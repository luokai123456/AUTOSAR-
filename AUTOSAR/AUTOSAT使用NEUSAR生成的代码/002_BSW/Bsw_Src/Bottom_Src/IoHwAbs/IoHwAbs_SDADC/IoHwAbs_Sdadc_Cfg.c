/*
 * IoHwAbs_Sdadc_Cfg.c
 *
 *  Created on: 2025年7月7日
 *      Author: 
 */

#include "IoHwAbs_Sdadc_Cfg.h"

#if 0
uint32 IoHwAbs_SDADC0_SetResultBuffer[SDADC_BUFFER_SIZE] = {0};
uint32 IoHwAbs_SDADC1_SetResultBuffer[SDADC_BUFFER_SIZE] = {0};
uint32 IoHwAbs_SDADC2_SetResultBuffer[SDADC_BUFFER_SIZE] = {0};
uint32 IoHwAbs_SDADC3_SetResultBuffer[SDADC_BUFFER_SIZE] = {0};
uint32 IoHwAbs_SDADC5_SetResultBuffer[SDADC_BUFFER_SIZE] = {0};

sint16 IoHwAbs_SDADC0_ReadResultBuffer[SDADC_BUFFER_SIZE] = {0};
sint16 IoHwAbs_SDADC1_ReadResultBuffer[SDADC_BUFFER_SIZE] = {0};
sint16 IoHwAbs_SDADC2_ReadResultBuffer[SDADC_BUFFER_SIZE] = {0};
sint16 IoHwAbs_SDADC3_ReadResultBuffer[SDADC_BUFFER_SIZE] = {0};
sint16 IoHwAbs_SDADC5_ReadResultBuffer[SDADC_BUFFER_SIZE] = {0};

uint32* IoHwAbs_SDADC_SetResultBuffer_ptr[SDADC_INSTANCE_CDG_NUM] = {
    IoHwAbs_SDADC1_SetResultBuffer,
    IoHwAbs_SDADC3_SetResultBuffer,
    IoHwAbs_SDADC0_SetResultBuffer,
    IoHwAbs_SDADC2_SetResultBuffer,
    IoHwAbs_SDADC5_SetResultBuffer
};

sint16* IoHwAbs_SDADC_ReadResultBuffer_ptr[SDADC_INSTANCE_CDG_NUM] = {
    IoHwAbs_SDADC1_ReadResultBuffer,
    IoHwAbs_SDADC3_ReadResultBuffer,
    IoHwAbs_SDADC0_ReadResultBuffer,
    IoHwAbs_SDADC2_ReadResultBuffer,
    IoHwAbs_SDADC5_ReadResultBuffer
};

#endif