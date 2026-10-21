/**
****************************************************************************************
 * @FilePath: saf_regprot.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Safety Regprot C Source File
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
#include "saf_common.h"
#include "saf_cpu.h"/*PRQA S 0380*/
#include "saf_regprot.h"
#include "SafetyRegprotTst_Cfg.h"
#include "Saf_MemMap.h"
/*PRQA S 0491,1431,1861,1863,2844,4424,4434,4534,4542,4543 EOF*/
/*******************************************************************************
 * Variables
 ******************************************************************************/
SAF_REGPROT_SEC_VAR_NO_INIT
static saf_regprot_test_result_t s_regprotTest[SAF_RP_INSTANCE_COUNT];

static void SAF_REGPROT_AccessSetLock(RP * rp, uint16_t offset, uint16_t setlockvalue, uint8_t enable);

static FS_STATUS SAF_REGPROT_AccessCheckLockResult(uint8_t instanceIndex, uint16_t regIndex);

/**
****************************************************************************************
* @brief:  This function is used to execute regprot test.
* @param[in]    instanceIndex	Regprot index
* @return       FS_STATUS		Regprot result
****************************************************************************************
*/
SAF_REGPROT_SEC_VAR_INIT
uint8_t RegLockValue = 0xFF;/*PRQA S 3408*/
SAF_REGPROT_SEC_VAR_INIT
uint8_t RegUnlockvalue = 0xFF;/*PRQA S 3408,1514*/

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/

/**
****************************************************************************************
* @brief:  This function is used to set register lock.
* @param[in]    rp			regprot address
* @param[in]    offset		regprot address offset
* @param[in]    rp			regprot lock value
* @param[in]    rp			regprot enable or disable
* @return       void
****************************************************************************************
*/
SAF_REGPROT_SEC_CODE
static void SAF_REGPROT_AccessSetLock(RP * rp, uint16_t offset, uint16_t setlockvalue, uint8_t enable)
{
	offset >>= 2;
	rp->SLBR[offset] = (enable) ? setlockvalue : (setlockvalue ^ 0x0F); /*PRQA S 4559,1854*/  /* polyspace RTE:IDP */
}


/**
****************************************************************************************
* @brief[SW_SM92]  This function is used to check register lock is success
* @param[in]    instanceIndex:    Regprot instance index
* @param[in]    regIndex:        Regprot register index
* @return       FS_STATUS
                    FS_STATUS_SUCCESS: register lock success
                    FS_STATUS_ERROR:   register lock error
****************************************************************************************
*/
SAF_REGPROT_SEC_CODE
static FS_STATUS SAF_REGPROT_AccessCheckLockResult(uint8_t instanceIndex, uint16_t regIndex)
{
	uint8_t getlockresult = 0;
    uint32_t addr;
    uint16_t offset;
    FS_STATUS status = FS_STATUS_SUCCESS;

	addr = RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Base; /* polyspace RTE:IDP */
	offset = RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Offset;

	getlockresult = SAF_RP_GetLock((RP *)addr, offset);/*PRQA S 4443*/

    if(REGPROT_MODE_8BIT == RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Mode)
    {
        getlockresult &= 0x0FU >> (offset & REGPROT_SLBR_OFFSET_8BIT_MASK);
    }
    else if(REGPROT_MODE_16BIT == RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Mode)
    {
        getlockresult &= 0x0FU >> (offset & REGPROT_SLBR_OFFSET_16BIT_MASK);
    }
    else if(REGPROT_MODE_32BIT == RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Mode)
    {
        getlockresult &= 0x0FU;
    }
    else
    {
        /* do nothing for satisfy the misra 2012*/
    }

	if(getlockresult != (RegLockValue & 0x0F))/*PRQA S 1853*/
	{
		s_regprotTest[instanceIndex].RegProtResult = SAF_STATUS_REGPROT_LOCK_ERROR;
		status = FS_STATUS_ERROR;
	}
	return status;
}

/**
*******************************************************************************
 * Global Functions
 ******************************************************************************
*/

