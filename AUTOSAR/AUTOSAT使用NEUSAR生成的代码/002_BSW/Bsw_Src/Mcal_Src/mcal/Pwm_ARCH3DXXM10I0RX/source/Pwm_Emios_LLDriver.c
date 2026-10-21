/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx eMIOS low level drivers code
* HISTORY     : Initial version
* @file     Pwm_Emios_LLDriver.c
* @version  3.0.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 3432, 3218, 1257 EOF*/
/* PRQA S 2844, 4342, 2976, 3604 EOF */
/* PRQA S 4332 EOF*/
#include "Pwm_Emios_LLDriver.h"/*PRQA S 0380*/
#include "eMIOS_HAL_Irq.h"
#include "Pwm_Irq.h"

#define PWM_EMS_LLD_C_VENDOR_ID                      176
#define PWM_EMS_LLD_C_AR_REL_MAJOR_VER               4
#define PWM_EMS_LLD_C_AR_REL_MINOR_VER               4
#define PWM_EMS_LLD_C_AR_REL_REV_VER                 0
#define PWM_EMS_LLD_C_SW_MAJOR_VER                   3
#define PWM_EMS_LLD_C_SW_MINOR_VER                   0
#define PWM_EMS_LLD_C_SW_PATCH_VER                   0

#if (PWM_EMS_LLD_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_C_VENDOR_ID "
#endif
#if (PWM_EMS_LLD_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_EMS_LLD_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_C_AR_REL_MINOR_VER "
#endif
#if (PWM_EMS_LLD_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_C_AR_REL_REV_VER "
#endif
#if (PWM_EMS_LLD_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_C_SW_MAJOR_VER "
#endif
#if (PWM_EMS_LLD_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_C_SW_MINOR_VER "
#endif
#if (PWM_EMS_LLD_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_EMS_LLD_C_SW_PATCH_VER "
#endif

#define PWM_START_SEC_VAR_NO_INIT
#include "Pwm_MemMap.h"
static VAR(uint32, AUTOMATIC) g_Opwmb_Offset[2][32];
#define PWM_STOP_SEC_VAR_NO_INIT
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
#define PWM_START_SEC_VAR_NO_INIT
#include "Pwm_MemMap.h"
static VAR(uint32, AUTOMATIC) g_Opwmt_Offset[2][32];
#define PWM_STOP_SEC_VAR_NO_INIT
#include "Pwm_MemMap.h"
#endif /* defined(RESOURCE_SUPPORT_EMIOS_OPWMT) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) EMIOS_LLD_PWM_SetLeadingEdge \
( \
    VAR(uint8, AUTOMATIC) emiosGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) newLeadingEdgePlacement \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) EMIOS_LLD_PWM_SetTrailingEdge \
