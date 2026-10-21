#include "IoHwAbs_ADC.h"
#include "Can_GeneralTypes.h"
#include "Mcu.h"
#include "EvptCdd_TPT1145.h"
#include "Evpt_BswM.h"
#include "Evpt_EcuM.h"
#include "Evpt_System.h"
#include "IoHwAbs_ADC_Prv.h"
#include "IoHwAbs_UART.h"
#include "Pwm3ph.h"
#include "port.h"
#include "Gpt.h"
#include "eDma.h"
#include "eMIOS.h"
#include "Adc3ph.h"
#include "SDAdc.h"
#include "RdcDrv.h"
#include "CanIf.h"
#include "Can.h"
#include "Spi.h"
#include "SchM_Can.h"
#include "LinDrv_Transmit_Prv.h"
#include "Cdd_Sa47301.h"
#include "IoHwAbs_PWM_Prv.h"
#include "Cdd_Imu_Control.h"
#include "IoHwAbs_ICU_prv.h"
#include "IoHwAbs_DIO_prv.h"
#include "Motor_Diag.h"
#include "NvM.h"
#include "Fee.h"
#include "Fls.h"
#include "Nvm_BlockCallback.h"
#include "Cdd_Afe_Manage.h"
#include "VX1000If.h"
#include "Nvm_prv.h"
#include "EcuM.h"
#include "EcuM_Callout_Init.h"
#include "Com.h"
#include "ComM.h"
#include "PduR.h"
#include "CanSM.h"
#include "CanNm.h"
#include "CanTp.h"
#include "LinIf.h"
#include "LinSM.h"
#include "J1939Tp.h"
#include "FiM.h"
#include "Nm.h"
#include "Cdd_Afe_Manage.h"
#include "Motor_HwIf.h"
#include "Evpt_InterDataWatch_Prv.h"
#include "Cdd_Tle9018_Driver.h"
#include "SecuAlgo.h"

#define ECUM_DELAY_1sCNT (200)


FUNC(void, ECUM_CODE) EcuM_DriverInit_core0(void)
{
    Gpt_Init(&GptChannelConfigSet);
	GPT_Gtm_Init(&Gpt_Gtm_Cmu_PBCfg);
	Port_Init(&PortContainer);
	IoHwAbs_Pwm_Init();
	EDMA_Init(&EDma_Config);
	eMIOS_Init(&eMIOS_Config);
	Spi_Init(&Spi_Configuration);
	IoHwAbs_UART_Init(); 

	IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_SEPIC_EN, 1); 
	IoHwAbs_ADC_Init();
	IoHwAbs_Icu_Init();
	Adc3ph_Init(3);
	Adc3ph_Init(0); //功能安全 电流采集
	Adc3ph_SetFifoMode();
	Dem_PreInit();
	Cdd_Sbc_Sa47301_InitFunction(); 
	CanTrcv_Init();
	if( Cdd_sbc_Sa47301_GetWakePinLevelStatusFunction()== false)
	(void)CanTrcv_ProcessKL30WakeupPowerDown(EcuM_OnGoOffTwo);
	Fls_Init(&Fls_Config);
	Fee_Init(NULL_PTR);
	NvM_Init(NULL_PTR);
    NvM_SetRamUserBlockStatus();
    Cdd_Imu_Init();
	SIUL.PCR[145].R = 0xdc; 
	SIUL.PCR[210].R = 0xdc; 
	SIUL.GPDO[210].B.PDO = 1;//功能安全使能 暂时默认打开
    IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_DO_9015_SLEEP, TRUE);
    IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_DO_9015_ERRQ_RES, TRUE);

	IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_HB_EN, TRUE);			//Half Bridge Enable
	IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_HV_5V_EN, TRUE);		//Driver HV 5V Enable

	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_UBR_CTL, 1); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_Driver_5V_EN, TRUE);	//Driver5V Enable

	extern void IoHwAbs_TOM_TrigAdc_Func();
	IoHwAbs_TOM_TrigAdc_Func();

	SecuAlgo_Init();

	Motor_Diag_Init();
	FiM_Init(NULL_PTR);
	Dcm_Init(NULL_PTR);
	// Dem_Init(NULL_PTR);//Dem_Init  need to be do after  Mem_Nvm_ReadAll
	Evpt_DiagDb_Init();
}

