/*
********************************************************************************
*
* File name: Std_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : WangJipeng/2018.10.13
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : WangJipeng/2018.11.14
* Change: Change Std_ReturnType from enum to uint8.
* Cause: Bugfix.
********************************************************************************
* Version: 1.2
* Author/Date : WangJipeng/2020.01.06
* Change: Improve Specification of Standard Types requirements.
* Cause: UpData.
********************************************************************************
* Version: 3.0
* Author/Date : WangJipeng/2020.07.02
* Change: Add Std module and autosar release version.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date : WangJipeng/2020.09.16
* Change: Add STD_LOW, STD_HIGH, STD_IDLE, STD_ACTIVE related notes.
*         Change SWS_Std_00006(E_OK) definition.
*         Change STD_TYPES_H to STD_TYPES_H_.
* Cause: Update
********************************************************************************
*/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Platform_Types.h"
#include "Compiler.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Module identification and version. */
#define STD_VENDOR_ID                            (119U)
#define STD_MODULE_ID                            (197U)
#define STD_SW_MAJOR_VERSION                     (3U)
#define STD_SW_MINOR_VERSION                     (1U)
#define STD_SW_PATCH_VERSION                     (0U)

/* AUTOSAR Version. */
#define STD_AR_RELEASE_MAJOR_VERSION             (4U)
#define STD_AR_RELEASE_MINOR_VERSION             (2U)
#define STD_AR_RELEASE_REVISION_VERSION          (2U)

/* SWS_Std_00006 */
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 	 (0x00U)
typedef unsigned char StatusType;	/* OSEK compliance. */
#endif

#define E_NOT_OK (0x01U)

/* SWS_Std_00007 */
#define STD_LOW		(0x00U) /* Physical state 0V. */
#define STD_HIGH	(0x01U)	/* Physical state 5V or 3.3V. */

/* SWS_Std_00013 */
#define STD_IDLE	(0x00U) /* Logical state idle. */
#define STD_ACTIVE	(0x01U) /* Logical state active. */

/* SWS_Std_00010 */
#define STD_OFF		(0x00U)
#define STD_ON		(0x01U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 Std_ReturnType;	/* SWS_Std_00005 */

/* This type shall be used to request the version of a BSW module. */
typedef struct
{
   uint16 vendorID;
   uint16 moduleID;
   uint8  sw_major_version;
   uint8  sw_minor_version;
   uint8  sw_patch_version;
} Std_VersionInfoType;	/* SWS_Std_00015 */

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

#endif /* STD_TYPES_H_ */
