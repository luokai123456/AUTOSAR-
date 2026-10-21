/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : SPI
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Spi.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Spi
*   @{
*/
/*PRQA S 1536,2053,3430,0722,1756,1758 EOF*/
#ifndef SPI_H
#define SPI_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
INCLUDE
==================================================================================================*/

#include "Spi_Cfg.h"
/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID                   176
#define SPI_AR_RELEASE_MAJOR_VERSION    4
#define SPI_AR_RELEASE_MINOR_VERSION    4
#define SPI_AR_PATCH_VER                0
#define SPI_SW_MAJOR_VER                3
#define SPI_SW_MINOR_VER                0
#define SPI_SW_PATCH_VER                0
#define SPI_MODULE_ID                   83
/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_VENDOR_ID != SPI_CFG_VENDOR_ID)
#error "NON-MATCHED DATA : SPI_VENDOR_ID"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (SPI_AR_RELEASE_MAJOR_VERSION != SPI_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SPI_AR_RELEASE_MAJOR_VERSION"
#endif
#if (SPI_AR_RELEASE_MINOR_VERSION != SPI_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SPI_AR_RELEASE_MINOR_VERSION"
#endif
#if (SPI_AR_PATCH_VER != SPI_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SPI_AR_PATCH_VER"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (SPI_SW_MAJOR_VER != SPI_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SPI_SW_MAJOR_VER"
#endif
#if (SPI_SW_MINOR_VER != SPI_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SPI_SW_MINOR_VER"
#endif
#if (SPI_SW_PATCH_VER != SPI_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SPI_SW_PATCH_VER"
#endif

/*==================================================================================================
DEFINES
==================================================================================================*/
#define SPI_INSTANCE_ID                             (uint8)0x00

#define SPI_CORE_NUM                                MCAL_CORE_NUM

#define SPI_INIT_SID                                (uint8)0x00
#define SPI_DEINIT_SID                              (uint8)0x01
#define SPI_WRITEIB_SID                             (uint8)0x02
#define SPI_ASYNCTRANSMIT_SID                       (uint8)0x03
#define SPI_READIB_SID                              (uint8)0x04
#define SPI_SETUPEB_SID                             (uint8)0x05
#define SPI_GETSTATUS_SID                           (uint8)0x06
#define SPI_GETJOBRESULT_SID                        (uint8)0x07
#define SPI_GETSEQUENCERESULT_SID                   (uint8)0x08
#define SPI_GETVERSIONINFO_SID                      (uint8)0x09
#define SPI_SYNCTRANSMIT_SID                        (uint8)0x0A
#define SPI_GETHWUNITSTATUS_SID                     (uint8)0x0B
#define SPI_CANCEL_SID                              (uint8)0x0C
#define SPI_SETAYNCMODE_SID                         (uint8)0x0D
#define SPI_MAINFUNCTION_HANDLING_SID               (uint8)0x10

/* Development Errors */
/* API service called with wrong parameter */
#define SPI_E_PARAM_CHANNEL                         (uint8)0x0A
#define SPI_E_PARAM_JOB                             (uint8)0x0B
#define SPI_E_PARAM_SEQ                             (uint8)0x0C
#define SPI_E_PARAM_LENGTH                          (uint8)0x0D
#define SPI_E_PARAM_UNIT                            (uint8)0x0E

/* APIs called with a Null Pointer */
#define SPI_E_PARAM_POINTER                         (uint8)0x10
/* API service used without module initiali-zation */
#define SPI_E_UNINIT                                (uint8)0x1A
/* API SPI_Init service called while the SPI driver has already been initialized */
#define SPI_E_ALREADY_INITIALIZED                   (uint8)0x4A

#define SPI_E_PARAM_EB_UNIT                         (uint8)0x11

/* Runtime Errors */
/* Services called in a wrong sequence */
#define SPI_E_SEQ_PENDING                           (uint8)0x2A
/* Synchronous transmission service */
#define SPI_E_SEQ_IN_PROCESS                        (uint8)0x3A

