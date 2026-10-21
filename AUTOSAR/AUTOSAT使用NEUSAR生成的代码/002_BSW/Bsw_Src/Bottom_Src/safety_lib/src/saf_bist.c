/**
****************************************************************************************
 * @FilePath: saf_bist.c
 * @Author: CCORE
 * @Date: 2024-03-10
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: BIST Source File
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
#include "saf_cpu.h"/*PRQA S 0380*/
#include "saf_bist.h"
#include "saf_flash.h"
#include "Saf_MemMap.h"
/*PRQA S 0380,0779,0704 EOF*/
/*PRQA S 1281,1259,1514,1840,1843 EOF*/
/*PRQA S 2214,2844,2911,2983,2985,2986,2994,2996 EOF*/
/*PRQA S 3119,3408,3218,3200,3344,3604 EOF*/
/*PRQA S 4304,4332,4404,4423,4532,4542 EOF*/
/**
****************************************************************************************
 * @brief: Local Macros
****************************************************************************************
*/
#define SAF_BIST_DCF_BIST_CFG_BASE_ADDR                     (0x00080008U)
#define SAF_BIST_DCF_START_ADDR_DATA                        (0x05AA55AFU)

/**
****************************************************************************************
 * @brief: Local Function Prototypes
****************************************************************************************
*/
static uint32_t SAF_BIST_AccessReadOfflineLbistStatus(void);
static uint32_t SAF_BIST_AccessReadOfflineLbistEndFlag(void);
static uint32_t SAF_BIST_AccessReadOfflineMbistStatus(void);
static uint32_t SAF_BIST_AccessReadOfflineMbistEndFlag(void);
static void SAF_BIST_OfflineBistDcfCfgDetect(saf_bist_offline_config_t *pBistDcf, saf_dcf_record_t *pRecord);
static FS_STATUS SAF_BIST_OfflineLbistStatusCheck(saf_bist_offline_config_t *pBistDcf, saf_bist_check_result_t *pBistCheckResult);
static FS_STATUS SAF_BIST_OfflineLbistEndFlagCheck(saf_bist_offline_config_t *pBistDcf, saf_bist_check_result_t *pBistCheckResult);
static FS_STATUS SAF_BIST_OfflineMbistStatusCheck(saf_bist_offline_config_t *pBistDcf, saf_bist_check_result_t *pBistCheckResult);
static FS_STATUS SAF_BIST_OfflineMbistEndFlagCheck(saf_bist_offline_config_t *pBistDcf, saf_bist_check_result_t *pBistCheckResult);
static uint32_t SAF_BIST_UpdateDcfStartAddr(const uint32_t dcfAddr);
static FS_STATUS SAF_BIST_DCFFlashDoubleWordWrite(uint32_t flashAddr, uint64_t writeData);

#ifdef SAF_BIST_ONLINE_BIST_SUPPORTED
static void IST_WAIT(unsigned int cnt);
static void IST_WRITE(unsigned int wdata);
static int IST_READ_XCMP(unsigned int cmpdata, unsigned mask);
static int IST_READ_BINCMP(unsigned int cmpdata);
static int SAF_MBist_Partiton1(void);
static int SAF_MBist_Partiton2(void);
static int SAF_MBist_Partiton5(void);
static int SAF_MBist_Partiton7(void);
static int SAF_MBist_Partiton8(void);
static int SAF_MBist_Partiton9(void);
static int SAF_LBist_Partiton0(void);
static int SAF_LBist_Partiton6(void);
static int SAF_LBist_Partiton9(void);
#endif

/**
****************************************************************************************
 * @brief: Lib Function Prototypes
****************************************************************************************
*/
extern void FlashDoubleWordWrite(uint32_t flashAddr, uint64_t writeData);

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/
SAF_BIST_SEC_VAR_INIT
saf_bist_offline_config_t s_offlineBistConfig =
{
    .startAddr = SAF_DCF_START_ADDR,
    .lbistCfg = 0UL,
    .mbistCfg = 0UL,
};

SAF_BIST_SEC_VAR_INIT
uint64_t DcfRecords[] = SAF_DCF_RECORD_LIST;

/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/

#ifdef SAF_BIST_ONLINE_BIST_SUPPORTED
SAF_BIST_SEC_VAR_INIT
static saf_bist_online_config_t s_onlineBistConfig =
{
	.lbistCount = 0,
	.mbistCount = 0,
};

SAF_BIST_SEC_CONFIG_DATA
static const bist_test_callback_t s_mbistTest[] = {
		{"NULL",    NULL},
        {"SAF_MBist_Partiton1",    &SAF_MBist_Partiton1},
        {"SAF_MBist_Partiton2",    &SAF_MBist_Partiton2},
		{"NULL",    NULL},
		{"NULL",    NULL},
        {"SAF_MBist_Partiton5",    &SAF_MBist_Partiton5},
		{"NULL",    NULL},
        {"SAF_MBist_Partiton7",    &SAF_MBist_Partiton7},
        {"SAF_MBist_Partiton8",    &SAF_MBist_Partiton8},
		{"SAF_MBist_Partiton9",    &SAF_MBist_Partiton9}
};

