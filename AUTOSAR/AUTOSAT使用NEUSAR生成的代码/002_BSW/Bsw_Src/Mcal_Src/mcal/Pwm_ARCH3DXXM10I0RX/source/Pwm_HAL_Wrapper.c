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
*   @file    Pwm_HAL_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 0311,0312,0380,0491,1006,1843,4397,0751,1891 EOF */
/* PRQA S 0686,2053,2832,2842,2844,2052,4332,0499,4424 EOF */
/* PRQA S 3604,4461,2934,2976,3432,4322,4342,1431,4491 EOF */
#include "Pwm.h"
#include "Pwm_LLDriver.h"
#include "Pwm_Irq.h"
#include "Pwm_Emios_LLDriver.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "Pwm_Etpu_LLDriver.h"
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#include "Pwm_Ccu7_LLDriver.h"
#endif
#include "SchM_Pwm.h"
#include "Pwm_HAL_Wrapper.h"
#include "common.h"

#define PWM_HAL_WRA_C_VENDOR_ID                      176
#define PWM_HAL_WRA_C_AR_REL_MAJOR_VER               4
#define PWM_HAL_WRA_C_AR_REL_MINOR_VER               4
#define PWM_HAL_WRA_C_AR_REL_REV_VER                 0
#define PWM_HAL_WRA_C_SW_MAJOR_VER                   3
#define PWM_HAL_WRA_C_SW_MINOR_VER                   0
#define PWM_HAL_WRA_C_SW_PATCH_VER                   0

#if (PWM_HAL_WRA_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_C_VENDOR_ID "
#endif
#if (PWM_HAL_WRA_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_HAL_WRA_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_C_AR_REL_MINOR_VER "
#endif
#if (PWM_HAL_WRA_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_C_AR_REL_REV_VER "
#endif
#if (PWM_HAL_WRA_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_C_SW_MAJOR_VER "
#endif
#if (PWM_HAL_WRA_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_C_SW_MINOR_VER "
#endif
#if (PWM_HAL_WRA_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_HAL_WRA_C_SW_PATCH_VER "
#endif

#define PWM_MULTI_CORE_SUPPORT                      (1)

#define PWM_CORE_Z70_ID_MASK                        (0x01U)
#define PWM_CORE_Z71_ID_MASK                        (0x02U)
#define PWM_CORE_Z42_ID_MASK                        (0x04U)

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(Pwm_PeriodType, PWM_VAR) s_u32Pwm_ChannelPeriod[PWM_CHANNEL_NUM];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(Pwm_DutycycleType, PWM_VAR) s_u32Pwm_ChannelDutycycle[PWM_CHANNEL_NUM];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(Pwm_OutputStateType, PWM_VAR) s_ePwm_ChannelIdleState[PWM_CHANNEL_NUM];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(Pwm_OutputStateType, PWM_VAR) s_ePwm_ChannelPolarity[PWM_CHANNEL_NUM];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(uint8, PWM_VAR) s_ePwm_ChannelInitState[PWM_CHANNEL_NUM];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(uint8, PWM_VAR) s_ePwm_ChannelNotification[PWM_CHANNEL_NUM];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(uint8, PWM_VAR) s_ePwm_ChannelNotifiClass[PWM_CHANNEL_NUM];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_INIT
#include "Pwm_MemMap.h"
static volatile P2VAR(Pwm_ChConfigsType, AUTOMATIC, PWM_APPL_CONST) s_pPwm_ChConfigs[PWM_CORE_NUM] = {NULL_PTR};
#define PWM_STOP_SEC_VAR_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(Pwm_ChConfigsType*, PWM_CODE) Pwm_Pwm_Wrapper_Get_pChConfigs(void);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableTomNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableAtomNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableEmiosNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableEtpuNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableCcu7Notification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_SetEmiosOutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_SetEtpuOutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_SetCcu7OutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_TomInit \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;

    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period = pPwm_ChConfig->nPwmPeriodDefault;
    VAR(uint16, AUTOMATIC) u16Pwm_duty = (uint16)pPwm_ChConfig->nPwmDutycycleDefault;

    u32Pwm_Cnt1 = u32Pwm_Period;
    u32Pwm_Cnt2 = (uint32)(((uint64)((uint64)u16Pwm_duty * (uint64)u32Pwm_Cnt1))>>15);

    Pwm_Wrapper_DisableTomNotification(pPwm_ChConfig);
    (void)GTM_TOM_LLD_Channel_SelectClockSource( \
        (GTM_TOM_Type)pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (GTM_TOM_Channel_Type)pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (GPT_GTM_TOM_ClockSource_Type)pPwm_ChConfig->sCmuClk.TOM_ClkSrc.ClkSrc
    );

    (void)SetTomChannelCM1 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt2 \
    );

    (void)GTM_TOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint16, AUTOMATIC))u32Pwm_Cnt1 \
    );

    (void)GTM_TOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint16, AUTOMATIC))u32Pwm_Cnt2 \
    );

    (void)SetTomChannelCM0 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex,
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt1 \
    );

    (void)GTM_TOM_LLD_Channel_SelectSignalLevel \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(GTM_TOM_SignalLevel_Type, AUTOMATIC)) pPwm_ChConfig->ePwmPolarity \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Enable \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableUpdateValue \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Enable \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableOutUpdateValue \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Enable \
    );
#ifdef RESOURCE_SUPPORT_GTM410_TOUT
    (void)GTM_LLD_SetToutSel \
    ( \
        (VAR(uint32, AUTOMATIC)) pPwm_ChConfig->nGtm4Tout, \
        (VAR(uint32, AUTOMATIC)) pPwm_ChConfig->nToutNum \
    );
#endif
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_AtomInit \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;

    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period = pPwm_ChConfig->nPwmPeriodDefault;
    VAR(uint16, AUTOMATIC) u16Pwm_duty = (uint16)pPwm_ChConfig->nPwmDutycycleDefault;

    u32Pwm_Cnt1 = u32Pwm_Period;
    u32Pwm_Cnt2 = (uint32)(((uint64)((uint64)u16Pwm_duty * (uint64)u32Pwm_Cnt1))>>15);

    Pwm_Wrapper_DisableAtomNotification(pPwm_ChConfig);
#ifdef RESOURCE_SUPPORT_GTM410_TOUT
    (void)GTM_LLD_SetToutSel \
    ( \
        (VAR(uint32, AUTOMATIC)) pPwm_ChConfig->nGtm4Tout, \
        (VAR(uint32, AUTOMATIC)) pPwm_ChConfig->nToutNum \
    );

    (void)GTM_ATOM_LLD_HresEn();
