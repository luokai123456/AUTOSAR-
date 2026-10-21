/**
****************************************************************************************
 * @FilePath: saf_smpu.c
 * @Author: CCORE
 * @Date: 2024-03-05
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety SMPU C File
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
#include "saf_smpu.h"/*PRQA S 0380*/
#include "saf_cache.h"
#include "saf_core.h"
#include "mcu_lld.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,1006,1843,1840,3200,3218,3344,3408,4116,4304,4558 EOF*/
#if SAF_SMPU_SUPPORTED

/**
****************************************************************************************
 * @brief: Definitions
****************************************************************************************
*/
#define SAF_SMPU_INSTANCE_COUNT                            SMPU_INSTANCE_COUNT

/* Default value of access right */
#define DEFAULT_ACCESS_RIGHT                               SMPU_RW

/**
****************************************************************************************
 * @brief: Variables
****************************************************************************************
*/
SAF_SMPU_SEC_VAR_INIT
uint32_t smpuTestFlag = 0U;
SAF_SMPU_SEC_VAR_INIT
uint32_t smpuTestInst = 0U;

SAF_SMPU_SEC_CONFIG_DATA
SMPU_Type * const smpuTest[SAF_SMPU_INSTANCE_COUNT] = { SMPU0_PTR, SMPU1_PTR };/*PRQA S 1514*/

/* SMPU access right test object */
SAF_SMPU_SEC_VAR_INIT
static saf_smpu_access_right_test_t s_smpuAccessRightTest =
{
    .output =
    {
        .readLimitPassed = 0,
        .writeLimitPassed  = 0,
    },
};/*PRQA S 0704*/

/* Expected error for write */
SAF_SMPU_SEC_VAR_INIT
static smpu_acc_err_t expectWriteErr =
{
    .master     = CUR_DEMO_MASTER_CORE,                /* Error Current core master */
    .overrun    = 0U,                                  /* Error overrun */
    .attributes = SMPU_DATA_ACCESS_IN_SUPERVISOR_MODE, /* Error data access in supervisor mode */
    .accType    = SMPU_ERR_TYPE_WRITE,                 /* Error read access */
    .accCtr     = 0x400000U,                           /* Error occurs on region 2 */
    .addr       = 0U,                                  /* Error address, Note: need set by user */
};

/* Expected error for read */
SAF_SMPU_SEC_VAR_INIT
static smpu_acc_err_t expectReadErr =
{
    .master     = CUR_DEMO_MASTER_CORE,                /* Error Current core master */
    .overrun    = 0U,                                  /* Error overrun */
    .attributes = SMPU_DATA_ACCESS_IN_SUPERVISOR_MODE, /* Error data access in supervisor mode */
    .accType    = SMPU_ERR_TYPE_READ,                  /* Error read access */
    .accCtr     = 0x200000U,                           /* Error occurs on region 1 */
    .addr       = 0U,                                  /* Error address, Note: need set by user */
};

/**
****************************************************************************************
 * @brief: Local Function
****************************************************************************************
*/

