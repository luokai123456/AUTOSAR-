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
*   @file    Gpt_Irq.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Gpt MCAL driver.
*
*   @addtogroup Gpt
*   @{
*/
/* PRQA S 0380,3432,1752 EOF */

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Gpt_Irq.h"
#include "Gpt_Stm_LLDriver.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined(RESOURCE_SUPPORT_GTM410))
#include "Gpt_Gtm_LLDriver.h"
#endif
#include "Gpt_Pit_LLDriver.h"
#include "Gpt_AutoSar_Wrapper.h"

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


/*=================================================CONSTANTS========================================*/

/*===========================================VARIABLE DECLARATIONS==================================*/

#if (defined(RESOURCE_SUPPORT_GTM104))
extern P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC,GPT_APPL_DATA) g_GPT_GTM_TOM_Base[5U];
#endif
/*============================================DEFINES AND MACROS====================================*/

/*===================================================ENUMS==========================================*/

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

/*===============================================LOCAL FUNCTIONS====================================*/

/*==============================================GLOBAL FUNCTIONS====================================*/

/*======================================STM IRQ============================*/
#ifdef RESOURCE_SUPPORT_STM0
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM0_CH0_Handler)
{
   Gpt_Stm_IRQHandler(STM0, STM_Channel0);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM0_CH1_Handler)
{
   Gpt_Stm_IRQHandler(STM0, STM_Channel1);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM0_CH2_Handler)
{
   Gpt_Stm_IRQHandler(STM0, STM_Channel2);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM0_CH3_Handler)
{
   Gpt_Stm_IRQHandler(STM0, STM_Channel3);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#ifdef RESOURCE_SUPPORT_STM1
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM1_CH0_Handler)
{
   Gpt_Stm_IRQHandler(STM1, STM_Channel0);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM1_CH1_Handler)
{
   Gpt_Stm_IRQHandler(STM1, STM_Channel1);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM1_CH2_Handler)
{
   Gpt_Stm_IRQHandler(STM1, STM_Channel2);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM1_CH3_Handler)
{
   Gpt_Stm_IRQHandler(STM1, STM_Channel3);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif


#ifdef RESOURCE_SUPPORT_STM2
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM2_CH0_Handler)
{
   Gpt_Stm_IRQHandler(STM2, STM_Channel0);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM2_CH1_Handler)
{
   Gpt_Stm_IRQHandler(STM2, STM_Channel1);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM2_CH2_Handler)
{
   Gpt_Stm_IRQHandler(STM2, STM_Channel2);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM2_CH3_Handler)
{
   Gpt_Stm_IRQHandler(STM2, STM_Channel3);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#ifdef RESOURCE_SUPPORT_STM3
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM3_CH0_Handler)
{
   Gpt_Stm_IRQHandler(STM3, STM_Channel0);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM3_CH1_Handler)
{
   Gpt_Stm_IRQHandler(STM3, STM_Channel1);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM3_CH2_Handler)
{
   Gpt_Stm_IRQHandler(STM3, STM_Channel2);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM3_CH3_Handler)
{
   Gpt_Stm_IRQHandler(STM3, STM_Channel3);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#ifdef RESOURCE_SUPPORT_STM4
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM4_CH0_Handler)
{
   Gpt_Stm_IRQHandler(STM4, STM_Channel0);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM4_CH1_Handler)
{
   Gpt_Stm_IRQHandler(STM4, STM_Channel1);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM4_CH2_Handler)
{
   Gpt_Stm_IRQHandler(STM4, STM_Channel2);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM4_CH3_Handler)
{
   Gpt_Stm_IRQHandler(STM4, STM_Channel3);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#ifdef RESOURCE_SUPPORT_STM5
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM5_CH0_Handler)
{
   Gpt_Stm_IRQHandler(STM5, STM_Channel0);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM5_CH1_Handler)
{
   Gpt_Stm_IRQHandler(STM5, STM_Channel1);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM5_CH2_Handler)
{
   Gpt_Stm_IRQHandler(STM5, STM_Channel2);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(STM5_CH3_Handler)
{
   Gpt_Stm_IRQHandler(STM5, STM_Channel3);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif
/*======================================PIT IRQ============================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT0_CH0_ISR)
{
   Gpt_Pit_IRQHandler(PIT0, PIT_Channel0);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT0_CH1_ISR)
{
   Gpt_Pit_IRQHandler(PIT0, PIT_Channel1);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT0_CH2_ISR)
{
   Gpt_Pit_IRQHandler(PIT0, PIT_Channel2);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT0_CH3_ISR)
{
   Gpt_Pit_IRQHandler(PIT0, PIT_Channel3);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT0_CH4_ISR)
{
   Gpt_Pit_IRQHandler(PIT0, PIT_Channel4);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT0_CH5_ISR)
{
   Gpt_Pit_IRQHandler(PIT0, PIT_Channel5);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT0_CH6_ISR)
{
   Gpt_Pit_IRQHandler(PIT0, PIT_Channel6);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT0_CH7_ISR)
{
   Gpt_Pit_IRQHandler(PIT0, PIT_Channel7);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT1_CH0_ISR)
{
   Gpt_Pit_IRQHandler(PIT1, PIT_Channel0);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(PIT1_CH1_ISR)
{
   Gpt_Pit_IRQHandler(PIT1, PIT_Channel1);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(RTI_ISR)
{
   Gpt_Pit_IRQHandler(PIT0, PIT_RTI);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

/*======================================TOM IRQ============================*/
#if (defined(RESOURCE_SUPPORT_GTM104) )
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH0_CH1_ISR)
{
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH0_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if((uint8)(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH0_IRQ_NOTIFY.R) == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH0);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH1_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH1_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH2_CH3_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH2_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH2_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH2);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH3_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH3_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH4_CH5_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH4_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH4_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH4);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH5_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH5_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH6_CH7_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH6_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH6_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH6);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH7_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH7_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH8_CH9_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH8_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH8_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH8);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH9_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH9_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH10_CH11_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH10_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH10_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH10);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH11_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH11_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH12_CH13_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH12_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH12_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH12);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH13_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH13_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH14_CH15_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH14_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH14_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH14);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH15_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM0]->CH15_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

