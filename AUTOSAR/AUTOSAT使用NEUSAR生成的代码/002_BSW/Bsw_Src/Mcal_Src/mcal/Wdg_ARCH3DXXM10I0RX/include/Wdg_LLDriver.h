/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     Wdg_LLDriver.h
* @version  3.0.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/

#ifndef Wdg_LLDRIVER_H
#define Wdg_LLDRIVER_H
/*PRQA S 1534,3472,1535,3630,0722 EOF*/

#include "status.h"
#include "WdgIf_Types.h"
#include "Gpt.h"
#include "Wdg_Cfg.h"

#define WDG_LLD_H_VENDOR_ID                      176
#define WDG_LLD_H_VERSION_MAJOR                  4
#define WDG_LLD_H_VERSION_MINOR                  4
#define WDG_LLD_H_VERSION_REVISION               0
#define WDG_LLD_H_SW_VERSION_MAJOR               3
#define WDG_LLD_H_SW_VERSION_MINOR               0
#define WDG_LLD_H_SW_VERSION_PATCH               0

#if (WDG_LLD_H_VENDOR_ID != WDG_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_LLD_H_VENDOR_ID "
#endif
#if (WDG_LLD_H_VERSION_MAJOR != WDG_CFG_H_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_LLD_H_VERSION_MAJOR "
#endif
#if (WDG_LLD_H_VERSION_MINOR != WDG_CFG_H_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_LLD_H_VERSION_MINOR "
#endif
#if (WDG_LLD_H_VERSION_REVISION != WDG_CFG_H_VER_REVISION)
    #error " NON-MATCHED DATA : WDG_LLD_H_VERSION_REVISION "
#endif
#if (WDG_LLD_H_SW_VERSION_MAJOR != WDG_CFG_H_SW_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_LLD_H_SW_VERSION_MAJOR "
#endif
#if (WDG_LLD_H_SW_VERSION_MINOR != WDG_CFG_H_SW_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_LLD_H_SW_VERSION_MINOR "
#endif
#if (WDG_LLD_H_SW_VERSION_PATCH != WDG_CFG_H_SW_VER_PATCH)
    #error " NON-MATCHED DATA : WDG_LLD_H_SW_VERSION_PATCH "
#endif

#define SWT_REG_READBACK                         (0U)

typedef  struct SWT_tag                          SWT_tag_Type;

#define SWT_0_BASE_ADDR                          ((uint32_t)0xFC050000UL)
#define SWT_1_BASE_ADDR                          ((uint32_t)0xFC054000UL)
#define SWT_2_BASE_ADDR                          ((uint32_t)0xFC058000UL)
#define SWT_3_BASE_ADDR                          ((uint32_t)0xFC05C000UL)
#define SWT_4_BASE_ADDR                          ((uint32_t)0xFC044000UL)
#define SWT_5_BASE_ADDR                          ((uint32_t)0xFC048000UL)
#define SWT_6_BASE_ADDR                          ((uint32_t)0xFC04C000UL)
#define SWT_7_BASE_ADDR                          ((uint32_t)0xFC060000UL)
#define SWT_0_BASE                               ((SWT_tag_Type *)SWT_0_BASE_ADDR)
#define SWT_1_BASE                               ((SWT_tag_Type *)SWT_1_BASE_ADDR)
#define SWT_2_BASE                               ((SWT_tag_Type *)SWT_2_BASE_ADDR)
#define SWT_3_BASE                               ((SWT_tag_Type *)SWT_3_BASE_ADDR)
#define SWT_4_BASE                               ((SWT_tag_Type *)SWT_4_BASE_ADDR)
#define SWT_5_BASE                               ((SWT_tag_Type *)SWT_5_BASE_ADDR)
#define SWT_6_BASE                               ((SWT_tag_Type *)SWT_6_BASE_ADDR)
#define SWT_7_BASE                               ((SWT_tag_Type *)SWT_7_BASE_ADDR)
#define SWT_BASE_ARRAY                           {SWT_0_BASE, SWT_1_BASE, SWT_2_BASE, SWT_3_BASE,SWT_4_BASE, SWT_5_BASE, SWT_6_BASE, SWT_7_BASE}

#define SWT_DET_ERR(x)                          DEV_ASSERT(x)

#define SWT_INSTANCE_NUM                         8U

#define FCCU_CTRL_OPS_MASK        0xC0

/*
 * Service keys
 */
#define SWT_SERVICE_KEY_1   0xA602
#define SWT_SERVICE_KEY_2   0xB480

