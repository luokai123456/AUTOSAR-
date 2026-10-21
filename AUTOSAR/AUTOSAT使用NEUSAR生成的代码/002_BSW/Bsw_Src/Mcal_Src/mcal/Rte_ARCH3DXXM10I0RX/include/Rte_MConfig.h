/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : RTE
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Rte_MConfig.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Rte MCAL driver.
*
*   @addtogroup Rte
*   @{
*/
#ifndef RTE_MCONFIG_H
#define RTE_MCONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Std_Types.h"
/*===================================================================================================
 *                                       INCLUDE FILES
 ====================================================================================================*/

/*===================================================================================================
 *                                       LOCAL MACROS
 ====================================================================================================*/
#define RTE_SEM42_TIMEOUT_ENABLE            STD_OFF
#define RTE_ADC_SEMA42_GATE_ID              0UL
#define RTE_PWM_SEMA42_GATE_ID              1UL
#define RTE_ICU_SEMA42_GATE_ID              2UL
#define RTE_GPT_SEMA42_GATE_ID              3UL
#define RTE_DIO_SEMA42_GATE_ID              4UL
#define RTE_LIN_SEMA42_GATE_ID              5UL
#define RTE_FLS_SEMA42_GATE_ID              15UL
#define RTE_FEE_SEMA42_GATE_ID              15UL
#define RTE_CAN_SEMA42_GATE_ID              6UL
#define RTE_ETH_SEMA42_GATE_ID              7UL
#define RTE_I2C_SEMA42_GATE_ID              8UL
#define RTE_WDG_SEMA42_GATE_ID              15UL
#define RTE_SPI_SEMA42_GATE_ID              9UL
#define RTE_MCU_SEMA42_GATE_ID              15UL
#define RTE_EDMA_SEMA42_GATE_ID             15UL
#define RTE_RTC_SEMA42_GATE_ID              15UL
#define RTE_PSI5_SEMA42_GATE_ID             15UL
#define RTE_SENT_SEMA42_GATE_ID             15UL
#define RTE_PORT_SEMA42_GATE_ID             10UL
#define RTE_DEFAULT_SEMA42_GATE_ID          15UL

#define RTE_SEM42_GATE_TIMEOUT              100UL

#define MULTICORE_TYPE_SPINLOCK             0UL
#define MULTICORE_TYPE_EXCLUSIVE            1UL
#define MULTICORE_TYPE_SEMAPHORE            2UL

/*===================================================================================================
 *                                       LOCAL CONSTANTS
 ====================================================================================================*/
/*===================================================================================================
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ====================================================================================================*/
typedef volatile uint16 guard_type;

/* SEM42GATE_TIMEOUT_HOOK function type declared */
typedef void (*semTimeOutCallback)(uint8 gate);
/*===================================================================================================
 *                                       LOCAL VARIABLES
 ====================================================================================================*/
#define GUARD_TYPE_SIZE                     2UL
#define RTE_SEM42GATE_TIMEOUT_HOOK          NULL_PTR
/*===================================================================================================
 *                                       FUNCTION PROTOTYPES
 ====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* RTE_MCONFIG_H */

