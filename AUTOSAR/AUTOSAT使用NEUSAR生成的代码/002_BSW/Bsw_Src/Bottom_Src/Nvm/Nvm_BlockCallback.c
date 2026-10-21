/*** create info ***********************
*@ Author : wangjiacheng 
*@ date :2025-12-04
*@ Description :NVM block callback functions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : wangjiacheng 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#include "NvM_BlockCallback.h"
#include "NvM_Cfg.h"
#include "NvM.h"
void NvM_SetRamUserBlockStatus(void)
{
    uint16 index = 0;
    for (index = 2; index<NVM_NUM_OF_BLOCK_TOTAL; index++)
    {
        (void)NvM_SetRamBlockStatus(index,TRUE);
    }

}

uint8 NvMBlock2_ResetReason_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK2_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock2_ResetReason[index];
    }
    return ret;
}

uint8 NvMBlock3_OsError_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK3_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock3_OsError[index];
    }
    return ret;
}

uint8 NvMBlock4_FunErrDiag_Security_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK4_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock4_FunErrDiag_Security[index];
    }
    return ret;
}

uint8 NvMBlock5_Information_Security_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK5_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock5_Information_Security[index];
    }
    return ret;
}

uint8 NvMBlock6_DCM11_NvMBuf_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK6_RAM_SIZE;index++)
    {
        Rom[index] = Dcm_11_NvMBuf[index];
    }
    return ret;
}

uint8 NvMBlock7_Dcm_27_Security_Data_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK7_RAM_SIZE;index++)
    {
        Rom[index] = Dcm_27_Security_Data[index].AttemptCounter;
    }
    return ret;
}
uint8 NvMBlock8_Uds_Faultstatus_agingcount_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK8_9_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock8_Uds_Faultstatus_agingcount[index];
    }
    return ret;
}

uint8 NvMBlock9_Uds_Faultstatus_agingcount_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK8_9_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock9_Uds_Faultstatus_agingcount[index];
    }
    return ret;
}

uint8 NvMBlock10_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock10_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock11_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock11_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock12_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock12_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock13_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock13_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock14_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock14_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock15_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock15_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock16_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock16_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock17_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock17_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock18_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock18_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock19_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock19_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock20_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock20_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock21_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock21_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock22_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock22_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock23_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock23_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock24_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock24_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock25_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock25_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock26_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock26_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock27_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock27_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock28_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock28_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock29_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock29_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock30_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock30_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock31_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock31_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock32_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock32_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock33_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock33_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock34_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock34_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock35_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock35_Uds_Frozendata[index];
    }
    return ret;
}

uint8 NvMBlock36_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock36_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock37_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock37_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock38_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock38_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock39_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock39_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock40_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock40_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock41_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock41_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock42_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock42_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock43_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock43_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock44_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock44_Uds_Frozendata[index];
    }
    return ret;
}


uint8 NvMBlock45_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock45_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock46_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock46_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock47_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock47_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock48_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock48_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock49_Uds_Frozendata_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock49_Uds_Frozendata[index];
    }
    return ret;
}
uint8 NvMBlock50_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock50_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock51_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock51_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock52_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock52_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock53_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock53_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock54_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock54_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock55_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock55_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock56_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock56_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock57_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock57_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock58_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock58_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock59_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock59_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock60_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock60_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock61_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock61_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock62_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock62_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock63_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock63_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock64_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock64_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock65_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock65_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock66_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock66_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock67_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock67_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock68_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock68_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock69_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock69_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock70_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock70_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock71_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock71_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock72_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock72_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock73_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock73_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock74_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock74_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock75_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock75_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock76_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock76_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock77_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock77_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock78_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock78_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock79_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock79_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock80_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock80_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock81_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock81_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock82_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock82_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock83_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock83_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock84_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock84_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock85_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock85_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock86_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock86_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock87_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock87_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock88_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock88_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock89_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock89_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock90_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock90_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock91_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock91_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock92_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock92_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock93_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock93_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock94_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock94_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock95_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock95_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock96_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock96_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock97_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK97_100_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock97_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock98_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK97_100_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock98_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock99_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK97_100_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock99_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock100_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK97_100_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock100_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock101_DCM2E_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK101_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock101_DCM2E_ASW[index];
    }
    return ret;
}
uint8 NvMBlock102_DCM2E_BOOT_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK102_105_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock102_DCM2E_BOOT[index];
    }
    return ret;
}
uint8 NvMBlock103_DCM2E_BOOT_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK102_105_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock103_DCM2E_BOOT[index];
    }
    return ret;
}
uint8 NvMBlock104_DCM2E_BOOT_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK102_105_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock104_DCM2E_BOOT[index];
    }
    return ret;
}
uint8 NvMBlock105_DCM2E_BOOT_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK102_105_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock105_DCM2E_BOOT[index];
    }
    return ret;
}
uint8 NvMBlock106_DCM2E_BOOT_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK106_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock106_DCM2E_BOOT[index];
    }
    return ret;
}
uint8 NvMBlock107_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock107_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock108_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock108_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock109_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock109_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock110_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock110_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock111_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock111_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock112_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock112_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock113_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock113_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock114_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock114_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock115_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock115_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock116_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock116_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock117_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock117_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock118_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock118_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock119_DCM2E_SHARE_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK119_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock119_DCM2E_SHARE[index];
    }
    return ret;
}
uint8 NvMBlock120_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock120_Reserve_ASW[index];
    }
    return ret;
}
uint8 NvMBlock121_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock121_Reserve_ASW[index];
    }
    return ret;
}
uint8 NvMBlock122_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock122_Reserve_ASW[index];
    }
    return ret;
}
uint8 NvMBlock123_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock123_Reserve_ASW[index];
    }
    return ret;
}
uint8 NvMBlock124_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock124_Reserve_ASW[index];
    }
    return ret;
}
uint8 NvMBlock125_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock125_Reserve_ASW[index];
    }
    return ret;
}uint8 NvMBlock126_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock126_Reserve_ASW[index];
    }
    return ret;
}uint8 NvMBlock127_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock127_Reserve_ASW[index];
    }
    return ret;
}
uint8 NvMBlock128_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK128_131_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock128_Reserve_ASW[index];
    }
    return ret;
}
uint8 NvMBlock129_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK128_131_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock129_Reserve_ASW[index];
    }
    return ret;
}uint8 NvMBlock130_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK128_131_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock130_Reserve_ASW[index];
    }
    return ret;
}uint8 NvMBlock131_Reserve_ASW_WriteCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK128_131_RAM_SIZE;index++)
    {
        Rom[index] = NvMBlock131_Reserve_ASW[index];
    }
    return ret;
}



uint8 NvMBlock2_ResetReason_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK2_RAM_SIZE;index++)
    {
        NvMBlock2_ResetReason[index] = Rom[index];
    }
    return ret;    
}
uint8 NvMBlock3_OsError_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK3_RAM_SIZE;index++)
    {
        NvMBlock3_OsError[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock4_FunErrDiag_Security_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK4_RAM_SIZE;index++)
    {
        NvMBlock4_FunErrDiag_Security[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock5_Information_Security_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK5_RAM_SIZE;index++)
    {
        NvMBlock5_Information_Security[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock6_DCM11_NvMBuf_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK6_RAM_SIZE;index++)
    {
        Dcm_11_NvMBuf[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock7_Dcm_27_Security_Data_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK7_RAM_SIZE;index++)
    {
        Dcm_27_Security_Data[index].AttemptCounter = Rom[index];
    }
    return ret;
}
uint8 NvMBlock8_Uds_Faultstatus_agingcount_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK8_9_RAM_SIZE;index++)
    {
        NvMBlock8_Uds_Faultstatus_agingcount[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock9_Uds_Faultstatus_agingcount_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK8_9_RAM_SIZE;index++)
    {
        NvMBlock9_Uds_Faultstatus_agingcount[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock10_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock10_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock11_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock11_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock12_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock12_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock13_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock13_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock14_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock14_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock15_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock15_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock16_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock16_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock17_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock17_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock18_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock18_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock19_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock19_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock20_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock20_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock21_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock21_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock22_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock22_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock23_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock23_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock24_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock24_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock25_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock25_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock26_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock26_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock27_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock27_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock28_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock28_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock29_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock29_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock30_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock30_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock31_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock31_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock32_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock32_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock33_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock33_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock34_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock34_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock35_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock35_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock36_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock36_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock37_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock37_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock38_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock38_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock39_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock39_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock40_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock40_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock41_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock41_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock42_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock42_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock43_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock43_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock44_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock44_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}

uint8 NvMBlock45_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock45_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock46_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock46_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock47_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock47_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock48_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock48_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock49_Uds_Frozendata_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK10_49_RAM_SIZE;index++)
    {
        NvMBlock49_Uds_Frozendata[index] = Rom[index];
    }
    return ret;
}

uint8 NvMBlock50_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock50_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock51_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock51_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}

uint8 NvMBlock52_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock52_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock53_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock53_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock54_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock54_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock55_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock55_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock56_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock56_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock57_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock57_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock58_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint16 index;
    uint8 ret = E_OK;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock58_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock59_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock59_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock60_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock60_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock61_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock61_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock62_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock62_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock63_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock63_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock64_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock64_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock65_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock65_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock66_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock66_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock67_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock67_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock68_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock68_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock69_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock69_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock70_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock70_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock71_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock71_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock72_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock72_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock73_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock73_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock74_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock74_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock75_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock75_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock76_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock76_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock77_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock77_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock78_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock78_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock79_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock79_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock80_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock80_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock81_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock81_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock82_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock82_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock83_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock83_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock84_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock84_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock85_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock85_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock86_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock86_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock87_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock87_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock88_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock88_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock89_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK50_89_RAM_SIZE;index++)
    {
        NvMBlock89_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock90_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        NvMBlock90_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock91_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        NvMBlock91_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock92_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        NvMBlock92_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock93_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        NvMBlock93_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock94_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        NvMBlock94_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock95_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        NvMBlock95_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock96_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK90_96_RAM_SIZE;index++)
    {
        NvMBlock96_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock97_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK97_100_RAM_SIZE;index++)
    {
        NvMBlock97_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock98_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK97_100_RAM_SIZE;index++)
    {
        NvMBlock98_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock99_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK97_100_RAM_SIZE;index++)
    {
        NvMBlock99_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock100_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK97_100_RAM_SIZE;index++)
    {
        NvMBlock100_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock101_DCM2E_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK101_RAM_SIZE;index++)
    {
        NvMBlock101_DCM2E_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock102_DCM2E_BOOT_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK102_105_RAM_SIZE;index++)
    {
        NvMBlock102_DCM2E_BOOT[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock103_DCM2E_BOOT_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK102_105_RAM_SIZE;index++)
    {
        NvMBlock103_DCM2E_BOOT[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock104_DCM2E_BOOT_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK102_105_RAM_SIZE;index++)
    {
        NvMBlock104_DCM2E_BOOT[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock105_DCM2E_BOOT_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK102_105_RAM_SIZE;index++)
    {
        NvMBlock105_DCM2E_BOOT[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock106_DCM2E_BOOT_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK106_RAM_SIZE;index++)
    {
        NvMBlock106_DCM2E_BOOT[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock107_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock107_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock108_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock108_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock109_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock109_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock110_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock110_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock111_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock111_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock112_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock112_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock113_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock113_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock114_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock114_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock115_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock115_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock116_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock116_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock117_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock117_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock118_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK107_118_RAM_SIZE;index++)
    {
        NvMBlock118_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock119_DCM2E_SHARE_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK119_RAM_SIZE;index++)
    {
        NvMBlock119_DCM2E_SHARE[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock120_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        NvMBlock120_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock121_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        NvMBlock121_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock122_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        NvMBlock122_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock123_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        NvMBlock123_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock124_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        NvMBlock124_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock125_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        NvMBlock125_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}uint8 NvMBlock126_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        NvMBlock126_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}uint8 NvMBlock127_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK120_127_RAM_SIZE;index++)
    {
        NvMBlock127_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock128_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK128_131_RAM_SIZE;index++)
    {
        NvMBlock128_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}
uint8 NvMBlock129_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK128_131_RAM_SIZE;index++)
    {
        NvMBlock129_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}uint8 NvMBlock130_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK128_131_RAM_SIZE;index++)
    {
        NvMBlock130_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}uint8 NvMBlock131_Reserve_ASW_ReadCbk(uint8* Rom)
{
    uint8 ret = E_OK;
    uint16 index;
    for (index = 0;index<EEPROM_BLOCK128_131_RAM_SIZE;index++)
    {
        NvMBlock131_Reserve_ASW[index] = Rom[index];
    }
    return ret;
}