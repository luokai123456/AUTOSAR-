/*** create info ***************************************************************
*@ File name: Nvm_Interface.h
*@ Author : liufengyuan 
*@ date :2025-04-27
*@ Description : 描述本文件实现功能
**** modify info ***************************************************************
*@ version :0.0
*@ Modifier : liufengyuan 
*@ date :2025-04-27
*@ Modification Description : 初始版本
********************************************************************************/
#ifndef BOTTOMLIB_INC_NVM_PRV_H_
#define BOTTOMLIB_INC_NVM_PRV_H_

#include "Std_Types.h"
#include "MemIf_Types.h"

/* CRITICAL WARNING: No underlying block size detection mechanism exists. 
 * PPLICATION LAYER MODIFICATIONS ARE STRICTLY PROHIBITED!
 * 
 * These sizes are hardcoded and must match the NvM configuration exactly.
 * Any changes to block sizes in the NvM configuration must be manually 
 * synchronized here by authorized BSW developers only.
 * 
 * Application layer developers MUST NOT modify these values under any 
 * circumstances. Doing so will cause memory corruption, data loss, and 
 * system instability. */


extern uint8* const NvM_RamBlockArray[]; 
extern FUNC(Std_ReturnType, NVM_CODE) Mem_Nvm_ReadAll(void);

extern FUNC(Std_ReturnType, NVM_CODE) Mem_Nvm_WriteAll(void);


#endif /* BOTTOMLIB_INC_NVM_PRV_H_ */
