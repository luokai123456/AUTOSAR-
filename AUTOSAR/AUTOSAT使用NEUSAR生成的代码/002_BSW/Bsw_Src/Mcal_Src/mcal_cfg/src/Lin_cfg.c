/**************************************************************************** 
* 

* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : LIN
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Lin_cfg.c
*   @implements Lin_cfg.c_Artifact
*   @version 3.0.0
*
*   @brief   AUTOSAR Lin - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup Lin
*   @{
*/

/*PRQA S 0380,1258,2053,1758,1756 EOF*/
#ifdef __cplusplus
extern "C"
{
#endif


/*======================================INCLUDE FILES===============================================*/
#include "Std_Types.h"
#include "Lin_Cfg.h"
#include "Lin.h"
#include "eDma.h"
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_WRAPPER_C_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_WRAPPER_C_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_WRAPPER_C_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_WRAPPER_C_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_WRAPPER_C_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_WRAPPER_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_WRAPPER_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_WRAPPER_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_WRAPPER_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_WRAPPER_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_WRAPPER_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_PATCH_VER "
#endif
/*=========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)===============================*/

/*======================================LOCAL MACROS================================================*/

/*=====================================LOCAL CONSTANTS==============================================*/

/*=====================================LOCAL VARIABLES==============================================*/

/*=====================================GLOBAL CONSTANTS=============================================*/




#define LIN_START_SEC_CONFIG_DATA
#include "Lin_MemMap.h"
static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_0=
{
    (uint8)0U,              /* Lin Channel ID */
    LinHWCh_6,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00014508U,            /* Baudrate 19200 ; Baudrate difference = 0.5208333333333144 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x03U, /* BreakLengthMaster = BL_13 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    NULL_PTR, /* Channel Sleep Compele notification */
};
#define LIN_STOP_SEC_CONFIG_DATA
#include "Lin_MemMap.h"



#define LIN_START_SEC_CONFIG_DATA
#include "Lin_MemMap.h"
VAR (Lin_CoreMapItemType, GPT_CONST) Lin_CoreMap[LIN_HW_MAX_MODULES]=
{

    
    {
        .u16Lin_SIUPin = 0,        
        .u8CoreId = 4

    },
 
};
#define LIN_STOP_SEC_CONFIG_DATA
#include "Lin_MemMap.h"



/* Specification of Lin Driver : [SWS_Lin_00225] */
#define LIN_START_SEC_CONFIG_DATA
#include "Lin_MemMap.h"
CONST(Lin_ConfigType,LIN_CONST)Lin_Config =
{
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)

    {(uint32)STD_OFF, 0U}, /* LIN_E_TIMEOUT parameters*/
        
#endif /* LIN_DISABLE_DEM_REPORT_ERROR_STATUS== STD_OFF */

    1U,
    {

        &Lin_LinChannel_0
                    
    },
    Lin_CoreMap,
};
#define LIN_STOP_SEC_CONFIG_DATA
#include "Lin_MemMap.h"


/*=====================================GLOBAL VARIABLES=============================================*/

/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/

/*======================================LOCAL FUNCTIONS=============================================*/

/*======================================GLOBAL FUNCTIONS============================================*/



#ifdef __cplusplus
}
#endif

/** @} */
