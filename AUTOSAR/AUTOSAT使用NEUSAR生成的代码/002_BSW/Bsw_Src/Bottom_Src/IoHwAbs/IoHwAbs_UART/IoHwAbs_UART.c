#include "linflexd_uart_lld.h"
#include "CCFC3012PT_features.h"
#include "CCFC3012PT.h"
#include "eDma_LLDriver.h"

static linflexd_uart_state_t linflexd_uart1_state;
static linflexd_uart_state_t linflexd_uart3_state;
static linflexd_uart_user_config_t linflexd_uart1_initconfig = {
  .transferType = LINFLEXD_UART_USING_DMA,
  .baudRate = 2000000,
  .parityCheck = FALSE,
  .parityType = LINFLEXD_UART_PARITY_EVEN,
  .stopBitsCount = LINFLEXD_UART_ONE_STOP_BIT,
  .wordLength = LINFLEXD_UART_8_BITS,
  .rxDMAChannel = 0U,
  .txDMAChannel = 0U,
};

static linflexd_uart_user_config_t linflexd_uart3_initconfig = {
  .transferType = LINFLEXD_UART_USING_DMA,
  .baudRate = 2000000,
  .parityCheck = FALSE,
  .parityType = LINFLEXD_UART_PARITY_EVEN,
  .stopBitsCount = LINFLEXD_UART_ONE_STOP_BIT,
  .wordLength = LINFLEXD_UART_8_BITS,
  .rxDMAChannel = 0U,
  .txDMAChannel = 0U,
};

/**
 * @brief  使能DMA
 * @param  instance: UART实例
 * @param  uartUserConfig: 用户DMA配置配置
 */
static void LINFLEXD_UART_ConfigDMA_Init(uint32 instance, linflexd_uart_user_config_t * uartUserConfig)
{
    const UartEdmaConfig gUart_Edma_Config_All[LINFLEXD_MAX] = LINFLEXD_EDMA_CONFIG;/* PRQA S 3604 */

    uartUserConfig->rxDMAChannel = (uint8_t)gUart_Edma_Config_All[instance].uart_edma_rx.edma_ch;
    uartUserConfig->txDMAChannel = (uint8_t)gUart_Edma_Config_All[instance].uart_edma_tx.edma_ch;

    (void)EDMA_LLD_SetChannelSourceConfig(gUart_Edma_Config_All[instance].uart_edma_rx.edma_ch,
                                          (uint32_t)gUart_Edma_Config_All[instance].uart_edma_rx.edma_mux,
                                          FALSE);

    (void)EDMA_LLD_SetChannelSourceConfig(gUart_Edma_Config_All[instance].uart_edma_tx.edma_ch,
                                          (uint32_t)gUart_Edma_Config_All[instance].uart_edma_tx.edma_mux,
                                          FALSE);
}

/**
 * @brief  串口模块初始化
 */
void IoHwAbs_UART_Init(void)
{
    LINFLEXD_UART_ConfigDMA_Init(INST_LINFLEXD_UART1, &linflexd_uart1_initconfig);
    LINFLEXD_UART_LLD_Init(INST_LINFLEXD_UART1, &linflexd_uart1_state, &linflexd_uart1_initconfig);

    LINFLEXD_UART_ConfigDMA_Init(INST_LINFLEXD_UART3, &linflexd_uart3_initconfig);
    LINFLEXD_UART_LLD_Init(INST_LINFLEXD_UART3, &linflexd_uart3_state, &linflexd_uart3_initconfig);
}

extern void LINFLEXD_UART_LLD_CompleteSendUsingDma(void * parameter, eDMAChnStatusType status);
extern void LINFLEXD_UART_LLD_CompleteReceiveUsingDma(void * parameter, eDMAChnStatusType status);
/**
 * @brief  等待接收空闲 → 启动指定长度接收 → 发送指定长度数据
 * @param  instance：UART实例
 * @param  pTxData: 发送数据缓冲区
 * @param  txLen：发送长度
 * @param  pRxData：接收数据缓冲区
 * @param  rxLen：接收长度
 */
uint8 TLE9018_UART_TransmitReceive(uint32 index, uint8 *pTxData, uint32 txLen,
        uint8 *pRxData, uint32 rxLen)
{
    uint32 instance;
    uint32 timeout = 4200U;

    if (index != 0U && index != 1U) {
        return 1;
    }

    if ((txLen > 0U && pTxData == NULL) || txLen == 0U) {
        return 2;
    }

    if ((rxLen > 0U && pRxData == NULL) || rxLen == 0U) {
        return 3;
    }

    if(0 == index) {
        instance = INST_LINFLEXD_UART1;
    } else if(1 == index) {
        instance = INST_LINFLEXD_UART3;
    }

    LINFLEXD_UART_LLD_CompleteSendUsingDma((void*)instance, EDMA_CHN_STATUS_NORMAL);
    LINFLEXD_UART_LLD_CompleteReceiveUsingDma((void*)instance, EDMA_CHN_STATUS_NORMAL);

    (void)LINFLEXD_UART_LLD_ReceiveData(instance, pRxData, rxLen);
    LINFLEXD_UART_LLD_SendData(instance, pTxData, txLen);
    if(0 == index) {
        while((!eDMA_0.TCD[48].CSR.B.DONE) && (timeout > 0)) {
            timeout--;
        }
    } else if(1 == index) {
        while((!eDMA_1.TCD[35].CSR.B.DONE) && (timeout > 0)) {
            timeout--;
        }  
    }

    if(0 == timeout) {
        return 4;
    }

    return 0;
}

uint8 TLE9018_UART_TransmitAndDualReceive(
    uint32 index,
    uint8 *pTxData,
    uint32 txLen,
    uint8 *pRxData1,
    uint8 *pRxData3,
    uint32 rxLen)
{
    uint32 instance;
    uint32 timeout = 4300U;

    if (index != 0U && index != 1U) {
        return 1;
    }

    if ((txLen > 0U && pTxData == NULL) || txLen == 0U) {
        return 2;
    }

    if ((rxLen > 0U && pRxData1 == NULL) ||\
        (rxLen > 0U && pRxData3 == NULL) ||\
        rxLen == 0U) {
        return 3;
    }

    if(0 == index) {
        instance = INST_LINFLEXD_UART1;
    } else if(1 == index) {
        instance = INST_LINFLEXD_UART3;
    }

    LINFLEXD_UART_LLD_CompleteSendUsingDma((void*)INST_LINFLEXD_UART1, EDMA_CHN_STATUS_NORMAL);
    LINFLEXD_UART_LLD_CompleteReceiveUsingDma((void*)INST_LINFLEXD_UART1, EDMA_CHN_STATUS_NORMAL);
    LINFLEXD_UART_LLD_CompleteSendUsingDma((void*)INST_LINFLEXD_UART3, EDMA_CHN_STATUS_NORMAL);
    LINFLEXD_UART_LLD_CompleteReceiveUsingDma((void*)INST_LINFLEXD_UART3, EDMA_CHN_STATUS_NORMAL);

    (void)LINFLEXD_UART_LLD_ReceiveData(INST_LINFLEXD_UART1, pRxData1, rxLen);
    (void)LINFLEXD_UART_LLD_ReceiveData(INST_LINFLEXD_UART3, pRxData3, rxLen);
    LINFLEXD_UART_LLD_SendData(instance, pTxData, txLen);

    while((!eDMA_0.TCD[48].CSR.B.DONE) && (!eDMA_1.TCD[35].CSR.B.DONE) && (timeout > 0)) {
        timeout--;
    }

    if(0 == timeout) {
        return 4;
    }

    return 0;
}
