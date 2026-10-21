/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : common h file
* HISTORY     : Initial version
* @file     common.h
* @version  3.0.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/
#ifndef COMMON_INC_COMMON_H_
#define COMMON_INC_COMMON_H_

#include "typedefs.h"
/*===================================================================================================
 *                                       LOCAL MEMMAP
 ====================================================================================================*/

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
 void cc_memcpy(uint8_t *dest, const uint8_t *src, const uint32_t bytes);
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
 void cc_memset(uint8_t *dest, const uint8_t val, const uint32_t bytes);
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
 uint8_t cc_memcmp(const uint8_t *src1, const uint8_t *src2, uint32_t len);
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
 uint32_t cc_strlen(const uint8_t * s);
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
 uint8_t halfword_swap(const uint8_t * src, uint8_t * dest, uint32_t n);
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
 void delay(volatile uint32_t x);
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
 void delay_ms(uint32_t ms);
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#endif /* COMMON_INC_COMMON_H_ */
