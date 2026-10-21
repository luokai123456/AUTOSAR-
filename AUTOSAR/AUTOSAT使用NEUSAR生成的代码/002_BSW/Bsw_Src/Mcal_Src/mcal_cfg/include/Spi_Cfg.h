#ifndef SPI_CFG_H
#define SPI_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
INCLUDE
==================================================================================================*/
#include "Mcal.h"

/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_CFG_VENDOR_ID                    176
#define SPI_CFG_AR_MAJOR_VER                 4
#define SPI_CFG_AR_MINOR_VER                 4
#define SPI_CFG_AR_PATCH_VER                 0
#define SPI_CFG_SW_MAJOR_VER                 3
#define SPI_CFG_SW_MINOR_VER                 0
#define SPI_CFG_SW_PATCH_VER                 0

/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
#if (SPI_CFG_VENDOR_ID != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : SPI_CFG_VENDOR_ID"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (SPI_CFG_AR_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_AR_MAJOR_VER"
#endif
#if (SPI_CFG_AR_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_AR_MINOR_VER"
#endif
#if (SPI_CFG_AR_PATCH_VER != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_AR_PATCH_VER"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (SPI_CFG_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_SW_MAJOR_VER"
#endif
#if (SPI_CFG_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_SW_MINOR_VER"
#endif
#if (SPI_CFG_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_SW_PATCH_VER"
#endif

#define Spi_Configuration   Spi_Config
/*==================================================================================================
DEFINES
==================================================================================================*/

#define SPI_PRECOMPILE_SUPPORT              STD_OFF

#define SPI_DEV_ERROR_DETECT                STD_ON

#define SPI_MULTI_CORE_SUPPORT                  (STD_OFF)

/* Switches the development error detection and notification on or off. */
/* [SWS_Spi_00031] The API parameter Channel shall have a value within the defined channels in the initialization data structure,
 and the correct type of channel (IB or EB) has to be used with services. Related error value: SPI_E_PARAM_CHANNEL. Otherwise, 
 the service is not done and the return value shall be E_NOT_OK. (SRS_BSW_00323) */

#define SPI_VERSION_INFO_API                   STD_ON

#define SPI_HW_STATUS_API                      STD_ON

#define SPI_CANCEL_API                         STD_ON

#define SPI_CHANNEL_BUFFERS_ALLOWED            2U

#define SPI_LEVEL_DELIVERED                    SPI_LEVEL_2

#define SPI_MAIN_FUNCTION_PERIOD               (0.01)

#define SPI_INTERRUPTIBLE_SEQ_ALLOWED          (STD_OFF)

#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT   (STD_ON)

#define SPI_DMA_USED                           (STD_OFF)

#define SPI_INLINE                       LOCAL_INLINE


#define SPI_EDGE_SELECT                        (SAMPLE)

#define SPI_TOTAL_CHANNEL                      5U
#define SPI_TOTAL_JOB                          5U
#define SPI_TOTAL_SEQUENCE                     5U
#define SPI_TOTAL_HWUNIT                       5U
#define SPI_TOTAL_HWDEVICE                     4U



#define SpiChannel_SBC_Sa47301   ((Spi_ChannelType)0U)

#define SpiChannel_HB_HE99MD   ((Spi_ChannelType)1U)

#define SpiChannel_IMU_QMI8A01Z   ((Spi_ChannelType)2U)

#define SpiChannel_CAN1_TPT1445   ((Spi_ChannelType)3U)

#define SpiChannel_CAN2_TPT1445   ((Spi_ChannelType)4U)


#define SpiJob_SBC_SA47301   ((Spi_JobType)0U)

#define SpiJob_HB_HE99MD   ((Spi_JobType)1U)

#define SpiJob_IMU_QMI8A01Z   ((Spi_JobType)2U)

#define SpiJob_CAN1_TPT1445   ((Spi_JobType)3U)

#define SpiJob_CAN2_TPT1445   ((Spi_JobType)4U)


#define SpiSequence_SBC_SA47301   ((Spi_SequenceType)0U)

#define SpiSequence_HB_HE99MD   ((Spi_SequenceType)1U)

#define SpiSequence_IMU_QMI8A01Z   ((Spi_SequenceType)2U)

#define SpiSequence_CAN1_TPT1445   ((Spi_SequenceType)3U)

#define SpiSequence_CAN2_TPT1445   ((Spi_SequenceType)4U)



/**
* @brief Defines the maximum number of supported channels.
* @details Defines the maximum number of supported channels
*     for all the driver configurations.
*/
#define SpiConf_SpiChannel_SpiChannel_SBC_Sa47301    ((Spi_ChannelType)0)
#define SpiConf_SpiChannel_SpiChannel_HB_HE99MD    ((Spi_ChannelType)1)
#define SpiConf_SpiChannel_SpiChannel_IMU_QMI8A01Z    ((Spi_ChannelType)2)
#define SpiConf_SpiChannel_SpiChannel_CAN1_TPT1445    ((Spi_ChannelType)3)
#define SpiConf_SpiChannel_SpiChannel_CAN2_TPT1445    ((Spi_ChannelType)4)
#define SPI_MAX_CHANNEL  (5u)

/**
* @brief Total number of Jobs configured.
* @details Defines the maximum number of supported jobs
*     for all the driver configurations.
*/
#define SpiConf_SpiJob_SpiJob_SBC_SA47301   ((Spi_JobType)0)
#define SpiConf_SpiJob_SpiJob_HB_HE99MD   ((Spi_JobType)1)
#define SpiConf_SpiJob_SpiJob_IMU_QMI8A01Z   ((Spi_JobType)2)
#define SpiConf_SpiJob_SpiJob_CAN1_TPT1445   ((Spi_JobType)3)
#define SpiConf_SpiJob_SpiJob_CAN2_TPT1445   ((Spi_JobType)4)
#define SPI_MAX_JOB     (5u)

/**
* @brief Total number of Sequences configured.
* @details Defines the maximum number of supported sequences
*     for all the driver configurations.
*/
#define SpiConf_SpiSequence_SpiSequence_SBC_SA47301   ((Spi_SequenceType)0)
#define SpiConf_SpiSequence_SpiSequence_HB_HE99MD   ((Spi_SequenceType)1)
#define SpiConf_SpiSequence_SpiSequence_IMU_QMI8A01Z   ((Spi_SequenceType)2)
#define SpiConf_SpiSequence_SpiSequence_CAN1_TPT1445   ((Spi_SequenceType)3)
#define SpiConf_SpiSequence_SpiSequence_CAN2_TPT1445   ((Spi_SequenceType)4)
#define SPI_MAX_SEQUENCE  (5u)
    



#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
extern CONST(uint32, SPI_CONST) Spi_HandleMap[22U];
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif
