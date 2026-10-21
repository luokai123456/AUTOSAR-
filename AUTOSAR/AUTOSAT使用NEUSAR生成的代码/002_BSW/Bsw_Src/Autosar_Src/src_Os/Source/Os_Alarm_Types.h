/*
********************************************************************************
*
*  File name: Os_Alarm_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.13
* Change: New create.
* Cause: New
********************************************************************************
*/
#ifndef OS_ALARM_TYPES_H_
#define OS_ALARM_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types.h"
#include "Os_Counter_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define OS_ALARM_OFF   (0x00U)    /* Alarm off state. */
#define OS_ALARM_SET   (0x01U)    /* Alarm set state. */

#define OS_ALARM_ABS   (0x00U)    /* Absolute time alarm mode. */
#define OS_ALARM_REL   (0x01U)    /* Relative time alarm mode. */

#define OS_ALARM_INIT  (0U)       /* Alarm initial zero value. */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8 Os_AlarmStateType;
typedef uint8 Os_AlarmModeType;
typedef void (*Os_AlarmCallbackType)(void);

struct Os_AlarmDyn
{
    /* The expiration point node, used for counter processing expiration point,
       and converted to alarm work during processing. */
    Os_CntExpListNodeCfgType expNode;
    AlarmType alarmId;        /* The alarm index. */
    Os_AlarmStateType state;  /* The current state of the alarm. */
    Os_TickType cycle;        /* Cycle of the alarm, Zero for non-cyclic alarms. */
    /* Counter configuration associated with the alarm. */
    const struct Os_CounterBaseCfg* counter;
};

struct Os_AlarmCfg
{
    /* Alarm start mode, for autostart mode. */
    Os_AlarmModeType alarmMode;
    /* Autostart mode. */
    AppModeType appMode;
    /* Counter configuration associated with the alarm. */
    const struct Os_CounterBaseCfg* counter;
    /* Alarm expired execution action. */
    Os_CntExpKindType cntExpKind;
    /* Parameters of the action to be executed when the alarm expires. */
    union Os_WorkParam workParam;
    /* Dynamic config of the alarm. */
    struct Os_AlarmDyn* alarmDyn;
    /* Reference to applications which access this object. */
    uint32 accessingApps;
    /* Owner application. */
    ApplicationType ownerAppId;
    /* The core id. */
    CoreIdType coreId;
    /* The time in ticks of the first alarm event in AutoStart mode. */
    Os_TickType alarmTime;
    /* The Config cycle the alarm in AutoStart mode. */
    Os_TickType autoCycle;
    /* Alarm callback function. */
    Os_AlarmCallbackType alarm_CallBack;
    /* The alarm id. */
    AlarmType alarmId;
};

typedef struct Os_AlarmDyn Os_AlarmDynType;
typedef struct Os_AlarmCfg Os_AlarmCfgType;
typedef Os_AlarmCfgType* Os_AlarmCfgRefType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* OS_ALARM_TYPES_H_ */
