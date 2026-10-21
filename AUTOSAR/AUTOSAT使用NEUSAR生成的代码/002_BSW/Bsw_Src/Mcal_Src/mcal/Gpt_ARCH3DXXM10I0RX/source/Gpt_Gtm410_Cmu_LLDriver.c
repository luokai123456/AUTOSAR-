
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
* @file     Gpt_GTM_Cmu_LLDriver.c
* @version  3.0.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 0380 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Gpt_Gtm_LLDriver.h"
#include "Gpt_Irq.h"
#if (defined(RESOURCE_SUPPORT_GTM410))


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
			GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK0 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_CLK1:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK1 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_CLK2:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK2 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_CLK3:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK3 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_CLK4:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK4 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_CLK5:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK5 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_CLK6:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK6 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_CLK7:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_CLK7 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_ECLK0:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_ECLK0 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_ECLK1:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_ECLK1 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_ECLK2:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_ECLK2 = (uint8_t)Status;
		break;
		case GPT_GTM_CMU_FXCLK:
			GTM4.GLS[0].CMU.CLK_EN.B.EN_FXCLK = (uint8_t)Status;
		break;
		default:
			Ret =  (Std_ReturnType)STATUS_ERROR;
		break;
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
    if(GTM4.GLS[0].CMU.CLK_EN.R != 0u)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    GTM4.GLS[0].CMU.GCLK_NUM.B.GCLK_NUM = Numerator;

    if(GTM4.GLS[0].CMU.GCLK_NUM.B.GCLK_NUM != Numerator )
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
    if(GTM4.GLS[0].CMU.CLK_EN.R != 0u)
    {
    	Ret = (Std_ReturnType)E_NOT_OK;
    }

    GTM4.GLS[0].CMU.GCLK_DEN.B.GCLK_DEN = Denominator;
    
	if(GTM4.GLS[0].CMU.GCLK_DEN.B.GCLK_DEN != Denominator)
	{
		Ret = (Std_ReturnType)E_NOT_OK;
	}
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
    if((GTM4.GLS[0].CMU.CLK_EN.R & 0xFFFFU) != 0u)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    switch(Clock)
    {
        case GPT_GTM_CMU_CLK0:
        {
            GTM4.GLS[0].CMU.CLK[0].CTRL.B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK1:
        {
            GTM4.GLS[0].CMU.CLK[1].CTRL.B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK2:
        {
            GTM4.GLS[0].CMU.CLK[2].CTRL.B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK3:
        {
            GTM4.GLS[0].CMU.CLK[3].CTRL.B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK4:
        {
            GTM4.GLS[0].CMU.CLK[4].CTRL.B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK5:
        {
            GTM4.GLS[0].CMU.CLK[5].CTRL.B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK6:
        {
            GTM4.GLS[0].CMU.CLK_6.B.CLK_CNT = Count;
            break;
        }
        case GPT_GTM_CMU_CLK7:
        {
            GTM4.GLS[0].CMU.CLK_7.B.CLK_CNT = Count;
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
    if(GTM4.GLS[0].CMU.CLK_EN.B.EN_FXCLK != 0u)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    GTM4.GLS[0].CMU.FXCLK.CTRL.B.FXCLK_SEL = (uint8_t)FXCLKSource;
    if(GTM4.GLS[0].CMU.FXCLK.CTRL.B.FXCLK_SEL != (uint8_t)FXCLKSource)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    
    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif
