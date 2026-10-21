/*
********************************************************************************
*
* File name: NvM_Def.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.12.13
* Change: Add
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: WangJipeng/2019.04.08
* Change: V2.0 release.
* Cause: Update
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
* Change: Simplify macro definition name.
* Cause: QAC
********************************************************************************
* Version: 3.2
* Author/Date: Hanbaiyu/2020.05.07
* Change: 1. Add member variable AutoValidation for NvM_Block_Descriptor_Table_st.
          2. Add member variable NvmLossRedun for Nvm_BlockManagment_st.
          3. Add strut type Nvm_QueueHeader_st.
          4. Add enum type MVN_StatusType.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: HanBY/2021.08.30
* Change: 1. Add some macros about auto calculation or verification block length.
*         2. Add some members for NvM_Block_Descriptor_Table_st to fit the function
*            auto calculation or verification block length.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: HanBY/2021.09.03
* Change: Modify the micro SuspendAllInterrupts_os and ResumeAllInterrupts_os,
*         delete the suffix _os.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: HanBY/2021.09.13
* Change: Modify the spelling mistake of micro NVM_BLOCKLEN_COMPLIER_CHECK.
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: HanBY/2021.10.18
* Change: Modify the wrong type name from MVN_StatusType to NvM_Status_Type.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: HanBY/2021.12.30
* Change: Delete the type define of Nvm_CrcCalc_Type.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: LiDY/2023.03.03
* Change: Add Fee devices counter in queue.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: WangLX/2023.10.19
* Change: Delete run time block length check defines.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: WangLX/2024.07.31
* Change: 1.Add immediate priority macro.
*         2.Add NvM_Statemachine_Type enum.
*         3.Optimization Nvm_BlockAdministrator_st.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: ZengJX/2025.06.04
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
*/
#ifndef NVM_DEF_H_
#define NVM_DEF_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os.h"
#include "NvM_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* NvMBlockDescriptor start. */
/* CrcType. */
#define NVM_BLOCK_CRC_UNUSE     (0U)
#define NVM_BLOCK_CRC_8         (1U)
#define NVM_BLOCK_CRC_16        (2U)
#define NVM_BLOCK_CRC_32        (3U)

/* CrcType Size. */
#define NVM_BLOCK_CRC_SIZE_UNUSE     (0U)
#define NVM_BLOCK_CRC_SIZE_8         (1U)
#define NVM_BLOCK_CRC_SIZE_16        (2U)
#define NVM_BLOCK_CRC_SIZE_32        (4U)

/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */

/* Deveice Index. */
#define NVM_BLOCK_MEMIF_EA      (0U)
#define NVM_BLOCK_MEMIF_FEE     (1U)

/* Defines whether the CRC of the RAM Block shall be compared during a write job with the CRC. */
#define NVM_BLOCK_CRC_COMP_ON     (1U)
#define NVM_BLOCK_CRC_COMP_OFF    (0U)

/* Defines whether the RAM Block shall be auto validated during shutdown phase. */
#define NVM_BLOCK_AUTO_VALID_ON        (1U)
#define NVM_BLOCK_AUTO_VALID_OFF       (0U)

/* Defines the block management type for the NVRAM block. */
#define NVM_BLOCK_MANAGENMENT_NATIVE            (0U)
#define NVM_BLOCK_MANAGENMENT_REDUNDANT         (1U)
#define NVM_BLOCK_MANAGENMENT_DATASET           (2U)

/* Defines if NvMSetRamBlockStatusApi shall be used for this block or not. */
#define NVM_BLOCK_SETBLOCKSTATUS_ON      (1U)
#define NVM_BLOCK_SETBLOCKSTATUS_OFF     (0U)

/* Defines whether an explicit synchronization mechanism with a RAM mirror
   and callback routines for transferring data to and from NvM module's RAM
   mirror is used for NV block. */
#define NVM_BLOCK_USE_SYNC_MECHANISM_ON         (1U)
#define NVM_BLOCK_USE_SYNC_MECHANISM_OFF        (0U)

/* Defines an initial write protection of the NV block. */
#define NVM_BLOCK_WRITE_PROT_ON                 (1U)
#define NVM_BLOCK_WRITE_PROT_OFF                (0U)

/* This parameter specifies whether BswM is informed about the current
   status of the specified block. */
