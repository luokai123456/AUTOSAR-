/**
****************************************************************************************
 * @FilePath: saf_cache.c
 * @Author: CCORE
 * @Date: 2024-03-01
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Cache C File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0_PatchCache
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
#include "saf_cache.h"/*PRQA S 0380*/
#include "saf_mpu.h"
#include "Saf_MemMap.h"
#if SAF_CACHE_SUPPORTED
/*PRQA S 0305,1006,1841,2052,2982,3006,3200,3344,3408,4304,4322,4542 EOF*/
/*PRQA S 0499,1258,1259,1881,2983,3119,3218,3397,3395,3401,3604,4404,4397 EOF*/
/**
****************************************************************************************
 * @brief: Global Variables
****************************************************************************************
*/
SAF_CACHE_SEC_VAR_INIT
uint32_t cacheTestFlag = CACHE_SAFETY_OP_CHANGED;
SAF_CACHE_SEC_VAR_INIT
static uint32_t s_dcacheEDCTestAddr = SAFETYMEMTEST_EDC_D_CACHE_TEST_ADDR;
SAF_CACHE_SEC_VAR_INIT
static uint32_t s_icacheEDCTestAddr = SAFETYMEMTEST_EDC_I_CACHE_TEST_ADDR;

extern cmpu_module_cfg_t cache_mpu_Cfg;
extern cmpu_entry_cfg_t cache_mpuEntryArray[SAFETYMEMTEST_CMPU_ENTRY_COUNT_BY_CACHE];
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
/* EDC report path test object */
SAF_CACHE_SEC_VAR_INIT
static saf_cache_edc_report_path_test_t s_cacheEdcReportPathTest =
{
    .output =
    {
        .dcacheTestPassed = (bool)false,
        .icacheTestPassed = (bool)false
    }
};

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
#if SAF_DCACHE_SUPPORTED
/**
****************************************************************************************
* @brief:  This function shall be used to detects if the DCACHE is enabled.
* @return      bool
*              true       DCACHE is enabled
*              false      DCACHE is disabled
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
bool SAF_CACHE_AccessDcacheIsEnabled(void)
{
    FS_CORE_L1CSR0_tag l1csr0Register = { 0U };
    bool dcacheIsEnabled = false;

    l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);/*PRQA S 1006*/
    
    dcacheIsEnabled = ((l1csr0Register.R & SAF_CACHE_L1CSR0_DCE_MASK) == SAF_CACHE_L1CSR0_DCE(1));

    return dcacheIsEnabled;
}

/**
****************************************************************************************
* @brief:  This function is used to invalidate DCACHE and it needs to be cache-inhibited.
* @return       void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessInvalidateDcache(void)/*PRQA S 3006*/
{
    FS_CORE_L1CSR0_tag l1csr0Register = { 0U };

    l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);
    l1csr0Register.B.DCINV = SAF_CACHE_DCACHE_INVALIDATION_OPERATION;
    MTSPR(SAF_CORE_L1CSR0_SPR_ID, l1csr0Register.R);
    PPCASM("se_isync");
}

/**
****************************************************************************************
* @brief:  This function is used to wait completing invalidate DCACHE and it needs
*          to be cache-inhibited.
* @return       void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessWaitInvalidateDcacheDone(void)
{
    FS_CORE_L1CSR0_tag l1csr0Register = { 0U };
    uint32_t timeout = SAF_CACHE_INVALIDATE_COUNT;

    /* Cache invalidation operations require approximately 66 cycles to complete. */
    do
    {
        l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);
        if (SAF_CACHE_DCACHE_NO_INVALIDATION_OPERATION == l1csr0Register.B.DCINV)
        {
            break;
        }

    } while ((--timeout) > 0U);
}

/**
****************************************************************************************
* @brief:  This function is used to clean all DCACHE error and it needs
*          to be cache-inhibited.
* @return       void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessCleanDcacheError(void)
{
    FS_CORE_L1CSR0_tag l1csr0Register = { 0U };

    l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);
    if (SAF_CACHE_DCACHE_CLEAN_CHECK_BITS_CLEARD != (l1csr0Register.R & SAF_CACHE_DCACHE_CLEAN_CHECK_BITS_MASK))
    {
        MTSPR(SAF_CORE_L1CSR0_SPR_ID, SAF_CACHE_L1CSR0_CLEAR_VALUE);
    }

    l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);
}

/**
****************************************************************************************
* @brief:  This function is used to enable DCACHE.
* @return       void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
void SAF_CACHE_AccessEnableDcache(void)
{
    FS_CORE_L1CSR0_tag l1csr0Register = { 0U };

    l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);
    /* Enable cache. */
    l1csr0Register.B.DCE = SAF_CACHE_DCACHE_ENABLE;
    l1csr0Register.B.DCEA = SAF_CACHE_DCACHE_ERROR_ACTION_AUTO_HANDLE_SELECT;
    l1csr0Register.B.DCECE = SAF_CACHE_DCACHE_ERROR_CHECKING_ENABLE;
    PPCASM("se_isync");
    PPCASM("msync");
    MTSPR(SAF_CORE_L1CSR0_SPR_ID, l1csr0Register.R);
    PPCASM("se_isync");
}

/**
****************************************************************************************
* @brief:  This function is used to disable DCACHE.
* @return       void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
void SAF_CACHE_AccessDisableDcache(void)
{
    FS_CORE_L1CSR0_tag l1csr0Register = { 0U };

    l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);
    /* Disable cache. */
    l1csr0Register.B.DCE = SAF_CACHE_DCACHE_DISABLE;
    PPCASM("se_isync");
    PPCASM("msync");
    MTSPR(SAF_CORE_L1CSR0_SPR_ID, l1csr0Register.R);
    PPCASM("se_isync");
}