FUNC(void, ECUM_CODE) EcuM_DriverInit_core1(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
	Os_Monitor_init();
}

FUNC(void, ECUM_CODE) EcuM_DriverInit_core2(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
    Cdd_Afe_InitFunction();
}

FUNC(void, ECUM_CODE) EcuM_DriverInit_core3(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
	//Adc3ph_Init();
	Sdadc_Init(&SdAdc_TotalConfig); 
	RdcDrv_DevInit();
	Pwm3ph_SetPwmAtomCfg();
	Icu_ConfigCmuClk_Func();
}

FUNC(void, ECUM_CODE) EcuM_DriverInit_core4(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */
#ifndef CAN_TEST_CFG_H_
	MCAN_Type *g_mcanBase_init[6] = {MCAN_7_P, MCAN_2_P, MCAN_9_P, MCAN_1_P, MCAN_6_P,  MCAN_11_P};
#else
	MCAN_Type *g_mcanBase_init[7] = {MCAN_7_P, MCAN_2_P, MCAN_3_P, MCAN_9_P, MCAN_1_P, MCAN_6_P,  MCAN_11_P};
#endif
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN3_STB, 0); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN4_STB, 0); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN5_STB, 0); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN6_STB, 0); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN7_STB, 0); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_CAN_5V_EN, 1); 
	CanIf_Init(NULL_PTR);
	Can_Init(&Can_Config);
#ifndef CAN_TEST_CFG_H_
	for(uint8 i = 0; i < 6; i++)
	{
		CanIf_SetControllerMode(i, CANIF_CS_STARTED);
		CanIf_SetPduMode(i, CANIF_ONLINE);
	}
	for(uint8 i = 0; i < 6; i++)
	{
		SchM_Enter_Can_EXCLUSIVE_AREA_13();
		g_mcanBase_init[i]->IE.B.RF0WE = 0;
		g_mcanBase_init[i]->IE.B.TCFE = 0;
		g_mcanBase_init[i]->IE.B.BOE = 1;
		g_mcanBase_init[i]->ILS.B.BOL = 1;
		g_mcanBase_init[i]->ILE.B.EINT1 = 1;
		SchM_Exit_Can_EXCLUSIVE_AREA_13();
	}
#else
	for(uint8 i = 0; i < 7; i++)
	{
		Can_SetControllerMode(i, CANIF_CS_STARTED);
	}
	for(uint8 i = 0; i < 7; i++)
	{
		SchM_Enter_Can_EXCLUSIVE_AREA_13();
		g_mcanBase_init[i]->IE.B.RF0WE = 0;
		g_mcanBase_init[i]->IE.B.TCFE = 0;
		g_mcanBase_init[i]->IE.B.BOE = 1;
		g_mcanBase_init[i]->ILS.B.BOL = 1;
		g_mcanBase_init[i]->ILE.B.EINT1 = 1;
		SchM_Exit_Can_EXCLUSIVE_AREA_13();
	}
