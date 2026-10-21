/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : common code
* HISTORY     : Initial version
* @file     common.c
* @version  3.0.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 488,3305,0311,0310,0498 EOF*/
#include "common.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
void cc_memcpy(uint8_t *dest, const uint8_t *src, const uint32_t bytes)
{
    uint32_t bytes_temp;
    uint8_t * dest_temp = NULL;
    uint8_t const * src_temp = NULL;

    bytes_temp = bytes;
    dest_temp = (uint8_t *)dest;
    src_temp = (uint8_t const *)src;

    while (bytes_temp > 0u)
    {
        *dest_temp = *src_temp;/* polyspace RTE:IDP,NIV */
        bytes_temp--;
        if (0u == bytes_temp)
        {
            break;
        }
        dest_temp++;
        src_temp++;
    }
}
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
void cc_memset(uint8_t *dest, const uint8_t val, const uint32_t bytes)
{
    uint32_t bytes_temp;
    uint8_t  * dest_temp = NULL;

    dest_temp = dest;
    bytes_temp = bytes;

    while (bytes_temp > 0u)
    {
        *dest_temp = val;/* polyspace RTE:IDP */
        bytes_temp--;
        if (0u == bytes_temp)
        {
            break;
        }
        dest_temp++;
    }
}
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
uint8_t cc_memcmp(const uint8_t *src1, const uint8_t *src2, uint32_t len)
{
    uint8_t const *p1 = NULL;
    uint8_t const *p2 = NULL;
    uint32_t len_temp = 0u;

    len_temp = len;
    p1 = src1;
    p2 = src2;

    do
    {
        if (*p1 != *p2)/* polyspace RTE:IDP */
        {
            return 1;
        }
        p1++;
        p2++;
        len_temp--;
    } while (len_temp != 0u);

    return 0;
}
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

/************************************************************************
 * @brief      high half-word and low half-word swap function every 4 byte(one word).
 * @param[in]  uint8_t * dest, const uint8_t * src, uint32_t bytes
 * @param[out] None
 * @notapi
 *************************************************************************/
#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
uint8_t halfword_swap(const uint8_t * src, uint8_t * dest, uint32_t n)
{
	uint32_t i;
	uint32_t * src_temp32 = NULL;
	uint32_t * dest_temp32 = NULL;
	uint32_t src_temp32_H = 0U;
	uint32_t src_temp32_L = 0U;

	for (i = 0u; i < n ; i = i+4u)
	{
	src_temp32 = (uint32_t *)src;
	src_temp32_H = (*src_temp32)>>16u;/* polyspace RTE:IDP */
	src_temp32_L = (*src_temp32)<<16u;
	dest_temp32 = (uint32_t *)dest;
	(*dest_temp32) = src_temp32_H |src_temp32_L;
	src = src + 4u;
	dest = dest + 4u;
	}

	return TRUE;
}
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
uint32_t cc_strlen(const uint8_t * s)
{
    const uint8_t *sc;
    uint32_t temp = 0;
    for (sc = s; *sc != (uint8_t)'\0'; ++sc)/* polyspace RTE:IDP */
    {
    }
    temp = (uint32_t)(sc - s);
    return temp;
}
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
void delay(volatile uint32_t x)
{
    volatile uint32_t x_temp = x;
    while (x_temp != 0u)
    {
        x_temp--;
    }
}
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

#define BASE_START_SEC_CODE
#include "Base_MemMap.h"
void delay_ms(uint32_t ms)
{
    uint32_t i;
    uint32_t temp = ms;
    do
    {
        temp--;
        i = 6400;
        do
        {
           i--;
        }while (i != 0u);
    }while (temp != 0u);
}
#define BASE_STOP_SEC_CODE
#include "Base_MemMap.h"