SAF_BIST_SEC_CONFIG_DATA
static const bist_test_callback_t s_lbistTest[] = {
		{"SAF_LBist_Partiton0",    &SAF_LBist_Partiton0},
		{"NULL",    NULL},
		{"NULL",    NULL},
		{"NULL",    NULL},
		{"NULL",    NULL},
		{"NULL",    NULL},
        {"SAF_LBist_Partiton6",    &SAF_LBist_Partiton6},
		{"NULL",    NULL},
		{"NULL",    NULL},
        {"SAF_LBist_Partiton9",    &SAF_LBist_Partiton9}
};
#endif /* SAF_BIST_ONLINE_BIST_SUPPORTED */
/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [] This function reads and returns the status of off-Line logic BIST.
* @param[in] void
* @return status
                0:Off-Line Successful LBIST execution
                1:Off-Line Failed LBIST execution
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static uint32_t SAF_BIST_AccessReadOfflineLbistStatus(void)
{
    uint32_t ret = 0U;

    ret = SAF_STCU2_BIST_STS.B.LB_F;

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function reads and returns the end flag of off-Line logic BIST.
* @param[in] void
* @return status
                0:Off-Line LBIST execution not yet completed
                1:Off-Line LBIST execution finished
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static uint32_t SAF_BIST_AccessReadOfflineLbistEndFlag(void)
{
    uint32_t ret = 0U;

    ret = SAF_STCU2_BIST_STS.B.LB_D;

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function reads and returns the status of off-Line memory BIST.
* @param[in] void
* @return status
                0:Off-Line Successful MBIST execution
                1:Off-Line Failed MBIST execution
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static uint32_t SAF_BIST_AccessReadOfflineMbistStatus(void)
{
    uint32_t ret = 0U;

    ret = SAF_STCU2_BIST_STS.B.MB_F;

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function reads and returns the end flag of off-Line memory BIST.
* @param[in] void
* @return status
                0:Off-Line MBIST execution not yet completed
                1:Off-Line MBIST execution finished
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static uint32_t SAF_BIST_AccessReadOfflineMbistEndFlag(void)
{
    uint32_t ret = 0U;

    ret = SAF_STCU2_BIST_STS.B.MB_D;

    return ret;
}

/**
****************************************************************************************
* @brief: []  This function detects the DCF configurations of the off-Line.
* @param[in] pBistDcf the offline BIST configuration.
* @param[in] pRecord Pointer of DCF record
* @return void
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static void SAF_BIST_OfflineBistDcfCfgDetect(saf_bist_offline_config_t *pBistDcf, saf_dcf_record_t *pRecord)
{    
    if (SAF_BIST_DCF_BIST_CFG_BASE_ADDR == pRecord->addr.R)/* polyspace RTE:NIV */
    {
        if (((pRecord->data >> SAF_OFFLINE_MBIST_CFG_SHIFT) & SAF_DCF_HALF_WORD_MASK) == SAF_OFFLINE_MBIST_CHECK_INDEX_LIMIT)/* polyspace RTE:NIV */
        {
            pBistDcf->mbistCfg = SAF_OFFLINE_MBIST_NEED_CHECK;
        }

        if ((pRecord->data & SAF_DCF_HALF_WORD_MASK) <= SAF_OFFLINE_LBIST_CHECK_INDEX_LIMIT)
        {
            pBistDcf->lbistCfg = SAF_OFFLINE_LBIST_NEED_CHECK;
            if((SAF_OFFLINE_MBIST_NEED_CHECK == pBistDcf->mbistCfg) && ((pRecord->data & SAF_DCF_HALF_WORD_MASK) != SAF_OFFLINE_LBIST_CHECK_INDEX_LIMIT))
            {
                pBistDcf->lbistCfg = SAF_OFFLINE_LBIST_NOT_NEED_CHECK;
            }
        }
    }
}

/**
****************************************************************************************
* @brief: [] This function will check off line logic BIST check status.
* @param[in] pBistDcf the offline BIST configuration.
* @param[out] pBistCheckResult Pointer of Offline BIST check result.
* @return status
            FS_STATUS_SUCCESS: Get results successfully.
            FS_STATUS_ERROR: Failed to get results.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static FS_STATUS SAF_BIST_OfflineLbistStatusCheck(saf_bist_offline_config_t *pBistDcf, 
                                                 saf_bist_check_result_t *pBistCheckResult)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    pBistCheckResult->offLineLbistCheckResult = SAF_BIST_AccessReadOfflineLbistStatus();
    if (pBistCheckResult->offLineLbistCheckResult != 0U)
    {
        status = FS_STATUS_ERROR;
    }

    (void)pBistDcf;

    return status;
}

/**
****************************************************************************************
* @brief: [] This function will check off line LBIST execution whether is complete .
* @param[in] pBistDcf the offline BIST configuration.
* @param[out] pBistCheckResult Pointer of Offline BIST check result.
* @return status
            FS_STATUS_SUCCESS: Get results successfully.
            FS_STATUS_ERROR: Failed to get results.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static FS_STATUS SAF_BIST_OfflineLbistEndFlagCheck(saf_bist_offline_config_t *pBistDcf, 
                                                  saf_bist_check_result_t *pBistCheckResult)
{
    FS_STATUS status = FS_STATUS_SUCCESS;

    pBistCheckResult->offLineLbistCheckEnd = SAF_BIST_AccessReadOfflineLbistEndFlag();
    if (pBistCheckResult->offLineLbistCheckEnd != pBistDcf->lbistCfg)
    {
        status = FS_STATUS_ERROR;
    }
    return status;
}

/**
****************************************************************************************
* @brief: [] This function will check off line MBIST check status.
* @param[in] pBistDcf the offline BIST configuration.
* @param[out] pBistCheckResult Pointer of Offline BIST check result.
* @return status
            FS_STATUS_SUCCESS: Get results successfully.
            FS_STATUS_ERROR: Failed to get results.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static FS_STATUS SAF_BIST_OfflineMbistStatusCheck(saf_bist_offline_config_t *pBistDcf,
                                                 saf_bist_check_result_t *pBistCheckResult)
{   
    FS_STATUS status = FS_STATUS_SUCCESS;

    pBistCheckResult->offLineMbistCheckResult = SAF_BIST_AccessReadOfflineMbistStatus();
    if (pBistCheckResult->offLineMbistCheckResult != 0U)
    {
        status = FS_STATUS_ERROR;
    }

    (void)pBistDcf;

    return status;
}

/**
****************************************************************************************
* @brief: [] This function will check off line MBIST execution whether is complete.
* @param[in] pBistDcf the offline BIST configuration.
* @param[out] pBistCheckResult Pointer of Offline BIST check result.
* @return status
            FS_STATUS_SUCCESS: Get results successfully.
            FS_STATUS_ERROR: Failed to get results.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static FS_STATUS SAF_BIST_OfflineMbistEndFlagCheck(saf_bist_offline_config_t *pBistDcf, 
                                                  saf_bist_check_result_t *pBistCheckResult)
{  
    FS_STATUS status = FS_STATUS_SUCCESS;

    pBistCheckResult->offLineMbistCheckEnd = SAF_BIST_AccessReadOfflineMbistEndFlag();
    if (pBistCheckResult->offLineMbistCheckEnd != pBistDcf->mbistCfg)
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief: [] This function is used to update the DCF start address.
* @param[in] dcfAddr Dcf address
* @return uint32_t 
              DCF start address.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static uint32_t SAF_BIST_UpdateDcfStartAddr(const uint32_t dcfAddr)
{    
    uint32_t lastDcfAddr = dcfAddr; 
    saf_dcf_record_t *pRecord = (saf_dcf_record_t *)lastDcfAddr;
    bool isLastRec = (bool)false;
    
    while (!isLastRec)/*PRQA S 4558,4116*/
    {
        if (pRecord->addr.B.stop & 0x1)/*PRQA S 4542,3344,3341,2985,1861*/ /* polyspace RTE:NIV,IDP */
        {
            isLastRec = (bool)true;
            continue;
        }
        
        if (SAF_BIST_DCF_START_ADDR_DATA == pRecord->data)/* polyspace RTE:NIV */
        {
            lastDcfAddr = (uint32_t)pRecord;
        }
        pRecord++;/*PRQA S 0498*/
    }

    return lastDcfAddr;
}

/**
****************************************************************************************
* @brief: [] This function is used to write data to UTEST flash.
* @param[in] flashAddr flash address
* @param[in] writeData The data being written
* @return void
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static FS_STATUS SAF_BIST_DCFFlashDoubleWordWrite(uint32_t flashAddr, uint64_t writeData)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    fls_ctx_data_t pLLDCtxData = { 0U };
    status_t sdkStatus = STATUS_SUCCESS;
    uint8_t opResult = 0;
    uint32_t dcfdata[2] = { 0U };
    uint32_t hdata = (uint32_t)(writeData >> SAF_DCF_RECORD_DATA_FIELD_SHIFT);
    uint32_t ldata = (uint32_t)(writeData & SAF_DCF_WORD_MASK);
    dcfdata[0] = hdata;
    dcfdata[1] = ldata;

    /* 1. Flash unlock block. */
    status = SAF_FLASH_LockBlockByAddr(flashAddr, false);
    if (FS_STATUS_SUCCESS == status)
    {
        do
        {
            /* Call FLASH_LLD_Program to start program. */
            pLLDCtxData.dest = flashAddr;
            pLLDCtxData.src = (uint32_t)(&dcfdata[0]);
            pLLDCtxData.size = (uint32_t)sizeof(dcfdata);
            pLLDCtxData.mode = SAF_FLS_OP_ASYNC;

            sdkStatus = SAF_FLASH_LLD_Program(&pLLDCtxData);

            if (STATUS_SUCCESS != sdkStatus)
            {
                status = FS_STATUS_ERROR;
                break;
            }

            /* Call FLASH_LLD_CheckProgramStatus to confirm program successful or not. */
            do
            {
                sdkStatus = SAF_FLASH_LLD_CheckProgramStatus(&pLLDCtxData, &opResult);
            }while(STATUS_FLASH_INPROGRESS == sdkStatus);

            if ((STATUS_SUCCESS != sdkStatus) || (SAF_FLS_OK != opResult))
            {
                status = FS_STATUS_ERROR;
                break;
            }

        } while(0);
        (void)SAF_FLASH_LockBlockByAddr(flashAddr, true);
    }

    return status;
}

