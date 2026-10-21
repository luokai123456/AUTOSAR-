/*
********************************************************************************
*
* File name: NvM.h
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
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangJipeng/2019.05.21
* Change: Change the Module ID and Vendor ID.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: WangJipeng/2019.08.08
* Change: Add BSwm header file BswM_NvM.h.
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date: Baowanglong/2020.02.17
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: Hanbaiyu/2020.03.23
* Change: Modify the API configuration class judgment conditions.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: Hanbaiyu/2020.03.27
* Change: Modify the major version number.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: Hanbaiyu/2020.05.07
* Change: Declare new extern global variables NvM_ModuleState and Nvm_QueueHeader.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: HanBY/2020.11.04
* Change: Deleting memrory maps for variable or function declarations.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: HanBY/2020.12.07
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: HanBY/2021.10.18
* Change: Modify the wrong type name from MVN_StatusType to NvM_Status_Type.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: HanBY/2021.10.20
* Change: Update the minor version.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: HanBY/2021.10.21
* Change: Update the minor version.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: HanBY/2021.11.01
* Change: Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: HanBY/2021.11.19
* Change: Update the patch version due to bug.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: HanBY/2021.12.30
* Change: Update the patch version due to bug.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: Chenyuyuan/2022.05.31
* Change: Update the patch version due to bug.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: LiDY/2022.12.29
* Change: Update the patch version due to bug.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: LiDY/2023.03.03
* Change: 1. Add NVM_EA_DEVICEID/NVM_FEE_DEVICEID/NVM_FEE_QUEUE_EMPTY macro
*            definition.
*         2. Update the patch version.
*         3. Add function NvM_SetBlockServices and NvM_GetQueueStatus declaration.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: LiDY/2023.05.17
* Change: Update the version to 3.7.0.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: LiDY/2023.5.26
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: LiDY/2023.5.26
* Change: Update the revision version to 3.7.0.1.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: WangLX/2023.09.18
* Change: Update the minor version, update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: WangLX/2024.01.16
* Change: Update the minor version, update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: WangLX/2024.02.28
* Change: Modify the label of the input parameter Ptrclass for NvM_WriteBlock.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: WangLX/2024.04.01
* Change: Update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: WangLX/2024.04.25
* Change: 1.Add a memory-map label to function and variable declarations.
*         2.Update the minor version, update REVISION version.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: WangLX/2024.07.31
* Change: Delete "NvM_Chk.h" header file reference.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: WangLX/2024.12.20
* Change: Update the minor version, update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: WangLX/2025.03.31
* Change: 1.Fix QAC and Polyspace warnings and add analysis results.
*         2.Updata Minor Version and Revision Version.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: ZengJX/2025.06.04
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: ZengJX/2024.06.16
* Change: Update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: ZengJX/2024.06.23
* Change: Update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: ZengJX/2024.08.01
* Change: Update REVISION version.
* Cause: Update
********************************************************************************
*/
#ifndef NVM_H_
#define NVM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "NvM_Cfg.h"
#include "NvM_Types.h"
#include "NvM_Def.h"
#include "NvM_Private.h"
#include "BswM_NvM.h"
#include "NvM_Queue.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */
/* Nvm module ID for Det. */
#define NVM_INSTANCE_ID                    (0U)
/* NvM version information. */
#define NVM_VENDOR_ID                      (119U)
#define NVM_MODULE_ID                      (20U)
#define NVM_SW_MAJOR_VERSION               (3U)
#define NVM_SW_MINOR_VERSION               (15U)
#define NVM_SW_PATCH_VERSION               (0U)
#define NVM_SW_REVISION_VERSION            (10U)
#define NVM_AR_RELEASE_MAJOR_VERSION       (4U)
#define NVM_AR_RELEASE_MINOR_VERSION       (2U)
#define NVM_AR_RELEASE_REVISION_VERSION    (2U)

/* Development Errors. */
/* No error. */
#define NVM_E_NO_ERR                       (0x00U)

/* The passed BlockID is out of range. */
#define NVM_E_PARAM_BLOCK_ID               (0x0AU)

/* Management type is not satisfied. */
#define NVM_E_PARAM_BLOCK_TYPE             (0x0BU)

/* DataIndex parameter exceeds the total number of configured datasets. */
#define NVM_E_PARAM_BLOCK_DATA_IDX         (0x0CU)

/* No permanent RAM block and no explicit synchronization are configured and a
   NULL pointer is passed via the parameter NvM_DstPtr. */
#define NVM_E_PARAM_ADDRESS                (0x0DU)

/* A NULL pointer is passed via the parameter RequestResultPtr. */
#define NVM_E_PARAM_DATA                   (0x0EU)

/* A NULL pointer is passed via the parameter versioninfo. */
#define NVM_E_PARAM_POINTER                (0x0FU)

/* Has no default data and no NvMInitBlockCallback configured. */
#define NVM_E_BLOCK_WITHOUT_DEFAULTS       (0x11U)

/* NVM not yet initialized. */
#define NVM_E_NOT_INITIALIZED              (0x14U)

/* NVRAM block identifier is already queued or currently in progress. */
#define NVM_E_BLOCK_PENDING                (0x15U)

/* This block configuration, depending on whether the build version mode is
   development mode. */
#define NVM_E_BLOCK_CONFIG                 (0x18U)

/* API write request failed for this block because RAM block is locked. */
#define NVM_E_BLOCK_LOCKED                 (0x19U)

/* The queue is full. */
#define NVM_E_QUEUE_FULL                   (0xA0U)

/* The EA DeviceId. */
#define NVM_EA_DEVICEID                    (0U)

/* The Fee DeviceId. */
#define NVM_FEE_DEVICEID                   (1U)

/* Number of Fee devices in the queue is emptied. */
#define NVM_FEE_OF_QUEUE_EMPTY             (0U)

/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */
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
#define NVM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern VAR(NvM_Status_Type, NVM_VAR_INIT) NvM_ModuleState;
extern VAR(Nvm_QueueProcss_st, NVM_VAR_INIT) NvM_QueueCrrntJob;
extern VAR(Nvm_QueueHeader_st, NVM_VAR_INIT) Nvm_QueueHeader;

#define NVM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
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
#define NVM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* PolySpace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_NvM_20.9" */
#if (NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_3)
/* Service for setting/resetting the write protection for a NV block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockProtection
(
    NvM_BlockIdType BlockId,
    boolean ProtectionEnabled
);
/* Service to erase a NV block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock(NvM_BlockIdType BlockId);
/* Service to invalidate a NV block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlock
(
    NvM_BlockIdType BlockId
);
#endif

/* PolySpace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_NvM_20.9" */
#if (NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2)
/* Service for setting the DataIndex of a dataset NVRAM block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex
(
    NvM_BlockIdType BlockId,
    uint8 DataIndex
);
/* Service for getting the currently set DataIndex of a dataset NVRAM block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_GetDataIndex
(
    NvM_BlockIdType BlockId,
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr
);
/* Service to copy the data of the NV block to its corresponding RAM block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
);
/* Service to copy the data of the RAM block to its corresponding NV block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
);
/* Service to restore the default data to its corresponding RAM block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
);
/* Service to cancel all jobs pending for a NV block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs(NvM_BlockIdType BlockId);
/* Service to copy the data of the NV block to
   its corresponding permanent RAM block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlock
(
    NvM_BlockIdType BlockId
);
/* Service to copy the data of the RAM block to
   its corresponding permanent RAM block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlock
(
    NvM_BlockIdType BlockId
);
/* Service to restore the default data to
   its corresponding permanent RAM block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaults
(
    NvM_BlockIdType BlockId
);
/* Initiates a multi block validation request. */
extern FUNC(void, NVM_CODE) NvM_ValidateAll(void);
#endif

/* Service to read the block dependent error/status information. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
    NvM_BlockIdType BlockId,
    P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
);

/* PolySpace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_NvM_20.9" */
#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
/* Service for setting the RAM block status of an NVRAM block. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus
(
    NvM_BlockIdType BlockId,
    boolean BlockChanged
);
#endif

/* Service for setting the lock status of a permanent RAM block or of the
   explicit synchronization of a NVRAM block. */
extern FUNC(void, NVM_CODE) NvM_SetBlockLockStatus
(
    NvM_BlockIdType BlockId,
    boolean BlockLocked
);
/* Initiates a multi block read request. */
extern FUNC(void, NVM_CODE) NvM_ReadAll(void);
/* Initiates a multi block write request */
extern FUNC(void, NVM_CODE) NvM_WriteAll(void);
/* Service to cancel a running NvM_WriteAll request. */
extern FUNC(void, NVM_CODE) NvM_CancelWriteAll(void);
/* Service for resetting all internal variables. */
extern FUNC(void, NVM_CODE) NvM_Init
(
    P2CONST(NvM_ConfigType, AUTOMATIC, NVM_APPL_CONST) ConfigPtr
);

/* Service for performing the processing of the NvM jobs. */
/* PolySpace +1 MISRA-C3:8.5 [Justified:Unset] "NSCA_Polyspace_NvM_8.5" */
extern FUNC(void, NVM_CODE) NvM_MainFunction(void);

/* PolySpace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_NvM_20.9" */
#if (NVM_VERSION_INFO_API == STD_ON)
/* Service to get the version information of the NvM module. */
extern FUNC(void, NVM_CODE) NvM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_DATA) versioninfo
);
#endif

/* PolySpace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_NvM_20.9" */
#if( NVM_STOP_SERVICES == STD_ON )
/* Service to read, write, erase and other operations cannot be performed or
   can be performed,When NvM_SetBlockServices is called. */
extern FUNC(void, NVM_CODE) NvM_SetBlockServices(boolean stopServices);
/* Service to get flag whether can write/read/erase to Pflash. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_GetFeeOfQueueStatus
(
    P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
);
#endif

#define NVM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* NVM_H_ */
