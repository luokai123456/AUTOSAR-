/****************************************************************************
*
* Copyright (c) 2026  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     Adc_Types.h
* @version  1.0
* @date     2026 - 03 - 26
* @brief    Initial version.
*
*****************************************************************************/

#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_
/* Include the adc-specific header file */

#if defined(CCFC3007PT)
    #include "Adc_Types_CCFC3007PT.h"

#elif defined(CCFC3007BC)
    #include "Adc_Types_CCFC3007BC.h"

#elif defined(CCFC3008PT)
    #include "Adc_Types_CCFC3008PT.h"

#elif defined(CCFC3008PC)
    #include "Adc_Types_CCFC3008PC.h"

#elif defined(CCFC3008PCSN)
    #include "Adc_Types_CCFC3008PCSN.h"

#elif defined(CCFC3008PCSA)
    #include "Adc_Types_CCFC3008PCSA.h"

#elif defined(CCFC3010PTD)
    #include "Adc_Types_CCFC3010PTD.h"

#elif defined(CCFC3010PT)
    #include "Adc_Types_CCFC3010PT.h"

#elif defined(CCFC3011PT)
    #include "Adc_Types_CCFC3011PT.h"

#elif defined(CCFC3012PT)
    #include "Adc_Types_CCFC3012PT.h"

#elif defined(CCFC3009PT)
    #include "Adc_Types_CCFC3009PT.h"

#else
    #error "No valid Adc_Types defined!"
#endif

#endif  /* ADC_TYPES_H_ */
