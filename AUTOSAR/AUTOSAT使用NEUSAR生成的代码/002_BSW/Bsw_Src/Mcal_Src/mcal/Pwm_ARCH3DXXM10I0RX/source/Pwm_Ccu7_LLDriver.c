/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3007PT
* DESCRIPTION : CCFC3007PT CCU7 low level drivers code
* HISTORY     : Initial version
* @file     Pwm_Ccu7_LLDriver.c
* @version  3.0.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 3432,2844,2991,2995,2844,2934,2983 EOF*/
/*PRQA S 4397,2985,4534,1860,3401,4342,0312,0380 EOF*/
#include "Mcal.h"
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#include "Pwm_Irq.h"
#include "Pwm_Ccu7_LLDriver.h"
#include "Pwm_HAL_Wrapper.h"
#include "SchM_Pwm.h"

#define PWM_CCU7_LLD_C_VENDOR_ID                      176
#define PWM_CCU7_LLD_C_AR_REL_MAJOR_VER               4
#define PWM_CCU7_LLD_C_AR_REL_MINOR_VER               4
#define PWM_CCU7_LLD_C_AR_REL_REV_VER                 0
#define PWM_CCU7_LLD_C_SW_MAJOR_VER                   3
#define PWM_CCU7_LLD_C_SW_MINOR_VER                   0
#define PWM_CCU7_LLD_C_SW_PATCH_VER                   0

#if (PWM_CCU7_LLD_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_C_VENDOR_ID "
#endif
#if (PWM_CCU7_LLD_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_CCU7_LLD_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_C_AR_REL_MINOR_VER "
#endif
#if (PWM_CCU7_LLD_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_C_AR_REL_REV_VER "
#endif
#if (PWM_CCU7_LLD_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_C_SW_MAJOR_VER "
#endif
#if (PWM_CCU7_LLD_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_C_SW_MINOR_VER "
#endif
#if (PWM_CCU7_LLD_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_C_SW_PATCH_VER "
#endif

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(uint8_t, PWM_VAR) s_Ccu7_Pm_Status[CCU7_INSTANCE_COUNT];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(uint8_t, PWM_VAR) s_Ccu7_Duty0or100_Status[CCU7_INSTANCE_COUNT];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static VAR(Pwm_17_GtmCcu7_ChannelConfigType, AUTOMATIC) s_Pwm_ConfigPtr[CCU7_INSTANCE_COUNT][MCU_17_CCU7_NO_OF_COMPARATORS];
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"
static Pwm_17_GtmCcu7_ChannelStatusType s_Pwm_CoreChannelStatus[CCU7_INSTANCE_COUNT][MCU_17_CCU7_NO_OF_COMPARATORS];  //ModuleNum, ChannelNum.
#define PWM_STOP_SEC_VAR_SHARED_NO_INIT
#include "Pwm_MemMap.h"


/*******************************************************************************
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
*******************************************************************************/

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_lCcu7StartChannel \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum, \
    CONST(uint32, AUTOMATIC) period, \
    CONST(uint32, AUTOMATIC) dutycycle \
)
{
    VAR(uint32, AUTOMATIC) tempPeriod;
    VAR(uint32, AUTOMATIC) tempDutycycle;
    P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) pCcu7_Base = g_ccu7Base[moduleNum];
    tempPeriod = period;
    tempDutycycle = dutycycle;

    if((period != 0U) && (period == dutycycle))
    {
        tempDutycycle = PWM_MAX_TIMER_CCU7;
    }
    if(period > 1U)
    {
        tempPeriod = period - 1U;
    }
    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        SchM_Enter_Pwm_EXCLUSIVE_AREA_08();

        /* Set period and duty */
        if(channelNum == 0U)
        {
            pCcu7_Base->CC70SR.reg = tempDutycycle;
        }
        else if(channelNum == 1U)
        {
            pCcu7_Base->CC71SR.reg = tempDutycycle;
        }
        else if(channelNum == 2U)
        {
            pCcu7_Base->CC72SR.reg = tempDutycycle;
        }
        else
        {
            /*do nothing*/
        }
        pCcu7_Base->T12PR.reg = tempPeriod;
        SchM_Exit_Pwm_EXCLUSIVE_AREA_08();
    }
    else
    {
        SchM_Enter_Pwm_EXCLUSIVE_AREA_09();
        /*  Set period and duty */
        pCcu7_Base->C73SR.reg = tempDutycycle;
        pCcu7_Base->T13PR.reg = tempPeriod;
        SchM_Exit_Pwm_EXCLUSIVE_AREA_08();
    }
    /* enable shadow transfer */
    Mcu_17_Ccu7_TimerShadowTransfer(moduleNum, channelNum);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*******************************************************************************
