/*PRQA S 0380, 0491, 2877,1861,4542,1853 EOF*/
#include "Sent_Irq.h"
#include "Sent_LLDriver.h"
#include "Sent.h"

#ifdef RESOURCE_SUPPORT_SENT

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define SENT_VENDOR_ID_C                 176
#define SENT_AR_MAJOR_VER_C              4
#define SENT_AR_MINOR_VER_C              4
#define SENT_AR_PATCH_VER_C              0
#define SENT_SW_MAJOR_VER_C              3
#define SENT_SW_MINOR_VER_C              0
#define SENT_SW_PATCH_VER_C              0

/*============================================FILE VERSION CHECKS===================================*/

/* Check if current file and SENT header file are of the same vendor */
#if (SENT_VENDOR_ID_C != SENT_VENDOR_ID)
#error "NON-MATCHED DATA : SENT_VENDOR_ID"
#endif

/* Check if current file and SENT header file are of the same Autosar version */
#if (SENT_AR_MAJOR_VER_C != SENT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER"
#endif
#if (SENT_AR_MINOR_VER_C != SENT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER"
#endif
#if (SENT_AR_PATCH_VER_C != SENT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER"
#endif

/* Check if current file and SENT header file are of the same Software version */
#if (SENT_SW_MAJOR_VER_C != SENT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER"
#endif
#if (SENT_SW_MINOR_VER_C != SENT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER"
#endif
#if (SENT_SW_PATCH_VER_C != SENT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER"
#endif


/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_IRQ_Dispatch
 * Description   : Interrupt dispatcher
 *
 *END**************************************************************************/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
