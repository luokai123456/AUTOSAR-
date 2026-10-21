/**************************************************************************** 
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
*   @file    QOM_LLDrivers.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of QOM MCAL driver.
*
*   @addtogroup QOM
*   @{
*/
/* PRQA S 2052 EOF */

#ifdef __cplusplus
extern "C"{
#endif

#include "eTPU_LLDrivers.h"       /* PRQA S 0380 */
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "eTPU_Cfg.h"             /* PRQA S 0380 */
#include "QOM_LLDrivers.h"        /* eTPU PPA API */

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define QOM_LLDRIVERS_VENDOR_ID_C                   176

#define QOM_LLDRIVERS_MAJOR_VER_C                   4
#define QOM_LLDRIVERS_MINOR_VER_C                   4
#define QOM_LLDRIVERS_REVISION_VER_C                0

#define QOM_LLDRIVERS_SW_MAJOR_VER_C                3
#define QOM_LLDRIVERS_SW_MINOR_VER_C                0
#define QOM_LLDRIVERS_SW_PATCH_VER_C                0

#if (QOM_LLDRIVERS_VENDOR_ID_C != QOM_LLDRIVERS_VENDOR_ID_H)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_VENDOR_ID_C"
#endif

/* Check if current file and EBPPA header file are of the same Autosar version */
#if (QOM_LLDRIVERS_MAJOR_VER_C != QOM_LLDRIVERS_MAJOR_VER_H)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_MAJOR_VER_C"
#endif
#if (QOM_LLDRIVERS_MINOR_VER_C != QOM_LLDRIVERS_MINOR_VER_H)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_MINOR_VER_C"
#endif
#if (QOM_LLDRIVERS_REVISION_VER_C != QOM_LLDRIVERS_REVISION_VER_H)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_REVISION_VER_C"
#endif

/* Check if current file and EBPPA header file are of the same Software version */
#if (QOM_LLDRIVERS_SW_MAJOR_VER_C != QOM_LLDRIVERS_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_SW_MAJOR_VER_C"
#endif
#if (QOM_LLDRIVERS_SW_MINOR_VER_C != QOM_LLDRIVERS_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_SW_MINOR_VER_C"
#endif
#if (QOM_LLDRIVERS_SW_PATCH_VER_C != QOM_LLDRIVERS_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : QOM_LLDRIVERS_SW_PATCH_VER_C"
#endif

#if ((ETPU_QOM_INSTANCE_NUM != 0U)&&(QOM_MODULE_ENABLE !=STD_OFF))
/******************************************************************************
FUNCTION     : fs_etpu_qom_init
PURPOSE      : To initialize an eTPU channel to generate a QOM output.
INPUTS NOTES : This function has 10 parameters:
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
              priority - This is the priority to assign to the channel.
                         This parameter should be assigned a value of:
                         ETPU_PRIORITY_HIGH, ETPU_PRIORITY_MIDDLE or
                         ETPU_PRIORITY_LOW.
                  mode - This define the repeat mode for the channel
                         This parameter should be assigned a value of:
                         FS_ETPU_QOM_SINGLE_SHOT,
                         FS_ETPU_QOM_LOOP,
                         FS_ETPU_QOM_CONTINUOUS
                         FS_ETPU_QOM_CONTINUOUS_A
              timebase - This is the timer to use as a reference for the QOM
                         signal. This parameter should be assigned to a value
                         of: ETPU_TCR1 or ETPU_TCR2.
              init_pin - The  state  the pin is driven to at initialisation.
               		       This parameter should be assigned a value of:
                         FS_ETPU_QOM_INIT_PIN_LOW, FS_ETPU_QOM_INIT_PIN_HIGH or
                         FS_ETPU_QOM_INIT_PIN_NO_CHANGE.
                         To initialise the channel to recieve a link the
                         parameter takes the value of :
                         FS_ETPU_QOM_INIT_PIN_LOW_LINK,
                         FS_ETPU_QOM_INIT_PIN_HIGH_LINK,
                         FS_ETPU_QOM_INIT_PIN_NO_CHANGE_LINK.
      first_match_mode - This is the reference mode for the first match
                         This parameter should be assigned a value of:
			                   FS_ETPU_QOM_IMMEDIATE,
			                   FS_ETPU_QOM_USE_LAST_EVENT,
			                   FS_ETPU_QOM_USE_REF_ADDRESS
                   ref - This is the address of the reference when
                         first_match_mode==FS_ETPU_QOM_USE_REF_ADDRESS
                  loop - the number of iterations in loop mode
      event_array_size - the number of entries in the event array
           event_array - a structure containing the event table
RETURNS NOTES: Error code if channel could not be initialized. Error code that
                 can be returned is: FS_ETPU_ERROR_MALLOC
WARNING      : *This function does not configure the pin, only the eTPU. In a
                  system a pin may need to be configured to select the eTPU.
******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
int32_t ETPU_LLD_QOM_INIT (uint8 etpuGroup, uint8 channel, uint8 priority, uint8 mode,
                          uint8 timebase, uint8 init_pin,
                          uint8 first_match_mode, uint32 * ref, uint8 Loop,
                          uint8 event_array_size,
                          const union etpu_events_array * const event_array)
{
    uint32 *pba;              /*parameter base address for channel */
    uint32 *pba_array;        /*parameter base address for match table */
    uint32 *Table_Start_Ptr;
    uint32 *Table_End_Ptr;
    uint16 event_array_size_rounded;
    uint16 x, x2;
    uint8 Option;
    uint8 channel_reuse = 0;
    uint8 *pba8;

    /* disable channel before changing anything else */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPR = 0U;

    /*generate option */
    Option = 0U;                 /*clear out any erroneous data */
    Option = (uint8)(timebase << 7U | first_match_mode);

    /*only get parameter RAM if the channel has not been used before */
    if (eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA == 0)
    {
        /* get parameter RAM number of parameters passed from eTPU C code */
        pba = ETPU_LLD_Malloc_32 (etpuGroup, FS_ETPU_QOM_NUM_PARMS);
        if (pba == 0)
        {
            return (ETPU_ERROR_MALLOC);
        }
    }
    else  /*set pba to what is in the CR register */
    {
        channel_reuse = 1U;
        //  pba = fs_etpu_data_ram (channel);
      	pba = (uint32*)((uint8*)eTPUInstance[etpuGroup].data_ram_start + \
            (eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3U));
    }
    /* Set the table start pointer variable so that the pointer is relative to the
    eTPU address map .The queue data begins after the parameter data. */
    Table_Start_Ptr = pba + (FS_ETPU_QOM_NUM_PARMS) / 4 - \
        (uint32) ((uint32 *) ((eTPUInstance[etpuGroup].data_ram_start) / 4));
    Table_End_Ptr = Table_Start_Ptr + (event_array_size - 1);

    pba8 = (uint8 *) pba;

    /*write parameters*/
    if (first_match_mode == FS_ETPU_QOM_USE_REF_ADDRESS)
    {
        /*only write reference pointer if using that mode. */
        *(pba + ((FS_ETPU_QOM_REF_ADDR_PTR_OFFSET - 1) >> 2)) = (uint32) ref;
    }

    /*only write new Table pointer if not running in last match time mode. */
    *(pba + ((FS_ETPU_QOM_TABLE_START_PTR_OFFSET - 1) >> 2)) = (uint32) (Table_Start_Ptr);
    *(pba + ((FS_ETPU_QOM_TABLE_END_PTR_OFFSET - 1) >> 2)) = (uint32) (Table_End_Ptr);

    *(pba8 + FS_ETPU_QOM_LOOP_COUNT_OFFSET) = (uint8) Loop;
    *(pba8 + FS_ETPU_QOM_OPTION_OFFSET) = (uint8) Option;

    if (channel_reuse == 0U)
    {
        /* get parameter RAM
            for the Event Table

            following code ensures that the pba ends up on a times 8 
            boundary; so if the user requests an odd event_array_size there
            will be 1 wasted 32bit PRAM location. */

        x2 = (uint16)(event_array_size + 1U);
        x2 = (uint16)(x2 >> 1U);
        event_array_size_rounded = (uint16)(x2 << 1U);
        pba_array = ETPU_LLD_Malloc_32 (etpuGroup, (uint16)(event_array_size_rounded << 2U));

        if (pba_array == 0)
        {
            return (ETPU_ERROR_MALLOC);
        }
    }
    else /* re-using parameter RAM which has already been allocated */
    {
        pba_array = (pba + (FS_ETPU_QOM_NUM_PARMS) / 4);
    }

    /*write event table*/
    for (x = 0; x < event_array_size; x++)
    {
        *(pba_array + x) = event_array[x].p;
    }

    /*write hsr*/
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = init_pin;

    eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.R = (mode);

    /*write chan config register */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.R =
        (priority << 28) + (FS_ETPU_QOM_TABLE_SELECT << 24) +
        (FS_ETPU_QOM_FUNCTION_NUMBER << 16) + (((uint32)pba -
        		eTPUInstance[etpuGroup].data_ram_start) >> 3);

    return (0);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_QOM_SetClose(uint8 etpuGroup, uint8 channel)
{
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPR = 0U;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint32 ETPU_LLD_QOM_GetState(uint8 etpuGroup, uint8 channel)
{
    uint32 CPR = eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.B.HSR;
    return CPR;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif
#endif
