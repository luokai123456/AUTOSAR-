/*
********************************************************************************
*
* File name: Det.h
*
* Copyright 2018-2024 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: ZhangDX/2019.05.15
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: JiaF/2019.11.19
* Change: Modify the file according to the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: JiaF/2020.06.08
* Change: Add autosar release version.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: JiaF/2020.09.09
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: FangT/2020.10.28
* Change: Modify function parameter VAR.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: FangT/2020.11.04
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: FangT/2020.11.06
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: ZhuCY/2021.04.12
* Change: Modify the minor version number.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiDY/2022.09.23
* Change: Add multicore function and update Version number.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: GaoXY/2023.05.17
* Change: Modify the version number to 3.7.0.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: GaoXY/2023.05.26
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: ChenQJ/2023.08.18
* Change: Fix P2CONST ptrclass issue.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: ChenQJ/2023.09.21
* Change: Change the header file name provided by Dlt.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: LinZhC/2024.03.21
* Change: Fix P2CONST ptrclass issue.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: ZengJX/2024.07.02
* Change: Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: ZengJX/2024.07.15
* Change: 1.Modify copyright information.
*         2.Optimize comments specifications.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: ZengJX/2024.09.03
* Change: 1.Modify copyright information.
*         2.Add REVISION version.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: ZengJX/2025.03.27
* Change: 1.Change version to 3.13.0.4.
*         2.Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Bugfix
********************************************************************************
* Version: 3.16
* Author/Date: ZengJX/2025.06.05
* Change: 1.Fix the PolySpace warning and add the PolySpace deviation suppression
*           comment. 
*         2.Change version to 3.14.0.5.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: ZengJX/2025.06.09
* Change: Fix the PolySpace warning and add the PolySpace deviation suppression
*         comment. 
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: ZengJX/2025.06.23
* Change: Change version to 3.14.0.6.
* Cause: Optimization
********************************************************************************
*/
#ifndef DET_H_
#define DET_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Det_Cfg.h"
#include "Rte_Det_Type.h"
#include "Os.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Det_2.5" */
#if ( USE_DET == STD_ON )
#define DET_RAMLOG_SIZE                     (256U)
#else
#define DET_RAMLOG_SIZE                     (0U)
#endif
#define DET_NUMBER_OF_CORES                 (OS_CFG_COREPHYSICALID_COUNT)

#define DET_FALSE                           (0U)
#define DET_TRUE                            (1U)
#define DET_ZERO                            (0U)

#define DET_E_OK                            (E_OK)
#define DET_E_NOT_OK                        (E_NOT_OK)
#define DET_E_NO_ERR                        (0x00)

/* Vendor and module identification. */
#define DET_VENDOR_ID                       (119)
#define DET_MODULE_ID                       (15)

/* Vendor specific BSW module version information. */
#define DET_SW_MAJOR_VERSION                (3U)
#define DET_SW_MINOR_VERSION                (14U)
#define DET_SW_PATCH_VERSION                (0U)
#define DET_SW_REVISION_VERSION             (6U)

#define DET_AR_RELEASE_MAJOR_VERSION        (4U)
#define DET_AR_RELEASE_MINOR_VERSION        (2U)
#define DET_AR_RELEASE_REVISION_VERSION     (2U)

#define DET_INSTANCE_ID                     (0x00U)

/* API ID. */
#define DET_INIT_ID                         (0x00U)
#define DET_REPORT_ERROR_ID                 (0x01U)
#define DET_START_ID                        (0x02U)
#define DET_GET_VERSION_INFO_ID             (0x03U)
#define DET_REPORT_RUNTIME_ERROR_ID         (0x04U)
#define DET_REPORT_TRANSIENT_FAULT_ID       (0x05U)