/* [SWS_Spi_00004] SPI Handler/driver shall be able to detect the error SPI_E_PARAM_CHANNEL when API service called with wrong parame-ter.(SRS_BSW_00327, SRS_BSW_00337, SRS_BSW_00385) */
/* [SWS_Spi_00237] SPI Handler/driver shall be able to detect the error SPI_E_PARAM_JOB when API service called with wrong parameter.() */
/* [SWS_Spi_00238] SPI Handler/driver shall be able to detect the error SPI_E_PARAM_SEQ when API service called with wrong parameter.() */
/* [SWS_Spi_00240] SPI Handler/driver shall be able to detect the error SPI_E_PARAM_LENGTH when API service called with wrong parameter.() */
/* [SWS_Spi_00241] SPI Handler/driver shall be able to detect the error SPI_E_PARAM_UNIT when API service called with wrong parameter.() */
/* [SWS_Spi_00242] SPI Handler/driver shall be able to detect the error SPI_E_UNINIT when API service used without module initialization.() */
/* [SWS_Spi_00243] SPI Handler/driver shall be able to detect the error SPI_E_SEQ_PENDING when services called in a wrong sequence.() */
/* [SWS_Spi_00245] SPI Handler/driver shall be able to detect the error SPI_E_SEQ_IN_PROCESS when synchronous transmission service called at wrong time.() */
/* [SWS_Spi_00246] SPI Handler/driver shall be able to detect the error SPI_E_ALREADY_INITIALIZED when API SPI_Init service called while the SPI driv-er has already been initialized time.() */
/* [SWS_Spi_00195] SPI Handler/driver shall be able to detect the error SPI_E_HARDWARE_ERROR when an hardware error occur during asynchronous or synchronous transmit. Please see also SWS_Spi_00267 and SWS_Spi_00384.() */
#if (SPI_MULTI_CORE_SUPPORT == STD_ON)
#define Spi_GetCoreID                       GetCoreID
#endif

#define SPI_DATA_REVERSE(val)               ((uint32)((0xFFFF0000U & ((val) << 16U)) | (0x0000FFFFU & ((val) >> 16U))))

#define PCS0                                (uint8)0x01
#define PCS1                                (uint8)0x02
#define PCS2                                (uint8)0x04
#define PCS3                                (uint8)0x08
#define PCS4                                (uint8)0x10
#define PCS5                                (uint8)0x20
#define PCS6                                (uint8)0x40
#define PCS7                                (uint8)0x80

#define SPI_LEVEL_0                         0
#define SPI_LEVEL_1                         1
#define SPI_LEVEL_2                         2

#define SAMPLE                              0
#define DATACHANGE                          1

#define Spi_Configuration   Spi_Config
/*==================================================================================================
ENUM
==================================================================================================*/
typedef enum
{
    IB = 0U,         /* Internal Buffer */
    EB = 1U          /* External Buffer */
}Spi_ChannelBufferType;

typedef enum
{
    MSB = 0U,        /* Transmission starts with the Most Signifi-cant Bit first */
    LSB = 1U         /* Transmission starts with the Least Significant Bit first */
} Spi_ChannelTransferType;

typedef enum
{
    SPI_LEVEL_LOW = 0U,
    SPI_LEVEL_HIGH = 1U
} Spi_ShiftClockIdleLevel;

typedef enum
{
    #if SPI_EDGE_SELECT == SAMPLE
    LEADING = 0U,
    TRAILING = 1U
    #else
    LEADING = 1U,
    TRAILING = 0U
    #endif
} Spi_DataShiftEdge;


