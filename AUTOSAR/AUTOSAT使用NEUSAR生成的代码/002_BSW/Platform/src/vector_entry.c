/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     vector_entry.c
* @version  3.0.0
* @date     2023 - 04 - 17
* @brief    Initial version.
*****************************************************************************/
#include "compiler_api.h"

#define PPCASMF(x) PPCASM (" " tostring(x) " ")
#define PPCASMF2(x,x1) PPCASM (" " tostring(x) "," tostring(x1) " ")
/* PRQA S 1006 ++ */
PPCASMF( .globl VTABLE);
PPCASMF( .globl IVOR0_Vector );
PPCASMF( .globl IVOR1_Vector );
PPCASMF( .globl IVOR2_Vector );
PPCASMF( .globl IVOR3_Vector );
PPCASMF( .globl IVOR4_Vector );
PPCASMF( .globl IVOR5_Vector );
PPCASMF( .globl IVOR6_Vector );
PPCASMF( .globl IVOR7_Vector );
PPCASMF( .globl IVOR8_Vector );
PPCASMF( .globl IVOR9_Vector );
PPCASMF( .globl IVOR10_Vector );
PPCASMF( .globl IVOR11_Vector );
PPCASMF( .globl IVOR12_Vector );
PPCASMF( .globl IVOR13_Vector );
PPCASMF( .globl IVOR14_Vector );
PPCASMF( .globl IVOR15_Vector );
PPCASMF( .globl SetupE2EECSR0_for_1b_ECC_fault);
PPCASMF( .globl SetupE2EECSR0_for_2b_ECC_fault);
PPCASMF( .globl SetupE2EECSR0_for_ClearECC);
PPCASMF( .globl SetupE2EECSR0_for_ClearWRC);
#ifndef __HIGHTEC__
PPCASMF( .extern IVOR0_Handler );
PPCASMF( .extern IVOR1_Handler );
PPCASMF( .extern IVOR2_Handler );
PPCASMF( .extern IVOR3_Handler );
PPCASMF( .extern IVOR4_Handler );
PPCASMF( .extern IVOR5_Handler );
PPCASMF( .extern IVOR6_Handler );
PPCASMF( .extern IVOR7_Handler );
PPCASMF( .extern IVOR8_Handler );
PPCASMF( .extern IVOR10_Handler );
PPCASMF( .extern IVOR11_Handler );
PPCASMF( .extern IVOR12_Handler );
PPCASMF( .extern IVOR13_Handler );
PPCASMF( .extern IVOR14_Handler );
PPCASMF( .extern IVOR15_Handler );
#endif
PPCASMF2( .section    .core_exceptions_table, "axv" );

VEC_ALIGN;
PPCASMF( VTABLE: );
PPCASMF( IVOR0_Vector: );
PPCASMF( e_b   IVOR0_Handler );

VEC_ALIGN;
PPCASMF( IVOR1_Vector: );
PPCASMF( e_b   IVOR1_Handler );

VEC_ALIGN;
PPCASMF( IVOR2_Vector: );
PPCASMF( e_b   IVOR2_Handler );

VEC_ALIGN;
PPCASMF( IVOR3_Vector: );
PPCASMF( e_b   IVOR3_Handler );

VEC_ALIGN;
PPCASMF( IVOR4_Vector: );
PPCASMF( e_b   IVOR4_Handler );

VEC_ALIGN;
PPCASMF( IVOR5_Vector: );
PPCASMF( e_b   IVOR5_Handler );

VEC_ALIGN;
PPCASMF( IVOR6_Vector: );
PPCASMF( e_b   IVOR6_Handler );

VEC_ALIGN;
PPCASMF( IVOR7_Vector: );
PPCASMF( e_b   IVOR7_Handler );

VEC_ALIGN;
PPCASMF( IVOR8_Vector: );
PPCASMF( se_illegal );  /* for semihosting support  */
PPCASMF( se_rfi );

VEC_ALIGN;
PPCASMF( IVOR9_Vector: );
PPCASMF( e_b   IVOR9_Vector );

VEC_ALIGN;
PPCASMF( IVOR10_Vector: );
PPCASMF( e_b   IVOR10_Handler );

VEC_ALIGN;
PPCASMF( IVOR11_Vector: );
PPCASMF( e_b   IVOR11_Handler );

VEC_ALIGN;
PPCASMF( IVOR12_Vector: );
PPCASMF( e_b   IVOR12_Handler );

VEC_ALIGN;
PPCASMF( IVOR13_Vector: );
PPCASMF( e_b   IVOR13_Handler );

VEC_ALIGN;
PPCASMF( IVOR14_Vector: );
PPCASMF( e_b   IVOR14_Handler );

VEC_ALIGN;
PPCASMF( IVOR15_Vector: );
PPCASMF( e_b   IVOR15_Handler );

/* PRQA S 1006 -- */