#define MODULE_ID_OS                        (1U)    /* Os. */
#define MODULE_ID_RTE                       (2U)    /* Runtime Environment. */
#define MODULE_ID_ECUM                      (10U)   /* ECU state manager. */
#define MODULE_ID_FIM                       (11U)   /* Function Inhibition Manager. */
#define MODULE_ID_COMM                      (12U)   /* Communication manager. */
#define MODULE_ID_WDGM                      (13U)   /* Watchdog manager. */
#define MODULE_ID_DET                       (15U)   /* Development Error Tracer. */
#define MODULE_ID_NVM                       (20U)   /* NVRAM Manager. */
#define MODULE_ID_FEE                       (21U)   /* Flash EEPROM Emulation. */
#define MODULE_ID_MEMIF                     (22U)   /* Memory Abstraction Interface. */
#define MODULE_ID_NM                        (29U)   /* Generic network management. */
#define MODULE_ID_OSEKNM                    (30U)   /* Osek network management. */
#define MODULE_ID_CANNM                     (31U)   /* Can network management. */
#define MODULE_ID_FRNM                      (32U)   /* Flexray network management. */
#define MODULE_ID_UDPNM                     (33U)   /* UDP network management. */
#define MODULE_ID_CANTP                     (35U)   /* Can transport layer. */
#define MODULE_ID_FRTP                      (36U)   /* Flexray transport protocol. */
#define MODULE_ID_J1939TP                   (37U)   /* J1939 Transport protocol (Autosar 4). */
#define MODULE_ID_EA                        (40U)   /* EEPROM Abstractio. */
#define MODULE_ID_BSWM                      (42U)   /* BSW Mode Manager. */
#define MODULE_ID_WDGIF                     (43U)   /* Watchdog interface. */
#define MODULE_ID_LDCOM                     (49U)   /* Large Data Com. */
#define MODULE_ID_COM                       (50U)   /* Autosar COM. */
#define MODULE_ID_PDUR                      (51U)   /* PDU router. */
#define MODULE_ID_IPDUM                     (52U)   /* IPDU Multiplexer. */
#define MODULE_ID_DCM                       (53U)   /* Diagnostic Communication Manager. */
#define MODULE_ID_DEM                       (54U)   /* Diagnostic Event Manager. */
#define MODULE_ID_DLT                       (55U)   /* Diagnostic Log and Trace. */
#define MODULE_ID_SOAD                      (56U)   /* Socket Adaptor. */
#define MODULE_ID_CANIF                     (60U)   /* CAN Interface. */
#define MODULE_ID_FRIF                      (61U)   /* Flexray interface. */
#define MODULE_ID_LINIF                     (62U)   /* LIN interface. */
#define MODULE_ID_LINNM                     (63U)   /* LIN network management. */
#define MODULE_ID_ETHIF                     (65U)   /* Ethernet Interface. */
#define MODULE_ID_CANTRCV                   (70U)   /* Can tranceiver driver. */
#define MODULE_ID_FRTRCV                    (71U)   /* Flexray tranceiver driver. */
#define MODULE_ID_CAN                       (80U)   /* Can Driver. */
#define MODULE_ID_FR                        (81U)   /* Flexray driver. */
#define MODULE_ID_LIN                       (82U)   /* LIN Driver. */
#define MODULE_ID_SPI                       (83U)   /* SPI Handler Driver. */
#define MODULE_ID_ETHTRCV                   (73U)   /* Ethernet transceiver. */
#define MODULE_ID_ETH                       (88U)   /* Ethernet Driver. */
#define MODULE_ID_EEP                       (90U)   /* EEPROM Driver. */
#define MODULE_ID_FLS                       (92U)   /* Flash driver. */
#define MODULE_ID_RAMTST                    (93U)   /* RAM test. */
#define MODULE_ID_GPT                       (100U)  /* GPT driver. */
#define MODULE_ID_MCU                       (101U)  /* MCU driver. */
#define MODULE_ID_WDG                       (102U)  /* Watchdog driver. */
#define MODULE_ID_DIO                       (120U)  /* Dio driver. */
#define MODULE_ID_PWM                       (121U)  /* PWM driver. */
#define MODULE_ID_ICU                       (122U)  /* ICU Driver. */
#define MODULE_ID_ADC                       (123U)  /* ADC driver. */
#define MODULE_ID_PORT                      (124U)  /* Port driver. */
#define MODULE_ID_SCHM                      (130U)  /* BSW Scheduler Module. */
#define MODULE_ID_STBM                      (160U)  /* Sync Time base Manger. */
#define MODULE_ID_CANSM                     (140U)  /* Can state manager. */
#define MODULE_ID_LINSM                     (141U)  /* LIN state manager. */
#define MODULE_ID_FRSM                      (142U)  /* Flexray state manager. */
#define MODULE_ID_ETHSM                     (143U)  /* Ethernet State Management. */
#define MODULE_ID_SOMEIPXF                  (148U)  /* SOME/IP Transformer. */
#define MODULE_ID_SECOC                     (150U)  /* Secure onboard communication. */
#define MODULE_ID_ETHTSYN                   (164U)  /* Time Sync Over Ethernet. */
#define MODULE_ID_SD                        (171U)  /* Service Discovery. */
#define MODULE_ID_TCPIP                     (170U)  /* Ethernet State Management. */
#define MODULE_ID_E2EXF                     (176U)  /* E2E Transformer. */
#define MODULE_ID_CRC                       (201U)  /* CRC Routines. */
#define MODULE_ID_CAL                       (206U)  /* Cypto abstraction library. */
#define MODULE_ID_E2E                       (207U)  /* End-to-end protections. */
#define MODULE_ID_CANXCP                    (210U)  /* Can specific XCP module. */
#define MODULE_ID_C2CAN                     (220U)  /* CAN. */
#define MODULE_ID_C2COM                     (221U)  /* COM Services. */
#define MODULE_ID_C2DIAG                    (222U)  /* Diagnostic. */
#define MODULE_ID_C2FW                      (223U)  /* ECU Firmware. */
#define MODULE_ID_C2FR                      (224U)  /* FlexRay. */
#define MODULE_ID_C2LIN                     (225U)  /* LIN. */
#define MODULE_ID_C2MMGT                    (226U)  /* Mode Management. */
#define MODULE_ID_IO                        (254U)  /* IO Hardware Abstraction. */
#define MODULE_ID_CPLX                      (255U)  /* Complex drivers. */

#define MODULE_ID_END                       (256U)  /* Module ID Rang. */

/* called with null parameter pointer. */
#define DET_E_PARAM_POINTER                 (0x01U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Det_2.5" */

/* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" PolySpace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define DET_DUMMY_STATEMENT(x)              ((x) = (x))

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Configuration data structure of the Det module. */
/* PolySpace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_Det_D4.8" PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Det_2.4" */
typedef struct tag_Det_ConfigType
{
    uint8 none;     /* nothing. */
}Det_ConfigType;

/* Type used to store errors. */
typedef struct
{
    uint8 instanceId;
    uint8 apiId;
    uint8 errorId;
    uint16 moduleId;
} Det_EntryType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define DET_START_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"

#if( DET_RAMLOG_SIZE > DET_ZERO )
extern volatile VAR(Det_EntryType, DET_VAR_NO_INIT) Det_RamLog[DET_RAMLOG_SIZE][DET_NUMBER_OF_CORES];
#endif

#define DET_STOP_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"
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
#define DET_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"

extern FUNC(void, DET_CODE) Det_Init
(
    P2CONST(Det_ConfigType, AUTOMATIC, DET_APPL_DATA) ConfigPtr
);
extern FUNC(Std_ReturnType, DET_CODE) Det_ReportError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
);
extern FUNC(void, DET_CODE) Det_Start(void);
extern FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
);
extern FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 FaultId
);

#if( STD_ON == DET_VERSION_INFO_API )
extern FUNC(void, DET_CODE) Det_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) versioninfo
);
#endif

#define DET_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Det_MemMap.h"

#endif /* DET_H_ */