/**
****************************************************************************************
* @brief: [] This function is used to compare the original value of a register with the
*            written value.
* @param[in] regaddr: Address of STCU2 register.
* @param[in] regmask: Mask of STCU2 register.
* @return ret
            SAF_BIST_RET_SUCCESS: The value of the register is not overwritten.
            SAF_BIST_RET_ERROR: The value of the register is overwritten.
****************************************************************************************
*/
static uint16_t SAF_BIST_RegValueCmp(volatile uint32_t* regaddr, uint32_t regmask)
{
    uint16_t ret = SAF_BIST_RET_SUCCESS;
    uint32_t bRegValue = 0U;
    uint32_t invertValue = 0U;
    uint32_t aRegValue = 0U;

    bRegValue = *regaddr;
    invertValue = (~bRegValue)&regmask;
    *regaddr = invertValue;
    aRegValue = *regaddr;

    if (aRegValue != bRegValue)
    {
        ret = SAF_BIST_RET_ERROR;
    }

    return ret;
}

#ifdef SAF_BIST_ONLINE_BIST_SUPPORTED
/**
****************************************************************************************
* @brief: [] This function is used to delay.
* @param[in] cnt delay count
* @return void
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static void IST_WAIT(unsigned int cnt)
{
	cnt = cnt * 2;
	while(cnt--);/*PRQA S 3344*/
}

