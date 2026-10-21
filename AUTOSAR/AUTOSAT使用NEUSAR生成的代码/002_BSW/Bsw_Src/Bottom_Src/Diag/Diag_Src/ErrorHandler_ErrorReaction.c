/**********************************************************************************************************************
*
* COPYRIGHT RESERVED, Tianjin Yidingfeng Power Technology, 2012. All rights reserved.
* The reproduction, distribution and utilization of this document as well as the communication of its contents to
* others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
* All rights reserved in the event of the grant of a patent, utility model or design.
*
**********************************************************************************************************************
* Administrative Information
* Namespace_:
* Class_____:C
* Name______:ErrorDiag_Swc
* Variant___:75.16.01
* Revision__:0
**********************************************************************************************************************
 * History___:
 *
 * 75.16.01; 0     10.04.2024 SH-RD  Xiangyu.Zhu
 *   N: new created
 *
 * 
 * 
 * 
***********************************************************************************************************************/

#include "Platform_Types.h"
#ifdef FUNC_SAFETY
#include "fccu_lld.h"
#endif
#include "Mcu.h"
#include "ErrorHandler_ErrorReaction.h"
#include "ErrorDiag_Swc.h"
#include "ErrorHandler_ReactionCfg.h"
#include "ErrorHandler_Swc.h"
#if (EH_CFG_NO_L2_SHUTDOWN == STD_OFF)
#include "IoHwAbs_DIO_prv.h"
#endif



#define ERRORDIAG_START_SEC_VAR_CLEAR_ASIL_C_8
#include "ErrorDiag_MemMap.h"
static boolean wdgResetRequested;
#define ERRORDIAG_STOP_SEC_VAR_CLEAR_ASIL_C_8
#include "ErrorDiag_MemMap.h"


#define ERRORDIAG_START_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"


#if (EH_L2_ENABLE_NUM > 0 && EH_CFG_NO_L2_SHUTDOWN == STD_OFF)
static void ErrorHandler_SetL2Enable(uint16 l2channel, boolean enable) {
	uint8 drvOff = enable ? 0u : 1u;

	switch (l2channel) {
		case L2_DIS_DC:
			// MCU_DC_EN6
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_DC_EN6, enable);
			EH_SetL2DriverOff(L2_DIS_DC, drvOff);
			break;
		case L2_DIS_BLDC1:
			// MCU_BLDC1_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_BLDC1_EN, enable);
			EH_SetL2DriverOff(L2_DIS_BLDC1, drvOff);
			break;
		case L2_DIS_BLDC2:
			// MCU_BLDC2_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_BLDC2_EN, enable);
			EH_SetL2DriverOff(L2_DIS_BLDC2, drvOff);
			break;

		case L2_DIS_HS1:
			// MCU_D_HS11_SEn, MCU_D_LS1-4_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_HS11_SEn, enable);
			EH_SetL2DriverOff(L2_DIS_HS1, drvOff);
		case L2_DIS_LS1_4:
			// MCU_D_LS1-4_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_LS1_4_EN, enable);
			EH_SetL2DriverOff(L2_DIS_LS1_4, drvOff);
			break;

		case L2_DIS_HS2:
			// MCU_D_HS12_SEn, MCU_D_LS5-8_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_HS12_SEn, enable);
			EH_SetL2DriverOff(L2_DIS_HS2, drvOff);
		case L2_DIS_LS5_8:
			// MCU_D_LS5-8_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_LS5_8_EN, enable);
			EH_SetL2DriverOff(L2_DIS_LS5_8, drvOff);
			break;

		case L2_DIS_HS3:
			// MCU_D_HS13_SEn, MCU_D_LS9-12_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_HS13_SEn, enable);
			EH_SetL2DriverOff(L2_DIS_HS3, drvOff);
		case L2_DIS_LS9_12:
			// MCU_D_LS9-12_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_LS9_12_EN, enable);
			EH_SetL2DriverOff(L2_DIS_LS9_12, drvOff);
			break;

		case L2_DIS_HS4:
			// MCU_D_HS14_SEn, MCU_D_LS13-14_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_HS14_SEn, enable);
			EH_SetL2DriverOff(L2_DIS_HS4, drvOff);
		case L2_DIS_LS13_16:
			// MCU_D_LS13-14_EN
			IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_LS13_14_EN, enable);
			EH_SetL2DriverOff(L2_DIS_LS13_16, drvOff);
			break;
	}
}
#endif


void ErrorHandler_Callback_PerformHwReset(uint16 errorId)
{
	(void) errorId;
}



void ErrorHandler_Callback_PerformSwReset(uint16 errorId)
{
	(void) errorId;
	Mcu_PerformReset();
}


void ErrorHandler_Callback_PerformWdgReset(uint16 errorId)
{
	(void) errorId;

	if (wdgResetRequested == TRUE) {
		return;
	}

	// TODO: NVM write
	// TODO: watchdog reset

	wdgResetRequested = TRUE;
}


