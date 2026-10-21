/*
********************************************************************************
*
*  File name:   Xcp.h
*
*  Copyright    Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2018.12.13
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: yong.zhang/2020.07.02
* Change: Add release software number
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: yong.zhang/2020.08.11
* Change: Delete macro definition of timestamp.
* Cause: Bugfix.
********************************************************************************
* Version: 3.2
* Author/Date: fangtao/2020.08.21
* Change: Add Det function.
* Cause: Bugfix.
********************************************************************************
* Version: 3.3
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: FangT/2021.03.03
* Change: Add checksum and Multi pudid functions.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: FangT/2021.06.30
* Change: Modify code specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date : FangT/2021.08.18
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date : FangT/2021.10.20
* Change: Modified version number.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date : FangT/2021.10.29
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date : FangT/2021.11.01
* Change: Update software version to 3.3.1.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date : FangT/2021.11.12
* Change: Update software version to 3.3.2.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date : FangT/2021.12.07
* Change: Update software version to 3.3.3.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date : FangT/2021.12.17
* Change: Modify the length of the single-pointer RAM buffer to be configurable.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date : FangT/2021.12.23
* Change: Update software version to 3.3.4.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date : FangT/2022.03.16
* Change: 1.Modify the byte order of the Ethernet sending data header
*         2.Change the send length to uint32 type.
*         3.Modify code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date : FangT/2022.06.21
* Change: Update software version to 3.3.5.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date : ShiRong/2022.09.16
* Change: Update software version to 3.3.6.
* Cause: Update
*******************************************************************************
* Version: 3.16
* Author/Date : ShiRong/2022.10.12
* Change:  Add structure  Xcp_Addr_st.
* Cause: Update
*******************************************************************************
* Version: 3.17
* Author/Date : ShiR/2022.11.3
* Change: Modify the adaptive length of Ethernet dto and cto.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date : ShiRong/2022.11.28
* Change: 1.Modify the bug with mismatched parentheses .
*         2.Add XCP_DAQMEMSIZE Configuration Item
* Cause: Update
*******************************************************************************
* Version: 3.19
* Author/Date : ShiRong/2023.02.09
* Change: 1.Add STIM function.
*         2.Add structure calibration method.
*         3.Add the observation method of collecting while sending.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date : ShiRong/2023.02.13
* Change: 1.Delete redundant comments.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date : ShiRong/2023.02.13
* Change: 1.Remove compilation warnings.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date : ShiRong/2023.02.13
* Change: Update software version to 3.3.12.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date : ShiRong/2023.03.09
* Change: 1.Modify the data processing of STIM function.
* Cause: Bug
********************************************************************************
* Version: 3.24
* Author/Date : ShiRong/2023.03.13
* Change: 1.Update software version to 3.3.14.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date : ShiRong/2023.03.21
* Change: 1.Update software version to 3.3.15.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date : ShiRong/2023.04.16
* Change: 1.Add security algorithm functionality.
*         2.Update software version to 3.3.16
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date : ShiRong/2023.05.06
* Change: 1.Add Block Transfer Mode.
*         2.Update software version to 3.3.17.
* Cause: Update.
********************************************************************************
* Version: 3.28
* Author/Date : ShiRong/2023.05.12
* Change: 1.Add storage RAM scaling to NVM functionality.
*         2.Update software version to 3.3.18.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date : ShiRong/2023.05.16
* Change: 1.The issue of modifying the polyspace.
*         2.Update software version to 3.3.19.
* Cause: Update.
********************************************************************************
* Version: 3.30
* Author/Date : ShiRong/2023.05.19
* Change: 1.Add error replies related to security algorithms.
*         2.Fix timestamp adaptation byte alignment issues with STIM functionality.
*         3.Update software version to 3.3.20.
* Cause: Update.
********************************************************************************
* Version: 3.31
* Author/Date : ShiRong/2023.05.23
* Change: 1.Modifying NVM Configuration Reference Issues.
*         2.Update software version to 3.3.21.
* Cause: Bug.
********************************************************************************
* Version: 3.32
* Author/Date : ShiRong/2023.05.24
* Change: 1.Adaptation STIM message cannot reach 1400.
*         2.Update software version to 3.3.22.
* Cause: Update.
********************************************************************************
* Version: 3.33
* Author/Date : ShiRong/2023.05.31
* Change: 1.The issue of missing address retrieval in modifying STIM timestamp code writing.
*         2.Add XCP_SW_REVISION_VERSION and Update to version 3.7.0.1
* Cause: Update.
********************************************************************************
* Version: 3.34
* Author/Date : ShiRong/2023.06.25
* Change: 1.Modifying single pointer calibration byte alignment issues.
*         2.Update software version to 3.8.0.0
* Cause: BugFix.
********************************************************************************
* Version: 3.35
* Author/Date : ShiRong/2023.08.01
* Change: 1.Add verification algorithms for XCP_ADD11 and XCP_CRC32.
*         2.Add flash writing function.
*         3.Update software version to 3.8.0.1
* Cause: Update.
********************************************************************************
* Version: 3.36
* Author/Date : ShiRong/2023.08.01
* Change: Update software version to 3.8.0.2
* Cause: Update.
********************************************************************************
* Version: 3.37
* Author/Date : ShiRong/2023.08.02
* Change: 1.Add sending confirmation timeout judgment function.
*         2.Update software version to 3.8.0.3
* Cause: Update.
********************************************************************************
* Version: 3.38
* Author/Date : ShiRong/2023.08.04
* Change: 1.Modify compilation issues caused by validation enabled configuration items.
*         2.Update software version to 3.8.0.4
* Cause: Update.
********************************************************************************
* Version: 3.39
* Author/Date : ShiRong/2023.08.16
* Change: 1.Modifying Compilation Warning Issues.
*         2.Update software version to 3.8.0.5.
* Cause: Update.
********************************************************************************
* Version: 3.40
* Author/Date : ShiRong/2023.08.17
* Change: 1.Modifying compilation issues when seed is enabled.
*         2.The sending confirmation time affects the block transmission function.
*         3.Update software version to 3.8.0.6.
* Cause: BugFix.
********************************************************************************
* Version: 3.41
* Author/Date : ShiRong/2023.08.28
* Change: 1.The sending confirmation time affects the block transmission function.
*         2.Update software version to 3.8.0.7.
* Cause: BugFix.
********************************************************************************
*/
#ifndef XCP_H_
#define XCP_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Xcp_Swc.h"
#include "Xcp_Cfg.h"
#include "Xcp_Lcfg.h"
#if( STD_ON == XCP_FLASH_PROGRAMING_ENABLE )
#include "Fls.h"
#endif

#if( XCP_ONCAN_ENABLE == STD_ON )
#include "CanXcp_Types.h"              /* Type definitions for XCP on CAN ASR. */
#include "CanXcp_Cfg.h"                /* Include configuration of XCP on CAN. */
#include "CanXcp_Lcfg.h"
#endif

#if( XCP_ONETHERNET_ENABLE == STD_ON )
#include "EthXcp_Cfg.h"                /* Include configuration of XCP on ETH. */
#include "EthXcp_Lcfg.h"
#endif

#if( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
#include "NvM.h"                       /* Contains the configuration used by XCP in NVM */
#endif

#if( STD_ON == XCP_ENABLE_CHECKSUM )
#include "Crc.h"
#endif

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define XCP_FF        (0xFFU)
#define XCP_ZERO      (0U)
#define XCP_ONE       (1U)
#define XCP_TWO       (2U)
#define XCP_THREE     (3U)
#define XCP_FOUR      (4U)
#define XCP_FIVE      (5U)
#define XCP_SIX       (6U)
#define XCP_SEVEN     (7U)
#define XCP_EIGHT     (8U)
#define XCP_NINE      (9U)
#define XCP_TEN       (10U)
#define XCP_FIFTEEN   (15U)
#define XCP_16        (16U)
#define XCP_24        (24U)
#define XCP_40        (40U)
#define XCP_62        (62U)
#define XCP_63        (63U)
#define XCP_64        (64U)
#define XCP_0X80      (0x80U)
#define XCP_127       (127U)
#define XCP_128       (128U)
#define XCP_255       (255U)
#define XCP_512       (512U)
#define XCP_1500      (1500U)
#define XCP_FFFF      (0xFFFFU)
#define XCP_00FF      (0x00FFU)
#define XCP_FFFF0000  (0xFFFF0000U)

#define XCP_E_OK                     (E_OK)
#define XCP_E_NOT_OK                 (E_NOT_OK)

/* Xcp error id. */
#define XCP_E_NO_ERROR               (0x00U)
#define XCP_E_INV_POINTER            (0x01U)
#define XCP_E_NOT_INITIALIZED        (0x02U)
#define XCP_E_INVALID_PDUID          (0x03U)
#define XCP_E_INIT_FAILED            (0x04U)
#define XCP_E_PARAM_POINTER          (0x12U)

#define FORERROR(e) { Xcp_Data.CrmLen = 2U; CRM_CMD = (uint8)PID_ERR; CRM_ERR = (uint8)e; return;}
#define CHECK_ERROR(e) { err=(e); if (err != 0U) { Xcp_Data.CrmLen = 2U; CRM_CMD = (uint8)PID_ERR; CRM_ERR = (uint8)err; return; } }

/* Check Enable seed key. */
#if( XCP_ENABLE_SEED_KEY == STD_ON )
    #define CheckResourceProtection(resource)   if( (Xcp_Data.ProtectionStatus & (resource)) != 0U ) { FORERROR(CRC_ACCESS_LOCKED ) }
#else
    #define CheckResourceProtection(resource)
#endif

