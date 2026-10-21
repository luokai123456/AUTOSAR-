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
#include "ErrorDiag_Types.h"


#define EH_REACTION_NONE         ((uint8) 0u)
#define EH_REACTION_L2_DISABLE   ((uint8) 1u)
#define EH_REACTION_ERROR_PIN    ((uint8) 2u)
#define EH_REACTION_RESET_SW     ((uint8) 3u)
#define EH_REACTION_RESET_HW     ((uint8) 4u)
#define EH_REACTION_RESET_WDG    ((uint8) 5u)
#define EH_REACTION_DRV_SUP      ((uint8) 6u)
#define EH_REACTION_MAX          ((uint8) 7u)

#define EH_DTC_INVALID (0xFFFFu)


typedef struct
{
  uint16 DtcIdx;
  uint16 DriverSuppressIdx;
  uint8  DriverSuppressLen;
  uint8  Reactions;				 /* Bitwise OR of reaction types */
} EH_ConfigReaction_TDSTR;



#endif  /* ERRORDIAF_CFG_H_  */
