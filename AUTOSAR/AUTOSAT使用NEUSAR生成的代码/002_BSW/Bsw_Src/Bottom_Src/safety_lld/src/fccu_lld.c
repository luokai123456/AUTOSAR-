/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx FCCU low level drivers code
* HISTORY     : Initial version
* @file     fccu_lld.c
* @version  1.0
* @date     2023 - 04 - 24
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/

#include "fccu_lld.h" /* PRQA S 0380 */
#include "intc_lld.h"
#include "memu_lld.h"
#include "Saf_MemMap.h"
/*PRQA S 0491,1472,1682,1862,3400,3401,4322,4422 EOF*/
/* static variables */
SAF_FCCU_SEC_VAR_NO_INIT
static fcc_isr_state_t s_irqStatus;
SAF_FCCU_SEC_VAR_NO_INIT
static fccu_rf_config_t const *s_rfConfigurations;
SAF_FCCU_SEC_VAR_NO_INIT
static uint32_t s_startupValue;

/*
 * @brief Startup FCCU callback
 *
 * This function call the startup function, adapt fccu channel 16 ~ 24
 *
 * @param[in] value: switch value , 1 use Startup Callback, 0 use custom Callback
 * @retval    STATUS_SUCCESS: success run operation
 *            STATUS_ERROR:  operation error
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_StartupCallbackSwitch(uint32_t value) /* PRQA S 1505 */
{
	status_t status = STATUS_SUCCESS;
	s_startupValue = value;
	if (s_startupValue != value)/* PRQA S 2992,2996 */
	{
		status = STATUS_ERROR;
	}
	return status;
}

/*
 * @brief Clear Fault Status Register
 *
 * This function use to clear the rf fault status register
 *
 * @param[in] faultIndex: FCCU failure input signal index
 * @retval    STATUS_SUCCESS: success clearing faults
 *            STATUS_TIMEOUT: timeout operation
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_ClearFaults(uint8_t faultIndex) /* PRQA S 1505 */
{
    uint8_t index, regIdx, bitPos;
    uint32_t timeout;
    status_t status = STATUS_SUCCESS;

    if (faultIndex >= SAF_FCCU_MAX_FAULTS_NO)
    {
        for (index = 0U; index < SAF_FCCU_RF_MAX_GROUP; index++)
        {
            /* set recoverable fault key */
            FCCU.RFK.R = SAF_FCCU_RECOVERABLE_FAULT_KEY;
            /* clear all faults */
            FCCU.RF_S[index].R = 0xFFFFFFFFU;
            /* wait operation 12 done */
            timeout = SAF_FCCU_OP_TIMEOUT_CONFIG;

            while ((FCCU.CTRL.B.OPS == (uint8_t)SAF_FCCU_OPS_IN_PROGRESS) && (timeout > 0U))
            {
                timeout--;
            }

            /* timeout happen */
            if (timeout == 0U)
            {
                status = STATUS_TIMEOUT;
                break;
            }
        }
    }
    else
    {
        regIdx = faultIndex >> 5U;   /* divide by 32 */
        bitPos = faultIndex & 0x1FU; /* modulo by 32 */

        /* set recoverable fault key */
        FCCU.RFK.R = SAF_FCCU_RECOVERABLE_FAULT_KEY;
        /* clear all faults */
        FCCU.RF_S[regIdx].R = 1UL << bitPos;
        /* wait operation 12 done */
        timeout = SAF_FCCU_OP_TIMEOUT_CONFIG;

        while ((FCCU.CTRL.B.OPS == (uint8_t)SAF_FCCU_OPS_IN_PROGRESS) && (timeout > 0U))
        {
            timeout--;
        }

        /* timeout happen */
        if (timeout == 0U)
        {
            status = STATUS_TIMEOUT;
        }
    }
    return status;
}

