#include "Std_Types.h"
#include "BMS_UDS_Event.h"
#include "Interface_Test_BMS.h"
#include "Interface_Test_IO.h"

FUNC(void, RTE_CODE) Core2_Runnable_Task_Init(void)
{

}

FUNC(void, RTE_CODE) Core2_Runnable_App_1ms(void)
{
    #ifdef VCU_Test_Code_YXP
    // Test_SetIO_Status_LS11(0);
    #endif
    
}

FUNC(void, RTE_CODE) Core2_Runnable_App_5ms(void)
{

}

FUNC(void, RTE_CODE) Core2_Runnable_App_10ms(void)
{
    Set_BMS_UDS_Event();
}

FUNC(void, RTE_CODE) Core2_Runnable_App_20ms(void)
{

}

FUNC(void, RTE_CODE) Core2_Runnable_App_50ms(void)
{

}

FUNC(void, RTE_CODE) Core2_Runnable_App_100ms(void)
{
    #ifdef BMS_Test_Code_KYH
    Interface_BMS_Test_Core2_100ms();
    #endif
}
