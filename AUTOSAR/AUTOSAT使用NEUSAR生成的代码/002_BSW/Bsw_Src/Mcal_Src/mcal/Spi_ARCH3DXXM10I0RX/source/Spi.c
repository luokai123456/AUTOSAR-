/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : SPI
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Spi.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of SPI MCAL driver.
*
*   @addtogroup Spi
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*PRQA S 0380,0311,0686,1006,2813,2842,2986,3432 EOF*/
/*PRQA S 0488,0491,2755,2844,2934,3305,0310,4397,1258,1580,1520 EOF*/ /*QAC_CWE*/
/*==================================================================================================
INCLUDE
==================================================================================================*/
#include "Spi_AutoSAR_Wrapper.h"
#include "Spi.h"
#include "Det.h"
#include "SchM_Spi.h"
/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_C_VENDOR_ID_C                 176
#define SPI_C_AR_MAJOR_VER_C              4
#define SPI_C_AR_MINOR_VER_C              4
#define SPI_C_AR_PATCH_VER_C              0
#define SPI_C_SW_MAJOR_VER_C              3
#define SPI_C_SW_MINOR_VER_C              0
#define SPI_C_SW_PATCH_VER_C              0

/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_C_VENDOR_ID_C != SPI_CFG_VENDOR_ID)
#error "NON-MATCHED DATA : SPI_C_VENDOR_ID_C"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (SPI_C_AR_MAJOR_VER_C != SPI_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SPI_C_AR_MAJOR_VER_C"
#endif
#if (SPI_C_AR_MINOR_VER_C != SPI_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SPI_C_AR_MINOR_VER_C"
#endif
#if (SPI_C_AR_PATCH_VER_C != SPI_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SPI_C_AR_PATCH_VER_C"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (SPI_C_SW_MAJOR_VER_C != SPI_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SPI_C_SW_MAJOR_VER_C"
#endif
#if (SPI_C_SW_MINOR_VER_C != SPI_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SPI_C_SW_MINOR_VER_C"
#endif
#if (SPI_C_SW_PATCH_VER_C != SPI_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SPI_C_SW_PATCH_VER_C"
#endif

#define SPI_PRIORITY_INSNODE(List, Node, Spi_ConfigPtr, NodeJobCfg)                           \
    P2VAR(Spi_AsyncScheType, SPI_VAR, SPI_APPL_DATA) CurrentAsyncNode = (*(List));            \
    P2VAR(Spi_AsyncScheType, SPI_VAR, SPI_APPL_DATA) LastAsyncNode = NULL_PTR;                \
    P2CONST(Spi_SequenceCfgType, SPI_VAR, SPI_APPL_CONST) ListSeqCfg;                         \
    P2CONST(Spi_JobCfgType, SPI_VAR, SPI_APPL_CONST) ListJobCfg;                              \
    do{                                                                                       \
        ListSeqCfg = &(Spi_ConfigPtr)->SequenceConfiguration[CurrentAsyncNode->SequenceId];   \
        ListJobCfg = &(Spi_ConfigPtr)->JobConfiguration[ListSeqCfg->JobList[0U]];             \
        if((NodeJobCfg)->SpiJobPriority > ListJobCfg->SpiJobPriority)                         \
        {                                                                                     \
            break;                                                                            \
        }                                                                                     \
        else                                                                                  \
        {                                                                                     \
            LastAsyncNode = CurrentAsyncNode;                                                 \
            CurrentAsyncNode = CurrentAsyncNode->Next_Sequence;                               \
        }                                                                                     \
    }while(CurrentAsyncNode != NULL_PTR);                                                     \
    (Node)->Next_Sequence = CurrentAsyncNode;                                                 \
    if(CurrentAsyncNode == (*(List)))                                                         \
    {                                                                                         \
        (*(List)) = (Node);                                                                   \
    }                                                                                         \
    else                                                                                      \
    {                                                                                         \
        if (LastAsyncNode != NULL_PTR)                                                        \
        {                                                                                     \
            LastAsyncNode->Next_Sequence = (Node);                                            \
        }                                                                                     \
    }                                                                                         \


#define SPI_MOVE_NODE(DesList, SrcList, Spi_ConfigPtr, NodeJobCfg)                            \
    P2VAR(Spi_AsyncScheType, SPI_VAR, SPI_APPL_DATA) MoveAsyncNode = (*(SrcList));            \
    (*(SrcList)) = (*(SrcList))->Next_Sequence;                                               \
    SPI_PRIORITY_INSNODE((DesList), (MoveAsyncNode), (Spi_ConfigPtr), NodeJobCfg);            \


#define SPI_ORIDER_INSNODE(List, Node)                                                        \
    P2VAR(Spi_AsyncScheType, SPI_VAR, SPI_APPL_DATA) CurrentAsyncNode = (*(List));            \
    P2VAR(Spi_AsyncScheType, SPI_VAR, SPI_APPL_DATA) LastAsyncNode = NULL_PTR;                \
    while(CurrentAsyncNode != NULL_PTR)                                                       \
    {                                                                                         \
        LastAsyncNode = CurrentAsyncNode;                                                     \
        CurrentAsyncNode = CurrentAsyncNode->Next_Sequence;                                   \
    }                                                                                         \
    (Node)->Next_Sequence = CurrentAsyncNode;                                                 \
    if(CurrentAsyncNode == (*(List)))                                                         \
    {                                                                                         \
        (*(List)) = (Node);                                                                   \
    }                                                                                         \
    else                                                                                      \
    {                                                                                         \
        if (LastAsyncNode != NULL_PTR)                                                        \
        {                                                                                     \
            LastAsyncNode->Next_Sequence = (Node);                                            \
        }                                                                                     \
    }                                                                                         \




/*==================================================================================================
SHARED VAR INIT
==================================================================================================*/

#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_gConfigPtr = NULL_PTR;
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
static VAR(Spi_StatusType, SPI_VAR) Spi_gStatus = SPI_UNINIT;
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
static VAR(Spi_StatusType, SPI_VAR) Spi_gAsyncStatus = SPI_UNINIT;
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
static VAR(Spi_StatusType, SPI_VAR) Spi_gHWUnitStatus[SPI_TOTAL_HWDEVICE] = {SPI_UNINIT};
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
static VAR(Spi_SeqResultType, SPI_VAR) Spi_gSeqStatus[SPI_TOTAL_SEQUENCE] = {SPI_SEQ_OK};
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
static VAR(Spi_JobResultType, SPI_VAR) Spi_gJobStatus[SPI_TOTAL_JOB] = {SPI_JOB_OK};
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
static VAR(Spi_AsyncScheType, SPI_VAR) Spi_gAsyncNode[SPI_TOTAL_SEQUENCE] = {{0U}};
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
#endif

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
VAR(Spi_AsyncModeType, SPI_VAR) Spi_gAsyncMode = SPI_POLLING_MODE;
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
VAR(Spi_HandleType, SPI_VAR) Spi_gHandle[SPI_TOTAL_HWDEVICE] = {{
    DSPI1,0U, 0U, 0U, 0U, 0U,//TODO
    NULL_PTR, NULL_PTR, 0U, 0U,
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    NULL_PTR, NULL_PTR, 0U, 0U, 0U, 0U, RW_B,
    #if (SPI_DMA_USED == STD_ON)
    0U,0U,0U
    #endif
    #endif
}};
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"


