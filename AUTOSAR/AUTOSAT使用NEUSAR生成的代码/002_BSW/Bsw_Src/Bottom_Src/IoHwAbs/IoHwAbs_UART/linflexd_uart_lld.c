/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx linflexed uart low level drivers code
* HISTORY     : Initial version
* @file     linflexed_uart_lld.c
* @version  1.0
* @date     2023 - 08 - 17
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 0491,0654,0779,1258,1503,1505,2844,3469,3604,4397,4404 EOF*/
#include "linflexd_uart_lld.h" /* PRQA S 0380 */
#include "derivative.h"
#include "eDma.h" /* PRQA S 0380 */
// #include "Mcu_LLDriver.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Array of pointers to UART driver runtime state structures */
static linflexd_uart_state_t * s_uartLINFlexDStatePtr[LINFLEXD_MAX] = {NULL};

/*! @brief Table storing DMA capabilities for LINFlexD instances. */
#if defined(FEATURE_LINFLEXD_HAS_DIFFERENT_MEM_MAP)
static const boolean *s_LINFlexDInstHasFilters = FEATURE_LINFLEXD_INST_HAS_IFCR;
#endif
/*! @brief Tables to save LINFlexD IRQ vectors defined in the header file */
static const IntrId *s_uartLINFlexDRxIntVec = LINFLEXD_RX_IRQS;
static const IntrId *s_uartLINFlexDTxIntVec = LINFLEXD_TX_IRQS;
static const IntrId *s_uartLINFlexDErrIntVec = LINFLEXD_ERR_IRQS;

/*******************************************************************************
 * Private Functions
 ******************************************************************************/
static void LINFLEXD_UART_LLD_CompleteSendUsingInterrupts(uint32_t instance);
static void LINFLEXD_UART_LLD_CompleteReceiveUsingInterrupts(uint32_t instance);
static status_t LINFLEXD_UART_LLD_StartSendUsingDma(uint32_t instance,
                                                   const uint8_t * txBuff,
                                                   uint32_t txSize);
static status_t LINFLEXD_UART_LLD_StartReceiveUsingDma(uint32_t instance,
                                                      uint8_t * rxBuff,
                                                      uint32_t rxSize);
static status_t LINFLEXD_UART_LLD_StartSendUsingInterrupts(uint32_t instance,
                                                          const uint8_t * txBuff,
                                                          uint32_t txSize);
static status_t LINFLEXD_UART_LLD_StartReceiveUsingInterrupts(uint32_t instance,
                                                             uint8_t * rxBuff,
                                                             uint32_t rxSize);
static void LINFLEXD_UART_LLD_PutData(uint32_t instance);
static void LINFLEXD_UART_LLD_GetData(uint32_t instance);
void LINFLEXD_UART_LLD_CompleteSendUsingDma(void * parameter, eDMAChnStatusType status);
void LINFLEXD_UART_LLD_CompleteReceiveUsingDma(void * parameter, eDMAChnStatusType status);
static void LINFLEXD_UART_LLD_FlushRxFifo(const volatile LINFlexD_Type *base, linflexd_uart_word_length_t wordLen);
extern void delay(volatile uint32_t x);
#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
 * Default interrupt handler - implemented in startup.s
 ******************************************************************************/
/*! @brief Default ISR. */
void DefaultISR(void)
{

}
/*FUNCTION**********************************************************************
 *
 * Function Name : OSIF_SemaCreate
 * Description   : This function creates (initializes) a semaphore.
 *
 * Implements : OSIF_SemaCreate_baremetal_Activity
 *END**************************************************************************/
static status_t OSIF_SemaCreate(semaphore_t * const pSem,
                         const uint8_t initValue)
{
    DEV_ASSERT(pSem != NULL);
    INTC_LLD_Set_Global_Disable();
    *pSem = initValue;
    INTC_LLD_Set_Global_Enable();

    return STATUS_SUCCESS;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : OSIF_SemaPost
 * Description   : This function performs the 'post' (increment) operation on a semaphore.
 *
 * Implements : OSIF_SemaPost_baremetal_Activity
 *END**************************************************************************/
static status_t OSIF_SemaPost(semaphore_t * const pSem)
{
    DEV_ASSERT(pSem != NULL);

    status_t osif_ret_code = STATUS_SUCCESS;
    INTC_LLD_Set_Global_Disable();
    if (*pSem != 255u)
    {
        (*pSem) += 1U;
    }
    else
    {
        osif_ret_code = STATUS_ERROR;
    }

    INTC_LLD_Set_Global_Enable();

    return osif_ret_code;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : OSIF_SemaWait
 * Description   : This function performs the 'wait' (decrement) operation on a semaphore.
 *      When timeout value is 0, it's the equivalent of TryWait - try to decrement but return
 *      immediately if it fails (counter is 0).
 *
 * Implements : OSIF_SemaWait_baremetal_Activity
 *END**************************************************************************/
static status_t OSIF_SemaWait(semaphore_t * const pSem,
                       const uint32_t timeout)
{
    DEV_ASSERT(pSem != NULL);

    status_t osif_ret_code = STATUS_SUCCESS;

    (void)delay(timeout);

    if (osif_ret_code == STATUS_SUCCESS) /* PRQA S 2991,2995 */
    {
        INTC_LLD_Set_Global_Disable();
        (*pSem) -= 1U;
        INTC_LLD_Set_Global_Enable();
    }

    return osif_ret_code;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : OSIF_SemaDestroy
 * Description   : This function destroys a semaphore object (mock operation in baremetal case).
 *
 * Implements : OSIF_SemaDestroy_baremetal_Activity
 *END**************************************************************************/
static status_t OSIF_SemaDestroy(const semaphore_t * const pSem)
{
    DEV_ASSERT(pSem != NULL);

    (void)pSem; /* PRQA S 3119 */

    return STATUS_SUCCESS;
}

/*******************************************************************************
 * LLD Code
 ******************************************************************************/
/*!
 * @brief Requests LINFlexD module to enter init mode.
 *
 * This function enters initialization mode.
 *
 * @param base LINFlexD base pointer.
 */
static inline void LINFLEXD_EnterInitMode(volatile LINFlexD_Type *base)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->LINCR1.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_LINCR1_SLEEP_MASK);
    regValTemp |= LINFlexD_LINCR1_INIT(1UL);
    base->LINCR1.R = regValTemp;
}

/*!
 * @brief Requests LINFlexD module to enter normal mode.
 *
 * This function enters normal mode. *
 *
 * @param base LINFlexD base pointer.
 */
static inline void LINFLEXD_EnterNormalMode(volatile LINFlexD_Type *base)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->LINCR1.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_LINCR1_SLEEP_MASK);
    regValTemp &= ~(LINFlexD_LINCR1_INIT_MASK);
    base->LINCR1.R = regValTemp;
}

/*!
 * @brief Sets the LINFlexD mode.
 *
 * This function sets LIN or UART mode, based on the parameter received.
 *
 * @param base LINFlexD base pointer.
 * @param mode LINFlexD mode - UART/LIN.
 */
static inline void LINFLEXD_SetMode(volatile LINFlexD_Type *base, linflexd_mode_t mode)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_UART_MASK);
    regValTemp |= LINFlexD_UARTCR_UART((uint32_t)mode); /* PRQA S 2985 */
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Returns the current LINFlexD state.
 *
 * This function returns the state of the LINFlexD instance. The possible states are:
 *    - Sleep mode
 *    - Init mode
 *    - Idle mode
 *    - Sync Break Reception/Transmission
 *    - Sync Delimiter Reception/Transmission
 *    - Sync Field Reception/Transmission
 *    - Identifier Field Reception/Transmission
 *    - Header Reception/Transmission
 *    - Data Reception/Transmission
 *    - Checksum Reception/Transmission
 *
 * @param base LINFlexD base pointer.
 * @return LINFlexD mode - UART/LIN.
 */
static inline linflexd_state_t LINFLEXD_GetLinState(const volatile LINFlexD_Type * base)
{
    uint8_t state = (uint8_t)((base->LINSR.R & LINFlexD_LINSR_LINS_MASK) >> LINFlexD_LINSR_LINS_SHIFT);/* polyspace RTE:NIV */
    return (linflexd_state_t)state; /* PRQA S 4342 */
}

/*!
 * @brief Sets the word length.
 *
 * This function sets the word length in UART mode.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param length UART mode word length.
 */
static inline void LINFLEXD_SetUartWordLength(volatile LINFlexD_Type *base, linflexd_uart_word_length_t length)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_WL0_MASK);
    regValTemp |= LINFlexD_UARTCR_WL0((uint32_t)length & 1U); /* PRQA S 2985 */
    regValTemp &= ~(LINFlexD_UARTCR_WL1_MASK);
    regValTemp |= LINFlexD_UARTCR_WL1(((uint32_t)length >> 1U) & 1U); /* PRQA S 2985 */
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Enables/disables parity bit.
 *
 * This function enables or disables the parity bit from UART bytes.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param enable TRUE - enable parity queuing/checking, FALSE - disable parity queuing/checking.
 */
static inline void LINFLEXD_SetParityControl(volatile LINFlexD_Type *base, boolean enable)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_PCE_MASK);
    regValTemp |= (uint32_t)LINFlexD_UARTCR_PCE((enable == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Sets parity type.
 *
 * This function sets the type of parity to be used for UART bytes. Available options are:
 *    - odd
 *    - even
 *    - always 0
 *    - always 1
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param parityType the type of parity.
 */
static inline void LINFLEXD_SetParityType(volatile LINFlexD_Type *base, linflexd_uart_parity_type_t parityType)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_PC0_MASK);
    regValTemp |= LINFlexD_UARTCR_PC0((uint32_t)parityType & 1U); /* PRQA S 2985 */
    regValTemp &= ~(LINFlexD_UARTCR_PC1_MASK);
    regValTemp |= LINFlexD_UARTCR_PC1(((uint32_t)parityType >> 1U) & 1U); /* PRQA S 2985 */
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Enables/disables transmitter.
 *
 * This function enables or disables the UART transmitter, based on the parameter received.
 * Should be called only when the module is in UART mode.
 *
 * @param base LINFlexD base pointer.
 * @param enable enable/disable transmitter.
 */
static inline void LINFLEXD_SetTransmitterState(volatile LINFlexD_Type *base, boolean enable)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_TxEn_MASK);
    regValTemp |= LINFlexD_UARTCR_TxEn((enable == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Enables/disables receiver.
 *
 * This function enables or disables the UART receiver, based on the parameter received.
 * Should be called only when the module is in UART mode.
 *
 * @param base LINFlexD base pointer.
 * @param enable enable/disable receiver.
 */
static inline void LINFLEXD_SetReceiverState(volatile LINFlexD_Type *base, boolean enable)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_RxEn_MASK);
    regValTemp |= LINFlexD_UARTCR_RxEn((enable == TRUE) ? 1UL : 0UL); /* PRQA S 2985 */
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Sets the transmission mode (FIFO/Buffer).
 *
 * This function sets the transmission mode (FIFO/Buffer).
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param mode tx mode: FIFO/Buffer.
 */
static inline void LINFLEXD_SetTxMode(volatile LINFlexD_Type *base, linflexd_uart_rxtx_mode_t mode)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_TFBM_MASK);
    regValTemp |= LINFlexD_UARTCR_TFBM((uint32_t)mode);
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Sets the reception mode (FIFO/Buffer).
 *
 * This function sets the reception mode (FIFO/Buffer).
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param mode rx mode: FIFO/Buffer.
 */
static inline void LINFLEXD_SetRxMode(volatile LINFlexD_Type *base, linflexd_uart_rxtx_mode_t mode)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_RFBM_MASK);
    regValTemp |= LINFlexD_UARTCR_RFBM((uint32_t)mode);
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Sets the reception data field length/FIFO depth.
 *
 * This function sets either the reception data field length or the number of bytes in the Rx FIFO, according to
 * the current reception mode.
 *
 * @param base LINFlexD base pointer.
 * @param length data field length/FIFO depth.
 */
