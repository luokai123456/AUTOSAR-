/*** create info *********************** 
* @ Author : liufengyuan 
* @ date :2024-12-02 
* @ Description :Abstraction Layer ICU file. PWM acquisition function 
**** modify info *********************** 
* @ version :0.0 
* @ Modifier : liufengyuan 
* @ date :2024-12-02 
* @ Modification Description : 闁告帗绻傞～鎰版偋閸喐鎷 
****************************************/ 
/*******************************************************************************
 * Includes
*******************************************************************************/
#include "IoHwAbs_ICU_prv.h"
#include "eMIOS_LLDriver.h"
#include "eDma_LLDriver.h"
#include "Icu.h"
#include "Icu_Cfg.h"
#include "IoHwAbs_DIO_prv.h"
#include "IoHwAbs_ICU_Cfg.h"
#include "gtm410_reg.h"
/*******************************************************************************
 * Variables
*******************************************************************************/
/* 假设主函数周期为10ms，110 * 10ms = 1100ms = 1.1s */
#define ICU_FILTER_TIMEOUT_TICKS  110U

static const uint8 Icu_valDMAChannel_Map_Arr[PWM_INPUT_DMA_MAX_CHANNELS] = 
{
    ICU_PWM_CH1_DMACHANNEL,
    ICU_PWM_CH3_DMACHANNEL,
    ICU_PWM_CH5_DMACHANNEL,
    ICU_PWM_CH6_DMACHANNEL,
    ICU_PWM_CH7_DMACHANNEL,
    ICU_FB1_PVF_DMACHANNEL,
    ICU_FB2_PVF_DMACHANNEL,
    ICU_FB4_PVF_DMACHANNEL,
    ICU_FB5_PVF_DMACHANNEL,
    ICU_FB6_PVF_DMACHANNEL,
    ICU_FB10_PVF_DMACHANNEL,
};

static const Icu_GetDutyChnCfg_TDSTR Icu_valIcuChannel_Map_Arr[PWM_INPUT_ICU_SIGNAL_MAX_CHANNELS] = 
{
    {IOHWABS_ICU_PwmIn_CH2,         IcuChannel_PWM_CH2},
    {IOHWABS_ICU_PwmIn_CH4,         IcuChannel_PWM_CH4},
    {IOHWABS_ICU_PWM_OUT_FB3_PVF,   IcuChannel_PWM_OUT_FB3},
    {IOHWABS_ICU_PwmIn_CH8,         Icu_PWM_CH8},
    {IOHWABS_ICU_PwmIn_CH9,         Icu_PWM_CH9},
    {IOHWABS_ICU_PWM_OUT_FB11_PVF,  Icu_MCU_PWM_OUT_FB11},
    {IOHWABS_ICU_MCU_DI_OCPorOV_TRIGGER, Icu_MCU_DI_OCPorOV_TRIGGER},
};

uint32 Icu_valBuffer_TimeStamp_Mp[PWM_INPUT_DMA_MAX_CHANNELS][ICU_DMA_TIMESTAMP_BUFFERSIZE] = {{0}};
uint32_t Icu_valCurrentTsResult_Arr[PWM_INPUT_DMA_MAX_CHANNELS][ICU_DMA_TIMESTAMP_BUFFERSIZE] = {{0}};
uint16 Icu_valCurrentTsPosition_Arr[PWM_INPUT_DMA_MAX_CHANNELS] = {0};

/*******************************************************************************
 * Function Prototypes
*******************************************************************************
/**
 * 闁告垼濮ら弳鐔煎触瀹ュ泦锟�: IoHwAbs_Icu_Init
 * 闁告瑥鍊归弳锟�: void
 * 閺夆晜鏌ㄥú鏍磹閿燂拷: void
 * 闁硅绻楅崼锟�: 
 */
/**
 * @brief 闁告帗绻傞～鎰板礌閺堟弲U(閺夊牊鎸搁崣鍡涘箲閺団崇闁告娲栭崢锟�)缁绢収鍏涘▎銏ゅ箮閸婄喕鏉介悘鐑囨嫹
 * @details 閻犲洢鍎遍崵閬嶅极閹殿喗鏆忓ù婊冮閸ㄥ灚鎱ㄧｎn亜顕CU婵☆垪锟借櫕鍋ラ柨娑樿嫰閼荤喖宕ラ姘楅柟纰夋嫹闁哄牆顦甸崢銈囩磾椤旂鍋ㄩ柣銊ュ殬CU闂侇偅宀告禍楣冩儍閸曨剚顦ч梻鍌氱摠閸╂垿骞戦弴鈥崇闁告梻鍠曢崗锟�
 */
