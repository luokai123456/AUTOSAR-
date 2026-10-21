/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : OS
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Os_counter_api.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Os MCAL driver.
*
*   @addtogroup Os
*   @{
*/
#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Os.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
OS_START_SEC_CODE
StatusType8 GetCounterValue (CounterType ctrId, TickRefType tickRef)
{
    (void)ctrId;
    (void)tickRef;
    return (StatusType8)0;
}
OS_STOP_SEC_CODE

OS_START_SEC_CODE
StatusType8 GetElapsedValue (CounterType ctrId, TickRefType valueRef, TickRefType tickRef)
{
    (void)ctrId;
    (void)valueRef;
    (void)tickRef;
    return (StatusType8)0;
}
OS_STOP_SEC_CODE

#ifdef __cplusplus
}
#endif

/** @} */

