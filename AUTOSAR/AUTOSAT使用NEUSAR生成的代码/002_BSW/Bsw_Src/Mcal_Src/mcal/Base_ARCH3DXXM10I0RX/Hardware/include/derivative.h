/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     derivative.h
* @version  1.0
* @date     2023 - 04 - 17
* @brief    Initial version.
*
*****************************************************************************/

#ifndef DERIVATIVE_H_
#define DERIVATIVE_H_
/* Include the derivative-specific header file */

#if defined(CCFC3007PT)
    #define CHIP_TYPE   0x37000000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #define CHIP_TYPE2  0x37100000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3007PT.h"

    /* Specific feature definitions */
    #include "CCFC3007PT_features.h"
#elif defined(CCFC3007BC)
    #define CHIP_TYPE   0x37B00000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3007BC.h"

    /* Specific feature definitions */
    #include "CCFC3007BC_features.h"
#elif defined(CCFC3008PT)
    #define CHIP_TYPE   0x38000000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #define CHIP_TYPE2  0x38100000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3008PT.h"

    /* Specific feature definitions */
    #include "CCFC3008PT_features.h"
#elif defined(CCFC3008PC)
    #define CHIP_TYPE   0x38C00000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3008PC.h"

    /* Specific feature definitions */
    #include "CCFC3008PC_features.h"
#elif defined(CCFC3008PCSN)
    #define CHIP_TYPE   0x38D00000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3008PCSN.h"

    /* Specific feature definitions */
    #include "CCFC3008PCSN_features.h"
#elif defined(CCFC3008PCSA)
    #define CHIP_TYPE   0x38A00000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3008PCSA.h"

    /* Specific feature definitions */
    #include "CCFC3008PCSA_features.h"
#elif defined(CCFC3010PTD)
    #define CHIP_TYPE   0x3A100000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3010PTD.h"

    /* Specific feature definitions */
    #include "CCFC3010PTD_features.h"
#elif defined(CCFC3010PT)
    #define CHIP_TYPE   0x3A000000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3010PT.h"

    /* Specific feature definitions */
    #include "CCFC3010PT_features.h"
#elif defined(CCFC3011PT)
    #define CHIP_TYPE   0x3B000000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3011PT.h"

    /* Specific feature definitions */
    #include "CCFC3011PT_features.h"
#elif defined(CCFC3012PT)
    #define CHIP_TYPE   0x3C000000UL    /* CHIP_TYPE_MASK: 0xFFF00000UL */
    #include "CCFC3012PT.h"

    /* Specific feature definitions */
    #include "CCFC3012PT_features.h"
#else
    #error "No valid CPU defined!"
#endif

#include "devassert.h"

#endif  /* DERIVATIVE_H_ */
