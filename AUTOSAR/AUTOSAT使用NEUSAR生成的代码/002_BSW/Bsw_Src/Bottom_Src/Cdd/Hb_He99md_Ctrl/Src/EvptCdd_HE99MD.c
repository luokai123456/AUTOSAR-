#include "EvptCdd_HE99MD_Prv.h"
#include "EvptCdd_HE99MD_Com.h"
#include "EvptCdd_HE99MD_Cfg.h"
#include "IoHwAbs_DIO_Prv.h"
#include "ErrorDiag_Errorid.h"
#include "ErrorDiag_Swc.h"
#include "ErrorDiag_Cfg.h"
#include "ErrorHandler_Swc.h"
#include "ErrorHandler_ReactionCfg.h"
/*
 * ***********************************DEFINE*******************************************************
 */
#define HB_HE99MD_SPI_STATE_PWMMODE_MASK			(0x0001U)
#define HB_HE99MD_SPI_STATE_PWMGEN_MASK            	(0x0002U)
#define HB_HE99MD_SPI_STATE_PWMFW_MASK             	(0x0004U)
#define HB_HE99MD_SPI_STATE_FREQ1_MASK            	(0x0008U)
#define HB_HE99MD_SPI_STATE_FREQ2_MASK             	(0x0010U)
#define HB_HE99MD_SPI_STATE_DUTY_MASK_BASE         	(0x0020U)
#define HB_HE99MD_SPI_STATE_CTRL1_MASK         	   	(0x2000U)
#define HB_HE99MD_SPI_STATE_CTRL2_MASK         		(0x4000U)


/*************************************DIAG_START**************************************************/
#define HE99MD_HB_DIAG_STATUSREG0					(0U)
#define HE99MD_HB_DIAG_STATUSREG1					(1U)
#define HE99MD_HB_DIAG_STATUSREG2					(2U)
#define HE99MD_HB_DIAG_STATUSREG3					(3U)
#define HE99MD_HB_DIAG_STATUSREG4					(4U)
#define HE99MD_HB_DIAG_ERROR_NUMMAX					(18U)
#define HE99MD_HB_DIAG_OV_MASK						(0x02U)
#define HE99MD_HB_DIAG_UV_MASK						(0x04U)
#define HE99MD_HB_DIAG_OC_OPL_MASK					(0x03U)
/*************************************DIAG_END**************************************************/

/*
 * ***********************************Global*******************************************************
 */
