/*** create info ***********************
*@ Author : liufengyuan 
*@ date :2025-12-04
*@ Description :BSW bootloader functions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier :  
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#include "Bsw_BootLoader.h"
#include "Can_Interface.h"
#include "string.h"
#include "Can_GeneralTypes.h"
#include "Mcu.h"
#include "Can.h"
#include "Cdd_Sa47301_Type.h"

uint8 OBD_fgJumpPBL_MP = 0;
extern Std_ReturnType BswM_RequestReset(uint8 ValResetMode);
extern uint8 Pm_FlgBootJump_Mp;
uint8 Bb_valJumpCnt_Mp = 0;

void Bt_WriteRAMFlag(void)
{
	uint32* dest_application = NULL_PTR;
	dest_application = (uint32*)(0xFC0C0040);
	*dest_application = SBL_JUMP_MAGIC_WORD;
}
void Bt_Write_PBL_RAMFlag(void)
{
	uint32 *dest_application = NULL;
	dest_application = (uint32*)(0xFC0C0040);
	*dest_application = PBL_JUMP_MAGIC_WORD;
}

void Bt_SoftReset(void)
{
	uint32 *dest_application = NULL;
	dest_application = 0xFFFA8300;  //FES
	*dest_application = 0xffffffffUL;
	dest_application = 0xFFFA8000;	//DES
	*dest_application = 0xffffffffUL;
    Mcu_PerformReset();
}

void Bt_OBD_JumpActiveReset(void)
{
    Bt_WriteRAMFlag();
    Bt_SoftReset();
}

extern Std_ReturnType Cdd_Sbc_Sa47301_CtrlErrMonStatusFunction(Cdd_Sa47301ErrMonType_STDR ErrMonCtrl);
void BootLoader_MainFunction_10ms(void)
{
    Cdd_Sa47301ErrMonType_STDR ErrMonCtrl;
    ErrMonCtrl.ErrMonEn = FALSE;
    ErrMonCtrl.ErrMonRecEn = FALSE;
    ErrMonCtrl.ErrMonSleepEn = FALSE;
    ErrMonCtrl.ErrMonRecTime = SA47301_ERRMONREC_10MS;
    if(Pm_FlgBootJump_Mp)
    {
        if(Bb_valJumpCnt_Mp < 10)
        {
            if(Bb_valJumpCnt_Mp == 0)
            {
                Cdd_Sbc_Sa47301_CtrlErrMonStatusFunction(ErrMonCtrl);
            }
            Bb_valJumpCnt_Mp++;
        }
        else
        {
            Bb_valJumpCnt_Mp = 0;
            Pm_FlgBootJump_Mp = 0;
            Bt_OBD_JumpActiveReset();
        }
    }
}

void SendSessionServerNRC(uint8 NRC)
{
	uint8 DataPtr[8] = {0};
	Can_PduType canPduInfo;
	canPduInfo.sdu = DataPtr;
	canPduInfo.length = 8;
	canPduInfo.id = 0x7EE;
	#ifndef CAN_TEST_CFG_H_
	canPduInfo.swPduHandle = 90;
	#else
	canPduInfo.swPduHandle = 38;
	#endif

	DataPtr[0] = 0x03;
	DataPtr[1] = 0x7F;
	DataPtr[2] = 0x10;
	DataPtr[3] = NRC;

	#ifndef CAN_TEST_CFG_H_
	Can_Write(PT_CAN_HWObject_TX, &canPduInfo); //92 PT CAN
	#else
	Can_Write(38, &canPduInfo);
	#endif
}

void Bt_RxIndexJudge(Can_HwType* sCan_Mailbox, PduInfoType* sCan_PduInfo)
{
	if((((sCan_Mailbox->CanId)&0x1FFFFFFF) == 0x7E6)&&((sCan_PduInfo->SduDataPtr[0] == 0x02)&&(sCan_PduInfo->SduDataPtr[1] == 0x10)&&(sCan_PduInfo->SduDataPtr[2] == 0x02)))
	{
		SendSessionServerNRC(0x78);
        BswM_RequestReset(2);
	}
}

