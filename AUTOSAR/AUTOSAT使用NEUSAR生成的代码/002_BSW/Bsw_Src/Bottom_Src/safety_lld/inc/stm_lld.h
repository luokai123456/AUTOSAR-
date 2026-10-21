/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     stm_lld.h
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
/*PRQA S 1534,3472,1535,3630 EOF*/
#ifndef _STM_LLD_H_
#define _STM_LLD_H_
#include "derivative.h"
#include "gpio_lld.h"
//#include "mcu_lld.h"
#define STM_REG_READBACK                         (0U)
typedef  struct STM_tag                          STM_tag_Type;

#define STM_0_BASE_ADDR                          ((uint32_t)&STM_0)
#define STM_1_BASE_ADDR                          ((uint32_t)&STM_1)
#define STM_2_BASE_ADDR                          ((uint32_t)&STM_2)
#define STM_0_BASE                               ((STM_tag_Type *)STM_0_BASE_ADDR)
#define STM_1_BASE                               ((STM_tag_Type *)STM_1_BASE_ADDR)
#define STM_2_BASE                               ((STM_tag_Type *)STM_2_BASE_ADDR)
#define STM_BASE_ARRAY                           {STM_0_BASE, STM_1_BASE, STM_2_BASE}

#define STM_DET_ERR(x)                          DEV_ASSERT(x)

#define STM_INSTANCE_NUM                         3U

#define STM0_CH_NUM                              4U
#define STM1_CH_NUM                              4U
#define STM2_CH_NUM                              4U

#define STM_CR_CPS_MASK                          0xff00u
#define STM_CR_CPS_SHIFT                         8u
#define STM_CR_CPS_WIDTH                         8u
#define STM_CR_CPS(x)                            (((uint32_t)(((uint32_t)(x)) << STM_CR_CPS_SHIFT))&STM_CR_CPS_MASK)

typedef void (*STM_Callback_Type)(void);

typedef enum{
    STM0 = 0,
    STM1,
    STM2
}STM_ModuleID_Type;

typedef enum{
    STM_Channel0 = 0,
    STM_Channel1,
    STM_Channel2,
    STM_Channel3
}STM_ChannelID_Type;

typedef enum{
    STM_FREEZEOFF = 0,
    STM_FREEZEON
}STM_DebugMode_Type;

typedef enum{
    STM_Disable = 0,
    STM_Enable
}STM_Status_Type;

typedef struct {
    STM_Status_Type          STM_ChannelEnable;
    STM_ChannelID_Type       STM_ChannelID;
    uint32_t                 STM_CompareValue;
    STM_Callback_Type        STM_Callback;
} STM_Channel_Config_Type;

typedef struct {
    STM_ModuleID_Type        STM_ModuleID;
    STM_DebugMode_Type       STM_DebugMode;
    uint8_t                  STM_Prescaler;
} STM_Module_Config_Type;

status_t STM_LLD_Init (STM_Module_Config_Type const *cfgptr);
status_t STM_LLD_Deinit(STM_ModuleID_Type STM_ModuleID);
status_t STM_LLD_ChannelConfig(STM_ModuleID_Type STM_ModuleID, STM_Channel_Config_Type const *cfgptr);
status_t STM_LLD_ClearInterruptFlag(STM_ModuleID_Type STM_ModuleID, STM_ChannelID_Type STM_ChannelID);
status_t STM_LLD_ModuleDisable (STM_ModuleID_Type STM_ModuleID);
status_t STM_LLD_ModuleEnable (STM_ModuleID_Type STM_ModuleID);
status_t STM_LLD_ChannelEnable(STM_ModuleID_Type STM_ModuleID, STM_ChannelID_Type STM_ChannelID);
status_t STM_LLD_ChannelDisable (STM_ModuleID_Type STM_ModuleID, STM_ChannelID_Type STM_ChannelID);
status_t STM_LLD_SetCounter(STM_ModuleID_Type STM_ModuleID , uint32_t value);
uint32_t STM_LLD_GetCounter(STM_ModuleID_Type STM_ModuleID);
status_t STM_LLD_SetDebugFreeze(STM_ModuleID_Type STM_ModuleID, STM_DebugMode_Type STM_DebugMode);
uint8_t STM_LLD_GetDebugFreeze(STM_ModuleID_Type STM_ModuleID);
uint32_t STM_LLD_GetInterruptFlag(STM_ModuleID_Type STM_ModuleID, STM_ChannelID_Type STM_ChannelID);
status_t STM_LLD_SetCompareValue(STM_ModuleID_Type STM_ModuleID, STM_ChannelID_Type STM_ChannelID, uint32_t CompareValue);
uint32_t STM_LLD_GetCompareValue(STM_ModuleID_Type STM_ModuleID, STM_ChannelID_Type STM_ChannelID);
status_t STM_LLD_SetPrescaler(STM_ModuleID_Type STM_ModuleID, uint32_t ClockDivision);
uint32_t STM_LLD_GetPrescaler(STM_ModuleID_Type STM_ModuleID);
status_t STM_LLD_DelayInit(STM_ModuleID_Type STM_ModuleID);
void STM_LLD_DelayMs(STM_ModuleID_Type STM_ModuleID, uint32_t ms);
void STM_LLD_DelayUs(STM_ModuleID_Type STM_ModuleID, uint32_t us);
void STM0_CH0_Handler(void);
void STM0_CH1_Handler(void);
void STM0_CH2_Handler(void);
void STM0_CH3_Handler(void);
void STM1_CH0_Handler(void);
void STM1_CH1_Handler(void);
void STM1_CH2_Handler(void);
void STM1_CH3_Handler(void);
void STM2_CH0_Handler(void);
void STM2_CH1_Handler(void);
void STM2_CH2_Handler(void);
void STM2_CH3_Handler(void);
#endif /* LLD_INC_STM_LLD_H_ */