#define XCPSETMTA(p,e) (Xcp_Data.Mta = (p))              /* Assign a pointer to a Mta. */
#define XCP_WRITE_BYTE_2_ADDR(addr, data)           *(addr) = (data)
#define XCP_READ_BYTE_FROM_ADDR(addr)               *(addr)
#define XCP_READ_CHECKSUMVALUE_FROM_ADDR(addr)      *((tXcpChecksumAddType*)addr)
#define XCP_DUMMY_STATEMENT(v) (v) = (v)

/* Version */
#define XCP_TRANSPORT_LAYER_VERSION         (0x0100U)
#define CP_XCP_VERSION                      (0x0125U)
#define XCP_VERSION                         (0x0100U)

#define XCP_VENDOR_ID                       (119U)
#define XCP_MODULE_ID                       (212U)
#define XCP_SW_MAJOR_VERSION                (3U)
#define XCP_SW_MINOR_VERSION                (8U)
#define XCP_SW_PATCH_VERSION                (0U)
#define XCP_SW_REVISION_VERSION             (7U)
#define XCP_INSTANCE_ID                     (0U)
#define XCP_AR_RELEASE_MAJOR_VERSION        (4U)
#define XCP_AR_RELEASE_MINOR_VERSION        (2U)
#define XCP_AR_RELEASE_REVISION_VERSION     (2U)

#define XCP_SID_GET_VERSIONINFO             (0x01U)
#define XCP_SID_TXCONFIRMATION              (0x02U)
#define XCP_SID_RXINDICATION                (0x03U)

/* Packet Identifiers Slave -> Master. */
#define PID_RES                             (0xFFU)    /* response packet */
#define PID_ERR                             (0xFEU)    /* error packet */
#define PID_EV                              (0xFDU)    /* event packet */
#define PID_SERV                            (0xFCU)    /* service request packet */

#if ( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD )
#define RTE_CALIBGROUP_PARABUF_ADDRSTART    ((uint32)&Xcp_CalibGroupParaRamBuf[0])
#define RTE_CALIBGROUP_PARABUF_ADDREND      (((uint32)&Xcp_CalibGroupParaRamBuf[0]) + SINGCALRAM_SIZE)
#endif

/* Commands */
/* Standard Commands */

#define CC_CONNECT                          (0xFFU)
#define CC_DISCONNECT                       (0xFEU)
#define CC_GET_STATUS                       (0xFDU)
#define CC_SYNC                             (0xFCU)

#define CC_GET_COMM_MODE_INFO               (0xFBU)
#define CC_GET_ID                           (0xFAU)
#define CC_SET_REQUEST                      (0xF9U)
#define CC_GET_SEED                         (0xF8U)
#define CC_UNLOCK                           (0xF7U)
#define CC_SET_MTA                          (0xF6U)
#define CC_UPLOAD                           (0xF5U)
#define CC_SHORT_UPLOAD                     (0xF4U)
#define CC_BUILD_CHECKSUM                   (0xF3U)

#define CC_TRANSPORT_LAYER_CMD              (0xF2U)
#define CC_USER_CMD                         (0xF1U)

/* Calibration Commands */
#define CC_DOWNLOAD                         (0xF0U)
#define CC_DOWNLOAD_NEXT                    (0xEFU)
#define CC_DOWNLOAD_MAX                     (0xEEU)
#define CC_SHORT_DOWNLOAD                   (0xEDU)
#define CC_MODIFY_BITS                      (0xECU)

/* Page switching Commands (PAG) */
#define CC_SET_CAL_PAGE                     (0xEBU)
#define CC_GET_CAL_PAGE                     (0xEAU)
#define CC_GET_PAG_PROCESSOR_INFO           (0xE9U)
#define CC_GET_SEGMENT_INFO                 (0xE8U)
#define CC_GET_PAGE_INFO                    (0xE7U)
#define CC_SET_SEGMENT_MODE                 (0xE6U)
#define CC_GET_SEGMENT_MODE                 (0xE5U)
#define CC_COPY_CAL_PAGE                    (0xE4U)

/* DATA Acquisition and Stimulation Commands (DAQ/STIM) */
#define CC_SET_DAQ_PTR                      (0xE2U)
#define CC_WRITE_DAQ                        (0xE1U)
#define CC_SET_DAQ_LIST_MODE                (0xE0U)
#define CC_START_STOP_DAQ_LIST              (0xDEU)
#define CC_START_STOP_SYNCH                 (0xDDU)
#define CC_WRITE_DAQ_MULIPLE                (0xC7U)
#define CC_READ_DAQ                         (0xDBU)
#define CC_GET_DAQ_CLOCK                    (0xDCU)
#define CC_GET_DAQ_PROCESSOR_INFO           (0xDAU)
#define CC_GET_DAQ_RESOLUTION_INFO          (0xD9U)
#define CC_GET_DAQ_LIST_MODE                (0xDFU)
#define CC_GET_DAQ_EVENT_INFO               (0xD7U)
#define CC_CLEAR_DAQ_LIST                   (0xE3U)
#define CC_GET_DAQ_LIST_INFO                (0xD8U)
#define CC_FREE_DAQ                         (0xD6U)
#define CC_ALLOC_DAQ                        (0xD5U)
#define CC_ALLOC_ODT                        (0xD4U)
#define CC_ALLOC_ODT_ENTRY                  (0xD3U)

/* Non volatile memory Programming Commands PGM */
#define CC_PROGRAM_START                    (0xD2U)
#define CC_PROGRAM_CLEAR                    (0xD1U)
#define CC_PROGRAM                          (0xD0U)
#define CC_PROGRAM_RESET                    (0xCFU)
#define CC_GET_PGM_PROCESSOR_INFO           (0xCEU)
#define CC_GET_SECTOR_INFO                  (0xCDU)
#define CC_PROGRAM_PREPARE                  (0xCCU)
#define CC_PROGRAM_FORMAT                   (0xCBU)
#define CC_PROGRAM_NEXT                     (0xCAU)
#define CC_PROGRAM_MAX                      (0xC9U)
#define CC_PROGRAM_VERIFY                   (0xC8U)

/* Command Return Codes */
#define CRC_CMD_SYNCH                       (0x00U)
#define CRC_CMD_BUSY                        (0x10U)
#define CRC_DAQ_ACTIVE                      (0x11U)
#define CRC_PRM_ACTIVE                      (0x12U)
#define CRC_CMD_UNKNOWN                     (0x20U)
#define CRC_CMD_SYNTAX                      (0x21U)
#define CRC_OUT_OF_RANGE                    (0x22U)
#define CRC_WRITE_PROTECTED                 (0x23U)
#define CRC_ACCESS_DENIED                   (0x24U)
#define CRC_ACCESS_LOCKED                   (0x25U)
#define CRC_PAGE_NOT_VALID                  (0x26U)
#define CRC_PAGE_MODE_NOT_VALID             (0x27U)
#define CRC_SEGMENT_NOT_VALID               (0x28U)
#define CRC_SEQUENCE                        (0x29U)
#define CRC_DAQ_CONDIF                      (0x2AU)
#define CRC_MEMORY_OVERFLOW                 (0x30U)
#define CRC_GENERIC                         (0x31U)
#define CRC_VERIFY                          (0x32U)

/* Event Codes */
#define EV_RESUME_MODE                      (0x00U)
#define EV_CLEAR_DAQ                        (0x01U)
#define EV_STORE_DAQ                        (0x02U)
#define EV_STORE_CAL                        (0x03U)
#define EV_CMD_PENDING                      (0x05U)
#define EV_DAQ_OVERLOAD                     (0x06U)
#define EV_SESSION_TERMINATED               (0x07U)
#define EV_TIME_SYNC                        (0x08U)
#define EV_STIM_TIMEOUT                     (0x09U)
#define EV_USER                             (0xFEU)
#define EV_TRANSPORT                        (0xFFU)

/* PID MASK */
#define PID_STIM_START                      (0x00U)
#define PID_STIM_END                        (0xBFU)

/* Service Request Codes */
/* Slave requesting to be reset */
#define SERV_RESET                          (0x00U)
/* Plain ASCII text null terminated */
#define SERV_TEXT                           (0x01U)

/* Definitions      */
/* ResourceMask (CONNECT) */

#define RM_CAL_PAG                          (0x01U)
#define RM_DAQ                              (0x04U)
#define RM_STIM                             (0x08U)
#define RM_PGM                              (0x10U)
#define RM_DAQ_STIM                         (0x0CU)

/* CommModeBasic (CONNECT) */
#define PI_INTEL                            (0x00U)
#define PI_MOTOROLA                         (0x01U)

#define CMB_BYTE_ORDER                      (0x01U << 0U)
#define CMB_ADDRESS_GRANULARITY             (0x03U << 1U)
#define CMB_SLAVE_BLOCK_MODE                (0x01U << 6U)
#define CMB_OPTIONAL                        (0x01U << 7U)

#define CMB_ADDRESS_GRANULARITY_BYTE        (0U << 1U)
#define CMB_ADDRESS_GRANULARITY_WORD        (1U << 1U)
#define CMB_ADDRESS_GRANULARITY_DWORD       (2U << 1U)
#define CMB_ADDRESS_GRANULARITY_QWORD       (3U << 1U)

/* Protocol Info (GET_COMM_MODE_INFO - COMM_OPTIONAL) */
#define CMO_MASTER_BLOCK_MODE               (0x01U)
#define CMO_INTERLEAVED_MODE                (0x02U)

/* Session Status (GET_STATUS and SET_REQUEST) */
#define SS_STORE_CAL_REQ                    (0x01U)
#define SS_BLOCK_UPLOAD                     (0x02U)  /* Internal */
#define SS_STORE_DAQ_REQ                    (0x04U)
#define SS_CLEAR_DAQ_REQ                    (0x08U)
#define SS_ERROR                            (0x10U)  /* Internal */
#define SS_CONNECTED                        (0x20U)  /* Internal */
#define SS_DAQ                              (0x40U)
#define SS_RESUME                           (0x80U)

