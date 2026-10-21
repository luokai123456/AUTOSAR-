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
* Name______:ErrorDiag_DriveCtrl_Check
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


#include  "ErrorDiag_DriverCtrl_Diag.h"


#define ERRORDIAG_START_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"


/* Monitor output feedback of external chips */
static void ErrorDiag_External_Output_Monitor_Task(void)
{


}


/* Monitor fault pin of external chips */
static void ErrorDiag_External_FaultPin_Monitor_Task(void)
{



}


void ErrorDiag_DriveCtrl_Monitor_Task(void)
{
   ErrorDiag_External_FaultPin_Monitor_Task();
   ErrorDiag_External_Output_Monitor_Task();

}


#define ERRORDIAG_STOP_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"
