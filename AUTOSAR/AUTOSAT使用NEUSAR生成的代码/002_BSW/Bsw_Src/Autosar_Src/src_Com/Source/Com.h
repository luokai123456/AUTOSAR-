/*
********************************************************************************
*
* File name: Com.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Sunpengfei/2018.09.25
* Change: Add
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: Sunpengfei/2019.04.15
* Change: V2.0 release.
* Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2019.12.24
* Change: Modify some macro definitions and types.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.4.30
* Change: Modify the included header file.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.5.11
* Change: Modify code specification.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.5.11
* Change: Modify space.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: lizhiheng/2020.06.08
* Change: Add release software number.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: lizhiheng/2020.6.08
* Change: Modify code specification.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: lizhiheng/2020.6.30
* Change: Add data type.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: lizhiheng/2020.07.01
* Change: Upgrade to 3.1.0.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: lizhiheng/2020.09.29
* Change: Add Memap processing.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: lizhiheng/2020.09.30
* Change: Modify the coding style of AutoSar.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: lizhiheng/2020.10.13
* Change: Remove non-pointer coding modification.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: LiZH/2020.11.05
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: LiZH/2020.11.28
* Change: Add Det.h include.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: LiZH/2021.04.27
* Change: Modify version number to 3.2.0.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: LiZH/2021.11.1
* Change: Update versions.
* Cause: Optimize
********************************************************************************
* Version: 3.15
* Author/Date: LiXB/2022.09.16
* Change: Modify version number to 3.2.2.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: LiXB/2022.9.20
* Change: Add two head files for multi-core and function declaration of sub mainfunctions.
          Add two macros COM_RECEIVE and COM_TRANSMIT.
          Modify version number to 3.2.3.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: LiXB/2022.09.16
* Change: Modify version number to 3.2.4.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: LiXB/2022.10.20
* Change: Modify CCOREDBUG-1514
*          1. Delete redundant function declaration Com_MainFunctionRx and Com_MainFunctionTx
*          2. Modify version number to 3.2.5.
* Cause: BugFix
********************************************************************************
* Version: 3.19
* Author/Date: LiXB/2022.10.24
* Change: Modify version number to 3.2.6.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: LiXB/2022.11.1
* Change: 1. Modify CCOREDBUG-1658
             Delete head file Os.h, Os_Types_Lcfg.h, add Os_Types_Cfg.h.
*         2. Modify version number to 3.2.7.
* Cause: BugFix
********************************************************************************
* Version: 3.21
* Author/Date: LiXB/2022.11.16
* Change:  Modify version number to 3.2.8.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: LiXB/2022.11.21
* Change:  Modify version number to 3.2.9.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: LiXB/2022.11.25
* Change:  Modify version number to 3.2.10.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: LiXB/2022.12.5
* Change:  Modify version number to 3.2.11.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: LiXB/2022.12.16
* Change:  Modify version number to 3.2.12.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: HeZH/2023.01.13
* Change:  Modify version number to 3.2.13.
* Cause: Bugfix
********************************************************************************
* Version: 3.27
* Author/Date: HeZH/2023.02.27
* Change:  Add the data length macro definition corresponding to the data type.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: HeZH/2023.05.17
* Change:  Modify version number to 3.7.0.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: HeZH/2023.05.28
* Change:  Modify version number to 3.7.0.0.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: ChiXP/2023.08.10
* Change:  Modify version number to 3.8.0.0.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: TianSL/2023.09.18
* Change: Modify version number to 3.9.0.1.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: TianSL/2023.10.27
* Change: 1.Add two macros (COM_FLT_EPSILON,COM_DBL_EPSILON).
          2.Modify version number to 3.9.0.2.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: HeH/2023.12.04
* Change: 1.Modify Com_MainFunction_Tx.
          2.Modify Com_MainFunction_RouteSignals.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: ZhangF/2023.12.04
* Change: 1.Modify Com_MainFunction_Rx.
*         2.Update the version number to 3.9.0.3.
* Cause: Update
********************************************************************************
* Version: 3.35
* Author/Date: TianG/2023.12.04
* Change: Add external declarations for functions.
* Cause: Update
********************************************************************************
* Version: 3.36
* Author/Date: TianG/2023.12.19
* Change: Update the version number to 3.9.0.4.
* Cause: Update
********************************************************************************
* Version: 3.37
* Author/Date: LuQ/2024.02.20
* Change: Update the version number to 3.10.0.5.
* Cause: Update
********************************************************************************
* Version: 3.38
* Author/Date: LuQ/2024.03.12
* Change: Update the version number to 3.10.0.6.
* Cause: Update
********************************************************************************
* Version: 3.39
* Author/Date: LuQ/2024.04.02
* Change: 1. Update the version number to 3.10.0.7.
*         2. Modify the comments format.
* Cause: Update
*******************************************************************************
* Version: 3.40
* Author/Date: TianG/2024.04.07
* Change: 1.Update the version number to 3.11.0.8.
*         2.Remove external declarations for some functions.
*         3.Add Com_RxSigUbInVFilterFunc function definition.
* Cause: Update
********************************************************************************
*******************************************************************************
* Version: 3.41
* Author/Date: LuQ/2024.05.13
* Change: 1.Add MDT function code.
*         2.Add MemMap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.42
* Author/Date: LuQ/2024.07.25
* Change: Update the version number to 3.11.0.9.
* Cause: Update
********************************************************************************
* Version: 3.43
* Author/Date: LuQ/2024.08.12
* Change: 1.Support the interface Com_SendSignalWithMetaData.
*         2.Support the interface Com_SendSignalGroupWithMetaData.
*         3.Add the metadata length macro (COM_METADATA_LEN_ZERO).
* Cause: Update
********************************************************************************
* Version: 3.44
* Author/Date: LuQ/2024.08.26
* Change: Update the version number to 3.11.0.10.
* Cause: Update
********************************************************************************
* Version: 3.45
* Author/Date: LuQ/2024.09.19
* Change: Update the version number to 3.11.0.11.
* Cause: Update
********************************************************************************
* Version: 3.46
* Author/Date: LuQ/2024.09.30
* Change: Update the version number to 3.11.0.12.
* Cause: Update
********************************************************************************
* Version: 3.47
* Author/Date: LuQ/2024.10.09
* Change: Update the version number to 3.11.0.13.
* Cause: Update
********************************************************************************
* Version: 3.48
* Author/Date: LuQ/2024.11.11
* Change: Update the version number to 3.12.0.14.
* Cause: Update
********************************************************************************
* Version: 3.49
* Author/Date: LuQ/2024.11.21
* Change: Update the version number to 3.12.0.15.
* Cause: Update
********************************************************************************
* Version: 3.50
* Author/Date: LuQ/2024.12.26
* Change: Update the version number to 3.12.0.16.
* Cause: Update
********************************************************************************
* Version: 3.51
* Author/Date: LuQ/2025.02.11
* Change: Update the version number to 3.13.0.17.
* Cause: Update
********************************************************************************
* Version: 3.52
* Author/Date: LuQ/2025.02.28
* Change: 1.Update the version number to 3.13.0.18.
*         2.Add macro definitions for bit operations
* Cause: Update
********************************************************************************
* Version: 3.53
* Author/Date: LuQ/2025.03.11
* Change: 1.Optimize the way of obtaining signal types.
*         2.Update the version number to 3.13.0.19.
* Cause: Update
********************************************************************************
* Version: 3.54
* Author/Date: LuQ/2025.03.26
* Change: Update the version number to 3.13.0.20.
* Cause: Update
********************************************************************************
* Version: 3.55
* Author/Date: LuQ/2025.03.26
* Change: Include head file Com_Write.h, Com_Read.h.
* Cause: Update
********************************************************************************
* Version: 3.56
* Author/Date: LuQ/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
* Version: 3.57
* Author/Date: LuQ/2025.04.22
* Change: Update the version number to 3.14.0.21.
* Cause: Optimization
********************************************************************************
* Version: 3.58
* Author/Date: LuQ/2025.04.28
* Change: Define macros for comparing floating-point variables.
* Cause: Bugfix
********************************************************************************
* Version: 3.59
* Author/Date: LuQ/2025.05.12
* Change: 1. Optimized memory copy performance.
*         2. Update the version number to 3.14.0.22.
* Cause: Update
********************************************************************************
* Version: 3.60
* Author/Date: LuQ/2025.06.17
* Change: 1. Add the polyspace deviation suppression comment.
*         2. Update the version number to 3.14.0.23.
* Cause: Update
********************************************************************************
* Version: 3.61
* Author/Date: LuQ/2025.06.23
* Change: Update software version to 3.14.0.24.
* Cause: Bugfix
********************************************************************************
* Version: 3.62
* Author/Date: LuQ/2025.07.07
* Change: Update software version to 3.15.0.25.
* Cause: Update
********************************************************************************
* Version: 3.63
* Author/Date: LuQ/2025.07.23
* Change: Update software version to 3.15.0.26.
* Cause: Update
********************************************************************************
*/
#ifndef COM_H_
#define COM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "Com_Cfg.h"
#include "Com_Lcfg.h"
#include "Com_Cbk.h"
#include "PduR_Com.h"
#include "NeuLib.h"
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
#include "Com_Write.h"
#include "Com_Read.h"
#endif
#if( COM_DEV_ERROR_REPORT == STD_ON )
#include "Det.h"
#endif  /* COM_DEV_ERROR_REPORT == STD_ON */

