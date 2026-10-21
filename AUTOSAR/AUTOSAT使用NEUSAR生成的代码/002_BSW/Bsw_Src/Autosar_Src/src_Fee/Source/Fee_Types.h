/*
********************************************************************************
*
* File name: Fee_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date : Baowanglong/2020.05.07
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: HanBY/2020.11.02
* Change: Modify code format.
* Cause: Optimization.
********************************************************************************
* Version: 3.2
* Author/Date: HanBY/2022.04.26
* Change: 1. Move some type defines from Fee_Cfg.h to this file.
*         2. Add type define Fee_JobType_en.
* Cause: Optimization.
********************************************************************************
* Version: 3.3
* Author/Date: GaoXY/2023.03.21
* Change: 1.Back up block head and sector head.
*         2.Recover block head and sector head,when Fls driver return Failed.
* Cause: Bugfix.
********************************************************************************
* Version: 3.4
* Author/Date: LiDY/2023.05.05
* Change: Add state machine for error retries.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiDaY/2024.01.15
* Change: 1.Split the state machine into Fee_JobType and Fee_SwapJobType.
*         2.Add Fee_SectorStatusType,Fee_SectorSwapStateType,Fee_SwapRequestType
*           enumeration.
*         3.Add Fee_ScanManagerInfoType Fee_JobManagerInfoType Fee_SwapManagerInfoType
*           Fee_PartitionCurrentInfoSnapType structural.
*         4.Changed Fee_PartitionCurrentInfoType Fee_SectorCurrentInfoType structural.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiDaY/2024.04.08
* Change: 1.Add enum member of Fee_SectorStatusType and Fee_SwapRequestType.
*         2.Add enum of Fee_ImmWrtieStateType.
*         3.Add member variable of structure Fee_SectorCurrentInfoType
*           Fee_PartitionCurrentInfoType Fee_SwapManagerInfoType Fee_ScanManagerInfoType
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiDaY/2024.07.24
* Change: 1.Change the enumeration order of Fee_SectorStatus Type,
*           Fee_immWriteSitType, and Fee_SwapRequestType.
*         2.Change the Fee_SlockHeadType type to Fee_SlockHeadRomType for building
*           data that needs to be written to Flash, and add Fee_SlockHeadRamType
*           for storing data that needs to be retained in Ram.
*         3.The Fee_SectorCurrentInfoType structure has added a SectionWriteFailed
*           Counter member to record the number of consecutive failures in writing
*           the Block header to each sector.
*         4.Change the Fee_SlockHeadType type of the Fee_SlockHead_Syn member in
*           the Fee_SlockCfgType structure to Fee_SlockHeadRamType; Change the
*           Fee_SwapMnagerInfoType type of the SwapBlockHeadBackup member in the
*           Fee_SwapMnagerInfoType structure to Fee_SlockHeadRomType; Change the
*           Fee_SlockHeadType type of the JobBlockHeadBackup member in the
*           Fee_JobManagerial InfoType structure to Fee_SlockHeadRomType.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiDaY/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: LiDaY/2024.08.26
* Change: Change copyright information.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: LiDaY/2025.02.18
* Change: Optimize header file references.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: WangLX/2025.02.18
* Change: Add the enum of sector tail.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: LiDaY/2025.03.28
* Change: 1.Add QAC, PolySpace warning analysis results.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: Chixp/2025.06.05
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
*/
#ifndef FEE_TYPES_H_
#define FEE_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Fee_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef enum
{
    /* Scan job */
    FEE_JOB_SCAN_INT_SCAN = 0U,
    FEE_JOB_SCAN_READ_SECTOR_HED,
    FEE_JOB_SCAN_READ_SECTOR_TAIL,
    FEE_JOB_SCAN_SECTOR_HED_PROC,
    FEE_JOB_SCAN_SECTOR_TAIL_PROC,
    FEE_JOB_SCAN_READ_BLOCK_HED,
    FEE_JOB_SCAN_READ_BLOCK_HED_RETRY,
    FEE_JOB_SCAN_BLOCK_HED_PROC,
    FEE_JOB_SCAN_BLOCK_HED_PROC_RETRY,
    FEE_JOB_SCAN_DONE,

    /* Read block job */
    FEE_JOB_READ,
    FEE_JOB_READ_DONE,

    /* Write block job */
    FEE_JOB_WRITE_HED,
    FEE_JOB_WRITE_DATA,
    FEE_JOB_WRITE_VALIDATE,
    FEE_JOB_WRITE_DONE,

    /* invalidate block job */
    FEE_JOB_INVAL_BLOCK,
    FEE_JOB_INVAL_BLOCK_UNVLD,
    FEE_JOB_INVAL_BLOCK_DONE,

    /* Erase block job */
    FEE_JOB_ERASE_BlOCK,
    FEE_JOB_ERASE_BlOCK_UNVLD,
    FEE_JOB_ERASE_IMMEDIATE_DONE,

    /* Sector head build */
    FEE_JOB_WRITE_SEC_HEAD,
    FEE_JOB_WRITE_SEC_TAIL,
    FEE_JOB_SEC_HEAD_DONE,

    /* Internal erase block job */
    FEE_JOB_INTER_ERASE,
    FEE_JOB_INTER_ERASE_DONE,

    /* End of work */
    FEE_JOB_DONE
} Fee_JobType;      /* Application layer request state machine enumeration */