static uint16 EH_numDiagClearCnt = 0;
static uint8 EH_valHE99MD_MainFctStep_Mp;
static uint8 EH_valInitStat[HE99MD_CHIP_MAX];
const uint8 EH_valDrvChann_Mp[HE99MD_CHIP_MAX]= {
		IOHWABS_DIOCHANNEL_MCU_D_HB_EN,
};
static uint8 EH_valMainFctSndReq_Mp[HE99MD_CHIP_MAX];
static uint8 EH_valDutyLast_Mp[HE99MD_CHIP_MAX][HE99MD_CHIP_HB_NUM_MAX];
static uint16 EH_Prv_valSpiState_Mp[HE99MD_CHIP_MAX];
static uint16 EH_valSpiInitRxBuf_Mp[HE99MD_CHIP_MAX][HE99MD_INIT_SEQUENCE_MAX];
static uint16 EH_valSpiCtrlTxBuf_Mp[HE99MD_CHIP_MAX][HE99MD_CTRL_SEQUENCE_MAX];
static uint16 EH_valSpiCtrlRxBuf_Mp[HE99MD_CHIP_MAX][HE99MD_CTRL_SEQUENCE_MAX];
static uint16 EH_valSpiDiagRxBuf_Mp[HE99MD_CHIP_MAX][HE99MD_DIAG_SEQUENCE_MAX];
static DrivingMode_Str EH_valDrvModeLast_Mp[HE99MD_CHIP_MAX][HE99MD_CHIP_HB_NUM_MAX];
static Hb_Fct_Str EH_valFctLast_Mp[HE99MD_CHIP_MAX][HE99MD_CHIP_HB_NUM_MAX];
static Motor_Freq_Str EH_valFreqLast_Mp[HE99MD_CHIP_MAX][HE99MD_CHIP_HB_NUM_MAX];
HbDrv_Stat_Str EH_valOpMode_Mp[HE99MD_CHIP_MAX] = {HbDrv_Stat_Normal};
HbDrv_MainFctStep_Str EH_valMainFctStep_Mp = HbDrv_MainFctStep_Init;
const Eh_ErrorIdMap_Str Eh_valErridMap[8] =
{
    {ERRORID_HE99MD_EXT_HB5_OC, ERRORID_HE99MD_EXT_HB5_OPL},
    {ERRORID_HE99MD_EXT_HB8_OC, ERRORID_HE99MD_EXT_HB8_OPL},
    {ERRORID_HE99MD_EXT_HB7_OC, ERRORID_HE99MD_EXT_HB7_OPL},
    {ERRORID_HE99MD_EXT_HB3_OC, ERRORID_HE99MD_EXT_HB3_OPL},
    {ERRORID_HE99MD_EXT_HB2_OC, ERRORID_HE99MD_EXT_HB2_OPL},
    {ERRORID_HE99MD_EXT_HB1_OC, ERRORID_HE99MD_EXT_HB1_OPL},
    {ERRORID_HE99MD_EXT_HB4_OC, ERRORID_HE99MD_EXT_HB4_OPL},
    {ERRORID_HE99MD_EXT_HB6_OC, ERRORID_HE99MD_EXT_HB6_OPL},
};
const uint8 EH_SuppressChannMap[HE99MD_CHIP_HB_NUM_MAX] = 
{
	EH_HB5_Ch_C,
	EH_HB8_Ch_C,
	EH_HB7_Ch_C,
	EH_HB3_Ch_C,
	EH_HB2_Ch_C,
	EH_HB1_Ch_C,
	EH_HB4_Ch_C,
	EH_HB6_Ch_C
};

uint8 HBridge_SetChannelOutputCtrl
(
	uint8 HBDrv_Channel, DrivingMode_Str HBDrv_PwmCtrl, Hb_Fct_Str HBDrv_Fct,
	Motor_Freq_Str HBDrv_Freq, uint8 HBDrv_Duty
);
/**
 * @brief 用于并联情况下的诊断状态判断，该函数期望检查3个连续的通道
 * 
 * @param input_buf 输入的数据
 * 
 * @param start_pos 开始的位置 range: 0 ~ 4
 * 
 * @param end_pos 结束的位置 range: 0 ~ 4
 * 
 * @param mask 掩码
 * 
 * @return 返回是/否有错误
 */
static uint8 checkbitsforerror(uint8* input_buf, uint8 start_pos, uint8 end_pos, uint8 mask)
{
    uint8 i = 0;
    uint8 ret_val = 0;
    uint8 status[3] = {0};

    if((end_pos - start_pos) > 3)
        return ret_val;

    while((start_pos < end_pos) && (i < 3))
    {
        if(0 != ((*input_buf >> 2 * start_pos) & mask))
            status[i] = 1;
        else
            status[i] = 0;
        start_pos++;
        i++;
    }

    if(status[0] &&\
        status[1] &&\
        status[2])
        ret_val = 1;
    else
        ret_val = 0;

    return ret_val;
}

static void processchip0Diagnosis(uint8* input_buf)
{
    uint8 j = 0;

    for(j = 0;j < 4;j++)
    {
        ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD_EXT_HB1_OC + 2 * j, (((input_buf[HE99MD_HB_DIAG_STATUSREG1] >> (2 * j)) & HE99MD_HB_DIAG_OC_OPL_MASK) != 0 ? ED_Status_NOK : ED_Status_OK));
        ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD_EXT_HB5_OC + 2 * j, (((input_buf[HE99MD_HB_DIAG_STATUSREG2] >> (2 * j)) & HE99MD_HB_DIAG_OC_OPL_MASK) != 0 ? ED_Status_NOK : ED_Status_OK));
        ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD_EXT_HB1_OPL + 2 * j, (((input_buf[HE99MD_HB_DIAG_STATUSREG3] >> (2 * j)) & HE99MD_HB_DIAG_OC_OPL_MASK) != 0 ? ED_Status_NOK : ED_Status_OK));
        ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD_EXT_HB5_OPL + 2 * j, (((input_buf[HE99MD_HB_DIAG_STATUSREG4] >> (2 * j)) & HE99MD_HB_DIAG_OC_OPL_MASK) != 0 ? ED_Status_NOK : ED_Status_OK));
    }
}