/* Define for SET_REQUEST */
#define ACTION_READ                         (1U)
#define ACTION_WRITE                        (0U)

/* Identifier Type (GET_ID) */
#define IDT_ASCII                           (0U)
#define IDT_ASAM_NAME                       (1U)
#define IDT_ASAM_PATH                       (2U)
#define IDT_ASAM_URL                        (3U)
#define IDT_ASAM_UPLOAD                     (4U)
#define IDT_VECTOR_MAPNAMES                 (0xDBU)

/* Checksum Types (BUILD_CHECKSUM) */
#define XCP_CHECKSUM_TYPE_ADD11             (0x01U)  /* Add BYTE into a BYTE checksum, ignore overflows */
#define XCP_CHECKSUM_TYPE_ADD12             (0x02U)  /* Add BYTE into a WORD checksum, ignore overflows */
#define XCP_CHECKSUM_TYPE_ADD14             (0x03U)  /* Add BYTE into a DWORD checksum, ignore overflows */
#define XCP_CHECKSUM_TYPE_ADD22             (0x04U)  /* Add WORD into a WORD checksum, ignore overflows, blocksize must be modulo 2 */
#define XCP_CHECKSUM_TYPE_ADD24             (0x05U)  /* Add WORD into a DWORD checksum, ignore overflows, blocksize must be modulo 2 */
#define XCP_CHECKSUM_TYPE_ADD44             (0x06U)  /* Add DWORD into DWORD, ignore overflows, blocksize must be modulo 4 */
#define XCP_CHECKSUM_TYPE_CRC16             (0x07U)  /* See CRC error detection algorithms */
#define XCP_CHECKSUM_TYPE_CRC16CCITT        (0x08U)  /* See CRC error detection algorithms */
#define XCP_CHECKSUM_TYPE_CRC32             (0x09U)  /* See CRC error detection algorithms */
#define XCP_CHECKSUM_TYPE_DLL               (0xFFU)  /* User defined, ASAM MCD 2MC DLL Interface */

/* Page Mode (SET_CAL_PAGE) */
#define CAL_ECU                             (0x01U)
#define CAL_XCP                             (0x02U)
#define CAL_ALL                             (0x80U)  /* not supported */

/* PAG_PROPERTIES (GET_PAG_PROCESSOR_INFO) */
#define PAG_PROPERTY_FREEZE                 (0x01U)

/* PAGE_PROPERTIES (GET_PAGE_INFO)*/
#define ECU_ACCESS_TYPE                     (0x03U)
#define XCP_READ_ACCESS_TYPE                (0x0CU)
#define XCP_WRITE_ACCESS_TYPE               (0x30U)

/* ECU_ACCESS_TYPE */
#define ECU_ACCESS_NONE                     (0U << 0U)
#define ECU_ACCESS_WITHOUT                  (1U << 0U)
#define ECU_ACCESS_WITH                     (2U << 0U)
#define ECU_ACCESS_DONT_CARE                (3U << 0U)

/* XCP_READ_ACCESS_TYPE */
#define XCP_READ_ACCESS_NONE                (0U << 2U)
#define XCP_READ_ACCESS_WITHOUT             (1U << 2U)
#define XCP_READ_ACCESS_WITH                (2U << 2U)
#define XCP_READ_ACCESS_DONT_CARE           (3U << 2U)

/* XCP_WRITE_ACCESS_TYPE */
#define XCP_WRITE_ACCESS_NONE               (0U << 4U)
#define XCP_WRITE_ACCESS_WITHOUT            (1U << 4U)
#define XCP_WRITE_ACCESS_WITH               (2U << 4U)
#define XCP_WRITE_ACCESS_DONT_CARE          (3U << 4U)

/* SEGMENT_MODE (GET_SEGMENT_MODE, SET_SEGMENT_MODE) */
#define SEGMENT_FLAG_FREEZE                 (0x01U)

/* DAQ_LIST_MODE (GET_DAQ_LIST_MODE, SET_DAQ_LIST_MODE) */
#define DAQ_FLAG_SELECTED                   (0x01U)
#define DAQ_FLAG_DIRECTION                  (0x02U)  /* Data Stimulation Mode */
#define DAQ_FLAG_TIMESTAMP                  (0x10U)  /* Timestamps */
#define DAQ_FLAG_NO_PID                     (0x20U)  /* No PID */
#define DAQ_FLAG_RUNNING                    (0x40U)  /* Is started */
#define DAQ_FLAG_RESUME                     (0x80U)  /* Resume Mode */
#define DAQ_FLAG_RESERVED                   (0x08U)
#define DAQ_FLAG_OVERRUN                    (0x08U)  /* Overun (Internal Use) */

/* GET_DAQ_PROCESSOR_INFO */
/* DAQ_PROPERTIES */
#define DAQ_PROPERTY_CONFIG_TYPE            (0x01U)
#define DAQ_PROPERTY_PRESCALER              (0x02U)
#define DAQ_PROPERTY_RESUME                 (0x04U)
#define DAQ_PROPERTY_BIT_STIM               (0x08U)
#define DAQ_PROPERTY_TIMESTAMP              (0x10U)
#define DAQ_PROPERTY_NO_PID                 (0x20U)
#define DAQ_PROPERTY_OVERLOAD_INDICATION    (0xC0U)

/* DAQ Overload Indication Type */
#define DAQ_OVERLOAD_INDICATION_NONE        (0U << 6U)
#define DAQ_OVERLOAD_INDICATION_PID         (1U << 6U)
#define DAQ_OVERLOAD_INDICATION_EVENT       (2U << 6U)

/* DAQ_KEY_BYTE */
#define DAQ_OPT_TYPE                        (0x0FU)
#define DAQ_EXT_TYPE                        (0x30U)
#define DAQ_HDR_TYPE                        (0xC0U)

/* DAQ Optimisation Type */
#define DAQ_OPT_DEFAULT                     (0U << 0U)
#define DAQ_OPT_ODT_16                      (1U << 0U)
#define DAQ_OPT_ODT_32                      (2U << 0U)
#define DAQ_OPT_ODT_64                      (3U << 0U)
#define DAQ_OPT_ALIGNMENT                   (4U << 0U)
#define DAQ_OPT_MAX_ENTRY_SIZE              (5U << 0U)

/* DAQ Address Extension Scope */
#define DAQ_EXT_FREE                        (0U << 4U)
#define DAQ_EXT_ODT                         (1U << 4U)
#define DAQ_EXT_DAQ                         (3U << 4U)

/* DAQ Identification Field Type */
#define DAQ_HDR_PID                         (0U << 6U)
#define DAQ_HDR_ODT_DAQB                    (1U << 6U)
#define DAQ_HDR_ODT_DAQW                    (2U << 6U)
#define DAQ_HDR_ODT_FIL_DAQW                (3U << 6U)

/* GET_DAQ_RESOLUTION_INFO */
/* TIMESTAMP_MODE */
#define DAQ_TIMESTAMP_SIZE                  (0x07U)
#define DAQ_TIMESTAMP_FIXED                 (0x08U)
#define DAQ_TIMESTAMP_UNIT                  (0xF0U)

/* DAQ Timestamp Size */
#define DAQ_TIMESTAMP_OFF                   (0U << 0U)
#define DAQ_TIMESTAMP_BYTE                  (1U << 0U)
#define DAQ_TIMESTAMP_WORD                  (2U << 0U)
#define DAQ_TIMESTAMP_DWORD                 (4U << 0U)

/* DAQ_LIST_PROPERTIES (GET_DAQ_LIST_INFO) */
#define DAQ_LIST_PREDEFINED                 (0x01U)
#define DAQ_LIST_FIXED_EVENT                (0x02U)
#define DAQ_LIST_DIR_DAQ                    (0x04U)
#define DAQ_LIST_DIR_STIM                   (0x08U)

/* EVENT_PROPERTY (GET_DAQ_EVENT_INFO) */

#define DAQ_EVENT_DIRECTION_DAQ             (0x04U)
#define DAQ_EVENT_DIRECTION_STIM            (0x08U)
#define DAQ_EVENT_DIRECTION_DAQ_STIM        (0x0CU)

/* Comm mode programming parameter (PROGRAM_START) */
#define PI_PGM_BLOCK_DOWNLOAD               (0x01U)
#define PI_PGM_BLOCK_UPLOAD                 (0x40U)
#define PI_PGM_BLOCK_MODE                   (0x41U)

/* PGM_PROPERTIES (GET_PGM_PROCESSOR_INFO) */
#define PGM_ACCESS_TYPE                     (0x03U)
#define PGM_COMPRESSION_TYPE                (0x0CU)
#define PGM_ENCRYPTION_TYPE                 (0x30U)
#define PGM_NON_SEQ_TYPE                    (0xC0U)

/* PGM Access Mode */
#define PGM_ACCESS_ABSOLUTE                 (1U << 0U)
#define PGM_ACCESS_FUNCTIONAL               (2U << 0U)
#define PGM_ACCESS_FREE                     (3U << 0U)

/* PGM Compression type */
#define PGM_COMPRESSION_NONE                (0U << 2U)
#define PGM_COMPRESSION_SUPPORTED           (1U << 2U)
#define PGM_COMPRESSION_REQUIRED            (3U << 2U)

/* PGM Encryption type */
#define PGM_ENCRYPTION_NONE                 (0U << 4U)
#define PGM_ENCRYPTION_SUPPORTED            (1U << 4U)
#define PGM_ENCRYPTION_REQUIRED             (3U << 4U)

