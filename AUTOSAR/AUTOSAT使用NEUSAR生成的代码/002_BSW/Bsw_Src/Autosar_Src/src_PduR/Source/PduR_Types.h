/*
********************************************************************************
*
*  File name: PduR_Types.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 2.0
* Author/Date: ZhangDX/2019.11.12
* Change: New create.
* Cause: New
********************************************************************************
* Version: 2.1
* Author/Date: ZhangDX/2019.10.12
* Change: 1. Modify the code format.
*         2. add Buffer allocation.
* Cause: Optimize
********************************************************************************
* Version: 2.2
* Author/Date: ZhangDX/2019.11.12
* Change: add Buffer allocation.
* Cause: Update
********************************************************************************
* Version: 2.3
* Author/Date: ZhangDX/2019.11.13
* Change: Add the configuration item whether the gateway function is supported.
* Cause: Update
********************************************************************************
* Version: 2.4
* Author/Date: ZhangDX/2019.12.03
* Change: Modify the inclusion relationship of header file, and add PduR_Cfg.h
*        inclusion.
* Cause: Update
********************************************************************************
* Version: 2.5
* Author/Date: ZhangDX/2019.12.09
* Change: 1. PDUR_USE_TP_BUFFER -> PDUR_SUPPORT_GETWAY.
*         2. Add pre-compilation options.
* Cause: Update
********************************************************************************
* Version: 2.6
* Author/Date: ZhangDX/2019.12.10
* Change: Add comments.
* Cause: Update
********************************************************************************
* Version: 2.7
* Author/Date: ZhangDX/2020.01.06
* Change: 1. Delete the PduR module reference Std_Types.h and replace it with
*           ComStack_Types.h.
*         2. Remove redundant "ComStack_Cfg.h" and "ComStack_Types.h" files.
* Cause: Update
********************************************************************************
* Version: 2.8
* Author/Date: ZhangDX/2020.01.09
* Change: Modify the configuration item name TRIGGER_TRANSMIT-> TRIGGERTRANSMIT.
* Cause: Update
********************************************************************************
* Version: 2.9
* Author/Date: ZhangDX/2020.02.19
* Change: 1. Modify the structure definition to support the implementation of
*           API: PduR_DisableRouting.
* Cause: Update
********************************************************************************
* Version: 2.10
* Author/Date: ZhangDX/2020.03.13
* Change: 1. Change the module Id defined under PduRDestAndSrcID_Type to the
*           module ID of AutoSAR.
*         2. And if there are duplicates, one bit is added.
* Cause: Update
********************************************************************************
* Version: 2.11
* Author/Date: ZhangDX/2020.03.25
* Change: 1. Add notes.
*         2. Perform a QAC check and correct any errors that occur.
* Cause: Optimize
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2020.03.27
* Change: 1. Updated version information is 3.0.0.
*         2. Fix the type mismatch problem.
*         3. PDUR_DEST_SRC_IF_ID_IPDUM = PDUR_DEST_SRC_UP_ID_IPDUM.
* Cause: Bugfix, Clear QAC warning and updata to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: ZhangDX/2020.04.16
* Change: Add PduR_Cfg.h header file included.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: ZhangDX/2020.07.13
* Change: Replace "req" with "Req".
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: ZhangDX/2020.07.14
* Change: 1. Modify the structure element with the same name.
*         2. Delete PduRPathSupportGetWay.
*         3. Update the gateway function of the communication interface layer and
*            the FIFO function of the gateway.
*         4. Update the code format.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: ZhangDX/2020.08.18
* Change: 1. Add an invalid RoutingPathGroupId so that no group reference is
*            made to the destination PDU.
*         2. Increase the judgment of invalid RoutingPathGroupId.
*         3. Increase the data type PduRBswModules_Type.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: ZhangDX/2020.08.20
* Change: Support configuration items PduRTxConfirmation, PduRTriggerTransmit
*         and PduRRetransmission.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: ZhangDX/2020.08.26
* Change: 1. In order to adapt to the current CanTp protocol implementation
*            logic, increase the size element actually applied for the buffer,
*            and use this element to calculate the remaining buffer.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: ZhangDX/2020.09.25
* Change: 1. Modify the errors that occurred during the code review on 2020.09.23.
*         2. Optimizing the code review on 2020.09.23 is a suggestion item given.
*         3. Move the macro definitions related to the generated function to
*            the PduR_Types.h file.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: ZhangDX/2020.09.27
* Change: Complete AutoSAR code style conversion.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: ZhangDX/2020.09.29
* Change: Add MemMap section.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: ZhangDX/2020.10.06
* Change: Add PostBuild function.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: ZhangDX/2020.10.09
* Change: Modify the element type in PduRDstPduThreshold_Type to boolean.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: ZhangDX/2020.10.10
* Change: Add the macro definition for judging the FIFO function.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: ZhangDX/2020.10.13
* Change: Optimize the implementation of PduRZeroCostOperation function code.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: ZhangDX/2020.10.15
* Change: Delete the macro definitions used to generate other module related
*         functions.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: ZhangDX/2020.10.28
* Change: Create a Pdu list data structure that supports the CDD module.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: ZhangDX/2020.11.03
* Change: Delete the segment definition in the type part.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: ZhangDX/2020.02.22
* Change: 1. Move PDUR_LOCAL_INLINE to the PduR_Types.h file.
*         2. Add pre-compiled code to judge the compiler, and implement
*            PDUR_LOCAL_INLINE according to the specific compiler.
*         3. Add the PDUR_LOCAL_FORCEINLINE macro definition to realize the
*            optimization of Changan, which can be added to the tool in the future.
*         4. The new macro definition PDUR_LOCAL_INLINE_CORE is used for specific
*            project optimization.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: ZhangDX/2021.06.30
* Change: Set the PDUR_LOCAL_FORCEINLINE macro definition to STD_OFF and add it
*         to the file.
* Cause: Optimization
********************************************************************************
********************************************************************************
* Version: 3.19
* Author/Date: ZhangDX/2021.9.21
* Change: Solve the problem of duplication of DET parameters of PduR module.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: SunHQ/2022.9.13
* Change: Add new members to PduR_TpBuffer_Type.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: SunHQ/2021.09.20
* Change: 1. Add new member to PduRDestPdu_Type & PduRSrcPdu_Type.
*         2. Add the definition of PduR_BufferHeaderType & PduR_BufferType.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: SunHQ/2023.02.10
* Change: 1. Declare the data types associated with diagnostic functions.
*         2. Modify the macro that controls the code implementation.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: SunHQ/2023.02.28
* Change: Add new member to PduR_TpBuffer_Type when multi-core is enabled.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: SunHQ/2023.03.24
* Change: Change the member counter of PduR_TimerType from uint16 to uint32.
* Cause: Bugfix
********************************************************************************
* Version: 3.25
* Author/Date: LuQ/2023.12.04
* Change: 1. Modify the included header file.
*         2. Add multicast macro definition.
* Cause: Bugfix
********************************************************************************
* Version: 3.26
* Author/Date: LuQ/2024.04.02
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.27
* Author/Date: LuQ/2024.08.14
* Change: Move application type definitions to RTE.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: LuQ/2024.09.23
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.29
* Author/Date: LuQ/2025.03.12
* Change: PduR multicast supports 1:32.
* Cause: Optimization
********************************************************************************
* Version: 3.30
* Author/Date: LuQ/2025.03.26
* Change: Add the definition of PduRZeroCostRout_Type.
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: LuQ/2025.06.24
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef PDUR_TYPES_H_
#define PDUR_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "PduR_Cfg.h"
#include "Os.h"
#include "Rte_PduR_Type.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* PduR encapsulation of E_OK and E_NOT_OK. */
#define PDUR_E_OK                                   ((Std_ReturnType)(E_OK))
#define PDUR_E_NOT_OK                               ((Std_ReturnType)(E_NOT_OK))
/* Encapsulate TRUE and FALSE PduR. */
#define PDUR_TRUE                                   (boolean)(TRUE)
#define PDUR_FALSE                                  (boolean)(FALSE)

