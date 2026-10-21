/**
****************************************************************************************
 * @FilePath: saf_mpu.c
 * @Author: CCORE
 * @Date: 2024-01-22
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety MPU C File
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
#include "saf_mpu.h"/*PRQA S 0380*/
#include "saf_core.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,1006,1843 EOF*/
/*PRQA S 2991,2992,2995,2996 EOF*/
/*PRQA S 3200,3344,3408,4304 EOF*/
#if SAF_MPU_SUPPORTED

/**
****************************************************************************************
 * @brief: Definitions
****************************************************************************************
*/
#define SAF_MPU_INSTANCE_COUNT                             CMPU_INSTANCE_COUNT
#define SAF_MPU_ENTRY_MAX_COUNT                            CMPU_ENTRY_MAX_COUNT


/**
****************************************************************************************
 * @brief: Variables
****************************************************************************************
*/
/* Define for cmpu error recovery */
SAF_CMPU_SEC_VAR_INIT
uint32_t mpuTestFlag = 0U;
SAF_CMPU_SEC_VAR_INIT
uint32_t mpuTestResult = CMPU_OP_SUCC;

/* MPU access right test object */
SAF_CMPU_SEC_VAR_INIT
static saf_mpu_access_right_test_t s_mpuAccessRightTest =
{
    .output =
    {
        .readLimitPassed = 0,
        .writeLimitPassed  = 0,
    },
};/*PRQA S 0704*/

