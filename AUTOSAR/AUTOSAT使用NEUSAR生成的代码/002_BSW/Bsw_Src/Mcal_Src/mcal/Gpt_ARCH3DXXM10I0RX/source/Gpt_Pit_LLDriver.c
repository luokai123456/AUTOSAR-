/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     Gpt_Pit_LLDriver.c
* @version  3.0.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 0380,3432,2844 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Gpt_Pit_LLDriver.h"
#include "Gpt_Irq.h"
#include "Gpt_AutoSar_Wrapper.h"
#include "Gpt_Pit_HAL_Wrapper.h"
#include "SchM_Gpt.h"
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

extern P2CONST(Gpt_ConfigType, GPT_VAR,  GPT_APPL_CONST)  sGpt_pConfig[GPT_MAX_PARTITION];
/*PIT Base Address*/

#define GPT_START_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
static CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) g_PITBase[PIT_INSTANCE_NUM] =  \
                                                                   PIT_BASE_ARRAY;
#define GPT_STOP_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"


#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(PIT_Module_t, GPT_CODE) Gpt_Pit_LLD_ConvertModuleId(VAR(uint8, AUTOMATIC) Module)
{

	VAR(PIT_Module_t, AUTOMATIC) eModuleId;

    switch(Module)
    {
        case 0u:
            eModuleId = PIT0;
        break;
        case 1u:
            eModuleId = PIT1;
        break;
        default:
            eModuleId = PIT0;
        break;
    }
    return eModuleId;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(PIT_Channel_t, GPT_CODE) Gpt_Pit_LLD_ConvertChannelId(VAR(uint8, AUTOMATIC) Channel)
{
	VAR(PIT_Channel_t, AUTOMATIC)eChannelId;
	switch(Channel)
	{
	case 0u:
		eChannelId = PIT_Channel0;
		break;
	case 1u:
		eChannelId = PIT_Channel1;
		break;
	case 2u:
		eChannelId = PIT_Channel2;
		break;
	case 3u:
		eChannelId = PIT_Channel3;
		break;
	case 4u:
		eChannelId = PIT_Channel4;
		break;
	case 5u:
		eChannelId = PIT_Channel5;
		break;
	case 6u:
		eChannelId = PIT_Channel6;
		break;
	case 7u:
		eChannelId = PIT_Channel7;
		break;
	case 8u:
		eChannelId = PIT_RTI;
		break;
	default:
		eChannelId = PIT_Channel0;
		break;
	}
	return eChannelId;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

/*
   [SWS_Gpt_00327]
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_ClearIntFlag       \
(                                                   \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
)
{
	/*Check Module ID*/
	DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
	/*Check Channel ID*/
	if (PIT0 == PIT_ModuleID)
	{
		DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT0_CH_NUM);
	}
	else
	{
		DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT1_CH_NUM);
	}
	/*Get base address of instance*/
	CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];

	/*Clear RTI channel interrupt flag*/
	if (PIT_ChannelID == PIT_RTI)
	{
        base->RTI_TFLG.R = TRUE;
	}
	/*Clear PIT channel interrupt flag*/
	else
	{
		base->TIMER[PIT_ChannelID].TFLG.R = TRUE;
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_ModuleEnable(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID)
{
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    /*Get base address of instance*/
    CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[PIT_ModuleID];

    /*Enable PIT module clock*/
    base->MCR.B.MDIS = 0U;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) Gpt_Pit_LLD_ModuleDisable(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID)
{
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    /*Get base address of instance*/
    CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[PIT_ModuleID];

    /*Disable PIT module clock*/
    base->MCR.B.MDIS = (uint8)PIT_Status_Enable;

}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_ChannelEnable      \
(                                                   \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
)
{
   /*Check Module ID*/
   DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
   /*Check Channel ID*/
   if (PIT0 == PIT_ModuleID)
   {
       DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT0_CH_NUM);
   }
   else
   {
       DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT1_CH_NUM);
   }
   /*Get base address of instance*/
   CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];

    if (PIT_ChannelID == PIT_RTI)
    {
        /*Enable RTI channel timer*/
        base->RTI_TCTRL.B.TEN = (uint8)PIT_Status_Enable;
    }
    else
    {
        /*Enable PIT channel timer*/
        base->TIMER[PIT_ChannelID].TCTRL.B.TEN = (uint8)PIT_Status_Enable;
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_ChannelDisable     \
(                                                   \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
)
{
   /*Check Module ID*/
   DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
   /*Check Channel ID*/
   if (PIT0 == PIT_ModuleID)
   {
       DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT0_CH_NUM);
   }
   else
   {
       DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT1_CH_NUM);
   }

   /*Get base address of instance*/
   CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];

    if (PIT_ChannelID == PIT_RTI)
    {
        /*Disable RTI channel timer*/
        base->RTI_TCTRL.B.TEN = (uint8)PIT_Status_Disable;
    }
    else
    {
        /*Disable PIT channel timer*/
        base->TIMER[PIT_ChannelID].TCTRL.B.TEN = (uint8)PIT_Status_Disable;
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_SetDebugFreeze  \
(                                                       \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,      \
   VAR(PIT_DebugMode_Type, AUTOMATIC) PIT_DebugMode     \
)
{
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    /*Get base address of instance*/
    CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[PIT_ModuleID];

    /*Set module freeze mode*/
    base->MCR.B.FRZ = (uint8)PIT_DebugMode;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint8, GPT_CODE) Gpt_Pit_LLD_GetDebugFreeze(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID)
{
   /*Check Module ID*/
   DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
   /*Get base address of instance*/
   P2CONST(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[PIT_ModuleID];
   /*Return module freeze mode*/
   return (uint8)(base->MCR.B.FRZ);/* polyspace RTE:NIV */
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Pit_LLD_GetIntFlag       \
(                                                   \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
)
{
   /*Check Module ID*/
   DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
   /*Check Channel ID*/
   if (PIT0 == PIT_ModuleID)
   {
       DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT0_CH_NUM);
   }
   else
   {
       DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT1_CH_NUM);
   }
   /*Get base address of instance*/
   P2CONST(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];
   VAR(uint32, AUTOMATIC) IntFlag;
   /*Get RTI channel interrupt flag*/
   if (PIT_ChannelID == PIT_RTI)
   {
       IntFlag = (uint32)(base->RTI_TFLG.B.TIF);
   }
   /*Get PIT channel interrupt flag*/
   else
   {
       IntFlag = (uint32)(base->TIMER[PIT_ChannelID].TFLG.B.TIF);/* polyspace RTE:NIV */
   }

   return IntFlag;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_SetChIntState             \
(                                                          \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,         \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,       \
   VAR(PIT_Status_Type, AUTOMATIC) eGpt_Pit_InterruptState \
)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    /*Check Channel ID*/
    if (PIT0 == PIT_ModuleID)
    {
        DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT0_CH_NUM);
    }
    else
    {
        DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT1_CH_NUM);
    }

    /*Get base address of instance*/
    CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];

    if (PIT_ChannelID == PIT_RTI)
    {
        /*Set RTI channel interrupt mode*/
        base->RTI_TCTRL.B.TIE = (uint8)eGpt_Pit_InterruptState;
    }
    else
    {
        /*Set PIT channel interrupt mode*/
        base->TIMER[PIT_ChannelID].TCTRL.B.TIE = (uint8)eGpt_Pit_InterruptState;
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_SetChChainMode       \
(                                                     \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,    \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,  \
   VAR(PIT_Status_Type, AUTOMATIC) eGpt_Stm_Chainmode \
)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    /*Check Channel ID*/
    if (PIT0 == PIT_ModuleID)
    {
        DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT0_CH_NUM);
    }
    else
    {
        DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT1_CH_NUM);
    }
	/*Get base address of instance*/
	CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];

    /*Set PIT channel chain mode*/
    if(PIT_ChannelID < PIT_RTI)
    {
        base->TIMER[PIT_ChannelID].TCTRL.B.CHN = (uint8)eGpt_Stm_Chainmode;/* polyspace RTE:IDP */
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Pit_LLD_GetCurrentValue  \
(                                                   \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
)
{
   /*Check Module ID*/
   DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
   /*Check Channel ID*/
   if (PIT0 == PIT_ModuleID)
   {
       DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT0_CH_NUM);
   }
   else
   {
       DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT1_CH_NUM);
   }
   /*Get base address of instance*/
   P2CONST(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];
   VAR(uint32, AUTOMATIC) CurrentValue;
   /*Get RTI channel current time*/
   if (PIT_ChannelID == PIT_RTI)
   {
       CurrentValue = (uint32)(base->RTI_CVAL.R);/* polyspace RTE:NIV */
   }
   /*Get PIT channel current time*/
   else
   {
       CurrentValue = (uint32)(base->TIMER[PIT_ChannelID].CVAL.R);/* polyspace RTE:NIV */
   }

   return CurrentValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) Gpt_Rti_LLD_ModuleEnable(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    /*Get base address of instance*/
    PIT_tag_Type * const base = g_PITBase[(uint8)PIT_ModuleID];
    Std_ReturnType status = E_OK;

    if (PIT_ModuleID == PIT0)
    {
        base->MCR.B.MDIS_RTI = (uint8)PIT_Status_Disable;
    }
    else
    {
        status = (Std_ReturnType)E_NOT_OK;
    }

    return status;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) Gpt_Rti_LLD_ModuleDisable(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    /*Get base address of instance*/
    CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];
    VAR(Std_ReturnType, AUTOMATIC) status = E_OK;

    if (PIT_ModuleID == PIT0)
    {
        /*Disable RTI module clock*/
        base->MCR.B.MDIS_RTI = 1U;
    }
    else
    {
        status = (Std_ReturnType)E_NOT_OK;
    }

   return status;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) Gpt_Pit_LLD_SetLoadValue \