/* Define init Num. */
#define PDUR_INIT_0                                 (0x00U)
#define PDUR_INIT_1                                 (0x01U)
#define PDUR_INIT_6                                 (0x06U)

/* Define index num. */
#define PDUR_IDX_0                                  (0U)
#define PDUR_IDX_1                                  (1U)
#define PDUR_IDX_2                                  (2U)
#define PDUR_IDX_3                                  (3U)

/* PduR Error ID Define Start. */
#define PDUR_E_NO_ERROR                             (uint8)(0xFFU)
/* Req: SWS_PduR_00100 */
/* Invalid configuration pointer. */
#define PDUR_E_INIT_FAILED                          (uint8)(0x00U)

/*
API service used without module initialization or PduR_Init called
in any state other than PDUR_UNINIT.
*/
#define PDUR_E_INVALID_REQUEST                      (uint8)(0x01U)
/* Invalid PDU identifier */
#define PDUR_E_PDU_ID_INVALID                       (uint8)(0x02U)
/*
If the routing table is invalid that is given to the PduR_EnableRouting
or PduR_DisableRouting functions.
*/
#define PDUR_E_ROUTING_PATH_GROUP_ID_INVALID        (uint8)(0x08U)
/* Null pointer has been passed as an argument. */
#define PDUR_E_PARAM_POINTER                        (uint8)(0x09U)
/* Configuration parameter error, requirement violation (SWS_PduR_00633). */
#define PDUR_E_CONFIG_PARAM_ERROR                   (uint8)(0x0BU)
/* PduR Error ID Define End   */
/* Req: SWS_PDUR_00816 */
/* TP module rejects a transmit request for a valid PDU identifier. */
#define PDUR_E_TP_TX_REQ_REJECTED                   (uint8)(0x03U)
/* Loss of a PDU instance (buffer overrun in gateway operation). */
#define PDUR_E_PDU_INSTANCES_LOST                   (uint8)(0x0AU)
/* Some warnings can be eliminated. */
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
#define PDUR_UNUSED(_data)                          (_data) = (_data)
/* Module attributes. Support up to 4094 modules. */
#define PDUR_MODULE_IS_UP                           (uint16)(0x1000U)
#define PDUR_MODULE_IS_IF                           (uint16)(0x2000U)
#define PDUR_MODULE_IS_TP                           (uint16)(0x4000U)
#define PDUR_MODULE_IS_MASK                         (uint16)(0xF000U)
#define PDUR_DEST_ID_END                            (uint16)(0x8FFFU)

/* Reference to the PduR_RoutingPathGroupIdType type: */
#define PDUR_INVALID_PATHGROUP_ID                   ((PduR_RoutingPathGroupIdType)0xFFFFU)

/* Reference to the PduRBswModules_Type type: */
/* Simplify obtaining ModuleID. */
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_MODULE(_pdu)                           (_pdu)->PduRModuleRef->PduRBswModuleRef
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_MODULE_TRIGGER_TRANSMINT(_pdu)         (_pdu)->PduRModuleRef->PduRTriggertransmit
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_MODULE_TX_CONFIRMATION(_pdu)           (_pdu)->PduRModuleRef->PduRTxConfirmation
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_MODULE_RETRY(_pdu)                     (_pdu)->PduRModuleRef->PduRRetransmission

