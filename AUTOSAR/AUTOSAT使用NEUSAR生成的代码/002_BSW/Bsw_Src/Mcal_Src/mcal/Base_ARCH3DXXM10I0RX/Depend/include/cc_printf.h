#ifndef CC_PRINTF_H_
#define CC_PRINTF_H_

#ifndef CC_PRINTF_ON
#define ADC_PRINTF(...)
#define CAN_PRINTF(...)
#define CANIF_PRINTF(...)
#define DEM_PRINTF(...)
#define DET_PRINTF(...)
#define DIO_PRINTF(...)
#define ECUC_PRINTF(...)
#define ECUM_PRINTF(...)
#define ETH_PRINTF(...)
#define ETHIF_PRINTF(...)
#define FEE_PRINTF(...)
#define FLS_PRINTF(...)
#define GPT_PRINTF(...)
#define ICU_PRINTF(...)
#define LIN_PRINTF(...)
#define LINIF_PRINTF(...)
#define MCU_PRINTF(...)
#define PORT_PRINTF(...)
#define PWM_PRINTF(...)
#define SPI_PRINTF(...)
#define WDG_PRINTF(...)
#else
#include "console.h"
#define ADC_PRINTF          PSPRINTF
#define CAN_PRINTF          PSPRINTF
#define CANIF_PRINTF        PSPRINTF
#define DEM_PRINTF          PSPRINTF
#define DET_PRINTF          PSPRINTF
#define DIO_PRINTF          PSPRINTF
#define ECUC_PRINTF         PSPRINTF
#define ECUM_PRINTF         PSPRINTF
#define ETH_PRINTF          PSPRINTF
#define ETHIF_PRINTF        PSPRINTF
#define FEE_PRINTF          PSPRINTF
#define FLS_PRINTF          PSPRINTF
#define GPT_PRINTF          PSPRINTF
#define ICU_PRINTF          PSPRINTF
#define LIN_PRINTF          PSPRINTF
#define LINIF_PRINTF        PSPRINTF
#define MCU_PRINTF          PSPRINTF
#define PORT_PRINTF         PSPRINTF
#define PWM_PRINTF          PSPRINTF
#define SPI_PRINTF          PSPRINTF
#define WDG_PRINTF          PSPRINTF
#endif  /* CC_PRINTF_ON */

#endif /* CC_PRINTF_H_ */
