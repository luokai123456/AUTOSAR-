/**************************************************************************** 
*
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETPU
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
*   @file    sPwm_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of sPwm MCAL driver.
*
*   @addtogroup sPwm
*   @{
*/

#ifndef SPWM_LLDRIVERS_H_
#define SPWM_LLDRIVERS_H_

/*******************************************************************************
* Includes
*******************************************************************************/

#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "eTPU_Cfg.h"
#include "status.h"

#define SPWM_LLD_WRA_H_VENDOR_ID                     176
#define SPWM_LLD_WRA_H_AR_REL_MAJOR_VER              4
#define SPWM_LLD_WRA_H_AR_REL_MINOR_VER              4
#define SPWM_LLD_WRA_H_AR_REL_REV_VER                0
#define SPWM_LLD_WRA_H_SW_MAJOR_VER                  3
#define SPWM_LLD_WRA_H_SW_MINOR_VER                  0
#define SPWM_LLD_WRA_H_SW_PATCH_VER                  0

#if (ETPU_VENDOR_ID_OUTPUT != SPWM_LLD_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_H_VENDOR_ID "
#endif
#if (ETPU_AR_REL_MAJOR_VER_OUTPUT != SPWM_LLD_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (ETPU_AR_REL_MINOR_VER_OUTPUT != SPWM_LLD_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_H_AR_REL_MINOR_VER "
#endif
#if (ETPU_AR_REL_REVISION_VER_OUTPUT != SPWM_LLD_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_H_AR_REL_REV_VER "
#endif
#if (ETPU_SW_MAJOR_VERSION_OUTPUT != SPWM_LLD_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_H_SW_MAJOR_VER "
#endif
#if (ETPU_SW_MINOR_VERSION_OUTPUT != SPWM_LLD_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_H_SW_MINOR_VER "
#endif
#if (ETPU_SW_PATCH_VERSION_OUTPUT != SPWM_LLD_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SPWM_LLD_WRA_H_SW_PATCH_VER "
#endif
#if ((SPWM_MASTER_NUM != 0U)&&(SPWM_MODULE_ENABLE !=STD_OFF))
/* Function Configuration Information */
#define ETPU_SPWM_FUNCTION_NUMBER 3
#define ETPU_SPWM_TABLE_SELECT 1
#define ETPU_SPWM_NUM_PARMS 0x30


/* Host Service Request Definitions */
#define ETPU_SPWM_INIT_MASTER 7
#define ETPU_SPWM_INIT_SLAVE 5

/* Function Mode Bit Definitions - polarity options */
#define ETPU_SPWM_USE_TCR1 0 << 1
#define ETPU_SPWM_USE_TCR2 1 << 1
/* INT_DMA_on_falling_edge options */
#define ETPU_SPWM_NO_FALL_EDGE_INT_DMA 0
#define ETPU_SPWM_FALLING_EDGE_INT_DMA 1

/* Parameter Definitions */
#define ETPU_SPWM_PERIOD_OFFSET 0x1
#define ETPU_SPWM_ACTIVE_OFFSET 0x5
#define ETPU_SPWM_REF_PTR_OFFSET 0x9
#define ETPU_SPWM_DELAY_OFFSET 0xd
#define ETPU_SPWM_LINK1_OFFSET 0x10
#define ETPU_SPWM_LINK2_OFFSET 0x14
#define ETPU_SPWM_MASTERRISINGEDGEPTR 0x1d
#define ETPU_SPWM_REF_MODE 0x0
#define ETPU_SPWM_REFERENCE 0x21

/* This parameter is not host modifable but the address is exported so the slave can reference it*/
#define ETPU_SPWM_RISING_OFFSET 0x19