static void processchip1Diagnosis(uint8* input_buf)
{
    uint8 iserror = FALSE;
    uint8 mask = HE99MD_HB_DIAG_OC_OPL_MASK;

    // /* OC诊断 */
    // iserror = checkbitsforerror(&input_buf[HE99MD_HB_DIAG_STATUSREG1], 0, 3, mask);
    // Cdd_ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD2_123_EXT_HS1_OC, iserror ? ED_Status_NOK : ED_Status_OK);

    // iserror = (0 != ((input_buf[HE99MD_HB_DIAG_STATUSREG1] >> 6) & mask));
    // Cdd_ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD2_4_EXT_HB9_OC, iserror ? ED_Status_NOK : ED_Status_OK);

    // iserror = checkbitsforerror(&input_buf[HE99MD_HB_DIAG_STATUSREG2], 1, 4, mask);
    // Cdd_ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD2_678_EXT_HS2_OC, iserror ? ED_Status_NOK : ED_Status_OK);

    // iserror = (0 != ((input_buf[HE99MD_HB_DIAG_STATUSREG2] >> 0) & mask));
    // Cdd_ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD2_5_EXT_HB10_OC, iserror ? ED_Status_NOK : ED_Status_OK);

    // /* OPL诊断 */
    // iserror = checkbitsforerror(&input_buf[HE99MD_HB_DIAG_STATUSREG3], 0, 3, mask);
    // Cdd_ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD2_123_EXT_HS1_OPL, iserror ? ED_Status_NOK : ED_Status_OK);

    // iserror = (0 != ((input_buf[HE99MD_HB_DIAG_STATUSREG3] >> 6) & mask));
    // Cdd_ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD2_4_EXT_HB9_OPL, iserror ? ED_Status_NOK : ED_Status_OK);

    // iserror = checkbitsforerror(&input_buf[HE99MD_HB_DIAG_STATUSREG4], 1, 4, mask);
    // Cdd_ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD2_678_EXT_HS2_OPL, iserror ? ED_Status_NOK : ED_Status_OK);

    // iserror = (0 != ((input_buf[HE99MD_HB_DIAG_STATUSREG4] >> 0) & mask));
    // Cdd_ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD2_5_EXT_HB10_OPL, iserror ? ED_Status_NOK : ED_Status_OK);
}

static uint8 HalfBridge_ComputeDuty(uint8 Para)
{
	uint8 EH_valDuty_Lo = 0;

	if(Para)
	{
		EH_valDuty_Lo = CALC_DUTY(Para);
	}
	else
	{
		EH_valDuty_Lo = Para;
	}

	return EH_valDuty_Lo;
}

void HBridge_Init(void)
{
	uint8 EH_valDrvIdx_Lo;

	for(EH_valDrvIdx_Lo = 0; EH_valDrvIdx_Lo < HE99MD_CHIP_MAX; EH_valDrvIdx_Lo++)
	{
		if(NULL_PTR != EH_valFctP_Mp[EH_valDrvIdx_Lo].Init)
		{
			EH_valFctP_Mp[EH_valDrvIdx_Lo].Init(EH_valDrvIdx_Lo);
			EH_valInitStat[EH_valDrvIdx_Lo] = 1;
		}
		else
		{}
	}
}

