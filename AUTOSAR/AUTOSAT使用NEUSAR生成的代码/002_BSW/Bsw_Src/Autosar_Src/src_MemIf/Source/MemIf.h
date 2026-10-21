/*
********************************************************************************
*
* File name: MemIf.h
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
* Author/Date: TongQian/2019.05.07
* Change: Add serviceID macro definition.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date:liuziyang/2020.03.27
* Change: Only version update to V3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: HanBY/2020.11.04
* Change: Deleting memrory maps for variable or function declarations.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: HanBY/2021.03.19
* Change: Add precompile switch for header file to eliminate the problem of manual
*         annotation unused header file.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: HanBY/2021.11.01
* Change: Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: GaoXY/2023.05.17
* Change: Update the version to 370.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: GaoXY/2023.05.26
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: WangLX/2023.10.30
* Change: Update the minor version, update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: WangLX/2024.04.25
* Change: 1.Add a memory-map label to function and variable declarations.
*         2.Update the minor version, update REVISION version.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: WangLX/2025.03.31
* Change: 1.Fix QAC and Polyspace warnings and add analysis results.
*         2.Updata Minor Version and Revision Version.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: Chixp/2025.06.05
* Change: 1.Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
*         2.Update the MEMIF_SW_MINOR_VERSION to 14 and the MEMIF_SW_REVISION_VERSION to 4.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: Chixp/2025.06.23
* Change: 1.Update the polyspace deviation suppression comment.
*         2.Update the MEMIF_SW_REVISION_VERSION to 5.
* Cause: Update
********************************************************************************
*/
#ifndef MEMIF_H_
#define MEMIF_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "MemIf_Cfg.h"

#if( MEMIF_EA_ENABLE == STD_ON )
#include "Ea.h"
#endif

#if( MEMIF_FEE_ENABLE == STD_ON )
#include "Fee.h"
#endif

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* MemIf Version. */
#define MEMIF_VENDOR_ID                              (119U)
#define MEMIF_MODULE_ID                              (22U)
#define MEMIF_SW_MAJOR_VERSION                       (3U)
#define MEMIF_SW_MINOR_VERSION                       (14U)
#define MEMIF_SW_PATCH_VERSION                       (0U)
#define MEMIF_SW_REVISION_VERSION                    (5U)
#define MEMIF_AR_RELEASE_MAJOR_VERSION               (4U)
#define MEMIF_AR_RELEASE_MINOR_VERSION               (2U)
#define MEMIF_AR_RELEASE_REVISION_VERSION            (2U)

/* MemIf instance ID for Det. */
#define MEMIF_INSTANCE_ID                            (0x00U)

/* MemIf ServiceID. */
#define MEMIF_SET_MODE                               (0x00U)
#define MEMIF_READ                                   (0x01U)
#define MEMIF_WRITE                                  (0x02U)
#define MEMIF_CANCEL                                 (0x03U)
#define MEMIF_GET_STATUS                             (0x04U)
#define MEMIF_GET_JOB_RESULT                         (0x05U)
#define MEMIF_INVALIDATE_BLOCK                       (0x06U)
#define MEMIF_ERASE_IMMEDIATE_BLOCK                  (0x07U)
#define MEMIF_GET_VERSION_INFO                       (0x08U)

/* MemIf Development Errors. */
#define MEMIF_E_NO_ERR                               (0x00U)

/* MemIf denoting a broadcast to all configured devices. */
#define MEMIF_BROADCAST_ID                           (0xFFU)

/* MemIf value at index initialization. */
#define MEMIF_INIT_0                                 (0U)

/* MemIf store each status. */
#define STORE_EACH_STATUS                            (1U)

/* MemIf Initial value of MemIf_StatusMask. */
#define MEMIF_MASK_INITIAL_VALUE                     (0U)

/* MemIf determine the state of underlying memory Abstract modules. */
#define DETERMINE_STATE_VALUE                        (0U)

/* MemIf total number of DEVICES. */
#define NUMBER_OF_DEVICES_TOTAL                      (2U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

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
#define MEMIF_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "MemIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_MemIf_Dir4.5" */
extern FUNC(void, MEMIF_CODE) MemIf_SetMode(MemIf_ModeType Mode);
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read
(
    uint8 DeviceIndex,
    uint16 BlockNumber,
    uint16 BlockOffset,
    P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_MemIf_Dir4.5" */
    uint16 Length
);
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write
(
    uint8 DeviceIndex,
    uint16 BlockNumber,
    P2CONST(uint8, AUTOMATIC, MEMIF_APPL_CONST) DataBufferPtr
);
extern FUNC(void, MEMIF_CODE) MemIf_Cancel(uint8 DeviceIndex);
extern FUNC(MemIf_StatusType, MEMIF_CODE) MemIf_GetStatus(uint8 DeviceIndex);
extern FUNC(MemIf_JobResultType, MEMIF_CODE) MemIf_GetJobResult(uint8 DeviceIndex);
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_InvalidateBlock
(
    uint8 DeviceIndex,
    uint16 BlockNumber
);
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_EraseImmediateBlock
(
    uint8 DeviceIndex,
    uint16 BlockNumber
);
extern FUNC(void, MEMIF_CODE) MemIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, MEMIF_APPL_DATA) VersionInfoPtr
);

#define MEMIF_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "MemIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* MEMIF_H_ */
