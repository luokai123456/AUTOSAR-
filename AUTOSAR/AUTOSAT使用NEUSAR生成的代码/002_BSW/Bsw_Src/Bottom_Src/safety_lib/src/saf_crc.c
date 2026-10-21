/**
****************************************************************************************
 * @FilePath: saf_crc.c
 * @Author: CCORE
 * @Date: 2024-02-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: Safety crc C Source File
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
#include "saf_crc.h"/*PRQA S 0380 */
#include "saf_ccfc30xx.h"
#include "Saf_MemMap.h"

/*PRQA S 0315 EOF*/
/*PRQA S 1495,1862,1863 EOF*/
/*PRQA S 2052,2053,2844,2984 EOF*/
/*PRQA S 3108,3119,3200,3218,3395,3408 EOF*/
/*PRQA S 4424 EOF*/
/*******************************************************************************
 * Variables
 ******************************************************************************/

SAF_CRC_SEC_VAR_NO_INIT
static uint32_t crc_kInputValue[CRCTST_MAX_INPUT_COUNT];
SAF_CRC_SEC_VAR_NO_INIT
static saf_crc_readback_test_result_t Crc_kReadTestRst[CRC_TOTAL_READBACK_TESTS];
SAF_CRC_SEC_VAR_NO_INIT
saf_crc_self_test_result_t Crc_kSelfTestRst[CRCTST_SELF_TEST_MODE_COUNT];
SAF_CRC_SEC_VAR_INIT
static uint32_t crc_kSelfTestBuff[CRCTST_SELF_TEST_BUFF_COUNT] = \
                                 {0x379C7B59U, 0x7FB8C7D3U, 0xC9002ADCU, 0x79A5B99DU, \
                                  0xE74F6EAEU, 0xCBB200A9U, 0x9FAE1766U, 0x90FDF189U, \
                                  0x521264BAU, 0x7C98E57CU, 0xCD3379C6U, 0x9EF5025EU, \
                                  0x5FB98C19U, 0xA35E3AC3U, 0xD547E452U, 0x4F3ECA72U, \
                                  0xF0737AD2U, 0x1907F94DU, 0xAD8E4E89U, 0x395AA11CU, \
                                  0x3ABCF95DU, 0x18033838U, 0x753386AFU, 0x89850B7FU, \
                                  0x10779F09U, 0x2486A77BU, 0xB54C6302U, 0xB1AA923FU, \
                                  0xC340398EU, 0xDCD9E35BU, 0x021C183BU, 0x992DAA8FU};

SAF_CRC_SEC_VAR_INIT
static uint32_t crc_SelfTestExpectedResult[CRCTST_SELF_TEST_MODE_COUNT] = \
                                 {0x7C55U, 0xC2866195U, 0xA2U, 0xA2U};
#if(SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
static LINFlexD_Type* s_pLinflexRegList[LINFELXD_MAX_INSTANCE] = SAF_LINFELXD_BASE_PTR;
#endif
#if(SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
static DSPI_Type* s_pDspiRegList[DSPI_MAX_INSTANCE] = SAF_DSPI_BASE_PTR;
#endif
#if(SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
static CSENT_Type* s_pCsentRegList[CSENT_MAX_INSTANCE] = SAF_CSENT_BASE_PTR;/*PRQA S 3401 */
#endif

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to set crc seed.
* @param[in]    seedvalue:       crc seed value.
* @return       Void
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static void SAF_CRC_AccessSetSeedReg(uint32_t seedvalue)
{
    CRC_0.CSTAT.R = seedvalue;

    READ_AFTER_WRITE_ASSERT(CRC_0.CSTAT.R, seedvalue);
}

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to get crc output value.
* @param[in]    count:               input buffer count.
* @param[in]    ParamSetIndex:       test index.
* @return       CrctstOutputValue:   crc output value
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static uint32_t SAF_CRC_AccessGetCrcOutput(uint32_t count, const uint8_t ParamSetIndex)
{
    uint16_t index;
    uint32_t CrctstOutputValue = 0;
    if(CRCTST_MAX_INPUT_COUNT > count)
    {
        for(index = 0; index < count; index++)
        {
            CRC_0.INP.R = crc_kInputValue[index];

        }
        CrctstOutputValue = CRC_0.OUTP.R;
    }
    else
    {
        Crc_kReadTestRst[ParamSetIndex].crcErrorFlag = CRCTST_ERROR_FLAG_ON;
    }
    return CrctstOutputValue;
}