void HBridge_HE99MD_Init(uint8 HBDriver)
{
	uint8 n = 0;
	uint8 EH_valInitIdx_Lo = 0;
	uint8 EH_valSize_Lo = 0;
	uint8 EH_valInitStart_Lo = 0;
	uint8 EH_valCtrlStart_Lo = 0;

	EH_valInitIdx_Lo = EH_valSpiArray_Mp[HBDriver].No;
	EH_valInitStart_Lo = EH_valSpiArray_Mp[EH_valInitIdx_Lo].InitStartPos;
	EH_valCtrlStart_Lo = EH_valSpiArray_Mp[EH_valInitIdx_Lo].ControlStartPos;
	EH_valSize_Lo = (EH_valCtrlStart_Lo - EH_valInitStart_Lo);

	Hbridge_SPI_RW_Function(EH_valSpiArray_Mp[EH_valInitIdx_Lo].Channel,
							EH_valSpiArray_Mp[EH_valInitIdx_Lo].Sequence,
							&EH_valCfgSpiChannel_Mp[EH_valInitStart_Lo],
							&EH_valSpiInitRxBuf_Mp[EH_valInitIdx_Lo][0],
							EH_valSize_Lo);

	EH_valSize_Lo = (EH_valSpiArray_Mp[EH_valInitIdx_Lo].ControlEndPos - EH_valCtrlStart_Lo);

	for(n = 0;n < EH_valSize_Lo;n++)
	{
		EH_valSpiCtrlTxBuf_Mp[EH_valInitIdx_Lo][n] = EH_valCfgSpiChannel_Mp[n + EH_valCtrlStart_Lo];
	}
	EH_He99md_RecoverFunction(0);
}

void HBridge_HE99MD_SetOpMode(uint8 HBDrv_Channel, HbDrv_Stat_Str HBDrv_Stat)
{
	EH_valOpMode_Mp[HBDrv_Channel] = HBDrv_Stat;
}