/*==================================================================================================
CODE
==================================================================================================*/

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_INLINE FUNC(void, SPI_CODE)Spi_InsSequence( 
    P2CONST(Spi_SequenceCfgType, AUTOMATIC, SPI_APPL_CONST) SequenceConfig );
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_INLINE FUNC(void, SPI_CODE)Spi_StartAsyncScheduler(
    P2CONST(Spi_JobCfgType, AUTOMATIC, SPI_APPL_CONST) JobConfig);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_INLINE FUNC(void, SPI_CODE) Spi_DataReverse(
    P2VAR(uint8, AUTOMATIC, SPI_APPL_DATA) src,
    P2VAR(uint8, AUTOMATIC, SPI_APPL_DATA) des,
    VAR(uint32, SPI_VAR) len )
{
    for(;(len != 0U);len--)
    {
        *((uint32 *)des) = SPI_DATA_REVERSE(*((uint32 *)src));/* polyspace RTE:NIV,IDP */
        src = (uint8 *)((uint32)src + 4U);
        des = (uint8 *)((uint32)des + 4U);
    }
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE)Spi_AsyncSchedulerMain( P2VAR(Spi_HandleType, SPI_VAR, SPI_APPL_DATA) Spi_HandlePtr )
{
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;
    P2CONST(Spi_SequenceCfgType, SPI_VAR, SPI_APPL_CONST)SequenceConfig;
    P2CONST(Spi_JobCfgType, SPI_VAR, SPI_APPL_CONST)JobConfig;

    P2VAR(Spi_AsyncScheType, SPI_VAR, SPI_APPL_DATA) Spi_AsyncSchePtr = Spi_HandlePtr->Spi_AsyncSchePtr;

    VAR(Spi_JobType, SPI_VAR)JobIdx;
    VAR(boolean, SPI_VAR) InsFlag = FALSE;

    VAR(Spi_SeqEndNotifyType, SPI_VAR) SeqNotification = NULL_PTR;
    SchM_Enter_Spi_EXCLUSIVE_AREA_00();
    SequenceConfig = &Spi_ConfigPtr->SequenceConfiguration[Spi_AsyncSchePtr->SequenceId];
    JobConfig = &Spi_ConfigPtr->JobConfiguration[SequenceConfig->JobList[Spi_AsyncSchePtr->Current_Job]];/* polyspace RTE:NIV,NIP,IDP */

    /* Complete current Job notification and state transition */
    Spi_gJobStatus[SequenceConfig->JobList[Spi_AsyncSchePtr->Current_Job]] = (Spi_JobResultType)SPI_JOB_OK;/* polyspace RTE:OBAI */
    if(JobConfig->JobEndNotification != NULL_PTR)/* polyspace RTE:NIP,IDP */
    {
        (void)JobConfig->JobEndNotification();/* polyspace RTE:COR */
    }

    Spi_gHWUnitStatus[JobConfig->HwDeviceIdx] = (Spi_StatusType)SPI_IDLE;/* polyspace RTE:OBAI,NIV */

    /* Switch to the next Job */
    Spi_AsyncSchePtr->Current_Job++;

    if(Spi_AsyncSchePtr->Current_Job < SequenceConfig->NoOfJobs)/* polyspace RTE:NIV */
    {
        if(SequenceConfig->InterruptableSequence == TRUE)/* polyspace RTE:NIV */
        {
            InsFlag = TRUE;
        }
    }
    else
    {
        /* The procedure is insertable for new sequences */
        InsFlag = TRUE;

        Spi_gSeqStatus[Spi_AsyncSchePtr->SequenceId] = (Spi_SeqResultType)SPI_SEQ_OK;/* polyspace RTE:OBAI,NIV */
        SeqNotification = SequenceConfig->SequenceEndNotification; /* polyspace RTE:COR *//* polyspace RTE:NIP */
        /* Iterate over to find the next valid Sequence */
        Spi_HandlePtr->Spi_AsyncSchePtr = Spi_AsyncSchePtr->Next_Sequence; /* polyspace RTE:NIP */
    }

    if(InsFlag == TRUE)
    {
        while(Spi_HandlePtr->Spi_AsyncAssSchePtr != NULL_PTR)
        {
            if(Spi_HandlePtr->Spi_AsyncSchePtr == NULL_PTR)
            {
                Spi_AsyncSchePtr = Spi_HandlePtr->Spi_AsyncAssSchePtr;
                Spi_HandlePtr->Spi_AsyncAssSchePtr = Spi_HandlePtr->Spi_AsyncAssSchePtr->Next_Sequence;/* polyspace RTE:NIP,IDP */
                Spi_AsyncSchePtr->Next_Sequence = NULL_PTR;
                Spi_HandlePtr->Spi_AsyncSchePtr = Spi_AsyncSchePtr;
            }
            else
            {
                SequenceConfig = &Spi_ConfigPtr->SequenceConfiguration[Spi_HandlePtr->Spi_AsyncAssSchePtr->SequenceId];/* polyspace RTE:NIV,IDP */
                JobConfig = &Spi_ConfigPtr->JobConfiguration[SequenceConfig->JobList[Spi_HandlePtr->Spi_AsyncAssSchePtr->Current_Job]];/* polyspace RTE:NIV,NIP,IDP */
                SPI_MOVE_NODE(&Spi_HandlePtr->Spi_AsyncSchePtr, &Spi_HandlePtr->Spi_AsyncAssSchePtr, Spi_ConfigPtr, JobConfig);/* polyspace RTE:NIV,NIP,IDP */
            }
        }
    }

    Spi_AsyncSchePtr = Spi_HandlePtr->Spi_AsyncSchePtr;

    while(Spi_AsyncSchePtr != NULL_PTR)
    {
        if(Spi_gSeqStatus[Spi_AsyncSchePtr->SequenceId] != (Spi_SeqResultType)SPI_SEQ_PENDING)/* polyspace RTE:OBAI,NIV,IDP */
        {
            SequenceConfig = (Spi_SequenceCfgType *)&Spi_ConfigPtr->SequenceConfiguration[Spi_AsyncSchePtr->SequenceId];
            for(JobIdx = Spi_AsyncSchePtr->Current_Job; JobIdx < SequenceConfig->NoOfJobs; JobIdx++)/* polyspace RTE:NIV,IDP */
            {
                Spi_gJobStatus[SequenceConfig->JobList[JobIdx]] = SPI_JOB_FAILED;/* polyspace RTE:OBAI,NIV,NIP,IDP */
            }
            Spi_HandlePtr->Spi_AsyncSchePtr = Spi_AsyncSchePtr->Next_Sequence;/* polyspace RTE:NIP */
            Spi_AsyncSchePtr = Spi_HandlePtr->Spi_AsyncSchePtr;
        }
        else
        {
            break;
        }
    }

    if(Spi_HandlePtr->Spi_AsyncSchePtr != NULL_PTR)
    {
        SequenceConfig = &Spi_ConfigPtr->SequenceConfiguration[Spi_HandlePtr->Spi_AsyncSchePtr->SequenceId];
        JobConfig = &Spi_ConfigPtr->JobConfiguration[SequenceConfig->JobList[Spi_HandlePtr->Spi_AsyncSchePtr->Current_Job]];/* polyspace RTE:NIV,NIP,IDP */
        /* Start AsyncScheduler */
        Spi_StartAsyncScheduler( JobConfig );
    }
    else
    {
        /* Stop AsyncScheduler */
        Spi_gStatus = (Spi_StatusType)SPI_IDLE;
        Spi_gAsyncStatus = (Spi_StatusType)SPI_IDLE;
    }
    if(SeqNotification != NULL_PTR)/* polyspace RTE:NIP */
    {
        (void)SeqNotification();/* polyspace RTE:COR */
    }
    SchM_Exit_Spi_EXCLUSIVE_AREA_00();  /* Critical region protection */
}

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_INLINE FUNC(void, SPI_CODE)Spi_InsSequence( 
    P2CONST(Spi_SequenceCfgType, AUTOMATIC, SPI_APPL_CONST) SequenceConfig )
{
    P2CONST(Spi_JobCfgType, SPI_VAR, SPI_APPL_CONST) JobConfig;
    P2VAR(Spi_HandleType, SPI_VAR, SPI_APPL_DATA) Spi_HandlePtr;

    JobConfig = &Spi_gConfigPtr->JobConfiguration[SequenceConfig->JobList[0U]];/* polyspace RTE:NIV,NIP,IDP */
    Spi_HandlePtr = &Spi_gHandle[JobConfig->HwDeviceIdx];/* polyspace RTE:NIV,IDP */

    Spi_gAsyncNode[SequenceConfig->SequenceId].Current_Job = 0U;/* polyspace RTE:OBAI,NIV */
    Spi_gAsyncNode[SequenceConfig->SequenceId].Next_Sequence = NULL_PTR;

    if((Spi_HandlePtr->Spi_AsyncSchePtr == NULL_PTR) && (Spi_HandlePtr->Spi_AsyncAssSchePtr == NULL_PTR))/* polyspace RTE:IDP */
    {
        Spi_gStatus = (Spi_StatusType)SPI_BUSY;
        Spi_gAsyncStatus = (Spi_StatusType)SPI_BUSY;
        Spi_HandlePtr->Spi_AsyncSchePtr = (Spi_AsyncScheType *)&Spi_gAsyncNode[SequenceConfig->SequenceId];
        Spi_StartAsyncScheduler( JobConfig );
    }
    else
    {
        SPI_ORIDER_INSNODE( (Spi_AsyncScheType **)&Spi_HandlePtr->Spi_AsyncAssSchePtr, /* polyspace RTE:NIP,IDP */
                            (Spi_AsyncScheType *)&Spi_gAsyncNode[SequenceConfig->SequenceId] );
    }
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_INLINE FUNC(void, SPI_CODE)Spi_StartAsyncScheduler(
    P2CONST(Spi_JobCfgType, AUTOMATIC, SPI_APPL_CONST) JobConfig )
{
    Spi_gJobStatus[JobConfig->JobId] = (Spi_JobResultType)SPI_JOB_PENDING;/* polyspace RTE:OBAI,NIV,IDP */
    Spi_gHWUnitStatus[JobConfig->HwDeviceIdx] = (Spi_StatusType)SPI_BUSY;/* polyspace RTE:OBAI,NIV */

    SchM_Exit_Spi_EXCLUSIVE_AREA_01();  /* Critical region protection */
    (void)Spi_Wrap_AsyncTransmit((Spi_JobCfgType *)JobConfig);
    SchM_Enter_Spi_EXCLUSIVE_AREA_01();  /* Critical region protection */
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif


/* [SWS_Spi_00175] */
/* Service for SPI initialization. */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE) Spi_Init(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr)
{
    VAR(uint32, SPI_VAR)Spi_ArrIndex = (uint32)0UL;
    P2CONST(Spi_HwDeviceCfgType, SPI_VAR, SPI_APPL_CONST) Spi_HwDevicePtr;
    SchM_Enter_Spi_EXCLUSIVE_AREA_02();  /* Critical region protection */
    /* [SWS_Spi_00298] */
    /* [SWS_Spi_00233] */
    #if (SPI_PRECOMPILE_SUPPORT == STD_ON)
    if(ConfigPtr != NULL_PTR)
    #else
    if(ConfigPtr == NULL_PTR)
    #endif
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError( (uint16)SPI_MODULE_ID,
                               (uint8)SPI_INSTANCE_ID,
                               (uint8)SPI_INIT_SID,
                               (uint8)SPI_E_PARAM_POINTER);
        #endif
    }
    else
    {
        if(Spi_gConfigPtr != NULL_PTR)
        {
            #if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError( (uint16)SPI_MODULE_ID,
                                   (uint8)SPI_INSTANCE_ID,
                                   (uint8)SPI_INIT_SID,
                                   (uint8)SPI_E_ALREADY_INITIALIZED );
            #endif
        }
        else
        {
            #if(SPI_PRECOMPILE_SUPPORT == STD_ON)
            Spi_gConfigPtr = (const Spi_ConfigType *)&Spi_Config;
            (void)ConfigPtr;
            #else
            Spi_gConfigPtr = (const Spi_ConfigType *)ConfigPtr;
            #endif
            /* [SWS_Spi_00015] */
            Spi_gStatus = (Spi_StatusType)SPI_IDLE;
            #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
            Spi_gAsyncStatus = (Spi_StatusType)SPI_IDLE;
            #endif

            for(Spi_ArrIndex=0; Spi_ArrIndex<SPI_TOTAL_SEQUENCE; Spi_ArrIndex++)
            {
                Spi_gSeqStatus[Spi_ArrIndex] = (Spi_SeqResultType)SPI_SEQ_OK;
            }
            for(Spi_ArrIndex=0; Spi_ArrIndex<SPI_TOTAL_JOB; Spi_ArrIndex++)
            {
                Spi_gJobStatus[Spi_ArrIndex] = (Spi_JobResultType)SPI_JOB_OK;
            }
            #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
            for(Spi_ArrIndex=0; Spi_ArrIndex<SPI_TOTAL_SEQUENCE; Spi_ArrIndex++)
            {
                Spi_gAsyncNode[Spi_ArrIndex].SequenceId = (Spi_SequenceType)Spi_ArrIndex;
                Spi_gAsyncNode[Spi_ArrIndex].Current_Job = (Spi_JobType)0U;
                Spi_gAsyncNode[Spi_ArrIndex].Next_Sequence = NULL_PTR;
            }
            #endif

            for(Spi_ArrIndex=0; Spi_ArrIndex<SPI_TOTAL_HWDEVICE; Spi_ArrIndex++)
            {
                Spi_HwDevicePtr = &Spi_gConfigPtr->HwDeviceConfiguration[Spi_ArrIndex];
                Spi_gHWUnitStatus[Spi_ArrIndex] = (Spi_StatusType)SPI_IDLE;
                #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
                Spi_gHandle[Spi_ArrIndex].Spi_AsyncSchePtr = NULL_PTR;
                Spi_gHandle[Spi_ArrIndex].Spi_AsyncAssSchePtr = NULL_PTR;
                #if (SPI_DMA_USED == STD_ON)
                Spi_gHandle[Spi_ArrIndex].Spi_TxDmaChannelID = Spi_HwDevicePtr->Spi_TxDmaChannelID;
                Spi_gHandle[Spi_ArrIndex].Spi_RxDmaChannelID = Spi_HwDevicePtr->Spi_RxDmaChannelID;
                #endif
                #endif
                Spi_Wrap_Init((uint8)Spi_HwDevicePtr->HwDevice);/* polyspace RTE:NIV,IDP */
            }

            /* [SWS_Spi_00151] */
            #if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
            Spi_gAsyncMode = (Spi_AsyncModeType)SPI_POLLING_MODE;
            #endif
        }
    }
    SchM_Exit_Spi_EXCLUSIVE_AREA_02();  /* Critical region protection */
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/* [SWS_Spi_00298] The operation Spi_Init is Non Re-entrant.() */
/* [SWS_Spi_00299] The function Spi_Init provides the service for SPI initialization.() */
/* [SWS_Spi_00013] The function Spi_Init shall initialize all SPI relevant registers with the values of the structure referenced by the parameter ConfigPtr.(SRS_BSW_00405, SRS_BSW_00101, SRS_SPAL_12057, SRS_SPAL_12125) */
/* [SWS_Spi_00082] The function Spi_Init shall define default values for required parameters of the structure referenced by the ConfigPtr. For example: all buffer pointers shall be initialized as a null value pointer.() */
/* [SWS_Spi_00015] After the module initialization using the function Spi_Init, the SPI Handler/Driver shall set its state to SPI_IDLE, the Sequences result to SPI_SEQ_OK and the jobs result to SPI_JOB_OK.(SRS_BSW_00406, SRS_BSW_00101, SRS_SPAL_12057) */
/* [SWS_Spi_00151] For LEVEL 2 (see chapter 7.2.5 and SPI103), the function Spi_Init shall set the SPI Handler/Driver asynchronous mechanism mode to SPI_POLLING_MODE by default. Interrupts related to SPI busses shall be disabled.() */