/* PGM non sequential programming type */
#define PGM_NON_SEQ_NONE                    (0U << 6U)
#define PGM_NON_SEQ_SUPPORTED               (1U << 6U)
#define PGM_NON_SEQ_REQUIRED                (3U << 6U)

/* Compatibility defines */
#define XCPMAXCTO_AG                        XCP_MAX_CTO
#define XCPMAXDTO_AG                        XCP_MAX_DTO
#define XCPAG                               (1U)

/* XCP Commands and Responces, Type Definition */
/* Protocol command structure definition */
#define CRO_CMD                                         CRO_BYTE(0)
#define CRM_CMD                                         CRM_BYTE(0)
#define CRM_ERR                                         CRM_BYTE(1)
/* CONNECT */
#define CRO_CONNECT_LEN                                 (2U)
#define CRO_CONNECT_MODE                                CRO_BYTE(1)
#define CRM_CONNECT_LEN                                 (Const_CRM_CONNECT_LEN)
#define CRM_CONNECT_RESOURCE                            CRM_BYTE(1)
#define CRM_CONNECT_COMM_BASIC                          CRM_BYTE(2)
#define CRM_CONNECT_MAX_CTO_SIZE                        CRM_BYTE(3)
#define CRM_CONNECT_MAX_DTO_SIZE                        CRM_WORD(2)
#define CRM_CONNECT_PROTOCOL_VERSION                    CRM_BYTE(6)
#define CRM_CONNECT_TRANSPORT_VERSION                   CRM_BYTE(7)

/* DISCONNECT */
#define CRO_DISCONNECT_LEN                              (1U)
#define CRM_DISCONNECT_LEN                              (1U)

/* GET_STATUS */
#define CRO_GET_STATUS_LEN                              (1U)
#define CRM_GET_STATUS_LEN                              (6U)
#define CRM_GET_STATUS_STATUS                           CRM_BYTE(1)
#define CRM_GET_STATUS_PROTECTION                       CRM_BYTE(2)
#define CRM_GET_STATUS_CONFIG_ID                        CRM_WORD(2)

/* SYNCH */
#define CRO_SYNCH_LEN                                   (1U)
#define CRM_SYNCH_LEN                                   (2U)
#define CRM_SYNCH_RESULT                                CRM_BYTE(1)

/* GET_COMM_MODE_INFO */
#define CRO_GET_COMM_MODE_INFO_LEN                      (1U)
#define CRM_GET_COMM_MODE_INFO_LEN                      (8U)
#define CRM_GET_COMM_MODE_INFO_COMM_OPTIONAL            CRM_BYTE(2)
#define CRM_GET_COMM_MODE_INFO_MAX_BS                   CRM_BYTE(4)
#define CRM_GET_COMM_MODE_INFO_MIN_ST                   CRM_BYTE(5)
#define CRM_GET_COMM_MODE_INFO_QUEUE_SIZE               CRM_BYTE(6)
#define CRM_GET_COMM_MODE_INFO_DRIVER_VERSION           CRM_BYTE(7)

/* GET_ID */
#define CRO_GET_ID_LEN                                  (2U)
#define CRO_GET_ID_TYPE                                 CRO_BYTE(1)
#define CRM_GET_ID_LEN                                  (8U)
#define CRM_GET_ID_MODE                                 CRM_BYTE(1)
#define CRM_GET_ID_LENGTH                               CRM_DWORD(1)
#define CRM_GET_ID_DATA                                 (&CRM_BYTE(8))

/* SET_REQUEST */
#define CRO_SET_REQUEST_LEN                             (4U)
#define CRO_SET_REQUEST_MODE                            CRO_BYTE(1)
#define CRO_SET_REQUEST_CONFIG_ID                       CRO_WORD(1)
#define CRM_SET_REQUEST_LEN                             (1U)
/* SET_REQUEST EV  */
#define CRM_EV_ID                                       EV_BYTE(0)
#define CRM_EV_CODE                                     EV_BYTE(1)
#define CRM_SET_REQUEST_EV_CODE                         CRM_BYTE(1)

/* GET_SEED */
#define CRO_GET_SEED_LEN                                (3U)
#define CRO_GET_SEED_MODE                               CRO_BYTE(1)
#define CRO_GET_SEED_RESOURCE                           CRO_BYTE(2)
#define CRM_GET_SEED_LEN                                (CRM_GET_SEED_LENGTH+2u)
#define CRM_GET_SEED_LENGTH                             CRM_BYTE(1)
#define CRM_GET_SEED_DATA                               (&CRM_BYTE(2))

/* UNLOCK */
#define CRO_UNLOCK_LEN                                  (8U)
#define CRO_UNLOCK_LENGTH                               CRO_BYTE(1)
#define CRO_UNLOCK_KEY                                  (&CRO_BYTE(2))
#define CRM_UNLOCK_LEN                                  (2U)
#define CRM_UNLOCK_PROTECTION                           CRM_BYTE(1)

/* SET_MTA */
#define CRO_SET_MTA_LEN                                 (8U)
#define CRO_SET_MTA_EXT                                 CRO_BYTE(3)
#define CRO_SET_MTA_ADDR                                CRO_DWORD(1)
#define CRM_SET_MTA_LEN                                 (1U)

/* UPLOAD */
#define CRM_UPLOAD_MAX_SIZE                             ((uint8)(XCPMAXCTO_AG - 1U))
#define CRO_UPLOAD_LEN                                  (2U)
#define CRO_UPLOAD_SIZE                                 CRO_BYTE(1)
#define CRM_UPLOAD_LEN                                  (1U)  /* +CRO_UPLOAD_SIZE */
#define CRM_UPLOAD_DATA                                 (&CRM_BYTE(1))

/* SHORT_UPLOAD */
#define CRO_SHORT_UPLOAD_LEN                            (8U)
#define CRO_SHORT_UPLOAD_SIZE                           CRO_BYTE(1)
#define CRO_SHORT_UPLOAD_EXT                            CRO_BYTE(3)
#define CRO_SHORT_UPLOAD_ADDR                           CRO_DWORD(1)
#define CRM_SHORT_UPLOAD_MAX_SIZE                       ((uint8)(XCPMAXCTO_AG - 1U))
#define CRM_SHORT_UPLOAD_LEN                            (1U)  /* +CRO_SHORT_UPLOAD_SIZE */
#define CRM_SHORT_UPLOAD_DATA                           (&CRM_BYTE(1))

/* BUILD_CHECKSUM */
#define CRO_BUILD_CHECKSUM_LEN                          (Const_CRO_BUILD_CHECKSUM_LEN)
#define CRO_BUILD_CHECKSUM_SIZE                         CRO_DWORD(1)
#define CRM_BUILD_CHECKSUM_LEN                          (Const_CRM_BUILD_CHECKSUM_LEN)
#define CRM_BUILD_CHECKSUM_TYPE                         CRM_BYTE(1)
#define CRM_BUILD_CHECKSUM_RESULT                       CRM_DWORD(1)

/* DOWNLOAD */
#define CRO_DOWNLOAD_MAX_SIZE                           ((uint8)((XCP_MAX_CTO - 2u) / XCPAG))
#define CRO_DOWNLOAD_LEN                                (2U)  /* + CRO_DOWNLOAD_SIZE */
#define CRO_DOWNLOAD_SIZE                               CRO_BYTE(1)
#define CRO_DOWNLOAD_DATA                               (&CRO_BYTE(2))
#define CRM_DOWNLOAD_LEN                                (1U)

/* DOWNLOAD_NEXT */
#define CRO_DOWNLOAD_NEXT_MAX_SIZE                      ((uint8)((XCP_MAX_CTO - 2U) / XCPAG))
#define CRO_DOWNLOAD_NEXT_LEN                           (2U)  /* + size */
#define CRO_DOWNLOAD_NEXT_SIZE                          CRO_BYTE(1)
#define CRO_DOWNLOAD_NEXT_DATA                          (&CRO_BYTE(2))
#define CRM_DOWNLOAD_NEXT_LEN                           (1U)

/* DOWNLOAD_MAX */
#define CRO_DOWNLOAD_MAX_MAX_SIZE                       ((uint8)(XCPMAXCTO_AG - 1U))
#define CRO_DOWNLOAD_MAX_DATA                           (&CRO_BYTE(1))
#define CRM_DOWNLOAD_MAX_LEN                            (1U)

/* SHORT_DOWNLOAD */
#define CRO_SHORT_DOWNLOAD_LEN                          (8U)
#define CRO_SHORT_DOWNLOAD_SIZE                         CRO_BYTE(1)
#define CRO_SHORT_DOWNLOAD_EXT                          CRO_BYTE(3)
#define CRO_SHORT_DOWNLOAD_ADDR                         CRO_DWORD(1)
#define CRO_SHORT_DOWNLOAD_DATA                         (&CRO_BYTE(8))
#define CRM_SHORT_DOWNLOAD_MAX_SIZE                     ((uint8)((XCP_MAX_CTO - 8U) / XCPAG))
#define CRM_SHORT_DOWNLOAD_LEN                          (1U)  /* +CRO_SHORT_UPLOAD_SIZE */

/* MODIFY_BITS */
#define CRO_MODIFY_BITS_LEN                             (6U)
#define CRO_MODIFY_BITS_SHIFT                           CRO_BYTE(1)
#define CRO_MODIFY_BITS_AND                             CRO_WORD(1)
#define CRO_MODIFY_BITS_XOR                             CRO_WORD(2)
#define CRM_MODIFY_BITS_LEN                             (1U)

