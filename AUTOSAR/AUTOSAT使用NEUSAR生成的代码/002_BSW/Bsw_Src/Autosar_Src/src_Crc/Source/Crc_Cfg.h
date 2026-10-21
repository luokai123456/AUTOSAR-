/*
********************************************************************************
*
* File name: Crc_Cfg.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2019.04.14
* Change: Complete CRC configuration options.
* Cause: New
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
* Author/Date : XieYN/2021.03.27
* Change: Delete the reference of "Crc_MemMap.h" header file.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: LiDaY/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiuY/2025.05.29
* Change: Add polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef CRC_CFG_H_
#define CRC_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CRC_16_MODE         (CRC_16_TABLE)
#define CRC_32_MODE         (CRC_32_TABLE)
#define CRC_32P4_MODE       (CRC_32P4_TABLE)
#define CRC_8H2F_MODE       (CRC_8H2F_TABLE)
#define CRC_8_MODE          (CRC_8_TABLE)

#define CRC_16_TABLE        (0U)    /* table based CRC16 calculation
                                       (default selection). */
#define CRC_16_RUNTIME      (1U)    /* runtime based CRC16 calculation. */
#define CRC_16_HARDWARE     (2U)    /* hardware based CRC16 calculation. */

#define CRC_32_TABLE        (0U)    /* table based CRC32 calculation
                                       (default selection). */
#define CRC_32_RUNTIME      (1U)    /* runtime based CRC32 calculation. */
#define CRC_32_HARDWARE     (2U)    /* hardware based CRC32 calculation. */

#define CRC_32P4_TABLE      (0U)    /* table based CRC32P4 calculation
                                       (default selection). */
#define CRC_32P4_RUNTIME    (1U)    /* runtime based CRC32P4 calculation. */
#define CRC_32P4_HARDWARE   (2U)    /* hardware based CRC32P4 calculation. */

#define CRC_8H2F_TABLE      (0U)    /* table based CRC8H2F calculation
                                       (default selection). */
#define CRC_8H2F_RUNTIME    (1U)    /* runtime based CRC8H2F calculation. */
#define CRC_8H2F_HARDWARE   (2U)    /* hardware based CRC8H2F calculation. */

#define CRC_8_TABLE         (0U)    /* table based CRC8 calculation
                                       (defaultselection). */
#define CRC_8_RUNTIME       (1U)    /* runtime based CRC8 calculation. */
#define CRC_8_HARDWARE      (2U)    /* hardware based CRC8 calculation. */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
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

#endif /* CRC_CFG_H_ */
