/*
********************************************************************************
*
* File name: Crc.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2019.04.02
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangJipeng/2019.04.04
* Change: Substitute macros for numbers used in programs.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: Tongqian/2019.04.14
* Change: Add comments, Change the CRC_MODULE_ID value.
* Cause: Optimization
********************************************************************************
* Version: 2.0
* Author/Date: WangHe/2019.11.26
* Change: Format modification.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date : Baowanglong/2020.03.27
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date : Tanjingyang/2020.09.29
* Change: 1.Add function of MemMap
*         2.Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date : TanJY/2020.11.02
* Change: Modify MemMap section
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date : TanJY/2020.11.03
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date : XieYN/2021.10.20
* Change: Nothing
* Cause: Update to V3.2.0
********************************************************************************
* Version: 3.5
* Author/Date : XieYN/2021.11.03
* Change: 1. Add definations for Crc_CalculateAccumulation.
*         2. Add Crc_CalculateAccumulation function declaration.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: XieYN/2022.9.06
* Change: Add declaration of Crc_CalculateCommonAccumulation.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: XieYN/2022.11.10
* Change: Add declaration of Crc_CalculateXORAccumulation.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date : HanXF/2023.5.22
* Change: Modify the patch number and minor number.
* Cause: Optimization
*******************************************************************************
* Version: 3.9
* Author/Date: HanXF/2023.5.26
* Change: Add REVISION Version.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: LiDaY/2024.04.25
* Change: 1.Add a memory-map label to function and variable declarations.
*         2.Updata Minor Version and Revision Version.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiDaY/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: LiDaY/2025.03.28
* Change: 1.Fix QAC and Polyspace warnings and add analysis results.
*         2.Updata Minor Version and Revision Version.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: LiuY/2025.05.29
* Change: 1.Add polyspace deviation suppression comment.
*         2.Updata Minor Version and Revision Version.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: LiuY/2025.06.24
* Change: 1.Add polyspace deviation suppression comment.
*         2.Updata Minor Version and Revision Version.
* Cause: Update
********************************************************************************
*/
#ifndef CRC_H_
#define CRC_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Crc_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Crc version. */
#define CRC_VENDOR_ID                   (119U)
#define CRC_MODULE_ID                   (201U)
#define CRC_SW_MAJOR_VERSION            (3U)
#define CRC_SW_MINOR_VERSION            (14U)
#define CRC_SW_PATCH_VERSION            (0U)
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CRC_SW_REVISION_VERSION         (4U)
#define CRC_AR_RELEASE_MAJOR_VERSION    (4U)
#define CRC_AR_RELEASE_MINOR_VERSION    (2U)
#define CRC_AR_RELEASE_REVISION_VERSION (2U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/* This Value is XORed to the final register value before the value is returned
   as the official checksum. */
#define CRC_XOR_VALUE_8                 (0xFFU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CRC_XOR_VALUE_16                (0xFFFFU)
#define CRC_XOR_VALUE_32                (0xFFFFFFFFU)

/* Crc table member numbers. */
#define CRC_TABLE_NUMS                  (256U)

/* The value at index initialization. */
#define CRC_INIT_0                      (0U)
#define CRC_INIT_1                      (1U)

/* The initial value of checksum in the crc8 algorithm. */
#define CRC_8_START_VALUE               (0xFFU)

/* The initial value of checksum in the crc16 algorithm. */
#define CRC_16_START_VALUE              (0xFFFFU)

/* The initial value of checksum in the crc32 algorithm. */
#define CRC_32_START_VALUE              (0xFFFFFFFFU)

/* Take the lower 8 bits of Crc16_ChkSum. */
#define CRC_CRC16_VALUE_LOW             (0xFFU)

/* Take the high 8 bits of Crc16_ChkSum. */
#define CRC_CRC16_VALUE_HIGH            (0xFF00U)

/* Take the lower 8 bits of Crc32_ChkSum. */
#define CRC_CRC32_VALUE_LOW             (0xFFU)

/* Number of digits shifted left or right. */
#define CRC_BITS_SHIFT_8                (8U)

/* Crc_GetVersionInfo. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CRC_GETVERSIONINFO Crc_GetVersionInfo

/* byte deal with. */
#define CRC_HIGH_NIBBLE                 (0xF0U)
#define CRC_LOW_NIBBLE                  (0x0FU)
#define CRC_4BIT                        (4U)
#define CRC_8BIT                        (8U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CRC_FULL_BYTE                   (0xFFU)

/* Ph checksum. */
#define CRC_DATAID_DATA_CHECKSUM_SUM    (0x10U)

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

#define CRC_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Crc_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern FUNC(uint8, CRC_CODE) Crc_CalculateCRC8
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8,
    boolean Crc_IsFirstCall
);
extern FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8H2F,
    boolean Crc_IsFirstCall
);
extern FUNC(uint16, CRC_CODE) Crc_CalculateCRC16
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    uint32 Crc_Length,
    uint16 Crc_StartValue16,
    boolean Crc_IsFirstCall
);
extern FUNC(uint32, CRC_CODE) Crc_CalculateCRC32
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    uint32 Crc_Length,
    uint32 Crc_StartValue32,
    boolean Crc_IsFirstCall
);
extern FUNC(uint32, CRC_CODE) Crc_CalculateCRC32P4
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) Crc_DataPtr,
    uint32 Crc_Length,
    uint32 Crc_StartValue32,
    boolean Crc_IsFirstCall
);
extern FUNC(uint8, CRC_CODE) Crc_CalculateAccumulation
(
    uint16 DataLen,
    uint8 SumDataID,
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) DataPtr
);
extern FUNC(uint8, CRC_CODE) Crc_CalculateCommonAccumulation
(
    uint16 DataLen,
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) DataPtr
);
extern FUNC(uint8, CRC_CODE) Crc_CalculateXORAccumulation
(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_CONST) DataPtr,
    uint16 DataLen
);
extern FUNC(void, CRC_CODE) Crc_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_APPL_DATA) Versioninfo
);

#define CRC_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Crc_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* CRC_H_ */