/* SET_CAL_PAGE */
#define CRO_SET_CAL_PAGE_LEN                            (4U)
#define CRO_SET_CAL_PAGE_MODE                           CRO_BYTE(1)
#define CRO_SET_CAL_PAGE_SEGMENT                        CRO_BYTE(2)
#define CRO_SET_CAL_PAGE_PAGE                           CRO_BYTE(3)
#define CRM_SET_CAL_PAGE_LEN                            (1U)

/* GET_CAL_PAGE */
#define CRO_GET_CAL_PAGE_LEN                            (3U)
#define CRO_GET_CAL_PAGE_MODE                           CRO_BYTE(1)
#define CRO_GET_CAL_PAGE_SEGMENT                        CRO_BYTE(2)
#define CRM_GET_CAL_PAGE_LEN                            (4U)
#define CRM_GET_CAL_PAGE_PAGE                           CRM_BYTE(3)

/* GET_PAG_PROCESSOR_INFO */
#define CRO_GET_PAG_PROCESSOR_INFO_LEN                  (1U)
#define CRM_GET_PAG_PROCESSOR_INFO_LEN                  (3U)
#define CRM_GET_PAG_PROCESSOR_INFO_MAX_SEGMENT          CRM_BYTE(1)
#define CRM_GET_PAG_PROCESSOR_INFO_PROPERTIES           CRM_BYTE(2)

/* GET_SEGMENT_INFO */
#define CRO_GET_SEGMENT_INFO_LEN                        (5U)
#define CRO_GET_SEGMENT_INFO_MODE                       CRO_BYTE(1)
#define CRO_GET_SEGMENT_INFO_NUMBER                     CRO_BYTE(2)
#define CRO_GET_SEGMENT_INFO_MAPPING_INDEX              CRO_BYTE(3)
#define CRO_GET_SEGMENT_INFO_MAPPING                    CRO_BYTE(4)
#define CRM_GET_SEGMENT_INFO_LEN                        (8U)
#define CRM_GET_SEGMENT_INFO_MAX_PAGES                  CRM_BYTE(1)
#define CRM_GET_SEGMENT_INFO_ADDRESS_EXTENSION          CRM_BYTE(2)
#define CRM_GET_SEGMENT_INFO_MAX_MAPPING                CRM_BYTE(3)
#define CRM_GET_SEGMENT_INFO_COMPRESSION                CRM_BYTE(4)
#define CRM_GET_SEGMENT_INFO_ENCRYPTION                 CRM_BYTE(5)
#define CRM_GET_SEGMENT_INFO_MAPPING_INFO               CRM_DWORD(1)

/* GET_PAGE_INFO */
#define CRO_GET_PAGE_INFO_LEN                           (4U)
#define CRO_GET_PAGE_INFO_SEGMENT_NUMBER                CRO_BYTE(2)
#define CRO_GET_PAGE_INFO_PAGE_NUMBER                   CRO_BYTE(3)
#define CRM_GET_PAGE_INFO_LEN                           (3U)
#define CRM_GET_PAGE_INFO_PROPERTIES                    CRM_BYTE(1)
#define CRM_GET_PAGE_INFO_INIT_SEGMENT                  CRM_BYTE(2)

/* SET_SEGMENT_MODE */
#define CRO_SET_SEGMENT_MODE_LEN                        (3U)
#define CRO_SET_SEGMENT_MODE_MODE                       CRO_BYTE(1)
#define CRO_SET_SEGMENT_MODE_SEGMENT                    CRO_BYTE(2)
#define CRM_SET_SEGMENT_MODE_LEN                        (1U)

/* GET_SEGMENT_MODE */
#define CRO_GET_SEGMENT_MODE_LEN                        (3U)
#define CRO_GET_SEGMENT_MODE_SEGMENT                    CRO_BYTE(2)
#define CRM_GET_SEGMENT_MODE_LEN                        (3U)
#define CRM_GET_SEGMENT_MODE_MODE                       CRM_BYTE(2)

/* COPY_CAL_PAGE */
#define CRO_COPY_CAL_PAGE_LEN                           (5U)
#define CRO_COPY_CAL_PAGE_SRC_SEGMENT                   CRO_BYTE(1)
#define CRO_COPY_CAL_PAGE_SRC_PAGE                      CRO_BYTE(2)
#define CRO_COPY_CAL_PAGE_DEST_SEGMENT                  CRO_BYTE(3)
#define CRO_COPY_CAL_PAGE_DEST_PAGE                     CRO_BYTE(4)
#define CRM_COPY_CAL_PAGE_LEN                           (1U)

/* CLEAR_DAQ_LIST */
#define CRO_CLEAR_DAQ_LIST_LEN                          (4U)
#define CRO_CLEAR_DAQ_LIST_DAQ                          CRO_WORD(1)
#define CRM_CLEAR_DAQ_LIST_LEN                          (1U)

/* SET_DAQ_PTR */
#define CRO_SET_DAQ_PTR_LEN                             (6U)
#define CRO_SET_DAQ_PTR_DAQ                             CRO_WORD(1)
#define CRO_SET_DAQ_PTR_ODT                             CRO_BYTE(4)
#define CRO_SET_DAQ_PTR_IDX                             CRO_BYTE(5)
#define CRM_SET_DAQ_PTR_LEN                             (1U)

/* WRITE_DAQ */
#define CRO_WRITE_DAQ_LEN                               (8U)
#define CRO_WRITE_DAQ_BITOFFSET                         CRO_BYTE(1)
#define CRO_WRITE_DAQ_SIZE                              CRO_BYTE(2)
#define CRO_WRITE_DAQ_EXT                               CRO_BYTE(3)
#define CRO_WRITE_DAQ_ADDR                              CRO_DWORD(1)
#define CRM_WRITE_DAQ_LEN                               (1U)

/* WRITE_DAQ_MULTIPLE */
#define CRO_WRITE_DAQ_MULIPLE_LEN                       (8U)
#define CRO_WRITE_DAQ_MULTIPLE_COMMAND                  CRO_BYTE(1)
#define CRO_WRITE_DAQ_MULTIPLE_NODAQ                    CRO_BYTE(2)
#define CRO_WRITE_DAQ_MULIPLE_BITOFFSET(i)              CRO_BYTE(8 + (8*(i)))
#define CRO_WRITE_DAQ_MULIPLE_SIZE(i)                   CRO_BYTE(9 + (8*(i)))
#define CRO_WRITE_DAQ_MULIPLE_EXT(i)                    CRO_BYTE(10 + (8*(i)))
#define CRO_WRITE_DAQ_MULIPLE_ADDR(i)                   CRO_DWORD(1 + (2*(i)))
#define CRM_WRITE_DAQ_MULIPLE_LEN                       (1U)

/* SET_DAQ_LIST_MODE */
#define CRO_SET_DAQ_LIST_MODE_LEN                       (8U)
#define CRO_SET_DAQ_LIST_MODE_MODE                      CRO_BYTE(1)
#define CRO_SET_DAQ_LIST_MODE_DAQ                       CRO_WORD(1)
#define CRO_SET_DAQ_LIST_MODE_EVENTCHANNEL              CRO_WORD(2)
#define CRO_SET_DAQ_LIST_MODE_PRESCALER                 CRO_BYTE(6)
#define CRO_SET_DAQ_LIST_MODE_PRIORITY                  CRO_BYTE(7)
#define CRM_SET_DAQ_LIST_MODE_LEN                       (6U)
#define XCP_DAQ_LIST_TIMESTAMP                          (0x10U)

/* GET_DAQ_LIST_MODE */
#define CRO_GET_DAQ_LIST_MODE_LEN                       (4U)
#define CRO_GET_DAQ_LIST_MODE_DAQ                       CRO_WORD(1)
#define CRM_GET_DAQ_LIST_MODE_LEN                       (8U)
#define CRM_GET_DAQ_LIST_MODE_MODE                      CRM_BYTE(1)
#define CRM_GET_DAQ_LIST_MODE_EVENTCHANNEL              CRM_WORD(2)
#define CRM_GET_DAQ_LIST_MODE_PRESCALER                 CRM_BYTE(6)
#define CRM_GET_DAQ_LIST_MODE_PRIORITY                  CRM_BYTE(7)

/* START_STOP_DAQ_LIST */
#define CRO_START_STOP_LEN                              (4U)
#define CRO_START_STOP_MODE                             CRO_BYTE(1)
#define CRO_START_STOP_DAQ                              CRO_WORD(1)
#define CRM_START_STOP_LEN                              (2U)
#define CRM_START_STOP_FIRST_PID                        CRM_BYTE(1)

/* START_STOP_SYNCH */
#define CRO_START_STOP_SYNC_LEN                         (Const_CRO_START_STOP_SYNC_LEN)
#define CRO_START_STOP_SYNC_MODE                        CRO_BYTE(1)
#define CRM_START_STOP_SYNC_LEN                         (1U)

/* GET_DAQ_CLOCK */
#define CRO_GET_DAQ_CLOCK_LEN                           (1U)
#define CRM_GET_DAQ_CLOCK_LEN                           (8U)
#define CRM_GET_DAQ_CLOCK_TIME                          CRM_DWORD(1)

/* READ_DAQ */
#define CRO_READ_DAQ_LEN                                (1U)
#define CRM_READ_DAQ_LEN                                (8U)
#define CRM_READ_DAQ_BITOFFSET                          CRM_BYTE(1)
#define CRM_READ_DAQ_SIZE                               CRM_BYTE(2)
#define CRM_READ_DAQ_EXT                                CRM_BYTE(3)
#define CRM_READ_DAQ_ADDR                               CRM_DWORD(1)

