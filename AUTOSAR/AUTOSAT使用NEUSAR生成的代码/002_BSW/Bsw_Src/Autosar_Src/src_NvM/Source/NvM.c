/*
********************************************************************************
*
* File name: NvM.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.09.25
* Change: new created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangJipeng/2018.11.14
* Change: NvM_GetVersionInfo add null pointer decide.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: WangJipeng/2019.04.08
* Change: V2.0 release.
* Cause: Update
********************************************************************************
* Version: 1.3
* Author/Date: WangJipeng/2019.04.24
* Change: Modifying Common Problems Discovered by Other Modules.
* Cause: Revision
********************************************************************************
* Version: 1.4
* Author/Date: WangJipeng/2019.05.05
* Change: Delete duplicate local variables of the formats.
* Cause: Optimization
********************************************************************************
* Version: 1.5
* Author/Date: WangJipeng/2019.07.17
* Change: Fix NvM_SetDataIndex DET report parameter error.
*         Fix NvM_JobErrorNotification Error of ID check result judgement.
* Cause: Bugfix
********************************************************************************
* Version: 2.0
* Author/Date: WangJipeng/2019.08.08
* Change: Fix NvM_ReadBlock DET report parameter error.
* Cause: Bugfix
********************************************************************************
* Version: 2.1
* Author/Date: LuoJia/2019.11.08
* Change: Modify the input parameter of the check read/write permanent RAM block
          condition related function.
* Cause: Bugfix
********************************************************************************
* Version: 2.2
* Author/Date: Baowanglong/2019.12.16
* Change: Modify the error detection function of the NvM_RestorePRAMBlockDefaults function
*         to NvM_Chk_RestorePRAMBlockDefaults_Condition.
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date: Baowanglong/2020.02.17
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: Hanbaiyu/2020.03.17
* Change: Modify the API configuration class judgment conditions.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: Hanbaiyu/2020.05.07
* Change: Modify the switching operation of single/multi-block jobs in NvM_MainFunction.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: Hanbaiyu/2020.07.15
* Change: Modify the problem that array out of bounds caused by not check blockid
*         range in advance for multiple functions.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: Hanbaiyu/2020.10.27
* Change: Delete redundant assignments.
* Cause: QAC.
********************************************************************************
* Version: 3.6
* Author/Date: HanBY/2020.11.02
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: HanBY/2020.11.04
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: HanBY/2020.11.09
* Change: Add the precompile of Det.h.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: HanBY/2020.11.27
* Change: Deleting Det header file contains.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: HanBY/2020.01.28
* Change: In order to prevent compilation errors caused by incorrect configuration
*         of the callback functions, modify the location of macro switchs.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: HanBY/2021.10.18
* Change: Modify the wrong type name from MVN_StatusType to NvM_Status_Type.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: HanBY/2021.10.27
* Change: Delete the header NvM_MemMap.h.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: LiDY/2023.02.28
* Change: For some chips, Dflash and Pflash cannot be written at the same time.
*         1.Add NvM_SetBlockServices and NvM_GetFeeOfQueueStatus API.
*         2.Read, write, erase and other operations cannot be requested,When
*           NvM_SetBlockServices pass parameters as ture.
*         3.Read, write, erase and other operations be performed,When
*           NvM_SetBlockServices pass parameters as flase.
*         4.Pflash cann write when NvM_GetFeeOfQueueStatus return complted.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: LiDY/2023.03.13
* Change: Add return ok for NvM_GetFeeOfQueueStatus function.
* Cause: Bugfix
********************************************************************************
* Version: 3.35
* Author/Date: WangLX/2023.10.07
* Change: Fix Compilation Warning.
* Cause: Optimization
********************************************************************************
* Version: 3.36
* Author/Date: WangLX/2024.01.16
* Change: Modify NvM_SetBlockServices and NvM_GetFeeOfQueueStatus API, Increase
*         calls to the Fee_SetModuleMode and Fee_GetModuleStopState API.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date: WangLX/2024.02.04
* Change: Modify NvM_StopServices variable to Local Variables.
* Cause: Optimization
********************************************************************************
* Version: 3.38
* Author/Date: WangLX/2024.02.28
* Change: Modify the label of the input parameter Ptrclass for NvM_WriteBlock.
* Cause: Optimization
********************************************************************************
* Version: 3.39
* Author/Date: WangLX/2024.07.31
* Change: Optimization function parameter check.
* Cause: Optimization
********************************************************************************
* Version: 3.40
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.41
* Author/Date: WangLX/2024.10.12
* Change: Fix the macro definition of Memmap in Local Variables.
* Cause: Bugfix
********************************************************************************
* Version: 3.42
* Author/Date: WangLX/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
* Cause: Update
********************************************************************************
* Version: 3.43
* Author/Date: ZengJX/2025.06.04
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.44
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.45
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.46
* Author/Date: ZengJX/2025.06.16
* Change: Modify the function NvM_CancelWriteAll and NvM_ValidateAll to notify BswM.
* Cause: Update
********************************************************************************
* Version: 3.47
* Author/Date: ZengJX/2025.06.23
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.48
* Author/Date: ZengJX/2025.08.01
* Change: Achieve the function that NvM_SetRamBlockStatus shall only work on
*         NVRAM blocks with NvMBlockUseSetRamBlockStatus enabled.
* Cause: Bugfix
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "NvM.h"
#include "Rte_NvM.h"
#include "NvM_Def.h"
#include "Dem.h"
#include "MemIf.h"
#include "SchM_NvM.h"
#include "NvM_Cbk.h"
#include "Crc.h"
#include "Nvm_UserBlock.h"
#include "common.h"
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

#if( NVM_STOP_SERVICES == STD_ON )
/* Read, write, erase and other operations Startup identification. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(boolean, NVM_VAR_INIT) NvM_StopServices = FALSE;
#endif

/* NVM module initialization is completed. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
static VAR(boolean, NVM_VAR_INIT) NVM_Init_Finish = FALSE;

#define NVM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

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
#define NVM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

static FUNC(boolean, NVM_CODE) NvM_ChkReadRamAddr
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
);
static FUNC(boolean, NVM_CODE) NvM_ChkWriteRamAddr
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
);
static FUNC(boolean, NVM_CODE) NvM_ChkPRamAddr
(
    NvM_BlockIdType BlockId,
    uint8** NvM_DestPtr
);
static FUNC(boolean, NVM_CODE) NvM_ChkRomAddr(NvM_BlockIdType BlockId);
static FUNC(uint8, NVM_CODE) NvM_GeneralCheck(NvM_BlockIdType BlockId);

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

/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
VAR(NvM_Status_Type, NVM_VAR_INIT) NvM_ModuleState = NVM_IDLE;              /* Current state information. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
VAR(Nvm_QueueProcss_st, NVM_VAR_INIT) NvM_QueueCrrntJob = {NVM_INIT_0};     /* Current job information. */
/* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_NvM_GlobalVariables" */
VAR(Nvm_QueueHeader_st, NVM_VAR_INIT) Nvm_QueueHeader = {NVM_INIT_0};       /* Current queue information. */

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
* Function Name: NvM_ChkReadRamAddr
*
* Explanation: Function to Check whether Block pointer is available.
*              (NvM private function)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        NvM_DestPtr: Pointer to the RAM data block.
*
* retval: TRUE: Block pointer is available.
*         FALSE: Block pointer is invalid.
********************************************************************************
*/
static FUNC(boolean, NVM_CODE) NvM_ChkReadRamAddr
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
)
{
    boolean rtrnValu = FALSE;

    /* The address sent by the upper layer is invalid. */
    if( NULL_PTR == NvM_DestPtr )
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Check private ram is valid or configured with callback function. */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" */
        if( (NvM_Block_Descriptor_Table[BlockId].RamAddr != NULL_PTR) ||
            (NvM_Block_Descriptor_Table[BlockId].NvMReadRamBlockFromNvCallback != NULL_PTR) )
        {
            rtrnValu = TRUE;
        }
    }
    else
    {
        rtrnValu = TRUE;    /* Valid address. */
    }

    return rtrnValu;
}