#endif
	LinIf_Init(NULL_PTR);
    LinSM_Init(NULL_PTR);
	LINDrv_Init();
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_LIN_EN, 1);
	
	VX1000If_InitMemory();
	VX1000If_Init();
	VX1000If_InitAsyncStart();
	VX1000If_InitAsyncEnd();

	Nm_Init(NULL_PTR);
	CanNm_Init(NULL_PTR);

    PduR_Init(&PduR_PBConfigTable);

    Com_Init(NULL_PTR);

    CanSM_Init(NULL_PTR);
    ComM_Init(NULL_PTR);

	CanTp_Init(NULL_PTR);
    J1939Tp_Init(NULL_PTR);
}
extern Tle9018_DevType Afe_valDev_Mp;
extern void Tle9018_SetEmmMask(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
FUNC(void, ECUM_CODE) EcuM_DriverInit_core5(void){  /* PRQA S 3408 */ /* NSCA_QAC_EcuM_8.4 */

}


FUNC(void, ECUM_CODE) EcuM_PwerOff(void)
{
    uint32 EcuM_delayCnt1 = 0;
    uint32 EcuM_delayCnt2 = 0;
    const uint32 EcuM_delayCnt_limit = ECUM_DELAY_1sCNT;
    CanTrcv_TrcvModeType TrcvMode1 = CANTRCV_TRCVMODE_NORMAL;
    CanTrcv_TrcvModeType TrcvMode2 = CANTRCV_TRCVMODE_NORMAL;
    uint8 i = 0;
    uint8 seg_cnt = 0;
    uint8 port = 0;
	uint32 numErrorCnt_Mp = 0;
    
    seg_cnt = Afe_valDev_Mp.link_state.segment_count;
    Cdd_Afe_GoToSleep();

  if( ECUM_CORE_ID_MASTER == GetCoreID() )
  {
        Mem_Nvm_WriteAll();
        while((CANTRCV_TRCVMODE_SLEEP != TrcvMode1))
        {    
	        CanTrcv_TPT1145_MainFunction_10ms();
            (void)CanTrcv_GetOpMode(0, &TrcvMode1);

            if(CANTRCV_TRCVMODE_STANDBY == TrcvMode1)
            {
                BswM_TPT1145_NORMAL();
            }else if ((CANTRCV_TRCVMODE_NORMAL == TrcvMode1))
            {
                BswM_TPT1145_SLEEP();
            }
            EcuM_delayCnt1++;
            if(EcuM_delayCnt1 >= EcuM_delayCnt_limit)
            {
                break;
            }
        }
        while((CANTRCV_TRCVMODE_SLEEP != TrcvMode2))
        {    
	        CanTrcv_TPT1145_MainFunction_10ms();
            (void)CanTrcv_GetOpMode(1, &TrcvMode2);
            
            if(CANTRCV_TRCVMODE_STANDBY == TrcvMode2)
            {
                BswM_TPT1145_NORMAL();
            }else if ((CANTRCV_TRCVMODE_NORMAL == TrcvMode2))
            {
                BswM_TPT1145_SLEEP();
            }
            EcuM_delayCnt2++;
            if(EcuM_delayCnt2 >= EcuM_delayCnt_limit)
            {
                break;
            }
        }
        IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_DO_9015_ERRQ_RES, FALSE);
        IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_DO_9015_SLEEP, FALSE);
        uint16 valKeyOn_Lo = 0;
        uint16 valAPlus1Volt_Lo = 0;
        uint16 valAPlus2Volt_Lo = 0;
        uint16 valAFEVolt_Lo = 0;
        uint16 valOBCVolt_Lo = 0;
        IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_AN_KEY_Mic,&valKeyOn_Lo);
        IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_DC_APlus1_Mic, &valAPlus1Volt_Lo);
        IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_DC_APlus2_Mic, &valAPlus2Volt_Lo);
        IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_9015_ERRQ, &valAFEVolt_Lo);
        IoHwAbs_ADC_GetChannelRawValue(IOHWABS_ADC_CHANNEL_AN_OBC_ON_Mic, &valOBCVolt_Lo);
        if(valKeyOn_Lo > 6000 || valAPlus1Volt_Lo > 6000 || valAPlus2Volt_Lo > 6000 \
                || valAFEVolt_Lo > 6000 || valOBCVolt_Lo > 6000)
        {
            Mcu_PerformReset();


        }
		Cdd_Sbc_Sa47301_SetWakeStatusFunction(Sys_tiWakeTimeEn);
        Cdd_Sbc_Sa47301_SetWakeTimeFunction(Sys_tiWakeTime);
        Cdd_Sbc_Sa47301_SetPowerOffFunction();
        while (1)/* WangM */
        {
			numErrorCnt_Mp++;
			if(numErrorCnt_Mp > 4000000)
			{
				Mcu_PerformReset();
			}
        }
    }
    else
    {
        //do nothing
    }

}