/**
****************************************************************************************
* @brief: [] This function is used to write data to the specified address.
* @param[in] wdata Data that needs to be written
* @return void
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static void IST_WRITE(unsigned int wdata)
{
	*(volatile unsigned int*)(0xfff46800) = wdata;
}

/**
****************************************************************************************
* @brief: [] This function is used to compare the data with the data at the specified 
             address.
* @param[in] cmpdata data for comparison
* @param[in] mask data mask
* @return status:
              FS_STATUS_SUCCESS Data comparison success
              FS_STATUS_ERROR Data comparison failure
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int IST_READ_XCMP(unsigned int cmpdata, unsigned mask)
{
	int ret = FS_STATUS_SUCCESS;
	unsigned int rata32 = *(volatile unsigned int*)(0xfff46800);
	if((rata32 & mask) != cmpdata)
	{
		ret = FS_STATUS_ERROR;
	}
	return ret;
}

/**
****************************************************************************************
* @brief: [] This function is used to compare the data with the data at the specified 
             address.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Data comparison success
              FS_STATUS_ERROR Data comparison failure
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int IST_READ_BINCMP(unsigned int cmpdata)
{
	int ret = FS_STATUS_SUCCESS;
	unsigned int rata32 = *(volatile unsigned int*)(0xfff46800);
	if(rata32 != cmpdata)
	{
		ret = FS_STATUS_ERROR;
	}
	return ret;
}

/**
****************************************************************************************
* @brief: []  This function will check Online MBist Partion1.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Mbist1 check is successful
              FS_STATUS_ERROR Mbist1 check failed
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int SAF_MBist_Partiton1(void)
{
	int ret = FS_STATUS_SUCCESS;

	*(volatile unsigned int*)(0xfff44004) = 0xD3FEA98B;
	*(volatile unsigned int*)(0xfff44004) = 0x2C015674;

	*(volatile unsigned int*)(0xfff44000) = 0x10000000;
	*(volatile unsigned int*)(0xfff44018) = 0x0;
	*(volatile unsigned int*)(0xfff44008) = 0x0;
	*(volatile unsigned int*)(0xfff44010) = 0xFFFF;
	*(volatile unsigned int*)(0xfff4400C) = 0x0;

	*(volatile unsigned int*)(0xfff44004) = 0x753F924E;
	*(volatile unsigned int*)(0xfff44004) = 0x8AC06DB1;

	IST_WRITE(0xc0000000);  //Setup-Ijtag
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0x0);  //ToPauseIR
	ret |= IST_READ_BINCMP(0x1);
	IST_WRITE(0x9c000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa0000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80108000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa00c2000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x70c20000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000400);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200861);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x800c0000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200821);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x801c0000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x801f4200);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3ffff3ff);
	IST_WRITE(0x7c200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x87ff);
	IST_WRITE(0x80012043);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40208400);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000002);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x70000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3c3fffff);
	IST_WRITE(0x80002057);  //ToRTI
	ret |= IST_READ_XCMP(0x48, 0x3ffffbff);
	IST_WRITE(0x4001d080);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x7ff);
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x4001fe00);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x20000000);
	IST_WRITE(0x80042050);  //ToRTI
	ret |= IST_READ_BINCMP(0x40);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x840000, 0x3ddfffff);
	IST_WRITE(0x800c207d);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WRITE(0x74200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x18400000, 0x3dffffff);
	IST_WRITE(0x800d2017);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WAIT(8211);
	IST_WRITE(0x8001f420);  //ToRTI
	ret |= IST_READ_XCMP(0x6000, 0x3fffe7ff);
	IST_WAIT(556184);
	IST_WRITE(0x8010f420);  //ToRTI
	ret |= IST_READ_XCMP(0x1800, 0x3fff9fff);
	IST_WRITE(0x74200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x1a400000, 0x1fff87ff);
	IST_WRITE(0x80052043);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x74200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x8400000, 0x1dff87ff);
	IST_WRITE(0x80042013);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x68400000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x344c0000, 0x3fff07ff);
	IST_WRITE(0x40000007);  //ToPauseDR
	ret |= IST_READ_XCMP(0x22817, 0x3ffff);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x4000000, 0x37800000);
	IST_WRITE(0x80040000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WAIT(4);
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0xc0000010);  //Setup-Done

	return ret;
}

/**
****************************************************************************************
* @brief: []  This function will check Online MBist Partion2.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Mbist2 check is successful
              FS_STATUS_ERROR Mbist2 check failed
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int SAF_MBist_Partiton2(void)
{
	int ret = FS_STATUS_SUCCESS;
	*(volatile unsigned int*)(0xfff44004) = 0xD3FEA98B;
	*(volatile unsigned int*)(0xfff44004) = 0x2C015674;

	*(volatile unsigned int*)(0xfff44000) = 0x10000000;
	*(volatile unsigned int*)(0xfff44018) = 0x0;
	*(volatile unsigned int*)(0xfff44008) = 0x0;
	*(volatile unsigned int*)(0xfff44010) = 0xFFFF;
	*(volatile unsigned int*)(0xfff4400C) = 0x0;

	*(volatile unsigned int*)(0xfff44004) = 0x753F924E;
	*(volatile unsigned int*)(0xfff44004) = 0x8AC06DB1;

	IST_WRITE(0xc0000000);  //Setup-Ijtag
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0x0);  //ToPauseIR
	ret |= IST_READ_BINCMP(0x1);
	IST_WRITE(0x9c000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa0000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80208000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80182000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa030c100);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x70400000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40004010);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x70000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000500);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x50400000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40004010);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x70000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000401);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x803e8200);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3fffe7ff);
	IST_WRITE(0x60800000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x20004fff);
	IST_WRITE(0x8002409f);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40020082);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x480000, 0x3bfff3ff);
	IST_WRITE(0x800040be);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x43a08000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfff);
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x7f000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x20000000, 0x3fc00000);
	IST_WRITE(0x80084087);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x1080000, 0x3bbfffff);
	IST_WRITE(0x801840fa);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WRITE(0x60800000);  //ToPauseDR
	ret |= IST_READ_XCMP(0xc200000, 0x3effffff);
	IST_WRITE(0x801a403e);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WAIT(1115955);
	IST_WRITE(0x8023a080);  //ToRTI
	ret |= IST_READ_BINCMP(0x3000);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x3480000, 0x3bffffff);
	IST_WRITE(0x800a40ba);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(4);
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0xc0000010);  //Setup-Done
	return ret;
}

/**
****************************************************************************************
* @brief: []  This function will check Online MBist Partion5.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Mbist5 check is successful
              FS_STATUS_ERROR Mbist5 check failed
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int SAF_MBist_Partiton5(void)
{
	int ret = FS_STATUS_SUCCESS;
	*(volatile unsigned int*)(0xfff44004) = 0xD3FEA98B;
	*(volatile unsigned int*)(0xfff44004) = 0x2C015674;

	*(volatile unsigned int*)(0xfff44000) = 0x10000000;
	*(volatile unsigned int*)(0xfff44018) = 0x0;
	*(volatile unsigned int*)(0xfff44008) = 0x0;
	*(volatile unsigned int*)(0xfff44010) = 0xFFFF;
	*(volatile unsigned int*)(0xfff4400C) = 0x0;

	*(volatile unsigned int*)(0xfff44004) = 0x753F924E;
	*(volatile unsigned int*)(0xfff44004) = 0x8AC06DB1;

	IST_WRITE(0xc0000000);  //Setup-Ijtag
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0x0);  //ToPauseIR
	ret |= IST_READ_BINCMP(0x1);
	IST_WRITE(0x9c000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa0000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x81008000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa1c02000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x43008000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000405);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x43008000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000401);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x41008000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000401);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x81000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x81d00800);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x81f40200);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3fff3fff);
	IST_WRITE(0x70080000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x207fff);
	IST_WRITE(0x8012040f);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3fffffc0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40010041);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x24000000, 0x3ff81fff);
	IST_WRITE(0x8002055f);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3ffffff7);
	IST_WRITE(0x48000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x7fff);
	IST_WRITE(0x40000740);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x42000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40800000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x100000, 0x3fffe000);
	IST_WRITE(0x80420420);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x8400000, 0x1dffffff);
	IST_WRITE(0x80c207d0);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WRITE(0x50080000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x10000000);
	IST_WRITE(0x80d2015f);  //ToRTI
	ret |= IST_READ_XCMP(0x18, 0x3ffffffd);
	IST_WAIT(1);
	IST_WAIT(19587);
	IST_WRITE(0x8053d008);  //ToRTI
	ret |= IST_READ_XCMP(0x18000, 0x3fe1ffff);
	IST_WAIT(1);
	IST_WAIT(180520);
	IST_WRITE(0x8013d008);  //ToRTI
	ret |= IST_READ_XCMP(0x180000, 0x3ff87fff);
	IST_WAIT(1);
	IST_WAIT(502586);
	IST_WRITE(0x8101d008);  //ToRTI
	ret |= IST_READ_XCMP(0x60000, 0x3fe67fff);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x1a400000, 0x1fffffff);
	IST_WRITE(0x805205d0);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x8400000, 0x1dffffff);
	IST_WRITE(0x805205d0);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(4);
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0xc0000010);  //Setup-Done

	return ret;
}

/**
****************************************************************************************
* @brief: []  This function will check Online MBist Partion7.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Mbist7 check is successful
              FS_STATUS_ERROR Mbist7 check failed
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int SAF_MBist_Partiton7(void)
{
	int ret = FS_STATUS_SUCCESS;
	*(volatile unsigned int*)(0xfff44004) = 0xD3FEA98B;
	*(volatile unsigned int*)(0xfff44004) = 0x2C015674;

	*(volatile unsigned int*)(0xfff44000) = 0x10000000;
	*(volatile unsigned int*)(0xfff44018) = 0x0;
	*(volatile unsigned int*)(0xfff44008) = 0x0;
	*(volatile unsigned int*)(0xfff44010) = 0xFFFF;
	*(volatile unsigned int*)(0xfff4400C) = 0x0;

	*(volatile unsigned int*)(0xfff44004) = 0x753F924E;
	*(volatile unsigned int*)(0xfff44004) = 0x8AC06DB1;

	IST_WRITE(0xc0000000);  //Setup-Ijtag
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0x0);  //ToPauseIR
	ret |= IST_READ_BINCMP(0x1);
	IST_WRITE(0x9c000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa0000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa4008000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40400000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000418);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x86180100);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4004010c);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x83000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40040104);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x87000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x87d00200);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3ffcffff);
	IST_WRITE(0x40800000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x9ffff);
	IST_WRITE(0x804813f0);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3ffffff0);
	IST_WRITE(0x40104008);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000001);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x800817c0);  //ToRTI
	ret |= IST_READ_XCMP(0x90000, 0x3f7ffe7f);
	IST_WRITE(0x40740080);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x1ffff);
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x7fe00000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x810810ff);  //ToRTI
	ret |= IST_READ_XCMP(0x1000, 0x3fffffe0);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x21000000, 0x37ffffff);
	IST_WRITE(0x83081f40);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3ffffffd);
	IST_WAIT(1);
	IST_WRITE(0x40800000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x4000000, 0x1fffffff);
	IST_WRITE(0x834807d0);  //ToRTI
	ret |= IST_READ_BINCMP(0x6);
	IST_WAIT(1);
	IST_WAIT(142950);
	IST_WRITE(0x84740080);  //ToRTI
	ret |= IST_READ_BINCMP(0x60000);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x29000000);
	IST_WRITE(0x81481740);  //ToRTI
	ret |= IST_READ_XCMP(0x1, 0x3ffffffd);
	IST_WAIT(4);
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0xc0000010);  //Setup-Done

	return ret;
}

/**
****************************************************************************************
* @brief: []  This function will check Online MBist Partion8.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Mbist8 check is successful
              FS_STATUS_ERROR Mbist8 check failed
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int SAF_MBist_Partiton8(void)
{
	int ret = FS_STATUS_SUCCESS;
	*(volatile unsigned int*)(0xfff44004) = 0xD3FEA98B;
	*(volatile unsigned int*)(0xfff44004) = 0x2C015674;

	*(volatile unsigned int*)(0xfff44000) = 0x10000000;
	*(volatile unsigned int*)(0xfff44018) = 0x0;
	*(volatile unsigned int*)(0xfff44008) = 0x0;
	*(volatile unsigned int*)(0xfff44010) = 0xFFFF;
	*(volatile unsigned int*)(0xfff4400C) = 0x0;

	*(volatile unsigned int*)(0xfff44004) = 0x753F924E;
	*(volatile unsigned int*)(0xfff44004) = 0x8AC06DB1;

	IST_WRITE(0xc0000000);  //Setup-Ijtag
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0x0);  //ToPauseIR
	ret |= IST_READ_BINCMP(0x1);
	IST_WRITE(0x9c000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa0000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x88008000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa6002000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x60020000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000461);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x48000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x42008600);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x86000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x48000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x42008200);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x8e000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x8fa00200);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3ff9ffff);
	IST_WRITE(0x40800000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x13ffff);
	IST_WRITE(0x809027e0);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3fffffe0);
	IST_WRITE(0x48200200);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000080);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80102f80);  //ToRTI
	ret |= IST_READ_XCMP(0x4800, 0x3ffbfff3);
	IST_WRITE(0x44000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3ffff);
	IST_WRITE(0x40001d00);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x1000000, 0x3ffe0000);
	IST_WRITE(0x821021ff);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x2000000, 0x2fffffff);
	IST_WRITE(0x86103e80);  //ToRTI
	ret |= IST_READ_XCMP(0x1, 0x3ffffffb);
	IST_WAIT(1);
	IST_WRITE(0x40800000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x8000000);
	IST_WRITE(0x86900fa0);  //ToRTI
	ret |= IST_READ_XCMP(0xc, 0x3ffffffe);
	IST_WAIT(1);
	IST_WAIT(1473060);
	IST_WRITE(0x88e80080);  //ToRTI
	ret |= IST_READ_BINCMP(0xc0000);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x12000000);
	IST_WRITE(0x82902e80);  //ToRTI
	ret |= IST_READ_XCMP(0x3, 0x3ffffffb);
	IST_WAIT(4);
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0xc0000010);  //Setup-Done

	return ret;
}

/**
****************************************************************************************
* @brief: []  This function will check Online MBist Partion9.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Mbist9 check is successful
              FS_STATUS_ERROR Mbist9 check failed
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int SAF_MBist_Partiton9(void)
{
	int ret = FS_STATUS_SUCCESS;
	*(volatile unsigned int*)(0xfff44004) = 0xD3FEA98B;
	*(volatile unsigned int*)(0xfff44004) = 0x2C015674;

	*(volatile unsigned int*)(0xfff44000) = 0x10000000;
	*(volatile unsigned int*)(0xfff44018) = 0x0;
	*(volatile unsigned int*)(0xfff44008) = 0x0;
	*(volatile unsigned int*)(0xfff44010) = 0xFFFF;
	*(volatile unsigned int*)(0xfff4400C) = 0x0;

	*(volatile unsigned int*)(0xfff44004) = 0x753F924E;
	*(volatile unsigned int*)(0xfff44004) = 0x8AC06DB1;

	IST_WRITE(0xc0000000);  //Setup-Ijtag
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0x0);  //ToPauseIR
	ret |= IST_READ_BINCMP(0x1);
	IST_WRITE(0x9c000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa0000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xb0008000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40400000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x400004e0);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x8a180040);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x60000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x50043000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x60000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x50041000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x90000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x9d000800);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x9f400200);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3ff3ffff);
	IST_WRITE(0x40800000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x27ffff);
	IST_WRITE(0x81204fc0);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3fffffc0);
	IST_WRITE(0x50400200);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000100);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80205f00);  //ToRTI
	ret |= IST_READ_XCMP(0x9000, 0x3ff7ffe7);
	IST_WRITE(0x44000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x7ffff);
	IST_WRITE(0x40003a00);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x2000000, 0x3ffc0000);
	IST_WRITE(0x842043fe);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x4000000, 0x1fffffff);
	IST_WRITE(0x8c207d00);  //ToRTI
	ret |= IST_READ_XCMP(0x2, 0x3ffffff7);
	IST_WAIT(1);
	IST_WRITE(0x40800000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x10000000);
	IST_WRITE(0x8d201f40);  //ToRTI
	ret |= IST_READ_XCMP(0x18, 0x3ffffffd);
	IST_WAIT(1);
	IST_WAIT(1473060);
	IST_WRITE(0x91d00080);  //ToRTI
	ret |= IST_READ_BINCMP(0x180000);
	IST_WAIT(1);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x24000000);
	IST_WRITE(0x85205d00);  //ToRTI
	ret |= IST_READ_XCMP(0x6, 0x3ffffff7);
	IST_WAIT(4);
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0xc0000010);  //Setup-Done

	return ret;
}

/**
****************************************************************************************
* @brief: []  This function will check Online LBist Partion0.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Lbist0 check is successful
              FS_STATUS_ERROR Lbist0 check failed
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int SAF_LBist_Partiton0(void)
{
	int ret = FS_STATUS_SUCCESS;

	*(volatile unsigned int*)(0xfff44004) = 0xD3FEA98B;
	*(volatile unsigned int*)(0xfff44004) = 0x2C015674;

	*(volatile unsigned int*)(0xfff44000) = 0x10000000;
	*(uint32_t*)0xFFF44018 = 0x00000001;

	*(volatile unsigned int*)(0xfff44004) = 0x753F924E;
	*(volatile unsigned int*)(0xfff44004) = 0x8AC06DB1;

	IST_WRITE(0xc0000000);  //Setup-Ijtag
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0x0);  //ToPauseIR
	ret |= IST_READ_BINCMP(0x1);
	IST_WRITE(0x9c000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa0000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80108000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x800c2000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x8005e100);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x7eeb0800);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80084bff);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x60000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4ac02b70);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x42b00ac0);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40ac02b0);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x402b00ac);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x700ac02b);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x6c02b00a);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x7200ac02);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fffff3e);
	IST_WRITE(0x40aa6008);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40005000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x723ec200);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x33efffff);
	IST_WRITE(0x40aac008);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40005000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4c200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fcfbfff);
	IST_WRITE(0x80001272);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4c200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fcfbfff);
	IST_WRITE(0x8000946a);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x50000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3ffff);
	IST_WRITE(0x45026518);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000ff0);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3ffc0000);
	IST_WRITE(0x80010000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x44000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xffff);
	IST_WRITE(0x50208246);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x5f043051);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x688a9828);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x5cf17213);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x4f1b2b34);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x34000000);
	IST_WRITE(0x41ce31a2);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x1e7);
	IST_WRITE(0x61f63e01);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fe00000);
	IST_WRITE(0x8001e81f);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4c200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fcfbfff);
	IST_WRITE(0x80001272);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4c200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fcfffff);
	IST_WRITE(0x800012f2);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4c200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fcfbfff);
	IST_WRITE(0x800010f2);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1108723);
	IST_WRITE(0x4c200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x4000, 0x3fcfffff);
	IST_WRITE(0x800012f2);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4c200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fcfbfff);
	IST_WRITE(0x80001272);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4c200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fcfbfff);
	IST_WRITE(0x8000107a);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x61000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x17a84000);
	IST_WRITE(0x40000011);  //ToPauseDR
	ret |= IST_READ_XCMP(0x9c, 0x3ff9f7ff);
	IST_WRITE(0x80001000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(4);
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0xc0000010);  //Setup-Done

	*(uint32_t*)0xFFF44018 = 0x10000;
	*(uint32_t*)0xFFF44018 = 0x0;

	return ret;
}

/**
****************************************************************************************
* @brief: []  This function will check Online LBist Partion6.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Lbist6 check is successful
              FS_STATUS_ERROR Lbist6 check failed
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int SAF_LBist_Partiton6(void)
{
	int ret = FS_STATUS_SUCCESS;

	*(volatile unsigned int*)(0xfff44004) = 0xD3FEA98B;
	*(volatile unsigned int*)(0xfff44004) = 0x2C015674;

	*(volatile unsigned int*)(0xfff44000) = 0x10000000;
	*(uint32_t*)0xFFF44018 = 0x00000040;

	*(volatile unsigned int*)(0xfff44004) = 0x753F924E;
	*(volatile unsigned int*)(0xfff44004) = 0x8AC06DB1;

	IST_WRITE(0xc0000000);  //Setup-Ijtag
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0x0);  //ToPauseIR
	ret |= IST_READ_BINCMP(0x1);
	IST_WRITE(0x9c000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa0000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x84008000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x83002000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x81580100);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x48000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x8212ff00);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x56778010);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x55805601);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x46401580);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfbfffff);
	IST_WRITE(0x40154c01);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000a00);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x4647d801);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3bffffff);
	IST_WRITE(0x40155801);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3ffffff3);
	IST_WRITE(0x40000a00);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x33efffff);
	IST_WRITE(0x80049c8c);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x33efffff);
	IST_WRITE(0x80051e8c);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x60040000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x1f7fffff);
	IST_WRITE(0x80641a51);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3ffffffe);
	IST_WRITE(0x44000000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fffff);
	IST_WRITE(0x7c9c9180);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x64fb8fe5);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x511dc73a);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x7eb33598);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x66a3cbe4);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x5b71ef5f);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xc);
	IST_WRITE(0x66000200);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x4000);
	IST_WRITE(0x7d8f83fc);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x38000000);
	IST_WRITE(0x807a07e9);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x33efffff);
	IST_WRITE(0x80049c8c);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x33ffffff);
	IST_WRITE(0x8004bc8c);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x33efffff);
	IST_WRITE(0x80043c8c);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1112740);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x100000, 0x33ffffff);
	IST_WRITE(0x8004bc8c);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x33efffff);
	IST_WRITE(0x80049c8c);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x33efffff);
	IST_WRITE(0x80041e8c);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x41000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x26000000);
	IST_WRITE(0x40000460);  //ToPauseDR
	ret |= IST_READ_XCMP(0x21c1, 0x3e7dffff);
	IST_WRITE(0x80040000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(4);
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0xc0000010);  //Setup-Done

	*(uint32_t*)0xFFF44018 = 0x400000;
	*(uint32_t*)0xFFF44018 = 0x0;

	return ret;
}

/**
****************************************************************************************
* @brief: []  This function will check Online LBist Partion9.
* @param[in] cmpdata data for comparison
* @return status:
              FS_STATUS_SUCCESS Lbist9 check is successful
              FS_STATUS_ERROR Lbist9 check failed
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static int SAF_LBist_Partiton9(void)
{
	int ret = FS_STATUS_SUCCESS;

	*(volatile unsigned int*)(0xfff44004) = 0xD3FEA98B;
	*(volatile unsigned int*)(0xfff44004) = 0x2C015674;

	*(volatile unsigned int*)(0xfff44000) = 0x10000000;
	*(uint32_t*)0xFFF44018 = 0x200;

	*(volatile unsigned int*)(0xfff44004) = 0x753F924E;
	*(volatile unsigned int*)(0xfff44004) = 0x8AC06DB1;

	IST_WRITE(0xc0000000);  //Setup-Ijtag
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0x0);  //ToPauseIR
	ret |= IST_READ_BINCMP(0x1);
	IST_WRITE(0x9c000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0xa0000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x90008000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x8c002000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x85600100);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x42000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x884bff00);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x5e001000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x41580567);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40560158);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40158056);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfbfffff);
	IST_WRITE(0x554c0119);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x400a0000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x47d80040);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x2fffffff);
	IST_WRITE(0x55580119);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3fffffcf);
	IST_WRITE(0x400a0000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x80000000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfbfffff);
	IST_WRITE(0x80127230);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfbfffff);
	IST_WRITE(0x80947a30);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40400000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x3dffffff);
	IST_WRITE(0x41069460);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x39);
	IST_WRITE(0x7e414080);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x81fffdfb);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3ffffffc);
	IST_WRITE(0x40040000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xffffff);
	IST_WRITE(0x4ffbf246);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x73bc35f4);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x7af8c43b);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x4d4bc02a);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x62946a96);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0x1c00000);
	IST_WRITE(0x763e05f9);  //ToPauseDR
	//entire word X, read transaction skipped
	IST_WRITE(0x81e81f67);  //ToRTI
	ret |= IST_READ_XCMP(0x0, 0x3fffff80);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfbfffff);
	IST_WRITE(0x80127230);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfffffff);
	IST_WRITE(0x8012f230);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfbfffff);
	IST_WRITE(0x8010f230);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(1104706);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x400000, 0xfffffff);
	IST_WRITE(0x8012f230);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfbfffff);
	IST_WRITE(0x80127230);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x40200000);  //ToPauseDR
	ret |= IST_READ_XCMP(0x0, 0xfbfffff);
	IST_WRITE(0x80107a30);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WRITE(0x41000000);  //ToPauseDR
	ret |= IST_READ_BINCMP(0x18400000);
	IST_WRITE(0x40001180);  //ToPauseDR
	ret |= IST_READ_XCMP(0x9c05, 0x39f7ffff);
	IST_WRITE(0x80100000);  //ToRTI
	ret |= IST_READ_BINCMP(0x0);
	IST_WAIT(4);
	IST_WRITE(0xc0000011);  //Setup-Reset
	IST_WRITE(0xc0000010);  //Setup-Done

	*(uint32_t*)0xFFF44018 = 0x2000000;
	*(uint32_t*)0xFFF44018 = 0x0;

	return ret;
}
#endif /* SAF_BIST_ONLINE_BIST_SUPPORTED */

