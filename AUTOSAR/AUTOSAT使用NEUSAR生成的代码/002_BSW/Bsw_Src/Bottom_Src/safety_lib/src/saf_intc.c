/**
****************************************************************************************
 * @FilePath: saf_intc.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: INTC Source File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_intc.h"/*PRQA S 0380*/
#include "Saf_MemMap.h"

extern IntrHandle IntcIsrVectorTable[];/*PRQA S 3684*/
/*PRQA S 1862,2844,3200,3344,3408,4304,4393,4543 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_INTC_SEC_VAR_INIT
static saf_intc_mgr_monitor_type_t s_intcMgr =
{
    .spuriousFlag = {FALSE},/*PRQA S 0686*/
    .missingFlag = {FALSE},
};

SAF_INTC_SEC_VAR_INIT
saf_intc_monitor_test_param_t s_intcInputTest =
{
    .monitorCount = SAF_INTC_MONITOR_COUNT,
    .irqNoMapArray = SAF_INTC_IRQID_LIST,/*PRQA S 4424*/
	.irqStatusChecApi = SAF_INTC_STATUS_CHECK_API,/*PRQA S 3635*/
};

SAF_INTC_SEC_VAR_INIT
static saf_intc_monitor_test_result_t s_intcOutputTest =
{
    .missingIrqBitmapArray = {0},
    .spuriousIrqBitmapArray = {0},
};

SAF_INTC_SEC_VAR_INIT
static uint32_t g_irq_num = 0;/*PRQA S 3218*/
#ifdef CCFC3008PCSN
SAF_INTC_SEC_VAR_INIT
static IntrHandle saved_isr_table[1] = {0};
#endif
/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [] This function check the assign number IRQ is available.
* @param[in] irq IRQ number.
* @return boolean
                TURE:The current interrupt number is available
                FALSE:The current interrupt number is not available
****************************************************************************************
*/
SAF_INTC_SEC_CODE
static boolean SAF_INTC_AccessIrqNoIsAvailable(const uint32_t irq)
{
    boolean status = FALSE;

    if(SAF_INTC_IRQ_COUNT > irq)
    {
        status = TRUE;
    }

    return status;
}

/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/

/**
****************************************************************************************
* @brief[SW_SM67] This function is used to check for Spurious interrupt.
* @param[in] irq: IRQ number.
* @return status
            FS_STATUS_SUCCESS: Check for Spurious interrupts successfully.
            FS_STATUS_ERROR: Check for Spurious interrupts failed.
****************************************************************************************
*/
SAF_INTC_SEC_CODE
FS_STATUS SAF_INTC_CheckSpuriousInterrupt(const uint32_t irq)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_intc_monitor_test_param_t *pParam = &s_intcInputTest;
    saf_intc_mgr_monitor_type_t *pIntcMgr = &s_intcMgr;
    uint16_t i, saf_irq = 0;

    if (TRUE == SAF_INTC_AccessIrqNoIsAvailable(irq))
    {
        for (i = 0; i < pParam->monitorCount; i++)
        {
            saf_irq = (uint16_t)(pParam->irqNoMapArray[i]);/* polyspace RTE:OBAI */
            if(irq == saf_irq)
            {
                if (NULL != pParam->irqStatusChecApi[i])
                {
                    if (FALSE == (pParam->irqStatusChecApi[i])())
                    {
                        pIntcMgr->spuriousFlag[irq] = TRUE;
                    }
                }
                else
                {
                    status = FS_STATUS_ERROR;
                }
                break;
            }
            else
            {
                if((pParam->monitorCount - 1U) == i)
                {
                    /* The interrupt number is not in the configuration list*/
                    status = FS_STATUS_ERROR;
                }
            }
        }
    }
    else
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_SM66] This function is used to check for missing interrupts.
* @return status
            FS_STATUS_SUCCESS: Check for missing interrupts successfully.
            FS_STATUS_ERROR: Check for missing interrupts failed.
