/*
********************************************************************************
*
*  File name: Os_MemMap_Code.h
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

#ifdef OS_START_SEC_CODE
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section ".OS_CODE" ax
#endif
#ifdef __ghs__
#pragma ghs section text = ".OS_CODE"
#endif
#ifdef __TASKING__
#pragma section code ".OS_CODE"
#endif
#ifdef __IAR__
#pragma default_function_attributes = @ ".OS_CODE"
#endif
#ifdef __clang__
#pragma clang section text = ".OS_CODE"
#endif
#ifdef __CSP__
#pragma section text ".OS_CODE"
#endif
#ifdef __GCC__
#pragma GCC section text ".OS_CODE"
#endif
#undef MEMMAP_ERROR
#undef OS_START_SEC_CODE
#endif


#ifdef OS_STOP_SEC_CODE
#if defined(__HIGHTEC__) && !defined(__clang__)
#pragma section
#endif
#ifdef __ghs__
#pragma ghs section
#endif
#ifdef __TASKING__
#pragma section code restore
#endif
#ifdef __IAR__
#pragma default_function_attributes =
#endif
#ifdef __clang__
#pragma clang section text = ""
#endif
#ifdef __CSP__
#pragma section default
#endif
#ifdef __GCC__
#pragma GCC section text
#endif
#undef MEMMAP_ERROR
#undef OS_STOP_SEC_CODE
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

