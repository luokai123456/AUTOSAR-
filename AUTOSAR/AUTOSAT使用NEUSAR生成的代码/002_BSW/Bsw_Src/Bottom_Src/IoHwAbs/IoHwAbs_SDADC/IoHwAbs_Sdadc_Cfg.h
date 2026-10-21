/*
 * IoHwAbs_Sdadc_Cfg.h
 *
 *  Created on: 2025年7月7日
 *      Author:
 */

#ifndef _IOHWABS_SDADC_CFG_H_
#define _IOHWABS_SDADC_CFG_H_

#include "Platform_Types.h"
#include "SDAdc_Cfg.h"
#define SDADC_BUFFER_SIZE 100u
#if 0
extern uint32 IoHwAbs_SDADC0_SetResultBuffer[SDADC_BUFFER_SIZE];
extern uint32 IoHwAbs_SDADC1_SetResultBuffer[SDADC_BUFFER_SIZE];
extern uint32 IoHwAbs_SDADC2_SetResultBuffer[SDADC_BUFFER_SIZE];
extern uint32 IoHwAbs_SDADC3_SetResultBuffer[SDADC_BUFFER_SIZE];
extern uint32 IoHwAbs_SDADC5_SetResultBuffer[SDADC_BUFFER_SIZE];

extern sint16 IoHwAbs_SDADC0_ReadResultBuffer[SDADC_BUFFER_SIZE];
extern sint16 IoHwAbs_SDADC1_ReadResultBuffer[SDADC_BUFFER_SIZE];
extern sint16 IoHwAbs_SDADC2_ReadResultBuffer[SDADC_BUFFER_SIZE];
extern sint16 IoHwAbs_SDADC3_ReadResultBuffer[SDADC_BUFFER_SIZE];
extern sint16 IoHwAbs_SDADC5_ReadResultBuffer[SDADC_BUFFER_SIZE];

extern uint32* IoHwAbs_SDADC_SetResultBuffer_ptr[SDADC_INSTANCE_CDG_NUM];
extern sint16* IoHwAbs_SDADC_ReadResultBuffer_ptr[SDADC_INSTANCE_CDG_NUM];

#endif
#endif /* SOURCE_FLASH_TESTER_IOHWABS_SDADC_IOHWABS_SDADC_CFG_H_ */
