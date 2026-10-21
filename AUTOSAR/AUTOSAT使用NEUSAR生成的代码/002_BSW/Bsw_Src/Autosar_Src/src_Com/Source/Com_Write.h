/*
********************************************************************************
*
* File name: Com_Write.h
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
* Author/Date: LuQ/2024.09.30
* Change: Correct the coding specifications.
* Cause: Optimization
********************************************************************************
* Version: 1.3
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef COM_WRITE_H_
#define COM_WRITE_H_

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
#define COM_TXASSIGNSIGNAL_FUNC_NUM                                 (90U)      /* Number of Tx assignsignal funcation. */

#if( HIGH_BYTE_FIRST == CPU_BYTE_ORDER )
/* Make 16 bit lenght data. */
#define Com_Make16Bit(hiByte,loByte)                                ((uint16)((((uint32)(hiByte))<<8U)| ((uint32)(loByte))))

/* Make 24 bit lenght data. */
#define Com_Make24Bit(hiHiByte,loHiByte,loLoByte)                   ((uint32)((((uint32)(hiHiByte))<<16U)| \
                                                                               (((uint32)(loHiByte))<<8U) | \
                                                                               ((uint32)(loLoByte))))

/* Make 32 bit lenght data. */
#define Com_Make32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)          ((uint32)((((uint32)(hiHiByte))<<24U)| \
                                                                               (((uint32)(hiLoByte))<<16U)| \
                                                                               (((uint32)(loHiByte))<<8U) | \
                                                                               ((uint32)(loLoByte))))

/* Make 64 bit lenght data. */
#define Com_Make64Bit(hiHi32Byte,hiLo32Byte,loHi32Byte,loLo32Byte,hiHiByte,hiLoByte,loHiByte,loLoByte) \
                                                                   ((uint64)((((uint64)(hiHi32Byte))<<56U)| \
                                                                               (((uint64)(hiLo32Byte))<<48U)| \
                                                                               (((uint64)(loHi32Byte))<<40U)| \
                                                                               (((uint64)(loLo32Byte))<<32U)| \
                                                                                 (((uint64)(hiHiByte))<<24U)| \
                                                                                 (((uint64)(hiLoByte))<<16U)| \
                                                                                 (((uint64)(loHiByte))<<8U) | \
                                                                                 ((uint64)(loLoByte))))
#else
/* Make 16 bit lenght data. */
#define Com_Make16Bit(hiByte,loByte)                                ((uint16)((((uint32)(loByte))<<8U)| ((uint32)(hiByte))))

/* Make 24 bit lenght data. */
#define Com_Make24Bit(hiHiByte,loHiByte,loLoByte)                   ((uint32)((((uint32)(loLoByte))<<16U)| \
                                                                               (((uint32)(loHiByte))<<8U) | \
                                                                               ((uint32)(hiHiByte))))

/* Make 32 bit lenght data. */
#define Com_Make32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)          ((uint32)((((uint32)(loLoByte))<<24U)| \
                                                                               (((uint32)(loHiByte))<<16U)| \
                                                                               (((uint32)(hiLoByte))<<8U) | \
                                                                               ((uint32)(hiHiByte))))

/* Make 64 bit lenght data. */
#define Com_Make64Bit(hiHi32Byte,hiLo32Byte,loHi32Byte,loLo32Byte,hiHiByte,hiLoByte,loHiByte,loLoByte) \
                                                                   ((uint64)((((uint64)(loLoByte))<<56U)| \
                                                                               (((uint64)(loHiByte))<<48U)| \
                                                                               (((uint64)(hiLoByte))<<40U)| \
                                                                               (((uint64)(hiHiByte))<<32U)| \
                                                                             (((uint64)(loLo32Byte))<<24U)| \
                                                                             (((uint64)(loHi32Byte))<<16U)| \
                                                                             (((uint64)(hiLo32Byte))<<8U) | \
                                                                             ((uint64)(hiHi32Byte))))
#endif

/* Com Module Inter Init Marco. */
#define COM_INIT_ZERO                                               (0U)                  /* Tx Init Value 0. */
#define COM_INIT_ONE                                                (1U)                  /* Tx Init Value 1. */
#define COM_INIT_TWO                                                (2U)                  /* Tx Init Value 2. */
#define COM_INIT_THREE                                              (3U)                  /* Tx Init Value 3. */
#define COM_INIT_FOUR                                               (4U)                  /* Tx Init Value 4. */
#define COM_INIT_FIVE                                               (5U)                  /* Tx Init Value 5. */
#define COM_INIT_SIX                                                (6U)                  /* Tx Init Value 6. */
#define COM_INIT_SEVEN                                              (7U)                  /* Tx Init Value 7. */

#define COM_OPERAND_ONE                                             (1U)                  /* Tx Operand  1. */
#define COM_LENGTH_ZERO                                             (0U)                  /* Tx Length Init. */
#define COM_INIT_FF                                                 (0xFFU)               /* Tx Init Value FF. */
#define COM_INIT_U16FF                                              (0xFFFFU)             /* Tx init uint16 value 0xffff */
#define COM_INIT_U24FF                                              (0xFFFFFFU)           /* Tx init uint32 value 0xffffff */
#define COM_INIT_U32FF                                              (0xFFFFFFFFU)         /* Tx init uint32 value 0xffffffff. */
#define COM_INIT_U64FF                                              (0xFFFFFFFFFFFFFFFFU) /* Tx init uint64 value 0xFFFFFFFFFFFFFFFFU. */

/* Com Bit Length. */
#define COM_1BYTE_BITLENGTH                                         (8U)                  /* Length of 1 byte bit. */
#define COM_2BYTE_BITLENGTH                                         (16U)                 /* Length of 2 byte bit. */
#define COM_3BYTE_BITLENGTH                                         (24U)                 /* Length of 3 byte bit. */
#define COM_4BYTE_BITLENGTH                                         (32U)                 /* Length of 4 byte bit. */
#define COM_8BYTE_BITLENGTH                                         (64U)                 /* Length of 8 byte bit. */

/* Com Byte Length. */
#define COM_4BYTELENGTH                                             (4U)                  /* Length of 4 byte. */
#define COM_8BYTELENGTH                                             (8U)                  /* Length of 8 byte. */
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
typedef void (*Com_TxAssignSignal_Func)
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
extern CONST(Com_TxAssignSignal_Func, COM_APPL_CONST) Com_TxAssignSignal_FuncTable[COM_TXASSIGNSIGNAL_FUNC_NUM];

#define COM_STOP_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"
#endif  /* COM_PERFOPTMZ_SUPPORT == STD_ON */

#endif  /* COM_WRITE_H */

