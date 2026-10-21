/*** create info ***********************
*@ Author : Wangjc 
*@ date :2026-06-13
*@ Description :描述本文件实现功能
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : Wangjc 
*@ date :2026-06-13
*@ Modification Description :
初始版本
****************************************/
#ifndef EVPT_INTERDATAWATCH_INTERFACE_H
#define EVPT_INTERDATAWATCH_INTERFACE_H



#include "Std_Types.h"
#include "Evpt_InterDataWatch_Configuration.h"

typedef struct
{
    /* 32位变量集中放在最前，保证4字节自然对齐 */
    uint32  ExcPcValue[OS_COREID_MAX];
    uint32  ExcMemAddr[OS_COREID_MAX];
    uint32  ExcIsrEntryArray[OS_COREID_MAX];
    uint32  ExcIntPrioMask[OS_COREID_MAX];
    uint32  ExcHwErrorCode[OS_COREID_MAX];
    uint32  ExcSpValue[OS_COREID_MAX];
    uint32  ExcTaskId[OS_COREID_MAX];
    uint32  OsErrorId[OS_COREID_MAX];
    uint32  ExcIntNestCnt[OS_COREID_MAX];
    uint32  ExcGlobalIntState[OS_COREID_MAX];
    uint32  ExcSource[OS_COREID_MAX];
    uint32  ExcExecType[OS_COREID_MAX];
    uint32  ExcCat1IntSrc[OS_COREID_MAX];
    uint32  ExcCat2IntId[OS_COREID_MAX];
    uint32  ExcCpuPrivLevel[OS_COREID_MAX];
    uint32  SbcFault;
    uint32  ExtWdgErrorCnt;
    uint32  ExtWdgFeedExecCnt;
    uint32  FaultFlagList;
    uint32  CoreLifecycleCnt;
    uint32  CpuLoadRate[OS_COREID_MAX];
    uint32  TaskStackMonitor[OS_TASKID_MAX];

    /* 16位变量居中，保证2字节自然对齐 */
    uint16  WdgErrorFeedCnt;
    uint16  InitRunPosition;
    uint16  ProgRunPosition;
    uint16  VbatVoltage;
    uint16  KeyVoltage;
    uint16  V5Voltage;
    uint16  CanTrcvInhVoltage;
    uint16  LinInhVoltage;
    uint16  McuCoreVoltage;
    sint16  McuTemperature;
    sint16  SbcTemperature;

    /* 8位变量放最后，无对齐要求 */


    uint8   ResetSource;
    uint8   WdgStatus;
    uint8   SbcWorkState;
    uint8   PowerOnWakeupSrc;
    uint8   AswPowerDownFlag;
    uint8   SleepRunState[BSWM_GENERIC_MAX];
    uint8   ResetReasonHistory[RESET_HISTORY_MAX];
    uint8   CanWorkMode[CAN_CONTROL_MAX];
    uint8   CanTrcvWorkState[CANTRCV_MAX];
    uint8   CanTrcvFaultState[CANTRCV_MAX];
    uint8   CanBusoffState[CAN_CONTROL_MAX];
    uint8   CanErrorWarning[CAN_CONTROL_MAX];
    uint8   CanErrorPassive[CAN_CONTROL_MAX];
    uint8   CanBusError[CAN_CONTROL_MAX];
    uint8   CanRunState[CAN_CONTROL_MAX];
    uint8   LinRunState[LIN_CONTROL_MAX];
    uint8   DrvCtrlRunState;
    uint8   BswmState;
    uint8   SpiRunState;
    uint8   MscRunState;
    uint8   SolenoidRunState;
    uint8   AdcRunState;
    uint8   IoRunState;
    uint8   IcuRunState;
    uint8   PwmRunState;
    uint8   SentIntFlag;
    uint8   ExtWdgFeedState;
    uint8   FeeJobState;
    uint8   FlsJobState;
    uint8   FlsJobResult;
    uint8   DrvCtrlState;
} Evpt_DiagDb_Storage_t;

extern volatile Evpt_DiagDb_Storage_t DiagDb_Storage __attribute__((aligned(4)));

#endif /* EVPT_INTERDATAWATCH_INTERFACE_H */






