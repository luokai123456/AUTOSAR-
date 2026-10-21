#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301_Ctrl.h"
#include "Cdd_Sa47301_Reg.h"
#include "Cdd_Sa47301_Com.h"



/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_CTRL_C             4
#define SA47301_AR_REL_MINOR_VER_CTRL_C             4
#define SA47301_AR_REL_REV_VER_CTRL_C               0
#define SA47301_SW_MAJOR_VER_CTRL_C                 1
#define SA47301_SW_MINOR_VER_CTRL_C                 0
#define SA47301_SW_PATCH_VER_CTRL_C                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_CTRL_C != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_CTRL_C"
#endif
#if (SA47301_AR_REL_MINOR_VER_CTRL_C != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_CTRL_C"
#endif
#if (SA47301_AR_REL_REV_VER_CTRL_C != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_CTRL_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_CTRL_C != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_CTRL_C"
#endif
#if (SA47301_SW_MINOR_VER_CTRL_C != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_CTRL_C"
#endif
#if (SA47301_SW_PATCH_VER_CTRL_C != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_CTRL_C"
#endif

extern Cdd_Sa47301SpiInfo_TDSTR SpiDataInfo;

Cdd_Sa47301AbistResInfo_TDSTR AbistResInfo[CDD_SA47301_ABIST_NUM_MAX] = {
    {.AbistName = CDD_SA47301_ABIST_TRK2OV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_TRK1OV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_VREFOV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_COMOV  , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_VMONOV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_STBYOV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_UCOV   , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_PREGOV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_TRK2UV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_TRK1UV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_VREFUV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_COMUV  , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_VMONUV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_STBYUV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_UCUV   , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_PREGUV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_BIASHI , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_BIASLOW, .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_RG12OV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_BG12UV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_INTOV  , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
    {.AbistName = CDD_SA47301_ABIST_VBATOV , .AbistEnStatus = CDD_SA_ABIST_ENABLE, .AbistResult = 0},
};

const Cdd_Sa47301FWdgResponse_TDSTR Sa47391_FuncWDGResponse[16] = {
    {.question = 0x0, .response = {0xFF, 0x0F, 0xF0, 0x00}},
    {.question = 0x1, .response = {0xB0, 0x40, 0xBF, 0x4F}},
    {.question = 0x2, .response = {0xE9, 0x19, 0xE6, 0x16}},
    {.question = 0x3, .response = {0xA6, 0x56, 0xA9, 0x59}},
    {.question = 0x4, .response = {0x75, 0x85, 0x7A, 0x8A}},
    {.question = 0x5, .response = {0x3A, 0xCA, 0x35, 0xC5}},
    {.question = 0x6, .response = {0x63, 0x93, 0x6C, 0x9C}},
    {.question = 0x7, .response = {0x2C, 0xDC, 0x23, 0xD3}},
    {.question = 0x8, .response = {0xD2, 0x22, 0xDD, 0x2D}},
    {.question = 0x9, .response = {0x9D, 0x6D, 0x92, 0x62}},
    {.question = 0xA, .response = {0xC4, 0x34, 0xCB, 0x3B}},
    {.question = 0xB, .response = {0x8B, 0x7B, 0x84, 0x74}},
    {.question = 0xC, .response = {0x58, 0xA8, 0x57, 0xA7}},
    {.question = 0xD, .response = {0x17, 0xE7, 0x18, 0xE8}},
    {.question = 0xE, .response = {0x4E, 0xBE, 0x41, 0xB1}},
    {.question = 0xF, .response = {0x01, 0xF1, 0x0E, 0xFE}}
};

uint16 WWD_Err_index = 0;
void Cdd_Sbc_Sa47301_FeedWWdg(void)
{
    uint16 valSpiRxBuf_Lo = 0;
    uint8 valRegData_Lo = 0;

    // Step 1: Read current state of WWDSCMD (WWD Command) register
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_WWDSCMD_ADDR, 0);
    
    // Step 2: Invert feed dog bit (bit 8 of WWDSCMD, mask 0x0100) – mandatory for SA47301 WWD feed
    valRegData_Lo = (SpiDataInfo.RxFrame.FrameData & 0x0100)?0:1;

    // Step 3: Write inverted bit back to WWDSCMD to complete feed dog (Fixed: SA_SPI_WRITE → SA_SPI_WRITE)
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_WWDSCMD_ADDR, valRegData_Lo);

    // Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_WWDSCMD_ADDR, 0);

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_REG_SYSFLG_TAG, 0);

    if(((SpiDataInfo.RxFrame.BITS.DATA >> 1) & 1) == 1)
    {
        WWD_Err_index++;
        Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_SYSFLG_TAG, 0x02);
    }

}