/*
 * Unlock keys
 */
#define SWT_UNLOCK_KEY_1    0xC520
#define SWT_UNLOCK_KEY_2    0xD928

/*
 * Converts a period (milliseconds) to ticks
 */
#define SWT_PERIOD_TO_TICKS(__frequency__, __period__) \
        (((__frequency__) * (__period__)) / 1000U)

/*
 * Pseudo random generated keys
 *
 * SKn + 1 = ((17 * SKn) + 3) mod 2^16
 */
#define NEW_SERVICE_KEY(__old_key__) \
        (((((__old_key__) << 4) + (0x00000003U) + (__old_key__))) & 0xFFFFU)

typedef void (*SWT_Callback_Type)(void);

typedef enum {
    SWT0 = 0,
    SWT1,
    SWT2,
    SWT3,
	SWT4,
	SWT5,
	SWT6,
	SWT7_AO
}SWT_ModuleID_Type;

 typedef enum {
     SWT_OFFMode = 0,
     SWT_SLOWMode,
     SWT_FASTMode
 }SWT_RunMode_Type;

typedef enum {
    Fixed_Serv_Seq = 0,
    Keyed_Serv_Seq,
#if (defined(RESOURCE_SUPPORT_WDG_ADDRMODE))
	Fixed_Addr_Exe,
	Incremental_Addr_Exe
#endif
}SWT_ServiceMode_Type;

typedef enum {
    SWT_BusError = 0,
    SWT_SystemReset
}SWT_RIA_Type;

typedef enum{
    SWT_Disable = 0,
    SWT_Enable
}SWT_Status_Type;

typedef enum
{
    SWT_RESET_FIRST = 0,
    SWT_RESET_SECOND,
} SWT_InterMode;

typedef enum
{
    SWT_CONTINUE = 0,
    SWT_STOP,
} SWT_StopMode_Type;

typedef enum
{
    SWT_FreezeOFF = 0,
    SWT_FreezeON,
} SWT_DebugMode_Type;

typedef enum
{
    SWT_Softlock = 0,
    SWT_Hardlock,
} SWT_Lock_Type;

typedef struct {
    uint8                SWT_MAPConfig;
    SWT_ServiceMode_Type SWT_ServiceMode;
    SWT_RIA_Type         SWT_ResetonInvalidAccess;
    SWT_Status_Type       SWT_WindowMode;
    SWT_InterMode         SWT_InterruptMode;
    SWT_StopMode_Type     SWT_StopMode;
    SWT_DebugMode_Type    SWT_DebugMode;
    SWT_Lock_Type         SWT_Lock_Mode;
    uint16                SWT_InitialSK;
    uint32                SWT_Timeout;
    uint32                SWT_WindowValue;
    uint32                Wdg_InternalClock;
#if (defined(RESOURCE_SUPPORT_WDG_ADDRMODE))
    uint32                Wdg_TriggerAddr;
#endif
} SWT_ModeConfig_Type;

typedef struct {
    CONST(SWT_ModuleID_Type, WDG_CONST) SWT_ModuleID;
    CONST(WdgIf_ModeType, WDG_CONST) SWT_DefaultRunMode;
    CONST(Gpt_ChannelType, WDG_CONST) u8Wdg_GptTimerChannel;
    CONST(uint32, WDG_CONST) u32Wdg_TriggerSourceClock;
    P2CONST(SWT_ModeConfig_Type, WDG_VAR, WDG_APPL_CONST) SWT_Config[3];
    SWT_Callback_Type             SWT_Callback;
} SWT_Module_Config_Type;

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_VAR) SWT_LLD_IRQHandler \
( \
	VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(status_t, WDG_CODE) SWT_LLD_SetMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(WdgIf_ModeType, WDG_VAR) eWdg_SWT_RunMode \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(status_t, WDG_CODE) SWT_LLD_Init \
( \
    P2CONST(SWT_Module_Config_Type, WDG_VAR, WDG_APPL_CONST) pWdg_Cfgptr \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE)     SWT_Trigger \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_ServiceMode_Type, WDG_VAR) eWdg_Servicemode \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint8, WDG_CODE)    SWT_LLD_GetDebugFreeze \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE)   SWT_LLD_GetInterruptFlag \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(status_t, WDG_CODE) SWT_LLD_SetStopMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_StopMode_Type, WDG_VAR) eWdg_Stopmode \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE)   SWT_LLD_GetStopMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE)   SWT_LLD_GetCounterOutValue \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#endif /* Wdg_LLDRIVER_H */
