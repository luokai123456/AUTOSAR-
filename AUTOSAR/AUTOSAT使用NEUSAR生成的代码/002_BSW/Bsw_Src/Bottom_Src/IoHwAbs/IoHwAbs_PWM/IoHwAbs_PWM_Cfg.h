/*** create info ***********************
*@ Author : duqian 
*@ date :2025-12-04
*@ Description :PWM-Emios configuration H file
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : duqian 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#ifndef IOHWABS_PWM_CFG_H
#define IOHWABS_PWM_CFG_H


/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "IoHwAbs_PWM_Prv.h"
#include "Platform_Types.h"
#include "Pwm_Cfg.h"


typedef enum{
	IoHwAbs_eMIOS_PWM     = 1,
    IoHwAbs_eTPU_PWM      = 2,
	IoHwAbs_eTPU_TriggerAdc = 3,
	IoHwAbs_GTM_PWM			= 4
}Pwm_ComponentType_TDEM;

typedef enum{
	IoHwAbs_ATOM_GTM     = 1,
	IoHwAbs_TOM_GTM      = 2
}Pwm_GtmOutputType_TDEM;


typedef struct
{
    Pwm_ComponentType_TDEM		numPwmType;
    Pwm_GtmOutputType_TDEM		numGtmType;
	uint16							numPwmChannel;
	uint8							numPwmChannelCfgId;
} Pwm_IndexConfig_TDSTR;

extern const Pwm_IndexConfig_TDSTR  Pwm_valChannelConfig_STR[IOHWABS_PWM_PwmOutChannMax];

#endif /*IOHWABS_PWM_CFG_H*/
