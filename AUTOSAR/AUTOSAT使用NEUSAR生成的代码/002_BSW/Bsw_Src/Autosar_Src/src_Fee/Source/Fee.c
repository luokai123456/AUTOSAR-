/*
********************************************************************************
*
* File name: Fee.c
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
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangJipeng/2019.04.12
* Change: To improve the V1.0 legacy functions.
* Cause: Update
********************************************************************************
* Version: 1.2
* Author/Date: WangJipeng/2019.04.23
* Change: Modify variable naming from FEE_Init_Finish to Fee_Init_Finish.
* Cause: Optimize
********************************************************************************
* Version: 1.3
* Author/Date: WangJipeng/2019.04.23
* Change: Revision of code review issues.
* Cause: Revision
********************************************************************************
* Version: 1.4
* Author/Date: WangJipeng/2019.04.23
* Change: Modify QAC Check Warning.
* Cause: Revision
********************************************************************************
* Version: 1.5
* Author/Date: WangJipeng/2019.04.23
* Change: Revision of Fee code review issues.
* Cause: Revision
********************************************************************************
* Version: 1.6
* Author/Date: WangJipeng/2019.05.05
* Change: Add internal function declaration.
* Cause: Optimization
********************************************************************************
* Version: 1.7
* Author/Date: WangJipeng/2019.05.05
* Change: Change the using of DET report function of functionFee_GetVersionInfo.
* Cause: Bugfix
********************************************************************************
* Version: 1.8
* Author/Date: WangJipeng/2019.05.06
* Change: Modify the calculation address error of Fee_GetBlockAdminiAddress.
* Cause: Bugfix
********************************************************************************
* Version: 2.0
* Author/Date: WangJipeng/2019.05.21
* Change: Repair function Fee_ChkReadCondition offset and length check error.
* Cause: Bugfix
********************************************************************************
* Version: 2.1
* Author/Date: WangHe/2019.11.8
* Change: FLS module function is controled by USE_FLS_MODULE
* Cause: Bugfix
********************************************************************************
* Version: 2.2
* Author/Date: WangHe/2019.11.18
* Change: FLS module function is controled by USE_FLS_MODULE and EA_POLLING_MOD
* is Changed by FEE_POLLING_MODE.
* Cause: Bugfix
********************************************************************************
* Version: 2.3
* Author/Date: WangHe/2019.11.22
* Change: Local variables are defined by hump standard and format modification.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: Hanbaiyu/2020.03.27
* Change: Use macro definition replace number.
* Cause: QAC
********************************************************************************
* Version: 3.1
* Author/Date: Baowanglong/2020.05.07
* Change: 1. Added internal management information
*         2. Added consistency information.
*         3. Added initial scan block operation.
*         4. Added data swap operations.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: Hanbaiyu/2020.05.29
* Change: In Fee_MainFunction, modify the callback notification to NvM.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: Hanbaiyu/2020.06.28
* Change: 1. Add the function Fee_ChkBlockImmediate to judge whether the block have
*         an immediate priority.
*         2. Modify the entry conditions of read/write/swap operation, to prevent
*         the current operation from being affected when the previous step fails.
*         3. Add global flag variable Fee_ClearStaticVariable to clear the static
*         variables when first enter a function.
*         4. Move the operation that update the data address of the current sector
*         to write data success.
*         5. Swap operation not allowed to be cancelled.
*         6. Add the entry condition of callback functions Fee_JobEndNotification
*         and Fee_JobErrorNotification.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
* Cause: Optimization.
********************************************************************************
* Version: 3.5
* Author/Date: Hanbaiyu/2020.10.27
* Change: Delete redundant assignments.
* Cause: QAC.
********************************************************************************
* Version: 3.6
* Author/Date: HanBY/2020.11.02
* Change: Modify code format.
* Cause: Optimization.
********************************************************************************
* Version: 3.7
* Author/Date: HanBY/2020.11.04
* Change: Deleting memory maps for variable or function declarations.
* Cause: Optimization.
********************************************************************************
* Version: 3.8
* Author/Date: HanBY/2020.11.09
* Change: 1. Modify the judge condition of null pointer in Fee_MemCpy.
*         2. Add the precompile of Det.h.
* Cause: Optimization.
********************************************************************************
* Version: 3.9
* Author/Date: HanBY/2020.12.03
* Change: In swap job, modify the step to update the check sum to avoid generate
*         error value.
* Cause: Bugfix.
********************************************************************************
* Version: 3.10
* Author/Date: HanBY/2020.12.04
* Change: Modify some variable types from uint32 to uint16 to eliminat implicit
*         type conversions.
* Cause: QAC.
********************************************************************************
* Version: 3.11
* Author/Date: HanBY/2021.04.27
* Change: Modify the logic of Fee_Cancel to prevent the Fee Internal operation to
*         be cancelled.
* Cause: Bugfix.
********************************************************************************
* Version: 3.12
* Author/Date: HanBY/2021.06.21
* Change: Modify the logic of the function Fee_ScanBlockProc to avoid the array
*         out of bounds when reading wrong block number.
* Cause: Bugfix.
********************************************************************************
* Version: 3.13
* Author/Date: HanBY/2021.06.30
* Change: Modify titles of function Fee_SwapWritedBlockData, Fee_JobWritedBlockUnvld,
*         Fee_InvalidateJob.
* Cause: Optimization.
********************************************************************************
* Version: 3.14
* Author/Date: HanBY/2021.10.27
* Change: Delete the header Fee_MemMap.h.
* Cause: Optimization.
********************************************************************************
* Version: 3.15
* Author/Date: HanBY/2022.04.26
* Change: 1. Modify the type of Fee_InterBuffer from uint8 to uint32 to fit mcal.
*         2. Modify the way of call the function of mcal fls module.
* Cause: Optimization.
********************************************************************************
* Version: 3.16
* Author/Date: LiK/2022.08.15
* Change: Fee_Det_ErrorReport API add macro switch.
* Cause: Bugfix.
********************************************************************************
* Version: 3.17
* Author/Date: LiDY/2022.10.26
* Change: Add the scan sector stop condition and Optimized lastsector size calculation.
* Cause: Bugfix.
********************************************************************************
* Version: 3.18
* Author/Date: LiDY/2022.11.03
* Change: Delete redundant semicolon.
* Cause: Bugfix.
********************************************************************************
* Version: 3.19
* Author/Date: LiDY/2022.11.17
* Change: Quit scanning when scanning invalid sectors.
* Cause: Bugfix.
********************************************************************************
* Version: 3.20
* Author/Date: LiDY/2022.12.14
* Change: Change FEE_BlOCK_NUMBER to FEE_BLOCK_NUMBER.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: GaoXY/2023.03.16
* Change: 1.Back up block head and sector head.
*         2.Recover block head and sector head,when Fls driver return Failed.
* Cause: Bugfix.
********************************************************************************
* Version: 3.22
* Author/Date: GaoXY/2023.3.21
* Change: Change FEE_BlOCK_NUMBER to FEE_BLOCK_NUMBER.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: ZhangXL/2023.08.03
* Change: Resolve Compile warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: WangLX/2023.08.23
* Change: Adding memclass to static variables in static code.
* Cause: Bugfix.
********************************************************************************
* Version: 3.25
* Author/Date: WangLX/2023.09.20
* Change: Modify the condition for stopping retry of the
*         Fee_ScanReadBlockHeadRetry function.
* Cause: Bugfix.
********************************************************************************
* Version: 3.26
* Author/Date: WangLX/2023.09.25
* Change: Adding conditions to exit scanning in the Fee_ScanBlockProcRetry
*         function.
* Cause: Bugfix.
********************************************************************************
* Version: 3.27
* Author/Date: LiDaY/2023.09.26
* Change: Add MemAcc Support.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: WangLX/2023.11.01
* Change: Change the type of secBuffersize from uint8 to uint16.
* Cause: Bugfix
********************************************************************************
* Version: 3.29
* Author/Date: WangLX/2023.11.02
* Change: Fix Compilation Warning.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: WangLX/2023.12.06
* Change: Add zeroing to Fee_ScanBlockProcRetry function for Fee_RetryCounter.
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: WangLX/2023.12.07
* Change: Modify Fee_BlockHeadAligned in the Fee_SwapPartition function
*         to Fee_SectorHeadAligned.
* Cause: Bugfix
********************************************************************************
* Version: 3.32
* Author/Date: LiDaY/2024.01.15
* Change: Add Fee multisector and bad sector manage support.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: LiDaY/2024.01.15
* Change: Remove ScanManagerInfo.ScanReadLen=FEE_Value_ZERO from Fee_Init().
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: LiDaY/2024.01.16
* Change: When scanning all sectors with data, erase the data of the largest
*         sector for rescanning and Immediate swaping.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: LiDaY/2024.02.02
* Change: 1.Modifying state machine processing for FLS pending timeout.
*         2.Add Fee_SwapClearStaticVariable Fee_SwapReadBlockRemainLenTemp
*           Fee_SwapReadBlockAddrTemp for use during swap read exception.
*         3.Replace FEE_SECTOR_NUMBER with Fee_PartitionCfg.SectorTotalNum in
*           FeeBadSectorProc.
*         4.Replace Fee_SectorHead_Dyn->SectorCounter with
*           Fee_SectorHead_Dyn->ValidFlag in Fee_GetEraseCount.
* Cause: Bugfix
********************************************************************************
* Version: 3.36
* Author/Date: LiDaY/2024.02.20
* Change: After Fee Scan ends, set the module status to IDLE
* Cause: Bugfix
********************************************************************************
* Version: 3.37
* Author/Date: LiDaY/2024.03.13
* Change: 1.Fix Compilation Warning.
*         2.Replace the macro FEE_START_BUFFER_VAR_INIT with
*           FEE_START_SEC_VAR_INIT_32.
* Cause: Optimization
********************************************************************************
* Version: 3.38
* Author/Date: LiDaY/2024.04.08
* Change: 1.Add immediately Write.
*         2.Add a memory-map label to function and variable declarations.
*         3.Self erasing during idle period of invalid sectors after power on.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: LiDaY/2024.07.24
* Change: 1.Optimize the Scan process to minimize scanning time.
*         2.Remove redundant code and optimize the usage of Rom and Ram.
*         3.To adapt to the scan logic, if the block head fails or is cancelled
*           five times in a row in the same sector, the sector needs to be switched.
*         4.Remove Fee_SwapInterBuffer and modify it to share Fee_SwapInterBuffer
*           with swap and user requests; Change Fee_SlockHeadInfoBackUp to
*           Fee_SlockHeadAddrBackUp, and change its type from Fee_SlockHeadType
*           to uint32.
* Cause: Update
********************************************************************************
* Version: 3.40
* Author/Date: LiDaY/2024.08.07
* Change: 1.Add processing logic for canceling block head data writing in Fee_Cancel.
* Cause: Update
********************************************************************************
* Version: 3.41
* Author/Date: LiDaY/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.42
* Author/Date: LiDaY/2024.9.10
* Change: 1.Set "noActiveSectors" to FALSE in "Fee_Init" function.
*         2.When Fls pending timeout occurs during the Scan phase,
*           FeenModuleState does not change to IDLE.
*         3.When Scan Done, do not set FeenModuleState to IDLE if it is not equal
*           to MEMIF_SUSY1 INTERNAL.
* Cause: Bugfix
********************************************************************************
* Version: 3.43
* Author/Date: LiDaY/2024.9.14
* Change: Optimized scan time.
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: LiDaY/2024.10.12
* Change: Change the variable label of Fee_PartitionInfo from FEE_VAR_INIT to
*         FEE_VAR_NO_INIT.
* Cause: Bugfix
********************************************************************************
* Version: 3.45
* Author/Date: LiDaY/2024.10.31
* Change: 1.Temporary solution compatible with P9 version code.
*         2.Resolve compilation warnings.
*         3.Update the ValidFlag in the block dynamic information of the
*           Fee_JobWriteBlockDone function with the ValidFlag value of the
*           temporary block information.
*         4.Update the boundary check for reading sector data when scanning Block
*           Head.
* Cause: Bugfix
********************************************************************************
* Version: 3.46
* Author/Date: LiDaY/2025.02.18
* Change: Optimize header file references.
* Cause: Optimization
********************************************************************************
* Version: 3.47
* Author/Date: WangLX/2025.02.18
* Change: Update sector scanning process.
* Cause: Update
********************************************************************************
* Version: 3.48
* Author/Date: WangLX/2025.03.04
* Change: Add macro definition to control the scanning of sector tails.
* Cause: Update
********************************************************************************
* Version: 3.49
* Author/Date: WangLX/2025.03.26
* Change: 1.Modify the self adding logic of SectionFreeNum when processing
*           sector tails.
*         2.FEE_SCAN_SECTOR_TAIL macro control range correction.
* Cause: Bugfix
********************************************************************************
* Version: 3.50
* Author/Date: LiDaY/2025.03.28
* Change: 1.Add QAC, PolySpace warning analysis results.
*         2.Modify Det to only perform checks and not upload exceptions when Det
*           cannot be opened.
* Cause: Update
********************************************************************************
* Version: 3.51
* Author/Date: Chixp/2025.04.29
* Change: Add a new function that forcibly triggers page swap.
* Cause: Update
********************************************************************************
* Version: 3.52
* Author/Date: Chixp/2025.05.13
* Change: Modify the conditions for establishing the sector tail and add the situation
*         where the FLS driver fails during the writing of the sector head.
* Cause: Bugfix
********************************************************************************
* Version: 3.53
* Author/Date: Chixp/2025.06.05
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
* Version: 3.54
* Author/Date: Chixp/2025.06.16
* Change: Fix the bug where the configured number of failures does not match the
*         actual number of failures.
* Cause: Bugfix
********************************************************************************
* Version: 3.55
* Author/Date: Chixp/2025.06.18
* Change: Update the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.56
* Author/Date: Chixp/2025.06.23
* Change: Update the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Fee_Cbk.h"

#if( FEE_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
#define FEE_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Fee module state. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Fee_UsedNonSharedVariable" */
static VAR(MemIf_StatusType, FEE_VAR_INIT) Fee_ModuleState = MEMIF_UNINIT;
/* Fee module state. */
/* polyspace-begin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Fee_UnusedVariable" */
static VAR(MemIf_StatusType, FEE_VAR_INIT) Fee_ModuleNextState = MEMIF_UNINIT;
/* Fee Internal variable clear flag for job process. */
static VAR(boolean, FEE_VAR_INIT) Fee_ClearStaticVariable = FALSE;
/* Fee Internal variable clear flag for swap process. */
static VAR(boolean, FEE_VAR_INIT) Fee_SwapClearStaticVariable = FALSE;
/* The number of erased data scanned by the current sector. */
static VAR(uint8, FEE_VAR_INIT) Fee_SectorEarseDataCoutner = FEE_VALUE_ZERO;
/* Number of sectors that need to be scanned. */
/* polyspace-begin MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Fee_Rule8.9" */
static VAR(uint8, FEE_VAR_INIT) Fee_SectorScanNum = FEE_VALUE_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Fee_Rule8.9 */
/* The index of the sector with the largest sector counter in the scanned sector. */
static VAR(uint8, FEE_VAR_INIT) Fee_SectorMaxCounterIndex = FEE_VALUE_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Fee_Rule8.9 */
/* When Fee_SwapBlcokHeadFailedUpdate is False, it indicates that he entered the stage of reading BLCOK data after
   changing pages and writing the BLCOK header. */
static VAR(boolean, FEE_VAR_INIT) Fee_SwapBlcokHeadFailedUpdate = TRUE;
/* Activation delay time after scan ends. */
static VAR(uint32, FEE_VAR_INIT) Fee_ActiveDelay = FEE_VALUE_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Fee_Rule8.9 */
/* The length of head block without vaild flag. */
static VAR(uint8, FEE_VAR_INIT) Fee_WithoutValidFlag = FEE_VALUE_ZERO;
/* The alignment length of the head block without the valid flag. */
static VAR(uint32, FEE_VAR_INIT) Fee_WithoutValidFlagAligned = FEE_VALUE_ZERO;
/* The length of the checksum required for the head block. */
static VAR(uint8, FEE_VAR_INIT) Fee_CalcuCheckSumLen = FEE_VALUE_ZERO;
/* The head block does not include the alignment length of the valid flag, plus the length of the valid flag. */
static VAR(uint32, FEE_VAR_INIT) Fee_BlockValidEndLen = FEE_VALUE_ZERO;

#if( FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON )
/* Used to record how many older versions of Sector headers have been read. */
static VAR(uint8, FEE_VAR_INIT) Fee_LegacySectorHeadNum = FEE_VALUE_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Fee_Rule8.9 */
#endif /* FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON */

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
/* For use during swap read exception to backup read block remainLen. */
static VAR(uint16, FEE_VAR_INIT) Fee_SwapReadBlockRemainLenTemp = FEE_VALUE_ZERO;
/* For use during swap read exception to backup read block addr. */
static VAR(uint32, FEE_VAR_INIT) Fee_SwapReadBlockAddrTemp = FEE_VALUE_ZERO;
/* Number of retries under abnormal conditions. */
static VAR(uint8, FEE_VAR_INIT) Fee_BuildSectorRetryCounter = FEE_VALUE_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Fee_Rule8.9 */
static VAR(uint8, FEE_VAR_INIT) Fee_SwapBlockRetryWriteCounter = FEE_VALUE_ZERO;
static VAR(uint8, FEE_VAR_INIT) Fee_SwapBlockRetryEraseCounter = FEE_VALUE_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Fee_Rule8.9 */
static VAR(uint8, FEE_VAR_INIT) Fee_SwapBlockRetryReadCounter = FEE_VALUE_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Fee_Rule8.9 */
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

#if( FEE_FLS_PENDING_TIMEOUT_COUNT > FEE_VALUE_ZERO )
/* Fls job result pending timeout counter. */
static VAR(uint16, FEE_VAR_INIT) Fee_TimeoutCounter = FEE_VALUE_ZERO;  /* PRQA S 3218 */ /* NSCA_QAC_Fee_Rule8.9 */
#endif /* ( FEE_FLS_PENDING_TIMEOUT_COUNT > FEE_VALUE_ZERO ) */
/* polyspace-end MISRA-C3:8.9 [Justified:Unset] "NSCA_Polyspace_Fee_Rule8.9" */

#if( (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) )
/* Fls job result notification flag. */
static VAR(boolean, FEE_VAR_INIT) Fee_Notification = FALSE;
#endif /* (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) */

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
static VAR(uint8, FEE_VAR_INIT) Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */
/* polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Fee_UnusedVariable" */

#define FEE_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define FEE_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* The current partiton information being processed. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Fee_UsedNonSharedVariable" */
volatile VAR(Fee_PartitionCurrentInfoType, FEE_VAR_NO_INIT) Fee_PartitionInfo;
/* Internal swap management data module. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Fee_UnusedVariable" */
volatile VAR(Fee_SwapManagerInfoType, FEE_VAR_NO_INIT) Fee_SwapManagerInfo;
/* Internal jobresult management data module. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Fee_UsedNonSharedVariable" */
static VAR(Fee_JobManagerInfoType, FEE_VAR_NO_INIT) Fee_JobManagerInfo;
/* Scan management data module. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Fee_UnusedVariable" */
volatile VAR(Fee_ScanManagerInfoType, FEE_VAR_NO_INIT) Fee_ScanManagerInfo;
/* Block Addr backup data. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Fee_UnusedVariable" */
static VAR(uint32, FEE_VAR_NO_INIT) Fee_BlockHeadAddrBackUp[FEE_BLOCK_NUMBER];

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define FEE_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define FEE_START_SEC_VAR_INIT_32
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Fee internal buffer. */
/* polyspace +1 MISRA-C3:12.1 [Justified:Unset] "NSCA_Polyspace_Fee_Rule12.1" polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Fee_UnusedVariable" */
static VAR(uint32, FEE_VAR_INIT) Fee_InterBuffer[FEE_WRITE_BUFFER_SIZE / FEE_DIVIDE_4 + FEE_VALUE_ONE] =
{ FEE_VALUE_ZERO };

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define FEE_STOP_SEC_VAR_INIT_32
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define FEE_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( FEE_DEV_ERROR_DETECT == STD_ON )
static FUNC(void, FEE_CODE) Fee_Det_ErrorReport(uint8 ApiId, uint8 ErrorId);
#endif

static FUNC(uint8, FEE_CODE) Fee_ChkGeneralCondition
(
    uint16 BlockIndex
);
static FUNC(uint32, FEE_CODE) Fee_CalcuAlignedLen(uint32 len);
static FUNC(void, FEE_CODE) Fee_MemCpy
(
    P2CONST(uint8, AUTOMATIC, FEE_APPL_CONST) SrcAddr,
    P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) DesAddr,
    uint16 length
);
static FUNC(uint16, FEE_CODE) Fee_SeekIndexFromNumber(uint16 blockNumber);
static FUNC(uint32, FEE_CODE) Fee_CheckSum
(
    P2CONST(uint8, AUTOMATIC, FEE_APPL_CONST) dataBuf,
    uint8 Length
);
static FUNC(uint32, FEE_CODE) Fee_CheckSumEraseData
(
    P2VAR(uint8, AUTOMATIC, FEE_APPL_CONST) BlockHdTmp,
    uint32 BlockHeadCheckSum
);
static FUNC(Std_ReturnType, FEE_CODE) Fee_ForwardGetSector
(
    Fee_SectorStatusType SectorState1,
    Fee_SectorStatusType SectorState2,
    P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) SectorIndex
);
static FUNC(Std_ReturnType, FEE_CODE) Fee_BackwardGetSector
(
    Fee_SectorStatusType SectorState1,
    Fee_SectorStatusType SectorState2,
    P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) SectorIndex
);
static FUNC(void, FEE_CODE) Fee_ScanCheckBlockHead
(
    uint16 BlockIndex,
    uint8 SectorIndex,
    P2CONST(Fee_BlockHeadRomType, AUTOMATIC, FEE_APPL_DATA) BlockHeadTmp,
    uint32 ValidFlag,
    uint32 CheckSum
);
static FUNC(void, FEE_CODE) Fee_ScanSectorBlockHeadEnd(uint8 SectorIndex);
static FUNC(void, FEE_CODE) Fee_UpdatePattitionInfo(uint8 SectorIndex);
static FUNC(void, FEE_CODE) Fee_ScanReadSectorHead(void);
static FUNC(void, FEE_CODE) Fee_ScanReadBlockHead(void);
static FUNC(void, FEE_CODE) Fee_ScanSectorProc(void);
static FUNC(void, FEE_CODE) Fee_ScanBlockProc(void);
static FUNC(void, FEE_CODE) Fee_ScanBlockProcRetry(void);
static FUNC(void, FEE_CODE) Fee_ScanReadBlockHeadRetry(void);
static FUNC(void, FEE_CODE) Fee_ScanDone(void);
static FUNC(void, FEE_CODE) Fee_ScanJob(void);
static FUNC(void, FEE_CODE) Fee_UpdateSwapRequest(void);
static FUNC(void, FEE_CODE) Fee_SwapWritedSectorHead(void);
static FUNC(void, FEE_CODE) Fee_SwapWritedSectorTail(void);
static FUNC(void, FEE_CODE) Fee_SwapReadData(void);
static FUNC(void, FEE_CODE) Fee_SwapWritedBlockHead(void);
static FUNC(void, FEE_CODE) Fee_SwapWritedBlockData(void);
static FUNC(void, FEE_CODE) Fee_SwapWritedBlockVld(void);
static FUNC(void, FEE_CODE) Fee_SwapBlockDone(void);
static FUNC(void, FEE_CODE) Fee_InternalErase(void);
static FUNC(void, FEE_CODE) Fee_InternalEraseDone(void);
static FUNC(void, FEE_CODE) Fee_InternalEraseJob(void);
static FUNC(void, FEE_CODE) Fee_JobWriteBlockHead(boolean validFlag);
static FUNC(void, FEE_CODE) Fee_JobWriteBlockData(void);
static FUNC(void, FEE_CODE) Fee_JobWriteBlockVld(void);
static FUNC(void, FEE_CODE) Fee_JobWriteBlockDone(void);
static FUNC(void, FEE_CODE) Fee_ReadJobRequest(void);
static FUNC(void, FEE_CODE) Fee_ReadJobDone(void);
static FUNC(void, FEE_CODE) Fee_SectorBuildHeadJob(void);
static FUNC(void, FEE_CODE) Fee_WriteJob(void);
static FUNC(void, FEE_CODE) Fee_ReadJob(void);
static FUNC(void, FEE_CODE) Fee_JobWritedBlockUnvld(void);
static FUNC(void, FEE_CODE) Fee_EraseJob(void);
static FUNC(void, FEE_CODE) Fee_InvalidateJob(void);
static FUNC(void, FEE_CODE) Fee_BadSectorProc(void);
static FUNC(void, FEE_CODE) Fee_InternalSwapEraseDone(void);
static FUNC(void, FEE_CODE) Fee_InternalSwapErase(void);
static FUNC(void, FEE_CODE) Fee_JobProcessStateMachine(void);
static FUNC(void, FEE_CODE) Fee_SwapProcess(void);
static FUNC(void, FEE_CODE) Fee_StateMachineSwitch(void);
static FUNC(void, FEE_CODE) Fee_SwapJobPause(void);
static FUNC(void, FEE_CODE) Fee_SwapStateMachine(void);
static FUNC(void, FEE_CODE) Fee_ScanCurrentSectorFinish(void);
static FUNC(void, FEE_CODE) Fee_CheckValidSector(void);
static FUNC(Std_ReturnType, FEE_CODE) Fee_GetSectorToScanBlock(void);
static FUNC(void, FEE_CODE) Fee_GetSwapSector(void);
static FUNC(void, FEE_CODE) Fee_SwapBlockJob(void);
static FUNC(void, FEE_CODE) Fee_SwapInternalEraseJob(void);
static FUNC(void, FEE_CODE) Fee_WritedSectorHeadDone(void);
static FUNC(void, FEE_CODE) Fee_ErrorDeal(void);
static FUNC(void, FEE_CODE) Fee_ChangePartintionSector(void);
static FUNC(void, FEE_CODE) Fee_SwapRetry(void);
static FUNC(Std_ReturnType, FEE_CODE) Fee_CheckWriteSpace(uint16 WriteLen);
static FUNC(Std_ReturnType, FEE_CODE) Fee_GetSwapBlocks(void);
static FUNC(void, FEE_CODE) Fee_SectorWriteFailedDeal(uint8 SectorIndex);
static FUNC(Std_ReturnType, FEE_CODE) Fee_CalTotalBlockLen(void);
static FUNC(void, FEE_CODE) Fee_CheckBlocklen(void);
static FUNC(void, FEE_CODE) Fee_ActiveVaildSector(void);

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
static FUNC(void, FEE_CODE) Fee_SwapJobCancel(void);
static FUNC(void, FEE_CODE) Fee_UpdateReservedSector( uint8 SectorIndex );
static FUNC(void, FEE_CODE) Fee_ImmWriteDone(void);
static FUNC(void, FEE_CODE) Fee_ChkBlockImmediateWriteJob(void);
static FUNC(void, FEE_CODE) Fee_SetReservedSector(void);
static FUNC(void, FEE_CODE) Fee_GetSwapSize
(
    uint32 SectorAddressStart,
    uint32 SectorAddressEnd
);
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

#if( (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) )
static FUNC(void, FEE_CODE) Fee_NotificationCallBack(void);
#endif /* (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) */

#if( (FEE_MEMACC_MODE_ENABLE == STD_ON) && (FEE_POLLING_MODE == STD_ON) )
static FUNC(MemIf_JobResultType, FEE_CODE) Fee_MemAccGetJobResult(void);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

#if( (FEE_MEMACC_MODE_ENABLE == STD_ON) && (FEE_POLLING_MODE == STD_OFF) )
static FUNC(MemIf_JobResultType, FEE_CODE) Fee_MemAccGetJobResultCallBack(MemAcc_JobResultType JobResult);
#endif /* ( FEE_MEMACC_MODE_ENABLE == STD_ON ) && ( FEE_POLLING_MODE == STD_OFF ) */


#if( FEE_SCAN_SECTOR_TAIL == STD_ON )
static FUNC(void, FEE_CODE) Fee_ScanReadSectorTail(void);
static FUNC(void, FEE_CODE) Fee_ScanSectorTailProc(void);
#endif/* FEE_SCAN_SECTOR_TAIL == STD_ON */