void Icu_ConfigCmuClk_Func()
{
    GTM4.GLS[0].TBU.CHEN.B.ENDIS_CH1 = 1;
    GTM4.GLS[0].TBU.CH1_CTRL.B.CH_CLK_SRC = 2;
    GTM4.GLS[0].TBU.CHEN.B.ENDIS_CH1 = 2;

    GTM4_TIM2.CH[4].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM2.CH[4].CTRL.B.GPR1_SEL = 1;
    GTM4_TIM2.CH[5].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM2.CH[5].CTRL.B.GPR1_SEL = 1;

    GTM4_TIM4.CH[1].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM4.CH[1].CTRL.B.GPR1_SEL = 1;
    GTM4_TIM4.CH[2].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM4.CH[2].CTRL.B.GPR1_SEL = 1;

    GTM4_TIM4.CH[4].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM4.CH[4].CTRL.B.GPR1_SEL = 1;
    GTM4_TIM4.CH[5].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM4.CH[5].CTRL.B.GPR1_SEL = 1;
    GTM4_TIM5.CH[1].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM5.CH[1].CTRL.B.GPR1_SEL = 1;
    GTM4_TIM5.CH[2].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM5.CH[2].CTRL.B.GPR1_SEL = 1;
    GTM4_TIM5.CH[4].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM5.CH[4].CTRL.B.GPR1_SEL = 1;
    GTM4_TIM5.CH[5].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM5.CH[5].CTRL.B.GPR1_SEL = 1;
    GTM4_TIM7.CH[5].CTRL.B.GPR0_SEL = 1;
    GTM4_TIM7.CH[5].CTRL.B.GPR1_SEL = 1;

    GTM4_TIM2.CH[6].CTRL.B.CLK_SEL = 2;
    GTM4_TIM2.CH[7].CTRL.B.CLK_SEL = 2;
    GTM4_TIM7.CH[0].CTRL.B.CLK_SEL = 2;

    GTM4_TIM4.CH[6].CTRL.B.CLK_SEL = 2;
    GTM4_TIM4.CH[7].CTRL.B.CLK_SEL = 2;
    GTM4_TIM5.CH[0].CTRL.B.CLK_SEL = 2;
    GTM4_TIM5.CH[7].CTRL.B.CLK_SEL = 2;
}

void IoHwAbs_Icu_Init(void)
{
    volatile uint8 Icu_numIcuEdmaChannel_i; // 閻庤鐭粻鐑瓹U闂侇偅宀告禍鍓ф媼閳╁啯娈堕柛锝冨妼瑜板鏌岄敓锟�
    volatile uint8 Icu_numIcuSignalChannel_i; // 闁告帗绻傞～鎰板礌閺堟弲U婵☆垪锟借櫕鍋ラ柨娑樺婵炲洭鎮介妸鈺婃殨閻庤鐭粻鐔兼儍閸曨垰甯崇紓鍐惧枤缁劑寮搁崟顏嗙Ъ

    Icu_Init(&Icu_Cfg); // 鐎甸偊浜為獮鍡涘礆濠靛棭娼楅柛鏍ㄧ墬婢у秹寮垫繅鍦昒闂侇偅宀告禍锟�

    GTM4.GLS[0].TBU.CHEN.B.ENDIS_CH1 = 1;
    GTM4.GLS[0].TBU.CH1_CTRL.B.CH_CLK_SRC = 2;
    GTM4.GLS[0].TBU.CHEN.B.ENDIS_CH1 = 2;

    for(Icu_numIcuEdmaChannel_i = 0; Icu_numIcuEdmaChannel_i < 11; Icu_numIcuEdmaChannel_i++ )
    {
        Icu_StartTimestamp(IoHwAbs_valIcuConfig_STR[Icu_numIcuEdmaChannel_i].numIcuInitIdx, 
                           IoHwAbs_valIcuConfig_STR[Icu_numIcuEdmaChannel_i].IcuTimeStampBuf, 
                           IoHwAbs_valIcuConfig_STR[Icu_numIcuEdmaChannel_i].numDmaBufSize, 100);
    }

    // Icu_StartTimestamp(1, IoHwAbs_valIcuConfig_STR[0].IcuTimeStampBuf, 50, 100);

    for(Icu_numIcuSignalChannel_i = 0; Icu_numIcuSignalChannel_i < PWM_INPUT_ICU_SIGNAL_MAX_CHANNELS; Icu_numIcuSignalChannel_i++ )
    {
        Icu_StartSignalMeasurement(Icu_valIcuChannel_Map_Arr[Icu_numIcuSignalChannel_i].numIcuInitIdx);
    }
}

