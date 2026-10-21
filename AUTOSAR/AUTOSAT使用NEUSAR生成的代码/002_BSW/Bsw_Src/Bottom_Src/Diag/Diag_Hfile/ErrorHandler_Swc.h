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
* Name______:ErrorHandler_Swc
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

#ifndef ERRORHANDLER_SWC_H_
#define ERRORHANDLER_SWC_H_


#include "ErrorHandler_Cfg.h"
#include "ErrorHandler_ReactionCfg.h"
#include "ErrorDiag_Interface.h"


/* whether specified bit is set */
#define IS_BIT_SET_u8(var, bit) ((uint8)(((var) >> (bit)) & (uint8)0x01U) != (uint8)0U)


void ErrorHandler_Init(void);
void ErrorHandler_MainFunction(void);
uint8 EH_GetOutputDisFlag(uint8 numDIsDriverCh_LO);
void EH_SetOutputDisFlag(uint8 numDIsDriverCh_LO, uint8 fgDisOutput_LO);
uint8 EH_GetL2DriverOff(uint8 numDIsDriverCh_LO);
void EH_SetL2DriverOff(uint8 numDIsDriverCh_LO, uint8 fgDisOutput_LO);
void ErrorHandler_ResetAndReport(uint16 ErrorId);

void EH_L2RefCounterInc(uint8 numDIsDriverCh_LO);
void EH_L2RefCounterDec(uint8 numDIsDriverCh_LO);
uint16 EH_GetL2RefCounter(uint8 numDIsDriverCh_LO);

void EH_DrvRefCounterInc(uint8 numDIsDriverCh_LO);
void EH_DrvRefCounterDec(uint8 numDIsDriverCh_LO);
uint16 EH_GetDrvRefCounter(uint8 numDIsDriverCh_LO);


#endif   /* ERRORHANDLER_SWC_H_  */