#define NVM_BSWM_INFORMATION_ON    (1U)
#define NVM_BSWM_INFORMATION_OFF   (0U)

/* Defines CRC (re)calculation for the permanent RAM block or NVRAM
   blocks which are configured to use explicit synchronization mechanism. */
#define NVM_CALC_RAM_BLOCK_CRC_ON               (1U)
#define NVM_CALC_RAM_BLOCK_CRC_OFF              (0U)

/* Defines the NVRAM device ID where the NVRAM block is located. */
#define NVM_NVRAM_DEVICE_EA                     (0U)
#define NVM_NVRAM_DEVICE_FEE                    (1U)

/* Defines whether a NVRAM block shall be treated resistant to configuration
   changes or not. */
#define NVM_RESISTANT_TO_CHANGED_SW_ON          (1U)
#define NVM_RESISTANT_TO_CHANGED_SW_OFF         (0U)

/* Defines whether a NVRAM block shall be processed during NvM_ReadAll or not. */
#define NVM_SELECT_BLOCK_4_READALL_ON           (1U)
#define NVM_SELECT_BLOCK_4_READALL_OFF          (0U)

/* Defines whether a NVRAM block shall be processed during NvM_WriteAll or not. */
#define NVM_SELECT_BLOCK_4_WRITEALL_ON          (1U)
#define NVM_SELECT_BLOCK_4_WRITEALL_OFF         (0U)

/* Defines if the Static Block ID check is enabled. */
#define NVM_STATIC_BLOCK_ID_CHECK_ON            (1U)
#define NVM_STATIC_BLOCK_ID_CHECK_OFF           (0U)

/* Defines write protection after first write. */
#define NVM_WRITE_BLOCK_ONCE_ON                 (1U)
#define NVM_WRITE_BLOCK_ONCE_OFF                (0U)

/* Defines if Write Verification is enabled */
#define NVM_WRITE_VERIFICATION_ON               (1U)
#define NVM_WRITE_VERIFICATION_OFF              (0U)
/* Defines if auto calculate block length is enabled. */
#define NVM_BLOCKLEN_AUTOCAL_ON                 (1U)
#define NVM_BLOCKLEN_AUTOCAL_OFF                (0U)
/* NvMBlockDescriptor end. */

/* Block protect. */
#define NVM_BLOCK_PRTCT_ON  (0x01U)
#define NVM_BLOCK_PRTCT_OFF (0xFEU)
/* Block Validate/Invalidate. */
#define NVM_BLOCK_VALID     (0x02U)
#define NVM_BLOCK_INVALID   (0xFDU)
/* Block changed/unchanged. */
#define NVM_BLOCK_CHANGED   (0x04U)
#define NVM_BLOCK_UNCHANGED (0xFBU)
/* Block Lock/Unlock. */
#define NVM_BLOCK_LOCKED    (0x08U)
#define NVM_BLOCK_UNLOCKED  (0xF7U)

/* Multiple block request. */
#define NVM_BLOCK_READALL_SET           (0x02U) /* Set read all request. */
#define NVM_BLOCK_READALL_CL            (0xFDU) /* Clear read all request. */
#define NVM_BLOCK_WRITEALL_SET          (0x04U) /* Set write all request. */
#define NVM_BLOCK_WRITEALL_CL           (0xFBU) /* Clear write all request. */
#define NVM_BLOCK_CANCEL_WRITEALL_SET   (0x08U) /* Set cancel all request. */
#define NVM_BLOCK_CANCEL_WRITEALL_CL    (0xF7U) /* Clear cancel all request. */
#define NVM_BLOCK_VALIDATEALL_SET       (0x10U) /* Set validate all request. */
#define NVM_BLOCK_VALIDATEALL_CL        (0xEFU) /* Clear validate all request. */
#define NVM_BLOCK_MULTIREQUESTALL       (0x1EU) /* All multi block request. */

/*  Current Multiple Job. */
#define NVM_MULTI_READALL   (0x01U) /* current mutli block request is read all. */
#define NVM_MULTI_WRITEALL  (0x02U) /* current mutli block request is write all. */

/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */

#define NVM_INIT_0                  (0U)    /* Initial value 0. */
#define NVM_CRC_START_VALUE         (0xFFFFFFFFU)   /* Initial value of CRC calculation. */

