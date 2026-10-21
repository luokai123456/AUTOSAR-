#ifndef _CDD_SA47301_HAL_H_
#define _CDD_SA47301_HAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301_Type.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_HAL             4
#define SA47301_AR_REL_MINOR_VER_HAL             4
#define SA47301_AR_REL_REV_VER_HAL               0
#define SA47301_SW_MAJOR_VER_HAL                 1
#define SA47301_SW_MINOR_VER_HAL                 0
#define SA47301_SW_PATCH_VER_HAL                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_HAL != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_HAL"
#endif
#if (SA47301_AR_REL_MINOR_VER_HAL != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_HAL"
#endif
#if (SA47301_AR_REL_REV_VER_HAL != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_HAL"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_HAL != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_HAL"
#endif
#if (SA47301_SW_MINOR_VER_HAL != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_HAL"
#endif
#if (SA47301_SW_PATCH_VER_HAL != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_HAL"
#endif
void MCU_SPI_InitSa47301(void);
uint16 MCU_SPI_SendToSa47301(uint16 Data);
uint16 MCU_SPI_ReceiveSa47301(void);

void MCU_ADC_GetKeyVolt(uint16 *valKeyVolt_Lo,uint16 *valKey1Volt_Lo);
void MCU_ADC_GetAPlusVolt(uint16 *valAPlus1Volt_Lo,uint16 *valAPlus2Volt_Lo);
void MCU_ADC_GetAfeObcVolt(uint16 *valAFEVolt_Lo,uint16 *valOBCVolt_Lo);

#ifdef __cplusplus
}
#endif

#endif /* _CDD_SA47301_HAL_H_ */