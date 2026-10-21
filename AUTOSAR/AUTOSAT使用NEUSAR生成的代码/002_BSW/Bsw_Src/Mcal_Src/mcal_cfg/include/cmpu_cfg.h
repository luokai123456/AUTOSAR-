/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : MPU
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*  
*****************************************************************************/

/**
*   @file    cmpu_cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of cmpu MCAL driver.
*
*   @addtogroup cmpu
*   @{
*/
/* PRQA S 3684,0883 EOF */
#ifdef MPU_ENABLE

#ifndef CMPU_CFG_H_
#define CMPU_CFG_H_

#include "mpu_lldriver.h"

extern cmpu_module_cfg_t cmpu_Cfg;
extern cmpu_entry_cfg_t cmpu_EntryArray[];

#endif /* CMPU_CFG_H_ */

#endif /* MPU_ENABLE */