#define NVM_BLOCK_HIGHEST_PRI       (0U)        /* Highest priority */
#define NVM_IMMEDIATE_WRITE_TURE    (1U)    /* Processing immediate write operation */
#define NVM_IMMEDIATE_WRITE_FALSE   (0U)    /* End of immediate write operation */

#define NVM_QUEUE_CURRENTBLOCKID    (0xFFFFU)   /* Current block is null. */
#define NVM_QUEUE_NEXTBLOCKID       (0xFFFFU)   /* Next block is null. */

/* dummy operation. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
#define NVM_DUMMY_STATEMENT(v)          (v)=(v)
/* immediate priority. */
#define NVM_IMMEDIATE_PRIORITY  (0U)

/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define SchM_Enter_NVM_EXCLUSIVE_AREA() SuspendAllInterrupts()

/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define SchM_Exit_NVM_EXCLUSIVE_AREA() ResumeAllInterrupts()

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Block configuration definition. */
typedef struct
{
    uint16 BlockId;                     /* Nv Block ID (BlockId >= 1). */
    boolean AutoCalBlockLength;         /* Define whether enable auto block length calculate. */
    uint8 CrcType;                      /* Checksum Algorithm Type. */
    uint8 ManagementType;               /* Mangment type. */
    uint8 AutoValidation;               /* Defines whether to enable the automatic verification function */
    boolean CrcCompMechanism;           /* Defines whether the CRC of the RAM Block shall be compared. */
    boolean SyncMechanism;              /* Defines whether synchronization mechanism is used, used the callback. */
    boolean WriteProt;                  /* Defines an initial write protection of the NV block. */
    uint8 MaxNumOfReadRetries;          /* Defines the maximum number of read retries. */
    uint8 MaxNumOfWriteRetries;         /* Defines the maximum number of write retries for a NVRAM block. */
    boolean BswMInform;                 /* informed BswM he current status of the specified block. */
    boolean RamBlockCrc;                /* Defines CRC usage for the NVRAM block. */
    boolean DeviceId;                   /* EA or FEE. */
    boolean ResistantToChangedSw;       /* Defines whether a NVRAM block shall be treated resistant to configuration changes or not. */
    boolean Select4ReadAll;             /* Defines whether a NVRAM block shall be processed during NvM_ReadAll or not. */
    boolean Select4WriteAll;            /* Defines whether a NVRAM block shall be processed during NvM_WriteAll or not. */
    boolean BlockIDCheck;               /* Reserved, Defines if the Static Block ID check is enabled. */
    boolean WriteBlockOnce;             /* Defines write protection after first write. */
    boolean UseSetRamBlockStatus;       /* Defines if NvMSetRamBlockStatusApi shall be used for this block or not. */
    boolean WriteVerification;          /* Reserved, Defines if Write Verification is enabled. */
    uint16 NvBlockBaseNumber;           /* FEE/EA_BLOCK_NUMBER = (NvMNvBlockBaseNumber << NvMDatasetSelectionBits)+ DataIndex. */
    uint16 NvBlockLength;               /* Defines the NV block data length in bytes. */
    uint16 RamBlockLengthCfg;           /* Defines the Ram block length configured. */
    uint16 RamBlockLengthSizeof;        /* Defines the Ram block length sizeof. */
    uint8 JobPriority;                  /* Defines the job priority for a NVRAM block */
    uint8 NvBlockNum;                   /* Defines the number of multiple NV blocks,DATASET 2-155, NATIVE 1, REDUNDANT 2. */
    uint8 RomBlockNum;                  /* Reserved, Defines the number of multiple ROM blocks
                                        in a contiguous area according to the given block management type. */
    uint16 WriteVerificationDataSize;   /* Defines the number of bytes to compare in each step
                                        when comparing the content of a RAM Block and a block read back. */
    uint8* RamAddr;                     /* Ram Block buffer pointer. */
    uint8* RomAddr;                     /* Rom Block buffer pointer. */
    uint8(* NvMInitBlockCallback)(void);                    /* Init Callback function. */
    /* Polyspace +1 MISRA-C3:8.2 [Justified:Unset] " NSCA_Polyspace_NvM_8.2 " */
    uint8(* NvMReadRamBlockFromNvCallback)(const void*);    /* Read RamBlock From Nv Callback function. */
    /* Polyspace +1 MISRA-C3:8.2 [Justified:Unset] " NSCA_Polyspace_NvM_8.2 " */
    uint8(* NvMWriteRamBlockToNvCallback)(void*);           /* WriteRamBlock To Nv Callback function. */
    /* Polyspace +1 MISRA-C3:8.2 [Justified:Unset] " NSCA_Polyspace_NvM_8.2 " */
    uint8(* NvMSingleBlockCallback)(uint8,NvM_RequestResultType);           /* Job End Callback function. */
} NvM_Block_Descriptor_Table_st;

