/*
********************************************************************************
*
* File name: MemIf_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.11.13
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: TongQian/2015.05.10
* Change: Format adjustment.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date:liuziyang/2020.03.27
* Change: Only version update to V3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: WangLX/2024.08.22
* Change: Change file name information.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: Chixp/2025.06.05
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
*/
#ifndef MEMIF_TYPES_H_
#define MEMIF_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
//wjc mcal
#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"

#define MEMIF_VENDOR_ID_PLUGIN                      176
#define MEMIF_AR_REL_MAJOR_VER                      4
#define MEMIF_AR_REL_MINOR_VER                      4
#define MEMIF_AR_REL_REVISION_VER                   0
#define MEMIF_SW_MAJOR_VERSION_PLUGIN               3
#define MEMIF_SW_MINOR_VERSION_PLUGIN               0
#define MEMIF_SW_PATCH_VERSION_PLUGIN               0

#if (MCAL_VENDOR_ID != MEMIF_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : MEMIF_VENDOR_ID_PLUGIN "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : MEMIF_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != MEMIF_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : MEMIF_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != MEMIF_AR_REL_REVISION_VER)
    #error " NON-MATCHED DATA : MEMIF_AR_REL_REVISION_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != MEMIF_SW_MAJOR_VERSION_PLUGIN)
    #error " NON-MATCHED DATA : MEMIF_SW_MAJOR_VERSION_PLUGIN "
#endif
#if (MCAL_SW_MINOR_VERSION != MEMIF_SW_MINOR_VERSION_PLUGIN)
    #error " NON-MATCHED DATA : MEMIF_SW_MINOR_VERSION_PLUGIN "
#endif
#if (MCAL_SW_PATCH_VERSION != MEMIF_SW_PATCH_VERSION_PLUGIN)
    #error " NON-MATCHED DATA : MEMIF_SW_PATCH_VERSION_PLUGIN "
#endif
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Development Errors. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define MEMIF_E_NO_ERROR        (0x00u) /* No error. */
#define MEMIF_E_PARAM_DEVICE    (0x01u) /* API service called with wrong device index parameter. */
#define MEMIF_E_PARAM_POINTER   (0x02u) /* API service called with NULL pointer argument. */

/* Deveice ID. */
#define MEMIF_DEVEICE_EA         (0u)   /* EEPROM Abstraction. */
#define MEMIF_DEVEICE_FEE        (1u)   /* Flash EEPROM Emulation. */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Denotes the current status of the underlying abstraction module and device drive. */
typedef enum
{
  MEMIF_UNINIT = 0U,    /* The underlying abstraction module or device driver has not been initialized (yet). */
  MEMIF_IDLE,       /* The underlying abstraction module or device driver is currently idle. */
  MEMIF_BUSY,    /* The underlying abstraction module or device driver is currently busy. */
  MEMIF_BUSY_INTERNAL    /* The underlying abstraction module is busy with internal management operations. The underlying device driver can be busy or idle. */
} MemIf_StatusType;

/* Denotes the result of the last job. */
typedef enum
{
  MEMIF_JOB_OK = 0U,    /* The job has been finished successfully. */
  MEMIF_JOB_FAILED,     /* The job has not been finished successfully. */
  MEMIF_JOB_PENDING,    /* The job has not yet been finished. */
  MEMIF_JOB_CANCELED,   /* The job has been canceled. */
  MEMIF_BLOCK_INCONSISTENT,   /* 1. The requested block is inconsistent, it may contain corrupted data.2. Block is NOT found. */
  MEMIF_BLOCK_INVALID   /* The requested block has been marked as invalid, the requested operation can not be performed. */
} MemIf_JobResultType;

/* Denotes the operation mode of the underlying abstraction modules and device drivers. */
typedef enum
{
    MEMIF_MODE_SLOW = 0U,    /* The underlying memory abstraction modules and drivers are working in slow mode. */
    MEMIF_MODE_FAST    /* The underlying memory abstraction modules and drivers are working in fast mode. */
} MemIf_ModeType;

typedef enum
{
    FLS_JOB_IDLE = 0,
    FLS_JOB_START,
    FLS_JOB_PENDING,
    FLS_JOB_FAILED,
    FLS_JOB_COMPLETED,
}Fls_SubJobStatusType; //wjc
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

#endif /* MEMIF_TYPES_H_ */