/* Reference to the PduRTpBuffer_Type type: */
/* TxBufferFifo is full (Only useful in FIFO mode). */
#define PDUR_TX_BUFFER_IS_FULL                      (uint8)(0x04)
/* TxBufferFifo is busy. */
#define PDUR_TX_BUFFER_TX                           (uint8)(0x02)
/* TxBufferFifo is busy. */
#define PDUR_TX_BUFFER_BUSY                         (uint8)(0x01)
/* TxBufferFifo is idle. */
#define PDUR_TX_BUFFER_IDLE                         (uint8)(0x00)
/* TxBufferFifo is in TP use. */
#define PDUR_TX_BUFFER_TP_USE                       PDUR_TRUE
/* TxBufferFifo is not used in TP. */
#define PDUR_TX_BUFFER_TP_NOUSE                     PDUR_FALSE

/* There is a sending buffer and it is a FIFO function. */
#define PDUR_DEPTH_IS_FIFO                          (uint8)(1U)
/* There is a send buffer. */
#define PDUR_DEPTH_IS_VALID                         (uint8)(0U)
/*The initial value for multicast routing*/
#define PDUR_MUL_TAB_INVALID_IDX                    (uint16)(0xFFFFU)

/* Reference to the PduRDestPdu_Type type: */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_DEPTH(_dstPdu)                (_dstPdu)->PduRDestTxBufferRef->PduRTxBufferDepth
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_MAXLEN(_dstPdu)               (_dstPdu)->PduRDestTxBufferRef->PduRPduMaxLength

#if (STD_ON == PDUR_SUPPORT_GETWAY)

/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_TXBUF(_dstPdu)                (_dstPdu)->PduRDestTxBufferRef->PduRTxBuffer
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_USE_BUFFER(_dstPdu)           (_dstPdu)->PduRDestTxBufferRef->PduRTxBuffer->PduRTpUseBuffer
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_STATUS(_dstPdu)               (_dstPdu)->PduRDestTxBufferRef->PduRTxBuffer->PduRTxBufferStatus
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_TAIL(_dstPdu)                 (_dstPdu)->PduRDestTxBufferRef->PduRTxBuffer->PduRTxBufferTail
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_FRONT(_dstPdu)                (_dstPdu)->PduRDestTxBufferRef->PduRTxBuffer->PduRTxBufferFront
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_ALLOC_SIZE(_dstPdu)           (_dstPdu)->PduRDestTxBufferRef->PduRTxBuffer->PduR_AllocBufSize
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:12.1 [Justified:Unset] "NSCA_Polyspace_PduR_12.1" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_PDU(_dstPdu, _idx)            (_dstPdu)->PduRDestTxBufferRef->PduRTxBuffer->pduInfo[_idx]
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_PDU_DATE(_dstPdu, _idx)       (_dstPdu)->PduRDestTxBufferRef->PduRTxBuffer->pduInfo[_idx].SduDataPtr
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TXBUFFER_PDU_LEN(_dstPdu, _idx)        (_dstPdu)->PduRDestTxBufferRef->PduRTxBuffer->pduInfo[_idx].SduLength

#endif /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

/* Inline keyword definition. */
#define PDUR_INLINE                                 INLINE
/**
 Used to optimize code performance.
 Forced inline enable flag, STD_ON is to enable forced inline, STD_OFF is to prohibit forced inline.
 */
#define PDUR_LOCAL_FORCEINLINE                      STD_OFF
/* MISRA C:2012 Dir-1.1 */
/* Mandatory inline encapsulation. */
/* IAR Compiler */
#if defined ( __ICCARM__ )
    #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE))
    #define PDUR_LOCAL_INLINE                       static __attribute__((always_inline)) inline
    #else   /* #ifndef PDUR_LOCAL_FORCEINLINE */
    #define PDUR_LOCAL_INLINE                       static inline
    #endif  /* #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE)) */

/* Arm Compiler 6 (armclang) */
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE))
    #define PDUR_LOCAL_INLINE                       static __attribute__((always_inline)) inline
    #else   /* #ifndef PDUR_LOCAL_FORCEINLINE */
    #define PDUR_LOCAL_INLINE                       static inline
    #endif  /* #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE)) */

/* GNU Compiler */
#elif defined ( __GNUC__ )
    #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE))
    #define PDUR_LOCAL_INLINE                       static __attribute__((always_inline)) inline
    #else   /* #ifndef PDUR_LOCAL_FORCEINLINE */
    #define PDUR_LOCAL_INLINE                       static inline
    #endif  /* #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE)) */

#elif defined ( __ghs__ )
    #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE))
    #define PDUR_LOCAL_INLINE                       static __attribute__((always_inline)) inline
    #else   /* #ifndef PDUR_LOCAL_FORCEINLINE */
    #define PDUR_LOCAL_INLINE                       static inline
    #endif  /* #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE)) */

#else   /* Other Compiler. */
    #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE))
    #define PDUR_LOCAL_INLINE                       LOCAL_INLINE
    #else   /* #ifndef PDUR_LOCAL_FORCEINLINE */
    #define PDUR_LOCAL_INLINE                       LOCAL_INLINE
    #endif  /* #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE)) */
#endif  /* #if defined ( __ICCARM__ ) */

