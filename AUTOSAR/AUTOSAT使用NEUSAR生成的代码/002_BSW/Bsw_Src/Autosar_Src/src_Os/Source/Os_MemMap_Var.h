/*
********************************************************************************
*
*  File name: Os_MemMap_Var.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date : HanCL/2021.11.23
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date : LiG/2024.10.14
* Change: Delete all "# ifdef__GNU__ # endif # ifdef__DCC__ # endif".
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date : LiG/2024.10.14
* Change: Change all "# ifdef__HIGHTEC__" to
*               "# if defined (__HIGHTEC__)&&! Defined (__clang__)".
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define MEMMAP_ERROR

/* Const section */

#ifdef OS_START_SEC_CONST
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_CONST"
#endif
#ifdef __ghs__
#pragma ghs section rodata = ".OS_CONST"
#endif
#ifdef __TASKING__
#pragma section farrom ".OS_CONST"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_CONST"
#endif
#ifdef __clang__
#pragma clang section rodata = ".OS_CONST"
#endif
#ifdef __CSP__
#pragma section const ".OS_CONST"
#endif
#ifdef __GCC__
#pragma GCC section rodata ".OS_CONST"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_CONST
#endif
#ifdef OS_STOP_SEC_CONST
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farrom restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section rodata = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section rodata
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_CONST
#endif


/* OSCORE0 const section */

#ifdef OS_START_SEC_VAR_OSCORE0
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_VAR_OSCORE0"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_VAR_OSCORE0"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_VAR_OSCORE0"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_VAR_OSCORE0"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_VAR_OSCORE0"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_VAR_OSCORE0"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_VAR_OSCORE0"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_VAR_OSCORE0
#endif


#ifdef OS_STOP_SEC_VAR_OSCORE0
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_VAR_OSCORE0
#endif


#ifdef OS_START_SEC_INITVAR_OSCORE0
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_INITVAR_OSCORE0"
#endif
#ifdef __ghs__
#pragma ghs section data = ".OS_INITVAR_OSCORE0"
#endif
#ifdef __TASKING__
#pragma section fardata ".OS_INITVAR_OSCORE0"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_INITVAR_OSCORE0"
#endif
#ifdef __clang__
#pragma clang section data = ".OS_INITVAR_OSCORE0"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_INITVAR_OSCORE0"
#endif
#ifdef __GCC__
#pragma GCC section data ".OS_INITVAR_OSCORE0"
#pragma GCC section bss ".OS_VAR_OSCORE0"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_INITVAR_OSCORE0
#endif


#ifdef OS_STOP_SEC_INITVAR_OSCORE0
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section fardata restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section data = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section data
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_INITVAR_OSCORE0
#endif


#ifdef OS_START_SEC_NOCACHE_VAR_OSCORE0
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_NOCACHE_VAR_OSCORE0"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_NOCACHE_VAR_OSCORE0"
#endif
#ifdef __TASKING__
#pragma section .farbss ".OS_NOCACHE_VAR_OSCORE0"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_NOCACHE_VAR_OSCORE0"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_NOCACHE_VAR_OSCORE0"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_NOCACHE_VAR_OSCORE0"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_NOCACHE_VAR_OSCORE0"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_NOCACHE_VAR_OSCORE0
#endif


#ifdef OS_STOP_SEC_NOCACHE_VAR_OSCORE0
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_NOCACHE_VAR_OSCORE0
#endif


/* OSCORE1 const section */

#ifdef OS_START_SEC_VAR_OSCORE1
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_VAR_OSCORE1"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_VAR_OSCORE1"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_VAR_OSCORE1"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_VAR_OSCORE1"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_VAR_OSCORE1"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_VAR_OSCORE1"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_VAR_OSCORE1"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_VAR_OSCORE1
#endif


#ifdef OS_STOP_SEC_VAR_OSCORE1
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_VAR_OSCORE1
#endif


#ifdef OS_START_SEC_INITVAR_OSCORE1
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_INITVAR_OSCORE1"
#endif
#ifdef __ghs__
#pragma ghs section data = ".OS_INITVAR_OSCORE1"
#endif
#ifdef __TASKING__
#pragma section fardata ".OS_INITVAR_OSCORE1"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_INITVAR_OSCORE1"
#endif
#ifdef __clang__
#pragma clang section data = ".OS_INITVAR_OSCORE1"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_INITVAR_OSCORE1"
#endif
#ifdef __GCC__
#pragma GCC section data ".OS_INITVAR_OSCORE1"
#pragma GCC section bss ".OS_VAR_OSCORE1"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_INITVAR_OSCORE1
#endif


#ifdef OS_STOP_SEC_INITVAR_OSCORE1
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section fardata restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section data = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section data
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_INITVAR_OSCORE1
#endif


#ifdef OS_START_SEC_NOCACHE_VAR_OSCORE1
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_NOCACHE_VAR_OSCORE1"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_NOCACHE_VAR_OSCORE1"
#endif
#ifdef __TASKING__
#pragma section .farbss ".OS_NOCACHE_VAR_OSCORE1"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_NOCACHE_VAR_OSCORE1"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_NOCACHE_VAR_OSCORE1"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_NOCACHE_VAR_OSCORE1"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_NOCACHE_VAR_OSCORE1"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_NOCACHE_VAR_OSCORE1
#endif


#ifdef OS_STOP_SEC_NOCACHE_VAR_OSCORE1
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_NOCACHE_VAR_OSCORE1
#endif


/* OSCORE2 const section */

#ifdef OS_START_SEC_VAR_OSCORE2
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_VAR_OSCORE2"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_VAR_OSCORE2"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_VAR_OSCORE2"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_VAR_OSCORE2"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_VAR_OSCORE2"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_VAR_OSCORE2"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_VAR_OSCORE2"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_VAR_OSCORE2
#endif


#ifdef OS_STOP_SEC_VAR_OSCORE2
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_VAR_OSCORE2
#endif


#ifdef OS_START_SEC_INITVAR_OSCORE2
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_INITVAR_OSCORE2"
#endif
#ifdef __ghs__
#pragma ghs section data = ".OS_INITVAR_OSCORE2"
#endif
#ifdef __TASKING__
#pragma section fardata ".OS_INITVAR_OSCORE2"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_INITVAR_OSCORE2"
#endif
#ifdef __clang__
#pragma clang section data = ".OS_INITVAR_OSCORE2"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_INITVAR_OSCORE2"
#endif
#ifdef __GCC__
#pragma GCC section data ".OS_INITVAR_OSCORE2"
#pragma GCC section bss ".OS_VAR_OSCORE2"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_INITVAR_OSCORE2
#endif


#ifdef OS_STOP_SEC_INITVAR_OSCORE2
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section fardata restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section data = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section data
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_INITVAR_OSCORE2
#endif


#ifdef OS_START_SEC_NOCACHE_VAR_OSCORE2
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_NOCACHE_VAR_OSCORE2"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_NOCACHE_VAR_OSCORE2"
#endif
#ifdef __TASKING__
#pragma section .farbss ".OS_NOCACHE_VAR_OSCORE2"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_NOCACHE_VAR_OSCORE2"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_NOCACHE_VAR_OSCORE2"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_NOCACHE_VAR_OSCORE2"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_NOCACHE_VAR_OSCORE2"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_NOCACHE_VAR_OSCORE2
#endif


#ifdef OS_STOP_SEC_NOCACHE_VAR_OSCORE2
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_NOCACHE_VAR_OSCORE2
#endif


/* OSCORE3 const section */

#ifdef OS_START_SEC_VAR_OSCORE3
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_VAR_OSCORE3"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_VAR_OSCORE3"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_VAR_OSCORE3"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_VAR_OSCORE3"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_VAR_OSCORE3"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_VAR_OSCORE3"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_VAR_OSCORE3"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_VAR_OSCORE3
#endif


