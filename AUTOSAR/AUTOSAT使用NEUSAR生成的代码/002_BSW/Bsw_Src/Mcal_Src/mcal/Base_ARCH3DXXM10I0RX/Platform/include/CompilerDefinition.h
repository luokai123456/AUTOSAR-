/**
* @file CompilerDefinition.h
* @version 3.0.0
**@brief   AUTOSAR Base - SWS Compiler abstraction.
* @details The file Compiler.h provides macros for the encapsulation of definitions and
*          declarations
* @addtogroup
* @{
*/
/****************************************************************************
*
* Copyright (c) 2022  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           :
*   Dependencies         :
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/
/*PRQA S 844 EOF*/
/**
*   @file    CompilerDefinition.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details SWS Compiler abstraction.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/

#ifndef COMPILERDEFINITION_H
#define COMPILERDEFINITION_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/

/*===================================================================================================
*                                       LOCAL MACROS
====================================================================================================*/
#ifdef __S32DS__
/**
* @brief Symbol required to be defined when S32DS for Power PC compiler is used.
*/
#define S32DS_C_CCFC30XX
#endif

#ifdef __ghs__
/**
* @brief Symbol required to be defined when GreenHills compiler is used.
*/
#define GHS_C_CCFC30XX
#endif

#ifdef __DCC__
/**
* @brief Symbol required to be defined when DiabData compiler is used.
*/
#define DCC_C_CCFC30XX
#endif

#ifdef __MWERKS__
/**
* @brief Symbol required to be defined when CodeWarrior compiler is used.
*/
#define MWERKS_C_CCFC30XX
#endif

#ifdef __CSMC__
/**
* @brief Symbol required to be defined when Cosmic compiler is used.
*/
#define CSMC_C_CCFC30XX
#endif

#ifdef __LINARO__
/**
* @brief Symbol required to be defined when Linaro compiler is used.
*/
#define LINARO_C_CCFC30XX
#endif

#if (defined(__GNUC__) && !defined(__S32DS__) && !defined(__DCC__))
/**
* @brief Symbol required to be defined when Hitech compiler is used.
*/
#define HITECH_C_CCFC30XX
#endif

#ifdef __CC_ARM
/**
* @brief Symbol required to be defined when DS5 compiler is used.
*/
#define DS5_C_CCFC30XX
#endif

#ifdef __ICCARM__
/**
* @brief Symbol required to be defined when IAR compiler is used.
*/
#define IAR_C_CCFC30XX
#endif

#ifdef __cplusplus
}
#endif

#endif 