/* Cancel the macro definition about INLINE judgment. */
#if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE))
/* MISRA C:2012 Rule-20.5 */
#undef PDUR_LOCAL_FORCEINLINE
#endif  /* #if ((defined PDUR_LOCAL_FORCEINLINE) && (STD_ON == PDUR_LOCAL_FORCEINLINE)) */
/* The optimized code is specific to Changan and needs to be deleted in other projects. */
#define PDUR_LOCAL_INLINE_CORE                      PDUR_LOCAL_INLINE
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
Name: PduRDestAndSrcID_Type
Brief: PDUR module routing destination&source type, using Module ID instead.
*/
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_PduR_2.3" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef uint16 PduRDestAndSrcID_Type;

/*
Name: PduR_PBConfigIdType
Brief: This type is returned by the PduR_GetConfigurationId API.
*/
typedef uint16 PduR_PBConfigIdType;

/*PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_INVALID_PATHGROUP_ID       ((PduR_RoutingPathGroupIdType)0xFFFFU)

/* The definition of Pdu in Ecuc. */
#if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH))
enum EcucEnumerationParamDef
{
    UINT8 = 0,
    UINT16 = 1,
    UINT32 = 2
};
typedef enum EcucEnumerationParamDef EcucEnumerationParamDef_Type;

struct EcucParamConfContainerDef
{
    VAR(boolean, TYPEDEF) J1939Requestable;
    VAR(uint8, TYPEDEF) MeteDataLength;
    VAR(uint32, TYPEDEF) PduLength;
#if SUPPORT_METE_DATA
    SysTPduToFrameTriggeringRef
    SysTPduToPduTriggeringRef
#endif  /* #if SUPPORT_METE_DATA */
};
typedef struct EcucParamConfContainerDef EcucParamConfContainerDef_Type;

struct EcucPduCollection
{
    VAR(EcucEnumerationParamDef_Type, TYPEDEF) PduIdTypeEnum;
    VAR(EcucEnumerationParamDef_Type, TYPEDEF) PduLengthTypeEnum;
    P2VAR(EcucParamConfContainerDef_Type, TYPEDEF, PDUR_APPL_DATA) EcucParamConfContainerDef;
};
typedef struct EcucPduCollection EcucPduCollection_Type;
#endif  /* #if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH)) */
/* The definition of Pdu in Ecuc. */

/*
Name: PduR_StateType
Brief: States of the PDU Router.
Req: SWS_PduR_00324
*/
enum PduR_StateType_enum
{
    /* PDU Router not initialised. */
    PDUR_UNINIT = (0x00U),
    /* PDU Router initialized successfully. */
    PDUR_ONLINE = (0x01U)
};
typedef enum PduR_StateType_enum PduR_StateType;

/*
Name: PduRDestPduDataProvision_Type
Brief: config type.
*/
enum PduRDestPduDataProvision_Type_enum
{
    /*
    The PDU Router module shall call the transmit function in the
    destination module and not buffer the I-PDU.
    */
    PDUR_DIRECT = (0x00U),
    /*
    The PDU Router module shall call the transmit function in
    the destination module.
    */
    PDUR_TRIGGERTRANSMIT = (0x01U)
};
typedef enum PduRDestPduDataProvision_Type_enum PduRDestPduDataProvision_Type;

/*
Name: tag_PduRBswModules
Brief: Represents one table of routing paths.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRBswModules
{
    /* Specifies if the Transport protocol module supports the CancelReceive API or not. Value true the API is supported. */
    VAR(boolean, TYPEDEF) PduRCancelReceive;
    VAR(boolean, TYPEDEF) PduRCancelTransmit;
    VAR(boolean, TYPEDEF) PduRChangeParameterApi;
    VAR(boolean, TYPEDEF) PduRCommunicationInterface;
    VAR(boolean, TYPEDEF) PduRLowerModule;
    VAR(boolean, TYPEDEF) PduRRetransmission;
    VAR(boolean, TYPEDEF) PduRTransportProtocol;
    VAR(boolean, TYPEDEF) PduRTriggertransmit;
    VAR(boolean, TYPEDEF) PduRTxConfirmation;
    VAR(boolean, TYPEDEF) PduRUpperModule;
    VAR(boolean, TYPEDEF) PduRUseTag;
    VAR(uint16, TYPEDEF) PduRBswModuleRef;
};
typedef struct tag_PduRBswModules PduRBswModules_Type;

/*
Name: PduRDefaultValueElement
Brief: Each value element is represented by the element and the position in an array.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRDefaultValueElement
{
    /* The default value consists of a number of elements.  */
    CONST(uint8, TYPEDEF) PduRDefaultValueElement;
    /*
    This parameter specifies the byte position of the element
    within the default value.
    */
    CONST(uint32, TYPEDEF) PduRDefaultValueElementBytePosition;
};
typedef struct tag_PduRDefaultValueElement PduRDefaultValueElement_Type;

/*
Name: PduRDefaultValue
Brief: Specifies the default value of the I-PDU.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRDefaultValue
{
    /* The default buffer size. */
    CONST(uint16, TYPEDEF) maxDefaultValueElementSize;
    /*
    Each value element is represented by the element and the
    position in an array.
    */
    /* Multiplicity: 0..*. */
    P2CONST(PduRDefaultValueElement_Type, TYPEDEF, PDUR_APPL_CONST) PduRDefaultValueElement;
};
typedef struct tag_PduRDefaultValue PduRDefaultValue_Type;

#if (STD_ON == PDUR_SUPPORT_GETWAY)