/* GET_DAQ_PROCESSOR_INFO */
#define CRO_GET_DAQ_PROCESSOR_INFO_LEN                  (1U)
#define CRM_GET_DAQ_PROCESSOR_INFO_LEN                  (8U)
#define CRM_GET_DAQ_PROCESSOR_INFO_PROPERTIES           CRM_BYTE(1)
#define CRM_GET_DAQ_PROCESSOR_INFO_MAX_DAQ              CRM_WORD(1)
#define CRM_GET_DAQ_PROCESSOR_INFO_MAX_EVENT            CRM_WORD(2)
#define CRM_GET_DAQ_PROCESSOR_INFO_MIN_DAQ              CRM_BYTE(6)
#define CRM_GET_DAQ_PROCESSOR_INFO_DAQ_KEY_BYTE         CRM_BYTE(7)

/* GET_DAQ_RESOLUTION_INFO */
#define CRO_GET_DAQ_RESOLUTION_INFO_LEN                 (1U)
#define CRM_GET_DAQ_RESOLUTION_INFO_LEN                 (8U)
#define CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_DAQ     CRM_BYTE(1)
#define CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_DAQ        CRM_BYTE(2)
#define CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_STIM    CRM_BYTE(3)
#define CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_STIM       CRM_BYTE(4)
#define CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_MODE      CRM_BYTE(5)
#define CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_TICKS     CRM_WORD(3)

/* GET_DAQ_LIST_INFO */
#define CRO_GET_DAQ_LIST_INFO_LEN                       (4U)
#define CRO_GET_DAQ_LIST_INFO_DAQ                       CRO_WORD(1)
#define CRM_GET_DAQ_LIST_INFO_LEN                       (6U)
#define CRM_GET_DAQ_LIST_INFO_PROPERTIES                CRM_BYTE(1)
#define CRM_GET_DAQ_LIST_INFO_MAX_ODT                   CRM_BYTE(2)
#define CRM_GET_DAQ_LIST_INFO_MAX_ODT_ENTRY             CRM_BYTE(3)
#define CRM_GET_DAQ_LIST_INFO_FIXED_EVENT               CRM_WORD(2)

/* GET_DAQ_EVENT_INFO */
#define CRO_GET_DAQ_EVENT_INFO_LEN                      (4U)
#define CRO_GET_DAQ_EVENT_INFO_EVENT                    CRO_WORD(1)
#define CRM_GET_DAQ_EVENT_INFO_LEN                      (7U)
#define CRM_GET_DAQ_EVENT_INFO_PROPERTIES               CRM_BYTE(1)
#define CRM_GET_DAQ_EVENT_INFO_MAX_DAQ_LIST             CRM_BYTE(2)
#define CRM_GET_DAQ_EVENT_INFO_NAME_LENGTH              CRM_BYTE(3)
#define CRM_GET_DAQ_EVENT_INFO_TIME_CYCLE               CRM_BYTE(4)
#define CRM_GET_DAQ_EVENT_INFO_TIME_UNIT                CRM_BYTE(5)
#define CRM_GET_DAQ_EVENT_INFO_PRIORITY                 CRM_BYTE(6)

/* FREE_DAQ */
#define CRO_FREE_DAQ_LEN                                (1U)
#define CRM_FREE_DAQ_LEN                                (1U)

/* ALLOC_DAQ */
#define CRO_ALLOC_DAQ_LEN                               (4U)
#define CRO_ALLOC_DAQ_COUNT                             CRO_WORD(1)
#define CRM_ALLOC_DAQ_LEN                               (1U)

/* ALLOC_ODT */
#define _CRO_ALLOC_ODT_LEN                              (3U)
#define _CRO_ALLOC_ODT_DAQ                              CRO_WORD(1)
#define _CRO_ALLOC_ODT_COUNT                            CRO_BYTE(1)
#define CRO_ALLOC_ODT_LEN                               (5U)
#define CRO_ALLOC_ODT_DAQ                               CRO_WORD(1)
#define CRO_ALLOC_ODT_COUNT                             CRO_BYTE(4)
#define CRM_ALLOC_ODT_LEN                               (1U)

/* ALLOC_ODT_ENTRY */
#define CRO_ALLOC_ODT_ENTRY_LEN                         (6U)
#define CRO_ALLOC_ODT_ENTRY_DAQ                         CRO_WORD(1)
#define CRO_ALLOC_ODT_ENTRY_ODT                         CRO_BYTE(4)
#define CRO_ALLOC_ODT_ENTRY_COUNT                       CRO_BYTE(5)
#define CRM_ALLOC_ODT_ENTRY_LEN                         (1U)

/* PROGRAM_START */
#define CRO_PROGRAM_START_LEN                           (1U)
#define CRM_PROGRAM_START_LEN                           (7U)
#define CRM_PROGRAM_COMM_MODE_PGM                       CRM_BYTE(2)
#define CRM_PROGRAM_MAX_CTO_PGM                         CRM_BYTE(3)
#define CRM_PROGRAM_MAX_BS_PGM                          CRM_BYTE(4)
#define CRM_PROGRAM_MIN_ST_PGM                          CRM_BYTE(5)
#define CRM_PROGRAM_QUEUE_SIZE_PGM                      CRM_BYTE(6)

/* PROGRAM_CLEAR */
#define CRO_PROGRAM_CLEAR_LEN                           (8U)
#define CRO_PROGRAM_CLEAR_MODE                          CRO_BYTE(1)
#define CRO_PROGRAM_CLEAR_SIZE                          CRO_DWORD(1)
#define CRM_PROGRAM_CLEAR_LEN                           (1U)

/* PROGRAM */
#define CRO_PROGRAM_MAX_SIZE                            ((uint8)((XCP_MAX_CTO - 2U) / XCPAG))
#define CRO_PROGRAM_LEN                                 (2U)  /* + CRO_PROGRAM_SIZE */
#define CRO_PROGRAM_SIZE                                CRO_BYTE(1)
#define CRO_PROGRAM_DATA                                (&CRO_BYTE(2))
#define CRM_PROGRAM_LEN                                 (1U)

/* PROGRAM RESET */
#define CRO_PROGRAM_RESET_LEN                           (1U)
#define CRM_PROGRAM_RESET_LEN                           (1U)

/*GET_PGM_PROCESSOR_INFO*/
#define CRO_GET_PGM_PROCESSOR_INFO_LEN                  (1U)
#define CRM_GET_PGM_PROCESSOR_INFO_LEN                  (3U)
#define CRM_GET_PGM_PROCESSOR_INFO_PROPERTIES           CRM_BYTE(1)
#define CRM_GET_PGM_PROCESSOR_INFO_MAX_SECTOR           CRM_BYTE(2)

/* GET_SECTOR_INFO */
#define CRO_PROGRAM_GET_SECTOR_INFO_LEN                 (3U)
#define CRO_PROGRAM_GET_SECTOR_INFO_MODE                CRO_BYTE(1)
#define CRO_PROGRAM_GET_SECTOR_INFO_NUMBER              CRO_BYTE(2)
#define CRM_PROGRAM_GET_SECTOR_INFO_LEN                 (8U)
#define CRM_PROGRAM_GET_SECTOR_CLEAR_SEQ_NUM            CRM_BYTE(1)
#define CRM_PROGRAM_GET_SECTOR_PGM_SEQ_NUM              CRM_BYTE(2)
#define CRM_PROGRAM_GET_SECTOR_PGM_METHOD               CRM_BYTE(3)
#define CRM_PROGRAM_GET_SECTOR_SECTOR_INFO              CRM_DWORD(1)

/* PROGRAM_PREPARE */
#define CRO_PROGRAM_PREPARE_LEN                         (4U)
#define CRO_PROGRAM_PREPARE_SIZE                        CRO_WORD(1)
#define CRM_PROGRAM_PREPARE_LEN                         (1U)

/* PROGRAM_FORMAT */
#define CRO_PROGRAM_FORMAT_LEN                          (5U)
#define CRO_PROGRAM_FORMAT_COMPRESSION_METHOD           CRO_BYTE(1)
#define CRO_PROGRAM_FORMAT_ENCRYPTION_METHOD            CRO_BYTE(2)
#define CRO_PROGRAM_FORMAT_PROGRAMMING_METHOD           CRO_BYTE(3)
#define CRO_PROGRAM_FORMAT_ACCESS_METHOD                CRO_BYTE(4)
#define CRM_PROGRAM_FORMAT_LEN                          (1U)

/* PROGRAM_NEXT */
#define CRO_PROGRAM_NEXT_MAX_SIZE                       ((uint8)((XCP_MAX_CTO - 2U) / XCPAG))
#define CRO_PROGRAM_NEXT_LEN                            (2U)  /* + size */
#define CRO_PROGRAM_NEXT_SIZE                           CRO_BYTE(1)
#define CRO_PROGRAM_NEXT_DATA                           (&CRO_BYTE(2))
#define CRM_PROGRAM_NEXT_LEN                            (3U)
#define CRM_PROGRAM_NEXT_ERR_SEQUENCE                   CRM_BYTE(1)
#define CRM_PROGRAM_NEXT_SIZE_EXPECTED_DATA             CRM_BYTE(2)

/* PROGRAM_MAX */
#define CRO_PROGRAM_MAX_MAX_SIZE                        ((uint8)((XCP_MAX_CTO - XCPAG) / XCPAG))
#define CRO_PROGRAM_MAX_DATA                            (&CRO_BYTE(1))
#define CRM_PROGRAM_MAX_LEN                             (1U)

/* PROGRAM_VERIFY */
#define CRO_PROGRAM_VERIFY_LEN                          (8U)
#define CRO_PROGRAM_VERIFY_MODE                         CRO_BYTE(1)
#define CRO_PROGRAM_VERIFY_TYPE                         CRO_WORD(1)
#define CRO_PROGRAM_VERIFY_VALUE                        CRO_DWORD(1)
#define CRM_PROGRAM_VERIFY_LEN                          (1U)