typedef enum
{
#ifdef RESOURCE_SUPPORT_DSPI_0
    DSPI0 = 0U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_1
    DSPI1 = 1U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_2
    DSPI2 = 2U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_3
    DSPI3 = 3U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_4
    DSPI4 = 4U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_5
    DSPI5 = 5U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_6
    DSPI6 = 6U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_7
    DSPI7 = 7U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_8
    DSPI8 = 8U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_9
    DSPI9 = 9U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_10
    DSPI10 = 10U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_11
    DSPI11 = 11U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_12
    DSPI12 = 12U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_13
    DSPI13 = 13U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_14
    DSPI14 = 14U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_15
    DSPI15 = 15U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_16
    DSPI16 = 16U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_17
    DSPI17 = 17U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_18
    DSPI18 = 18U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_19
    DSPI19 = 19U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_20
    DSPI20 = 20U,
#endif
#ifdef RESOURCE_SUPPORT_DSPI_21
    DSPI21 = 21U
#endif
} Spi_HwDSpiType;


/* [SWS_Spi_00373] */
/* This type defines a range of specific status for SPI Handler/Driver. */
typedef enum
{
    SPI_UNINIT = 0x00,      /* The SPI Handler/Driver is not initialized or not usable. */
    SPI_IDLE = 0x01,        /* The SPI Handler/Driver is not currently transmitting any Job. */
    SPI_BUSY = 0x02         /* The SPI Handler/Driver is performing a SPI Job (trans-mit). */
}Spi_StatusType;
/* [SWS_Spi_00061] The type Spi_StatusType defines a range of specific status for SPI Handler/Driver. It informs about the SPI Handler/Driver status or specified SPI Hardware microcontroller peripheral.(SRS_BSW_00335) */
/* [SWS_Spi_00259] The type Spi_StatusType can be obtained calling the API ser-vice Spi_GetStatus.() */
/* [SWS_Spi_00260] The type Spi_StatusType can be obtained calling the API ser-vice Spi_GetHWUnitStatus.() */
/* [SWS_Spi_00011] After reset, the type Spi_StatusType shall have the default value SPI_UNINIT.() */
/* [SWS_Spi_00345]  API service Spi_GetStatus shall return SPI_UNINIT when the SPI Handler/Driver is not initialized or not usable.() */
/* [SWS_Spi_00346] API service Spi_GetStatus shall return SPI_IDLE when The SPI Handler/Driver is not currently transmitting any Job.() */
/* [SWS_Spi_00347] API service Spi_GetStatus shall return SPI_BUSY when The SPI Handler/Driver is performing a SPI Job transmit.() */
/* [SWS_Spi_00348] Spi_GetHWUnitStatus function shall return SPI_IDLE when The SPI Hardware microcontroller peripheral is not currently transmitting any Job,() */
/* [SWS_Spi_00349] Spi_GetHWUnitStatus function shall return SPI_BUSYwhen The SPI Hardware microcontroller peripheral is performing a SPI Job transmit.() */


/* [SWS_Spi_00374] */
/* This type defines a range of specific Jobs status for SPI Handler/Driver. */
typedef enum
{
    SPI_JOB_OK = 0U,     /* The last transmission of the Job has been finished success-fully. */
    SPI_JOB_PENDING = 1U,    /* The SPI Handler/Driver is performing a SPI Job. The mean-ing of this status is equal to SPI_BUSY. */
    SPI_JOB_FAILED = 2U,     /* The last transmission of the Job has failed. */
    SPI_JOB_QUEUED = 3U      /* An asynchronous transmit Job has been accepted, while actual transmission for this Job has not started yet. */
}Spi_JobResultType;

/* [SWS_Spi_00062] The type Spi_JobResultType defines a range of specific Jobs status for SPI Handler/Driver.(SRS_BSW_00335) */
/* [SWS_Spi_00261] The type Spi_JobResultType it informs about a SPI Han-dler/Driver Job status and can be obtained calling the API service Spi_GetJobResult with the Job ID.() */
/* [SWS_Spi_00012] After reset, the type Spi_JobResultType shall have the de-fault value SPI_JOB_OK.() */
/* [SWS_Spi_00350] The function Spi_GetJobResult shall return SPI_JOB_OK when the last transmission of the Job has been finished successfully.() */

/* [SWS_Spi_00375] */
/* This type defines a range of specific Sequences status for SPI Handler/Driver. */
typedef enum
{
    SPI_SEQ_OK = 0U,      /* The last transmission of the Sequence has been finished successfully. */
    SPI_SEQ_PENDING = 1U,     /* The SPI Handler/Driver is performing a SPI Sequence. The meaning of this status is equal to SPI_BUSY. */
    SPI_SEQ_FAILED = 2U,      /* The last transmission of the Sequence has failed. */
    SPI_SEQ_CANCELED = 3U     /* The last transmission of the Sequence has been canceled by user. */
}Spi_SeqResultType;
/* [SWS_Spi_00351] The type Spi_SeqResultType defines a range of specific Se-quences status for SPI Handler/Driver and can be obtained calling the API service Spi_GetSequenceResult, it shall be provided for external use.() */
/* [SWS_Spi_00019] The type Spi_SeqResultType defines the range of specific Se-quences status for SPI Handler/Driver.(SRS_BSW_00335) */
/* [SWS_Spi_00251] The type Spi_SeqResultType defines about SPI Handler/Driver Sequence status and can be obtained calling the API service Spi_GetSequenceResult with the Sequence ID.() */
/* [SWS_Spi_00017] After reset, the type Spi_SeqResultType shall have the de-fault value SPI_SEQ_OK.() */
/* [SWS_Spi_00352] Spi_GetSequenceResult function shall return SPI_SEQ_OK when the last transmission of the Sequence has been finished successfully.() */
/* [SWS_Spi_00353] Spi_GetSequenceResult function shall return SPI_SEQ_PENDING when the SPI Handler/Driver is performing a SPI Sequence. The meaning of this status is equal to SPI_BUSY.() */
/* [SWS_Spi_00354] Spi_GetSequenceResult function shall return SPI_SEQ_FAILED when the last transmission of the Sequence has failed.() */

/* [SWS_Spi_00382] */
/* Specifies the asynchronous mechanism mode for SPI busses handled asynchro-nously in LEVEL 2. */
typedef enum
{
    SPI_POLLING_MODE = 0U,       /* The asynchronous mechanism is ensured by polling, so interrupts related to SPI busses handled asynchronously are disabled. */
    SPI_INTERRUPT_MODE = 1U          /* The asynchronous mechanism is ensured by interrupt, so interrupts related to SPI busses handled asynchronously are enabled. */
}Spi_AsyncModeType;
/* [SWS_Spi_00360] The type Spi_AsyncModeType specifies the asynchronous mechanism mode for SPI buses handled asynchronously in LEVEL 2 and obtained by the API Spi_SetAsyncMode.() */
/* [SWS_Spi_00170] The type Spi_AsyncModeType is used for specifying the asynchronous mechanism mode for SPI busses handled asynchronously in LEVEL 2.() */
/* [SWS_Spi_00150] The type Spi_AsyncModeType is made available or not de-pending on the pre-compile time parameter: SpiLevelDelivered. This is only rel-evant for LEVEL 2.() */
/* [SWS_Spi_00361] If API Spi_SetAsyncMode function is called by the parameter value SPI_POLLING_MODE then asynchronous mechanism is ensured by polling. So interrupts related to SPI buses handled asynchronously are disabled.() */
/* [SWS_Spi_00362] If API Spi_SetAsyncMode function is called by the parameter value SPI_INTERRUPT_MODE asynchronous mechanism is ensured by interrupt, so interrupts related to SPI buses handled asynchronously are enabled.() */

typedef enum{
    RW_B = 0U,  /* Read Write - Byte */
    RW_W = 1U,      /* Read Write - Word */
    RW_I = 2U,
    W_B = 3U,       /* Write - Byte */
    W_W = 4U,       /* Write - Word */
    W_I = 5U,
    R_B = 6U,       /* Read - Byte */
    R_W = 7U,       /* Read - Word */
    R_I = 8U
}TranFuncType;