/**
****************************************************************************************
* @brief[SW_SM051] This function is used to clear inputbuf.
* @return       void
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static void SAF_CRC_AccessClearInputBuf(void)
{
    (void)memset(crc_kInputValue, 0, CRCTST_MAX_INPUT_COUNT * sizeof(uint32_t));
}


/**
****************************************************************************************
* @brief[SW_SM051] This function is used to execute crc register Check sum.
* @param[in]    ParamSetIndex:       test index.
* @return       CheckSumResult
*               FS_STATUS_SUCCESS: crc check sum success
*               FS_STATUS_CRC_CALC_ERROR: crc check sum error
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static FS_STATUS SAF_CRC_AccessRegCheckSum(const uint8_t ParamSetIndex)
{
    FS_STATUS CheckSumResult = FS_STATUS_SUCCESS;
    if(CRC_TOTAL_READBACK_TESTS <= ParamSetIndex)
    {
        CheckSumResult = FS_STATUS_CRC_CALC_ERROR;
    }
    else if(CRCTST_ERROR_FLAG_ON == Crc_kReadTestRst[ParamSetIndex].crcErrorFlag)
    {
        Crc_kReadTestRst[ParamSetIndex].crcTstRslt = FS_STATUS_CRC_CALC_ERROR;
        CheckSumResult = FS_STATUS_CRC_CALC_ERROR;
    }
    else if(CRCTST_UNINITIALIZED == Crc_kReadTestRst[ParamSetIndex].crcInitialized)
    {
        Crc_kReadTestRst[ParamSetIndex].crcInitialized = CRCTST_INITIALIZED;
        Crc_kReadTestRst[ParamSetIndex].crcExpectedResult = Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult;
        Crc_kReadTestRst[ParamSetIndex].funcName = SAF_crc_kTestInfo[ParamSetIndex].funcName;
    }
    else if(Crc_kReadTestRst[ParamSetIndex].crcExpectedResult != Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult)
    {
        Crc_kReadTestRst[ParamSetIndex].crcTstRslt = FS_STATUS_CRC_CALC_ERROR;
        CheckSumResult = FS_STATUS_CRC_CALC_ERROR;
    }
    else
    {
        Crc_kReadTestRst[ParamSetIndex].crcTstRslt = FS_STATUS_CRC_CALC_SUCCESS;
    }
    return CheckSumResult;
}


/**
****************************************************************************************
* @brief This function is used to get CRC_OUTP register value.
* @return       CrcSelftstOutputValue: crc output value
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static uint32_t SAF_CRC_AccessSeflTestOutput(void)
{
    uint16_t index;
    uint32_t CrcSelftstOutputValue = 0;
    for(index = 0; index < CRCTST_SELF_TEST_BUFF_COUNT; index++)
    {
        CRC_0.INP.R = crc_kSelfTestBuff[index];
    }
    CrcSelftstOutputValue = CRC_0.OUTP.R;

    return CrcSelftstOutputValue;
}

/**
****************************************************************************************
* @brief This function is used to get crc self test result.
* @return       Result
*               FS_STATUS_CRC_SELF_TEST_SUCCESS: self test success
*               FS_STATUS_CRC_SELF_TEST_ERROR: self test error
*               FS_STATUS_ERROR: param error
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static FS_STATUS SAF_CRC_AccessCheckSelfTestResult(uint8_t crcPolyg)
{
    FS_STATUS Result = FS_STATUS_ERROR;
    if(CRCTST_SELF_TEST_MODE_COUNT > crcPolyg)
    {
        Result = Crc_kSelfTestRst[crcPolyg].crcSelfTstRslt;
    }
    return Result;
}

/**
****************************************************************************************
* @brief This function is used to execute crc 8 polynomial self test.
* @return       Result
*               FS_STATUS_SUCCESS: 8 polynomial self test success
*               FS_STATUS_ERROR: 8 polynomial self test error
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static FS_STATUS SAF_CRC_Access8PolygSelfTest(void)
{
    FS_STATUS Result = FS_STATUS_SUCCESS;
    CRC_CFG_tag lCfgRegVal;

    Crc_kSelfTestRst[CRCTST_8_POLYG].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_SUCCESS;
    lCfgRegVal.R = CRC_0.CFG.R;
    lCfgRegVal.B.POLYG = CRCTST_8_POLYG;
    lCfgRegVal.B.SWAP_BITWISE = CRCTST_INPUT_BITSWAP;
    CRC_0.CFG.R = lCfgRegVal.R;

    READ_AFTER_WRITE_ASSERT(CRC_0.CFG.R, lCfgRegVal.R);

    SAF_CRC_AccessSetSeedReg(SAF_CRC_8_TEST_SEED);
    if(crc_SelfTestExpectedResult[CRCTST_8_POLYG] != SAF_CRC_AccessSeflTestOutput())
    {
        Crc_kSelfTestRst[CRCTST_8_POLYG].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_ERROR;
        Result = FS_STATUS_ERROR;
    }
    return Result;
}

/**
****************************************************************************************
* @brief This function is used to execute crc 32 polynomial self test.
* @return       Result
*               FS_STATUS_SUCCESS: 32 polynomial self test success
*               FS_STATUS_ERROR: 32 polynomial self test error
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static FS_STATUS SAF_CRC_Access32PolygSelfTest(void)
{
    FS_STATUS Result = FS_STATUS_SUCCESS;
    CRC_CFG_tag lCfgRegVal;

    Crc_kSelfTestRst[CRCTST_32_POLYG].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_SUCCESS;
    lCfgRegVal.R = CRC_0.CFG.R;
    lCfgRegVal.B.POLYG = CRCTST_32_POLYG;
    lCfgRegVal.B.SWAP_BITWISE = CRCTST_INPUT_BITSWAP;
    CRC_0.CFG.R = lCfgRegVal.R;

    READ_AFTER_WRITE_ASSERT(CRC_0.CFG.R, lCfgRegVal.R);

    SAF_CRC_AccessSetSeedReg(SAF_CRC_32_TEST_SEED);
    if(crc_SelfTestExpectedResult[CRCTST_32_POLYG] != SAF_CRC_AccessSeflTestOutput())
    {
        Crc_kSelfTestRst[CRCTST_32_POLYG].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_ERROR;
        Result = FS_STATUS_ERROR;
    }
    return Result;
}

/**
****************************************************************************************
* @brief This function is used to execute crc reserved self test.
* @return       Result
*               FS_STATUS_SUCCESS: reserved self test success
*               FS_STATUS_ERROR: reserved self test error
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static FS_STATUS SAF_CRC_AccessResPolygSelfTest(void)
{
    FS_STATUS Result = FS_STATUS_SUCCESS;
    CRC_CFG_tag lCfgRegVal;

    Crc_kSelfTestRst[CRCTST_RESERVED].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_SUCCESS;
    lCfgRegVal.R = CRC_0.CFG.R;
    lCfgRegVal.B.POLYG = CRCTST_RESERVED;
    lCfgRegVal.B.SWAP_BITWISE = CRCTST_INPUT_BITSWAP;
    CRC_0.CFG.R = lCfgRegVal.R;

    READ_AFTER_WRITE_ASSERT(CRC_0.CFG.R, lCfgRegVal.R);

    SAF_CRC_AccessSetSeedReg(SAF_CRC_8_TEST_SEED);
    if(crc_SelfTestExpectedResult[CRCTST_RESERVED] != SAF_CRC_AccessSeflTestOutput())
    {
        Crc_kSelfTestRst[CRCTST_RESERVED].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_ERROR;
        Result = FS_STATUS_ERROR;
    }
    return Result;
}

/**
****************************************************************************************
* @brief This function is used to execute crc ccitt polynomial self test.
* @return       Result
*               FS_STATUS_SUCCESS: ccitt polynomial self test success
*               FS_STATUS_ERROR: ccitt polynomial self test error
****************************************************************************************
*/
SAF_CRC_SEC_CODE
static FS_STATUS SAF_CRC_AccessCcittPolygSelfTest(void)
{
    FS_STATUS Result = FS_STATUS_SUCCESS;
    CRC_CFG_tag lCfgRegVal;

    Crc_kSelfTestRst[CRCTST_CCITT_POLYG].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_SUCCESS;
    lCfgRegVal.R = CRC_0.CFG.R;
    lCfgRegVal.B.POLYG = CRCTST_CCITT_POLYG;
    lCfgRegVal.B.SWAP_BITWISE = CRCTST_INPUT_BITSWAP;
    CRC_0.CFG.R = lCfgRegVal.R;

    READ_AFTER_WRITE_ASSERT(CRC_0.CFG.R, lCfgRegVal.R);

    SAF_CRC_AccessSetSeedReg(SAF_CRC_16_TEST_SEED);
    if(crc_SelfTestExpectedResult[CRCTST_CCITT_POLYG] != SAF_CRC_AccessSeflTestOutput())
    {
        Crc_kSelfTestRst[CRCTST_CCITT_POLYG].crcSelfTstRslt = FS_STATUS_CRC_SELF_TEST_ERROR;
        Result = FS_STATUS_ERROR;
    }
    return Result;
}

/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/

/**
****************************************************************************************
* @brief This function is used to execute crc self test.
* @return       Result
*               FS_STATUS_SUCCESS: self test success
*               FS_STATUS_ERROR: self test error
****************************************************************************************
*/
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_SelfTest(void)
{
    FS_STATUS Result = FS_STATUS_SUCCESS;

    /* step1: set CRC_CFG to CCITT polynomial */
    if(FS_STATUS_SUCCESS != SAF_CRC_AccessCcittPolygSelfTest())
    {
        Result = FS_STATUS_ERROR;
    }

    /* step2: set CRC_CFG to 8 polynomial */
    if(FS_STATUS_SUCCESS != SAF_CRC_Access8PolygSelfTest())
    {
        Result = FS_STATUS_ERROR;
    }

    /* step3: set CRC_CFG to reserved */
    if(FS_STATUS_SUCCESS != SAF_CRC_AccessResPolygSelfTest())
    {
        Result = FS_STATUS_ERROR;
    }

    /* step4: set CRC_CFG to 32 polynomial */
    if(FS_STATUS_SUCCESS != SAF_CRC_Access32PolygSelfTest())
    {
        Result = FS_STATUS_ERROR;
    }

    return Result;
}


/**
****************************************************************************************
* @brief:  This function is used to execute crc register read back test.
* @param[in]    index    	test index.
* @return       Result		test result
****************************************************************************************
*/
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_RegisterReadbackTest(const uint8_t ParamSetIndex)/*PRQA S 1330 */
{
    FS_STATUS Result = FS_STATUS_SUCCESS;
    CRC_CSTAT_tag lCstatRegVal;
    uint8_t crcPolygValue = 0;

    crcPolygValue = (uint8_t)CRC_0.CFG.B.POLYG;
    if(FS_STATUS_CRC_SELF_TEST_SUCCESS != SAF_CRC_AccessCheckSelfTestResult(crcPolygValue))
    {
        Result = FS_STATUS_CRC_SELF_TEST_ERROR;
    }
    else if((CRC_TOTAL_READBACK_TESTS <= ParamSetIndex) || (SAF_NULL_PTR == SAF_crc_kTestInfo[ParamSetIndex].TestFuncPtr))
    {
        Result = FS_STATUS_CRC_INV_PARAM_ERR;
    }
    else
    {
        lCstatRegVal.R = CRC_0.CSTAT.R;
        SAF_CRC_AccessSetSeedReg(CRCTST_INIT_SEEDVALUE);
        SAF_CRC_AccessClearInputBuf();
        Crc_kReadTestRst[ParamSetIndex].crcErrorFlag = CRCTST_ERROR_FLAG_OFF;

        if(FS_STATUS_SUCCESS != (SAF_crc_kTestInfo[ParamSetIndex].TestFuncPtr(ParamSetIndex)))
        {
            Result = FS_STATUS_CRC_CALC_ERROR;
        }
        else
        {
            Result = SAF_CRC_AccessRegCheckSum(ParamSetIndex);
        }
        CRC_0.CSTAT.R = lCstatRegVal.R;
	}

    return Result;
}

