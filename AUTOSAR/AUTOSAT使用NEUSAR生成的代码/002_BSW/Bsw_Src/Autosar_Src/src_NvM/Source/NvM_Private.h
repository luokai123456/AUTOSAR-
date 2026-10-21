/*
********************************************************************************
*
* File name: NvM_Private.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.12.19
* Change: New
* Cause: New
********************************************************************************
* Version: 2.0
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
* Change: Delete external function NVM_MultiBlock_NullCallBack.
* Cause: QAC
********************************************************************************
* Version: 3.2
* Author/Date: Hanbaiyu/2020.05.07
* Change: Add macro definitions about static id and configure id.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: HanBY/2020.11.04
* Change: Deleting memrory maps for variable or function declarations.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: HanBY/2020.11.27
* Change: Add the precompile of Det.h.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: HanBY/2021.03.19
* Change: Add some macro definitions to support write verification.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: HanBY/2021.12.30
* Change: Add some macro definition NVM_CRC16_MASK_VALUE for crc calculation.
* Cause: Bugfix
********************************************************************************
* Version: 3.8
* Author/Date: WangLX/2024.04.25
* Change: Add a memory-map label to function and variable declarations.
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: WangLX/2024.07.31
* Change: Deleting Nvm mainfunction state machine macro.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: WangLX/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
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
#ifndef NVM_PRIVATE_H_
#define NVM_PRIVATE_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "NvM_Cfg.h"
#include "NvM_Def.h"
#include "MemIf.h"
#include "NvM_Queue.h"
#include "NvM.h"

/* PolySpace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_NvM_20.9" */
#if( NVM_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Redundant block number.  */
#define NVM_REDUNDANT_PRIMARY       (0U)
#define NVM_REDUNDANT_SECOND        (1U)

/* Number of crc calculation algorithms API. */
#define NVM_CRCCALC_API_NUMBER      (4U)

/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */
#define NVM_VALUE_ONE               (0x1U)
#define NVM_DADAINDEX_MAX           (0x255U)

/* Nvm mainfunction Internal state machine. */
#define NVM_TRANSITION_STATE1       (0x01U)
#define NVM_TRANSITION_STATE2       (0x02U)
#define NVM_TRANSITION_STATE3       (0x03U)

/* Crc start valu. */
#define NVM_CRC_INIT_VALUE          (0xFFFFFFFFU)
#define NVM_CRC_MASK_VALUE          (0xFFU)
#define NVM_CRC16_MASK_VALUE        (0xFFFFU)
#define NVM_CRC_SHIFT_BIT           (8U)

/* There is only one request in the current queue. */
#define NVM_ONLY_ONE_REQUEST_LEFT   (1U)

/* Nvm reserve Id. */
#define NVM_BLOCK_RESERVEID         (0U)

#define NVM_BLOCK_RESERVE_NUM       (1U)

/* User can use the starting id. */
#define NVM_BLOCK_STARTID           (1U)

/* Block offset is 0. */
#define NVM_BLOCK_OFFSET_0          (0U)

/* residual data length of CRC calculates. */
#define NVM_BLOCK_CRC_REMAINLEGTH   (0U)

/* At least one block succeeded of redundant. */
#define NVM_ATLEAST_ONE_SUCCESS     (1U)

/* Set Configure ID shift bit to transform two uint8 to one uint16. */
#define NVM_CFGID_SHIFT_BIT         (8U)

/* Set static ID shift bit to transform two uint8 to one uint16. */
#define NVM_STATICID_SHIFT_BIT      (8U)

/* Set the first bit of static ID. */
#define NVM_STATICID_FIRST_BIT      (0U)

/* Set the first bit of static ID. */
#define NVM_STATICID_SECOND_BIT     (1U)

/* Set the mask of static ID. */
#define NVM_STATICID_MASK           (0xFFU)

/* Set the length of static ID. */
#define NVM_STATICID_LENGTH         (0x2U)

/* Set the first bit of configure ID. */
#define NVM_CFGID_FIRST_BIT         (0U)

/* Set the first bit of static ID. */
#define NVM_CFGID_SECOND_BIT        (1U)

/* Four byte align. */
#define NVM_BYTE_4_ALIGN            (4U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */
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
#define NVM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern VAR(NvM_Statemachine_Type, NVM_VAR_INIT) NvM_SingleStateMachine;

#define NVM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
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
#define NVM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern FUNC(void, NVM_CODE) NvM_MainFun_GetNewBlock(void);
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
extern FUNC(void, NVM_CODE) NVM_Det_ErrorReport(uint8 ApiId, uint8 ErrorId);
extern FUNC(void, NVM_CODE) NVM_Init_BlockManagment(void);
extern FUNC(void, NVM_CODE) NVM_Init_CrrntJob(void);
extern FUNC(void, NVM_CODE) NVM_Init_QueueJob(void);
extern FUNC(void, NVM_CODE) NVM_MultiBlock_CallBack
(
    /* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_NvM_D4.5" */
    uint8 ServiceId,
    NvM_RequestResultType JobResult
);
extern FUNC(void, NVM_CODE) NvM_MainFun_ValidateAll(void);
extern FUNC(void, NVM_CODE) NvM_MainFun_SingleBlock(void);
extern FUNC(void, NVM_CODE) NvM_MainFun_MultiBlock(void);

#define NVM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* NVM_PRIVATE_H_ */