#if( COM_MULTICORE_SUPPORT == STD_ON )
#include "Os_Types_Cfg.h"
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* PolySpace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define COM_VENDOR_ID                   (119U)      /* the vendor ID of this implementation. */
#define COM_MODULE_ID                   (50U)       /* the module ID of this implementation. */
#define COM_INSTANCE_ID                 (0U)        /* the instance ID of this implementation. */
#define COM_SW_MAJOR_VERSION            (3U)        /* Major version. */
#define COM_SW_MINOR_VERSION            (15U)       /* Minor version. */
#define COM_SW_PATCH_VERSION            (0U)        /* Patch level version. */
#define COM_SW_REVISION_VERSION         (26U)       /* Revision number. */

/* AUTOSAR Version. */
#define COM_AR_RELEASE_MAJOR_VERSION                  (4U)
#define COM_AR_RELEASE_MINOR_VERSION                  (2U)
#define COM_AR_RELEASE_REVISION_VERSION               (2U)

/* Com Bit Length. */
#define COM_1BYTE_BITLENGTH             (8U)
#define COM_2BYTE_BITLENGTH             (16U)
#define COM_3BYTE_BITLENGTH             (24U)
#define COM_4BYTE_BITLENGTH             (32U)
#define COM_8BYTE_BITLENGTH             (64U)

