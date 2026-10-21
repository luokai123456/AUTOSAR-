/*
********************************************************************************
*
* File name: Com_Read.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: TianG/2024.03.22
* Change: Add
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: LuQ/2024.09.20
* Change: Modify CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef COM_READ_H_
#define COM_READ_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Com_Types.h"
#include "Com_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
#define COM_RXPARSESIGNAL_FUNC_NUM                      (90U)                                  /* Number of Rx parsesignal funcation. */

#if( HIGH_BYTE_FIRST == CPU_BYTE_ORDER )
#define Com_GetHiByte(data)                             ((uint8)(((uint16)(data))>>8U))        /* Get uint16 high byte. */
#define Com_GetLoByte(data)                             ((uint8)(data))                        /* Get uint16 low byte. */

#define Com_GetHiHiByte(data)                           ((uint8)(((uint32)(data))>>24U))       /* Get uint32 high byte. */
#define Com_GetHiLoByte(data)                           ((uint8)(((uint32)(data))>>16U))       /* Get uint32 middle high byte. */
#define Com_GetLoHiByte(data)                           ((uint8)(((uint32)(data))>>8U))        /* Get uint32 middle low byte. */
#define Com_GetLoLoByte(data)                           ((uint8)(data))                        /* Get uint32 low byte. */

#define Com_Get64HiHiByte(data)                         ((uint8)(((uint64)(data))>>56U))       /* Get uint64 high uint32 high byte. */
#define Com_Get64HiLoByte(data)                         ((uint8)(((uint64)(data))>>48U))       /* Get uint64 high uint32 middle high byte. */
#define Com_Get64LoHiByte(data)                         ((uint8)(((uint64)(data))>>40U))       /* Get uint64 high uint32 middle low byte. */
#define Com_Get64LoLoByte(data)                         ((uint8)(((uint64)(data))>>32U))       /* Get uint64 high uint32 low byte. */
#define Com_Get64Hi32HiByte(data)                       ((uint8)(((uint64)(data))>>24U))       /* Get uint64 low uint32 high byte. */
#define Com_Get64Hi32LoByte(data)                       ((uint8)(((uint64)(data))>>16U))       /* Get uint64 low uint32 middle high byte. */
#define Com_Get64Lo32HiByte(data)                       ((uint8)(((uint64)(data))>>8U))        /* Get uint64 low uint32 middle low byte. */
#define Com_Get64Lo32LoByte(data)                       ((uint8)(data))                        /* Get uint64 low uint32 low byte. */
#else
#define Com_GetHiByte(data)                             ((uint8)(data))                        /* Get uint16 high byte. */
#define Com_GetLoByte(data)                             ((uint8)(((uint16)(data))>>8U))        /* Get uint16 low byte. */

#define Com_GetHiHiByte(data)                           ((uint8)(data))                        /* Get uint32 high byte. */
#define Com_GetHiLoByte(data)                           ((uint8)(((uint32)(data))>>8U))        /* Get uint32 middle high byte. */
#define Com_GetLoHiByte(data)                           ((uint8)(((uint32)(data))>>16U))       /* Get uint32 middle low byte. */
#define Com_GetLoLoByte(data)                           ((uint8)(((uint32)(data))>>24U))       /* Get uint32 low byte. */

#define Com_Get64HiHiByte(data)                         ((uint8)(data))                        /* Get uint64 high uint32 high byte. */
#define Com_Get64HiLoByte(data)                         ((uint8)(((uint64)(data))>>8U))        /* Get uint64 high uint32 middle high byte. */
#define Com_Get64LoHiByte(data)                         ((uint8)(((uint64)(data))>>16U))       /* Get uint64 high uint32 middle low byte. */
#define Com_Get64LoLoByte(data)                         ((uint8)(((uint64)(data))>>24U))       /* Get uint64 high uint32 low byte. */
#define Com_Get64Hi32HiByte(data)                       ((uint8)(((uint64)(data))>>32U))       /* Get uint64 low uint32 high byte. */
#define Com_Get64Hi32LoByte(data)                       ((uint8)(((uint64)(data))>>40U))       /* Get uint64 low uint32 middle high byte. */
#define Com_Get64Lo32HiByte(data)                       ((uint8)(((uint64)(data))>>48U))       /* Get uint64 low uint32 middle low byte. */
#define Com_Get64Lo32LoByte(data)                       ((uint8)(((uint64)(data))>>56U))       /* Get uint64 low uint32 low byte. */
#endif

/* Com Module Inter Init Marco. */
#define COM_INIT_ZERO                                   (0U)                  /* Init Value 0. */
#define COM_INIT_ONE                                    (1U)                  /* Init Value 1. */
#define COM_INIT_TWO                                    (2U)                  /* Init Value 2. */
#define COM_INIT_THREE                                  (3U)                  /* Init Value 3. */
#define COM_INIT_FOUR                                   (4U)                  /* Init Value 4. */
#define COM_INIT_FIVE                                   (5U)                  /* Init Value 5. */
#define COM_INIT_SIX                                    (6U)                  /* Init Value 6. */
#define COM_INIT_SEVEN                                  (7U)                  /* Init Value 7. */

#define COM_OPERAND_ONE                                 (1U)                  /* Operand  1. */
#define COM_LENGTH_ZERO                                 (0U)                  /* Length Init. */
#define COM_INIT_FF                                     (0xFFU)               /* Init Value FF. */
#define COM_INIT_U16FF                                  (0xFFFFU)             /* Init uint16 value 0xffff */
#define COM_INIT_U24FF                                  (0xFFFFFFU)           /* Init uint32 value 0xffffff */
#define COM_INIT_U32FF                                  (0xFFFFFFFFU)         /* Init uint32 value 0xffffffff. */
#define COM_INIT_U64FF                                  (0xFFFFFFFFFFFFFFFFU) /* Init uint64 value 0xFFFFFFFFFFFFFFFFU. */

/* Com Bit Length. */
#define COM_1BYTE_BITLENGTH                             (8U)                  /* Length of 1 byte bit. */
#define COM_2BYTE_BITLENGTH                             (16U)                 /* Length of 2 byte bit. */
#define COM_3BYTE_BITLENGTH                             (24U)                 /* Length of 3 byte bit. */
#define COM_4BYTE_BITLENGTH                             (32U)                 /* Length of 4 byte bit. */
#define COM_8BYTE_BITLENGTH                             (64U)                 /* Length of 8 byte bit. */

/* Com Byte Length. */
#define COM_4BYTELENGTH                                 (4U)                  /* Length of 4 byte. */
#define COM_8BYTELENGTH                                 (8U)                  /* Length of 8 byte. */
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
typedef void (*Com_RxParseSignal_Func)
(
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) srcBuffer,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) destBuffer,
    P2CONST(Com_SignalBaseInfo_st, AUTOMATIC, COM_APPL_DATA) signalBaseRef
);
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
#define COM_START_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"

extern CONST(Com_RxParseSignal_Func, COM_APPL_CONST) Com_RxParseSignalFuncTable[COM_RXPARSESIGNAL_FUNC_NUM];

#define COM_STOP_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

#endif  /* COM_READ_H */