/**
****************************************************************************************
 * @brief: Local Function
****************************************************************************************
*/
/**
****************************************************************************************
* @brief:  This function shall be used to execute CMPU read right limit test.
* @param[in]    addr         target address of testing.
* @param[in]    exptStatus   expect status.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     read right limit test succeed
*               FS_STATUS_ERROR       read right limit test failed
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
static FS_STATUS __attribute__((ghs_optimize(Onone))) SAF_MPU_ReadTest(uint32_t addr, uint32_t exptStatus)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t readValue = 0U;

    /* Clear mpuTestResult */
    mpuTestResult = CMPU_OP_SUCC;

    /* Read operate */
    readValue = *((uint32_t *)addr);/* polyspace RTE:NIV,IDP */
    (void)readValue; /* PRQA S 3119 */

    /* Check mpuTestResult */
    if (mpuTestResult != exptStatus)
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function shall be used to execute CMPU read right limit test.
* @param[in]   addr         target address of testing.
* @param[in]   exptStatus   expect status.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     read right limit test succeed
*               FS_STATUS_ERROR       read right limit test failed
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
static FS_STATUS __attribute__((ghs_optimize(Onone))) SAF_MPU_WriteTest(uint32_t addr, uint32_t exptStatus)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    /* 0x00040004U is bl instruction */
    uint32_t testData = 0x00040004U;

    /* Clear mpuTestResult */
    mpuTestResult = CMPU_OP_SUCC;

    /* Write operate */
    *((uint32_t *)addr) = testData; /* polyspace RTE:IDP */

    /* Check mpuTestResult */
    if (mpuTestResult != exptStatus)
    {
        status = FS_STATUS_ERROR;
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
* @brief:  This function shall be used to initialize the MPU configuration.
* @param[in]   mpuInst      CMPU instance.
* @param[in]   mpuConfig    CMPU module configuration point.
* @param[in]   entryConfig  CMPU entry configuration point.
* @param[in]   entryCnt     CMPU entry count.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         initialize succeed
*              FS_STATUS_ERROR           initialize failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
FS_STATUS SAF_MPU_SafetyInit(const uint32_t mpuInst, const cmpu_module_cfg_t *mpuConfig, const cmpu_entry_cfg_t *entryConfig, const uint8_t entryCnt)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if ((SAF_MPU_INSTANCE_COUNT <= mpuInst) || (NULL == mpuConfig) || (NULL == entryConfig) || (SAF_MPU_ENTRY_MAX_COUNT < entryCnt))
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
		if (STATUS_SUCCESS != SAF_CMPU_LLD_Init(mpuConfig, entryConfig, entryCnt))
		{
			status = FS_STATUS_ERROR;
		}
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to de-initialize CMPU.
* @param[in]   mpuInst      CMPU instance.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         de-initialize succeed
*              FS_STATUS_ERROR           de-initialize failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
FS_STATUS SAF_MPU_SafetyDeinit(const uint8_t mpuInst)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if (SAF_MPU_INSTANCE_COUNT <= mpuInst)
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
		SAF_CMPU_LLD_DeInit();
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function reads the requested entry from the CMPU and returns as a structure.
* @param[in]   mpuInst       CMPU instance.
* @param[in]   regionId      CMPU region id.
* @param[in]   regType       CMPU region type.
* @param[in]   entryConfig   CMPU entry configuration point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         reads the requested entry succeed
*              FS_STATUS_ERROR           reads the requested entry failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
FS_STATUS SAF_MPU_SafetyGetEntryConfig(uint32_t mpuInst, uint8_t regionId, const uint8_t regType, cmpu_entry_cfg_t *entryConfig)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if ((SAF_MPU_INSTANCE_COUNT <= mpuInst) || (NULL == entryConfig))
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
		if (STATUS_SUCCESS != SAF_CMPU_LLD_GetEntryConfig(regionId, regType, entryConfig))
		{
			status = FS_STATUS_ERROR;
		}
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function reads the current configuration of the CMPU module.
* @param[in]   mpuInst       CMPU instance.
* @param[in]   mpuConfig     CMPU module configuration point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         reads the module configuration succeed
*              FS_STATUS_ERROR           reads the module configuration failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
FS_STATUS SAF_MPU_SafetyGetModuleConfig(uint32_t mpuInst, cmpu_module_cfg_t *mpuConfig)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    if ((SAF_MPU_INSTANCE_COUNT <= mpuInst) || (NULL == mpuConfig))
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
		if (STATUS_SUCCESS != SAF_CMPU_LLD_GetModuleConfig(mpuConfig))
		{
			status = FS_STATUS_ERROR;
		}
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function set entry configuration into CMPU.
* @param[in]   mpuInst         CMPU instance.
* @param[in]   entryConfig     CMPU entry configuration point.
* @return      FS_STATUS
*              FS_STATUS_SUCCESS         set entry configuration succeed
*              FS_STATUS_ERROR           set entry configuration failed
*              FS_STATUS_ERROR_CORE_ID   current core is not safety core
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
FS_STATUS SAF_MPU_SafetySetEntryConfig(const uint32_t mpuInst, const cmpu_entry_cfg_t *entryConfig)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    
    if ((SAF_MPU_INSTANCE_COUNT <= mpuInst) || (NULL == entryConfig))
    {
        status = FS_STATUS_ERROR;
    }
    else
    {
		if (STATUS_SUCCESS != SAF_CMPU_LLD_SetEntry(entryConfig))
		{
			status = FS_STATUS_ERROR;
		}
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to be called by IVOR handle in MPU test(CMPU error recovery).
* @return       void
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
void SAF_MPU_IvorHandler(void)
{
    if (mpuTestFlag == 1U)
    {
    	if(0 == GetCoreID())
    	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE0
			/* Set entry 1 permission to write only */
			mpuEntryArrayZ70[1].sRight = CMPU_W;
			(void)SAF_CMPU_LLD_SetEntry(&(mpuEntryArrayZ70[1]));
			/* Set entry 2 permission to read only */
			mpuEntryArrayZ70[2].sRight = CMPU_R;
			(void)SAF_CMPU_LLD_SetEntry(&(mpuEntryArrayZ70[2]));
#endif
    	}
    	else if (1 == GetCoreID())
    	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE1
			mpuEntryArrayZ71[1].sRight = CMPU_W;
			(void)SAF_CMPU_LLD_SetEntry(&(mpuEntryArrayZ71[1]));
			/* Set entry 2 permission to read only */
			mpuEntryArrayZ71[2].sRight = CMPU_R;
			(void)SAF_CMPU_LLD_SetEntry(&(mpuEntryArrayZ71[2]));
#endif
    	}
    	else if (2 == GetCoreID())
    	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE2
			mpuEntryArrayZ42[1].sRight = CMPU_W;
			(void)SAF_CMPU_LLD_SetEntry(&(mpuEntryArrayZ42[1]));
			/* Set entry 2 permission to read only */
			mpuEntryArrayZ42[2].sRight = CMPU_R;
			(void)SAF_CMPU_LLD_SetEntry(&(mpuEntryArrayZ42[2]));
#endif
    	}
    	else
    	{
    		//Reserve
    	}
        /* Set test flag */
        mpuTestResult = CMPU_OP_FAIL;
    }
    else
    {
        /* Nothing */
    }
}
/**
****************************************************************************************
* @brief:  This function shall be used to get MPU access right test result.
* @param[out]   pTestResult   MPU access right test result.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get result succeed
*               FS_STATUS_ERROR       get result failed
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
FS_STATUS SAF_MPU_AccessRightTestResult(saf_mpu_access_right_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (pTestResult != NULL)
    {
        memcpy(pTestResult, &s_mpuAccessRightTest.output, sizeof(s_mpuAccessRightTest.output));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to execute MPU access right test.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     MPU access right test succeed
*               FS_STATUS_ERROR       MPU access right test failed
****************************************************************************************
*/
SAF_CMPU_SEC_CODE
FS_STATUS SAF_MPU_AccessRightTest(void)
{
    FS_STATUS status = FS_STATUS_ERROR;
    const saf_mpu_access_right_test_param_t *pParam  = &s_mpuAcRightTestCfg;
    saf_mpu_access_right_test_result_t *pResult = &s_mpuAccessRightTest.output;
    uint32_t testMpuAddr = CMPU_DEMO_PROTECT_SRAM;
    const uint32_t mpuInst = 0U;

    mpuTestFlag = 1U;

    /* Init CMPU config  */
	if(0 == GetCoreID())
	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE0
		status = SAF_MPU_SafetyInit(mpuInst, &mpu_CfgZ70, mpuEntryArrayZ70, CMPU_DEMO_ENTRY_COUNT);
#endif
	}
	else if (1 == GetCoreID())
	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE1
		status = SAF_MPU_SafetyInit(mpuInst, &mpu_CfgZ71, mpuEntryArrayZ71, CMPU_DEMO_ENTRY_COUNT);