#endif
    (void)GTM_ATOM_LLD_Channel_SelectClockSource( \
        (GTM_ATOM_Type)pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (GTM_ATOM_Channel_Type)pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (GTM_ATOM_ClockSource_Type)pPwm_ChConfig->sCmuClk.ATOM_ClkSrc.ClkSrc
    );

    (void)GTM_ATOM_LLD_Channel_SelectATOMMode \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_MODE_SOMP \
    );

    (void)SetAtomChannelCM1 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt2 \
    );

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt1 \
    );

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt2 \
    );

    (void)SetAtomChannelCM0 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt1 \
    );

    (void)GTM_ATOM_LLD_Channel_SelectSignalLevel \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(GTM_ATOM_SignalLevel_Type, AUTOMATIC)) pPwm_ChConfig->ePwmPolarity \
    );
    
    (void)GTM_ATOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Enable \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableUpdateValue \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC))pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC))pPwm_ChConfig->sHwConfig.nPwmChIndex, GPT_GTM_Enable \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableOutUpdateValue \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC))pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC))pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Enable \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_EmiosInit \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    static VAR(eMIOS_PWM_ParamType, AUTOMATIC) eMIOS_PWM_chConfig[PWM_CORE_NUM]; 
    eMIOS_PWM_chConfig[u32CoreIDn].active = (uint8)pPwm_ChConfig->ePwmPolarity; /* polyspace RTE:OBAI */
    eMIOS_PWM_chConfig[u32CoreIDn].deadTime = pPwm_ChConfig->sEmiosChannelConfig.nDeadtime; /* polyspace RTE:OBAI */
    eMIOS_PWM_chConfig[u32CoreIDn].divid = (uint8)pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosPrescaler; /* polyspace RTE:OBAI */
    eMIOS_PWM_chConfig[u32CoreIDn].idealDutyCycle = pPwm_ChConfig->sEmiosChannelConfig.nIdealDutyCycle; /* polyspace RTE:OBAI */
    eMIOS_PWM_chConfig[u32CoreIDn].mode = pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode; /* polyspace RTE:OBAI */
    eMIOS_PWM_chConfig[u32CoreIDn].period = pPwm_ChConfig->nPwmPeriodDefault; /* polyspace RTE:OBAI */
    eMIOS_PWM_chConfig[u32CoreIDn].timebase = pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosBus; /* polyspace RTE:OBAI */
    eMIOS_PWM_chConfig[u32CoreIDn].offset = pPwm_ChConfig->sEmiosChannelConfig.nOffset; /* polyspace RTE:OBAI */
    eMIOS_PWM_chConfig[u32CoreIDn].eMiosDmaSwitch = pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosDmaSwitch; /* polyspace RTE:OBAI */
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    eMIOS_PWM_chConfig[u32CoreIDn].trigTime = pPwm_ChConfig->sEmiosChannelConfig.ntrigTime;/* polyspace RTE:OBAI */
#endif
    Pwm_Wrapper_DisableEmiosNotification(pPwm_ChConfig);
    eMIOS_PWM_chConfig[u32CoreIDn].dutyCycle = (uint32)((uint64)((uint64)pPwm_ChConfig->nPwmDutycycleDefault * (uint64)pPwm_ChConfig->nPwmPeriodDefault)>>15);

    (void)eMIOS_LLD_PWM_Init(pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                            pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                            &eMIOS_PWM_chConfig[u32CoreIDn]);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_EtpuInit \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    static VAR(etpu_pwm_param_t, AUTOMATIC) Etpu_PWM_chConfig[PWM_CORE_NUM];
    VAR(uint8, AUTOMATIC) etpuGroup = 0;
    VAR(uint8, AUTOMATIC) channel = 0;

    Etpu_PWM_chConfig[u32CoreIDn].priority = ETPU_PRIORITY_MIDDLE; /* polyspace RTE:OBAI */
    Etpu_PWM_chConfig[u32CoreIDn].polarity = (uint8)pPwm_ChConfig->ePwmPolarity; /* polyspace RTE:OBAI */
    Etpu_PWM_chConfig[u32CoreIDn].dutyCycle = (uint32)((uint64)((uint64)pPwm_ChConfig->nPwmDutycycleDefault * (uint64)pPwm_ChConfig->nPwmPeriodDefault)>>15); /* polyspace RTE:OBAI */
    Etpu_PWM_chConfig[u32CoreIDn].period = pPwm_ChConfig->nPwmPeriodDefault; /* polyspace RTE:OBAI */
    Etpu_PWM_chConfig[u32CoreIDn].timebase = (uint8)pPwm_ChConfig->eEtpuTimeBase; /* polyspace RTE:OBAI */

    if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 0U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_A_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 1U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_B_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 2U)
    {
        etpuGroup = ETPU_INSTANCE_C;
        channel = ETPU_C_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else{
        /* nothing */
    }

    (void)ETPU_LLD_PWM_Init \
    ( \
        etpuGroup, \
        channel, \
        &Etpu_PWM_chConfig[u32CoreIDn] \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* defined(RESOURCE_SUPPORT_ETPU) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_Ccu7Init \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    VAR(Pwm_IndexType, AUTOMATIC) channelNum;
    u32CoreIDn = GetCoreID();    //get core id
    channelNum = pPwm_ChConfig->sHwConfig.nPwmChIndex; //get channel number

    static VAR(Pwm_17_GtmCcu7_ChannelConfigType, AUTOMATIC) ccu7_PWM_chConfig[MCAL_CORE_NUM];
    static VAR(Mcu_17_Ccu7_TimerConfigType, AUTOMATIC) ccu7_PwmTimerPtr;

    cc_memset((uint8_t *)&ccu7_PWM_chConfig, 0, sizeof(ccu7_PWM_chConfig));
    cc_memset((uint8_t *)&ccu7_PwmTimerPtr, 0, sizeof(ccu7_PwmTimerPtr));

    ccu7_PWM_chConfig[u32CoreIDn].PwmChanneId = (uint8)pPwm_ChConfig->nPwmChannelId;/* polyspace RTE:OBAI */
    ccu7_PWM_chConfig[u32CoreIDn].PwmNotification = pPwm_ChConfig->pfPwmChannelNotification;
    ccu7_PWM_chConfig[u32CoreIDn].PwmChannelInfo = (uint8)(((uint32)(pPwm_ChConfig->ePwmChannelClass) << 3U) | \
                                                   (((uint32)(pPwm_ChConfig->ePwmIdleState) & PWM_CONST_1) << 1U) | \
                                                   ((uint32)(pPwm_ChConfig->ePwmPolarity) & PWM_CONST_1));
    ccu7_PWM_chConfig[u32CoreIDn].PwmPeriodDefault = (uint32)pPwm_ChConfig->nPwmPeriodDefault;
    ccu7_PWM_chConfig[u32CoreIDn].PwmDutycycleDefault = (uint32)pPwm_ChConfig->nPwmDutycycleDefault;

    ccu7_PwmTimerPtr.TimerModeSelectReg |= (pPwm_ChConfig->pPwmConfig_HwConfig.MSEL7x << (channelNum * CCU7_T12MSEL_MSEL70_LEN));/* polyspace RTE:OVFL,SHF */
    ccu7_PwmTimerPtr.TimerCntReg = pPwm_ChConfig->pPwmConfig_HwConfig.T1xCV;
    ccu7_PwmTimerPtr.TimerCtrlReg0 = (pPwm_ChConfig->pPwmConfig_HwConfig.T12PRE << IFX_CCU7_TCTR0_T12PRE_OFF) \
                                                                & (pPwm_ChConfig->pPwmConfig_HwConfig.CTM << IFX_CCU7_TCTR0_CTM_OFF);
    ccu7_PwmTimerPtr.TimerPeriodReg = pPwm_ChConfig->pPwmConfig_HwConfig.T1xPV;
    ccu7_PwmTimerPtr.Ccu7ShadowReg = pPwm_ChConfig->pPwmConfig_HwConfig.CCV;

    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        ccu7_PwmTimerPtr.ModCtrlReg |= (pPwm_ChConfig->pPwmConfig_HwConfig.MODEN & CCU7_MODCTR_T12MODEN_MSK) << (channelNum * CCU7_MODCTR_T12MODEN_LEN);
    }
    else if(channelNum == MCU_CCU7_COMPARATOR_CCU73)
    {
        ccu7_PwmTimerPtr.ModCtrlReg |= (pPwm_ChConfig->pPwmConfig_HwConfig.MODEN & IFX_CCU7_MODCTR_ECT13O_MSK) << IFX_CCU7_MODCTR_ECT13O_OFF;
    }
    else
    {
        /* nothing */
    }

    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        ccu7_PwmTimerPtr.PasStateLvlReg |= ((((pPwm_ChConfig->pPwmConfig_HwConfig.PSL) << 1U) | ((uint8)pPwm_ChConfig->ePwmPolarity))\
                & CCU7_PSLR_PSL_MSK) << (channelNum * CCU7_PSLR_PSL_LEN);
    }
    else if(channelNum == MCU_CCU7_COMPARATOR_CCU73)
    {
        ccu7_PwmTimerPtr.PasStateLvlReg |= ((((pPwm_ChConfig->pPwmConfig_HwConfig.PSL) << 1U) | ((uint8)pPwm_ChConfig->ePwmPolarity))\
                & IFX_CCU7_PSLR_PSL73_MSK) << IFX_CCU7_PSLR_PSL73_OFF;
    }
    else
    {
        /* nothing */
    }

    ccu7_PWM_chConfig[u32CoreIDn].PwmTimerPtr = &ccu7_PwmTimerPtr;

    (void)Ccu7_LLD_PWM_Init \
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ccu7_PWM_chConfig[u32CoreIDn] \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_CCU7_IP */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Wrapper_Init \
( \
    P2CONST(Pwm_ChConfigsType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfigs \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
    VAR(uint32, AUTOMATIC) PwmTomTrig[RESOURCE_SUPPORT_GTM_TOM_NUM] = {0U};
    VAR(uint16, AUTOMATIC) PwmAtomTrig[RESOURCE_SUPPORT_GTM_ATOM_NUM] = {0U};
    VAR(uint16, AUTOMATIC) TriggerVal;
    VAR(uint8, AUTOMATIC) ModuleNo = 0U;
#endif

    u32CoreIDn = GetCoreID();    //get core id

    s_pPwm_ChConfigs[u32CoreIDn] = (Pwm_ChConfigsType*)pPwm_ChConfigs;/* polyspace RTE:OBAI */  

    VAR(uint32, AUTOMATIC) u32Pwm_Index = 0U;
#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
        u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }
#endif
    SchM_Enter_Pwm_EXCLUSIVE_AREA_00();
    for(u32Pwm_Index = 0U; u32Pwm_Index < pPwm_ChConfigs->nNum; u32Pwm_Index++)
    {
#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
        if((u32CoreID & (pPwm_ChConfigs->pPwm_CoreMap[u32Pwm_Index].nCoreId)) != 0U)/* polyspace RTE:NIV,IDP */  
#endif
        {
            if(s_ePwm_ChannelInitState[u32Pwm_Index] == 0U)/* polyspace RTE:OBAI */  
            {
                s_u32Pwm_ChannelPeriod[u32Pwm_Index] \
                    = pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].nPwmPeriodDefault;
                s_u32Pwm_ChannelDutycycle[u32Pwm_Index] \
                   = pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].nPwmDutycycleDefault;
                s_ePwm_ChannelIdleState[u32Pwm_Index] \
                   = pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].ePwmIdleState;
                s_ePwm_ChannelPolarity[u32Pwm_Index] \
                   = pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].ePwmPolarity;
                s_ePwm_ChannelNotification[u32Pwm_Index] &= (uint8)(~u32CoreID);
                s_ePwm_ChannelInitState[u32Pwm_Index] = 1U;

                switch(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].ePwmHwIP)
                {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
                    case PWM_TOM:
                    {
                        Pwm_Wrapper_TomInit(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                        PwmTomTrig[pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].sHwConfig.nPwmHwIndex] |= /* polyspace RTE:OBAI */  
                        		((uint32)2UL << (pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].sHwConfig.nPwmChIndex * 2U));/* polyspace RTE:SHF */  
                        break;
                    }
                    case PWM_ATOM:
                    {
                        Pwm_Wrapper_AtomInit(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                        PwmAtomTrig[pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].sHwConfig.nPwmHwIndex] |= /* polyspace RTE:OBAI */  
                        		((uint32)2UL << (pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].sHwConfig.nPwmChIndex * 2U));/* polyspace RTE:SHF */  
                        break;
                    }