/**
 * 闁告垼濮ら弳鐔煎触瀹ュ泦锟�: IoHwAbs_ICU_GetTimeStampValues
 * 闁告瑥鍊归弳鐒沶: 闂侇偅宀告禍锟�
 * 闁告瑥鍊归弳鐒沶t: 闁哄啫鐖煎Λ鍧楀箣閾忣偅娈剁紓浣稿缁辨繈骞栭鍐濞达絽绉堕悿锟�
 * 閺夆晜鏌ㄥú鏍磹閿燂拷: return
 * 闁硅绻楅崼锟�: ICU 闁兼儳鍢茶ぐ鍥煂閸ヮ剚鑲犻柡鍐ㄧ埣濡潡骞嬮崗鍛鞍闁告瑥顨圡A闁圭⒈鍓濈换宥嗘媴瀹ュ洨鏋�
 */
Std_ReturnType IoHwAbs_ICU_GetTimeStampValues(uint16 channel,uint32 *Pwm_In_TimeStampResult, uint16 *TimeStampresultIdx )
{
    Std_ReturnType RetVal_LO = E_OK;
    uint8 Icu_numEdmaPos_LO = 0;
    uint8 Icu_numIcuDMAChannel_LO = 0xFF;
    uint8 Icu_numIdx_LO = 0;

    if (Pwm_In_TimeStampResult == NULL || TimeStampresultIdx == NULL)
    {
        return E_NOT_OK;
    }

    if(channel < IOHWABS_ICU_PwmIn_NUM_MAX)
    {
        Icu_numIcuDMAChannel_LO = Icu_valDMAChannel_Map_Arr[channel];
        if(Icu_numIcuDMAChannel_LO != 0xFF)
        {
            Icu_numEdmaPos_LO = (ICU_DMA_TIMESTAMP_BUFFERSIZE - EDMA_GetChnRemainingIterationsCount(Icu_numIcuDMAChannel_LO ));
            *TimeStampresultIdx = Icu_numEdmaPos_LO ;
            for(Icu_numIdx_LO = 0; Icu_numIdx_LO < ICU_DMA_TIMESTAMP_BUFFERSIZE; Icu_numIdx_LO++)
            {
                Pwm_In_TimeStampResult[Icu_numIdx_LO] = (Icu_valBuffer_TimeStamp_Mp[channel][Icu_numIdx_LO] & 0x01FFFFFFU);
            }
        }
        else
        {
            RetVal_LO = E_NOT_OK;
        }
    }
    else
    {
        RetVal_LO = E_NOT_OK;
    }

    return RetVal_LO;
}

/**
 * 闁告垼濮ら弳鐔煎触瀹ュ泦锟�: IoHwAbs_ICU_GetDifferentialCount
 * 闁告瑥鍊归弳鐒沶: 閻炴凹鍋勯崳娲极鐢喚绀夐柛鎴濈箲閺嗭拷
 * 閺夆晜鏌ㄥú鏍磹閿燂拷: 鐎瑰壊鍠栭敓鏂ゆ嫹
 * 闁硅绻楅崼锟�: 閻犱緤绱曢悾缁樼▔閵堝嫰鍤嬮悹浣插墲閺嗙喖宕愰懖鈺傜暠鐎瑰壊鍠栭敓鐣屻嬬槐婵嬫嚀閸愵厽顎氶悹浣插墲閺嗙喖宕抽妸锕顒㈤柛鎴犲劋閸庡繘宕橀敓锟�
 */