static FUNC(void, NVM_CODE) NvM_MemcopyRamAddr_Write
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
)
{
    const NvM_Block_Descriptor_Table_st *blockTab = &NvM_Block_Descriptor_Table[BlockId]; /* Get block definition of current job. */
    uint8* targetRamBlock = NvM_RamBlockArray[BlockId];
	uint32 blockLength_Lo = blockTab->RamBlockLengthCfg;

    cc_memcpy(targetRamBlock, (uint8*)NvM_DestPtr, blockLength_Lo);
    NvM_DestPtr = targetRamBlock;
}
static FUNC(Std_ReturnType, NVM_CODE) NvM_MemcopyRamAddr_Read
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint32 blockLength_Lo = 0;
    const NvM_Block_Descriptor_Table_st *blockTab = &NvM_Block_Descriptor_Table[BlockId]; /* Get block definition of current job. */
    uint8* targetRamBlock = NvM_RamBlockArray[BlockId];
    blockLength_Lo = blockTab->RamBlockLengthCfg;

    uint16 timer_count = 0;
	Std_ReturnType ReadReqResult_Lo = 0;
	
    do
    {
        NvM_MainFunction();
        Fee_MainFunction();
        Fls_MainFunction();
        NvM_GetErrorStatus(BlockId, &ReadReqResult_Lo);
        if(ReadReqResult_Lo != NVM_REQ_PENDING)
        {
            if(NvM_DestPtr != NULL_PTR)
            {
                cc_memcpy((uint8 *)NvM_DestPtr, targetRamBlock, blockLength_Lo);
            }
            rtrnValu = E_OK;
            break;
        }
        timer_count++;
    }while(timer_count < 50);

    return rtrnValu;
}
/*
********************************************************************************
* Function Name: NvM_ChkWriteRamAddr
*
* Explanation: Function to Check whether Block pointer is available.
*              (NvM private function)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        NvM_DestPtr: Pointer to the RAM data block.
*
* retval: TRUE: Block pointer is available.
*         FALSE: Block pointer is invalid.
********************************************************************************
*/
static FUNC(boolean, NVM_CODE) NvM_ChkWriteRamAddr
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
)
{
    boolean rtrnValu = FALSE;

    /* The address sent by the upper layer is invalid. */
    if( NULL_PTR == NvM_DestPtr )
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        /* Check private ram is valid or configured with callback function. */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" */
        if( (NvM_Block_Descriptor_Table[BlockId].RamAddr != NULL_PTR) ||
            (NvM_Block_Descriptor_Table[BlockId].NvMWriteRamBlockToNvCallback != NULL_PTR) )
        {
            rtrnValu = TRUE;
        }
    }
    else
    {
        NvM_MemcopyRamAddr_Write(BlockId, NvM_DestPtr);
        rtrnValu = TRUE;    /* Valid address. */
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_ChkPRamAddr
*
* Explanation: This service Check whether Block pointer is available.
*              (NvM private function)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor. A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        NvM_DestPtr: Pointer to a pointer to the RAM data block.
*
* retval: TRUE: Block pointer is available.
*         FALSE: Block pointer is invalid.
********************************************************************************
*/
static FUNC(boolean, NVM_CODE) NvM_ChkPRamAddr
(
    NvM_BlockIdType BlockId,
    uint8** NvM_DestPtr
)
{
    Std_ReturnType rtrnValu = FALSE;

    /* Check private ram is valid. */
    /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" */
    if( NvM_Block_Descriptor_Table[BlockId].RamAddr != NULL_PTR )
    {
        /* Get private ram address. */
        *NvM_DestPtr = NvM_Block_Descriptor_Table[BlockId].RamAddr;
        rtrnValu = TRUE;
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_ChkRomAddr
*
* Explanation: This service Check whether Block pointer is available.
*              (NvM private function)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor. A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*
* retval: TRUE: Block pointer is available.
*         FALSE: Block pointer is invalid.
********************************************************************************
*/
static FUNC(boolean, NVM_CODE) NvM_ChkRomAddr(NvM_BlockIdType BlockId)
{
    boolean rtrnValu = FALSE;

    /* Check whether initial values are configured. */
    /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" */
    if( (NvM_Block_Descriptor_Table[BlockId].RomAddr != NULL_PTR) ||
        (NvM_Block_Descriptor_Table[BlockId].NvMInitBlockCallback != NULL_PTR) )
    {
        rtrnValu = TRUE;
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_GeneralCheck
*
* Explanation: Function to check if initialization is completed,
*              ID is in the range, whether the block's current Error state
*              is pending.
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*
* retval: NVM_E_NOT_INITIALIZED: Not yet initialized.
*         NVM_E_PARAM_BLOCK_ID: BlockId is invalid
*         NVM_E_BLOCK_PENDING: Block is pending.
********************************************************************************
*/
static FUNC(uint8, NVM_CODE) NvM_GeneralCheck(NvM_BlockIdType BlockId)
{
    uint8 chkResult = NVM_E_NO_ERR;

    /* Check if initialization is completed. */
    if( FALSE == NVM_Init_Finish )
    {
        chkResult = NVM_E_NOT_INITIALIZED;
    }
    /* Check if ID is in the range. */
    else if( BlockId >= NVM_NUM_OF_BLOCK_TOTAL )
    {
        chkResult = NVM_E_PARAM_BLOCK_ID;
    }
    /* Check whether the block's current Error state is pending. */
    else if( (NVM_REQ_PENDING == NvM_gstaBlockVar[BlockId].NvRamErrStatus) )
    {
        chkResult = NVM_E_BLOCK_PENDING;
    }
    else
    {
        /* Do nothing. */
    }

    return chkResult;
}
#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_SetDataIndex
*
* Explanation: Service for setting the DataIndex of a dataset NVRAM block.
*              (Synchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        DataIndex: Index position (association) of a NV/ROM block.
*
* retval: E_OK: The index position was set successfully.
*         E_NOT_OK: An error occurred.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex
(
    NvM_BlockIdType BlockId,
    uint8 DataIndex
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check if index is in the range. */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" */
        if( DataIndex > ((uint16)NvM_Block_Descriptor_Table[locBlockId].NvBlockNum +
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            (uint16)NvM_Block_Descriptor_Table[locBlockId].RomBlockNum) )
        {
            chkResult = NVM_E_PARAM_BLOCK_DATA_IDX;
        }
        else
        {
            /* Get block definition of current job. */
            blockTab = &NvM_Block_Descriptor_Table[locBlockId];
            if( NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType )
            {
                /* Set the new index to the corresponding block. */
                NvM_gstaBlockVar[locBlockId].DataIndex = DataIndex;
                rtrnValu = E_OK;
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    /* Error detected. */
    if( chkResult != NVM_E_NO_ERR )
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_SET_DATA_INDEX, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_GetDataIndex
*
* Explanation: Service for getting the currently set DataIndex of a dataset NVRAM
*               block.(Synchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        DataIndexPtr: Pointer to where to store the current dataset index
*                      (0..255)
*
* retval: E_OK: The index position has been retrieved successfully.
*         E_NOT_OK: An error occurred.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetDataIndex
(
    NvM_BlockIdType BlockId,
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    const NvM_Block_Descriptor_Table_st *blockTab;

    locBlockId = BlockId;           /* Copy BlockId to local variable. */
    /* Check whether pointer parameter is null pointer. */
    if( NULL_PTR == DataIndexPtr )
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkResult = NVM_E_PARAM_DATA;
    }
    /* Check if initialization is completed. */
    else if( FALSE == NVM_Init_Finish )
    {
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NvM_UseOfTaintedPointer" */
        *DataIndexPtr = NVM_INIT_0;
        chkResult = NVM_E_NOT_INITIALIZED;
    }
    /* Check if ID is in the range. */
    else if( locBlockId > NVM_NUM_OF_BLOCK_TOTAL )
    {
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NvM_UseOfTaintedPointer" */
        *DataIndexPtr = NVM_INIT_0;
        chkResult = NVM_E_PARAM_BLOCK_ID;
    }
    else
    {
        /* Get block definition of current job. */
        blockTab = &NvM_Block_Descriptor_Table[locBlockId];
        /* No errors occurred. */
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:IDP [JUstified:Unset] "NSCA_Polyspace_Dem_IllegallyDereferencedPointer" */
        if( NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType )
        {
            /* Get the current index from the corresponding block. */
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NvM_UseOfTaintedPointer" */
            *DataIndexPtr = NvM_gstaBlockVar[locBlockId].DataIndex;
            rtrnValu = E_OK;
        }
        else
        {
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NvM_UseOfTaintedPointer" */
            *DataIndexPtr = NVM_INIT_0;
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_GET_DATA_INDEX, chkResult);
    }
#else
    NVM_DUMMY_STATEMENT(chkResult);
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_3 )
/*
********************************************************************************
* Function Name: NvM_SetBlockProtection
*
* Explanation: Service for setting/resetting the write protection for a NV
*              block.(Synchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        ProtectionEnabled: TRUE: Write protection shall be enabled.
*                           FALSE: Write protection shall be disabled.
*
* retval: E_OK: The block was enabled/disabled as requested.
*         E_NOT_OK: An error occurred.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockProtection
(
    NvM_BlockIdType BlockId,
    boolean ProtectionEnabled
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    boolean locProtectionEnabled;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* Copy ProtectionEnabled to local. */
    locProtectionEnabled = ProtectionEnabled;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* check whether Block is configured to write once. */
        /* Polyspace +2 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
        if( NVM_WRITE_BLOCK_ONCE_ON ==
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            NvM_Block_Descriptor_Table[locBlockId].WriteBlockOnce )
        {
            chkResult = NVM_E_BLOCK_CONFIG;
        }
        /* Check if block is locked. */
        else if( NVM_BLOCK_LOCKED ==
            (NvM_gstaBlockVar[locBlockId].NvRamState & NVM_BLOCK_LOCKED) )
        {
            chkResult = NVM_E_BLOCK_LOCKED;
        }
        else
        {
            /* Get Block managment struct adddress. */
            blockMngmnt  = &NvM_gstaBlockVar[locBlockId];
            if( TRUE == locProtectionEnabled )
            {
                /* Enable Nv block protection. */
                blockMngmnt->NvRamState |= NVM_BLOCK_PRTCT_ON;
            }
            else
            {
                /* Disable Nv block protection. */
                blockMngmnt->NvRamState &= NVM_BLOCK_PRTCT_OFF;
            }
            rtrnValu = E_OK;
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR )     /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_SET_BLOCK_PROTECTION, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

/*
********************************************************************************
* Function Name: NvM_GetErrorStatus
*
* Explanation: Service to read the block dependent error/status information.
*              (Synchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        RequestResultPtr: Pointer to where to store the request result.
*
* retval: E_OK: The block dependent error/status information was read
*               successfully.
*         E_NOT_OK: An error occurred.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
    NvM_BlockIdType BlockId,
    P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;

    locBlockId = BlockId;   /* Copy BlockId to local variable. */
    /* Check if initialization is completed. */
    if( FALSE == NVM_Init_Finish )
    {
        chkResult = NVM_E_NOT_INITIALIZED;
    }
    /* Check if ID is in the range, "0" for multiple blocks' status */
    else if( locBlockId >= NVM_NUM_OF_BLOCK_TOTAL )
    {
        chkResult = NVM_E_PARAM_BLOCK_ID;
    }
    /* Check whether pointer parameter is null pointer. */
    else if( NULL_PTR == RequestResultPtr )
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        chkResult = NVM_E_PARAM_DATA;
    }
    else
    {
        /* Check whether the block's current Error state is pending. */
        if( NVM_REQ_PENDING == NvM_gstaBlockVar[locBlockId].NvRamErrStatus )
        {
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NvM_UseOfTaintedPointer" */
            *RequestResultPtr = NVM_REQ_PENDING;
        }
        else
        {
            /* Get Block managment struct adddress. */
            blockMngmnt = &NvM_gstaBlockVar[locBlockId];
            /* Get Ram block status. */
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NvM_UseOfTaintedPointer" */
            *RequestResultPtr = blockMngmnt->NvRamErrStatus;
        }
        rtrnValu = E_OK;
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR )     /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_GET_ERROR_STASUS, chkResult);
    }
#else
        NVM_DUMMY_STATEMENT(chkResult);
#endif

    return rtrnValu;
}

#if ( NVM_SET_RAM_BLOCK_STATUS_API == STD_ON )
/*
********************************************************************************
* Function Name: NvM_SetRamBlockStatus
*
* Explanation: Service for setting the RAM block status of an NVRAM block.
*              (Synchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        BlockChanged: TRUE: Validate the RAM block and mark block as changed.
*                      FALSE: Invalidate the RAM block and mark block as
*                             unchanged.
*
* retval: E_OK: The status of the RAM-Block was changed as requested.
*         E_NOT_OK: An error occurred.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus
(
    NvM_BlockIdType BlockId,
    boolean BlockChanged
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    boolean locBlockChanged;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* Copy BlockChanged to local. */
    locBlockChanged = BlockChanged;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check if block is locked. */
        /* Polyspace +2 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
        if( NVM_BLOCK_LOCKED ==
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            (NvM_gstaBlockVar[locBlockId].NvRamState & NVM_BLOCK_LOCKED) )
        {
            chkResult = NVM_E_BLOCK_LOCKED;
        }
        else
        {
            /* Get block definition of current job. */
            blockTab = &NvM_Block_Descriptor_Table[locBlockId];
            blockMngmnt = &NvM_gstaBlockVar[locBlockId];
            /* NvMSetRamBlockStatusApi and permanent ram is used. */
            if( (NVM_BLOCK_SETBLOCKSTATUS_ON == blockTab->UseSetRamBlockStatus) &&
                ((NVM_BLOCK_USE_SYNC_MECHANISM_ON == blockTab->SyncMechanism) ||
                  (blockTab->RamAddr != NULL_PTR)) )
            {
                /* Get Block managment struct adddress. */
                if( TRUE == locBlockChanged )
                {
                    /* Validate the RAM block and mark block as changed. */
                    blockMngmnt->NvRamState |= (NVM_BLOCK_VALID | NVM_BLOCK_CHANGED);
                }
                else
                {
                    /* Invalidate the RAM block and mark block as unchanged. */
                    blockMngmnt->NvRamState &= (NVM_BLOCK_INVALID & NVM_BLOCK_UNCHANGED);
                }
                rtrnValu = E_OK;
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
        if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
        {
            /* Report ErrorId to Det. */
            NVM_Det_ErrorReport(NVM_SET_RAM_BLOCK_STATUS, chkResult);
        }
#endif

    return rtrnValu;
}
#endif

/*
********************************************************************************
* Function Name: NvM_SetBlockLockStatus
*
* Explanation: Service for setting the lock status of a permanent RAM block or
*              of the explicitsynchronization of a NVRAM block.(Synchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        BlockLocked: TRUE: Mark the RAM.block as locked.
*                     FALSE: Mark the RAM.block as unlocked.
*
* retval: void
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_SetBlockLockStatus(NvM_BlockIdType BlockId, boolean BlockLocked)
{
    boolean locBlockChanged;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* Copy BlockLocked to local. */
    locBlockChanged = BlockLocked;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* check whether Block is configured to write once. */
        /* Polyspace +2 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
        if( NVM_WRITE_BLOCK_ONCE_ON ==
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            NvM_Block_Descriptor_Table[locBlockId].WriteBlockOnce )
        {
            chkResult = NVM_E_BLOCK_CONFIG;
        }
        else
        {
            /* Get Block managment struct adddress. */
            blockMngmnt = &NvM_gstaBlockVar[locBlockId];
            /* Get block definition of current job. */
            blockTab = &NvM_Block_Descriptor_Table[locBlockId];
            if( (NVM_BLOCK_USE_SYNC_MECHANISM_ON == blockTab->SyncMechanism) || (blockTab->RamAddr != NULL_PTR) )
            {
                if( TRUE == locBlockChanged )
                {
                    /* Mark the RAM.block as locked. */
                    blockMngmnt->NvRamState |= NVM_BLOCK_LOCKED;
                }
                else
                {
                    /* Mark the RAM.block as unlocked. */
                    blockMngmnt->NvRamState &= NVM_BLOCK_UNLOCKED;
                }
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_SET_BLOCK_LOCK_STATUS, chkResult);
    }
#endif
}

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_ReadBlock
*
* Explanation: Service to copy the data of the NV block to its corresponding
*              RAM block.(Asynchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        NvM_DstPtr: Pointer to the RAM data block.
*
* retval: E_OK: request has been accepted.
*         E_NOT_OK: request has not been accepted.
********************************************************************************
*/
uint8 NvM_Sart_Flag = 0;
void NvM_ReadAll_Finish_Flag(uint8 Finish_Flag)
{
    NvM_Sart_Flag = Finish_Flag;
}
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock
(
    NvM_BlockIdType BlockId,
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr    /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    if( NvM_Sart_Flag == 0 )
    {
        chkResult = NVM_E_NOT_INITIALIZED;
    }
    /* Check the ReadBlock conditions. */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check whether pointer parameter is null pointer. */
        if( FALSE == NvM_ChkReadRamAddr(locBlockId, NvM_DstPtr) )
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            chkResult = NVM_E_PARAM_ADDRESS;
        }
        else
        {
#if( NVM_STOP_SERVICES == STD_ON )
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            if( (FALSE == NvM_StopServices) || (NVM_EA_DEVICEID == NvM_Block_Descriptor_Table[locBlockId].DeviceId) )
#endif
            {
                /* Queue processing the read Block request. */
                rtrnValu = NvM_QueueProcess(locBlockId, NvM_DstPtr, NVM_READ_BLOCK);
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR )  /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_READ_BLOCK, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_WriteBlock
*
* Explanation: Service to copy the data of the RAM block to its corresponding
*              NV block.(Asynchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        NvM_SrcPtr: Pointer to the RAM data block.
*
* retval: E_OK: request has been accepted.
*         E_NOT_OK: request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    if( NvM_Sart_Flag == 0 )
    {
        chkResult = NVM_E_NOT_INITIALIZED;
    }
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check whether pointer parameter is null pointer. */
        if( FALSE == NvM_ChkWriteRamAddr(locBlockId, NvM_SrcPtr) )
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            chkResult = NVM_E_PARAM_ADDRESS;
        }
        /* Check if block is locked. */
        /* Polyspace +2 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
        else if( NVM_BLOCK_LOCKED ==
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            (NvM_gstaBlockVar[locBlockId].NvRamState & NVM_BLOCK_LOCKED) )
        {
            chkResult = NVM_E_BLOCK_LOCKED;
        }
        else
        {
#if( NVM_STOP_SERVICES == STD_ON )
            if( (FALSE == NvM_StopServices) || (NVM_EA_DEVICEID == NvM_Block_Descriptor_Table[locBlockId].DeviceId) )
#endif
            {
                blockMngmnt = &NvM_gstaBlockVar[locBlockId];        /* Get block management of current job. */
                blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */

                /* Check the write protection. */
                if( NVM_BLOCK_PRTCT_ON == (blockMngmnt->NvRamState & NVM_BLOCK_PRTCT_ON) )
                {
                    rtrnValu = E_NOT_OK; /* this block is protected. */
                }
                /* Check if dataset point the rom. */
                else if( (NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType) &&
                    (blockMngmnt->DataIndex >= blockTab->NvBlockNum) )
                {
                    rtrnValu = E_NOT_OK;
                }
                /* Check the WriteBlock conditions. */
                else
                {
                    /* Queue processing the write Block request. */
                    rtrnValu = NvM_QueueProcess(locBlockId, NvM_SrcPtr, NVM_WRITE_BLOCK);
                }
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_WRITE_BLOCK, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_RestoreBlockDefaults
*
* Explanation: Service to restore the default data to its corresponding RAM
               block.(Asynchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*        NvM_DestPtr: Pointer to the RAM data block.
*
* retval: E_OK: request has been accepted.
*         E_NOT_OK: request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults
(
    NvM_BlockIdType BlockId,
    /* PolySpace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr   /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check whether pointer parameter is null pointer. */
        if( FALSE == NvM_ChkReadRamAddr(locBlockId, NvM_DestPtr) )
        /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            chkResult = NVM_E_PARAM_ADDRESS;
        }
        /* Check if Ram Block buffer pointer is Null. */
        else if( FALSE == NvM_ChkRomAddr(locBlockId) )
        {
            chkResult = NVM_E_BLOCK_CONFIG;
        }
        else
        {
            blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
            blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */

            /* Check the data index for block type of DATASET and the index is ponits to nv block. */
            if( (NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType)
                && (blockMngmnt->DataIndex < blockTab->NvBlockNum) )
            {
                rtrnValu = E_NOT_OK;
            }
            /* Check if rom or initcallback is avaliable. */
            else if( ((blockTab->RomAddr != NULL_PTR) && (blockTab->RomBlockNum != NVM_INIT_0)) ||
                    (blockTab->NvMInitBlockCallback != NULL_PTR) )
            {
                /* Queue processing the restore Block request. */
                rtrnValu = NvM_QueueProcess(locBlockId, NvM_DestPtr, NVM_RESTORE_BLOCK_DEFAULTS);
            }
            else
            {
                /* Do nothing. */
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_RESTORE_BLOCK_DEFAULTS, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_3 )
/*
********************************************************************************
* Function Name: NvM_EraseNvBlock
*
* Explanation: Service to erase a NV block.(Asynchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*
* retval: E_OK: request has been accepted.
*         E_NOT_OK: request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check whether the priority of configuration is immediate. */
        /* Polyspace +2 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
        if( NVM_IMMEDIATE_PRIORITY !=
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            NvM_Block_Descriptor_Table[locBlockId].JobPriority )
        {
            chkResult = NVM_E_BLOCK_CONFIG;
        }
        /* Check if block is locked. */
        else if( NVM_BLOCK_LOCKED ==
            (NvM_gstaBlockVar[locBlockId].NvRamState & NVM_BLOCK_LOCKED) )
        {
            chkResult = NVM_E_BLOCK_LOCKED;
        }
        else
        {

#if( NVM_STOP_SERVICES == STD_ON )
            if( (FALSE == NvM_StopServices) || (NVM_EA_DEVICEID == NvM_Block_Descriptor_Table[locBlockId].DeviceId) )
#endif
            {
                blockMngmnt = &NvM_gstaBlockVar[locBlockId];        /* Get block management of current job. */
                blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
                /* Check the write protection. */
                if( NVM_BLOCK_PRTCT_ON == (blockMngmnt->NvRamState & NVM_BLOCK_PRTCT_ON) )
                {
                    rtrnValu = E_NOT_OK; /* this block is protected. */
                }
                /* Check if dataset point the rom. */
                else if( (NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType) &&
                    (blockMngmnt->DataIndex >= blockTab->NvBlockNum) )
                {
                    rtrnValu = E_NOT_OK;
                }
                else
                {
                    /* Queue processing the rease Block request. */
                    rtrnValu = NvM_QueueProcess(locBlockId, NULL_PTR, NVM_ERASE_NV_BLOCK);
                }
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_ERASE_NV_BLOCK, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_3 )
/*
********************************************************************************
* Function Name: NvM_InvalidateNvBlock
*
* Explanation: Service to invalidate a NV block.(Asynchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*
* retval: E_OK: request has been accepted.
*         E_NOT_OK: request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check if block is locked. */
        /* Polyspace +2 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
        if( NVM_BLOCK_LOCKED ==
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            (NvM_gstaBlockVar[locBlockId].NvRamState & NVM_BLOCK_LOCKED) )
        {
            chkResult = NVM_E_BLOCK_LOCKED;
        }
        else
        {

#if( NVM_STOP_SERVICES == STD_ON )
            if( (FALSE == NvM_StopServices) || (NVM_EA_DEVICEID == NvM_Block_Descriptor_Table[locBlockId].DeviceId) )
#endif
            {
                blockMngmnt = &NvM_gstaBlockVar[locBlockId];        /* Get block management of current job. */
                blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
                /* Check the write protection. */
                if( NVM_BLOCK_PRTCT_ON == (blockMngmnt->NvRamState & NVM_BLOCK_PRTCT_ON) )
                {
                    rtrnValu = E_NOT_OK; /* this block is protected. */
                }
                /* Check if dataset point the rom. */
                else if( (NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType) &&
                         (blockMngmnt->DataIndex >= blockTab->NvBlockNum) )
                {
                    rtrnValu = E_NOT_OK;
                }
                else
                {
                    /* Queue processing the read Block request. */
                   rtrnValu = NvM_QueueProcess(locBlockId, NULL_PTR,
                                            NVM_INVALIDATE_NV_BLOCK);
                }
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_INVALIDATE_NV_BLOCK, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_CancelJobs
*
* Explanation: Service to cancel all jobs pending for a NV block.(Synchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*
* retval: E_OK: The job was successfully removed from queue.
*         E_NOT_OK: The job could not be found in the queue.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs(NvM_BlockIdType BlockId)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* Check if initialization is completed. */
    if( FALSE == NVM_Init_Finish )
    {
        chkResult = NVM_E_NOT_INITIALIZED;
    }
    /* Check if ID is in the range. */
    else if( locBlockId >= NVM_NUM_OF_BLOCK_TOTAL )
    {
        chkResult = NVM_E_PARAM_BLOCK_ID;
    }
    else
    {
        /* Remove the BlocId form queue. */
        rtrnValu = NvM_CancelQueueProcess(locBlockId);
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_CANCEL_JOBS, chkResult);
    }
#else
        NVM_DUMMY_STATEMENT(chkResult);
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_ReadPRAMBlock
*
* Explanation: Service to copy the data of the NV block to its corresponding
*              permanent RAM block.(Asynchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*
* retval: E_OK: request has been accepted.
*         E_NOT_OK: request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    uint8* dstPtr = NULL_PTR;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check if Ram Block buffer pointer is Null. */
        if( FALSE == NvM_ChkPRamAddr(locBlockId, &dstPtr) )
        {
            chkResult = NVM_E_PARAM_ADDRESS;
        }
        /* Check if block is locked. */
        /* Polyspace +2 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
        else if( NVM_BLOCK_LOCKED ==
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            (NvM_gstaBlockVar[locBlockId].NvRamState & NVM_BLOCK_LOCKED) )
        {
            chkResult = NVM_E_BLOCK_LOCKED;
        }
        else
        {

#if( NVM_STOP_SERVICES == STD_ON )
            if( (FALSE == NvM_StopServices) || (NVM_EA_DEVICEID == NvM_Block_Descriptor_Table[locBlockId].DeviceId) )
#endif
            {
                /* Queue processing the read Block request. */
                rtrnValu = NvM_QueueProcess(locBlockId, dstPtr, NVM_READ_BLOCK);
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_READ_PRAM_BLOCK, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_WritePRAMBlock
*
* Explanation: Service to copy the data of the RAM block to its corresponding
*               permanent RAM block.(Asynchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*
* retval: E_OK: request has been accepted.
*         E_NOT_OK: request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    uint8* dstPtr = NULL_PTR;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check if Ram Block buffer pointer is Null. */
        if( FALSE == NvM_ChkPRamAddr(locBlockId, &dstPtr) )
        {
            chkResult = NVM_E_PARAM_ADDRESS;
        }
        /* Check if block is locked. */
        /* Polyspace +2 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
        else if( NVM_BLOCK_LOCKED ==
            /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            (NvM_gstaBlockVar[locBlockId].NvRamState & NVM_BLOCK_LOCKED) )
        {
            chkResult = NVM_E_BLOCK_LOCKED;
        }
        else
        {

#if( NVM_STOP_SERVICES == STD_ON )
            if( (FALSE == NvM_StopServices) || (NVM_EA_DEVICEID == NvM_Block_Descriptor_Table[locBlockId].DeviceId) )
#endif
            {
                blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
                blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
                /* Check the write protection */
                if( NVM_BLOCK_PRTCT_ON == (blockMngmnt->NvRamState & NVM_BLOCK_PRTCT_ON) )
                {
                    rtrnValu = E_NOT_OK;    /* this block is protected. */
                }
                /* Check if dataset point the rom. */
                else if( (NVM_BLOCK_MANAGENMENT_DATASET == blockTab->ManagementType) &&
                    (blockMngmnt->DataIndex >= blockTab->NvBlockNum) )
                {
                    rtrnValu = E_NOT_OK;
                }
                else
                {
                    /* Queue processing the write Block request. */
                    rtrnValu = NvM_QueueProcess(locBlockId, dstPtr, NVM_WRITE_BLOCK);
                }
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_WRITE_PRAM_BLOCK, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_RestorePRAMBlockDefaults
*
* Explanation: Service to restore the default data to its corresponding permanent
*              RAM block.(Asynchronous)
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block
*                 descriptor.A NVRAM block descriptor contains all needed
*                 information about a single NVRAM block.
*
* retval: E_OK: request has been accepted.
*         E_NOT_OK: request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaults(NvM_BlockIdType BlockId)
{
    Std_ReturnType rtrnValu = E_NOT_OK;
    uint8 chkResult = NVM_E_NO_ERR;
    uint16 locBlockId;
    uint8* dstPtr = NULL_PTR;
    Nvm_BlockManagment_st *blockMngmnt;
    const NvM_Block_Descriptor_Table_st *blockTab;

    /* Copy BlockId to local. */
    locBlockId = BlockId;
    /* General check */
    chkResult = NvM_GeneralCheck(locBlockId);
    if( NVM_E_NO_ERR == chkResult )
    {
        /* Check if Ram Block buffer pointer is Null. */
        if( FALSE == NvM_ChkPRamAddr(locBlockId, &dstPtr) )
        {
            chkResult = NVM_E_PARAM_ADDRESS;
        }
       /* Check if Ram Block buffer pointer is Null. */
        else if( FALSE == NvM_ChkRomAddr(locBlockId) )
        {
            chkResult = NVM_E_BLOCK_CONFIG;
        }
        else
        {
            blockMngmnt = &NvM_gstaBlockVar[locBlockId];    /* Get block management of current job. */
            blockTab = &NvM_Block_Descriptor_Table[locBlockId]; /* Get block definition of current job. */
            /* Check the data index for block type of DATASET and the index is ponits to nv block. */
            if( (blockTab->ManagementType == NVM_BLOCK_MANAGENMENT_DATASET)
                && (blockMngmnt->DataIndex < blockTab->NvBlockNum) )
            {
                rtrnValu = E_NOT_OK;
            }
            /* Check if rom or initcallback is avaliable. */
            else if( ((blockTab->RomAddr != NULL_PTR) && (blockTab->RomBlockNum != NVM_INIT_0)) ||
                    (blockTab->NvMInitBlockCallback != NULL_PTR) )
            {
                /* Queue processing the restore Block request. */
                rtrnValu = NvM_QueueProcess(locBlockId, dstPtr,
                                                        NVM_RESTORE_BLOCK_DEFAULTS);
            }
            else
            {
                /* Do nothing. */
            }
        }
    }

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
    if( chkResult != NVM_E_NO_ERR ) /* Error detected. */
    {
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_RESTORE_PRAM_BLOCK_DEFAULTS, chkResult);
    }
#endif

    return rtrnValu;
}
#endif

/*
********************************************************************************
* Function Name: NvM_ReadAll
*
* Explanation: Initiates a multi block read request.(Asynchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_ReadAll(void)
{
    /* Check if initialization is completed. */
    if( FALSE == NVM_Init_Finish )
    {

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_READ_ALL, NVM_E_NOT_INITIALIZED);
#endif

    }
    else
    {
#if( NVM_STOP_SERVICES == STD_ON )
        if( FALSE == NvM_StopServices )
#endif
        {
            /* Check if there is no multi block request currently. */
            if( (NVM_INIT_0 == (NvM_QueueCrrntJob.MultiBlockReq & NVM_BLOCK_MULTIREQUESTALL)) )
            {
                /* Get the readall qequest. */
                NvM_QueueCrrntJob.MultiBlockReq |= NVM_BLOCK_READALL_SET;
                /* Set block0 status to pending. */
                NvM_gstaBlockVar[NVM_BLOCK_RESERVEID].NvRamErrStatus = NVM_REQ_PENDING;

#if( NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON )
                /* Notice bswm of mutli service id and status currently processed. */
                BswM_NvM_CurrentJobMode(NVM_READ_ALL, NVM_REQ_PENDING);
#endif /* NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON */
            }
        }
    }
}

/*
********************************************************************************
* Function Name: NvM_WriteAll
*
* Explanation: Initiates a multi block write request.(Asynchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_WriteAll(void)
{
    /* Check if initialization is completed. */
    if( FALSE == NVM_Init_Finish )
    {

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_WRITE_ALL, NVM_E_NOT_INITIALIZED);
#endif

    }
    else
    {
#if( NVM_STOP_SERVICES == STD_ON )
        if( FALSE == NvM_StopServices )
#endif
        {
            /* Check if there is no multi block request currently. */
            if( (NVM_INIT_0 == (NvM_QueueCrrntJob.MultiBlockReq & NVM_BLOCK_MULTIREQUESTALL)) )
            {
                /* Get the writeall qequest. */
                NvM_QueueCrrntJob.MultiBlockReq |= NVM_BLOCK_WRITEALL_SET;
                /* Set block0 status to pending. */
                NvM_gstaBlockVar[NVM_BLOCK_RESERVEID].NvRamErrStatus = NVM_REQ_PENDING;

#if( NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON )
                /* Notice bswm of mutli service id and status currently processed. */
                BswM_NvM_CurrentJobMode(NVM_WRITE_ALL, NVM_REQ_PENDING);
#endif /* NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON */
            }
        }
    }
}

/*
********************************************************************************
* Function Name: NvM_CancelWriteAll
*
* Explanation: Service to cancel a running NvM_WriteAll request.(Asynchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_CancelWriteAll(void)
{
    /* Check if initialization is completed. */
    if( FALSE == NVM_Init_Finish )
    {

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_CANCEL_WRITE_ALL, NVM_E_NOT_INITIALIZED);
#endif

    }
    else
    {
        /* Check if there is no multi block request currently. */
        if( ((NvM_QueueCrrntJob.MultiBlockReq & NVM_BLOCK_WRITEALL_SET) > NVM_INIT_0) )
        {
            /* Get the writeall qequest. */
            NvM_QueueCrrntJob.MultiBlockReq |= NVM_BLOCK_CANCEL_WRITEALL_SET;
            /* Set block0 status to pending. */
            NvM_gstaBlockVar[NVM_BLOCK_RESERVEID].NvRamErrStatus = NVM_REQ_PENDING;

#if( NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON )
            /* Notice bswm of mutli service id and status currently processed. */
            BswM_NvM_CurrentJobMode(NVM_CANCEL_WRITE_ALL, NVM_REQ_PENDING);
#endif /* NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON */
        }
    }
}

#if ( NVM_API_CONFIG_CLASS >= NVM_API_CONFIG_CLASS_2 )
/*
********************************************************************************
* Function Name: NvM_ValidateAll
*
* Explanation: Initiates a multi block validation request.(Asynchronous)
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_ValidateAll(void)
{
    /* Check if initialization is completed. */
    if( FALSE == NVM_Init_Finish )
    {

#if( NVM_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_VALIDATE_ALL, NVM_E_NOT_INITIALIZED);
#endif

    }
    else
    {
#if( NVM_STOP_SERVICES == STD_ON )
        if( FALSE == NvM_StopServices )
#endif
        {
            /* Check if there is no multi block request currently. */
            if( (NVM_INIT_0 == (NvM_QueueCrrntJob.MultiBlockReq & NVM_BLOCK_MULTIREQUESTALL)) )
            {
                /* Get the writeall qequest. */
                NvM_QueueCrrntJob.MultiBlockReq |= NVM_BLOCK_VALIDATEALL_SET;
                /* Set block0 status to pending. */
                NvM_gstaBlockVar[NVM_BLOCK_RESERVEID].NvRamErrStatus = NVM_REQ_PENDING;

#if( NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON )
                /* Notice bswm of mutli service id and status currently processed. */
                BswM_NvM_CurrentJobMode(NVM_VALIDATE_ALL, NVM_REQ_PENDING);
#endif /* NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON */
            }
        }
    }
}
#endif

/*
********************************************************************************
* Function Name: NvM_Init
*
* Explanation: Service for resetting all internal variables.(Synchronous)
*
* param: ConfigPtr: Pointer to the selected configuration set.
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_Init
(
    P2CONST(NvM_ConfigType, AUTOMATIC, NVM_APPL_CONST) ConfigPtr
)
{
    NVM_DUMMY_STATEMENT(ConfigPtr);
    NVM_Init_BlockManagment();      /* Block managment init. */
    NVM_Init_CrrntJob();            /* Crrent job init. */
    NVM_Init_QueueJob();            /* Job queue init. */
    NVM_Init_Finish = TRUE;         /* Init finish flag. */
}

/*
********************************************************************************
* Function Name: NvM_JobEndNotification
*
* Explanation: Function to be used by the underlying memory abstraction to
*              signal end of job without error.(Synchronous)
*
* param: None
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_JobEndNotification(void)
{

#if ( NVM_POLLING_MODE == STD_OFF )
    /* End of job without error,Set result to OK. */
    NvM_QueueCrrntJob.JobResult = NVM_REQ_OK;
#endif /* NVM_POLLING_MODE == STD_OFF */

}