#if HBDRV_PARALLEL_MODE_SUPPORT
#else
void HBridge_HE99MD_OutputCtrl
(
	uint8 HBDrv_Channel, DrivingMode_Str HBDrv_PwmCtrl, Hb_Fct_Str HBDrv_Fct,
	Motor_Freq_Str HBDrv_Freq, uint8 HBDrv_Duty
)
{
	uint8 EH_valDuty_Lo = HalfBridge_ComputeDuty(HBDrv_Duty);
	uint8 EH_valQuotient_Lo = HBDrv_Channel / HE99MD_CHIP_HB_NUM_MAX;
	uint8 EH_valRemainder_Lo = HBDrv_Channel % HE99MD_CHIP_HB_NUM_MAX;

	if(HBDrv_PwmCtrl != EH_valDrvModeLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo])
	{
		if(DrivingMode_PWM == HBDrv_PwmCtrl)
		{
//			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG0d] &= ~SHIFT_1BIT(1, EH_valRemainder_Lo);
//			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG0d] |= SHIFT_1BIT(1, EH_valRemainder_Lo);
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG0c] &= ~SHIFT_1BIT(1, EH_valRemainder_Lo);
		}
		else
		{
//			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG0d] &= ~SHIFT_1BIT(1, EH_valRemainder_Lo);
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG0c] |= SHIFT_1BIT(1, EH_valRemainder_Lo);
		}
		EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG0b] &= ~SHIFT_1BIT(1, EH_valRemainder_Lo);
		EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG0b] |= SHIFT_1BIT((uint8)HBDrv_PwmCtrl, EH_valRemainder_Lo);
		EH_Prv_valSpiState_Mp[EH_valQuotient_Lo] |= (HB_HE99MD_SPI_STATE_PWMMODE_MASK
													| HB_HE99MD_SPI_STATE_PWMGEN_MASK
													| HB_HE99MD_SPI_STATE_PWMFW_MASK);
		EH_valDrvModeLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo] = HBDrv_PwmCtrl;
	}
	else
	{}

	if(EH_valDuty_Lo != EH_valDutyLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo])
	{
		EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG15 + EH_valRemainder_Lo] &= HB_CFG_HE99MD_DUTY_MASK;
		EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG15 + EH_valRemainder_Lo] |= EH_valDuty_Lo;
		EH_Prv_valSpiState_Mp[EH_valQuotient_Lo] |= SHIFT_1BIT(HB_HE99MD_SPI_STATE_DUTY_MASK_BASE,EH_valRemainder_Lo);
		EH_valDutyLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo] = EH_valDuty_Lo;
	}
	else
	{}

	if(EH_valRemainder_Lo < HB_CFG_HE99MD_SPI_REG14_OFFSET)
	{
		if(HBDrv_Freq != EH_valFreqLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo])
		{
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG13] &= ~SHIFT_2BIT(HB_CFG_HE99MD_FREQ_FCT_MASK, EH_valRemainder_Lo);
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG13] |= SHIFT_2BIT((uint8)HBDrv_Freq, EH_valRemainder_Lo);
			EH_Prv_valSpiState_Mp[EH_valQuotient_Lo] |= HB_HE99MD_SPI_STATE_FREQ1_MASK;
			EH_valFreqLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo] = HBDrv_Freq;
		}
		else
		{}
	}
	else
	{
		if(HBDrv_Freq != EH_valFreqLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo])
		{
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG14] &= ~SHIFT_2BIT(HB_CFG_HE99MD_FREQ_FCT_MASK, (EH_valRemainder_Lo - HB_CFG_HE99MD_SPI_REG14_OFFSET));
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG14] |= SHIFT_2BIT((uint8)HBDrv_Freq, (EH_valRemainder_Lo - HB_CFG_HE99MD_SPI_REG14_OFFSET));
			EH_Prv_valSpiState_Mp[EH_valQuotient_Lo] |= HB_HE99MD_SPI_STATE_FREQ2_MASK;
			EH_valFreqLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo] = HBDrv_Freq;
		}
		else
		{}
	}

	if(EH_valRemainder_Lo < HB_CFG_HE99MD_SPI_REG09_OFFSET)
	{
		if(HBDrv_Fct != EH_valFctLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo])
		{
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG08] &= ~SHIFT_2BIT(HB_CFG_HE99MD_FREQ_FCT_MASK, EH_valRemainder_Lo);
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG08] |= SHIFT_2BIT((uint8)HBDrv_Fct, EH_valRemainder_Lo);
			EH_Prv_valSpiState_Mp[EH_valQuotient_Lo] |= HB_HE99MD_SPI_STATE_CTRL1_MASK;
			EH_valFctLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo] = HBDrv_Fct;
		}
		else
		{}
	}
	else
	{
		if(HBDrv_Fct != EH_valFctLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo])
		{
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG09] &= ~SHIFT_2BIT(HB_CFG_HE99MD_FREQ_FCT_MASK, (EH_valRemainder_Lo - HB_CFG_HE99MD_SPI_REG09_OFFSET));
			EH_valSpiCtrlTxBuf_Mp[EH_valQuotient_Lo][HB_CFG_HE99MD_SPI_REG09] |= SHIFT_2BIT((uint8)HBDrv_Fct, (EH_valRemainder_Lo - HB_CFG_HE99MD_SPI_REG09_OFFSET));
			EH_Prv_valSpiState_Mp[EH_valQuotient_Lo] |= HB_HE99MD_SPI_STATE_CTRL2_MASK;
			EH_valFctLast_Mp[EH_valQuotient_Lo][EH_valRemainder_Lo] = HBDrv_Fct;
		}
		else
		{}
	}
}
#endif

