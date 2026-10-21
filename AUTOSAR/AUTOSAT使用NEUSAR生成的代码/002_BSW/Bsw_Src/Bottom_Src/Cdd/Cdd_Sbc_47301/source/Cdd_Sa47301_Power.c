#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301_Power.h"
#include "Cdd_Sa47301_Reg.h"
#include "Cdd_Sa47301_Type.h"
#include "Cdd_Sa47301_Com.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_POWER_C             4
#define SA47301_AR_REL_MINOR_VER_POWER_C             4
#define SA47301_AR_REL_REV_VER_POWER_C               0
#define SA47301_SW_MAJOR_VER_POWER_C                 1
#define SA47301_SW_MINOR_VER_POWER_C                 0
#define SA47301_SW_PATCH_VER_POWER_C                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_POWER_C != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_POWER_C"
#endif
#if (SA47301_AR_REL_MINOR_VER_POWER_C != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_POWER_C"
#endif
#if (SA47301_AR_REL_REV_VER_POWER_C != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_POWER_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_POWER_C != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_POWER_C"
#endif
#if (SA47301_SW_MINOR_VER_POWER_C != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_POWER_C"
#endif
#if (SA47301_SW_PATCH_VER_POWER_C != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_POWER_C"
#endif

extern Cdd_SA47301_RegInfoType SA47301_RegDataInfo_Mp[SA_REG_NUM_MAX];
extern Cdd_Sa47301SpiInfo_TDSTR SpiDataInfo;
extern Cdd_Sa47301ConfigType_TDSTR Cdd_Sa47301_Config;

Std_ReturnType Cdd_Sbc_Sa47301_PowerOff(void)
{
    /* Power off the SA47301 */
    /* TODO: Implement power off sequence */

    uint8 valRegData_Lo = 0;
    uint16 valSpiRxBuf_Lo = 0;
    Std_ReturnType valRet_Lo = E_NOT_OK;

    valRegData_Lo = SA47301_RegDataInfo_Mp[SA_REG_DEVCTRL_TAG].Data | SA_DEVICE_STANDBY_MODE; // Fixed: SA47301 → SA47301
 
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_WRITE, SA_DEVCTL_ADDR, valRegData_Lo);    // Fixed: SA_SPI_WRITE → SA_SPI_WRITE
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_WRITE, SA_DEVCTRLN_ADDR, ~valRegData_Lo); // Write complementary value to DEVCTRLN

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_READ, SA_DEVSTAT_ADDR, 0);
    
    valSpiRxBuf_Lo = SpiDataInfo.RxFrame.BITS.DATA;
    if (((valSpiRxBuf_Lo) & SA_STATE_MASK) == SA_DEVICE_STANDBY_MODE)
    {
        valRet_Lo = E_OK;
    }
    return valRet_Lo;
}

void Cdd_Sbc_Sa47301_SetLdoEn(Cdd_Sa47301LdoCtrl_TDSTR *LdoCtrlstr)
{
    uint8 valRegData_Lo = 0;
    uint16 valSpiRxBuf_Lo = 0;
    if(LdoCtrlstr == NULL_PTR) 
    {
        return;
    }
    // SA_SpiTransmit_Function(SA_SPI_READ,SA_DEVSTAT_ADDR,0,&valSpiRxBuf_Lo);
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_DEVSTAT_ADDR,0);

	valRegData_Lo = SpiDataInfo.RxFrame.BITS.DATA & 0x07;
	valRegData_Lo |= ((*LdoCtrlstr).RefVoltEnable << 3)&0x08;  
	valRegData_Lo |= ((*LdoCtrlstr).ComVoltEnable << 5)&0x20; 
	valRegData_Lo |= ((*LdoCtrlstr).Trk1VoltEnable << 6)&0x40; 
	valRegData_Lo |= ((*LdoCtrlstr).Trk2VoltEnable << 7)&0x80; 

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_DEVCTL_ADDR, valRegData_Lo);
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_DEVCTRLN_ADDR, ~valRegData_Lo);
}

Std_ReturnType Cdd_Sbc_Sa47301_SetWakeStatus(uint8 WakeStatus)
{
    Std_ReturnType valRet_Lo = E_NOT_OK;
    uint8 valRegData_Lo = 0;
    uint16 valSpiRxBuf_Lo = 0;

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_REG_DEVCFG0_TAG,0);

    valRegData_Lo = (SpiDataInfo.RxFrame.BITS.DATA & 0x7F) | (WakeStatus << SA_WKTIMEEN_SHIFT);

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_DEVCFG0_TAG, valRegData_Lo);

    // Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_REG_DEVCFG0_TAG,0);

    // valSpiRxBuf_Lo = SpiDataInfo.RxFrame.BITS.DATA;
    // if (((valSpiRxBuf_Lo) & 0x80) == WakeStatus)
    // {
        
    //     valRet_Lo = E_OK;
    // }
    return valRet_Lo;
}

Std_ReturnType Cdd_Sbc_Sa47301_SetWakeTime(uint32 wakeTime)
{
    uint8 valRegData_Lo = 0;   


    uint8 valWakeTime_Hi = 0;
    uint8 valWakeTime_Mi = 0;
    uint8 valWakeTime_Lo = 0;

    Std_ReturnType valRet_Lo = E_NOT_OK;    
    
    if(Cdd_Sa47301_Config.DevCfg->WakeTimeCyc == EVPT_CDD_SA_WAKETIME_CYC_PERIOD_1MS)
    {
        if(wakeTime*1000 > 0xFFFFFF)
        {
            Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_REG_DEVCFG0_TAG,0);
            valRegData_Lo = SpiDataInfo.RxFrame.BITS.DATA & 0xCF | (1 << SA_WKTIMECYC_SHIFT);
            Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_DEVCFG0_TAG, valRegData_Lo);

            valWakeTime_Hi = (uint8)((wakeTime >> 16 )& 0xFF);
            valWakeTime_Mi = (uint8)((wakeTime >> 8 )& 0xFF);
            valWakeTime_Lo = (uint8)(wakeTime & 0xFF);

            Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WKTIMCFG2_TAG, valWakeTime_Hi);
            Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WKTIMCFG1_TAG, valWakeTime_Mi);
            Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WKTIMCFG0_TAG, valWakeTime_Lo);

        }
        else
        {
            valWakeTime_Hi = (uint8)(((wakeTime * 1000) >> 16) & 0xFF);
            valWakeTime_Mi = (uint8)(((wakeTime * 1000) >> 8) & 0xFF);
            valWakeTime_Lo = (uint8)((wakeTime * 1000) & 0xFF);

            Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WKTIMCFG2_TAG, valWakeTime_Hi);
            Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WKTIMCFG1_TAG, valWakeTime_Mi);
            Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WKTIMCFG0_TAG, valWakeTime_Lo);
        }
    }
    else
    {
        valWakeTime_Hi = (uint8)((wakeTime >> 16 )& 0xFF);
        valWakeTime_Mi = (uint8)((wakeTime >> 8 )& 0xFF);
        valWakeTime_Lo = (uint8)(wakeTime & 0xFF);
        Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WKTIMCFG2_TAG, valWakeTime_Hi);
        Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WKTIMCFG1_TAG, valWakeTime_Mi);
        Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WKTIMCFG0_TAG, valWakeTime_Lo);
    }

    return valRet_Lo;
}

#ifdef __cplusplus
}
#endif