#endif
                    case PWM_EMIOS:
                    {
                        Pwm_Wrapper_EmiosInit(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                        break;
                    }
#if (defined(RESOURCE_SUPPORT_ETPU))
                    case PWM_ETPU:
                    {
                        Pwm_Wrapper_EtpuInit(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                        break;
                    }
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
                    case PWM_CCU7:
                    {
                        Pwm_Wrapper_Ccu7Init(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                        break;
                    }
#endif
                    default:
                    {
                        /*nothing*/
                        break;
                    }
                }
            }
        }
    }
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
	for(ModuleNo = 0U; ModuleNo < (uint8)(RESOURCE_SUPPORT_GTM_ATOM_NUM); ModuleNo++)
    {
      TriggerVal = PwmAtomTrig[ModuleNo];
      if(TriggerVal != 0U)
      {
        /* Set host triger for current AGC automatic write */
    	(void)GTM_ATOM_LLD_AGC_HostTrigger((GTM_ATOM_Type)ModuleNo);
      }
    }

    for(ModuleNo = 0U; ModuleNo < (uint8)(RESOURCE_SUPPORT_GTM_TOM_NUM); ModuleNo++)
    {
      TriggerVal = (uint16)(PwmTomTrig[ModuleNo] & 0xFFFFU);
      if(TriggerVal != 0U)
      {
        /* Start TGC 0 of selected module */
    	(void)GTM_TOM_LLD_TGC0_HostTrigger((GTM_TOM_Type)ModuleNo);
      }

      TriggerVal = (uint16)((PwmTomTrig[ModuleNo] & 0xFFFF0000U) >> 16U);
      if(TriggerVal != 0U)
      {
        /* Start TGC 1 of selected module */
        (void)GTM_TOM_LLD_TGC1_HostTrigger((GTM_TOM_Type)ModuleNo);
      }
    }
#endif

#if (defined(RESOURCE_SUPPORT_CCU7_IP))
    for(u32Pwm_Index = 0U; u32Pwm_Index < pPwm_ChConfigs->nNum; u32Pwm_Index++)
    {
        if(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].ePwmHwIP == PWM_CCU7)/* polyspace RTE:OBAI */
        {
            if(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].sHwConfig.nPwmHwIndex == 0U)
            {
                Pwm_Ccu7_SetTCTR4_T12RS(0, PWM_CONST_3);
                break;
            }
            if(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].sHwConfig.nPwmHwIndex == 1U)
            {
                Pwm_Ccu7_SetTCTR4_T12RS(1, PWM_CONST_3);
                break;
            }
        }
    }

    for(u32Pwm_Index = 0U; u32Pwm_Index < pPwm_ChConfigs->nNum; u32Pwm_Index++)
    {
        if(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].ePwmHwIP == PWM_CCU7)/* polyspace RTE:OBAI */
        {
            if(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].sHwConfig.nPwmHwIndex == 0U)
            {
                Pwm_Ccu7_SetTCTR4_T13RS(0, PWM_CONST_3);
                break;
            }
            if(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].sHwConfig.nPwmHwIndex == 1U)
            {
                Pwm_Ccu7_SetTCTR4_T13RS(1, PWM_CONST_3);
                break;
            }
        }
    }