** Description :     This function starts the PWM channel as given by the     **
**                   Input parameters with the desired properties.            **
*******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void,  PWM_CODE) Pwm_lCcu7StartChannelsInit \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum \
)
{
    VAR(uint32, AUTOMATIC) period     = 0U;
    VAR(uint32, AUTOMATIC) duty = 0U;
    period                   = s_Pwm_ConfigPtr[moduleNum][channelNum].PwmTimerPtr->TimerPeriodReg;/* polyspace RTE:IDP,NIV */
    duty                     = s_Pwm_ConfigPtr[moduleNum][channelNum].PwmTimerPtr->Ccu7ShadowReg;/* polyspace RTE:NIV */
    /* Initialize CCU7 timer*/
    Mcu_17_Ccu7_TimerInit(moduleNum, channelNum, s_Pwm_ConfigPtr[moduleNum][channelNum].PwmTimerPtr);
    Pwm_lCcu7StartChannel(moduleNum, channelNum, period, duty);
    /* If comparator is CCU73. */
    if(channelNum == MCU_CCU7_COMPARATOR_CCU73)
    {
        /* Set timer T13 to start on period zero match of T12 timer. */
        Pwm_Ccu7_SetTCTR2_T13TEC(moduleNum, (uint32)PWM_CONST_6);
        Pwm_Ccu7_SetTCTR2_T13TED(moduleNum, (uint32)PWM_CONST_1);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description :      Local function :Service to initialize fixed period     **
**                                   channel                                 **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void,  PWM_CODE) Pwm_lInitFixedPeriod \
( \
	CONST(uint8, AUTOMATIC)  moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)  channelNum \
)
{
    Pwm_lCcu7StartChannelsInit(moduleNum, channelNum);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description :      Local function :Service to initialize variable period  **
**                                   channel                                 **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void,  PWM_CODE) Pwm_lInitVariablePeriod \
( \
	CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum \
)
{
    VAR(Pwm_17_GtmCcu7_ChannelConfigType, AUTOMATIC)    pLocalPwmChanPtr; /* ROM pointer */
    P2VAR(Pwm_17_GtmCcu7_ChannelStatusType, AUTOMATIC, PWM_APPL_DATA)       pLocalChannelStatusPtr;

    VAR(uint32, AUTOMATIC) period;

    /* Initialize PWM configured channel ROM pointer */
    pLocalPwmChanPtr = s_Pwm_ConfigPtr[moduleNum][channelNum];
    period = pLocalPwmChanPtr.PwmPeriodDefault;
    pLocalChannelStatusPtr = &s_Pwm_CoreChannelStatus[moduleNum][channelNum];
    pLocalChannelStatusPtr->Pwm_CurrentPeriodVal = period;

    Pwm_lCcu7StartChannelsInit(moduleNum, channelNum);

} /* End of function Pwm_lInitVariablePeriod */
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


/******************************************************************************
** Description :      Local function :Service to initialize shifted and      **
**                                                 centre aligned channel    **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void,  PWM_CODE) Pwm_lInitShiftedCentreAligned \
( \
	CONST(uint8, AUTOMATIC)   moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)   channelNum \
)
{
    Pwm_lCcu7StartChannelsInit(moduleNum, channelNum);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description :      Local function to obtain the Idle state from           **
**                                                           PwmChannelInfo  **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(Pwm_17_GtmCcu7_OutputStateType, PWM_CODE) Pwm_lIdle \
( \
    CONST(uint16, AUTOMATIC) value \
)
{
    VAR(Pwm_17_GtmCcu7_OutputStateType, AUTOMATIC) retVal;

    retVal = (Pwm_17_GtmCcu7_OutputStateType)\
            (((uint16)(value) >> PWM_IDLESTATE_POS) & (PWM_IDLESTATE_MASK));
    return(retVal);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*******************************************************************************
** Description :     This function sets PWM channel to Idle state for         **
**                   ccu7 channels                                            **
*******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_lCcu7StartChannelIdle \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum, \
    VAR(uint32, AUTOMATIC) dutycycle \
)
{
    P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) pCcu7_Base = g_ccu7Base[moduleNum];

    SchM_Enter_Pwm_EXCLUSIVE_AREA_10();
    /* If timer type is T12 */
    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        /* Set duty cycle for timer T12 */
        /* CC7SR register */
        if(channelNum == 0U)
        {
            pCcu7_Base->CC70SR.reg = dutycycle;
        }
        else if(channelNum == 1U)
        {
            pCcu7_Base->CC71SR.reg = dutycycle;
        }
        else if(channelNum == 2U)
        {
            pCcu7_Base->CC72SR.reg = dutycycle;
        }
        else
        {
            /*nothing*/
        }
    }
    else
    {
        pCcu7_Base->C73SR.reg = dutycycle;
    }
    Mcu_17_Ccu7_TimerShadowTransfer(moduleNum, channelNum);

    s_Ccu7_Duty0or100_Status[moduleNum] |= (1U << channelNum);

    SchM_Exit_Pwm_EXCLUSIVE_AREA_10();
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description :      Local function : This function will convert the passed **
**                                    value to scaled value as per period    **
**                                    This will be utilized for edge aligned **
**                                    Type PWM channels                      **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(Pwm_17_GtmCcu7_PeriodType, PWM_CODE) Pwm_lGetAbsvalEdge \
( \
    CONST(Pwm_17_GtmCcu7_PeriodType, AUTOMATIC) period, \
    CONST(uint32, AUTOMATIC) value \
)
{
    VAR(uint32, AUTOMATIC) scaledValue;
    VAR(float32, AUTOMATIC) lScaledValue;
    VAR(float32, AUTOMATIC) absval;
    /* If period is zero */
    if (period == 0U)
    {
        /* Make scaled value zero for zero period */
        scaledValue = 0U;
    }
    else
    {
        /* dutycycle is in percentage */
        /* Covert the passed Relative value to absolute value as mentioned in SWS
        (AbsoluteDutyCycle=(((uint32)AbsolutePeriodTime *relativeDutyCycle)))>>15)*/
        absval = ((float32)period / (float32)PWM_SHIFT_BY15);
        lScaledValue = (absval * (float32)value);
        scaledValue =  (uint32) lScaledValue;/* polyspace RTE:OVFL */
        /* If period is less than scaled value */
        if (period <= scaledValue)
        {
        /* Make scaled value with full range of timer max */
        scaledValue = period;
        }
    }
    return (scaledValue);
}/* End of Pwm_lGetAbsvalEdge() function */
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*******************************************************************************
** Description :     This function returns the output state of the channel    **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(boolean, PWM_CODE) Pwm_lGetOutputState \
( \
    CONST(uint8, AUTOMATIC)  moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)  channelNum \
)
{
    VAR(uint8, AUTOMATIC) retVal = 0U;   /* Stores the output state      */
    VAR(Pwm_17_GtmCcu7_ChannelConfigType, AUTOMATIC) PwmChannelCfgPtr;
    PwmChannelCfgPtr = s_Pwm_ConfigPtr[moduleNum][channelNum];/* polyspace RTE:OBAI */
    P2CONST(s_CCU7_Type, PWM_CONST, PWM_APPL_CONST) base = g_ccu7Base[moduleNum];

    /* If CCU7 timer type is T12 */
    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        retVal = (uint8)((base->CMPSTAT.reg >> channelNum) & PWM_CONST_1);/* polyspace RTE:NIV */
    }
    else
    {
        retVal = (uint8)((base->CMPSTAT.reg >> PWM_CONST_6) & PWM_CONST_1);/* polyspace RTE:NIV */
    }
    if(PWM_GET_POLARITY(PwmChannelCfgPtr.PwmChannelInfo) == (uint8)PWM_17_GTMCCU7_HIGH)
    {
        retVal = retVal ^ (uint8)PWM_CONST_1;
    }
    return (retVal);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
