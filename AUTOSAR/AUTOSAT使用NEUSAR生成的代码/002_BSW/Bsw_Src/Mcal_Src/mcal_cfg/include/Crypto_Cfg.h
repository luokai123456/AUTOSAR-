/**************************************************************************** 
* 
* Copyright (c) 2024  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Crypto
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/
/**
*   @file    Crypto_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Gpt MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/
#ifndef CRYPTO_CFG_H
#define CRYPTO_CFG_H

#include "Compiler.h"
#include "Std_Types.h"


#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

/*============================================FILE VERSION CHECKS===================================*/

/*=================================================Constants========================================*/

/*===========================================VARIABLE DECLARATIONS==================================*/

/*============================================DEFINES AND MACROS====================================*/
#define CRYPTO_PRECOMPILE_SUPPORT              (STD_ON)
#define CRYPTO_DET_ERROR_REPORT                (STD_ON)
#define CRYPTO_VERSION_INFO_API                (STD_ON)
#define CRYPTO_MAIN_FUNCTION_PERIOD            (1000)
#define CRYPTO_NUMBER_OF_DRIVER_OBJECTS        (8UL)
#define CRYPTO_NUMBER_OF_KEYS                  (71UL)
#define CRYPTO_NUMBER_OF_KEY_ELEMENTS          (84)
#define CRYPTO_INSTANCE_ID                     ((uint8)0)