static inline void LINFLEXD_SetRxDataFieldLength(volatile LINFlexD_Type *base, uint8_t length)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_RDFL_RFC_MASK);
    regValTemp |= LINFlexD_UARTCR_RDFL_RFC(length);
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Sets the transmission data field length/FIFO depth.
 *
 * This function sets either the transmission data field length or the number of bytes in the Tx FIFO, according to
 * the current transmission mode.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param length data field length/FIFO depth.
 */
static inline void LINFLEXD_SetTxDataFieldLength(volatile LINFlexD_Type *base, uint8_t length)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_TDFL_TFC_MASK);
    regValTemp |= LINFlexD_UARTCR_TDFL_TFC(length);
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Sets the number of stop bits for Rx.
 *
 * This function sets the number of stop bits for received bytes.
 *
 * @param base LINFlexD base pointer.
 * @param stopBitsCount number of stop bits.
 */
static inline void LINFLEXD_SetRxStopBitsCount(volatile LINFlexD_Type *base, linflexd_uart_stop_bits_count_t stopBitsCount)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->UARTCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_UARTCR_SBUR_MASK);
    regValTemp |= LINFlexD_UARTCR_SBUR(stopBitsCount);
    base->UARTCR.R = regValTemp;
}

/*!
 * @brief Sets fractional baud rate.
 *
 * This function configures the bits that decide the fractional part of the LIN Baud Rate.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param fbr fractional baud rate.
 */
static inline void LINFLEXD_SetFractionalBaudRate(volatile LINFlexD_Type *base, uint8_t fbr)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->LINFBRR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_LINFBRR_FBR_MASK);
    regValTemp |= LINFlexD_LINFBRR_FBR(fbr); /* PRQA S 2985 */
    base->LINFBRR.R = regValTemp;
}

/*!
 * @brief Gets fractional baud rate.
 *
 * This function returns the bits that decide the fractional part of the LIN Baud Rate.
 *
 * @param base LINFlexD base pointer.
 * @return fractional baud rate.
 */
static inline uint8_t LINFLEXD_GetFractionalBaudRate(const volatile LINFlexD_Type * base)
{
    return (uint8_t)((base->LINFBRR.B.FBR & LINFlexD_LINFBRR_FBR_MASK) >> LINFlexD_LINFBRR_FBR_SHIFT);/* polyspace RTE:NIV */
}

/*!
 * @brief Sets integer baud rate.
 *
 * This function configures the bits that decide the integer part of the LIN Baud Rate.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param fbr integer baud rate.
 */
static inline void LINFLEXD_SetIntegerBaudRate(volatile LINFlexD_Type *base, uint32_t ibr)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->LINIBRR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_LINIBRR_IBR_MASK);
    regValTemp |= LINFlexD_LINIBRR_IBR(ibr); /* PRQA S 2985 */
    base->LINIBRR.R = regValTemp;
}

/*!
 * @brief Gets integer baud rate.
 *
 * This function returns the bits that decide the integer part of the LIN Baud Rate.
 *
 * @param base LINFlexD base pointer.
 * @return integer baud rate.
 */
static inline uint32_t LINFLEXD_GetIntegerBaudRate(const volatile LINFlexD_Type * base)
{
    return (uint32_t)((base->LINIBRR.B.IBR & LINFlexD_LINIBRR_IBR_MASK) >> LINFlexD_LINIBRR_IBR_SHIFT);/* polyspace RTE:NIV */
}

/*!
 * @brief Sets the number of stop bits for Tx.
 *
 * This function sets the number of stop bits for transmitted bytes.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param defaultOffset - TRUE - use the memory map defined in the header file to access the register;
 *                      - FALSE - use custom memory map to access the register.
 * @param stopBitsCount number of stop bits.
 */
static inline void LINFLEXD_SetTxStopBitsCount(volatile LINFlexD_Type *base, linflexd_uart_stop_bits_count_t stopBitsCount,
                                               boolean defaultOffset)
{
    uint32_t regValTemp = 0U;

#if defined(FEATURE_LINFLEXD_HAS_DIFFERENT_MEM_MAP)
    if (!defaultOffset)
    {
        regValTemp = ((LINFlexD_0IFCR_Type *)base)->GCR;
        regValTemp &= ~(LINFlexD_GCR_STOP_MASK);
        regValTemp |= LINFlexD_GCR_STOP(stopBitsCount);
        ((LINFlexD_0IFCR_Type *)base)->GCR = regValTemp;
    }
    else
    {
        regValTemp = base->GCR;
        regValTemp &= ~(LINFlexD_GCR_STOP_MASK);
        regValTemp |= LINFlexD_GCR_STOP(stopBitsCount);
        base->GCR = regValTemp;
    }
#else
    (void)defaultOffset;
    regValTemp = base->GCR.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_GCR_STOP_MASK);
    regValTemp |= LINFlexD_GCR_STOP(stopBitsCount);
    base->GCR.R = regValTemp;
#endif
}

/*!
 * @brief Clears an UART interrupt flag.
 *
 * This function clears the UART status flag received as parameter.
 *
 * @param base LINFlexD base pointer.
 * @param flag UART status flag.
 */
static inline void LINFLEXD_ClearStatusFlag(volatile LINFlexD_Type * base, linflexd_uart_status_flag_t flag)
{
    base->UARTSR.R = (uint32_t)flag;/* polyspace RTE:NIV */
}

/*!
 * @brief Returns an UART interrupt flag.
 *
 * This function returns the value of the UART status flag received as parameter.
 *
 * @param base LINFlexD base pointer.
 * @return TRUE - UART status flag set, FALSE - UART status flag reset.
 */
static inline boolean LINFLEXD_GetStatusFlag(const volatile LINFlexD_Type * base, linflexd_uart_status_flag_t flag)
{
    if (((uint32_t)(base->UARTSR.R) & (uint32_t)flag) != 0U)/* polyspace RTE:NIV */
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*!
 * @brief Enables/disables an UART interrupt.
 *
 * This function configures whether the UART event will trigger an interrupt.
 *
 * @param base LINFlexD base pointer.
 * @param intSrc UART interrupt source.
 * @param enable TRUE - enable interrupt, FALSE - disable interrupt.
 */
static inline void LINFLEXD_SetInterruptMode(volatile LINFlexD_Type * base, linflexd_interrupt_t intSrc, boolean enable)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->LINIER.R;/* polyspace RTE:NIV */
    if (enable == TRUE)
    {
        regValTemp |= (uint32_t)intSrc;
    }
    else
    {
        regValTemp &= ~(uint32_t)intSrc;
    }
    base->LINIER.R = regValTemp;
}

#if defined (FEATURE_LINFLEXD_ORED_INT_LINES)
/*!
 * @brief Returns the state of an UART interrupt.
 *
 * This function returns whether the UART event will trigger an interrupt.
 *
 * @param base LINFlexD base pointer.
 * @param intSrc UART interrupt source.
 * @return TRUE - interrupt enabled, FALSE - interrupt disabled.
 */
static inline bool LINFLEXD_IsInterruptEnabled(volatile LINFlexD_Type * base, linflexd_interrupt_t intSrc)
{
    return ((base->LINIER & (uint32_t)intSrc) != 0U);/* polyspace RTE:NIV */
}
#endif

/*!
 * @brief Sets the first byte of the tx data buffer.
 *
 * This function writes one byte to the tx data buffer.
 *
 * @param base LINFlexD base pointer.
 * @param data data byte.
 */
static inline void LINFLEXD_SetTxDataBuffer1Byte(volatile LINFlexD_Type * base, uint8_t data)
{
    uint32_t regValTemp = 0U;

    regValTemp = base->BDRL.R;/* polyspace RTE:NIV */
    regValTemp &= ~(LINFlexD_BDRL_DATA0_MASK);
    regValTemp |= LINFlexD_BDRL_DATA0(data); /* PRQA S 2985 */
    base->BDRL.R = regValTemp;
}

/*!
 * @brief Sets the first half-word of the tx data buffer.
 *
 * This function writes two bytes to the tx data buffer.
 *
 * @param base LINFlexD base pointer.
 * @param data data half-word.
 */
static inline void LINFLEXD_SetTxDataBuffer2Bytes(volatile LINFlexD_Type * base, uint16_t data)
{
    uint32_t mask, regValTemp = 0U;
    mask = LINFlexD_BDRL_DATA0_MASK | LINFlexD_BDRL_DATA1_MASK;
    regValTemp = base->BDRL.R;/* polyspace RTE:NIV */
    regValTemp &= ~(mask);
    regValTemp |= ((uint32_t)data & mask); /* PRQA S 2985 */
    base->BDRL.R = regValTemp;
}

/*!
 * @brief Gets the first byte of the rx data buffer.
 *
 * This function retrieves one byte from the rx data buffer.
 *
 * @param base LINFlexD base pointer.
 * @return data byte.
 */
static inline uint8_t LINFLEXD_GetRxDataBuffer1Byte(const volatile LINFlexD_Type * base)
{
    return (uint8_t)((base->BDRM.B.DATA4 & LINFlexD_BDRM_DATA4_MASK) >> LINFlexD_BDRM_DATA4_SHIFT);/* polyspace RTE:NIV */
}

/*!
 * @brief Gets the first half-word of the rx data buffer.
 *
 * This function retrieves two bytes from the rx data buffer.
 *
 * @param base LINFlexD base pointer.
 * @return data half-word.
 */
static inline uint16_t LINFLEXD_GetRxDataBuffer2Bytes(const volatile LINFlexD_Type * base)
{
    uint32_t mask = LINFlexD_BDRM_DATA4_MASK | LINFlexD_BDRM_DATA5_MASK;/* polyspace RTE:NIV */
    return (uint16_t)(base->BDRM.B.DATA4 & mask);/* polyspace RTE:NIV */
}

#if defined(__cplusplus)
}
#endif

/*******************************************************************************
 * API Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_SetBaudRate
 * Description   : This function sets the baud rate for UART communication.
 *
 * Implements    : LINFLEXD_UART_LLD_SetBaudRate_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_SetBaudRate(uint32_t instance, uint32_t baudrate)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    float32_t prescaler = 0;
    float32_t fraction = 0;
    uint32_t mantissa = 0U;
    uint32_t fractionDenominator = 0U;
    uint8_t fractionNumerator = 0U;
    uint32_t uartSourceClock = 0U;
    volatile LINFlexD_Type * base;
    bool resetIdle = FALSE;

    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */
    // (void)CLOCK_GetModuleClockFreq(LIN_CLK, &uartSourceClock);
    uartSourceClock = 100000000;

    const linflexd_uart_state_t * uartState;
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];

    if (uartState->isTxBusy == TRUE)/* polyspace RTE:IDP,NIV */
    {
        return STATUS_BUSY;
    }

    if (uartState->isRxBusy == TRUE)
    {
        return STATUS_BUSY;
    }

    /* Compute the values for baud rate divider mantissa and fraction */
    if(0U != baudrate)
    {
        prescaler = (float32_t)uartSourceClock / ((float32_t)baudrate * (float32_t)DEFAULT_OSR);/* polyspace RTE:NIVL */
    }
    mantissa = (uint32_t)prescaler;
    fraction = prescaler - (float32_t)mantissa;
    fractionDenominator = ((uint32_t)1U << (uint32_t)BAUDRATE_FRACTION_WIDTH);
    float32_t float32_tNumerator = ((float32_t)fraction * (float32_t)fractionDenominator) + (float32_t)0.5F;
    fractionNumerator = (uint8_t)(float32_tNumerator);/* polyspace RTE:OVFL */

    if (fractionNumerator == fractionDenominator)
    {
        fractionNumerator = 0;
        mantissa++;
    }

    if (LINFLEXD_GetLinState(base) != LINFlexD_STATE_INIT_MODE)
    {
        /* Request init mode and wait until the mode entry is complete */
        LINFLEXD_EnterInitMode(base);
        while (LINFLEXD_GetLinState(base) != LINFlexD_STATE_INIT_MODE) {}

        resetIdle = TRUE;
    }

    /* Write the computed values to registers */
    LINFLEXD_SetIntegerBaudRate(base, mantissa);
    LINFLEXD_SetFractionalBaudRate(base, fractionNumerator);

    if (resetIdle == TRUE)
    {
        /* Enter normal mode */
        LINFLEXD_EnterNormalMode(base);
    }

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_GetBaudRate
 * Description   : This function retrieves the baud rate for UART communication.
 *
 * Implements    : LINFLEXD_UART_LLD_GetBaudRate_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_GetBaudRate(uint32_t instance, uint32_t * baudrate)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);
    DEV_ASSERT(baudrate != NULL);

    uint32_t mantissa = 0U;
    uint8_t fraction = 0U;
    uint32_t uartSourceClock = 0U;
    const volatile LINFlexD_Type * base;

    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */
    // (void)CLOCK_GetModuleClockFreq(LIN_CLK, &uartSourceClock);
    uartSourceClock = 100000000;
    
    /* Get the baud rate divider integer and fractional parts from registers */
    mantissa = LINFLEXD_GetIntegerBaudRate(base);
    fraction = LINFLEXD_GetFractionalBaudRate(base);

    /* Calculate the baud rate based on protocol clock value */
    if(0U < mantissa)
    {
        *baudrate = uartSourceClock / ((mantissa * DEFAULT_OSR) + (uint32_t)fraction);/* PRQA S 2834 */
    }

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_InstallRxCallback
 * Description   : This function installs a callback for UART receive.
 *
 * Implements    : LINFLEXD_UART_LLD_InstallRxCallback_Activity
 *END**************************************************************************/