/*
********************************************************************************
* Function Name: NvM_JobErrorNotification
*
* Explanation: Function to be used by the underlying memory abstraction to
*              signal end of job with error.(Synchronous)
*
* param: None
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_JobErrorNotification(void)
{

#if ( NVM_POLLING_MODE == STD_OFF )
    uint8 locDeviceId = NVM_INIT_0;
    uint16 locBlockId = NVM_INIT_0;

    /* Get the BlockId that being processed. */
    locBlockId = NvM_QueueCrrntJob.CurBlockId;
    if( locBlockId < NVM_NUM_OF_BLOCK_TOTAL )    /* Valid BlockId. */
    {
        /* Get the BlockId that being processed. */
        locDeviceId = NvM_Block_Descriptor_Table[locBlockId].DeviceId;

        switch( MemIf_GetJobResult(locDeviceId) )
        {
            case MEMIF_BLOCK_INCONSISTENT:
                NvM_QueueCrrntJob.JobResult = NVM_REQ_INTEGRITY_FAILED;
                break;

            case MEMIF_BLOCK_INVALID:
                NvM_QueueCrrntJob.JobResult = NVM_REQ_NV_INVALIDATED;
                break;

            default:
                NvM_QueueCrrntJob.JobResult = NVM_REQ_NOT_OK;
                break;
        }
    }
