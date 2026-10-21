/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3007PT
* DESCRIPTION : CCFC3007PT memu low level drivers code
* HISTORY     : Initial version
* @file     memu_lld.c
* @version  1.0
* @date     2023 - 09 - 11
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/

/*PRQA S 1503,3206,1505,2842,2844,3119 EOF*/
#include "memu_lld.h"/*PRQA S 0380*/
#include "Saf_MemMap.h"

extern uint32_t sramitcmTestFlag;

SAF_MEMU_SEC_CONFIG_DATA
static MEMU_tag_Type* const g_MEMU_Base = MEMU_BASE_ARRAY;

SAF_MEMU_SEC_VAR_NO_INIT
static MEMUCallbackType memu_prram_callback[5];

SAF_MEMU_SEC_VAR_NO_INIT
static MEMUCallbackType memu_flash_callback[5];

SAF_MEMU_SEC_VAR_NO_INIT
static MEMUCallbackType memu_sysram_callback[5];

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_SendFlagtoFCCU(memu_error_flag_t error, boolean enable)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    if(enable == TRUE)
    {
     	base->DEBUG.R |= (uint32_t)error;    /* polyspace RTE:NIV */
    }
    else
    {
        base->DEBUG.R &= ~((uint32_t)error); /* polyspace RTE:NIV */
    }

    return STATUS_SUCCESS;
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_ClearErrorFlag(memu_error_flag_t error)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    base->ERR_FLAG.R |= (uint32_t)error;  /* polyspace RTE:NIV */

    return STATUS_SUCCESS;
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_ClearAllErrorFlag(void)
{
	MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    base->ERR_FLAG.R = 0xFFFFFFFFU;

	return STATUS_SUCCESS;
}

SAF_MEMU_SEC_CODE
uint32_t MEMU_LLD_GetErrorFlag(memu_error_flag_t error)
{
    MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

    uint8_t flag;

    uint8_t length = 0;

    uint8_t i = 0;

    uint32_t errorValue;

    uint32_t tempValue;

    errorValue = (uint32_t)error;

    tempValue = (uint32_t)error;

    for(i = 0U; i < 32U; i++)
    {
        if(tempValue == 1U)
        {
            break;
        }
        else
        {
            tempValue = tempValue >> 1U;
            length++;
        }
    }

    if(length < 32U)
    {
    	errorValue = errorValue & (base->ERR_FLAG.R);  /* polyspace RTE:NIV */
        flag = (uint8_t)(errorValue >> length);
    }
    else
    {
    	flag = 0U;
    }

    return flag;
}

SAF_MEMU_SEC_CODE
uint32_t MEMU_LLD_GetAllErrorFlag(void)
{
    MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

    return base->ERR_FLAG.R;  /* polyspace RTE:NIV */
}