typedef enum
{
    /* Swap block job */
    FEE_JOB_SWAP_WRITE_BLOCK_HEAD = 0U,
    FEE_JOB_SWAP_READ_BLOCK_DATA,
    FEE_JOB_SWAP_WRITE_BLOCK_DATA,
    FEE_JOB_SWAP_WRITE_BLOCK_VLDE,
    FEE_JOB_SWAP_BLOCK_DONE,
    FEE_JOB_SWAP_BLOCK_IDLE,
    /* Internal erase block job */
    FEE_JOB_SWAP_ERASE,
    FEE_JOB_SWAP_ERASE_DONE,
    /* End of work */
    FEE_JOB_SWAP_DONE
} Fee_SwapJobType;              /* Internal swap block state machine enumeration */

typedef enum
{
    FEE_SECTOR_FREE = 0U,               /* Sector free state */
    FEE_SECTOR_NEED_ERASE,              /* Sector need erase state */
    FEE_SECTOR_RESERVED_FREE,           /* Sector has reserved space for immediate writing */
    FEE_SECTOR_IMM_SWAP_NEED_ERASE,     /* Immediately swap sector need erase */
    FEE_SECTOR_NEED_SCAN,               /* Sector need scan state */
    FEE_SECTOR_FULL,                    /* Sector full state */
    FEE_SECTOR_WRITE_FAILED,            /* Sector write failed swap sector state */
    FEE_SECTOR_ACTIVATE,                /* Sector used now state */
    FEE_SECTOR_BAD_NEED_SWAP,           /* Sector bad need swap block state */
    FEE_SECTOR_BLOCK_NEED_SWAP,         /* Sector can not used need swap block state */
    FEE_SECTOR_RESERVED_ACTIVATE,       /* The writable space reserved by the sector for immediate writing */
    FEE_SECTOR_BAD,                     /* Sector bad state */
    FEE_SECTOR_DEF = 0xFFU              /* Sector initialize defaults */
} Fee_SectorStatusType;                 /* Sector state enumeration */

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.8" */
{
    uint8 reserve;
} Fee_ConfigType;

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.8" */
{
    uint32 BlockProgramCounter;     /* Block program counter */
    uint32 BlockStartAddr;          /* Block start address */
    uint32 ValidFlag;               /* Block valid flag */
} Fee_BlockHeadRamType;             /* Block head data struct Ram Type*/

