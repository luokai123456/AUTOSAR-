

#ifndef SOFTWAREVERSION_H
#define SOFTWAREVERSION_H



#include "System_Release.h"

#define BSW_VERSION_MAJOR	(1u)	/* 大版本号 */
#define BSW_VERSION_MINOR	(0u)	/* 小版本号 */
#define BSW_VERSION_TEST	(0u)	/* 测试版本号 */
#define BSW_VERSION_YEAR	(26)	/* 年 */
#define BSW_VERSION_MONTH	(04)	/* 月 */
#define BSW_VERSION_DAY		(02)	/* 日 */

/* 存放 PBL,SBL 版本号的地址 */
#define PBL_VERSION_ADDR	(0x00FDFFC0UL)
#define SBL_VERSION_ADDR	(0x0103FA00UL)

#define POWERREF_APPMAXCOUNT_C		(12U)	/* 客户需要的任务数量 */

#define POWERREF_MONITOR_TIME_C		(100)	/* OS Monitor 监控的周期 单位10ms */

#define POWERREF_STMCOUNTMAX_C		(0xFFFFFFFFu)	/* STM模块最大计数值 */

typedef enum
{
	CoreId_0 = 0,
	CoreId_1 = 1,
	CoreId_2 = 2,
	CoreId_Count = 3,
}Os_CoreIdType;




#endif 