/*
 * @brief Run operation
 *
 * This function use to run fcc operation
 *
 * @param[in] opRun: operation run
 * @retval    STATUS_SUCCESS: success run operation
 *            STATUS_TIMEOUT: timeout run operation
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_RunOperation(const SAF_fccu_op_run_t opRun) /* PRQA S 1505 */
{
    status_t status = STATUS_SUCCESS;
    uint32_t timeout = SAF_FCCU_OP_TIMEOUT_CONFIG;

    /* wait for the last operation complete */
    while (((uint8_t)SAF_FCCU_OPS_IN_PROGRESS == FCCU.CTRL.B.OPS) && (timeout != 0U))
    {
        timeout--;
    }

    if (0U == timeout)
    {
        status = STATUS_TIMEOUT;
    }

    if (status == STATUS_SUCCESS)
    {
        /* get operation status */
        switch (opRun)
        {
            case SAF_FCCU_RUN_OP1:/* PRQA S 0570 */
                FCCU.CTRLK.R = SAF_FCCU_UNLOCK_OP1_KEY;
                FCCU.CTRL.R = (uint32_t)SAF_FCCU_RUN_OP1;
                break;
            case SAF_FCCU_RUN_OP2:/* PRQA S 0570 */
                FCCU.CTRLK.R = SAF_FCCU_UNLOCK_OP2_KEY;
                FCCU.CTRL.R = (uint32_t)SAF_FCCU_RUN_OP2;
                break;
            default:
                FCCU.CTRL.R = (uint32_t)opRun;
                break;
        }

        timeout = SAF_FCCU_OP_TIMEOUT_CONFIG;
        /* wait for the last operation complete */
        while (((uint8_t)SAF_FCCU_OPS_IN_PROGRESS == FCCU.CTRL.B.OPS) && (timeout != 0U))
        {
            timeout--;
        }

        if (0U == timeout)
        {
            status = STATUS_TIMEOUT;
        }
    }

    return status;
}

/*
 * @brief Read Recoverable Faults
 *
 * This function update and read recoverable faults
 *
 * @param[in] flags: faults flags
 * @retval    STATUS_SUCCESS: success run operation
 *            STATUS_TIMEOUT: timeout operation
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_ReadFaults(SAF_fccu_faults_flags_t *flags) /* PRQA S 1505 */
{
    uint8_t index;
    status_t status = STATUS_SUCCESS;

    for (index = 0; index < SAF_FCCU_RF_MAX_GROUP; index++)
    {
        status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP10);
        if (STATUS_SUCCESS == status)
        {
            flags->faultsFlags[index] = FCCU.RF_S[index].R;/* polyspace RTE:NIV */
        }
        else
        {
            return status;
        }
    }

    return status;
}

/*
 * @brief Read FCCU state
 *
 * This function use to read fccu state
 *
 * @retval the state of fccu module
 */
SAF_FCCU_SEC_CODE
SAF_fccu_status_t SAF_FCCU_LLD_GetState(void) /* PRQA S 1505 */
{
    status_t status;
    fccu_status_t fccuStatus = (fccu_status_t)SAF_FCCU_UNKNOWN_STATE;

    status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP3);
    if (STATUS_SUCCESS == status)
    {
        switch (FCCU.STAT.B.STATUS)
        {
            case 0U:
                fccuStatus = (fccu_status_t)SAF_FCCU_NORMAL_STATE;
                break;
            case 1U:
                fccuStatus = (fccu_status_t)SAF_FCCU_CONFIG_STATE;
                break;
            case 2U:
                fccuStatus = (fccu_status_t)SAF_FCCU_ALARM_STATE;
                break;
            default:
                fccuStatus = (fccu_status_t)SAF_FCCU_FAULT_STATE;
                break;
        }
    }

    return (SAF_fccu_status_t)fccuStatus;
}

/*
 * @brief Set FCCU into config state
 *
 * This function set fccu into config state
 *
 * @retval STATUS_SUCCESS: success to set fccu in config state
 *         STATUS_TIMEOUT: timeout operation
 *         STATUS_FCCU_ERROR_SET_CONFIG: fail to set fccu in config state
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_SetConfigState(void) /* PRQA S 1505 */
{
    uint8_t index;
    status_t status = STATUS_FCCU_ERROR_OTHER;
    SAF_fccu_status_t fccuStatus;
    fccu_faults_flags_t faultsFlags;
    uint32_t faultsAll = 0UL;
    uint32_t timeout = SAF_FCCU_OP_TIMEOUT_CONFIG;
    uint8_t fccuOpStatus;

    /* Unlock configuration */
    FCCU.TRANS_LOCK.R = SAF_FCCU_TRANSKEY_UNLOCK_VAL;

    fccuStatus = SAF_FCCU_LLD_GetState();
    if (fccuStatus == SAF_FCCU_NORMAL_STATE)
    {
        /* clear all faults */
        status = SAF_FCCU_LLD_ClearFaults(SAF_FCCU_MAX_FAULTS_NO);
        if (STATUS_SUCCESS == status)
        {
            fccuOpStatus = (uint8_t)FCCU.CTRL.B.OPS;
            if ((uint8_t)SAF_FCCU_OPS_SUCCESSFUL != fccuOpStatus)
            {
                /* read FCCU state */
                (void)SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP3);
            }

            /* set fccu to enter config state */
            (void)SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP1);
        }
        fccuStatus = SAF_FCCU_LLD_GetState();
        if (SAF_FCCU_CONFIG_STATE == fccuStatus)
        {
            status = STATUS_SUCCESS;
        }
        else
        {
            status = STATUS_FCCU_ERROR_SET_CONFIG;
        }
    }
    else if (fccuStatus == SAF_FCCU_CONFIG_STATE)
    {
        status = STATUS_SUCCESS;
    }
    else if (fccuStatus == SAF_FCCU_UNKNOWN_STATE)
    {
        status = STATUS_FCCU_ERROR_SET_CONFIG;
    }
    else /* Alarm or Fault State */
    {
        do
        {
            status = SAF_FCCU_LLD_ClearFaults(SAF_FCCU_MAX_FAULTS_NO);
            if (STATUS_SUCCESS == status)
            {
                status = SAF_FCCU_LLD_ReadFaults((SAF_fccu_faults_flags_t *)&faultsFlags);/* PRQA S 0310 */
                if (STATUS_SUCCESS == status)
                {
                    timeout--;
                    for (index = 0U; index < SAF_FCCU_RF_MAX_GROUP; index++)
                    {
                        faultsAll += faultsFlags.faultsFlags[index];/* polyspace RTE:NIVL */
                    }
                }
            }
        } while ((faultsAll != 0U) && (timeout != 0U));

        if (timeout == 0U)
        {
            status = STATUS_TIMEOUT;
        }
        else
        {
            /* set fccu in noraml state */
            (void)SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP2);
            if (SAF_FCCU_NORMAL_STATE != SAF_FCCU_LLD_GetState())
            {
                status = STATUS_FCCU_ERROR_SET_CONFIG;
            }
            else
            {
                /* set fccu in config state */
                (void)SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP1);
                if (SAF_FCCU_CONFIG_STATE != SAF_FCCU_LLD_GetState())
                {
                    status = STATUS_FCCU_ERROR_SET_CONFIG;
                }
                else
                {
                    status = STATUS_SUCCESS;
                }
            }
        }
    }

    return status;
}

