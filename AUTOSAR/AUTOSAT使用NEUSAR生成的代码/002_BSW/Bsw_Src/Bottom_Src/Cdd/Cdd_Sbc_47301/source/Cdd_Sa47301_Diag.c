#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301_Diag.h"
#include "Cdd_Sa47301_Reg.h"
#include "Cdd_Sa47301_Com.h"
#include "Cdd_Sa47301_Type.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_DIAG_C             4
#define SA47301_AR_REL_MINOR_VER_DIAG_C             4
#define SA47301_AR_REL_REV_VER_DIAG_C               0
#define SA47301_SW_MAJOR_VER_DIAG_C                 1
#define SA47301_SW_MINOR_VER_DIAG_C                 0
#define SA47301_SW_PATCH_VER_DIAG_C                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_DIAG_C != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_DIAG_C"
#endif
#if (SA47301_AR_REL_MINOR_VER_DIAG_C != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_DIAG_C"
#endif
#if (SA47301_AR_REL_REV_VER_DIAG_C != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_DIAG_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_DIAG_C != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_DIAG_C"
#endif
#if (SA47301_SW_MINOR_VER_DIAG_C != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_DIAG_C"
#endif
#if (SA47301_SW_PATCH_VER_DIAG_C != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_DIAG_C"
#endif

#define SA47301_DIAG_NUM  (sizeof(Cdd_Sa47301DiagInfo)/sizeof(Cdd_Sa47301DiagInfo[0]))
#define EXTRACT_DIAG_BIT(regData, bitPos)    (boolean)(((regData) >> (bitPos)) & 0x01U)
// 无效寄存器地址标记，用于初始化
#define INVALID_REG_ADDR                     (0xFFFFU)

extern Cdd_Sa47301SpiInfo_TDSTR SpiDataInfo;

Cdd_Sa47301DiagInfo_TDSTR Cdd_Sa47301DiagInfo[] =
{
    {SA47301_DIAG_TRK2SC , SA_MONSF0_ADDR, 7, FALSE},
    {SA47301_DIAG_TRK1SC , SA_MONSF0_ADDR, 6, FALSE},
    {SA47301_DIAG_VREFSG , SA_MONSF0_ADDR, 5, FALSE},
    {SA47301_DIAG_COMSG  , SA_MONSF0_ADDR, 4, FALSE},
    {SA47301_DIAG_VMONSG , SA_MONSF0_ADDR, 3, FALSE},
    {SA47301_DIAG_STBYSG , SA_MONSF0_ADDR, 2, FALSE},
    {SA47301_DIAG_UCSG   , SA_MONSF0_ADDR, 1, FALSE},
    {SA47301_DIAG_PREGSG , SA_MONSF0_ADDR, 0, FALSE},
    {SA47301_DIAG_TRK2OV , SA_MONSF1_ADDR, 7, FALSE},
    {SA47301_DIAG_TRK1OV , SA_MONSF1_ADDR, 6, FALSE},
    {SA47301_DIAG_VREFOV , SA_MONSF1_ADDR, 5, FALSE},
    {SA47301_DIAG_COMOV  , SA_MONSF1_ADDR, 4, FALSE},
    {SA47301_DIAG_VMONOV , SA_MONSF1_ADDR, 3, FALSE},
    {SA47301_DIAG_STBYOV , SA_MONSF1_ADDR, 2, FALSE},
    {SA47301_DIAG_UCOV   , SA_MONSF1_ADDR, 1, FALSE},
    {SA47301_DIAG_TRK2UV , SA_MONSF2_ADDR, 7, FALSE},
    {SA47301_DIAG_TRK1UV , SA_MONSF2_ADDR, 6, FALSE},
    {SA47301_DIAG_VREFUV , SA_MONSF2_ADDR, 5, FALSE},
    {SA47301_DIAG_COMUV  , SA_MONSF2_ADDR, 4, FALSE},
    {SA47301_DIAG_VMONUV , SA_MONSF2_ADDR, 3, FALSE},
    {SA47301_DIAG_STBYUV , SA_MONSF2_ADDR, 2, FALSE},
    {SA47301_DIAG_UCUV   , SA_MONSF2_ADDR, 1, FALSE},
    {SA47301_DIAG_PREGUV , SA_MONSF2_ADDR, 0, FALSE},
    {SA47301_DIAG_BIASHI , SA_MONSF3_ADDR, 7, FALSE},
    {SA47301_DIAG_BIASLOW, SA_MONSF3_ADDR, 6, FALSE},
    {SA47301_DIAG_RG12OV , SA_MONSF3_ADDR, 5, FALSE},
    {SA47301_DIAG_BG12UV , SA_MONSF3_ADDR, 4, FALSE},
    {SA47301_DIAG_VBATOV , SA_MONSF3_ADDR, 0, FALSE},
    {SA47301_DIAG_MON    , SA_OTFAIL_ADDR, 7, FALSE},
    {SA47301_DIAG_COM    , SA_OTFAIL_ADDR, 4, FALSE},
    {SA47301_DIAG_UC     , SA_OTFAIL_ADDR, 1, FALSE},
    {SA47301_DIAG_PREG   , SA_OTFAIL_ADDR, 0, FALSE},
};


Std_ReturnType Cdd_Sbc_Sa47301_ClearDiag(void)
{
    const uint16 ClearRegAddr[] = {SA_REG_INITERROR_TAG,SA_MONSF0_ADDR, SA_MONSF1_ADDR, SA_MONSF2_ADDR, SA_MONSF3_ADDR, SA_OTFAIL_ADDR};
    const uint16 TxData = 0xFFU;
    uint8 idx = 0U;
    Std_ReturnType ret = E_OK;
    const uint8 RegCnt = sizeof(ClearRegAddr)/sizeof(ClearRegAddr[0]);

    for(idx = 0U; idx < RegCnt; idx++)
    {
       ret |= Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, ClearRegAddr[idx], TxData);
    }

    for(idx = 0U; idx < RegCnt; idx++)
    {
       ret |= Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, ClearRegAddr[idx], 0U);
       ret |= (SpiDataInfo.RxFrame.BITS.DATA == 0U) ? E_OK : E_NOT_OK;
    }

    for(uint8 index = 0; index < SA47301_DIAG_NUM; index++)
    {
        Cdd_Sa47301DiagInfo[index].DiagFlag = FALSE; // Clear all diag status
    }
    return ret;
}


boolean Cdd_Sbc_Sa47301_GetDiagStatus(Cdd_Sa47301Diag_TDEM DiagID)
{
    boolean DiagVal = FALSE;
    DiagVal = Cdd_Sa47301DiagInfo[(uint8)DiagID].DiagFlag;
    return DiagVal;
}

Std_ReturnType Cdd_Sbc_Sa47301_SaveDiagStatus(void)
{
    uint8  DiagIdx = 0U;       
    uint16 LastRegAddr = INVALID_REG_ADDR;
    Std_ReturnType ret = E_OK;

    for(DiagIdx = 0U; DiagIdx < SA47301_DIAG_NUM; DiagIdx++)
    {
        if(Cdd_Sa47301DiagInfo[DiagIdx].Addr != LastRegAddr)
        {
            ret |= Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, Cdd_Sa47301DiagInfo[DiagIdx].Addr, 0U);
            LastRegAddr = Cdd_Sa47301DiagInfo[DiagIdx].Addr; 
        }
        Cdd_Sa47301DiagInfo[DiagIdx].DiagFlag = EXTRACT_DIAG_BIT(SpiDataInfo.RxFrame.BITS.DATA, Cdd_Sa47301DiagInfo[DiagIdx].Bit);
    }
    return ret;
}

/************************* 内部静态函数 *************************/
/**
 * @brief  组装ABIST_SELECT0寄存器数值
 */