#endif
    SchM_Exit_Pwm_EXCLUSIVE_AREA_00();
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_AtomDeInit \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;

    (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU0TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU1TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU0TC \
    );

    (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex,
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC))pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU1TC \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Disable \
    );

    if(s_ePwm_ChannelPolarity[pPwm_ChConfig->nPwmChannelId] /* polyspace RTE:OBAI */  
            == s_ePwm_ChannelIdleState[pPwm_ChConfig->nPwmChannelId])
    {
        u32Pwm_Cnt1 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        u32Pwm_Cnt2 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] \
            = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
    }
    else
    {
        u32Pwm_Cnt1 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        u32Pwm_Cnt2 = 0;
        s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = 0;
    }

    (void)GTM_ATOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Disable \
    );

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex,
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt1 \
    );

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt2 \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Enable \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_TomDeInit \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;

    (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        TOM_IRQ_CCU0TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        TOM_IRQ_CCU1TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        TOM_IRQ_CCU0TC \
    );

    (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        TOM_IRQ_CCU1TC \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Disable \
    );

    if(s_ePwm_ChannelPolarity[pPwm_ChConfig->nPwmChannelId] /* polyspace RTE:OBAI */  
            == s_ePwm_ChannelIdleState[pPwm_ChConfig->nPwmChannelId])
    {
        u32Pwm_Cnt1 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        u32Pwm_Cnt2 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] \
            = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
    }
    else
    {
        u32Pwm_Cnt1 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        u32Pwm_Cnt2 = 0;
        s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = 0;
    }

    (void)GTM_TOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Disable \
    );

    (void)GTM_TOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint16, AUTOMATIC))u32Pwm_Cnt1 \
    );

    (void)GTM_TOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint16, AUTOMATIC)) u32Pwm_Cnt2 \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Enable \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_EmiosDeInit \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(eMIOS_PWM_ParamType, AUTOMATIC) eMIOS_PWM_GPIO_chConfig;
    eMIOS_PWM_GPIO_chConfig.active = (uint8)pPwm_ChConfig->ePwmIdleState;
    eMIOS_PWM_GPIO_chConfig.mode = EMIOS_UC_MODE_PWM_GPIO;
    Pwm_Wrapper_DisableEmiosNotification(pPwm_ChConfig);
    (void)eMIOS_LLD_PWM_Init \
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        &eMIOS_PWM_GPIO_chConfig \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_EtpuDeInit \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint8, AUTOMATIC) etpuGroup = 0;
    VAR(uint8, AUTOMATIC) channel = 0;

    if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 0U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_A_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 1U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_B_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 2U)
    {
        etpuGroup = ETPU_INSTANCE_C;
        channel = ETPU_C_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else{
        /* nothing */
    }
    Pwm_Wrapper_DisableEtpuNotification(pPwm_ChConfig);
    Pwm_Wrapper_SetEtpuOutputToIdle(pPwm_ChConfig);
    ETPU_LLD_ChannelDisable(etpuGroup, channel);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* defined(RESOURCE_SUPPORT_ETPU) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_Ccu7DeInit \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    Ccu7_LLD_PWM_DisableNotification \
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
    Ccu7_LLD_PWM_SetOutputToIdle \
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
    Ccu7_LLD_PWM_DeInit \
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* defined(RESOURCE_SUPPORT_CCU7_IP) */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Wrapper_DeInit \
( \
    P2CONST(Pwm_ChConfigsType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfigs \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
        u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }
#endif


    VAR(uint32, AUTOMATIC) u32Pwm_Index = 0U;
    SchM_Enter_Pwm_EXCLUSIVE_AREA_01();
    for(u32Pwm_Index = 0U; u32Pwm_Index < pPwm_ChConfigs->nNum; u32Pwm_Index++)/* polyspace RTE:COR,IDP */ 
    {
#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
        if((u32CoreID & (pPwm_ChConfigs->pPwm_CoreMap[u32Pwm_Index].nCoreId)) != 0U)/* polyspace RTE:COR,NIV,IDP */ 
#endif
        {
            s_ePwm_ChannelInitState[u32Pwm_Index] = 0U;/* polyspace RTE:OBAI */  
            switch(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index].ePwmHwIP)
            {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
                case PWM_TOM:
                {
                    Pwm_Wrapper_TomDeInit(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                    break;
                }
                case PWM_ATOM:
                {
                    Pwm_Wrapper_AtomDeInit(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                    break;
                }
#endif
                case PWM_EMIOS:
                {
                    Pwm_Wrapper_EmiosDeInit(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                    break;
                }
#if (defined(RESOURCE_SUPPORT_ETPU))
                case PWM_ETPU:
                {
                    Pwm_Wrapper_EtpuDeInit(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                    break;
                }
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
                case PWM_CCU7:
                {
                    Pwm_Wrapper_Ccu7DeInit(&(pPwm_ChConfigs->sPwmChConfigs[u32Pwm_Index]));
                    break;
                }
#endif
                default:
                {
                    /*nothing*/
                    break;
                }
            }
        }
    }
    SchM_Exit_Pwm_EXCLUSIVE_AREA_01();

    s_pPwm_ChConfigs[u32CoreIDn] = NULL_PTR; /* polyspace RTE:OBAI */
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if(defined(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD) && (PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_ON))
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetTomPeriodAndDuty \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;
    VAR(uint16, AUTOMATIC) u16Pwm_Duty_temp = 0U;
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period_temp = 0U;
    u16Pwm_Duty_temp = u16Pwm_Duty;
    u32Pwm_Period_temp = u32Pwm_Period;

    if(u32Pwm_Period_temp == 0U)
    {
        u16Pwm_Duty_temp = 0U;
        u32Pwm_Period_temp = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];/* polyspace RTE:OBAI */  
    }

    s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = u16Pwm_Duty_temp;/* polyspace RTE:OBAI */  
    s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId] = u32Pwm_Period_temp;

    u32Pwm_Cnt1 = u32Pwm_Period_temp;
    u32Pwm_Cnt2 = (uint32)(((uint64)((uint64)u16Pwm_Duty_temp * (uint64)u32Pwm_Cnt1))>>15);

    (void)GTM_TOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Disable \
    );

    (void)GTM_TOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint16, AUTOMATIC)) u32Pwm_Cnt1 \
    );

    (void)GTM_TOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint16, AUTOMATIC)) u32Pwm_Cnt2 \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Enable \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
#if(defined(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD) && (PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_ON))
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetAtomPeriodAndDuty \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;
    VAR(uint16, AUTOMATIC) u16Pwm_Duty_temp = 0U;
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period_temp = 0U;
    u16Pwm_Duty_temp = u16Pwm_Duty;
    u32Pwm_Period_temp = u32Pwm_Period;

    if(u32Pwm_Period_temp == 0U)
    {
        u16Pwm_Duty_temp = 0;
        u32Pwm_Period_temp = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];/* polyspace RTE:OBAI */  
    }

    s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = u16Pwm_Duty_temp;/* polyspace RTE:OBAI */  
    s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId] = u32Pwm_Period_temp;

    u32Pwm_Cnt1 = u32Pwm_Period_temp;
    u32Pwm_Cnt2 = (uint32)(((uint64)((uint64)u16Pwm_Duty_temp * (uint64)u32Pwm_Cnt1))>>15);

    (void)GTM_ATOM_LLD_Channel_IsEnableUpdate \
    ( \
        (GTM_ATOM_Type)pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (GTM_ATOM_Channel_Type)pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Disable \
    );

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (GTM_ATOM_Type)pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (GTM_ATOM_Channel_Type)pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt1 \
    );

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (GTM_ATOM_Type)pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (GTM_ATOM_Channel_Type)pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        u32Pwm_Cnt2 \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableUpdate \
    ( \
        (GTM_ATOM_Type)pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (GTM_ATOM_Channel_Type)pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        GPT_GTM_Enable \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetEmiosPeriodAndDuty \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint16, AUTOMATIC) u16Pwm_Duty_temp = 0U;
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period_temp = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Duty_temp = 0U;

    u16Pwm_Duty_temp = u16Pwm_Duty;
    u32Pwm_Period_temp = u32Pwm_Period;

    if(u32Pwm_Period_temp == 0U)
    {
        u16Pwm_Duty_temp = 0U;
        u32Pwm_Period_temp = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];/* polyspace RTE:OBAI */  
    }

    if((pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_OPWFMB)||
            (pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_OPWMCB_TRAIL)||
            (pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_OPWMCB_LEAD)||
            (pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_OPWMB) ||
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
            (pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_OPWMT) ||
#endif
            (pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_DAOC))
    {
        s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = u16Pwm_Duty_temp;/* polyspace RTE:OBAI */  
        s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId] = u32Pwm_Period_temp;

        u32Pwm_Duty_temp = (uint32)((uint64)((uint64)u16Pwm_Duty_temp * (uint64)u32Pwm_Period_temp)>>15);

        if((pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_OPWFMB))
        {
            eMIOS_LLD_SetChOutputUPDEnDis \
            (\
                pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                FALSE
            );

            (void)eMIOS_LLD_PWM_SetPeriodAndDuty \
            ( \
                pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                u32Pwm_Period_temp, \
                u32Pwm_Duty_temp
            );

            eMIOS_LLD_SetChOutputUPDEnDis \
            (\
                pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                TRUE
            );
        }
        else
        {
            if(pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_DAOC)
            {
                (void)eMIOS_LLD_PWM_DAOC_SetDutyCycle \
                ( \
                    pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                    pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                    u32Pwm_Duty_temp, \
                    pPwm_ChConfig->nPwmPeriodDefault
                );
            }
            else
            {
                (void)eMIOS_LLD_PWM_SetDutyCycle \
                ( \
                    pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                    pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                    u32Pwm_Duty_temp \
                );
            }
        }
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetEtpuPeriodAndDuty \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint32, AUTOMATIC) dutyCycle = 0;
    VAR(uint8, AUTOMATIC) etpuGroup = 0;
    VAR(uint8, AUTOMATIC) channel = 0;
    VAR(uint16, AUTOMATIC) u16Pwm_Duty_temp = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Period_temp = 0U;
    u16Pwm_Duty_temp = u16Pwm_Duty;
    u32Pwm_Period_temp = u32Pwm_Period;

    if(u32Pwm_Period == 0U)
    {
        u16Pwm_Duty_temp = 0U;
        u32Pwm_Period_temp = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];/* polyspace RTE:OBAI */  
    }

    s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = u16Pwm_Duty_temp;/* polyspace RTE:OBAI */  
    s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId] = u32Pwm_Period_temp;
    dutyCycle = (uint32)((uint64)((uint64)u16Pwm_Duty_temp * (uint64)u32Pwm_Period_temp)>>15);
    if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 0U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_A_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 1U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_B_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 2U)
    {
        etpuGroup = ETPU_INSTANCE_C;
        channel = ETPU_C_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else{
        /* nothing */
    }

    (void)ETPU_LLD_PWM_SetPeriodAndDuty(etpuGroup,channel,u32Pwm_Period_temp,dutyCycle);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetCcu7PeriodAndDuty \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint16, AUTOMATIC) u16Pwm_Duty_temp = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Period_temp = 0U;
    u16Pwm_Duty_temp = u16Pwm_Duty;
    u32Pwm_Period_temp = u32Pwm_Period;

    if(u32Pwm_Period == 0U)
    {
        u16Pwm_Duty_temp = 0U;
        u32Pwm_Period_temp = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];/* polyspace RTE:OBAI */
    }

    s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = u16Pwm_Duty_temp;/* polyspace RTE:OBAI */
    s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId] = u32Pwm_Period_temp;

    Ccu7_LLD_PWM_SetPeriodAndDuty \
    (\
                pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                u32Pwm_Period_temp, \
                u16Pwm_Duty_temp \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_CCU7_IP */

#if(defined(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD) && (PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_OFF))
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetTomPeriodAndDuty_asyn \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;
    VAR(uint16, AUTOMATIC) u16Pwm_Duty_temp = 0U;
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period_temp = 0U;
    u16Pwm_Duty_temp = u16Pwm_Duty;
    u32Pwm_Period_temp = u32Pwm_Period;

    if(u32Pwm_Period_temp == 0U)
    {
        u16Pwm_Duty_temp = 0U;
        u32Pwm_Period_temp = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
    }

    s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = u16Pwm_Duty_temp;
    s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId] = u32Pwm_Period_temp;

    u32Pwm_Cnt1 = u32Pwm_Period_temp;
    u32Pwm_Cnt2 = (uint32)(((uint64)((uint64)u16Pwm_Duty_temp * (uint64)u32Pwm_Cnt1))>>15);

    (void)GTM_TOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint16, AUTOMATIC)) u32Pwm_Cnt1 \
    );

    (void)GTM_TOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint16, AUTOMATIC)) u32Pwm_Cnt2 \
    );

    (void)GTM_TOM_LLD_Channel_SetCompareRegister \
    (
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint16, AUTOMATIC)) u32Pwm_Cnt1, \
        (VAR(uint16, AUTOMATIC)) u32Pwm_Cnt2
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif

#if(defined(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD) && (PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_OFF))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetAtomPeriodAndDuty_asyn \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;
    VAR(uint16, AUTOMATIC) u16Pwm_Duty_temp = 0U;
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period_temp = 0U;
    u16Pwm_Duty_temp = u16Pwm_Duty;
    u32Pwm_Period_temp = u32Pwm_Period;

    if(u32Pwm_Period_temp == 0U)
    {
        u16Pwm_Duty_temp = 0U;
        u32Pwm_Period_temp = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
    }

    s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = u16Pwm_Duty_temp;
    s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId] = u32Pwm_Period_temp;

    u32Pwm_Cnt1 = u32Pwm_Period_temp;
    u32Pwm_Cnt2 = (uint32)(((uint64)((uint64)u16Pwm_Duty_temp * (uint64)u32Pwm_Cnt1))>>15);

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint32, AUTOMATIC)) u32Pwm_Cnt1 \
    );

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint32, AUTOMATIC)) u32Pwm_Cnt2 \
    );

    (void)GTM_ATOM_LLD_Channel_SetCompareRegister \
    (
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        (VAR(uint32, AUTOMATIC)) u32Pwm_Cnt1, \
        (VAR(uint32, AUTOMATIC)) u32Pwm_Cnt2
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Wrapper_SetPeriodAndDuty \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
        u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }
#endif

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    if((u32CoreID & (s_pPwm_ChConfigs[u32CoreIDn]->pPwm_CoreMap[pPwm_ChConfig->nPwmChannelId].nCoreId)) != 0U)/* polyspace RTE:COR,OBAI,NIV,IDP */ 
#endif
    {
        SchM_Enter_Pwm_EXCLUSIVE_AREA_02();
        switch(pPwm_ChConfig->ePwmHwIP)
        {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
            case PWM_TOM:
            {
#if(defined(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD) && (PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_ON))
                Pwm_Wrapper_SetTomPeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
#else
                Pwm_Wrapper_SetTomPeriodAndDuty_asyn(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
#endif
            }
            case PWM_ATOM:
            {
#if(defined(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD) && (PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_ON))
                Pwm_Wrapper_SetAtomPeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
#else
                Pwm_Wrapper_SetAtomPeriodAndDuty_asyn(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
#endif
            }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
            case PWM_EMIOS:
            {
                Pwm_Wrapper_SetEmiosPeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
            }
#if (defined(RESOURCE_SUPPORT_ETPU))
            case PWM_ETPU:
            {
                Pwm_Wrapper_SetEtpuPeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
            }
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
            case PWM_CCU7:
            {
                Pwm_Wrapper_SetCcu7PeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
            }
#endif
            default:
            {
                /*nothing*/
                break;
            }
        }
        SchM_Exit_Pwm_EXCLUSIVE_AREA_02();
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetDuty \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];/* polyspace RTE:COR,OBAI,IDP */ 
#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
        u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }
#endif

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    if((u32CoreID & (s_pPwm_ChConfigs[u32CoreIDn]->pPwm_CoreMap[pPwm_ChConfig->nPwmChannelId].nCoreId)) != 0U)/* polyspace RTE:COR,OBAI,NIV,IDP */ 
#endif
    {
        SchM_Enter_Pwm_EXCLUSIVE_AREA_03();
        switch (pPwm_ChConfig->ePwmHwIP)
        {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
            case PWM_TOM:
            {
#if(defined(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD) && (PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_ON))
                Pwm_Wrapper_SetTomPeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
#else
                Pwm_Wrapper_SetTomPeriodAndDuty_asyn(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
#endif
            }
            case PWM_ATOM:
            {
#if(defined(PWM_DUTY_PERIOD_UPDATED_ENDPERIOD) && (PWM_DUTY_PERIOD_UPDATED_ENDPERIOD == STD_ON))
                Pwm_Wrapper_SetAtomPeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
#else
                Pwm_Wrapper_SetAtomPeriodAndDuty_asyn(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
#endif
            }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
            case PWM_EMIOS:
            {
                Pwm_Wrapper_SetEmiosPeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
            }
#if (defined(RESOURCE_SUPPORT_ETPU))
            case PWM_ETPU:
            {
                Pwm_Wrapper_SetEtpuPeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
            }
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
            case PWM_CCU7:
            {
                Pwm_Wrapper_SetCcu7PeriodAndDuty(pPwm_ChConfig, u32Pwm_Period, u16Pwm_Duty);
                break;
            }
#endif
            default:
            {
                /* Do nothing */
                break;
            }
        }
        SchM_Exit_Pwm_EXCLUSIVE_AREA_03();
    }
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Wrapper_SetDutyCycle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    Pwm_Wrapper_SetDuty \
    ( \
        pPwm_ChConfig, u16Pwm_Duty \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetTomOutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;

    (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        TOM_IRQ_CCU0TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        TOM_IRQ_CCU1TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, TOM_IRQ_CCU0TC \
    );

    (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC))pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, TOM_IRQ_CCU1TC \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC))pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, GPT_GTM_Disable \
    );

    if(s_ePwm_ChannelPolarity[pPwm_ChConfig->nPwmChannelId] /* polyspace RTE:OBAI */  
            == s_ePwm_ChannelIdleState[pPwm_ChConfig->nPwmChannelId])
    {
        u32Pwm_Cnt1 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        u32Pwm_Cnt2 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] \
            = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
    }
    else
    {
        u32Pwm_Cnt1 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        u32Pwm_Cnt2 = 0;
        s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = 0;
    }

    (void)GTM_TOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC))pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, GPT_GTM_Disable \
    );

    (void)GTM_TOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC))pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, (uint16)u32Pwm_Cnt1 \
    );

    (void)GTM_TOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, (uint16)u32Pwm_Cnt2 \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, GPT_GTM_Enable \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_SetAtomOutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt1 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_Cnt2 = 0U;

    (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU0TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU1TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU0TC \
    );

    (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU1TC \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, GPT_GTM_Disable \
    );

    if(s_ePwm_ChannelPolarity[pPwm_ChConfig->nPwmChannelId] /* polyspace RTE:OBAI */  
            == s_ePwm_ChannelIdleState[pPwm_ChConfig->nPwmChannelId])
    {
        u32Pwm_Cnt1 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        u32Pwm_Cnt2 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] \
            = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
    }
    else
    {
        u32Pwm_Cnt1 = s_u32Pwm_ChannelPeriod[pPwm_ChConfig->nPwmChannelId];
        u32Pwm_Cnt2 = 0;
        s_u32Pwm_ChannelDutycycle[pPwm_ChConfig->nPwmChannelId] = 0;
    }

    (void)GTM_ATOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, GPT_GTM_Disable \
    );

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister0 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, u32Pwm_Cnt1 \
    );

    (void)GTM_ATOM_LLD_Channel_SetShadowRegister1 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, u32Pwm_Cnt2 \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableUpdate \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, GPT_GTM_Enable \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_SetEmiosOutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    if((pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode != EMIOS_UC_MODE_PWM_DAOC)&&
        (pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode != EMIOS_UC_MODE_PWM_OPWMT))