/*
 * @brief Set FCCU into normal state
 *
 * @retval STATUS_SUCCESS: set fccu successfully
 *         STATUS_FCCU_ERROR_SET_NORMAL: fails to set fccu state
 *         STATUS_TIMEOUT: run operation timeout
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_SetNormalState(void) /* PRQA S 1505 */
{
    uint32_t index;
    uint32_t faultsAll = 0xFFFFFFFFU;
    uint32_t timeout = SAF_FCCU_OP_TIMEOUT_CONFIG;
    status_t status = STATUS_FCCU_ERROR_OTHER;
    SAF_fccu_status_t fccuStatus;
    fccu_faults_flags_t faultsFlags;

    fccuStatus = SAF_FCCU_LLD_GetState();
    if (SAF_FCCU_NORMAL_STATE == fccuStatus)
    {
        /* fccu already in normal state */
        status = STATUS_SUCCESS;
    }
    else if (SAF_FCCU_CONFIG_STATE == fccuStatus)
    {
        /* set fccu into noraml state */
        (void)SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP2);
        if (SAF_FCCU_NORMAL_STATE == SAF_FCCU_LLD_GetState())
        {
            status = STATUS_SUCCESS;
        }
        else
        {
            status = STATUS_FCCU_ERROR_SET_NORMAL;
        }
    }
    else if ((SAF_FCCU_ALARM_STATE == fccuStatus) || (SAF_FCCU_FAULT_STATE == fccuStatus))
    {
        do
        {
            /* clear all faults */
            status = SAF_FCCU_LLD_ClearFaults(SAF_FCCU_MAX_FAULTS_NO);
            if (STATUS_SUCCESS == status)
            {
                if (STATUS_SUCCESS == SAF_FCCU_LLD_ReadFaults((SAF_fccu_faults_flags_t *)&faultsFlags))/* PRQA S 0310 */
                {
                    for (index = 0; index < SAF_FCCU_RF_MAX_GROUP; index++)
                    {
                        faultsAll += faultsFlags.faultsFlags[index];/* polyspace RTE:NIVL */
                    }
                }
            }

            timeout--;
        } while ((faultsAll != 0U) && (timeout != 0U));

        if (timeout == 0U)
        {
            status = STATUS_TIMEOUT;
        }
        else
        {
            (void)SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP2);
            if (SAF_FCCU_NORMAL_STATE == SAF_FCCU_LLD_GetState())
            {
                status = STATUS_SUCCESS;
            }
            else
            {
                status = STATUS_FCCU_ERROR_SET_NORMAL;
            }
        }
    }
    else
    {
        status = STATUS_FCCU_ERROR_SET_NORMAL;
    }

    return status;
}