/* Symbolic names for the CryptoDriverObjectId attribute of all the Crypto Driver Objects */
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_0  ((uint32)1U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_1  ((uint32)2U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_2  ((uint32)3U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_3  ((uint32)4U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_4  ((uint32)5U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_5  ((uint32)6U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_6  ((uint32)7U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_7  ((uint32)8U)

/* Symbolic names for the CryptoKeyId attribute of all the Crypto keys */

/* Symbolic names for the CryptoKeyElementId attribute of all the Crypto key elements */



#define CryptoConf_CryptoKey_CryptoKey_0              ((uint8) 0U)
#define CryptoConf_CryptoKey_CryptoKey_1              ((uint8) 1U)
#define CryptoConf_CryptoKey_CryptoKey_2              ((uint8) 2U)
#define CryptoConf_CryptoKey_CryptoKey_3              ((uint8) 3U)
#define CryptoConf_CryptoKey_CryptoKey_4              ((uint8) 4U)
#define CryptoConf_CryptoKey_CryptoKey_5              ((uint8) 5U)
#define CryptoConf_CryptoKey_CryptoKey_6              ((uint8) 6U)
#define CryptoConf_CryptoKey_CryptoKey_7              ((uint8) 7U)
#define CryptoConf_CryptoKey_CryptoKey_8              ((uint8) 8U)
#define CryptoConf_CryptoKey_CryptoKey_9              ((uint8) 9U)
#define CryptoConf_CryptoKey_CryptoKey_10              ((uint8) 10U)
#define CryptoConf_CryptoKey_CryptoKey_11              ((uint8) 11U)
#define CryptoConf_CryptoKey_CryptoKey_12              ((uint8) 12U)
#define CryptoConf_CryptoKey_CryptoKey_13              ((uint8) 13U)
#define CryptoConf_CryptoKey_CryptoKey_14              ((uint8) 14U)
#define CryptoConf_CryptoKey_CryptoKey_15              ((uint8) 15U)
#define CryptoConf_CryptoKey_CryptoKey_16              ((uint8) 16U)
#define CryptoConf_CryptoKey_CryptoKey_17              ((uint8) 17U)
#define CryptoConf_CryptoKey_CryptoKey_18              ((uint8) 18U)
#define CryptoConf_CryptoKey_CryptoKey_19              ((uint8) 19U)
#define CryptoConf_CryptoKey_CryptoKey_20              ((uint8) 20U)
#define CryptoConf_CryptoKey_CryptoKey_21              ((uint8) 21U)
#define CryptoConf_CryptoKey_CryptoKey_22              ((uint8) 22U)
#define CryptoConf_CryptoKey_CryptoKey_23              ((uint8) 23U)
#define CryptoConf_CryptoKey_CryptoKey_24              ((uint8) 24U)
#define CryptoConf_CryptoKey_CryptoKey_25              ((uint8) 25U)
#define CryptoConf_CryptoKey_CryptoKey_26              ((uint8) 26U)
#define CryptoConf_CryptoKey_CryptoKey_27              ((uint8) 27U)
#define CryptoConf_CryptoKey_CryptoKey_28              ((uint8) 28U)
#define CryptoConf_CryptoKey_CryptoKey_29              ((uint8) 29U)
#define CryptoConf_CryptoKey_CryptoKey_30              ((uint8) 30U)
#define CryptoConf_CryptoKey_CryptoKey_31              ((uint8) 31U)
#define CryptoConf_CryptoKey_CryptoKey_32              ((uint8) 32U)
#define CryptoConf_CryptoKey_CryptoKey_33              ((uint8) 33U)
#define CryptoConf_CryptoKey_CryptoKey_34              ((uint8) 34U)
#define CryptoConf_CryptoKey_CryptoKey_35              ((uint8) 35U)
#define CryptoConf_CryptoKey_CryptoKey_36              ((uint8) 36U)
#define CryptoConf_CryptoKey_CryptoKey_37              ((uint8) 37U)
#define CryptoConf_CryptoKey_CryptoKey_38              ((uint8) 38U)
#define CryptoConf_CryptoKey_CryptoKey_39              ((uint8) 39U)
#define CryptoConf_CryptoKey_CryptoKey_40              ((uint8) 40U)
#define CryptoConf_CryptoKey_CryptoKey_41              ((uint8) 41U)
#define CryptoConf_CryptoKey_CryptoKey_42              ((uint8) 42U)
#define CryptoConf_CryptoKey_CryptoKey_43              ((uint8) 43U)
#define CryptoConf_CryptoKey_CryptoKey_44              ((uint8) 44U)
#define CryptoConf_CryptoKey_CryptoKey_45              ((uint8) 45U)
#define CryptoConf_CryptoKey_CryptoKey_46              ((uint8) 46U)
#define CryptoConf_CryptoKey_CryptoKey_47              ((uint8) 47U)
#define CryptoConf_CryptoKey_CryptoKey_48              ((uint8) 48U)
#define CryptoConf_CryptoKey_CryptoKey_49              ((uint8) 49U)
#define CryptoConf_CryptoKey_CryptoKey_50              ((uint8) 50U)
#define CryptoConf_CryptoKey_CryptoKey_51              ((uint8) 51U)
#define CryptoConf_CryptoKey_CryptoKey_52              ((uint8) 52U)
#define CryptoConf_CryptoKey_CryptoKey_53              ((uint8) 53U)
#define CryptoConf_CryptoKey_CryptoKey_54              ((uint8) 54U)
#define CryptoConf_CryptoKey_CryptoKey_55              ((uint8) 55U)
#define CryptoConf_CryptoKey_CryptoKey_56              ((uint8) 56U)
#define CryptoConf_CryptoKey_CryptoKey_57              ((uint8) 57U)
#define CryptoConf_CryptoKey_CryptoKey_58              ((uint8) 58U)
#define CryptoConf_CryptoKey_CryptoKey_59              ((uint8) 59U)
#define CryptoConf_CryptoKey_CryptoKey_60              ((uint8) 60U)
#define CryptoConf_CryptoKey_CryptoKey_61              ((uint8) 61U)
#define CryptoConf_CryptoKey_CryptoKey_62              ((uint8) 62U)
#define CryptoConf_CryptoKey_CryptoKey_63              ((uint8) 63U)
#define CryptoConf_CryptoKey_CryptoKey_64              ((uint8) 64U)
#define CryptoConf_CryptoKey_CryptoKey_65              ((uint8) 65U)
#define CryptoConf_CryptoKey_CryptoKey_66              ((uint8) 66U)
#define CryptoConf_CryptoKey_CryptoKey_67              ((uint8) 67U)
#define CryptoConf_CryptoKey_CryptoKey_68              ((uint8) 68U)
#define CryptoConf_CryptoKey_CryptoKey_69              ((uint8) 69U)
#define CryptoConf_CryptoKey_CryptoKey_70              ((uint8) 70U)


/*===================================================ENUMS==========================================*/

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

/*===============================================LOCAL FUNCTIONS====================================*/

/*==============================================GLOBAL FUNCTIONS====================================*/
#define CRYPTO_INLINE    LOCAL_INLINE


#ifdef __cplusplus
}
#endif
#endif



