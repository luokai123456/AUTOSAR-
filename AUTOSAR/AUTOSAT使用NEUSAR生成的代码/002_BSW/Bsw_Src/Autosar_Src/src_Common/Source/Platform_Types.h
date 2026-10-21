/*
********************************************************************************
*
* File name: Platform_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : WangJP/2018.11.13
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : WangJP/2019.12.10
* Change: Redefine types and symbols according to autosar specifications. 
*         Remove extension definitions.
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date : WangJP/2020.07.02
* Change: Add platform module and autosar release version.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date : WangJP/2021.12.30
* Change: 1. Change the data type definition according to the TC39x.
*         2. Change the bit order and byte order according to the TC39x.
* Cause: Optimization 
********************************************************************************
*/
#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

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
/* Module identification and version. */
#define PLATFORM_VENDOR_ID                            (119U)
#define PLATFORM_MODULE_ID                            (199U)
#define PLATFORM_SW_MAJOR_VERSION                     (3U)
#define PLATFORM_SW_MINOR_VERSION                     (0U)
#define PLATFORM_SW_PATCH_VERSION                     (1U)

/* AUTOSAR Version. */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION             (4U)
#define PLATFORM_AR_RELEASE_MINOR_VERSION             (2U)
#define PLATFORM_AR_RELEASE_REVISION_VERSION          (2U)

/* In case of in-built compiler support of the symbols, redefinitions shall be avoided using a conditional check. */
/* SWS_Platform_00026, SWS_Platform_00056, SWS_Platform_00054 */
#ifndef TRUE
#define TRUE   	(1U)
#endif

#ifndef FALSE
#define FALSE  	(0U)
#endif

/* SWS_Platform_00057 */
#define CPU_TYPE_8		(8U)
#define CPU_TYPE_16		(16U)
#define CPU_TYPE_32		(32U)

#define MSB_FIRST 		(0U)		/* Big endian bit. */
#define LSB_FIRST 		(1U)		/* Little endian bit. */

#define HIGH_BYTE_FIRST (0U)		/* Big endian byte.  */
#define LOW_BYTE_FIRST 	(1U)		/* Little endian byte. */

/* the register width of the CPU. */
#define  CPU_TYPE CPU_TYPE_32			/* SWS_Platform_00044, SWS_Platform_00045, SWS_Platform_00064 */

/* the appropriate bit order on register level. */
#define CPU_BIT_ORDER LSB_FIRST			/* SWS_Platform_00043, SWS_Platform_00038, SWS_Platform_00048 ,SWS_Platform_00049 */

//Modified
/* the appropriate byte order on memory level. */
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST	/* SWS_Platform_00046, SWS_Platform_00039, SWS_Platform_00050, SWS_Platform_00051 */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* The standard AUTOSAR types. */
typedef unsigned char		boolean;	/* SWS_Platform_00027, SWS_Platform_00060 */
typedef signed char 		sint8;		/* SWS_Platform_00016 */
typedef unsigned char 		uint8;		/* SWS_Platform_00013 */
typedef short               int16;		// ADD MCAL
typedef short 		        sint16;		/* SWS_Platform_00017 */
typedef unsigned short		uint16;		/* SWS_Platform_00014 */
typedef long 		        sint32;		/* SWS_Platform_00018 */
typedef unsigned long		uint32;		/* SWS_Platform_00015 */

/* The optimized AUTOSAR types. */
typedef unsigned long 		uint8_least;	/* SWS_Platform_00020 */
typedef unsigned long 		uint16_least;	/* SWS_Platform_00021 */
typedef unsigned long 		uint32_least;	/* SWS_Platform_00022 */
typedef signed long 		sint8_least;	/* SWS_Platform_00023 */
typedef signed long 		sint16_least;	/* SWS_Platform_00024 */
typedef signed long 		sint32_least;	/* SWS_Platform_00025 */

typedef long long	        sint64;		/* SWS_Platform_00067 */
typedef unsigned long long	uint64;		/* SWS_Platform_00066 */

typedef float float32;		/* SWS_Platform_00041 */
typedef double float64;		/* SWS_Platform_00042 */

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

#endif /* PLATFORM_TYPES_H_ */
