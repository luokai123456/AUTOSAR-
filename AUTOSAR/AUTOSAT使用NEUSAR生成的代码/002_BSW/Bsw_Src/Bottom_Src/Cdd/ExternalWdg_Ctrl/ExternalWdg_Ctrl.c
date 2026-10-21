
#include "ExternalWdg_Ctrl.h"
#include "Cdd_Sa47301_Reg.h"
#include "Cdd_Sa47301_Com.h"

const SA_47301_FwdResponse_Type SA_47301_FwdResponseTbl[16] =
{
/* QUESTION */ /* RESP3, RESP2, RESP1, RESP0 */
/*     0    */  { 0xFFu, 0x0Fu, 0xF0u, 0x00u },
/*     1    */  { 0xB0u, 0x40u, 0xBFu, 0x4Fu },
/*     2    */  { 0xE9u, 0x19u, 0xE6u, 0x16u },
/*     3    */  { 0xA6u, 0x56u, 0xA9u, 0x59u },
/*     4    */  { 0x75u, 0x85u, 0x7Au, 0x8Au },
/*     5    */  { 0x3Au, 0xCAu, 0x35u, 0xC5u },
/*     6    */  { 0x63u, 0x93u, 0x6Cu, 0x9Cu },
/*     7    */  { 0x2Cu, 0xDCu, 0x23u, 0xD3u },
/*     8    */  { 0xD2u, 0x22u, 0xDDu, 0x2Du },
/*     9    */  { 0x9Du, 0x6Du, 0x92u, 0x62u },
/*     A    */  { 0xC4u, 0x34u, 0xCBu, 0x3Bu },
/*     B    */  { 0x8Bu, 0x7Bu, 0x84u, 0x74u },
/*     C    */  { 0x58u, 0xA8u, 0x57u, 0xA7u },
/*     D    */  { 0x17u, 0xE7u, 0x18u, 0xE8u },
/*     E    */  { 0x4Eu, 0xBEu, 0x41u, 0xB1u },
/*     F    */  { 0x01u, 0xF1u, 0x0Eu, 0xFEu }
};
uint8 Wdg_30_Sbc_Timer_permissionCounter = 4;
uint8 Wdg_30_Sbc_ResetWdgFlag = 1;

uint16 ExternalWdg_Ctrl_Init(void)
{
	uint16 valSpiRxBuf_Lo = 0;
	uint16 valSpiTxBuf_Lo = 0x96;
	uint16 valRet_Lo = FAILED;

	Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_WTITE,SA_WDCFG0_ADDR,valSpiTxBuf_Lo);
	Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_READ,SA_WDCFG0_ADDR,0);
	valSpiRxBuf_Lo = SpiDataInfo.RxFrame.BITS.DATA ^ 0xFFFF;
	// valSpiRxBuf_Lo  ^= 0xFFFF;
	if(((valSpiRxBuf_Lo >> 1) & 0xFF) == valSpiTxBuf_Lo)
	{
		valRet_Lo = SUCCESSFUL;
	}

	valRet_Lo = FAILED;

	Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_WTITE,SA_FWDCFG_ADDR,EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_900WD);
	Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_READ,SA_FWDCFG_ADDR,0);
	valSpiRxBuf_Lo  = ~(SpiDataInfo.RxFrame.BITS.DATA);
	if(((valSpiRxBuf_Lo) & 0x1F) == EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_900WD)
	{
		valRet_Lo = SUCCESSFUL;
	}

	ExternalWdg_FeedFWD_Function();
	return valRet_Lo;
}

void ExternalWdg_FeedFWD_Function(void)
{
	uint16 valSpiRxBuf1_Lo = 0;
	uint16 valSpiRxBuf2_Lo = 0;
	uint16 fwdquest_val = 0;
	if(Wdg_30_Sbc_Timer_permissionCounter >= 1)
    {
        Wdg_30_Sbc_Timer_permissionCounter --;
    }

	if((Wdg_30_Sbc_Timer_permissionCounter > 0)&&(Wdg_30_Sbc_ResetWdgFlag == 1))
	{
		Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_READ,SA_FWDRSPOK_ADDR,0);
		fwdquest_val = ((SpiDataInfo.RxFrame.BITS.DATA) & 0x0F);

		Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_WTITE,SA_FWDRSP_ADDR,SA_47301_FwdResponseTbl[fwdquest_val].RESP3);
		Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_READ,SA_FWDRSPOK_ADDR,0);

		Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_WTITE,SA_FWDRSP_ADDR,SA_47301_FwdResponseTbl[fwdquest_val].RESP2);
		Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_READ,SA_FWDRSPOK_ADDR,0);

		Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_WTITE,SA_FWDRSP_ADDR,SA_47301_FwdResponseTbl[fwdquest_val].RESP1);
		Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_READ,SA_FWDRSPOK_ADDR,0);

		Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_WTITE,SA_FWDRSPSYNC_ADDR,SA_47301_FwdResponseTbl[fwdquest_val].RESP0);
		Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_READ,SA_FWDRSPOK_ADDR,0);
	}
}
void Wdg30_Sbc_Timer_SetTimeout(void)
{
	Wdg_30_Sbc_Timer_permissionCounter = 0;
}

void Wdg30_Sbc_ExtWdgReset(void)
{
	Wdg_30_Sbc_ResetWdgFlag = 0;
}

uint16 STATE_val = 0;
uint16 FWDErrorCounter = 0;
uint16 FWDEnStatus = 0;
uint32 Sbc_NomMode_Cunt = 0;
uint32 Sbc_InitMode_Cunt = 0;
void SA47031_CONDITION_Function(void)
{
	uint16 valSpiRxBuf1_Lo = 0;
	uint16 valSpiRxBuf2_Lo = 0;

	Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SPI_READ,SA_DEVSTAT_ADDR,0);
	STATE_val = ((SpiDataInfo.RxFrame.BITS.DATA) & SA_STATE_MASK);

	Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SPI_READ,SA_FWDSTAT1_ADDR,0);
	FWDErrorCounter = (uint16)((SpiDataInfo.RxFrame.BITS.DATA) & 0x0F);

	Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SPI_READ,SA_REG_INITERROR_TAG,0);
	FWDEnStatus = (uint16)((SpiDataInfo.RxFrame.BITS.DATA));

	if(STATE_val == 2)
	{
	    Sbc_NomMode_Cunt++;
	}
	else if(STATE_val == 1)
	{
	    Sbc_InitMode_Cunt++;
	}
	else
	{
	    ;
	}
}

