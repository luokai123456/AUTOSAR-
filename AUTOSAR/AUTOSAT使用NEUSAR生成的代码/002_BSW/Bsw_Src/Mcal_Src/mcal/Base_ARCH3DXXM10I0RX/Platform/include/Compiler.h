/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Compiler.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer MCAL driver.
*
*   @addtogroup COMPILER
*   @{
*/

#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Compiler_Cfg.h"

#define AUTOMATIC
#define TYPEDEF
#define NULL_PTR                                    ((void *)0)
#define INLINE                                      __inline__
#define LOCAL_INLINE                                static __inline__
#define FUNC(rettype, memclass)                     rettype
#define P2VAR(ptrtype, memclass, ptrclass)          ptrtype *
#define P2P2VAR(ptrtype, memclass, ptrclass)        ptrtype **
#define P2CONST(ptrtype, memclass, ptrclass)        const ptrtype *
#define CONSTP2VAR(ptrtype, memclass, ptrclass)     ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass)   const ptrtype * const
#define P2FUNC(rettype, ptrclass, fctname)          rettype (*fctname)
#define CONST(consttype, memclass)                  const consttype
#define VAR(vartype, memclass)                      vartype

#ifdef __cplusplus
}
#endif
#endif 