/*
 * @brief Defines the preset value of the watchdog timer for the
 *        recovery from the CONFIG state
 *
 *
 * @param[in] to: configuration time-out value
 * @retval STATUS_SUCCESS: set configuration timeout successfully
 *         STATUS_FCCU_ERROR_CONFIG_TIMEOUT: fail to set configuration timeout
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_SetCfgTimeout(uint8_t to) /* PRQA S 1503 */
{
    SAF_fccu_status_t fccuState;
    status_t status;

    fccuState = SAF_FCCU_LLD_GetState();
    if (SAF_FCCU_CONFIG_STATE == fccuState)
    {
        status = SAF_FCCU_LLD_SetNormalState();
        if (STATUS_SUCCESS != status)
        {
            status = STATUS_FCCU_ERROR_CONFIG_TIMEOUT;
        }
        else
        {
            FCCU.CFG_TO.R = to;
        }
    }
    else
    {
        FCCU.CFG_TO.R = to;
        status = STATUS_SUCCESS;
    }

    return status;
}

/*
 * @brief Lock the fccu configuration
 *
 *
 * @param[in] lock: type of lock
 * @retval None
 */
SAF_FCCU_SEC_CODE
void SAF_FCCU_LLD_LockConfig(const SAF_fccu_lock_type_t lock) /* PRQA S 1505 */
{
    switch (lock)
    {
        case SAF_FCCU_TRANSIENTLY_UNLOCK:
            FCCU.TRANS_LOCK.B.TRANSKEY = FCCU_TRANSKEY_UNLOCK_VAL;
            break;
        case SAF_FCCU_TRANSIENTLY_LOCK:
            FCCU.TRANS_LOCK.B.TRANSKEY = FCCU_TRANSKEY_LOCK_VAL;
            break;
        case SAF_FCCU_PERANENTLY_LOCK:
            FCCU.PERMNT_LOCK.B.PERMNTKEY = FCCU_PERMENTKEY_LOCK_VAL;
            break;
        default:
            /* Do nothing */
            break;
    }
}

/*
 * @brief Check fccu IRQ_STAT register
 *
 *
 * @param[in] intStatus: status of interrupt
 * @retval 1: int bit occurs in IRQ_STAT register
 *         0: int bit nor occurs
 */
SAF_FCCU_SEC_CODE
uint8_t SAF_FCCU_LLD_CheckIntStatus(SAF_fccu_int_status_t intStatus) /* PRQA S 1505 */
{
    uint32_t regIrqStat = (uint32_t)FCCU.IRQ_STAT.R;

    regIrqStat &= (1UL << (uint32_t)intStatus);

    return (regIrqStat != 0UL) ? 1U : 0U;
}

/*
 * @brief Clear fccu interrupt flag
 *
 *
 * @param[in] intStatus: status of interrupt
 * @retval None
 */
SAF_FCCU_SEC_CODE
void SAF_FCCU_LLD_ClearIntFlag(SAF_fccu_int_status_t intStatus) /* PRQA S 1505 */
{
    uint32_t regIrqStat;

    FCCU.IRQ_STAT.R = FCCU.IRQ_STAT.R & ~(1UL << (uint32_t)intStatus);
    regIrqStat = (uint32_t)(1UL << (uint32_t)intStatus);
    FCCU.IRQ_STAT.R |= regIrqStat;
}

/*
 * @brief FCCU Alarm Interrupt Callback function
 *
 */
SAF_FCCU_SEC_CODE
static void FCCU_LLD_AlarmIrqCallback(void)
{
    uint8_t index;
    uint8_t reg_index, bit_pos;

    /* Update faults status */
    (void)SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP10);

    for (index = 0U; index < s_irqStatus.rfConfigNu; index++)
    {
        reg_index = s_rfConfigurations[index].channel >> 5U; /* divide by 32 */ /* PRQA S 0491 */  /* polyspace RTE:IDP */
        bit_pos = s_rfConfigurations[index].channel & 0x1FU; /* modulo by 32 */ /* PRQA S 0491 */

        if ((reg_index < SAF_FCCU_RF_MAX_GROUP) && ((FCCU.RF_S[reg_index].R & (1UL << bit_pos)) != 0UL))/* polyspace RTE:NIV */
        {
            /* Clear Fault */
            (void)SAF_FCCU_LLD_ClearFaults(s_rfConfigurations[index].channel);/* PRQA S 0491 */
            if ((s_startupValue == 1U) && (16 <= bit_pos && 24 >= bit_pos) && (reg_index == 0))/* PRQA S 1863,3396,3397 */
            {
            	if (bit_pos < 19)
            	{
            		MEMU_SYSRAM_IRQHandler(NULL_PTR);
            	}
            	else if (bit_pos > 21)
            	{
            		MEMU_FLASH_IRQHandler(NULL_PTR);
            	}
            	else
            	{
            		MEMU_PRRAM_IRQHandler(NULL_PTR);
            	}
            }
            else if (NULL_PTR != s_rfConfigurations[index].callback)/* PRQA S 2004 */
            {
                s_rfConfigurations[index].callback(s_rfConfigurations[index].callbackParam); /* PRQA S 0404 */
            }
            (void)SAF_FCCU_LLD_ClearFaults(s_rfConfigurations[index].channel);
        }
    }
}

