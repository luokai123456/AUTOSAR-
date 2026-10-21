/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30XX
* DESCRIPTION : CCFC30XX rtcapi low level drivers code
* HISTORY     : Initial version
* @file     Gpt_Rtc_LLDriver.c
* @version  3.0.0
* @date     2023 - 08 - 30
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 3432,0380,2844 EOF */
#include "Gpt_Rtc_LLDriver.h"
#include "derivative.h"
#include "Gpt_AutoSar_Wrapper.h"
#include "Gpt_Irq.h"

#ifdef RESOURCE_SUPPORT_RTC_API

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


#define RTCAPI_BASE_ADDR                         ((uint32)&RTC_API)
#define RTCAPI_BASE                              ((RTCAPI_tag_Type *)RTCAPI_BASE_ADDR)
#define RTCAPI_BASE_ARRAY                        {RTCAPI_BASE}

typedef  struct RTCAPI_tag                       RTCAPI_tag_Type;

extern P2CONST(Gpt_ConfigType, GPT_VAR,  GPT_APPL_CONST)  sGpt_pConfig[GPT_MAX_PARTITION];

#define GPT_START_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
static RTCAPI_tag_Type*  const g_RTCAPI_Base = RTCAPI_BASE_ARRAY;
#define GPT_STOP_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT
#include "Gpt_MemMap.h"
static VAR(uint32, AUTOMATIC) g_startTime = 0U;
#define GPT_STOP_SEC_VAR_INIT
#include "Gpt_MemMap.h"

/** @brief  Table of month length (in days) for the Un-leap-year*/
#define GPT_START_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
static CONST(uint8, GPT_CONST) ULY[] = {0U, 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};
#define GPT_STOP_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"

/** @brief Table of month length (in days) for the Leap-year*/
#define GPT_START_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
static CONST(uint8, GPT_CONST) LY[] = {0U, 31U, 29U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};
#define GPT_STOP_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"

/** @brief Number of days from begin of the non Leap-year*/

#define GPT_START_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
static CONST(uint16, GPT_CONST) MONTH_DAYS[] = {0U, 0U, 31U, 59U, 90U, 120U, 151U, 181U, 212U, 243U, 273U, 304U, 334U}; /* PRQA S 3218 */
#define GPT_STOP_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"