#endif /* NVM_POLLING_MODE == STD_OFF */

}

#if( NVM_STOP_SERVICES == STD_ON )
/*
********************************************************************************
* Function Name: NvM_SetBlockServices
*
* Explanation: Read, write, erase and other operations cannot be performed or
*            can be performed,When NvM_SetBlockServices is called.
*
* param: stopServices:TRUE: Disable the read/write/erase service.
*                      FALSE: Enable read/write/erase service.
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_SetBlockServices(boolean stopServices)
{
    NvM_StopServices = stopServices;
    if( FALSE == stopServices )
    {
        Fee_SetModuleMode(FALSE);
    }
}

/*
********************************************************************************
* Function Name: NvM_GetFeeOfQueueStatus
*
* Explanation:Get Fee request completed or incomplete.
*
* param: RequestResultPtr: Fee request completed or incomplete.
*
* retval: E_OK: request has been accepted.
*         E_NOT_OK: request has not been accepted.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetFeeOfQueueStatus
(
    P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
)
{
    Std_ReturnType rtrnValu = E_NOT_OK;

    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( NULL_PTR != RequestResultPtr )
    {
        if( NVM_FEE_OF_QUEUE_EMPTY != Nvm_QueueHeader.FeeReqNum )
        {
            /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NvM_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
            *RequestResultPtr = NVM_REQ_NOT_COMPLTED;
        }
        else
        {
            if( TRUE == NvM_StopServices )
            {
                Fee_SetModuleMode(TRUE);
                if( E_OK == Fee_GetModuleStopState() )
                {
                    /* Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NvM_UseOfTaintedPointer" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
                    *RequestResultPtr = NVM_REQ_COMPLTED;
                }
            }
        }
        rtrnValu = E_OK;
    }
    return rtrnValu;
}
#endif /* NVM_STOP_SERVICES == STD_ON */