/* Com Byte Length. */
#define COM_4BYTELENGTH                 (4U)
#define COM_8BYTELENGTH                 (8U)

#define COM_E_OK                        (0x00U)
#define COM_E_NOK                       (0x01U)

#define COM_PDUGRP_VECTOR_INIT          (0x00U)

#ifndef COM_DUMMY_STATEMENT
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Com_17.8" */
#define COM_DUMMY_STATEMENT(v)             (v)=(v)
#endif
#define COM_E_NO_ERROR                     (0x00U) /* this code is used to detect that no error occurred. Det_ReportError() is not called. */
#define COM_E_PARAM                        (0x01U) /* the API service has been with a wrong parameter. */
#define COM_E_UNINIT                       (0x02U) /* the API service has been called before COM was initialized with Com_Init() or after a call to Com_DeInit(). */
#define COM_E_PARAM_POINTER                (0x03U) /* the API service has been called with a not expected NULL pointer. */
#define COM_E_INIT_FAILED                  (0x04U) /* the API service has been when COM was already initialized. */
#define COM_E_SKIPPED_TRANSMISSION         (0x05U) /* the API service has been when COM was already skipped. */

/* Com ServiceID. */
#define COM_SERVICEID_INIT                               (0x01U)
#define COM_SERVICEID_DEINIT                             (0x02U)
#define COM_SERVICEID_IPDUGROUPCONTROL                   (0x03U)
#define COM_SERVICEID_RECEPTIONDMCONTROL                 (0x06U)
#define COM_SERVICEID_GETSTATUS                          (0x07U)
#define COM_SERVICEID_GETVERSIONINFO                     (0x09U)
#define COM_SERVICEID_SENDSIGNAL                         (0x0AU)
#define COM_SERVICEID_RECEIVESIGNAL                      (0x0BU)
#define COM_SERVICEID_UPDATESHADOWSIGNAL                 (0x0CU)
#define COM_SERVICEID_SENDSIGNALGROUP                    (0x0DU)
#define COM_SERVICEID_RECEIVESIGNALGROUP                 (0x0EU)
#define COM_SERVICEID_RECEIVESHADOWSIGNAL                (0x0FU)
#define COM_SERVICEID_INVALIDATESIGNAL                   (0x10U)
#define COM_SERVICEID_INVALIDATESHADOWSIGNAL             (0x16U)
#define COM_SERVICEID_TRIGGERIPDUSEND                    (0x17U)
#define COM_SERVICEID_MAINFUNCTIONRX                     (0x18U)
#define COM_SERVICEID_MAINFUNCTIONTX                     (0x19U)
#define COM_SERVICEID_MAINFUNCTIONROUTESIGNALS           (0x1AU)
#define COM_SERVICEID_INVALIDATESIGNALGROUP              (0x1BU)
#define COM_SERVICEID_CLEARIPDUGROUPVECTOR               (0x1CU)
#define COM_SERVICEID_SETIPDUGROUP                       (0x1DU)
#define COM_SERVICEID_SENDDYNSIGNAL                      (0x21U)
#define COM_SERVICEID_RECEIVEDYNSIGNAL                   (0x22U)
#define COM_SERVICEID_SENDSIGNALGROUPARRAY               (0x23U)
#define COM_SERVICEID_RECEIVESIGNALGRPARRAY              (0x24U)
#define COM_SERVICEID_SWITCHIPDUTXMODE                   (0x27U)
#define COM_SERVICEID_TRIGGERIPDUSENDWITHMETADATA        (0x28U)
#define COM_SERVICEID_TXCONFIRMATION                     (0x40U)
#define COM_SERVICEID_TRIGGERTRANSMIT                    (0x41U)
#define COM_SERVICEID_RXINDICATION                       (0x42U)
#define COM_SERVICEID_COPYTXDATA                         (0x43U)
#define COM_SERVICEID_COPYRXDATA                         (0x44U)
#define COM_SERVICEID_TPRXINDICATION                     (0x45U)
#define COM_SERVICEID_STARTOFRECEPTION                   (0x46U)
#define COM_SERVICEID_TPTXCONFIRMATION                   (0x48U)