void ErrorHandler_Callback_SetErrorPin(uint16 errorId)
{
	(void) errorId;
#ifdef FUNC_SAFETY
	/* enter CONFIG state */
	(void)SAF_FCCU_LLD_SetConfigState();
	/* EOUT goes to faulty */
	FCCU.CFG.B.FCCU_SET_CLEAR = (uint8)1u;
	/* exit CONFIG state */
	(void)SAF_FCCU_LLD_SetNormalState();
#endif
}


void ErrorHandler_Callback_ResetErrorPin(uint16 errorId)
{
	(void) errorId;
#ifdef FUNC_SAFETY
	/* enter CONFIG state */
	(void)SAF_FCCU_LLD_SetConfigState();
	/* EOUT goes to software independant mode */
	FCCU.CFG.B.FCCU_SET_CLEAR = (uint8)0u;
	/* exit CONFIG state */
	(void)SAF_FCCU_LLD_SetNormalState();
#endif
}


void ErrorHandler_Callback_DisDriver(uint16 errorId)
{
#if (EH_DRIVER_SUPPRESS_NUM > 0)
	uint8 i = 0u;
	uint8 SuppLength = 0;
	uint16 SuppressChannel = 0;

	if (errorId < ERRORDIAG_ID_NUM_BSW)
	{
		SuppLength = EH_Reaction_Cfg[errorId].DriverSuppressLen;
		for (i = 0u; i < SuppLength; i++)
		{
			SuppressChannel = EH_DrvSuppress_Cfg[EH_Reaction_Cfg[errorId].DriverSuppressIdx][i];
			if (SuppressChannel < EH_DRIVER_SUPPRESS_CHANNEL_NUM)
			{
				EH_DrvRefCounterInc(SuppressChannel);
				EH_SetOutputDisFlag(SuppressChannel, TRUE);
			}
			else
			{
				/* Do nothing */
			}
		}
	}
	else
	{
		/* Do nothing */
	}
#endif
}


void ErrorHandler_Callback_EnDriver(uint16 errorId)
{
#if (EH_DRIVER_SUPPRESS_NUM > 0)
	uint8 i = 0u;
	uint8 SuppLength = 0;
	uint16 SuppressChannel = 0;

	if (errorId < ERRORDIAG_ID_NUM_BSW)
	{
		SuppLength = EH_Reaction_Cfg[errorId].DriverSuppressLen;
		for (i = 0u; i < SuppLength; i++)
		{
			SuppressChannel = EH_DrvSuppress_Cfg[EH_Reaction_Cfg[errorId].DriverSuppressIdx][i];
			if (SuppressChannel < EH_DRIVER_SUPPRESS_CHANNEL_NUM)
			{
				EH_DrvRefCounterDec(SuppressChannel);
				if (EH_GetDrvRefCounter(SuppressChannel) == 0u) {
					EH_SetOutputDisFlag(SuppressChannel, FALSE);
				}
			}
			else
			{
				/* Do nothing */
			}
		}
	}
	else
	{
		/* Do nothing */
	}
#endif
}


void ErrorHandler_Callback_L2Disable(uint16 errorId)
{
#if (EH_L2_ENABLE_NUM > 0 && EH_CFG_NO_L2_SHUTDOWN == STD_OFF)
	uint8 i = 0u;
	uint8 disLength = 0;
	uint16 disChannel = 0;

	if (errorId < ERRORDIAG_ID_NUM_BSW)
	{
		disLength = EH_Reaction_Cfg[errorId].DriverSuppressLen;
		for (i = 0u; i < disLength; i++)
		{
			disChannel = EH_L2Suppress_Cfg[EH_Reaction_Cfg[errorId].DriverSuppressIdx][i];
			if (disChannel < L2_DIS_NUM_MAX)
			{
				EH_L2RefCounterInc(disChannel);
				ErrorHandler_SetL2Enable(disChannel, FALSE);
			}
		}
	}
#endif
}


void ErrorHandler_Callback_L2Enable(uint16 errorId)
{
#if (EH_L2_ENABLE_NUM > 0 && EH_CFG_NO_L2_SHUTDOWN == STD_OFF)
	uint8 i = 0u;
	uint8 disLength = 0;
	uint16 disChannel = 0;

	if (errorId < ERRORDIAG_ID_NUM_BSW)
	{
		disLength = EH_Reaction_Cfg[errorId].DriverSuppressLen;
		for (i = 0u; i < disLength; i++)
		{
			disChannel = EH_L2Suppress_Cfg[EH_Reaction_Cfg[errorId].DriverSuppressIdx][i];
			if (disChannel < L2_DIS_NUM_MAX)
			{
				EH_L2RefCounterDec(disChannel);
				if (EH_GetL2RefCounter(disChannel) == 0u) {
					ErrorHandler_SetL2Enable(disChannel, TRUE);
				}
			}
		}
	}
#endif
}


#define ERRORDIAG_STOP_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"