****************************************************************************************
*/
SAF_INTC_SEC_CODE
FS_STATUS SAF_INTC_CheckMissingInterrupt(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_intc_mgr_monitor_type_t *pIntcMgr = &s_intcMgr;
    saf_intc_monitor_test_param_t *pParam = &s_intcInputTest;
    uint16_t i, irq = 0;

    for (i = 0; i < pParam->monitorCount; i++)
    {
        irq = (uint16_t)(pParam->irqNoMapArray[i]);/* polyspace RTE:OBAI */
        if (TRUE == SAF_INTC_AccessIrqNoIsAvailable(irq))
        {
            if (NULL != (pParam->irqStatusChecApi[i]))
            {
                if (TRUE == (pParam->irqStatusChecApi[i])())
                {
                    /* if isr has not been called, then missing irq  */
                    pIntcMgr->missingFlag[irq] = TRUE;
                }
            }
            else
            {
                status = FS_STATUS_ERROR;
            }
        }
        else
        {
            status = FS_STATUS_ERROR;
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief: []  This function get IRQ  monitor test result.
* @param[out] pTestResult IRQ  monitor test result
* @return status
            FS_STATUS_SUCCESS: get IRQ  monitor test result successfully.
            FS_STATUS_ERROR: Failed to get IRQ  monitor test result.
****************************************************************************************
*/ 
SAF_INTC_SEC_CODE
FS_STATUS SAF_INTC_IrqMonitorTestResult(saf_intc_monitor_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        memcpy(pTestResult, &s_intcOutputTest, sizeof(s_intcOutputTest));/*PRQA S 0315*/
    }

    return status;
}

/**
****************************************************************************************
* @brief: []  This function IRQ  monitor test.
* @param[out] pTestResult IRQ monitor test result
* @return status
            FS_STATUS_SUCCESS:  IRQ  monitor test successfully.
            FS_STATUS_ERROR: Failed to IRQ  monitor test .
****************************************************************************************
*/
SAF_INTC_SEC_CODE
FS_STATUS SAF_INTC_IrqMonitorTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_intc_monitor_test_param_t *pParam = &s_intcInputTest;
    saf_intc_monitor_test_result_t *pResult = &s_intcOutputTest;
    saf_intc_mgr_monitor_type_t *pIntcMgr = &s_intcMgr;
    uint16_t i, irq = 0;
    uint8_t index, offset = 0;

    for (i = 0; i < pParam->monitorCount; i++)
    {
        irq = (uint16_t)pParam->irqNoMapArray[i]; /* polyspace RTE:OBAI */
        index = (uint8_t)(irq >> SAF_DIV_8_RIGHT_SHIFT_BIT);
        offset = (uint8_t)(irq & SAF_MOD_8_MASK);/*PRQA S 1841,1861,4542*/

        pResult->missingIrqBitmapArray[index] &= ~(uint8_t)(0x1 << offset); /*PRQA S 4397*/ /* polyspace RTE:OBAI */
        pResult->spuriousIrqBitmapArray[index] &= ~(uint8_t)(0x1 << offset); /*PRQA S 4397*/

        if (TRUE == SAF_INTC_AccessIrqNoIsAvailable(irq))
        {
            /* 1. check missing */
            if (TRUE == pIntcMgr->missingFlag[irq])
            {
                pResult->missingIrqBitmapArray[index] |= (uint8_t)(0x1U << offset);
                pIntcMgr->missingFlag[irq] = FALSE;
                status = FS_STATUS_ERROR;
            }
            /* 2. check spurious */
            if (TRUE == pIntcMgr->spuriousFlag[irq])
            {
                pResult->spuriousIrqBitmapArray[index] |= (uint8_t)(0x1U << offset);
                pIntcMgr->spuriousFlag[irq] = FALSE;
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief: [SW_SM70]  This function get current core id.
* @param[out] id core id.
* @return void
****************************************************************************************
*/
SAF_INTC_SEC_CODE
void SAF_INTC_Get_Core_Id(uint8_t *id)
{
	Saf_CoreId core_id = SAF_MCU_LLD_Get_Core_Id();
	*id = core_id;/*PRQA S 4424*/
}

/**
****************************************************************************************
* @brief: [SW_SM68]  This function get the global interrupt priority.
* @param[out] intr_prior priority number.
* @return  status
            FS_STATUS_SUCCESS: Get interrupt priority successfully.
            FS_STATUS_ERROR: Failed to Get interrupt priority.
****************************************************************************************
*/
SAF_INTC_SEC_CODE
FS_STATUS SAF_INTC_Get_Global_Priority(uint32_t* intr_prior)
{
    FS_STATUS status = FS_STATUS_ERROR;
    Saf_CoreId core_id = SAF_MCU_LLD_Get_Core_Id();

    if (intr_prior !=NULL)
    {
        *intr_prior = INTC_0.CPR[core_id].B.PRI; /* polyspace RTE:NIV,IDP,OBAI */
        status = FS_STATUS_SUCCESS;
    }

    return status;
}
#if defined(CCFC3008PCSN)
SAF_INTC_SEC_CODE
static void SAF_INTC_ReplaceIntHandler(uint32_t intcNum, IntrHandle newFuncHandle)
{
	saved_isr_table[0] = IntcIsrVectorTable[intcNum];
	IntcIsrVectorTable[intcNum] = newFuncHandle;
	INTC_LLD_Set_Vector_Table((uint32_t)&IntcIsrVectorTable[intcNum]);/*PRQA S 2934*/
}

SAF_INTC_SEC_CODE
static void SAF_INTC_RestoreIntHandler(uint32_t intcNum)
{
	IntcIsrVectorTable[intcNum] = saved_isr_table[0];
	INTC_LLD_Set_Vector_Table((uint32_t)&IntcIsrVectorTable[intcNum]);/*PRQA S 2934*/
}
#endif
SAF_INTC_SEC_CODE
void SAF_INTC_IrqMonitorFault(void)
{

	INTC_0.SSCIR[g_irq_num].R = 1;

}

SAF_INTC_SEC_CODE
FS_STATUS SAF_INTC_MonitorReportPathTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
#if defined(CCFC3008PCSN)
    SAF_fccu_faults_flags_t rf_flag;
    uint32_t counter = 0;
    uint32_t monitor_instance = 0;
    uint32_t irq_num = 0;
    uint32_t sucTime = 0;
    uint32_t irqOrinInfo = 0;
    uint32_t fs_Ch[3] = {0, 0, 0};

    if (SAF_FCCU_LLD_CheckChEnState(SAF_FCCU_FAILURE_INTC_MON_ERR_0_CH_59) == STATUS_INITIALIZED)
    {
    	fs_Ch[0] = 1;
    }
    if (SAF_FCCU_LLD_CheckChEnState(SAF_FCCU_FAILURE_INTC_MON_ERR_1_CH_60) == STATUS_INITIALIZED)
    {
    	fs_Ch[1] = 1;
    }
    if (SAF_FCCU_LLD_CheckChEnState(SAF_FCCU_FAILURE_INTC_MON_ERR_2_CH_61) == STATUS_INITIALIZED)
    {
    	fs_Ch[2] = 1;
    }

    SAF_FCCU_LLD_CloseChReaction(SAF_FCCU_FAILURE_INTC_MON_ERR_0_CH_59);
    SAF_FCCU_LLD_CloseChReaction(SAF_FCCU_FAILURE_INTC_MON_ERR_1_CH_60);
    SAF_FCCU_LLD_CloseChReaction(SAF_FCCU_FAILURE_INTC_MON_ERR_2_CH_61);
    for(irq_num = 0; irq_num < 1; irq_num++)
    {
    	SAF_INTC_ReplaceIntHandler(irq_num, (IntrHandle)SAF_INTC_IrqMonitorFault);
		// Raise PRI for software configurable interrupt 0 to 1
        irqOrinInfo = INTC_0.PSR[irq_num].R;
    	INTC_LLD_Set_IRQ_Priority((IntrId)irq_num,INTR_PRI_1);
    	INTC_LLD_Set_IRQ_Enable((IntrId)irq_num);
    	sucTime = 0;
		counter = 0x1;

		for(monitor_instance = 0; monitor_instance <= 2; monitor_instance++)
		{

			SAF_INTC0_MONITOR.MTOR0[monitor_instance].R = counter;
			SAF_INTC0_MONITOR.MSR0[monitor_instance].R = irq_num;	//select intc source
			SAF_INTC0_MONITOR.MCR0.B.MMR = 1;	// 0:stop; 1:read IACKR stop; 2:write EOIR stop; 3:write EOIR stop & ack other pause

			// Assert software configurable interrupt 0
			if(irq_num > 31)
			{
				g_irq_num = 0;
				INTC_0.PSR[irq_num].R |= 0x100;
			}
			else
			{
				g_irq_num = irq_num;
				INTC_0.SSCIR[irq_num].R = 2;
			}

			SAF_FCCU_LLD_ReadFaults(&rf_flag);

			if(irq_num > 31)
			{
				INTC_0.PSR[irq_num].R &= ~0x100;
			}
			else
			{
			// Clear interrupt flag
				INTC_0.SSCIR[irq_num].R = 1;
			}

			SAF_INTC0_MONITOR.MTOR0[monitor_instance].R = 0;
			SAF_INTC0_MONITOR.MSR0[monitor_instance].R = 0;	//select intc source
			SAF_INTC0_MONITOR.MCR0.B.MMR = 0;	// 0:stop; 1:read IACKR stop; 2:write EOIR stop; 3:write EOIR stop & ack other pause


			/* clear fault */
			SAF_FCCU_LLD_ClearFaults(SAF_FCCU_MAX_FAULTS_NO);

			if ((rf_flag.faultsFlags[1] & FCCU_INTC_MON_ERR_MASK) != 0U)/* polyspace RTE:NIVL */
			{
				sucTime++;
			}

		}
		SAF_INTC_RestoreIntHandler(irq_num);
		INTC_0.PSR[irq_num].R = irqOrinInfo;
		if (sucTime == 3) {
			status = FS_STATUS_SUCCESS;
		}
    }

    if (fs_Ch[0] == 1)
    {
    	SAF_FCCU_LLD_OpenChReaction(SAF_FCCU_FAILURE_INTC_MON_ERR_0_CH_59);
    }
    if (fs_Ch[1] == 1)
    {
    	SAF_FCCU_LLD_OpenChReaction(SAF_FCCU_FAILURE_INTC_MON_ERR_1_CH_60);
    }
    if (fs_Ch[2] == 1)
    {
    	SAF_FCCU_LLD_OpenChReaction(SAF_FCCU_FAILURE_INTC_MON_ERR_2_CH_61);
    }
#else
    status = FS_STATUS_SUCCESS;
#endif
    return status;
}

#ifdef __cplusplus
}
#endif