uart_callback_t LINFLEXD_UART_LLD_InstallRxCallback(uint32_t instance,
                                                    uart_callback_t function,
                                                    void * callbackParam)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    linflexd_uart_state_t * uartState;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Save the previous callback and set the new one */
    uart_callback_t currentCallback = uartState->rxCallback;/* polyspace RTE:IDP,NIV */
    uartState->rxCallback = function;
    uartState->rxCallbackParam = callbackParam;

    return currentCallback;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_InstallTxCallback
 * Description   : This function installs a callback for UART transmit.
 *
 * Implements    : LINFLEXD_UART_LLD_InstallTxCallback_Activity
 *END**************************************************************************/
uart_callback_t LINFLEXD_UART_LLD_InstallTxCallback(uint32_t instance,
                                                    uart_callback_t function,
                                                    void * callbackParam)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    linflexd_uart_state_t * uartState;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Save the previous callback and set the new one */
    uart_callback_t currentCallback = uartState->txCallback;/* polyspace RTE:IDP,NIV */
    uartState->txCallback = function;
    uartState->txCallbackParam = callbackParam;

    return currentCallback;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_InstallErrorCallback
 * Description   : This function installs a callback for UART error cases.
 *
 * Implements    : LINFLEXD_UART_LLD_InstallErrorCallback_Activity
 *END**************************************************************************/
uart_callback_t LINFLEXD_UART_LLD_InstallErrorCallback(uint32_t instance,
                                                       uart_callback_t function,
                                                       void * callbackParam)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    linflexd_uart_state_t * uartState;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Save the previous callback and set the new one */
    uart_callback_t currentCallback = uartState->errorCallback;/* polyspace RTE:IDP,NIV */
    uartState->errorCallback = function;
    uartState->errorCallbackParam = callbackParam;

    return currentCallback;
}

#if defined RESOURCE_SUPPORT_SIUL2_IP
void LINFLEXD_UART_LLD_GPIO_Init(uint32_t instance, const UartGpioSiul2 UartGpioList[])
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);
    const UartGpioSiul2 *s_UartGpioVec = UartGpioList;

    const uint32_t _pad_num_tx_ = s_UartGpioVec[instance].uart_tx.pad_num; /* polyspace RTE:IDP,OBAI */
    const uint32_t _mscr_io_val_tx_ = s_UartGpioVec[instance].uart_tx.mscr_io_val;

    const uint32_t _pad_num_rx_ = s_UartGpioVec[instance].uart_rx.pad_num;
    const uint32_t _mscr_io_val_rx_ = s_UartGpioVec[instance].uart_rx.mscr_io_val;
#if defined RESOURCE_SUPPORT_EIOMUX
    const uint32_t _io_mode_tx_ = s_UartGpioVec[instance].uart_tx.io_mode;
    const uint32_t _io_mode_rx_ = s_UartGpioVec[instance].uart_rx.io_mode;
#elif defined RESOURCE_SUPPORT_EIOMUX2
    const uint32_t _imscr_tx_ = s_UartGpioVec[instance].uart_tx.imscr;
    const uint32_t _imscr_rx_ = s_UartGpioVec[instance].uart_rx.imscr;
    const uint32_t _isss_ = s_UartGpioVec[instance].uart_tx.isss;
    const uint32_t _iss_ = s_UartGpioVec[instance].uart_tx.iss;
#else
    const uint32_t _mux_reg_rx_ = s_UartGpioVec[instance].uart_rx.mscr_mux_reg;
    const uint32_t _mux_val_rx_ = s_UartGpioVec[instance].uart_rx.mscr_mux_val;
#endif

    SIUL2.MSCR_IO[_pad_num_tx_].R = _mscr_io_val_tx_;
    SIUL2.MSCR_IO[_pad_num_rx_].R = _mscr_io_val_rx_;
#if defined RESOURCE_SUPPORT_EIOMUX
    /* set IO_MODE to select PIN function */
    EIOMUX.PAD_MODE[_pad_num_tx_].R = _io_mode_tx_;
    EIOMUX.PAD_MODE[_pad_num_rx_].R = _io_mode_rx_;
#elif defined RESOURCE_SUPPORT_EIOMUX2
    (void)_imscr_tx_;
    /* Set port output */
    EIOMUX2.PAD[_pad_num_tx_].R = 0x40u | _isss_;
    /* Set port input */
    EIOMUX2.PAD[_pad_num_rx_].R = 0x800u;
    /*   ICR offset = ((IMSCR<<2)-0x800)/4   */
    EIOMUX2.ICR[_imscr_rx_].R = _iss_;
#else
    /* set SSS to select PIN function */
    SIUL2.MSCR_MUX[_mux_reg_rx_].R = _mux_val_rx_;
#endif
}

#elif defined RESOURCE_SUPPORT_SIUL_IP

void LINFLEXD_UART_LLD_GPIO_Init(uint32_t instance, const UartGpioSiul UartGpioList[])
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);
    const UartGpioSiul *s_UartGpioVec = UartGpioList;

    const uint16_t _pad_num_tx_ = s_UartGpioVec[instance].uart_tx.pad_num;/* polyspace RTE:OBAI */
    const uint16_t _pcr_tx_ = s_UartGpioVec[instance].uart_tx.pcr_val;

    const uint16_t _pad_num_rx_ = s_UartGpioVec[instance].uart_rx.pad_num;
    const uint16_t _pcr_rx_ = s_UartGpioVec[instance].uart_rx.pcr_val;
    const uint16_t _psmi_reg_rx_ = s_UartGpioVec[instance].uart_rx.psmi_reg;
    const uint8_t _padsel_rx_ = s_UartGpioVec[instance].uart_rx.padsel;

    SIUL.PCR[_pad_num_tx_].R = _pcr_tx_;
    SIUL.PCR[_pad_num_rx_].R = _pcr_rx_;
    SIUL.PSMI[_psmi_reg_rx_].B.PADSEL = _padsel_rx_;
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_Init
 * Description   : This function initializes a LINFlexD instance for UART
 * operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, enable the module-level interrupt to the core, and enable
 * the UART module transmitter and receiver.
 *
 * Implements    : LINFLEXD_UART_DRV_Init_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_Init(uint32_t instance, linflexd_uart_state_t * uartStatePtr,
                                const linflexd_uart_user_config_t * uartUserConfig)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);
    DEV_ASSERT(uartStatePtr != NULL);
    DEV_ASSERT(uartUserConfig != NULL);

    volatile LINFlexD_Type * base;
    uint32_t idx;
    uint32_t uartSourceClock;

    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */

    /* Check if current instance is clock gated off. */
    // (void)CLOCK_GetModuleClockFreq(LIN_CLK, &uartSourceClock);
    uartSourceClock = 100000000;

    DEV_ASSERT(uartSourceClock != 0U);

    /* Check if current instance is already initialized. */
    DEV_ASSERT(s_uartLINFlexDStatePtr[instance] == NULL);

    /* Check if an instance with no DMA support is configured in DMA mode */
    DEV_ASSERT((uartUserConfig->transferType != LINFLEXD_UART_USING_DMA) || (s_LINFlexDInstHasDma[instance] == TRUE));

    /* Clear the state struct for this instance. */
    uint8_t *clearStructPtr = (uint8_t *)uartStatePtr;/* PRQA S 0751 */
    for (idx = 0; idx < sizeof(linflexd_uart_state_t); idx++)
    {
        clearStructPtr[idx] = 0;
    }

    /* Save runtime structure pointer.*/
    s_uartLINFlexDStatePtr[instance] = uartStatePtr;

    /* Request init mode and wait until the mode entry is complete */
    LINFLEXD_EnterInitMode(base);
    while (LINFLEXD_GetLinState(base) != LINFlexD_STATE_INIT_MODE) {}

    base->GCR.B.TDFBM = 1;
    base->GCR.B.RDFBM = 1;

    /* Set UART mode */
    LINFLEXD_SetMode(base, LINFlexD_UART_MODE);

    /* Set the baud rate */
    (void)LINFLEXD_UART_LLD_SetBaudRate(instance, uartUserConfig->baudRate);

    /* Set word length */
    LINFLEXD_SetUartWordLength(base, uartUserConfig->wordLength);
    LINFLEXD_SetTxDataFieldLength(base, (uint8_t)((uint8_t)uartUserConfig->wordLength >> 1U));
    LINFLEXD_SetRxDataFieldLength(base, (uint8_t)((uint8_t)uartUserConfig->wordLength >> 1U));
    uartStatePtr->wordLength = uartUserConfig->wordLength;

    /* Set parity */
    if (uartUserConfig->parityCheck == TRUE)
    {
        LINFLEXD_SetParityControl(base, TRUE);
        LINFLEXD_SetParityType(base, uartUserConfig->parityType);
    }
    else
    {
        LINFLEXD_SetParityControl(base, FALSE);
    }

    /* Set stop bits count */
    LINFLEXD_SetRxStopBitsCount(base, uartUserConfig->stopBitsCount);
#if defined(FEATURE_LINFLEXD_HAS_DIFFERENT_MEM_MAP)
    LINFLEXD_SetTxStopBitsCount(base, uartUserConfig->stopBitsCount, s_LINFlexDInstHasFilters[instance]);
#else
    LINFLEXD_SetTxStopBitsCount(base, uartUserConfig->stopBitsCount, TRUE);
#endif

    /* Enable FIFO for DMA based communication, or buffer mode for interrupt based communication */
    if (uartUserConfig->transferType == LINFLEXD_UART_USING_DMA)
    {
        LINFLEXD_SetTxMode(base, LINFLEXD_UART_RXTX_FIFO_MODE);
        LINFLEXD_SetRxMode(base, LINFLEXD_UART_RXTX_FIFO_MODE);
    }
    else
    {
        LINFLEXD_SetTxMode(base, LINFLEXD_UART_RXTX_BUFFER_MODE);
        LINFLEXD_SetRxMode(base, LINFLEXD_UART_RXTX_BUFFER_MODE);
    }

    /* Enter normal mode */
    LINFLEXD_EnterNormalMode(base);


    /* initialize last driver operation status */
    uartStatePtr->transmitStatus = STATUS_SUCCESS;
    uartStatePtr->receiveStatus = STATUS_SUCCESS;
    uartStatePtr->isTxBusy = FALSE;
    uartStatePtr->isRxBusy = FALSE;

    /* Save the transfer type and DMA channels in driver state */
    uartStatePtr->transferType = uartUserConfig->transferType;
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
    uartStatePtr->rxDMAChannel = uartUserConfig->rxDMAChannel;
    uartStatePtr->txDMAChannel = uartUserConfig->txDMAChannel;
    uartStatePtr->txLinkDMAChannel = uartUserConfig->txLinkDMAChannel;