(                                                  \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,      \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,    \
   VAR(uint32, AUTOMATIC) u32Pit_Value,            \
   VAR(PIT_Value_Type, AUTOMATIC) PIT_Value        \
)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    /*Check Channel ID*/
    if (PIT0 == PIT_ModuleID)
    {
        DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT0_CH_NUM);
    }
    else
    {
        DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT1_CH_NUM);
    }

    /*Get base address of instance*/
    CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];
    VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) per_freq, rti_freq;
    VAR(uint32, AUTOMATIC) calculated_time = 0U;

    if (PIT_ChannelID == PIT_RTI)
    {
        /*Get current RTI clock*/
        rti_freq = PitClkFreq.u32RtiClkFreq;
        /*Calculate value based on value type*/
        switch (PIT_Value)
        {
            case PIT_Period_Count:
            {
                calculated_time = u32Pit_Value;
                break;
            }
            case PIT_Period_US:
            {
                calculated_time = ((u32Pit_Value) * (rti_freq / 1000000U));
                break;
            }
            case PIT_Period_MS:
            {
                calculated_time = ((u32Pit_Value) * (rti_freq / 1000U));
                break;
            }
            default:
            {
                DEV_ASSERT(FALSE);
                break;
            }
        }
        /*value at least 1*/
        if (0u == calculated_time)
        {
            calculated_time = 1u;
        }
        /*Set load value, timer end at zero*/
        base->RTI_LDVAL.R = calculated_time - 1u;
        
        if (base->RTI_LDVAL.R != (calculated_time - 1u))
        {
            ret = (Std_ReturnType)E_NOT_OK;
        }

    }
    else
    {
        /*Get current PER clock*/
        per_freq = PitClkFreq.u32PerClkFreq;
        /*Calculate value based on value type*/
        switch (PIT_Value)
        {
            case PIT_Period_Count:
            {
                calculated_time = u32Pit_Value;
                break;
            }
            case PIT_Period_US:
            {
                calculated_time = ((u32Pit_Value) * (per_freq / 1000000U));
                break;
            }
            case PIT_Period_MS:
            {
                calculated_time = ((u32Pit_Value) * (per_freq / 1000U));
                break;
            }
            default:
            {
                DEV_ASSERT(FALSE);
                break;
            }
        }
        if (0u == calculated_time)
        {
            calculated_time = 1u;
        }

        /*Set load value, timer end at zero*/
        base->TIMER[PIT_ChannelID].LDVAL.R = calculated_time - 1u;

        if (base->TIMER[PIT_ChannelID].LDVAL.R != (calculated_time - 1u))
        {
            ret = (Std_ReturnType)E_NOT_OK;
        }
    }

   return ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Pit_LLD_GetLoadValue     \
(                                                   \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,\
   VAR(PIT_Value_Type, AUTOMATIC) PIT_Value         \
)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    /*Check Channel ID*/
    if (PIT0 == PIT_ModuleID)
    {
        DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT0_CH_NUM);
    }
    else
    {
        DEV_ASSERT((uint8)PIT_ChannelID < (uint8)PIT1_CH_NUM);
    }
    /*Get base address of instance*/
    P2CONST(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];

    VAR(uint32, AUTOMATIC) per_freq, rti_freq;
    VAR(uint32, AUTOMATIC) required_time;
    VAR(uint32, AUTOMATIC) return_time = 0U;

    if (PIT_ChannelID == PIT_RTI)
    {
        /*Get current RTI clock*/
        rti_freq = PitClkFreq.u32RtiClkFreq;
        /*Get RTI channel load value*/
        required_time = base->RTI_LDVAL.R;
        /*Calculate value based on value type, timer end at zero*/
        switch (PIT_Value)
        {
            case PIT_Period_Count:
            {
                return_time = required_time + 1u;
                break;
            }
            case PIT_Period_US:
            {
                return_time = ((required_time + 1u) * (rti_freq / 1000000U)); /* PRQA S 2834 */
                break;
            }
            case PIT_Period_MS:
            {
                return_time = ((required_time + 1u) * (rti_freq / 1000U)); /* PRQA S 2834 */
                break;
            }
            default:
            {
                DEV_ASSERT(FALSE);
                break;
            }
        }
    }
    else
    {
        /*Get current PER clock*/
        per_freq = PitClkFreq.u32PerClkFreq;
        /*Get PIT channel load value*/
        required_time = base->TIMER[PIT_ChannelID].LDVAL.R;/* polyspace RTE:NIV */
        /*Calculate value based on value type, timer end at zero*/
        switch (PIT_Value)
        {
            case PIT_Period_Count:
            {
                return_time = required_time + 1u;
                break;
            }
            case PIT_Period_US:
            {
                return_time = ((required_time + 1u) / (per_freq / 1000000U)); /* PRQA S 2834 */
                break;
            }
            case PIT_Period_MS:
            {
                return_time = ((required_time + 1u) / (per_freq / 1000U)); /* PRQA S 2834 */
                break;
            }
            default:
            {
                DEV_ASSERT(FALSE);
                break;
            }
        }
    }

    return return_time;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_Deinit(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8)PIT_ModuleID < (uint8)PIT_INSTANCE_NUM);
    VAR(uint8, AUTOMATIC) loopvalue;
    VAR(PIT_Channel_t, AUTOMATIC) eChannelID;
    VAR(uint8, AUTOMATIC) cnt;

    if (PIT_ModuleID == PIT0)
    {
        /*Disable PIT moduel clock*/
        Gpt_Pit_LLD_ModuleDisable(PIT_ModuleID);
        /*Disable freeze mode*/
        Gpt_Pit_LLD_SetDebugFreeze(PIT_ModuleID, FREEZEOFF);
        /*Disable RTI moduel clock*/
        (void)Gpt_Rti_LLD_ModuleDisable(PIT_ModuleID);
        /*Clear load u32Pit_Value register*/
        (void)Gpt_Pit_LLD_SetLoadValue(PIT0, PIT_RTI, 1U, PIT_Period_Count);
        /*Disable RTI channel*/
        Gpt_Pit_LLD_ChannelDisable(PIT0, PIT_RTI);
        /*Disable RTI channel interrupt*/
        Gpt_Pit_LLD_SetChIntState(PIT0, PIT_RTI, PIT_Status_Disable);
        /*Clear RTI channel interrupt flag*/
        (void)Gpt_Pit_LLD_ClearIntFlag(PIT0, PIT_RTI);
        loopvalue = PIT0_CH_NUM - 1U;   /* without PIT RTI */
    }
    else
    {
        /*Disable PIT moduel clock*/
        (void)Gpt_Pit_LLD_ModuleDisable(PIT_ModuleID);
        /*Disable freeze mode*/
        (void)Gpt_Pit_LLD_SetDebugFreeze(PIT_ModuleID, FREEZEOFF);
        loopvalue = PIT1_CH_NUM;
    }

    for (cnt = 0u; cnt < loopvalue; cnt++)
    {
    	eChannelID = Gpt_Pit_LLD_ConvertChannelId(cnt);
        /*Clear RTI channel interrupt flag*/
        Gpt_Pit_LLD_ClearIntFlag(PIT_ModuleID, eChannelID);/*PRQA S 4442*/
        /*Clear load u32Pit_Value register*/
        (void)Gpt_Pit_LLD_SetLoadValue(PIT_ModuleID, eChannelID, 1U, PIT_Period_Count);/*PRQA S 4442*/
        /*Disable PIT channel*/
        Gpt_Pit_LLD_ChannelDisable(PIT_ModuleID, eChannelID);/*PRQA S 4442*/
        if (PIT0 == PIT_ModuleID)
        {
            /*Disable PIT channel chain mode*/
            Gpt_Pit_LLD_SetChChainMode(PIT_ModuleID, eChannelID, PIT_Status_Disable);/*PRQA S 4442*/
        }
        /*Disable PIT channel interrupt*/
        Gpt_Pit_LLD_SetChIntState(PIT_ModuleID, eChannelID, PIT_Status_Disable);/*PRQA S 4442*/
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_IRQHandler        \
(                                              \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
)
{
    VAR(uint8, AUTOMATIC) u8Channel = 0;
    VAR(uint8, AUTOMATIC) u8Instance = 0;
    VAR(uint32, AUTOMATIC) Pit_CoreIndex = Gpt_GetCoreID();
    CONSTP2VAR(PIT_tag_Type, AUTOMATIC, GPT_APPL_CONST) base = g_PITBase[(uint8)PIT_ModuleID];

    u8Instance = (uint8)(((uint8)PIT_ModuleID * GPT_PIT_MODULE_CHANNEL_MAX) + (uint8)PIT_ChannelID + GPT_PIT_MODULE_INDEX);
    u8Channel = sGpt_pConfig[Pit_CoreIndex]->Gpt_aHw2LogicChannelMap[u8Instance]; /* polyspace RTE:IDP */

    /*Clear channel interrupt flag*/
	if (PIT_ChannelID == PIT_RTI)
	{
        base->RTI_TFLG.R = TRUE;
	}
	else
	{
		base->TIMER[PIT_ChannelID].TFLG.R = TRUE;
	}

    if (GPT_CH_MODE_ONESHOT == (*(sGpt_pConfig[Pit_CoreIndex]->pChannelConfig))[u8Channel].eChannelMode) /* polyspace RTE:IDP,OBAI */
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_10();

        /* Disable PIT channel */
         if (PIT_ChannelID == PIT_RTI)
         {
             base->RTI_TCTRL.B.TEN = (uint8)PIT_Status_Disable;
         }
         else
         {
             base->TIMER[PIT_ChannelID].TCTRL.B.TEN = (uint8)PIT_Status_Disable;
         }

        SchM_Exit_Gpt_EXCLUSIVE_AREA_10();
    }

#if (GPT_ENABLE_MULTICORE == STD_ON)

    VAR(uint32, AUTOMATIC) CoreId = 1 << Gpt_GetCoreID();
    P2VAR(Gpt_Wrapper_ChannelInfo, AUTOMATIC, GPT_APPL_DATA) pChannelInfo = NULL_PTR;

    pChannelInfo = Gpt_AutoSar_Wrapper_GetChannelInfo(u8Channel);

    VAR(uint8, AUTOMATCI) Temp = CoreId & pChannelInfo->pGpt_CoreId[u8Channel];
    if(Temp != (uint8)0u)
#endif
    {
            Gpt_ProcessCommonIrq(u8Channel);
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 


#ifdef __cplusplus
}
#endif
