/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM TOM low level drivers code
* HISTORY     : Initial version
* @file     gtm4_tom_lld.c
* @version  3.0.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 0380,4342,2985,3432 EOF */
/* PRQA S 4522,1891,4397,0499,1258 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm_LLDriver.h"
#if (defined(RESOURCE_SUPPORT_GTM410))
#include "Gpt_Gtm_LLDriver.h"

#define PWM_LLD_C_VENDOR_ID                      176
#define PWM_LLD_C_AR_REL_MAJOR_VER               4
#define PWM_LLD_C_AR_REL_MINOR_VER               4
#define PWM_LLD_C_AR_REL_REV_VER                 0
#define PWM_LLD_C_SW_MAJOR_VER                   3
#define PWM_LLD_C_SW_MINOR_VER                   0
#define PWM_LLD_C_SW_PATCH_VER                   0

#if (PWM_LLD_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_LLD_C_VENDOR_ID "
#endif
#if (PWM_LLD_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_LLD_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_AR_REL_MINOR_VER "
#endif
#if (PWM_LLD_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_AR_REL_REV_VER "
#endif
#if (PWM_LLD_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_SW_MAJOR_VER "
#endif
#if (PWM_LLD_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_SW_MINOR_VER "
#endif
#if (PWM_LLD_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_LLD_C_SW_PATCH_VER "
#endif

/*
 * @brief Gated Counter ePwm_Mode enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableGatedCounterMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.GCM = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.GCM != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief SPE mode enable for channel.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableSPEMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SPEM = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SPEM != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief One-shot mode enable for channel.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableOneShotMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.OSM = (uint8_t)ePwm_IsEnable;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.OSM != (uint8_t)ePwm_IsEnable)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Trigger output selection.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_TriggerOutput Trigger output type.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectTriggerOutput \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_TriggerOutput_Type, AUTOMATIC) ePwm_TriggerOutput \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.TRIGOUT = (uint8_t)ePwm_TriggerOutput;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.TRIGOUT != (uint8_t)ePwm_TriggerOutput)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief CCU0 Reset Source selection.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_CCU0ResetSource CCU0 Reset Source.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectCCU0ResetSource \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_CCU0ResetSource_Type, AUTOMATIC) ePwm_CCU0ResetSource \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.RST_CCU0 = (uint8_t)ePwm_CCU0ResetSource;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.RST_CCU0 != (uint8_t)ePwm_CCU0ResetSource)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Clock source select.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_ClockSource Clock source.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectClockSource \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_TOM_ClockSource_Type, AUTOMATIC) ePwm_ClockSource \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL_SR.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;/* polyspace RTE:OBAI */
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL_SR.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)/* polyspace RTE:NIV */
    {
    	ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief GET Clock source.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return ClockSource Clock source.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(GTM_TOM_ClockSource_Type, AUTOMATIC) GTM_TOM_LLD_Channel_GetClockSource \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    return (GTM_TOM_ClockSource_Type)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL_SR.B.CLK_SRC_SR;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Signal level for duty cycle.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_SignalLevel Signal level.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectSignalLevel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_SignalLevel_Type, AUTOMATIC) ePwm_SignalLevel \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint32, PWM_VAR) SignalLevel_Reg = ((uint32)ePwm_SignalLevel << 11U);

    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL_SR.R = SignalLevel_Reg;
    if((GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL_SR.R & SignalLevel_Reg) != SignalLevel_Reg)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectSignalLevelShadowRegister \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GTM_TOM_SignalLevel_Type, AUTOMATIC) SignalLevel \
)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint32_t tempReg;

    tempReg = GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL_SR.R;
    tempReg &= ~((SignalLevel & 0x1U) << 11);
	tempReg |= ((SignalLevel & 0x1U) << 11);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL_SR.R = tempReg;

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*
 * @brief Set Shadow Register value.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u16Pwm_SR0 Shadow Register0 value.
 * @param[in] u16Pwm_SR1 Shadow Register1 value.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetShadowRegister \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR0, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.R = u16Pwm_SR0;
    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.R = u16Pwm_SR1;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.R != u16Pwm_SR0) 
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }else if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.R != u16Pwm_SR1)
    {
        ePwm_ReturnValue = STATUS_ERROR;        
    }else{
        /* do nothing */
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Set compare Register value.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u16Pwm_CM0 compare Register0 value.
 * @param[in] u16Pwm_CM1 compare Register1 value.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetCompareRegister \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_CM0, \
    VAR(uint16, AUTOMATIC) u16Pwm_CM1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM0.B.CM0 = u16Pwm_CM0;
    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM1.B.CM1 = u16Pwm_CM1;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM0.B.CM0 != u16Pwm_CM0)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }else if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM1.B.CM1 != u16Pwm_CM1)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }else{
        /* do nothing */
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Set Counter Register value.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u16Pwm_CN0 Counter Register0 value.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetCounter \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_CN0 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CN0.B.CN0 = u16Pwm_CN0;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CN0.B.CN0 != u16Pwm_CN0)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Get Counter Register value.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Counter Register value.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint16, PWM_CODE) GTM_TOM_LLD_Channel_GetCounter \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    return (uint16_t)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CN0.B.CN0;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Get Output Level.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Output Level.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) GTM_TOM_LLD_Channel_GetOutputLevel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    return (uint8_t)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].STAT.B.OL;/* polyspace RTE:OBAI,NIV */
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Get ePwm_Interrupt Flag.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt Interrupt type.
 *
 * @return Interrupt Flag status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) GTM_TOM_LLD_Channel_GetInterruptFlag \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    VAR(uint8, AUTOMATIC) u8Pwm_ReturnValue = 0U;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(ePwm_Interrupt == TOM_IRQ_CCU0TC)
    {
        u8Pwm_ReturnValue = (uint8_t)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_NOTIFY.B.CCU0TC;/* polyspace RTE:OBAI,NIV */
    }else if(ePwm_Interrupt == TOM_IRQ_CCU1TC)
    {
        u8Pwm_ReturnValue = (uint8_t)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_NOTIFY.B.CCU1TC;
    }else
    {
        /* do nothing */
    }

    return u8Pwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Clear ePwm_Interrupt Flag.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt Interrupt type.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_ClearInterruptFlag \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    if(ePwm_Interrupt == TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_NOTIFY.R = 1U;
    }else if(ePwm_Interrupt == TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_NOTIFY.R = 2U;
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief ePwm_Interrupt enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt Interrupt type.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableInterrupt \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(ePwm_Interrupt == TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_EN.B.CCU0TC_IRQ_EN = (uint8_t)ePwm_IsEnable;/* polyspace RTE:OBAI */
        if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_EN.B.CCU0TC_IRQ_EN != (uint8_t)ePwm_IsEnable)/* polyspace RTE:NIV */
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else if(ePwm_Interrupt == TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_EN.B.CCU1TC_IRQ_EN = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_EN.B.CCU1TC_IRQ_EN != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Force ePwm_Interrupt.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt Interrupt type.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_ForceInt \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_TOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    if(ePwm_Interrupt == TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
    }else if(ePwm_Interrupt == TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Select ePwm_Interrupt ePwm_Mode.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_InterruptMode Interrupt mode.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SelectInterruptMode\
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_InterruptMode_Type, AUTOMATIC) ePwm_InterruptMode \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_MODE.B.IRQ_MODE = (uint8_t)ePwm_InterruptMode;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].IRQ_MODE.B.IRQ_MODE != (uint8_t)ePwm_InterruptMode)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Update enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableUpdate \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    VAR(uint8_t, AUTOMATIC) ePwm_IsEnable_l = (uint8_t) ePwm_IsEnable;

    if(ePwm_IsEnable_l  == 1u)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8_t, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_GLB_CTRL_UPEN_CTRL0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_GLB_CTRL.R |= (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));/* polyspace RTE:OBAI */
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_GLB_CTRL.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(1u):(2u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_GLB_CTRL.R |= (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));/* polyspace RTE:OBAI */
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_GLB_CTRL.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(1u):(2u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Reset Channel.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_ResetChannel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    VAR(uint8_t, AUTOMATIC)  shift = ((uint8_t)ePwm_CHn % 8U) + (uint8_t)GTM4_TOM_TGC_GLB_CTRL_RST_CH0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_GLB_CTRL.R = (uint32_t)((uint32_t)1UL << (shift & 0x1FU));
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_GLB_CTRL.R = (uint32_t)((uint32_t)1UL << (shift & 0x1FU));
    }

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief TGC0 Host Trigger.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC0_HostTrigger \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_GLB_CTRL.B.HOST_TRIG = 1;

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief TGC1 Host Trigger.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC1_HostTrigger \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_GLB_CTRL.B.HOST_TRIG = 1;

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief TGC0 Host Select ePwm_TimeBase.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_TimeBase ePwm_TimeBase type.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC0_SelectTimeBase \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ACT_TB.B.TBU_SEL = (uint8_t)ePwm_TimeBase;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ACT_TB.B.TBU_SEL != (uint8_t)ePwm_TimeBase)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief TGC1 Host Select ePwm_TimeBase.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_TimeBase ePwm_TimeBase type.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC1_SelectTimeBase \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ACT_TB.B.TBU_SEL = (uint8_t)ePwm_TimeBase;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ACT_TB.B.TBU_SEL != (uint8_t)ePwm_TimeBase)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Set TGC0 Action Time.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] u32Pwm_ActionTime Action Time.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC0_SetActionTime \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    VAR(uint32, AUTOMATIC) ActionTime_l = u32Pwm_ActionTime;
    ActionTime_l = (0x00ffffffU & ActionTime_l);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ACT_TB.B.ACT_TB = ActionTime_l;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ACT_TB.B.ACT_TB != ActionTime_l)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Set TGC1 Action Time.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] u32Pwm_ActionTime Action Time.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_TGC1_SetActionTime \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);

    VAR(uint32, AUTOMATIC) ActionTime_l = u32Pwm_ActionTime;
    ActionTime_l = (0x00ffffffU & ActionTime_l);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ACT_TB.B.ACT_TB = ActionTime_l;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ACT_TB.B.ACT_TB != ActionTime_l)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Force Update for reset u16Pwm_CN0 enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableForceUpdateCN0Reset \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(ePwm_IsEnable_l  == 1u)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_FUPD_CTRL_RSTCN0_CH0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_FUPD_CTRL.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_FUPD_CTRL.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_FUPD_CTRL.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_FUPD_CTRL.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Force Update enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableForceUpdate \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(ePwm_IsEnable_l  == 1u)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_FUPD_CTRL_FUPD_CTRL0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_FUPD_CTRL.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_FUPD_CTRL.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_FUPD_CTRL.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_FUPD_CTRL.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Internal Trigger enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableInternalTrigger \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8) ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2U;
    }
    else
    {
        ePwm_IsEnable_l = 1U;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_INT_TRIG_INT_TRIG0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_INT_TRIG.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_INT_TRIG.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_INT_TRIG.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_INT_TRIG.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Update Value enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableUpdateValue \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8)ePwm_GTM_TOMn < (uint8)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8)ePwm_CHn < (uint8)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;
    VAR(uint32, AUTOMATIC) reg;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2u;

    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8)ePwm_CHn % 8U) * 2U) + (uint8)GTM4_TOM_TGC_ENDIS_CTRL_ENDIS_CTRL0_OFF;

    if((uint8)ePwm_CHn < 8U)
    {
        reg = GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ENDIS_CTRL.R;
        reg &= (uint32)(~((uint32)(0x3UL << shift)));
        reg |= ((uint32)ePwm_IsEnable_l << shift);
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ENDIS_CTRL.R = reg;

        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ENDIS_CTRL.R >> shift) & 0x3u) != ePwm_IsEnable_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        reg = GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ENDIS_CTRL.R;
        reg &= (uint32)(~((uint32)(0x3UL << shift)));
        reg |= ((uint32)ePwm_IsEnable_l << shift);
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ENDIS_CTRL.R = reg;

        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ENDIS_CTRL.R >> shift) & 0x3u) != ePwm_IsEnable_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Channel enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableChannel \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_ENDIS_STAT_ENDIS_STAT0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ENDIS_STAT.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_ENDIS_STAT.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ENDIS_STAT.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_ENDIS_STAT.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief OutUpdate Value enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableOutUpdateValue \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS; 
    GTM4_TOM_DET_ERR((uint8)ePwm_GTM_TOMn < (uint8)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8)ePwm_CHn < (uint8)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;
    VAR(uint32, AUTOMATIC) reg;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8)ePwm_CHn % 8U) * 2U) + (uint8)GTM4_TOM_TGC_OUTEN_CTRL_OUTEN_CTRL0_OFF;

    if((uint8)ePwm_CHn < 8U)
    {
        reg = GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_CTRL.R;
        reg &= (uint32)(~((uint32)(0x3UL << shift)));
        reg |= ((uint32)ePwm_IsEnable_l << shift);
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_CTRL.R = reg;

        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_CTRL.R >> shift) & 0x3u) != ePwm_IsEnable_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        reg = GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_OUTEN_CTRL.R;
        reg &= (uint32)(~((uint32)(0x3UL << shift)));
        reg |= ((uint32)ePwm_IsEnable_l << shift);
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_OUTEN_CTRL.R = reg;

        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_OUTEN_CTRL.R >> shift) & 0x3u) != ePwm_IsEnable_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Out enable.
 *
 * @param[in] ePwm_GTM_TOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_IsEnableOut \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;
    
    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2u;
    }
    else
    {
        ePwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_TOM_TGC_OUTEN_STAT_OUTEN_STAT0_OFF;

    if((uint8_t)ePwm_CHn < 8U)
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_STAT.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_STAT.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_OUTEN_STAT.R = (uint32_t)((uint32_t)ePwm_IsEnable_l << (shift & 0x1FU));
        if(((GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC1_OUTEN_STAT.R >> (shift & 0x1FU)) & 0x3u) != ((ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetCountMode \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) CHn, \
    VAR(uint8, AUTOMATIC) mode \
)
{
    GTM4_TOM_DET_ERR((uint8_t)GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    uint32_t tempReg;

    tempReg = GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.R;
    tempReg &= ~((mode & 0x3u) << 18);
    tempReg |= ((mode & 0x3u) << 18);

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.R = tempReg;

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* RESOURCE_SUPPORT_GTM410 */
#ifdef __cplusplus
}
#endif

/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM ATOM low level drivers code
* HISTORY     : Initial version
* @file     gtm4_atom_lld.c
* @version  1.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0380,1317,1503,1296,1338,2016,2023,2024,4442,2985 EOF*/
 /*PRQA S 4404,3469 EOF*/

#ifdef __cplusplus
extern "C"{
#endif

#if (defined(RESOURCE_SUPPORT_GTM410))

/*
 * @brief ARU Read address.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u16Pwm_ReadAddress0  ARU Read address 0.
 * @param[in] u16Pwm_ReadAddress1  ARU Read address 1.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetReadAddress \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_ReadAddress0, \
    VAR(uint16, AUTOMATIC) u16Pwm_ReadAddress1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].RDADDR.B.RDADDR0 = (uint8_t)u16Pwm_ReadAddress0;
    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].RDADDR.B.RDADDR1 = (uint8_t)u16Pwm_ReadAddress1;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].RDADDR.B.RDADDR0 != (uint8_t)u16Pwm_ReadAddress0) 
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }else if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].RDADDR.B.RDADDR1 != (uint8_t)u16Pwm_ReadAddress1)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }else{
        /* do nothing */
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief ARU blocking mode.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable  Enable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableARUBlockMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ARU_EN = (uint8_t)ePwm_IsEnable;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ARU_EN != (uint8_t)ePwm_IsEnable)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief One-shot mode.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable  Enable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableOneShotMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.OSM = (uint8_t)ePwm_IsEnable;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.OSM != (uint8_t)ePwm_IsEnable)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief NTrigger output selection (output signal TRIG_CHn) of module ATOM_CHn.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_TriggerOutput  Trigger source.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectTriggerOutput \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_TriggerOutput_Type, AUTOMATIC) ePwm_TriggerOutput \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.TRIGOUT = (uint8_t)ePwm_TriggerOutput;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.TRIGOUT != (uint8_t)ePwm_TriggerOutput)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Reset source of CCU0.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_ResetSource  Reset source.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectCCU0ResetSource \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_ResetSource_Type, AUTOMATIC) ePwm_ResetSource \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.RST_CCU0 = (uint8_t)ePwm_ResetSource;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.RST_CCU0 != (uint8_t)ePwm_ResetSource)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP).
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_ClockSource clock source.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectClockSource \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_ClockSource_Type, AUTOMATIC) ePwm_ClockSource \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL_SR.B.CLK_SRC_SR = (uint8_t)ePwm_ClockSource;/* polyspace RTE:OBAI */
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL_SR.B.CLK_SRC_SR != (uint8_t)ePwm_ClockSource)/* polyspace RTE:NIV */
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief GET Actual CMU clock source (SOMS) / shadow register for CMU clock source (SOMP).
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return ClockSource clock source.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(GTM_ATOM_ClockSource_Type, AUTOMATIC) GTM_ATOM_LLD_Channel_GetClockSource \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    return (GTM_ATOM_ClockSource_Type)GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL_SR.B.CLK_SRC_SR;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Initial signal level after channel enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_SignalLevel signal level.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectSignalLevel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_SignalLevel_Type, AUTOMATIC) ePwm_SignalLevel \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL_SR.B.SL_SR = (uint8_t)ePwm_SignalLevel;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL_SR.B.SL_SR != (uint8_t)ePwm_SignalLevel)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*
 * @brief CCUn compare strategy select.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_CompareStrategy compare strategy.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectCompareStrategy \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_CompareStrategy_Type, AUTOMATIC) ePwm_CompareStrategy \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS; 
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.CMP_CTRL = (uint8_t)ePwm_CompareStrategy;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.CMP_CTRL != (uint8_t)ePwm_CompareStrategy)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief ATOM ePwm_Mode control bits.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u8Pwm_ACBbits ATOM ePwm_Mode control bits.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetACBbits \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_ACBbits \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ACB = u8Pwm_ACBbits;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ACB != u8Pwm_ACBbits)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief ARU Input stream enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable Enable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableARU \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ARU_EN = (uint8_t)ePwm_IsEnable;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.ARU_EN != (uint8_t)ePwm_IsEnable)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Select time base value TBU_TS1 or TBU_TS2.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_TimeBase TBU_TS1 or TBU_TS2.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectTB12TimeBase \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_TB12TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.TB12_SEL = (uint8_t)ePwm_TimeBase;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.TB12_SEL != (uint8_t)ePwm_TimeBase)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief ATOM channel mode select.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Mode channel mode.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectATOMMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Mode_Type, AUTOMATIC) ePwm_Mode \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.MODE = (uint8_t)ePwm_Mode;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL.B.MODE != (uint8_t)ePwm_Mode)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Set Shadow Register value.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u32Pwm_SR0 Shadow Register0 value.
 * @param[in] u32Pwm_SR1 Shadow Register1 value.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetShadowRegister \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR0, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0 = u32Pwm_SR0;
    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1 = u32Pwm_SR1;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0 != u32Pwm_SR0) 
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }else if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1 != u32Pwm_SR1)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }else{
        /* do nothing */
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Set compare Register value.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] u32Pwm_CM0 compare Register0 value.
 * @param[in] u32Pwm_CM1 compare Register1 value.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetCompareRegister \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_CM0, \
    VAR(uint32, AUTOMATIC) u32Pwm_CM1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM0.B.CM0 = u32Pwm_CM0;
    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM1.B.CM1 = u32Pwm_CM1;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM0.B.CM0 != u32Pwm_CM0) 
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }else if (GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM1.B.CM1 != u32Pwm_CM1)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }else{
        /* do nothing */
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Get Counter Register value.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Counter Register value.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetCounter \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_CN0 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(uint32, AUTOMATIC) u32Pwm_CN0_l = u32Pwm_CN0;

    u32Pwm_CN0_l = ((uint32)0x00ffffffUL & u32Pwm_CN0_l);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CN0.B.CN0 = u32Pwm_CN0_l;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CN0.B.CN0 != u32Pwm_CN0_l)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Get Output Level.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Output Level.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) GTM_ATOM_LLD_Channel_GetOutputLevel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    return (uint8_t)GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].STAT.B.OL;/* polyspace RTE:OBAI,NIV */
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Get ePwm_Interrupt Flag.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt ePwm_Interrupt type.
 *
 * @return ePwm_Interrupt Flag status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8, PWM_CODE) GTM_ATOM_LLD_Channel_GetInterruptFlag \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;

    if(ePwm_Interrupt == ATOM_IRQ_CCU0TC)
    {
        ePwm_ReturnValue = (status_t)GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_NOTIFY.B.CCU0TC;/* polyspace RTE:OBAI,NIV */
    }else if(ePwm_Interrupt == ATOM_IRQ_CCU1TC)
    {
        ePwm_ReturnValue = (status_t)GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_NOTIFY.B.CCU1TC;
    }else
    {
        /* do nothing */
    }

    return (uint8_t)ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Clear ePwm_Interrupt Flag.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt ePwm_Interrupt type.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_ClearInterruptFlag \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    if(ePwm_Interrupt == ATOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_NOTIFY.R = 1U;
    }else if(ePwm_Interrupt == ATOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_NOTIFY.R = 2U;
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief ePwm_Interrupt enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt ePwm_Interrupt type.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableInterrupt \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

   if(ePwm_Interrupt == ATOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_EN.B.CCU0TC_IRQ_EN = (uint8_t)ePwm_IsEnable;/* polyspace RTE:OBAI */
        if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_EN.B.CCU0TC_IRQ_EN != (uint8_t)ePwm_IsEnable)/* polyspace RTE:NIV */
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else if(ePwm_Interrupt == ATOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_EN.B.CCU1TC_IRQ_EN = (uint8_t)ePwm_IsEnable;
        if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_EN.B.CCU1TC_IRQ_EN != (uint8_t)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Force ePwm_Interrupt.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_Interrupt ePwm_Interrupt type.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_ForceInterrupt \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC) ePwm_Interrupt \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    if(ePwm_Interrupt == ATOM_IRQ_CCU0TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_FORCINT.B.TRG_CCU0TC = 1u;
    }else if(ePwm_Interrupt == ATOM_IRQ_CCU1TC)
    {
        GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_FORCINT.B.TRG_CCU1TC = 1u;
    }else
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Select ePwm_Interrupt ePwm_Mode.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_InterruptMode ePwm_Interrupt mode.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SelectInterruptMode \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GTM_InterruptMode_Type, AUTOMATIC) ePwm_InterruptMode \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_MODE.B.IRQ_MODE = (uint8_t)ePwm_InterruptMode;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].IRQ_MODE.B.IRQ_MODE != (uint8_t)ePwm_InterruptMode)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Update enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableUpdate \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2;
    }
    else
    {
        u8Pwm_IsEnable_l = 1;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_GLB_CTRL_UPEN_CTRL0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.GLB_CTRL.R |= (uint32_t)((uint32_t)u8Pwm_IsEnable_l << (shift & 0x1FU));/* polyspace RTE:OBAI */
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.GLB_CTRL.R >> (shift & 0x1FU)) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(1u):(2u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Reset Channel.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_ResetChannel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);    

    VAR(uint8_t, AUTOMATIC)  shift = ((uint8_t)ePwm_CHn % 8U) + (uint8_t)GTM4_ATOM_AGC_GLB_CTRL_RST_CH0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.GLB_CTRL.R = (uint32_t)((uint32_t)1UL << (shift & 0x1FU));

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief TGC0 Host Trigger.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_AGC_HostTrigger \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.GLB_CTRL.B.HOST_TRIG = 1U;

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief TGC0 Host Select ePwm_TimeBase.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_TimeBase ePwm_TimeBase type.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_AGC_SelectTimeBase \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_TimeBase_Type, AUTOMATIC) ePwm_TimeBase \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ACT_TB.B.TBU_SEL = (uint8_t)ePwm_TimeBase;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ACT_TB.B.TBU_SEL != (uint8_t)ePwm_TimeBase)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*
 * @brief Set TGC0 Action Time.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] u32Pwm_ActionTime Action Time.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_AGC_SetActionTime \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ACT_TB.B.ACT_TB = u32Pwm_ActionTime;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ACT_TB.B.ACT_TB != u32Pwm_ActionTime)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Force Update enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableForceUpdateCN0Reset \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_FUPD_CTRL_RSTCN0_CH0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R = (uint32_t)((uint32_t)u8Pwm_IsEnable_l << (shift & 0x1FU));
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R >> (shift & 0x1FU)) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableForceUpdate \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

     uint8_t  shift = ((uint8_t)ePwm_CHn * 2U) + (uint8_t)GTM4_ATOM_AGC_FUPD_CTRL_FUPD_CTRL0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R = (uint32_t)((uint32_t)u8Pwm_IsEnable_l << (shift & 0x1FU));
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.FUPD_CTRL.R >> (shift & 0x1FU)) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
* @brief Internal Trigger enable.
*
* @param[in] ePwm_GTM_ATOMn submodule.
* @param[in] ePwm_CHn Channel.
* @param[in] ePwm_IsEnable ePwm_IsEnable status.
*
* @return Operation status.
*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableInternalTrigger \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = ((uint8_t)ePwm_CHn * 2U) + (uint8_t)GTM4_ATOM_AGC_INT_TRIG_INT_TRIG0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.INT_TRIG.R = (uint32_t)((uint32_t)u8Pwm_IsEnable_l << (shift & 0x1FU));
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.INT_TRIG.R >> (shift & 0x1FU)) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Update Value enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableUpdateValue \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8)ePwm_GTM_ATOMn < (uint8)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8)ePwm_CHn < (uint8)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;
    VAR(uint32, AUTOMATIC) reg;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = ((uint8)ePwm_CHn * 2U) + (uint8)GTM4_ATOM_AGC_ENDIS_CTRL_ENDIS_CTRL0_OFF;

    reg = GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ENDIS_CTRL.R;
    reg &= (uint32)(~((0x3UL << shift)));
    reg |= ((uint32)u8Pwm_IsEnable_l << shift);
    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ENDIS_CTRL.R = reg;

    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ENDIS_CTRL.R >> shift) & 0x3u) != u8Pwm_IsEnable_l)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Channel enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableChannel \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2U;
    }
    else
    {
        u8Pwm_IsEnable_l = 1U;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_ENDIS_STAT_ENDIS_STAT0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ENDIS_STAT.R = (uint32_t)((uint32_t)u8Pwm_IsEnable_l << (shift & 0x1FU));
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.ENDIS_STAT.R >> (shift & 0x1FU)) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*
 * @brief OutUpdate Value enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableOutUpdateValue \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8)ePwm_GTM_ATOMn < (uint8)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8)ePwm_CHn < (uint8)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;
    VAR(uint32, AUTOMATIC) reg;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8)ePwm_CHn % 8U) * 2U) + (uint8)GTM4_ATOM_AGC_OUTEN_CTRL_OUTEN_CTRL0_OFF;

    reg = GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_CTRL.R;
    reg &= (uint32)(~((0x3UL << shift)));
    reg |= ((uint32)u8Pwm_IsEnable_l << shift);
    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_CTRL.R = reg;

    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_CTRL.R >> shift) & 0x3u) != u8Pwm_IsEnable_l)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief Out enable.
 *
 * @param[in] ePwm_GTM_ATOMn submodule.
 * @param[in] ePwm_CHn Channel.
 * @param[in] ePwm_IsEnable ePwm_IsEnable status.
 *
 * @return Operation status.
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_IsEnableOut \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) ePwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) u8Pwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(u8Pwm_IsEnable_l == 1U)
    {
        u8Pwm_IsEnable_l = 2u;
    }
    else
    {
        u8Pwm_IsEnable_l = 1u;
    }

    VAR(uint8, AUTOMATIC)  shift = (((uint8_t)ePwm_CHn % 8U) * 2U) + (uint8_t)GTM4_ATOM_AGC_OUTEN_STAT_OUTEN_STAT0_OFF;

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_STAT.R = (uint32_t)((uint32_t)u8Pwm_IsEnable_l << (shift & 0x1FU));
    if(((GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_STAT.R >> (shift & 0x1FU)) & 0x3u) != ((u8Pwm_IsEnable_l == 1u)?(0u):(3u)))
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_GTM410 */
#ifdef __cplusplus
}
#endif