static uint32 IoHwAbs_ICU_GetDifferentialCount(uint32 numSubtraction_LO,uint32 numMinuend_LO)
{
    uint32 Icu_numDifference_LO = 0;

    if(numSubtraction_LO < numMinuend_LO)
    {
        Icu_numDifference_LO = 0xFFFFFFU + numSubtraction_LO - numMinuend_LO;
    }
    else
    {
        Icu_numDifference_LO = numSubtraction_LO - numMinuend_LO;
    }

    return Icu_numDifference_LO;
}

/**
 * 闁告垼濮ら弳鐔煎触瀹ュ泦锟�: IoHwAbs_PwmIn_GetChanneValue
 * 闁告瑥鍊归弳鐒沶: 闂侇偅宀告禍楣冨矗閿燂拷
 * 闁告瑥鍊归弳鐒沶t: PWM闂佹彃娲▔锔剧磼閹惧浜紓浣规尰閻庮垱鎷呴幘鏉戠樄闂佹枻鎷�
 * 閺夆晜鏌ㄥú鏍磹閿燂拷: return
 * 闁硅绻楅崼锟�: 闁兼儳鍢茶ぐ鍢漌M閺夊牊鎸搁崣鍡樼┍閳ュ啿濞囬柣銊ュ瀹曟壆绮氶悜妯兼Х闁告粌鐭傞。鍫曟偝閸パ嶆嫹閿燂拷
 */
uint16 Icu_numCurPos_LO[17] = {0};
uint16 Icu_numIcu_DiagPos_LO[6] = {0};
Pwm_ResultIn_TDSTR Icu_ResultInfo_Str[IOHWABS_ICU_PwmIn_NUM_MAX] = {0};

__attribute__((ghs_optimize(Onone)))
Std_ReturnType IoHwAbs_ICU_GetChanneValue(uint8 numChannel_LO, Pwm_ResultIn_TDSTR* valresult_STR)
{
    if ((numChannel_LO >= IOHWABS_ICU_PwmIn_NUM_MAX) || (valresult_STR == NULL_PTR))
    {
        return E_NOT_OK;
    }
    else
    {
        if(numChannel_LO < IOHWABS_ICU_PwmIn_NUM_MAX)
        {

            valresult_STR->numDuty = Icu_ResultInfo_Str[numChannel_LO].numDuty;
            valresult_STR->numFreq = Icu_ResultInfo_Str[numChannel_LO].numFreq;
            valresult_STR->flgActive = Icu_ResultInfo_Str[numChannel_LO].flgActive;
        }
    }
    return E_OK;
}

/* 缂傚倹鐗為惁褔宕抽妸褍顥楅悗瑙勬皑濞堟垶瀵煎Ο鍝勵嚙闁硅矇鍐ㄧ厬閻庣櫢鎷� */
#if defined(__GNUC__) || defined(__clang__)
#define NO_OPTIMIZE __attribute__((optimize("O0")))
#elif defined(_MSC_VER)
#define NO_OPTIMIZE __declspec(noinline)
#elif defined(__ghs__)
#define NO_OPTIMIZE __attribute__((ghs_optimize(Onone)))
#else
#define NO_OPTIMIZE
#endif