* API Function
******************************************************************************/

/* @brief eMIOS PWM mode Initialize.
 * */
// channel Init
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void,  PWM_CODE) Ccu7_LLD_PWM_Init \
( \
	CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)       moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)       channelNum, \
    VAR(Pwm_17_GtmCcu7_ChannelConfigType, AUTOMATIC) ConfigPtr \
)
{
    VAR(Pwm_17_GtmCcu7_ChannelClassType, AUTOMATIC)         channelKind;
    P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) pCcu7_Base = g_ccu7Base[moduleNum];/* polyspace RTE:OBAI */
    s_Pwm_ConfigPtr[moduleNum][channelNum] = ConfigPtr; /*PRQA S 2919*//* polyspace RTE:OBAI */
    if (CCU7_KERNEL_ENABLE != pCcu7_Base->CLC.bit.DISS)/* polyspace RTE:NIV */
    {
        pCcu7_Base->CLC.bit.DISR = CCU7_KERNEL_ENABLE; //Enable CCU7[moduleNum]
    }
    channelKind = ((ConfigPtr.PwmChannelInfo >> 3U) & 0x3U);

#if (PWM_NOTIFICATION_SUPPORT == STD_ON)
    SchM_Enter_Pwm_EXCLUSIVE_AREA_16();
    s_Ccu7_Pm_Status[moduleNum] &= ~(1U << channelNum);
    SchM_Exit_Pwm_EXCLUSIVE_AREA_16();