void HBridge_HE99MD_MainFunction(void)
{
	uint8 EH_valCtrlCnter_Lo = 0;
    uint8 EH_valChipIndex_Lo = 0;
    uint8 EH_valSize_Lo = 0;
    uint8 EH_valDiagStart_Lo = 0;
    uint8 Eh_valDiagChannel_Lo = 0;

	// EH_valChipIndex_Lo = EH_valHE99MD_MainFctStep_Mp % 2;
	// EH_valHE99MD_MainFctStep_Mp++;

	//Mode
	switch(EH_valOpMode_Mp[EH_valChipIndex_Lo])
	{
		case HbDrv_Stat_Normal :
		{
			IoHwAbs_DIO_SetChannelValue(EH_valDrvChann_Mp[EH_valChipIndex_Lo], TRUE);
			break;
		}
		case HbDrv_Stat_Sleep :
		{
			IoHwAbs_DIO_SetChannelValue(EH_valDrvChann_Mp[EH_valChipIndex_Lo], FALSE);
			break;
		}
		case HbDrv_Stat_LimpHome :
		{
			//Reserved
			break;
		}
		default :
		{
			break;
		}
	}

	//Ctrl
    for(uint8 EH_valChipChannel_Lo = 0;EH_valChipChannel_Lo < 8;EH_valChipChannel_Lo++)
    {
        switch (EH_valChipChannel_Lo)
        {
            case 0:  Eh_valDiagChannel_Lo = 5;  break;
            case 1:  Eh_valDiagChannel_Lo = 4;  break;
            case 2:  Eh_valDiagChannel_Lo = 3;  break;
            case 3:  Eh_valDiagChannel_Lo = 6;  break;
            case 4:  Eh_valDiagChannel_Lo = 0;  break;
            case 5:  Eh_valDiagChannel_Lo = 7;  break;
            case 6:  Eh_valDiagChannel_Lo = 2;  break;
            case 7:  Eh_valDiagChannel_Lo = 1;  break;
            default:
                // return HE99MD_RETVAL_ERR_CHANNEL_OVER_RANGE;
        }

        if(true == EH_GetOutputDisFlag(EH_SuppressChannMap[Eh_valDiagChannel_Lo]))
        {
            HBridge_SetChannelOutputCtrl(Eh_valDiagChannel_Lo, \
                                        DrivingMode_Continuous,\
                                        HBridge_Fct_OFF,\
                                        1U,\
                                        0);
        } 
    }
    

	for(EH_valCtrlCnter_Lo = 0;EH_valCtrlCnter_Lo < HE99MD_CTRL_SEQUENCE_MAX;EH_valCtrlCnter_Lo++)
	{
		if(EH_Prv_valSpiState_Mp[EH_valChipIndex_Lo] & SHIFT_1BIT(1, EH_valCtrlCnter_Lo))
		{
			EH_Prv_valSpiState_Mp[EH_valChipIndex_Lo] &= ~SHIFT_1BIT(1, EH_valCtrlCnter_Lo);
			EH_valMainFctSndReq_Mp[EH_valChipIndex_Lo] = 1;
		}
	}

	if(0 != EH_valMainFctSndReq_Mp[EH_valChipIndex_Lo])
	{  
        Hbridge_SPI_RW_Function(EH_valSpiArray_Mp[EH_valChipIndex_Lo].Channel,
								EH_valSpiArray_Mp[EH_valChipIndex_Lo].Sequence,
								&EH_valSpiCtrlTxBuf_Mp[EH_valChipIndex_Lo][0],
								&EH_valSpiCtrlRxBuf_Mp[EH_valChipIndex_Lo][0],
								HE99MD_CTRL_SEQUENCE_MAX);
        EH_valMainFctSndReq_Mp[EH_valChipIndex_Lo] = 0;
	}
	//Diag
	EH_valDiagStart_Lo = EH_valSpiArray_Mp[EH_valChipIndex_Lo].ControlEndPos;
	EH_valSize_Lo = EH_valSpiArray_Mp[EH_valChipIndex_Lo].DiagEndPos - EH_valDiagStart_Lo;
	Hbridge_SPI_RW_Function(EH_valSpiArray_Mp[EH_valChipIndex_Lo].Channel,
							EH_valSpiArray_Mp[EH_valChipIndex_Lo].Sequence,
							&EH_valCfgSpiChannel_Mp[EH_valDiagStart_Lo],
							&EH_valSpiDiagRxBuf_Mp[EH_valChipIndex_Lo][0],
							EH_valSize_Lo);
	if(EH_valSpiDiagRxBuf_Mp[EH_valChipIndex_Lo][0] & 0x18)
	{
		if(EH_numDiagClearCnt < 100)
		{
			EH_numDiagClearCnt++;
		}
		else
		{
			EH_numDiagClearCnt = 0;
			EH_He99md_RecoverFunction(0);

		}


	}

}

void HBridge_MainFunction(void)
{
	switch(EH_valMainFctStep_Mp)
	{
		case HbDrv_MainFctStep_Init :
		{
			HBridge_Init();
			EH_valMainFctStep_Mp = HbDrv_MainFctStep_Normal;
			break;
		}
		case HbDrv_MainFctStep_Normal :
		{
			HBridge_HE99MD_MainFunction();
			break;
		}
		default :
		{
			break;
		}
	}
}

