/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Adc
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
*   @file    Adc_Irq.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

#ifndef ADC_IRQ_H
#define ADC_IRQ_H

#include "Adc.h"

#define ADC_IRQ_H_VENDOR_ID                     176
#define ADC_IRQ_H_AR_REL_MAJOR_VER              4
#define ADC_IRQ_H_AR_REL_MINOR_VER              4
#define ADC_IRQ_H_AR_REL_REV_VER                0
#define ADC_IRQ_H_SW_MAJOR_VER                  3
#define ADC_IRQ_H_SW_MINOR_VER                  0
#define ADC_IRQ_H_SW_PATCH_VER                  0

#if (ADC_VENDOR_ID               != ADC_IRQ_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ADC_IRQ_H_VENDOR_ID "
#endif
#if (ADC_AR_REL_MAJOR_VER    != ADC_IRQ_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_IRQ_H_AR_REL_MAJOR_VER "
#endif
#if (ADC_AR_REL_MINOR_VER    != ADC_IRQ_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_IRQ_H_AR_REL_MINOR_VER "
#endif
#if (ADC_AR_REL_REV_VER != ADC_IRQ_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ADC_IRQ_H_AR_REL_REV_VER "
#endif
#if (ADC_SW_MAJOR_VER        != ADC_IRQ_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_IRQ_H_SW_MAJOR_VER "
#endif
#if (ADC_SW_MINOR_VER        != ADC_IRQ_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_IRQ_H_SW_MINOR_VER "
#endif
#if (ADC_SW_PATCH_VER        != ADC_IRQ_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ADC_IRQ_H_SW_PATCH_VER "
#endif

extern P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST) Adc_ConfigPtr[ADC_CORE_NUM];
extern VAR(Adc_RunningGroupType, ADC_VAR) sAdc_RunningGroup[ADC_CORE_NUM][ADC_CONFIG_GROUPS];
extern VAR(Adc_RunningHwUnitType, ADC_VAR) sAdc_RunningUnit[ADC_CORE_NUM][ADC_MAX_HW_UNITS];

#ifdef RESOURCE_SUPPORT_EQADC_INST0
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC01_GRP0(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC01_GRP1(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC01_GRP2(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC01_GRP3(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC01_GRP4(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC01_GRP5(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC01_GRP6(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC01_GRP7(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST0 */

#ifdef RESOURCE_SUPPORT_EQADC_INST1
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC23_GRP0(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC23_GRP1(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC23_GRP2(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC23_GRP3(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC23_GRP4(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC23_GRP5(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC23_GRP6(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC23_GRP7(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST1 */

#ifdef RESOURCE_SUPPORT_EQADC_INST2
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC45_GRP0(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC45_GRP1(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC45_GRP2(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC45_GRP3(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC45_GRP4(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC45_GRP5(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC45_GRP6(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC45_GRP7(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST2 */

#ifdef RESOURCE_SUPPORT_EQADC_INST3
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC67_GRP0(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC67_GRP1(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC67_GRP2(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC67_GRP3(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC67_GRP4(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC67_GRP5(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC67_GRP6(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC67_GRP7(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST3 */

#ifdef RESOURCE_SUPPORT_EQADC_INST4
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC89_GRP0(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC89_GRP1(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC89_GRP2(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC89_GRP3(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC89_GRP4(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC89_GRP5(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC89_GRP6(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC89_GRP7(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST4 */

#ifdef RESOURCE_SUPPORT_EQADC_INST5
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1011_GRP0(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1011_GRP1(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1011_GRP2(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1011_GRP3(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1011_GRP4(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1011_GRP5(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1011_GRP6(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1011_GRP7(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST5 */

#ifdef RESOURCE_SUPPORT_EQADC_INST6
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1213_GRP0(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1213_GRP1(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1213_GRP2(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1213_GRP3(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1213_GRP4(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1213_GRP5(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1213_GRP6(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1213_GRP7(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST6 */

#ifdef RESOURCE_SUPPORT_EQADC_INST0
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc0_DmaResult0 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc0_DmaResult1 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc0_DmaResult2 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc0_DmaResult3 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc0_DmaResult4 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc0_DmaResult5 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc0_DmaResult6 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc0_DmaResult7 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST0 */

#ifdef RESOURCE_SUPPORT_EQADC_INST1
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc1_DmaResult0 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc1_DmaResult1 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc1_DmaResult2 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc1_DmaResult3 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc1_DmaResult4 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc1_DmaResult5 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc1_DmaResult6 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc1_DmaResult7 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST1 */

#ifdef RESOURCE_SUPPORT_EQADC_INST2
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc2_DmaResult0 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc2_DmaResult1 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc2_DmaResult2 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc2_DmaResult3 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc2_DmaResult4 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc2_DmaResult5 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc2_DmaResult6 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc2_DmaResult7 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST2 */

#ifdef RESOURCE_SUPPORT_EQADC_INST3
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc3_DmaResult0 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc3_DmaResult1 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc3_DmaResult2 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc3_DmaResult3 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc3_DmaResult4 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc3_DmaResult5 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc3_DmaResult6 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc3_DmaResult7 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST3 */

#ifdef RESOURCE_SUPPORT_EQADC_INST4
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc4_DmaResult0 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc4_DmaResult1 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc4_DmaResult2 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc4_DmaResult3 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc4_DmaResult4 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc4_DmaResult5 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc4_DmaResult6 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc4_DmaResult7 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST4 */

#ifdef RESOURCE_SUPPORT_EQADC_INST5
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc5_DmaResult0 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc5_DmaResult1 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc5_DmaResult2 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc5_DmaResult3 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc5_DmaResult4 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc5_DmaResult5 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc5_DmaResult6 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc5_DmaResult7 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST5 */

#ifdef RESOURCE_SUPPORT_EQADC_INST6
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc6_DmaResult0 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc6_DmaResult1 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc6_DmaResult2 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc6_DmaResult3 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc6_DmaResult4 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc6_DmaResult5 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (RESOURCE_SUPPORT_EQADC_FIFO_CNT == RESOURCE_SUPPORT_EQADC_FIFO_CNT_8)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc6_DmaResult6 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Eqadc6_DmaResult7 \
( \
    P2CONST(void,             AUTOMATIC, ADC_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_FIFO_CNT */
#endif  /* RESOURCE_SUPPORT_EQADC_INST6 */

#ifdef RESOURCE_SUPPORT_EQADC_INST0
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC01_FISR_Overflow(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_INST0 */

#ifdef RESOURCE_SUPPORT_EQADC_INST1
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC23_FISR_Overflow(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_INST1 */

#ifdef RESOURCE_SUPPORT_EQADC_INST2
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC45_FISR_Overflow(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_INST2 */

#ifdef RESOURCE_SUPPORT_EQADC_INST3
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC67_FISR_Overflow(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_INST3 */

#ifdef RESOURCE_SUPPORT_EQADC_INST4
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC89_FISR_Overflow(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_INST4 */

#ifdef RESOURCE_SUPPORT_EQADC_INST5
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1011_FISR_Overflow(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_INST5 */

#ifdef RESOURCE_SUPPORT_EQADC_INST6
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) ADC1213_FISR_Overflow(void);
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_INST6 */

#endif /* ADC_IRQ_H */

/** @} */