/**
****************************************************************************************
* @brief:  		This function is used to readback xbar config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
SAF_CRC_SEC_CODE
#if(SAF_CRC_XbarRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
FS_STATUS SAF_CRC_XbarRegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
	uint16_t index = 0;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
		crc_kInputValue[index++] = XBAR_0.PORT[0].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[0].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[1].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[1].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[2].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[2].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
	#if !(defined(CCFC3008PC) | defined(CCFC3008PCSN))
		crc_kInputValue[index++] = XBAR_0.PORT[3].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[3].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
	#endif
		crc_kInputValue[index++] = XBAR_0.PORT[4].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[4].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[5].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[5].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
	//	crc_kInputValue[index++] = XBAR_0_PRS6;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
	//	crc_kInputValue[index++] = XBAR_0_CRS6;         /* XBAR Control Register */          /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[7].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_0.PORT[7].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */

		crc_kInputValue[index++] = XBAR_1.PORT[0].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_1.PORT[0].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
	#if !(defined(CCFC3008PC) | defined(CCFC3008PCSN))
		crc_kInputValue[index++] = XBAR_1.PORT[1].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_1.PORT[1].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
	#endif
		crc_kInputValue[index++] = XBAR_1.PORT[2].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_1.PORT[2].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_1.PORT[3].PRS.R;         /* XBAR Priority Registers Slave */  /* polyspace RTE:NIV */
		crc_kInputValue[index++] = XBAR_1.PORT[3].CRS.R;         /* XBAR Control Register */          /* polyspace RTE:NIV */
	//	crc_kInputValue[index++] = XBAR_1_PRS4;         /* XBAR Priority Registers Slave */
	//	crc_kInputValue[index++] = XBAR_1_CRS4;         /* XBAR Control Register */
	//	crc_kInputValue[index++] = XBAR_1_PRS5;         /* XBAR Priority Registers Slave */
	//	crc_kInputValue[index++] = XBAR_1_CRS5;         /* XBAR Control Register */
	//	crc_kInputValue[index++] = XBAR_1_PRS6;         /* XBAR Priority Registers Slave */
	//	crc_kInputValue[index++] = XBAR_1_CRS6;		  	/* XBAR Control Register */
	//	crc_kInputValue[index++] = XBAR_1_PRS7;		  	/* XBAR Priority Registers Slave */
	//	crc_kInputValue[index++] = XBAR_1_CRS7;		  	/* XBAR Control Register */

		Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);  /* polyspace RTE:OBAI */
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

	return RegReadbackResult;
}
#endif /* #if(SAF_CRC_XbarRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief:  		This function is used to readback pit config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
#if(SAF_CRC_PitRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_PitRegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
	uint16_t index = 0;
	uint16_t i = 0;
    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
		/*PIT0 Register*/
		crc_kInputValue[index++] = PIT_0.MCR.R;		/* PIT Module Control Register */
		crc_kInputValue[index++] = PIT_0.RTI_LDVAL.R;	/* PIT RTI Timer Load Value Register */
		crc_kInputValue[index++] = PIT_0.RTI_TCTRL.R;	/* PIT RTI Timer Control Register */
		/*PIT1 Register*/
		crc_kInputValue[index++] = PIT_1.MCR.R;		/* PIT Module Control Register */
		crc_kInputValue[index++] = PIT_1.RTI_LDVAL.R;	/* PIT RTI Timer Load Value Register */
		crc_kInputValue[index++] = PIT_1.RTI_TCTRL.R;	/* PIT RTI Timer Control Register */

		for(i = 0; i < PIT_TIMER_COUNT; i++)
		{
			/*PIT0 Register*/
			crc_kInputValue[index++] = PIT_0.TIMER[i].LDVAL.R;        /* PIT Timer Load Value Register n */ /* polyspace RTE:NIV */
			crc_kInputValue[index++] = PIT_0.TIMER[i].TCTRL.R;        /* PIT Timer Control Register n */    /* polyspace RTE:NIV */
			/*PIT1 Register*/
			crc_kInputValue[index++] = PIT_1.TIMER[i].LDVAL.R;        /* PIT Timer Load Value Register n */ /* polyspace RTE:NIV */
			crc_kInputValue[index++] = PIT_1.TIMER[i].TCTRL.R;        /* PIT Timer Control Register n */    /* polyspace RTE:NIV */
		}

		Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex); /* polyspace RTE:OBAI */
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }
    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_PitRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief:  		This function is used to readback CMU config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