SAF_MEMU_SEC_CODE
uint32_t MEMU_LLD_GetSpecificErrorFlag(memu_detect_type_t error)
{
	MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

	uint32_t flag;

	flag = base->ERR_FLAG.R;/* polyspace RTE:NIV */

	if(error == MEMU_PERIPHERAL_RAM_DETECT)
	{
		flag = (flag & 0x00FF0000U) >> 16U;
	}
	else if(error == MEMU_FLASH_DETECT)
	{
		flag = (flag & 0x0000FF00U) >> 8U;
	}
	else if(error == MEMU_SYSTEM_RAM_DETECT)
	{
		flag = flag & 0x000000FFU;
	}
	else
	{
        flag = 0U;
	}

	return flag;
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_ClearSpecificErrorFlag(memu_detect_type_t error)
{
	MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

	if(error == MEMU_PERIPHERAL_RAM_DETECT)
	{
		base->ERR_FLAG.R = 0x00FF0000U;
	}
	else if(error == MEMU_FLASH_DETECT)
	{
		base->ERR_FLAG.R = 0x0000FF00U;
	}
	else if(error == MEMU_SYSTEM_RAM_DETECT)
	{
		base->ERR_FLAG.R = 0x000000FFU;
	}
	else
	{
        return STATUS_ERROR;
	}

    return STATUS_SUCCESS;
}

SAF_MEMU_SEC_CODE
uint8_t MEMU_LLD_GetAndClearCorrectableErrorBadBit(memu_detect_type_t error, uint8_t position)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    uint8_t badbit;

    switch(error)
    {
        case MEMU_PERIPHERAL_RAM_DETECT:

        	if(position > MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		badbit = 0xFFU;
        	}
        	else
        	{
        	    badbit = (uint8_t)base->PERIPH_RAM_CERR[position].STS.B.BAD_BIT;  /* polyspace RTE:OBAI,NIV */
        	}

        	if (badbit != 0U)
        	{
        		base->PERIPH_RAM_CERR[position].STS.B.BAD_BIT = 0U;
        	}

            break;

        case MEMU_FLASH_DETECT:

        	if(position > MEMU_FLASH_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		badbit = 0xFFU;
        	}
        	else
        	{
        	    badbit = (uint8_t)base->FLASH_CERR[position].STS.B.BAD_BIT;  /* polyspace RTE:OBAI,NIV */
        	}

        	if (badbit != 0U)
        	{
        		base->FLASH_CERR[position].STS.B.BAD_BIT = 0U;
        	}

            break;

        case MEMU_SYSTEM_RAM_DETECT:

        	if(position > MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		badbit = 0xFFU;
        	}
        	else
        	{
        	    badbit = (uint8_t)base->SYS_RAM_CERR[position].STS.B.BAD_BIT;  /* polyspace RTE:OBAI,NIV */
        	}

        	if (badbit != 0U)
        	{
        		base->SYS_RAM_CERR[position].STS.B.BAD_BIT = 0U;
        	}

            break;

        default:

    		badbit = 0xFFU;

        	break;
    }

    return badbit;
}

SAF_MEMU_SEC_CODE
uint8_t MEMU_LLD_GetCorrectableErrorValid(memu_detect_type_t error, uint8_t position)
{
    MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

    uint8_t validValue;

    switch(error)
    {
        case MEMU_PERIPHERAL_RAM_DETECT:

        	if(position >= MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		validValue = 0U;
        	}
        	else
        	{
        		validValue = (uint8_t)base->PERIPH_RAM_CERR[position].STS.B.VLD;  /* polyspace RTE:OBAI,NIV */
        	}

            break;

        case MEMU_FLASH_DETECT:

        	if(position >= MEMU_FLASH_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		validValue = 0U;
        	}
        	else
        	{
        		validValue = (uint8_t)base->FLASH_CERR[position].STS.B.VLD;  /* polyspace RTE:OBAI,NIV */
        	}

            break;

        case MEMU_SYSTEM_RAM_DETECT:

        	if(position >= MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		validValue = 0U;
        	}
        	else
        	{
        		validValue = (uint8_t)base->SYS_RAM_CERR[position].STS.B.VLD;  /* polyspace RTE:OBAI,NIV */
        	}

            break;

        default:

        	validValue = 0U;

        	break;
    }

    return validValue;
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_SetCorrectableErrorValid(memu_detect_type_t error, uint8_t position, boolean enable)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    status_t ret = STATUS_SUCCESS;

    switch(error)
    {
        case MEMU_PERIPHERAL_RAM_DETECT:

        	if(position > MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		ret = STATUS_ERROR;
        	}
        	else
        	{
        		base->PERIPH_RAM_CERR[position].STS.B.VLD = enable;
        		if (0U == enable)
        		{
        			base->PERIPH_RAM_CERR[position].STS.B.BAD_BIT = enable;
        		}
        	}

            break;

        case MEMU_FLASH_DETECT:

        	if(position > MEMU_FLASH_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		ret = STATUS_ERROR;
        	}
        	else
        	{
        		base->FLASH_CERR[position].STS.B.VLD = enable;
        		if (0U == enable)
        		{
        			base->FLASH_CERR[position].STS.B.BAD_BIT = enable; /* polyspace RTE:OBAI */
        		}
        	}

            break;

        case MEMU_SYSTEM_RAM_DETECT:

        	if(position > MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		ret = STATUS_ERROR;
        	}
        	else
        	{
        		base->SYS_RAM_CERR[position].STS.B.VLD = enable;
        		if (0U == enable)
        		{
        			base->SYS_RAM_CERR[position].STS.B.BAD_BIT = enable;
        		}
        	}

            break;

        default:

    		ret = STATUS_ERROR;

        	break;
    }

    return ret;
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_ClearCorrectableErrorAddress(memu_detect_type_t error, uint8_t position)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    status_t ret = STATUS_SUCCESS;

    switch(error)
    {
        case MEMU_PERIPHERAL_RAM_DETECT:

        	if(position > MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		ret = STATUS_ERROR;
        	}
        	else
        	{
        		base->PERIPH_RAM_CERR[position].ADDR.R = 0U;
        	}

            break;

        case MEMU_FLASH_DETECT:

        	if(position > MEMU_FLASH_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		ret = STATUS_ERROR;
        	}
        	else
        	{
        		base->FLASH_CERR[position].ADDR.R = 0U;
        	}

            break;

        case MEMU_SYSTEM_RAM_DETECT:

        	if(position > MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		ret = STATUS_ERROR;
        	}
        	else
        	{
        		base->SYS_RAM_CERR[position].ADDR.R = 0U;
        	}

            break;

        default:

    		ret = STATUS_ERROR;

        	break;
    }

    return ret;
}