/*
 * @brief FCCU Interrupt Handler
 *
 */
SAF_FCCU_SEC_CODE
void FCCU_IRQ_Handler(void)
{
    if (1U == SAF_FCCU_LLD_CheckIntStatus(SAF_FCCU_INT_ALARM))
    {
        FCCU_LLD_AlarmIrqCallback();
        SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    }

    if (1U == SAF_FCCU_LLD_CheckIntStatus(SAF_FCCU_INT_TIMEOUT))
    {
        SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_TIMEOUT);
    }

    if (NULL_PTR != s_irqStatus.SafcallBackFunction)
    {
        s_irqStatus.SafcallBackFunction(s_irqStatus.callBaclParam);
    }
}

SAF_FCCU_SEC_CODE
void FCCU_CFG_TO_IRQ_Handler(void)
{
    if (1U == SAF_FCCU_LLD_CheckIntStatus(SAF_FCCU_INT_ALARM))
    {
        FCCU_LLD_AlarmIrqCallback();
        SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    }

    if (1U == SAF_FCCU_LLD_CheckIntStatus(SAF_FCCU_INT_TIMEOUT))
    {
        SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_TIMEOUT);
    }

    if (NULL_PTR != s_irqStatus.SafcallBackFunction)
    {
        s_irqStatus.SafcallBackFunction(s_irqStatus.callBaclParam);
    }
}

/*
 * @brief Check whether there is an FCCU channel set when entering IVOR
 *
 */

SAF_FCCU_SEC_CODE
uint32_t FCCU_IVOR_Handler(void)
{
	uint32_t ret = 0;
    uint32_t mask0 = 0xfffffff7U;
    uint32_t mask1 = 0xfffff77fU;
    status_t status = STATUS_ERROR;

    status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP10);
    if (status == STATUS_SUCCESS) {
	    ret |= (FCCU.RF_S[0].R & mask0);/* polyspace RTE:NIV */
	    ret |= (FCCU.RF_S[1].R & mask1);/* polyspace RTE:NIV */
    }

    return (uint32_t)(ret == 0U ? 0U : 1U);/* PRQA S 3396 */
}


/*
 * @brief Check whether there is an startuptest when entering IVOR
 *
 */
SAF_FCCU_SEC_CODE
uint32_t FCCU_StartInject_Check(void)
{
	return s_startupValue;
}

/*
 * @brief Set the recoverable fault configuration
 *
 *
 * @param[in] cfg: recoverable fault configuration
 * @retval STATUS_SUCCESS: set recoverable configuration successfully
 *         STATUS_FCCU_ERROR_SET_NORMAL: fail to set fccu in noraml state
 *         STATUS_FCCU_ERROR_SET_CONFIG: fail to set fccu in config state
 *         STATUS_TIMEOUT: run operation timeout
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_SetRfConfig(const fccu_rf_config_t *cfg) /* PRQA S 1505 */
{
    uint8_t regIdx;
    uint8_t bitPos;
    status_t status;

    status = SAF_FCCU_LLD_SetConfigState();
    if (STATUS_SUCCESS == status)
    {
        /* set rf configurations */
        regIdx = cfg->channel >> 5U;   /* divide by 32 */
        bitPos = cfg->channel & 0x1FU; /* modulo by 32 */

        /* recoverable fault configuration */
        FCCU.RF_CFG[regIdx].R = (FCCU.RF_CFG[regIdx].R & ~(1UL << bitPos)) | (((uint32_t)cfg->hwSw_recovery) << bitPos);/* polyspace RTE:NIV,OBAI */

        /* allow fccu moves ALARM or FAULT state */
        FCCU.RF_E[regIdx].R = (FCCU.RF_E[regIdx].R & ~(1UL << bitPos)) | (1UL << bitPos);/* polyspace RTE:NIV */

        /* set timeout enable
         * 0 FCCU moves into the FAULT state if the respective fault is enabled
         * 1 FCCU moves into the ALARM state if the respective fault is enabled
         */
        FCCU.RF_TOE[regIdx].R = (FCCU.RF_TOE[regIdx].R & ~(1UL << bitPos)) | (((cfg->timeout_alarm_enable == TRUE) ? 1UL : 0UL) << bitPos); /* polyspace RTE:NIV */ 
        /* set irq alarm en */
        FCCU.IRQ_ALARM_EN[regIdx].R = (FCCU.IRQ_ALARM_EN[regIdx].R & ~(1UL << bitPos)) | (((cfg->reaction.irq_alarm_en == TRUE) ? 1UL : 0UL) << bitPos); /* polyspace RTE:NIV */                                 
        /* set nmi en */
        FCCU.NMI_EN[regIdx].R = (FCCU.NMI_EN[regIdx].R & ~(1UL << bitPos)) | (((cfg->reaction.nmi_en == TRUE) ? 1UL : 0UL) << bitPos); /* polyspace RTE:NIV */
        /* set eout signaling enable */
        FCCU.EOUT_SIG_EN[regIdx].R = (FCCU.EOUT_SIG_EN[regIdx].R & ~(1UL << bitPos)) | (((cfg->reaction.eout_sig_en == TRUE) ? 1UL : 0UL) << bitPos);   /* polyspace RTE:NIV,IDP */                              

        /* set reset reaction */
        regIdx = cfg->channel >> 4U;   /* divide by 16 */
        bitPos = (cfg->channel & 0xFU) << 1U; /* modulo by 16 */

        FCCU.RFS_CFG[regIdx].R = (FCCU.RFS_CFG[regIdx].R & ~(3UL << bitPos)) | (((uint32_t)cfg->reset) << bitPos);/* polyspace RTE:NIV */

        status = SAF_FCCU_LLD_SetNormalState();
    }

    return status;
}