( \
    VAR(uint8, AUTOMATIC) emiosGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) newTrailingEdgePlacement \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) eMIOS_PWM_UC_An_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_A_value \
)
{
    if(u32eMIOS_A_value < 0xFFFFFFU)
    {
        eMIOS_UC_An_SetValue(u8eMIOS_Index,u8eMIOS_ChanNum,u32eMIOS_A_value);
    }
    else
    {
        eMIOS_UC_An_SetValue(u8eMIOS_Index,u8eMIOS_ChanNum,0xFFFFFFU);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) eMIOS_PWM_UC_Bn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_B_value \
)
{
    if(u32eMIOS_B_value < 0xFFFFFFU)
    {
        eMIOS_UC_Bn_SetValue(u8eMIOS_Index,u8eMIOS_ChanNum,u32eMIOS_B_value);
    }
    else
    {
        eMIOS_UC_Bn_SetValue(u8eMIOS_Index,u8eMIOS_ChanNum,0xFFFFFFU);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_GetBusDrivenCh \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2VAR(uint8, AUTOMATIC, PWM_APPL_DATA) busDriven \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    /* Get current bus select */
    VAR(uint8, AUTOMATIC) bus = eMIOS_UC_Cn_GetBSL(emiosIndex, ChanNum);
    switch (bus)
    {
    case (uint8)EMIOS_COUNTER_BUS_A:
    {
        *busDriven = (uint8)EMIOS_CNT_BUSA_DRIVEN_CHANNEL;
        break;
    }
    case (uint8)EMIOS_COUNTER_BUS_BCDE:
    {
        *busDriven = (uint8)(ChanNum & 0xF8U);
        break;
    }
    case (uint8)EMIOS_COUNTER_BUS_INTERNAL:
    {
        *busDriven = (uint8)EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL;
        break;
    }
    default :
    {
        *busDriven = (uint8)EMIOS_CNT_NONE_DRIVEN_CHANNEL;
        ret = STATUS_EMIOS_WRONG_CNT_BUS;
        break;
    }
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(uint32, PWM_CODE) eMIOS_LLD_PWM_GetDutyOPWFMB \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(uint32, AUTOMATIC) A, \
    CONST(uint32, AUTOMATIC) B \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(uint32, AUTOMATIC) ret;

    if (eMIOS_LLD_GetChNumOutUpdateDis(emiosIndex, ChanNum) == TRUE)
    {
        ret = 0UL; /* 0% duty cycle */
    }
    else if (A < B)
    {
        ret = A;
    }
    else
    {
        /* Duty cycle = period */
        ret = B; /* 100% duty cycle */
    }

    if (eMIOS_UC_Cn_GetEDPOL(emiosIndex, ChanNum) == (uint8)EMIOS_POSITIVE_PULSE)
    {
        ret = B - ret;
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(uint32, PWM_CODE) eMIOS_LLD_PWM_GetDutyLead \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) busChannel, \
    CONST(uint32, AUTOMATIC) A, \
    CONST(uint32, AUTOMATIC) B, \
    CONST(uint8, AUTOMATIC)  active \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(busChannel));

    VAR(uint32, AUTOMATIC) ret  = 0UL;
    VAR(uint32, AUTOMATIC) temp = eMIOS_UC_An_GetValue(emiosIndex, busChannel);

    if (active == (uint8)EMIOS_POSITIVE_PULSE)
    {
        /* Leading edge dead-time insertion */
        if (A < temp)
        {
            if (A == 1UL)
            {
                ret = (temp << 1UL) - 2UL; /* 100% duty cycle */
            }
            else
            {
                if ((temp - A) <= B)
                {
                    ret = 0UL; /* 0% duty cycle */
                }
                else
                {
                    ret = ((temp - A) << 1UL) - B;
                }
            }
        }
        else if (A == temp)
        {
            /* Special case Note RM Page 1035/4083 MPC5748G_RM_Rev5_RC */
            ret = (temp << 1UL) - 2UL; /* 100% duty cycle */
        }
        else
        {
            ret = 0UL; /* 0% duty cycle */
        }
    }
    else
    {
        /* Leading edge dead-time insertion */
        if (A < temp)
        {
            if (A <= 1UL)
            {
                ret = 0UL; /* 0% duty cycle */
            }
            else
            {
                if ((A + B) > temp)
                {
                    ret = ((temp - 1UL) << 1UL); /* 100 % duty cycle */
                }
                else
                {
                    ret = ((A - 1UL) << 1UL) + B;
                }
            }
        }
        else
        {
            /* Special case Note RM Page 1035/4083 MPC5748G_RM_Rev5_RC */
            ret = ((temp - 1UL) << 1UL); /* 100 % duty cycle */
        }
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(uint32, PWM_CODE) eMIOS_LLD_PWM_GetDutyTrail \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) busChannel, \
    CONST(uint32, AUTOMATIC) A, \
    CONST(uint32, AUTOMATIC) B, \
    CONST(uint32, AUTOMATIC) active \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(busChannel));

    VAR(uint32, AUTOMATIC) ret = 0UL;
    VAR(uint32, AUTOMATIC) tmpARegVal = eMIOS_UC_An_GetValue(emiosIndex, busChannel);

    if (active == (uint32)EMIOS_POSITIVE_PULSE)
    {
        /* Leading edge dead-time insertion */
        if (A < tmpARegVal)
        {
            if (A <= 1UL)
            {
                /* 100% duty cycle */
                ret = (tmpARegVal << 1UL) - 2UL;
            }
            else
            {
                if (B >= A)
                {
                    /* 100% duty cycle */
                    ret = (tmpARegVal << 1UL) - 2UL;
                }
                else
                {
                    ret = ((tmpARegVal - A) << 1UL) + B;
                }
            }
        }
        else if (A == tmpARegVal)
        {
            /* Special case Note RM Page 1035/4083 MPC5748G_RM_Rev5_RC */
            ret = (tmpARegVal << 1UL) - 2UL; /* 100% duty cycle */
        }
        else
        {
            /* 0% duty cycle */
            ret = 0UL;
        }
    }
    else
    {
        /* Leading edge dead-time insertion */
        if (A < tmpARegVal)
        {
            if (A <= 1UL)
            {
                ret = 0UL; /* 0% duty cycle */
            }
            else
            {
                if (B >= A)
                {
                    ret = 0UL; /* 0% duty cycle */
                }
                else
                {
                    ret = ((A - 1UL) << 1UL) - B;
                }
            }
        }
        else
        {
            /* Special case Note RM Page 1035/4083 MPC5748G_RM_Rev5_RC */
            ret = ((tmpARegVal - 1UL) << 1UL); /* 100& duty cycle */
        }
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(uint32, PWM_CODE) eMIOS_LLD_PWM_GetDutyOPWMB \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(uint8, AUTOMATIC) busChannel, \
    CONST(uint32, AUTOMATIC) A, \
    CONST(uint32, AUTOMATIC) B \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(uint32, AUTOMATIC) ret;
    VAR(uint32, AUTOMATIC) cntPeriod = eMIOS_LLD_MC_GetPeriod(emiosIndex, busChannel);

    if (eMIOS_LLD_GetChNumOutUpdateDis(emiosIndex, ChanNum) == TRUE)
    {
        ret = 0UL; /* 0% duty cycle */
    }
    else if ((A > cntPeriod) || ((A == cntPeriod) && (B == cntPeriod)))
    {
        /* Does not match any edge */
        ret = cntPeriod; /* 100% duty cycle */
    }
    else if (B > cntPeriod)
    {
        /* Leading edge matches only */
        ret = 0UL;
    }
    else if (B == A)
    {
        /* Trailing edge matches have precedence over leading edge matches */
        ret = cntPeriod; /* 100% duty cycle */
    }
    else
    {
        ret = (cntPeriod - B) + A;
    }

    if (eMIOS_UC_Cn_GetEDPOL(emiosIndex, ChanNum) == (uint8)EMIOS_POSITIVE_PULSE)
    {
        ret = cntPeriod - ret;
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) eMIOS_LLD_PWM_InitGpio \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_PWM_ParamType, AUTOMATIC, PWM_APPL_CONST) pwmParam, \
    P2VAR(eMIOS_GPIO_ParamType, AUTOMATIC, PWM_APPL_DATA)   gpio_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(pwmParam != NULL);

    (void)emiosIndex;
    (void)ChanNum;
    gpio_param->mode      = pwmParam->mode;
    gpio_param->active    = pwmParam->active;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) eMIOS_LLD_PWM_InitSaoc \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_PWM_ParamType, AUTOMATIC, PWM_APPL_CONST) pwmParam, \
    P2VAR(eMIOS_SAOC_ParamType, AUTOMATIC, PWM_APPL_DATA)   saoc_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(pwmParam != NULL);

    (void)emiosIndex;
    (void)ChanNum;
    saoc_param->mode      = pwmParam->mode;
    saoc_param->active    = pwmParam->active;
    saoc_param->divid     = (uint8)(pwmParam->divid - 1U);
    saoc_param->compare   = pwmParam->period;
    saoc_param->timebase  = pwmParam->timebase;
    saoc_param->eMiosDmaSwitch = pwmParam->eMiosDmaSwitch;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitDaoc \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_PWM_ParamType, AUTOMATIC, PWM_APPL_CONST) pwmParam, \
    P2VAR(eMIOS_DAOC_ParamType, AUTOMATIC, PWM_APPL_DATA)   daoc_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(pwmParam != NULL);

    VAR(status_t, AUTOMATIC) status           = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC)    busChannel       = 0U;

    daoc_param->divid        = (uint8)(pwmParam->divid - 1U);
    daoc_param->mode         = pwmParam->mode;
    daoc_param->timebase     = EMIOS_COUNTER_BUS_A;
    daoc_param->leadingEdge  = 0UL;
    daoc_param->trailingEdge = 0UL;

    if ((eMIOS_LLD_PWM_GetBusDrivenCh(emiosIndex, ChanNum, &busChannel) == STATUS_SUCCESS) && (busChannel < (uint8)EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL))
    {
        daoc_param->trailingEdge = pwmParam->dutyCycle;

        /* If MCB counter mode, this timebase count from 1 */
        if ((eMIOS_UC_Cn_GetMode(emiosIndex, busChannel) & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UP_MASK)
        {
            daoc_param->leadingEdge   = 1UL;
            daoc_param->trailingEdge += 1UL;
        }
        daoc_param->timebase = pwmParam->timebase;
        daoc_param->active = pwmParam->active;
    }
    else
    {
        status = STATUS_ERROR;
    }

    return status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) eMIOS_LLD_PWM_InitOpwfm \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_PWM_ParamType, AUTOMATIC, PWM_APPL_CONST) pwmParam, \
    P2VAR(eMIOS_OPWFMB_ParamType, AUTOMATIC, PWM_APPL_DATA) opwfm_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(pwmParam != NULL);

    (void)emiosIndex;
    (void)ChanNum;
    opwfm_param->mode      = pwmParam->mode;
    opwfm_param->dutyCycle = pwmParam->dutyCycle;
    opwfm_param->divid     = (uint8)(pwmParam->divid - 1U);
    opwfm_param->active    = pwmParam->active;
    opwfm_param->period    = pwmParam->period;
    opwfm_param->eMiosDmaSwitch = pwmParam->eMiosDmaSwitch;

    if(opwfm_param->active == 0U)
    {
        opwfm_param->active = 1;
    }
    else
    {
        opwfm_param->active = 0;
    }
    opwfm_param->dutyCycle = opwfm_param->period - opwfm_param->dutyCycle;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) eMIOS_LLD_PWM_InitOpwmcb \