void Cdd_Sbc_Sa47301_FeedFWdg(void)
{
    uint16 valSpiRxBuf_Lo = 0;  // SPI read/write receive buffer
    uint8 valRegData_Lo = 0;    // Fixed: uint8 → uint8_t (C99 standard type)

    uint8  Sa47301_question;

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_FWDRSPOK_ADDR, 0);

    Sa47301_question = SpiDataInfo.RxFrame.BITS.DATA & 0x0F;

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_FWDRSP_ADDR, Sa47391_FuncWDGResponse[Sa47301_question].response[0]);
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_FWDRSPOK_ADDR, 0);

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_FWDRSP_ADDR, Sa47391_FuncWDGResponse[Sa47301_question].response[1]);
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_FWDRSPOK_ADDR, 0);

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_FWDRSP_ADDR, Sa47391_FuncWDGResponse[Sa47301_question].response[2]);
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_FWDRSPOK_ADDR, 0);

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_FWDRSPSYNC_ADDR, Sa47391_FuncWDGResponse[Sa47301_question].response[3]);
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_FWDRSPOK_ADDR, 0);
}

Std_ReturnType Cdd_Sbc_Sa47301_SetWdgEnStatus(Cdd_Sa47301WdgType_TDEN WdgType,uint8 wdgEnStatus)
{
    uint8 valRegData_Lo = 0;    // Fixed: uint8 → uint8_t (C99 standard type)
    uint8 valWdgVal = 0; 
    uint8 valWdgMask = 0;

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_READ, SA_REG_RWDCFG0_TAG, 0);

    if(WdgType == SA47301_WWDG)
    {
        valWdgMask = SA_WWDEN_MASK;
        valWdgVal = wdgEnStatus << SA_WWDEN_SHIFT;
    }
    else if(WdgType == SA47301_FWDG)
    {
        valWdgMask = SA_FWDEN_MASK;
        valWdgVal = wdgEnStatus << SA_FWDEN_SHIFT;
    }
    else
    {
        return E_NOT_OK;
    }

    valRegData_Lo = (SpiDataInfo.RxFrame.BITS.DATA & (~valWdgMask)) | (valWdgVal << SA_WKTIMEEN_SHIFT);

    SA47301_ProtectedRegMode_Function(SA_REG_UNLOCK);
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo,SA47301_SPI_WRITE, SA_REG_WDCFG0_TAG, valRegData_Lo);
    SA47301_ProtectedRegMode_Function(SA_REG_LOCKED);

    return E_OK;
}

Std_ReturnType Cdd_Sbc_Sa47301_CtrlErrMonStatusFunction(Cdd_Sa47301ErrMonType_STDR ErrMonCtrl)
{
    uint8 valRegData_Lo = 0U;
    uint8 valSysPCfg1Val = 0U;
    const uint8 valErrMonMask = (uint8)(SA_ERREN_MASK | SA_ERRRECEN_MASK |
                                        SA_ERRSLPEN_MASK | SA_ERRRECTIM_MASK);
    Std_ReturnType valRet_Lo = E_NOT_OK;
    Std_ReturnType valLockRet_Lo;

    if (((uint8)ErrMonCtrl.ErrMonEn > 1U) ||
        ((uint8)ErrMonCtrl.ErrMonRecEn > 1U) ||
        ((uint8)ErrMonCtrl.ErrMonSleepEn > 1U) ||
        ((uint8)ErrMonCtrl.ErrMonRecTime > (uint8)SA47301_ERRMONREC_10MS))
    {
        return E_NOT_OK;
    }

    valRet_Lo = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ,
                                             SA_REG_RSYSCFG1_TAG, 0U);
    if (valRet_Lo != E_OK)
    {
        return E_NOT_OK;
    }

    valSysPCfg1Val = (uint8)((((uint8)ErrMonCtrl.ErrMonEn << SA_ERREN_SHIFT) & SA_ERREN_MASK) |
                             (((uint8)ErrMonCtrl.ErrMonRecEn << SA_ERRRECEN_SHIFT) & SA_ERRRECEN_MASK) |
                             (((uint8)ErrMonCtrl.ErrMonSleepEn << SA_ERRSLPEN_SHIFT) & SA_ERRSLPEN_MASK) |
                             (((uint8)ErrMonCtrl.ErrMonRecTime << SA_ERRRECTIM_SHIFT) & SA_ERRRECTIM_MASK));

    /* Preserve SS2DEL and update only the error-monitor configuration bits. */
    valRegData_Lo = (uint8)((SpiDataInfo.RxFrame.BITS.DATA & (uint8)~valErrMonMask) |
                            valSysPCfg1Val);

    valRet_Lo = SA47301_ProtectedRegMode_Function(SA_REG_UNLOCK);
    if (valRet_Lo == E_OK)
    {
        valRet_Lo = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE,
                                                 SA_REG_SYSPCFG1_TAG, valRegData_Lo);

        /* Always attempt to restore register protection after an unlock. */
        valLockRet_Lo = SA47301_ProtectedRegMode_Function(SA_REG_LOCKED);
        if ((valRet_Lo == E_OK) && (valLockRet_Lo == E_OK))
        {
            valRet_Lo = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ,
                                                     SA_REG_RSYSCFG1_TAG, 0U);
            if ((valRet_Lo == E_OK) &&
                ((SpiDataInfo.RxFrame.BITS.DATA & valErrMonMask) !=
                 (valRegData_Lo & valErrMonMask)))
            {
                valRet_Lo = E_NOT_OK;
            }
        }
        else
        {
            valRet_Lo = E_NOT_OK;
        }
    }

    return valRet_Lo;
}




#ifdef __cplusplus
}
#endif