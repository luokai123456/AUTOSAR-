/****************************************************************
 * 模块：Cdd层 - 电机驱动接口模块
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.0 (初始版本)
 * 1. 支持电机驱动接口功能
 * 2. 支持电机驱动接口状态获取功能
 * ==================================================
 ****************************************************************/

#ifndef _MOTOR_HWIF_H_
#define _MOTOR_HWIF_H_

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Platform_Types.h"
#include "status.h"
#include "typedefs.h"
#include "rtwtypes.h"
#include "RdcDrv.h"
#include "Pwm3ph.h"
#include "Adc3ph.h"
#define ADC_REF_MV          5000U   
#define ADC_MAX_VALUE       4095U   

#define HV_DC1_GROUP_INDEX   25
#define HV_DC1_CH_INDEX      0
#define HV_DC2_GROUP_INDEX   22
#define HV_DC2_CH_INDEX      0

extern uint16 VDD5REF_AN1[3];     
extern uint16 VDD5REF_AN0[3];
extern uint16 Mcu_HV_DC1;

// #define MOTORCTRL_TEST   // 电机测试



#ifdef MOTORCTRL_TEST

extern void  Hal_SetAllSwitchesOff(void);
extern uint8 Hal_GetHwHsIntBSt(void);
extern uint8 Hal_GetHwLsIntBSt(void);
extern uint8_T Hal_GetBswInit(void);
#else

#endif



/* Asw -> Bsw */
extern void Hal_UpdatePwmDutyCycle(float dutyU, float dutyV, float dutyW);
extern void Hal_SetDriverCircuit(uint8 state);
extern void Hal_ConfigActiveShortCircuit(uint8 ascCmd);
extern void Hal_UpdatePwmFreqCycle(float Freq);
extern void Hal_ClrHWFaultCycle(boolean faultCmd);
extern void Hal_SetPwrOffDlyFlg(boolean pwrOffDlyFlgCmd);
extern void Hal_PwmEnableSet(uint8 state);

/* Bsw -> Asw */

typedef struct {
    uint16   Motor_AN_UBD_Mic;
    uint16   Motor_AN_KEY_Mic;
    uint16   Motor_MCU_AN_TEMP_IGBT_IN1;
    uint16   Motor_MCU_AN_TEMP_IGBT_IN2;
    uint16   Motor_MCU_AN_TEMP_IGBT_IN3;
    uint16   Motor_MCU_AN_HV_DC1;
    uint16   Motor_MCU_AN_HV_DC2;
    uint16   Motor_MCU_AN_Motor_TEMP_P;
    uint16   Motor_MCU_AN_Motor_TEMP_N;

}Motor_InterFace;

extern Motor_InterFace Motor_InterFace_MT;

uint16 Hal_ReadPhaseCurrentAdc1(void);
uint16 Hal_ReadPhaseCurrentAdc1BkUp(void);
uint16 Hal_ReadPhaseCurrentAdc2(void);
uint16 Hal_ReadPhaseCurrentAdc2BkUp(void);
uint16 Hal_ReadPhaseCurrentAdc3(void);
uint16 Hal_ReadPhaseCurrentAdc3BkUp(void);

uint16 Hal_ReadPhaseACurrentAD(void);
uint16 Hal_ReadPhaseBCurrentAD(void);
uint16 Hal_ReadPhaseCCurrentAD(void);

uint8 Hal_ReadPwmState(void);
uint16 Hal_ReadMotorTempAdc(void);
uint16 Hal_ReadMotorTempAdcBkUp(void);

uint16 Hal_ReadDcBusVoltageAdc(void);
uint16 Hal_ReadDcLinkVoltMeasAD(void);

uint16 Hal_ReadSwitchTempAdc1(void);
uint16 Hal_ReadUTempAdcBkUp(void);
uint16 Hal_ReadSwitchTempAdc2(void);
uint16 Hal_ReadVTempAdcBkUp(void);
uint16 Hal_ReadSwitchTempAdc3(void);
uint16 Hal_ReadWTempAdcBkUp(void);

uint16 Hal_ReadIgnitionVoltageAdc(void);
uint16 Hal_ReadBatteryVoltageAdc(void);

uint8 Hal_GetHwOvervoltSt(void);
uint8 Hal_GetHwOvervoltSt1(void);

uint8 Hal_GetHwOvercurSt(void);
uint8 Hal_GetHwOvercurSt1(void);
uint8 Hal_GetHwOvercurSt2(void);

uint16 Hal_ReadUHDriFault(void);
uint16 Hal_ReadULDriFault(void);
uint16 Hal_ReadVHDriFault(void);
uint16 Hal_ReadVLDriFault(void);
uint16 Hal_ReadWHDriFault(void);
uint16 Hal_ReadWLDriFault(void);

uint16_T Hal_ReadHDriDeSatFault(void);
uint16_T Hal_ReadLDriDeSatFault(void);
uint16_T Hal_ReadHDirUVFault(void);
uint16_T Hal_ReadLDriUVFault(void);

uint16 Hal_ReadPowerChipVoltageAdc(void);
uint16 Hal_ReadPwrChipVolt(void);

uint16 Hal_ReadUPhaZeroPointAD(void);

uint16 Hal_ReadWPhaZeroPointAD(void);

/*旋变功能安全 */
int16 Hal_ReadSinPosiHigh(void);
int16 Hal_ReadSinPosiLow(void);
int16 Hal_ReadSinNegHigh(void);
int16 Hal_ReadSinNegLow(void);
int16 Hal_ReadCosPosiHigh(void);
int16 Hal_ReadCosPosiLow(void);
int16 Hal_ReadCosNegHigh(void);
int16 Hal_ReadCosNegLow(void);
int16 Hal_ReadExcPosiHigh(void);
int16 Hal_ReadExcPosiLow(void);
int16 Hal_ReadExcNegHigh(void);
int16 Hal_ReadExcNegLow(void);

uint16 Hal_ReadPhaseCurrentAdc1ZeroPointBkUp(void);


uint16 Hal_ReadPhaseCurrentAdc3ZeroPointBkUp(void);

void Motor_ADC_MainFunction(void);
void Motor_ADC_HV_DC_Read(void);

extern uint16 Hal_Get_VDD5REF_Ch1_mv(void);
extern uint16 Hal_Get_VDD5REF_Ch4_mv(void);
extern uint16 Hal_Get_VDD5REF_Ch5_mv(void);


#endif /* __MOTOR_HWIF_H_ */




