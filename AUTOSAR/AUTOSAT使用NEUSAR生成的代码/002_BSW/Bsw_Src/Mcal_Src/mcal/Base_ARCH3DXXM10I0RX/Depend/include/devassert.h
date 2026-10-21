/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx dev assert define
* HISTORY     : Initial version
* @file     devassert.h
* @version  3.0.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
#ifndef DEVASSERT_H
#define DEVASSERT_H

#include <stdbool.h>
#include "compiler_api.h"

#if defined (CUSTOM_DEVASSERT)
    /* If the CUSTOM_DEVASSERT symbol is defined, then add the custom implementation */
    #include CUSTOM_DEVASSERT
#elif defined (DEV_ERROR_DETECT)
    /* Implement default assert macro */

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
static inline void DevAssert(volatile bool x)/*PRQA S 3006*/
{
    if(x) { } else { BKPT_ASM; for(;;) {} }/*PRQA S 3344,1006*/
}
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

    #define DEV_ASSERT(x) DevAssert(x)
#else
    /* Assert macro does nothing */
    #define DEV_ASSERT(x) ((void)0)
#endif

#endif /* DEVASSERT_H */
