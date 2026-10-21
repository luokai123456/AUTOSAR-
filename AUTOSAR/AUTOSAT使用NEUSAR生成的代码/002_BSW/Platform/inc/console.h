/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : console h file
* HISTORY     : Initial version
* @file     console.h
* @version  1.0
* @date     2023 - 05 - 06
* @brief    Initial version.
*
*****************************************************************************/

#ifndef COMMON_INC_CONSOLE_H_
#define COMMON_INC_CONSOLE_H_

#include <stdlib.h>
#include "derivative.h"


#ifndef DEMO_TEST
#define DEMO_TEST 0
#endif
/*PRQA S 3630, 0659 EOF*/

#define SWITCH_CORE_ENABLE      (1U)

#define UART_BAUDRATE           (115200U)

#ifndef DISABLE
#define DISABLE                 (0U)         /*Bit-Field Is Disabled */
#endif

#ifndef ENABLE
#define ENABLE                  (1U)         /*Bit-Field Is Enabled  */
#endif

#define UART_DISABLE_PARITY     (0U)
#define UART_ODD_PARITY         (1U)
#define UART_EVEN_PARITY        (2U)

struct Private_Param
{
    uint8_t tx_buf[4];
    uint8_t rx_buf[4];

    uint8_t tx_buflen;
    uint8_t rx_buflen;

    uint8_t tx_flag;
    uint8_t rx_flag;

    uint32_t tx_count;
    uint32_t rx_count;

    struct Lin_Device *std_uart;

};

struct Lin_Device
{
    volatile struct LINFlexD_tag *lin_num;
    struct Private_Param *param_num;
    uint8_t MSid;
};

void UART_INT_DIS(const struct Lin_Device *dev);
void UART_TX(const struct Lin_Device *dev, char data);
uint8_t UART_RX(const struct Lin_Device *dev, char *data);
void Std_Dev_Register(struct Lin_Device *lin_dev,volatile struct LINFlexD_tag *base,struct Private_Param *Paramx);
void LINFLEX_Start_Config(struct Lin_Device *dev);
void LINFLEX_Complete_Config(struct Lin_Device *dev);
void Uart_Send_Char(char s);
uint8_t Uart_Read_Char(char *s);
void Uart_SendStr(const char * s);

void HandleDebugCmd(uint8_t cmdChar);

extern void Console_Init(void);
extern void PSPRINTF(const char *fmt, ...);

#if DEMO_TEST
#define Uart_Printf         PSPRINTF
#else
#define Uart_Printf(...)
#endif

/*for multi-core uart*/
#define UART_MULTI_CORE_CONFIG 1
#define SPI_CONFIG 1


#endif /* COMMON_INC_CONSOLE_H_ */
