/****************************************************************
 * 模块：Cdd层 - SBC47301模块
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.2 (初始版本)
 * 1. 支持SBC47301模块的唤醒功能
 * 2. 支持SBC47301模块的状态获取功能
 * 3. 支持SBC47301模块的看门狗功能
 * 4. 支持SBC47301模块的RTC定时唤醒功能
 * 5. 支持SBC47301模块的剩余唤醒时间获取功能
 * ==================================================
 ****************************************************************/
#ifndef _CDD_SA47301_H_
#define _CDD_SA47301_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301_Type.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER             4
#define SA47301_AR_REL_MINOR_VER             4
#define SA47301_AR_REL_REV_VER               0
#define SA47301_SW_MAJOR_VER                 1
#define SA47301_SW_MINOR_VER                 0
#define SA47301_SW_PATCH_VER                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_"
#endif
#if (SA47301_AR_REL_MINOR_VER != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_"
#endif
#if (SA47301_AR_REL_REV_VER != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_"
#endif
#if (SA47301_SW_MINOR_VER != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_"
#endif
#if (SA47301_SW_PATCH_VER != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_"
#endif

#define SA47301_WDG_TYPE_WWDG 0
#define SA47301_WDG_TYPE_FWDG 1

#define SA47301_LDO_CH_TRK1     (0U)
#define SA47301_LDO_CH_TRK2     (1U)
#define SA47301_LDO_CH_COMV     (2U)
#define SA47301_LDO_CH_REFV     (3U)

#define SA47301_HWWDG_RESET_FLAG_FALSE  (0U)
#define SA47301_HWWDG_RESET_FLAG_TRUE  (1U)

typedef enum
{
    SA47301_WEAKTIME_1MS = 0,
    SA47301_WEAKTIME_1S  = 1,
} Cdd_Sa47301WeakTimeCyc_TDEN;

typedef struct 
{
    boolean fgCanAWakeUpActive;
    boolean fgCanBWakeUpActive;
	boolean fgKeyWakeUpActive;
	boolean fgAPlus1WakeUpActive;
    boolean fgAPlus2WakeUpActive;
    boolean fgOBCWakeUpActive;
    boolean fgRTCWakeUpActive;
    boolean fgAFEWakeUpActive;
}SA_WakeSrc_STDR;

typedef enum
{
    SA47301_FEED_WDG_MODE_AUTO,
    SA47301_FEED_WDG_MODE_MANUAL,
}Cdd_Sa47301WdgModeType_TDEN;

typedef enum 
{
    SA47301_FEED_WWDG,
    SA47301_FEED_FWDG
}Cdd_Sa47301FeedWdgModeType_TDEM;

extern Cdd_Sa47301SpiInfo_TDSTR SpiDataInfo;

// void Sensor_5V_1_Output_Function(boolean valEn_Lo);
// void Sensor_5V_2_Output_Function(boolean valEn_Lo);

Std_ReturnType Cdd_Sbc_Sa47301_InitFunction(void);
Std_ReturnType Cdd_Sbc_Sa47301_SetWakeStatusFunction(boolean valEn_Lo);
Std_ReturnType Cdd_Sbc_Sa47301_SetWakeTimeFunction(uint32 WakeTime);
Std_ReturnType Cdd_Sbc_Sa47301_SetPowerOffFunction(void);
Std_ReturnType Cdd_Sbc_Sa47301_CtrlWdgEnStatusFunction(uint8 WdgType, boolean valEn_Lo);
Std_ReturnType Cdd_Sbc_Sa47301_SetWdgFeedModeFunction(Cdd_Sa47301WdgModeType_TDEN FeedWdgMode);
void Cdd_Sbc_Sa47301_FeedWdgFunction(Cdd_Sa47301FeedWdgModeType_TDEM Feed_Mode);
Std_ReturnType Cdd_Sbc_Sa47301_GetDiagFunction(Cdd_Sa47301Diag_TDEM DiagId, boolean *DiagFlag);
Std_ReturnType Cdd_Sbc_Sa47301_SetLdoEnFunction(uint8 LdoCh, boolean valEn_Lo);

SA_WakeSrc_STDR Cdd_Sbc_Sa47301_GetWakeSourceFunction(void);
Std_ReturnType Cdd_Sbc_Sa47301_GetPoweroffTimeFunction(uint32 *WakeTime);

void Cdd_Sbc_Sa47301_10msMainFunction(void);
extern uint8 Cdd_sbc_Sa47301_GetWakePinLevelStatusFunction(void);
#ifdef __cplusplus
}
#endif




#endif /* _CDD_SA47301_H_ */