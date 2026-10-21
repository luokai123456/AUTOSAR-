/****************************************************************
 * 模块：Cdd层 - HE99MD模块
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.0 (初始版本)
 * 1. 支持HE99MD模块的控制功能
 * 2. 支持HE99MD模块的诊断功能
 * 3. 支持HE99MD模块的错误诊断功能

 * ==================================================
 ****************************************************************/
#ifndef __EVPTCDD_HB_HE99MD_PRV_H_
#define __EVPTCDD_HB_HE99MD_PRV_H_

#include "StandardTypes.h"
#include "Spi.h"
#include "EvptCdd_HBridge.h"
typedef struct
{
    uint8 OC_Errorid;
    uint8 OL_Errorid;
} Eh_ErrorIdMap_Str;
typedef enum {
	HbDrv_Stat_Normal = 0,
	HbDrv_Stat_Sleep,
	HbDrv_Stat_LimpHome,
}HbDrv_Stat_Str;

typedef enum{
	DrivingMode_Continuous = 0,
	DrivingMode_PWM,
}DrivingMode_Str;

typedef enum{
	HBridge_Fct_OFF = 0,
	HBridge_Fct_LS,
	HBridge_Fct_HS
}Hb_Fct_Str;

typedef enum{
	Motor_Freq_80Hz = 0,
	Motor_Freq_100Hz,
	Motor_Freq_200Hz,
	Motor_Freq_2000Hz,
}Motor_Freq_Str;

typedef enum{
	HbDrv_MainFctStep_Init,
	HbDrv_MainFctStep_Normal,
}HbDrv_MainFctStep_Str;

typedef struct
{
    uint8                 No;
    Spi_ChannelType       Channel;
    Spi_SequenceType      Sequence;
    uint16                InitStartPos;
    uint16                ControlStartPos;
    uint16                ControlEndPos;
    uint16                DiagEndPos;
}HBDrv_Spi_Str;

typedef void (*HbDrv_Init_t)(uint8 HbDriver);
typedef void (*HbDrv_SetOpMode_t)(uint8 HBDrv_Channel,HbDrv_Stat_Str HBDrv_Stat);
typedef void (*HbDrv_OutputCtrl_t)(uint8 HBDrv_Channel, DrivingMode_Str HBDrv_PwmCtrl, Hb_Fct_Str HBDrv_Fct,
								   Motor_Freq_Str HBDrv_Freq, uint8 HBDrv_Duty);

typedef struct{
	HbDrv_Init_t 			Init;
	HbDrv_SetOpMode_t 		Mode;
	HbDrv_OutputCtrl_t		Output;
}HbDrv_FctP_Str;

extern HBDrv_Spi_Str EH_valSpiArray_Mp[];
extern uint16 EH_valCfgSpiChannel_Mp[];
extern HbDrv_FctP_Str EH_valFctP_Mp[];

extern void HBridge_HE99MD_Init(uint8 HBDriver);
extern void HBridge_HE99MD_SetOpMode(uint8 HBDrv_Channel, HbDrv_Stat_Str HBDrv_Stat);
extern void HBridge_HE99MD_OutputCtrl
(
	uint8 HBDrv_Channel, DrivingMode_Str HBDrv_PwmCtrl, Hb_Fct_Str HBDrv_Fct,
	Motor_Freq_Str HBDrv_Freq, uint8 HBDrv_Duty
);
extern void HBridge_MainFunction(void);
extern void EH_He99md_DiagFunction(void);
extern void EH_He99md_RecoverFunction(uint8 HBDriver);
extern void EH_He99md_RecoverFunction(uint8 HBDriver);
#endif /*__EVPTCDD_HB_HE99MD_PRV_H_*/
