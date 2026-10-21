#ifndef __IOHWABS_UART_H_
#define __IOHWABS_UART_H_

/****************************************************************
 * 模块：IO硬件抽象层 - UART驱动
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.0 (初始版本)
 *  1. 实现UART1/3基础初始化
 *  2. 支持DMA传输配置
 *  3. 基于Linflexd底层驱动封装
 * V0.2.0
 *  1. 修改TLE9018_UART_TransmitReceive函数，收发正常
 *  2. 修改为MSB
 * V0.3.0
 *  1. 串口接收修改为同步
 * ==================================================
 ****************************************************************/
#include "Std_Types.h"

#define UART_VER_MAJOR      0
#define UART_VER_MINOR      2
#define UART_VER_PATCH      0
#define UART_VERSION        ((uint32)UART_VER_MAJOR << 16 | \
                            (uint32)UART_VER_MINOR << 8  | \
                            UART_VER_PATCH)

extern void IoHwAbs_UART_Init(void);
extern uint8 TLE9018_UART_TransmitReceive(uint32 index, uint8 *pTxData, uint32 txLen,
        uint8 *pRxData, uint32 rxLen);
extern uint8 TLE9018_UART_TransmitAndDualReceive(
    uint32 index,
    uint8 *pTxData,
    uint32 txLen,
    uint8 *pRxData1,
    uint8 *pRxData3,
    uint32 rxLen);

#endif /* __IOHWABS_UART_H_ */