#endif

    /* Initialize callback functions and parameters */
    uartStatePtr->rxCallback = NULL;
    uartStatePtr->txCallback = NULL;
    uartStatePtr->errorCallback = NULL;
    uartStatePtr->rxCallbackParam = NULL;
    uartStatePtr->txCallbackParam = NULL;
    uartStatePtr->errorCallbackParam = NULL;

    /* Create the synchronization objects */
    (void)OSIF_SemaCreate(&uartStatePtr->rxComplete, 0);
    (void)OSIF_SemaCreate(&uartStatePtr->txComplete, 0);

    /* Install UART handlers */
    // (void)INTC_LLD_Set_IRQ_Priority(s_uartLINFlexDRxIntVec[instance], INTR_PRI_10);
    // (void)INTC_LLD_Set_IRQ_Handle(s_uartLINFlexDRxIntVec[instance], g_uartLINFlexDRxIsr[instance]);
    // (void)INTC_LLD_Set_IRQ_Priority(s_uartLINFlexDTxIntVec[instance], INTR_PRI_10);
    // (void)INTC_LLD_Set_IRQ_Handle(s_uartLINFlexDTxIntVec[instance], g_uartLINFlexDTxIsr[instance]);
    // (void)INTC_LLD_Set_IRQ_Priority(s_uartLINFlexDErrIntVec[instance], INTR_PRI_10);
    // (void)INTC_LLD_Set_IRQ_Handle(s_uartLINFlexDErrIntVec[instance], g_uartLINFlexDErrIsr[instance]);


    /* Enable LINFlexD interrupts */
    // (void)INTC_LLD_Set_IRQ_Enable(s_uartLINFlexDRxIntVec[instance]);
    // (void)INTC_LLD_Set_IRQ_Enable(s_uartLINFlexDTxIntVec[instance]);
    // (void)INTC_LLD_Set_IRQ_Enable(s_uartLINFlexDErrIntVec[instance]);

    /* Enable error interrupts */
    // LINFLEXD_SetInterruptMode(base, LINFlexD_FRAME_ERROR_INT, TRUE);
    // LINFLEXD_SetInterruptMode(base, LINFlexD_BUFFER_OVERRUN_INT, TRUE);

    /* Enable the transmitter */
    LINFLEXD_SetTransmitterState(base, TRUE);
    base->DMATXE.B.DTE = 1U;

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_Deinit
 * Description   : This function shuts down the UART by disabling interrupts and
 *                 transmitter/receiver.
 *
 * Implements    : LINFLEXD_UART_LLD_Deinit_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_Deinit(uint32_t instance)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    uint32_t uartSourceClock;
    volatile LINFlexD_Type * base;
    const linflexd_uart_state_t * uartState;

    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    // (void)CLOCK_GetModuleClockFreq(LIN_CLK, &uartSourceClock);
    uartSourceClock = 100000000;

    /* Check if current instance is already de-initialized or is gated.*/
    DEV_ASSERT(s_uartLINFlexDStatePtr[instance] != NULL);
    DEV_ASSERT(uartSourceClock != 0U);

    /* Disable error interrupts */
    LINFLEXD_SetInterruptMode(base, LINFlexD_FRAME_ERROR_INT, FALSE);
    LINFLEXD_SetInterruptMode(base, LINFlexD_BUFFER_OVERRUN_INT, FALSE);

    /* Restore default handlers */
    (void)INTC_LLD_Set_IRQ_Priority(s_uartLINFlexDRxIntVec[instance], INTR_PRI_10);
    (void)INTC_LLD_Set_IRQ_Handle(s_uartLINFlexDRxIntVec[instance],&DefaultISR);
    (void)INTC_LLD_Set_IRQ_Priority(s_uartLINFlexDTxIntVec[instance], INTR_PRI_10);
    (void)INTC_LLD_Set_IRQ_Handle(s_uartLINFlexDTxIntVec[instance], &DefaultISR);
    (void)INTC_LLD_Set_IRQ_Priority(s_uartLINFlexDErrIntVec[instance], INTR_PRI_10);
    (void)INTC_LLD_Set_IRQ_Handle(s_uartLINFlexDErrIntVec[instance], &DefaultISR);

    /* Disable LINFlexD interrupts */
    (void)INTC_LLD_Set_IRQ_Disable(s_uartLINFlexDRxIntVec[instance]);
    (void)INTC_LLD_Set_IRQ_Disable(s_uartLINFlexDTxIntVec[instance]);
    (void)INTC_LLD_Set_IRQ_Disable(s_uartLINFlexDErrIntVec[instance]);


    /* Destroy the synchronization objects */
    (void)OSIF_SemaDestroy(&uartState->rxComplete);
    (void)OSIF_SemaDestroy(&uartState->txComplete);

    /* Clear the saved pointer to the state structure */
    s_uartLINFlexDStatePtr[instance] = NULL;

    return STATUS_SUCCESS;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_SendDataBlocking
 * Description   : This function sends data using LINFlexD module in UART mode
 * with blocking method.
 *
 * Implements    : LINFLEXD_UART_LLD_SendDataBlocking_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_SendDataBlocking(uint32_t instance,
                                            const uint8_t * txBuff,
                                            uint32_t txSize,
                                            uint32_t timeout)
{
    DEV_ASSERT(txBuff != NULL);
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    linflexd_uart_state_t * uartState;
    status_t retVal;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */
    retVal = STATUS_SUCCESS; /*PRQA S 2982*/

    /* Indicates this is a blocking transaction. */
    uartState->isTxBlocking = TRUE;/* polyspace RTE:IDP,NIV */

    DEV_ASSERT((uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS) ||
               (uartState->transferType == LINFLEXD_UART_USING_DMA));

    if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
    {
        /* Start the transmission process using interrupts */
        retVal = LINFLEXD_UART_LLD_StartSendUsingInterrupts(instance, txBuff, txSize);
    }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
    else
    {
        /* Start the transmission process using DMA */
        retVal = LINFLEXD_UART_LLD_StartSendUsingDma(instance, txBuff, txSize);
    }
#endif

    if (retVal == STATUS_SUCCESS)
    {
        /* Wait until the transmit is complete. */
        retVal = OSIF_SemaWait(&uartState->txComplete, timeout);

        /* Finish the transmission if timeout expired */
        if (retVal == STATUS_TIMEOUT) /* PRQA S 2992, 2996 */
        {
            uartState->isTxBlocking = FALSE;
            uartState->transmitStatus = STATUS_TIMEOUT;

            if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
            {
                LINFLEXD_UART_LLD_CompleteSendUsingInterrupts(instance);
            }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
            else
            {
                LINFLEXD_UART_LLD_CompleteSendUsingDma(((void *)instance), EDMA_CHN_STATUS_NORMAL); /*PRQA S 0326*/
            }
#endif
        }
    }

    return uartState->transmitStatus;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_SendData
 * Description   : This function sends data using LINFlexD module in UART mode
 * with non-blocking method.
 *
 * Implements    : LINFLEXD_UART_LLD_SendData_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_SendData(uint32_t instance,
                                    const uint8_t * txBuff,
                                    uint32_t txSize)
{
    status_t retVal;
    DEV_ASSERT(txBuff != NULL);
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    linflexd_uart_state_t * uartState;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Indicates this is a non-blocking transaction. */
    uartState->isTxBlocking = FALSE;/* polyspace RTE:IDP,NIV */

    DEV_ASSERT((uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS) ||
                  (uartState->transferType == LINFLEXD_UART_USING_DMA));

    if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
    {
        /* Start the transmission process using interrupts */
        retVal = LINFLEXD_UART_LLD_StartSendUsingInterrupts(instance, txBuff, txSize);
    }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
    else
    {
       /* Start the transmission process using DMA */
       retVal = LINFLEXD_UART_LLD_StartSendUsingDma(instance, txBuff, txSize);
    }
#endif
    /* Start the transmission process */
    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_GetTransmitStatus
 * Description   : This function returns whether the previous UART transmit has
 * finished. When performing non-blocking transmit, the user can call this
 * function to ascertain the state of the current transmission:
 * in progress (or busy) or complete (success). In addition, if the transmission
 * is still in progress, the user can obtain the number of words that have been
 * currently transferred.
 *
 * Implements    : LINFLEXD_UART_LLD_GetTransmitStatus_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_GetTransmitStatus(uint32_t instance, uint32_t * bytesRemaining)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    const linflexd_uart_state_t * uartState;
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    if (bytesRemaining != NULL)
    {
        /* Fill in the number of bytes yet to be transferred and update the return value if needed */
        if (uartState->isTxBusy == TRUE)/* polyspace RTE:IDP,NIV */
        {
            /* Fill in the bytes not transferred yet. */
            if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
            {
                /* In interrupt-based communication, the remaining bytes are retrieved
                 * from the state structure
                 */
                *bytesRemaining = uartState->txSize;;
            }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
            else
            {
                /* In DMA-based communication, the remaining bytes are retrieved
                 * from the current DMA major loop count
                 */
                *bytesRemaining = EDMA_GetChnRemainingIterationsCount(uartState->txDMAChannel);
            }
#endif
        }
        else
        {
            *bytesRemaining = 0;
        }
    }

    return uartState->transmitStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_AbortSendingData
 * Description   : This function terminates an non-blocking UART transmission
 * early. During a non-blocking UART transmission, the user has the option to
 * terminate the transmission early if the transmission is still in progress.
 *
 * Implements    : LINFLEXD_UART_LLD_AbortSendingData_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_AbortSendingData(uint32_t instance)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    linflexd_uart_state_t * uartState;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Check if a transfer is running. */
    if (uartState->isTxBusy == FALSE)/* polyspace RTE:IDP,NIV */
    {
        return STATUS_SUCCESS;
    }

    /* Update the tx status */
    uartState->transmitStatus = STATUS_UART_ABORTED;

    /* Stop the running transfer. */
    if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
    {
        LINFLEXD_UART_LLD_CompleteSendUsingInterrupts(instance);
    }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
    else
    {
        LINFLEXD_UART_LLD_CompleteSendUsingDma(((void *)instance), EDMA_CHN_STATUS_NORMAL); /*PRQA S 0326*/
    }
#endif

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_ReceiveDataBlocking
 * Description   : Retrieves data from the LINFlexD module in UART mode with
 * blocking method.
 *
 * Implements    : LINFLEXD_UART_LLD_ReceiveDataBlocking_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_ReceiveDataBlocking(uint32_t instance,
                                               uint8_t * rxBuff,
                                               uint32_t rxSize,
                                               uint32_t timeout)
{
    DEV_ASSERT(rxBuff != NULL);
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    linflexd_uart_state_t * uartState;
    status_t retVal;

    retVal = STATUS_SUCCESS; /*PRQA S 2982*/
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Indicates this is a blocking transaction. */
    uartState->isRxBlocking = TRUE;/* polyspace RTE:IDP,NIV */

    DEV_ASSERT((uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS) ||
               (uartState->transferType == LINFLEXD_UART_USING_DMA));

    if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
    {
        /* Start the reception process using interrupts */
        retVal = LINFLEXD_UART_LLD_StartReceiveUsingInterrupts(instance, rxBuff, rxSize);
    }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
    else
    {
        /* Start the reception process using DMA */
        retVal = LINFLEXD_UART_LLD_StartReceiveUsingDma(instance, rxBuff, rxSize);
    }
#endif

    if (retVal == STATUS_SUCCESS)
    {
        /* Wait until the receive is complete. */
        retVal = OSIF_SemaWait(&uartState->rxComplete, timeout);

        /* Finish the reception if timeout expired */
        if (retVal == STATUS_TIMEOUT) /* PRQA S 2992, 2996 */
        {
            uartState->isRxBlocking = FALSE;
            uartState->receiveStatus = STATUS_TIMEOUT;

            if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
            {
                LINFLEXD_UART_LLD_CompleteReceiveUsingInterrupts(instance);
            }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
            else
            {
                LINFLEXD_UART_LLD_CompleteReceiveUsingDma(((void *)instance), EDMA_CHN_STATUS_NORMAL); /*PRQA S 0326*/
            }
#endif
        }
    }

    return uartState->receiveStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_ReceiveData
 * Description   : Retrieves data from the LINFlexD module in UART mode with
 * non-blocking method.
 *
 * Implements    : LINFLEXD_UART_LLD_ReceiveData_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_ReceiveData(uint32_t instance,
                                       uint8_t * rxBuff,
                                       uint32_t rxSize)
{
    DEV_ASSERT(rxBuff != NULL);
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    status_t retVal;
    linflexd_uart_state_t * uartState;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Indicates this is a non-blocking transaction. */
    uartState->isRxBlocking = FALSE;/* polyspace RTE:IDP,NIV */

    DEV_ASSERT((uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS) ||
               (uartState->transferType == LINFLEXD_UART_USING_DMA));

    if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
    {
        /* Start the transmission process using interrupts */
        retVal = LINFLEXD_UART_LLD_StartReceiveUsingInterrupts(instance, rxBuff, rxSize);
    }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
    else
    {
        /* Start the transmission process using interrupts */
        retVal = LINFLEXD_UART_LLD_StartReceiveUsingDma(instance, rxBuff, rxSize);
    }
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_GetReceiveStatus
 * Description   : This function returns whether the previous UART receive is
 * complete. When performing a non-blocking receive, the user can call this
 * function to ascertain the state of the current receive progress: in progress
 * or complete. In addition, if the receive is still in progress, the user can
 * obtain the number of words that have not yet been received.
 *
 * Implements    : LINFLEXD_UART_LLD_GetReceiveStatus_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_GetReceiveStatus(uint32_t instance, uint32_t * bytesRemaining)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    const linflexd_uart_state_t * uartState;
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    if (bytesRemaining != NULL)
    {
        if (uartState->isRxBusy == TRUE)/* polyspace RTE:IDP,NIV */
        {
            /* Fill in the number of bytes yet to be received and update the return value if needed */
            if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
            {
                /* In interrupt-based communication, the remaining bytes are retrieved
                 * from the state structure
                 */
                *bytesRemaining = uartState->rxSize;
            }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
            else
            {
                /* In DMA-based communication, the remaining bytes are retrieved
                 * from the current DMA major loop count
                 */
                 *bytesRemaining = EDMA_GetChnRemainingIterationsCount(uartState->rxDMAChannel);
            }
#endif
        }
        else
        {
            *bytesRemaining = 0;
        }
    }

    return uartState->receiveStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_AbortReceivingData
 * Description   : Terminates a non-blocking receive early.
 *
 * Implements    : LINFLEXD_UART_LLD_AbortReceivingData_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_AbortReceivingData(uint32_t instance)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);

    linflexd_uart_state_t * uartState;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Check if a transfer is running. */
    if (uartState->isRxBusy == FALSE)/* polyspace RTE:IDP,NIV */
    {
        return STATUS_SUCCESS;
    }

    /* Update the rx status */
    uartState->receiveStatus = STATUS_UART_ABORTED;

    /* Stop the running transfer. */
    if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
    {
        LINFLEXD_UART_LLD_CompleteReceiveUsingInterrupts(instance);
    }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
    else
    {
        LINFLEXD_UART_LLD_CompleteReceiveUsingDma(((void *)instance), EDMA_CHN_STATUS_NORMAL); /*PRQA S 0326*/
    }
#endif

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_SetTxBuffer
 * Description   : Sets the driver internal reference to the tx buffer.
 *                 Can be called from the tx callback to provide a different
 *                 buffer for continuous transmission.
 *
 * Implements    : LINFLEXD_UART_LLD_SetTxBuffer_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_SetTxBuffer(uint32_t instance,
                                       const uint8_t * txBuff,
                                       uint32_t txSize)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);
    DEV_ASSERT(txBuff != NULL);
    DEV_ASSERT(txSize > 0U);

    linflexd_uart_state_t * uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */
    uartState->txBuff = txBuff;/* polyspace RTE:IDP,NIV */
    uartState->txSize = txSize;

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_SetRxBuffer
 * Description   : Sets the driver internal reference to the rx buffer.
 *                 Can be called from the rx callback to provide a different
 *                 buffer for continuous reception.
 *
 * Implements    : LINFLEXD_UART_LLD_SetRxBuffer_Activity
 *END**************************************************************************/
status_t LINFLEXD_UART_LLD_SetRxBuffer(uint32_t instance,
                                       uint8_t * rxBuff,
                                       uint32_t rxSize)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);
    DEV_ASSERT(rxBuff != NULL);
    DEV_ASSERT(rxSize > 0U);

    linflexd_uart_state_t * uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */
    uartState->rxBuff = rxBuff;/* polyspace RTE:IDP,NIV */
    uartState->rxSize = rxSize;

    return STATUS_SUCCESS;
}