/********************************** add **********************************/

#ifdef __cplusplus
extern "C"{
#endif

#if (defined(RESOURCE_SUPPORT_GTM410))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) SetTomChannelSL \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SL = (uint8_t)u8Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CTRL.B.SL != (uint8_t)u8Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) SetAtomChannelSL \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_Val \
)
{

    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL_SR.B.SL_SR = (uint8_t)u8Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CTRL_SR.B.SL_SR != (uint8_t)u8Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) SetTomChannelCM0 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM0.R = u32Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM0.R != u32Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) SetTomChannelCM1 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM1.R = u32Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].CM1.R != u32Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) SetAtomChannelCM0 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM0.B.CM0 = u32Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM0.B.CM0 != u32Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) SetAtomChannelCM1 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_Val \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM1.B.CM1 = u32Pwm_Val;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].CM1.B.CM1 != u32Pwm_Val)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetShadowRegister0 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint16, AUTOMATIC, PWM_APPL_DATA) pPwm_SR0 \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    *pPwm_SR0 = (uint16)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.B.SR0;/* polyspace RTE:OBAI,NIV */

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetShadowRegister1 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint16, AUTOMATIC, PWM_APPL_DATA) pPwm_SR1 \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    *pPwm_SR1 = (uint16)GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.B.SR1;

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetShadowRegister0 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_SR0 \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    *pPwm_SR0 = GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0;/* polyspace RTE:OBAI,NIV */

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetShadowRegister1 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_SR1 \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

   *pPwm_SR1 = GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1;

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetEnableOut \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
/*    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \ */
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_IsEnable \
)
{
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    /* (GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);) */

    *pPwm_IsEnable = GTM4.GLS[ePwm_GTM_TOMn].TOM.TGC0_OUTEN_STAT.R;

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetEnableOut \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    /*VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \*/
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_IsEnable \
)
{
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    /* (GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);) */

    *pPwm_IsEnable = GTM4.GLS[ePwm_GTM_ATOMn].ATOM.AGC.OUTEN_STAT.R;

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __HIGHTEC__
#pragma GCC diagnostic push
#pragma GCC optimize("O0")
#endif

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetShadowRegister0 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR0 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.R = u16Pwm_SR0;/* polyspace RTE:OBAI */
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR0.R != u16Pwm_SR0)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __HIGHTEC__
#pragma GCC diagnostic pop
#endif

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_SetShadowRegister1 \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint16, AUTOMATIC) u16Pwm_SR1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    GTM4_TOM_DET_ERR((uint8_t)ePwm_GTM_TOMn < (uint8_t)GTM4_TOM_INSTANCE_NUM);
    GTM4_TOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_TOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.R = u16Pwm_SR1;
    if(GTM4.GLS[ePwm_GTM_TOMn].TOM.CH[ePwm_CHn].SR1.R != u16Pwm_SR1)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetShadowRegister0 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR0 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0 = u32Pwm_SR0;/* polyspace RTE:OBAI */
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR0.B.SR0 != u32Pwm_SR0)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_SetShadowRegister1 \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint32, AUTOMATIC) u32Pwm_SR1 \
)
{
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue  = STATUS_SUCCESS;
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_GTM_ATOMn < (uint8_t)GTM4_ATOM_INSTANCE_NUM);
    GTM4_ATOM_DET_ERR((uint8_t)ePwm_CHn < (uint8_t)GTM4_ATOM_CHANNEL_NUM);

    GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1 = u32Pwm_SR1;
    if(GTM4.GLS[ePwm_GTM_ATOMn].ATOM.CH[ePwm_CHn].SR1.B.SR1 != u32Pwm_SR1)
    {
        ePwm_ReturnValue = STATUS_ERROR;
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*
 * @brief GTM HRES enable
 *
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status
 */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(Std_ReturnType, PWM_CODE) GTM_ATOM_LLD_HresEn(void)
{
    GTM4.GLS[0].GLSDLLCTRL[0].R = ((uint32_t)0x33030000UL | (uint32_t)1UL);
    GTM4.GLS[0].GLSDLLCTRL[1].R = ((uint32_t)0x33030000UL | (uint32_t)1UL);

    return (Std_ReturnType)STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef RESOURCE_SUPPORT_GTM410_TOUT
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_LLD_SetToutSel \
( \
    VAR(uint32, AUTOMATIC) u32Pwm_TOUT_NUM, \
    VAR(uint32, AUTOMATIC) u32Pwm_TOUT_SEL \
)
{
    GTM4.GLS[0].TOUTSEL[u32Pwm_TOUT_NUM / (uint32_t)8UL].R |= (u32Pwm_TOUT_SEL << ((uint32_t)0x4UL * (u32Pwm_TOUT_NUM % (uint32_t)8UL)));/* polyspace RTE:OBAI */

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif  /* RESOURCE_SUPPORT_GTM410_TOUT */

#endif /* RESOURCE_SUPPORT_GTM410 */
#ifdef __cplusplus
}
#endif