/* GET_SLAVE_ID */
#define CRO_GET_SLAVE_ID_LEN                            (6U)
#define CRO_GET_SLAVE_ID_SUB_CODE                       CRO_BYTE(1)
#define CRO_GET_SLAVE_ID_X                              CRO_BYTE(2)
#define CRO_GET_SLAVE_ID_C                              CRO_BYTE(3)
#define CRO_GET_SLAVE_ID_P                              CRO_BYTE(4)
#define CRO_GET_SLAVE_ID_MODE                           CRO_BYTE(5)
#define CRM_GET_SLAVE_ID_LEN                            (8U)
#define CRM_GET_SLAVE_ID_X                              CRM_BYTE(1)
#define CRM_GET_SLAVE_ID_C                              CRM_BYTE(2)
#define CRM_GET_SLAVE_ID_P                              CRM_BYTE(3)
#define CRM_GET_SLAVE_ID_CAN_ID_CMD_STIM                CRM_DWORD(1)

/* GET_DAQ_ID */
#define CRO_GET_DAQ_ID_LEN                              (3U)
#define CRO_GET_DAQ_ID_SUB_CODE                         CRO_BYTE(1)
#define CRO_GET_DAQ_ID_DAQ                              CRO_WORD(1)
#define CRM_GET_DAQ_ID_LEN                              (8U)
#define CRM_GET_DAQ_ID_FIXED                            CRM_BYTE(1)
#define CRM_GET_DAQ_ID_ID                               CRM_DWORD(1)

/* SET_DAQ_ID */
#define CRO_SET_DAQ_ID_LEN                              (8U)
#define CRO_SET_DAQ_ID_SUB_CODE                         CRO_BYTE(1)
#define CRO_SET_DAQ_ID_DAQ                              CRO_WORD(1)
#define CRO_SET_DAQ_ID_ID                               CRO_DWORD(1)
#define CRM_SET_DAQ_ID_LEN                              (1U)

/* SET_SLAVE_PORT */
#define CRO_SET_SLAVE_PORT_LEN                          (4U)
#define CRO_SET_SLAVE_PORT_SUB_CODE                     CRO_BYTE(1)
#define CRO_SET_SLAVE_PORT_PORT                         CRO_WORD(1)

#define CRM_SET_SLAVE_PORT                              (1U)

/* Implementation      */
#if defined (XCP_ENABLE_SEND_EVENT) && ( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
#define EV_BYTE(x)              (Xcp_Data.Ev.bytes[x])
#endif

#define CRO_BYTE(x)             (pCmd->bytes[x])    /*pcmd: Orders accepted*/
#define CRO_WORD(x)             (pCmd->words[x])
#define CRO_DWORD(x)            (pCmd->dwords[x])
#define CRM_BYTE(x)             (Xcp_Data.Crm.bytes[x])
#define CRM_WORD(x)             (Xcp_Data.Crm.words[x])
#define CRM_DWORD(x)            (Xcp_Data.Crm.dwords[x])

#define XCP_MAX_ODT_ENTRY_SIZE (XCP_MAX_DTO - 1U)

/* XCP Driver Variables, Type Definition      */
/* Return values */
#define XCP_CMD_OK                  (0U)
#define XCP_CMD_DENIED              (1U)
#define XCP_CMD_PENDING             (2U)
#define XCP_CMD_SYNTAX              (3U)
#define XCP_CMD_BUSY                (4U)
#define XCP_CMD_UNKNOWN             (5U)
#define XCP_CMD_OUT_OF_RANGE        (6U)
#define XCP_MODE_NOT_VALID          (7U)
#define XCP_CMD_ERROR               (0xFFU)

/* Return values for XcpEvent() */
#define XCP_EVENT_NOP               (0x00U)   /* Inactive (DAQ not running, Event not configured) */
#define XCP_EVENT_DAQ               (0x01U)   /* DAQ active */
#define XCP_EVENT_DAQ_OVERRUN       (0x02U)   /* DAQ queue overflow */
#define XCP_EVENT_STIM              (0x04U)   /* STIM active */
#define XCP_EVENT_STIM_OVERRUN      (0x08U)   /* STIM data not available */

/* Bitmasks for xcp.SendStatus */
#define XCP_CRM_REQUEST             (0x01U)
#define XCP_DTO_REQUEST             (0x02U)
#define XCP_EVT_REQUEST             (0x04U)
#define XCP_CRM_PENDING             (0x10U)
#define XCP_DTO_PENDING             (0x20U)
#define XCP_EVT_PENDING             (0x40U)
#define XCP_SEND_PENDING            (XCP_DTO_PENDING|XCP_CRM_PENDING|XCP_EVT_PENDING)

/* Shortcuts */
/* j is absolute odt number */
#define DaqListOdtEntryCount(j) ((Xcp_Data.pOdt[j].lastOdtEntry - Xcp_Data.pOdt[j].firstOdtEntry) + 1U)
#define DaqListOdtLastEntry(j)  (Xcp_Data.pOdt[j].lastOdtEntry)
#define DaqListOdtFirstEntry(j) (Xcp_Data.pOdt[j].firstOdtEntry)
#define DaqListOdtStimBuffer(j) (Xcp_Data.pOdt[j].pStimBuffer)

/* n is absolute odtEntry number */
#define OdtEntrySize(n)         (Xcp_Data.pOdtEntrySize[n])
#define OdtEntryAddr(n)         (Xcp_Data.pOdtEntryAddr[n])

/* i is daq number */
#define DaqListOdtCount(i)      ((Xcp_Data.Daq.u.DaqList[i].lastOdt - Xcp_Data.Daq.u.DaqList[i].firstOdt) + 1U)
#define DaqListLastOdt(i)       (Xcp_Data.Daq.u.DaqList[i].lastOdt)
#define DaqListFirstOdt(i)      (Xcp_Data.Daq.u.DaqList[i].firstOdt)
#define DaqListFirstPid(i)      (Xcp_Data.Daq.u.DaqList[i].firstOdt)
#define DaqListFlags(i)         (Xcp_Data.Daq.u.DaqList[i].flags)
#define DaqListEventChannel(i)  (Xcp_Data.Daq.u.DaqList[i].eventChannel)
#define DaqListPrescaler(i)     (Xcp_Data.Daq.u.DaqList[i].prescaler)
#define DaqListCycle(i)         (Xcp_Data.Daq.u.DaqList[i].cycle)

/* x is current queue */
#define XcpStimOdt(x)           (Xcp_Data.pQueueStim[x].xcpStimOdt)
#define XcpStimData(x)           (Xcp_Data.pQueueStim[x].bytes)
#ifdef XCP_ENABLE_PAGE_COPY
#define CALPAGE_FLASH          (0U)
#define CALPAGE_RAM            (1U)
#endif

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* XCP Packet Type Definition         */
typedef struct{
    uint8 bytes[XCP_MAX_DTO];
    uint32 length;
} Xcp_Dto_st;

#if ( XCP_TIMESTAMP_TYPE == XCPTS_ONE_BYTE )
typedef uint8 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
#elif ( XCP_TIMESTAMP_TYPE == XCPTS_TWO_BYTE )
typedef uint16 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
#else
typedef uint32 Xcp_TimestampType; /*<! Timestamp used during DAQ measurement */
#endif

typedef struct{
#if ( XCP_MAX_DTO > XCP_255 )
    uint8 bytes[XCP_255];
#else
    uint8 bytes[XCP_MAX_DTO];
#endif
    uint8 xcpStimDaq;
    uint8 xcpStimOdt;
#if( XCP_TIMESTAMP_TYPE > XCP_ZERO )
    Xcp_TimestampType xcpStimTimeStamp;     /* STIM timetamp */
#endif
} Xcp_Stim_Dto_st;

#if( XCP_ONETHERNET_ENABLE == STD_ON )
typedef struct{
    uint8 bytes[XCP_MAX_DTO + XCP_FOUR];
    uint32 length;
}Xcp_Eth_Dto_st;
#endif

typedef union{
    /* There might be a loss of up to 3 bytes. */
    uint8 bytes[ ((XCP_MAX_CTO + 3U) & 0xFFCU) ];
    uint16 words[ ((XCP_MAX_CTO + 3U) & 0xFFCU) / 2U ];
    uint32 dwords[ ((XCP_MAX_CTO + 3U) & 0xFFCU) / 4U ];
} Xcp_Cto_st;

/* ODT */
/* Size must be even !!! */
#ifdef XCP_ENABLE_DAQ

typedef struct{
    uint16 firstOdtEntry;       /* Absolute */
    uint16 lastOdtEntry;        /* Absolute */
} Xcp_Odt_st;

/* DAQ list */
typedef struct{
    uint8 lastOdt;
    uint8 firstOdt;
    uint8 flags;
    uint8 eventChannel;

    #if( XCP_PRESCALER_SUPPORTED == STD_ON )
    uint8 prescaler;
    uint8 cycle;
    #endif
} Xcp_DaqList_st;

/* Dynamic DAQ list structures */
typedef struct{
    union{
        uint8 b[XCP_DAQMEMSIZE];
        Xcp_DaqList_st DaqList[XCP_MIN_DAQ + XCP_DAQ_COUNT];
    }u;
    uint8 StimDateBuffer[XCP_DAQMEMSIZE_STIM];
    uint8 DaqCount;
    uint8 OdtCount;                /* Absolute count */
    uint16 OdtEntryCount;          /* Absolute count */

    uint8 EventDaq[XCP_MAX_EVENT];  /* Event-Daq association array */
} Xcp_Daq_st;
/* DAQ Lists, Type Definition */
#endif /* XCP_ENABLE_DAQ */

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
/* ram definition */
typedef struct{
    uint32 RamStaAddr;
    uint32 RamCurAddr;
    uint32 RamLen;
}Xcp_Ram_st;
/* ram list */
typedef struct{
    uint8 RamCnt;
    uint8 RamNum;
    Xcp_Ram_st *RamCfg;
}Xcp_RamList_st;
typedef struct{
    uint32 CalVecAddr;
    uint32 CalVecWpAddr;
    uint32 CalVecRpAddr;
    uint32 CalVecLen;
}Xcp_VectInfo_st;

