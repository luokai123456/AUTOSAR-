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

#include "Platform_Types.h"
#include "ErrorDiag_MCU_Diag.h"
#include "ResetCause.h"
#include "ErrorDiag_Swc.h"


#define ERRORDIAG_START_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"

/*****************************************************************************
** Service Name       : ErrorDiag_MCU_Startup_Diag                                               
** 
**  Description      :  Init task. Execute C3008 Safetylib Initial test. 
**                                                                               
**  Parameters (in)  :  None                         
**                                                                           
**  Parameters (in)  :  None                           
**    
**  Parameters (out) :  None                                                   
**                                                                            
**  Return value     :  None                                                    
**                                                                            
******************************************************************************/
void ErrorDiag_MCU_Startup_Diag_Init(void)
{
   uint8 reset_cause = ResetCause_GetCause();
   if (reset_cause == RESET_CAUSE_TYP_WDG_CAUSED_POR) {
     // ErrorDiag_Send_ErrorStatus(ERRORID_MCU_RESET_CAUSE_EXTWDG, ED_Status_NOK);
   } else if (reset_cause == RC_MCU_FCCU_HARD_RESET || reset_cause == RC_MCU_FCCU_SOFT_RESET) {
      //ErrorDiag_Send_ErrorStatus(ERRORID_MCU_RESET_CAUSE_MCU_ERROR, ED_Status_NOK);
   }
}


/*****************************************************************************
** Service Name       : ErrorDiag_MCU_Runtime_Diag_Task                                               
** 
**  Description      :  10ms period task. Execute C3008 Safetylib runtime test. 
**                                                                               
**  Parameters (in)  :  None                         
**                                                                           
**  Parameters (in)  :  None                           
**    
**  Parameters (out) :  None                                                   
**                                                                            
**  Return value     :  None                                                    
**                                                                            
******************************************************************************/
void ErrorDiag_MCU_Runtime_Diag_Task(void)
{

   /* NA */
}

#define ERRORDIAG_STOP_SEC_CODE_ASIL_C
#include "ErrorDiag_MemMap.h"
