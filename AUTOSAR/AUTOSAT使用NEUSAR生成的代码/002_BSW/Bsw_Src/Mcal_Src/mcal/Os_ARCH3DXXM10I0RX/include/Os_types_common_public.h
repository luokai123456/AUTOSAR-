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
*   @file    Os_types_common_public.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Os MCAL driver.
*
*   @addtogroup Os
*   @{
*/

/* PRQA S 2053,1535 EOF */

#ifndef OS_TYPES_COMMON_PUBLIC_H_
#define OS_TYPES_COMMON_PUBLIC_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include "Os_types_basic.h"

#define OSFALSE         (0U)
#define OSTRUE          (1U)

/*
 *  types required by the Autosar API
 */



/* avoid collision with MCAL */
#ifndef STATUSTYPEDEFINED
/* prescribed by OSEK/VDX */
#define STATUSTYPEDEFINED       /* required by OSEK/VDX Binding Specification */


typedef unsigned char StatusType8;       /* OSEK: Status type             */

#endif /* !defined(STATUSTYPEDEFINED) */


typedef OSWORD16 OSObjectType;            /* bits [15] - Core Id, bits [14..11] - ObjType, bits [10..0] - ObjId, */

typedef OSObjectType TaskType;          /* used in task, events api ... */

typedef OSDWORD32 TickType;               /* Type for timers ticks - use by counter, alarm, schedule table alarm */
typedef TickType  const *TickRefType;         /* OSEK: Reference to counter value - use by counter and alarm */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_TYPES_COMMON_PUBLIC_H_ */

/** @} */

