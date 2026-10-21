/*
 *    File Name: Work_St.h
 * Project Name: XCU_A020102
 *   Created on: 2026年4月14日
 *       Author: 张艺
 *  Description: WorkSt模块
 *      Version: V0.0.1
 */


#ifndef WORK_ST_H_
#define WORK_ST_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "StandardTypes.h"

//*******************************输出定义***********************************//



//**************************项目专属变量声明*********************************//



// 上电初始化
void WorkTime_Init(void);

// 10ms 周期调用
void WorkTime_Task_10ms(void);

// 独立的保存函数（可主动调用，也可内部自动调用）
void WorkTime_SaveToEEPROM(void);

// 获取时间接口
uint8 WorkTime_GetHours(void);
uint8  WorkTime_GetMinutes(void);
uint8  WorkTime_GetSeconds(void);
unsigned long long WorkTime_GetTotalSec(void);
uint8 WorkTime_GetDay(void);
uint8 WorkTime_GetMonth(void);
unsigned long long WorkTime_GetYear(void);
//**********************************************************************//
extern uint8 NvM_256Byte_RAM_Block0[8];
#endif /* WORK_ST_H_ */
