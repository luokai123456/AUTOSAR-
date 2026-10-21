/*
********************************************************************************
*
*  File name: Os_MemMap_Stack.h
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

#ifdef OS_START_SEC_STACK_OSCORE0
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_STACK_OSCORE0"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_STACK_OSCORE0"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_STACK_OSCORE0"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_STACK_OSCORE0"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_STACK_OSCORE0"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_STACK_OSCORE0"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_STACK_OSCORE0"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_STACK_OSCORE0
#endif


#ifdef OS_STOP_SEC_STACK_OSCORE0
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
#undef OS_STOP_SEC_STACK_OSCORE0
#endif


#ifdef OS_START_SEC_STACK_OSCORE1
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_STACK_OSCORE1"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_STACK_OSCORE1"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_STACK_OSCORE1"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_STACK_OSCORE1"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_STACK_OSCORE1"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_STACK_OSCORE1"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_STACK_OSCORE1"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_STACK_OSCORE1
#endif


#ifdef OS_STOP_SEC_STACK_OSCORE1
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
#undef OS_STOP_SEC_STACK_OSCORE1
#endif


#ifdef OS_START_SEC_STACK_OSCORE2
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_STACK_OSCORE2"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_STACK_OSCORE2"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_STACK_OSCORE2"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_STACK_OSCORE2"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_STACK_OSCORE2"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_STACK_OSCORE2"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_STACK_OSCORE2"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_STACK_OSCORE2
#endif


#ifdef OS_STOP_SEC_STACK_OSCORE2
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
#undef OS_STOP_SEC_STACK_OSCORE2
#endif


#ifdef OS_START_SEC_STACK_OSCORE3
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_STACK_OSCORE3"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_STACK_OSCORE3"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_STACK_OSCORE3"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_STACK_OSCORE3"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_STACK_OSCORE3"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_STACK_OSCORE3"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_STACK_OSCORE3"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_STACK_OSCORE3
#endif


#ifdef OS_STOP_SEC_STACK_OSCORE3
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
#undef OS_STOP_SEC_STACK_OSCORE3
#endif


#ifdef OS_START_SEC_STACK_OSCORE4
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_STACK_OSCORE4"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_STACK_OSCORE4"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_STACK_OSCORE4"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_STACK_OSCORE4"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_STACK_OSCORE4"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_STACK_OSCORE4"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_STACK_OSCORE4"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_STACK_OSCORE4
#endif


#ifdef OS_STOP_SEC_STACK_OSCORE4
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
#undef OS_STOP_SEC_STACK_OSCORE4
#endif


#ifdef OS_START_SEC_STACK_OSCORE5
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_STACK_OSCORE5"
#endif
#ifdef __ghs__
#pragma ghs section bss = ".OS_STACK_OSCORE5"
#endif
#ifdef __TASKING__
#pragma section farbss ".OS_STACK_OSCORE5"
#endif
#ifdef __IAR__
#pragma default_variable_attributes = @ ".OS_STACK_OSCORE5"
#endif
#ifdef __clang__
#pragma clang section bss = ".OS_STACK_OSCORE5"
#endif
#ifdef __CSP__
#pragma section r0_disp32 ".OS_STACK_OSCORE5"
#endif
#ifdef __GCC__
#pragma GCC section bss ".OS_STACK_OSCORE5"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_STACK_OSCORE5
#endif


#ifdef OS_STOP_SEC_STACK_OSCORE5
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
#undef OS_STOP_SEC_STACK_OSCORE5
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