/**
****************************************************************************************
* @brief: [] This function is used to initialize the DCF records.
* @param[in] pOfflineCfg: Pointer of offline BIST configuration.
* @param[out] recordCount: Pointer of all DCF records counter.
* @return status
            FS_STATUS_SUCCESS: The DCF is initialized successfully.
            FS_STATUS_ERROR: Failed to initialize the DCF.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
static FS_STATUS SAF_BIST_DcfInit(saf_bist_offline_config_t *pOfflineCfg, uint32_t *recordCount)
{
    FS_STATUS status = FS_STATUS_ERROR;
    saf_dcf_record_t *pRecord;
    bool isLastRec = (bool)false;

    if ((pOfflineCfg != NULL) && (recordCount != NULL))
    {

        pOfflineCfg->lbistCfg = 0;
        pOfflineCfg->mbistCfg = 0;
        pOfflineCfg->dcfCount = 0;

        pRecord = (saf_dcf_record_t *)SAF_BIST_UpdateDcfStartAddr(pOfflineCfg->startAddr);

        pOfflineCfg->startAddr = (uint32_t)pRecord;

        while (!isLastRec)/*PRQA S 4558,4116*/
        {
            if (pRecord->addr.B.stop & 0x1) /*PRQA S 1861,2985*/ /* polyspace RTE:NIV,IDP */
            {
                isLastRec = (bool)true;
                continue;
            }

            SAF_BIST_OfflineBistDcfCfgDetect(pOfflineCfg, pRecord);

            pRecord++;/*PRQA S 0498*/
            pOfflineCfg->dcfCount++;
            pOfflineCfg->endAddr = (uint32_t)pRecord;
        }

        *recordCount = pOfflineCfg->dcfCount;
        status = FS_STATUS_SUCCESS;
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
* @brief: [] This function is used to get the appointed DCF record value.
* @param[in] dcfAddr DCF record address.
* @param[out] pRecordData Pointer of DCF record.
* @return status
            FS_STATUS_SUCCESS: Obtaining data successfully.
            FS_STATUS_ERROR: Data acquisition failure.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