#if HBDRV_PARALLEL_MODE_SUPPORT
#else
uint8 HBridge_SetChannelOutputCtrl
(
	uint8 HBDrv_Channel, DrivingMode_Str HBDrv_PwmCtrl, Hb_Fct_Str HBDrv_Fct,
	Motor_Freq_Str HBDrv_Freq, uint8 HBDrv_Duty
)
{
	uint8 EH_valDriver_Lo = HBDrv_Channel/ HE99MD_CHIP_HB_NUM_MAX;
	uint8 EH_valRetVal_Lo = HE99MD_RETVAL_OK;

	if(1 != EH_valInitStat[EH_valDriver_Lo])
	{
		EH_valRetVal_Lo = HE99MD_RETVAL_ERR_INIT;
	}
	else if(HBDrv_Channel >= HE99MD_CHANNEL_NUM_MAX)
	{
		EH_valRetVal_Lo = HE99MD_RETVAL_ERR_CHANNEL_OVER_RANGE;
	}
	else if(HBDrv_Duty > HE99MD_HB_PWM_DUTY_VALUE_MAX)
	{
		EH_valRetVal_Lo = HE99MD_RETVAL_ERR_SET_PWM;
	}
	else
	{
		if(NULL_PTR != EH_valFctP_Mp[EH_valDriver_Lo].Output)
		{
			EH_valFctP_Mp[EH_valDriver_Lo].Output(HBDrv_Channel, HBDrv_PwmCtrl, HBDrv_Fct, HBDrv_Freq, HBDrv_Duty);
		}
		else
		{}
	}

	return EH_valRetVal_Lo;
}
#endif

uint8 HalfBridgeDrv_SetOpMode(uint8 Hb_valController, HbDrv_Stat_Str Hb_valStat)
{
	uint8 EH_valRetVal_Lo = HE99MD_RETVAL_OK;

	if(1 != EH_valInitStat[Hb_valController])
	{
		EH_valRetVal_Lo = HE99MD_RETVAL_ERR_INIT;
	}
	else if(Hb_valController >= HE99MD_CHIP_MAX)
	{
		EH_valRetVal_Lo = HE99MD_RETVAL_ERR_CTRL_OVER_RANGE;
	}
	else
	{
		if(NULL_PTR != EH_valFctP_Mp[Hb_valController].Mode)
		{
			EH_valFctP_Mp[Hb_valController].Mode(Hb_valController, Hb_valStat);
		}
		else
		{}
	}

	return EH_valRetVal_Lo;
}

uint8 Cdd_HalfBridegeOut_Function(
	uint8 Hb_valChannel, uint8 Hb_valPwmMode, uint8 Hb_valFct,
	uint8 Hb_valFreq, uint8 Hb_valDuty
)
{
	uint8 Eh_valRetVal_Lo = HE99MD_RETVAL_OK;
    uint8 Eh_valActualChannel_Lo;

	if((Hb_valPwmMode > HE99MD_HB_PWM_MODE_VALUE_MAX) || (Hb_valFct > HE99MD_HB_FCT_VALUE_MAX))
		return HE99MD_RETVAL_ERR_CTRL_OVER_RANGE;

	if(Hb_valChannel >= EXT_D_HB_CHANNEL_MAX)
		return HE99MD_RETVAL_ERR_CHANNEL_OVER_RANGE;

	if((Hb_valFreq > HE99MD_HB_PWM_FREQ_VALUE_MAX) || (Hb_valDuty > HE99MD_HB_PWM_DUTY_VALUE_MAX))
		return HE99MD_RETVAL_ERR_SET_PWM;

    switch (Hb_valChannel)
	{
		case 0:  Eh_valActualChannel_Lo = 5;  break;
		case 1:  Eh_valActualChannel_Lo = 4;  break;
		case 2:  Eh_valActualChannel_Lo = 3;  break;
		case 3:  Eh_valActualChannel_Lo = 6;  break;
		case 4:  Eh_valActualChannel_Lo = 0;  break;
		case 5:  Eh_valActualChannel_Lo = 7;  break;
		case 6:  Eh_valActualChannel_Lo = 2;  break;
		case 7:  Eh_valActualChannel_Lo = 1;  break;
		default:
			return HE99MD_RETVAL_ERR_CHANNEL_OVER_RANGE;
	}

    Eh_valRetVal_Lo = HBridge_SetChannelOutputCtrl(Eh_valActualChannel_Lo, \
                                                (DrivingMode_Str)Hb_valPwmMode,\
                                                (Hb_Fct_Str)Hb_valFct,\
                                                (Motor_Freq_Str)Hb_valFreq,\
                                                Hb_valDuty);

	return Eh_valRetVal_Lo;
}
uint16_t merge_u8_to_u16(uint8_t high_byte, uint8_t low_byte)
{
    return ((uint16_t)high_byte << 8) | low_byte;
}

