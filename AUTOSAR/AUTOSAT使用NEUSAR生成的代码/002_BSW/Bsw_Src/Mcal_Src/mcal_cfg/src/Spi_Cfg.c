#ifdef __cplusplus
extern "C"{
#endif

/*PRQA S 0380,0499 EOF*/
/*PRQA S 0704,4397,0686,1756,1758 EOF*/ /*QAC_CWE*/

#include "Spi.h"
#if(SPI_DMA_USED == STD_ON)
#include "eDma.h"
#endif

/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_CFG_C_VENDOR_ID                    176
#define SPI_CFG_C_AR_MAJOR_VER                 4
#define SPI_CFG_C_AR_MINOR_VER                 4
#define SPI_CFG_C_AR_PATCH_VER                 0
#define SPI_CFG_C_SW_MAJOR_VER                 3
#define SPI_CFG_C_SW_MINOR_VER                 0
#define SPI_CFG_C_SW_PATCH_VER                 0

/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
#if (SPI_CFG_C_VENDOR_ID != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : SPI_CFG_C_VENDOR_ID"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (SPI_CFG_C_AR_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_AR_MAJOR_VER"
#endif
#if (SPI_CFG_C_AR_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_AR_MINOR_VER"
#endif
#if (SPI_CFG_C_AR_PATCH_VER != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_AR_PATCH_VER"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (SPI_CFG_C_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_SW_MAJOR_VER"
#endif
#if (SPI_CFG_C_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_SW_MINOR_VER"
#endif
#if (SPI_CFG_C_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_SW_PATCH_VER"
#endif




#define SPI_START_SEC_VAR_INIT
#include "Spi_MemMap.h"
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_SBC_Sa47301 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
#define SPI_STOP_SEC_VAR_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_INIT
#include "Spi_MemMap.h"
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_HB_HE99MD = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
#define SPI_STOP_SEC_VAR_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_INIT
#include "Spi_MemMap.h"
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_IMU_QMI8A01Z = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
#define SPI_STOP_SEC_VAR_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_INIT
#include "Spi_MemMap.h"
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_CAN1_TPT1445 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
#define SPI_STOP_SEC_VAR_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_INIT
#include "Spi_MemMap.h"
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_CAN2_TPT1445 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
#define SPI_STOP_SEC_VAR_INIT
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_ChannelCfgType, SPI_CONST) SpiChannelConfiguration[SPI_TOTAL_CHANNEL] =
{
    {
        /* SpiChannel_SBC_Sa47301*/
        .ChannelId = 0,
        .ChannelBufferType = EB,
        .DataWidth = 16U,
        .BufferSize = 10U,
        .WriteBuffer = NULL_PTR,
        .ReadBuffer = NULL_PTR,
        .EB_Buffer = &EB_SpiChannel_SBC_Sa47301,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_HB_HE99MD*/
        .ChannelId = 1,
        .ChannelBufferType = EB,
        .DataWidth = 16U,
        .BufferSize = 16U,
        .WriteBuffer = NULL_PTR,
        .ReadBuffer = NULL_PTR,
        .EB_Buffer = &EB_SpiChannel_HB_HE99MD,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_IMU_QMI8A01Z*/
        .ChannelId = 2,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 13U,
        .WriteBuffer = NULL_PTR,
        .ReadBuffer = NULL_PTR,
        .EB_Buffer = &EB_SpiChannel_IMU_QMI8A01Z,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_CAN1_TPT1445*/
        .ChannelId = 3,
        .ChannelBufferType = EB,
        .DataWidth = 16U,
        .BufferSize = 29U,
        .WriteBuffer = NULL_PTR,
        .ReadBuffer = NULL_PTR,
        .EB_Buffer = &EB_SpiChannel_CAN1_TPT1445,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_CAN2_TPT1445*/
        .ChannelId = 4,
        .ChannelBufferType = EB,
        .DataWidth = 16U,
        .BufferSize = 29U,
        .WriteBuffer = NULL_PTR,
        .ReadBuffer = NULL_PTR,
        .EB_Buffer = &EB_SpiChannel_CAN2_TPT1445,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_SBC_SA47301_ChannelList[1] = 
{
    0U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_HB_HE99MD_ChannelList[1] = 
{
    1U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_IMU_QMI8A01Z_ChannelList[1] = 
{
    2U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_CAN1_TPT1445_ChannelList[1] = 
{
    3U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_CAN2_TPT1445_ChannelList[1] = 
{
    4U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"





#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_JobCfgType, SPI_CONST) SpiJobConfiguration[SPI_TOTAL_JOB] = 
{
    {
        .JobId = 0U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI1,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity =SPI_LEVEL_LOW ,
        .CSCountinue =0x8000U,
        .TimeClkCs = 0U,
        .ClockPolarity =SPI_LEVEL_LOW ,
        .ClockShift = TRAILING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 2 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2UL << 16U) 
            /* Scaler */    | (1UL << 0U)
            /* PCSSCK */    | (0UL << 22U)
            /* CSSCK */     | (0UL << 12U)
            /* PASC */      | (0UL << 20U)
            /* ASC */       | (0UL << 8U)
            /* PDT */       | (0UL << 18U)
            /* DT */        | (0UL << 4U) ),
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_SBC_SA47301_ChannelList,
    },
    {
        .JobId = 1U,
        .HwUnit = 1U, /* @index */
        .HwDeviceIdx = 1U,
        .HwDevice = DSPI4,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity =SPI_LEVEL_LOW ,
        .CSCountinue =0U,
        .TimeClkCs = 0U,
        .ClockPolarity =SPI_LEVEL_LOW ,
        .ClockShift = TRAILING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 64 */ /* ASC = 64 */ /* DT = 64 */ 
            /* Prescaler */   (2UL << 16U) 
            /* Scaler */    | (1UL << 0U)
            /* PCSSCK */    | (0UL << 22U)
            /* CSSCK */     | (5UL << 12U)
            /* PASC */      | (0UL << 20U)
            /* ASC */       | (5UL << 8U)
            /* PDT */       | (0UL << 18U)
            /* DT */        | (5UL << 4U) ),
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_HB_HE99MD_ChannelList,
    },
    {
        .JobId = 2U,
        .HwUnit = 2U, /* @index */
        .HwDeviceIdx = 2U,
        .HwDevice = DSPI2,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity =SPI_LEVEL_LOW ,
        .CSCountinue =0x8000U,
        .TimeClkCs = 0U,
        .ClockPolarity = SPI_LEVEL_HIGH,
        .ClockShift = TRAILING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 8 */ /* ASC = 8 */ /* DT = 256 */ 
            /* Prescaler */   (2UL << 16U) 
            /* Scaler */    | (1UL << 0U)
            /* PCSSCK */    | (0UL << 22U)
            /* CSSCK */     | (2UL << 12U)
            /* PASC */      | (0UL << 20U)
            /* ASC */       | (2UL << 8U)
            /* PDT */       | (0UL << 18U)
            /* DT */        | (7UL << 4U) ),
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_IMU_QMI8A01Z_ChannelList,
    },
    {
        .JobId = 3U,
        .HwUnit = 3U, /* @index */
        .HwDeviceIdx = 3U,
        .HwDevice = DSPI17,
        .CSPin = PCS4,
        .CSFunc = TRUE,
        .CSPolarity =SPI_LEVEL_LOW ,
        .CSCountinue =0U,
        .TimeClkCs = 0U,
        .ClockPolarity =SPI_LEVEL_LOW ,
        .ClockShift = TRAILING,
        .Ctar = (uint32)( /* Real Frequency 3571428 Hz */ /* CSC = 64 */ /* ASC = 64 */ /* DT = 64 */ 
            /* Prescaler */   (3UL << 16U) 
            /* Scaler */    | (1UL << 0U)
            /* PCSSCK */    | (0UL << 22U)
            /* CSSCK */     | (5UL << 12U)
            /* PASC */      | (0UL << 20U)
            /* ASC */       | (5UL << 8U)
            /* PDT */       | (0UL << 18U)
            /* DT */        | (5UL << 4U) ),
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_CAN1_TPT1445_ChannelList,
    },
    {
        .JobId = 4U,
        .HwUnit = 4U, /* @index */
        .HwDeviceIdx = 3U,
        .HwDevice = DSPI17,
        .CSPin = PCS5,
        .CSFunc = TRUE,
        .CSPolarity =SPI_LEVEL_LOW ,
        .CSCountinue =0U,
        .TimeClkCs = 0U,
        .ClockPolarity =SPI_LEVEL_LOW ,
        .ClockShift = TRAILING,
        .Ctar = (uint32)( /* Real Frequency 3571428 Hz */ /* CSC = 64 */ /* ASC = 64 */ /* DT = 64 */ 
            /* Prescaler */   (3UL << 16U) 
            /* Scaler */    | (1UL << 0U)
            /* PCSSCK */    | (0UL << 22U)
            /* CSSCK */     | (5UL << 12U)
            /* PASC */      | (0UL << 20U)
            /* ASC */       | (5UL << 8U)
            /* PDT */       | (0UL << 18U)
            /* DT */        | (5UL << 4U) ),
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_CAN2_TPT1445_ChannelList,
    },
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_JobType, SPI_CONST) SpiSequence_SBC_SA47301_JobList[1] = 
{
    0U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_JobType, SPI_CONST) SpiSequence_HB_HE99MD_JobList[1] = 
{
    1U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_JobType, SPI_CONST) SpiSequence_IMU_QMI8A01Z_JobList[1] = 
{
    2U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_JobType, SPI_CONST) SpiSequence_CAN1_TPT1445_JobList[1] = 
{
    3U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_JobType, SPI_CONST) SpiSequence_CAN2_TPT1445_JobList[1] = 
{
    4U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_SequenceCfgType, SPI_CONST) SpiSequenceConfiguration[SPI_TOTAL_SEQUENCE] =
{
    {
        /* SpiSequence_0 */
        .SequenceId = 0U,
        .InterruptableSequence = FALSE,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_SBC_SA47301_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_1 */
        .SequenceId = 1U,
        .InterruptableSequence = FALSE,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_HB_HE99MD_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_2 */
        .SequenceId = 2U,
        .InterruptableSequence = FALSE,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_IMU_QMI8A01Z_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_3 */
        .SequenceId = 3U,
        .InterruptableSequence = FALSE,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_CAN1_TPT1445_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_4 */
        .SequenceId = 4U,
        .InterruptableSequence = FALSE,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_CAN2_TPT1445_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_HwUnitCfgType, SPI_CONST) Spi_HwConfiguration[SPI_TOTAL_HWUNIT] = 
{
    {
        .HwDeviceIdx = 0,
        .HwDevice = DSPI1
    },
    {
        .HwDeviceIdx = 1,
        .HwDevice = DSPI4
    },
    {
        .HwDeviceIdx = 2,
        .HwDevice = DSPI2
    },
    {
        .HwDeviceIdx = 3,
        .HwDevice = DSPI17
    },
    {
        .HwDeviceIdx = 3,
        .HwDevice = DSPI17
    },
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"


#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
static CONST(Spi_HwDeviceCfgType, SPI_CONST) Spi_HwDeviceConfiguration[SPI_TOTAL_HWDEVICE] = 
{
    {
        .HwIdx = 0,
        .HwDevice = DSPI1,
    },
    {
        .HwIdx = 1,
        .HwDevice = DSPI4,
    },
    {
        .HwIdx = 2,
        .HwDevice = DSPI2,
    },
    {
        .HwIdx = 3,
        .HwDevice = DSPI17,
    },
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"


#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
CONST(Spi_ConfigType, SPI_CONST) Spi_Config = 
{
    .SequenceNum = 5U,
    .JobNum = 5U,
    .ChannelNum = 5U,
    .HwUnitNum = 5U,
    .HwDeviceNum = 4U,
    .ChannelConfiguration = SpiChannelConfiguration,
    .JobConfiguration = SpiJobConfiguration,
    .SequenceConfiguration = SpiSequenceConfiguration,
    .HwConfiguration = Spi_HwConfiguration,
    .HwDeviceConfiguration = Spi_HwDeviceConfiguration,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
CONST(uint32, SPI_CONST) Spi_HandleMap[22U] = 
{
    0U,
    0U,
    2U,
    0U,
    1U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    3U,
    0U,
    0U,
    0U,
    0U,
};
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
