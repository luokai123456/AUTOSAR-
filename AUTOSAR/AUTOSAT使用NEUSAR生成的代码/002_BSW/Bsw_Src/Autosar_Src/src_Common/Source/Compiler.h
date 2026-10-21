/*
********************************************************************************
*
* File name: Compiler.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : WangJP/2018.12.20
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : WangJP/2019.12.11
* Change: Add Compiler symbol definition.
*         Add SWS_COMPILER ID.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date : WangJP/2020.07.02
* Change: Add Compiler module and autosar release version.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date : WangJP/2020.08.25
* Change: Correction of writing errors for CONST(type, memclass).
* Cause: BugFix
********************************************************************************
* Version: 3.2
* Author/Date : WangJP/2021.12.30
* Change: Change the compiler symbol definition.
* Cause: Optimization
********************************************************************************
*/
#ifndef COMPILTER_H_
#define COMPILTER_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Compiler_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Module identification and version. */
#define COMPILER_VENDOR_ID                            (119U)
#define COMPILER_MODULE_ID                            (198U)
#define COMPILER_SW_MAJOR_VERSION                     (3U)
#define COMPILER_SW_MINOR_VERSION                     (0U)
#define COMPILER_SW_PATCH_VERSION                     (1U)

/* AUTOSAR Version. */
#define COMPILER_AR_RELEASE_MAJOR_VERSION             (4U)
#define COMPILER_AR_RELEASE_MINOR_VERSION             (2U)
#define COMPILER_AR_RELEASE_REVISION_VERSION          (2U)

/* Compiler symbol definition */
#define _HIGHTECH_C_TC39X_		/* SWS_COMPILER_00010 */

/* General definitions */
/* The memory class AUTOMATIC shall be provided as empty definition, used for
the declaration of local pointers. */
#ifndef AUTOMATIC
#define AUTOMATIC	/* SWS_COMPILER_00046 */
#endif

/* The memory class TYPEDEF shall be provided as empty definition. */
#ifndef TYPEDEF
#define TYPEDEF		/* SWS_COMPILER_00059 */
#endif

/* The NULL_PTR define with a void pointer to zero definition. */
#ifndef NULL_PTR
#define NULL_PTR	((void *)0)		/* SWS_COMPILER_00051 */
#endif

/* The INLINE define for abstraction of the keyword inline. */
#ifndef INLINE
#define INLINE	inline				/* SWS_COMPILER_00057 */
#endif

/* The LOCAL_INLINE define for abstraction of the keyword inline in functions with “static” scope. */
#ifndef LOCAL_INLINE
#define LOCAL_INLINE	static inline	/* SWS_COMPILER_00060 */
#endif

/* Function definitions */
/* The FUNC macro for the declaration and definition of functions that ensures 
correct syntax of function declarations as required by a specific compiler. */
#define FUNC(rettype, memclass) rettype		/* SWS_COMPILER_00001 */

/* The FUNC_P2CONST macro for the declaration and definition of functions returning
 a pointer to a constant. This shall ensure the correct syntax of function declarations 
 as required by a specific compiler */
#define FUNC_P2CONST(rettype, ptrclass, memclass)	const rettype*	/* SWS_COMPILER_00061 */

/* The FUNC_P2VAR macro for the declarationand definition of functions returning
 a pointer to a variable. This shall ensure the correct syntax of function declarations 
 as required by a specific compiler. */
#define FUNC_P2VAR(rettype, ptrclass, memclass) rettype* /* SWS_COMPILER_00063 */

/* Pointer definitions */
/* The P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables. */
#define P2VAR(ptrtype, memclass, ptrclass)		ptrtype*	/* SWS_COMPILER_00006 */

/* The P2CONST macro for the declaration and definition of pointers in RAM pointing to constants. */
#define P2CONST(ptrtype, memclass, ptrclass)	const ptrtype*	/* SWS_COMPILER_00013 */

/* The CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables. */
#define CONSTP2VAR(ptrtype, memclass, ptrclass)	ptrtype* const	/* SWS_COMPILER_00031 */

/* The CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants. */
#define CONSTP2CONST(ptrtype, memclass, ptrclass)	const ptrtype* const	/* SWS_COMPILER_00032 */

/* The P2FUNC macro for the type definition of pointers to functions. */
#define P2FUNC(rettype, ptrclass, fctname)		rettype (* fctname)		/* SWS_COMPILER_00039 */

/* The CONSTP2FUNC macro for the type definition of constant pointers to functions. */
#define CONSTP2FUNC(rettype, ptrclass, fctname)	rettype (* const fctname)	/* SWS_COMPILER_00065 */

/* Variable definitions */
/* Define the CONST macro for the declaration and definition of constant */
#define CONST(type, memclass) const type /* SWS_COMPILER_00023 */

/* The VAR macro for the declaration and definition of variables. */
#define VAR(vartype, memclass) vartype		/* SWS_COMPILER_00026 */

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

#endif /* COMPILTER_H */	/* SWS_COMPILER_00047 */