static uint8 SA47301_AssembleSelect0(Cdd_Sa47301AbistCfgType_TDSTR *AbistCfg)
{
    uint8 regVal = 0x00U;
    if(AbistCfg->OVTrk2 == EVPT_CDD_SA_ABIST_OVTRK2_SELECT)  regVal |= 0x80U;
    if(AbistCfg->OVTrk1 == EVPT_CDD_SA_ABIST_OVTRK1_SELECT)  regVal |= 0x40U;
    if(AbistCfg->OVVref == EVPT_CDD_SA_ABIST_OVVREF_SELECT)  regVal |= 0x20U;
    if(AbistCfg->OVCom  == EVPT_CDD_SA_ABIST_OVCOM_SELECT)  regVal |= 0x10U;
    if(AbistCfg->OVVmon == EVPT_CDD_SA_ABIST_OVVMON_SELECT)  regVal |= 0x08U;
    if(AbistCfg->OVStby == EVPT_CDD_SA_ABIST_OVSTBY_SELECT)  regVal |= 0x04U;
    if(AbistCfg->OVUc   == EVPT_CDD_SA_ABIST_OVUC_SELECT)  regVal |= 0x02U;
    if(AbistCfg->OVPreg == EVPT_CDD_SA_ABIST_OVPREG_SELECT)  regVal |= 0x01U;
    return regVal;
}

/**
 * @brief  组装ABIST_SELECT1寄存器数值
 */
static uint8 SA47301_AssembleSelect1(Cdd_Sa47301AbistCfgType_TDSTR *AbistCfg)
{
    uint8 regVal = 0x00U;
    if(AbistCfg->UVTrk2 == EVPT_CDD_SA_ABIST_UVTRK2_SELECT)  regVal |= 0x80U;
    if(AbistCfg->UVTrk1 == EVPT_CDD_SA_ABIST_UVTRK1_SELECT)  regVal |= 0x40U;
    if(AbistCfg->UVVref == EVPT_CDD_SA_ABIST_UVVREF_SELECT)  regVal |= 0x20U;
    if(AbistCfg->UVCom  == EVPT_CDD_SA_ABIST_UVCOM_SELECT)  regVal |= 0x10U;
    if(AbistCfg->UVVmon == EVPT_CDD_SA_ABIST_UVVMON_SELECT)  regVal |= 0x08U;
    if(AbistCfg->UVStby == EVPT_CDD_SA_ABIST_UVSTBY_SELECT)  regVal |= 0x04U;
    if(AbistCfg->UVUc   == EVPT_CDD_SA_ABIST_UVUC_SELECT)  regVal |= 0x02U;
    if(AbistCfg->UVPreg == EVPT_CDD_SA_ABIST_UVPREG_SELECT)  regVal |= 0x01U;
    return regVal;
}

/**
 * @brief  组装ABIST_SELECT2寄存器数值
 */
static uint8 SA47301_AssembleSelect2(Cdd_Sa47301AbistCfgType_TDSTR *AbistCfg)
{
    uint8 regVal = 0x00U;
    if(AbistCfg->BiasHigh == EVPT_CDD_SA_ABIST_BIASHIGH_SELECT) regVal |= 0x80U;
    if(AbistCfg->BiasLow  == EVPT_CDD_SA_ABIST_BIASLOW_SELECT) regVal |= 0x40U;
    if(AbistCfg->Bg12Ov   == EVPT_CDD_SA_ABIST_BG12OV_SELECT) regVal |= 0x20U;
    if(AbistCfg->Bg12Uv   == EVPT_CDD_SA_ABIST_BG12UV_SELECT) regVal |= 0x10U;
    if(AbistCfg->IntOV    == EVPT_CDD_SA_ABIST_INTOV_SELECT) regVal |= 0x08U;
    if(AbistCfg->VBatOV   == EVPT_CDD_SA_ABIST_VBATOV_SELECT) regVal |= 0x01U;
    return regVal;
}

