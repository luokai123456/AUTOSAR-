/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     Gpt_Pit_LLDriver.h
* @version  3.0.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/

#ifndef GPT_PIT_LLDRIVER_H
#define GPT_PIT_LLDRIVER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
/*PRQA S 1534,1535,3472 EOF*/
#include "derivative.h"
#include "Std_Types.h"
#include "Gpt_Cfg.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define GPT_VENDOR_ID_H                     176
#define GPT_MODULE_ID_H                     100
#define GPT_AR_RELEASE_MAJOR_VERSION        4
#define GPT_AR_RELEASE_MINOR_VERSION        4
#define GPT_AR_PATCH_VER_H                  0
#define GPT_SW_MAJOR_VER_H                  3
#define GPT_SW_MINOR_VER_H                  0
#define GPT_SW_PATCH_VER_H                  0

/*============================================FILE VERSION CHECKS===================================*/

#if (GPT_VENDOR_ID_H != GPT_VENDOR_ID)
#error "NON-MATCHED DATA : GPT_CFG_VENDOR_ID"
#endif

#if (GPT_AR_RELEASE_MAJOR_VERSION != GPT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER"
#endif
#if (GPT_AR_RELEASE_MINOR_VERSION != GPT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER"
#endif
#if (GPT_AR_PATCH_VER_H != GPT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER"
#endif

#if (GPT_SW_MAJOR_VER_H != GPT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER"
#endif
#if (GPT_SW_MINOR_VER_H != GPT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER"
#endif
#if (GPT_SW_PATCH_VER_H != GPT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER"
#endif

/*=================================================Constants========================================*/

/*============================================DEFINES AND MACROS====================================*/
#define PIT_0_BASE_ADDR                         ((uint32)&PIT_0)
#define PIT_1_BASE_ADDR                         ((uint32)&PIT_1)
#define PIT_0_BASE                              ((PIT_tag_Type *)PIT_0_BASE_ADDR)
#define PIT_1_BASE                              ((PIT_tag_Type *)PIT_1_BASE_ADDR)
#define PIT_BASE_ARRAY                          {PIT_0_BASE, PIT_1_BASE}

#define PIT_INSTANCE_NUM                        (2U)

#define PIT0_CH_NUM                             (9U)
#define PIT1_CH_NUM                             (2U)

#define GPT_PIT_MODULE_MAX                      (2U)
#define GPT_PIT_MODULE_CHANNEL_MAX              (9U)

#define PIT_CHANNEL_DISABLE 	0u
#define PIT_CHANNEL_ENABLE		1u

#define PIT_MODLE_DISABLE		0u
#define PIT_MODLE_ENABLE		1u


#define PIT_MOD_SHIFT               ((uint8)4U)
#define PIT_CH_MASK_U8              ((uint8)0x0FU)

#define PIT_MODULE_INDEX_U32(ch)    (((ch) >> PIT_MOD_SHIFT) & 0xFU)
#define PIT_CHANNEL_INDEX_U32(ch)   ((ch) & PIT_CH_MASK_U8)

/*===================================================ENUMS==========================================*/
typedef enum
{
    PIT0 = 0x0U,
    PIT1 = 0x1U
}PIT_Module_t;

typedef enum
{
    PIT_Channel0 = 0x0U,
    PIT_Channel1 = 0x1U,
    PIT_Channel2 = 0x2U,
    PIT_Channel3 = 0x3U,
    PIT_Channel4 = 0x4U,
    PIT_Channel5 = 0x5U,
    PIT_Channel6 = 0x6U,
    PIT_Channel7 = 0x7U,
    PIT_RTI = 0x8U
}PIT_Channel_t;
typedef enum
{
    FREEZEOFF = 0x0U,
    FREEZEON = 0x1U,
}PIT_DebugMode_Type;

typedef enum
{
    PIT_Status_Disable = 0x0U,
    PIT_Status_Enable = 0x1U
}PIT_Status_Type;

typedef enum
{
    RTI_Status_Disable = 0x0U,
    RTI_Status_Enable = 0x1U
}RTI_Status_Type;

typedef enum
{
    PIT_Period_Count = 0x0U,
    PIT_Period_US = 0x1U,
    PIT_Period_MS = 0x2U
}PIT_Value_Type;

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

typedef struct PIT_tag PIT_tag_Type;

typedef struct {
    VAR(uint32, GPT_VAR) u32PerClkFreq;
    VAR(uint32, GPT_VAR) u32RtiClkFreq;
}PIT_ClkFreq;
/*==============================================GLOBAL FUNCTIONS====================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(PIT_Channel_t, GPT_CODE) Gpt_Pit_LLD_ConvertChannelId(VAR(uint8, AUTOMATIC) Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(PIT_Module_t, GPT_CODE) Gpt_Pit_LLD_ConvertModuleId(VAR(uint8, AUTOMATIC) Module);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_IRQHandler(                \
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,     \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID    \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_ModuleEnable(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) Gpt_Rti_LLD_ModuleEnable(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_Deinit 		    \
( 													\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID 	\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_SetDebugFreeze     \
(                                                   \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
   VAR(PIT_DebugMode_Type, AUTOMATIC) PIT_DebugMode \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_ChannelEnable 		 \
( 													 \
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_ChannelDisable 	 \
( 													 \
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);
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
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Pit_LLD_GetLoadValue \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID, 	\
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,\
    VAR(PIT_Value_Type, AUTOMATIC) PIT_Value 	\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint8, GPT_CODE) Gpt_Pit_LLD_GetDebugFreeze \
( 												 \
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID 	 \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_ClearIntFlag   \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Pit_LLD_GetIntFlag 	\
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_SetChIntState 	\
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID, 	\
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,\
    VAR(PIT_Status_Type, AUTOMATIC) eGpt_Pit_InterruptState \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_LLD_SetChChainMode \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,\
    VAR(PIT_Status_Type, AUTOMATIC) eGpt_Stm_Chainmode \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Pit_LLD_GetCurrentValue \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID, 	\
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) Gpt_Rti_LLD_ModuleDisable \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID 	\
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#ifdef __cplusplus
}
#endif

#endif /* PIT_H_ */