( \
    CONST(uint8, AUTOMATIC)  emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_PWM_ParamType, AUTOMATIC, PWM_APPL_CONST) pwmParam, \
    P2VAR(eMIOS_OPWMCB_ParamType, AUTOMATIC, PWM_APPL_DATA) opwmcb_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(pwmParam != NULL);

    (void)emiosIndex;
    (void)ChanNum;
    opwmcb_param->mode           = pwmParam->mode;
    opwmcb_param->deadTime       = pwmParam->deadTime;
    opwmcb_param->idealDutyCycle = pwmParam->idealDutyCycle;
    opwmcb_param->divid          = (uint8)(pwmParam->divid - 1U);
    opwmcb_param->active         = pwmParam->active;
    opwmcb_param->timebase       = pwmParam->timebase;
    opwmcb_param->eMiosDmaSwitch = pwmParam->eMiosDmaSwitch;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitOpwmb \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_PWM_ParamType, AUTOMATIC, PWM_APPL_CONST) pwmParam, \
    P2VAR(eMIOS_OPWMB_ParamType, AUTOMATIC, PWM_APPL_DATA) opwmb_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(pwmParam != NULL);

    VAR(status_t, AUTOMATIC) status         = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) busChannel        = 0U;
    uint32_t temp_B           = 0U;

    opwmb_param->mode         = pwmParam->mode;
    opwmb_param->divid        = (uint8)(pwmParam->divid - 1U);
    opwmb_param->timebase     = EMIOS_COUNTER_BUS_A;
    opwmb_param->leadingEdge  = 0UL;
    opwmb_param->trailingEdge = 0UL;
    opwmb_param->eMiosDmaSwitch = pwmParam->eMiosDmaSwitch;

    if ((eMIOS_LLD_PWM_GetBusDrivenCh(emiosIndex, ChanNum, &busChannel) == STATUS_SUCCESS) && (busChannel < (uint8)EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL))
    {
        opwmb_param->trailingEdge = pwmParam->dutyCycle;
        /* If MCB counter mode, this timebase count from 1 */
        if ((eMIOS_UC_Cn_GetMode(emiosIndex, busChannel) & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UP_MASK)
        {
            opwmb_param->leadingEdge   = 1UL;
            opwmb_param->trailingEdge += 1UL;
        }

        temp_B = pwmParam->offset + pwmParam->dutyCycle;

        if (temp_B <= eMIOS_LLD_MC_GetPeriod(emiosIndex, busChannel))
        {
            g_Opwmb_Offset[emiosIndex][ChanNum] = pwmParam->offset;/* polyspace RTE:OBAI */ 
            opwmb_param->leadingEdge += pwmParam->offset;
            opwmb_param->trailingEdge += pwmParam->offset;
        }
        else
        {
            status = STATUS_ERROR;
        }

        opwmb_param->timebase = pwmParam->timebase;
        opwmb_param->active = pwmParam->active;
    }

    return status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitOpwmt \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_PWM_ParamType, AUTOMATIC, PWM_APPL_CONST) pwmParam, \
    P2VAR(eMIOS_OPWMT_ParamType, AUTOMATIC, PWM_APPL_DATA) opwmt_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(pwmParam != NULL);

    VAR(status_t, AUTOMATIC) status         = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) busChannel        = 0U;

    opwmt_param->mode         = pwmParam->mode;
    opwmt_param->divid        = (uint8)(pwmParam->divid - 1U);
    opwmt_param->timebase     = EMIOS_COUNTER_BUS_A;
    opwmt_param->leadingEdge  = 0UL;
    opwmt_param->trailingEdge = 0UL;
    opwmt_param->active       = 0U;
    opwmt_param->trigTime     = 0UL;    
    if ((eMIOS_LLD_PWM_GetBusDrivenCh(emiosIndex, ChanNum, &busChannel) == STATUS_SUCCESS) && (busChannel < (uint8_t)EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL))
    {
        if (pwmParam->active == (VAR(uint8, PWM_VAR))EMIOS_POSITIVE_PULSE)
        {
        	opwmt_param->trailingEdge = pwmParam->dutyCycle;
        }
        else
        {
            if (eMIOS_LLD_MC_GetPeriod(emiosIndex, busChannel) >= pwmParam->dutyCycle)
            {
            	opwmt_param->trailingEdge = eMIOS_LLD_MC_GetPeriod(emiosIndex, busChannel) - pwmParam->dutyCycle;
            }
            else
            {
                /* duty cycle count should not be greater than period of timebase  */
                status = STATUS_ERROR;
            }
        }

        if (status == STATUS_SUCCESS)
        {
            /* If MCB counter mode, this timebase count from 1 */
            if ((eMIOS_UC_Cn_GetMode(emiosIndex, busChannel) & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UP_MASK)
            {
            	opwmt_param->leadingEdge   = 1UL;
            	opwmt_param->trailingEdge += 1UL;
            }
            opwmt_param->timebase = pwmParam->timebase;
            opwmt_param->active = pwmParam->active;
            opwmt_param->trigTime = pwmParam->trigTime;
        }
    }

    return status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_EMIOS_OPWMT)) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(uint32, PWM_CODE) eMIOS_LLD_PWM_CalibrationDuty \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(uint32, AUTOMATIC) idealDutyCycle \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(uint32, AUTOMATIC) newIdealDutyCycle = 0UL;

    if (idealDutyCycle < eMIOS_LLD_MC_GetPeriod(emiosIndex, ChanNum))
    {
        if (idealDutyCycle > 0U)
        {
            newIdealDutyCycle = ((eMIOS_LLD_MC_GetPeriod(emiosIndex, ChanNum) - idealDutyCycle) / 2U) + 1UL;
        }
        else
        {
            newIdealDutyCycle = (eMIOS_LLD_MC_GetPeriod(emiosIndex, ChanNum) / 2U) + 2UL; /* 0% duty cycle */
        }
    }
    else
    {
        newIdealDutyCycle = 1UL; /* 100% duty cycle */
    }

    /* New Ideal duty value */
    return newIdealDutyCycle;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitFixPerOutMode \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_GPIO_ParamType, AUTOMATIC, PWM_APPL_CONST) gpio_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(gpio_param != NULL);

    VAR(status_t, AUTOMATIC) status = STATUS_SUCCESS;

    /* Cleared UC configure registers */
    eMIOS_LLD_UC_DeInitChannel(emiosIndex, ChanNum); /* Disable channel pre-scaler (reset default) */

    eMIOS_UC_Cn_SetEDPOL(emiosIndex, ChanNum, gpio_param->active);
    eMIOS_UC_Cn_SetMode(emiosIndex, ChanNum, (uint8)gpio_param->mode);
    eMIOS_UC_Cn_SetUCPREN(emiosIndex, ChanNum, TRUE);

    return status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitSingOutMode \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_SAOC_ParamType, AUTOMATIC, PWM_APPL_CONST) saoc_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(saoc_param != NULL);

    VAR(status_t, AUTOMATIC) status = STATUS_SUCCESS;

    /* Cleared UC configure registers */
    eMIOS_LLD_UC_DeInitChannel(emiosIndex, ChanNum); /* Disable channel pre-scaler (reset default) */

    eMIOS_UC_Cn_SetEDSEL(emiosIndex, ChanNum, saoc_param->active);
    eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, saoc_param->compare);
    eMIOS_UC_Cn_SetBSL(emiosIndex, ChanNum, (uint8)saoc_param->timebase);
    eMIOS_UC_Cn_SetMode(emiosIndex, ChanNum, (uint8)EMIOS_UC_MODE_PWM_SAOC);
    eMIOS_UC_Cn_SetUCPREN(emiosIndex, ChanNum, TRUE);
    eMIOS_UC_Cn_SetUCPRE(emiosIndex, ChanNum, saoc_param->divid);         /* Pre-scale channel clock by divid +1 */
    eMIOS_UC_Cn_SetFEN(emiosIndex, ChanNum, (boolean)saoc_param->eMiosDmaSwitch);
    eMIOS_UC_Cn_SetDMA(emiosIndex, ChanNum, saoc_param->eMiosDmaSwitch);
    return status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitDoubleOutMode \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_DAOC_ParamType, AUTOMATIC, PWM_APPL_CONST) daoc_param \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(daoc_param != NULL);

    VAR(status_t, AUTOMATIC) ret         = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC)  busChannel    = (uint8)EMIOS_CNT_BUSA_DRIVEN_CHANNEL;
    /* Validate timebase: must be external counter, MCB Up mode */
    if (daoc_param->timebase == EMIOS_COUNTER_BUS_A)
    {
        busChannel = (uint8)EMIOS_CNT_BUSA_DRIVEN_CHANNEL;
    }
    else /* Local bus */
    {
        busChannel = (uint8)(ChanNum & 0xF8U);
    }

    if ((eMIOS_UC_Cn_GetMode(emiosIndex, busChannel) & EMIOS_FILTER_MCB_MASK) != EMIOS_MCB_UP_MASK)
    {
        /* Wrong mode */
        ret = STATUS_ERROR;
    }
    else
    {
        /* Cleared UC configure registers */
        Pwm_Set_Emios_DAOC_Active(emiosIndex, ChanNum, daoc_param->active); /* polyspace RTE:NIV */
        Pwm_Set_Emios_DAOC_B(emiosIndex, ChanNum, daoc_param->trailingEdge);
        eMIOS_LLD_UC_DeInitChannel(emiosIndex, ChanNum);                                        /* Disable ChanNum pre-scaler (reset default) */
        eMIOS_UC_Cn_SetBSL(emiosIndex, ChanNum, (uint8)daoc_param->timebase);
        eMIOS_UC_Cn_SetEDPOL(emiosIndex, ChanNum, daoc_param->active);
        eMIOS_UC_Cn_SetMode(emiosIndex, ChanNum, (uint8)daoc_param->mode);
        eMIOS_UC_Cn_SetUCPREN(emiosIndex, ChanNum, TRUE);
        eMIOS_UC_Cn_SetUCPRE(emiosIndex, ChanNum, daoc_param->divid);         /* Pre-scale ChanNum clock by divid +1 */
        eMIOS_LLD_UC_ClearFlag( emiosIndex, ChanNum);
        eMIOS_UC_Cn_SetFEN(emiosIndex, ChanNum, (boolean)TRUE);
        eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, daoc_param->leadingEdge);
        eMIOS_PWM_UC_Bn_SetValue(emiosIndex, ChanNum, daoc_param->trailingEdge);
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitPerDutyMode \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_OPWFMB_ParamType, AUTOMATIC, PWM_APPL_CONST) opwfmParam \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(opwfmParam != NULL);

    VAR(status_t, AUTOMATIC) status = STATUS_SUCCESS;

    /* Cleared UC configure registers */
    eMIOS_LLD_UC_DeInitChannel(emiosIndex, ChanNum); /* Disable channel pre-scaler (reset default) */
    eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, opwfmParam->period - opwfmParam->dutyCycle);
    eMIOS_PWM_UC_Bn_SetValue(emiosIndex, ChanNum, opwfmParam->period);
    eMIOS_UC_CNTn_SetValue(emiosIndex, ChanNum, 1UL);
    eMIOS_UC_Cn_SetEDPOL(emiosIndex, ChanNum, opwfmParam->active);
    eMIOS_UC_Cn_SetMode(emiosIndex, ChanNum, (uint8)opwfmParam->mode);
    eMIOS_UC_Cn_SetUCPREN(emiosIndex, ChanNum, TRUE);
    eMIOS_UC_Cn_SetUCPRE(emiosIndex, ChanNum, opwfmParam->divid);         /* Pre-scale channel clock by divid +1 */
    eMIOS_UC_Cn_SetFEN(emiosIndex, ChanNum, (boolean)opwfmParam->eMiosDmaSwitch);
    eMIOS_UC_Cn_SetDMA(emiosIndex, ChanNum, opwfmParam->eMiosDmaSwitch);
    return status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitTrigPlacementMode \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_OPWMT_ParamType, AUTOMATIC, PWM_APPL_CONST) opwmtParam \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(opwmtParam != NULL);

    VAR(status_t, AUTOMATIC) ret         = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC)  busChannel    = (uint8)EMIOS_CNT_BUSA_DRIVEN_CHANNEL;
    /* Validate timebase: must be external counter, MCB Up mode */
    if (opwmtParam->timebase == EMIOS_COUNTER_BUS_A)
    {
        busChannel = (VAR(uint8, AUTOMATIC))EMIOS_CNT_BUSA_DRIVEN_CHANNEL;
    }
    else /* Local bus */
    {
        busChannel = (VAR(uint8, AUTOMATIC))(ChanNum & 0xF8U);
    }

    if ((eMIOS_UC_Cn_GetMode(emiosIndex, busChannel) & EMIOS_FILTER_MCB_MASK) != EMIOS_MCB_UP_MASK)
    {
        /* Wrong mode */
        ret = STATUS_ERROR;
    }
    else
    {
        /* Cleared UC configure registers */
        eMIOS_LLD_UC_DeInitChannel(emiosIndex, ChanNum);                                        /* Disable ChanNum pre-scaler (reset default) */
        eMIOS_UC_An_SetValue(emiosIndex, ChanNum, opwmtParam->leadingEdge);
        eMIOS_UC_Bn_SetValue(emiosIndex, ChanNum, opwmtParam->trailingEdge);
        eMIOS_UC_ALTAn_SetValue(emiosIndex, ChanNum, opwmtParam->trigTime);
        eMIOS_UC_Cn_SetBSL(emiosIndex, ChanNum, (uint8)opwmtParam->timebase);
        eMIOS_UC_Cn_SetEDPOL(emiosIndex, ChanNum, opwmtParam->active);
        eMIOS_UC_Cn_SetMode(emiosIndex, ChanNum, (uint8)opwmtParam->mode);
        eMIOS_UC_Cn_SetUCPREN(emiosIndex, ChanNum, TRUE);
        eMIOS_UC_Cn_SetUCPRE(emiosIndex, ChanNum, opwmtParam->divid);         /* Pre-scale ChanNum clock by divid +1 */
        eMIOS_LLD_UC_SetIntcRequestEn(emiosIndex,ChanNum);
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_EMIOS_OPWMT)) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitEdgePlacMode \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_OPWMB_ParamType, AUTOMATIC, PWM_APPL_CONST) opwmbParam \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(opwmbParam != NULL);

    VAR(status_t, AUTOMATIC) ret         = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC)  busChannel    = (uint8)EMIOS_CNT_BUSA_DRIVEN_CHANNEL;
    /* Validate timebase: must be external counter, MCB Up mode */
    if (opwmbParam->timebase == EMIOS_COUNTER_BUS_A)
    {
        busChannel = (uint8)EMIOS_CNT_BUSA_DRIVEN_CHANNEL;
    }
    else /* Local bus */
    {
        busChannel = (uint8)(ChanNum & 0xF8U);
    }

    if ((eMIOS_UC_Cn_GetMode(emiosIndex, busChannel) & EMIOS_FILTER_MCB_MASK) != EMIOS_MCB_UP_MASK)
    {
        /* Wrong mode */
        ret = STATUS_ERROR;
    }
    else
    {
        /* Cleared UC configure registers */
        eMIOS_LLD_UC_DeInitChannel(emiosIndex, ChanNum);                                        /* Disable ChanNum pre-scaler (reset default) */
        eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, opwmbParam->leadingEdge);
        eMIOS_PWM_UC_Bn_SetValue(emiosIndex, ChanNum, opwmbParam->trailingEdge);
        eMIOS_UC_Cn_SetBSL(emiosIndex, ChanNum, (uint8)opwmbParam->timebase);
        eMIOS_UC_Cn_SetEDPOL(emiosIndex, ChanNum, opwmbParam->active);
        eMIOS_UC_Cn_SetMode(emiosIndex, ChanNum, (uint8)opwmbParam->mode);
        eMIOS_UC_Cn_SetUCPREN(emiosIndex, ChanNum, TRUE);
        eMIOS_UC_Cn_SetUCPRE(emiosIndex, ChanNum, opwmbParam->divid);         /* Pre-scale ChanNum clock by divid +1 */
        eMIOS_UC_Cn_SetFEN(emiosIndex, ChanNum, (boolean)opwmbParam->eMiosDmaSwitch);
        eMIOS_UC_Cn_SetDMA(emiosIndex, ChanNum, opwmbParam->eMiosDmaSwitch);
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/* Init Center Align DeadTime Mode */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_InitCenAliDtimMod \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    P2CONST(eMIOS_OPWMCB_ParamType, AUTOMATIC, PWM_APPL_CONST)  opwmcbParam \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(opwmcbParam != NULL);

    VAR(status_t, AUTOMATIC) status       = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC)    busChannel   = 0U;
    VAR(uint8, AUTOMATIC)    mode         = 0U;
    VAR(uint32, AUTOMATIC)   newDutyCycle = 0UL;

    /* Validate timebase: must be external counter, MCB Up mode */
    if (opwmcbParam->timebase == EMIOS_COUNTER_BUS_A)
    {
        busChannel = (uint8)EMIOS_CNT_BUSA_DRIVEN_CHANNEL;
    }
    else if (opwmcbParam->timebase == EMIOS_COUNTER_BUS_BCDE)
    {
        busChannel = (uint8)(ChanNum & 0xF8U);
    }
    else
    {
        /* Wrong counter bus : choosing internal counter bus ? */
        status = STATUS_ERROR;
    }

    if (status == STATUS_SUCCESS)
    {
        mode = (uint8)(eMIOS_UC_Cn_GetMode(emiosIndex, busChannel) & EMIOS_FILTER_MCB_MASK);

        /* Check bus select and valid Opwmcb with channels supported */
        if (mode != EMIOS_MCB_UPDOWN_MASK)
        {
            /* Wrong counter bus */
            status = STATUS_ERROR;
        }
        else
        {
            /* Calibration ideal duty value */
            newDutyCycle = eMIOS_LLD_PWM_CalibrationDuty(emiosIndex, busChannel, opwmcbParam->idealDutyCycle);
            /* Cleared UC configure registers */
            eMIOS_LLD_UC_DeInitChannel(emiosIndex, ChanNum);                                        /* Disable ChanNum pre-scaler (reset default) */
            eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, newDutyCycle);
            eMIOS_PWM_UC_Bn_SetValue(emiosIndex, ChanNum, opwmcbParam->deadTime);
            eMIOS_UC_Cn_SetBSL(emiosIndex, ChanNum, (uint8)opwmcbParam->timebase);
            eMIOS_UC_Cn_SetEDPOL(emiosIndex, ChanNum, opwmcbParam->active);
            eMIOS_UC_Cn_SetMode(emiosIndex, ChanNum, (uint8)opwmcbParam->mode);
            eMIOS_UC_Cn_SetUCPREN(emiosIndex, ChanNum, TRUE);
            eMIOS_UC_Cn_SetUCPRE(emiosIndex, ChanNum, opwmcbParam->divid);         /* Pre-scale ChanNum clock by divid +1 */
            eMIOS_UC_Cn_SetFEN(emiosIndex, ChanNum, (boolean)opwmcbParam->eMiosDmaSwitch);
            eMIOS_UC_Cn_SetDMA(emiosIndex, ChanNum, opwmcbParam->eMiosDmaSwitch);
        }
    }

    return status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(uint8, PWM_CODE) eMIOS_LLD_PWM_SetPeriodCheck \
