/*** create info ***********************
*@ Author : liufengyuan
*@ date :2024-12-02
*@ Description :Abstraction Layer ICU configuration file
**** modify info ***********************
*@ version :0.0
*@ Modifier : liufengyuan
*@ date :2024-12-02
*@ Modification Description :
初始版本
****************************************/

/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "IoHwAbs_ICU_Cfg.h"
#include "IoHwAbs_ICU.h"
#include "Icu.h"
#include "IoHwAbs_ICU_prv.h"
#include "Icu_Cfg.h"

/* 外部变量声明 */
extern uint32 Icu_valBuffer_TimeStamp_Mp[PWM_INPUT_DMA_MAX_CHANNELS][ICU_DMA_TIMESTAMP_BUFFERSIZE];

/* ICU抽象通道和对应配置通道 */
const IoHwAbs_IcuConfig_TDSTR IoHwAbs_valIcuConfig_STR[PWM_INPUT_DMA_MAX_CHANNELS] = {    
    { IOHWABS_ICU_PwmIn_CH1           ,   IcuChannel_PWM_CH1            ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[0][0]},
    { IOHWABS_ICU_PwmIn_CH3           ,   IcuChannel_PWM_CH3            ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[1][0]},
    { IOHWABS_ICU_PwmIn_CH5           ,   IcuChannel_PWM_CH5            ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[2][0]},
    { IOHWABS_ICU_PwmIn_CH6           ,   IcuChannel_PWM_CH6            ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[3][0]},
    { IOHWABS_ICU_PwmIn_CH7           ,   IcuChannel_PWM_CH7            ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[4][0]},
    { IOHWABS_ICU_PWM_OUT_FB1_PVF     ,   Icu_IcuChannel_PWM_OUT_FB1    ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[5][0]},
    { IOHWABS_ICU_PWM_OUT_FB2_PVF     ,   Icu_IcuChannel_PWM_OUT_FB2    ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[6][0]},
    { IOHWABS_ICU_PWM_OUT_FB4_PVF     ,   Icu_IcuChannel_PWM_OUT_FB4    ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[7][0]},
    { IOHWABS_ICU_PWM_OUT_FB5_PVF     ,   Icu_IcuChannel_PWM_OUT_FB5    ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[8][0]},
    { IOHWABS_ICU_PWM_OUT_FB6_PVF     ,   Icu_IcuChannel_PWM_OUT_FB6    ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[9][0]},
    { IOHWABS_ICU_PWM_OUT_FB10_PVF    ,   Icu_IcuChannel_PWM_OUT_FB10   ,   50      ,   &Icu_valBuffer_TimeStamp_Mp[10][0]},
};