/* GPT GTM TOM1 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH0_CH1_ISR)
{
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH0_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH0_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH0);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH1_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH1_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH2_CH3_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH2_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH2_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH2);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH3_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH3_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH4_CH5_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH4_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH4_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH4);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH5_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH5_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH6_CH7_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH6_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH6_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH6);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH7_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH7_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH8_CH9_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH8_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH8_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH8);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH9_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH9_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH10_CH11_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH10_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH10_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH10);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH11_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH11_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH12_CH13_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH12_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH12_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH12);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH13_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH13_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH14_CH15_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH14_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH14_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH14);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH15_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM1]->CH15_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

/* GPT GTM TOM2 */

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH0_CH1_ISR)
{
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH0_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH0_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH0);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH1_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH1_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH2_CH3_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH2_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH2_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH2);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH3_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH3_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH4_CH5_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH4_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH4_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH4);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH5_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH5_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH6_CH7_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH6_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH6_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH6);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH7_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH7_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH8_CH9_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH8_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH8_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH8);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH9_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH9_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH10_CH11_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH10_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH10_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH10);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH11_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH11_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH12_CH13_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH12_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH12_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH12);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH13_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH13_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH14_CH15_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH14_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH14_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH14);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH15_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM2]->CH15_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
/* GPT GTM TOM3 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH0_CH1_ISR)
{
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH0_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH0_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH0);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH1_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH1_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH2_CH3_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH2_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH2_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH2);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH3_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH3_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH4_CH5_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH4_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH4_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH4);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH5_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH5_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH6_CH7_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH6_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH6_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH6);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH7_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH7_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH8_CH9_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH8_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH8_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH8);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH9_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH9_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH10_CH11_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH10_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH10_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH10);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH11_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH11_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH12_CH13_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH12_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH12_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH12);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH13_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH13_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH14_CH15_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH14_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH14_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH14);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH15_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM3]->CH15_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
/* GPT_GTM_TOM4 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH0_CH1_ISR)
{
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH0_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH0_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH0);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH1_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH1_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH2_CH3_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH2_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH2_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH2);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH3_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH3_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH4_CH5_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH4_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH4_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH4);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH5_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH5_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH6_CH7_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH6_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH6_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH6);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH7_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH7_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH8_CH9_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH8_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH8_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH8);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH9_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH9_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH10_CH11_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH10_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH10_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH10);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH11_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH11_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH12_CH13_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH12_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH12_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH12);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH13_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH13_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH14_CH15_ISR)
{
    if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH14_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH14_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH14);
		}
	}
	if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH15_IRQ_EN.R != 0u) /* polyspace RTE:NIV */
	{
		if(g_GPT_GTM_TOM_Base[GPT_GTM_TOM4]->CH15_IRQ_NOTIFY.R == 1u) /* polyspace RTE:NIV */
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#if ( defined(RESOURCE_SUPPORT_GTM410))
#ifdef RESOURCE_SUPPORT_GTM_TOM0
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH0_CH1_ISR)
{
	if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH0].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH0].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH0);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH1].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH1].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH2_CH3_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH2].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH2].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH2);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH3].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH3].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH4_CH5_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH4].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH4].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH4);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH5].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH5].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH6_CH7_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH6].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH6].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH6);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH7].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH7].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH8_CH9_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH8].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH8].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH8);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH9].IRQ_EN.R  != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH9].IRQ_NOTIFY.R  == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH10_CH11_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH10].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH10].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH10);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH11].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH11].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH12_CH13_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH12].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH12].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH12);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH13].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH13].IRQ_NOTIFY.R  == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM0_CH14_CH15_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH14].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH14].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH14);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH15].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM0].TOM.CH[GPT_GTM_TOM_CH15].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM0, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#ifdef RESOURCE_SUPPORT_GTM_TOM1