/**
****************************************************************************************
* @brief[SW_SM92]  This function is used to execute regprot test.
* @param[in]    instanceIndex:    Regprot instance index
* @return       FS_STATUS
                    FS_STATUS_SUCCESS: register lock test success
                    FS_STATUS_ERROR:   register lock test error
****************************************************************************************
*/
SAF_REGPROT_SEC_CODE
FS_STATUS SAF_RegProt_RegprotTest(SAF_REG_PROT_INSTANCE instanceIndex)
{
	uint16_t regIndex;
	FS_STATUS status = FS_STATUS_ERROR;

	(void)s_regprotTest;/*PRQA S 3119*/
	if(instanceIndex < SAF_RP_INSTANCE_COUNT)/*PRQA S 1880*/
	{
		s_regprotTest[instanceIndex].RegProtResult = SAF_STATUS_REGPROT_LOCK_SUCCESS;
		status = FS_STATUS_SUCCESS;
		for(regIndex = 0; regIndex < RP_REG_LIST[instanceIndex].Size; regIndex++)
		{
			SAF_RegProt_LockReg(instanceIndex, regIndex);
			if(FS_STATUS_SUCCESS != SAF_REGPROT_AccessCheckLockResult(instanceIndex, regIndex))/*PRQA S 2991,2995*/
			{
				s_regprotTest[instanceIndex].RegProtResult = SAF_STATUS_REGPROT_LOCK_ERROR;
				status = FS_STATUS_ERROR;
			}
		}
	}
	return status;
}

/**
****************************************************************************************
* @brief:  This function is used to lock regprot.
* @param[in]    instanceIndex	Regprot instance index
* @param[in]    regIndex		Regprot index
* @return       void
****************************************************************************************
*/
SAF_REGPROT_SEC_CODE
void SAF_RegProt_LockReg(uint8_t instanceIndex, uint16_t regIndex)
{
    uint32_t addr = 0U;
    uint16_t offset = 0U;

    addr = RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Base;/* polyspace RTE:IDP */
    offset = RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Offset;
    if(REGPROT_MODE_8BIT == RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Mode)
    {
        RegLockValue = REGPROT_SLBR_LOCK_8BIT_VALUE >> (offset & REGPROT_SLBR_OFFSET_8BIT_MASK);
    }
    else if(REGPROT_MODE_16BIT == RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Mode)
    {
        RegLockValue = REGPROT_SLBR_LOCK_16BIT_VALUE >> (offset & REGPROT_SLBR_OFFSET_16BIT_MASK);
    }
    else if(REGPROT_MODE_32BIT == RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Mode)
    {
        RegLockValue = REGPROT_SLBR_LOCK_32BIT_VALUE;
    }
    else
    {
        /* do nothing for satisfy the misra 2012*/
    }
	SAF_REGPROT_AccessSetLock((RP *)addr, offset, RegLockValue, REGPROT_LOCK_ENABLE);
}

/**
****************************************************************************************
* @brief:  This function is used to lock regprot.
* @param[in]    instanceIndex	Regprot instance index
* @param[in]    regIndex		Regprot index
* @return       void
****************************************************************************************
*/
SAF_REGPROT_SEC_CODE
void SAF_RegProt_UnlockReg(uint8_t instanceIndex, uint16_t regIndex)
{
    uint32_t addr;
    uint16_t offset;

	addr = RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Base; /* polyspace RTE:IDP,OBAI */
	offset = RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Offset;
	if(RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Mode == REGPROT_MODE_8BIT)
	{
		RegUnlockvalue = 0x88 >> (offset & 0x3);
	}
	else if(RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Mode == REGPROT_MODE_16BIT)
	{
		RegUnlockvalue = 0xCC >> (offset & 0x2);
	}
	else if(RP_REG_LIST[instanceIndex].RP_Test_Info[regIndex].Mode == REGPROT_MODE_32BIT)
	{
		RegUnlockvalue = 0xFF;
	}
	else
	{
		/* do nothing for satisfy the misra 2012*/
	}
	SAF_REGPROT_AccessSetLock((RP *)addr, offset, RegUnlockvalue, REGPROT_LOCK_DISABLE);
}

/**
****************************************************************************************
* @brief:  This function is used to get register lock.
* @param[in]    rp			regprot address
* @param[in]    offset		regprot address offsetgetlockresult
* @return       uint8_t		regprot lock value
****************************************************************************************
*/
SAF_REGPROT_SEC_CODE
uint8_t SAF_RP_GetLock(RP * rp, int offset)
{
	uint8_t result;
	result = (rp->SLBR[(uint16_t)offset >> 2U]); /* polyspace RTE:NIV,IDP */
	return result;
}



/*******************************************************************************
 * EOF
 ******************************************************************************/
