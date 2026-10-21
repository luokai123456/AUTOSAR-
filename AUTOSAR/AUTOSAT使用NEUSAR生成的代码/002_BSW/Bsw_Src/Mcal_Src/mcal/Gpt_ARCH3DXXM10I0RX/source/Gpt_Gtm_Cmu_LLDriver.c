
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30XX
* DESCRIPTION : CCFC30XX GTM TOM low level drivers code
* HISTORY     : Initial version
* @file     Gpt_Gtm_Cmu_LLDriver.c
* @version  3.0.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S  0380,3432 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Gpt_Gtm_LLDriver.h"
#include "Gpt_Irq.h"
#if (defined(RESOURCE_SUPPORT_GTM104))


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


typedef volatile struct GTM_CMU_tag st_Gpt_GTM_CMU_tag;

#define GPT_GTM_CMU_BASE_ADDR							 (&GTM_CMU)

#define GPT_START_SEC_VAR_INIT
#include "Gpt_MemMap.h"
static P2VAR(st_Gpt_GTM_CMU_tag, AUTOMATIC, GPT_APPL_DATA) g_GPT_GTM_CMU_Base[1u] = {
										 GPT_GTM_CMU_BASE_ADDR
};
#define GPT_STOP_SEC_VAR_INIT
#include "Gpt_MemMap.h"
 
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_IsEnableClock(    \
    VAR(GPT_GTM_CMU_Clock_Type, AUTOMATIC) Clock,                \
    VAR(VAR(GPT_GTM_Status_Type, AUTOMATIC), AUTOMATIC) IsEnable \
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
	VAR(uint8, AUTOMATIC) Status = 0;

	if((uint8)IsEnable == 1u)
	{
		Status = 2u;
	}
	else
	{
		Status = 1u;
	}

    switch(Clock)
    {
        case GPT_GTM_CMU_CLK0:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_CLK0 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_CLK1:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_CLK1 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_CLK2:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_CLK2 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_CLK3:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_CLK3 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_CLK4:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_CLK4 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_CLK5:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_CLK5 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_CLK6:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_CLK6 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_CLK7:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_CLK7 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_ECLK0:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_ECLK0 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_ECLK1:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_ECLK1 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_ECLK2:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_ECLK2 = (uint8)Status;
            break;
        }
        case GPT_GTM_CMU_FXCLK:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_FXCLK = (uint8)Status;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

	return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_SetGlobalClockNumerator(VAR(uint32, AUTOMATIC) Numerator)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_NOT_OK;
    /*Value can only be modified when all clock enables EN_CLK[n] and the EN_FXCLK are disabled.*/
    if(g_GPT_GTM_CMU_Base[0]->CLK_EN.R != 0u)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    g_GPT_GTM_CMU_Base[0]->GCLK_NUM.B.GCLK_NUM = Numerator;

    if(g_GPT_GTM_CMU_Base[0]->GCLK_NUM.B.GCLK_NUM != Numerator)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_SetGlobalClockDenominator(VAR(uint32, AUTOMATIC) Denominator)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    /*Value can only be modified when all clock enables EN_CLK[n] and the EN_FXCLK are disabled.*/
    if(g_GPT_GTM_CMU_Base[0]->CLK_EN.R != 0u)
    {
    	Ret = (Std_ReturnType)E_NOT_OK;
    }

    g_GPT_GTM_CMU_Base[0]->GCLK_DEN.B.GCLK_DEN = Denominator;

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_SetClockCount(
    VAR(GPT_GTM_CMU_Clock_Type, AUTOMATIC) Clock,
    VAR(uint32, AUTOMATIC) Count
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    /*Value can only be modified when corresponding clock enable EN_CLK[0:7] is disabled.*/
    if((g_GPT_GTM_CMU_Base[0]->CLK_EN.R & 0xFFFFUL) != 0u)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    switch(Clock)
    {
        case GPT_GTM_CMU_CLK0:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_CTRL[0].B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK1:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_CTRL[1].B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK2:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_CTRL[2].B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK3:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_CTRL[3].B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK4:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_CTRL[4].B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK5:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_CTRL[5].B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK6:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_6_CTRL.R = Count;
            break;
        }
        case GPT_GTM_CMU_CLK7:
        {
            g_GPT_GTM_CMU_Base[0]->CLK_7_CTRL.R = Count;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_CMU_LLD_SelectFXCLKSource(VAR(GTM_CMU_FXCLKSource_Type, AUTOMATIC) FXCLKSource)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    /*This value can only be written, when the CMU_FXCLK generation is disabled. */
    if(g_GPT_GTM_CMU_Base[0]->CLK_EN.B.EN_FXCLK != 0u)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    g_GPT_GTM_CMU_Base[0]->FXCLK_CTRL.B.FXCLK_SEL = (uint8)FXCLKSource;
    if(g_GPT_GTM_CMU_Base[0]->FXCLK_CTRL.B.FXCLK_SEL != (uint8)FXCLKSource)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    
    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#endif

