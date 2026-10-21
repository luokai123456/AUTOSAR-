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
* @file     gtm_tom_lld.c
* @version  3.0.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 3432 EOF */
/* PRQA S 2844 EOF */
/* PRQA S 1820,2052,3004,3108,3395,3401,4521,4524,4543,4434 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm_LLDriver.h" /* PRQA S 0380 */
#include "Gpt_Gtm_LLDriver.h"

#if (defined(RESOURCE_SUPPORT_GTM104))

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

typedef volatile struct GTM_TOM_tag st_GTM_TOM_tag;

#define GTM_TOM_0_BASE_ADDR                          (&GTM_TOM_0)
#define GTM_TOM_1_BASE_ADDR                          (&GTM_TOM_1)
#define GTM_TOM_2_BASE_ADDR                          (&GTM_TOM_2)
#define GTM_TOM_3_BASE_ADDR                          (&GTM_TOM_3)
#define GTM_TOM_4_BASE_ADDR                          (&GTM_TOM_4)

#define PWM_START_SEC_VAR_INIT
#include "Pwm_MemMap.h"
static P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) g_GTM_TOM_Base[5U] = {GTM_TOM_0_BASE_ADDR, \
                                                                      GTM_TOM_1_BASE_ADDR, \
                                                                      GTM_TOM_2_BASE_ADDR, \
                                                                      GTM_TOM_3_BASE_ADDR, \
                                                                      GTM_TOM_4_BASE_ADDR};  /* PRQA S 1504,3408 */
#define PWM_STOP_SEC_VAR_INIT
#include "Pwm_MemMap.h"

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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CTRL.B.GCM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH0_CTRL.B.GCM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CTRL.B.GCM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH1_CTRL.B.GCM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CTRL.B.GCM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH2_CTRL.B.GCM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CTRL.B.GCM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH3_CTRL.B.GCM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CTRL.B.GCM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH4_CTRL.B.GCM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CTRL.B.GCM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH5_CTRL.B.GCM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CTRL.B.GCM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH6_CTRL.B.GCM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CTRL.B.GCM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH7_CTRL.B.GCM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CTRL.B.SPEM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH0_CTRL.B.SPEM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CTRL.B.SPEM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH1_CTRL.B.SPEM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CTRL.B.SPEM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH2_CTRL.B.SPEM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CTRL.B.SPEM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH3_CTRL.B.SPEM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CTRL.B.SPEM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH4_CTRL.B.SPEM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CTRL.B.SPEM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH5_CTRL.B.SPEM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CTRL.B.SPEM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH6_CTRL.B.SPEM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {

        pPwm_GTM_TOM_n->CH7_CTRL.B.SPEM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH7_CTRL.B.SPEM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }        
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH0_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH1_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH2_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH3_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH4_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH5_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH6_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH7_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH8_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:   
    {
        pPwm_GTM_TOM_n->CH9_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH9_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH10_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH11_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH12_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH13_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH14_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_TOM_n->CH15_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH0_CTRL.B.TRIGOUT !=(uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH1_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH2_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH3_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH4_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH5_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH6_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH7_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH8_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH9_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH10_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH11_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH12_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH13_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH14_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_TOM_n->CH15_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH0_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH1_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH2_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH3_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH4_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH5_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH6_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH7_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH8_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH9_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH10_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH11_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH12_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH13_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH14_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CTRL.B.RST_CCU0 = (uint8)ePwm_CCU0ResetSource;
        if(pPwm_GTM_TOM_n->CH15_CTRL.B.RST_CCU0 != (uint8)ePwm_CCU0ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];/* polyspace RTE:OBAI */  

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH0_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH1_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH2_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH3_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH4_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH5_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH6_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH7_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH8_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH9_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH10_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH11_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH12_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH13_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH14_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_TOM_n->CH15_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
    }

    return ePwm_ReturnValue;
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(uint32, PWM_VAR) SignalLevel_Reg = ((uint32)ePwm_SignalLevel << 11U);

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH0_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH1_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH2_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH3_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH4_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH5_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH6_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH7_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH8_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH9_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH10_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH11_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH12_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH13_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH14_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CTRL.R = SignalLevel_Reg;
        if((pPwm_GTM_TOM_n->CH15_CTRL.R & SignalLevel_Reg) != SignalLevel_Reg )
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
    }

    return ePwm_ReturnValue;
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH0_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH1_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH2_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH3_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH4_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH5_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH6_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH7_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH8_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH9_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH10_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH11_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH12_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH13_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH14_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_SR0.B.SR0 = u16Pwm_SR0;
        pPwm_GTM_TOM_n->CH15_SR1.B.SR1 = u16Pwm_SR1;
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH0_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH1_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH2_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH3_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH4_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH5_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH6_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH7_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH8_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH9_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH10_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH11_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH12_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH13_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH14_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CM0.B.CM0 = u16Pwm_CM0;
        pPwm_GTM_TOM_n->CH15_CM1.B.CM1 = u16Pwm_CM1;
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH0_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH1_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH2_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH3_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH4_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH5_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH6_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH7_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH8_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH9_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH10_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH11_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH12_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH13_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH14_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CN0.B.CN0 = u16Pwm_CN0;
        if(pPwm_GTM_TOM_n->CH15_CN0.B.CN0 != u16Pwm_CN0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    VAR(uint16, AUTOMATIC) ePwm_ReturnValue = 0U;
    P2CONST(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_CONST) pPwm_GTM_TOM_n \
        = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH0_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH1:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH1_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH2:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH2_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH3:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH3_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH4:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH4_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH5:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH5_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH6:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH6_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH7:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH7_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH8:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH8_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH9:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH9_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH10:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH10_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH11:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH11_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH12:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH12_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH13:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH13_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH14:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH14_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH15:
    {
        ePwm_ReturnValue = (uint16)pPwm_GTM_TOM_n->CH15_CN0.B.CN0;/* polyspace RTE:NIV */ 
        break;
    }
    default:
    {
        /* Do nothing */
        break;
    }
    }

    return ePwm_ReturnValue;
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
    VAR(uint8, AUTOMATIC) u8Pwm_ReturnValue = 0U;
    P2CONST(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_CONST) pPwm_GTM_TOM_n \
        = g_GTM_TOM_Base[ePwm_GTM_TOMn];/* polyspace RTE:OBAI */  

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH0_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH1:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH1_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH2:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH2_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH3:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH3_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH4:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH4_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH5:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH5_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH6:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH6_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH7:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH7_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH8:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH8_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH9:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH9_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH10:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH10_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH11:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH11_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH12:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH12_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH13:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH13_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH14:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH14_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH15:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_TOM_n->CH15_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    default:
    {
        /* nothing */
        break;
    }
    }

    return u8Pwm_ReturnValue;
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
    P2CONST(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_CONST) pPwm_GTM_TOM_n \
        = g_GTM_TOM_Base[ePwm_GTM_TOMn];/* polyspace RTE:OBAI */  

    uint32* pTestBase = 0;

    pTestBase = (uint32*)((uint32)(&pPwm_GTM_TOM_n->CH0_IRQ_NOTIFY.R) + 0x40 * ePwm_CHn);

    u8Pwm_ReturnValue = (uint8)(((*pTestBase) >> ePwm_Interrupt) & (0x1u));/* polyspace RTE:COR,NIV,IDP */ 

//    switch(ePwm_CHn)
//    {
//    case GTM_TOM_CH0:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH0_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH0_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH1:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH1_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH1_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH2:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH2_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH2_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH3:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH3_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH3_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH4:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH4_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH4_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH5:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH5_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH5_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH6:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH6_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH6_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH7:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH7_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH7_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH8:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH8_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH8_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH9:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH9_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH9_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH10:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH10_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH10_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH11:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH11_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH11_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH12:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH12_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH12_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH13:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH13_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH13_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH14:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH14_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH14_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH15:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH15_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_TOM_n->CH15_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    default:
//    {
//        /* nothing */
//        break;
//    }
//    }

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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    uint32* pTestBase = 0;

    pTestBase = (uint32*)((uint32)(&pPwm_GTM_TOM_n->CH0_IRQ_NOTIFY.R) + 0x40 * ePwm_CHn);

    *pTestBase = (1 << ePwm_Interrupt);/* polyspace RTE:IDP */


//    switch(ePwm_CHn)
//    {
//    case GTM_TOM_CH0:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH0_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH0_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH0_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH0_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH1:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH1_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH1_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH1_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH1_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH2:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH2_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH2_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH2_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH2_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH3:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH3_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH3_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH3_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH3_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH4:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH4_IRQ_NOTIFY.B.CCU0TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH4_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH4_IRQ_NOTIFY.B.CCU1TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH4_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH5:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH5_IRQ_NOTIFY.B.CCU0TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH5_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH5_IRQ_NOTIFY.B.CCU1TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH5_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH6:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH6_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH6_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH6_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH6_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH7:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH7_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH7_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH7_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH7_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH8:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH8_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH8_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH8_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH8_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH9:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH9_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH9_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH9_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH9_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH10:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH10_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH10_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH10_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH10_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH11:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH11_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_TOM_n->CH11_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH11_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_TOM_n->CH11_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH12:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH12_IRQ_NOTIFY.B.CCU0TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH12_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH12_IRQ_NOTIFY.B.CCU1TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH12_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH13:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH13_IRQ_NOTIFY.B.CCU0TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH13_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH13_IRQ_NOTIFY.B.CCU1TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH13_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH14:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH14_IRQ_NOTIFY.B.CCU0TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH14_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH14_IRQ_NOTIFY.B.CCU1TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH14_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_TOM_CH15:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case TOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_TOM_n->CH15_IRQ_NOTIFY.B.CCU0TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH15_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case TOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_TOM_n->CH15_IRQ_NOTIFY.B.CCU1TC = (uint8)ePwm_Interrupt;
//            if(pPwm_GTM_TOM_n->CH15_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    default:
//    {
//        ePwm_ReturnValue = STATUS_ERROR;
//        break;
//    }
//    }

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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];/* polyspace RTE:OBAI */  

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH0_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH0_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH0_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH0_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH1_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH1_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH1_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH1_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH2_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH2_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH2_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH2_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH3_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH3_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH3_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH3_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH4_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH4_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH4_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH4_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH5_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH5_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH5_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH5_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH6_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH6_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH6_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH6_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH7_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH7_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH7_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH7_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH8_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH8_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH8_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH8_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH9_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH9_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH9_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH9_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH10_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH10_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH10_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH10_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH11_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_Interrupt;
            if(pPwm_GTM_TOM_n->CH11_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH11_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_Interrupt;
            if(pPwm_GTM_TOM_n->CH11_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH12_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_Interrupt;
            if(pPwm_GTM_TOM_n->CH12_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH12_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_Interrupt;
            if(pPwm_GTM_TOM_n->CH12_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH13_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH13_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH13_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH13_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH14_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH14_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH14_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH14_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH15_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH15_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH15_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_TOM_n->CH15_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH0_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH0_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH1_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH1_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH2_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH2_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH3_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH3_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH4_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH4_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH5_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH5_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH6_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH6_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH7_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH7_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH8_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH8_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH9_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH9_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH10_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH10_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH11_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH11_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH12_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH12_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH13_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH13_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH14_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH14_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        switch(ePwm_Interrupt)
        {
        case TOM_IRQ_CCU0TC:
        {
            pPwm_GTM_TOM_n->CH15_IRQ_FORCINT.B.TRG_CCU0TC0 = 1u;
            break;
        }
        case TOM_IRQ_CCU1TC:
        {
            pPwm_GTM_TOM_n->CH15_IRQ_FORCINT.B.TRG_CCU1TC0 = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH0_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH1_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH2_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH3_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH4_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH5_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH6_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH7_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH8_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH9_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH10_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH11_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH12_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH13_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH14_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_TOM_n->CH15_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];/* polyspace RTE:OBAI */  

    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8) ePwm_IsEnable;

    if(ePwm_IsEnable_l == 1u)
    {
        ePwm_IsEnable_l = 2;
    }
    else
    {
        ePwm_IsEnable_l = 1;
    }

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL0 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL0 \
                != (((uint8)ePwm_IsEnable_l == 1u)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL1 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL1 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL2 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL2 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL3 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL3 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL4 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL4 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL5 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL5 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL6 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL6 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL7 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL7 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL8 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL8 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL9 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL9 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL10 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL10 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL11 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL11 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL12 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL12 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL13 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL13 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL14 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL14 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL15 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL15 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
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
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.RST_CH0 = 1u;
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.RST_CH1 = 1u;
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.RST_CH2 = 1u;
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.RST_CH3 = 1u;
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.RST_CH4 = 1u;
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.RST_CH5 = 1u;
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.RST_CH6 = 1u;
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.RST_CH7 = 1u;
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.RST_CH8 = 1u;
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.RST_CH9 = 1u;
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.RST_CH10 = 1u;
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.RST_CH11 = 1u;
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.RST_CH12 = 1u;
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.RST_CH13 = 1u;
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.RST_CH14 = 1u;
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.RST_CH15 = 1u;
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
    }

    return ePwm_ReturnValue;
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    pPwm_GTM_TOM_n->TGC0_GLB_CTRL.B.HOST_TRIG = 1u;

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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    pPwm_GTM_TOM_n->TGC1_GLB_CTRL.B.HOST_TRIG = 1u;

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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    pPwm_GTM_TOM_n->TGC0_ACT_TB.B.TBU_SEL = (uint8)ePwm_TimeBase;

    if(pPwm_GTM_TOM_n->TGC0_ACT_TB.B.TBU_SEL  != (uint8)ePwm_TimeBase)
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    pPwm_GTM_TOM_n->TGC1_ACT_TB.B.TBU_SEL = (uint8)ePwm_TimeBase;

    if(pPwm_GTM_TOM_n->TGC1_ACT_TB.B.TBU_SEL  != (uint8)ePwm_TimeBase)
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime_l = u32Pwm_ActionTime;

    u32Pwm_ActionTime_l = (0x00ffffffU & u32Pwm_ActionTime_l);
    pPwm_GTM_TOM_n->TGC0_ACT_TB.B.ACT_TB = u32Pwm_ActionTime_l;

    if(pPwm_GTM_TOM_n->TGC0_ACT_TB.B.ACT_TB  != u32Pwm_ActionTime_l)
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(uint32, AUTOMATIC) u32Pwm_ActionTime_l = u32Pwm_ActionTime;

    u32Pwm_ActionTime_l = (0x00ffffffU & u32Pwm_ActionTime_l);
    pPwm_GTM_TOM_n->TGC1_ACT_TB.B.ACT_TB = u32Pwm_ActionTime_l;

    if(pPwm_GTM_TOM_n->TGC1_ACT_TB.B.ACT_TB  != u32Pwm_ActionTime_l)
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2;
    }
    else
    {
        ePwm_IsEnable_l = 1;
    }

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH0 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH0 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH1 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH1 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH2 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH2 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH3 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH3 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH4 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH4 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH5 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH5 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH6 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH6 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH7 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.RSTCN0_CH7 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH8 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH8 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH9 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH9 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH10 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH10 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH11 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH11 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH12 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH12 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH13 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH13 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH14 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH14 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH15 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.RSTCN0_CH15 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if(ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2;
    }
    else
    {
        ePwm_IsEnable_l = 1;
    }

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL0 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL0 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL1 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL1 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL2 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL2 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL3 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL3 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL4 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL4 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL5 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL5 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL6 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL6 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL7 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_FUPD_CTRL.B.FUPD_CTRL7 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL8 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL8 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL9 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL9 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL10 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL10 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL11 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL11 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL12 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL12 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL13 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL13 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL14 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL14 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL15 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_FUPD_CTRL.B.FUPD_CTRL15 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8) ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2U;
    }
    else
    {
        ePwm_IsEnable_l = 1U;
    }

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG0 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG0 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG1 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG1 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG2 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG2 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG3 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG3 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG4 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG4 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG5 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG5 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG6 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG6 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG7 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_INT_TRIG.B.INT_TRIG7 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG8 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG8 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG9 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG9 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG10 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG10 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG11 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG11 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG12 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG12 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG13 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG13 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG14 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG14 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG15 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_INT_TRIG.B.INT_TRIG15 != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2;

    }
    else
    {
        ePwm_IsEnable_l = 1;
    }

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL0 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL0 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL1 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL1 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL2 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL2 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL3 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL3 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL4 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL4 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL5 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL5 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL6 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL6 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL7 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_CTRL.B.ENDIS_CTRL7 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL8 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL8 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL9 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL9 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL10 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL10 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL11 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL11 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL12 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL12 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL13 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL13 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL14 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL14 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL15 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_CTRL.B.ENDIS_CTRL15 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
     VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2;
    }
    else
    {
        ePwm_IsEnable_l = 1;
    }

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT0 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT0 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT1 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT1 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT2 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT2 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT3 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT3 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT4 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT4 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT5 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT5 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT6 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT6 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT7 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT7 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT8 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT8 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT9 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT9 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT10 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT10 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT11 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT11 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT12 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT12 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT13 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT13 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT14 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT14 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT15 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT15 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;

    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2;
    }
    else
    {
        ePwm_IsEnable_l = 1;
    }

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL0 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL0 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL1 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL1 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL2 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL2 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL3 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL3 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL4 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL4 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL7 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_CTRL.B.OUTEN_CTRL7 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL8 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL8 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL9 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL9 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL10 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL10 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL11 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL11 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL12 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL12 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL13 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL13 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL14 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL14 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL15 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_CTRL.B.OUTEN_CTRL15 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(uint8, AUTOMATIC) ePwm_IsEnable_l = (uint8)ePwm_IsEnable;
    
    if((uint8)ePwm_IsEnable_l == 1U)
    {
        ePwm_IsEnable_l = 2;
    }
    else
    {
        ePwm_IsEnable_l = 1;
    }

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT0 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT0 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT1 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT1 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT2 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT2 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT3 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT3 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT4 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT4 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT5 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT5 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT6 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT6 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT7 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT7 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT8 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT8 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT9 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT9 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT10 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT10 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT11 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT11 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT12 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT12 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT13 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT13 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT14 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT14 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT15 = (uint8)ePwm_IsEnable_l;
        if(pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT15 \
                != (((uint8)ePwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

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
* @file     gtm_atom_lld.c
* @version  3.0.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0380,1317,1503,1296,1338,2016,2023,2024,4442 EOF*/

#ifdef __cplusplus
extern "C"{
#endif

typedef volatile struct GTM_ATOM_tag st_GTM_ATOM_tag;

#define GTM_ATOM_0_BASE_ADDR                          (&GTM_ATOM_0)
#define GTM_ATOM_1_BASE_ADDR                          (&GTM_ATOM_1)
#define GTM_ATOM_2_BASE_ADDR                          (&GTM_ATOM_2)
#define GTM_ATOM_3_BASE_ADDR                          (&GTM_ATOM_3)
#define GTM_ATOM_4_BASE_ADDR                          (&GTM_ATOM_4)
#define GTM_ATOM_5_BASE_ADDR                          (&GTM_ATOM_5)
#define GTM_ATOM_6_BASE_ADDR                          (&GTM_ATOM_6)
#define GTM_ATOM_7_BASE_ADDR                          (&GTM_ATOM_7)
#define GTM_ATOM_8_BASE_ADDR                          (&GTM_ATOM_8)

#define PWM_START_SEC_VAR_INIT
#include "Pwm_MemMap.h"
static P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) g_GTM_ATOM_Base[9u] = {GTM_ATOM_0_BASE_ADDR, \
                                                                        GTM_ATOM_1_BASE_ADDR, \
                                                                        GTM_ATOM_2_BASE_ADDR, \
                                                                        GTM_ATOM_3_BASE_ADDR, \
                                                                        GTM_ATOM_4_BASE_ADDR, \
                                                                        GTM_ATOM_5_BASE_ADDR, \
                                                                        GTM_ATOM_6_BASE_ADDR, \
                                                                        GTM_ATOM_7_BASE_ADDR, \
                                                                        GTM_ATOM_8_BASE_ADDR};  /* PRQA S 1504,3408 */
#define PWM_STOP_SEC_VAR_INIT
#include "Pwm_MemMap.h"

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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress0;
        pPwm_GTM_ATOM_n->CH0_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress1;
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress0;
        pPwm_GTM_ATOM_n->CH1_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress1;
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress0;
        pPwm_GTM_ATOM_n->CH2_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress1;
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress0;
        pPwm_GTM_ATOM_n->CH3_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress1;
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress0;
        pPwm_GTM_ATOM_n->CH4_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress1;
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress0;
        pPwm_GTM_ATOM_n->CH5_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress1;
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress0;
        pPwm_GTM_ATOM_n->CH6_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress1;
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress0;
        pPwm_GTM_ATOM_n->CH7_RDADDR.B.RDADDR0 = u16Pwm_ReadAddress1;
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.OSM = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.OSM != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.TRIGOUT = (uint8)ePwm_TriggerOutput;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.TRIGOUT != (uint8)ePwm_TriggerOutput)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.RST_CCU0 = (uint8)ePwm_ResetSource;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.RST_CCU0 != (uint8)ePwm_ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.RST_CCU0 = (uint8)ePwm_ResetSource;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.RST_CCU0 != (uint8)ePwm_ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.RST_CCU0 =(uint8) ePwm_ResetSource;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.RST_CCU0 != (uint8)ePwm_ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.RST_CCU0 = (uint8)ePwm_ResetSource;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.RST_CCU0 != (uint8)ePwm_ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.RST_CCU0 = (uint8)ePwm_ResetSource;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.RST_CCU0 != (uint8)ePwm_ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.RST_CCU0 = (uint8)ePwm_ResetSource;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.RST_CCU0 !=(uint8) ePwm_ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.RST_CCU0 = (uint8)ePwm_ResetSource;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.RST_CCU0 != (uint8)ePwm_ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.RST_CCU0 = (uint8)ePwm_ResetSource;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.RST_CCU0 != (uint8)ePwm_ResetSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];/* polyspace RTE:OBAI */  

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.CLK_SRC_SR = (uint8)ePwm_ClockSource;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.CLK_SRC_SR != (uint8)ePwm_ClockSource)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
    }

    return ePwm_ReturnValue;
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.SL = (uint8)ePwm_SignalLevel;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.SL != (uint8)ePwm_SignalLevel)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.SL = (uint8)ePwm_SignalLevel;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.SL != (uint8)ePwm_SignalLevel)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.SL = (uint8)ePwm_SignalLevel;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.SL != (uint8)ePwm_SignalLevel)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.SL = (uint8)ePwm_SignalLevel;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.SL != (uint8)ePwm_SignalLevel)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.SL = (uint8)ePwm_SignalLevel;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.SL != (uint8)ePwm_SignalLevel)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.SL = (uint8)ePwm_SignalLevel;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.SL != (uint8)ePwm_SignalLevel)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.SL = (uint8)ePwm_SignalLevel;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.SL != (uint8)ePwm_SignalLevel)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.SL = (uint8)ePwm_SignalLevel;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.SL != (uint8)ePwm_SignalLevel)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.CMP_CTRL = (uint8)ePwm_CompareStrategy;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.CMP_CTRL != (uint8)ePwm_CompareStrategy)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.CMP_CTRL = (uint8)ePwm_CompareStrategy;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.CMP_CTRL != (uint8)ePwm_CompareStrategy)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.CMP_CTRL = (uint8)ePwm_CompareStrategy;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.CMP_CTRL != (uint8)ePwm_CompareStrategy)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.CMP_CTRL = (uint8)ePwm_CompareStrategy;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.CMP_CTRL != (uint8)ePwm_CompareStrategy)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.CMP_CTRL = (uint8)ePwm_CompareStrategy;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.CMP_CTRL != (uint8)ePwm_CompareStrategy)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.CMP_CTRL = (uint8)ePwm_CompareStrategy;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.CMP_CTRL != (uint8)ePwm_CompareStrategy)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.CMP_CTRL = (uint8)ePwm_CompareStrategy;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.CMP_CTRL != (uint8)ePwm_CompareStrategy)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.CMP_CTRL = (uint8)ePwm_CompareStrategy;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.CMP_CTRL != (uint8)ePwm_CompareStrategy)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) \
        pPwm_GTM_ATOM_n = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.ACB = u8Pwm_ACBbits;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.ACB != u8Pwm_ACBbits)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.ACB = u8Pwm_ACBbits;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.ACB != u8Pwm_ACBbits)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.ACB = u8Pwm_ACBbits;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.ACB != u8Pwm_ACBbits)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.ACB = u8Pwm_ACBbits;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.ACB != u8Pwm_ACBbits)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.ACB = u8Pwm_ACBbits;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.ACB != u8Pwm_ACBbits)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.ACB = u8Pwm_ACBbits;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.ACB != u8Pwm_ACBbits)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.ACB = u8Pwm_ACBbits;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.ACB != u8Pwm_ACBbits)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.ACB = u8Pwm_ACBbits;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.ACB != u8Pwm_ACBbits)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.ARU_EN = (uint8)ePwm_IsEnable;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.ARU_EN != (uint8)ePwm_IsEnable)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.TB12_SEL = (uint8)ePwm_TimeBase;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.TB12_SEL != (uint8)ePwm_TimeBase)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.TB12_SEL = (uint8)ePwm_TimeBase;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.TB12_SEL != (uint8)ePwm_TimeBase)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.TB12_SEL = (uint8)ePwm_TimeBase;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.TB12_SEL != (uint8)ePwm_TimeBase)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.TB12_SEL = (uint8)ePwm_TimeBase;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.TB12_SEL != (uint8)ePwm_TimeBase)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.TB12_SEL = (uint8)ePwm_TimeBase;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.TB12_SEL != (uint8)ePwm_TimeBase)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.TB12_SEL = (uint8)ePwm_TimeBase;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.TB12_SEL != (uint8)ePwm_TimeBase)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.TB12_SEL = (uint8)ePwm_TimeBase;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.TB12_SEL != (uint8)ePwm_TimeBase)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.TB12_SEL = (uint8)ePwm_TimeBase;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.TB12_SEL != (uint8)ePwm_TimeBase)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.MODE = (uint8)ePwm_Mode;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.MODE != (uint8)ePwm_Mode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.MODE = (uint8)ePwm_Mode;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.MODE != (uint8)ePwm_Mode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.MODE = (uint8)ePwm_Mode;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.MODE != (uint8)ePwm_Mode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.MODE = (uint8)ePwm_Mode;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.MODE != (uint8)ePwm_Mode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.MODE = (uint8)ePwm_Mode;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.MODE != (uint8)ePwm_Mode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.MODE = (uint8)ePwm_Mode;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.MODE != (uint8)ePwm_Mode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.MODE = (uint8)ePwm_Mode;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.MODE != (uint8)ePwm_Mode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.MODE = (uint8)ePwm_Mode;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.MODE != (uint8)ePwm_Mode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_SR0.B.SR0 = u32Pwm_SR0;
        pPwm_GTM_ATOM_n->CH0_SR1.B.SR1 = u32Pwm_SR1;
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_SR0.B.SR0 = u32Pwm_SR0;
        pPwm_GTM_ATOM_n->CH1_SR1.B.SR1 = u32Pwm_SR1;
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_SR0.B.SR0 = u32Pwm_SR0;
        pPwm_GTM_ATOM_n->CH2_SR1.B.SR1 = u32Pwm_SR1;
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_SR0.B.SR0 = u32Pwm_SR0;
        pPwm_GTM_ATOM_n->CH3_SR1.B.SR1 = u32Pwm_SR1;
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_SR0.B.SR0 = u32Pwm_SR0;
        pPwm_GTM_ATOM_n->CH4_SR1.B.SR1 = u32Pwm_SR1;
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_SR0.B.SR0 = u32Pwm_SR0;
        pPwm_GTM_ATOM_n->CH5_SR1.B.SR1 = u32Pwm_SR1;
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_SR0.B.SR0 = u32Pwm_SR0;
        pPwm_GTM_ATOM_n->CH6_SR1.B.SR1 = u32Pwm_SR1;
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_SR0.B.SR0 = u32Pwm_SR0;
        pPwm_GTM_ATOM_n->CH7_SR1.B.SR1 = u32Pwm_SR1;
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CM0.B.CM0 = u32Pwm_CM0;
        pPwm_GTM_ATOM_n->CH0_CM1.B.CM1 = u32Pwm_CM1;
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CM0.B.CM0 = u32Pwm_CM0;
        pPwm_GTM_ATOM_n->CH1_CM1.B.CM1 = u32Pwm_CM1;
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CM0.B.CM0 = u32Pwm_CM0;
        pPwm_GTM_ATOM_n->CH2_CM1.B.CM1 = u32Pwm_CM1;
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CM0.B.CM0 = u32Pwm_CM0;
        pPwm_GTM_ATOM_n->CH3_CM1.B.CM1 = u32Pwm_CM1;
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CM0.B.CM0 = u32Pwm_CM0;
        pPwm_GTM_ATOM_n->CH4_CM1.B.CM1 = u32Pwm_CM1;
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CM0.B.CM0 = u32Pwm_CM0;
        pPwm_GTM_ATOM_n->CH5_CM1.B.CM1 = u32Pwm_CM1;
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CM0.B.CM0 = u32Pwm_CM0;
        pPwm_GTM_ATOM_n->CH6_CM1.B.CM1 = u32Pwm_CM1;
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CM0.B.CM0 = u32Pwm_CM0;
        pPwm_GTM_ATOM_n->CH7_CM1.B.CM1 = u32Pwm_CM1;
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(uint32, AUTOMATIC) u32Pwm_CN0_l = u32Pwm_CN0;

    u32Pwm_CN0_l = ((uint32)0x00ffffffUL & u32Pwm_CN0_l);

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CN0.B.CN0 = u32Pwm_CN0_l;
        if(pPwm_GTM_ATOM_n->CH0_CN0.B.CN0 != u32Pwm_CN0_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CN0.B.CN0 = u32Pwm_CN0_l;
        if(pPwm_GTM_ATOM_n->CH1_CN0.B.CN0 != u32Pwm_CN0_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CN0.B.CN0 = u32Pwm_CN0_l;
        if(pPwm_GTM_ATOM_n->CH2_CN0.B.CN0 != u32Pwm_CN0_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CN0.B.CN0 = u32Pwm_CN0_l;
        if(pPwm_GTM_ATOM_n->CH3_CN0.B.CN0 != u32Pwm_CN0_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CN0.B.CN0 = u32Pwm_CN0_l;
        if(pPwm_GTM_ATOM_n->CH4_CN0.B.CN0 != u32Pwm_CN0_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CN0.B.CN0 = u32Pwm_CN0_l;
        if(pPwm_GTM_ATOM_n->CH5_CN0.B.CN0 != u32Pwm_CN0_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CN0.B.CN0 = u32Pwm_CN0_l;
        if(pPwm_GTM_ATOM_n->CH6_CN0.B.CN0 != u32Pwm_CN0_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CN0.B.CN0 = u32Pwm_CN0_l;
        if(pPwm_GTM_ATOM_n->CH7_CN0.B.CN0 != u32Pwm_CN0_l)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2CONST(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_CONST) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];/* polyspace RTE:OBAI */  
    VAR(uint8, AUTOMATIC) u8Pwm_ReturnValue = 0U;

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH0_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH1:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_ATOM_n->CH1_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH2:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_ATOM_n->CH2_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH3:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_ATOM_n->CH3_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH4:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_ATOM_n->CH4_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH5:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_ATOM_n->CH5_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH6:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_ATOM_n->CH6_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH7:
    {
        u8Pwm_ReturnValue =  (uint8)pPwm_GTM_ATOM_n->CH7_STAT.B.OL;/* polyspace RTE:NIV */ 
        break;
    }
    default:
    {
        /* nothing */
        break;
    }
    }

    return u8Pwm_ReturnValue;
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
    P2CONST(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_CONST) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];/* polyspace RTE:OBAI */  
    VAR(uint8, AUTOMATIC) u8Pwm_ReturnValue = 0U;

    uint32* pTestBase = 0;

    pTestBase = (uint32*)((uint32)(&pPwm_GTM_ATOM_n->CH0_IRQ_NOTIFY.R) + 0x40 * ePwm_CHn);

    u8Pwm_ReturnValue = (uint8)(((*pTestBase) >> ePwm_Interrupt) & (0x1u));/* polyspace RTE:NIV,IDP */

//    switch(ePwm_CHn)
//    {
//    case GTM_ATOM_CH0:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH0_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH0_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH1:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH1_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH1_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH2:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH2_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH2_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH3:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH3_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH3_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH4:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH4_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH4_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH5:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH5_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH5_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH6:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH6_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH6_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH7:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH7_IRQ_NOTIFY.B.CCU0TC;
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            u8Pwm_ReturnValue = (uint8)pPwm_GTM_ATOM_n->CH7_IRQ_NOTIFY.B.CCU1TC;
//            break;
//        }
//        default:
//        {
//            /* nothing */
//            break;
//        }
//        }
//        break;
//    }
//    default:
//    {
//        /* nothing */
//        break;
//    }
//    }

    return u8Pwm_ReturnValue;
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    uint32* pTestBase = 0;

    pTestBase = (uint32*)((uint32)(&pPwm_GTM_ATOM_n->CH0_IRQ_NOTIFY.R) + 0x40 * ePwm_CHn);

    *pTestBase = (1 << ePwm_Interrupt);/* polyspace RTE:IDP */

//
//    switch(ePwm_CHn)
//    {
//    case GTM_ATOM_CH0:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_ATOM_n->CH0_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH0_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_ATOM_n->CH0_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH0_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH1:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_ATOM_n->CH1_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH1_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_ATOM_n->CH1_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH1_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH2:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_ATOM_n->CH2_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH2_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_ATOM_n->CH2_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH2_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH3:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_ATOM_n->CH3_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH3_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_ATOM_n->CH3_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH3_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH4:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_ATOM_n->CH4_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH4_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_ATOM_n->CH4_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH4_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH5:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_ATOM_n->CH5_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH5_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_ATOM_n->CH5_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH5_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH6:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_ATOM_n->CH6_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH6_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_ATOM_n->CH6_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH6_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    case GTM_ATOM_CH7:
//    {
//        switch(ePwm_Interrupt)
//        {
//        case ATOM_IRQ_CCU0TC:
//        {
//            pPwm_GTM_ATOM_n->CH7_IRQ_NOTIFY.B.CCU0TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH7_IRQ_NOTIFY.B.CCU0TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        case ATOM_IRQ_CCU1TC:
//        {
//            pPwm_GTM_ATOM_n->CH7_IRQ_NOTIFY.B.CCU1TC = 1u;
//            if(pPwm_GTM_ATOM_n->CH7_IRQ_NOTIFY.B.CCU1TC != 0u)
//            {
//                ePwm_ReturnValue = STATUS_ERROR;
//            }
//            break;
//        }
//        default:
//        {
//            ePwm_ReturnValue = STATUS_ERROR;
//            break;
//        }
//        }
//        break;
//    }
//    default:
//    {
//        ePwm_ReturnValue = STATUS_ERROR;
//        break;
//    }
//    }
//
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];/* polyspace RTE:OBAI */  
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH0_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH0_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH0_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH0_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH1_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH1_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH1_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH1_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH2_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH2_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH2_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH2_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH3_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH3_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH3_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH3_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH4_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH4_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH4_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH4_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH5_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH5_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH5_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH5_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH6_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH6_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH6_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH6_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH7_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH7_IRQ_EN.B.CCU0TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH7_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)ePwm_IsEnable;
            if(pPwm_GTM_ATOM_n->CH7_IRQ_EN.B.CCU1TC_IRQ_EN != (uint8)ePwm_IsEnable)
            {
                ePwm_ReturnValue = STATUS_ERROR;
            }
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH0_IRQ_FORCINT.B.TRG_CCU0TC = 1u;
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH0_IRQ_FORCINT.B.TRG_CCU1TC = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH1_IRQ_FORCINT.B.TRG_CCU0TC = 1u;
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH1_IRQ_FORCINT.B.TRG_CCU1TC = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH2_IRQ_FORCINT.B.TRG_CCU0TC = 1u;
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH2_IRQ_FORCINT.B.TRG_CCU1TC = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH3_IRQ_FORCINT.B.TRG_CCU0TC = 1u;
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH3_IRQ_FORCINT.B.TRG_CCU1TC = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH4_IRQ_FORCINT.B.TRG_CCU0TC = 1u;
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH4_IRQ_FORCINT.B.TRG_CCU1TC = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH5_IRQ_FORCINT.B.TRG_CCU0TC = 1u;
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH5_IRQ_FORCINT.B.TRG_CCU1TC = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH6_IRQ_FORCINT.B.TRG_CCU0TC = 1u;
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH6_IRQ_FORCINT.B.TRG_CCU1TC = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        switch(ePwm_Interrupt)
        {
        case ATOM_IRQ_CCU0TC:
        {
            pPwm_GTM_ATOM_n->CH7_IRQ_FORCINT.B.TRG_CCU0TC = 1u;
            break;
        }
        case ATOM_IRQ_CCU1TC:
        {
            pPwm_GTM_ATOM_n->CH7_IRQ_FORCINT.B.TRG_CCU1TC = 1u;
            break;
        }
        default:
        {
            ePwm_ReturnValue = STATUS_ERROR;
            break;
        }
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_ATOM_n->CH0_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_ATOM_n->CH1_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_ATOM_n->CH2_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_ATOM_n->CH3_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_ATOM_n->CH4_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_ATOM_n->CH5_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_ATOM_n->CH6_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_IRQ_MODE.B.IRQ_MODE = (uint8)ePwm_InterruptMode;
        if(pPwm_GTM_ATOM_n->CH7_IRQ_MODE.B.IRQ_MODE != (uint8)ePwm_InterruptMode)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];/* polyspace RTE:OBAI */  
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

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL0 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL0 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL1 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL1 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL2 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL2 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL3 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL3 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL4 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL4 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL5 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL5 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL6 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL6 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL7 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.UPEN_CTRL7 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;    

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.RST_CH0 = 1u;
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.RST_CH1 = 1u;
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.RST_CH2 = 1u;
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.RST_CH3 = 1u;
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.RST_CH4 = 1u;
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.RST_CH5 = 1u;
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.RST_CH6 = 1u;
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.RST_CH7 = 1u;
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
    }

    return ePwm_ReturnValue;
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    pPwm_GTM_ATOM_n->AGC_GLB_CTRL.B.HOST_TRIG = 1u;

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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    pPwm_GTM_ATOM_n->AGC_ACT_TB.B.TBU_SEL = (uint8)ePwm_TimeBase;

    if(pPwm_GTM_ATOM_n->AGC_ACT_TB.B.TBU_SEL  != (uint8)ePwm_TimeBase)
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    pPwm_GTM_ATOM_n->AGC_ACT_TB.B.ACT_TB = u32Pwm_ActionTime;

    if(pPwm_GTM_ATOM_n->AGC_ACT_TB.B.ACT_TB  != u32Pwm_ActionTime)
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
     = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
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

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH0 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH0 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH1 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH1 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH2 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH2 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH3 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH3 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH4 = (uint8)u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH4 != (((uint8)u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH5 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH5 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH6 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH6 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH7 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.RSTCN0_CH7 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
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

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL0 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL0 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL1 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL1 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL2 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL2 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL3 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL3 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL4 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL4 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL5 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL5 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL6 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL6 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL7 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_FUPD_CTRL.B.FUPD_CTRL7 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
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

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG0 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG0 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG1 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG1 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG2 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG2 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG3 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG3 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG4 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG4 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG5 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG5 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG6 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG6 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG7 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_INT_TRIG.B.INT_TRIG7 != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
            = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
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

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL0 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL0 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL1 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL1 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL2 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL2 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL3 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL3 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL4 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL4 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL5 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL5 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL6 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL6 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL7 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_CTRL.B.ENDIS_CTRL7 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
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

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT0 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT0 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue =  STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT1 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT1 \
                != (((uint8)ePwm_IsEnable == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue =  STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT2 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT2 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue =  STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT3 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT3 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue =  STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT4 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT4 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue =  STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT5 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT5 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue =  STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT6 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT6 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue =  STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT7 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_ENDIS_STAT.B.ENDIS_STAT7 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue =  STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue =  STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
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

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL0 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL0 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL1 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL1 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL2 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL2 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL3 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL3 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL4 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL4 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL5 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL5 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL6 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL6 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL7 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_CTRL.B.OUTEN_CTRL7 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
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

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT0 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT0 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT1 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT1 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT2 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT2 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT3 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT3 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT4 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT4 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT5 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT5 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT6 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT6 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT7 = u8Pwm_IsEnable_l;
        if(pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT7 \
                != ((u8Pwm_IsEnable_l == 1U)?(0u):(3u)))
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/********************************** add **********************************/

#ifdef __cplusplus
extern "C"{
#endif

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) SetTomChannelSL \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    VAR(uint8, AUTOMATIC) u8Pwm_Val \
)
{
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH0_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH1_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH2_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH3_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH4_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH5_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH6_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH7_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH8_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH9_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH10_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH11_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH12_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH13_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH14_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_TOM_n->CH15_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH0_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH1_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH2_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH3_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH4_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH5_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH6_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CTRL.B.SL = u8Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH7_CTRL.B.SL != u8Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH0_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH1_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH2_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH3_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH4_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH5_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH6_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH7_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH8_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH9_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH10_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH11_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH12_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH13_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH14_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH15_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n \
        = g_GTM_TOM_Base[ePwm_GTM_TOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH0_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH1_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH2_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH3_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH4_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH5_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH6_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH7_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH8_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH9_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH10_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH11_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH12_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH13_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH14_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_TOM_n->CH15_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH0_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH1_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH2_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH3_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH4_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH5_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH6_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CM0.B.CM0 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH7_CM0.B.CM0 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH0_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH1_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH2_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH3_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH4_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH5_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH6_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_CM1.B.CM1 = u32Pwm_Val;
        if(pPwm_GTM_ATOM_n->CH7_CM1.B.CM1 != u32Pwm_Val)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n \
        = g_GTM_TOM_Base[ePwm_GTM_TOMn];/* polyspace RTE:OBAI */  

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH0_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH1:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH1_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH2:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH2_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH3:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH3_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH4:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH4_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH5:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH5_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH6:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH6_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH7:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH7_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH8:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH8_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH9:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH9_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH10:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH10_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH11:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH11_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH12:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH12_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH13:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH13_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH14:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH14_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH15:
    {
        *pPwm_SR0 = (uint16)pPwm_GTM_TOM_n->CH15_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    default:
    {
        /* nothing */
        break;
    }
    }

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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n \
        = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH0_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH1:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH1_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH2:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH2_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH3:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH3_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH4:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH4_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH5:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH5_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH6:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH6_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH7:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH7_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH8:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH8_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH9:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH9_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH10:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH10_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH11:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH11_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH12:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH12_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH13:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH13_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH14:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH14_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH15:
    {
        *pPwm_SR1 = (uint16)pPwm_GTM_TOM_n->CH15_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    default:
    {
        /* nothing */
        break;
    }
    }

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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];/* polyspace RTE:OBAI */  

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        *pPwm_SR0 = pPwm_GTM_ATOM_n->CH0_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH1:
    {
        *pPwm_SR0 = pPwm_GTM_ATOM_n->CH1_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH2:
    {
        *pPwm_SR0 = pPwm_GTM_ATOM_n->CH2_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH3:
    {
        *pPwm_SR0 = pPwm_GTM_ATOM_n->CH3_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH4:
    {
        *pPwm_SR0 = pPwm_GTM_ATOM_n->CH4_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH5:
    {
        *pPwm_SR0 = pPwm_GTM_ATOM_n->CH5_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH6:
    {
        *pPwm_SR0 = pPwm_GTM_ATOM_n->CH6_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH7:
    {
        *pPwm_SR0 = pPwm_GTM_ATOM_n->CH7_SR0.B.SR0;/* polyspace RTE:NIV */ 
        break;
    }
    default:
    {
        /* nothing */
        break;
    }
    }

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
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        *pPwm_SR1 = pPwm_GTM_ATOM_n->CH0_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH1:
    {
        *pPwm_SR1 = pPwm_GTM_ATOM_n->CH1_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH2:
    {
        *pPwm_SR1 = pPwm_GTM_ATOM_n->CH2_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH3:
    {
        *pPwm_SR1 = pPwm_GTM_ATOM_n->CH3_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH4:
    {
        *pPwm_SR1 = pPwm_GTM_ATOM_n->CH4_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH5:
    {
        *pPwm_SR1 = pPwm_GTM_ATOM_n->CH5_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH6:
    {
        *pPwm_SR1 = pPwm_GTM_ATOM_n->CH6_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH7:
    {
        *pPwm_SR1 = pPwm_GTM_ATOM_n->CH7_SR1.B.SR1;/* polyspace RTE:NIV */ 
        break;
    }
    default:
    {
        /* nothing */
        break;
    }
    }

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_TOM_LLD_Channel_GetEnableOut \
( \
    VAR(GTM_TOM_Type, AUTOMATIC) ePwm_GTM_TOMn, \
    VAR(GTM_TOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_IsEnable \
)
{
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n \
        = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH1:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH2:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT2;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH3:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT3;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH4:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT4;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH5:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT5;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH6:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT6;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH7:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT7;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH8:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT8;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH9:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT9;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH10:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT10;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH11:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT11;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH12:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT12;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH13:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT13;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH14:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT14;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_TOM_CH15:
    {
        *pPwm_IsEnable = pPwm_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT15;/* polyspace RTE:NIV */ 
        break;
    }
    default:
    {
        /* nothing */
        break;
    }
    }

    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t, PWM_CODE) GTM_ATOM_LLD_Channel_GetEnableOut \
( \
    VAR(GTM_ATOM_Type, AUTOMATIC) ePwm_GTM_ATOMn, \
    VAR(GTM_ATOM_Channel_Type, AUTOMATIC) ePwm_CHn, \
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pPwm_IsEnable \
)
{
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        *pPwm_IsEnable = pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT0;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH1:
    {
        *pPwm_IsEnable = pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT1;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH2:
    {
        *pPwm_IsEnable = pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT2;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH3:
    {
        *pPwm_IsEnable = pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT3;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH4:
    {
        *pPwm_IsEnable = pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT4;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH5:
    {
        *pPwm_IsEnable = pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT5;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH6:
    {
        *pPwm_IsEnable = pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT6;/* polyspace RTE:NIV */ 
        break;
    }
    case GTM_ATOM_CH7:
    {
        *pPwm_IsEnable = pPwm_GTM_ATOM_n->AGC_OUTEN_STAT.B.OUTEN_STAT7;/* polyspace RTE:NIV */ 
        break;
    }
    default:
    {
        /* nothing */
        break;
    }
    }
    
    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n \
        = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH0_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH1_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH2_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH3_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH4_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH5_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH6_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH7_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH8_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH9_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH10_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH11_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH12_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH13_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH14_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_SR0.B.SR0 = u16Pwm_SR0;
        if(pPwm_GTM_TOM_n->CH15_SR0.B.SR0 != u16Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

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
    P2VAR(st_GTM_TOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_TOM_n \
        = g_GTM_TOM_Base[ePwm_GTM_TOMn];

    switch(ePwm_CHn)
    {
    case GTM_TOM_CH0:
    {
        pPwm_GTM_TOM_n->CH0_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH0_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH1:
    {
        pPwm_GTM_TOM_n->CH1_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH1_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH2:
    {
        pPwm_GTM_TOM_n->CH2_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH2_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH3:
    {
        pPwm_GTM_TOM_n->CH3_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH3_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH4:
    {
        pPwm_GTM_TOM_n->CH4_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH4_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH5:
    {
        pPwm_GTM_TOM_n->CH5_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH5_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH6:
    {
        pPwm_GTM_TOM_n->CH6_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH6_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH7:
    {
        pPwm_GTM_TOM_n->CH7_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH7_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH8:
    {
        pPwm_GTM_TOM_n->CH8_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH8_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH9:
    {
        pPwm_GTM_TOM_n->CH9_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH9_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH10:
    {
        pPwm_GTM_TOM_n->CH10_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH10_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH11:
    {
        pPwm_GTM_TOM_n->CH11_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH11_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH12:
    {
        pPwm_GTM_TOM_n->CH12_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH12_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH13:
    {
        pPwm_GTM_TOM_n->CH13_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH13_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH14:
    {
        pPwm_GTM_TOM_n->CH14_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH14_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_TOM_CH15:
    {
        pPwm_GTM_TOM_n->CH15_SR1.B.SR1 = u16Pwm_SR1;
        if(pPwm_GTM_TOM_n->CH15_SR1.B.SR1 != u16Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_SR0.B.SR0 = u32Pwm_SR0;
        if(pPwm_GTM_ATOM_n->CH0_SR0.B.SR0 != u32Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_SR0.B.SR0 = u32Pwm_SR0;
        if(pPwm_GTM_ATOM_n->CH1_SR0.B.SR0 != u32Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_SR0.B.SR0 = u32Pwm_SR0;
        if(pPwm_GTM_ATOM_n->CH2_SR0.B.SR0 != u32Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_SR0.B.SR0 = u32Pwm_SR0;
        if(pPwm_GTM_ATOM_n->CH3_SR0.B.SR0 != u32Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_SR0.B.SR0 = u32Pwm_SR0;
        if(pPwm_GTM_ATOM_n->CH4_SR0.B.SR0 != u32Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_SR0.B.SR0 = u32Pwm_SR0;
        if(pPwm_GTM_ATOM_n->CH5_SR0.B.SR0 != u32Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    } 
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_SR0.B.SR0 = u32Pwm_SR0;
        if(pPwm_GTM_ATOM_n->CH6_SR0.B.SR0 != u32Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_SR0.B.SR0 = u32Pwm_SR0;
        if(pPwm_GTM_ATOM_n->CH7_SR0.B.SR0 != u32Pwm_SR0)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
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
    VAR(status_t, AUTOMATIC) ePwm_ReturnValue = STATUS_SUCCESS;
    P2VAR(st_GTM_ATOM_tag, AUTOMATIC, PWM_APPL_DATA) pPwm_GTM_ATOM_n \
        = g_GTM_ATOM_Base[(uint8)ePwm_GTM_ATOMn];

    switch(ePwm_CHn)
    {
    case GTM_ATOM_CH0:
    {
        pPwm_GTM_ATOM_n->CH0_SR1.B.SR1 = u32Pwm_SR1;
        if(pPwm_GTM_ATOM_n->CH0_SR1.B.SR1 != u32Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH1:
    {
        pPwm_GTM_ATOM_n->CH1_SR1.B.SR1 = u32Pwm_SR1;
        if(pPwm_GTM_ATOM_n->CH1_SR1.B.SR1 != u32Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH2:
    {
        pPwm_GTM_ATOM_n->CH2_SR1.B.SR1 = u32Pwm_SR1;
        if(pPwm_GTM_ATOM_n->CH2_SR1.B.SR1 != u32Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH3:
    {
        pPwm_GTM_ATOM_n->CH3_SR1.B.SR1 = u32Pwm_SR1;
        if(pPwm_GTM_ATOM_n->CH3_SR1.B.SR1 != u32Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH4:
    {
        pPwm_GTM_ATOM_n->CH4_SR1.B.SR1 = u32Pwm_SR1;
        if(pPwm_GTM_ATOM_n->CH4_SR1.B.SR1 != u32Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH5:
    {
        pPwm_GTM_ATOM_n->CH5_SR1.B.SR1 = u32Pwm_SR1;
        if(pPwm_GTM_ATOM_n->CH5_SR1.B.SR1 != u32Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH6:
    {
        pPwm_GTM_ATOM_n->CH6_SR1.B.SR1 = u32Pwm_SR1;
        if(pPwm_GTM_ATOM_n->CH6_SR1.B.SR1 != u32Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    case GTM_ATOM_CH7:
    {
        pPwm_GTM_ATOM_n->CH7_SR1.B.SR1 = u32Pwm_SR1;
        if(pPwm_GTM_ATOM_n->CH7_SR1.B.SR1 != u32Pwm_SR1)
        {
            ePwm_ReturnValue = STATUS_ERROR;
        }
        break;
    }
    default:
    {
        ePwm_ReturnValue = STATUS_ERROR;
        break;
    }
    }

    return ePwm_ReturnValue;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_GTM104 */
#ifdef __cplusplus
}
#endif