/* reference_mode options */
#define ETPU_SPWM_IMMEDIATE 0
#define ETPU_SPWM_REF_IN_PRAM 1
typedef struct {
    VAR(uint8, AUTOMATIC) etpuGroup;
    VAR(uint8, AUTOMATIC) channel;
    VAR(uint8, AUTOMATIC) priority;
    VAR(uint32, AUTOMATIC) freq;
    VAR(uint16, AUTOMATIC) duty;
    VAR(uint32, AUTOMATIC) cnl_delay;
    VAR(uint8, AUTOMATIC) timebase;
    VAR(uint32, AUTOMATIC) timebase_freq;
    VAR(uint32, AUTOMATIC) master_flag;
} spwm_channel_t;

typedef struct {      
    VAR(uint8, AUTOMATIC) etpuGroup;
    VAR(uint8, AUTOMATIC) channel;
    VAR(uint32, AUTOMATIC) freq;
    VAR(uint16, AUTOMATIC) duty;
    VAR(uint8, AUTOMATIC) timebase;
    VAR(uint32, AUTOMATIC) timebase_freq;
    VAR(uint8, AUTOMATIC) reference_mode;
    P2VAR(uint32, AUTOMATIC, ETPU_APPL_DATA) reference_ptr;
    VAR(uint8, AUTOMATIC) INT_DMA_on_falling_edge;
    VAR(uint32, AUTOMATIC) link1;
    VAR(uint32, AUTOMATIC) link2;  
    const spwm_channel_t *spwm_channel_config;
    VAR(uint32, AUTOMATIC) channel_count; 
} spwm_master_t;

typedef struct
{
    CONST(uint8, AUTOMATIC)     channel;
    CONST(uint32, AUTOMATIC)    sPwm_CoreId;
} spwm_core_map_t;

typedef struct {        
    const spwm_master_t *spwm_master_config;
    P2CONST(spwm_core_map_t, SPWM_CONST, SPWM_APPL_CONST) mastercore_map;
    P2CONST(spwm_core_map_t, SPWM_CONST, SPWM_APPL_CONST) channelcore_map;
    const uint8 *slave_num;
} spwm_config_t;

/**************************************************************************/
/*                       Function Prototypes                              */
/**************************************************************************/

/* SPWM channel configuration : master */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(sint32, SPWM_CODE) ETPU_LLD_SPWM_Init_Master \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) freq, \
    VAR(uint16, AUTOMATIC) duty, \
    VAR(uint8, AUTOMATIC) timebase, \
    VAR(uint32, AUTOMATIC) timebase_freq, \
    VAR(uint8, AUTOMATIC) reference_mode, \
    P2VAR(uint32, AUTOMATIC, SPWM_APPL_DATA) reference_ptr, \
    VAR(uint8, AUTOMATIC) INT_DMA_on_falling_edge, \
    VAR(uint32, AUTOMATIC) link1, \
    VAR(uint32, AUTOMATIC) link2 \
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
                                  
/* SPWM channel run : master */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, SPWM_CODE) ETPU_LLD_SPWM_Run_Master \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) priority
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/* SPWM channel initialization : slave */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(sint32, SPWM_CODE) ETPU_LLD_SPWM_Init_Slave \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) priority, \
    VAR(uint32, AUTOMATIC) freq, \
    VAR(uint16, AUTOMATIC) duty, \
    VAR(uint32, AUTOMATIC) slave_delay, \
    VAR(uint8, AUTOMATIC) timebase, \
    VAR(uint32, AUTOMATIC) timebase_freq, \
    P2CONST(uint32, AUTOMATIC, SPWM_APPL_DATA) MasterFrameEdgePtr
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/* SPWM duty cycle update */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, SPWM_CODE) ETPU_LLD_SPWM_Duty \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint16, AUTOMATIC) duty \
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/* SPWM duty cycle and freq update */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(sint32, SPWM_CODE) ETPU_LLD_SPWM_Update_Master \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) freq, \
    VAR(uint16, AUTOMATIC) duty, \
    VAR(uint32, AUTOMATIC) timebase_freq \
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/* SPWM information */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, SPWM_CODE) ETPU_LLD_SPWM_Get_Freq_Master \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) timebase_freq \
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#endif /*SPWM_MASTER_NUM != 0*/
#endif 
#endif /* SPWM_LLDRIVERS_H_ */
