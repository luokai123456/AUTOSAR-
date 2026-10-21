/**
****************************************************************************************
 * @FilePath: saf_sch.c
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Schedule C File
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
#include "SafetyTestHnd_Cfg.h"
#include "saf_cpu.h"/*PRQA S 0380*/
#include "saf_sch.h"
#include "saf_core.h"
#include "Saf_MemMap.h"
#include "saf_crc.h"
/*PRQA S 0315,0491,1296,2844,3200,3218,3408,4332 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_SCH_SEC_VAR_NO_INIT
static uint32_t v_prestartupTestIdx;

SAF_SCH_SEC_VAR_NO_INIT
static uint32_t v_startupTestIdx;

SAF_SCH_SEC_VAR_NO_INIT
static uint32_t v_runtimeTestIdx;
/**
****************************************************************************************
 * @brief: Global Variables
****************************************************************************************
*/
SAF_SCH_SEC_VAR_NO_INIT
saf_sch_err_container_type_t s_errContainer;

extern saf_sch_prestartup_t s_libPrestartupSch;

extern saf_sch_startup_t s_libStartupSch;

extern saf_sch_runtime_t s_libRuntimeSch;

extern saf_crc_self_test_result_t Crc_kSelfTestRst[CRCTST_SELF_TEST_MODE_COUNT];
/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/


/**
****************************************************************************************
* @brief:  The service run the prestartup tests.
* @return  void
****************************************************************************************
*/
SAF_SCH_SEC_CODE
void SAF_SCH_PrestartupTest(void)
{
    saf_sch_prestartup_t *pPreSafStartupSch = &s_libPrestartupSch;

    uint32_t i;

    if (pPreSafStartupSch->prestartupTestInitialized == (bool)false)/*PRQA S 4304*/
    {
    	pPreSafStartupSch->prestartupTestInitialized = (bool)true;/*PRQA S 4304*/

        for(i=0;i<SAFETYTESTHND_TOTAL_PRESTARTUP_TESTS;i++)/*PRQA S 2877*/
        {
            pPreSafStartupSch->pPrestartupTestErrStatus[0].ErrStatus[i] = (FS_STATUS)0;
        }

        for (v_prestartupTestIdx = 0; v_prestartupTestIdx < SAFETYTESTHND_TOTAL_PRESTARTUP_TESTS; v_prestartupTestIdx++)/*PRQA S 2461*/
        {
            if (pPreSafStartupSch->pPrestartupTestHandlerList[v_prestartupTestIdx] != NULL)
            {
            	pPreSafStartupSch->pPrestartupTestErrStatus[0].ErrStatus[v_prestartupTestIdx] = pPreSafStartupSch->pPrestartupTestHandlerList[v_prestartupTestIdx]->test_func(); /* polyspace RTE:COR */
            }
        }
    }
}

/**
****************************************************************************************
* @brief:  The service run the startup tests.
* @return  void
****************************************************************************************
*/
SAF_SCH_SEC_CODE
void SAF_SCH_StartupTest(void)
{
    saf_sch_startup_t *pSafStartupSch = &s_libStartupSch;

    uint32_t i;

    if (pSafStartupSch->startupTestInitialized == (bool)false)/*PRQA S 4304*/
    {
    	pSafStartupSch->startupTestInitialized = (bool)true;/*PRQA S 4304*/

        for(i=0;i<SAFETYTESTHND_TOTAL_STARTUP_TESTS;i++)
        {
            pSafStartupSch->pstartupTestErrStatus[0].ErrStatus[i] = (FS_STATUS)0;
        }

        for (v_startupTestIdx = 0; v_startupTestIdx < SAFETYTESTHND_TOTAL_STARTUP_TESTS; v_startupTestIdx++)/*PRQA S 2461*/
    	{
    		if (pSafStartupSch->pStartupTestHandlerList[v_startupTestIdx] != NULL)
    		{
    			pSafStartupSch->pstartupTestErrStatus[0].ErrStatus[v_startupTestIdx] = pSafStartupSch->pStartupTestHandlerList[v_startupTestIdx]->test_func(); /* polyspace RTE:COR */
    		}
    	}

    }


}

/**
****************************************************************************************
* @brief:  The service run the runtime tests.
* @return  void
****************************************************************************************
*/
SAF_SCH_SEC_CODE
void SAF_SCH_RuntimeTest(void)
{
	saf_sch_runtime_t *pRuntimeSch = &s_libRuntimeSch;
    static uint8_t exec_once = 0;

    if (exec_once == 0)
    {
        Crc_kSelfTestRst[0].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_SUCCESS;
        Crc_kSelfTestRst[1].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_SUCCESS;
        Crc_kSelfTestRst[2].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_SUCCESS;
        Crc_kSelfTestRst[3].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_SUCCESS;
        exec_once = 1;
    }

    for (v_runtimeTestIdx = 0; v_runtimeTestIdx < SAFETYTESTHND_TOTAL_RUNTIME_TESTS; v_runtimeTestIdx++)/*PRQA S 2461*/
    {
        if (pRuntimeSch->pRuntimeTestHandlerList[v_runtimeTestIdx] != NULL)
        {
        	pRuntimeSch->pruntimeTestErrStatus[0].ErrStatus[v_runtimeTestIdx] = pRuntimeSch->pRuntimeTestHandlerList[v_runtimeTestIdx]->test_func(); /* polyspace RTE:COR */
        }
    }
}


/**
****************************************************************************************
* @brief:  This function is used to get the prestartup test result.
* @param[out]   pResult   test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     Get prestartup test result succeed
*               FS_STATUS_ERROR       Get prestartup test result failed
****************************************************************************************
*/
SAF_SCH_SEC_CODE
FS_STATUS SAF_SCH_PrestartupErrReportResult(saf_sch_prestartup_err_t *TestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != TestResult)
    {
        memmove(TestResult, &s_libPrestartupSch.pPrestartupTestErrStatus[0].ErrStatus[0], sizeof(s_libPrestartupSch.pPrestartupTestErrStatus[0])); /*PRQA S 1495*/  /* polyspace RTE:STD_LIB */
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to get the startup test result.
* @param[out]   pResult   test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     Get startup test result succeed
*               FS_STATUS_ERROR       Get startup test result failed
****************************************************************************************
*/
SAF_SCH_SEC_CODE
FS_STATUS SAF_SCH_StartupErrReportResult(saf_sch_startup_err_t *TestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != TestResult)
    {
    	memmove(TestResult, &s_libStartupSch.pstartupTestErrStatus[0].ErrStatus[0], sizeof(s_libStartupSch.pstartupTestErrStatus[0])); /*PRQA S 1495*/ /* polyspace RTE:STD_LIB */
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to get the runtime test result.
* @param[out]   pResult   test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     Get runtime test result succeed
*               FS_STATUS_ERROR       Get runtime test result failed
****************************************************************************************
*/
SAF_SCH_SEC_CODE
FS_STATUS SAF_SCH_RuntimeErrReportResult(saf_sch_runtime_err_t *TestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != TestResult)
    {
    	memmove(TestResult, &s_libRuntimeSch.pruntimeTestErrStatus[0].ErrStatus[0], sizeof(s_libRuntimeSch.pruntimeTestErrStatus[0])); /*PRQA S 1495*/  /* polyspace RTE:STD_LIB */
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