/* Com Module Inter Init Marco. */
#define COM_INIT_ZERO                                    (0U)   /* Com Init Value 0. */
#define COM_OPERAND_ONE                                  (1U)   /* Com Operand  1. */
#define COM_PDUGRPVECTOR_CLEARVALUE                      (0U)   /* Pdu Group Vector Clear Value. */
#define COM_IMSTATUS_ZERO                                (0U)   /* Com Inter Monitor Status Init. */
#define COM_IMCOUNTER_ZERO                               (0U)   /* Com Inter Monitor Counter Init. */
#define COM_LENGTH_ZERO                                  (0U)   /* Com Length Init. */
#define COM_INIT_FF                                      (0xFFU) /* Com Init Value FF. */
#define COM_INIT_U16FF                                   (0xFFFFU)              /* Com init uint16 value 0xffff */
#define COM_INIT_U24FF                                   (0xFFFFFFU)              /* Com init uint32 value 0xffffff */
#define COM_INIT_U32FF                                   (0xFFFFFFFFU)          /* Com init uint32 value 0xffffffff. */
#define COM_INIT_U64FF                                   (0xFFFFFFFFFFFFFFFFU)  /* Com init uint64 value 0xFFFFFFFFFFFFFFFFU. */

/* Com Init PDU. */
#define Com_PDUMINDLYCNT_ZERO                            (0U)   /* Init PDU Min Delay Counter 0. */
#define Com_PDUCYCCNT_ZERO                               (0U)   /* Init Tx Pdu Cycle Counter. */
#define Com_PDUMIXCYCCNT_ZERO                            (0U)   /* Init Tx Pdu MixCycle Counter (Mix Mode).*/
#define Com_PDUOFFSETCNT_ZERO                            (0U)   /* Delay Counter Process Start. */

/* Com value length. */
#define COM_U8S8_BITS                                    (8U)   /* Com value length 8. */
#define COM_U16S16_BITS                                  (16U)  /* Com value length 16. */
#define COM_U32S32_BITS                                  (32U)  /* Com value length 32. */
#define COM_U64S64_BITS                                  (64U)  /* Com value length 64. */

/* Com Receive or transmit*/
#if( COM_MULTICORE_SUPPORT == STD_ON )
#define COM_RECEIVE                                      (0U)
#define COM_TRANSMIT                                     (1U)
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

#define COM_FLT_EPSILON                                  (1E-5f)
#define COM_FLT_EPSILON_NEGATIVE                         (-1E-5f)
#define COM_DBL_EPSILON                                  (1E-9)
#define COM_DBL_EPSILON_NEGATIVE                         (-1E-9)

#define COM_ONE                                          (1U)
#define COM_TWO                                          (2U)
#define COM_THREE                                        (3U)
#define COM_FOUR                                         (4U)

#define COM_METADATA_LEN_ZERO                            (0U)