#endif
	}
	else if (2 == GetCoreID())
	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE2
		status = SAF_MPU_SafetyInit(mpuInst, &mpu_CfgZ42, mpuEntryArrayZ42, CMPU_DEMO_ENTRY_COUNT);
#endif
	}
	else
	{
		//Reserve
	}

    if(FS_STATUS_SUCCESS == status)
    {
        /* Note:  Both Read and Write allowed */
        /* Write (Except: write ok) */
        status = SAF_MPU_WriteTest(testMpuAddr, CMPU_OP_SUCC);
        if(FS_STATUS_SUCCESS == status)
        {
            /* Read (Except: read ok) */
            status = SAF_MPU_ReadTest(testMpuAddr, CMPU_OP_SUCC);
            if (status != FS_STATUS_SUCCESS)
            {
                return status;
            }
        }
        else
        {
            return status;
        }

        if (pParam->readLimitSelect)
        {
            pResult->readLimitPassed = (bool)false;

            /* Set entry 2 permission from read to none */
        	if(0 == GetCoreID())
        	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE0
        		mpuEntryArrayZ70[2].sRight = CMPU_NONE;
                status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ70[2]));
#endif
        	}
        	else if (1 == GetCoreID())
        	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE1
        		mpuEntryArrayZ71[2].sRight = CMPU_NONE;
                status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ71[2]));
#endif
        	}
        	else if (2 == GetCoreID())
        	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE2
        		mpuEntryArrayZ42[2].sRight = CMPU_NONE;
                status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ42[2]));
