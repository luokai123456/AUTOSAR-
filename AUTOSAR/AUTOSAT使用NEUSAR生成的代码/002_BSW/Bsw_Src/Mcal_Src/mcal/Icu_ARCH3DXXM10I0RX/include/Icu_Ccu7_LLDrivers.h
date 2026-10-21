/* PRQA S 2023, 2024, 1860,0722,1281,4534,2016,4543,2053,1599,4434,1891,1841,4542 EOF */
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           :
*   Dependencies         :
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Icu_Ccu7_LLDriver.h
*   @version
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/

#ifndef ICU_Ccu7_LLDRIVER_H
#define ICU_Ccu7_LLDRIVER_H
#ifdef __cplusplus
extern "C"
{
#endif
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Std_Types.h"
#include "Compiler.h"
#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_CCU7_IP))

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_Ccu7_LLDRIVERS_VENDOR_ID_H                   176

#define ICU_Ccu7_LLDRIVERS_MAJOR_VER_H                   4
#define ICU_Ccu7_LLDRIVERS_MINOR_VER_H                   4
#define ICU_Ccu7_LLDRIVERS_REVISION_VER_H                0

#define ICU_Ccu7_LLDRIVERS_SW_MAJOR_VER_H                3
#define ICU_Ccu7_LLDRIVERS_SW_MINOR_VER_H                0
#define ICU_Ccu7_LLDRIVERS_SW_PATCH_VER_H                0

#if (ICU_Ccu7_LLDRIVERS_VENDOR_ID_H != STANDARD_VENDOR_ID)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_Ccu7_LLDRIVERS_MAJOR_VER_H != STANDARD_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_Ccu7_LLDRIVERS_MINOR_VER_H != STANDARD_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_Ccu7_LLDRIVERS_REVISION_VER_H != STANDARD_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_Ccu7_LLDRIVERS_SW_MAJOR_VER_H != STANDARD_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_Ccu7_LLDRIVERS_SW_MINOR_VER_H != STANDARD_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_Ccu7_LLDRIVERS_SW_PATCH_VER_H != STANDARD_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define CCU7_0_BASEADDR                     &CCU7_0
#define CCU7_1_BASEADDR                     &CCU7_1
typedef struct CCU7_Type st_Ccu7_Type;

/** Array initializer of Ccu7 peripheral base pointers */
#define CCU7_CHANNEL_0                      (uint8)0U
#define CCU7_CHANNEL_1                      (uint8)1U
#define CCU7_CHANNEL_2                      (uint8)2U

#define ICU_CCU7_INSTANCE_MAX               (2U)
#define ICU_CCU7_MODULE_CHANNEL_MAX         (3U)

#define ICU_CCU_CAPTURE_MODE1               (4U)
#define ICU_CCU_CAPTURE_MODE2               (5U)
#define ICU_CCU_CAPTURE_MODE3               (6U)
#define ICU_CCU7_MAX_T12_TIMER_VAL          (0xFFFFU)

#define ICU_CCU7_TCTR4_T12RR_SET_MASK       (0x00000001UL)
#define ICU_CCU7_TCTR4_T12RS_SET_MASK       (0x00000002UL)
#define ICU_CCU7_TCTR4_T12STR_SET_MASK      (0x00000040UL)

static volatile st_Ccu7_Type* pCcu7_BasePtr[ICU_CCU7_INSTANCE_MAX] = { CCU7_0_BASEADDR, CCU7_1_BASEADDR };

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef enum
{
    ICU_CCU7x_0 = 0u,
    ICU_CCU7x_1 = 1u,
    ICU_CCU7x_2 = 2u,
    ICU_CCU7x_3 = 3u
} Ccu7_Port_Select;

typedef enum
{
    ICU_PreDisable = 0u,
    ICU_PreEnable = 1u
} Ccu7_T12_Prescaler;

typedef enum
{
    ICU_EdgealignedMode = 0u,
    ICU_CenteralignedMode = 1u
} Ccu7_Operating_Mode;

typedef enum
{
    ICU_SR0 = 0u,
    ICU_SR1 = 1u,
    ICU_SR2 = 2u,
    ICU_SR3 = 3u
} Ccu7_Interupt_Line;

typedef enum
{
    ICU_MODE1 = 4u,
    ICU_MODE2 = 5u,
    ICU_MODE3 = 6u,
    ICU_MODE4 = 7u
} Ccu7_TimerMode;

typedef enum
{
    ICU_CCU7X_R = 1u,
    ICU_CCU7X_F = 2u,
    ICU_CCU7X_RF = 3u
} Ccu7_Edge_Type;

typedef enum
{
    CCU7_INS0 = 0u,
    CCU7_INS1 = 1u
} Ccu7_Instance_Type;

typedef enum
{
    ICU_CCU70 = 0u,
    ICU_CCU71 = 1u,
    ICU_CCU72 = 2u
} Ccu7_Channel_Type;

typedef struct             /*PRQA S 3630 EOF*/
{
	uint8 TimerCtrlReg0; /* For T12 - [2-0] - Timer T12 Input Clock Select
	                                     [3]   - Timer T12 Prescaler Bit
	                                     [7]   - T12 Operating Mode
	                           For T13 - [10-8] - Timer T13 Input Clock Select
	                                     [11]   - Timer T13 Prescaler Bit*/
	uint32 TimerCntReg;
	uint32 TimerPeriodReg;
	uint8 TimerModeSelectReg;
	uint8 PortInSelReg0;
	uint8 IntEnReg;           /* 2 - Falling 1- Raising 0- PM */
	uint8 IntNodePointerReg;  /* [3:2]T12/T13, [1:0] CC6x     */
} Ccu7_ic_param_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetTCTR0 \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint8, AUTOMATIC) reg
)
{
    pCcu7_BasePtr[Ccu7Group]->TCTR0.reg &= 0xffffff00;/* polyspace RTE:OBAI,NIV */
    pCcu7_BasePtr[Ccu7Group]->TCTR0.reg |= (uint32)reg;/* polyspace RTE:NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_ClrCc7xFlag \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel,
    VAR(Ccu7_Edge_Type, AUTOMATIC) mask
)
{
    switch (mask)
    {
        case ICU_CCU7X_R:
            pCcu7_BasePtr[Ccu7Group]->ISR.reg = (0x1 << (channel * 2));
            break;
        case ICU_CCU7X_F:
            pCcu7_BasePtr[Ccu7Group]->ISR.reg = (0x2 << (channel * 2));
            break;
        case ICU_CCU7X_RF:
            pCcu7_BasePtr[Ccu7Group]->ISR.reg = (0x3 << (channel * 2));/* polyspace RTE:SHF,OVFL,OBAI */
            break;
        default:
            break;
    };
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_ClrT12pmFlag \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group
)
{
    pCcu7_BasePtr[Ccu7Group]->ISR.reg = 0x80;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetCc7xIntEn \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel,
    VAR(Ccu7_Edge_Type, AUTOMATIC) mask
)
{
    pCcu7_BasePtr[Ccu7Group]->IEN.reg &= ~(0x3u << (channel * 2u));/* polyspace RTE:NIV */
    switch (mask)
    {
        case ICU_CCU7X_R:
            pCcu7_BasePtr[Ccu7Group]->IEN.reg |= (0x1u << (channel * 2u));/* polyspace RTE:NIV */
            break;
        case ICU_CCU7X_F:
            pCcu7_BasePtr[Ccu7Group]->IEN.reg |= (0x2u << (channel * 2u));/* polyspace RTE:NIV */
            break;
        case ICU_CCU7X_RF:
            pCcu7_BasePtr[Ccu7Group]->IEN.reg |= (0x3u << (channel * 2u));/* polyspace RTE:NIV */
            break;
        default:
            break;
    };
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_ClrCc7xIntEn \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel,
    VAR(Ccu7_Edge_Type, AUTOMATIC) mask
)
{
    switch (mask)
    {
        case ICU_CCU7X_R:
            pCcu7_BasePtr[Ccu7Group]->IEN.reg &= ~(0x1U << (channel * 2U));
            break;
        case ICU_CCU7X_F:
            pCcu7_BasePtr[Ccu7Group]->IEN.reg &= ~(0x2U << (channel * 2U));
            break;
        case ICU_CCU7X_RF:
            pCcu7_BasePtr[Ccu7Group]->IEN.reg &= ~(0x3U << (channel * 2U));/* polyspace RTE:SHF,OBAI,NIV */
            break;
        default:
            break;
    };
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetT12pmIntEn \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group
)
{
    pCcu7_BasePtr[Ccu7Group]->IEN.reg |= 0x80U;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_ClrT12pmIntEn \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group
)
{
    pCcu7_BasePtr[Ccu7Group]->IEN.reg &= ~0x80U;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetInpT12 \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group,
    VAR(uint8, AUTOMATIC) reg
)
{

    pCcu7_BasePtr[Ccu7Group]->INP.bit.INPT12 = (reg >> 2U) & 0x3U;

}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetInpCc7x \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel,
    VAR(uint8, AUTOMATIC) reg
)
{
    pCcu7_BasePtr[Ccu7Group]->INP.reg &= ~(0x3U << (channel * 2U));/* polyspace RTE:NIV */
    pCcu7_BasePtr[Ccu7Group]->INP.reg |= ((reg & 0x3U) << (channel * 2U));/* polyspace RTE:NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetPISEL0 \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel,
    VAR(uint8, AUTOMATIC) reg
)
{
    pCcu7_BasePtr[Ccu7Group]->PISEL0.reg &= ~(0x3U << (channel * 2));/* polyspace RTE:NIV */
    pCcu7_BasePtr[Ccu7Group]->PISEL0.reg |= (reg << (channel * 2));/* polyspace RTE:OVFL,NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetT12MSEL \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel,
    VAR(uint8, AUTOMATIC) reg
)
{
    pCcu7_BasePtr[Ccu7Group]->T12MSEL.reg &= ~(0xFU << (channel * 4));/* polyspace RTE:SHF,OBAI,NIV */
    pCcu7_BasePtr[Ccu7Group]->T12MSEL.reg |= (reg << (channel * 4));/* polyspace RTE:OVFL,NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetT12PR \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group,
    VAR(uint32, AUTOMATIC) reg
)
{
    pCcu7_BasePtr[Ccu7Group]->T12PR.reg = reg;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetT12CNT \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint32, AUTOMATIC) reg
)
{
    pCcu7_BasePtr[Ccu7Group]->T12.reg = reg;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetTimerShadowTransfer \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group
)
{
    pCcu7_BasePtr[Ccu7Group]->TCTR4.bit.T12STR = 1u;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetCmpmodifCC7xR \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel
)
{
    pCcu7_BasePtr[Ccu7Group]->CMPMODIF.reg = (1u << (8 + channel));
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(uint8, CCU7_CODE) ICU_CCU7_LLD_GetIsCC7xR \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel
)
{
    return (uint8)((pCcu7_BasePtr[Ccu7Group]->IS.reg >> (channel * 2)) & 0x3);/* polyspace RTE:SHF,OBAI,NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(uint8, CCU7_CODE) ICU_CCU7_LLD_GetIenCC7xR \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel
)
{
    return (uint8)((pCcu7_BasePtr[Ccu7Group]->IEN.reg >> (channel * 2)) & 0x3);/* polyspace RTE:NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_ClrCC7xSR \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel
)
{
    switch (channel)
    {
    case 0:
        pCcu7_BasePtr[Ccu7Group]->CC70SR.reg = 0u;
        break;
    case 1:
        pCcu7_BasePtr[Ccu7Group]->CC71SR.reg = 0u;
        break;
    case 2:
        pCcu7_BasePtr[Ccu7Group]->CC72SR.reg = 0u;
        break;
    default:
        //do nothing
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(uint32, CCU7_CODE) ICU_CCU7_LLD_GetCC7xR \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel
)
{
    switch (channel)
    {
    case 0:
        return pCcu7_BasePtr[Ccu7Group]->CC70R.reg;/* polyspace RTE:NIV */
    case 1:
        return pCcu7_BasePtr[Ccu7Group]->CC71R.reg;/* polyspace RTE:NIV */
    case 2:
        return pCcu7_BasePtr[Ccu7Group]->CC72R.reg;/* polyspace RTE:NIV */
    default:
        return 0;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(uint32, CCU7_CODE) ICU_CCU7_LLD_GetCC7xSR \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint16, AUTOMATIC) channel
)
{
    switch (channel)
    {
    case 0:
        return pCcu7_BasePtr[Ccu7Group]->CC70SR.reg;/* polyspace RTE:NIV */
    case 1:
        return pCcu7_BasePtr[Ccu7Group]->CC71SR.reg;/* polyspace RTE:NIV */
    case 2:
        return pCcu7_BasePtr[Ccu7Group]->CC72SR.reg;/* polyspace RTE:NIV */
    default:
        return 0;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(uint8, CCU7_CODE) ICU_CCU7_LLD_GetCLCDISS \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group
)
{
    return (uint8)((pCcu7_BasePtr[Ccu7Group]->CLC.reg >> 1) & 0x1);/* polyspace RTE:OBAI,NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetCLCDISR \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(boolean, AUTOMATIC) IsEnable
)
{
    pCcu7_BasePtr[Ccu7Group]->CLC.reg &= 0xFFFFFFFE;/* polyspace RTE:NIV */
    pCcu7_BasePtr[Ccu7Group]->CLC.reg |= IsEnable;/* polyspace RTE:NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetTCTR4 \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint32, AUTOMATIC) mask
)
{
    pCcu7_BasePtr[Ccu7Group]->TCTR4.reg |= mask;/* polyspace RTE:NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(uint8, CCU7_CODE) ICU_CCU7_LLD_GetMCFG \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint32, AUTOMATIC) mask
)
{
    return (uint8)(pCcu7_BasePtr[Ccu7Group]->MCFG.reg & (0x1U << mask));/* polyspace RTE:NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
LOCAL_INLINE FUNC(void, CCU7_CODE) ICU_CCU7_LLD_SetMCFG \
( \
    VAR(uint8, AUTOMATIC) Ccu7Group, \
    VAR(uint32, AUTOMATIC) mask
)
{
    pCcu7_BasePtr[Ccu7Group]->MCFG.reg |= (0x1U << mask);/* polyspace RTE:NIV */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */
#ifdef __cplusplus
}
#endif
#endif /* ICU_Ccu7_LLDRIVER_H */