/*==================================================================================================
TYPEDEDF
==================================================================================================*/

/*@brief typedef for job end notification function pointer*/
typedef P2FUNC( void, SPI_APPL_CODE, Spi_JobEndNotifyType )( void );

/*@brief typedef for sequence end notification function pointer*/
typedef P2FUNC( void, SPI_APPL_CODE, Spi_SeqEndNotifyType )( void );

/* [SWS_Spi_00376] */
/* Type of application data buffer elements. */
typedef uint8 Spi_DataBufferType;
/* [SWS_Spi_00355] Spi_DataBufferType defines the type of application data buffer elements. Type is uint8. Access to the data is selected dynamically as is described in SWS_SPI_00437. The data buffer has to be aligned to 32 bits. It shall be provided for external use.() */
/* [SWS_Spi_00164] The type Spi_DataBufferType refers to application data buffer elements.() */

/* [SWS_Spi_00377] */
/* Type for defining the number of data elements of the type Spi_DataBufferType to send and / or receive by Channel */
typedef uint16 Spi_NumberOfDataType;
/* [SWS_Spi_00165] The type Spi_NumberOfDataType is used for defining the number of data elements of the type specified in [SWS_SPI_00437] to send and / or receive by Channel.() */

/* [SWS_Spi_00378] */
/* Specifies the identification (ID) for a Channel. */
typedef uint8 Spi_ChannelType;
/* [SWS_Spi_00356] The type Spi_ChannelType specifies the identification (ID) for a Channel.() */
/* [SWS_Spi_00166] The type Spi_ChannelType is used for specifying the identi-fication (ID) for a Channel.() */

/* [SWS_Spi_00379] */
/* Specifies the identification (ID) for a Job. */
typedef uint16 Spi_JobType;
/* [SWS_Spi_00357] The type Spi_JobType specifies the identification (ID) for a Job.() */
/* [SWS_Spi_00167] The type Spi_JobType is used for specifying the identification (ID) for a Job.() */

/* [SWS_Spi_00380] */
/* Specifies the identification (ID) for a sequence of jobs. */
typedef uint8 Spi_SequenceType;
/* [SWS_Spi_00358] The type Spi_SequenceType specifies the identification (ID) for a sequence of jobs.() */
/* [SWS_Spi_00168] The type Spi_SequenceType is used for specifying the identi-fication (ID) for a sequence of jobs.() */

/* [SWS_Spi_00381] */
/* Specifies the identification (ID) for a SPI Hardware microcontroller peripheral (unit). */
typedef uint8 Spi_HWUnitType;
/* [SWS_Spi_00359] The type Spi_HWUnitType specifies the identification (ID) for a SPI Hardware microcontroller peripheral (unit).() */
/* [SWS_Spi_00169] The type Spi_HWUnitType is used for specifying the identifi-cation (ID) for a SPI Hardware microcontroller peripheral (unit).() */

typedef uint8 Spi_HWDeviceType;

/*==================================================================================================
STRUCT
==================================================================================================*/

typedef struct
{
    VAR(Spi_HWUnitType, SPI_VAR) HwDeviceIdx;
    VAR(Spi_HwDSpiType, SPI_CONST) HwDevice;
}Spi_HwUnitCfgType;

typedef struct
{
    VAR(uint8, SPI_VAR) HwIdx;
    VAR(Spi_HwDSpiType, SPI_CONST) HwDevice;
    #if (SPI_DMA_USED == STD_ON)
    VAR(uint8, SPI_VAR) Spi_TxDmaChannelID;
    VAR(uint8, SPI_VAR) Spi_RxDmaChannelID;
    #endif
}Spi_HwDeviceCfgType;


