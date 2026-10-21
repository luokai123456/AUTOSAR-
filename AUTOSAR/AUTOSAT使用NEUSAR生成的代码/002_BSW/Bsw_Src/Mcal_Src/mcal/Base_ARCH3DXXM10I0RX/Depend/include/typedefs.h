/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     typedefs.h
* @version  3.0.0
* @date     2023 - 04 - 17
* @brief    Initial version.
*
*****************************************************************************/

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

/****************************************************************************/
#include "Platform_Types.h"
/* PRQA S 1535,4600,5209 EOF */

#ifndef ON
#define ON 1U
#endif

#ifndef OFF
#define OFF 0U
#endif

#ifndef TRUE
#define TRUE 1U
#endif

#ifndef FALSE
#define FALSE 0U
#endif

#ifndef NULL
#define NULL 0L
#endif

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

#ifndef GET_MAX
#define GET_MAX(x, y) (((x) < (y)) ? (y) : (x))
#endif

#ifndef GET_MIN
#define GET_MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif

#ifndef ALIGN_UP
#define ALIGN_UP(x, align) (((int) (x) + ((align) - 1)) & ~((align) - 1))
#endif

#ifndef ALIGN_DOWN
#define ALIGN_DOWN(x, align) ((int)(x) & ~((align) - 1))
#endif

#ifndef IS_ALIGNED
#define IS_ALIGNED(x, align) (((int)(x) & ((align) - 1)) == 0)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))
#endif

#ifndef REG_READ32
  #define REG_READ32(address)               (*(volatile uint32_t*)(address))
#endif

#ifndef REG_WRITE32
  #define REG_WRITE32(address, value)       ((*(volatile uint32_t*)(address))= (uint32_t)(value))
#endif

#ifndef REG_BIT_SET32
  #define REG_BIT_SET32(address, mask)      ((*(volatile uint32_t*)(address))|= (uint32_t)(mask))
#endif

#ifndef REG_BIT_CLEAR32
  #define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32_t*)(address))&= ((uint32_t)~((uint32_t)(mask))))
#endif

#ifndef REG_RMW32
  #define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32_t)~((uint32_t)(mask))))| ((uint32_t)(value)))))
#endif
 
/****************************************************************************/
#if defined (__GNUC__)  /* GCC compiler*/
#include <stdint.h>

typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;

typedef float float32_t;

#elif defined (__MWERKS__)    /* Metrowerk CodeWarrior */
#include <stdint.h>

typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;

typedef float float32_t;

#elif defined (__ghs__)    /* GreenHills */
#include <stdint.h>

typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;

typedef float float32_t;

#elif defined(__HIGHTEC__)   /* HighTec GCC */

#include <stdint.h>

/* Standard typedefs used by header files, based on ISO C standard */
typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;
#else
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef volatile signed char vint8_t;
typedef volatile unsigned char vuint8_t;

typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef volatile signed short vint16_t;
typedef volatile unsigned short vuint16_t;

typedef signed long int32_t;
typedef unsigned long uint32_t;
typedef volatile signed long vint32_t;
typedef volatile unsigned long vuint32_t;

typedef long long int64_t;
typedef unsigned long long uint64_t;

typedef float float32_t;

#endif
#endif
