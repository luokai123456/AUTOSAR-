/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Mcu
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
*   @file    Mcu_Types.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifndef MCU_TYPES_H_
#define MCU_TYPES_H_

#if defined(CCFC3007PT)

    #include "Mcu_Types_CCFC3007PT.h"

#elif defined(CCFC3007BC)

    #include "Mcu_Types_CCFC3007BC.h"

#elif defined(CCFC3008PT)

    #include "Mcu_Types_CCFC3008PT.h"

#elif defined(CCFC3008PC)

    #include "Mcu_Types_CCFC3008PC.h"

#elif defined(CCFC3008PCSN)

    #include "Mcu_Types_CCFC3008PCSN.h"

#elif defined(CCFC3008PCSA)

    #include "Mcu_Types_CCFC3008PCSA.h"

#elif defined(CCFC3010PTD)

    #include "Mcu_Types_CCFC3010PTD.h"

#elif defined(CCFC3010PT)

    #include "Mcu_Types_CCFC3010PT.h"

#elif defined(CCFC3011PT)

    #include "Mcu_Types_CCFC3011PT.h"

#elif defined(CCFC3012PT)

    #include "Mcu_Types_CCFC3012PT.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* MCU_TYPES_H_ */