/*
 * @brief Set fccu eout configuration
 *
 *
 * @param[in] eoutCfg: configuration of errpin out
 * @retval STATUS_SUCCESS: set fccu eout configuration successfully
 *         STATUS_FCCU_ERROR_SET_EOUT: fail to set fccu eout configuration
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_SetEout(fccu_eout_config_t *eoutCfg) /* PRQA S 1505,3673 */
{
    status_t status;

    status = SAF_FCCU_LLD_SetConfigState();
    if (STATUS_SUCCESS == status)
    {
        FCCU.CFG.B.FCCU_SET_AFTER_RESET = (eoutCfg->set_after_reset == TRUE) ? 1U : 0U;
        FCCU.CFG.B.FCCU_SET_CLEAR = (uint8_t)eoutCfg->control;
        FCCU.CFG.B.OD = (uint8_t)eoutCfg->output;
        #if (defined(RESOURCE_SUPPORT_FCCU_EOUT_FREQ) | defined(RESOURCE_SUPPORT_FCCU_EOUT_FREQ_EXT))
        #ifdef RESOURCE_SUPPORT_FCCU_EOUT_FREQ_EXT
        FCCU.CFG.B.FOPEXT = (uint8_t)eoutCfg->fop_ext;
        #endif /* RESOURCE_SUPPORT_FCCU_EOUT_FREQ_EXT */
        FCCU.CFG.B.FOP = (uint8_t)eoutCfg->fop;
        FCCU.CFG.B.EOFS = (uint8_t)eoutCfg->eof;
        #endif /* RESOURCE_SUPPORT_FCCU_EOUT_FREQ_EXT | RESOURCE_SUPPORT_FCCU_EOUT_FREQ */
        FCCU.CFG.B.SM = (uint8_t)eoutCfg->switch_mode;
        FCCU.CFG.B.PS = (uint8_t)eoutCfg->polarity_sel;
        FCCU.CFG.B.FOM = (uint8_t)eoutCfg->mode;
        FCCU.DELTA_T.B.DELTA_T = eoutCfg->delta_t_value;
    }
    else
    {
         status = STATUS_FCCU_ERROR_SET_EOUT;
    }

    return status;
}

/*
 * @brief Initializes the fccu module
 *
 *
 * @param[in] config: fccu module configuration
 * @param[in] rfConfig: fccu recoverable faults configuration
 * @retval    STATUS_SUCCESS: init successfully
 *            STATUS_FCCU_ERROR_SET_NORMAL: fail to set fccu goto normal state
 *            STATUS_FCCU_ERROR_SET_CONFIG: fail to set fccu goto config state
 *            STATUS_TIMEOUT: in case of a timeout operation
 */
