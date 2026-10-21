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
* Name______:ErrorDiag
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

#ifndef ERRORDIAG_SWC_H_
#define ERRORDIAG_SWC_H_

#include "ErrorDiag_Cfg.h"
#include "ErrorDiag_Errorid.h"
#include "ErrorDiag_DriverCtrl_Diag.h"
#include "ErrorDiag_MCU_Diag.h"
#include "ErrorDiag_Interface.h"
#include "Rte_Dem_Type.h"
#include "Dem_Lcfg.h"
#include "Dem.h"

extern void ErrorDiag_PreInit(void);
extern void ErrorDiag_Init(void);
extern void ErrorDiag_MainFunction(void);
extern uint8 ErrorDiag_Get_Config_CountUp(uint16 ErrorId);
extern uint8 ErrorDiag_Get_Config_CountDown(uint16 ErrorId);
extern uint8 ErrorDiag_Get_Config_MaxRecoverTimes(uint16 ErrorId);
extern boolean ErrorDiag_Receive_ErrorStatus(uint16 ErrorId);
extern boolean ErrorDiag_IsSuppressed(uint16 ErrorId);
extern Std_ReturnType ErrorDiag_LoadFromNvm(uint16 *romData);
extern void ErrorDiag_Send_ErrorStatus(uint16 ErrorId, boolean ReportStatus);
extern uint8 ErrorDiag_GetLastWill(uint16 ErrorId);
extern void ErrorDiag_ClearLastWill(uint16 ErrorId);
extern void ErrorDiag_FinishLastWill(uint16 ErrorId);
extern void ED_Update_ReportId_Variable(uint16 ErrorId);

extern uint16 ErrorDiag_GetBswNum(void);
extern uint16 ErrorDiag_GetAswNum(void);


#endif /* ERRORDIAG_SWC_H_ */
