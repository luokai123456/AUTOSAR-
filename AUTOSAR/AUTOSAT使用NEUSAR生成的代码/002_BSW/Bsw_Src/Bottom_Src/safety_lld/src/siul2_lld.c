/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3007PT
* DESCRIPTION : CCFC3007PT SIUL2 low level drivers code
* HISTORY     : Initial version
* @file     siul2_lld.c
* @version  1.0
* @date     2023 - 04 - 17
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
#include "siul2_lld.h" /* PRQA S 0380 */
#include "Saf_MemMap.h"
#ifdef RESOURCE_SUPPORT_SIUL2_IP
/* EIRQ interrupt callback function */
SAF_SEC_VAR_NO_INIT
static SafcallBackFunction eirq_cb[EIRQ_MAX_NUM];

/*
 * @brief Initializes the pad with the given configuration structure
 *
 * This function configures the pad with the options provided in the
 * given structure.
 *
 * @param[in] pinIndex the index of pad
 * @param[in] config the configuration structure
  */
SAF_SEC_CODE
status_t SIUL2_LLD_InitPad(pin_index_t pinIndex, const pad_control_config_t *config)
{
    SIUL2_MSCR_IO_tag mscr_io_value = {0U};/*PRQA S 3604*/
    SIUL2_MSCR_MUX_tag mscr_mux_value = {0U};/*PRQA S 3604*/

    if (pinIndex >= SIUL2_MSCR_MAX_CNT)
    {
        return STATUS_ERROR;
    }

    mscr_io_value.B.OERC = (uint8_t)config->drive_strength_select;
    mscr_io_value.B.ODC  = (uint8_t)config->output_derive_control;
    mscr_io_value.B.SMC  = (uint8_t)config->safe_mode;
    mscr_io_value.B.APC  = (uint8_t)config->analog_pad_control;
    mscr_io_value.B.ILS  = (uint8_t)config->input_level_select;
    mscr_io_value.B.IBE  = (uint8_t)config->input_buffer_control;
    mscr_io_value.B.HYS  = (uint8_t)config->hysteresis_control;
    mscr_io_value.B.SSS  = (uint8_t)config->sss_config;

    if (config->pull_config == PAD_INTERNAL_PULL_DISABLED)
    {
        mscr_io_value.B.WPDE = 0U;
        mscr_io_value.B.WPUE = 0U;
    }
    else
    {
        if (config->pull_config == PAD_INTERNAL_PULLDOWN_ENABLED)
        {
            mscr_io_value.B.WPDE = 1U;
            mscr_io_value.B.WPUE = 0U;
        }
        else
        {
            mscr_io_value.B.WPDE = 0U;
            mscr_io_value.B.WPUE = 1U;
        }
    }

    mscr_io_value.B.INV = (uint8_t)config->invert_output;
    SIUL2.MSCR_IO[pinIndex].R = mscr_io_value.R;

    /* configures mscr_mux register if pin mux is enabled */
    if (config->mux_config.pin_mux_enable == TRUE)
    {
        mscr_mux_value.B.INV = (uint8_t)config->mux_config.invert_output;
        mscr_mux_value.B.SSS = (uint8_t)config->mux_config.mux_sss_config;

        SIUL2.MSCR_MUX[config->mux_config.pin_mux_index - SIUL2_MSCR_MAX_CNT].R = mscr_mux_value.R; /* polyspace RTE:IDP,OBAI */
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Write the corresponding pin level
 *
 * This function writes the corresponding pin level
 *
 * @param[in] pinIndex the index of pin
 * @param[in] pinLevel the value of pin
 */
SAF_SEC_CODE
status_t SIUL2_LLD_WritePin(pin_index_t pinIndex, pin_level_t pinLevel)
{
    if (pinIndex >= SIUL2_MSCR_MAX_CNT)
    {
        return STATUS_ERROR;
    }

    SIUL2.GPDO[pinIndex].R = (uint8_t)pinLevel;

    return STATUS_SUCCESS;
}

/*
 * @brief read the corresponding pin level
 *
 * This function reads the corresponding pin level
 *
 * @param[in] pinIndex the index of pin
 */
SAF_SEC_CODE
pin_level_t SIUL2_LLD_ReadPin(pin_index_t pinIndex)
{
    pin_level_t level = PIN_UNKNOWN;

    if (pinIndex >= SIUL2_MSCR_MAX_CNT)
    {
        return PIN_UNKNOWN;
    }

    if (SIUL2.GPDI[pinIndex].R == 1U)/* polyspace RTE:NIV */
    {
        level = PIN_HIGH;
    }
    else
    {
        level = PIN_LOW;
    }

    return level;
}

/*
 * @brief toggle the corresponding pin level
 *
 * This function toggles the corresponding pin level
 *
 * @param[in] pinIndex the index of pin
 */
SAF_SEC_CODE
status_t SIUL2_LLD_TogglePin(pin_index_t pinIndex) /* PRQA S 1503 */
{
    if (pinIndex >= SIUL2_MSCR_MAX_CNT)
    {
        return STATUS_ERROR;
    }

    SIUL2.GPDO[pinIndex].B.PDO ^= SIUL2.GPDI[pinIndex].B.PDI; /* PRQA S 0404 */ /* polyspace RTE:NIV */

    return STATUS_SUCCESS;
}

/*
 * @brief Configures the internal pull resistor
 *
 * This function configures the internal pull resistor
 *
 * @param[in] pinIndex   port pin number
 * @param[in] pullConfig the pull configuration
 */
SAF_SEC_CODE
status_t SIUL2_LLD_SetPinPullSel(pin_index_t pinIndex, pad_pull_config_t pullConfig) /* PRQA S 1503 */
{
    uint32_t regValue = 0U;

    if (pinIndex >= SIUL2_MSCR_MAX_CNT)
    {
        return STATUS_ERROR;
    }

    if (pullConfig == PAD_INTERNAL_PULLDOWN_ENABLED)
    {
        SIUL2.MSCR_IO[pinIndex].B.WPDE = 1U;
        SIUL2.MSCR_IO[pinIndex].B.WPUE = 0U;
    }
    else if (pullConfig == PAD_INTERNAL_PULLUP_ENABLED)
    {
        SIUL2.MSCR_IO[pinIndex].B.WPUE = 1U;
        SIUL2.MSCR_IO[pinIndex].B.WPDE = 0U;
    }
    else
    {
        SIUL2.MSCR_IO[pinIndex].B.WPUE = 0U;
        SIUL2.MSCR_IO[pinIndex].B.WPDE = 0U;
    }

    SIUL2.MSCR_IO[pinIndex].R = regValue;

    return STATUS_SUCCESS;
}

/*
 * @brief Configures the output drvie control
 *
 * This function configure the output drive control for the pin
 *
 * @param[in] pinIndex  port pin number
 * @param[in] driveCtrl the output drive control
 */
SAF_SEC_CODE
status_t SIUL2_LLD_SetPinOutputDriveControl(pin_index_t pinIndex, pad_output_drvie_control_t driveCtrl) /* PRQA S 1503 */
{
    if (pinIndex >= SIUL2_MSCR_MAX_CNT)
    {
        return STATUS_ERROR;
    }

    SIUL2.MSCR_IO[pinIndex].B.ODC = 0U;
    SIUL2.MSCR_IO[pinIndex].B.ODC = (uint8_t)driveCtrl;

    return STATUS_SUCCESS;
}

/*
 * @brief Configures the input buffer
 *
 * This function configures the input buffer
 *
 * @param[in] pinIndex port pin number
 * @param[in] enable   enable or disable output buffer
 */
SAF_SEC_CODE
status_t SIUL2_LLD_SetPinInputBuffer(uint16_t pinIndex, boolean enable) /* PRQA S 1503 */
{
    if (pinIndex >= SIUL2_MSCR_MAX_CNT)
    {
        return STATUS_ERROR;
    }

    if (enable == TRUE)
    {
        SIUL2.MSCR_IO[pinIndex].B.IBE = 1U;
    }
    else
    {
        SIUL2.MSCR_IO[pinIndex].B.IBE = 0U;
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Configures the interrupt filter
 *
 * This function configures the interrupt filter clock prescaler
 *
 * @param[in] prescaler interrupt filter clock prescaler
 */
SAF_SEC_CODE
void SIUL2_LLD_ConfigFilterClk(uint8_t preScaler)
{
    SIUL2.IFCPR.R = (uint32_t)preScaler & 0xfU;
}

/*
 * @brief Configures the soc register
 *
 * This function configures the soc regster
 *
 * @param[in] socConfig soc configuration
 */
SAF_SEC_CODE
void SIUL2_LLD_ConfigSoc(const siul2_soc_config_t *socConfig) /* PRQA S 1503 */
{
    SIUL2.SCR0.B.FEC_MODE    = (uint8_t)socConfig->fec_mode;
    SIUL2.SCR0.B.ESR0_ASSERT = socConfig->esr0_assert;
}

/*
 * @brief Global Interrupt SIUL2 external interrupt 0 Handler
 *
 * In case of interrupt checks the triggered source for
 * EIRQ0 | EIRQ1 | EIRQ2 | EIRQ3 | 
 * EIRQ4 | EIRQ5 | EIRQ6 | EIRQ7 
 */
SAF_SEC_CODE
void SAF_SIUL2_EIRQ_0_IRQHandler(void)
{
    uint32_t eirq_n, tmp_disr0;

    tmp_disr0 = SIUL2.DISR0.R;

    for (eirq_n = EIRQ0; eirq_n <= EIRQ7; eirq_n++)
    {
        if ((tmp_disr0 & (1UL << eirq_n)) != 0UL)
        {
            SIUL2.DISR0.R = (1UL << eirq_n);
            if (eirq_cb[eirq_n] != NULL_PTR)
            {
                eirq_cb[eirq_n](NULL_PTR);
            }
        }
    }
}

/*
 * @brief Global Interrupt SIUL2 external interrupt 1 Handler
 *
 * In case of interrupt checks the triggered source for
 * EIRQ8  | EIRQ9  | EIRQ10 | EIRQ11 |
 * EIRQ12 | EIRQ13 | EIRQ14 | EIRQ15
 */
SAF_SEC_CODE
void SAF_SIUL2_EIRQ_1_IRQHandler(void)
{
    uint32_t eirq_n, tmp_disr0;

    tmp_disr0 = SIUL2.DISR0.R;

    for (eirq_n = EIRQ8; eirq_n <= EIRQ15; eirq_n++)
    {
        if ((tmp_disr0 & (1UL << eirq_n)) != 0UL)
        {
            SIUL2.DISR0.R = (1UL << eirq_n);
            if (eirq_cb[eirq_n] != NULL_PTR)
            {
                eirq_cb[eirq_n](NULL_PTR);
            }
        }
    }
}

/*
 * @brief Configures the eirq pin interrupt or dma request
 *
 * This function configures the eirq pin interrupt or dma request
 *
 * @param[in] reqConfig the eriq pin request configration
 */
SAF_SEC_CODE
void SIUL2_LLD_SetExtRequest(const siul2_request_config_t *reqConfig)
{
    uint32_t eirqIndexReg = (uint32_t)(1UL << reqConfig->eirq_index); /* polyspace RTE:SHF */

    if (reqConfig->event_edge_sel != SAF_SIUL2_EVENT_DISABLED)
    {
        SIUL2.DISR0.R  |= eirqIndexReg; /* clear eirq pin status flag */
        SIUL2.DIRER0.R |= eirqIndexReg;

        /* select dma or int  */
        if (reqConfig->request_sel == SIUL2_REQ_USING_INT)
        {
            SIUL2.DIRSR0.R &= ~eirqIndexReg;;
        }
        else
        {
            SIUL2.DIRSR0.R |= eirqIndexReg;;
        }

        /* select request edge trigger */
        if (reqConfig->event_edge_sel == SAF_SIUL2_EVENT_RISING_EDGE)
        {
            SIUL2.IREER0.R |= eirqIndexReg;
            SIUL2.IFEER0.R &= ~eirqIndexReg;
        }
        else if (reqConfig->event_edge_sel == SAF_SIUL2_EVENT_FALLING_EDGE)
        {
            SIUL2.IREER0.R &= ~eirqIndexReg;
            SIUL2.IFEER0.R |= eirqIndexReg;
        }
        else
        {
            SIUL2.IREER0.R |= eirqIndexReg;
            SIUL2.IFEER0.R |= eirqIndexReg;
        }

        /* enable or disbale filter */
        if (reqConfig->digital_filter_enable == TRUE)
        {
            SIUL2.IFER0.R |= eirqIndexReg;
            SIUL2.IFMCR[reqConfig->eirq_index].R = (uint32_t)reqConfig->filter_max_count & 0xFU;
        }
        else
        {
            SIUL2.IFER0.R &= ~eirqIndexReg;
        }

        /* register callback function */
        if (reqConfig->eirq_cb != NULL_PTR)
        {
            eirq_cb[reqConfig->eirq_index] = reqConfig->eirq_cb; /*PRQA S 2844*/ /* polyspace RTE:OBAI */
        }
    }
}

/*
 * @brief Clears the eirq pin interrupt or dma status flag
 *
 * This function clear the eirq pin interrupt or dma status flag
 *
 * @param[in] eirqPinIndex the index number of eriq pin
 */
SAF_SEC_CODE
status_t SIUL2_LLD_ClearPinExtRequestFlag(uint8_t eirqIndex) /* PRQA S 1503 */
{
    if (eirqIndex >= EIRQ_MAX_NUM)
    {
        return STATUS_ERROR;
    }

    SIUL2.DISR0.R |= (1UL << eirqIndex);

    return STATUS_SUCCESS;
}

/*
 * @brief Gets the eirq pin interrupt or dma status flag
 *
 * This function gets the eirq pin interrupt or dma status flag
 *
 * @param[in] eirqPinIndex the index number of eriq pin
 */
SAF_SEC_CODE
status_t SIUL2_LLD_GetPinExtRequestFlag(uint8_t eirqIndex) /* PRQA S 1503 */
{
	status_t ret = STATUS_SUCCESS;

    if (eirqIndex >= EIRQ_MAX_NUM)
    {
        ret = STATUS_ERROR;
    }
    else
    {
        if ((SIUL2.DISR0.R & (1UL << eirqIndex)) == 1U)
        {
            ret = STATUS_SUCCESS;
        }
        else
        {
            ret = STATUS_ERROR;
        }
    }

    return ret;
}

/*
 * @brief Gets the eirq pins interrupt or dma status flag
 *
 * This function gets the eirq pins interrupt or dma status flag
 */
SAF_SEC_CODE
uint32_t SIUL2_LLD_GetExtRequestFlag(void) /* PRQA S 1503 */
{
    return SIUL2.DISR0.R;
}

/*
 * @brief Clears the eirq pins interrupt or dma status flag
 *
 * This function clears the eirq pins interrupt or dma status flag
 */
SAF_SEC_CODE
void SIUL2_LLD_ClearExtRequestFlag(void) /* PRQA S 1503 */
{
    SIUL2.DISR0.R = 0xFFFFUL;
}

/*
 * @brief Set the User Access Allowed bit of an IP module
 *
 * The registers in the module under protection can be accessed in the mode defined
 * for the module registers without any additional restrictions
 */
SAF_SEC_CODE
void SIUL2_LLD_SetUserAccessAllowed(void)
{
    SIUL2_REG_PROT.GCR.B.UAA = 1U;
}

#endif /* RESOURCE_SUPPORT_SIUL2_IP */