#if(SAF_CRC_CmuRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_CmuRegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
	uint16_t index = 0;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
		crc_kInputValue[index++] = CMU_ADCSAR.CSR.R;              /* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_ADCSAR.HFREFR.R;          	/* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_ADCSAR.LFREFR.R;           /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_ADCSD.CSR.R ;				/* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_ADCSD.HFREFR.R;            /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_ADCSD.LFREFR.R;            /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_CLKOUT.CSR.R;              /* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_CLKOUT.HFREFR.R;           /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_CLKOUT.LFREFR.R;           /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_CORE.CSR.R;             	/* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_CORE.HFREFR.R;             /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_CORE.LFREFR.R;             /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_FXBAR.CSR.R;               /* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_FXBAR.HFREFR.R;            /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_FXBAR.LFREFR.R;            /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_PBRIDGE.CSR.R;             /* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_PBRIDGE.HFREFR.R;          /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_PBRIDGE.LFREFR.R;          /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_PER.CSR.R;                	/* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_PER.HFREFR.R;              /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_PER.LFREFR.R;              /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_PLL.CSR.R;                 /* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_PLL.HFREFR.R;              /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_PLL.LFREFR.R;             	/* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_PSI5_1US.CSR.R;            /* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_PSI5_1US.HFREFR.R;         /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_PSI5_1US.LFREFR.R;         /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_PSI5_F125.CSR.R;          	/* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_PSI5_F125.HFREFR.R;        /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_PSI5_F125.LFREFR.R;        /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_PSI5_F189.CSR.R;           /* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_PSI5_F189.HFREFR.R;        /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_PSI5_F189.LFREFR.R;        /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_SENT.CSR.R;               	/* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_SENT.HFREFR.R;             /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_SENT.LFREFR.R;             /* CMU Low Frequency Reference Register CLKMN1 */

		crc_kInputValue[index++] = CMU_SXBAR.CSR.R;              	/* CMU Control Status Register */
		crc_kInputValue[index++] = CMU_SXBAR.HFREFR.R;            /* CMU High Frequency Reference Register CLKMN1 */
		crc_kInputValue[index++] = CMU_SXBAR.LFREFR.R;            /* CMU Low Frequency Reference Register CLKMN1 */
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

	Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex); /*PRQA S 2842*//* polyspace RTE:OBAI */

	return RegReadbackResult;
}
#endif /* #if(SAF_CRC_CmuRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief:  		This function is used to readback Pbridge config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
#if(SAF_CRC_PbridgeRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_PbridgeRegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
	uint16_t index = 0;
	uint16_t i = 0;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
		/*PBRIDGE_A Register*/
		crc_kInputValue[index++] = PBRIDGE_A.MPRA.R;		/* Master Privilege Register A */
		/*PBRIDGE_B Register*/
		crc_kInputValue[index++] = PBRIDGE_B.MPRA.R;		/* Master Privilege Register A */

		for(i = 0; i < PACR_COUNT; i++)
		{
			if(i != 4)
			{
				/*PBRIDGE_A Register*/
				crc_kInputValue[index++] = PBRIDGE_A.PACR[i].R;        /* Peripheral Access Control Register */ /* polyspace RTE:NIV */
				/*PBRIDGE_B Register*/
				crc_kInputValue[index++] = PBRIDGE_B.PACR[i].R;        /* Peripheral Access Control Register */ /* polyspace RTE:NIV */
			}
		}

		for(i = 0; i < OPACR_COUNT; i++)
		{
			/*PBRIDGE_A Register*/
			crc_kInputValue[index++] = PBRIDGE_A.OPACR[i].R;       /* Off-platform Peripheral Access Control Register */ /* polyspace RTE:NIV */
			/*PBRIDGE_B Register*/
			crc_kInputValue[index++] = PBRIDGE_B.OPACR[i].R;       /* Off-platform Peripheral Access Control Register */ /* polyspace RTE:NIV */
		}
		Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex); /* polyspace RTE:OBAI */
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

	return RegReadbackResult;
}
#endif /* #if(SAF_CRC_PbridgeRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief:  		This function is used to readback Emios config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
#if(SAF_CRC_EmiosRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_EmiosRegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
	uint16_t index = 0;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
		crc_kInputValue[index++] = EMIOS_0.MCR.R;
	#ifndef CCFC3012PT
		crc_kInputValue[index++] = EMIOS_1.MCR.R;
	#endif

		Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex); /* polyspace RTE:OBAI */
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

	return RegReadbackResult;
}
#endif /* #if(SAF_CRC_EmiosRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief:  		This function is used to readback Etpu config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
#if(SAF_CRC_EtpuRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_EtpuRegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
	uint16_t index = 0;
	uint16_t i = 0;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
		for(i = 0; i < ETPU_CR_COUNT; i++)
		{
			/*ETPU_A & ETPU_B Register*/
			crc_kInputValue[index++] = ETPU_AB_CR_ENG1.CHAN[i].CR.R; /* polyspace RTE:NIV */
			crc_kInputValue[index++] = ETPU_AB_CR_ENG2.CHAN[i].CR.R; /* polyspace RTE:NIV */
			/*ETPU_C Register*/
			crc_kInputValue[index++] = ETPU_C_CR_ENG1.CHAN[i].CR.R;  /* polyspace RTE:NIV */
			crc_kInputValue[index++] = ETPU_C_CR_ENG2.CHAN[i].CR.R;  /* polyspace RTE:NIV */
		}
		Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex); /* polyspace RTE:OBAI */
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

	return RegReadbackResult;
}
#endif /* #if(SAF_CRC_EtpuRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief:  		This function is used to readback Eqadc config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
#if(SAF_CRC_EqadcRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_EqadcRegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
	uint16_t index = 0;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
	#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
		crc_kInputValue[index++] = EQADC1_ADC23.MCR.R;
	#else
		crc_kInputValue[index++] = EQADC0_ADC01.MCR.R;
	#endif
	#if defined(CCFC3007PT)
		crc_kInputValue[index++] = EQADC1_ADC23.MCR.R;
		crc_kInputValue[index++] = EQADC2_ADC45.MCR.R;
		crc_kInputValue[index++] = EQADC3_ADC67.MCR.R;
		crc_kInputValue[index++] = EQADC4_ADC89.MCR.R;
	#endif

		Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex); /* polyspace RTE:OBAI */
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

	return RegReadbackResult;
}
#endif /* #if(SAF_CRC_EqadcRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief:  		This function is used to readback Sdadc config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
#if(SAF_CRC_SdadcRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_SdadcRegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
#if defined(CCFC3007PT)
	uint16_t index = 0;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
		crc_kInputValue[index++] = SDADC_0.FCFGC.R;
		crc_kInputValue[index++] = SDADC_0.FCFGM.R;
		crc_kInputValue[index++] = SDADC_0.IECFG.R;
		crc_kInputValue[index++] = SDADC_0.FCFG.R;
		crc_kInputValue[index++] = SDADC_0.DICFG.R;
		crc_kInputValue[index++] = SDADC_0.OVSCFG.R;
		crc_kInputValue[index++] = SDADC_0.HTCFG.R;
		crc_kInputValue[index++] = SDADC_0.STCFG.R;
		crc_kInputValue[index++] = SDADC_0.ATT.R;

		crc_kInputValue[index++] = SDADC_1.FCFGC.R;
		crc_kInputValue[index++] = SDADC_1.FCFGM.R;
		crc_kInputValue[index++] = SDADC_1.IECFG.R;
		crc_kInputValue[index++] = SDADC_1.FCFG.R;
		crc_kInputValue[index++] = SDADC_1.DICFG.R;
		crc_kInputValue[index++] = SDADC_1.OVSCFG.R;
		crc_kInputValue[index++] = SDADC_1.HTCFG.R;
		crc_kInputValue[index++] = SDADC_1.STCFG.R;
		crc_kInputValue[index++] = SDADC_1.ATT.R;

		crc_kInputValue[index++] = SDADC_2.FCFGC.R;
		crc_kInputValue[index++] = SDADC_2.FCFGM.R;
		crc_kInputValue[index++] = SDADC_2.IECFG.R;
		crc_kInputValue[index++] = SDADC_2.FCFG.R;
		crc_kInputValue[index++] = SDADC_2.DICFG.R;
		crc_kInputValue[index++] = SDADC_2.OVSCFG.R;
		crc_kInputValue[index++] = SDADC_2.HTCFG.R;
		crc_kInputValue[index++] = SDADC_2.STCFG.R;
		crc_kInputValue[index++] = SDADC_2.ATT.R;

		crc_kInputValue[index++] = SDADC_3.FCFGC.R;
		crc_kInputValue[index++] = SDADC_3.FCFGM.R;
		crc_kInputValue[index++] = SDADC_3.IECFG.R;
		crc_kInputValue[index++] = SDADC_3.FCFG.R;
		crc_kInputValue[index++] = SDADC_3.DICFG.R;
		crc_kInputValue[index++] = SDADC_3.OVSCFG.R;
		crc_kInputValue[index++] = SDADC_3.HTCFG.R;
		crc_kInputValue[index++] = SDADC_3.STCFG.R;
		crc_kInputValue[index++] = SDADC_3.ATT.R;

		crc_kInputValue[index++] = SDADC_4.FCFGC.R;
		crc_kInputValue[index++] = SDADC_4.FCFGM.R;
		crc_kInputValue[index++] = SDADC_4.IECFG.R;
		crc_kInputValue[index++] = SDADC_4.FCFG.R;
		crc_kInputValue[index++] = SDADC_4.DICFG.R;
		crc_kInputValue[index++] = SDADC_4.OVSCFG.R;
		crc_kInputValue[index++] = SDADC_4.HTCFG.R;
		crc_kInputValue[index++] = SDADC_4.STCFG.R;
		crc_kInputValue[index++] = SDADC_4.ATT.R;

		crc_kInputValue[index++] = SDADC_6.FCFGC.R;
		crc_kInputValue[index++] = SDADC_6.FCFGM.R;
		crc_kInputValue[index++] = SDADC_6.IECFG.R;
		crc_kInputValue[index++] = SDADC_6.FCFG.R;
		crc_kInputValue[index++] = SDADC_6.DICFG.R;
		crc_kInputValue[index++] = SDADC_6.OVSCFG.R;
		crc_kInputValue[index++] = SDADC_6.HTCFG.R;
		crc_kInputValue[index++] = SDADC_6.STCFG.R;
		crc_kInputValue[index++] = SDADC_6.ATT.R;

		crc_kInputValue[index++] = SDADC_7.FCFGC.R;
		crc_kInputValue[index++] = SDADC_7.FCFGM.R;
		crc_kInputValue[index++] = SDADC_7.IECFG.R;
		crc_kInputValue[index++] = SDADC_7.FCFG.R;
		crc_kInputValue[index++] = SDADC_7.DICFG.R;
		crc_kInputValue[index++] = SDADC_7.OVSCFG.R;
		crc_kInputValue[index++] = SDADC_7.HTCFG.R;
		crc_kInputValue[index++] = SDADC_7.STCFG.R;
		crc_kInputValue[index++] = SDADC_7.ATT.R;

		crc_kInputValue[index++] = SDADC_8.FCFGC.R;
		crc_kInputValue[index++] = SDADC_8.FCFGM.R;
		crc_kInputValue[index++] = SDADC_8.IECFG.R;
		crc_kInputValue[index++] = SDADC_8.FCFG.R;
		crc_kInputValue[index++] = SDADC_8.DICFG.R;
		crc_kInputValue[index++] = SDADC_8.OVSCFG.R;
		crc_kInputValue[index++] = SDADC_8.HTCFG.R;
		crc_kInputValue[index++] = SDADC_8.STCFG.R;
		crc_kInputValue[index++] = SDADC_8.ATT.R;

		Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex); /* polyspace RTE:OBAI */

    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }
#else
    (void)ParamSetIndex;
#endif /* CCFC3007PT */
	return RegReadbackResult;
}
#endif /* #if(SAF_CRC_SdadcRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief:  		This function is used to readback pmc config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
#if(SAF_CRC_PmcRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_PmcRegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
	uint16_t index = 0;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
		crc_kInputValue[index++] = PMCDIG.REE_VD3.R;
		crc_kInputValue[index++] = PMCDIG.RES_VD3.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD3.R;
		crc_kInputValue[index++] = PMCDIG.REE_VD4.R;
		crc_kInputValue[index++] = PMCDIG.RES_VD4.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD4.R;
		crc_kInputValue[index++] = PMCDIG.REE_VD7.R;
		crc_kInputValue[index++] = PMCDIG.RES_VD7.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD7.R;
		crc_kInputValue[index++] = PMCDIG.REE_VD8.R;
		crc_kInputValue[index++] = PMCDIG.RES_VD8.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD8.R;
		crc_kInputValue[index++] = PMCDIG.REE_VD9.R;
		crc_kInputValue[index++] = PMCDIG.RES_VD9.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD9.R;
		crc_kInputValue[index++] = PMCDIG.REE_VD10.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD10.R;
		crc_kInputValue[index++] = PMCDIG.REE_VD12.R;
		crc_kInputValue[index++] = PMCDIG.RES_VD12.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD12.R;
		crc_kInputValue[index++] = PMCDIG.REE_VD13.R;
		crc_kInputValue[index++] = PMCDIG.RES_VD13.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD13.R;
		crc_kInputValue[index++] = PMCDIG.REE_VD14.R;
		crc_kInputValue[index++] = PMCDIG.RES_VD14.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD14.R;
		crc_kInputValue[index++] = PMCDIG.REE_VD15.R;
		crc_kInputValue[index++] = PMCDIG.RES_VD15.R;
		crc_kInputValue[index++] = PMCDIG.FEE_VD15.R;
		crc_kInputValue[index++] = PMCDIG.VSIO.R;
		crc_kInputValue[index++] = PMCDIG.REE_TD.R;
		crc_kInputValue[index++] = PMCDIG.RES_TD.R;
		crc_kInputValue[index++] = PMCDIG.CTL_TD.R;
		crc_kInputValue[index++] = PMCDIG.FEE_TD.R;
		crc_kInputValue[index++] = PMCDIG.VREG1P2_CTRL.R;

    	Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex); /* polyspace RTE:OBAI */
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

	return RegReadbackResult;
}
#endif /* #if(SAF_CRC_PmcRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief:  		This function is used to readback Siul2 config register.
* @param[in]    ParamSetIndex    	test index.
* @return       RegReadbackResult	test result
****************************************************************************************
*/
#if(SAF_CRC_Siul2RegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_Siul2RegReadbackCheck(const uint8_t ParamSetIndex)
{
	FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
#if !defined(CCFC3012PT)
	uint16_t index = 0;
	uint16_t i = 0;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
		crc_kInputValue[index++] = SIUL2.SCR0.R;
		for(i = 0; i < SIUL2_MSCR_COUNT; i++)
		{
			crc_kInputValue[index++] = SIUL2.MSCR_IO[i].R;  /* polyspace RTE:NIV */
			crc_kInputValue[index++] = SIUL2.MSCR_MUX[i].R; /* polyspace RTE:NIV */
		}

		Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);  /* polyspace RTE:OBAI */
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }
#else
    (void)ParamSetIndex;
