/*
 *    File Name: Work_St.c
 * Project Name: XCU_A020102
 *   Created on: 2026年4月14日
 *       Author: 张艺
 *  Description: WorkSt模块
 *      Version: V0.0.1
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "User_Func.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
	unsigned long long Ui_TimeCounter10ms_MP 				= 0;
	unsigned long long Ui_TotalSeconds_MP 				= 0;
	unsigned long long Ui_RTCSeconds_MP 					= 0;//RTC 秒数，配合上电时间计算总秒数
	uint8 NvM_256Byte_RAM_Block0[8]={0};
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************/






// ==========================
// 10ms 周期任务（只负责计时）
// ==========================
void WorkTime_Task_10ms(void)
{
	static uint8 UI_WorkTimeInit_LO  = 0;

	if(UI_WorkTimeInit_LO == 0)
	{
		WorkTime_Init();
		UI_WorkTimeInit_LO = 1;
	}

    // 10ms 计数 → 秒
	Ui_TimeCounter10ms_MP++;
	if (Ui_TimeCounter10ms_MP >= 100U)
	{
		Ui_TimeCounter10ms_MP = 0;
		Ui_TotalSeconds_MP++;
	}


}


uint8 Get_MsgIdActiveSta(uint16 MsgId)
{
/*0:NotActive 1:Active*/
}






// ==========================
// 上电初始化
// ==========================
void WorkTime_Init(void)
{
	unsigned long long Ui_LastSaveSecond_MP 		= 0;

	
    // 从EEPROM读取总秒数
    Ui_LastSaveSecond_MP =
        ((unsigned long long)NvM_256Byte_RAM_Block0[0] << 56) |
        ((unsigned long long)NvM_256Byte_RAM_Block0[1] << 48) |
        ((unsigned long long)NvM_256Byte_RAM_Block0[2] << 40) |
        ((unsigned long long)NvM_256Byte_RAM_Block0[3] << 32) |
        ((unsigned long long)NvM_256Byte_RAM_Block0[4] << 24) |
        ((unsigned long long)NvM_256Byte_RAM_Block0[5] << 16) |
        ((unsigned long long)NvM_256Byte_RAM_Block0[6] << 8)  |
        NvM_256Byte_RAM_Block0[7];


    Ui_TotalSeconds_MP = Ui_LastSaveSecond_MP+Ui_RTCSeconds_MP;
    Ui_TimeCounter10ms_MP = 0;
}

// ==========================
// 独立：保存工作时间到EEPROM
// ==========================
void WorkTime_SaveToEEPROM(void)
{
    // 拆分64位总秒数
    NvM_256Byte_RAM_Block0[0] = (Ui_TotalSeconds_MP >> 56) & 0xFF;
    NvM_256Byte_RAM_Block0[1] = (Ui_TotalSeconds_MP >> 48) & 0xFF;
    NvM_256Byte_RAM_Block0[2] = (Ui_TotalSeconds_MP >> 40) & 0xFF;
    NvM_256Byte_RAM_Block0[3] = (Ui_TotalSeconds_MP >> 32) & 0xFF;
    NvM_256Byte_RAM_Block0[4] = (Ui_TotalSeconds_MP >> 24) & 0xFF;
    NvM_256Byte_RAM_Block0[5] = (Ui_TotalSeconds_MP >> 16) & 0xFF;
    NvM_256Byte_RAM_Block0[6] = (Ui_TotalSeconds_MP >> 8) & 0xFF;
    NvM_256Byte_RAM_Block0[7] = Ui_TotalSeconds_MP & 0xFF;

    // 调用你的EEPROM写入
}


// ==========================
// 获取接口
// ==========================
unsigned long long WorkTime_GetYear(void)
{
    return Ui_TotalSeconds_MP / 32140800;
}
uint8 WorkTime_GetMonth(void)
{
    return (Ui_TotalSeconds_MP / 2678400) % 12;
}
uint8 WorkTime_GetDay(void)
{
    return (Ui_TotalSeconds_MP / 86400) % 31;
}
uint8 WorkTime_GetHours(void)
{ return (Ui_TotalSeconds_MP / 3600) % 24; }

uint8  WorkTime_GetMinutes(void)
{ return (Ui_TotalSeconds_MP / 60) % 60; }
uint8  WorkTime_GetSeconds(void)
{ return Ui_TotalSeconds_MP % 60; }
unsigned long long WorkTime_GetTotalSec(void)
{ return Ui_TotalSeconds_MP; }




