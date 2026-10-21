/*** create info ***********************
*@ Author : wangjiacheng
*@ date :2025-12-04
*@ Description :NVM interface functions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : wangjiacheng 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#include "NvM.h"
#include "Fee.h"
#include "Compiler.h"
#include "StandardTypes.h"
#include "NvM_Types.h"
#include "MemIf_Types.h"
#include "NvM_Def.h"
#include "common.h"
#include "MemIf_Types.h"
#include "Nvm_UserBlock.h"
#include "Nvm_prv.h"
#include "NvM_Cfg.h"
#include "NvM_BlockCallback.h"
MemIf_StatusType Mem_Fee_GetStatus(void)
{
	MemIf_StatusType MemIf_Status;

	MemIf_Status = Fee_GetStatus();

	return MemIf_Status;
}

#define NvM_delayCnt_limit 30000
extern void NvM_ReadAll_Finish_Flag(uint8 Finish_Flag);
FUNC(Std_ReturnType, NVM_CODE) Mem_Nvm_ReadAll(void)//增加超时判断
{
    uint32 EcuM_delayCnt = 0;
	Std_ReturnType retVal = E_NOT_OK;
	NvM_RequestResultType ReadAllReqResult = NVM_REQ_NOT_OK;

    NvM_ReadAll();
    do
    {
        NvM_MainFunction();
        Fee_MainFunction();
        Fls_MainFunction();
        retVal = NvM_GetErrorStatus(0, &ReadAllReqResult);
        EcuM_delayCnt++;
        if(EcuM_delayCnt >= NvM_delayCnt_limit)
        {
            break;
        }
    }while(ReadAllReqResult == NVM_REQ_PENDING);
    NvM_ReadAll_Finish_Flag(1);
    return retVal;
}
FUNC(Std_ReturnType, NVM_CODE) Mem_Nvm_WriteAll(void)//增加超时判断
{
    uint32 EcuM_delayCnt = 0;
	Std_ReturnType retVal = E_NOT_OK;
	NvM_RequestResultType WriteAllReqResult = NVM_REQ_NOT_OK;
    NvM_SetRamUserBlockStatus();

    NvM_WriteAll();
    do
    {
        NvM_MainFunction();
        Fee_MainFunction();
        Fls_MainFunction();
        retVal = NvM_GetErrorStatus(0, &WriteAllReqResult);
        EcuM_delayCnt++;
        if(EcuM_delayCnt >= NvM_delayCnt_limit)
        {
            break;
        }
    }while(WriteAllReqResult == NVM_REQ_PENDING);

    return retVal;
}
