/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx compiler specific file
* HISTORY     : Initial version
* @file     compiler_api.h
* @version  3.0.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 0835, 0844 EOF*/
#ifndef COMPILER_API_H
#define COMPILER_API_H

#if !defined(__GNUC__) && !defined(__ghs__) && !defined (__DCC__) && !defined (__HIGHTEC__)
#error "Compiler is not defined"
#endif

#define stringify(s) tostring(s)
#define tostring(s) #s/*PRQA S 0341*/

/* definitions for assembler functions */
#ifdef __GNUC__   /* GCC */
#define PPCASM             __asm__
#define MFSPR(rn)        ({uint32_t rval; PPCASM volatile("mfspr %0," stringify(rn) : "=r" (rval)); rval;}) /*PRQA S 0835*/
#define MTSPR(rn, v)     PPCASM volatile("mtspr " stringify(rn) ",%0" : : "r" (v))                          /*PRQA S 0835*/
#define MFMSR()          ({uint32_t rval; PPCASM volatile("mfmsr %0,"  : "=r" (rval)); rval;})
#define MTMSR(v)         PPCASM volatile("mtmsr %0" : : "r" (v))
#define MFESR()          ({uint32_t rval; PPCASM volatile("mfesr %0,"  : "=r" (rval)); rval;})
#define MTESR(v)         PPCASM volatile("mtesr %0" : : "r" (v))
#define MEM_ALIGN(x)     __attribute__ ((__aligned__ (x)))
#define MTDCR(dcr, v)    PPCASM volatile("mtdcr " stringify(dcr) ", %0" : : "r" (v))
#define MFDCR(dcr)       ({uint32_t rval; PPCASM volatile("mfdcr %0," stringify(dcr) : "=r" (rval)); rval;})
#endif

#ifdef __HIGHTEC__   /* HighTec GCC */
#define PPCASM             __asm__
#define MFSPR(rn)        ({uint32_t rval; PPCASM volatile("mfspr %0," stringify(rn) : "=r" (rval)); rval;})
#define MTSPR(rn, v)     PPCASM volatile("mtspr " stringify(rn) ",%0" : : "r" (v))
#define MFMSR()          ({uint32_t rval; PPCASM volatile("mfmsr %0,"  : "=r" (rval)); rval;})
#define MTMSR(v)         PPCASM volatile("mtmsr %0" : : "r" (v))
#define MFESR()          ({uint32_t rval; PPCASM volatile("mfesr %0,"  : "=r" (rval)); rval;})
#define MTESR(v)         PPCASM volatile("mtesr %0" : : "r" (v))
#define MEM_ALIGN(x)     __attribute__ ((__aligned__ (x)))
#define MTDCR(dcr, v)    PPCASM volatile("mtdcr " stringify(dcr) ", %0" : : "r" (v))
#define MFDCR(dcr)       ({uint32_t rval; PPCASM volatile("mfdcr %0," stringify(dcr) : "=r" (rval)); rval;})
#endif

#ifdef __ghs__    /* GreenHills */
#include <ppc_ghs.h>    /* for intrinsic functions only */
#define PPCASM   __asm
#define MFSPR(spr)       __MFSPR(spr)
#define MTSPR(spr, val)  __MTSPR(spr, val)
#define MFMSR()          __GETSR()
#define MTMSR(val)       __SETSR(val)
#define MFESR()          __MFMSR()
#define MTESR(val)       __MTMSR(val)
#define PRAGMA(x)        _Pragma(#x)
#define MEM_ALIGN(x)     PRAGMA(alignvar(x))
#define MTDCR(dcr, v)    __MTDCR((dcr), (v))
#define MFDCR(dcr)       __MFDCR(dcr)
#endif

#ifdef __DCC__ /* Diab */
#include <diab/ppcasm.h>    /* for intrinsic functions only */
#define PPCASM   asm
#define MFSPR(spr)       __mfspr(spr)
#define MTSPR(spr, val)  __mtspr((spr), (val))
#define MFMSR()          __mfmsr()
#define MTMSR(v)         __mtmsr(val)
#define MFESR()          __mfmsr()
#define MTESR(v)         __mtmsr(val)
#define MEM_ALIGN(x)
#endif

/* intrrupt vector align */
#define VEC_ALIGN          PPCASM(" .align 4 ")

/* trigger debug interrupt */
#define DEBUG_BKPT()       PPCASM("se_illegal")

/** \brief  BKPT_ASM
 *
 *   Macro to be used to trigger an debug interrupt
 */
#define BKPT_ASM    PPCASM ("se_illegal")

#endif