/* ----------------------------------------------------------------------------INTC--------------------------------------------------------------*/
/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_RxIRQHandler
 * Description   : Rx interrupt handler for UART.
 * This handler uses the rx buffer stored in the state structure to receive
 * data. This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 *END**************************************************************************/
static void LINFLEXD_UART_LLD_RxIRQHandler(uint32_t instance)
{
    linflexd_uart_state_t * uartState;
    volatile LINFlexD_Type * base;

    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Exit if there is no reception in progress */
    if (uartState->isRxBusy == FALSE)/* polyspace RTE:IDP,NIV */
    {
        /* Clear the flag */
        LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_DATA_RECEPTION_COMPLETE_FLAG);
        return;
    }

    /* Retrieve the data */
    LINFLEXD_UART_LLD_GetData(instance);

    /* Clear the flags */
    LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_DATA_RECEPTION_COMPLETE_FLAG);
    LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_MESSAGE_BUFFER_FULL_FLAG);

    /* Check if this was the last byte in the current buffer */
    if (uartState->rxSize == 0U)
    {
        /* Invoke the callback when the buffer is finished;
         * Application can provide another buffer inside the callback by calling LINFLEXD_UART_LLD_SetRxBuffer */
        if (uartState->rxCallback != NULL)
        {
            uartState->rxCallback(uartState, UART_EVENT_RX_FULL, uartState->rxCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
        }
    }

    /* Finish reception if this was the last byte received */
    if (uartState->rxSize == 0U)
    {
        /* Complete transfer (disable rx logic) */
        LINFLEXD_UART_LLD_CompleteReceiveUsingInterrupts(instance);

        /* Invoke callback if there is one */
        if (uartState->rxCallback != NULL)
        {
            uartState->rxCallback(uartState, UART_EVENT_END_TRANSFER, uartState->rxCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_TxIRQHandler
 * Description   : Tx interrupt handler for UART.
 * This handler uses the tx buffer stored in the state structure to transmit
 * data. This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 *END**************************************************************************/
static void LINFLEXD_UART_LLD_TxIRQHandler(uint32_t instance)
{
    linflexd_uart_state_t * uartState;
    volatile LINFlexD_Type * base;

    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Exit if there is no transmission in progress */
    if (uartState->isTxBusy == FALSE)/* polyspace RTE:IDP,NIV */
    {
        /* Clear the flag */
        LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_DATA_TRANSMITTED_FLAG);
        return;
    }

    /* Check if there are any more bytes to send */
    if (uartState->txSize > 0U)
    {
        /* Send data */
        LINFLEXD_UART_LLD_PutData(instance);

        /* Clear the flag */
        LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_DATA_TRANSMITTED_FLAG);
    }
    else
    {
        /* Invoke the callback when the buffer is finished;
         * Application can provide another buffer inside the callback by calling LINFLEXD_UART_LLD_SetTxBuffer */
        if (uartState->txCallback != NULL)
        {
            uartState->txCallback(uartState, UART_EVENT_TX_EMPTY, uartState->txCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
        }

        /* If there is no more data to send, complete the transmission */
        if (uartState->txSize == 0U)
        {
            LINFLEXD_UART_LLD_CompleteSendUsingInterrupts(instance);

            /* Call the callback to notify application that the transfer is complete */
            if (uartState->txCallback != NULL)
            {
                uartState->txCallback(uartState, UART_EVENT_END_TRANSFER, uartState->txCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
            }

            /* Clear the flag */
            LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_DATA_TRANSMITTED_FLAG);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_ErrIRQHandler
 * Description   : Error interrupt handler for UART.
 * This handler calls the user callback to treat error conditions.
 *
 *END**************************************************************************/
static void LINFLEXD_UART_LLD_ErrIRQHandler(uint32_t instance)
{
    linflexd_uart_state_t * uartState;
    volatile LINFlexD_Type * base;

    base = s_LINFlexDBase[instance];
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Update the receive status according to the error occurred */
    if (LINFLEXD_GetStatusFlag(base, LINFlexD_UART_BUFFER_OVERRUN_FLAG) == TRUE)
    {
        /* Update the status */
        uartState->receiveStatus = STATUS_UART_RX_OVERRUN;/* polyspace RTE:IDP,NIV */
        /* Clear the flag */
        LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_BUFFER_OVERRUN_FLAG);
    }
    else if (LINFLEXD_GetStatusFlag(base, LINFlexD_UART_FRAME_ERROR_FLAG) == TRUE)
    {
        /* Update the status */
        uartState->receiveStatus = STATUS_UART_FRAMING_ERROR;/* polyspace RTE:IDP,NIV */
        /* Clear the flag */
        LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_FRAME_ERROR_FLAG);
    }
    else
    {
        /* This branch should never be reached - avoid MISRA violations */
        uartState->receiveStatus = STATUS_ERROR;/* polyspace RTE:IDP,NIV */
    }

    /* Terminate the current reception */
    if (uartState->transferType == LINFLEXD_UART_USING_INTERRUPTS)
    {
        LINFLEXD_UART_LLD_CompleteReceiveUsingInterrupts(instance);
    }
#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
    else
    {
        LINFLEXD_UART_LLD_CompleteReceiveUsingDma(((void *)instance), EDMA_CHN_STATUS_NORMAL); /*PRQA S 0326*/
    }
#endif

    /* Invoke the callback, if any */
    if (uartState->errorCallback != NULL)
    {
        uartState->errorCallback(uartState, UART_EVENT_ERROR, uartState->errorCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_StartSendUsingInterrupts
 * Description   : Initiate (start) a transmit by beginning the process of
 * sending data and enabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static status_t LINFLEXD_UART_LLD_StartSendUsingInterrupts(uint32_t instance,
                                                           const uint8_t * txBuff,
                                                           uint32_t txSize)
{
	volatile LINFlexD_Type * base;
    linflexd_uart_state_t * uartState;

    base = s_LINFlexDBase[instance];
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Check it's not busy transmitting data from a previous function call */
    if (uartState->isTxBusy == TRUE)/* polyspace RTE:IDP,NIV */
    {
        return STATUS_BUSY;
    }

    DEV_ASSERT(txSize > 0U);

    /* Initialize the module driver state structure */
    uartState->txBuff = txBuff;
    uartState->txSize = txSize;
    uartState->isTxBusy = TRUE;
    uartState->transmitStatus = STATUS_BUSY;

    /* Enable the transmitter */
    LINFLEXD_SetTransmitterState(base, TRUE);

    /* Clear the tx empty flag to make sure the transmission of the first byte
     * doesn't occur right after enabling the tx interrupt
     */
    LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_DATA_TRANSMITTED_FLAG);

    /* Enable transmission complete interrupt */
    LINFLEXD_SetInterruptMode(base, LINFlexD_DATA_TRANSMITTED_INT, TRUE);

    /* Transmit the first word */
    LINFLEXD_UART_LLD_PutData(instance);

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_StartReceiveUsingInterrupts
 * Description   : Initiate (start) a receive by beginning the process of
 * receiving data and enabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static status_t LINFLEXD_UART_LLD_StartReceiveUsingInterrupts(uint32_t instance,
                                                              uint8_t * rxBuff,
                                                              uint32_t rxSize)
{
    DEV_ASSERT(instance < (uint32_t)LINFLEXD_MAX);
    DEV_ASSERT(rxBuff != NULL);

    linflexd_uart_state_t * uartState;
    volatile LINFlexD_Type * base;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */
    base = s_LINFlexDBase[instance];

    /* Check it's not busy receiving data from a previous function call */
    if ((uartState->isRxBusy == TRUE) && (uartState->rxCallback == NULL))/* polyspace RTE:IDP,NIV */
    {
        return STATUS_BUSY;
    }

    DEV_ASSERT(rxSize > 0U);

    /* Initialize the module driver state struct to indicate transfer in progress
     * and with the buffer and byte count data. */
    uartState->isRxBusy = TRUE;
    uartState->rxBuff = rxBuff;
    uartState->rxSize = rxSize;
    uartState->receiveStatus = STATUS_BUSY;

    /* Clear the flag */
    LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_DATA_RECEPTION_COMPLETE_FLAG);
    LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_MESSAGE_BUFFER_FULL_FLAG);

    /* Enable the receiver */
    LINFLEXD_SetReceiverState(base, TRUE);

    /* Enable receive data full interrupt */
    LINFLEXD_SetInterruptMode(base, LINFlexD_DATA_RECEPTION_COMPLETE_INT, TRUE);

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_CompleteSendUsingInterrupts
 * Description   : Finish up a transmit by completing the process of sending
 * data and disabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void LINFLEXD_UART_LLD_CompleteSendUsingInterrupts(uint32_t instance)
{
	volatile LINFlexD_Type * base;
    linflexd_uart_state_t * uartState;

    base = s_LINFlexDBase[instance];
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Disable transmission complete interrupt */
    LINFLEXD_SetInterruptMode(base, LINFlexD_DATA_TRANSMITTED_INT, FALSE);

    /* Disable the transmitter */
    LINFLEXD_SetTransmitterState(base, FALSE);

    /* Signal the synchronous completion object. */
    if (uartState->isTxBlocking == TRUE)/* polyspace RTE:IDP,NIV */
    {
        (void)OSIF_SemaPost(&uartState->txComplete);
    }

    /* Update the information of the module driver state */
    uartState->isTxBusy = FALSE;

    /* If the current transmission hasn't been aborted, update the status */
    if (uartState->transmitStatus == STATUS_BUSY)
    {
        uartState->transmitStatus = STATUS_SUCCESS;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_CompleteReceiveUsingInterrupts
 * Description   : Finish up a receive by completing the process of receiving data
 * and disabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void LINFLEXD_UART_LLD_CompleteReceiveUsingInterrupts(uint32_t instance)
{
    linflexd_uart_state_t * uartState;
    volatile LINFlexD_Type * base;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */
    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */

    /* Disable receive data full interrupt. */
    LINFLEXD_SetInterruptMode(base, LINFlexD_DATA_RECEPTION_COMPLETE_INT, FALSE);

    /* Disable the receiver */
    LINFLEXD_SetReceiverState(base, FALSE);

    /* Signal the synchronous completion object. */
    if (uartState->isRxBlocking == TRUE)/* polyspace RTE:IDP,NIV */
    {
        (void)OSIF_SemaPost(&uartState->rxComplete);
        uartState->isRxBlocking = FALSE;
    }

    /* Update the information of the module driver state */
    uartState->isRxBusy = FALSE;

    /* If the current reception hasn't been aborted and no error occurred, update the status */
    if (uartState->receiveStatus == STATUS_BUSY)
    {
        uartState->receiveStatus = STATUS_SUCCESS;
    }
}

#if defined(FEATURE_LINFLEXD_HAS_DMA_ENABLED)
/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_StartSendDataUsingDma
 * Description   : Initiate (start) a transmit by beginning the process of
 * sending data using DMA transfers.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static status_t LINFLEXD_UART_LLD_StartSendUsingDma(uint32_t instance,
                                                    const uint8_t * txBuff,
                                                    uint32_t txSize)
{
	volatile LINFlexD_Type * base;
    linflexd_uart_state_t * uartState;

    base = s_LINFlexDBase[instance];
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Check it's not busy transmitting data from a previous function call */
    if (uartState->isTxBusy == TRUE)/* polyspace RTE:IDP,NIV */
    {
        return STATUS_BUSY;
    }

    /* Check the validity of the parameters */
    DEV_ASSERT(txSize > 0U);
    if(!((uartState->wordLength == LINFLEXD_UART_7_BITS) || (uartState->wordLength == LINFLEXD_UART_8_BITS)))
    {
        /* The size of the buffer should be an even number for DMA transfers with 15/16 bits word length */
        DEV_ASSERT((txSize & 1U) == 0U);
    }

    /* Update state structure */
    uartState->txBuff = txBuff;
    uartState->txSize = 0U;
    uartState->isTxBusy = TRUE;
    uartState->transmitStatus = STATUS_BUSY;

    /* Configure the transfer control descriptor for the DMA channel */
    if((uartState->wordLength == LINFLEXD_UART_7_BITS) || (uartState->wordLength == LINFLEXD_UART_8_BITS))
    {
        (void)EDMA_LLD_SetMultiTransferConfig(uartState->txDMAChannel, EDMA_TRANSFER_TYPE_MEMTOPERIPH, (uint32_t)txBuff,
                                                ((uint32_t)(&(base->BDRL.R)) + 3U), EDMA_TRANSFER_SIZE_1B,
                                                1U, txSize, TRUE);
    }
    else
    {
        (void)EDMA_LLD_SetMultiTransferConfig(uartState->txDMAChannel, EDMA_TRANSFER_TYPE_MEMTOPERIPH, (uint32_t)txBuff,
                                                ((uint32_t)(&(base->BDRL.R)) + 2U), EDMA_TRANSFER_SIZE_2B,
                                                2U, txSize >> 1U, TRUE);
    }

    /* Call driver function to end the transmission when the DMA transfer is done */
    (void)EDMA_LLD_SetUpCallback(uartState->txDMAChannel,
                                   (eDMACallbackType)(&LINFLEXD_UART_LLD_CompleteSendUsingDma),
                                   (void*)(instance)); /*PRQA S 0326*/

    /* Start the DMA channel */
    (void)EDMA_LLD_SetChannelRequest(uartState->txDMAChannel);

    /* Enable the transmitter */
    LINFLEXD_SetTransmitterState(base, TRUE);

    /* Enable tx DMA requests for the current instance */
#if defined(FEATURE_LINFLEXD_HAS_DIFFERENT_MEM_MAP)
    if (s_LINFlexDInstHasFilters[instance])
    {
        base->DMATXE = 1U;
    }
    else
    {
        ((LINFlexD_0IFCR_Type *)base)->DMATXE = 1U;
    }
#else
    base->DMATXE.B.DTE = 1U;
#endif

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_StartReceiveDataUsingDma
 * Description   : Initiate (start) a receive by beginning the process of
 * receiving data using DMA transfers.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static status_t LINFLEXD_UART_LLD_StartReceiveUsingDma(uint32_t instance,uint8_t * rxBuff,uint32_t rxSize)
{
	volatile LINFlexD_Type * base;
    linflexd_uart_state_t * uartState;

    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Check it's not busy transmitting data from a previous function call */
    if (uartState->isRxBusy == TRUE)/* polyspace RTE:IDP,NIV */
    {
        return STATUS_BUSY;
    }

    DEV_ASSERT(rxSize > 0U);
    if(!((uartState->wordLength == LINFLEXD_UART_7_BITS) || (uartState->wordLength == LINFLEXD_UART_8_BITS)))
    {
           /* The size of the buffer should be an even number for DMA transfers with 15/16 bits word length */
           DEV_ASSERT((rxSize & 1U) == 0U);
    }

    /* Update the state structure */
    uartState->rxBuff = rxBuff;
    uartState->rxSize = 0U;
    uartState->isRxBusy = TRUE;
    uartState->receiveStatus = STATUS_BUSY;

    /* Configure the transfer control descriptor for the DMA channel */
    if((uartState->wordLength == LINFLEXD_UART_7_BITS) || (uartState->wordLength == LINFLEXD_UART_8_BITS))
    {
        /* Dma configuration structure */
        eDMATransferConfigType dmaConfig_uart =
        {
            .srcAddr = ((uint32_t)(&(base->BDRM.R)) + 3U), /* Modified by function */
            .destAddr = (uint32_t)rxBuff, /* Modified by function */
            .srcTransDataSize = EDMA_TRANSFER_SIZE_1B,
            .destTransDataSize = EDMA_TRANSFER_SIZE_1B,
            .srcAddrOffset = 0,
            .destAddrOffset = (int16_t)sizeof(uint8_t),
            .srcAddrAdjustLast = 0,
            .destAddrAdjustLast = -(int32_t)rxSize, /* Modified by function *//* polyspace RTE:OVFL */
            .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
            .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
            .minorTransByte = 1u, /* Modified by function */
            .featureScatterGatherEn = FALSE,
            .featureScatterGatherNextDescriptor = 0u,
            .completeIntEn = FALSE,
            .lpTransConfigPtr = &(eDMALoopTransferConfigType)
            {
                .majorLpIterCnt = rxSize,
                .srcAddrOffsetEn = FALSE,
                .dstAddrOffsetEn = TRUE,
                .minorLpOffset = 0,
                .minorLpLinkEn = FALSE,
                .minorLpLinkChn = 0u,
                .majorLpLinkEn = FALSE,
                .majorLpLinkChn = 0u
            }
        };/* PRQA S 0704 */

        (void)EDMA_LLD_SetLoopTransferConfig(uartState->rxDMAChannel, &dmaConfig_uart);
        // (void)EDMA_LLD_SetMultiTransferConfig(uartState->rxDMAChannel, EDMA_TRANSFER_TYPE_PERIPHTOMEM,
        //                         ((uint32_t)(&(base->BDRM.R)) + 3U), (uint32_t)rxBuff, EDMA_TRANSFER_SIZE_1B,
        //                         1U, rxSize, TRUE);
    }
    else
    {
        (void)EDMA_LLD_SetMultiTransferConfig(uartState->rxDMAChannel, EDMA_TRANSFER_TYPE_PERIPHTOMEM,
                                ((uint32_t)(&(base->BDRM.R)) + 2U), (uint32_t)rxBuff, EDMA_TRANSFER_SIZE_2B,
                                2U, rxSize >> 1U, TRUE);
    }

    /* Call driver function to end the reception when the DMA transfer is done */
    (void)EDMA_LLD_SetUpCallback(uartState->rxDMAChannel,
                                   (eDMACallbackType)(&LINFLEXD_UART_LLD_CompleteReceiveUsingDma),
                                   (void*)(instance)); /*PRQA S 0326*/

    /* Start the DMA channel */
    (void)EDMA_LLD_SetChannelRequest(uartState->rxDMAChannel);

    /* Flush the rx FIFO to discard any junk data received while the driver was idle */
    LINFLEXD_UART_LLD_FlushRxFifo(base, uartState->wordLength);

    /* Enable the receiver */
    LINFLEXD_SetReceiverState(base, TRUE);

    /* Enable rx DMA requests for the current instance */
#if defined(FEATURE_LINFLEXD_HAS_DIFFERENT_MEM_MAP)
    if (s_LINFlexDInstHasFilters[instance])
    {
        base->DMARXE = 1U;
    }
    else
    {
        ((LINFlexD_0IFCR_Type *)base)->DMARXE = 1U;
    }
#else
    base->DMARXE.B.DRE = 1U;
#endif

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_CompleteSendDataUsingDma
 * Description   : Finish up a transmit by completing the process of sending
 * data and disabling the DMA requests. This is a callback for DMA major loop
 * completion, so it must match the DMA callback signature.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
void LINFLEXD_UART_LLD_CompleteSendUsingDma(void * parameter, eDMAChnStatusType status) /*PRQA S 3673*/
{
    uint32_t instance;
    volatile LINFlexD_Type * base;
    linflexd_uart_state_t * uartState;

    instance = ((uint32_t)parameter); /*PRQA S 0326*/
    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Release the DMA channel */
    (void)EDMA_LLD_ClearChannelRequest(uartState->txDMAChannel);/* polyspace RTE:IDP,NIP */

    /* Check if the DMA transfer completed with errors */
    if (status != EDMA_CHN_STATUS_NORMAL)
    {
        uartState->transmitStatus = STATUS_ERROR;
        /* Notify the application that an error occurred */
        if (uartState->txCallback != NULL)
        {
            uartState->txCallback(uartState, UART_EVENT_ERROR, uartState->txCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
        }
        /* Clear remaining bytes count */
        uartState->txSize = 0U;
    }

    /* Invoke the callback when the buffer is finished;
     * Application can provide another buffer inside the callback by calling LINFLEXD_UART_LLD_SetTxBuffer */
    if (uartState->transmitStatus == STATUS_BUSY)
    {
        if (uartState->txCallback != NULL)
        {
            /* Pass the state structure as parameter for internal information retrieval */
            uartState->txCallback(uartState, UART_EVENT_TX_EMPTY, uartState->txCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
        }
    }

    /* If the callback has updated the tx buffer, update the DMA descriptor to continue the transfer;
     * otherwise, stop the current transfer.
     */
    if (uartState->txSize > 0U)
    {
        /* Set the source address and the number of minor loops (bytes to be transfered) */
        EDMA_LLD_SetChnSrcAddr(uartState->txDMAChannel, (uint32_t)(uartState->txBuff));
        EDMA_SetChnMajorLpIterationCount(uartState->txDMAChannel, uartState->txSize);

        /* Now that this tx is set up, clear remaining bytes count */
        uartState->txSize = 0U;

        /* Re-start the channel */
        (void)EDMA_LLD_SetChannelRequest(uartState->txDMAChannel);
    }
    else
    {
        /* Disable tx DMA requests for the current instance */
    #if defined(FEATURE_LINFLEXD_HAS_DIFFERENT_MEM_MAP)
        if (s_LINFlexDInstHasFilters[instance])
        {
            base->DMATXE = 0U;
        }
        else
        {
            ((LINFlexD_0IFCR_Type *)base)->DMATXE = 0U;
        }
    #else
        base->DMATXE.B.DTE = 0U;
    #endif

        /* Disable the transmitter */
        LINFLEXD_SetTransmitterState(base, FALSE);

        /* Signal the synchronous completion object. */
        if (uartState->isTxBlocking == TRUE)
        {
            (void)OSIF_SemaPost(&uartState->txComplete);
        }

        /* Update the busy flag */
        uartState->isTxBusy = FALSE;

        /* If the current reception hasn't been aborted, update the status */
        if (uartState->transmitStatus == STATUS_BUSY)
        {
            uartState->transmitStatus = STATUS_SUCCESS;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_DRV_CompleteReceiveDataUsingDma
 * Description   : Finish up a receive by completing the process of receiving data
 * and disabling the DMA requests. This is a callback for DMA major loop
 * completion, so it must match the DMA callback signature.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
void LINFLEXD_UART_LLD_CompleteReceiveUsingDma(void * parameter, eDMAChnStatusType status) /* PRQA S 3673 */
{
    uint32_t instance;
    volatile LINFlexD_Type * base;
    linflexd_uart_state_t * uartState;

    instance = ((uint32_t)parameter); /*PRQA S 0326*/
    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Release the DMA channel */
    (void)EDMA_LLD_ClearChannelRequest(uartState->rxDMAChannel);/* polyspace RTE:IDP,NIV */

    /* Check if the DMA transfer completed with errors */
    if (status != EDMA_CHN_STATUS_NORMAL)
    {
        uartState->receiveStatus = STATUS_ERROR;
        /* Notify the application that an error occurred */
        if (uartState->rxCallback != NULL)
        {
            uartState->rxCallback(uartState, UART_EVENT_ERROR, uartState->rxCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
        }
        /* Clear remaining bytes count */
        uartState->rxSize = 0U;
    }

    /* Invoke the callback when the buffer is finished */
    if (uartState->receiveStatus == STATUS_BUSY)
    {
        /* Application can provide another buffer inside the callback by calling LINFLEXD_UART_LLD_SetRxBuffer */
        if (uartState->rxCallback != NULL)
        {
            uartState->rxCallback(uartState, UART_EVENT_RX_FULL, uartState->rxCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
        }
    }

    /* If the callback has updated the rx buffer, update the DMA descriptor to continue the transfer;
     * otherwise, stop the current transfer.
     */
    if (uartState->rxSize > 0U)
    {
        /* Set the source address and the number of minor loops (bytes to be transfered) */
        EDMA_LLD_SetChnDestAddr(uartState->rxDMAChannel, (uint32_t)(uartState->rxBuff));

        EDMA_SetChnMajorLpIterationCount(uartState->rxDMAChannel, uartState->rxSize);

        /* Now that this rx is set up, clear remaining bytes count */
        uartState->rxSize = 0U;

        /* Re-start the channel */
        (void)EDMA_LLD_SetChannelRequest(uartState->rxDMAChannel);
    }
    else
    {
        /* Disable rx DMA requests for the current instance */
    #if defined(FEATURE_LINFLEXD_HAS_DIFFERENT_MEM_MAP)
        if (s_LINFlexDInstHasFilters[instance])
        {
            base->DMARXE = 0U;
        }
        else
        {
            ((LINFlexD_0IFCR_Type *)base)->DMARXE = 0U;
        }
    #else
        base->DMARXE.B.DRE = 0U;
    #endif

        /* Disable the receiver */
        LINFLEXD_SetReceiverState(base, FALSE);

        /* Signal the synchronous completion object. */
        if (uartState->isRxBlocking == TRUE)
        {
            (void)OSIF_SemaPost(&uartState->rxComplete);
            uartState->isRxBlocking = FALSE;
        }

        /* Update the information of the module driver state */
        uartState->isRxBusy = FALSE;

        /* If the current reception hasn't been aborted, update the status and call the callback */
        if (uartState->receiveStatus == STATUS_BUSY)
        {
            uartState->receiveStatus = STATUS_SUCCESS;

            /* Call the callback to notify application that the transfer is complete */
            if (uartState->rxCallback != NULL)
            {
                uartState->rxCallback(uartState, UART_EVENT_END_TRANSFER, uartState->rxCallbackParam);/* PRQA S 0315 *//* polyspace RTE:COR */
            }
        }
    }
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_PutData
 * Description   : Write data to the buffer register, according to configured
 * word length.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void LINFLEXD_UART_LLD_PutData(uint32_t instance)
{
    linflexd_uart_state_t * uartState;
    volatile LINFlexD_Type * base;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */
    base = s_LINFlexDBase[instance];

    if((uartState->wordLength == LINFLEXD_UART_7_BITS) || (uartState->wordLength == LINFLEXD_UART_8_BITS))/* polyspace RTE:IDP,NIV */
    {
        /* Transmit the data */
        LINFLEXD_SetTxDataBuffer1Byte(base, *(uartState->txBuff));/* polyspace RTE:IDP,NIV */
        /* Update the state structure */
        ++uartState->txBuff;/* PRQA S 0498 */
        uartState->txSize -= 1U;
    }
    else
    {
        /* Transmit the data and update state structure */
        if(uartState->txSize == 1U)
        {
            LINFLEXD_SetTxDataBuffer2Bytes(base, (uint16_t)(*uartState->txBuff));/* polyspace RTE:IDP,NIV */
            ++uartState->txBuff;/* PRQA S 0498 */
            uartState->txSize -= 1U;
        }
        else
        {
            LINFLEXD_SetTxDataBuffer2Bytes(base, *((const uint16_t*)uartState->txBuff)); /*PRQA S 0310,3305 *//* polyspace RTE:IDP,NIV */
            /* Move the pointer twice */
            ++uartState->txBuff;/* PRQA S 0498 */
            ++uartState->txBuff;/* PRQA S 0498 */
            uartState->txSize -= 2U;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_GetData
 * Description   : Read data from the buffer register, according to configured
 * word length.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void LINFLEXD_UART_LLD_GetData(uint32_t instance)
{
    linflexd_uart_state_t * uartState;
    const volatile LINFlexD_Type * base;

    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */
    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */

    if((uartState->wordLength == LINFLEXD_UART_7_BITS) || (uartState->wordLength == LINFLEXD_UART_8_BITS))/* polyspace RTE:IDP,NIV */
    {
        /* Get the data */
        *(uartState->rxBuff) = LINFLEXD_GetRxDataBuffer1Byte(base);/* polyspace RTE:IDP,NIV */
        /* Update the state structure */
        ++uartState->rxBuff;/* PRQA S 0498 */
        uartState->rxSize -= 1U;
    }
    else
    {
        /* Get the data and update state structure */
        if(uartState->rxSize == 1U)
        {
            *(uartState->rxBuff) = (uint8_t)(LINFLEXD_GetRxDataBuffer2Bytes(base));/* polyspace RTE:IDP,NIV *//* polyspace RTE:IDP,NIV */
            ++uartState->rxBuff;/* PRQA S 0498 */
            uartState->rxSize -= 1U;
        }
        else
        {
            *((uint16_t*)(uartState->rxBuff)) = LINFLEXD_GetRxDataBuffer2Bytes(base); /*PRQA S 0310,3305 *//* polyspace RTE:IDP,NIV */
            /* Move the pointer twice */
            ++uartState->rxBuff;/* PRQA S 0498 */
            ++uartState->rxBuff;/* PRQA S 0498 */
            uartState->rxSize -= 2U;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_LLD_FlushRxFifo
 * Description   : Flushes the rx FIFO.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void LINFLEXD_UART_LLD_FlushRxFifo(const volatile LINFlexD_Type *base, linflexd_uart_word_length_t wordLen)
{
    uint16_t dummy;

    if((wordLen == LINFLEXD_UART_7_BITS) || (wordLen == LINFLEXD_UART_8_BITS))
    {
        volatile const uint8_t *fifoBase;

        /* Get the address of the FIFO */
        fifoBase = (volatile const uint8_t *)(&(base->BDRM.R));/* PRQA S 0751 */
#ifdef CORE_BIG_ENDIAN
        fifoBase = &fifoBase[3];
#endif

        /* Four dummy reads, to flush the FIFO contents */
        dummy = (uint16_t)(*fifoBase); /*PRQA S 2982*//* polyspace RTE:IDP,NIV */
        dummy = (uint16_t)(*fifoBase); /*PRQA S 2982*//* polyspace RTE:IDP,NIV */
        dummy = (uint16_t)(*fifoBase); /*PRQA S 2982*//* polyspace RTE:IDP,NIV */
        dummy = (uint16_t)(*fifoBase);/* polyspace RTE:IDP,NIV */
    }
    else
    {
        volatile const uint16_t *fifoBase;

        /* Get the address of the FIFO */
        fifoBase = (volatile const uint16_t *)(&(base->BDRM.R)); /* PRQA S 0310 */
#ifdef CORE_BIG_ENDIAN
        fifoBase = &fifoBase[1];
#endif

        /* Four dummy reads, to flush the FIFO contents */
        dummy = (uint16_t)(*fifoBase); /*PRQA S 2982*//* polyspace RTE:IDP,NIV */
        dummy = (uint16_t)(*fifoBase); /*PRQA S 2982*//* polyspace RTE:IDP,NIV */
        dummy = (uint16_t)(*fifoBase); /*PRQA S 2982*//* polyspace RTE:IDP,NIV */
        dummy = (uint16_t)(*fifoBase);/* polyspace RTE:IDP,NIV */
    }
    (void)dummy; /* PRQA S 3119 */
}



/* Implementation of LINFlexD0 rx handler named in startup code. */
static void LINflexd0_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART0);
}

/* Implementation of LINFlexD0 tx handler named in startup code. */
static void LINflexd0_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART0);
}

/* Implementation of LINFlexD0 error handler named in startup code. */
static void LINflexd0_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART0);
}

/* Implementation of LINFlexD1 rx handler named in startup code. */
static void LINflexd1_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART1);
}

/* Implementation of LINFlexD1 tx handler named in startup code. */
static void LINflexd1_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART1);
}

/* Implementation of LINFlexD1 error handler named in startup code. */
static void LINflexd1_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART1);
}

/* Implementation of LINFlexD2 rx handler named in startup code. */
static void LINflexd2_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART2);
}

/* Implementation of LINFlexD2 tx handler named in startup code. */
static void LINflexd2_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART2);
}

/* Implementation of LINFlexD2 error handler named in startup code. */
static void LINflexd2_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART2);
}
#if defined RESOURCE_SUPPORT_LINFLEXD_3
/* Implementation of LINFlexD3 rx handler named in startup code. */
static void LINflexd3_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART3);
}

/* Implementation of LINFlexD3 tx handler named in startup code. */
static void LINflexd3_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART3);
}

/* Implementation of LINFlexD3 error handler named in startup code. */
static void LINflexd3_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART3);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_4
/* Implementation of LINFlexD4 rx handler named in startup code. */
static void LINflexd4_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART4);
}