#endif
	return RegReadbackResult;
}
#endif /* #if(SAF_CRC_Siul2RegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback MC_RGM config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back MC_RGM register success
*               FS_STATUS_ERROR: read back MC_RGM register param error
****************************************************************************************
*/
#if(SAF_CRC_RgmRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_RgmRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = MC_RGM.DERD.R;
        crc_kInputValue[index++] = MC_RGM.DEAR.R;
        crc_kInputValue[index++] = MC_RGM.DBRE.R;
        crc_kInputValue[index++] = MC_RGM.FERD.R;
        crc_kInputValue[index++] = MC_RGM.FEAR.R;
        crc_kInputValue[index++] = MC_RGM.FBRE.R;
        crc_kInputValue[index++] = MC_RGM.FESS.R;
        crc_kInputValue[index++] = MC_RGM.FRET.R;
        crc_kInputValue[index++] = MC_RGM.DRET.R;
        crc_kInputValue[index++] = MC_RGM.EROEC.R;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_RgmRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback INTC config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back INTC register success
*               FS_STATUS_ERROR: read back INTC register param error
****************************************************************************************
*/
#if(SAF_CRC_IntcRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_IntcRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = INTC_0.BCR.R;
        crc_kInputValue[index++] = INTC_0.MPROT.R;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_IntcRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback RAM config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back RAM register success
*               FS_STATUS_ERROR: read back RAM register param error
****************************************************************************************
*/
#if(SAF_CRC_RamRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_RamRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = PRAMC.PRCR1.R;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_RamRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback FLASH config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back FLASH register success
*               FS_STATUS_ERROR: read back FLASH register param error
****************************************************************************************
*/
#if(SAF_CRC_FlashRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_FlashRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = PFLASH.PFCR1.R;
        crc_kInputValue[index++] = PFLASH.PFCR2.R;
        crc_kInputValue[index++] = PFLASH.PFCR3.R;

        crc_kInputValue[index++] = PFLASH.PFCRCR.R;
        crc_kInputValue[index++] = PFLASH.PFCRCR.R;
        crc_kInputValue[index++] = PFLASH.PFCRDE.R;

        for (i = 0; i < FLASH_PFCRD_COUNT; i++)
        {
            crc_kInputValue[index++] = PFLASH.PFCRD[i].Word0.R;
            crc_kInputValue[index++] = PFLASH.PFCRD[i].Word1.R;
            crc_kInputValue[index++] = PFLASH.PFCRD[i].Word2.R;
        }

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_FlashRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback DMA config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back DMA register success
*               FS_STATUS_ERROR: read back DMA register param error
****************************************************************************************
*/
#if(SAF_CRC_DmaRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_DmaRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = eDMA_0.CR.R;
        crc_kInputValue[index++] = eDMA_0.ERQH.R;
        crc_kInputValue[index++] = eDMA_0.ERQL.R;
        crc_kInputValue[index++] = eDMA_0.EEIH.R;
        crc_kInputValue[index++] = eDMA_0.EEIL.R;

        crc_kInputValue[index++] = eDMA_1.CR.R;
        crc_kInputValue[index++] = eDMA_1.ERQH.R;
        crc_kInputValue[index++] = eDMA_1.ERQL.R;
        crc_kInputValue[index++] = eDMA_1.EEIH.R;
        crc_kInputValue[index++] = eDMA_1.EEIL.R;

        for(i = 0; i < EDMA_DCH_COUNT; i++)
        {
            crc_kInputValue[index++] = eDMA_0.DCHPRI[i].R;
            crc_kInputValue[index++] = eDMA_0.DCHMID[i].R;

            crc_kInputValue[index++] = eDMA_1.DCHPRI[i].R;
            crc_kInputValue[index++] = eDMA_1.DCHMID[i].R;
        }

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_DmaRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback CANFD config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back CANFD register success
*               FS_STATUS_ERROR: read back CANFD register param error
****************************************************************************************
*/
#if(SAF_CRC_CanfdRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_CanfdRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = CANFD_1.PRESC;
        crc_kInputValue[index++] = CANFD_1.INTE.R;
        crc_kInputValue[index++] = CANFD_1.TCRL.R;
        crc_kInputValue[index++] = CANFD_1.RCRL.R;
        crc_kInputValue[index++] = CANFD_1.TRIG_CFG_0.R;
        crc_kInputValue[index++] = CANFD_1.TRIG_CFG_1.R;
        crc_kInputValue[index++] = CANFD_1.TTCFG.R;
        crc_kInputValue[index++] = CANFD_1.SCFG.R;
        crc_kInputValue[index++] = CANFD_1.ACFEN_0;
        crc_kInputValue[index++] = CANFD_1.ACFEN_1;

        crc_kInputValue[index++] = CANFD_9.PRESC;
        crc_kInputValue[index++] = CANFD_9.INTE.R;
        crc_kInputValue[index++] = CANFD_9.TCRL.R;
        crc_kInputValue[index++] = CANFD_9.RCRL.R;
        crc_kInputValue[index++] = CANFD_9.TRIG_CFG_0.R;
        crc_kInputValue[index++] = CANFD_9.TRIG_CFG_1.R;
        crc_kInputValue[index++] = CANFD_9.TTCFG.R;
        crc_kInputValue[index++] = CANFD_9.SCFG.R;
        crc_kInputValue[index++] = CANFD_9.ACFEN_0;
        crc_kInputValue[index++] = CANFD_9.ACFEN_1;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_CanfdRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback CAN config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back CAN register success
*               FS_STATUS_ERROR: read back CAN register param error
****************************************************************************************
*/
#if(SAF_CRC_CanRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_CanRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = M_CAN_1.CCCR.R;
        crc_kInputValue[index++] = M_CAN_1.TOCC.R;
        crc_kInputValue[index++] = M_CAN_1.TDCR.R;
        crc_kInputValue[index++] = M_CAN_1.IE.R;
        crc_kInputValue[index++] = M_CAN_1.ILS.R;
        crc_kInputValue[index++] = M_CAN_1.ILE.R;
        crc_kInputValue[index++] = M_CAN_1.GFC.R;
        crc_kInputValue[index++] = M_CAN_1.SIDFC.R;
        crc_kInputValue[index++] = M_CAN_1.XIDFC.R;

        crc_kInputValue[index++] = M_CAN_2.CCCR.R;
        crc_kInputValue[index++] = M_CAN_2.TOCC.R;
        crc_kInputValue[index++] = M_CAN_2.TDCR.R;
        crc_kInputValue[index++] = M_CAN_2.IE.R;
        crc_kInputValue[index++] = M_CAN_2.ILS.R;
        crc_kInputValue[index++] = M_CAN_2.ILE.R;
        crc_kInputValue[index++] = M_CAN_2.GFC.R;
        crc_kInputValue[index++] = M_CAN_2.SIDFC.R;
        crc_kInputValue[index++] = M_CAN_2.XIDFC.R;

        crc_kInputValue[index++] = M_CAN_3.CCCR.R;
        crc_kInputValue[index++] = M_CAN_3.TOCC.R;
        crc_kInputValue[index++] = M_CAN_3.TDCR.R;
        crc_kInputValue[index++] = M_CAN_3.IE.R;
        crc_kInputValue[index++] = M_CAN_3.ILS.R;
        crc_kInputValue[index++] = M_CAN_3.ILE.R;
        crc_kInputValue[index++] = M_CAN_3.GFC.R;
        crc_kInputValue[index++] = M_CAN_3.SIDFC.R;
        crc_kInputValue[index++] = M_CAN_3.XIDFC.R;

        crc_kInputValue[index++] = M_CAN_4.CCCR.R;
        crc_kInputValue[index++] = M_CAN_4.TOCC.R;
        crc_kInputValue[index++] = M_CAN_4.TDCR.R;
        crc_kInputValue[index++] = M_CAN_4.IE.R;
        crc_kInputValue[index++] = M_CAN_4.ILS.R;
        crc_kInputValue[index++] = M_CAN_4.ILE.R;
        crc_kInputValue[index++] = M_CAN_4.GFC.R;
        crc_kInputValue[index++] = M_CAN_4.SIDFC.R;
        crc_kInputValue[index++] = M_CAN_4.XIDFC.R;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_CanRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback LinFlex config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back LinFlex register success