#if( COM_TXPDU_MDT_SUPPORT == STD_ON )
#define COM_MDTCOUNTER_ZERO                              (0U)  /* Com MDT Counter Init. */
#endif
/* PolySpace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/* Get backup signal value. */
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Com_2.5" */
#define Com_SIGNAL_GETSHADOWVALUE(shadowValue,type,sigInfo)        ((shadowValue) = (*((type*)sigInfo->sigRTEValue)))
#else
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Com_2.5" */
#define Com_SIGNAL_GETSHADOWVALUE(shadowValue,type,sigInfo)        ((shadowValue) = (*((type*)sigInfo->sigShadowValue)))
#endif
/* Get rte signal value. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Com_2.5" */
#define Com_SIGNAL_GETRTEVALUE(value,type,sigInfo)                 ((value) = (*((type*)sigInfo->sigRTEValue)))
/* Set shadowvalue signal value. */
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Com_2.5" */
#define Com_SIGNAL_SETSHADOWVALUE(setValue,type,sigInfo)           ((*((type*)sigInfo->sigRTEValue)) = (setValue))
#else
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Com_2.5" */
#define Com_SIGNAL_SETSHADOWVALUE(setValue,type,sigInfo)           ((*((type*)sigInfo->sigShadowValue)) = (setValue))
#endif
/* Signal  shadow to rte assignment. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" */
#define Com_SIGNALGRP_ASSIGNMENT(type,sigInfo)                     ((*((type*)sigInfo->sigRTEValue)) = (*((type*)sigInfo->sigShadowValue)))
/* Signal init replace Rte. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" */
#define Com_SIGNAL_INITREPLACE(type,sigInfo)                       ((*((type*)sigInfo->sigRTEValue)) = (*((type*)sigInfo->initvalue)))
/* Signal init replace Rte. */
#if( COM_RXWITHOUTSHADOWVALUE == STD_ON )
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" */
#define Com_SIGNAL_INITREPLACESHADOW(type,sigInfo)                 ((*((type*)sigInfo->sigRTEValue)) = (*((type*)sigInfo->initvalue)))
#else
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" */
#define Com_SIGNAL_INITREPLACESHADOW(type,sigInfo)                 ((*((type*)sigInfo->sigShadowValue)) = (*((type*)sigInfo->initvalue)))
#endif
/* Get retvalue set to point value. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:11.5 [Justified:Unset] "NSCA_Polyspace_Com_11.5" */
#define Com_SIGNAL_GETRTETODATAPTR(SignalDataPtr,type,sigInfo)     ((*(type*)SignalDataPtr)  = (*((type*)sigInfo->sigRTEValue)))
/* Get signal filter type. */
/* PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" PolySpace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Com_2.5" */
#define COM_GETFILTER_ALGOOFFILTERINFO(sigIdx)                     (Com_RxSignalInfo[sigIdx].signalFilterMonitor->acFilterAlgorithm)
#define Com_Memcpy32                                               NeuLib_memcpy32

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef struct
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Com_Dir4.8" */
{
    uint8 Com_PCConfigNeverUsed;
} Com_PCConfigType;

typedef Com_PCConfigType Com_ConfigType;