NO_OPTIMIZE static Std_ReturnType IoHwAbs_ICU_CalculatePwmValues(uint8_t channel, Pwm_ResultIn_TDSTR* pResult)
{
    volatile uint32_t T1 = 0U, T2 = 0U, T3 = 0U;
    volatile uint32_t T1_watch = 0U, T2_watch = 0U, T3_watch = 0U;
    uint32_t period = 0U, pulse = 0U;
    static uint16_t prevPos[PWM_INPUT_DMA_MAX_CHANNELS] = {0};
    static uint32_t prevTimestamp[PWM_INPUT_DMA_MAX_CHANNELS] = {0};
    static uint32_t noUpdateTickCount[PWM_INPUT_DMA_MAX_CHANNELS] = {0}; /* 1.1s滤波计数器 */
    volatile uint8 Icu_valPinState_lo = 0U;

    if (channel >= PWM_INPUT_DMA_MAX_CHANNELS || pResult == NULL_PTR)
    {
        return E_NOT_OK;
    }

    // 闁兼儳鍢茶ぐ鍥亹閹惧啿顤呴梺顐ｅ哺娴滈箖鎯冮崟顒侇槯闂傚倸鐡ㄩ崺鎴﹀极閻楀牆绁�
    IoHwAbs_ICU_GetTimeStampValues(channel, &Icu_valCurrentTsResult_Arr[channel][0], &Icu_valCurrentTsPosition_Arr[channel]);

    uint16_t curPos = Icu_valCurrentTsPosition_Arr[channel];
    uint32_t* curBuf = Icu_valCurrentTsResult_Arr[channel];

    // 閻犱緤绱曢悾濠氬嫉閿熶粙寮悧鍫燁槯闂傚倸鐡ㄩ崺鎴︽儍閸曨厼鍋嶇殿噯鎷�
    uint16_t idx = (curPos == 0U) ? (ICU_DMA_TIMESTAMP_BUFFERSIZE - 1U) : (curPos - 1U);
    uint32_t curTimestamp = curBuf[idx] & 0x00FFFFFFU;

    // 婵☆偓鎷烽柡灞诲劜濡炲倿姊荤�涙ê鐓堥柡鍕靛灠閹¼線寮垫径瀣函闁哄偊鎷�
    if ((prevPos[channel] == curPos) && (prevTimestamp[channel] == curTimestamp))
    {
        noUpdateTickCount[channel]++;
        
        if (noUpdateTickCount[channel] < ICU_FILTER_TIMEOUT_TICKS)
        {
            /* 1.1s内没有新结果，维持之前值，直接返回 */
            return E_OK;
        }
        else
        {
            /* 超过1.1s，清0 */
            pResult->flgActive = FALSE;
            pResult->numDuty = 0;
            pResult->numFreq = 0;
            return E_OK;
        }
    }
    else
    {
        /* 有新数据更新，重置超时计数器 */
        noUpdateTickCount[channel] = 0;
    }

    // 闁哄洤鐡ㄩ弻濠囧礈瀹ュ嫮顏辨繛鍡磿婵悂骞�閿燂拷
    prevPos[channel] = curPos;
    prevTimestamp[channel] = curTimestamp;

    // 閻犱緤绱曢悾缁樼▔婢跺鍤嬮弶鈥冨仧閻㈠寮崼鏇燂紵闁规潙纾▓鎴犳閵忕姷绌�
    uint16_t idx1 = (curPos == 0U) ? (ICU_DMA_TIMESTAMP_BUFFERSIZE - 1U) : (curPos - 1U);
    uint16_t idx2 = (idx1 == 0U) ? (ICU_DMA_TIMESTAMP_BUFFERSIZE - 1U) : (idx1 - 1U);
    uint16_t idx3 = (idx2 == 0U) ? (ICU_DMA_TIMESTAMP_BUFFERSIZE - 1U) : (idx2 - 1U);

    // 闁圭粯鍔曡ぐ鍥冀閸パ呯濞达綇鎷�
    T1_watch = curBuf[idx1] >> 24;
    T2_watch = curBuf[idx2] >> 24;
    T3_watch = curBuf[idx3] >> 24;

    // 闁圭粯鍔曡ぐ鍥籍閸洘锛熼柟鏉戝暱閿熸枻鎷�
    T1 = curBuf[idx1] & 0x00FFFFFFU;
    T2 = curBuf[idx2] & 0x00FFFFFFU;
    T3 = curBuf[idx3] & 0x00FFFFFFU;

    // 閻犱緤绱曢悾濠氬川閵婏附鍩�
    period = IoHwAbs_ICU_GetDifferentialCount(T1, T3);

    // 闁哄秷顫夊畵浣规綇鐟欏嫰鍎撮柡宥呮搐缁绘梻鎷嬮敍鍕毈闁兼潙顦锟�
    if (curBuf[curPos] & 0x01000000U) // 濞戞挸锕ゅ畷灞解柦閹稿海鍨奸煫鍥锋嫹
    {
        if ((T1_watch == T3_watch) && (T1_watch == 0))
        {
            pulse = IoHwAbs_ICU_GetDifferentialCount(T1, T2);
        }
        else
        {
            pResult->flgActive = FALSE;
            pResult->numDuty = 0;
            pResult->numFreq = 0;
            return E_OK;
        }
    }
    else // 濞戞挸顑夊宄扳柦閹稿海鍨奸煫鍥锋嫹
    {
        if ((T1_watch == T3_watch) && (T2_watch == 0))
        {
            pulse = IoHwAbs_ICU_GetDifferentialCount(T2, T3);
        }
        else
        {
            pResult->flgActive = FALSE;
            pResult->numDuty = 0;
            pResult->numFreq = 0;
            return E_OK;
        }
    }

    // 閻犱緤绱曢悾濠氬础閻樼鏁勬慨锝嗘煥閹风増锛愰幋鐘茶姵
    if (period != 0U)
    {
        uint8_t duty = (uint8_t)((pulse * 100U) / period);
        if (duty > 100U)
        {
            pResult->flgActive = FALSE;
            pResult->numDuty = 0;
            pResult->numFreq = 0;
        }
        else
        {
            pResult->flgActive = TRUE;
            pResult->numFreq = (uint16_t)(PWM_INPUT_GTM_TIMTBASE / period);
            pResult->numDuty = duty;
        }
    }
    else
    {
        pResult->flgActive = FALSE;
        pResult->numDuty = 0;
        pResult->numFreq = 0;
    }

    return E_OK;
}