SAF_MEMU_SEC_CODE
uint32_t MEMU_LLD_GetCorrectableErrorAddress(memu_detect_type_t error, uint8_t position)
{
    MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

    uint32_t errorAddr;

    switch(error)
    {
        case MEMU_PERIPHERAL_RAM_DETECT:

        	if(position > MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		errorAddr = 0U;
        	}
        	else
        	{
        		errorAddr = base->PERIPH_RAM_CERR[position].ADDR.R;  /* polyspace RTE:NIV */
        	}

            break;

        case MEMU_FLASH_DETECT:

        	if(position > MEMU_FLASH_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		errorAddr = 0U;
        	}
        	else
        	{
        		errorAddr = base->FLASH_CERR[position].ADDR.R;  /* polyspace RTE:NIV */
        	}

            break;

        case MEMU_SYSTEM_RAM_DETECT:

        	if(position > MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM)
        	{
        		errorAddr = 0U;
        	}
        	else
        	{
        		errorAddr = base->SYS_RAM_CERR[position].ADDR.R;  /* polyspace RTE:NIV */
        	}

            break;

        default:

        	errorAddr = 0U;

        	break;
    }

    return errorAddr;
}

SAF_MEMU_SEC_CODE
uint8_t MEMU_LLD_GetUncorrectableErrorValid(memu_detect_type_t error)
{
    MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

    uint8_t validValue;

    switch(error)
    {
        case MEMU_PERIPHERAL_RAM_DETECT:

            validValue = (uint8_t)base->PERIPH_RAM_UNCERR_STS.B.VLD;  /* polyspace RTE:NIV */

            break;

        case MEMU_FLASH_DETECT:

        	validValue = (uint8_t)base->FLASH_UNCERR_STS.B.VLD;  /* polyspace RTE:NIV */

            break;

        case MEMU_SYSTEM_RAM_DETECT:

        	validValue = (uint8_t)base->SYS_RAM_UNCERR_STS.B.VLD;  /* polyspace RTE:NIV */

            break;

        default:

        	validValue = 0U;

        	break;
    }

    return validValue;
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_SetUncorrectableErrorValid(memu_detect_type_t error, boolean enable)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    status_t ret = STATUS_SUCCESS;

    switch(error)
    {
        case MEMU_PERIPHERAL_RAM_DETECT:

            base->PERIPH_RAM_UNCERR_STS.B.VLD = enable;

            break;

        case MEMU_FLASH_DETECT:

        	base->FLASH_UNCERR_STS.B.VLD = enable;

            break;

        case MEMU_SYSTEM_RAM_DETECT:

        	base->SYS_RAM_UNCERR_STS.B.VLD = enable;

            break;

        default:

        	ret = STATUS_ERROR;

        	break;
    }

    return ret;
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_ClearUncorrectableErrorAddress(memu_detect_type_t error)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    status_t ret = STATUS_SUCCESS;

    switch(error)
    {
        case MEMU_PERIPHERAL_RAM_DETECT:

            base->PERIPH_RAM_UNCERR_ADDR.R = 0U;

            break;

        case MEMU_FLASH_DETECT:

        	base->FLASH_UNCERR_ADDR.R = 0U;

            break;

        case MEMU_SYSTEM_RAM_DETECT:

        	base->SYS_RAM_UNCERR_ADDR.R = 0U;

            break;

        default:

        	ret = STATUS_ERROR;

        	break;
    }

    return ret;
}

