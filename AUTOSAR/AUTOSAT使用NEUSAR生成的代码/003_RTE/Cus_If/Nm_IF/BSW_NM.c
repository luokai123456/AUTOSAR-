#include "BSW_NM.h"

FUNC(void, BSW_NM_CODE) BSW_NM_Init(void)
{


}


FUNC(void, BSW_NM_CODE) BSW_NM_5ms(void)
{
	can_NM_WakeUpFlg_Clear();
    Can_NM_UserData_Fill();
}