/* [SWS_Spi_00233] If development error detection for the SPI module is enabled, the calling of the rou-tine SPI_Init() while the SPI driver is already initialized will cause a development error SPI_E_ALREADY_INITIALIZED and the desired functionality shall be left without any action.() */

/* [SWS_Spi_00176] */
/* Service for SPI de-initialization. */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void)
{
    VAR(Std_ReturnType, SPI_VAR)RetResult = (Std_ReturnType)E_OK;
    VAR(uint32, SPI_VAR)Spi_ArrIndex = (uint32)0U;
    P2CONST(Spi_HwDeviceCfgType, SPI_DATA, SPI_APPL_CONST) Spi_HwDevicePtr;

    SchM_Enter_Spi_EXCLUSIVE_AREA_03();  /* Critical region protection */
    /* [SWS_Spi_00300] */
    if(Spi_gConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError( (uint16)SPI_MODULE_ID, \
                               (uint8)SPI_INSTANCE_ID, \
                               (uint8)SPI_DEINIT_SID, \
                               (uint8)SPI_E_UNINIT );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        for(Spi_ArrIndex = 0; Spi_ArrIndex < SPI_TOTAL_HWDEVICE; Spi_ArrIndex++)
        {
            if(Spi_gHWUnitStatus[Spi_ArrIndex] == SPI_BUSY)
            {
                break;
            }
        }

        if(Spi_ArrIndex != SPI_TOTAL_HWDEVICE)
        {
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Spi_gStatus = (Spi_StatusType)SPI_UNINIT;
            #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
            Spi_gAsyncStatus = (Spi_StatusType)SPI_UNINIT;
            #endif

            for(Spi_ArrIndex=0; Spi_ArrIndex<SPI_TOTAL_SEQUENCE; Spi_ArrIndex++)
            {
                Spi_gSeqStatus[Spi_ArrIndex] = (Spi_SeqResultType)SPI_SEQ_OK;
            }
            for(Spi_ArrIndex=0; Spi_ArrIndex<SPI_TOTAL_JOB; Spi_ArrIndex++)
            {
                Spi_gJobStatus[Spi_ArrIndex] = (Spi_JobResultType)SPI_JOB_OK;
            }
            #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
            for(Spi_ArrIndex=0; Spi_ArrIndex<SPI_TOTAL_SEQUENCE; Spi_ArrIndex++)
            {
                Spi_gAsyncNode[Spi_ArrIndex].SequenceId = (Spi_SequenceType)Spi_ArrIndex;
                Spi_gAsyncNode[Spi_ArrIndex].Current_Job = (Spi_JobType)0U;
                Spi_gAsyncNode[Spi_ArrIndex].Next_Sequence = NULL_PTR;
            }
            #endif

            for(Spi_ArrIndex=0; Spi_ArrIndex<SPI_TOTAL_HWDEVICE; Spi_ArrIndex++)
            {
                Spi_HwDevicePtr = &Spi_gConfigPtr->HwDeviceConfiguration[Spi_ArrIndex];
                Spi_gHWUnitStatus[Spi_ArrIndex] = (Spi_StatusType)SPI_UNINIT;
                #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
                Spi_gHandle[Spi_ArrIndex].Spi_AsyncSchePtr = NULL_PTR;
                Spi_gHandle[Spi_ArrIndex].Spi_AsyncAssSchePtr = NULL_PTR;
                #if (SPI_DMA_USED == STD_ON)
                Spi_gHandle[Spi_ArrIndex].Spi_TxDmaChannelID = Spi_HwDevicePtr->Spi_TxDmaChannelID;
                Spi_gHandle[Spi_ArrIndex].Spi_RxDmaChannelID = Spi_HwDevicePtr->Spi_RxDmaChannelID;
                #endif
                #endif
                Spi_Wrap_DeInit((uint8)Spi_HwDevicePtr->HwDevice);/* polyspace RTE:NIV,IDP */
            }

            /* [SWS_Spi_00151] */
            #if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
            Spi_gAsyncMode = (Spi_AsyncModeType)SPI_POLLING_MODE;
            #endif

            Spi_gConfigPtr = NULL_PTR;
            RetResult = (Std_ReturnType)E_OK;
        }
    }
    SchM_Exit_Spi_EXCLUSIVE_AREA_03();  /* Critical region protection */
    return (Std_ReturnType)RetResult;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/* [SWS_Spi_00300] The operation Std_ReturnType Spi_DeInit( ) is Non Re-entrant.() */
/* [SWS_Spi_00301] When the API Spi_DeInit has been accepted the return value of this function shall be E_OK.() */
/* [SWS_Spi_00302] When the API Spi_DeInit has not been accepted the return value of this function shall be E_NOT_OK.() */
/* [SWS_Spi_00303] The function Spi_DeInit provides the service for SPI de-initialization.() */
/* [SWS_Spi_00021] The function Spi_DeInit shall de-initialize SPI Handler/Driver.(SRS_BSW_00336, SRS_SPAL_12163, SRS_SPAL_12064) */
/* [SWS_Spi_00252] In case of the SPI Handler/Driver state is not SPI_BUSY, the deInitialization function shall put all already initialized microcontroller SPI McMePeripheral into the same state such as Power On Reset.() */
/* [SWS_Spi_00253] The function call Spi_DeInit shall be rejected if the status of SPI Handler/Driver is SPI_BUSY.() */
/* [SWS_Spi_00022] After the module de-initialization using the function Spi_DeInit, the SPI Handler/Driver shall set its state to SPI_UNINIT.(SRS_BSW_00336, SRS_SPAL_12163) */

/* [SWS_Spi_00177] */
/* Service for writing one or more data to an IB SPI Handler/Driver Channel specified by parameter. */
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB(
    VAR(Spi_ChannelType, AUTOMATIC) Channel,
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_CONST) DataBufferPtr)
{
    VAR(Std_ReturnType, SPI_VAR) RetResult = (Std_ReturnType)E_OK;
    VAR(uint32, SPI_VAR)Spi_ArrIndex = 0U;

    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;

    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_WRITEIB_SID, \
                                (uint8)SPI_E_UNINIT );
        RetResult = (Std_ReturnType)E_NOT_OK;
        #endif
    }
    else if(Channel >= SPI_TOTAL_CHANNEL)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_WRITEIB_SID, \
                                (uint8)SPI_E_PARAM_CHANNEL );
        RetResult = (Std_ReturnType)E_NOT_OK;
        #endif
    }
    else
    {
        if(Spi_ConfigPtr->ChannelConfiguration[Channel].ChannelBufferType != IB)/* polyspace RTE:NIV,IDP */
        {
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            SchM_Enter_Spi_EXCLUSIVE_AREA_04();  /* Critical region protection */
            if(DataBufferPtr == NULL_PTR)
            {
                if(Spi_ConfigPtr->ChannelConfiguration[Channel].DataWidth <= (uint8)0x08U)
                {
                    for(Spi_ArrIndex = 0; Spi_ArrIndex < Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize; Spi_ArrIndex++)
                    {
                        *(((uint8 *)Spi_ConfigPtr->ChannelConfiguration[Channel].WriteBuffer) + Spi_ArrIndex) \
                            = (uint8)Spi_ConfigPtr->ChannelConfiguration[Channel].DefaultValue;
                    }
                }
                else if(Spi_ConfigPtr->ChannelConfiguration[Channel].DataWidth <= (uint8)0x10U)
                {
                    for(Spi_ArrIndex = 0; Spi_ArrIndex < Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize; Spi_ArrIndex++)
                    {
                        *(((uint16 *)Spi_ConfigPtr->ChannelConfiguration[Channel].WriteBuffer) + Spi_ArrIndex) \
                            = (uint16)Spi_ConfigPtr->ChannelConfiguration[Channel].DefaultValue;
                    }
                }
                else if(Spi_ConfigPtr->ChannelConfiguration[Channel].DataWidth <= (uint8)0x20U)
                {
                    for(Spi_ArrIndex = 0; Spi_ArrIndex < Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize; Spi_ArrIndex++)
                    {
                        *(((uint32 *)Spi_ConfigPtr->ChannelConfiguration[Channel].WriteBuffer) + Spi_ArrIndex) \
                            = SPI_DATA_REVERSE((uint32)Spi_ConfigPtr->ChannelConfiguration[Channel].DefaultValue);
                    }
                }
                else
                {
                    /* do nothing */
                }
            }
            else
            {
                if(Spi_ConfigPtr->ChannelConfiguration[Channel].DataWidth <= (uint8)0x08U)/* polyspace RTE:NIV,IDP */
                {
                    for(Spi_ArrIndex = 0; Spi_ArrIndex < Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize; Spi_ArrIndex++)/* polyspace RTE:NIV,IDP */
                    {
                        *(((uint8 *)Spi_ConfigPtr->ChannelConfiguration[Channel].WriteBuffer) + Spi_ArrIndex) /* polyspace RTE:NIP,IDP */
                            = *(((uint8 *)DataBufferPtr) + Spi_ArrIndex);
                    }
                }
                else if(Spi_ConfigPtr->ChannelConfiguration[Channel].DataWidth <= (uint8)0x10U)      /* polyspace RTE:IDP */
                {
                    for(Spi_ArrIndex = 0; Spi_ArrIndex < Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize; Spi_ArrIndex++)/* polyspace RTE:NIV,IDP */
                    {
                        *(((uint16 *)Spi_ConfigPtr->ChannelConfiguration[Channel].WriteBuffer) + Spi_ArrIndex) /* polyspace RTE:NIP,IDP */
                            = *(((uint16 *)DataBufferPtr) + Spi_ArrIndex);
                    }
                }
                else if(Spi_ConfigPtr->ChannelConfiguration[Channel].DataWidth <= (uint8)0x20U)  /* polyspace RTE:IDP */
                {
                    Spi_DataReverse( (uint8*)DataBufferPtr,
                                     (uint8 *)Spi_ConfigPtr->ChannelConfiguration[Channel].WriteBuffer,/* polyspace RTE:NIP,IDP */
                                    (uint32)Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize);/* polyspace RTE:NIV,IDP */
                }
                else
                {
                    /* do nothing */
                }
            }
            SchM_Exit_Spi_EXCLUSIVE_AREA_04();  /* Critical region protection */
            RetResult = (Std_ReturnType)E_OK;
        }
    }
    return (Std_ReturnType)RetResult;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

