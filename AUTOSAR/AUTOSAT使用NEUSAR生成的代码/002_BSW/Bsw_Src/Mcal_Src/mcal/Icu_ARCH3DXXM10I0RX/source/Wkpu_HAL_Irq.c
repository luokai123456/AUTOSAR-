/* PRQA S 3432, 0380, 2053 EOF */
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu.h"
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))
#include "Icu_Wkpu_LLDrivers.h"
#include "Wkpu_HAL_Irq.h"



/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_WKPU_HAL_IRQ_VENDOR_ID_C                   176

#define ICU_WKPU_HAL_IRQ_MAJOR_VER_C                   4
#define ICU_WKPU_HAL_IRQ_MINOR_VER_C                   4
#define ICU_WKPU_HAL_IRQ_REVISION_VER_C                0

#define ICU_WKPU_HAL_IRQ_SW_MAJOR_VER_C                3
#define ICU_WKPU_HAL_IRQ_SW_MINOR_VER_C                0
#define ICU_WKPU_HAL_IRQ_SW_PATCH_VER_C                0

#if (ICU_WKPU_HAL_IRQ_VENDOR_ID_C != ICU_WKPU_HAL_IRQ_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_WKPU_HAL_IRQ_MAJOR_VER_C != ICU_WKPU_HAL_IRQ_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_WKPU_HAL_IRQ_MINOR_VER_C != ICU_WKPU_HAL_IRQ_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_WKPU_HAL_IRQ_REVISION_VER_C != ICU_WKPU_HAL_IRQ_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_WKPU_HAL_IRQ_SW_MAJOR_VER_C != ICU_WKPU_HAL_IRQ_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_WKPU_HAL_IRQ_SW_MINOR_VER_C != ICU_WKPU_HAL_IRQ_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_WKPU_HAL_IRQ_SW_PATCH_VER_C != ICU_WKPU_HAL_IRQ_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(WKPU_IRQ0_Handler)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    uint8 channelId = 0U;
    uint32 u32ChannelMask = 0U;
    uint32 u32reg_WKPU_WISR = (uint32)base->WISR0.R;/* polyspace RTE:NIV */
    uint32 u32reg_WKPU_WIER = (uint32)base->IRER0.R;/* polyspace RTE:NIV */

    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for(channelId = 0U; channelId < 8U; channelId++)
    {
        u32ChannelMask = (1UL << (uint32)channelId);
        if((u32reg_WKPU_WISR & u32ChannelMask) != 0U)
        {
            base->WISR0.R = u32ChannelMask;
            Icu_Wkpu_LLD_IrqCallbcak(0U,channelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(WKPU_IRQ1_Handler)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    uint8 channelId = 0U;
    uint32 u32ChannelMask = 0U;
    uint32 u32reg_WKPU_WISR = (uint32)base->WISR0.R;/* polyspace RTE:NIV */
    uint32 u32reg_WKPU_WIER = (uint32)base->IRER0.R;/* polyspace RTE:NIV */

    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for(channelId = 8U; channelId < 16U; channelId++)
    {
        u32ChannelMask = (1UL << (uint32)channelId);
        if((u32reg_WKPU_WISR & u32ChannelMask) != 0U)
        {
            base->WISR0.R = u32ChannelMask;
            Icu_Wkpu_LLD_IrqCallbcak(0U,channelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(WKPU_IRQ2_Handler)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    uint8 channelId = 0U;
    uint32 u32ChannelMask = 0U;
    uint32 u32reg_WKPU_WISR = (uint32)base->WISR0.R;/* polyspace RTE:NIV */
    uint32 u32reg_WKPU_WIER = (uint32)base->IRER0.R;/* polyspace RTE:NIV */

    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for(channelId = 16U; channelId < 24U; channelId++)
    {
        u32ChannelMask = (1UL << (uint32)channelId);
        if((u32reg_WKPU_WISR & u32ChannelMask) != 0U)
        {
            base->WISR0.R = u32ChannelMask;
            Icu_Wkpu_LLD_IrqCallbcak(0U,channelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(WKPU_IRQ3_Handler)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    uint8 channelId = 0U;
    uint32 u32ChannelMask = 0U;
    uint32 u32reg_WKPU_WISR = (uint32)base->WISR0.R;/* polyspace RTE:NIV */
    uint32 u32reg_WKPU_WIER = (uint32)base->IRER0.R;/* polyspace RTE:NIV */

    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for(channelId = 24U; channelId < 32U; channelId++)
    {
        u32ChannelMask = (1UL << (uint32)channelId);
        if((u32reg_WKPU_WISR & u32ChannelMask) != 0U)
        {
            base->WISR0.R = u32ChannelMask;
            Icu_Wkpu_LLD_IrqCallbcak(0U,channelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(WKPU_IRQ4_Handler)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    uint8 channelId = 0U;
    uint32 u32ChannelMask = 0U;
    uint32 u32reg_WKPU_WISR = (uint32)base->WISR1.R;/* polyspace RTE:NIV */
    uint32 u32reg_WKPU_WIER = (uint32)base->IRER1.R;/* polyspace RTE:NIV */

    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for(channelId = 0U; channelId < 8U; channelId++)
    {
        u32ChannelMask = (1UL << (uint32)channelId);
        if((u32reg_WKPU_WISR & u32ChannelMask) != 0U)
        {
            base->WISR1.R = u32ChannelMask;
            Icu_Wkpu_LLD_IrqCallbcak(0U,channelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(WKPU_IRQ5_Handler)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    uint8 channelId = 0U;
    uint32 u32ChannelMask = 0U;
    uint32 u32reg_WKPU_WISR = (uint32)base->WISR1.R;/* polyspace RTE:NIV */
    uint32 u32reg_WKPU_WIER = (uint32)base->IRER1.R;/* polyspace RTE:NIV */

    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for(channelId = 8U; channelId < 16U; channelId++)
    {
        u32ChannelMask = (1UL << (uint32)channelId);
        if((u32reg_WKPU_WISR & u32ChannelMask) != 0U)
        {
            base->WISR1.R = u32ChannelMask;
            Icu_Wkpu_LLD_IrqCallbcak(0U,channelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(WKPU_IRQ6_Handler)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    uint8 channelId = 0U;
    uint32 u32ChannelMask = 0U;
    uint32 u32reg_WKPU_WISR = (uint32)base->WISR1.R;/* polyspace RTE:NIV */
    uint32 u32reg_WKPU_WIER = (uint32)base->IRER1.R;/* polyspace RTE:NIV */

    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for(channelId = 16U; channelId < 24U; channelId++)
    {
        u32ChannelMask = (1UL << (uint32)channelId);
        if((u32reg_WKPU_WISR & u32ChannelMask) != 0U)
        {
            base->WISR1.R = u32ChannelMask;
            Icu_Wkpu_LLD_IrqCallbcak(0U,channelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
ISR(WKPU_IRQ7_Handler)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    uint8 channelId = 0U;
    uint32 u32ChannelMask = 0U;
    uint32 u32reg_WKPU_WISR = (uint32)base->WISR1.R;/* polyspace RTE:NIV */
    uint32 u32reg_WKPU_WIER = (uint32)base->IRER1.R;/* polyspace RTE:NIV */

    u32reg_WKPU_WISR &= u32reg_WKPU_WIER;

    for(channelId = 24U; channelId < 32U; channelId++)
    {
        u32ChannelMask = (1UL << (uint32)channelId);
        if((u32reg_WKPU_WISR & u32ChannelMask) != 0U)
        {
            base->WISR1.R = u32ChannelMask;
            Icu_Wkpu_LLD_IrqCallbcak(0U,channelId);
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
#ifdef __cplusplus
}
#endif