( \
    CONST(uint8, AUTOMATIC)  mode, \
    CONST(uint32, AUTOMATIC) period \
)
{
    VAR(uint8, AUTOMATIC) tmpCheck = 1U;

    switch (mode)
    {
    case (uint8)EMIOS_UC_MODE_PWM_OPWFMB:
    {
        if ((period > EMIOS_OPWFMB_CNT_MAX) || \
            (period <= EMIOS_OPWFMB_CNT_MIN))
        {
            tmpCheck = 0U;
        }
        break;
    }
    case (uint8)EMIOS_UC_MODE_PWM_OPWMB:
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    case (uint8)EMIOS_UC_MODE_PWM_OPWMT:
#endif /* (defined(RESOURCE_SUPPORT_EMIOS_OPWMT)) */
    case (uint8)EMIOS_UC_MODE_PWM_OPWMCB_TRAIL:
    case (uint8)EMIOS_UC_MODE_PWM_OPWMCB_LEAD:
    {
        if ((period > EMIOS_OPWMCB_CNT_MAX) || \
            (period <= EMIOS_OPWMCB_CNT_MIN))
        {
            tmpCheck = 0U;
        }
        break;
    }
    default :
    {
        /* Mode not supported */
        tmpCheck = 0U;
        break;
    }
    }

    return tmpCheck;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_ForceLeadingEdge \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) temp = 0U;

    temp = eMIOS_UC_Cn_GetMode(emiosIndex, ChanNum);

    if (!(((temp & EMIOS_FILTER_OPWMCB_MASK) == EMIOS_OPWMCB_MASK) || \
               (temp == (uint8)EMIOS_UC_MODE_PWM_OPWMB) || \
               (temp == (uint8)EMIOS_UC_MODE_PWM_OPWFMB)))
    {
        ret = STATUS_EMIOS_WRONG_PARAMETER;
    }

    if (ret == STATUS_SUCCESS)
    {
        eMIOS_UC_Cn_SetFORCMA(emiosIndex, ChanNum, TRUE);
    }
    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) eMIOS_LLD_PWM_ForceTrailingEdge \