/*
Name: PduRTpBuffer
Brief: Specifies a buffer used for gatwaying through TP.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRTpBuffer
{
    /* Length of the TP buffer in number of bytes */
    /* Multiplicity: 1..1. */
    CONST(uint32, TYPEDEF) PduRTpBufferLength;
    /* TP buffer reference. */
    /* Multiplicity: 1..1. */
    CONSTP2VAR(uint8, TYPEDEF, PDUR_APPL_CONST) tpBufPtr;
};
typedef struct tag_PduRTpBuffer PduRTpBuffer_Type;

/*
Name:: PduR_TxBuffer
Brief:: Used to save the TxBuffer buffer.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct PduR_TxBuffer
{
#if (STD_ON == PDUR_SUPPORT_GETWAY)
    /* The status standard uses this buffer (TRUE) and does not apply this buffer (FALSE). */
    VAR(boolean, TYPEDEF) PduRTpUseBuffer;
    /* The buffer status is free(FALSE) and busy(TRUE). */
    VAR(uint8, TYPEDEF) PduRTxBufferStatus;
    /* Buffer pointer. */
    VAR(uint8, TYPEDEF) PduRTxBufferTail;
    /* Pointer to the head of the queue. */
    VAR(uint8, TYPEDEF) PduRTxBufferFront;
    /* The length of the buffer actually requested. */
    VAR(PduLengthType, TYPEDEF) PduR_AllocBufSize;
#endif /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

    CONSTP2VAR(PduInfoType, TYPEDEF, PDUR_APPL_CONST) pduInfo;
};
typedef struct PduR_TxBuffer PduRTxBufferFifo_Type;
#endif /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

/*
Name: PduRTxBuffer
Brief: Specifies a buffer used for gatewaying via communication interfaces
       or for single frames of transport protocols.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRTxBuffer
{
    /* Number of Pdus that can be stored in the buffer. */
    /* Multiplicity: 1..1. */
    CONST(uint8, TYPEDEF) PduRTxBufferDepth;
    /* Length of the Tx buffer in bytes. */
    /* Multiplicity: 1..1. */
    CONST(uint32, TYPEDEF) PduRPduMaxLength;
#if (STD_ON == PDUR_SUPPORT_GETWAY)
    /* Reference the send buffer. */
    /* Multiplicity: 1..1. */
    CONSTP2VAR(PduRTxBufferFifo_Type, TYPEDEF, PDUR_APPL_CONST) PduRTxBuffer;
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */
};
typedef struct tag_PduRTxBuffer PduRTxBuffer_Type;

/*
Name: PduRDestPdu
Brief: This container is a subcontainer of PduRRoutingPath and specifies
       one destination for the PDU to be routed.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRDestPdu
{
    /* This parameter is only for communication interfaces. */
    /* Multiplicity: 0..1. */
    CONST(boolean, TYPEDEF) PduRTransmissionConfirmation;
    /* Not autoSar -> PduR Dest pdu module Id */
    /* Multiplicity: 1..1. */
    CONSTP2CONST(PduRBswModules_Type, TYPEDEF, PDUR_APPL_CONST) PduRModuleRef;
    /* Not autoSar -> Identification of the routing group. */
    /* Note: : Add points to groupID element for easy lookup. */
    /* Multiplicity: 1..1. */
    VAR(PduR_RoutingPathGroupIdType, TYPEDEF) PduRRoutingPathGroupIdRef;
    /* Index of the destination PDU list. */
    /* Multiplicity: 1..1. */
    CONST(uint16, TYPEDEF) PduRDestPduIdx;
    /* Route path ID reference. */
    /* Multiplicity: 1..1. */
    CONST(uint16, TYPEDEF) PduRRoutPathRefId;
    /*
    Reference to unique PDU identifier which shall be used by the PDU Router
    instead of the source PDU ID when calling the related function of the d-
    estination module.
    */
#if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH))

    /* Multiplicity: 1..1. */
    P2CONST(EcucParamConfContainerDef_Type, TYPEDEF, PDUR_APPL_CONST) PduRDestPduRef;

#else   /* #if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH)) */

    /* Multiplicity: 1..1. */
    CONST(uint16, TYPEDEF) PduRDestPduRef;

#endif  /* #if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH)) */

    /* PDU identifier assigned by PDU Router. */
    /* Multiplicity: 0..1. */
    CONST(uint16, TYPEDEF) PduRDestPduHandleId;
    /* This parameter is only relevant for TP routings. */
    /* Multiplicity: 0..1. */
    CONST(uint16, TYPEDEF) PduRTpThreshold;
    /*
    Specifies how data are provided: direct (as part of the Transmit call) or
    via the TriggerTransmit callback function.
    */
    /* Multiplicity: 0..1. */
    CONST(PduRDestPduDataProvision_Type, TYPEDEF) PduRDestPduDataProvision;
    /* Reference to a buffer that is allocated in the PduRTxBufferTable. */
    /* Multiplicity: 0..1. */
    CONSTP2VAR(PduRTxBuffer_Type, TYPEDEF, PDUR_APPL_CONST) PduRDestTxBufferRef;
    /* Specifies the default value of the I-PDU. */
    /* Multiplicity: 0..1. */
    CONSTP2CONST(PduRDefaultValue_Type, TYPEDEF, PDUR_APPL_CONST) PduRDefaultValue;

#if (STD_ON == PDUR_SUPPORT_MULTICORE)

    /* Reference to EcucPartition, where the according Pdu is assigned to */
    CONST(uint16, TYPEDEF) PduRPartitionRef;

#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
    CONST(uint16, TYPEDEF) PdurMulTabIdx;
};
typedef struct tag_PduRDestPdu PduRDestPdu_Type;