/*
********************************************************************************
* Function Name: NvM_MainFunction
*
* Explanation: Service for performing the processing of the NvM jobs.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_MainFunction(void)
{
    uint8 locMultiReq;

    locMultiReq = NvM_QueueCrrntJob.MultiBlockReq;

    /* Check if there is a single block request. */
    if( (Nvm_QueueHeader.Counter > NVM_INIT_0) )
    {
        /* Check if the module state is idle. */
        if( NVM_IDLE == NvM_ModuleState )
        {
            NvM_ModuleState = NVM_SINGLE;
        }
    }
    else
    {
        /* If the module status is single block and the request has been processed,
           the module is set to the idle state. */
        if( (NVM_SINGLE == NvM_ModuleState) && (NVM_STATEMACHINE_IDLE == NvM_SingleStateMachine) )
        {
            NvM_ModuleState = NVM_IDLE;
        }
        /* If the module status is idle and there are multi-block requests,
           the module is set to the multi-block state. */
        if( ((locMultiReq & NVM_BLOCK_MULTIREQUESTALL) > NVM_INIT_0)
             && (NVM_IDLE == NvM_ModuleState) )
        {
            NvM_ModuleState = NVM_MULTI;
        }
    }
    /* If the module status is single block and the request has been processed,
       the module is set to the idle state. */
    if( ( NVM_INIT_0 == (locMultiReq & NVM_BLOCK_MULTIREQUESTALL))
                  && (NVM_MULTI == NvM_ModuleState) )
    {
        NvM_ModuleState = NVM_IDLE;
    }

    /* Get multi block request to local. */
    NvM_MainFun_GetNewBlock();
    /* Check whether there is multi-block job to be done. */
    if( NVM_MULTI == NvM_ModuleState )
    {
        NvM_MainFun_MultiBlock();   /* Multi block processing. */
    }
    else if( NVM_SINGLE == NvM_ModuleState ) /* Check whether there is single block job to be done. */
    {
        NvM_MainFun_SingleBlock();  /* Single block processing. */
    }
    else
    {
        /* Do nothing. */
    }
}

#if ( NVM_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: NvM_GetVersionInfo
*
* Explanation: Service to get the version information of the NvM module.
*              (Synchronous)
*
* param: versioninfo:Pointer to where to store the version information of this
*        module.
*
* retval: None
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_DATA) versioninfo
)
{
    if( NULL_PTR == versioninfo )   /* Pointer parameter is Null. */
    /* Polyspace +1 RTE:UNR [JUstified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {

#if ( NVM_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        NVM_Det_ErrorReport(NVM_GET_VERSION_INFO, NVM_E_PARAM_POINTER);
#endif

    }
    else
    {
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_NvM_UseOfTaintedPointer" */
        versioninfo->vendorID = NVM_VENDOR_ID;
        versioninfo->moduleID = NVM_MODULE_ID;
        versioninfo->sw_major_version = NVM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = NVM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = NVM_SW_PATCH_VERSION;
    }
}
#endif

#define NVM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
