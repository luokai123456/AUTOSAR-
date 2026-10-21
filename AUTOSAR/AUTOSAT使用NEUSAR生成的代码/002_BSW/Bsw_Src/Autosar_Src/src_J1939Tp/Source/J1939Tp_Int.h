/*
********************************************************************************
*
* File name: J1939Tp_Int.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2019.3.18
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: li.zhiheng/2020.03.30
* Change: Nothing
* Cause: Update to 3.0
********************************************************************************
* Version: 3.1
* Author/Date: li.zhiheng/2020.05.20
* Change: Modification code specification.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: li.zhiheng/2020.05.20
* Change: Modification code specification.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: Li.ZH/2021.8.16
* Change: Modification code specification, Change u to U.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: TongXY/2023.3.14
* Change: 1.New status for retransmission.
*         2.Modified qac warning.
*         3.Change the det error to a function implementation.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: YanCL/2024.4.2
* Change: 1.Modify the P2CONST incorrect labels.
*         2.Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: YanCL/2024.5.24
* Change: Add macro definition:J1939TP_TPDT_COUNT, J1939TP_IDX_ZERO.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: YanCL/2024.6.25
* Change: 1.Add copyright information.
*         2.Add Memmap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: YanCL/2024.10.11
* Change: Modify the functions memclass of J1939Tp_ReportDevError() and
*         J939Tp_ReportRuntimeError().
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: YanCL/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: YanCL/2025.06.23
* Change: #include "J1939Tp_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
#ifndef J1939TP_INT_H_
#define J1939TP_INT_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "J1939Tp_Cfg.h"
#include "J1939Tp.h"
#include "ComStack_Types.h"

#if( J1939TP_DEV_ERROR_REPORT == STD_ON )
#include "Det.h"           /* SWS_J1939Tp_00193 */
#endif  /* J1939TP_DEV_ERROR_REPORT == STD_ON*/

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Development Error Detection */
# define J1939TP_INSTANCE_ID_DET                (0u)

/* Special addresses. */
#define J1939TP_NULL_ADDRESS                   (0xFEU)
#define J1939TP_BROADCAST_ADDRESS              (0xFFU)
#define J1939TP_NO_ADDRESS_CONFIGURED          (0xFEU)

/* Default priority for TP frames. */
#define J1939TP_DEFAULT_PRIORITY               (7U << 2U)
#define J1939TP_PRIORITY_MASK                  (0x1CU)

/* MetaData sizes and positions. */
#define J1939TP_MDL_SIZE                       (4U)
#define J1939TP_MDL_SA_POS                     (0U)
#define J1939TP_MDL_DA_POS                     (1U)
#define J1939TP_MDL_GE_POS                     J1939TP_MDL_DA_POS
#define J1939TP_MDL_PDUF_POS                   (2U)
#define J1939TP_MDL_DP_POS                     (3U)
#define J1939TP_MDL_PRI_POS                    J1939TP_MDL_DP_POS

/* Standardized sizes and positions. */
#define J1939TP_FRAME_LENGTH                   (8U)

/* TP.CM */
#define J1939TP_TPCM_CB                        (0U) /* all */
#define J1939TP_TPCM_TMS_LO                    (1U) /* BAM, RTS, EOMAck */
#define J1939TP_TPCM_TMS_HI                    (2U) /* BAM, RTS, EOMAck */
#define J1939TP_TPCM_TNOP                      (3U) /* BAM, RTS, EOMAck */
#define J1939TP_TPCM_MNOP                      (4U) /* RTS */
#define J1939TP_TPCM_NOP                       (1U) /* CTS */
#define J1939TP_TPCM_NPN                       (2U) /* CTS */
#define J1939TP_TPCM_CAR                       (1U) /* Abort */
#define J1939TP_TPCM_RES3                      (2U) /* Abort */
#define J1939TP_TPCM_RES4                      (3U) /* CTS, Abort */
#define J1939TP_TPCM_RES5                      (4U) /* BAM, CTS, EOMAck, Abort */
#define J1939TP_TPCM_PGN_LO                    (5U) /* all */
#define J1939TP_TPCM_PGN_MD                    (6U) /* all */
#define J1939TP_TPCM_PGN_HI                    (7U) /* all */

/* TP.DT */
#define J1939TP_TPDT_COUNT                     (0U)
#define J1939TP_TPDT_SEQ                       (0U)
#define J1939TP_TPDT_DATA                      (1U)
#define J1939TP_TPDT_DATA_SIZE                 (7U)

/* Index values. */
#define J1939TP_IDX_ZERO                       (0U)



/* Standardized values. */
#define J1939TP_MAX_LENGTH                     (1785U)
#define J1939TP_CTS_WAIT                       (0U)

