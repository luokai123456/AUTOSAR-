/*
********************************************************************************
*
*  File name: Os_Arch_Mach_Timer.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: JiangGL/2025.6.25
* Change: New create.
* Cause: New
********************************************************************************
*/
#ifndef OS_ARCH_MACH_TIMER_H_
#define OS_ARCH_MACH_TIMER_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Os_Arch_Mach.h"
#include "Os_Arch_Lcfg.h"
#include "Os_Arch_Core.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* PIT disable mask. */
#define PIT_DISABLE_MASK                (0x00000000U)
/* PIT ebable mark. */
#define PIT_ENABLE_MARK                 (0x00000004U)
/* PIT interrupt flag clear mark. */
#define PIT_INTC_CLEAR_MARK             (0x00000001U)
/* PIT channel enable mark. */
#define PIT_CHANNEL_ENABLE_MARK         (0x00000003U)
/* STM enable mark. */
#define STM_CR_ENABLE_MARK              (0x00000001U)
/* STM interrupt flag clear mark. */
#define STM_INTC_CLEAR_MARK             (0x00000001U)
/* STM channel enable mark. */
#define STM_CHANNEL_ENABLE_MARK         (0x00000001U)
/* Hrt init value. */
#define OS_HAL_HRT_INIT_VALUE           (0xFFFFFFFFU)

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
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if( OS_HRT_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Arch_Mach_HrtTimerGetValue
*
* Explanation: Get high precision timer value.
*
* Param: hrtCfg: High precision timer configuraton.
*
* Retval: Timer value.
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_TickType, OS_CODE) Os_Arch_Mach_HrtTimerGetValue
(
    P2CONST(Os_Arch_Mach_TimerHrtCfgType, AUTOMATIC, OS_APPL_CONST) hrtCfg
)
{
    /* Get the current Value. */
    return *(volatile uint32*)(hrtCfg->TimerHrtBaseAddress + OS_HAL_STM_CNT_OFFSET);
}

/*
********************************************************************************
* Function Name: Os_Arch_Mach_HrtTimerInit
*
* Explanation: High precision timer initializaiion.
*
* Param: hrtCfg: High precision timer configuraton.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Mach_HrtTimerInit
(
    P2CONST(Os_Arch_Mach_TimerHrtCfgType, AUTOMATIC, OS_APPL_CONST) hrtCfg
)
{
    /* Set the Compare Value. */
    *(volatile uint32*)(hrtCfg->TimerHrtBaseAddress +
        OS_HAL_STM_CMP_OFFSET(hrtCfg->TimerHrtChannel)) = OS_HAL_HRT_INIT_VALUE;
}

/*
********************************************************************************
* Function Name: Os_Arch_Mach_HrtTimerStart
*
* Explanation: High precision timer satrt.
*
* Param: hrtCfg: High precision timer configuraton.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Mach_HrtTimerStart
(
    P2CONST(Os_Arch_Mach_TimerHrtCfgType, AUTOMATIC, OS_APPL_CONST) hrtCfg
)
{
    /* Clear the current channel match flag. */
    *(volatile uint32*)(hrtCfg->TimerHrtBaseAddress +
        OS_HAL_STM_CIR_OFFSET(hrtCfg->TimerHrtChannel)) = STM_INTC_CLEAR_MARK;
    /* Start Timer Counter. */
    *(volatile uint32*)(hrtCfg->TimerHrtBaseAddress +
        OS_HAL_STM_CCR_OFFSET(hrtCfg->TimerHrtChannel)) = STM_CHANNEL_ENABLE_MARK;
    /* Enable STM Timer. */
    *(volatile uint32*)(hrtCfg->TimerHrtBaseAddress +
        OS_HAL_STM_CR_OFFSET) |= STM_CR_ENABLE_MARK;
}

/*
********************************************************************************
* Function Name: Os_Arch_Mach_HrtTimerSetCompareValue
*
* Explanation: High precision timer set compare.
*
* Param: hrtCfg: High precision timer configuraton.
*        value: value to set.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Mach_HrtTimerSetCompareValue
(
    P2CONST(Os_Arch_Mach_TimerHrtCfgType, AUTOMATIC, OS_APPL_CONST) hrtCfg,
    Os_TickType value
)
{
    /* Set the Compare Value. */
    *(volatile uint32*)(hrtCfg->TimerHrtBaseAddress +
        OS_HAL_STM_CMP_OFFSET(hrtCfg->TimerHrtChannel)) = value;
}

/*
********************************************************************************
* Function Name: Os_Arch_Mach_HrtTimerGetCompareValue
*
* Explanation: High precision timer get compare Value.
*
* Param: hrtCfg: High precision timer configuraton.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(Os_TickType, OS_CODE) Os_Arch_Mach_HrtTimerGetCompareValue
(
    P2CONST(Os_Arch_Mach_TimerHrtCfgType, AUTOMATIC, OS_APPL_CONST) hrtCfg
)
{
    /* Get the Compare Value. */
    return *(volatile uint32*)(hrtCfg->TimerHrtBaseAddress +
        OS_HAL_STM_CMP_OFFSET(hrtCfg->TimerHrtChannel));
}