typedef struct
{
    uint16 BlockNumber;             /* Block ID */
    uint16 BlockSize;               /* Block size */
    uint32 BlockProgramCounter;     /* Block program counter */
    uint32 BlockStartAddr;          /* Block start address */
    uint32 BlockCheck;              /* Block checksum */
    uint32 ValidFlag;               /* Block valid flag */
} Fee_BlockHeadRomType;             /* Block head data struct Rom Type*/

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.8" */
{
    uint32 SectorCounter;           /* Sector counter */
    uint32 SectorStartAddr;         /* Sector start address */
    uint32 SectorSize;              /* Sector size */
    uint32 SectorCheck;             /* Sector checksum */
    uint32 ValidFlag;               /* Sector valid flag */
} Fee_SectorHeadType;               /* Sector head data struct Type*/

typedef enum
{
    FEE_SWAP_IDLE = 0U,             /* Swap idle state */
    FEE_SWAP_PENDING                /* Scan pending state */
} Fee_SectorSwapStateType;          /* Current sector swap status */

typedef enum
{
    FEE_IMM_WRITE_DONE = 0U,            /* Immediate write end status */
    FEE_IMM_WRITE_ON_SWAP_INIT,         /* Immediate write initialization is required during swap */
    FEE_IMM_WRITE_ON_IMM_SWAP_INIT,     /* Immediate write initialization is required during immediate swap */
    FEE_IMM_WRITE_NO_SPACE,             /* No space reserved for immediate write action */
    FEE_IMM_WRITE_ON_SWAP,              /* Immediate write action is required during swap */
    FEE_IMM_WRITE_ON_IMM_SWAP           /* Immediate write action is required during immediate swap */
} Fee_ImmWrtieStateType;                /* Write working status immediately */

typedef enum
{
    FEE_SECTOR_SWAP_OFF = 0U,           /* Turn off sector swap operation */
    FEE_SECTOR_SWAP_PAUSE,              /* Turn pause sector swap operation */
    FEE_SECTOR_IMM_SWAP_PAUSE,          /* Turn pause sector immediately swap operation */
    FEE_ONLY_EARSE_PAUSE,               /* Earse sector pause */
    FEE_SECTOR_IMMEDIATELY_SWAP_ON,     /* Turn on sector immediately swap operation */
    FEE_SECTOR_SWAP_ON,                 /* Turn on sector swap operation */
    FEE_ONLY_EARSE_SECTOR               /* Only to earse sector */
}Fee_SwapRequestType;                   /* Module swap status */

typedef enum
{
    FEE_STOP_BY_INTER_ERROR = 0U,           /* Turn off Fee Module due to internal errors */
    FEE_STOP_BY_USER,                       /* Turn off Fee Module due to USER REQUESTD */
    FEE_RUNNING,                            /* Turn on Fee */
}Fee_ModuleRunningStateType;                /* Module swap status */

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.8" */
{
    Fee_SectorStatusType SectorState;       /* Sector state. */
    uint32 SectorCounter;                   /* Sector counter. */
    uint32 BlockHeadAddr;                   /* Block header address. */
    uint32 BlockDataAddr;                   /* Block data address. */
    uint32 SectorLastSize;                  /* Sector last size. */
    uint32 BlockWriteCounterInSector;       /* The maximum number of times a single sector writes to a block. */
    boolean DecoreLegacySectorHead;         /* Compatible with old sector heads. */
    uint8 SectorWriteFailedCounter;         /* The number of consecutive failures in writing Block headers in the current sector. */
} Fee_SectorCurrentInfoType;                /* Sector management info */

