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
#ifndef ERRORDIAG_CFG_H_
#define ERRORDIAG_CFG_H_


#include "ErrorDiag_Errorid_ASW.h"
#include "Std_Types.h"
#include "Platform_Types.h"


#define EH_NA                   0xFFFFu
#define EH_INVALID_VALUE        0xFFu
/*************************************************************/
#define ED_Status_OK           (0u)
#define ED_Status_NOK          (1u)
/*************************************************************/
#define ED_SUPPRESSION_NONE (0u)
#define ED_INVALID_COUNT (0xFFu)

#define ED_LASTWILL_STATE_NONE     (0u)
#define ED_LASTWILL_STATE_ISSUED   (1u)
#define ED_LASTWILL_STATE_REPORTED (2u)


typedef struct
{
  uint16 ED_SuppressionIdx;
  uint8 ED_SuppressionLen;
  uint8 ED_CountUp;
  uint8 ED_CountDown;
  uint8 ED_MaxRecovery;
} ErrorDiag_ConfigStatus_params_t;

typedef struct 
{
  uint8 ED_ErrCount;
  uint8 ED_Status;
  uint8 ED_cntOccurred;
  uint8 ED_LastWill;
} ErrorDiag_Status_params_t;



#endif   /* ERRORDIAG_CFG_H_ */

