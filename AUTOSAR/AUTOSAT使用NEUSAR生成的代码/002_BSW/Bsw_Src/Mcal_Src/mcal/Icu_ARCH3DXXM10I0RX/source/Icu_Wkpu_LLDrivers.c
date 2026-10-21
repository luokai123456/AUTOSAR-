/* PRQA S 3432, 0380, 2985, 2842, 2921, 1842, 1891, 2877 EOF */
/* PRQA S 2844, 0491, 2991, 1258, 4559, 2995, 2053 EOF */
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu.h"
#if (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI))

#include "Icu_Irq.h"
#include "Icu_Wkpu_LLDrivers.h"
#include "Icu_Cfg.h"

#define ICU_START_SEC_CONFIG_DATA
#include "Icu_MemMap.h"
CONSTP2VAR(WKPU_Type, ICU_CONST, ICU_APPL_CONST)Wkpu_Base[] = {((WKPU_Type *)0xFFF98000UL)};
#define ICU_STOP_SEC_CONFIG_DATA
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_INIT
#include "Icu_MemMap.h"
static VAR(uint16, ICU_VAR)Wkpu_ChMap[1U][64U] = {{0U}};
#define ICU_STOP_SEC_VAR_INIT
#include "Icu_MemMap.h"

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_WKPU_LLDRIVERS_VENDOR_ID_C                   176

#define ICU_WKPU_LLDRIVERS_MAJOR_VER_C                   4
#define ICU_WKPU_LLDRIVERS_MINOR_VER_C                   4
#define ICU_WKPU_LLDRIVERS_REVISION_VER_C                0

#define ICU_WKPU_LLDRIVERS_SW_MAJOR_VER_C                3
#define ICU_WKPU_LLDRIVERS_SW_MINOR_VER_C                0
#define ICU_WKPU_LLDRIVERS_SW_PATCH_VER_C                0