SAF_FCCU_SEC_CODE
status_t FCCU_LLD_Init(fccu_config_t *config, fccu_rf_config_t const *rfConfig)
{
    uint8_t index;
    status_t status = STATUS_FCCU_ERROR_OTHER;

    s_irqStatus.rfConfigNu = config->rfConfigNumber;
    s_irqStatus.SafcallBackFunction = config->callbackFunc;
    s_irqStatus.callBaclParam = config->callbackParam; /* PRQA S 2919 */

    Mcu_CoreType core_id = Mcu_LLD_Get_Core_Id();

    /* set debug mode */
    FCCU.CTRL.B.DEBUG = config->debug_enable;

    /* set filter bypass and width */
    FCCU.CTRL.B.FILTER_BYPASS = config->filter_bypass_enable;
    if (TRUE == config->filter_bypass_enable)
    {
        FCCU.CTRL.B.FILTER_WIDTH = config->filter_width;
    }

    s_rfConfigurations = (fccu_rf_config_t const *)rfConfig; /* PRQA S 2919 */

    /* enable timeout interrupt */
    if (config->irq_type == SAF_FCCU_IRQ_CFG_TO_IEN)
    {
        FCCU.IRQ_EN.B.CFG_TO_IEN = 0x1U;
        if (core_id != 0U)
        {
			(void)INTC_LLD_Set_IRQ_Enable(FCCU_1_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(FCCU_1_IRQn, INTR_PRI_1);
        }
        else
        {
        	if (INTC_0.PSR[FCCU_1_IRQn].B.PRC_SELN0 == OFF)  /* polyspace RTE:NIV */
        	{
    			(void)INTC_LLD_Set_IRQ_Enable(FCCU_1_IRQn);
    			(void)INTC_LLD_Set_IRQ_Priority(FCCU_1_IRQn, INTR_PRI_1);
        	}
        	else
        	{

        	}
        }

    }

    /* check alarm interrupt  */
    for (index = 0U; index < s_irqStatus.rfConfigNu; index++)
    {
        if (TRUE == s_rfConfigurations[index].reaction.irq_alarm_en) /* polyspace RTE:IDP */ 
        {
            if (core_id != 0U)
            {
    			(void)INTC_LLD_Set_IRQ_Enable(FCCU_0_IRQn);
    			(void)INTC_LLD_Set_IRQ_Priority(FCCU_0_IRQn, INTR_PRI_1);
            }
            else
            {
            	if (INTC_0.PSR[FCCU_0_IRQn].B.PRC_SELN0 == OFF)  /* polyspace RTE:NIV */
            	{
        			(void)INTC_LLD_Set_IRQ_Enable(FCCU_0_IRQn);
        			(void)INTC_LLD_Set_IRQ_Priority(FCCU_0_IRQn, INTR_PRI_1);
            	}
            	else
            	{

            	}
            }
        }
    }

    /* set fccu goto config state */
    status = SAF_FCCU_LLD_SetConfigState();
    if (STATUS_SUCCESS == status)
    {
        FCCU.CFG_TO.B.TO = config->cfg_timeout;

        status = SAF_FCCU_LLD_SetEout(&config->eout_config);
        if (STATUS_SUCCESS != status)
        {
            return status;
        }

        for (index = 0U; index < s_irqStatus.rfConfigNu; index++)
        {
             status = SAF_FCCU_LLD_SetRfConfig(&s_rfConfigurations[index]);
            if (STATUS_SUCCESS != status)
            {
                break;
            }
        }
    }

    if (STATUS_SUCCESS == status)
    {
        status = SAF_FCCU_LLD_SetNormalState();
        if (STATUS_SUCCESS == status)
        {
            SAF_FCCU_LLD_LockConfig(config->lock_type);
        }
    }

    return status;
}

/*
 * @brief Read the FCCU frozen status flags
 *
 *
 * @param[in] frozenType: type of frozen status
 * @param[in] frozenStatus: pointer to frozen status address
 * @retval STATUS_SUCCESS: read status successfully
 *         STATUS_FCCU_ERROR_UPDATE_FREEZE: fail to read frozen status
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_GetFrozenStatus(SAF_fccu_frozen_type_t frozenType, uint16_t *frozenStatus) /* PRQA S 1503 */
{
    status_t status = STATUS_FCCU_ERROR_UPDATE_FREEZE;

    switch (frozenType)
    {
    case SAF_FCCU_FROZEN_N2AF_STATUS:
        status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP4);
        if (STATUS_SUCCESS != status)
        {
            return status;
        }
        if ((uint8_t)SAF_FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = FCCU.N2AF_STATUS.B.NAFS;
            status = STATUS_SUCCESS;
        }
        break;
    case SAF_FCCU_FROZEN_A2FF_STATUS:
        status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP5);
        if (STATUS_SUCCESS != status)
        {
            return status;
        }
        if ((uint8_t)SAF_FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = FCCU.A2FF_STATUS.B.AFFS;
            status = STATUS_SUCCESS;
        }
        break;
    case SAF_FCCU_FROZEN_N2FF_STATUS:
        status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP6);
        if (STATUS_SUCCESS != status)
        {
            return status;
        }
        if ((uint8_t)SAF_FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = FCCU.N2FF_STATUS.B.NFFS;
            status = STATUS_SUCCESS;
        }
        break;
    case SAF_FCCU_FROZEN_F2AF_STATUS:
        status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP7);
        if (STATUS_SUCCESS != status)
        {
            return status;
        }
        if ((uint8_t)SAF_FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = FCCU.F2A_STATUS.B.FAFS;
            status = STATUS_SUCCESS;
        }
        break;
    default:
        status = STATUS_FCCU_ERROR_UPDATE_FREEZE;
        break;
    }

    return status;
}