FS_STATUS SAF_BIST_GetDcfValue(const saf_dcf_record_addr_t dcfAddr, uint32_t *pRecordData)
{
    FS_STATUS status = FS_STATUS_ERROR;
    saf_dcf_record_t *pRecord = (saf_dcf_record_t *)SAF_DCF_START_ADDR;
    bool isLastRec = (bool)false;

    if (pRecordData != NULL)
    {
        while (!isLastRec)/*PRQA S 4558,4116*/
        {
            if (pRecord->addr.B.stop & 0x1)/*PRQA S 2985,1861*//* polyspace RTE:NIV,IDP */
            {
                isLastRec = (bool)true;
                continue;
            }

            if ((pRecord->addr.B.addr == dcfAddr.B.addr) && (pRecord->addr.B.cs == dcfAddr.B.cs))/* polyspace RTE:NIV */
            {
                status = FS_STATUS_SUCCESS;
                *pRecordData = pRecord->data;/* polyspace RTE:NIV */
                break;
            }
            pRecord++;/*PRQA S 0498*/
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief: [] This function is used to set configuration data of a specified register
*            with DCF record address..
* @param[in] DcfFlashAddr DCF flash address.
* @param[in] Record DCF record
* @return status
            FS_STATUS_SUCCESS: Data write success.
            FS_STATUS_ERROR: Data write failure.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
FS_STATUS SAF_BIST_SetDcfValue(uint32_t DcfFlashAddr, saf_dcf_record_t Record)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint64_t data = 0U;
    data = (uint64_t)((uint64_t)(Record.data) << SAF_DCF_RECORD_DATA_FIELD_SHIFT) | ((uint64_t)Record.addr.R);
    
    if (SAF_DCF_RECORD_ADDRESS_ALIGNMENT_VALUE != (DcfFlashAddr & SAF_DCF_RECORD_ADDRESS_ALIGNMENT))
    {
        status = FS_STATUS_ERROR;
    }

    if (FS_STATUS_SUCCESS == status)
    {
        if (*(uint64_t*)DcfFlashAddr == SAF_DCF_RECORD_ERASED_VALUE)/* polyspace RTE:NIV,IDP */
        {
            status = SAF_BIST_DCFFlashDoubleWordWrite(DcfFlashAddr, data);
        }
        else
        {
            status = FS_STATUS_ERROR;
        }
    }
    else
    {
        /*do nothing*/
    }

    return status;
}

/**
****************************************************************************************
* @brief: [] This function is used to compare all dcf data.
* @param[in] DcfStartAddr DCF start address.
* @return status
            FS_STATUS_SUCCESS: Data comparison success.
            FS_STATUS_ERROR: Data comparison failure.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
FS_STATUS SAF_BIST_DcfCmpValue(uint32_t DcfStartAddr)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint16_t dcfCount = 0U; //SAF_DCF_RECORD_COUNT
    uint32_t dcfIndex = 0U;
    uint32_t count = 0U;
    uint64_t *pDcf = NULL;

    saf_bist_offline_config_t s_bistDcf = {
        .startAddr = DcfStartAddr,
        .dcfCount = 0,
    };

    (void)SAF_BIST_DcfInit(&s_bistDcf, &count);

    if (count == dcfCount)
    {
        for (dcfIndex = 0U; dcfIndex < dcfCount; dcfIndex++)
        {
            pDcf = (uint64_t *)(s_bistDcf.startAddr + (dcfIndex << SAF_DCF_RECORD_INDEX_SHIFT));/*PRQA S 2880*/
            if (pDcf != NULL_PTR)
            {
                if (*pDcf != DcfRecords[dcfIndex])
                {
                    status = FS_STATUS_ERROR;
                    break;
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
* @brief: [] This function is used to get the configurations of off-Line logic BIST.
* @param[in] pOfflineCfg the offline BIST configuration.
* @return status
            FS_STATUS_SUCCESS: Configuration successfully obtained.
            FS_STATUS_ERROR: Failed to get configuration.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
FS_STATUS SAF_BIST_GetOfflinebistConfig(saf_bist_offline_config_t *pOfflineCfg)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (pOfflineCfg != NULL)
    {
        status = FS_STATUS_SUCCESS;
        memcpy(pOfflineCfg, &s_offlineBistConfig, sizeof(saf_bist_offline_config_t));/*PRQA S 0315*/
    }

    return status;
}

/**
****************************************************************************************
* @brief: [] This function is used to verify that the registers of STCU2 are protected.
* @return status
            FS_STATUS_SUCCESS: The registers of STCU2 are protected.
            FS_STATUS_ERROR: The registers of STCU2 are not protected.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
FS_STATUS SAF_BIST_KeyPairCheck(void)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint16_t ret = SAF_BIST_RET_SUCCESS;

    ret = SAF_BIST_RegValueCmp(SAF_STCU2_BIST_CR, SAF_BIST_CR_MASK);

    ret |= SAF_BIST_RegValueCmp(SAF_STCU2_BIST_PDR, SAF_BIST_PDR_MASK);

    ret |= SAF_BIST_RegValueCmp(SAF_STCU2_BIST_PLL_CFG, SAF_BIST_PLL_MASK);

    ret |= SAF_BIST_RegValueCmp(SAF_STCU2_BIST_WDG, SAF_BIST_WDG_MASK);

    ret |= SAF_BIST_RegValueCmp(SAF_STCU2_BIST_LBRM, SAF_BIST_LBRM_MASK);

    ret |= SAF_BIST_RegValueCmp(SAF_STCU2_BIST_LBDRC, SAF_BIST_LBDRC_MASK);

    if (SAF_BIST_RET_SUCCESS != ret)
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

#ifdef SAF_BIST_ONLINE_BIST_SUPPORTED
/**
****************************************************************************************
* @brief: [] This function is used to initialize on-Line BIST.
* @param[in] lbistPartition Lbist region that needs to be detected
* @param[in] lbistCount Number of LBIsts detected
* @param[in] mbistPartition Mbist region that needs to be detected
* @param[in] mbistCount Number of MBIsts detected
* @return status
            FS_STATUS_SUCCESS: online-bist initialization success. 
            FS_STATUS_ERROR: Online-bist initialization failed.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
FS_STATUS SAF_BIST_OnlineInit(const uint8_t lbistPartition[],
                             const uint8_t lbistCount,
                             const uint8_t mbistPartition[],
                             const uint8_t mbistCount)
{
	FS_STATUS status = FS_STATUS_SUCCESS;
	saf_bist_online_config_t *pBistCfg = &s_onlineBistConfig;
	uint8_t Idx = 0;

	if((lbistCount <= SAF_ONLINE_LBIST_MAX_COUNT) && (mbistCount <= SAF_ONLINE_MBIST_MAX_COUNT))
	{
		pBistCfg->lbistCount = lbistCount;
		pBistCfg->mbistCount = mbistCount;

		for(Idx=0; Idx < pBistCfg->lbistCount; Idx++)
		{
			pBistCfg->lbistPartition[Idx] = lbistPartition[Idx];
		}

		for(Idx=0; Idx < pBistCfg->mbistCount; Idx++)
		{
			pBistCfg->mbistPartition[Idx] = mbistPartition[Idx];
		}
	}
	else
	{
		status = FS_STATUS_ERROR;
	}

	return status;
}
#endif
/**
****************************************************************************************
* @brief: [] This function will check off line MBIST and LBIST execution result and status.
* @param[in] pBistCheckResult Pointer of BIST check result.
* @return status
            FS_STATUS_SUCCESS: The BIST test is successful.
            FS_STATUS_ERROR: The BIST test is error.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
FS_STATUS SAF_BIST_OfflineCheck(saf_bist_check_result_t *pBistCheckResult)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint32_t recordCount;
    saf_bist_offline_config_t *pOfflineBistDcfCfg = &s_offlineBistConfig;

    if (pBistCheckResult != NULL)
    {
        /* Update lbistCfg and mbistCfg */
        SAF_BIST_DcfInit(pOfflineBistDcfCfg, &recordCount);

        if (FS_STATUS_SUCCESS != SAF_BIST_OfflineLbistStatusCheck(pOfflineBistDcfCfg, pBistCheckResult))
        {
            status = FS_STATUS_ERROR;
        }

        if (FS_STATUS_SUCCESS != SAF_BIST_OfflineLbistEndFlagCheck(pOfflineBistDcfCfg, pBistCheckResult))
        {
            status = FS_STATUS_ERROR;
        }

        if (FS_STATUS_SUCCESS != SAF_BIST_OfflineMbistStatusCheck(pOfflineBistDcfCfg, pBistCheckResult))
        {
            status = FS_STATUS_ERROR;
        }

        if (FS_STATUS_SUCCESS != SAF_BIST_OfflineMbistEndFlagCheck(pOfflineBistDcfCfg, pBistCheckResult))
        {
            status = FS_STATUS_ERROR;
        }

		#if SAF_OFFLINEBIST_FAIL_RESET == STD_ON
			if (FS_STATUS_SUCCESS != status)
			{
				Mcu_PerformReset();
			}
		#endif
    }
    else
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}

#ifdef SAF_BIST_ONLINE_BIST_SUPPORTED
/**
****************************************************************************************
* @brief: [] This function will check Online MBIST and LBIST execution result.
* @param[in] pBistCheckResult Pointer of BIST check result.
* @return status
            FS_STATUS_SUCCESS: The offline BIST test is successful.
            FS_STATUS_ERROR: The offline BIST test is error.
****************************************************************************************
*/
SAF_BIST_SEC_CODE
FS_STATUS SAF_BIST_OnlineCheck(saf_bist_check_result_t *pBistCheckResult)
{
	FS_STATUS status = FS_STATUS_SUCCESS;
	FS_STATUS ret = FS_STATUS_SUCCESS;
	uint8_t Idx = 0;
	uint8_t Pidx = 0;
	saf_bist_online_config_t *pBistCfg = &s_onlineBistConfig;

	if (pBistCheckResult != NULL)
	{
		for(Idx = 0; Idx < pBistCfg->mbistCount; Idx++)
		{
			Pidx = pBistCfg->mbistPartition[Idx];
	        ret = (FS_STATUS)s_mbistTest[Pidx].func();/*PRQA S 4432*/
	        pBistCheckResult->onLineMbistCheckResult[Idx] = ret;/*PRQA S 4424*/
	        if(ret != 0)/*PRQA S 1881*/
	        {
	        	status = FS_STATUS_ERROR;
	        }
		}

		for(Idx = 0; Idx < pBistCfg->lbistCount; Idx++)/*PRQA S 4424*/
		{
			Pidx = pBistCfg->lbistPartition[Idx];
	        ret = (FS_STATUS)s_lbistTest[Pidx].func();/*PRQA S 4432*/
	        pBistCheckResult->onLineLbistCheckResult[Idx] = ret;/*PRQA S 4424*/
	        if(ret != 0)/*PRQA S 1881*/
	        {
	        	status = FS_STATUS_ERROR;
	        }
		}
	}
	else
	{
		status = FS_STATUS_ERROR;
	}

	return status;
}
#endif /* SAF_BIST_ONLINE_BIST_SUPPORTED */

#ifdef __cplusplus
}
#endif
