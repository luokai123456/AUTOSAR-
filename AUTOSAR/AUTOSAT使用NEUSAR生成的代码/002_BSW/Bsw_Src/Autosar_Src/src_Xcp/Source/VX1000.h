/*------------------------------------------------------------------------------- */
/* VX1000.h                                                                       */
/* Vector VX1000 Application Driver                                               */
/* Release: 04_09                    Build: 810          Modification: 17.05.2025 */
/*                                                                                */
/*                                                                                */
/* For VX1000If and the VX1000 AppDriver Product-Specific Special Terms apply,    */
/* which can be downloaded here: www.vector.com/TC-VX1000If-VX1000AppDriver       */
/*                                                                                */
/* Note: The VX1000 AppDriver has been developed for test and development         */
/* purposes but not for use in production software. Activating the VX1000         */
/* AppDriver in production software is always prohibited!                         */
/*                                                                                */
/* For production software options for VX1000If and VX1000 AppDriver, please      */
/* refer to the documentation accompanying VX1000If and the VX1000 AppDriver or   */
/* consult your Vector sales contact.                                             */
/*                                                                                */
/*                                                                                */
/* Copyright (c) 2025 by Vector Informatik GmbH. All rights reserved.             */
/* This software is copyright protected and proprietary to Vector Informatik GmbH */
/* Vector Informatik GmbH grants to you only those rights as set out in the       */
/* license conditions. All other rights remain with Vector Informatik GmbH.       */
/*                                                                                */
/* Don't modify this file, settings are defined in VX1000_cfg.h and in memmap.h   */
/*------------------------------------------------------------------------------- */


/* ----------------------------------------------------------------------------------------------------------------------- /
/ Status of MISRA conformance:                                                                                             /
/ ---------------------------                                                                                              /
/  * required rule 16.1 "usage of variadic functions"                                                                      /
/     - violated only if the user explicitly enables the debug print feature during development phase.                     /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * advisory rule 19.1 "location of file inclusions"                                                                      /
/     - violated because there exists no MISRA-conform workaround without loosing essential functionality                  /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * required rule 19.4 "complete statement inside a macro"                                                                /
/     - violated to allow the application to generically call the API without having to care whether a feature             /
/       is currently disabled or enabled. Additional parentheses would no longer be valid C syntax.                        /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * advisory rule 19.7 "functions vs. macros"                                                                             /
/     - violated because a MISRA-conform workaround would induce configuration-dependent MISRA violations in user's code   /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * required rule 19.10 "macro parameter used without parentheses"                                                        /
/     - violated in user-overridable typecast callback and when appending userdefined suffices to ISA-dependent functions  /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * advisory rule 19.13 "preprocessor operator '##' used"                                                                 /
/     - violated only when appending userdefined suffices to ISA-dependent functions for making their names unique         /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * required rule 19.15 "missing protection against repeated file inclusion"                                              /
/     - violated to allow memmap.h-like functionality (all other lines of the file however are protected)                  /
/                                                                                                                          /
/  * violations in user code of rule 17.4 "usage of pointer arithmetic" and of rule 12.8 "usage of unsupported data types" /
/    and of rule 16.7 "missing qualifier" when calling the VX1000 API hopefully will be fixed soon by mailbox replacement  /
/                                                                                                                          /
/                                                                            (checked in PowerPC build 600)                /
/                                                                                                                          /
/------------------------------------------------------------------------------------------------------------------------ */


#if !defined(VX1000_H)
#define VX1000_H


/*------------------------------------------------------------------------------ */
/* Driver's version and status                                                   */

#define VX1000_APPDRIVER_BUILDNUMBER   810UL
#define VX1000_RELEASENAMEARRAY        '0','4','_','0','9',' ',' ',' ',' ',' ',' ',' '
/* semantic versioning no longer used starting with release 3.0:
/ #define VX1000_FILE_VERSION_STATUS     (VX1000_ALPHA)  /-* VX1000_RELEASED / VX1000_TESTED / VX1000_BETA / VX1000_ALPHA; a change does NOT force version increase *-/
/ #define VX1000_FILE_VERSION_MAJOR      3U   /-* major version number (1..16); a change initially forces ALPHA status *-/
/ #define VX1000_FILE_VERSION_MINOR      0U   /-* minor version number (0..99); a change initially forces BETA status  *-/
/ #define VX1000_FILE_VERSION_PATCH      3U   /-* patch level (0..7); a change does NOT change VERSION_STATUS *-/
/
/ #define VX1000_FILE_VERSION ( ((((VX1000_FILE_VERSION_MAJOR) & 0xfU) << 12U) | (((VX1000_FILE_VERSION_MINOR) & 0x7fU) << 5U)) | (((VX1000_FILE_VERSION_STATUS) << 3U) | ((VX1000_FILE_VERSION_PATCH) & 0x7U)) )
*/

#define VX1000_CFG_VER_MAJOR_AD        2U /* incremented, when a new generator needs to generate less settings, settings with changed meaning or settings with less choices */
#define VX1000_CFG_VER_MINOR_AD        0U /* incremented, when a new generator shall generate more settings, or settings would have more choices */


/*------------------------------------------------------------------------------ */
/* data types                                                                    */

#if defined(_C166)                           /* PRQA S 0883 */ /* Actually not violating MISRA rule 19.15: QAC gives a false warning here */
#define VX1000_TASKING_WRAPDEF_C166    _C166 /* map to the reserved name for MISRA checkers that do not like to see leading single underscores in user code */
#elif defined(__C166__) && defined(__VERSION__)
#define VX1000_TASKING_WRAPDEF_C166    __VERSION__ /* map to the reserved name for MISRA checkers that do not like to see surrounding underscores in user code */
#else  /* !_C166 && !__C166__ */
#define VX1000_TASKING_WRAPDEF_C166    0 /* create an impossible version as workaround for some MISRA check tools not allowing negative defined-check and optional value-comparision on same line */
#endif /* !_C166 && !__C166__ */

#if (defined(__GNUC__) || defined(__GNUG__)) && (!defined(__GNUC_PATCHLEVEL__)) /* is the GNU C or the GNU C++ toolchain compiling this source for XC2000? */
/* GCC provides these memory models:
   Small
   Compact
   Medium (special)
   Large

It allows to assign specific attributes like structure packing per object by appending e.g. "__attribute__ ((aligned (16), packed))".
*/
typedef unsigned long  VX1000_UINT32_;
typedef unsigned short VX1000_UINT16_;
typedef unsigned char  VX1000_UINT8_;
typedef signed long    VX1000_INT32_;
typedef signed short   VX1000_INT16_;
typedef signed char    VX1000_INT8_;


#define VX1000_INNERSTRUCT_VOLATILE    volatile
#define VX1000_STRUCTSTRUCT_VOLATILE   /* empty */
#define VX1000_OUTERSTRUCT_VOLATILE    /* empty */

#if defined(__MODEL_LARGE__)
#define VX1000_DECL_PTR_DEFAULT             huge
#define VX1000_ADDRESS_TO_POINTER_DFLT(A,T) ((T huge *)(T far *)(T huge *)(A)) /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#define VX1000_POINTER_TO_ADDRESS_DFLT(P,T) ((VX1000_UINT32)((T huge *)(P)))   /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#elif defined(__MODEL_SPECMED__)
#define VX1000_DECL_PTR_DEFAULT             far
#define VX1000_ADDRESS_TO_POINTER_DFLT(A,T) ((T far *)                                                                         \
({                                                                                                                             \
  __typeof__(A) TMP = (A);                                                                                                     \
  VX1000_UINT16 PAGE = TMP >> 14U;                                                                                             \
  VX1000_UINT16 OFS  = TMP & 0x3FFFU;                                                                                          \
  if      (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E00\n":"=&r"(DPP)); DPP;})) /* already OK */; \
  else if (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E02\n":"=&r"(DPP)); DPP;})) OFS |= 1U<<14U;   \
  else if (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E04\n":"=&r"(DPP)); DPP;})) OFS |= 2U<<14U;   \
  else if (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E06\n":"=&r"(DPP)); DPP;})) OFS |= 3U<<14U;   \
  else { OFS = 0U; /* not representable --> create a null pointer */ VX1000_ERRLOGGER(VX1000_ERRLOG_PTR_NONREPSTBL) }          \
  (T *)OFS;                                                                                                                    \
})) /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#define VX1000_POINTER_TO_ADDRESS_DFLT(P,T) ((VX1000_UINT32)((T far *)(P)))
#elif defined(__MODEL_COMPACT__)
#define VX1000_DECL_PTR_DEFAULT             /* empty (?) */
#define VX1000_ADDRESS_TO_POINTER_DFLT(A,T) ((T *)                                                                             \
({                                                                                                                             \
  __typeof__(A) TMP = (A);                                                                                                     \
  VX1000_UINT16 PAGE = TMP >> 14U;                                                                                             \
  VX1000_UINT16 OFS  = TMP & 0x3FFFU;                                                                                          \
  if      (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E00\n":"=&r"(DPP)); DPP;})) /* already OK */; \
  else if (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E02\n":"=&r"(DPP)); DPP;})) OFS |= 1U<<14U;   \
  else if (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E04\n":"=&r"(DPP)); DPP;})) OFS |= 2U<<14U;   \
  else if (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E06\n":"=&r"(DPP)); DPP;})) OFS |= 3U<<14U;   \
  else { OFS = 0U; /* not representable --> create a null pointer */  VX1000_ERRLOGGER(VX1000_ERRLOG_PTR_NONREPSTBL) }         \
  (T *)OFS;                                                                                                                    \
})) /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#define VX1000_POINTER_TO_ADDRESS_DFLT(P, T)                                                                                                                                     \
({                                                                                                                                                                               \
  VX1000_UINT32 TMP = (VX1000_UINT32)(P);                                                                                                                                        \
  switch (((VX1000_UINT16)(TMP)) >> 14U)                                                                                                                                         \
  {                                                                                                                                                                              \
    case 0U: TMP = (((VX1000_UINT32)({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E00\n":"=&r"(DPP)); DPP;})) << 14U) | (VX1000_UINT32)((TMP) & 0x3FFFU); break; \
    case 1U: TMP = (((VX1000_UINT32)({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E02\n":"=&r"(DPP)); DPP;})) << 14U) | (VX1000_UINT32)((TMP) & 0x3FFFU); break; \
    case 2U: TMP = (((VX1000_UINT32)({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E04\n":"=&r"(DPP)); DPP;})) << 14U) | (VX1000_UINT32)((TMP) & 0x3FFFU); break; \
    case 3U: TMP = (((VX1000_UINT32)({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E06\n":"=&r"(DPP)); DPP;})) << 14U) | (VX1000_UINT32)((TMP) & 0x3FFFU); break; \
  }                                                                                                                                                                              \
  TMP;                                                                                                                                                                           \
}) /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#else /* small */
#define VX1000_DECL_PTR_DEFAULT        /* empty */
#define VX1000_ADDRESS_TO_POINTER_DFLT(A,T) ((T *)                                                                             \
({                                                                                                                             \
  __typeof__(A) TMP = (A);                                                                                                     \
  VX1000_UINT16 PAGE = TMP >> 14U;                                                                                             \
  VX1000_UINT16 OFS  = TMP & 0x3FFFU;                                                                                          \
  if      (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E00\n":"=&r"(DPP)); DPP;})) /* already OK */; \
  else if (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E02\n":"=&r"(DPP)); DPP;})) OFS |= 1U<<14U;   \
  else if (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E04\n":"=&r"(DPP)); DPP;})) OFS |= 2U<<14U;   \
  else if (PAGE == ({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E06\n":"=&r"(DPP)); DPP;})) OFS |= 3U<<14U;   \
  else { OFS = 0U; /* not representable --> create a null pointer */ VX1000_ERRLOGGER(VX1000_ERRLOG_PTR_NONREPSTBL) }          \
  (T *) OFS;                                                                                                                   \
})) /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#define VX1000_POINTER_TO_ADDRESS_DFLT(P, T)                                                                                                                                     \
({                                                                                                                                                                               \
  VX1000_UINT32 TMP = (VX1000_UINT32)(P);                                                                                                                                        \
  switch (((VX1000_UINT16)(TMP)) >> 14U)                                                                                                                                         \
  {                                                                                                                                                                              \
    case 0U: TMP = (((VX1000_UINT32)({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E00\n":"=&r"(DPP)); DPP;})) << 14U) | (VX1000_UINT32)((TMP) & 0x3FFFU); break; \
    case 1U: TMP = (((VX1000_UINT32)({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E02\n":"=&r"(DPP)); DPP;})) << 14U) | (VX1000_UINT32)((TMP) & 0x3FFFU); break; \
    case 2U: TMP = (((VX1000_UINT32)({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E04\n":"=&r"(DPP)); DPP;})) << 14U) | (VX1000_UINT32)((TMP) & 0x3FFFU); break; \
    case 3U: TMP = (((VX1000_UINT32)({VX1000_UINT16 DPP; __asm__ volatile ("extp #3,#1\nmov %0,0x3E06\n":"=&r"(DPP)); DPP;})) << 14U) | (VX1000_UINT32)((TMP) & 0x3FFFU); break; \
  }                                                                                                                                                                              \
  TMP;                                                                                                                                                                           \
}) /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#endif /* small or compact */
#define VX1000_OBJAT /* __attribute__((aligned(ADDR))) -- empty: GCC does not support this tasking-proprietary language extension. Macro's semantic must be changed --> pass address as parameter! */


#elif (defined(_C166) && (((VX1000_TASKING_WRAPDEF_C166) >= 60) && ((VX1000_TASKING_WRAPDEF_C166) <= 100))) /* is it a valid tasking_classic compiler version for XC2000? */
/*
Tasking classic offers these pointer classes to c programmers:
   _xnear       --> 14-bit-arithmetic inside DPP1 page (DPP1 must point to the page that contains the stack)
   _near        --> 14-bit-arithmetic inside DPP2/DPP0 page (DPP2/DPP0 defined freely at link stage for data/const)
   _system      --> 14-bit-arithmetic inside DPP3 page with DPP3 being fixed to the CPU-SFR page
   _far         --> 14-bit-arithmetic inside a page addressed by bits 16..25. (note: far function pointers handled differently!)
   _shuge       --> 16-bit-arithmetic inside any segment (the compiler generates code to push-modify-use-pop a DPP of its choice)
   _huge        --> 24-bit-arithmetic also across page/segment boundaries (the compiler generates EXTS-prefixes for each access)
   _iram        --> same as _system, just that object size is further limited
   _bita        --> same as _iram, just that object types are further limited

Whether a class is actually available depends on the "-m XXX" command line switch that selects one of these memory models:
   tiny         --> forbids usage of _xnear, _far, _shuge, _huge; implies _near for everything; DPPx fixed for "linear-like" addresses
   small        --> implies _near for const and data and _huge for text
   medium       --> implies _near for text
   large        --> implies _far for const and data and _huge for text
   huge         --> implies _huge for everything

The compiler provides an intrinsic define called "_MODEL" so an application can choose the right pointer class e.g. for "'t'".
*/
typedef unsigned long  VX1000_UINT32_;
typedef unsigned short VX1000_UINT16_;
typedef unsigned char  VX1000_UINT8_;
typedef signed long    VX1000_INT32_;
typedef signed short   VX1000_INT16_;
typedef signed char    VX1000_INT8_;

#if (_MODEL == 't')                    /* 16bit linear addressing, pointers are _always_ 2 bytes */
#define VX1000_DECL_PTR_DEFAULT        _near
#define VX1000_ADDRESS_TO_POINTER_DFLT(A, T)   ((T _near *)(A))                        /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#define VX1000_POINTER_TO_ADDRESS_DFLT(P, T)   ((VX1000_UINT32)(P))
#else /* _MODEL != 't' */              /* potentially weird addressing, force pointers to use 24bit linear addressing, stored in 4 bytes */
#define VX1000_DECL_PTR_DEFAULT _huge
#define VX1000_ADDRESS_TO_POINTER_DFLT(A, T)   ((T _huge *)(A))                        /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#define VX1000_POINTER_TO_ADDRESS_DFLT(P, T)   ((VX1000_UINT32)(P))
#endif /* _MODEL != 't' */
#define VX1000_OBJAT                   _at


#elif defined (__C166__)               /* is it any other XC2000 tool chain? */

#if (defined(__VERSION__) && (((VX1000_TASKING_WRAPDEF_C166) >= 1000) && ((VX1000_TASKING_WRAPDEF_C166) <= 5000))) /* is it a valid tasking_VX compiler version? */

/*
Tasking VX offers these pointer classes to c programmers:
   __near       --> 16-bit-arithmetic using virtual 64K address space (fix DPPx then freely map the result to physical 16M address space)
   __far        --> 14-bit-arithmetic inside a page addressed by bits 16..25 (the compiler generates EXTP-prefixes for each access)
   __shuge      --> 16-bit-arithmetic inside any segment (the compiler generates EXTS-prefixes for each access)
   __huge       --> 24-bit-arithmetic also across page/segment boundaries
   __iram       --> same as __near, just that address range is further limited
   __bita       --> same as __iram, just that object types are further limited
   __bit        --> same as __iram, just that object types are further limited and using only 12-bit pointer-arithmetic

The default pointer class for const and data depends on the "--model=XXX" command line switch that selects one of these memory models:
   near         --> implies __near (attention with the __CONTIGUOUS_NEAR trick: depending on the DPPx initialisation, results of near versus non-near pointer arithmetic may differ!)
   far          --> implies __far
   shuge        --> implies __shuge
   huge         --> implies __huge

Note that the "--near-threshold=xxx" command line switch may overrule the default for specific (small) objects.
The default pointer class for functions is always __huge unless overridden to __near via the "--near-functions" command line switch.

The compiler provides an intrinsic define called "__MODEL__" so an application can choose the right pointer class e.g. for "'h'".
*/
typedef unsigned long  VX1000_UINT32_;
typedef unsigned short VX1000_UINT16_;
typedef unsigned char  VX1000_UINT8_;
typedef signed long    VX1000_INT32_;
typedef signed short   VX1000_INT16_;
typedef signed char    VX1000_INT8_;

#define VX1000_DECL_PTR_DEFAULT             __huge
#define VX1000_ADDRESS_TO_POINTER_DFLT(A, T) ((T __huge *)(A))                         /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#define VX1000_POINTER_TO_ADDRESS_DFLT(P, T) ((VX1000_UINT32)(P))
#define VX1000_OBJAT                        __at
#define VX1000_INNERSTRUCT_VOLATILE         volatile
#define VX1000_STRUCTSTRUCT_VOLATILE        /* empty */
#define VX1000_OUTERSTRUCT_VOLATILE         /* empty */

#elif (__C166__ != 1)                  /* _seems_ to be a Keil compiler (?) -- completely untested! */

/* KEIL provides these memory models:
   Tiny
   Small
   Compact
   Hcompact
   Medium
   Large
   Hlarge

It supports the "#pragma pack" and the "#pragma bytealign" switches to change structure member padding, but probably default packing is OK for our uint16s.
*/
typedef unsigned long  VX1000_UINT32_;
typedef unsigned short VX1000_UINT16_;
typedef unsigned char  VX1000_UINT8_;
typedef signed long    VX1000_INT32_;
typedef signed short   VX1000_INT16_;
typedef signed char    VX1000_INT8_;

#define VX1000_DECL_PTR_DEFAULT             xhuge /* might need a 2nd define that is used everywhere IN FRONT of the type (?) */
#define VX1000_ADDRESS_TO_POINTER_DFLT(A, T) ((T xhuge *)(A))  /* might be ((xhuge VX1000_UINT8 *)(p)) instead? */ /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#define VX1000_POINTER_TO_ADDRESS_DFLT(P, T) ((VX1000_UINT32)(P))
#define VX1000_OBJAT                        /* empty: keil does not support this tasking-proprietary language extension. Standard section method must be used! */
#define VX1000_INNERSTRUCT_VOLATILE         volatile
#define VX1000_STRUCTSTRUCT_VOLATILE        /* empty */
#define VX1000_OUTERSTRUCT_VOLATILE         /* empty */

#else  /* !TaskingVX & !Keil */
typedef unsigned long  VX1000_UINT32_;
typedef unsigned short VX1000_UINT16_;
typedef unsigned char  VX1000_UINT8_;
typedef signed long    VX1000_INT32_;
typedef signed short   VX1000_INT16_;
typedef signed char    VX1000_INT8_;
#define VX1000_OBJAT                   /* empty: user shall use the pragmas offered by his unsupported compiler! */

#endif /* !TaskingVX & !Keil */

#else /* !<C166/C167/XC164/XC2000/XE166 compiler> */

/* The user header must be able to provide callback prototypes with VX data types, therefore the types must be located before the header include */

#if defined(__LP64__) || defined(__ARM_64BIT_STATE)
typedef unsigned int   VX1000_UINT32_;
#else  /* !__LP64__ && !__ARM_64BIT_STATE */
typedef unsigned long  VX1000_UINT32_;
#endif /* !__LP64__ && !__ARM_64BIT_STATE */
typedef unsigned short VX1000_UINT16_;
typedef unsigned char  VX1000_UINT8_;
#if defined(__LP64__) || defined(__ARM_64BIT_STATE)
typedef signed int     VX1000_INT32_;
#else  /* !__LP64__ && !__ARM_64BIT_STATE */
typedef signed long    VX1000_INT32_;
#endif /* !__LP64__ && !__ARM_64BIT_STATE */
typedef signed short   VX1000_INT16_;
typedef signed char    VX1000_INT8_;
#define VX1000_OBJAT   __at /* Tasking syntax storage qualifier - normally unused */   /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */

#if !defined(VX1000_DECL_PTR_DEFAULT)
#define VX1000_DECL_PTR_DEFAULT             /* empty */
#endif /* !VX1000_DECL_PTR_DEFAULT */
#if !defined(VX1000_ADDRESS_TO_POINTER_DFLT)
#define VX1000_ADDRESS_TO_POINTER_DFLT(A, T) ((/*NO parentheses here!*/T *)(A))        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */ /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#endif /* !VX1000_ADDRESS_TO_POINTER_DFLT */
#if !defined(VX1000_POINTER_TO_ADDRESS_DFLT)
#define VX1000_POINTER_TO_ADDRESS_DFLT(P, T) ((VX1000_UINT32)(P))                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_POINTER_TO_ADDRESS_DFLT */
#define VX1000_INNERSTRUCT_VOLATILE         /* empty */
#define VX1000_STRUCTSTRUCT_VOLATILE        /* empty */
#define VX1000_OUTERSTRUCT_VOLATILE         volatile

#endif /* !<C166/C167/XC164/XC2000/XE166 compiler> */

#define VX1000_INT16                   VX1000_INT16_                                   /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#define VX1000_INT32                   VX1000_INT32_                                   /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#define VX1000_INT8                    VX1000_INT8_                                    /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#define VX1000_UINT16                  VX1000_UINT16_                                  /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#define VX1000_UINT32                  VX1000_UINT32_                                  /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#define VX1000_UINT8                   VX1000_UINT8_                                   /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#define VX1000_VOID                    VX1000_VOID_                                    /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */

/* Needed as alternative to VX1000_UINT8 because signed-ness of potentially referred compiler intrinsics like __date, __file etc. actually depends on makefile/compile options: */
typedef char                           VX1000_CHAR;

/* These are just needed by HBB feature and for "sizeof" expression in Debug printf feature. We define them always for the sake of simplicity:  */
typedef int                            VX1000_INT;

typedef long                           VX1000_LONG;

typedef float                          VX1000_FLOAT;

typedef double                         VX1000_DOUBLE;

typedef long double                    VX1000_LDOUBL;

typedef void                           VX1000_VOID_;

typedef void (*VX1000_VVFUNCP_T)(void);
typedef VX1000_UINT32  /* codeSize in DWords */ (VX1000_VUFUNC_T)(VX1000_UINT32 Addr/*DAQ: dstAddr / STIM: srcAddr*/ , VX1000_UINT32 t0, VX1000_UINT32 evSync);
typedef VX1000_VUFUNC_T * VX1000_VUFUNCP_T;


/*------------------------------------------------------------------------------ */
/* constants                                                                     */
#define VX1000_RELEASED                0x0U
#define VX1000_TESTED                  0x1U
#define VX1000_BETA                    0x2U
#define VX1000_ALPHA                   0x3U
#define VX1000_ASSEMBLY_IS_PRECOMPILED /* Inform VX1000_cfg.h that handwritten assembler instructions are precompiled and thus independent from syntax of specific compilers */


/*------------------------------------------------------------------------------ */
/* Configuration                                                                 */

/* Include user specified defines and fetch prototypes of user callbacks (has to be done before switching sections) */
#include "VX1000_cfg.h"  /* PRQA S 0883 */ /* Willingly violating MISRA rule 19.15: this file is included multiple times because it contains multiple disjunct parts that each are filtered exactly once by preprocessor conditions */ /* PRQA S 5087*/ /* Willingly violating MISRA rule 19.1: this file is included multiple at exactly those lines where it is needed to expand to the desired lines. Inclusion/expansion of those lines at the top of this file would not work */
#if defined(VX1000_MAILBOX_PRINTF)
#include <stdarg.h>
#endif /* VX1000_MAILBOX_PRINTF */

#if   defined(VX1000_TARGET_ARM)
#elif defined(VX1000_TARGET_POWERPC)
#elif defined(VX1000_TARGET_SH2)
#elif defined(VX1000_TARGET_TMS570)
#elif defined(VX1000_TARGET_TRICORE)
#elif defined(VX1000_TARGET_X850)
#elif defined(VX1000_TARGET_XC2000)
#else /* !VX1000_TARGET_<target> */
#define VX1000_CFG_NO_TARGET
#endif /* !VX1000_TARGET_<target> */
#if defined(VX1000_CFG_NO_TARGET)
/* workarounds for users of the mini-configuration-template: */
#if !defined(VX1000_DERIVATIVE_CLASS)
#error You must define the appropriate VX1000_TARGET_<target> in VX1000_cfg.h!
#elif ((VX1000_DERIVATIVE_CLASS) >= 0x10U)
#error You must define the appropriate VX1000_TARGET_<target> in VX1000_cfg.h!
#elif ((VX1000_DERIVATIVE_CLASS) < 1U)
#define VX1000_TARGET_ARM /* as no HW-specific features can be enabled in the mini-configuration, this dummy selection of ARM will work for any target */
#else  /* VX1000_DERIVATIVE_CLASS == TriCore */
#define VX1000_TARGET_TRICORE /* this selection allows to enable HW features that make the life of PMC9 easier with TC2xx/TC3xx customers */
#endif /* VX1000_DERIVATIVE_CLASS == TriCore */
#endif /* !VX1000_CFG_NO_TARGET */


#define VX1000_EVENT_IS_UNUSED         0x0UL
#define VX1000_EVENT_USES_ONLY_TRIGGER 0x1UL                            /* ASAM POD name for normal events */
#define VX1000_EVENT_NORMAL            (VX1000_EVENT_USES_ONLY_TRIGGER) /* Vector name (introduced in 4.9) */
#if defined(VX1000_SUPPRESS_IPO_API)
#define VX1000_EVENT_ALSO_USES_BARRIER (VX1000_EVENT_USES_ONLY_TRIGGER)
#else  /* !VX1000_SUPPRESS_IPO_API */
#define VX1000_EVENT_ALSO_USES_BARRIER 0x3UL
#endif /* !VX1000_SUPPRESS_IPO_API */
#if defined(VX1000_IGNORE_MBUF_EVENTMODE)
#define VX1000_EVENT_MBUF_ONLY_TRIGGER (VX1000_EVENT_USES_ONLY_TRIGGER)
#else  /* !VX1000_IGNORE_MBUF_EVENTMODE */
#define VX1000_EVENT_MBUF_ONLY_TRIGGER 0x5UL
#endif /* !VX1000_IGNORE_MBUF_EVENTMODE */
#if defined(VX1000_SUPPRESS_IPO_API)
#define VX1000_EVENT_ALWAYS_USE_BARRIER (VX1000_EVENT_USES_ONLY_TRIGGER)
#else  /* !VX1000_SUPPRESS_IPO_API */
#define VX1000_EVENT_ALWAYS_USE_BARRIER 0xBUL
#endif /* !VX1000_SUPPRESS_IPO_API */
#define VX1000_EVENT_IS_RESERVED       (VX1000_EVENT_IS_UNUSED) /* just an alias name */


#if !defined(VX1000_DISABLE_INSTRUMENTATION)
#if defined(VX1000_TARGET_XC2000) || (defined(VX1000_TARGET_X850) /* || defined(VX1000_TARGET_TRICORE) */)
/* no 64bit integer data type known on XC2000/V850 ... must live without it (and indeed we can) */
#else  /* !VX1000_TARGET_XC2000 & !VX1000_TARGET_X850 & !VX1000_TARGET_TRICORE */

/* As 64bit is no standard data type, it normally comes from the user. Therefore the default
definition must be placed after the include of the user header. To be able to avoid conflicts
between the VX1000_UINT64 coming from the user and the A_UINT64 coming from the standard
header, the AppDriver internally has to use now a third name: VX1000_UINT64_ which is just
a define to one of both. This way we stay compatible to both worlds: */
#if defined(A_UINT64)
#define VX1000_UINT64_T                A_UINT64                                        /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#elif defined(VX1000_UINT64)
#define VX1000_UINT64_T                VX1000_UINT64                                   /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#endif /* VX1000_UINT64 */

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

#endif /* !VX1000_TARGET_XC2000 & !VX1000_TARGET_X850 & !VX1000_TARGET_TRICORE */

#if ((!defined(VX1000_DECL_PTR_DEFAULT)) && (!defined(VX1000_DECL_PTR))) || (((!defined(VX1000_ADDRESS_TO_POINTER_DFLT)) && (!defined(VX1000_ADDRESS_TO_POINTER))) || ((!defined(VX1000_POINTER_TO_ADDRESS_DFLT)) && (!defined(VX1000_POINTER_TO_ADDRESS))))
#error Unsupported compiler; please provide the macros VX1000_DECL_PTR, VX1000_ADDRESS_TO_POINTER and VX1000_POINTER_TO_ADDRESS!
#endif /* !VX1000_DECL_PTR_DEFAULT | !VX1000_ADDRESS_TO_POINTER | !VX1000_POINTER_TO_ADDRESS */

#if (!defined(VX1000_INNERSTRUCT_VOLATILE)) || ((!defined(VX1000_STRUCTSTRUCT_VOLATILE)) || (!defined(VX1000_OUTERSTRUCT_VOLATILE)))
#error Unsupported compiler; please provide the macros VX1000_INNERSTRUCT_VOLATILE, VX1000_STRUCTSTRUCT_VOLATILE and VX1000_OUTERSTRUCT_VOLATILE!
#endif /* !VX1000_INNERSTRUCT_VOLATILE | !VX1000_STRUCTSTRUCT_VOLATILE | !VX1000_OUTERSTRUCT_VOLATILE */


#if !defined(VX1000_DECL_PTR)
#define VX1000_DECL_PTR                VX1000_DECL_PTR_DEFAULT                                                               /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#endif /* !VX1000_DECL_PTR */
#if !defined(VX1000_ADDRESS_TO_POINTER)
#define VX1000_ADDRESS_TO_POINTER(A, T) /*lint -e(923) OK*/(VX1000_ADDRESS_TO_POINTER_DFLT((A), /*NO parentheses here!*/T))  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */ /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#endif /* !VX1000_ADDRESS_TO_POINTER */
#if !defined(VX1000_POINTER_TO_ADDRESS)
#define VX1000_POINTER_TO_ADDRESS(P, T) /*lint -e(923) OK*/(VX1000_POINTER_TO_ADDRESS_DFLT((P), /*NO parentheses here!*/T))  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */ /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#endif /* !VX1000_POINTER_TO_ADDRESS */



#if !defined(VX1000_ADDR_TO_PTR2C)
#define VX1000_ADDR_TO_PTR2C(A)        VX1000_ADDRESS_TO_POINTER((A), VX1000_CHAR)                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2C */
#if !defined(VX1000_ADDR_TO_PTR2U16)
#define VX1000_ADDR_TO_PTR2U16(A)      VX1000_ADDRESS_TO_POINTER((A), VX1000_UINT16)                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2U16 */
#if !defined(VX1000_ADDR_TO_PTR2PTR2U32)
#define VX1000_ADDR_TO_PTR2PTR2U32(A)  VX1000_ADDRESS_TO_POINTER((A), VX1000_UINT32 *)                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2PTR2U32 */
#if !defined(VX1000_ADDR_TO_PTR2VMC)
#define VX1000_ADDR_TO_PTR2VMC(A)      VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_MEMSYNC_CPY_T)                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VMC */
#if !defined(VX1000_ADDR_TO_PTR2VU32)
#define VX1000_ADDR_TO_PTR2VU32(A)     VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_UINT32)                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VU32 */
#if !defined(VX1000_ADDR_TO_PTR2VU16)
#define VX1000_ADDR_TO_PTR2VU16(A)     VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_UINT16)                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VU16 */
#if !defined(VX1000_ADDR_TO_PTR2VF)
#define VX1000_ADDR_TO_PTR2VF(A)       VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_FLOAT)                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VF */
#if !defined(VX1000_ADDR_TO_PTR2VD)
#define VX1000_ADDR_TO_PTR2VD(A)       VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_DOUBLE)                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VD */
#if !defined(VX1000_ADDR_TO_PTR2VVX)
#define VX1000_ADDR_TO_PTR2VVX(A)      VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_STRUCT_T)                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VVX */
#if !defined(VX1000_ADDR_TO_PTR2VMT)
#define VX1000_ADDR_TO_PTR2VMT(A)      VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_MEMSYNC_TRIG_T)                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VMT */
#if !defined(VX1000_ADDR_TO_PTR2VU8)
#define VX1000_ADDR_TO_PTR2VU8(A)      VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_UINT8)                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VU8 */
#if !defined(VX1000_ADDR_TO_PTR2U8)
#define VX1000_ADDR_TO_PTR2U8(A)       VX1000_ADDRESS_TO_POINTER((A), VX1000_UINT8)                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2U8 */
#if !defined(VX1000_ADDR_TO_PTR2EH)
#define VX1000_ADDR_TO_PTR2EH(A)       VX1000_ADDRESS_TO_POINTER((A), VX1000_EMEM_HDR_T)                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2EH */
#if !defined(VX1000_ADDR_TO_PTR2FW)
#define VX1000_ADDR_TO_PTR2FW(A)       VX1000_ADDRESS_TO_POINTER((A), VX1000_FKL_WORKSPACE_T)                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2FW */
#if !defined(VX1000_ADDR_TO_PTR2VU64)
#define VX1000_ADDR_TO_PTR2VU64(A)     VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_UINT64_T)                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VU64 */
#if !defined(VX1000_ADDR_TO_PTR2SL)
#define VX1000_ADDR_TO_PTR2SL(A)       VX1000_ADDRESS_TO_POINTER((A), VX1000_DYNADDRSIG_STATIC_T)                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2SL */
#if !defined(VX1000_ADDR_TO_PTR2U32)
#define VX1000_ADDR_TO_PTR2U32(A)      VX1000_ADDRESS_TO_POINTER((A), VX1000_UINT32)                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2U32 */
#if !defined(VX1000_ADDR_TO_PTR2OE)
#define VX1000_ADDR_TO_PTR2OE(A)       VX1000_ADDRESS_TO_POINTER((A), VX1000_OLDA_EVENT_T)                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2OE */
#if !defined(VX1000_ADDR_TO_PTR2V)
#define VX1000_ADDR_TO_PTR2V(A)        VX1000_ADDRESS_TO_POINTER((A), void)                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2V */
#if !defined(VX1000_ADDR_TO_PTR2VV)
#define VX1000_ADDR_TO_PTR2VV(A)       VX1000_ADDRESS_TO_POINTER((A), volatile void)                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VV */
#if !defined(VX1000_ADDR_TO_PTR2VCC)
#define VX1000_ADDR_TO_PTR2VCC(A)      VX1000_ADDRESS_TO_POINTER((A), volatile const VX1000_CHAR)                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VCC */
#if !defined(VX1000_ADDR_TO_PTR2VC)
#define VX1000_ADDR_TO_PTR2VC(A)       VX1000_ADDRESS_TO_POINTER((A), volatile VX1000_CHAR)                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VC */
#if !defined(VX1000_ADDR_TO_PTR2VCU8)
#define VX1000_ADDR_TO_PTR2VCU8(A)     VX1000_ADDRESS_TO_POINTER((A), volatile const VX1000_UINT8)                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VCU8 */
#if !defined(VX1000_ADDR_TO_PTR2VCU32)
#define VX1000_ADDR_TO_PTR2VCU32(A)    VX1000_ADDRESS_TO_POINTER((A), volatile const VX1000_UINT32)                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VCU32 */
#if !defined(VX1000_ADDR_TO_PTR2OCR)
#define VX1000_ADDR_TO_PTR2OCR(A)      VX1000_ADDRESS_TO_POINTER((A), VX1000_OVL_CONFIG_REGS_T)                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2OCR */
#if !defined(VX1000_ADDR_TO_PTR2VTE)
#define VX1000_ADDR_TO_PTR2VTE(A)      VX1000_ADDRESS_TO_POINTER((A), VX1000_HBB_VX_TABLE_ENTRY_T)                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2VTE */
#if !defined(VX1000_ADDR_TO_PTR2OCB)
#define VX1000_ADDR_TO_PTR2OCB(A)      VX1000_ADDRESS_TO_POINTER((A), VX1000_VUFUNC_T)                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2OCB */
#if !defined(VX1000_PTR2VU16_TO_ADDRESS)
#define VX1000_PTR2VU16_TO_ADDRESS(P)  VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_UINT16)                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VU16_TO_ADDRESS */
#if !defined(VX1000_PTR2VU32_TO_ADDRESS)
#define VX1000_PTR2VU32_TO_ADDRESS(P)  VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_UINT32)                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VU32_TO_ADDRESS */
#if !defined(VX1000_PTR2VU64_TO_ADDRESS)
#define VX1000_PTR2VU64_TO_ADDRESS(P)  VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_UINT64_T)                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VU64_TO_ADDRESS */
#if !defined(VX1000_PTR2VF_TO_ADDRESS)
#define VX1000_PTR2VF_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_FLOAT)                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VF_TO_ADDRESS */
#if !defined(VX1000_PTR2VD_TO_ADDRESS)
#define VX1000_PTR2VD_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_DOUBLE)                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VD_TO_ADDRESS */
#if !defined(VX1000_PTR2VVX_TO_ADDRESS)
#define VX1000_PTR2VVX_TO_ADDRESS(P)   VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_STRUCT_T)                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VVX_TO_ADDRESS */
#if !defined(VX1000_PTR2VU8_TO_ADDRESS)
#define VX1000_PTR2VU8_TO_ADDRESS(P)   VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_UINT8)                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VU8_TO_ADDRESS */
#if !defined(VX1000_PTR2SPS_TO_ADDRESS)
#define VX1000_PTR2SPS_TO_ADDRESS(P)   VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_SYNCAL_PAGE_SWITCH_T)           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2SPS_TO_ADDRESS */
#if !defined(VX1000_PTR2OCR_TO_ADDRESS)
#define VX1000_PTR2OCR_TO_ADDRESS(P)   VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_OVL_CONFIG_REGS_T)              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2OCR_TO_ADDRESS */
#if !defined(VX1000_PTR2VI32_TO_ADDRESS)
#define VX1000_PTR2VI32_TO_ADDRESS(P)  VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_INT32)                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VI32_TO_ADDRESS */
#if !defined(VX1000_PTR2VFF_TO_ADDRESS)
#define VX1000_PTR2VFF_TO_ADDRESS(P)   VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_FKL_FCT)                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VFF_TO_ADDRESS */
#if !defined(VX1000_PTR2SL_TO_ADDRESS)
#define VX1000_PTR2SL_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), const VX1000_DYNADDRSIG_STATIC_T*)              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2SL_TO_ADDRESS */
#if !defined(VX1000_PTR2U32_TO_ADDRESS)
#define VX1000_PTR2U32_TO_ADDRESS(P)   VX1000_POINTER_TO_ADDRESS((P), VX1000_UINT32)                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2U32_TO_ADDRESS */
#if !defined(VX1000_PTR2U8_TO_ADDRESS)
#define VX1000_PTR2U8_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), VX1000_UINT8)                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2U8_TO_ADDRESS */
#if !defined(VX1000_PTR2VM_TO_ADDRESS)
#define VX1000_PTR2VM_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_MAILBOX_T)                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VM_TO_ADDRESS */
#if !defined(VX1000_PTR2CU8_TO_ADDRESS)
#define VX1000_PTR2CU8_TO_ADDRESS(P)   VX1000_POINTER_TO_ADDRESS((P), const VX1000_UINT8)                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2CU8_TO_ADDRESS */
#if !defined(VX1000_PTR2CU32_TO_ADDRESS)
#define VX1000_PTR2CU32_TO_ADDRESS(P)  VX1000_POINTER_TO_ADDRESS((P), const VX1000_UINT32)                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2CU32_TO_ADDRESS */
#if !defined(VX1000_PTR2VO_TO_ADDRESS)
#define VX1000_PTR2VO_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_OLDA_T)                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VO_TO_ADDRESS */
#if !defined(VX1000_PTR2U16_TO_ADDRESS)
#define VX1000_PTR2U16_TO_ADDRESS(P)   VX1000_POINTER_TO_ADDRESS((P), VX1000_UINT16)                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2U16_TO_ADDRESS */
#if !defined(VX1000_PTR2VS_TO_ADDRESS)
#define VX1000_PTR2VS_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_STIM_T)                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VS_TO_ADDRESS */
#if !defined(VX1000_PTR2MC_TO_ADDRESS)
#define VX1000_PTR2MC_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), VX1000_MEMSYNC_CPY_T)                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2MC_TO_ADDRESS */
#if !defined(VX1000_PTR2MT_TO_ADDRESS)
#define VX1000_PTR2MT_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_MEMSYNC_TRIG_T)                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2MT_TO_ADDRESS */
#if !defined(VX1000_PTR2VRM_TO_ADDRESS)
#define VX1000_PTR2VRM_TO_ADDRESS(P)   VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_RES_MGMT_T)                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VRM_TO_ADDRESS */
#if !defined(VX1000_PTR2VEHM_TO_ADDRESS)
#define VX1000_PTR2VEHM_TO_ADDRESS(P)  VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_EMEM_HDR_T)                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VEHM_TO_ADDRESS */
#if !defined(VX1000_PTR2V_TO_ADDRESS)
#define VX1000_PTR2V_TO_ADDRESS(P)     VX1000_POINTER_TO_ADDRESS((P), void)                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2V_TO_ADDRESS */
#if !defined(VX1000_PTR2VOVL_TO_ADDRESS)
#define VX1000_PTR2VOVL_TO_ADDRESS(P)  VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_OVL_T)                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VOVL_TO_ADDRESS */
#if !defined(VX1000_PTR2SE_TO_ADDRESS)
#define VX1000_PTR2SE_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_STIM_EVENT_T)                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2SE_TO_ADDRESS */
#if !defined(VX1000_PTR2CC_TO_ADDRESS)
#define VX1000_PTR2CC_TO_ADDRESS(P)    VX1000_POINTER_TO_ADDRESS((P), const VX1000_CHAR)                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2CC_TO_ADDRESS */
#if !defined(VX1000_PTR2C_TO_ADDRESS)
#define VX1000_PTR2C_TO_ADDRESS(P)     VX1000_POINTER_TO_ADDRESS((P), VX1000_CHAR)                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2C_TO_ADDRESS */
#if !defined(VX1000_PTR2VC_TO_ADDRESS)
#define VX1000_PTR2VC_TO_ADDRESS(P)     VX1000_POINTER_TO_ADDRESS((P), volatile VX1000_CHAR)                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_PTR2VC_TO_ADDRESS */
#if !defined(VX1000_ADDR_TO_PTR2MBOE)
#define VX1000_ADDR_TO_PTR2MBOE(A)     VX1000_ADDRESS_TO_POINTER((A), VX1000_MULTIBUFFER_OLDA_EVENT_T)                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide type-casting code that compiles without warnings on his toolchain */
#endif /* !VX1000_ADDR_TO_PTR2MBOE */

#if !defined(VX1000_NULL)
#define VX1000_NULL                    ((VX1000_UINT32 *) 0UL)
#endif /* !VX1000_NULL */

#if !defined(VX1000_COVER)
#define VX1000_COVER(X,Y)              (Y)                                                                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the testsuite to inject instrumentation code when needed */
#endif /* !VX1000_COVER */
#if !defined(VX1000_COVER_VOID)
#define VX1000_COVER_VOID(X)           /* empty */                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the testsuite to inject instrumentation code when needed */
#endif /* !VX1000_COVER_VOID */

#if !defined(VX1000_OLDA_NOPS)
#define VX1000_OLDA_NOPS()             /* empty */                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide inline-assembly code that compiles without warnings on his toolchain */
#endif /* !VX1000_OLDA_NOPS */

#if !defined(VX1000_VA_ARG)
#define VX1000_VA_ARG                  va_arg                                                                         /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#endif /* !VX1000_VA_ARG */


#if !defined(VX1000_DUMMYREAD)
#define VX1000_DUMMYREAD(X)            /* empty */
#endif /* !VX1000_DUMMYREAD */

#if !defined(VX1000_DISCARD4DUMMYARGS)
#define VX1000_DISCARD4DUMMYARGS(T, R, A1, A2, A3, A4)  (R)
#endif /* !VX1000_DISCARD4DUMMYARGS */

#if !defined(VX1000_FUNC)
#define VX1000_FUNC(T, S)              T                                                                                                                                               /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#endif /* !VX1000_FUNC */

#if !defined(VX1000_VAR)
#define VX1000_VAR(T, S)               T                                                                                                                                               /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parenthesis would cause compilation to fail */
#endif /* !VX1000_VAR */


#if defined(VX1000_COMPILED_FOR_SLAVECORES)
/* On multi-core systems with different instruction sets, the same function must exist multiple times, so add suffixes: */
#define VX1000_SUFFU3(F, S) /*lint -e(961,960) OK*/ F ## S                                        /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */ /* PRQA S 0342 */ /* Willingly violating MISRA rule 19.13 to be able to append user-configured IDs to functions' names. User whose tool chain does not support this syntax will not provide IDs */
#define VX1000_SUFFU2(F, S) /*lint -e(961,960) OK*/ VX1000_SUFFU3(F, S)                           /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */
#define VX1000_SUFFUN(F) /*lint -e(961,960) OK*/ VX1000_SUFFU2(F, VX1000_COMPILED_FOR_SLAVECORES) /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */
#else /* !VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_SUFFUN(F)               F /* direct mapping */                                     /* PRQA S 3410 */ /* Willingly violating MISRA rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES */

#if defined(VX1000_ADADDONS_BUILDNUMBER_H)
#if !defined(VX1000_MEMSYNC_TRIGGER_COUNT)
#define VX1000_MEMSYNC_TRIGGER_COUNT   0U  /* this misplaced default setting is just a workaround for AddOns file split dependencies in some configurations. The REAL place for default settings is way down */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#include "VX1000_addons.h"                 /* basically included too early. should be included after ALL default settings and consistency checks have been done! */
#endif /* VX1000_ADADDONS_BUILDNUMBER_H */
#if !defined(VX1000_ADDOFS)
#define VX1000_ADDOFS(IDX)             0UL                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_ADDOFS */

/* Default SFR sections */
#define VX1000_SFR_SECTION_UNUSED      0
#define VX1000_SFR_SECTION_COUNT       1

#if !defined(VX1000_SFR_SECTION_WDT)
#define VX1000_SFR_SECTION_WDT         (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_WDT */

#if !defined(VX1000_SFR_SECTION_OIFM)
#define VX1000_SFR_SECTION_OIFM        (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OIFM */

#if !defined(VX1000_SFR_SECTION_OCNTRL)
#define VX1000_SFR_SECTION_OCNTRL      (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OCNTRL */

#if !defined(VX1000_SFR_SECTION_PORT20)
#define VX1000_SFR_SECTION_PORT20      (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_PORT20 */

#if !defined(VX1000_SFR_SECTION_PORT21)
#define VX1000_SFR_SECTION_PORT21      (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_PORT21 */

#if !defined(VX1000_SFR_SECTION_PORT22)
#define VX1000_SFR_SECTION_PORT22      (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_PORT22 */

#if (!defined(VX1000_SFR_SECTION_HSSL0)) && defined(VX1000_SFR_SECTION_HSSL)
#define VX1000_SFR_SECTION_HSSL0       (VX1000_SFR_SECTION_HSSL)
#elif !defined(VX1000_SFR_SECTION_HSSL0)
#define VX1000_SFR_SECTION_HSSL0       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_HSSL0 */

#if !defined(VX1000_SFR_SECTION_HSSL1)
#define VX1000_SFR_SECTION_HSSL1       (VX1000_SFR_SECTION_UNUSED)
#endif /* VX1000_SFR_SECTION_HSSL1 */

#if (!defined(VX1000_SFR_SECTION_HSCT0)) && defined(VX1000_SFR_SECTION_HSCT)
#define VX1000_SFR_SECTION_HSCT0       (VX1000_SFR_SECTION_HSCT)
#elif !defined(VX1000_SFR_SECTION_HSCT0)
#define VX1000_SFR_SECTION_HSCT0       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_HSCT0 */

#if !defined(VX1000_SFR_SECTION_HSCT1)
#define VX1000_SFR_SECTION_HSCT1       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_HSCT1 */

#if !defined(VX1000_SFR_SECTION_CLOCK)
#define VX1000_SFR_SECTION_CLOCK       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_CLOCK */

#if !defined(VX1000_SFR_SECTION_BRCON)
#define VX1000_SFR_SECTION_BRCON       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_BRCON */

#if !defined(VX1000_SFR_SECTION_MEMCON)
#define VX1000_SFR_SECTION_MEMCON      (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_MEMCON */

#if !defined(VX1000_SFR_SECTION_TRACE)
#define VX1000_SFR_SECTION_TRACE       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_TRACE */

#if !defined(VX1000_SFR_SECTION_OCDS)
#define VX1000_SFR_SECTION_OCDS        (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OCDS */

#if !defined(VX1000_SFR_SECTION_SCU)
#define VX1000_SFR_SECTION_SCU         (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_SCU */

#if !defined(VX1000_SFR_SECTION_OVC0)
#define VX1000_SFR_SECTION_OVC0        (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVC0 */

#if !defined(VX1000_SFR_SECTION_OVC1)
#define VX1000_SFR_SECTION_OVC1        (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVC1 */

#if !defined(VX1000_SFR_SECTION_OVC2)
#define VX1000_SFR_SECTION_OVC2        (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVC2 */

#if !defined(VX1000_SFR_SECTION_OVC3)
#define VX1000_SFR_SECTION_OVC3        (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVC3 */

#if !defined(VX1000_SFR_SECTION_OVC4)
#define VX1000_SFR_SECTION_OVC4        (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVC4 */

#if !defined(VX1000_SFR_SECTION_OVC5)
#define VX1000_SFR_SECTION_OVC5        (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVC5 */

#if !defined(VX1000_SFR_SECTION_TC17XX)
#define VX1000_SFR_SECTION_TC17XX      (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_TC17XX */

#if !defined(VX1000_SFR_SECTION_MAGICID)
#define VX1000_SFR_SECTION_MAGICID     (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_MAGICID */

#if !defined(VX1000_SFR_SECTION_AUDMBR)
#define VX1000_SFR_SECTION_AUDMBR      (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_AUDMBR */

#if !defined(VX1000_SFR_SECTION_CFU)
#define VX1000_SFR_SECTION_CFU         (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_CFU */

#if !defined(VX1000_SFR_SECTION_DTS)
#define VX1000_SFR_SECTION_DTS         (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_DTS */

#if !defined(VX1000_SFR_SECTION_MCB)
#define VX1000_SFR_SECTION_MCB         (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_MCB */

#if !defined(VX1000_SFR_SECTION_PFLASH0)
#define VX1000_SFR_SECTION_PFLASH0     (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_PFLASH0 */

#if !defined(VX1000_SFR_SECTION_PFLASH1)
#define VX1000_SFR_SECTION_PFLASH1     (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_PFLASH1 */

#if !defined(VX1000_SFR_SECTION_SIPI0)
#define VX1000_SFR_SECTION_SIPI0       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_SIPI0 */

#if !defined(VX1000_SFR_SECTION_SIPI1)
#define VX1000_SFR_SECTION_SIPI1       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_SIPI1 */

#if !defined(VX1000_SFR_SECTION_LFAST0)
#define VX1000_SFR_SECTION_LFAST0      (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_LFAST0 */

#if !defined(VX1000_SFR_SECTION_LFAST1)
#define VX1000_SFR_SECTION_LFAST1      (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_LFAST1 */

#if !defined(VX1000_SFR_SECTION_OVLY0)
#define VX1000_SFR_SECTION_OVLY0       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVLY0 */

#if !defined(VX1000_SFR_SECTION_OVLY1)
#define VX1000_SFR_SECTION_OVLY1       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVLY1 */

#if !defined(VX1000_SFR_SECTION_OVLY2)
#define VX1000_SFR_SECTION_OVLY2       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVLY2 */

#if !defined(VX1000_SFR_SECTION_OVLY3)
#define VX1000_SFR_SECTION_OVLY3       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVLY3 */

#if !defined(VX1000_SFR_SECTION_OVLY3)
#define VX1000_SFR_SECTION_OVLY3       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVLY4 */

#if !defined(VX1000_SFR_SECTION_OVLY5)
#define VX1000_SFR_SECTION_OVLY5       (VX1000_SFR_SECTION_UNUSED)
#endif /* !VX1000_SFR_SECTION_OVLY5 */

#if defined(VX1000_SFR_WRITE_PROTECTED)
/* SFRs are write protected: SFRs are written via OS write peripheral API or via user specific functions */
#if !defined(VX1000_SFR_WRITE_8)
#error "Please define VX1000_SFR_WRITE_8 in VX1000_cfg.h because VX1000_SFR_WRITE_PROTECTED is enabled!"
#endif /* !VX1000_SFR_WRITE_8 */
#if !defined(VX1000_SFR_WRITE_16)
#error "Please define VX1000_SFR_WRITE_16 in VX1000_cfg.h because VX1000_SFR_WRITE_PROTECTED is enabled!"
#endif /* !VX1000_SFR_WRITE_16 */
#if !defined(VX1000_SFR_WRITE_32)
#error "Please define VX1000_SFR_WRITE_32 in VX1000_cfg.h because VX1000_SFR_WRITE_PROTECTED is enabled!"
#endif /* !VX1000_SFR_WRITE_32 */
#else /* !VX1000_SFR_WRITE_PROTECTED */
/* Default SFR write macros: SFRs are written directly at given address */
#define VX1000_SFR_WRITE_8(S, A, D)    ((VX1000_ADDR_TO_PTR2VU8( (VX1000_UINT32)(A)))[0] = (D))                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#define VX1000_SFR_WRITE_16(S, A, D)   ((VX1000_ADDR_TO_PTR2VU16((VX1000_UINT32)(A)))[0] = (D))                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#define VX1000_SFR_WRITE_32(S, A, D)   ((VX1000_ADDR_TO_PTR2VU32((VX1000_UINT32)(A)))[0] = (D))                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#endif /* !VX1000_SFR_WRITE_PROTECTED */

/* SFR set macros: SFR is ORed with given mask value */
#define VX1000_SFR_SET_8( S, A, D)     (VX1000_SFR_WRITE_8( (S), (A), (VX1000_UINT8)(((VX1000_UINT32)((VX1000_ADDR_TO_PTR2VU8(A))[0]))   | (VX1000_UINT32)(D)))) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#define VX1000_SFR_SET_16(S, A, D)     (VX1000_SFR_WRITE_16((S), (A), (VX1000_UINT16)(((VX1000_UINT32)((VX1000_ADDR_TO_PTR2VU16(A))[0])) | (VX1000_UINT32)(D)))) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#define VX1000_SFR_SET_32(S, A, D)     (VX1000_SFR_WRITE_32((S), (A), (VX1000_ADDR_TO_PTR2VU32(A))[0] | (D)))                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */

/* SFR clear macros: SFR is ANDed with given clear mask value */
#define VX1000_SFR_CLEAR_8( S, A, D)   (VX1000_SFR_WRITE_8( (S), (A), (VX1000_UINT8)(((VX1000_UINT32)((VX1000_ADDR_TO_PTR2VU8(A))[0]))   & (VX1000_UINT32)(D)))) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#define VX1000_SFR_CLEAR_16(S, A, D)   (VX1000_SFR_WRITE_16((S), (A), (VX1000_UINT16)(((VX1000_UINT32)((VX1000_ADDR_TO_PTR2VU16(A))[0])) & (VX1000_UINT32)(D)))) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#define VX1000_SFR_CLEAR_32(S, A, D)   (VX1000_SFR_WRITE_32((S), (A), (VX1000_ADDR_TO_PTR2VU32(A))[0] & (D)))                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */

/* SFR modify macros: SFR is ANDed with given clear mask value and then ORed with given set mask value */
#define VX1000_SFR_MODIFY_8( S, A, CLR, SET)  (VX1000_SFR_WRITE_8( (S), (A), (VX1000_UINT8)(((VX1000_UINT32)((VX1000_ADDR_TO_PTR2VU8(A))[0])   & (VX1000_UINT32)(CLR)) | (VX1000_UINT32)(SET)))) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#define VX1000_SFR_MODIFY_16(S, A, CLR, SET)  (VX1000_SFR_WRITE_16((S), (A), (VX1000_UINT16)(((VX1000_UINT32)((VX1000_ADDR_TO_PTR2VU16(A))[0]) & (VX1000_UINT32)(CLR)) | (VX1000_UINT32)(SET)))) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#define VX1000_SFR_MODIFY_32(S, A, CLR, SET)  (VX1000_SFR_WRITE_32((S), (A), ((VX1000_ADDR_TO_PTR2VU32(A))[0] & (CLR)) | (SET)))                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */


#if defined(VX1000_TARGET_TRICORE)

/*------------------------------------------------------------------------------ */
/* TriCore related defines                                                       */

#define VX1000_JTAGID_PN_TC1767        0x00159000UL
#define VX1000_JTAGID_PN_TC1797        0x0015A000UL
#define VX1000_JTAGID_PN_TC178x        0x0018E000UL
#define VX1000_JTAGID_PN_TC1387        0x0018F000UL
#define VX1000_JTAGID_PN_TC1798        0x001BE000UL
#define VX1000_JTAGID_PN_TC172x        0x001D0000UL
#define VX1000_JTAGID_PN_TC27xTC2Dx    0x001DA000UL /* TC27x and TC2Dx have the same base ID, bits 28..31==1/2/3/4/5 define Dx/7A/7B/7C/7D */
#define VX1000_JTAGID_PN_TC26x         0x001E8000UL
#define VX1000_JTAGID_PN_TC29x         0x001E9000UL
#define VX1000_JTAGID_PN_TC24x         0x001EA000UL
#define VX1000_JTAGID_PN_TC23x         0x00200000UL
#define VX1000_JTAGID_PN_TC22x         0x00201000UL
#define VX1000_JTAGID_PN_TC21x         0x00202000UL
#define VX1000_JTAGID_PN_TC39x         0x00205000UL /* same base ID also for Astep (which contains classic AURIX DAP and MCDS modules), bits 28..31==1/2/A define Astep/Bstep/Bstep */
#define VX1000_JTAGID_PN_TC38x         0x00206000UL /* NG */
#define VX1000_JTAGID_PN_TC37x         0x00207000UL /* NG */
#define VX1000_JTAGID_PN_TC37xED       0x00208000UL /* NG (alternative name: TC37xEXT) */
#define VX1000_JTAGID_PN_TC36x         0x00209000UL /* NG */
#define VX1000_JTAGID_PN_TC35x         0x0020A000UL /* NG */
#define VX1000_JTAGID_PN_TC33x         0x0020B000UL /* NG */
#define VX1000_JTAGID_PN_TC33xED       0x0020C000UL /* NG (alternative name: TC33xEXT) */
#define VX1000_JTAGID_PN_TC3Ax         0x0020D000UL /* NG (alternative name: TC35xEVO) */
#define VX1000_JTAGID_PN_TC3Ex         0x00215000UL /* NG */
#define VX1000_JTAGID_PN_TC32x         0xF0000FFFUL /* NG - DEVICE CANCELLED - its code made unreachable via impossible "ID" */
#define VX1000_JTAGID_PN_TC49xA        0x0021E000UL /* NG2 (Astep is different from regular TC4xx, therefore having its own ID) */
#define VX1000_JTAGID_PN_TC4Dx         0x00225000UL /* NG2 */
#define VX1000_JTAGID_PN_TC49xN        0x0022B000UL /* NG2 (This device is a mixture between TC49xA and TC4Dx) */
/* non-confirmed Astep-IDs (devices will not work as they use a new "Access Protection"-style for SFRs as well as extended OVL config):*/
#define VX1000_JTAGID_PN_TC42x         0x00219000UL /* NG2 */
#define VX1000_JTAGID_PN_TC44x         0x0021A000UL /* NG2 */
#define VX1000_JTAGID_PN_TC45x         0x0021B000UL /* NG2 */
#define VX1000_JTAGID_PN_TC46x         0x0021C000UL /* NG2 */
#define VX1000_JTAGID_PN_TC4Zx         0x00230000UL /* NG2 */
#define VX1000_JTAGID_PN_TC48x         0x0021D000UL /* NG2 */
#define VX1000_JTAGID_PN_TC4Ex         0x00231000UL /* NG2 */
#define VX1000_JTAGID_PN_TC4Px         0x0022F000UL /* NG2 */
#define VX1000_JTAGID_PN_TC4Sx         0x0todo000UL /* NG2 - future device, ID not published, yet */
#define VX1000_JTAGID_PN_TC43x         0xF0000FFEUL /* NG2 - DEVICE CANCELLED - its code made unreachable via impossible "ID" */
#define VX1000_JTAGID_PN_MASK          0x0FFFF000UL


#define VX1000_DERIVATIVE_ANY          0U /* dummy value, only used by the mini-cfg header */
#define VX1000_DERIVATIVE_TC1XXX       1U /* selects e.g. TC1387 and TC1798 */
#define VX1000_DERIVATIVE_TC2XX        2U /* selects e.g. TC212L and TC2D7T */
#define VX1000_DERIVATIVE_TC3XX        4U /* selects e.g. TC337D and TC3E7QF */
#define VX1000_DERIVATIVE_TC4XX        8U /* selects e.g. TC499X */

#if !defined(VX1000_DERIVATIVE_CLASS)
#define VX1000_DERIVATIVE_CLASS        gVX1000.tmp.DerivativeClass
#define VX1000_TRICORE_RUNTIMECHECK    /* enable the automatic derivative class identification */
#endif /* !VX1000_DERIVATIVE_CLASS */


/* JTAG Device Identification Register */
#define VX1000_MCREG_CBS_JTAGID        ((VX1000_ADDR_TO_PTR2VU32(0xF0000464UL))[0])
/* OCDS Interface Mode Control (ENDINIT protection ctl?) */
#define VX1000_MCREG_OCDS_OCNTRL_ADDR  (0xF000047CUL)
/* Aurix OCDS Interface Mode Control */
#define VX1000_MCREG_OCDS_OIFM_ADDR    (0xF000040CUL)
/* Tricore Overlay Control Registers */
#define VX1000_MCREG_OVC_OCON_ADDR     (0xF87FFBE0UL)
#define VX1000_MCREG_OVC_OCON          ((VX1000_ADDR_TO_PTR2VU32(VX1000_MCREG_OVC_OCON_ADDR))[0])
#define VX1000_MCREG_OVC_OENABLE_ADDR  (0xF87FFBE8UL)
/* Aurix Overlay Control Register */
#define VX1000_MCREG_SCU_OVCENBL_ADDR  (0xF00361E0UL)
#define VX1000_MCREG_SCU_OVCCON_ADDR   (0xF00361E4UL)
/* Aurix Overlay Range Select Register for each Core */
#define VX1000_MCREG_OVC0_OSEL_ADDR    (0xF880FB00UL)
#define VX1000_MCREG_OVC1_OSEL_ADDR    (0xF882FB00UL)
#define VX1000_MCREG_OVC2_OSEL_ADDR    (0xF884FB00UL)
#define VX1000_MCREG_OVC3_OSEL_ADDR    (0xF886FB00UL)
#define VX1000_MCREG_OVC4_OSEL_ADDR    (0xF888FB00UL)
#define VX1000_MCREG_OVC5_OSEL_ADDR    (0xF88CFB00UL)
#define VX1000_MCREG_OVC0_OSEL         ((VX1000_ADDR_TO_PTR2VU32(VX1000_MCREG_OVC0_OSEL_ADDR))[0])
/* Audo TRIGS Register */
#define VX1000_MCREG_OCDS_TRIGS_ADDR   (0xF00004A0UL)
/* Audo TRIGC Register */
#define VX1000_MCREG_OCDS_TRIGC_ADDR   (0xF00004A4UL)
/* Audo TRIG v1 Register */
#define VX1000_MCREG_OCDS_TRIG         ((VX1000_ADDR_TO_PTR2VU32(0xF00004A8UL))[0])
/* Aurix TRIG20 v2 Register -- note: does not exist for <= TC23x (only 0-5) or >= TC3x */
#define VX1000_MCREG_OCDS_TRIG20       ((VX1000_ADDR_TO_PTR2VU32(0xF0000550UL))[0])
/* Aurix TRIG5 v3 Register */
#define VX1000_MCREG_OCDS_TRIG5        ((VX1000_ADDR_TO_PTR2VU32(0xF0000514UL))[0])

#define VX1000_AURIX_TRIG_REG_OFS      480UL /* Bit 0 in OCDS_TRIG20; */
#define VX1000_AURIX_TRIG_REG_OFS_V3   80UL  /* Bit 0 in OCDS_TRIG5;  */

#endif /* VX1000_TARGET_TRICORE */


/*------------------------------------------------------------------------------ */
/* VX1000 default parameters                                                     */

#if !defined(VX1000_CO_OFFLOADER_COUNT)
#define VX1000_CO_OFFLOADER_COUNT    0U
#endif /* !VX1000_CO_OFFLOADER_COUNT */

#if !defined(VX1000_STORE_FIXDST)
#define VX1000_STORE_FIXDST(A, D32)    do { (VX1000_ADDR_TO_PTR2VU32((A)))[0] = (D32); } while (0)                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the testsuite to inject sniffer code */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to allow the testsuite to inject sniffer code */
#endif /* !VX1000_STORE_FIXDST */

#if !defined(VX1000_BARRIER_FORCE_WRITE)
#if defined(VX1000_ARM_DSB)
#define VX1000_BARRIER_FORCE_WRITE()   VX1000_ARM_DSB()                                                                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to inject processor-specific callback code when needed */
#else  /* !VX1000_ARM_DSB */
#define VX1000_BARRIER_FORCE_WRITE()   /* empty */                                                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to inject processor-specific callback code when needed */
#endif /* !VX1000_ARM_DSB */
#endif /* !VX1000_BARRIER_FORCE_WRITE */

#if !defined(VX1000_BARRIER_FORCE_ORDER)
#if defined(VX1000_ARM_DSB)
#define VX1000_BARRIER_FORCE_ORDER()   VX1000_ARM_DSB()                                                                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to inject processor-specific callback code when needed */
#else  /* !VX1000_ARM_DSB */
#define VX1000_BARRIER_FORCE_ORDER()   /* empty */                                                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to inject processor-specific callback code when needed */
#endif /* !VX1000_ARM_DSB */
#endif /* !VX1000_BARRIER_FORCE_ORDER */

#if !defined(VX1000_ENTER_SPINLOCK)
#define VX1000_ENTER_SPINLOCK()        /* empty */                                                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to inject processor-specific callback code when needed */
#endif /* !VX1000_ENTER_SPINLOCK */

#if !defined(VX1000_LEAVE_SPINLOCK)
#define VX1000_LEAVE_SPINLOCK()        /* empty */                                                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to inject processor-specific callback code when needed */
#endif /* !VX1000_LEAVE_SPINLOCK */

#if !defined(VX1000_ATOMIC_XOR8POW2)
#define VX1000_ATOMIC_XOR8POW2(A, I)   do { VX1000_ENTER_SPINLOCK() (VX1000_ADDR_TO_PTR2VU8(A))[0] ^= (1U << (I)); VX1000_LEAVE_SPINLOCK() } while (0)                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to overload callback with processor-optimised code */
#endif /* !VX1000_ATOMIC_XOR8POW2 */

#if defined(VX1000_TARGET_X850)
/* starting may 2024 we again use the interims method, but only on x850 targets */
#if !defined(VX1000_ATOMIC_XOR32X2)
#if defined( VX1000_ATOMIC_XOR32)
#define VX1000_ATOMIC_XOR32X2(A, D)    do { VX1000_ATOMIC_XOR32((A), (D)) VX1000_ATOMIC_XOR32(((A)+4UL), (D)) } while (0)                                                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to overload callback with processor-optimised code */
#else  /* !VX1000_ATOMIC_XOR32 */
#define VX1000_ATOMIC_XOR32X2(A, D)    do { VX1000_ENTER_SPINLOCK() (VX1000_ADDR_TO_PTR2VU32(A))[0] ^= (D); (VX1000_ADDR_TO_PTR2VU32(A))[1] ^= (D); VX1000_LEAVE_SPINLOCK() } while (0)  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to overload callback with processor-optimised code */
#endif /* !VX1000_ATOMIC_XOR32 */
#endif /* !VX1000_ATOMIC_XOR32X2 */
#define VX1000_FORCE_OLDATRIGGERTYPE_4 /* signal to the NIOS that it must check redundancy to avoid sending false data upon ECU brownout */
#else /* !VX1000_TARGET_X850 */
#if !defined(VX1000_ATOMIC_XOR32X2)    /* from january 2016 to january 2024 we used a redundant version with twice the data */
/* starting february 2024 we again use the classic method, but to avoid changing all usages of "VX1000_ATOMIC_XOR32X2" back */
/* to "VX1000_ATOMIC_XOR32" everywhere, we keep the new "VX1000_ATOMIC_XOR32X2" name but let it expand to the classic code: */
#if defined( VX1000_ATOMIC_XOR32)
#define VX1000_ATOMIC_XOR32X2(A, D)    VX1000_ATOMIC_XOR32((A), (D)) /* yes: single XOR (see comment above) */                                                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to inject processor-specific callback code when needed */
#else  /* !VX1000_ATOMIC_XOR32 */
#define VX1000_ATOMIC_XOR32X2(A, D)    do { VX1000_ENTER_SPINLOCK() (VX1000_ADDR_TO_PTR2VU32(A))[0] ^= (D); VX1000_LEAVE_SPINLOCK() } while (0) /* yes: single XOR (see comment above)*//* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to overload callback with processor-optimised code */
#endif /* !VX1000_ATOMIC_XOR32 */
#endif /* !VX1000_ATOMIC_XOR32X2 */
#endif /* !VX1000_TARGET_X850 */

#if !defined(VX1000_MAILBOX_SLOT_DWORDS)
#define VX1000_MAILBOX_SLOT_DWORDS     (1UL + 2UL) /* must be at least 3 (=4 bytes size info + 8 bytes payload (=XCP command)) */
#endif /* !VX1000_MAILBOX_SLOT_DWORDS */
#if !defined(VX1000_MAILBOX_SLOTS)
#define VX1000_MAILBOX_SLOTS           8U
#endif /* !VX1000_MAILBOX_SLOTS */

#if !defined(VX1000_OLDA_HIPRIOMASK)
#define VX1000_OLDA_HIPRIOMASK         0UL
#endif /* !VX1000_OLDA_HIPRIOMASK */

#if !defined(VX1000_IS_BYPASS_RESUME_ALLOWED)
#define VX1000_IS_BYPASS_RESUME_ALLOWED() 0U  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to provide either runtime-decision or compiletime-decision callback code */
#endif /* VX1000_IS_BYPASS_RESUME_ALLOWED */

#if !defined(VX1000_OVERLAY_PHYSADDR)
#define VX1000_OVERLAY_PHYSADDR        (VX1000_OVERLAY_ADDR)
#endif /* !VX1000_OVERLAY_PHYSADDR */

#if !defined(VX1000_CALRAM_PHYSADDR)
#define VX1000_CALRAM_PHYSADDR         (VX1000_CALRAM_ADDR)
#endif /* !VX1000_CALRAM_PHYSADDR */

#if !defined(VX1000_ERRLOG_SIZE)
#define VX1000_ERRLOG_SIZE             0U
#endif /* !VX1000_ERRLOG_SIZE */

#if !defined(VX1000_MEMSYNC_TRIGGER_COUNT)
#define VX1000_MEMSYNC_TRIGGER_COUNT   0U  /* this is the correct place for default settings. As a workaround for AddOns file split dependencies this had to pre-done at the beginning of the file in some configurations */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */

#if !defined(VX1000_MEMSYNC_COPY_COUNT)
#define VX1000_MEMSYNC_COPY_COUNT      0U
#endif /* !VX1000_MEMSYNC_COPY_COUNT */

#if !defined(VX1000_CURRENT_CORE_IDX)
#define VX1000_CURRENT_CORE_IDX()      ((gVX1000.MagicId != 0UL)? 0U:0U)  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to allow the user to inject processor-specific callback code when needed */
#define VX1000_CURRENT_CORE_IDX_NOT_DEF
#endif /* !VX1000_CURRENT_CORE_IDX */

#if defined(VX1000_STORE64)
/* If user provided an optimised callback, use that one. Otherwise fall back to one of the generic built-in solutions. */
#elif defined(VX1000_UINT64_T)
#define VX1000_STORE64(S, A, D )       do { ((VX1000_ADDR_TO_PTR2VU64((S))))[0] = ((((VX1000_UINT64_T)(VX1000_UINT32)(A)) * (VX1000_UINT64_T)8UL) << 29U) | ((VX1000_UINT64_T)(VX1000_UINT32)(D)); } while (0) /* PRQA S 0303 */ /* PRQA S 3453 */ /* PRQA S 3412 */ /* This is just a C-style algorithm specification to be overruled by a user-defined implementation. It allows sales to demonstrate project compilation without the need to provide an actual assembly language callback */
#endif /* !VX1000_STORE64 & VX1000_UINT64_T */

#if !defined(VX1000_LFAST_PLLMULOFS)
#define VX1000_LFAST_PLLMULOFS         1UL /* There are rumours that few derivatives use 0 instead of 1. The user can overload the default in those cases */
#endif /* !VX1000_LFAST_PLLMULOFS */

#if defined(VX1000_TARGET_TRICORE)

#if (!defined(VX1000_SW_RSTOUT_AVAILABLE)) && (!defined(VX1000_KEEP_VXSTRUCT_OVER_RESET)) /* VX1000_KEEP_VXSTRUCT_OVER_RESET is a "secret user configuration" because it never shall be used by the average user */
#define VX1000_SW_RSTOUT_AVAILABLE     1U /* select standard behaviour: after each ECU reset (no matter what kind it was) perform a new tool handshake, re-download overlay and re-start measurement */
#endif /* !VX1000_SW_RSTOUT_AVAILABLE && !VX1000_KEEP_VXSTRUCT_OVER_RESET */

#endif /* VX1000_TARGET_TRICORE */

#if defined(VX1000_CLOCK_TICKS_PER_BASE)

#if (!defined(VX1000_CLOCK_TICKS_BASE_NS)) && (!defined(VX1000_DISABLE_INSTRUMENTATION))
#error Please define VX1000_CLOCK_TICKS_BASE_NS as the time bas in ns during which VX1000_CLOCK_TICKS_PER_BASE ticks occur
#endif /* !VX1000_CLOCK_TICKS_BASE_NS && !VX1000_DISABLE_INSTRUMENTATION */

#else /* !VX1000_CLOCK_TICKS_PER_BASE */

#if defined(VX1000_CLOCK_TICKS_PER_S)
#define VX1000_CLOCK_TICKS_PER_BASE    ((VX1000_UINT32)(VX1000_CLOCK_TICKS_PER_S))
#define VX1000_CLOCK_TICKS_BASE_NS     1000000000UL
#elif defined(VX1000_CLOCK_TICKS_PER_MS)
#define VX1000_CLOCK_TICKS_PER_BASE    ((VX1000_UINT32)(VX1000_CLOCK_TICKS_PER_MS))
#define VX1000_CLOCK_TICKS_BASE_NS     1000000UL
#elif defined(VX1000_CLOCK_TICKS_PER_US)
#define VX1000_CLOCK_TICKS_PER_BASE    ((VX1000_UINT32)(VX1000_CLOCK_TICKS_PER_US))
#define VX1000_CLOCK_TICKS_BASE_NS     1000UL
#elif !defined(VX1000_DISABLE_INSTRUMENTATION)
#error Please define VX1000_CLOCK_TICKS_PER_US or VX1000_CLOCK_TICKS_PER_MS or VX1000_CLOCK_TICKS_PER_S
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

#endif /* !VX1000_CLOCK_TICKS_PER_BASE */

#if !defined(VX1000_CLOCK_TICKS_PER_S)
#define VX1000_CLOCK_TICKS_PER_S       ((VX1000_UINT32)((1000000000UL * ((VX1000_UINT32)(VX1000_CLOCK_TICKS_PER_BASE))) / ((VX1000_UINT32)(VX1000_CLOCK_TICKS_BASE_NS))))
#endif /* !VX1000_CLOCK_TICKS_PER_S */

#if !defined(VX1000_CLOCK_TICKS_PER_MS)
#define VX1000_CLOCK_TICKS_PER_MS      ((VX1000_UINT32)((1000000UL * ((VX1000_UINT32)(VX1000_CLOCK_TICKS_PER_BASE))) / ((VX1000_UINT32)(VX1000_CLOCK_TICKS_BASE_NS))))
#endif /* !VX1000_CLOCK_TICKS_PER_MS */

#if !defined(VX1000_CLOCK_TICKS_PER_US)
#define VX1000_CLOCK_TICKS_PER_US      100;//((VX1000_UINT32)((1000UL * ((VX1000_UINT32)(VX1000_CLOCK_TICKS_PER_BASE))) / ((VX1000_UINT32)(VX1000_CLOCK_TICKS_BASE_NS))))
#endif /* !VX1000_CLOCK_TICKS_PER_US */

#if !defined(VX1000_CLOCK_TIMER_SIZE)
#define VX1000_CLOCK_TIMER_SIZE        32U /* legacy mode of VX1000_CLOCK() */
#endif /* !VX1000_CLOCK_TIMER_SIZE */

#if !defined(VX1000_CLOCK_TIMER_ADDRREGION)
#define VX1000_CLOCK_TIMER_ADDRREGION  0U /* timer is a memory-mapped peripheral (no SPR) */
#endif /* !VX1000_CLOCK_TIMER_ADDRREGION */

#if !defined(VX1000_CLOCK_TIMER_REVERSE)
#define VX1000_CLOCK_TIMER_REVERSE     0U /* timer periphery uses same endianess as the CPU */
#endif /* !VX1000_CLOCK_TIMER_REVERSE */

#if !defined(VX1000_CLOCK_TIMER_ADDR)
#define VX1000_CLOCK_TIMER_ADDR        0UL /* turns the synchronisation feature off */
#endif /* !VX1000_CLOCK_TIMER_ADDR */

/* Default timeouts for VX detection in us and cold start initialization in ms */
#if !defined(VX1000_DETECTION_TIMEOUT_US)
#define VX1000_DETECTION_TIMEOUT_US    50UL
#endif /* !VX1000_DETECTION_TIMEOUT_US */
#if !defined(VX1000_COLDSTART_TIMEOUT_MS)
#if defined(VX1000_TARGET_XC2000)
#define VX1000_COLDSTART_TIMEOUT_MS    100UL
#else  /* !VX1000_TARGET_XC2000 */
#define VX1000_COLDSTART_TIMEOUT_MS    20UL
#endif /* !VX1000_TARGET_XC2000 */
#endif /* !VX1000_COLDSTART_TIMEOUT_MS */

#if !defined(VX1000_OLDA_ACTIVE_EVT_CNT_MAX)
#if defined(VX1000_OLDA_AUDMBR_REG_ADDR)
#define VX1000_OLDA_ACTIVE_EVT_CNT_MAX 15U
#else /* !VX1000_OLDA_AUDMBR_REG_ADDR */
#define VX1000_OLDA_ACTIVE_EVT_CNT_MAX 31U
#endif /* !VX1000_OLDA_AUDMBR_REG_ADDR */
#endif /* !VX1000_OLDA_ACTIVE_EVT_CNT_MAX */

#if !defined(VX1000_OLDA_BENCHMARK_CNT)
/* This feature eats a lot of RAM  for 512 events. The user can configure it that big, but by default, ignore VX1000_OLDA_ACTIVE_EVT_CNT_MAX and provide the much smaller classic value: */
#define VX1000_OLDA_BENCHMARK_CNT      31U
#endif /* !VX1000_OLDA_BENCHMARK_CNT */


/*------------------------------------------------------------------------------ */
/* Defines                                                                       */


#define VX1000_OLDATRIG_VXSF            0x00000400UL           /* if set then process but if clear then skip VXSF commands unless one of the VX1000_OLDAPROC_xxx bits is set */
#define VX1000_OLDAPROC_SPECEV          0x00000200UL           /* if set then process but if clear then skip special-event-specific OLDA commands */
#if defined(VX1000_ENABLE_RADAR_API)
#define VX1000_OLDAPROC_RADAR           0x00000100UL           /* if set then process but if clear then skip radar-API-specific OLDA commands */
#define VX1000_OLDAPROC_ERROR           0x00000800UL           /* if set then process but if clear then skip radar-API-specific ERROR notifications */
#else  /* !VX1000_ENABLE_RADAR_API */
#define VX1000_OLDAPROC_RADAR           0x00000000UL           /* to produce "always-false" conditions for better compiler optimisations */
#define VX1000_OLDAPROC_ERROR           0x00000000UL           /* to produce "always-false" conditions for better compiler optimisations */
#endif /* !VX1000_ENABLE_RADAR_API */
#define VX1000_OLDAPROC_MUBU_SPEC       0x00000080UL           /* perform multibuffer-specific OLDA handling (advance pointer instead of event triggering) */
#if !defined(VX1000_SUPPRESS_IPO_API)
#define VX1000_OLDAPROC_BAR             0x00000040UL           /* if set then process but if clear then skip VX1000_EVENT_PROCESSING_BARRIER()-specific OLDA commands */
#else  /* VX1000_SUPPRESS_IPO_API */
#define VX1000_OLDAPROC_BAR             0x00000000UL           /* to produce "always-false" conditions for better compiler optimisations */
#endif /* VX1000_SUPPRESS_IPO_API */
#if defined(VX1000_STIM_BY_OLDA)
#define VX1000_OLDAPROC_STIM            0x00000020UL           /* if set then process but if clear then skip VX1000_STIM_WAIT()-specific OLDA commands */
#else  /* !VX1000_STIM_BY_OLDA */
#define VX1000_OLDAPROC_STIM            0x00000000UL           /* to produce "always-false" conditions for better compiler optimisations */
#endif /* !VX1000_STIM_BY_OLDA */
#define VX1000_OLDAPROC_DAQ             0x00000010UL           /* if set then process but if clear then skip VX1000_EVENT()/VX1000_STIM_REQUEST()-specific OLDA commands */
#if defined(VX1000_SUPPRESS_TRACE_SUPPORT)
#define VX1000_OLDATRIG_MEMSY           0x00000000UL           /* zero, because in no-trace scenario events are never triggered via memsync trace */
#define VX1000_OLDATRIG_TRACE           0x00000000UL           /* zero, because in no-trace scenario events are never triggered in the classic trace way */
#elif ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_OLDATRIG_MEMSY           0x02000000UL           /* !DO NOT TOUCH as it must match the encoding of the radarGen6 FW! */ /* request event triggering via memsy trace */
#define VX1000_OLDATRIG_TRACE           0x00000000UL           /* zero, because in memsync scenario events are never triggered in the classic trace way */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT && !VX1000_SUPPRESS_TRACE_SUPPORT */
#define VX1000_OLDATRIG_MEMSY           0x00000000UL           /* zero, because in classic trace scenario events are never triggered via memsync */
#define VX1000_OLDATRIG_TRACE           0x02000000UL           /* !DO NOT TOUCH as it must match the encoding of the radarGen6 FW! */ /* request event triggering via classic trace */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT && !VX1000_SUPPRESS_TRACE_SUPPORT */
#if defined(VX1000_OLDA)
#define VX1000_OLDATRIG_NIOS            0x01000000UL           /* !DO NOT TOUCH as it must match the encoding of the radarGen6 FW! */ /* request event triggering in one of the ways the Coprocessor can detect it */
#else  /* !VX1000_OLDA */
#define VX1000_OLDATRIG_NIOS            0x00000000UL           /* zero, because in no-OLDA scenario events are never triggered via NIOS */
#endif /* !VX1000_OLDA */
#define VX1000_OLDATRIG_RESRVD          0x0000000EUL           /* the pre-compiled code still uses the original bit positiond for the features that have been moved to bits 24,25,26 - don't re-use! */
#define VX1000_OLDASAVE_TIME            0x00000001UL           /* request to save/transmit the event's timestamp via one of the hardcoded methods (gVX1000, memsy, etcpp) */


#if !defined(VX1000_DYNADDRSIG_ENABLED)
#define VX1000_NEWA_MUBU_ONLY_DAS(COMMANDS, DST_ADR) /* empty */                                                                                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else /* VX1000_DYNADDRSIG_ENABLED */
#define VX1000_NEWA_MUBU_ONLY_DAS(COMMANDS, DST_ADR)                                                                          \
              if ((word1 & 0x000000FFUL) == 0x00000007UL) /* VX1000_DasTransmitLargeChunk */                                  \
              {                                                                                                               \
                NewaDst32 = VX1000_ADDR_TO_PTR2VU32((DST_ADR));                                                               \
                for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                    \
                { /* in MuBu context, always sub-command 0x00UL is requested by the FW, so no check needed here */            \
                  word2 = (COMMANDS)[step+1U]; /* actually this is "word3" */                                                 \
                  srcAddr32 = (COMMANDS)[step] + VX1000_ADDR_TO_PTR2VU32(gVX1000.DynamicLutAddr)[0xFFFFUL & (word2 >> 16)];   \
                  chunkSize = word2 & 0xFFFFUL;                                                                               \
                  NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                             \
                  for (J = 0UL; J < chunkSize; ++J) { NewaDst32[J] = NewaSrc32[J]; }                                          \
                  (DST_ADR) += chunkSize << 2;                                                                                \
                  step += 2UL;                                                                                                \
                }                                                                                                             \
              }                                                                                                               \
              else  /* PRQA S 3412 */ /* Cannot avoid violating MISRA rule 19.4 because the code fragment indeed is just a fragment that cannot exist self-contained in parentheses. Adapting the code would make it un-compilable */
#endif /* VX1000_DYNADDRSIG_ENABLED */
#define VX1000_NEWA_MUBU_PROCESSOR(COMMANDS, DST_ADR) do                                                                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
          {                                                                                                                    \
            volatile VX1000_UINT32 VX1000_DECL_PTR *NewaSrc32;                                                                 \
            volatile VX1000_UINT32 VX1000_DECL_PTR *NewaDst32;                                                                 \
            VX1000_UINT32 word1, word2, loops, chunkSize, J, step = 0UL, srcAddr32;                                            \
            word1 = (COMMANDS)[step];                                                                                          \
            do /* FW always places a MultiCopy32/DasTransmitLargeChunk first so LastCommand is only checked _after_ the loop */\
            {                                                                                                                  \
              ++step;                                                                                                          \
              VX1000_NEWA_MUBU_ONLY_DAS((COMMANDS), (DST_ADR))                                                                 \
              if ((word1 & 0x000000FFUL) == 0x00000001UL)/* VX1000_MultiCopy32LargeChunks is unlikely but possible in the FW */\
              {                                                                                                                \
                srcAddr32 = word1;                                                                                             \
                for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                     \
                {                                                                                                              \
                  word2 = (COMMANDS)[step];                                                                                    \
                  chunkSize = word2 & 0x3FFFFUL;                                                                               \
                  srcAddr32 = (srcAddr32 & 0xFFFF0000UL) | (0xFFFCUL & (word2 >> 16));                                         \
                  NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                              \
                  NewaDst32 = VX1000_ADDR_TO_PTR2VU32((DST_ADR));                                                              \
                  for (J = 0UL; J < chunkSize; ++J) { NewaDst32[J] = NewaSrc32[J]; }                                           \
                  (DST_ADR) += chunkSize << 2;                                                                                 \
                  ++step;                                                                                                      \
                }                                                                                                              \
              }                                                                                                                \
              else                                                                                                             \
              {                                                                                                                \
                /* must be VX1000_MultiCopy32 (0x00000002UL) because the FW would not generate any other command */            \
                srcAddr32 = word1;                                                                                             \
                for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                     \
                {                                                                                                              \
                  word2 = (COMMANDS)[step];                                                                                    \
                  chunkSize = word2 & 0x3FFUL;                                                                                 \
                  srcAddr32 = (srcAddr32 & 0xFF000000UL) | (0xFFFFFCUL & (word2 >> 8));                                        \
                  NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                              \
                  NewaDst32 = VX1000_ADDR_TO_PTR2VU32((DST_ADR));                                                              \
                  for (J = 0UL; J < chunkSize; ++J) { NewaDst32[J] = NewaSrc32[J]; }                                           \
                  (DST_ADR) += chunkSize << 2;                                                                                 \
                  ++step;                                                                                                      \
                }                                                                                                              \
              }                                                                                                                \
              word1 = (COMMANDS)[step];                                                                                        \
            } while ((word1 & 0x000000FFUL) != 0UL); /* !VX1000_LastCommand */                                                 \
          } while (0) /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */ /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */


#define VX1000_NEWA_PROCESSOR(ACTIONS_V, ACTIONS_C, COMMANDS, DST_ADR, EVENT, TIME, VX_ADR, SYN_ADR) do /* PRQA S 3453 *//* Processor used repeatedly, macro faster than function */\
  {                                                                                                                                                            \
    volatile VX1000_UINT8 VX1000_DECL_PTR *NewaSrc8;                                                                                                           \
    volatile VX1000_UINT8 VX1000_DECL_PTR *NewaDst8;                                                                                                           \
    volatile VX1000_UINT32 VX1000_DECL_PTR *NewaSrc32;                                                                                                         \
    volatile VX1000_UINT32 VX1000_DECL_PTR *NewaDst32;                                                                                                         \
    const VX1000_UINT32 VX1000_DECL_PTR *Commands = (COMMANDS);                                                                                                \
    VX1000_UINT32 word1, word2, loops, chunkSize, J, step = 0UL, srcAddr32;                                                                                    \
    VX1000_UINT32 VX1000_ASYNC_OLDA_DECL_AUX_VAR MetadataOffset = 0UL;                                                                                         \
    do                                                                                                                                                         \
    {                                                                                                                                                          \
      word1 = Commands[step];                                                                                                                                  \
      switch ((VX1000_UINT8)(word1 & 0x000000FFUL))                                                                                                            \
      {                                                                                                                                                        \
        VX1000_LastCommand((DST_ADR), (ACTIONS_V))                                                                                                             \
        VX1000_MultiCopy32LargeChunks((DST_ADR), (ACTIONS_C))                                                                                                  \
        VX1000_MultiCopy32((DST_ADR), (ACTIONS_C))                                                                                                             \
        VX1000_MultiCopy8((DST_ADR), (ACTIONS_C))                                                                                                              \
        VX1000_MultiMemSyncWriteLargeCh((SYN_ADR), (DST_ADR), (ACTIONS_C))                                                                                     \
        VX1000_MultiFixDst32LargeChunks((DST_ADR), (ACTIONS_C))                                                                                                \
        VX1000_PatchVXSFMetadata((ACTIONS_C), (EVENT), (TIME))                                                                                                 \
        VX1000_DasTransmitLargeChunk((SYN_ADR), (DST_ADR), (ACTIONS_C))                                                                                        \
        VX1000_AsyncOldaEnqueueCopyJobs((ACTIONS_C), (EVENT))                                                                                                  \
        VX1000_RelJump((DST_ADR))                                                                                                                              \
        VX1000_SelectMemsyncTrigger((SYN_ADR))                                                                                                                 \
        VX1000_AbsJump((DST_ADR), (VX_ADR))                                                                                                                    \
        VX1000_LastStim((DST_ADR), (ACTIONS_V))                                                                                                                \
        VX1000_MultiStim8LargeChunks((DST_ADR), (ACTIONS_C))                                                                                                   \
        VX1000_DasStim8LargeChunk((DST_ADR), (ACTIONS_C))                                                                                                      \
        default:                                                                                                                                               \
          VX1000_ERRLOGGER(VX1000_ERRLOG_OLDA_UNIMPLCMD)                                                                                                       \
          ++MetadataOffset; /* dummy usage for configurations where no other consuming cases are active (as we abort anyway, we can destroy it) */             \
          step = 0xFFFFUL;  /* we abort parsing the remaining commands because we do not know the word count of this unknown command */                        \
          break;                                                                                                                                               \
      }                                                                                                                                                        \
    } while (step < 0xFFFFUL);                                                                                                                                 \
  } while (0) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */


#define VX1000_LastCommand(DST_ADR, ACTIONS) /* PRQA S 3453 */                                                                                                 \
      case 0x00U: /* VX1000_LastCommand */                                                                                                                     \
        (ACTIONS) &=~ (word1 & ((VX1000_OLDATRIG_NIOS) | ((VX1000_OLDATRIG_TRACE) | (VX1000_OLDATRIG_MEMSY))));                                                \
        step = 0xFFFFUL;                                                                                                                                       \
        break; /* PRQA S 3453 */ /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 and MISRA rule 19.7 because a switch-case cannot be turned into a subfunction */


#define VX1000_MultiCopy32LargeChunks(DST_ADR, ACTIONS)                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0x01U: /* VX1000_MultiCopy32LargeChunks */                                                                                                          \
        ++step;                                                                                                                                                \
        srcAddr32 = word1;                                                                                                                                     \
        for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                             \
        {                                                                                                                                                      \
          word2 = Commands[step];                                                                                                                              \
          chunkSize = word2 & 0x3FFFFUL;                                                                                                                       \
          srcAddr32 = (srcAddr32 & 0xFFFF0000UL) | (0xFFFCUL & (word2 >> 16));                                                                                 \
          NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                                                                      \
          NewaDst32 = VX1000_ADDR_TO_PTR2VU32((DST_ADR));                                                                                                      \
          /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & (VX1000_OLDAPROC_DAQ | VX1000_OLDAPROC_RADAR | VX1000_OLDAPROC_ERROR)) != 0U)\
          {                                                                                                                                                    \
            for (J = 0UL; J < chunkSize; ++J) { NewaDst32[J] = NewaSrc32[J]; }                                                                                 \
            (DST_ADR) += (chunkSize << 2);                                                                                                                     \
          }                                                                                                                                                    \
          ++step;                                                                                                                                              \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */ /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */


#define VX1000_MultiCopy32(DST_ADR, ACTIONS)                                                                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0x02U: /* VX1000_MultiCopy32 */                                                                                                                     \
        ++step;                                                                                                                                                \
        srcAddr32 = word1;                                                                                                                                     \
        /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & (VX1000_OLDAPROC_DAQ | VX1000_OLDAPROC_RADAR | VX1000_OLDAPROC_ERROR)) != 0U)\
        {                                                                                                                                                      \
          for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                           \
          {                                                                                                                                                    \
            word2 = Commands[step];                                                                                                                            \
            chunkSize = word2 & 0x3FFUL;                                                                                                                       \
            srcAddr32 = (srcAddr32 & 0xFF000000UL) | (0xFFFFFCUL & (word2 >> 8));                                                                              \
            NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                                                                    \
            NewaDst32 = VX1000_ADDR_TO_PTR2VU32((DST_ADR));                                                                                                    \
            for (J = 0UL; J < chunkSize; ++J) { NewaDst32[J] = NewaSrc32[J]; }                                                                                 \
            (DST_ADR) += chunkSize << 2;                                                                                                                       \
            ++step;                                                                                                                                            \
          }                                                                                                                                                    \
        }                                                                                                                                                      \
        else                                                                                                                                                   \
        {                                                                                                                                                      \
          step += 0xFFUL & (word1 >> 8);                                                                                                                       \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */


#define VX1000_MultiCopy8(DST_ADR, ACTIONS)                                                                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0x03U: /* VX1000_MultiCopy8 */                                                                                                                      \
        ++step;                                                                                                                                                \
        srcAddr32 = word1;                                                                                                                                     \
        /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & (VX1000_OLDAPROC_DAQ | VX1000_OLDAPROC_RADAR | VX1000_OLDAPROC_ERROR)) != 0U)\
        {                                                                                                                                                      \
          NewaDst8 = VX1000_ADDR_TO_PTR2VU8((DST_ADR));                                                                                                        \
          for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                           \
          {                                                                                                                                                    \
            word2 = Commands[step];                                                                                                                            \
            chunkSize = word2 & 0xFFUL;                                                                                                                        \
            srcAddr32 = (srcAddr32 & 0xFF000000UL) | (0xFFFFFFUL & (word2 >> 8));                                                                              \
            NewaSrc8 = VX1000_ADDR_TO_PTR2VU8(srcAddr32);                                                                                                      \
            for (J = 0UL; J < chunkSize; ++J) { NewaDst8[0] = NewaSrc8[J]; NewaDst8 = &NewaDst8[1]; }                                                          \
            ++step;                                                                                                                                            \
          }                                                                                                                                                    \
          (DST_ADR) = VX1000_PTR2VU8_TO_ADDRESS(NewaDst8);                                                                                                     \
        }                                                                                                                                                      \
        else                                                                                                                                                   \
        {                                                                                                                                                      \
          step += 0xFFUL & (word1 >> 8);                                                                                                                       \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */


#if defined(VX1000_SUPPRESS_TRACE_SUPPORT) || ((!defined(VX1000_MEMSYNC_TRIGGER_COUNT)) || (0U == VX1000_MEMSYNC_TRIGGER_COUNT))
#define VX1000_MultiMemSyncWriteLargeCh(SYN_ADR, DST_ADR, ACTIONS) /* empty */                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else /* !VX1000_SUPPRESS_TRACE_SUPPORT && VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_MultiMemSyncWriteLargeCh(SYN_ADR, DST_ADR, ACTIONS)                                                                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0x04U: /* VX1000_MultiMemSyncWriteLargeCh (opposed to MultiMemSyncReadLargeChunks we use a DST_ADR inside the J loop instead of srcAddr32) */       \
        ++step;                                                                                                                                                \
        srcAddr32 = word1;                                                                                                                                     \
        for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                             \
        {                                                                                                                                                      \
          word2 = Commands[step];                                                                                                                              \
          chunkSize = word2 & 0x3FFFFUL;                                                                                                                       \
          srcAddr32 = (srcAddr32 & 0xFFFF0000UL) | (0xFFFCUL & (word2 >> 16));                                                                                 \
          NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                                                                      \
          /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & (VX1000_OLDAPROC_DAQ | VX1000_OLDAPROC_RADAR | VX1000_OLDAPROC_ERROR)) != 0U) { for (J = 0UL; J < chunkSize; ++J)\
          {                                                                                                                                                    \
            VX1000_STORE64((SYN_ADR), (DST_ADR), NewaSrc32[J]); VX1000_BARRIER_FORCE_WRITE()                                                                   \
            (DST_ADR) += 4UL;                                                                                                                                  \
          }}                                                                                                                                                   \
          ++step;                                                                                                                                              \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT */


#define VX1000_MultiFixDst32LargeChunks(DST_ADR, ACTIONS)                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0x05U: /* VX1000_MultiFixDst32LargeChunks */                                                                                                        \
        ++step;                                                                                                                                                \
        srcAddr32 = word1;                                                                                                                                     \
        /* The FW takes care that this command is never used together with other commands that use or abuse the destination value */                           \
        for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                             \
        {                                                                                                                                                      \
          word2 = Commands[step];                                                                                                                              \
          chunkSize = word2 & 0x3FFFFUL;                                                                                                                       \
          srcAddr32 = (srcAddr32 & 0xFFFF0000UL) | (0xFFFCUL & (word2 >> 16));                                                                                 \
          NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                                                                      \
          /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & (VX1000_OLDAPROC_DAQ | VX1000_OLDAPROC_RADAR | VX1000_OLDAPROC_ERROR)) != 0U){for (J = 0UL; J < chunkSize; ++J){VX1000_STORE_FIXDST((DST_ADR),NewaSrc32[J]);}}\
          ++step;                                                                                                                                              \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */


#if !defined(VX1000_OLDA_OVERLOAD_DETECTION)
#define VX1000_PatchVXSFMetadataEvenVal(EVENT) 0UL /* dummy counter: even value. Internally used by VX1000_PatchVXSFMetadata */                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else  /* VX1000_OLDA_OVERLOAD_DETECTION */
#define VX1000_PatchVXSFMetadataEvenVal(EVENT) ((VX1000_ADDR_TO_PTR2OE(gVX1000.Olda.EventList))[(EVENT)].EventCounter &~ 1UL)                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#endif /* VX1000_OLDA_OVERLOAD_DETECTION */
#if !defined(VX1000_DYNADDRSIG_ENABLED)
#define VX1000_PatchVXSFMetadataDas() /* empty */                                                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else /* VX1000_DYNADDRSIG_ENABLED */
#define VX1000_PatchVXSFMetadataDas() /* internally used by VX1000_PatchVXSFMetadata */                                                                        \
          else                                                                                                                                                 \
          {                                                                                                                                                    \
            VX1000_UINT32 das_idx = (word2 & 0xFFFFUL);                                                                                                        \
            VX1000_UINT32 chunk_idx = VX1000_ADDR_TO_PTR2VU32(gVX1000.DynamicLutAddr)[das_idx];                                                                \
            chunk_idx /= VX1000_ADDR_TO_PTR2VU32(gVX1000.StaticLutAddr)[(4UL * das_idx) + /*.size:*/1UL];                                                      \
            MetadataOffset = chunk_idx * (0xFFUL & (word1 >> 8)); /* remember for AsyncOldaEnqueueCopyJobs */                                                  \
          } /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_DYNADDRSIG_ENABLED */
#define VX1000_PatchVXSFMetadata(ACTIONS, EVENT, TIME)                                                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0x06U: /* VX1000_PatchVXSFMetadata */                                                                                                               \
        word2 = Commands[step+1U];                                                                                                                             \
        srcAddr32 = VX1000_PTR2CU32_TO_ADDRESS(&Commands[step+2U]);                                                                                            \
        if ((word2 & 0x10000UL) != 0UL)                                                                                                                        \
        {                                                                                                                                                      \
          /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_SPECEV) != 0U)          \
          {                                                                                                                                                    \
            VX1000_ENTER_SPINLOCK()                                                                                                                            \
            gVX1000.tmp.SpecEventCount = (gVX1000.tmp.SpecEventCount < (0xFFUL & (word1 >> 16)))? (1UL + gVX1000.tmp.SpecEventCount) : 0UL;                    \
            MetadataOffset = gVX1000.tmp.SpecEventCount * (0xFFUL & (word1 >> 8)); /* remember for AsyncOldaEnqueueCopyJobs */                                 \
            /* consume the new value of the counter already inside the mutex before another process/core can increment it again (FPGA would get confused): */  \
            VX1000_ADDR_TO_PTR2VU32(srcAddr32 + MetadataOffset)[1] = gVX1000.tmp.SpecEventCount << 1;                                                          \
            VX1000_LEAVE_SPINLOCK()                                                                                                                            \
          }                                                                                                                                                    \
          /* Note: no need to check here for VX1000_OLDAPROC_RADAR nor to consider gVX1000.tmp.RadarEventCount, */                                             \
          /* because radar is always real time, using no or only a single VXSF metadata instance!               */                                             \
          VX1000_PatchVXSFMetadataDas() /* optional else case for DAS */                                                                                       \
          srcAddr32 += MetadataOffset;                                                                                                                         \
        }                                                                                                                                                      \
        NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                                                                        \
        /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & (VX1000_OLDAPROC_DAQ | /*"empty DAQ on dummy channel:"*/VX1000_OLDATRIG_VXSF)) != 0U)\
        {                                                                                                                                                      \
          /* the stream decoder expects 64bit timestamps but app only knows 32bit timestamps. Feed all available timer bits and the event counter: */          \
          NewaSrc32[1] = VX1000_PatchVXSFMetadataEvenVal((EVENT));                                                                                             \
          NewaSrc32[2] = (TIME);                                                                                                                               \
          NewaSrc32[3] = 0UL;                                                                                                                                  \
        }                                                                                                                                                      \
        else /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_BAR) != 0U)          \
        {                                                                                                                                                      \
          /* flag payload as inconsistent via LSB of the transfer counter */                                                                                   \
          NewaSrc32[1] |= 1UL;                                                                                                                                 \
        }                                                                                                                                                      \
        else /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_ERROR) != 0U)        \
        {                                                                                                                                                      \
          NewaSrc32[1] = 0UL;                                                                                                                                  \
          NewaSrc32[2] = 0UL;                                                                                                                                  \
          NewaSrc32[3] = gVX1000.tmp.RadarStreamHasErrors;                                                                                                     \
          NewaSrc32[4] = 0UL;                                                                                                                                  \
        }                                                                                                                                                      \
        else /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_RADAR) != 0U)        \
        {                                                                                                                                                      \
          NewaSrc32[1] = gVX1000.tmp.RadarEventCount;                                                                                                          \
          NewaSrc32[2] = gVX1000.tmp.RadarEventStartTimeL;                                                                                                     \
          NewaSrc32[3] = gVX1000.tmp.RadarEventStartTimeH;                                                                                                     \
          NewaSrc32[4] = (TIME); /* note: in radar use case, this parameter actually holds the radar payload length (real timestamp comes from gVX1000 tmp space)*/\
        }                                                                                                                                                      \
        else /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_SPECEV) != 0U)       \
        {                                                                                                                                                      \
          /* NewaSrc32[1] already handled inside mutex, pseudo event number 0x001F already stored by FW to metadata, unused (special events */                 \
          /* are swallowed by VX) XCP timestamp extension is abused to buffer the expected 4-byte "payload" in a FW-allocated memory    */                     \
          NewaSrc32[2] = (TIME);                                                                                                                               \
          NewaSrc32[3] = (EVENT);                                                                                                                              \
          VX1000_ASYNC_OLDA_REMEMBA(srcAddr32 + (3UL << 2)) /* remember for AsyncOldaEnqueueCopyJobs */                                                        \
        }                                                                                                                                                      \
        else                                                                                                                                                   \
        {                                                                                                                                                      \
          ; /* empty "else" only here for MISRA */                                                                                                             \
        }                                                                                                                                                      \
        step += 2UL + (((0xFFUL & (word1 >> 8)) >> 2) * (0xFFUL & (word1 >> 16))); /* skip the in-place data structures */                                     \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */


#if !defined(VX1000_DYNADDRSIG_ENABLED)
#define VX1000_DasTransmitLargeChunk(SYN_ADR, DST_ADR, ACTIONS) /* empty */                                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else /* VX1000_DYNADDRSIG_ENABLED */
#if defined(VX1000_SUPPRESS_TRACE_SUPPORT) || (!defined(VX1000_MEMSYNC_TRIGGER_COUNT)) || (0U == VX1000_MEMSYNC_TRIGGER_COUNT)
#define VX1000_DasTransmitLargeSyncLoop(SYN_ADR, DST_ADR, ACTIONS) /* empty */
#else /* !VX1000_SUPPRESS_TRACE_SUPPORT || VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_DasTransmitLargeSyncLoop(SYN_ADR, DST_ADR, ACTIONS) /* internally used by VX1000_DasTransmitLargeChunk */                                       \
          case 0x01UL: /* same method as in MemSyncWriteLargeChunks */                                                                                         \
            for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                         \
            {                                                                                                                                                  \
              word2 = Commands[step+1U]; /* actually this is "word3" */                                                                                        \
              srcAddr32 = Commands[step] + VX1000_ADDR_TO_PTR2VU32(gVX1000.DynamicLutAddr)[0xFFFFUL & (word2 >> 16)];                                          \
              chunkSize = word2 & 0xFFFFUL;                                                                                                                    \
              NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                                                                  \
              /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_DAQ) != 0U)         \
              {                                                                                                                                                \
                for (J = 0UL; J < chunkSize; ++J)                                                                                                              \
                {                                                                                                                                              \
                  VX1000_STORE64((SYN_ADR), (DST_ADR), NewaSrc32[J]); VX1000_BARRIER_FORCE_WRITE()                                                             \
                  (DST_ADR) += 4UL;                                                                                                                            \
                }                                                                                                                                              \
              }                                                                                                                                                \
              step += 2UL;                                                                                                                                     \
            }                                                                                                                                                  \
            break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_DasTransmitLargeChunk(SYN_ADR, DST_ADR, ACTIONS)                                                                                                \
      case 0x07U: /* VX1000_DasTransmitLargeChunk */                                                                                                           \
        ++step;                                                                                                                                                \
        switch (0xFFUL & (word1 >> 16))                                                                                                                        \
        {                                                                                                                                                      \
          case 0x00UL: /* same method as in MultiCopy32LargeChunks */                                                                                          \
            NewaDst32 = VX1000_ADDR_TO_PTR2VU32((DST_ADR));                                                                                                    \
            for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                         \
            {                                                                                                                                                  \
              word2 = Commands[step+1U]; /* actually this is "word3" */                                                                                        \
              srcAddr32 = Commands[step] + VX1000_ADDR_TO_PTR2VU32(gVX1000.DynamicLutAddr)[0xFFFFUL & (word2 >> 16)];                                          \
              chunkSize = word2 & 0xFFFFUL;                                                                                                                    \
              NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                                                                  \
              /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_DAQ) != 0U)         \
              {                                                                                                                                                \
                for (J = 0UL; J < chunkSize; ++J) { NewaDst32[0] = NewaSrc32[J]; NewaDst32 = &NewaDst32[1]; }                                                  \
              }                                                                                                                                                \
              step += 2UL;                                                                                                                                     \
            }                                                                                                                                                  \
            (DST_ADR) = VX1000_PTR2VU32_TO_ADDRESS(NewaDst32);                                                                                                 \
            break;                                                                                                                                             \
          VX1000_DasTransmitLargeSyncLoop((SYN_ADR), (DST_ADR), (ACTIONS)) /* optional case 0x01 for memsync */                                                \
          case 0x02UL: /* same method as in FixDst32LargeChunks */                                                                                             \
            for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                         \
            {                                                                                                                                                  \
              word2 = Commands[step+1U]; /* actually this is "word3" */                                                                                        \
              srcAddr32 = Commands[step] + VX1000_ADDR_TO_PTR2VU32(gVX1000.DynamicLutAddr)[0xFFFFUL & (word2 >> 16)];                                          \
              chunkSize = word2 & 0xFFFFUL;                                                                                                                    \
              NewaSrc32 = VX1000_ADDR_TO_PTR2VU32(srcAddr32);                                                                                                  \
              /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_DAQ) != 0U)         \
              {                                                                                                                                                \
                /* The FW takes care that this command is never used together with other commands that use or abuse the destination value */                   \
                for (J = 0UL; J < chunkSize; ++J) { VX1000_STORE_FIXDST((DST_ADR), NewaSrc32[J]); }                                                            \
              }                                                                                                                                                \
              step += 2UL;                                                                                                                                     \
            }                                                                                                                                                  \
            break;                                                                                                                                             \
          default:                                                                                                                                             \
            /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_DAQ) != 0U)           \
            {                                                                                                                                                  \
              VX1000_ERRLOGGER(VX1000_ERRLOG_OLDA_UNIMPLSUB)                                                                                                   \
            }                                                                                                                                                  \
            step += 2UL * (0xFFUL & (word1 >> 8));                                                                                                             \
            break;                                                                                                                                             \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_DYNADDRSIG_ENABLED */


#if 0U == (VX1000_CO_OFFLOADER_COUNT)
#define VX1000_ASYNC_OLDA_DECL_AUX_VAR /* empty */
#define VX1000_ASYNC_OLDA_REMEMBA(ADR) /* empty */                                                                                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#define VX1000_AsyncOldaEnqueueCopyJobs(ACTIONS, EVENT) /* empty */                                                                                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else /* VX1000_CO_OFFLOADER_COUNT */
#define VX1000_ASYNC_OLDA_DECL_AUX_VAR EventDataAddr = 0UL,
#define VX1000_ASYNC_OLDA_REMEMBA(ADR) do { EventDataAddr = (ADR); } while (0);  /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. */
#if !defined(VX1000_DYNADDRSIG_ENABLED)
#define VX1000_AsyncOldaEnqueueCopyDas() /* empty */
#else /* VX1000_DYNADDRSIG_ENABLED */
#define VX1000_AsyncOldaEnqueueCopyDas() /* internally used by VX1000_AsyncOldaEnqueueCopyJobs */                                                              \
              else                                                                                                                                             \
              {                                                                                                                                                \
                VX1000_UINT32 dasindex = VX1000_CO_GET_DAS_INDEX(pDescr), dasaddr = VX1000_CO_GET_POOLOFFSET16(pDescr);                                        \
                dasaddr -= (dasaddr & 0x8000UL) << 1; /* treat as signed */                                                                                    \
                dasaddr += VX1000_ADDR_TO_PTR2VU32(gVX1000.StaticLutAddr)[(4UL * dasindex) + /*.a2lAddr:*/0UL];                                                \
                dasaddr += VX1000_ADDR_TO_PTR2VU32(gVX1000.DynamicLutAddr)[dasindex];                                                                          \
                (VX1000_CO_GET_RW_PTR_TO_SRCADDR(pDescr))[0] = dasaddr;                                                                                        \
              } /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_DYNADDRSIG_ENABLED */
#if !defined(VX1000_DYNADDRSIG_ENABLED)
#define VX1000_AsyncOldaDasCondition(ACTIONS) if ((MetadataOffset | ((ACTIONS) & VX1000_OLDAPROC_SPECEV)) != 0UL) /* PRQA S 3412 */ /* Cannot avoid violating MISRA rule 19.4 because the code fragment indeed is just a fragment that cannot exist self-contained in parentheses. Adapting the code would make it un-compilable */
#else  /* VX1000_DYNADDRSIG_ENABLED */
#define VX1000_AsyncOldaDasCondition(ACTIONS) if (VX1000_CO_GET_ARE_PATCHES_USED(pDescr) != 0UL) /* the new FW requests execution of the patching loop depending whether the current event despite DAS feature has no or has at least one DAS in its signal list */ /* PRQA S 3412 */ /* Cannot avoid violating MISRA rule 19.4 because the code fragment indeed is just a fragment that cannot exist self-contained in parentheses. Adapting the code would make it un-compilable */
#endif /* VX1000_DYNADDRSIG_ENABLED */
#define VX1000_AsyncOldaEnqueueCopyJobs(ACTIONS, EVENT)                                                                                                        \
      case 0x08U: /* VX1000_AsyncOldaEnqueueCopyJobs */                                                                                                        \
        ++step;                                                                                                                                                \
        chunkSize  = (VX1000_UINT32)gVX1000.Olda.offloadStatus.CopyOffloaderCfgStructSize >> 2;                                                                \
        loops      = 0xFFUL & (word1 >> 16); /* actually this is offLoadNum */                                                                                 \
        /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & ((VX1000_OLDAPROC_DAQ | VX1000_OLDAPROC_RADAR) | VX1000_OLDAPROC_ERROR| (VX1000_OLDAPROC_SPECEV | /*"DAQ on dummy channel:"*/VX1000_OLDATRIG_VXSF))) != 0U)\
        {                                                                                                                                                      \
          /* safety note: the FW ensures that at least 1 entry exists (otherwise the command does not make sense anyway) */                                    \
          const VX1000_UINT32 VX1000_DECL_PTR *pDescr = &Commands[step];                                                                                       \
          VX1000_UINT32 k0 = 0UL, OLindex = VX1000_CO_GET_OFFLOADER_INDEX(pDescr);                                                                             \
          volatile VX1000_UINT32 VX1000_DECL_PTR *pMetaHAddr = 0, *pMetaFAddr /*dummy initialisation to avoid compiler warnings:*/ = 0;                        \
          /* select the DAS-specific header/footer by adding the offset that was computed by previous command 0x06 (MetadataOffset) to first and last entry */ \
          /* select the current DAS chunk by computing the current absolute address from the base and the offsets */                                           \
          /* safety note: the temporarily patched data is single-owner until end of measurement (so no mutex needed here) */                                   \
          VX1000_AsyncOldaDasCondition((ACTIONS))                                                                                                              \
          {                                                                                                                                                    \
            for (J = 0UL; J < loops; ++J)                                                                                                                      \
            {                                                                                                                                                  \
              if (VX1000_CO_GET_DO_PATCH4VXSF(pDescr) != 0UL)                                                                                                  \
              {                                                                                                                                                \
                pMetaFAddr = VX1000_CO_GET_RW_PTR_TO_SRCADDR(pDescr);                                                                                          \
                pMetaFAddr[0] += MetadataOffset;                                                                                                               \
                if (0==pMetaHAddr) { pMetaHAddr = pMetaFAddr; } /* this algorithm assumes that there are exactly 0 or 2 PATCH4VXSF requests per event */       \
              }                                                                                                                                                \
              else if (VX1000_CO_GET_DO_PATCH4DAS(pDescr) != 0UL)                                                                                              \
              {                                                                                                                                                \
                /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_SPECEV) != 0U)    \
                {                                                                                                                                              \
                  /* Point to right dword in the currently used metadata to reach the 32bit eventnumber: */                                                    \
                  (VX1000_CO_GET_RW_PTR_TO_SRCADDR(pDescr))[0] = EventDataAddr;                                                                                \
                }                                                                                                                                              \
                VX1000_AsyncOldaEnqueueCopyDas() /* an optional else case for DAS-DAQ */                                                                       \
              }                                                                                                                                                \
              else                                                                                                                                             \
              {                                                                                                                                                \
                ; /* empty dummy else with empty dummy instruction only here for MISRA */                                                                      \
              }                                                                                                                                                \
              VX1000_CO_NEXT(pDescr)                                                                                                                           \
            }                                                                                                                                                  \
            pDescr = &Commands[step];                                                                                                                          \
          }                                                                                                                                                    \
          for (J = 1UL; J <= loops; ++J)                                                                                                                       \
          {                                                                                                                                                    \
            if (OLindex != ((J == loops)? 0xFFFFFFFFUL : VX1000_CO_GET_OFFLOADER_INDEX(&Commands[step + (J * chunkSize)]))) /* execute the user callback */    \
            {                                                                                                                                                  \
              volatile VX1000_CopyOffloadStatus_T *pOLsubstruct = &gVX1000.Olda.offloadStatus;                                                                 \
              VX1000_UINT8 OLresult = (*(VX1000_COPY_OFFLOAD_Q_FUNC_P_T)(pOLsubstruct->offloaderQueueFunction[OLindex]))(pDescr, J - k0);                      \
              if (OLresult == VX1000_ERRTYPE_OVERLOAD_MEMORY)                                                                                                  \
              {                                                                                                                                                \
                gVX1000.Olda.offloadStatus.offloaderInfos[OLindex].lastEventNumberWithOverldMemory = (VX1000_UINT16)(EVENT);                                   \
              }                                                                                                                                                \
              if (OLresult != VX1000_ERRTYPE_OK)                                                                                                               \
              {                                                                                                                                                \
                VX1000_NOTIFICATION_ERROR((VX1000_UINT8)OLindex, VX1000_DAQ_TYPE_XCP, OLresult)                                                                \
              }                                                                                                                                                \
              if (J < loops)                                                                                                                                   \
              {                                                                                                                                                \
                k0 = J;                                                                                                                                        \
                pDescr = &Commands[step + (J * chunkSize)];                                                                                                    \
                OLindex = VX1000_CO_GET_OFFLOADER_INDEX(pDescr);                                                                                               \
              }                                                                                                                                                \
            }                                                                                                                                                  \
          }                                                                                                                                                    \
          /* re-select the original header/footer by subtracting the offset that was computed by previous command 0x06 (MetadataOffset) */                     \
          if (pMetaHAddr != 0){pMetaHAddr[0] -= MetadataOffset;/*dummy check to avoid compiler warnings:*/if (pMetaFAddr!=0){pMetaFAddr[0] -= MetadataOffset;}}\
        }                                                                                                                                                      \
        step += loops * chunkSize; /* skip the in-place data structures */                                                                                     \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_CO_OFFLOADER_COUNT */


#define VX1000_RelJump(DST_ADR)                                                                                                                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0x09U: /* VX1000_RelJump */                                                                                                                         \
        switch (0xFFUL & (word1 >> 8))                                                                                                                         \
        {                                                                                                                                                      \
          case 0x00UL: /* jump bytes forward in destination space */                                                                                           \
            (DST_ADR) += (0xFFFFUL & (word1 >> 16));                                                                                                           \
            break;                                                                                                                                             \
          case 0x01UL: /* jump bytes backward in destination space */                                                                                          \
            (DST_ADR) -= (0xFFFFUL & (word1 >> 16));                                                                                                           \
            break;                                                                                                                                             \
          default:                                                                                                                                             \
            VX1000_ERRLOGGER(VX1000_ERRLOG_OLDA_UNIMPLSUB)                                                                                                     \
            break;                                                                                                                                             \
        }                                                                                                                                                      \
        ++step;                                                                                                                                                \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */


#if ((!defined(VX1000_MEMSYNC_TRIGGER_COUNT)) || (0U==(VX1000_MEMSYNC_TRIGGER_COUNT))) || defined(VX1000_SUPPRESS_TRACE_SUPPORT)
#define VX1000_SelectMemsyncTrigger(SYN_ADR) /* empty */                                                                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else /* VX1000_MEMSYNC_TRIGGER_COUNT && !VX1000_SUPPRESS_TRACE_SUPPORT */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 1U)
#define VX1000_SelectMemsyncTriggerPre(SYN_ADR) /* internally used by VX1000_SelectMemsyncTrigger */                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
            if ((0xFFUL & (word1 >> 8)) < gVX1000.MemSyncTrigCnt)                                                                                              \
            {                                                                                                                                                  \
              (SYN_ADR) = gVX1000.tmp.MemsyCache[0xFFUL & (word1 >> 8)];                                                                                       \
            } /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#elif (VX1000_MEMSYNC_TRIGGER_COUNT == 1U)
#define VX1000_SelectMemsyncTriggerPre(SYN_ADR) /* internally used by VX1000_SelectMemsyncTrigger */                                                           \
            (SYN_ADR) = gVX1000.tmp.MemsyCache[0]; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_SelectMemsyncTriggerPre(SYN_ADR) /* empty */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 1U) && (!defined(VX1000_SUPPRESS_TRACE_SUPPORT))
#define VX1000_SelectMemsyncTriggerStd(SYN_ADR) /* internally used by VX1000_SelectMemsyncTrigger */                                                           \
            do                                                                                                                                                 \
            {                                                                                                                                                  \
              VX1000_UINT8 NewaProp = (VX1000_UINT8)(VX1000_CURRENT_CORE_IDX());                                                                               \
              if (NewaProp >= ((VX1000_UINT8)(gVX1000.MemSyncTrigCnt)))                                                                                        \
              {                                                                                                                                                \
                NewaProp = 0U;                                                                                                                                 \
                VX1000_ERRLOGGER(VX1000_ERRLOG_TOO_MANY_CORES)                                                                                                 \
              }                                                                                                                                                \
              (SYN_ADR) = gVX1000.tmp.MemsyCache[NewaProp];                                                                                                    \
            } while (0); /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#elif (VX1000_MEMSYNC_TRIGGER_COUNT == 1U) && (!defined(VX1000_SUPPRESS_TRACE_SUPPORT))
#define VX1000_SelectMemsyncTriggerStd(SYN_ADR) /* internally used by VX1000_SelectMemsyncTrigger */                                                           \
            (SYN_ADR) = gVX1000.tmp.MemsyCache[0]; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#else /* VX1000_MEMSYNC_TRIGGER_COUNT == 0 */
#define VX1000_SelectMemsyncTriggerStd(SYN_ADR) /* empty */
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT <= 1 */
#define VX1000_SelectMemsyncTrigger(SYN_ADR)                                                                                                                   \
      case 0x0AU: /* VX1000_SelectMemsyncTrigger */                                                                                                            \
        if ((0xFFUL & (word1 >> 8)) < 0x20UL)                                                                                                                  \
        {                                                                                                                                                      \
          VX1000_SelectMemsyncTriggerPre((SYN_ADR))  /* access the right gVX1000.MemSyncTrigPtr */                                                             \
          ++step;                                                                                                                                              \
          ++step;                                    /* skip the unused placeholder for sub-command 0xFE that is specified to be always present */             \
        }                                                                                                                                                      \
        else if ((0xFFUL & (word1 >> 8)) == 0xFEUL)  /* use an alternative memsync trigger address, directly provided by the FW as MemSync_0 address */        \
        {                                                                                                                                                      \
          (SYN_ADR) = Commands[step + 1UL];                                                                                                                    \
          step += 2UL;                                                                                                                                         \
        }                                                                                                                                                      \
        else if ((0xFFUL & (word1 >> 8)) == 0xFFUL)  /* return to the default (core-dependent) memsync trigger */                                              \
        {                                                                                                                                                      \
          VX1000_SelectMemsyncTriggerStd((SYN_ADR))  /* access the right gVX1000.MemSyncTrigPtr */                                                             \
          ++step;                                                                                                                                              \
          ++step;                                    /* skip the unused placeholder for sub-command 0xFE that is specified to be always present */             \
        }                                                                                                                                                      \
        else                                                                                                                                                   \
        {                                                                                                                                                      \
          VX1000_ERRLOGGER(VX1000_ERRLOG_OLDA_UNIMPLSUB)                                                                                                       \
          step = 0xFFFFUL;                                                                                                                                     \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT */


#define VX1000_AbsJump(DST_ADR, VX_ADR)                                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0x0BU: /* VX1000_AbsJump */                                                                                                                         \
        switch (0xFFUL & (word1 >> 8))                                                                                                                         \
        {                                                                                                                                                      \
          case 0x00UL: /* jump to absolute address in destination space */                                                                                     \
            (DST_ADR) = Commands[step + 1UL];                                                                                                                  \
            step += 2UL;                                                                                                                                       \
            break;                                                                                                                                             \
          VX1000_RelocateEvTrigAddr((VX_ADR))                                                                                                                  \
          default:                                                                                                                                             \
            VX1000_ERRLOGGER(VX1000_ERRLOG_OLDA_UNIMPLSUB)                                                                                                     \
            step = 0xFFFFUL;                                                                                                                                   \
            break;                                                                                                                                             \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */

#if !defined(VX1000_SUPPRESS_TRACE_SUPPORT)
#define VX1000_RelocateEvTrigAddr(VX_ADR)                                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
          case 0x01UL: /* relocate trace event trigger to outside the gVX1000 structure */                                                                     \
            (VX_ADR) = Commands[step + 1UL];                                                                                                                   \
            step += 2UL;                                                                                                                                       \
            break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#else  /* VX1000_SUPPRESS_TRACE_SUPPORT */
#define VX1000_RelocateEvTrigAddr(VX_ADR) /* empty */
#endif /* VX1000_SUPPRESS_TRACE_SUPPORT */


#if (!defined(VX1000_STIM)) || (!defined(VX1000_STIM_BY_OLDA))
#define VX1000_LastStim(DST_ADR, ACTIONS) /* empty */                                                                                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else /* VX1000_STIM && VX1000_STIM_BY_OLDA */
#define VX1000_LastStim(DST_ADR, ACTIONS)                                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0xE0U: /* VX1000_LastStim */                                                                                                                        \
        step = 0xFFFFUL; /* in contrast to LastCommand (0x00U) LastStim (0xE0U) does not care for trigger settings */                                          \
        break;                                                                                                                                                 \
      case 0xE1U: /* VX1000_MultiStim8 */                                                                                                                      \
        ++step;                                                                                                                                                \
        srcAddr32 = word1;                                                                                                                                     \
        for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                             \
        {                                                                                                                                                      \
          word2 = Commands[step];                                                                                                                              \
          chunkSize = word2 & 0xFFUL;                                                                                                                          \
          srcAddr32 = (srcAddr32 & 0xFF000000UL) | (0xFFFFFFUL & (word2 >> 8));                                                                                \
          NewaSrc8 = VX1000_ADDR_TO_PTR2VU8(srcAddr32);                                                                                                        \
          NewaDst8 = VX1000_ADDR_TO_PTR2VU8((DST_ADR));                                                                                                        \
          /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_STIM) != 0U)            \
          {                                                                                                                                                    \
            for (J = 0UL; J < chunkSize; ++J) { NewaSrc8[J] = NewaDst8[J]; } /* for STIM the inverse copy direction compared to DAQ is used */                 \
            (DST_ADR) += chunkSize;                                                                                                                            \
          }                                                                                                                                                    \
          ++step;                                                                                                                                              \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_STIM && VX1000_STIM_BY_OLDA */


#if (!defined(VX1000_STIM)) || (!defined(VX1000_STIM_BY_OLDA))
#define VX1000_MultiStim8LargeChunks(DST_ADR, ACTIONS) /* empty */                                                                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else /* VX1000_STIM && VX1000_STIM_BY_OLDA */
#define VX1000_MultiStim8LargeChunks(DST_ADR, ACTIONS)                                                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0xE2U: /* VX1000_MultiStim8LargeChunks */                                                                                                           \
        ++step;                                                                                                                                                \
        srcAddr32 = word1;                                                                                                                                     \
        for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                             \
        {                                                                                                                                                      \
          word2 = Commands[step];                                                                                                                              \
          chunkSize = word2 & 0xFFFFUL;                                                                                                                        \
          srcAddr32 = (srcAddr32 & 0xFFFF0000UL) | (0xFFFFUL & (word2 >> 16));                                                                                 \
          NewaSrc8 = VX1000_ADDR_TO_PTR2VU8(srcAddr32);                                                                                                        \
          NewaDst8 = VX1000_ADDR_TO_PTR2VU8((DST_ADR));                                                                                                        \
          /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_STIM) != 0U)            \
          {                                                                                                                                                    \
            for (J = 0UL; J < chunkSize; ++J) { NewaSrc8[J] = NewaDst8[J]; } /* for STIM the inverse copy direction compared to DAQ is used */                 \
            (DST_ADR) += chunkSize;                                                                                                                            \
          }                                                                                                                                                    \
          ++step;                                                                                                                                              \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_STIM && VX1000_STIM_BY_OLDA */


#if ((!defined(VX1000_STIM)) || (!defined(VX1000_STIM_BY_OLDA))) || (!defined(VX1000_DYNADDRSIG_ENABLED))
#define VX1000_DasStim8LargeChunk(DST_ADR, ACTIONS) /* empty */                                                                                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else /* VX1000_STIM && VX1000_STIM_BY_OLDA && VX1000_DYNADDRSIG_ENABLED */
#define VX1000_DasStim8LargeChunk(DST_ADR, ACTIONS)                                                                                                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      case 0xE3U: /* VX1000_DasStim8LargeChunk */                                                                                                              \
        ++step;                                                                                                                                                \
        for (loops = 0xFFUL & (word1 >> 8); loops != 0UL; --loops)                                                                                             \
        {                                                                                                                                                      \
          word2 = Commands[step+1U]; /* actually this is "word3" */                                                                                            \
          srcAddr32 = Commands[step] + VX1000_ADDR_TO_PTR2VU32(gVX1000.DynamicLutAddr)[0xFFFFUL & (word2 >> 16)];                                              \
          chunkSize = word2 & 0xFFFFUL;                                                                                                                        \
          NewaSrc8 = VX1000_ADDR_TO_PTR2VU8(srcAddr32);                                                                                                        \
          NewaDst8 = VX1000_ADDR_TO_PTR2VU8((DST_ADR));                                                                                                        \
          /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDAPROC_STIM) != 0U)            \
          {                                                                                                                                                    \
            for (J = 0UL; J < chunkSize; ++J) { NewaSrc8[J] = NewaDst8[J]; } /* for STIM the inverse copy direction compared to DAQ is used */                 \
            (DST_ADR) += chunkSize;                                                                                                                            \
          }                                                                                                                                                    \
          step += 2UL;                                                                                                                                         \
        }                                                                                                                                                      \
        break; /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because optional cases of a switch statement cannot be outsourced to sub functions. */
#endif /* VX1000_STIM && VX1000_STIM_BY_OLDA && VX1000_DYNADDRSIG_ENABLED */


#define VX1000_NEWA_TRIGGER(EVENT, TIME, VX_ADR, SYN_ADR, ACTIONS) do          /* The trigger is used in different places, macro faster than function. */      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
  {                                                                                                                                                            \
    VX1000_UINT32 timeStamp = (TIME);                                                                                                                          \
    /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & ((VX1000_OLDASAVE_TIME) | (VX1000_OLDATRIG_MEMSY | VX1000_OLDATRIG_TRACE))) == VX1000_OLDASAVE_TIME)\
    {                                                                                                                                                          \
      VX1000_TRIGGER_DO_ONLY_TIME((VX_ADR), (SYN_ADR))                                                                                                         \
    }                                                                                                                                                          \
    /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDATRIG_MEMSY) != 0UL)                \
    {                                                                                                                                                          \
      VX1000_TRIGGER_DO_ALL_THE_MEMSY((ACTIONS), (EVENT), (VX_ADR), (SYN_ADR))                                                                                 \
    }                                                                                                                                                          \
    /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDATRIG_TRACE) != 0UL) /* Optionally store event ID */\
    {                                                                                                                                                          \
      VX1000_TRIGGER_STORE_FOR_TRACE((ACTIONS), (EVENT), (VX_ADR))                                                                                             \
    }                                                                                                                                                          \
    /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDATRIG_NIOS) != 0UL) /* Optionally OLDA-trigger the event */\
    {                                                                                                                                                          \
      /*lint -e(506,587,774,778,835) constant expressions desired for compile-time optimisations*/if (((ACTIONS) & VX1000_OLDASAVE_TIME) != 0UL)               \
      {                                                                                                                                                        \
        gVX1000.EventTimestamp = timeStamp;        /* Note that, as the NIOS works always with the REAL gVX1000, the VX_ADR parameter is NOT used here */      \
      }                                                                                                                                                        \
      VX1000_TRIGGER_OLDA_CHANNEL(EVENT)                                                                                                                       \
    }                                                                                                                                                          \
  } while (0)   /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. */


/* target specific modifications of VX1000_NEWA_TRIGGER: */
#if (!defined(VX1000_TARGET_TRICORE)) || (defined(VX1000_FORCE_NO_DAP_NO_TRIG))
#define VX1000_TRIGGER_TRICORE_REPEAT(COUNT) /* empty */                                                                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#else  /* VX1000_TARGET_TRICORE && !VX1000_FORCE_NO_DAP_NO_TRIG */
#define VX1000_TRIGGER_TRICORE_REPEAT(COUNT) VX1000_UINT32 letLoop; for (letLoop = 0UL; letLoop < (COUNT); ++letLoop)  /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_TARGET_TRICORE && !VX1000_FORCE_NO_DAP_NO_TRIG */

#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 31U
#define VX1000_TRIGGER_INFORM_THE_NIOS(EVENT)                                                                                                                  \
    VX1000_ATOMIC_XOR8POW2(gVX1000.Olda.OldaTriggerAddr + ((EVENT) >> 3), (VX1000_UINT8)((EVENT) & 0x7UL)); /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#elif defined(VX1000_TARGET_TRICORE) && (!defined(VX1000_FORCE_NO_DAP_NO_TRIG))
#define VX1000_TRIGGER_INFORM_THE_NIOS(EVENT)                                                                                                                  \
    if ((VX1000_DERIVATIVE_TC4XX) == (VX1000_DERIVATIVE_CLASS))                                                                                                \
    {                                                                                                                                                          \
      VX1000_SFR_WRITE_32(VX1000_SFR_SECTION_OCDS, 0xFA180318UL, (EVENT));                                                                                     \
    }                                                                                                                                                          \
    else if ((VX1000_DERIVATIVE_TC2XX) <= (VX1000_DERIVATIVE_CLASS)) /* TC3XX or TC2XX */                                                                      \
    {                                                                                                                                                          \
      VX1000_SFR_WRITE_32(VX1000_SFR_SECTION_OCDS, VX1000_MCREG_OCDS_TRIGS_ADDR, (EVENT));                                                                     \
    }                                                                                                                                                          \
    else                                                                                                                                                       \
    {                                                                                                                                                          \
      VX1000_SFR_WRITE_32(VX1000_SFR_SECTION_OCDS, VX1000_MCREG_OCDS_TRIGS_ADDR, 1UL << (EVENT));                                                              \
    } /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#elif defined(VX1000_OLDA_AUDMBR_REG_ADDR) && ((VX1000_OLDA_ACTIVE_EVT_CNT_MAX) <= 15U)
#define VX1000_TRIGGER_INFORM_THE_NIOS(EVENT)                                                                                                                  \
    VX1000_SFR_WRITE_16(VX1000_SFR_SECTION_AUDMBR, VX1000_OLDA_AUDMBR_REG_ADDR, (VX1000_UINT16)(1UL << (EVENT)));  /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#elif defined(VX1000_OLDA_DTS_BASE_ADDR)
#define VX1000_TRIGGER_INFORM_THE_NIOS(EVENT)                                                                                                                  \
    VX1000_SFR_WRITE_32(VX1000_SFR_SECTION_DTS, (VX1000_OLDA_DTS_BASE_ADDR + 8UL), 1UL << (EVENT)); /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#elif defined(VX1000_TARGET_XC2000)
#define VX1000_TRIGGER_INFORM_THE_NIOS(EVENT)                                                                                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
    gVX1000.OldaEventNumber ^= (VX1000_UINT32)(1UL << (EVENT));                                                                                                \
    gVX1000.CalPtr ^= (VX1000_UINT32)(1UL << (EVENT)); /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#else  /* (!VX1000_TARGET_TRICORE || VX1000_FORCE_NO_DAP_NO_TRIG) && !VX1000_TARGET_XC2000 && !VX1000_OLDA_AUDMBR_REG_ADDR && !VX1000_OLDA_DTS_BASE_ADDR */
#define VX1000_TRIGGER_INFORM_THE_NIOS(EVENT)                                                                                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
    VX1000_ATOMIC_XOR32X2(VX1000_PTR2VU32_TO_ADDRESS(&gVX1000.OldaEventNumber), (VX1000_UINT32)(1UL << (EVENT))); /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* (!VX1000_TARGET_TRICORE || VX1000_FORCE_NO_DAP_NO_TRIG) && !VX1000_TARGET_XC2000 && !VX1000_OLDA_AUDMBR_REG_ADDR && !VX1000_OLDA_DTS_BASE_ADDR */


/* user-dependent modifications of VX1000_NEWA_TRIGGER: */
#if defined(VX1000_OLDA)
#define VX1000_TRIGGER_OLDA_CHANNEL(EVENT) do       /* Note that, as the NIOS works always with the REAL gVX1000, the VX_ADR parameter is NOT used here */     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      {                                                                                                                                                        \
        VX1000_UINT32 ev = (EVENT);                                                                                                                            \
        if (ev >= (VX1000_UINT32)(VX1000_OLDA_ACTIVE_EVT_CNT_MAX))                 /* Is it a special event? -> move it to proprietary fixed channel 31 */     \
        {                                                                                                                                                      \
          gVX1000.EventNumber = ev; /* NIOS boots up in VX1240 mode, FW didn't download the OLDA cfg, yet -> expecting special event payload at fix position */\
          ev = 31UL;                                                                                                                                           \
        }                                                                                                                                                      \
        else if (ev == 31UL)                        /* Is it a DAQ event on proprietary fixed special event channel? -> move it to last channel plus one */    \
        {                                                                                                                                                      \
          ev = gVX1000.Olda.EventCount;                                                                                                                        \
        }                                                                                                                                                      \
        else                                                                       /* It's a DAQ event and the channel is encoded in the bit position */       \
        {                                                                                                                                                      \
          ;                                                                        /* An empty else case with dummy statement only here for MISRA */           \
        }                                                                                                                                                      \
        VX1000_TRIGGER_INFORM_THE_NIOS(ev)                                                                                                                     \
      } while (0);                                                                                                                                             /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#else  /* !VX1000_OLDA */
#define VX1000_TRIGGER_OLDA_CHANNEL(EVENT) /* Empty */                                                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#endif /* !VX1000_OLDA */

#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_TRIGGER_DO_ONLY_TIME(VX_ADR, SYN_ADR) do { VX1000_STORE64((SYN_ADR), (VX_ADR) + 4UL, timeStamp); VX1000_BARRIER_FORCE_WRITE() } while (0);      /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#elif !defined(VX1000_SUPPRESS_TRACE_SUPPORT)
#define VX1000_TRIGGER_DO_ONLY_TIME(VX_ADR, SYN_ADR) do                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      {                                                                                                                                                        \
        (VX1000_ADDR_TO_PTR2VU32((VX_ADR)))[1] /*"gVX1000.EventTimestamp"*/ = timeStamp;                                                                       \
        VX1000_BARRIER_FORCE_WRITE()                                             /* Ensure that the timestamp is actually stored/synced */                     \
      } while (0); /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#else  /* VX1000_SUPPRESS_TRACE_SUPPORT */
#define VX1000_TRIGGER_DO_ONLY_TIME(VX_ADR, SYN_ADR) gVX1000.EventTimestamp = timeStamp;                                                                       /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* VX1000_SUPPRESS_TRACE_SUPPORT */

#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U) && defined(VX1000_COMBINE_TIMESTAMP_EVENT)
#define VX1000_TRIGGER_DO_ALL_THE_MEMSY(ACTIONS, EVENT, VX_ADR, SYN_ADR)                                                                                       \
      if ((((ACTIONS) & VX1000_OLDASAVE_TIME) != 0UL) && ((EVENT) <= 0xFFFFUL)) /* Both the timestamp and the event info shall be synced together */           \
      {                                                                                                                                                        \
        VX1000_BARRIER_FORCE_ORDER() /* Ensure storage order: first DAQ data, then timestamp+trigger */                                                        \
        VX1000_STORE64((SYN_ADR), (((EVENT) << 16) + 1UL), timeStamp);  VX1000_BARRIER_FORCE_WRITE() /* Combined memsy trigger without address information */  \
        VX1000_BARRIER_FORCE_ORDER() /* Ensure storage order: current event cycle must be finished before data of new cycle can be transmitted */              \
      }                                                                                                                                                        \
      else                                                                                                                                                     \
      { VX1000_TRIGGER_SEPARATE_MEMSY((ACTIONS), (EVENT), (VX_ADR), (SYN_ADR)) }                                                                               /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#elif ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_TRIGGER_DO_ALL_THE_MEMSY(ACTIONS, EVENT, VX_ADR, SYN_ADR)  do { VX1000_TRIGGER_SEPARATE_MEMSY((ACTIONS),(EVENT),(VX_ADR),(SYN_ADR)) } while (0);/* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_TRIGGER_DO_ALL_THE_MEMSY(ACTIONS, EVENT, VX_ADR, SYN_ADR)  /* Empty */                                                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */

#define VX1000_TRIGGER_SEPARATE_MEMSY(ACTIONS, EVENT, VX_ADR, SYN_ADR) do                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
      {                                                                                                                                                        \
        if (((ACTIONS) & VX1000_OLDASAVE_TIME) != 0UL)                                                                                                         \
        {                                                                                                                                                      \
          VX1000_UINT32 vxetsadr = (VX_ADR) + 4UL;                                                                                                             \
          VX1000_TRIGGER_TRICORE_REPEAT(4UL) /* On TriCore we have to write four times to ensure that both time and address are not run over by eventNumber: */\
          {                                                                                                                                                    \
            VX1000_STORE64((SYN_ADR), vxetsadr, timeStamp); VX1000_BARRIER_FORCE_WRITE()                                                                       \
          }                                                                                                                                                    \
        }                                                                                                                                                      \
        VX1000_BARRIER_FORCE_ORDER() /* Ensure storage order: first DAQ and/or timestamp, then trigger */                                                      \
        VX1000_STORE64((SYN_ADR), (VX_ADR), (EVENT)); VX1000_BARRIER_FORCE_WRITE()                                                                             \
        VX1000_BARRIER_FORCE_ORDER() /* Ensure storage order: current event cycle must be finished before data of new cycle can be transmitted */              \
      } while (0); /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */

#if !defined(VX1000_SUPPRESS_TRACE_SUPPORT)
#if defined(VX1000_COMBINE_TIMESTAMP_EVENT)
#define VX1000_TRIGGER_STORE_FOR_TRACE(ACTIONS, EVENT, VX_ADR) do                                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
    {                                                                                                                                                          \
      if (((ACTIONS) & VX1000_OLDASAVE_TIME) != 0UL) /* Both timestamp and event shall be written */                                                           \
      {                                                                                                                                                        \
        VX1000_BARRIER_FORCE_ORDER() /* Ensure storage order: first DAQ data, then timestamp+trigger */                                                        \
        if (0xFEU == VX1000_ADDR_TO_PTR2U8(VX1000_PTR2VU32_TO_ADDRESS(&gVX1000.MagicId))[0])                                                                   \
        {                                                                                                                                                      \
          VX1000_STORE64((VX_ADR), (EVENT), timeStamp);                                                                                                        \
        }                                                                                                                                                      \
        else                                                                                                                                                   \
        {                                                                                                                                                      \
          VX1000_STORE64((VX_ADR), timeStamp, (EVENT));                                                                                                        \
        }                                                                                                                                                      \
      }                                                                                                                                                        \
      else                                                                                                                                                     \
      {                                                                                                                                                        \
        VX1000_BARRIER_FORCE_ORDER() /* Ensure storage order: first DAQ, then trigger */                                                                       \
        (VX1000_ADDR_TO_PTR2VU32((VX_ADR)))[0] /*"gVX1000.EventNumber"*/ = (EVENT);                                                                            \
      }                                                                                                                                                        \
      VX1000_BARRIER_FORCE_ORDER() /* Ensure storage order: current event cycle must be finished before data of new cycle can be transmitted */                \
    } while (0); /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#else  /* !VX1000_COMBINE_TIMESTAMP_EVENT */
#define VX1000_TRIGGER_STORE_FOR_TRACE(ACTIONS, EVENT, VX_ADR) do                                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would increase runtime significantly */\
    {                                                                                                                                                          \
      if (((ACTIONS) & VX1000_OLDASAVE_TIME) != 0UL) /* Both timestamp and event shall be written */                                                           \
      {                                                                                                                                                        \
        VX1000_TRIGGER_TRICORE_REPEAT(2UL)/* Increase probability that timestamp reaches VX before eventNumber does (TC has multiple parallel trace FIFOs!): */\
        {                                                                                                                                                      \
          (VX1000_ADDR_TO_PTR2VU32((VX_ADR)))[1] /*"gVX1000.EventTimestamp"*/ = timeStamp;                                                                     \
        }                                                                                                                                                      \
      }                                                                                                                                                        \
      VX1000_BARRIER_FORCE_ORDER() /* Ensure storage order: first DAQ and/or timestamp, then trigger */                                                        \
      (VX1000_ADDR_TO_PTR2VU32((VX_ADR)))[0] /*"gVX1000.EventNumber"*/ = (EVENT);                                                                              \
      VX1000_BARRIER_FORCE_ORDER() /* Ensure storage order: current event cycle must be finished before data of new cycle can be transmitted */                \
    } while (0); /* PRQA S 3412 */ /* Cannot justify to NOT violate MISRA rule 19.4 because subfunctions execute slower than macros and increase the risk of watchdog resets. Also the risk of mis-maintenance was higher when having the macro's code expanded manually all over the place */
#endif /* !VX1000_COMBINE_TIMESTAMP_EVENT */
#else  /* VX1000_SUPPRESS_TRACE_SUPPORT */
#define VX1000_TRIGGER_STORE_FOR_TRACE(ACTIONS, EVENT, VX_ADR) /* Empty */
#endif /* VX1000_SUPPRESS_TRACE_SUPPORT */



/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: VX1000_STORE_TIMESTAMP                                                                                      */
/* Classic API:   None ?                                                                                                      */
/* Wrapper API:   None ?                                                                                                      */
/* ASAM API:      None                                                                                                        */
/* Parameter1:    The current 32bit time                                                                                      */
/* Return value:  None                                                                                                        */
/* Preemption:    No problem                                                                                                  */
/* Termination:   No effect                                                                                                   */
/* Precondition1: vx1000_Init() must have been called.                                                                        */
/* Description:   TriCore-specific transmission of the parameter to the event timestamp field of the VX1000                   */
/* Devel state:   Deprecated                                                                                                  */
/*----------------------------------------------------------------------------------------------------------------------------*/
#if defined(VX1000_DISABLE_INSTRUMENTATION)
#define VX1000_STORE_TIMESTAMP(t)      VX1000_DUMMYREAD((t))                                                                                                                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_DISABLE_INSTRUMENTATION */
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_STORE_TIMESTAMP(t)      (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)(0UL, (VX1000_UINT32)(t), 0xFFFFFFFFUL, VX1000_OLDASAVE_TIME );                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_STORE_TIMESTAMP(t)      (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)(0UL, (VX1000_UINT32)(t), VX1000_OLDASAVE_TIME );                                                                                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: VX1000_STORE_EVENT                                                                                          */
/* Classic API:   None ?                                                                                                      */
/* Wrapper API:   None ?                                                                                                      */
/* ASAM API:      None                                                                                                        */
/* Parameter1:    eventNumber E [0,512) or any special eventNumber                                                            */
/* Return value:  None                                                                                                        */
/* Preemption:    No problem                                                                                                  */
/* Termination:   No effect                                                                                                   */
/* Precondition1: vx1000_Init() must have been called.                                                                        */
/* Description:   Trigger a TRACE event for the XCP master or a special event for VX-internal synchronisation purposes        */
/* Devel state:   Deprecated                                                                                                  */
/*----------------------------------------------------------------------------------------------------------------------------*/
#if defined(VX1000_DISABLE_INSTRUMENTATION)
#define VX1000_STORE_EVENT(e)          VX1000_DUMMYREAD((e))                                                                                                                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_DISABLE_INSTRUMENTATION */
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_STORE_EVENT(e)          (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), 0UL, 0xFFFFFFFFUL, (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY));                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_STORE_EVENT(e)          (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), 0UL, (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY));                                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

/* Special Events */
#define VX1000_EVENT_RAMZERO_START     0x00010000UL
#define VX1000_EVENT_RAMZERO_DONE      0x00010001UL
#define VX1000_EVENT_RAMSYNC_START     0x00010002UL
#define VX1000_EVENT_MAILBOX_INIT      0x00020000UL
#define VX1000_EVENT_MAILBOX_UPDATE    0x00020001UL
#define VX1000_EVENT_MAILBOX_RESETREQ  0x00020002UL
#define VX1000_EVENT_STIM_INIT         0x00030100UL
#define VX1000_EVENT_STIM_ACK          0x00030101UL
#define VX1000_EVENT_STIM_TIMEOUT(e)  (0x00030200UL | (VX1000_UINT32)(e))                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would inhibit constant propagation of the compiler */
#define VX1000_EVENT_STIM_ERR(e)      (0x00030300UL | (e))                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would inhibit constant propagation of the compiler */
#define VX1000_EVENT_STRUCT_INIT       0x00040000UL
#define VX1000_EVENT_GP(e)            (0x00050000UL | (e))                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would inhibit constant propagation of the compiler */
#define VX1000_ECU_EVT_SW_RESET        0x00050001UL
#define VX1000_ECU_EVT_OLDA_OVERLOAD   0x00050002UL
#define VX1000_ECU_EVT_SW_RESET_FAIL   0x00050003UL
#define VX1000_ECU_EVT_SW_RESET_PREP   0x00050004UL
#define VX1000_ECU_EVT_OLDA_DOUBLE_EVT 0x00050005UL /* FW-internal usage */
#define VX1000_ECU_EVT_OLDA_MISSED_EVT 0x00050006UL /* FW-internal usage */
#define VX1000_ECU_EVT_SPEC_EVT_MISSED 0x00050007UL /* FW-internal usage */
#define VX1000_ECU_EVT_OLDA_SEQUENCE   0x00050008UL
#define VX1000_ECU_EVT_NOTIFY_CHANGES  0x00050009UL
#define VX1000_ECU_EVT_STIM_SKIP(e)   (0x00058000UL | (VX1000_UINT32)(e))                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 because a function call would inhibit constant propagation of the compiler */

/*------------------------------------------------------------------------------ */
/* Check the configuration for plausibility                                      */
#if !defined(VX1000_DISABLE_INSTRUMENTATION)

#if defined(VX1000_DETECT_XCP)
#error By defining VX1000_DETECT_XCP you requested an unimplemented feature! If you really need such a thing, please contact Vector with a change request.
#endif /* VX1000_DETECT_XCP */

#if !defined(VX1000_CLOCK)
#error Please define VX1000_CLOCK() as a free running 32 bit timer of desired resolution!
#endif /* !VX1000_CLOCK */

#if (((VX1000_CLOCK_TIMER_SIZE != 0U) && (VX1000_CLOCK_TIMER_SIZE != 16U)) && ((VX1000_CLOCK_TIMER_SIZE != 24U) && (VX1000_CLOCK_TIMER_SIZE != 32U)))&& (VX1000_CLOCK_TIMER_SIZE != 64U)
#error VX1000_CLOCK_TIMER_SIZE supports only these values: 0U, 16U, 24U, 32U, 64U! (you may round down to gain a valid configuration)
#endif /* VX1000_CLOCK_TIMER_SIZE */

#if (!defined(VX1000_PCIE_BAR0_SIZE_BYTES)) && defined(VX1000_PCIE_BAR0_START_ADDR)
/* Note: we cannot check VX1000_PCIE_BAR0_SIZE_BYTES for zero in the preprocessor because it may be given as computation from */
/* linker labels. Therefore the feature is made dependent on the existence of the definition of VX1000_PCIE_BAR0_START_ADDR.  */
/* The check of the validity of the bar size (non-zero and power of two) must be postponed until the FW has read the gVX1000. */
#error As you provided VX1000_PCIE_BAR0_START_ADDR you must also define VX1000_PCIE_BAR0_SIZE_BYTES!
#endif /* !VX1000_PCIE_BAR0_SIZE_BYTES && VX1000_PCIE_BAR0_START_ADDR */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x10U
#error VX1000_CO_OFFLOADER_COUNT supports only values in the range 0 to 16!
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x10 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x00U
#if !defined(VX1000_CO_ACCESS_SIZES_00)
#error You must specify the supported access sizes of copy offloader 0x00 (VX1000_CO_ACCESS_SIZES_00)!
#endif /* !(VX1000_CO_ACCESS_SIZES_00) */
#if !defined(VX1000_CO_ADDRESS_MODES_00)
#error You must specify the supported access modes of copy offloader 0x00 (VX1000_CO_ADDRESS_MODES_00)!
#endif /* !(VX1000_CO_ADDRESS_MODES_00) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_00)
#error You must specify the maximally supported block size of copy offloader 0x00 (VX1000_CO_MAX_BLOCKSIZE_00)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_00) */
#if !defined(VX1000_CO_COPY_TYPES_00)
#error You must specify the supported copy types of copy offloader 0x00 (VX1000_CO_COPY_TYPES_00)!
#endif /* !(VX1000_CO_COPY_TYPES_00) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_00)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x00 (VX1000_CO_FUNCP_ENQUEUE_00)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_00 */
#if !defined(VX1000_CO_FUNCP_RESET_00)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x00 (VX1000_CO_FUNCP_RESET_00)!
#endif /* !VX1000_CO_FUNCP_RESET_00 */
#if !defined(VX1000_CO_FUNCP_STATUS_00)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x00 (VX1000_CO_FUNCP_STATUS_00)!
#endif /* !VX1000_CO_FUNCP_STATUS_00 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x00 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x01U
#if !defined(VX1000_CO_ACCESS_SIZES_01)
#error You must specify the supported access sizes of copy offloader 0x01 (VX1000_CO_ACCESS_SIZES_01)!
#endif /* !(VX1000_CO_ACCESS_SIZES_01) */
#if !defined(VX1000_CO_ADDRESS_MODES_01)
#error You must specify the supported access modes of copy offloader 0x01 (VX1000_CO_ADDRESS_MODES_01)!
#endif /* !(VX1000_CO_ADDRESS_MODES_01) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_01)
#error You must specify the maximally supported block size of copy offloader 0x01 (VX1000_CO_MAX_BLOCKSIZE_01)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_01) */
#if !defined(VX1000_CO_COPY_TYPES_01)
#error You must specify the supported copy types of copy offloader 0x01 (VX1000_CO_COPY_TYPES_01)!
#endif /* !(VX1000_CO_COPY_TYPES_01) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_01)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x01 (VX1000_CO_FUNCP_ENQUEUE_01)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_01 */
#if !defined(VX1000_CO_FUNCP_RESET_01)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x01 (VX1000_CO_FUNCP_RESET_01)!
#endif /* !VX1000_CO_FUNCP_RESET_01 */
#if !defined(VX1000_CO_FUNCP_STATUS_01)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x01 (VX1000_CO_FUNCP_STATUS_01)!
#endif /* !VX1000_CO_FUNCP_STATUS_01 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x01 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x02U
#if !defined(VX1000_CO_ACCESS_SIZES_02)
#error You must specify the supported access sizes of copy offloader 0x02 (VX1000_CO_ACCESS_SIZES_02)!
#endif /* !(VX1000_CO_ACCESS_SIZES_02) */
#if !defined(VX1000_CO_ADDRESS_MODES_02)
#error You must specify the supported access modes of copy offloader 0x02 (VX1000_CO_ADDRESS_MODES_02)!
#endif /* !(VX1000_CO_ADDRESS_MODES_02) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_02)
#error You must specify the maximally supported block size of copy offloader 0x02 (VX1000_CO_MAX_BLOCKSIZE_02)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_02) */
#if !defined(VX1000_CO_COPY_TYPES_02)
#error You must specify the supported copy types of copy offloader 0x02 (VX1000_CO_COPY_TYPES_02)!
#endif /* !(VX1000_CO_COPY_TYPES_02) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_02)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x02 (VX1000_CO_FUNCP_ENQUEUE_02)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_02 */
#if !defined(VX1000_CO_FUNCP_RESET_02)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x02 (VX1000_CO_FUNCP_RESET_02)!
#endif /* !VX1000_CO_FUNCP_RESET_02 */
#if !defined(VX1000_CO_FUNCP_STATUS_02)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x02 (VX1000_CO_FUNCP_STATUS_02)!
#endif /* !VX1000_CO_FUNCP_STATUS_02 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x02 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x03U
#if !defined(VX1000_CO_ACCESS_SIZES_03)
#error You must specify the supported access sizes of copy offloader 0x03 (VX1000_CO_ACCESS_SIZES_03)!
#endif /* !(VX1000_CO_ACCESS_SIZES_03) */
#if !defined(VX1000_CO_ADDRESS_MODES_03)
#error You must specify the supported access modes of copy offloader 0x03 (VX1000_CO_ADDRESS_MODES_03)!
#endif /* !(VX1000_CO_ADDRESS_MODES_03) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_03)
#error You must specify the maximally supported block size of copy offloader 0x03 (VX1000_CO_MAX_BLOCKSIZE_03)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_03) */
#if !defined(VX1000_CO_COPY_TYPES_03)
#error You must specify the supported copy types of copy offloader 0x03 (VX1000_CO_COPY_TYPES_03)!
#endif /* !(VX1000_CO_COPY_TYPES_03) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_03)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x03 (VX1000_CO_FUNCP_ENQUEUE_03)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_03 */
#if !defined(VX1000_CO_FUNCP_RESET_03)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x03 (VX1000_CO_FUNCP_RESET_03)!
#endif /* !VX1000_CO_FUNCP_RESET_03 */
#if !defined(VX1000_CO_FUNCP_STATUS_03)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x03 (VX1000_CO_FUNCP_STATUS_03)!
#endif /* !VX1000_CO_FUNCP_STATUS_03 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x03 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x04U
#if !defined(VX1000_CO_ACCESS_SIZES_04)
#error You must specify the supported access sizes of copy offloader 0x04 (VX1000_CO_ACCESS_SIZES_04)!
#endif /* !(VX1000_CO_ACCESS_SIZES_04) */
#if !defined(VX1000_CO_ADDRESS_MODES_04)
#error You must specify the supported access modes of copy offloader 0x04 (VX1000_CO_ADDRESS_MODES_04)!
#endif /* !(VX1000_CO_ADDRESS_MODES_04) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_04)
#error You must specify the maximally supported block size of copy offloader 0x04 (VX1000_CO_MAX_BLOCKSIZE_04)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_04) */
#if !defined(VX1000_CO_COPY_TYPES_04)
#error You must specify the supported copy types of copy offloader 0x04 (VX1000_CO_COPY_TYPES_04)!
#endif /* !(VX1000_CO_COPY_TYPES_04) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_04)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x04 (VX1000_CO_FUNCP_ENQUEUE_04)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_04 */
#if !defined(VX1000_CO_FUNCP_RESET_04)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x04 (VX1000_CO_FUNCP_RESET_04)!
#endif /* !VX1000_CO_FUNCP_RESET_04 */
#if !defined(VX1000_CO_FUNCP_STATUS_04)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x04 (VX1000_CO_FUNCP_STATUS_04)!
#endif /* !VX1000_CO_FUNCP_STATUS_04 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x04 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x05U
#if !defined(VX1000_CO_ACCESS_SIZES_05)
#error You must specify the supported access sizes of copy offloader 0x05 (VX1000_CO_ACCESS_SIZES_05)!
#endif /* !(VX1000_CO_ACCESS_SIZES_05) */
#if !defined(VX1000_CO_ADDRESS_MODES_05)
#error You must specify the supported access modes of copy offloader 0x05 (VX1000_CO_ADDRESS_MODES_05)!
#endif /* !(VX1000_CO_ADDRESS_MODES_05) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_05)
#error You must specify the maximally supported block size of copy offloader 0x05 (VX1000_CO_MAX_BLOCKSIZE_05)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_05) */
#if !defined(VX1000_CO_COPY_TYPES_05)
#error You must specify the supported copy types of copy offloader 0x05 (VX1000_CO_COPY_TYPES_05)!
#endif /* !(VX1000_CO_COPY_TYPES_05) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_05)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x05 (VX1000_CO_FUNCP_ENQUEUE_05)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_05 */
#if !defined(VX1000_CO_FUNCP_RESET_05)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x05 (VX1000_CO_FUNCP_RESET_05)!
#endif /* !VX1000_CO_FUNCP_RESET_05 */
#if !defined(VX1000_CO_FUNCP_STATUS_05)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x05 (VX1000_CO_FUNCP_STATUS_05)!
#endif /* !VX1000_CO_FUNCP_STATUS_05 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x05 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x06U
#if !defined(VX1000_CO_ACCESS_SIZES_06)
#error You must specify the supported access sizes of copy offloader 0x06 (VX1000_CO_ACCESS_SIZES_06)!
#endif /* !(VX1000_CO_ACCESS_SIZES_06) */
#if !defined(VX1000_CO_ADDRESS_MODES_06)
#error You must specify the supported access modes of copy offloader 0x06 (VX1000_CO_ADDRESS_MODES_06)!
#endif /* !(VX1000_CO_ADDRESS_MODES_06) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_06)
#error You must specify the maximally supported block size of copy offloader 0x06 (VX1000_CO_MAX_BLOCKSIZE_06)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_06) */
#if !defined(VX1000_CO_COPY_TYPES_06)
#error You must specify the supported copy types of copy offloader 0x06 (VX1000_CO_COPY_TYPES_06)!
#endif /* !(VX1000_CO_COPY_TYPES_06) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_06)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x06 (VX1000_CO_FUNCP_ENQUEUE_06)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_06 */
#if !defined(VX1000_CO_FUNCP_RESET_06)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x06 (VX1000_CO_FUNCP_RESET_06)!
#endif /* !VX1000_CO_FUNCP_RESET_06 */
#if !defined(VX1000_CO_FUNCP_STATUS_06)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x06 (VX1000_CO_FUNCP_STATUS_06)!
#endif /* !VX1000_CO_FUNCP_STATUS_06 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x06 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x07U
#if !defined(VX1000_CO_ACCESS_SIZES_07)
#error You must specify the supported access sizes of copy offloader 0x07 (VX1000_CO_ACCESS_SIZES_07)!
#endif /* !(VX1000_CO_ACCESS_SIZES_07) */
#if !defined(VX1000_CO_ADDRESS_MODES_07)
#error You must specify the supported access modes of copy offloader 0x07 (VX1000_CO_ADDRESS_MODES_07)!
#endif /* !(VX1000_CO_ADDRESS_MODES_07) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_07)
#error You must specify the maximally supported block size of copy offloader 0x07 (VX1000_CO_MAX_BLOCKSIZE_07)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_07) */
#if !defined(VX1000_CO_COPY_TYPES_07)
#error You must specify the supported copy types of copy offloader 0x07 (VX1000_CO_COPY_TYPES_07)!
#endif /* !(VX1000_CO_COPY_TYPES_07) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_07)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x07 (VX1000_CO_FUNCP_ENQUEUE_07)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_07 */
#if !defined(VX1000_CO_FUNCP_RESET_07)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x07 (VX1000_CO_FUNCP_RESET_07)!
#endif /* !VX1000_CO_FUNCP_RESET_07 */
#if !defined(VX1000_CO_FUNCP_STATUS_07)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x07 (VX1000_CO_FUNCP_STATUS_07)!
#endif /* !VX1000_CO_FUNCP_STATUS_07 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x07 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x08U
#if !defined(VX1000_CO_ACCESS_SIZES_08)
#error You must specify the supported access sizes of copy offloader 0x08 (VX1000_CO_ACCESS_SIZES_08)!
#endif /* !(VX1000_CO_ACCESS_SIZES_08) */
#if !defined(VX1000_CO_ADDRESS_MODES_08)
#error You must specify the supported access modes of copy offloader 0x08 (VX1000_CO_ADDRESS_MODES_08)!
#endif /* !(VX1000_CO_ADDRESS_MODES_08) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_08)
#error You must specify the maximally supported block size of copy offloader 0x08 (VX1000_CO_MAX_BLOCKSIZE_08)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_08) */
#if !defined(VX1000_CO_COPY_TYPES_08)
#error You must specify the supported copy types of copy offloader 0x08 (VX1000_CO_COPY_TYPES_08)!
#endif /* !(VX1000_CO_COPY_TYPES_08) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_08)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x08 (VX1000_CO_FUNCP_ENQUEUE_08)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_08 */
#if !defined(VX1000_CO_FUNCP_RESET_08)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x08 (VX1000_CO_FUNCP_RESET_08)!
#endif /* !VX1000_CO_FUNCP_RESET_08 */
#if !defined(VX1000_CO_FUNCP_STATUS_08)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x08 (VX1000_CO_FUNCP_STATUS_08)!
#endif /* !VX1000_CO_FUNCP_STATUS_08 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x08 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x09U
#if !defined(VX1000_CO_ACCESS_SIZES_09)
#error You must specify the supported access sizes of copy offloader 0x09 (VX1000_CO_ACCESS_SIZES_09)!
#endif /* !(VX1000_CO_ACCESS_SIZES_09) */
#if !defined(VX1000_CO_ADDRESS_MODES_09)
#error You must specify the supported access modes of copy offloader 0x09 (VX1000_CO_ADDRESS_MODES_09)!
#endif /* !(VX1000_CO_ADDRESS_MODES_09) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_09)
#error You must specify the maximally supported block size of copy offloader 0x09 (VX1000_CO_MAX_BLOCKSIZE_09)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_09) */
#if !defined(VX1000_CO_COPY_TYPES_09)
#error You must specify the supported copy types of copy offloader 0x09 (VX1000_CO_COPY_TYPES_09)!
#endif /* !(VX1000_CO_COPY_TYPES_09) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_09)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x09 (VX1000_CO_FUNCP_ENQUEUE_09)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_09 */
#if !defined(VX1000_CO_FUNCP_RESET_09)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x09 (VX1000_CO_FUNCP_RESET_09)!
#endif /* !VX1000_CO_FUNCP_RESET_09 */
#if !defined(VX1000_CO_FUNCP_STATUS_09)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x09 (VX1000_CO_FUNCP_STATUS_09)!
#endif /* !VX1000_CO_FUNCP_STATUS_09 */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x09 */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x0AU
#if !defined(VX1000_CO_ACCESS_SIZES_0A)
#error You must specify the supported access sizes of copy offloader 0x0A (VX1000_CO_ACCESS_SIZES_0A)!
#endif /* !(VX1000_CO_ACCESS_SIZES_0A) */
#if !defined(VX1000_CO_ADDRESS_MODES_0A)
#error You must specify the supported access modes of copy offloader 0x0A (VX1000_CO_ADDRESS_MODES_0A)!
#endif /* !(VX1000_CO_ADDRESS_MODES_0A) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_0A)
#error You must specify the maximally supported block size of copy offloader 0x0A (VX1000_CO_MAX_BLOCKSIZE_0A)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_0A) */
#if !defined(VX1000_CO_COPY_TYPES_0A)
#error You must specify the supported copy types of copy offloader 0x0A (VX1000_CO_COPY_TYPES_0A)!
#endif /* !(VX1000_CO_COPY_TYPES_0A) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_0A)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x0A (VX1000_CO_FUNCP_ENQUEUE_0A)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_0A */
#if !defined(VX1000_CO_FUNCP_RESET_0A)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x0A (VX1000_CO_FUNCP_RESET_0A)!
#endif /* !VX1000_CO_FUNCP_RESET_0A */
#if !defined(VX1000_CO_FUNCP_STATUS_0A)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x0A (VX1000_CO_FUNCP_STATUS_0A)!
#endif /* !VX1000_CO_FUNCP_STATUS_0A */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x0A */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x0BU
#if !defined(VX1000_CO_ACCESS_SIZES_0B)
#error You must specify the supported access sizes of copy offloader 0x0B (VX1000_CO_ACCESS_SIZES_0B)!
#endif /* !(VX1000_CO_ACCESS_SIZES_0B) */
#if !defined(VX1000_CO_ADDRESS_MODES_0B)
#error You must specify the supported access modes of copy offloader 0x0B (VX1000_CO_ADDRESS_MODES_0B)!
#endif /* !(VX1000_CO_ADDRESS_MODES_0B) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_0B)
#error You must specify the maximally supported block size of copy offloader 0x0B (VX1000_CO_MAX_BLOCKSIZE_0B)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_0B) */
#if !defined(VX1000_CO_COPY_TYPES_0B)
#error You must specify the supported copy types of copy offloader 0x0B (VX1000_CO_COPY_TYPES_0B)!
#endif /* !(VX1000_CO_COPY_TYPES_0B) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_0B)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x0B (VX1000_CO_FUNCP_ENQUEUE_0B)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_0B */
#if !defined(VX1000_CO_FUNCP_RESET_0B)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x0B (VX1000_CO_FUNCP_RESET_0B)!
#endif /* !VX1000_CO_FUNCP_RESET_0B */
#if !defined(VX1000_CO_FUNCP_STATUS_0B)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x0B (VX1000_CO_FUNCP_STATUS_0B)!
#endif /* !VX1000_CO_FUNCP_STATUS_0B */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x0B */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x0CU
#if !defined(VX1000_CO_ACCESS_SIZES_0C)
#error You must specify the supported access sizes of copy offloader 0x0C (VX1000_CO_ACCESS_SIZES_0C)!
#endif /* !(VX1000_CO_ACCESS_SIZES_0C) */
#if !defined(VX1000_CO_ADDRESS_MODES_0C)
#error You must specify the supported access modes of copy offloader 0x0C (VX1000_CO_ADDRESS_MODES_0C)!
#endif /* !(VX1000_CO_ADDRESS_MODES_0C) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_0C)
#error You must specify the maximally supported block size of copy offloader 0x0C (VX1000_CO_MAX_BLOCKSIZE_0C)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_0C) */
#if !defined(VX1000_CO_COPY_TYPES_0C)
#error You must specify the supported copy types of copy offloader 0x0C (VX1000_CO_COPY_TYPES_0C)!
#endif /* !(VX1000_CO_COPY_TYPES_0C) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_0C)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x0C (VX1000_CO_FUNCP_ENQUEUE_0C)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_0C */
#if !defined(VX1000_CO_FUNCP_RESET_0C)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x0C (VX1000_CO_FUNCP_RESET_0C)!
#endif /* !VX1000_CO_FUNCP_RESET_0C */
#if !defined(VX1000_CO_FUNCP_STATUS_0C)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x0C (VX1000_CO_FUNCP_STATUS_0C)!
#endif /* !VX1000_CO_FUNCP_STATUS_0C */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x0C */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x0DU
#if !defined(VX1000_CO_ACCESS_SIZES_0D)
#error You must specify the supported access sizes of copy offloader 0x0D (VX1000_CO_ACCESS_SIZES_0D)!
#endif /* !(VX1000_CO_ACCESS_SIZES_0D) */
#if !defined(VX1000_CO_ADDRESS_MODES_0D)
#error You must specify the supported access modes of copy offloader 0x0D (VX1000_CO_ADDRESS_MODES_0D)!
#endif /* !(VX1000_CO_ADDRESS_MODES_0D) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_0D)
#error You must specify the maximally supported block size of copy offloader 0x0D (VX1000_CO_MAX_BLOCKSIZE_0D)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_0D) */
#if !defined(VX1000_CO_COPY_TYPES_0D)
#error You must specify the supported copy types of copy offloader 0x0D (VX1000_CO_COPY_TYPES_0D)!
#endif /* !(VX1000_CO_COPY_TYPES_0D) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_0D)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x0D (VX1000_CO_FUNCP_ENQUEUE_0D)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_0D */
#if !defined(VX1000_CO_FUNCP_RESET_0D)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x0D (VX1000_CO_FUNCP_RESET_0D)!
#endif /* !VX1000_CO_FUNCP_RESET_0D */
#if !defined(VX1000_CO_FUNCP_STATUS_0D)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x0D (VX1000_CO_FUNCP_STATUS_0D)!
#endif /* !VX1000_CO_FUNCP_STATUS_0D */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x0D */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x0EU
#if !defined(VX1000_CO_ACCESS_SIZES_0E)
#error You must specify the supported access sizes of copy offloader 0x0E (VX1000_CO_ACCESS_SIZES_0E)!
#endif /* !(VX1000_CO_ACCESS_SIZES_0E) */
#if !defined(VX1000_CO_ADDRESS_MODES_0E)
#error You must specify the supported access modes of copy offloader 0x0E (VX1000_CO_ADDRESS_MODES_0E)!
#endif /* !(VX1000_CO_ADDRESS_MODES_0E) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_0E)
#error You must specify the maximally supported block size of copy offloader 0x0E (VX1000_CO_MAX_BLOCKSIZE_0E)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_0E) */
#if !defined(VX1000_CO_COPY_TYPES_0E)
#error You must specify the supported copy types of copy offloader 0x0E (VX1000_CO_COPY_TYPES_0E)!
#endif /* !(VX1000_CO_COPY_TYPES_0E) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_0E)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x0E (VX1000_CO_FUNCP_ENQUEUE_0E)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_0E */
#if !defined(VX1000_CO_FUNCP_RESET_0E)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x0E (VX1000_CO_FUNCP_RESET_0E)!
#endif /* !VX1000_CO_FUNCP_RESET_0E */
#if !defined(VX1000_CO_FUNCP_STATUS_0E)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x0E (VX1000_CO_FUNCP_STATUS_0E)!
#endif /* !VX1000_CO_FUNCP_STATUS_0E */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x0E */

#if (VX1000_CO_OFFLOADER_COUNT) > 0x0FU
#if !defined(VX1000_CO_ACCESS_SIZES_0F)
#error You must specify the supported access sizes of copy offloader 0x0F (VX1000_CO_ACCESS_SIZES_0F)!
#endif /* !(VX1000_CO_ACCESS_SIZES_0F) */
#if !defined(VX1000_CO_ADDRESS_MODES_0F)
#error You must specify the supported access modes of copy offloader 0x0F (VX1000_CO_ADDRESS_MODES_0F)!
#endif /* !(VX1000_CO_ADDRESS_MODES_0F) */
#if !defined(VX1000_CO_MAX_BLOCKSIZE_0F)
#error You must specify the maximally supported block size of copy offloader 0x0F (VX1000_CO_MAX_BLOCKSIZE_0F)!
#endif /* !(VX1000_CO_MAX_BLOCKSIZE_0F) */
#if !defined(VX1000_CO_COPY_TYPES_0F)
#error You must specify the supported copy types of copy offloader 0x0F (VX1000_CO_COPY_TYPES_0F)!
#endif /* !(VX1000_CO_COPY_TYPES_0F) */
#if !defined(VX1000_CO_FUNCP_ENQUEUE_0F)
#error You must specify a function pointer to your callback implementation that shall handle enqueuing requests for copy offloader 0x0F (VX1000_CO_FUNCP_ENQUEUE_0F)!
#endif /* !VX1000_CO_FUNCP_ENQUEUE_0F */
#if !defined(VX1000_CO_FUNCP_RESET_0F)
#error You must specify a function pointer to your callback implementation that shall handle reset requests for copy offloader 0x0F (VX1000_CO_FUNCP_RESET_0F)!
#endif /* !VX1000_CO_FUNCP_RESET_0F */
#if !defined(VX1000_CO_FUNCP_STATUS_0F)
#error You must specify a function pointer to your callback implementation that shall handle status queries for copy offloader 0x0F (VX1000_CO_FUNCP_STATUS_0F)!
#endif /* !VX1000_CO_FUNCP_STATUS_0F */
#endif /* VX1000_CO_OFFLOADER_COUNT > 0x0F */

#if defined(VX1000_OLDA) && defined(VX1000_OLDA_MEMORY_SIZE)
#if (VX1000_OLDA_MEMORY_SIZE > 0xFFFCU)
#error Maximum value allowed for VX1000_OLDA_MEMORY_SIZE configuration is 0xFFFC
#endif /* VX1000_OLDA_MEMORY_SIZE > 0xFFFC */
#endif /* VX1000_OLDA & VX1000_OLDA_MEMORY_SIZE */



#if defined(VX1000_OLDA) && defined(VX1000_OLDA_ACTIVE_EVT_CNT_MAX)
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX < 1U) || (VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 1023U)
#error "VX1000_OLDA_ACTIVE_EVT_CNT_MAX is not in valid range [1,1023]!"
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX not in range */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 15U)
#if defined(VX1000_OLDA_AUDMBR_REG_ADDR)
/*silently overridden now: #error "Either VX1000_OLDA_AUDMBR_REG_ADDR must be undefined or VX1000_OLDA_ACTIVE_EVT_CNT_MAX must be <= 15!"*/
#endif /* VX1000_OLDA_AUDMBR_REG_ADDR */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 15 */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 31U)
#if defined(VX1000_OLDA_DTS_BASE_ADDR)
/*silently overridden now: #error "Either VX1000_OLDA_DTS_BASE_ADDR must be undefined or VX1000_OLDA_ACTIVE_EVT_CNT_MAX must be <= 31!"*/
#endif /* VX1000_OLDA_DTS_BASE_ADDR */
#if defined(VX1000_TARGET_TRICORE) && (!defined(VX1000_FORCE_NO_DAP_NO_TRIG))
/*silently overridden now: #error "Either VX1000_FORCE_NO_DAP_NO_TRIG must be defined or VX1000_OLDA_ACTIVE_EVT_CNT_MAX must be <= 31!"*/
#endif /* VX1000_TARGET_TRICORE && !VX1000_FORCE_NO_DAP_NO_TRIG */
#if (defined(VX1000_TARGET_POWERPC) || defined(VX1000_TARGET_SH2)) || (defined(VX1000_TARGET_TMS570) || defined(VX1000_TARGET_XC2000))
/* The following check does not represent a technical limitation - it just keeps the amount of test steps to be performed per release in a bearable range: */
#error "On the used target architecture the define VX1000_OLDA_ACTIVE_EVT_CNT_MAX must be <= 31 (or undefined)!"
#endif /* VX1000_TARGET_POWERPC || VX1000_TARGET_SH2 || VX1000_TARGET_TMS570 || VX1000_TARGET_XC2000 */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 31 */
#endif /* VX1000_OLDA && VX1000_OLDA_ACTIVE_EVT_CNT_MAX */

#if defined(VX1000_STIM_BY_OLDA) && (!defined(VX1000_OLDA))
#error VX1000_STIM_BY_OLDA cannot be enabled while VX1000_OLDA is disabled!
#endif /* VX1000_STIM_BY_OLDA && !VX1000_OLDA */

#if defined(VX1000_STIM_BY_OLDA) && (!defined(VX1000_STIM))
#error VX1000_STIM_BY_OLDA cannot be enabled while VX1000_STIM is disabled!
#endif /* VX1000_STIM_BY_OLDA && !VX1000_STIM */

#if defined(VX1000_TARGET_TRICORE)

#if defined(VX1000_TRICORE_RUNTIMECHECK) && (!defined(VX1000_MFCR_FE18))
#error Either define VX1000_DERIVATIVE_CLASS correctly (prefered method) or for automatic evaluation (slow!) provide callback/macro VX1000_MFCR_FE18() performing a "mfcr %d2, 0xFE18" machine instruction!
#elif !defined(VX1000_TRICORE_RUNTIMECHECK) /* VX1000_TRICORE_RUNTIMECHECK is only used internally by the AppDriver as workaround for generic device-agnostic testkernels, it is never set by the user! */
/* As it is valid for the user to specify in rare cases runtime code like ((SFR_x == y)? VX1000_DERIVATIVE_TC3XX : VX1000_DERIVATIVE_TC2XX) we do not throw preprocessor #error for VX1000_DERIVATIVE_CLASS settings other than "VX1000_DERIVATIVE_TC1XXX"/"VX1000_DERIVATIVE_TC2XX"/"VX1000_DERIVATIVE_TC3XX"/"VX1000_DERIVATIVE_TC4XX" */
#endif /* !VX1000_TRICORE_RUNTIMECHECK */

#if defined(VX1000_STIM) && (!defined(VX1000_STIM_BY_OLDA))
#if (0==(VX1000_MEMSYNC_TRIGGER_COUNT))
#error On TriCore, VX1000_STIM cannot be enabled while VX1000_STIM_BY_OLDA is disabled!
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#endif /* VX1000_STIM && !VX1000_STIM_BY_OLDA */

#if (!defined(VX1000_OLDA)) && (!defined(VX1000_DISABLE_INSTRUMENTATION))
#error On TriCore, VX1000_OLDA must be always enabled!
#endif /* !VX1000_OLDA && !VX1000_DISABLE_INSTRUMENTATION */

#if (defined(VX1000_CURRENT_CORE_IDX_NOT_DEF)) && (defined(VX1000_RUNNING_ON_MAINCORE) || defined(VX1000_COMPILED_FOR_SLAVECORES))
#error On TriCore multicore systems, callback VX1000_CURRENT_CORE_IDX() must be provided!
#endif /* VX1000_CURRENT_CORE_IDX_NOT_DEF && (VX1000_RUNNING_ON_MAINCORE || VX1000_COMPILED_FOR_SLAVECORES) */

#endif /* VX1000_TARGET_TRICORE */

#if defined(VX1000_TARGET_SH2)

#if defined(VX1000_STIM) && (!defined(VX1000_STIM_BY_OLDA))
#if (0==(VX1000_MEMSYNC_TRIGGER_COUNT))
#error On SH2, VX1000_STIM cannot be enabled while VX1000_STIM_BY_OLDA is disabled!
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#endif /* VX1000_STIM && !VX1000_STIM_BY_OLDA */

#if (!defined(VX1000_OLDA)) && (!defined(VX1000_DISABLE_INSTRUMENTATION))
#error On SH2, VX1000_OLDA must be always enabled!
#endif /* !VX1000_OLDA && !VX1000_DISABLE_INSTRUMENTATION */

#endif /* VX1000_TARGET_SH2 */

#if defined(VX1000_TARGET_TMS570)

#if defined(VX1000_STIM_BY_OLDA)
#error On TMS570, VX1000_STIM_BY_OLDA must be always disabled!
#endif /* VX1000_STIM_BY_OLDA */

#if defined(VX1000_OLDA)
#error On TMS570, VX1000_OLDA must be always disabled!
#endif /* VX1000_OLDA */

#endif /* VX1000_TARGET_TMS570 */

#if defined(VX1000_TARGET_XC2000)

#if defined(VX1000_STIM) && (!defined(VX1000_STIM_BY_OLDA))
#if (0==(VX1000_MEMSYNC_TRIGGER_COUNT))
#error On XC2000, VX1000_STIM cannot be enabled while VX1000_STIM_BY_OLDA is disabled!
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#endif /* VX1000_STIM && !VX1000_STIM_BY_OLDA */
#endif /* VX1000_TARGET_XC2000 */

#if defined(VX1000_OLDA_EVENT_COUNT)
#if (VX1000_OLDA_EVENT_COUNT) != (VX1000_OLDA_ACTIVE_EVT_CNT_MAX)
#error Please configure VX1000_OLDA_ACTIVE_EVT_CNT_MAX instead of VX1000_OLDA_EVENT_COUNT (define has been renamed)!
#endif /* VX1000_OLDA_EVENT_COUNT != VX1000_OLDA_ACTIVE_EVT_CNT_MAX */
#else /* !VX1000_OLDA_EVENT_COUNT */
#define VX1000_OLDA_EVENT_COUNT        (VX1000_OLDA_ACTIVE_EVT_CNT_MAX)
#endif /* !VX1000_OLDA_EVENT_COUNT */

/* To save memory, the number range for STIM events may be reduced */
#if !defined(VX1000_STIM_EVENT_COUNT)
#define VX1000_STIM_EVENT_COUNT        31U   /* Count of STIM events used starting from VX1000_STIM_EVENT_OFFSET */
#elif (VX1000_STIM_EVENT_COUNT > 31U) && (!defined(VX1000_OLDA_EVENT_COUNT))
#error "VX1000_STIM_EVENT_COUNT must be <= 31U"
#elif defined(VX1000_OLDA_EVENT_COUNT)
#if (VX1000_STIM_EVENT_COUNT > VX1000_OLDA_EVENT_COUNT)
#error "VX1000_STIM_EVENT_COUNT must be <= VX1000_OLDA_EVENT_COUNT"
#endif /* VX1000_STIM_EVENT_COUNT > VX1000_OLDA_EVENT_COUNT */
#if (VX1000_STIM_EVENT_COUNT > 255U)
#error "VX1000_STIM_EVENT_COUNT must be <= 255U"
#endif /* VX1000_STIM_EVENT_COUNT > 255 */
#endif /* VX1000_STIM_EVENT_COUNT && VX1000_STIM_EVENT_COUNT > 31 */

#if !defined(VX1000_STIM_EVENT_OFFSET)
#define VX1000_STIM_EVENT_OFFSET       0U   /* Number of the first STIM event */
#elif (VX1000_STIM_EVENT_OFFSET > 30U) && (!defined(VX1000_OLDA_EVENT_COUNT))
#error "VX1000_STIM_EVENT_OFFSET <= 30U!"
#elif defined(VX1000_OLDA_EVENT_COUNT)
#if ((VX1000_STIM_EVENT_OFFSET + VX1000_STIM_EVENT_COUNT) > VX1000_OLDA_EVENT_COUNT)
#error "VX1000_STIM_EVENT_OFFSET must be <= VX1000_OLDA_EVENT_COUNT - VX1000_STIM_EVENT_COUNT"
#endif /* VX1000_STIM_EVENT_OFFSET + VX1000_STIM_EVENT_COUNT > VX1000_OLDA_EVENT_COUNT */
#if ((VX1000_STIM_EVENT_OFFSET + VX1000_STIM_EVENT_COUNT) > 255U)
#error "VX1000_STIM_EVENT_OFFSET must be <= 255U - VX1000_STIM_EVENT_COUNT"
#endif /* VX1000_STIM_EVENT_OFFSET + VX1000_STIM_EVENT_COUNT > 255 */
#endif /* VX1000_STIM_EVENT_OFFSET && VX1000_STIM_EVENT_OFFSET > 30 */

#if defined(VX1000_COMBINE_TIMESTAMP_EVENT) && (!defined(VX1000_STORE64))
#error "VX1000_COMBINE_TIMESTAMP_EVENT must NOT be defined unless the VX1000_STORE64() callback is provided!"
#endif /* VX1000_COMBINE_TIMESTAMP_EVENT && !VX1000_STORE64 */

#if (VX1000_MEMSYNC_TRIGGER_COUNT > 0U) && (!defined(VX1000_STORE64))
#error "VX1000_MEMSYNC_TRIGGER_COUNT must NOT be defined > 0U unless the VX1000_STORE64() callback is provided!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT && !VX1000_STORE64 */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 1U) && defined(VX1000_MEMSYNC_TRIGGER_PTR)
#error "VX1000_MEMSYNC_TRIGGER_PTR must NOT be defined by the user when VX1000_MEMSYNC_TRIGGER_COUNT > 1"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTR */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 1U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR0))
#error "VX1000_MEMSYNC_TRIGGER_PTR0 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 1U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR1))
#error "VX1000_MEMSYNC_TRIGGER_PTR1 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 2U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR2))
#error "VX1000_MEMSYNC_TRIGGER_PTR2 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 3U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR3))
#error "VX1000_MEMSYNC_TRIGGER_PTR3 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 4U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR4))
#error "VX1000_MEMSYNC_TRIGGER_PTR4 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 5U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR5))
#error "VX1000_MEMSYNC_TRIGGER_PTR5 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 6U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR6))
#error "VX1000_MEMSYNC_TRIGGER_PTR6 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 7U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR7))
#error "VX1000_MEMSYNC_TRIGGER_PTR7 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 8U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR8))
#error "VX1000_MEMSYNC_TRIGGER_PTR8 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 9U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR9))
#error "VX1000_MEMSYNC_TRIGGER_PTR9 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 10U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR10))
#error "VX1000_MEMSYNC_TRIGGER_PTR10 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 11U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR11))
#error "VX1000_MEMSYNC_TRIGGER_PTR11 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 12U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR12))
#error "VX1000_MEMSYNC_TRIGGER_PTR12 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 13U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR13))
#error "VX1000_MEMSYNC_TRIGGER_PTR13 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 14U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR14))
#error "VX1000_MEMSYNC_TRIGGER_PTR14 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 15U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR15))
#error "VX1000_MEMSYNC_TRIGGER_PTR15 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 16U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR16))
#error "VX1000_MEMSYNC_TRIGGER_PTR16 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 17U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR17))
#error "VX1000_MEMSYNC_TRIGGER_PTR17 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 18U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR18))
#error "VX1000_MEMSYNC_TRIGGER_PTR18 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 19U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR19))
#error "VX1000_MEMSYNC_TRIGGER_PTR19 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 20U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR20))
#error "VX1000_MEMSYNC_TRIGGER_PTR20 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 21U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR21))
#error "VX1000_MEMSYNC_TRIGGER_PTR21 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 22U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR22))
#error "VX1000_MEMSYNC_TRIGGER_PTR22 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 23U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR23))
#error "VX1000_MEMSYNC_TRIGGER_PTR23 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 24U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR24))
#error "VX1000_MEMSYNC_TRIGGER_PTR24 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 25U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR25))
#error "VX1000_MEMSYNC_TRIGGER_PTR25 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 26U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR26))
#error "VX1000_MEMSYNC_TRIGGER_PTR26 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 27U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR27))
#error "VX1000_MEMSYNC_TRIGGER_PTR27 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 28U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR28))
#error "VX1000_MEMSYNC_TRIGGER_PTR28 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 29U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR29))
#error "VX1000_MEMSYNC_TRIGGER_PTR29 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 30U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR30))
#error "VX1000_MEMSYNC_TRIGGER_PTR30 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 31U) && (!defined(VX1000_MEMSYNC_TRIGGER_PTR31))
#error "VX1000_MEMSYNC_TRIGGER_PTR31 must be provided and point to 64 bytes unused RAM!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT vs. VX1000_MEMSYNC_TRIGGER_PTRx */
#if (VX1000_MEMSYNC_TRIGGER_COUNT > 32U)
#error "VX1000_MEMSYNC_TRIGGER_COUNT configured too big (max. 32 is allowed)!"
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT > 7 */

#if defined(VX1000_ENABLE_RADAR_API) && (!defined(VX1000_UINT64_T))
#error VX1000_ENABLE_RADAR_API cannot be enabled while A_UINT64 / VX1000_UINT64 is not provided!
#endif /* VX1000_ENABLE_RADAR_API && !VX1000_UINT64_T */

#if defined(VX1000_HOOK_BASED_BYPASSING) && (!defined(VX1000_STIM_BY_OLDA))
#error VX1000_HOOK_BASED_BYPASSING cannot be enabled while VX1000_STIM_BY_OLDA is disabled!
#endif /* VX1000_HOOK_BASED_BYPASSING && !VX1000_STIM_BY_OLDA */

#if defined(VX1000_HOOK_BASED_BYPASSING) && (!defined(VX1000_BYPASS_HBB_LUT_ENTRIES))
#error VX1000_BYPASS_HBB_LUT_ENTRIES must be defined to a value >0 if VX1000_HOOK_BASED_BYPASSING shall be used!
#endif /* VX1000_HOOK_BASED_BYPASSING && !VX1000_BYPASS_HBB_LUT_ENTRIES */

#if defined(VX1000_HOOK_BASED_BYPASSING) && (!defined(VX1000_BYPASS_HBB_LUT_ADDR))
#error VX1000_BYPASS_HBB_LUT_ADDR must be defined if VX1000_HOOK_BASED_BYPASSING shall be used!
#endif /* VX1000_HOOK_BASED_BYPASSING && !VX1000_BYPASS_HBB_LUT_ADDR */

#if defined(VX1000_HOOK_BASED_BYPASSING) && (!defined(VX1000_STIM_FORCE_V1))
#error VX1000_HOOK_BASED_BYPASSING cannot be enabled while VX1000_STIM_FORCE_V1 is disabled!
#endif /* VX1000_HOOK_BASED_BYPASSING && !VX1000_STIM_FORCE_V1 */

#if defined(VX1000_BYPASS_ALL_CHANS_STIMD) && (!defined(VX1000_STIM_FORCE_V1))
#error VX1000_BYPASS_ALL_CHANS_STIMD cannot be enabled while VX1000_STIM_FORCE_V1 is disabled!
#endif /* VX1000_BYPASS_ALL_CHANS_STIMD && !VX1000_STIM_FORCE_V1 */

#if defined(VX1000_STIM_FORCE_V1) && (!defined(VX1000_SET_STIM_INFO))
#error VX1000_SET_STIM_INFO() must be defined properly when VX1000_STIM_FORCE_V1 is enabled!
#endif /* VX1000_STIM_FORCE_V1 && !VX1000_SET_STIM_INFO */

#if defined(VX1000_OVERLAY)

#if defined(VX1000_OVL_INVALIDATE_CACHE_CB)
#define VX1000_OVLENBL_INVALIDATE_CACHE
#endif /* VX1000_OVL_INVALIDATE_CACHE_CB */

#if defined(VX1000_OVERLAY_USER_MANAGED) || ((defined(VX1000_INIT_CAL_PAGE) && defined(VX1000_GET_CAL_PAGE)) && (defined(VX1000_SET_CAL_PAGE) && defined(VX1000_COPY_CAL_PAGE)))
#define VX1000_OVERLAY_USERMANAGED
#endif /* VX1000_INIT_CAL_PAGE && VX1000_GET_CAL_PAGE && VX1000_SET_CAL_PAGE && VX1000_COPY_CAL_PAGE */

#if defined(VX1000_OVERLAY_USER_MANAGED) && ((defined(VX1000_INIT_CAL_PAGE) || defined(VX1000_GET_CAL_PAGE)) || (defined(VX1000_SET_CAL_PAGE) || defined(VX1000_COPY_CAL_PAGE)))
/* well, we don't throw an error to allow migrators to leave the callbacks defined so they are still available for the user to call them now manually */
#endif /* VX1000_OVERLAY_USER_MANAGED && (VX1000_INIT_CAL_PAGE || VX1000_GET_CAL_PAGE || VX1000_SET_CAL_PAGE || VX1000_COPY_CAL_PAGE) */

#if ((defined(VX1000_OVLENBL_SYNC_PAGESWITCH) || defined(VX1000_OVLENBL_CORE_SYNC_PAGESW)) && defined(VX1000_OVERLAY_USERMANAGED))
#error User-defined overlay handling callbacks cannot be used in conjunction with VX1000_OVLENBL_SYNC_PAGESWITCH / VX1000_OVLENBL_CORE_SYNC_PAGESW
#endif /* (VX1000_OVLENBL_SYNC_PAGESWITCH || VX1000_OVLENBL_CORE_SYNC_PAGESW) && VX1000_OVERLAY_USERMANAGED */

#if defined(VX1000_OVERLAY_VX_CONFIGURABLE) && (defined(VX1000_OVERLAY_USERMANAGED))
#error VX1000_xxx_CAL_PAGE() user callbacks will NOT be executed because VX1000_OVERLAY_VX_CONFIGURABLE is enabled
#endif /* VX1000_OVERLAY_VX_CONFIGURABLE & VX1000_OVERLAY_USERMANAGED */

#if defined(VX1000_TARGET_POWERPC)

#if defined(VX1000_OVERLAY_VX_CONFIGURABLE) && (defined(VX1000_OVERLAY_TLB) || defined(VX1000_OVERLAY_DESCR_IDX))
#error VX1000_OVERLAY_VX_CONFIGURABLE cannot be enabled while VX1000_OVERLAY_TLB or VX1000_OVERLAY_DESCR_IDX is enabled
#endif /* VX1000_OVERLAY_VX_CONFIGURABLE && (VX1000_OVERLAY_TLB || VX1000_OVERLAY_DESCR_IDX) */

#if defined(VX1000_OVERLAY_USERMANAGED) && defined(VX1000_OVERLAY_TLB)
#error VX1000_xxx_CAL_PAGE() user callbacks will NOT be executed because VX1000_OVERLAY_TLB is enabled
#endif /* VX1000_OVERLAY_USERMANAGED & VX1000_OVERLAY_TLB */

#if defined(VX1000_OVERLAY_USERMANAGED) && (defined(VX1000_OVERLAY_DESCR_IDX))
#error VX1000_xxx_CAL_PAGE() user callbacks will NOT be executed because VX1000_OVERLAY_DESCR_IDX is enabled
#endif /* VX1000_OVERLAY_USERMANAGED & VX1000_OVERLAY_DESCR_IDX */

#if (((!defined(VX1000_OVERLAY_TLB)) && (!defined(VX1000_OVERLAY_DESCR_IDX))) && ((!defined(VX1000_MPC56xCRAM_BASE_ADDR)) && (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)))) && (!defined(VX1000_OVERLAY_USERMANAGED))
#error To use VX1000_OVERLAY, configure VX1000_MPC56xCRAM_BASE_ADDR, VX1000_OVERLAY_TLB, VX1000_OVERLAY_DESCR_IDX or VX1000_OVERLAY_VX_CONFIGURABLE or all VX1000_xxx_CAL_PAGE() macros in VX1000_cfg.h !
#endif /* !VX1000_OVERLAY_TLB & !VX1000_OVERLAY_DESCR_IDX & !VX1000_MPC56xCRAM_BASE_ADDR & !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */

#endif /* VX1000_TARGET_POWERPC */

#if defined(VX1000_TARGET_TRICORE)

#if defined(VX1000_OVERLAY_VX_CONFIGURABLE) && (defined(VX1000_OVERLAY_DESCR_IDX))
#error VX1000_OVERLAY_VX_CONFIGURABLE cannot be enabled while VX1000_OVERLAY_DESCR_IDX is enabled
#endif /* VX1000_OVERLAY_VX_CONFIGURABLE & VX1000_OVERLAY_DESCR_IDX */

#if ( (!defined(VX1000_OVERLAY_DESCR_IDX)) && (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)) ) && (!defined(VX1000_OVERLAY_USERMANAGED))
#error To use VX1000_OVERLAY, configure VX1000_OVERLAY_DESCR_IDX or VX1000_OVERLAY_VX_CONFIGURABLE or all VX1000_xxx_CAL_PAGE() macros in VX1000_cfg.h !
#endif /* !VX1000_OVERLAY_DESCR_IDX && !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */

#if defined(VX1000_OVERLAY_USERMANAGED) && (defined(VX1000_OVERLAY_DESCR_IDX))
#error VX1000_xxx_CAL_PAGE() user callbacks will NOT be executed because VX1000_OVERLAY_DESCR_IDX is enabled
#endif /* VX1000_OVERLAY_USERMANAGED & VX1000_OVERLAY_DESCR_IDX */

#if defined(VX1000_HSCT_REFCLOCKPIN_USE_5V) && defined(VX1000_HSCT_REFCLOCKPIN_USE_3V3)
#error VX1000_HSCT_REFCLOCKPIN_USE_5V and VX1000_HSCT_REFCLOCKPIN_USE_3V3 cannot be used at the same time
#endif /* VX1000_HSCT_REFCLOCKPIN_USE_5V && VX1000_HSCT_REFCLOCKPIN_USE_3V3 */

#if defined(VX1000_HSCT_LVDSSUPPLY_IS_5V) && defined(VX1000_HSCT_LVDSSUPPLY_IS_3V3)
#error VX1000_HSCT_LVDSSUPPLY_IS_5V and VX1000_HSCT_LVDSSUPPLY_IS_3V3 cannot be used at the same time
#endif /* VX1000_HSCT_LVDSSUPPLY_IS_5V && VX1000_HSCT_LVDSSUPPLY_IS_3V3 */

#endif /* VX1000_TARGET_TRICORE */

#if defined(VX1000_TARGET_SH2)

#if defined(VX1000_OVERLAY_USERMANAGED) && (defined(VX1000_SH2_FCU_BASE_ADDR))
#error VX1000_xxx_CAL_PAGE() user callbacks will NOT be executed because VX1000_SH2_FCU_BASE_ADDR is enabled
#endif /* VX1000_OVERLAY_USERMANAGED & VX1000_SH2_FCU_BASE_ADDR */

#if ( (!defined(VX1000_SH2_FCU_BASE_ADDR)) && (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)) ) && (!defined(VX1000_OVERLAY_USERMANAGED))
#error To use VX1000_OVERLAY, configure VX1000_SH2_FCU_BASE_ADDR or VX1000_OVERLAY_VX_CONFIGURABLE or all VX1000_xxx_CAL_PAGE() macros in VX1000_cfg.h !
#endif /* !VX1000_SH2_FCU_BASE_ADDR && !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */

#endif /* VX1000_TARGET_SH2 */

#if defined(VX1000_TARGET_X850)

#if (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (!defined(VX1000_OVERLAY_USERMANAGED))
#error To use VX1000_OVERLAY, configure VX1000_OVERLAY_VX_CONFIGURABLE or all VX1000_xxx_CAL_PAGE() macros in VX1000_cfg.h !
#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */

#endif /* VX1000_TARGET_X850 */

#if defined(VX1000_TARGET_TMS570)

#if (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (!defined(VX1000_OVERLAY_USERMANAGED))
#error To use VX1000_OVERLAY, configure VX1000_OVERLAY_VX_CONFIGURABLE or all VX1000_xxx_CAL_PAGE() macros in VX1000_cfg.h !
#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */

#endif /* VX1000_TARGET_TMS570 */

#if defined(VX1000_TARGET_XC2000)

#if (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (!defined(VX1000_OVERLAY_USERMANAGED))
#error To use VX1000_OVERLAY, configure VX1000_OVERLAY_VX_CONFIGURABLE or all VX1000_xxx_CAL_PAGE() macros in VX1000_cfg.h !
#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */

#endif /* VX1000_TARGET_XC2000 */

#if (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (!defined(VX1000_OVERLAY_USERMANAGED))

/* check completeness of the common settings */
#if ((!defined(VX1000_OVERLAY_ADDR)) || ((!defined(VX1000_OVERLAY_SIZE)) || (!defined(VX1000_CALRAM_ADDR))) )
#error Please define the overlay parameters VX1000_OVERLAY_SIZE, VX1000_OVERLAY_ADDR and VX1000_CALRAM_ADDR in VX1000_cfg.h !
#endif /* !VX1000_OVERLAY_ADDR | !VX1000_OVERLAY_SIZE | !VX1000_CALRAM_ADDR */

/* check completeness of the settings for the MMU method */
#if defined(VX1000_TARGET_POWERPC) && (!(defined(VX1000_SUPPORT_OLDA_ASMGNUBOOKE) || defined(VX1000_SUPPORT_OLDA_ASMGNUVLE)))
#if defined(VX1000_OVERLAY_TLB) && (!((defined(VX1000_MPC_MMU_MTMAS0) && defined(VX1000_MPC_MMU_MTMAS1)) && (defined(VX1000_MPC_MMU_MTMAS2) && defined(VX1000_MPC_MMU_MTMAS3))))
#error VX1000_MPC_MMU_MTMASxx() must be defined for your compiler in VX1000_cfg.h
#endif /* VX1000_OVERLAY_TLB && !VX1000_MPC_MMU_MTMAS** */
#if defined(VX1000_OVERLAY_TLB) && (!defined(VX1000_MPC_MMU_TLBWE))
#error VX1000_MPC_MMU_TLBWE() must be defined for your compiler in VX1000_cfg.h
#endif /* VX1000_OVERLAY_TLB && !VX1000_MPC_MMU_TLBWE */
#endif /* VX1000_TARGET_POWERPC && !VX1000_SUPPORT_OLDA_ASMGNUBOOKE && !VX1000_SUPPORT_OLDA_ASMGNUVLE */

/* check completeness of the settings for the flash port method */
#if defined(VX1000_TARGET_POWERPC) && (defined(VX1000_OVERLAY_DESCR_IDX) && (!defined(VX1000_FLASHPORTCTLR_BASE_ADDR)))
#error Please define the overlay parameter VX1000_FLASHPORTCTLR_BASE_ADDR in VX1000_cfg.h !
#endif /* VX1000_TARGET_POWERPC && VX1000_OVERLAY_DESCR_IDX && !VX1000_FLASHPORTCTLR_BASE_ADDR */

/* check completeness of the settings for the OVLY method */
#if defined(VX1000_TARGET_ARM) && (defined(VX1000_OVERLAY_DESCR_IDX) && (!defined(VX1000_OVLY_BASE_ADDR)))
#error Please define the overlay parameter VX1000_OVLY_BASE_ADDR in VX1000_cfg.h !
#endif /* VX1000_TARGET_ARM && VX1000_OVERLAY_DESCR_IDX && !VX1000_OVLY_BASE_ADDR */

#if defined(VX1000_TARGET_XC2000)

/* check completeness of the common settings */
#if ((!defined(VX1000_OVERLAY_ADDR)) || (!defined(VX1000_OVERLAY_SIZE)) || (!defined(VX1000_CALRAM_ADDR)) )
#error Please define the overlay parameters VX1000_OVERLAY_SIZE, VX1000_OVERLAY_ADDR and VX1000_CALRAM_ADDR in VX1000_cfg.h !
#endif /* !VX1000_OVERLAY_ADDR | !VX1000_OVERLAY_SIZE | !VX1000_CALRAM_ADDR */

#endif /* VX1000_TARGET_XC2000 */

#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */

#endif /* VX1000_OVERLAY */

#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS) && (!defined(VX1000_OVLENBL_VALIDATE_PAGESW))
#error VX1000_OVLENBL_USE_VX_EPK_TRANS cannot be enabled while VX1000_OVLENBL_VALIDATE_PAGESW is disabled!
#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS & !VX1000_OVLENBL_VALIDATE_PAGESW */

#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS) && (!defined(VX1000_SYNCAL_VALIDATE_WP_CB))
#error VX1000_SYNCAL_VALIDATE_WP_CB must be configured to be able to use the EPK translation!
#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS & !VX1000_OVLENBL_USE_VX_EPK_TRANS */

#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS) && (!defined(VX1000_OVL_EPK_REFPAGE_ADDR))
#error VX1000_OVL_EPK_REFPAGE_ADDR must be configured to be able to use the EPK translation!
#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS & !VX1000_OVL_EPK_REFPAGE_ADDR */

#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS) && (!defined(VX1000_OVL_EPK_LENGTH))
#error VX1000_OVL_EPK_LENGTH must be configured to be able to use the EPK translation!
#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS & !VX1000_OVL_EPK_LENGTH */

#if defined(VX1000_OVLENBL_VALIDATE_PAGESW) && (!(defined(VX1000_SYNCAL_USRVALIDATE_WP_CB) || defined(VX1000_OVLENBL_USE_VX_EPK_TRANS)))
#error VX1000_OVLENBL_VALIDATE_PAGESW cannot be enabled while neither VX1000_SYNCAL_USRVALIDATE_WP_CB nor EPK translation are configured!
#endif /* VX1000_OVLENBL_VALIDATE_PAGESW & !VX1000_SYNCAL_USRVALIDATE_WP_CB & !VX1000_OVLENBL_USE_VX_EPK_TRANS */

#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW) && (!defined(VX1000_OVL_CAL_BUS_MASTER))
#error VX1000_OVLENBL_CORE_SYNC_PAGESW cannot be enabled while VX1000_OVL_CAL_BUS_MASTER is not configured!
#endif /* VX1000_OVLENBL_CORE_SYNC_PAGESW & !VX1000_OVL_CAL_BUS_MASTER */

#if defined(VX1000_SUPPRESS_LEGACY_API) && (defined(VX1000_OVLENBL_CORE_SYNC_PAGESW) && (!defined(VX1000_OVL_CAL_BUS_MASTER_0)))
#error VX1000_OVLENBL_CORE_SYNC_PAGESW cannot be enabled while VX1000_OVL_CAL_BUS_MASTER_x is not configured!
#endif /* VX1000_SUPPRESS_LEGACY_API & VX1000_OVLENBL_CORE_SYNC_PAGESW & !VX1000_OVL_CAL_BUS_MASTER_0 */

#if defined(VX1000_OVLENBL_SYNC_PAGESWITCH) && (!defined(VX1000_OVL_CAL_BUS_MASTER))
#error VX1000_OVLENBL_SYNC_PAGESWITCH cannot be enabled while VX1000_OVL_CAL_BUS_MASTER is not configured!
#endif /* VX1000_OVLENBL_SYNC_PAGESWITCH & !VX1000_OVL_CAL_BUS_MASTER */

#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW) && (!defined(VX1000_OVLENBL_SYNC_PAGESWITCH))
#error VX1000_OVLENBL_CORE_SYNC_PAGESW cannot be used without VX1000_OVLENBL_SYNC_PAGESWITCH!
#endif /* VX1000_OVLENBL_CORE_SYNC_PAGESW & !VX1000_OVLENBL_SYNC_PAGESWITCH */

#if defined(VX1000_OVLENBL_RST_ON_CALWAKEUP) && (!defined(VX1000_OVL_RST_ON_CAL_WAKEUP_CB))
#error VX1000_OVL_RST_ON_CAL_WAKEUP_CB() must be configured because VX1000_OVLENBL_RST_ON_CALWAKEUP is enabled!
#endif /* VX1000_OVLENBL_RST_ON_CALWAKEUP & !VX1000_OVL_RST_ON_CAL_WAKEUP_CB */

#if defined(VX1000_MAILBOX) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#if (VX1000_MAILBOX_SLOT_DWORDS) < 3U
#error VX1000_MAILBOX_SLOT_DWORDS must be at least 3 ! /* 4 bytes + 8 bytes xcp command = 12bytes = 3 dwords */
#endif /* VX1000_MAILBOX_SLOT_DWORDS */
#if (VX1000_MAILBOX_SLOTS < 2U) || (((VX1000_MAILBOX_SLOTS) & ((VX1000_MAILBOX_SLOTS) - 1U)) != 0U)
#error VX1000_MAILBOX_SLOTS must be at least 2 and be a power of 2!
#endif /* VX1000_MAILBOX_SLOTS */
#endif /* VX1000_MAILBOX & ! VX1000_COMPILED_FOR_SLAVECORES */

#if (!defined(VX1000_MEMSYNC_TRIGGER_COUNT)) || ((VX1000_MEMSYNC_TRIGGER_COUNT) == 0U)
#if defined(VX1000_MEMSYNC_COPY_COUNT)
#if ((VX1000_MEMSYNC_COPY_COUNT) > 0U)
#error VX1000_MEMSYNC_COPY_COUNT cannot be defined > 0 unless VX1000_MEMSYNC_TRIGGER_COUNT is defined > 0, too!
#endif /* VX1000_MEMSYNC_COPY_COUNT > 0*/
#endif /* VX1000_MEMSYNC_COPY_COUNT */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */

#if defined(VX1000_OLDA_BENCHMARK)
#if ((VX1000_OLDA_BENCHMARK_CNT) == 0U)
#error VX1000_OLDA_BENCHMARK_CNT must be defined greater than zero when VX1000_OLDA_BENCHMARK is enabled!
#endif /* !VX1000_OLDA_BENCHMARK_CNT */
#endif /* VX1000_OLDA_BENCHMARK */

#if defined(VX1000_LFAST_BASEADDR) && (!defined(VX1000_SIPI_CLK_TXN_TXP_RXN_RXP))
#error Please define VX1000_SIPI_CLK_TXN_TXP_RXN_RXP() to C code that enables the 5 LFAST pins as clock out plus 2 LVDS pairs.
#endif /* VX1000_LFAST_BASEADDR & !VX1000_SIPI_CLK_TXN_TXP_RXN_RXP */

#if defined(VX1000_DETECTION) || defined(VX1000_TARGET_TRICORE) /* on TriCore, this functionality is always present because it is needed in DAP initialisation decision */
#if defined(VX1000_COLDSTART_CALIBRATION)
#if !defined(VX1000_OLDA_MEMORY_SIZE)
#error VX1000_COLDSTART_CALIBRATION is enabled while VX1000_OLDA_MEMORY_SIZE is undefined
#elif ((VX1000_OLDA_MEMORY_SIZE) == 0)
#error VX1000_COLDSTART_CALIBRATION is enabled while VX1000_OLDA_MEMORY_SIZE is set to zero
#endif /* !VX1000_OLDA_MEMORY_SIZE */
#if !defined(VX1000_COLDSTART_FLASH_SIZE)
#error VX1000_COLDSTART_CALIBRATION is enabled while VX1000_COLDSTART_FLASH_SIZE is undefined
#elif ((VX1000_COLDSTART_FLASH_SIZE) == 0)
#error VX1000_COLDSTART_CALIBRATION is enabled while VX1000_COLDSTART_FLASH_SIZE is set to zero
#endif /* !VX1000_COLDSTART_FLASH_SIZE */
#if !defined(VX1000_COLDSTART_CHS_BLOCK_SIZE)
#error VX1000_COLDSTART_CALIBRATION is enabled while VX1000_COLDSTART_CHS_BLOCK_SIZE is undefined
#elif ((VX1000_COLDSTART_CHS_BLOCK_SIZE) == 0)
#error VX1000_COLDSTART_CALIBRATION is enabled while VX1000_COLDSTART_CHS_BLOCK_SIZE is set to zero
#endif /* !VX1000_COLDSTART_CHS_BLOCK_SIZE */
#if (VX1000_OLDA_MEMORY_SIZE) < (((VX1000_COLDSTART_FLASH_SIZE) / (VX1000_COLDSTART_CHS_BLOCK_SIZE)) + 4) * 4
#error VX1000_MEMORY_SIZE too small for FLASH checksum array
#endif /* VX1000_OLDA_MEMORY_SIZE < ... */
#if ((VX1000_COLDSTART_FLASH_SIZE) % (VX1000_COLDSTART_CHS_BLOCK_SIZE)) != 0
#error VX1000_COLDSTART_FLASH_SIZE % VX1000_COLDSTART_CHS_BLOCK_SIZE != 0
#endif /* VX1000_COLDSTART_FLASH_SIZE % VX1000_COLDSTART_CHS_BLOCK_SIZE */
#endif /* VX1000_COLDSTART_CALIBRATION */
#endif /* VX1000_DETECTION || VX1000_TARGET_TRICORE */

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

/* States */

/* ToolDetectState */
#define VX1000_TDS_INIT                0x00000001UL /* VX1000_INIT() has been called */
#define VX1000_TDS_DETECT              0x00000002UL /* VX1000_DETECT_VX() has been called */
#define VX1000_TDS_DETECTED            0x00000004UL /* VX1000 was detected by VX1000_DETECT_VX() */
#define VX1000_TDS_COLDSTART_DELAY_REQ 0x00000008UL /* Coldstart delay request has been accepted by VX */
#define VX1000_TDS_COLDSTART_DONE      0x00000010UL /* Coldstart handshake successfully executed */
#define VX1000_TDS_COLDSTART_TIMEOUT   0x00000020UL /* Coldstart handshake resulted in timeout */
#define VX1000_TDS_COLDSTART_DELAY     0x00000040UL /* Coldstart delay has been entered */
#define VX1000_TDS_APPRST              0x00000080UL /* Resume after application reset done */
#define VX1000_TDS_FKL_REQ_DETECTED    0x00000100UL /* FlashPrepare request detected: trying to handle it */
#define VX1000_TDS_FKL_REQ_IGNORED     0x00000200UL /* FlashPrepare request could not be served right now; app still runs */
#define VX1000_TDS_FKL_FORCED_IDLE     0x00000400UL /* Request served: ECU stays idle; FKL can be downloaded by the tool -> gVX1000.MagicId contains a pointer to the new communication space. */
#define VX1000_TDS_DETECT_DONE         0x00000800UL /* VX1000 Tooldetection sequence finished */
#define VX1000_TDS_ERROR               0x00001000UL /* VX1000_INIT() detected a misconfiguration */
#define VX1000_TDS_VX_ACCESS_DISABLED  0x00002000UL /* The VX has NO access to the ECU, another tool is connected (no resources shall be wasted for ANY feature) */
#define VX1000_TDS_WORKING_PAGE        0x00004000UL /* 0: ECU is on reference page / 1: ECU is on working page */
#define VX1000_TDS_DEALLOCATE_CAL_RES  0x00008000UL /* Inform VX1000 that the app wants the VX to switch to default page and free the overlay resources */
#define VX1000_TDS_COLDSTART_CHS_BUSY  0x00010000UL /* Unused new feature of release 1.6: Coldstart checksum calculation ongoing, replaced by external validation (see VX1000_TCS_SKIP_WP_INIT) */
#define VX1000_TDS_COLDSTART_CHS_DONE  0x00020000UL /* Unused new feature of release 1.6: Coldstart checksum calculation done, replaced by external validation (see VX1000_TCS_SKIP_WP_INIT) */
#define VX1000_TDS_NO_BYP_RESUME       0x00040000UL /* Inform VX1000 not to resume VX bypassing */
#define VX1000_TDS_FEAT_TIMEOUT_TRC    0x00080000UL /* Inform VX1000 that ECU felt that the activation of TRC feature took too long and that app will no longer try to use that feature */
#define VX1000_TDS_RESERVED_FOR_ASAM   0x7FF00000UL /* Already used by FW for ASAM features (recently shifted one position upwards and available for "repurposing after discussion") */
#define VX1000_TDS_UNUSED_BITS         0x80000000UL /* unused */

/* ToolCtrlState */
#define VX1000_TCS_PRESENT             0x00000001UL /* VX1000 is present */
#define VX1000_TCS_COLDSTART_DELAY     0x00000002UL /* VX1000 requests coldstart delay */
#define VX1000_TCS_COLDSTART_DONE      0x00000004UL /* VX1000 coldstart configuration done (== ALL features ready for use) */
#define VX1000_TCS_FKL_REQUEST         0x00000008UL /* VX1000 requests the appl to go idle and prepare to jump to a pointer */
#define VX1000_TCS_SOFTRESET_PREP      0x00000010UL /* VX1000 acknowledges a soft-reset announcement */
#define VX1000_TCS_SWITCH_TO_WP        0x00000020UL /* Tell the ECU to switch to WP */
#define VX1000_TCS_CAL_WAKEUP          0x00000040UL /* The VX1000 has woken up the ECU */
#define VX1000_TCS_SKIP_WP_INIT        0x00000080UL /* Inform the ECU that the WP's RAM content is still intact */
#define VX1000_TCS_FEAT_DONE_TRC       0x00000100UL /* Inform the ECU that the TRC feature is ready for use */
#define VX1000_TCS_RESERVED_FOR_ASAM   0x00007E00UL /* Already used by FW for ASAM features (recently shifted one position upwards) */
#define VX1000_TCS_UNUSED_BITS         0xFFFF8000UL /* unused */

/* Feature status */
#define VX1000_FEATURE_CAL             0x00000001UL /* ASAM standardised bit (but still reserved at Vector for future abuse) */
#define VX1000_FEATURE_DBG             0x00000002UL /* ASAM standardised bit (but still reserved at Vector for future abuse) */
#define VX1000_FEATURE_DAQ             0x00000004UL /* ASAM standardised bit (but still reserved at Vector for future abuse) */
#define VX1000_FEATURE_STIM            0x00000008UL /* ASAM standardised bit (but still reserved at Vector for future abuse) */
#define VX1000_FEATURE_PGM             0x00000010UL /* ASAM standardised bit (but still reserved at Vector for future abuse) */
#define VX1000_FEATURE_TRACE           0x80000000UL /* Vector-proprietary (used) bit */

/* Extensions for 4.6 and 4.7 */
#define VX1000_DAQ_FW_INFO_VERSION     1U
#define VX1000_DAQ_TYPE_UNDEF          0x00000000UL
#define VX1000_DAQ_TYPE_RADARRAWDATA   0x01000000UL
#define VX1000_DAQ_TYPE_XCP            0x02000000UL
#define VX1000_DAQ_TYPE_CMP            0x03000000UL
#define VX1000_DAQ_STATUS_UNKNOWN      0U /* AKA: "VX1000_DAQ_STATUS_UNKOWN" */
#define VX1000_DAQ_STATUS_STARTED      1U
#define VX1000_DAQ_STATUS_STOPPED      2U
#define VX1000_DAQ_STATUS_RESERVED     0xFFU
#define VX1000_PCIE_FW_INFO_VERSION    0U
#define VX1000_LINK_TYPE_PCIE          1U
#define VX1000_LINK_STATUS_UP          1U
#define VX1000_LINK_STATUS_DOWN        2U
#define VX1000_ERRTYPE_OK               ((VX1000_UINT8)0U)
#define VX1000_ERRTYPE_GENERIC          ((VX1000_UINT8)1U) /* AKA: "VX1000_ERROR_TYPE_GENERIC" */
#define VX1000_ERRTYPE_OVERLOAD_GENERIC ((VX1000_UINT8)2U) /* AKA: "VX1000_ERROR_TYPE_OVERLOAD_GENERIC" */
#define VX1000_ERRTYPE_OVERLOAD_MEMORY  ((VX1000_UINT8)3U) /* AKA: "VX1000_ERROR_TYPE_OVERLOAD_MEMORY" */
#define VX1000_ERRTYPE_WILLFUL_ABORT    ((VX1000_UINT8)4U) /* AKA: "VX1000_ERROR_TYPE_WILLFUL_ABORT" */
#define VX1000_TYPE_CO_STATUS_IDLE      0x00UL /* copy offloader is idling and ready to accept new jobs */
#define VX1000_TYPE_CO_STATUS_COPY      0x01UL /* copy offloader is still busy and cannot be stopped until the entire transaction has finished */
#define VX1000_TYPE_CO_STATUS_ERROR     0x02UL /* copy offloader is in an error state and probably cannot be started */
#define VX1000_TYPE_CO_STATUS_FWCLEARED 0xFFUL /* the FW has seen the status and acknowledged it by overwriting it with this clear pattern */
#if defined(VX1000_ENABLE_RADAR_API)
#if defined(VX1000_UINT64)
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_DataTransferStart)(VX1000_UINT32 DtsTransferType, VX1000_UINT64 DtsTime64, VX1000_UINT32 DtsAddr, VX1000_UINT32 DtsBytes);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_UINT64 */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_DataTransferFinish)(VX1000_UINT32 DtfTransferType);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_DataTransferGetInfo)(VX1000_UINT32 DtgTransferType, VX1000_UINT32 *pDtgDstAddress, VX1000_UINT32 *pDtgDstMode);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_NotificationLinkChange)(VX1000_UINT8 NlcLinktype, VX1000_UINT8 NlcLinkstatus);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_NotificationError)(VX1000_UINT8 NeOlInstance, VX1000_UINT32 NeDaqType, VX1000_UINT8 NeErrorType);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_ENABLE_RADAR_API */
#if defined(VX1000_ENABLE_RADAR_API) || defined(VX1000_ENABLE_DAQ_STATUS_API)
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_DaqGetStatus)(VX1000_UINT32 DgsDaqType, VX1000_UINT8* pDgsDaqStatus);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_ENABLE_RADAR_API || VX1000_ENABLE_DAQ_STATUS_API */


/*------------------------------------------------------------------------------ */
/* VX1000 Detection                                                              */

#if defined(VX1000_DETECTION) || (defined(VX1000_TARGET_TRICORE) && (!defined(VX1000_DISABLE_INSTRUMENTATION)))
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_Detected)(void);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_DETECTION || (VX1000_TARGET_TRICORE && !VX1000_DISABLE_INSTRUMENTATION) */


/*------------------------------------------------------------------------------ */
/* ColdStart                                                                     */

#define VX1000_COLDSTART_CHS_MAGIC     0xFEC70A09UL
#if (defined(VX1000_DETECTION) || (defined(VX1000_TARGET_TRICORE) && (!defined(VX1000_DISABLE_INSTRUMENTATION)))) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#define VX1000_START_SEC_VAR_NOCACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#if defined(VX1000_COLDSTART_BENCHMARK)
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectStartTime;
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectStartTimeAsyncEnd;
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectToolDetectTime;
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectChecksumDoneTime;
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectEndTimeAsyncStart;
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectEndTime;
#define VX1000_COLDSTART_BENCHMARK_DATA volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectStartTime;\
                                        volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectStartTimeAsyncEnd;\
                                        volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectToolDetectTime;\
                                        volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectChecksumDoneTime;\
                                        volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectEndTimeAsyncStart;\
                                        volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectEndTime                                    /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#else /* !VX1000_COLDSTART_BENCHMARK */
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectStartTime;
#define VX1000_COLDSTART_BENCHMARK_DATA volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) vx1000_DetectStartTime                                  /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#endif /* !VX1000_COLDSTART_BENCHMARK */
#define VX1000_STOP_SEC_VAR_NOCACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#else  /* (!VX1000_DETECTION & !VX1000_TARGET_TRICORE) | VX1000_DISABLE_INSTRUMENTATION | VX1000_COMPILED_FOR_SLAVECORES */
#endif /* (!VX1000_DETECTION & !VX1000_TARGET_TRICORE) | VX1000_DISABLE_INSTRUMENTATION | VX1000_COMPILED_FOR_SLAVECORES */


/*------------------------------------------------------------------------------ */
/* Flash kernel download support                                                 */

#if !defined(VX1000_DISABLE_INSTRUMENTATION)
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_FlashPrepareLoop)(void);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_DISABLE_INSTRUMENTATION */
#if defined(VX1000_FKL_SUPPORT_ADDR)
typedef void VX1000_FKL_FCT(VX1000_UINT32 A, VX1000_UINT32 B, VX1000_UINT32 C);  /* PRQA-S-3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef struct VX1000_fkl_workspace_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 DeprotectTrigger;        /*  0+ */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 DeprotectState;          /*  2+ */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 TransitionTimeout;       /*  4+ */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 WdgData1;                /*  8+ */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 WdgData2;                /* 12+ */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 WdgData3_FklParam3;      /* 16+ */   /* it depends on the platform whether the watchdog handler or the kernel needs more parameters */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 FklParam1;               /* 20+ */
  VX1000_FKL_FCT * VX1000_INNERSTRUCT_VOLATILE EntryPoint;           /* 24+ */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 FklParam2;               /* 28+ */
} VX1000_FKL_WORKSPACE_T;                                                        /* PRQA-S-3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
#define VX1000_FKL_WORKSPACE           (VX1000_ADDR_TO_PTR2FW(  0xFFFFFFE0UL & (((VX1000_UINT32)(VX1000_FKL_SUPPORT_ADDR)))))
#define VX1000_FKL_WORKSPACE_EPASINT   ((VX1000_ADDR_TO_PTR2VU32(0xFFFFFFE0UL & (((VX1000_UINT32)(VX1000_FKL_SUPPORT_ADDR))+24UL)))[0]) /* alias of the EntryPoint member to avoid type cast warnings when invalidating or comparing the pointer */
#define VX1000_FKL_TRANSITION_TIMEOUT  0xFFFFFFFFUL
#define VX1000_FKL_STATE1CODE          0x1243U
#define VX1000_FKL_STATE2CODE          0x2486U
#define VX1000_FKL_STATE3CODE          0x36C9U
#define VX1000_FKL_STATE4CODE          0x480CU
#define VX1000_FKL_STATE5CODE          0x5A4FU
#define VX1000_FKL_TOSTATE1CODE        0x6BF0U
#define VX1000_FKL_TOSTATE2CODE        0x7A0FU
#define VX1000_FKL_TOSTATE3CODE        0x891EU
#define VX1000_FKL_TOSTATE4CODE        0x98E1U
#define VX1000_FKL_TOSTATE5CODE        0xA72DU
#define VX1000_FKL_LAUNCHCODE          0xB6D2U
#endif /* VX1000_FKL_SUPPORT_ADDR */


/*------------------------------------------------------------------------------ */
/* VX1000 Mailbox                                                                */

#define VX1000_MAILBOX_OK              0UL
#define VX1000_MAILBOX_ERR_FULL        1UL
#define VX1000_MAILBOX_ERR_EMPTY       2UL
#define VX1000_MAILBOX_ERR_INDICES     3UL
#define VX1000_MAILBOX_ERR_SEQUENCE    4UL
#define VX1000_MAILBOX_ERR_SIZE        5UL
#define VX1000_MAILBOX_SLOT_RSVD       6UL
#define VX1000_MAILBOX_ERR_NULL        7UL
#define VX1000_MAILBOX_ERR_SPLIT_PEND  8UL

#define VX1000_CRC_CMD_UNKNOWN         0x20U
#define VX1000_CRC_CMD_BUSY            0x10U
#define VX1000_CRC_CMD_SYNTAX          0x21U
#define VX1000_CRC_OUT_OF_RANGE        0x22U
#define VX1000_CRC_WRITE_PROTECTED     0x23U
#define VX1000_CRC_ACCESS_DENIED       0x24U
#define VX1000_CRC_ACCESS_LOCKED       0x25U
#define VX1000_CRC_PAGE_NOT_VALID      0x26U
#define VX1000_CRC_PAGE_MODE_NOT_VALID 0x27U
#define VX1000_CRC_SEGMENT_NOT_VALID   0x28U

#define VX1000_CAL_ECU                 0x01U
#define VX1000_CAL_XCP                 0x02U
#define VX1000_CAL_ALL                 0x80U

#if (!defined(VX1000_COMPILED_FOR_SLAVECORES)) && ((((VX1000_CO_OFFLOADER_COUNT) > 0U) || defined(VX1000_OVL_INVALIDATE_CACHE_CB)) || (defined(VX1000_DAQ_STARTED_CB) || defined(VX1000_TRIGGER_DISCOVERING_CB)))
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_NonMxMailboxActions)(void);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES && (VX1000_CO_OFFLOADER_COUNT || VX1000_OVL_INVALIDATE_CACHE_CB || VX1000_DAQ_STARTED_CB || VX1000_TRIGGER_DISCOVERING_CB) */

#if defined(VX1000_MAILBOX)
#define VX1000_MAILBOX_MAGIC           0xFEC70A06UL

typedef struct VX1000_mailbox_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  MagicIdMX;     /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  VersionMX;     /* 0x04 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16  SlotSize;      /* 0x08 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   MS_Slots;      /* 0x0A */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   SM_Slots;      /* 0x0B */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  MS_Ptr;        /* 0x0C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  SM_Ptr;        /* 0x10 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   MS_ReadIdx;    /* 0x14 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   MS_WriteIdx;   /* 0x15 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   SM_ReadIdx;    /* 0x16 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   SM_WriteIdx;   /* 0x17 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16  RstReq;        /* 0x18 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16  RstAck;        /* 0x1A */
  VX1000_INNERSTRUCT_VOLATILE VX1000_INT32   MSData[VX1000_MAILBOX_SLOTS][VX1000_MAILBOX_SLOT_DWORDS]; /* 0x1C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_INT32   SMData[VX1000_MAILBOX_SLOTS][VX1000_MAILBOX_SLOT_DWORDS]; /* no fix offset */
} VX1000_MAILBOX_T;

#define VX1000_MAILBOX_DATA            VX1000_MAILBOX_T Mailbox                                                                                                                      /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#define VX1000_MAILBOX_PTR             (VX1000_PTR2VM_TO_ADDRESS(&gVX1000.Mailbox))
#else  /* !VX1000_MAILBOX */
#define VX1000_MAILBOX_PTR             0UL
#endif /* !VX1000_MAILBOX */

#if defined(VX1000_MAILBOX) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MailboxWrite)(VX1000_UINT32 len, const volatile VX1000_CHAR VX1000_DECL_PTR * pBuf);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MailboxRead)(VX1000_UINT32 * pLen, VX1000_CHAR VX1000_DECL_PTR * pBufR);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_MAILBOX && !VX1000_COMPILED_FOR_SLAVECORES */
#if (!defined(VX1000_COMPILED_FOR_SLAVECORES)) && (defined(VX1000_MAILBOX) && ((defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH)) || defined(VX1000_MAILBOX_CAL_READ_WRITE)))
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MailboxControl)(VX1000_UINT8 aMask);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_VAR_CACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_VAR(VX1000_CHAR, VX1000_VAR_CACHE_ALIGN_4) VX1000_DECL_PTR *vx1000_tmp_MxRxPtr;
#define VX1000_STOP_SEC_VAR_CACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#if defined(VX1000_MAILBOX_CAL_READ_WRITE)
#define VX1000_START_SEC_VAR_CACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_VAR(VX1000_CHAR, VX1000_VAR_CACHE_ALIGN_4) VX1000_DECL_PTR *vx1000_tmp_MxTxPtr;
#define VX1000_STOP_SEC_VAR_CACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_MAILBOX_CAL_READ_WRITE */
#endif /* (!VX1000_COMPILED_FOR_SLAVECORES) && (VX1000_MAILBOX && (VX1000_MAILBOX_OVERLAY_CONTROL || VX1000_MAILBOX_FLASH || VX1000_MAILBOX_CAL_READ_WRITE)) */
#if (defined(VX1000_MAILBOX) && ((defined(VX1000_MAILBOX_CAL_READ_WRITE)) || (!defined(VX1000_MAILBOX_NO_SPLITWRITE)))) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MailboxWriteDone)(VX1000_UINT32 len);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MailboxWriteSplit)(VX1000_CHAR VX1000_DECL_PTR * volatile * volatile ppBuf);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_MAILBOX && (VX1000_MAILBOX_CAL_READ_WRITE || !VX1000_MAILBOX_NO_SPLITWRITE) && !VX1000_COMPILED_FOR_SLAVECORES */
#if ((defined(VX1000_MAILBOX) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))) && ((defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH)) || (defined(VX1000_MAILBOX_CAL_READ_WRITE) || (!defined(VX1000_MAILBOX_NO_SPLITREAD)))))
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MailboxReadDone)(void);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MailboxReadSplit)(volatile VX1000_UINT32 * pLenS, VX1000_CHAR VX1000_DECL_PTR * volatile * volatile ppBufR);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_MAILBOX && !VX1000_COMPILED_FOR_SLAVECORES && (VX1000_MAILBOX_OVERLAY_CONTROL || VX1000_MAILBOX_FLASH || VX1000_MAILBOX_CAL_READ_WRITE || !VX1000_MAILBOX_NO_SPLITREAD) */
#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_PRINTF)) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MailboxPrintfBackEnd)( const VX1000_CHAR *format, /*const*/ va_list arglist );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern /*lint -e(960) variadic function only available in debug builds*/VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MailboxPrintf)( const VX1000_CHAR *format, ... ); /* PRQA S 5069 */ /* Cannot avoid violating MISRA rule 16.1 because a C++-based workaround would only violate other rules */
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_VAR_CACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#if !defined(VX1000_PRINTF_MINIMAL)
extern VX1000_VAR(VX1000_CHAR, VX1000_VAR_CACHE_ALIGN_4) vx1000_PrintBuffer[256]; /* a DWORD-aligned and DWORD-padded char buffer */
#else  /* VX1000_PRINTF_MINIMAL */
extern VX1000_VAR(VX1000_CHAR, VX1000_VAR_CACHE_ALIGN_4) vx1000_PrintBuffer[24];  /* a DWORD-aligned and DWORD-padded char buffer */
#endif /* VX1000_PRINTF_MINIMAL */
#define VX1000_STOP_SEC_VAR_CACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_MAILBOX && VX1000_MAILBOX_PRINTF && !VX1000_COMPILED_FOR_SLAVECORES */

#if (defined(VX1000_OVERLAY) && (!defined(VX1000_COMPILED_FOR_SLAVECORES)))
#if (defined(VX1000_INIT_CAL_PAGE)) && (!defined(VX1000_OVERLAY_VX_CONFIGURABLE))
#endif /* VX1000_INIT_CAL_PAGE && !VX1000_OVERLAY_VX_CONFIGURABLE */
#if (!defined(VX1000_INIT_CAL_PAGE)) && (!(defined(VX1000_OVERLAY_VX_CONFIGURABLE) || defined(VX1000_OVERLAY_USER_MANAGED)))
#define VX1000_INIT_CAL_PAGE_INTERNAL
#endif /* !VX1000_INIT_CAL_PAGE & !VX1000_OVERLAY_VX_CONFIGURABLE & !VX1000_OVERLAY_USER_MANAGED */
#endif /* VX1000_OVERLAY & !VX1000_COMPILED_FOR_SLAVECORES */
#if ((!defined(VX1000_OVERLAY)) || ((defined(VX1000_COMPILED_FOR_SLAVECORES)) || defined(VX1000_OVERLAY_VX_CONFIGURABLE)))
#endif /* !VX1000_OVERLAY | VX1000_COMPILED_FOR_SLAVECORES | VX1000_OVERLAY_VX_CONFIGURABLE */
#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL)) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#if !defined(VX1000_GET_CAL_PAGE)
#define VX1000_GET_CAL_PAGE(seg, mod)  VX1000_SUFFUN(vx1000_GetCalPage)((VX1000_UINT8)(seg), (VX1000_UINT8)(mod))                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_GET_CAL_PAGE_INTERNAL
#endif /* !VX1000_GET_CAL_PAGE */
#define VX1000_WRP_SET_CAL_PAGE(seg, pag, mod, stup) VX1000_SUFFUN(vx1000_SetCalPage)((VX1000_UINT8)(seg), (VX1000_UINT8)(pag), (VX1000_UINT8)(mod), (VX1000_UINT8)(stup))           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_WRP_SET_CAL_PAGE_VOID(seg, pag, mod, stup) (void)VX1000_WRP_SET_CAL_PAGE((seg), (pag), (mod), (stup));                                                                /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#if !defined(VX1000_OVERLAY_USER_MANAGED)
#if defined(VX1000_SET_CAL_PAGE)
#define VX1000_SET_CAL_PAGE_EXTERNAL
#else /* !VX1000_SET_CAL_PAGE */
#define VX1000_SET_CAL_PAGE_INTERNAL
#endif /* !VX1000_SET_CAL_PAGE */
#endif /* !VX1000_OVERLAY_USER_MANAGED */
#else /* !VX1000_MAILBOX | !VX1000_MAILBOX_OVERLAY_CONTROL | VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_WRP_SET_CAL_PAGE( seg, pag, mod, stup) VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(VX1000_CRC_OUT_OF_RANGE), (seg), (pag), (mod), (stup)) /* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_WRP_SET_CAL_PAGE_VOID(seg, pag, mod, stup) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(VX1000_CRC_OUT_OF_RANGE), (seg), (pag), (mod), (stup)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif  /* !VX1000_MAILBOX | !VX1000_MAILBOX_OVERLAY_CONTROL | VX1000_COMPILED_FOR_SLAVECORES */
#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL)) && (((!defined(VX1000_COMPILED_FOR_SLAVECORES)) && (!defined(VX1000_OVERLAY_VX_CONFIGURABLE))) && (!defined(VX1000_OVERLAY_USER_MANAGED)))
#if !defined(VX1000_COPY_CAL_PAGE)
#define VX1000_COPY_CAL_PAGE(sseg, spag, dseg, dpag) VX1000_SUFFUN(vx1000_CopyCalPage)((VX1000_UINT8)(sseg), (VX1000_UINT8)(spag), (VX1000_UINT8)(dseg), (VX1000_UINT8)(dpag))       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_COPY_CAL_PAGE_INTERNAL
#endif /* !VX1000_COPY_CAL_PAGE */
#endif  /* VX1000_MAILBOX && VX1000_MAILBOX_OVERLAY_CONTROL && !VX1000_COMPILED_FOR_SLAVECORES && !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USER_MANAGED */


/*------------------------------------------------------------------------------ */
/* VX1000 ECU ID                                                                 */

#if !defined(VX1000_ECUID_PTR)
#if defined(VX1000_ECUID) && defined(VX1000_ECUID_LEN)
#define VX1000_START_SEC_CONST_UNSPECIFIED
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern const VX1000_VAR(VX1000_UINT8, VX1000_CONST_UNSPECIFIED) gVX1000_ECUID[(VX1000_ECUID_LEN) + 1U];
#define VX1000_STOP_SEC_CONST_UNSPECIFIED
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_ECUID_DATA              const VX1000_VAR(VX1000_UINT8, VX1000_CONST_UNSPECIFIED) gVX1000_ECUID[(VX1000_ECUID_LEN) + 1U] = VX1000_ECUID
#define VX1000_ECUID_PTR               (VX1000_PTR2CU8_TO_ADDRESS(&gVX1000_ECUID[0]))
#else /* !VX1000_ECUID || !VX1000_ECUID_LEN */
#define VX1000_ECUID_PTR               0UL
#endif /* !VX1000_ECUID || !VX1000_ECUID_LEN */
#endif /* !VX1000_ECUID_PTR */

#if !defined(VX1000_ECUID_LEN)
#define VX1000_ECUID_LEN               0U
#endif /* !VX1000_ECUID_LEN */


/*------------------------------------------------------------------------------ */
/* OLDA                                                                          */

#if defined(VX1000_OLDA)

#define VX1000_OLDA_MAGIC              0x2603U

/* bit definitions of gVX1000.Olda.OldaFeatures3: */
#define VX1000_OLDAFEAT_IPO             (0x001UL/*<<0*/)       /* bit 0: IPO events supported */
#define VX1000_OLDAFEAT_MULTIBUF        (0x001UL << 1)         /* bit 1: multibuffer events supported */
#define VX1000_OLDAFEAT_MULTIBUF_LUT    (0x001UL << 2)         /* bit 2: multibufferIpoLutAddress is valid, not used since OLDA_MULTIBUFFER_IPO_SUPPORT is always undefined  */
                                                               /* bits 7..3: 5bit enum to describe the set of available subcommands (assuming the main command is enabled):  */
#if defined(VX1000_SUPPRESS_TRACE_SUPPORT)
#define VX1000_OLDAFEAT_SUBCMD_VERSION  (0x000UL << 3)         /* version_0_set means 0x07:0x00..0x07:0x02 , 0x09:0x00..0x09:0x01 , 0x0A:0x00..0x0A:0x1F , 0x0A:0xFE..0x0A:0xFF */
#else  /* !VX1000_SUPPRESS_TRACE_SUPPORT */
#define VX1000_OLDAFEAT_SUBCMD_VERSION  (0x001UL << 3)         /* version_1_set means 0x07:0x00..0x07:0x02 , 0x09:0x00..0x09:0x01 , 0x0A:0x00..0x0A:0x1F , 0x0A:0xFE..0x0A:0xFF , 0x0B:0x00..0x0B:0x01 */
#endif /* !VX1000_SUPPRESS_TRACE_SUPPORT */
#define VX1000_OLDAFEAT_LAST            (0x100UL/*<< 0*/)      /* bit 8: LastCommand available: when this bit is set, descriptor based DAQ is unavailable, and command based DAQ must be used */
#define VX1000_OLDAFEAT_MULTICOPY32_BIG (0x100UL << 0x01)      /* bit 9: MultiCopy32LargeChunks command available */
#define VX1000_OLDAFEAT_MULTICOPY32     (0x100UL << 0x02)      /* bit 10: MultiCopy32 command available */
#define VX1000_OLDAFEAT_MULTICOPY8      (0x100UL << 0x03)      /* bit 11: MultiCopy8 command available */
#define VX1000_OLDAFEAT_MULTIMEMSYW_BIG (0x100UL << 0x04)      /* bit 12: MultiMemSyncWriteLargeChunks command available */
#define VX1000_OLDAFEAT_MULTIFIXDST_BIG (0x100UL << 0x05)      /* bit 13: MultiFixedDest32LargeChunks command available */
#define VX1000_OLDAFEAT_LOAD_CO_METADAT (0x100UL << 0x06)      /* bit 14: LoadCopyOffloaderMetadata command available */
#define VX1000_OLDAFEAT_DASTRANSMIT_BIG (0x100UL << 0x07)      /* bit 15: DasTransmitLargeChunk command available */
#define VX1000_OLDAFEAT_ASYNC_OLDA      (0x100UL << 0x08)      /* bit 16: AsyncOlda command available */
#define VX1000_OLDAFEAT_PERM_JUMP       (0x100UL << 0x09)      /* bit 17: PermanentJump command available */
#define VX1000_OLDAFEAT_SELECT_MEMSYTRG (0x100UL << 0x0A)      /* bit 18: SelectMemsyncTrigger command available */
#define VX1000_OLDAFEAT_TEMP_JUMP       (0x100UL << 0x0B)      /* bit 19: TemporaryJump command available */
#define VX1000_OLDAFEAT_LAST_STIM       (0x100UL << 0x0C)      /* bit 20: Alternative version of LastCommand available */
#define VX1000_OLDAFEAT_MULTISTIM8      (0x100UL << 0x0D)      /* bit 21: MultiStim8: when this bit is set, descriptor based STIM is unavailable, and command based STIM must be used. This command is the inverse of MultiCopy8. */
#define VX1000_OLDAFEAT_MULTISTIM8_BIG  (0x100UL << 0x0E)      /* bit 22: MultiStim8LargeChunks command available */

#if defined(VX1000_EVENT00_HANDLING)
#if ((VX1000_EVENT00_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT00_HANDLING */
#define VX1000_EVENT00_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT00_HANDLING */
#if defined(VX1000_EVENT01_HANDLING)
#if ((VX1000_EVENT01_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT01_HANDLING */
#define VX1000_EVENT01_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT01_HANDLING */
#if defined(VX1000_EVENT02_HANDLING)
#if ((VX1000_EVENT02_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT02_HANDLING */
#define VX1000_EVENT02_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT02_HANDLING */
#if defined(VX1000_EVENT03_HANDLING)
#if ((VX1000_EVENT03_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT03_HANDLING */
#define VX1000_EVENT03_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT03_HANDLING */
#if defined(VX1000_EVENT04_HANDLING)
#if ((VX1000_EVENT04_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT04_HANDLING */
#define VX1000_EVENT04_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT04_HANDLING */
#if defined(VX1000_EVENT05_HANDLING)
#if ((VX1000_EVENT05_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT05_HANDLING */
#define VX1000_EVENT05_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT05_HANDLING */
#if defined(VX1000_EVENT06_HANDLING)
#if ((VX1000_EVENT06_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT06_HANDLING */
#define VX1000_EVENT06_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT06_HANDLING */
#if defined(VX1000_EVENT07_HANDLING)
#if ((VX1000_EVENT07_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT07_HANDLING */
#define VX1000_EVENT07_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT07_HANDLING */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 8U
#if defined(VX1000_EVENT08_HANDLING)
#if ((VX1000_EVENT08_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT08_HANDLING */
#define VX1000_EVENT08_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT08_HANDLING */
#if defined(VX1000_EVENT09_HANDLING)
#if ((VX1000_EVENT09_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT09_HANDLING */
#define VX1000_EVENT09_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT09_HANDLING */
#if defined(VX1000_EVENT10_HANDLING)
#if ((VX1000_EVENT10_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT10_HANDLING */
#define VX1000_EVENT10_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT10_HANDLING */
#if defined(VX1000_EVENT11_HANDLING)
#if ((VX1000_EVENT11_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT11_HANDLING */
#define VX1000_EVENT11_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT11_HANDLING */
#if defined(VX1000_EVENT12_HANDLING)
#if ((VX1000_EVENT12_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT12_HANDLING */
#define VX1000_EVENT12_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT12_HANDLING */
#if defined(VX1000_EVENT13_HANDLING)
#if ((VX1000_EVENT13_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT13_HANDLING */
#define VX1000_EVENT13_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT13_HANDLING */
#if defined(VX1000_EVENT14_HANDLING)
#if ((VX1000_EVENT14_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT14_HANDLING */
#define VX1000_EVENT14_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT14_HANDLING */
#if defined(VX1000_EVENT15_HANDLING)
#if ((VX1000_EVENT15_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT15_HANDLING */
#define VX1000_EVENT15_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT15_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 8U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 16U
#if defined(VX1000_EVENT16_HANDLING)
#if ((VX1000_EVENT16_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT16_HANDLING */
#define VX1000_EVENT16_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT16_HANDLING */
#if defined(VX1000_EVENT17_HANDLING)
#if ((VX1000_EVENT17_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT17_HANDLING */
#define VX1000_EVENT17_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT17_HANDLING */
#if defined(VX1000_EVENT18_HANDLING)
#if ((VX1000_EVENT18_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT18_HANDLING */
#define VX1000_EVENT18_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT18_HANDLING */
#if defined(VX1000_EVENT19_HANDLING)
#if ((VX1000_EVENT19_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT19_HANDLING */
#define VX1000_EVENT19_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT19_HANDLING */
#if defined(VX1000_EVENT20_HANDLING)
#if ((VX1000_EVENT20_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT20_HANDLING */
#define VX1000_EVENT20_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT20_HANDLING */
#if defined(VX1000_EVENT21_HANDLING)
#if ((VX1000_EVENT21_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT21_HANDLING */
#define VX1000_EVENT21_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT21_HANDLING */
#if defined(VX1000_EVENT22_HANDLING)
#if ((VX1000_EVENT22_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT22_HANDLING */
#define VX1000_EVENT22_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT22_HANDLING */
#if defined(VX1000_EVENT23_HANDLING)
#if ((VX1000_EVENT23_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT23_HANDLING */
#define VX1000_EVENT23_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT23_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 16U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 24U
#if defined(VX1000_EVENT24_HANDLING)
#if ((VX1000_EVENT24_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT24_HANDLING */
#define VX1000_EVENT24_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT24_HANDLING */
#if defined(VX1000_EVENT25_HANDLING)
#if ((VX1000_EVENT25_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT25_HANDLING */
#define VX1000_EVENT25_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT25_HANDLING */
#if defined(VX1000_EVENT26_HANDLING)
#if ((VX1000_EVENT26_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT26_HANDLING */
#define VX1000_EVENT26_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT26_HANDLING */
#if defined(VX1000_EVENT27_HANDLING)
#if ((VX1000_EVENT27_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT27_HANDLING */
#define VX1000_EVENT27_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT27_HANDLING */
#if defined(VX1000_EVENT28_HANDLING)
#if ((VX1000_EVENT28_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT28_HANDLING */
#define VX1000_EVENT28_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT28_HANDLING */
#if defined(VX1000_EVENT29_HANDLING)
#if ((VX1000_EVENT29_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT29_HANDLING */
#define VX1000_EVENT29_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT29_HANDLING */
#if defined(VX1000_EVENT30_HANDLING)
#if ((VX1000_EVENT30_HANDLING) != (VX1000_EVENT_USES_ONLY_TRIGGER)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT30_HANDLING */
#define VX1000_EVENT30_HANDLING        (VX1000_EVENT_USES_ONLY_TRIGGER)
#endif /* !VX1000_EVENT30_HANDLING */
#if defined(VX1000_EVENT31_HANDLING)
#if ((VX1000_EVENT31_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT31_HANDLING */
#define VX1000_EVENT31_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT31_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 24U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 32U
#if defined(VX1000_EVENT32_HANDLING)
#if ((VX1000_EVENT32_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT32_HANDLING */
#define VX1000_EVENT32_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT32_HANDLING */
#if defined(VX1000_EVENT33_HANDLING)
#if ((VX1000_EVENT33_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT33_HANDLING */
#define VX1000_EVENT33_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT33_HANDLING */
#if defined(VX1000_EVENT34_HANDLING)
#if ((VX1000_EVENT34_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT34_HANDLING */
#define VX1000_EVENT34_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT34_HANDLING */
#if defined(VX1000_EVENT35_HANDLING)
#if ((VX1000_EVENT35_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT35_HANDLING */
#define VX1000_EVENT35_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT35_HANDLING */
#if defined(VX1000_EVENT36_HANDLING)
#if ((VX1000_EVENT36_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT36_HANDLING */
#define VX1000_EVENT36_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT36_HANDLING */
#if defined(VX1000_EVENT37_HANDLING)
#if ((VX1000_EVENT37_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT37_HANDLING */
#define VX1000_EVENT37_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT37_HANDLING */
#if defined(VX1000_EVENT38_HANDLING)
#if ((VX1000_EVENT38_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT38_HANDLING */
#define VX1000_EVENT38_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT38_HANDLING */
#if defined(VX1000_EVENT39_HANDLING)
#if ((VX1000_EVENT39_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT39_HANDLING */
#define VX1000_EVENT39_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT39_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 32U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 40U
#if defined(VX1000_EVENT40_HANDLING)
#if ((VX1000_EVENT40_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT40_HANDLING */
#define VX1000_EVENT40_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT40_HANDLING */
#if defined(VX1000_EVENT41_HANDLING)
#if ((VX1000_EVENT41_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT41_HANDLING */
#define VX1000_EVENT41_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT41_HANDLING */
#if defined(VX1000_EVENT42_HANDLING)
#if ((VX1000_EVENT42_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT42_HANDLING */
#define VX1000_EVENT42_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT42_HANDLING */
#if defined(VX1000_EVENT43_HANDLING)
#if ((VX1000_EVENT43_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT43_HANDLING */
#define VX1000_EVENT43_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT43_HANDLING */
#if defined(VX1000_EVENT44_HANDLING)
#if ((VX1000_EVENT44_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT44_HANDLING */
#define VX1000_EVENT44_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT44_HANDLING */
#if defined(VX1000_EVENT45_HANDLING)
#if ((VX1000_EVENT45_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT45_HANDLING */
#define VX1000_EVENT45_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT45_HANDLING */
#if defined(VX1000_EVENT46_HANDLING)
#if ((VX1000_EVENT46_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT46_HANDLING */
#define VX1000_EVENT46_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT46_HANDLING */
#if defined(VX1000_EVENT47_HANDLING)
#if ((VX1000_EVENT47_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT47_HANDLING */
#define VX1000_EVENT47_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT47_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 40U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 48U
#if defined(VX1000_EVENT48_HANDLING)
#if ((VX1000_EVENT48_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT48_HANDLING */
#define VX1000_EVENT48_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT48_HANDLING */
#if defined(VX1000_EVENT49_HANDLING)
#if ((VX1000_EVENT49_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT49_HANDLING */
#define VX1000_EVENT49_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT49_HANDLING */
#if defined(VX1000_EVENT50_HANDLING)
#if ((VX1000_EVENT50_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT50_HANDLING */
#define VX1000_EVENT50_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT50_HANDLING */
#if defined(VX1000_EVENT51_HANDLING)
#if ((VX1000_EVENT51_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT51_HANDLING */
#define VX1000_EVENT51_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT51_HANDLING */
#if defined(VX1000_EVENT52_HANDLING)
#if ((VX1000_EVENT52_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT52_HANDLING */
#define VX1000_EVENT52_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT52_HANDLING */
#if defined(VX1000_EVENT53_HANDLING)
#if ((VX1000_EVENT53_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT53_HANDLING */
#define VX1000_EVENT53_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT53_HANDLING */
#if defined(VX1000_EVENT54_HANDLING)
#if ((VX1000_EVENT54_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT54_HANDLING */
#define VX1000_EVENT54_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT54_HANDLING */
#if defined(VX1000_EVENT55_HANDLING)
#if ((VX1000_EVENT55_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT55_HANDLING */
#define VX1000_EVENT55_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT55_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 48U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 56U
#if defined(VX1000_EVENT56_HANDLING)
#if ((VX1000_EVENT56_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT56_HANDLING */
#define VX1000_EVENT56_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT56_HANDLING */
#if defined(VX1000_EVENT57_HANDLING)
#if ((VX1000_EVENT57_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT57_HANDLING */
#define VX1000_EVENT57_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT57_HANDLING */
#if defined(VX1000_EVENT58_HANDLING)
#if ((VX1000_EVENT58_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT58_HANDLING */
#define VX1000_EVENT58_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT58_HANDLING */
#if defined(VX1000_EVENT59_HANDLING)
#if ((VX1000_EVENT59_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT59_HANDLING */
#define VX1000_EVENT59_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT59_HANDLING */
#if defined(VX1000_EVENT60_HANDLING)
#if ((VX1000_EVENT60_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT60_HANDLING */
#define VX1000_EVENT60_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT60_HANDLING */
#if defined(VX1000_EVENT61_HANDLING)
#if ((VX1000_EVENT61_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT61_HANDLING */
#define VX1000_EVENT61_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT61_HANDLING */
#if defined(VX1000_EVENT62_HANDLING)
#if ((VX1000_EVENT62_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT62_HANDLING */
#define VX1000_EVENT62_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT62_HANDLING */
#if defined(VX1000_EVENT63_HANDLING)
#if ((VX1000_EVENT63_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT63_HANDLING */
#define VX1000_EVENT63_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT63_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 56U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 64U
#if defined(VX1000_EVENT64_HANDLING)
#if ((VX1000_EVENT64_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT64_HANDLING */
#define VX1000_EVENT64_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT64_HANDLING */
#if defined(VX1000_EVENT65_HANDLING)
#if ((VX1000_EVENT65_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT65_HANDLING */
#define VX1000_EVENT65_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT65_HANDLING */
#if defined(VX1000_EVENT66_HANDLING)
#if ((VX1000_EVENT66_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT66_HANDLING */
#define VX1000_EVENT66_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT66_HANDLING */
#if defined(VX1000_EVENT67_HANDLING)
#if ((VX1000_EVENT67_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT67_HANDLING */
#define VX1000_EVENT67_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT67_HANDLING */
#if defined(VX1000_EVENT68_HANDLING)
#if ((VX1000_EVENT68_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT68_HANDLING */
#define VX1000_EVENT68_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT68_HANDLING */
#if defined(VX1000_EVENT69_HANDLING)
#if ((VX1000_EVENT69_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT69_HANDLING */
#define VX1000_EVENT69_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT69_HANDLING */
#if defined(VX1000_EVENT70_HANDLING)
#if ((VX1000_EVENT70_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT70_HANDLING */
#define VX1000_EVENT70_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT70_HANDLING */
#if defined(VX1000_EVENT71_HANDLING)
#if ((VX1000_EVENT71_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT71_HANDLING */
#define VX1000_EVENT71_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT71_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 64U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 72U
#if defined(VX1000_EVENT72_HANDLING)
#if ((VX1000_EVENT72_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT72_HANDLING */
#define VX1000_EVENT72_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT72_HANDLING */
#if defined(VX1000_EVENT73_HANDLING)
#if ((VX1000_EVENT73_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT73_HANDLING */
#define VX1000_EVENT73_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT73_HANDLING */
#if defined(VX1000_EVENT74_HANDLING)
#if ((VX1000_EVENT74_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT74_HANDLING */
#define VX1000_EVENT74_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT74_HANDLING */
#if defined(VX1000_EVENT75_HANDLING)
#if ((VX1000_EVENT75_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT75_HANDLING */
#define VX1000_EVENT75_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT75_HANDLING */
#if defined(VX1000_EVENT76_HANDLING)
#if ((VX1000_EVENT76_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT76_HANDLING */
#define VX1000_EVENT76_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT76_HANDLING */
#if defined(VX1000_EVENT77_HANDLING)
#if ((VX1000_EVENT77_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT77_HANDLING */
#define VX1000_EVENT77_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT77_HANDLING */
#if defined(VX1000_EVENT78_HANDLING)
#if ((VX1000_EVENT78_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT78_HANDLING */
#define VX1000_EVENT78_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT78_HANDLING */
#if defined(VX1000_EVENT79_HANDLING)
#if ((VX1000_EVENT79_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT79_HANDLING */
#define VX1000_EVENT79_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT79_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 72U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 80U
#if defined(VX1000_EVENT80_HANDLING)
#if ((VX1000_EVENT80_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT80_HANDLING */
#define VX1000_EVENT80_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT80_HANDLING */
#if defined(VX1000_EVENT81_HANDLING)
#if ((VX1000_EVENT81_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT81_HANDLING */
#define VX1000_EVENT81_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT81_HANDLING */
#if defined(VX1000_EVENT82_HANDLING)
#if ((VX1000_EVENT82_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT82_HANDLING */
#define VX1000_EVENT82_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT82_HANDLING */
#if defined(VX1000_EVENT83_HANDLING)
#if ((VX1000_EVENT83_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT83_HANDLING */
#define VX1000_EVENT83_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT83_HANDLING */
#if defined(VX1000_EVENT84_HANDLING)
#if ((VX1000_EVENT84_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT84_HANDLING */
#define VX1000_EVENT84_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT84_HANDLING */
#if defined(VX1000_EVENT85_HANDLING)
#if ((VX1000_EVENT85_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT85_HANDLING */
#define VX1000_EVENT85_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT85_HANDLING */
#if defined(VX1000_EVENT86_HANDLING)
#if ((VX1000_EVENT86_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT86_HANDLING */
#define VX1000_EVENT86_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT86_HANDLING */
#if defined(VX1000_EVENT87_HANDLING)
#if ((VX1000_EVENT87_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT87_HANDLING */
#define VX1000_EVENT87_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT87_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 80U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 88U
#if defined(VX1000_EVENT88_HANDLING)
#if ((VX1000_EVENT88_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT88_HANDLING */
#define VX1000_EVENT88_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT88_HANDLING */
#if defined(VX1000_EVENT89_HANDLING)
#if ((VX1000_EVENT89_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT89_HANDLING */
#define VX1000_EVENT89_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT89_HANDLING */
#if defined(VX1000_EVENT90_HANDLING)
#if ((VX1000_EVENT90_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT90_HANDLING */
#define VX1000_EVENT90_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT90_HANDLING */
#if defined(VX1000_EVENT91_HANDLING)
#if ((VX1000_EVENT91_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT91_HANDLING */
#define VX1000_EVENT91_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT91_HANDLING */
#if defined(VX1000_EVENT92_HANDLING)
#if ((VX1000_EVENT92_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT92_HANDLING */
#define VX1000_EVENT92_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT92_HANDLING */
#if defined(VX1000_EVENT93_HANDLING)
#if ((VX1000_EVENT93_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT93_HANDLING */
#define VX1000_EVENT93_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT93_HANDLING */
#if defined(VX1000_EVENT94_HANDLING)
#if ((VX1000_EVENT94_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT94_HANDLING */
#define VX1000_EVENT94_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT94_HANDLING */
#if defined(VX1000_EVENT95_HANDLING)
#if ((VX1000_EVENT95_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT95_HANDLING */
#define VX1000_EVENT95_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT95_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 88U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 96U
#if defined(VX1000_EVENT96_HANDLING)
#if ((VX1000_EVENT96_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT96_HANDLING */
#define VX1000_EVENT96_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT96_HANDLING */
#if defined(VX1000_EVENT97_HANDLING)
#if ((VX1000_EVENT97_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT97_HANDLING */
#define VX1000_EVENT97_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT97_HANDLING */
#if defined(VX1000_EVENT98_HANDLING)
#if ((VX1000_EVENT98_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT98_HANDLING */
#define VX1000_EVENT98_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT98_HANDLING */
#if defined(VX1000_EVENT99_HANDLING)
#if ((VX1000_EVENT99_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT99_HANDLING */
#define VX1000_EVENT99_HANDLING        (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT99_HANDLING */
#if defined(VX1000_EVENT100_HANDLING)
#if ((VX1000_EVENT100_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT100_HANDLING */
#define VX1000_EVENT100_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT100_HANDLING */
#if defined(VX1000_EVENT101_HANDLING)
#if ((VX1000_EVENT101_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT101_HANDLING */
#define VX1000_EVENT101_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT101_HANDLING */
#if defined(VX1000_EVENT102_HANDLING)
#if ((VX1000_EVENT102_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT102_HANDLING */
#define VX1000_EVENT102_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT102_HANDLING */
#if defined(VX1000_EVENT103_HANDLING)
#if ((VX1000_EVENT103_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT103_HANDLING */
#define VX1000_EVENT103_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT103_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 96U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 104U
#if defined(VX1000_EVENT104_HANDLING)
#if ((VX1000_EVENT104_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT104_HANDLING */
#define VX1000_EVENT104_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT104_HANDLING */
#if defined(VX1000_EVENT105_HANDLING)
#if ((VX1000_EVENT105_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT105_HANDLING */
#define VX1000_EVENT105_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT105_HANDLING */
#if defined(VX1000_EVENT106_HANDLING)
#if ((VX1000_EVENT106_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT106_HANDLING */
#define VX1000_EVENT106_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT106_HANDLING */
#if defined(VX1000_EVENT107_HANDLING)
#if ((VX1000_EVENT107_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT107_HANDLING */
#define VX1000_EVENT107_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT107_HANDLING */
#if defined(VX1000_EVENT108_HANDLING)
#if ((VX1000_EVENT108_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT108_HANDLING */
#define VX1000_EVENT108_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT108_HANDLING */
#if defined(VX1000_EVENT109_HANDLING)
#if ((VX1000_EVENT109_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT109_HANDLING */
#define VX1000_EVENT109_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT109_HANDLING */
#if defined(VX1000_EVENT110_HANDLING)
#if ((VX1000_EVENT110_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT110_HANDLING */
#define VX1000_EVENT110_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT110_HANDLING */
#if defined(VX1000_EVENT111_HANDLING)
#if ((VX1000_EVENT111_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT111_HANDLING */
#define VX1000_EVENT111_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT111_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 104U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 112U
#if defined(VX1000_EVENT112_HANDLING)
#if ((VX1000_EVENT112_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT112_HANDLING */
#define VX1000_EVENT112_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT112_HANDLING */
#if defined(VX1000_EVENT113_HANDLING)
#if ((VX1000_EVENT113_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT113_HANDLING */
#define VX1000_EVENT113_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT113_HANDLING */
#if defined(VX1000_EVENT114_HANDLING)
#if ((VX1000_EVENT114_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT114_HANDLING */
#define VX1000_EVENT114_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT114_HANDLING */
#if defined(VX1000_EVENT115_HANDLING)
#if ((VX1000_EVENT115_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT115_HANDLING */
#define VX1000_EVENT115_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT115_HANDLING */
#if defined(VX1000_EVENT116_HANDLING)
#if ((VX1000_EVENT116_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT116_HANDLING */
#define VX1000_EVENT116_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT116_HANDLING */
#if defined(VX1000_EVENT117_HANDLING)
#if ((VX1000_EVENT117_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT117_HANDLING */
#define VX1000_EVENT117_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT117_HANDLING */
#if defined(VX1000_EVENT118_HANDLING)
#if ((VX1000_EVENT118_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT118_HANDLING */
#define VX1000_EVENT118_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT118_HANDLING */
#if defined(VX1000_EVENT119_HANDLING)
#if ((VX1000_EVENT119_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT119_HANDLING */
#define VX1000_EVENT119_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT119_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 112U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 120U
#if defined(VX1000_EVENT120_HANDLING)
#if ((VX1000_EVENT120_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT120_HANDLING */
#define VX1000_EVENT120_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT120_HANDLING */
#if defined(VX1000_EVENT121_HANDLING)
#if ((VX1000_EVENT121_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT121_HANDLING */
#define VX1000_EVENT121_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT121_HANDLING */
#if defined(VX1000_EVENT122_HANDLING)
#if ((VX1000_EVENT122_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT122_HANDLING */
#define VX1000_EVENT122_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT122_HANDLING */
#if defined(VX1000_EVENT123_HANDLING)
#if ((VX1000_EVENT123_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT123_HANDLING */
#define VX1000_EVENT123_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT123_HANDLING */
#if defined(VX1000_EVENT124_HANDLING)
#if ((VX1000_EVENT124_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT124_HANDLING */
#define VX1000_EVENT124_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT124_HANDLING */
#if defined(VX1000_EVENT125_HANDLING)
#if ((VX1000_EVENT125_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT125_HANDLING */
#define VX1000_EVENT125_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT125_HANDLING */
#if defined(VX1000_EVENT126_HANDLING)
#if ((VX1000_EVENT126_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT126_HANDLING */
#define VX1000_EVENT126_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT126_HANDLING */
#if defined(VX1000_EVENT127_HANDLING)
#if ((VX1000_EVENT127_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT127_HANDLING */
#define VX1000_EVENT127_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT127_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 120U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 128U
#if defined(VX1000_EVENT128_HANDLING)
#if ((VX1000_EVENT128_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT128_HANDLING */
#define VX1000_EVENT128_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT128_HANDLING */
#if defined(VX1000_EVENT129_HANDLING)
#if ((VX1000_EVENT129_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT129_HANDLING */
#define VX1000_EVENT129_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT129_HANDLING */
#if defined(VX1000_EVENT130_HANDLING)
#if ((VX1000_EVENT130_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT130_HANDLING */
#define VX1000_EVENT130_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT130_HANDLING */
#if defined(VX1000_EVENT131_HANDLING)
#if ((VX1000_EVENT131_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT131_HANDLING */
#define VX1000_EVENT131_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT131_HANDLING */
#if defined(VX1000_EVENT132_HANDLING)
#if ((VX1000_EVENT132_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT132_HANDLING */
#define VX1000_EVENT132_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT132_HANDLING */
#if defined(VX1000_EVENT133_HANDLING)
#if ((VX1000_EVENT133_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT133_HANDLING */
#define VX1000_EVENT133_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT133_HANDLING */
#if defined(VX1000_EVENT134_HANDLING)
#if ((VX1000_EVENT134_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT134_HANDLING */
#define VX1000_EVENT134_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT134_HANDLING */
#if defined(VX1000_EVENT135_HANDLING)
#if ((VX1000_EVENT135_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT135_HANDLING */
#define VX1000_EVENT135_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT135_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 128U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 136U
#if defined(VX1000_EVENT136_HANDLING)
#if ((VX1000_EVENT136_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT136_HANDLING */
#define VX1000_EVENT136_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT136_HANDLING */
#if defined(VX1000_EVENT137_HANDLING)
#if ((VX1000_EVENT137_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT137_HANDLING */
#define VX1000_EVENT137_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT137_HANDLING */
#if defined(VX1000_EVENT138_HANDLING)
#if ((VX1000_EVENT138_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT138_HANDLING */
#define VX1000_EVENT138_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT138_HANDLING */
#if defined(VX1000_EVENT139_HANDLING)
#if ((VX1000_EVENT139_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT139_HANDLING */
#define VX1000_EVENT139_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT139_HANDLING */
#if defined(VX1000_EVENT140_HANDLING)
#if ((VX1000_EVENT140_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT140_HANDLING */
#define VX1000_EVENT140_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT140_HANDLING */
#if defined(VX1000_EVENT141_HANDLING)
#if ((VX1000_EVENT141_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT141_HANDLING */
#define VX1000_EVENT141_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT141_HANDLING */
#if defined(VX1000_EVENT142_HANDLING)
#if ((VX1000_EVENT142_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT142_HANDLING */
#define VX1000_EVENT142_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT142_HANDLING */
#if defined(VX1000_EVENT143_HANDLING)
#if ((VX1000_EVENT143_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT143_HANDLING */
#define VX1000_EVENT143_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT143_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 136U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 144U
#if defined(VX1000_EVENT144_HANDLING)
#if ((VX1000_EVENT144_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT144_HANDLING */
#define VX1000_EVENT144_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT144_HANDLING */
#if defined(VX1000_EVENT145_HANDLING)
#if ((VX1000_EVENT145_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT145_HANDLING */
#define VX1000_EVENT145_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT145_HANDLING */
#if defined(VX1000_EVENT146_HANDLING)
#if ((VX1000_EVENT146_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT146_HANDLING */
#define VX1000_EVENT146_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT146_HANDLING */
#if defined(VX1000_EVENT147_HANDLING)
#if ((VX1000_EVENT147_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT147_HANDLING */
#define VX1000_EVENT147_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT147_HANDLING */
#if defined(VX1000_EVENT148_HANDLING)
#if ((VX1000_EVENT148_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT148_HANDLING */
#define VX1000_EVENT148_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT148_HANDLING */
#if defined(VX1000_EVENT149_HANDLING)
#if ((VX1000_EVENT149_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT149_HANDLING */
#define VX1000_EVENT149_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT149_HANDLING */
#if defined(VX1000_EVENT150_HANDLING)
#if ((VX1000_EVENT150_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT150_HANDLING */
#define VX1000_EVENT150_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT150_HANDLING */
#if defined(VX1000_EVENT151_HANDLING)
#if ((VX1000_EVENT151_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT151_HANDLING */
#define VX1000_EVENT151_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT151_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 144U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 152U
#if defined(VX1000_EVENT152_HANDLING)
#if ((VX1000_EVENT152_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT152_HANDLING */
#define VX1000_EVENT152_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT152_HANDLING */
#if defined(VX1000_EVENT153_HANDLING)
#if ((VX1000_EVENT153_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT153_HANDLING */
#define VX1000_EVENT153_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT153_HANDLING */
#if defined(VX1000_EVENT154_HANDLING)
#if ((VX1000_EVENT154_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT154_HANDLING */
#define VX1000_EVENT154_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT154_HANDLING */
#if defined(VX1000_EVENT155_HANDLING)
#if ((VX1000_EVENT155_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT155_HANDLING */
#define VX1000_EVENT155_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT155_HANDLING */
#if defined(VX1000_EVENT156_HANDLING)
#if ((VX1000_EVENT156_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT156_HANDLING */
#define VX1000_EVENT156_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT156_HANDLING */
#if defined(VX1000_EVENT157_HANDLING)
#if ((VX1000_EVENT157_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT157_HANDLING */
#define VX1000_EVENT157_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT157_HANDLING */
#if defined(VX1000_EVENT158_HANDLING)
#if ((VX1000_EVENT158_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT158_HANDLING */
#define VX1000_EVENT158_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT158_HANDLING */
#if defined(VX1000_EVENT159_HANDLING)
#if ((VX1000_EVENT159_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT159_HANDLING */
#define VX1000_EVENT159_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT159_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 152U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 160U
#if defined(VX1000_EVENT160_HANDLING)
#if ((VX1000_EVENT160_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT160_HANDLING */
#define VX1000_EVENT160_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT160_HANDLING */
#if defined(VX1000_EVENT161_HANDLING)
#if ((VX1000_EVENT161_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT161_HANDLING */
#define VX1000_EVENT161_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT161_HANDLING */
#if defined(VX1000_EVENT162_HANDLING)
#if ((VX1000_EVENT162_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT162_HANDLING */
#define VX1000_EVENT162_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT162_HANDLING */
#if defined(VX1000_EVENT163_HANDLING)
#if ((VX1000_EVENT163_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT163_HANDLING */
#define VX1000_EVENT163_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT163_HANDLING */
#if defined(VX1000_EVENT164_HANDLING)
#if ((VX1000_EVENT164_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT164_HANDLING */
#define VX1000_EVENT164_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT164_HANDLING */
#if defined(VX1000_EVENT165_HANDLING)
#if ((VX1000_EVENT165_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT165_HANDLING */
#define VX1000_EVENT165_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT165_HANDLING */
#if defined(VX1000_EVENT166_HANDLING)
#if ((VX1000_EVENT166_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT166_HANDLING */
#define VX1000_EVENT166_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT166_HANDLING */
#if defined(VX1000_EVENT167_HANDLING)
#if ((VX1000_EVENT167_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT167_HANDLING */
#define VX1000_EVENT167_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT167_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 160U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 168U
#if defined(VX1000_EVENT168_HANDLING)
#if ((VX1000_EVENT168_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT168_HANDLING */
#define VX1000_EVENT168_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT168_HANDLING */
#if defined(VX1000_EVENT169_HANDLING)
#if ((VX1000_EVENT169_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT169_HANDLING */
#define VX1000_EVENT169_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT169_HANDLING */
#if defined(VX1000_EVENT170_HANDLING)
#if ((VX1000_EVENT170_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT170_HANDLING */
#define VX1000_EVENT170_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT170_HANDLING */
#if defined(VX1000_EVENT171_HANDLING)
#if ((VX1000_EVENT171_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT171_HANDLING */
#define VX1000_EVENT171_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT171_HANDLING */
#if defined(VX1000_EVENT172_HANDLING)
#if ((VX1000_EVENT172_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT172_HANDLING */
#define VX1000_EVENT172_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT172_HANDLING */
#if defined(VX1000_EVENT173_HANDLING)
#if ((VX1000_EVENT173_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT173_HANDLING */
#define VX1000_EVENT173_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT173_HANDLING */
#if defined(VX1000_EVENT174_HANDLING)
#if ((VX1000_EVENT174_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT174_HANDLING */
#define VX1000_EVENT174_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT174_HANDLING */
#if defined(VX1000_EVENT175_HANDLING)
#if ((VX1000_EVENT175_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT175_HANDLING */
#define VX1000_EVENT175_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT175_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 168U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 176U
#if defined(VX1000_EVENT176_HANDLING)
#if ((VX1000_EVENT176_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT176_HANDLING */
#define VX1000_EVENT176_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT176_HANDLING */
#if defined(VX1000_EVENT177_HANDLING)
#if ((VX1000_EVENT177_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT177_HANDLING */
#define VX1000_EVENT177_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT177_HANDLING */
#if defined(VX1000_EVENT178_HANDLING)
#if ((VX1000_EVENT178_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT178_HANDLING */
#define VX1000_EVENT178_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT178_HANDLING */
#if defined(VX1000_EVENT179_HANDLING)
#if ((VX1000_EVENT179_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT179_HANDLING */
#define VX1000_EVENT179_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT179_HANDLING */
#if defined(VX1000_EVENT180_HANDLING)
#if ((VX1000_EVENT180_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT180_HANDLING */
#define VX1000_EVENT180_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT180_HANDLING */
#if defined(VX1000_EVENT181_HANDLING)
#if ((VX1000_EVENT181_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT181_HANDLING */
#define VX1000_EVENT181_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT181_HANDLING */
#if defined(VX1000_EVENT182_HANDLING)
#if ((VX1000_EVENT182_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT182_HANDLING */
#define VX1000_EVENT182_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT182_HANDLING */
#if defined(VX1000_EVENT183_HANDLING)
#if ((VX1000_EVENT183_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT183_HANDLING */
#define VX1000_EVENT183_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT183_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 176U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 184U
#if defined(VX1000_EVENT184_HANDLING)
#if ((VX1000_EVENT184_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT184_HANDLING */
#define VX1000_EVENT184_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT184_HANDLING */
#if defined(VX1000_EVENT185_HANDLING)
#if ((VX1000_EVENT185_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT185_HANDLING */
#define VX1000_EVENT185_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT185_HANDLING */
#if defined(VX1000_EVENT186_HANDLING)
#if ((VX1000_EVENT186_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT186_HANDLING */
#define VX1000_EVENT186_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT186_HANDLING */
#if defined(VX1000_EVENT187_HANDLING)
#if ((VX1000_EVENT187_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT187_HANDLING */
#define VX1000_EVENT187_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT187_HANDLING */
#if defined(VX1000_EVENT188_HANDLING)
#if ((VX1000_EVENT188_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT188_HANDLING */
#define VX1000_EVENT188_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT188_HANDLING */
#if defined(VX1000_EVENT189_HANDLING)
#if ((VX1000_EVENT189_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT189_HANDLING */
#define VX1000_EVENT189_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT189_HANDLING */
#if defined(VX1000_EVENT190_HANDLING)
#if ((VX1000_EVENT190_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT190_HANDLING */
#define VX1000_EVENT190_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT190_HANDLING */
#if defined(VX1000_EVENT191_HANDLING)
#if ((VX1000_EVENT191_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT191_HANDLING */
#define VX1000_EVENT191_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT191_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 184U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 192U
#if defined(VX1000_EVENT192_HANDLING)
#if ((VX1000_EVENT192_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT192_HANDLING */
#define VX1000_EVENT192_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT192_HANDLING */
#if defined(VX1000_EVENT193_HANDLING)
#if ((VX1000_EVENT193_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT193_HANDLING */
#define VX1000_EVENT193_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT193_HANDLING */
#if defined(VX1000_EVENT194_HANDLING)
#if ((VX1000_EVENT194_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT194_HANDLING */
#define VX1000_EVENT194_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT194_HANDLING */
#if defined(VX1000_EVENT195_HANDLING)
#if ((VX1000_EVENT195_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT195_HANDLING */
#define VX1000_EVENT195_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT195_HANDLING */
#if defined(VX1000_EVENT196_HANDLING)
#if ((VX1000_EVENT196_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT196_HANDLING */
#define VX1000_EVENT196_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT196_HANDLING */
#if defined(VX1000_EVENT197_HANDLING)
#if ((VX1000_EVENT197_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT197_HANDLING */
#define VX1000_EVENT197_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT197_HANDLING */
#if defined(VX1000_EVENT198_HANDLING)
#if ((VX1000_EVENT198_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT198_HANDLING */
#define VX1000_EVENT198_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT198_HANDLING */
#if defined(VX1000_EVENT199_HANDLING)
#if ((VX1000_EVENT199_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT199_HANDLING */
#define VX1000_EVENT199_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT199_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 192U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 200U
#if defined(VX1000_EVENT200_HANDLING)
#if ((VX1000_EVENT200_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT200_HANDLING */
#define VX1000_EVENT200_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT200_HANDLING */
#if defined(VX1000_EVENT201_HANDLING)
#if ((VX1000_EVENT201_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT201_HANDLING */
#define VX1000_EVENT201_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT201_HANDLING */
#if defined(VX1000_EVENT202_HANDLING)
#if ((VX1000_EVENT202_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT202_HANDLING */
#define VX1000_EVENT202_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT202_HANDLING */
#if defined(VX1000_EVENT203_HANDLING)
#if ((VX1000_EVENT203_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT203_HANDLING */
#define VX1000_EVENT203_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT203_HANDLING */
#if defined(VX1000_EVENT204_HANDLING)
#if ((VX1000_EVENT204_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT204_HANDLING */
#define VX1000_EVENT204_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT204_HANDLING */
#if defined(VX1000_EVENT205_HANDLING)
#if ((VX1000_EVENT205_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT205_HANDLING */
#define VX1000_EVENT205_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT205_HANDLING */
#if defined(VX1000_EVENT206_HANDLING)
#if ((VX1000_EVENT206_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT206_HANDLING */
#define VX1000_EVENT206_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT206_HANDLING */
#if defined(VX1000_EVENT207_HANDLING)
#if ((VX1000_EVENT207_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT207_HANDLING */
#define VX1000_EVENT207_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT207_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 200U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 208U
#if defined(VX1000_EVENT208_HANDLING)
#if ((VX1000_EVENT208_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT208_HANDLING */
#define VX1000_EVENT208_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT208_HANDLING */
#if defined(VX1000_EVENT209_HANDLING)
#if ((VX1000_EVENT209_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT209_HANDLING */
#define VX1000_EVENT209_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT209_HANDLING */
#if defined(VX1000_EVENT210_HANDLING)
#if ((VX1000_EVENT210_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT210_HANDLING */
#define VX1000_EVENT210_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT210_HANDLING */
#if defined(VX1000_EVENT211_HANDLING)
#if ((VX1000_EVENT211_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT211_HANDLING */
#define VX1000_EVENT211_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT211_HANDLING */
#if defined(VX1000_EVENT212_HANDLING)
#if ((VX1000_EVENT212_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT212_HANDLING */
#define VX1000_EVENT212_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT212_HANDLING */
#if defined(VX1000_EVENT213_HANDLING)
#if ((VX1000_EVENT213_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT213_HANDLING */
#define VX1000_EVENT213_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT213_HANDLING */
#if defined(VX1000_EVENT214_HANDLING)
#if ((VX1000_EVENT214_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT214_HANDLING */
#define VX1000_EVENT214_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT214_HANDLING */
#if defined(VX1000_EVENT215_HANDLING)
#if ((VX1000_EVENT215_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT215_HANDLING */
#define VX1000_EVENT215_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT215_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 208U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 216U
#if defined(VX1000_EVENT216_HANDLING)
#if ((VX1000_EVENT216_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT216_HANDLING */
#define VX1000_EVENT216_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT216_HANDLING */
#if defined(VX1000_EVENT217_HANDLING)
#if ((VX1000_EVENT217_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT217_HANDLING */
#define VX1000_EVENT217_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT217_HANDLING */
#if defined(VX1000_EVENT218_HANDLING)
#if ((VX1000_EVENT218_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT218_HANDLING */
#define VX1000_EVENT218_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT218_HANDLING */
#if defined(VX1000_EVENT219_HANDLING)
#if ((VX1000_EVENT219_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT219_HANDLING */
#define VX1000_EVENT219_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT219_HANDLING */
#if defined(VX1000_EVENT220_HANDLING)
#if ((VX1000_EVENT220_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT220_HANDLING */
#define VX1000_EVENT220_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT220_HANDLING */
#if defined(VX1000_EVENT221_HANDLING)
#if ((VX1000_EVENT221_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT221_HANDLING */
#define VX1000_EVENT221_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT221_HANDLING */
#if defined(VX1000_EVENT222_HANDLING)
#if ((VX1000_EVENT222_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT222_HANDLING */
#define VX1000_EVENT222_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT222_HANDLING */
#if defined(VX1000_EVENT223_HANDLING)
#if ((VX1000_EVENT223_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT223_HANDLING */
#define VX1000_EVENT223_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT223_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 216U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 224U
#if defined(VX1000_EVENT224_HANDLING)
#if ((VX1000_EVENT224_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT224_HANDLING */
#define VX1000_EVENT224_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT224_HANDLING */
#if defined(VX1000_EVENT225_HANDLING)
#if ((VX1000_EVENT225_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT225_HANDLING */
#define VX1000_EVENT225_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT225_HANDLING */
#if defined(VX1000_EVENT226_HANDLING)
#if ((VX1000_EVENT226_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT226_HANDLING */
#define VX1000_EVENT226_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT226_HANDLING */
#if defined(VX1000_EVENT227_HANDLING)
#if ((VX1000_EVENT227_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT227_HANDLING */
#define VX1000_EVENT227_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT227_HANDLING */
#if defined(VX1000_EVENT228_HANDLING)
#if ((VX1000_EVENT228_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT228_HANDLING */
#define VX1000_EVENT228_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT228_HANDLING */
#if defined(VX1000_EVENT229_HANDLING)
#if ((VX1000_EVENT229_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT229_HANDLING */
#define VX1000_EVENT229_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT229_HANDLING */
#if defined(VX1000_EVENT230_HANDLING)
#if ((VX1000_EVENT230_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT230_HANDLING */
#define VX1000_EVENT230_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT230_HANDLING */
#if defined(VX1000_EVENT231_HANDLING)
#if ((VX1000_EVENT231_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT231_HANDLING */
#define VX1000_EVENT231_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT231_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 224U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 232U
#if defined(VX1000_EVENT232_HANDLING)
#if ((VX1000_EVENT232_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT232_HANDLING */
#define VX1000_EVENT232_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT232_HANDLING */
#if defined(VX1000_EVENT233_HANDLING)
#if ((VX1000_EVENT233_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT233_HANDLING */
#define VX1000_EVENT233_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT233_HANDLING */
#if defined(VX1000_EVENT234_HANDLING)
#if ((VX1000_EVENT234_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT234_HANDLING */
#define VX1000_EVENT234_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT234_HANDLING */
#if defined(VX1000_EVENT235_HANDLING)
#if ((VX1000_EVENT235_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT235_HANDLING */
#define VX1000_EVENT235_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT235_HANDLING */
#if defined(VX1000_EVENT236_HANDLING)
#if ((VX1000_EVENT236_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT236_HANDLING */
#define VX1000_EVENT236_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT236_HANDLING */
#if defined(VX1000_EVENT237_HANDLING)
#if ((VX1000_EVENT237_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT237_HANDLING */
#define VX1000_EVENT237_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT237_HANDLING */
#if defined(VX1000_EVENT238_HANDLING)
#if ((VX1000_EVENT238_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT238_HANDLING */
#define VX1000_EVENT238_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT238_HANDLING */
#if defined(VX1000_EVENT239_HANDLING)
#if ((VX1000_EVENT239_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT239_HANDLING */
#define VX1000_EVENT239_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT239_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 232U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 240U
#if defined(VX1000_EVENT240_HANDLING)
#if ((VX1000_EVENT240_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT240_HANDLING */
#define VX1000_EVENT240_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT240_HANDLING */
#if defined(VX1000_EVENT241_HANDLING)
#if ((VX1000_EVENT241_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT241_HANDLING */
#define VX1000_EVENT241_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT241_HANDLING */
#if defined(VX1000_EVENT242_HANDLING)
#if ((VX1000_EVENT242_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT242_HANDLING */
#define VX1000_EVENT242_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT242_HANDLING */
#if defined(VX1000_EVENT243_HANDLING)
#if ((VX1000_EVENT243_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT243_HANDLING */
#define VX1000_EVENT243_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT243_HANDLING */
#if defined(VX1000_EVENT244_HANDLING)
#if ((VX1000_EVENT244_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT244_HANDLING */
#define VX1000_EVENT244_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT244_HANDLING */
#if defined(VX1000_EVENT245_HANDLING)
#if ((VX1000_EVENT245_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT245_HANDLING */
#define VX1000_EVENT245_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT245_HANDLING */
#if defined(VX1000_EVENT246_HANDLING)
#if ((VX1000_EVENT246_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT246_HANDLING */
#define VX1000_EVENT246_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT246_HANDLING */
#if defined(VX1000_EVENT247_HANDLING)
#if ((VX1000_EVENT247_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT247_HANDLING */
#define VX1000_EVENT247_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT247_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 240U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 248U
#if defined(VX1000_EVENT248_HANDLING)
#if ((VX1000_EVENT248_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT248_HANDLING */
#define VX1000_EVENT248_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT248_HANDLING */
#if defined(VX1000_EVENT249_HANDLING)
#if ((VX1000_EVENT249_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT249_HANDLING */
#define VX1000_EVENT249_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT249_HANDLING */
#if defined(VX1000_EVENT250_HANDLING)
#if ((VX1000_EVENT250_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT250_HANDLING */
#define VX1000_EVENT250_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT250_HANDLING */
#if defined(VX1000_EVENT251_HANDLING)
#if ((VX1000_EVENT251_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT251_HANDLING */
#define VX1000_EVENT251_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT251_HANDLING */
#if defined(VX1000_EVENT252_HANDLING)
#if ((VX1000_EVENT252_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT252_HANDLING */
#define VX1000_EVENT252_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT252_HANDLING */
#if defined(VX1000_EVENT253_HANDLING)
#if ((VX1000_EVENT253_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT253_HANDLING */
#define VX1000_EVENT253_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT253_HANDLING */
#if defined(VX1000_EVENT254_HANDLING)
#if ((VX1000_EVENT254_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT254_HANDLING */
#define VX1000_EVENT254_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT254_HANDLING */
#if defined(VX1000_EVENT255_HANDLING)
#if ((VX1000_EVENT255_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT255_HANDLING */
#define VX1000_EVENT255_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT255_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 248U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 256U
#if defined(VX1000_EVENT256_HANDLING)
#if ((VX1000_EVENT256_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT256_HANDLING */
#define VX1000_EVENT256_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT256_HANDLING */
#if defined(VX1000_EVENT257_HANDLING)
#if ((VX1000_EVENT257_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT257_HANDLING */
#define VX1000_EVENT257_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT257_HANDLING */
#if defined(VX1000_EVENT258_HANDLING)
#if ((VX1000_EVENT258_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT258_HANDLING */
#define VX1000_EVENT258_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT258_HANDLING */
#if defined(VX1000_EVENT259_HANDLING)
#if ((VX1000_EVENT259_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT259_HANDLING */
#define VX1000_EVENT259_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT259_HANDLING */
#if defined(VX1000_EVENT260_HANDLING)
#if ((VX1000_EVENT260_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT260_HANDLING */
#define VX1000_EVENT260_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT260_HANDLING */
#if defined(VX1000_EVENT261_HANDLING)
#if ((VX1000_EVENT261_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT261_HANDLING */
#define VX1000_EVENT261_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT261_HANDLING */
#if defined(VX1000_EVENT262_HANDLING)
#if ((VX1000_EVENT262_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT262_HANDLING */
#define VX1000_EVENT262_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT262_HANDLING */
#if defined(VX1000_EVENT263_HANDLING)
#if ((VX1000_EVENT263_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT263_HANDLING */
#define VX1000_EVENT263_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT263_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 256U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 264U
#if defined(VX1000_EVENT264_HANDLING)
#if ((VX1000_EVENT264_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT264_HANDLING */
#define VX1000_EVENT264_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT264_HANDLING */
#if defined(VX1000_EVENT265_HANDLING)
#if ((VX1000_EVENT265_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT265_HANDLING */
#define VX1000_EVENT265_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT265_HANDLING */
#if defined(VX1000_EVENT266_HANDLING)
#if ((VX1000_EVENT266_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT266_HANDLING */
#define VX1000_EVENT266_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT266_HANDLING */
#if defined(VX1000_EVENT267_HANDLING)
#if ((VX1000_EVENT267_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT267_HANDLING */
#define VX1000_EVENT267_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT267_HANDLING */
#if defined(VX1000_EVENT268_HANDLING)
#if ((VX1000_EVENT268_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT268_HANDLING */
#define VX1000_EVENT268_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT268_HANDLING */
#if defined(VX1000_EVENT269_HANDLING)
#if ((VX1000_EVENT269_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT269_HANDLING */
#define VX1000_EVENT269_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT269_HANDLING */
#if defined(VX1000_EVENT270_HANDLING)
#if ((VX1000_EVENT270_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT270_HANDLING */
#define VX1000_EVENT270_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT270_HANDLING */
#if defined(VX1000_EVENT271_HANDLING)
#if ((VX1000_EVENT271_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT271_HANDLING */
#define VX1000_EVENT271_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT271_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 264U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 272U
#if defined(VX1000_EVENT272_HANDLING)
#if ((VX1000_EVENT272_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT272_HANDLING */
#define VX1000_EVENT272_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT272_HANDLING */
#if defined(VX1000_EVENT273_HANDLING)
#if ((VX1000_EVENT273_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT273_HANDLING */
#define VX1000_EVENT273_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT273_HANDLING */
#if defined(VX1000_EVENT274_HANDLING)
#if ((VX1000_EVENT274_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT274_HANDLING */
#define VX1000_EVENT274_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT274_HANDLING */
#if defined(VX1000_EVENT275_HANDLING)
#if ((VX1000_EVENT275_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT275_HANDLING */
#define VX1000_EVENT275_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT275_HANDLING */
#if defined(VX1000_EVENT276_HANDLING)
#if ((VX1000_EVENT276_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT276_HANDLING */
#define VX1000_EVENT276_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT276_HANDLING */
#if defined(VX1000_EVENT277_HANDLING)
#if ((VX1000_EVENT277_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT277_HANDLING */
#define VX1000_EVENT277_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT277_HANDLING */
#if defined(VX1000_EVENT278_HANDLING)
#if ((VX1000_EVENT278_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT278_HANDLING */
#define VX1000_EVENT278_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT278_HANDLING */
#if defined(VX1000_EVENT279_HANDLING)
#if ((VX1000_EVENT279_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT279_HANDLING */
#define VX1000_EVENT279_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT279_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 272U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 280U
#if defined(VX1000_EVENT280_HANDLING)
#if ((VX1000_EVENT280_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT280_HANDLING */
#define VX1000_EVENT280_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT280_HANDLING */
#if defined(VX1000_EVENT281_HANDLING)
#if ((VX1000_EVENT281_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT281_HANDLING */
#define VX1000_EVENT281_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT281_HANDLING */
#if defined(VX1000_EVENT282_HANDLING)
#if ((VX1000_EVENT282_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT282_HANDLING */
#define VX1000_EVENT282_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT282_HANDLING */
#if defined(VX1000_EVENT283_HANDLING)
#if ((VX1000_EVENT283_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT283_HANDLING */
#define VX1000_EVENT283_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT283_HANDLING */
#if defined(VX1000_EVENT284_HANDLING)
#if ((VX1000_EVENT284_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT284_HANDLING */
#define VX1000_EVENT284_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT284_HANDLING */
#if defined(VX1000_EVENT285_HANDLING)
#if ((VX1000_EVENT285_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT285_HANDLING */
#define VX1000_EVENT285_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT285_HANDLING */
#if defined(VX1000_EVENT286_HANDLING)
#if ((VX1000_EVENT286_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT286_HANDLING */
#define VX1000_EVENT286_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT286_HANDLING */
#if defined(VX1000_EVENT287_HANDLING)
#if ((VX1000_EVENT287_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT287_HANDLING */
#define VX1000_EVENT287_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT287_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 280U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 288U
#if defined(VX1000_EVENT288_HANDLING)
#if ((VX1000_EVENT288_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT288_HANDLING */
#define VX1000_EVENT288_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT288_HANDLING */
#if defined(VX1000_EVENT289_HANDLING)
#if ((VX1000_EVENT289_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT289_HANDLING */
#define VX1000_EVENT289_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT289_HANDLING */
#if defined(VX1000_EVENT290_HANDLING)
#if ((VX1000_EVENT290_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT290_HANDLING */
#define VX1000_EVENT290_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT290_HANDLING */
#if defined(VX1000_EVENT291_HANDLING)
#if ((VX1000_EVENT291_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT291_HANDLING */
#define VX1000_EVENT291_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT291_HANDLING */
#if defined(VX1000_EVENT292_HANDLING)
#if ((VX1000_EVENT292_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT292_HANDLING */
#define VX1000_EVENT292_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT292_HANDLING */
#if defined(VX1000_EVENT293_HANDLING)
#if ((VX1000_EVENT293_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT293_HANDLING */
#define VX1000_EVENT293_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT293_HANDLING */
#if defined(VX1000_EVENT294_HANDLING)
#if ((VX1000_EVENT294_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT294_HANDLING */
#define VX1000_EVENT294_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT294_HANDLING */
#if defined(VX1000_EVENT295_HANDLING)
#if ((VX1000_EVENT295_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT295_HANDLING */
#define VX1000_EVENT295_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT295_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 288U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 296U
#if defined(VX1000_EVENT296_HANDLING)
#if ((VX1000_EVENT296_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT296_HANDLING */
#define VX1000_EVENT296_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT296_HANDLING */
#if defined(VX1000_EVENT297_HANDLING)
#if ((VX1000_EVENT297_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT297_HANDLING */
#define VX1000_EVENT297_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT297_HANDLING */
#if defined(VX1000_EVENT298_HANDLING)
#if ((VX1000_EVENT298_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT298_HANDLING */
#define VX1000_EVENT298_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT298_HANDLING */
#if defined(VX1000_EVENT299_HANDLING)
#if ((VX1000_EVENT299_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT299_HANDLING */
#define VX1000_EVENT299_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT299_HANDLING */
#if defined(VX1000_EVENT300_HANDLING)
#if ((VX1000_EVENT300_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT300_HANDLING */
#define VX1000_EVENT300_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT300_HANDLING */
#if defined(VX1000_EVENT301_HANDLING)
#if ((VX1000_EVENT301_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT301_HANDLING */
#define VX1000_EVENT301_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT301_HANDLING */
#if defined(VX1000_EVENT302_HANDLING)
#if ((VX1000_EVENT302_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT302_HANDLING */
#define VX1000_EVENT302_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT302_HANDLING */
#if defined(VX1000_EVENT303_HANDLING)
#if ((VX1000_EVENT303_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT303_HANDLING */
#define VX1000_EVENT303_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT303_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 296U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 304U
#if defined(VX1000_EVENT304_HANDLING)
#if ((VX1000_EVENT304_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT304_HANDLING */
#define VX1000_EVENT304_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT304_HANDLING */
#if defined(VX1000_EVENT305_HANDLING)
#if ((VX1000_EVENT305_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT305_HANDLING */
#define VX1000_EVENT305_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT305_HANDLING */
#if defined(VX1000_EVENT306_HANDLING)
#if ((VX1000_EVENT306_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT306_HANDLING */
#define VX1000_EVENT306_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT306_HANDLING */
#if defined(VX1000_EVENT307_HANDLING)
#if ((VX1000_EVENT307_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT307_HANDLING */
#define VX1000_EVENT307_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT307_HANDLING */
#if defined(VX1000_EVENT308_HANDLING)
#if ((VX1000_EVENT308_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT308_HANDLING */
#define VX1000_EVENT308_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT308_HANDLING */
#if defined(VX1000_EVENT309_HANDLING)
#if ((VX1000_EVENT309_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT309_HANDLING */
#define VX1000_EVENT309_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT309_HANDLING */
#if defined(VX1000_EVENT310_HANDLING)
#if ((VX1000_EVENT310_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT310_HANDLING */
#define VX1000_EVENT310_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT310_HANDLING */
#if defined(VX1000_EVENT311_HANDLING)
#if ((VX1000_EVENT311_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT311_HANDLING */
#define VX1000_EVENT311_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT311_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 304U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 312U
#if defined(VX1000_EVENT312_HANDLING)
#if ((VX1000_EVENT312_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT312_HANDLING */
#define VX1000_EVENT312_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT312_HANDLING */
#if defined(VX1000_EVENT313_HANDLING)
#if ((VX1000_EVENT313_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT313_HANDLING */
#define VX1000_EVENT313_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT313_HANDLING */
#if defined(VX1000_EVENT314_HANDLING)
#if ((VX1000_EVENT314_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT314_HANDLING */
#define VX1000_EVENT314_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT314_HANDLING */
#if defined(VX1000_EVENT315_HANDLING)
#if ((VX1000_EVENT315_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT315_HANDLING */
#define VX1000_EVENT315_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT315_HANDLING */
#if defined(VX1000_EVENT316_HANDLING)
#if ((VX1000_EVENT316_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT316_HANDLING */
#define VX1000_EVENT316_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT316_HANDLING */
#if defined(VX1000_EVENT317_HANDLING)
#if ((VX1000_EVENT317_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT317_HANDLING */
#define VX1000_EVENT317_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT317_HANDLING */
#if defined(VX1000_EVENT318_HANDLING)
#if ((VX1000_EVENT318_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT318_HANDLING */
#define VX1000_EVENT318_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT318_HANDLING */
#if defined(VX1000_EVENT319_HANDLING)
#if ((VX1000_EVENT319_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT319_HANDLING */
#define VX1000_EVENT319_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT319_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 312U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 320U
#if defined(VX1000_EVENT320_HANDLING)
#if ((VX1000_EVENT320_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT320_HANDLING */
#define VX1000_EVENT320_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT320_HANDLING */
#if defined(VX1000_EVENT321_HANDLING)
#if ((VX1000_EVENT321_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT321_HANDLING */
#define VX1000_EVENT321_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT321_HANDLING */
#if defined(VX1000_EVENT322_HANDLING)
#if ((VX1000_EVENT322_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT322_HANDLING */
#define VX1000_EVENT322_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT322_HANDLING */
#if defined(VX1000_EVENT323_HANDLING)
#if ((VX1000_EVENT323_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT323_HANDLING */
#define VX1000_EVENT323_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT323_HANDLING */
#if defined(VX1000_EVENT324_HANDLING)
#if ((VX1000_EVENT324_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT324_HANDLING */
#define VX1000_EVENT324_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT324_HANDLING */
#if defined(VX1000_EVENT325_HANDLING)
#if ((VX1000_EVENT325_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT325_HANDLING */
#define VX1000_EVENT325_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT325_HANDLING */
#if defined(VX1000_EVENT326_HANDLING)
#if ((VX1000_EVENT326_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT326_HANDLING */
#define VX1000_EVENT326_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT326_HANDLING */
#if defined(VX1000_EVENT327_HANDLING)
#if ((VX1000_EVENT327_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT327_HANDLING */
#define VX1000_EVENT327_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT327_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 320U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 328U
#if defined(VX1000_EVENT328_HANDLING)
#if ((VX1000_EVENT328_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT328_HANDLING */
#define VX1000_EVENT328_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT328_HANDLING */
#if defined(VX1000_EVENT329_HANDLING)
#if ((VX1000_EVENT329_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT329_HANDLING */
#define VX1000_EVENT329_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT329_HANDLING */
#if defined(VX1000_EVENT330_HANDLING)
#if ((VX1000_EVENT330_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT330_HANDLING */
#define VX1000_EVENT330_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT330_HANDLING */
#if defined(VX1000_EVENT331_HANDLING)
#if ((VX1000_EVENT331_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT331_HANDLING */
#define VX1000_EVENT331_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT331_HANDLING */
#if defined(VX1000_EVENT332_HANDLING)
#if ((VX1000_EVENT332_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT332_HANDLING */
#define VX1000_EVENT332_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT332_HANDLING */
#if defined(VX1000_EVENT333_HANDLING)
#if ((VX1000_EVENT333_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT333_HANDLING */
#define VX1000_EVENT333_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT333_HANDLING */
#if defined(VX1000_EVENT334_HANDLING)
#if ((VX1000_EVENT334_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT334_HANDLING */
#define VX1000_EVENT334_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT334_HANDLING */
#if defined(VX1000_EVENT335_HANDLING)
#if ((VX1000_EVENT335_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT335_HANDLING */
#define VX1000_EVENT335_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT335_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 328U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 336U
#if defined(VX1000_EVENT336_HANDLING)
#if ((VX1000_EVENT336_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT336_HANDLING */
#define VX1000_EVENT336_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT336_HANDLING */
#if defined(VX1000_EVENT337_HANDLING)
#if ((VX1000_EVENT337_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT337_HANDLING */
#define VX1000_EVENT337_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT337_HANDLING */
#if defined(VX1000_EVENT338_HANDLING)
#if ((VX1000_EVENT338_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT338_HANDLING */
#define VX1000_EVENT338_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT338_HANDLING */
#if defined(VX1000_EVENT339_HANDLING)
#if ((VX1000_EVENT339_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT339_HANDLING */
#define VX1000_EVENT339_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT339_HANDLING */
#if defined(VX1000_EVENT340_HANDLING)
#if ((VX1000_EVENT340_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT340_HANDLING */
#define VX1000_EVENT340_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT340_HANDLING */
#if defined(VX1000_EVENT341_HANDLING)
#if ((VX1000_EVENT341_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT341_HANDLING */
#define VX1000_EVENT341_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT341_HANDLING */
#if defined(VX1000_EVENT342_HANDLING)
#if ((VX1000_EVENT342_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT342_HANDLING */
#define VX1000_EVENT342_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT342_HANDLING */
#if defined(VX1000_EVENT343_HANDLING)
#if ((VX1000_EVENT343_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT343_HANDLING */
#define VX1000_EVENT343_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT343_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 336U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 344U
#if defined(VX1000_EVENT344_HANDLING)
#if ((VX1000_EVENT344_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT344_HANDLING */
#define VX1000_EVENT344_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT344_HANDLING */
#if defined(VX1000_EVENT345_HANDLING)
#if ((VX1000_EVENT345_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT345_HANDLING */
#define VX1000_EVENT345_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT345_HANDLING */
#if defined(VX1000_EVENT346_HANDLING)
#if ((VX1000_EVENT346_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT346_HANDLING */
#define VX1000_EVENT346_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT346_HANDLING */
#if defined(VX1000_EVENT347_HANDLING)
#if ((VX1000_EVENT347_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT347_HANDLING */
#define VX1000_EVENT347_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT347_HANDLING */
#if defined(VX1000_EVENT348_HANDLING)
#if ((VX1000_EVENT348_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT348_HANDLING */
#define VX1000_EVENT348_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT348_HANDLING */
#if defined(VX1000_EVENT349_HANDLING)
#if ((VX1000_EVENT349_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT349_HANDLING */
#define VX1000_EVENT349_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT349_HANDLING */
#if defined(VX1000_EVENT350_HANDLING)
#if ((VX1000_EVENT350_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT350_HANDLING */
#define VX1000_EVENT350_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT350_HANDLING */
#if defined(VX1000_EVENT351_HANDLING)
#if ((VX1000_EVENT351_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT351_HANDLING */
#define VX1000_EVENT351_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT351_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 344U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 352U
#if defined(VX1000_EVENT352_HANDLING)
#if ((VX1000_EVENT352_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT352_HANDLING */
#define VX1000_EVENT352_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT352_HANDLING */
#if defined(VX1000_EVENT353_HANDLING)
#if ((VX1000_EVENT353_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT353_HANDLING */
#define VX1000_EVENT353_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT353_HANDLING */
#if defined(VX1000_EVENT354_HANDLING)
#if ((VX1000_EVENT354_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT354_HANDLING */
#define VX1000_EVENT354_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT354_HANDLING */
#if defined(VX1000_EVENT355_HANDLING)
#if ((VX1000_EVENT355_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT355_HANDLING */
#define VX1000_EVENT355_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT355_HANDLING */
#if defined(VX1000_EVENT356_HANDLING)
#if ((VX1000_EVENT356_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT356_HANDLING */
#define VX1000_EVENT356_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT356_HANDLING */
#if defined(VX1000_EVENT357_HANDLING)
#if ((VX1000_EVENT357_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT357_HANDLING */
#define VX1000_EVENT357_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT357_HANDLING */
#if defined(VX1000_EVENT358_HANDLING)
#if ((VX1000_EVENT358_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT358_HANDLING */
#define VX1000_EVENT358_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT358_HANDLING */
#if defined(VX1000_EVENT359_HANDLING)
#if ((VX1000_EVENT359_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT359_HANDLING */
#define VX1000_EVENT359_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT359_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 352U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 360U
#if defined(VX1000_EVENT360_HANDLING)
#if ((VX1000_EVENT360_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT360_HANDLING */
#define VX1000_EVENT360_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT360_HANDLING */
#if defined(VX1000_EVENT361_HANDLING)
#if ((VX1000_EVENT361_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT361_HANDLING */
#define VX1000_EVENT361_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT361_HANDLING */
#if defined(VX1000_EVENT362_HANDLING)
#if ((VX1000_EVENT362_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT362_HANDLING */
#define VX1000_EVENT362_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT362_HANDLING */
#if defined(VX1000_EVENT363_HANDLING)
#if ((VX1000_EVENT363_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT363_HANDLING */
#define VX1000_EVENT363_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT363_HANDLING */
#if defined(VX1000_EVENT364_HANDLING)
#if ((VX1000_EVENT364_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT364_HANDLING */
#define VX1000_EVENT364_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT364_HANDLING */
#if defined(VX1000_EVENT365_HANDLING)
#if ((VX1000_EVENT365_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT365_HANDLING */
#define VX1000_EVENT365_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT365_HANDLING */
#if defined(VX1000_EVENT366_HANDLING)
#if ((VX1000_EVENT366_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT366_HANDLING */
#define VX1000_EVENT366_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT366_HANDLING */
#if defined(VX1000_EVENT367_HANDLING)
#if ((VX1000_EVENT367_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT367_HANDLING */
#define VX1000_EVENT367_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT367_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 360U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 368U
#if defined(VX1000_EVENT368_HANDLING)
#if ((VX1000_EVENT368_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT368_HANDLING */
#define VX1000_EVENT368_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT368_HANDLING */
#if defined(VX1000_EVENT369_HANDLING)
#if ((VX1000_EVENT369_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT369_HANDLING */
#define VX1000_EVENT369_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT369_HANDLING */
#if defined(VX1000_EVENT370_HANDLING)
#if ((VX1000_EVENT370_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT370_HANDLING */
#define VX1000_EVENT370_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT370_HANDLING */
#if defined(VX1000_EVENT371_HANDLING)
#if ((VX1000_EVENT371_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT371_HANDLING */
#define VX1000_EVENT371_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT371_HANDLING */
#if defined(VX1000_EVENT372_HANDLING)
#if ((VX1000_EVENT372_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT372_HANDLING */
#define VX1000_EVENT372_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT372_HANDLING */
#if defined(VX1000_EVENT373_HANDLING)
#if ((VX1000_EVENT373_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT373_HANDLING */
#define VX1000_EVENT373_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT373_HANDLING */
#if defined(VX1000_EVENT374_HANDLING)
#if ((VX1000_EVENT374_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT374_HANDLING */
#define VX1000_EVENT374_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT374_HANDLING */
#if defined(VX1000_EVENT375_HANDLING)
#if ((VX1000_EVENT375_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT375_HANDLING */
#define VX1000_EVENT375_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT375_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 368U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 376U
#if defined(VX1000_EVENT376_HANDLING)
#if ((VX1000_EVENT376_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT376_HANDLING */
#define VX1000_EVENT376_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT376_HANDLING */
#if defined(VX1000_EVENT377_HANDLING)
#if ((VX1000_EVENT377_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT377_HANDLING */
#define VX1000_EVENT377_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT377_HANDLING */
#if defined(VX1000_EVENT378_HANDLING)
#if ((VX1000_EVENT378_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT378_HANDLING */
#define VX1000_EVENT378_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT378_HANDLING */
#if defined(VX1000_EVENT379_HANDLING)
#if ((VX1000_EVENT379_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT379_HANDLING */
#define VX1000_EVENT379_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT379_HANDLING */
#if defined(VX1000_EVENT380_HANDLING)
#if ((VX1000_EVENT380_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT380_HANDLING */
#define VX1000_EVENT380_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT380_HANDLING */
#if defined(VX1000_EVENT381_HANDLING)
#if ((VX1000_EVENT381_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT381_HANDLING */
#define VX1000_EVENT381_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT381_HANDLING */
#if defined(VX1000_EVENT382_HANDLING)
#if ((VX1000_EVENT382_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT382_HANDLING */
#define VX1000_EVENT382_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT382_HANDLING */
#if defined(VX1000_EVENT383_HANDLING)
#if ((VX1000_EVENT383_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT383_HANDLING */
#define VX1000_EVENT383_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT383_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 376U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 384U
#if defined(VX1000_EVENT384_HANDLING)
#if ((VX1000_EVENT384_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT384_HANDLING */
#define VX1000_EVENT384_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT384_HANDLING */
#if defined(VX1000_EVENT385_HANDLING)
#if ((VX1000_EVENT385_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT385_HANDLING */
#define VX1000_EVENT385_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT385_HANDLING */
#if defined(VX1000_EVENT386_HANDLING)
#if ((VX1000_EVENT386_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT386_HANDLING */
#define VX1000_EVENT386_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT386_HANDLING */
#if defined(VX1000_EVENT387_HANDLING)
#if ((VX1000_EVENT387_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT387_HANDLING */
#define VX1000_EVENT387_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT387_HANDLING */
#if defined(VX1000_EVENT388_HANDLING)
#if ((VX1000_EVENT388_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT388_HANDLING */
#define VX1000_EVENT388_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT388_HANDLING */
#if defined(VX1000_EVENT389_HANDLING)
#if ((VX1000_EVENT389_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT389_HANDLING */
#define VX1000_EVENT389_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT389_HANDLING */
#if defined(VX1000_EVENT390_HANDLING)
#if ((VX1000_EVENT390_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT390_HANDLING */
#define VX1000_EVENT390_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT390_HANDLING */
#if defined(VX1000_EVENT391_HANDLING)
#if ((VX1000_EVENT391_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT391_HANDLING */
#define VX1000_EVENT391_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT391_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 384U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 392U
#if defined(VX1000_EVENT392_HANDLING)
#if ((VX1000_EVENT392_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT392_HANDLING */
#define VX1000_EVENT392_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT392_HANDLING */
#if defined(VX1000_EVENT393_HANDLING)
#if ((VX1000_EVENT393_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT393_HANDLING */
#define VX1000_EVENT393_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT393_HANDLING */
#if defined(VX1000_EVENT394_HANDLING)
#if ((VX1000_EVENT394_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT394_HANDLING */
#define VX1000_EVENT394_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT394_HANDLING */
#if defined(VX1000_EVENT395_HANDLING)
#if ((VX1000_EVENT395_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT395_HANDLING */
#define VX1000_EVENT395_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT395_HANDLING */
#if defined(VX1000_EVENT396_HANDLING)
#if ((VX1000_EVENT396_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT396_HANDLING */
#define VX1000_EVENT396_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT396_HANDLING */
#if defined(VX1000_EVENT397_HANDLING)
#if ((VX1000_EVENT397_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT397_HANDLING */
#define VX1000_EVENT397_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT397_HANDLING */
#if defined(VX1000_EVENT398_HANDLING)
#if ((VX1000_EVENT398_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT398_HANDLING */
#define VX1000_EVENT398_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT398_HANDLING */
#if defined(VX1000_EVENT399_HANDLING)
#if ((VX1000_EVENT399_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT399_HANDLING */
#define VX1000_EVENT399_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT399_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 392U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 400U
#if defined(VX1000_EVENT400_HANDLING)
#if ((VX1000_EVENT400_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT400_HANDLING */
#define VX1000_EVENT400_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT400_HANDLING */
#if defined(VX1000_EVENT401_HANDLING)
#if ((VX1000_EVENT401_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT401_HANDLING */
#define VX1000_EVENT401_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT401_HANDLING */
#if defined(VX1000_EVENT402_HANDLING)
#if ((VX1000_EVENT402_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT402_HANDLING */
#define VX1000_EVENT402_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT402_HANDLING */
#if defined(VX1000_EVENT403_HANDLING)
#if ((VX1000_EVENT403_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT403_HANDLING */
#define VX1000_EVENT403_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT403_HANDLING */
#if defined(VX1000_EVENT404_HANDLING)
#if ((VX1000_EVENT404_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT404_HANDLING */
#define VX1000_EVENT404_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT404_HANDLING */
#if defined(VX1000_EVENT405_HANDLING)
#if ((VX1000_EVENT405_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT405_HANDLING */
#define VX1000_EVENT405_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT405_HANDLING */
#if defined(VX1000_EVENT406_HANDLING)
#if ((VX1000_EVENT406_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT406_HANDLING */
#define VX1000_EVENT406_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT406_HANDLING */
#if defined(VX1000_EVENT407_HANDLING)
#if ((VX1000_EVENT407_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT407_HANDLING */
#define VX1000_EVENT407_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT407_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 400U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 408U
#if defined(VX1000_EVENT408_HANDLING)
#if ((VX1000_EVENT408_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT408_HANDLING */
#define VX1000_EVENT408_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT408_HANDLING */
#if defined(VX1000_EVENT409_HANDLING)
#if ((VX1000_EVENT409_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT409_HANDLING */
#define VX1000_EVENT409_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT409_HANDLING */
#if defined(VX1000_EVENT410_HANDLING)
#if ((VX1000_EVENT410_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT410_HANDLING */
#define VX1000_EVENT410_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT410_HANDLING */
#if defined(VX1000_EVENT411_HANDLING)
#if ((VX1000_EVENT411_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT411_HANDLING */
#define VX1000_EVENT411_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT411_HANDLING */
#if defined(VX1000_EVENT412_HANDLING)
#if ((VX1000_EVENT412_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT412_HANDLING */
#define VX1000_EVENT412_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT412_HANDLING */
#if defined(VX1000_EVENT413_HANDLING)
#if ((VX1000_EVENT413_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT413_HANDLING */
#define VX1000_EVENT413_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT413_HANDLING */
#if defined(VX1000_EVENT414_HANDLING)
#if ((VX1000_EVENT414_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT414_HANDLING */
#define VX1000_EVENT414_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT414_HANDLING */
#if defined(VX1000_EVENT415_HANDLING)
#if ((VX1000_EVENT415_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT415_HANDLING */
#define VX1000_EVENT415_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT415_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 408U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 416U
#if defined(VX1000_EVENT416_HANDLING)
#if ((VX1000_EVENT416_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT416_HANDLING */
#define VX1000_EVENT416_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT416_HANDLING */
#if defined(VX1000_EVENT417_HANDLING)
#if ((VX1000_EVENT417_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT417_HANDLING */
#define VX1000_EVENT417_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT417_HANDLING */
#if defined(VX1000_EVENT418_HANDLING)
#if ((VX1000_EVENT418_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT418_HANDLING */
#define VX1000_EVENT418_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT418_HANDLING */
#if defined(VX1000_EVENT419_HANDLING)
#if ((VX1000_EVENT419_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT419_HANDLING */
#define VX1000_EVENT419_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT419_HANDLING */
#if defined(VX1000_EVENT420_HANDLING)
#if ((VX1000_EVENT420_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT420_HANDLING */
#define VX1000_EVENT420_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT420_HANDLING */
#if defined(VX1000_EVENT421_HANDLING)
#if ((VX1000_EVENT421_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT421_HANDLING */
#define VX1000_EVENT421_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT421_HANDLING */
#if defined(VX1000_EVENT422_HANDLING)
#if ((VX1000_EVENT422_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT422_HANDLING */
#define VX1000_EVENT422_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT422_HANDLING */
#if defined(VX1000_EVENT423_HANDLING)
#if ((VX1000_EVENT423_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT423_HANDLING */
#define VX1000_EVENT423_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT423_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 416U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 424U
#if defined(VX1000_EVENT424_HANDLING)
#if ((VX1000_EVENT424_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT424_HANDLING */
#define VX1000_EVENT424_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT424_HANDLING */
#if defined(VX1000_EVENT425_HANDLING)
#if ((VX1000_EVENT425_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT425_HANDLING */
#define VX1000_EVENT425_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT425_HANDLING */
#if defined(VX1000_EVENT426_HANDLING)
#if ((VX1000_EVENT426_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT426_HANDLING */
#define VX1000_EVENT426_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT426_HANDLING */
#if defined(VX1000_EVENT427_HANDLING)
#if ((VX1000_EVENT427_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT427_HANDLING */
#define VX1000_EVENT427_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT427_HANDLING */
#if defined(VX1000_EVENT428_HANDLING)
#if ((VX1000_EVENT428_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT428_HANDLING */
#define VX1000_EVENT428_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT428_HANDLING */
#if defined(VX1000_EVENT429_HANDLING)
#if ((VX1000_EVENT429_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT429_HANDLING */
#define VX1000_EVENT429_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT429_HANDLING */
#if defined(VX1000_EVENT430_HANDLING)
#if ((VX1000_EVENT430_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT430_HANDLING */
#define VX1000_EVENT430_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT430_HANDLING */
#if defined(VX1000_EVENT431_HANDLING)
#if ((VX1000_EVENT431_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT431_HANDLING */
#define VX1000_EVENT431_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT431_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 424U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 432U
#if defined(VX1000_EVENT432_HANDLING)
#if ((VX1000_EVENT432_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT432_HANDLING */
#define VX1000_EVENT432_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT432_HANDLING */
#if defined(VX1000_EVENT433_HANDLING)
#if ((VX1000_EVENT433_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT433_HANDLING */
#define VX1000_EVENT433_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT433_HANDLING */
#if defined(VX1000_EVENT434_HANDLING)
#if ((VX1000_EVENT434_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT434_HANDLING */
#define VX1000_EVENT434_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT434_HANDLING */
#if defined(VX1000_EVENT435_HANDLING)
#if ((VX1000_EVENT435_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT435_HANDLING */
#define VX1000_EVENT435_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT435_HANDLING */
#if defined(VX1000_EVENT436_HANDLING)
#if ((VX1000_EVENT436_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT436_HANDLING */
#define VX1000_EVENT436_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT436_HANDLING */
#if defined(VX1000_EVENT437_HANDLING)
#if ((VX1000_EVENT437_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT437_HANDLING */
#define VX1000_EVENT437_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT437_HANDLING */
#if defined(VX1000_EVENT438_HANDLING)
#if ((VX1000_EVENT438_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT438_HANDLING */
#define VX1000_EVENT438_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT438_HANDLING */
#if defined(VX1000_EVENT439_HANDLING)
#if ((VX1000_EVENT439_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT439_HANDLING */
#define VX1000_EVENT439_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT439_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 432U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 440U
#if defined(VX1000_EVENT440_HANDLING)
#if ((VX1000_EVENT440_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT440_HANDLING */
#define VX1000_EVENT440_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT440_HANDLING */
#if defined(VX1000_EVENT441_HANDLING)
#if ((VX1000_EVENT441_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT441_HANDLING */
#define VX1000_EVENT441_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT441_HANDLING */
#if defined(VX1000_EVENT442_HANDLING)
#if ((VX1000_EVENT442_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT442_HANDLING */
#define VX1000_EVENT442_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT442_HANDLING */
#if defined(VX1000_EVENT443_HANDLING)
#if ((VX1000_EVENT443_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT443_HANDLING */
#define VX1000_EVENT443_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT443_HANDLING */
#if defined(VX1000_EVENT444_HANDLING)
#if ((VX1000_EVENT444_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT444_HANDLING */
#define VX1000_EVENT444_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT444_HANDLING */
#if defined(VX1000_EVENT445_HANDLING)
#if ((VX1000_EVENT445_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT445_HANDLING */
#define VX1000_EVENT445_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT445_HANDLING */
#if defined(VX1000_EVENT446_HANDLING)
#if ((VX1000_EVENT446_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT446_HANDLING */
#define VX1000_EVENT446_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT446_HANDLING */
#if defined(VX1000_EVENT447_HANDLING)
#if ((VX1000_EVENT447_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT447_HANDLING */
#define VX1000_EVENT447_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT447_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 440U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 448U
#if defined(VX1000_EVENT448_HANDLING)
#if ((VX1000_EVENT448_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT448_HANDLING */
#define VX1000_EVENT448_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT448_HANDLING */
#if defined(VX1000_EVENT449_HANDLING)
#if ((VX1000_EVENT449_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT449_HANDLING */
#define VX1000_EVENT449_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT449_HANDLING */
#if defined(VX1000_EVENT450_HANDLING)
#if ((VX1000_EVENT450_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT450_HANDLING */
#define VX1000_EVENT450_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT450_HANDLING */
#if defined(VX1000_EVENT451_HANDLING)
#if ((VX1000_EVENT451_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT451_HANDLING */
#define VX1000_EVENT451_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT451_HANDLING */
#if defined(VX1000_EVENT452_HANDLING)
#if ((VX1000_EVENT452_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT452_HANDLING */
#define VX1000_EVENT452_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT452_HANDLING */
#if defined(VX1000_EVENT453_HANDLING)
#if ((VX1000_EVENT453_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT453_HANDLING */
#define VX1000_EVENT453_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT453_HANDLING */
#if defined(VX1000_EVENT454_HANDLING)
#if ((VX1000_EVENT454_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT454_HANDLING */
#define VX1000_EVENT454_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT454_HANDLING */
#if defined(VX1000_EVENT455_HANDLING)
#if ((VX1000_EVENT455_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT455_HANDLING */
#define VX1000_EVENT455_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT455_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 448U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 456U
#if defined(VX1000_EVENT456_HANDLING)
#if ((VX1000_EVENT456_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT456_HANDLING */
#define VX1000_EVENT456_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT456_HANDLING */
#if defined(VX1000_EVENT457_HANDLING)
#if ((VX1000_EVENT457_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT457_HANDLING */
#define VX1000_EVENT457_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT457_HANDLING */
#if defined(VX1000_EVENT458_HANDLING)
#if ((VX1000_EVENT458_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT458_HANDLING */
#define VX1000_EVENT458_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT458_HANDLING */
#if defined(VX1000_EVENT459_HANDLING)
#if ((VX1000_EVENT459_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT459_HANDLING */
#define VX1000_EVENT459_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT459_HANDLING */
#if defined(VX1000_EVENT460_HANDLING)
#if ((VX1000_EVENT460_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT460_HANDLING */
#define VX1000_EVENT460_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT460_HANDLING */
#if defined(VX1000_EVENT461_HANDLING)
#if ((VX1000_EVENT461_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT461_HANDLING */
#define VX1000_EVENT461_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT461_HANDLING */
#if defined(VX1000_EVENT462_HANDLING)
#if ((VX1000_EVENT462_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT462_HANDLING */
#define VX1000_EVENT462_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT462_HANDLING */
#if defined(VX1000_EVENT463_HANDLING)
#if ((VX1000_EVENT463_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT463_HANDLING */
#define VX1000_EVENT463_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT463_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 456U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 464U
#if defined(VX1000_EVENT464_HANDLING)
#if ((VX1000_EVENT464_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT464_HANDLING */
#define VX1000_EVENT464_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT464_HANDLING */
#if defined(VX1000_EVENT465_HANDLING)
#if ((VX1000_EVENT465_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT465_HANDLING */
#define VX1000_EVENT465_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT465_HANDLING */
#if defined(VX1000_EVENT466_HANDLING)
#if ((VX1000_EVENT466_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT466_HANDLING */
#define VX1000_EVENT466_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT466_HANDLING */
#if defined(VX1000_EVENT467_HANDLING)
#if ((VX1000_EVENT467_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT467_HANDLING */
#define VX1000_EVENT467_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT467_HANDLING */
#if defined(VX1000_EVENT468_HANDLING)
#if ((VX1000_EVENT468_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT468_HANDLING */
#define VX1000_EVENT468_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT468_HANDLING */
#if defined(VX1000_EVENT469_HANDLING)
#if ((VX1000_EVENT469_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT469_HANDLING */
#define VX1000_EVENT469_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT469_HANDLING */
#if defined(VX1000_EVENT470_HANDLING)
#if ((VX1000_EVENT470_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT470_HANDLING */
#define VX1000_EVENT470_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT470_HANDLING */
#if defined(VX1000_EVENT471_HANDLING)
#if ((VX1000_EVENT471_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT471_HANDLING */
#define VX1000_EVENT471_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT471_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 464U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 472U
#if defined(VX1000_EVENT472_HANDLING)
#if ((VX1000_EVENT472_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT472_HANDLING */
#define VX1000_EVENT472_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT472_HANDLING */
#if defined(VX1000_EVENT473_HANDLING)
#if ((VX1000_EVENT473_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT473_HANDLING */
#define VX1000_EVENT473_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT473_HANDLING */
#if defined(VX1000_EVENT474_HANDLING)
#if ((VX1000_EVENT474_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT474_HANDLING */
#define VX1000_EVENT474_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT474_HANDLING */
#if defined(VX1000_EVENT475_HANDLING)
#if ((VX1000_EVENT475_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT475_HANDLING */
#define VX1000_EVENT475_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT475_HANDLING */
#if defined(VX1000_EVENT476_HANDLING)
#if ((VX1000_EVENT476_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT476_HANDLING */
#define VX1000_EVENT476_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT476_HANDLING */
#if defined(VX1000_EVENT477_HANDLING)
#if ((VX1000_EVENT477_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT477_HANDLING */
#define VX1000_EVENT477_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT477_HANDLING */
#if defined(VX1000_EVENT478_HANDLING)
#if ((VX1000_EVENT478_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT478_HANDLING */
#define VX1000_EVENT478_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT478_HANDLING */
#if defined(VX1000_EVENT479_HANDLING)
#if ((VX1000_EVENT479_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT479_HANDLING */
#define VX1000_EVENT479_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT479_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 472U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 480U
#if defined(VX1000_EVENT480_HANDLING)
#if ((VX1000_EVENT480_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT480_HANDLING */
#define VX1000_EVENT480_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT480_HANDLING */
#if defined(VX1000_EVENT481_HANDLING)
#if ((VX1000_EVENT481_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT481_HANDLING */
#define VX1000_EVENT481_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT481_HANDLING */
#if defined(VX1000_EVENT482_HANDLING)
#if ((VX1000_EVENT482_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT482_HANDLING */
#define VX1000_EVENT482_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT482_HANDLING */
#if defined(VX1000_EVENT483_HANDLING)
#if ((VX1000_EVENT483_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT483_HANDLING */
#define VX1000_EVENT483_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT483_HANDLING */
#if defined(VX1000_EVENT484_HANDLING)
#if ((VX1000_EVENT484_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT484_HANDLING */
#define VX1000_EVENT484_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT484_HANDLING */
#if defined(VX1000_EVENT485_HANDLING)
#if ((VX1000_EVENT485_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT485_HANDLING */
#define VX1000_EVENT485_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT485_HANDLING */
#if defined(VX1000_EVENT486_HANDLING)
#if ((VX1000_EVENT486_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT486_HANDLING */
#define VX1000_EVENT486_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT486_HANDLING */
#if defined(VX1000_EVENT487_HANDLING)
#if ((VX1000_EVENT487_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT487_HANDLING */
#define VX1000_EVENT487_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT487_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 480U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 488U
#if defined(VX1000_EVENT488_HANDLING)
#if ((VX1000_EVENT488_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT488_HANDLING */
#define VX1000_EVENT488_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT488_HANDLING */
#if defined(VX1000_EVENT489_HANDLING)
#if ((VX1000_EVENT489_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT489_HANDLING */
#define VX1000_EVENT489_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT489_HANDLING */
#if defined(VX1000_EVENT490_HANDLING)
#if ((VX1000_EVENT490_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT490_HANDLING */
#define VX1000_EVENT490_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT490_HANDLING */
#if defined(VX1000_EVENT491_HANDLING)
#if ((VX1000_EVENT491_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT491_HANDLING */
#define VX1000_EVENT491_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT491_HANDLING */
#if defined(VX1000_EVENT492_HANDLING)
#if ((VX1000_EVENT492_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT492_HANDLING */
#define VX1000_EVENT492_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT492_HANDLING */
#if defined(VX1000_EVENT493_HANDLING)
#if ((VX1000_EVENT493_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT493_HANDLING */
#define VX1000_EVENT493_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT493_HANDLING */
#if defined(VX1000_EVENT494_HANDLING)
#if ((VX1000_EVENT494_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT494_HANDLING */
#define VX1000_EVENT494_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT494_HANDLING */
#if defined(VX1000_EVENT495_HANDLING)
#if ((VX1000_EVENT495_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT495_HANDLING */
#define VX1000_EVENT495_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT495_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 488U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 496U
#if defined(VX1000_EVENT496_HANDLING)
#if ((VX1000_EVENT496_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT496_HANDLING */
#define VX1000_EVENT496_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT496_HANDLING */
#if defined(VX1000_EVENT497_HANDLING)
#if ((VX1000_EVENT497_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT497_HANDLING */
#define VX1000_EVENT497_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT497_HANDLING */
#if defined(VX1000_EVENT498_HANDLING)
#if ((VX1000_EVENT498_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT498_HANDLING */
#define VX1000_EVENT498_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT498_HANDLING */
#if defined(VX1000_EVENT499_HANDLING)
#if ((VX1000_EVENT499_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT499_HANDLING */
#define VX1000_EVENT499_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT499_HANDLING */
#if defined(VX1000_EVENT500_HANDLING)
#if ((VX1000_EVENT500_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT500_HANDLING */
#define VX1000_EVENT500_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT500_HANDLING */
#if defined(VX1000_EVENT501_HANDLING)
#if ((VX1000_EVENT501_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT501_HANDLING */
#define VX1000_EVENT501_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT501_HANDLING */
#if defined(VX1000_EVENT502_HANDLING)
#if ((VX1000_EVENT502_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT502_HANDLING */
#define VX1000_EVENT502_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT502_HANDLING */
#if defined(VX1000_EVENT503_HANDLING)
#if ((VX1000_EVENT503_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT503_HANDLING */
#define VX1000_EVENT503_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT503_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 496U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 504U
#if defined(VX1000_EVENT504_HANDLING)
#if ((VX1000_EVENT504_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT504_HANDLING */
#define VX1000_EVENT504_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT504_HANDLING */
#if defined(VX1000_EVENT505_HANDLING)
#if ((VX1000_EVENT505_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT505_HANDLING */
#define VX1000_EVENT505_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT505_HANDLING */
#if defined(VX1000_EVENT506_HANDLING)
#if ((VX1000_EVENT506_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT506_HANDLING */
#define VX1000_EVENT506_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT506_HANDLING */
#if defined(VX1000_EVENT507_HANDLING)
#if ((VX1000_EVENT507_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT507_HANDLING */
#define VX1000_EVENT507_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT507_HANDLING */
#if defined(VX1000_EVENT508_HANDLING)
#if ((VX1000_EVENT508_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT508_HANDLING */
#define VX1000_EVENT508_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT508_HANDLING */
#if defined(VX1000_EVENT509_HANDLING)
#if ((VX1000_EVENT509_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT509_HANDLING */
#define VX1000_EVENT509_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT509_HANDLING */
#if defined(VX1000_EVENT510_HANDLING)
#if ((VX1000_EVENT510_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT510_HANDLING */
#define VX1000_EVENT510_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT510_HANDLING */
#if defined(VX1000_EVENT511_HANDLING)
#if ((VX1000_EVENT511_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT511_HANDLING */
#define VX1000_EVENT511_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT511_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 504U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 512U
#if defined(VX1000_EVENT512_HANDLING)
#if ((VX1000_EVENT512_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT512_HANDLING */
#define VX1000_EVENT512_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT512_HANDLING */
#if defined(VX1000_EVENT513_HANDLING)
#if ((VX1000_EVENT513_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT513_HANDLING */
#define VX1000_EVENT513_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT513_HANDLING */
#if defined(VX1000_EVENT514_HANDLING)
#if ((VX1000_EVENT514_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT514_HANDLING */
#define VX1000_EVENT514_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT514_HANDLING */
#if defined(VX1000_EVENT515_HANDLING)
#if ((VX1000_EVENT515_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT515_HANDLING */
#define VX1000_EVENT515_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT515_HANDLING */
#if defined(VX1000_EVENT516_HANDLING)
#if ((VX1000_EVENT516_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT516_HANDLING */
#define VX1000_EVENT516_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT516_HANDLING */
#if defined(VX1000_EVENT517_HANDLING)
#if ((VX1000_EVENT517_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT517_HANDLING */
#define VX1000_EVENT517_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT517_HANDLING */
#if defined(VX1000_EVENT518_HANDLING)
#if ((VX1000_EVENT518_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT518_HANDLING */
#define VX1000_EVENT518_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT518_HANDLING */
#if defined(VX1000_EVENT519_HANDLING)
#if ((VX1000_EVENT519_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT519_HANDLING */
#define VX1000_EVENT519_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT519_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 512U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 520U
#if defined(VX1000_EVENT520_HANDLING)
#if ((VX1000_EVENT520_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT520_HANDLING */
#define VX1000_EVENT520_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT520_HANDLING */
#if defined(VX1000_EVENT521_HANDLING)
#if ((VX1000_EVENT521_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT521_HANDLING */
#define VX1000_EVENT521_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT521_HANDLING */
#if defined(VX1000_EVENT522_HANDLING)
#if ((VX1000_EVENT522_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT522_HANDLING */
#define VX1000_EVENT522_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT522_HANDLING */
#if defined(VX1000_EVENT523_HANDLING)
#if ((VX1000_EVENT523_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT523_HANDLING */
#define VX1000_EVENT523_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT523_HANDLING */
#if defined(VX1000_EVENT524_HANDLING)
#if ((VX1000_EVENT524_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT524_HANDLING */
#define VX1000_EVENT524_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT524_HANDLING */
#if defined(VX1000_EVENT525_HANDLING)
#if ((VX1000_EVENT525_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT525_HANDLING */
#define VX1000_EVENT525_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT525_HANDLING */
#if defined(VX1000_EVENT526_HANDLING)
#if ((VX1000_EVENT526_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT526_HANDLING */
#define VX1000_EVENT526_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT526_HANDLING */
#if defined(VX1000_EVENT527_HANDLING)
#if ((VX1000_EVENT527_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT527_HANDLING */
#define VX1000_EVENT527_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT527_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 520U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 528U
#if defined(VX1000_EVENT528_HANDLING)
#if ((VX1000_EVENT528_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT528_HANDLING */
#define VX1000_EVENT528_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT528_HANDLING */
#if defined(VX1000_EVENT529_HANDLING)
#if ((VX1000_EVENT529_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT529_HANDLING */
#define VX1000_EVENT529_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT529_HANDLING */
#if defined(VX1000_EVENT530_HANDLING)
#if ((VX1000_EVENT530_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT530_HANDLING */
#define VX1000_EVENT530_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT530_HANDLING */
#if defined(VX1000_EVENT531_HANDLING)
#if ((VX1000_EVENT531_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT531_HANDLING */
#define VX1000_EVENT531_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT531_HANDLING */
#if defined(VX1000_EVENT532_HANDLING)
#if ((VX1000_EVENT532_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT532_HANDLING */
#define VX1000_EVENT532_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT532_HANDLING */
#if defined(VX1000_EVENT533_HANDLING)
#if ((VX1000_EVENT533_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT533_HANDLING */
#define VX1000_EVENT533_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT533_HANDLING */
#if defined(VX1000_EVENT534_HANDLING)
#if ((VX1000_EVENT534_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT534_HANDLING */
#define VX1000_EVENT534_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT534_HANDLING */
#if defined(VX1000_EVENT535_HANDLING)
#if ((VX1000_EVENT535_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT535_HANDLING */
#define VX1000_EVENT535_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT535_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 528U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 536U
#if defined(VX1000_EVENT536_HANDLING)
#if ((VX1000_EVENT536_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT536_HANDLING */
#define VX1000_EVENT536_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT536_HANDLING */
#if defined(VX1000_EVENT537_HANDLING)
#if ((VX1000_EVENT537_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT537_HANDLING */
#define VX1000_EVENT537_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT537_HANDLING */
#if defined(VX1000_EVENT538_HANDLING)
#if ((VX1000_EVENT538_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT538_HANDLING */
#define VX1000_EVENT538_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT538_HANDLING */
#if defined(VX1000_EVENT539_HANDLING)
#if ((VX1000_EVENT539_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT539_HANDLING */
#define VX1000_EVENT539_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT539_HANDLING */
#if defined(VX1000_EVENT540_HANDLING)
#if ((VX1000_EVENT540_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT540_HANDLING */
#define VX1000_EVENT540_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT540_HANDLING */
#if defined(VX1000_EVENT541_HANDLING)
#if ((VX1000_EVENT541_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT541_HANDLING */
#define VX1000_EVENT541_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT541_HANDLING */
#if defined(VX1000_EVENT542_HANDLING)
#if ((VX1000_EVENT542_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT542_HANDLING */
#define VX1000_EVENT542_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT542_HANDLING */
#if defined(VX1000_EVENT543_HANDLING)
#if ((VX1000_EVENT543_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT543_HANDLING */
#define VX1000_EVENT543_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT543_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 536U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 544U
#if defined(VX1000_EVENT544_HANDLING)
#if ((VX1000_EVENT544_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT544_HANDLING */
#define VX1000_EVENT544_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT544_HANDLING */
#if defined(VX1000_EVENT545_HANDLING)
#if ((VX1000_EVENT545_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT545_HANDLING */
#define VX1000_EVENT545_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT545_HANDLING */
#if defined(VX1000_EVENT546_HANDLING)
#if ((VX1000_EVENT546_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT546_HANDLING */
#define VX1000_EVENT546_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT546_HANDLING */
#if defined(VX1000_EVENT547_HANDLING)
#if ((VX1000_EVENT547_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT547_HANDLING */
#define VX1000_EVENT547_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT547_HANDLING */
#if defined(VX1000_EVENT548_HANDLING)
#if ((VX1000_EVENT548_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT548_HANDLING */
#define VX1000_EVENT548_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT548_HANDLING */
#if defined(VX1000_EVENT549_HANDLING)
#if ((VX1000_EVENT549_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT549_HANDLING */
#define VX1000_EVENT549_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT549_HANDLING */
#if defined(VX1000_EVENT550_HANDLING)
#if ((VX1000_EVENT550_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT550_HANDLING */
#define VX1000_EVENT550_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT550_HANDLING */
#if defined(VX1000_EVENT551_HANDLING)
#if ((VX1000_EVENT551_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT551_HANDLING */
#define VX1000_EVENT551_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT551_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 544U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 552U
#if defined(VX1000_EVENT552_HANDLING)
#if ((VX1000_EVENT552_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT552_HANDLING */
#define VX1000_EVENT552_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT552_HANDLING */
#if defined(VX1000_EVENT553_HANDLING)
#if ((VX1000_EVENT553_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT553_HANDLING */
#define VX1000_EVENT553_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT553_HANDLING */
#if defined(VX1000_EVENT554_HANDLING)
#if ((VX1000_EVENT554_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT554_HANDLING */
#define VX1000_EVENT554_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT554_HANDLING */
#if defined(VX1000_EVENT555_HANDLING)
#if ((VX1000_EVENT555_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT555_HANDLING */
#define VX1000_EVENT555_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT555_HANDLING */
#if defined(VX1000_EVENT556_HANDLING)
#if ((VX1000_EVENT556_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT556_HANDLING */
#define VX1000_EVENT556_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT556_HANDLING */
#if defined(VX1000_EVENT557_HANDLING)
#if ((VX1000_EVENT557_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT557_HANDLING */
#define VX1000_EVENT557_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT557_HANDLING */
#if defined(VX1000_EVENT558_HANDLING)
#if ((VX1000_EVENT558_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT558_HANDLING */
#define VX1000_EVENT558_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT558_HANDLING */
#if defined(VX1000_EVENT559_HANDLING)
#if ((VX1000_EVENT559_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT559_HANDLING */
#define VX1000_EVENT559_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT559_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 552U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 560U
#if defined(VX1000_EVENT560_HANDLING)
#if ((VX1000_EVENT560_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT560_HANDLING */
#define VX1000_EVENT560_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT560_HANDLING */
#if defined(VX1000_EVENT561_HANDLING)
#if ((VX1000_EVENT561_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT561_HANDLING */
#define VX1000_EVENT561_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT561_HANDLING */
#if defined(VX1000_EVENT562_HANDLING)
#if ((VX1000_EVENT562_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT562_HANDLING */
#define VX1000_EVENT562_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT562_HANDLING */
#if defined(VX1000_EVENT563_HANDLING)
#if ((VX1000_EVENT563_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT563_HANDLING */
#define VX1000_EVENT563_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT563_HANDLING */
#if defined(VX1000_EVENT564_HANDLING)
#if ((VX1000_EVENT564_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT564_HANDLING */
#define VX1000_EVENT564_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT564_HANDLING */
#if defined(VX1000_EVENT565_HANDLING)
#if ((VX1000_EVENT565_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT565_HANDLING */
#define VX1000_EVENT565_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT565_HANDLING */
#if defined(VX1000_EVENT566_HANDLING)
#if ((VX1000_EVENT566_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT566_HANDLING */
#define VX1000_EVENT566_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT566_HANDLING */
#if defined(VX1000_EVENT567_HANDLING)
#if ((VX1000_EVENT567_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT567_HANDLING */
#define VX1000_EVENT567_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT567_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 560U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 568U
#if defined(VX1000_EVENT568_HANDLING)
#if ((VX1000_EVENT568_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT568_HANDLING */
#define VX1000_EVENT568_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT568_HANDLING */
#if defined(VX1000_EVENT569_HANDLING)
#if ((VX1000_EVENT569_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT569_HANDLING */
#define VX1000_EVENT569_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT569_HANDLING */
#if defined(VX1000_EVENT570_HANDLING)
#if ((VX1000_EVENT570_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT570_HANDLING */
#define VX1000_EVENT570_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT570_HANDLING */
#if defined(VX1000_EVENT571_HANDLING)
#if ((VX1000_EVENT571_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT571_HANDLING */
#define VX1000_EVENT571_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT571_HANDLING */
#if defined(VX1000_EVENT572_HANDLING)
#if ((VX1000_EVENT572_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT572_HANDLING */
#define VX1000_EVENT572_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT572_HANDLING */
#if defined(VX1000_EVENT573_HANDLING)
#if ((VX1000_EVENT573_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT573_HANDLING */
#define VX1000_EVENT573_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT573_HANDLING */
#if defined(VX1000_EVENT574_HANDLING)
#if ((VX1000_EVENT574_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT574_HANDLING */
#define VX1000_EVENT574_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT574_HANDLING */
#if defined(VX1000_EVENT575_HANDLING)
#if ((VX1000_EVENT575_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT575_HANDLING */
#define VX1000_EVENT575_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT575_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 568U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 576U
#if defined(VX1000_EVENT576_HANDLING)
#if ((VX1000_EVENT576_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT576_HANDLING */
#define VX1000_EVENT576_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT576_HANDLING */
#if defined(VX1000_EVENT577_HANDLING)
#if ((VX1000_EVENT577_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT577_HANDLING */
#define VX1000_EVENT577_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT577_HANDLING */
#if defined(VX1000_EVENT578_HANDLING)
#if ((VX1000_EVENT578_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT578_HANDLING */
#define VX1000_EVENT578_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT578_HANDLING */
#if defined(VX1000_EVENT579_HANDLING)
#if ((VX1000_EVENT579_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT579_HANDLING */
#define VX1000_EVENT579_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT579_HANDLING */
#if defined(VX1000_EVENT580_HANDLING)
#if ((VX1000_EVENT580_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT580_HANDLING */
#define VX1000_EVENT580_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT580_HANDLING */
#if defined(VX1000_EVENT581_HANDLING)
#if ((VX1000_EVENT581_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT581_HANDLING */
#define VX1000_EVENT581_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT581_HANDLING */
#if defined(VX1000_EVENT582_HANDLING)
#if ((VX1000_EVENT582_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT582_HANDLING */
#define VX1000_EVENT582_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT582_HANDLING */
#if defined(VX1000_EVENT583_HANDLING)
#if ((VX1000_EVENT583_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT583_HANDLING */
#define VX1000_EVENT583_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT583_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 576U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 584U
#if defined(VX1000_EVENT584_HANDLING)
#if ((VX1000_EVENT584_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT584_HANDLING */
#define VX1000_EVENT584_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT584_HANDLING */
#if defined(VX1000_EVENT585_HANDLING)
#if ((VX1000_EVENT585_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT585_HANDLING */
#define VX1000_EVENT585_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT585_HANDLING */
#if defined(VX1000_EVENT586_HANDLING)
#if ((VX1000_EVENT586_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT586_HANDLING */
#define VX1000_EVENT586_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT586_HANDLING */
#if defined(VX1000_EVENT587_HANDLING)
#if ((VX1000_EVENT587_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT587_HANDLING */
#define VX1000_EVENT587_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT587_HANDLING */
#if defined(VX1000_EVENT588_HANDLING)
#if ((VX1000_EVENT588_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT588_HANDLING */
#define VX1000_EVENT588_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT588_HANDLING */
#if defined(VX1000_EVENT589_HANDLING)
#if ((VX1000_EVENT589_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT589_HANDLING */
#define VX1000_EVENT589_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT589_HANDLING */
#if defined(VX1000_EVENT590_HANDLING)
#if ((VX1000_EVENT590_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT590_HANDLING */
#define VX1000_EVENT590_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT590_HANDLING */
#if defined(VX1000_EVENT591_HANDLING)
#if ((VX1000_EVENT591_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT591_HANDLING */
#define VX1000_EVENT591_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT591_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 584U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 592U
#if defined(VX1000_EVENT592_HANDLING)
#if ((VX1000_EVENT592_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT592_HANDLING */
#define VX1000_EVENT592_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT592_HANDLING */
#if defined(VX1000_EVENT593_HANDLING)
#if ((VX1000_EVENT593_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT593_HANDLING */
#define VX1000_EVENT593_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT593_HANDLING */
#if defined(VX1000_EVENT594_HANDLING)
#if ((VX1000_EVENT594_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT594_HANDLING */
#define VX1000_EVENT594_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT594_HANDLING */
#if defined(VX1000_EVENT595_HANDLING)
#if ((VX1000_EVENT595_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT595_HANDLING */
#define VX1000_EVENT595_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT595_HANDLING */
#if defined(VX1000_EVENT596_HANDLING)
#if ((VX1000_EVENT596_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT596_HANDLING */
#define VX1000_EVENT596_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT596_HANDLING */
#if defined(VX1000_EVENT597_HANDLING)
#if ((VX1000_EVENT597_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT597_HANDLING */
#define VX1000_EVENT597_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT597_HANDLING */
#if defined(VX1000_EVENT598_HANDLING)
#if ((VX1000_EVENT598_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT598_HANDLING */
#define VX1000_EVENT598_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT598_HANDLING */
#if defined(VX1000_EVENT599_HANDLING)
#if ((VX1000_EVENT599_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT599_HANDLING */
#define VX1000_EVENT599_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT599_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 592U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 600U
#if defined(VX1000_EVENT600_HANDLING)
#if ((VX1000_EVENT600_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT600_HANDLING */
#define VX1000_EVENT600_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT600_HANDLING */
#if defined(VX1000_EVENT601_HANDLING)
#if ((VX1000_EVENT601_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT601_HANDLING */
#define VX1000_EVENT601_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT601_HANDLING */
#if defined(VX1000_EVENT602_HANDLING)
#if ((VX1000_EVENT602_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT602_HANDLING */
#define VX1000_EVENT602_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT602_HANDLING */
#if defined(VX1000_EVENT603_HANDLING)
#if ((VX1000_EVENT603_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT603_HANDLING */
#define VX1000_EVENT603_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT603_HANDLING */
#if defined(VX1000_EVENT604_HANDLING)
#if ((VX1000_EVENT604_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT604_HANDLING */
#define VX1000_EVENT604_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT604_HANDLING */
#if defined(VX1000_EVENT605_HANDLING)
#if ((VX1000_EVENT605_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT605_HANDLING */
#define VX1000_EVENT605_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT605_HANDLING */
#if defined(VX1000_EVENT606_HANDLING)
#if ((VX1000_EVENT606_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT606_HANDLING */
#define VX1000_EVENT606_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT606_HANDLING */
#if defined(VX1000_EVENT607_HANDLING)
#if ((VX1000_EVENT607_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT607_HANDLING */
#define VX1000_EVENT607_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT607_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 600U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 608U
#if defined(VX1000_EVENT608_HANDLING)
#if ((VX1000_EVENT608_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT608_HANDLING */
#define VX1000_EVENT608_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT608_HANDLING */
#if defined(VX1000_EVENT609_HANDLING)
#if ((VX1000_EVENT609_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT609_HANDLING */
#define VX1000_EVENT609_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT609_HANDLING */
#if defined(VX1000_EVENT610_HANDLING)
#if ((VX1000_EVENT610_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT610_HANDLING */
#define VX1000_EVENT610_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT610_HANDLING */
#if defined(VX1000_EVENT611_HANDLING)
#if ((VX1000_EVENT611_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT611_HANDLING */
#define VX1000_EVENT611_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT611_HANDLING */
#if defined(VX1000_EVENT612_HANDLING)
#if ((VX1000_EVENT612_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT612_HANDLING */
#define VX1000_EVENT612_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT612_HANDLING */
#if defined(VX1000_EVENT613_HANDLING)
#if ((VX1000_EVENT613_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT613_HANDLING */
#define VX1000_EVENT613_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT613_HANDLING */
#if defined(VX1000_EVENT614_HANDLING)
#if ((VX1000_EVENT614_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT614_HANDLING */
#define VX1000_EVENT614_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT614_HANDLING */
#if defined(VX1000_EVENT615_HANDLING)
#if ((VX1000_EVENT615_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT615_HANDLING */
#define VX1000_EVENT615_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT615_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 608U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 616U
#if defined(VX1000_EVENT616_HANDLING)
#if ((VX1000_EVENT616_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT616_HANDLING */
#define VX1000_EVENT616_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT616_HANDLING */
#if defined(VX1000_EVENT617_HANDLING)
#if ((VX1000_EVENT617_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT617_HANDLING */
#define VX1000_EVENT617_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT617_HANDLING */
#if defined(VX1000_EVENT618_HANDLING)
#if ((VX1000_EVENT618_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT618_HANDLING */
#define VX1000_EVENT618_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT618_HANDLING */
#if defined(VX1000_EVENT619_HANDLING)
#if ((VX1000_EVENT619_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT619_HANDLING */
#define VX1000_EVENT619_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT619_HANDLING */
#if defined(VX1000_EVENT620_HANDLING)
#if ((VX1000_EVENT620_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT620_HANDLING */
#define VX1000_EVENT620_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT620_HANDLING */
#if defined(VX1000_EVENT621_HANDLING)
#if ((VX1000_EVENT621_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT621_HANDLING */
#define VX1000_EVENT621_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT621_HANDLING */
#if defined(VX1000_EVENT622_HANDLING)
#if ((VX1000_EVENT622_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT622_HANDLING */
#define VX1000_EVENT622_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT622_HANDLING */
#if defined(VX1000_EVENT623_HANDLING)
#if ((VX1000_EVENT623_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT623_HANDLING */
#define VX1000_EVENT623_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT623_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 616U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 624U
#if defined(VX1000_EVENT624_HANDLING)
#if ((VX1000_EVENT624_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT624_HANDLING */
#define VX1000_EVENT624_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT624_HANDLING */
#if defined(VX1000_EVENT625_HANDLING)
#if ((VX1000_EVENT625_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT625_HANDLING */
#define VX1000_EVENT625_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT625_HANDLING */
#if defined(VX1000_EVENT626_HANDLING)
#if ((VX1000_EVENT626_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT626_HANDLING */
#define VX1000_EVENT626_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT626_HANDLING */
#if defined(VX1000_EVENT627_HANDLING)
#if ((VX1000_EVENT627_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT627_HANDLING */
#define VX1000_EVENT627_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT627_HANDLING */
#if defined(VX1000_EVENT628_HANDLING)
#if ((VX1000_EVENT628_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT628_HANDLING */
#define VX1000_EVENT628_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT628_HANDLING */
#if defined(VX1000_EVENT629_HANDLING)
#if ((VX1000_EVENT629_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT629_HANDLING */
#define VX1000_EVENT629_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT629_HANDLING */
#if defined(VX1000_EVENT630_HANDLING)
#if ((VX1000_EVENT630_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT630_HANDLING */
#define VX1000_EVENT630_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT630_HANDLING */
#if defined(VX1000_EVENT631_HANDLING)
#if ((VX1000_EVENT631_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT631_HANDLING */
#define VX1000_EVENT631_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT631_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 624U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 632U
#if defined(VX1000_EVENT632_HANDLING)
#if ((VX1000_EVENT632_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT632_HANDLING */
#define VX1000_EVENT632_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT632_HANDLING */
#if defined(VX1000_EVENT633_HANDLING)
#if ((VX1000_EVENT633_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT633_HANDLING */
#define VX1000_EVENT633_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT633_HANDLING */
#if defined(VX1000_EVENT634_HANDLING)
#if ((VX1000_EVENT634_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT634_HANDLING */
#define VX1000_EVENT634_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT634_HANDLING */
#if defined(VX1000_EVENT635_HANDLING)
#if ((VX1000_EVENT635_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT635_HANDLING */
#define VX1000_EVENT635_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT635_HANDLING */
#if defined(VX1000_EVENT636_HANDLING)
#if ((VX1000_EVENT636_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT636_HANDLING */
#define VX1000_EVENT636_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT636_HANDLING */
#if defined(VX1000_EVENT637_HANDLING)
#if ((VX1000_EVENT637_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT637_HANDLING */
#define VX1000_EVENT637_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT637_HANDLING */
#if defined(VX1000_EVENT638_HANDLING)
#if ((VX1000_EVENT638_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT638_HANDLING */
#define VX1000_EVENT638_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT638_HANDLING */
#if defined(VX1000_EVENT639_HANDLING)
#if ((VX1000_EVENT639_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT639_HANDLING */
#define VX1000_EVENT639_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT639_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 632U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 640U
#if defined(VX1000_EVENT640_HANDLING)
#if ((VX1000_EVENT640_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT640_HANDLING */
#define VX1000_EVENT640_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT640_HANDLING */
#if defined(VX1000_EVENT641_HANDLING)
#if ((VX1000_EVENT641_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT641_HANDLING */
#define VX1000_EVENT641_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT641_HANDLING */
#if defined(VX1000_EVENT642_HANDLING)
#if ((VX1000_EVENT642_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT642_HANDLING */
#define VX1000_EVENT642_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT642_HANDLING */
#if defined(VX1000_EVENT643_HANDLING)
#if ((VX1000_EVENT643_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT643_HANDLING */
#define VX1000_EVENT643_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT643_HANDLING */
#if defined(VX1000_EVENT644_HANDLING)
#if ((VX1000_EVENT644_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT644_HANDLING */
#define VX1000_EVENT644_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT644_HANDLING */
#if defined(VX1000_EVENT645_HANDLING)
#if ((VX1000_EVENT645_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT645_HANDLING */
#define VX1000_EVENT645_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT645_HANDLING */
#if defined(VX1000_EVENT646_HANDLING)
#if ((VX1000_EVENT646_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT646_HANDLING */
#define VX1000_EVENT646_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT646_HANDLING */
#if defined(VX1000_EVENT647_HANDLING)
#if ((VX1000_EVENT647_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT647_HANDLING */
#define VX1000_EVENT647_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT647_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 640U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 648U
#if defined(VX1000_EVENT648_HANDLING)
#if ((VX1000_EVENT648_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT648_HANDLING */
#define VX1000_EVENT648_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT648_HANDLING */
#if defined(VX1000_EVENT649_HANDLING)
#if ((VX1000_EVENT649_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT649_HANDLING */
#define VX1000_EVENT649_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT649_HANDLING */
#if defined(VX1000_EVENT650_HANDLING)
#if ((VX1000_EVENT650_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT650_HANDLING */
#define VX1000_EVENT650_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT650_HANDLING */
#if defined(VX1000_EVENT651_HANDLING)
#if ((VX1000_EVENT651_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT651_HANDLING */
#define VX1000_EVENT651_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT651_HANDLING */
#if defined(VX1000_EVENT652_HANDLING)
#if ((VX1000_EVENT652_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT652_HANDLING */
#define VX1000_EVENT652_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT652_HANDLING */
#if defined(VX1000_EVENT653_HANDLING)
#if ((VX1000_EVENT653_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT653_HANDLING */
#define VX1000_EVENT653_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT653_HANDLING */
#if defined(VX1000_EVENT654_HANDLING)
#if ((VX1000_EVENT654_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT654_HANDLING */
#define VX1000_EVENT654_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT654_HANDLING */
#if defined(VX1000_EVENT655_HANDLING)
#if ((VX1000_EVENT655_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT655_HANDLING */
#define VX1000_EVENT655_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT655_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 648U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 656U
#if defined(VX1000_EVENT656_HANDLING)
#if ((VX1000_EVENT656_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT656_HANDLING */
#define VX1000_EVENT656_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT656_HANDLING */
#if defined(VX1000_EVENT657_HANDLING)
#if ((VX1000_EVENT657_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT657_HANDLING */
#define VX1000_EVENT657_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT657_HANDLING */
#if defined(VX1000_EVENT658_HANDLING)
#if ((VX1000_EVENT658_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT658_HANDLING */
#define VX1000_EVENT658_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT658_HANDLING */
#if defined(VX1000_EVENT659_HANDLING)
#if ((VX1000_EVENT659_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT659_HANDLING */
#define VX1000_EVENT659_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT659_HANDLING */
#if defined(VX1000_EVENT660_HANDLING)
#if ((VX1000_EVENT660_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT660_HANDLING */
#define VX1000_EVENT660_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT660_HANDLING */
#if defined(VX1000_EVENT661_HANDLING)
#if ((VX1000_EVENT661_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT661_HANDLING */
#define VX1000_EVENT661_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT661_HANDLING */
#if defined(VX1000_EVENT662_HANDLING)
#if ((VX1000_EVENT662_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT662_HANDLING */
#define VX1000_EVENT662_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT662_HANDLING */
#if defined(VX1000_EVENT663_HANDLING)
#if ((VX1000_EVENT663_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT663_HANDLING */
#define VX1000_EVENT663_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT663_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 656U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 664U
#if defined(VX1000_EVENT664_HANDLING)
#if ((VX1000_EVENT664_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT664_HANDLING */
#define VX1000_EVENT664_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT664_HANDLING */
#if defined(VX1000_EVENT665_HANDLING)
#if ((VX1000_EVENT665_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT665_HANDLING */
#define VX1000_EVENT665_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT665_HANDLING */
#if defined(VX1000_EVENT666_HANDLING)
#if ((VX1000_EVENT666_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT666_HANDLING */
#define VX1000_EVENT666_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT666_HANDLING */
#if defined(VX1000_EVENT667_HANDLING)
#if ((VX1000_EVENT667_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT667_HANDLING */
#define VX1000_EVENT667_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT667_HANDLING */
#if defined(VX1000_EVENT668_HANDLING)
#if ((VX1000_EVENT668_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT668_HANDLING */
#define VX1000_EVENT668_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT668_HANDLING */
#if defined(VX1000_EVENT669_HANDLING)
#if ((VX1000_EVENT669_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT669_HANDLING */
#define VX1000_EVENT669_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT669_HANDLING */
#if defined(VX1000_EVENT670_HANDLING)
#if ((VX1000_EVENT670_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT670_HANDLING */
#define VX1000_EVENT670_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT670_HANDLING */
#if defined(VX1000_EVENT671_HANDLING)
#if ((VX1000_EVENT671_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT671_HANDLING */
#define VX1000_EVENT671_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT671_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 664U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 672U
#if defined(VX1000_EVENT672_HANDLING)
#if ((VX1000_EVENT672_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT672_HANDLING */
#define VX1000_EVENT672_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT672_HANDLING */
#if defined(VX1000_EVENT673_HANDLING)
#if ((VX1000_EVENT673_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT673_HANDLING */
#define VX1000_EVENT673_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT673_HANDLING */
#if defined(VX1000_EVENT674_HANDLING)
#if ((VX1000_EVENT674_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT674_HANDLING */
#define VX1000_EVENT674_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT674_HANDLING */
#if defined(VX1000_EVENT675_HANDLING)
#if ((VX1000_EVENT675_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT675_HANDLING */
#define VX1000_EVENT675_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT675_HANDLING */
#if defined(VX1000_EVENT676_HANDLING)
#if ((VX1000_EVENT676_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT676_HANDLING */
#define VX1000_EVENT676_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT676_HANDLING */
#if defined(VX1000_EVENT677_HANDLING)
#if ((VX1000_EVENT677_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT677_HANDLING */
#define VX1000_EVENT677_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT677_HANDLING */
#if defined(VX1000_EVENT678_HANDLING)
#if ((VX1000_EVENT678_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT678_HANDLING */
#define VX1000_EVENT678_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT678_HANDLING */
#if defined(VX1000_EVENT679_HANDLING)
#if ((VX1000_EVENT679_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT679_HANDLING */
#define VX1000_EVENT679_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT679_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 672U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 680U
#if defined(VX1000_EVENT680_HANDLING)
#if ((VX1000_EVENT680_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT680_HANDLING */
#define VX1000_EVENT680_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT680_HANDLING */
#if defined(VX1000_EVENT681_HANDLING)
#if ((VX1000_EVENT681_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT681_HANDLING */
#define VX1000_EVENT681_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT681_HANDLING */
#if defined(VX1000_EVENT682_HANDLING)
#if ((VX1000_EVENT682_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT682_HANDLING */
#define VX1000_EVENT682_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT682_HANDLING */
#if defined(VX1000_EVENT683_HANDLING)
#if ((VX1000_EVENT683_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT683_HANDLING */
#define VX1000_EVENT683_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT683_HANDLING */
#if defined(VX1000_EVENT684_HANDLING)
#if ((VX1000_EVENT684_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT684_HANDLING */
#define VX1000_EVENT684_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT684_HANDLING */
#if defined(VX1000_EVENT685_HANDLING)
#if ((VX1000_EVENT685_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT685_HANDLING */
#define VX1000_EVENT685_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT685_HANDLING */
#if defined(VX1000_EVENT686_HANDLING)
#if ((VX1000_EVENT686_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT686_HANDLING */
#define VX1000_EVENT686_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT686_HANDLING */
#if defined(VX1000_EVENT687_HANDLING)
#if ((VX1000_EVENT687_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT687_HANDLING */
#define VX1000_EVENT687_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT687_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 680U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 688U
#if defined(VX1000_EVENT688_HANDLING)
#if ((VX1000_EVENT688_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT688_HANDLING */
#define VX1000_EVENT688_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT688_HANDLING */
#if defined(VX1000_EVENT689_HANDLING)
#if ((VX1000_EVENT689_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT689_HANDLING */
#define VX1000_EVENT689_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT689_HANDLING */
#if defined(VX1000_EVENT690_HANDLING)
#if ((VX1000_EVENT690_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT690_HANDLING */
#define VX1000_EVENT690_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT690_HANDLING */
#if defined(VX1000_EVENT691_HANDLING)
#if ((VX1000_EVENT691_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT691_HANDLING */
#define VX1000_EVENT691_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT691_HANDLING */
#if defined(VX1000_EVENT692_HANDLING)
#if ((VX1000_EVENT692_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT692_HANDLING */
#define VX1000_EVENT692_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT692_HANDLING */
#if defined(VX1000_EVENT693_HANDLING)
#if ((VX1000_EVENT693_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT693_HANDLING */
#define VX1000_EVENT693_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT693_HANDLING */
#if defined(VX1000_EVENT694_HANDLING)
#if ((VX1000_EVENT694_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT694_HANDLING */
#define VX1000_EVENT694_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT694_HANDLING */
#if defined(VX1000_EVENT695_HANDLING)
#if ((VX1000_EVENT695_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT695_HANDLING */
#define VX1000_EVENT695_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT695_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 688U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 696U
#if defined(VX1000_EVENT696_HANDLING)
#if ((VX1000_EVENT696_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT696_HANDLING */
#define VX1000_EVENT696_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT696_HANDLING */
#if defined(VX1000_EVENT697_HANDLING)
#if ((VX1000_EVENT697_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT697_HANDLING */
#define VX1000_EVENT697_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT697_HANDLING */
#if defined(VX1000_EVENT698_HANDLING)
#if ((VX1000_EVENT698_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT698_HANDLING */
#define VX1000_EVENT698_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT698_HANDLING */
#if defined(VX1000_EVENT699_HANDLING)
#if ((VX1000_EVENT699_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT699_HANDLING */
#define VX1000_EVENT699_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT699_HANDLING */
#if defined(VX1000_EVENT700_HANDLING)
#if ((VX1000_EVENT700_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT700_HANDLING */
#define VX1000_EVENT700_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT700_HANDLING */
#if defined(VX1000_EVENT701_HANDLING)
#if ((VX1000_EVENT701_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT701_HANDLING */
#define VX1000_EVENT701_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT701_HANDLING */
#if defined(VX1000_EVENT702_HANDLING)
#if ((VX1000_EVENT702_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT702_HANDLING */
#define VX1000_EVENT702_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT702_HANDLING */
#if defined(VX1000_EVENT703_HANDLING)
#if ((VX1000_EVENT703_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT703_HANDLING */
#define VX1000_EVENT703_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT703_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 696U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 704U
#if defined(VX1000_EVENT704_HANDLING)
#if ((VX1000_EVENT704_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT704_HANDLING */
#define VX1000_EVENT704_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT704_HANDLING */
#if defined(VX1000_EVENT705_HANDLING)
#if ((VX1000_EVENT705_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT705_HANDLING */
#define VX1000_EVENT705_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT705_HANDLING */
#if defined(VX1000_EVENT706_HANDLING)
#if ((VX1000_EVENT706_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT706_HANDLING */
#define VX1000_EVENT706_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT706_HANDLING */
#if defined(VX1000_EVENT707_HANDLING)
#if ((VX1000_EVENT707_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT707_HANDLING */
#define VX1000_EVENT707_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT707_HANDLING */
#if defined(VX1000_EVENT708_HANDLING)
#if ((VX1000_EVENT708_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT708_HANDLING */
#define VX1000_EVENT708_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT708_HANDLING */
#if defined(VX1000_EVENT709_HANDLING)
#if ((VX1000_EVENT709_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT709_HANDLING */
#define VX1000_EVENT709_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT709_HANDLING */
#if defined(VX1000_EVENT710_HANDLING)
#if ((VX1000_EVENT710_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT710_HANDLING */
#define VX1000_EVENT710_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT710_HANDLING */
#if defined(VX1000_EVENT711_HANDLING)
#if ((VX1000_EVENT711_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT711_HANDLING */
#define VX1000_EVENT711_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT711_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 704U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 712U
#if defined(VX1000_EVENT712_HANDLING)
#if ((VX1000_EVENT712_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT712_HANDLING */
#define VX1000_EVENT712_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT712_HANDLING */
#if defined(VX1000_EVENT713_HANDLING)
#if ((VX1000_EVENT713_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT713_HANDLING */
#define VX1000_EVENT713_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT713_HANDLING */
#if defined(VX1000_EVENT714_HANDLING)
#if ((VX1000_EVENT714_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT714_HANDLING */
#define VX1000_EVENT714_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT714_HANDLING */
#if defined(VX1000_EVENT715_HANDLING)
#if ((VX1000_EVENT715_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT715_HANDLING */
#define VX1000_EVENT715_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT715_HANDLING */
#if defined(VX1000_EVENT716_HANDLING)
#if ((VX1000_EVENT716_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT716_HANDLING */
#define VX1000_EVENT716_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT716_HANDLING */
#if defined(VX1000_EVENT717_HANDLING)
#if ((VX1000_EVENT717_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT717_HANDLING */
#define VX1000_EVENT717_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT717_HANDLING */
#if defined(VX1000_EVENT718_HANDLING)
#if ((VX1000_EVENT718_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT718_HANDLING */
#define VX1000_EVENT718_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT718_HANDLING */
#if defined(VX1000_EVENT719_HANDLING)
#if ((VX1000_EVENT719_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT719_HANDLING */
#define VX1000_EVENT719_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT719_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 712U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 720U
#if defined(VX1000_EVENT720_HANDLING)
#if ((VX1000_EVENT720_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT720_HANDLING */
#define VX1000_EVENT720_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT720_HANDLING */
#if defined(VX1000_EVENT721_HANDLING)
#if ((VX1000_EVENT721_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT721_HANDLING */
#define VX1000_EVENT721_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT721_HANDLING */
#if defined(VX1000_EVENT722_HANDLING)
#if ((VX1000_EVENT722_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT722_HANDLING */
#define VX1000_EVENT722_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT722_HANDLING */
#if defined(VX1000_EVENT723_HANDLING)
#if ((VX1000_EVENT723_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT723_HANDLING */
#define VX1000_EVENT723_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT723_HANDLING */
#if defined(VX1000_EVENT724_HANDLING)
#if ((VX1000_EVENT724_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT724_HANDLING */
#define VX1000_EVENT724_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT724_HANDLING */
#if defined(VX1000_EVENT725_HANDLING)
#if ((VX1000_EVENT725_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT725_HANDLING */
#define VX1000_EVENT725_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT725_HANDLING */
#if defined(VX1000_EVENT726_HANDLING)
#if ((VX1000_EVENT726_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT726_HANDLING */
#define VX1000_EVENT726_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT726_HANDLING */
#if defined(VX1000_EVENT727_HANDLING)
#if ((VX1000_EVENT727_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT727_HANDLING */
#define VX1000_EVENT727_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT727_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 720U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 728U
#if defined(VX1000_EVENT728_HANDLING)
#if ((VX1000_EVENT728_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT728_HANDLING */
#define VX1000_EVENT728_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT728_HANDLING */
#if defined(VX1000_EVENT729_HANDLING)
#if ((VX1000_EVENT729_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT729_HANDLING */
#define VX1000_EVENT729_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT729_HANDLING */
#if defined(VX1000_EVENT730_HANDLING)
#if ((VX1000_EVENT730_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT730_HANDLING */
#define VX1000_EVENT730_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT730_HANDLING */
#if defined(VX1000_EVENT731_HANDLING)
#if ((VX1000_EVENT731_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT731_HANDLING */
#define VX1000_EVENT731_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT731_HANDLING */
#if defined(VX1000_EVENT732_HANDLING)
#if ((VX1000_EVENT732_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT732_HANDLING */
#define VX1000_EVENT732_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT732_HANDLING */
#if defined(VX1000_EVENT733_HANDLING)
#if ((VX1000_EVENT733_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT733_HANDLING */
#define VX1000_EVENT733_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT733_HANDLING */
#if defined(VX1000_EVENT734_HANDLING)
#if ((VX1000_EVENT734_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT734_HANDLING */
#define VX1000_EVENT734_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT734_HANDLING */
#if defined(VX1000_EVENT735_HANDLING)
#if ((VX1000_EVENT735_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT735_HANDLING */
#define VX1000_EVENT735_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT735_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 728U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 736U
#if defined(VX1000_EVENT736_HANDLING)
#if ((VX1000_EVENT736_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT736_HANDLING */
#define VX1000_EVENT736_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT736_HANDLING */
#if defined(VX1000_EVENT737_HANDLING)
#if ((VX1000_EVENT737_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT737_HANDLING */
#define VX1000_EVENT737_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT737_HANDLING */
#if defined(VX1000_EVENT738_HANDLING)
#if ((VX1000_EVENT738_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT738_HANDLING */
#define VX1000_EVENT738_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT738_HANDLING */
#if defined(VX1000_EVENT739_HANDLING)
#if ((VX1000_EVENT739_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT739_HANDLING */
#define VX1000_EVENT739_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT739_HANDLING */
#if defined(VX1000_EVENT740_HANDLING)
#if ((VX1000_EVENT740_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT740_HANDLING */
#define VX1000_EVENT740_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT740_HANDLING */
#if defined(VX1000_EVENT741_HANDLING)
#if ((VX1000_EVENT741_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT741_HANDLING */
#define VX1000_EVENT741_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT741_HANDLING */
#if defined(VX1000_EVENT742_HANDLING)
#if ((VX1000_EVENT742_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT742_HANDLING */
#define VX1000_EVENT742_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT742_HANDLING */
#if defined(VX1000_EVENT743_HANDLING)
#if ((VX1000_EVENT743_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT743_HANDLING */
#define VX1000_EVENT743_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT743_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 736U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 744U
#if defined(VX1000_EVENT744_HANDLING)
#if ((VX1000_EVENT744_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT744_HANDLING */
#define VX1000_EVENT744_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT744_HANDLING */
#if defined(VX1000_EVENT745_HANDLING)
#if ((VX1000_EVENT745_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT745_HANDLING */
#define VX1000_EVENT745_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT745_HANDLING */
#if defined(VX1000_EVENT746_HANDLING)
#if ((VX1000_EVENT746_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT746_HANDLING */
#define VX1000_EVENT746_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT746_HANDLING */
#if defined(VX1000_EVENT747_HANDLING)
#if ((VX1000_EVENT747_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT747_HANDLING */
#define VX1000_EVENT747_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT747_HANDLING */
#if defined(VX1000_EVENT748_HANDLING)
#if ((VX1000_EVENT748_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT748_HANDLING */
#define VX1000_EVENT748_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT748_HANDLING */
#if defined(VX1000_EVENT749_HANDLING)
#if ((VX1000_EVENT749_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT749_HANDLING */
#define VX1000_EVENT749_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT749_HANDLING */
#if defined(VX1000_EVENT750_HANDLING)
#if ((VX1000_EVENT750_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT750_HANDLING */
#define VX1000_EVENT750_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT750_HANDLING */
#if defined(VX1000_EVENT751_HANDLING)
#if ((VX1000_EVENT751_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT751_HANDLING */
#define VX1000_EVENT751_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT751_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 744U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 752U
#if defined(VX1000_EVENT752_HANDLING)
#if ((VX1000_EVENT752_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT752_HANDLING */
#define VX1000_EVENT752_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT752_HANDLING */
#if defined(VX1000_EVENT753_HANDLING)
#if ((VX1000_EVENT753_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT753_HANDLING */
#define VX1000_EVENT753_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT753_HANDLING */
#if defined(VX1000_EVENT754_HANDLING)
#if ((VX1000_EVENT754_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT754_HANDLING */
#define VX1000_EVENT754_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT754_HANDLING */
#if defined(VX1000_EVENT755_HANDLING)
#if ((VX1000_EVENT755_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT755_HANDLING */
#define VX1000_EVENT755_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT755_HANDLING */
#if defined(VX1000_EVENT756_HANDLING)
#if ((VX1000_EVENT756_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT756_HANDLING */
#define VX1000_EVENT756_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT756_HANDLING */
#if defined(VX1000_EVENT757_HANDLING)
#if ((VX1000_EVENT757_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT757_HANDLING */
#define VX1000_EVENT757_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT757_HANDLING */
#if defined(VX1000_EVENT758_HANDLING)
#if ((VX1000_EVENT758_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT758_HANDLING */
#define VX1000_EVENT758_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT758_HANDLING */
#if defined(VX1000_EVENT759_HANDLING)
#if ((VX1000_EVENT759_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT759_HANDLING */
#define VX1000_EVENT759_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT759_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 752U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 760U
#if defined(VX1000_EVENT760_HANDLING)
#if ((VX1000_EVENT760_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT760_HANDLING */
#define VX1000_EVENT760_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT760_HANDLING */
#if defined(VX1000_EVENT761_HANDLING)
#if ((VX1000_EVENT761_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT761_HANDLING */
#define VX1000_EVENT761_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT761_HANDLING */
#if defined(VX1000_EVENT762_HANDLING)
#if ((VX1000_EVENT762_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT762_HANDLING */
#define VX1000_EVENT762_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT762_HANDLING */
#if defined(VX1000_EVENT763_HANDLING)
#if ((VX1000_EVENT763_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT763_HANDLING */
#define VX1000_EVENT763_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT763_HANDLING */
#if defined(VX1000_EVENT764_HANDLING)
#if ((VX1000_EVENT764_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT764_HANDLING */
#define VX1000_EVENT764_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT764_HANDLING */
#if defined(VX1000_EVENT765_HANDLING)
#if ((VX1000_EVENT765_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT765_HANDLING */
#define VX1000_EVENT765_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT765_HANDLING */
#if defined(VX1000_EVENT766_HANDLING)
#if ((VX1000_EVENT766_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT766_HANDLING */
#define VX1000_EVENT766_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT766_HANDLING */
#if defined(VX1000_EVENT767_HANDLING)
#if ((VX1000_EVENT767_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT767_HANDLING */
#define VX1000_EVENT767_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT767_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 760U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 768U
#if defined(VX1000_EVENT768_HANDLING)
#if ((VX1000_EVENT768_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT768_HANDLING */
#define VX1000_EVENT768_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT768_HANDLING */
#if defined(VX1000_EVENT769_HANDLING)
#if ((VX1000_EVENT769_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT769_HANDLING */
#define VX1000_EVENT769_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT769_HANDLING */
#if defined(VX1000_EVENT770_HANDLING)
#if ((VX1000_EVENT770_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT770_HANDLING */
#define VX1000_EVENT770_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT770_HANDLING */
#if defined(VX1000_EVENT771_HANDLING)
#if ((VX1000_EVENT771_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT771_HANDLING */
#define VX1000_EVENT771_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT771_HANDLING */
#if defined(VX1000_EVENT772_HANDLING)
#if ((VX1000_EVENT772_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT772_HANDLING */
#define VX1000_EVENT772_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT772_HANDLING */
#if defined(VX1000_EVENT773_HANDLING)
#if ((VX1000_EVENT773_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT773_HANDLING */
#define VX1000_EVENT773_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT773_HANDLING */
#if defined(VX1000_EVENT774_HANDLING)
#if ((VX1000_EVENT774_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT774_HANDLING */
#define VX1000_EVENT774_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT774_HANDLING */
#if defined(VX1000_EVENT775_HANDLING)
#if ((VX1000_EVENT775_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT775_HANDLING */
#define VX1000_EVENT775_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT775_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 768U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 776U
#if defined(VX1000_EVENT776_HANDLING)
#if ((VX1000_EVENT776_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT776_HANDLING */
#define VX1000_EVENT776_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT776_HANDLING */
#if defined(VX1000_EVENT777_HANDLING)
#if ((VX1000_EVENT777_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT777_HANDLING */
#define VX1000_EVENT777_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT777_HANDLING */
#if defined(VX1000_EVENT778_HANDLING)
#if ((VX1000_EVENT778_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT778_HANDLING */
#define VX1000_EVENT778_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT778_HANDLING */
#if defined(VX1000_EVENT779_HANDLING)
#if ((VX1000_EVENT779_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT779_HANDLING */
#define VX1000_EVENT779_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT779_HANDLING */
#if defined(VX1000_EVENT780_HANDLING)
#if ((VX1000_EVENT780_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT780_HANDLING */
#define VX1000_EVENT780_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT780_HANDLING */
#if defined(VX1000_EVENT781_HANDLING)
#if ((VX1000_EVENT781_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT781_HANDLING */
#define VX1000_EVENT781_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT781_HANDLING */
#if defined(VX1000_EVENT782_HANDLING)
#if ((VX1000_EVENT782_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT782_HANDLING */
#define VX1000_EVENT782_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT782_HANDLING */
#if defined(VX1000_EVENT783_HANDLING)
#if ((VX1000_EVENT783_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT783_HANDLING */
#define VX1000_EVENT783_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT783_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 776U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 784U
#if defined(VX1000_EVENT784_HANDLING)
#if ((VX1000_EVENT784_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT784_HANDLING */
#define VX1000_EVENT784_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT784_HANDLING */
#if defined(VX1000_EVENT785_HANDLING)
#if ((VX1000_EVENT785_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT785_HANDLING */
#define VX1000_EVENT785_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT785_HANDLING */
#if defined(VX1000_EVENT786_HANDLING)
#if ((VX1000_EVENT786_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT786_HANDLING */
#define VX1000_EVENT786_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT786_HANDLING */
#if defined(VX1000_EVENT787_HANDLING)
#if ((VX1000_EVENT787_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT787_HANDLING */
#define VX1000_EVENT787_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT787_HANDLING */
#if defined(VX1000_EVENT788_HANDLING)
#if ((VX1000_EVENT788_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT788_HANDLING */
#define VX1000_EVENT788_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT788_HANDLING */
#if defined(VX1000_EVENT789_HANDLING)
#if ((VX1000_EVENT789_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT789_HANDLING */
#define VX1000_EVENT789_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT789_HANDLING */
#if defined(VX1000_EVENT790_HANDLING)
#if ((VX1000_EVENT790_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT790_HANDLING */
#define VX1000_EVENT790_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT790_HANDLING */
#if defined(VX1000_EVENT791_HANDLING)
#if ((VX1000_EVENT791_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT791_HANDLING */
#define VX1000_EVENT791_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT791_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 784U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 792U
#if defined(VX1000_EVENT792_HANDLING)
#if ((VX1000_EVENT792_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT792_HANDLING */
#define VX1000_EVENT792_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT792_HANDLING */
#if defined(VX1000_EVENT793_HANDLING)
#if ((VX1000_EVENT793_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT793_HANDLING */
#define VX1000_EVENT793_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT793_HANDLING */
#if defined(VX1000_EVENT794_HANDLING)
#if ((VX1000_EVENT794_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT794_HANDLING */
#define VX1000_EVENT794_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT794_HANDLING */
#if defined(VX1000_EVENT795_HANDLING)
#if ((VX1000_EVENT795_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT795_HANDLING */
#define VX1000_EVENT795_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT795_HANDLING */
#if defined(VX1000_EVENT796_HANDLING)
#if ((VX1000_EVENT796_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT796_HANDLING */
#define VX1000_EVENT796_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT796_HANDLING */
#if defined(VX1000_EVENT797_HANDLING)
#if ((VX1000_EVENT797_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT797_HANDLING */
#define VX1000_EVENT797_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT797_HANDLING */
#if defined(VX1000_EVENT798_HANDLING)
#if ((VX1000_EVENT798_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT798_HANDLING */
#define VX1000_EVENT798_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT798_HANDLING */
#if defined(VX1000_EVENT799_HANDLING)
#if ((VX1000_EVENT799_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT799_HANDLING */
#define VX1000_EVENT799_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT799_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 792U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 800U
#if defined(VX1000_EVENT800_HANDLING)
#if ((VX1000_EVENT800_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT800_HANDLING */
#define VX1000_EVENT800_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT800_HANDLING */
#if defined(VX1000_EVENT801_HANDLING)
#if ((VX1000_EVENT801_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT801_HANDLING */
#define VX1000_EVENT801_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT801_HANDLING */
#if defined(VX1000_EVENT802_HANDLING)
#if ((VX1000_EVENT802_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT802_HANDLING */
#define VX1000_EVENT802_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT802_HANDLING */
#if defined(VX1000_EVENT803_HANDLING)
#if ((VX1000_EVENT803_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT803_HANDLING */
#define VX1000_EVENT803_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT803_HANDLING */
#if defined(VX1000_EVENT804_HANDLING)
#if ((VX1000_EVENT804_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT804_HANDLING */
#define VX1000_EVENT804_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT804_HANDLING */
#if defined(VX1000_EVENT805_HANDLING)
#if ((VX1000_EVENT805_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT805_HANDLING */
#define VX1000_EVENT805_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT805_HANDLING */
#if defined(VX1000_EVENT806_HANDLING)
#if ((VX1000_EVENT806_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT806_HANDLING */
#define VX1000_EVENT806_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT806_HANDLING */
#if defined(VX1000_EVENT807_HANDLING)
#if ((VX1000_EVENT807_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT807_HANDLING */
#define VX1000_EVENT807_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT807_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 800U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 808U
#if defined(VX1000_EVENT808_HANDLING)
#if ((VX1000_EVENT808_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT808_HANDLING */
#define VX1000_EVENT808_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT808_HANDLING */
#if defined(VX1000_EVENT809_HANDLING)
#if ((VX1000_EVENT809_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT809_HANDLING */
#define VX1000_EVENT809_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT809_HANDLING */
#if defined(VX1000_EVENT810_HANDLING)
#if ((VX1000_EVENT810_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT810_HANDLING */
#define VX1000_EVENT810_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT810_HANDLING */
#if defined(VX1000_EVENT811_HANDLING)
#if ((VX1000_EVENT811_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT811_HANDLING */
#define VX1000_EVENT811_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT811_HANDLING */
#if defined(VX1000_EVENT812_HANDLING)
#if ((VX1000_EVENT812_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT812_HANDLING */
#define VX1000_EVENT812_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT812_HANDLING */
#if defined(VX1000_EVENT813_HANDLING)
#if ((VX1000_EVENT813_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT813_HANDLING */
#define VX1000_EVENT813_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT813_HANDLING */
#if defined(VX1000_EVENT814_HANDLING)
#if ((VX1000_EVENT814_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT814_HANDLING */
#define VX1000_EVENT814_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT814_HANDLING */
#if defined(VX1000_EVENT815_HANDLING)
#if ((VX1000_EVENT815_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT815_HANDLING */
#define VX1000_EVENT815_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT815_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 808U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 816U
#if defined(VX1000_EVENT816_HANDLING)
#if ((VX1000_EVENT816_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT816_HANDLING */
#define VX1000_EVENT816_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT816_HANDLING */
#if defined(VX1000_EVENT817_HANDLING)
#if ((VX1000_EVENT817_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT817_HANDLING */
#define VX1000_EVENT817_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT817_HANDLING */
#if defined(VX1000_EVENT818_HANDLING)
#if ((VX1000_EVENT818_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT818_HANDLING */
#define VX1000_EVENT818_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT818_HANDLING */
#if defined(VX1000_EVENT819_HANDLING)
#if ((VX1000_EVENT819_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT819_HANDLING */
#define VX1000_EVENT819_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT819_HANDLING */
#if defined(VX1000_EVENT820_HANDLING)
#if ((VX1000_EVENT820_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT820_HANDLING */
#define VX1000_EVENT820_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT820_HANDLING */
#if defined(VX1000_EVENT821_HANDLING)
#if ((VX1000_EVENT821_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT821_HANDLING */
#define VX1000_EVENT821_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT821_HANDLING */
#if defined(VX1000_EVENT822_HANDLING)
#if ((VX1000_EVENT822_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT822_HANDLING */
#define VX1000_EVENT822_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT822_HANDLING */
#if defined(VX1000_EVENT823_HANDLING)
#if ((VX1000_EVENT823_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT823_HANDLING */
#define VX1000_EVENT823_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT823_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 816U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 824U
#if defined(VX1000_EVENT824_HANDLING)
#if ((VX1000_EVENT824_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT824_HANDLING */
#define VX1000_EVENT824_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT824_HANDLING */
#if defined(VX1000_EVENT825_HANDLING)
#if ((VX1000_EVENT825_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT825_HANDLING */
#define VX1000_EVENT825_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT825_HANDLING */
#if defined(VX1000_EVENT826_HANDLING)
#if ((VX1000_EVENT826_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT826_HANDLING */
#define VX1000_EVENT826_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT826_HANDLING */
#if defined(VX1000_EVENT827_HANDLING)
#if ((VX1000_EVENT827_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT827_HANDLING */
#define VX1000_EVENT827_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT827_HANDLING */
#if defined(VX1000_EVENT828_HANDLING)
#if ((VX1000_EVENT828_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT828_HANDLING */
#define VX1000_EVENT828_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT828_HANDLING */
#if defined(VX1000_EVENT829_HANDLING)
#if ((VX1000_EVENT829_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT829_HANDLING */
#define VX1000_EVENT829_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT829_HANDLING */
#if defined(VX1000_EVENT830_HANDLING)
#if ((VX1000_EVENT830_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT830_HANDLING */
#define VX1000_EVENT830_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT830_HANDLING */
#if defined(VX1000_EVENT831_HANDLING)
#if ((VX1000_EVENT831_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT831_HANDLING */
#define VX1000_EVENT831_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT831_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 824U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 832U
#if defined(VX1000_EVENT832_HANDLING)
#if ((VX1000_EVENT832_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT832_HANDLING */
#define VX1000_EVENT832_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT832_HANDLING */
#if defined(VX1000_EVENT833_HANDLING)
#if ((VX1000_EVENT833_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT833_HANDLING */
#define VX1000_EVENT833_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT833_HANDLING */
#if defined(VX1000_EVENT834_HANDLING)
#if ((VX1000_EVENT834_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT834_HANDLING */
#define VX1000_EVENT834_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT834_HANDLING */
#if defined(VX1000_EVENT835_HANDLING)
#if ((VX1000_EVENT835_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT835_HANDLING */
#define VX1000_EVENT835_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT835_HANDLING */
#if defined(VX1000_EVENT836_HANDLING)
#if ((VX1000_EVENT836_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT836_HANDLING */
#define VX1000_EVENT836_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT836_HANDLING */
#if defined(VX1000_EVENT837_HANDLING)
#if ((VX1000_EVENT837_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT837_HANDLING */
#define VX1000_EVENT837_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT837_HANDLING */
#if defined(VX1000_EVENT838_HANDLING)
#if ((VX1000_EVENT838_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT838_HANDLING */
#define VX1000_EVENT838_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT838_HANDLING */
#if defined(VX1000_EVENT839_HANDLING)
#if ((VX1000_EVENT839_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT839_HANDLING */
#define VX1000_EVENT839_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT839_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 832U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 840U
#if defined(VX1000_EVENT840_HANDLING)
#if ((VX1000_EVENT840_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT840_HANDLING */
#define VX1000_EVENT840_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT840_HANDLING */
#if defined(VX1000_EVENT841_HANDLING)
#if ((VX1000_EVENT841_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT841_HANDLING */
#define VX1000_EVENT841_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT841_HANDLING */
#if defined(VX1000_EVENT842_HANDLING)
#if ((VX1000_EVENT842_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT842_HANDLING */
#define VX1000_EVENT842_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT842_HANDLING */
#if defined(VX1000_EVENT843_HANDLING)
#if ((VX1000_EVENT843_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT843_HANDLING */
#define VX1000_EVENT843_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT843_HANDLING */
#if defined(VX1000_EVENT844_HANDLING)
#if ((VX1000_EVENT844_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT844_HANDLING */
#define VX1000_EVENT844_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT844_HANDLING */
#if defined(VX1000_EVENT845_HANDLING)
#if ((VX1000_EVENT845_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT845_HANDLING */
#define VX1000_EVENT845_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT845_HANDLING */
#if defined(VX1000_EVENT846_HANDLING)
#if ((VX1000_EVENT846_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT846_HANDLING */
#define VX1000_EVENT846_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT846_HANDLING */
#if defined(VX1000_EVENT847_HANDLING)
#if ((VX1000_EVENT847_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT847_HANDLING */
#define VX1000_EVENT847_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT847_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 840U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 848U
#if defined(VX1000_EVENT848_HANDLING)
#if ((VX1000_EVENT848_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT848_HANDLING */
#define VX1000_EVENT848_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT848_HANDLING */
#if defined(VX1000_EVENT849_HANDLING)
#if ((VX1000_EVENT849_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT849_HANDLING */
#define VX1000_EVENT849_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT849_HANDLING */
#if defined(VX1000_EVENT850_HANDLING)
#if ((VX1000_EVENT850_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT850_HANDLING */
#define VX1000_EVENT850_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT850_HANDLING */
#if defined(VX1000_EVENT851_HANDLING)
#if ((VX1000_EVENT851_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT851_HANDLING */
#define VX1000_EVENT851_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT851_HANDLING */
#if defined(VX1000_EVENT852_HANDLING)
#if ((VX1000_EVENT852_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT852_HANDLING */
#define VX1000_EVENT852_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT852_HANDLING */
#if defined(VX1000_EVENT853_HANDLING)
#if ((VX1000_EVENT853_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT853_HANDLING */
#define VX1000_EVENT853_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT853_HANDLING */
#if defined(VX1000_EVENT854_HANDLING)
#if ((VX1000_EVENT854_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT854_HANDLING */
#define VX1000_EVENT854_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT854_HANDLING */
#if defined(VX1000_EVENT855_HANDLING)
#if ((VX1000_EVENT855_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT855_HANDLING */
#define VX1000_EVENT855_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT855_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 848U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 856U
#if defined(VX1000_EVENT856_HANDLING)
#if ((VX1000_EVENT856_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT856_HANDLING */
#define VX1000_EVENT856_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT856_HANDLING */
#if defined(VX1000_EVENT857_HANDLING)
#if ((VX1000_EVENT857_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT857_HANDLING */
#define VX1000_EVENT857_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT857_HANDLING */
#if defined(VX1000_EVENT858_HANDLING)
#if ((VX1000_EVENT858_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT858_HANDLING */
#define VX1000_EVENT858_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT858_HANDLING */
#if defined(VX1000_EVENT859_HANDLING)
#if ((VX1000_EVENT859_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT859_HANDLING */
#define VX1000_EVENT859_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT859_HANDLING */
#if defined(VX1000_EVENT860_HANDLING)
#if ((VX1000_EVENT860_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT860_HANDLING */
#define VX1000_EVENT860_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT860_HANDLING */
#if defined(VX1000_EVENT861_HANDLING)
#if ((VX1000_EVENT861_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT861_HANDLING */
#define VX1000_EVENT861_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT861_HANDLING */
#if defined(VX1000_EVENT862_HANDLING)
#if ((VX1000_EVENT862_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT862_HANDLING */
#define VX1000_EVENT862_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT862_HANDLING */
#if defined(VX1000_EVENT863_HANDLING)
#if ((VX1000_EVENT863_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT863_HANDLING */
#define VX1000_EVENT863_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT863_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 856U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 864U
#if defined(VX1000_EVENT864_HANDLING)
#if ((VX1000_EVENT864_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT864_HANDLING */
#define VX1000_EVENT864_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT864_HANDLING */
#if defined(VX1000_EVENT865_HANDLING)
#if ((VX1000_EVENT865_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT865_HANDLING */
#define VX1000_EVENT865_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT865_HANDLING */
#if defined(VX1000_EVENT866_HANDLING)
#if ((VX1000_EVENT866_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT866_HANDLING */
#define VX1000_EVENT866_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT866_HANDLING */
#if defined(VX1000_EVENT867_HANDLING)
#if ((VX1000_EVENT867_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT867_HANDLING */
#define VX1000_EVENT867_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT867_HANDLING */
#if defined(VX1000_EVENT868_HANDLING)
#if ((VX1000_EVENT868_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT868_HANDLING */
#define VX1000_EVENT868_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT868_HANDLING */
#if defined(VX1000_EVENT869_HANDLING)
#if ((VX1000_EVENT869_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT869_HANDLING */
#define VX1000_EVENT869_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT869_HANDLING */
#if defined(VX1000_EVENT870_HANDLING)
#if ((VX1000_EVENT870_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT870_HANDLING */
#define VX1000_EVENT870_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT870_HANDLING */
#if defined(VX1000_EVENT871_HANDLING)
#if ((VX1000_EVENT871_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT871_HANDLING */
#define VX1000_EVENT871_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT871_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 864U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 872U
#if defined(VX1000_EVENT872_HANDLING)
#if ((VX1000_EVENT872_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT872_HANDLING */
#define VX1000_EVENT872_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT872_HANDLING */
#if defined(VX1000_EVENT873_HANDLING)
#if ((VX1000_EVENT873_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT873_HANDLING */
#define VX1000_EVENT873_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT873_HANDLING */
#if defined(VX1000_EVENT874_HANDLING)
#if ((VX1000_EVENT874_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT874_HANDLING */
#define VX1000_EVENT874_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT874_HANDLING */
#if defined(VX1000_EVENT875_HANDLING)
#if ((VX1000_EVENT875_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT875_HANDLING */
#define VX1000_EVENT875_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT875_HANDLING */
#if defined(VX1000_EVENT876_HANDLING)
#if ((VX1000_EVENT876_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT876_HANDLING */
#define VX1000_EVENT876_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT876_HANDLING */
#if defined(VX1000_EVENT877_HANDLING)
#if ((VX1000_EVENT877_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT877_HANDLING */
#define VX1000_EVENT877_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT877_HANDLING */
#if defined(VX1000_EVENT878_HANDLING)
#if ((VX1000_EVENT878_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT878_HANDLING */
#define VX1000_EVENT878_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT878_HANDLING */
#if defined(VX1000_EVENT879_HANDLING)
#if ((VX1000_EVENT879_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT879_HANDLING */
#define VX1000_EVENT879_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT879_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 872U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 880U
#if defined(VX1000_EVENT880_HANDLING)
#if ((VX1000_EVENT880_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT880_HANDLING */
#define VX1000_EVENT880_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT880_HANDLING */
#if defined(VX1000_EVENT881_HANDLING)
#if ((VX1000_EVENT881_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT881_HANDLING */
#define VX1000_EVENT881_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT881_HANDLING */
#if defined(VX1000_EVENT882_HANDLING)
#if ((VX1000_EVENT882_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT882_HANDLING */
#define VX1000_EVENT882_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT882_HANDLING */
#if defined(VX1000_EVENT883_HANDLING)
#if ((VX1000_EVENT883_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT883_HANDLING */
#define VX1000_EVENT883_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT883_HANDLING */
#if defined(VX1000_EVENT884_HANDLING)
#if ((VX1000_EVENT884_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT884_HANDLING */
#define VX1000_EVENT884_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT884_HANDLING */
#if defined(VX1000_EVENT885_HANDLING)
#if ((VX1000_EVENT885_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT885_HANDLING */
#define VX1000_EVENT885_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT885_HANDLING */
#if defined(VX1000_EVENT886_HANDLING)
#if ((VX1000_EVENT886_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT886_HANDLING */
#define VX1000_EVENT886_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT886_HANDLING */
#if defined(VX1000_EVENT887_HANDLING)
#if ((VX1000_EVENT887_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT887_HANDLING */
#define VX1000_EVENT887_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT887_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 880U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 888U
#if defined(VX1000_EVENT888_HANDLING)
#if ((VX1000_EVENT888_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT888_HANDLING */
#define VX1000_EVENT888_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT888_HANDLING */
#if defined(VX1000_EVENT889_HANDLING)
#if ((VX1000_EVENT889_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT889_HANDLING */
#define VX1000_EVENT889_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT889_HANDLING */
#if defined(VX1000_EVENT890_HANDLING)
#if ((VX1000_EVENT890_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT890_HANDLING */
#define VX1000_EVENT890_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT890_HANDLING */
#if defined(VX1000_EVENT891_HANDLING)
#if ((VX1000_EVENT891_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT891_HANDLING */
#define VX1000_EVENT891_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT891_HANDLING */
#if defined(VX1000_EVENT892_HANDLING)
#if ((VX1000_EVENT892_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT892_HANDLING */
#define VX1000_EVENT892_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT892_HANDLING */
#if defined(VX1000_EVENT893_HANDLING)
#if ((VX1000_EVENT893_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT893_HANDLING */
#define VX1000_EVENT893_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT893_HANDLING */
#if defined(VX1000_EVENT894_HANDLING)
#if ((VX1000_EVENT894_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT894_HANDLING */
#define VX1000_EVENT894_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT894_HANDLING */
#if defined(VX1000_EVENT895_HANDLING)
#if ((VX1000_EVENT895_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT895_HANDLING */
#define VX1000_EVENT895_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT895_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 888U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 896U
#if defined(VX1000_EVENT896_HANDLING)
#if ((VX1000_EVENT896_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT896_HANDLING */
#define VX1000_EVENT896_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT896_HANDLING */
#if defined(VX1000_EVENT897_HANDLING)
#if ((VX1000_EVENT897_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT897_HANDLING */
#define VX1000_EVENT897_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT897_HANDLING */
#if defined(VX1000_EVENT898_HANDLING)
#if ((VX1000_EVENT898_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT898_HANDLING */
#define VX1000_EVENT898_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT898_HANDLING */
#if defined(VX1000_EVENT899_HANDLING)
#if ((VX1000_EVENT899_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT899_HANDLING */
#define VX1000_EVENT899_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT899_HANDLING */
#if defined(VX1000_EVENT900_HANDLING)
#if ((VX1000_EVENT900_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT900_HANDLING */
#define VX1000_EVENT900_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT900_HANDLING */
#if defined(VX1000_EVENT901_HANDLING)
#if ((VX1000_EVENT901_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT901_HANDLING */
#define VX1000_EVENT901_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT901_HANDLING */
#if defined(VX1000_EVENT902_HANDLING)
#if ((VX1000_EVENT902_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT902_HANDLING */
#define VX1000_EVENT902_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT902_HANDLING */
#if defined(VX1000_EVENT903_HANDLING)
#if ((VX1000_EVENT903_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT903_HANDLING */
#define VX1000_EVENT903_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT903_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 896U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 904U
#if defined(VX1000_EVENT904_HANDLING)
#if ((VX1000_EVENT904_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT904_HANDLING */
#define VX1000_EVENT904_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT904_HANDLING */
#if defined(VX1000_EVENT905_HANDLING)
#if ((VX1000_EVENT905_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT905_HANDLING */
#define VX1000_EVENT905_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT905_HANDLING */
#if defined(VX1000_EVENT906_HANDLING)
#if ((VX1000_EVENT906_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT906_HANDLING */
#define VX1000_EVENT906_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT906_HANDLING */
#if defined(VX1000_EVENT907_HANDLING)
#if ((VX1000_EVENT907_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT907_HANDLING */
#define VX1000_EVENT907_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT907_HANDLING */
#if defined(VX1000_EVENT908_HANDLING)
#if ((VX1000_EVENT908_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT908_HANDLING */
#define VX1000_EVENT908_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT908_HANDLING */
#if defined(VX1000_EVENT909_HANDLING)
#if ((VX1000_EVENT909_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT909_HANDLING */
#define VX1000_EVENT909_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT909_HANDLING */
#if defined(VX1000_EVENT910_HANDLING)
#if ((VX1000_EVENT910_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT910_HANDLING */
#define VX1000_EVENT910_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT910_HANDLING */
#if defined(VX1000_EVENT911_HANDLING)
#if ((VX1000_EVENT911_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT911_HANDLING */
#define VX1000_EVENT911_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT911_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 904U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 912U
#if defined(VX1000_EVENT912_HANDLING)
#if ((VX1000_EVENT912_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT912_HANDLING */
#define VX1000_EVENT912_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT912_HANDLING */
#if defined(VX1000_EVENT913_HANDLING)
#if ((VX1000_EVENT913_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT913_HANDLING */
#define VX1000_EVENT913_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT913_HANDLING */
#if defined(VX1000_EVENT914_HANDLING)
#if ((VX1000_EVENT914_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT914_HANDLING */
#define VX1000_EVENT914_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT914_HANDLING */
#if defined(VX1000_EVENT915_HANDLING)
#if ((VX1000_EVENT915_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT915_HANDLING */
#define VX1000_EVENT915_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT915_HANDLING */
#if defined(VX1000_EVENT916_HANDLING)
#if ((VX1000_EVENT916_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT916_HANDLING */
#define VX1000_EVENT916_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT916_HANDLING */
#if defined(VX1000_EVENT917_HANDLING)
#if ((VX1000_EVENT917_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT917_HANDLING */
#define VX1000_EVENT917_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT917_HANDLING */
#if defined(VX1000_EVENT918_HANDLING)
#if ((VX1000_EVENT918_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT918_HANDLING */
#define VX1000_EVENT918_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT918_HANDLING */
#if defined(VX1000_EVENT919_HANDLING)
#if ((VX1000_EVENT919_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT919_HANDLING */
#define VX1000_EVENT919_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT919_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 912U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 920U
#if defined(VX1000_EVENT920_HANDLING)
#if ((VX1000_EVENT920_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT920_HANDLING */
#define VX1000_EVENT920_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT920_HANDLING */
#if defined(VX1000_EVENT921_HANDLING)
#if ((VX1000_EVENT921_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT921_HANDLING */
#define VX1000_EVENT921_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT921_HANDLING */
#if defined(VX1000_EVENT922_HANDLING)
#if ((VX1000_EVENT922_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT922_HANDLING */
#define VX1000_EVENT922_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT922_HANDLING */
#if defined(VX1000_EVENT923_HANDLING)
#if ((VX1000_EVENT923_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT923_HANDLING */
#define VX1000_EVENT923_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT923_HANDLING */
#if defined(VX1000_EVENT924_HANDLING)
#if ((VX1000_EVENT924_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT924_HANDLING */
#define VX1000_EVENT924_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT924_HANDLING */
#if defined(VX1000_EVENT925_HANDLING)
#if ((VX1000_EVENT925_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT925_HANDLING */
#define VX1000_EVENT925_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT925_HANDLING */
#if defined(VX1000_EVENT926_HANDLING)
#if ((VX1000_EVENT926_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT926_HANDLING */
#define VX1000_EVENT926_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT926_HANDLING */
#if defined(VX1000_EVENT927_HANDLING)
#if ((VX1000_EVENT927_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT927_HANDLING */
#define VX1000_EVENT927_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT927_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 920U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 928U
#if defined(VX1000_EVENT928_HANDLING)
#if ((VX1000_EVENT928_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT928_HANDLING */
#define VX1000_EVENT928_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT928_HANDLING */
#if defined(VX1000_EVENT929_HANDLING)
#if ((VX1000_EVENT929_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT929_HANDLING */
#define VX1000_EVENT929_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT929_HANDLING */
#if defined(VX1000_EVENT930_HANDLING)
#if ((VX1000_EVENT930_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT930_HANDLING */
#define VX1000_EVENT930_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT930_HANDLING */
#if defined(VX1000_EVENT931_HANDLING)
#if ((VX1000_EVENT931_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT931_HANDLING */
#define VX1000_EVENT931_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT931_HANDLING */
#if defined(VX1000_EVENT932_HANDLING)
#if ((VX1000_EVENT932_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT932_HANDLING */
#define VX1000_EVENT932_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT932_HANDLING */
#if defined(VX1000_EVENT933_HANDLING)
#if ((VX1000_EVENT933_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT933_HANDLING */
#define VX1000_EVENT933_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT933_HANDLING */
#if defined(VX1000_EVENT934_HANDLING)
#if ((VX1000_EVENT934_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT934_HANDLING */
#define VX1000_EVENT934_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT934_HANDLING */
#if defined(VX1000_EVENT935_HANDLING)
#if ((VX1000_EVENT935_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT935_HANDLING */
#define VX1000_EVENT935_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT935_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 928U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 936U
#if defined(VX1000_EVENT936_HANDLING)
#if ((VX1000_EVENT936_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT936_HANDLING */
#define VX1000_EVENT936_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT936_HANDLING */
#if defined(VX1000_EVENT937_HANDLING)
#if ((VX1000_EVENT937_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT937_HANDLING */
#define VX1000_EVENT937_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT937_HANDLING */
#if defined(VX1000_EVENT938_HANDLING)
#if ((VX1000_EVENT938_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT938_HANDLING */
#define VX1000_EVENT938_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT938_HANDLING */
#if defined(VX1000_EVENT939_HANDLING)
#if ((VX1000_EVENT939_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT939_HANDLING */
#define VX1000_EVENT939_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT939_HANDLING */
#if defined(VX1000_EVENT940_HANDLING)
#if ((VX1000_EVENT940_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT940_HANDLING */
#define VX1000_EVENT940_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT940_HANDLING */
#if defined(VX1000_EVENT941_HANDLING)
#if ((VX1000_EVENT941_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT941_HANDLING */
#define VX1000_EVENT941_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT941_HANDLING */
#if defined(VX1000_EVENT942_HANDLING)
#if ((VX1000_EVENT942_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT942_HANDLING */
#define VX1000_EVENT942_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT942_HANDLING */
#if defined(VX1000_EVENT943_HANDLING)
#if ((VX1000_EVENT943_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT943_HANDLING */
#define VX1000_EVENT943_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT943_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 936U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 944U
#if defined(VX1000_EVENT944_HANDLING)
#if ((VX1000_EVENT944_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT944_HANDLING */
#define VX1000_EVENT944_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT944_HANDLING */
#if defined(VX1000_EVENT945_HANDLING)
#if ((VX1000_EVENT945_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT945_HANDLING */
#define VX1000_EVENT945_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT945_HANDLING */
#if defined(VX1000_EVENT946_HANDLING)
#if ((VX1000_EVENT946_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT946_HANDLING */
#define VX1000_EVENT946_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT946_HANDLING */
#if defined(VX1000_EVENT947_HANDLING)
#if ((VX1000_EVENT947_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT947_HANDLING */
#define VX1000_EVENT947_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT947_HANDLING */
#if defined(VX1000_EVENT948_HANDLING)
#if ((VX1000_EVENT948_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT948_HANDLING */
#define VX1000_EVENT948_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT948_HANDLING */
#if defined(VX1000_EVENT949_HANDLING)
#if ((VX1000_EVENT949_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT949_HANDLING */
#define VX1000_EVENT949_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT949_HANDLING */
#if defined(VX1000_EVENT950_HANDLING)
#if ((VX1000_EVENT950_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT950_HANDLING */
#define VX1000_EVENT950_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT950_HANDLING */
#if defined(VX1000_EVENT951_HANDLING)
#if ((VX1000_EVENT951_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT951_HANDLING */
#define VX1000_EVENT951_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT951_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 944U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 952U
#if defined(VX1000_EVENT952_HANDLING)
#if ((VX1000_EVENT952_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT952_HANDLING */
#define VX1000_EVENT952_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT952_HANDLING */
#if defined(VX1000_EVENT953_HANDLING)
#if ((VX1000_EVENT953_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT953_HANDLING */
#define VX1000_EVENT953_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT953_HANDLING */
#if defined(VX1000_EVENT954_HANDLING)
#if ((VX1000_EVENT954_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT954_HANDLING */
#define VX1000_EVENT954_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT954_HANDLING */
#if defined(VX1000_EVENT955_HANDLING)
#if ((VX1000_EVENT955_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT955_HANDLING */
#define VX1000_EVENT955_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT955_HANDLING */
#if defined(VX1000_EVENT956_HANDLING)
#if ((VX1000_EVENT956_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT956_HANDLING */
#define VX1000_EVENT956_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT956_HANDLING */
#if defined(VX1000_EVENT957_HANDLING)
#if ((VX1000_EVENT957_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT957_HANDLING */
#define VX1000_EVENT957_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT957_HANDLING */
#if defined(VX1000_EVENT958_HANDLING)
#if ((VX1000_EVENT958_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT958_HANDLING */
#define VX1000_EVENT958_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT958_HANDLING */
#if defined(VX1000_EVENT959_HANDLING)
#if ((VX1000_EVENT959_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT959_HANDLING */
#define VX1000_EVENT959_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT959_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 952U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 960U
#if defined(VX1000_EVENT960_HANDLING)
#if ((VX1000_EVENT960_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT960_HANDLING */
#define VX1000_EVENT960_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT960_HANDLING */
#if defined(VX1000_EVENT961_HANDLING)
#if ((VX1000_EVENT961_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT961_HANDLING */
#define VX1000_EVENT961_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT961_HANDLING */
#if defined(VX1000_EVENT962_HANDLING)
#if ((VX1000_EVENT962_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT962_HANDLING */
#define VX1000_EVENT962_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT962_HANDLING */
#if defined(VX1000_EVENT963_HANDLING)
#if ((VX1000_EVENT963_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT963_HANDLING */
#define VX1000_EVENT963_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT963_HANDLING */
#if defined(VX1000_EVENT964_HANDLING)
#if ((VX1000_EVENT964_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT964_HANDLING */
#define VX1000_EVENT964_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT964_HANDLING */
#if defined(VX1000_EVENT965_HANDLING)
#if ((VX1000_EVENT965_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT965_HANDLING */
#define VX1000_EVENT965_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT965_HANDLING */
#if defined(VX1000_EVENT966_HANDLING)
#if ((VX1000_EVENT966_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT966_HANDLING */
#define VX1000_EVENT966_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT966_HANDLING */
#if defined(VX1000_EVENT967_HANDLING)
#if ((VX1000_EVENT967_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT967_HANDLING */
#define VX1000_EVENT967_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT967_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 960U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 968U
#if defined(VX1000_EVENT968_HANDLING)
#if ((VX1000_EVENT968_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT968_HANDLING */
#define VX1000_EVENT968_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT968_HANDLING */
#if defined(VX1000_EVENT969_HANDLING)
#if ((VX1000_EVENT969_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT969_HANDLING */
#define VX1000_EVENT969_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT969_HANDLING */
#if defined(VX1000_EVENT970_HANDLING)
#if ((VX1000_EVENT970_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT970_HANDLING */
#define VX1000_EVENT970_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT970_HANDLING */
#if defined(VX1000_EVENT971_HANDLING)
#if ((VX1000_EVENT971_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT971_HANDLING */
#define VX1000_EVENT971_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT971_HANDLING */
#if defined(VX1000_EVENT972_HANDLING)
#if ((VX1000_EVENT972_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT972_HANDLING */
#define VX1000_EVENT972_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT972_HANDLING */
#if defined(VX1000_EVENT973_HANDLING)
#if ((VX1000_EVENT973_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT973_HANDLING */
#define VX1000_EVENT973_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT973_HANDLING */
#if defined(VX1000_EVENT974_HANDLING)
#if ((VX1000_EVENT974_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT974_HANDLING */
#define VX1000_EVENT974_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT974_HANDLING */
#if defined(VX1000_EVENT975_HANDLING)
#if ((VX1000_EVENT975_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT975_HANDLING */
#define VX1000_EVENT975_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT975_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 968U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 976U
#if defined(VX1000_EVENT976_HANDLING)
#if ((VX1000_EVENT976_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT976_HANDLING */
#define VX1000_EVENT976_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT976_HANDLING */
#if defined(VX1000_EVENT977_HANDLING)
#if ((VX1000_EVENT977_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT977_HANDLING */
#define VX1000_EVENT977_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT977_HANDLING */
#if defined(VX1000_EVENT978_HANDLING)
#if ((VX1000_EVENT978_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT978_HANDLING */
#define VX1000_EVENT978_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT978_HANDLING */
#if defined(VX1000_EVENT979_HANDLING)
#if ((VX1000_EVENT979_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT979_HANDLING */
#define VX1000_EVENT979_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT979_HANDLING */
#if defined(VX1000_EVENT980_HANDLING)
#if ((VX1000_EVENT980_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT980_HANDLING */
#define VX1000_EVENT980_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT980_HANDLING */
#if defined(VX1000_EVENT981_HANDLING)
#if ((VX1000_EVENT981_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT981_HANDLING */
#define VX1000_EVENT981_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT981_HANDLING */
#if defined(VX1000_EVENT982_HANDLING)
#if ((VX1000_EVENT982_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT982_HANDLING */
#define VX1000_EVENT982_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT982_HANDLING */
#if defined(VX1000_EVENT983_HANDLING)
#if ((VX1000_EVENT983_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT983_HANDLING */
#define VX1000_EVENT983_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT983_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 976U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 984U
#if defined(VX1000_EVENT984_HANDLING)
#if ((VX1000_EVENT984_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT984_HANDLING */
#define VX1000_EVENT984_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT984_HANDLING */
#if defined(VX1000_EVENT985_HANDLING)
#if ((VX1000_EVENT985_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT985_HANDLING */
#define VX1000_EVENT985_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT985_HANDLING */
#if defined(VX1000_EVENT986_HANDLING)
#if ((VX1000_EVENT986_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT986_HANDLING */
#define VX1000_EVENT986_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT986_HANDLING */
#if defined(VX1000_EVENT987_HANDLING)
#if ((VX1000_EVENT987_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT987_HANDLING */
#define VX1000_EVENT987_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT987_HANDLING */
#if defined(VX1000_EVENT988_HANDLING)
#if ((VX1000_EVENT988_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT988_HANDLING */
#define VX1000_EVENT988_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT988_HANDLING */
#if defined(VX1000_EVENT989_HANDLING)
#if ((VX1000_EVENT989_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT989_HANDLING */
#define VX1000_EVENT989_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT989_HANDLING */
#if defined(VX1000_EVENT990_HANDLING)
#if ((VX1000_EVENT990_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT990_HANDLING */
#define VX1000_EVENT990_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT990_HANDLING */
#if defined(VX1000_EVENT991_HANDLING)
#if ((VX1000_EVENT991_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT991_HANDLING */
#define VX1000_EVENT991_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT991_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 984U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 992U
#if defined(VX1000_EVENT992_HANDLING)
#if ((VX1000_EVENT992_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT992_HANDLING */
#define VX1000_EVENT992_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT992_HANDLING */
#if defined(VX1000_EVENT993_HANDLING)
#if ((VX1000_EVENT993_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT993_HANDLING */
#define VX1000_EVENT993_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT993_HANDLING */
#if defined(VX1000_EVENT994_HANDLING)
#if ((VX1000_EVENT994_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT994_HANDLING */
#define VX1000_EVENT994_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT994_HANDLING */
#if defined(VX1000_EVENT995_HANDLING)
#if ((VX1000_EVENT995_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT995_HANDLING */
#define VX1000_EVENT995_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT995_HANDLING */
#if defined(VX1000_EVENT996_HANDLING)
#if ((VX1000_EVENT996_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT996_HANDLING */
#define VX1000_EVENT996_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT996_HANDLING */
#if defined(VX1000_EVENT997_HANDLING)
#if ((VX1000_EVENT997_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT997_HANDLING */
#define VX1000_EVENT997_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT997_HANDLING */
#if defined(VX1000_EVENT998_HANDLING)
#if ((VX1000_EVENT998_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT998_HANDLING */
#define VX1000_EVENT998_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT998_HANDLING */
#if defined(VX1000_EVENT999_HANDLING)
#if ((VX1000_EVENT999_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT999_HANDLING */
#define VX1000_EVENT999_HANDLING       (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT999_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 992U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 1000U
#if defined(VX1000_EVENT1000_HANDLING)
#if ((VX1000_EVENT1000_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1000_HANDLING */
#define VX1000_EVENT1000_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1000_HANDLING */
#if defined(VX1000_EVENT1001_HANDLING)
#if ((VX1000_EVENT1001_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1001_HANDLING */
#define VX1000_EVENT1001_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1001_HANDLING */
#if defined(VX1000_EVENT1002_HANDLING)
#if ((VX1000_EVENT1002_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1002_HANDLING */
#define VX1000_EVENT1002_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1002_HANDLING */
#if defined(VX1000_EVENT1003_HANDLING)
#if ((VX1000_EVENT1003_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1003_HANDLING */
#define VX1000_EVENT1003_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1003_HANDLING */
#if defined(VX1000_EVENT1004_HANDLING)
#if ((VX1000_EVENT1004_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1004_HANDLING */
#define VX1000_EVENT1004_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1004_HANDLING */
#if defined(VX1000_EVENT1005_HANDLING)
#if ((VX1000_EVENT1005_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1005_HANDLING */
#define VX1000_EVENT1005_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1005_HANDLING */
#if defined(VX1000_EVENT1006_HANDLING)
#if ((VX1000_EVENT1006_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1006_HANDLING */
#define VX1000_EVENT1006_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1006_HANDLING */
#if defined(VX1000_EVENT1007_HANDLING)
#if ((VX1000_EVENT1007_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1007_HANDLING */
#define VX1000_EVENT1007_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1007_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 1000U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 1008U
#if defined(VX1000_EVENT1008_HANDLING)
#if ((VX1000_EVENT1008_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1008_HANDLING */
#define VX1000_EVENT1008_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1008_HANDLING */
#if defined(VX1000_EVENT1009_HANDLING)
#if ((VX1000_EVENT1009_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1009_HANDLING */
#define VX1000_EVENT1009_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1009_HANDLING */
#if defined(VX1000_EVENT1010_HANDLING)
#if ((VX1000_EVENT1010_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1010_HANDLING */
#define VX1000_EVENT1010_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1010_HANDLING */
#if defined(VX1000_EVENT1011_HANDLING)
#if ((VX1000_EVENT1011_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1011_HANDLING */
#define VX1000_EVENT1011_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1011_HANDLING */
#if defined(VX1000_EVENT1012_HANDLING)
#if ((VX1000_EVENT1012_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1012_HANDLING */
#define VX1000_EVENT1012_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1012_HANDLING */
#if defined(VX1000_EVENT1013_HANDLING)
#if ((VX1000_EVENT1013_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1013_HANDLING */
#define VX1000_EVENT1013_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1013_HANDLING */
#if defined(VX1000_EVENT1014_HANDLING)
#if ((VX1000_EVENT1014_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1014_HANDLING */
#define VX1000_EVENT1014_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1014_HANDLING */
#if defined(VX1000_EVENT1015_HANDLING)
#if ((VX1000_EVENT1015_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1015_HANDLING */
#define VX1000_EVENT1015_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1015_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 1008U */
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 1016U
#if defined(VX1000_EVENT1016_HANDLING)
#if ((VX1000_EVENT1016_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1016_HANDLING */
#define VX1000_EVENT1016_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1016_HANDLING */
#if defined(VX1000_EVENT1017_HANDLING)
#if ((VX1000_EVENT1017_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1017_HANDLING */
#define VX1000_EVENT1017_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1017_HANDLING */
#if defined(VX1000_EVENT1018_HANDLING)
#if ((VX1000_EVENT1018_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1018_HANDLING */
#define VX1000_EVENT1018_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1018_HANDLING */
#if defined(VX1000_EVENT1019_HANDLING)
#if ((VX1000_EVENT1019_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1019_HANDLING */
#define VX1000_EVENT1019_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1019_HANDLING */
#if defined(VX1000_EVENT1020_HANDLING)
#if ((VX1000_EVENT1020_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1020_HANDLING */
#define VX1000_EVENT1020_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1020_HANDLING */
#if defined(VX1000_EVENT1021_HANDLING)
#if ((VX1000_EVENT1021_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1021_HANDLING */
#define VX1000_EVENT1021_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1021_HANDLING */
#if defined(VX1000_EVENT1022_HANDLING)
#if ((VX1000_EVENT1022_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1022_HANDLING */
#define VX1000_EVENT1022_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1022_HANDLING */
#if defined(VX1000_EVENT1023_HANDLING)
#if ((VX1000_EVENT1023_HANDLING) != (VX1000_EVENT_IS_UNUSED)) && (!defined(VX1000_OLDA_EVENT_MODE_OVERRIDE))
#define VX1000_OLDA_EVENT_MODE_OVERRIDE
#endif /* !VX1000_OLDA_EVENT_MODE_OVERRIDE */
#else  /* !VX1000_EVENT1023_HANDLING */
#define VX1000_EVENT1023_HANDLING      (VX1000_EVENT_IS_UNUSED)
#endif /* !VX1000_EVENT1023_HANDLING */
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 1016U */

#if (!defined(VX1000_COMPILED_FOR_SLAVECORES)) && (defined(VX1000_OLDA_EVENT_MODE_OVERRIDE) && ((VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 31U))
#define VX1000_START_SEC_CONST_UNSPECIFIED
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern const VX1000_VAR(VX1000_UINT8, VX1000_CONST_UNSPECIFIED) vx1000_oldaInitModeList_LE[((((VX1000_OLDA_ACTIVE_EVT_CNT_MAX) + 7UL) & 0xFFFFFFF8UL) >> 1U) + 1UL]; /* for successful memmapping in a MISRA-conform way, this actually function-local variable has to fake global scope */
extern const VX1000_VAR(VX1000_UINT8, VX1000_CONST_UNSPECIFIED) vx1000_oldaInitModeList_BE[((((VX1000_OLDA_ACTIVE_EVT_CNT_MAX) + 7UL) & 0xFFFFFFF8UL) >> 1U) + 1UL]; /* for successful memmapping in a MISRA-conform way, this actually function-local variable has to fake global scope */
#define VX1000_STOP_SEC_CONST_UNSPECIFIED
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES && VX1000_OLDA_EVENT_MODE_OVERRIDE && VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 31 */

#define VX1000_OLDA_VERSION            0x000BU          /* Olda Version 11 (common for all targets) */

/* TriCore legacy memory size and address defaults: if not specified by user, use 16Kb of EMEM (unless further overridden by resource management feature) */
#if defined(VX1000_TARGET_TRICORE)
#if !defined(VX1000_OLDA_MEMORY_SIZE)
#define VX1000_OLDA_MEMORY_SIZE        0UL
#endif /* VX1000_OLDA_MEMORY_SIZE */
#if (!defined(VX1000_OLDA_MEMORY_ADDR)) && (0UL==(VX1000_OLDA_MEMORY_SIZE))
#define VX1000_OLDA_MEMORY_ADDR        0UL
#endif /* !VX1000_OLDA_MEMORY_ADDR && !VX1000_OLDA_MEMORY_SIZE */
#endif /* VX1000_TARGET_TRICORE */
#if (!defined(VX1000_OLDA_MEMORY_SIZE)) && (!defined(VX1000_DISABLE_INSTRUMENTATION))
#error VX1000_OLDA_MEMORY_SIZE must be defined in VX1000_cfg.h!
#endif /* !VX1000_OLDA_MEMORY_SIZE */

/* Feature flags using first featureFlags field: */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE0 0x0000U /* (((0x0U << 15U) | (0x0U << 4U)) | (0x0U << 3U)) : all targets: 32bits in gVX1000 */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE1 0x0008U /* (((0x0U << 15U) | (0x0U << 4U)) | (0x1U << 3U)) : SHx: 16bits in AUDMBR; PowerPC: 32bits + 32duplicatebits in DTS; TC1xxx: 32bits in TRIGS; reserved on other targets */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE2 0x0010U /* (((0x0U << 15U) | (0x1U << 4U)) | (0x0U << 3U)) : TC24x..TC29x: 32bits in TRIGS; reserved on other targets */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE3 0x0018U /* (((0x0U << 15U) | (0x1U << 4U)) | (0x1U << 3U)) : TC21x..TC23x, TC3xx: 16bits in TRIGS; reserved on other targets */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE4 0x8000U /* (((0x1U << 15U) | (0x0U << 4U)) | (0x0U << 3U)) : all targets: 32bits + 32inversebits in gVX1000 */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE5 0x8008U /* (((0x1U << 15U) | (0x0U << 4U)) | (0x1U << 3U)) : all targets (except Tricore): event signalling via trace */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE6 0x8010U /* (((0x1U << 15U) | (0x1U << 4U)) | (0x0U << 3U)) : all targets: arbitrary length bitfield + 8bits "01010101" */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE7 0x8018U /* (((0x1U << 15U) | (0x1U << 4U)) | (0x1U << 3U)) : reserved */
#define VX1000_FEAT_OLDA_UNUSED_FLAG13 (1U << 13U) /* still free for future use */
#define VX1000_FEAT_OLDA_UNUSED_FLAG12 (1U << 12U) /* still free for future use */
#define VX1000_FEAT_OLDA_UNUSED_FLAG11 (1U << 11U) /* still free for future use */

#if defined(VX1000_TARGET_X850)

/* As workaround for users often forgetting to provide the needed #pragmas for their toolchain in VX1000_BEGSECT_VXMODULE_H configuration, we silently inject a pragma ourselves for the most common compilers: */
#if defined(__CX__) || defined(__ghs__)
#pragma pack(1) /* shall be removed (tends to lead to compile errors; other code parts that would suffer from the same problem that this line pretends to solve come without pragma) */
#endif /* __CX__ || __ghs__ */

#endif /* VX1000_TARGET_X850 */

#if defined(VX1000_COMPILER_REQ_IDENTIFIERS)
typedef VX1000_UINT8  VX1000_COPY_OFFLOAD_Q_FUNC_TYPE(  const VX1000_UINT32 VX1000_DECL_PTR * pJobDescriptions, VX1000_UINT32 jobCount);
typedef VX1000_UINT8  (*VX1000_COPY_OFFLOAD_Q_FUNC_P_T)(const VX1000_UINT32 VX1000_DECL_PTR * pJobDescriptions, VX1000_UINT32 jobCount);
#else  /* !VX1000_COMPILER_REQ_IDENTIFIERS */
typedef VX1000_UINT8  VX1000_COPY_OFFLOAD_Q_FUNC_TYPE(  const VX1000_UINT32 VX1000_DECL_PTR *, VX1000_UINT32);
typedef VX1000_UINT8  (*VX1000_COPY_OFFLOAD_Q_FUNC_P_T)(const VX1000_UINT32 VX1000_DECL_PTR *, VX1000_UINT32);
#endif /* !VX1000_COMPILER_REQ_IDENTIFIERS */
typedef VX1000_UINT32 VX1000_COPY_OFFLOAD_S_FUNC_TYPE(void);
typedef void VX1000_COPY_OFFLOAD_R_FUNC_TYPE(void);

typedef struct VX1000_CopyOffloadCap_t
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  supportedAccessSizes;              /* bitmask, bit0: char, bit1: short, bit2: long, bit3: long long, bit4: T_128, bit5: T_256 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  supportedAccessModes;              /* bitmask, bit0: fixedAddressMode, bit1: addrAutoIncrMode */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 cocPadding16;                      /* currently unused, always zero */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 maximumTransferBytes;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 supportedCopyTypes;                /* */
} VX1000_CopyOffloadCap_T;                                                     /* CopyOffloaderCapabilities */

typedef struct VX1000_CopyOffloadInfo_t
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 resetRequired;                     /* written by Firwmare                                                 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 coiStatus;                         /* current status of the CopyOffloader                                 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 lastEventNumberWithOverldMemory;   /* last event number where memory overload occurred                    */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  counterOverloadMemory;             /* when no memory is available for enqueueing additional copy commands */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  counterErrorGeneric;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  counterOverloadGeneric;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  coiPadding8;                       /* reserved for future use */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 coiPadding16;                      /* reserved for future use */
} VX1000_CopyOffloadInfo_T;                                                    /* CopyOffloaderInformation */

#if defined(VX1000_OLDA) && (((VX1000_CO_OFFLOADER_COUNT) > 0U) || defined(VX1000_ENABLE_RADAR_API))
typedef struct VX1000_CopyOffloadStatus_t
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 cosMagicID;                        /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  cosStructVer;                      /* 0x02 */ /* struct version of StatusInformation         */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  structVerCopyOffloaderInfo;        /* 0x03 */ /* struct version of VX1000_CopyOffloadInfo_T  */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  CopyOffloaderInfoStructSize;       /* 0x04 */ /* sizeof(VX1000_CopyOffloadInfo_T)            */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  numberOfCopyOffloaders;            /* 0x05 */ /* VX1000_NUMBER_OF_COPYOFFLOADERS             */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  numberOfTargetInterfaceErrors;     /* 0x06 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  counterOfStatusUpdates;            /* 0x07 */ /* is incremented each time the copy offloader status is updated */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 addrOfOffloaderInfos;              /* 0x08 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 addrOfOffloaderCapabilities;       /* 0x0C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 CopyOffloaderCfgStructSize;        /* 0x10 */ /* Size of the structure VX1000_CopyOffloadCfg_T, set by the FW */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 CopyOffloaderCfgStructVersion;     /* 0x12 */ /* Version of the structure CopyOf-floaderConfiguration */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 CopyOffloaderCapsStructSize;       /* 0x14 */ /* sizeof(VX1000_CopyOffloadCap_T) */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 CopyOffloaderCapsStructVersion;    /* 0x16 */ /* Struct Version of VX1000_CopyOffloadCap_T */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  rrdCounterOverloadMemory;          /* 0x18 */ /* incremented upon overrun of the copy offloaders job queue */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  rrdCounterErrorGeneric;            /* 0x19 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  rrdCounterOverloadGeneric;         /* 0x1A */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  rrdCurrentStatus;                  /* 0x1B */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  rrdCounterWillfulAbort;            /* 0x1C */ /* new in version 1 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  cosPadding8;                       /* reserved for future use */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 cosPadding16;                      /* reserved for future use */
#if ((VX1000_CO_OFFLOADER_COUNT) > 0U)
  VX1000_INNERSTRUCT_VOLATILE VX1000_CopyOffloadInfo_T offloaderInfos[VX1000_CO_OFFLOADER_COUNT];
  VX1000_INNERSTRUCT_VOLATILE VX1000_CopyOffloadCap_T offloaderCapabilities[VX1000_CO_OFFLOADER_COUNT];
  VX1000_INNERSTRUCT_VOLATILE VX1000_COPY_OFFLOAD_Q_FUNC_P_T    offloaderQueueFunction[VX1000_CO_OFFLOADER_COUNT]; /* used only AppDriver-internal by name, so no address of it needed. Also the volatile is unneeded/undesired, but because some compilers uses outer- and others INNERSTRUCT syntax, to avoid toolchain-dependend inherited volatility, make it always volatile */
  VX1000_COPY_OFFLOAD_S_FUNC_TYPE * VX1000_INNERSTRUCT_VOLATILE offloaderStateFunction[VX1000_CO_OFFLOADER_COUNT]; /* used only AppDriver-internal by name, so no address of it needed. Also the volatile is unneeded/undesired, but because some compilers uses outer- and others INNERSTRUCT syntax, to avoid toolchain-dependend inherited volatility, make it always volatile */
  VX1000_COPY_OFFLOAD_R_FUNC_TYPE * VX1000_INNERSTRUCT_VOLATILE offloaderResetFunction[VX1000_CO_OFFLOADER_COUNT]; /* used only AppDriver-internal by name, so no address of it needed. Also the volatile is unneeded/undesired, but because some compilers uses outer- and others INNERSTRUCT syntax, to avoid toolchain-dependend inherited volatility, make it always volatile */
#endif /* VX1000_CO_OFFLOADER_COUNT */
} VX1000_CopyOffloadStatus_T;                                                  /* StatusInformation */
#endif /* VX1000_OLDA && (VX1000_CO_OFFLOADER_COUNT || VX1000_ENABLE_RADAR_API) */

#if !defined(VX1000_IGNORE_MBUF_EVENTMODE)
typedef struct VX1000_multibuffer_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 startAddress; /* start address of the buffer */
} VX1000_MULTIBUFFER_T;

typedef struct VX1000_multibuffer_olda_event_T
{
  /* The following fields are written by the VX1000, read by the Application Driver */
  /* Address of a  MULTIBUFFER_T list containing the start addresses */
  /* of all multi-buffers used by the current event.                 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 multibufferDescriptor;
  /* Shall contain the total size of the measurement objects (payload data) in bytes. */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 slotSizeData;
  /* Shall contain the 4-byte timestamp + the payload data + any necessary           */
  /* padding to ensure 4-byte alignment + 4-byte overload counter. Size is in bytes. */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 slotSizeTotal;
  /* Shall specify the number of slots each buffer contains. */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 numSlots;
  /* Shall specify the number of buffers available for this event. */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 numBuffers;
  /* The following fields are used internally by the Application Driver */
  /* Index of the currently used multi-buffer. Shall be incremented (with wrap-around) once a buffer is full. */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 currentBufferIndex;
  /* Index of the currently free multi-buffer slot. Shall be incremented with each call to VX1000If_Event(). */
  /* Shall be reset when the currently active buffer is changed.                                             */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 currentSlotIndex;
  /* Counter used to detect error scenarios. Incremented each time writing to a previously unused buffer is started. */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 eventCounter;
} VX1000_MULTIBUFFER_OLDA_EVENT_T;
#endif /* !VX1000_IGNORE_MBUF_EVENTMODE */

typedef struct VX1000_olda_event_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     EventCounter;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     EventTimestampO;  /* NB: for OLDA stimulation, this field is used to store the address of the stimulation buffer */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     TransferDest;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     TransferIndex;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     TransferCount;   /* NB: for command based OLDA, this field is used to define the aligned size in bytes of the event's olda buffer */
} VX1000_OLDA_EVENT_T;

typedef struct VX1000_olda_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     MagicIdO;                  /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8      VersionO;                  /* 0x02 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8      Running;                   /* 0x03 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     MemoryAddr;                /* 0x04 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     MemorySize;                /* 0x08 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     EventCount;                /* 0x0A */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     EventList;                 /* 0x0C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     TransferList;              /* 0x10 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8      SizeLengthNOffset;         /* 0x14 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8      SizeSwapValue;             /* 0x15 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     OldaFeatures;              /* 0x16 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     OldaFeatures2;             /* 0x18 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     OldaBenchmarkCnt;          /* 0x1A */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     OldaFeatures3;             /* 0x1C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     MultiBufferEventList;      /* 0x20 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     OldaModeEvent0to7Legacy;   /* 0x24 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     OldaModeEvent8to15Legacy;  /* 0x28 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     OldaModeEvent16to23Legacy; /* 0x2C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     OldaModeEvent24to31Legacy; /* 0x30 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     MultiBufferEventCount;     /* 0x34 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16     OldaNumEventsMax;          /* 0x36 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     OldaTriggerAddr;           /* 0x38 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     OldaModesAddr;             /* 0x3C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     SpecialEventListAddr;      /* 0x40 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     OldaOffloaderAddr;         /* 0x44 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     SpecialEventTransferList;  /* 0x48 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     SpecialEventCount;         /* 0x4C */
#if ((VX1000_CO_OFFLOADER_COUNT) > 0U) || defined(VX1000_ENABLE_RADAR_API)
  VX1000_INNERSTRUCT_VOLATILE VX1000_CopyOffloadStatus_T offloadStatus;
#endif /* VX1000_CO_OFFLOADER_COUNT || VX1000_ENABLE_RADAR_API*/
#if (VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 31U
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8      OldaTriggerBits[(((VX1000_UINT32)(VX1000_OLDA_ACTIVE_EVT_CNT_MAX) + ((1UL /*special event channel*/ + 8UL/*validator pattern*/) + 31UL/*aligner*/)) >> 3) & 0xFFFFFFFCUL];
#endif /* VX1000_OLDA_ACTIVE_EVT_CNT_MAX > 31 */
  /* ! note: if further fields were to be added here, then OldaTriggerAddr+OldaModesAddr fields above will become non-optional ! */
#if !defined(VX1000_OLDA_MEMORY_ADDR)
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32     Data[(VX1000_OLDA_MEMORY_SIZE) >> 2U];
#endif /* !VX1000_OLDA_MEMORY_ADDR */
} VX1000_OLDA_T;

#if defined(VX1000_TARGET_X850)

/* As workaround for users often forgetting to provide the needed #pragmas for restoring previous padding strategy of their toolchain in VX1000_ENDSECT_VXMODULE_H configuration, we silently inject a pragma ourselves for the most common compilers: */
#if defined(__CX__)
/* Renesas CX compiler syntax. ATTENTION: this may differ from original setting of the user's project so his application inherits this new setting exactly in those files that include VX1000.h! */
#pragma pack(4) /* shall be removed */
#elif defined(__ghs__)
/* GHS compiler syntax */
#pragma pack() /* shall be removed */
#endif /* __ghs__ */

#endif /* VX1000_TARGET_X850 */

#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(void, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_SpecialEvent)( VX1000_UINT32 SpecEv );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#if !defined(VX1000_SUPPRESS_IPO_API)
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_OldaEventBarrier)( VX1000_UINT32 eventNum );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_SUPPRESS_IPO_API */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_OldaEvent)( VX1000_UINT32 eventNumber, VX1000_UINT32 t0 );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_OLDA_EVENT_COUNT2       (VX1000_OLDA_EVENT_COUNT)
#define VX1000_OLDA_BENCHMARK_CNT2     (VX1000_OLDA_BENCHMARK_CNT)
#define VX1000_OLDA_DATA               VX1000_OLDA_T Olda                                                                                                      /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#define VX1000_OLDA_PTR                (VX1000_PTR2VO_TO_ADDRESS(&gVX1000.Olda))

#if defined(VX1000_OLDA_BENCHMARK)
/* The problem with this is that it does not follow the VX1000-prefix rule, but we cannot correct it because users' A2L files already reference it using the bad names: */
#if defined(VX1000_COMPILED_FOR_SLAVECORES) && defined(VX1000_MAINCORE_VX_STRUCT_ADDR)
#define gVX1000_OLDA_Duration          VX1000_ADDR_TO_PTR2VU32(gVX1000.OldaDurArrayPtr)
#else  /* !VX1000_COMPILED_FOR_SLAVECORES || !VX1000_MAINCORE_VX_STRUCT_ADDR */
#define VX1000_START_SEC_VAR_NOCACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) gVX1000_OLDA_Duration[VX1000_OLDA_BENCHMARK_CNT2];
#define VX1000_STOP_SEC_VAR_NOCACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES || !VX1000_MAINCORE_VX_STRUCT_ADDR */
#define VX1000_OLDA_BENCHMARK_DATA     VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) gVX1000_OLDA_Duration[VX1000_OLDA_BENCHMARK_CNT2]                                                         /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#define VX1000_OLDA_DURARRAY_PTR       (VX1000_PTR2U32_TO_ADDRESS(gVX1000_OLDA_Duration))
#else /* !VX1000_OLDA_BENCHMARK */
#define VX1000_OLDA_DURARRAY_PTR       0UL
#endif /* VX1000_OLDA_BENCHMARK */

typedef struct VX1000_CopyOffloadCfg_t
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 cocSrcAddr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 cocDstAddr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 numberOfBytesToCopy;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 cocUsrInfo_LittleEndian;   /* Bits 0-3 srcAccessSize,                                               */
                                                                       /* read as 0: byte, 1: short, 2: 32bit, 3: 64bit, 4: 128bit, 5: 256bit,  */
                                                                       /* Bits 4-7 AccessMode,                                                  */
                                                                       /* 0: autoincrement addr, 1: non-autoincrement addr,                     */
                                                                       /* Bits 8-11 dstAccessSize,                                              */
                                                                       /* store as 0: byte, 1: short, 2: 32bit, 3: 64bit, 4: 128bit, 5: 256bit, */
                                                                       /* Bits 12-15 AccessMode,                                                */
                                                                       /* 0: autoincrement addr, 1: non-autoincrement addr,                     */
                                                                       /* 2: Memsync-Copy (academic spec, no use case)                          */
                                                                       /* Bits 16-23 May be used in the future                                  */
                                                                       /* Bits 24-31 Index of the Copy Offloader that shall be used.            */
                                                                       /* Note: "OffloaderIndex==DMAChannelNumber" where                        */
                                                                       /*       0x00..0xFE==<use value as channelnumber>                        */
                                                                       /*       0xFF==<use coreID for ChannelNumber>                            */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 cocSysInfo_LittleEndian;   /* Bit0 patchDasDaqAddr,                                                 */
                                                                       /* 0: Do not set srcAddr, 1: Compute srcAddr according to DAS-offset,    */
                                                                       /* Bit1 patchDasMetadataAddr (used for header and for footer),           */
                                                                       /* 0: Do not adjust srcAddr, 1: Adjust srcAddr based on DAS-Index,       */
                                                                       /* Bits 4-15 DASindex (optional, see bits 0 and 1)                       */
                                                                       /* Bits 16-31 Misc (e.g. pool-base-related DAS object start offset)      */
} VX1000_CopyOffloadCfg_T;

/* Internally used macros and/or "user's API" backends of VX1000If_CoGetDstDatatype(), VX1000If_CoGetSrcDatatype(), VX1000If_CoGetDstAddr(),    */
/* VX1000If_CoGetSrcAddr(), VX1000If_CoGetCopysize(), VX1000If_CoGetDoSrcInc(), VX1000If_CoGetDoDstInc() and VX1000If_CoNext() for the usage    */
/* exclusively inside the VX1000_CO_FUNCP_ENQUEUE_xx() callbacks of the user */
#if (VX1000_CO_OFFLOADER_COUNT) > 0U
#define VX1000_CO_NEXT(P)                      (P) = &(P)[gVX1000.Olda.offloadStatus.CopyOffloaderCfgStructSize >> 2];                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_CO_OFFLOADER_COUNT */
#define VX1000_CO_NEXT(P)                      /* empty statement */
#endif /* !VX1000_CO_OFFLOADER_COUNT */
#define VX1000_CO_GET_EVENTNUMBER(P)           ((VX1000_ADDR_TO_PTR2VU32((P)[0])[0]) >> 16) /* Note: must only be used before the offloader starts enqueuing/processing the first block */     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_RW_PTR_TO_SRCADDR(P)     (VX1000_ADDR_TO_PTR2VU32(VX1000_PTR2CU32_TO_ADDRESS(P)))                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_SRCADDR(P)               ((P)[0])                                                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DESTADDR(P)              ((P)[1])                                                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_COPYSIZE(P)              ((P)[2]) /* byte count */                                                                                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DO_SRCINC(P)             (0x0001UL & (~(P)[3] >> (/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0] != (VX1000_UINT8)(0xFFU & (VX1000_OLDA_MAGIC)))? 28:*/4)))              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DO_DSTINC(P)             (((0x0003UL & ((P)[3] >> (/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0] != (VX1000_UINT8)(0xFFU & (VX1000_OLDA_MAGIC)))? 20:*/12)))!=1UL)? 1UL:0UL)/* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DO_MEMSYNC(P)            (((0x0003UL & ((P)[3] >> (/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0] != (VX1000_UINT8)(0xFFU & (VX1000_OLDA_MAGIC)))? 20:*/12)))==2UL)? 1UL:0UL)/* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_SRC_DATATYPE(P)          (0x000FUL & ((P)[3] >> (/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0] != (VX1000_UINT8)(0xFFU & (VX1000_OLDA_MAGIC)))? 24:*/0)))               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DST_DATATYPE(P)          (0x000FUL & ((P)[3] >> (/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0] != (VX1000_UINT8)(0xFFU & (VX1000_OLDA_MAGIC)))? 16:*/8)))               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_ARE_PATCHES_USED(P)      (((0x000FUL & ((P)[4] >> (/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0] != (VX1000_UINT8)(0xFFU & (VX1000_OLDA_MAGIC)))? 16:*/0)))!=3UL)? 1UL:0UL)/* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DO_PATCH4VXSF(P)         (((0x000FUL & ((P)[4] >> (/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0] != (VX1000_UINT8)(0xFFU & (VX1000_OLDA_MAGIC)))? 16:*/0)))==2UL)? 1UL:0UL)/* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#if defined(VX1000_DYNADDRSIG_ENABLED)
#define VX1000_CO_GET_DO_PATCH4DAS(P)          (((0x000FUL & ((P)[4] >> (/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0] != (VX1000_UINT8)(0xFFU & (VX1000_OLDA_MAGIC)))? 16:*/0)))==1UL)? 1UL:0UL)/* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else  /* !VX1000_DYNADDRSIG_ENABLED */
#define VX1000_CO_GET_DO_PATCH4DAS(P)          (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_DYNADDRSIG_ENABLED */
#define VX1000_CO_GET_DAS_INDEX(P)             (0x0FFFUL & ((P)[4] >> (/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0] != (VX1000_UINT8)(0xFFU & (VX1000_OLDA_MAGIC)))? 20:*/4)))               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_POOLOFFSET16(P)          ((VX1000_ADDR_TO_PTR2U16(VX1000_PTR2CU32_TO_ADDRESS(P)))[9]) /* Note: inside AD code must also be usable as C-lvalue so cast away the "const" *//* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#if (VX1000_CO_OFFLOADER_COUNT) > 1U
#define VX1000_CO_GET_OFFLOADER_INDEX(P) (((0x00FFUL&((P)[3]>>(/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0]!=(VX1000_UINT8)(0xFFU&(VX1000_OLDA_MAGIC)))?0:*/24)))!=0xFFUL)?(0x00FFUL&((P)[3]>>(/*((VX1000_ADDR_TO_PTR2U8(gVX1000.OldaPtr))[0]!=(VX1000_UINT8)(0xFFU&(VX1000_OLDA_MAGIC)))?0:*/24))):((((VX1000_UINT32)VX1000_CURRENT_CORE_IDX())<((VX1000_UINT32)(VX1000_CO_OFFLOADER_COUNT)))?(VX1000_CURRENT_CORE_IDX()):0UL))/* PRQA S 3453 */ /* Violating MISRA rule 19.7 to be able to provide configurable API */
#else  /* VX1000_CO_OFFLOADER_COUNT==1 */
#define VX1000_CO_GET_OFFLOADER_INDEX(P)       (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* VX1000_CO_OFFLOADER_COUNT==1 */

#else /* !VX1000_OLDA */

#define VX1000_OLDA_PTR                0UL
#define VX1000_OLDA_DURARRAY_PTR       0UL

/* dummy "User's API" for the VX1000_CO_FUNCP_ENQUEUE_xx callbacks when OLDA feature is disabled */
#define VX1000_CO_NEXT(P)                      /* empty statement */
#define VX1000_CO_GET_EVENTNUMBER(P)           (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_RW_PTR_TO_SRCADDR(P)     (0UL) /* actually never used when no offloaders are present, only here for completeness of the "API" list */                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_SRCADDR(P)               (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DESTADDR(P)              (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_COPYSIZE(P)              (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DO_SRCINC(P)             (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DO_DSTINC(P)             (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DO_MEMSYNC(P)            (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_SRC_DATATYPE(P)          (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DST_DATATYPE(P)          (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_ARE_PATCHES_USED(P)      (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DO_PATCH4VXSF(P)         (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DO_PATCH4DAS(P)          (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_DAS_INDEX(P)             (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_POOLOFFSET16(P)          (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CO_GET_OFFLOADER_INDEX(P)       (0UL)                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */

#endif /* !VX1000_OLDA */
#if !defined(VX1000_DISABLE_INSTRUMENTATION)
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_LegacyEventTrigger)( VX1000_UINT32 event_number, VX1000_UINT32 time_Stamp, VX1000_UINT32 syncOverride, VX1000_UINT32 actionMaskVarPart);
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_LegacyEventTrigger)( VX1000_UINT32 event_number, VX1000_UINT32 time_Stamp, VX1000_UINT32 actionMaskVarPart);
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

/* Defines used for the copy offloader feature descriptions in VX1000_cfg.h */
#define VX1000_CO_ACCESS_SIZE_8BIT     0x01U
#define VX1000_CO_ACCESS_SIZE_16BIT    0x02U
#define VX1000_CO_ACCESS_SIZE_32BIT    0x04U
#define VX1000_CO_ACCESS_SIZE_64BIT    0x08U
#define VX1000_CO_ACCESS_SIZE_128BIT   0x10U
#define VX1000_CO_ACCESS_SIZE_256BIT   0x20U
#define VX1000_CO_ADDRESS_MODE_FIXSRC  0x01U
#define VX1000_CO_ADDRESS_MODE_INCSRC  0x02U
#define VX1000_CO_ADDRESS_MODE_FIXDST  0x04U
#define VX1000_CO_ADDRESS_MODE_INCDST  0x08U
#define VX1000_CO_COPY_TYPE_SIMPLECOPY 0x01U
#define VX1000_CO_COPY_TYPE_MEMSYNC    0x02U


/*------------------------------------------------------------------------------ */
/* Driver Error Logger                                                           */

#define VX1000_ERRLOG_NO_ERROR         0x0000U /* no error at all */

#define VX1000_ERRLOG_STRUCTS_PADDED   0x0101U /* due to bad compiler settings, the VX1000 structures were padded (but they must be packed) */
#define VX1000_ERRLOG_JTAGID_UNKNOWN   0x0102U /* the driver found a derivative that it does not know how to handle (e.g. support was de-configured to reduce code size) */
#define VX1000_ERRLOG_TYPESIZE_INVAL   0x0103U /* due to bad compiler settings or wrong user configuration the VX1000_xxxINTxx typedefs result in wrong byte size */
#define VX1000_ERRLOG_PTR_NONREPSTBL   0x0104U /* the driver received a linear pointer from the tool that has no valid representation in the used compiler memory model */
#define VX1000_ERRLOG_TOO_MANY_CORES   0x0105U /* VX1000_CURRENT_CORE_IDX() returned a core index that exceeds the configured maximum */
#define VX1000_ERRLOG_BAD_PRINTTOKEN   0x0106U /* the user called the debug print API with a format string that contains a token type that is not supported */
#define VX1000_ERRLOG_MEAS_CFG_OOR     0x0107U /* the user called the VX1000_MEAS_ADD-API more often than his configuration of VX1000_MEAS_CFG_RAMSIZE allows. */
#define VX1000_ERRLOG_MEAS_BADPARM     0x0108U /* the user called the VX1000_MEAS_ADD-API with parameters that result in a descriptor list that is not parsable. */
#define VX1000_ERRLOG_DIGRF_UNIMPL     0x0109U /* either the derivative is too old (no HW implementation) or too new (no SW implementation, yet), so DIGRF/HSCT/RHSIF/SIPI will not work */
#define VX1000_ERRLOG_SLAVECORE_DIFF   0x010AU /* an outdated slave core image got booted whose configuration no longer matches the AppDriver structure format on the main core */
#define VX1000_ERRLOG_DIGRF_BADPLLFREQ 0x010BU /* TC4xx has a fixed fractional divider of 2.5 for HSCT high speed clock. This error is logged when the user definitely did not configure 800MHz in his peripheral PLL. */
#define VX1000_ERRLOG_DIGRF_UNKNOWNCLK 0x010CU /* TC4xx standard 800MHz configuration of peripheral PLL SFRs was not found. If HSCT does not work, probably this is the reason for it */
#define VX1000_ERRLOG_DIGRF_POWERDOWN  0x010DU /* TC4xx by default gates clock to HSCT module. Ungating is not possible from any core at any time. This error indicates that ungating failed */

#define VX1000_ERRLOG_TM_RESO_TOO_LOW  0x0201U /* the resolution of the timer is too low for some features */
#define VX1000_ERRLOG_TM_RESO_TOO_HIGH 0x0202U /* the resolution of the timer is too high for some features */
#define VX1000_ERRLOG_TM_DT_IS_ZERO    0x0203U /* due to a low resolution, the conversion from a non-zero time resulted in a tick count of zero */
#define VX1000_ERRLOG_TM_DTDT_TOO_LONG 0x0204U /* the user requested a VX1000_DETECT() timeout that cannot be represented within the available bit slice */
#define VX1000_ERRLOG_TM_DTCS_TOO_LONG 0x0205U /* the user requested a VX1000_INIT() timeout that cannot be represented within the available bit slice */
#define VX1000_ERRLOG_TM_DTST_TOO_LONG 0x0206U /* the user called the STIM API with a timeout that cannot be represented within the available bit slice */
#define VX1000_ERRLOG_TM_DTSR_TOO_LONG 0x0207U /* the user requested a VX1000_PREPARE_SOFTRESET() timeout that cannot be represented within the available bit slice */

#define VX1000_ERRLOG_OLDA_UNIMPLCMD   0x0301U /* the olda descriptors contain an unimplemented command */
#define VX1000_ERRLOG_OLDA_UNIMPLSUB   0x0302U /* the olda descriptors contain an unimplemented subcommand */
#define VX1000_ERRLOG_OLDA_BUFINVAL    0x0303U /* the olda buffer is linked to an invalid address / not linked at all */
#define VX1000_ERRLOG_OLDA_BUFSMALL    0x0304U /* the olda buffer was configured too small */
#define VX1000_ERRLOG_OLDA_BIGENDIAN   0x0305U /* the olda copy offloader cfg struct was specified little-endian. To speed up the AD, the code for endian-correction is disabled in this build, so offloaders are suppressed on this big endian target */

#define VX1000_ERRLOG_OVL_INVALID_PAGE 0x0401U /* the XCP master requested a page number > 1 which is not supported by the driver */
#define VX1000_ERRLOG_OVL_INVALID_SIZE 0x0402U /* the user specified an overlay size that is not supported by the hardware/driver */
#define VX1000_ERRLOG_OVL_MISALIGNED   0x0403U /* the user specified an overlay alignment that is not supported by the hardware/driver */
#define VX1000_ERRLOG_OVL_TOO_MANY     0x0404U /* the XCP master requested a segment number > 1 which is not supported by the driver */
#define VX1000_ERRLOG_OVL_USER_FAILED  0x0405U /* a user's overlay callback returned a value != 0 */
#define VX1000_ERRLOG_OVL_UNIMPL       0x0406U /* code was triggered that is not implemented for the derivative it is executed on */
#define VX1000_ERRLOG_OVL_NONEXCLUSIVE 0x0407U /* the AppDriver was triggered to handle overlays but not all descriptors were assigned to his control */

/* reserved range for DAS:             0x05xxU */

#define VX1000_ERRLOG_STIM_EVENT_OOR   0x0601U /* the user called a STIM API with an event number that is out of the valid range */
#define VX1000_ERRLOG_STIM_BAD_HBBTYPE 0x0602U /* the user called the HBB register API with an invalid mode parameter */

#define VX1000_ERRLOG_MX_API_DEADLOCK  0x0701U /* an XCP command of a type that the user decided not to handle got stuck in the head of the mailbox queue for more than 1000 API calls */
#define VX1000_ERRLOG_MX_ON_SLAVECORE  0x0702U /* a (non-threadsafe) mailbox API has been called by a core that is not meant for mailbox handling */

#define VX1000_ERRLOG_RES_TOO_MANY     0x0801U /* the user tried to assign during runtime more single resources to the VX than his configured resource descriptor space allows */
#define VX1000_ERRLOG_RES_INVALID_TYPE 0x0802U /* the user passed an inconsistent or unsupported type during a resource assignment */

#if (VX1000_ERRLOG_SIZE != 0U)
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(void, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_ErrLogger)( VX1000_UINT16 ErrorCode );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_ERRLOG_DATA             VX1000_UINT16 ErrLog[VX1000_ERRLOG_SIZE]
#define VX1000_ERRLOG_ADDR             (VX1000_PTR2VU16_TO_ADDRESS(gVX1000.ErrLog))
#else /* !VX1000_ERRLOG_SIZE */
#define VX1000_ERRLOG_ADDR             0UL
#endif /* !VX1000_ERRLOG_SIZE */


/*------------------------------------------------------------------------------ */
/* VX1000 Stimulation                                                            */

/* STIM event API return codes */
#define VX1000_STIM_RET_INACTIVE       0U
#define VX1000_STIM_RET_SUCCESS        1U
#define VX1000_STIM_RET_TIMEOUT        2U
#define VX1000_STIM_RET_ERROR          3U

#if defined(VX1000_STIM)

#define VX1000_STIM_MAGIC              0xFEC70A07UL
#define VX1000_STIM_EVENT_MAGIC        0xFEC70A19UL

#if !defined(VX1000_STIM_FORCE_V1)
typedef struct VX1000_stim_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MagicIdS;          /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 VersionS;          /* 0x04 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 Control;           /* 0x06 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  EvtOffset;         /* 0x08 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  EvtNumber;         /* 0x09 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 Padding1;          /* 0x0A */
  struct VX1000_stim_event                                     /* 0x0C */
  {
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 Ctr;              /* 0x0C + 4*e */
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 RqCtr;            /* 0x0D + 4*e */
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 Enable;           /* 0x0E + 4*e */
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 Copying;          /* 0x0F + 4*e */
  } Event[VX1000_STIM_EVENT_COUNT];
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 EnableS;           /* 0x0C + 4*VX1000_STIM_EVENT_COUNT */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 TimeoutCtr;        /* 0x0E + 4*VX1000_STIM_EVENT_COUNT */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 TimeoutCtr2;       /* 0x10 + 4*VX1000_STIM_EVENT_COUNT */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 Padding2;          /* 0x12 + 4*VX1000_STIM_EVENT_COUNT */
} VX1000_STIM_T;
#define VX1000_STIMEVENT_ARRAYNAME gVX1000.Stim.Event
#else /* VX1000_STIM_FORCE_V1 */
typedef struct VX1000_stim_event_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MagicIdSE;         /* 0x20 + 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 VersionSE;         /* 0x20 + 0x04 */
  struct VX1000_stim_event                                     /* 0x20 + 0x08 */
  {
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 EventType;        /* 0x20 + 0x08 + 8*e */
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 DaqEvent;         /* 0x20 + 0x09 + 8*e */
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 Enable;           /* 0x20 + 0x0A + 8*e */
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 Copying;          /* 0x20 + 0x0B + 8*e */
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 Ctr;              /* 0x20 + 0x0C + 8*e */
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 RqCtr;            /* 0x20 + 0x0D + 8*e */
    VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 Reserved;        /* 0x20 + 0x0E + 8*e */
  } Event[VX1000_STIM_EVENT_COUNT];
} VX1000_STIM_EVENT_T;

typedef struct VX1000_hbb_vx_table_entry_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 StimEvent;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 ReservedHBB;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 OldaAddress;
} VX1000_HBB_VX_TABLE_ENTRY_T;

typedef struct VX1000_stim_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MagicIdS;          /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 VersionS;          /* 0x04 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 Control;           /* 0x06 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 EvtOffset;          /* 0x08 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8 EvtNumber;          /* 0x09 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 EnableS;           /* 0x0a */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 EventPointer;      /* 0x0c */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 TimeoutCtr;        /* 0x10 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 TimeoutCtr2;       /* 0x12 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 hbbLUTNumber;      /* 0x14 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 hbbLUTPointer;     /* 0x18 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 hbbLUTVXPointer;   /* 0x1c */
  VX1000_STIM_EVENT_T Events;                                  /* 0x20 */ /* attention: no reserved field for future extensions! */
} VX1000_STIM_T;
#define VX1000_STIMEVENT_ARRAYNAME     gVX1000.Stim.Events.Event
#endif /* VX1000_STIM_FORCE_V1 */

#if (VX1000_STIM_EVENT_OFFSET != 0U)
#define VX1000_STIMEVENT_ARRAYINDEXA   (stim_event - (VX1000_UINT8)(VX1000_STIM_EVENT_OFFSET))
#define VX1000_STIMEVENT_ARRAYINDEXB   (Stim_Event - (VX1000_UINT8)(VX1000_STIM_EVENT_OFFSET))
#define VX1000_STIMEVENT_ARRAYINDEXC   (stim_Event - (VX1000_UINT8)(VX1000_STIM_EVENT_OFFSET))
#define VX1000_STIMEVENT_ARRAYINDEXD   (Stim_event - (VX1000_UINT8)(VX1000_STIM_EVENT_OFFSET))
#define VX1000_STIMEVENT_ARRAYINDEXE   (stimevent  - (VX1000_UINT8)(VX1000_STIM_EVENT_OFFSET))
#define VX1000_STIMEVENT_ARRAYINDEXF   (StimEvent  - (VX1000_UINT8)(VX1000_STIM_EVENT_OFFSET))
#define VX1000_STIMEVENT_ARRAYINDEXG   (stimEvent  - (VX1000_UINT8)(VX1000_STIM_EVENT_OFFSET))
#define VX1000_STIMEVENT_ARRAYINDEXH   (Stimevent  - (VX1000_UINT8)(VX1000_STIM_EVENT_OFFSET))
#else  /* !VX1000_STIM_EVENT_OFFSET */
#define VX1000_STIMEVENT_ARRAYINDEXA   (stim_event)
#define VX1000_STIMEVENT_ARRAYINDEXB   (Stim_Event)
#define VX1000_STIMEVENT_ARRAYINDEXC   (stim_Event)
#define VX1000_STIMEVENT_ARRAYINDEXD   (Stim_event)
#define VX1000_STIMEVENT_ARRAYINDEXE   (stimevent )
#define VX1000_STIMEVENT_ARRAYINDEXF   (StimEvent )
#define VX1000_STIMEVENT_ARRAYINDEXG   (stimEvent )
#define VX1000_STIMEVENT_ARRAYINDEXH   (Stimevent )
#endif /* !VX1000_STIM_EVENT_OFFSET */

/* STIM event enable flag     */
#define VX1000_STIM_INACTIVE           0U
#define VX1000_STIM_VX_ENABLE          1U
#define VX1000_STIM_DAQ_SENT           2U
#define VX1000_STIM_BUFFER_VALID       3U
#define VX1000_STIM_BUFFER_INVALID     4U

/* STIM event global enable   */
#define VX1000_STIM_GLOBAL_INACTIVE    0U
#define VX1000_STIM_GLOBAL_VX_ENABLE   1U
#define VX1000_STIM_GLOBAL_ALL_CHAN    2U

/* STIM event types           */
#define VX1000_BYPASS_TYPE_DIRECT      1U
#define VX1000_BYPASS_TYPE_OLDA        2U
#define VX1000_BYPASS_TYPE_HOOK        3U

/* Copy Active Flag meanings - used for direct stimulation  */
#define VX1000_BP_CPACT_WAITING_DAQ    0U
#define VX1000_BP_CPACT_WAITING_STIM   1U
#define VX1000_BP_CPACT_DATA_READY     2U
#define VX1000_BP_CPACT_COPYING        3U

#define VX1000_BP_TIMESTAMP_SIZE       4UL


/* stim API */
#define VX1000_STIM_DATA               VX1000_STIM_T Stim
#define VX1000_STIM_PTR                (VX1000_PTR2VS_TO_ADDRESS(&gVX1000.Stim))
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_StimWait)( VX1000_UINT8 stim_event, VX1000_UINT8 copy_enable, VX1000_UINT32 timeout_us );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#if defined(VX1000_STIM_BY_OLDA)
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_Stimulate)( VX1000_UINT8 stim_trigger_event, VX1000_UINT8 stim_event, VX1000_UINT8 cycle_delay, VX1000_UINT32 timeout_us);
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_STIM_BY_OLDA */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_StimControl)( void );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_StimGetCurrentState)( VX1000_UINT8 stim_event );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_BypassTrigger)( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_BypassDaq) ( VX1000_UINT8 daq_event, VX1000_UINT8 stim_eventBD );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_BypassWait)( VX1000_UINT8 stimevent, VX1000_UINT32 timeout_US);
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_Bypass)( VX1000_UINT8 daq_Event, VX1000_UINT8 stim_Event, VX1000_UINT32 timeout_in_us );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_RegisterStimEvent)( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event, VX1000_UINT8 stim_type);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#if defined(VX1000_STIM_BENCHMARK)
/* note: separate array "gVX1000_STIM_Begin" now embedded in VX1000 param structure ("gVX1000.tmp.StimBegArray") */
#if defined(VX1000_COMPILED_FOR_SLAVECORES) && defined(VX1000_MAINCORE_VX_STRUCT_ADDR)
#define gVX1000_STIM_Duration          VX1000_ADDR_TO_PTR2VU32(gVX1000.StimDurArrayPtr)
#else  /* !VX1000_COMPILED_FOR_SLAVECORES || !VX1000_MAINCORE_VX_STRUCT_ADDR */
#define VX1000_START_SEC_VAR_NOCACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) gVX1000_STIM_Duration[VX1000_STIM_EVENT_COUNT];
#define VX1000_STOP_SEC_VAR_NOCACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES || !VX1000_MAINCORE_VX_STRUCT_ADDR */
#if defined(VX1000_STIM_HISTOGRAM)
#if defined(VX1000_COMPILED_FOR_SLAVECORES) && defined(VX1000_MAINCORE_VX_STRUCT_ADDR)
#define gVX1000_STIM_Histogram         VX1000_ADDR_TO_PTR2VU32(gVX1000.tmp.StimHist1ArrayPtr)
#define gVX1000_STIM_Histogram2        VX1000_ADDR_TO_PTR2VU32(gVX1000.tmp.StimHist2ArrayPtr)
#else  /* !VX1000_COMPILED_FOR_SLAVECORES || !VX1000_MAINCORE_VX_STRUCT_ADDR */
#define VX1000_START_SEC_VAR_NOCACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) gVX1000_STIM_Histogram[256];
extern volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) gVX1000_STIM_Histogram2[16];
#define VX1000_STOP_SEC_VAR_NOCACHE_ALIGN_4
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES || !VX1000_MAINCORE_VX_STRUCT_ADDR */
#define VX1000_STIM_BENCHMARK_DATA     volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) gVX1000_STIM_Duration[VX1000_STIM_EVENT_COUNT]; volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) gVX1000_STIM_Histogram[256]; volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) gVX1000_STIM_Histogram2[16]/* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 because additional parentheses would render the code un-compilable */
#else /* !VX1000_STIM_HISTOGRAM */
#define VX1000_STIM_BENCHMARK_DATA     volatile VX1000_VAR(VX1000_UINT32, VX1000_VAR_NOCACHE_ALIGN_4) gVX1000_STIM_Duration[VX1000_STIM_EVENT_COUNT]
#endif /* !VX1000_STIM_HISTOGRAM */
#define VX1000_STIM_DURARRAY_PTR       (VX1000_PTR2VU32_TO_ADDRESS(gVX1000_STIM_Duration))
#else /* !VX1000_STIM_BENCHMARK */
#define VX1000_STIM_DURARRAY_PTR       0UL
#endif /* !VX1000_STIM_BENCHMARK */

#define VX1000_STIM_TIMEOUTS           gVX1000.Stim.TimeoutCtr
#define VX1000_STIM_TIMEOUTS_IN_SEQ    gVX1000.Stim.TimeoutCtr2

#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_StimActive)( VX1000_UINT8 stim_event );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_StimRequest)( VX1000_UINT8 stim_event );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_StimSkip)( VX1000_UINT8 stimeventSK );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */

#if defined(VX1000_STIM_BY_OLDA)
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_OldaStimRequestEvent)( VX1000_UINT8 Eventnumber );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_STIM_BY_OLDA */

#else /* !VX1000_STIM */

#define VX1000_STIM_PTR                0UL /* "invalid" */
#define VX1000_STIM_DURARRAY_PTR       0UL /* "invalid" */

#endif /* !VX1000_STIM */

/* Hook based bypassing macros */
#if defined(VX1000_HOOK_BASED_BYPASSING) && defined(VX1000_STIM)

#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_BypassHbbGetVal_8) ( VX1000_UINT32 HookID, VX1000_UINT8 DefaultValue );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT16, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_BypassHbbGetVal_16) ( VX1000_UINT32 HookID, VX1000_UINT16 DefaultValue );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT32, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_BypassHbbGetVal_32) ( VX1000_UINT32 HookID, VX1000_UINT32 DefaultValue );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#if defined(VX1000_UINT64_T)
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT64_T, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_BypassHbbGetVal_64) ( VX1000_UINT32 HookID, VX1000_UINT64_T DefaultValue );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_UINT64_T */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_FLOAT, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_BypassHbbGetVal_Float) ( VX1000_UINT32 HookID, VX1000_FLOAT DefaultValue );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_DOUBLE, VX1000_CODE_FAST) VX1000_SUFFUN(vx1000_BypassHbbGetVal_Double) ( VX1000_UINT32 HookID, VX1000_DOUBLE DefaultValue );
#define VX1000_STOP_SEC_CODE_FAST
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */

#else /* !VX1000_HOOK_BASED_BYPASSING || !VX1000_STIM */


#endif /* !VX1000_HOOK_BASED_BYPASSING || !VX1000_STIM */


/*------------------------------------------------------------------------------ */
/* Calibration                                                                   */

#if defined(VX1000_CAL)

#include "cc_autosar.h"
#define CC_PTR                         (VX1000_PTR2V_TO_ADDRESS(&gCC))

#else /* !VX1000_CAL */

#define CC_PTR                         0UL

#endif /* !VX1000_CAL */


/*------------------------------------------------------------------------------ */
/* Overlay                                                                       */

#if defined(VX1000_OVERLAY)

#define VX1000_OVL_MAGIC                 0xFEC70A17UL
#define VX1000_EMEM_HDR_MAGIC            0xFEC81B28UL

#define VX1000_OVLFEAT_KEEP_AWAKE        0x00000001UL /* (1 << 0) : VX may suppress ECU falling asleep and/or shut down */
#define VX1000_OVLFEAT_SYNC_PAGESWITCH   0x00000002UL /* (1 << 1) : The moment of page switching is synchronised to API calls inside the ECU instead of clicks in a XCP tool */
#define VX1000_OVLFEAT_PERSISTENT_EMEM   0x00000004UL /* (1 << 2) : This bit indicates a secret feature only used by a single customer */
#define VX1000_OVLFEAT_RST_ON_CALWAKEUP  0x00000008UL /* (1 << 3) : This bit indicates a secret feature only used by a single customer */
#define VX1000_OVLFEAT_USE_VX_EPK_TRANS  0x00000010UL /* (1 << 4) : This bit indicates a secret feature only used by a single customer */
#define VX1000_OVLFEAT_VALIDATE_PAGESW   0x00000020UL /* (1 << 5) : This bit indicates a secret feature only used by a single customer */
#define VX1000_OVLFEAT_CORE_SYNC_PAGESW  0x00000040UL /* (1 << 6) : After a page switch request, cores will switch their respective pages individually */
#define VX1000_OVLFEAT_NONE              0x00000000UL /* (0 << 7) : The ECU application does not provide overlay functionality */
#define VX1000_OVLFEAT_USER              0x00000080UL /* (1 << 7) : The ECU application provides overlay feature via user callbacks */
#define VX1000_OVLFEAT_DRIVER            0x00000100UL /* (2 << 7) : The ECU application provides overlay feature AppDriver built-in code */
#define VX1000_OVLFEAT_VX                0x00000180UL /* (3 << 7) : The ECU application provides auxiliary mailbox functionality that supports the VX1000-FW-controlled overlay handling */
#define VX1000_OVLFEAT_ECU_REGS_VIA_MX   0x00000200UL /* (1 << 9) : overlay registers are configured over mailbox */
#define VX1000_OVLFEAT_RST_ON_SNCPAGESW  0x00000400UL /* (1 <<10) : ECU will perform an ECU Reset on Sync_Cal_Page_Switch */
#define VX1000_OVLFEAT_INVALIDATE_CACHE  0x00000800UL /* (1 <<11) : MailboxControl calls application callback function for cache invalidation when requested by VX1000 */

#if defined(VX1000_TARGET_POWERPC)
typedef struct VX1000_ovl_descriptor_T
{    /* 4x4 = 16B = 0x10 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MAS0;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MAS1;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MAS2;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MAS3;
} VX1000_OVL_DESCRIPTOR_T;
typedef struct VX1000_ovl_config_regs_T
{   /* 16*1*64 + 4*2 + 2 + 2 = 1036 = 0x40C Bytes */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 magicIdRG;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 versionRG;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 reservedRG1;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 reservedRG2;
  VX1000_INNERSTRUCT_VOLATILE VX1000_OVL_DESCRIPTOR_T DESCR[64];   /* for all cores, the descriptors need the same value; there are maximum 64 descriptors in the hardware */
} VX1000_OVL_CONFIG_REGS_T;
#endif /* VX1000_TARGET_POWERPC */

#if defined(VX1000_TARGET_SH2)
typedef struct VX1000_ovl_descriptor_T
{    /* Comment about the size */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 EXAMPLE_SH2_A;
} VX1000_OVL_DESCRIPTOR_T;
typedef struct VX1000_ovl_config_regs_T
{    /* Comment about the size */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 EXAMPLE_SH2_B;
} VX1000_OVL_CONFIG_REGS_T;
#endif /* VX1000_TARGET_SH2 */

#if defined(VX1000_TARGET_TMS570)
typedef struct VX1000_ovl_descriptor_T
{    /* Comment about the size */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 EXAMPLE_TMS570_A;
} VX1000_OVL_DESCRIPTOR_T;
typedef struct VX1000_ovl_config_regs_T
{    /* Comment about the size */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 EXAMPLE_TMS570_B;
} VX1000_OVL_CONFIG_REGS_T;
#endif /* VX1000_TARGET_TMS570 */

#if defined(VX1000_TARGET_TRICORE)
typedef struct VX1000_ovl_descriptor_T
{    /* 4x3 = 12B = 0xC */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 RABR;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 OTAR;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 OMASK;
} VX1000_OVL_DESCRIPTOR_T;
typedef struct VX1000_ovl_config_regs_T
{   /* 12*1*32 + 4*2 + 2 + 2 = 396 = 0x18C Bytes */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 magicIdRG;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 versionRG;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 reservedRG;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 OSEL;
  VX1000_INNERSTRUCT_VOLATILE VX1000_OVL_DESCRIPTOR_T DESCR[32];   /* for all cores, the descriptors need the same value; there are maximum 32 descriptors in the hardware */
} VX1000_OVL_CONFIG_REGS_T;
#endif /* VX1000_TARGET_TRICORE */

#if defined(VX1000_TARGET_X850)
typedef struct VX1000_ovl_descriptor_T
{    /* Comment about the size */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 EXAMPLE_x850_A;
} VX1000_OVL_DESCRIPTOR_T;
typedef struct VX1000_ovl_config_regs_T
{    /* Comment about the size */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 EXAMPLE_x850_B;
} VX1000_OVL_CONFIG_REGS_T;
#endif /* VX1000_TARGET_X850 */

#if defined(VX1000_TARGET_XC2000)
typedef struct VX1000_ovl_descriptor_T
{    /* 1x10bits = 2B = 0x02 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 DPPx;
} VX1000_OVL_DESCRIPTOR_T;
typedef struct VX1000_ovl_config_regs_T
{   /* 2*1*4 + 4 + 2*3 = 18 = 0x12 Bytes */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 magicIdRG;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 versionRG;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 reservedRG;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 maskRG;
  VX1000_INNERSTRUCT_VOLATILE VX1000_OVL_DESCRIPTOR_T DESCR[4];   /* just a single core, there are exactly 4 descriptors in the hardware because we do not support overlaying the code segment */
} VX1000_OVL_CONFIG_REGS_T;
#endif /* VX1000_TARGET_XC2000 */

typedef struct VX1000_syncal_page_switch_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 magicIdP;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 versionP;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  pageSwitchRequested;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  targetPage;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 overlayValue;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 overlayMask;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 busMasterRequested;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  coreDone[32];
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 overlayValueB;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 overlayMaskB;
} VX1000_SYNCAL_PAGE_SWITCH_T;

/* Structure for EMEM invalidation when cal-wakeup and EMEM-supply is used */
typedef struct VX1000_emem_hdr_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 magicIdE;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 versionE;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 reserved;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ememInitEnd;                    /* VX-RW, ECU-RO */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ememInitEndInvert;              /* VX-RW, ECU-RO */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ememInitStart;                  /* VX-RW, ECU-RW */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ememInitStartInvert;            /* VX-RW, ECU-RW */
#define VX1000_EMEM_HDR_VERSION        1U
} VX1000_EMEM_HDR_T;

typedef struct VX1000_ovl_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 magicIdOV;                      /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 versionOV;                      /* 0x04 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 presenceCounter;                /* 0x06 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlConfigValue;                 /* 0x08 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlConfigMask;                  /* 0x0C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 calFeaturesEnable;              /* 0x10 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 persistentECUEmemHeaderPtr;     /* 0x14 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlBusMasterMask;               /* 0x18 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 ecuLastPresenceCounter;         /* 0x1C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 ovlEPKLength;                   /* 0x1E */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlReferencePageDataEPKAddress; /* 0x20 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlWorkingPageDataEPKAddress;   /* 0x24 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 syncCalSwitchDataPtr;           /* 0x28 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlConfigRegsPtr;               /* 0x2C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlConfigValueB;                /* 0x30 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlConfigMaskB;                 /* 0x34 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlWriteCounter;                /* 0x38 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  overlayStatus;                  /* 0x3C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  selectedPage;                   /* 0x3D */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 ovlPad16;
  VX1000_SYNCAL_PAGE_SWITCH_T syncCalData;                                  /* no fix offset */
#if ((defined(VX1000_OVERLAY)) && (defined(VX1000_OVERLAY_VX_CONFIGURABLE))) && ((defined(VX1000_OVLENBL_REGWRITE_VIA_MX)) && (defined(VX1000_MAILBOX_OVERLAY_CONTROL)))
  VX1000_OVL_CONFIG_REGS_T ovlConfigRegs;
#endif /* VX1000_OVERLAY && VX1000_OVERLAY_VX_CONFIGURABLE && VX1000_OVLENBL_REGWRITE_VIA_MX && VX1000_MAILBOX_OVERLAY_CONTROL */
#define VX1000_OVL_VERSION             7U
} VX1000_OVL_T;

#define VX1000_OVL_DATA                VX1000_OVL_T Ovl
#define VX1000_OVL_PTR                 (VX1000_PTR2VOVL_TO_ADDRESS(&gVX1000.Ovl))

#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_CalWakeupRequested)(void);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_OverlayGetStatus)(VX1000_UINT8 *workingPageStatus, VX1000_UINT8 *selectedPage);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#if defined(VX1000_OVLENBL_KEEP_AWAKE)
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_IsCalWakeupActive)( void );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_OVLENBL_KEEP_AWAKE */

#if defined(VX1000_OVERLAY) && ((defined(VX1000_MAILBOX_OVERLAY_CONTROL) && defined(VX1000_OVLENBL_SYNC_PAGESWITCH)) || (!defined(VX1000_SUPPRESS_ASAM_VENDOR_API)))
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_OverlaySetConfigDone)( VX1000_UINT8 cfgResult, VX1000_UINT8 page, VX1000_UINT8 onStartup );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_OVERLAY && ((VX1000_MAILBOX_OVERLAY_CONTROL && VX1000_OVLENBL_SYNC_PAGESWITCH) || !VX1000_SUPPRESS_ASAM_VENDOR_API) */

#if defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
#if !defined(VX1000_OVL_SET_CONFIG)
#define VX1000_OVL_SET_CONFIG_INTERNAL
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_OverlaySetConfig)(VX1000_UINT32 value, VX1000_UINT32 mask, VX1000_UINT32 valueB, VX1000_UINT32 maskB, VX1000_UINT8 page, VX1000_UINT32 master, VX1000_UINT32 calMaster);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_OVL_SET_CONFIG */

#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_OverlayChkPageSwitchDone)( void );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */

#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_OverlayChkPageSwitchCore)( VX1000_UINT32 master );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */

#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_overlayIsPageSwitchReq)( VX1000_UINT32 master );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */

#endif /* VX1000_OVLENBL_SYNC_PAGESWITCH */

#if defined(VX1000_OVLENBL_PERSISTENT_EMEM)
#define VX1000_EMEM_HDR_DATA           volatile VX1000_VAR(VX1000_EMEM_HDR_T, VX1000_EMEM_VAR_NOCACHE_NOINIT) gVXEmemHdr
#define VX1000_EMEM_HDR_PTR            (VX1000_PTR2VEHM_TO_ADDRESS(&gVXEmemHdr))
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_InvalidateEmem)( void );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */

#else /* !VX1000_OVLENBL_PERSISTENT_EMEM */

#define VX1000_EMEM_HDR_PTR            0UL

#endif /* !VX1000_OVLENBL_PERSISTENT_EMEM */

#else /* !VX1000_OVERLAY */

#define VX1000_OVL_PTR                 0UL
#define VX1000_EMEM_HDR_PTR            0UL
#endif /* !VX1000_OVERLAY */

/*------------------------------------------------------------------------------ */
/* VX1000_RES_MGMT                                                               */
/* Note: this is a pure project specific feature.                                */
/* The specification comes from the customer, so do not improve.                 */

#if defined(VX1000_RES_MGMT)

#define VX1000_RES_MGMT_MAGIC          0xFEC70A18UL

typedef struct VX1000_res_mgmt_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 magicIdRM;               /* 0x00 */ /* Version 2 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 versionRM;               /* 0x04 */
  /* Resource 0: the first consecutive range of overlay descriptors (register group) free for usage by VX1000 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  ovlConfigItemStart;      /* 0x06 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  ovlConfigItemLength;     /* 0x07 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 resMgmtEnable;           /* 0x08 */
  /* Resource 1: the first consecutive chunk of RAM (usable by hardware as overlay buffer) free for usage by VX1000 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlRamStart;             /* 0x0C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlRamSize;              /* 0x10 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlRamStart1;            /* 0x14 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlRamSize1;             /* 0x18 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlRamStart2;            /* 0x1C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlRamSize2;             /* 0x20 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlRamStart3;            /* 0x24 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 ovlRamSize3;             /* 0x28 */
} VX1000_RES_MGMT_T;

#define VX1000_RES_MGMT_VERSION        2U

#define VX1000_RES_MGMT_RES_CONFIG_ITEM 0x00000001UL /* (1UL << 0) */
#define VX1000_RES_MGMT_RES_OVL_RAM    0x00000002UL  /* (1UL << 1) */

#define VX1000_RES_MGMT_DATA           VX1000_RES_MGMT_T ResMgmt
#define VX1000_RES_MGMT_PTR            (VX1000_PTR2VRM_TO_ADDRESS(&gVX1000.ResMgmt))

#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_EnableAccess)( void );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_DisableAccess)( void );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_IsAccessDisabled)( void );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */

/* Resource Overlay Configuration Item */
#if !defined(VX1000_RES_MGMT_CFG_ITEM_START)
#define VX1000_RES_MGMT_CFG_ITEM_START 0U
#endif /* !VX1000_RES_MGMT_CFG_ITEM_START */

#if !defined(VX1000_RES_MGMT_CFG_ITEM_LEN)
#define VX1000_RES_MGMT_CFG_ITEM_LEN   32U
#endif /* !VX1000_RES_MGMT_CFG_ITEM_LEN */

#if !defined(VX1000_RES_MGMT_ENABLE_CFG_ITEM)
#define VX1000_RESMGMT_ENBLVAL_CFG_ITEM 0UL
#else /* VX1000_RES_MGMT_ENABLE_CFG_ITEM */
#define VX1000_RESMGMT_ENBLVAL_CFG_ITEM (VX1000_RES_MGMT_RES_CONFIG_ITEM)
#endif /* VX1000_RES_MGMT_ENABLE_CFG_ITEM */

/* Resource Ram */
#if !defined(VX1000_RES_MGMT_RAM_START)
#if defined(VX1000_RES_MGMT_RAM_START_0)
#define VX1000_RES_MGMT_RAM_START      (VX1000_RES_MGMT_RAM_START_0)
#else  /* !VX1000_RES_MGMT_RAM_START_0 */
#define VX1000_RES_MGMT_RAM_START      0UL
#endif /* !VX1000_RES_MGMT_RAM_START_0 */
#endif /* !VX1000_RES_MGMT_RAM_START */

#if !defined(VX1000_RES_MGMT_RAM_SIZE)
#if defined(VX1000_RES_MGMT_RAM_SIZE_0)
#define VX1000_RES_MGMT_RAM_SIZE       (VX1000_RES_MGMT_RAM_SIZE_0)
#else  /* !VX1000_RES_MGMT_RAM_SIZE_0 */
#define VX1000_RES_MGMT_RAM_SIZE       0U
#endif /* !VX1000_RES_MGMT_RAM_SIZE_0 */
#endif /* !VX1000_RES_MGMT_RAM_SIZE */

#if !defined(VX1000_RES_MGMT_RAM_START_1)
#define VX1000_RES_MGMT_RAM_START_1    0UL
#endif /* !VX1000_RES_MGMT_RAM_START_1 */

#if !defined(VX1000_RES_MGMT_RAM_SIZE_1)
#define VX1000_RES_MGMT_RAM_SIZE_1     0U
#endif /* !VX1000_RES_MGMT_RAM_SIZE_1 */

#if !defined(VX1000_RES_MGMT_RAM_START_2)
#define VX1000_RES_MGMT_RAM_START_2    0UL
#endif /* !VX1000_RES_MGMT_RAM_START_2 */

#if !defined(VX1000_RES_MGMT_RAM_SIZE_2)
#define VX1000_RES_MGMT_RAM_SIZE_2     0U
#endif /* !VX1000_RES_MGMT_RAM_SIZE_2 */

#if !defined(VX1000_RES_MGMT_RAM_START_3)
#define VX1000_RES_MGMT_RAM_START_3    0UL
#endif /* !VX1000_RES_MGMT_RAM_START_3 */

#if !defined(VX1000_RES_MGMT_RAM_SIZE_3)
#define VX1000_RES_MGMT_RAM_SIZE_3     0U
#endif /* !VX1000_RES_MGMT_RAM_SIZE_3 */

#if !defined(VX1000_RES_MGMT_ENABLE_OVL_RAM)
#define VX1000_RESMGMT_ENBLVAL_OVL_RAM 0UL
#else /* VX1000_RES_MGMT_ENABLE_OVL_RAM */
#define VX1000_RESMGMT_ENBLVAL_OVL_RAM (VX1000_RES_MGMT_RES_OVL_RAM)
#endif /* VX1000_RES_MGMT_OVL_ENABLE */


#else /* !VX1000_RES_MGMT */

#define VX1000_RES_MGMT_PTR            0UL

#endif /* !VX1000_RES_MGMT */

#if defined(VX1000_MEAS_CFG_ENABLE)
#if !defined(VX1000_MEAS_CFG_RAMSIZE)
#define VX1000_MEAS_CFG_RAMSIZE        4U                          /* allocate space for a termination at least */
#endif /* !VX1000_MEAS_CFG_RAMSIZE */
typedef struct VX1000_measurement_cfg_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MagicIdMC;             /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  StructVersionMC;       /* 0x04 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  Padding8MC;            /* 0x05 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 Padding16MC;           /* 0x06 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 AddrOfFlashSignals;    /* 0x08 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 SizeOfFlashSignals;    /* 0x0C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 AddrOfFlashEvents;     /* 0x10 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 SizeOfFlashEvents;     /* 0x14 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 AddrOfRam;             /* 0x18 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 SizeOfRam;             /* 0x1C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 UsedSizeOfRam;         /* 0x20 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 UpdateCounter;         /* 0x24 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 CheckSum;              /* 0x28 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 CfgRam[(VX1000_MEAS_CFG_RAMSIZE) >> 2]; /* no fix offset; accessed indirectly */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 RamIndex;              /* no fix offset; used internally only */
} VX1000_MEASUREMENT_CFG_T;
#define VX1000_STRUCT_VERS_MEASURECFG  0U
#define VX1000_STRUCT_MAGIC_MEASURECFG 0xFEC70A0AUL
#define VX1000_MEAS_CFG_DATA           VX1000_MEASUREMENT_CFG_T MeasurementConfig
#define VX1000_MEAS_CFG_ADDR           VX1000_PTR2VU32_TO_ADDRESS(&gVX1000.MeasurementConfig.MagicIdMC)
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(VX1000_MeasTypedefAdd)( const VX1000_CHAR VX1000_DECL_PTR* TAName, VX1000_UINT8 TAType, VX1000_UINT32 TAOffset, VX1000_UINT32 TAArrayCnt );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(VX1000_MeasTypedefAddSt)( const VX1000_CHAR VX1000_DECL_PTR* TASName, const VX1000_CHAR VX1000_DECL_PTR* TASTypeName, VX1000_UINT32 TASOffset, VX1000_UINT32 TASArrayCnt );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(VX1000_MeasTypedefBegin)( const VX1000_CHAR VX1000_DECL_PTR* TBName, VX1000_UINT8 TBPad, VX1000_UINT32 TBStructSize );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(VX1000_MeasTypedefEnd)( void );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(VX1000_MeasTypedefInst)( const VX1000_CHAR VX1000_DECL_PTR* TIName, const VX1000_CHAR VX1000_DECL_PTR* TITypeName, VX1000_UINT16 TIEvt, VX1000_UINT32 TIAdr, VX1000_UINT8 TIExt, VX1000_UINT32 TIArrayCnt );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(VX1000_MeasTypedefInstId)( VX1000_UINT32 TIID, const VX1000_CHAR VX1000_DECL_PTR* TIITypeName, VX1000_UINT16 TIIEvt, VX1000_UINT32 TIIAdr, VX1000_UINT8 TIIExt, VX1000_UINT32 TIIArrayCnt );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MeasAddEvent)( VX1000_UINT32 AEv, VX1000_UINT32 APrio, VX1000_UINT32 ADir, VX1000_UINT32 ACycUs, const VX1000_CHAR VX1000_DECL_PTR *ADesc );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MeasAddSignalById)( VX1000_UINT32 AID, VX1000_UINT32 AIEvt, VX1000_UINT32 AIAdr, VX1000_UINT32 AIExt, VX1000_UINT32 AIType, VX1000_UINT32 AIArrayCnt );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MeasAddSignalByName)( const VX1000_CHAR VX1000_DECL_PTR *AName, VX1000_UINT32 ANEvt, VX1000_UINT32 ANAdr, VX1000_UINT32 ANExt, VX1000_UINT32 ANType, VX1000_UINT32 ANArrayCnt );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MeasConfigDone)( void );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MeasConfigInit)( void );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MeasSetEventList)( const VX1000_UINT32 VX1000_DECL_PTR *EList, VX1000_UINT32 EListBytes );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_MeasSetSignalList)( const VX1000_UINT32 VX1000_DECL_PTR *SList, VX1000_UINT32 SListBytes );
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_MEAS_INIT_EVENT(EVT, PRI, DIR, CYC, TXT, LEN)                   ((((VX1000_UINT32)(EVT)) << 16) | (((VX1000_UINT32)(PRI)) << 8) | (VX1000_UINT32)(DIR)), (VX1000_UINT32)(const void VX1000_DECL_PTR*)(const VX1000_CHAR VX1000_DECL_PTR*)((TXT)), ((VX1000_UINT32)(LEN)), ((VX1000_UINT32)(CYC)), /* array continues */                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_INIT_SIGNAL_NAME(NAM, LEN, EVT, ADR, EXT, TYP, NUM)        ((((VX1000_UINT32)(EVT)) << 16) | (((VX1000_UINT32)(EXT)) << 8) | (VX1000_UINT32)(TYP)), (VX1000_UINT32)(const void VX1000_DECL_PTR*)(const VX1000_CHAR VX1000_DECL_PTR*)((NAM)), ((VX1000_UINT32)(LEN)), ((VX1000_UINT32)(ADR)), ((VX1000_UINT32)(NUM)), /* array continues */                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_INIT_SIGNAL_ENUMID(ID, EVT, ADR, EXT, TYP, NUM)            ((((VX1000_UINT32)(EVT)) << 16) | (((VX1000_UINT32)(EXT)) << 8) | (VX1000_UINT32)(TYP)), ((VX1000_UINT32)(ID)), /*LEN:*/0UL, ((VX1000_UINT32)(ADR)), ((VX1000_UINT32)(NUM)), /* array continues */                                                                                                                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_INIT_TYPEDEF_INST(NAM, LEN, TNM, TNL, EVT, ADR, EXT, NUM)  (0x000000FBUL | (((VX1000_UINT32)(EVT)) << 16) | (((VX1000_UINT32)(EXT)) << 8)), (VX1000_UINT32)(const void VX1000_DECL_PTR*)(const VX1000_CHAR VX1000_DECL_PTR*)((NAM)), (((VX1000_UINT32)(LEN)) | ((VX1000_UINT32)(TNL) << 16)), ((VX1000_UINT32)(NUM)), (VX1000_UINT32)(const void VX1000_DECL_PTR*)(const VX1000_CHAR VX1000_DECL_PTR*)((TNM)), ((VX1000_UINT32)(ADR)),/*cont*//* PRQA S 3453 */ /* violating MISRA rule 19.7 as below */
#define VX1000_MEAS_INIT_TYPEDEF_INSTID(ID, TNM, TNL, EVT, ADR, EXT, NUM)      (0x000000FBUL | (((VX1000_UINT32)(EVT)) << 16) | (((VX1000_UINT32)(EXT)) << 8)), (VX1000_UINT32)(ID), ((VX1000_UINT32)(TNL) << 16), ((VX1000_UINT32)(NUM)), (VX1000_UINT32)(const void VX1000_DECL_PTR*)(const VX1000_CHAR VX1000_DECL_PTR*)((TNM)), ((VX1000_UINT32)(ADR)), /* array continues */                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_INIT_TYPEDEF_ADD_ST(NAM, LEN, TNM, TNL, OFS, NUM)          (0x000000FCUL), (VX1000_UINT32)(const void VX1000_DECL_PTR*)(const VX1000_CHAR VX1000_DECL_PTR*)((NAM)), (((VX1000_UINT32)(LEN)) | ((VX1000_UINT32)(TNL) << 16)), ((VX1000_UINT32)(NUM)), (VX1000_UINT32)(const void VX1000_DECL_PTR*)(const VX1000_CHAR VX1000_DECL_PTR*)((TNM)), ((VX1000_UINT32)(OFS)), /* array continues */  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_INIT_TYPEDEF_ADD(NAM, LEN, TYP, OFS, NUM)                  (0x000000FDUL | ((VX1000_UINT32)(TYP) << 8)), (VX1000_UINT32)(const void VX1000_DECL_PTR*)(const VX1000_CHAR VX1000_DECL_PTR*)((NAM)), ((VX1000_UINT32)(LEN)), ((VX1000_UINT32)(NUM)), ((VX1000_UINT32)(OFS)), /* array continues */                                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_INIT_TYPEDEF_BEGIN(NAM, LEN, PAD, SIZ)                     (0x000000FEUL | ((VX1000_UINT32)(PAD) << 8)), (VX1000_UINT32)(const void VX1000_DECL_PTR*)(const VX1000_CHAR VX1000_DECL_PTR*)((NAM)), ((VX1000_UINT32)(LEN)), ((VX1000_UINT32)(SIZ)), /* array continues */                                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_INIT_TYPEDEF_END()                                         (0x000000FFUL),  /* array continues */
#define VX1000_MEAS_INIT_DONE()                                                (0x00000000UL) /* end of array */
#else  /* !VX1000_MEAS_CFG_ENABLE */
#define VX1000_MEAS_CFG_ADDR           0UL
#define VX1000_MEAS_INIT_EVENT(EVT, PRI, DIR, CYC, TXT, LEN)                   /* empty */
#define VX1000_MEAS_INIT_SIGNAL_NAME(NAM, LEN, EVT, ADR, EXT, TYP, NUM)        /* empty */
#define VX1000_MEAS_INIT_SIGNAL_ENUMID(ID, EVT, ADR, EXT, TYP, NUM)            /* empty */
#define VX1000_MEAS_INIT_TYPEDEF_INST(NAM, LEN, TNM, TNL, EVT, ADR, EXT, NUM)  /* empty */
#define VX1000_MEAS_INIT_TYPEDEF_INSTID(ID, TNM, TNL, EVT, ADR, EXT, NUM)      /* empty */
#define VX1000_MEAS_INIT_TYPEDEF_ADD_ST(NAM, LEN, TNM, TNL, OFS, NUM)          /* empty */
#define VX1000_MEAS_INIT_TYPEDEF_ADD(NAM, LEN, TYP, OFS, NUM)                  /* empty */
#define VX1000_MEAS_INIT_TYPEDEF_BEGIN(NAM, LEN, PAD, SIZ)                     /* empty */
#define VX1000_MEAS_INIT_TYPEDEF_END()                                         /* empty */
#define VX1000_MEAS_INIT_DONE()                                                0x00000000UL /* single element in unused array */
#endif /* !VX1000_MEAS_CFG_ENABLE */
#define VX1000_MEAS_EVENT_DAQ          1UL
#define VX1000_MEAS_EVENT_STIM         2UL
#define VX1000_MEAS_EVENT_DAQSTIM      3UL
#define VX1000_MEAS_DATA_UBYTE         11UL
#define VX1000_MEAS_DATA_SBYTE         12UL
#define VX1000_MEAS_DATA_UWORD         13UL
#define VX1000_MEAS_DATA_SWORD         14UL
#define VX1000_MEAS_DATA_ULONG         15UL
#define VX1000_MEAS_DATA_SLONG         16UL
#define VX1000_MEAS_DATA_A_UINT64      17UL
#define VX1000_MEAS_DATA_A_INT64       18UL
#define VX1000_MEAS_DATA_FLOAT32_IEEE  19UL
#define VX1000_MEAS_DATA_FLOAT64_IEEE  20UL
#define VX1000_MEAS_DATA_BLOB          21UL
#define VX1000_MEAS_AUTO_OFFSET        0xFFFFFFFFUL

typedef struct VX1000_memsync_trig_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MagicIdMT;             /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  StructVersionMT;       /* 0x04 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  Reserved0;             /* 0x05 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16 Reserved1;             /* 0x06 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MemSync_0;             /* 0x08 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MemSync_1;             /* 0x0C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MemSync_2;             /* 0x10 */
} VX1000_MEMSYNC_TRIG_T;
#define VX1000_STRUCT_MAGIC_MEMSYNCTRIG 0xFEC72016UL

typedef struct VX1000_memsync_cpy_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 MagicIdMC;             /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  StructVersionMC;       /* 0x04 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  SyncWinStatus;         /* 0x05 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  SyncMasterId;          /* 0x06 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8  SyncTriggerId;         /* 0x07 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 SyncWinStart;          /* 0x08 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 SyncWinSize;           /* 0x0C */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32 SyncChunkSize;         /* 0x10 */
} VX1000_MEMSYNC_CPY_T;
#define VX1000_STRUCT_MAGIC_MEMSYNCCPY 0xFEC70815UL

#if ((VX1000_MEMSYNC_TRIGGER_COUNT) == 0U)
#define VX1000_MEMSYNC_TRIGGER_PTR     0UL
#elif ((VX1000_MEMSYNC_TRIGGER_COUNT) == 1U)
#if !defined(VX1000_MEMSYNC_TRIGGER_PTR)
#define VX1000_MEMSYNCTRIG_DATA        VX1000_MEMSYNC_TRIG_T MemSyncTrigger
#define VX1000_MEMSYNC_TRIGGER_PTR     (VX1000_PTR2MT_TO_ADDRESS(&gVX1000.MemSyncTrigger))
#endif /* !VX1000_MEMSYNC_TRIGGER_PTR */
#else  /* VX1000_MEMSYNC_TRIGGER_COUNT > 1 */
#define VX1000_MEMSYNCTRIG_DATA        VX1000_UINT32 MemSyncTrigger[VX1000_MEMSYNC_TRIGGER_COUNT]
#define VX1000_MEMSYNC_TRIGGER_PTR     (VX1000_PTR2VU32_TO_ADDRESS(gVX1000.MemSyncTrigger))
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT > 1 */
#if ((VX1000_MEMSYNC_COPY_COUNT) == 0U)
#define VX1000_MEMSYNC_COPY_PTR        0UL
#else  /* VX1000_MEMSYNC_COPY_COUNT */
#define VX1000_MEMSYNCCPY_DATA         VX1000_MEMSYNC_CPY_T MemSyncCopy[VX1000_MEMSYNC_COPY_COUNT]
#define VX1000_MEMSYNC_COPY_PTR        (VX1000_PTR2MC_TO_ADDRESS(gVX1000.MemSyncCopy))
#endif /* VX1000_MEMSYNC_COPY_COUNT */

#if !defined(VX1000_ADDONS_INIT)
#define VX1000_ADDONS_INIT()           /* empty */                                                                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to overload a simple default implementation by a premium version implemented in an optional source file */
#endif /* !VX1000_ADDONS_INIT */
#if !defined(VX1000_ADDONS_DASDAQ_OLDACMD)
#define VX1000_ADDONS_DASDAQ_OLDACMD(A, B, C, D, E) VX1000_ERRLOGGER(VX1000_ERRLOG_OLDA_UNIMPLCMD)                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to overload a simple default implementation by a premium version implemented in an optional source file */
#endif /* VX1000_ADDONS_DASDAQ_OLDACMD */
#if !defined(VX1000_ADDONS_DASSTIM_OLDACMD)
#define VX1000_ADDONS_DASSTIM_OLDACMD(A, B, C, D, E) VX1000_ERRLOGGER(VX1000_ERRLOG_OLDA_UNIMPLCMD)                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to overload a simple default implementation by a premium version implemented in an optional source file */
#endif /* VX1000_ADDONS_DASSTIM_OLDACMD */


#if defined(VX1000_DISABLE_INSTRUMENTATION)

#define VX1000_DATA                    /* empty */

#else /* !VX1000_DISABLE_INSTRUMENTATION */



/*------------------------------------------------------------------------------ */
/* VX1000 data structure                                                         */
/* Version history (as "new in version"):                                        */
/*  4: OldaPtr                                                                   */
/*  5: Olda integrated at fixed position 0x40                                    */
/*  6: CalPtr                                                                    */
/*  7: ToolCtrlState (written by tool)                                           */
/*  8: ResMgmtPtr, OvlPtr                                                        */
/*  9: FileVersion, FeatureFlags0, TimerXXX, xxxDur-pointers, ErrLog             */
/* 10: MemSyncXXXPtr, MemSyncXXXCnt, ReleaseNamexxx, BuildNumber                 */
/* 11: "DAS"                                                                     */
/* 12: "A2L" (ECU measurement configuration)                                     */
/* 13: DaqInfo                                                                   */
/* 14: PcieInfo                                                                  */
/* 15: CalibrationStatus                                                         */

#define VX1000_STRUCT_VERSION          15UL
#define VX1000_STRUCT_MAGIC            0xFEC70A08UL

#define VX1000_ECUFEAT_FKLINSTRUMENTED 0x00000001UL /* (1 << 0)  The application provides support to download and start an external flash kernel */
#define VX1000_ECUFEAT_MX_FLASHSTART   0x00000002UL /* (1 << 1)  Reserved for mailbox flashing */
#define VX1000_ECUFEAT_MX_FLASHMODIFY  0x00000004UL /* (1 << 2)  Reserved for mailbox flashing */
#define VX1000_ECUFEAT_MX_SOFTRESET    0x00000008UL /* (1 << 3)  Reserved for mailbox flashing */
#define VX1000_ECUFEAT_MX_CALPAGE_RW   0x00000010UL /* (1 << 4)  The application wants to handle calpage up/downloads manually via mailbox callbacks */
#define VX1000_ECUFEAT_MX_CALPAGE_GSC  0x00000020UL /* (1 << 5)  The application provides mailbox handling for get/set/copy calpage commands */
#define VX1000_ECUFEAT_STIMWT_DURATION 0x00000040UL /* (1 << 6)  The application provides a snapshot of all STIM events' busy waiting times */
#define VX1000_ECUFEAT_STIMRT_DURATION 0x00000080UL /* (1 << 7)  The application provides a snapshot of all STIM events' round trip times and a global timeout counter */
#define VX1000_ECUFEAT_STIMRT_HISTOGR  0x00000100UL /* (1 << 8)  The application provides a histogram of one STIM event's round trip times since ECU boot */
/* reserved range for DAS:             0x00000200UL    (1 << 9) */
#define VX1000_ECUFEAT_MEMSY_FALLBACK  0x00000400UL /* (1 << 10) Regular OLDA copy actions can be requested by tool despite OLDA code being compiled for MemSync trace */
#define VX1000_ECUFEAT_NO_DAP_NO_TRIG  0x00000800UL /* (1 << 11) Despite running on TriCore, the DAP debug resources, especially the TRIG registers, are NOT used by VX */

#if !defined(VX1000_ADDONS_FEATUREFLAGS0)
#define VX1000_ADDONS_FEATUREFLAGS0    0UL
#endif /* !VX1000_ADDONS_FEATUREFLAGS0 */

#define VX1000_RELEASECODE_H           65U
#define VX1000_RELEASECODE_B           1339057152UL
#define VX1000_RELEASECODE_T           0UL


typedef struct VX1000_DAQ_FW_INFO_t
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16  daqMagicID;           /* v0 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16  daqVersion;           /* v0 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   daqStatusXcp;         /* v0: See VX1000If_GetDaqStatus for details                    */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   daqStatusRadarRawData;/* v0: See VX1000If_GetDaqStatus for details                    */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   startDaqCounter;      /* v0: See VX1000_DAQ_STARTED-Callback                          */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   daqPadding8;          /* v0: Currently unused byte                                    */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  rawDataDstAddress;    /* v0: See VX1000If_DataTransferGetInfo Information for details */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  headerDstAddress;     /* v1: Currently unused - would be written by the FW            */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  footerDstAddress;     /* v1: Currently unused - would be written by the FW            */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   rawDataMode;          /* v1(+v0): See VX1000If_DataTransferGetInfo for details        */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   headerMode;           /* v1: Currently unused - would be written by the FW            */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   footerMode;           /* v1: Currently unused - would be written by the FW            */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   daqPadding8B;         /* v1: Currently unused byte                                    */
} VX1000_DAQ_FW_INFO_T;

typedef struct VX1000_PCIE_FW_INFO_t
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16  pcieMagicID;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16  pcieVersion;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  bar0RegionStartAddrCPU;/* Start address of the BAR region perspective of the core */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  bar0RegionSizeInBytes; /* Size of the BAR region in bytes                         */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   linkDownCounter;      /* Used by VX1000If_NotificationLinkChange                  */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   triggerVX1000detection;/* Via 0x5A FW can trigger VX1000_TRIGGER_DISCOVERING_CB() */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   ecuSwBehavior;        /* Bit1: PCIe exclusive for VX, bit0: PCIe set up by ECU    */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   pciePadding8;         /* Currently unused byte                                    */
} VX1000_PCIE_FW_INFO_T;

typedef struct VX1000_TMP_AT_END_t /* This is not known by the FW. It just collects all global temp variables of this particular AppDriver version in arbitrary order */
{
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  MemsyCache[VX1000_MEMSYNC_TRIGGER_COUNT];
#endif /* VX1000_MEMSYNC_TRIGGER_COUNT */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  RadarEventCount;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  RadarEventStartTimeL; /* probably will need to be published in main structures because the FW will have to write OLDA copy commands with its address as source address */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  RadarEventStartTimeH;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  SpecEventCount;
#if defined(VX1000_STIM)
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  StimTimeout[VX1000_STIM_EVENT_COUNT];
#endif /* VX1000_STIM */
#if defined(VX1000_STIM) && defined(VX1000_STIM_BENCHMARK) /* not checked, because only 12 bytes are wasted: && defined(VX1000_MAINCORE_VX_STRUCT_ADDR) */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  StimBegArray[VX1000_STIM_EVENT_COUNT];
#if defined(VX1000_STIM_HISTOGRAM)
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  StimHist1ArrayPtr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  StimHist2ArrayPtr;
#endif /* VX1000_STIM_HISTOGRAM */
#endif /* VX1000_STIM && VX1000_STIM_BENCHMARK */ /* not checked: && VX1000_MAINCORE_VX_STRUCT_ADDR */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  MainStructSizeCheck;
#if defined(VX1000_OVLENBL_INVALIDATE_CACHE)
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  LastOvlWriteCounter;
#endif /* VX1000_OVLENBL_INVALIDATE_CACHE */
#if defined(VX1000_TARGET_TRICORE)
#if (!defined(VX1000_FORCE_NO_DAP_NO_TRIG)) || defined(VX1000_OVERLAY) || (defined(VX1000_HSCT_INTERFACES_MASK) && (VX1000_HSCT_INTERFACES_MASK != 0UL))
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  MaskedJtagId;
#endif /* !VX1000_FORCE_NO_DAP_NO_TRIG || VX1000_OVERLAY || VX1000_HSCT_INTERFACES_MASK */
#if defined(VX1000_HSCT_INTERFACES_MASK) && defined(VX1000_SUPPORT_MULTI_HSCT)
#if ((VX1000_HSCT_INTERFACES_MASK) & 0xFEUL) != 0UL
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  HsctSlaveId;
#endif /* VX1000_HSCT_INTERFACES_MASK & 0xFE */
#endif /* VX1000_HSCT_INTERFACES_MASK && VX1000_SUPPORT_MULTI_HSCT */
#endif /* VX1000_TARGET_TRICORE */
#if defined(VX1000_MAILBOX) && ((defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH)) || (defined(VX1000_MAILBOX_CAL_READ_WRITE) || (!defined(VX1000_MAILBOX_NO_SPLITREAD))))
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  FlgRdSplitPend;
#endif /* VX1000_MAILBOX && (VX1000_MAILBOX_OVERLAY_CONTROL || VX1000_MAILBOX_FLASH || VX1000_MAILBOX_CAL_READ_WRITE || !VX1000_MAILBOX_NO_SPLITREAD) */
#if defined(VX1000_MAILBOX) && (defined(VX1000_MAILBOX_CAL_READ_WRITE) || (!defined(VX1000_MAILBOX_NO_SPLITWRITE)))
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  FlgWrSplitPend;
#endif /* VX1000_MAILBOX && (VX1000_MAILBOX_CAL_READ_WRITE || !VX1000_MAILBOX_NO_SPLITWRITE) */
#if defined(VX1000_MAILBOX) && ((defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH)) || defined(VX1000_MAILBOX_CAL_READ_WRITE))
  VX1000_INNERSTRUCT_VOLATILE VX1000_INT32   MxCallPendulum;
#endif /* VX1000_MAILBOX && (VX1000_MAILBOX_OVERLAY_CONTROL || VX1000_MAILBOX_FLASH || VX1000_MAILBOX_CAL_READ_WRITE) */
#if defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_PRINTF)
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  MxServTextLen;
  VX1000_INNERSTRUCT_VOLATILE VX1000_CHAR    MxServTextBuf[(VX1000_UINT32)(VX1000_MAILBOX_SLOT_DWORDS) * 4UL]; /* a DWORD-aligned and DWORD-padded char buffer */
#if defined(VX1000_PRINTF_MINIMAL)
  VX1000_INNERSTRUCT_VOLATILE VX1000_LDOUBL  MxDummyFloat, MxPaddingFloat; /* dummies to correctly handly floats, may the compiler use 32, 64 or even 80 bits */
#endif /* VX1000_PRINTF_MINIMAL */
#endif /* VX1000_MAILBOX && VX1000_MAILBOX_PRINTF */
#if defined(VX1000_MAILBOX) && ((defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH)) || defined(VX1000_MAILBOX_CAL_READ_WRITE))
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  MxMTA, MxRxLen;
  VX1000_INNERSTRUCT_VOLATILE VX1000_CHAR    MxTxBuf[12];             /* a DWORD-aligned and DWORD-padded char buffer */
#if defined(VX1000_MAILBOX_CAL_READ_WRITE)
#endif /* VX1000_MAILBOX_CAL_READ_WRITE */
#endif /* VX1000_MAILBOX && (VX1000_MAILBOX_OVERLAY_CONTROL || VX1000_MAILBOX_FLASH || VX1000_MAILBOX_CAL_READ_WRITE) */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32  CheckEndian;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16  LastErrorCode;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   LastStartDaqCounter;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   DerivativeClass;      /* currently used only on TriCore and if VX1000_DERIVATIVE_CLASS was not provided by the user, otherwise serves for padding */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   RadarStreamHasErrors;
#if defined(VX1000_OVERLAY) && defined(VX1000_MAILBOX_OVERLAY_CONTROL)
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   CalPageECU;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8   CalPageXCP;
#endif /* VX1000_OVERLAY && VX1000_MAILBOX_OVERLAY_CONTROL */
  /* no padding needed here because this sub-struct is always the last one */
} VX1000_TMP_AT_END_T;

typedef struct VX1000_struct_T
{
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   EventNumber;         /* 0x00 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   EventTimestamp;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   MagicId;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   Version;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   GetIdPtr;            /* 0x10 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   GetIdLen;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   XcpMailboxPtr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   StimCtrlPtr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   RamSynchField;       /* 0x20 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   ToolDetectState;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   OldaPtr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   OldaEventNumber;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   CalPtr;              /* 0x30 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   ToolCtrlState;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   ErrLogAddr;          /* previous: "VX1000_UINT32 TimestampInfoMant" is no longer used, redefined in v9 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    ErrLogSize;          /* previous: "VX1000_INT16  TimestampInfoExpDiv", no longer used, redefined in v9 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    ErrLogIndex;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16   FileVersion;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   ResMgmtPtr;          /* 0x40 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   OvlPtr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   FeatureFlags0;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   TimerFreqkHz;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   TimerAddr;           /* 0x50 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    TimerAddrRegion;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    TimerSize;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    TimerOffset;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    TimerDirection;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   StimDurArrayPtr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   OldaDurArrayPtr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   MemSyncTrigPtr;      /* 0x60 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   Padding32;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   MemSyncCpyPtr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    MemSyncTrigCnt;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    CalibrationStatus;   /* redefined in v15 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    MemSyncCpyCnt;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT8    ReleaseNameHead;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   ReleaseNameBody;     /* 0x70 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   ReleaseNameTail;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   BuildNumber;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   MagicIdSfrAddr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   StaticLutAddr;       /* 0x80 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   DynamicLutAddr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   MemsyncLutAddr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16   DynamicAddressSignalsCnt;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT16   Padding16;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   MeasConfigAddr;      /* 0x90 */
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   DaqInfoAddr;
  VX1000_INNERSTRUCT_VOLATILE VX1000_UINT32   PcieInfoAddr;

  /* note: no pointer to VX1000_COLDSTART_BENCHMARK_DATA because that info is not settled, yet */
#if defined(VX1000_MEMSYNCTRIG_DATA)
  VX1000_MEMSYNCTRIG_DATA;             /* no fix offset */
#endif /* VX1000_MEMSYNCTRIG_DATA */
#if defined(VX1000_DYNADDRSIG_DYNAMICLUT_DT)
  VX1000_DYNADDRSIG_DYNAMICLUT_DT;     /* no fix offset */
#endif /* VX1000_DYNADDRSIG_DYNAMICLUT_DT */
#if defined(VX1000_DYNADDRSIG_MEMSYNCLUT_DT)
  VX1000_DYNADDRSIG_MEMSYNCLUT_DT;     /* no fix offset */
#endif /* VX1000_DYNADDRSIG_MEMSYNCLUT_DT */
#if defined(VX1000_OLDA_DATA)
  VX1000_OLDA_DATA;                    /* no fix offset (note: FW < 1.8 expected 0x40 during cold-start!) */
#endif /* VX1000_OLDA_DATA */
#if defined(VX1000_STIM_DATA)
  VX1000_STIM_DATA;                    /* no fix offset */
#endif /* VX1000_STIM_DATA */
#if defined(VX1000_MAILBOX_DATA)
  VX1000_MAILBOX_DATA;                 /* no fix offset */
#endif /* VX1000_MAILBOX_DATA */
#if defined(VX1000_OVL_DATA)
  VX1000_OVL_DATA;                     /* no fix offset */
#endif /* VX1000_OVL_DATA */
#if defined(VX1000_RES_MGMT_DATA)
  VX1000_RES_MGMT_DATA;                /* no fix offset */
#endif /* VX1000_RES_MGMT_DATA */
#if defined(VX1000_ERRLOG_DATA)
  VX1000_ERRLOG_DATA;                  /* no fix offset */
#endif /* VX1000_ERRLOG_DATA */
#if defined(VX1000_MEMSYNCCPY_DATA)
  VX1000_MEMSYNCCPY_DATA;              /* no fix offset */
#endif /* VX1000_MEMSYNCCPY_DATA */
#if defined(VX1000_MEAS_CFG_DATA)
  VX1000_MEAS_CFG_DATA;                /* no fix offset */
#endif /* VX1000_MEAS_CFG_DATA */
#if defined(VX1000_PCIE_BAR0_START_ADDR)
  VX1000_PCIE_FW_INFO_T PcieInfo;      /* no fix offset */
#endif /* VX1000_PCIE_BAR0_START_ADDR */
#if defined(VX1000_ENABLE_RADAR_API) || defined(VX1000_ENABLE_DAQ_STATUS_API) || defined(VX1000_DAQ_STARTED_CB)
  VX1000_DAQ_FW_INFO_T DaqInfo;        /* no fix offset */
#endif /* VX1000_ENABLE_RADAR_API || VX1000_ENABLE_DAQ_STATUS_API || VX1000_DAQ_STARTED_CB */
  VX1000_TMP_AT_END_T tmp;             /* last part of gVX1000: unpadded AppDriver-internal aux variables (not known to the VX1000)  */
  /* note: other VX data not included by now to not loose backward compatibility of old A2L files; this will be changed changed when */
  /* there'd be a user's requirement for specific linkage of all VX objects or there is a requirement to split ROM and RAM anyway... */
} VX1000_STRUCT_T;

/*------------------------------------------------------------------------------ */
/* VX1000_INIT_ASYNC_START(), VX1000_INIT_ASYNC_END(); legacy VX1000_DATA dummy  */
/* API for declaring and initialising the global VX1000 data needed for VX1000   */
/* Must be called before any other VX1000_xxxx() routine is called but _after_   */
/* timestamp provider has been initialised                                       */

#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(void, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_Init)(void);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_InitAsyncStart)(VX1000_UINT32 initialTDS, const VX1000_VOID *pConfigIAS);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_InitAsyncEnd)(void);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_INT32, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_CheckFeatureStatus)(VX1000_UINT32 *pFeatStatus, VX1000_UINT32 final);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */

#if defined(VX1000_TARGET_TRICORE) || defined(VX1000_SOFTRESET_TIMEOUT_MS)
#define VX1000_START_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_FUNC(VX1000_UINT8, VX1000_CODE_SLOW) VX1000_SUFFUN(vx1000_PrepareSoftreset)(void);
#define VX1000_STOP_SEC_CODE_SLOW
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_TARGET_TRICORE || VX1000_SOFTRESET_TIMEOUT_MS */

/* Define the global data needed for VX1000 (the user must ensure that the VX1000_STRUCT_DATA part is linked first!) */
#define VX1000_DATA /* now an empty dummy because the actual data is already declared in VX1000.c module directly! */

#if defined(VX1000_KEEP_VXSTRUCT_OVER_RESET)
#define VX1000_STRUCT_DATA             volatile VX1000_VAR(VX1000_STRUCT_T, VX1000_VAR_NOINIT_NOCACHE) gVX1000
#else  /* !VX1000_KEEP_VXSTRUCT_OVER_RESET */
#define VX1000_STRUCT_DATA            __attribute__ ((section (".VX1000_Fixed"))) volatile VX1000_VAR(VX1000_STRUCT_T, VX1000_PRM_VAR_ALIGN_8_NOCACHE) gVX1000
#endif /* !VX1000_KEEP_VXSTRUCT_OVER_RESET */

#if defined(VX1000_STRUCT_DATA)
#if defined(VX1000_COMPILED_FOR_SLAVECORES) && defined(VX1000_MAINCORE_VX_STRUCT_ADDR)
#define gVX1000                        (*(VX1000_ADDR_TO_PTR2VVX(VX1000_MAINCORE_VX_STRUCT_ADDR)))
#else  /* !VX1000_COMPILED_FOR_SLAVECORES || !VX1000_MAINCORE_VX_STRUCT_ADDR */
#if defined(VX1000_KEEP_VXSTRUCT_OVER_RESET)
#define VX1000_START_SEC_VAR_NOINIT_NOCACHE
#else  /* !VX1000_KEEP_VXSTRUCT_OVER_RESET */
#define VX1000_START_SEC_PRM_VAR_ALIGN_8_NOCACHE
#endif /* !VX1000_KEEP_VXSTRUCT_OVER_RESET */
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_STRUCT_DATA;
#if defined(VX1000_KEEP_VXSTRUCT_OVER_RESET)
#define VX1000_STOP_SEC_VAR_NOINIT_NOCACHE
#else  /* !VX1000_KEEP_VXSTRUCT_OVER_RESET */
#define VX1000_STOP_SEC_PRM_VAR_ALIGN_8_NOCACHE
#endif /* !VX1000_KEEP_VXSTRUCT_OVER_RESET */
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES || !VX1000_MAINCORE_VX_STRUCT_ADDR */
#endif /* VX1000_STRUCT_DATA */

#if defined(VX1000_OVLENBL_PERSISTENT_EMEM)

#if defined(VX1000_EMEM_HDR_DATA)
#define VX1000_START_SEC_EMEM_VAR_NOCACHE_NOINIT
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
extern VX1000_EMEM_HDR_DATA;
#define VX1000_STOP_SEC_EMEM_VAR_NOCACHE_NOINIT
/*lint -e(451,537,961) OK*/#include "VX1000_MemMap.h" /* PRQA S 5087 */ /* willingly violating MISRA rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#endif /* VX1000_EMEM_HDR_DATA */

#endif /* VX1000_OVLENBL_PERSISTENT_EMEM */

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

#if !defined(VX1000_SUPPRESS_LEGACY_API)

#if (!defined(VX1000_COMPILED_FOR_SLAVECORES)) && (defined(VX1000_MAILBOX) && ((defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH)) || defined(VX1000_MAILBOX_CAL_READ_WRITE)))
#define VX1000_MAILBOX_CONTROL()           (void)VX1000_SUFFUN(vx1000_MailboxControl)(0xFFU);                                                                                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#elif (!defined(VX1000_COMPILED_FOR_SLAVECORES)) && (((VX1000_CO_OFFLOADER_COUNT) > 0U) || defined(VX1000_OVL_INVALIDATE_CACHE_CB) || defined(VX1000_DAQ_STARTED_CB) || defined(VX1000_TRIGGER_DISCOVERING_CB))
#define VX1000_MAILBOX_CONTROL()           (void)VX1000_SUFFUN(vx1000_NonMxMailboxActions)();                                                                                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* VX1000_COMPILED_FOR_SLAVECORES || (!VX1000_CO_OFFLOADER_COUNT && !VX1000_OVL_INVALIDATE_CACHE_CB && !VX1000_DAQ_STARTED_CB && !VX1000_TRIGGER_DISCOVERING_CB) */
#define VX1000_MAILBOX_CONTROL()                 /* empty */
#endif /* VX1000_COMPILED_FOR_SLAVECORES || (!VX1000_CO_OFFLOADER_COUNT && !VX1000_OVL_INVALIDATE_CACHE_CB && !VX1000_DAQ_STARTED_CB && !VX1000_TRIGGER_DISCOVERING_CB) */
#if defined(VX1000_MAILBOX) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#define VX1000_MAILBOX_READ(      L, B)          VX1000_SUFFUN(vx1000_MailboxRead)((L), (B))       /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READ_VOID( L, B)    (void)VX1000_SUFFUN(vx1000_MailboxRead)((L), (B));      /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITE(     L, B)          VX1000_SUFFUN(vx1000_MailboxWrite)((L), /*(const VX1000_CHAR VX1000_DECL_PTR*)*/(B))  /* usable in/as an expression  */                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITE_VOID(L, B)    (void)VX1000_SUFFUN(vx1000_MailboxWrite)((L), /*(const VX1000_CHAR VX1000_DECL_PTR*)*/(B)); /* usable as a whole statement */                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else /* !VX1000_MAILBOX | VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_MAILBOX_READ(      L, B)          VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_EMPTY), ++(L)[0],(VX1000_UINT32)(++(B)[0]),(9UL),(9UL))                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READ_VOID( L, B)          VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_EMPTY), ++(L)[0],((VX1000_UINT32)((VX1000_UINT8)((B)[0]))),(9UL),(9UL)))  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITE(     L, B)          VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_FULL), (L),((VX1000_UINT32)((VX1000_UINT8)((B)[0]))),(9UL),(9UL))                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITE_VOID(L, B)          VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_FULL), (L),((VX1000_UINT32)((VX1000_UINT8)((B)[0]))),(9UL),(9UL)))        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_MAILBOX | VX1000_COMPILED_FOR_SLAVECORES */
#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_PRINTF)) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#define VX1000_PRINTF                      (void)VX1000_SUFFUN(vx1000_MailboxPrintf)
#define VX1000_PRINTF_BE(PF, PAL)          (void)VX1000_SUFFUN(vx1000_MailboxPrintfBackEnd)((PF), (PAL));                                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_MAILBOX || !VX1000_MAILBOX_PRINTF || VX1000_COMPILED_FOR_SLAVECORES */
#if !defined VX1000_PRINTF                       /* in the disabled-case, the user may want to overload our simple and code-less default to get rid of its unavoidable "unused comma separated list" warning by providing a redirection to his own implementation of a variadic do-nothing function. */
#define VX1000_PRINTF                            /*lint -e(505,960) willingly reinterpreting function argument list as comma-separated do-nothing-list*/(void)
#endif /* !VX1000_PRINTF */
#define VX1000_PRINTF_BE(PF, PAL)                VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (((PF)==(PF))?9UL:8UL),((&(PAL)==&(PAL))?9UL:8UL),(9UL),(9UL)))                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_MAILBOX || !VX1000_MAILBOX_PRINTF || VX1000_COMPILED_FOR_SLAVECORES */
#if (defined(VX1000_MAILBOX) && (!defined(VX1000_MAILBOX_NO_SPLITREAD))) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#define VX1000_MAILBOX_READDONE(     )           VX1000_SUFFUN(vx1000_MailboxReadDone)()           /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READDONE_VOID()     (void)VX1000_SUFFUN(vx1000_MailboxReadDone)();          /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READSPLIT(     L,B)       VX1000_SUFFUN(vx1000_MailboxReadSplit)((L), (B))  /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READSPLIT_VOID(L,B) (void)VX1000_SUFFUN(vx1000_MailboxReadSplit)((L), (B)); /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else /* !VX1000_MAILBOX || VX1000_MAILBOX_NO_SPLITREAD || VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_MAILBOX_READDONE(     )           (VX1000_MAILBOX_ERR_SPLIT_PEND)                   /* not perfect, but it was the best match that we were able to find */                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READDONE_VOID()           /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READSPLIT(     L, B)      VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_EMPTY), ++(L)[0],(((B)==(B))?9UL:8UL),(9UL),(9UL))                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READSPLIT_VOID(L, B)      VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_EMPTY), ++(L)[0],(((B)==(B))?9UL:8UL),(9UL),(9UL)))                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_MAILBOX || VX1000_MAILBOX_NO_SPLITREAD || VX1000_COMPILED_FOR_SLAVECORES */
#if (defined(VX1000_MAILBOX) && (!defined(VX1000_MAILBOX_NO_SPLITWRITE))) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#define VX1000_MAILBOX_WRITEDONE(      L)        VX1000_SUFFUN(vx1000_MailboxWriteDone)((L))       /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITEDONE_VOID( L)  (void)VX1000_SUFFUN(vx1000_MailboxWriteDone)((L));      /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITESPLIT(     B)        VX1000_SUFFUN(vx1000_MailboxWriteSplit)((B))      /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITESPLIT_VOID(B)  (void)VX1000_SUFFUN(vx1000_MailboxWriteSplit)((B));     /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else /* !VX1000_MAILBOX || VX1000_MAILBOX_NO_SPLITWRITE || VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_MAILBOX_WRITEDONE(      L)        VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_SIZE), (L),(9UL),(9UL),(9UL))                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITEDONE_VOID( L)        VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_SIZE), (L),(9UL),(9UL),(9UL)))                                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITESPLIT(     B)        VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_FULL), (((B)==(B))?9UL:8UL),(9UL),(9UL),(9UL))                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITESPLIT_VOID(B)        VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_FULL), (((B)==(B))?9UL:8UL),(9UL),(9UL),(9UL)))                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_MAILBOX || VX1000_MAILBOX_NO_SPLITWRITE || VX1000_COMPILED_FOR_SLAVECORES */

#if defined(VX1000_MEAS_CFG_ENABLE)
#define VX1000_MEAS_ADD_EVENT(EVT, PRI, DIR, CYC, TXT)                  (void)VX1000_SUFFUN(vx1000_MeasAddEvent)((VX1000_UINT32)(EVT), (VX1000_UINT32)(PRI), (VX1000_UINT32)(DIR), (VX1000_UINT32)(CYC), (const VX1000_CHAR VX1000_DECL_PTR*)(TXT));                                   /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_ADD_SIGNAL_ENUMID(ID, EVT, ADR, EXT, TYP, NUM)      (void)VX1000_SUFFUN(vx1000_MeasAddSignalById)((VX1000_UINT32)(ID), (VX1000_UINT32)(EVT), (VX1000_UINT32)(ADR), (VX1000_UINT32)(EXT), (VX1000_UINT32)(TYP), (VX1000_UINT32)(NUM));                              /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_ADD_SIGNAL_NAME(NAM, EVT, ADR, EXT, TYP, NUM)       (void)VX1000_SUFFUN(vx1000_MeasAddSignalByName)((const VX1000_CHAR VX1000_DECL_PTR*)(NAM), (VX1000_UINT32)(EVT), (VX1000_UINT32)(ADR), (VX1000_UINT32)(EXT), (VX1000_UINT32)(TYP), (VX1000_UINT32)(NUM));      /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_CONFIG_DONE()                                       (void)VX1000_SUFFUN(vx1000_MeasConfigDone)();                                                                                  /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_CONFIG_INIT()                                       (void)VX1000_SUFFUN(vx1000_MeasConfigInit)();                                                                                  /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_SET_EVENTLIST(PTR, SIZ)                             (void)VX1000_SUFFUN(vx1000_MeasSetEventList)((const VX1000_UINT32 VX1000_DECL_PTR*)(PTR), (VX1000_UINT32)(SIZ));               /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_SET_SIGNALLIST(PTR, SIZ)                            (void)VX1000_SUFFUN(vx1000_MeasSetSignalList)((const VX1000_UINT32 VX1000_DECL_PTR*)(PTR), (VX1000_UINT32)(SIZ));              /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_ADD(NAM, TYP, OFS, NUM)                     (void)VX1000_SUFFUN(VX1000_MeasTypedefAdd)((const VX1000_CHAR VX1000_DECL_PTR*)(NAM), (VX1000_UINT8)(TYP), (VX1000_UINT32)(OFS), (VX1000_UINT32)(NUM));                                                        /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_ADD_ST(NAM, TYP, OFS, NUM)                  (void)VX1000_SUFFUN(VX1000_MeasTypedefAddSt)((const VX1000_CHAR VX1000_DECL_PTR*)(NAM), (const VX1000_CHAR VX1000_DECL_PTR*)(TYP), (VX1000_UINT32)(OFS), (VX1000_UINT32)(NUM));                                /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_BEGIN(NAM, PAD, SIZ)                        (void)VX1000_SUFFUN(VX1000_MeasTypedefBegin)((const VX1000_CHAR VX1000_DECL_PTR*)(NAM), (VX1000_UINT8)(PAD), (VX1000_UINT32)(SIZ));                                                                            /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_END()                                       (void)VX1000_SUFFUN(VX1000_MeasTypedefEnd)();                                                                                                                                                                  /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_INST(NAM, TYP, EVT, ADR, EXT, NUM)          (void)VX1000_SUFFUN(VX1000_MeasTypedefInst)((const VX1000_CHAR VX1000_DECL_PTR*)(NAM), (const VX1000_CHAR VX1000_DECL_PTR*)(TYP), (VX1000_UINT16)(EVT), (VX1000_UINT32)(ADR), (VX1000_UINT8)(EXT), (VX1000_UINT32)(NUM));/* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_INST_ID(ID, TYP, EVT, ADR, EXT, NUM)        (void)VX1000_SUFFUN(VX1000_MeasTypedefInstId)((VX1000_UINT32)(ID), (const VX1000_CHAR VX1000_DECL_PTR*)(TYP), (VX1000_UINT16)(EVT), (VX1000_UINT32)(ADR), (VX1000_UINT8)(EXT), (VX1000_UINT32)(NUM));          /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_MEAS_CFG_ENABLE */
#define VX1000_MEAS_ADD_EVENT(EVT, PRI, DIR, CYC, TXT)                  VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_UINT32)(EVT), (VX1000_UINT32)(PRI), (VX1000_UINT32)(DIR), (VX1000_UINT32)(CYC), ((VX1000_UINT32)((VX1000_UINT8)((TXT)[0])))))                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_ADD_SIGNAL_ENUMID(ID, EVT, ADR, EXT, TYP, NUM)      VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (VX1000_UINT32)(ID), (VX1000_UINT32)(EVT), (VX1000_UINT32)(ADR), VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_UINT32)(EXT), (VX1000_UINT32)(TYP), (VX1000_UINT32)(NUM), 9UL, 9UL)))                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_ADD_SIGNAL_NAME(NAM, EVT, ADR, EXT, TYP, NUM)       VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, ((VX1000_UINT32)((VX1000_UINT8)((NAM)[0]))), (VX1000_UINT32)(EVT), (VX1000_UINT32)(ADR), VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_UINT32)(EXT), (VX1000_UINT32)(TYP), (VX1000_UINT32)(NUM), 9UL, 9UL))) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_CONFIG_DONE()                                       /* empty */
#define VX1000_MEAS_CONFIG_INIT()                                       /* empty */
#define VX1000_MEAS_SET_EVENTLIST(PTR, SIZ)                             VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (VX1000_UINT32)((PTR)[0]), (VX1000_UINT32)(SIZ), 9UL, 9UL))                                                                                                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_SET_SIGNALLIST(PTR, SIZ)                            VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (VX1000_UINT32)((PTR)[0]), (VX1000_UINT32)(SIZ), 9UL, 9UL))                                                                                                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_ADD(NAM, TYP, OFS, NUM)                     VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, ((VX1000_UINT32)((VX1000_UINT8)((NAM)[0]))), (VX1000_UINT32)(TYP), (VX1000_UINT32)(OFS), (VX1000_UINT32)(NUM)))                                                                                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_ADD_ST(NAM, TYP, OFS, NUM)                  VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, ((VX1000_UINT32)((VX1000_UINT8)((NAM)[0]))), ((VX1000_UINT32)((VX1000_UINT8)((TYP)[0]))), (VX1000_UINT32)(OFS), (VX1000_UINT32)(NUM)))                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_BEGIN(NAM, PAD, SIZ)                        VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, ((VX1000_UINT32)((VX1000_UINT8)((NAM)[0]))), (VX1000_UINT32)(PAD), (VX1000_UINT32)(SIZ), 9UL))                                                                                                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_END()                                       /* empty */
#define VX1000_MEAS_TYPEDEF_INST(NAM, TYP, EVT, ADR, EXT, NUM)          VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, ((VX1000_UINT32)((VX1000_UINT8)((NAM)[0]))), (VX1000_UINT32)((VX1000_UINT8)((TYP)[0])), (VX1000_UINT32)(EVT), VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_UINT32)(ADR), (VX1000_UINT32)(EXT), (VX1000_UINT32)(NUM), 9UL, 9UL))) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MEAS_TYPEDEF_INST_ID(ID, TYP, EVT, ADR, EXT, NUM)        VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (VX1000_UINT32)(ID), (VX1000_UINT32)((VX1000_UINT8)((TYP)[0])), (VX1000_UINT32)(EVT), VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_UINT32)(ADR), (VX1000_UINT32)(EXT), (VX1000_UINT32)(NUM), 9UL, 9UL)))   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_MEAS_CFG_ENABLE */

#if !defined(VX1000_ENABLE_RADAR_API)
#define VX1000_DATATRANSFER_START(TP, T64, A, B)               VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,99U, (TP),(T64),(A),(B))   /* return code for "xxxxx" */                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_DATATRANSFER_FINISH(TP)                         VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,99U, (TP),(9UL),(9UL),(9UL))   /* return code for "xxxxx" */                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_DATATRANSFER_GET_INFO(TP, P_A, P_M)             VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,1U, (TP),(((P_A)==(P_A))?9UL:8UL),(9UL),(((P_M)==(P_M))?9UL:8UL)) /* return code for "invalid" */ /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_NOTIFICATION_LINKCHANGE(LT, LS)                 VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (LT),(LS),(9UL),(9UL)))    /* empty */                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_NOTIFICATION_ERROR(OL, TP, ERR)                 VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (OL),(TP),(ERR),(9UL)))    /* empty */                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else  /* VX1000_ENABLE_RADAR_API */
#if !defined(VX1000_UINT64)
#define VX1000_DATATRANSFER_START(TP, T64, A, B)               VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,99U, (TP),(T64),(A),(B))   /* return error code */                                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */                                                                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else  /* VX1000_UINT64 */
#define VX1000_DATATRANSFER_START(TP, T64, A, B)               (VX1000_SUFFUN(vx1000_DataTransferStart)((VX1000_UINT32)(TP), (VX1000_UINT64)(T64), (VX1000_UINT32)(A), (VX1000_UINT32)(B)))            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* VX1000_UINT64 */
#define VX1000_DATATRANSFER_FINISH(TP)                         (VX1000_SUFFUN(vx1000_DataTransferFinish)((VX1000_UINT32)(TP)))                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_DATATRANSFER_GET_INFO(TP, P_A, P_M)             (VX1000_SUFFUN(vx1000_DataTransferGetInfo)((VX1000_UINT32)(TP), (P_A), (P_M)))                                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_NOTIFICATION_LINKCHANGE(LT, LS)            (void)VX1000_SUFFUN(vx1000_NotificationLinkChange)((LT), (LS));                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_NOTIFICATION_ERROR(OL, TP, ERR)            (void)VX1000_SUFFUN(vx1000_NotificationError)((OL), (TP), (ERR));                                                                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* VX1000_ENABLE_RADAR_API */
#if !(defined(VX1000_ENABLE_RADAR_API) || defined(VX1000_ENABLE_DAQ_STATUS_API))
#define VX1000_DAQGETSTATUS(TP, P_S)                           VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (TP),(((P_S)==(P_S))?9UL:8UL),(9UL),(9UL)))   /* empty */                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else  /* VX1000_ENABLE_RADAR_API || VX1000_ENABLE_DAQ_STATUS_API */
#define VX1000_DAQGETSTATUS(TP, P_S)                      (void)VX1000_SUFFUN(vx1000_DaqGetStatus)((TP), (P_S));                                                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* VX1000_ENABLE_RADAR_API || VX1000_ENABLE_DAQ_STATUS_API */

#if defined(VX1000_STIM)
#define VX1000_STIM_GET_CURRENT_STATE(S)         VX1000_SUFFUN(vx1000_StimGetCurrentState)((S))                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_STIM_WAIT(     E, T)              VX1000_SUFFUN(vx1000_StimWait)((E), 1U, (T) )     /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_WAIT_VOID(E, T)        (void)VX1000_SUFFUN(vx1000_StimWait)((E), 1U, (T) );    /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_STIM_WAIT_NO_COPY(E, T)           VX1000_SUFFUN(vx1000_StimWait)((E), 0U, (T) )     /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_CONTROL()              (void)VX1000_SUFFUN(vx1000_StimControl)();                                                                                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_CONTROL()            (void)VX1000_SUFFUN(vx1000_StimControl)();                                                                                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_GET_CURRENT_STATE(S)       VX1000_SUFFUN(vx1000_StimGetCurrentState)((S))                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER(     D, S)         VX1000_SUFFUN(vx1000_BypassTrigger)((D), (S))     /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER_VOID(D, S)   (void)VX1000_SUFFUN(vx1000_BypassTrigger)((D), (S));    /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_DAQ(     D, S)             VX1000_SUFFUN(vx1000_BypassDaq)((D), (S))         /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_DAQ_VOID(D, S)       (void)VX1000_SUFFUN(vx1000_BypassDaq)((D), (S));        /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_STIM(     S )              VX1000_SUFFUN(vx1000_StimWait)((S), 1U, 0UL )     /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_STIM_VOID(S)         (void)VX1000_SUFFUN(vx1000_StimWait)((S), 1U, 0UL );    /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT(     S, T)            VX1000_SUFFUN(vx1000_BypassWait)((S), (T))        /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT_VOID(S, T)      (void)VX1000_SUFFUN(vx1000_BypassWait)((S), (T));       /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_BYPASS(      D, S, T)             VX1000_SUFFUN(vx1000_Bypass)((D), (S), (T))       /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_VOID( D, S, T)       (void)VX1000_SUFFUN(vx1000_Bypass)((D), (S), (T));      /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_REGISTER_STIM_EVENT(D, S,T) (void)VX1000_SUFFUN(vx1000_RegisterStimEvent)((VX1000_UINT8)(D),(VX1000_UINT8)(S),(VX1000_UINT8)(T));                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_STIM_ACTIVE(S)                    VX1000_SUFFUN(vx1000_StimActive)((S))             /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_REQUEST(S)             (void)VX1000_SUFFUN(vx1000_StimRequest)((S));           /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_STIM_SKIP(S)                (void)VX1000_SUFFUN(vx1000_StimSkip)((S));              /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#if defined(VX1000_STIM_BY_OLDA)
#define VX1000_STIMULATE(     D, S, P, T)        VX1000_SUFFUN(vx1000_Stimulate)((D),(S),(P),(T))  /* usable in/as an expression  */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE_VOID(D, S, P, T)  (void)VX1000_SUFFUN(vx1000_Stimulate)((D),(S),(P),(T)); /* usable as a whole statement */                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_STIM_REQUEST_EVENT(x)       (void)VX1000_SUFFUN(vx1000_OldaStimRequestEvent)((VX1000_UINT8)(x));                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else /* !VX1000_STIM_BY_OLDA */
#define VX1000_STIMULATE(     D, S, P, T)        VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(P),(T))   /* return code for "inactive" */                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE_VOID(D, S, P, T)        VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(P),(T)))      /* empty */                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_REQUEST_EVENT(x)             VX1000_EVENT((VX1000_UINT32)(x))                                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_STIM_BY_OLDA */
#else /* !VX1000_STIM */
#define VX1000_STIM_WAIT(     E, T)              VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,1U, (E),(T),(9UL),(9UL)) /* return code for "timeout" */                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_WAIT_VOID(E, T)              VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,1U, (E),(T),(9UL),(9UL)))   /* empty */                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_WAIT_NO_COPY(E, T)           VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,1U, (E),(T),(9UL),(9UL)) /* return code for "timeout" */                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE(     D, S, P, T)        VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(P),(T))    /* return code for "inactive" */                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE_VOID(D, S, P, T)        VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(P),(T)))       /* empty */                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_ACTIVE(S)                    VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (S),(9U),(9U),(9U)) /* return code for "inactive" */                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_CONTROL()                    /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_GET_CURRENT_STATE(S)         VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (S),(9U),(9U),(9U))  /* return code for "no data requested" */                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_REQUEST(S)                   VX1000_DUMMYREAD((S)) /* empty */                                                                                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_SKIP(S)                      VX1000_DUMMYREAD((S)) /* empty */                                                                                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_CONTROL()                  /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_GET_CURRENT_STATE(S)       VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (S),(9U),(9U),(9U))  /* return code for "no data requested" */                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_DAQ(     D, S)             VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(9U),(9U))  /* return code for "inactive" */                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_DAQ_VOID(D, S)             VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(9U),(9U)))     /* empty */                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_STIM(      S)              VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (S),(9U),(9U),(9U))  /* return code for "inactive" */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_STIM_VOID( S)              VX1000_DUMMYREAD((S)) /* empty */                                                                                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER(     D, S)         VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(9U),(9U))   /* return code for "inactive" */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER_VOID(D, S)         VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(9U),(9U)))      /* empty */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT(     S, T)            VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (S),(T),(9UL),(9UL)) /* return code for "inactive" */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT_VOID(S, T)            VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (S),(T),(9UL),(9UL)))    /* empty */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS(     D, S, T)              VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(T),(9UL))   /* return code for "inactive" */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_VOID(D, S, T)              VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (D),(S),(T),(9UL)))      /* empty */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_REGISTER_STIM_EVENT(D, S, T)      VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,1U, (D),(S),(T),(9U)))                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_STIM */
#if defined(VX1000_HOOK_BASED_BYPASSING) && defined(VX1000_STIM)
#define VX1000_BYPASS_HBB_GETVAL_8(H, D)         VX1000_SUFFUN(vx1000_BypassHbbGetVal_8)((H), (D))             /* usable in/as an expression  */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_16(H, D)        VX1000_SUFFUN(vx1000_BypassHbbGetVal_16)((H), (D))            /* usable in/as an expression  */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_32(H, D)        VX1000_SUFFUN(vx1000_BypassHbbGetVal_32)((H), (D))            /* usable in/as an expression  */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#if defined(VX1000_UINT64_T)
#define VX1000_BYPASS_HBB_GETVAL_64(H, D)        VX1000_SUFFUN(vx1000_BypassHbbGetVal_64)((H), (D))            /* usable in/as an expression  */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* VX1000_UINT64_T */
#define VX1000_BYPASS_HBB_GETVAL_FLOAT(H, D)     VX1000_SUFFUN(vx1000_BypassHbbGetVal_Float)((H), (D))         /* usable in/as an expression  */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_DOUBLE(H, D)    VX1000_SUFFUN(vx1000_BypassHbbGetVal_Double)((H), (D))        /* usable in/as an expression  */                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_HOOK_BASED_BYPASSING || !VX1000_STIM */
#define VX1000_BYPASS_HBB_GETVAL_8(H, D)         ((VX1000_UINT8)(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(D), (H),(9U),(9U),(9U))))                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_16(H, D)        ((VX1000_UINT16)(VX1000_DISCARD4DUMMYARGS(VX1000_UINT16,(D), (H),(9U),(9U),(9U))))                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_32(H, D)        VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(D), (H),(9UL),(9UL),(9UL))                                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#if defined(VX1000_UINT64_T)
#define VX1000_BYPASS_HBB_GETVAL_64(H, D)        VX1000_DISCARD4DUMMYARGS((VX1000_UINT64_T),(D), (H),(9ULL),(9ULL),(9ULL))                                                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* VX1000_UINT64_T */
#define VX1000_BYPASS_HBB_GETVAL_FLOAT(H, D)     VX1000_DISCARD4DUMMYARGS(VX1000_FLOAT,(D), (VX1000_FLOAT)(H),(VX1000_FLOAT)(0),(VX1000_FLOAT)(0),(VX1000_FLOAT)(0))                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_DOUBLE(H, D)    VX1000_DISCARD4DUMMYARGS(VX1000_DOUBLE,(D), (VX1000_DOUBLE)(H),(VX1000_DOUBLE)(0),(VX1000_DOUBLE)(0),(VX1000_DOUBLE)(0))                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_HOOK_BASED_BYPASSING || !VX1000_STIM */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: none (system requirement forces this API to be implemented purely as a macro to save memory if unused)      */
/* Classic API:   VX1000_CAL_GET_STATUS                                                                                       */
/* Wrapper API:   VX1000If_CalGetStatus                                                                                       */
/* Parameter1:    None                                                                                                        */
/* Return value:  0: no modification has taken place / 1: modification since boot detected / 2: undecided or feature inactive */
/* Preemption:    No problem                                                                                                  */
/* Termination:   No effect                                                                                                   */
/* Precondition1: vx1000_Init() must have been called                                                                         */
/* Description:   Find out the calibration status                                                                             */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
#if defined(VX1000_DISABLE_INSTRUMENTATION)
#define VX1000_CAL_GET_STATUS()                  ((VX1000_UINT8)(2)) /* provide return value "feature inactive" */                                                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else  /* !VX1000_DISABLE_INSTRUMENTATION */
#define VX1000_CAL_GET_STATUS()                  (gVX1000.CalibrationStatus)                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

#if defined(VX1000_OVERLAY)
#define VX1000_CAL_WAKEUP_REQUESTED()            VX1000_SUFFUN(vx1000_CalWakeupRequested)()                                                                                                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVERLAY_GET_STATUS(P_S, P_P)      (VX1000_UINT8)VX1000_SUFFUN(vx1000_OverlayGetStatus)((P_S), (P_P))                                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#if defined(VX1000_OVLENBL_KEEP_AWAKE)
#define VX1000_IS_CAL_WAKEUP_ACTIVE()            VX1000_SUFFUN(vx1000_IsCalWakeupActive)()                                                                                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_OVLENBL_KEEP_AWAKE */
#define VX1000_IS_CAL_WAKEUP_ACTIVE()            (0U) /* provide return value for "not active" */                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVLENBL_KEEP_AWAKE */
#if defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
#if !defined(VX1000_OVL_SET_CONFIG)
#define VX1000_OVL_SET_CONFIG(V,M,W,N,P,I,C)     VX1000_SUFFUN(vx1000_OverlaySetConfig)((V),(M),(W),(N),(P),(I),(C))                                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_VOID(V,M,W,N,P,I,C) (void)VX1000_SUFFUN(vx1000_OverlaySetConfig)((V),(M),(W),(N),(P),(I),(C));                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVL_SET_CONFIG */
#define VX1000_OVL_SET_CONFIG_DONE(res,pg) (void)VX1000_SUFFUN(vx1000_OverlaySetConfigDone)((res),(pg), 0U);                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_DONE_STUP(r,p) (void)VX1000_SUFFUN(vx1000_OverlaySetConfigDone)((r),(p), (VX1000_UINT8)1U);                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_DONE()             VX1000_SUFFUN(vx1000_OverlayChkPageSwitchDone)()                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_DONE_VOID()  (void)VX1000_SUFFUN(vx1000_OverlayChkPageSwitchDone)();                                                                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_CORE(cores)        VX1000_SUFFUN(vx1000_OverlayChkPageSwitchCore)((cores))                                                                                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_CORE_VOID(c) (void)VX1000_SUFFUN(vx1000_OverlayChkPageSwitchCore)((c));                                                                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_OVL_IS_PAGESW_REQUESTED(cores)    VX1000_SUFFUN(vx1000_overlayIsPageSwitchReq)((cores))                                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_OVLENBL_SYNC_PAGESWITCH */
#if !defined(VX1000_OVL_SET_CONFIG)
/* provide return value for "nothing done": */
#define VX1000_OVL_SET_CONFIG(V,M,W,N,P,I,C)     VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(1U), (V),(M),(VX1000_UINT32)(P),VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(I), (C),(W),(N),(9UL)))                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_VOID(V,M,W,N,P,I,C) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(1U),(V),(M),(VX1000_UINT32)(P),VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(I),(C),(W),(N),(9UL)))) /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVL_SET_CONFIG */
#define VX1000_OVL_SET_CONFIG_DONE(result, page) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (result),(page),(9U),(9U)))                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_DONE_STUP(res,pag) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (res),(pag),(9U),(9U)))                                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_DONE()             ((VX1000_UINT8)(1)) /* provide return value "not ready" */                                                                                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_DONE_VOID()        /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_CORE(cores)        VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,((VX1000_UINT8)(1U)), (cores),(9UL),(9UL),(9UL)) /* provide return value "not ready" */                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_CORE_VOID(cores)   VX1000_DUMMYREAD((cores))                                                                                                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_IS_PAGESW_REQUESTED(cores)    VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (cores),(9UL),(9UL),(9UL)) /* provide return value "no" */                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVLENBL_SYNC_PAGESWITCH */
#if defined(VX1000_OVLENBL_PERSISTENT_EMEM)
#define VX1000_INVALIDATE_EMEM()           (void)VX1000_SUFFUN(vx1000_InvalidateEmem)();                                                                                                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else /* !VX1000_OVLENBL_PERSISTENT_EMEM */
#define VX1000_INVALIDATE_EMEM()                 /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVLENBL_PERSISTENT_EMEM */
#else /* !VX1000_OVERLAY */
#define VX1000_INVALIDATE_EMEM()                 /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVERLAY_GET_STATUS(P_S, P_P)      VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(1U), (((P_S)==(P_S))?9UL:8UL),(((P_P)==(P_P))?9UL:8UL),(9UL),(9UL)) /* provide return code for "invalid" */    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CAL_WAKEUP_REQUESTED()            0U /* provide return value for "no request" */                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_IS_CAL_WAKEUP_ACTIVE()            0U /* provide return value for "not active" */                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#if !defined(VX1000_OVL_SET_CONFIG)
/* provide return value for "nothing done": */
#define VX1000_OVL_SET_CONFIG(V,M,W,N,P,I,C)     VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(1U), (V),(M),(P),VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(I), (C),(W),(N),(9UL)))                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_VOID(V,M,W,N,P,I,C) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(1U), (V),(M),(P),VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(I), (C),(W),(N),(9UL))))            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVL_SET_CONFIG */
#define VX1000_OVL_SET_CONFIG_DONE(result, page) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (result),(page),(9U),(9U)))                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_DONE_STUP(res,pag) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (res),(pag),(9U),(9U)))                                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_DONE()             ((VX1000_UINT8)(1U))       /* provide return value for "not ready" ? */
#define VX1000_OVL_CHK_PAGESW_DONE_VOID()        /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_CORE(cores)        VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,((VX1000_UINT8)(1U)), (cores),(9UL),(9UL),(9UL)) /* provide return value for "not ready" */                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_CORE_VOID(cores)   VX1000_DUMMYREAD((cores))                                                                                                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_IS_PAGESW_REQUESTED(cores)    VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0U, (cores),(9UL),(9UL),(9UL))/* provide return value "no" */                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVERLAY */

#if defined(VX1000_RES_MGMT)
#define VX1000_ENABLE_ACCESS()             (void)VX1000_SUFFUN(vx1000_EnableAccess)();                                                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_DISABLE_ACCESS()                  VX1000_SUFFUN(vx1000_DisableAccess)()                                                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_DISABLE_ACCESS_VOID()       (void)VX1000_SUFFUN(vx1000_DisableAccess)();                                                                                                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_IS_ACCESS_DISABLED()              VX1000_SUFFUN(vx1000_IsAccessDisabled)()                                                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_RES_MGMT */
#define VX1000_DISABLE_ACCESS_VOID()             /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_DISABLE_ACCESS()                  (0U) /* provide return value for "there is no VX anyway" */                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_ENABLE_ACCESS()                   /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_IS_ACCESS_DISABLED()              (1U) /* provide return value for "tool is disabled" */                                                                                                /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_RES_MGMT */

#if defined(VX1000_DETECTION) || (defined(VX1000_TARGET_TRICORE) && (!defined(VX1000_DISABLE_INSTRUMENTATION)))
#define VX1000_DETECTED()                        (VX1000_SUFFUN(vx1000_Detected)())                                                                                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#else  /* !VX1000_DETECTION & !VX1000_TARGET_TRICORE | VX1000_DISABLE_INSTRUMENTATION */
#define VX1000_DETECTED()                        (0U) /* means "no VX detected" */                                                                                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_DETECTION & !VX1000_TARGET_TRICORE | VX1000_DISABLE_INSTRUMENTATION */

#if (VX1000_ERRLOG_SIZE != 0U)
#define VX1000_ERRLOGGER(E)                      VX1000_SUFFUN(vx1000_ErrLogger)(E);                                                                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else /* !VX1000_ERRLOG_SIZE */
#define VX1000_ERRLOGGER(E)                      /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_ERRLOG_SIZE */

#if defined(VX1000_DISABLE_INSTRUMENTATION)
#define VX1000_DETECT_FKL_REQUESTS()             /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_INIT()                            /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_INIT_ASYNC_START()                /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_INIT_ASYNC_END()                  /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CHECK_FEATURESTATUS(P,F)          VX1000_DISCARD4DUMMYARGS(VX1000_INT32,0L, ((VX1000_INT32)(F)),(((P)==(P))?8:9),9,9)                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_CHECK_FEATURESTATUS_VOID(P,F)     VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_INT32,0L, ((VX1000_INT32)(F)),(((P)==(P))?8:9),9,9))                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_PREPARE_SOFTRESET_VOID()          /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_PREPARE_SOFTRESET()               (0U) /* provide return value for "accepted" */
#define VX1000_EVENT(E)                          VX1000_DUMMYREAD((E))                                                                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_EVENT_USER_TIMESTAMP(E, T)        VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (VX1000_UINT32)(E),(T),(9UL),(9UL)))                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_EVENT_PROCESSING_BARRIER(E)       VX1000_DUMMYREAD((E))                                                                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_TIMESTAMP_EVENT(E, T)             VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (VX1000_UINT32)(E),(T),(9UL),(9UL)))                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_TIMESTAMP_UPDATE(T)               VX1000_DUMMYREAD((T))                                                                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_TIMESTAMP()                       /* empty */
#define VX1000_ENABLE_LEGACY_FW_SUPPORT()        /* empty */ /* not a public API (so no VX1000If for it) and only needed internally for FW regression testing */
#else /* !VX1000_DISABLE_INSTRUMENTATION */
#define VX1000_DETECT_FKL_REQUESTS()       (void)VX1000_SUFFUN(vx1000_FlashPrepareLoop)();                                                                                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_INIT()                            VX1000_SUFFUN(vx1000_Init)();                                                                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_INIT_ASYNC_START()          (void)VX1000_SUFFUN(vx1000_InitAsyncStart)(0UL, 0);                                                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_INIT_ASYNC_END()            (void)VX1000_SUFFUN(vx1000_InitAsyncEnd)();                                                                                                                 /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_CHECK_FEATURESTATUS(P,F)          VX1000_SUFFUN(vx1000_CheckFeatureStatus)((P), (VX1000_UINT32)(F))                                                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_CHECK_FEATURESTATUS_VOID(P,F) (void)VX1000_SUFFUN(vx1000_CheckFeatureStatus)((P), (VX1000_UINT32)(F));                                                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#if defined(VX1000_TARGET_TRICORE) || defined(VX1000_SOFTRESET_TIMEOUT_MS)
#define VX1000_PREPARE_SOFTRESET()               VX1000_SUFFUN(vx1000_PrepareSoftreset)()                                                                                                              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_PREPARE_SOFTRESET_VOID()    (void)VX1000_SUFFUN(vx1000_PrepareSoftreset)();                                                                                                             /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_TARGET_TRICORE && !VX1000_SOFTRESET_TIMEOUT_MS */
#define VX1000_PREPARE_SOFTRESET()               (0U) /* provide return value for "accepted" */                                                                                                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_PREPARE_SOFTRESET_VOID()          /* empty */                                                                                                                                           /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_TARGET_TRICORE && !VX1000_SOFTRESET_TIMEOUT_MS */

#if 0 && (defined(VX1000_OLDA) && ((VX1000_OLDA_ACTIVE_EVT_CNT_MAX) > 31U))
#define VX1000_ENABLE_LEGACY_FW_SUPPORT()        do { gVX1000.Olda.Running = 0U; gVX1000.Olda.OldaFeatures3 = 0UL; gVX1000.Olda.VersionO = 0x000AU; } while (0); /* not a public API (so no VX1000If for it) and only needed internally for FW regression testing */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#elif 0 && defined(VX1000_OLDA)
#define VX1000_ENABLE_LEGACY_FW_SUPPORT()        do { gVX1000.Olda.Running = 0U; gVX1000.Olda.OldaFeatures3 = 0UL; gVX1000.Olda.VersionO = 0x0007U; if ((gVX1000.Olda.OldaFeatures & VX1000_FEAT_OLDA_TRIGGER_TYPE7) == VX1000_FEAT_OLDA_TRIGGER_TYPE4) { gVX1000.Olda.OldaFeatures ^= VX1000_FEAT_OLDA_TRIGGER_TYPE4; }} while (0);/* non-public API (without VX1000If) needed only for FW regression testing *//* PRQA S 3412 *//* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_OLDA */
#define VX1000_ENABLE_LEGACY_FW_SUPPORT()        /* nothing to do in this release (the gVX1000 main version is compared "GreaterEqual" by the FW) */ /* not a public API (so no VX1000If for it) and only needed internally for FW regression testing */
#endif /* !VX1000_OLDA */

#if defined(VX1000_OLDA) && (!defined(VX1000_SUPPRESS_IPO_API))
#define VX1000_EVENT_PROCESSING_BARRIER(e) (void)VX1000_SUFFUN(vx1000_OldaEventBarrier)((VX1000_UINT32)(e));                                                                                                                                                   /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_OLDA  || VX1000_SUPPRESS_IPO_API */
#define VX1000_EVENT_PROCESSING_BARRIER(e) VX1000_DUMMYREAD((e))                                                                                                                                                                                               /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OLDA  || VX1000_SUPPRESS_IPO_API */

#if defined(VX1000_OLDA)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: VX1000_TRACE_EVENT                                                                                          */
/* Classic API:   None ?                                                                                                      */
/* Wrapper API:   None ?                                                                                                      */
/* ASAM API:      None                                                                                                        */
/* Parameter1:    eventNumber E [0,512)                                                                                       */
/* Return value:  None                                                                                                        */
/* Preemption:    No problem                                                                                                  */
/* Termination:   No effect                                                                                                   */
/* Precondition1: vx1000_Init() must have been called.                                                                        */
/* Description:   Trigger a TriCore specific TRACE event for the XCP master.                                                  */
/* Devel state:   Deprecated                                                                                                  */
/*----------------------------------------------------------------------------------------------------------------------------*/
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_TRACE_EVENT(e)              (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), (VX1000_UINT32)(VX1000_CLOCK()), 0xFFFFFFFFUL, (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)));                        /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_SPECIAL_EVENT(e)            (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((e), (VX1000_UINT32)(VX1000_CLOCK()), 0xFFFFFFFFUL, ((VX1000_OLDASAVE_TIME | VX1000_OLDATRIG_TRACE) | (VX1000_OLDATRIG_MEMSY | VX1000_OLDATRIG_NIOS)));              /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_SPECIAL_EVENT2(e)           (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((e), (VX1000_UINT32)(VX1000_CLOCK()), 0xFFFFFFFFUL, (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)));                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_TRACE_EVENT(e)              (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), (VX1000_UINT32)(VX1000_CLOCK()), (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)));                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_SPECIAL_EVENT(e)            (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((e), (VX1000_UINT32)(VX1000_CLOCK()), ((VX1000_OLDASAVE_TIME | VX1000_OLDATRIG_TRACE) | (VX1000_OLDATRIG_MEMSY | VX1000_OLDATRIG_NIOS)));                            /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_SPECIAL_EVENT2(e)           (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((e), (VX1000_UINT32)(VX1000_CLOCK()), (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)));                                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_EVENT(e)                    (void)VX1000_SUFFUN(vx1000_OldaEvent)((VX1000_UINT32)(e), (VX1000_UINT32)(VX1000_CLOCK()));                                                                                                                         /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_EVENT_USER_TIMESTAMP(e, t)  (void)VX1000_SUFFUN(vx1000_OldaEvent)((VX1000_UINT32)(e), (VX1000_UINT32)(t));                                                                                                                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else /* !VX1000_OLDA */
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_SPECIAL_EVENT(e)            (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((e), (VX1000_UINT32)(VX1000_CLOCK()), 0xFFFFFFFFUL, (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)) );                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_SPECIAL_EVENT2(e)           (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((e), (VX1000_UINT32)(VX1000_CLOCK()), 0xFFFFFFFFUL, (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)) );                                      /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_EVENT(e)                    (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), (VX1000_UINT32)(VX1000_CLOCK()), 0xFFFFFFFFUL, (VX1000_OLDASAVE_TIME | VX1000_OLDATRIG_TRACE) | (VX1000_OLDATRIG_MEMSY) );                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_EVENT_USER_TIMESTAMP(e, t)  (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), (VX1000_UINT32)(t), 0xFFFFFFFFUL, (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)) );                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_SPECIAL_EVENT(e)            (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((e), (VX1000_UINT32)(VX1000_CLOCK()), (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)) );                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_SPECIAL_EVENT2(e)           (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((e), (VX1000_UINT32)(VX1000_CLOCK()), (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)) );                                                    /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_EVENT(e)                    (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), (VX1000_UINT32)(VX1000_CLOCK()), (VX1000_OLDASAVE_TIME | VX1000_OLDATRIG_TRACE) | (VX1000_OLDATRIG_MEMSY) );                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#define VX1000_EVENT_USER_TIMESTAMP(e, t)  (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), (VX1000_UINT32)(t), (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)) );                                                  /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: VX1000_TIMESTAMP_UPDATE                                                                                     */
/* Classic API:   None ?                                                                                                      */
/* Wrapper API:   None ?                                                                                                      */
/* ASAM API:      None                                                                                                        */
/* Parameter1:    timestamp (32bit upwards counting)                                                                          */
/* Return value:  None                                                                                                        */
/* Preemption:    No problem                                                                                                  */
/* Termination:   No effect                                                                                                   */
/* Precondition1: vx1000_Init() must have been called.                                                                        */
/* Description:   Update the timestamp (optional, only needed if timestamp update rate by events is too slow).                */
/* Devel state:   Deprecated                                                                                                  */
/*----------------------------------------------------------------------------------------------------------------------------*/
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_TIMESTAMP_UPDATE(t)         (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)(0UL, (VX1000_UINT32)(t), 0xFFFFFFFFUL, VX1000_OLDASAVE_TIME );                                                                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_TIMESTAMP_UPDATE(t)         (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)(0UL, (VX1000_UINT32)(t), VX1000_OLDASAVE_TIME );                                                                                                       /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#endif /* !VX1000_OLDA */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: VX1000_TIMESTAMP_EVENT                                                                                      */
/* Classic API:   None ?                                                                                                      */
/* Wrapper API:   None ?                                                                                                      */
/* ASAM API:      None                                                                                                        */
/* Parameter1:    eventNumber E [0,512)                                                                                       */
/* Parameter2:    timestamp (32bit upwards counting)                                                                          */
/* Return value:  None                                                                                                        */
/* Preemption:    No problem                                                                                                  */
/* Termination:   No effect                                                                                                   */
/* Precondition1: vx1000_Init() must have been called.                                                                        */
/* Description:   Trigger an event with a given value for ECU timestamp.                                                      */
/* Devel state:   Deprecated                                                                                                  */
/*----------------------------------------------------------------------------------------------------------------------------*/
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_TIMESTAMP_EVENT(e, t)       (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), (VX1000_UINT32)(t), 0xFFFFFFFFUL, (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)));                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_TIMESTAMP_EVENT(e, t)       (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)((VX1000_UINT32)(e), (VX1000_UINT32)(t), (VX1000_OLDASAVE_TIME | (VX1000_OLDATRIG_TRACE | VX1000_OLDATRIG_MEMSY)));                                     /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: VX1000_TIMESTAMP                                                                                            */
/* Classic API:   None ?                                                                                                      */
/* Wrapper API:   None ?                                                                                                      */
/* ASAM API:      None                                                                                                        */
/* Parameter1:    None                                                                                                        */
/* Return value:  None                                                                                                        */
/* Preemption:    No problem                                                                                                  */
/* Termination:   No effect                                                                                                   */
/* Precondition1: vx1000_Init() must have been called.                                                                        */
/* Description:   Update the timestamp (optional, only needed if timestamp update rate by events is too slow).                */
/* Devel state:   Deprecated                                                                                                  */
/*----------------------------------------------------------------------------------------------------------------------------*/
#if ((VX1000_MEMSYNC_TRIGGER_COUNT) > 0U)
#define VX1000_TIMESTAMP()                 (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)(0UL, (VX1000_UINT32)(VX1000_CLOCK()), 0xFFFFFFFFUL, VX1000_OLDASAVE_TIME );                                                                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#else  /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#define VX1000_TIMESTAMP()                 (void)VX1000_SUFFUN(vx1000_LegacyEventTrigger)(0UL, (VX1000_UINT32)(VX1000_CLOCK()), VX1000_OLDASAVE_TIME );                                                                                          /* PRQA S 3453 */ /* Willingly violating MISRA rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide configurable API wrappers */
#endif /* !VX1000_MEMSYNC_TRIGGER_COUNT */
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

#endif /* !VX1000_SUPPRESS_LEGACY_API */

#endif /* !VX1000_H */
