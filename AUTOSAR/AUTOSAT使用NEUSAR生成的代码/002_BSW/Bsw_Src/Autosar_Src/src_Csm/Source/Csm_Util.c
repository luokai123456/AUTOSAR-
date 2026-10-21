/*
********************************************************************************
*
*  File name: Csm_Util.c
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 1.0
*  Author/Date: jia_feng/2020.03.10
*  Change: New created
*  Cause: New
********************************************************************************
*  Version: 3.0
*  Author/Date: jia_feng/2020.07.02
*  Change: Nothing
*  Cause: Update
********************************************************************************
*  Version: 3.1
*  Author/Date: NiXM/2023.01.31
*  Change: Modify codes due to coding standards.
*  Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: WangLX/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiK/2025.5.26
* Change: Add polyspace Warning inhibition comment.
* Cause: Optimization
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Csm.h"
#include "Csm_Util.h"

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
*    Global Variable
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
* Function Name: Csm_Util_JobTypeMemcpy
*
* Explanation: JobType memory copy
*
* param: pSource pDest
*
* retval: None
********************************************************************************
*/
FUNC(void, CSM_CODE) Csm_Util_JobTypeMemcpy
(
    P2CONST(Crypto_JobType, AUTOMATIC, CSM_APPL_CONST)pSource,
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA)pDest
)
{
    uint32 u32Size = sizeof(Crypto_JobType);
    const uint8 *pS = (const uint8 *)pSource;   /* PRQA S 310 */ /* NSCA_QAC_Csm_Rule_11.3 */
    uint8 *pD = (uint8 *)pDest;                 /* PRQA S 310 */ /* NSCA_QAC_Csm_Rule_11.3 */

    while( CSM_ZERO < u32Size-- )               /* PRQA S 3440 */ /* NSCA_QAC_Csm_Rule_13.3 */
    {
        /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
        /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
        /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
        *pD = *pS;
        pD++;
        pS++;
    }
}

/*
********************************************************************************
* Function Name: Csm_Util_InitJobQueues
*
* Explanation: Init job queues.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, CSM_CODE) Csm_Util_InitJobQueues(void)
{
    uint32 u32QueueIdx = CSM_ZERO;
    uint32 u32IdxQueue = CSM_ZERO;

    for(u32QueueIdx = CSM_ZERO; u32QueueIdx < (uint32)CSM_NUMBER_OF_QUEUES; u32QueueIdx++)
    {
        /* Initialize the head of queued jobs stating that no job is queued */
        csmJobQueue[u32QueueIdx]->u32HeadOfQueuedJobs = CSM_JOB_QUEUE_NONE_U32;

        if( CSM_ZERO == csmJobQueue[u32QueueIdx]->u32CsmQueueSize )
        {
            /* If CDO queue size is zero, mark the queue of free jobs as being empty. */
            csmJobQueue[u32QueueIdx]->u32HeadOfFreeJobs = CSM_JOB_QUEUE_NONE_U32;
        }
        else
        {
            /* Initialize the queue of free jobs by chaining all queue job elements */
            csmJobQueue[u32QueueIdx]->u32HeadOfFreeJobs = CSM_ZERO;
            for(u32IdxQueue = CSM_ZERO; u32IdxQueue < (csmJobQueue[u32QueueIdx]->u32CsmQueueSize - CSM_ONE); u32IdxQueue++)
            {
                /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
                /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
                /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
                csmJobQueue[u32QueueIdx]->pQueuedJobs[u32IdxQueue].u32Next = u32IdxQueue + CSM_ONE;
            }
            /* Mark the last in the queue as pointing to no other next queue element */
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            csmJobQueue[u32QueueIdx]->pQueuedJobs[u32IdxQueue].u32Next = CSM_JOB_QUEUE_NONE_U32;
        }
    }
}