/* Implementation of LINFlexD4 tx handler named in startup code. */
static void LINflexd4_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART4);
}

/* Implementation of LINFlexD4 error handler named in startup code. */
static void LINflexd4_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART4);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_5
/* Implementation of LINFlexD5 rx handler named in startup code. */
static void LINflexd5_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART5);
}

/* Implementation of LINFlexD5 tx handler named in startup code. */
static void LINflexd5_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART5);
}

/* Implementation of LINFlexD5 error handler named in startup code. */
static void LINflexd5_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART5);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_6
/* Implementation of LINFlexD6 rx handler named in startup code. */
static void LINflexd6_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART6);
}

/* Implementation of LINFlexD6 tx handler named in startup code. */
static void LINflexd6_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART6);
}

/* Implementation of LINFlexD6 error handler named in startup code. */
static void LINflexd6_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART6);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_7
/* Implementation of LINFlexD7 rx handler named in startup code. */
static void LINflexd7_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART7);
}

/* Implementation of LINFlexD7 tx handler named in startup code. */
static void LINflexd7_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART7);
}

/* Implementation of LINFlexD7 error handler named in startup code. */
static void LINflexd7_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART7);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_8
/* Implementation of LINFlexD8 rx handler named in startup code. */
static void LINflexd8_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART8);
}