#endif
        	}
        	else
        	{
        		//Reserve
        	}

            if(FS_STATUS_SUCCESS == status)
            {
                /* Write (Except: write ok) */
                status = SAF_MPU_WriteTest(testMpuAddr, CMPU_OP_SUCC);
                if(FS_STATUS_SUCCESS == status)
                {
                    /* Read (Except: read fail, trigger mpu error) */
                    status = SAF_MPU_ReadTest(testMpuAddr, CMPU_OP_FAIL);
                    if(FS_STATUS_SUCCESS == status)
                    {
                        pResult->readLimitPassed = (bool)true;
                    }
                }
            }
        }

        /* Set entry 2 permission from none to read */
    	if(0 == GetCoreID())
    	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE0
    		mpuEntryArrayZ70[2].sRight = CMPU_R;
            status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ70[2]));
#endif
    	}
    	else if (1 == GetCoreID())
    	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE1
    		mpuEntryArrayZ71[2].sRight = CMPU_R;
            status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ71[2]));
#endif
    	}
    	else if (2 == GetCoreID())
    	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE2
    		mpuEntryArrayZ42[2].sRight = CMPU_R;
            status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ42[2]));
#endif
    	}
    	else
    	{
    		//Reserve
    	}

        if (status != FS_STATUS_SUCCESS)
        {
            status = FS_STATUS_TEST_FAILED;
            return status;
        }

        if (pParam->writeLimitSelect)
        {
           pResult->writeLimitPassed = (bool)false;

           /* Note:  Only Read allowed */
           /* Set entry 1 permission from write to none */
			if(0 == GetCoreID())
			{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE0
				mpuEntryArrayZ70[1].sRight = CMPU_NONE;
				   status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ70[1]));
#endif
			}
			else if (1 == GetCoreID())
			{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE1
				mpuEntryArrayZ71[1].sRight = CMPU_NONE;
				   status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ71[1]));
#endif
			}
			else if (2 == GetCoreID())
			{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE2
				mpuEntryArrayZ42[1].sRight = CMPU_NONE;
				   status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ42[1]));
#endif
			}
			else
			{
				//Reserve
			}

           if(FS_STATUS_SUCCESS == status)
           {
               /* Read (Except: read ok) */
               status = SAF_MPU_ReadTest(testMpuAddr, CMPU_OP_SUCC);
               if(FS_STATUS_SUCCESS == status)
               {
                   /* Write (Except: write fail, trigger mpu error) */
                   status = SAF_MPU_WriteTest(testMpuAddr, CMPU_OP_FAIL);
                   if(FS_STATUS_SUCCESS == status)
                   {
                       pResult->writeLimitPassed = (bool)true;
                   }
               }
           }
        }

       /* Set entry 1 permission from none to write */
    	if(0 == GetCoreID())
    	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE0
    		mpuEntryArrayZ70[1].sRight = CMPU_W;
            status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ70[1]));
#endif
    	}
    	else if (1 == GetCoreID())
    	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE1
    		mpuEntryArrayZ71[1].sRight = CMPU_W;
            status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ71[1]));
#endif
    	}
    	else if (2 == GetCoreID())
    	{
#ifdef SAFETY_RESOURCE_DEF_CMPU_CORE2
    		mpuEntryArrayZ42[1].sRight = CMPU_W;
            status = SAF_MPU_SafetySetEntryConfig(mpuInst, &(mpuEntryArrayZ42[1]));
#endif
    	}
    	else
    	{
    		//Reserve
    	}

       if (status != FS_STATUS_SUCCESS)
       {
           status = FS_STATUS_TEST_FAILED;
           return status;
       }
    }

    if (FS_STATUS_SUCCESS != SAF_MPU_SafetyDeinit((uint8_t)mpuInst))
    {
    	status = FS_STATUS_TEST_FAILED;
    	return status;
    }

    mpuTestFlag = 0U;

    return status;
}

#endif

#ifdef __cplusplus
}
#endif
/*******************************************************************************
 * EOF
 ******************************************************************************/
