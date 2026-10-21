
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
* Class_____:C
* Name______:ErrorDiag_Swc
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

#include "ErrorHandler_Cfg.h"


#define ERRORDIAG_START_SEC_CONST_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"

const EH_Reaction_Config_params_t EH_Reaction_Func[EH_REACTION_MAX] =
{
	{ NULL_PTR,							      NULL_PTR                             }, /* EH_REACTION_NONE */
	{ &ErrorHandler_Callback_L2Disable,       &ErrorHandler_Callback_L2Enable      }, /* EH_REACTION_L2_DISABLE */
	{ &ErrorHandler_Callback_SetErrorPin,     &ErrorHandler_Callback_ResetErrorPin }, /* EH_REACTION_ERROR_PIN */
	{ &ErrorHandler_Callback_PerformSwReset,  NULL_PTR                             }, /* EH_REACTION_RESET_SW */
	{ &ErrorHandler_Callback_PerformHwReset,  NULL_PTR                             }, /* EH_REACTION_RESET_HW */
	{ &ErrorHandler_Callback_PerformWdgReset, NULL_PTR                             }, /* EH_REACTION_RESET_WDG */
	{ &ErrorHandler_Callback_DisDriver,       &ErrorHandler_Callback_EnDriver      }, /* EH_REACTION_DRV_SUP */
};

#define ERRORDIAG_STOP_SEC_CONST_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"