#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(boolean, GPT_CODE) RTCAPI_LLD_RTCIsYearLeap(VAR(uint16, AUTOMATIC) year)
{
    VAR(boolean, AUTOMATIC) returnValue;
    /* Check if yearLeap */
    if ((((year % 4U) == 0U) && ((year % 100U) != 0U)) || ((year % 400U) == 0U))
    {
        returnValue = TRUE;
    }
    else
    {
        returnValue = FALSE;
    }
    /* Return the exit code */
    return returnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(boolean, GPT_CODE) RTCAPI_LLD_RTCIsTimeDateCorrectFormat    \
(                                                                       \
    P2CONST(RTCAPI_RTCTimedateType, AUTOMATIC, GPT_APPL_CONST) timeDate \
)
{

    /* Declare local variables */
    VAR(boolean, AUTOMATIC) returnValue;
    P2CONST(uint8, AUTOMATIC, GPT_APPL_CONST) pDays;

    /* Set the days-in-month table for the corresponding year */
    pDays = (RTCAPI_LLD_RTCIsYearLeap(timeDate->year) == TRUE) ? (LY) : (ULY);

    /* Check if the time and date are in the correct ranges */
    if ((timeDate->year < YEAR_RANGE_START) || (timeDate->year > YEAR_RANGE_END)
            ||  (timeDate->month < 1U) || (timeDate->month > 12U)
            ||  (timeDate->day < 1U) || (timeDate->day > 31U)
            ||  (timeDate->hour >= HOURS_IN_A_DAY)
            ||  (timeDate->minutes >= MINS_IN_A_HOUR) || (timeDate->seconds >= SECONDS_IN_A_MIN))
    {
        returnValue = FALSE;
    }
    /* Check if the day is a valid day from the corresponding month */
    else if (timeDate->day > pDays[timeDate->month]) /* PRQA S 0491 */
    {
        returnValue = FALSE;
    }
    else
    {
        returnValue = TRUE;
    }

    /* Return the exit code */
    return returnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(uint32, GPT_CODE) RTC_API_LLD_TickTotime(VAR(uint64, AUTOMATIC) tick)
{
    CONSTP2CONST(RTCAPI_tag_Type, GPT_CONST, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    VAR(uint32, AUTOMATIC) frequency;
    VAR(uint32, AUTOMATIC) ms;
    if(base->CR.B.CLKSEL == (uint32)RTC_SIRC_CLK)  /* polyspace RTE:NIV */
    {
        frequency = 32000U;
    }
    else if(base->CR.B.CLKSEL == (uint32)RTC_FIRC_CLK) /* polyspace RTE:NIV */
    {
        frequency = 16000000U;
    }
    else
    {
        frequency = 0U;
        ret = STATUS_ERROR;
    }

    if(base->CR.B.DIV32EN == TRUE)  /* polyspace RTE:NIV */
    {
        frequency = frequency / 32U;
    }

    if((base->CR.B.DIV512EN == TRUE)&&(base->CR.B.CLKSEL == (uint32)RTC_FIRC_CLK)) /* polyspace RTE:NIV */
    {
        frequency = frequency / 512U;
    }

    ms = (ret != STATUS_SUCCESS)? 0U : (uint32_t)((uint64_t)(tick * 1000U) / frequency);/*PRQA S 3396*/ /* polyspace RTE:ZDV */

    return ms;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) RTC_API_SUPV_SetSUPV           \
(                                                                \
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base, \
    VAR(boolean, AUTOMATIC) enable                               \
)
{
    base->SUPV.B.SUPV = (uint32)((enable == TRUE)? 1u : 0u);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(uint8, GPT_CODE) RTC_API_CR_GetCNTEN            \
(                                                                 \
    CONSTP2CONST(RTCAPI_tag_Type, GPT_CONST, GPT_APPL_CONST) base \
)
{
    return (uint8)(base->CR.B.CNTEN); /* polyspace RTE:NIV */
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) RTC_API_CR_SetFRZEN            \
(                                                                \
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base, \
    VAR(boolean, AUTOMATIC) enable                               \
)
{
    base->CR.B.FRZEN = (uint32)((enable == TRUE)? 1u : 0u);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) RTC_API_CR_SetCLKSEL           \
(                                                                \
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base, \
    VAR(uint8, AUTOMATIC) srcClock                               \
)
{
    base->CR.B.CLKSEL = (uint32)srcClock;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) RTC_API_CR_SetDIV512EN         \
(                                                                \
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base, \
    VAR(boolean, AUTOMATIC) enable                               \
)
{
    base->CR.B.DIV512EN = (uint32)((enable == TRUE)? 1u : 0u);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) RTC_API_CR_SetDIV32EN          \
(                                                                \
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base, \
    VAR(boolean, AUTOMATIC) enable                               \
)
{
    base->CR.B.DIV32EN = (uint32)((enable == TRUE)? 1u : 0u);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) RTC_API_SR_ClearROVRF         \
(                                                               \
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base \
)
{
    base->SR.R &= 0x400U; /* polyspace RTE:NIV */
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(uint32, GPT_CODE) RTC_API_CR_GetRTCCNT          \
(                                                                 \
    CONSTP2CONST(RTCAPI_tag_Type, GPT_CONST, GPT_APPL_CONST) base \
)
{
    return (uint32)(base->RTCCNT.R); /* polyspace RTE:NIV */
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) RTC_API_SetCR                  \
(                                                                \
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base, \
    VAR(uint32, AUTOMATIC) value                                 \
)
{
    base->CR.R = (uint32)value;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) RTC_API_LLD_SetCNTEN(VAR(boolean, AUTOMATIC) enable)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    base->CR.B.CNTEN = (uint32)((enable == TRUE)? 1u : 0u);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTC_API_LLD_ClearAPIF(void)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    base->SR.R &= 0x2000U; /* polyspace RTE:NIV */
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTC_API_LLD_SetAPIEN(VAR(boolean, AUTOMATIC) enable)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    base->CR.B.APIEN = (uint32)((enable == TRUE)? 1u : 0u);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTC_API_LLD_SetAPIIE(VAR(boolean, AUTOMATIC) enable)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;

    base->CR.B.APIIE = (uint32)((enable == TRUE)? 1u : 0u);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint8, GPT_CODE) RTC_API_LLD_GetRTCF(void)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    return (uint8)(base->SR.B.RTCF); /* polyspace RTE:NIV */
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTC_API_LLD_SetRTCVAL(VAR(uint32, AUTOMATIC) u32Value)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    base->CR.B.RTCVAL = (uint32)u32Value;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTC_API_LLD_SetAPIVAL(VAR(uint32, AUTOMATIC) u32Value)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;

    RTC_API_LLD_SetAPIEN(FALSE);

    base->CR.B.APIVAL = (uint32)u32Value;

    RTC_API_LLD_SetAPIEN(TRUE);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTC_API_LLD_ClearRTCF(void)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    base->SR.R &= 0x20000000U; /* polyspace RTE:NIV */
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTC_API_LLD_SetRTCIE(VAR(boolean, AUTOMATIC) enable)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    base->CR.B.RTCIE = (uint32)((enable == TRUE)? 1u : 0u);
    if(RTC_API_CR_GetCNTEN(base) == TRUE)
    {
        RTC_API_LLD_SetCNTEN(FALSE);
        RTC_API_LLD_SetCNTEN(TRUE);
    }
    else
    {
        RTC_API_LLD_SetCNTEN(FALSE);
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) RTC_API_LLD_GetRTCVAL(void)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    return (uint32)(base->CR.B.RTCVAL); /* polyspace RTE:NIV */
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) RTCAPI_LLD_ModuleInit(const rtcapi_module_t * const config)
{
    VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_OK;

    if(config == NULL_PTR)
    {
        ret = E_NOT_OK;
    }
    else
    {
        CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base =  (RTCAPI_tag_Type *)g_RTCAPI_Base;

        RTC_API_SUPV_SetSUPV(base, FALSE);

        RTC_API_CR_SetFRZEN(base, 0);

        RTC_API_CR_SetDIV32EN(base, config->prescaler32);

        RTC_API_CR_SetDIV512EN(base, config->prescaler512);

        RTC_API_CR_SetCLKSEL(base, (uint8)config->clockType);
    }

    return ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTCAPI_LLD_RTCInit(void)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;

    RTC_API_LLD_ClearRTCF();

    RTC_API_SR_ClearROVRF(base);

    RTC_API_LLD_SetRTCIE(TRUE);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTCAPI_LLD_APIInit(void)
{
    RTC_API_LLD_ClearAPIF();
    
    RTC_API_LLD_SetAPIEN(TRUE);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTCAPI_LLD_StartCounter(void)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;
    VAR(uint32, AUTOMATIC) timeout;
    VAR(uint32, AUTOMATIC) value;
    timeout = 0xFFFFFFU;

    if(RTC_API_CR_GetCNTEN(base) == TRUE)
    {
        RTC_API_LLD_SetCNTEN(FALSE);
        RTC_API_LLD_SetCNTEN(TRUE);
    }
    else
    {
        RTC_API_LLD_SetCNTEN(TRUE);
    }

    while(timeout > 0U)
    {
    	timeout--;
    	value = RTC_API_CR_GetRTCCNT(base);
    	if(value >= 4U)
    	{
    		break;
    	}
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) RTCAPI_LLD_StopCounter(void)
{
    VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_OK;

    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;

    RTC_API_LLD_SetCNTEN(FALSE);

    if(RTC_API_CR_GetCNTEN(base) != FALSE)
    {
        ret = E_NOT_OK;
    }

    return ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) RTCAPI_LLD_GetRunTime(void)
{
    CONSTP2CONST(RTCAPI_tag_Type, GPT_CONST, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;

    VAR(uint32, AUTOMATIC) counterCnt;

    counterCnt = RTC_API_CR_GetRTCCNT(base);

    return counterCnt;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTCAPI_LLD_DeInit(void)
{
    CONSTP2VAR(RTCAPI_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = (RTCAPI_tag_Type *)g_RTCAPI_Base;

    RTC_API_LLD_ClearRTCF();
    RTC_API_SR_ClearROVRF(base);
    RTC_API_LLD_ClearAPIF();
    RTC_API_SetCR(base, 0U);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTCAPI_LLD_RTCIrqHandler(void)
{
    VAR(Gpt_ChannelType, AUTOMATIC) u8Gpt_Instance = 0U;
	VAR(uint32, AUTOMATIC) Rtc_CoreIndex = Gpt_GetCoreID();

    u8Gpt_Instance = Gpt_GetInstance(GPT_MODULE_RTC, 0);


#if (GPT_ENABLE_MULTICORE == STD_ON)
    P2VAR(Gpt_Wrapper_ChannelInfo, AUTOMATIC, GPT_APPL_DATA) pChannelInfo = NULL_PTR;

    VAR(uint32, AUTOMATIC) CurrentCoreId = 1 << Gpt_GetCoreID();

    pChannelInfo = Gpt_AutoSar_Wrapper_GetChannelInfo(u8Gpt_Instance);

    VAR(uint8, AUTOMATCI) Temp = CurrentCoreId & pChannelInfo->pGpt_CoreId[u8Gpt_Instance];

    if(Temp != 0)
#endif
    {
        RTC_API_LLD_ClearRTCF();
        RTC_API_LLD_SetCNTEN(FALSE);
        RTC_API_LLD_SetCNTEN(TRUE);

        if (GPT_CH_MODE_ONESHOT == (*(sGpt_pConfig[Rtc_CoreIndex]->pChannelConfig))[u8Gpt_Instance].eChannelMode)/* polyspace RTE:OBAI,IDP*/
		{
		   Gpt_StopTimer(u8Gpt_Instance);
		}

        Gpt_ProcessCommonIrq(u8Gpt_Instance);
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTCAPI_LLD_APIIrqHandler(void)
{

    VAR(Gpt_ChannelType, AUTOMATIC) u8Gpt_Instance = 0U;
	VAR(uint32, AUTOMATIC) Rtc_CoreIndex = Gpt_GetCoreID();

	u8Gpt_Instance = Gpt_GetInstance(GPT_MODULE_API, 0);

	if (GPT_CH_MODE_ONESHOT == (*(sGpt_pConfig[Rtc_CoreIndex]->pChannelConfig))[u8Gpt_Instance].eChannelMode) /* polyspace RTE:OBAI,IDP*/
    {
       Gpt_StopTimer(u8Gpt_Instance);
    }

#if (GPT_ENABLE_MULTICORE == STD_ON)
    P2VAR(Gpt_Wrapper_ChannelInfo, AUTOMATIC, GPT_APPL_DATA) pChannelInfo = NULL_PTR;

    VAR(uint32, AUTOMATIC) CurrentCoreId = (uint8)(1u << (uint8)Gpt_GetCoreID());

    pChannelInfo = Gpt_AutoSar_Wrapper_GetChannelInfo(u8Gpt_Instance);

    VAR(uint8, AUTOMATCI) Temp = CurrentCoreId & pChannelInfo->pGpt_CoreId[u8Gpt_Instance];

    if(Temp != 0)
#endif
    {
        RTC_API_LLD_ClearAPIF();
        Gpt_ProcessCommonIrq(u8Gpt_Instance);
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will set the date passed by the user.
*
* @param[in]     *timeDate          pointer to configuration
* @return        Std_ReturnType  status error
* @pre           The driver needs to be initialized.
* @implements    RTCAPI_LLD_RTCSetTimeDate_Activity
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) RTCAPI_LLD_RTCSetTimeDate                \
(                                                                       \
    P2CONST(RTCAPI_RTCTimedateType, AUTOMATIC, GPT_APPL_CONST) timeDate \
)
{
    VAR(Std_ReturnType, AUTOMATIC) returnValue;

#if GPT_DEV_ERROR_DETECT == STD_ON
    DEV_ASSERT(NULL_PTR != timeDate);
#endif

    /* Check if the date/time format is correct */
    if(!(RTCAPI_LLD_RTCIsTimeDateCorrectFormat(timeDate) == TRUE))
    {
        /* Set the status code to error */
        returnValue = E_NOT_OK;
    }
    else
    {
        /* Convert the time and date to seconds and save it in the state structure */
        RTCAPI_LLD_RTCConvertTimeDateToSeconds(timeDate, &g_startTime);
        returnValue = E_OK;
    }

    return returnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will get the current time and date and it will
*                               store in the state structure.
*
* @param[in]     *timeDate          pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    RTCAPI_LLD_RTCGetTimeDate_Activity
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTCAPI_LLD_RTCGetTimeDate                             \
(                                                                          \
    CONSTP2VAR(RTCAPI_RTCTimedateType, AUTOMATIC, GPT_APPL_CONST) timeDate \
)
{
    VAR(uint32, AUTOMATIC) counterValue = 0U;
    VAR(uint32, AUTOMATIC) secondsPassed = 0U;

#if GPT_DEV_ERROR_DETECT == STD_ON
    DEV_ASSERT(NULL_PTR != timeDate);
#endif

    /* Get the current counter value in ticks */
    counterValue = RTCAPI_LLD_GetRunTime();
    /* Compute the number of the seconds passed since setting the time and date */
    secondsPassed = RTC_API_LLD_TickTotime(counterValue) / 1000U;
    /* Add the start time to the calculated value */
    secondsPassed += g_startTime;
    /* Convert the seconds into time/date format */
    RTCAPI_LLD_RTCConvertSecondsToTimeDate(&secondsPassed, timeDate);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will convert seconds into time-date format.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    RTCAPI_LLD_RTCConvertSecondsToTimeDate_Activity
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTCAPI_LLD_RTCConvertSecondsToTimeDate                \
(                                                                          \
    P2CONST(uint32, AUTOMATIC, GPT_APPL_CONST) seconds,                    \
    CONSTP2VAR(RTCAPI_RTCTimedateType, AUTOMATIC, GPT_APPL_CONST) timeDate \
)
{
#if GPT_DEV_ERROR_DETECT == STD_ON
	DEV_ASSERT(NULL_PTR != seconds);
	DEV_ASSERT(NULL_PTR != timeDate);
#endif
    /* Declare the variables needed */
    VAR(uint8, AUTOMATIC) index;
    VAR(boolean, AUTOMATIC) yearLeap;
    VAR(uint32, AUTOMATIC) numberOfDays;
    VAR(uint32, AUTOMATIC) tempSeconds;
    VAR(uint16, AUTOMATIC) daysInYear;

    /* Because the starting year(1970) is not leap, set the daysInYear
     * variable with the number of the days in a normal year
     */
    daysInYear = DAYS_IN_A_YEAR;

    /* Set the year to the beginning of the range */
    timeDate->year = YEAR_RANGE_START;

    /* Get the number of days */
    numberOfDays = (*seconds) / SECONDS_IN_A_DAY;
    /* Get the number of seconds remaining */
    tempSeconds = (*seconds) % SECONDS_IN_A_DAY;

    /* Get the current hour */
    timeDate->hour        = (uint16)(tempSeconds / SECONDS_IN_A_HOUR);
    /* Get the remaining seconds */
    tempSeconds           = tempSeconds % SECONDS_IN_A_HOUR;
    /* Get the minutes */
    timeDate->minutes     = (uint16)(tempSeconds / SECONDS_IN_A_MIN);
    /* Get seconds */
    timeDate->seconds     = (uint8)(tempSeconds % SECONDS_IN_A_MIN);

    /* Get the current year */
    while (numberOfDays >= daysInYear)
    {
        /* Increment year if the number of days is greater than the ones in
         * one year
         */
        timeDate->year++;
        /* Subtract the number of the days */
        numberOfDays -= daysInYear;

        /* Check if the year is leap or unleap */
        if (!(RTCAPI_LLD_RTCIsYearLeap(timeDate->year) == TRUE))
        {
            /* Set the number of non leap year to the current year number
             * of days.
             */
            daysInYear = DAYS_IN_A_YEAR;
        }
        else
        {
            /* Set the number of leap year to the current year number
             * of days.
             */
            daysInYear = DAYS_IN_A_LEAP_YEAR;
        }
    }

    /* Add the current day */
    numberOfDays += 1U;

    /* Check if the current year is leap */
    yearLeap = RTCAPI_LLD_RTCIsYearLeap(timeDate->year);

    /* Get the month */
    for (index = 1U; index <= 12U; index++)
    {
        VAR(uint32, AUTOMATIC) daysInCurrentMonth = ((yearLeap == TRUE) ? (uint32)LY[index] : (uint32)ULY[index]);
        if (numberOfDays <= daysInCurrentMonth)
        {
            timeDate->month = (uint16)index;
            break;
        }
        else
        {
            numberOfDays -= daysInCurrentMonth;
        }

    }

    /* Set the current day */
    timeDate->day = (uint16)numberOfDays;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

/*================================================================================================*/
/**
*
* @brief         Rtc Driver function
* @details       This function:
*                        - will convert time-date into seconds.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    RTCAPI_LLD_RTCConvertTimeDateToSeconds_Activity
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) RTCAPI_LLD_RTCConvertTimeDateToSeconds              \
(                                                                        \
    P2CONST(RTCAPI_RTCTimedateType, AUTOMATIC, GPT_APPL_CONST) timeDate, \
    CONSTP2VAR(uint32, AUTOMATIC, GPT_APPL_CONST) seconds                \
)
{
#if GPT_DEV_ERROR_DETECT == STD_ON
	DEV_ASSERT(NULL_PTR != seconds);
	DEV_ASSERT(NULL_PTR != timeDate);
#endif

    /* Declare local variables */
    VAR(uint16, AUTOMATIC) year;

    /* Convert years to seconds */
    (*seconds) = (uint32)(DAYS_IN_A_YEAR * (uint32)(SECONDS_IN_A_DAY));
    (*seconds) *= ((uint32)timeDate->year - YEAR_RANGE_START);

    /* Add the seconds from the leap years */
    for (year = YEAR_RANGE_START; year < timeDate->year; year++)
    {
        if (RTCAPI_LLD_RTCIsYearLeap(year) == TRUE)
        {
            (*seconds) += SECONDS_IN_A_DAY;
        }
    }

    /* If the current year is leap and 29th of February has passed, add
     * another day to seconds passed.
     */
    if ((RTCAPI_LLD_RTCIsYearLeap(year) == TRUE) && (timeDate->month > 2U))
    {
        (*seconds) += SECONDS_IN_A_DAY;
    }

    /* Add the rest of the seconds from the current month */
    	(*seconds) += MONTH_DAYS[timeDate->month] * SECONDS_IN_A_DAY;  /* polyspace RTE:OBAI */
    /* Add the rest of the seconds from the current day */
    (*seconds) += (uint32)(((uint32)timeDate->day - 1U) * (uint32)SECONDS_IN_A_DAY);
    /* Add the rest of the seconds from the current time */
    (*seconds) += (uint32)(((uint32)timeDate->hour * SECONDS_IN_A_HOUR)   + \
                           ((uint32)timeDate->minutes * SECONDS_IN_A_MIN) + \
                            (uint32)timeDate->seconds);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#endif