*               FS_STATUS_ERROR: read back LinFlex register param error
****************************************************************************************
*/
#if(SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_LinflexRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i, j = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        for(i = 0; i < LINFELXD_MAX_INSTANCE; i++)
        {
            crc_kInputValue[index++] = s_pLinflexRegList[i]->LINCR1.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->LINIER.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->UARTCR.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->LINTOCR.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->LINFBRR.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->LINIBRR.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->LINCR2.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->IFER.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->IFMR.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->GCR.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->UARTPTO.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->DMATXE.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->DMARXE.R;
            crc_kInputValue[index++] = s_pLinflexRegList[i]->PTD.R;

            for(j = 0; j < LINFELXD_IFCR_COUNT; j++)
            {
                crc_kInputValue[index++] = s_pLinflexRegList[i]->IFCR[j].R;
            }
        }
        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_LinflexRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback STM config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back STM register success
*               FS_STATUS_ERROR: read back STM register param error
****************************************************************************************
*/
#if(SAF_CRC_StmRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_StmRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = STM_0.CR.R;
        crc_kInputValue[index++] = STM_1.CR.R;
        crc_kInputValue[index++] = STM_2.CR.R;

        for(i = 0; i < STM_CHANNEL_COUNT; i++)
        {
            crc_kInputValue[index++] = STM_0.CHANNEL[i].CCR.R;
            crc_kInputValue[index++] = STM_1.CHANNEL[i].CCR.R;
            crc_kInputValue[index++] = STM_2.CHANNEL[i].CCR.R;
        }
        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_StmRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback DSPI config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back DSPI register success
*               FS_STATUS_ERROR: read back DSPI register param error
****************************************************************************************
*/
#if(SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_DspiRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i, j = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        for(i = 0; i < DSPI_MAX_INSTANCE; i++)
        {
            crc_kInputValue[index++] = s_pDspiRegList[i]->MCR.R;
            crc_kInputValue[index++] = s_pDspiRegList[i]->RSER.R;
            crc_kInputValue[index++] = s_pDspiRegList[i]->DSICR0.R;
            crc_kInputValue[index++] = s_pDspiRegList[i]->DSICR1.R;
            crc_kInputValue[index++] = s_pDspiRegList[i]->DPIR0.R;
            crc_kInputValue[index++] = s_pDspiRegList[i]->MODE.CTAR_SLAVE[0].R;
            crc_kInputValue[index++] = s_pDspiRegList[i]->MODE.CTAR_SLAVE[1].R;
            for(j = 0; j < DSPI_CTAR_COUNT; j++)
            {
                crc_kInputValue[index++] = s_pDspiRegList[i]->MODE.CTAR[j].R;
            }
        }
        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_DspiRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback SSI config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back SSI register success
*               FS_STATUS_ERROR: read back SSI register param error
****************************************************************************************
*/
#if(SAF_CRC_SsiRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_SsiRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = SSI0.CTRLR0.R;
        crc_kInputValue[index++] = SSI0.CTRLR1.R;
        crc_kInputValue[index++] = SSI0.SSIENR.R;
        crc_kInputValue[index++] = SSI0.BAUDR.R;
        crc_kInputValue[index++] = SSI0.DMACR.R;
        crc_kInputValue[index++] = SSI0.SPICTRLR0.R;
        crc_kInputValue[index++] = SSI0.XIPMBR.R;
        crc_kInputValue[index++] = SSI0.XIPIIR.R;
        crc_kInputValue[index++] = SSI0.XIPCR.R;

        crc_kInputValue[index++] = SSI1.CTRLR0.R;
        crc_kInputValue[index++] = SSI1.CTRLR1.R;
        crc_kInputValue[index++] = SSI1.SSIENR.R;
        crc_kInputValue[index++] = SSI1.BAUDR.R;
        crc_kInputValue[index++] = SSI1.DMACR.R;
        crc_kInputValue[index++] = SSI1.SPICTRLR0.R;
        crc_kInputValue[index++] = SSI1.XIPMBR.R;
        crc_kInputValue[index++] = SSI1.XIPIIR.R;
        crc_kInputValue[index++] = SSI1.XIPCR.R;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_SsiRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback SENT config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back SENT register success