void EH_He99md_DiagFunction(void)
{
    uint8 i = 0;
    uint8 j = 0;
    uint8 numLoop = 0;
	uint8 EH_valDiagRegData_Lo[HE99MD_CHIP_MAX][HE99MD_DIAG_SEQUENCE_MAX] = {0};
	uint16 EH_valOCReg_Lo = 0;
	uint16 EH_valOLReg_Lo = 0;
    for(i = 0;i < HE99MD_CHIP_MAX;i++)
    {
        for(j = 0;j < HE99MD_DIAG_SEQUENCE_MAX; j++)
        {
            EH_valDiagRegData_Lo[i][j] = EH_valSpiDiagRxBuf_Mp[i][j] & 0xFF;
        }

        /* 这里是相同的处理 */
        ErrorDiag_Send_ErrorStatus( ERRORID_HE99MD_OV, ((EH_valDiagRegData_Lo[i][HE99MD_HB_DIAG_STATUSREG0] & HE99MD_HB_DIAG_OV_MASK) != 0 ? ED_Status_NOK : ED_Status_OK));
        ErrorDiag_Send_ErrorStatus(ERRORID_HE99MD_UV, ((EH_valDiagRegData_Lo[i][HE99MD_HB_DIAG_STATUSREG0] & HE99MD_HB_DIAG_UV_MASK) != 0 ? ED_Status_NOK : ED_Status_OK));

        EH_valOCReg_Lo = merge_u8_to_u16(EH_valDiagRegData_Lo[i][HE99MD_HB_DIAG_STATUSREG2],EH_valDiagRegData_Lo[i][HE99MD_HB_DIAG_STATUSREG1]);
        EH_valOLReg_Lo = merge_u8_to_u16(EH_valDiagRegData_Lo[i][HE99MD_HB_DIAG_STATUSREG4],EH_valDiagRegData_Lo[i][HE99MD_HB_DIAG_STATUSREG3]);

        for(numLoop = 0; numLoop <8;numLoop++)
        {
        	ErrorDiag_Send_ErrorStatus(Eh_valErridMap[numLoop].OC_Errorid,(((EH_valOCReg_Lo >> (2 * numLoop)) & HE99MD_HB_DIAG_OC_OPL_MASK)  != 0 ? ED_Status_NOK : ED_Status_OK));
        	ErrorDiag_Send_ErrorStatus(Eh_valErridMap[numLoop].OL_Errorid,(((EH_valOLReg_Lo >> (2 * numLoop)) & HE99MD_HB_DIAG_OC_OPL_MASK)  != 0 ? ED_Status_NOK : ED_Status_OK));
        }
    }
}

void EH_He99md_RecoverFunction(uint8 HBDriver)
{
	uint16 EH_valTxData_Lo = HE99MD_RECOVER_REG_VAL;
	uint16 EH_valRxData_Lo = 0;

    Hbridge_SPI_RW_Function(EH_valSpiArray_Mp[HBDriver].Channel,
                            EH_valSpiArray_Mp[HBDriver].Sequence,
                            &EH_valTxData_Lo,
                            &EH_valRxData_Lo,
                            1);
}