SAF_MEMU_SEC_CODE
uint32_t MEMU_LLD_GetUncorrectableErrorAddress(memu_detect_type_t error)
{
    MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

    uint32_t errorAddr;

    switch(error)
    {
        case MEMU_PERIPHERAL_RAM_DETECT:

        		errorAddr = base->PERIPH_RAM_UNCERR_ADDR.R;  /* polyspace RTE:NIV */

            break;

        case MEMU_FLASH_DETECT:

        		errorAddr = base->FLASH_UNCERR_ADDR.R;  /* polyspace RTE:NIV */

            break;

        case MEMU_SYSTEM_RAM_DETECT:

        		errorAddr = base->SYS_RAM_UNCERR_ADDR.R;  /* polyspace RTE:NIV */

            break;

        default:

        	errorAddr = 0U;

        	break;
    }

    return errorAddr;
}

SAF_MEMU_SEC_CODE
uint32_t MEMU_LLD_GetPeripheralRamOverflowFlag(uint8_t offset)
{
    MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

    if(offset > 1U)
    {
    	return 0U;
    }

    return base->PERIPH_RAM_OFLW[offset].R;  /* polyspace RTE:NIV */
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_ClearPeripheralRamOverflowFlag(uint8_t offset)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    if(offset > 1U)
    {
    	return STATUS_ERROR;
    }

    base->PERIPH_RAM_OFLW[offset].R = 0xFFFFFFFFU;

    return STATUS_SUCCESS;
}

SAF_MEMU_SEC_CODE
uint32_t MEMU_LLD_GetFlashOverflowFlag(void)
{
    MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

    return base->FLASH_OFLW0.R;  /* polyspace RTE:NIV */
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_ClearFlashOverflowFlag(void)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    base->FLASH_OFLW0.R = 0xFFFFFFFFU;

    return STATUS_SUCCESS;
}