/*
********************************************************************************
* Function Name: Csm_Util_QueueJob
*
* Explanation: queue in.
*
* param: u32JobIdIdx: the job number to be queued.
*        pJob: the job to be queued.
*
* retval: E_OK E_NOT_OK
********************************************************************************
*/
FUNC(boolean, CSM_CODE) Csm_Util_QueueJob
(
    uint32 u32QueueIdx,
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA)pJob /* PRQA S 3673 */ /* NSCA_QAC_Common_Rule8.13 */
)
{
    uint32 *pSearch = (uint32*)&(csmJobQueue[u32QueueIdx]->u32HeadOfQueuedJobs);
    boolean bJobQueued = (boolean)FALSE;
    uint32 u32IdxQueueJob = CSM_ZERO;
    uint32 u32TempIdxQueue = CSM_ZERO;

    /* Check if there is at least one element in the free jobs queue */
    if( CSM_JOB_QUEUE_NONE_U32 != csmJobQueue[u32QueueIdx]->u32HeadOfFreeJobs )
    {
        /* Enter critical section  */
        /* SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_00(); */
        /* Take the first element from the queue of free jobs */
        u32IdxQueueJob = csmJobQueue[u32QueueIdx]->u32HeadOfFreeJobs;
        /* Set new value for head of free jobs queue as the next element in the queue */
        /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
        /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
        /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
        /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
        csmJobQueue[u32QueueIdx]->u32HeadOfFreeJobs = csmJobQueue[u32QueueIdx]->pQueuedJobs[u32IdxQueueJob].u32Next;
        /* Put the element taken from free jobs queue in the job queue, in the right position based on priority */
        /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
        /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
        /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
        /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
        while( ((boolean)FALSE == bJobQueued) && (CSM_JOB_QUEUE_NONE_U32 != *pSearch) )
        {
            /* Polyspace +5 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
            /* Polyspace +4 RTE:NIP [Justified:Unset] "NSCA_Polyspace_Csm_NIP" */
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            if( pJob->jobInfo->jobPriority > csmJobQueue[u32QueueIdx]->pQueuedJobs[*pSearch].job.jobInfo->jobPriority )
            {
                /* Save address of list element we are inserting the new job in front of */
                u32TempIdxQueue = *pSearch;
                /* Need to insert the element here */
                *pSearch = u32IdxQueueJob;
                /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
                /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
                /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
                csmJobQueue[u32QueueIdx]->pQueuedJobs[u32IdxQueueJob].u32Next = u32TempIdxQueue;
                /* Mark the job as queued */
                bJobQueued = (boolean)TRUE;
            }
            /* Advance to the next element in the queue */
            pSearch = (uint32*)&(csmJobQueue[u32QueueIdx]->pQueuedJobs[*pSearch].u32Next);
        }

        if( (boolean)FALSE == bJobQueued )
        {
            *pSearch = u32IdxQueueJob;
            /* Mark the new added queue element as being the last one in the queue */
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            csmJobQueue[u32QueueIdx]->pQueuedJobs[u32IdxQueueJob].u32Next = CSM_JOB_QUEUE_NONE_U32;
        }
        /* Exit critical section */
        //SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_00();
        /* Copy the job into the free queue element found */
        Csm_Util_JobTypeMemcpy(pJob, &(csmJobQueue[u32QueueIdx]->pQueuedJobs[u32IdxQueueJob].job));
        /* Mark the job as queued */
        bJobQueued = (boolean)TRUE;
    }

    return bJobQueued;
}

/*
********************************************************************************
* Function Name: Csm_Util_DequeueHeadJob
*
* Explanation: Head job queue out.
*
* param: u32JobIdIdx: the job number to be Dequeued
*
* retval: None
********************************************************************************
*/

