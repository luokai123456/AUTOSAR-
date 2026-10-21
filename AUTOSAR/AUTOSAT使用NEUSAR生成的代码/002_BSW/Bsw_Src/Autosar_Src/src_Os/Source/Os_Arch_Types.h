/*
********************************************************************************
*
*  File name: Os_Arch_Types.h
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
#ifndef OS_ARCH_TYPES_H_
#define OS_ARCH_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Arch_Lcfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define ARCH_CONTEXT_M           (0U)
#define ARCH_CONTEXT_R           (1U)
#define ARCH_TRICORE             (2U)
#define ARCH_POWERPC             (4U)
#define ARCH_RH850               (5U)

#define OS_SPINLOCK_UNLOCK       (0U)
#define OS_SPINLOCK_LOCK         (1U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* The type of interrupt state. */
typedef uint32 Os_Arch_IntState;
/* This data type of interrupt priority. */
typedef uint8 Os_IntLevelType;
/* This data type of interrupt number. */
typedef uint16 Os_IntNumType;

typedef struct
{
    /* Cat1 disable mask level. */
    Os_IntLevelType Cat1MaskLevel;
    /* Cat2 disable mask level. */
    Os_IntLevelType Cat2MaskLevel;
    /* Os_Arch_IntDisable disable mask level. */
    Os_IntLevelType IntDisableMaskLevel;
} Os_Arch_IsrMaskLevelType;

typedef struct
{
    /* Interrupt number. */
    Os_IntNumType number;
    /* Interrupt level. */
    Os_IntLevelType level;
} Os_Arch_IsrSourceType;

#if( OS_PIT_ENABLE == STD_ON )
struct Os_Arch_Mach_TimerPitCfg
{
    /* Pit timer base address. */
    uint32 TimerPitBaseAdress;
    /* Pit timer channel. */
    uint32 TimerPitChannel;
    /* Pit reload value. */
    uint32 ReloadValue;
};
#endif

#if( OS_HRT_ENABLE == STD_ON )
struct Os_Arch_Mach_TimerHrtCfg
{

    /* Hrt timer base address. */
    uint32 TimerHrtBaseAddress;
    /* Hrt timer channel. */
    uint32 TimerHrtChannel;
    /* Hrt isr source. */
    const Os_Arch_IsrSourceType* source;
};
#endif

#if( OS_PIT_ENABLE == STD_ON )
typedef struct Os_Arch_Mach_TimerPitCfg Os_Arch_Mach_TimerPitCfgType;
#endif

#if( OS_HRT_ENABLE == STD_ON )
typedef struct Os_Arch_Mach_TimerHrtCfg Os_Arch_Mach_TimerHrtCfgType;
#endif
typedef uint32 Os_Stack_Address;
typedef uint32 Os_Stack_Size;

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

#endif /* OS_ARCH_TYPES_H_ */