uint32 Icu_valActiveTime_Arr[7] = {0};
uint32 Icu_valPeriodTime_Arr[7] = {0};
uint32 Icu_valGPR0Time_Arr[7] = {0};
uint32 Icu_valLastTime_Arr[7] = {0};

static Std_ReturnType IoHwAbs_ICU_GetSingalMeasurementValues(uint8_t channel, Pwm_ResultIn_TDSTR* valresult_STR)
{
    Icu_DutyCycleType dutyCycle = {0};
    volatile uint8 Duty_lo = 0;
    static uint32_t noUpdateTickCount[PWM_INPUT_ICU_SIGNAL_MAX_CHANNELS] = {0}; /* 1.1s滤波计数器 */

    if (channel >= PWM_INPUT_ICU_SIGNAL_MAX_CHANNELS || valresult_STR == NULL_PTR)
    {
        return E_NOT_OK;
    }
    else
    {
        switch(channel)
        {
            case 0:
                Icu_valActiveTime_Arr[0] = GTM4_TIM2.CH[6].GPR0.R & 0x00FFFFFFU;
                Icu_valPeriodTime_Arr[0] = GTM4_TIM2.CH[6].GPR1.R & 0x00FFFFFFU;
                Icu_valGPR0Time_Arr[0] = ((GTM4_TIM2.CH[6].GPR0.R & 0xFFFFFFFFU));
                break;
            case 1:
                Icu_valActiveTime_Arr[1] = GTM4_TIM2.CH[7].GPR0.R & 0x00FFFFFFU;
                Icu_valPeriodTime_Arr[1] = GTM4_TIM2.CH[7].GPR1.R & 0x00FFFFFFU;
                Icu_valGPR0Time_Arr[1] = (GTM4_TIM2.CH[7].GPR0.R);
                break;
            case 2:
                Icu_valActiveTime_Arr[2] = GTM4_TIM7.CH[0].GPR0.R & 0x00FFFFFFU;
                Icu_valPeriodTime_Arr[2] = GTM4_TIM7.CH[0].GPR1.R & 0x00FFFFFFU;
                Icu_valGPR0Time_Arr[2] = (GTM4_TIM7.CH[0].GPR0.R );
                break;

            case 3:
                Icu_valActiveTime_Arr[3] = GTM4_TIM5.CH[0].GPR0.R & 0x00FFFFFFU;
                Icu_valPeriodTime_Arr[3] = GTM4_TIM5.CH[0].GPR1.R & 0x00FFFFFFU;
                Icu_valGPR0Time_Arr[3] = (GTM4_TIM5.CH[0].GPR0.R );
                break;
            case 4:
                Icu_valActiveTime_Arr[4] = GTM4_TIM5.CH[7].GPR0.R & 0x00FFFFFFU;
                Icu_valPeriodTime_Arr[4] = GTM4_TIM5.CH[7].GPR1.R & 0x00FFFFFFU;
                Icu_valGPR0Time_Arr[4] = (GTM4_TIM5.CH[7].GPR0.R );
                break;
            case 5:
                Icu_valActiveTime_Arr[5] = GTM4_TIM4.CH[6].GPR0.R & 0x00FFFFFFU;
                Icu_valPeriodTime_Arr[5] = GTM4_TIM4.CH[6].GPR1.R & 0x00FFFFFFU;
                Icu_valGPR0Time_Arr[5] = (GTM4_TIM4.CH[6].GPR0.R );
                break;
            case 6:
                Icu_valActiveTime_Arr[6] = GTM4_TIM4.CH[7].GPR0.R & 0x00FFFFFFU;
                Icu_valPeriodTime_Arr[6] = GTM4_TIM4.CH[7].GPR1.R & 0x00FFFFFFU;
                Icu_valGPR0Time_Arr[6] = (GTM4_TIM4.CH[7].GPR0.R );
                break;
            default:
                return E_NOT_OK;
        }

        Duty_lo = (Icu_valActiveTime_Arr[channel] * 100)/ Icu_valPeriodTime_Arr[channel];

        if(Icu_valGPR0Time_Arr[channel] == Icu_valLastTime_Arr[channel])
        {
            noUpdateTickCount[channel]++;
            
            if (noUpdateTickCount[channel] < ICU_FILTER_TIMEOUT_TICKS)
            {
                /* 1.1s内没有新结果，维持之前值，直接返回 */
                return E_OK;
            }
            else
            {
                /* 超过1.1s，清0 */
                valresult_STR->flgActive = FALSE;
                valresult_STR->numDuty = 0;
                valresult_STR->numFreq = 0;
                return E_OK;
            }
        }
        else
        {
            /* 有新数据更新，重置超时计数器 */
            noUpdateTickCount[channel] = 0;
            
            if(Duty_lo < 100)
            {
                valresult_STR->flgActive = TRUE;
                valresult_STR->numDuty = (uint8_t)(100 - (uint8)((Icu_valActiveTime_Arr[channel] * 100)/ Icu_valPeriodTime_Arr[channel]));
                valresult_STR->numFreq = PWM_INPUT_GTM_TIMTBASE / Icu_valPeriodTime_Arr[channel];
                Icu_valLastTime_Arr[channel] = Icu_valGPR0Time_Arr[channel];
            }
            else
            {
                valresult_STR->flgActive = FALSE;
                valresult_STR->numDuty = 0;
                valresult_STR->numFreq = 0;
            }
        }
        return E_OK;
    }
}

/**
 * 闁告垼濮ら弳鐔煎触瀹ュ泦锟�: IoHwAbs_Icu_MainFunction
 * 闁告瑥鍊归弳锟�: void
 * 閺夆晜鏌ㄥú鏍磹閿燂拷: void
 * 闁硅绻楅崼锟�: ICU濞戞捁顕чˇ鈺呮偠閸℃姣愰柡浣稿簻缁辨繃寰勯崟顓熷為柟纰夋嫹闁哄牆顦甸敓鑺ュ哺娴滈箖鎯冮崙鐩琈閻犱緤绱曢悾锟�
 */
volatile uint8_t Icu_valChannelNum_mp = 0;
volatile uint8_t Icu_valSingalChannelNum_mp = 0;

void IoHwAbs_Icu_MainFunction(void)
{
    // 濠㈣泛瀚幃濠傂掕箛搴ㄥ殝闂侇偅宀告禍楣冩儍閸曨垼鏆ラ柣婊冩搐閹蜂即宕￠悩纰樻晞婵絾妫侀鍝ョ不閿燂拷
    for (Icu_valChannelNum_mp = 0U; Icu_valChannelNum_mp < PWM_INPUT_DMA_MAX_CHANNELS; Icu_valChannelNum_mp++)
    {
        // 濞达綀娉曢弫銈囦焊娴ｇ瓔妫呴柣銊ュ閸ら亶寮幏宀婂悁缂佺姵顨呭畷鐔哥▔椤忓牞鎷峰鏈靛
        IoHwAbs_ICU_CalculatePwmValues(Icu_valChannelNum_mp, &Icu_ResultInfo_Str[IoHwAbs_valIcuConfig_STR[Icu_valChannelNum_mp].numIcuAbsIdx]);
    }

    for (Icu_valSingalChannelNum_mp = 0U; Icu_valSingalChannelNum_mp < PWM_INPUT_ICU_SIGNAL_MAX_CHANNELS; Icu_valSingalChannelNum_mp++)
    {
        IoHwAbs_ICU_GetSingalMeasurementValues(Icu_valSingalChannelNum_mp, &Icu_ResultInfo_Str[Icu_valIcuChannel_Map_Arr[Icu_valSingalChannelNum_mp].numIcuAbsIdx]);
    }
}
