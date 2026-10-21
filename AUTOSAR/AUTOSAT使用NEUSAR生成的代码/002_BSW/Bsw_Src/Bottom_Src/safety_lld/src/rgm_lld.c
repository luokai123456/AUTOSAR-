/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     rgm_lld.c
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
/*PRQA S 1505,1503,4342 EOF*/
#include "rgm_lld.h"/*PRQA S 0380*/
#include "mcu_lld.h"
#include "intc_lld.h"
#include "compiler_api.h"
#include "console.h"
#include "Saf_MemMap.h"

SAF_CORE_SEC_VAR_INIT
rgm_manager_user_config_t config1 =
{
	.DERD_PROST = {
			.DE_enable = FALSE,
			.DE_name = DEST_PORST,
	},
	{//FERD
		{
			.FE_enable = FALSE,
			.FERD_name = Func_VOR,
		},
		{
			.FE_enable = FALSE,
			.FERD_name = Func_TSR,
		},
		{
			.FE_enable = FALSE,
			.FERD_name = Func_ESR1,
		},
	},
	{//FEAR
		{
			.FE_enable = FALSE,
			.mode = INT_REQ,
			.FEAR_name = Func_VOR,
		},
		{
			.FE_enable = FALSE,
			.mode = INT_REQ,
			.FEAR_name = Func_TSR,
		},
		{
			.FE_enable = FALSE,
			.mode = INT_REQ,
			.FEAR_name = Func_ESR1,
		},
	},
	{//FBRE
		{
			.isnot_esr0_assreted = TRUE,
			.FB_name = Func_VOR,
		},
		{
			.isnot_esr0_assreted = TRUE,
			.FB_name = Func_TSR,
		},
		{
			.isnot_esr0_assreted = TRUE,
			.FB_name = Func_HSM,
		},
		{
			.isnot_esr0_assreted = TRUE,
			.FB_name = Func_JTAG,
		},
		{
			.isnot_esr0_assreted = TRUE,
			.FB_name = Func_FCCU_SOFT,
		},
		{
			.isnot_esr0_assreted = TRUE,
			.FB_name = Func_FCCU_HARD,
		},
		{
			.isnot_esr0_assreted = TRUE,
			.FB_name = Func_ESR1,
		},
	},
	{//FBSS
		{
			.FE_enable = FALSE,
			.FESS_name= Func_VOR,
		},
		{
			.FE_enable = FALSE,
			.FESS_name= Func_TSR,
		},
		{
			.FE_enable = FALSE,
			.FESS_name= Func_JTAG,
		},
		{
			.FE_enable = FALSE,
			.FESS_name= Func_SOFT,
		},
		{
			.FE_enable = FALSE,
			.FESS_name= Func_ESR1,
		},
		{
			.FE_enable = FALSE,
			.FESS_name= Func_ESR0,
		},

	},
	.DRET = {
			.DE_enable = FALSE,
			.threholdcount = 0,
	},
	.FRET = {
			.FE_enable = FALSE,
			.threholdcount = 0,
	},

};

/* ISR*/
SAF_CORE_SEC_CODE
void RGM_ISR(void)
{
	if(RGM_StPtr->DES.B.F_PORST == 1U)
	{
		Uart_Printf("DES.F_PORST test!\r\n");
		RGM_StPtr->DES.B.F_PORST =1; // w1c
	}
	if(RGM_StPtr->FES.B.F_VOR_FUNC == 1U)
	{
		Uart_Printf("FES.F_VOR_FUNC test!\r\n");
		RGM_StPtr->FES.B.F_VOR_FUNC = 1;//w1c
	}

	if(RGM_StPtr->FES.B.F_TSR_FUNC == 1U)
	{
		Uart_Printf("FES.F_TSR_FUNC test!\r\n");
		RGM_StPtr->FES.B.F_TSR_FUNC = 1;//w1c
	}

	if(RGM_StPtr->FES.B.F_ESR1 == 1U)
	{
		Uart_Printf("FES.F_ESR1 test!\r\n");
		RGM_StPtr->FES.B.F_ESR1 = 1;//w1c
	}

}

