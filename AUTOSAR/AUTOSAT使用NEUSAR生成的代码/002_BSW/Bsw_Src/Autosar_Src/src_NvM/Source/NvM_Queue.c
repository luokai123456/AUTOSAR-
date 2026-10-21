/*
********************************************************************************
*
* File name: NvM_Queue.c
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
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangJipeng/2018.11.10
* Change: Fix function NvM_QueueProcess RemainNum check error.
* Cause: Bugfix
********************************************************************************
* Version: 2.1
* Author/Date: Baowanglong/2019.11.12
* Change: Modify the code format
* Cause: Coding Standards
********************************************************************************
* Version: 3.0
* Author/Date: Baowanglong/2020.02.17
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: Hanbaiyu/2020.03.27
* Change: 1.Initial value for indicator variable of for loop.
          2.Change type for locNvM_Ctrl from uint16 to uint8.
* Cause: QAC
********************************************************************************
* Version: 3.2
* Author/Date: Hanbaiyu/2020.05.07
* Change: Modify the job processing method according to priority.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: Hanbaiyu/2020.06.28
* Change: In the function NvM_QueueAddSort_ImmediateJob, Modify the judgment of
          maximum queue length.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
*         3. For NvM_QueueAddSort_ImmediateJob, put the same priority request in
*         the queue head.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: Hanbaiyu/2020.10.27
* Change: Delete redundant assignments.
* Cause: QAC.
********************************************************************************
* Version: 3.6
* Author/Date: HanBY/2020.11.04
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: HanBY/2020.12.08
* Change: Add judgment that only immediate counter greater than 0 to avoid decrease
*         immediate counter when priority queue is not enabled.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: HanBY/2020.12.24
* Change: In the function NvM_CancelQueueProcess, modify the question that can not
*         cancel request in the queue head and the queue header and tail information
*         were not updated.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: HanBY/2020.1.6
* Change: In the function NvM_CancelQueueProcess, modify the question that can not
*         update queue tail when queue length is one.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: HanBY/2021.06.30
* Change: Modify the title of function NvM_QueuePop.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: LiDY/2022.12.29
* Change: In the function NvM_QueueProcess,move the SchM_Exit_NVM_EXCLUSIVE_AREA
          interrupt function backwards
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: LiDY/2023.03.03
* Change: Add the function of counting the number of Fee devices in the queue.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: LiDY/2023.04.27
* Change: NVM_BLOCK_TOTAL_NUMBER change name to NVM_NUM_OF_BLOCK_TOTAL.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: WangLX/2024.04.01
* Change: Modify the label of the input parameter Ptrclass for NvM_QueueProcess
*         and NvM_ReQueueProcess.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: WangLX/2024.07.31
* Change: Optimization NvM_QueueProcess function pending check.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: WangLX/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: ZengJX/2025.06.04
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date: ZengJX/2025.06.23
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "NvM_Cfg.h"
#include "NvM_Queue.h"
#include "NvM.h"

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
#define NVM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
* Function Name: NvM_QueueAddSort_ImmediateJob
*
* Explanation: Function to sort the queue by priority.
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
*                 A NVRAM block descriptor contains all needed information about a
*                 single NVRAM block.
*        NvM_Ctrl: Indicates the current request type.
*
* retval: E_OK: Successful.
*         E_NOT_OK: Unsuccessful.
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.7" */
FUNC(uint8, NVM_CODE) NvM_QueueAddSort_ImmediateJob(uint16 BlockId, uint8 NvM_Ctrl)
{
    boolean flag = FALSE;
    uint8 rtrnValu = E_NOT_OK;
    uint16 blockSortId;
    uint16 nextId;
    uint16 loopBlockId;

    /* The enqueued block numbers have exceeded the queue length. */
    if( Nvm_QueueHeader.Counter >= NVM_SIZE_IMMEDIATE_JOB_QUEUE )
    {
        rtrnValu = E_NOT_OK;
    }
    else
    {
        /* The queue is empty. */
        if( NVM_QUEUE_CURRENTBLOCKID == Nvm_QueueHeader.FirstBlockId )
        {
            /* Set the block id to be the first be executed. */
            Nvm_QueueHeader.FirstBlockId = BlockId;
            Nvm_QueueHeader.LastBlockId = BlockId;
            rtrnValu = E_OK;
        }
        else
        {
            /* Record the next ID for priority comparison. */
            loopBlockId = Nvm_QueueHeader.FirstBlockId;
            /* Loop through the block in the queue */
            for( blockSortId = NVM_INIT_0; blockSortId < Nvm_QueueHeader.Counter; blockSortId++ )
            {
                /* If the priority of the block is less than the priority of the current block. */
                /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" */
                if( NvM_gstaBlockVar[BlockId].Priority >= NvM_gstaBlockVar[loopBlockId].Priority )
                {
                    /* If the block is the last one. */
                    if( NVM_QUEUE_NEXTBLOCKID == NvM_gstaBlockVar[loopBlockId].NxtBlockId )
                    {
                        /* Set this BlockID to next. */
                        NvM_gstaBlockVar[loopBlockId].NxtBlockId = BlockId;
                        Nvm_QueueHeader.LastBlockId = BlockId;
                        flag = TRUE;
                    }
                    else
                    {
                        /* Record the next ID for priority comparison. */
                        nextId = NvM_gstaBlockVar[loopBlockId].NxtBlockId;
                        /* If the priority of the block is greater than the priority of the current block. */
                        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
                        if( NvM_gstaBlockVar[BlockId].Priority <= NvM_gstaBlockVar[nextId].Priority )
                        {
                            /* Set this BlockID to next. */
                            NvM_gstaBlockVar[loopBlockId].NxtBlockId = BlockId;
                            /* Set original after this BlockID. */
                            NvM_gstaBlockVar[BlockId].NxtBlockId = nextId;
                            flag = TRUE;
                        }
                    }
                }
                else    /* The enqueued block is the highest priority. */
                {
                    NvM_gstaBlockVar[BlockId].NxtBlockId = Nvm_QueueHeader.FirstBlockId;
                    Nvm_QueueHeader.FirstBlockId = BlockId;
                    flag = TRUE;
                }
                /* Record the next ID for priority comparison. */
                loopBlockId = NvM_gstaBlockVar[loopBlockId].NxtBlockId;

                if( TRUE == flag )
                {
                    rtrnValu = E_OK;
                    break;
                }

            }
        }
        /* If the block is the immediate priority. */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" */
        if( (NVM_BLOCK_HIGHEST_PRI == NvM_gstaBlockVar[BlockId].Priority)
             && (NVM_WRITE_BLOCK == NvM_Ctrl) )
        {
            /* Immediate counter plus one. */
            Nvm_QueueHeader.CounterImmediate++;
        }
        /* Increase the number of queues. */
        Nvm_QueueHeader.Counter++;

#if( NVM_STOP_SERVICES == STD_ON )
        /* The number of Fee devices in the queue */
        /* Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
        if( NVM_FEE_DEVICEID == NvM_Block_Descriptor_Table[BlockId].DeviceId )
        {
            Nvm_QueueHeader.FeeReqNum++;
        }
#endif
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_QueueAddSort_StandardJob
*
* Explanation: Function to sort the queue by standard.
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
*                 A NVRAM block descriptor contains all needed information about a
*                 single NVRAM block.
*
* retval: None
*
********************************************************************************
*/
FUNC(void, NVM_CODE) NvM_QueueAddSort_StandardJob(uint16 BlockId)
{
    /* The queue is empty. */
    if( NVM_QUEUE_CURRENTBLOCKID == Nvm_QueueHeader.FirstBlockId )
    {
        /* Set the block id to be the first be executed. */
        Nvm_QueueHeader.FirstBlockId = BlockId;
        Nvm_QueueHeader.LastBlockId = BlockId;
    }
    else
    {
        /* Put the block at the end of the queue. */
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
        NvM_gstaBlockVar[Nvm_QueueHeader.LastBlockId].NxtBlockId = BlockId;
        Nvm_QueueHeader.LastBlockId = BlockId;
    }
    /* Increase the number of queues. */
    Nvm_QueueHeader.Counter++;

#if( NVM_STOP_SERVICES == STD_ON )
    /* The number of Fee devices in the queue */
    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" PolySpace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary4" */
    if( NVM_FEE_DEVICEID == NvM_Block_Descriptor_Table[BlockId].DeviceId )
    {
        Nvm_QueueHeader.FeeReqNum++;
    }
#endif
}

/*
********************************************************************************
* Function Name: NvM_QueueProcess
*
* Explanation: Funciton to Check whether BlockId is available.
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
*                 A NVRAM block descriptor contains all needed information about a
*                 single NVRAM block.
*        NvM_Point: Pointer to the RAM data block.
*        NvM_Ctrl: Indicates the current request type.
*
* retval: E_OK: BlockId is available.
*         E_NOT_OK: BlockId is invalid.
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_QueueProcess
(
    uint16 BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_Point,
    uint8 NvM_Ctrl
)
{
    uint8 rtrnValu = E_NOT_OK;
    uint8 locNvM_Ctrl;
    uint16 locBlockId;

    locBlockId = BlockId;       /* Copy BlockId to local variable. */
    locNvM_Ctrl = NvM_Ctrl;     /* Copy NvM_Ctrl to local variable. */

    /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " Polyspace +1 DEFECT:TAINTED_ARRAY_INDEX [Justified:Unset] "NSCA_Polyspace_NvM_ArrayAccessWithTaintedIndex" */
    if( (NVM_REQ_PENDING != NvM_gstaBlockVar[BlockId].NvRamErrStatus) )  /* The request blcok is pending already. */
    {
        SchM_Enter_NVM_EXCLUSIVE_AREA();

#if( NVM_JOB_PRIORITIZATION == STD_ON ) /* NvMJobPrioritization is configured. */
        /* Insert the request into the queue by priority. */
        rtrnValu = NvM_QueueAddSort_ImmediateJob(locBlockId, locNvM_Ctrl);
#else
        if( Nvm_QueueHeader.Counter < NVM_SIZE_STANDARD_JOB_QUEUE )
        {
            /* Insert the request into the queue in order. */
            NvM_QueueAddSort_StandardJob(locBlockId);
            rtrnValu = E_OK;
        }
#endif  /* NVM_JOB_PRIORITIZATION == STD_ON */

        if( E_OK == rtrnValu )  /* Insert queue successfully. */
        {
            /* Set request type to ram block management. */
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
            NvM_gstaBlockVar[locBlockId].CtrlType = locNvM_Ctrl;
            /* Set the remain lenght. */
            /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_NvM_PtrBoundary " */
            NvM_gstaBlockVar[locBlockId].RemainLegth = NvM_Block_Descriptor_Table[locBlockId].NvBlockLength;
            /* Set ram address to ram block management. */
            /* Polyspace +1 MISRA-C3:11.8 [Justified:Unset] " NSCA_Polyspace_NvM_11.8 " */
            NvM_gstaBlockVar[locBlockId].RamAddr = (uint8*)NvM_Point;    /* PRQA S 311,316 */ /* NSCA_QAC_NvM_Rule_11.8,NSCA_QAC_NvM_Rule_11.5 */
            /* Set ram address to current address. */
            /* Polyspace +1 MISRA-C3:11.8 [Justified:Unset] " NSCA_Polyspace_NvM_11.8 " */
            NvM_gstaBlockVar[locBlockId].CurRamAddr = (uint8*)NvM_Point;    /* PRQA S 311,316 */ /* NSCA_QAC_NvM_Rule_11.8,NSCA_QAC_NvM_Rule_11.5 */
            /* Set Block status NVM_REQ_PENDING. */
            NvM_gstaBlockVar[locBlockId].NvRamErrStatus = NVM_REQ_PENDING;
        }
        SchM_Exit_NVM_EXCLUSIVE_AREA();
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_ReQueueProcess
*
* Explanation: Funciton to Re queue the preempted job.
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
*                 A NVRAM block descriptor contains all needed information about a
*                 single NVRAM block.
*        NvM_Point: Pointer to the RAM data block.
*        NvM_Ctrl: Indicates the current request type.
*
* retval: E_OK: BlockId is available.
*         E_NOT_OK: BlockId is invalid.
********************************************************************************
*/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReQueueProcess
(
    uint16 BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_Point,
    uint8 NvM_Ctrl
)
{
    uint8 rtrnValu = E_NOT_OK;
    uint8 locNvM_Ctrl;
    uint16 locBlockId;

    locBlockId = BlockId;       /* Copy BlockId to local variable. */
    locNvM_Ctrl = NvM_Ctrl;     /* Copy NvM_Ctrl to local variable. */

    /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
    if( NVM_REQ_PENDING == NvM_gstaBlockVar[locBlockId].NvRamErrStatus )  /* The request blcok is pending already. */
    {
        SchM_Enter_NVM_EXCLUSIVE_AREA();

#if( NVM_JOB_PRIORITIZATION == STD_ON ) /* NvMJobPrioritization is configured. */
        /* Insert the request into the queue by priority. */
        rtrnValu = NvM_QueueAddSort_ImmediateJob(locBlockId, locNvM_Ctrl);
#else
        if( Nvm_QueueHeader.Counter < NVM_SIZE_STANDARD_JOB_QUEUE )
        {
            /* Insert the request into the queue in order. */
            NvM_QueueAddSort_StandardJob(locBlockId);
            rtrnValu = E_OK;
        }
#endif  /* NVM_JOB_PRIORITIZATION == STD_ON */

        if( E_OK == rtrnValu )  /* Insert queue successfully. */
        {
            /* Set request type to ram block management. */
            NvM_gstaBlockVar[locBlockId].CtrlType = locNvM_Ctrl;
            /* Set the remain lenght. */
            NvM_gstaBlockVar[locBlockId].RemainLegth = NvM_Block_Descriptor_Table[locBlockId].NvBlockLength;
            /* Set ram address to ram block management. */
            /* Polyspace +1 MISRA-C3:11.8 [Justified:Unset] " NSCA_Polyspace_NvM_11.8 " */
            NvM_gstaBlockVar[locBlockId].RamAddr = (uint8*)NvM_Point;    /* PRQA S 311,316 */ /* NSCA_QAC_NvM_Rule_11.8,NSCA_QAC_NvM_Rule_11.5 */
            /* Set ram address to current address. */
            /* Polyspace +1 MISRA-C3:11.8 [Justified:Unset] " NSCA_Polyspace_NvM_11.8 " */
            NvM_gstaBlockVar[locBlockId].CurRamAddr = (uint8*)NvM_Point;    /* PRQA S 311,316 */ /* NSCA_QAC_NvM_Rule_11.8,NSCA_QAC_NvM_Rule_11.5 */
            /* Set Block status NVM_REQ_PENDING. */
            NvM_gstaBlockVar[locBlockId].NvRamErrStatus = NVM_REQ_PENDING;
        }
        SchM_Exit_NVM_EXCLUSIVE_AREA();
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_CancelQueueProcess
*
* Explanation: Function to remove the requeset from queue.
*
* param: BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
*                 A NVRAM block descriptor contains all needed information about a
*                 single NVRAM block.
*
* retval: Std_ReturnType
********************************************************************************
*/
FUNC(Std_ReturnType, NVM_CODE) NvM_CancelQueueProcess(uint16 BlockId)
{
    boolean flag = FALSE;
    uint8 rtrnValu = E_NOT_OK;
    uint16 curBlockId;
    uint16 indx;
    uint16 preBlockId;
    uint16 recordId;

    curBlockId = NvM_QueueCrrntJob.CurBlockId;  /* Read being performed BlockId. */

    if( NVM_REQ_PENDING == NvM_gstaBlockVar[BlockId].NvRamErrStatus )   /* Pending? */
    {
        if( BlockId != curBlockId ) /* Cannot cancel the block being executed. */
        {
            SchM_Enter_NVM_EXCLUSIVE_AREA();

            if( Nvm_QueueHeader.FirstBlockId == BlockId )
            {
                flag = TRUE;
                /* Check if the pushed block is the end of the queue. */
                if( NVM_QUEUE_CURRENTBLOCKID == NvM_gstaBlockVar[Nvm_QueueHeader.FirstBlockId].NxtBlockId )
                {
                    /* Clear the link relationship of the block. */
                    NvM_gstaBlockVar[Nvm_QueueHeader.FirstBlockId].NxtBlockId = NVM_QUEUE_CURRENTBLOCKID;
                    /* Point to the next block in the queue. */
                    Nvm_QueueHeader.FirstBlockId = NVM_QUEUE_CURRENTBLOCKID;
                    Nvm_QueueHeader.LastBlockId = NVM_QUEUE_CURRENTBLOCKID;
                }
                else
                {
                    recordId = NvM_gstaBlockVar[Nvm_QueueHeader.FirstBlockId].NxtBlockId;
                    /* Clear the link relationship of the block. */
                    NvM_gstaBlockVar[Nvm_QueueHeader.FirstBlockId].NxtBlockId = NVM_QUEUE_CURRENTBLOCKID;
                    Nvm_QueueHeader.FirstBlockId = recordId;
                }
            }
            else
            {
                for( indx = NVM_INIT_0; indx < NVM_NUM_OF_BLOCK_TOTAL; indx++ )
                {
                    if( BlockId == NvM_gstaBlockVar[indx].NxtBlockId )  /* Confirm location in queue. */
                    {
                        flag = TRUE;
                        preBlockId = indx;  /* Remove the requeset from queue. */
                        if( BlockId == Nvm_QueueHeader.LastBlockId )
                        {
                            Nvm_QueueHeader.LastBlockId = preBlockId;
                        }
                        NvM_gstaBlockVar[preBlockId].NxtBlockId = NvM_gstaBlockVar[BlockId].NxtBlockId;
                        NvM_gstaBlockVar[BlockId].NxtBlockId = NVM_QUEUE_NEXTBLOCKID;
                        break;
                    }
                }
            }

            /* Check if the correct block is found. */
            if( TRUE == flag )
            {
                /* Queue length minus one. */
                Nvm_QueueHeader.Counter--;

#if( NVM_STOP_SERVICES == STD_ON )
                /* The number of Fee devices in the queue */
                if( NVM_FEE_DEVICEID == NvM_Block_Descriptor_Table[BlockId].DeviceId )
                {
                    Nvm_QueueHeader.FeeReqNum--;
                }
#endif
                /* Check if the pushed block is immediate write type. */
                if( (NVM_WRITE_BLOCK == NvM_gstaBlockVar[BlockId].CtrlType)
                     && (NVM_BLOCK_HIGHEST_PRI == NvM_gstaBlockVar[BlockId].Priority) )
                {
                    if( Nvm_QueueHeader.CounterImmediate > NVM_INIT_0 )
                    {
                        /* Immediate queue length minus one. */
                        Nvm_QueueHeader.CounterImmediate--;
                    }
                }

                NvM_gstaBlockVar[BlockId].CtrlType = NVM_NO_REQUEST;    /* Clear the request. */
                NvM_gstaBlockVar[BlockId].RamAddr = NULL_PTR;           /* Clrear the target ram address. */
                NvM_gstaBlockVar[BlockId].NvRamErrStatus = NVM_REQ_CANCELED;    /* Set canceled state to block. */
                rtrnValu = E_OK;
            }
            SchM_Exit_NVM_EXCLUSIVE_AREA();
        }
    }

    return rtrnValu;
}

/*
********************************************************************************
* Function Name: NvM_QueuePop
*
* Explanation: Find new element from the queue.
*
* param: void
*
* retval: None
********************************************************************************
*/
FUNC(uint16, NVM_CODE) NvM_QueuePop(void)
{
    uint16 nextBlockId = NVM_INIT_0;

    SchM_Enter_NVM_EXCLUSIVE_AREA();
    /* Check if there is a single block request. */
    if( Nvm_QueueHeader.Counter > NVM_INIT_0 )
    {
        /* Find the block id at the head of the queue. */
        nextBlockId = Nvm_QueueHeader.FirstBlockId;
        /* Point to the next block in the queue. */
        /* PolySpace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" PolySpace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_NvM_PtrBoundary" Polyspace +1 RTE:OBAI [JUstified:Unset] "NSCA_Polyspace_NvM_OutOfBoundArrayIndex" */
        Nvm_QueueHeader.FirstBlockId = NvM_gstaBlockVar[nextBlockId].NxtBlockId;
        /* Check if the pushed block is the end of the queue. */
        if( NVM_QUEUE_CURRENTBLOCKID == NvM_gstaBlockVar[nextBlockId].NxtBlockId )
        {
            Nvm_QueueHeader.LastBlockId = NvM_gstaBlockVar[nextBlockId].NxtBlockId;
        }
        else
        {
            /* Clear the link relationship of the block. */
            NvM_gstaBlockVar[nextBlockId].NxtBlockId = NVM_QUEUE_CURRENTBLOCKID;
        }
        /* Queue length minus one. */
        Nvm_QueueHeader.Counter--;
        /* Check if the pushed block is immediate write type. */
        if( (NVM_WRITE_BLOCK == NvM_gstaBlockVar[nextBlockId].CtrlType)
             && (NVM_BLOCK_HIGHEST_PRI == NvM_gstaBlockVar[nextBlockId].Priority) )
        {
            if( Nvm_QueueHeader.CounterImmediate > NVM_INIT_0 )
            {
                /* Immediate queue length minus one. */
                Nvm_QueueHeader.CounterImmediate--;
            }
        }
    }
    SchM_Exit_NVM_EXCLUSIVE_AREA();

    return nextBlockId;
}

#define NVM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