/* [SWS_Spi_00304] The operation Spi_WriteIB is Re-entrant.() */
/* [SWS_Spi_00305] When the API Spi_WriteIB command has been accepted the function returns the value E_OK.() */
/* [SWS_Spi_00306] When the API Spi_WriteIB command has not been accepted the function returns the value E_NOT_OK.() */
/* [SWS_Spi_00307] The function Spi_WriteIB provides the service for writing one or more data to an IB SPI Handler/Driver Channel by the respective parameter.() */
/* [SWS_Spi_00018] The function Spi_WriteIB shall write one or more data to an IB SPI Handler/Driver Channel specified by the respective parameter.(SRS_Spi_12101, SRS_Spi_12153) */
/* [SWS_Spi_00024] The function Spi_WriteIB shall take over the given parameters, and save the pointed data to the internal buffer defined with the function Spi_Init.() */
/* [SWS_Spi_00023] If the given parameter "DataBufferPtr" is null, the function Spi_WriteIB shall assume that the data to be transmitted is not relevant and the default transmit value of the given channel shall be used instead */
/* [SWS_Spi_00137] The function Spi_WriteIB shall be pre-compile time configurable by the parameter SpiChannelBuffersAllowed. This function is only relevant for Channels with IB.() */


/* [SWS_Spi_00178] */
/* Service to transmit data on the SPI bus. */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    VAR(Std_ReturnType, SPI_VAR) RetResult = (Std_ReturnType)E_OK;

    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;
    P2CONST(Spi_SequenceCfgType, SPI_VAR, SPI_APPL_CONST) SequenceConfig;
    P2CONST(Spi_JobCfgType, SPI_VAR, SPI_APPL_CONST) JobConfig;
    P2CONST(Spi_ChannelCfgType, SPI_VAR, SPI_APPL_CONST) ChannelConfig;

    VAR(Spi_JobType, SPI_VAR) JobIndex;
    VAR(Spi_ChannelType, SPI_VAR) ChannelIndex;

    #if (SPI_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint8, SPI_VAR) Spi_CoreID = (uint8)Spi_GetCoreID();
    #endif

    SchM_Enter_Spi_EXCLUSIVE_AREA_05();  /* Critical region protection */
    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError( (uint16)SPI_MODULE_ID, \
                               (uint8)SPI_INSTANCE_ID, \
                               (uint8)SPI_ASYNCTRANSMIT_SID, \
                               (uint8)SPI_E_UNINIT );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else if(Sequence >= SPI_TOTAL_SEQUENCE)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_ASYNCTRANSMIT_SID, \
                                (uint8)SPI_E_PARAM_SEQ );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if(Spi_gSeqStatus[Sequence] == SPI_SEQ_PENDING)
        {
            (void)Det_ReportRuntimeError ( (uint16)SPI_MODULE_ID, \
                                           (uint8)SPI_INSTANCE_ID, \
                                           (uint8)SPI_ASYNCTRANSMIT_SID, \
                                           (uint8)SPI_E_SEQ_PENDING );
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {

            SequenceConfig = (Spi_SequenceCfgType *)&Spi_ConfigPtr->SequenceConfiguration[Sequence];

            for(JobIndex = 0; JobIndex < SequenceConfig->NoOfJobs; JobIndex++)/* polyspace RTE:NIV,IDP */
            {
                if((Spi_gJobStatus[SequenceConfig->JobList[JobIndex]] == SPI_JOB_QUEUED) /* polyspace RTE:OBAI,NIV,NIP,IDP */
                    || (Spi_gJobStatus[SequenceConfig->JobList[JobIndex]] == SPI_JOB_PENDING))   /* polyspace RTE:IDP */
                {
                    break;
                }

                JobConfig = &Spi_ConfigPtr->JobConfiguration[SequenceConfig->JobList[JobIndex]];     /* polyspace RTE:IDP */

                if(
                    #if (SPI_MULTI_CORE_SUPPORT == STD_ON)
                    (Spi_CoreID != Spi_ConfigPtr->DeviceMap[JobConfig->HwUnit]) ||/* polyspace RTE:NIV,IDP */
                    #endif
                    (Spi_gHWUnitStatus[JobConfig->HwDeviceIdx] == SPI_UNINIT))/* polyspace RTE:OBAI,NIV,IDP */
                {
                    break;
                }

                for(ChannelIndex = 0; ChannelIndex < JobConfig->NoOfChannels; ChannelIndex++)/* polyspace RTE:NIV */
                {
                    ChannelConfig = &Spi_ConfigPtr->ChannelConfiguration[JobConfig->ChannelList[ChannelIndex]];/* polyspace RTE:NIV,NIP,IDP */
                    if(ChannelConfig->ChannelBufferType == EB)/* polyspace RTE:NIV,IDP */
                    {
                        if(ChannelConfig->EB_Buffer->Length == 0U)/* polyspace RTE:NIV,NIP,IDP */
                        {
                            #if (SPI_DEV_ERROR_DETECT == STD_ON)
                            (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                                    (uint8)SPI_INSTANCE_ID, \
                                                    (uint8)SPI_ASYNCTRANSMIT_SID, \
                                                    (uint8)SPI_E_PARAM_EB_UNIT);
                            #endif
                            break;
                        }
                        else
                        {
                            if(ChannelConfig->DataWidth > 16U)/* polyspace RTE:NIV */
                            {
                                if(ChannelConfig->EB_Buffer->WriteBuffer != NULL_PTR)/* polyspace RTE:NIP */
                                {
                                    Spi_DataReverse( (uint8*)ChannelConfig->EB_Buffer->WriteBuffer,
                                                    (uint8*)ChannelConfig->EB_Buffer->WriteBufferReverse,/* polyspace RTE:NIP */
                                                    (uint32)ChannelConfig->EB_Buffer->Length);
                                }
                            }
                        }

                    }
                }
                if(ChannelIndex != JobConfig->NoOfChannels)
                {
                    break;
                }
            }

            if(JobIndex != SequenceConfig->NoOfJobs)
            {
                RetResult = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /* Locking Sequence */
                Spi_gSeqStatus[Sequence] = SPI_SEQ_PENDING;
                /* Locking Job of Sequence */
                for(JobIndex = 0; JobIndex < SequenceConfig->NoOfJobs; JobIndex++)
                {
                    Spi_gJobStatus[SequenceConfig->JobList[JobIndex]] = SPI_JOB_QUEUED;/* polyspace RTE:OBAI,NIV,NIP,IDP */
                }
                /* Enqueue */
                Spi_InsSequence(SequenceConfig);
            }
        }
    }
    SchM_Exit_Spi_EXCLUSIVE_AREA_05();  /* Critical region protection */
    return (Std_ReturnType)RetResult;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif
/* [SWS_Spi_00308] The operation Std_ReturnType Spi_AsyncTransmit( Spi_SequenceType Sequence ) is Re-entrant.() */
/* [SWS_Spi_00309] When the API Spi_AsyncTransmit command has been accepted the function shall return the value E_OK.() */
/* [SWS_Spi_00310] When the API Spi_AsyncTransmit command has not been accepted the function shall return the value E_NOT_OK.() */
/* [SWS_Spi_00311] The function Spi_AsyncTransmit provides service to transmit data on the SPI bus.() */
/* [SWS_Spi_00020] The function Spi_AsyncTransmit shall take over the given parameter, initiate a transmission, set the SPI Handler/Driver status to SPI_BUSY, set the sequence result to SPI_SEQ_PENDING and return. (SRS_Spi_12099, SRS_Spi_12101, SRS_Spi_12103) */
/* [SWS_Spi_00194] When the function Spi_AsyncTransmit is called, shall take over the given parameter and set the Job status to SPI_JOB_QUEUED, which can be obtained by calling the API service Spi_GetJobResult.() */
/* [SWS_Spi_00157] When the function Spi_AsyncTransmit is called, the SPI Handler/Driver shall handle the Job results. Result shall be SPI_JOB_PENDING when the transmission of Jobs is started.() */
/* [SWS_Spi_00292] When the function Spi_AsyncTransmit is called, the SPI Handler/Driver shall handle the Job results. Result shall be SPI_JOB_OK when the transmission of Jobs is success.() */
/* [SWS_Spi_00293] When the function Spi_AsyncTransmit is called, the SPI Handler/Driver shall handle the Job results. Result shall be SPI_JOB_FAILED when the transmission of Jobs is failed.() */
/* [SWS_Spi_00081] When the function Spi_AsyncTransmit is called and the requested Sequence is already in state SPI_SEQ_PENDING, the SPI Handler/Driver shall not take in account this new request and this function shall return with value E_NOT_OK, in this case.() */
/* [SWS_Spi_00266] When the function Spi_AsyncTransmit is called and the requested Sequence is already in state SPI_SEQ_PENDING the SPI Handler/Driver shall report the SPI_E_SEQ_PENDING error according to [SWS_BSW_00042] and [SWS_BSW_00045].() */
/* [SWS_Spi_00086] When the function Spi_AsyncTransmit is called and the requested Sequence shares Jobs with another sequence that is in the state SPI_SEQ_PENDING, 
 the SPI Handler/Driver shall not take into account this new request and this function shall return the value E_NOT_OK. In this case and according to [SWS_BSW_00042] 
 and [SWS_BSW_00045], the SPI Handler/Driver shall report the SPI_E_SEQ_PENDING error.()*/
/* [SWS_Spi_00035] When the function Spi_AsyncTransmit is used with EB and the source data pointer has been provided as NULL using the Spi_SetupEB method, the default transmit data configured for each channel shall be transmitted. (See also [SWS_SPI_00028])(SRS_Spi_12200, SRS_Spi_12201) */
/* [SWS_Spi_00036] When the function Spi_AsyncTransmit is used with EB and the destination data pointer has been provided as NULL using the Spi_SetupEB method, the SPI Handler/Driver shall ignore receiving data (See also [SWS_Spi_00030])() */
/* [SWS_Spi_00055] When the function Spi_AsyncTransmit is used for a Sequence with linked Jobs, the function shall transmit from the first Job up to the last Job in the sequence.(SRS_Spi_12181) */
/* [SWS_Spi_00057]  At the end of a sequence transmission initiated by the function Spi_AsyncTransmit and if configured, the SPI Handler/Driver shall invoke the sequence notification callback function after the last Job end notification if this one is also configured.(SRS_SPAL_00157, SRS_Spi_12108) */
/* [SWS_Spi_00133] The function Spi_AsyncTransmit is pre-compile time selectable by the configuration parameter SpiLevelDelivered. This function is only relevant for LEVEL 1 and LEVEL 2.() */
/* [SWS_Spi_00173] The SPI Handler/Driver's environment shall call the function Spi_AsyncTransmit after a function call of Spi_SetupEB for EB Channels or a function call of Spi_WriteIB for IB Channels but before the function call Spi_ReadIB.() */

/* [SWS_Spi_00179] */
/* Service for reading synchronously one or more data from an IB SPI Handler/Driver Channel specified by parameter. */
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB(
    VAR(Spi_ChannelType, AUTOMATIC) Channel,
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr)
{
    VAR(Std_ReturnType, SPI_VAR) RetResult = (Std_ReturnType)E_OK;
    VAR(uint32, SPI_VAR)Spi_ArrIndex = 0U;

    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;
    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_READIB_SID, \
                                (uint8)SPI_E_UNINIT );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else if(Channel >= SPI_TOTAL_CHANNEL)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_READIB_SID, \
                                (uint8)SPI_E_PARAM_CHANNEL );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if(Spi_ConfigPtr->ChannelConfiguration[Channel].ChannelBufferType != IB)/* polyspace RTE:NIV,IDP */
        {
            #if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError( (uint16)SPI_MODULE_ID, \
                                   (uint8)SPI_INSTANCE_ID, \
                                   (uint8)SPI_READIB_SID, \
                                   (uint8)SPI_E_PARAM_CHANNEL );
            #endif
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            if(DataBufferPtr == NULL_PTR)
            {
                #if (SPI_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                        (uint8)SPI_INSTANCE_ID, \
                                        (uint8)SPI_READIB_SID, \
                                        (uint8)SPI_E_PARAM_POINTER );
                #endif
                RetResult = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                SchM_Enter_Spi_EXCLUSIVE_AREA_06();  /* Critical region protection */
                if(Spi_ConfigPtr->ChannelConfiguration[Channel].DataWidth <= (uint8)0x08U)/* polyspace RTE:NIV,IDP   */
                {
                    for(Spi_ArrIndex = 0; Spi_ArrIndex < Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize; Spi_ArrIndex++)/* polyspace RTE:NIV,IDP */
                    {
                        *(((uint8 *)DataBufferPtr) + Spi_ArrIndex) \
                            = *(((uint8 *)Spi_ConfigPtr->ChannelConfiguration[Channel].ReadBuffer) + Spi_ArrIndex);/* polyspace RTE:NIV,NIP,IDP */
                    }
                }
                else if(Spi_ConfigPtr->ChannelConfiguration[Channel].DataWidth <= (uint8)0x10U)      /* polyspace RTE:IDP */
                {
                    for(Spi_ArrIndex = 0; Spi_ArrIndex < Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize; Spi_ArrIndex++)/* polyspace RTE:NIV,IDP */
                    {
                       *(((uint16 *)DataBufferPtr) + Spi_ArrIndex) \
                            = *(((uint16 *)Spi_ConfigPtr->ChannelConfiguration[Channel].ReadBuffer + Spi_ArrIndex));/* polyspace RTE:NIV,NIP,IDP */
                    }
                }
                else if(Spi_ConfigPtr->ChannelConfiguration[Channel].DataWidth <= (uint8)0x20U)  /* polyspace RTE:IDP */
                {
                    for(Spi_ArrIndex = 0; Spi_ArrIndex < Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize; Spi_ArrIndex++)/* polyspace RTE:NIV,IDP */
                    {
                       *(((uint32 *)DataBufferPtr) + Spi_ArrIndex) \
                            = *(((uint32 *)Spi_ConfigPtr->ChannelConfiguration[Channel].ReadBuffer + Spi_ArrIndex));/* polyspace RTE:NIV,NIP,IDP */
                    }
                }
                else
                {
                    /* do nothing */
                }
                SchM_Exit_Spi_EXCLUSIVE_AREA_06();  /* Critical region protection */
                RetResult = (Std_ReturnType)E_OK;
            }
        }
    }
    return (Std_ReturnType)RetResult;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif
/* [SWS_Spi_00312] The operation Spi_ReadIB is Re-entrant.() */
/* [SWS_Spi_00313] The function Spi_ReadIB return values E_OK: read command has been accepted.() */
/* [SWS_Spi_00314] The function Spi_ReadIB return values E_NOT_OK: read command has not been accepted.() */
/* [SWS_Spi_00315] The function Spi_ReadIB provides the service for reading synchronously one or more data from an IB SPI Handler/Driver Channel specified by parameter.() */
/* [SWS_Spi_00016] The function Spi_ReadIB shall read synchronously one or more data from an IB SPI Handler/Driver Channel specified by the respective parameter.(SRS_Spi_12099, SRS_Spi_12152) */
/* [SWS_Spi_00027] The SPI Handler/Driver environment shall call the function Spi_ReadIB after a Transmit method call to have relevant data within IB Channel.() */
/* [SWS_Spi_00138] The function Spi_ReadIB is pre-compile time configurable by the parameter SpiChannelBuffersAllowed. This function is only relevant for Channels with IB.() */

/* [SWS_Spi_00180] */
/* Service to setup the buffers and the length of data for the EB SPI Handler/Driver Channel specified. */
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB(
    VAR(Spi_ChannelType, AUTOMATIC) Channel,
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_CONST) SrcDataBufferPtr,
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
    VAR(Spi_NumberOfDataType, AUTOMATIC) Length )
{
    VAR(Std_ReturnType, SPI_VAR) RetResult = (Std_ReturnType)E_OK;
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;

    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_SETUPEB_SID, \
                                (uint8)SPI_E_UNINIT );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else if(Channel >= SPI_TOTAL_CHANNEL)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_SETUPEB_SID, \
                                (uint8)SPI_E_PARAM_CHANNEL );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else if((Length == (Spi_NumberOfDataType)0U) ||
            (Length > Spi_ConfigPtr->ChannelConfiguration[Channel].BufferSize))/* polyspace RTE:NIV,IDP */
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_SETUPEB_SID, \
                                (uint8)SPI_E_PARAM_LENGTH );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if(Spi_ConfigPtr->ChannelConfiguration[Channel].ChannelBufferType != EB)/* polyspace RTE:NIV,IDP */
        {
            #if (SPI_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                    (uint8)SPI_INSTANCE_ID, \
                                    (uint8)SPI_SETUPEB_SID, \
                                    (uint8)SPI_E_PARAM_CHANNEL );
            #endif
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            SchM_Enter_Spi_EXCLUSIVE_AREA_07();  /* Critical region protection */
            Spi_ConfigPtr->ChannelConfiguration[Channel].EB_Buffer->Length /* polyspace RTE:NIP,IDP */
                = (Spi_NumberOfDataType)Length;
            Spi_ConfigPtr->ChannelConfiguration[Channel].EB_Buffer->WriteBuffer /* polyspace RTE:NIP,IDP */
                = (Spi_DataBufferType *)SrcDataBufferPtr;
            Spi_ConfigPtr->ChannelConfiguration[Channel].EB_Buffer->ReadBuffer /* polyspace RTE:NIP,IDP */
                = (Spi_DataBufferType *)DesDataBufferPtr;
            RetResult = (Std_ReturnType)E_OK;
            SchM_Exit_Spi_EXCLUSIVE_AREA_07();  /* Critical region protection */
        }
    }
    return (Std_ReturnType)RetResult;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif
/* [SWS_Spi_00316] The operation Spi_SetupEB is Re-entrant.() */
/* [SWS_Spi_00317] Return values of the function Spi_SetupEB are E_OK: Setup command has been accepted and E_NOT_OK: Setup command has not been accepted.() */
/* [SWS_Spi_00318] The function Spi_SetupEB provides the service to setup the buffers and the length of data for the EB SPI Handler/Driver Channel specified.() */
/* [SWS_Spi_00058] The function Spi_SetupEB shall set up the buffers and the length of data for the specific EB SPI Handler/Driver Channel.(SRS_Spi_12103) */
/* [SWS_Spi_00067] The function Spi_SetupEB shall update the buffer pointers and length attributes of the specified Channel with the provided values.(SRS_Spi_12103) */
/* [SWS_Spi_00028] When the SPI Handler/Driver environment is calling the function Spi_SetupEB with the parameter SrcDataBufferPtr being a Null pointer, the function shall transmit the default transmit value configured for the channel after a Transmit method is requested. (See also [SWS_Spi_00035])() */
/* [SWS_Spi_00030] When the function Spi_SetupEB is called with the parameter DesDataBufferPtr being a Null pointer, the SPI Handler/Driver shall ignore the received data after a Transmit method is requested.(See also [SWS_Spi_00036])() */
/* [SWS_Spi_00037] The SPI Handler/Driver environment shall call the Spi_SetupEB function once for each Channel with EB declared before the SPI Handler/Driver environment calls a Transmit method on them.() */
/* [SWS_Spi_00139] The function Spi_SetupEB is pre-compile time configurable by the parameter SpiChannelBuffersAllowed. This function is only relevant for Channels with EB.() */

/* [SWS_Spi_00181] */
/* Service returns the SPI Handler/Driver software module status. */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void)
{
    VAR(Spi_StatusType, SPI_VAR)Status;
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;

    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_GETSTATUS_SID, \
                                (uint8)SPI_E_UNINIT );
        #endif
        Status = (Spi_StatusType)SPI_UNINIT;
    }
    else
    {
        Status = (Spi_StatusType)Spi_gStatus;
    }
    return (Spi_StatusType)Status;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/* [SWS_Spi_00319] The operation Spi_GetStatus is Re-entrant.() */
/* [SWS_Spi_00320] The function Spi_GetStatus returns the SPI Handler/Driver software module status.() */
/* [SWS_Spi_00025] The function Spi_GetStatus shall return the SPI Han-dler/Driver software module status.(SRS_SPAL_12064, SRS_Spi_12104) */


/* [SWS_Spi_00182] */
/* This service returns the last transmission result of the specified Job. */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult(VAR(Spi_JobType, AUTOMATIC) Job )
{
    VAR(Spi_JobResultType, SPI_VAR) JobStatus = (Spi_JobResultType)SPI_JOB_OK;
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;

    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_GETJOBRESULT_SID, \
                                (uint8)SPI_E_UNINIT );
        #endif
    }
    else if(Job >= SPI_TOTAL_JOB)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_GETJOBRESULT_SID, \
                                (uint8)SPI_E_PARAM_JOB );
        #endif
    }
    else
    {
        JobStatus = (Spi_JobResultType)Spi_gJobStatus[Job];
    }
    return (Spi_JobResultType)JobStatus;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/* [SWS_Spi_00321] The operation Spi_GetJobResult is Re-entrant.() */
/* [SWS_Spi_00322] The function Spi_GetJobResult service returns the last transmission result of the specified Job.() */
/* [SWS_Spi_00026] The function Spi_GetJobResult shall return the last transmission result of the specified Job. (SRS_SPAL_00157, SRS_Spi_12104) */
/* [SWS_Spi_00038] The SPI Handler/Driver environment shall call the function Spi_GetJobResult to inquire whether the Job transmission has succeeded (SPI_JOB_OK) or failed (SPI_JOB_FAILED).(SRS_SPAL_00157) */


/* [SWS_Spi_00183] */
/* This service returns the last transmission result of the specified Sequence. */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    VAR(Spi_SeqResultType, SPI_VAR) SequenceStatus = (Spi_SeqResultType)SPI_SEQ_OK;
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;
    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_GETSEQUENCERESULT_SID, \
                                (uint8)SPI_E_UNINIT );
        #endif
    }
    else if(Sequence >= SPI_TOTAL_SEQUENCE)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_GETSEQUENCERESULT_SID, \
                                (uint8)SPI_E_PARAM_SEQ );
        #endif
    }
    else
    {
        SequenceStatus = (Spi_SeqResultType)Spi_gSeqStatus[Sequence];
    }
    return (Spi_SeqResultType)SequenceStatus;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/* [SWS_Spi_00323] The operation Spi_GetSequenceResult is Re-entrant.() */