/*
********************************************************************************
* Function Name: Os_Arch_Mach_HrtClearInterrupt
*
* Explanation: High precision timer clear interrupt.
*
* Param: hrtCfg: High precision timer configuraton.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Mach_HrtClearInterrupt
(
    P2CONST(Os_Arch_Mach_TimerHrtCfgType, AUTOMATIC, OS_APPL_CONST) hrtCfg
)
{
    /* Clear the interrupt flag. */
    *(volatile uint32*)(hrtCfg->TimerHrtBaseAddress +
        OS_HAL_STM_CIR_OFFSET(hrtCfg->TimerHrtChannel)) = STM_INTC_CLEAR_MARK;
}

#ifdef OS_SUPPORT_HARDWARE_TRIGGER_INTERRUPT
/*
********************************************************************************
* Function Name: Os_Arch_Hrt_TrigerIrq
*
* Explanation: Manually trigger HRT interrupt.
*
* Param: hrtCfg: High precision timer configuraton.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Hrt_TrigerIrq
(
    P2CONST(Os_Arch_Mach_TimerHrtCfgType, AUTOMATIC, OS_APPL_CONST) hrtCfg
)
{
    uint32 coreId;
    Os_IntNumType isrSourceNum = hrtCfg->source->number;

    /* Get Core id. */
    coreId = Os_Arch_GetCoreId();
    if( OS_HAL_INTC_SOFT_INTERRUPTS_NUM > isrSourceNum )
    {
        /* Trigger the softirq. */
        *(volatile uint8*)(OS_HAL_INTC_BASE_ADDRESS(coreId) + OS_HAL_INTC_SSCIR(isrSourceNum)) =
            OS_HAL_INTC_SSCIR_TRIGGER_MSK;
    }
    else
    {
        /* Trigger the peripheral irq. */
        *(volatile uint16*)(OS_HAL_INTC_BASE_ADDRESS(coreId) + OS_HAL_INTC_PSR_OFFSET(isrSourceNum))
            |= OS_HAL_INTC_PSR_TRIGGER_MSK;
    }
}
#endif /* OS_SUPPORT_HARDWARE_TRIGGER_INTERRUPT */

#endif /* ( OS_HRT_ENABLE == STD_ON ) */

#if( OS_PIT_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Os_Arch_Mach_PitTimerInit
*
* Explanation: Periodic interrupt timer initializaiion.
*
* Param: pitCfg: Periodic interrupt timer configuraton.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Mach_PitTimerInit
(
    P2CONST(Os_Arch_Mach_TimerPitCfgType, AUTOMATIC, OS_APPL_CONST) pitCfg
)
{
    /* Periodic interrupt timer initializaiion. */
    /* Disable pit channel , disable pit channel interrupt. */
    *(volatile uint32*)(pitCfg->TimerPitBaseAdress +
        OS_HAL_PIT_TCTRL_OFFSET(pitCfg->TimerPitChannel)) = PIT_DISABLE_MASK;
    /* Clear the pit channel match flag. */
    *(volatile uint32*)(pitCfg->TimerPitBaseAdress +
        OS_HAL_PIT_TFLG_OFFSET(pitCfg->TimerPitChannel)) = PIT_INTC_CLEAR_MARK;
    /* Reload the pit value. */
    *(volatile uint32*)(pitCfg->TimerPitBaseAdress +
        OS_HAL_PIT_LDVAL_OFFSET(pitCfg->TimerPitChannel)) = pitCfg->ReloadValue;
    /* Enable pit timer. */
    *(volatile uint32*)(pitCfg->TimerPitBaseAdress +
        OS_HAL_PIT_MCR_OFFSET) = PIT_ENABLE_MARK;
}

/*
********************************************************************************
* Function Name: Os_Arch_Mach_PitTimerStart
*
* Explanation: Periodic interrupt timer start.
*
* Param: pitCfg: Periodic interrupt timer configuraton.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Mach_PitTimerStart
(
    P2CONST(Os_Arch_Mach_TimerPitCfgType, AUTOMATIC, OS_APPL_CONST) pitCfg
)
{
    /* Start Timer Counter,enable interrput. */
     *(volatile uint32*)(pitCfg->TimerPitBaseAdress +
        OS_HAL_PIT_TCTRL_OFFSET(pitCfg->TimerPitChannel)) = PIT_CHANNEL_ENABLE_MARK;
}

/*
********************************************************************************
* Function Name: Os_Arch_Mach_PitClearInterrupt
*
* Explanation: Periodic interrupt timer clear interrupt.
*
* Param: pitCfg: Periodic interrupt timer configuraton.
*
* Retval: None
********************************************************************************
*/
LOCAL_INLINE FUNC(void, OS_CODE) Os_Arch_Mach_PitClearInterrupt
(
    P2CONST(Os_Arch_Mach_TimerPitCfgType, AUTOMATIC, OS_APPL_CONST) pitCfg
)
{
    /* Clear the current channel match flag. */
    *(volatile uint32*)(pitCfg->TimerPitBaseAdress +
        OS_HAL_PIT_TFLG_OFFSET(pitCfg->TimerPitChannel)) = PIT_INTC_CLEAR_MARK;
}
#endif

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* OS_ARCH_MACH_TIMER_H_ */
