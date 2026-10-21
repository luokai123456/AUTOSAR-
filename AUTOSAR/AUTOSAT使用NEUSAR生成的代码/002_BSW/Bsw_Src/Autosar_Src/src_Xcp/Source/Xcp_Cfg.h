/*
********************************************************************************
*
*  File name:   Xcp_Cfg.h
*
*  Copyright    Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2018.12.28
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : fangtao/2020.08.11
* Change: Delete event name.
* Cause: Bugfix
********************************************************************************
* Version: 3.0
* Author/Date: FangT/2021.03.03
* Change: Add checksum and Multi pudid functions.
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date: lqiao/2022.09.16
* Change: Add struct CanXcpFrame_st
* Cause: new.
********************************************************************************
* Version: 3.2
* Author/Date: zxt/2022.12.27
* Change: delete #define XCP_DaqMemSize                  (4096U)
* Cause:CCOREDBUG-1896.
********************************************************************************
*/
#ifndef XCP_CFG_H_
#define XCP_CFG_H_

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
#define XCP_STATIONIDLENGTH             (7U) /* Slave device identification length */
#define XCP_STATIONIDSTRING             "NEUXCP"

/* Standard commands */
#define XCP_ENABLE_COMM_MODE_INFO /* Get communication mode info */

/* Checksum */
#define XCP_CHECKSUMBLOCKSIZE           (1024U)

/* Synchronous Data Acquisition (DAQ) */
#define XCP_ENABLE_DAQ  /* Daq */
#define XCP_ENABLE_DAQ_PRESCALER          /* Daq Prescaler */
#define XCP_ENABLE_DAQ_OVERRUN_INDICATION /* Daq OverRun Indication */

/* Synchronous Data Stimulation (STIM) */
#define XCP_ENABLE_STIM
#define XCP_ENABLE_STIM_QUEUE

/* Add a macro with multiple daqs under one channel */
#define XCP_ENABLE_MULDAQ_EVENT

/* Page switching */
#define XCP_ENABLE_CALIBRATION_PAGE          /* Calibration Page */
#define XCP_MAXSEGMENT                  (1U) /* Segment */
#define XCP_MAXPAGES                    (2U)

/* Verify Algorithm Type */
#define XCP_ADD11                       (1U)
#define XCP_ADD12                       (2U)
#define XCP_CRC32                       (3U)

/* Programming */

/* Motorola */
#define XCP_CPUTYPE_BIGENDIAN

#define XCPSTACKSIZE                    (10U)

/* Xcp/XcpGeneral */
#define DAQ_DEFAULT                     (0x00U)
#define DAQ_DYNAMIC                     (0x01U)
#define DAQ_STATIC                      (0x02U)

#define ID_TYPE_DEFAULT                 (0U)
#define ID_TYPE_ABSOLUTE                (1U)
#define ID_TYPE_RELATIVE_BYTE           (2U)
#define ID_TYPE_RELATIVE_WORD           (3U)
#define ID_TYPE_RELATIVE_WORD_ALIGNED   (4U)

#define XCPTS_NO_TIME_STAMP             (0U)
#define XCPTS_ONE_BYTE                  (1U)
#define XCPTS_TWO_BYTE                  (2U)
#define XCPTS_NOT_ALLOWED               (3U)
#define XCPTS_FOUR_BYTE                 (4U)

#define RTE_INITRAM_METHOD              (0U)
#define RTE_SINGLE_PT_METHOD            (1U)
#define RTE_MMU_METHOD                  (2U)
#define OVERLAY_METHOD                  (3U)
#define XCP_STRUCTUREPT_METHOD	        (8U)

#define MULTIPDUIDSUPPORT               (STD_OFF)

#define TIMESTAMP_UINT_DEFAULT          (0U)

#define XCP_DAQMEMSIZE_STIM             (6144U)
#define XCP_ENABLE_SEND_EVENT
#define XCPDAQCONFIGTYPE                       (DAQ_DYNAMIC)
#define XCP_DAQ_COUNT                          (5U)
#define XCP_DEV_ERROR_DETECT                   (STD_ON)
#define XCP_FLASH_PROGRAMING_ENABLE            (STD_OFF)
#define XCP_IDENTIFICATION_FIELD_TYPE          (ID_TYPE_ABSOLUTE)
#define XCP_MAINFUNCTION_PERIOD                (5U)
#define XCP_MAX_CTO                            (8U)
#define XCP_MAX_DTO                            (8U)
#define XCP_MAX_EVENT                          (5U)
#define XCP_MIN_DAQ                            (0U)
#define XCP_ODT_COUNT                          (Const_XCP_ODT_COUNT)
#define XCP_ODT_ENTRYS_COUNT                   (Const_XCP_ODT_ENTRYYS_COUNT)
#define XCP_ODT_ENTRY_SIZE_DAQ                 (8U)
#define XCP_ODT_ENTRY_SIZE_STIM                (0U)
#define XCP_ONCAN_ENABLE                       (STD_ON)
#define XCP_ONCDD_ENABLE                       (STD_OFF)
#define XCP_ONETHERNET_ENABLE                  (STD_OFF)
#define XCP_ONFLEXRAY_ENABLE                   (STD_OFF)
#define XCP_PRESCALER_SUPPORTED                (STD_OFF)
#define XCP_SUPPRESS_TX_SUPPORT                (STD_OFF)
#define XCP_TIMESTAMP_TICKS                    (1U)
#define XCP_TIMESTAMP_TYPE                     (XCPTS_NO_TIME_STAMP)
#define XCP_TIMESTAMP_UNIT                     (DAQ_TIMESTAMP_UNIT_10MS)
#define XCP_VERSION_INFO_API                   (STD_ON)
#define XCP_COUNTER_REF                        (2U)
#define XCP_NVRAM_BLOCK_REF                    (0U)
#define XCP_DAQMEMSIZE                         (2048U)
#define XCP_ENABLE_SEND_QUEUE                  (STD_OFF)
#define XCP_ENABLE_NVM_SAVE_DATA               (STD_OFF)
#define XCP_ENABLE_SEED_KEY                    (STD_OFF)
#define XCPBLOCK_SIZE                          (2U)
#define XCPBLOCK_MIN_ST                        (0U)
#define XCP_CHECKSUM_TYPE                      (XCP_ADD12)
#define XCP_BLOCK_DOWNLOAD                     (STD_OFF)
#define XCP_BLOCK_UPLOAD                       (STD_OFF)
#define XCP_ENABLE_CHECKSUM                    (STD_ON)
#define RTECALIBRATIONSUPPORT                  (0U)
#define CALRAM_ADDR                            (XCP_valCalRAM_ADDR_MP)   /*Overlay��ַ���䣬ǰ��0x100�ֽ�����blkd����*/
#define CALFLASH_ADDR                          (XCP_valCalFLASH_ADDR_MP)   /*Overlay��ַ���䣬ǰ��0x100�ֽ�����blkd����*/
#define CALRAM_SIZE                            (XCP_valCALRAM_SIZE_MP)
#define SINGCALRAM_SIZE                        (2048U)
#define TRANSMITTIMEOUT                        (1U)

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

#endif  /* XCP_CFG_H_ */