/* [SWS_Spi_00324] The function Spi_GetSequenceResult shall return the last transmission result of the specified Sequence.( SRS_SPAL_00157, SRS_Spi_12104) */
/* [SWS_Spi_00042] The SPI Handler/Driver environment shall call the function Spi_GetSequenceResult to inquire whether the full Sequence transmission has succeeded (SPI_SEQ_OK) or failed (SPI_SEQ_FAILED).(SRS_SPAL_00157, SRS_Spi_12170) */

/* [SWS_Spi_00184] */
/* This service returns the version information of this module. */
#if (SPI_VERSION_INFO_API == STD_ON)
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE) Spi_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) versioninfo \
)
{
    if (NULL_PTR == versioninfo)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_GETVERSIONINFO_SID, \
                                (uint8)SPI_E_PARAM_POINTER );
        #endif
    }
    else
    {
        versioninfo->vendorID = (uint16)SPI_VENDOR_ID;
        versioninfo->moduleID = (uint16)SPI_MODULE_ID;
        versioninfo->sw_major_version = (uint8)SPI_AR_RELEASE_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)SPI_AR_RELEASE_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)SPI_AR_PATCH_VER;
    }
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif
/* [SWS_Spi_00371] If Det is enabled, the parameter versioninfo shall be checked for being NULL. The error SPI_E_PARAM_POINTER shall be reported in case the value is a NULL pointer.() */

/* [SWS_Spi_00185] */
/* Service to transmit data on the SPI bus */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    VAR(Std_ReturnType, SPI_VAR) RetResult = (Std_ReturnType)E_OK;
    // Getting the global configuration
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;
    // Sequence Configuration
    P2CONST(Spi_SequenceCfgType, AUTOMATIC, SPI_APPL_CONST) SequenceConfig;
    // Job Configuration
    P2CONST(Spi_JobCfgType, AUTOMATIC, SPI_APPL_CONST) JobConfig;
    // Channel Configuration
    P2CONST(Spi_ChannelCfgType, AUTOMATIC, SPI_APPL_CONST) ChannelConfig;
    // Job Index
    VAR(Spi_JobType, AUTOMATIC) JobIndex;
    // Channel Index
    VAR(Spi_ChannelType, AUTOMATIC) ChannelIndex;
    #if (SPI_MULTI_CORE_SUPPORT == STD_ON)
    // Current Core ID
    VAR(uint8, SPI_VAR) Spi_CoreID = (uint8)Spi_GetCoreID();
    #endif
    SchM_Enter_Spi_EXCLUSIVE_AREA_08();  /* Critical region protection */
    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_SYNCTRANSMIT_SID, \
                                (uint8)SPI_E_UNINIT );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else if(Sequence >= SPI_TOTAL_SEQUENCE)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_SYNCTRANSMIT_SID, \
                                (uint8)SPI_E_PARAM_SEQ );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
        if(Spi_gStatus != SPI_IDLE)
        {
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        #endif
        {
            if(Spi_gSeqStatus[Sequence] == SPI_SEQ_PENDING)
            {
                (void)Det_ReportRuntimeError ( (uint16)SPI_MODULE_ID, \
                                               (uint8)SPI_INSTANCE_ID, \
                                               (uint8)SPI_SYNCTRANSMIT_SID, \
                                               (uint8)SPI_E_SEQ_IN_PROCESS );
                RetResult = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
                /* Set the current status of SPI */
                Spi_gStatus = (Spi_StatusType)SPI_BUSY;
                #endif
                /* Get current Sequence config */
                SequenceConfig = (Spi_SequenceCfgType *)&Spi_ConfigPtr->SequenceConfiguration[Sequence];
                /* Set the current status of Sequence */
                Spi_gSeqStatus[Sequence] = (Spi_SeqResultType)SPI_SEQ_PENDING;
                /* Loop Job */
                for(JobIndex = 0; JobIndex < SequenceConfig->NoOfJobs; JobIndex++)/* polyspace RTE:NIV,IDP */
                {
                    if((Spi_gJobStatus[SequenceConfig->JobList[JobIndex]] == SPI_JOB_QUEUED) /* polyspace RTE:OBAI,NIV,NIP,IDP */
                            || (Spi_gJobStatus[SequenceConfig->JobList[JobIndex]] == SPI_JOB_PENDING))
                    {
                        RetResult = (Std_ReturnType)E_NOT_OK;
                        /* The current job failed, exit the loop. */
                        break;
                    }
                    else
                    {
                        /* Get current Job config */
                        JobConfig = (Spi_JobCfgType *)&Spi_ConfigPtr->JobConfiguration[SequenceConfig->JobList[JobIndex]];

                        if(
                            #if (SPI_MULTI_CORE_SUPPORT == STD_ON)
                            ( Spi_CoreID != Spi_ConfigPtr->DeviceMap[JobConfig->HwUnit]) || /* polyspace RTE:NIV,IDP */
                            #endif
                            (Spi_gHWUnitStatus[JobConfig->HwDeviceIdx] != SPI_IDLE) )/* polyspace RTE:OBAI,NIV,IDP */
                        {
                            RetResult = (Std_ReturnType)E_NOT_OK;
                        }
                        else
                        {
                            for(ChannelIndex = 0; ChannelIndex < JobConfig->NoOfChannels; ChannelIndex++)/* polyspace RTE:NIV */
                            {
                                ChannelConfig = &Spi_ConfigPtr->ChannelConfiguration[JobConfig->ChannelList[ChannelIndex]];/* polyspace RTE:NIV,NIP,IDP */

                                if(ChannelConfig->ChannelBufferType == EB)/* polyspace RTE:NIV,IDP */
                                {
                                    if(ChannelConfig->EB_Buffer->Length == 0U)/* polyspace RTE:NIV,NIP,IDP */
                                    {
                                        RetResult = (Std_ReturnType)E_NOT_OK;
                                        #if (SPI_DEV_ERROR_DETECT == STD_ON)
                                        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                                                (uint8)SPI_INSTANCE_ID, \
                                                                (uint8)SPI_SYNCTRANSMIT_SID, \
                                                                (uint8)SPI_E_PARAM_EB_UNIT);
                                        #endif
                                        break;
                                    }
                                    else
                                    {
                                        if(ChannelConfig->DataWidth > 16U)/* polyspace RTE:NIV */
                                        {
                                            if(ChannelConfig->EB_Buffer->WriteBuffer != NULL_PTR)/* polyspace RTE:NIP */
                                            {
                                                Spi_DataReverse( (uint8*)ChannelConfig->EB_Buffer->WriteBuffer,
                                                                 (uint8*)ChannelConfig->EB_Buffer->WriteBufferReverse,/* polyspace RTE:NIP */
                                                                 (uint32)ChannelConfig->EB_Buffer->Length);
                                            }
                                        }
                                    }
                                } /* EB */
                            } /* Channel Loop End */

                            if(RetResult != (Std_ReturnType)E_OK)
                            {
                                /* Do nothing */
                            }
                            else
                            {
                                Spi_gHWUnitStatus[JobConfig->HwDeviceIdx] = (Spi_StatusType)SPI_BUSY;

                                Spi_gJobStatus[SequenceConfig->JobList[JobIndex]] = (Spi_JobResultType)SPI_JOB_PENDING;

                                /* Transmit */
                                RetResult = (Std_ReturnType)Spi_Wrap_SyncTransmit(JobConfig);

                                if(RetResult == (Std_ReturnType)E_NOT_OK)
                                {
                                    Spi_gJobStatus[SequenceConfig->JobList[JobIndex]] = (Spi_JobResultType)SPI_JOB_FAILED;
                                }
                                else
                                {
                                    if(JobConfig->JobEndNotification != NULL_PTR)/* polyspace RTE:NIP */
                                    {
                                        (void)JobConfig->JobEndNotification();/* polyspace RTE:COR */
                                    }
                                    Spi_gJobStatus[SequenceConfig->JobList[JobIndex]] = (Spi_JobResultType)SPI_JOB_OK;
                                }
                                Spi_gHWUnitStatus[JobConfig->HwDeviceIdx] = (Spi_StatusType)SPI_IDLE;
                            }
                        }
                    }
                } /* Job Loop End */

                /* Restoring sequence state */
                if(RetResult == (Std_ReturnType)E_NOT_OK)
                {
                    Spi_gSeqStatus[Sequence] = (Spi_SeqResultType)SPI_SEQ_FAILED;
                }
                else
                {
                    Spi_gSeqStatus[Sequence] = (Spi_SeqResultType)SPI_SEQ_OK;
                }

                #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
                Spi_gStatus = (Spi_StatusType)SPI_IDLE;
                #endif
            }
        }
    }
    SchM_Exit_Spi_EXCLUSIVE_AREA_08();  /* Critical region protection */
    return (Std_ReturnType)RetResult;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif
/* [SWS_Spi_00327] The operation Spi_SyncTransmit is Re-entrant.() */
/* [SWS_Spi_00328] Return value of the function Spi_SyncTransmit is E_OK: when Transmission command has been accepted.() */
/* [SWS_Spi_00329] Return value of the function Spi_SyncTransmit is E_NOT_OK: When Transmission command has not been accepted.() */
/* [SWS_Spi_00330] The function Spi_SyncTransmit provides the service to transmit data on the SPI bus.() */
/* [SWS_Spi_00134] When the function Spi_SyncTransmit is called, shall take over the given parameter and set the SPI Handler/Driver status to SPI_BUSY can be obtained calling the API service SPI_GetStatus.(SRS_Spi_12152, SRS_Spi_12153, SRS_Spi_12154) */
/* [SWS_Spi_00285] When the function Spi_SyncTransmit is called, shall take over the given parameter and set the Sequence status to SPI_SEQ_PENDING can be obtained calling the API service Spi_GetSequenceResult.() */
/* [SWS_Spi_00286] When the function Spi_SyncTransmit is called, shall take over the given parameter and set the Job status to SPI_JOB_PENDING can be obtained calling the API service Spi_GetJobResult.() */
/* [SWS_Spi_00135] When the function Spi_SyncTransmit is called while a sequence is on transmission and SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT is disabled or another sequence is on transmission on same bus, 
 the SPI Handler/Driver shall not take into account this new transmission request and the function shall return the value E_NOT_OK (see [SWS_Spi_00114]). In this case, the SPI Handler/Driver shall report the SPI_E_SEQ_IN_PROCESS error according to [SWS_BSW_00042] and [SWS_BSW_00045].(SRS_Spi_12093) */
/* [SWS_Spi_00136] The function Spi_SyncTransmit is pre-compile time selectable by the configuration parameter SpiLevelDelivered. This function is only relevant for LEVEL 0 and LEVEL 2.() */

/* [SWS_Spi_00186] */
/* This service returns the status of the specified SPI Hardware microcontroller peripheral. */
#if (SPI_HW_STATUS_API == STD_ON)
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(VAR(Spi_HWUnitType, AUTOMATIC) HwUnit)
{
    VAR(Spi_StatusType, SPI_VAR) HwUnitStatus = (Spi_StatusType)SPI_UNINIT;
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;
    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_GETHWUNITSTATUS_SID, \
                                (uint8)SPI_E_UNINIT );
        #endif
    }
    else if(HwUnit >= SPI_TOTAL_HWDEVICE)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_GETHWUNITSTATUS_SID, \
                                (uint8)SPI_E_PARAM_UNIT );
        #endif
    }
    else
    {
        HwUnitStatus = (Spi_StatusType)Spi_gHWUnitStatus[HwUnit];
    }
    return (Spi_StatusType)HwUnitStatus;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif
/* [SWS_Spi_00331] The operation Spi_GetHWUnitStatus is Re-entrant.() */
/* [SWS_Spi_00332] The function Spi_GetHWUnitStatus service returns the status of the specified SPI Hardware microcontroller peripheral.() */
/* [SWS_Spi_00141] The function Spi_GetHWUnitStatus shall return the status of the specified SPI Hardware microcontroller peripheral.() */
/* [SWS_Spi_00287] The SPI Handler/Driver environment shall call this function to inquire whether the specified SPI Hardware microcontroller peripheral is SPI_IDLE or SPI_BUSY.() */
/* [SWS_Spi_00142] The function Spi_GetHWUnitStatus is pre-compile time configurable On / Off by the configuration parameter SpiHwStatusApi.() */

/* [SWS_Spi_00187] */
/* Service cancels the specified on-going sequence transmission. */
#if (SPI_CANCEL_API == STD_ON)
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE) Spi_Cancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;

    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_CANCEL_SID, \
                                (uint8)SPI_E_UNINIT );
        #endif
    }
    else if(Sequence >= SPI_TOTAL_SEQUENCE)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_CANCEL_SID, \
                                (uint8)SPI_E_PARAM_SEQ );
        #endif
    }
    else
    {
        SchM_Enter_Spi_EXCLUSIVE_AREA_09();     /* polyspace RTE:IDP */ /* Critical region protection */
        if(Spi_gSeqStatus[Sequence] == (Spi_SeqResultType)SPI_SEQ_PENDING)
        {
            Spi_gSeqStatus[Sequence] = (Spi_SeqResultType)SPI_SEQ_CANCELED;
        }
        SchM_Exit_Spi_EXCLUSIVE_AREA_09();  /* Critical region protection */
    }
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif
/* [SWS_Spi_00333] The operation Spi_Cancel is Re-entrant.() */
/* [SWS_Spi_00334] The function Spi_Cancel service cancels the specified ongoing sequence transmission.() */
/* [SWS_Spi_00144] The function Spi_Cancel shall cancel the specified ongoing sequence transmission without cancelling any Job transmission and set the sequence result to SPI_SEQ_CANCELLED.() */
/* [SWS_Spi_00145] When the sequence is cancelled by the function Spi_Cancel and if configured, the SPI Handler/Driver shall call the sequence notification callback function instead of starting a potential next job belonging to it.() */
/* [SWS_Spi_00146] The function Spi_Cancel is pre-compile time configurable On / Off by the configuration parameter SpiCancelApi.() */

/* [SWS_Spi_00188] */
/* Service to set the asynchronous mechanism mode for SPI busses handled asynchronously. */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(VAR(Spi_AsyncModeType, AUTOMATIC) Mode)
{
    VAR(Std_ReturnType, SPI_VAR) RetResult = (Std_ReturnType)E_OK;
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;

    if(Spi_ConfigPtr == NULL_PTR)
    {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError ( (uint16)SPI_MODULE_ID, \
                                (uint8)SPI_INSTANCE_ID, \
                                (uint8)SPI_SETAYNCMODE_SID, \
                                (uint8)SPI_E_UNINIT );
        #endif
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        SchM_Enter_Spi_EXCLUSIVE_AREA_10();  /* Critical region protection */
        if(Spi_gAsyncStatus != SPI_IDLE)
        {
            (void)Det_ReportRuntimeError( (uint16)SPI_MODULE_ID, \
                                          (uint8)SPI_INSTANCE_ID, \
                                          (uint8)SPI_SETAYNCMODE_SID, \
                                          (uint8)SPI_E_SEQ_PENDING );
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Spi_gAsyncMode = (Spi_AsyncModeType)Mode;
            RetResult = (Std_ReturnType)E_OK;
        }
        SchM_Exit_Spi_EXCLUSIVE_AREA_10();  /* Critical region protection */
    }
    return (Std_ReturnType)RetResult;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif
/* [SWS_Spi_00335] The operation Spi_SetAsyncMode is Non Re-entrant.() */
/* [SWS_Spi_00336] Return value of the function Spi_SetAsyncMode is E_OK: Setting command has been done.() */
/* [SWS_Spi_00337] Return value of the function Spi_SetAsyncMode is E_NOT_OK: setting command has not been accepted.() */
/* [SWS_Spi_00338] The function Spi_SetAsyncMode service to set the asynchronous mechanism mode for SPI buses handled asynchronously.() */
/* [SWS_Spi_00152] The function Spi_SetAsyncMode according to the given pa-rameter shall set the asynchronous mechanism mode for SPI channels configured to behave asynchronously.() */
/* [SWS_Spi_00171] If the function Spi_SetAsyncMode is called while the SPI Handler/Driver status is SPI_BUSY and an asynchronous transmission is in progress,
 the SPI Handler/Driver shall not change the AsyncModeType and keep the mode type as it is. The function shall return the value E_NOT_OK.() */
/* [SWS_Spi_00172] If Spi_SetAsyncMode is called while a synchronous transmission is in progress, the SPI Handler/Driver shall set the AsyncModeType according to parameter 'Mode',
 even if the SPI Handler/Driver status is SPI_BUSY. The function shall return the value E_OK.() */
/* [SWS_Spi_00154] The function Spi_SetAsyncMode is pre-compile time selectable by the configuration parameter SpiLevelDelivered. This function is only relevant for LEVEL 2.() */

/* [SWS_Spi_00189] */
/* This function shall polls the SPI interrupts linked to HW Units allocated to the transmission of SPI sequences to enable the evolution of transmission state machine. */
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC (void, SPI_CODE) Spi_MainFunction_Handling(void)
{
    SchM_Enter_Spi_EXCLUSIVE_AREA_11();  /* Critical region protection */
    VAR(uint32, SPI_VAR) Spi_HwIdx;
    P2VAR(Spi_HandleType, SPI_DATA, SPI_APPL_DATA) Spi_HandlePtr;
    #if (SPI_MULTI_CORE_SUPPORT == STD_ON)
    P2CONST(Spi_ConfigType, SPI_DATA, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;
    P2CONST(Spi_JobCfgType, SPI_DATA, SPI_APPL_CONST) JobConfig;
    VAR(uint32, SPI_VAR) Spi_CoreId = Spi_GetCoreID();
    #endif
    for(Spi_HwIdx = 0U; Spi_HwIdx < SPI_TOTAL_HWDEVICE; Spi_HwIdx++)
    {
        if(Spi_gHWUnitStatus[Spi_HwIdx] == SPI_BUSY)
        {
            Spi_HandlePtr = &Spi_gHandle[Spi_HwIdx];
            #if (SPI_MULTI_CORE_SUPPORT == STD_ON)
            JobConfig = &Spi_ConfigPtr->JobConfiguration[/* polyspace RTE:IDP */
                Spi_ConfigPtr->SequenceConfiguration[/* polyspace RTE:IDP */
                    Spi_HandlePtr->Spi_AsyncSchePtr->SequenceId ].JobList[0U] ];/* polyspace RTE:NIV,NIP,IDP */
            if(Spi_CoreId == (uint32)Spi_ConfigPtr->DeviceMap[JobConfig->HwUnit])/* polyspace RTE:NIV,IDP */
            #endif
            {
                Spi_Wrap_MainFunc( Spi_HandlePtr );
            }
        }
    }
    SchM_Exit_Spi_EXCLUSIVE_AREA_11();  /* Critical region protection */
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif
