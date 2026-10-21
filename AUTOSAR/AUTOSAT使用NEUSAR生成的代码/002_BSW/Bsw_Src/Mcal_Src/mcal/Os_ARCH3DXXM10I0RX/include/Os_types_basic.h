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
*   @file    Os_types_basic.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Os MCAL driver.
*
*   @addtogroup Os
*   @{
*/

#ifndef OS_TYPES_BASIC_H
#define OS_TYPES_BASIC_H


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include    "Std_Types.h"        /**< Standard type header - from MCAL  */

/*
 * only the basic types
 */



typedef unsigned short OSWORD16;

typedef unsigned int OSDWORD32;

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_TYPES_BASIC_H */

/** @} */
