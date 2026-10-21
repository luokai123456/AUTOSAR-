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
*   @file    Os_counter_types.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Os MCAL driver.
*
*   @addtogroup Os
*   @{
*/

#ifndef OS_COUNTER_TYPES_H_
#define OS_COUNTER_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "Os_types_basic.h"     /* for OSDWORD32  */
#include "Os_types_common_public.h"     /* for OSObjectType */

typedef OSObjectType CounterType;

#ifdef __cplusplus
}
#endif

#endif /*OS_COUNTER_TYPES_H_ */

/** @} */