#if (ICU_WKPU_LLDRIVERS_VENDOR_ID_C != ICU_WKPU_LLDRIVERS_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_WKPU_LLDRIVERS_MAJOR_VER_C != ICU_WKPU_LLDRIVERS_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_WKPU_LLDRIVERS_MINOR_VER_C != ICU_WKPU_LLDRIVERS_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_WKPU_LLDRIVERS_REVISION_VER_C != ICU_WKPU_LLDRIVERS_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_WKPU_LLDRIVERS_SW_MAJOR_VER_C != ICU_WKPU_LLDRIVERS_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_WKPU_LLDRIVERS_SW_MINOR_VER_C != ICU_WKPU_LLDRIVERS_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_WKPU_LLDRIVERS_SW_PATCH_VER_C != ICU_WKPU_LLDRIVERS_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EdgeRisingSet
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];/* polyspace RTE:OBAI */
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        base->WIREER0.R |= Val;/* polyspace RTE:NIV */
        base->WIFEER0.R &= ~Val;/* polyspace RTE:NIV */
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        base->WIREER1.R |= Val;/* polyspace RTE:NIV */
        base->WIFEER1.R &= ~Val;/* polyspace RTE:NIV */
    }
    else
    {
        // Do nothing
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EdgeFallingSet
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];/* polyspace RTE:OBAI */
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        base->WIREER0.R &= ~Val;/* polyspace RTE:NIV */
        base->WIFEER0.R |= Val;/* polyspace RTE:NIV */
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        base->WIREER1.R &= ~Val;/* polyspace RTE:NIV */
        base->WIFEER1.R |= Val;/* polyspace RTE:NIV */
    }
    else
    {
        // Do nothing
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EdgeBothSet
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];/* polyspace RTE:OBAI */
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        base->WIREER0.R |= Val;/* polyspace RTE:NIV */
        base->WIFEER0.R |= Val;/* polyspace RTE:NIV */
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        base->WIREER1.R |= Val;/* polyspace RTE:NIV */
        base->WIFEER1.R |= Val;/* polyspace RTE:NIV */
    }
    else
    {
        // Do nothing
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
static FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EdgeNoneSet
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        base->WIREER0.R &= ~Val;/* polyspace RTE:NIV */
        base->WIFEER0.R &= ~Val;/* polyspace RTE:NIV */
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        base->WIREER1.R &= ~Val;/* polyspace RTE:NIV */
        base->WIFEER1.R &= ~Val;/* polyspace RTE:NIV */
    }
    else
    {
        // Do nothing
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_Init
(
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Wkpu_ConfigPtr
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[Wkpu_ConfigPtr->IcuConfig_ModuleId];/* polyspace RTE:OBAI,IDP,NIV */
    VAR(uint32, ICU_VAR) Val = 0U;

    Wkpu_ChMap[Wkpu_ConfigPtr->IcuConfig_ModuleId][Wkpu_ConfigPtr->IcuConfig_ChannelId] = Wkpu_ConfigPtr->IcuConfig_Instance;/* polyspace RTE:OBAI,NIV */

    if(Wkpu_ConfigPtr->IcuConfig_ChannelId < 32U)
    {
        Val = (uint32)(1UL << Wkpu_ConfigPtr->IcuConfig_ChannelId);
        if(Wkpu_ConfigPtr->IcuChannel_Filter == TRUE)/* polyspace RTE:NIV */
        {
            base->WIFER0.R |= Val;/* polyspace RTE:NIV */
        }
        else
        {
            base->WIFER0.R &= ~Val;/* polyspace RTE:NIV */
        }
    }
    else if(Wkpu_ConfigPtr->IcuConfig_ChannelId < 64U)
    {
        Val = (uint32)(1UL << (Wkpu_ConfigPtr->IcuConfig_ChannelId - 32U));
        if(Wkpu_ConfigPtr->IcuChannel_Filter == TRUE)/* polyspace RTE:NIV */
        {
            base->WIFER1.R |= Val;/* polyspace RTE:NIV */
        }
        else
        {
            base->WIFER1.R &= ~Val;/* polyspace RTE:NIV */
        }
    }
    else
    {
        // Do Nothing
    }
    switch(Wkpu_ConfigPtr->IcuChannel_DefaultStartEdge)/* polyspace RTE:NIV */
    {
        case ICU_RISING_EDGE:
        {
            Icu_Wkpu_LLD_EdgeRisingSet(Wkpu_ConfigPtr->IcuConfig_ModuleId,(uint8)Wkpu_ConfigPtr->IcuConfig_ChannelId);
        }break;
        case ICU_FALLING_EDGE:
        {
            Icu_Wkpu_LLD_EdgeFallingSet(Wkpu_ConfigPtr->IcuConfig_ModuleId,(uint8)Wkpu_ConfigPtr->IcuConfig_ChannelId);
        }break;
        case ICU_BOTH_EDGES:
        {
            Icu_Wkpu_LLD_EdgeBothSet(Wkpu_ConfigPtr->IcuConfig_ModuleId,(uint8)Wkpu_ConfigPtr->IcuConfig_ChannelId);
        }break;
        default:
        {
            Icu_Wkpu_LLD_EdgeNoneSet(Wkpu_ConfigPtr->IcuConfig_ModuleId,(uint8)Wkpu_ConfigPtr->IcuConfig_ChannelId);
        }break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_DeInit
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];/* polyspace RTE:OBAI */
    VAR(uint32, ICU_VAR) Val = 0U;

    Wkpu_ChMap[instance][hwChannel] = 0U;/* polyspace RTE:OBAI */

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        base->WIFER0.R &= ~Val;/* polyspace RTE:NIV */
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        base->WIFER1.R &= ~Val;/* polyspace RTE:NIV */
    }
    else
    {
        // Do Nothing
    }
    Icu_Wkpu_LLD_EdgeNoneSet(instance, hwChannel);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_WkpuNMI_LLD_Init(
    P2CONST(ICU_Wkpu_NMIConfigType, AUTOMATIC, ICU_APPL_CONST) pWkpuNMIConfig
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    P2CONST(Wkpu_NmiCfgType, ICU_VAR, ICU_APPL_CONST) ConfigNMI = &pWkpuNMIConfig->WkpuNMIConfig[0];/* polyspace RTE:IDP,NIP */
    VAR(uint8, ICU_VAR)coreNumber = 0U;
    VAR(uint32, ICU_VAR)coreShift = 0U;

#ifdef RESOURCE_SUPPORT_WKPU_NMI_IO_MUX
#if (RESOURCE_SUPPORT_WKPU_NMI_IO_MUX == NMI_IO_MUX_REG_WKPU_NCR)

    #if (ICU_NMI_WAKEUP_PIN == WKP_PS0) /* PRQA S 3332 */

    if ((WKPU.NCR.R & 0x00000008U) != 0x00000000U)
    { 
        WKPU.NCR.R &= (uint32)~0x00000008UL;
    } 

    #elif (ICU_NMI_WAKEUP_PIN == WKP_PA4)

    if ((WKPU.NCR.R & 0x00000008U) != 0x00000008U)
    { 
        WKPU.NCR.R |= 0x00000008U;
    } 

    #endif

#elif (RESOURCE_SUPPORT_WKPU_NMI_IO_MUX == NMI_IO_MUX_REG_SIUL2_SCR0)

    #if (ICU_NMI_WAKEUP_PIN == WKP_PS0) 

    if ((SIUL2.SCR0.R & 0x40000000U) != 0x00000000U)
    { 
        SIUL2.SCR0.R &= ~0x40000000U;
    } 

    #elif (ICU_NMI_WAKEUP_PIN == WKP_PA4)

    if ((SIUL2.SCR0.R & 0x40000000U) != 0x40000000U)
    { 
        SIUL2.SCR0.R |= 0x40000000U;
    } 

    #endif

#else
    #error "RESOURCE_SUPPORT_WKPU_NMI_IO_MUX error!"
#endif /* (RESOURCE_SUPPORT_WKPU_NMI_IO_MUX == NMI_IO_MUX_REG_SIUL2_SCR0) */
#endif /* RESOURCE_SUPPORT_WKPU_NMI_IO_MUX */
    for (uint8 i = 0U; i<pWkpuNMIConfig->NMICount; i++)/* polyspace RTE:NIV */
    {
        coreNumber = (uint8)ConfigNMI[i].core;/* polyspace RTE:NIV,IDP*/
        if(coreNumber < 3U)
        {
            coreShift = (coreNumber * WKPU_NMI_CORE_BIT_OFFSET);
            /* Configure destination source */
            base->NCR.R &= ~(WKPU_NCR_NDSS0_MASK >> coreShift);/* polyspace RTE:NIV */
            base->NCR.R |= WKPU_NCR_NDSS0((uint8)ConfigNMI[i].destination) >> coreShift;/* polyspace RTE:NIV */

            /* Configure wake-up request */
            base->NCR.R &= ~(WKPU_NCR_NWRE0_MASK >> coreShift);
            base->NCR.R |= WKPU_NCR_NWRE0(ConfigNMI[i].wkpReqEn ? 1UL : 0UL) >> coreShift;/* polyspace RTE:NIV */

            /* Only set filter for Core 0 */
            if ( 0UL == coreNumber)
            {
                /* Configure glitch filter */
                base->NCR.R &= ~(WKPU_NCR_NFE0_MASK >> coreShift);
                base->NCR.R |= WKPU_NCR_NFE0(ConfigNMI[i].filterEn ? 1UL : 0UL) >> coreShift;/* polyspace RTE:NIV */
            }

            /* Configure edge events */
            if (WKPU_RISING_EDGE == ConfigNMI[i].edgeEvent)/* polyspace RTE:NIV */
            {
                base->NCR.R |= WKPU_NCR_NREE0_MASK >> coreShift;
                base->NCR.R &= ~(WKPU_NCR_NFEE0_MASK >> coreShift);
            }
            else if (WKPU_FALLING_EDGE == ConfigNMI[i].edgeEvent)
            {
                base->NCR.R &= ~(WKPU_NCR_NREE0_MASK >> coreShift);
                base->NCR.R |= WKPU_NCR_NFEE0_MASK >> coreShift;
            }
            else
            {
                base->NCR.R |= WKPU_NCR_NFEE0_MASK >> coreShift;
                base->NCR.R |= WKPU_NCR_NREE0_MASK >> coreShift;
            }
            /* Configure lock */
            base->NCR.R |= WKPU_NCR_NLOCK0(ConfigNMI[i].lockEn ? 1UL : 0UL) >> coreShift;/* polyspace RTE:NIV */
        }
        else if (coreNumber < 6u)
        {
            coreShift = ((coreNumber % 3U) * WKPU_NMI_CORE_BIT_OFFSET);
            /* Configure destination source */
            base->NCR1.R &= ~(WKPU_NCR1_NDSS3_MASK >> coreShift);/* polyspace RTE:NIV */
            base->NCR1.R |= WKPU_NCR1_NDSS3((uint8)ConfigNMI[i].destination) >> coreShift;/* polyspace RTE:NIV */

            /* Configure wake-up request */
            base->NCR1.R &= ~(WKPU_NCR1_NWRE3_MASK >> coreShift);
            base->NCR1.R |= WKPU_NCR1_NWRE3(ConfigNMI[i].wkpReqEn ? 1UL : 0UL) >> coreShift;/* polyspace RTE:NIV */

            /* Configure edge events */
            if (WKPU_RISING_EDGE == ConfigNMI[i].edgeEvent)/* polyspace RTE:NIV */
            {
                base->NCR1.R |= WKPU_NCR1_NREE3_MASK >> coreShift;
                base->NCR1.R &= ~(WKPU_NCR1_NFEE3_MASK >> coreShift); 
            }
            else if (WKPU_FALLING_EDGE == ConfigNMI[i].edgeEvent)
            {
                base->NCR1.R &= ~(WKPU_NCR1_NREE3_MASK >> coreShift);
                base->NCR1.R |= WKPU_NCR1_NFEE3_MASK >> coreShift;
            }
            else
            {
                base->NCR1.R |= WKPU_NCR1_NFEE3_MASK >> coreShift;
                base->NCR1.R |= WKPU_NCR1_NREE3_MASK >> coreShift;
            }
            /* Configure lock */
            base->NCR1.R |= WKPU_NCR1_NLOCK3(ConfigNMI[i].lockEn ? 1UL : 0UL) >> coreShift;/* polyspace RTE:NIV */
        }
        else
        {
            /* nothing */
        }
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_WkpuNMI_LLD_DeInit( void )
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
	VAR(uint32, ICU_VAR)coreShift = 0U;

    for (uint32 CoreIdx = 0U; CoreIdx < WKPU_NMI_CORE_MAX; CoreIdx++)
	{
		
        if(CoreIdx < 3)
        {
            coreShift = (uint32)CoreIdx * WKPU_NMI_CORE_BIT_OFFSET;
            if((base->NCR.R & WKPU_NCR_NLOCK0(coreShift) )!= 0U)/* polyspace RTE:NIV */
            {
                // Do nothing
            }
            else
            {
                /* Clear status flag and overrun status flag */
                base->NSR.R = ((WKPU_NSR_NIF0_MASK | WKPU_NSR_NOVF0_MASK) >> coreShift);
                /* Clear edge events */
                base->NCR.R &= ~(WKPU_NCR_NREE0_MASK >> coreShift);
                base->NCR.R &= ~(WKPU_NCR_NFEE0_MASK >> coreShift);

                /* Only set filter for Core 0 */
                if ((uint32)WKPU_CORE0 == (uint32) CoreIdx)
                {
                    /* Disable glitch filter */
                    base->NCR.R &= ~(WKPU_NCR_NFE0_MASK >> coreShift);
                }
                /* Disable wake-up request */
                base->NCR.R &= ~(WKPU_NCR_NWRE0_MASK >> coreShift);
                /* Configure destination source */
                base->NCR.R &= ~(WKPU_NCR_NDSS0_MASK >> coreShift);
                base->NCR.R |= WKPU_NCR_NDSS0((uint8)WKPU_NMI_NONE) >> coreShift;
            }

        }
        else if(CoreIdx < 6)
        {
            coreShift = ((uint32)CoreIdx % 3U) * WKPU_NMI_CORE_BIT_OFFSET;
            if((base->NCR1.R & WKPU_NCR1_NLOCK3(coreShift) )!= 0U)/* polyspace RTE:NIV */
            {
                // Do nothing
            }
            else
            {
                /* Clear status flag and overrun status flag */
                base->NSR1.R = ((WKPU_NSR1_NIF3_MASK | WKPU_NSR1_NOVF3_MASK) >> coreShift);
                /* Clear edge events */
                base->NCR1.R &= ~(WKPU_NCR1_NREE3_MASK >> coreShift);
                base->NCR1.R &= ~(WKPU_NCR1_NFEE3_MASK >> coreShift);

                /* Disable wake-up request */
                base->NCR1.R &= ~(WKPU_NCR1_NWRE3_MASK >> coreShift);
                /* Configure destination source */
                base->NCR1.R &= ~(WKPU_NCR1_NDSS3_MASK >> coreShift);
                base->NCR1.R |= WKPU_NCR1_NDSS3((uint8)WKPU_NMI_NONE) >> coreShift;
            }
        }
        else
        {
            // Do nothing
        }
	}
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EnableInterrupt
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];/* polyspace RTE:OBAI */
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        base->WISR0.R = Val;/* polyspace RTE:NIV */
        base->IRER0.R |= Val;/* polyspace RTE:NIV */
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        base->WISR1.R = Val;/* polyspace RTE:NIV */
        base->IRER1.R |= Val;/* polyspace RTE:NIV */
    }
    else
    {
        // Do nothing
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_DisableInterrupt
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];/* polyspace RTE:OBAI */
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        base->WISR0.R = Val;/* polyspace RTE:NIV */
        base->IRER0.R &= ~Val;/* polyspace RTE:NIV */
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        base->WISR1.R = Val;/* polyspace RTE:NIV */
        base->IRER1.R &= ~Val;/* polyspace RTE:NIV */
    }
    else
    {
        // Do nothing
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EnableWakeup
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];/* polyspace RTE:OBAI */
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        base->WISR0.R = Val;/* polyspace RTE:NIV */
        base->WRER0.R |= Val;/* polyspace RTE:NIV */
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        base->WISR1.R = Val;/* polyspace RTE:NIV */
        base->WRER1.R |= Val;/* polyspace RTE:NIV */
    }
    else
    {
        // Do nothing
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_DisableWakeup
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];/* polyspace RTE:OBAI */
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        base->WISR0.R = Val;/* polyspace RTE:NIV */
        base->WRER0.R &= ~Val;/* polyspace RTE:NIV */
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        base->WISR1.R = Val;/* polyspace RTE:NIV */
        base->WRER1.R &= ~Val;/* polyspace RTE:NIV */
    }
    else
    {
        // Do nothing
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_SetActivationCondition
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel,
    VAR(Icu_Wkpu_EdgeType, ICU_VAR)edge
)
{

    switch(edge)
    {
        case WKPU_NONE_EDGE:
        {
            Icu_Wkpu_LLD_EdgeNoneSet(instance,hwChannel);
        }break;
        case WKPU_RISING_EDGE:
        {
            Icu_Wkpu_LLD_EdgeRisingSet(instance,hwChannel);
        }break;
        case WKPU_FALLING_EDGE:
        {
            Icu_Wkpu_LLD_EdgeFallingSet(instance,hwChannel);
        }break;
        case WKPU_BOTH_EDGES:
        {
            Icu_Wkpu_LLD_EdgeBothSet(instance,hwChannel);
        }break;
        default :
        {
        	/*do nothing*/
        }break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(boolean, ICU_CODE)Icu_Wkpu_LLD_GetInputState
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];/* polyspace RTE:OBAI */
    VAR(uint32, ICU_VAR) Val = 0U;
    VAR(boolean, ICU_VAR) status = FALSE;

    if(hwChannel < 32U)
    {
        Val = (uint32)(1UL << hwChannel);
        if((Val & base->WISR0.R)!=0U)/* polyspace RTE:NIV */
        {
            status = TRUE;
        }
        else
        {
            status = FALSE;
        }
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)(1UL << (hwChannel - 32U));
        if((Val & base->WISR1.R)!=0U)/* polyspace RTE:NIV */
        {
            status = TRUE;
        }
        else
        {
            status = FALSE;
        }
    }
    else
    {
        // Do nothing
    }
    return status;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_IrqCallbcak
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    ICU_AutoSAR_Wapper_ReportEvents(Wkpu_ChMap[instance][hwChannel], FALSE);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#endif /* (defined(RESOURCE_SUPPORT_WKPU_MULT_WAKE_SRC) || defined (RESOURCE_SUPPORT_WKPU_NMI)) */
#ifdef __cplusplus
}
#endif

/** @} */