SAF_MEMU_SEC_CODE
uint32_t MEMU_LLD_GetSysRamOverflowFlag(uint8_t offset)
{
    MEMU_tag_Type const * const base = (MEMU_tag_Type *)g_MEMU_Base;

    if(offset > 2U)
    {
    	return 0U;
    }

    return base->SYS_RAM_OFLW[offset].R;  /* polyspace RTE:NIV */
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_ClearSysRamOverflowFlag(uint8_t offset)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    if(offset > 2U)
    {
    	return STATUS_ERROR;
    }

    base->SYS_RAM_OFLW[offset].R = 0xFFFFFFFFU;

    return STATUS_SUCCESS;
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_Reset(void)
{
    MEMU_tag_Type * const base = (MEMU_tag_Type *)g_MEMU_Base;

    uint8_t i;

    for(i = 0U; i < MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM; i++)
    {
        (void)MEMU_LLD_SetCorrectableErrorValid(MEMU_PERIPHERAL_RAM_DETECT, i, 0U);

        (void)MEMU_LLD_ClearCorrectableErrorAddress(MEMU_PERIPHERAL_RAM_DETECT, i);

        (void)MEMU_LLD_GetAndClearCorrectableErrorBadBit(MEMU_PERIPHERAL_RAM_DETECT, i);
    }

    for(i = 0U; i < MEMU_FLASH_CORRECTABLE_ERROR_TABLE_NUM; i++)
    {
        (void)MEMU_LLD_SetCorrectableErrorValid(MEMU_FLASH_DETECT, i, 0U);

        (void)MEMU_LLD_ClearCorrectableErrorAddress(MEMU_FLASH_DETECT, i);

        (void)MEMU_LLD_GetAndClearCorrectableErrorBadBit(MEMU_FLASH_DETECT, i);
    }

    for(i = 0U; i < MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM; i++)
    {
        (void)MEMU_LLD_SetCorrectableErrorValid(MEMU_SYSTEM_RAM_DETECT, i, 0U);

        (void)MEMU_LLD_ClearCorrectableErrorAddress(MEMU_SYSTEM_RAM_DETECT, i);

        (void)MEMU_LLD_GetAndClearCorrectableErrorBadBit(MEMU_SYSTEM_RAM_DETECT, i);
    }

    (void)MEMU_LLD_SetUncorrectableErrorValid(MEMU_PERIPHERAL_RAM_DETECT, 0U);

    (void)MEMU_LLD_ClearUncorrectableErrorAddress(MEMU_PERIPHERAL_RAM_DETECT);

    (void)MEMU_LLD_SetUncorrectableErrorValid(MEMU_FLASH_DETECT, 0U);

    (void)MEMU_LLD_ClearUncorrectableErrorAddress(MEMU_FLASH_DETECT);

    (void)MEMU_LLD_SetUncorrectableErrorValid(MEMU_SYSTEM_RAM_DETECT, 0U);

    (void)MEMU_LLD_ClearUncorrectableErrorAddress(MEMU_SYSTEM_RAM_DETECT);

    for(i = 0U; i < MEMU_PRRAM_OVERFLOW_ERROR_TABLE_NUM; i++)
    {
        (void)MEMU_LLD_ClearPeripheralRamOverflowFlag(i);
    }

    (void)MEMU_LLD_ClearFlashOverflowFlag();

    for(i = 0U; i < MEMU_SYSRAM_OVERFLOW_ERROR_TABLE_NUM; i++)
    {
        (void)MEMU_LLD_ClearSysRamOverflowFlag(i);
    }

    (void)MEMU_LLD_ClearAllErrorFlag();

    base->CTRL.B.SWR = 0x1U;

    return STATUS_SUCCESS;
}

SAF_MEMU_SEC_CODE
status_t MEMU_LLD_SetUpCallback(memu_detect_type_t error,
		                        memu_error_type_t type,
		                        MEMUCallbackType callback)
{
    if(error == MEMU_PERIPHERAL_RAM_DETECT)
    {
    	memu_prram_callback[type] = callback;
    }
    else if(error == MEMU_FLASH_DETECT)
    {
    	memu_flash_callback[type] = callback;
    }
    else if(error == MEMU_SYSTEM_RAM_DETECT)
    {
    	memu_sysram_callback[type] = callback;
    }
    else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}

SAF_MEMU_SEC_CODE
void MEMU_PRRAM_IRQHandler(void *param)
{
	(void)param;
    uint32_t flag;

    uint8_t i;

    flag = MEMU_LLD_GetSpecificErrorFlag(MEMU_PERIPHERAL_RAM_DETECT);

    (void)MEMU_LLD_ClearSpecificErrorFlag(MEMU_PERIPHERAL_RAM_DETECT);

    if((flag & 0x10U) != 0U)
    {
        if(memu_prram_callback[MEMU_CORRECTABLE_ERROR_DETECT] != NULL_PTR)
        {
        	memu_prram_callback[MEMU_CORRECTABLE_ERROR_DETECT]();/* polyspace RTE:COR */
        }
    }

    if((flag & 0x08U) != 0U)
    {
        if(memu_prram_callback[MEMU_UNCORRECTABLE_ERROR_DETECT] != NULL_PTR)
        {
        	memu_prram_callback[MEMU_UNCORRECTABLE_ERROR_DETECT]();/* polyspace RTE:COR */
        }
    }

    if((flag & 0x7U) != 0U)
    {
		if((flag & 0x04U) != 0U)
		{
			if(memu_prram_callback[MEMU_CORRECTABLE_ERROR_OVERFLOW] != NULL_PTR)
			{
				memu_prram_callback[MEMU_CORRECTABLE_ERROR_OVERFLOW]();
			}
		}

		if((flag & 0x02U) != 0U)
		{
			if(memu_prram_callback[MEMU_UNCORRECTABLE_ERROR_OVERFLOW] != NULL_PTR)
			{
				memu_prram_callback[MEMU_UNCORRECTABLE_ERROR_OVERFLOW]();
			}
		}

		if((flag & 0x01U) != 0U)
		{
			if(memu_prram_callback[MEMU_ERROR_BUFFER_OVERFLOW] != NULL_PTR)
			{
				memu_prram_callback[MEMU_ERROR_BUFFER_OVERFLOW]();
			}
		}

        for(i = 0U; i < 2U; i++)
        {
            (void)MEMU_LLD_ClearPeripheralRamOverflowFlag(i);
        }
    }
}

SAF_MEMU_SEC_CODE
void MEMU_FLASH_IRQHandler(void *param)
{
	(void)param;
    uint32_t flag;

    flag = MEMU_LLD_GetSpecificErrorFlag(MEMU_FLASH_DETECT);

    (void)MEMU_LLD_ClearSpecificErrorFlag(MEMU_FLASH_DETECT);

    if((flag & 0x10U) != 0U)
    {
        if(memu_flash_callback[MEMU_CORRECTABLE_ERROR_DETECT] != NULL_PTR)
        {
        	memu_flash_callback[MEMU_CORRECTABLE_ERROR_DETECT]();/* polyspace RTE:COR */
        }
    }

    if((flag & 0x08U) != 0U)
    {
        if(memu_flash_callback[MEMU_UNCORRECTABLE_ERROR_DETECT] != NULL_PTR)
        {
        	memu_flash_callback[MEMU_UNCORRECTABLE_ERROR_DETECT]();/* polyspace RTE:COR */
        }
    }

    if((flag & 0x7U) != 0U)
    {
		if((flag & 0x04U) != 0U)
		{
			if(memu_flash_callback[MEMU_CORRECTABLE_ERROR_OVERFLOW] != NULL_PTR)
			{
				memu_flash_callback[MEMU_CORRECTABLE_ERROR_OVERFLOW]();
			}
		}

		if((flag & 0x02U) != 0U)
		{
			if(memu_flash_callback[MEMU_UNCORRECTABLE_ERROR_OVERFLOW] != NULL_PTR)
			{
				memu_flash_callback[MEMU_UNCORRECTABLE_ERROR_OVERFLOW]();
			}
		}

		if((flag & 0x01U) != 0U)
		{
			if(memu_flash_callback[MEMU_ERROR_BUFFER_OVERFLOW] != NULL_PTR)
			{
				memu_flash_callback[MEMU_ERROR_BUFFER_OVERFLOW]();
			}
		}

        (void)MEMU_LLD_ClearFlashOverflowFlag();
    }
}

SAF_MEMU_SEC_CODE
void MEMU_SYSRAM_IRQHandler(void *param)
{
	(void)param;
    uint32_t flag;

    uint8_t i;

    /* SRAM single bit test flag*/
    sramitcmTestFlag = RAM_SAFETY_OP_CHANGED;

    flag = MEMU_LLD_GetSpecificErrorFlag(MEMU_SYSTEM_RAM_DETECT);

    (void)MEMU_LLD_ClearSpecificErrorFlag(MEMU_SYSTEM_RAM_DETECT);

    if((flag & 0x10U) != 0U)
    {

        if(memu_sysram_callback[MEMU_CORRECTABLE_ERROR_DETECT] != NULL_PTR)
        {
        	memu_sysram_callback[MEMU_CORRECTABLE_ERROR_DETECT]();/* polyspace RTE:COR */
        }
    }

    if((flag & 0x08U) != 0U)
    {
        if(memu_sysram_callback[MEMU_UNCORRECTABLE_ERROR_DETECT] != NULL_PTR)
        {
        	memu_sysram_callback[MEMU_UNCORRECTABLE_ERROR_DETECT]();/* polyspace RTE:COR */
        }
    }

    if((flag & 0x7U) != 0U)
    {
		if((flag & 0x04U) != 0U)
		{
			if(memu_sysram_callback[MEMU_CORRECTABLE_ERROR_OVERFLOW] != NULL_PTR)
			{
				memu_sysram_callback[MEMU_CORRECTABLE_ERROR_OVERFLOW]();
			}
		}

		if((flag & 0x02U) != 0U)
		{
			if(memu_sysram_callback[MEMU_UNCORRECTABLE_ERROR_OVERFLOW] != NULL_PTR)
			{
				memu_sysram_callback[MEMU_UNCORRECTABLE_ERROR_OVERFLOW]();
			}
		}

		if((flag & 0x01U) != 0U)
		{
			if(memu_sysram_callback[MEMU_ERROR_BUFFER_OVERFLOW] != NULL_PTR)
			{
				memu_sysram_callback[MEMU_ERROR_BUFFER_OVERFLOW]();
			}
		}

        for(i = 0U; i < 3U; i++)
        {
            (void)MEMU_LLD_ClearSysRamOverflowFlag(i);
        }
    }
}