/* GPT GTM TOM1 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH0_CH1_ISR)
{
	if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH0].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH0].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH0);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH1].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH1].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH2_CH3_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH2].IRQ_EN.R!= 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH2].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH2);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH3].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH3].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH4_CH5_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH4].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH4].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH4);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH5].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH5].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH6_CH7_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH6].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH6].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH6);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH7].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH7].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH8_CH9_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH8].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH8].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH8);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH9].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH9].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH10_CH11_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH10].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH10].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH10);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH11].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH11].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH12_CH13_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH12].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH12].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH12);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH13].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH13].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM1_CH14_CH15_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH14].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH14].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH14);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH15].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM1].TOM.CH[GPT_GTM_TOM_CH15].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM1, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif
/* GPT GTM TOM2 */

#ifdef RESOURCE_SUPPORT_GTM_TOM2
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH0_CH1_ISR)
{
	if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH0].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH0].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH0);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH1].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH1].IRQ_NOTIFY.R== 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH2_CH3_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH2].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH2].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH2);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH3].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH3].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH4_CH5_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH4].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH4].IRQ_NOTIFY.R== 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH4);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH5].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH5].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH6_CH7_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH6].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH6].IRQ_NOTIFY.R== 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH6);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH7].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH7].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH8_CH9_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH8].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH8].IRQ_NOTIFY.R== 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH8);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH9].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH9].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH10_CH11_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH10].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH10].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH10);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH11].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH11].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH12_CH13_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH12].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH12].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH12);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH13].IRQ_EN.R!= 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH13].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM2_CH14_CH15_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH14].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH14].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH14);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH15].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM2].TOM.CH[GPT_GTM_TOM_CH15].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM2, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#ifdef RESOURCE_SUPPORT_GTM_TOM3
