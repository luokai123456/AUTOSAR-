#ifndef __EVPTCDD_HE99MD_CFG_H_
#define __EVPTCDD_HE99MD_CFG_H_

#include "StandardTypes.h"

#define SHIFT_1BIT(x,y)								(x << y)
#define SHIFT_2BIT(x,y)								(x << (2 * y))
#define CALC_DUTY(x)								(x / 100.0 * 256 - 1)

#define HBDRV_PARALLEL_MODE_SUPPORT					STD_OFF

#define HE99MD_CHIP_MAX								(1U)
#define HE99MD_CHIP_HB_NUM_MAX						(8U)
#define HE99MD_CHANNEL_NUM_MAX						(HE99MD_CHIP_MAX * HE99MD_CHIP_HB_NUM_MAX)
#define HE99MD_INIT_SEQUENCE_MAX					(9U)
#define HE99MD_CTRL_SEQUENCE_MAX					(15U)
#define HE99MD_DIAG_SEQUENCE_MAX					(5U)

#define HB_CFG_HE99MD_SPI_REG0b     				(0U)
#define HB_CFG_HE99MD_SPI_REG0c     				(1U)
#define HB_CFG_HE99MD_SPI_REG0d     				(2U)
#define HB_CFG_HE99MD_SPI_REG13     				(3U)
#define HB_CFG_HE99MD_SPI_REG14_OFFSET				(4U)
#define HB_CFG_HE99MD_SPI_REG14     				(4U)
#define HB_CFG_HE99MD_SPI_REG15     				(5U)
#define HB_CFG_HE99MD_SPI_REG08     				(13U)
#define HB_CFG_HE99MD_SPI_REG09_OFFSET				(4U)
#define HB_CFG_HE99MD_SPI_REG09     				(14U)
#define HB_CFG_HE99MD_DUTY_MASK     				(0xff00U)
#define HB_CFG_HE99MD_FREQ_FCT_MASK     			(0x03U)

/* return value */
#define HE99MD_RETVAL_OK							(0U)
#define HE99MD_RETVAL_ERR_INIT						(1U)
#define HE99MD_RETVAL_ERR_SET_PWM					(2U)
#define HE99MD_RETVAL_ERR_CHANNEL_OVER_RANGE		(3U)
#define HE99MD_RETVAL_ERR_CTRL_OVER_RANGE			(4U)

/* channel mapping */
#define HE99MD_CHANNEL0								(0U)
#define HE99MD_CHANNEL1								(1U)
#define HE99MD_CHANNEL2								(2U)
#define HE99MD_CHANNEL3								(3U)
#define HE99MD_CHANNEL4								(4U)
#define HE99MD_CHANNEL5								(5U)
#define HE99MD_CHANNEL6								(6U)
#define HE99MD_CHANNEL7								(7U)

// #define EXT_D_HS_CHANNEL_MAX						(2U)
#define EXT_D_HB_CHANNEL_MAX						(8U)


#define HE99MD_APP_DIRECT_CTRL_MAX					(2U)
#define HE99MD_HB_PWM_MODE_VALUE_MAX				(1U)
#define HE99MD_HB_FCT_VALUE_MAX						(2U)
#define HE99MD_HB_PWM_FREQ_VALUE_MAX				(3U)
#define HE99MD_HB_PWM_DUTY_VALUE_MAX				(100U)

#define HE99MD_RECOVER_REG_VAL                      (0x0725)

#endif /*__EVPTCDD_HE99MD_CFG_H_*/