#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
typedef struct
{
    /*Buffer for data source */
    P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) WriteBuffer;
    /*Buffer for data destination */
    P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) ReadBuffer;
    /*Length of buffer */
    VAR(Spi_NumberOfDataType, SPI_VAR) Length;
    /*Buffer for data source (reverse) */
    P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) WriteBufferReverse;
} Spi_EBDataType;
#endif
typedef struct
{
    VAR(Spi_ChannelType, SPI_VAR) ChannelId;
    /*@brief Buffer usage with EB/IB Channel*/
    VAR(Spi_ChannelBufferType, SPI_VAR) ChannelBufferType;
    /*@brief Transmit data width (1 up to 32 bits)*/
    VAR(uint8, SPI_VAR) DataWidth;
    /*@brief Number of IB Channels or maximum size of EB Channels*/
    VAR(Spi_NumberOfDataType, SPI_VAR) BufferSize;
    #if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
    /*@brief pointer to channel internal write buffers*/
    P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) WriteBuffer;
    /*@brief pointer to channel internal Read buffers*/
    P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) ReadBuffer;
    #endif
    #if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
    /*@brief EB Config */
    P2VAR(Spi_EBDataType, SPI_VAR, SPI_APPL_DATA)EB_Buffer;
    #endif
    /*@brief Transfer start LSB or MSB*/
    VAR(Spi_ChannelTransferType, SPI_VAR) TransferType;
    /*@brief Default transmit value*/
    VAR(uint32, SPI_VAR) DefaultValue;
} Spi_ChannelCfgType;
/* [SWS_Spi_00063] For the type Spi_ConfigType, the definition for each Chan-nel shall contain:
 Buffer usage with EB/IB Channel
 Transmit data width (1 up to 32 bits)
 Number of data buffers for IB Channels (at least 1) or it is the maximum of da-ta for EB Channels (a value of 0 makes no sense)
 Transfer start LSB or MSB
 Default transmit value(SRS_Spi_12257, SRS_Spi_12025, SRS_Spi_12197, SRS_Spi_12024) */

typedef struct
{
    /*@brief Assigned Jobid*/
    VAR(uint8, SPI_VAR) JobId;
    /*@brief Assigned SPI HW Unit*/
    VAR(Spi_HWUnitType, SPI_VAR) HwUnit;
    VAR(uint8, SPI_VAR) HwDeviceIdx;
    VAR(Spi_HwDSpiType, SPI_CONST) HwDevice;
    /*@brief Assigned Chip Select pin*/
    VAR(uint8, SPI_VAR) CSPin;
    /*@brief Chip select functionality on/off*/
    VAR(boolean, SPI_VAR) CSFunc;
    /*@brief Chip select pin polarity high or low*/
    VAR(Spi_ShiftClockIdleLevel, SPI_VAR) CSPolarity;
    /* CSCountinue */
    VAR(uint16, SPI_VAR) CSCountinue;
    /*@brief Timing between clock and chip select*/
    VAR(uint8, SPI_VAR) TimeClkCs;
    /*@brief Shift clock idle low or idle high*/
    VAR(Spi_ShiftClockIdleLevel, SPI_VAR) ClockPolarity;
    /*@brief Data shift with leading or trailing edge*/
    VAR(Spi_DataShiftEdge, SPI_VAR) ClockShift;
    /* BaudRate */
    VAR(uint32, SPI_CONST) Ctar;
    /*@brief Priority (4 levels are available from 0, the lower to 3, the higher)*/
    VAR(uint8, SPI_VAR) SpiJobPriority;
    /*@brief Pointer to Job finish callback function*/
    VAR(Spi_JobEndNotifyType, SPI_VAR) JobEndNotification;
    /*@brief number if channels in the Job */
    VAR(uint8, SPI_VAR) NoOfChannels;
    /*@brief Link to channel list*/
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) ChannelList;
    #if (SPI_DMA_USED == STD_ON)
    VAR(boolean, SPI_VAR) JobDmaEn;
    #endif
} Spi_JobCfgType;
/* [SWS_Spi_00009] For the type Spi_ConfigType, the definition for each Job shall contain:
 Assigned SPI HW Unit
 Assigned Chip Select pin (it is possible to assign no pin)
 Chip select functionality on/off
 Chip select pin polarity high or low
 Baud rate
 Timing between clock and chip select
 Shift clock idle low or idle high
 Data shift with leading or trailing edge
 Priority (4 levels are available from 0, the lower to 3, the higher)
 Job finish end notification function
 MCU dependent properties for the Job (only if needed)
 Fixed link of Channels (at least one)(SRS_BSW_00344, SRS_SPAL_12056, SRS_SPAL_12125, SRS_Spi_12093, SRS_Spi_12094, SRS_Spi_12256, SRS_Spi_12257, SRS_Spi_12025, SRS_Spi_12179, SRS_Spi_12026, SRS_Spi_12259, SRS_Spi_12258, SRS_Spi_12260, SRS_Spi_12032, SRS_Spi_12033, SRS_Spi_12150) */