( \
    VAR(uint8, AUTOMATIC) emiosIndex, \
    VAR(uint8, AUTOMATIC) ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) temp = 0U;

    temp = eMIOS_UC_Cn_GetMode(emiosIndex, ChanNum);

    if(!(((temp & EMIOS_FILTER_OPWMCB_MASK) == EMIOS_OPWMCB_MASK) || \
            (temp == (uint8)EMIOS_UC_MODE_PWM_OPWMB) || \
            (temp == (uint8)EMIOS_UC_MODE_PWM_OPWFMB)))
    {
        ret = STATUS_EMIOS_WRONG_PARAMETER;
    }
    if (ret == STATUS_SUCCESS)
    {
        eMIOS_UC_Cn_SetFORCMB(emiosIndex, ChanNum, TRUE);
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/******************************************************************************
* API Function
******************************************************************************/

/* @brief eMIOS PWM mode Initialize.
 *
 * @param emiosIndex: eMIOS index
 *        ChanNum: channel number
 *        pwmParam: PWM parameter configuration pointer
 *
 * @return
 * */
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_Init
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(eMIOS_PWM_ParamType, AUTOMATIC)  *pwmParam \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(pwmParam != NULL);

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;

    eMIOS_LLD_SetChOutputUPDEnDis(emiosIndex, ChanNum, TRUE);

    switch (pwmParam->mode)
    {
    case EMIOS_UC_MODE_PWM_GPIO:
    {
        eMIOS_GPIO_ParamType gpio_param;
        eMIOS_LLD_PWM_InitGpio(emiosIndex, ChanNum, pwmParam, &gpio_param);
        ret = eMIOS_LLD_PWM_InitFixPerOutMode(emiosIndex, ChanNum, &gpio_param);
        break;
    }    
    case EMIOS_UC_MODE_PWM_SAOC:
    {
        eMIOS_SAOC_ParamType saoc_param;
        eMIOS_LLD_PWM_InitSaoc(emiosIndex, ChanNum, pwmParam, &saoc_param);
        ret = eMIOS_LLD_PWM_InitSingOutMode(emiosIndex, ChanNum, &saoc_param);
        break;
    }
    case EMIOS_UC_MODE_PWM_DAOC:
    {
        eMIOS_DAOC_ParamType daoc_param;
        if (eMIOS_LLD_PWM_InitDaoc(emiosIndex, ChanNum, pwmParam, &daoc_param) == STATUS_SUCCESS)
        {
            ret = eMIOS_LLD_PWM_InitDoubleOutMode(emiosIndex, ChanNum, &daoc_param);
        }
        else
        {
            ret = STATUS_ERROR; /* Operation failed, wrong counter bus */
        }
        break;
    }
    case EMIOS_UC_MODE_PWM_OPWFMB:
    {
        eMIOS_OPWFMB_ParamType opwfmb_param;
        eMIOS_LLD_PWM_InitOpwfm(emiosIndex, ChanNum, pwmParam, &opwfmb_param);
        ret = eMIOS_LLD_PWM_InitPerDutyMode(emiosIndex, ChanNum, &opwfmb_param);
        break;
    }
    case EMIOS_UC_MODE_PWM_OPWMCB_TRAIL:
    case EMIOS_UC_MODE_PWM_OPWMCB_LEAD:
    {
        eMIOS_OPWMCB_ParamType opwmcb_param;
        eMIOS_LLD_PWM_InitOpwmcb(emiosIndex, ChanNum, pwmParam, &opwmcb_param);
        ret = eMIOS_LLD_PWM_InitCenAliDtimMod(emiosIndex, ChanNum, &opwmcb_param);
        break;
    }
    case EMIOS_UC_MODE_PWM_OPWMB:
    {
        eMIOS_OPWMB_ParamType opwmb_param = {(eMIOS_PWM_ModeType)0U,0U,0U,(eMIOS_UC_CounterBusSelType)0U,0UL,0UL,FALSE};
        if (eMIOS_LLD_PWM_InitOpwmb(emiosIndex, ChanNum, pwmParam, &opwmb_param) == STATUS_SUCCESS)
        {
            ret = eMIOS_LLD_PWM_InitEdgePlacMode(emiosIndex, ChanNum, &opwmb_param);
        }
        else
        {
            ret = STATUS_ERROR; /* Operation failed, wrong counter bus */
        }
        break;
    }
#if defined(RESOURCE_SUPPORT_EMIOS_OPWMT)
    case EMIOS_UC_MODE_PWM_OPWMT:
    {
        eMIOS_OPWMT_ParamType opwmt_param;
        if (eMIOS_LLD_PWM_InitOpwmt(emiosIndex, ChanNum, pwmParam, &opwmt_param) == STATUS_SUCCESS)
        {
            ret = eMIOS_LLD_PWM_InitTrigPlacementMode(emiosIndex, ChanNum, &opwmt_param);
        }
        else
        {
            ret = STATUS_ERROR; /* Operation failed, wrong counter bus */
        }
        break;
    }
#endif
    default :
    {
        ret = STATUS_ERROR;
        break;
    }
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_ForceEdge \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(uint8, AUTOMATIC) edge \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;

    if (edge == TRUE)
    {
        ret = eMIOS_LLD_PWM_ForceTrailingEdge(emiosIndex, ChanNum);
    }
    else
    {
        ret = eMIOS_LLD_PWM_ForceLeadingEdge(emiosIndex, ChanNum);
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint32,  PWM_CODE) eMIOS_LLD_PWM_GetPeriod \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(uint32, AUTOMATIC) ret = 0UL;
    VAR(uint8, AUTOMATIC) mode = 0U;
    VAR(uint8, AUTOMATIC) busDrivenCh;

    mode = eMIOS_UC_Cn_GetMode(emiosIndex, ChanNum);

    switch (mode)
    {
    case (uint8)EMIOS_UC_MODE_PWM_OPWFMB:
    {
        ret = eMIOS_UC_Bn_GetValue(emiosIndex, ChanNum);
        break;
    }
    case (uint8)EMIOS_UC_MODE_PWM_OPWMCB_TRAIL:
    case (uint8)EMIOS_UC_MODE_PWM_OPWMCB_LEAD:
    case (uint8)EMIOS_UC_MODE_PWM_OPWMB:
    {
        if ((eMIOS_LLD_PWM_GetBusDrivenCh(emiosIndex, ChanNum, &busDrivenCh) == STATUS_SUCCESS) && (busDrivenCh < (uint8)EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL))
        {
            ret = eMIOS_LLD_MC_GetPeriod(emiosIndex, busDrivenCh);
        }
        break;
    }
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    case (uint8)EMIOS_UC_MODE_PWM_OPWMT:
    {
        if ((eMIOS_LLD_PWM_GetBusDrivenCh(emiosIndex, ChanNum, &busDrivenCh) == STATUS_SUCCESS) && (busDrivenCh < (uint8)EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL))
        {
            ret = eMIOS_LLD_MC_GetPeriod(emiosIndex, busDrivenCh);
        }
        break;
    }
#endif /* (defined(RESOURCE_SUPPORT_EMIOS_OPWMT)) */
    default:
    {
        EMIOS_DEV_ERR(FALSE);
        break;
    }
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_SetPeriodAndDuty \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(uint32, AUTOMATIC) period, \
    CONST(uint32, AUTOMATIC) duty \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) mode = eMIOS_UC_Cn_GetMode(emiosIndex, ChanNum);

    if(eMIOS_LLD_PWM_SetPeriodCheck(mode, period) == 0U)
    {
        ret = STATUS_EMIOS_WRONG_PARAMETER;
    }

    if (ret == STATUS_SUCCESS)
    {
        /* Check PWM mode */
        switch (mode)
        {
        case (uint8)EMIOS_UC_MODE_PWM_OPWFMB:
        {
            eMIOS_PWM_UC_Bn_SetValue(emiosIndex, ChanNum, period);

            if (duty < period)
            {
                eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, duty);
            }
            else
            {
                /* new duty cycle >= period */
                eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, period); /* 100% duty cycle */
            }
            break;
        }
        default:
        {
            /* nothing */
            break;
        }
        }
    }
    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint32,  PWM_CODE) eMIOS_LLD_PWM_GetDutyCycle \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(uint32, AUTOMATIC) ret        = 0UL;
    VAR(uint8, AUTOMATIC)  busChannel = 0U;
    VAR(uint8, AUTOMATIC)  cmode      = 0U;
    VAR(uint32, AUTOMATIC) A    = 0UL;
    VAR(uint32, AUTOMATIC) B    = 0UL;

    /* Get currently mode */
    cmode      = eMIOS_UC_Cn_GetMode(emiosIndex, ChanNum);
    A    = eMIOS_UC_An_GetValue(emiosIndex, ChanNum);
    B    = eMIOS_UC_Bn_GetValue(emiosIndex, ChanNum);

    /* Check current bus selected */
    if (eMIOS_LLD_PWM_GetBusDrivenCh(emiosIndex, ChanNum, &busChannel) == STATUS_SUCCESS)
    {
        /* Check current PWM mode */
        switch (cmode)
        {
        case (uint8)EMIOS_UC_MODE_PWM_OPWFMB:
        {
            ret = eMIOS_LLD_PWM_GetDutyOPWFMB(emiosIndex, ChanNum, A, B);
            break;
        }
        case (uint8)EMIOS_UC_MODE_PWM_OPWMCB_TRAIL:
        case (uint8)EMIOS_UC_MODE_PWM_OPWMCB_LEAD:
        {
            if (eMIOS_LLD_GetChNumOutUpdateDis(emiosIndex, ChanNum) == TRUE)
            {
                /* 0% duty cycle, The output disable feature, if enabled, causes the output flip-flop to transition to the
                EDPOL inverted state, RM Page 1036/4083 MPC5748G_RM_Rev5_RC */
                ret = 0UL;
            }
            else if (cmode == (uint8)EMIOS_UC_MODE_PWM_OPWMCB_LEAD)
            {
                ret = eMIOS_LLD_PWM_GetDutyLead(emiosIndex, busChannel, A, B, eMIOS_UC_Cn_GetEDPOL(emiosIndex, ChanNum));
            }
            else /* Trailing edge dead-time insertion */
            {
                ret = eMIOS_LLD_PWM_GetDutyTrail(emiosIndex, busChannel, A, B, eMIOS_UC_Cn_GetEDPOL(emiosIndex, ChanNum));
            }
            break;
        }
        case (uint8)EMIOS_UC_MODE_PWM_OPWMB:
        {
            ret = eMIOS_LLD_PWM_GetDutyOPWMB(emiosIndex, ChanNum, busChannel, A, B);
            break;
        }
        default:
        {
            EMIOS_DEV_ERR(FALSE);
            break;
        }
        }
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_SetDutyCycle \
( \
    CONST(uint8, AUTOMATIC) emiosIndex, \
    CONST(uint8, AUTOMATIC) ChanNum, \
    CONST(uint32, AUTOMATIC) newDutyCycle \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));

    VAR(status_t, AUTOMATIC) ret     = STATUS_SUCCESS;
    VAR(uint8, AUTOMATIC) busChannel = 0U;
    VAR(uint32, AUTOMATIC) newduty_offset;
    VAR(uint8, AUTOMATIC) mode = eMIOS_UC_Cn_GetMode(emiosIndex, ChanNum);
    uint32_t tempVal;
    /* Check PWM mode */
    switch (mode)
    {
    case (uint8)EMIOS_UC_MODE_PWM_OPWFMB: /* OPWFMB mode */
    {
        tempVal = eMIOS_UC_Bn_GetValue(emiosIndex, ChanNum);
        if (newDutyCycle < tempVal)
        {
            eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, newDutyCycle);
        }
        else
        {
            /* new duty cycle >= period */
            eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, eMIOS_UC_Bn_GetValue(emiosIndex, ChanNum)); /* 100% duty cycle */
        }
        break; /* End of OPWFMB mode */
    }
    case (uint8)EMIOS_UC_MODE_PWM_OPWMB: /* OPWMB mode */
    {
        if ((eMIOS_LLD_PWM_GetBusDrivenCh(emiosIndex, ChanNum, &busChannel) == STATUS_SUCCESS) && (busChannel < (uint8)EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL))
        {
            /* Check output update disabled */
            if (eMIOS_LLD_GetChNumOutUpdateDis(emiosIndex, ChanNum) == TRUE)
            {
                ret = STATUS_ERROR;
            }
            else
            {
                if( g_Opwmb_Offset[emiosIndex][ChanNum] == 0U)/* polyspace RTE:OBAI */ 
                {
                    ret = EMIOS_LLD_PWM_SetLeadingEdge(emiosIndex, ChanNum, 1UL);
                }
                else
                {
                    ret = EMIOS_LLD_PWM_SetLeadingEdge(emiosIndex, ChanNum, 1UL + g_Opwmb_Offset[emiosIndex][ChanNum]);
                }
            }
            VAR(uint32, AUTOMATIC) MC_Period = eMIOS_LLD_MC_GetPeriod(emiosIndex, busChannel);
            if (ret == STATUS_SUCCESS)
            {
                if (newDutyCycle < MC_Period)
                {
                    if(g_Opwmb_Offset[emiosIndex][ChanNum] == 0U)
                    {
                        EMIOS_LLD_PWM_SetTrailingEdge(emiosIndex, ChanNum, (newDutyCycle + 1UL));
                    }
                    else
                    {
                        newduty_offset = newDutyCycle + 1UL + g_Opwmb_Offset[emiosIndex][ChanNum];

                        if(newduty_offset <= MC_Period)
                        {
                            EMIOS_LLD_PWM_SetTrailingEdge(emiosIndex, ChanNum, (newduty_offset));
                        }
                        else
                        {
                            ret = STATUS_ERROR;
                        }
                    }
                }
                else /* new duty cycle >= period */
                {
                	if(MC_Period < 0xFFFFFFFFU)
                	{
                		(void)EMIOS_LLD_PWM_SetTrailingEdge(emiosIndex, ChanNum, (MC_Period + 1UL)); /* 100% duty cycle */
                	}
                }
            }
        }
        break; /* End of OPWMB mode */
    }
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    case (uint8)EMIOS_UC_MODE_PWM_OPWMT: /* OPWMT mode */
    {
        if ((eMIOS_LLD_PWM_GetBusDrivenCh(emiosIndex, ChanNum, &busChannel) == STATUS_SUCCESS) && (busChannel < (uint8)EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL))
        {
            /* Check output update disabled */
            if (eMIOS_LLD_GetChNumOutUpdateDis(emiosIndex, ChanNum) == TRUE)
            {
                ret = STATUS_ERROR;
            }
            else
            {
                if( g_Opwmt_Offset[emiosIndex][ChanNum] == 0U)/* polyspace RTE:OBAI */ 
                {
                    ret = EMIOS_LLD_PWM_SetLeadingEdge(emiosIndex, ChanNum, 1UL);
                }
                else
                {
                    ret = EMIOS_LLD_PWM_SetLeadingEdge(emiosIndex, ChanNum, 1UL + g_Opwmt_Offset[emiosIndex][ChanNum]);
                }
            }
            VAR(uint32, AUTOMATIC) MC_Period = eMIOS_LLD_MC_GetPeriod(emiosIndex, busChannel);
            if (ret == STATUS_SUCCESS)
            {
                if (newDutyCycle < MC_Period)
                {
                    if(g_Opwmt_Offset[emiosIndex][ChanNum] == 0U)
                    {
                        EMIOS_LLD_PWM_SetTrailingEdge(emiosIndex, ChanNum, (newDutyCycle + 1UL));
                    }
                    else
                    {
                        newduty_offset = newDutyCycle + 1UL + g_Opwmt_Offset[emiosIndex][ChanNum];
                    
                        if(newduty_offset <= MC_Period)
                        {
                            EMIOS_LLD_PWM_SetTrailingEdge(emiosIndex, ChanNum, (newduty_offset));
                        }
                        else
                        {
                            ret = STATUS_ERROR;
                        }
                    }
                }
                else /* new duty cycle >= period */
                {
                	if(MC_Period < 0xFFFFFFFFU)
                	{
                		(void)EMIOS_LLD_PWM_SetTrailingEdge(emiosIndex, ChanNum, (MC_Period + 1UL)); /* 100% duty cycle */
                	}
                }
            }
        }
        break; /* End of OPWMT mode */
    }
#endif /* (defined(RESOURCE_SUPPORT_EMIOS_OPWMT)) */
    case (uint8)EMIOS_UC_MODE_PWM_OPWMCB_TRAIL: /* OPWMCB mode */
    case (uint8)EMIOS_UC_MODE_PWM_OPWMCB_LEAD:
    {
        if ((eMIOS_LLD_PWM_GetBusDrivenCh(emiosIndex, ChanNum, &busChannel) == STATUS_SUCCESS) && (busChannel < (uint8)EMIOS_CNT_INTERNAL_DRIVEN_CHANNEL))
        {
            /* Check output update disabled */
            if (eMIOS_LLD_GetChNumOutUpdateDis(emiosIndex, busChannel) == TRUE)
            {
                ret = STATUS_ERROR;
            }
            else
            {
                VAR(uint32, AUTOMATIC) tmpIdealDutyCycle = 0U;
                /* Calibration ideal duty value */
                tmpIdealDutyCycle = eMIOS_LLD_PWM_CalibrationDuty(emiosIndex, busChannel, newDutyCycle);
                /* Set ideal duty value */
                eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum, tmpIdealDutyCycle);
            }
        }
        break;
    }
    default:
    {
        ret = STATUS_ERROR;
        break;
    }
    }

    return ret;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(status_t,  PWM_CODE) eMIOS_LLD_PWM_DAOC_SetDutyCycle \
( \
    VAR(uint8, AUTOMATIC) emiosIndex, \
    VAR(uint8, AUTOMATIC) ChanNum, \
    VAR(uint32, AUTOMATIC) DutyCycle, \
    VAR(uint32, AUTOMATIC) Period \
)
{
    VAR(uint32, AUTOMATIC) oldDutyCycle = 0;
    VAR(uint32, AUTOMATIC) newDutyCycle = 0;
    oldDutyCycle = eMIOS_UC_Bn_GetValue(emiosIndex, ChanNum);
    if(DutyCycle == 0UL)
    {
        newDutyCycle = 1U;
    }else if(DutyCycle < Period)
    {
        newDutyCycle = DutyCycle + 1U;
    }else{
        newDutyCycle = Period + 2U;
    }
    Pwm_Set_Emios_DAOC_B(emiosIndex, ChanNum, newDutyCycle);
    if((oldDutyCycle == 1UL) || (oldDutyCycle >= (Period + 2UL)))
    {
        eMIOS_PWM_UC_Bn_SetValue(emiosIndex, ChanNum , newDutyCycle);
        eMIOS_PWM_UC_An_SetValue(emiosIndex, ChanNum , 1U);
    }
    return STATUS_SUCCESS;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(status_t, PWM_CODE) EMIOS_LLD_PWM_SetLeadingEdge \
( \
    VAR(uint8, AUTOMATIC) emiosGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) newLeadingEdgePlacement \
)
{
    VAR(status_t, AUTOMATIC) status   = STATUS_SUCCESS;
    VAR(boolean, AUTOMATIC) temp = FALSE;
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    temp = ((eMIOS_UC_Cn_GetMode(emiosGroup, channel) == (uint32)EMIOS_UC_MODE_PWM_OPWMB) ||
             (eMIOS_UC_Cn_GetMode(emiosGroup, channel) == (uint32)EMIOS_UC_MODE_PWM_OPWMT)) ?TRUE:FALSE;
#else
    temp = (eMIOS_UC_Cn_GetMode(emiosGroup, channel) == (uint32)EMIOS_UC_MODE_PWM_OPWMB)?TRUE:FALSE;
#endif
    EMIOS_DEV_ERR(temp);

    (void)temp;

    eMIOS_PWM_UC_An_SetValue(emiosGroup, channel, newLeadingEdgePlacement);

    return status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) EMIOS_LLD_PWM_SetTrailingEdge \
( \
    VAR(uint8, AUTOMATIC) emiosGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) newTrailingEdgePlacement \
)
{
	VAR(boolean, AUTOMATIC) temp = FALSE;
#if (defined(RESOURCE_SUPPORT_EMIOS_OPWMT))
    temp = ((eMIOS_UC_Cn_GetMode(emiosGroup, channel) == (uint32)EMIOS_UC_MODE_PWM_OPWMB) ||
			  (eMIOS_UC_Cn_GetMode(emiosGroup, channel) == (uint32)EMIOS_UC_MODE_PWM_OPWMT))?TRUE:FALSE;
#else
    temp = (eMIOS_UC_Cn_GetMode(emiosGroup, channel) == (uint32)EMIOS_UC_MODE_PWM_OPWMB)?TRUE:FALSE;
#endif
    EMIOS_DEV_ERR(temp);

    EMIOS_DEV_ERR(newTrailingEdgePlacement >= eMIOS_UC_An_GetValue(emiosGroup, channel));

    (void)temp;

    eMIOS_PWM_UC_Bn_SetValue(emiosGroup, channel, newTrailingEdgePlacement);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

