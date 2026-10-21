#include "Nvm_prv.h"
#include "EvptCdd_TPT1145.h"
#include "Can_GeneralTypes.h"
#include "Can.h"
#include "Rte_CanIf_Type.h"
#include "IoHwAbs_DIO_prv.h"
#include "IoHwAbs_ICU_prv.h"
#include "IoHwAbs_ADC_Prv.h"
#include "IoHwAbs_ADC_Filter.h"
#include "Dem.h"
FUNC(void, BSWM_CODE) BswM_TPT1145_NORMAL(void)
{				    
	(void)CanTrcv_SetOpMode(0,CANTRCV_TRCVMODE_NORMAL);
	(void)CanTrcv_SetOpMode(1,CANTRCV_TRCVMODE_NORMAL);
    (void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN3_STB, 0); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN4_STB, 0); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN5_STB, 0); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN6_STB, 0); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN7_STB, 0); 
}

FUNC(void, BSWM_CODE) BswM_TPT1145_SLEEP(void)
{				    
	(void)CanTrcv_SetOpMode(0,CANTRCV_TRCVMODE_SLEEP);
	(void)CanTrcv_SetOpMode(1,CANTRCV_TRCVMODE_SLEEP);
    (void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN3_STB, 1); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN4_STB, 1); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN5_STB, 1); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN6_STB, 1); 
	(void)IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_CAN7_STB, 1); 

}

FUNC(void, BSWM_CODE) BswM_CanIf_NORMAL(void)
{				    
   Can_SetControllerMode(0, CANIF_CS_STARTED);	
   Can_SetControllerMode(1, CANIF_CS_STARTED);
   Can_SetControllerMode(2, CANIF_CS_STARTED);
   Can_SetControllerMode(3, CANIF_CS_STARTED);
   Can_SetControllerMode(4, CANIF_CS_STARTED);
   Can_SetControllerMode(5, CANIF_CS_STARTED);
   Can_SetControllerMode(6, CANIF_CS_STARTED);
}


FUNC(void, BSWM_CODE) BswM_CanIf_SLEEP(void)
{				    
   Can_SetControllerMode(0, CANIF_CS_STOPPED);	
   Can_SetControllerMode(1, CANIF_CS_STOPPED);
   Can_SetControllerMode(2, CANIF_CS_STOPPED);
   Can_SetControllerMode(3, CANIF_CS_STOPPED);
   Can_SetControllerMode(4, CANIF_CS_STOPPED);
   Can_SetControllerMode(5, CANIF_CS_STOPPED);
   Can_SetControllerMode(6, CANIF_CS_STOPPED);
}

FUNC(void, BSWM_CODE) BswM_Nvm_WriteAll(void)
{
	Mem_Nvm_WriteAll();
}

/*  BSWM actual execution code; */
/*  Content and order require approval for changes; */

FUNC(void, BSWM_CODE) BswM_Nvm_ReadAll(void)
{
	Mem_Nvm_ReadAll();
}


extern void Cdd_Sbc_Sa47301_GetWKSFRegValueFunction(void);
# if ((CANTRCV_CFG_WAKEUP_BY_NODE_USED == STD_ON) || ( CANTRCV_CFG_SPI_TPT1145_USED == STD_ON ))
extern void            CanTrcv_TPT1145_MainFunction_10ms( void );
# endif
FUNC(void, BSWM_CODE) InitToRun_Action(void)
{
	static uint8 Init_fgAct_log = 0;
	if(Init_fgAct_log == 0)
	{
		IoHwAbs_DIO_MainFunction();
		IoHwAbs_Icu_MainFunction();
		IoHwAbs_ADC_MainFunction();
		IoHwAbs_ADC_ReFileterValue();
        for(uint8 i = 0;i < 2;i++)
        {
            CanTrcv_TPT1145_MainFunction_10ms();
        }
		// CanTrcv_TPT1145_MainFunction_10ms();
		Cdd_Sbc_Sa47301_GetWKSFRegValueFunction();
		Init_fgAct_log = 1;
	}
}

FUNC(void, BSWM_CODE) RunToPostRun_Action(void)
{
	BswM_CanIf_SLEEP();
	BswM_TPT1145_SLEEP();
}

FUNC(void, BSWM_CODE) PostRunToRun_Action(void)
{
	BswM_TPT1145_NORMAL();
    BswM_CanIf_NORMAL();
}

FUNC(void, BSWM_CODE) PostRunToShutdown_Action(void)
{
	
}

FUNC(void, BSWM_CODE) SoftReset_Action(void)
{
	
}

FUNC(void, BSWM_CODE) BootReset_Action(void)
{
	
}

FUNC(void, BSWM_CODE) HardReset_Action(void)
{
	
}