/* Block management. */
typedef struct
{
    uint16 BlockId;         /* Block ID. */
    uint16 NxtBlockId;      /* The next blockID to deal with. */
    uint8  CtrlType;        /* Request for block. */
    uint8  Priority;        /* Block priority. */
    uint8  DataIndex;       /* used for dataset index. */
    uint8  NvRamErrStatus;  /* NvM_RequestResultType. */
    uint8  NvRamState;      /* Ram blcok status. */
    uint8  NvmLossRedun;    /* Loss redundant flag */
    uint16 RemainLegth;     /* The length of the block data to be processed. */
    uint8* RamAddr;         /* Ram start address. */
    uint8* CurRamAddr;      /* Ram current address.*/
} Nvm_BlockManagment_st;

/* Information about blocks currently being processed. */
typedef struct
{
    uint16 CurBlockId;      /* current processing blockID. */
    uint16 RemainNum;       /* Number of pending blockId. */
    uint16 BlockNumber;     /* Block number for EA/FEE. */
    uint8  MultiBlockReq;   /* Mutli block request. */
    uint8  JobResult;       /* Result of block operation. */
    uint32 CrcValu;         /* CRC calculation result for the current block. */
} Nvm_QueueProcss_st;

/* Information about queue head. */
typedef struct
{
    uint16 FirstBlockId;        /* First block to process. */
    uint16 LastBlockId;         /* Last block to be processed. */
    uint16 Counter;             /* Number of pending blockId. */
    uint16 CounterImmediate;    /* Immediate number of pending. */
    uint16 FeeReqNum;           /* Fee devices counter in queue. */
} Nvm_QueueHeader_st;

typedef struct
{
    uint32 CrcValue;        /* The value of CRC checksum. */
} Nvm_BlockAdministrator_st;

typedef enum
{
    NVM_IDLE = 0U,      /* Module is in idle state. */
    NVM_SINGLE,         /* The module is processing a single block request. */
    NVM_MULTI           /* Module is processing multiple block requests. */
} NvM_Status_Type;

/* Nvm mainfunction state machine. */
typedef enum
{
    NVM_STATEMACHINE_IDLE        = 0U,      /* Module is in idle state. */
    NVM_STATEMACHINE_REQUEST     = 1U,      /* Sending read/write data request to the lower level. */
    NVM_STATEMACHINE_BUSY        = 2U,      /* Wait for processing results. */
    NVM_STATEMACHINE_CRCCALC     = 3U,      /* Crc checking. */
    NVM_STATEMACHINE_RETRY       = 4U,      /* Request to read backup data. */
    NVM_STATEMACHINE_WRITERED    = 5U,      /* Write the second block, Only for REDUNDANT. */
    NVM_STATEMACHINE_VALIDATE    = 6U,      /* . */
    NVM_STATEMACHINE_RESISTANT   = 7U,      /* Restore default value. */
    NVM_STATEMACHINE_FINISH      = 8U,      /* End processing flow, reset process information. */
    NVM_STATEMACHINE_ERASED      = 9U,      /* Erase the second block, Only for REDUNDANT. */
    NVM_STATEMACHINE_INALIDATED  = 10U,     /* Invalidate the second block, Only for REDUNDANT. */
    NVM_STATEMACHINE_VERIFY_REQ  = 11U,     /* Send read request for write verify. */
    NVM_STATEMACHINE_VERIFY_BUSY = 12U,     /* Wait for verify read processing results. */
    NVM_STATEMACHINE_COMPARE     = 13U,     /* Compare the data in ram block and buffer. */
}NvM_Statemachine_Type;
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

#endif /* NVM_DEF_H_ */