typedef struct
{
    uint8 EraseFlag;                            /* Perform erase operation flag */
    uint8 EraseSectorIndex;                     /* Erase sector ID */
    Fee_JobType EraseNextState;                 /* Job state after erase state */
    Fee_SwapJobType SwapEraseNextState;         /* Swap state after erase state */
    uint8 SectorIndex;                          /* Target write sector ID */
    uint16 BlockReadlen;                        /* Read block data length */
    uint16 BlockWritelen;                       /* Write block data length */
    uint32 SectorCounter;                       /* Sector counter */
    uint32 SectorLastSize;                      /* Sector last size */
    uint32 BlockHeadAddr;                       /* Block header address */
    uint32 BlockDataAddr;                       /* Block data address */
    uint32 BlockReadDataAddr;                   /* Read block data offset address */
} Fee_PartitionInfoSnapType;                    /* Module Management Snap */

typedef struct
{
    Fee_PartitionInfoSnapType PartitionInfoSnap;    /* Partition Snap */
    uint8* ReadDataBufferPtr;                       /* The buffer address for reading data */
    const uint8* WriteDataBufferPtr;                /* Write data buffer address */
    uint8 SectorFullNum;                            /* Fee Sector Full and Blcok_need_swap number */
    uint8 SectorFreeNum;                            /* Fee Sector Free and Need_Erase number */
    uint8 SectorReservedNum;                        /* Fee Sector Reserved and Reserved_Sector number */
    uint8 SectorBadNum;                             /* Fee Sector bad number */
    uint8 TriggerSwapThreshold;                     /* But when SectorFullNum is greater than TriggerSwapThreshold, trigger the SwapFlag */
    Fee_ModuleRunningStateType ModuleRunningState;  /* Flag indicating that an internal exception caused the module to stop running */
    boolean ReservedActive;                         /* Whether there is a reserved active sector */
    boolean noActiveSectors;                        /* Whether the active sector is obtained */
    Fee_ImmWrtieStateType ImmWriteState;            /* Immediate write state */
    uint8 BlockUseSectorNum;                        /* The minimum number of sectors occupied by block len for all configurations */
    Fee_JobType JobState;                           /* Fee job schedule state. */
    Fee_JobType JobNextState;                       /* Fee job next schedule state. */
    Fee_SwapJobType SwapJobBackUp;                  /* Swap job state backup before writing immediately */
    uint8 SectorIndexBackUp;                        /* Sector Index before writing immediately */
    uint8 RecoverSwapTimer;                         /* Reply to swap timer */
    uint32 BlockWriteCounterInSector;               /* The maximum number of times a single sector writes to a block */
} Fee_PartitionCurrentInfoType;                     /* Module Management Block */

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.8" */
{
    /* Polyspace-begin MISRA-C3:8.2 [JUstified:Unset] " NSCA_Polyspace_Fee_Rule8.2 " */
    Std_ReturnType (*Erase)(uint32, uint32);
    Std_ReturnType (*Write)(uint32, const uint8*, uint32);
    void (*Cancel)(void);
    MemIf_JobResultType (*GetJobResult)(void);
    Std_ReturnType (*Read)(uint32, uint8*, uint32);
    void (*SetMode)(MemIf_ModeType);
    /* Polyspace-end MISRA-C3:8.2 [JUstified:Unset] " NSCA_Polyspace_Fee_Rule8.2 " */
} Fls_FunctionListType;                        /* Fls function pointer */

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.8" */
{
    boolean IsImmediateData;                        /* Immediate bit */
    uint16 BlockNumber;                             /* Block number */
    uint16 BlockSize;                               /* Block size */
    Fee_BlockHeadRamType* Fee_BlockHead_Dyn;        /* Block header real-time change */
} Fee_BlockCfgType;                                 /* Block config data struct type */

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Fee_Dir4.8" */
{
    uint8 SectorNumber;                                 /* Sector number */
    uint32 SectorStartAddr;                             /* Sector start address */
    uint32 SectorSize;                                  /* Sector size */
    Fee_SectorCurrentInfoType* Fee_SectorCurrentInfo;   /* Current sector information */
    Fee_SectorHeadType* Fee_SectorHead_Dyn;             /* Sector header real-time change */
} Fee_SectorHeadCfgType;                                /* Sector config data struct type */

