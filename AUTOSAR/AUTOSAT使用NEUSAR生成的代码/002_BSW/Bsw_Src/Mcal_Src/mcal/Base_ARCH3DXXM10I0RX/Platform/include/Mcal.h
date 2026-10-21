/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Mcal.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of MCAL driver.
*
*   @addtogroup MCAL
*   @{
*/

#ifndef MCAL_H
#define MCAL_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Std_Types.h"
#include "compiler_api.h"
#include "derivative.h"
#ifdef AUTOSAR_OS_NOT_USED
#else
#include "Os.h"
#endif


#define MCAL_VENDOR_ID                    176
#define MCAL_MODULE_ID                    0
#define MCAL_AR_RELEASE_MAJOR_VERSION     4
#define MCAL_AR_RELEASE_MINOR_VERSION     4
#define MCAL_AR_RELEASE_REVISION_VERSION  0
#define MCAL_SW_MAJOR_VERSION             3
#define MCAL_SW_MINOR_VERSION             0
#define MCAL_SW_PATCH_VERSION             0

#ifdef AUTOSAR_OS_NOT_USED
#define ISR(IsrName)                    void IsrName(void)
#define GetCoreID()                     MFSPR(SPR_PIR)
#define ResumeAllInterrupts()           PPCASM(" wrteei 1")
#define SuspendAllInterrupts()          PPCASM(" wrteei 0")
#endif

#define ISR_STATE_MASK                  ((uint32)0x00008000UL)   /* EE bit of MSR */
#define ISR_ON(msr)                     (uint32)((uint32)(msr) & (uint32)(ISR_STATE_MASK))

#define BOOLTOUINT(x)  (uint8)(((x) == TRUE)?1U:0U)

#define MCAL_CORE_NUM                   RESOURCE_CHIP_CORE_NUM
#define DEFAULT_TIMEOUT                 1000000UL

typedef struct
{
    VAR(uint32,AUTOMATIC) state;
    VAR(uint32,AUTOMATIC) id ;
}Mcal_DemErrorType;


#ifdef __cplusplus
}
#endif
#endif 