typedef struct
{
    VAR(Spi_SequenceType, SPI_VAR) SequenceId;
    /*@brief Interruptable or not interruptable after each Job*/
    VAR(boolean, SPI_VAR) InterruptableSequence;
    /*@brief Sequence finish end notification function*/
    VAR(Spi_SeqEndNotifyType, SPI_VAR) SequenceEndNotification;
    /*@brief Number of Jobs*/
    VAR(uint16, SPI_VAR) NoOfJobs;
    /*@brief Collection of Jobs*/
    P2CONST(Spi_JobType, SPI_VAR, SPI_APPL_CONST) JobList;
} Spi_SequenceCfgType;
/* [SWS_Spi_00064] For the type Spi_ConfigType, the definition for each Se-quence shall contain:
 Collection of Jobs (at least one)
 Interruptible or not interruptible after each Job
 Sequence finish end notification function(SRS_SPAL_12056, SRS_Spi_12179, SRS_Spi_12260, SRS_Spi_12199, SRS_Spi_12150) */



/* [SWS_Spi_00372] */
/* This type of the external data structure shall contain the initialization data for the SPI Handler/Driver. */
typedef struct Spi_Config
{
    VAR(Spi_SequenceType, SPI_VAR) SequenceNum;
    VAR(Spi_JobType, SPI_VAR) JobNum;
    VAR(Spi_ChannelType, SPI_VAR) ChannelNum;
    VAR(Spi_HWUnitType, SPI_VAR) HwUnitNum;
    VAR(Spi_HWDeviceType, SPI_VAR) HwDeviceNum;
    /*@brief Definition of Channels*/
    P2CONST(Spi_ChannelCfgType, SPI_VAR, SPI_APPL_CONST) ChannelConfiguration;
    /*@brief Definition of Jobs*/
    P2CONST(Spi_JobCfgType, SPI_VAR, SPI_APPL_CONST) JobConfiguration;
    /*@brief Definition of Sequences*/
    P2CONST(Spi_SequenceCfgType, SPI_VAR, SPI_APPL_CONST) SequenceConfiguration;

    P2CONST(Spi_HwUnitCfgType, SPI_VAR, SPI_APPL_CONST) HwConfiguration;

    P2CONST(Spi_HwDeviceCfgType, SPI_VAR, SPI_APPL_CONST) HwDeviceConfiguration;
    #if (SPI_MULTI_CORE_SUPPORT == STD_ON)
    P2CONST(uint8, SPI_VAR, SPI_APPL_CONST) DeviceMap;
    #endif
}Spi_ConfigType;
/* [SWS_Spi_00344] The description of the type Spi_ConfigType is implementation specific and it shall be provided for external use.() */

/* [SWS_Spi_00008] The type Spi_ConfigType is an external data structure and shall contain the initialization data for the SPI Handler/Driver. It shall contain:
 MCU dependent properties for SPI HW units
 Definition of Channels
 Definition of Jobs
 Definition of Sequences(SRS_BSW_00405, SRS_SPAL_12125, SRS_Spi_12256, SRS_Spi_12257, SRS_Spi_12025, SRS_Spi_12024) */
