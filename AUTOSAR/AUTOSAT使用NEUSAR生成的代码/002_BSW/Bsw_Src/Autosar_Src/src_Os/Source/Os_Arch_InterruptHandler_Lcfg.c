/*
********************************************************************************
*
*  File name: Os_Arch_InterruptHandler_Lcfg.c
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: MiaoLH/2025.1.20
* Change: New create.
* Cause: New
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Arch_Kernal_Lcfg.h"
#include "Os_Arch_Interrupt_Lcfg.h"
#include "Os_Platform_Lcfg.h"
#include "Os_Arch_Context_Types.h"
#include "Os_Arch_Types.h"
#include "Os_Lcfg.h"
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_Arch_Exception.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define OS_START_SEC_CODE 
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core0(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_CounterIsr_SystemTimer_Core0); }
FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core0(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_MultiCommIsr_Core0); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_37_STM0_CH1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_37_STM0_CH1); }
FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_CounterIsr_SystemTimer_Core1); }
FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_MultiCommIsr_Core1); }
FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core2(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_CounterIsr_SystemTimer_Core2); }
FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core2(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_MultiCommIsr_Core2); }
FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core3(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_CounterIsr_SystemTimer_Core3); }
FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core3(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_MultiCommIsr_Core3); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM6_6_W_OCP_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM6_6_W_OCP_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM3_4_DC_OverFault2_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM3_4_DC_OverFault2_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM3_3_DC_OverFault1_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM3_3_DC_OverFault1_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM3_2_U_OCP_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM3_2_U_OCP_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM6_5_W_HsFault_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM6_5_W_HsFault_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM6_4_W_LsFault_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM6_4_W_LsFault_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM6_3_V_HsFault_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM6_3_V_HsFault_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM6_2_V_LsFault_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM6_2_V_LsFault_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM6_1_U_HsFault_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM6_1_U_HsFault_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM6_0_V_OCP_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM6_0_V_OCP_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM4_0_U_LsFault_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM4_0_U_LsFault_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_ATOM0_6_FOC_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(ATOM0_6_FOC_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_TIM4_7_OCPOV_Trigger_IRQHandler(void) { Os_Arch_Cat1InterruptAsm(TIM4_7_OCPOV_Trigger_IRQHandler); }
FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core4(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_CounterIsr_SystemTimer_Core4); }
FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core4(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_MultiCommIsr_Core4); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_450_MCAN11_CH1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_450_MCAN11_CH1); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_449_MCAN11_CH0(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_449_MCAN11_CH0); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_699_MCAN6_CH1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_699_MCAN6_CH1); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_698_MCAN6_CH0(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_698_MCAN6_CH0); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_689_MCAN1_CH1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_689_MCAN1_CH1); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_688_MCAN1_CH0(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_688_MCAN1_CH0); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_446_MCAN9_CH1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_446_MCAN9_CH1); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_445_MCAN9_CH0(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_445_MCAN9_CH0); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_693_MCAN3_CH1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_693_MCAN3_CH1); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_692_MCAN3_CH0(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_692_MCAN3_CH0); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_691_MCAN2_CH1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_691_MCAN2_CH1); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_690_MCAN2_CH0(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_690_MCAN2_CH0); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_701_MCAN7_CH1(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_701_MCAN7_CH1); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_700_MCAN7_CH0(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_700_MCAN7_CH0); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_698_LINTX_CH6(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_698_LINTX_CH6); }
FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_698_LINRX_CH6(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_Os_ISR_698_LINRX_CH6); }
FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core5(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_CounterIsr_SystemTimer_Core5); }
FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core5(void) { Os_Arch_Cat2InterruptAsm(OsCfg_Isr_MultiCommIsr_Core5); }
FUNC(void, OS_CODE) Os_Arch_Irq_SDADC6_DMA_Complete_Handler(void) { Os_Arch_Cat1InterruptAsm(SDADC6_DMA_Complete_Handler); }
#define OS_STOP_SEC_CODE 
#include "Os_MemMap.h"

/*
********************************************************************************
*    Global Variable
********************************************************************************
*/