#if (STD_ON == PDUR_SUPPORT_GETWAY)
/*
Name: PduRDstPduThreshold
Brief: The status value used in the on-the-fly mode of the TP gateway of the destination PDU.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRDstPduThreshold
{
    VAR(boolean, TYPEDEF) pduRTpThrFlag;
};
typedef struct tag_PduRDstPduThreshold PduRDstPduThreshold_Type;
#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

/*
Name: PduRSrcPdu
Brief: This container is a subcontainer of PduRRoutingPath and specifies
       the source of the PDU to be routed.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRSrcPdu
{
    /* Not autoSar -> PduR Src pdu module Id */
    /* Multiplicity: 1..1. */
    CONSTP2CONST(PduRBswModules_Type, TYPEDEF, PDUR_APPL_CONST) PduRModuleRef;
    /* Source PDU reference. */
#if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH))

    /* Multiplicity: 1..1. */
    P2CONST(EcucParamConfContainerDef_Type, TYPEDEF, PDUR_APPL_CONST) PduRSrcPduRef;

#else   /* #if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH)) */

    /* Multiplicity: 1..1. */
    CONST(uint16, TYPEDEF) PduRSrcPduRef;

#endif  /* #if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH)) */

    /* PDU identifier assigned by PDU Router. */
    /* Multiplicity: 0..1. */
    CONST(uint16, TYPEDEF) PduRSourcePduHandleId;
    /* When enabled, the TxConfirmation will be forwarded to the upper layer. */
    /* Multiplicity: 0..1. */
    CONST(boolean, TYPEDEF) PduRSrcPduUpTxConf;

#if (STD_ON == PDUR_SUPPORT_MULTICORE)

    /* Reference to EcucPartition, where the according Pdu is assigned to */
    CONST(uint16, TYPEDEF) PduRPartitionRef;

#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */
};
typedef struct tag_PduRSrcPdu PduRSrcPdu_Type;

/*
Name: PduRRoutingPath
Brief: This container is a subcontainer of PduRRoutingTable and specifies
       the routing path of a PDU.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRRoutingPath
{
    /* Reference to the destination Pdu. */
    /* Multiplicity: 1..*. */
    CONSTP2CONST(PduRDestPdu_Type, TYPEDEF, PDUR_APPL_CONST)* PduRDestPdu;
    /* Reference to the source Pdu. */
    /* Multiplicity: 1..1. */
    CONSTP2CONST(PduRSrcPdu_Type, TYPEDEF, PDUR_APPL_CONST) PduRSrcPdu;
};
typedef struct tag_PduRRoutingPath PduRRoutingPath_Type;

/*
Name: PduRRoutingPathGroup
Brief: This container groups routing path destinations.
       Destinations are used instead of routing paths since a routing path
       can be 1:n. It is desirable to be able to enable/disable a specific
       bus (i.e. a destination) rather than a routing path.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduR_RoutingPathGroup
{
    /*
    If set to true this routing path group will be enabled after initializing
    the PDU Router module.
    */
    /* Multiplicity: 1..1. */
    VAR(boolean, TYPEDEF) PduRIsEnabledAtInit;
    /* Identification of the routing group. */
    /* Multiplicity: 1..1. */
    CONST(PduR_RoutingPathGroupIdType, TYPEDEF) PduRRoutingPathGroupId;
    /* This reference selects one destination of the routing path. */
    /* Multiplicity: 1..*. */
    CONSTP2CONST(PduRDestPdu_Type, TYPEDEF, PDUR_APPL_CONST)* destPduRef;
};
typedef struct tag_PduR_RoutingPathGroup PduRRoutingPathGroup_Type;

/*
Name: PduRRoutingTable
Brief: Represents one container of routing paths.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRRoutingTable
{
    /* Multiplicity: 0..*. */
    P2CONST(PduRRoutingPath_Type, TYPEDEF, PDUR_APPL_CONST) PduRRoutingPathRef;
};
typedef struct tag_PduRRoutingTable PduRRoutingTable_Type;

#if (STD_ON == PDUR_SUPPORT_GETWAY)

/*
Name: PduRTpBufferTable
Brief: This container will specify the needed buffers for gatewaying using TP.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRTpBufferTable
{
    /* Multiplicity: 1..1. */
    CONST(uint16, TYPEDEF) PduRMaxTpBufferNumber;
    /* Multiplicity: 0..*. */
    CONSTP2CONST(PduRTpBuffer_Type, TYPEDEF, PDUR_APPL_CONST) PduRTpBufferRef;
};
typedef struct tag_PduRTpBufferTable PduRTpBufferTable_Type;

#endif /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

#if ((STD_ON == PDUR_SUPPORT_GETWAY) || (defined PDUR_SUPPORT_TP_GETWAY))
/*
Name: PduRTpBufferStatus_type
Brief: tpBuf Status Record.
*/
enum PduR_TpBufferStatus_enum
{
    PDUR_BUFFER_RX_READY = 0x01U,
    PDUR_BUFFER_RX_BUSY = 0x02U,
    PDUR_BUFFER_FREE = 0x04U
};
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_PduR_2.3" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef enum PduR_TpBufferStatus_enum PduR_TpBufferStatus_type;