/* GPT GTM TOM3 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH0_CH1_ISR)
{
	if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH0].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH0].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH0);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH1].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH1].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH2_CH3_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH2].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH2].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH2);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH3].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH3].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH4_CH5_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH4].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH4].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH4);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH5].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH5].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH6_CH7_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH6].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH6].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH6);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH7].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH7].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH8_CH9_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH8].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH8].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH8);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH9].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH9].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH10_CH11_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH10].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH10].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH10);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH11].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH11].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH12_CH13_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH12].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH12].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH12);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH13].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH13].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM3_CH14_CH15_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH14].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH14].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH14);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH15].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM3].TOM.CH[GPT_GTM_TOM_CH15].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM3, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#ifdef RESOURCE_SUPPORT_GTM_TOM4
/* GPT_GTM_TOM4 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH0_CH1_ISR)
{
	if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH0].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH0].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH0);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH1].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH1].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH2_CH3_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH2].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH2].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH2);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH3].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH3].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH4_CH5_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH4].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH4].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH4);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH5].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH5].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH6_CH7_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH6].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH6].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH6);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH7].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH7].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH8_CH9_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH8].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH8].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH8);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH9].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH9].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH10_CH11_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH10].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH10].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH10);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH11].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH11].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH12_CH13_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH12].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH12].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH12);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH13].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH13].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM4_CH14_CH15_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH14].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH14].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH14);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH15].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM4].TOM.CH[GPT_GTM_TOM_CH15].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM4, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#ifdef RESOURCE_SUPPORT_GTM_TOM5
/* GPT_GTM_TOM5 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM5_CH0_CH1_ISR)
{
	if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH0].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH0].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH0);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH1].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH1].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH1);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM5_CH2_CH3_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH2].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH2].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH2);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH3].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH3].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH3);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM5_CH4_CH5_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH4].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH4].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH4);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH5].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH5].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH5);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM5_CH6_CH7_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH6].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH6].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH6);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH7].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH7].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH7);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM5_CH8_CH9_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH8].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH8].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH8);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH9].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH9].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH9);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM5_CH10_CH11_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH10].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH10].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH10);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH11].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH11].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH11);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM5_CH12_CH13_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH12].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH12].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH12);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH13].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH13].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH13);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
ISR(TOM5_CH14_CH15_ISR)
{
    if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH14].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH14].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH14);
		}
	}
	if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH15].IRQ_EN.R != 0u)
	{
		if(GTM4.GLS[GPT_GTM_TOM5].TOM.CH[GPT_GTM_TOM_CH15].IRQ_NOTIFY.R == 1u)
		{
			GPT_TOM_LLD_IRQHandler(GPT_GTM_TOM5, GPT_GTM_TOM_CH15);
		}
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif
#endif

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void,GPT_CODE) Gpt_Stm_Callback_From_IRQ(VAR(Gpt_ChannelType, AUTOMATIC) Gpt_Channel)
{
    /* Process callback */
    Gpt_ProcessCommonIrq(Gpt_Channel);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_Callback_From_IRQ(VAR(Gpt_ChannelType, AUTOMATIC) Gpt_Channel)
{
    /* Process callback */
    Gpt_ProcessCommonIrq(Gpt_Channel);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#if (defined(RESOURCE_SUPPORT_GTM104) || defined(RESOURCE_SUPPORT_GTM410))
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

FUNC(void,GPT_CODE) Gpt_Gtm_Callback_From_IRQ(VAR(Gpt_ChannelType, AUTOMATIC) Gpt_Channel)
{
    /* Process callback */
    Gpt_ProcessCommonIrq(Gpt_Channel);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif
#ifdef RESOURCE_SUPPORT_RTC_API
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void,GPT_CODE) Gpt_Rtc_Callback_From_IRQ(VAR(Gpt_ChannelType, AUTOMATIC) Gpt_Channel)
{
	/* Process callback */
	Gpt_ProcessCommonIrq(Gpt_Channel);

}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 
#endif

#ifdef __cplusplus
}
#endif
