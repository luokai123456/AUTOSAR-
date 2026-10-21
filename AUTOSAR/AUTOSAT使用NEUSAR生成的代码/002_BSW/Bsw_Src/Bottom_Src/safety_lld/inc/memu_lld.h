/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3007PT
* DESCRIPTION : CCFC3007PT memu low level drivers h file
* HISTORY     : Initial version
* @file     memu_lld.h
* @version  1.0
* @date     2023 - 09 - 11
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/

/*PRQA S 0722,1534,0779,0787 EOF*/

#ifndef LLD_INC_MEMU_LLD_H_
#define LLD_INC_MEMU_LLD_H_

#include "derivative.h"
#include "status.h"

typedef  struct MEMU_tag                       MEMU_tag_Type;

#define MEMU_BASE_ADDR                         ((uint32_t)&MEMU)
#define MEMU_BASE                              ((MEMU_tag_Type *)MEMU_BASE_ADDR)
#define MEMU_BASE_ARRAY                        {MEMU_BASE}

#define MEMU_PRRAM_CORRECTABLE_ERROR_TABLE_NUM      2U
#define MEMU_FLASH_CORRECTABLE_ERROR_TABLE_NUM      20U
#define MEMU_SYSRAM_CORRECTABLE_ERROR_TABLE_NUM     10U

#define MEMU_PRRAM_OVERFLOW_ERROR_TABLE_NUM      2U
#define MEMU_FLASH_OVERFLOW_ERROR_TABLE_NUM      1U
#define MEMU_SYSRAM_OVERFLOW_ERROR_TABLE_NUM     3U

/* Define ram test flag */
#define RAM_SAFETY_OP_INITIAL                    1U
#define RAM_SAFETY_OP_CHANGED                    0U

typedef enum
{
    MEMU_PERIPHERAL_RAM_CORRECTABLE_ERROR_DETECT     = 0x00100000U,
    MEMU_PERIPHERAL_RAM_UNCORRECTABLE_ERROR_DETECT   = 0x00080000U,
    MEMU_PERIPHERAL_RAM_CORRECTABLE_ERROR_OVERFLOW   = 0x00040000U,
    MEMU_PERIPHERAL_RAM_UNCORRECTABLE_ERROR_OVERFLOW = 0x00020000U,
    MEMU_PERIPHERAL_RAM_ERROR_BUFFER_OVERFLOW        = 0x00010000U,

    MEMU_FLASH_CORRECTABLE_ERROR_DETECT              = 0x00001000U,
    MEMU_FLASH_UNCORRECTABLE_ERROR_DETECT            = 0x00000800U,
    MEMU_FLASH_CORRECTABLE_ERROR_OVERFLOW            = 0x00000400U,
    MEMU_FLASH_UNCORRECTABLE_ERROR_OVERFLOW          = 0x00000200U,
    MEMU_FLASH_ERROR_BUFFER_OVERFLOW                 = 0x00000100U,

    MEMU_SYSTEM_RAM_CORRECTABLE_ERROR_DETECT         = 0x00000010U,
    MEMU_SYSTEM_RAM_UNCORRECTABLE_ERROR_DETECT       = 0x00000008U,
    MEMU_SYSTEM_RAM_CORRECTABLE_ERROR_OVERFLOW       = 0x00000004U,
    MEMU_SYSTEM_RAM_UNCORRECTABLE_ERROR_OVERFLOW     = 0x00000002U,
    MEMU_SYSTEM_RAM_ERROR_BUFFER_OVERFLOW            = 0x00000001U
}memu_error_flag_t;


typedef enum
{
	MEMU_PERIPHERAL_RAM_DETECT = 0U,
	MEMU_FLASH_DETECT,
	MEMU_SYSTEM_RAM_DETECT
}memu_detect_type_t;

typedef enum
{
	MEMU_CORRECTABLE_ERROR_DETECT = 0U,
	MEMU_UNCORRECTABLE_ERROR_DETECT,
	MEMU_CORRECTABLE_ERROR_OVERFLOW,
	MEMU_UNCORRECTABLE_ERROR_OVERFLOW,
	MEMU_ERROR_BUFFER_OVERFLOW
}memu_error_type_t;

typedef void (*MEMUCallbackType)(void);

status_t MEMU_LLD_SendFlagtoFCCU(memu_error_flag_t error, boolean enable);

status_t MEMU_LLD_ClearErrorFlag(memu_error_flag_t error);

status_t MEMU_LLD_ClearAllErrorFlag(void);

uint32_t MEMU_LLD_GetErrorFlag(memu_error_flag_t error);

uint32_t MEMU_LLD_GetAllErrorFlag(void);

uint32_t MEMU_LLD_GetSpecificErrorFlag(memu_detect_type_t error);

status_t MEMU_LLD_ClearSpecificErrorFlag(memu_detect_type_t error);

uint8_t MEMU_LLD_GetAndClearCorrectableErrorBadBit(memu_detect_type_t error, uint8_t position);

uint8_t MEMU_LLD_GetCorrectableErrorValid(memu_detect_type_t error, uint8_t position);

status_t MEMU_LLD_SetCorrectableErrorValid(memu_detect_type_t error, uint8_t position, boolean enable);

status_t MEMU_LLD_ClearCorrectableErrorAddress(memu_detect_type_t error, uint8_t position);

uint32_t MEMU_LLD_GetCorrectableErrorAddress(memu_detect_type_t error, uint8_t position);

uint8_t MEMU_LLD_GetUncorrectableErrorValid(memu_detect_type_t error);

status_t MEMU_LLD_SetUncorrectableErrorValid(memu_detect_type_t error, boolean enable);

status_t MEMU_LLD_ClearUncorrectableErrorAddress(memu_detect_type_t error);

uint32_t MEMU_LLD_GetUncorrectableErrorAddress(memu_detect_type_t error);

uint32_t MEMU_LLD_GetPeripheralRamOverflowFlag(uint8_t offset);

status_t MEMU_LLD_ClearPeripheralRamOverflowFlag(uint8_t offset);

uint32_t MEMU_LLD_GetFlashOverflowFlag(void);

status_t MEMU_LLD_ClearFlashOverflowFlag(void);

uint32_t MEMU_LLD_GetSysRamOverflowFlag(uint8_t offset);

status_t MEMU_LLD_ClearSysRamOverflowFlag(uint8_t offset);

status_t MEMU_LLD_Reset(void);

status_t MEMU_LLD_SetUpCallback(memu_detect_type_t error,
		                        memu_error_type_t type,
		                        MEMUCallbackType callback);

void MEMU_PRRAM_IRQHandler(void *param);

void MEMU_FLASH_IRQHandler(void *param);

void MEMU_SYSRAM_IRQHandler(void *param);

#endif /* LLD_INC_MEMU_LLD_H_ */