/**
****************************************************************************************
* @brief:  This function is used to inject DCACHE error.
* @return       void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessInjectDcacheError(void)
{
    FS_CORE_L1CSR0_tag l1csr0Register = { 0U };

    SAF_CACHE_AccessInvalidateDcache();
    SAF_CACHE_AccessWaitInvalidateDcacheDone();

    l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);
    /* DCACHE invalidate and enable error injection. */
    l1csr0Register.R |= SAF_CACHE_DCACHE_ERROR_INJECTION_BITS_SET;
    MTSPR(SAF_CORE_L1CSR0_SPR_ID, l1csr0Register.R);

    SAF_CACHE_AccessWaitInvalidateDcacheDone();
}

#endif

#if SAF_ICACHE_SUPPORTED
/**
****************************************************************************************
* @brief:  This function detects if ICACHE is enabled.
* @return      bool
*              true       ICACHE is enabled
*              false      ICACHE is disabled
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
bool SAF_CACHE_AccessIcacheIsEnabled(void)
{
    FS_CORE_L1CSR1_tag l1csr1Register = { 0U };
    bool icacheIsEnabled = false;

    l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);

    icacheIsEnabled = ((l1csr1Register.R & SAF_CACHE_L1CSR1_ICE_MASK) == SAF_CACHE_L1CSR1_ICE(1));

    return icacheIsEnabled;
}

/**
****************************************************************************************
* @brief:  This function is used to invalidate ICACHE and it needs to be cache-inhibited.
* @return      void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessInvalidateIcache(void)
{
    FS_CORE_L1CSR1_tag l1csr1Register = { 0U };

    l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);
    l1csr1Register.B.ICINV = SAF_CACHE_ICACHE_INVALIDATION_OPERATION;
    MTSPR(SAF_CORE_L1CSR1_SPR_ID, l1csr1Register.R);
    PPCASM("se_isync");
}

/**
****************************************************************************************
* @brief:  This function is used to wait completing invalidate ICACHE
*          and it needs to be cache-inhibited.
* @return      void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessWaitInvalidateIcacheDone(void)
{
    FS_CORE_L1CSR1_tag l1csr1Register = { 0U };
    uint32_t timeout = SAF_CACHE_INVALIDATE_COUNT;

    /* Cache invalidation operations require approximately 134 cycles to complete. */
    do
    {
        l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);
        if (SAF_CACHE_ICACHE_NO_INVALIDATION_OPERATION == l1csr1Register.B.ICINV)
        {
            break;
        }

    } while ((--timeout) > 0U);
}

/**
****************************************************************************************
* @brief:  This function is used to clear ICACHE error and it needs to
*          be cache-inhibited.
* @return      void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessCleanIcacheError(void)
{
    FS_CORE_L1CSR1_tag l1csr1Register = { 0U };

    l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);
    if (SAF_CACHE_ICACHE_CLEAN_CHECK_BITS_CLEARD != (l1csr1Register.R & SAF_CACHE_ICACHE_CLEAN_CHECK_BITS_MASK))
    {
        MTSPR(SAF_CORE_L1CSR1_SPR_ID, SAF_CACHE_L1CSR1_CLEAR_VALUE);
    }

    l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);
}

/**
****************************************************************************************
* @brief:  This function is used to enable ICACHE.
* @return      void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
void SAF_CACHE_AccessEnableIcache(void)
{
    FS_CORE_L1CSR1_tag l1csr1Register = { 0U };

    l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);
    l1csr1Register.B.ICE = SAF_CACHE_ICACHE_ENABLE;
    l1csr1Register.B.ICEA = SAF_CACHE_ICACHE_ERROR_ACTION_AUTO_HANDLE_SELECT;
    l1csr1Register.B.ICECE = SAF_CACHE_ICACHE_ERROR_CHECKING_ENABLE;
    PPCASM("se_isync");
    PPCASM("msync");
    MTSPR(SAF_CORE_L1CSR1_SPR_ID, l1csr1Register.R);
    PPCASM("se_isync");
}

/**
****************************************************************************************
* @brief:  This function is used to disable ICACHE.
* @return      void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
void SAF_CACHE_AccessDisableIcache(void)
{
    FS_CORE_L1CSR1_tag l1csr1Register = { 0U };

    l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);
    /* Disable cache. */
    l1csr1Register.B.ICE = SAF_CACHE_ICACHE_DISABLE;
    PPCASM("se_isync");
    PPCASM("msync");
    MTSPR(SAF_CORE_L1CSR1_SPR_ID, l1csr1Register.R);
    PPCASM("se_isync");
}

/**
****************************************************************************************
* @brief:  This function is used to inject ICACHE error.
* @return      void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessInjectIcacheError(void)
{
    FS_CORE_L1CSR1_tag l1csr1Register = { 0U };

    SAF_CACHE_AccessInvalidateIcache();
    SAF_CACHE_AccessWaitInvalidateIcacheDone();

    l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);
    /* ICACHE invalidate and enable error injection. */
    l1csr1Register.R |= SAF_CACHE_ICACHE_ERROR_INJECTION_BITS_SET;
    MTSPR(SAF_CORE_L1CSR1_SPR_ID, l1csr1Register.R);

    SAF_CACHE_AccessWaitInvalidateIcacheDone();

}

#endif