*               FS_STATUS_ERROR: read back SENT register param error
****************************************************************************************
*/
#if(SAF_CRC_SentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_SentRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = SRX_0.GBL_CTRL.R;
        crc_kInputValue[index++] = SRX_0.CHNL_EN.R;
        crc_kInputValue[index++] = SRX_0.DATA_CTRL1.R;
        crc_kInputValue[index++] = SRX_0.FDMA_CTRL.R;
        crc_kInputValue[index++] = SRX_0.SDMA_CTRL.R;
        crc_kInputValue[index++] = SRX_0.FRDY_IE.R;
        crc_kInputValue[index++] = SRX_0.SRDY_IE.R;

        crc_kInputValue[index++] = SRX_1.GBL_CTRL.R;
        crc_kInputValue[index++] = SRX_1.CHNL_EN.R;
        crc_kInputValue[index++] = SRX_1.DATA_CTRL1.R;
        crc_kInputValue[index++] = SRX_1.FDMA_CTRL.R;
        crc_kInputValue[index++] = SRX_1.SDMA_CTRL.R;
        crc_kInputValue[index++] = SRX_1.FRDY_IE.R;
        crc_kInputValue[index++] = SRX_1.SRDY_IE.R;

        for(i = 0; i < SENT_CH_COUNT; i++)
        {
            crc_kInputValue[index++] = SRX_0.CH[i].CLK_CTRL.R;
            crc_kInputValue[index++] = SRX_0.CH[i].CONFIG.R;

            crc_kInputValue[index++] = SRX_1.CH[i].CLK_CTRL.R;
            crc_kInputValue[index++] = SRX_1.CH[i].CONFIG.R;
        }

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_SentRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback CSENT config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back CSENT register success
*               FS_STATUS_ERROR: read back CSENT register param error
****************************************************************************************
*/
#if(SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_CsentRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        for(i = 0; i < CSENT_MAX_INSTANCE; i++)/*PRQA S 2877*/
        {
            crc_kInputValue[index++] = s_pCsentRegList[i]->TCFG.R;
            crc_kInputValue[index++] = s_pCsentRegList[i]->TTFT.R;
            crc_kInputValue[index++] = s_pCsentRegList[i]->TSTG.R;
            crc_kInputValue[index++] = s_pCsentRegList[i]->RCFG.R;
            crc_kInputValue[index++] = s_pCsentRegList[i]->RSYNC.R;
        }

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_CsentRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback FlexRay config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back FlexRay register success
*               FS_STATUS_ERROR: read back FlexRay register param error
****************************************************************************************
*/
#if(SAF_CRC_FlexrayRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_FlexrayRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = FR_0.MCR.R;
        crc_kInputValue[index++] = FR_0.SYMBADHR.R;
        crc_kInputValue[index++] = FR_0.SYMBADLR.R;
        crc_kInputValue[index++] = FR_0.MBDSR.R;
        crc_kInputValue[index++] = FR_0.MBSSUTR.R;
        crc_kInputValue[index++] = FR_0.POCR.R;
        crc_kInputValue[index++] = FR_0.PIER0.R;
        crc_kInputValue[index++] = FR_0.PIER1.R;
        crc_kInputValue[index++] = FR_0.SFTOR.R;
        crc_kInputValue[index++] = FR_0.TICCR.R;
        crc_kInputValue[index++] = FR_0.NMVLR.R;
        crc_kInputValue[index++] = FR_0.PCR0.R;
        crc_kInputValue[index++] = FR_0.PCR1.R;
        crc_kInputValue[index++] = FR_0.PCR2.R;
        crc_kInputValue[index++] = FR_0.PCR3.R;
        crc_kInputValue[index++] = FR_0.PCR4.R;
        crc_kInputValue[index++] = FR_0.PCR5.R;
        crc_kInputValue[index++] = FR_0.PCR6.R;
        crc_kInputValue[index++] = FR_0.PCR7.R;
        crc_kInputValue[index++] = FR_0.PCR8.R;
        crc_kInputValue[index++] = FR_0.PCR9.R;
        crc_kInputValue[index++] = FR_0.PCR10.R;
        crc_kInputValue[index++] = FR_0.PCR11.R;
        crc_kInputValue[index++] = FR_0.PCR12.R;
        crc_kInputValue[index++] = FR_0.PCR13.R;
        crc_kInputValue[index++] = FR_0.PCR14.R;
        crc_kInputValue[index++] = FR_0.PCR15.R;
        crc_kInputValue[index++] = FR_0.PCR16.R;
        crc_kInputValue[index++] = FR_0.PCR17.R;
        crc_kInputValue[index++] = FR_0.PCR18.R;
        crc_kInputValue[index++] = FR_0.PCR19.R;
        crc_kInputValue[index++] = FR_0.PCR20.R;
        crc_kInputValue[index++] = FR_0.PCR21.R;
        crc_kInputValue[index++] = FR_0.PCR22.R;
        crc_kInputValue[index++] = FR_0.PCR23.R;
        crc_kInputValue[index++] = FR_0.PCR24.R;
        crc_kInputValue[index++] = FR_0.PCR25.R;
        crc_kInputValue[index++] = FR_0.PCR26.R;
        crc_kInputValue[index++] = FR_0.PCR27.R;
        crc_kInputValue[index++] = FR_0.PCR28.R;
        crc_kInputValue[index++] = FR_0.PCR29.R;
        crc_kInputValue[index++] = FR_0.PCR30.R;
        crc_kInputValue[index++] = FR_0.PEOER.R;

        crc_kInputValue[index++] = FR_1.MCR.R;
        crc_kInputValue[index++] = FR_1.SYMBADHR.R;
        crc_kInputValue[index++] = FR_1.SYMBADLR.R;
        crc_kInputValue[index++] = FR_1.MBDSR.R;
        crc_kInputValue[index++] = FR_1.MBSSUTR.R;
        crc_kInputValue[index++] = FR_1.POCR.R;
        crc_kInputValue[index++] = FR_1.PIER0.R;
        crc_kInputValue[index++] = FR_1.PIER1.R;
        crc_kInputValue[index++] = FR_1.SFTOR.R;
        crc_kInputValue[index++] = FR_1.TICCR.R;
        crc_kInputValue[index++] = FR_1.NMVLR.R;
        crc_kInputValue[index++] = FR_1.PCR0.R;
        crc_kInputValue[index++] = FR_1.PCR1.R;
        crc_kInputValue[index++] = FR_1.PCR2.R;
        crc_kInputValue[index++] = FR_1.PCR3.R;
        crc_kInputValue[index++] = FR_1.PCR4.R;
        crc_kInputValue[index++] = FR_1.PCR5.R;
        crc_kInputValue[index++] = FR_1.PCR6.R;
        crc_kInputValue[index++] = FR_1.PCR7.R;
        crc_kInputValue[index++] = FR_1.PCR8.R;
        crc_kInputValue[index++] = FR_1.PCR9.R;
        crc_kInputValue[index++] = FR_1.PCR10.R;
        crc_kInputValue[index++] = FR_1.PCR11.R;
        crc_kInputValue[index++] = FR_1.PCR12.R;
        crc_kInputValue[index++] = FR_1.PCR13.R;
        crc_kInputValue[index++] = FR_1.PCR14.R;
        crc_kInputValue[index++] = FR_1.PCR15.R;
        crc_kInputValue[index++] = FR_1.PCR16.R;
        crc_kInputValue[index++] = FR_1.PCR17.R;
        crc_kInputValue[index++] = FR_1.PCR18.R;
        crc_kInputValue[index++] = FR_1.PCR19.R;
        crc_kInputValue[index++] = FR_1.PCR20.R;
        crc_kInputValue[index++] = FR_1.PCR21.R;
        crc_kInputValue[index++] = FR_1.PCR22.R;
        crc_kInputValue[index++] = FR_1.PCR23.R;
        crc_kInputValue[index++] = FR_1.PCR24.R;
        crc_kInputValue[index++] = FR_1.PCR25.R;
        crc_kInputValue[index++] = FR_1.PCR26.R;
        crc_kInputValue[index++] = FR_1.PCR27.R;
        crc_kInputValue[index++] = FR_1.PCR28.R;
        crc_kInputValue[index++] = FR_1.PCR29.R;
        crc_kInputValue[index++] = FR_1.PCR30.R;
        crc_kInputValue[index++] = FR_1.PEOER.R;

        for(i = 0; i < FR_MBCCFR_COUNT; i++)
        {
            crc_kInputValue[index++] = FR_0.MB[i].CCFR.R;

            crc_kInputValue[index++] = FR_1.MB[i].CCFR.R;
        }

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_FlexrayRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback I2C config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back I2C register success
*               FS_STATUS_ERROR: read back I2C register param error
****************************************************************************************
*/
#if(SAF_CRC_I2cRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_I2cRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = I2C_0.IBAD.R;
        crc_kInputValue[index++] = I2C_0.IBFD.R;
        crc_kInputValue[index++] = I2C_0.IBCR.R;
        crc_kInputValue[index++] = I2C_0.IBIC.R;

        crc_kInputValue[index++] = I2C_1.IBAD.R;
        crc_kInputValue[index++] = I2C_1.IBFD.R;
        crc_kInputValue[index++] = I2C_1.IBCR.R;
        crc_kInputValue[index++] = I2C_1.IBIC.R;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_I2cRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback EMAC config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back EMAC register success
*               FS_STATUS_ERROR: read back EMAC register param error
****************************************************************************************
*/
#if(SAF_CRC_EmacRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_EmacRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
#if !defined(CCFC3012PT)
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = ETHERNET_0.MAC_CONFIGURATION.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_EXT_CONFIGURATION.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_PACKET_FILTER.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_WATCHDOG_TIMEOUT.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_VLAN_TAG_CTRL.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_INTERRUPT_ENABLE.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_LPI_TIMERS_CONTROL.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_CSR_SW_CTRL.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_EXT_CFG1.R;
        crc_kInputValue[index++] = ETHERNET_0.MMC_CONTROL.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_AUXILIARY_CONTROL.R;
        crc_kInputValue[index++] = ETHERNET_0.MAC_PPS_CONTROL.R;
        crc_kInputValue[index++] = ETHERNET_0.DMA_MODE.R;
        crc_kInputValue[index++] = ETHERNET_0.DMA_SYSBUS_MODE.R;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }
#else
    (void)ParamSetIndex;
#endif
    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_EmacRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback PSI5 config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back PSI5 register success
*               FS_STATUS_ERROR: read back PSI5 register param error
****************************************************************************************
*/
#if(SAF_CRC_Psi5RegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_Psi5RegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = PSI5_0.GCR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_PCCR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_DCR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_GICR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_NDICR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_OWICR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_EICR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_S1SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_S2SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_S3SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_S4SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_S5SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_S6SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_SnEBR.R;
        crc_kInputValue[index++] = PSI5_0.CH0_PCCR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_DCR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_GICR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_NDICR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_OWICR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_EICR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_S1SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_S2SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_S3SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_S4SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_S5SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_S6SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH1_SnEBR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_PCCR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_DCR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_GICR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_NDICR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_OWICR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_EICR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_S1SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_S2SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_S3SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_S4SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_S5SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_S6SBR.R;
        crc_kInputValue[index++] = PSI5_0.CH2_SnEBR.R;
        #if !defined(CCFC3012PT)
        crc_kInputValue[index++] = PSI5_1.GCR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_PCCR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_DCR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_GICR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_NDICR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_OWICR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_EICR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_S1SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_S2SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_S3SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_S4SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_S5SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_S6SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_SnEBR.R;
        crc_kInputValue[index++] = PSI5_1.CH0_PCCR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_DCR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_GICR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_NDICR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_OWICR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_EICR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_S1SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_S2SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_S3SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_S4SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_S5SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_S6SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH1_SnEBR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_PCCR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_DCR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_GICR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_NDICR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_OWICR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_EICR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_S1SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_S2SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_S3SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_S4SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_S5SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_S6SBR.R;
        crc_kInputValue[index++] = PSI5_1.CH2_SnEBR.R;
        #endif
        for(i = 0; i < PSI5_SFCR_COUNT; i++)
        {
            crc_kInputValue[index++] = PSI5_0.CH0_SFCR[i].R;
            crc_kInputValue[index++] = PSI5_0.CH1_SFCR[i].R;
            crc_kInputValue[index++] = PSI5_0.CH2_SFCR[i].R;
            #if !defined(CCFC3012PT)
            crc_kInputValue[index++] = PSI5_1.CH0_SFCR[i].R;
            crc_kInputValue[index++] = PSI5_1.CH1_SFCR[i].R;
            crc_kInputValue[index++] = PSI5_1.CH2_SFCR[i].R;
            #endif
        }

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_Psi5RegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback I2S config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back I2S register success
*               FS_STATUS_ERROR: read back I2S register param error
****************************************************************************************
*/
#if(SAF_CRC_I2sRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_I2sRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = I2S_1.CR.R;
        crc_kInputValue[index++] = I2S_1.CDR.R;
        crc_kInputValue[index++] = I2S_1.DMACR.R;

        crc_kInputValue[index++] = I2S_2.CR.R;
        crc_kInputValue[index++] = I2S_2.CDR.R;
        crc_kInputValue[index++] = I2S_2.DMACR.R;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_I2sRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback I2SSLV config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back I2SSLV register success
