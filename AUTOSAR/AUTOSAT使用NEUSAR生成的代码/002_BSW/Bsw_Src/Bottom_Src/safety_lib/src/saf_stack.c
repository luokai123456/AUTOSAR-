
/**
****************************************************************************************
 * @FilePath: saf_stack.c
 * @Author: CCORE
 * @Date: 2024-03-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety stack C File
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
#include "compiler_api.h"
#include "saf_cpu.h"/*PRQA S 0380*/
#include "saf_stack.h"
#include "saf_core.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,1006,1840,1881,2052,2983,3200,3344,3604,4116,4304,4404,4558 EOF*/
/**
****************************************************************************************
 * @brief: Global Variables
****************************************************************************************
*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_STACK_SEC_VAR_INIT
static saf_stack_monitor_test_t s_stackMonitorTestObj =
{
    .output =
    {
        .overflowPassed   = (bool)false,
        .underflowPassed  = (bool)false,
    },
};

static uint32_t s_stackMonitorBottomLimitAddr = (uint32_t)&SAF_STACK_MONITOR_BOTTOM_LIMIT_ADDR;
static uint32_t s_stackTopAddr = (uint32_t)&SAF_STACK_TOP_ADDR;
static uint32_t s_stackBottomAddr = (uint32_t)&SAF_STACK_BOTTOM_ADDR;/*PRQA S 3218*/
/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief:  This function is used to get the monitor test address.
* @param[in]    overFlowAddr     over flow test address.
* @param[in]    underFlowAddr    under flow test address.
* @return       void
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static void SAF_STACK_AccessGetMonitorTestAddr(uint32_t *underFlowAddr, uint32_t *overFlowAddr)
{
    /* +4 to make sure the area located in the monitor area */
    uint32_t dac1  = 4 + s_stackTopAddr;
    uint32_t dac2  = 4 + s_stackMonitorBottomLimitAddr;

    *underFlowAddr = (dac1 > dac2) ? dac2 : dac1;
    *overFlowAddr = (dac1 > dac2) ? dac1 : dac2;
}

/**
****************************************************************************************
* @brief:  This function is used to enable MSR debug exception.
* @param[in]   enable     enable selection.
* @return      void
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static void SAF_STACK_AccessEnableMsrDebugException(const bool enable)/*PRQA S 3006*/
{
    volatile FS_CORE_MSR_tag msr = { 0U };

    msr.R = MFMSR();
    msr.B.DE = enable ? SAF_DEBUG_INTERRUPT_ENABLE : SAF_DEBUG_INTERRUPT_DISABLE;/*PRQA S 4434,4559*/
    MTMSR(msr.R);
}

