/*
 * Model version                  : 1.0
 */

#include "Std_Types.h"
#include "Interface_Test_IO.h"
#include "Lsd_Release.h"

/*IO_TestCode*/

uint8 Test_IO_Status_LS9 = 0;
uint8 Test_IO_Status_LS10 = 0;
uint8 Test_IO_Status_LS11 = 0;
uint8 Test_IO_Status_LS12 = 0;

void Test_IO_Turn_LS9(void)
{
    Test_IO_Status_LS9 = 1-Test_IO_Status_LS9;
    Cdd_Lsd_SetLevelFunction(EXT_D_LS9_CH1,Test_IO_Status_LS9);
}

void Test_SetIO_Status_LS9(uint8 Status)
{
    Test_IO_Status_LS9 = Status;
    Cdd_Lsd_SetLevelFunction(EXT_D_LS9_CH1,Test_IO_Status_LS9);
}

void Test_IO_Turn_LS10(void)
{
    Test_IO_Status_LS10 = 1-Test_IO_Status_LS10;
    Cdd_Lsd_SetLevelFunction(EXT_D_LS10_CH2,Test_IO_Status_LS10);
}

void Test_SetIO_Status_LS10(uint8 Status)
{
    Test_IO_Status_LS10 = Status;
    Cdd_Lsd_SetLevelFunction(EXT_D_LS10_CH2,Test_IO_Status_LS10);
}

void Test_IO_Turn_LS11(void)
{
    Test_IO_Status_LS11 = 1-Test_IO_Status_LS11;
    Cdd_Lsd_SetLevelFunction(EXT_D_LS11_CH3,Test_IO_Status_LS11);
}

void Test_SetIO_Status_LS11(uint8 Status)
{
    Test_IO_Status_LS11 = Status;
    Cdd_Lsd_SetLevelFunction(EXT_D_LS11_CH3,Test_IO_Status_LS11);
}

void Test_IO_Turn_LS12(void)
{
    Test_IO_Status_LS12 = 1-Test_IO_Status_LS12;
    Cdd_Lsd_SetLevelFunction(EXT_D_LS12_CH4,Test_IO_Status_LS12);
}

void Test_SetIO_Status_LS12(uint8 Status)
{
    Test_IO_Status_LS12 = Status;
    Cdd_Lsd_SetLevelFunction(EXT_D_LS12_CH4,Test_IO_Status_LS12);
}




/*IO_TestCode*/