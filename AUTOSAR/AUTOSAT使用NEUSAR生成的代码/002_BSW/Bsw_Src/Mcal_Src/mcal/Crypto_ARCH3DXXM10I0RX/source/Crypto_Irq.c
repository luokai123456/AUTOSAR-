/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Crypto
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
*   @file    Crypto_Irq.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/
/* PRQA S 0380 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Crypto_Irq.h"

/*!
 * @brief HSM Interrupt Handler.
 */

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) ISR_HSM_MOUDLE_0(void)
{
	HSM_LLD_IRQHandler(0);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) ISR_HSM_MOUDLE_1(void)
{
	HSM_LLD_IRQHandler(1);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) ISR_HSM_MOUDLE_2(void)
{
	HSM_LLD_IRQHandler(2);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) ISR_HSM_MOUDLE_3(void)
{
	HSM_LLD_IRQHandler(3);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) ISR_HSM_MOUDLE_4(void)
{
	HSM_LLD_IRQHandler(4);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) ISR_HSM_MOUDLE_5(void)
{
	HSM_LLD_IRQHandler(5);
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"




#ifdef __cplusplus
}
#endif

/** @} */