/* PolySpace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Com_2.3" */
typedef void (*Com_RxSigUbInVFilterFunc)
(
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) dataPtr,
    P2CONST(COM_RxSignalInfo_st, AUTOMATIC, COM_APPL_CONST) rxSigBasePtr,
    uint16 sigIdx
);

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define COM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"
extern P2VAR(Com_ConfigType, COM_VAR_INIT, COM_APPL_DATA) Com_ConfigDataPtr;
#define COM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#if( COM_PERFOPTMZ_SUPPORT == STD_ON )
extern CONST(Com_RxSigUbInVFilterFunc, COM_APPL_CONST) Com_RxSigUbInvFilterFuncTable[COM_RXPARSESIGNAL_FUNC_NUM + COM_ONE];
#endif

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define COM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"
extern FUNC(void, COM_CODE) Com_Init
(
    P2CONST(Com_ConfigType, AUTOMATIC, COM_APPL_CONST) config
);
extern FUNC(void, COM_CODE) Com_DeInit
(
    void
);
extern FUNC(void, COM_CODE) Com_IpduGroupControl
(
    Com_IpduGroupVector ipduGroupVector,
    boolean initialize
);
extern FUNC(void, COM_CODE) Com_ReceptionDMControl
(
    Com_IpduGroupVector ipduGroupVector
);
extern FUNC(Com_StatusType, COM_CODE) Com_GetStatus
(
    void
);
#if( COM_VERSIONINFOAPI_SUPPORT == STD_ON )
extern FUNC(void, COM_CODE) Com_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COM_APPL_DATA) versioninfo
);
#endif
extern FUNC(void, COM_CODE) Com_ClearIpduGroupVector
(
    Com_IpduGroupVector ipduGroupVector
);
extern FUNC(void, COM_CODE) Com_SetIpduGroup
(
    Com_IpduGroupVector ipduGroupVector,
    Com_IpduGroupIdType ipduGroupId,
    boolean bitval
);
extern FUNC(uint8, COM_CODE) Com_SendSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr
);
extern FUNC(uint8, COM_CODE) Com_SendDynSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    uint16 Length
);
extern FUNC(uint8, COM_CODE) Com_ReceiveSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);
extern FUNC(uint8, COM_CODE) Com_ReceiveDynSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_DATA) Length
);
extern FUNC(uint8, COM_CODE) Com_SendSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
);
extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
);
extern FUNC(uint8, COM_CODE) Com_InvalidateSignal
(
    Com_SignalIdType SignalId
);
#if( COM_SIGNALGROUPARRAY_SUPPORT == STD_ON )
extern FUNC(uint8, COM_CODE) Com_SendSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) SignalGroupArrayPtr
);
#endif
#if( COM_SIGNALGROUPARRAY_SUPPORT == STD_ON )
extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) SignalGroupArrayPtr
);
#endif
extern FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
);
extern FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSend
(
    PduIdType PduId
);
#if( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) )
extern FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSendWithMetaData
(
    PduIdType PduId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) MetaData
);
extern FUNC(uint8, COM_CODE) Com_SendSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) MetaDataPtr
);
extern FUNC(uint8, COM_CODE) Com_SendSignalGroupWithMetaData
(
    Com_SignalGroupIdType SignalGroupId, 
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) MetaDataPtr
);
#endif  /* ( (COM_METADATA_SUPPORT == STD_ON) && (COM_TXMETADATA_NUM > COM_INIT_ZERO) ) */
extern FUNC(void, COM_CODE) Com_SwitchIpduTxMode
(
    PduIdType PduId,
    boolean Mode
);
#if( COM_MULTICORE_SUPPORT == STD_ON )
extern FUNC(void, COM_CODE) Com_MainFunctionRx_Can
(
    void
);
extern FUNC(void, COM_CODE) Com_MainFunctionRx_Lin
(
    void
);
extern FUNC(void, COM_CODE) Com_MainFunctionRx_Fr
(
    void
);
extern FUNC(void, COM_CODE) Com_MainFunctionRx_Eth
(
    void
);
extern FUNC(void, COM_CODE) Com_MainFunctionTx_Can
(
    void
);
extern FUNC(void, COM_CODE) Com_MainFunctionTx_Lin
(
    void
);
extern FUNC(void, COM_CODE) Com_MainFunctionTx_Fr
(
    void
);
extern FUNC(void, COM_CODE) Com_MainFunctionTx_Eth
(
    void
);
#else
extern FUNC(void, COM_CODE) Com_MainFunction_Rx
(
    uint16 ComRxPduInfoTableIndex
);
extern FUNC(void, COM_CODE) Com_MainFunction_Tx
(
    uint16 ComTxPduInfoTableIndex
);
#endif  /* COM_MULTICORE_SUPPORT == STD_ON */

#if( COM_GWSIGNAL_SUPPORT == STD_ON )
extern FUNC(void, COM_CODE) Com_MainFunction_RouteSignals
(
    uint16 ComGatewayInfoTableIndex
);
#endif

extern FUNC(Com_SigEndianessType, COM_CODE) Com_GetSignalEndianess
(
    Com_SigFuncIdType sigFuncIdx
);

extern FUNC(Com_SigType, COM_CODE) Com_GetSignalType(Com_SigFuncIdType sigFuncIdx);

/* PolySpace +1 MISRA-C3:20.9 [Justified:Unset] "NSCA_Polyspace_Com_20.9" */
#if( COM_SIGGRP_RTEGROUP_OPERATE == STD_ON )
extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupOpt
(
    Com_SignalGroupIdType signalGroupId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) dataPtr,
    uint32 length
);
#endif  /* COM_SIGGRP_RTEGROUP_OPERATE == STD_ON */

#define COM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Com_MemMap.h"

#endif /* COM_H_ */

