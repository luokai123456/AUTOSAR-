/*
********************************************************************************
*
* File name: Fee_Cfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation.All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: WangJP/2021.08.14
* Change: new created.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiDaY/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiDaY/2024.08.27
* Change: Change copyright information.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: LiDaY/2024.08.28
* Change: Change the macro definition of the memory mapping label to const
*         variable.
* Cause: Bugfix
********************************************************************************
*/
#ifndef FEE_CFG_H_
#define FEE_CFG_H_

/*
*******************************************************************************
*    Includes
*******************************************************************************
*/
#include "Fls.h"
#include "MemIf_Types.h"
#include "NvM_Cbk.h"

/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define FEE_DEV_ERROR_DETECT                         (STD_ON)
#define FEE_NVM_JOB_END_NOTIFICATION                 (STD_OFF)
#define FEE_NVM_JOB_END_NOTIFICATION_FUNC            (STD_OFF)
#define FEE_NVM_JOB_ERROR_NOTIFICATION               (STD_OFF)
#define FEE_NVM_JOB_ERROR_NOTIFICATION_FUNC          (STD_OFF)
#define FEE_POLLING_MODE                             (STD_ON)
#define FEE_SET_MODE_SUPPORTED                       (STD_ON)
#define FEE_VERSION_INFO_API                         (STD_ON)
#define FEE_VIRTUAL_PAGE_SIZE                        (64U)
#define FEE_BLOCK_OVER_HEAD                          (192U)
#define FEE_PAGE_OVER_HEAD                           (0U)
#define FEE_SECTOR_MAX_BLOCK_NUMBER                  (0x400U)
#define FEE_BLOCK_NUMBER                             (187U)
#define FEE_WRITE_BUFFER_SIZE                        (4096U)
#define FEE_ERASED_INIT_VALUE                        (0xff)
#define MAX_NUM_SCAN_RETRYIES                        (2U)
#define FEE_MEMACC_MODE_ENABLE                       (STD_OFF)

/* Number of sector for paratiton . */
#define FEE_SECTOR_NUMBER                            (2U)
#define FEE_FLS_PENDING_TIMEOUT_COUNT                (0U)
#define MAX_NUM_INTER_ERROR_RETRYIES                 (0U)
#define FEE_PERIOD_POLLING_BLOCK_NUM                 (150U)
#define FEE_COMPATIBLE_LEGACY_SECTOR_HEAD            (STD_OFF)
#define FEE_IMMEDIATE_WRITE_ENABLE                   (STD_OFF)
#define FEE_BLOCK_EARSE_DATA_CHECKSUM                (0x13ECU)
#define FEE_SECTOR_HEAD_VAILD_ID                     (0x12345678U)
#define FEE_COMPATIBLE_SECTOR_HEAD_VAILD_ID          (0x4E657543U)
#define FEE_SCAN_SECTOR_TAIL                         (STD_ON)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
*******************************************************************************
*    Global Types
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Variables
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Constants
*******************************************************************************
*/

/*
*******************************************************************************
*    Global Functions
*******************************************************************************
*/

#endif /* FEE_CFG_H_ */

