/*
 * Model version                  : 1.0
 */

#include "Std_Types.h"

#include "User_Func.h"
#include "CusM_XCU.h"

/*PMS_TestCode*/
#include "Rte_swc_VCOP.h"
uint16 PMSTest_Counter=0;
/*PMS_TestCode*/
void Interface_VCU_Test_Core1_10ms(void)
{
	/*PMS_TestCode*/
	if(PMSTest_Counter<300)
	{
		Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05(1);

		Rte_IWrite_swc_VCOP_Step_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03(1);

		PMSTest_Counter++;
	}
	else if(PMSTest_Counter<600)
	{
		 Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05(0);

		 Rte_IWrite_swc_VCOP_Step_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03(0);

		PMSTest_Counter++;
	}
	else
	{
		PMSTest_Counter=0;
	}

	/*PMS_TestCode*/

}