SAF_CORE_SEC_CODE
status_t RGM_LLD_PITRTC_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST0.B.PIT_RTC_0_RST = enable;
	}
	else if(instance == 1U)
	{
		RGM_StPtr->PRST0.B.PIT_RTC_1_RST = enable;
	}
	else{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_SIUL_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST0.B.SIUL_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_SIPI_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST0.B.SIPI_0_RST = enable;
	}
	else{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_LFAST_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST0.B.LFAST_0_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_EBI_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST0.B.EBI_0_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_ADCSD_Rst(uint32_t instance,boolean enable)
{

	status_t ret = STATUS_SUCCESS;
	switch(instance)
	{
	case 0:
		RGM_StPtr->PRST1.B.ADCSD_0_RST = enable;
		break;
	case 1:
		RGM_StPtr->PRST5.B.ADCSD_1_RST = enable;
		break;
	case 2:
		RGM_StPtr->PRST1.B.ADCSD_2_RST = enable;
		break;
	case 3:
		RGM_StPtr->PRST5.B.ADCSD_3_RST = enable;
		break;
	case 4:
		RGM_StPtr->PRST1.B.ADCSD_4_RST = enable;
		break;
	case 5:
		RGM_StPtr->PRST5.B.ADCSD_5_RST = enable;
		break;
	case 6:
		RGM_StPtr->PRST1.B.ADCSD_6_RST = enable;
		break;
	case 7:
		RGM_StPtr->PRST5.B.ADCSD_7_RST = enable;
		break;
	case 8:
		RGM_StPtr->PRST1.B.ADCSD_8_RST = enable;
		break;
	case 9:
		RGM_StPtr->PRST5.B.ADCSD_9_RST = enable;
		break;
	default:
		ret = STATUS_ERROR;
		break;
	}

	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_CRC_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST1.B.CRC_0_RST = enable;
	}
	else if(instance == 1U)
	{
		RGM_StPtr->PRST5.B.CRC_1_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_DMAMUX_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST1.B.DMAMUX_0_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_DSPI_Rst(uint32_t instance,boolean enable)
{
	status_t ret = STATUS_SUCCESS;
	switch(instance)
	{
	case 0:
		RGM_StPtr->PRST3.B.DSPI_0_RST = enable;
		break;
	case 1:
		RGM_StPtr->PRST3.B.DSPI_1_RST = enable;
		break;
	case 2:
		RGM_StPtr->PRST7.B.DSPI_2_RST = enable;
		break;
	case 3:
		RGM_StPtr->PRST7.B.DSPI_3_RST = enable;
		break;
	case 4:
		RGM_StPtr->PRST3.B.DSPI_4_RST = enable;
		break;
	case 5:
		RGM_StPtr->PRST7.B.DSPI_5_RST = enable;
		break;
	case 6:
		RGM_StPtr->PRST3.B.DSPI_6_RST = enable;
		break;
	case 12:
		RGM_StPtr->PRST2.B.DSPI_12_RST = enable;
		break;
	default:
		ret = STATUS_ERROR;
		break;
	}

	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_LINFlexd_Rst(uint32_t instance,boolean enable)
{

	status_t ret = STATUS_SUCCESS;
	switch(instance)
	{
	case 0:
		RGM_StPtr->PRST2.B.LINFlexD_0_RST = enable;
		break;
	case 1:
		RGM_StPtr->PRST2.B.LINFlexD_1_RST = enable;
		break;
	case 2:
		RGM_StPtr->PRST6.B.LINFlexD_2_RST = enable;
		break;
	case 14:
		RGM_StPtr->PRST2.B.LINFlexD_14_RST = enable;
		break;
	case 15:
		RGM_StPtr->PRST6.B.LINFlexD_15_RST = enable;
		break;
	case 16:
		RGM_StPtr->PRST2.B.LINFlexD_16_RST = enable;
		break;
	default:
		ret =  STATUS_ERROR;
                break;
	}

	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_CANRAMCTR_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST2.B.CAN_RAM_CTR_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_TTCAN_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST2.B.TTCAN_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_MCAN_Rst(uint32_t instance,boolean enable)
{
	status_t ret = STATUS_SUCCESS;
	switch(instance)
	{
	case 1:
		RGM_StPtr->PRST2.B.MCAN_1_RST = enable;
		break;
	case 2:
		RGM_StPtr->PRST2.B.MCAN_2_RST = enable;
		break;
	case 3:
		RGM_StPtr->PRST2.B.MCAN_3_RST = enable;
		break;
	case 4:
		RGM_StPtr->PRST2.B.MCAN_4_RST = enable;
		break;
	default:
		ret =  STATUS_ERROR;
		break;
	}

	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_PSI5_Rst(PSI5_name_t instance,boolean enable)
{
	status_t ret = STATUS_SUCCESS;
	switch(instance)
	{
	case PSI5_0_RST:
		RGM_StPtr->PRST3.B.PSI5_0_RST = enable;
		break;
	case PSI5_1_RST:
		RGM_StPtr->PRST7.B.PSI5_1_RST = enable;
		break;
	case PSI5_S_0_RST:
		RGM_StPtr->PRST5.B.PSI5_S_0_RST = enable;
		break;
	default:
		ret = STATUS_ERROR;
		break;
	}
	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_FlexRay_Rst(uint32_t instance,boolean enable)
{

	if(instance == 0U)
	{
		RGM_StPtr->PRST3.B.FLEXRAY_0_RST = enable;
	}
	else if(instance == 1U)
	{
		RGM_StPtr->PRST7.B.FLEXRAY_1_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_SENT_Rst(uint32_t instance,boolean enable)
{

	if(instance == 0U)
	{
		RGM_StPtr->PRST3.B.SENT_0_RST = enable;
	}
	else if(instance == 1U)
	{
		RGM_StPtr->PRST7.B.SENT_1_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_IIC_Rst(uint32_t instance,boolean enable)
{
	if(instance == 0U)
	{
		RGM_StPtr->PRST3.B.IIC_0_RST = enable;
	}
	else if(instance == 1U)
	{
		RGM_StPtr->PRST7.B.IIC_1_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_ADCSAR_Rst(uint32_t instance,boolean enable)
{
	status_t ret = STATUS_SUCCESS;
	switch(instance)
	{
	case 0:
		RGM_StPtr->PRST3.B.ADCSAR_0_RST = enable;
		break;
	case 1:
		RGM_StPtr->PRST7.B.ADCSAR_1_RST = enable;
		break;
	case 2:
		RGM_StPtr->PRST7.B.ADCSAR_2_RST = enable;
		break;
	case 3:
		RGM_StPtr->PRST7.B.ADCSAR_3_RST = enable;
		break;
	case 4:
		RGM_StPtr->PRST3.B.ADCSAR_4_RST = enable;
		break;
	case 5:
		RGM_StPtr->PRST7.B.ADCSAR_5_RST = enable;
		break;
	case 6:
		RGM_StPtr->PRST7.B.ADCSAR_6_RST = enable;
		break;
	case 7:
		RGM_StPtr->PRST7.B.ADCSAR_7_RST = enable;
		break;
	case 8:
		RGM_StPtr->PRST7.B.ADCSAR_8_RST = enable;
		break;
	case 9:
		RGM_StPtr->PRST7.B.ADCSAR_9_RST = enable;
		break;
	case 10:
		RGM_StPtr->PRST7.B.ADCSAR_10_RST = enable;
                break;
	case 0x0b:
		RGM_StPtr->PRST3.B.ADCSAR_b_RST = enable;
		break;
	default:
		ret = STATUS_ERROR;
                break;
	}

	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_GTMMINT_Rst(uint32_t instance,boolean enable)
{

	if(instance == 0U)
	{
		RGM_StPtr->PRST4.B.GTMINT_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_FCCU_Rst(uint32_t instance,boolean enable)
{

	if(instance == 0U)
	{
		RGM_StPtr->PRST5.B.FCCU_RST = enable;
	}
	else
	{
		return STATUS_ERROR;
	}

	return STATUS_SUCCESS;
}

/*
 * note:
 * It is important to clear the RGM_DES register before setting
 * any of the bits in the RGM_DERD register to '1'.
 * */
SAF_CORE_SEC_CODE
status_t RGM_LLD_SetDERD(destrutive_reset_name_t name,boolean enable)
{
	status_t ret = STATUS_SUCCESS;

	if(name == DEST_PORST)
	{
		RGM_StPtr->DERD.R |= RGM_PORST_DEST_MASK;
		RGM_StPtr->DERD.B.D_PORST = enable;
	}
	else
	{
		ret = STATUS_ERROR;
	}
	return ret;
}
//set the bit ,wait at least two peripheral clock periods
SAF_CORE_SEC_CODE
status_t RGM_LLD_SetDEAR(destrutive_reset_name_t name,alternate_request_t mode)
{
	status_t ret = STATUS_SUCCESS;
	if(name == DEST_PORST)
	{
		RGM_StPtr->DERD.B.D_PORST = 1;//An external power-on reset event  will not triggers a reset sequence
		if(mode == INT_REQ )
		{
			RGM_StPtr->DEAR.B.AR_PORST = 1;//Generate an interrupt request on an external power-on reset
            (void)INTC_LLD_Set_IRQ_Enable(MC_RGM_0_IRQn);
            (void)INTC_LLD_Set_IRQ_Priority(MC_RGM_0_IRQn, INTR_PRI_1);
		}
		else
		{
			RGM_StPtr->DEAR.B.AR_PORST = 0;//Generate an interrupt request on an external power-on reset
		}
	}
	else
	{
		ret = STATUS_ERROR;
	}
	return ret;
}

/*
 * note:
 * It is important to clear the RGM_FES register before setting
 * any of the bits in the RGM_FERD register to '1'.
 * */
SAF_CORE_SEC_CODE
status_t RGM_LLD_SetFERD(functional_reset_name_t name,boolean enable)
{
	status_t ret = STATUS_SUCCESS;
	switch(name)
	{
		case Func_VOR:
			RGM_StPtr->FES.R |= RGM_VOR_FUNC_MASK;
			RGM_StPtr->FERD.B.D_VOR_FUNC = enable;
			break;
		case Func_TSR:
			RGM_StPtr->FES.R |= RGM_TSR_FUNC_MASK;
			RGM_StPtr->FERD.B.D_TSR_FUNC = enable;
			break;
		case Func_ESR1:
			RGM_StPtr->FES.R |= RGM_ESR1_FUNC_MASK;
			RGM_StPtr->FERD.B.D_ESR1 = enable;
			break;
		default:
			ret = STATUS_ERROR;
			break;
	}
	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_SetFEAR(functional_reset_name_t name,alternate_request_t mode)
{
	status_t ret = STATUS_SUCCESS;
	if(name == Func_VOR)
	{
		RGM_StPtr->FERD.B.D_VOR_FUNC = 1;
		if(mode == INT_REQ )
		{
			RGM_StPtr->FEAR.B.AR_VOR_FUNC = 1;//Generate an interrupt request on an external power-on reset
            (void)INTC_LLD_Set_IRQ_Enable(MC_RGM_0_IRQn);
            (void)INTC_LLD_Set_IRQ_Priority(MC_RGM_0_IRQn, INTR_PRI_1);
		}
		else
		{
			RGM_StPtr->FEAR.B.AR_VOR_FUNC = 0;//Generate an interrupt request on an external power-on reset
		}
	}
	else if(name == Func_TSR)
	{
		RGM_StPtr->FERD.B.D_TSR_FUNC = 1;
		if(mode == INT_REQ )
		{
			RGM_StPtr->FEAR.B.AR_TSR_FUNC = 1;//Generate an interrupt request on an external power-on reset
        (void)INTC_LLD_Set_IRQ_Enable(MC_RGM_0_IRQn);
        (void)INTC_LLD_Set_IRQ_Priority(MC_RGM_0_IRQn, INTR_PRI_1);
		}
		else
		{
			RGM_StPtr->FEAR.B.AR_TSR_FUNC = 0;//Generate an interrupt request on an external power-on reset
		}
	}
	else
	{
		ret = STATUS_ERROR;
	}
	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_SetFBRE(functional_reset_name_t name,boolean isnot_esr0_assreted)
{
	status_t ret = STATUS_SUCCESS;
	switch(name)
	{
		case Func_VOR:
			RGM_StPtr->FBRE.B.BE_VOR_FUNC = isnot_esr0_assreted;
			break;
		case Func_TSR:
			RGM_StPtr->FBRE.B.BE_TSR_FUNC = isnot_esr0_assreted;
			break;
		case Func_HSM:
			RGM_StPtr->FBRE.B.BE_HSM_FUNC = isnot_esr0_assreted;
			break;
		case Func_JTAG:
			RGM_StPtr->FBRE.B.BE_JTAG_FUNC = isnot_esr0_assreted;
			break;
		case Func_FCCU_SOFT:
			RGM_StPtr->FBRE.B.BE_FCCU_SOFT = isnot_esr0_assreted;
			break;
		case Func_FCCU_HARD:
			RGM_StPtr->FBRE.B.BE_FCCU_HARD = isnot_esr0_assreted;
			break;
		case Func_SOFT:
			RGM_StPtr->FBRE.B.BE_FCCU_SOFT = isnot_esr0_assreted;
			break;
		case Func_ESR1:
			RGM_StPtr->FBRE.B.BE_ESR1 = isnot_esr0_assreted;
			break;
		default:
			ret = STATUS_ERROR;
			break;
	}

	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_SetFESS(functional_reset_name_t name,boolean enable)
{
	status_t ret = STATUS_SUCCESS;
	switch(name)
	{
		case Func_VOR:
			RGM_StPtr->FESS.B.SS_VOR_FUNC = enable;
			break;
		case Func_TSR:
			RGM_StPtr->FESS.B.SS_TSR_FUNC = enable;
			break;
		case Func_JTAG:
			RGM_StPtr->FESS.B.SS_JTAG_FUNC = enable;
			break;
		case Func_SOFT:
			RGM_StPtr->FESS.B.SS_SOFT_FUNC = enable;
			break;
		case Func_ESR0:
			RGM_StPtr->FESS.B.SS_ESR0 = enable;
			break;
		case Func_ESR1:
			RGM_StPtr->FESS.B.SS_ESR1 = enable;
			break;
		default:
			ret = STATUS_ERROR;
			break;
	}

	return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_SetDRET(boolean enable,uint8_t count)
{
	if(enable == TRUE)
	{
		RGM_StPtr->DRET.B.DRET = count;
	}
	else
	{
		RGM_StPtr->DRET.B.DRET = 0;
	}
	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_SetFRET(boolean enable,uint8_t count)
{
	if(enable == TRUE)
	{
		RGM_StPtr->FRET.B.FRET = count;
	}
	else
	{
		RGM_StPtr->FRET.B.FRET = 0;
	}
	return STATUS_SUCCESS;
}

SAF_CORE_SEC_CODE
void RGM_LLD_DESandFES(void)
{
	RGM_StPtr->DES.R = 0xffffffffUL;
	RGM_StPtr->FES.R = 0xffffffffUL;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_Config(rgm_manager_user_config_t const * config)
{
	uint32_t i =0;
	status_t ret = STATUS_SUCCESS;

	ret = RGM_LLD_SetDERD(config->DERD_PROST.DE_name,config->DERD_PROST.DE_enable);/*PRQA S 2982*/


    for(i = 0U; i < (uint8_t)RGM_FERD_COUNT; i++)
    {
    	ret = RGM_LLD_SetFERD(config->FERD[i].FERD_name,config->FERD[i].FE_enable);
    	if(ret != STATUS_SUCCESS)
    	{
    		return ret;
    	}
    }

    for(i = 0U; i < (uint8_t)RGM_FEAR_COUNT; i++)
    {
    	if(config->FEAR[i].FE_enable == TRUE){
			ret = RGM_LLD_SetFEAR(config->FEAR[i].FEAR_name,config->FEAR[i].mode);
			if(ret != STATUS_SUCCESS)
			{
				return ret;
			}
    	}
    }

    for(i = 0U; i < (uint8_t)RGM_FBRE_COUNT; i++)
    {
		ret = RGM_LLD_SetFBRE(config->FBRE[i].FB_name,config->FBRE[i].isnot_esr0_assreted);
		if(ret != STATUS_SUCCESS)
		{
			return ret;
		}
    }
    for(i = 0U; i < (uint8_t)RGM_FESS_COUNT; i++)
    {
		ret = RGM_LLD_SetFESS(config->FESS[i].FESS_name,config->FESS[i].FESS_name);/*PRQA S 1431,4424*/
		if(ret != STATUS_SUCCESS)
		{
			return ret;
		}
    }

    ret = RGM_LLD_SetDRET(config->DRET.DE_enable,config->DRET.threholdcount);/*PRQA S 2982*/

    ret = RGM_LLD_SetFRET(config->FRET.FE_enable,config->FRET.threholdcount);

    return ret;
}

SAF_CORE_SEC_CODE
status_t RGM_LLD_SetPRST(individual_PR_name_t peripheral_name,uint32_t instance,boolean enable)
{
	status_t ret = STATUS_SUCCESS;
	switch(peripheral_name)
	{
		case PIT_RTC_RST:
			ret = RGM_LLD_PITRTC_Rst(instance,enable);
			break;
		case SIUL_RST:
			ret = RGM_LLD_SIUL_Rst(instance,enable);
			break;
		case SIPI_RST:
			ret = RGM_LLD_SIPI_Rst(instance,enable);
			break;
		case LFAST_RST:
			ret = RGM_LLD_LFAST_Rst(instance,enable);
			break;
		case EBI_RST:
			ret = RGM_LLD_EBI_Rst(instance,enable);
			break;
		case ADCSD_RST:
			ret = RGM_LLD_ADCSD_Rst(instance, enable);
			break;
		case CRC_RST:
			ret = RGM_LLD_CRC_Rst(instance, enable);
			break;
		case DMAMUX_RST:
			ret = RGM_LLD_DMAMUX_Rst(instance,enable);
			break;
		case DSPI_RST:
			ret = RGM_LLD_DSPI_Rst(instance,enable);
			break;
		case LINFlexeD_RST:
			ret = RGM_LLD_LINFlexd_Rst(instance,enable);
			break;
		case CAN_RAM_CTR_RST:
			ret = RGM_CANRAMCTR_Rst(instance,enable);
			break;
		case TTCAN_RST:
			ret = RGM_LLD_TTCAN_Rst(instance,enable);
			break;
		case MCAN_RST:
			ret = RGM_LLD_MCAN_Rst(instance,enable);
			break;
		case PSI5_RST:
			ret = RGM_LLD_PSI5_Rst((PSI5_name_t)instance,enable);/*PRQA S 1441,4442*/
			break;
		case ADCSAR_RST:
			ret = RGM_LLD_ADCSAR_Rst(instance,enable);
			break;
		case FLEXRAY_RST:
			ret = RGM_LLD_FlexRay_Rst(instance,enable);
			break;
		case SENT_RST:
			ret = RGM_LLD_SENT_Rst(instance,enable);
			break;
		case IIC_RST:
			ret = RGM_IIC_Rst(instance,enable);
			break;
		case GTMINT_RST:
			ret = RGM_LLD_GTMMINT_Rst(instance,enable);
			break;
		case FCCU_RST:
			ret = RGM_LLD_FCCU_Rst(instance,enable);
			break;
		default:
			ret = STATUS_ERROR;
                        break;
	}

	return ret;
}

