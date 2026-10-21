#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301_Hal.h"
#include "IoHwAbs_Spi.h"
#include "IoHwAbs_Adc.h"
#include "IoHwAbs_ADC_Cfg.h"
#include "CCFC3011PT.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_HAL_C             4
#define SA47301_AR_REL_MINOR_VER_HAL_C             4
#define SA47301_AR_REL_REV_VER_HAL_C               0
#define SA47301_SW_MAJOR_VER_HAL_C                 1
#define SA47301_SW_MINOR_VER_HAL_C                 0
#define SA47301_SW_PATCH_VER_HAL_C                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_HAL_C != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_HAL_C"
#endif
#if (SA47301_AR_REL_MINOR_VER_HAL_C != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_HAL_C"
#endif
#if (SA47301_AR_REL_REV_VER_HAL_C != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_HAL_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_HAL_C != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_HAL_C"
#endif
#if (SA47301_SW_MINOR_VER_HAL_C != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_HAL_C"
#endif
#if (SA47301_SW_PATCH_VER_HAL_C != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_HAL_C"
#endif
extern Cdd_Sa47301SpiInfo_TDSTR SpiDataInfo;
uint16 ret_data = 0;


void MCU_SPI_InitSa47301(void)
{
    SpiDataInfo.TxFrame.FrameData = 0;
    SpiDataInfo.RxFrame.FrameData = 0;
    SpiDataInfo.SpiReceiveCallBack = MCU_SPI_ReceiveSa47301;
    SpiDataInfo.SpiSendCallBack = MCU_SPI_SendToSa47301;
}

uint16 MCU_SPI_SendToSa47301(uint16 Data)
{
    uint16 Status = 1U;

    IoHwAbs_Spi_SetupEB(EVPT_CDD_SPI_CHANNEL_SBC_SA47301_CH, &Data, &ret_data, 1);
    IoHwAbs_Spi_SyncTransmit(EVPT_CDD_SPI_SEQUENCE_SBC_SA47301_SEQ);

    return Status;
}


uint16 MCU_SPI_ReceiveSa47301(void)
{
    return ret_data;
}

void MCU_ADC_GetKeyVolt(uint16 *valKeyVolt_Lo,uint16 *valKey1Volt_Lo)
{
    IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_KEY_Mic, valKeyVolt_Lo);
    // IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_KEY1_Mic,&valKey1Volt_Lo);
}

void MCU_ADC_GetAPlusVolt(uint16 *valAPlus1Volt_Lo,uint16 *valAPlus2Volt_Lo)
{
    IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_DC_APlus1_Mic, valAPlus1Volt_Lo);
    IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_DC_APlus2_Mic, valAPlus2Volt_Lo);
}

void MCU_ADC_GetAfeObcVolt(uint16 *valAFEVolt_Lo,uint16 *valOBCVolt_Lo)
{
    IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_9015_ERRQ, valAFEVolt_Lo);
    IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_OBC_ON_Mic, valOBCVolt_Lo);
}

#ifdef __cplusplus
}
#endif
