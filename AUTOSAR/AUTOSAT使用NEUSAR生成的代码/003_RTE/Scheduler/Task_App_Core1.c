#include "Std_Types.h"

#include "User_Func.h"
#include "CusM_XCU.h"
#include "Interface_Test_VCU.h"
#include "Interface_Test_IO.h"
// extern void uds_GetActiveSession(uint8 *Data);

// uint8 SessionData = 0;
FUNC(void, RTE_CODE) Core1_Runnable_Task_Init(void)
{

}

FUNC(void, RTE_CODE) Core1_Runnable_App_1ms(void)
{
	#ifdef VCU_Test_Code_YXP
	Test_SetIO_Status_LS10(0);
	#endif

}
FUNC(void, RTE_CODE) Core1_Runnable_App_5ms(void)
{

}
FUNC(void, RTE_CODE) Core1_Runnable_App_10ms(void)
{

	WorkTime_Task_10ms();

	// uds_GetActiveSession(&SessionData);

	#ifdef VCU_Test_Code_FXS
    Interface_VCU_Test_Core1_10ms();
    #endif

}
FUNC(void, RTE_CODE) Core1_Runnable_App_20ms(void)
{

}
FUNC(void, RTE_CODE) Core1_Runnable_App_50ms(void)
{

}
FUNC(void, RTE_CODE) Core1_Runnable_App_100ms(void)
{

}