/**
****************************************************************************************
* @brief:  This function shall be used to compare error information.
* @param[in]    error1         target address of testing.
* @param[in]    error2         expect status.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     compared succeed
*               FS_STATUS_ERROR       compared failed
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
static FS_STATUS SAF_SMPU_ExpectErrorCompare(smpu_acc_err_t error1, smpu_acc_err_t error2)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if ((error1.master == error2.master)
        && (error1.overrun == error2.overrun)
        && (error1.attributes == error2.attributes)
        && (error1.accType == error2.accType)
        && (error1.accCtr  == error2.accCtr)
        && (error1.addr == error2.addr))
    {
        status = FS_STATUS_SUCCESS;
    }
    return status;
}
/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/
/**
****************************************************************************************
* @brief:  This function is used to initialize SMPU.
* @param[in]   smpuInst       SMPU instance.
* @param[in]   regionCnt      SMPU region count.
* @param[in]   userConfigPtr  SMPU entry and master access right configuration point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         initialize succeed
*              FS_STATUS_ERROR           initialize failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_SafetyInit(const uint32_t smpuInst, const uint8_t regionCnt, const smpu_config_t *userConfigPtr)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if ((SAF_SMPU_INSTANCE_COUNT <= smpuInst) || (NULL == userConfigPtr))
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        if (!SAF_CORE_IsSafetyCore())
        {
            status = FS_STATUS_ERROR_CORE_ID;
        }
        else
        {
            if (STATUS_SUCCESS != SMPU_LLD_Init(smpuInst, regionCnt, userConfigPtr))
            {
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to de-initialize SMPU.
* @param[in]   smpuInst       SMPU instance.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         de-initialize succeed
*              FS_STATUS_ERROR           de-initialize failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_SafetyDeinit(const uint32_t smpuInst)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    
    if (SAF_SMPU_INSTANCE_COUNT <= smpuInst)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        if (!SAF_CORE_IsSafetyCore())
        {
            status = FS_STATUS_ERROR_CORE_ID;
        }
        else
        {
            if (STATUS_SUCCESS != SMPU_LLD_Deinit(smpuInst))
            {
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to configure the SMPU region.
* @param[in]   smpuInst         SMPU instance.
* @param[in]   regionNum        SMPU region number.
* @param[in]   regionConfigPtr  SMPU region configuration point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         configure region succeed
*              FS_STATUS_ERROR           configure region failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_SafetySetRegionConfig(uint32_t smpuInst, uint8_t regionNum, const smpu_config_t *regionConfigPtr)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if ((SAF_SMPU_INSTANCE_COUNT <= smpuInst) || (NULL == regionConfigPtr))
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        if (!SAF_CORE_IsSafetyCore())
        {
            status = FS_STATUS_ERROR_CORE_ID;
        }
        else
        {
            if (STATUS_SUCCESS != SMPU_LLD_SetRegionConfig(smpuInst, regionNum, regionConfigPtr))
            {
                status = FS_STATUS_ERROR;
            }
        }
    }
    
    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to set the SMPU region address.
* @param[in]   smpuInst         SMPU instance.
* @param[in]   regionNum        SMPU region number.
* @param[in]   startAddr        SMPU region start address.
* @param[in]   endAddr          SMPU region end address.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         set region address succeed
*              FS_STATUS_ERROR           set region address failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_SafetySetRegionAddr(const uint32_t smpuInst, const uint8_t regionNum, const uint32_t startAddr, const uint32_t endAddr)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (SAF_SMPU_INSTANCE_COUNT <= smpuInst)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        if (!SAF_CORE_IsSafetyCore())
        {
            status = FS_STATUS_ERROR_CORE_ID;
        }
        else
        {
            if (STATUS_SUCCESS != SMPU_LLD_SetRegionAddr(smpuInst, regionNum, startAddr, endAddr))
            {
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to enable the SMPU region.
* @param[in]   smpuInst         SMPU instance.
* @param[in]   regionNum        SMPU region number.
* @param[in]   enable           SMPU region enable or disable.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         enable or disable region succeed
*              FS_STATUS_ERROR           enable or disable region failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_SafetyEnableRegion(const uint32_t smpuInst, const uint8_t regionNum, const bool enable)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (SAF_SMPU_INSTANCE_COUNT <= smpuInst)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        if (!SAF_CORE_IsSafetyCore())
        {
            status = FS_STATUS_ERROR_CORE_ID;
        }
        else
        {
            if (STATUS_SUCCESS != SMPU_LLD_EnableRegion(smpuInst, regionNum, enable))
            {
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to set the master access rights.
* @param[in]   smpuInst         SMPU instance.
* @param[in]   regionNum        SMPU region number.
* @param[in]   pMasterAccRight  Master access rights information point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         set the master access rights succeed
*              FS_STATUS_ERROR           set the master access rights failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_SafetySetMasterAccessRights(const uint32_t smpuInst, const uint8_t regionNum, const smpu_master_access_right_t *pMasterAccRight)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if ((SAF_SMPU_INSTANCE_COUNT <= smpuInst) || (NULL == pMasterAccRight))
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        if (!SAF_CORE_IsSafetyCore())
        {
            status = FS_STATUS_ERROR_CORE_ID;
        }
        else
        {
            if (STATUS_SUCCESS != SMPU_LLD_SetMasterAccessRights(smpuInst, regionNum, (const smpu_master_acc_right_t *)pMasterAccRight))/*PRQA S 0310*/
            {
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to configure the SMPU region lock.
* @param[in]   smpuInst         SMPU instance.
* @param[in]   regionNum        SMPU region number.
* @param[in]   lockConfig       Region lock or unlock.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         configure the SMPU region lock succeed
*              FS_STATUS_ERROR           configure the SMPU region lock failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_SafetySetRegionLockConfig(const uint32_t smpuInst, const uint8_t regionNum, const uint8_t lockConfig)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    
    if (SAF_SMPU_INSTANCE_COUNT <= smpuInst)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        if (!SAF_CORE_IsSafetyCore())
        {
            status = FS_STATUS_ERROR_CORE_ID;
        }
        else
        {
            if (STATUS_SUCCESS != SMPU_LLD_SetRegionLockConfig(smpuInst, regionNum, lockConfig))
            {
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to get the configuration of appointed SMPU region lock.
* @param[in]   smpuInst         SMPU instance.
* @param[in]   regionNum        SMPU region number.
* @param[out]  pRegionLock      Region lock or unlock information point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         get region lock configuration succeed
*              FS_STATUS_ERROR           get region lock configuration failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_SafetyGetRegionLockInfo(const uint32_t smpuInst, const uint8_t regionNum, uint8_t *pRegionLock)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if ((SAF_SMPU_INSTANCE_COUNT <= smpuInst) || (NULL == pRegionLock))
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
        if (!SAF_CORE_IsSafetyCore())
        {
            status = FS_STATUS_ERROR_CORE_ID;
        }
        else
        {

            if (STATUS_SUCCESS != SMPU_LLD_GetRegionLockInfo(smpuInst, regionNum, pRegionLock))
            {
                status = FS_STATUS_ERROR;
            }
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to get the detail SMPU error information.
* @param[in]   smpuInst         SMPU instance.
* @param[in]   errorNum         Error master number.
* @param[out]  errInfoPtr       The pointer of error information..
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         get detail SMPU error information succeed
*              FS_STATUS_ERROR           get detail SMPU error information failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_SafetyGetDetailErrorInfo(const uint32_t smpuInst, const uint8_t errorNum, smpu_acc_err_t *errInfoPtr)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if ((SAF_SMPU_INSTANCE_COUNT <= smpuInst) || (NULL == errInfoPtr))
    {
        status = FS_STATUS_DATA_INVALID;
    }
    else
    {     
        if (!SAF_CORE_IsSafetyCore())
        {
            status = FS_STATUS_ERROR_CORE_ID;
        }
        else
        {
            if (STATUS_SUCCESS == SMPU_LLD_GetDetailErrorInfo(smpuInst, errorNum, errInfoPtr))
            {
                status = FS_STATUS_SUCCESS;
            }
        }
    }

    return status;
}


/**
****************************************************************************************
* @brief:  This function is used to be called by IVOR handle in SMPU test.
* @return       void
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
void SAF_SMPU_IvorHandler(void)
{
    if (smpuTestFlag == 1U)
    {
        (void)SMPU_LLD_EnableRegion(smpuTestInst, 1U, 1U);
        (void)SMPU_LLD_EnableRegion(smpuTestInst, 2U, 1U);
    }
    else
    {
        /* Do nothing */
    }
}

/**
****************************************************************************************
* @brief:  This function shall be used to get SMPU access right test result.
* @param[out]   pTestResult   SMPU access right test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get result succeed
*               FS_STATUS_ERROR       get result failed
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_AccessRightTestResult(saf_smpu_access_right_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (pTestResult != NULL)
    {
        memcpy(pTestResult, &s_smpuAccessRightTest.output, sizeof(s_smpuAccessRightTest.output));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to execute SMPU access right test.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     SMPU access right test succeed
*               FS_STATUS_ERROR       SMPU access right test failed
****************************************************************************************
*/
SAF_SMPU_SEC_CODE
FS_STATUS SAF_SMPU_AccessRightTest(void)/*PRQA S 3006*/
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    const saf_smpu_access_right_test_param_t *pParam  = &s_smpuAcRightTestCfg;
    saf_smpu_access_right_test_result_t *pResult = &s_smpuAccessRightTest.output;
    const uint8_t regionCnt = SAFETYMEMTEST_SMPU_0_ENTRY_COUNT;
    uint32_t testSmpuData = SMPU0_DEMO_TEST_DATA;
    uint32_t testSmpuAddr = SMPU0_DEMO_TEST_PROTECT_ADDR;
    uint32_t readSmpuValue = 0U;
    uint32_t masterMask = 0U;
    uint8_t coreId = 0U;
    smpu_acc_err_t reportError;

    coreId = SAF_MCU_LLD_Get_Core_Id();/*PRQA S 4424*/
    masterMask = ((1 << (SAF_SMPU_MASTER_MAX_INDEX - coreId))); /*PRQA S 4434,4543*/ /* polyspace RTE:SHF */
    smpuTestFlag = 1U;

    FS_CORE_L1CSR0_tag l1csr0Register = {0UL};/*PRQA S 3604*/
    FS_CORE_L1CSR1_tag l1csr1Register = {0UL};/*PRQA S 3604*/
    l1csr0Register.R = 0U;
    l1csr1Register.R = 0U;
    MTSPR(SAF_CORE_L1CSR0_SPR_ID, l1csr0Register.R);
    MTSPR(SAF_CORE_L1CSR1_SPR_ID, l1csr1Register.R);

    if((MFSPR(SAF_CORE_L1CSR0_SPR_ID)) || (MFSPR(SAF_CORE_L1CSR1_SPR_ID)))/*PRQA S 4115*/
    {
        status = FS_STATUS_ERROR;
        return status;
    }

    memset(pResult, 0, sizeof(saf_smpu_access_right_test_result_t));

    if (FS_STATUS_SUCCESS != SAF_SMPU_SafetyInit(smpuTestInst, regionCnt, (const smpu_config_t *)smpu0EntryArray))
    {
        status = FS_STATUS_ERROR;
        return status;
    }

    /* Region 1 (W)| Region 2 (R)  overlapping */
    /* Write address in sram which protected by SMPU */
    *((uint32_t *)testSmpuAddr) = testSmpuData;  /* polyspace RTE:IDP */

    /* Check error status (Except: write OK) */
    status = SAF_SMPU_SafetyGetDetailErrorInfo(smpuTestInst, coreId, &reportError);
    if (FS_STATUS_SUCCESS == status)
    {
        status = FS_STATUS_ERROR;
        return status;
    }

    /* Read address in sram which protected by SMPU */
    readSmpuValue = *((uint32_t *)testSmpuAddr);/* polyspace RTE:NIV,IDP */
    (void)readSmpuValue;/*PRQA S 3119*/

    status = SAF_SMPU_SafetyGetDetailErrorInfo(smpuTestInst, coreId, &reportError);
    if (FS_STATUS_SUCCESS == status)
    {
        status = FS_STATUS_ERROR;
        return status;
    }

    expectWriteErr.addr = testSmpuAddr;
    expectWriteErr.master = coreId;
    expectReadErr.addr = testSmpuAddr;
    expectReadErr.master = coreId;

    if (pParam->readLimitSelect)
    {
        pResult->readLimitPassed = (bool)false;

        /*Only Write allowed  Region 1 (R) | Region 2 (W) --> Region 2 (W)*/
        /* Disable region 1 (disable read permission) */
        status = SAF_SMPU_SafetyEnableRegion(smpuTestInst, 1U, 0U);

        if(FS_STATUS_SUCCESS == status)
        {
            /* Write address in sram which protected by SMPU */
            *((uint32_t *)testSmpuAddr) = testSmpuData; /* polyspace RTE:IDP */

            /* Check error status (Except: write OK) */
            status = SAF_SMPU_SafetyGetDetailErrorInfo(smpuTestInst, coreId, &reportError);
            if (FS_STATUS_SUCCESS == status)
            {
                status = FS_STATUS_ERROR;
                return status;
            }

            /* Read address in sram which protected by SMPU */
            readSmpuValue = *((uint32_t *)testSmpuAddr);/* polyspace RTE:NIV,IDP */
            (void)readSmpuValue;/*PRQA S 3119*/

            if ((masterMask & (smpuTest[smpuTestInst]->CESR0.B.MERR)) != 0)/*PRQA S 2844*//* polyspace RTE:IDP */
            {
                /* report error master number */
                reportError.master = (uint8_t)(smpuTest[smpuTestInst]->ERROR_REG[0].EDR.B.EMN);

                /* report error attribute */
                reportError.attributes = (uint8_t)(smpuTest[smpuTestInst]->ERROR_REG[0].EDR.B.EATTR);

                /* report error access type */
                reportError.accType = (uint8_t)(smpuTest[smpuTestInst]->ERROR_REG[0].EDR.B.ERW);

                /* report Error Access Control Detail */
                reportError.accCtr = (uint32_t)(smpuTest[smpuTestInst]->ERROR_REG[0].EDR.B.EACD);

                /* report error address */
                reportError.addr = smpuTest[smpuTestInst]->ERROR_REG[0].EAR.R;

                /* report master error overrun status */
                reportError.overrun = (((smpuTest[smpuTestInst]->CESR1.B.MEOVR
                                        & (1UL << (SAF_SMPU_MASTER_MAX_INDEX - 0)))
                                        != 0U) ? 1U : 0U);

                /* clear error flag */
                smpuTest[smpuTestInst]->CESR0.B.MERR = (1UL << (SAF_SMPU_MASTER_MAX_INDEX - 0));
            }

            status = SAF_SMPU_ExpectErrorCompare(reportError, expectReadErr); /* polyspace RTE:NIVL */
            if (FS_STATUS_SUCCESS != status)
            {
                /* error not meet expect */
                status = FS_STATUS_ERROR;
            }
            else
            {
                /* error meet expect */
                pResult->readLimitPassed = (bool)true;
            }
        }
    }

    if (pParam->writeLimitSelect)
    {
        pResult->writeLimitPassed = (bool)false;
        /* Region 1 (R) | Region 2 (W) --> Region 1 (R)*/

        /* Disable region 2 (disable write permission) */
        status = SAF_SMPU_SafetyEnableRegion(smpuTestInst, 2U, 0U);

        if(FS_STATUS_SUCCESS == status)
        {
            /* Read address in sram which protected by SMPU */
            readSmpuValue = *((uint32_t *)testSmpuAddr);/* polyspace RTE:NIV,IDP */
            (void)readSmpuValue;/*PRQA S 3119*/

            /* Check error status (Except: read OK) */
            status = SAF_SMPU_SafetyGetDetailErrorInfo(smpuTestInst, coreId, &reportError);
            if (FS_STATUS_SUCCESS == status)
            {
                status = FS_STATUS_ERROR;
                return status;
            }

            /* 2.1 Write address in sram which protected by SMPU */
            *((uint32_t *)testSmpuAddr) = testSmpuData; /* polyspace RTE:IDP */

            if ((masterMask & (smpuTest[smpuTestInst]->CESR0.B.MERR)) != 0U)/* polyspace RTE:IDP */
            {
                /* report error master number */
                reportError.master = (uint8_t)(smpuTest[smpuTestInst]->ERROR_REG[0].EDR.B.EMN);

                /* report error attribute */
                reportError.attributes = (uint8_t)(smpuTest[smpuTestInst]->ERROR_REG[0].EDR.B.EATTR);

                /* report error access type */
                reportError.accType = (uint8_t)(smpuTest[smpuTestInst]->ERROR_REG[0].EDR.B.ERW);

                /* report Error Access Control Detail */
                reportError.accCtr = (uint32_t)(smpuTest[smpuTestInst]->ERROR_REG[0].EDR.B.EACD);

                /* report error address */
                reportError.addr = smpuTest[smpuTestInst]->ERROR_REG[0].EAR.R;

                /* report master error overrun status */
                reportError.overrun = (((smpuTest[smpuTestInst]->CESR1.B.MEOVR
                                        & (1UL << (SAF_SMPU_MASTER_MAX_INDEX - 0)))
                                        != 0U) ? 1U : 0U);

                /* clear error flag */
                smpuTest[smpuTestInst]->CESR0.B.MERR = (1UL << (SAF_SMPU_MASTER_MAX_INDEX - 0));
            }
            /* Check error status (Except: write fail, trigger smpu error) */
            status = SAF_SMPU_ExpectErrorCompare(reportError, expectWriteErr); /* polyspace RTE:NIVL */
            if (FS_STATUS_SUCCESS != status)
            {
                /* error not meet expect */
                status = FS_STATUS_ERROR;
            }
            else
            {
                /* error meet expect */
                pResult->writeLimitPassed = (bool)true;
            }
        }
    }

    smpuTestFlag = 0U;

    return status;
}

#endif

#ifdef __cplusplus
}
#endif