/**
****************************************************************************************
* @brief This function is used to enable DAC function.
* @param[in] monitorRangeSize :Stack monitor range size.
* @return FS_STATUS
*         FS_STATUS_SUCCESS :Monitor range size valid.
*         FS_STATUS_ERROR :Monitor range size invalid.
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static FS_STATUS SAF_STACK_AccessEnableDac(const uint32_t monitorRangeSize)/*PRQA S 3006*/
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    volatile FS_CORE_DBCR0_tag dbcr0 = { 0U };
    volatile FS_CORE_DBCR2_tag dbcr2 = { 0U };
    volatile FS_CORE_DBCR4_tag dbcr4 = { 0U };

    uint8_t bitMask = 0x00;
    bool checkPassed = false;

    for (bitMask = 0; bitMask <= SAF_STACK_DAC_MAX_BIT_MASK; bitMask++)
    {
        if (SAF_DEBUG_REGISTER_BITS_CLEAR_VALUE != ((monitorRangeSize >> bitMask) & SAF_DEBUG_REGISTER_LSB_MASK))
        {
            checkPassed = true;
            break;
        }
    }

    if (false == checkPassed)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        /* 1. get register */
        dbcr0.R = MFSPR(SAF_CORE_DBCR0_SPR_ID);
        dbcr2.R = MFSPR(SAF_CORE_DBCR2_SPR_ID);
        dbcr4.R = MFSPR(SAF_CORE_DBCR4_SPR_ID);

        /* 2.1 config DBCR0 */
        dbcr0.B.IDM = SAF_DEBUG_INTERNAL_DEBUG_MODE_ENABLE;
        dbcr0.B.EDM = SAF_DEBUG_EXTERNAL_DEBUG_MODE_DISABLE;
        dbcr0.B.DAC1 = SAF_STACK_DAC_EABLE_DEBUG_EVENT_STROE_AND_LOAD;
        dbcr0.B.DAC2 = SAF_STACK_DAC_EABLE_DEBUG_EVENT_STROE_AND_LOAD;

        /* 2.2 config DBCR2 */
        dbcr2.B.DAC12M = SAF_DEBUG_DAC_MODE_EXACT_ADDRESS_COMPARE;

        /* 2.3 config DBCR4 */
        dbcr4.B.DAC1XM = bitMask;
        dbcr4.B.DAC2XM = bitMask;

        /* 3. reconfig DBCR & MSR */
        MTSPR(SAF_CORE_DBCR2_SPR_ID, dbcr2.R);
        MTSPR(SAF_CORE_DBCR4_SPR_ID, dbcr4.R);
        MTSPR(SAF_CORE_DBCR0_SPR_ID, dbcr0.R);

        SAF_STACK_AccessEnableMsrDebugException(false);
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to clean DAC value.
* @return       void
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static void SAF_STACK_AccessCleanDbsrDac(void)/*PRQA S 3006*/
{
    FS_CORE_DBSR_tag dbsr = { 0U };
    
    dbsr.R = MFSPR(SAF_CORE_DBSR_SPR_ID);/*PRQA S 2982*/

    dbsr.R = SAF_STACK_DBSR_CLEAR_VALUE;
    dbsr.B.DACR = SAF_DEBUG_DAC_READ_EVENT_CLEAR;
    dbsr.B.DACW = SAF_DEBUG_DAC_WRITE_EVENT_CLEAR;

    MTSPR(SAF_CORE_DBSR_SPR_ID, dbsr.R);
    dbsr.R = MFSPR(SAF_CORE_DBSR_SPR_ID);

}

/**
****************************************************************************************
* @brief:  This function is used to disable DAC function.
* @return       void
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static void SAF_STACK_AccessDisableDac(void)/*PRQA S 3006*/
{
    FS_CORE_DBCR0_tag dbcr0 = { 0U };

    dbcr0.R = MFSPR(SAF_CORE_DBCR0_SPR_ID);/*PRQA S 2982*/
    dbcr0.B.DAC1 = SAF_STACK_DAC_DISABLE_DEBUG_EVENT;
    dbcr0.B.DAC2 = SAF_STACK_DAC_DISABLE_DEBUG_EVENT;
    dbcr0.B.IDM = SAF_DEBUG_INTERNAL_DEBUG_MODE_DISABLE;
    dbcr0.B.EDM = SAF_DEBUG_EXTERNAL_DEBUG_MODE_ENABLE;

    MTSPR(SAF_CORE_DBCR0_SPR_ID, dbcr0.R);
}

/**
****************************************************************************************
* @brief:  This function is used to get the SPR value.
* @param[in]    regID     SPR register id.
* @return       uint32_t  SPR value
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static uint32_t SAF_STACK_AccessGetSprValue(const uint32_t regID)
{
    uint32_t data = 0;

    if (SAF_CORE_DBSR_SPR_ID == regID)
    {
        data = MFSPR(SAF_CORE_DBSR_SPR_ID);
    }
    else if (SAF_CORE_DAC1_SPR_ID == regID)
    {
        data = MFSPR(SAF_CORE_DAC1_SPR_ID);
    }
    else if (SAF_CORE_DAC2_SPR_ID == regID)
    {
        data = MFSPR(SAF_CORE_DAC2_SPR_ID);
    }
    else
    {
        /* Do nothing. */
    }
    
    return data;/*PRQA S 2962*/
}

