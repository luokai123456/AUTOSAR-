#ifndef __CDD_TLE9018_DRIVER_H_
#define __CDD_TLE9018_DRIVER_H_

#include <string.h>
#include "Std_Types.h"
#include "Cdd_Tle9018_Reg.h"
#include "Cdd_Tle9018_Com.h"

#define TLE9015_MAX_SEGMENTS                        2

#define TLE9018_CHIP_NUMBER                         6U
#define TLE9018_CELL_NUMBER                         18U
#define TLE9018_BAL_CELL_PER_REG                    3U
#define TLE9018_BAL_CNT_BIT_WIDTH                   5U
#define TLE9018_GPIO_NUMBER                         8U
#define TLE9018_PROC_TYPE_CELL                      0U
#define TLE9018_PROC_TYPE_RIST                      1U
#define TLE9018_SPI_DATA_STEP                       5U
#define TLE9018_VOLTAGE_REFERENCE_MV                5000U
#define TLE9018_ADC_RESOLUTION                      65536U
#define TLE9018_CALCU_FSR_TEMP                      2U
#define TLE9018_REG_EXT_TEMP_RESULT_MASK            0x03ffU
#define TLE9018_CALCU_PARA_U                        1024U
#define TLE9018_CALCU_PARA_A                        640U
#define TLE9018_CALCU_PARA_O                        100U
#define TLE9018_CALCU_PARA_M                        1000.0f

typedef struct {
    uint8  dev_count;
    uint8  dev_list[TLE9018_CHIP_NUMBER];
} Tle9015_SegmentType;

typedef struct {
    Tle9015_SegmentType segments[TLE9015_MAX_SEGMENTS];
    uint8 logical_to_physical[TLE9018_CHIP_NUMBER + 1];
    uint8 logic_to_port[TLE9018_CHIP_NUMBER + 1];
    uint8 total_devices;
    uint8 segment_count;
} Tle9015_LinkStateType;

typedef struct {
    float int_temp[TLE9018_CHIP_NUMBER];
    uint32 cell_mask[TLE9018_CHIP_NUMBER];
    uint32 cell_opl_state[TLE9018_CHIP_NUMBER];
    uint32 temp_opl_state[TLE9018_CHIP_NUMBER];
    uint32 bal_mask[TLE9018_CHIP_NUMBER];
    uint32 bal_mask_last[TLE9018_CHIP_NUMBER];
    uint32 balance_error_state[TLE9018_CHIP_NUMBER];
    uint32 balance_state[TLE9018_CHIP_NUMBER];
    uint16 cell_vol[TLE9018_CHIP_NUMBER * TLE9018_CELL_NUMBER];
    uint16 rist_val[TLE9018_CHIP_NUMBER * TLE9018_GPIO_NUMBER];
    uint8 temp_number[TLE9018_CHIP_NUMBER];
    uint8 is_offline[TLE9018_CHIP_NUMBER];
    uint8 is_offlinehistory[TLE9018_CHIP_NUMBER];
    uint8 is_chip_error[TLE9018_CHIP_NUMBER];
}Tle9018_DrvType;

typedef struct {
    Tle9015_LinkStateType link_state;
    Tle9018_DrvType driver;
    uint8 step;
    uint8 read_counter;
    uint8 delay;
    uint8 curt_id;
    uint8 inited;
    uint8 wake_up_from_sleep;
}Tle9018_DevType;

extern void Tle9018_WakeUpDevices(Tle9018_DevType* dev, uint8 port);
extern uint8 Tle9018_SetDeviceId(Tle9018_DevType* dev,
    uint8 port,
    uint8 dev_id,
    uint8 is_final
);
extern uint8 Tle9018_ReadDualDevId(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint8* id_out);
extern uint8 Tle9018_ReadDevId(Tle9018_DevType* dev, uint8 port, uint8* dev_id);
extern void Tle9018_ReadSleepStat(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_ClearAllFaults(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_EnablePCVM(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint32 cell_mask);
extern void Tle9018_EnableExternalTemp(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint8 temp_num);
extern void Tle9018_SetEmmMask(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_GeneralConfig(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_CfgMultiRead(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_SetOvUvThreshold(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_SetBalCurtThreshold(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_ClearTmpRefFaults(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_StartRoundRobin(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_StartCellBalance(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint32 bal_mask);
extern void Tle9018_TrigMeas(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_ReadIntelTemp(Tle9018_DevType* dev, uint8 port, uint8 dev_id, float* int_temp);
extern void Tle9018_ReadCellVoltage(Tle9018_DevType* dev, uint8 port, uint8 pos);
extern void Tle9018_ReadTempVoltage(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_ReadGenernalInfo(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint8* chip_error);
extern void Tle9018_ReadDiagInfo(Tle9018_DevType* dev,
    uint8 port,
    uint8 dev_id,
    uint32* temp_opl,
    uint32* cell_opl,
    uint32* bal_err
);
extern void Tle9018_FeedWatchDog(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern uint8 Tle9018_ReadBalancingStatus(Tle9018_DevType* dev,
    uint8 port,
    uint8 dev_id,
    uint32* balancing_mask);
extern void Tle9018_GoToSleep(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
extern void Tle9018_ResetFromSleep(Tle9018_DevType* dev, uint8 port, uint8 dev_id);

#endif /*__EVPTCDD_TLE9018_H_*/