/**
****************************************************************************************
* @brief:  This function is CACHE error call back function.
* @return      void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessErrorCallBack(void)
{
    FS_CORE_MCSR_tag mcsrRegister = { 0U };
    saf_cache_edc_report_path_test_t *pCacheTest = &s_cacheEdcReportPathTest;

    mcsrRegister.R = MFSPR(FS_CORE_MCSR_SPR_ID);
#if SAF_DCACHE_SUPPORTED
    if (SAF_MCSR_IACHE_DATA_ARRAY_PARITY_ERROR_NOT_OCCURRED != mcsrRegister.B.DC_DPERR)
    {
        pCacheTest->output.dcacheTestPassed = true;
        SAF_CACHE_AccessCleanDcacheError();
    }

#endif
#if SAF_ICACHE_SUPPORTED
    if (SAF_MCSR_IACHE_DATA_ARRAY_PARITY_ERROR_NOT_OCCURRED != mcsrRegister.B.IC_DPERR)
    {
        pCacheTest->output.icacheTestPassed = true;
        SAF_CACHE_AccessCleanIcacheError();
    }

#endif
}

/**
****************************************************************************************
* @brief:  This function is CACHE error Correction/Auto-invalidation call back function.
* @return      void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static void SAF_CACHE_AccessErrorCorrectionCallBack(SAF_CACHE_TYPE errType)
{
    saf_cache_edc_report_path_test_t *pCacheTest = &s_cacheEdcReportPathTest;
#if SAF_DCACHE_SUPPORTED
    if ((errType == SAF_CACHE_TYPE_DCACHE) && (SAF_MCSR_DACHE_DATA_ARRAY_PARITY_ERROR_NOT_OCCURRED != MEMU.ERR_FLAG.B.SR_CE))
    {
        cacheTestFlag = CACHE_SAFETY_OP_CHANGED;
        pCacheTest->output.dcacheTestPassed = true;
        SAF_CACHE_AccessCleanDcacheError();
    }

#endif
#if SAF_ICACHE_SUPPORTED
    if ((errType == SAF_CACHE_TYPE_ICACHE) && (SAF_MCSR_IACHE_DATA_ARRAY_PARITY_ERROR_NOT_OCCURRED != MEMU.ERR_FLAG.B.SR_CE))
    {
        cacheTestFlag = CACHE_SAFETY_OP_CHANGED;
        pCacheTest->output.icacheTestPassed = true;
        SAF_CACHE_AccessCleanIcacheError();
    }

#endif
    MEMU_LLD_Reset();
    SAF_FCCU_RestoreFault(SAF_FCCU_FAILURE_MEMU_RAM_CE_CH_16);
    SAF_FCCU_RestoreFault(SAF_FCCU_FAILURE_MEMU_RAM_BOV_CH_18);
}

/**
****************************************************************************************
* @brief This function is used to store CACHE status.
* @param[in] cacheType :CACHE type.
* @param[out] pCacheEnableFlag :CACHE status.
* @return FS_STATUS
*         FS_STATUS_SUCCESS :Store CACHE status succeed.
*         FS_STATUS_ERROR :Store CACHE status failed.
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static FS_STATUS SAF_CACHE_AccessStore(const SAF_CACHE_TYPE cacheType, uint32_t *pCacheEnableFlag)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pCacheEnableFlag)
    {
        if (SAF_CACHE_TYPE_DCACHE == cacheType)
        {
#if SAF_DCACHE_SUPPORTED
            *pCacheEnableFlag = SAF_CACHE_L1CSR0_DCE_MASK & MFSPR(SAF_CORE_L1CSR0_SPR_ID);
            status = FS_STATUS_SUCCESS;
#endif
        }
        else if (SAF_CACHE_TYPE_ICACHE == cacheType)
        {
#if SAF_ICACHE_SUPPORTED
            *pCacheEnableFlag = SAF_CACHE_L1CSR1_ICE_MASK & MFSPR(SAF_CORE_L1CSR1_SPR_ID);
            status = FS_STATUS_SUCCESS;
#endif
        }
        else
        {
            /* Do nothing. */
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief This function is used to restore CACHE status.
* @param[in] cacheType :CACHE type.
* @param[in] cacheEnableFlag :CACHE status.
* @return FS_STATUS
*         FS_STATUS_SUCCESS :Restore CACHE status succeed.
*         FS_STATUS_ERROR :Restore CACHE status failed.
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static FS_STATUS SAF_CACHE_AccessRestore(const SAF_CACHE_TYPE cacheType, const uint32_t cacheEnableFlag)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
#if SAF_DCACHE_SUPPORTED
    FS_CORE_L1CSR0_tag l1csr0Register = { 0U };
#endif
#if SAF_ICACHE_SUPPORTED
    FS_CORE_L1CSR1_tag l1csr1Register = { 0U };
#endif

    if (SAF_CACHE_TYPE_DCACHE == cacheType)
    {
#if SAF_DCACHE_SUPPORTED
        if (SAF_CACHE_L1CSR0_DCE(0) != (cacheEnableFlag & SAF_CACHE_L1CSR0_DCE_MASK))
        {
            (void)SAF_CACHE_Enable(SAF_CACHE_TYPE_DCACHE);
        }
        else
        {
            (void)SAF_CACHE_Disable(SAF_CACHE_TYPE_DCACHE);
        }

        /* Read back. */
        l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);
        if ((l1csr0Register.R & SAF_CACHE_L1CSR0_DCE_MASK) != (cacheEnableFlag & SAF_CACHE_L1CSR0_DCE_MASK))
        {
            status = FS_STATUS_ERROR;
        }

#endif
    }
    else if (SAF_CACHE_TYPE_ICACHE == cacheType)
    {
#if SAF_ICACHE_SUPPORTED
        if (SAF_CACHE_L1CSR1_ICE(0) != (cacheEnableFlag & SAF_CACHE_L1CSR1_ICE_MASK))
        {
            (void)SAF_CACHE_Enable(SAF_CACHE_TYPE_ICACHE);
        }
        else
        {
            (void)SAF_CACHE_Disable(SAF_CACHE_TYPE_ICACHE);
        }

        /* Read back. */
        l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);
        if ((l1csr1Register.R & SAF_CACHE_L1CSR1_ICE_MASK) != (cacheEnableFlag & SAF_CACHE_L1CSR1_ICE_MASK))
        {
            status = FS_STATUS_ERROR;
        }