/**
****************************************************************************************
* @brief:  This function is used to enable configure DAC register.
* @param[in]   dac1Addr     DAC1 configure value.
* @param[in]   dac2Addr     DAC1 configure value.
* @return      void
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static void SAF_STACK_AccessConfigDacReg(const uint32_t dac1Addr, const uint32_t dac2Addr)/*PRQA S 3206*/
{
    MTSPR(SAF_CORE_DAC1_SPR_ID, dac1Addr);
    MTSPR(SAF_CORE_DAC2_SPR_ID, dac2Addr);
}

/**
****************************************************************************************
* @brief:  This function is used to detect DAC read error.
* @return      bool
*              true       DAC read error occurred
*              false      DAC read error not occurred
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static bool SAF_STACK_AccessDetectDacReadErr(void)
{
    volatile FS_CORE_DBSR_tag dbsr = { 0U };
    bool dacErrStatus = (bool)false;

    dbsr.R = SAF_STACK_AccessGetSprValue(SAF_CORE_DBSR_SPR_ID);
    dacErrStatus = (SAF_DEBUG_DAC_READ_EVENT_NOT_OCCURRED != dbsr.B.DACR) ? true : false;

    return dacErrStatus;
}

/**
****************************************************************************************
* @brief:  This function is used to detect DAC write error.
* @return      bool
*              true       DAC write error occurred
*              false      DAC write error not occurred
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static bool SAF_STACK_AccessDetectDacWriteErr(void)
{
    volatile FS_CORE_DBSR_tag dbsr = { 0U };
    bool dacErrStatus = (bool)false;

    dbsr.R = SAF_STACK_AccessGetSprValue(SAF_CORE_DBSR_SPR_ID);
    dacErrStatus = (SAF_DEBUG_DAC_WRITE_EVENT_NOT_OCCURRED != dbsr.B.DACW) ? true : false;

    return dacErrStatus;
}

/**
****************************************************************************************
* @brief:  This function is used to detect DAC error.
* @return      bool
*              true       DAC error occurred
*              false      DAC error not occurred
****************************************************************************************
*/
SAF_STACK_SEC_CODE
static bool SAF_STACK_AccessDetectDacErr(void)
{
    FS_CORE_DBSR_tag dbsr = { 0U };
    bool dacErrStatus = (bool)false;

    dbsr.R = SAF_STACK_AccessGetSprValue(SAF_CORE_DBSR_SPR_ID);

    dacErrStatus = (SAF_STACK_DAC_EVENT_CHECK_BITS_CLEARD != (dbsr.R & SAF_STACK_DAC_EVENT_CHECK_BITS_MASK)) ? true : false;/*PRQA S 0499,4397*/

    return dacErrStatus;
}

/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief:  This function is used to clean DAC register.
* @return      void
****************************************************************************************
*/
SAF_STACK_SEC_CODE
void SAF_STACK_CleanDbsrDac(void)
{
    SAF_STACK_AccessCleanDbsrDac();
}

/**
****************************************************************************************
* @brief:  This function is used to disable stack monitor function.
* @return      void
****************************************************************************************
*/
SAF_STACK_SEC_CODE
void SAF_STACK_MonitorDisable(void)
{
    SAF_STACK_AccessDisableDac();
}

