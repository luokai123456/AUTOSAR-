/**
****************************************************************************************
 * @FilePath: saf_userservice_callback.c
 * @Author: CCORE
 * @Date: 2024-03-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety User Service call back C File
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
#include "saf_flash.h"/*PRQA S 0380*/
#include "saf_cmu.h"
#include "saf_userservice_callback.h"
#include "saf_fccu.h"
#include "fccu_lld.h"
#include "mcu_lld.h"
#include "Saf_MemMap.h"
/*PRQA S 1860,1862,3119,3408,3200,4304,4424,4434 EOF*/
/**
****************************************************************************************
 * @brief: Variables
****************************************************************************************
*/
SAF_SEC_VAR_INIT
uint8_t Irq_notifyFlag = 0;

/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/

/**
****************************************************************************************
* @brief:  This call back function is used in flash ECC error report test.
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_FlashEccCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

SAF_SEC_CODE
void SAF_UserService_OSCCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

SAF_SEC_CODE
void SAF_UserService_PmcSelfCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

SAF_SEC_CODE
void SAF_UserService_PLLSysClkCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

SAF_SEC_CODE
void SAF_UserService_PLLMcanClkCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

SAF_SEC_CODE
void SAF_UserService_CrcCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

/**
****************************************************************************************
* @brief:  This call back function is used in Stm Timer Monitor test.
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_StmTimerMonitorCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

/**
****************************************************************************************
* @brief:  This call back function is used in Pit Timer Monitor test.
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_PitTimerMonitorcCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

/**
****************************************************************************************
* @brief:  This call back function is used in Tsens Chip Temp test.
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_TsensChipTempCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

/**
****************************************************************************************
* @brief:  This call back function is used in Fccu 31 Cmu alarm callback.
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_Fccu31CmuDisableCallback(void *param)
{
	(void)param;
    SAF_CMU_LLD_CleanStatusRegister(CMU_0);
}
/**
****************************************************************************************
* @brief:  This call back function is used in Fccu 31 Cmu alarm callback test(just enter alarm onetime) .
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_Fccu31CmuDisableCallback_test(void *param)
{
	(void)param;
    SAF_CMU_LLD_SetLowFreq(CMU_0, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_0, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_0,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_0);
    SAF_FCCU_LLD_ClearFaults(SAF_FCCU_FAILURE_CMU_0_OSC_CH_31);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_0);
}

/**
****************************************************************************************
* @brief:  This call back function is used in Fccu 32 Cmu alarm callback .
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_Fccu32CmuDisableCallback(void *param)
{
	(void)param;
    SAF_CMU_LLD_CleanStatusRegister(CMU_0);
}
/**
****************************************************************************************
* @brief:  This call back function is used in Fccu 32 Cmu alarm callback test(just enter alarm onetime) .
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_Fccu32CmuDisableCallback_test(void *param)
{
	(void)param;
    SAF_CMU_LLD_SetLowFreq(CMU_0, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_0, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_0,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_0);
    SAF_FCCU_LLD_ClearFaults(SAF_FCCU_FAILURE_CMU_0_PLL_CH_32);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_0);
}

/**
****************************************************************************************
* @brief:  This call back function is used in Fccu 33 Cmu alarm callback .
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_Fccu33CmuDisableCallback(void *param)
{
	(void)param;
    SAF_CMU_LLD_CleanStatusRegister(CMU_1);

    SAF_CMU_LLD_CleanStatusRegister(CMU_2);

    SAF_CMU_LLD_CleanStatusRegister(CMU_3);

    SAF_CMU_LLD_CleanStatusRegister(CMU_11);

}

/**
****************************************************************************************
* @brief:  This call back function is used in Fccu 33 Cmu alarm callback test(just enter alarm onetime) .
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_Fccu33CmuDisableCallback_test(void *param)
{
	(void)param;
    SAF_CMU_LLD_SetLowFreq(CMU_1, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_1, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_1,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_1);
    SAF_FCCU_LLD_ClearFaults(SAF_FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_1);

    SAF_CMU_LLD_SetLowFreq(CMU_2, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_2, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_2,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_2);
    SAF_FCCU_LLD_ClearFaults(SAF_FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_2);

    SAF_CMU_LLD_SetLowFreq(CMU_3, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_3, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_3,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_3);
    SAF_FCCU_LLD_ClearFaults(SAF_FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_3);

    SAF_CMU_LLD_SetLowFreq(CMU_11, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_11, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_11,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_11);
    SAF_FCCU_LLD_ClearFaults(SAF_FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_11);
}

/**
****************************************************************************************
* @brief:  This call back function is used in Fccu 34 Cmu alarm callback .
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_Fccu34CmuDisableCallback(void *param)
{
	(void)param;
    SAF_CMU_LLD_CleanStatusRegister(CMU_4);

    SAF_CMU_LLD_CleanStatusRegister(CMU_5);

    SAF_CMU_LLD_CleanStatusRegister(CMU_6);

    SAF_CMU_LLD_CleanStatusRegister(CMU_7);

    SAF_CMU_LLD_CleanStatusRegister(CMU_8);

    SAF_CMU_LLD_CleanStatusRegister(CMU_9);

    SAF_CMU_LLD_CleanStatusRegister(CMU_10);

    SAF_CMU_LLD_CleanStatusRegister(CMU_12);
}
/**
****************************************************************************************
* @brief:  This call back function is used in Fccu 34 Cmu alarm callback test(just enter alarm onetime) .
* @param[in]   param       input parameter point.
* @return  void
****************************************************************************************
*/
SAF_SEC_CODE
void SAF_UserService_Fccu34CmuDisableCallback_Injecttest(void *param)
{
	(void)param;
	SAF_CMU_LLD_SetLowFreq(CMU_4, 0x00);
	SAF_CMU_LLD_SetHighFreq(CMU_4, 0xfff);
	SAF_CMU_LLD_EnableCMU(CMU_4,(bool)true);
    SAF_CMU_GetAndCleanIrqStatus(4);
    SAF_FCCU_LLD_ClearFaults(SAF_FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_4);

    SAF_CMU_LLD_SetLowFreq(CMU_5, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_5, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_5,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_5);
    SAF_FCCU_LLD_ClearFaults(5);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_5);

    SAF_CMU_LLD_SetLowFreq(CMU_6, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_6, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_6,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_6);
    SAF_FCCU_LLD_ClearFaults(6);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_6);

    SAF_CMU_LLD_SetLowFreq(CMU_7, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_7, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_7,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_7);
    SAF_FCCU_LLD_ClearFaults(7);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_7);

    SAF_CMU_LLD_SetLowFreq(CMU_8, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_8, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_8,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_8);
    SAF_FCCU_LLD_ClearFaults(8);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_8);

    SAF_CMU_LLD_SetLowFreq(CMU_9, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_9, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_9,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_9);
    SAF_FCCU_LLD_ClearFaults(9);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_9);

    SAF_CMU_LLD_SetLowFreq(CMU_10, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_10, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_10,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_10);
    SAF_FCCU_LLD_ClearFaults(10);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_10);

    SAF_CMU_LLD_SetLowFreq(CMU_12, 0x00);
    SAF_CMU_LLD_SetHighFreq(CMU_12, 0xfff);
    SAF_CMU_LLD_EnableCMU(CMU_12,(bool)true);
    SAF_CMU_LLD_CleanStatusRegister(CMU_12);
    SAF_FCCU_LLD_ClearFaults(12);
    SAF_FCCU_LLD_ClearIntFlag(SAF_FCCU_INT_ALARM);
    SAF_CMU_LLD_CleanStatusRegister(CMU_12);
}