/* Implementation of LINFlexD8 tx handler named in startup code. */
static void LINflexd8_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART8);
}

/* Implementation of LINFlexD8 error handler named in startup code. */
static void LINflexd8_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART8);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_9
/* Implementation of LINFlexD9 rx handler named in startup code. */
static void LINflexd9_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART9);
}

/* Implementation of LINFlexD9 tx handler named in startup code. */
static void LINflexd9_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART9);
}

/* Implementation of LINFlexD9 error handler named in startup code. */
static void LINflexd9_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART9);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_10
/* Implementation of LINFlexD10 rx handler named in startup code. */
static void LINflexd10_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART10);
}

/* Implementation of LINFlexD10 tx handler named in startup code. */
static void LINflexd10_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART10);
}

/* Implementation of LINFlexD10 error handler named in startup code. */
static void LINflexd10_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART10);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_11
/* Implementation of LINFlexD11 rx handler named in startup code. */
static void LINflexd11_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART11);
}

/* Implementation of LINFlexD11 tx handler named in startup code. */
static void LINflexd11_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART11);
}

/* Implementation of LINFlexD11 error handler named in startup code. */
static void LINflexd11_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART11);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_12
/* Implementation of LINFlexD12 rx handler named in startup code. */
static void LINflexd12_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART12);
}