#ifdef OS_STOP_SEC_VAR_OSCORE3
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_VAR_OSCORE3
#endif


#ifdef OS_START_SEC_INITVAR_OSCORE3
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_INITVAR_OSCORE3"
#endif
#ifdef __ghs__
#pragma ghs section data = ".OS_INITVAR_OSCORE3"
#endif
#ifdef __TASKING__
#pragma section fardata ".OS_INITVAR_OSCORE3"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_INITVAR_OSCORE3"
#endif
#ifdef __clang__
#pragma clang section data = ".OS_INITVAR_OSCORE3"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_INITVAR_OSCORE3"
#endif
#ifdef __GCC__
#pragma GCC section data ".OS_INITVAR_OSCORE3"
#pragma GCC section bss ".OS_VAR_OSCORE3"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_INITVAR_OSCORE3
#endif


#ifdef OS_STOP_SEC_INITVAR_OSCORE3
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section fardata restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section data = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section data
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_INITVAR_OSCORE3
#endif


#ifdef OS_START_SEC_NOCACHE_VAR_OSCORE3
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_NOCACHE_VAR_OSCORE3"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_NOCACHE_VAR_OSCORE3"
#endif
#ifdef __TASKING__
#pragma section .farbss ".OS_NOCACHE_VAR_OSCORE3"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_NOCACHE_VAR_OSCORE3"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_NOCACHE_VAR_OSCORE3"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_NOCACHE_VAR_OSCORE3"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_NOCACHE_VAR_OSCORE3"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_NOCACHE_VAR_OSCORE3
#endif


#ifdef OS_STOP_SEC_NOCACHE_VAR_OSCORE3
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_NOCACHE_VAR_OSCORE3
#endif


/* OSCORE4 const section */

#ifdef OS_START_SEC_VAR_OSCORE4
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_VAR_OSCORE4"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_VAR_OSCORE4"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_VAR_OSCORE4"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_VAR_OSCORE4"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_VAR_OSCORE4"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_VAR_OSCORE4"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_VAR_OSCORE4"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_VAR_OSCORE4
#endif


#ifdef OS_STOP_SEC_VAR_OSCORE4
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_VAR_OSCORE4
#endif


#ifdef OS_START_SEC_INITVAR_OSCORE4
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_INITVAR_OSCORE4"
#endif
#ifdef __ghs__
#pragma ghs section data = ".OS_INITVAR_OSCORE4"
#endif
#ifdef __TASKING__
#pragma section fardata ".OS_INITVAR_OSCORE4"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_INITVAR_OSCORE4"
#endif
#ifdef __clang__
#pragma clang section data = ".OS_INITVAR_OSCORE4"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_INITVAR_OSCORE4"
#endif
#ifdef __GCC__
#pragma GCC section data ".OS_INITVAR_OSCORE4"
#pragma GCC section bss ".OS_VAR_OSCORE4"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_INITVAR_OSCORE4
#endif


#ifdef OS_STOP_SEC_INITVAR_OSCORE4
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section fardata restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section data = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section data
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_INITVAR_OSCORE4
#endif


#ifdef OS_START_SEC_NOCACHE_VAR_OSCORE4
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_NOCACHE_VAR_OSCORE4"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_NOCACHE_VAR_OSCORE4"
#endif
#ifdef __TASKING__
#pragma section .farbss ".OS_NOCACHE_VAR_OSCORE4"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_NOCACHE_VAR_OSCORE4"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_NOCACHE_VAR_OSCORE4"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_NOCACHE_VAR_OSCORE4"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_NOCACHE_VAR_OSCORE4"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_NOCACHE_VAR_OSCORE4
#endif


#ifdef OS_STOP_SEC_NOCACHE_VAR_OSCORE4
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_NOCACHE_VAR_OSCORE4
#endif


/* OSCORE5 const section */

#ifdef OS_START_SEC_VAR_OSCORE5
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_VAR_OSCORE5"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_VAR_OSCORE5"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_VAR_OSCORE5"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_VAR_OSCORE5"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_VAR_OSCORE5"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_VAR_OSCORE5"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_VAR_OSCORE5"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_VAR_OSCORE5
#endif