#define FEE_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define FEE_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( FEE_DEV_ERROR_DETECT == STD_ON )
/*
********************************************************************************
* Function Name: Fee_Det_ErrorReport
*
* Explanation: Function to report Error to Det.
*
* param: ApiId: Unique Api ID of Fee manager service.
*        ErrorId: Det Error ID of Fee manager.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
static FUNC(void, FEE_CODE) Fee_Det_ErrorReport(uint8 ApiId, uint8 ErrorId)
{
    /* Report Error to Det. */
    (void)Det_ReportError(FEE_MODULE_ID, FEE_INSTANCE_ID, ApiId, ErrorId);
}
#endif

/*
********************************************************************************
* Function Name: Fee_ErrorDeal
*
* Explanation: Execute when the Fee is abnormal and stop its function.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ErrorDeal(void)
{
    /*Stop Fee Module */
    Fee_PartitionInfo.ModuleRunningState = FEE_STOP_BY_INTER_ERROR;
    /* Stop Swap reaquest */
    Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_OFF;
    /* Set fee job result to failed */
    Fee_JobManagerInfo.JobResult = MEMIF_JOB_FAILED;
    /* Set fee job result to failed */
    Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
    /* Set job state to done */
    Fee_PartitionInfo.JobState = FEE_JOB_DONE;
    /* Set job state to done */
    Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_DONE;
    /* Update Fee module state */
    Fee_ModuleState = MEMIF_IDLE;
}

/*
********************************************************************************
* Function Name: Fee_SectorWriteFailedDeal
*
* Explanation: If the block head in the same sector fails continuously or is
*              cancelled for a total of 5 times, the action of switching sectors
*              will be executed.
* param: SectorIndex : Sector index that requires exception handling.
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SectorWriteFailedDeal(uint8 SectorIndex)
{

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
    uint8 actSectorIndex = FEE_VALUE_ZERO;
#endif/* FEE_IMMEDIATE_WRITE_ENABLE == STD_ON */

    /* Write block head consecutive failure count. */
    Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorWriteFailedCounter++;
    if( FEE_SECTOR_WRITE_FAILED_NUM <=
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorWriteFailedCounter )
    {
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorWriteFailedCounter = FEE_VALUE_ZERO;

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
        if( FEE_SECTOR_RESERVED_ACTIVATE == Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            if( FEE_IMM_WRITE_ON_IMM_SWAP != Fee_PartitionInfo.ImmWriteState )
            {
                if( E_OK == Fee_ForwardGetSector(FEE_SECTOR_ACTIVATE, FEE_SECTOR_DEF, &actSectorIndex) )
                {
                    Fee_UpdatePattitionInfo(actSectorIndex);
                }
            }
            else
            {
                if( E_OK == Fee_ForwardGetSector(FEE_SECTOR_RESERVED_FREE, FEE_SECTOR_DEF, &actSectorIndex) )
                {
                    Fee_PartitionInfo.SectorReservedNum--;
                    Fee_PartitionInfo.SectorFullNum++;
                    Fee_UpdatePattitionInfo(actSectorIndex);
                }
            }
        }
        else
#endif/* FEE_IMMEDIATE_WRITE_ENABLE == STD_ON */

        {
            Fee_PartitionInfo.SectorFullNum++;
            /* Switch to a new writable sector. */
            Fee_ChangePartintionSector();
        }
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_WRITE_FAILED;

        /* Update Swap status. */
        Fee_UpdateSwapRequest();
    }
}

/*
********************************************************************************
* Function Name: Fee_ScanCheckBlockHead
*
* Explanation: Scan check block head validity Synchronize to Ram space if
*              effective.
* param: BlockIndex : Scanned Block Index.
*        SectorIndex : Sector index that requires exception handling.
*        BlockHeadTmp : Temporary variable for storing Block information.
*        ValidFlag : Block head valid Flag.
*        CheckSum : Block head checksum.
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanCheckBlockHead
(
    uint16 BlockIndex,
    uint8 SectorIndex,
    P2CONST(Fee_BlockHeadRomType, AUTOMATIC, FEE_APPL_DATA) BlockHeadTmp,
    uint32 ValidFlag,
    uint32 CheckSum
)
{
    /* Calculate CheckSum.
       Check if the CheckSum are correct.
       Check block Index and blcok size. */
    if( (BlockIndex != FEE_DEFAULT_VALUE_BLOCK)&&
        (BlockHeadTmp->BlockSize == Fee_PartitionCfg.Fee_Block[BlockIndex].BlockSize) &&
        (FEE_VALUE_ZERO != BlockHeadTmp->BlockSize)&&
        (BlockHeadTmp->BlockCheck == CheckSum) )
    {
        Fee_ScanManagerInfo.BlankAddrUpdateRequest = TRUE;
        /* Check if the header flag is valid or invalid. */
        if( ((FEE_VALID_ID == ValidFlag) || (FEE_INVALID_ID == ValidFlag)) &&
            /* Update Ram data when scan block counter is greater than the Ram counter. */
            (BlockHeadTmp->BlockProgramCounter > Fee_PartitionCfg.Fee_Block[BlockIndex].Fee_BlockHead_Dyn->BlockProgramCounter) )
        {
                Fee_PartitionCfg.Fee_Block[BlockIndex].Fee_BlockHead_Dyn->BlockProgramCounter =
                    BlockHeadTmp->BlockProgramCounter;
                Fee_PartitionCfg.Fee_Block[BlockIndex].Fee_BlockHead_Dyn->BlockStartAddr =
                    BlockHeadTmp->BlockStartAddr;
                Fee_PartitionCfg.Fee_Block[BlockIndex].Fee_BlockHead_Dyn->ValidFlag = ValidFlag;
        }
        /* Update Sector valid block data addr. */
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->BlockDataAddr
            = BlockHeadTmp->BlockStartAddr;
        /* Update Sector valid block head addr. */
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr
            = Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned;
        /* Update current Sector valid block data addr. */
        Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr = BlockHeadTmp->BlockStartAddr;
    }
    else
    {
        /* This sector cannot write data anymore. */
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_BLOCK_NEED_SWAP;
    }

    /* Block loop counter increase. */
    Fee_PartitionInfo.BlockWriteCounterInSector++;
}

/*
********************************************************************************
* Function Name: Fee_ScanSectorBlockHeadEnd
*
* Explanation: The process required to complete the scanning of the current sector.
*
* param: SectorIndex : Sector index that requires exception handling.
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanSectorBlockHeadEnd(uint8 SectorIndex)
{
    if( FEE_SECTOR_NEED_SCAN == Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState )
    {
        if( FALSE == Fee_ScanManagerInfo.BlankAddrUpdateRequest )
        {
            Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr = Fee_ScanManagerInfo.BlankAddr;
        }
        /* Fee_CheckValidSector() to select which sector is FEE_SECTOR_ACTIVATE. */
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_FULL;
    }

    /* How many blcoks have been written to the scanned Sector for updating. */
    if( FEE_VALUE_ZERO != Fee_PartitionInfo.BlockWriteCounterInSector )
    {
        Fee_PartitionInfo.BlockWriteCounterInSector = Fee_PartitionInfo.BlockWriteCounterInSector - FEE_VALUE_ONE;
    }
    Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->BlockWriteCounterInSector = Fee_PartitionInfo.BlockWriteCounterInSector;
}

/*
********************************************************************************
* Function Name: Fee_ChkGeneralCondition
*
* Explanation: Check the general conditions.
*
* param: BlockIndex: The index of the corresponding block.
*
* retval: rtrnValu: Development Error.
********************************************************************************
*/
static FUNC(uint8, FEE_CODE) Fee_ChkGeneralCondition
(
    uint16 BlockIndex
)
{
    uint8 rtrnValu = FEE_E_NO_ERR;

    /* Check that FEE is initialized. */
    if( MEMIF_UNINIT == Fee_ModuleState ) /* [SWS_Fee_00123] */
    {
        rtrnValu = FEE_E_UNINIT;
    }
    /* [SWS_Fee_00144] */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    else if( MEMIF_BUSY == Fee_ModuleState )
    {
        rtrnValu = FEE_E_BUSY;
    }
    /* Check the blocknumber is in the range. */
    else if( BlockIndex >= FEE_BLOCK_NUMBER )
    {
        rtrnValu = FEE_E_INVALID_BLOCK_NO;
    }
    else
    {
        /* Do nothing. */
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_CalcuAlignedLen
*
* Explanation: Calculate the aligned length of the input data.
*
* param: len: Input length.
*
* retval: outLen: The aligned length.
********************************************************************************
*/
static FUNC(uint32, FEE_CODE) Fee_CalcuAlignedLen(uint32 len)
{
    uint32 outLen;

    /* Calculate the length aligned with the FEE_VIRTUAL_PAGE_SIZE. */
    if( (len % FEE_VIRTUAL_PAGE_SIZE) > FEE_VALUE_ZERO )
    {
        outLen = ((len / FEE_VIRTUAL_PAGE_SIZE) * FEE_VIRTUAL_PAGE_SIZE) + FEE_VIRTUAL_PAGE_SIZE;
    }
    else
    {
        outLen = len;
    }

    return outLen;
}

/*
********************************************************************************
* Function Name: Fee_MemCpy
*
* Explanation: Distribute internal data into the sector header structure.
*
* param: SrcAddr : Starting address.
*        DesAddr : Destination address.
*        length : Copy length.
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_MemCpy
(
    P2CONST(uint8, AUTOMATIC, FEE_APPL_CONST) SrcAddr,
    P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) DesAddr,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 length
)
{
    uint16 loopNum = FEE_VALUE_ZERO;
    uint16 alignedLen = FEE_VALUE_ZERO;

    /* Check if the input pointer is NULL. */
    if( (SrcAddr != NULL_PTR) && (DesAddr != NULL_PTR) )
    {
        if( length >= FEE_LENGTH_SIZE_16BYTE )
        {
            /* Determine if 4-byte alignment is present. */
            /* Polyspace +1 MISRA-C3:11.4 [JUstified:Unset] "NSCA_Polyspace_Fee_Rule11.4" */
            if( (FEE_VALUE_ZERO == (((uint32)SrcAddr) & FEE_REMAIN_4_MASK)) /* PRQA S 306 */ /* NSCA_QAC_Fee_Rule11.4, NSCA_QAC_Fee_Rule11.6 */
                /* Polyspace +1 MISRA-C3:11.4 [JUstified:Unset] "NSCA_Polyspace_Fee_Rule11.4" */
                && (FEE_VALUE_ZERO == (((uint32)DesAddr) & FEE_REMAIN_4_MASK)) ) /* PRQA S 306 */ /* NSCA_QAC_Fee_Rule11.4, NSCA_QAC_Fee_Rule11.6 */
            {
                alignedLen = (length >> FEE_VALUE_TWO);
                /* Copy destination address to source address. */
                for( loopNum = FEE_VALUE_ZERO; loopNum < alignedLen; loopNum++ )
                {
                    /* Polyspace +1 MISRA-C3:11.3 [JUstified:Unset] "NSCA_Polyspace_Common_NeuLibCopy" */
                    ((uint32 *)DesAddr)[loopNum] = ((const uint32 *)SrcAddr)[loopNum]; /* PRQA S 3305,310 */ /* NSCA_QAC_Fee_Rule11.3, NSCA_QAC_Fee_Rule11.3 */
                }
            }
        }
        /* Copy destination address to source address. */
        for( loopNum = (alignedLen << FEE_VALUE_TWO); loopNum < length; loopNum++ )
        {
            DesAddr[loopNum] = SrcAddr[loopNum];
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_SeekIndexFromNumber
*
* Explanation: Seek block index by block number.
*
* param: blockNumber: Number of logical block number.
*
* retval: block index
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
static FUNC(uint16, FEE_CODE) Fee_SeekIndexFromNumber(uint16 blockNumber)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 blockIndex;
    uint16 rtrnValu = FEE_DEFAULT_VALUE_BLOCK;
    uint16 left, right;

    left = FEE_VALUE_ZERO;
    right = Fee_PartitionCfg.BlockTotalNum - FEE_VALUE_ONE;
    /* Using the binary method. */
    while( left <= right )
    {
        blockIndex = (left + right) / FEE_VALUE_TWO;
        /* polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Fee_IllegallyDereferencedPointer" */
        /* polyspace +2 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Fee_PtrOutside" */
        /* polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Fee_PtrOutside" */
        if( Fee_PartitionCfg.Fee_Block[blockIndex].BlockNumber == blockNumber )
        {
            rtrnValu = blockIndex;
            break;
        }
        else if( Fee_PartitionCfg.Fee_Block[blockIndex].BlockNumber > blockNumber )
        {
            right = blockIndex - FEE_VALUE_ONE;
        }
        else
        {
            left = blockIndex + FEE_VALUE_ONE;
        }
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_CheckSum
*
* Explanation: Calculate the checksum of data according to uint8.
*
* param: dataBuf: Calculated data set
*        Length: The length of the calculated data set.
*
* retval: checksum: Calculated checksum result.
********************************************************************************
*/
static FUNC(uint32, FEE_CODE) Fee_CheckSum
(
    P2CONST(uint8, AUTOMATIC, FEE_APPL_CONST) dataBuf,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint8 Length
)
{
    uint8 i;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint32 checkSum = FEE_VALUE_ZERO;

    /* Calculate checksum */
    for( i = FEE_VALUE_ZERO; i < Length; i++ )
    {
        checkSum = checkSum + dataBuf[i];
    }

    return checkSum;
}

/*
********************************************************************************
* Function Name: Fee_CheckSumEraseData
*
* Explanation: Distribute internal data into the block header structure.
*
* param: BlockHdTmp: block header structure to be assigned
*        BlockHeadCheckSum : Analyze the checksum of the calculated Block Head.
*
* retval: eraseCheckSum: The checksum of the entire blcok head data is used to
*         determine whether it is an erase value.
********************************************************************************
*/
static FUNC(uint32, FEE_CODE) Fee_CheckSumEraseData
(
    P2VAR(uint8, AUTOMATIC, FEE_APPL_CONST) BlockHdTmp,
    uint32 BlockHeadCheckSum
)
{
    uint32 i;
    uint8 *temPtr;
    uint32 eraseCheckSum = BlockHeadCheckSum;

    temPtr = (uint8 *)BlockHdTmp;

    /* Sum Block Head CheckSum. */
    for( i = Fee_CalcuCheckSumLen; i < Fee_WithoutValidFlag; i++ )
    {
        eraseCheckSum = eraseCheckSum + temPtr[i];
    }
    /* Sum Block Head ValidFlag. */
    for( i = Fee_WithoutValidFlagAligned; i < Fee_BlockValidEndLen; i++ )
    {
        eraseCheckSum = eraseCheckSum + temPtr[i];
    }
    return eraseCheckSum;
}

/*
********************************************************************************
* Function Name: Fee_ScanCurrentSectorFinish
*
* Explanation: Service to process sector head.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanCurrentSectorFinish(void)
{
    Fee_PartitionInfo.SectorFullNum++;
    /* If there are no sectors need to scan. */
    if( E_NOT_OK == Fee_GetSectorToScanBlock() )
    {
        /* Set job state to next state. */
        Fee_PartitionInfo.JobState = FEE_JOB_SCAN_DONE;
        Fee_PartitionInfo.noActiveSectors = TRUE;
        Fee_ScanDone();
    }
}

/*
********************************************************************************
* Function Name: Fee_CheckValidSector
*
* Explanation: Get valid sector from one partiton.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_CheckValidSector(void)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint8 sectorIndex = FEE_VALUE_ZERO;
    uint8 valid = FEE_VALID_FALSE;
    Fee_SectorHeadType *Fee_SectorHeadDyn = NULL_PTR;
    uint32 sectorCounterTemp = FEE_VALUE_ZERO;

    Fee_PartitionInfo.PartitionInfoSnap.SectorCounter = FEE_VALUE_ZERO;
    for( sectorIndex = FEE_VALUE_ZERO; sectorIndex < Fee_PartitionCfg.SectorTotalNum; sectorIndex++ )
    {
        Fee_SectorHeadDyn = Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorHead_Dyn;
        Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorLastSize =
            Fee_Sublmt(Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->BlockDataAddr,
                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr);
        /* If there is a valid sector, update it to the current sector. */
        if( FEE_SECTOR_FULL == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            /* Update to the latest sectorcounter. */
            if( Fee_SectorHeadDyn->SectorCounter >= Fee_PartitionInfo.PartitionInfoSnap.SectorCounter )
            {
                /* Update badBlocksectorCounter to maximum counter. */
                if( Fee_SectorHeadDyn->SectorCounter > sectorCounterTemp )
                {
                    sectorCounterTemp = Fee_SectorHeadDyn->SectorCounter;
                }
                /* Get the maximum counter. */
                Fee_PartitionInfo.PartitionInfoSnap.SectorCounter = Fee_SectorHeadDyn->SectorCounter;

                /* FEE_COMPATIBLE_SECTOR_HEAD_VAILD_ID is a special sector valid identification used to be compatible
                   with reading old version sector heads, or to be read special sector valid identification that
                   introduced for reading old version sector heads. */
                if( (FEE_SECTOR_HEAD_VAILD_ID == Fee_SectorHeadDyn->ValidFlag) ||
                    (FEE_COMPATIBLE_SECTOR_HEAD_VAILD_ID == Fee_SectorHeadDyn->ValidFlag) )
                {
                    valid = FEE_VALID_TURE;
                    /* Set correct information. */
                    Fee_PartitionInfo.PartitionInfoSnap.SectorIndex = sectorIndex;
                }
            }
        }
        else if( FEE_SECTOR_BLOCK_NEED_SWAP == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            if( Fee_SectorHeadDyn->SectorCounter > sectorCounterTemp )
            {
                sectorCounterTemp = Fee_SectorHeadDyn->SectorCounter;
                Fee_PartitionInfo.PartitionInfoSnap.SectorCounter = sectorCounterTemp;
            }
        }
        else
        {
            /* Nothing to do */
        }
    }

    if( FEE_VALID_TURE == valid )
    {
        /* Set the latest block data address and block size. */
        Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr =
            Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr;
        Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr =
            Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->BlockDataAddr;

        /* Sector state is USED_NOW. */
        Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_ACTIVATE;

        /* Subtract the sectors that can currently be written. */
        Fee_PartitionInfo.SectorFullNum--;
        /* Calculate sector remaining address size. */
        Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize =
            Fee_Sublmt(Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr,Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr);
        Fee_UpdateSwapRequest();
    }
    else
    {
        Fee_ChangePartintionSector();
        Fee_UpdateSwapRequest();
    }
}

/*
********************************************************************************
* Function Name: Fee_ScanReadSectorHead
*
* Explanation: Service to send read sector head command.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanReadSectorHead(void)
{
    Std_ReturnType rtrnValu;
    uint16 loopCtrl;
    const Fee_SectorHeadCfgType* feeSectorHdCfgTmp;
    uint16 legacySectorHeadAligned;

    /* Check if sector indedx is in the range. */
    if( (Fee_PartitionInfo.PartitionInfoSnap.SectorIndex < Fee_PartitionCfg.SectorTotalNum) &&
        (MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult) )
    {
        legacySectorHeadAligned = (uint16)(Fee_CalcuAlignedLen(sizeof(Fee_SectorHeadType) - sizeof(uint32)) +
                                    Fee_CalcuAlignedLen(sizeof(uint32)));
        /* Get the sector head structure of the partition. */
        feeSectorHdCfgTmp = &Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex];

        /* Read sector head from flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Read(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)(feeSectorHdCfgTmp->SectorStartAddr),
                                                      (MemAcc_DataType *)Fee_InterBuffer, /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                      (MemAcc_LengthType)legacySectorHeadAligned);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Read(feeSectorHdCfgTmp->SectorStartAddr,
                                                      (uint8 *)Fee_InterBuffer,
                                                      legacySectorHeadAligned);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;
            /* Set job state to next state. */
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_SECTOR_HED_PROC;
        }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        else if( Fee_RetryCounter < MAX_NUM_SCAN_RETRYIES ) /* Scan retry. */
        {
            Fee_RetryCounter++;
        }
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        else
        {
            /* The sector that cannot read the sector head continuously is
               treated as the sector of abnormal data and will be erased. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_SECTOR_HED_PROC;
            /* Clean the valid flag from Fee_InterBuffer. */
            legacySectorHeadAligned = legacySectorHeadAligned >> FEE_VALUE_TWO;
            for( loopCtrl = FEE_VALUE_ZERO; loopCtrl < legacySectorHeadAligned; loopCtrl++ )
            {
                Fee_InterBuffer[loopCtrl] = FEE_BUFFER_VALUE;
            }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        }
    }
}

#if( FEE_SCAN_SECTOR_TAIL == STD_ON )
/*
********************************************************************************
* Function Name: Fee_ScanReadSectorTail
*
* Explanation: Service to send read sector tail command.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanReadSectorTail(void)
{
    Std_ReturnType rtrnValu;
    uint32 loopCtrl;
    uint32 sectorTailAligned;
    uint32 readAddr;

    /* Check if sector indedx is in the range. */
    if( (Fee_PartitionInfo.PartitionInfoSnap.SectorIndex < Fee_PartitionCfg.SectorTotalNum) &&
        (MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult) )
    {
        /* Calculate the alignment length. */
        /* Polyspace +1 MISRA-C3:10.3 [JUstified:Unset] " NSCA_Polyspace_Common_AutosarBoolean " */
        sectorTailAligned = Fee_CalcuAlignedLen(sizeof(uint32));

        /* set current sector header write address. */
        readAddr = Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].SectorStartAddr +
                    Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].SectorSize - sectorTailAligned;
        /* Read sector head from flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Read(FEE_MEMACC_ADDRESS_AREA_ID, readAddr,
                                                      (MemAcc_DataType *)Fee_InterBuffer, /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                      (MemAcc_LengthType)sectorTailAligned);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Read(readAddr,
                                                      (uint8 *)Fee_InterBuffer,
                                                      sectorTailAligned);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;
            /* Set job state to next state. */
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_SECTOR_TAIL_PROC;
        }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        else if( Fee_RetryCounter < MAX_NUM_SCAN_RETRYIES ) /* Scan retry. */
        {
            Fee_RetryCounter++;
        }
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        else
        {
            /* The sector that cannot read the sector head continuously is
               treated as the sector of abnormal data and will be erased. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_SECTOR_TAIL_PROC;
            /* Clean the valid flag from Fee_InterBuffer. */
            sectorTailAligned = sectorTailAligned >> FEE_VALUE_TWO;
            for( loopCtrl = FEE_VALUE_ZERO; loopCtrl < sectorTailAligned; loopCtrl++ )
            {
                Fee_InterBuffer[loopCtrl] = FEE_BUFFER_VALUE;
            }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        }
    }
}
#endif/* FEE_SCAN_SECTOR_TAIL == STD_ON */
/*
********************************************************************************
* Function Name: Fee_GetSectorToScanBlock
*
* Explanation: Get sector to scan block.
*
* param: None
*
* retval: E_OK : Obtain the sector that requires scanning.
*         E_NOT_OK : There are no sectors that require scanning.
********************************************************************************
*/
static FUNC(Std_ReturnType, FEE_CODE) Fee_GetSectorToScanBlock(void)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint8 sectorIndex = FEE_VALUE_ZERO;
    Fee_SectorHeadType *sectorHeadDyn = NULL_PTR;

    for( sectorIndex = FEE_VALUE_ZERO; sectorIndex < Fee_PartitionCfg.SectorTotalNum; sectorIndex++ )
    {
        /* Get need scan sector. */
        if( FEE_SECTOR_NEED_SCAN == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            sectorHeadDyn = Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorHead_Dyn;

            /* Set correct information. */
            Fee_PartitionInfo.PartitionInfoSnap.SectorIndex = sectorIndex;
            Fee_PartitionInfo.PartitionInfoSnap.SectorCounter = sectorHeadDyn->SectorCounter;

#if( FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON )
            if( TRUE == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->DecoreLegacySectorHead )
            {
                Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr =
                                   sectorHeadDyn->SectorStartAddr + Fee_CalcuAlignedLen(sizeof(Fee_SectorHeadType) - sizeof(uint32)) +
                                   Fee_CalcuAlignedLen(sizeof(uint32));
            }
            else
#endif /* FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON */

            {
                Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr =
                    sectorHeadDyn->SectorStartAddr + Fee_JobManagerInfo.SectorHeadAligned;
            }
            /* Set the latest block data address and block size. */
            Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr =
                sectorHeadDyn->SectorStartAddr + sectorHeadDyn->SectorSize;

            /* Initialize the number of blocks written to the current sector. */
            Fee_PartitionInfo.BlockWriteCounterInSector = FEE_VALUE_ZERO;

            rtrnValu = E_OK;
            break;
        }
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_ScanReadBlockHead
*
* Explanation: Service to send read block head command
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanReadBlockHead(void)
{
    Std_ReturnType rtrnValu;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    uint32 scanReadlen = Fee_ScanManagerInfo.ScanReadLen;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint32 sectorEndAddr = Fee_PartitionCfg.Fee_SectorHead[sectorIndex].SectorStartAddr +
                                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].SectorSize;
    /* Check if the job result is successfully processed. */
    if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        if( (Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_ScanManagerInfo.ScanReadLen) > sectorEndAddr )
        {
            scanReadlen = sectorEndAddr - Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr;
        }
        /* Read sector head from flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Read(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)(Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr),
                                                      (MemAcc_DataType*)Fee_InterBuffer, /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                      (MemAcc_LengthType)scanReadlen);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Read(Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr,
                                                      (uint8 *)Fee_InterBuffer,
                                                      scanReadlen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;
            /* Set job state to next state. */
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_BLOCK_HED_PROC;
        }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        else if( Fee_RetryCounter < MAX_NUM_SCAN_RETRYIES ) /* Scan retry. */
        {
            Fee_RetryCounter++;
        }
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        else
        {
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED_RETRY;

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

            Fee_ScanReadBlockHeadRetry();
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_ScanReadBlockHeadRetry
*
* Explanation: Service to send read block head command.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanReadBlockHeadRetry(void)
{
    Std_ReturnType rtrnValu;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    const Fee_SectorHeadCfgType *sectorHeadCfg = &Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex];
    /* Check if the job result is successfully processed */
    if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        /* Read sector head from flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Read(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)(Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr),
                                                      (MemAcc_DataType *)(&Fee_InterBuffer[FEE_VALUE_ZERO]),  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                      (MemAcc_LengthType)Fee_JobManagerInfo.BlockHeadAligned);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Read(Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr,
                                                      (uint8 *)(&Fee_InterBuffer[FEE_VALUE_ZERO]),
                                                      Fee_JobManagerInfo.BlockHeadAligned);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;
            /* Set job state to next state. */
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_BLOCK_HED_PROC_RETRY;
        }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        else if( Fee_RetryCounter < MAX_NUM_SCAN_RETRYIES )
        {
             Fee_RetryCounter++;
        }
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        else
        {
            /* Set fee job result to ok. */
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED_RETRY;
            Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr =
                Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned;

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO. */

            /* Check whether the current HeadAddr is greater than the DataAddr. */
            if( ((Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned) >= Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr) ||
                 /* the block head address is out of the config size. */
                (Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr >= ((sectorHeadCfg->SectorStartAddr + sectorHeadCfg->SectorSize) - Fee_JobManagerInfo.BlockHeadAligned)) )
            {
                /* This sector cannot write data anymore. */
                Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorState =
                    FEE_SECTOR_BLOCK_NEED_SWAP;
                Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED;
                Fee_ScanCurrentSectorFinish();
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_BadSectorProc
*
* Explanation: Bad sector deal.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_BadSectorProc(void)
{
    uint8 idleSectorNum = FEE_VALUE_ZERO;

    Fee_PartitionInfo.SectorBadNum++;
    if( (Fee_PartitionCfg.SectorTotalNum > (Fee_PartitionInfo.SectorBadNum + Fee_PartitionInfo.BlockUseSectorNum)) )
    {
        idleSectorNum = Fee_PartitionCfg.SectorTotalNum - Fee_PartitionInfo.SectorBadNum - Fee_PartitionInfo.BlockUseSectorNum;
    }
    else
    {
        Fee_ErrorDeal();
    }

    if( FEE_RUNNING == Fee_PartitionInfo.ModuleRunningState )
    {
        if( (idleSectorNum >= Fee_PartitionInfo.BlockUseSectorNum) && (idleSectorNum > FEE_VALUE_TWO) )
        {
            if( FEE_VALUE_TWO <= (Fee_PartitionInfo.BlockUseSectorNum >> FEE_VALUE_ONE) )
            {
                Fee_PartitionInfo.TriggerSwapThreshold =
                    Fee_PartitionCfg.SectorTotalNum - Fee_PartitionInfo.SectorBadNum - (Fee_PartitionInfo.BlockUseSectorNum >> FEE_VALUE_ONE);

                if( (Fee_PartitionInfo.TriggerSwapThreshold - Fee_PartitionInfo.BlockUseSectorNum) <=
                    /* polyspace +1 DEFECT:BITWISE_ARITH_MIX [Justified:Unset] "NSCA_Polyspace_Fee_BITWISE_ARITH_MIX" */
                    (Fee_PartitionInfo.BlockUseSectorNum >> FEE_VALUE_ONE) )
                {
                    Fee_PartitionInfo.TriggerSwapThreshold =
                        Fee_PartitionCfg.SectorTotalNum - Fee_PartitionInfo.SectorBadNum - FEE_VALUE_TWO;
                }
            }
            else
            {
                Fee_PartitionInfo.TriggerSwapThreshold =
                    Fee_PartitionCfg.SectorTotalNum - Fee_PartitionInfo.SectorBadNum - FEE_VALUE_TWO;
            }
        }
        else
        {
            Fee_PartitionInfo.TriggerSwapThreshold =
                Fee_PartitionCfg.SectorTotalNum - Fee_PartitionInfo.SectorBadNum - FEE_VALUE_ONE;
        }
        if( Fee_PartitionInfo.BlockUseSectorNum >= Fee_PartitionInfo.TriggerSwapThreshold )
        {
            Fee_ErrorDeal();
        }

        if( FEE_JOB_SWAP_ERASE_DONE != Fee_SwapManagerInfo.SwapJob )
        {
            Fee_ChangePartintionSector();
            if( (FEE_JOB_SWAP_DONE != Fee_SwapManagerInfo.SwapJob) &&
                (FEE_SECTOR_SWAP_PAUSE != Fee_SwapManagerInfo.SwapRequest) )
            {
                Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_BLOCK_IDLE;
            }
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
            Fee_UpdateSwapRequest();
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_ScanSectorProc
*
* Explanation: Service to process sector head.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanSectorProc(void)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    uint16 secBuffersize;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint32 checkSum;
    Fee_SectorHeadType *sectorHeadTmp = NULL_PTR;
    Fee_SectorHeadType *sectorHeadDyn = NULL_PTR;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorHeadCheckSumLen = (uint8)(sizeof(Fee_SectorHeadType) - sizeof(uint32) - sizeof(uint32));

#if( FEE_SCAN_SECTOR_TAIL == STD_ON )
    uint32 eraseDataCheckSum;
#endif/* FEE_SCAN_SECTOR_TAIL == STD_ON */

#if( FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON )
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorHeadWithoutVaild = (uint8)(sizeof(Fee_SectorHeadType) - sizeof(uint32));
    uint16 legacySectorHeadAligned = FEE_VALUE_ZERO;
    uint16 sectorHeadWithoutVaildAlign = FEE_VALUE_ZERO;
#endif /* FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON */

    /* Check if the job result is ok. Check if partiton index and sector indedx is in the range. */
    if( (MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult) && (sectorIndex < Fee_PartitionCfg.SectorTotalNum) )
    {
        sectorHeadDyn = Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorHead_Dyn;
        /* Decode data from flash into sector header structure. */
        /* Polyspace +1 MISRA-C3:11.3 [JUstified:Unset] " NSCA_Polyspace_Common_NeuLibCopy " polyspace +1 DEFECT:OBJECT_SIZE_MISMATCH [Justified:Unset] "NSCA_Polyspace_Fee_OBJECT_SIZE_MISMATCH" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.1" */
        sectorHeadTmp = (Fee_SectorHeadType*)&Fee_InterBuffer[FEE_VALUE_ZERO];  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

#if( FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON )
        /* FEE_COMPATIBLE_SECTOR_HEAD_VAILD_ID is a special sector valid identification used to be compatible
           with reading old version sector heads, or to be read special sector valid identification that
           introduced for reading old version sector heads. */
        if( ((FEE_COMPATIBLE_SECTOR_HEAD_VAILD_ID != sectorHeadTmp->ValidFlag) &&
             (FEE_SECTOR_HEAD_VAILD_ID != sectorHeadTmp->ValidFlag)) ||
            ((FEE_COMPATIBLE_SECTOR_HEAD_VAILD_ID == sectorHeadTmp->ValidFlag) &&
             (FEE_VALUE_TWO == Fee_PartitionCfg.SectorTotalNum) &&
             (FEE_VIRTUAL_PAGE_SIZE <= FEE_LENGTH_SIZE_16BYTE)) )
        {
            sectorHeadWithoutVaildAlign = ((uint16)Fee_CalcuAlignedLen(sectorHeadWithoutVaild) / FEE_DIVIDE_4);
            sectorHeadTmp->ValidFlag = *((uint32*)(&Fee_InterBuffer[sectorHeadWithoutVaildAlign]));
            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->DecoreLegacySectorHead = TRUE;
            Fee_LegacySectorHeadNum++;
        }
#endif /* FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON */

        /* Calculate checksum. */
        checkSum = Fee_CheckSum((const uint8 *)sectorHeadTmp, sectorHeadCheckSumLen);  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

#if( FEE_SCAN_SECTOR_TAIL == STD_ON )
        eraseDataCheckSum = Fee_CheckSumEraseData((uint8*)sectorHeadTmp, checkSum);  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
        if( FEE_BLOCK_EARSE_DATA_CHECKSUM != eraseDataCheckSum)
        {
#endif/* FEE_SCAN_SECTOR_TAIL == STD_ON */
            /* Check if th checksum and valid bits are correct. */
            if( (checkSum == sectorHeadTmp->SectorCheck) &&
            ((FEE_SECTOR_HEAD_VAILD_ID == sectorHeadTmp->ValidFlag) ||
            (FEE_COMPATIBLE_SECTOR_HEAD_VAILD_ID == sectorHeadTmp->ValidFlag)) &&
            (sectorHeadTmp->SectorStartAddr == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].SectorStartAddr) )
            {
                FEE_MEMCPY((const uint8*)sectorHeadTmp, (uint8*)sectorHeadDyn, sizeof(Fee_SectorHeadType));  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_NEED_SCAN;
                Fee_SectorScanNum++;

                if( Fee_PartitionCfg.Fee_SectorHead[Fee_SectorMaxCounterIndex].Fee_SectorHead_Dyn->SectorCounter <
                    sectorHeadTmp->SectorCounter )
                {
                    Fee_SectorMaxCounterIndex = sectorIndex;
                }

                if( Fee_SectorScanNum == Fee_PartitionCfg.SectorTotalNum )
                {

#if( FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON )
                    if( (Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->DecoreLegacySectorHead == TRUE) &&
                        (Fee_LegacySectorHeadNum == FEE_VALUE_TWO) )
                    {
                        if( Fee_SectorMaxCounterIndex == FEE_VALUE_ONE )
                        {
                            Fee_PartitionCfg.Fee_SectorHead[FEE_VALUE_ZERO].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_NEED_ERASE;
                        }
                        else
                        {
                            Fee_PartitionCfg.Fee_SectorHead[FEE_VALUE_ONE].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_NEED_ERASE;
                        }
                    }
                    else
#endif

                    {
                        Fee_PartitionCfg.Fee_SectorHead[Fee_SectorMaxCounterIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_NEED_ERASE;
                    }

                    Fee_ScanManagerInfo.ScanSectorNeedEraseNum++;
                    Fee_PartitionInfo.SectorFreeNum++;
                }

#if( FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON )
                if( TRUE == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->DecoreLegacySectorHead )
                {
                    legacySectorHeadAligned =
                        (uint16)(Fee_CalcuAlignedLen(sizeof(Fee_SectorHeadType) - sizeof(uint32)) + Fee_CalcuAlignedLen(sizeof(uint32)));

                    Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr =
                        Fee_PartitionCfg.Fee_SectorHead[sectorIndex].SectorStartAddr + legacySectorHeadAligned;
                }
                else
#endif /* FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON */

                {
                    Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr
                        = Fee_PartitionCfg.Fee_SectorHead[sectorIndex].SectorStartAddr + Fee_JobManagerInfo.SectorHeadAligned;
                }
                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->BlockDataAddr
                    = Fee_PartitionCfg.Fee_SectorHead[sectorIndex].SectorSize +
                        Fee_PartitionCfg.Fee_SectorHead[sectorIndex].SectorStartAddr;

                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorCounter
                    = sectorHeadTmp->SectorCounter;
            }
            /* There is data but the check failed. */
            else
            {
                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_NEED_ERASE;
                Fee_ScanManagerInfo.ScanSectorNeedEraseNum++;
                Fee_PartitionInfo.SectorFreeNum++;

#if( FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON )
                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->DecoreLegacySectorHead = FALSE;
#endif /* FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON */

            }

            /* Set next sector. */
            Fee_PartitionInfo.PartitionInfoSnap.SectorIndex++;

            /* Set job state to read sector head. */
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_SECTOR_HED;

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO. */

            /* Check if all the sector have been decode */
            if( Fee_PartitionCfg.SectorTotalNum == Fee_PartitionInfo.PartitionInfoSnap.SectorIndex )
            {
                /* Set job state to next state. */
                Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED;

                /* Call read block header fucntion */
                if( E_OK == Fee_GetSectorToScanBlock() )
                {
                    Fee_ScanReadBlockHead();
                }
                else
                {
                    /* Set job state to end state. */
                    Fee_ScanDone();
                }
            }

#if( FEE_SCAN_SECTOR_TAIL == STD_ON )
        }
        else
        {
            /* Set job state to next state. */
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_SECTOR_TAIL;
        }
#endif/* FEE_SCAN_SECTOR_TAIL == STD_ON */

    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        if( Fee_RetryCounter < MAX_NUM_SCAN_RETRYIES )
        {
            Fee_RetryCounter++;
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_SECTOR_HED;
        }
        else
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        {
            /* Set fee job result to ok. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
            /* Clean the valid flag from Fee_InterBuffer */
            for( secBuffersize = FEE_VALUE_ZERO; secBuffersize < (Fee_JobManagerInfo.SectorHeadAligned >> FEE_VALUE_TWO); secBuffersize++)
            {
                Fee_InterBuffer[secBuffersize] = FEE_BUFFER_VALUE;
            }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        }
    }
    else
    {
        /* Nothing to do. */
    }
}

#if( FEE_SCAN_SECTOR_TAIL == STD_ON )
/*
********************************************************************************
* Function Name: Fee_ScanSectorTailProc
*
* Explanation: Service to process sector head.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanSectorTailProc(void)
{
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    uint16 secBuffersize;

    /* Check if the job result is ok. Check if partiton index and sector indedx is in the range. */
    if( (MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult) && (sectorIndex < Fee_PartitionCfg.SectorTotalNum) )
    {
        if( FEE_SECTOR_TAIL_ID == Fee_InterBuffer[FEE_VALUE_ZERO] )
        {
            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_NEED_ERASE;
            Fee_ScanManagerInfo.ScanSectorNeedEraseNum++;

#if( FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON )
            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->DecoreLegacySectorHead = FALSE;
#endif /* FEE_COMPATIBLE_LEGACY_SECTOR_HEAD == STD_ON */

        }
        Fee_PartitionInfo.SectorFreeNum++;

        /* Set next sector. */
        Fee_PartitionInfo.PartitionInfoSnap.SectorIndex++;

        /* Set job state to read sector head. */
        Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_SECTOR_HED;

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO. */

        /* Check if all the sector have been decode */
        if( Fee_PartitionCfg.SectorTotalNum == Fee_PartitionInfo.PartitionInfoSnap.SectorIndex )
        {
            /* Set job state to next state. */
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED;

            /* Call read block header fucntion */
            if( E_OK == Fee_GetSectorToScanBlock() )
            {
                Fee_ScanReadBlockHead();
            }
            else
            {
                /* Set job state to end state. */
                Fee_ScanDone();
            }
        }
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        if( Fee_RetryCounter < MAX_NUM_SCAN_RETRYIES )
        {
            Fee_RetryCounter++;
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_SECTOR_HED;
        }
        else
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        {
            /* Set fee job result to ok. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
            /* Clean the valid flag from Fee_InterBuffer */
            for( secBuffersize = FEE_VALUE_ZERO; secBuffersize < (Fee_JobManagerInfo.SectorHeadAligned >> FEE_VALUE_TWO); secBuffersize++)
            {
                Fee_InterBuffer[secBuffersize] = FEE_BUFFER_VALUE;
            }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        }
    }
    else
    {
        /* Nothing to do. */
    }
}
#endif/* FEE_SCAN_SECTOR_TAIL == STD_ON */
/*
********************************************************************************
* Function Name: Fee_ScanBlockProc
*
* Explanation: Service to process sector head.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanBlockProc(void)
{
    boolean tmpExit = FALSE;
    /* polyspace-begin MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    uint16 i;
    uint16 blockLoopNum;
    uint16 blockIndex;
    uint8 *bufferPtr;
    uint32 blockHeadNum = FEE_VALUE_ZERO;
    uint32 checkSum;
    uint32 eraseDataCheckSum;
    uint32 validFlag = FEE_VALUE_ZERO;
    Fee_BlockHeadRomType *blockHeadTmp;
    uint32 blockHeadDataOffset = FEE_VALUE_ZERO;
    uint32 blockHeadValidOffset = FEE_VALUE_ZERO;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    const Fee_SectorHeadCfgType *sectorHeadCfg = &Fee_PartitionCfg.Fee_SectorHead[sectorIndex];
    /* polyspace-end MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */

    /* Check if the job result is ok. */
    if( MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult )
    {
        /* Number of blocks that can be processed by one read operation. */
        blockLoopNum = (uint16)(FEE_WRITE_BUFFER_SIZE / (Fee_JobManagerInfo.BlockHeadAligned));
        bufferPtr = (uint8 *)&Fee_InterBuffer[FEE_VALUE_ZERO];  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

        for( i = FEE_VALUE_ZERO; i < blockLoopNum; i++ )
        {
            blockHeadDataOffset = i * Fee_JobManagerInfo.BlockHeadAligned;
            blockHeadValidOffset = blockHeadDataOffset + Fee_WithoutValidFlagAligned;
            /* Polyspace +1 MISRA-C3:11.3 [JUstified:Unset] " NSCA_Polyspace_Common_NeuLibCopy " polyspace +1 DEFECT:OBJECT_SIZE_MISMATCH [Justified:Unset] "NSCA_Polyspace_Fee_OBJECT_SIZE_MISMATCH" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.1" */
            blockHeadTmp = (Fee_BlockHeadRomType*)(&bufferPtr[blockHeadDataOffset]);  /* PRQA S 310,3305 */ /* NSCA_QAC_Fee_Rule11.3 */
            /* Polyspace +1 MISRA-C3:11.3 [JUstified:Unset] " NSCA_Polyspace_Common_NeuLibCopy " */
            validFlag = *((uint32*)(&bufferPtr[blockHeadValidOffset]));  /* PRQA S 310,3305 */ /* NSCA_QAC_Fee_Rule11.3 */
            checkSum = Fee_CheckSum((const uint8*)&bufferPtr[blockHeadDataOffset], Fee_CalcuCheckSumLen);
            /* Check if the block is default erase block or the number of blocks in this sector exceeds the limit. */
            eraseDataCheckSum = Fee_CheckSumEraseData(&bufferPtr[blockHeadDataOffset],checkSum);
            if( (FEE_BLOCK_EARSE_DATA_CHECKSUM != eraseDataCheckSum) &&
                (FEE_SECTOR_MAX_BLOCK_NUMBER >= Fee_PartitionInfo.BlockWriteCounterInSector) )
            {
                /* Find the block index by block number. */
                blockIndex = Fee_SeekIndexFromNumber(blockHeadTmp->BlockNumber);
                Fee_SectorEarseDataCoutner = FEE_VALUE_ZERO;

                Fee_ScanCheckBlockHead(blockIndex, sectorIndex, (const Fee_BlockHeadRomType*)blockHeadTmp, validFlag, checkSum);
            }
            else
            {
                blockHeadNum++;
                if( TRUE == Fee_ScanManagerInfo.BlankAddrUpdateRequest )
                {
                    Fee_ScanManagerInfo.BlankAddrUpdateRequest = FALSE;
                    Fee_ScanManagerInfo.BlankAddr =
                        Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr;
                    Fee_PartitionInfo.BlockWriteCounterInSector = Fee_PartitionInfo.BlockWriteCounterInSector + blockHeadNum;
                    blockHeadNum = FEE_VALUE_ZERO;
                }
                Fee_SectorEarseDataCoutner++;
                if( (FEE_SECTOR_WRITE_FAILED_NUM < Fee_SectorEarseDataCoutner) ||
                    (FEE_SECTOR_MAX_BLOCK_NUMBER == Fee_PartitionInfo.BlockWriteCounterInSector) )
                {
                    tmpExit = TRUE;
                    Fee_SectorEarseDataCoutner = FEE_VALUE_ZERO;
                }
            }

            /* Set the flash address for the next read. */
            Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr =
                Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned;

            /* Check whether the current HeadAddr is greater than the DataAddr. */
            if( ((Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned) >= Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr) ||
                /* the block head address is out of the config size. */
                (Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr >= ((sectorHeadCfg->SectorStartAddr + sectorHeadCfg->SectorSize) - Fee_JobManagerInfo.BlockHeadAligned)) )
            {
                /* Scan finished, Set exit flag. */
                tmpExit = TRUE;
            }
            if( TRUE == tmpExit )
            {
                Fee_ScanSectorBlockHeadEnd(sectorIndex);
                break;
            }
        }

        /* Set job state to read sector head */
        Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED;

        /* Check if the scan block operation is complete. */
        if( TRUE == tmpExit )
        {
            /* The current sector scan is complete, you need to get the next sector to scan. */
            Fee_ScanCurrentSectorFinish();
        }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO. */

    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        if( Fee_RetryCounter < MAX_NUM_SCAN_RETRYIES )
        {
            Fee_RetryCounter++;
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED;
        }
        else
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO. */

        {
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED_RETRY;

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO. */

            Fee_ScanReadBlockHeadRetry();
        }
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_ScanDone
*
* Explanation: Action at the end of the scan.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanDone(void)
{
    Fee_PartitionInfo.noActiveSectors = TRUE;
    /* Clear Fee_PartitionInfo.PartitionInfoSnap.SectorIndex. */
    Fee_PartitionInfo.PartitionInfoSnap.SectorIndex = FEE_VALUE_ZERO;

    /* Set job state to done */
    Fee_PartitionInfo.JobState = FEE_JOB_DONE;
    if( MEMIF_BUSY_INTERNAL == Fee_ModuleState )
    {
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;
    }
}

/*
********************************************************************************
* Function Name: Fee_ScanJob
*
* Explanation: Service to scan valid block information.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanJob(void)
{
    switch( Fee_PartitionInfo.JobState )
    {
        case FEE_JOB_SCAN_INT_SCAN:
            Fee_ScanReadSectorHead();
            break;

        case FEE_JOB_SCAN_READ_SECTOR_HED:
            Fee_ScanReadSectorHead();
            break;

        case FEE_JOB_SCAN_SECTOR_HED_PROC:
            Fee_ScanSectorProc();
            break;

#if( FEE_SCAN_SECTOR_TAIL == STD_ON )
        case FEE_JOB_SCAN_READ_SECTOR_TAIL:
            Fee_ScanReadSectorTail();
            break;

        case FEE_JOB_SCAN_SECTOR_TAIL_PROC:
            Fee_ScanSectorTailProc();
            break;
#endif/* FEE_SCAN_SECTOR_TAIL == STD_ON */

        case FEE_JOB_SCAN_READ_BLOCK_HED:
            Fee_ScanReadBlockHead();
            break;

        case FEE_JOB_SCAN_READ_BLOCK_HED_RETRY:
            Fee_ScanReadBlockHeadRetry();
            break;

        case FEE_JOB_SCAN_BLOCK_HED_PROC:
            Fee_ScanBlockProc();
            break;

        case FEE_JOB_SCAN_BLOCK_HED_PROC_RETRY:
            Fee_ScanBlockProcRetry();
            break;

        case FEE_JOB_SCAN_DONE:
            Fee_ScanDone();
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: Fee_ScanBlockProcRetry
*
* Explanation: Service to process sector head.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ScanBlockProcRetry(void)
{
    boolean tmpExit = FALSE;
    /* polyspace-begin MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    uint16 blockIndex;
    uint32 checkSum;
    uint32 eraseDataCheckSum;
    uint32 validFlag = FEE_VALUE_ZERO;
    /* polyspace-end MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    Fee_BlockHeadRomType *blockHeadTmp;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    const Fee_SectorHeadCfgType *sectorHeadCfg = &Fee_PartitionCfg.Fee_SectorHead[sectorIndex];

    /* Number of blocks that can be processed by one read operation Check if the job result is ok. */
    if( MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult )
    {
        /* Polyspace +1 MISRA-C3:11.3 [JUstified:Unset] " NSCA_Polyspace_Common_NeuLibCopy " polyspace +1 DEFECT:OBJECT_SIZE_MISMATCH [Justified:Unset] "NSCA_Polyspace_Fee_OBJECT_SIZE_MISMATCH" polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.1" */
        blockHeadTmp = (Fee_BlockHeadRomType*)&Fee_InterBuffer[FEE_VALUE_ZERO];  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
        validFlag = *((uint32*)(&Fee_InterBuffer[Fee_WithoutValidFlagAligned/FEE_DIVIDE_4]));
        checkSum = Fee_CheckSum((const uint8*)blockHeadTmp, Fee_CalcuCheckSumLen);  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
        eraseDataCheckSum = Fee_CheckSumEraseData((uint8*)blockHeadTmp, checkSum);  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
        /* Check if the block is default erase block or the number of blocks in this sector exceeds the limit. */
        if( (FEE_BLOCK_EARSE_DATA_CHECKSUM == eraseDataCheckSum) ||
            (FEE_SECTOR_MAX_BLOCK_NUMBER == Fee_PartitionInfo.BlockWriteCounterInSector) )
        {
            if( TRUE == Fee_ScanManagerInfo.BlankAddrUpdateRequest )
            {
                Fee_ScanManagerInfo.BlankAddrUpdateRequest = FALSE;
                Fee_ScanManagerInfo.BlankAddr =
                    Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr;
            }
            Fee_SectorEarseDataCoutner++;
            if( (FEE_SECTOR_WRITE_FAILED_NUM < Fee_SectorEarseDataCoutner) ||
                (FEE_SECTOR_MAX_BLOCK_NUMBER == Fee_PartitionInfo.BlockWriteCounterInSector) )
            {
                tmpExit = TRUE;
                Fee_SectorEarseDataCoutner = FEE_VALUE_ZERO;
            }
        }
        else
        {
            Fee_SectorEarseDataCoutner = FEE_VALUE_ZERO;
            /* Find the block index by block number. */
            blockIndex = Fee_SeekIndexFromNumber(blockHeadTmp->BlockNumber);

            Fee_ScanCheckBlockHead(blockIndex, sectorIndex, (const Fee_BlockHeadRomType*)blockHeadTmp, validFlag, checkSum);
        }

        /* Set the flash address for the next read. */
        Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr = Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned;
        Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED_RETRY;

        /* Check whether the current HeadAddr is greater than the DataAddr. */
        if( ((Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned) >= Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr) ||
             /* the block head address is out of the config size. */
            (Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr >= ((sectorHeadCfg->SectorStartAddr + sectorHeadCfg->SectorSize) - Fee_JobManagerInfo.BlockHeadAligned)) ||
            (TRUE == tmpExit) )
        {
            Fee_ScanSectorBlockHeadEnd(sectorIndex);
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED;
            Fee_ScanCurrentSectorFinish();
        }

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        if( Fee_RetryCounter < MAX_NUM_SCAN_RETRYIES )
        {
            Fee_RetryCounter++;
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED_RETRY;
        }
        else
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

        {
            Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED_RETRY;

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

            Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr = Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned;
            /* Check whether the current HeadAddr is greater than the DataAddr. */
            if( ((Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned) >= Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr) ||
            /* the block head address is out of the config size. */
                (Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr >= ((sectorHeadCfg->SectorStartAddr + sectorHeadCfg->SectorSize) - Fee_JobManagerInfo.BlockHeadAligned)) )
            {
                /* This sector cannot write data anymore. */
                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_BLOCK_NEED_SWAP;
                Fee_PartitionInfo.JobState = FEE_JOB_SCAN_READ_BLOCK_HED;
                Fee_ScanCurrentSectorFinish();
            }
            else
            {
                Fee_ScanReadBlockHeadRetry();
            }

        }
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_UpdateSwapRequest
*
* Explanation: Service to set a partiton preform swap flag.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_UpdateSwapRequest(void)
{
    uint8 triggerImmediateSwapThreshold;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint32 blockIndex;

    if( (FEE_RUNNING == Fee_PartitionInfo.ModuleRunningState) &&
        (FEE_SECTOR_SWAP_PAUSE != Fee_SwapManagerInfo.SwapRequest) )
    {
        triggerImmediateSwapThreshold = Fee_PartitionCfg.SectorTotalNum - Fee_PartitionInfo.SectorBadNum - FEE_VALUE_ONE -
            Fee_PartitionInfo.SectorReservedNum;
        /* Determine whether a page change is required based on the sector usage. */
        if( (Fee_PartitionInfo.SectorFullNum >= Fee_PartitionInfo.TriggerSwapThreshold) &&
            (FEE_VALUE_ONE != Fee_PartitionInfo.TriggerSwapThreshold) &&
            (Fee_PartitionInfo.SectorFullNum != triggerImmediateSwapThreshold) )
        {
            Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_ON;
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_DONE;
        }
        else if( Fee_PartitionInfo.SectorFullNum >= triggerImmediateSwapThreshold )
        {
            Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_IMMEDIATELY_SWAP_ON;
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_DONE;
            for( blockIndex = FEE_VALUE_ZERO; blockIndex < FEE_BLOCK_NUMBER; blockIndex++ )
            {
                Fee_BlockHeadAddrBackUp[blockIndex] = Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->BlockStartAddr;
            }
        }
        else
        {
            /* Nothing to do. */
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_WritedSectorHeadDone
*
* Explanation: Write sector head to flash Done.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_WritedSectorHeadDone(void)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    /* Check if the job result is ok and the sector index is in the range. */
    if( (MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult) && (sectorIndex< Fee_PartitionCfg.SectorTotalNum) )
    {
        if( FEE_SECTOR_RESERVED_FREE != Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_ACTIVATE;
            Fee_PartitionInfo.SectorFreeNum--;
        }
        else
        {
            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_RESERVED_ACTIVATE;
            Fee_PartitionInfo.ReservedActive = TRUE;
            Fee_PartitionInfo.SectorReservedNum--;
            Fee_PartitionInfo.SectorFullNum++;
        }

        /* Set job state to done. */
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;

        Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorWriteFailedCounter = FEE_VALUE_ZERO;
        /* Copy backup sector header to current block header. */
        FEE_MEMCPY((const uint8 *)&Fee_SwapManagerInfo.SectorHeadBackup,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                    (uint8 *)Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorHead_Dyn,
                        sizeof(Fee_SectorHeadType));

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
        Fee_BuildSectorRetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
        if( MAX_NUM_INTER_ERROR_RETRYIES <= Fee_BuildSectorRetryCounter )
        {
            Fee_BuildSectorRetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_BAD;
            Fee_PartitionInfo.SectorFreeNum--;
            Fee_BadSectorProc();

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
        }
        else
        {
            Fee_BuildSectorRetryCounter++;
            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_NEED_ERASE;
            Fee_ScanManagerInfo.ScanSectorNeedEraseNum++;
            Fee_PartitionInfo.PartitionInfoSnap.EraseFlag = FEE_SECTOR_ERASE_ON;
            Fee_PartitionInfo.PartitionInfoSnap.EraseSectorIndex = sectorIndex;
            Fee_PartitionInfo.PartitionInfoSnap.EraseNextState = FEE_JOB_WRITE_SEC_HEAD;
            Fee_PartitionInfo.JobState = FEE_JOB_INTER_ERASE;
        }
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapWritedSectorHead
*
* Explanation: Write sector head to flash in swap/init operation.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapWritedSectorHead(void)
{
    Std_ReturnType rtrnValu;
    uint32 writeAlignLen;
    uint32 writeAddr;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorHeadCheckSumLen = (uint8)(sizeof(Fee_SectorHeadType) - sizeof(uint32) - sizeof(uint32));

    /* Check if the job result is ok and the sector index is in the range. */
    if( (MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult) && (Fee_PartitionInfo.PartitionInfoSnap.SectorIndex < Fee_PartitionCfg.SectorTotalNum) )
    {
        /* set current sector header write address. */
        writeAddr = Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].SectorStartAddr;

        /* Backup current sector header information. */
        FEE_MEMCPY((const uint8 *)Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorHead_Dyn,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                    (uint8 *)&Fee_SwapManagerInfo.SectorHeadBackup, sizeof(Fee_SectorHeadType));

        /* Number of sector writes plus one. */
        if( FEE_SECTOR_RESERVED_FREE != Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            Fee_SwapManagerInfo.SectorHeadBackup.SectorCounter = Fee_PartitionInfo.PartitionInfoSnap.SectorCounter;
        }
        else
        {
            Fee_SwapManagerInfo.SectorHeadBackup.SectorCounter = FEE_VALUE_ZERO;
        }

        /* Update sector start address. */
        Fee_SwapManagerInfo.SectorHeadBackup.SectorStartAddr = writeAddr;

        /* Update sector size. */
        Fee_SwapManagerInfo.SectorHeadBackup.SectorSize =
            Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].SectorSize;

        /* Calculation sector header checksum. */
        Fee_SwapManagerInfo.SectorHeadBackup.SectorCheck = Fee_CheckSum((const uint8 *)&Fee_SwapManagerInfo.SectorHeadBackup, sectorHeadCheckSumLen);  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

        /* Update sector valid flag. */
        Fee_SwapManagerInfo.SectorHeadBackup.ValidFlag = FEE_SECTOR_HEAD_VAILD_ID;

        /* Write sector header to internal buffer. */
        FEE_MEMCPY((const uint8 *)&Fee_SwapManagerInfo.SectorHeadBackup, (uint8*)Fee_InterBuffer, sizeof(Fee_SectorHeadType));  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

        /* Calculate the alignment length. */
        writeAlignLen = Fee_CalcuAlignedLen(sizeof(Fee_SectorHeadType));

        /* Write sector header to flash */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)writeAddr,
                                                      (const MemAcc_DataType*)Fee_InterBuffer,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                      (MemAcc_LengthType)writeAlignLen);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Write(writeAddr,
                                                      (const uint8*)Fee_InterBuffer,
                                                       writeAlignLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;
            /* Set current sector last size. */
            Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize =
                Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize - Fee_JobManagerInfo.SectorHeadAligned;
            /* Set the job state to write the sector tail. */
            Fee_PartitionInfo.JobState = FEE_JOB_WRITE_SEC_TAIL;
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapWritedSectorTail
*
* Explanation: Write sector tail to flash in swap/init operation.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapWritedSectorTail(void)
{
    Std_ReturnType rtrnValu;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    uint32 writeAlignLen;
    uint32 writeAddr;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint32 Fee_Tail = FEE_SECTOR_TAIL_ID;

    /* Check if the job result is ok and the sector index is in the range. */
    if( (MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult) && (sectorIndex < Fee_PartitionCfg.SectorTotalNum) )
    {
        /* Write sector header to internal buffer. */
        FEE_MEMCPY((const uint8 *)&Fee_Tail, (uint8*)Fee_InterBuffer, sizeof(uint32));  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

        /* Calculate the alignment length. */
        writeAlignLen = Fee_CalcuAlignedLen(sizeof(uint32));

        /* set current sector header write address. */
        writeAddr = Fee_PartitionCfg.Fee_SectorHead[sectorIndex].SectorStartAddr +
                    Fee_PartitionCfg.Fee_SectorHead[sectorIndex].SectorSize - writeAlignLen;

        /* Write sector header to flash */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)writeAddr,
                                                      (const MemAcc_DataType*)Fee_InterBuffer,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                      (MemAcc_LengthType)writeAlignLen);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Write(writeAddr,
                                                      (const uint8*)Fee_InterBuffer,
                                                       writeAlignLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;
            /* Set current sector last size. */
            Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize =
                Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize - writeAlignLen;
            /* Set the job state to done. */
            Fee_PartitionInfo.JobState = FEE_JOB_SEC_HEAD_DONE;
        }
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
        /* Check if the retry counter exceeds the configured maximum retry number. */
        if( MAX_NUM_INTER_ERROR_RETRYIES <= Fee_BuildSectorRetryCounter )
        {
            Fee_BuildSectorRetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */
            /* Set the current sector state to "sector is bad". */
            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_BAD;
            /* Decrease the number of free sectors by one. */
            Fee_PartitionInfo.SectorFreeNum--;
            /* Handle bad sectors. */
            Fee_BadSectorProc();
#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
        }
        else
        {
            /* Establishment failed. Increment the retry counter. */
            Fee_BuildSectorRetryCounter++;
            /* Set the current sector state to "need erase", wait for retry to re-establish after the erase operation completes. */
            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_NEED_ERASE;
            /* Increment the count of sectors pending erasure by one. */
            Fee_ScanManagerInfo.ScanSectorNeedEraseNum++;
            /* Set the sector erase flag. */
            Fee_PartitionInfo.PartitionInfoSnap.EraseFlag = FEE_SECTOR_ERASE_ON;
            /* Set the erase sector index to the current sector index. */
            Fee_PartitionInfo.PartitionInfoSnap.EraseSectorIndex = sectorIndex;
            /* Set the next state to "write sector head". */
            Fee_PartitionInfo.PartitionInfoSnap.EraseNextState = FEE_JOB_WRITE_SEC_HEAD;
            /* Set the job state to "erase". */
            Fee_PartitionInfo.JobState = FEE_JOB_INTER_ERASE;
        }
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapRetry
*
* Explanation: Erase the Sector to retry and swap , or bad sector deal.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapRetry(void)
{

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint32 blockIndex;
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

    if( FEE_SECTOR_IMMEDIATELY_SWAP_ON == Fee_SwapManagerInfo.SwapRequest )
    {

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
        Fee_SwapBlockRetryWriteCounter++;
        if( MAX_NUM_INTER_ERROR_RETRYIES >= Fee_SwapBlockRetryWriteCounter )
        {
            Fee_PartitionCfg.Fee_SectorHead[Fee_SwapManagerInfo.SwapPartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorState =
                FEE_SECTOR_IMM_SWAP_NEED_ERASE;
            Fee_PartitionInfo.SectorFreeNum++;
            for( blockIndex = FEE_VALUE_ZERO; blockIndex < FEE_BLOCK_NUMBER; blockIndex++ )
            {
                Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->BlockStartAddr = Fee_BlockHeadAddrBackUp[blockIndex];
            }
            Fee_UpdatePattitionInfo(Fee_PartitionInfo.PartitionInfoSnap.SectorIndex);
        }
        else
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

        {

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
            Fee_SwapBlockRetryWriteCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

            if( Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorState != FEE_SECTOR_ACTIVATE )
            {
                Fee_PartitionInfo.SectorFullNum--;
            }
            Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_BAD_NEED_SWAP;
            Fee_BadSectorProc();
        }
    }
    else
    {
        Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_BLOCK_IDLE;
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapReadData
*
* Explanation: Service to read block data from flash.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapReadData(void)
{
    Std_ReturnType rtrnValu;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_SwapManagerInfo.SwapPartitionInfoSnap.SectorIndex;

    /* Check if the job result is ok and the pointer is not NULL. */
    if( MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult )
    {
        Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorWriteFailedCounter = FEE_VALUE_ZERO;

        /* Judge if need clear the static variable. */
        if( TRUE == Fee_SwapClearStaticVariable )
        {
            Fee_SwapManagerInfo.ReadIsProcessing = FALSE;
            Fee_SwapManagerInfo.RemaindReadLen = FEE_VALUE_ZERO;
            Fee_SwapManagerInfo.SwapReadAddr = FEE_VALUE_ZERO;
        }
        /* Whether it is the first read. */
        if( FALSE == Fee_SwapManagerInfo.ReadIsProcessing )
        {
            Fee_SwapManagerInfo.ReadIsProcessing = TRUE;
            /* Set total read length. */
            Fee_SwapManagerInfo.RemaindReadLen =
                Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].BlockSize;

            /* Set the block read address from previous sector. */
            Fee_SwapManagerInfo.SwapReadAddr =
                Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].Fee_BlockHead_Dyn->BlockStartAddr;
        }
        /* Check if the block size is large than the internal buffer size. */
        if( Fee_SwapManagerInfo.RemaindReadLen > FEE_WRITE_BUFFER_SIZE )
        {
            /* Set read block length to buffer size. */
            Fee_SwapManagerInfo.SwapReadLen = FEE_WRITE_BUFFER_SIZE;
        }
        else
        {
            /* Set read block length to block size. */
            Fee_SwapManagerInfo.SwapReadLen = Fee_SwapManagerInfo.RemaindReadLen;
        }

        /* Call read flash function. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Read(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)Fee_SwapManagerInfo.SwapReadAddr,
                                                      (MemAcc_DataType *)Fee_InterBuffer,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                      (MemAcc_LengthType)Fee_SwapManagerInfo.SwapReadLen);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Read(Fee_SwapManagerInfo.SwapReadAddr,
                                                      (uint8 *)Fee_InterBuffer,
                                                      Fee_SwapManagerInfo.SwapReadLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
            Fee_SwapReadBlockAddrTemp = Fee_SwapManagerInfo.SwapReadAddr;
            Fee_SwapReadBlockRemainLenTemp = Fee_SwapManagerInfo.RemaindReadLen;
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

            /* Update next read block adress. */
            Fee_SwapManagerInfo.SwapReadAddr = (uint32)(Fee_SwapManagerInfo.SwapReadAddr + Fee_SwapManagerInfo.SwapReadLen);
            /* Update next read block size. */
            Fee_SwapManagerInfo.RemaindReadLen = (uint16)(Fee_SwapManagerInfo.RemaindReadLen - Fee_SwapManagerInfo.SwapReadLen);

            /* Check if the block have been read finish. */
            if( FEE_VALUE_ZERO == Fee_SwapManagerInfo.RemaindReadLen )
            {
                Fee_SwapManagerInfo.ReadIsProcessing = FALSE;
            }

            /* Set job state to write block. */
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_WRITE_BLOCK_DATA;
        }
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        Fee_SwapRetry();
        if( FEE_SECTOR_IMMEDIATELY_SWAP_ON != Fee_SwapManagerInfo.SwapRequest )
        {
            if( FALSE == Fee_SwapBlcokHeadFailedUpdate )
            {
                Fee_SwapBlcokHeadFailedUpdate = TRUE;
                Fee_SectorWriteFailedDeal(sectorIndex);
            }
        }
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_UpdatePattitionInfo
*
* Explanation: Update Pattition Sector Info.
*
* param: SectorIndex: Sector Index
*
* retval: void
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
static FUNC(void, FEE_CODE) Fee_UpdatePattitionInfo(uint8 SectorIndex)
{
    /* The sector status that needs to be established before it can be used. */
    if( FEE_SECTOR_NEED_SCAN > Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState )
    {
        if( FEE_SECTOR_IMM_SWAP_NEED_ERASE == Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            Fee_PartitionInfo.PartitionInfoSnap.SectorCounter =
                Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorCounter + FEE_VALUE_ONE;
        }
        else
        {
            Fee_PartitionInfo.PartitionInfoSnap.SectorCounter++;
        }

        Fee_PartitionInfo.PartitionInfoSnap.SectorIndex = SectorIndex;

        /* Set current sector last size. */
        Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize =
            Fee_PartitionCfg.Fee_SectorHead[SectorIndex].SectorSize - Fee_JobManagerInfo.SectorHeadAligned;

        /* Set current sector block header address. */
        Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr =
            Fee_PartitionCfg.Fee_SectorHead[SectorIndex].SectorStartAddr + Fee_JobManagerInfo.SectorHeadAligned;

        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr =
            Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr;

        /* Set current sector block data address. */
        Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr =
            Fee_PartitionCfg.Fee_SectorHead[SectorIndex].SectorStartAddr + Fee_PartitionCfg.Fee_SectorHead[SectorIndex].SectorSize - Fee_CalcuAlignedLen(sizeof(uint32));

        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->BlockDataAddr =
            Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr;

        /* Set current sector last size. */
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorLastSize =
            Fee_Sublmt(Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr, Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr);

        if( FEE_SECTOR_RESERVED_FREE != Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorCounter =
                Fee_PartitionInfo.PartitionInfoSnap.SectorCounter;
        }
        else
        {
            Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorCounter = FEE_VALUE_ZERO;
        }

        /* Set the next sector to invalid. */
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorHead_Dyn->ValidFlag =
            FEE_INVALID_ID;

        /* Clear write counter. */
        Fee_PartitionInfo.BlockWriteCounterInSector = FEE_VALUE_ZERO;
        Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->BlockWriteCounterInSector = FEE_VALUE_ZERO;
        if( (FEE_SECTOR_NEED_ERASE == Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState) )
        {
            Fee_PartitionInfo.PartitionInfoSnap.EraseFlag = FEE_SECTOR_ERASE_ON;
            Fee_PartitionInfo.PartitionInfoSnap.EraseSectorIndex = SectorIndex;
            Fee_PartitionInfo.PartitionInfoSnap.EraseNextState = FEE_JOB_WRITE_SEC_HEAD;
            Fee_PartitionInfo.JobState = FEE_JOB_INTER_ERASE;
        }
        else if( FEE_SECTOR_IMM_SWAP_NEED_ERASE == Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            /* Erases the sector that was swaped. */
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseFlag = FEE_SECTOR_ERASE_ON;
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseSectorIndex = SectorIndex;
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseNextState = FEE_JOB_WRITE_SEC_HEAD;
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.SwapEraseNextState = FEE_JOB_SWAP_BLOCK_IDLE;
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_ERASE;
            Fee_SwapManagerInfo.SwapScanBlockIndex = FEE_VALUE_ZERO;
        }
        else
        {
            Fee_PartitionInfo.JobState = FEE_JOB_WRITE_SEC_HEAD;
        }
    }
    /* Can directly switch the sector state for use (no need to establish a sector head). */
    else if( (FEE_SECTOR_RESERVED_ACTIVATE == Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState) ||
            (FEE_SECTOR_ACTIVATE == Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState) )
    {
        /* Update the current sector status to the sector status corresponding to SectorIndex. */
        Fee_PartitionInfo.PartitionInfoSnap.SectorIndex = SectorIndex;

        Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize =
            Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorLastSize;

        Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr =
            Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr;

        Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr =
            Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->BlockDataAddr;

        Fee_PartitionInfo.BlockWriteCounterInSector =
            Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->BlockWriteCounterInSector;
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_ForwardGetSector
*
* Explanation: Get the sector index whose status is SectorState1 or SectorState2.
*
* param: SectorState1:Status of the sector to be searched.
*        SectorState2:Status of the sector to be searched.
*        SectorIndex: Pointer to Sector Index.
*
* retval: E_OK : Obtained the corresponding Sector index for the state.
*         E_NOT_OK : No corresponding Sector index found for the state.
********************************************************************************
*/
static FUNC(Std_ReturnType, FEE_CODE) Fee_ForwardGetSector
(
    Fee_SectorStatusType SectorState1,
    Fee_SectorStatusType SectorState2,
    P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) SectorIndex
)
{
    uint8 sectorIndex_temp = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex + FEE_VALUE_ONE;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint8 sectorIndex;
    Std_ReturnType rtrnValu = E_NOT_OK;
    boolean loop = TRUE;

    while( TRUE == loop )
    {
        for( sectorIndex = sectorIndex_temp; sectorIndex < FEE_SECTOR_NUMBER; sectorIndex++ )
        {
            if( (SectorState1 == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) ||
                (SectorState2 == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) )
            {
                *SectorIndex = sectorIndex;
                rtrnValu = E_OK;
                break;
            }
            if( sectorIndex == Fee_PartitionInfo.PartitionInfoSnap.SectorIndex )
            {
                loop = FALSE;
                /* polyspace +1 MISRA-C3:15.4 [Justified:Unset] "NSCA_Polyspace_Fee_Rule15.4" */
                break;  /* PRQA S 771 */ /* NSCA_QAC_Fee_Rule15.4 */
            }
        }
        if( E_OK == rtrnValu )
        {
            break;
        }
        else if( sectorIndex == Fee_PartitionCfg.SectorTotalNum )
        {
            sectorIndex_temp = FEE_VALUE_ZERO;
        }
        else
        {
            /* Nothing to do. */
        }
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_BackwardGetSector
*
* Explanation: Get the sector index whose status is SectorState1 or SectorState2.
*
* param: SectorState1:Status of the sector to be searched.
*        SectorState2:Status of the sector to be searched.
*        SectorIndex: Pointer to Sector Index.
*
* retval: E_OK : Obtained the corresponding Sector index for the state.
*         E_NOT_OK : No corresponding Sector index found for the state.
********************************************************************************
*/
static FUNC(Std_ReturnType, FEE_CODE) Fee_BackwardGetSector
(
    Fee_SectorStatusType SectorState1,
    Fee_SectorStatusType SectorState2,
    P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) SectorIndex
)
{
    uint8 sectorIndex_temp = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex - FEE_VALUE_ONE;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint8 sectorIndex;
    Std_ReturnType rtrnValu = E_NOT_OK;
    boolean loop = TRUE;

    while( TRUE == loop )
    {
        for( sectorIndex = sectorIndex_temp; ((sectorIndex != FEE_VALUE_FF) && (sectorIndex < Fee_PartitionCfg.SectorTotalNum)); sectorIndex-- )
        {
            if( (SectorState1 == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) ||
                (SectorState2 == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) )
            {
                *SectorIndex = sectorIndex;
                rtrnValu = E_OK;
                break;
            }
            if( sectorIndex == Fee_PartitionInfo.PartitionInfoSnap.SectorIndex )
            {
                loop = FALSE;
                /* polyspace +1 MISRA-C3:15.4 [Justified:Unset] "NSCA_Polyspace_Fee_Rule15.4" */
                break;  /* PRQA S 771 */ /* NSCA_QAC_Fee_Rule15.4 */
            }
        }
        if( E_OK == rtrnValu )
        {
            break;
        }
        else if( sectorIndex == FEE_VALUE_FF )
        {
            sectorIndex_temp = Fee_PartitionCfg.SectorTotalNum - FEE_VALUE_ONE;
        }
        else
        {
            /* Nothing to do. */
        }
    }
    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_SwapWritedBlockHead
*
* Explanation: Write Block head to flash in swap operation.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapWritedBlockHead(void)
{
    Std_ReturnType rtrnValu = E_OK;
    uint32 writeAlignLen;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 writeLen;
    uint32 writeAddr;

    /* Check if the job result is ok and the block index is in the range. */
    if( (MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult) && (Fee_SwapManagerInfo.SwapBlockIndex < Fee_PartitionCfg.BlockTotalNum) )
    {

        /* Backup current block header information. */
        Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockNumber =
            Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].BlockNumber;
        Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockSize =
            Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].BlockSize;
        Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockProgramCounter =
            Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].Fee_BlockHead_Dyn->BlockProgramCounter;
        Fee_SwapManagerInfo.SwapBlockHeadBackup.ValidFlag =
            Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].Fee_BlockHead_Dyn->ValidFlag;

        /* Check if the block is valid. */
        if( FEE_VALID_ID == Fee_SwapManagerInfo.SwapBlockHeadBackup.ValidFlag )
        {
            /* Get the data write size of the block. */
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockWritelen =
                Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].BlockSize;
            rtrnValu = Fee_CheckWriteSpace(Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockWritelen);

            if( E_OK == rtrnValu )
            {
                /* Create snapshot form Fee_PartitionInfo, used for swap jobs. */
                FEE_MEMCPY((const uint8 *)&Fee_PartitionInfo.PartitionInfoSnap,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                            (uint8 *)&Fee_SwapManagerInfo.SwapPartitionInfoSnap, (sizeof(Fee_PartitionInfoSnapType)));

                /* Set current block header write address. */
                writeAddr = Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockHeadAddr;

                /* Set current block header write length. */
                writeLen = (uint16)(sizeof(Fee_BlockHeadRomType) - sizeof(uint32)); /* Block header size except vilad flag */

                /* Number of block writes plus one. */
                Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockProgramCounter++;

                /* Set block valid flag to default. */
                Fee_SwapManagerInfo.SwapBlockHeadBackup.ValidFlag = FEE_DEFAULT_VALID_ID;

                /* Set the block write address of the current sector. */
                Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockStartAddr =
                    Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockDataAddr - Fee_CalcuAlignedLen(Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockSize);

                /* Calculation block header checksum. */
                Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockCheck = Fee_CheckSum((const uint8*)(&Fee_SwapManagerInfo.SwapBlockHeadBackup), Fee_CalcuCheckSumLen);  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

                /* Write block header to internal buffer. */
                FEE_MEMCPY((const uint8 *)&Fee_SwapManagerInfo.SwapBlockHeadBackup, (uint8 *)Fee_InterBuffer, writeLen);  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

                /* Calculate the alignment length. */
                writeAlignLen = Fee_CalcuAlignedLen(writeLen);

                /* Write block header to flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
                rtrnValu = MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)writeAddr,
                                                              (const MemAcc_DataType*)Fee_InterBuffer,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                              (MemAcc_LengthType)writeAlignLen);
#else
                rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Write(writeAddr,
                                                              (const uint8*)Fee_InterBuffer,
                                                              writeAlignLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

                if( E_OK == rtrnValu )
                {
                    /* Set fls job result to pending. */
                    Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;

                    /* Set current block header address. */
                    Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockHeadAddr =
                        Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned;

                    /* Set the block write address of the current sector. */
                    Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockDataAddr =
                         Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockDataAddr - Fee_CalcuAlignedLen(Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockSize);

                    /* Set current sector last size for asyn swap sector. */
                    Fee_SwapManagerInfo.SwapPartitionInfoSnap.SectorLastSize =
                        Fee_SwapManagerInfo.SwapPartitionInfoSnap.SectorLastSize - Fee_JobManagerInfo.BlockHeadAligned -
                        Fee_CalcuAlignedLen(Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockSize);

                    /* Update current Sector data. */
                    Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr = Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockHeadAddr;
                    Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr = Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockDataAddr;
                    Fee_PartitionInfo.PartitionInfoSnap.SectorIndex = Fee_SwapManagerInfo.SwapPartitionInfoSnap.SectorIndex;
                    Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize = Fee_SwapManagerInfo.SwapPartitionInfoSnap.SectorLastSize;
                    Fee_PartitionInfo.PartitionInfoSnap.SectorCounter = Fee_SwapManagerInfo.SwapPartitionInfoSnap.SectorCounter;

                    /* Update Sector data. */
                    Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr =
                        Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr;
                    Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->BlockDataAddr =
                        Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr;
                    Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorLastSize =
                                            Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize;

                    Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].Fee_BlockHead_Dyn->BlockProgramCounter++;

                    /* Increase Fee Write Block Count. */
                    Fee_PartitionInfo.BlockWriteCounterInSector++;
                    Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->BlockWriteCounterInSector =
                        Fee_PartitionInfo.BlockWriteCounterInSector;

                    /* Set job sate to read block data. */
                    Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_READ_BLOCK_DATA;
                    Fee_SwapClearStaticVariable = TRUE;
                    Fee_SwapBlcokHeadFailedUpdate = FALSE;
                }
            }
        }
        else
        {
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_BLOCK_IDLE;
        }
    }
    else
    {
        if( Fee_SwapManagerInfo.SwapBlockIndex >= Fee_PartitionCfg.BlockTotalNum )
        {
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_BLOCK_IDLE;
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapWritedBlockData
*
* Explanation: Service to write block to flash in swap operation.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapWritedBlockData(void)
{
    Std_ReturnType rtrnValu;
    uint16 blockSize;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint32 writeLen;
    uint32 writeAddr;

    /* Check if the job result is ok and the block index is in the range. */
    if( (MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult) &&
        (Fee_SwapManagerInfo.SwapBlockIndex < Fee_PartitionCfg.BlockTotalNum) )
    {
        /* Judge if need to clear the static variable. */
        if( TRUE == Fee_SwapClearStaticVariable )
        {
            Fee_SwapManagerInfo.ProcessedWriteLen = FEE_VALUE_ZERO;
            Fee_SwapClearStaticVariable = FALSE;
        }
        /* Set block size. */
        blockSize = Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockSize;
        /* Calculate the alignment length */
        writeLen = Fee_CalcuAlignedLen(Fee_SwapManagerInfo.SwapReadLen);
        /* Update next write address. */
        writeAddr = Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockDataAddr + Fee_SwapManagerInfo.ProcessedWriteLen;

        /* Write sector header to flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)writeAddr,
                                                       (const MemAcc_DataType*)Fee_InterBuffer,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                       (MemAcc_LengthType)writeLen);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Write(writeAddr,
                                                      (const uint8*)Fee_InterBuffer,
                                                       writeLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;

            /* Update write total length. */
            Fee_SwapManagerInfo.ProcessedWriteLen = Fee_SwapManagerInfo.ProcessedWriteLen + writeLen;

            /* Set job sate to write block head. */
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_READ_BLOCK_DATA;
            Fee_SwapBlcokHeadFailedUpdate = TRUE;

            /* Check if the block has write finish. */
            if( Fee_SwapManagerInfo.ProcessedWriteLen >= blockSize )
            {
                /* Clear total length. */
                Fee_SwapManagerInfo.ProcessedWriteLen = FEE_VALUE_ZERO;

                /* Set job sate to write block head. */
                Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_WRITE_BLOCK_VLDE;
            }
        }

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
        Fee_SwapBlockRetryReadCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

    }
    else if( (MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult) &&
             (Fee_SwapManagerInfo.SwapBlockIndex < Fee_PartitionCfg.BlockTotalNum) )
    {

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
        if( Fee_SwapBlockRetryReadCounter < MAX_NUM_INTER_ERROR_RETRYIES )
        {
            Fee_SwapBlockRetryReadCounter++;
            /* Back up read block data param */
            Fee_SwapManagerInfo.SwapReadAddr = Fee_SwapReadBlockAddrTemp;
            Fee_SwapManagerInfo.RemaindReadLen = Fee_SwapReadBlockRemainLenTemp;
            Fee_SwapManagerInfo.ReadIsProcessing = TRUE;

            /* Set job state to internal erase */
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_READ_BLOCK_DATA;
            Fee_SwapBlcokHeadFailedUpdate = TRUE;
            /* Reset Fls result to OK */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
        }
        else
        {
            Fee_SwapBlockRetryReadCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_BLOCK_IDLE;
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
            Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].Fee_BlockHead_Dyn->ValidFlag = FEE_SWAP_READ_ERROR;
            Fee_SwapManagerInfo.SwapScanBlockIndex++;

#if(MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO)
        }
#endif

    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapWritedBlockVld
*
* Explanation: Write block valid flag
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapWritedBlockVld(void)
{
    Std_ReturnType rtrnValu;
    uint32 writeAlignLen;
    uint32 writeAddr;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint32 validFlag = FEE_VALID_ID;

    /* Check if the job result is ok */
    if( MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult )
    {
        /* Calculate the valid identifier alignment length. */
        writeAlignLen = Fee_CalcuAlignedLen(sizeof(uint32));

        /* Set write address. */
        writeAddr = Fee_SwapManagerInfo.SwapPartitionInfoSnap.BlockHeadAddr - writeAlignLen;

        /* Write valid flag to internal buffer. */
        FEE_MEMCPY((const uint8*)&validFlag, (uint8*)Fee_InterBuffer, sizeof(uint32));  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

        /* Write sector header to flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )

        rtrnValu = MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)writeAddr,
                                                      (const MemAcc_DataType*)Fee_InterBuffer,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                      (MemAcc_LengthType)writeAlignLen);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Write(writeAddr,
                                                      (const uint8*)Fee_InterBuffer,
                                                       writeAlignLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {

            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;

            /* Set job sate to write block head. */
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_BLOCK_DONE;
            /* Set current block valid flag. */
            Fee_SwapManagerInfo.SwapBlockHeadBackup.ValidFlag = FEE_VALID_ID;
        }
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        Fee_SwapRetry();
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapBlockDone
*
* Explanation: Action at the end of the swap.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapBlockDone(void)
{
    /* Check if the job result is ok. */
    if( MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult )
    {
        if( Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockProgramCounter >=
            Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].Fee_BlockHead_Dyn->BlockProgramCounter )
        {
            /* Copy backup block header to current block header. */

            Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].Fee_BlockHead_Dyn->BlockProgramCounter =
                Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockProgramCounter;
            Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].Fee_BlockHead_Dyn->BlockStartAddr =
                Fee_SwapManagerInfo.SwapBlockHeadBackup.BlockStartAddr;
            Fee_PartitionCfg.Fee_Block[Fee_SwapManagerInfo.SwapBlockIndex].Fee_BlockHead_Dyn->ValidFlag = FEE_VALID_ID;
        }

#if( MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO )
        Fee_SwapBlockRetryWriteCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

        /* Set job state to done. */
        Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_BLOCK_IDLE;
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        Fee_SwapRetry();
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapBlockJob
*
* Explanation: Service to scan valid block information.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapBlockJob(void)
{
    switch( Fee_SwapManagerInfo.SwapJob )
    {
        case FEE_JOB_SWAP_WRITE_BLOCK_HEAD:
            Fee_SwapWritedBlockHead();
            break;

        case FEE_JOB_SWAP_READ_BLOCK_DATA:
            Fee_SwapReadData();
            break;

        case FEE_JOB_SWAP_WRITE_BLOCK_DATA:
            Fee_SwapWritedBlockData();
            break;

        case FEE_JOB_SWAP_WRITE_BLOCK_VLDE:
            Fee_SwapWritedBlockVld();
            break;

        case FEE_JOB_SWAP_BLOCK_DONE:
            Fee_SwapBlockDone();
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: Fee_InternalErase
*
* Explanation: Internal erase process
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_InternalErase(void)
{
    Std_ReturnType rtrnValu;
    uint32 eraseAddress;
    uint32 eraseSize;

    if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        /* Check if the partition needs to be erased. */
        if( FEE_SECTOR_ERASE_ON == Fee_PartitionInfo.PartitionInfoSnap.EraseFlag )
        {
            /* Set erase address. */
            eraseAddress = Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.EraseSectorIndex].SectorStartAddr;
            /* Set erase size */
            eraseSize = Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.EraseSectorIndex].SectorSize;

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
            rtrnValu = MemAcc_Erase(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)eraseAddress,
                                                            (MemAcc_LengthType)eraseSize);
#else
            rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Erase(eraseAddress, eraseSize);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

            if( E_OK == rtrnValu )
            {
                /* Set fls job result to pending. */
                Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;

                /* Set job sate to erase done. */
                Fee_PartitionInfo.JobState = FEE_JOB_INTER_ERASE_DONE;
            }
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_InternalEraseDone
*
* Explanation: Internal erase process.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_InternalEraseDone(void)
{
    uint8 earseIndex;

    if( MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult )
    {
        earseIndex = Fee_PartitionInfo.PartitionInfoSnap.EraseSectorIndex;
        Fee_PartitionInfo.PartitionInfoSnap.EraseFlag = FEE_SECTOR_ERASE_OFF;
        if( FEE_SECTOR_NEED_ERASE != Fee_PartitionCfg.Fee_SectorHead[earseIndex].Fee_SectorCurrentInfo->SectorState )
        {
            Fee_PartitionInfo.SectorFreeNum++;
        }
        else
        {
            Fee_ScanManagerInfo.ScanSectorNeedEraseNum--;
        }
        Fee_PartitionCfg.Fee_SectorHead[earseIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_FREE;
        /* Set job sate to job done. */
        Fee_PartitionInfo.JobState = Fee_PartitionInfo.PartitionInfoSnap.EraseNextState;

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        /* clean retry counter */
        Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        /* Set job state to internal erase. */
        if( Fee_RetryCounter < MAX_NUM_SCAN_RETRYIES )
        {
            Fee_RetryCounter++;
            /* Set job state to internal erase. */
            Fee_PartitionInfo.JobState = FEE_JOB_INTER_ERASE;
        }
        else
        {
            /* clean retry counter. */
            Fee_RetryCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

            Fee_PartitionInfo.PartitionInfoSnap.EraseFlag = FEE_SECTOR_ERASE_OFF;
            Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.EraseSectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_BAD;
            /* Set the sector is bad. */
            Fee_BadSectorProc();

#if( MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO )
        }
#endif /* MAX_NUM_SCAN_RETRYIES > FEE_VALUE_ZERO */

    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_InternalSwapErase
*
* Explanation: Internal swap erase process.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_InternalSwapErase(void)
{
    Std_ReturnType rtrnValu;
    uint32 eraseAddress;
    uint32 eraseSize;

    if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        /* Check if the partition needs to be erased. */
        if( FEE_SECTOR_ERASE_ON == Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseFlag )
        {
            /* Set erase address. */
            eraseAddress = Fee_PartitionCfg.Fee_SectorHead[Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseSectorIndex].SectorStartAddr;
            /* Set erase size. */
            eraseSize = Fee_PartitionCfg.Fee_SectorHead[Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseSectorIndex].SectorSize;

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
            rtrnValu = MemAcc_Erase(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)eraseAddress,
                                                            (MemAcc_LengthType)eraseSize);
#else
            rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Erase(eraseAddress, eraseSize);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

            if( E_OK == rtrnValu )
            {
                /* Set fls job result to pending. */
                Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;

                /* Set job sate to erase done. */
                Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_ERASE_DONE;
            }
        }
    }
}

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Fee_UpdateReservedSector
*
* Explanation: Update reserved sector status.
*
* param: SectorIndex: Determine whether to update the sector index.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
static FUNC(void, FEE_CODE) Fee_UpdateReservedSector( uint8 SectorIndex )
{
    uint8 reservedSectorIndex;

    if( E_OK == Fee_BackwardGetSector(FEE_SECTOR_RESERVED_FREE, FEE_SECTOR_DEF, &reservedSectorIndex) )
    {
        if( FEE_VALUE_ZERO < SectorIndex )
        {
            if( SectorIndex > reservedSectorIndex )
            {
                Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_RESERVED_FREE;
                Fee_PartitionCfg.Fee_SectorHead[reservedSectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_FREE;
            }
        }
        else
        {
            if( (SectorIndex < reservedSectorIndex) && (Fee_PartitionInfo.PartitionInfoSnap.SectorIndex < reservedSectorIndex) )
            {
                Fee_PartitionCfg.Fee_SectorHead[SectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_RESERVED_FREE;
                Fee_PartitionCfg.Fee_SectorHead[reservedSectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_FREE;
            }
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: Fee_InternalSwapEraseDone
*
* Explanation: Internal swap erase process end.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_InternalSwapEraseDone(void)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 earseIndex = Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseSectorIndex;
    uint8 reservedActivateIndex;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    Fee_SectorStatusType sectorState = Fee_PartitionCfg.Fee_SectorHead[earseIndex].Fee_SectorCurrentInfo->SectorState;

    if( MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult )
    {
        Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseFlag = FEE_SECTOR_ERASE_OFF;

        Fee_SwapManagerInfo.SectorSwapState = FEE_SWAP_IDLE;

        /* Set job sate to job done. */
        Fee_SwapManagerInfo.SwapJob = Fee_SwapManagerInfo.SwapPartitionInfoSnap.SwapEraseNextState;
        if( FEE_SECTOR_IMM_SWAP_NEED_ERASE != sectorState )
        {
            if( FEE_SECTOR_BAD_NEED_SWAP == sectorState )
            {
                Fee_PartitionCfg.Fee_SectorHead[earseIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_BAD;
                Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_OFF;
                Fee_UpdateSwapRequest();
            }
            else if( FEE_SECTOR_NEED_ERASE == sectorState )
            {
                Fee_PartitionCfg.Fee_SectorHead[earseIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_FREE;
                Fee_ScanManagerInfo.ScanSectorNeedEraseNum--;
                Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_OFF;
            }
            else
            {
                Fee_PartitionCfg.Fee_SectorHead[earseIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_FREE;
                Fee_PartitionInfo.SectorFreeNum++;
                if( FEE_VALUE_ZERO != Fee_PartitionInfo.SectorFullNum )
                {
                    Fee_PartitionInfo.SectorFullNum--;
                }
                if( Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize >= Fee_ScanManagerInfo.ReservedImmLen )
                {
                    if( E_OK == Fee_ForwardGetSector(FEE_SECTOR_RESERVED_ACTIVATE, FEE_SECTOR_DEF, &reservedActivateIndex) )
                    {
                        Fee_UpdatePattitionInfo(reservedActivateIndex);
                    }
                }

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
                Fee_UpdateReservedSector(earseIndex);
#endif /* ( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON ) */

                Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_OFF;
                Fee_UpdateSwapRequest();
            }

#if(MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO)
            /* Clean retry counter. */
            Fee_SwapBlockRetryEraseCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

        }
        else
        {
            Fee_PartitionInfo.JobState = Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseNextState;
        }
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {

#if(MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO)
        if( Fee_SwapBlockRetryEraseCounter < MAX_NUM_INTER_ERROR_RETRYIES )
        {
            Fee_SwapBlockRetryEraseCounter++;
            /* Set job state to internal erase. */
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_ERASE;
        }
        else
        {
            /* Clean retry counter. */
            Fee_SwapBlockRetryEraseCounter = FEE_VALUE_ZERO;
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

            if( FEE_SECTOR_BAD_NEED_SWAP != sectorState )
            {
                if( FEE_VALUE_ZERO != Fee_PartitionInfo.SectorFullNum )
                {
                    Fee_PartitionInfo.SectorFullNum--;
                }
                /* Update Fee_PartitionInfo.TriggerSwapThreshold. */
                Fee_BadSectorProc();
            }
            Fee_PartitionCfg.Fee_SectorHead[earseIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_BAD;
            /* Set job sate to job done. */
            Fee_SwapManagerInfo.SwapJob = Fee_SwapManagerInfo.SwapPartitionInfoSnap.SwapEraseNextState;
            Fee_SwapManagerInfo.SectorSwapState = FEE_SWAP_IDLE;
            Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_OFF;
            if( FEE_SECTOR_NEED_ERASE != sectorState )
            {
                Fee_UpdateSwapRequest();
            }

#if(MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO)
        }
#endif /* MAX_NUM_INTER_ERROR_RETRYIES > FEE_VALUE_ZERO */

    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_InternalEraseJob
*
* Explanation: Service to erase flash sector.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_InternalEraseJob(void)
{
    switch( Fee_PartitionInfo.JobState )
    {
        case FEE_JOB_INTER_ERASE:
            Fee_InternalErase();
            break;

        case FEE_JOB_INTER_ERASE_DONE:
            Fee_InternalEraseDone();
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapInternalEraseJob
*
* Explanation: Service to erase flash sector.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapInternalEraseJob(void)
{
    switch( Fee_SwapManagerInfo.SwapJob )
    {
        case FEE_JOB_SWAP_ERASE:
            Fee_InternalSwapErase();
            break;

        case FEE_JOB_SWAP_ERASE_DONE:
            Fee_InternalSwapEraseDone();
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: Fee_ChangePartintionSector
*
* Explanation: Change Partintion Sector from Free.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ChangePartintionSector(void)
{
    uint8 idleSectorIndex = FEE_VALUE_ZERO;

    if( E_OK == Fee_ForwardGetSector(FEE_SECTOR_FREE, FEE_SECTOR_NEED_ERASE, &idleSectorIndex) )
    {
        Fee_UpdatePattitionInfo(idleSectorIndex);
    }
    else
    {
        Fee_ErrorDeal();
    }
}

/*
********************************************************************************
* Function Name: Fee_CheckWriteSpace
*
* Explanation: Write block head to flash.Determine if it is still possible to write.
*
* param: WriteLen : The length of user data that needs to be written.
*
* retval: E_OK : The current Sector is able to write.
*         E_NOT_OK : The current Sector is not sufficient to write.
********************************************************************************
*/
/* polyspace-begin MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
static FUNC(Std_ReturnType, FEE_CODE) Fee_CheckWriteSpace(uint16 WriteLen)
{
    Std_ReturnType rtrnValu = E_OK;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    uint32 blockIndex;
    /* polyspace-end MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
    uint8 actSectorIndex;

    if( (Fee_PartitionInfo.SectorFreeNum != FEE_VALUE_ONE) || (TRUE == Fee_PartitionInfo.ReservedActive) || (FEE_VALUE_ZERO == Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize) )
    {
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

        /* Check if need swap operation. */
        if( (Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize < (Fee_JobManagerInfo.BlockHeadAligned + Fee_CalcuAlignedLen(WriteLen))) ||
            (Fee_PartitionInfo.BlockWriteCounterInSector >= FEE_SECTOR_MAX_BLOCK_NUMBER) )
        {

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
            if( Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState != FEE_SECTOR_RESERVED_ACTIVATE )
            {
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

                if( FEE_SECTOR_IMMEDIATELY_SWAP_ON != Fee_SwapManagerInfo.SwapRequest )
                {
                    if( FEE_JOB_WRITE_HED == Fee_PartitionInfo.JobState )
                    {
                        /* The user request caused the sector to be filled, and the request needs
                           to be recorded before continuing to execute the request after switching sectors. */
                        Fee_PartitionInfo.JobNextState = Fee_PartitionInfo.JobState;
                        Fee_ModuleNextState = Fee_ModuleState;
                        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
                    }
                    Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_FULL;
                    Fee_PartitionInfo.SectorFullNum++;
                    Fee_ChangePartintionSector();
                    Fee_UpdateSwapRequest();
                    rtrnValu = E_NOT_OK;
                }
                else
                {
                    /* Full sectors caused by immediate page swapping require RAM data recovery
                       and a new immediate page swapping action. */
                    Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState =
                        FEE_SECTOR_IMM_SWAP_NEED_ERASE;
                    Fee_PartitionInfo.SectorFreeNum++;
                    for( blockIndex = FEE_VALUE_ZERO; blockIndex < FEE_BLOCK_NUMBER; blockIndex++ )
                    {
                        Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->BlockStartAddr = Fee_BlockHeadAddrBackUp[blockIndex];
                    }
                    Fee_UpdatePattitionInfo(sectorIndex);
                    rtrnValu = E_NOT_OK;
                }

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
            }
            else
            {
                if( E_OK == Fee_ForwardGetSector(FEE_SECTOR_ACTIVATE, FEE_SECTOR_IMM_SWAP_NEED_ERASE, &actSectorIndex) )
                {
                    if( FEE_JOB_WRITE_HED == Fee_PartitionInfo.JobState )
                    {
                        /* The user request caused the sector to be filled, and the request needs
                           to be recorded before continuing to execute the request after switching sectors. */
                        Fee_PartitionInfo.JobNextState = Fee_PartitionInfo.JobState;
                        Fee_ModuleNextState = Fee_ModuleState;
                        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
                    }
                    Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_FULL;
                    Fee_PartitionInfo.ReservedActive = FALSE;
                    Fee_UpdatePattitionInfo(actSectorIndex);
                    rtrnValu = E_NOT_OK;
                }
                else
                {
                    Fee_ErrorDeal();
                }
            }
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

        }

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
    }
    /* When there is only one free sector left and an immediate page change occurs,
       it is necessary to reserve an active sector for immediate write operations. */
    else
    {
        if( (Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize <
             (Fee_JobManagerInfo.BlockHeadAligned + Fee_CalcuAlignedLen(Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen) + Fee_ScanManagerInfo.ReservedImmLen)) ||
             (Fee_PartitionInfo.BlockWriteCounterInSector >= FEE_SECTOR_MAX_BLOCK_NUMBER) )
        {
            Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_RESERVED_ACTIVATE;
            Fee_PartitionInfo.ReservedActive = TRUE;
            Fee_PartitionInfo.SectorFullNum++;
            if( FEE_JOB_WRITE_HED == Fee_PartitionInfo.JobState )
            {
                Fee_PartitionInfo.JobNextState = Fee_PartitionInfo.JobState;
                Fee_ModuleNextState = Fee_ModuleState;
                Fee_PartitionInfo.JobState = FEE_JOB_DONE;
            }
            Fee_ChangePartintionSector();
            Fee_UpdateSwapRequest();
            rtrnValu = E_NOT_OK;
        }
    }
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_JobWriteBlockHead
*
* Explanation: Write block head to flash.
*
* param: TRUE : The subsequent state machine is FEE_JOB_WRITE_DATA.
*        FALSE : The subsequent state machine is FEE_JOB_ERASE_BlOCK_UNVLD
*                or FEE_JOB_ERASE_BlOCK_UNVLD.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
static FUNC(void, FEE_CODE) Fee_JobWriteBlockHead(boolean validFlag)
{
    Std_ReturnType rtrnValu = E_OK;
    uint32 writeAlignLen;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 writeLen;
    uint32 writeAddr;

    /* Check if the job result is ok and the block index is in the range. */
    if( (MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult) && (Fee_JobManagerInfo.JobBlockIndex < Fee_PartitionCfg.BlockTotalNum) )
    {

        rtrnValu = Fee_CheckWriteSpace(Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen);

        if( E_OK == rtrnValu )
        {
            /* set current block header write address. */
            writeAddr = Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr;

            /* Set current sector header write length. */
            /* Sector header size except valid flag. */
            writeLen = (uint16)(sizeof(Fee_BlockHeadRomType) - sizeof(uint32));

            /* Backup current block header information. */

            /* Set the block number of the current sector. */
            Fee_JobManagerInfo.JobBlockHeadBackup.BlockNumber =
                Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].BlockNumber;
            /* Set the block size of the current sector. */
            Fee_JobManagerInfo.JobBlockHeadBackup.BlockSize =
                Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].BlockSize;
            Fee_JobManagerInfo.JobBlockHeadBackup.BlockProgramCounter =
                Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].Fee_BlockHead_Dyn->BlockProgramCounter;

            /* Update the block write address of the current sector. */
            Fee_JobManagerInfo.JobBlockHeadBackup.BlockStartAddr
                = Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr - Fee_CalcuAlignedLen(Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen);

            /* Number of sector writes plus one. */
            Fee_JobManagerInfo.JobBlockHeadBackup.BlockProgramCounter++;

            /* Calculation sector header checksum. */
            Fee_JobManagerInfo.JobBlockHeadBackup.BlockCheck = Fee_CheckSum((const uint8*)(&Fee_JobManagerInfo.JobBlockHeadBackup), Fee_CalcuCheckSumLen);  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

            /* Set block valid flag to default. */
            Fee_JobManagerInfo.JobBlockHeadBackup.ValidFlag = FEE_DEFAULT_VALID_ID;

            /* Write block header to internal buffer. */
            FEE_MEMCPY((const uint8 *)&Fee_JobManagerInfo.JobBlockHeadBackup, (uint8 *)Fee_InterBuffer, writeLen);  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

            /* Calculate the alignment length. */
            writeAlignLen = Fee_CalcuAlignedLen(writeLen);

            /* Write sector header to flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
            rtrnValu = MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)writeAddr,
                                                           (const MemAcc_DataType*)Fee_InterBuffer,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                           (MemAcc_LengthType)writeAlignLen);

#else
            rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Write(writeAddr,
                                                          (const uint8*)Fee_InterBuffer,
                                                           writeAlignLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

            if( E_OK == rtrnValu )
            {
                /* Set fls job result to pending. */
                Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;

                /* Update current sector last size. */
                Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize =
                    Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize - Fee_JobManagerInfo.BlockHeadAligned;

                /* Update current block header address. */
                Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr =
                    Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr + Fee_JobManagerInfo.BlockHeadAligned;

                /* Update Sector block header address. */
                Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->BlockHeadAddr =
                    Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr;

                Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorLastSize =
                    Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize;

                /* Increase Fee Write Block Count. */
                Fee_PartitionInfo.BlockWriteCounterInSector++;

                Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->BlockWriteCounterInSector =
                    Fee_PartitionInfo.BlockWriteCounterInSector;

                if( (FALSE == validFlag) && (FEE_JOB_INVAL_BLOCK == Fee_PartitionInfo.JobState) )
                {
                    /* Set job sate to FEE_JOB_INVAL_BLOCK_DONE. */
                    Fee_PartitionInfo.JobState = FEE_JOB_INVAL_BLOCK_UNVLD;
                }
                else if( (FALSE == validFlag) && (FEE_JOB_ERASE_BlOCK == Fee_PartitionInfo.JobState) )
                {
                    /* Set job sate to FEE_JOB_ERASE_IMMEDIATE_DONE. */
                    Fee_PartitionInfo.JobState = FEE_JOB_ERASE_BlOCK_UNVLD;
                }
                else
                {
                    /* Set job sate to read block data. */
                    Fee_PartitionInfo.JobState = FEE_JOB_WRITE_DATA;
                    /* Set the clear internal variable flag. */
                    Fee_ClearStaticVariable = TRUE;
                }
            }
            else
            {
                /* Set fls job result to failed. */
                Fee_JobManagerInfo.JobResult = MEMIF_JOB_FAILED;
                /* Set job state to done. */
                Fee_PartitionInfo.JobState = FEE_JOB_DONE;
                /* Update Fee module state. */
                Fee_ModuleState = MEMIF_IDLE;

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
                Fee_ImmWriteDone();
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

            }
        }

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
        else
        {
            Fee_ImmWriteDone();
        }
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

    }
}

/*
********************************************************************************
* Function Name: Fee_JobWriteBlockData
*
* Explanation: Service to write block data to flash.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_JobWriteBlockData(void)
{
    Std_ReturnType rtrnValu;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    uint16 i;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint32 writeLen;
    uint32 writeAddr;
    const uint8* srcAddress;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 *bufferPtr = (uint8 *)&Fee_InterBuffer[FEE_VALUE_ZERO];  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

    if( MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult )
    {
        /* Clear write block head consecutive failure count. */
        Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorWriteFailedCounter = FEE_VALUE_ZERO;

        /* Judge if need to clear the static variable. */
        if( TRUE == Fee_ClearStaticVariable )
        {
            Fee_JobManagerInfo.WriteJobProcessedLen = FEE_VALUE_ZERO;
            Fee_JobManagerInfo.WriteJobStartAddr = Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr -
                Fee_CalcuAlignedLen(Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen);
        }
        /* Set write length. */
        writeLen = Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen;

        /* Set sources address. */
        srcAddress = Fee_PartitionInfo.WriteDataBufferPtr;
        /* First, write the alignment section. */
        if( writeLen >= FEE_VIRTUAL_PAGE_SIZE )
        {
            if( writeLen <= FEE_WRITE_BUFFER_SIZE )
            {
                writeLen = (writeLen / FEE_VIRTUAL_PAGE_SIZE) * FEE_VIRTUAL_PAGE_SIZE;
            }
            else
            {
                writeLen = FEE_WRITE_BUFFER_SIZE;
            }
            /* Copy user data to InterBuffer. */
            for( i = FEE_VALUE_ZERO; i < writeLen; i++ )
            {
                bufferPtr[i] = srcAddress[Fee_JobManagerInfo.WriteJobProcessedLen + i];
            }
        }
        /* Then, write all the remaining bytes. */
        else
        {
            for( i = FEE_VALUE_ZERO; i < writeLen; i++ )
            {
                bufferPtr[i] = srcAddress[Fee_JobManagerInfo.WriteJobProcessedLen + i];
            }
            writeLen = FEE_VIRTUAL_PAGE_SIZE;
            srcAddress = &bufferPtr[FEE_VALUE_ZERO];
            Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen = (uint16)writeLen;
        }

        /* Update next write address. */
        writeAddr = Fee_JobManagerInfo.WriteJobStartAddr + Fee_JobManagerInfo.WriteJobProcessedLen;

        /* Write sector header to flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)writeAddr,
                                                       (const MemAcc_DataType*)bufferPtr,
                                                       (MemAcc_LengthType)writeLen);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Write(writeAddr,
                                                      (const uint8*)bufferPtr,
                                                       writeLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            if( TRUE == Fee_ClearStaticVariable )
            {
                /* Set the flag to FALSE. */
                Fee_ClearStaticVariable = FALSE;

                /* Update the block write address of the current sector. */
                Fee_PartitionInfo.PartitionInfoSnap.BlockDataAddr = writeAddr;
                /* Update the Sector block write address */
                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->BlockDataAddr = writeAddr;

                /* Set current sector last size. */
                Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize = (uint32)(Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize -
                    Fee_CalcuAlignedLen(Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen));
                Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorLastSize =
                    Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize;
            }

            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;

            /* Update next write size. */
            Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen =
                (uint16)(Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen - writeLen);

            /* Update write total length. */
            Fee_JobManagerInfo.WriteJobProcessedLen = (uint32)(Fee_JobManagerInfo.WriteJobProcessedLen + writeLen);

            /* Check if the block has write finish. */
            /* polyspace +1 MISRA-C3:12.1 [Justified:Unset] "NSCA_Polyspace_Fee_Rule12.1" */
            if( (srcAddress == &bufferPtr[FEE_VALUE_ZERO])
                || (FEE_VALUE_ZERO == Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen) )
            {
                /* Clear total length. */
                Fee_JobManagerInfo.WriteJobProcessedLen = FEE_VALUE_ZERO;

                /* Set job sate to write block head. */
                Fee_PartitionInfo.JobState = FEE_JOB_WRITE_VALIDATE;
            }
        }
        else
        {
            /* Set job state to done. */
            Fee_JobManagerInfo.JobResult = MEMIF_JOB_FAILED;
            Fee_PartitionInfo.JobState = FEE_JOB_DONE;
            /* Update Fee module state */
            Fee_ModuleState = MEMIF_IDLE;

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
            Fee_ImmWriteDone();
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

        }
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        /* Set job state to done. */
        Fee_JobManagerInfo.JobResult = Fee_JobManagerInfo.FlsJobResult;
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;

        Fee_SectorWriteFailedDeal(sectorIndex);

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
        Fee_ImmWriteDone();
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_JobWriteBlockVld
*
* Explanation: Write block valid flag.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_JobWriteBlockVld(void)
{
    Std_ReturnType rtrnValu;
    uint32 writeAignLen;
    uint32 writeAddr;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint32 validFlag = FEE_VALID_ID;

    /* Check if the job result is ok and the block index is in the range. */
    if( (MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult) )
    {
        /* Calculate the valid identifier alignment length. */
        writeAignLen = Fee_CalcuAlignedLen(sizeof(uint32));

        /* Set write address. */
        writeAddr = Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr - writeAignLen;

        /* Write valid flag to internal buffer. */
        FEE_MEMCPY((const uint8*)&validFlag, (uint8*)Fee_InterBuffer, sizeof(uint32));  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

        /* Write sector header to flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)writeAddr,
                                                       (const MemAcc_DataType*)Fee_InterBuffer,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                       (MemAcc_LengthType)writeAignLen);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Write(writeAddr,
                                                      (const uint8*)Fee_InterBuffer,
                                                       writeAignLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;
            /* Set job state to write job done. */
            Fee_PartitionInfo.JobState = FEE_JOB_WRITE_DONE;
            /* Set current block valid flag. */
            Fee_JobManagerInfo.JobBlockHeadBackup.ValidFlag = FEE_VALID_ID;
        }
        else
        {
            /* Set fls job result to failed. */
           Fee_JobManagerInfo.JobResult = MEMIF_JOB_FAILED;
           /* Set job sate to done. */
           Fee_PartitionInfo.JobState = FEE_JOB_DONE;
           /* Update Fee module state. */
           Fee_ModuleState = MEMIF_IDLE;

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
           Fee_ImmWriteDone();
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

        }
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        Fee_JobManagerInfo.JobResult = Fee_JobManagerInfo.FlsJobResult;
        /* Set job state to done. */
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
        Fee_ImmWriteDone();
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

    }
    else
    {
        /* Nothing to do. */
    }
}

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Fee_ImmWriteDone
*
* Explanation: Immediately Write block Done.
*
* param: None
*
* retval: None
********************************************************************************
*/
/* polyspace-begin MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
static FUNC(void, FEE_CODE) Fee_ImmWriteDone(void)
{
    uint8 actSectorIndex;
    uint32 sectorAddressEnd;
    uint32 sectorAddressStart;
    uint32 blockIndex;
    /* polyspace-end MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */

    if( FEE_IMM_WRITE_ON_SWAP == Fee_PartitionInfo.ImmWriteState )
    {
        if( Fee_PartitionInfo.SwapJobBackUp < FEE_JOB_SWAP_BLOCK_IDLE )
        {
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_WRITE_BLOCK_HEAD;
        }
        else if( (Fee_PartitionInfo.SwapJobBackUp >= FEE_JOB_SWAP_ERASE) &&
                 (Fee_PartitionInfo.SwapJobBackUp <= FEE_JOB_SWAP_ERASE_DONE) )
        {
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_ERASE;
        }
        else
        {
            /* Nothing to do. */
        }
        Fee_PartitionInfo.RecoverSwapTimer = FEE_IMM_WRITE_TIMER_DELAY;
    }
    else if( FEE_IMM_WRITE_ON_IMM_SWAP == Fee_PartitionInfo.ImmWriteState )
    {
        if( E_OK == Fee_ForwardGetSector(FEE_SECTOR_ACTIVATE, FEE_SECTOR_IMM_SWAP_NEED_ERASE, &actSectorIndex) )
        {
            Fee_UpdatePattitionInfo(actSectorIndex);
            if( FEE_SECTOR_WRITE_FAILED_NUM <=
                Fee_PartitionCfg.Fee_SectorHead[actSectorIndex].Fee_SectorCurrentInfo->SectorWriteFailedCounter )
            {
                Fee_PartitionCfg.Fee_SectorHead[actSectorIndex].Fee_SectorCurrentInfo->SectorWriteFailedCounter = FEE_VALUE_ZERO;
                Fee_PartitionCfg.Fee_SectorHead[actSectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_WRITE_FAILED;
            }
            /* The remaining space is insufficient to complete the immediate page change operation. RAM data
               will be restored and the current sector will be erased, and the immediate page change operation will be redone. */
            if( Fee_PartitionInfo.SwapJobBackUp < FEE_JOB_SWAP_BLOCK_IDLE )
            {
                sectorAddressStart = Fee_PartitionCfg.Fee_SectorHead[Fee_SwapManagerInfo.SourceSectorIndex].SectorStartAddr;
                sectorAddressEnd = Fee_PartitionCfg.Fee_SectorHead[Fee_SwapManagerInfo.SourceSectorIndex].SectorStartAddr +
                                    Fee_PartitionCfg.Fee_SectorHead[Fee_SwapManagerInfo.SourceSectorIndex].SectorSize;
                Fee_GetSwapSize(sectorAddressStart, sectorAddressEnd);
                if( (Fee_SwapManagerInfo.ImmSwapNeedSize < Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize) &&
                    (FEE_SECTOR_WRITE_FAILED != Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorState) )
                {
                    Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_WRITE_BLOCK_HEAD;
                }
                else
                {
                    Fee_PartitionCfg.Fee_SectorHead[Fee_PartitionInfo.PartitionInfoSnap.SectorIndex].Fee_SectorCurrentInfo->SectorState =
                        FEE_SECTOR_IMM_SWAP_NEED_ERASE;
                    Fee_PartitionInfo.SectorFreeNum++;
                    for( blockIndex = FEE_VALUE_ZERO; blockIndex < FEE_BLOCK_NUMBER; blockIndex++ )
                    {
                        Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->BlockStartAddr = Fee_BlockHeadAddrBackUp[blockIndex];
                    }
                    Fee_UpdatePattitionInfo(Fee_PartitionInfo.PartitionInfoSnap.SectorIndex);
                }
            }
            else if( (Fee_PartitionInfo.SwapJobBackUp == FEE_JOB_SWAP_ERASE) ||
                     (Fee_PartitionInfo.SwapJobBackUp == FEE_JOB_SWAP_ERASE_DONE) )
            {
                Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_ERASE;
            }
            else
            {
                /* Nothing to do. */
            }
        }
        else
        {
            Fee_ErrorDeal();
        }
        Fee_PartitionInfo.RecoverSwapTimer = FEE_IMM_WRITE_TIMER_DELAY;
    }
    else
    {
        /* Nothing to do. */
    }
    Fee_PartitionInfo.ImmWriteState = FEE_IMM_WRITE_DONE;
}
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

/*
********************************************************************************
* Function Name: Fee_JobWriteBlockDone
*
* Explanation: Write block Done.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_JobWriteBlockDone(void)
{
    /* Check if the job result is ok and the block index is in the range. */
    if( (MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult) )
    {
        /* Copy backup block header to current block header. */

        Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].Fee_BlockHead_Dyn->BlockProgramCounter =
            Fee_JobManagerInfo.JobBlockHeadBackup.BlockProgramCounter;
        Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].Fee_BlockHead_Dyn->BlockStartAddr =
            Fee_JobManagerInfo.JobBlockHeadBackup.BlockStartAddr;
        Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].Fee_BlockHead_Dyn->ValidFlag =
            Fee_JobManagerInfo.JobBlockHeadBackup.ValidFlag;

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )

        if( FEE_IMM_WRITE_ON_IMM_SWAP == Fee_PartitionInfo.ImmWriteState )
        {
            Fee_BlockHeadAddrBackUp[Fee_JobManagerInfo.JobBlockIndex] =
                Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].Fee_BlockHead_Dyn->BlockStartAddr;
        }
#endif /* ( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON ) */

        /* Set fls job result to ok. */
        Fee_JobManagerInfo.JobResult = MEMIF_JOB_OK;
        /* Set job state to done. */
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
        Fee_ImmWriteDone();
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        /* Set fls job result to failed. */
        Fee_JobManagerInfo.JobResult = Fee_JobManagerInfo.FlsJobResult;
        /* Set job state to done. */
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
        Fee_ImmWriteDone();
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_WriteJob
*
* Explanation: Processing flow of writing Block data.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_WriteJob(void)
{
    switch( Fee_PartitionInfo.JobState )
    {
        case FEE_JOB_WRITE_HED:
            Fee_JobWriteBlockHead(TRUE);
            break;

        case FEE_JOB_WRITE_DATA:
            Fee_JobWriteBlockData();
            break;

        case FEE_JOB_WRITE_VALIDATE:
            Fee_JobWriteBlockVld();
            break;

        case FEE_JOB_WRITE_DONE:
            Fee_JobWriteBlockDone();
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: Fee_ReadJobRequest
*
* Explanation: Service to request read block data from flash.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ReadJobRequest(void)
{
    Std_ReturnType rtrnValu;
    uint16 readLen;
    uint32 readAddress;
    uint8 *desAddress;

    if( FEE_VALID_ID == Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].Fee_BlockHead_Dyn->ValidFlag )
    {
        /* Check if the job result is ok. */
        if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
        {
            /* Set read length. */
            readLen = Fee_PartitionInfo.PartitionInfoSnap.BlockReadlen;

            /* Set read address. */
            readAddress = Fee_PartitionInfo.PartitionInfoSnap.BlockReadDataAddr +
                Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].Fee_BlockHead_Dyn->BlockStartAddr;

            /* Set destination address. */
            desAddress = Fee_PartitionInfo.ReadDataBufferPtr;

            /* Call read flash function. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
            rtrnValu = MemAcc_Read(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)readAddress,
                                                        (MemAcc_DataType *)desAddress, (MemAcc_LengthType)readLen);
#else
            rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Read(readAddress, desAddress, readLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

            if( E_OK == rtrnValu )
            {
                /* Set fls job result to pending. */
                Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;
                Fee_PartitionInfo.JobState = FEE_JOB_READ_DONE;
            }
            else
            {
                /* Set fls job result to failed. */
                Fee_JobManagerInfo.JobResult = MEMIF_JOB_FAILED;
                /* Set job state to write block. */
                Fee_PartitionInfo.JobState = FEE_JOB_DONE;
                /* Update Fee module state. */
                Fee_ModuleState = MEMIF_IDLE;
            }
        }
    }
    else if( FEE_INVALID_ID == Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].Fee_BlockHead_Dyn->ValidFlag )
    {
        /* Set fee job result to invalid. */
        Fee_JobManagerInfo.JobResult = MEMIF_BLOCK_INVALID;
        /* Set job state to write block. */
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;
    }
    else
    {
        /* Set fee job result to invalid. */
        Fee_JobManagerInfo.JobResult = MEMIF_BLOCK_INCONSISTENT;
        /* Set job state to write block. */
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;
    }
}

/*
********************************************************************************
* Function Name: Fee_ReadJobDone
*
* Explanation: Service to read block data from flash end.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ReadJobDone(void)
{
    if( MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult )
    {
        /* Set fee job result to ok. */
        Fee_JobManagerInfo.JobResult = MEMIF_JOB_OK;
        /* Set job state to done. */
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        /* Set fee job result to failed. */
        Fee_JobManagerInfo.JobResult = Fee_JobManagerInfo.FlsJobResult;
        /* Set job state to done. */
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_Readjob
*
* Explanation: Service to read block data from flash.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ReadJob(void)
{
    switch( Fee_PartitionInfo.JobState )
    {
        case FEE_JOB_READ:
            Fee_ReadJobRequest();
            break;

        case FEE_JOB_READ_DONE:
            Fee_ReadJobDone();
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: Fee_JobWritedBlockUnvld
*
* Explanation: Write block unvalid flag.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_JobWritedBlockUnvld(void)
{
    Std_ReturnType rtrnValu;
    uint32 writeAignLen;
    uint32 writeAddr;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint32 validFlag = FEE_INVALID_ID;

    /* Check if the job result is ok and the block index is in the range */
    if( (MEMIF_JOB_OK == Fee_JobManagerInfo.FlsJobResult) )
    {
        /* Calculate the valid identifier alignment length. */
        writeAignLen = Fee_CalcuAlignedLen(sizeof(uint32));

        /* Set write address. */
        writeAddr = Fee_PartitionInfo.PartitionInfoSnap.BlockHeadAddr - writeAignLen;

        /* Write valid flag to internal buffer. */
        FEE_MEMCPY((const uint8*)&validFlag, (uint8*)Fee_InterBuffer, sizeof(uint32));  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */

        /* Write sector header to flash. */
#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
        rtrnValu = MemAcc_Write(FEE_MEMACC_ADDRESS_AREA_ID, (MemAcc_AddressType)writeAddr,
                                                       (const MemAcc_DataType*)Fee_InterBuffer,  /* PRQA S 310 */ /* NSCA_QAC_Fee_Rule11.3 */
                                                       (MemAcc_LengthType)writeAignLen);
#else
        rtrnValu = Fee_PartitionCfg.Fls_FunctionList->Write(writeAddr,
                                                      (const uint8*)Fee_InterBuffer,
                                                       writeAignLen);
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        if( E_OK == rtrnValu )
        {
            /* Set fls job result to pending. */
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_PENDING;
            /* Set current block unvalid flag. */
            Fee_JobManagerInfo.JobBlockHeadBackup.ValidFlag = FEE_INVALID_ID;

            if( (FEE_JOB_INVAL_BLOCK_UNVLD == Fee_PartitionInfo.JobState) )
            {
                /* Set job sate to FEE_JOB_INVAL_BLOCK_DONE. */
                Fee_PartitionInfo.JobState = FEE_JOB_INVAL_BLOCK_DONE;
            }
            else if( (FEE_JOB_ERASE_BlOCK_UNVLD == Fee_PartitionInfo.JobState) )
            {
                /* Set job sate to FEE_JOB_ERASE_IMMEDIATE_DONE. */
                Fee_PartitionInfo.JobState = FEE_JOB_ERASE_IMMEDIATE_DONE;
            }
            else
            {
                /* Nothing to do. */
            }
        }
        else
        {
            /* Set fls job result to failed. */
            Fee_JobManagerInfo.JobResult = MEMIF_JOB_FAILED;
            /* Set job sate to done. */
            Fee_PartitionInfo.JobState = FEE_JOB_DONE;
            /* Update Fee module state. */
            Fee_ModuleState = MEMIF_IDLE;
        }
    }
    else if( MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult )
    {
        /* Set fls job result to failed. */
        Fee_JobManagerInfo.JobResult = Fee_JobManagerInfo.FlsJobResult;
        /* Set job state to done. */
        Fee_PartitionInfo.JobState = FEE_JOB_DONE;
        /* Update Fee module state. */
        Fee_ModuleState = MEMIF_IDLE;
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_EraseJob
*
* Explanation: Service to scan valid block information.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_EraseJob(void)
{
    switch( Fee_PartitionInfo.JobState )
    {
        case FEE_JOB_ERASE_BlOCK:
            Fee_JobWriteBlockHead(FALSE);
            break;

        case FEE_JOB_ERASE_BlOCK_UNVLD:
            Fee_JobWritedBlockUnvld();
            break;

        case FEE_JOB_ERASE_IMMEDIATE_DONE:
            Fee_JobWriteBlockDone();
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: Fee_SectorBuildHeadJob
*
* Explanation: Build sector head.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SectorBuildHeadJob(void)
{
    switch( Fee_PartitionInfo.JobState )
    {
        case FEE_JOB_WRITE_SEC_HEAD:
            Fee_SwapWritedSectorHead();
            break;

        case FEE_JOB_WRITE_SEC_TAIL:
            Fee_SwapWritedSectorTail();
            break;

        case FEE_JOB_SEC_HEAD_DONE:
            Fee_WritedSectorHeadDone();
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: Fee_GetSwapSector
*
* Explanation: Fee get Swap sector.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_GetSwapSector(void)
{
    boolean loop = TRUE;
    uint8 Index_temp = (Fee_PartitionInfo.PartitionInfoSnap.SectorIndex + FEE_VALUE_ONE);
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint8 sectorIndex;

    /* When the current sector swap finish, search for the next sector. */
    if( FEE_SWAP_IDLE == Fee_SwapManagerInfo.SectorSwapState )
    {
        /* cyclic query need swap sector. */
        while( TRUE == loop )
        {
            for( sectorIndex = Index_temp; sectorIndex < FEE_SECTOR_NUMBER; sectorIndex++ )
            {
                if( (FEE_SECTOR_FULL == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) ||
                    (FEE_SECTOR_BAD_NEED_SWAP == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) ||
                    (FEE_SECTOR_BLOCK_NEED_SWAP == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) ||
                    (FEE_SECTOR_WRITE_FAILED == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) )
                {
                    /* Found sector that need swap. */
                    Fee_SwapManagerInfo.SourceSectorIndex = sectorIndex;
                    /* Current sector swap status set pending. */
                    Fee_SwapManagerInfo.SectorSwapState = FEE_SWAP_PENDING;
                    break;
                }
                if( sectorIndex == (Fee_PartitionInfo.PartitionInfoSnap.SectorIndex) )
                {
                    Fee_PartitionInfo.SectorFullNum = FEE_VALUE_ZERO;
                    loop = FALSE;
                    /* polyspace +1 MISRA-C3:15.4 [Justified:Unset] "NSCA_Polyspace_Fee_Rule15.4" */
                    break;  /* PRQA S 771 */ /* NSCA_QAC_Fee_Rule15.4 */
                }
            }
            /* Found sectors that require swap to exit. */
            if( FEE_SWAP_PENDING == Fee_SwapManagerInfo.SectorSwapState )
            {
                break;
            }
            /* Start searching again from the 0th sector until the current sector. */
            else if( sectorIndex == Fee_PartitionCfg.SectorTotalNum )
            {
                Index_temp = FEE_VALUE_ZERO;
            }
            else
            {
                /* Nothing to do. */
            }
        }
    }
}

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Fee_GetSwapSize
*
* Explanation: Fee get immediate swap need space size.
*
* param: SectorAddressStart : The starting address currently written by the Sector.
*        SectorAddressEnd : The current end address that the Sector can write.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
static FUNC(void, FEE_CODE) Fee_GetSwapSize(uint32 SectorAddressStart, uint32 SectorAddressEnd)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 blockIndex;
    uint32 swapSize = FEE_VALUE_ZERO;
    /* cyclic query need swap block,Every call will check the last swap. */
    for( blockIndex = FEE_VALUE_ZERO; blockIndex < Fee_PartitionCfg.BlockTotalNum; blockIndex++ )
    {
        /* Find valid blcoks within the address range. */
        if( (SectorAddressStart < Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->BlockStartAddr) &&
            (Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->BlockStartAddr < SectorAddressEnd) &&
            (FEE_VALID_ID == Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->ValidFlag) )
        {
            swapSize =
                swapSize + Fee_CalcuAlignedLen(Fee_PartitionCfg.Fee_Block[blockIndex].BlockSize) + Fee_JobManagerInfo.BlockHeadAligned;
        }
    }
    Fee_SwapManagerInfo.ImmSwapNeedSize = swapSize;
}
#endif

/*
********************************************************************************
* Function Name: Fee_GetSwapBlocks
*
* Explanation: Fee get Swap block.
*
* param: None
*
* retval: E_OK: Found a block need swap or need to continue searching in the
*         next cycle.
*         E_NOT_OK: Not found a block need swap.
********************************************************************************
*/
static FUNC(Std_ReturnType, FEE_CODE) Fee_GetSwapBlocks(void)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint16 blockScanCount = FEE_VALUE_ZERO;
    /* polyspace-begin MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 blockIndex;
    uint32 sectorAddressEnd;
    uint32 sectorAddressStart;
    /* polyspace-end MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */

    Fee_GetSwapSector();

    if( FEE_SWAP_PENDING == Fee_SwapManagerInfo.SectorSwapState )
    {
        sectorAddressStart = Fee_PartitionCfg.Fee_SectorHead[Fee_SwapManagerInfo.SourceSectorIndex].SectorStartAddr;
        sectorAddressEnd = Fee_PartitionCfg.Fee_SectorHead[Fee_SwapManagerInfo.SourceSectorIndex].SectorStartAddr +
                            Fee_PartitionCfg.Fee_SectorHead[Fee_SwapManagerInfo.SourceSectorIndex].SectorSize;
        /* cyclic query need swap block,Every call will check the last swap. */
        for( blockIndex = Fee_SwapManagerInfo.SwapScanBlockIndex; blockIndex < Fee_PartitionCfg.BlockTotalNum; blockIndex++ )
        {
            /* Find valid blcoks within the address range. */
            if( (sectorAddressStart < Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->BlockStartAddr) &&
                (Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->BlockStartAddr < sectorAddressEnd) &&
                (FEE_VALID_ID == Fee_PartitionCfg.Fee_Block[blockIndex].Fee_BlockHead_Dyn->ValidFlag) )
            {
                Fee_SwapManagerInfo.BlockSwapRequired = TRUE;
                Fee_SwapManagerInfo.SwapBlockIndex = blockIndex;
                /* Then query the blcok status of the last swap. */
                Fee_SwapManagerInfo.SwapScanBlockIndex = blockIndex;
                rtrnValu = E_OK;
                break;
            }

            blockScanCount++;
            /* If the number of scans exceeds FEE_PERIOD_POLLING_BLOCK_NUM, exit the next cycle and continue scanning. */
            if( FEE_PERIOD_POLLING_BLOCK_NUM < blockScanCount )
            {
                Fee_SwapManagerInfo.BlockSwapRequired = FALSE;
                /* Then query the blcok status of the last swap. */
                Fee_SwapManagerInfo.SwapScanBlockIndex = blockIndex;
                rtrnValu = E_OK;
                /* polyspace +1 MISRA-C3:15.4 [Justified:Unset] "NSCA_Polyspace_Fee_Rule15.4" */
                break;  /* PRQA S 771 */ /* NSCA_QAC_Fee_Rule15.4 */
            }
        }
    }
    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_InvalidateJob
*
* Explanation: Service to scan valid block information.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_InvalidateJob(void)
{
    switch( Fee_PartitionInfo.JobState )
    {
        case FEE_JOB_INVAL_BLOCK:
            Fee_JobWriteBlockHead(FALSE);
            break;

        case FEE_JOB_INVAL_BLOCK_UNVLD:
            Fee_JobWritedBlockUnvld();
            break;

        case FEE_JOB_INVAL_BLOCK_DONE:
            Fee_JobWriteBlockDone();
            break;
        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: Fee_Init
*
* Explanation: Service to initialize the FEE module.(Asynchronous)
*
* param: ConfigPtr: Pointer to the selected configuration set.
*
* retval: None
********************************************************************************
*/
FUNC(void, FEE_CODE) Fee_Init(P2CONST(Fee_ConfigType, AUTOMATIC, FEE_APPL_CONST) ConfigPtr)
{
    uint16 loopNum;
    uint32 bufferInitValue;

    /* Check if input parameter is NULL. */
    if( NULL_PTR == ConfigPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Set fee module to internal busy state. */
        Fee_ModuleState = MEMIF_BUSY_INTERNAL;
        Fee_ModuleNextState = MEMIF_IDLE;

        bufferInitValue = ((uint32)(FEE_ERASED_INIT_VALUE) << FEE_LEFT_SHIFT_24BIT) | ((uint32)(FEE_ERASED_INIT_VALUE) << FEE_LEFT_SHIFT_16BIT)| \
                          ((uint32)(FEE_ERASED_INIT_VALUE) << FEE_LEFT_SHIFT_8BIT) | (uint32)(FEE_ERASED_INIT_VALUE);
        /* Clear internal buffer. */
        for( loopNum = FEE_VALUE_ZERO; loopNum < (FEE_WRITE_BUFFER_SIZE >> FEE_VALUE_TWO); loopNum++ )
        {
            Fee_InterBuffer[loopNum] = bufferInitValue;
        }
        /* Calculation the size of sector header writen to flash. */
        Fee_JobManagerInfo.SectorHeadAligned = Fee_CalcuAlignedLen(sizeof(Fee_SectorHeadType));

        /* Calculation the size of block header writen to flash. */
        Fee_JobManagerInfo.BlockHeadAligned = Fee_CalcuAlignedLen(sizeof(Fee_BlockHeadRomType) - sizeof(uint32)) +
            Fee_CalcuAlignedLen(sizeof(uint32));

        Fee_WithoutValidFlag = (uint8)(sizeof(Fee_BlockHeadRomType) - sizeof(uint32));
        Fee_WithoutValidFlagAligned = Fee_JobManagerInfo.BlockHeadAligned - Fee_CalcuAlignedLen(sizeof(uint32));
        Fee_CalcuCheckSumLen = (uint8)(sizeof(Fee_BlockHeadRomType) - sizeof(uint32) - sizeof(uint32));
        Fee_BlockValidEndLen = Fee_WithoutValidFlagAligned + sizeof(uint32);

        /* Calculation the number of block header read from flash at one time. */
        Fee_ScanManagerInfo.ScanReadLen = (uint16)((FEE_WRITE_BUFFER_SIZE / (Fee_JobManagerInfo.BlockHeadAligned )) *
            (Fee_JobManagerInfo.BlockHeadAligned));

        Fee_PartitionInfo.ModuleRunningState = FEE_RUNNING;
        Fee_PartitionInfo.PartitionInfoSnap.SectorIndex = FEE_VALUE_ZERO;
        Fee_PartitionInfo.JobState = FEE_JOB_SCAN_INT_SCAN;
        Fee_PartitionInfo.JobNextState = FEE_JOB_DONE;
        Fee_PartitionInfo.TriggerSwapThreshold = (FEE_SECTOR_NUMBER - FEE_VALUE_ONE);
        Fee_PartitionInfo.SectorFullNum = FEE_VALUE_ZERO;
        Fee_PartitionInfo.SectorFreeNum = FEE_VALUE_ZERO;
        Fee_PartitionInfo.SectorReservedNum = FEE_VALUE_ZERO;
        Fee_PartitionInfo.SectorBadNum = FEE_VALUE_ZERO;
        Fee_PartitionInfo.ImmWriteState = FEE_IMM_WRITE_DONE;

        Fee_PartitionInfo.SwapJobBackUp = FEE_JOB_SWAP_DONE;
        Fee_PartitionInfo.SectorIndexBackUp = FEE_VALUE_ZERO;
        Fee_PartitionInfo.RecoverSwapTimer = FEE_VALUE_ZERO;
        /* Currently set to False, set to True after Scan ends */
        Fee_PartitionInfo.noActiveSectors = FALSE;

        /* Initialize variable for Fee_CheckBlocklen(). */
        Fee_ScanManagerInfo.TotalBlockLenCalcuFinish = FALSE;
        Fee_ScanManagerInfo.CalcuBlockLenBlockIndex = FEE_VALUE_ZERO;
        Fee_ScanManagerInfo.TotalBlockLen = FEE_VALUE_ZERO;
        /* Initialize variable for get the latest Block head write address. */
        Fee_ScanManagerInfo.BlankAddrUpdateRequest = TRUE;
        Fee_ScanManagerInfo.TotalImmBlockLen = FEE_VALUE_ZERO;
        Fee_ScanManagerInfo.MaxImmBlockLen = FEE_VALUE_ZERO;
        Fee_ScanManagerInfo.ReservedImmLen = FEE_VALUE_ZERO;
        Fee_ScanManagerInfo.ReservedImmSectors = FEE_VALUE_ZERO;
        Fee_ScanManagerInfo.ScanSectorNeedEraseNum = FEE_VALUE_ZERO;

        Fee_JobManagerInfo.WriteJobProcessedLen = FEE_VALUE_ZERO;
        Fee_JobManagerInfo.WriteJobStartAddr = FEE_VALUE_ZERO;
        Fee_JobManagerInfo.JobBlockIndex = FEE_VALUE_ZERO;
        Fee_JobManagerInfo.JobResult = MEMIF_JOB_OK;
        Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;

        Fee_SwapManagerInfo.ReadIsProcessing = FALSE;
        Fee_SwapManagerInfo.RemaindReadLen = FEE_VALUE_ZERO;
        Fee_SwapManagerInfo.SwapReadAddr = FEE_VALUE_ZERO;
        Fee_SwapManagerInfo.ProcessedWriteLen = FEE_VALUE_ZERO;
        Fee_SwapManagerInfo.SwapBlockIndex = FEE_VALUE_ZERO;
        Fee_SwapManagerInfo.SwapReadLen = FEE_VALUE_ZERO;
        Fee_SwapManagerInfo.SourceSectorIndex = FEE_VALUE_FF;
        Fee_SwapManagerInfo.BlockSwapRequired = FALSE;
        Fee_SwapManagerInfo.SectorSwapState = FEE_SWAP_IDLE;
        Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_DONE;
        Fee_SwapManagerInfo.SwapScanBlockIndex = FEE_VALUE_ZERO;
        Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_OFF;
        Fee_SwapManagerInfo.FlsJobResultBackup = MEMIF_JOB_OK;
        Fee_SwapManagerInfo.ImmSwapNeedSize = FEE_VALUE_ZERO;

        /* Check the rationality of BLCOK length configuration and
           the number of sectors occupied by all BLCOK lengths. */
        Fee_CheckBlocklen();
    }
}

/*
********************************************************************************
* Function Name: Fee_SetMode
*
* Explanation: Service to call the Fls_SetMode function of the underlying flash
*              driver.(Synchronous)
*
* param: Mode: Desired mode for the underlying flash driver.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
FUNC(void, FEE_CODE) Fee_SetMode(MemIf_ModeType Mode)
{

#if( (FEE_SET_MODE_SUPPORTED == STD_ON) && (FEE_MEMACC_MODE_ENABLE == STD_OFF) )

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    uint8 chkResult = FEE_E_NO_ERR;

    /* SWS_Fee_00121 */
    if( MEMIF_UNINIT == Fee_ModuleState )
    {
        chkResult = FEE_E_UNINIT;
    }
    /* SWS_Fee_00170 */
    else if( MEMIF_BUSY == Fee_ModuleState )
    {
        chkResult = FEE_E_BUSY;
    }
    else
    {
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */

        /* SWS_Fee_00020 */
        if( (MEMIF_IDLE == Fee_ModuleState) )
        {
            Fee_PartitionCfg.Fls_FunctionList->SetMode(Mode);
        }

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    }
    if( chkResult != FEE_E_NO_ERR )
    {
        /* Report ErrorId to Det. */
        Fee_Det_ErrorReport(FEE_SET_MODE, chkResult);
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

#else
    FEE_DUMMY_STATEMENT(Mode);
#endif /* (FEE_SET_MODE_SUPPORTED == STD_ON) && (FEE_MEMACC_MODE_ENABLE == STD_OFF) */

}

/*
********************************************************************************
* Function Name: Fee_Read
*
* Explanation: Service to initiate a read job.(Asynchronous)
*
* param: BlockNumber: Number of logical block, also denoting start address of
*                     that block in flash memory.
*        BlockOffset: Read address offset inside the block.
*        Length: Number of bytes to read.
*        DataBufferPtr: Pointer to data buffer.
*
* retval: E_OK: The requested job has been accepted by the module.
*         E_NOT_OK: The requested job has not been accepted by the module.
********************************************************************************
*/
FUNC(Std_ReturnType, FEE_CODE) Fee_Read
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 BlockNumber,
    uint16 BlockOffset,
    P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) DataBufferPtr,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 Length
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint16 blockIndx = FEE_VALUE_ZERO;
    uint8 chkResult = FEE_E_NO_ERR;

    blockIndx = Fee_SeekIndexFromNumber(BlockNumber);
    chkResult = Fee_ChkGeneralCondition(blockIndx);
    /* Check the readout conditions. */
    if( FEE_E_NO_ERR == chkResult )     /* No error. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Check the pointer is not null. */
        if( NULL_PTR == DataBufferPtr )
        {
            chkResult = FEE_E_PARAM_POINTER;
        }
        /* Check the offset is in the range. */
        else if( BlockOffset > Fee_PartitionCfg.Fee_Block[blockIndx].BlockSize )
        {
            chkResult = FEE_E_INVALID_BLOCK_OFS;
        }
        /* Check the length is in the range. */
        else if( (BlockOffset + Length) > Fee_PartitionCfg.Fee_Block[blockIndx].BlockSize )
        {
            chkResult = FEE_E_INVALID_BLOCK_LEN;
        }
        else
        {
            /* [SWS_Fee_00022] */
            if( ((MEMIF_IDLE == Fee_ModuleState) ||
                (MEMIF_BUSY_INTERNAL == Fee_ModuleState)) &&
                (FEE_RUNNING == Fee_PartitionInfo.ModuleRunningState) )
            {
                /* Set parameters of FEE job management to read data. */
                Fee_ModuleState = MEMIF_BUSY;
                Fee_JobManagerInfo.JobResult = MEMIF_JOB_PENDING;
                Fee_JobManagerInfo.JobBlockIndex = blockIndx;
                Fee_PartitionInfo.ReadDataBufferPtr = DataBufferPtr;
                Fee_PartitionInfo.PartitionInfoSnap.BlockReadlen = Length;
                Fee_PartitionInfo.PartitionInfoSnap.BlockReadDataAddr = BlockOffset;
                Fee_ModuleNextState = MEMIF_BUSY;
                Fee_PartitionInfo.JobNextState = FEE_JOB_READ;

#if( (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) )
                Fee_Notification = TRUE;
#endif

                rtrnValu = E_OK;
            }
        }
    }

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( chkResult != FEE_E_NO_ERR )     /* Error detected. */
    {
        Fee_Det_ErrorReport(FEE_READ, chkResult);   /* Report ErrorId to Det. */
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_Write
*
* Explanation: Service to initiate a write job.(Asynchronous)
*
* param: BlockNumber: Number of logical block, also denoting start address of
*                     that block in EEPROM.
*        DataBufferPtr: Pointer to data buffer.
*
* retval: E_OK: The requested job has been accepted by the module.
*         E_NOT_OK: The requested job has not been accepted by the module.
********************************************************************************
*/
FUNC(Std_ReturnType, FEE_CODE) Fee_Write
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 BlockNumber,
    P2CONST(uint8, AUTOMATIC, FEE_APPL_CONST) DataBufferPtr
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint16 blockIndx = FEE_VALUE_ZERO;
    uint8 chkResult = FEE_E_NO_ERR;

    blockIndx = Fee_SeekIndexFromNumber(BlockNumber);
    chkResult = Fee_ChkGeneralCondition(blockIndx);
    /* Check the write conditions. */
    if( FEE_E_NO_ERR == chkResult )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {   /* [SWS_Fee_00025] */
        if( NULL_PTR == DataBufferPtr )  /* Check the pointer is not null. */
        {
            chkResult = FEE_E_PARAM_POINTER;
        }
        else
        {
            if( (MEMIF_IDLE == Fee_ModuleState) &&
                (FEE_RUNNING == Fee_PartitionInfo.ModuleRunningState) )
            {
                /* Set parameters of FEE job management to read data. */
                Fee_ModuleState = MEMIF_BUSY;
                Fee_JobManagerInfo.JobResult = MEMIF_JOB_PENDING;
                Fee_JobManagerInfo.JobBlockIndex = blockIndx;
                Fee_PartitionInfo.WriteDataBufferPtr = DataBufferPtr;
                Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen
                    = Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].BlockSize;
                Fee_ModuleNextState = MEMIF_BUSY;
                Fee_PartitionInfo.JobNextState = FEE_JOB_WRITE_HED;

#if( (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) )
                Fee_Notification = TRUE;
#endif

                rtrnValu = E_OK;
            }
        }
    }

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( chkResult != FEE_E_NO_ERR ) /* Error detected. */
    {
        Fee_Det_ErrorReport(FEE_WRITE, chkResult);  /* Report ErrorId to Det. */
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_Cancel
*
* Explanation: Service to call the cancel function of the underlying flash
*              driver.(Synchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, FEE_CODE) Fee_Cancel(void)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
    Fee_JobType jobStateTemp;

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    uint8 chkResult = FEE_E_NO_ERR;

    /* Check the FEE is initialized. */
    if( MEMIF_UNINIT == Fee_ModuleState )
    {
        chkResult = FEE_E_UNINIT;
    }
    else
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        if( (MEMIF_BUSY == Fee_ModuleState) )
        {
            /* Check if current job is scan or swap or inner erase job. */
            if( (FEE_SECTOR_IMMEDIATELY_SWAP_ON == Fee_SwapManagerInfo.SwapRequest) ||
                ((FEE_JOB_WRITE_SEC_HEAD <= Fee_PartitionInfo.JobState) &&
                 (FEE_JOB_INTER_ERASE_DONE >= Fee_PartitionInfo.JobState)) )
            {
                /* Cancel will call in Fee_SwapJobCancel or directly call Fee_SwapJobPause. */
                Fee_PartitionInfo.JobNextState = FEE_JOB_DONE;
                Fee_ModuleState = MEMIF_IDLE;
                Fee_ModuleNextState = MEMIF_IDLE;
                if( MEMIF_JOB_PENDING == Fee_JobManagerInfo.JobResult )
                {
                    Fee_JobManagerInfo.JobResult = MEMIF_JOB_CANCELED;
                }
                /* The erase operation cannot be directly interrupted when there is no space.
                   The establishment operation of the sector head cannot be directly interrupted. */
                if( (FEE_SECTOR_IMMEDIATELY_SWAP_ON == Fee_SwapManagerInfo.SwapRequest) &&
                    (FEE_JOB_WRITE_SEC_HEAD > Fee_PartitionInfo.JobState) )
                {
                    Fee_PartitionInfo.JobState = FEE_JOB_DONE;
                }
                Fee_PartitionInfo.RecoverSwapTimer = FEE_IMM_WRITE_TIMER_DELAY;
            }
            else
            {
                if( MEMIF_JOB_PENDING == Fee_JobManagerInfo.FlsJobResult )
                {

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
                    MemAcc_Cancel(FEE_MEMACC_ADDRESS_AREA_ID);
#else
                    Fee_PartitionCfg.Fls_FunctionList->Cancel();
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

                }

                jobStateTemp = Fee_PartitionInfo.JobState;
                Fee_PartitionInfo.JobState = FEE_JOB_DONE;
                Fee_PartitionInfo.JobNextState = FEE_JOB_DONE;
                Fee_JobManagerInfo.JobResult = MEMIF_JOB_CANCELED;
                Fee_ModuleNextState = MEMIF_IDLE;
                Fee_ModuleState = MEMIF_IDLE;

                if( FEE_JOB_WRITE_DATA == jobStateTemp )
                {
                    Fee_SectorWriteFailedDeal(sectorIndex);
                }

                if( FEE_SECTOR_IMMEDIATELY_SWAP_ON < Fee_SwapManagerInfo.SwapRequest )
                {
                    if( FEE_JOB_SWAP_BLOCK_IDLE > Fee_SwapManagerInfo.SwapJob )
                    {
                        /* Fee_GetSwapBlocks Every call will check the block of the last swap block. */
                        Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_BLOCK_IDLE;
                    }
                    else if( FEE_JOB_SWAP_DONE > Fee_SwapManagerInfo.SwapJob )
                    {
                        Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_ERASE;
                    }
                    else
                    {
                        /* Nothing to do. */
                    }
                    Fee_PartitionInfo.RecoverSwapTimer = FEE_TIMER_DELAY;
                }

#if( (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) )
                Fee_Notification = TRUE;
#endif /* (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) */

            }
        }
        else
        {
            Fee_PartitionInfo.JobNextState = FEE_JOB_DONE;
            Fee_ModuleState = MEMIF_IDLE;
            Fee_ModuleNextState = MEMIF_IDLE;

#if( FEE_DEV_ERROR_DETECT == STD_ON )
            chkResult = FEE_E_INVALID_CANCEL;
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

        }
    }

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( chkResult != FEE_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        Fee_Det_ErrorReport(FEE_CANCEL, chkResult);
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */

}

/*
********************************************************************************
* Function Name: Fee_GetStatus
*
* Explanation: Service to return the status.(Synchronous)
*
* param: None
*
* retval: MEMIF_UNINIT: The FEE module has not been initialized.
*         MEMIF_IDLE: The FEE module is currently idle.
*         MEMIF_BUSY: The FEE module is currently busy.
*         MEMIF_BUSY_INTERNAL: The FEE module is busy with internal management
*                              operations.
********************************************************************************
*/
FUNC(MemIf_StatusType, FEE_CODE) Fee_GetStatus(void)
{
    return Fee_ModuleState;
}

/*
********************************************************************************
* Function Name: Fee_GetEraseCount
*
* Explanation: Service to return the erase count.(Synchronous)
*
* param: None
*
* retval: eraseCount == 0xffffffff : Failed to get the number of times of Erase.
*         eraseCount != 0xffffffff : get the number of times of Erase.
********************************************************************************
*/
FUNC(uint32, FEE_CODE) Fee_GetEraseCount(void)
{
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint8 sectorIndex;
    uint32 eraseCount = FEE_DEFAULT_VALID_ID;

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* Check the FEE is initialized. */
    if( MEMIF_UNINIT != Fee_ModuleState )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

        if( FEE_JOB_SCAN_DONE <= Fee_PartitionInfo.JobState)
        {
            for( sectorIndex = FEE_VALUE_ZERO; sectorIndex < FEE_SECTOR_NUMBER; sectorIndex++ )
            {
                /* FEE_COMPATIBLE_SECTOR_HEAD_VAILD_ID is a special sector valid identification used to be compatible
                   with reading old version sector heads, or to be read special sector valid identification that
                   introduced for reading old version sector heads. */
                if( (FEE_SECTOR_HEAD_VAILD_ID == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorHead_Dyn->ValidFlag) ||
                    (FEE_COMPATIBLE_SECTOR_HEAD_VAILD_ID == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorHead_Dyn->ValidFlag) )
                {
                   eraseCount = Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorHead_Dyn->SectorCounter / FEE_SECTOR_NUMBER;
                   break;
                }
            }
        }

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

    return eraseCount;
}

/*
********************************************************************************
* Function Name: Fee_GetJobResult
*
* Explanation: Service to query the result of the last accepted job issued by
*              the upper layer software.(Synchronous)
*
* param: None
*
* retval: MEMIF_JOB_OK: The last job has been finished successfully.
*         MEMIF_JOB_PENDING: The last job is waiting for execution or currently
*                            being executed.
*         MEMIF_JOB_CANCELED: The last job has been canceled(which means
*                             it failed).
*         MEMIF_JOB_FAILED: The last job has not been finished successfully
*                           (it failed).
*         MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, it
*                                   may contain corrupted data.
*         MEMIF_BLOCK_INVALID: The requested block has been invalidated, the
*                              requested read operation can not beperformed.
********************************************************************************
*/
FUNC(MemIf_JobResultType, FEE_CODE) Fee_GetJobResult(void)
{
    MemIf_JobResultType rtrnValu = MEMIF_JOB_FAILED;

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* Check that FEE is initialized. */
    if( MEMIF_UNINIT == Fee_ModuleState )
    {
        /* Report ErrorId to Det. */
        Fee_Det_ErrorReport(FEE_GET_JOB_RESULT, FEE_E_UNINIT);
    }
    else
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Return the job result. */
        rtrnValu = Fee_JobManagerInfo.JobResult;
    }
    return  rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_InvalidateBlock
*
* Explanation: Service to invalidate a logical block.(Asynchronous)
*
* param: BlockNumber: Number of logical block, also denoting start address of
*                     that block in flash memory.
*
* retval: E_OK: The requested job has been accepted by the module.
*         E_NOT_OK-only if DET is enabled: The requested job has not
*                                          been accepted by the module.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
FUNC(Std_ReturnType, FEE_CODE) Fee_InvalidateBlock(uint16 BlockNumber)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint16 blockIndx = FEE_VALUE_ZERO;
    uint8 chkResult = FEE_E_NO_ERR;

    blockIndx = Fee_SeekIndexFromNumber(BlockNumber);
    chkResult = Fee_ChkGeneralCondition(blockIndx);
    /* Check the readout conditions. */
    if( FEE_E_NO_ERR == chkResult )     /* No error. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        if( (MEMIF_IDLE == Fee_ModuleState) &&
            (FEE_RUNNING == Fee_PartitionInfo.ModuleRunningState) )
        {
            /* Set parameters of FEE job management to read data. */
            Fee_ModuleState = MEMIF_BUSY;
            Fee_JobManagerInfo.JobResult = MEMIF_JOB_PENDING;
            Fee_JobManagerInfo.JobBlockIndex = blockIndx;
            Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen = FEE_VALUE_ZERO;
            Fee_ModuleNextState = MEMIF_BUSY;
            Fee_PartitionInfo.JobNextState = FEE_JOB_INVAL_BLOCK;

#if( (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) )
            Fee_Notification = TRUE;
#endif

            rtrnValu = E_OK;
        }
    }

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* Error detected. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( chkResult != FEE_E_NO_ERR )
    {
        /* Report ErrorId to Det. */
        Fee_Det_ErrorReport(FEE_INVALIDATE_BLOCK, chkResult);
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_EraseImmediateBlock
*
* Explanation: Service to erase a logical block.(Asynchronous)
*
* param: BlockNumber: Number of logical block, also denoting start address of
*                     that block in EEPROM.
*
* retval: E_OK: The requested job has been accepted by the module.
*         E_NOT_OK : only if DET is enabled: The requested job has not been
*                                          accepted by the module.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
FUNC(Std_ReturnType, FEE_CODE) Fee_EraseImmediateBlock(uint16 BlockNumber)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint16 blockIndx = FEE_VALUE_ZERO;
    uint8 chkResult = FEE_E_NO_ERR;

    blockIndx = Fee_SeekIndexFromNumber(BlockNumber);
    chkResult = Fee_ChkGeneralCondition(blockIndx);

    /* Check the readout conditions. */
    if( FEE_E_NO_ERR == chkResult )     /* No error. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Check the block is immediate. */
        if( FALSE == Fee_PartitionCfg.Fee_Block[blockIndx].IsImmediateData )
        {
            chkResult = FEE_E_INVALID_BLOCK_NO;
        }
        else
        {
            if( (MEMIF_IDLE == Fee_ModuleState) &&
                (FEE_RUNNING == Fee_PartitionInfo.ModuleRunningState) )
            {
                /* Set parameters of FEE job management to read data. */
                Fee_ModuleState = MEMIF_BUSY;
                Fee_JobManagerInfo.JobResult = MEMIF_JOB_PENDING;
                Fee_JobManagerInfo.JobBlockIndex = blockIndx;
                Fee_PartitionInfo.PartitionInfoSnap.BlockWritelen = FEE_VALUE_ZERO;
                Fee_ModuleNextState = MEMIF_BUSY;
                Fee_PartitionInfo.JobNextState = FEE_JOB_ERASE_BlOCK;

#if( (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) )
                Fee_Notification = TRUE;
#endif

                rtrnValu = E_OK;
            }
        }
    }

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* Error detected. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( chkResult != FEE_E_NO_ERR )
    {
        /* Report ErrorId to Det. */
        Fee_Det_ErrorReport(FEE_ERASE_IMMEDIATE_BLOCK, chkResult);
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

    return rtrnValu;
}

#if( (FEE_MEMACC_MODE_ENABLE == STD_ON) && (FEE_POLLING_MODE == STD_ON) )
/*
********************************************************************************
* Function Name: Fee_MemAccGetJobResult
*
* Explanation: Service to get MemAcc job result.(Synchronous)
*
* param: None
*
* retval: MEMIF_JOB_OK: The last job has been finished successfully.
*         MEMIF_JOB_PENDING: The last job is waiting for execution or currently
*                            being executed.
*         MEMIF_JOB_CANCELED: The last job has been canceled(which means
*                             it failed).
*         MEMIF_JOB_FAILED: The last job has not been finished successfully
*                           (it failed).
*         MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, it
*                                   may contain corrupted data.
*         MEMIF_BLOCK_INVALID: The requested block has been invalidated, the
*                              requested read operation can not beperformed.
********************************************************************************
*/
static FUNC(MemIf_JobResultType, FEE_CODE) Fee_MemAccGetJobResult(void)
{
    MemAcc_JobStatusType MemAcc_JobStatus = MEMACC_JOB_PENDING;
    MemAcc_JobResultType MemAcc_JobResult = MEMACC_MEM_FAILED;
    MemIf_JobResultType Fee_DriveJobResult_temp = MEMIF_JOB_PENDING;

    MemAcc_JobStatus = MemAcc_GetJobStatus(FEE_MEMACC_ADDRESS_AREA_ID);
    if( MEMACC_JOB_IDLE == MemAcc_JobStatus )
    {
        MemAcc_JobResult = MemAcc_GetJobResult(FEE_MEMACC_ADDRESS_AREA_ID);
        switch( MemAcc_JobResult )
        {
            case MEMACC_MEM_OK:
                Fee_DriveJobResult_temp = MEMIF_JOB_OK;
            break;
            case MEMACC_MEM_FAILED:
                Fee_DriveJobResult_temp = MEMIF_JOB_FAILED;
            break;
            case MEMACC_MEM_CANCELED:
                Fee_DriveJobResult_temp = MEMIF_JOB_CANCELED;
            break;
            case MEMACC_MEM_INCONSISTENT:
                Fee_DriveJobResult_temp = MEMIF_BLOCK_INCONSISTENT;
            break;
            default:
                Fee_DriveJobResult_temp = MEMIF_JOB_FAILED;
            break;
        }
    }
    return Fee_DriveJobResult_temp;
}
#endif /* (FEE_MEMACC_MODE_ENABLE == STD_ON) && (FEE_POLLING_MODE == STD_ON) */

#if( (FEE_MEMACC_MODE_ENABLE == STD_ON) && (FEE_POLLING_MODE == STD_OFF) )
/*
********************************************************************************
* Function Name: Fee_MemAccGetJobResultCallBack
*
* Explanation: Service to get MemAcc job result.(Synchronous)
*
* Param: JobResult: The MemAcc job result
*
* Retval: MEMIF_JOB_OK: The last job has been finished successfully.
*         MEMIF_JOB_PENDING: The last job is waiting for execution or currently
*                            being executed.
*         MEMIF_JOB_CANCELED: The last job has been canceled(which means it failed).
*         MEMIF_JOB_FAILED: The last job has not been finished successfully (it failed).
*         MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, it may
*                                   contain corrupted data.
*         MEMIF_BLOCK_INVALID: The requested block has been invalidated, the
*                                   requested read operation can not beperformed.
********************************************************************************
*/
static FUNC(MemIf_JobResultType, FEE_CODE) Fee_MemAccGetJobResultCallBack(MemAcc_JobResultType JobResult)
{
    MemAcc_JobResultType MemAcc_JobResult = JobResult;
    MemIf_JobResultType Fee_DriveJobResult_temp = MEMIF_JOB_PENDING;

    switch( MemAcc_JobResult )
    {
        case MEMACC_MEM_OK:
            Fee_DriveJobResult_temp = MEMIF_JOB_OK;
        break;
        case MEMACC_MEM_FAILED:
            Fee_DriveJobResult_temp = MEMIF_JOB_FAILED;
        break;
        case MEMACC_MEM_CANCELED:
            Fee_DriveJobResult_temp = MEMIF_JOB_CANCELED;
        break;
        case MEMACC_MEM_INCONSISTENT:
            Fee_DriveJobResult_temp = MEMIF_BLOCK_INCONSISTENT;
        break;
        default:
            Fee_DriveJobResult_temp = MEMIF_JOB_FAILED;
        break;
    }

    return Fee_DriveJobResult_temp;
}
#endif /* (FEE_MEMACC_MODE_ENABLE == STD_ON) && (FEE_POLLING_MODE == STD_OFF) */

#if( FEE_POLLING_MODE == STD_OFF )

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Fee_JobEndNotification
*
* Explanation: Service to report to this module the successful end of an asynchronous operation.(Synchronous)
*
* Param: FeeAddressAreaId: The MemAcc address area Id.
*        JobResult: The MemAcc job result.
*
* Retval: None
********************************************************************************
*/
FUNC(void, FEE_CODE) Fee_JobEndNotification(MemAcc_AddressAreaIdType FeeAddressAreaId, MemAcc_JobResultType JobResult)
#else
/*
********************************************************************************
* Function Name: Fee_JobEndNotification
*
* Explanation: Service to report to this module the successful end of an
*              asynchronous operation.(Synchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, FEE_CODE) Fee_JobEndNotification(void)
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

{

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
    MemAcc_JobResultType MemAcc_JobResult = MEMACC_MEM_FAILED;

    if( MEMIF_JOB_PENDING == Fee_JobManagerInfo.FlsJobResult )
    {
        MemAcc_JobResult = MemAcc_GetJobResult(FEE_MEMACC_ADDRESS_AREA_ID);
        /* Set the MemAcc execution result to OK. */
        Fee_JobManagerInfo.FlsJobResult = Fee_MemAccGetJobResultCallBack(JobResult);
    }
#else
    if( MEMIF_JOB_PENDING == Fee_JobManagerInfo.FlsJobResult )
    {
        /* Set the FLS execution result to OK. */
        Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
    }
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

}

/*
********************************************************************************
* Function Name: Fee_JobErrorNotification
*
* Explanation: Service to report to this module the failure of an asynchronous
*              operation.(Synchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, FEE_CODE) Fee_JobErrorNotification(void)
{
    if( MEMIF_JOB_PENDING == Fee_JobManagerInfo.FlsJobResult )
    {
        /* Set the FLS execution result to failed. */
        Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_FAILED;
    }
}
#endif /* FEE_POLLING_MODE == STD_OFF */

/*
********************************************************************************
* Function Name: Fee_SetSectorLastSizeToZero
*
* Explanation: Set the remaining space of the current sector to zero and trigger
*              page swapping during the next write operation.
*
* param: None
*
* retval: E_OK: Set the current sector size is 0 and page swapping when writing data next time.
*         E_NOT_OK: No free sectors are currently available or the Fee is working.
********************************************************************************
*/
FUNC(Std_ReturnType, FEE_CODE) Fee_SetSectorLastSizeToZero(void)
{
    Std_ReturnType rtrnValu = E_NOT_OK;

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (Fee_PartitionInfo.SectorFreeNum > FEE_VALUE_ZERO) && (FEE_JOB_DONE == Fee_PartitionInfo.JobState)
         && (FEE_JOB_SWAP_DONE == Fee_SwapManagerInfo.SwapJob) )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        Fee_PartitionInfo.PartitionInfoSnap.SectorLastSize = FEE_VALUE_ZERO;
        rtrnValu = E_OK;
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_JobProcessStateMachine
*
* Explanation: Fee job State machine peration.(Synchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_JobProcessStateMachine(void)
{
    /* Scan block header. */
    if( Fee_PartitionInfo.JobState < FEE_JOB_READ )
    {
        Fee_ScanJob();
    }
    /* Read block operation. */
    else if( Fee_PartitionInfo.JobState < FEE_JOB_WRITE_HED )
    {
        Fee_ReadJob();
    }
    /* Write block operation. */
    else if( Fee_PartitionInfo.JobState < FEE_JOB_INVAL_BLOCK )
    {
        Fee_WriteJob();
    }
    /* Invalidate block operation. */
    else if( Fee_PartitionInfo.JobState < FEE_JOB_ERASE_BlOCK )
    {
        Fee_InvalidateJob();
    }
    /* Erase block operation. */
    else if( Fee_PartitionInfo.JobState < FEE_JOB_WRITE_SEC_HEAD )
    {
        Fee_EraseJob();
    }
    /* Build sector head. */
    else if( Fee_PartitionInfo.JobState < FEE_JOB_INTER_ERASE )
    {
        Fee_SectorBuildHeadJob();
    }
    /* Internal rease block operation. */
    else if( Fee_PartitionInfo.JobState < FEE_JOB_DONE )
    {
        Fee_InternalEraseJob();
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_SwapProcess
*
* Explanation: Fee swap State machine peration.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapProcess(void)
{
    /* Swap block header. */
    if( Fee_SwapManagerInfo.SwapJob < FEE_JOB_SWAP_BLOCK_IDLE )
    {
        Fee_SwapBlockJob();
    }
    /* Earse sector operation. */
    else if( Fee_SwapManagerInfo.SwapJob < FEE_JOB_SWAP_DONE )
    {
        Fee_SwapInternalEraseJob();
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_CalTotalBlockLen
*
* Explanation: Calculate the length of all blocks.
*
* param: None
*
* retval: Std_ReturnType
********************************************************************************
*/
static FUNC(Std_ReturnType, FEE_CODE) Fee_CalTotalBlockLen(void)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" */
    uint16 blockIndex;
    uint32 blockSize;
    uint32 sectorSize;

    sectorSize = Fee_PartitionCfg.Fee_SectorHead[FEE_VALUE_ZERO].SectorSize - Fee_JobManagerInfo.SectorHeadAligned;
    for( blockIndex = Fee_ScanManagerInfo.CalcuBlockLenBlockIndex; blockIndex < Fee_PartitionCfg.BlockTotalNum; blockIndex++ )
    {
        blockSize = Fee_CalcuAlignedLen(Fee_PartitionCfg.Fee_Block[blockIndex].BlockSize)+ Fee_JobManagerInfo.BlockHeadAligned;
        if( blockSize > sectorSize )
        {
            Fee_ErrorDeal();
        }

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
        if( TRUE == Fee_PartitionCfg.Fee_Block[blockIndex].IsImmediateData )
        {
            Fee_ScanManagerInfo.TotalImmBlockLen = Fee_ScanManagerInfo.TotalImmBlockLen + blockSize;
            if( blockSize > (uint32)Fee_ScanManagerInfo.MaxImmBlockLen )
            {
                Fee_ScanManagerInfo.MaxImmBlockLen = (uint16)blockSize;
            }
        }
#endif /* ( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON ) */

        Fee_ScanManagerInfo.TotalBlockLen = Fee_ScanManagerInfo.TotalBlockLen + blockSize;
    }

    if( blockIndex >= Fee_PartitionCfg.BlockTotalNum )
    {

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
        if( Fee_ScanManagerInfo.TotalImmBlockLen > sectorSize )
        {
            Fee_ScanManagerInfo.ReservedImmSectors = (uint8)(Fee_ScanManagerInfo.TotalImmBlockLen / sectorSize);
            Fee_ScanManagerInfo.ReservedImmLen =
                (Fee_ScanManagerInfo.TotalImmBlockLen % sectorSize) + (uint32)Fee_ScanManagerInfo.MaxImmBlockLen;
            Fee_ScanManagerInfo.TotalImmBlockLen =
                Fee_ScanManagerInfo.TotalImmBlockLen + (uint32)Fee_ScanManagerInfo.MaxImmBlockLen;
        }
        else
        {
            Fee_ScanManagerInfo.ReservedImmLen = Fee_ScanManagerInfo.TotalImmBlockLen;
        }
#endif /* ( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON ) */

        Fee_ScanManagerInfo.TotalBlockLen = Fee_ScanManagerInfo.TotalBlockLen + (uint32)Fee_ScanManagerInfo.MaxImmBlockLen;
        rtrnValu = E_OK;
    }
    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_CheckBlocklen
*
* Explanation: Check if the block configuration is reasonable for Fee detection.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_CheckBlocklen(void)
{
    Std_ReturnType rtrnValu;
    uint8 sectorFreeTotalNum;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint32 sectorSize = Fee_PartitionCfg.Fee_SectorHead[FEE_VALUE_ZERO].SectorSize - Fee_JobManagerInfo.SectorHeadAligned;

    if( FALSE == Fee_ScanManagerInfo.TotalBlockLenCalcuFinish )
    {
        rtrnValu = Fee_CalTotalBlockLen();
        sectorFreeTotalNum = Fee_PartitionCfg.SectorTotalNum - Fee_ScanManagerInfo.ReservedImmSectors;
        if( E_OK == rtrnValu )
        {
            Fee_PartitionInfo.BlockUseSectorNum = (uint8)(Fee_ScanManagerInfo.TotalBlockLen / sectorSize);

            if( FEE_VALUE_TWO < sectorFreeTotalNum )
            {
                if( Fee_PartitionInfo.BlockUseSectorNum >= (sectorFreeTotalNum - FEE_VALUE_TWO) )
                {
                    Fee_ErrorDeal();
                }
                else if( (FEE_VALUE_TWO <= (Fee_PartitionInfo.BlockUseSectorNum / FEE_VALUE_TWO)) &&
                    ((sectorFreeTotalNum - Fee_PartitionInfo.BlockUseSectorNum) >
                     (Fee_PartitionInfo.BlockUseSectorNum / FEE_VALUE_TWO)) )
                {
                    Fee_PartitionInfo.TriggerSwapThreshold = sectorFreeTotalNum -
                        (Fee_PartitionInfo.BlockUseSectorNum / FEE_VALUE_TWO);

                    if( (Fee_PartitionInfo.TriggerSwapThreshold - Fee_PartitionInfo.BlockUseSectorNum) <
                        (Fee_PartitionInfo.BlockUseSectorNum / FEE_VALUE_TWO) )
                    {
                        Fee_PartitionInfo.TriggerSwapThreshold = sectorFreeTotalNum - FEE_VALUE_TWO;
                    }
                }
                else
                {
                    Fee_PartitionInfo.TriggerSwapThreshold = sectorFreeTotalNum - FEE_VALUE_TWO;
                }
                if( Fee_PartitionInfo.BlockUseSectorNum >= Fee_PartitionInfo.TriggerSwapThreshold )
                {
                    Fee_ErrorDeal();
                }
            }
            else
            {
                 Fee_PartitionInfo.TriggerSwapThreshold = FEE_VALUE_ONE;
                 if( Fee_PartitionInfo.BlockUseSectorNum >= Fee_PartitionInfo.TriggerSwapThreshold )
                 {
                     Fee_ErrorDeal();
                 }
            }

            Fee_ScanManagerInfo.TotalBlockLenCalcuFinish = TRUE;
        }
    }
}

#if( (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) )
/*
********************************************************************************
* Function Name: Fee_NotificationCallBack
*
* Explanation: Fee User request callback.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_NotificationCallBack(void)
{
    if( (TRUE == Fee_Notification) && (MEMIF_JOB_PENDING != Fee_JobManagerInfo.JobResult) )
    {
        /* Polyspace +1 MISRA-C3:14.3 [JUstified:Unset] " NSCA_Polyspace_Fee_Rule14.3 " */
        if( MEMIF_JOB_OK != Fee_JobManagerInfo.JobResult )
        {

#if( FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON )
            FEE_NVM_JOB_ERROR_NOTIFICATION_FUNC;
            Fee_Notification = FALSE;
#endif /* FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON */

        }
        /* Polyspace +1 MISRA-C3:14.3 [JUstified:Unset] " NSCA_Polyspace_Fee_Rule14.3 " */
        else if( MEMIF_JOB_OK == Fee_JobManagerInfo.JobResult )
        {

#if( FEE_NVM_JOB_END_NOTIFICATION == STD_ON )
            FEE_NVM_JOB_END_NOTIFICATION_FUNC;
            Fee_Notification = FALSE;
#endif /* FEE_NVM_JOB_END_NOTIFICATION == STD_ON */

        }
        else
        {
            /* Nothing to do. */
        }
    }
}
#endif /* (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) */

/*
********************************************************************************
* Function Name: Fee_SwapJobPause
*
* Explanation: Fee swap job pause.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapJobPause(void)
{
    if( (FEE_JOB_SWAP_BLOCK_IDLE == Fee_SwapManagerInfo.SwapJob) ||
        (FEE_JOB_SWAP_DONE == Fee_SwapManagerInfo.SwapJob) )
    {
        if( FEE_SECTOR_SWAP_ON == Fee_SwapManagerInfo.SwapRequest )
        {
            Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_PAUSE;
        }
        else if( FEE_ONLY_EARSE_SECTOR == Fee_SwapManagerInfo.SwapRequest )
        {
            Fee_SwapManagerInfo.SwapRequest = FEE_ONLY_EARSE_PAUSE;
        }
        else
        {
            /* When Fee_PartitionInfo.JobNextState == FEE_JOB_READ. */
            Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_IMM_SWAP_PAUSE;
        }
        /* Record the fls status */
        Fee_SwapManagerInfo.FlsJobResultBackup = Fee_JobManagerInfo.FlsJobResult;
    }
}

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Fee_SwapJobCancel
*
* Explanation: Fee swap job cancel.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapJobCancel(void)
{
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 swapSectorIndex = Fee_SwapManagerInfo.SwapPartitionInfoSnap.SectorIndex;
    uint8 reservedSectorIndex;

    if( FEE_IMM_WRITE_ON_SWAP_INIT == Fee_PartitionInfo.ImmWriteState )
    {
        if(MEMIF_JOB_PENDING == Fee_JobManagerInfo.FlsJobResult)
        {

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
            MemAcc_Cancel(FEE_MEMACC_ADDRESS_AREA_ID);
#else
            Fee_PartitionCfg.Fls_FunctionList->Cancel();
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_CANCELED;
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

            if( (FEE_JOB_SWAP_READ_BLOCK_DATA == Fee_SwapManagerInfo.SwapJob) &&
                (FALSE== Fee_SwapBlcokHeadFailedUpdate) )
            {
                Fee_SwapBlcokHeadFailedUpdate = TRUE;
                Fee_SectorWriteFailedDeal(swapSectorIndex);
            }
        }
        else
        {
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_CANCELED;
        }

        Fee_PartitionInfo.SectorIndexBackUp = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
        Fee_PartitionInfo.SwapJobBackUp = Fee_SwapManagerInfo.SwapJob;
        Fee_PartitionInfo.ImmWriteState = FEE_IMM_WRITE_ON_SWAP;
    }
    else if( FEE_IMM_WRITE_ON_IMM_SWAP_INIT == Fee_PartitionInfo.ImmWriteState )
    {
        /* For immediate write operations during the immediate swap period, it is necessary to
           obtain whether there are any reserved sectors reserved for immediate data. */
        /* Polyspace +1 MISRA-C3:13.5 [JUstified:Unset] " NSCA_Polyspace_Fee_Rule13.5 " */
        if( (E_OK == Fee_BackwardGetSector(FEE_SECTOR_RESERVED_ACTIVATE, FEE_SECTOR_DEF, &reservedSectorIndex)) ||
            (E_OK == Fee_BackwardGetSector(FEE_SECTOR_RESERVED_FREE, FEE_SECTOR_DEF, &reservedSectorIndex)) )  /* PRQA S 3415 */ /* NSCA_QAC_Fee_Rule13.5 */
        {
            Fee_PartitionInfo.SectorIndexBackUp = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
            Fee_PartitionInfo.SwapJobBackUp = Fee_SwapManagerInfo.SwapJob;
            Fee_UpdatePattitionInfo(reservedSectorIndex);
            Fee_PartitionInfo.ImmWriteState = FEE_IMM_WRITE_ON_IMM_SWAP;
            if(MEMIF_JOB_PENDING == Fee_JobManagerInfo.FlsJobResult)
            {

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
                MemAcc_Cancel(FEE_MEMACC_ADDRESS_AREA_ID);
#else
                Fee_PartitionCfg.Fls_FunctionList->Cancel();
                Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_CANCELED;
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

                if( (FEE_JOB_SWAP_READ_BLOCK_DATA == Fee_SwapManagerInfo.SwapJob) &&
                    (FALSE== Fee_SwapBlcokHeadFailedUpdate) )
                {
                    Fee_SwapBlcokHeadFailedUpdate = TRUE;
                    Fee_PartitionCfg.Fee_SectorHead[swapSectorIndex].Fee_SectorCurrentInfo->SectorWriteFailedCounter++;
                }
            }
            else
            {
                Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_CANCELED;
            }
        }
        else
        {
            Fee_PartitionInfo.ImmWriteState = FEE_IMM_WRITE_NO_SPACE;
        }
    }
    else
    {
        /* Nothing to do. */
    }
}
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

/*
********************************************************************************
* Function Name: Fee_SwapStateMachine
*
* Explanation: Fee swap State machine peration.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SwapStateMachine(void)
{
    Std_ReturnType rtrnValu;
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 eraseSectorIndex = Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseSectorIndex;
    /* If the page swap sector is Pause, it is restored to the state before the Pause. */
    if( FEE_SECTOR_SWAP_PAUSE == Fee_SwapManagerInfo.SwapRequest )
    {
        Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_ON;
        Fee_UpdateSwapRequest();
        Fee_JobManagerInfo.FlsJobResult = Fee_SwapManagerInfo.FlsJobResultBackup;
        Fee_PartitionInfo.RecoverSwapTimer = FEE_TIMER_DELAY;
    }
    else if( FEE_SECTOR_IMM_SWAP_PAUSE == Fee_SwapManagerInfo.SwapRequest )
    {
        Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_IMMEDIATELY_SWAP_ON;
        Fee_JobManagerInfo.FlsJobResult = Fee_SwapManagerInfo.FlsJobResultBackup;
    }
    else if( FEE_ONLY_EARSE_PAUSE == Fee_SwapManagerInfo.SwapRequest )
    {
        if( FEE_SECTOR_NEED_ERASE == Fee_PartitionCfg.Fee_SectorHead[eraseSectorIndex].Fee_SectorCurrentInfo->SectorState )
        {
            Fee_SwapManagerInfo.SwapRequest = FEE_ONLY_EARSE_SECTOR;
            Fee_JobManagerInfo.FlsJobResult = Fee_SwapManagerInfo.FlsJobResultBackup;
            Fee_PartitionInfo.RecoverSwapTimer = FEE_TIMER_DELAY;
        }
        /* If the sector has been erased, there is no need to perform the erase operation again. */
        else
        {
            Fee_SwapManagerInfo.SwapRequest = FEE_SECTOR_SWAP_OFF;
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_DONE;
        }
    }
    else
    {
        /* Nothing to do. */
    }
    /* Sector swap status When completing a block or completing the entire swap sector. */
    if( ((FEE_JOB_SWAP_BLOCK_IDLE == Fee_SwapManagerInfo.SwapJob) ||
         (FEE_JOB_SWAP_DONE == Fee_SwapManagerInfo.SwapJob)) &&
         (FEE_SECTOR_SWAP_OFF != Fee_SwapManagerInfo.SwapRequest) )
    {
        /* Gets the sector or blcok that you want to swap. */
        rtrnValu = Fee_GetSwapBlocks();
        if( (E_OK == rtrnValu) && (FALSE != Fee_SwapManagerInfo.BlockSwapRequired) )
        {
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_OK;
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_WRITE_BLOCK_HEAD;
        }
        /* If not ok is returned, no blocks need to be swap. */
        else if( (FEE_SWAP_PENDING == Fee_SwapManagerInfo.SectorSwapState) && (E_NOT_OK == rtrnValu) )
        {
            /* Erases the sector that was swaped. */
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseFlag = FEE_SECTOR_ERASE_ON;
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseSectorIndex = Fee_SwapManagerInfo.SourceSectorIndex;
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.SwapEraseNextState = FEE_JOB_SWAP_DONE;
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_ERASE;
            Fee_SwapManagerInfo.SwapScanBlockIndex = FEE_VALUE_ZERO;
        }
        else
        {
            /* Nothing to do. */
        }
    }
    else
    {
        /* Nothing to do */
    }
}

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: Fee_SetReservedSector
*
* Explanation: Fee Set reserved sector space.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_SetReservedSector(void)
{
    uint8 idleSectorIndex = FEE_VALUE_ZERO;

    /* If the number of sectors in Free is greater than 1 and space still needs to be
       reserved for immediate data writing, then set the reservation settings. */
    if( (Fee_ScanManagerInfo.ReservedImmSectors != Fee_PartitionInfo.SectorReservedNum) &&
        (Fee_PartitionInfo.SectorFreeNum > FEE_VALUE_ONE) )
    {
        if( E_OK == Fee_BackwardGetSector(FEE_SECTOR_FREE, FEE_SECTOR_DEF, &idleSectorIndex) )
        {
            Fee_PartitionCfg.Fee_SectorHead[idleSectorIndex].Fee_SectorCurrentInfo->SectorState = FEE_SECTOR_RESERVED_FREE;
            Fee_PartitionInfo.SectorFreeNum--;
            Fee_PartitionInfo.SectorReservedNum++;
        }
        else
        {
            /* Nothing to do. */
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_ChkBlockImmediateWriteJob
*
* Explanation: Judge whether the current write task is written immediately.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ChkBlockImmediateWriteJob(void)
{
    uint8 reservedSectorIndex;
    if( (Fee_PartitionInfo.JobNextState == FEE_JOB_WRITE_HED) &&
        (TRUE == Fee_PartitionCfg.Fee_Block[Fee_JobManagerInfo.JobBlockIndex].IsImmediateData) )
    {
        /* Suspend if Swap is not end a block. */
        if( ((FEE_JOB_SWAP_BLOCK_IDLE != Fee_SwapManagerInfo.SwapJob) &&
             (FEE_SECTOR_SWAP_ON == Fee_SwapManagerInfo.SwapRequest)) &&
             (FEE_SWAP_PENDING == Fee_SwapManagerInfo.SectorSwapState) )
        {
            Fee_PartitionInfo.ImmWriteState = FEE_IMM_WRITE_ON_SWAP_INIT;
        }
        else if( (FEE_SECTOR_IMMEDIATELY_SWAP_ON == Fee_SwapManagerInfo.SwapRequest) &&
                 (FEE_SWAP_PENDING == Fee_SwapManagerInfo.SectorSwapState) )
        {
            /* If there is no reserved space for immediate writing, the request
               action for immediate writing cannot be issued. */
            if( FEE_IMM_WRITE_NO_SPACE != Fee_PartitionInfo.ImmWriteState )
            {
                Fee_PartitionInfo.ImmWriteState = FEE_IMM_WRITE_ON_IMM_SWAP_INIT;
            }
            else
            {
                if( E_OK == Fee_BackwardGetSector(FEE_SECTOR_RESERVED_ACTIVATE, FEE_SECTOR_RESERVED_FREE, &reservedSectorIndex) )
                {
                    Fee_PartitionInfo.ImmWriteState = FEE_IMM_WRITE_ON_IMM_SWAP_INIT;
                }
            }
        }
        else
        {
            Fee_PartitionInfo.ImmWriteState = FEE_IMM_WRITE_DONE;
        }
    }
}
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

/*
********************************************************************************
* Function Name: Fee_ActiveVaildSector
*
* Explanation: Fee activation effective sector.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_ActiveVaildSector(void)
{
    uint8 needEraseSectorIndex;

    if( TRUE == Fee_PartitionInfo.noActiveSectors )
    {
        /* After receiving a user request or completing a Scan, it will retrieve valid active sectors
           and determine whether page swapping is necessary based on the usage of the sectors. */
        if( ((Fee_PartitionInfo.JobNextState >= FEE_JOB_WRITE_HED) &&
            (Fee_PartitionInfo.JobNextState <= FEE_JOB_ERASE_BlOCK)) ||
            ((MEMIF_IDLE == Fee_ModuleState) && (FEE_ACTIVE_DELAY <= Fee_ActiveDelay)) )
        {
            /* Check if a valid sector was found, clean Fee_PartitionInfo.noActiveSectors. */
            Fee_CheckValidSector();
            Fee_PartitionInfo.noActiveSectors = FALSE;
        }
        if( (MEMIF_IDLE == Fee_ModuleState) && (TRUE == Fee_PartitionInfo.noActiveSectors) )
        {
            Fee_ActiveDelay++;
        }
    }
    /* If there are Fee sectors that cannot be recognized as valid sectors when powered on,
       they will be aligned for erasure during idle periods. */
    else if( (FALSE == Fee_PartitionInfo.noActiveSectors) &&
             (FEE_VALUE_ZERO < Fee_ScanManagerInfo.ScanSectorNeedEraseNum) &&
             (FEE_SECTOR_SWAP_OFF == Fee_SwapManagerInfo.SwapRequest) &&
             (FEE_JOB_DONE == Fee_PartitionInfo.JobState) &&
             (FEE_JOB_DONE == Fee_PartitionInfo.JobNextState) )
    {
        if( E_OK == Fee_BackwardGetSector(FEE_SECTOR_NEED_ERASE, FEE_SECTOR_DEF, &needEraseSectorIndex) )
        {
            Fee_SwapManagerInfo.SwapRequest = FEE_ONLY_EARSE_SECTOR;
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseFlag = FEE_SECTOR_ERASE_ON;
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.EraseSectorIndex = needEraseSectorIndex;
            Fee_SwapManagerInfo.SwapPartitionInfoSnap.SwapEraseNextState = FEE_JOB_SWAP_DONE;
            Fee_SwapManagerInfo.SwapJob = FEE_JOB_SWAP_ERASE;
        }
    }
    else
    {
        /* Nothing to do. */
    }
}

/*
********************************************************************************
* Function Name: Fee_StateMachineSwitch
*
* Explanation: Fee State machine Switching, processing jobs or swap.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, FEE_CODE) Fee_StateMachineSwitch(void)
{

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_Fee_UNMODIFIED_VAR_NOT_CONST" */
    uint8 sectorIndex = Fee_PartitionInfo.PartitionInfoSnap.SectorIndex;
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

    /* Activate valid active sectors and determine whether to erase invalid sectors. */
    Fee_ActiveVaildSector();

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
    if( FEE_JOB_SCAN_DONE < Fee_PartitionInfo.JobState )
    {
        /* Determine if an internal immediate write request needs to be issued
           to interrupt the current internal Fee swap/erase operation. */
        Fee_ChkBlockImmediateWriteJob();

        if( (FEE_SECTOR_ACTIVATE == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) ||
            (FEE_SECTOR_RESERVED_ACTIVATE == Fee_PartitionCfg.Fee_SectorHead[sectorIndex].Fee_SectorCurrentInfo->SectorState) )
        {
            /* Update the free sector for immediate write reservation. */
            Fee_SetReservedSector();
        }
    }
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

    /* The processing of the upper-layer request is idle. */
    if( FEE_JOB_DONE == Fee_PartitionInfo.JobState )
    {

#if( (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) )
        /* Call Back Fee Notification */
        Fee_NotificationCallBack();
#endif /* (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_END_NOTIFICATION == STD_ON) */

        /* Whether a new upper-layer request has been received
           Can accept user requests for Fee during idle periods
           During non immediate swap/erase periods, it can be paused by the user's write/read request
           During the swap period, it can be interrupted by the user's immediate write request
           During the immediate swap period, it can be paused by the user's read request
           During the immediate swap period, it can be interrupted by the user's immediate write request */
        if( FEE_JOB_DONE != Fee_PartitionInfo.JobNextState )
        {
            /* Polyspace +1 MISRA-C3:14.3 [JUstified:Unset] " NSCA_Polyspace_Fee_Rule14.3 " polyspace +1 DEFECT:USELESS_IF [Justified:Unset] "NSCA_Polyspace_Common_UselessIf" */
            if( FEE_JOB_SCAN_DONE < Fee_PartitionInfo.JobState )
            {
                /* The upper layer has a request accepted and is currently in the swap sector state. */
                if( ((FEE_SECTOR_IMMEDIATELY_SWAP_ON < Fee_SwapManagerInfo.SwapRequest) &&
                      ((FEE_IMM_WRITE_DONE == Fee_PartitionInfo.ImmWriteState) ||
                       (FEE_IMM_WRITE_NO_SPACE == Fee_PartitionInfo.ImmWriteState))) ||
                    ((FEE_JOB_READ == Fee_PartitionInfo.JobNextState) &&
                     (FEE_SECTOR_IMMEDIATELY_SWAP_ON == Fee_SwapManagerInfo.SwapRequest)) )
                {
                    Fee_SwapJobPause();
                }

#if( FEE_IMMEDIATE_WRITE_ENABLE == STD_ON )
                else if( (FEE_IMM_WRITE_ON_SWAP_INIT == Fee_PartitionInfo.ImmWriteState) ||
                         (FEE_IMM_WRITE_ON_IMM_SWAP_INIT == Fee_PartitionInfo.ImmWriteState) )
                {
                    Fee_SwapJobCancel();
                }
                else
                {
                    /* Nothing to do. */
                }
#endif /* (FEE_IMMEDIATE_WRITE_ENABLE == STD_ON) */

            }
            /* If not in the swap sector state, you can switch to processing the upper-level request. */
            if( (FEE_JOB_DONE == Fee_PartitionInfo.JobState) &&
                ((FEE_SECTOR_IMMEDIATELY_SWAP_ON > Fee_SwapManagerInfo.SwapRequest) ||
                 (FEE_IMM_WRITE_NO_SPACE < Fee_PartitionInfo.ImmWriteState)) )
            {
                Fee_PartitionInfo.JobState = Fee_PartitionInfo.JobNextState;
                Fee_ModuleState = Fee_ModuleNextState;
                Fee_PartitionInfo.JobNextState = FEE_JOB_DONE;
                Fee_ModuleNextState = MEMIF_IDLE;
            }
        }
        /* No upper level request was accepted and requires swap sector processing. */
        if( (FEE_SECTOR_SWAP_OFF != Fee_SwapManagerInfo.SwapRequest) &&
            (FEE_JOB_DONE == Fee_PartitionInfo.JobState) )
        {
            Fee_SwapStateMachine();
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_SetModuleMode
*
* Explanation: Service to stop/start the requested read / write / erase jobs and
* the internal management operations.
*
* param: TRUE : Request to close the Fee module.
*        FALSE : Request to enable the Fee module.
*
* retval: None
********************************************************************************
*/
FUNC(void, FEE_CODE) Fee_SetModuleMode(boolean stopServices)
{
    if( FEE_STOP_BY_INTER_ERROR != Fee_PartitionInfo.ModuleRunningState )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        if( TRUE == stopServices )
        {
            Fee_PartitionInfo.ModuleRunningState = FEE_STOP_BY_USER;
        }
        else
        {
            Fee_PartitionInfo.ModuleRunningState = FEE_RUNNING;
        }
    }
}

/*
********************************************************************************
* Function Name: Fee_GetModuleStopState
*
* Explanation: Service to get job result for Fee_SetModuleMode(TRUE).
*
* param: None
*
* retval: E_OK : The Fee module has stopped working.
*         E_NOT_OK : The Fee module has not stopped working.
********************************************************************************
*/
FUNC(Std_ReturnType, FEE_CODE) Fee_GetModuleStopState(void)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (FEE_RUNNING != Fee_PartitionInfo.ModuleRunningState) &&
        (MEMIF_JOB_PENDING != Fee_JobManagerInfo.JobResult ) &&
        (MEMIF_JOB_PENDING != Fee_JobManagerInfo.FlsJobResult) )
    {
        rtrnValu = E_OK;
    }
    return rtrnValu;
}

/*
********************************************************************************
* Function Name: Fee_MainFunction
*
* Explanation: Service to handle the requested read / write / erase jobs and the
*              internal management operations.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, FEE_CODE) Fee_MainFunction(void)
{

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* Check that Fee is initialized. */
    if( MEMIF_UNINIT != Fee_ModuleState )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

#if( FEE_POLLING_MODE == STD_ON )
        if( MEMIF_JOB_PENDING == Fee_JobManagerInfo.FlsJobResult )
        {

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
            Fee_JobManagerInfo.FlsJobResult = Fee_MemAccGetJobResult();
#else
            Fee_JobManagerInfo.FlsJobResult = Fee_PartitionCfg.Fls_FunctionList->GetJobResult();
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

        }
#endif /* FEE_POLLING_MODE == STD_ON */

#if( FEE_FLS_PENDING_TIMEOUT_COUNT > FEE_VALUE_ZERO )
        if( MEMIF_JOB_PENDING == Fee_JobManagerInfo.FlsJobResult )
        {
            Fee_TimeoutCounter++;
        }
        else
        {
            Fee_TimeoutCounter = FEE_VALUE_ZERO;
        }
        if( FEE_FLS_PENDING_TIMEOUT_COUNT < Fee_TimeoutCounter )
        {

#if( FEE_MEMACC_MODE_ENABLE == STD_ON )
            MemAcc_Cancel(FEE_MEMACC_ADDRESS_AREA_ID);
#else
            Fee_PartitionCfg.Fls_FunctionList->Cancel();
            Fee_JobManagerInfo.FlsJobResult = MEMIF_JOB_CANCELED;
#endif /* FEE_MEMACC_MODE_ENABLE == STD_ON */

            if( FEE_JOB_SCAN_DONE < Fee_PartitionInfo.JobState )
            {
                Fee_ModuleState = MEMIF_IDLE;
            }
            Fee_TimeoutCounter = FEE_VALUE_ZERO;
        }
#endif /* ( FEE_FLS_PENDING_TIMEOUT_COUNT > FEE_VALUE_ZERO ) */

        if( FEE_VALUE_ZERO < Fee_PartitionInfo.RecoverSwapTimer )
        {
            Fee_PartitionInfo.RecoverSwapTimer--;
            if( (FEE_SECTOR_IMMEDIATELY_SWAP_ON == Fee_SwapManagerInfo.SwapRequest) &&
                (FEE_TIMER_DELAY > Fee_PartitionInfo.RecoverSwapTimer) )
            {
                Fee_PartitionInfo.RecoverSwapTimer = FEE_VALUE_ZERO;
            }
        }
        if( (FEE_RUNNING == Fee_PartitionInfo.ModuleRunningState) ||
            (MEMIF_JOB_PENDING == Fee_JobManagerInfo.JobResult) ||
            (MEMIF_JOB_PENDING == Fee_JobManagerInfo.FlsJobResult) )
        {
            /* Obtain the next state to be processed. */
            Fee_StateMachineSwitch();

            if( FEE_JOB_DONE != Fee_PartitionInfo.JobState )
            {
                /* Application requested work processing. */
                Fee_JobProcessStateMachine();
            }
            else if( (FEE_ONLY_EARSE_PAUSE < Fee_SwapManagerInfo.SwapRequest) &&
                     (FEE_VALUE_ZERO == Fee_PartitionInfo.RecoverSwapTimer) )
            {
                /* Internal swap work processing. */
                Fee_SwapProcess();
            }
            else
            {
                /* Nothing to do. */
            }
        }

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    }
    else
    {
        /* Report ErrorId to Det. */
        Fee_Det_ErrorReport(FEE_JOB_MAIN_FUNCTION, FEE_E_UNINIT);
    }
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

}

#if( FEE_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: Fee_GetVersionInfo
*
* Explanation: Service to return the version information of the FEE module.
*              (Synchronous)
*
* param: VersionInfoPtr: Pointer to standard version information structure.
*
* retval: None
********************************************************************************
*/
FUNC(void, FEE_CODE) Fee_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA) VersionInfoPtr
)
{

#if( FEE_DEV_ERROR_DETECT == STD_ON )
    /* Check parameter is null pointer. */
    if( NULL_PTR == VersionInfoPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Report error. */
        Fee_Det_ErrorReport(FEE_GET_VERSION_INFO, FEE_E_PARAM_POINTER);
    }
    else
#endif /* FEE_DEV_ERROR_DETECT == STD_ON. */

    {
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_Fee_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.14" */
        VersionInfoPtr->vendorID = FEE_VENDOR_ID;
        VersionInfoPtr->moduleID = FEE_MODULE_ID;
        VersionInfoPtr->sw_major_version = FEE_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = FEE_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = FEE_SW_PATCH_VERSION;
    }
}
#endif /* FEE_VERSION_INFO_API == STD_ON. */

#define FEE_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Fee_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