/* [SWS_Spi_00010] For the type Spi_ConfigType, the configuration will map the Jobs to the different SPI hardware units and the devices.(SRS_Spi_12093, SRS_Spi_12257) */

typedef struct Spi_AsyncSche{
    VAR(Spi_SequenceType, SPI_VAR)SequenceId;
    VAR(Spi_JobType, SPI_VAR)Current_Job;
    P2VAR(struct Spi_AsyncSche, SPI_VAR, SPI_APPL_DATA)Next_Sequence;
}Spi_AsyncScheType;

typedef struct{
    VAR(Spi_HwDSpiType, SPI_VAR)          HwDevice;
    VAR(uint32, SPI_VAR)                  Ctar;
    VAR(uint16, SPI_VAR)                  PushCmd;
    VAR(uint8, SPI_VAR)                   FrameSize;
    VAR(uint8, SPI_VAR)                   Pcs_Idle;
    VAR(uint8, SPI_VAR)                   LastChannel;
    P2VAR(uint8, SPI_VAR, SPI_APPL_DATA)  Spi_TranBufPtr;
    P2VAR(uint8, SPI_VAR, SPI_APPL_DATA)  Spi_RecBufPtr;
    VAR(uint32, SPI_VAR)                  Spi_DataLength;
    VAR(uint32, SPI_VAR)                  TranDefaultData;
    #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
    P2VAR(Spi_AsyncScheType, SPI_VAR, SPI_APPL_DATA) Spi_AsyncSchePtr;
    P2VAR(Spi_AsyncScheType, SPI_VAR, SPI_APPL_DATA) Spi_AsyncAssSchePtr;
    VAR(uint32, SPI_VAR)                  CurrentChannel;

    VAR(uint32, SPI_VAR)                  Spi_RxCnt;
    VAR(uint32, SPI_VAR)                  Spi_TxCnt;
    VAR(uint8, SPI_VAR)                   Spi_FifoTxCnt;
    VAR(TranFuncType, SPI_VAR)            Spi_TranFuncType;

    #if (SPI_DMA_USED == STD_ON)
    VAR(uint8, SPI_VAR)                   Spi_DmaEnable;
    VAR(uint8, SPI_VAR)                   Spi_TxDmaChannelID;
    VAR(uint8, SPI_VAR)                   Spi_RxDmaChannelID;
    #endif
    #endif
}Spi_HandleType;


/*==================================================================================================
VAR INIT
==================================================================================================*/

#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
extern P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_gConfigPtr;
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
extern VAR(Spi_AsyncModeType, SPI_VAR) Spi_gAsyncMode;
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
extern VAR(Spi_HandleType, SPI_VAR) Spi_gHandle[SPI_TOTAL_HWDEVICE];
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE)Spi_AsyncSchedulerMain( P2VAR(Spi_HandleType, SPI_VAR, SPI_APPL_DATA) Spi_HandlePtr );
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE) Spi_Init(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB(
    VAR(Spi_ChannelType, AUTOMATIC) Channel,
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_CONST) DataBufferPtr);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB(
    VAR(Spi_ChannelType, AUTOMATIC) Channel,
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB(
    VAR(Spi_ChannelType, AUTOMATIC) Channel,
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_CONST) SrcDataBufferPtr,
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
    VAR(Spi_NumberOfDataType, AUTOMATIC) Length);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult(VAR(Spi_JobType, AUTOMATIC) Job );
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE) Spi_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) versioninfo);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if (SPI_HW_STATUS_API == STD_ON)
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(VAR(Spi_HWUnitType, AUTOMATIC) HwUnit);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if (SPI_CANCEL_API == STD_ON)
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE) Spi_Cancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(VAR(Spi_AsyncModeType, AUTOMATIC) Mode);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC (void, SPI_CODE) Spi_MainFunction_Handling(void);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

extern CONST(Spi_ConfigType, SPI_CONST) Spi_Config;

#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SPI_H */
