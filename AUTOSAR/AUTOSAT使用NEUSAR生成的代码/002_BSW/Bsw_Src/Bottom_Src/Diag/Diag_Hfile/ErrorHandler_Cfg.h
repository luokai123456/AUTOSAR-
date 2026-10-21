/**********************************************************************************************************************
*
* COPYRIGHT RESERVED, Tianjin Yidingfeng Power Technology, 2012. All rights reserved.
* The reproduction, distribution and utilization of this document as well as the communication of its contents to
* others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
* All rights reserved in the event of the grant of a patent, utility model or design.
*
**********************************************************************************************************************
* Administrative Information
* Namespace_:
* Class_____:H
* Name______:ErrorDiag_Cfg
* Variant___:75.16.01
* Revision__:0
**********************************************************************************************************************
 * History___:
 *
 * 75.16.01; 0     10.04.2024 SH-RD  Xiangyu.Zhu
 *   N: new created
 *
 * 
 * 
 * 
***********************************************************************************************************************/

#ifndef ERRORHANDLER_CFG_H_
#define ERRORHANDLER_CFG_H_


#include "Std_Types.h"
#include "ErrorDiag_Cfg.h"
#include "ErrorHandler_ErrorReaction.h"


/* ErrorHandler 配置 */
#ifndef EH_CFG_REPORT_DTC_EN
#define EH_CFG_REPORT_DTC_EN (STD_ON) /* 使能DTC上报功能 */
#endif
#ifndef EH_CFG_NO_DEM_H
#define EH_CFG_NO_DEM_H (STD_ON) /* 当前环境没有Dem.h时打开 */
#endif
#ifndef EH_CFG_NO_L2_SHUTDOWN
#define EH_CFG_NO_L2_SHUTDOWN (STD_OFF) /* 关闭L2关断响应 */
#endif
#ifndef EH_CFG_CUST_RESET_EN
#define EH_CFG_CUST_RESET_EN (STD_OFF) /* NOTE: 跨核调用需要确保DCACHE未使能，否则只能在ErrorDiag同一个核调用 */
#endif
#ifndef EH_CFG_CUST_ERRPIN_EN
#define EH_CFG_CUST_ERRPIN_EN (STD_OFF) /* NOTE: 跨核调用需要确保DCACHE未使能，否则只能在ErrorDiag同一个核调用 */
#endif


#define EH_REACTION_NONE         ((uint8) 0u)
#define EH_REACTION_L2_DISABLE   ((uint8) 1u)
#define EH_REACTION_ERROR_PIN    ((uint8) 2u)
#define EH_REACTION_RESET_SW     ((uint8) 3u)
#define EH_REACTION_RESET_HW     ((uint8) 4u)
#define EH_REACTION_RESET_WDG    ((uint8) 5u)
#define EH_REACTION_DRV_SUP      ((uint8) 6u)
#define EH_REACTION_MAX          ((uint8) 7u)


/* Don't forget to update ErrorHandler_SetL2Enable if these definitions are modified */
#define L2_DIS_DC      (0u)
#define L2_DIS_BLDC1   (1u)
#define L2_DIS_BLDC2   (2u)
#define L2_DIS_HS1     (3u)
#define L2_DIS_HS2     (4u)
#define L2_DIS_HS3     (5u)
#define L2_DIS_HS4     (6u)
#define L2_DIS_LS1_4   (7u)
#define L2_DIS_LS5_8   (8u)
#define L2_DIS_LS9_12  (9u)
#define L2_DIS_LS13_16 (10u)
#define L2_DIS_NUM_MAX (11u)


#define EH_DTC_INVALID (0xFFFFu)


typedef struct
{
	void   (*EH_Error_Detect_Action_Func)(uint16 errorId);
	void   (*EH_Error_Recover_Action_Func)(uint16 errorId);
} EH_Reaction_Config_params_t;


typedef struct
{
  uint16 DtcIdx;
  uint16 DriverSuppressIdx;
  uint8  DriverSuppressLen;
  uint8  Reactions;				 /* Bitwise OR of reaction types */
} EH_ConfigReaction_TDSTR;


extern const EH_Reaction_Config_params_t EH_Reaction_Func[EH_REACTION_MAX];

extern const EH_ConfigReaction_TDSTR EH_Reaction_Cfg[];
extern const EH_ConfigReaction_TDSTR EH_ASW_Reaction_Cfg[];

extern const uint16 EH_Reaction_BswDtcNum;
extern const uint16 EH_Reaction_AswDtcNum;
extern const uint16 EH_Reaction_DtcCfg_BSW[];
extern const uint16 EH_Reaction_DtcCfg_ASW[];


#endif  /* ERRORDIAF_CFG_H_  */