#endif
    }
    else
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

#if SAF_DCACHE_SUPPORTED
/**
****************************************************************************************
* @brief This function is used to test DCACHE ECC/EDC error auto handle function.
* @param[out] cacheErrTestType :CACHE auto handle test type.
* @return FS_STATUS
*         FS_STATUS_SUCCESS :CACHE auto handle test success.
*         FS_STATUS_ERROR :CACHE auto handle test failed.
*         FS_STATUS_TIMEOUT :Opertaion timeout.
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static FS_STATUS SAF_CACHE_AccessDcacheErrorAutoHandleTest(const SAF_CACHE_ERR_AUTO_HANDLE_TEST_TYPE cacheErrTestType)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t cacheStatus = 0U;
    uint32_t cacheReadData = 0U;
    uint32_t cacheRegRWValue = 0U;
    uint32_t dcacheDataArrayValue = 0U;
    uint32_t bitErrWriteVal= 0U;
    uint32_t bitErrReadVal= 0U;
    uint32_t bitErrInjectVal = 0U;
    FS_CORE_L1CSR0_tag l1csr0Register = { 0U };
    uint32_t operationTimeOut = 0U;
    const uint32_t cacheTestAddr = s_dcacheEDCTestAddr;

    for (uint32_t i = cacheTestAddr; i < cacheTestAddr + SAF_CORE_DCACHE_SET_SIZE * SAF_CACHE_TEST_SET_COUNT; i = i + 4U)
    {
        *((volatile uint32_t *)(i)) = SAF_CACHE_DCACHE_LOAD_VALUE;/* polyspace RTE:IDP */
    }

    (void)SAF_CACHE_AccessStore(SAF_CACHE_TYPE_DCACHE, (uint32_t *)&cacheStatus);

    /* Invalidate cache and enable cache. */
    l1csr0Register.R = SAF_CACHE_L1CSR0_DCE(SAF_CACHE_DCACHE_ENABLE)\
                        | SAF_CACHE_L1CSR0_DCINV(SAF_CACHE_DCACHE_INVALIDATION_OPERATION)\
                        | SAF_CACHE_L1CSR0_DCEA(SAF_CACHE_DCACHE_ERROR_ACTION_MACHINE_CHECK_SELECT)\
                        | SAF_CACHE_L1CSR0_DCECE(SAF_CACHE_DCACHE_ERROR_CHECKING_ENABLE);
    MTSPR(SAF_CORE_L1CSR0_SPR_ID, l1csr0Register.R);

    operationTimeOut = 0U;
    do
    {
        if (operationTimeOut++ >= SAF_CACHE_INVALIDATE_COUNT)
        {
            status = FS_STATUS_TIMEOUT;
            break;
        }
        l1csr0Register.R = MFSPR(SAF_CORE_L1CSR0_SPR_ID);
    }while(l1csr0Register.B.DCINV == SAF_CACHE_DCACHE_INVALIDATION_OPERATION);

    if (FS_STATUS_SUCCESS == status)
    {
        status = FS_STATUS_ERROR;

        /* Load data into DCACHE. */
        cacheReadData = *(uint32_t *)(cacheTestAddr);/* polyspace RTE:NIV,IDP */

        (void)SAF_CACHE_Disable(SAF_CACHE_TYPE_DCACHE);

        /* Select CACHE data array and read. */
        cacheRegRWValue = SAF_CACHE_CDACNTL_TD(SAF_CACHE_CDACNTL_DATA_ARRAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CWAY(SAF_CACHE_WAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CSET(SAF_CACHE_SET_SELECT)\
                            | SAF_CACHE_CDACNTL_WORD(SAF_CACHE_WORD_SELECT)\
                            | SAF_CACHE_CDACNTL_CACHE_SELECT(SAF_CACHE_CDACNTL_DATA_CACHE_SELECT)\
                            | SAF_CACHE_CDACNTL_RW(SAF_CACHE_CDACNTL_CACHE_ACCESS_READ_SELECT)\
                            | SAF_CACHE_CDACNTL_GO(SAF_CACHE_CDACNTL_GO_COMMAND_RW_ACTION_SELECT);

        MTDCR(DCR_CDACNTL, cacheRegRWValue);
        dcacheDataArrayValue = MFDCR(DCR_CDADATA);

        /* Generate single bit error. */
        if (SAF_CACHE_TEST_TYPE_SBC == cacheErrTestType)
        {
            bitErrInjectVal = SAF_CACHE_SBE_INJECT_XOR_DATA;
        }
        else
        {
            bitErrInjectVal = SAF_CACHE_MBE_INJECT_XOR_DATA;
        }

        bitErrWriteVal = dcacheDataArrayValue ^ bitErrInjectVal;

        /* Select CACHE data array and write. */
        cacheRegRWValue = SAF_CACHE_CDACNTL_TD(SAF_CACHE_CDACNTL_DATA_ARRAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CWAY(SAF_CACHE_WAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CSET(SAF_CACHE_SET_SELECT)\
                            | SAF_CACHE_CDACNTL_WORD(SAF_CACHE_WORD_SELECT)\
                            | SAF_CACHE_CDACNTL_CACHE_SELECT(SAF_CACHE_CDACNTL_DATA_CACHE_SELECT)\
                            | SAF_CACHE_CDACNTL_RW(SAF_CACHE_CDACNTL_CACHE_ACCESS_WRITE_SELECT)\
                            | SAF_CACHE_CDACNTL_GO(SAF_CACHE_CDACNTL_GO_COMMAND_RW_ACTION_SELECT);

        MTDCR(DCR_CDADATA, bitErrWriteVal);
        MTDCR(DCR_CDACNTL, cacheRegRWValue);

        /* Select CACHE data array and read. */
        cacheRegRWValue = SAF_CACHE_CDACNTL_TD(SAF_CACHE_CDACNTL_DATA_ARRAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CWAY(SAF_CACHE_WAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CSET(SAF_CACHE_SET_SELECT)\
                            | SAF_CACHE_CDACNTL_WORD(SAF_CACHE_WORD_SELECT)\
                            | SAF_CACHE_CDACNTL_CACHE_SELECT(SAF_CACHE_CDACNTL_DATA_CACHE_SELECT)\
                            | SAF_CACHE_CDACNTL_RW(SAF_CACHE_CDACNTL_CACHE_ACCESS_READ_SELECT)\
                            | SAF_CACHE_CDACNTL_GO(SAF_CACHE_CDACNTL_GO_COMMAND_RW_ACTION_SELECT);

        MTDCR(DCR_CDACNTL, cacheRegRWValue);
        bitErrReadVal = MFDCR(DCR_CDADATA);

        /* Error auto handle verify. */
        if (bitErrWriteVal == bitErrReadVal)
        {
            /* Enable cache, and select error auto handle. */
            cacheRegRWValue = SAF_CACHE_L1CSR0_DCE(SAF_CACHE_DCACHE_ENABLE)\
                                | SAF_CACHE_L1CSR0_DCECE(SAF_CACHE_DCACHE_ERROR_CHECKING_ENABLE)\
                                | SAF_CACHE_L1CSR0_DCEA(SAF_CACHE_DCACHE_ERROR_ACTION_AUTO_HANDLE_SELECT);

            MTSPR(SAF_CORE_L1CSR0_SPR_ID, cacheRegRWValue);

            cacheReadData = *(uint32_t *)cacheTestAddr;/* polyspace RTE:NIV,IDP */
            cacheReadData = *(uint32_t *)cacheTestAddr;/* polyspace RTE:NIV,IDP */

            (void)SAF_CACHE_Disable(SAF_CACHE_TYPE_DCACHE);

            /* Select CACHE data array and read. */
            cacheRegRWValue = SAF_CACHE_CDACNTL_TD(SAF_CACHE_CDACNTL_DATA_ARRAY_SELECT)\
                                | SAF_CACHE_CDACNTL_CWAY(SAF_CACHE_WAY_SELECT)\
                                | SAF_CACHE_CDACNTL_CSET(SAF_CACHE_SET_SELECT)\
                                | SAF_CACHE_CDACNTL_WORD(SAF_CACHE_WORD_SELECT)\
                                | SAF_CACHE_CDACNTL_CACHE_SELECT(SAF_CACHE_CDACNTL_DATA_CACHE_SELECT)\
                                | SAF_CACHE_CDACNTL_RW(SAF_CACHE_CDACNTL_CACHE_ACCESS_READ_SELECT)\
                                | SAF_CACHE_CDACNTL_GO(SAF_CACHE_CDACNTL_GO_COMMAND_RW_ACTION_SELECT);

            MTDCR(DCR_CDACNTL, cacheRegRWValue);
            bitErrReadVal = MFDCR(DCR_CDADATA);

            if (bitErrInjectVal == (bitErrReadVal ^ bitErrWriteVal))
            {
                /* Error auto handle check pass. */
                status = FS_STATUS_SUCCESS;
            }

            /* Clear SRAM ECC errors in MEMU caused by CACHE tests. */
            MEMU_LLD_ClearAllErrorFlag();
            MEMU_LLD_Reset();
        }
    }

    (void)SAF_CACHE_AccessRestore(SAF_CACHE_TYPE_DCACHE, cacheStatus);

    (void)cacheReadData;

    return status;
}
#endif

#if SAF_ICACHE_SUPPORTED
/**
****************************************************************************************
* @brief This function is used to test ICACHE ECC/EDC error auto handle function.
* @param[out] cacheErrTestType :CACHE auto handle test type.
* @return FS_STATUS
*         FS_STATUS_SUCCESS :CACHE auto handle test success.
*         FS_STATUS_ERROR :CACHE auto handle test failed.
*         FS_STATUS_TIMEOUT :Opertaion timeout.
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
static FS_STATUS SAF_CACHE_AccessIcacheErrorAutoHandleTest(const SAF_CACHE_ERR_AUTO_HANDLE_TEST_TYPE cacheErrTestType)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t cacheStatus = 0U;
    uint32_t cacheRegRWValue = 0U;
    uint32_t icacheDataArrayValue = 0U;
    uint32_t bitErrWriteVal= 0U;
    uint32_t bitErrReadVal= 0U;
    uint32_t bitErrInjectVal = 0U;
    FS_CORE_L1CSR1_tag l1csr1Register = { 0U };
    uint32_t operationTimeOut = 0U;
    const uint32_t cacheTestAddr = s_dcacheEDCTestAddr;

    for (uint32_t i = cacheTestAddr; i < cacheTestAddr + SAF_CORE_ICACHE_SET_SIZE * SAF_CACHE_TEST_SET_COUNT; i = i + 4U)
    {
        *((volatile uint32_t *)(i)) = SAF_CACHE_ICACHE_LOAD_VALUE;/* polyspace RTE:IDP */
    }

    (void)SAF_CACHE_AccessStore(SAF_CACHE_TYPE_ICACHE, (uint32_t *)&cacheStatus);

    l1csr1Register.R = SAF_CACHE_L1CSR1_ICE(SAF_CACHE_ICACHE_ENABLE)\
                        | SAF_CACHE_L1CSR1_ICINV(SAF_CACHE_ICACHE_INVALIDATION_OPERATION)\
                        | SAF_CACHE_L1CSR1_ICEA(SAF_CACHE_ICACHE_ERROR_ACTION_MACHINE_CHECK_SELECT)\
                        | SAF_CACHE_L1CSR1_ICECE(SAF_CACHE_ICACHE_ERROR_CHECKING_ENABLE);
    MTSPR(SAF_CORE_L1CSR1_SPR_ID, l1csr1Register.R);

    /* Invalidate cache and enable cache. */
    operationTimeOut = 0U;
    do
    {
        if (operationTimeOut++ >= SAF_CACHE_INVALIDATE_COUNT)
        {
            status = FS_STATUS_TIMEOUT;
            break;
        }
        l1csr1Register.R = MFSPR(SAF_CORE_L1CSR1_SPR_ID);
    }while(l1csr1Register.B.ICINV == SAF_CACHE_ICACHE_INVALIDATION_OPERATION);

    if (FS_STATUS_SUCCESS == status)
    {
        status = FS_STATUS_ERROR;

        /* Load data into ICACHE. */
        (*((void (*)(void))(cacheTestAddr)))();/* polyspace RTE:COR */

        (void)SAF_CACHE_Disable(SAF_CACHE_TYPE_ICACHE);

        /* Select CACHE data array and read. */
        cacheRegRWValue = SAF_CACHE_CDACNTL_TD(SAF_CACHE_CDACNTL_DATA_ARRAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CWAY(SAF_CACHE_WAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CSET(SAF_CACHE_SET_SELECT)\
                            | SAF_CACHE_CDACNTL_WORD(SAF_CACHE_WORD_SELECT)\
                            | SAF_CACHE_CDACNTL_CACHE_SELECT(SAF_CACHE_CDACNTL_INSTRUCTION_CACHE_SELECT)\
                            | SAF_CACHE_CDACNTL_RW(SAF_CACHE_CDACNTL_CACHE_ACCESS_READ_SELECT)\
                            | SAF_CACHE_CDACNTL_GO(SAF_CACHE_CDACNTL_GO_COMMAND_RW_ACTION_SELECT);

        MTDCR(DCR_CDACNTL, cacheRegRWValue);
        icacheDataArrayValue = MFDCR(DCR_CDADATA);

        /* Generate single bit error. */
        if (SAF_CACHE_TEST_TYPE_SBC == cacheErrTestType)
        {
            bitErrInjectVal = SAF_CACHE_SBE_INJECT_XOR_DATA;
        }
        else
        {
            bitErrInjectVal = SAF_CACHE_MBE_INJECT_XOR_DATA;
        }

        bitErrWriteVal = icacheDataArrayValue ^ bitErrInjectVal;

        /* Select CACHE data array and write. */
        cacheRegRWValue = SAF_CACHE_CDACNTL_TD(SAF_CACHE_CDACNTL_DATA_ARRAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CWAY(SAF_CACHE_WAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CSET(SAF_CACHE_SET_SELECT)\
                            | SAF_CACHE_CDACNTL_WORD(SAF_CACHE_WORD_SELECT)\
                            | SAF_CACHE_CDACNTL_CACHE_SELECT(SAF_CACHE_CDACNTL_INSTRUCTION_CACHE_SELECT)\
                            | SAF_CACHE_CDACNTL_RW(SAF_CACHE_CDACNTL_CACHE_ACCESS_WRITE_SELECT)\
                            | SAF_CACHE_CDACNTL_GO(SAF_CACHE_CDACNTL_GO_COMMAND_RW_ACTION_SELECT);

        MTDCR(DCR_CDADATA, bitErrWriteVal);
        MTDCR(DCR_CDACNTL, cacheRegRWValue);

        /* Select CACHE data array and read. */
        cacheRegRWValue = SAF_CACHE_CDACNTL_TD(SAF_CACHE_CDACNTL_DATA_ARRAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CWAY(SAF_CACHE_WAY_SELECT)\
                            | SAF_CACHE_CDACNTL_CSET(SAF_CACHE_SET_SELECT)\
                            | SAF_CACHE_CDACNTL_WORD(SAF_CACHE_WORD_SELECT)\
                            | SAF_CACHE_CDACNTL_CACHE_SELECT(SAF_CACHE_CDACNTL_INSTRUCTION_CACHE_SELECT)\
                            | SAF_CACHE_CDACNTL_RW(SAF_CACHE_CDACNTL_CACHE_ACCESS_READ_SELECT)\
                            | SAF_CACHE_CDACNTL_GO(SAF_CACHE_CDACNTL_GO_COMMAND_RW_ACTION_SELECT);

        MTDCR(DCR_CDACNTL, cacheRegRWValue);
        bitErrReadVal = MFDCR(DCR_CDADATA);

        /* Error auto handle verify. */
        if (bitErrWriteVal == bitErrReadVal)
        {
            /* Enable cache, and select error auto handle. */
            cacheRegRWValue = SAF_CACHE_L1CSR1_ICE(SAF_CACHE_ICACHE_ENABLE)\
                                | SAF_CACHE_L1CSR1_ICECE(SAF_CACHE_ICACHE_ERROR_CHECKING_ENABLE)\
                                | SAF_CACHE_L1CSR1_ICEA(SAF_CACHE_ICACHE_ERROR_ACTION_AUTO_HANDLE_SELECT);

            MTSPR(SAF_CORE_L1CSR1_SPR_ID, cacheRegRWValue);

            (*((void (*)(void))(cacheTestAddr)))();/* polyspace RTE:COR */
            (*((void (*)(void))(cacheTestAddr)))();/* polyspace RTE:COR */

            (void)SAF_CACHE_Disable(SAF_CACHE_TYPE_ICACHE);

            /* Select CACHE data array and read. */
            cacheRegRWValue = SAF_CACHE_CDACNTL_TD(SAF_CACHE_CDACNTL_DATA_ARRAY_SELECT)\
                                | SAF_CACHE_CDACNTL_CWAY(SAF_CACHE_WAY_SELECT)\
                                | SAF_CACHE_CDACNTL_CSET(SAF_CACHE_SET_SELECT)\
                                | SAF_CACHE_CDACNTL_WORD(SAF_CACHE_WORD_SELECT)\
                                | SAF_CACHE_CDACNTL_CACHE_SELECT(SAF_CACHE_CDACNTL_INSTRUCTION_CACHE_SELECT)\
                                | SAF_CACHE_CDACNTL_RW(SAF_CACHE_CDACNTL_CACHE_ACCESS_READ_SELECT)\
                                | SAF_CACHE_CDACNTL_GO(SAF_CACHE_CDACNTL_GO_COMMAND_RW_ACTION_SELECT);

            MTDCR(DCR_CDACNTL, cacheRegRWValue);
            bitErrReadVal = MFDCR(DCR_CDADATA);

            if (bitErrInjectVal == (bitErrReadVal ^ bitErrWriteVal))
            {
                /* Error auto handle check pass. */
                status = FS_STATUS_SUCCESS;
            }

            /* Clear SRAM ECC errors in MEMU caused by CACHE tests. */
            MEMU_LLD_ClearAllErrorFlag();
            MEMU_LLD_Reset();
        }
    }

    (void)SAF_CACHE_AccessRestore(SAF_CACHE_TYPE_ICACHE, cacheStatus);

    return status;
}
#endif

/*******************************************************************************
 * Global Functions
 ******************************************************************************/
/**
****************************************************************************************
* @brief:  This function is used to configure CMPU for cache ECC/EDC test.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     configure succeed
*               FS_STATUS_ERROR       configure failed
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
FS_STATUS SAF_CACHE_ConfigCmpu(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    const uint32_t mpuInst = 0U;

    /* Init CMPU config  */
    status = SAF_MPU_SafetyInit(mpuInst, &cache_mpu_Cfg, cache_mpuEntryArray, SAFETYMEMTEST_CMPU_ENTRY_COUNT_BY_CACHE);

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to enable CACHE.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     enable CACHE succeed
*               FS_STATUS_ERROR       enable CACHE failed
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
FS_STATUS SAF_CACHE_Enable(const SAF_CACHE_TYPE cacheType)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (SAF_CACHE_TYPE_DCACHE == cacheType)
    {
#if SAF_DCACHE_SUPPORTED
        if (false == SAF_CACHE_AccessDcacheIsEnabled())/*PRQA S 4558,4116*/
        {
            /* Invalidate cache before cache is enabled. */
            SAF_CACHE_AccessInvalidateDcache();
            SAF_CACHE_AccessWaitInvalidateDcacheDone();
            SAF_CACHE_AccessEnableDcache();
        }
#endif
    }
    else if (SAF_CACHE_TYPE_ICACHE == cacheType)
    {
#if SAF_ICACHE_SUPPORTED
        if (false == SAF_CACHE_AccessIcacheIsEnabled())/*PRQA S 4558,4116*/
        {
            /* Invalidate cache before cache is enabled. */
            SAF_CACHE_AccessInvalidateIcache();
            SAF_CACHE_AccessWaitInvalidateIcacheDone();
            SAF_CACHE_AccessEnableIcache();
        }
#endif
    }
    else
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to disable CACHE.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     disable CACHE succeed
*               FS_STATUS_ERROR       disable CACHE failed
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
FS_STATUS SAF_CACHE_Disable(const SAF_CACHE_TYPE cacheType)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (SAF_CACHE_TYPE_DCACHE == cacheType)
    {
#if SAF_DCACHE_SUPPORTED
        SAF_CACHE_AccessDisableDcache();
#endif
    }
    else if (SAF_CACHE_TYPE_ICACHE == cacheType)
    {
#if SAF_ICACHE_SUPPORTED
        SAF_CACHE_AccessDisableIcache();
#endif
    }
    else
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to be called by IVOR handle in cache test.
* @return       void
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
void SAF_CACHE_IvorHandler(void)
{
    if (CACHE_SAFETY_OP_INITIAL == cacheTestFlag)
    {
        SAF_CACHE_AccessErrorCallBack();
        cacheTestFlag = CACHE_SAFETY_OP_CHANGED;
    }
    else
    {
        /* Do nothing */
    }
}

/**
****************************************************************************************
* @brief:  This function is used to execute CACHE EDC report path test.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     CACHE EDC report path test succeed
*               FS_STATUS_ERROR       CACHE EDC report path test failed
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
FS_STATUS SAF_CACHE_EdcReportPathTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
    FS_STATUS switchStatus = FS_STATUS_SUCCESS;
    uint32_t cacheStatus = 0U;
    saf_cache_edc_report_path_test_result_t *pResult = &s_cacheEdcReportPathTest.output;
    uint32_t icacheAddr = s_icacheEDCTestAddr;
    uint32_t dcacheAddr = s_dcacheEDCTestAddr;
    uint32_t switchOn = 1;
    uint32_t switchOff = 0;

    if (FS_STATUS_SUCCESS != (FS_STATUS)SAF_FCCU_LLD_StartupCallbackSwitch(switchOn))
    {
        switchStatus = FS_STATUS_ERROR;
    }

#if SAF_DCACHE_SUPPORTED
    uint32_t data = 0U;
#endif
    *((volatile uint32_t *)(icacheAddr)) = SAF_CACHE_ICACHE_LOAD_VALUE;/*PRQA S 1259*//* polyspace RTE:IDP */
    *((volatile uint32_t *)(dcacheAddr)) = SAF_CACHE_DCACHE_LOAD_VALUE;/*PRQA S 1259*//* polyspace RTE:IDP */

    SAF_FCCU_LLD_CloseChReaction(SAF_FCCU_FAILURE_MEMU_RAM_CE_CH_16);
    SAF_FCCU_LLD_CloseChReaction(SAF_FCCU_FAILURE_MEMU_RAM_BOV_CH_18);

#if SAF_ICACHE_SUPPORTED
    pResult->icacheTestPassed = 0U;
    icache_func_ptr_t icacheFunc = (icache_func_ptr_t)icacheAddr;
    /* ICACHE EDC report path test */
    if (FS_STATUS_SUCCESS == SAF_CACHE_AccessStore(SAF_CACHE_TYPE_ICACHE, (uint32_t *)&cacheStatus))/*PRQA S 2991,2995*/
    {
        SAF_CACHE_Enable(SAF_CACHE_TYPE_ICACHE);

        cacheTestFlag = CACHE_SAFETY_OP_INITIAL;

        /* inject ICACHE error */
        SAF_CACHE_AccessInjectIcacheError();

        /* Read data for loading instruction into ICACHE */

        icacheFunc(); /*PRQA S 0305*//* polyspace RTE:COR */
        icacheFunc(); /*PRQA S 0305*//* polyspace RTE:COR */

        SAF_CACHE_AccessErrorCorrectionCallBack(SAF_CACHE_TYPE_ICACHE);
        if (cacheTestFlag == CACHE_SAFETY_OP_INITIAL)
        {
            status = FS_STATUS_ERROR;
            return status;
        }

        status = SAF_CACHE_AccessRestore(SAF_CACHE_TYPE_ICACHE, cacheStatus);

        if(FS_STATUS_SUCCESS != status)
        {
            status = FS_STATUS_ERROR;
            return status;
        }

        icacheFunc(); /*PRQA S 0305*//* polyspace RTE:COR */
        icacheFunc(); /*PRQA S 0305*//* polyspace RTE:COR */
    }
#endif

#if SAF_DCACHE_SUPPORTED
    pResult->dcacheTestPassed = 0U;

    /* DCACHE EDC report path test */
    if (FS_STATUS_SUCCESS == SAF_CACHE_AccessStore(SAF_CACHE_TYPE_DCACHE, (uint32_t *)&cacheStatus))/*PRQA S 2991,2995*/
    {
        SAF_CACHE_Enable(SAF_CACHE_TYPE_DCACHE);

        cacheTestFlag = CACHE_SAFETY_OP_INITIAL;

        /* inject DCACHE error */
        SAF_CACHE_AccessInjectDcacheError();

        /* Read data for loading data into DCACHE */
        data = *((volatile uint32_t *)(dcacheAddr));/*PRQA S 2982*//* polyspace RTE:IDP,NIV */
        data = *((volatile uint32_t *)(dcacheAddr));/*PRQA S 2982*//* polyspace RTE:IDP,NIV */
        (void)data;/*PRQA S 3119*/

        SAF_CACHE_AccessErrorCorrectionCallBack(SAF_CACHE_TYPE_DCACHE);
        if (cacheTestFlag == CACHE_SAFETY_OP_INITIAL)
        {
            status = FS_STATUS_ERROR;
            return status;
        }

        status = SAF_CACHE_AccessRestore(SAF_CACHE_TYPE_DCACHE, cacheStatus);

        if(FS_STATUS_SUCCESS != status)
        {
            status = FS_STATUS_ERROR;
            return status;
        }

        data = *((volatile uint32_t *)(dcacheAddr));/*PRQA S 2982*//* polyspace RTE:IDP,NIV */
        data = *((volatile uint32_t *)(dcacheAddr));/*PRQA S 2982*//* polyspace RTE:IDP,NIV */
    }
#endif

    if (FS_STATUS_SUCCESS != (FS_STATUS)SAF_FCCU_LLD_StartupCallbackSwitch(switchOff))
    {
        switchStatus = FS_STATUS_ERROR;
    }

    if (FS_STATUS_SUCCESS != switchStatus)
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to get the result of CACHE EDC report test.
* @param[out]   pTestResult   CACHE EDC report test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     CACHE EDC report test succeed
*               FS_STATUS_ERROR       CACHE EDC report test failed
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
FS_STATUS SAF_CACHE_EdcReportPathTestResult(saf_cache_edc_report_path_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        memcpy(pTestResult, &s_cacheEdcReportPathTest.output, sizeof(s_cacheEdcReportPathTest.output));/*PRQA S 0315,3200*/
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief This function is used to test DCACHE ECC/EDC error auto handle function.
* @param[out] cacheErrTestType :CACHE auto handle test type.
* @return FS_STATUS
*         FS_STATUS_SUCCESS :CACHE auto handle test success.
*         FS_STATUS_ERROR :CACHE auto handle test failed.
*         FS_STATUS_TIMEOUT :Opertaion timeout.
****************************************************************************************
*/
SAF_CACHE_SEC_CODE
FS_STATUS SAF_CACHE_ErrorAutoHandleTest(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

#if SAF_DCACHE_SUPPORTED
    status = SAF_CACHE_AccessDcacheErrorAutoHandleTest(SAF_CACHE_TEST_TYPE_SBC);
    if (FS_STATUS_SUCCESS == status)
    {
        status = SAF_CACHE_AccessDcacheErrorAutoHandleTest(SAF_CACHE_TEST_TYPE_MBE);
    }
#endif

#if SAF_ICACHE_SUPPORTED
    if (FS_STATUS_SUCCESS == status)
    {
        status = SAF_CACHE_AccessIcacheErrorAutoHandleTest(SAF_CACHE_TEST_TYPE_SBC);
        if (FS_STATUS_SUCCESS == status)
        {
            status = SAF_CACHE_AccessIcacheErrorAutoHandleTest(SAF_CACHE_TEST_TYPE_MBE);
        }
    }
#endif

    return status;
}

#endif

#ifdef __cplusplus
}
#endif