FUNC(void, CSM_CODE) Csm_Util_DequeueHeadJob
(
    uint32 u32QueueIdx
)
{
    uint32 u32HeadOfQueuedJobs = CSM_ZERO;
    uint32 u32HeadOfFreeJobs = CSM_ZERO;

    /* Enter critical section  */
    /* SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_01(); */

    u32HeadOfQueuedJobs = csmJobQueue[u32QueueIdx]->u32HeadOfQueuedJobs;
    u32HeadOfFreeJobs   = csmJobQueue[u32QueueIdx]->u32HeadOfFreeJobs;

    /* Move head of queued jobs to the next element in the queue */
    /* Polyspace +4 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
    /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
    /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
    /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
    csmJobQueue[u32QueueIdx]->u32HeadOfQueuedJobs = csmJobQueue[u32QueueIdx]->pQueuedJobs[u32HeadOfQueuedJobs].u32Next;

    /* Add the removed head of queued jobs as being the head of queue of free jobs */
    csmJobQueue[u32QueueIdx]->u32HeadOfFreeJobs                        = u32HeadOfQueuedJobs;
    csmJobQueue[u32QueueIdx]->pQueuedJobs[u32HeadOfQueuedJobs].u32Next = u32HeadOfFreeJobs;

    /* Exit critical section */
    /*SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_01();*/
}

/*
********************************************************************************
* Function Name: Csm_Util_DequeueJob
*
* Explanation: queue out.
*
* param: u32JobIdIdx: the job number to be dequeued.
*        pJobInfo: the job to be dequeued.
*
* retval: E_OK E_NOT_OK
********************************************************************************
*/
FUNC(Std_ReturnType, CSM_CODE) Csm_Util_DequeueJob
(
    uint32 u32QueueIdx,
    P2CONST(Crypto_JobInfoType, AUTOMATIC, CSM_APPL_CONST)pJobInfo
)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint32 u32TempIdxQueue1 = CSM_ZERO;
    uint32 u32TempIdxQueue2 = CSM_ZERO;
    uint32 *pSearch = (uint32*)&(csmJobQueue[u32QueueIdx]->u32HeadOfQueuedJobs);

    /* Check if there is at least one element in the list of queued jobs */
    if( CSM_JOB_QUEUE_NONE_U32 != csmJobQueue[u32QueueIdx]->u32HeadOfQueuedJobs )
    {
        /* Loop through entire list of queued jobs */
        /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
        while( CSM_JOB_QUEUE_NONE_U32 != *pSearch )
        {
            /* Check if the current looped job from the list of queued jobs has same jobId with the one received as parameter */
            /* Polyspace +5 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
            /* Polyspace +4 RTE:NIP [Justified:Unset] "NSCA_Polyspace_Csm_NIP" */
            /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
            /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
            /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
            if( pJobInfo->jobId == csmJobQueue[u32QueueIdx]->pQueuedJobs[*pSearch].job.jobInfo->jobId )
            {
                /* Enter critical section  */
                /*SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_02();*/

                /* Store temporary the value of the address of the element in array */
                u32TempIdxQueue1 = *pSearch;

                /* Found a job matching the same jobId. Remove it from the list of queued jobs */
                /* Polyspace +1 RTE:NIV [Justified:Unset] "NSCA_Polyspace_Csm_NIV" */
                *pSearch = csmJobQueue[u32QueueIdx]->pQueuedJobs[*pSearch].u32Next;

                /* Add the removed element in in the list of free jobs */
                u32TempIdxQueue2 = csmJobQueue[u32QueueIdx]->u32HeadOfFreeJobs;
                csmJobQueue[u32QueueIdx]->u32HeadOfFreeJobs = u32TempIdxQueue1;
                /* Polyspace +3 RTE:IDP [Justified:Unset] "NSCA_Polyspace_Csm_IDP" */
                /* Polyspace +2 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_Csm_Rule18.1" */
                /* Polyspace +1 MISRA-C3:D4.1 [JUstified:Unset] "NSCA_Polyspace_Csm_Dir4.1" */
                csmJobQueue[u32QueueIdx]->pQueuedJobs[u32TempIdxQueue1].u32Next = u32TempIdxQueue2;

                /* Exit critical section */
                /*SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_02();*/

                retVal = E_OK;
                break;
            }
            /* Advance to the next element in the list of queued jobs, searching for the job to dequeue */
            pSearch = (uint32*)&(csmJobQueue[u32QueueIdx]->pQueuedJobs[*pSearch].u32Next);
        }
    }

    return retVal;
}

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
