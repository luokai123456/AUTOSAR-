/**
****************************************************************************************
 * @FilePath: saf_userservice_runtime.c
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety User Service Runtime C File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_userservice_runtime.h"/*PRQA S 0380*/
#include "saf_crc.h"
#include "saf_osc.h"/*PRQA S 0380*/
#include "saf_pll.h"
#include "saf_stm.h"
#include "saf_pit.h"
#include "saf_tsens.h"
#include "saf_intc.h"
#include "saf_dma.h"
#include "saf_swt.h"
#include "Saf_MemMap.h"
#include "ErrorDiag_Swc.h"
#include "ErrorHandler_Swc.h"
/**
****************************************************************************************
 * @brief: Global Variables
****************************************************************************************
*/
extern const call_config_t s_crcSelfTestCallSet;
extern const call_config_t s_StmTimerMonitorCallSet;
extern const call_config_t s_PitTimerMonitorCallSet;
extern const call_config_t s_TsensChipTempErrorRangeCallSet;
extern const call_config_t s_IrqMonitorCallSet;
extern const call_config_t s_DmaMonitorCallSet;
/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/
/**
****************************************************************************************
* @brief:  The service run the crc test.
* @return  FS_STATUS
*          FS_STATUS_SUCCESS     Crc test succeed
*          FS_STATUS_ERROR       Crc test failed
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_CrcTest(void)
{
    uint8_t index;
    FS_STATUS Result = FS_STATUS_SUCCESS;

	#if 0
    for(index = 0; index < CRC_TOTAL_READBACK_TESTS; index++)
    {
        if(FS_STATUS_SUCCESS != SAF_CRC_RegisterReadbackTest(index))
        {
            Result = FS_STATUS_ERROR;
            if (NULL != s_crcReadTestCallSet.callback)
            {
                s_crcReadTestCallSet.callback(s_crcReadTestCallSet.callbackParam);
            }
            /*APP error handle*/
			ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_CRC_RegisterReadbackTest,E_NOT_OK);
        }
        else
		{
		    ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_CRC_RegisterReadbackTest,E_OK);
		}
    }
	#endif
    return Result;
}

/**
****************************************************************************************
* @brief:  The service run the stm test.
* @return  FS_STATUS
*          FS_STATUS_SUCCESS     Stm test succeed
*          FS_STATUS_ERROR       Stm test failed
****************************************************************************************
*/
SAF_SEC_CODE
FS_STATUS SAF_UserService_StmMonitorTest(void)
{
	FS_STATUS result = FS_STATUS_SUCCESS;

	if(FS_STATUS_SUCCESS != SAF_STM_TimerMonitorTest())
	{
		if (s_StmTimerMonitorCallSet.callback != NULL)
		{
			s_StmTimerMonitorCallSet.callback(s_StmTimerMonitorCallSet.callbackParam);
		}

		result = FS_STATUS_ERROR;
		/*APP error handle*/
		ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_STM_TimerMonitorTest,E_NOT_OK);
	}
	else
	{
        ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_STM_TimerMonitorTest,E_OK);
	}

	return result;
}
/**
 ****************************************************************************************
 * @brief:  The service run the pit test.
 * @return  FS_STATUS
 *          FS_STATUS_SUCCESS     Pit test succeed
 *          FS_STATUS_ERROR       Pit test failed
 ****************************************************************************************
 */
SAF_SEC_CODE
FS_STATUS SAF_UserService_PitMonitorTest(void)
{
	FS_STATUS result = FS_STATUS_SUCCESS;

	if(FS_STATUS_SUCCESS != SAF_PIT_TimerMonitorTest())
	{
		if (s_PitTimerMonitorCallSet.callback != NULL)
		{
			s_PitTimerMonitorCallSet.callback(s_PitTimerMonitorCallSet.callbackParam);
		}

		result = FS_STATUS_ERROR;
		/*APP error handle*/
		ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_PIT_TimerMonitorTest,E_NOT_OK);
	}
	else
	{
        ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_PIT_TimerMonitorTest,E_OK);
	}

	return result;
}

/**
 ****************************************************************************************
 * @brief:  The service run the tsens test.
 * @return  FS_STATUS
 *          FS_STATUS_SUCCESS     Tsens test succeed
 *          FS_STATUS_ERROR       Tsens test failed
 ****************************************************************************************
 */
SAF_SEC_CODE
FS_STATUS SAF_UserService_TsensChipTempTest(void)
{
	FS_STATUS result = FS_STATUS_SUCCESS;

#if 0
	if(FS_STATUS_SUCCESS != SAF_TSENS_ChipTempErrRangeTest())
	{
		if (s_TsensChipTempErrorRangeCallSet.callback != NULL)
		{
			s_TsensChipTempErrorRangeCallSet.callback(s_TsensChipTempErrorRangeCallSet.callbackParam);
		}

		result = FS_STATUS_ERROR;
		/*APP error handle*/
	}
	else
	{
		
	}
#endif
	return result;
}



/**
 ****************************************************************************************
 * @brief:  The service run the intc test.
 * @return  FS_STATUS
 *          FS_STATUS_SUCCESS     Intc test succeed
 *          FS_STATUS_ERROR       Intc test failed
 ****************************************************************************************
 */
SAF_SEC_CODE
FS_STATUS SAF_UserService_IntcTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;

    SAF_INTC_CheckMissingInterrupt();/*PRQA S 3200*/
    if (FS_STATUS_SUCCESS != SAF_INTC_IrqMonitorTest())
    {
		if (s_IrqMonitorCallSet.callback != NULL)
		{
			s_IrqMonitorCallSet.callback(s_IrqMonitorCallSet.callbackParam);
		}

        result = FS_STATUS_ERROR;
		/*APP error handle*/
		ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_INTC_IrqMonitorTest,E_NOT_OK);
    }
	else
	{
       ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_INTC_IrqMonitorTest,E_OK);
	}
   
    return result;
}

/**
 ****************************************************************************************
 * @brief:  The service run the dma test.
 * @return  FS_STATUS
 *          FS_STATUS_SUCCESS     Dma test succeed
 *          FS_STATUS_ERROR       Dma test failed
 ****************************************************************************************
 */
SAF_SEC_CODE
FS_STATUS SAF_UserService_DmaTest(void)
{
    FS_STATUS result = FS_STATUS_SUCCESS;

    if (FS_STATUS_SUCCESS != SAF_DMA_MonitorTest())
    {
		if (s_DmaMonitorCallSet.callback != NULL)
		{
			s_DmaMonitorCallSet.callback(s_DmaMonitorCallSet.callbackParam);
		}

        result = FS_STATUS_ERROR;
		/*APP error handle*/
		ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_DMA_MonitorTest,E_NOT_OK);
    }
	else
	{
       ErrorDiag_Send_ErrorStatus(ERRORID_MCU_Runtime_DMA_MonitorTest,E_OK);
	}   
    return result;
}