/**
****************************************************************************************
* @brief:  This function is used to enable stack monitor function.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS     enable succeed
*              FS_STATUS_ERROR       enable failed
****************************************************************************************
*/
SAF_STACK_SEC_CODE
FS_STATUS SAF_STACK_MonitorEnable(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    uint32_t underflowAddr= s_stackMonitorBottomLimitAddr;
    uint32_t overflowAddr = s_stackTopAddr;
    uint32_t stackMonitorSize = s_stackBottomAddr - s_stackMonitorBottomLimitAddr;

    if (overflowAddr <= underflowAddr)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        /* 1. configure DAC Register*/
        SAF_STACK_AccessConfigDacReg(underflowAddr, overflowAddr);
        /* 2. enable DAC  */
        status = SAF_STACK_AccessEnableDac(stackMonitorSize);
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to check stack monitor status.
*          to the destination address.
* @param[in]   pStackStatus        stack monitor status point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS     check stack monitor status succeed
*              FS_STATUS_ERROR       check stack monitor status failed
****************************************************************************************
*/
SAF_STACK_SEC_CODE
FS_STATUS SAF_STACK_CheckStatus(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (true == SAF_STACK_AccessDetectDacErr())
    {
        status = FS_STATUS_ERROR;
    }
    
    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to get the test result stack monitor test.
* @param[out]   pTestResult   stack monitor test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get result succeed
*               FS_STATUS_ERROR       get result failed
****************************************************************************************
*/
SAF_STACK_SEC_CODE
FS_STATUS SAF_STACK_MonitorTestResult(saf_stack_monitor_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        status = FS_STATUS_SUCCESS;
        memcpy(pTestResult, &s_stackMonitorTestObj.output, sizeof(s_stackMonitorTestObj.output));
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function executes stack monitor test.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     stack monitor test succeed
*               FS_STATUS_ERROR       stack monitor test failed
****************************************************************************************
*/
SAF_STACK_SEC_CODE
FS_STATUS SAF_STACK_MonitorTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
    saf_stack_monitor_test_result_t *pResult= &s_stackMonitorTestObj.output;
    uint32_t overFlowAddr = 0U;
    uint32_t underFlowAddr = 0U;
    uint32_t data = 0U;
    pResult->overflowPassed   = (bool)true;
    pResult->underflowPassed  = (bool)true;

    /* 1. enable monitor DAC */
    status = SAF_STACK_MonitorEnable();
    if (FS_STATUS_SUCCESS == status)
    {
        SAF_STACK_CleanDbsrDac();
        /* 2.Get stack monitor test addr */
        SAF_STACK_AccessGetMonitorTestAddr(&underFlowAddr, &overFlowAddr);

        /* 3.1 test overflow write */
        *((volatile uint32_t *)overFlowAddr) = SAF_STACK_WRITE_VALUE; /* polyspace RTE:IDP */
        if (false == SAF_STACK_AccessDetectDacWriteErr())
        {
            pResult->overflowPassed = (bool)false;
        }
        else
        {
            SAF_STACK_CleanDbsrDac();

            /* 3.2. Test overflow read. */
            data = *((volatile uint32_t *)overFlowAddr); /* polyspace RTE:NIV,IDP *//* parasoft-suppress MISRAC2012-RULE_2_2-b "function requirement" */
            if (false == SAF_STACK_AccessDetectDacReadErr())
            {
                pResult->overflowPassed = false;
            }
        }
        SAF_STACK_CleanDbsrDac();

        /* 3.3 test underflow write */
        *((volatile uint32_t *)underFlowAddr) = SAF_STACK_WRITE_VALUE; /* polyspace RTE:IDP */
        if (false == SAF_STACK_AccessDetectDacWriteErr())
        {
            pResult->underflowPassed = (bool)false;
        }
        else
        {
            SAF_STACK_CleanDbsrDac();

            /* 3.4. Test underflow read. */
            data = *((volatile uint32_t *)underFlowAddr);/* polyspace RTE:NIV,IDP */
            if (false == SAF_STACK_AccessDetectDacReadErr())
            {
                pResult->underflowPassed = false;
            }
        }

        (void)data;/*PRQA S 3119*/
        SAF_STACK_CleanDbsrDac();

        if ((pResult->underflowPassed == (bool)false) || (pResult->overflowPassed == (bool)false))
        {
            status = FS_STATUS_ERROR;
        }

        SAF_STACK_MonitorDisable();
    }  
    else
    {
        pResult->overflowPassed   = (bool)false;
        pResult->underflowPassed  = (bool)false;
    }

    return status;
}

#ifdef __cplusplus
}
#endif
