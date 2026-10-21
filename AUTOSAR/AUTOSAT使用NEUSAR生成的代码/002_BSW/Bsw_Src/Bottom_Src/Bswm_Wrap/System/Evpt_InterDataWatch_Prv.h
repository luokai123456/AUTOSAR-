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
#ifndef EVPT_INTERDATAWATCH_PRV_H
#define EVPT_INTERDATAWATCH_PRV_H


#include <stdint.h>
#include "Std_Types.h"
#include "Os_Monitor.h"

/* =============================================
 * 诊断变量ID枚举：与原定义完全一致，兼容原有调用
 * ============================================= */
typedef enum
{
    /* ---------- 1. 异常现场类 ---------- */
    DIAG_VAR_EXC_PC_VALUE = 0u,
    DIAG_VAR_EXC_MEM_ADDR,
    DIAG_VAR_EXC_INT_NEST_CNT,
    DIAG_VAR_EXC_ISR_ENTRY_ARRAY,
    DIAG_VAR_EXC_INT_PRIO_MASK,
    DIAG_VAR_EXC_GLOBAL_INT_STATE,
    DIAG_VAR_EXC_CPU_PRIV_LEVEL,
    DIAG_VAR_EXC_SOURCE,
    DIAG_VAR_EXC_HW_ERROR_CODE,
    DIAG_VAR_EXC_SP_VALUE,
    DIAG_VAR_EXC_EXEC_TYPE,
    DIAG_VAR_EXC_TASK_ID,
    DIAG_VAR_EXC_CAT2_INT_ID,
    DIAG_VAR_EXC_CAT1_INT_SRC,
    DIAG_VAR_OS_ERROR_ID,

    /* ---------- 2. 复位与电源类 ---------- */
    DIAG_VAR_RESET_SOURCE,
    DIAG_VAR_WDG_STATUS,
    DIAG_VAR_WDG_ERROR_FEED_CNT,
    DIAG_VAR_SBC_WORK_STATE,
    DIAG_VAR_POWER_ON_WAKEUP_SRC,
    DIAG_VAR_INIT_RUN_POSITION,
    DIAG_VAR_PROG_RUN_POSITION,
    DIAG_VAR_ASW_POWER_DOWN_FLAG,
    DIAG_VAR_SLEEP_RUN_STATE,
    DIAG_VAR_RESET_REASON_HISTORY,

    /* ---------- 3. 总线与外设状态类 ---------- */
    DIAG_VAR_CAN_WORK_MODE,
    DIAG_VAR_CAN_TRCV_WORK_STATE,
    DIAG_VAR_CAN_TRCV_FAULT_STATE,
    DIAG_VAR_CAN_BUSOFF_STATE,
    DIAG_VAR_CAN_ERROR_WARNING,
    DIAG_VAR_CAN_ERROR_PASSIVE,
    DIAG_VAR_CAN_BUS_ERROR,
    DIAG_VAR_CAN_RUN_STATE,
    DIAG_VAR_LIN_RUN_STATE,
    DIAG_VAR_DRV_CTRL_RUN_STATE,
    DIAG_VAR_BSWM_STATE,
    DIAG_VAR_SPI_RUN_STATE,
    DIAG_VAR_MSC_RUN_STATE,
    DIAG_VAR_SOLENOID_RUN_STATE,
    DIAG_VAR_ADC_RUN_STATE,
    DIAG_VAR_IO_RUN_STATE,
    DIAG_VAR_ICU_RUN_STATE,
    DIAG_VAR_PWM_RUN_STATE,

    /* ---------- 4. 模拟采集与温度类 ---------- */
    DIAG_VAR_VBAT_VOLTAGE,
    DIAG_VAR_KEY_VOLTAGE,
    DIAG_VAR_5V_VOLTAGE,
    DIAG_VAR_CAN_TRCV_INH_VOLTAGE,
    DIAG_VAR_LIN_INH_VOLTAGE,
    DIAG_VAR_MCU_CORE_VOLTAGE,
    DIAG_VAR_MCU_TEMPERATURE,
    DIAG_VAR_SBC_TEMPERATURE,
    DIAG_VAR_SBC_FAULT,

    /* ---------- 5. 计数与系统状态类 ---------- */
    DIAG_VAR_SENT_INT_FLAG,
    DIAG_VAR_EXT_WDG_ERROR_CNT,
    DIAG_VAR_EXT_WDG_FEED_EXEC_CNT,
    DIAG_VAR_EXT_WDG_FEED_STATE,
    DIAG_VAR_FEE_JOB_STATE,
    DIAG_VAR_FLS_JOB_STATE,
    DIAG_VAR_FLS_JOB_RESULT,
    DIAG_VAR_CPU_LOAD_RATE,
    DIAG_VAR_DRV_CTRL_STATE,
    DIAG_VAR_FAULT_FLAG_LIST,
    DIAG_VAR_CORE_LIFECYCLE_CNT,
    DIAG_VAR_TASK_STACK_MONITOR,
    DIAG_VAR_MAX
} Evpt_DiagVarId_t;

typedef struct
{
    volatile uint8* pDataAddr; /* 指向volatile存储区的指针 */
    uint16          DataLen;   /* 数据总长度(字节) */
} Evpt_DiagDb_MapEntry_t;


/* =============================================
 * 对外接口
 * ============================================= */

/**
 * @brief  诊断数据库初始化
 */
extern Std_ReturnType Evpt_DiagDb_Init(void);

/**
 * @brief  通用写入接口（整体覆盖写入）
 * @note   带同核临界区保护，支持任务/普通中断上下文调用
 *         适合单值整体赋值场景，如状态量、采集值
 */
extern Std_ReturnType Evpt_DiagDb_SetValue(uint16 VarId, const void* pData, uint16 DataLen);


void Evpt_Diagnostic_Database_NeusarDiagData(void);
void Evpt_Diagnostic_Database_ExceptionDiagData(void);
void Evpt_Diagnostic_TaskStackData_Core0(void);
void Evpt_Diagnostic_TaskStackData_Core1(void);
void Evpt_Diagnostic_TaskStackData_Core2(void);
void Evpt_Diagnostic_TaskStackData_Core3(void);
void Evpt_Diagnostic_TaskStackData_Core4(void);
void Evpt_Diagnostic_TaskStackData_Core5(void);
#endif /* EVPT_INTERDATAWATCH_PRV_H */