typedef struct{
    uint16 vect_cnt;
    Xcp_VectInfo_st *vect_info;
}Xcp_VectList_st;

typedef struct{
    uint16 DownSize;
    uint32 CopyAddrSrc;
    uint32 CopyAddrDest;
    uint32 CopyLen;
    uint8 CopyReqState;
    const uint8* DownData;
}Xcp_DownloadCopy_t;
#endif
/* Checksum, Type Definition            */
typedef uint8 tXcpChecksumAddType;     /* Data type (width) of the data to be added.  */
#if( XCP_ADD12 == XCP_CHECKSUM_TYPE )
typedef uint16 tXcpChecksumSumType;    /* Data type (width) of the actually checksum. */
#elif( XCP_ADD11 == XCP_CHECKSUM_TYPE )
typedef uint8 tXcpChecksumSumType;    /* Data type (width) of the actually checksum. */
#elif( XCP_CRC32== XCP_CHECKSUM_TYPE )
typedef uint32 tXcpChecksumSumType;
#endif

typedef struct {
    Xcp_Cto_st Crm;                     /* RES,ERR Message buffer */
    uint32  CrmLen;                     /* RES,ERR Message length */
    uint16  sessionId;                  /* Record Session ID */
    uint8   storeFlag;                  /* Store NVM's block flag */
    uint8   PageInd;                     /* Flag of WP or RP */
#if defined (XCP_ENABLE_SEND_EVENT) && ( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
    Xcp_Cto_st Ev;                      /* EV,SERV Message buffer */
    uint8 EvLen;                       /* EV,SERV Message length */
#endif

    uint8 SessionStatus;
    uint8* Mta;                        /* Memory Transfer Address */
#if( XCP_ENABLE_SEED_KEY == STD_ON )
    uint8 ProtectionStatus;            /* Resource Protection Status */
#endif

#if( STD_ON == XCP_ENABLE_CHECKSUM )
#if( XCP_CRC32 != XCP_CHECKSUM_TYPE )
    uint16 CheckSumSize;   /* Counter for checksum calculation */
#else
    uint32             CheckSumSize;   /* Counter for checksum calculation */
#endif
    tXcpChecksumSumType CheckSum;      /* Actual checksum */
    uint8 Crc32Flag;
#endif

#if( STD_ON == XCP_BLOCK_UPLOAD )
    uint8 NextDataBlockSize;
#endif
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
    uint8 NextDownloadSize;
#endif
    /* Dynamic DAQ list structures
    This structure should be stored in resume mode */
#ifdef XCP_ENABLE_DAQ
    Xcp_Daq_st Daq;
    Xcp_Odt_st *pOdt;
    uint8* *pOdtEntryAddr;
    uint8 *pOdtEntrySize;

    /* Transmit Queue */
#if( MULTIPDUIDSUPPORT == STD_ON )

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    Xcp_Dto_st *pQueue[XCP_EVENT_CHANNEL_NUM];
    uint8 QueueSize[XCP_EVENT_CHANNEL_NUM];
    uint8 QueueLen[XCP_EVENT_CHANNEL_NUM];
    uint8 QueueRp[XCP_EVENT_CHANNEL_NUM];
#endif
    /* Transmit Status */
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    uint8 SendStatus[XCP_TXPDU_LIST];
#endif

#else
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    Xcp_Dto_st *pQueue;
    uint8 QueueSize;
    uint8 QueueLen;
    uint8 QueueRp;
#endif

#ifdef XCP_ENABLE_STIM_QUEUE
    Xcp_Stim_Dto_st *pQueueStim;
    uint8 QueueSizeStim;
    uint8 QueueLenStim;
    uint8 QueueRpStim;
#endif

    /* Transmit Status */
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    uint8 SendStatus;
#endif
#endif  /*MULTIPDUIDSUPPORT == STD_ON*/
    /* Pointer for SET_DAQ_PTR */
    uint16 DaqListPtr;
#endif /* defined (XCP_ENABLE_DAQ) */
#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
    Xcp_RamList_st * XcpRamPtr;
#endif
} XCP_Data_st;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
extern VAR(uint8, XCP_VAR_INIT) CanXcpGetStatus;
extern VAR(uint8, XCP_VAR_INIT) XcpCommandTimeCounter;

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
#if( XCP_VERSION_INFO_API == STD_ON )
extern FUNC(void, XCP_CODE) Xcp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, XCP_APPL_DATA) VersionInfoPtr
);
#endif

extern FUNC(void, XCP_CODE) Xcp_Init(void);
extern FUNC(void, XCP_CODE) Xcp_Command
(
    P2CONST(uint32, AUTOMATIC, XCP_APPL_CONST) avlpCommand
);
extern FUNC(uint8, XCP_CODE) Xcp_Event(uint8 avcEvent);
extern FUNC(uint8, XCP_CODE) Xcp_StimEvent(uint8 daq);
extern FUNC(uint8, XCP_CODE) Xcp_DaqEvent(uint8 daq);
extern FUNC(uint8, XCP_CODE) Xcp_Background(void);
extern FUNC(void, XCP_CODE) Xcp_Disconnect(void);
extern FUNC(void, XCP_CODE) Xcp_SendCrm(void);
#if ( MULTIPDUIDSUPPORT == STD_ON )
extern FUNC(uint8, XCP_CODE) Xcp_SendCallBack(uint8 eventid);
#else
extern FUNC(uint8, XCP_CODE) Xcp_SendCallBack(void);
#endif

#ifdef XCP_ENABLE_DAQ

#if ( MULTIPDUIDSUPPORT == STD_ON )
extern FUNC(void, XCP_CODE) Xcp_SendDto
(
    uint8 eventid,
    P2VAR(Xcp_Dto_st, AUTOMATIC, XCP_APPL_DATA)astpDto
);
#else
extern FUNC(void, XCP_CODE) Xcp_SendDto
(
    P2VAR(Xcp_Dto_st, AUTOMATIC, XCP_APPL_DATA)astpDto
);
#endif /* MULTIPDUIDSUPPORT == STD_ON */
#endif /* XCP_ENABLE_DAQ */

extern FUNC(void, XCP_CODE) Xcp_MemSet
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)destAddr,
    uint16 num, uint8 byte
);
extern FUNC(void, XCP_CODE) Xcp_MemCpy8
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) dest,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST)src,
    uint32 num
);
extern FUNC(void, XCP_CODE) Xcp_MemClr
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)straddr,
    uint16 num
);
extern FUNC(void, XCP_CODE) Xcp_MainFunction(void);
extern FUNC(void, XCP_CODE) Xcp_Det_ErrorReport(uint8 ApiId, uint8 ErrorId);
extern FUNC(void, XCP_CODE) Xcp_InterruptDisable(void);
extern FUNC(void, XCP_CODE) Xcp_InterruptEnable(void);

#if( XCP_ONCAN_ENABLE == STD_ON )
extern FUNC(void, XCP_CODE) CanXcp_Init(void);
extern FUNC(void, XCP_CODE) CanXcp_MainFunction(void);

#if ( MULTIPDUIDSUPPORT == STD_ON )
extern FUNC(void, XCP_CODE) CanXcp_Send
(
    uint8 pduid, uint32 len,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST) msg
);
#else
extern FUNC(void, XCP_CODE) CanXcp_Send
(
    uint32 len,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST) msg
);
#endif

extern FUNC(uint8, XCP_CODE) CanXcp_GetRxMsg(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_CONST) avcpDlc,
    P2VAR(uint32, AUTOMATIC, XCP_APPL_CONST) avlpId,
    P2VAR(uint32, AUTOMATIC, XCP_APPL_CONST) avlpData
);
#endif

#if( XCP_ONETHERNET_ENABLE == STD_ON )
extern FUNC(void, XCP_CODE) Xcp_SendEthDaq
(
    P2VAR(Xcp_Eth_Dto_st, AUTOMATIC, XCP_APPL_DATA)astpDto
);
extern FUNC(void, XCP_CODE) EthXcp_Init(void);
extern FUNC(void, XCP_CODE) EthXcp_MainFunction(void);
extern FUNC(void, XCP_CODE) EthXcp_Send(uint16 len, P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST) msg);
extern FUNC(uint8, XCP_CODE) EthXcp_GetRxMsg(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_CONST) avcpDlc,
    P2VAR(uint32, AUTOMATIC, XCP_APPL_CONST) avlpId,
    P2VAR(uint32, AUTOMATIC, XCP_APPL_CONST) avlpData
);
#endif

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
extern FUNC(void, XCP_CODE) Xcp_CalVectRegister
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_CONST) *Pptr,
    uint16 Size
);
#endif

#if ( XCP_ENABLE_SEND_QUEUE == STD_OFF )
extern FUNC(void, XCP_CODE) Xcp_SendDtoMode(P2VAR(Xcp_Dto_st, AUTOMATIC, XCP_APPL_DATA)astpDto);
#endif

extern FUNC(void, XCP_CODE) Xcp_StimDate
(
    P2VAR(const uint8, AUTOMATIC, XCP_APPL_DATA) stimDate,
    uint32 dateLen
);

#endif