Std_ReturnType Cdd_Sbc_Sa47301_AbistEnFunction(Cdd_Sa47301AbistCfgType_TDSTR *AbistCfg)
{
    Std_ReturnType ret = E_OK;
    uint8 select0Val = 0x00U;
    uint8 select1Val = 0x00U;
    uint8 select2Val = 0x00U;
    uint8 ctrl0CfgVal = 0x00U;
    uint8 ctrl1CfgVal = 0x00U;
    uint8 devStatVal = 0x00U;

    // 1. 入参合法性检查
    if((AbistCfg == NULL_PTR))
    {
        return E_NOT_OK;
    }

    // 2. 校验设备当前状态是否支持ABIST（仅INIT/NORMAL/WAKE状态可执行）
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_DEVSTAT_TAG, 0x00U);
    if(ret != E_OK)
    {
        return E_NOT_OK;
    }
    devStatVal = SpiDataInfo.RxFrame.BITS.DATA & SA_STATE_MASK;
    if((devStatVal != SA_DEVICE_INIT_MODE) && (devStatVal != SA_DEVICE_NORMAL_MODE) && (devStatVal != SA_DEVICE_WAKE_MODE))
    {
        return E_NOT_OK; // 非支持ABIST的状态
    }

    // 3. 清除历史ABIST中断与故障标志（写1清0）
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_REG_INTERRUPTFLAGS_TAG, 0x40U);
    if(ret != E_OK)
    {
        return E_NOT_OK;
    }
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_REG_SYSFLG_TAG, 0x40U);
    if(ret != E_OK)
    {
        return E_NOT_OK;
    }

    // 4. 组装通道选择寄存器数值并写入
    select0Val = SA47301_AssembleSelect0(AbistCfg);
    select1Val = SA47301_AssembleSelect1(AbistCfg);
    select2Val = SA47301_AssembleSelect2(AbistCfg);

    // 写入SELECT0寄存器
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_REG_ABIST_SELECT0_TAG, select0Val);
    if(ret != E_OK)
    {
        return E_NOT_OK;
    }
    // 写入SELECT1寄存器
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_REG_ABIST_SELECT1_TAG, select1Val);
    if(ret != E_OK)
    {
        return E_NOT_OK;
    }
    // 写入SELECT2寄存器
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_REG_ABIST_SELECT2_TAG, select2Val);
    if(ret != E_OK)
    {
        return E_NOT_OK;
    }

    // 5. 组装ABIST_CTRL0控制寄存器，先写入配置，再启动测试
    ctrl0CfgVal |= ((uint8)AbistCfg->SafetyPath << SA_ABIST_CTRL0_INT_SHIFT);
    ctrl0CfgVal |= ((uint8)AbistCfg->AbistSequence << SA_ABIST_CTRL0_SINGLE_SHIFT);
    ctrl0CfgVal |= ((uint8)AbistCfg->FullPath << SA_ABIST_CTRL0_PATH_SHIFT);

    ctrl1CfgVal |= ((uint8)AbistCfg->OVTrigMonEn << SA_ABIST_CTRL_CLKEN_SHIFT);
    ctrl1CfgVal |= ((uint8)AbistCfg->AbistClkCheckEn << SA_ABIST_CTRL_OV_TRIG_SHIFT);

    // 先写入控制配置（不启动）
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_REG_ABIST_CTRL0_TAG, ctrl0CfgVal);
    if(ret != E_OK)
    {
        return E_NOT_OK;
    }

    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_REG_ABIST_CTRL1_TAG, ctrl1CfgVal);
    if(ret != E_OK)
    {
        return E_NOT_OK;
    }

    // 6. 置位START位，启动ABIST测试
    ctrl0CfgVal |= ((uint8)EVPT_CDD_SA_ABIST_STARTABIST_START << SA_ABIST_CTRL0_START_SHIFT);
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_REG_ABIST_CTRL0_TAG, ctrl0CfgVal);
    if(ret != E_OK)
    {
        return E_NOT_OK;
    }

    // 更新配置结构体启动状态
    AbistCfg->StartAbist = EVPT_CDD_SA_ABIST_STARTABIST_START;

    return E_OK;
}