#ifdef OS_STOP_SEC_VAR_OSCORE5
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_VAR_OSCORE5
#endif


#ifdef OS_START_SEC_INITVAR_OSCORE5
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_INITVAR_OSCORE5"
#endif
#ifdef __ghs__
#pragma ghs section data = ".OS_INITVAR_OSCORE5"
#endif
#ifdef __TASKING__
#pragma section fardata ".OS_INITVAR_OSCORE5"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_INITVAR_OSCORE5"
#endif
#ifdef __clang__
#pragma clang section data = ".OS_INITVAR_OSCORE5"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_INITVAR_OSCORE5"
#endif
#ifdef __GCC__
#pragma GCC section data ".OS_INITVAR_OSCORE5"
#pragma GCC section bss ".OS_VAR_OSCORE5"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_INITVAR_OSCORE5
#endif


#ifdef OS_STOP_SEC_INITVAR_OSCORE5
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section fardata restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section data = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section data
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_INITVAR_OSCORE5
#endif


#ifdef OS_START_SEC_NOCACHE_VAR_OSCORE5
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_NOCACHE_VAR_OSCORE5"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_NOCACHE_VAR_OSCORE5"
#endif
#ifdef __TASKING__
#pragma section .farbss ".OS_NOCACHE_VAR_OSCORE5"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_NOCACHE_VAR_OSCORE5"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_NOCACHE_VAR_OSCORE5"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_NOCACHE_VAR_OSCORE5"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_NOCACHE_VAR_OSCORE5"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_NOCACHE_VAR_OSCORE5
#endif


#ifdef OS_STOP_SEC_NOCACHE_VAR_OSCORE5
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_NOCACHE_VAR_OSCORE5
#endif


#ifdef OS_START_SEC_GLOBAL_NOCACHE_VAR
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_GLOBAL_NOCACHE_VAR"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_GLOBAL_NOCACHE_VAR"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_GLOBAL_NOCACHE_VAR"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_GLOBAL_NOCACHE_VAR"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_GLOBAL_NOCACHE_VAR"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_GLOBAL_NOCACHE_VAR"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_GLOBAL_NOCACHE_VAR"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_GLOBAL_NOCACHE_VAR
#endif


#ifdef OS_STOP_SEC_GLOBAL_NOCACHE_VAR
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section farbss restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section bss = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_GLOBAL_NOCACHE_VAR
#endif


#ifdef OS_START_SEC_GLOBAL_NOCACHE_INITVAR
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_GLOBAL_NOCACHE_INITVAR"
#endif
#ifdef __ghs__
#pragma ghs section data = ".OS_GLOBAL_NOCACHE_INITVAR"
#endif
#ifdef __TASKING__
#pragma section fardata ".OS_GLOBAL_NOCACHE_INITVAR"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_GLOBAL_NOCACHE_INITVAR"
#endif
#ifdef __clang__
#pragma clang section data = ".OS_GLOBAL_NOCACHE_INITVAR"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_GLOBAL_NOCACHE_INITVAR"
#endif
#ifdef __GCC__
#pragma GCC section data ".OS_GLOBAL_NOCACHE_INITVAR"
#pragma GCC section bss ".OS_GLOBAL_NOCACHE_INITVAR"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_GLOBAL_NOCACHE_INITVAR
#endif
#ifdef OS_STOP_SEC_GLOBAL_NOCACHE_INITVAR
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section fardata restore
#endif
#ifdef __IAR__
#pragma default_variable_attributes =
#endif
#ifdef __clang__
#pragma clang section data = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section data
#pragma GCC section bss
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_GLOBAL_NOCACHE_INITVAR
#endif


#ifdef MEMMAP_ERROR
    /* #error "Os_MemMap_OsCode.h, wrong pragma command." */
#undef MEMMAP_ERROR
#endif
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