/* Used to save TpBuffer state. */
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
struct tag_PduR_TpBuffer
{
    /* SWS_PDUR_00813. */
    /*
    All destination PDUs used to identify a routing
    path are sorted according to the routing path.
    From bit 0 to bit 15, a total of 16 destinations
    are supported.
    */
#if (STD_ON == PDUR_SUPPORT_MULTICORE)
    /* Current partition id */
    VAR(uint16, TYPEDEF) partitionId;
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE)*/
    VAR(PduRMultiCastType, TYPEDEF) dstPduMask;
    /* The mask value is saved for use. */
    VAR(PduRMultiCastType, TYPEDEF) dstPduMaskSave;
    /* The route ID used by the buffer. */
    VAR(PduIdType, TYPEDEF) usedId;
    /* The length of the buffer actually requested. */
    VAR(PduLengthType, TYPEDEF) allocBufLen;
    /* Data copy pointer. */
    VAR(PduLengthType, TYPEDEF) copyRxPointer;
    /* Data copy pointer. */
    VAR(PduLengthType, TYPEDEF) copyTxPointer;
    /* First node pointer. */
    VAR(PduLengthType, TYPEDEF) firstNodePointer;
    /* Last node pointer. */
    VAR(PduLengthType, TYPEDEF) lastNodePointer;
    /* The actual used buffer length. */
    VAR(PduLengthType, TYPEDEF) usedBufferLength;
    /* The last copied pdu length. */
    VAR(PduLengthType, TYPEDEF) lastTxPduLength;
    /* buffer status. */
    VAR(uint8, TYPEDEF) bufStatus;
    /* Point to the actual buffer. */
    P2CONST(PduRTpBuffer_Type, TYPEDEF, PDUR_APPL_CONST) pdurTpBufPtr;
};
/* PolySpace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.5" */
typedef struct tag_PduR_TpBuffer PduR_TpBuffer_Type;
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TP_BUFFER(_tpBuf)          (_tpBuf)->pdurTpBufPtr->tpBufPtr
/* MISRA C:2012 Dir-4.9 */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define PDUR_TP_BUFFER_LEN(_tpBuf)      (_tpBuf)->pdurTpBufPtr->PduRTpBufferLength
#endif  /* #if ((STD_ON == PDUR_SUPPORT_GETWAY) || (defined PDUR_SUPPORT_TP_GETWAY)) */

/*
Name: PduRTxBufferTable.
Brief: This container contains the buffers used for gatewaying via
       communication interfaces and for single frames of transport
       protocols.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRTxBufferTable
{
    CONST(uint32, TYPEDEF) PduRMaxTxBufferNumber;
    /*
    Specifies a buffer used for gatewaying via communication inter-
    faces or for single frames of transport protocols.
    */
    /* Multiplicity: 0..*. */
    CONSTP2VAR(PduRTxBuffer_Type, TYPEDEF, PDUR_APPL_CONST) PduRTxBufferPtr;
};
typedef struct tag_PduRTxBufferTable PduRTxBufferTable_Type;

#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))
/*
Name: PduR_TpMulStruct
Brief: The structure used to implement TP multicast.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct PduR_TpMulStruct
{
    /* Record the status returned by TpTxConfirmation. Implement SWS_PduR_00765 requirements. */
    VAR(Std_ReturnType, TYPEDEF) result;
    /* Save the number of destination PDUs. */
    CONST(uint16, TYPEDEF) dstPduCnt;
    /* Calculate the number of destination PDUs. Accumulate in PduR_LoTpTxConfirmation. */
    VAR(uint16, TYPEDEF) dstPduCntDyn;
    /* Routing path ID. */
    CONST(uint16, TYPEDEF) routPathRefId;
    /* The status passed in when calling <LoTP> CopyTxData. */
    VAR(RetryInfoType, TYPEDEF) retryInfo;
};
typedef struct PduR_TpMulStruct PduRTpMul_Type;
#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */

#if ((defined PDUR_SUPPORT_IF_MULICAST) && (STD_ON == PDUR_SUPPORT_IF_MULICAST))
/*
Name: PduR_IfMulStruct.
Brief: The structure used to implement If multicast.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct PduR_IfMulStruct
{
    /* Save the number of destination PDUs. */
    CONST(uint16, TYPEDEF) dstPduCnt;
    /* Calculate the number of destination PDUs. */
    VAR(uint16, TYPEDEF) dstPduCntDyn;
    /* Routing path ID. */
    CONST(uint16, TYPEDEF) routPathRefId;
};
typedef struct PduR_IfMulStruct PduRIfMul_Type;
#endif  /* #if (STD_ON == PDUR_SUPPORT_IF_MULICAST) */

/*
Name: PduRRoutingTables.
Brief: Represents one table of routing paths.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduRRoutingTables
{
    /* Multiplicity: 1..1 */
    CONST(uint16, TYPEDEF) PduRConfigurationId;
    /* Multiplicity: 0..1. */
    CONST(uint16, TYPEDEF) PduRMaxRoutingPathCnt;
    /* Multiplicity: 0..1. */
    CONST(uint16, TYPEDEF) PduRMaxRoutingPathGroupCnt;
    /* Multiplicity: 0..1. */
    CONST(uint16, TYPEDEF) PduRMaxRoutingTableCnt;
    /* Multiplicity: 0..*. */
    CONSTP2VAR(PduRRoutingPathGroup_Type, TYPEDEF, PDUR_APPL_CONST) PduRRoutingPathGroup;
    /*
    Note: In the code implementation, only one of this parameter exists in
          the RoutingTable, as specified in the documentation, but it is
          easy to implement.
    */
    /* Multiplicity: 0..1. */
    P2CONST(PduRRoutingTable_Type, TYPEDEF, PDUR_APPL_CONST) PduRRoutingTable;
    /* Multiplicity: 0..*. */
    P2CONST(PduRDestPdu_Type, TYPEDEF, PDUR_APPL_CONST) PduRDestPduList;