Std_ReturnType Cdd_Sbc_Sa47301_GetAbistResrult(Cdd_Sa47301AbistResult_TDSTR *AbistResult, \
                                                    uint32 *FailChMask)
{
    Std_ReturnType ret = E_OK;
    uint8 ctrl0Val = 0x00U;
    uint8 ifVal = 0x00U;
    uint8 sysFailVal = 0x00U;
    uint8 select0Val = 0x00U;
    uint8 select1Val = 0x00U;
    uint8 select2Val = 0x00U;
    uint32 failMaskTemp = 0x00000000U;

    // 1. 入参合法性检查
    if((AbistResult == NULL_PTR))
    {
        return E_NOT_OK;
    }
    *AbistResult = ABIST_RESULT_IDLE;

    // 2. 读取ABIST_CTRL0寄存器，判断测试是否完成
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_ABIST_CTRL0_TAG, 0x00U);
    if(ret != E_OK)
    {
        *AbistResult = ABIST_RESULT_COMM_ERR;
        return E_NOT_OK;
    }
    ctrl0Val = SpiDataInfo.RxFrame.BITS.DATA;

    // 3. 判断START位是否为0，非0则测试仍在执行中
    if((ctrl0Val & (1U << SA_ABIST_CTRL0_START_SHIFT)) != 0x00U)
    {
        *AbistResult = ABIST_RESULT_BUSY;
        return E_OK;
    }

    // 4. 读取中断与故障寄存器，判断是否被异常中断
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_SYSFAIL_TAG, 0x00U);
    if(ret != E_OK)
    {
        *AbistResult = ABIST_RESULT_COMM_ERR;
        return E_NOT_OK;
    }
    sysFailVal = SpiDataInfo.RxFrame.BITS.DATA;
    if((sysFailVal & SA_ABISTERR_MASK) != 0x00U)
    {
        *AbistResult = ABIST_RESULT_ABORT_ERR;
        // 读取失败通道掩码
        if(FailChMask != NULL_PTR)
        {
            *FailChMask = 0xFFFFFFFFU;
        }
        return E_OK;
    }

    // 5. 读取ABIST完成中断标志
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_INTERRUPTFLAGS_TAG, 0x00U);
    if(ret != E_OK)
    {
        *AbistResult = ABIST_RESULT_COMM_ERR;
        return E_NOT_OK;
    }
    ifVal = SpiDataInfo.RxFrame.BITS.DATA;

    // 6. 读取SELECT寄存器，判断失败通道（测试通过的通道位会被硬件清0）
    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_ABIST_SELECT0_TAG, 0x00U);
    if(ret != E_OK)
    {
        *AbistResult = ABIST_RESULT_COMM_ERR;
        return E_NOT_OK;
    }
    select0Val = SpiDataInfo.RxFrame.BITS.DATA;

    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_ABIST_SELECT1_TAG, 0x00U);
    if(ret != E_OK)
    {
        *AbistResult = ABIST_RESULT_COMM_ERR;
        return E_NOT_OK;
    }
    select1Val = SpiDataInfo.RxFrame.BITS.DATA;

    ret = Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_ABIST_SELECT2_TAG, 0x00U);
    if(ret != E_OK)
    {
        *AbistResult = ABIST_RESULT_COMM_ERR;
        return E_NOT_OK;
    }
    select2Val = SpiDataInfo.RxFrame.BITS.DATA;

    // 7. 组装失败通道掩码
    failMaskTemp = ((uint32)select2Val << 16U) | ((uint32)select1Val << 8U) | (uint32)select0Val;
    if(FailChMask != NULL_PTR)
    {
        *FailChMask = failMaskTemp;
    }

    // 8. 最终结果判断
    if((ctrl0Val & SA_ABIST_CTRL0_STATUS_MASK) == SA_ABIST_CTRL0_STATUS_PASS)
    {
        if(failMaskTemp == 0x00000000U)
        {
            *AbistResult = ABIST_RESULT_PASS;
        }
        else
        {
            *AbistResult = ABIST_RESULT_FAIL;
        }
    }
    else if((ctrl0Val & SA_ABIST_CTRL0_STATUS_MASK) == SA_ABIST_CTRL0_STATUS_FAIL)
    {
        *AbistResult = ABIST_RESULT_FAIL;
    }
    else
    {
        *AbistResult = ABIST_RESULT_IDLE;
    }

    return E_OK;
}


#ifdef __cplusplus
}
#endif