SAF_SEC_CODE
void SAF_UserService_CmuConfigcheckCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}

SAF_SEC_CODE
void SAF_UserService_CmuMonitorTestFreqOverHighCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}
SAF_SEC_CODE
void SAF_UserService_CmuMonitorTestFreqOverLowCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}
SAF_SEC_CODE
void SAF_UserService_CmuMonitorTestOscFreqOverLowCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}
SAF_SEC_CODE
void SAF_UserService_CmuUserServiceTestCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}
SAF_SEC_CODE
void SAF_UserService_AdcCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}
SAF_SEC_CODE
void SAF_UserService_IntcCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}
SAF_SEC_CODE
void SAF_UserService_DmaCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}
SAF_SEC_CODE
void SAF_UserService_SwtMonitorTimerCallBack(void *param)
{
	(void)param;
	Irq_notifyFlag += 1;
	if(Irq_notifyFlag > 100)
	{
		Irq_notifyFlag = 0;
	}
    return;
}
SAF_SEC_CODE
void Saf_RamCEInject_Callback(void *param)
{
	(void)param;

	(void)MEMU_LLD_Reset();
}
SAF_SEC_CODE
void Saf_FlashCEInject_Callback(void *param)
{
	(void)param;

	(void)MEMU_LLD_Reset();

}

#ifdef __cplusplus
}
#endif





