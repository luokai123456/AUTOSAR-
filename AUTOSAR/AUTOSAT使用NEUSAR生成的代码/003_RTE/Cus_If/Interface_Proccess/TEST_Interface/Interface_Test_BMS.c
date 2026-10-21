/*
 * Model version                  : 1.0
 */

#include "Std_Types.h"
#include "Rte_swc_COL.h"
//#include "Sws_DriverCtrl.h"
extern uint16 Ea_CellTemp[48];
extern float32 Ea_AFETemp[8];
extern uint16 Ea_CellVoltage[144];
extern sint16 Tset_Cs_BMUTemp[32];
extern sint16 Tset_Cs_BMUTemp1[32];
// extern uint16 PMS_KL30;
// extern uint16 PMS_EXT_AI_BATTERY_TEMPH_6;
// extern uint16 PMS_EXT_AI_BATTERY_TEMPH_5;
// // extern uint16 PMS_EXT_AI_MID_COOLING_TEMPH_8;
// extern boolean PMS_EXT_DI_HS_10;
// extern boolean PMS_EXT_DI_HS_08;

void Interface_BMS_Test_Core2_100ms(void)
{
//	Ea_CellVoltage[0] = 3;
//	Ea_CellTemp[0]/330
	Rte_IWrite_COL_100ms_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt(Ea_CellVoltage[0]);// 0X21A
	Rte_IWrite_COL_100ms_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt(Ea_CellVoltage[18]);// 0X21A
	Rte_IWrite_COL_100ms_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt(Ea_CellVoltage[36]);// 0X21A
//	Rte_IWrite_COL_100ms_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID(Ea_CellTemp[0]/330);// 0X21A
//	Rte_IWrite_COL_100ms_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID(Ea_CellTemp[0]*0.01);

//	Ea_AFETemp[0] = 400;	Ea_AFETemp[1] = 500;
//	Tset_Cs_BMUTemp[0] = 500;	Tset_Cs_BMUTemp[6] = 600;
//	Tset_Cs_BMUTemp[12] = 700;	Tset_Cs_BMUTemp[18] = 800;

	uint8 Ea_AFETemp_0 = (uint8)(2*(Ea_AFETemp[0] +40));
	uint8 Ea_AFETemp_1 = (uint8)(2*(Ea_AFETemp[1] +40));

	if(Tset_Cs_BMUTemp[0] >= 1250)
	{
		Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID(125);
	}
	else if((Tset_Cs_BMUTemp[0]>870)&&(Tset_Cs_BMUTemp[0]<1250))
	{
		Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID(Tset_Cs_BMUTemp[0]*0.1);
	}
	else if(Tset_Cs_BMUTemp[0] > 0)
	{
		Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID(Tset_Cs_BMUTemp[0]*0.1);
	}
	else
	{
		Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID(88);
	}
	if(Tset_Cs_BMUTemp[0]>870)
	{
		Tset_Cs_BMUTemp[0] = 870;
	}
	if(Tset_Cs_BMUTemp[6]>870)
	{
		Tset_Cs_BMUTemp[6] = 870;
	}
	if(Tset_Cs_BMUTemp[12]>870)
	{
		Tset_Cs_BMUTemp[12] = 870;
	}
	if(Tset_Cs_BMUTemp[18]>870)
	{
		Tset_Cs_BMUTemp[18] = 870;
	}
	uint8 Ea_BMUTemp_0 = (uint8)(2*(Tset_Cs_BMUTemp[0]*0.1 +40));
	uint8 Ea_BMUTemp_6 = (uint8)(2*(Tset_Cs_BMUTemp[6]*0.1 +40));
	uint8 Ea_BMUTemp_12 = (uint8)(2*(Tset_Cs_BMUTemp[12]*0.1 +40));
	uint8 Ea_BMUTemp_18 = (uint8)(2*(Tset_Cs_BMUTemp[18]*0.1 +40));

//	if(Ea_CellTemp[0] == 0)
//	{
//		Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID(21);
//	}
//	if((Ea_CellTemp[0] > 0)&&(Ea_CellTemp[0] < 210))
//	{
//		Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID(Ea_CellTemp[0]);
//	}
//	if(Ea_CellTemp[0] >= 210)
//	{
//		Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID(Ea_CellTemp[0]/210);
//	}

	if(Tset_Cs_BMUTemp1[0] == 0)
	{
		Rte_IWrite_COL_100ms_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID(21);
	}
	if((Tset_Cs_BMUTemp1[0] > 0)&&(Tset_Cs_BMUTemp1[0] < 210))
	{
		Rte_IWrite_COL_100ms_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID(Tset_Cs_BMUTemp1[0]);
	}
	if(Tset_Cs_BMUTemp1[0] >= 210)
	{
		Rte_IWrite_COL_100ms_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID(Tset_Cs_BMUTemp1[0]/210);
	}
//
//
//	if(Ea_BMUTemp_0 > 87)
//	{
//		Ea_BMUTemp_0 = 87;
//	}
//	if(Ea_BMUTemp_6 > 87)
//	{
//		Ea_BMUTemp_6 = 87;
//	}
//	if(Ea_BMUTemp_12 > 87)
//	{
//		Ea_BMUTemp_12 = 87;
//	}
//	if(Ea_BMUTemp_18 > 87)
//	{
//		Ea_BMUTemp_18 = 87;
//	}
	Rte_IWrite_COL_100ms_BMSH_TBOX_TempA_BMSH_TBOX_TempA(Ea_AFETemp_0);// 0X21B
	Rte_IWrite_COL_100ms_BMSH_TBOX_TempB_BMSH_TBOX_TempB(Ea_AFETemp_1);// 0X21B
	Rte_IWrite_COL_100ms_BMSH_TBOX_TempC_BMSH_TBOX_TempC(Ea_BMUTemp_0);// 0X21B
	Rte_IWrite_COL_100ms_BMSH_TBOX_TempD_BMSH_TBOX_TempD(Ea_BMUTemp_6);// 0X21B
	Rte_IWrite_COL_100ms_BMSH_TBOX_TempE_BMSH_TBOX_TempE(Ea_BMUTemp_12);// 0X21B
	Rte_IWrite_COL_100ms_BMSH_TBOX_TempF_BMSH_TBOX_TempF(Ea_BMUTemp_18);// 0X21B

	// Rte_IWrite_COL_1000ms_BMSH_CellVoltMax_BMSH_CellVoltMax(PMS_KL30);
	// Rte_IWrite_COL_1000ms_BMSH_CellVoltMin_BMSH_CellVoltMin(PMS_EXT_AI_BATTERY_TEMPH_6);
	// Rte_IWrite_COL_1000ms_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt(PMS_EXT_AI_BATTERY_TEMPH_5);
	// Rte_IWrite_COL_100ms_BMSH_StsWakeUp_BMSH_StsWakeUp(PMS_EXT_DI_HS_10);
	// Rte_IWrite_COL_100ms_BMSH_StsA_plus_BMSH_StsA_plus(PMS_EXT_DI_HS_08);

}
