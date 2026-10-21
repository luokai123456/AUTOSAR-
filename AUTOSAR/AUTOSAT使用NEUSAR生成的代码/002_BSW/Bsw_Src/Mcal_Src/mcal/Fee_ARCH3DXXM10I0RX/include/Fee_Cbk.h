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
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Fee_Cbk.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FEE MCAL driver.
*
*   @addtogroup FEE
*   @{
*/

#ifndef FEE_CBK_H
#define FEE_CBK_H

#ifdef __cplusplus
extern "C"{
#endif
/*==============================================INCLUDE FILES=======================================*/

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define FEE_CBK_WRA_H_VENDOR_ID                     176
#define FEE_CBK_WRA_H_AR_REL_MAJOR_VER              4
#define FEE_CBK_WRA_H_AR_REL_MINOR_VER              4
#define FEE_CBK_WRA_H_AR_REL_REV_VER                0
#define FEE_CBK_WRA_H_SW_MAJOR_VER                  3
#define FEE_CBK_WRA_H_SW_MINOR_VER                  0
#define FEE_CBK_WRA_H_SW_PATCH_VER                  0
/*============================================FILE VERSION CHECKS===================================*/
#if (FEE_VENDOR_ID_OUTPUT != FEE_CBK_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : FEE_CBK_WRA_H_VENDOR_ID "
#endif
#if (FEE_AR_REL_MAJOR_VER_OUTPUT != FEE_CBK_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FEE_CBK_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (FEE_AR_REL_MINOR_VER_OUTPUT != FEE_CBK_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FEE_CBK_WRA_H_AR_REL_MINOR_VER "
#endif
#if (FEE_AR_REL_REVISION_VER_OUTPUT != FEE_CBK_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FEE_CBK_WRA_H_AR_REL_REV_VER "
#endif
#if (FEE_SW_MAJOR_VERSION_OUTPUT != FEE_CBK_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FEE_CBK_WRA_H_SW_MAJOR_VER "
#endif
#if (FEE_SW_MINOR_VERSION_OUTPUT != FEE_CBK_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FEE_CBK_WRA_H_SW_MINOR_VER "
#endif
#if (FEE_SW_PATCH_VERSION_OUTPUT != FEE_CBK_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FEE_CBK_WRA_H_SW_PATCH_VER "
#endif
/*=================================================Constants========================================*/

/*============================================DEFINES AND MACROS====================================*/

/*===================================================Enums==========================================*/

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

/*===========================================VARIABLE DECLARATIONS==================================*/

/*============================================FUNCTION PROTOTYPES===================================*/

extern FUNC( void, FEE_CODE ) Fee_JobEndNotification( void );
extern FUNC( void, FEE_CODE ) Fee_JobErrorNotification( void );


#ifdef __cplusplus
}
#endif

#endif /* _FEE_CBK_H_ */