/* Pattern for unused areas. */
#define J1939TP_SNA_VALUE                      (0xFFU)

/* Special values. */
#define J1939TP_ZERO                           (0U)
#define J1939TP_ONE                            (1U)
#define J1939TP_TWO                            (2U)
#define J1939TP_FOUR                           (4U)
#define J1939TP_FF                             (255U)

#define J1939TP_DONT_RETRY                     (0U)
#define J1939TP_NEED_RETRY                     (1U)

/* N-PDU size and MDL positions. */
#define J1939TP_NPDU_LENGTH                    (J1939TP_FRAME_LENGTH + J1939TP_MDL_SIZE)
#define J1939TP_NPDU_MDL_POS                   J1939TP_FRAME_LENGTH
#define J1939TP_NPDU_SA_POS                    (J1939TP_FRAME_LENGTH + J1939TP_MDL_SA_POS)
#define J1939TP_NPDU_DA_POS                    (J1939TP_FRAME_LENGTH + J1939TP_MDL_DA_POS)
#define J1939TP_NPDU_GE_POS                    J1939TP_NPDU_DA_POS
#define J1939TP_NPDU_PDUF_POS                  (J1939TP_FRAME_LENGTH + J1939TP_MDL_PDUF_POS)
#define J1939TP_NPDU_DP_POS                    (J1939TP_FRAME_LENGTH + J1939TP_MDL_DP_POS)
#define J1939TP_NPDU_PRI_POS                   J1939TP_NPDU_DP_POS

/* Divide and round up. */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_RoundUp(value, div)            (uint8)(((value) + ((div) - 1U)) / (div))

/* Generic access macros */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_AssembleTwoBytes(lo, hi)       ((uint16)((uint16)(hi) << 8U) | (uint16)(lo))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_AssembleThreeBytes(lo, md, hi) (((uint32)(hi) << 16U) | ((uint32)(md) << 8U) | (lo))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_ExtractByteOne(val)            ((uint8)((val) & 0xFFU))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_ExtractByteTwo(val)            ((uint8)(((uint16)(val) >> 8U) & 0xFFU))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_ExtractByteThree(val)          ((uint8)(((uint32)(val) >> 16U) & 0xFFU))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_ExtractByteFour(val)           ((uint8)(((uint32)(val) >> 24U) & 0xFFU))

/* PGN access and check macros. */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_PGN_GetDP(pgn)                 (J1939Tp_ExtractByteThree(pgn) & 0x03U)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_PGN_GetPDUF(pgn)               J1939Tp_ExtractByteTwo(pgn)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_PGN_GetPDUS(pgn)               J1939Tp_ExtractByteOne(pgn)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_PGN_IsPDU2(pgn)                (J1939Tp_PGN_GetPDUF(pgn) >= 0xF0U)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_PGN_ValidDP(pgn)               (J1939Tp_PGN_GetDP(pgn) != 0x03U)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_PGN_ValidPDUS(pgn)             (J1939Tp_PGN_IsPDU2(pgn) || (J1939Tp_PGN_GetPDUS(pgn) == 0x00U))
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_PGN_Valid(pgn)                 (J1939Tp_PGN_ValidDP(pgn) && J1939Tp_PGN_ValidPDUS(pgn))

/* (E)TP.CM access and check macros. */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_Get_TMS(tms_lo, tms_hi)        J1939Tp_AssembleTwoBytes(tms_lo, tms_hi)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_Make_TMS_LO(tms)               J1939Tp_ExtractByteOne(tms)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_Make_TMS_HI(tms)               J1939Tp_ExtractByteTwo(tms)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_Get_Packets(size)              J1939Tp_RoundUp(size, J1939TP_TPDT_DATA_SIZE)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_Get_PGN(pgn_lo, pgn_md, pgn_hi) J1939Tp_AssembleThreeBytes(pgn_lo, pgn_md, pgn_hi)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_Make_PGN_LO(pgn)               J1939Tp_PGN_GetPDUS(pgn)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_Make_PGN_MD(pgn)               J1939Tp_PGN_GetPDUF(pgn)
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_Make_PGN_HI(pgn)               J1939Tp_PGN_GetDP(pgn)

/* MDL access macros. */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define J1939Tp_MDL_Get_PRI(pri)               ((pri) & J1939TP_PRIORITY_MASK)

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

#define J1939TP_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

extern FUNC(void, J1939TP_CODE) J1939Tp_ReportDevError(uint8 apiId, uint8 errorId);
extern FUNC(void, J1939TP_CODE) J1939Tp_ReportRuntimeError(uint8 apiId, uint8 errorId);

#define J1939TP_STOP_SEC_CODE
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "J1939Tp_MemMap.h"

#endif /* J1939TP_INT_H_ */