#endif

    switch (channelKind)
    {
        case (uint8)PWM_VARIABLE_PERIOD:
        /* Variable period */
        Pwm_lInitVariablePeriod(moduleNum, channelNum);
        break;
        case (uint8)PWM_FIXED_PERIOD:
        /* Fixed period */
        Pwm_lInitFixedPeriod(moduleNum, channelNum);
        break;
        case (uint8)PWM_FIXED_PERIOD_SHIFTED:
        /*  If channel class is fixed period shifted */
        Pwm_lInitShiftedCentreAligned(moduleNum, channelNum);
        break;
        default:
        /* Default: Init center aligned channels */
        Pwm_lInitShiftedCentreAligned(moduleNum, channelNum);
        break;
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*******************************************************************************
** Description      : This interface configures an instance of a CCU7 timer   **
**                    channel. User of the CCU7 channel invokes this interface**
**                    at the time of channel's initialization.                **
*******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerInit \
( \
	CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)       moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum, \
    CONSTP2CONST(Mcu_17_Ccu7_TimerConfigType, PWM_CONST, PWM_APPL_CONST) pConfigPtr \
)
{
    P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) pCcu7_Base = g_ccu7Base[moduleNum];

    /* Based on the  Kernel, Timer and Comparator type, initialize the channel */
    if(channelNum <= MCU_CCU7_COMPARATOR_CCU72)  //T12
    {
        Pwm_Ccu7_SetTCTR0_T12PRE(moduleNum, ((pConfigPtr->TimerCtrlReg0 >> IFX_CCU7_TCTR0_T12PRE_OFF) & IFX_CCU7_TCTR0_T12PRE_MSK));/* polyspace RTE:NIV */
        Pwm_Ccu7_SetTCTR0_CTM(moduleNum, ((pConfigPtr->TimerCtrlReg0 >> IFX_CCU7_TCTR0_CTM_OFF) & \
                        IFX_CCU7_TCTR0_CTM_MSK));

        /* MODCTR.T12MODEN */
        Pwm_Ccu7_SetMODCTR_T12MODEN(moduleNum, channelNum, (pConfigPtr->ModCtrlReg >> (channelNum * CCU7_MODCTR_T12MODEN_LEN)) & CCU7_MODCTR_T12MODEN_MSK);/* polyspace RTE:NIV */
        Pwm_Ccu7_SetPSLR_PSL(moduleNum, channelNum, ((pConfigPtr->PasStateLvlReg >> (channelNum * CCU7_PSLR_PSL_LEN)) & CCU7_PSLR_PSL_MSK));/* polyspace RTE:NIV */
        Pwm_Ccu7_ClearISR_RCC7xRF(moduleNum, channelNum);
        Pwm_Ccu7_ClearISR_RT12PM(moduleNum);

        Pwm_Ccu7_SetT12MSEL_MSEL7x(moduleNum, channelNum, ((pConfigPtr->TimerModeSelectReg >> (channelNum * CCU7_T12MSEL_MSEL70_LEN)) & CCU7_T12MSEL_MSEL70_MSK));/* polyspace RTE:NIV */

        /* T1xPR register */
        pCcu7_Base->T12PR.reg = pConfigPtr->TimerPeriodReg & CCU7_T12_MSK;/* polyspace RTE:NIV */
        pCcu7_Base->T12.reg   = pConfigPtr->TimerCntReg & CCU7_T12_MSK;/* polyspace RTE:NIV */
        if(channelNum == 0U)
        {
            pCcu7_Base->CC70SR.reg = pConfigPtr->Ccu7ShadowReg & CCU7_T12_MSK;/* polyspace RTE:NIV */
        }
        else if(channelNum == 1U)
        {
            pCcu7_Base->CC71SR.reg = pConfigPtr->Ccu7ShadowReg & CCU7_T12_MSK;/* polyspace RTE:NIV */
        }
        else if(channelNum == 2U)
        {
            pCcu7_Base->CC72SR.reg = pConfigPtr->Ccu7ShadowReg & CCU7_T12_MSK;/* polyspace RTE:NIV */
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        Pwm_Ccu7_SetTCTR0_T13PRE(moduleNum, ((pConfigPtr->TimerCtrlReg0 >> IFX_CCU7_TCTR0_T13PRE_OFF) & IFX_CCU7_TCTR0_T13PRE_MSK));/* polyspace RTE:NIV */
        Pwm_Ccu7_SetMODCTR_ECT13O(moduleNum, ((pConfigPtr->ModCtrlReg >> CCU7_MODCTR_ECT13O_OFF) & IFX_CCU7_MODCTR_ECT13O_MSK));/* polyspace RTE:NIV */
        Pwm_Ccu7_SetPSLR_PSL73(moduleNum, ((pConfigPtr->PasStateLvlReg >> CCU7_PSLR_PSL73_OFF) & IFX_CCU7_PSLR_PSL73_MSK));/* polyspace RTE:NIV */
        Pwm_Ccu7_ClearISR_RT13PM(moduleNum);
        Pwm_Ccu7_ClearISR_RT13CM(moduleNum);

        /* T1xPR register */
        pCcu7_Base->T13PR.reg = pConfigPtr->TimerPeriodReg;/* polyspace RTE:NIV */
        pCcu7_Base->T13R.reg = pConfigPtr->TimerCntReg;/* polyspace RTE:NIV */
        pCcu7_Base->C73SR.reg = pConfigPtr->Ccu7ShadowReg;/* polyspace RTE:NIV */
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*******************************************************************************
** Description      : This function starts the specified CCU7 timer.          **
*******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerStart \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum \
)
{
    /* Based on the timer type, start the timer counter */
    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        /* Clear the any interrupt status flags */
        Pwm_Ccu7_ClearISR_RCC7xRF(moduleNum, channelNum);
        Pwm_Ccu7_ClearISR_RT12PM(moduleNum);
        /* Start the timer counter for T12*/
        Pwm_Ccu7_SetTCTR4_T12RS(moduleNum, CCU7_T12_START);
    }
    else
    {
        /* Clear the any interrupt status flags */
        Pwm_Ccu7_ClearISR_RT13PM(moduleNum);
        Pwm_Ccu7_ClearISR_RT13CM(moduleNum);
        /* Start the timer counter for T13*/
        Pwm_Ccu7_SetTCTR4_T13RS(moduleNum, CCU7_T13_START);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*******************************************************************************
** Description      : This function clear CCU7 Interrupt flag.          **
*******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_Pwm_LLD_ClearIntrFlag \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum \
)
{
    /* Based on the timer type, start the timer counter */
    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        /* Clear the any interrupt status flags */
        Pwm_Ccu7_ClearISR_RCC7xRF(moduleNum, channelNum);
        Pwm_Ccu7_ClearISR_RT12PM(moduleNum);
    }
    else
    {
        /* Clear the any interrupt status flags */
        Pwm_Ccu7_ClearISR_RT13PM(moduleNum);
        Pwm_Ccu7_ClearISR_RT13CM(moduleNum);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*******************************************************************************
** Description      : This function starts the specified CCU7 timer.          **
*******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerStop \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum \
)
{
    /* Based on the timer type, stop the timer counter */
    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        Pwm_Ccu7_SetTCTR4_T12RR(moduleNum, CCU7_T12_STOP);
    }
    else
    {
        Pwm_Ccu7_SetTCTR4_T13RR(moduleNum, CCU7_T13_STOP);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*******************************************************************************
** Description      : This function enables the shadow transfer for the       **
**                    specified CCU7 timer channel, that is to copy contents  **
**                    from shadow register to main register.                  **
*******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerShadowTransfer \
( \
    CONST(uint8, AUTOMATIC) moduleNum,  \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum \
)
{
    /* Based on the CCU7 Timer type, initiate the shadow transfer */
    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        Pwm_Ccu7_SetTCTR4_T12STR(moduleNum, CCU7_T12_STR);
    }
    else
    {
        Pwm_Ccu7_SetTCTR4_T13STR(moduleNum, CCU7_T13_STR);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/*******************************************************************************
** Description      : This function enables/disables the specified interrupts **
**                    for input the CCU7 timers.                              **
*******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerIntEnDis \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONSTP2CONST(Mcu_17_Ccu7_TimerChIntType, PWM_CONST, PWM_APPL_CONST) pCcu7IntConfig \
)
{
    Pwm_Ccu7_SetIEN_EnBits(moduleNum, (IEN_Intr_Edge_Type)pCcu7IntConfig->IEnLen, pCcu7IntConfig->RegVal, \
                pCcu7IntConfig->IEnBitPos);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description : Service for PWM De-Initialization                           **
**               1.After the call of this service, the state of the used     **
**                 peripherals/registers will set to power on reset state.   **
**               2.This service will disable all used interrupts and         **
**                  notifications.                                           **
**               3.This service clear all pending interrupt flags            **
**               4.All global variables will get reset                       **
**               5.All channel output signal state will set to Idle State    **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_DeInit \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    VAR(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)  channelNum \
)
{
    P2VAR(Pwm_17_GtmCcu7_ChannelStatusType, AUTOMATIC, PWM_APPL_CONST) pLocalChannelStatusPtr;
    VAR(Pwm_17_GtmCcu7_OutputStateType, AUTOMATIC)          idleState;
    VAR(uint8, AUTOMATIC)                                   polarity;
    VAR(uint32, AUTOMATIC)                                  duty;

    pLocalChannelStatusPtr = &s_Pwm_CoreChannelStatus[moduleNum][channelNum];

    pLocalChannelStatusPtr->Pwm_GlobChn = (uint32)0UL;/* polyspace RTE:IDP */  
    /* Set 0 in current period value */
    pLocalChannelStatusPtr->Pwm_CurrentPeriodVal = (uint32)0UL;
    /* Extract idleState,polarity*/
    idleState = Pwm_lIdle(s_Pwm_ConfigPtr[moduleNum][channelNum].PwmChannelInfo);/* polyspace RTE:OBAI */  

    polarity = PWM_GET_POLARITY(s_Pwm_ConfigPtr[moduleNum][channelNum].PwmChannelInfo);
    /* Set duty to maximum */
    duty = PWM_MAX_TIMER_CCU7;
    if (idleState != polarity)
    {
        /* Set dyty to zero */
        duty = 0U;
    }
    /* Set channel to idle state */
    Pwm_lCcu7StartChannelIdle(moduleNum, channelNum, duty);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
**               1.This service will allow to set the duty cycle of the PWM  **
**                 channel.                                                  **
**               2.If the duty cycle = 0% (value=0x0000), then the PWM output**
**                 state will set to opposite level of polarity.             **
**               3.If the duty cycle=100% (value=0x8000), then the PWM output**
**                 state will set to polarity level.                         **
**               4.If the duty cycle>100%(value>0x8000), then the PWM output **
**                 will be undefined behavior (recommended that, user not to **
**                 provide this range of value)                              **
**               5 If the duty cycle >0% and <100%,then the PWM output will  **
**                 set to active state according to duty cycle and period    **
**                 parameters , polarity state.                              **
**               6.Dependency on PWM_17_GTMCCU7_DUTYCYCLE_UPDATED_ENDPERIOD  **
**                 config                                                    **
**                 parameter.                                                **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_SetDutyCycle \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum, \
    CONST(uint16, AUTOMATIC)          dutyCycle \
)
{
    VAR(Pwm_17_GtmCcu7_ChannelClassType, AUTOMATIC)         channelKind;
    VAR(Pwm_17_GtmCcu7_ChannelConfigType, AUTOMATIC) pLocalPwmChanPtr;
    VAR(uint32, AUTOMATIC)                              period     = 0U;
    VAR(uint32, AUTOMATIC)                              scaledDuty = 0U;

    P2VAR(Pwm_17_GtmCcu7_ChannelStatusType, AUTOMATIC, PWM_APPL_CONST)        pLocalChannelStatusPtr;

    pLocalPwmChanPtr = s_Pwm_ConfigPtr[moduleNum][channelNum];/* polyspace RTE:OBAI */
    pLocalChannelStatusPtr = &s_Pwm_CoreChannelStatus[moduleNum][channelNum];
    channelKind = pLocalPwmChanPtr.PwmChannelInfo;

    switch (channelKind)
    {
    case (uint8)PWM_VARIABLE_PERIOD:
        /* If channel class is variable period */
        period = pLocalChannelStatusPtr->Pwm_CurrentPeriodVal;
        scaledDuty = (uint32)Pwm_lGetAbsvalEdge(period, (uint32)dutyCycle);
        break;
    case (uint8)PWM_FIXED_PERIOD:
        /* If channel class is fixed period */
        period = pLocalPwmChanPtr.PwmPeriodDefault;
        scaledDuty = (uint32)Pwm_lGetAbsvalEdge(period, (uint32)dutyCycle);
        break;
    case (uint8)PWM_FIXED_PERIOD_SHIFTED:
        /* If channel class is fixed shifted period */
        period = pLocalPwmChanPtr.PwmPeriodDefault;
        /* Get Scale value of duty according to period */
        scaledDuty = (uint32)Pwm_lGetAbsvalEdge(period, (uint32)dutyCycle);
        break;
    default:
        period = pLocalPwmChanPtr.PwmPeriodDefault;
        /* Get Scale value of duty according to period */
        scaledDuty = (uint32)Pwm_lGetAbsvalEdge(period, (uint32)dutyCycle);
        break;
    }/* End of Switch condition */

#if (PWM_NOTIFICATION_SUPPORT == STD_ON)
    SchM_Enter_Pwm_EXCLUSIVE_AREA_11();

    if((scaledDuty == 0U) || (scaledDuty == period))
    {
        s_Ccu7_Duty0or100_Status[moduleNum] |= (1U << channelNum);
    }
    else
    {
        s_Ccu7_Duty0or100_Status[moduleNum] &= ~(1U << channelNum);
    }

    SchM_Exit_Pwm_EXCLUSIVE_AREA_11();
#endif

    /* Start CCU7 channel */
    Pwm_lCcu7StartChannel\
    (moduleNum, channelNum, period, scaledDuty);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description : Service to set period and duty cycle (PWM019:)              **
**               1.This service will allow to set the period and duty cycle  **
**                 of the PWM channel.                                       **
**               2.Valid only for variable period                            **
**               3.If the duty cycle=0% (value=0x8000), then the PWM output  **
**                 state will set to opposite of polarity level.             **
**               4.If the duty cycle=100% (value=0x8000), then the PWM       **
**                 output state will set to polarity level.                  **
**               5.If the duty cycle>100%(value>0x8000), then the PWM output **
**                 will be undefined behavior (recommended that, user not to **
**                 provide this range of value)                              **
**               6 If the duty cycle >0% and <100%,then the PWM output will  **
**                 set to active state according to duty cycle and period    **
**                 parameters polarity state.                                **
**               7.To scale the duty cycle passed period  will be used       **
**                 Req's: PWM019, PWM076, PWM020, PWM041, PWM060             **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_SetPeriodAndDuty \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum, \
    CONST(Pwm_17_GtmCcu7_PeriodType, AUTOMATIC) period, \
    CONST(uint32, AUTOMATIC) dutyCycle \
)
{
    VAR(uint32, AUTOMATIC)                      scaledDuty;
    P2VAR(Pwm_17_GtmCcu7_ChannelStatusType, AUTOMATIC, PWM_APPL_CONST) pLocalChannelStatusPtr;

    s_Pwm_ConfigPtr[moduleNum][channelNum].PwmPeriodDefault = period;/* polyspace RTE:OBAI */
    pLocalChannelStatusPtr = &s_Pwm_CoreChannelStatus[moduleNum][channelNum];
    pLocalChannelStatusPtr->Pwm_CurrentPeriodVal = period;
    /* Extract scaled duty */
    scaledDuty = (uint32)Pwm_lGetAbsvalEdge(period, (uint32)dutyCycle);

#if (PWM_NOTIFICATION_SUPPORT == STD_ON)
    SchM_Enter_Pwm_EXCLUSIVE_AREA_12();

    if((scaledDuty == 0U) || (scaledDuty == period))
    {
        s_Ccu7_Duty0or100_Status[moduleNum] |= (1U << channelNum);
    }
    else
    {
        s_Ccu7_Duty0or100_Status[moduleNum] &= ~(1U << channelNum);
    }

    SchM_Exit_Pwm_EXCLUSIVE_AREA_12();
#endif

    Pwm_lCcu7StartChannel(moduleNum, channelNum, period, scaledDuty);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description : Service for to set PWM output to Idle State PWM021:         **
**               1.This API will be useful to set out to Idle immediately and**
**                 during emergency condition                                **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_SetOutputToIdle \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum \
)
{
    VAR(Pwm_17_GtmCcu7_OutputStateType, AUTOMATIC)      idleState;
    VAR(uint32, AUTOMATIC)                              period;
    VAR(uint32, AUTOMATIC)                              scaledDuty;
    VAR(uint32, AUTOMATIC)                              duty;
    VAR(uint8, AUTOMATIC)                               polarity;
    /* Local pointers */
    VAR(Pwm_17_GtmCcu7_ChannelConfigType, AUTOMATIC) pLocalPwmChanPtr;
    P2VAR(Pwm_17_GtmCcu7_ChannelStatusType, AUTOMATIC, PWM_APPL_CONST) pLocalChannelStatusPtr;
    VAR(Pwm_17_GtmCcu7_ChannelClassType, AUTOMATIC)         channelKind;

    /* Initialize ROM pointer */
    pLocalPwmChanPtr = s_Pwm_ConfigPtr[moduleNum][channelNum];/* polyspace RTE:OBAI */
    /* Store OCM value */
    idleState = Pwm_lIdle(pLocalPwmChanPtr.PwmChannelInfo);
    period = pLocalPwmChanPtr.PwmPeriodDefault;
    channelKind = pLocalPwmChanPtr.PwmChannelInfo;
    polarity = PWM_GET_POLARITY(pLocalPwmChanPtr.PwmChannelInfo);
    pLocalChannelStatusPtr = &s_Pwm_CoreChannelStatus[moduleNum][channelNum];

    if(channelKind == (uint8)PWM_VARIABLE_PERIOD)
    {
        period = pLocalChannelStatusPtr->Pwm_CurrentPeriodVal;
    }
    duty = PWM_MAX_DUTY;
    /* If Idle state and polarity mismatches */
    if (idleState != polarity)
    {
        /* Idle state and polarity mismatches then 0 % duty desired */
        duty = 0U;
    }
    /* Get Scale value of duty according to period */
    scaledDuty = Pwm_lGetAbsvalEdge(period, (uint32) duty);

#if (PWM_NOTIFICATION_SUPPORT == STD_ON)
    SchM_Enter_Pwm_EXCLUSIVE_AREA_13();

    if((scaledDuty == 0U) || (scaledDuty == period))
    {
        s_Ccu7_Duty0or100_Status[moduleNum] |= (1U << channelNum);
    }
    else
    {
        s_Ccu7_Duty0or100_Status[moduleNum] &= ~(1U << channelNum);
    }

    SchM_Exit_Pwm_EXCLUSIVE_AREA_13();
#endif

    /* Trace from Main*/
    Pwm_lCcu7StartChannelIdle(moduleNum, channelNum, scaledDuty);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description : Service to read the PWM output state                        **
**               1.If development error detection is enabled and an error is **
**                  detected the service returns PWM_17_GTMCCU7_LOW.         **
**               2.Output state of a PWM channel. Note that this will be read**
**            from the output state on the TOM/ATOM Channel (Assigned_HwUnit)**
**                 connected to the port pin. This will not be read directly **
**                 from the Port Pin. However both will be the same          **
**               Req: PWM022, PWM044, PWm047, PWM051                         **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(Pwm_17_GtmCcu7_OutputStateType, PWM_CODE) Ccu7_LLD_PWM_GetOutputState \
( \
    CONST(uint8, AUTOMATIC)  moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)  channelNum \
)
{
    VAR(Pwm_17_GtmCcu7_OutputStateType, AUTOMATIC)  ReturnState;

    ReturnState = Pwm_lGetOutputState(moduleNum, channelNum);
    return (ReturnState);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description : This service will disable all PWM signal notifications of   **
**               this channel. (PWM023:)                                     **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_DisableNotification \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum \
)
{
    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        Pwm_Ccu7_ClearISR_RCC7xRF(moduleNum, channelNum);
        Pwm_Ccu7_ClearISR_RT12PM(moduleNum);

        Pwm_Ccu7_SetIEN_ENCC7xRF(moduleNum, channelNum, 0x0u);

        SchM_Enter_Pwm_EXCLUSIVE_AREA_14();
        s_Ccu7_Pm_Status[moduleNum] &= ~(1U << channelNum);
        SchM_Exit_Pwm_EXCLUSIVE_AREA_14();
    }
    else
    {
        Pwm_Ccu7_ClearISR_RT13PM(moduleNum);
        Pwm_Ccu7_ClearISR_RT13CM(moduleNum);
        Pwm_Ccu7_SetIEN_ENT13CM(moduleNum, 0x0u);
        Pwm_Ccu7_SetIEN_ENT13PM(moduleNum, 0x0u);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/******************************************************************************
** Description : This service will enable the PWM signal notification        **
**               according to notification parameter. PWM024:                **
******************************************************************************/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_EnableNotification \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum, \
    CONST(Pwm_17_GtmCcu7_EdgeNotificationType, AUTOMATIC)  notification \
)
{
    P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) pCcu7_Base = g_ccu7Base[moduleNum];/* polyspace RTE:OBAI */
    VAR(uint16, AUTOMATIC) u16Pwm_RegPr = 0U;
    VAR(uint16, AUTOMATIC) u16Pwm_RegSr = 0U;
    VAR(uint8, AUTOMATIC) u8Polarity = 0U;

    if(channelNum < MCU_CCU7_COMPARATOR_CCU73)
    {
        Pwm_Ccu7_ClearISR_RCC7xRF(moduleNum, channelNum);
        Pwm_Ccu7_ClearISR_RT12PM(moduleNum);

        u16Pwm_RegPr = (uint16)pCcu7_Base->T12PR.reg;/* polyspace RTE:NIV */

        if(channelNum == MCU_CCU7_COMPARATOR_CCU70)
        {
            u16Pwm_RegSr = (uint16)pCcu7_Base->CC70SR.reg;/* polyspace RTE:NIV */
            u8Polarity = (uint8)(pCcu7_Base->PSLR.reg & 0x1U);/* polyspace RTE:NIV */

        }
        else if(channelNum == MCU_CCU7_COMPARATOR_CCU71)
        {
            u16Pwm_RegSr = (uint16)pCcu7_Base->CC71SR.reg;/* polyspace RTE:NIV */
            u8Polarity = (uint8)(pCcu7_Base->PSLR.reg & 0x4U) >> 2;/* polyspace RTE:NIV */
        }
        else
        {
            u16Pwm_RegSr = (uint16)pCcu7_Base->CC72SR.reg;/* polyspace RTE:NIV */
            u8Polarity = (uint8)(pCcu7_Base->PSLR.reg & 0x10U) >> 4;/* polyspace RTE:NIV */
        }

        SchM_Enter_Pwm_EXCLUSIVE_AREA_15();
        if((u16Pwm_RegSr != 0U) && (u16Pwm_RegSr != u16Pwm_RegPr))
        {
            s_Ccu7_Pm_Status[moduleNum] &= ~(1U << channelNum);

            if (3U == notification)
            {
                Pwm_Ccu7_SetIEN_ENCC7xRF(moduleNum, channelNum, 0x1U);
                Pwm_Ccu7_SetIEN_ENCC7xRF(moduleNum, 3U, 0x2U);

                s_Ccu7_Pm_Status[moduleNum] |= (1U << channelNum);
            }
            else if(1U == notification)
            {
                if(u8Polarity == 0U)
                {
                    Pwm_Ccu7_SetIEN_ENCC7xRF(moduleNum, channelNum, 0x1U);
                }
                else
                {
                    Pwm_Ccu7_SetIEN_ENCC7xRF(moduleNum, channelNum, 0x0U);
                    Pwm_Ccu7_SetIEN_ENCC7xRF(moduleNum, 3U, 0x2U);
                    s_Ccu7_Pm_Status[moduleNum] |= (1U << channelNum);
                }
            }
            else if(2U == notification)
            {
                if(u8Polarity == 0U)
                {
                    Pwm_Ccu7_SetIEN_ENCC7xRF(moduleNum, channelNum, 0x0U);
                    Pwm_Ccu7_SetIEN_ENCC7xRF(moduleNum, 3U, 0x2U);
                    s_Ccu7_Pm_Status[moduleNum] |= (1U << channelNum);
                }
                else
                {
                    Pwm_Ccu7_SetIEN_ENCC7xRF(moduleNum, channelNum, 0x1U);
                }
            }
            else
            {
                /* Do nothing */
            }
            SchM_Exit_Pwm_EXCLUSIVE_AREA_15();
        }
    }
    else
    {
        Pwm_Ccu7_ClearISR_RT13PM(moduleNum);
        Pwm_Ccu7_ClearISR_RT13CM(moduleNum);

        u16Pwm_RegPr = (uint16)pCcu7_Base->T13PR.reg;/* polyspace RTE:NIV */
        u16Pwm_RegSr = (uint16)pCcu7_Base->C73SR.reg;/* polyspace RTE:NIV */
        u8Polarity = (uint8)((pCcu7_Base->PSLR.reg & 0x80U) >> 7);/* polyspace RTE:NIV */

        if (3U == notification)
        {
            Pwm_Ccu7_SetIEN_ENT13CM(moduleNum, 0x1u);

            Pwm_Ccu7_SetIEN_ENT13PM(moduleNum, 0x1u);
        }
        else if(1U == notification)
        {
            if(u8Polarity == 0U)
            {
                Pwm_Ccu7_SetIEN_ENT13PM(moduleNum, 0x0u);
                Pwm_Ccu7_SetIEN_ENT13CM(moduleNum, 0x1u);
            }
            else
            {
                Pwm_Ccu7_SetIEN_ENT13PM(moduleNum, 0x1u);
                Pwm_Ccu7_SetIEN_ENT13CM(moduleNum, 0x0u);
            }
        }
        else if(2U == notification)
        {
            if(u8Polarity == 0U)
            {
                Pwm_Ccu7_SetIEN_ENT13PM(moduleNum, 0x1u);
                Pwm_Ccu7_SetIEN_ENT13CM(moduleNum, 0x0u);
            }
            else
            {
                Pwm_Ccu7_SetIEN_ENT13PM(moduleNum, 0x0u);
                Pwm_Ccu7_SetIEN_ENT13CM(moduleNum, 0x1u);
            }
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
FUNC(uint8*, PWM_CODE) Ccu7_LLD_PWM_Get_PmStatus(void)
{
    uint8* Ccu7_Pm_Status = (uint8*)s_Ccu7_Pm_Status;
    return Ccu7_Pm_Status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8*, PWM_CODE) Ccu7_LLD_PWM_Get_Duty0or100Status(void)
{
    uint8* Ccu7_Duty0or100_Status = (uint8*)s_Ccu7_Duty0or100_Status;
    return Ccu7_Duty0or100_Status;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* RESOURCE_SUPPORT_CCU7_IP */