/*
 * @brief Clear the freeze status register
 *
 *
 * @retval STATUS_SUCCESS: clear status register successfully
 *         STATUS_SUCCESS: fail to clear status register
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_ClearFreezeStatus(void) /* PRQA S 1503 */
{
    status_t status;

    (void)SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP13);
    if ((uint8_t)SAF_FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
    {
        status = STATUS_SUCCESS;
    }
    else
    {
        status = STATUS_FCCU_ERROR_CLEAR_FREEZE;
    }

    return status;
}

/*
 * @brief Return the XTMR register value
 *
 *
 * @param[in] xtmrType: type of xtmr value
 * @retval the value of XTMR register
 */
SAF_FCCU_SEC_CODE
uint32_t SAF_FCCU_LLD_GetXtmrValue(SAF_fccu_xtmr_type_t xtmrType) /* PRQA S 1503 */
{
    status_t status = STATUS_SUCCESS;
    uint32_t value = 0U;

    switch (xtmrType)
    {
        case SAF_FCCU_XTMR_ALARM:
            status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP17);
            break;
        case SAF_FCCU_XTMR_CFG:
            status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP19);
            break;
        case SAF_FCCU_XTMR_ETMR:
            status = SAF_FCCU_LLD_RunOperation(SAF_FCCU_RUN_OP20);
            break;
        default:
            value = 0U;
            break;
    }

    if (STATUS_SUCCESS == status)
    {
        if ((uint8_t)SAF_FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            value = FCCU.XTMR.R;
        }
    }

    return value;
}

/*
 * @brief Trigger a recoverable fault fake to test
 *
 *
 * @param[in] fakeCode: trogger fake fault channel
 * @retval None
 */
SAF_FCCU_SEC_CODE
void SAF_FCCU_LLD_SetRfFake(SAF_fccu_failure_inputs_t fakeCode)
{
    FCCU.RFF.B.FRFC = (uint8_t)fakeCode;
}


/*
 * @brief Close FCCU CH Reaction after init
 *
 *
 * @param[in] closeCh: Channel to close
 * @retval state of the function
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_CloseChReaction(SAF_fccu_failure_inputs_t closeCh)
{
    uint8_t regIdx;
    uint8_t bitPos;
    status_t status;

    regIdx = (uint8_t)closeCh >> 5U;   /* divide by 32 */
    bitPos = (uint8_t)closeCh & 0x1FU; /* modulo by 32 */

    status = SAF_FCCU_LLD_SetConfigState();
    if (STATUS_SUCCESS == status)
    {
        FCCU.RF_E[regIdx].R = (FCCU.RF_E[regIdx].R & ~(1UL << bitPos));/* polyspace RTE:NIV */
        status = SAF_FCCU_LLD_SetNormalState();
    }

    return status;
}

/*
 * @brief Close FCCU CH Reaction after init
 *
 *
 * @param[in] closeCh: Channel to close
 * @retval state of the function
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_OpenChReaction(SAF_fccu_failure_inputs_t openCh)
{
    uint8_t regIdx;
    uint8_t bitPos;
    status_t status;

    regIdx = (uint8_t)openCh >> 5U;   /* divide by 32 */
    bitPos = (uint8_t)openCh & 0x1FU; /* modulo by 32 */

    status = SAF_FCCU_LLD_SetConfigState();
    if (STATUS_SUCCESS == status)
    {
        FCCU.RF_E[regIdx].R = (FCCU.RF_E[regIdx].R | (1UL << bitPos));/* polyspace RTE:NIV */
        status = SAF_FCCU_LLD_SetNormalState();
    }

    return status;
}

/*
 * @brief Close FCCU CH Reaction after init
 *
 *
 * @param[in] closeCh: Channel to close
 * @retval state of the function
 */
SAF_FCCU_SEC_CODE
status_t SAF_FCCU_LLD_CheckChEnState(SAF_fccu_failure_inputs_t checkCh)
{
    uint8_t regIdx;
    uint8_t bitPos;
    status_t status;

    regIdx = (uint8_t)checkCh >> 5U;   /* divide by 32 */
    bitPos = (uint8_t)checkCh & 0x1FU; /* modulo by 32 */


    if ((FCCU.RF_E[regIdx].R & (1UL << bitPos)) != (uint32_t)0) /* PRQA S 1259 */
    {
    	status = STATUS_INITIALIZED;
    }
    else
    {
    	status = STATUS_UNINITIALIZED;
    }


    return status;
}
