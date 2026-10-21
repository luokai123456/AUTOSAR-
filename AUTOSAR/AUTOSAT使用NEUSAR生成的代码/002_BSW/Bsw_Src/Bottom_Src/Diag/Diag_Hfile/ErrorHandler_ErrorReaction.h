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
* Name______:ErrorHandler_ErrorReaction
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

#ifndef ERRORHANDLER_ERRORRRACTION_H_
#define ERRORHANDLER_ERRORRRACTION_H_

#include "Std_Types.h"

extern void ErrorHandler_Callback_PerformHwReset(uint16 errorId);
extern void ErrorHandler_Callback_PerformSwReset(uint16 errorId);
extern void ErrorHandler_Callback_PerformWdgReset(uint16 errorId);
extern void ErrorHandler_Callback_SetErrorPin(uint16 errorId);
extern void ErrorHandler_Callback_ResetErrorPin(uint16 errorId);
extern void ErrorHandler_Callback_DisDriver(uint16 errorId);
extern void ErrorHandler_Callback_EnDriver(uint16 errorId);
extern void ErrorHandler_Callback_L2Disable(uint16 errorId);
extern void ErrorHandler_Callback_L2Enable(uint16 errorId);

#endif   /* ERRORHANDLER_ERRORRRACTION_H_ */