#else
    if(pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode != EMIOS_UC_MODE_PWM_DAOC)
#endif
    {
        eMIOS_LLD_UC_ClearFlag \
        ( \
            pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            pPwm_ChConfig->sHwConfig.nPwmChIndex \
        );

        eMIOS_UC_Cn_SetFEN \
        ( \
            pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            pPwm_ChConfig->sHwConfig.nPwmChIndex, \
            (boolean)FALSE
        );
    }

    if(s_ePwm_ChannelPolarity[pPwm_ChConfig->nPwmChannelId] /* polyspace RTE:OBAI */  
                == s_ePwm_ChannelIdleState[pPwm_ChConfig->nPwmChannelId])
    {
        Pwm_Wrapper_SetDutyCycle(pPwm_ChConfig,0x8000);
    }
    else
    {
        Pwm_Wrapper_SetDutyCycle(pPwm_ChConfig,0);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_SetEtpuOutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint8, AUTOMATIC) etpuGroup = 0;
    VAR(uint8, AUTOMATIC) channel = 0;

    if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 0U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_A_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 1U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_B_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 2U)
    {
        etpuGroup = ETPU_INSTANCE_C;
        channel = ETPU_C_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else{
        /* nothing */
    }

    (void)ETPU_LLD_ClearChannelInterruptFlag(etpuGroup,channel);
    (void)ETPU_LLD_ChannelIntMaskDisable(etpuGroup,channel);

    if(s_ePwm_ChannelPolarity[pPwm_ChConfig->nPwmChannelId] /* polyspace RTE:OBAI */  
                == s_ePwm_ChannelIdleState[pPwm_ChConfig->nPwmChannelId])
    {
        Pwm_Wrapper_SetDutyCycle(pPwm_ChConfig,0x8000);
    }
    else
    {
        Pwm_Wrapper_SetDutyCycle(pPwm_ChConfig,0);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_ETPU */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_SetCcu7OutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    Ccu7_LLD_PWM_SetOutputToIdle
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_CCU7_IP */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Wrapper_SetOutputToIdle \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
        u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }
#endif

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    if((u32CoreID & (s_pPwm_ChConfigs[u32CoreIDn]->pPwm_CoreMap[pPwm_ChConfig->nPwmChannelId].nCoreId)) != 0U)/* polyspace RTE:COR,OBAI,NIV,IDP */ 
#endif
    {
        SchM_Enter_Pwm_EXCLUSIVE_AREA_04();
        switch (pPwm_ChConfig->ePwmHwIP)
        {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
            case PWM_TOM:
            {
                Pwm_Wrapper_SetTomOutputToIdle(pPwm_ChConfig);
                break;
            }
            case PWM_ATOM:
            {
                Pwm_Wrapper_SetAtomOutputToIdle(pPwm_ChConfig);
                break;
            }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
            case PWM_EMIOS:
            {
                Pwm_Wrapper_SetEmiosOutputToIdle(pPwm_ChConfig);
                break;
            }
#if (defined(RESOURCE_SUPPORT_ETPU))
            case PWM_ETPU:
            {
                Pwm_Wrapper_SetEtpuOutputToIdle(pPwm_ChConfig);
                break;
            }
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
            case PWM_CCU7:
            {
                Pwm_Wrapper_SetCcu7OutputToIdle(pPwm_ChConfig);
                break;
            }
#endif
            default:
            {
                /*nothing*/
                break;
            }
        }
//        Pwm_clr_isr_flag(pPwm_ChConfig->nPwmChannelId);
        s_ePwm_ChannelNotification[pPwm_ChConfig->nPwmChannelId] = 0U;/* polyspace RTE:OBAI */  
        SchM_Exit_Pwm_EXCLUSIVE_AREA_04();
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetTomOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    return GTM_TOM_LLD_Channel_GetOutputLevel \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetAtomOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    return GTM_ATOM_LLD_Channel_GetOutputLevel \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetEmiosOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    return eMIOS_UC_Sn_GetUCOUT \
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetEtpuOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    return ETPU_LLD_PWM_GetOutputState \
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_ETPU */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetCcu7OutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    return Ccu7_LLD_PWM_GetOutputState \
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_CCU7_IP */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) Pwm_Wrapper_GetOutputState \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint8, AUTOMATIC) u8Pwm_Status = 0;
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
        u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }
#endif

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    if((u32CoreID & (s_pPwm_ChConfigs[u32CoreIDn]->pPwm_CoreMap[pPwm_ChConfig->nPwmChannelId].nCoreId)) != 0U)/* polyspace RTE:COR,OBAI,NIV,IDP */ 
#endif
    {
        SchM_Enter_Pwm_EXCLUSIVE_AREA_05();
        switch (pPwm_ChConfig->ePwmHwIP)
        {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
            case PWM_TOM:
            {
                u8Pwm_Status = Pwm_Wrapper_GetTomOutputState(pPwm_ChConfig);
                break;
            }
            case PWM_ATOM:
            {
                u8Pwm_Status = Pwm_Wrapper_GetAtomOutputState(pPwm_ChConfig);
                break;
            }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
            case PWM_EMIOS:
            {
                u8Pwm_Status = Pwm_Wrapper_GetEmiosOutputState(pPwm_ChConfig);
                break;
            }
#if (defined(RESOURCE_SUPPORT_ETPU))
            case PWM_ETPU:
            {
                u8Pwm_Status = Pwm_Wrapper_GetEtpuOutputState(pPwm_ChConfig);
                break;
            }
#endif /* RESOURCE_SUPPORT_ETPU */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
            case PWM_CCU7:
            {
                u8Pwm_Status = Pwm_Wrapper_GetCcu7OutputState(pPwm_ChConfig);
                break;
            }
#endif /* RESOURCE_SUPPORT_CCU7_IP */
            default:
            {
                /* Do nothing */
                break;
            }
        }
        SchM_Exit_Pwm_EXCLUSIVE_AREA_05();
    }

    return u8Pwm_Status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableTomNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        TOM_IRQ_CCU0TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        TOM_IRQ_CCU1TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, TOM_IRQ_CCU0TC \
    );

    (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, TOM_IRQ_CCU1TC \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableAtomNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt
    (
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU0TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt
    (
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU1TC, \
        GPT_GTM_Disable \
    );

    (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU0TC \
    );

    (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ATOM_IRQ_CCU1TC \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableEmiosNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    if((pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode != EMIOS_UC_MODE_PWM_DAOC) &&
        (pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode != EMIOS_UC_MODE_PWM_OPWMT))
#else
    if(pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode != EMIOS_UC_MODE_PWM_DAOC)
#endif
    {
        eMIOS_LLD_UC_ClearFlag \
        ( \
            pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            pPwm_ChConfig->sHwConfig.nPwmChIndex \
        );

        eMIOS_UC_Cn_SetFEN \
        ( \
            pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            pPwm_ChConfig->sHwConfig.nPwmChIndex, \
            (boolean)pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosDmaSwitch
        );

        eMIOS_UC_Cn_SetDMA \
        ( \
            pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            pPwm_ChConfig->sHwConfig.nPwmChIndex, \
            (boolean)pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosDmaSwitch
        );
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableEtpuNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint8, AUTOMATIC) etpuGroup = 0;
    VAR(uint8, AUTOMATIC) channel = 0;

    if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 0U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_A_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 1U)
    {
        etpuGroup = ETPU_INSTANCE_A_B;
        channel = ETPU_B_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 2U)
    {
        etpuGroup = ETPU_INSTANCE_C;
        channel = ETPU_C_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
    }else{
        /* nothing */
    }

    (void)ETPU_LLD_ClearChannelInterruptFlag(etpuGroup,channel);
    (void)ETPU_LLD_ChannelIntMaskDisable(etpuGroup,channel);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_ETPU */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Wrapper_DisableCcu7Notification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    Ccu7_LLD_PWM_DisableNotification
    ( \
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex \
    );
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_CCU7_IP */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Wrapper_DisableNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
        u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }
#endif

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    if((u32CoreID & (s_pPwm_ChConfigs[u32CoreIDn]->pPwm_CoreMap[pPwm_ChConfig->nPwmChannelId].nCoreId)) != 0U)/* polyspace RTE:COR,OBAI,NIV,IDP */ 
#endif
    {
        SchM_Enter_Pwm_EXCLUSIVE_AREA_06();
        s_ePwm_ChannelNotification[pPwm_ChConfig->nPwmChannelId] &= (uint8)(~u32CoreID);/* polyspace RTE:OBAI */  
        if(s_ePwm_ChannelNotification[pPwm_ChConfig->nPwmChannelId] == 0U)
        {
            switch (pPwm_ChConfig->ePwmHwIP)
            {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
                case PWM_TOM:
                {
                    Pwm_Wrapper_DisableTomNotification(pPwm_ChConfig);
                    break;
                }
                case PWM_ATOM:
                {
                    Pwm_Wrapper_DisableAtomNotification(pPwm_ChConfig);
                    break;
                }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
                case PWM_EMIOS:
                {
                    Pwm_Wrapper_DisableEmiosNotification(pPwm_ChConfig);
                    break;
                }
#if (defined(RESOURCE_SUPPORT_ETPU))
                case PWM_ETPU:
                {
                    Pwm_Wrapper_DisableEtpuNotification(pPwm_ChConfig);
                    break;
                }
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
                case PWM_CCU7:
                {
                    Pwm_Wrapper_DisableCcu7Notification(pPwm_ChConfig);
                    break;
                }
#endif
                default:
                {
                    /*nothing*/
                    break;
                }
            }
//            Pwm_clr_isr_flag(pPwm_ChConfig->nPwmChannelId);
        }
        SchM_Exit_Pwm_EXCLUSIVE_AREA_06();
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_EnableTomNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) ePwm_Notification \
)
{
    VAR(uint16, AUTOMATIC) u16Pwm_RegS0 = 0U;
    VAR(uint16, AUTOMATIC) u16Pwm_RegS1 = 0U;

    (void)GTM_TOM_LLD_Channel_GetShadowRegister0 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, &u16Pwm_RegS0 \
    );
    (void)GTM_TOM_LLD_Channel_GetShadowRegister1 \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, &u16Pwm_RegS1 \
    );

    if((u16Pwm_RegS1 != 0U) && (u16Pwm_RegS1 != u16Pwm_RegS0))
    {
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, TOM_IRQ_CCU0TC \
        );
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, TOM_IRQ_CCU1TC \
        );

        if (PWM_BOTH_EDGES == ePwm_Notification)
        {
            (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                TOM_IRQ_CCU0TC, \
                GPT_GTM_Enable \
            );
            (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                TOM_IRQ_CCU1TC, \
                GPT_GTM_Enable \
            );
        }
        else if(PWM_FALLING_EDGE == ePwm_Notification)
        {
            (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                TOM_IRQ_CCU0TC, \
                GPT_GTM_Disable \
            );
            (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                TOM_IRQ_CCU1TC, \
                GPT_GTM_Enable \
            );
        }
        else if(PWM_RISING_EDGE == ePwm_Notification)
        {
            (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                TOM_IRQ_CCU0TC, \
                GPT_GTM_Enable \
            );
            (void)GTM_TOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_TOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                TOM_IRQ_CCU1TC, \
                GPT_GTM_Disable \
            );
        }
        else
        {
            /* Do nothing */
        }
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_EnableAtomNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC,PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) ePwm_Notification \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_RegS0 = 0U;
    VAR(uint32, AUTOMATIC) u32Pwm_RegS1 = 0U;

    (void)GTM_ATOM_LLD_Channel_GetShadowRegister0 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, &u32Pwm_RegS0 \
    );
    (void)GTM_ATOM_LLD_Channel_GetShadowRegister1 \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, &u32Pwm_RegS1 \
    );

    if((u32Pwm_RegS1 != 0U) && (u32Pwm_RegS1 != u32Pwm_RegS0))
    {
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
            ATOM_IRQ_CCU0TC \
        );
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
            ATOM_IRQ_CCU1TC \
        );

        if (PWM_BOTH_EDGES == ePwm_Notification)
        {
            (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                ATOM_IRQ_CCU0TC, \
                GPT_GTM_Enable \
            );
            (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                ATOM_IRQ_CCU1TC, \
                GPT_GTM_Enable \
            );
        }
        else if(PWM_RISING_EDGE == ePwm_Notification)
        {
            (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                ATOM_IRQ_CCU0TC, \
                GPT_GTM_Enable \
            );
            (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                ATOM_IRQ_CCU1TC, \
                GPT_GTM_Disable \
            );
        }
        else if(PWM_FALLING_EDGE == ePwm_Notification)
        {
            (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                ATOM_IRQ_CCU0TC, \
                GPT_GTM_Disable \
            );
            (void)GTM_ATOM_LLD_Channel_IsEnableInterrupt \
            ( \
                (VAR(GTM_ATOM_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
                (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) pPwm_ChConfig->sHwConfig.nPwmChIndex, \
                ATOM_IRQ_CCU1TC, \
                GPT_GTM_Enable \
            );
        }
        else
        {
            /* Do nothing */
        }
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_EnableEmiosNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC,PWM_APPL_CONST) pPwm_ChConfig \
)
{
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    if((pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode != EMIOS_UC_MODE_PWM_DAOC) &&
        (pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode != EMIOS_UC_MODE_PWM_OPWMT))
#else
    if(pPwm_ChConfig->sEmiosChannelConfig.nPwmeMiosMode != EMIOS_UC_MODE_PWM_DAOC)
#endif
    {
        eMIOS_LLD_UC_ClearFlag \
        ( \
            pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            pPwm_ChConfig->sHwConfig.nPwmChIndex \
        );

        eMIOS_UC_Cn_SetFEN \
        ( \
            pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            pPwm_ChConfig->sHwConfig.nPwmChIndex, \
            (boolean)TRUE
        );

        eMIOS_UC_Cn_SetDMA \
        ( \
            pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
            pPwm_ChConfig->sHwConfig.nPwmChIndex, \
            (boolean)FALSE
        );
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_EnableEtpuNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC,PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) ePwm_Notification \
)
{
    VAR(uint8, AUTOMATIC) etpuGroup = 0;
    VAR(uint8, AUTOMATIC) channel = 0;

    if(((pPwm_ChConfig->ePwmPolarity == PWM_HIGH) && (ePwm_Notification == PWM_RISING_EDGE)) || \
        ((pPwm_ChConfig->ePwmPolarity == PWM_LOW) && (ePwm_Notification == PWM_FALLING_EDGE)) || \
        (ePwm_Notification == PWM_BOTH_EDGES))
    {
        if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 0U)
        {
            etpuGroup = ETPU_INSTANCE_A_B;
            channel = ETPU_A_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
        }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 1U)
        {
            etpuGroup = ETPU_INSTANCE_A_B;
            channel = ETPU_B_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
        }else if(pPwm_ChConfig->sHwConfig.nPwmHwIndex == 2U)
        {
            etpuGroup = ETPU_INSTANCE_C;
            channel = ETPU_C_CHANNLE(pPwm_ChConfig->sHwConfig.nPwmChIndex);
        }else{
            /* nothing */
        }

        (void)ETPU_LLD_ClearChannelInterruptFlag(etpuGroup,channel);
        (void)ETPU_LLD_ChannelIntMaskEnable(etpuGroup,channel);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_ETPU */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE) Pwm_Wrapper_EnableCcu7Notification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC,PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) ePwm_Notification \
)
{
    Ccu7_LLD_PWM_EnableNotification \
    (\
        pPwm_ChConfig->sHwConfig.nPwmHwIndex, \
        pPwm_ChConfig->sHwConfig.nPwmChIndex, \
        ePwm_Notification \
    );
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_CCU7_IP */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Wrapper_EnableNotification \
( \
    P2CONST(Pwm_ChConfigType, AUTOMATIC, PWM_APPL_CONST) pPwm_ChConfig, \
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) ePwm_Notification \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
        u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }
#endif
#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    if((u32CoreID & (s_pPwm_ChConfigs[u32CoreIDn]->pPwm_CoreMap[pPwm_ChConfig->nPwmChannelId].nCoreId)) != 0U)/* polyspace RTE:COR,OBAI,NIV,IDP */ 
#endif
    {
        SchM_Enter_Pwm_EXCLUSIVE_AREA_07();
        s_ePwm_ChannelNotification[pPwm_ChConfig->nPwmChannelId] |= (uint8)u32CoreID;/* polyspace RTE:OBAI */  
        s_ePwm_ChannelNotifiClass[pPwm_ChConfig->nPwmChannelId] = (uint8)ePwm_Notification;
        if(s_ePwm_ChannelNotification[pPwm_ChConfig->nPwmChannelId] == u32CoreID)
        {
            switch (pPwm_ChConfig->ePwmHwIP)
            {
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
                case PWM_TOM:
                {
                    Pwm_Wrapper_EnableTomNotification(pPwm_ChConfig, ePwm_Notification);
                    break;
                }
                case PWM_ATOM:
                {
                    Pwm_Wrapper_EnableAtomNotification(pPwm_ChConfig, ePwm_Notification);
                    break;
                }
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */
                case PWM_EMIOS:
                {
                    Pwm_Wrapper_EnableEmiosNotification(pPwm_ChConfig);
                    break;
                }
#if (defined(RESOURCE_SUPPORT_ETPU))
                case PWM_ETPU:
                {
                    Pwm_Wrapper_EnableEtpuNotification(pPwm_ChConfig, ePwm_Notification);
                    break;
                }
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
                case PWM_CCU7:
                {
                    Pwm_Wrapper_EnableCcu7Notification(pPwm_ChConfig, ePwm_Notification);
                    break;
                }
#endif
                default:
                {
                    /*nothing*/
                    break;
                }
            }
        }
        SchM_Exit_Pwm_EXCLUSIVE_AREA_07();
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(Pwm_ChConfigsType*, PWM_CODE) Pwm_Pwm_Wrapper_Get_pChConfigs(void)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    Pwm_ChConfigsType* pPwm_ChConfigs = (Pwm_ChConfigsType*)s_pPwm_ChConfigs[u32CoreIDn]; /* polyspace RTE:OBAI */
    return pPwm_ChConfigs;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8*, PWM_CODE) Pwm_Wrapper_Get_ChannelNotification(void)
{
    uint8* ePwm_ChannelNotification = (uint8*)s_ePwm_ChannelNotification;
    return ePwm_ChannelNotification;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8*, PWM_CODE) Pwm_Wrapper_Get_ChannelNotifiClass(void)
{
    uint8* ePwm_ChannelNotifiClass = (uint8*)s_ePwm_ChannelNotifiClass;
    return ePwm_ChannelNotifiClass;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(Pwm_DutycycleType, PWM_CODE) Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelType id)
{
    Pwm_DutycycleType ChannelDutycycle = 0;
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    if(u32CoreIDn < PWM_CORE_NUM)
    {
        u32CoreID = (uint8)(1U<<(u32CoreIDn));
    }
#endif

#if(defined(PWM_MULTI_CORE_SUPPORT) && (PWM_MULTI_CORE_SUPPORT == 1))
    if((u32CoreID & (s_pPwm_ChConfigs[u32CoreIDn]->pPwm_CoreMap[id].nCoreId)) != 0U)/* polyspace RTE:COR,OBAI,NIV,IDP */ 
#endif
    {
        ChannelDutycycle = s_u32Pwm_ChannelDutycycle[id];/* polyspace RTE:OBAI */  
    }

    return ChannelDutycycle;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) Pwm_Wrapper_Check_DutyCycle
(
    VAR(Pwm_ChannelType, AUTOMATIC) id,
    VAR(uint16, AUTOMATIC) u16Pwm_Duty
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_offset = 0;
    VAR(uint32, AUTOMATIC)  u32Pwm_Duty_temp = 0;
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period_temp = 0U;
    VAR(uint8, AUTOMATIC)  ret = 0;

    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if(s_pPwm_ChConfigs[u32CoreIDn]->sPwmChConfigs[id].ePwmHwIP == PWM_EMIOS)/* polyspace RTE:COR,OBAI,IDP */ 
    {
        if(s_pPwm_ChConfigs[u32CoreIDn]->sPwmChConfigs[id].sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_OPWMB)
        {
            u32Pwm_offset = s_pPwm_ChConfigs[u32CoreIDn]->sPwmChConfigs[id].sEmiosChannelConfig.nOffset;
            u32Pwm_Period_temp = s_u32Pwm_ChannelPeriod[id];
            u32Pwm_Duty_temp = (uint32)((uint64)((uint64)u16Pwm_Duty * (uint64)u32Pwm_Period_temp)>>15);
            if((u32Pwm_offset == 0U) || ((u32Pwm_offset + u32Pwm_Duty_temp) < u32Pwm_Period_temp))
            {
                ret = 1;
            }
        }
        else
        {
            ret = 1;
        }
    }
    else
    {
        ret = 1;
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) Pwm_Wrapper_Check_PeriodAndDuty
(
    VAR(Pwm_ChannelType, AUTOMATIC) id, \
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period, \
    VAR(uint16, AUTOMATIC) u16Pwm_Duty \
)
{
    VAR(uint32, AUTOMATIC) u32Pwm_offset = 0;
    VAR(uint32, AUTOMATIC)  u32Pwm_Duty_temp = 0;
    VAR(Pwm_PeriodType, AUTOMATIC) u32Pwm_Period_temp = 0U;
    VAR(uint8, AUTOMATIC)  ret = 0;

    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id

    if((s_pPwm_ChConfigs[u32CoreIDn]->sPwmChConfigs[id].ePwmHwIP == PWM_EMIOS))/* polyspace RTE:COR,OBAI,IDP */ 
    {
        if(s_pPwm_ChConfigs[u32CoreIDn]->sPwmChConfigs[id].sEmiosChannelConfig.nPwmeMiosMode == EMIOS_UC_MODE_PWM_OPWMB)
        {
            u32Pwm_offset = s_pPwm_ChConfigs[u32CoreIDn]->sPwmChConfigs[id].sEmiosChannelConfig.nOffset;
            u32Pwm_Period_temp = u32Pwm_Period;
            u32Pwm_Duty_temp = (uint32)((uint64)((uint64)u16Pwm_Duty * (uint64)u32Pwm_Period_temp)>>15);
            if((u32Pwm_offset == 0U) || ((u32Pwm_offset + u32Pwm_Duty_temp) < u32Pwm_Period_temp))
            {
                ret = 1;
            }
        }
        else
        {
            ret = 1;
        }
    }
    else
    {
        ret = 1;
    }
    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint32, PWM_CODE) Pwm_Wrapper_Get_MaxDutycycle
(
    VAR(Pwm_ChannelType, AUTOMATIC) id \
)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();    //get core id
    return (s_pPwm_ChConfigs[u32CoreIDn]->sPwmChConfigs[id].nPwmMaxDutycycle);/* polyspace RTE:COR,OBAI,IDP */ 
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif
