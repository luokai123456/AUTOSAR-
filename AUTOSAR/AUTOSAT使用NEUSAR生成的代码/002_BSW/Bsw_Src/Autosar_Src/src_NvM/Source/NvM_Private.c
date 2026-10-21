/*
********************************************************************************
*
* File name: NvM_Private.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.11.10
* Change: New create
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangJipeng/2019.04.08
* Change: V2.0 release.
* Cause: Update
********************************************************************************
* Version: 1.2
* Author/Date: WangJipeng/2019.05.28
* Change: Fix function NvM_MainFunction_ReadAllFinish faildcounter increase error.
* Cause: Bugfix
********************************************************************************
* Version: 1.3
* Author/Date: WangJipeng/2019.05.28
* Change: Fix Crc start value and remain length error.
* Cause: Bugfix
********************************************************************************
* Version: 1.4
* Author/Date: WangJipeng/2019.06.12
* Change: Fix notify BSWM readall/writeall status error.
* Cause: Bugfix
********************************************************************************
* Version: 1.5
* Author/Date: WangJipeng/2019.06.14
* Change: Fix not reser crc value enf of Writeall& readall .
* Cause: Bugfix
********************************************************************************
* Version: 2.0
* Author/Date: WangJipeng/2019.07.17
* Change: Fix the error in state machine RTERY state migration of NvM_MainFunction_WDBI.
* Cause: Bugfix
********************************************************************************
* Version: 2.1
* Author/Date: WangJipeng/2019.10.25
* Change: Add reset CRC calculation results operate in NvM_MainFun_ProtectCrc.
*         Del NVM_REQ_REDUNDANCY_FAILED in NvM_MainFun_ReadRetry
* Cause: Bugfix
********************************************************************************
* Version: 2.2
* Author/Date: Baowanglong/2019.11.12
* Change: Modify the code format
* Cause: Coding Standards
********************************************************************************
* Version: 2.3
* Author/Date: Baowanglong/2019.12.04
* Change: Add multi-block processing results
* Cause: Bugfix
********************************************************************************
* Version: 2.4
* Author/Date: Baowanglong/2019.12.16
* Change: In the NvM_MainFunction_RSDBI function, modify the state order of the
*         NvM_SingleStateMachine function when the state is NVM_STATEMACHINE_BUSY
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date: Baowanglong/2020.02.17
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: Hanbaiyu/2020.03.27
* Change: 1. Delete unapplied functions of NVM_MultiStateMachine_Finish and
          NvM_MainFun_SetBlockInfo.
          2.Initial value for indicator variable of for loop.
* Cause: QAC
********************************************************************************
* Version: 3.2
* Author/Date: Hanbaiyu/2020.05.07
* Change: 1. Add the function of static id comparison.
          2. Add the function of configuration id comparison.
          3. Modify the processing of redundant NVRAM for erase and Invalidate operations.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: Hanbaiyu/2020.05.25
* Change: 1. In the NvM_MainFunction_ReadAllFinish function, add the Judgement
          for NvM_MainFun_CopyDataToRam function which shoud be configure readall.
          2. Modify the implementation of BSWM information.
          3. In the NvM_MainFun_WriteRetry function, modify the problem which pass
          the wrong address to the underlying write function.
          4. Judge whether the pointer to ram is null before use.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: Hanbaiyu/2020.05.29
* Change: Modify the setting of ram status when the read/write operation is completed.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: Hanbaiyu/2020.06.28
* Change: Delete unused functions and add else branch for judgment statement.
* Cause: QAC
********************************************************************************
* Version: 3.6
* Author/Date: Hanbaiyu/2020.06.28
* Change: 1. In the function NvM_MainFun_WriteRetry, Modify problem that cannot
          switch to the next state for redundant block.
          2. Move the operation whitch update crc of administrative block to
          the write operation has succeed.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
*         3. Add the function NvM_MemmoryCopy to copy data in 4 byte aligned.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: Hanbaiyu/2020.10.27
* Change: Delete redundant assignments.
* Cause: QAC.
********************************************************************************
* Version: 3.9
* Author/Date: HanBY/2020.11.02
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: HanBY/2020.11.04
* Change: Deleting memrory maps for variable or function declarations.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: HanBY/2020.11.30
* Change: In the function of NvM_MainFun_WriteAll, add the judgement to update
*         job result only for the block when it is not in the single block queue.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: HanBY/2020.12.02
* Change: 1. Correcting the disabled condition of redundant loss flag.
*         2. Fixed the problem that immediate write job could interrupt an
*            immediate write job.
*         3. In the function of NVM_MultiStateMachine_WriteAll, using function
*            NvM_MemmoryCopy to replace the loop copy.
*         4. Modify the type of the partial loop indicator variable from uint8
*            to uint16 to avoid dead loop caused by excessive loop length.
* Cause: Bugfix
********************************************************************************
* Version: 3.13
* Author/Date: HanBY/2020.12.05
* Change: 1. In tne function of NVM_MultiStateMachine_WriteAll, modify the retry
*            numbers of explicit synchronization callback failed.
*         2. In the function of NVM_MultiStateMachine_ReadAll, modify the judgment
*            steps of explicit synchronous callback.
* Cause: Bugfix
********************************************************************************
* Version: 3.14
* Author/Date: HanBY/2020.12.07
* Change: In tne function of NvM_MainFun_GetNewBlock, add judgment of current write
*         operation to avoid setting write immediate flag in other operations.
* Cause: Bugfix
********************************************************************************
* Version: 3.15
* Author/Date: HanBY/2020.12.24
* Change: In tne function of NvM_MainFun_ProcessInit, set return value to TRUE for
*         the situation that configured explicit synchronization callback function.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: HanBY/2021.05.24
* Change: Modify the logic of function NVM_Single_StateMachine_DualStates to eliminate
*         the influence of different compilers have different results for type conversion.
* Cause: Bugfix
********************************************************************************
* Version: 3.17
* Author/Date: HanBY/2021.06.30
* Change: Modify titles of function NvM_MainFunction_Finish, NvM_MainFun_CheckConfigureID,
*         NvM_MainFunction_RSDBI.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: HanBY/2021.07.09
* Change: Set the job result to NVM_REQ_NOT_OK when static id check was failed
*         in the function NvM_MainFun_CheckCrc to aovid continue copying data to
*         ram block.
* Cause: Bugfix
********************************************************************************
* Version: 3.19
* Author/Date: HanBY/2021.07.30
* Change: Add the function of write verification to ensure that the write operation
*         has completed successfully.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: HanBY/2021.08.30
* Change: For multi block job readall and writeall, add the block length check to
*         prevent array out of bounds or data loss due to configuration errors.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: HanBY/2021.11.01
* Change: In the function NvM_MemmoryCopy, modify the copy length from 4 byte to
*         1 byte to avoid hard fault.
* Cause: Bugfix
********************************************************************************
* Version: 3.22
* Author/Date: HanBY/2021.11.19
* Change: Modify the bug that NVM_SuccessCounter is not increased correctly, it
*         may cause the redundant block write successfully condition wrong.
* Cause: Bugfix
********************************************************************************
* Version: 3.23
* Author/Date: HanBY/2021.12.30
* Change: Modify the way of crc calculation in read/write job, to aovid the parameter
*         type error caused by compiler optimization.
* Cause: Bugfix
********************************************************************************
* Version: 3.24
* Author/Date: HanBY/2022.02.10
* Change: Modify the bug that erase and invalidate job do not clear the crc in
*         administrative block, it may cause skip write job when enable write comparison
*         mechanism.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: LiK/2022.06.17
* Change: Modify Buffer for write verify variable NvM_WriteVerifyBuffer and add
*         the macro NVM_WRITEVERIFY_ENABLE to precompile.
* Cause: Optimization
********************************************************************************
* Version: 3.26
* Author/Date: LiDY/2023.03.03
* Change: Add the function of counting the number of Fee devices in the queue.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: LiDY/2023.04.27
* Change: NVM_BLOCK_TOTAL_NUMBER change name to NVM_NUM_OF_BLOCK_TOTAL.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: LiDY/2023.04.28
* Change: Add NvM_CancelWriteAll execution branch when NvM_WriteAll accepts a
*         equest but does not execute in the mainfunction.
* Cause: Bugfix
********************************************************************************
* Version: 3.29
* Author/Date: LiDY/2023.06.01
* Change: Add return NVM_REQ_BLOCK_SKIPPED when the block is not configured
*         NvMSelectBlockForReadAll or NvMSelectBlockForWriteAll(CCOREDBUG-3183).
* Cause: Bugfix
********************************************************************************
* Version: 3.30
* Author/Date: WangLX/2023.09.13
* Change: In the function NvM_MainFun_Busy, delete NvM_RetryCounter clean
*         operation.
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: WangLX/2023.09.13
* Change: In the function NvM_MainFun_CancelWriteAll, add clean operation to
*         the NvM_CurMultiJob variable.
* Cause: Bugfix
********************************************************************************
* Version: 3.32
* Author/Date: WangLX/2023.10.07
* Change: 1. Delete block length check code.
*         2. Fix Compilation Warning.
* Cause: Optimization
********************************************************************************
* Version: 3.33
* Author/Date: WangLX/2023.10.09
* Change: Delete block length check code in the function
*         NVM_MultiStateMachine_ReadAll.
* Cause: Bugfix
********************************************************************************
* Version: 3.34
* Author/Date: WangLX/2023.11.16
* Change: NvM_MainFun_CancelWriteAll Calls BswM to BswM_NvM_CurrentJobMode
*         change the parameter to NVM_WRITE_ALL, NVM_REQ_CANCELED.
* Cause: Bugfix
********************************************************************************
* Version: 3.35
* Author/Date: WangLX/2023.11.16
* Change: Remove the operation of modifying the current Block state to the
*         NVMR_REQ_CANCELED state in the NvM_MainFun_CancelWriteAll function.
* Cause: Bugfix
********************************************************************************
* Version: 3.36
* Author/Date: WangLX/2024.01.24
* Change: Modify the "NvM_MainFun_CheckConfigureID" function When the
*         configurationID does not match, change "NvRamState" to
*         "NVM_BLOCK_CHANGED".
* Cause: Bugfix
********************************************************************************
* Version: 3.37
* Author/Date: WangLX/2024.04.01
* Change: Modify the label of the input parameter Ptrclass for NvM_CalculateCrc.
* Cause: Optimization
********************************************************************************
* Version: 3.38
* Author/Date: WangLX/2024.04.25
* Change: Add a memory-map label to function and variable declarations.
* Cause: Bugfix
********************************************************************************
* Version: 3.39
* Author/Date: WangLX/2024.07.31
* Change: Optimization WriteAll and WriteBlock state machine.
* Cause: Optimization
********************************************************************************
* Version: 3.40
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.41
* Author/Date: WangLX/2024.08.13
* Change: Delete NvM-GeneralCheck function declaration.
* Cause: Optimization
********************************************************************************
* Version: 3.42
* Author/Date: WangLX/2024.09.03
* Change: Add the current task mode judgment to function
*         NvM_MainFun_Verify_Compare.
* Cause: Bugfix
********************************************************************************
* Version: 3.43
* Author/Date: WangLX/2024.12.20
* Change: Modify the NvM_MainFun_Verify_Compare function for verify failed.
* Cause: Bugfix
********************************************************************************
* Version: 3.44
* Author/Date: WangLX/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
* Cause: Update
********************************************************************************
* Version: 3.45
* Author/Date: ZengJX/2025.06.04
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.46
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.47
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.48
* Author/Date: ZengJX/2025.06.16
* Change: Modify the function NvM_MainFun_CancelWriteAll and NvM_MainFun_ValidateAll
*         to notify BswM.
* Cause: Update
********************************************************************************
* Version: 3.49
* Author/Date: ZengJX/2025.06.23
* Change: Fix the bug that the Block that restores the default value cannot be
*         written in the first NvM_WriteAll().
* Cause: Bugfix
********************************************************************************
* Version: 3.50
* Author/Date: ZengJX/2025.08.01
* Change: When NVRAM blocks with NvMBlockUseSetRamBlockStatus disable is processed
*         NvM_WriteAll, NvM module shall treat the block as valid.
* Cause: Bugfix
********************************************************************************
* Version: 3.51
* Author/Date: ZengJX/2025.08.04
* Change: Fix the NvRamState condition in NvM_WriteAll when NVM_SET_RAM_BLOCK_STATUS_API
*         is configured as STD_ON.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "NvM_Private.h"

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
#define NVM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Explicit synchronization flag. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(boolean, NVM_VAR_INIT) NvM_SyncMechanismUesd = FALSE;
/* NvM write configId flag. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(boolean, NVM_VAR_INIT) NvM_WriteCfgidFlg = FALSE;
/* NvM configId mismatch flag. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(boolean, NVM_VAR_INIT) NvM_CfgidMismatch = FALSE;
/* Flag of read operation for DATASET NVRAM when data index point rom. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(boolean, NVM_VAR_INIT) NvM_ReadRomFlg = FALSE;
/* Multi Operation state machine. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(NvM_Statemachine_Type, NVM_VAR_INIT) NvM_MultiStateMachine = NVM_STATEMACHINE_IDLE;
/* Sign Redundant type block read another address. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint8, NVM_VAR_INIT) NvM_RetryCounter = NVM_INIT_0;
/* Multi block operation fail counter. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint8, NVM_VAR_INIT) NvM_FailedCounter = NVM_INIT_0;
/* Multi block operation first execution flag. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint8, NVM_VAR_INIT) NvM_Multi_FirstFlg = NVM_INIT_0;
/* Multi block operation fail counter. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint8, NVM_VAR_INIT) NvM_CurMultiJob = NVM_INIT_0;
/* Request successful count. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint8, NVM_VAR_INIT) NVM_SuccessCounter = NVM_INIT_0;
/* Redundant type block number. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint8, NVM_VAR_INIT) NVM_RedundantNumber = NVM_INIT_0;
/* Immediate write flag. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint8, NVM_VAR_INIT) Nvm_ImmediateWrite = NVM_INIT_0;
/* Record multiple block request status. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint8, NVM_VAR_INIT) Nvm_MultiReqTemp = NVM_INIT_0;
/* Buffer for write verify. */
#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint8, NVM_VAR_INIT) NvM_WriteVerifyBuffer[NVM_WRITEVERIFY_LENGTH + NVM_VALUE_ONE] =
{
    NVM_INIT_0
};
/* Buffer for write verify. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(uint16, NVM_VAR_INIT) NvM_WriteVerifyLength = NVM_INIT_0;
#endif

#define NVM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
#define NVM_START_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* CRC calculation size table. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static CONST(uint8, NVM_CONST) Nvm_CrcCalc_Size_Table[NVM_CRCCALC_API_NUMBER] =
{
    NVM_BLOCK_CRC_SIZE_UNUSE,
    NVM_BLOCK_CRC_SIZE_8,
    NVM_BLOCK_CRC_SIZE_16,
    NVM_BLOCK_CRC_SIZE_32
};

#define NVM_STOP_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define NVM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

static FUNC(void, NVM_CODE) NVM_Single_StateMachine_SoleState
(
    NvM_Statemachine_Type State
);
static FUNC(void, NVM_CODE) NVM_Single_StateMachine_DualStates
(
    uint8 Result,
    NvM_Statemachine_Type State1,
    NvM_Statemachine_Type State2
);
static FUNC(void, NVM_CODE) NVM_Single_StateMachine_ThrStates
(
    uint8 Result,
    NvM_Statemachine_Type State1,
    NvM_Statemachine_Type State2,
    NvM_Statemachine_Type State3
);
static FUNC(void, NVM_CODE) NVM_Multi_StateMachine_SoleState(
    NvM_Statemachine_Type State
);
static FUNC(void, NVM_CODE) NVM_Multi_StateMachine_ThrStates
(
    uint8 Result,
    NvM_Statemachine_Type State1,
    NvM_Statemachine_Type State2,
    NvM_Statemachine_Type State3
);
static FUNC(void, NVM_CODE) NVM_MultiBlock_Set_ServiceId(uint8 ServiceId);
static FUNC(void, NVM_CODE) NVM_SingleBlock_CallBack
(
    uint16 BlockId,
    uint8 BlockRequest,
    NvM_RequestResultType JobResult
);
static FUNC_P2VAR(uint8, NVM_APPL_DATA, NVM_CODE) NvM_MainFun_GetRomBlockAddr(void);
static FUNC(void, NVM_CODE) NVM_MultiStateMachine_WriteAll(void);
static FUNC(void, NVM_CODE) NVM_MultiStateMachine_ReadAll(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_ProcessInit(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_ReadBlock(void);
static FUNC(void, NVM_CODE) NvM_MainFun_WriteBlock(void);
static FUNC(void, NVM_CODE) NvM_MainFun_WriteReDundant(void);
static FUNC(void, NVM_CODE) NvM_MainFun_WriteRetry(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_EraseNvBlock(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_EraseReDundant(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_InvalidateNvBlock(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_InvalidateReDundant(void);
static FUNC(void, NVM_CODE) NvM_MainFun_RestoreRequest(void);
static FUNC(void, NVM_CODE) NvM_MainFun_RestoreNvBlock(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_Busy(void);
static FUNC(void, NVM_CODE) NvM_MainFun_ProtectCrc(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_CheckCrc(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_ReadRetry(void);
static FUNC(void, NVM_CODE) NvM_QueueJob_ResetInfo(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_ReadFinish(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_FinishSwitch(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_WriteFinish(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_Finish(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_WriteAllFinish(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_ReadAllFinish(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_RDBI(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_WDBI(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_RSDBI(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_EDBI(void);
static FUNC(void, NVM_CODE) NvM_MainFunction_IDBI(void);
static FUNC(void, NVM_CODE) NvM_MainFun_ReadAll(void);
static FUNC(void, NVM_CODE) NvM_MainFun_WriteAll(void);
static FUNC(void, NVM_CODE) NvM_MainFun_CancelWriteAll(void);
static FUNC(void, NVM_CODE) NvM_MainFun_CopyRomData
(
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) Romaddress
);
static FUNC(uint8, NVM_CODE) NvM_MainFun_WriteDataToMirror(void);
static FUNC(void, NVM_CODE) NvM_MainFun_CopyDataToRam(void);
static FUNC(void, NVM_CODE) NvM_MainFun_CheckConfigureID(void);
static FUNC(uint8, NVM_CODE) NvM_MainFun_CheckCrcFinish(void);
static FUNC(void, NVM_CODE) NvM_MemmoryCopy
(
    P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) SrcAddr,
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DesAddr,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint16 length
);

#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
static FUNC(void, NVM_CODE) NvM_IsNeedWriteVerify(void);
static FUNC(void, NVM_CODE) NvM_MainFun_Verify_Request(void);
static FUNC(void, NVM_CODE) NvM_MainFun_Verify_Compare(void);
#endif

static FUNC(uint32, NVM_CODE) NvM_CalculateCrc
(
    P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) DataAddr,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint16 Length,
    uint32 CrcValue,
    boolean IsFirstCall
);

#define NVM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define NVM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Single Operation state machine. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
VAR(NvM_Statemachine_Type, NVM_VAR_INIT) NvM_SingleStateMachine = NVM_STATEMACHINE_IDLE;

#define NVM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define NVM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: NVM_Single_StateMachine_SoleState
*
* Explanation: Function to signal block state machine setup.
*
* param: State machine setup.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
static FUNC(void, NVM_CODE) NVM_Single_StateMachine_SoleState(NvM_Statemachine_Type State)
{
    NvM_SingleStateMachine = State; /* Ready to start State. */
}

/*
********************************************************************************
* Function Name: NVM_Single_StateMachine_DualStates
*
* Explanation: Function to 2 signal block state machine setup.
*
* param: Result: Job result.
*        State1: A state of a block.
*        State2: A state of a block.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
static FUNC(void, NVM_CODE) NVM_Single_StateMachine_DualStates
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint8 Result,
    NvM_Statemachine_Type State1,
    NvM_Statemachine_Type State2
)
{
    if( NVM_TRANSITION_STATE1 == Result )    /* Is the previous processing successful? */
    {
        NvM_SingleStateMachine = State1;    /* Ready to start State1. */
    }
    else
    {
        NvM_SingleStateMachine = State2;    /* Ready to start State2. */
    }
}

/*
********************************************************************************
* Function Name: NVM_Single_StateMachine_ThrStates
*
* Explanation: Function to 3 signal block state machine setup.
*
* param: Result: Job result.
*        State1: A state of a block.
*        State2: A state of a block.
*        State3: A state of a block.
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NVM_Single_StateMachine_ThrStates
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint8 Result,
    NvM_Statemachine_Type State1,
    NvM_Statemachine_Type State2,
    NvM_Statemachine_Type State3
)
{
    switch( Result )    /* Select different states based on the result of last processing. */
    {
        case NVM_TRANSITION_STATE1: NvM_SingleStateMachine = State1;
            break; /* Ready to start State1. */
        case NVM_TRANSITION_STATE2: NvM_SingleStateMachine = State2;
            break; /* Ready to start State2. */
        case NVM_TRANSITION_STATE3: NvM_SingleStateMachine = State3;
            break; /* Ready to start State3. */
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        default: break;
    }
}

/*
********************************************************************************
* Function Name: NVM_Multi_StateMachine_SoleState
*
* Explanation: Function to signal block state machine setup.
*
* param: State machine setup.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
static FUNC(void, NVM_CODE) NVM_Multi_StateMachine_SoleState(NvM_Statemachine_Type State)
{
    NvM_MultiStateMachine = State;  /* Waiting for the next block to process. */
}
/*
********************************************************************************
* Function Name: NVM_Multi_StateMachine_ThrStates
*
* Explanation: Function to 3 multi block state machine setup.
*
* param: Result: Job result.
*        State1: A state of a block.
*        State2: A state of a block.
*        State3: A state of a block.
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NVM_Multi_StateMachine_ThrStates
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint8 Result,
    NvM_Statemachine_Type State1,
    NvM_Statemachine_Type State2,
    NvM_Statemachine_Type State3
)
{
    switch( Result )    /* Select different states based on the result of last processing. */
    {
        case NVM_TRANSITION_STATE1: NvM_MultiStateMachine = State1;
            break;      /* Ready to start State1. */
        case NVM_TRANSITION_STATE2: NvM_MultiStateMachine = State2;
            break;      /* Ready to start State2. */
        case NVM_TRANSITION_STATE3: NvM_MultiStateMachine = State3;
            break;      /* Ready to start State3. */
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        default: break;
    }
}

/*
********************************************************************************
* Function Name: NVM_MultiBlock_Set_ServiceId
*
* Explanation: Funtion to set ServiceId for multiblcok.
*
* param: ServiceId:Unique Service ID of NVRAM manager service.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
static FUNC(void, NVM_CODE) NVM_MultiBlock_Set_ServiceId(uint8 ServiceId)
{
    if( TRUE == NvM_Multi_FirstFlg )    /* First of multi block operation. */
    {
        /* Record the current multi block processing is write all. */
        NvM_CurMultiJob = ServiceId;
        if( NVM_WRITE_ALL == NvM_CurMultiJob )
        {
            if( TRUE == NvM_WriteCfgidFlg )
            {
                /* Setup starts in Block 2,write block 1 finally. */
                NvM_QueueCrrntJob.CurBlockId = NVM_BLOCK_STARTID + NVM_VALUE_ONE;
                /* Reset the remaining number to all. */
                NvM_QueueCrrntJob.RemainNum = NVM_BLOCK_REMAIN_NUMBER;
            }
            else
            {
                /* Setup starts in Block 2. */
                NvM_QueueCrrntJob.CurBlockId = NVM_BLOCK_STARTID + NVM_VALUE_ONE;
                /* Reset the remaining number to all. */
                NvM_QueueCrrntJob.RemainNum = NVM_BLOCK_REMAIN_NUMBER - NVM_VALUE_ONE;
            }
        }
        else if( NVM_READ_ALL == NvM_CurMultiJob )
        {
            /* Clear configid mismatch flag. */
            NvM_CfgidMismatch = FALSE;
            /* Clear write configid flag. */
            NvM_WriteCfgidFlg = FALSE;
            /* Setup starts in Block 1. */
            NvM_QueueCrrntJob.CurBlockId = NVM_BLOCK_STARTID;
            /* Reset the remaining number to all. */
            NvM_QueueCrrntJob.RemainNum = NVM_BLOCK_REMAIN_NUMBER;
        }
        else
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Do Nothing. */
        }
        NvM_Multi_FirstFlg = FALSE;     /* Set the Start sign. */

/* Enable fast mode. */
#if( NVM_DRV_MODE_SWITCH == STD_ON )
        MemIf_SetMode(MEMIF_MODE_FAST);
#endif
    }
    else
    {
        if( (NvM_QueueCrrntJob.CurBlockId < NVM_NUM_OF_BLOCK_TOTAL)
            && (NvM_QueueCrrntJob.RemainNum > NVM_INIT_0) )
        {
            /* Process the next ID in sequence. */
            NvM_QueueCrrntJob.CurBlockId++;
            /* Complete a ID processing, reduce the remaining number. */
            NvM_QueueCrrntJob.RemainNum--;
            if( NVM_WRITE_ALL == NvM_CurMultiJob )
            {
                if( (NVM_INIT_0 == NvM_QueueCrrntJob.RemainNum) && (TRUE == NvM_WriteCfgidFlg) )
                {
                    NvM_QueueCrrntJob.CurBlockId = NVM_BLOCK_STARTID;
                    NvM_WriteCfgidFlg = FALSE;
                }
            }
        }
    }
    /* NvM module's RAM mirror is not used. */
    NvM_SyncMechanismUesd = FALSE;
    /* Set job result to OK. */
    NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
}

/*
********************************************************************************
* Function Name: NVM_SingleBlock_CallBack
*
* Explanation: Function to notice upper block result by callback.
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
*                 A NVRAM block descriptor contains all needed information about a
*                 single NVRAM block.
*        BlockRequest: Unique Service ID of NVRAM manager service.
*        JobResult: Covers the job result of the previous processed single block job.
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NVM_SingleBlock_CallBack
(
    uint16 BlockId,
    uint8 BlockRequest,
    NvM_RequestResultType JobResult
)
{
    /* NvMSingleBlockCallback is configured. */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
    if( (NvM_Block_Descriptor_Table[BlockId].NvMSingleBlockCallback != NULL_PTR)
        && (JobResult != NVM_REQ_PENDING) )
    {
        /* Call the block specific callback routine. */
        (void)NvM_Block_Descriptor_Table[BlockId].NvMSingleBlockCallback(BlockRequest, JobResult);
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_GetRomBlockAddr
*
* Explanation: Function to get rom block address.
*
* param: None
*
* retval: Rom block address
*
********************************************************************************
*/
static FUNC_P2VAR(uint8, NVM_APPL_DATA, NVM_CODE) NvM_MainFun_GetRomBlockAddr(void)
{
    uint8  dateIndexTemp = NVM_INIT_0;
    uint8* retValue = NULL_PTR;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Get managment information of current job. */
    blockMngmnt = &NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId];
    /* Get block definition of current jobc */
    blockTab = &NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId];
    /* Check if the dataset point the NV for dataset NVRAM. */
    if( (NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType) &&
        (blockMngmnt->DataIndex >= blockTab->NvBlockNum) )
    {
        /* Get date index of rom block. */
        dateIndexTemp = blockMngmnt->DataIndex - blockTab->NvBlockNum;
    }
    else if( blockTab->RomAddr != NULL_PTR )
    {
        retValue = blockTab->RomAddr;
    }
    else
    {
        /* Do nothing. */
    }
    /* Check if the rom block is configed. */
    if( (dateIndexTemp < blockTab->RomBlockNum) && (blockTab->RomAddr != NULL_PTR) )
    {
        /* Check the data index for block type of DATASET and the index is ponits to nv block. */
        if( (NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType )
            && (blockMngmnt->DataIndex >= blockTab->NvBlockNum) )
        {
            /* PolySpace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_NvM_18.4" */
            retValue = blockTab->RomAddr + (dateIndexTemp * (blockTab->NvBlockLength -   /* PRQA S 488 */ /* NSCA_QAC_NvM_Rule_18.4 */
            Nvm_CrcCalc_Size_Table[blockTab->CrcType] - NVM_STATICID_LENGTH) );
        }
    }

    return retValue;
}

/*
********************************************************************************
* Function Name: NVM_MultiStateMachine_WriteAll
*
* Explanation: Function to identify whether blocks need to be written in writeall.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NVM_MultiStateMachine_WriteAll(void)
{
    uint16 locBlockId;
    uint16 tryCounter;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get the block ID currently processed. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get managment information of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */
    /* Set next status to calculate crc */
    NvM_MultiStateMachine = NVM_STATEMACHINE_CRCCALC;
    NvM_SyncMechanismUesd = FALSE;
    NvM_QueueCrrntJob.CrcValu = NVM_CRC_INIT_VALUE; /* reset the crc start value. */

    /* NvMSelectBlockForWriteAll is configured. */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
    if( NVM_SELECT_BLOCK_4_WRITEALL_ON == NvM_Block_Descriptor_Table[locBlockId].Select4WriteAll )
    {
        /* Check lock status, write protection status, ramblock status. */
        if( (NVM_BLOCK_LOCKED == (blockMngmnt->NvRamState & NVM_BLOCK_LOCKED)) ||
            ((NVM_BLOCK_PRTCT_ON == (blockMngmnt->NvRamState & NVM_BLOCK_PRTCT_ON)) &&
            (FALSE == blockMngmnt->NvmLossRedun))
#if ( NVM_SET_RAM_BLOCK_STATUS_API == STD_ON )
            /* SWS_NvM_00344 */
            || ( ((blockMngmnt->NvRamState & (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED)) != (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED))
                 && (NVM_BLOCK_SETBLOCKSTATUS_ON == blockTab->UseSetRamBlockStatus))
#endif /* NVM_SET_RAM_BLOCK_STATUS_API == STD_ON */
        )
        {
            /* Skip the block. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_BLOCK_SKIPPED;
            /* End processing flow, reset process information. */
            NvM_MainFunction_WriteAllFinish();
        }
        else
        {
            /* Check if explicit synchronization is configured. */
            if( (NVM_BLOCK_USE_SYNC_MECHANISM_ON == blockTab->SyncMechanism) &&   /* NvMBlockUseSyncMechanism is configured. */
                    (blockTab->NvMWriteRamBlockToNvCallback != NULL_PTR) &&    /* NvMWriteRamBlockToNvCallback is configured. */
                    (blockTab->NvBlockLength <= NVM_BLOCK_MAX_LENGTH) )   /* The size of the mirrored image is large enough. */
            {
                NvM_SyncMechanismUesd = TRUE;   /* NvM module's RAM mirror is used. */
            }
            blockMngmnt->RemainLegth = blockTab->NvBlockLength - Nvm_CrcCalc_Size_Table[blockTab->CrcType];
            blockMngmnt->CurRamAddr = Nvm_InternalBuffer;   /* Use the NVM internal ram mirror. */
            /* Set the static id for Nvm_InternalBuffer. */
            Nvm_InternalBuffer[NVM_STATICID_SECOND_BIT] = (uint8)(NvM_QueueCrrntJob.CurBlockId & NVM_STATICID_MASK);
            Nvm_InternalBuffer[NVM_STATICID_FIRST_BIT] = (uint8)((NvM_QueueCrrntJob.CurBlockId >>
                                                         NVM_STATICID_SHIFT_BIT) & NVM_STATICID_MASK);
            /* Check if enable NvM_SyncMechanismUesd. */
            if( TRUE == NvM_SyncMechanismUesd )
            {
                for( tryCounter = NVM_INIT_0; tryCounter < NVM_REPEAT_MIRROR_OPERATIONS; tryCounter++ )
                {
                    /* Copy data by callback. */
                    /* Polyspace +1 RTE:COR [JUstified:Unset] "NSCA_Polyspace_NvM_CorrectnessCondition" */
                    if( E_OK == blockTab->NvMWriteRamBlockToNvCallback(&Nvm_InternalBuffer[NVM_STATICID_LENGTH]) )
                    {
                        /* Validate the RAM after called explict synchronization. */
                        blockMngmnt->NvRamState |= (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED);
                        break;
                    }
                }
                if( NVM_REPEAT_MIRROR_OPERATIONS == tryCounter )
                {
                    /* Set result to unsuccessfully */
                    NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
                    /* End processing flow, reset process information. */
                    NvM_MainFunction_WriteAllFinish();
                }
                else
                {
                    /* crc protecting. */
                    NvM_MainFun_ProtectCrc();
                }
            }
            else if( blockTab->RamAddr != NULL_PTR )
            {
                NvM_MemmoryCopy(blockTab->RamAddr, &Nvm_InternalBuffer[NVM_STATICID_LENGTH],
                    blockMngmnt->RemainLegth - NVM_STATICID_LENGTH);
                /* crc protecting. */
                NvM_MainFun_ProtectCrc();
            }
            else
            {
                /* Skip the block. */
                NvM_QueueCrrntJob.JobResult = NVM_REQ_BLOCK_SKIPPED;
                /* End processing flow, reset process information. */
                NvM_MainFunction_WriteAllFinish();
            }
        }
    }
    else
    {
        /* Set job result to OK. */
        NvM_QueueCrrntJob.JobResult = NVM_REQ_BLOCK_SKIPPED;
        /* End processing flow, reset process information. */
        NvM_MainFunction_WriteAllFinish();
    }
}

/*
********************************************************************************
* Function Name: NVM_MultiStateMachine_ReadAll
*
* Explanation: Function to identify whether blocks need to be read in readall.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NVM_MultiStateMachine_ReadAll(void)
{
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Get the block ID currently processed. */
    locBlockId = NvM_QueueCrrntJob.CurBlockId;
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get managment information of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */

    /* NvMSelectBlockForReadAll is configured. */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
    if( NVM_SELECT_BLOCK_4_READALL_ON == NvM_Block_Descriptor_Table[locBlockId].Select4ReadAll )
    {
        if( NVM_BLOCK_MANAGENMENT_DATASET == NvM_Block_Descriptor_Table[locBlockId].ManagementType )
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_BLOCK_SKIPPED;
            NvM_MultiStateMachine = NVM_STATEMACHINE_FINISH;
        }
        /* NvMBlockUseSyncMechanism is configured. */
        else if( (NVM_BLOCK_USE_SYNC_MECHANISM_ON == blockTab->SyncMechanism) && (blockTab->NvBlockLength <= NVM_BLOCK_MAX_LENGTH)
                  && (blockTab->NvMReadRamBlockFromNvCallback != NULL_PTR) )
        {
            NvM_SyncMechanismUesd = TRUE;   /* NvM module's RAM mirror is used. */
            NvM_MultiStateMachine = NVM_STATEMACHINE_REQUEST;   /* Ready to request reading. */
        }
        else if( blockTab->RamAddr != NULL_PTR )    /* Meeting the read condition. */
        {
            /* Use the nvm private ram */
            blockMngmnt->RamAddr = blockTab->RamAddr;
            NvM_MultiStateMachine = NVM_STATEMACHINE_REQUEST;   /* Ready to request reading. */
        }
        else
        {
            /* Read conditions are not satisfied. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_BLOCK_SKIPPED;
            /* End the operation of the current block. */
            NvM_MultiStateMachine = NVM_STATEMACHINE_FINISH;
        }
    }
    else
    {
        /* Set job result to OK */
        NvM_QueueCrrntJob.JobResult = NVM_REQ_BLOCK_SKIPPED;
        /* End the operation of the current block. */
        NvM_MultiStateMachine = NVM_STATEMACHINE_FINISH;
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_ProcessInit
*
* Explanation: Function to Prepare for block processing.
*
* param: None
*
* retval: TRUE: Request successful,take the next step.
*         FALSE: Error occurred,end request.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_ProcessInit(void)
{
    uint8 rtrnValu = TRUE;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Get managment information of current job. */
    blockMngmnt = &NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId];
    /* Get block definition of current job. */
    blockTab = &NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId];

    NvM_QueueCrrntJob.CrcValu = NVM_CRC_INIT_VALUE; /* reset the crc start value. */
    NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;  /* Set status to pending. */
    blockMngmnt->CurRamAddr = Nvm_InternalBuffer;   /* Use the NVM internal ram mirror. */
    /* Reset Residual length. */
    blockMngmnt->RemainLegth = blockTab->NvBlockLength - Nvm_CrcCalc_Size_Table[blockTab->CrcType];
    NvM_SyncMechanismUesd = FALSE;   /* NvM module's RAM mirror is not used. */

    /* An empty address request from the upper. */
    if( NULL_PTR == blockMngmnt->RamAddr)
    {
        /* Check if configured with permanent ram block. */
        if( NULL_PTR == blockTab->RamAddr )
        {
            /* Set result to unsuccessfully. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
            rtrnValu = FALSE;
        }
        else
        {
            blockMngmnt->RamAddr = blockTab->RamAddr;
        }
    }

    /* Check if NvMBlockUseSyncMechanism is enable. */
    if( (NVM_BLOCK_USE_SYNC_MECHANISM_ON == blockTab->SyncMechanism) && (blockTab->NvBlockLength <= NVM_BLOCK_MAX_LENGTH) )
    {
        /* Check current operation type. */
        if( NVM_WRITE_BLOCK == blockMngmnt->CtrlType )
        {
            /* Check if explicit synchronization callbacks can be used. */
            if( blockTab->NvMWriteRamBlockToNvCallback != NULL_PTR )
                {
                    rtrnValu = TRUE;
                    /* Set explicit synchronization callbacks flag. */
                    NvM_SyncMechanismUesd = TRUE;
                }
        }
        /* Check if explicit synchronization callbacks can be used. */
        else if( blockTab->NvMReadRamBlockFromNvCallback != NULL_PTR )
        {
            rtrnValu = TRUE;
            /* Set explicit synchronization callbacks flag. */
            NvM_SyncMechanismUesd = TRUE;
        }
        else
        {
            /* Do nothing. */
        }
    }

    /* The upper layer requests to write data. */
    if( (NVM_WRITE_BLOCK == blockMngmnt->CtrlType) && (TRUE == rtrnValu) )
    {
        rtrnValu = NvM_MainFun_WriteDataToMirror();
    }
    /* Notifies the state of the BswM block. */
    if( NVM_BSWM_INFORMATION_ON == NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].BswMInform )
    {
        /* Notify bswm of blockid and status currently processed. */
        BswM_NvM_CurrentBlockMode(NvM_QueueCrrntJob.CurBlockId, NVM_REQ_PENDING);
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_WriteDataToMirror
*
* Explanation: Function to write data from RAM to RAM Mirror
*
* param: None
*
* retval: TRUE: Write data to RAM Mirror successfully.
          FALSE: Write data to RAM Mirror  unsuccessfully.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_WriteDataToMirror(void)
{
    uint16 tryCounter;
    uint8 rtrnValu = TRUE;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Get managment information of current job. */
    blockMngmnt = &NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId];
    /* Get block definition of current job. */
    blockTab = &NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId];
    /* Set the static id for Nvm_InternalBuffer. */
    Nvm_InternalBuffer[NVM_STATICID_SECOND_BIT] = (uint8)(NvM_QueueCrrntJob.CurBlockId & NVM_STATICID_MASK);
    Nvm_InternalBuffer[NVM_STATICID_FIRST_BIT] = (uint8)((NvM_QueueCrrntJob.CurBlockId >>
                                                 NVM_STATICID_SHIFT_BIT) & NVM_STATICID_MASK);
    /* Check if enable NvM_SyncMechanismUesd. */
    if( TRUE == NvM_SyncMechanismUesd )
    {
        for( tryCounter = NVM_INIT_0; tryCounter < NVM_REPEAT_MIRROR_OPERATIONS; tryCounter++ )
        {
            /* Copy data by callback. */
            /* Polyspace +1 RTE:COR [JUstified:Unset] "NSCA_Polyspace_NvM_CorrectnessCondition" */
            if( E_OK == blockTab->NvMWriteRamBlockToNvCallback(&Nvm_InternalBuffer[NVM_STATICID_LENGTH]) )
            {
                /* Validate the RAM after called explict synchronization. */
                blockMngmnt->NvRamState |= (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED);
                break;
            }
        }
        if( NVM_REPEAT_MIRROR_OPERATIONS == tryCounter )
        {
            /* Set result to unsuccessfully. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
            rtrnValu = FALSE;
        }
    }
    else if( blockMngmnt->RamAddr != NULL_PTR )
    {
        NvM_MemmoryCopy(blockMngmnt->RamAddr, &Nvm_InternalBuffer[NVM_STATICID_LENGTH],
                                       blockMngmnt->RemainLegth - NVM_STATICID_LENGTH);
    }
    else
    {
        /* Do nothing. */
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_ReadBlock
*
* Explanation: Function to pass the read data request to the lower level.
*
* param: None
*
* retval: TRUE: Request successful,take the next step.
*         FALSE: Error occurred,end request.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_ReadBlock(void)
{
    uint8 rtrnValu = NVM_TRANSITION_STATE1;
    uint8 memIf_result;
    uint16 locBlockId;
    uint16 locBlockNumber = NVM_INIT_0;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;      /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get managment information of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */
    NvM_ReadRomFlg = FALSE;

    /* Check if execute extended runtime preparation. */
    if( (TRUE == NvM_CfgidMismatch) && (TRUE == NvM_WriteCfgidFlg)
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
        && (FALSE == blockTab->ResistantToChangedSw) )
    {
        NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
        rtrnValu = NVM_TRANSITION_STATE3;
    }
    /* Block is configured as DATASET. */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    else if( NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType )
    {
        /* dataset point NV. */
        if( (blockMngmnt->DataIndex) < (blockTab->NvBlockNum) )
        {
            /* Confirm the read location according to the current dataindex. */
            locBlockNumber = blockTab->NvBlockBaseNumber + blockMngmnt->DataIndex;
        }
        else
        {
            NvM_ReadRomFlg = TRUE;
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
            rtrnValu = NVM_TRANSITION_STATE3;
        }
    }
    else
    {
        locBlockNumber = blockTab->NvBlockBaseNumber;   /* Get configured basenumber. */
    }
    /* Check if the explicit synchronization or permanent ram block is configerd. */
    if( (TRUE == NvM_SyncMechanismUesd) ||  (blockTab->RamAddr != NULL_PTR) )
    {
        blockMngmnt->NvRamState &= NVM_BLOCK_INVALID;
        blockMngmnt->NvRamState &= NVM_BLOCK_UNCHANGED;
    }

    /* Ram address is not null and dataset not point ROM. */
    if( NVM_TRANSITION_STATE3 != rtrnValu )
    {
        /* Call the read interface of MemIf to request read data. */
        memIf_result = MemIf_Read( blockTab->DeviceId, locBlockNumber, NVM_BLOCK_OFFSET_0,
                                    Nvm_InternalBuffer, blockTab->NvBlockLength);
        if( E_OK == memIf_result )  /* Results feedback from Lower level is OK? */
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;  /* Set result is pending. */
        }
        else
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
            rtrnValu = NVM_TRANSITION_STATE2;    /* Allow access to the next state machine. */
        }
    }

    /* Set current ram block address. */
    blockMngmnt->CurRamAddr = Nvm_InternalBuffer;
    /* Get the length of the data to be calculated. */
    blockMngmnt->RemainLegth =  blockTab->NvBlockLength
                                - Nvm_CrcCalc_Size_Table[blockTab->CrcType];
    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_WriteBlock
*
* Explanation: Function to pass the written data request to the lower level.
*
* param: None
*
* retval: TRUE: Request successful,take the next step.
*         FALSE: Error occurred,end request.
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_WriteBlock(void)
{
    uint8 memIf_result;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;      /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get managment information of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */
    NVM_RedundantNumber = NVM_REDUNDANT_PRIMARY;

    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    if( NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType ) /* Block is configured as DATASET. */
    {
        /* Confirm the write location according to the current dataindex. */
        NvM_QueueCrrntJob.BlockNumber = blockTab->NvBlockBaseNumber + blockMngmnt->DataIndex;
    }
    else if( NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType )
    {
        NvM_QueueCrrntJob.BlockNumber = blockTab->NvBlockBaseNumber + NVM_VALUE_ONE;    /* Get second NV block. */
        /* Second block currently processing, only used for Redundant. */
        NVM_RedundantNumber = NVM_REDUNDANT_SECOND;
    }
    else
    {
         NvM_QueueCrrntJob.BlockNumber = blockTab->NvBlockBaseNumber; /* Get configured basenumber. */
    }

    /* Validate the permanent RAM block and mark block as changed. */
    if( blockTab->RamAddr != NULL_PTR )
    {
        /* Validate the permanent RAM block and mark block as changed. */
        blockMngmnt->NvRamState |= (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED);
    }
    /* Call the read interface of MemIf to request write data. */
    memIf_result = MemIf_Write(blockTab->DeviceId ,NvM_QueueCrrntJob.BlockNumber, Nvm_InternalBuffer);

    if( E_OK == memIf_result )  /* Results feedback from Lower level is OK? */
    {
        NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;  /* Set result is pending. */
        if( NVM_MULTI == NvM_ModuleState )
        {
            NvM_MultiStateMachine = NVM_STATEMACHINE_BUSY;   /* To waiting result state. */
        }
        else
        {
            NvM_SingleStateMachine = NVM_STATEMACHINE_BUSY;   /* To waiting result state. */
        }
    }
    else
    {
        NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
        if( NVM_MULTI == NvM_ModuleState )              /* Allow access to the next state machine. */
        {
            NvM_MultiStateMachine = NVM_STATEMACHINE_RETRY;   /* Retry. */
        }
        else
        {
            NvM_SingleStateMachine = NVM_STATEMACHINE_RETRY;   /* Retry. */
        }
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_WriteReDundant
*
* Explanation: Function to Wait for lower level processing results.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_WriteReDundant(void)
{
    uint8 memIf_result;
    uint16 locBlockId;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;      /* Get blockID of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */
    /* Block is configured as REDUNDANT and PRIMARY block is completed. */
    if( (NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType)
        && (NVM_REDUNDANT_SECOND == NVM_RedundantNumber) )
    {
        /* First block currently processing, only used for Redundant. */
        NVM_RedundantNumber = NVM_REDUNDANT_PRIMARY;
        /* Get the second blok number. */
        NvM_QueueCrrntJob.BlockNumber = blockTab->NvBlockBaseNumber;
        /* Request to write second block. */
        memIf_result = MemIf_Write(blockTab->DeviceId ,NvM_QueueCrrntJob.BlockNumber, Nvm_InternalBuffer);

        if( E_OK == memIf_result )  /* Results feedback from Lower level is OK? */
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;  /* Set result is pending. */
            if( NVM_MULTI == NvM_ModuleState )
            {
                NvM_MultiStateMachine = NVM_STATEMACHINE_BUSY;   /* To waiting result state. */
            }
            else
            {
                NvM_SingleStateMachine = NVM_STATEMACHINE_BUSY;   /* To waiting result state. */
            }
        }
        else
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
            if( NVM_MULTI == NvM_ModuleState )
            {
                NvM_MultiStateMachine = NVM_STATEMACHINE_RETRY;   /* Retry. */
            }
            else
            {
                NvM_SingleStateMachine = NVM_STATEMACHINE_RETRY;   /* Retry. */
            }
        }
    }
    else
    {
        /* End the operation of the current block. */
        NvM_MainFunction_FinishSwitch();
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_WriteRetry
*
* Explanation: Function to pass the written data request to the lower level.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_WriteRetry(void)
{
    boolean writeRetry = FALSE;
    uint8 memIf_result;
    uint16 locBlockId;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */

    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    if( NvM_RetryCounter < blockTab->MaxNumOfWriteRetries )
    {
        NvM_RetryCounter++;     /* Increase retry times. */
        writeRetry = TRUE;
    }
    else
    {
        /* Block is configured as REDUNDANT. */
        if( NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType )
        {
            if( NVM_REDUNDANT_SECOND == NVM_RedundantNumber )  /* If the next write is the first block. */
            {
                NvM_RetryCounter = NVM_VALUE_ONE;      /* Clear the retry counter. */
                /* Get the first blok number. */
                NvM_QueueCrrntJob.BlockNumber = blockTab->NvBlockBaseNumber;
                NVM_RedundantNumber = NVM_REDUNDANT_PRIMARY;
                writeRetry = TRUE;
            }
        }
    }

    if( TRUE == writeRetry )    /* Can write again. */
    {
        /* Call the write interface of MemIf to request write data. */
        memIf_result = MemIf_Write(blockTab->DeviceId, NvM_QueueCrrntJob.BlockNumber, Nvm_InternalBuffer);

        if( E_OK == memIf_result )  /* Results feedback from Lower level is OK? */
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;      /* Set result is pending. */
            if( NVM_MULTI == NvM_ModuleState )                  /* Allow access to the next state machine. */
            {
                NvM_MultiStateMachine = NVM_STATEMACHINE_BUSY;  /* To waiting result state. */
            }
            else
            {
                NvM_SingleStateMachine = NVM_STATEMACHINE_BUSY; /* To waiting result state. */
            }
        }
        else
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;       /* Retry. */
        }
    }
    else
    {
        /* Reset reduant block as primary block. */
        NVM_RedundantNumber = NVM_REDUNDANT_PRIMARY;
        NvM_MainFunction_FinishSwitch();
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_EraseNvBlock
*
* Explanation: Function to pass the erase block request to the lower level.
*
* param: None
*
* retval: TRUE: Request successful,take the next step.
*         FALSE: Error occurred,end request.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_EraseNvBlock(void)
{
    uint8 nextStep = FALSE;
    uint8 memIf_result;
    uint16 locBlockId;
    uint16 locBlockNumber = NVM_INIT_0;
    const NvM_Block_Descriptor_Table_st *blockTab;
    Nvm_BlockManagment_st *blockMngmnt;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get managment information of current job. */

    /* Select the erase method according to the type of NVRAM. */
    if( blockTab->ManagementType == NVM_BLOCK_MANAGENMENT_DATASET )
    {
        if( blockMngmnt->DataIndex < blockTab->NvBlockNum )
        {
            locBlockNumber = blockTab->NvBlockBaseNumber + blockMngmnt->DataIndex;
        }
        else
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
        }
    }
    else
    {
        locBlockNumber = blockTab->NvBlockBaseNumber;
    }
    /* Call the erase interface of MemIf. */
    memIf_result = MemIf_EraseImmediateBlock(blockTab->DeviceId, locBlockNumber);
    if( E_OK == memIf_result )  /* Results feedback from Lower level is OK? */
    {
        NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;      /* Set result is pending. */
        nextStep = TRUE;    /* Allow access to the next state machine. */
    }
    else
    {
        NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
    }

    if( NVM_BSWM_INFORMATION_ON == NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].BswMInform )
    {
        /* Notify bswm of blockid and status currently processed. */
        BswM_NvM_CurrentBlockMode(NvM_QueueCrrntJob.CurBlockId, NVM_REQ_PENDING);
    }

    return nextStep;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_EraseReDundant
*
* Explanation: Function to erase the second NV block of redundant NVRAM.
*
* param: None
*
* retval: NVM_TRANSITION_STATE1: Next step erase the second NV block.
*         NVM_TRANSITION_STATE2: Erase finisged.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_EraseReDundant(void)
{
    uint8 rtrnValu = NVM_TRANSITION_STATE2;
    uint8 memIf_result;
    uint16 locBlockId;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;      /* Get blockID of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */
    /* Block is configured as REDUNDANT and PRIMARY block is completed. */
    if( (NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType)
        && (NVM_REDUNDANT_PRIMARY == NVM_RedundantNumber) )
    {
        /* Get the second blok number. */
        NvM_QueueCrrntJob.BlockNumber = blockTab->NvBlockBaseNumber + NVM_VALUE_ONE;
        /* Request to erase second block. */
        memIf_result = MemIf_EraseImmediateBlock( blockTab->DeviceId, NvM_QueueCrrntJob.BlockNumber );
        if( E_OK == memIf_result )  /* Results feedback from Lower level is OK? */
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;  /* Set result is pending. */
            rtrnValu = NVM_TRANSITION_STATE1;   /* To waiting result state. */
        }
        else
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
        }
        /* Second block currently processing, only used for Redundant. */
        NVM_RedundantNumber = NVM_REDUNDANT_SECOND;
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_InvalidateNvBlock
*
* Explanation: Function to pass the Invalidate block request to the lower level.
*
* param: None
*
* retval: TRUE: Request successful,take the next step.
*         FALSE: Error occurred,end request.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_InvalidateNvBlock(void)
{
    uint8 nextStep = FALSE;
    uint8 memIf_result;
    uint16 locBlockId;
    uint16 locBlockNumber;
    const NvM_Block_Descriptor_Table_st *blockTab;
    Nvm_BlockManagment_st *blockMngmnt;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get managment information of current job. */
    if( blockTab->ManagementType == NVM_BLOCK_MANAGENMENT_DATASET )
    {
        locBlockNumber = blockTab->NvBlockBaseNumber + blockMngmnt->DataIndex;
    }
    else
    {
        locBlockNumber = blockTab->NvBlockBaseNumber;
    }
    /* Call the invalidate interface of MemIf. */
    memIf_result = MemIf_InvalidateBlock(blockTab->DeviceId, locBlockNumber);

    if( E_OK == memIf_result )  /* Results feedback from Lower level is OK? */
    {
        NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;  /* Set result is pending. */
        nextStep = TRUE;    /* Allow access to the next state machine. */
    }
    else
    {
        NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
    }
    /* Notifies the state of the BswM block. */
    if( NVM_BSWM_INFORMATION_ON == NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].BswMInform )
    {
        /* Notify bswm of blockid and status currently processed. */
        BswM_NvM_CurrentBlockMode(NvM_QueueCrrntJob.CurBlockId, NVM_REQ_PENDING);
    }

    return nextStep;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_InvalidateReDundant
*
* Explanation: Function to invalidate the second NV block of redundant NVRAM.
*
* param: None
*
* retval: NVM_TRANSITION_STATE1: Next step invalidate the second NV block.
*         NVM_TRANSITION_STATE2: Invalidate finisged.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_InvalidateReDundant(void)
{
    uint8 rtrnValu = NVM_TRANSITION_STATE2;
    uint8 memIf_result;
    uint16 locBlockId;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;      /* Get blockID of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */
    /* Block is configured as REDUNDANT and PRIMARY block is completed. */
    if( (NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType)
        && (NVM_REDUNDANT_PRIMARY == NVM_RedundantNumber) )
    {
        /* Get the second blok number. */
        NvM_QueueCrrntJob.BlockNumber = blockTab->NvBlockBaseNumber + NVM_VALUE_ONE;
        /* Request to write second block. */
        memIf_result = MemIf_InvalidateBlock( blockTab->DeviceId, NvM_QueueCrrntJob.BlockNumber );
        if( E_OK == memIf_result )  /* Results feedback from Lower level is OK? */
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;  /* Set result is pending. */
            rtrnValu = NVM_TRANSITION_STATE1;   /* To waiting result state. */
        }
        else
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Set result is NotOK,End operation. */
        }
        /* Second block currently processing, only used for Redundant. */
        NVM_RedundantNumber = NVM_REDUNDANT_SECOND;
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_RestoreRequest
*
* Explanation: Function to requet restore data.
*
* param: None
*
* retval: TRUE: Request successful,take the next step.
*         FALSE: Error occurred,end request.
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_RestoreRequest(void)
{
    uint16 tryCounter;
    uint16 locBlockId;
    uint8 *romData;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
    /* Set job result to fail. */
    NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;

    /* Check if a permanent ramblock or explicit synchronization is configured. */
    if( (blockTab->RamAddr != NULL_PTR) || (TRUE == NvM_SyncMechanismUesd) )
    {
        /* Set ram state to invalid and unchanged. */
        blockMngmnt->NvRamState &= NVM_BLOCK_INVALID;
        blockMngmnt->NvRamState &= NVM_BLOCK_UNCHANGED;
    }
    /* Check if rom block is configured. */
    if( (blockTab->RomAddr != NULL_PTR) && (blockTab->RomBlockNum != NVM_INIT_0) )
    {
        /* Get rom block address. */
        romData = NvM_MainFun_GetRomBlockAddr();
        if( romData != NULL_PTR )
        {
            /* Use explicit synchronization callback to copy rom data to ram. */
            if( TRUE == NvM_SyncMechanismUesd )   /* The size of the mirrored image is large enough. */
            {
                for( tryCounter = NVM_INIT_0; tryCounter < NVM_REPEAT_MIRROR_OPERATIONS;
                        tryCounter++ )
                {
                    /* Copy data to upper. */
                    /* Polyspace +1 RTE:COR [JUstified:Unset] "NSCA_Polyspace_NvM_CorrectnessCondition" */
                    if( E_OK == blockTab->NvMReadRamBlockFromNvCallback(romData) )
                    {
                        /* Restore successfully. */
                        NvM_QueueCrrntJob.JobResult = NVM_REQ_RESTORED_FROM_ROM;
                        break;
                    }
                }
            }
            /* Check if the RAM address is valid. */
            else if( blockMngmnt->RamAddr != NULL_PTR )
            {
                NvM_MemmoryCopy(romData, blockMngmnt->RamAddr,
                                blockMngmnt->RemainLegth - NVM_STATICID_LENGTH);
                /* Restore successfully. */
                NvM_QueueCrrntJob.JobResult = NVM_REQ_RESTORED_FROM_ROM;
            }
            else
            {
                /* Do nothing. */
            }
        }
    }
    /* Check if initialization callback is configured. */
    else if( blockTab->NvMInitBlockCallback != NULL_PTR )
    {
        /* The block initializes callbacks. */
        if( E_OK == blockTab->NvMInitBlockCallback() )
        {
            /* Restore successfully. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_RESTORED_FROM_ROM;
        }
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_RestoreNvBlock
*
* Explanation: Function to restore data by blockId.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_RestoreNvBlock(void)
{
    uint16 tryCounter;
    uint16 locBlockId;
    uint8 *romData;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:COR [JUstified:Unset] "NSCA_Polyspace_Dem_CorrectnessCondition" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_NvM_IllegallyDereferencedPointer" */
    blockMngmnt->RemainLegth = blockTab->NvBlockLength - Nvm_CrcCalc_Size_Table[blockTab->CrcType]
                             - NVM_STATICID_LENGTH;
    /* Check if current operation is implicit recovery and the block is dataset. */
    if( (FALSE == NvM_ReadRomFlg) && (NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType) )
    {
        NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
    }
    else
    {
        /* Check if rom block is configured. */
        if( (blockTab->RomAddr != NULL_PTR) && (blockTab->RomBlockNum != NVM_INIT_0) )
        {
            /* Get rom block address. */
            romData = NvM_MainFun_GetRomBlockAddr();
            if( romData != NULL_PTR )
            {
                /* Use explicit synchronization callback to copy rom data to ram. */
                if( TRUE == NvM_SyncMechanismUesd )   /* The size of the mirrored image is large enough. */
                {
                    for( tryCounter = NVM_INIT_0; tryCounter < NVM_REPEAT_MIRROR_OPERATIONS;
                            tryCounter++ )
                    {
                        /* Copy data to upper. */
                        /* Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_NvM_IllegallyDereferencedPointer" Polyspace +1 RTE:COR [JUstified:Unset] "NSCA_Polyspace_NvM_CorrectnessCondition" */
                        if( E_OK == blockTab->NvMReadRamBlockFromNvCallback(romData) )
                        {
                            /* Determine whether the operation is to read the ROM or restore. */
                            if( TRUE == NvM_ReadRomFlg )
                            {
                                /* Set job result for read rom successfully. */
                                NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
                            }
                            else
                            {
                                /* Set job result for restore successfully. */
                                NvM_QueueCrrntJob.JobResult = NVM_REQ_RESTORED_FROM_ROM;
                            }
                            break;
                        }
                    }
                }
                else
                {
                    NvM_MainFun_CopyRomData(romData);
                }
            }
        }
        /* Check if initialization callback is configured. */
        else if( blockTab->NvMInitBlockCallback != NULL_PTR )
        {
            /* The block initializes callbacks. */
            if( E_OK == blockTab->NvMInitBlockCallback() )
            {
                /* Restore successfully. */
                NvM_QueueCrrntJob.JobResult = NVM_REQ_RESTORED_FROM_ROM;
            }
        }
        else
        {
            /* Do nothing. */
        }
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_Busy
*
* Explanation: Function to Wait for lower level processing results.
*
* param: None
*
* retval: NVM_TRANSITION_STATE1: Depending on the request.
*         NVM_TRANSITION_STATE2: To waiting result state.
*         NVM_TRANSITION_STATE3: Depending on the request.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_Busy(void)
{
    uint8 rtrnValu = NVM_TRANSITION_STATE3;

#if( NVM_POLLING_MODE == STD_ON )   /* Polling mode is configured. */
    MemIf_JobResultType memIf_result;
    uint16 locBlockId;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    memIf_result = MemIf_GetJobResult(blockTab->DeviceId); /* Read processing results from the lower level. */

    switch( memIf_result )
    {
        case MEMIF_JOB_OK:  /* The last asynchronous request has been finished successfully. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
            rtrnValu = NVM_TRANSITION_STATE2;
            break;
        /* The last asynchronous read/write/control request has been finished unsuccessfully. */
        case MEMIF_JOB_FAILED:
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
            break;

        case MEMIF_JOB_PENDING: /* An asynchronous request is currently being processed. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;
            rtrnValu = NVM_TRANSITION_STATE1;
            break;

        case MEMIF_JOB_CANCELED:    /* The multi block request NvM_WriteAll was canceled. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_CANCELED;
            break;

        /* The result of the last asynchronous request NvM_ReadBlock or NvM_ReadAll is a data integrity failure. */
        case MEMIF_BLOCK_INCONSISTENT:
            NvM_QueueCrrntJob.JobResult = NVM_REQ_INTEGRITY_FAILED;
            break;

        case MEMIF_BLOCK_INVALID:   /* The referenced NV block is invalidated. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NV_INVALIDATED;
            break;
        
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        default:    /* The last asynchronous read/write/control request has been finished unsuccessfully. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
            break;
    }
#else
    switch( NvM_QueueCrrntJob.JobResult )
    {
        case MEMIF_JOB_OK:  /* The last asynchronous request has been finished successfully. */
            rtrnValu = NVM_TRANSITION_STATE2;
            break;

        case MEMIF_JOB_PENDING: /* An asynchronous request is currently being processed. */
            rtrnValu = NVM_TRANSITION_STATE1;
            break;

        default:    /* Error occur. */
            rtrnValu = NVM_TRANSITION_STATE3;
            break;
    }
#endif /* NVM_POLLING_MODE == STD_ON */

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_ProtectCrc
*
* Explanation: Function to Calculate CRC to protect written data.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_ProtectCrc(void)
{
    uint8 crcType;
    uint8 i;
    uint16 locBlockId;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint16 length;
    uint8 *datAddr;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    datAddr = blockMngmnt->CurRamAddr;  /* Get the data starting address for this calculation. */
    crcType = blockTab->CrcType;    /* Get the CRC type definition of the block. */
    /* Get the length of the data to be calculated. */
    length = blockMngmnt->RemainLegth;

    if( TRUE == blockTab->RamBlockCrc )
    {
        /* Is the length of the data greater than the maximum allowable length? */
        if( length > NVM_CRC_NUM_OF_BYTES )
        {
            length = NVM_CRC_NUM_OF_BYTES;  /* The calculated length is 64 bytes. */
        }
        /* Calculate remaining data length used for the next calculation. */
        blockMngmnt->RemainLegth -= length;
        /* Check if the address is NULL. */
        if( datAddr != NULL_PTR )
        {
            /* Calculate the next calculation data start address */
            blockMngmnt->CurRamAddr = &datAddr[length];
        }
        /* Check the crc type. */
        if( (crcType > NVM_INIT_0) && (crcType < NVM_CRCCALC_API_NUMBER) &&
            (datAddr != NULL_PTR) )
        {
            NvM_QueueCrrntJob.CrcValu = NvM_CalculateCrc(datAddr,
                                                         length,
                                                         NvM_QueueCrrntJob.CrcValu,
                                                         FALSE);
        }
        /* CRC calculation is completed. */
        if( NVM_INIT_0 == blockMngmnt->RemainLegth )
        {
            if( (NVM_BLOCK_CRC_COMP_ON == blockTab->CrcCompMechanism)
                && (NvM_QueueCrrntJob.CrcValu == NvM_gstaBlockAdmini[locBlockId].CrcValue)
                && (FALSE == blockMngmnt->NvmLossRedun) )
            {
                /* The data is up to date, and no need to write again. */
                NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
                NvM_MainFunction_FinishSwitch();
            }
            else
            {
                /* Update crc value to internal buffer. */
                for( i = NVM_INIT_0; i < Nvm_CrcCalc_Size_Table[crcType]; i++ )
                {
                    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
                    Nvm_InternalBuffer[blockTab->NvBlockLength - Nvm_CrcCalc_Size_Table[crcType] + i]
                        = (uint8)(NvM_QueueCrrntJob.CrcValu >> (i * NVM_CRC_SHIFT_BIT));
                }
                /* The CRC calculation is complete and entered into the next state machine. */
                /* Sending write data request to the lower level. */
                NvM_MainFun_WriteBlock();
            }
        }
    }
    else/* No need to CRC calculation. */
    {
        /* Sending write data request to the lower level. */
        NvM_MainFun_WriteBlock();
    }
}

/*
********************************************************************************
* Function Name: NvM_CalculateCrc
*
* Explanation: Function to calculate the crc value.
*
* param: DataAddr: Data address.
*        Length: Data Length.
*        CrcValue: Crc init value.
*        IsFirstCall: Is first call.
*
* retval: Crc value.
********************************************************************************
*/
static FUNC(uint32, NVM_CODE) NvM_CalculateCrc
(
    P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) DataAddr,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint16 Length,
    uint32 CrcValue,
    boolean IsFirstCall
)
{
    uint8 crc8Value;
    uint16 crc16Value;
    uint32 retVal;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Get block definition of current job. */
    blockTab = &NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId];
    /* Calculate crc. */
    if( NVM_BLOCK_CRC_8 == blockTab->CrcType )
    {
        /* Get the crc mask value. */
        crc8Value = (uint8)(CrcValue & NVM_CRC_MASK_VALUE);
        /* Calculate the crc8. */
        retVal = (uint32)Crc_CalculateCRC8(DataAddr, Length, crc8Value, IsFirstCall);
    }
    else if( NVM_BLOCK_CRC_16 == blockTab->CrcType )
    {
        /* Get the crc mask value. */
        crc16Value = (uint16)(CrcValue & NVM_CRC16_MASK_VALUE);
        /* Calculate the crc16. */
        retVal = (uint32)Crc_CalculateCRC16(DataAddr, Length, crc16Value, IsFirstCall);
    }
    else
    {
        /* Calculate the crc32. */
        retVal = Crc_CalculateCRC32(DataAddr, Length, CrcValue, IsFirstCall);
    }

    return retVal;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_CheckCrc
*
* Explanation: Function to Calculate CRC to check readout data.
*
* param: None
*
* retval: NVM_TRANSITION_STATE1: CRC calculation.
*         NVM_TRANSITION_STATE2: Retry.
*         NVM_TRANSITION_STATE3: End.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_CheckCrc(void)
{
    uint8 rtrnValu = NVM_TRANSITION_STATE1;
    uint8 chkresult = E_OK;
    uint8 crcType;
    uint16 locBlockId;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint16 length;
    uint16 staticId;
    uint8 *datAddr;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
    /* Get the length of the data to be calculated. */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    length = blockMngmnt->RemainLegth;
    /* Get the data starting address for this calculation. */
    datAddr = blockMngmnt->CurRamAddr;
    crcType = blockTab->CrcType;    /* Get the CRC type definition of the block. */

    /* Comparison the static ID. */
    if( NVM_STATIC_BLOCK_ID_CHECK_ON == blockTab->BlockIDCheck )
    {
        staticId = ((uint16)((uint16)Nvm_InternalBuffer[NVM_STATICID_FIRST_BIT] << NVM_STATICID_SHIFT_BIT) |
                (uint16)(Nvm_InternalBuffer[NVM_STATICID_SECOND_BIT]));
        if( locBlockId != staticId )
        {
            chkresult = E_NOT_OK;
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
            rtrnValu = NVM_TRANSITION_STATE2;
        }
    }
    /* If the result is TURE. */
    if( E_OK == chkresult )
    {
        if( TRUE == blockTab->RamBlockCrc )
        {
            /* Is the length of the data greater than the maximum allowable length? */
            if( length > NVM_CRC_NUM_OF_BYTES )
            {
                length = NVM_CRC_NUM_OF_BYTES;      /* The calculated length is 64 bytes. */
            }
            /* Calculate remaining data length used for the next calculation. */
            blockMngmnt->RemainLegth -= length;
            /* Check if the address is NULL. */
            if( datAddr != NULL_PTR )
            {
                /* Calculate the remaining length of the next use. */
                blockMngmnt->CurRamAddr = &datAddr[length];
            }
            /* check CRC type. */
            if( (crcType > NVM_INIT_0) && (crcType < NVM_CRCCALC_API_NUMBER) )
            {
                /* Calculate CRC for data that read from NV. */
                NvM_QueueCrrntJob.CrcValu = NvM_CalculateCrc(datAddr,
                                                             length,
                                                             NvM_QueueCrrntJob.CrcValu,
                                                             FALSE);
            }
            if( NVM_INIT_0 == blockMngmnt->RemainLegth )    /* CRC calculation is completed */
            {
                rtrnValu = NvM_MainFun_CheckCrcFinish();
            }
        }
        else
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_OK; /* finished successfully. */
            /* CRC is the same. read process Successful. */
            rtrnValu = NVM_TRANSITION_STATE3;
        }
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_CheckCrcFinish
*
* Explanation: Function to read another block to recover data.
*
* param: None
*
* retval: NVM_TRANSITION_STATE1: NvMResistantToChangedSw.
*         NVM_TRANSITION_STATE2: wait result.
*         NVM_TRANSITION_STATE3: End.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_CheckCrcFinish(void)
{
    uint8 rtrnValu;
    uint8 crcType;
    uint8 i;
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint32 crcValue = NVM_INIT_0;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */

    /* Get the data starting address for this calculation. */
    crcType = blockTab->CrcType;    /* Get the CRC type definition of the block. */

    /* Get the crc value in flash. */
    for( i = NVM_INIT_0; i < Nvm_CrcCalc_Size_Table[crcType]; i++ )
    {
        crcValue = crcValue
         /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
         | ((uint32)((uint32)Nvm_InternalBuffer[blockTab->NvBlockLength - Nvm_CrcCalc_Size_Table[crcType] + i]
            << (i * NVM_CRC_SHIFT_BIT)) & ((uint32)NVM_CRC_MASK_VALUE << (i * NVM_CRC_SHIFT_BIT)));
    }
    blockMngmnt->RemainLegth = blockTab->NvBlockLength - Nvm_CrcCalc_Size_Table[crcType] - NVM_STATICID_LENGTH;
    /* Comparison between calculated and received CRC. */
    if( crcValue == NvM_QueueCrrntJob.CrcValu )
    {
        /* Set new CRC value. */
        NvM_gstaBlockAdmini[locBlockId].CrcValue = NvM_QueueCrrntJob.CrcValu;
        NvM_QueueCrrntJob.JobResult = NVM_REQ_OK; /* finished successfully. */
        /* CRC is the same. read process Successful. */
        rtrnValu = NVM_TRANSITION_STATE3;
    }
    else
    {
        NvM_QueueCrrntJob.JobResult = NVM_REQ_INTEGRITY_FAILED;
        rtrnValu = NVM_TRANSITION_STATE2;
    }
    /* Reset CRC calculation results. */
    NvM_QueueCrrntJob.CrcValu = NVM_CRC_START_VALUE;
    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_MemmoryCopy
*
* Explanation: Function to copy data from souce address to destination address in
*              1 byte format.
*
* param: SrcAddr: Souce addrsss.
*        DesAddr: Destination address.
*        length: Data length.
*
* retval: void
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MemmoryCopy
(
    P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) SrcAddr,
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DesAddr,
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint16 length
)
{
    uint16 loopNum;

    /* Check if the input pointer is NULL */
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( (SrcAddr != NULL_PTR) && (DesAddr != NULL_PTR) )
    {
        /* Copy destination address to source address */
        for( loopNum = NVM_INIT_0; loopNum < length; loopNum++ )
        {
            /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
            DesAddr[loopNum] = SrcAddr[loopNum];
        }
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_ReadRetry
*
* Explanation: Function to read another block to recover data.
*
* param: None
*
* retval: NVM_TRANSITION_STATE1: NvMResistantToChangedSw.
*         NVM_TRANSITION_STATE2: wait result.
*         NVM_TRANSITION_STATE3: End.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_MainFun_ReadRetry(void)
{
    uint8 rtrnValu = NVM_TRANSITION_STATE3;
    uint8 memIf_result;
    uint8 readRetry = NVM_INIT_0;
    uint16 locBlockId;
    uint16 locBlockNumber = NVM_INIT_0;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    /* Get managment information of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];
    /* Get block definition of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];

    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    if( NvM_RetryCounter < blockTab->MaxNumOfReadRetries )  /* Read retry. */
    {
        /* Block is configured as DATASET. */
        if( NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType )
        {
            /* Confirm the write location according to the current dataindex. */
            locBlockNumber = blockTab->NvBlockBaseNumber + blockMngmnt->DataIndex;
        }
        else
        {
            /* Get configured basenumber. */
            locBlockNumber = blockTab->NvBlockBaseNumber + NVM_RedundantNumber;
        }
        NvM_RetryCounter++; /* Increase retry times. */
        readRetry = TRUE;
    }
    else
    {
        /* Block is configured as REDUNDANT and the block is primary block. */
        if( (NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType)
                && (NVM_REDUNDANT_PRIMARY == NVM_RedundantNumber) )
        {
            blockMngmnt->NvmLossRedun = TRUE;
            NvM_RetryCounter = NVM_VALUE_ONE;
            NVM_RedundantNumber = NVM_REDUNDANT_SECOND;
            /* Get the second blok number. */
            locBlockNumber = blockTab->NvBlockBaseNumber + NVM_RedundantNumber;
            readRetry = TRUE;
        }
    }

    if( TRUE == readRetry )     /* Can read again. */
    {
        /* Request to read again. */
        memIf_result = MemIf_Read(blockTab->DeviceId, locBlockNumber, NVM_BLOCK_OFFSET_0,
                                   Nvm_InternalBuffer, blockTab->NvBlockLength);
        if( E_OK == memIf_result )  /* Results feedback from Lower level is OK? */
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;  /* Set result is pending. */
            rtrnValu = NVM_TRANSITION_STATE2;               /* Allow access to wait result. */
        }
        else
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;   /* Retry. */
        }
    }
    else
    {
        /* Reset reduant block as primary block. */
        NVM_RedundantNumber = NVM_REDUNDANT_PRIMARY;
        rtrnValu = NVM_TRANSITION_STATE1;               /* Allow access to wait result. */
    }

    /* Set current ram block address. */
    blockMngmnt->CurRamAddr = Nvm_InternalBuffer;
    /* Get the length of the data to be calculated. */
    blockMngmnt->RemainLegth =  blockTab->NvBlockLength
                                - Nvm_CrcCalc_Size_Table[blockTab->CrcType];
    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_QueueJob_ResetInfo
*
* Explanation: Function to finish queue job and reset request.
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_QueueJob_ResetInfo(void)
{
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
    /* get ram block status from job result. */
    blockMngmnt->NvRamErrStatus = NvM_QueueCrrntJob.JobResult;
    blockMngmnt->RamAddr = NULL_PTR;    /* Reset ram start address. */
    blockMngmnt->CurRamAddr = NULL_PTR; /* Reset ram current address. */
    blockMngmnt->RemainLegth = blockTab->NvBlockLength;     /* Reset Residual length. */

    if( NVM_REQ_OK == NvM_QueueCrrntJob.JobResult )
    {
        /* Ivalidate the RAM block for Erase/Invalidate function successful. */
        if( (NVM_ERASE_NV_BLOCK == blockMngmnt->CtrlType) ||
            (NVM_INVALIDATE_NV_BLOCK == blockMngmnt->CtrlType) )
        {
            blockMngmnt->NvRamState &= NVM_BLOCK_INVALID;
            blockMngmnt->NvRamState &= NVM_BLOCK_UNCHANGED;
        }
        else
        {
            /* Judge if the operation is read rom for DATASET NVRAM. */
            if( TRUE == NvM_ReadRomFlg )
            {
                /* Validate the RAM block and mark block as changed. */
                blockMngmnt->NvRamState |= (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED);
            }
            else
            {
                /* Validate the RAM block and mark block as unchanged. */
                blockMngmnt->NvRamState |= NVM_BLOCK_VALID;
                blockMngmnt->NvRamState &= NVM_BLOCK_UNCHANGED;
            }
            /* Set wrtie protect for block that is not detected by underlying SW as being invalidated. */
            if( TRUE == blockTab->WriteBlockOnce )
            {
                blockMngmnt->NvRamState |= NVM_BLOCK_PRTCT_ON;
            }
        }
    }
    else if( NVM_REQ_RESTORED_FROM_ROM == NvM_QueueCrrntJob.JobResult )
    {
        /* Judge if the current RAM is a permanent ram. */
        if( blockTab->RamAddr != NULL_PTR )
        {
            /* Validate the RAM block and mark block as changed. */
            blockMngmnt->NvRamState |= (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED);
        }
    }
    else if( (NVM_REQ_NOT_OK == NvM_QueueCrrntJob.JobResult)
                          || (NVM_REQ_INTEGRITY_FAILED == NvM_QueueCrrntJob.JobResult)
                          || (NVM_REQ_NV_INVALIDATED == NvM_QueueCrrntJob.JobResult) )
    {
        /* Invalidate the block read operation faild. */
        blockMngmnt->NvRamState &= (NVM_BLOCK_INVALID & NVM_BLOCK_UNCHANGED);
    }
    else
    {
        /* Do noting. */
    }
    /* Set up the ID that will be processed next. */
    NvM_QueueCrrntJob.CrcValu = NVM_CRC_START_VALUE; /* Reset CRC calculation results. */
    NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;   /* reset current block id status. */
    NvM_QueueCrrntJob.CurBlockId = NVM_QUEUE_CURRENTBLOCKID;    /* Reset current block id. */
    NvM_RetryCounter = NVM_INIT_0;      /* Reset counter of the number of retry. */
    NVM_SuccessCounter = NVM_INIT_0;    /* Reset counter of the number of job successful. */
    NvM_SyncMechanismUesd = FALSE;      /* Reset NvM module's RAM mirror. */
    /* Reset reduant block as primary block. */
    NVM_RedundantNumber = NVM_REDUNDANT_PRIMARY;
    NvM_ReadRomFlg = FALSE;

    /* Notice job result. */
    NVM_SingleBlock_CallBack(blockMngmnt->BlockId, blockMngmnt->CtrlType, blockMngmnt->NvRamErrStatus);
    /* Notifies the state of the BswM block. */
    if( NVM_BSWM_INFORMATION_ON == NvM_Block_Descriptor_Table[blockMngmnt->BlockId].BswMInform )
    {
        /* Notify bswm of blockid and status currently processed. */
        BswM_NvM_CurrentBlockMode(blockMngmnt->BlockId, blockMngmnt->NvRamErrStatus);
    }
    blockMngmnt->CtrlType= NVM_NO_REQUEST;  /* Clear request for block. */
}

/*
********************************************************************************
* Function Name: NvM_MainFunction_ReadFinish
*
* Explanation: Function to finish read job and reset request.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_ReadFinish(void)
{
    /* Check if the data in the mirror can be copied to ram. */
    if( NVM_REQ_OK == NvM_QueueCrrntJob.JobResult )
    {
        /* Copy data from RAM Mirror to RAM. */
        NvM_MainFun_CopyDataToRam();
    }
    NvM_QueueJob_ResetInfo();
}

/*
********************************************************************************
* Function Name: NvM_MainFunction_WriteFinish
*
* Explanation: Function to finish queue job and reset request.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_WriteFinish(void)
{
    uint16 locBlockId;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];    /* Get block management of current job. */

    /* Check if write operation for redundant block has succeed once. */
    if( NvM_QueueCrrntJob.JobResult != NVM_REQ_OK )
    {
        /* At least one block request is successful, Only for REDUNDANT. */
        if( (NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType)
                && (NVM_SuccessCounter >= NVM_ATLEAST_ONE_SUCCESS) )
        {
            NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
        }
    }
    /* If it is an immediate write operation. */
    if( NVM_IMMEDIATE_WRITE_TURE == Nvm_ImmediateWrite )
    {
        /* Clear the flag. */
        Nvm_ImmediateWrite = NVM_IMMEDIATE_WRITE_FALSE;
        /* Check if multi-block requests are interrupted. */
        if( Nvm_MultiReqTemp > NVM_INIT_0 )
        {
            /* Recovery the multiblock request. */
            NvM_QueueCrrntJob.MultiBlockReq = Nvm_MultiReqTemp;
            /* Set module state to multi-block request. */
            NvM_ModuleState = NVM_MULTI;
        }
        /* Clear the flag. */
        Nvm_MultiReqTemp = NVM_INIT_0;
    }
    /* Update the crc value. */
    if( NVM_REQ_OK == NvM_QueueCrrntJob.JobResult )
    {
        /* Set new CRC value. */
        NvM_gstaBlockAdmini[locBlockId].CrcValue = NvM_QueueCrrntJob.CrcValu;
        /* Judge if the 2 NV blocks are all be writed successfully. */
        if( (NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType)
                && (NVM_SuccessCounter > NVM_ATLEAST_ONE_SUCCESS) )
        {
            /* Clear the redundant loss. */
            NvM_gstaBlockVar[locBlockId].NvmLossRedun = FALSE;
        }
    }
    else
    {
        /* Set CRC value to default value. */
        NvM_gstaBlockAdmini[locBlockId].CrcValue = NVM_CRC_INIT_VALUE;
    }

    NvM_QueueJob_ResetInfo();   /* Finish queue job and reset request. */
    NvM_SingleStateMachine = NVM_STATEMACHINE_IDLE;
}

/*
********************************************************************************
* Function Name: NvM_MainFunction_Finish
*
* Explanation: Function to finish queue job and reset request.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_Finish(void)
{
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get managment information of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */
    if( (NVM_ERASE_NV_BLOCK == blockMngmnt->CtrlType) || (NVM_INVALIDATE_NV_BLOCK == blockMngmnt->CtrlType) )
   {
        if( NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType )
        {
            if( NVM_SuccessCounter > NVM_ATLEAST_ONE_SUCCESS )
            {
                NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
            }
            else
            {
                NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
            }
        }
        if( NVM_REQ_OK == NvM_QueueCrrntJob.JobResult )
        {
            /* Set CRC value to default value. */
            NvM_gstaBlockAdmini[locBlockId].CrcValue = NVM_CRC_INIT_VALUE;
        }
   }

    NvM_QueueJob_ResetInfo();   /* Finish queue job and reset request. */
}

/*
********************************************************************************
* Function Name: NvM_MainFunction_WriteAllFinish
*
* Explanation: Function to finish writeall job and reset request.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_WriteAllFinish(void)
{
    uint8 finalResult;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */

    if( NVM_REQ_OK == NvM_QueueCrrntJob.JobResult )
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
        if( NVM_SELECT_BLOCK_4_WRITEALL_ON == NvM_Block_Descriptor_Table[locBlockId].Select4WriteAll )
        {
            /* Validate the RAM block and mark block as unchanged. */
            blockMngmnt->NvRamState |= NVM_BLOCK_VALID;
            blockMngmnt->NvRamState &= NVM_BLOCK_UNCHANGED;
            /* Set new CRC value. */
            NvM_gstaBlockAdmini[locBlockId].CrcValue = NvM_QueueCrrntJob.CrcValu;
        }
    }
    else
    {
        /* At least one block request is successful, Only for REDUNDANT. */
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
        if( (NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType)
                && (NVM_SuccessCounter >= NVM_ATLEAST_ONE_SUCCESS) )
        {
            /* Set new CRC value. */
            NvM_gstaBlockAdmini[locBlockId].CrcValue = NvM_QueueCrrntJob.CrcValu;
            NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
            /* Validate the RAM block and mark block as unchanged. */
            blockMngmnt->NvRamState |= NVM_BLOCK_VALID;
            blockMngmnt->NvRamState &= NVM_BLOCK_UNCHANGED;
        }
        else
        {
            if(NvM_QueueCrrntJob.JobResult != NVM_REQ_BLOCK_SKIPPED )
            {
                /* Set CRC value to default value. */
                NvM_gstaBlockAdmini[locBlockId].CrcValue = NVM_CRC_INIT_VALUE;
                /* Record the number of failed blocks. */
                NvM_FailedCounter++;
                blockMngmnt->NvRamState &= (NVM_BLOCK_INVALID & NVM_BLOCK_UNCHANGED);
            }
        }
    }
    /* Judge if the 2 NV blocks are all be writed successfully. */
    if( (NVM_REQ_OK == NvM_QueueCrrntJob.JobResult) &&
        (NVM_BLOCK_MANAGENMENT_REDUNDANT == blockTab->ManagementType) &&
        (NVM_SuccessCounter > NVM_ATLEAST_ONE_SUCCESS) )
    {
        /* Clear the redundant loss. */
        blockMngmnt->NvmLossRedun = FALSE;
    }
    /* Check if single block write is successful and write block once is enable. */
    if( (TRUE == blockTab->WriteBlockOnce) && (NVM_REQ_OK == NvM_QueueCrrntJob.JobResult) )
    {
        blockMngmnt->NvRamState |= NVM_BLOCK_PRTCT_ON;
    }
    /* Notice the single block job result. */
    NVM_SingleBlock_CallBack(locBlockId, NVM_WRITE_BLOCK, NvM_QueueCrrntJob.JobResult);
    /* Multi block operation finish? */
    if( NVM_INIT_0 == NvM_QueueCrrntJob.RemainNum )
    {

        /* Disable fast mode. */
#if( NVM_DRV_MODE_SWITCH == STD_ON )
        MemIf_SetMode(MEMIF_MODE_SLOW);
#endif
        /* Reset multi block operation start identification. */
        NvM_Multi_FirstFlg = TRUE;
        /* Reset current blockid to null. */
        NvM_QueueCrrntJob.CurBlockId = NVM_QUEUE_CURRENTBLOCKID;
        /* Reset Crc start avlue. */
        NvM_QueueCrrntJob.CrcValu = NVM_CRC_START_VALUE;
        /* Clear writeall request. */
        NvM_QueueCrrntJob.MultiBlockReq &= NVM_BLOCK_WRITEALL_CL;

        if( NVM_INIT_0 == NvM_FailedCounter )   /* No falied. */
        {
            finalResult = NVM_REQ_OK;
        }
        else
        {
            finalResult = NVM_REQ_NOT_OK;
        }
        /* Set multiple flag */
        NvM_gstaBlockVar[NVM_INIT_0].NvRamErrStatus = finalResult;

#if( NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON )
        /* Notice bswm of mutli service id and status currently processed. */
        BswM_NvM_CurrentJobMode(NVM_WRITE_ALL, finalResult);
#else
        /* Notice the writeall result. */
        NVM_MultiBlock_CallBack(NvM_CurMultiJob, finalResult);
#endif

        NvM_CurMultiJob = NVM_NO_REQUEST;   /* End multiple block processing. */
        NvM_FailedCounter = NVM_INIT_0;     /* Clear failed counter. */
    }

    /* Update status for the block when it is not in the single block queue. */
    if( blockMngmnt->NvRamErrStatus != NVM_REQ_PENDING )
    {
        blockMngmnt->NvRamErrStatus = NvM_QueueCrrntJob.JobResult;
    }
    blockMngmnt->RemainLegth = blockTab->NvBlockLength;

    NVM_SuccessCounter = NVM_INIT_0;    /* Clear Success counter. */
    NvM_RetryCounter = NVM_INIT_0;      /* Clear counter of the number of read backup data. */
    /* Reset reduant block as primary block. */
    NVM_RedundantNumber = NVM_REDUNDANT_PRIMARY;
    NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
    NvM_MultiStateMachine = NVM_STATEMACHINE_IDLE;
}

/*
********************************************************************************
* Function Name: NvM_MainFunction_FinishSwitch
*
* Explanation: Function to finish queue job and reset request.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_FinishSwitch(void)
{
    if( NVM_MULTI == NvM_ModuleState )
    {
        NvM_MultiStateMachine = NVM_STATEMACHINE_FINISH;   /* To end state. */
        /* End processing flow, reset process information. */
        NvM_MainFunction_WriteAllFinish();
    }
    else
    {
        NvM_SingleStateMachine = NVM_STATEMACHINE_FINISH;   /* To end state. */
        /* End processing flow, reset process information. */
        NvM_MainFunction_WriteFinish();
    }
}
/*
********************************************************************************
* Function Name: NvM_MainFunction_ReadAllFinish
*
* Explanation: Function to finish queue job and reset request.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_ReadAllFinish(void)
{
    uint8 finalResult;
    uint16 locBlockId;
    uint16 compId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Get blockID of current job. */
    locBlockId = NvM_QueueCrrntJob.CurBlockId;
    /* Get block management of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];
    /* Get block definition of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];

    if( (NvM_QueueCrrntJob.JobResult != NVM_REQ_OK)
        && (NvM_QueueCrrntJob.JobResult != NVM_REQ_BLOCK_SKIPPED) )
    {
        NvM_FailedCounter++;    /* Record the number of failed blocks. */
    }
    if( NVM_REQ_OK == NvM_QueueCrrntJob.JobResult )
    {
         /* NvMSelectBlockForReadAll is configured. */
         /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
        if( NVM_SELECT_BLOCK_4_READALL_ON == NvM_Block_Descriptor_Table[locBlockId].Select4ReadAll )
        {
            /* Validate the RAM block and mark block as unchanged. */
            blockMngmnt->NvRamState |= NVM_BLOCK_VALID;
            blockMngmnt->NvRamState &= NVM_BLOCK_UNCHANGED;
            /* Copy data from RAM Mirror to RAM. */
            NvM_MainFun_CopyDataToRam();
            /* Check whether the configuration ID is consistent. */
            NvM_MainFun_CheckConfigureID();
            /* Check if last operation is an extended runtime preparation[SWS_NvM_00309]. */
            if( (TRUE == NvM_CfgidMismatch) && (TRUE == NvM_WriteCfgidFlg)
                                              && (FALSE == blockTab->ResistantToChangedSw) )
            {
                blockMngmnt->NvRamState &= (NVM_BLOCK_INVALID & NVM_BLOCK_UNCHANGED);
            }
        }
    }
    else if( NVM_REQ_RESTORED_FROM_ROM == NvM_QueueCrrntJob.JobResult )
    {
        /* Validate the RAM block and mark block as changed. */
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
        blockMngmnt->NvRamState |= (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED);
    }
    else if( (NVM_REQ_NOT_OK == NvM_QueueCrrntJob.JobResult)
                            || (NVM_REQ_NV_INVALIDATED == NvM_QueueCrrntJob.JobResult)
                            || (NVM_REQ_INTEGRITY_FAILED == NvM_QueueCrrntJob.JobResult) )
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
        blockMngmnt->NvRamState &= (NVM_BLOCK_INVALID & NVM_BLOCK_UNCHANGED);
        /* Judge whether currentjob ID is configuration ID. */
        if( NVM_BLOCK_STARTID == locBlockId )
        {
            /* Set write configid flag. */
            NvM_WriteCfgidFlg = TRUE;
            /* Set new configuration ID. */
            compId = NVM_COMPILED_CONFIG_ID;
            NvM_CompiledConfigId[NVM_CFGID_SECOND_BIT] = (uint8)(compId & NVM_STATICID_MASK);
            NvM_CompiledConfigId[NVM_CFGID_FIRST_BIT] = (uint8)((compId >>
                                                 NVM_STATICID_SHIFT_BIT) & NVM_STATICID_MASK);
            /* Set the RAM block to valid. */
            NvM_gstaBlockVar[locBlockId].NvRamState |= NVM_BLOCK_VALID;
        }
    }
    else
    {
        /* Do nothing. */
    }
    /* Check the write once attribute. */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    if( (TRUE == blockTab->WriteBlockOnce) && (NVM_REQ_OK == NvM_QueueCrrntJob.JobResult) )
    {
        blockMngmnt->NvRamState |= NVM_BLOCK_PRTCT_ON;
    }
    /* Notice the single block job result. */
    NVM_SingleBlock_CallBack(locBlockId, NVM_READ_BLOCK, NvM_QueueCrrntJob.JobResult);
    /* Multi block operation finish. */
    if( NvM_QueueCrrntJob.RemainNum == NVM_INIT_0 )
    {
        /* Disable fast mode. */
#if( NVM_DRV_MODE_SWITCH == STD_ON )
        MemIf_SetMode(MEMIF_MODE_SLOW);
#endif
        NvM_Multi_FirstFlg = TRUE;  /* Reset multi block operation start identification. */
        /* Reset Crc start avlue. */
        NvM_QueueCrrntJob.CrcValu = NVM_CRC_START_VALUE;
        /* Reset current blockid to null. */
        NvM_QueueCrrntJob.CurBlockId = NVM_QUEUE_CURRENTBLOCKID;
        /* Clear readall request. */
        NvM_QueueCrrntJob.MultiBlockReq &= NVM_BLOCK_READALL_CL;
        /* Clear configid mismatch flag. */
        NvM_CfgidMismatch = FALSE;

        if( NVM_INIT_0 == NvM_FailedCounter )   /* No failed. */
        {
            finalResult = NVM_REQ_OK;
        }
        else
        {
            finalResult = NVM_REQ_NOT_OK;
        }
        /* Set multiple flag. */
        NvM_gstaBlockVar[NVM_INIT_0].NvRamErrStatus = finalResult;

#if( NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON )
        /* Notice bswm of mutli service id and status currently processed. */
        BswM_NvM_CurrentJobMode(NVM_READ_ALL, finalResult);
#else
        /* Notice others the readall result. */
        NVM_MultiBlock_CallBack(NvM_CurMultiJob, finalResult);
#endif /* NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON */

        NvM_CurMultiJob = NVM_NO_REQUEST;   /* End multiple block processing. */
        NvM_FailedCounter = NVM_INIT_0;     /* Clear failed counter. */
    }

    /* Update status for the block when it is not in the single block queue. */
    if( blockMngmnt->NvRamErrStatus != NVM_REQ_PENDING )
    {
        blockMngmnt->NvRamErrStatus = NvM_QueueCrrntJob.JobResult;
    }
    blockMngmnt->RemainLegth = blockTab->NvBlockLength;
    NVM_SuccessCounter = NVM_INIT_0;    /* Clear Success counter. */
    /* Clear counter of the number of read backup data. */
    NvM_RetryCounter = NVM_INIT_0;
    /* Reset reduant block as primary block. */
    NVM_RedundantNumber = NVM_REDUNDANT_PRIMARY;
    NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
    NvM_ReadRomFlg = FALSE;
}

/*
********************************************************************************
* Function Name: NvM_MainFun_CopyDataToRam
*
* Explanation: Function to copy data from RAM Mirrir to RAM.
*
* param: None
*
* retval: None
*
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_CopyDataToRam(void)
{
    uint16 tryCounter;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Get blockID of current job. */
    locBlockId = NvM_QueueCrrntJob.CurBlockId;
    /* Get block management of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];
    /* Get block definition of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];
    blockMngmnt->RemainLegth = blockTab->NvBlockLength - Nvm_CrcCalc_Size_Table[blockTab->CrcType]
                            - NVM_STATICID_LENGTH;

    /* Check if enable NvM_SyncMechanismUesd. */
    if( TRUE == NvM_SyncMechanismUesd )
    {
        for( tryCounter = NVM_INIT_0; tryCounter < NVM_REPEAT_MIRROR_OPERATIONS;
            tryCounter++ )
        {
            /* Copy data to upper. */
            /* Polyspace +1 RTE:COR [JUstified:Unset] "NSCA_Polyspace_NvM_CorrectnessCondition" */
            if( E_OK == blockTab->NvMReadRamBlockFromNvCallback(&Nvm_InternalBuffer[NVM_STATICID_LENGTH]) )
            {
                break;
            }
        }
        if( NVM_REPEAT_MIRROR_OPERATIONS == tryCounter )
        {
            /* Set result to unsuccessfully. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
        }
    }
    /* Check if the RAM address is valid. */
    else if( blockMngmnt->RamAddr != NULL_PTR )
    {
        NvM_MemmoryCopy(&Nvm_InternalBuffer[NVM_STATICID_LENGTH],
                        blockMngmnt->RamAddr,
                        blockMngmnt->RemainLegth);
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_CheckConfigureID
*
* Explanation: Check whether the configure ID is consistent with the configuration.
*
* param: None
*
* retval: None
*
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_CheckConfigureID(void)
{
     uint16 curConfigureid;
     Nvm_BlockManagment_st *blockMngmnt;

#if( NVM_DYNAMIC_CONFIGURATION == STD_ON )
     uint16 compId;
#endif

     /* Get block management of current job. */
     blockMngmnt = &NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId];

     /* Judge whether currentjob ID is configuration ID and whether RAM address is valid. */
    if( (NVM_BLOCK_STARTID == NvM_QueueCrrntJob.CurBlockId)
                                 && (blockMngmnt->RamAddr != NULL_PTR) )
    {
        /* Get the configure id from ram. */
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
        curConfigureid = ((uint16)((uint16)blockMngmnt->RamAddr[NVM_CFGID_FIRST_BIT] << NVM_CFGID_SHIFT_BIT) |
                /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
                (uint16)(blockMngmnt->RamAddr[NVM_CFGID_SECOND_BIT]));

        /* Judge whether the configuration ID matches. */
        if( NVM_COMPILED_CONFIG_ID != curConfigureid )
        {
            /* Set configid mismatch flag. */
            NvM_CfgidMismatch = TRUE;
            /* Set job result for configure id mismatch. */
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;

#if( NVM_DYNAMIC_CONFIGURATION == STD_ON )
            /* Set write configid flag. */
            NvM_WriteCfgidFlg = TRUE;
            /* Set configid to new id. */
            compId = NVM_COMPILED_CONFIG_ID;
            NvM_CompiledConfigId[NVM_CFGID_SECOND_BIT] = (uint8)(compId & NVM_STATICID_MASK);
            NvM_CompiledConfigId[NVM_CFGID_FIRST_BIT] = (uint8)((compId >>
                                                 NVM_STATICID_SHIFT_BIT) & NVM_STATICID_MASK);
            /* Set the RAM block to valid. */
            NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId].NvRamState |= (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED);
#endif
        }
        else
        {
            blockMngmnt->NvRamState |= NVM_BLOCK_VALID;
        }
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFunction_RDBI
*
* Explanation: Function to read block by blockID.
*
* param: None
*
* retval: None
*
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_RDBI(void)
{
    uint8 step_Result;

    switch( NvM_SingleStateMachine )
    {
        case NVM_STATEMACHINE_IDLE:
            /* Prepare for reading block processing. */
            step_Result = NvM_MainFun_ProcessInit();
            NVM_Single_StateMachine_DualStates(step_Result, NVM_STATEMACHINE_REQUEST,
                                               NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_REQUEST:
            /* Sending read data request to the lower level. */
            step_Result = NvM_MainFun_ReadBlock();
            NVM_Single_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_BUSY,
                                              NVM_STATEMACHINE_RETRY, NVM_STATEMACHINE_RESISTANT);
            break;

        case NVM_STATEMACHINE_BUSY:
            /* wait for processing results. */
            step_Result = NvM_MainFun_Busy();
            NVM_Single_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_BUSY,
                                              NVM_STATEMACHINE_CRCCALC, NVM_STATEMACHINE_RETRY);
            break;

        case NVM_STATEMACHINE_CRCCALC:
            step_Result = NvM_MainFun_CheckCrc();   /* Check crc. */
            NVM_Single_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_CRCCALC,
                                              NVM_STATEMACHINE_RETRY, NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_RETRY:
            /* Request to read data again or read redundant data. */
            step_Result = NvM_MainFun_ReadRetry();
            NVM_Single_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_RESISTANT,
                                              NVM_STATEMACHINE_BUSY, NVM_STATEMACHINE_RETRY);
            break;

        case NVM_STATEMACHINE_RESISTANT:
            /* Copy the default data to upper. */
            NvM_MainFun_RestoreNvBlock();
            NVM_Single_StateMachine_SoleState(NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_FINISH:
            /* End processing flow, reset process information. */
            NvM_MainFunction_ReadFinish();
            NVM_Single_StateMachine_SoleState(NVM_STATEMACHINE_IDLE);
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFunction_WDBI
*
* Explanation: Function to write block by blockID.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_WDBI(void)
{
    uint8 step_Result;

    switch( NvM_SingleStateMachine )
    {
        case NVM_STATEMACHINE_IDLE:
            /* Prepare for writing block processing. */
            step_Result = NvM_MainFun_ProcessInit();
            NVM_Single_StateMachine_DualStates(step_Result, NVM_STATEMACHINE_CRCCALC,
                                               NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_CRCCALC:
            /* crc protecting. */
            NvM_MainFun_ProtectCrc();
            break;

        case NVM_STATEMACHINE_BUSY:
            /* wait for processing results */
            step_Result = NvM_MainFun_Busy();
            /* The last asynchronous request has been finished successfully. */
            if( NVM_TRANSITION_STATE2 == step_Result )
            {

#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
                NvM_IsNeedWriteVerify();
#else
                /* Increase job successful counter. */
                NVM_SuccessCounter++;
                /* Write the second block, Only for REDUNDANT. */
                NvM_MainFun_WriteReDundant();
#endif

            }
            /* The last asynchronous write request has been finished unsuccessfully. */
            if( NVM_TRANSITION_STATE3 == step_Result )
            {
                NvM_SingleStateMachine = NVM_STATEMACHINE_RETRY;
            }
            break;

        case NVM_STATEMACHINE_RETRY:
            /* Sending write backup data request to the lower level. */
            NvM_MainFun_WriteRetry();
            break;

        case NVM_STATEMACHINE_FINISH:
            NvM_MainFunction_WriteFinish(); /* End processing flow, reset process information. */
            break;

#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
        case NVM_STATEMACHINE_VERIFY_REQ:
            /* Send read request to do vrtify. */
            NvM_MainFun_Verify_Request();
            break;

        case NVM_STATEMACHINE_VERIFY_BUSY:
            /* Wait the job result. */
            step_Result = NvM_MainFun_Busy();
            if(NVM_TRANSITION_STATE2 == step_Result)
            {
                /* Compare the data in ram block and buffer. */
                NvM_MainFun_Verify_Compare();
            }
            if(NVM_TRANSITION_STATE3 == step_Result)
            {
                NvM_MainFun_WriteRetry();
            }
            break;

        case NVM_STATEMACHINE_COMPARE:
            /* Compare the data in ram block and buffer. */
            NvM_MainFun_Verify_Compare();
            break;
#endif

        default:
            /* Nothing to do. */
            break;
    }
}

#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: NvM_IsNeedWriteVerify
*
* Explanation: Function to check if need to do write verify.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_IsNeedWriteVerify(void)
{
    /* Check if have enable write verify and the WriteVerificationDataSize bigger than 0. */
    if( (NVM_WRITE_VERIFICATION_ON == NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].WriteVerification) &&
        (NVM_INIT_0 < NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].WriteVerificationDataSize) )
    {
        /* Reset Residual length. */
        NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId].RemainLegth =
        NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].NvBlockLength;
        NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId].CurRamAddr = Nvm_InternalBuffer;
        /* Send read request to do vrtify. */
        NvM_MainFun_Verify_Request();
    }
    else
    {
        /* Increase job successful counter. */
        NVM_SuccessCounter++;
        /* Write the second block, Only for REDUNDANT. */
        NvM_MainFun_WriteReDundant();
    }
}
#endif

#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: NvM_MainFun_Verify_Request
*
* Explanation: Function to send read request for write verify.
*
* param: None
*
* retval: TRUE: Read requset have been acceptted.
*         FALSE: Read requset have not been acceptted.
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_Verify_Request(void)
{
    uint8 memIf_result;
    uint16 locBlockId;
    uint16 readLength;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;      /* Get blockID of current job. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get managment information of current job. */
    blockTab = &NvM_Block_Descriptor_Table[locBlockId];     /* Get block definition of current job. */

    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    if( blockMngmnt->RemainLegth <= blockTab->WriteVerificationDataSize )
    {
        readLength = blockMngmnt->RemainLegth;
    }
    else
    {
        readLength = blockTab->WriteVerificationDataSize;
    }

    /* Call the read interface of MemIf to request read data. */
    memIf_result = MemIf_Read(blockTab->DeviceId, NvM_QueueCrrntJob.BlockNumber, NvM_WriteVerifyLength,
                              NvM_WriteVerifyBuffer, readLength);

    /* Results feedback from Lower level is OK? */
    if( E_OK == memIf_result )
    {
        /* Set result is pending. */
        NvM_QueueCrrntJob.JobResult = NVM_REQ_PENDING;
        /* Allow access to the next state machine. */
        if( NVM_MULTI == NvM_ModuleState )
        {
            NvM_MultiStateMachine = NVM_STATEMACHINE_VERIFY_BUSY; /* To waiting result state. */
        }
        else
        {
            NvM_SingleStateMachine = NVM_STATEMACHINE_VERIFY_BUSY; /* To waiting result state. */
        }
    }
    else
    {
        NvM_WriteVerifyLength = NVM_INIT_0;
        /* Set result is NotOK,End operation. */
        NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
        /* Allow access to the next state machine. */
        if( NVM_MULTI == NvM_ModuleState )
        {
            NvM_MultiStateMachine = NVM_STATEMACHINE_RETRY; /* Retry. */
        }
        else
        {
            NvM_SingleStateMachine = NVM_STATEMACHINE_RETRY; /* Retry. */
        }
    }
}
#endif

#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
/*
********************************************************************************
* Function Name: NvM_MainFun_Verify_Compare
*
* Explanation: Function to compare data read form underlying with ram block.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_Verify_Compare(void)
{
    uint16 currentLength;
    uint16 loopNum;
    uint8 *dataAddr;
    const NvM_Block_Descriptor_Table_st *blockTab;
    Nvm_BlockManagment_st *blockMngmnt;

    if( NVM_MULTI == NvM_ModuleState )
    {
        NvM_MultiStateMachine = NVM_STATEMACHINE_VERIFY_REQ;
    }
    else
    {
        NvM_SingleStateMachine = NVM_STATEMACHINE_VERIFY_REQ;
    }
    /* Get block definition of current job. */
    blockTab = &NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId];
    /* Get managment information of current job. */
    blockMngmnt = &NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId];
    dataAddr = blockMngmnt->CurRamAddr;

    /* Get the length to be dealt of one cycle. */
    if( blockTab->WriteVerificationDataSize <= blockMngmnt->RemainLegth )
    {
        currentLength = blockTab->WriteVerificationDataSize;
    }
    else
    {
        currentLength = blockMngmnt->RemainLegth;
    }

    NvM_WriteVerifyLength += currentLength;
    /* Set the block remain length. */
    blockMngmnt->RemainLegth -= currentLength;
    /* PolySpace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_NvM_18.4" */
    blockMngmnt->CurRamAddr += currentLength;    /* PRQA S 488 */ /* NSCA_QAC_NvM_Rule_18.4 */
    /* Compare data. */
    for( loopNum = NVM_INIT_0; loopNum < currentLength; loopNum++)
    {
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.4 [Justified:Unset] "NSCA_Polyspace_NvM_18.4" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
        if( *(dataAddr + loopNum) != NvM_WriteVerifyBuffer[loopNum] )    /* PRQA S 488 */ /* NSCA_QAC_NvM_Rule_18.4 */
        {
            /* Set next state to write retry. */
            if( NVM_MULTI == NvM_ModuleState )
            {
                NvM_MultiStateMachine = NVM_STATEMACHINE_RETRY; /* Retry. */
            }
            else
            {
                NvM_SingleStateMachine = NVM_STATEMACHINE_RETRY; /* Retry. */
            }
            NvM_WriteVerifyLength = NVM_INIT_0;
            NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
            break;
        }
    }
    /* Check if finish compare operation. */
    if( (NVM_INIT_0 == blockMngmnt->RemainLegth) && (NvM_QueueCrrntJob.JobResult != NVM_REQ_NOT_OK) )
    {
        NvM_WriteVerifyLength = NVM_INIT_0;
        /* Increase job successful counter. */
        NVM_SuccessCounter++;
        /* Write the second block, Only for REDUNDANT. */
        NvM_MainFun_WriteReDundant();
    }
}
#endif
/*
********************************************************************************
* Function Name: NvM_MainFunction_RSDBI
*
* Explanation: Function to restore block by blockID.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_RSDBI(void)
{
    uint8 step_Result;

    switch( NvM_SingleStateMachine )
    {
        case NVM_STATEMACHINE_IDLE:
            /* Prepare for restoring block processing. */
            step_Result = NvM_MainFun_ProcessInit();
            NVM_Single_StateMachine_DualStates(step_Result, NVM_STATEMACHINE_REQUEST,
                                               NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_REQUEST:
            /* Restore default value. */
            NvM_MainFun_RestoreRequest();
            NVM_Single_StateMachine_SoleState(NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_FINISH:
            /* End processing flow, reset process information. */
            NvM_MainFunction_Finish();
            NVM_Single_StateMachine_SoleState(NVM_STATEMACHINE_IDLE);
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFunction_EDBI
*
* Explanation: service to rease block by blockID.(NvM private function)
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_EDBI(void)
{
    uint8 step_Result;

    switch( NvM_SingleStateMachine )
    {
        case NVM_STATEMACHINE_IDLE:
            NVM_Single_StateMachine_SoleState(NVM_STATEMACHINE_REQUEST);
            break;

        case NVM_STATEMACHINE_REQUEST:
            /* Sending erase data request to the lower level. */
            step_Result = NvM_MainFun_EraseNvBlock();
            NVM_Single_StateMachine_DualStates(step_Result, NVM_STATEMACHINE_BUSY,
                                               NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_BUSY:
            /* wait for processing results. */
            step_Result = NvM_MainFun_Busy();
            /* Check if have erased nv block successfully last operation. */
            if( NVM_REQ_OK == NvM_QueueCrrntJob.JobResult )
            {
                /* Increase job successful counter. */
                NVM_SuccessCounter++;
            }
            NVM_Single_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_BUSY,
                                              NVM_STATEMACHINE_ERASED, NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_ERASED:
            /* wait for processing results. */
            step_Result = NvM_MainFun_EraseReDundant();
            NVM_Single_StateMachine_DualStates(step_Result, NVM_STATEMACHINE_BUSY,
                                               NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_FINISH:
            /* End processing flow, reset process information. */
            NvM_MainFunction_Finish();
            NVM_Single_StateMachine_SoleState(NVM_STATEMACHINE_IDLE);
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFunction_IDBI
*
* Explanation: Function to invalidate block by blockID.(NvM private function)
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFunction_IDBI(void)
{
    uint8 step_Result;

    switch( NvM_SingleStateMachine )
    {
        case NVM_STATEMACHINE_IDLE:
            NVM_Single_StateMachine_SoleState(NVM_STATEMACHINE_REQUEST);
            break;

        case NVM_STATEMACHINE_REQUEST:
            /* Sending incalidate data request to the lower level. */
            step_Result = NvM_MainFun_InvalidateNvBlock();
            NVM_Single_StateMachine_DualStates(step_Result, NVM_STATEMACHINE_BUSY,
                                               NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_BUSY:
            /* wait for processing results. */
            step_Result = NvM_MainFun_Busy();
            /* Check if have invalidate nv block successfully last operation. */
            if( NVM_REQ_OK == NvM_QueueCrrntJob.JobResult )
            {
                /* Increase job successful counter. */
                NVM_SuccessCounter++;
            }
            NVM_Single_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_BUSY,
                                              NVM_STATEMACHINE_INALIDATED, NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_INALIDATED:
            /* wait for processing results. */
            step_Result = NvM_MainFun_InvalidateReDundant();
            NVM_Single_StateMachine_DualStates(step_Result, NVM_STATEMACHINE_BUSY,
                                                           NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_FINISH:
            /* End processing flow, reset process information. */
            NvM_MainFunction_Finish();
            NVM_Single_StateMachine_SoleState(NVM_STATEMACHINE_IDLE);
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_ReadAll
*
* Explanation: Function to read all.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_ReadAll(void)
{
    uint8 step_Result;

    switch( NvM_MultiStateMachine )
    {
        case NVM_STATEMACHINE_IDLE:
            /* set NVM_READ_ALL for multiblcok. */
            NVM_MultiBlock_Set_ServiceId(NVM_READ_ALL);
            NVM_MultiStateMachine_ReadAll();
            break;

        case NVM_STATEMACHINE_REQUEST:
            /* Sending read data request to the lower level. */
            step_Result = NvM_MainFun_ReadBlock();
            NVM_Multi_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_BUSY,
                                              NVM_STATEMACHINE_RETRY, NVM_STATEMACHINE_RESISTANT);
            break;

        case NVM_STATEMACHINE_BUSY:
            /* wait for processing results. */
            step_Result = NvM_MainFun_Busy();
            NVM_Multi_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_BUSY,
                                             NVM_STATEMACHINE_CRCCALC, NVM_STATEMACHINE_RETRY);
            break;

        case NVM_STATEMACHINE_CRCCALC:
            /* crc checking. */
            step_Result = NvM_MainFun_CheckCrc();
            NVM_Multi_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_CRCCALC,
                                             NVM_STATEMACHINE_RETRY, NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_RETRY:
            /* Request to read backup data. */
            step_Result = NvM_MainFun_ReadRetry();
            NVM_Multi_StateMachine_ThrStates(step_Result, NVM_STATEMACHINE_RESISTANT,
                                             NVM_STATEMACHINE_BUSY, NVM_STATEMACHINE_RETRY);
            break;

        case NVM_STATEMACHINE_RESISTANT:
            /* Restore default value. */
            NvM_MainFun_RestoreNvBlock();
            NVM_Multi_StateMachine_SoleState(NVM_STATEMACHINE_FINISH);
            break;

        case NVM_STATEMACHINE_FINISH:
            /* End processing flow, reset process information. */
            NvM_MainFunction_ReadAllFinish();
            /* Waiting for the next block to process. */
            NVM_Multi_StateMachine_SoleState(NVM_STATEMACHINE_IDLE);
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_WriteAll
*
* Explanation: Function to write all.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_WriteAll(void)
{
    uint8 step_Result;

    switch( NvM_MultiStateMachine )
    {
        case NVM_STATEMACHINE_IDLE:
            /* set NVM_WRITE_ALL for multiblcok. */
            NVM_MultiBlock_Set_ServiceId(NVM_WRITE_ALL);
            NVM_MultiStateMachine_WriteAll();
            break;

        case NVM_STATEMACHINE_CRCCALC:
            /* crc protecting. */
            NvM_MainFun_ProtectCrc();
            break;

        case NVM_STATEMACHINE_REQUEST:
            /* Sending write data request to the lower level. */
            NvM_MainFun_WriteBlock();
            break;

        case NVM_STATEMACHINE_BUSY:
            /* wait for processing results. */
            step_Result = NvM_MainFun_Busy();
            /* The last asynchronous request has been finished successfully. */
            if( NVM_TRANSITION_STATE2 == step_Result )
            {

#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
                NvM_IsNeedWriteVerify();
#else
                /* Increase job successful counter. */
                NVM_SuccessCounter++;
                NvM_MultiStateMachine = NVM_STATEMACHINE_WRITERED;
                /* Write the second block, Only for REDUNDANT. */
                NvM_MainFun_WriteReDundant();
#endif

            }
            /* The last asynchronous write request has been finished unsuccessfully. */
            if( NVM_TRANSITION_STATE3 == step_Result )
            {
                NvM_MultiStateMachine = NVM_STATEMACHINE_RETRY;
            }
            break;


        case NVM_STATEMACHINE_RETRY:
            /* Sending write backup data request to the lower level. */
            NvM_MainFun_WriteRetry();
            break;

        case NVM_STATEMACHINE_FINISH:
            /* End processing flow, reset process information. */
            NvM_MainFunction_WriteAllFinish();
            break;

#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
        case NVM_STATEMACHINE_VERIFY_REQ:
            /* Send read request to do vrtify. */
            NvM_MainFun_Verify_Request();
            break;

        case NVM_STATEMACHINE_VERIFY_BUSY:
            /* Wait the job result. */
            step_Result = NvM_MainFun_Busy();
            if(NVM_TRANSITION_STATE2 == step_Result)
            {
                /* Compare the data in ram block and buffer. */
                NvM_MainFun_Verify_Compare();
            }
            if(NVM_TRANSITION_STATE3 == step_Result)
            {
                NvM_MainFun_WriteRetry();
            }
            break;

        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        case NVM_STATEMACHINE_COMPARE:
            /* Compare the data in ram block and buffer. */
            NvM_MainFun_Verify_Compare();
            break;
#endif

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_CancelWriteAll
*
* Explanation: Function to cancel writeall multi process.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_CancelWriteAll(void)
{
    uint8 step_Result = FALSE;
    /* Check whether there are writeall requests at present. */
    if( (NvM_QueueCrrntJob.MultiBlockReq & NVM_BLOCK_WRITEALL_SET) > NVM_INIT_0 )
    {
        if( NVM_WRITE_ALL == NvM_CurMultiJob )  /* Writeall is processed. */
        {
            do
            {
                /* The remaining NVM blocks remain to be processed. */
                if( NvM_QueueCrrntJob.RemainNum != NVM_INIT_0 )
                {
                    /* Process the next ID in sequence. */
                    NvM_QueueCrrntJob.CurBlockId++;
                    /* Set the last blockID for configure ID not match. */
                    if( (TRUE == NvM_WriteCfgidFlg) &&
                                            (NVM_NUM_OF_BLOCK_TOTAL == NvM_QueueCrrntJob.CurBlockId) )
                    {
                        NvM_QueueCrrntJob.CurBlockId = NVM_BLOCK_STARTID;
                    }
                    /* Complete a ID processing, reduce the remaining number. */
                    NvM_QueueCrrntJob.RemainNum--;
                }

                if( NVM_INIT_0 == NvM_QueueCrrntJob.RemainNum )
                {
                    /* All blocks have been processed. */
                    step_Result = TRUE;
                }
            }
            while(FALSE == step_Result);

            /* Set multi job result.*/
            NvM_gstaBlockVar[NVM_INIT_0].NvRamErrStatus = NVM_REQ_CANCELED;
            /* Clear the writeall request. */
            NvM_QueueCrrntJob.MultiBlockReq &= NVM_BLOCK_WRITEALL_CL;
            /* No writeall request, clear the cancelwriteall request. */
            NvM_QueueCrrntJob.MultiBlockReq &= NVM_BLOCK_CANCEL_WRITEALL_CL;
            /* Reset the current blockID. */
            NvM_QueueCrrntJob.CurBlockId = NVM_QUEUE_CURRENTBLOCKID;
            /* Reset the First read or write flag for multi request. */
            NvM_Multi_FirstFlg = TRUE;
            /* Current Multi job init. */
            NvM_CurMultiJob = NVM_NO_REQUEST;
/* Disable fast mode. */
#if( NVM_DRV_MODE_SWITCH == STD_ON )
            MemIf_SetMode(MEMIF_MODE_SLOW);
#endif

#if( NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON )
            /* Notice bswm of mutli service id and status currently processed. */
            BswM_NvM_CurrentJobMode(NVM_CANCEL_WRITE_ALL, NVM_REQ_CANCELED);
#else
            /* Notice others the cacelwriteall result. */
            NVM_MultiBlock_CallBack(NVM_CANCEL_WRITE_ALL, NVM_REQ_CANCELED);
#endif /* NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON */

        }
        else
        {
             /* Set multi job result.*/
            NvM_gstaBlockVar[NVM_INIT_0].NvRamErrStatus = NVM_REQ_CANCELED;
            /* Clear the writeall request. */
            NvM_QueueCrrntJob.MultiBlockReq &= NVM_BLOCK_WRITEALL_CL;
            /* No writeall request, clear the cancelwriteall request. */
            NvM_QueueCrrntJob.MultiBlockReq &= NVM_BLOCK_CANCEL_WRITEALL_CL;
            /* Reset the current blockID. */
            NvM_QueueCrrntJob.CurBlockId = NVM_QUEUE_CURRENTBLOCKID;
            /* Reset the First read or write flag for multi request. */
            NvM_Multi_FirstFlg = TRUE;
        }
    }
    else
    {
        /* No writeall request, clear the cancelwriteall request and do nothing. */
        NvM_QueueCrrntJob.MultiBlockReq &= NVM_BLOCK_CANCEL_WRITEALL_CL;
        NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_CopyRomData
*
* Explanation: Function to copy data to RAM Mirror/RAM
*
* param: Romaddress: Rom address.
*
* retval: None
********************************************************************************
*/
static FUNC(void, NVM_CODE) NvM_MainFun_CopyRomData
(
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) Romaddress
)
{
    Nvm_BlockManagment_st *blockMngmnt;
    uint8 *romData;

    blockMngmnt = &NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId];    /* Get block management of current job. */
    romData = Romaddress;
    /* Determine whether the operation is to read the ROM or restore. */
    if( TRUE == NvM_ReadRomFlg)
    {
        NvM_MemmoryCopy(romData, &Nvm_InternalBuffer[NVM_STATICID_LENGTH],
                                                      blockMngmnt->RemainLegth);
        /* Set job result for read rom successfully. */
        NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
    }
    else if( blockMngmnt->RamAddr != NULL_PTR )
    {
        NvM_MemmoryCopy(romData, blockMngmnt->RamAddr, blockMngmnt->RemainLegth);
        /* Set job result for restore successfully. */
        NvM_QueueCrrntJob.JobResult = NVM_REQ_RESTORED_FROM_ROM;
    }
    else
    {
        /* Do nothing. */
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_GetNewBlock
*
* Explanation: Function to get new block index.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_MainFun_GetNewBlock(void)
{
    uint8 retValue;
    Nvm_BlockManagment_st *blockMngmnt;

    /* Detect if there is an immediate write request. */
    if( (Nvm_QueueHeader.CounterImmediate > NVM_INIT_0)
         && (Nvm_ImmediateWrite != NVM_IMMEDIATE_WRITE_TURE)
         && (NvM_QueueCrrntJob.CurBlockId != NVM_QUEUE_CURRENTBLOCKID) )
    {
        /* Clear the write verify offset. */
#if( NVM_WRITEVERIFY_ENABLE == STD_ON )
        NvM_WriteVerifyLength = NVM_INIT_0;
#endif
        /* Set immediate write flag. */
        Nvm_ImmediateWrite = NVM_IMMEDIATE_WRITE_TURE;

        /* Check if need to call lower cancel function. */
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
        if( MemIf_GetStatus(NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].DeviceId)
                           == MEMIF_BUSY )
        {
            MemIf_Cancel(NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].DeviceId);
        }

        /* Save multiple block request states. */
        if( NVM_MULTI == NvM_ModuleState )
        {
            Nvm_MultiReqTemp = NvM_QueueCrrntJob.MultiBlockReq;
            /* Set module state to single block request. */
            NvM_ModuleState = NVM_SINGLE;
            /* Clear multiple block request state. */
            NvM_QueueCrrntJob.MultiBlockReq = NVM_INIT_0;
            /* Reset the current remain block numbers. */
            NvM_QueueCrrntJob.RemainNum = NVM_INIT_0;
            /* Reset the current blockID. */
            NvM_QueueCrrntJob.CurBlockId = NVM_QUEUE_CURRENTBLOCKID;
            /* Reset the First read or write flag for multi request. */
            NvM_Multi_FirstFlg = TRUE;
            /* Reset the multi block state to IDLE. */
            NvM_MultiStateMachine = NVM_STATEMACHINE_IDLE;
        }
        else
        {
            /* Record processed blocks. */
            blockMngmnt = &NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId];
            /* Check if the interrupted request is processed. */
            if( NVM_STATEMACHINE_IDLE != NvM_SingleStateMachine )
            {
                /* Requeue the interrupted request,
                    if the enqueue fails, set the request result to fail. */
                retValue = NvM_ReQueueProcess(blockMngmnt->BlockId,
                                            blockMngmnt->RamAddr, blockMngmnt->CtrlType);
                if( retValue != E_OK )
                {
                    blockMngmnt->NvRamErrStatus = NVM_REQ_NOT_OK;
                }
            }
        }

        /* Get new block ID. */
        NvM_QueueCrrntJob.CurBlockId = NvM_QueuePop();

#if( NVM_STOP_SERVICES == STD_ON )
        /* The number of Fee devices in the queue */
        if( NVM_FEE_DEVICEID == NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].DeviceId )
        {
            Nvm_QueueHeader.FeeReqNum--;
        }
#endif
        /* Set single request to idle. */
        NvM_SingleStateMachine = NVM_STATEMACHINE_IDLE;
    }
    else
    {
        /* During single request processing and ready to process status is idle. */
        if( (NVM_SINGLE == NvM_ModuleState) && (Nvm_QueueHeader.Counter > NVM_INIT_0)
            && (NVM_STATEMACHINE_IDLE == NvM_SingleStateMachine) )
        {
            /* Get new block ID. */
            NvM_QueueCrrntJob.CurBlockId = NvM_QueuePop();

#if( NVM_STOP_SERVICES == STD_ON )
            /* The number of Fee devices in the queue */
            if( NVM_FEE_DEVICEID== NvM_Block_Descriptor_Table[NvM_QueueCrrntJob.CurBlockId].DeviceId )
            {
                Nvm_QueueHeader.FeeReqNum--;
            }
#endif
            /* Check if current block priority is 0. */
            if( (NVM_BLOCK_HIGHEST_PRI == NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId].Priority) &&
                (NVM_WRITE_BLOCK == NvM_gstaBlockVar[NvM_QueueCrrntJob.CurBlockId].CtrlType) )
            {
                /* Set immediate write flag. */
                Nvm_ImmediateWrite = NVM_IMMEDIATE_WRITE_TURE;
            }
        }
    }
}

#if( NVM_DEV_ERROR_DETECT == STD_ON )
/*
********************************************************************************
* Function Name: NVM_Det_ErrorReport
*
* Explanation: Function to report Error to Det.
*
* param: ApiId: Unique Api ID of NVRAM manager service.
*        ErrorId: Det Error ID of NVRAM manager.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
FUNC(void, NVM_CODE) NVM_Det_ErrorReport(uint8 ApiId, uint8 ErrorId)
{
    /* Report Error to Det. */
    (void)Det_ReportError(NVM_MODULE_ID, NVM_INSTANCE_ID, ApiId, ErrorId);
}
#endif

/*
********************************************************************************
* Function Name: NVM_Init_BlockManagment
*
* Explanation: Function to Initialize block management.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NVM_Init_BlockManagment(void)
{
    uint16 locIdIndx;

    /* Initialization of all block management information. */
    for( locIdIndx = NVM_INIT_0; locIdIndx < NVM_NUM_OF_BLOCK_TOTAL; locIdIndx++ )
    {
        /* Block ID initialization. */
        NvM_gstaBlockVar[locIdIndx].BlockId = NvM_Block_Descriptor_Table[locIdIndx].BlockId;
        /* Next processing block ID initialization. */
        NvM_gstaBlockVar[locIdIndx].NxtBlockId = NVM_QUEUE_NEXTBLOCKID;
        /* Processing type initialization. */
        NvM_gstaBlockVar[locIdIndx].CtrlType= NVM_NO_REQUEST;
        /* Priority initialization. */
        NvM_gstaBlockVar[locIdIndx].Priority = NvM_Block_Descriptor_Table[locIdIndx].JobPriority;
        /* DataIndex initialization. */
        NvM_gstaBlockVar[locIdIndx].DataIndex = NVM_INIT_0;
        /* Error status initialization. */
        NvM_gstaBlockVar[locIdIndx].NvRamErrStatus = NVM_REQ_NOT_OK;
        /* Ram address initialization. */
        NvM_gstaBlockVar[locIdIndx].RamAddr = NULL_PTR;
        /* current Ram address initialization. */
        NvM_gstaBlockVar[locIdIndx].CurRamAddr = NULL_PTR;
        /* Set redundant loss to FALSE. */
        NvM_gstaBlockVar[locIdIndx].NvmLossRedun = FALSE;
        NvM_gstaBlockVar[locIdIndx].RemainLegth = NvM_Block_Descriptor_Table[locIdIndx].NvBlockLength;
        /* Ram state initialization. */
        NvM_gstaBlockVar[locIdIndx].NvRamState = NVM_INIT_0;
        if( NVM_BLOCK_WRITE_PROT_ON == NvM_Block_Descriptor_Table[locIdIndx].WriteProt )
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* The block is configured for write protection. */
            NvM_gstaBlockVar[locIdIndx].NvRamState |= NVM_BLOCK_PRTCT_ON;
        }
    }
}

/*
********************************************************************************
* Function Name: NVM_Init_CrrntJob
*
* Explanation: Function to Initialize job management.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NVM_Init_CrrntJob(void)
{
    /* Information initialization of current work in queue. */
    /* Block ID initialization. */
    NvM_QueueCrrntJob.CurBlockId = NVM_QUEUE_CURRENTBLOCKID;
    /* Number of remaining work initialization. */
    NvM_QueueCrrntJob.RemainNum = NVM_INIT_0;
    /* Multi block request initialization. */
    NvM_QueueCrrntJob.MultiBlockReq = NVM_INIT_0;
    /* Job result initialization. */
    NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
    /* CRC start value initialization. */
    NvM_QueueCrrntJob.CrcValu = NVM_CRC_START_VALUE;
    Nvm_QueueHeader.Counter = NVM_INIT_0;
    Nvm_QueueHeader.CounterImmediate = NVM_INIT_0;
    Nvm_QueueHeader.FirstBlockId = NVM_QUEUE_CURRENTBLOCKID;
    Nvm_QueueHeader.LastBlockId = NVM_QUEUE_CURRENTBLOCKID;
}

/*
********************************************************************************
* Function Name: NVM_Init_QueueJob
*
* Explanation: Function to Initialize queue job.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NVM_Init_QueueJob(void)
{
    NvM_MultiStateMachine = NVM_STATEMACHINE_IDLE;  /* Operation state machine init. */
    NvM_SingleStateMachine = NVM_STATEMACHINE_IDLE; /* Operation state machine init. */
    NvM_RetryCounter = NVM_INIT_0;      /* Sign Redundant type block read another address init. */
    NvM_Multi_FirstFlg = TRUE;          /* Multi job Start identification init. */
    NvM_CurMultiJob = NVM_NO_REQUEST;   /* Current Multi job init. */
    NvM_FailedCounter = NVM_INIT_0;     /* Multi block operation fail counter init. */
    NVM_SuccessCounter = NVM_INIT_0;    /* Request successful count. */
    NVM_RedundantNumber = NVM_INIT_0;   /* Redundant type block number. */
    NvM_SyncMechanismUesd = FALSE;      /* Callback to copy nvmdata. */
    Nvm_ImmediateWrite = NVM_IMMEDIATE_WRITE_FALSE;
    Nvm_MultiReqTemp = NVM_INIT_0;
}

/*
********************************************************************************
* Function Name: NVM_MultiBlock_CallBack
*
* Explanation: Function to notice other block satate.
*
* param: ServiceId:Unique Service ID of NVRAM manager service.
*        JobResult:Covers the job result of the previous processed single block job.
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, NVM_CODE) NVM_MultiBlock_CallBack
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint8 ServiceId,
    NvM_RequestResultType JobResult
)
{
    /* Only notice the result,but not pendging. */
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( JobResult != NVM_REQ_PENDING )
    {
#if(NVM_MULTI_BLOCK_CALLBACK_ENABLE != STD_OFF)
        /* Notice upper job result by callback. */
        (void)NVM_MULTI_BLOCK_CALLBACK(ServiceId, JobResult);
#else
        NVM_DUMMY_STATEMENT(ServiceId);
#endif
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_ValidateAll
*
* Explanation: The sevice initiates a multi block validation process.
*
* param: None
*
* retval: None
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(void, NVM_CODE) NvM_MainFun_ValidateAll(void)
{
    uint16 tryCounter;
    const NvM_Block_Descriptor_Table_st *blockTab;
    Nvm_BlockManagment_st *blockMngmnt;

    /* Reset the remaining number to all. */
    NvM_QueueCrrntJob.RemainNum = NVM_BLOCK_REMAIN_NUMBER;

    /* Set multiple blocks status to pengding. */
    NvM_gstaBlockVar[NVM_BLOCK_RESERVEID].NvRamErrStatus = NVM_REQ_PENDING;

    for( tryCounter = NVM_BLOCK_STARTID; tryCounter <= NVM_BLOCK_REAL_NUMBER ; tryCounter++ )
    {
        blockMngmnt = &NvM_gstaBlockVar[tryCounter];    /* Get managment information of current job. */
        blockTab = &NvM_Block_Descriptor_Table[tryCounter]; /* Get block definition of current job. */
        NvM_QueueCrrntJob.CurBlockId = tryCounter;
        /* Check if the block is configed with the auto validation function. */
        if( (NVM_BLOCK_AUTO_VALID_ON == blockTab->AutoValidation) )
        {
            /* Check if the block is configed with ram block or syncMechanism function. */
            if( (blockTab->RamAddr != NULL_PTR) || ((NVM_BLOCK_USE_SYNC_MECHANISM_ON == blockTab->SyncMechanism) && (blockTab->NvBlockLength
             <= NVM_BLOCK_MAX_LENGTH)) )
            {
                /* Set the current block job result. */
                blockMngmnt->NvRamErrStatus = NVM_REQ_OK;
                /* Set the ram state. */
                blockMngmnt->NvRamState |= (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED);
            }
        }
        /* Check whether there are still unprocessed blocks. */
        if( NVM_INIT_0 != NvM_QueueCrrntJob.RemainNum )
        {
            NvM_QueueCrrntJob.RemainNum--;
        }
    }
    /* Check Whether there are still unprocessed blocks. */
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NVM_INIT_0 == NvM_QueueCrrntJob.RemainNum ) /* Finished. */
    {
        /* Clear validation all flag */
        NvM_QueueCrrntJob.MultiBlockReq &= NVM_BLOCK_VALIDATEALL_CL;
        /* Set multiple block status to OK */
        NvM_gstaBlockVar[NVM_BLOCK_RESERVEID].NvRamErrStatus = NVM_REQ_OK;
        /* Call the multi block callback information. */

#if( NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON )
        /* Notice bswm of mutli service id and status currently processed. */
        BswM_NvM_CurrentJobMode(NVM_VALIDATE_ALL, NVM_REQ_OK);
#else
        /* Notice the validateall result. */
        NVM_MultiBlock_CallBack(NVM_VALIDATE_ALL, NVM_REQ_OK);
#endif /* NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON */
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_SingleBlock
*
* Explanation: service to handle requests for single block operations.(NvM private function)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_MainFun_SingleBlock(void)
{
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;

    locBlockId = NvM_QueueCrrntJob.CurBlockId;      /* Get current processing blockID. */
    blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get Block managment struct adddress. */

    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
    switch( blockMngmnt->CtrlType )
    {
        case NVM_READ_BLOCK:
            NvM_MainFunction_RDBI();    /* Read data by blockId. */
            break;

        case NVM_WRITE_BLOCK:
            NvM_MainFunction_WDBI();    /* Write data by blockId. */
            break;

        case NVM_RESTORE_BLOCK_DEFAULTS:
            NvM_MainFunction_RSDBI();   /* Restore data by blockId. */
            break;

        case NVM_ERASE_NV_BLOCK:
            NvM_MainFunction_EDBI();    /* Erase block by blockId. */
            break;

        case NVM_INVALIDATE_NV_BLOCK:
            NvM_MainFunction_IDBI();    /* Invalidate block by blockId. */
            break;

        default:
            /* Nothing to do. */
            break;
    }
}

/*
********************************************************************************
* Function Name: NvM_MainFun_MultiBlock
*
* Explanation: Function to multi block operation.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_MainFun_MultiBlock(void)
{
    uint8 locMultiBlockReq;

    /* Get all the multi block request. */
    locMultiBlockReq = NvM_QueueCrrntJob.MultiBlockReq & NVM_BLOCK_MULTIREQUESTALL;

    /* Only in idle state can cancelwriteall. */
    if( ((locMultiBlockReq & NVM_BLOCK_CANCEL_WRITEALL_SET) > NVM_INIT_0)
       && (NVM_STATEMACHINE_IDLE == NvM_MultiStateMachine) )
    {
        NvM_MainFun_CancelWriteAll();   /* Cancle writeall. */
    }
    else if( (locMultiBlockReq & NVM_BLOCK_READALL_SET) > NVM_INIT_0 )
    {
        NvM_MainFun_ReadAll();  /* Read all block. */
    }
    else if( (locMultiBlockReq & NVM_BLOCK_WRITEALL_SET) > NVM_INIT_0 )
    {
        NvM_MainFun_WriteAll(); /* Write all block. */
    }
    else if( (locMultiBlockReq & NVM_BLOCK_VALIDATEALL_SET) > NVM_INIT_0 )
    {
        NvM_MainFun_ValidateAll();      /* ValidateAll job processing. */
    }
    else
    {
        /* Do nothing. */
    }
}

#define NVM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
