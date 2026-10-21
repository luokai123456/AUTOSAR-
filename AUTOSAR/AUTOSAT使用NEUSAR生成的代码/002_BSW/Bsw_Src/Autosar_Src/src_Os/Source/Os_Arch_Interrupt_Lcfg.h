/*
********************************************************************************
*
*  File name: Os_Arch_Interrupt_Lcfg.h
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
#ifndef OS_ARCH_INTERRUPT_LCFG_H_
#define OS_ARCH_INTERRUPT_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
extern FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core0(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core0(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_37_STM0_CH1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core2(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core2(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core3(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core3(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core4(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core4(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_450_MCAN11_CH1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_449_MCAN11_CH0(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_699_MCAN6_CH1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_698_MCAN6_CH0(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_689_MCAN1_CH1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_688_MCAN1_CH0(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_446_MCAN9_CH1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_445_MCAN9_CH0(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_693_MCAN3_CH1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_692_MCAN3_CH0(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_691_MCAN2_CH1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_690_MCAN2_CH0(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_701_MCAN7_CH1(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_700_MCAN7_CH0(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_698_LINTX_CH6(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_Os_ISR_698_LINRX_CH6(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_CounterIsr_SystemTimer_Core5(void);
extern FUNC(void, OS_CODE) Os_Arch_Irq_MultiCommIsr_Core5(void);
#endif /* OS_ARCH_INTERRUPT_LCFG_H_ */


