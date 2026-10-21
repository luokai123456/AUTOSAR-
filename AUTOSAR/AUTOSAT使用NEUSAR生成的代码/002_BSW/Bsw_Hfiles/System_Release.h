/*** create info ***********************
*@ Author : yanxinlong
*@ date :2025-12-04
*@ Description :System release functions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#ifndef __SYSTEM_RELEASE_H_
#define __SYSTEM_RELEASE_H_

#include "typedefs.h"
#include "Std_Types.h"
/************************* WakeUp source *************************/

#define	POWERMANAGE_WAKEUPSOUCE_NONE	(0u)	//None
#define	POWERMANAGE_WAKEUPSOUCE_CANA	(1u)	//9788 CAN
#define	POWERMANAGE_WAKEUPSOUCE_KEY		(2u)	//9788 key
#define	POWERMANAGE_WAKEUPSOUCE_EOT		(3u)	//9788 EOT
#define	POWERMANAGE_WAKEUPSOUCE_ACC		(4u)	//9788 WakeIn-ACC
#define	POWERMANAGE_WAKEUPSOUCE_APlus	(5u)	//9788 WakeIn-A+/CC2
#define	POWERMANAGE_WAKEUPSOUCE_CP		(6u)	//9788 WakeIn-CP


/*Reset*/
#define BSWM_RESET_TYPE_HARD		(0u)
#define BSWM_RESET_TYPE_SOFT		(1u)
#define BSWM_RESET_TYPE_BOOT        (2u)

/*Power_state*/
#define BSWM_POWER_STATE_ON			(0u)
#define BSWM_POWER_STATE_OFF		(1u)
/******************************end************************************ */

/*****************************Sensor输出控制索引*********************** */
#define  SYS_5VSENSOR1_OUTPUT_CH      (0U)
#define  SYS_5VSENSOR2_OUTPUT_CH      (1U)
#define  SYS_HVDriver_5V_OUTPUT_CH    (2U)
#define  SYS_Driver_5V_OUTPUT_CH      (3U)
#define  SYS_12VPOWER_OUTPUT_CH       (4U)
/******************************************************************** */

/**********************************温度索引*************************** */
#define SYS_NTCThermisor_BLDC1       (0U)
#define SYS_NTCThermisor_BLDC2       (1U)
#define SYS_NTCThermisor_DC1         (2U)
#define SYS_NTCThermisor_DC2         (3U)
#define SYS_NTCThermisor_PowerMOS    (4U)

#define SYS_NTCThermisor_Retarder_OilTemp  		(5U)
#define SYS_NTCThermisor_Retarder_WaterTemp 	(6U)
#define SYS_NTCThermisor_Transmission_OilTemp  	(7U)
/******************************************************************** */





typedef struct
{
	uint8  Sw_numVersion1;		//Major version number
	uint8  Sw_numVersion2;		//Minor version number
	uint8  Sw_numVersion3;		//Test  version number
	uint8  Sw_tiYear;			//year
	uint8  Sw_tiMonth;			//month
	uint8  Sw_tiDay;			//date
} Sw_stVersionTime_TDSTR;


extern uint8 BswM_GetWakeSource(void);
extern uint32 Sys_GetSystemTimer_us(void);
extern uint32 Sys_GetSystemTimer_ms(void);
extern Sw_stVersionTime_TDSTR Get_Bsw_Version(void);
extern Sw_stVersionTime_TDSTR Get_Pbl_Version(void);
extern Sw_stVersionTime_TDSTR Get_Sbl_Version(void);
extern Std_ReturnType BswM_RequestReset(uint8 ValResetMode);
extern Std_ReturnType BswM_RequestPwerOff(uint8 EnPowerOff);
extern Std_ReturnType Sys_GetNTCTempureValue(uint8 Channel,float *Resultvalue);
extern Std_ReturnType Sys_Get_McuTemperature(float* McuTemperature);
extern Std_ReturnType Sys_Sensor_CtrlOut_Function(uint8 SensorChanel,uint8 valEn_Lo);

/**
 * Func Name: Cdd_DOUT_SetLevelFunction
 * Para in: ValChId
 * 		  Ctr: 0：Disable 1：Enable
 * Return: 执行成功与否
 * Description: set the output level value of DOUT channel
 */
extern Std_ReturnType Cdd_DOUT_SetLevelFunction(uint16 ValChId, uint8 Ctr);

/*************************RTC**************************************** */
extern Std_ReturnType Sys_SetWakeTime(uint32 valWakeTime);
extern Std_ReturnType Sys_GetRemainWakeTime(uint32* valRemainWakeTime);
extern Std_ReturnType Sys_UpdateRemainWakeTime(void);
#endif /* __SYSTEM_RELEASE_H_ */