/* Implementation of LINFlexD12 tx handler named in startup code. */
static void LINflexd12_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART12);
}

/* Implementation of LINFlexD12 error handler named in startup code. */
static void LINflexd12_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART12);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_14
/* Implementation of LINFlexD14 rx handler named in startup code. */
static void LINflexd14_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART14);
}

/* Implementation of LINFlexD14 tx handler named in startup code. */
static void LINflexd14_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART14);
}

/* Implementation of LINFlexD14 error handler named in startup code. */
static void LINflexd14_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART14);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_15
/* Implementation of LINFlexD15 rx handler named in startup code. */
static void LINflexd15_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART15);
}

/* Implementation of LINFlexD15 tx handler named in startup code. */
static void LINflexd15_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART15);
}

/* Implementation of LINFlexD15 error handler named in startup code. */
static void LINflexd15_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART15);
}
#endif
#if defined RESOURCE_SUPPORT_LINFLEXD_16
/* Implementation of LINFlexD16 rx handler named in startup code. */
static void LINflexd16_UART_RxIRQHandler(void)
{
    LINFLEXD_UART_LLD_RxIRQHandler((uint32_t)INST_LINFLEXD_UART16);
}

/* Implementation of LINFlexD16 tx handler named in startup code. */
static void LINflexd16_UART_TxIRQHandler(void)
{
    LINFLEXD_UART_LLD_TxIRQHandler((uint32_t)INST_LINFLEXD_UART16);
}

/* Implementation of LINFlexD16 error handler named in startup code. */
static void LINflexd16_UART_ErrIRQHandler(void)
{
    LINFLEXD_UART_LLD_ErrIRQHandler((uint32_t)INST_LINFLEXD_UART16);
}
#endif

/* Rx ISR array for LINFlexD UART driver */
const IntrHandle g_uartLINFlexDRxIsr[LINFLEXD_MAX] = { /* PRQA S 1514 */
    &LINflexd0_UART_RxIRQHandler,
    &LINflexd1_UART_RxIRQHandler,
    &LINflexd2_UART_RxIRQHandler,
#ifdef RESOURCE_SUPPORT_LINFLEXD_3
    &LINflexd3_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_4
    &LINflexd4_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_5
    &LINflexd5_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_6
    &LINflexd6_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_7
    &LINflexd7_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_8
    &LINflexd8_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_9
    &LINflexd9_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_10
    &LINflexd10_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_11
    &LINflexd11_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_12
    &LINflexd12_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_14
    &LINflexd14_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_15
    &LINflexd15_UART_RxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_16
    &LINflexd16_UART_RxIRQHandler,
#endif
};

/* Tx ISR array for LINFlexD UART driver */
const IntrHandle g_uartLINFlexDTxIsr[LINFLEXD_MAX] = { /* PRQA S 1514 */
    &LINflexd0_UART_TxIRQHandler,
    &LINflexd1_UART_TxIRQHandler,
    &LINflexd2_UART_TxIRQHandler,

#ifdef RESOURCE_SUPPORT_LINFLEXD_3
    &LINflexd3_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_4
    &LINflexd4_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_5
    &LINflexd5_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_6
    &LINflexd6_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_7
    &LINflexd7_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_8
    &LINflexd8_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_9
    &LINflexd9_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_10
    &LINflexd10_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_11
    &LINflexd11_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_12
    &LINflexd12_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_14
    &LINflexd14_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_15
    &LINflexd15_UART_TxIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_16
    &LINflexd16_UART_TxIRQHandler,
#endif
};

/* Err ISR array for LINFlexD UART driver */
const IntrHandle g_uartLINFlexDErrIsr[LINFLEXD_MAX] = { /* PRQA S 1514 */
    &LINflexd0_UART_ErrIRQHandler,
    &LINflexd1_UART_ErrIRQHandler,
    &LINflexd2_UART_ErrIRQHandler,

#ifdef RESOURCE_SUPPORT_LINFLEXD_3
    &LINflexd3_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_4
    &LINflexd4_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_5
    &LINflexd5_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_6
    &LINflexd6_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_7
    &LINflexd7_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_8
    &LINflexd8_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_9
    &LINflexd9_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_10
    &LINflexd10_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_11
    &LINflexd11_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_12
    &LINflexd12_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_14
    &LINflexd14_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_15
    &LINflexd15_UART_ErrIRQHandler,
#endif
#ifdef RESOURCE_SUPPORT_LINFLEXD_16
    &LINflexd16_UART_ErrIRQHandler,
#endif
};

status_t LINFLEXD_UART_LLD_StartSendUsingDmaLoop(uint32_t instance,
                                                    const uint8_t * txBuff,
                                                    uint32_t txSize)
{
    volatile LINFlexD_Type * base;
    linflexd_uart_state_t * uartState;

    base = s_LINFlexDBase[instance];/* polyspace RTE:OBAI */
    uartState = (linflexd_uart_state_t *)s_uartLINFlexDStatePtr[instance];/* polyspace RTE:OBAI */

    /* Check it's not busy transmitting data from a previous function call */
    if (uartState->isTxBusy == TRUE)/* polyspace RTE:IDP,NIV */
    {
        return STATUS_BUSY;
    }

    /* Check the validity of the parameters */
    DEV_ASSERT(txSize > 0U);
    if(!((uartState->wordLength == LINFLEXD_UART_7_BITS) || (uartState->wordLength == LINFLEXD_UART_8_BITS)))
    {
        /* The size of the buffer should be an even number for DMA transfers with 15/16 bits word length */
        DEV_ASSERT((txSize & 1U) == 0U);
    }

    /* Update state structure */
    uartState->txBuff = txBuff;
    uartState->txSize = 0U;
    uartState->isTxBusy = TRUE;
    uartState->transmitStatus = STATUS_BUSY;

    /* Configure the transfer control descriptor for the DMA channel */
    if((uartState->wordLength == LINFLEXD_UART_7_BITS) || (uartState->wordLength == LINFLEXD_UART_8_BITS))
    {
        /* Dma configuration structure */
        eDMATransferConfigType dmaConfig_uart_send =
        {
            .srcAddr = (uint32_t)txBuff , /* Modified by function */
            .destAddr = ((uint32_t)(&(base->BDRL.R)) + 3U), /* Modified by function */
            .srcTransDataSize = EDMA_TRANSFER_SIZE_1B,
            .destTransDataSize = EDMA_TRANSFER_SIZE_1B,
            .srcAddrOffset = (int16_t)sizeof(uint8_t),
            .destAddrOffset = 0,
            .srcAddrAdjustLast = 0,
            .destAddrAdjustLast = 0, /* Modified by function */
            .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
            .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
            .minorTransByte = 1u, /* Modified by function */
            .featureScatterGatherEn = FALSE,
            .featureScatterGatherNextDescriptor = 0u,
            .completeIntEn = FALSE,
            .lpTransConfigPtr = &(eDMALoopTransferConfigType)
            {
                .majorLpIterCnt = txSize,
                .srcAddrOffsetEn = FALSE,
                .dstAddrOffsetEn = TRUE,
                .minorLpOffset = 0,
                .minorLpLinkEn = FALSE,
                .minorLpLinkChn = 0u,
                .majorLpLinkEn = FALSE,
                .majorLpLinkChn = 0u
            }
        };/* PRQA S 0704 */

        eDMATransferConfigType dmaConfig_uart_send_linc =
        {
            .srcAddr = (uint32_t)txBuff , /* Modified by function */
            .destAddr = ((uint32_t)(&(base->BDRL.R)) + 3U), /* Modified by function */
            .srcTransDataSize = EDMA_TRANSFER_SIZE_1B,
            .destTransDataSize = EDMA_TRANSFER_SIZE_1B,
            .srcAddrOffset = (int16_t)sizeof(uint8_t),
            .destAddrOffset = 0,
            .srcAddrAdjustLast = 0,
            .destAddrAdjustLast = 0, /* Modified by function */
            .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
            .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
            .minorTransByte = 1u, /* Modified by function */
            .featureScatterGatherEn = FALSE,
            .featureScatterGatherNextDescriptor = 0u,
            .completeIntEn = FALSE,
            .lpTransConfigPtr = &(eDMALoopTransferConfigType)
            {
                .majorLpIterCnt = txSize,
                .srcAddrOffsetEn = FALSE,
                .dstAddrOffsetEn = TRUE,
                .minorLpOffset = 0,
                .minorLpLinkEn = FALSE,
                .minorLpLinkChn = 0u,
                .majorLpLinkEn = FALSE,
                .majorLpLinkChn = 0u
            }
        };/* PRQA S 0704 */

        (void)EDMA_LLD_SetLoopTransferConfig(uartState->txDMAChannel, &dmaConfig_uart_send);
        EDMA_SetChnDisRequestsOnTransferComplete(uartState->txDMAChannel,TRUE);
        (void)EDMA_LLD_SetLoopTransferConfig(uartState->txLinkDMAChannel, &dmaConfig_uart_send_linc);
        EDMA_SetChnDisRequestsOnTransferComplete(uartState->txLinkDMAChannel,TRUE);
    }

    return STATUS_SUCCESS;
}
