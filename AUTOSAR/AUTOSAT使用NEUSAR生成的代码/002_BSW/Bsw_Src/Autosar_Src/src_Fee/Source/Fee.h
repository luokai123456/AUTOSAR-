/*
********************************************************************************
*
* File name: Fee.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.12.12
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangJipeng/2019.04.12
* Change: V2.0 release.
* Cause: Update
********************************************************************************
* Version: 1.2
* Author/Date: WangJipeng/2019.04.23
* Change: Revision of code review issues.
* Cause: Revision
********************************************************************************
* Version: 1.3
* Author/Date: WangJipeng/2019.04.23
* Change: Revision of Fee code review issues.
* Cause: Revision
********************************************************************************
* Version: 1.4
* Author/Date: WangJipeng/2019.05.21
* Change: Change the Module ID and Vendor ID.
* Cause: Optimization
********************************************************************************
* Version: 2.0
* Author/Date: WangHe/2019.11.8
* Change: Delete NVM function Statement.
* Cause: Optimization
********************************************************************************
* Version: 2.1
* Author/Date: WangHe/2019.11.22
* Change: Format modification.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: Hanbaiyu/2020.05.07
* Change: 1. Modify the major version number.
* Cause: Update to 3.0.
********************************************************************************
* Version: 3.1
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
* Cause: Optimization.
********************************************************************************
* Version: 3.2
* Author/Date: HanBY/2020.11.04
* Change: Deleting memrory maps for variable or function declarations.
* Cause: Optimization.
********************************************************************************
* Version: 3.3
* Author/Date: HanBY/2021.11.01
* Change: Update the patch version.
* Cause: Update.
********************************************************************************
* Version: 3.4
* Author/Date: HanBY/2022.04.26
* Change: 1. Delete the menu type Fee_JobType_en.
*         2. Add the macro FEE_DIVIDE_4.
*         3. Delete the macro FEE_DEFAULT_VALUE.
* Cause: Optimization.
********************************************************************************
* Version: 3.5
* Author/Date: LiDY/2022.10.26
* Change: Optimized lastsector size calculation and Update the patch version
*         because add the limit of scanning blockhead.
* Cause: Bugfix.
********************************************************************************
* Version: 3.6
* Author/Date: LiDY/2022.11.03
* Change: Update the patch version.
* Cause: Update.
********************************************************************************
* Version: 3.7
* Author/Date: LiDY/2022.11.17
* Change: Update the patch version.
* Cause: Update.
********************************************************************************
* Version: 3.8
* Author/Date: LiDY/2022.12.14
* Change: Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiDY/2023.05.08
* Change: Add definition of FEE_BUFFER_VALUE.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: LiDY/2023.05.17
* Change: Update the version to 3.7.0.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: GaoXY/2023.05.26
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: WangLX/2023.09.25
* Change: Update the minor version, update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: WangLX/2023.11.02
* Change: Fix Compilation Warning.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: LiDaY/2024.01.15
* Change: 1.Update the minor version, update REVISION version.
*         2.Add FEE_MEMCPY FEE_VALUE_TWO FEE_VALUE_FF FEE_SWAP_READ_ERROR macro
*           definition.
*         3.Move out FEE_SECTOR_SWAP_OFF FEE_SECTOR_SWAP_ON.
*         4.Add Fee_SetModuleMode Fee_GetModuleStopState Fee_GetEraseCount API
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: LiDaY/2024.04.08
* Change: 1.Add FEE_TIMER_DELAY FEE_ACTIVE_DELAY macro definition.
*         2.Update the minor version, update REVISION version.
*         3.Add a memory-map label to function and variable declarations.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: LiDaY/2024.07.24
* Change: 1.Add macro definition FEELEFT_SHIFT-8BIT FEE_LEFT_SHIFT_16BIT,
*           FEE_LEFT_SHIFT_24BIT, FEE_LENGTH_SIZE_16BYTE,FEE_REMAIN_4_MASK,
*           FEE_12BYTE, FEE_SECTOR_WRITE_FAILED_NUM.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: LiDaY/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: LiDaY/2024.11.05
* Change: Update the minor version, update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: LiDaY/2025.02.18
* Change: Optimize header file references.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: WangLX/2025.02.18
* Change: 1.Add the value of sector tail id.
*         2.Update the minor version, update REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: LiDaY/2025.03.28
* Change: 1.Add QAC, PolySpace warning analysis results.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: Chixp/2025.04.29
* Change: 1.Add the external declaration of the Fee_SetSectorLastSizeToZero function.
*         2.Update the FEE_SW_MINOR_VERSION to 14 and the FEE_SW_REVISION_VERSION to 7.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: Chixp/2025.05.13
* Change: Update the FEE_SW_REVISION_VERSION to 8.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: Chixp/2025.06.05
* Change: 1.Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
*         2.Update the FEE_SW_REVISION_VERSION to 9.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: Chixp/2025.06.16
* Change: Update software version to 3.14.0.10.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: Chixp/2025.06.18
* Change: Update software version to 3.14.0.11.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: Chixp/2025.06.23
* Change: 1.Update the polyspace deviation suppression comment.
*         2.Update software version to 3.14.0.12.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: Chixp/2025.08.04
* Change: Update software version to 3.15.0.13.
* Cause: Update
********************************************************************************
*/
#ifndef FEE_H_
#define FEE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Fee_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* MemIf Version */
#define FEE_VENDOR_ID                       (119U)
#define FEE_MODULE_ID                       (21U)
#define FEE_SW_MAJOR_VERSION                (3U)
#define FEE_SW_MINOR_VERSION                (15U)
#define FEE_SW_PATCH_VERSION                (0U)
#define FEE_SW_REVISION_VERSION             (13U)
#define FEE_AR_RELEASE_MAJOR_VERSION        (4U)
#define FEE_AR_RELEASE_MINOR_VERSION        (2U)
#define FEE_AR_RELEASE_REVISION_VERSION     (2U)

/* FEE instance ID for Det */
#define FEE_INSTANCE_ID                     (0x00U)

/* FEE ServiceID */
#define FEE_INIT                            (0x00U)
#define FEE_SET_MODE                        (0x01U)
#define FEE_READ                            (0x02U)
#define FEE_WRITE                           (0x03U)
#define FEE_CANCEL                          (0x04U)
#define FEE_GET_STATUS                      (0x05U)
#define FEE_GET_JOB_RESULT                  (0x06U)
#define FEE_INVALIDATE_BLOCK                (0x07U)
#define FEE_GET_VERSION_INFO                (0x08U)
#define FEE_ERASE_IMMEDIATE_BLOCK           (0x09U)
#define FEE_JOB_END_NOTIFICATION            (0x10U)
#define FEE_JOB_ERROR_NOTIFICATION          (0x11U)
#define FEE_JOB_MAIN_FUNCTION               (0x12U)

/* FEE Development Errors. */
/* No error. */
#define FEE_E_NO_ERR                        (0x00U)
/* API service called when module was not initialized. */
#define FEE_E_UNINIT                        (0x01U)
/* API service called with invalid block number. */
#define FEE_E_INVALID_BLOCK_NO              (0x02U)
/* API service called with invalid block offset. */
#define FEE_E_INVALID_BLOCK_OFS             (0x03U)
/* API service called with invalid data pointer. */
#define FEE_E_PARAM_POINTER                 (0x04U)
/* API service called with invalid length information. */
#define FEE_E_INVALID_BLOCK_LEN             (0x05U)
/* API service called while module is busy processing a user request. */
#define FEE_E_BUSY                          (0x06U)
/* Fee_Cancel called while no job was pending. */
#define FEE_E_INVALID_CANCEL                (0x08U)
/* Fee_Init failed. */
#define FEE_E_INIT_FAILED                   (0x09U)

/* Reserved block number. */
#define FEE_BLOCK_NUMBER_RESERVED           (0U)
/* The value of zero */
#define FEE_VALUE_ZERO                      (0U)
/* The value of one */
#define FEE_VALUE_ONE                       (1U)
/* The value of two */
#define FEE_VALUE_TWO                       (2U)
/* The default value of partition number */
#define FEE_VALUE_FF                        (0xFFU)
/* The default value of block number */
#define FEE_DEFAULT_VALUE_BLOCK             (0xFFFFU)
/* The default value of valid flag */
#define FEE_DEFAULT_VALID_ID                (0xFFFFFFFFU)
/* The value of valid id */
#define FEE_VALID_ID                        (0x12345678U)
/* The value of invalid id */
#define FEE_INVALID_ID                      (0x87654321U)
/* The value of sector tail id */
#define FEE_SECTOR_TAIL_ID                  (0x14785293U)
/* The result is valid */
#define FEE_VALID_TURE                      (1U)
/* The result is invalid */
#define FEE_VALID_FALSE                     (0U)
/* Found bad block */
#define FEE_BAD_BLOCK                       (1U)
/* Breaking the process */
#define FEE_BREAK_FLAG                      (1U)
/* Sector can be used normally */
#define FEE_SECTOR_NORMAL_STATE             (0U)
/* Sector is erased */
#define FEE_SECTOR_ERASE_STATE              (1U)
/* Turn off sector erase operation */
#define FEE_SECTOR_ERASE_OFF                (0U)
/* Turn on sector erase operation */
#define FEE_SECTOR_ERASE_ON                 (1U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/* Delay time configuration of Fee timer */
#define FEE_TIMER_DELAY                     (10U)
/* Immdiate Write delay time configuration of Fee timer */
#define FEE_IMM_WRITE_TIMER_DELAY           (20U)
/* Divide into 4. */
#define FEE_DIVIDE_4                        (4U)
/* dummy operation */
/* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define FEE_DUMMY_STATEMENT(v)              (v)=(v)
/* The Critical Value. */
#define FEE_CRITICAL_VALUE                  (0U)
/* Optimized lastsector size calculation. */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Fee_Sublmt(A,B)                     ((A) < (B) )? FEE_CRITICAL_VALUE:((A) - (B))
/* The value of buffer */
#define FEE_BUFFER_VALUE                    (0x55555555U)
/* The value of buffer */
#define FEE_SWAP_READ_ERROR                 (0x77777777U)
/* Memcpy API */
/* polyspace +1 MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define FEE_MEMCPY(src, des, length)        Fee_MemCpy(src, des, length)
/* Number of delay cycles for activating Sector after power on scanning */
#define FEE_ACTIVE_DELAY                    (0x800U)
/* Bitwise operation usage */
#define FEE_LEFT_SHIFT_8BIT                 (8U)
#define FEE_LEFT_SHIFT_16BIT                (16U)
#define FEE_LEFT_SHIFT_24BIT                (24U)
#define FEE_LENGTH_SIZE_16BYTE              (16U)
#define FEE_REMAIN_4_MASK                   (3U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define FEE_12BYTE                          (12U)
#define FEE_SECTOR_WRITE_FAILED_NUM         (5U)

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
#define FEE_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern CONST(Fee_PartitionCfgType, FEE_CONFIG_DATA) Fee_PartitionCfg;

#define FEE_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define FEE_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern FUNC(void, FEE_CODE) Fee_Init
(
    P2CONST(Fee_ConfigType, AUTOMATIC, FEE_APPL_CONST) ConfigPtr
);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
extern FUNC(void, FEE_CODE) Fee_SetMode(MemIf_ModeType Mode);
extern FUNC(Std_ReturnType, FEE_CODE) Fee_Read
(
    uint16 BlockNumber,
    uint16 BlockOffset,
    P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) DataBufferPtr,
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 Length
);
extern FUNC(Std_ReturnType, FEE_CODE) Fee_Write
(
    uint16 BlockNumber,
    P2CONST(uint8, AUTOMATIC, FEE_APPL_CONST) DataBufferPtr
);
extern FUNC(void, FEE_CODE) Fee_Cancel(void);
extern FUNC(MemIf_StatusType, FEE_CODE) Fee_GetStatus(void);
extern FUNC(MemIf_JobResultType, FEE_CODE) Fee_GetJobResult(void);
extern FUNC(Std_ReturnType, FEE_CODE) Fee_InvalidateBlock(uint16 BlockNumber);
extern FUNC(Std_ReturnType, FEE_CODE) Fee_EraseImmediateBlock(uint16 BlockNumber);
extern FUNC(void, FEE_CODE) Fee_MainFunction(void);
extern FUNC(void, FEE_CODE) Fee_SetModuleMode(boolean stopServices);
extern FUNC(Std_ReturnType, FEE_CODE) Fee_GetModuleStopState(void);
extern FUNC(uint32, FEE_CODE) Fee_GetEraseCount(void);

#if( FEE_VERSION_INFO_API == STD_ON )
extern FUNC(void, FEE_CODE) Fee_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA) VersionInfoPtr
);
#endif /* FEE_VERSION_INFO_API == STD_ON. */

extern FUNC(Std_ReturnType, FEE_CODE) Fee_SetSectorLastSizeToZero(void);
#define FEE_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* FEE_H_ */