*               FS_STATUS_ERROR: read back I2SSLV register param error
****************************************************************************************
*/
#if(SAF_CRC_I2sslvRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_I2sslvRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = I2S_1_SLV.IER.R;

        crc_kInputValue[index++] = I2S_2_SLV.IER.R;

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_I2sslvRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback SMPU config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back SMPU register success
*               FS_STATUS_ERROR: read back SMPU register param error
****************************************************************************************
*/
#if(SAF_CRC_SmpuRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_SmpuRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        for(i = 0; i < SMPU_RGD_COUNT; i++)
        {
            crc_kInputValue[index++] = SMPU_0.RGD[i].WORD0.R;
            crc_kInputValue[index++] = SMPU_0.RGD[i].WORD1.R;
            crc_kInputValue[index++] = SMPU_0.RGD[i].WORD2.R;
            crc_kInputValue[index++] = SMPU_0.RGD[i].WORD3.R;
#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
            if (8U <= i)
            {
            	continue;
            }
#endif
            crc_kInputValue[index++] = SMPU_1.RGD[i].WORD0.R;
            crc_kInputValue[index++] = SMPU_1.RGD[i].WORD1.R;
            crc_kInputValue[index++] = SMPU_1.RGD[i].WORD2.R;
            crc_kInputValue[index++] = SMPU_1.RGD[i].WORD3.R;
        }

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_SmpuRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback MC_ME config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back MC_ME register success
*               FS_STATUS_ERROR: read back MC_ME register param error
****************************************************************************************
*/
#if(SAF_CRC_McmeRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_McmeRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;
    uint16_t i = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = MC_ME.MCTL.R;
        crc_kInputValue[index++] = MC_ME.ME.R;
        crc_kInputValue[index++] = MC_ME.RESET_MC.R;
        crc_kInputValue[index++] = MC_ME.TEST_MC.R;
        crc_kInputValue[index++] = MC_ME.SAFE_MC.R;
        crc_kInputValue[index++] = MC_ME.DRUN_MC.R;
        crc_kInputValue[index++] = MC_ME.HALT0_MC.R;
        crc_kInputValue[index++] = MC_ME.STOP0_MC.R;
        crc_kInputValue[index++] = MC_ME.STANDBY_MC.R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL3].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL9].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL11].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL15].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL30].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL31].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL36].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL38].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL56].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL57].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL58].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL59].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL60].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL67].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL68].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL69].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL70].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL72].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL74].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL84].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL85].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL91].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL92].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL93].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL96].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL97].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL98].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL99].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL101].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL104].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL107].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL111].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL112].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL123].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL127].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL128].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL162].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL166].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL184].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL185].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL186].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL187].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL188].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL213].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL220].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL225].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL226].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL227].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL229].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL232].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL235].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL239].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL245].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL246].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL247].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL248].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL249].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL250].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL252].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL253].R;
        crc_kInputValue[index++] = MC_ME.PCTL[MCME_PCTL254].R;
        crc_kInputValue[index++] = MC_ME.CCTL0.R;
        crc_kInputValue[index++] = MC_ME.CCTL1.R;
        crc_kInputValue[index++] = MC_ME.CCTL2.R;
        crc_kInputValue[index++] = MC_ME.CCTL3.R;
        crc_kInputValue[index++] = MC_ME.CCTL4.R;

        for(i = 0; i < MCME_RUN_COUNT; i++)
        {
            crc_kInputValue[index++] = MC_ME.RUN_MC[i].R;
        }

        for(i = 0; i < MCME_PC_COUNT; i++)
        {
            crc_kInputValue[index++] = MC_ME.RUN_PC[i].R;
            crc_kInputValue[index++] = MC_ME.LP_PC[i].R;
        }

        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_McmeRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to readback MCCGM config register.
* @param[in]    ParamSetIndex:       test index.
* @return       RegReadbackResult
*               FS_STATUS_SUCCESS: read back MCCGM register success
*               FS_STATUS_ERROR: read back MCCGM register param error
****************************************************************************************
*/
#if(SAF_CRC_MccgmRegReadback_SWITCH == SAF_CRC_SWITCH_ON)
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_MccgmRegReadbackCheck(const uint8_t ParamSetIndex)
{
    FS_STATUS RegReadbackResult = FS_STATUS_SUCCESS;
    uint16_t index = 0U;

    if(CRC_TOTAL_READBACK_TESTS > ParamSetIndex)
    {
        crc_kInputValue[index++] = MC_CGM.AC5_CDC0.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC1.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC2.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC10.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC11.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC12.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC13.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC20.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC21.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC22.R;
        crc_kInputValue[index++] = MC_CGM.AC5_CDC23.R;
        crc_kInputValue[index++] = MC_CGM.SC_DC0.R;
        crc_kInputValue[index++] = MC_CGM.SC_DC1.R;
        crc_kInputValue[index++] = MC_CGM.SC_DC2.R;
        crc_kInputValue[index++] = MC_CGM.SC_DC3.R;
        crc_kInputValue[index++] = MC_CGM.SC_DC4.R;
        crc_kInputValue[index++] = MC_CGM.AC0_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC0_DC1.R;
        crc_kInputValue[index++] = MC_CGM.AC0_DC2.R;
        crc_kInputValue[index++] = MC_CGM.AC0_DC3.R;
        crc_kInputValue[index++] = MC_CGM.AC0_DC4.R;
        crc_kInputValue[index++] = MC_CGM.AC2_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC2_DC1.R;
        crc_kInputValue[index++] = MC_CGM.AC3_SC.R;
        crc_kInputValue[index++] = MC_CGM.AC4_SC.R;
        crc_kInputValue[index++] = MC_CGM.AC5_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC5_DC1.R;
        crc_kInputValue[index++] = MC_CGM.AC5_DC2.R;
        crc_kInputValue[index++] = MC_CGM.AC6_SC.R;
        crc_kInputValue[index++] = MC_CGM.AC6_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC7_SC.R;
        crc_kInputValue[index++] = MC_CGM.AC7_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC8_SC.R;
        crc_kInputValue[index++] = MC_CGM.AC8_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC9_SC.R;
        crc_kInputValue[index++] = MC_CGM.AC9_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC10_SC.R;
        crc_kInputValue[index++] = MC_CGM.AC10_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC11_SC.R;
        crc_kInputValue[index++] = MC_CGM.AC11_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC12_SC.R;
        crc_kInputValue[index++] = MC_CGM.AC12_DC0.R;
        crc_kInputValue[index++] = MC_CGM.AC12_DC1.R;
        crc_kInputValue[index++] = MC_CGM.AC12_DC2.R;


        Crc_kReadTestRst[ParamSetIndex].crcCalculatedResult = SAF_CRC_AccessGetCrcOutput(index, ParamSetIndex);
    }
    else
    {
        RegReadbackResult = FS_STATUS_ERROR;
    }

    return RegReadbackResult;
}
#endif /* #if(SAF_CRC_MccgmRegReadback_SWITCH == SAF_CRC_SWITCH_ON) */
/**
****************************************************************************************
* @brief:  		This function is used to get the crc read back test results.
* @param[in]    pTestResult         test parameters.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get results success
*               FS_STATUS_ERROR       get results failed
****************************************************************************************
*/
SAF_CRC_SEC_CODE
FS_STATUS SAF_CRC_GetReadbackResult(saf_crc_readback_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        (void)memcpy(pTestResult, Crc_kReadTestRst, sizeof(Crc_kReadTestRst));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_SM051] This function is used to get the crc self test result.
* @param[out]   pTestResult:        test parameters.
* @return       status
*               FS_STATUS_SUCCESS:    get results success
*               FS_STATUS_ERROR:      get results failed
****************************************************************************************
*/
FS_STATUS SAF_CRC_GetSelfTestResult(saf_crc_self_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        (void)memcpy(pTestResult, Crc_kSelfTestRst, sizeof(Crc_kSelfTestRst));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}


