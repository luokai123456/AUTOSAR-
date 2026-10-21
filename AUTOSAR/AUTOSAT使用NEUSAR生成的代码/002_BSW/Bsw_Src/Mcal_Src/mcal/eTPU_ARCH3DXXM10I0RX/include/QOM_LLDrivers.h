/*PRQA S 2053 EOF */

/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : -
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    QOM_LLDrivers.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of QOM MCAL driver.
*
*   @addtogroup QOM
*   @{
*/

#ifndef QOM_LLDRIVERS_H_
#define QOM_LLDRIVERS_H_

#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "eTPU_Cfg.h"
#include "status.h"

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define QOM_LLDRIVERS_VENDOR_ID_H                   176

#define QOM_LLDRIVERS_MAJOR_VER_H                   4
#define QOM_LLDRIVERS_MINOR_VER_H                   4
#define QOM_LLDRIVERS_REVISION_VER_H                0

#define QOM_LLDRIVERS_SW_MAJOR_VER_H                3
#define QOM_LLDRIVERS_SW_MINOR_VER_H                0
#define QOM_LLDRIVERS_SW_PATCH_VER_H                0

#if (QOM_LLDRIVERS_VENDOR_ID_H != ETPU_VENDOR_ID_OUTPUT)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_VENDOR_ID_H"
#endif

/* Check if current file and EBPPA header file are of the same Autosar version */
#if (QOM_LLDRIVERS_MAJOR_VER_H != ETPU_AR_REL_MAJOR_VER_OUTPUT)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_MAJOR_VER_H"
#endif
#if (QOM_LLDRIVERS_MINOR_VER_H != ETPU_AR_REL_MINOR_VER_OUTPUT)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_MINOR_VER_H"
#endif
#if (QOM_LLDRIVERS_REVISION_VER_H != ETPU_AR_REL_REVISION_VER_OUTPUT)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_REVISION_VER_H"
#endif

/* Check if current file and EBPPA header file are of the same Software version */
#if (QOM_LLDRIVERS_SW_MAJOR_VER_H != ETPU_SW_MAJOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_SW_MAJOR_VER_H"
#endif
#if (QOM_LLDRIVERS_SW_MINOR_VER_H != ETPU_SW_MINOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_SW_MINOR_VER_H"
#endif
#if (QOM_LLDRIVERS_SW_PATCH_VER_H != ETPU_SW_PATCH_VERSION_OUTPUT)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_SW_PATCH_VER_H"
#endif

#if ((ETPU_QOM_INSTANCE_NUM != 0U)&&(QOM_MODULE_ENABLE !=STD_OFF))
union etpu_events_array {
    uint32_t p;
    struct {
        uint32_t empty:9;
        uint32_t offset:22;
        uint32_t pin:1;
    } b;
};

typedef struct {
    uint8 event_array_size;
    const union etpu_events_array * const event_array;
} etpu_events_array_t;

typedef void (*Qom_GetStaType)(void);

typedef struct{
    CONST(Qom_GetStaType,ETPU_CONST) Qom_Notification;
}Qom_NotifyTableItemType;
typedef struct {
    uint8 etpuGroup;
    uint8 channel;
    uint8 priority; 
    uint8 mode;
    uint8 timebase;
    uint8 init_pin;
    uint8 first_match_mode;
    uint32 * ref;
    uint8 Loop;
    CONSTP2CONST(etpu_events_array_t, ETPU_CONST, ETPU_APPL_CONST) EventConfigPtr;
    boolean interrupt;
} etpu_qom_config_t;

typedef struct {

P2CONST(etpu_qom_config_t, ETPU_CONST, ETPU_APPL_CONST) Qom_ChannelConfigPtr;
P2CONST(Qom_NotifyTableItemType, ETPU_CONST, ETPU_APPL_CONST) Qom_GetStaNotifyTable;

} etpu_channel_qom_config_t;

/* Function Configuration Information */
#define FS_ETPU_QOM_FUNCTION_NUMBER 2
#define FS_ETPU_QOM_TABLE_SELECT 0
#define FS_ETPU_QOM_NUM_PARMS 0x18


/* Time Reference Mode Bits - first_match_mode options */
#define FS_ETPU_QOM_IMMEDIATE 0
#define FS_ETPU_QOM_USE_LAST_EVENT 1
#define FS_ETPU_QOM_USE_REF_ADDRESS 3

/* Host Service Request Definitions - init_pin options */
#define FS_ETPU_QOM_INIT_PIN_LOW_LINK 2
#define FS_ETPU_QOM_INIT_PIN_HIGH_LINK 3
#define FS_ETPU_QOM_INIT_PIN_NO_CHANGE_LINK 4
#define FS_ETPU_QOM_INIT_PIN_LOW 5
#define FS_ETPU_QOM_INIT_PIN_HIGH 6
#define FS_ETPU_QOM_INIT_PIN_NO_CHANGE 7

/* Function Mode Bit Definitions - mode options */
#define FS_ETPU_QOM_SINGLE_SHOT 0
#define FS_ETPU_QOM_LOOP 1
#define FS_ETPU_QOM_CONTINUOUS 2
#define FS_ETPU_QOM_CONTINUOUS_A 3

/* Parameter Definitions */
#define FS_ETPU_QOM_TABLE_START_PTR_OFFSET 0x1
#define FS_ETPU_QOM_TABLE_END_PTR_OFFSET 0x5
#define FS_ETPU_QOM_LAST_MATCH_TIME_OFFSET 0x9
#define FS_ETPU_QOM_LOOP_COUNT_OFFSET 0x0
#define FS_ETPU_QOM_OPTION_OFFSET 0x4
#define FS_ETPU_QOM_REF_ADDR_PTR_OFFSET 0xd

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
int32_t ETPU_LLD_QOM_INIT (uint8 etpuGroup, uint8 channel, uint8 priority, uint8 mode,
                          uint8 timebase, uint8 init_pin,
                          uint8 first_match_mode, uint32 * ref, uint8 Loop,
                          uint8 event_array_size,
                          const union etpu_events_array * const event_array);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void  ETPU_LLD_QOM_SetClose(uint8 etpuGroup, uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint32 ETPU_LLD_QOM_GetState(uint8 etpuGroup, uint8 channel);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#endif /* QOM_LLDRIVERS_H_ */
#endif
#endif
