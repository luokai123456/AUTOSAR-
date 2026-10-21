/*
********************************************************************************
*
* File name: NvM_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.07.03
* Change: New Create
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: Baowanglong/2019.11.12
* Change: Modify the code format
* Cause: Coding Standards
********************************************************************************
* Version: 3.0
* Author/Date: Baowanglong/2020.02.17
* Change: Only version update to V3.0
* Cause: Update
********************************************************************************
********************************************************************************
* Version: 3.1
* Author/Date: Chenyuyuan/2022.05.31
* Change: Resolve the redefinition of Rte_Type.h
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiDY/2023.03.04
* Change: Add NVM_REQ_COMPLTED/NVM_REQ_NOT_COMPLTED macro definition.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiDY/2023.03.07
* Change: Delete ifndef about Rte.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: WangLX/2024.04.25
* Change: Add NVM_COMPILEDCONFIGID_LENGHT macro definition.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: ZengJX/2025.06.04
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: ZengJX/2025.06.18
* Change: Move application type definitions and mocros definitions to RTE.
* Cause: Optimization
********************************************************************************
*/
#ifndef NVM_TYPES_H_
#define NVM_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Rte_NvM_Type.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* The Fee Of queue are complted */
#define NVM_REQ_COMPLTED                (0x01U)
/* The Fee Of queue are not complted. */
#define NVM_REQ_NOT_COMPLTED            (0x02U)
/* The NvM_CompiledConfigId length. */
#define NVM_COMPILEDCONFIGID_LENGHT    (0x02U)

/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */
#define NVM_INIT                        (0x00U) /* Service ID of NvM_Init. */
#define NVM_SET_DATA_INDEX              (0x01U) /* Service ID of NvM_SetDataIndex. */
#define NVM_GET_DATA_INDEX              (0x02U) /* Service ID of NvM_GetDataIndex. */
#define NVM_SET_BLOCK_PROTECTION        (0x03U) /* Service ID of NvM_SetBlockProtection. */
#define NVM_GET_ERROR_STASUS            (0x04U) /* Service ID of NvM_GetErrorStatus. */
#define NVM_SET_RAM_BLOCK_STATUS        (0x05U) /* Service ID of NvM_SetRamBlockStatus. */
#define NVM_READ_BLOCK                  (0x06U) /* Service ID of NvM_ReadBlock. */
#define NVM_WRITE_BLOCK                 (0x07U) /* Service ID of NvM_WriteBlock. */
#define NVM_RESTORE_BLOCK_DEFAULTS      (0x08U) /* Service ID of NvM_RestoreBlockDefaults. */
#define NVM_ERASE_NV_BLOCK              (0x09U) /* Service ID of NvM_EraseNvBlock. */
#define NVM_CANCEL_WRITE_ALL            (0x0AU) /* Service ID of NvM_CancelWriteAll. */
#define NVM_INVALIDATE_NV_BLOCK         (0x0BU) /* Service ID of NvM_InvalidateNvBlock. */
#define NVM_READ_ALL                    (0x0CU) /* Service ID of NvM_ReadAll. */
#define NVM_WRITE_ALL                   (0x0DU) /* Service ID of NvM_WriteAll. */
#define NVM_MAIN_FUNCTION               (0x0EU) /* Service ID of NvM_MainFunction. */
#define NVM_GET_VERSION_INFO            (0x0FU) /* Service ID of NvM_GetVersionInfo. */
#define NVM_CANCEL_JOBS                 (0x10U) /* Service ID of NvM_CancelJobs. */
#define NVM_JOB_END_NOTIFICATION        (0x11U) /* Service ID of NvM_JobEndNotification. */
#define NVM_JOB_ERROR_NOTIFICATION      (0x12U) /* Service ID of NvM_JobErrorNotification. */
#define NVM_SET_BLOCK_LOCK_STATUS       (0x13U) /* Service ID of NvM_SetBlockLockStatus. */
#define NVM_READ_PRAM_BLOCK             (0x16U) /* Service ID of NvM_ReadPRAMBlock. */
#define NVM_WRITE_PRAM_BLOCK            (0x17U) /* Service ID of NvM_WritePRAMBlock. */
#define NVM_RESTORE_PRAM_BLOCK_DEFAULTS (0x18U) /* Service ID of NvM_RestorePRAMBlockDefaults. */
#define NVM_VALIDATE_ALL                (0x19U) /* Service ID of NvM_ValidateAll. */
#define NVM_NO_REQUEST                  (0xFFU) /* No request. */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */

#ifndef NULL_PTR
#define NULL_PTR    ((void *)0U)
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

#endif /* NVM_TYPES_H_ */