#if (STD_ON == PDUR_SUPPORT_GETWAY)

#if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY))

    P2VAR(PduRDstPduThreshold_Type, TYPEDEF, PDUR_APPL_DATA) PduRDstPduThrPtr;
    /* Multiplicity: 0..1. */
    P2CONST(PduRTpBufferTable_Type, TYPEDEF, PDUR_APPL_CONST) PduRTpBufferTable;

#endif  /* #if ((defined PDUR_SUPPORT_TP_GETWAY) && (STD_ON == PDUR_SUPPORT_TP_GETWAY)) */

    /* Multiplicity: 0..1. */
    P2CONST(PduRTxBufferTable_Type, TYPEDEF, PDUR_APPL_CONST) PduRTxBufferTable;

#endif  /* #if (STD_ON == PDUR_SUPPORT_GETWAY) */

#if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST))

    P2VAR(PduRTpMul_Type, TYPEDEF, PDUR_APPL_DATA) PduR_TpMulPtr;

#endif  /* #if ((defined PDUR_SUPPORT_TP_MULICAST) && (STD_ON == PDUR_SUPPORT_TP_MULICAST)) */

#if ((defined PDUR_SUPPORT_IF_MULICAST) && (STD_ON == PDUR_SUPPORT_IF_MULICAST))

    P2VAR(PduRIfMul_Type, TYPEDEF, PDUR_APPL_DATA) PduR_IfMulPtr;

#endif  /* #if ((defined PDUR_SUPPORT_IF_MULICAST) && (STD_ON == PDUR_SUPPORT_IF_MULICAST)) */
};
typedef struct tag_PduRRoutingTables PduRRoutingTables_Type;

/* Create a Pdu list data structure about the CDD module. */
struct tag_PduR_Cdd_PduType
{
    /* TP of IF. */
    const uint8 pduApiType;     /* 1..1 */
    const uint16 pduIdx;        /* 1..1 */
#if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH))
    const EcucParamConfContainerDef_Type* PduRDestPduRef;    /* 1..1 */
#else   /* #if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH)) */
    const uint16 pduRef;        /* 1..1 */
#endif  /* #if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH)) */
    const uint16 pduHandleId;   /* 0..1 */
};
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_PduR_2.3" */
typedef struct tag_PduR_Cdd_PduType PduR_Cdd_PduType;

/*
Name: PduR_BufferHeader.
Brief: The structure used to implement header of PduR_Buffer.
*/
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_PduR_Dir4.8" */
struct tag_PduR_BufferHeader
{
    /* valid buffer size */
    uint32 validSize;
    /* position to read */
    uint32 readPos;
    /* position to write */
    uint32 writePos;
};
typedef struct tag_PduR_BufferHeader PduR_BufferHeaderType;

/*
Name: PduR_Buffer.
Brief: The structure used to implement buffer associated with queue.
*/
struct tag_PduR_Buffer
{
    /* buffer header */
    CONSTP2VAR(PduR_BufferHeaderType, TYPEDEF, PDUR_APPL_DATA) header;
    /* buffer address */
    CONSTP2VAR(uint8, TYPEDEF, PDUR_APPL_DATA) dataPtr;
    /* buffer size */
    CONST(uint32, TYPEDEF) dataSize;
    /* spinlock id */
    CONST(SpinlockIdType, TYPEDEF) spinlockId;
};
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_PduR_2.3" */
typedef struct tag_PduR_Buffer PduR_BufferType;

/*
Name: PduR_TimerType.
Brief: The structure is used to implement timer.
*/
struct tag_PduR_Timer
{
    /* elapsed time */
    uint32 counter;
    /* working status */
    uint8  status;
    /* reserved field */
    uint8  reserved;
};
typedef struct tag_PduR_Timer PduR_TimerType;

/*
Name: PduR_DiagTimerType.
Brief: The structure is used to implement timer for diagnostic.
*/
struct tag_PduR_DiagTimer
{
    /* P2 timer */
    PduR_TimerType p2;
    /* P2* timer */
    PduR_TimerType p2Ex;
    /* P6 timer */
    PduR_TimerType p6;
    /* P6* timer */
    PduR_TimerType p6Ex;
};
typedef struct tag_PduR_DiagTimer PduR_DiagTimerType;

/*
Name: PduR_UdsType.
Brief: The structure is used to hold diagnostic information.
*/
struct tag_PduR_Uds
{
    /* service identifier */
    uint8 sid;
    /* working status */
    uint8 status;
    /* nrc78 is received or not */
    uint8 hasRcvNrc;
    /* unused */
    uint8 resFlag;
};
typedef struct tag_PduR_Uds PduR_UdsType;

/*
Name: PduR_DiagPathType.
Brief: This structure is used to contain PDUs for diagnostic.
*/
struct tag_PduR_DiagPath
{
    /* PduId for diagnostic request */
    const uint16 pduId;
    /* PduId for diagnostic reponse */
    const uint16 resPduId;
    /* diagnostic information */
    PduR_UdsType uds;
    /* timer for diagnostic */
    PduR_DiagTimerType timer;
};
/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_PduR_2.3" */
typedef struct tag_PduR_DiagPath PduR_DiagPathType;

typedef struct
{ 
    /* Index of the source PDU. */
    uint16 pduRSourcePduHandleId;
    /* Index of the destination PDU list. */
    uint16 pduRDestPduHandleId;
    /* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_PduR_2.3" */
} PduR_ZeroCostRoute_Type;

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

#endif /* #define PDUR_TYPES_H_ */