SENT_INLINE FUNC(void, SENT_CODE) SRX_LLD_IRQ_Dispatch(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    /* Dispatch according to event type */
    if (SRX_LLD_GetFastRxStatus(instance, channel) == TRUE)
    {
        SRX_LLD_IRQ_FastHandler(instance, channel);
    }
    else if(SRX_LLD_GetSlowRxStatus(instance, channel) == TRUE)
    {
        SRX_LLD_IRQ_SlowHandler(instance, channel);
    }
    else
    {
        /* do nothing */
    }
    if (SRX_LLD_GetErrorStatus(instance, channel) == TRUE)
    {
        /* Fall through, error */
        SRX_LLD_IRQ_RxErrHandler(instance, channel);
    }
    else
    {
        /* do nothing */
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_IRQ_COMBINED_FAST_Dispatch
 * Description   : Interrupt dispatcher
 *
 *END**************************************************************************/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
__attribute__((unused)) SENT_INLINE FUNC(void, SENT_CODE) SRX_LLD_IRQ_COMBINED_FAST_Dispatch(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    /* Dispatch according to event type */
    if (SRX_LLD_GetFastRxStatus(instance, channel) == TRUE)
    {
        SRX_LLD_IRQ_FastHandler(instance, channel);
    }
    else
    {
        /* do nothing */
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_IRQ_COMBINED_FAST_Dispatch
 * Description   : Interrupt dispatcher
 *
 *END**************************************************************************/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
__attribute__((unused)) SENT_INLINE FUNC(void, SENT_CODE) SRX_LLD_IRQ_COMBINED_SLOW_Dispatch(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    /* Dispatch according to event type */
    if(SRX_LLD_GetSlowRxStatus(instance, channel) == TRUE)
    {
        SRX_LLD_IRQ_SlowHandler(instance, channel);
    }
    else
    {
        /* do nothing */
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_IRQ_COMBINED_FAST_Dispatch
 * Description   : Interrupt dispatcher
 *
 *END**************************************************************************/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
__attribute__((unused)) SENT_INLINE FUNC(void, SENT_CODE) SRX_LLD_IRQ_COMBINED_ERR_Dispatch(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    if (SRX_LLD_GetErrorStatus(instance, channel) == TRUE)
    {
        /* Fall through, error */
        SRX_LLD_IRQ_RxErrHandler(instance, channel);
    }
    else
    {
        /* do nothing */
    } 
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX0_CH0_IRQHandler
 * Description   : Handler for SRX0_CH0_IRQn interrupt
 *
 *END**************************************************************************/
#ifdef FEATURE_SRX_HAS_COMBINED_IRQ
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_COMBINED_FAST_IRQHandler(void)
{
    uint8 u8Sent_Index, u8Sent_Flg;
    for(u8Sent_Index = 0u; u8Sent_Index < SRX0_CHANNEL_COUNT; u8Sent_Index++)
    {
        for (u8Sent_Flg = 0; u8Sent_Flg < SENT_CHANNEL_NUM; u8Sent_Flg++)
        {
            if ((SentChannelConfigSet.pChanCfgPtr[u8Sent_Flg].u8ChannelId & (0x1F)) == u8Sent_Index)
            {
                SRX_LLD_IRQ_COMBINED_FAST_Dispatch(0u, u8Sent_Index);
                break;
            }
        }
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_COMBINED_SLOW_IRQHandler(void)
{
    uint8 u8Sent_Index, u8Sent_Flg;
    for(u8Sent_Index = 0u; u8Sent_Index < SRX0_CHANNEL_COUNT; u8Sent_Index++)
    {
        for (u8Sent_Flg = 0; u8Sent_Flg < SENT_CHANNEL_NUM; u8Sent_Flg++)
        {
            if ((SentChannelConfigSet.pChanCfgPtr[u8Sent_Flg].u8ChannelId & (0x1F)) == u8Sent_Index)
            {
                SRX_LLD_IRQ_COMBINED_SLOW_Dispatch(0u, u8Sent_Index);
                break;
            }
        }
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_COMBINED_ERR_IRQHandler(void)
{
    uint8 u8Sent_Index, u8Sent_Flg;
    for(u8Sent_Index = 0u; u8Sent_Index < SRX0_CHANNEL_COUNT; u8Sent_Index++)
    {
        for (u8Sent_Flg = 0; u8Sent_Flg < SENT_CHANNEL_NUM; u8Sent_Flg++)
        {
            if ((SentChannelConfigSet.pChanCfgPtr[u8Sent_Flg].u8ChannelId & (0x1F))== u8Sent_Index)
            {
                SRX_LLD_IRQ_COMBINED_ERR_Dispatch(0u, u8Sent_Index);
                break;
            }
        }
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif /* FEATURE_SRX_HAS_COMBINED_IRQ */

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_CH0_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 0u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#if (SRX_CHANNEL_COUNT > 1u)
/*FUNCTION**********************************************************************
 *
 * Function Name : SRX0_CH1_IRQHandler
 * Description   : Handler for SRX0_CH1_IRQn interrupt
 *
 *END**************************************************************************/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_CH1_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 1u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_CH2_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 2u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_CH3_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 3u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_CH4_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 4u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_CH5_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 5u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_CH6_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 6u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX0_CH7_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 7u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX1_CH0_IRQHandler
 * Description   : Handler for SRX1_CH0_IRQn interrupt
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX1_CH0_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 0u);
}

#if (SRX_CHANNEL_COUNT > 1u)
/*FUNCTION**********************************************************************
 *
 * Function Name : SRX1_CH1_IRQHandler
 * Description   : Handler for SRX1_CH1_IRQn interrupt
 *
 *END**************************************************************************/
#ifdef FEATURE_SRX_HAS_COMBINED_IRQ
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX1_COMBINED_FAST_IRQHandler(void)
{
    uint8 u8Sent_Index, u8Sent_Flg;
    for(u8Sent_Index = 0u; u8Sent_Index < SRX1_CHANNEL_COUNT; u8Sent_Index++)
    {
        for (u8Sent_Flg = 0; u8Sent_Flg < SENT_CHANNEL_NUM; u8Sent_Flg++)
        {
            if ((SentChannelConfigSet.pChanCfgPtr[u8Sent_Flg].u8ChannelId & (0x1F))== u8Sent_Index)
            {
                SRX_LLD_IRQ_COMBINED_FAST_Dispatch(1u, u8Sent_Index);
                break;
            }
        }
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX1_COMBINED_SLOW_IRQHandler(void)
{
    uint8 u8Sent_Index, u8Sent_Flg;
    for(u8Sent_Index = 0u; u8Sent_Index < SRX1_CHANNEL_COUNT; u8Sent_Index++)
    {
        for (u8Sent_Flg = 0; u8Sent_Flg < SENT_CHANNEL_NUM; u8Sent_Flg++)
        {
            if ((SentChannelConfigSet.pChanCfgPtr[u8Sent_Flg].u8ChannelId & (0x1F))== u8Sent_Index)
            {
                SRX_LLD_IRQ_COMBINED_SLOW_Dispatch(1u, u8Sent_Index);
                break;
            }
        }
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX1_COMBINED_ERR_IRQHandler(void)
{
    uint8 u8Sent_Index, u8Sent_Flg;
    for(u8Sent_Index = 0u; u8Sent_Index < SRX1_CHANNEL_COUNT; u8Sent_Index++)
    {
        for (u8Sent_Flg = 0; u8Sent_Flg < SENT_CHANNEL_NUM; u8Sent_Flg++)
        {
            if ((SentChannelConfigSet.pChanCfgPtr[u8Sent_Flg].u8ChannelId & (0x1F))== u8Sent_Index)
            {
                SRX_LLD_IRQ_COMBINED_ERR_Dispatch(1u, u8Sent_Index);
                break;
            }
        }
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif /* FEATURE_SRX_HAS_COMBINED_IRQ */

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX1_CH1_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 1u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX1_CH2_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 2u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX1_CH3_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 3u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX1_CH4_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 4u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX1_CH5_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 5u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
FUNC(void, SENT_CODE) SRX1_CH6_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 6u);
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#endif

#endif /* RESOURCE_SUPPORT_SENT */

/*******************************************************************************
* EOF
*******************************************************************************/
