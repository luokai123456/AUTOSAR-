/*****************************************************************************
******************************************************************************
*
*               C Runtime Library for Simulink Desktop Real-Time
*
*               Copyright 1994-2022 The MathWorks, Inc.
*
******************************************************************************
*****************************************************************************/

#ifndef _SLDRTCRT_H__
#define _SLDRTCRT_H__

#include <stddef.h>

/* ensure NULL is properly defined for C++ */
#ifdef __cplusplus
#undef NULL
#ifdef _LP64
#define NULL 0LL
#else
#define NULL 0
#endif
#endif

/* function imported from kernel */
#ifdef SLDRT_TARGET_win64
#define CRTKERNELIMPORTATTRIB __attribute__((ms_abi))
#else
#define CRTKERNELIMPORTATTRIB
#endif

#ifdef __cplusplus
#define CRTKERNELEXTERNC extern "C"
#define CRTKERNELIMPORT(fn) extern "C" CRTKERNELIMPORTATTRIB fn
#define CRTKERNELRESTRICT

#else
#define CRTKERNELEXTERNC extern
#define CRTKERNELIMPORT(fn) CRTKERNELIMPORTATTRIB fn
#define CRTKERNELRESTRICT restrict

#endif

/* function currently unsupported by kernel */
#define CRTKERNELUNSUPPORTED(fn) fn


#endif /* _SLDRTCRT_H__ */