typedef struct
{
    uint8 SectorTotalNum;                               /* Sector total number */
    uint16 BlockTotalNum;                               /* Block total number */
    const Fee_SectorHeadCfgType* Fee_SectorHead;        /* Sector header address */
    const Fee_BlockCfgType* Fee_Block;                  /* Block address */
    const Fls_FunctionListType* Fls_FunctionList;       /* Fls funtion list. */
} Fee_PartitionCfgType;                                 /* Module config data struct type */

typedef struct
{
    MemIf_JobResultType FlsJobResultBackup;                 /* Fls feedback status recorded during swap pause */
    Fee_SwapJobType SwapJob;                                /* Fee swap job. */
    Fee_SwapRequestType SwapRequest;                        /* Swap request. */
    Fee_SectorSwapStateType SectorSwapState;                /* Fee current Sector Swap state */
    uint8 SourceSectorIndex;                                /* Fee Swaped Sector index. */
    boolean BlockSwapRequired;                              /* Did you get the block that needs to be swapped */
    boolean ReadIsProcessing;                               /* Performing a read operation */
    uint16 SwapBlockIndex;                                  /* Block index in data swap operation. */
    uint16 SwapScanBlockIndex;                              /* Block index in data swap scan operation. */
    uint16 RemaindReadLen;                                  /* Remaining read length */
    uint32 SwapReadLen;                                     /* Data length in data swap operation. */
    uint32 SwapReadAddr;                                    /* Address for reading data */
    uint32 ProcessedWriteLen;                               /* Fee swap write total length*/
    uint32 ImmSwapNeedSize;                                 /* The size of space required for immediate Swap */
    Fee_PartitionInfoSnapType SwapPartitionInfoSnap;        /* Swap Partition */
    Fee_SectorHeadType SectorHeadBackup;                    /* The backup current sector hearder information */
    Fee_BlockHeadRomType SwapBlockHeadBackup;               /* The backup current block hearder information */
} Fee_SwapManagerInfoType;                                  /* Swap Management Control Block */

typedef struct
{
    MemIf_JobResultType JobResult;             /* Fee job result state. */
    MemIf_JobResultType FlsJobResult;          /* Fee job result state. */
    uint16 JobBlockIndex;                      /* Fee block index. */
    uint32 WriteJobProcessedLen;               /* Fee job write total length*/
    uint32 WriteJobStartAddr;                  /* Fee job write total length*/
    uint32 BlockHeadAligned;                   /* The header data is aligned with the page size. */
    uint32 SectorHeadAligned;                  /* The header data is aligned with the page size. */
    Fee_BlockHeadRomType JobBlockHeadBackup;   /* The backup current block hearder information  */
} Fee_JobManagerInfoType;                      /* Job Management Control Block */

typedef struct
{
    uint16 ScanReadLen;                 /* Data length in scan operation. */
    boolean BlankAddrUpdateRequest;     /* Scan vaild Block head Flag */
    boolean TotalBlockLenCalcuFinish;   /* Scan Block length */
    uint16 CalcuBlockLenBlockIndex;     /* Block index in check block size operation. */
    uint32 BlankAddr;                   /* Scan Block head blank addr */
    uint32 TotalBlockLen;               /* Total Block len calculating in Fee_CheckBlocklen */
    uint32 TotalImmBlockLen;            /* Total length of all immediate write blocks */
    uint32 MaxImmBlockLen;              /* Maximum immediate write block length */
    uint32 ReservedImmLen;              /* Length of reserved write space immediately */
    uint8 ReservedImmSectors;           /* Write reserved sectors immediately */
    uint8 ScanSectorNeedEraseNum;       /* Number of sectors to be erased scanned during scan */
} Fee_ScanManagerInfoType;              /* Scan Management Control Block */

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

#endif /* FEE_TYPES_H_ */

