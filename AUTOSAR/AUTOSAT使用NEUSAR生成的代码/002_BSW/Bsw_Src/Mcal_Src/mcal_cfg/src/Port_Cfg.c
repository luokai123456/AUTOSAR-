/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : PORT
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/
/**
* @file    Port_PBcfg.c
* @implements Port_PBcfg.c_Artifact
*
* @version 3.0.0
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver postbuild configuration.
*
* @addtogroup  Port
* @{
*/

#ifdef __cplusplus
extern "C" {
#endif
/* PRQA S 2053,0380,1258,1259,0704,1533,0686,1753,1594,1509,1593,1527 EOF */
/*==============================================INCLUDE FILES=======================================*/
#include "Port.h"
#include "derivative.h"


/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*
*/
#define PORT_C_VENDOR_ID_PBCFG                       176
/*
* @violates @ref PORT_PBCFG_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_C_AR_RELEASE_MAJOR_VERSION_PBCFG        4
/*
* @violates @ref PORT_PBCFG_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_C_AR_RELEASE_MINOR_VERSION_PBCFG        4

/** @violates @ref PORT_PBCFG_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*   ensure that 31 character significance and case sensitivity are supported for external
*   identifiers.
*/
#define PORT_C_AR_RELEASE_REVISION_VERSION_PBCFG     0
#define PORT_C_SW_MAJOR_VERSION_PBCFG                3
#define PORT_C_SW_MINOR_VERSION_PBCFG                0
#define PORT_C_SW_PATCH_VERSION_PBCFG                0

/*============================================FILE VERSION CHECKS===================================*/

/* Check if Port_PBcfg.c and Port.h are of the same vendor */
#if (PORT_C_VENDOR_ID_PBCFG != PORT_VENDOR_ID)
    #error "NON-MATCHED DATA : PORT_VENDOR_ID"
#endif
/* Check if Port_PBcfg.c and Port.h are of the same Autosar version */
#if (PORT_C_AR_RELEASE_MAJOR_VERSION_PBCFG    != PORT_AR_RELEASE_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MAJOR_VERSION"
#endif

#if (PORT_C_AR_RELEASE_MINOR_VERSION_PBCFG    != PORT_AR_RELEASE_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MINOR_VERSION"
#endif

#if (PORT_C_AR_RELEASE_REVISION_VERSION_PBCFG != PORT_AR_RELEASE_REV_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_REV_VERSION"
#endif

/* Check if Port_PBcfg.c and Port.h are of the same software version */
#if (PORT_C_SW_MAJOR_VERSION_PBCFG != PORT_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MAJOR_VERSION"
#endif

#if (PORT_C_SW_MINOR_VERSION_PBCFG != PORT_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MINOR_VERSION"
#endif

#if (PORT_C_SW_PATCH_VERSION_PBCFG != PORT_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_PATCH_VERSION"
#endif

/*=========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)===============================*/


/*======================================LOCAL MACROS================================================*/


/*======================================LOCAL CONSTANTS=============================================*/


/*======================================LOCAL VARIABLES=============================================*/


/*======================================GLOBAL CONSTANTS============================================*/
#define PORT_START_SEC_CONFIG_DATA

#include "Port_MemMap.h"
static CONST(Port_CoreMapItemType, PORT_CONST) Port_CoreMap[PORT_MAX_CONFIGURED_PADS_U16];
#define PORT_STOP_SEC_CONFIG_DATA

#include "Port_MemMap.h"

/*
* @violates @ref PORT_PBCFG_REF_2 Violates MISRA 2004 Required Rules 10.1,Implicit conversion changes signedness.
*/
#if (PORT_MAX_UNUSED_PADS_U16 != 0U)
/**
* @brief NoDefaultPadsArray is an array containing Unimplemented pads and User pads
* @violates @ref PORT_PBCFG_REF_4 The compiler/linker shall be checked to ensure that 31 character

*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
static CONST(uint16, PORT_CONST) Port_au16NoUnUsedPadsArrayDefault[PORT_MAX_UNUSED_PADS_U16]=
{
    (uint16)0,
    (uint16)2,
    (uint16)18,
    (uint16)22,
    (uint16)23,
    (uint16)25,
    (uint16)26,
    (uint16)32,
    (uint16)44,
    (uint16)50,
    (uint16)54,
    (uint16)63,
    (uint16)64,
    (uint16)67,
    (uint16)70,
    (uint16)71,
    (uint16)73,
    (uint16)80,
    (uint16)83,
    (uint16)84,
    (uint16)85,
    (uint16)86,
    (uint16)87,
    (uint16)88,
    (uint16)89,
    (uint16)91,
    (uint16)93,
    (uint16)95,
    (uint16)96,
    (uint16)98,
    (uint16)99,
    (uint16)100,
    (uint16)103,
    (uint16)104,
    (uint16)105,
    (uint16)106,
    (uint16)107,
    (uint16)108,
    (uint16)117,
    (uint16)119,
    (uint16)120,
    (uint16)128,
    (uint16)131,
    (uint16)134,
    (uint16)140,
    (uint16)141,
    (uint16)142,
    (uint16)143,
    (uint16)146,
    (uint16)147,
    (uint16)152,
    (uint16)153,
    (uint16)154,
    (uint16)155,
    (uint16)156,
    (uint16)157,
    (uint16)158,
    (uint16)159,
    (uint16)162,
    (uint16)163,
    (uint16)164,
    (uint16)166,
    (uint16)167,
    (uint16)233,
    (uint16)234,
    (uint16)235,
    (uint16)236,
    (uint16)240,
    (uint16)243,
    (uint16)251,
    (uint16)255,
    (uint16)266,
    (uint16)294,
    (uint16)305,
    (uint16)307,
    (uint16)312,
    (uint16)314,
    (uint16)318,
    (uint16)319,
    (uint16)326,
    (uint16)334,
    (uint16)335
};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"
#endif
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
static CONST(uint8, PORT_CONST) u8Port_Etpu_Input_Select[6]={
    0,
    0,
    0,
    0,
    0,
    0,
};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"

/**
 * @brief Default Configuration for Pins not initialized
*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
static CONST(Port_Siul2_UnUsedPinConfigType, PORT_CONST) Port_UnUsedPin =
{
   /**
   * @note: Configuration of Default pin
   */
    (uint32)0x00000040, (uint8)0, (uint8)0
};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"
/**
* @brief Pin default configuration data for configPB

*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
static CONST(Port_Siul2_PinConfigType, PORT_CONST) Port_aPinConfigDefaultPB[PORT_MAX_CONFIGURED_PADS_U16]=
{
    {(Port_InternalPinIdType)298, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)321, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)241, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)270, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)308, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)303, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)320, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)295, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)3, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)4, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)289, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)292, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)297, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)21, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)310, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)6, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)311, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)277, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)327, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)284, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)332, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)274, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)272, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)268, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)267, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)275, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)285, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)273, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)242, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)283, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)264, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)299, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)309, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)271, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)286, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)269, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)316, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)333, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)276, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)317, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)278, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)313, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)262, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)9, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)263, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)279, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)10, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)315, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)19, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)20, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)11, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)8, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)5, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)293, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)300, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)291, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)290, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)296, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)288, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)306, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)265, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)302, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)301, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)246, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)287, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)245, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)248, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)304, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)27, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)28, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)31, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)33, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)38, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)43, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)48, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)49, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)51, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)53, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)57, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)58, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)59, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)60, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)61, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)62, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)68, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)75, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)76, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)77, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)78, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)90, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)92, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)94, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)97, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)101, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)102, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)111, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)114, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)115, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)116, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)118, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)121, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)122, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)123, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)124, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)125, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)126, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)132, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)135, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)136, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)137, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)138, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)139, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)182, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)183, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)189, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)191, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)192, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)193, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)195, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)196, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)197, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)198, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)199, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)207, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)208, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)209, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)210, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)211, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)212, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)213, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)214, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)217, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)218, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)219, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)220, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)244, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)39, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)40, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)47, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)168, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)169, (uint32)0x0000015c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)170, (uint32)0x0000015c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)171, (uint32)0x0000015c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)172, (uint32)0x0000015c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)173, (uint32)0x0000015c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)174, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)175, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)176, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)177, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)178, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)179, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)180, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)181, (uint32)0x0000015c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)184, (uint32)0x0000015c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)185, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)186, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)187, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)188, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)194, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)200, (uint32)0x0000015c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)201, (uint32)0x0000015c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)202, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)203, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)204, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)205, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)206, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)215, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)216, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)221, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)222, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)223, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)224, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)225, (uint32)0x0000059c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)226, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)227, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)228, (uint32)0x0000059c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)229, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)230, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)231, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)232, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)256, (uint32)0x0000059c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)249, (uint32)0x00000c9c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)79, (uint32)0x0000035c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)150, (uint32)0x0000059c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)161, (uint32)0x0000079c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)148, (uint32)0x0000079c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)160, (uint32)0x0000059c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)165, (uint32)0x0000049c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)237, (uint32)0x0000059c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)52, (uint32)0x0000099c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)151, (uint32)0x0000079c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)149, (uint32)0x0000079c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)325, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)324, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)280, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)322, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)331, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)330, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)329, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)328, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)7, (uint32)0x00000c9c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)12, (uint32)0x00000a9c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)1, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)281, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)282, (uint32)0x0000001c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)133, (uint32)0x0000079c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)252, (uint32)0x0000069c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)253, (uint32)0x0000089c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)254, (uint32)0x0000045c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)260, (uint32)0x0000079c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)259, (uint32)0x0000069c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)258, (uint32)0x0000055c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)257, (uint32)0x0000069c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)247, (uint32)0x00000d9c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)250, (uint32)0x0000099c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)238, (uint32)0x0000079c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)239, (uint32)0x0000075c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)69, (uint32)0x0000069c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)66, (uint32)0x0000045c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)72, (uint32)0x0000079c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)74, (uint32)0x00000a9c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)65, (uint32)0x0000059c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)55, (uint32)0x0000ab9c, (uint8)1, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)56, (uint32)0x0000a45c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)45, (uint32)0x0000ab9c, (uint8)1, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)46, (uint32)0x0000a45c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)34, (uint32)0x0000ab9c, (uint8)1, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)35, (uint32)0x0000a55c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)41, (uint32)0x0000ac9c, (uint8)1, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)42, (uint32)0x0000a65c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)29, (uint32)0x0000a99c, (uint8)1, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)24, (uint32)0x0000a45c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)37, (uint32)0x0000ab9c, (uint8)1, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)36, (uint32)0x0000a85c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)109, (uint32)0x0000a89c, (uint8)1, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)110, (uint32)0x0000a45c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)17, (uint32)0x0000079c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)16, (uint32)0x0000075c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)112, (uint32)0x0000059c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)113, (uint32)0x0000045c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)127, (uint32)0x00000b9c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)130, (uint32)0x0000045c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)145, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)81, (uint32)0x0000069c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)82, (uint32)0x0000055c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)144, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)190, (uint32)0x0000009c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)323, (uint32)0x0000005c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)13, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)14, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)15, (uint32)0x0000059c, (uint8)0, (boolean)FALSE, (uint8)1},
    {(Port_InternalPinIdType)30, (uint32)0x0000035c, (uint8)0, (boolean)FALSE, (uint8)0},
    {(Port_InternalPinIdType)261, (uint32)0x0000025c, (uint8)0, (boolean)FALSE, (uint8)0}

};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"
/**
* @brief Pad selection default configuration for configPB

*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
static CONST(Port_Siul2_PadSelConfigType, PORT_CONST) Port_aPadSelConfigDefaultPB[PORT_NMBR_INMUX_REGS_U16]=
{
    (uint32)0x00000000, /*"MSCR_MUX_0"*/
    (uint32)0x00000003, /*"MSCR_MUX_1"*/
    (uint32)0x00000000, /*"MSCR_MUX_2"*/
    (uint32)0x00000005, /*"MSCR_MUX_3"*/
    (uint32)0x00000000, /*"MSCR_MUX_4"*/
    (uint32)0x00000000, /*"MSCR_MUX_5"*/
    (uint32)0x00000000, /*"MSCR_MUX_6"*/
    (uint32)0x00000000, /*"MSCR_MUX_7"*/
    (uint32)0x00000000, /*"MSCR_MUX_8"*/
    (uint32)0x00000000, /*"MSCR_MUX_9"*/
    (uint32)0x00000003, /*"MSCR_MUX_10"*/
    (uint32)0x00000000, /*"MSCR_MUX_11"*/
    (uint32)0x00000000, /*"MSCR_MUX_12"*/
    (uint32)0x00000006, /*"MSCR_MUX_13"*/
    (uint32)0x00000000, /*"MSCR_MUX_14"*/
    (uint32)0x00000000, /*"MSCR_MUX_15"*/
    (uint32)0x00000005, /*"MSCR_MUX_16"*/
    (uint32)0x00000000, /*"MSCR_MUX_17"*/
    (uint32)0x00000000, /*"MSCR_MUX_18"*/
    (uint32)0x00000000, /*"MSCR_MUX_19"*/
    (uint32)0x00000000, /*"MSCR_MUX_20"*/
    (uint32)0x00000000, /*"MSCR_MUX_21"*/
    (uint32)0x00000003, /*"MSCR_MUX_22"*/
    (uint32)0x00000000, /*"MSCR_MUX_23"*/
    (uint32)0x00000000, /*"MSCR_MUX_24"*/
    (uint32)0x00000000, /*"MSCR_MUX_25"*/
    (uint32)0x00000000, /*"MSCR_MUX_26"*/
    (uint32)0x00000000, /*"MSCR_MUX_27"*/
    (uint32)0x00000000, /*"MSCR_MUX_28"*/
    (uint32)0x00000000, /*"MSCR_MUX_29"*/
    (uint32)0x00000000, /*"MSCR_MUX_30"*/
    (uint32)0x00000000, /*"MSCR_MUX_31"*/
    (uint32)0x00000000, /*"MSCR_MUX_32"*/
    (uint32)0x00000000, /*"MSCR_MUX_33"*/
    (uint32)0x00000000, /*"MSCR_MUX_34"*/
    (uint32)0x00000000, /*"MSCR_MUX_35"*/
    (uint32)0x00000000, /*"MSCR_MUX_36"*/
    (uint32)0x00000000, /*"MSCR_MUX_37"*/
    (uint32)0x00000000, /*"MSCR_MUX_38"*/
    (uint32)0x00000000, /*"MSCR_MUX_39"*/
    (uint32)0x00000001, /*"MSCR_MUX_40"*/
    (uint32)0x00000000, /*"MSCR_MUX_41"*/
    (uint32)0x00000000, /*"MSCR_MUX_42"*/
    (uint32)0x00000000, /*"MSCR_MUX_43"*/
    (uint32)0x00000001, /*"MSCR_MUX_44"*/
    (uint32)0x00000000, /*"MSCR_MUX_45"*/
    (uint32)0x00000000, /*"MSCR_MUX_46"*/
    (uint32)0x00000001, /*"MSCR_MUX_47"*/
    (uint32)0x00000000, /*"MSCR_MUX_48"*/
    (uint32)0x00000000, /*"MSCR_MUX_49"*/
    (uint32)0x00000000, /*"MSCR_MUX_50"*/
    (uint32)0x00000000, /*"MSCR_MUX_51"*/
    (uint32)0x00000000, /*"MSCR_MUX_52"*/
    (uint32)0x00000000, /*"MSCR_MUX_53"*/
    (uint32)0x00000000, /*"MSCR_MUX_54"*/
    (uint32)0x00000000, /*"MSCR_MUX_55"*/
    (uint32)0x00000000, /*"MSCR_MUX_56"*/
    (uint32)0x00000000, /*"MSCR_MUX_57"*/
    (uint32)0x00000000, /*"MSCR_MUX_58"*/
    (uint32)0x00000000, /*"MSCR_MUX_59"*/
    (uint32)0x00000000, /*"MSCR_MUX_60"*/
    (uint32)0x00000000, /*"MSCR_MUX_61"*/
    (uint32)0x00000004, /*"MSCR_MUX_62"*/
    (uint32)0x00000000, /*"MSCR_MUX_63"*/
    (uint32)0x00000000, /*"MSCR_MUX_64"*/
    (uint32)0x00000000, /*"MSCR_MUX_65"*/
    (uint32)0x00000000, /*"MSCR_MUX_66"*/
    (uint32)0x00000000, /*"MSCR_MUX_67"*/
    (uint32)0x00000000, /*"MSCR_MUX_68"*/
    (uint32)0x00000000, /*"MSCR_MUX_69"*/
    (uint32)0x00000000, /*"MSCR_MUX_70"*/
    (uint32)0x00000000, /*"MSCR_MUX_71"*/
    (uint32)0x00000000, /*"MSCR_MUX_72"*/
    (uint32)0x00000000, /*"MSCR_MUX_73"*/
    (uint32)0x00000000, /*"MSCR_MUX_74"*/
    (uint32)0x00000000, /*"MSCR_MUX_75"*/
    (uint32)0x00000000, /*"MSCR_MUX_76"*/
    (uint32)0x00000000, /*"MSCR_MUX_77"*/
    (uint32)0x00000000, /*"MSCR_MUX_78"*/
    (uint32)0x00000000, /*"MSCR_MUX_79"*/
    (uint32)0x00000000, /*"MSCR_MUX_80"*/
    (uint32)0x00000000, /*"MSCR_MUX_81"*/
    (uint32)0x00000000, /*"MSCR_MUX_82"*/
    (uint32)0x00000000, /*"MSCR_MUX_83"*/
    (uint32)0x00000000, /*"MSCR_MUX_84"*/
    (uint32)0x00000000, /*"MSCR_MUX_85"*/
    (uint32)0x00000000, /*"MSCR_MUX_86"*/
    (uint32)0x00000000, /*"MSCR_MUX_87"*/
    (uint32)0x00000000, /*"MSCR_MUX_88"*/
    (uint32)0x00000000, /*"MSCR_MUX_89"*/
    (uint32)0x00000000, /*"MSCR_MUX_90"*/
    (uint32)0x00000000, /*"MSCR_MUX_91"*/
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000, /*"MSCR_MUX_93"*/
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000, /*"MSCR_MUX_95"*/
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000, /*"MSCR_MUX_97"*/
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000, /*"MSCR_MUX_99"*/
    (uint32)0x00000000, /*"MSCR_MUX_100"*/
    (uint32)0x00000000, /*"MSCR_MUX_101"*/
    (uint32)0x00000000, /*"MSCR_MUX_102"*/
    (uint32)0x00000000, /*"MSCR_MUX_103"*/
    (uint32)0x00000000, /*"MSCR_MUX_104"*/
    (uint32)0x00000000, /*"MSCR_MUX_105"*/
    (uint32)0x00000000, /*"MSCR_MUX_106"*/
    (uint32)0x00000000, /*"MSCR_MUX_107"*/
    (uint32)0x00000000, /*"MSCR_MUX_108"*/
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000, /*"MSCR_MUX_111"*/
    (uint32)0x00000000, /*"MSCR_MUX_112"*/
    (uint32)0x00000000, /*"MSCR_MUX_113"*/
    (uint32)0x00000000, /*"MSCR_MUX_114"*/
    (uint32)0x00000000, /*"MSCR_MUX_115"*/
    (uint32)0x00000000, /*"MSCR_MUX_116"*/
    (uint32)0x00000000, /*"MSCR_MUX_117"*/
    (uint32)0x00000000, /*"MSCR_MUX_118"*/
    (uint32)0x00000000, /*"MSCR_MUX_119"*/
    (uint32)0x00000000, /*"MSCR_MUX_120"*/
    (uint32)0x00000000, /*"MSCR_MUX_121"*/
    (uint32)0x00000000, /*"MSCR_MUX_122"*/
    (uint32)0x00000000, /*"MSCR_MUX_123"*/
    (uint32)0x00000000, /*"MSCR_MUX_124"*/
    (uint32)0x00000000, /*"MSCR_MUX_125"*/
    (uint32)0x00000000, /*"MSCR_MUX_126"*/
    (uint32)0x00000000, /*"MSCR_MUX_127"*/
    (uint32)0x00000000, /*"MSCR_MUX_128"*/
    (uint32)0x00000000, /*"MSCR_MUX_129"*/
    (uint32)0x00000000, /*"MSCR_MUX_130"*/
    (uint32)0x00000000, /*"MSCR_MUX_131"*/
    (uint32)0x00000000, /*"MSCR_MUX_132"*/
    (uint32)0x00000000, /*"MSCR_MUX_133"*/
    (uint32)0x00000000, /*"MSCR_MUX_134"*/
    (uint32)0x00000000, /*"MSCR_MUX_135"*/
    (uint32)0x00000000, /*"MSCR_MUX_136"*/
    (uint32)0x00000000, /*"MSCR_MUX_137"*/
    (uint32)0x00000000, /*"MSCR_MUX_138"*/
    (uint32)0x00000000, /*"MSCR_MUX_139"*/
    (uint32)0x00000000, /*"MSCR_MUX_140"*/
    (uint32)0x00000000, /*"MSCR_MUX_141"*/
    (uint32)0x00000000, /*"MSCR_MUX_142"*/
    (uint32)0x00000000, /*"MSCR_MUX_143"*/
    (uint32)0x00000000, /*"MSCR_MUX_144"*/
    (uint32)0x00000000, /*"MSCR_MUX_145"*/
    (uint32)0x00000000, /*"MSCR_MUX_146"*/
    (uint32)0x00000000, /*"MSCR_MUX_147"*/
};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"


#if (PORT_SET_SIUL2_API == STD_ON)
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
static CONST(Port_siul2_request_config, PORT_CONST) Port_Siul2_config[0] =
{
    
};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"
#endif


#if (STD_ON == PORT_LVDS_SUPPORT)
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
static CONST(Port_LVDSConfigType, PORT_CONST) Port_LVDS_Config[PORT_LVDS_PIN_PAIR_NUM_U16] =
{
};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"
#endif


/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode NotUsedPortPin
* @violates @ref PORT_PBCFG_REF_4 Violates MISRA 2004 Required Rule 8.10
*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
CONST(Port_ConfigType, PORT_CONST) NotUsedPortPin =
{
      .Port_UsedPin={
            PORT_MAX_CONFIGURED_PADS_U16,
            Port_aPinConfigDefaultPB,
            Port_aPadSelConfigDefaultPB
        },
        .Port_UnusedPin={
            PORT_MAX_UNUSED_PADS_U16,
    #if (PORT_MAX_UNUSED_PADS_U16 != 0U)
      Port_au16NoUnUsedPadsArrayDefault,
    #else
      NULL_PTR,
    #endif
            &Port_UnUsedPin
        },
        .Etpu_IS=u8Port_Etpu_Input_Select,
        .coreMap = Port_CoreMap,
#if (PORT_SET_SIUL2_API == STD_ON)
        .reqConfig = Port_Siul2_config,
#endif
#if (STD_ON == PORT_LVDS_SUPPORT)
        .LVDSConfig = Port_LVDS_Config
#endif
};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"
/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode PortContainer
* @violates @ref PORT_PBCFG_REF_4 Violates MISRA 2004 Required Rule 8.10
*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
CONST(Port_ConfigType, PORT_CONST) PortContainer =
{
      .Port_UsedPin={
            PORT_MAX_CONFIGURED_PADS_U16,
            Port_aPinConfigDefaultPB,
            Port_aPadSelConfigDefaultPB
        },
        .Port_UnusedPin={
            PORT_MAX_UNUSED_PADS_U16,
    #if (PORT_MAX_UNUSED_PADS_U16 != 0U)
      Port_au16NoUnUsedPadsArrayDefault,
    #else
      NULL_PTR,
    #endif
            &Port_UnUsedPin
        },
        .Etpu_IS=u8Port_Etpu_Input_Select,
        .coreMap = Port_CoreMap,
#if (PORT_SET_SIUL2_API == STD_ON)
        .reqConfig = Port_Siul2_config,
#endif
#if (STD_ON == PORT_LVDS_SUPPORT)
        .LVDSConfig = Port_LVDS_Config
#endif
};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Port INOUT settings data
*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
CONST(Port_InoutSettingType,PORT_CONST) Port_aPadFunctInoutMuxSettings[PORT_INOUT_TABLE_NUM_ENTRIES_U16] =
{


  /* Inout settings for pad PORT0:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT0 input func */
  {0U, 88U, 0U, 10U},

  /* Inout settings for pad PORT2:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT2 input func */
  {2U, 88U, 2U, 10U},

  /* Inout settings for pad PORT10:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI4_DSPI4_SCK_IN_OUT10 input func */
  {10U, 88U, 10U, 9U},

  /* Inout settings for pad PORT22:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI9_DSPI9_SCK_IN_OUT22 input func */
  {22U, 88U, 22U, 8U},

  /* Inout settings for pad PORT23:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI19_DSPI19_SCK_IN_OUT23 input func */
  {23U, 88U, 23U, 10U},

  /* Inout settings for pad PORT26:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI7_DSPI7_SCK_IN_OUT26 input func */
  {26U, 88U, 26U, 11U},

  /* Inout settings for pad PORT36:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI2_DSPI2_SCK_IN_OUT36 input func */
  {36U, 88U, 36U, 13U},

  /* Inout settings for pad PORT36:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C0_I2C0_SDA_IN_OUT36 input func */
  {36U, 89U, 36U, 7U},

  /* Inout settings for pad PORT37:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C0_I2C0_SCL_IN_OUT37 input func */
  {37U, 88U, 37U, 4U},

  /* Inout settings for pad PORT39:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI19_DSPI19_SCK_IN_OUT39 input func */
  {39U, 88U, 39U, 14U},

  /* Inout settings for pad PORT40:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI8_DSPI8_SCK_IN_OUT40 input func */
  {40U, 88U, 40U, 0U},

  /* Inout settings for pad PORT46:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI6_DSPI6_SCK_IN_OUT46 input func */
  {46U, 88U, 46U, 10U},

  /* Inout settings for pad PORT50:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI17_DSPI17_SCK_IN_OUT50 input func */
  {50U, 88U, 50U, 11U},

  /* Inout settings for pad PORT54:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI2_DSPI2_SCK_IN_OUT54 input func */
  {54U, 88U, 54U, 11U},

  /* Inout settings for pad PORT56:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI19_DSPI19_SCK_IN_OUT56 input func */
  {56U, 88U, 56U, 13U},

  /* Inout settings for pad PORT59:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI6_DSPI6_SCK_IN_OUT59 input func */
  {59U, 88U, 59U, 7U},

  /* Inout settings for pad PORT64:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT64 input func */
  {64U, 88U, 64U, 6U},

  /* Inout settings for pad PORT67:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT67 input func */
  {67U, 88U, 67U, 7U},

  /* Inout settings for pad PORT69:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI17_DSPI17_SCK_IN_OUT69 input func */
  {69U, 88U, 69U, 6U},

  /* Inout settings for pad PORT69:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI11_DSPI11_SCK_P_IN_OUT69 input func */
  {69U, 89U, 69U, 0U},

  /* Inout settings for pad PORT76:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C1_I2C1_SDA_IN_OUT76 input func */
  {76U, 88U, 76U, 4U},

  /* Inout settings for pad PORT77:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C1_I2C1_SCL_IN_OUT77 input func */
  {77U, 88U, 77U, 6U},

  /* Inout settings for pad PORT81:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI18_DSPI18_SCKN_IN_OUT81 input func */
  {81U, 88U, 81U, 0U},

  /* Inout settings for pad PORT81:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI11_DSPI11_SCK_N_IN_OUT81 input func */
  {81U, 89U, 81U, 0U},

  /* Inout settings for pad PORT82:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI18_DSPI18_SCKP_IN_OUT82 input func */
  {82U, 88U, 82U, 0U},

  /* Inout settings for pad PORT82:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI11_DSPI11_SCK_P_IN_OUT82 input func */
  {82U, 89U, 82U, 0U},

  /* Inout settings for pad PORT82:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C0_I2C0_SCL_IN_OUT82 input func */
  {82U, 90U, 82U, 3U},

  /* Inout settings for pad PORT83:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI0_DSPI0_SCK_IN_OUT83 input func */
  {83U, 88U, 83U, 7U},

  /* Inout settings for pad PORT83:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI11_DSPI11_SCK_P_IN_OUT83 input func */
  {83U, 89U, 83U, 0U},

  /* Inout settings for pad PORT83:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C0_I2C0_SDA_IN_OUT83 input func */
  {83U, 90U, 83U, 4U},

  /* Inout settings for pad PORT85:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI14_DSPI14_SCK_N_IN_OUT85 input func */
  {85U, 88U, 85U, 0U},

  /* Inout settings for pad PORT86:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI14_DSPI14_SCK_P_IN_OUT86 input func */
  {86U, 88U, 86U, 0U},

  /* Inout settings for pad PORT89:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C1_I2C1_SCL_IN_OUT89 input func */
  {89U, 88U, 89U, 4U},

  /* Inout settings for pad PORT92:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C1_I2C1_SDA_IN_OUT92 input func */
  {92U, 88U, 92U, 6U},

  /* Inout settings for pad PORT93:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI7_DSPI7_SCK_IN_OUT93 input func */
  {93U, 88U, 93U, 8U},

  /* Inout settings for pad PORT96:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI10_DSPI10_SCK_IN_OUT96 input func */
  {96U, 88U, 96U, 11U},

  /* Inout settings for pad PORT98:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI2_DSPI2_SCK_IN_OUT98 input func */
  {98U, 88U, 98U, 9U},

  /* Inout settings for pad PORT106:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI21_DSPI21_SCK_IN_OUT106 input func */
  {106U, 88U, 106U, 6U},

  /* Inout settings for pad PORT108:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI5_DSPI5_SCK_IN_OUT108 input func */
  {108U, 88U, 108U, 7U},

  /* Inout settings for pad PORT108:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI7_DSPI7_SCK_IN_OUT108 input func */
  {108U, 89U, 108U, 9U},

  /* Inout settings for pad PORT109:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI21_DSPI21_SCK_IN_OUT109 input func */
  {109U, 88U, 109U, 6U},

  /* Inout settings for pad PORT112:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI1_DSPI1_SCK_IN_OUT112 input func */
  {112U, 88U, 112U, 10U},

  /* Inout settings for pad PORT114:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI10_DSPI10_SCK_IN_OUT114 input func */
  {114U, 88U, 114U, 13U},

  /* Inout settings for pad PORT115:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI18_DSPI18_SCK_IN_OUT115 input func */
  {115U, 88U, 115U, 12U},

  /* Inout settings for pad PORT116:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C0_I2C0_SCL_IN_OUT116 input func */
  {116U, 88U, 116U, 3U},

  /* Inout settings for pad PORT117:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* I2C0_I2C0_SDA_IN_OUT117 input func */
  {117U, 88U, 117U, 5U},

  /* Inout settings for pad PORT118:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI18_DSPI18_SCK_IN_OUT118 input func */
  {118U, 88U, 118U, 10U},

  /* Inout settings for pad PORT118:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT118 input func */
  {118U, 89U, 118U, 12U},

  /* Inout settings for pad PORT120:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI18_DSPI18_SCK_IN_OUT120 input func */
  {120U, 88U, 120U, 6U},

  /* Inout settings for pad PORT120:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT120 input func */
  {120U, 89U, 120U, 8U},

  /* Inout settings for pad PORT121:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI15_DSPI15_SCK_N_IN_OUT121 input func */
  {121U, 88U, 121U, 0U},

  /* Inout settings for pad PORT122:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI15_DSPI15_SCK_P_IN_OUT122 input func */
  {122U, 88U, 122U, 0U},

  /* Inout settings for pad PORT126:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI21_DSPI21_SCK_IN_OUT126 input func */
  {126U, 88U, 126U, 6U},

  /* Inout settings for pad PORT127:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT127 input func */
  {127U, 88U, 127U, 14U},

  /* Inout settings for pad PORT135:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI1_DSPI1_SCK_IN_OUT135 input func */
  {135U, 88U, 135U, 11U},

  /* Inout settings for pad PORT136:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI16_DSPI16_SCK_IN_OUT136 input func */
  {136U, 88U, 136U, 6U},

  /* Inout settings for pad PORT138:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI16_DSPI16_SCK_IN_OUT138 input func */
  {138U, 88U, 138U, 8U},

  /* Inout settings for pad PORT143:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI12_DSPI12_SCK_IN_OUT143 input func */
  {143U, 88U, 143U, 11U},

  /* Inout settings for pad PORT145:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT145 input func */
  {145U, 88U, 145U, 8U},

  /* Inout settings for pad PORT147:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT147 input func */
  {147U, 88U, 147U, 11U},

  /* Inout settings for pad PORT148:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI20_DSPI20_SCKN_IN_OUT148 input func */
  {148U, 88U, 148U, 0U},

  /* Inout settings for pad PORT148:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI13_DSPI13_SCK_N_IN_OUT148 input func */
  {148U, 89U, 148U, 0U},

  /* Inout settings for pad PORT149:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI20_DSPI20_SCKP_IN_OUT149 input func */
  {149U, 88U, 149U, 0U},

  /* Inout settings for pad PORT149:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI13_DSPI13_SCK_P_IN_OUT149 input func */
  {149U, 89U, 149U, 0U},

  /* Inout settings for pad PORT151:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI20_DSPI20_SCK_IN_OUT151 input func */
  {151U, 88U, 151U, 8U},

  /* Inout settings for pad PORT155:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI4_DSPI4_SCK_IN_OUT155 input func */
  {155U, 88U, 155U, 6U},

  /* Inout settings for pad PORT155:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI16_DSPI16_SCK_IN_OUT155 input func */
  {155U, 89U, 155U, 7U},

  /* Inout settings for pad PORT156:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI5_DSPI5_SCK_IN_OUT156 input func */
  {156U, 88U, 156U, 6U},

  /* Inout settings for pad PORT156:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI16_DSPI16_SCK_IN_OUT156 input func */
  {156U, 89U, 156U, 7U},

  /* Inout settings for pad PORT161:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI6_DSPI6_SCK_IN_OUT161 input func */
  {161U, 88U, 161U, 14U},

  /* Inout settings for pad PORT236:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT236 input func */
  {236U, 88U, 236U, 7U},

  /* Inout settings for pad PORT242:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI18_DSPI18_SCK_IN_OUT242 input func */
  {242U, 88U, 242U, 14U},

  /* Inout settings for pad PORT243:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI3_DSPI3_SCK_IN_OUT243 input func */
  {243U, 88U, 243U, 10U},

  /* Inout settings for pad PORT244:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI5_DSPI5_SCK_IN_OUT244 input func */
  {244U, 88U, 244U, 10U},

  /* Inout settings for pad PORT248:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI2_DSPI2_SCK_IN_OUT248 input func */
  {248U, 88U, 248U, 10U},

  /* Inout settings for pad PORT250:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI2_DSPI2_SCK_IN_OUT250 input func */
  {250U, 88U, 250U, 9U},

  /* Inout settings for pad PORT252:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI1_DSPI1_SCK_IN_OUT252 input func */
  {252U, 88U, 252U, 6U},

  /* Inout settings for pad PORT252:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI20_DSPI20_SCK_IN_OUT252 input func */
  {252U, 89U, 252U, 7U},

  /* Inout settings for pad PORT253:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI1_DSPI1_SCK_IN_OUT253 input func */
  {253U, 88U, 253U, 11U},

  /* Inout settings for pad PORT255:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI18_DSPI18_SCK_IN_OUT255 input func */
  {255U, 88U, 255U, 7U},

  /* Inout settings for pad PORT259:     {MSCR, MODE, INMUX reg, PADSEL val} */
  /* DSPI4_DSPI4_SCK_IN_OUT259 input func */
  {259U, 88U, 259U, 6U}


};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"

/**
* @brief Port INPUT INMUX settings data
*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
CONST(Port_InMuxSettingType,PORT_CONST) Port_aPadFunctInMuxSettings[PORT_INPUT_INMUX_TABLE_NUM_ENTRIES_U16]=
{

  /* INMUX settings for pad not available:  */
  { NO_INPUTMUX_U16, 0U},
  /* INMUX settings for pad PORT0:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN4_10 input func */
  {0U, 1U},
  /* GTM_TIM3_IN0_1 input func */
  {0U, 2U},
  /* GTM_TIM2_IN0_1 input func */
  {0U, 3U},
  /* EMIOS_emios_odis input func */
  {0U, 4U},
  /* GMAC_GETH_MDIOA input func */
  {0U, 7U},
  /* DSPI3_DSPI3_SCK input func */
  {0U, 10U},
  /* GTM_TOUT9 input func */
  {0U, 8U},
  /* LINFLEX3_LIN3_TX input func */
  {0U, 11U},
  /* DSPI3_DSPI3_SOUT input func */
  {0U, 12U},
  /* M_CAN_5_CAN10_TXD input func */
  {0U, 13U},
  /* EMIOS_EMIOS_20 input func */
  {0U, 14U},
  /* GMAC_GETH_MDIO input func */
  {0U, 7U},
  /* INMUX settings for pad PORT1:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN5_11 input func */
  {1U, 1U},
  /* GTM_TIM3_IN1_1 input func */
  {1U, 2U},
  /* GTM_TIM2_IN1_1 input func */
  {1U, 3U},
  /* EMIOS_EMIOS_0 input func */
  {1U, 4U},
  /* LINFLEX3_LIN3_RX input func */
  {1U, 5U},
  /* DSPI3_DSPI3_SINE input func */
  {1U, 6U},
  /* M_CAN_5_CAN10_RXDA input func */
  {1U, 8U},
  /* PSI5_PSI5_RX0A input func */
  {1U, 9U},
  /* EMIOS_EMIOS_6 input func */
  {1U, 10U},
  /* SENT_SENT_SENT0B input func */
  {1U, 11U},
  /* GTM_TOUT10 input func */
  {1U, 14U},
  /* LINFLEX3_LIN3_TX input func */
  {1U, 15U},
  /* DSPI3_DSPI3_SOUT input func */
  {1U, 0U},
  /* SENT_SENT_SPC0 input func */
  {1U, 11U},
  /* EMIOS_EMIOS_6 input func */
  {1U, 4U},
  /* INMUX settings for pad PORT2:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN6_11 input func */
  {2U, 1U},
  /* GTM_TIM3_IN1_2 input func */
  {2U, 2U},
  /* GTM_TIM2_IN1_2 input func */
  {2U, 3U},
  /* SENT_SENT_SENT1B input func */
  {2U, 6U},
  /* DSPI3_DSPI3_SCK input func */
  {2U, 10U},
  /* GTM_TOUT11 input func */
  {2U, 8U},
  /* M_CAN_10_CAN21_TXD input func */
  {2U, 11U},
  /* PSI5_PSI5_TX0 input func */
  {2U, 12U},
  /* M_CAN_4_CAN03_TXD input func */
  {2U, 13U},
  /* DSPI19_DSPI19_PCS4 input func */
  {2U, 14U},
  /* EMIOS_EMIOS_7 input func */
  {2U, 15U},
  /* INMUX settings for pad PORT3:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN7_10 input func */
  {3U, 1U},
  /* GTM_TIM3_IN2_1 input func */
  {3U, 2U},
  /* GTM_TIM2_IN2_1 input func */
  {3U, 3U},
  /* EMIOS_EMIOS_1 input func */
  {3U, 4U},
  /* SAR_ADC_SDADC_EDSADC_ITR5F input func */
  {3U, 6U},
  /* PSI5_PSI5_RX1A input func */
  {3U, 7U},
  /* M_CAN_4_CAN03_RXDA input func */
  {3U, 8U},
  /* M_CAN_10_CAN21_RXDA input func */
  {3U, 9U},
  /* PSI5S_PSI5S_RXA input func */
  {3U, 10U},
  /* SENT_SENT_SENT2B input func */
  {3U, 11U},
  /* EMIOS_EMIOS_7 input func */
  {3U, 12U},
  /* DSPI3_DSPI3_PCS0 input func */
  {3U, 0U},
  /* GTM_TOUT12 input func */
  {3U, 14U},
  /* DSPI3_DSPI3_PCS0 input func */
  {3U, 0U},
  /* SENT_SENT_SPC2 input func */
  {3U, 11U},
  /* EMIOS_EMIOS_16 input func */
  {3U, 3U},
  /* INMUX settings for pad PORT4:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN4_1 input func */
  {4U, 1U},
  /* GTM_TIM3_IN3_1 input func */
  {4U, 2U},
  /* GTM_TIM2_IN3_1 input func */
  {4U, 3U},
  /* SENT_SENT_SENT3B input func */
  {4U, 5U},
  /* LINFLEX10_LIN10_RX input func */
  {4U, 8U},
  /* DSPI0_DSPI0_SINA input func */
  {4U, 9U},
  /* GTM_DTMA5_0 input func */
  {4U, 10U},
  /* GTM_DTMT3_0 input func */
  {4U, 11U},
  /* GTM_TOUT13 input func */
  {4U, 13U},
  /* PSI5S_PSI5S_TX input func */
  {4U, 14U},
  /* M_CAN_6_CAN11_TXD input func */
  {4U, 15U},
  /* PSI5_PSI5_TX1 input func */
  {4U, 0U},
  /* ACMP4_EVADC_FC4BFLOUT input func */
  {4U, 1U},
  /* SENT_SENT_SPC3 input func */
  {4U, 5U},
  /* EMIOS_EMIOS_17 input func */
  {4U, 3U},
  /* INMUX settings for pad PORT5:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN4_1 input func */
  {5U, 1U},
  /* GTM_TIM3_IN0_11 input func */
  {5U, 2U},
  /* GTM_TIM2_IN4_1 input func */
  {5U, 3U},
  /* EMIOS_EMIOS_2 input func */
  {5U, 4U},
  /* DSPI10_DSPI10_PCS0 input func */
  {5U, 5U},
  /* PSI5_PSI5_RX2A input func */
  {5U, 6U},
  /* EMIOS_EMIOS_16 input func */
  {5U, 7U},
  /* SENT_SENT_SENT4B input func */
  {5U, 8U},
  /* M_CAN_6_CAN11_RXDB input func */
  {5U, 9U},
  /* GTM_DTMT1_1 input func */
  {5U, 10U},
  /* GTM_DTMT4_2 input func */
  {5U, 11U},
  /* GTM_TOUT14 input func */
  {5U, 12U},
  /* DSPI19_DSPI19_PCS3 input func */
  {5U, 14U},
  /* DSPI10_DSPI10_PCS0 input func */
  {5U, 15U},
  /* ACMP0_EVADC_FC0BFLOUT input func */
  {5U, 0U},
  /* SENT_SENT_SPC4 input func */
  {5U, 8U},
  /* EMIOS_EMIOS_18 input func */
  {5U, 2U},
  /* INMUX settings for pad PORT6:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN5_1 input func */
  {6U, 1U},
  /* GTM_TIM3_IN1_14 input func */
  {6U, 2U},
  /* GTM_TIM2_IN5_1 input func */
  {6U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR4F input func */
  {6U, 4U},
  /* SENT_SENT_SENT5B input func */
  {6U, 6U},
  /* LINFLEX5_LIN5_RX input func */
  {6U, 7U},
  /* DSPI5_DSPI5_SINA input func */
  {6U, 8U},
  /* GTM_DTMA6_0 input func */
  {6U, 9U},
  /* GTM_DTMT3_1 input func */
  {6U, 10U},
  /* GTM_TOUT15 input func */
  {6U, 11U},
  /* ACMP5_EVADC_FC5BFLOUT input func */
  {6U, 13U},
  /* PSI5_PSI5_TX2 input func */
  {6U, 14U},
  /* SENT_SENT_SPC5 input func */
  {6U, 6U},
  /* EMIOS_EMIOS_19 input func */
  {6U, 1U},
  /* INMUX settings for pad PORT7:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN6_1 input func */
  {7U, 1U},
  /* GTM_TIM3_IN2_11 input func */
  {7U, 2U},
  /* GTM_TIM2_IN6_1 input func */
  {7U, 3U},
  /* EMIOS_EMIOS_6 input func */
  {7U, 4U},
  /* SENT_SENT_SENT6B input func */
  {7U, 5U},
  /* EMIOS_EMIOS_20 input func */
  {7U, 7U},
  /* EMIOS_EMIOS_17 input func */
  {7U, 8U},
  /* GTM_DTMT0_2 input func */
  {7U, 10U},
  /* GTM_TOUT16 input func */
  {7U, 12U},
  /* LINFLEX5_LIN5_TX input func */
  {7U, 13U},
  /* DSPI5_DSPI5_SOUT input func */
  {7U, 14U},
  /* ACMP2_EVADC_FC2BFLOUT input func */
  {7U, 15U},
  /* SENT_SENT_SPC6 input func */
  {7U, 5U},
  /* EMIOS_EMIOS_6 input func */
  {7U, 3U},
  /* INMUX settings for pad PORT8:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN7_1 input func */
  {8U, 1U},
  /* GTM_TIM3_IN3_11 input func */
  {8U, 2U},
  /* GTM_TIM2_IN7_1 input func */
  {8U, 3U},
  /* EMIOS_EMIOS_7 input func */
  {8U, 4U},
  /* SENT_SENT_SENT7B input func */
  {8U, 5U},
  /* EMIOS_EMIOS_18 input func */
  {8U, 8U},
  /* LINFLEX10_LIN10_RX input func */
  {8U, 10U},
  /* DSPI0_DSPI0_SINB input func */
  {8U, 11U},
  /* GTM_TOUT17 input func */
  {8U, 13U},
  /* DSPI19_DSPI19_PCS6 input func */
  {8U, 14U},
  /* LINFLEX10_LIN10_TX input func */
  {8U, 15U},
  /* DSPI0_DSPI0_SOUT input func */
  {8U, 0U},
  /* SENT_SENT_SPC7 input func */
  {8U, 5U},
  /* EMIOS_EMIOS_16 input func */
  {8U, 3U},
  /* INMUX settings for pad PORT9:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN0_7 input func */
  {9U, 1U},
  /* GTM_TIM1_IN0_1 input func */
  {9U, 2U},
  /* GTM_TIM0_IN0_1 input func */
  {9U, 3U},
  /* EMIOS_EMIOS_16 input func */
  {9U, 4U},
  /* SENT_SENT_SENT8B input func */
  {9U, 5U},
  /* EMIOS_EMIOS_19 input func */
  {9U, 6U},
  /* SAR_ADC_SDADC_EDSADC_ITR3F input func */
  {9U, 8U},
  /* GTM_TOUT18 input func */
  {9U, 13U},
  /* DSPI19_DSPI19_PCS7 input func */
  {9U, 14U},
  /* LINFLEX4_LIN4_TX input func */
  {9U, 1U},
  /* DSPI4_DSPI4_SOUT input func */
  {9U, 2U},
  /* SENT_SENT_SPC8 input func */
  {9U, 5U},
  /* EMIOS_EMIOS_18 input func */
  {9U, 4U},
  /* INMUX settings for pad PORT10:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN1_11 input func */
  {10U, 1U},
  /* GTM_TIM1_IN1_1 input func */
  {10U, 2U},
  /* GTM_TIM0_IN1_1 input func */
  {10U, 3U},
  /* SENT_SENT_SENT9B input func */
  {10U, 4U},
  /* DSPI4_DSPI4_SCK input func */
  {10U, 9U},
  /* GTM_TOUT19 input func */
  {10U, 7U},
  /* SENT_SENT_SPC9 input func */
  {10U, 4U},
  /* EMIOS_EMIOS_21 input func */
  {10U, 11U},
  /* INMUX settings for pad PORT11:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN2_11 input func */
  {11U, 1U},
  /* GTM_TIM1_IN2_1 input func */
  {11U, 2U},
  /* GTM_TIM0_IN2_1 input func */
  {11U, 3U},
  /* SENT_SENT_SENT10B input func */
  {11U, 7U},
  /* DSPI4_DSPI4_PCS0 input func */
  {11U, 11U},
  /* GTM_TOUT20 input func */
  {11U, 9U},
  /* DSPI4_DSPI4_PCS0 input func */
  {11U, 11U},
  /* INMUX settings for pad PORT12:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN3_11 input func */
  {12U, 1U},
  /* GTM_TIM1_IN3_1 input func */
  {12U, 2U},
  /* GTM_TIM0_IN3_1 input func */
  {12U, 3U},
  /* LINFLEX4_LIN4_RX input func */
  {12U, 6U},
  /* DSPI4_DSPI4_SINA input func */
  {12U, 7U},
  /* SENT_SENT_SENT11B input func */
  {12U, 8U},
  /* GTM_TOUT21 input func */
  {12U, 10U},
  /* EMIOS_EMIOS_21 input func */
  {12U, 11U},
  /* INMUX settings for pad PORT13:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN5_2 input func */
  {13U, 1U},
  /* GTM_TIM5_IN0_1 input func */
  {13U, 2U},
  /* GTM_TIM4_IN0_1 input func */
  {13U, 3U},
  /* GTM_TOUT167 input func */
  {13U, 5U},
  /* INMUX settings for pad PORT14:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN6_2 input func */
  {14U, 1U},
  /* GTM_TIM5_IN7_1 input func */
  {14U, 2U},
  /* GTM_TIM4_IN7_1 input func */
  {14U, 3U},
  /* GTM_TOUT166 input func */
  {14U, 5U},
  /* INMUX settings for pad PORT15:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN7_2 input func */
  {15U, 1U},
  /* GTM_TIM5_IN1_1 input func */
  {15U, 2U},
  /* GTM_TIM4_IN1_1 input func */
  {15U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR6F input func */
  {15U, 4U},
  /* GTM_TOUT168 input func */
  {15U, 5U},
  /* INMUX settings for pad PORT16:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN4_1 input func */
  {16U, 1U},
  /* GTM_TIM4_IN4_1 input func */
  {16U, 2U},
  /* GTM_TIM2_IN6_13 input func */
  {16U, 3U},
  /* M_CAN_10_CAN21_RXDE input func */
  {16U, 4U},
  /* SAR_ADC_SDADC_EDSADC_ITR6E input func */
  {16U, 5U},
  /* M_CAN_4_CAN03_RXDF input func */
  {16U, 6U},
  /* LINFLEX6_LIN6_RX input func */
  {16U, 7U},
  /* DSPI6_DSPI6_SINB input func */
  {16U, 8U},
  /* GTM_TOUT155 input func */
  {16U, 9U},
  /* INMUX settings for pad PORT17:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN1_2 input func */
  {17U, 1U},
  /* GTM_TIM4_IN1_2 input func */
  {17U, 2U},
  /* SAR_ADC_SDADC_EDSADC_ITR8E input func */
  {17U, 3U},
  /* FLEXRAY1_ERAY1_RXDA1 input func */
  {17U, 4U},
  /* SENT_SENT_SENT15B input func */
  {17U, 5U},
  /* GTM_TOUT159 input func */
  {17U, 6U},
  /* LINFLEX6_LIN6_TX input func */
  {17U, 7U},
  /* DSPI6_DSPI6_SOUT input func */
  {17U, 8U},
  /* INMUX settings for pad PORT18:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN5_1 input func */
  {18U, 1U},
  /* GTM_TIM4_IN5_1 input func */
  {18U, 2U},
  /* GTM_TOUT156 input func */
  {18U, 4U},
  /* M_CAN_4_CAN03_TXD input func */
  {18U, 5U},
  /* M_CAN_10_CAN21_TXD input func */
  {18U, 6U},
  /* INMUX settings for pad PORT19:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN5_2 input func */
  {19U, 1U},
  /* GTM_TIM2_IN0_14 input func */
  {19U, 2U},
  /* GTM_TIM0_IN5_8 input func */
  {19U, 3U},
  /* DSPI19_DSPI19_PCSB input func */
  {19U, 4U},
  /* SAR_ADC_SDADC_EDSADC_ITR7F input func */
  {19U, 5U},
  /* GTM_TOUT111 input func */
  {19U, 6U},
  /* M_CAN_2_CAN01_TXD input func */
  {19U, 8U},
  /* INMUX settings for pad PORT20:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN6_2 input func */
  {20U, 1U},
  /* GTM_TIM2_IN1_14 input func */
  {20U, 2U},
  /* GTM_TIM0_IN6_8 input func */
  {20U, 3U},
  /* M_CAN_2_CAN01_RXDC input func */
  {20U, 4U},
  /* SAR_ADC_SDADC_EDSADC_ITR7E input func */
  {20U, 5U},
  /* DSPI9_DSPI9_PCS0 input func */
  {20U, 8U},
  /* GTM_TOUT112 input func */
  {20U, 6U},
  /* DSPI9_DSPI9_PCS0 input func */
  {20U, 8U},
  /* INMUX settings for pad PORT21:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN3_2 input func */
  {21U, 1U},
  /* GTM_TIM2_IN3_7 input func */
  {21U, 2U},
  /* GTM_TIM2_IN2_7 input func */
  {21U, 3U},
  /* DSPI19_DSPI19_SINC input func */
  {21U, 4U},
  /* LINFLEX9_LIN9_RX input func */
  {21U, 6U},
  /* DSPI9_DSPI9_SINA input func */
  {21U, 7U},
  /* GTM_TOUT113 input func */
  {21U, 8U},
  /* DSPI19_DSPI19_SOUT input func */
  {21U, 9U},
  /* INMUX settings for pad PORT22:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN6_2 input func */
  {22U, 1U},
  /* GTM_TIM5_IN5_3 input func */
  {22U, 2U},
  /* GTM_TIM2_IN5_7 input func */
  {22U, 3U},
  /* DSPI19_DSPI19_SINC input func */
  {22U, 4U},
  /* DSPI9_DSPI9_SCK input func */
  {22U, 8U},
  /* GTM_TOUT114 input func */
  {22U, 6U},
  /* DSPI19_DSPI19_SOUT input func */
  {22U, 9U},
  /* INMUX settings for pad PORT23:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN7_2 input func */
  {23U, 1U},
  /* GTM_TIM2_IN7_7 input func */
  {23U, 2U},
  /* DSPI19_DSPI19_SCKC input func */
  {23U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR8F input func */
  {23U, 4U},
  /* LINFLEX9_LIN9_RX input func */
  {23U, 5U},
  /* DSPI9_DSPI9_SINB input func */
  {23U, 6U},
  /* GTM_TOUT115 input func */
  {23U, 7U},
  /* LINFLEX9_LIN9_TX input func */
  {23U, 8U},
  /* DSPI9_DSPI9_SOUT input func */
  {23U, 9U},
  /* INMUX settings for pad PORT24:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN4_2 input func */
  {24U, 1U},
  /* GTM_TIM5_IN0_10 input func */
  {24U, 2U},
  /* GTM_TIM4_IN4_2 input func */
  {24U, 3U},
  /* M_CAN_1_CAN00_RXDF input func */
  {24U, 4U},
  /* FLEXRAY1_ERAY1_RXDB1 input func */
  {24U, 5U},
  /* SENT_SENT_SENT17B input func */
  {24U, 7U},
  /* LINFLEX0_LIN0_RX input func */
  {24U, 8U},
  /* DSPI10_DSPI10_SINC input func */
  {24U, 9U},
  /* M_CAN_9_CAN20_RXDE input func */
  {24U, 10U},
  /* LINFLEX7_LIN7_RX input func */
  {24U, 11U},
  /* DSPI7_DSPI7_SINB input func */
  {24U, 12U},
  /* GTM_TOUT162 input func */
  {24U, 13U},
  /* ACMP4_EVADC_FC4BFLOUT input func */
  {24U, 14U},
  /* INMUX settings for pad PORT25:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN2_1 input func */
  {25U, 1U},
  /* GTM_TIM5_IN1_11 input func */
  {25U, 2U},
  /* GTM_TIM4_IN2_1 input func */
  {25U, 3U},
  /* SENT_SENT_SENT16B input func */
  {25U, 5U},
  /* GTM_TOUT160 input func */
  {25U, 6U},
  /* LINFLEX7_LIN7_TX input func */
  {25U, 7U},
  /* DSPI7_DSPI7_SOUT input func */
  {25U, 8U},
  /* ACMP5_EVADC_FC5BFLOUT input func */
  {25U, 10U},
  /* INMUX settings for pad PORT26:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN5_2 input func */
  {26U, 1U},
  /* GTM_TIM5_IN2_9 input func */
  {26U, 2U},
  /* GTM_TIM4_IN5_3 input func */
  {26U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR9F input func */
  {26U, 4U},
  /* SENT_SENT_SENT18B input func */
  {26U, 5U},
  /* GTM_DTMT4_0 input func */
  {26U, 6U},
  /* GTM_DTMA6_1 input func */
  {26U, 7U},
  /* GTM_DTMT3_2 input func */
  {26U, 8U},
  /* DSPI7_DSPI7_SCK input func */
  {26U, 11U},
  /* GTM_TOUT163 input func */
  {26U, 9U},
  /* ACMP6_EVADC_FC6BFLOUT input func */
  {26U, 12U},
  /* INMUX settings for pad PORT27:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN7_3 input func */
  {27U, 1U},
  /* GTM_TIM5_IN3_11 input func */
  {27U, 2U},
  /* GTM_TIM4_IN7_2 input func */
  {27U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR9E input func */
  {27U, 4U},
  /* SENT_SENT_SENT19B input func */
  {27U, 5U},
  /* GTM_DTMT4_1 input func */
  {27U, 6U},
  /* GTM_DTMA5_1 input func */
  {27U, 7U},
  /* GTM_DTMA6_2 input func */
  {27U, 8U},
  /* DSPI7_DSPI7_PCS0 input func */
  {27U, 11U},
  /* GTM_TOUT165 input func */
  {27U, 9U},
  /* DSPI7_DSPI7_PCS0 input func */
  {27U, 11U},
  /* ACMP7_EVADC_FC7BFLOUT input func */
  {27U, 12U},
  /* INMUX settings for pad PORT28:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN0_3 input func */
  {28U, 1U},
  /* GTM_TIM5_IN0_2 input func */
  {28U, 2U},
  /* GTM_TIM4_IN0_2 input func */
  {28U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR10F input func */
  {28U, 5U},
  /* GTM_TOUT158 input func */
  {28U, 6U},
  /* LINFLEX7_LIN7_TX input func */
  {28U, 7U},
  /* DSPI7_DSPI7_SOUT input func */
  {28U, 8U},
  /* FLEXRAY1_ERAY1_TXDA input func */
  {28U, 9U},
  /* INMUX settings for pad PORT29:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN1_3 input func */
  {29U, 1U},
  /* GTM_TIM5_IN3_1 input func */
  {29U, 2U},
  /* GTM_TIM4_IN3_1 input func */
  {29U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR10E input func */
  {29U, 5U},
  /* GTM_TOUT161 input func */
  {29U, 6U},
  /* LINFLEX0_LIN0_TX input func */
  {29U, 7U},
  /* DSPI10_DSPI10_SOUT input func */
  {29U, 8U},
  /* M_CAN_1_CAN00_TXD input func */
  {29U, 9U},
  /* M_CAN_9_CAN20_TXD input func */
  {29U, 10U},
  /* FLEXRAY1_ERAY1_TXDB input func */
  {29U, 11U},
  /* INMUX settings for pad PORT30:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN2_3 input func */
  {30U, 1U},
  /* GTM_TIM5_IN6_3 input func */
  {30U, 2U},
  /* GTM_TIM4_IN6_3 input func */
  {30U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR11F input func */
  {30U, 5U},
  /* GTM_TOUT164 input func */
  {30U, 6U},
  /* FLEXRAY1_ERAY1_TXENA input func */
  {30U, 7U},
  /* INMUX settings for pad PORT31:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN3_3 input func */
  {31U, 1U},
  /* GTM_TIM5_IN6_1 input func */
  {31U, 2U},
  /* GTM_TIM4_IN6_1 input func */
  {31U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR11E input func */
  {31U, 6U},
  /* GTM_TOUT157 input func */
  {31U, 7U},
  /* INMUX settings for pad PORT32:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN0_2 input func */
  {32U, 1U},
  /* GTM_TIM0_IN0_2 input func */
  {32U, 2U},
  /* EMIOS_EMIOS_6 input func */
  {32U, 3U},
  /* LINFLEX2_LIN2_RX input func */
  {32U, 4U},
  /* DSPI2_DSPI2_SING input func */
  {32U, 5U},
  /* EMIOS_EMIOS_0 input func */
  {32U, 6U},
  /* GTM_DTMA0_0 input func */
  {32U, 8U},
  /* GTM_TOUT0 input func */
  {32U, 9U},
  /* LINFLEX2_LIN2_TX input func */
  {32U, 10U},
  /* DSPI2_DSPI2_SOUT input func */
  {32U, 11U},
  /* DSPI19_DSPI19_PCS1 input func */
  {32U, 12U},
  /* M_CAN_1_CAN00_TXD input func */
  {32U, 14U},
  /* FLEXRAY0_ERAY0_TXDA input func */
  {32U, 15U},
  /* EMIOS_EMIOS_0 input func */
  {32U, 0U},
  /* INMUX settings for pad PORT33:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN1_2 input func */
  {33U, 1U},
  /* GTM_TIM0_IN1_2 input func */
  {33U, 2U},
  /* FLEXRAY0_ERAY0_RXDA2 input func */
  {33U, 3U},
  /* LINFLEX2_LIN2_RX input func */
  {33U, 4U},
  /* DSPI2_DSPI2_SINB input func */
  {33U, 5U},
  /* M_CAN_1_CAN00_RXDA input func */
  {33U, 6U},
  /* GTM_TOUT1 input func */
  {33U, 8U},
  /* DSPI20_DSPI20_PCS7 input func */
  {33U, 9U},
  /* DSPI19_DSPI19_PCS2 input func */
  {33U, 10U},
  /* EMIOS_EMIOS_1 input func */
  {33U, 12U},
  /* INMUX settings for pad PORT34:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN2_2 input func */
  {34U, 1U},
  /* GTM_TIM0_IN2_2 input func */
  {34U, 2U},
  /* EMIOS_EMIOS_7 input func */
  {34U, 3U},
  /* EMIOS_EMIOS_1 input func */
  {34U, 4U},
  /* SENT_SENT_SENT14B input func */
  {34U, 5U},
  /* GTM_TOUT2 input func */
  {34U, 6U},
  /* LINFLEX1_LIN1_TX input func */
  {34U, 7U},
  /* DSPI1_DSPI1_SOUT input func */
  {34U, 8U},
  /* DSPI19_DSPI19_PCS3 input func */
  {34U, 9U},
  /* PSI5_PSI5_TX0 input func */
  {34U, 10U},
  /* M_CAN_3_CAN02_TXD input func */
  {34U, 11U},
  /* FLEXRAY0_ERAY0_TXDB input func */
  {34U, 12U},
  /* EMIOS_EMIOS_2 input func */
  {34U, 13U},
  /* INMUX settings for pad PORT35:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN3_2 input func */
  {35U, 1U},
  /* GTM_TIM0_IN3_2 input func */
  {35U, 2U},
  /* FLEXRAY0_ERAY0_RXDB2 input func */
  {35U, 4U},
  /* M_CAN_3_CAN02_RXDB input func */
  {35U, 5U},
  /* LINFLEX1_LIN1_RX input func */
  {35U, 6U},
  /* DSPI1_DSPI1_SING input func */
  {35U, 7U},
  /* DSPI13_DSPI13_SIN input func */
  {35U, 8U},
  /* PSI5_PSI5_RX0B input func */
  {35U, 9U},
  /* SENT_SENT_SENT13B input func */
  {35U, 10U},
  /* DSPI2_DSPI2_PCS0 input func */
  {35U, 13U},
  /* GTM_TOUT3 input func */
  {35U, 11U},
  /* DSPI2_DSPI2_PCS0 input func */
  {35U, 13U},
  /* DSPI19_DSPI19_PCS4 input func */
  {35U, 14U},
  /* EMIOS_EMIOS_3 input func */
  {35U, 0U},
  /* INMUX settings for pad PORT36:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN4_1 input func */
  {36U, 1U},
  /* GTM_TIM0_IN4_1 input func */
  {36U, 2U},
  /* EMIOS_EMIOS_16 input func */
  {36U, 3U},
  /* DSPI19_DSPI19_PCSA input func */
  {36U, 5U},
  /* EMIOS_EMIOS_2 input func */
  {36U, 6U},
  /* I2C0_I2C0_SDAA input func */
  {36U, 7U},
  /* M_CAN_6_CAN11_RXDA input func */
  {36U, 8U},
  /* TTCAN0_CAN0_ECTT1 input func */
  {36U, 9U},
  /* SENT_SENT_SENT12B input func */
  {36U, 10U},
  /* DSPI2_DSPI2_SCK input func */
  {36U, 13U},
  /* GTM_TOUT4 input func */
  {36U, 11U},
  /* DSPI19_DSPI19_PCS0 input func */
  {36U, 14U},
  /* PSI5S_PSI5S_CLK input func */
  {36U, 15U},
  /* FLEXRAY0_ERAY0_TXENA input func */
  {36U, 1U},
  /* EMIOS_EMIOS_4 input func */
  {36U, 2U},
  /* INMUX settings for pad PORT37:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN5_1 input func */
  {37U, 1U},
  /* GTM_TIM0_IN5_1 input func */
  {37U, 2U},
  /* I2C0_I2C0_SCLA input func */
  {37U, 4U},
  /* PSI5_PSI5_RX1B input func */
  {37U, 5U},
  /* PSI5S_PSI5S_RXB input func */
  {37U, 6U},
  /* DSPI19_DSPI19_SINA input func */
  {37U, 7U},
  /* SENT_SENT_SENT3C input func */
  {37U, 8U},
  /* TTCAN0_CAN0_ECTT2 input func */
  {37U, 9U},
  /* GTM_TOUT5 input func */
  {37U, 10U},
  /* M_CAN_6_CAN11_TXD input func */
  {37U, 11U},
  /* DSPI19_DSPI19_SOUT input func */
  {37U, 12U},
  /* FLEXRAY0_ERAY0_TXENB input func */
  {37U, 15U},
  /* EMIOS_EMIOS_5 input func */
  {37U, 0U},
  /* INMUX settings for pad PORT38:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN0_10 input func */
  {38U, 1U},
  /* GTM_TIM1_IN6_1 input func */
  {38U, 2U},
  /* GTM_TIM0_IN6_1 input func */
  {38U, 3U},
  /* EMIOS_EMIOS_0 input func */
  {38U, 4U},
  /* SENT_SENT_SENT2C input func */
  {38U, 5U},
  /* SAR_ADC_SDADC_EDSADC_ITR5E input func */
  {38U, 7U},
  /* EMIOS_EMIOS_21 input func */
  {38U, 8U},
  /* EMIOS_EMIOS_3 input func */
  {38U, 9U},
  /* DSPI19_DSPI19_SINA input func */
  {38U, 11U},
  /* GTM_TOUT6 input func */
  {38U, 13U},
  /* PSI5S_PSI5S_TX input func */
  {38U, 14U},
  /* DSPI19_DSPI19_SOUT input func */
  {38U, 15U},
  /* PSI5_PSI5_TX1 input func */
  {38U, 0U},
  /* EMIOS_EMIOS_0 input func */
  {38U, 2U},
  /* INMUX settings for pad PORT39:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN1_10 input func */
  {39U, 1U},
  /* GTM_TIM1_IN7_1 input func */
  {39U, 2U},
  /* GTM_TIM0_IN7_1 input func */
  {39U, 3U},
  /* EMIOS_EMIOS_1 input func */
  {39U, 4U},
  /* SENT_SENT_SENT1C input func */
  {39U, 5U},
  /* SAR_ADC_SDADC_EDSADC_ITR4E input func */
  {39U, 7U},
  /* PSI5_PSI5_RX2B input func */
  {39U, 9U},
  /* EMIOS_EMIOS_4 input func */
  {39U, 10U},
  /* DSPI19_DSPI19_SCKA input func */
  {39U, 11U},
  /* GTM_TOUT7 input func */
  {39U, 13U},
  /* SENT_SENT_SPC1 input func */
  {39U, 5U},
  /* EMIOS_EMIOS_2 input func */
  {39U, 2U},
  /* INMUX settings for pad PORT40:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN2_10 input func */
  {40U, 1U},
  /* GTM_TIM3_IN0_2 input func */
  {40U, 2U},
  /* GTM_TIM2_IN0_2 input func */
  {40U, 3U},
  /* EMIOS_EMIOS_2 input func */
  {40U, 4U},
  /* SENT_SENT_SENT0C input func */
  {40U, 5U},
  /* EMIOS_EMIOS_5 input func */
  {40U, 6U},
  /* SAR_ADC_SDADC_EDSADC_ITR3E input func */
  {40U, 8U},
  /* EMIOS_EMIOS_22 input func */
  {40U, 9U},
  /* GTM_DTMA0_1 input func */
  {40U, 12U},
  /* DSPI8_DSPI8_SCK input func */
  {40U, 0U},
  /* GTM_TOUT8 input func */
  {40U, 13U},
  /* DSPI19_DSPI19_PCS5 input func */
  {40U, 14U},
  /* PSI5_PSI5_TX2 input func */
  {40U, 1U},
  /* GMAC_GETH_MDC input func */
  {40U, 3U},
  /* EMIOS_EMIOS_4 input func */
  {40U, 4U},
  /* INMUX settings for pad PORT41:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN2_2 input func */
  {41U, 1U},
  /* GTM_TIM3_IN3_10 input func */
  {41U, 2U},
  /* GTM_TIM0_IN2_10 input func */
  {41U, 3U},
  /* SENT_SENT_SENT20B input func */
  {41U, 4U},
  /* LINFLEX8_LIN8_RX input func */
  {41U, 5U},
  /* DSPI8_DSPI8_SINA input func */
  {41U, 6U},
  /* GTM_TOUT116 input func */
  {41U, 7U},
  /* LINFLEX2_LIN2_TX input func */
  {41U, 8U},
  /* DSPI2_DSPI2_SOUT input func */
  {41U, 9U},
  /* LINFLEX8_LIN8_TX input func */
  {41U, 10U},
  /* DSPI8_DSPI8_SOUT input func */
  {41U, 11U},
  /* M_CAN_2_CAN01_TXD input func */
  {41U, 12U},
  /* INMUX settings for pad PORT42:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN3_2 input func */
  {42U, 1U},
  /* GTM_TIM3_IN4_11 input func */
  {42U, 2U},
  /* GTM_TIM0_IN3_10 input func */
  {42U, 3U},
  /* LINFLEX2_LIN2_RX input func */
  {42U, 4U},
  /* DSPI2_DSPI2_SINC input func */
  {42U, 5U},
  /* M_CAN_2_CAN01_RXDE input func */
  {42U, 6U},
  /* SENT_SENT_SENT21B input func */
  {42U, 7U},
  /* LINFLEX8_LIN8_RX input func */
  {42U, 8U},
  /* DSPI8_DSPI8_SINB input func */
  {42U, 9U},
  /* GTM_TOUT117 input func */
  {42U, 10U},
  /* INMUX settings for pad PORT43:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN4_3 input func */
  {43U, 1U},
  /* GTM_TIM3_IN5_12 input func */
  {43U, 2U},
  /* GTM_TIM0_IN7_7 input func */
  {43U, 3U},
  /* SENT_SENT_SENT22B input func */
  {43U, 4U},
  /* DSPI8_DSPI8_PCS0 input func */
  {43U, 7U},
  /* GTM_TOUT118 input func */
  {43U, 5U},
  /* DSPI8_DSPI8_PCS0 input func */
  {43U, 7U},
  /* INMUX settings for pad PORT44:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN0_3 input func */
  {44U, 1U},
  /* GTM_TIM4_IN0_3 input func */
  {44U, 2U},
  /* GTM_TIM3_IN6_12 input func */
  {44U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR12F input func */
  {44U, 5U},
  /* SENT_SENT_SENT23B input func */
  {44U, 6U},
  /* DSPI6_DSPI6_PCS0 input func */
  {44U, 11U},
  /* GTM_TOUT151 input func */
  {44U, 7U},
  /* DSPI19_DSPI19_PCS5 input func */
  {44U, 8U},
  /* DSPI20_DSPI20_PCS4 input func */
  {44U, 9U},
  /* DSPI6_DSPI6_PCS0 input func */
  {44U, 11U},
  /* INMUX settings for pad PORT45:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN2_2 input func */
  {45U, 1U},
  /* GTM_TIM4_IN2_3 input func */
  {45U, 2U},
  /* GTM_TIM3_IN7_11 input func */
  {45U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR12E input func */
  {45U, 5U},
  /* SENT_SENT_SENT24B input func */
  {45U, 6U},
  /* GTM_TOUT153 input func */
  {45U, 7U},
  /* DSPI19_DSPI19_PCS7 input func */
  {45U, 8U},
  /* DSPI20_DSPI20_PCS6 input func */
  {45U, 9U},
  /* M_CAN_1_CAN00_TXD input func */
  {45U, 10U},
  /* M_CAN_9_CAN20_TXD input func */
  {45U, 11U},
  /* INMUX settings for pad PORT46:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN3_3 input func */
  {46U, 1U},
  /* GTM_TIM4_IN3_3 input func */
  {46U, 2U},
  /* GTM_TIM2_IN4_14 input func */
  {46U, 3U},
  /* M_CAN_9_CAN20_RXDD input func */
  {46U, 4U},
  /* M_CAN_1_CAN00_RXDH input func */
  {46U, 5U},
  /* SAR_ADC_SDADC_EDSADC_ITR13F input func */
  {46U, 7U},
  /* DSPI6_DSPI6_SCK input func */
  {46U, 10U},
  /* GTM_TOUT154 input func */
  {46U, 8U},
  /* INMUX settings for pad PORT47:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN1_3 input func */
  {47U, 1U},
  /* GTM_TIM4_IN1_3 input func */
  {47U, 2U},
  /* GTM_TIM2_IN5_14 input func */
  {47U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR13E input func */
  {47U, 5U},
  /* GTM_TOUT152 input func */
  {47U, 6U},
  /* DSPI19_DSPI19_PCS6 input func */
  {47U, 7U},
  /* DSPI20_DSPI20_PCS5 input func */
  {47U, 8U},
  /* LINFLEX6_LIN6_TX input func */
  {47U, 9U},
  /* DSPI6_DSPI6_SOUT input func */
  {47U, 10U},
  /* FLEXRAY1_ERAY1_TXENB input func */
  {47U, 11U},
  /* INMUX settings for pad PORT48:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN0_12 input func */
  {48U, 1U},
  /* GTM_TIM1_IN4_2 input func */
  {48U, 2U},
  /* GTM_TIM0_IN4_2 input func */
  {48U, 3U},
  /* LINFLEX11_LIN11_RX input func */
  {48U, 5U},
  /* DSPI12_DSPI12_SINA input func */
  {48U, 6U},
  /* GMAC_GETH_RXERC input func */
  {48U, 7U},
  /* GTM_DTMA5_2 input func */
  {48U, 8U},
  /* GTM_TOUT102 input func */
  {48U, 9U},
  /* LINFLEX11_LIN11_TX input func */
  {48U, 10U},
  /* DSPI12_DSPI12_SOUT input func */
  {48U, 11U},
  /* ACMP6_EVADC_FC6BFLOUT input func */
  {48U, 13U},
  /* INMUX settings for pad PORT49:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN4_12 input func */
  {49U, 1U},
  /* GTM_TIM1_IN1_3 input func */
  {49U, 2U},
  /* GTM_TIM0_IN1_3 input func */
  {49U, 3U},
  /* DSPI17_DSPI17_SINA input func */
  {49U, 5U},
  /* GTM_DTMT0_1 input func */
  {49U, 6U},
  /* GTM_TOUT103 input func */
  {49U, 7U},
  /* DSPI17_DSPI17_SOUT input func */
  {49U, 8U},
  /* DSPI11_DSPI11_PCS1 input func */
  {49U, 10U},
  /* ACMP1_EVADC_FC1BFLOUT input func */
  {49U, 11U},
  /* INMUX settings for pad PORT50:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN5_12 input func */
  {50U, 1U},
  /* GTM_TIM1_IN2_3 input func */
  {50U, 2U},
  /* GTM_TIM0_IN2_3 input func */
  {50U, 3U},
  /* M_CAN_3_CAN02_RXDE input func */
  {50U, 4U},
  /* DSPI11_DSPI11_SIN input func */
  {50U, 5U},
  /* DSPI17_DSPI17_SCKA input func */
  {50U, 6U},
  /* EMIOS_EMIOS_24 input func */
  {50U, 7U},
  /* GTM_DTMT2_2 input func */
  {50U, 9U},
  /* GTM_TOUT104 input func */
  {50U, 10U},
  /* DSPI11_DSPI11_PCS0 input func */
  {50U, 12U},
  /* ACMP3_EVADC_FC3BFLOUT input func */
  {50U, 13U},
  /* INMUX settings for pad PORT51:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN6_10 input func */
  {51U, 1U},
  /* GTM_TIM1_IN3_3 input func */
  {51U, 2U},
  /* GTM_TIM0_IN3_3 input func */
  {51U, 3U},
  /* DSPI17_DSPI17_SINA input func */
  {51U, 4U},
  /* EMIOS_EMIOS_23 input func */
  {51U, 6U},
  /* GTM_TOUT105 input func */
  {51U, 7U},
  /* DSPI17_DSPI17_SOUT input func */
  {51U, 8U},
  /* DSPI11_DSPI11_PCS0 input func */
  {51U, 9U},
  /* M_CAN_3_CAN02_TXD input func */
  {51U, 10U},
  /* INMUX settings for pad PORT52:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN7_3 input func */
  {52U, 1U},
  /* GTM_TIM1_IN6_2 input func */
  {52U, 2U},
  /* GTM_TIM0_IN6_2 input func */
  {52U, 3U},
  /* DSPI17_DSPI17_SINC input func */
  {52U, 4U},
  /* EMIOS_EMIOS_3 input func */
  {52U, 5U},
  /* EMIOS_EMIOS_21 input func */
  {52U, 6U},
  /* LINFLEX11_LIN11_RX input func */
  {52U, 7U},
  /* DSPI12_DSPI12_SINB input func */
  {52U, 8U},
  /* GTM_TOUT106 input func */
  {52U, 9U},
  /* DSPI17_DSPI17_SOUT input func */
  {52U, 11U},
  /* DSPI11_DSPI11_PCS0 input func */
  {52U, 12U},
  /* INMUX settings for pad PORT53:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN3_13 input func */
  {53U, 1U},
  /* GTM_TIM1_IN2_4 input func */
  {53U, 2U},
  /* GTM_TIM0_IN2_4 input func */
  {53U, 3U},
  /* M_CAN_9_CAN20_RXDA input func */
  {53U, 5U},
  /* DSPI2_DSPI2_PCS0 input func */
  {53U, 14U},
  /* GTM_TOUT107 input func */
  {53U, 7U},
  /* LINFLEX2_LIN2_TX input func */
  {53U, 8U},
  /* DSPI2_DSPI2_SOUT input func */
  {53U, 9U},
  /* EMIOS_EMIOS_23 input func */
  {53U, 12U},
  /* DSPI2_DSPI2_PCS0 input func */
  {53U, 14U},
  /* PSI5_PSI5_TX3 input func */
  {53U, 15U},
  /* INMUX settings for pad PORT54:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN2_13 input func */
  {54U, 1U},
  /* GTM_TIM1_IN3_4 input func */
  {54U, 2U},
  /* GTM_TIM0_IN3_4 input func */
  {54U, 3U},
  /* PSI5_PSI5_RX3C input func */
  {54U, 4U},
  /* LINFLEX2_LIN2_RX input func */
  {54U, 5U},
  /* DSPI2_DSPI2_SIND input func */
  {54U, 6U},
  /* DSPI19_DSPI19_SINB input func */
  {54U, 7U},
  /* DSPI2_DSPI2_SCK input func */
  {54U, 11U},
  /* GTM_TOUT108 input func */
  {54U, 9U},
  /* DSPI19_DSPI19_SOUT input func */
  {54U, 12U},
  /* EMIOS_EMIOS_22 input func */
  {54U, 13U},
  /* M_CAN_9_CAN20_TXD input func */
  {54U, 14U},
  /* DSPI17_DSPI17_SOUT input func */
  {54U, 15U},
  /* ACMP7_EVADC_FC7BFLOUT input func */
  {54U, 0U},
  /* INMUX settings for pad PORT55:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN0_3 input func */
  {55U, 1U},
  /* GTM_TIM0_IN0_3 input func */
  {55U, 2U},
  /* DSPI19_DSPI19_SINB input func */
  {55U, 5U},
  /* EMIOS_EMIOS_4 input func */
  {55U, 7U},
  /* GTM_TOUT109 input func */
  {55U, 8U},
  /* DSPI19_DSPI19_SOUT input func */
  {55U, 9U},
  /* M_CAN_9_CAN20_TXD input func */
  {55U, 10U},
  /* M_CAN_7_CAN12_TXD input func */
  {55U, 11U},
  /* INMUX settings for pad PORT56:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN0_13 input func */
  {56U, 1U},
  /* GTM_TIM1_IN5_2 input func */
  {56U, 2U},
  /* GTM_TIM0_IN5_2 input func */
  {56U, 3U},
  /* M_CAN_7_CAN12_RXDB input func */
  {56U, 4U},
  /* EMIOS_EMIOS_22 input func */
  {56U, 5U},
  /* DSPI19_DSPI19_SCKB input func */
  {56U, 6U},
  /* EMIOS_EMIOS_5 input func */
  {56U, 8U},
  /* M_CAN_9_CAN20_RXDB input func */
  {56U, 9U},
  /* GTM_TOUT110 input func */
  {56U, 11U},
  /* INMUX settings for pad PORT57:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN0_5 input func */
  {57U, 1U},
  /* GTM_TIM4_IN1_4 input func */
  {57U, 2U},
  /* GTM_TIM0_IN1_10 input func */
  {57U, 3U},
  /* SENT_SENT_SENT15C input func */
  {57U, 4U},
  /* LINFLEX6_LIN6_RX input func */
  {57U, 5U},
  /* DSPI6_DSPI6_SIND input func */
  {57U, 6U},
  /* GTM_TOUT265 input func */
  {57U, 7U},
  /* INMUX settings for pad PORT58:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN1_5 input func */
  {58U, 1U},
  /* GTM_TIM4_IN2_4 input func */
  {58U, 2U},
  /* GTM_TIM0_IN2_11 input func */
  {58U, 3U},
  /* SENT_SENT_SENT16C input func */
  {58U, 4U},
  /* GTM_TOUT266 input func */
  {58U, 5U},
  /* LINFLEX6_LIN6_TX input func */
  {58U, 6U},
  /* DSPI6_DSPI6_SOUT input func */
  {58U, 7U},
  /* INMUX settings for pad PORT59:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN2_5 input func */
  {59U, 1U},
  /* GTM_TIM4_IN5_4 input func */
  {59U, 2U},
  /* GTM_TIM0_IN5_9 input func */
  {59U, 3U},
  /* SENT_SENT_SENT19C input func */
  {59U, 4U},
  /* DSPI6_DSPI6_SCK input func */
  {59U, 7U},
  /* GTM_TOUT269 input func */
  {59U, 5U},
  /* INMUX settings for pad PORT60:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN3_5 input func */
  {60U, 1U},
  /* GTM_TIM4_IN4_4 input func */
  {60U, 2U},
  /* GTM_TIM0_IN4_9 input func */
  {60U, 3U},
  /* SENT_SENT_SENT18C input func */
  {60U, 4U},
  /* DSPI6_DSPI6_PCS0 input func */
  {60U, 7U},
  /* GTM_TOUT268 input func */
  {60U, 5U},
  /* DSPI6_DSPI6_PCS0 input func */
  {60U, 7U},
  /* INMUX settings for pad PORT61:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN0_4 input func */
  {61U, 1U},
  /* GTM_TIM4_IN3_4 input func */
  {61U, 2U},
  /* GTM_TIM0_IN3_11 input func */
  {61U, 3U},
  /* SENT_SENT_SENT17C input func */
  {61U, 4U},
  /* GTM_TOUT267 input func */
  {61U, 5U},
  /* INMUX settings for pad PORT62:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN1_4 input func */
  {62U, 1U},
  /* GTM_TIM4_IN6_4 input func */
  {62U, 2U},
  /* GTM_TIM0_IN6_9 input func */
  {62U, 3U},
  /* GTM_TOUT270 input func */
  {62U, 4U},
  /* INMUX settings for pad PORT63:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN5_1 input func */
  {63U, 1U},
  /* GTM_TIM4_IN0_4 input func */
  {63U, 2U},
  /* GTM_TIM2_IN0_7 input func */
  {63U, 3U},
  /* LINFLEX3_LIN3_RX input func */
  {63U, 4U},
  /* DSPI3_DSPI3_SINB input func */
  {63U, 5U},
  /* GTM_DTMA2_1 input func */
  {63U, 6U},
  /* GTM_TOUT119 input func */
  {63U, 7U},
  /* LINFLEX3_LIN3_TX input func */
  {63U, 8U},
  /* DSPI3_DSPI3_SOUT input func */
  {63U, 9U},
  /* M_CAN_6_CAN11_TXD input func */
  {63U, 10U},
  /* GMAC_GETH_TXD3 input func */
  {63U, 11U},
  /* INMUX settings for pad PORT64:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN6_1 input func */
  {64U, 1U},
  /* GTM_TIM4_IN1_5 input func */
  {64U, 2U},
  /* GTM_TIM2_IN1_6 input func */
  {64U, 3U},
  /* DSPI3_DSPI3_SCK input func */
  {64U, 6U},
  /* GTM_TOUT120 input func */
  {64U, 4U},
  /* LINFLEX3_LIN3_TX input func */
  {64U, 7U},
  /* DSPI3_DSPI3_SOUT input func */
  {64U, 8U},
  /* M_CAN_7_CAN12_TXD input func */
  {64U, 9U},
  /* GMAC_GETH_TXD2 input func */
  {64U, 10U},
  /* INMUX settings for pad PORT65:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN1_3 input func */
  {65U, 1U},
  /* GTM_TIM2_IN1_3 input func */
  {65U, 2U},
  /* GTM_TOUT95 input func */
  {65U, 3U},
  /* DSPI16_DSPI16_PCS5 input func */
  {65U, 4U},
  /* DSPI17_DSPI17_PCS5 input func */
  {65U, 5U},
  /* DSPI11_DSPI11_PCS1 input func */
  {65U, 6U},
  /* GMAC_GETH_TXD1 input func */
  {65U, 7U},
  /* EMIOS_EMIOS_20 input func */
  {65U, 8U},
  /* INMUX settings for pad PORT66:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN2_2 input func */
  {66U, 1U},
  /* GTM_TIM2_IN2_2 input func */
  {66U, 2U},
  /* DSPI11_DSPI11_SIN input func */
  {66U, 3U},
  /* DSPI17_DSPI17_SINB input func */
  {66U, 4U},
  /* GTM_TOUT96 input func */
  {66U, 5U},
  /* DSPI17_DSPI17_SOUT input func */
  {66U, 6U},
  /* FLEXRAY0_ERAY0_TXDA input func */
  {66U, 7U},
  /* GMAC_GETH_TXD0 input func */
  {66U, 8U},
  /* EMIOS_EMIOS_5 input func */
  {66U, 9U},
  /* INMUX settings for pad PORT67:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN7_1 input func */
  {67U, 1U},
  /* GTM_TIM4_IN2_5 input func */
  {67U, 2U},
  /* GTM_TIM2_IN2_6 input func */
  {67U, 3U},
  /* GMAC_GETH_RXCLKB input func */
  {67U, 4U},
  /* DSPI3_DSPI3_SCK input func */
  {67U, 7U},
  /* GTM_TOUT121 input func */
  {67U, 5U},
  /* M_CAN_8_CAN13_TXD input func */
  {67U, 8U},
  /* GMAC_GETH_TXER input func */
  {67U, 9U},
  /* GMAC_GETH_TXCLK input func */
  {67U, 10U},
  /* SSI0_SSI0_SCK input func */
  {67U, 11U},
  /* INMUX settings for pad PORT68:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN3_5 input func */
  {68U, 1U},
  /* GTM_TIM2_IN3_8 input func */
  {68U, 2U},
  /* GMAC_GETH_TXCLKA input func */
  {68U, 3U},
  /* GMAC_GETH_GREFCLK input func */
  {68U, 4U},
  /* GTM_TOUT122 input func */
  {68U, 5U},
  /* M_CAN_9_CAN20_TXD input func */
  {68U, 6U},
  /*  SSI0_SSI0_CS input func */
  {68U, 7U},
  /* INMUX settings for pad PORT69:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN3_2 input func */
  {69U, 1U},
  /* GTM_TIM2_IN3_2 input func */
  {69U, 2U},
  /* DSPI17_DSPI17_SCKB input func */
  {69U, 3U},
  /*  SSI0_SSI0_DATA0 input func */
  {69U, 12U},
  /* GTM_TOUT97 input func */
  {69U, 4U},
  /* FLEXRAY0_ERAY0_TXENB input func */
  {69U, 5U},
  /* FLEXRAY0_ERAY0_TXENA input func */
  {69U, 7U},
  /* GMAC_GETH_TXEN input func */
  {69U, 9U},
  /* EMIOS_EMIOS_3 input func */
  {69U, 11U},
  /*  SSI0_SSI0_DATA0 input func */
  {69U, 12U},
  /* INMUX settings for pad PORT70:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN4_5 input func */
  {70U, 1U},
  /* GTM_TIM2_IN4_7 input func */
  {70U, 2U},
  /* GMAC_GETH_RXD3A input func */
  {70U, 3U},
  /* M_CAN_6_CAN11_RXDD input func */
  {70U, 4U},
  /*  SSI0_SSI0_DATA1 input func */
  {70U, 6U},
  /* GTM_TOUT123 input func */
  {70U, 5U},
  /*  SSI0_SSI0_DATA1 input func */
  {70U, 6U},
  /* INMUX settings for pad PORT71:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN5_5 input func */
  {71U, 1U},
  /* GTM_TIM2_IN5_8 input func */
  {71U, 2U},
  /* GMAC_GETH_RXD2A input func */
  {71U, 3U},
  /* M_CAN_7_CAN12_RXDD input func */
  {71U, 4U},
  /*  SSI0_SSI0_DATA2 input func */
  {71U, 6U},
  /* GTM_TOUT124 input func */
  {71U, 5U},
  /*  SSI0_SSI0_DATA2 input func */
  {71U, 6U},
  /* INMUX settings for pad PORT72:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN4_2 input func */
  {72U, 1U},
  /* GTM_TIM2_IN4_2 input func */
  {72U, 2U},
  /* DSPI17_DSPI17_SINB input func */
  {72U, 3U},
  /* FLEXRAY0_ERAY0_RXDA1 input func */
  {72U, 4U},
  /* GMAC_GETH_RXD1A input func */
  {72U, 5U},
  /*  SSI0_SSI0_DATA3 input func */
  {72U, 10U},
  /* GTM_TOUT98 input func */
  {72U, 6U},
  /* DSPI17_DSPI17_SOUT input func */
  {72U, 7U},
  /* EMIOS_EMIOS_1 input func */
  {72U, 9U},
  /*  SSI0_SSI0_DATA3 input func */
  {72U, 10U},
  /* INMUX settings for pad PORT73:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN5_2 input func */
  {73U, 1U},
  /* GTM_TIM2_IN5_2 input func */
  {73U, 2U},
  /* GTM_TIM2_IN0_9 input func */
  {73U, 3U},
  /* M_CAN_4_CAN03_RXDD input func */
  {73U, 4U},
  /* FLEXRAY0_ERAY0_RXDB1 input func */
  {73U, 5U},
  /* LINFLEX1_LIN1_RX input func */
  {73U, 6U},
  /* DSPI1_DSPI1_SINE input func */
  {73U, 7U},
  /* DSPI11_DSPI11_SIN input func */
  {73U, 9U},
  /* GMAC_GETH_RXD0A input func */
  {73U, 10U},
  /* DSPI17_DSPI17_PCSA input func */
  {73U, 11U},
  /* GTM_TOUT99 input func */
  {73U, 12U},
  /* DSPI16_DSPI16_PCS3 input func */
  {73U, 13U},
  /* DSPI17_DSPI17_PCS3 input func */
  {73U, 14U},
  /* EMIOS_EMIOS_4 input func */
  {73U, 15U},
  /* SSI1_SSI1_SCK input func */
  {73U, 0U},
  /* INMUX settings for pad PORT74:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN6_2 input func */
  {74U, 1U},
  /* GTM_TIM3_IN0_14 input func */
  {74U, 2U},
  /* GTM_TIM2_IN6_2 input func */
  {74U, 3U},
  /* GMAC_GETH_RXDVA input func */
  {74U, 5U},
  /* GMAC_GETH_CRSB input func */
  {74U, 6U},
  /* GTM_TOUT100 input func */
  {74U, 8U},
  /* DSPI16_DSPI16_PCS4 input func */
  {74U, 9U},
  /* DSPI17_DSPI17_PCS4 input func */
  {74U, 10U},
  /* DSPI11_DSPI11_PCS0 input func */
  {74U, 11U},
  /* FLEXRAY0_ERAY0_TXENB input func */
  {74U, 12U},
  /* EMIOS_EMIOS_2 input func */
  {74U, 13U},
  /* SSI1_SSI1_CS input func */
  {74U, 14U},
  /* INMUX settings for pad PORT75:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN7_2 input func */
  {75U, 1U},
  /* GTM_TIM2_IN7_2 input func */
  {75U, 2U},
  /* GMAC_GETH_REFCLKA input func */
  {75U, 3U},
  /* GMAC_GETH_TXCLKB input func */
  {75U, 4U},
  /* GMAC_GETH_RXCLKA input func */
  {75U, 5U},
  /*  SSI1_SSI1_DATA0 input func */
  {75U, 14U},
  /* GTM_TOUT101 input func */
  {75U, 6U},
  /* LINFLEX1_LIN1_TX input func */
  {75U, 7U},
  /* DSPI1_DSPI1_SOUT input func */
  {75U, 8U},
  /* GTM_CLK2 input func */
  {75U, 9U},
  /* FLEXRAY0_ERAY0_TXDB input func */
  {75U, 10U},
  /* M_CAN_4_CAN03_TXD input func */
  {75U, 11U},
  /* EMIOS_EMIOS_0 input func */
  {75U, 13U},
  /*  SSI1_SSI1_DATA0 input func */
  {75U, 14U},
  /* INMUX settings for pad PORT76:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN6_5 input func */
  {76U, 1U},
  /* GTM_TIM2_IN6_7 input func */
  {76U, 2U},
  /* GMAC_GETH_RXERA input func */
  {76U, 3U},
  /* I2C1_I2C1_SDAA input func */
  {76U, 4U},
  /* M_CAN_8_CAN13_RXDD input func */
  {76U, 5U},
  /*  SSI1_SSI1_DATA1 input func */
  {76U, 8U},
  /* GTM_TOUT125 input func */
  {76U, 6U},
  /*  SSI1_SSI1_DATA1 input func */
  {76U, 8U},
  /* INMUX settings for pad PORT77:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN7_4 input func */
  {77U, 1U},
  /* GTM_TIM2_IN7_8 input func */
  {77U, 2U},
  /* GMAC_GETH_RXDVB input func */
  {77U, 4U},
  /* GMAC_GETH_CRSA input func */
  {77U, 5U},
  /* I2C1_I2C1_SCLA input func */
  {77U, 6U},
  /* M_CAN_9_CAN20_RXDF input func */
  {77U, 7U},
  /*  SSI1_SSI1_DATA2 input func */
  {77U, 10U},
  /* GTM_TOUT126 input func */
  {77U, 8U},
  /*  SSI1_SSI1_DATA2 input func */
  {77U, 10U},
  /* INMUX settings for pad PORT78:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN7_5 input func */
  {78U, 1U},
  /* GTM_TIM0_IN7_8 input func */
  {78U, 2U},
  /* GMAC_GETH_COLA input func */
  {78U, 3U},
  /*  SSI1_SSI1_DATA3 input func */
  {78U, 5U},
  /* GTM_TOUT127 input func */
  {78U, 4U},
  /*  SSI1_SSI1_DATA3 input func */
  {78U, 5U},
  /* INMUX settings for pad PORT79:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN3_2 input func */
  {79U, 1U},
  /* GTM_TIM4_IN0_5 input func */
  {79U, 2U},
  /* GTM_TIM3_IN0_7 input func */
  {79U, 3U},
  /* M_CAN_1_CAN00_RXDC input func */
  {79U, 4U},
  /* GMAC_GETH_RXCLKC input func */
  {79U, 5U},
  /* GTM_DTMA4_0 input func */
  {79U, 6U},
  /* GTM_TOUT128 input func */
  {79U, 7U},
  /* GMAC_GETH_MDC input func */
  {79U, 8U},
  /* INMUX settings for pad PORT80:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN4_1 input func */
  {80U, 1U},
  /* GTM_TIM4_IN1_6 input func */
  {80U, 2U},
  /* GTM_TIM3_IN1_6 input func */
  {80U, 3U},
  /* GMAC_GETH_MDIOC input func */
  {80U, 4U},
  /* DSPI3_DSPI3_PCS0 input func */
  {80U, 7U},
  /* GTM_TOUT129 input func */
  {80U, 5U},
  /* DSPI3_DSPI3_PCS0 input func */
  {80U, 7U},
  /* M_CAN_1_CAN00_TXD input func */
  {80U, 8U},
  /* GMAC_GETH_MDIO input func */
  {80U, 4U},
  /* INMUX settings for pad PORT81:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN5_3 input func */
  {81U, 1U},
  /* GTM_TIM2_IN5_3 input func */
  {81U, 2U},
  /* LINFLEX10_LIN10_RX input func */
  {81U, 3U},
  /* DSPI0_DSPI0_SINC input func */
  {81U, 4U},
  /* GTM_TOUT91 input func */
  {81U, 5U},
  /* LINFLEX10_LIN10_TX input func */
  {81U, 6U},
  /* DSPI0_DSPI0_SOUT input func */
  {81U, 7U},
  /* DSPI11_DSPI11_PCS1 input func */
  {81U, 9U},
  /* M_CAN_5_CAN10_TXD input func */
  {81U, 11U},
  /* INMUX settings for pad PORT82:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN6_3 input func */
  {82U, 1U},
  /* GTM_TIM2_IN6_3 input func */
  {82U, 2U},
  /* I2C0_I2C0_SCLB input func */
  {82U, 3U},
  /* M_CAN_5_CAN10_RXDD input func */
  {82U, 4U},
  /* LINFLEX10_LIN10_RX input func */
  {82U, 5U},
  /* DSPI0_DSPI0_SIND input func */
  {82U, 6U},
  /* GTM_TOUT92 input func */
  {82U, 7U},
  /* INMUX settings for pad PORT83:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN7_3 input func */
  {83U, 1U},
  /* GTM_TIM2_IN7_3 input func */
  {83U, 2U},
  /* I2C0_I2C0_SDAB input func */
  {83U, 4U},
  /* DSPI0_DSPI0_SCK input func */
  {83U, 7U},
  /* GTM_TOUT93 input func */
  {83U, 5U},
  /* INMUX settings for pad PORT84:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN0_3 input func */
  {84U, 1U},
  /* GTM_TIM2_IN0_3 input func */
  {84U, 2U},
  /* DSPI0_DSPI0_PCS0 input func */
  {84U, 5U},
  /* GTM_TOUT94 input func */
  {84U, 3U},
  /* DSPI0_DSPI0_PCS0 input func */
  {84U, 5U},
  /* INMUX settings for pad PORT85:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN0_4 input func */
  {85U, 1U},
  /* GTM_TIM5_IN3_4 input func */
  {85U, 2U},
  /* GTM_TIM3_IN3_8 input func */
  {85U, 3U},
  /* GTM_TOUT253 input func */
  {85U, 4U},
  /* DSPI14_DSPI14_PCS0 input func */
  {85U, 5U},
  /* M_CAN_12_CAN23_TXD input func */
  {85U, 7U},
  /* INMUX settings for pad PORT86:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN1_4 input func */
  {86U, 1U},
  /* GTM_TIM5_IN4_4 input func */
  {86U, 2U},
  /* GTM_TIM3_IN4_9 input func */
  {86U, 3U},
  /* M_CAN_12_CAN23_RXDD input func */
  {86U, 4U},
  /* GTM_TOUT254 input func */
  {86U, 5U},
  /* INMUX settings for pad PORT87:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN2_4 input func */
  {87U, 1U},
  /* GTM_TIM5_IN5_4 input func */
  {87U, 2U},
  /* GTM_TIM3_IN5_10 input func */
  {87U, 3U},
  /* GTM_TOUT255 input func */
  {87U, 4U},
  /* INMUX settings for pad PORT88:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN3_4 input func */
  {88U, 1U},
  /* GTM_TIM5_IN6_4 input func */
  {88U, 2U},
  /* GTM_TIM3_IN6_10 input func */
  {88U, 3U},
  /* GTM_TOUT256 input func */
  {88U, 4U},
  /* INMUX settings for pad PORT89:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN4_4 input func */
  {89U, 1U},
  /* GTM_TIM4_IN7_6 input func */
  {89U, 2U},
  /* GTM_TIM2_IN7_12 input func */
  {89U, 3U},
  /* I2C1_I2C1_SCLB input func */
  {89U, 4U},
  /* GTM_TOUT248 input func */
  {89U, 5U},
  /* LINFLEX3_LIN3_TX input func */
  {89U, 6U},
  /* DSPI3_DSPI3_SOUT input func */
  {89U, 7U},
  /* DSPI21_DSPI21_PCS5 input func */
  {89U, 8U},
  /* M_CAN_10_CAN21_TXD input func */
  {89U, 9U},
  /* INMUX settings for pad PORT90:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN5_4 input func */
  {90U, 1U},
  /* GTM_TIM5_IN1_5 input func */
  {90U, 2U},
  /* GTM_TIM3_IN1_8 input func */
  {90U, 3U},
  /* PSI5_PSI5_RX3A input func */
  {90U, 4U},
  /* DSPI15_DSPI15_SIN input func */
  {90U, 5U},
  /* GTM_TOUT251 input func */
  {90U, 6U},
  /* LINFLEX0_LIN0_TX input func */
  {90U, 7U},
  /* DSPI10_DSPI10_SOUT input func */
  {90U, 8U},
  /* INMUX settings for pad PORT91:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN6_4 input func */
  {91U, 1U},
  /* GTM_TIM5_IN0_9 input func */
  {91U, 2U},
  /* GTM_TIM3_IN0_9 input func */
  {91U, 3U},
  /* LINFLEX0_LIN0_RX input func */
  {91U, 4U},
  /* DSPI10_DSPI10_SINE input func */
  {91U, 5U},
  /* LINFLEX7_LIN7_RX input func */
  {91U, 6U},
  /* DSPI7_DSPI7_SIND input func */
  {91U, 7U},
  /* GTM_TOUT250 input func */
  {91U, 9U},
  /* PSI5_PSI5_TX3 input func */
  {91U, 10U},
  /* INMUX settings for pad PORT92:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN7_4 input func */
  {92U, 1U},
  /* GTM_TIM4_IN0_6 input func */
  {92U, 2U},
  /* GTM_TIM0_IN0_11 input func */
  {92U, 3U},
  /* LINFLEX3_LIN3_RX input func */
  {92U, 4U},
  /* DSPI3_DSPI3_SINH input func */
  {92U, 5U},
  /* I2C1_I2C1_SDAB input func */
  {92U, 6U},
  /* M_CAN_10_CAN21_RXDB input func */
  {92U, 7U},
  /* GTM_TOUT249 input func */
  {92U, 8U},
  /* LINFLEX7_LIN7_TX input func */
  {92U, 9U},
  /* DSPI7_DSPI7_SOUT input func */
  {92U, 10U},
  /* INMUX settings for pad PORT93:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN0_3 input func */
  {93U, 1U},
  /* GTM_TIM5_IN5_5 input func */
  {93U, 2U},
  /* GTM_TIM3_IN5_9 input func */
  {93U, 3U},
  /* PSI5_PSI5_RX3B input func */
  {93U, 5U},
  /* DSPI7_DSPI7_SCK input func */
  {93U, 8U},
  /* GTM_TOUT262 input func */
  {93U, 6U},
  /* INMUX settings for pad PORT94:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN1_3 input func */
  {94U, 1U},
  /* GTM_TIM5_IN2_4 input func */
  {94U, 2U},
  /* GTM_TIM3_IN2_7 input func */
  {94U, 3U},
  /* GTM_TOUT252 input func */
  {94U, 4U},
  /* DSPI21_DSPI21_PCS4 input func */
  {94U, 5U},
  /* INMUX settings for pad PORT95:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN2_3 input func */
  {95U, 1U},
  /* GTM_TIM5_IN7_4 input func */
  {95U, 2U},
  /* GTM_TIM3_IN7_9 input func */
  {95U, 3U},
  /* DSPI7_DSPI7_PCS0 input func */
  {95U, 6U},
  /* GTM_TOUT264 input func */
  {95U, 4U},
  /* DSPI7_DSPI7_PCS0 input func */
  {95U, 6U},
  /* PSI5_PSI5_TX3 input func */
  {95U, 7U},
  /* INMUX settings for pad PORT96:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN3_5 input func */
  {96U, 1U},
  /* GTM_TIM0_IN3_5 input func */
  {96U, 2U},
  /* SENT_SENT_SENT17D input func */
  {96U, 3U},
  /* DSPI10_DSPI10_SCK input func */
  {96U, 11U},
  /* GTM_TOUT80 input func */
  {96U, 4U},
  /* LINFLEX0_LIN0_TX input func */
  {96U, 5U},
  /* DSPI10_DSPI10_SOUT input func */
  {96U, 6U},
  /* FLEXRAY0_ERAY0_TXDA input func */
  {96U, 7U},
  /* FLEXRAY0_ERAY0_TXDB input func */
  {96U, 8U},
  /* M_CAN_2_CAN01_TXD input func */
  {96U, 9U},
  /* EMIOS_EMIOS_5 input func */
  {96U, 12U},
  /* INMUX settings for pad PORT97:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN4_3 input func */
  {97U, 1U},
  /* GTM_TIM0_IN4_3 input func */
  {97U, 2U},
  /* FLEXRAY0_ERAY0_RXDA3 input func */
  {97U, 3U},
  /* LINFLEX0_LIN0_RX input func */
  {97U, 4U},
  /* DSPI10_DSPI10_SINA input func */
  {97U, 5U},
  /* SENT_SENT_SENT18D input func */
  {97U, 6U},
  /* FLEXRAY0_ERAY0_RXDB3 input func */
  {97U, 7U},
  /* M_CAN_2_CAN01_RXDB input func */
  {97U, 8U},
  /* GTM_TOUT81 input func */
  {97U, 11U},
  /* LINFLEX0_LIN0_TX input func */
  {97U, 12U},
  /* DSPI10_DSPI10_SOUT input func */
  {97U, 13U},
  /* EMIOS_EMIOS_20 input func */
  {97U, 14U},
  /* INMUX settings for pad PORT98:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN5_3 input func */
  {98U, 1U},
  /* GTM_TIM0_IN5_3 input func */
  {98U, 2U},
  /* DSPI2_DSPI2_SCK input func */
  {98U, 9U},
  /* GTM_TOUT82 input func */
  {98U, 4U},
  /* LINFLEX2_LIN2_TX input func */
  {98U, 5U},
  /* DSPI2_DSPI2_SOUT input func */
  {98U, 6U},
  /* DSPI18_DSPI18_PCS1 input func */
  {98U, 7U},
  /* INMUX settings for pad PORT99:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN6_3 input func */
  {99U, 1U},
  /* GTM_TIM0_IN6_3 input func */
  {99U, 2U},
  /* LINFLEX2_LIN2_RX input func */
  {99U, 4U},
  /* DSPI2_DSPI2_SINA input func */
  {99U, 5U},
  /* DSPI11_DSPI11_SIN input func */
  {99U, 6U},
  /* DSPI1_DSPI1_PCS0 input func */
  {99U, 13U},
  /* DSPI3_DSPI3_PCS0 input func */
  {99U, 15U},
  /* GTM_TOUT83 input func */
  {99U, 8U},
  /* LINFLEX2_LIN2_TX input func */
  {99U, 9U},
  /* DSPI2_DSPI2_SOUT input func */
  {99U, 10U},
  /* DSPI18_DSPI18_PCS3 input func */
  {99U, 11U},
  /* DSPI1_DSPI1_PCS0 input func */
  {99U, 13U},
  /* DSPI3_DSPI3_PCS0 input func */
  {99U, 15U},
  /* INMUX settings for pad PORT100:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN7_2 input func */
  {100U, 1U},
  /* GTM_TIM0_IN7_2 input func */
  {100U, 2U},
  /* GTM_DTMT0_0 input func */
  {100U, 4U},
  /* GTM_TOUT84 input func */
  {100U, 5U},
  /* GMAC_GETH_PPS input func */
  {100U, 6U},
  /* INMUX settings for pad PORT101:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN0_4 input func */
  {101U, 1U},
  /* GTM_TIM0_IN0_4 input func */
  {101U, 2U},
  /* DSPI21_DSPI21_SINB input func */
  {101U, 4U},
  /* GTM_DTMA2_0 input func */
  {101U, 5U},
  /* GTM_TOUT85 input func */
  {101U, 6U},
  /* DSPI21_DSPI21_SOUT input func */
  {101U, 7U},
  /* FLEXRAY0_ERAY0_TXDB input func */
  {101U, 8U},
  /* FLEXRAY1_ERAY1_TXDB input func */
  {101U, 9U},
  /* INMUX settings for pad PORT102:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN1_4 input func */
  {102U, 1U},
  /* GTM_TIM0_IN1_4 input func */
  {102U, 2U},
  /* DSPI21_DSPI21_SINB input func */
  {102U, 3U},
  /* GTM_TOUT86 input func */
  {102U, 4U},
  /* DSPI21_DSPI21_SOUT input func */
  {102U, 5U},
  /* DSPI18_DSPI18_PCS2 input func */
  {102U, 6U},
  /* M_CAN_8_CAN13_TXD input func */
  {102U, 7U},
  /* FLEXRAY0_ERAY0_TXENB input func */
  {102U, 8U},
  /* FLEXRAY1_ERAY1_TXENB input func */
  {102U, 9U},
  /* INMUX settings for pad PORT103:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN7_10 input func */
  {103U, 1U},
  /* GTM_TIM1_IN0_5 input func */
  {103U, 2U},
  /* GTM_TIM0_IN0_5 input func */
  {103U, 3U},
  /* FLEXRAY0_ERAY0_RXDB0 input func */
  {103U, 4U},
  /* FLEXRAY1_ERAY1_RXDB0 input func */
  {103U, 5U},
  /* M_CAN_5_CAN10_RXDB input func */
  {103U, 6U},
  /* M_CAN_8_CAN13_RXDA input func */
  {103U, 7U},
  /* LINFLEX9_LIN9_RX input func */
  {103U, 8U},
  /* DSPI9_DSPI9_SINC input func */
  {103U, 9U},
  /* GTM_TOUT87 input func */
  {103U, 10U},
  /* DSPI18_DSPI18_PCS4 input func */
  {103U, 12U},
  /* LINFLEX9_LIN9_TX input func */
  {103U, 13U},
  /* DSPI9_DSPI9_SOUT input func */
  {103U, 14U},
  /* INMUX settings for pad PORT104:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN2_3 input func */
  {104U, 1U},
  /* GTM_TIM2_IN2_3 input func */
  {104U, 2U},
  /* FLEXRAY0_ERAY0_RXDA0 input func */
  {104U, 3U},
  /* M_CAN_3_CAN02_RXDD input func */
  {104U, 4U},
  /* LINFLEX1_LIN1_RX input func */
  {104U, 5U},
  /* DSPI1_DSPI1_SIND input func */
  {104U, 6U},
  /* FLEXRAY1_ERAY1_RXDA0 input func */
  {104U, 7U},
  /* DSPI5_DSPI5_PCS0 input func */
  {104U, 10U},
  /* DSPI7_DSPI7_PCS0 input func */
  {104U, 12U},
  /* GTM_TOUT88 input func */
  {104U, 8U},
  /* DSPI5_DSPI5_PCS0 input func */
  {104U, 10U},
  /* DSPI7_DSPI7_PCS0 input func */
  {104U, 12U},
  /* INMUX settings for pad PORT105:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN3_3 input func */
  {105U, 1U},
  /* GTM_TIM2_IN3_3 input func */
  {105U, 2U},
  /* LINFLEX9_LIN9_RX input func */
  {105U, 5U},
  /* DSPI9_DSPI9_SIND input func */
  {105U, 6U},
  /* GTM_TOUT89 input func */
  {105U, 7U},
  /* M_CAN_12_CAN23_TXD input func */
  {105U, 8U},
  /* DSPI11_DSPI11_PCS1 input func */
  {105U, 9U},
  /* M_CAN_5_CAN10_TXD input func */
  {105U, 10U},
  /* FLEXRAY0_ERAY0_TXENB input func */
  {105U, 11U},
  /* FLEXRAY0_ERAY0_TXENA input func */
  {105U, 12U},
  /* FLEXRAY1_ERAY1_TXENA input func */
  {105U, 13U},
  /* INMUX settings for pad PORT106:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN4_3 input func */
  {106U, 1U},
  /* GTM_TIM2_IN4_3 input func */
  {106U, 2U},
  /* M_CAN_12_CAN23_RXDA input func */
  {106U, 3U},
  /* GTM_TOUT90 input func */
  {106U, 5U},
  /* DSPI11_DSPI11_PCS0 input func */
  {106U, 7U},
  /* LINFLEX1_LIN1_TX input func */
  {106U, 8U},
  /* DSPI1_DSPI1_SOUT input func */
  {106U, 9U},
  /* M_CAN_3_CAN02_TXD input func */
  {106U, 10U},
  /* FLEXRAY0_ERAY0_TXDA input func */
  {106U, 11U},
  /* FLEXRAY1_ERAY1_TXDA input func */
  {106U, 12U},
  /* INMUX settings for pad PORT107:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN6_2 input func */
  {107U, 1U},
  /* GTM_TIM5_IN1_4 input func */
  {107U, 2U},
  /* GTM_TIM3_IN1_9 input func */
  {107U, 3U},
  /* DSPI14_DSPI14_SIN input func */
  {107U, 4U},
  /* GTM_TOUT258 input func */
  {107U, 5U},
  /* DSPI14_DSPI14_PCS2 input func */
  {107U, 6U},
  /* INMUX settings for pad PORT108:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN4_3 input func */
  {108U, 1U},
  /* GTM_TIM5_IN4_5 input func */
  {108U, 2U},
  /* GTM_TIM3_IN4_8 input func */
  {108U, 3U},
  /* DSPI14_DSPI14_SIN input func */
  {108U, 4U},
  /* DSPI5_DSPI5_SCK input func */
  {108U, 7U},
  /* DSPI7_DSPI7_SCK input func */
  {108U, 9U},
  /* GTM_TOUT261 input func */
  {108U, 5U},
  /* DSPI21_DSPI21_PCS6 input func */
  {108U, 10U},
  /* INMUX settings for pad PORT109:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN5_3 input func */
  {109U, 1U},
  /* GTM_TIM5_IN3_5 input func */
  {109U, 2U},
  /* GTM_TIM3_IN3_6 input func */
  {109U, 3U},
  /* DSPI21_DSPI21_SCKB input func */
  {109U, 4U},
  /* GTM_TOUT260 input func */
  {109U, 5U},
  /* DSPI14_DSPI14_PCS1 input func */
  {109U, 7U},
  /* M_CAN_11_CAN22_TXD input func */
  {109U, 8U},
  /* INMUX settings for pad PORT110:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN6_3 input func */
  {110U, 1U},
  /* GTM_TIM5_IN2_3 input func */
  {110U, 2U},
  /* GTM_TIM3_IN2_8 input func */
  {110U, 3U},
  /* M_CAN_11_CAN22_RXDD input func */
  {110U, 4U},
  /* GTM_TOUT259 input func */
  {110U, 5U},
  /* LINFLEX5_LIN5_TX input func */
  {110U, 6U},
  /* DSPI5_DSPI5_SOUT input func */
  {110U, 7U},
  /* LINFLEX7_LIN7_TX input func */
  {110U, 8U},
  /* DSPI7_DSPI7_SOUT input func */
  {110U, 9U},
  /* DSPI14_DSPI14_PCS0 input func */
  {110U, 10U},
  /* M_CAN_12_CAN23_TXD input func */
  {110U, 11U},
  /* DSPI21_DSPI21_PCS7 input func */
  {110U, 12U},
  /* INMUX settings for pad PORT111:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN7_3 input func */
  {111U, 1U},
  /* GTM_TIM5_IN6_5 input func */
  {111U, 2U},
  /* GTM_TIM3_IN6_9 input func */
  {111U, 3U},
  /* LINFLEX5_LIN5_RX input func */
  {111U, 5U},
  /* DSPI5_DSPI5_SIND input func */
  {111U, 6U},
  /* LINFLEX7_LIN7_RX input func */
  {111U, 7U},
  /* DSPI7_DSPI7_SINA input func */
  {111U, 8U},
  /* M_CAN_12_CAN23_RXDC input func */
  {111U, 9U},
  /* GTM_TOUT263 input func */
  {111U, 11U},
  /* LINFLEX1_LIN1_TX input func */
  {111U, 12U},
  /* DSPI1_DSPI1_SOUT input func */
  {111U, 13U},
  /* INMUX settings for pad PORT112:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN3_4 input func */
  {112U, 1U},
  /* GTM_TIM2_IN3_4 input func */
  {112U, 2U},
  /* SD_EMMC_SDMMC0_DAT7_IN input func */
  {112U, 3U},
  /* DSPI1_DSPI1_SCK input func */
  {112U, 10U},
  /* GTM_TOUT71 input func */
  {112U, 4U},
  /* LINFLEX1_LIN1_TX input func */
  {112U, 5U},
  /* DSPI1_DSPI1_SOUT input func */
  {112U, 6U},
  /* M_CAN_3_CAN02_TXD input func */
  {112U, 8U},
  /* SD_EMMC_SDMMC0_DAT7 input func */
  {112U, 3U},
  /* INMUX settings for pad PORT113:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN4_4 input func */
  {113U, 1U},
  /* GTM_TIM2_IN4_4 input func */
  {113U, 2U},
  /* M_CAN_3_CAN02_RXDA input func */
  {113U, 3U},
  /* LINFLEX1_LIN1_RX input func */
  {113U, 4U},
  /* DSPI1_DSPI1_SINA input func */
  {113U, 5U},
  /* DSPI18_DSPI18_PCSB input func */
  {113U, 6U},
  /* GTM_TOUT72 input func */
  {113U, 8U},
  /* LINFLEX1_LIN1_TX input func */
  {113U, 9U},
  /* DSPI1_DSPI1_SOUT input func */
  {113U, 10U},
  /* DSPI18_DSPI18_PCS5 input func */
  {113U, 11U},
  /* SD_EMMC_SDMMC0_CLK input func */
  {113U, 12U},
  /* INMUX settings for pad PORT114:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN5_4 input func */
  {114U, 1U},
  /* GTM_TIM2_IN5_4 input func */
  {114U, 2U},
  /* DSPI18_DSPI18_PCSA input func */
  {114U, 3U},
  /* SENT_SENT_SENT10D input func */
  {114U, 4U},
  /* DSPI18_DSPI18_SINE input func */
  {114U, 5U},
  /* DSPI10_DSPI10_SCK input func */
  {114U, 13U},
  /* GTM_TOUT73 input func */
  {114U, 7U},
  /* LINFLEX0_LIN0_TX input func */
  {114U, 8U},
  /* DSPI10_DSPI10_SOUT input func */
  {114U, 9U},
  /* DSPI18_DSPI18_PCS0 input func */
  {114U, 10U},
  /* M_CAN_2_CAN01_TXD input func */
  {114U, 11U},
  /* INMUX settings for pad PORT115:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN6_4 input func */
  {115U, 1U},
  /* GTM_TIM2_IN6_4 input func */
  {115U, 2U},
  /* M_CAN_2_CAN01_RXDA input func */
  {115U, 3U},
  /* LINFLEX0_LIN0_RX input func */
  {115U, 4U},
  /* DSPI10_DSPI10_SINB input func */
  {115U, 5U},
  /* DSPI18_DSPI18_SCKA input func */
  {115U, 6U},
  /* SD_EMMC_SDMMC0_CMD_IN input func */
  {115U, 8U},
  /* GTM_TOUT74 input func */
  {115U, 9U},
  /* LINFLEX0_LIN0_TX input func */
  {115U, 10U},
  /* DSPI10_DSPI10_SOUT input func */
  {115U, 11U},
  /* DSPI11_DSPI11_PCS1 input func */
  {115U, 13U},
  /* SD_EMMC_SDMMC0_CMD input func */
  {115U, 8U},
  /* INMUX settings for pad PORT116:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN7_4 input func */
  {116U, 1U},
  /* GTM_TIM2_IN7_4 input func */
  {116U, 2U},
  /* I2C0_I2C0_SCLC input func */
  {116U, 3U},
  /* DSPI18_DSPI18_SINA input func */
  {116U, 4U},
  /* SENT_SENT_SENT11D input func */
  {116U, 6U},
  /* GTM_TOUT75 input func */
  {116U, 7U},
  /* LINFLEX1_LIN1_TX input func */
  {116U, 8U},
  /* DSPI1_DSPI1_SOUT input func */
  {116U, 9U},
  /* DSPI18_DSPI18_SOUT input func */
  {116U, 10U},
  /* EMIOS_EMIOS_4 input func */
  {116U, 12U},
  /* INMUX settings for pad PORT117:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN0_4 input func */
  {117U, 1U},
  /* GTM_TIM2_IN0_4 input func */
  {117U, 2U},
  /* LINFLEX1_LIN1_RX input func */
  {117U, 3U},
  /* DSPI1_DSPI1_SINB input func */
  {117U, 4U},
  /* I2C0_I2C0_SDAC input func */
  {117U, 5U},
  /* DSPI18_DSPI18_SINA input func */
  {117U, 6U},
  /* GTM_TOUT76 input func */
  {117U, 8U},
  /* LINFLEX1_LIN1_TX input func */
  {117U, 9U},
  /* DSPI1_DSPI1_SOUT input func */
  {117U, 10U},
  /* DSPI18_DSPI18_SOUT input func */
  {117U, 11U},
  /* DSPI11_DSPI11_PCS0 input func */
  {117U, 12U},
  /* EMIOS_EMIOS_2 input func */
  {117U, 14U},
  /* INMUX settings for pad PORT118:      {INMUX reg, PADSEL val} */
  /* GTM_TIM2_IN2_14 input func */
  {118U, 1U},
  /* GTM_TIM1_IN0_6 input func */
  {118U, 2U},
  /* GTM_TIM0_IN0_6 input func */
  {118U, 3U},
  /* DSPI18_DSPI18_SINB input func */
  {118U, 4U},
  /* DSPI3_DSPI3_SCK input func */
  {118U, 12U},
  /* GTM_TOUT77 input func */
  {118U, 5U},
  /* LINFLEX3_LIN3_TX input func */
  {118U, 6U},
  /* DSPI3_DSPI3_SOUT input func */
  {118U, 7U},
  /* DSPI18_DSPI18_SOUT input func */
  {118U, 8U},
  /* DSPI21_DSPI21_PCS3 input func */
  {118U, 9U},
  /* EMIOS_EMIOS_0 input func */
  {118U, 13U},
  /* INMUX settings for pad PORT119:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN1_5 input func */
  {119U, 1U},
  /* GTM_TIM0_IN1_5 input func */
  {119U, 2U},
  /* LINFLEX3_LIN3_RX input func */
  {119U, 3U},
  /* DSPI3_DSPI3_SINA input func */
  {119U, 4U},
  /* DSPI18_DSPI18_SINB input func */
  {119U, 5U},
  /* GTM_TOUT78 input func */
  {119U, 6U},
  /* LINFLEX3_LIN3_TX input func */
  {119U, 7U},
  /* DSPI3_DSPI3_SOUT input func */
  {119U, 8U},
  /* DSPI18_DSPI18_SOUT input func */
  {119U, 9U},
  /* EMIOS_EMIOS_1 input func */
  {119U, 10U},
  /* INMUX settings for pad PORT120:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN2_5 input func */
  {120U, 1U},
  /* GTM_TIM0_IN2_5 input func */
  {120U, 2U},
  /* DSPI18_DSPI18_SCKB input func */
  {120U, 3U},
  /* DSPI3_DSPI3_SCK input func */
  {120U, 8U},
  /* GTM_TOUT79 input func */
  {120U, 5U},
  /* EMIOS_EMIOS_3 input func */
  {120U, 9U},
  /* INMUX settings for pad PORT121:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN0_2 input func */
  {121U, 1U},
  /* GTM_TIM4_IN1_7 input func */
  {121U, 2U},
  /* GTM_TIM2_IN1_8 input func */
  {121U, 3U},
  /* DSPI21_DSPI21_SINA input func */
  {121U, 4U},
  /* GTM_TOUT242 input func */
  {121U, 5U},
  /* DSPI21_DSPI21_SOUT input func */
  {121U, 6U},
  /* INMUX settings for pad PORT122:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN1_2 input func */
  {122U, 1U},
  /* GTM_TIM4_IN2_6 input func */
  {122U, 2U},
  /* GTM_TIM2_IN2_8 input func */
  {122U, 3U},
  /* DSPI21_DSPI21_PCSA input func */
  {122U, 4U},
  /* GTM_TOUT243 input func */
  {122U, 5U},
  /* DSPI21_DSPI21_PCS2 input func */
  {122U, 6U},
  /* INMUX settings for pad PORT123:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN2_2 input func */
  {123U, 1U},
  /* GTM_TIM4_IN3_6 input func */
  {123U, 2U},
  /* GTM_TIM2_IN3_6 input func */
  {123U, 3U},
  /* GTM_TOUT244 input func */
  {123U, 4U},
  /* DSPI21_DSPI21_PCS1 input func */
  {123U, 5U},
  /* INMUX settings for pad PORT124:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN3_3 input func */
  {124U, 1U},
  /* GTM_TIM4_IN4_6 input func */
  {124U, 2U},
  /* GTM_TIM2_IN4_9 input func */
  {124U, 3U},
  /* GTM_TOUT245 input func */
  {124U, 4U},
  /* DSPI21_DSPI21_PCS0 input func */
  {124U, 5U},
  /* INMUX settings for pad PORT125:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN4_2 input func */
  {125U, 1U},
  /* GTM_TIM4_IN5_6 input func */
  {125U, 2U},
  /* GTM_TIM2_IN5_12 input func */
  {125U, 3U},
  /* DSPI21_DSPI21_SINA input func */
  {125U, 4U},
  /* GTM_TOUT246 input func */
  {125U, 5U},
  /* DSPI21_DSPI21_SOUT input func */
  {125U, 6U},
  /* DSPI15_DSPI15_PCS0 input func */
  {125U, 7U},
  /* INMUX settings for pad PORT126:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN5_2 input func */
  {126U, 1U},
  /* GTM_TIM4_IN6_6 input func */
  {126U, 2U},
  /* GTM_TIM2_IN6_9 input func */
  {126U, 3U},
  /* DSPI21_DSPI21_SCKA input func */
  {126U, 4U},
  /* GTM_TOUT247 input func */
  {126U, 5U},
  /* DSPI15_DSPI15_PCS1 input func */
  {126U, 7U},
  /* INMUX settings for pad PORT127:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN6_7 input func */
  {127U, 1U},
  /* GTM_TIM1_IN4_9 input func */
  {127U, 2U},
  /* GTM_TIM0_IN6_7 input func */
  {127U, 3U},
  /* M_CAN_4_CAN03_RXDC input func */
  {127U, 4U},
  /* M_CAN_10_CAN21_RXDC input func */
  {127U, 6U},
  /* DSPI3_DSPI3_SCK input func */
  {127U, 14U},
  /* GTM_TOUT59 input func */
  {127U, 10U},
  /* LINFLEX3_LIN3_TX input func */
  {127U, 11U},
  /* DSPI3_DSPI3_SOUT input func */
  {127U, 12U},
  /* INMUX settings for pad PORT128:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN4_11 input func */
  {128U, 1U},
  /* GTM_TIM3_IN3_5 input func */
  {128U, 2U},
  /* GTM_TIM2_IN3_5 input func */
  {128U, 3U},
  /* GTM_DTMA1_1 input func */
  {128U, 5U},
  /* GTM_TOUT60 input func */
  {128U, 6U},
  /* INMUX settings for pad PORT130:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN5_11 input func */
  {130U, 1U},
  /* GTM_TIM3_IN4_5 input func */
  {130U, 2U},
  /* GTM_TIM2_IN4_5 input func */
  {130U, 3U},
  /* LINFLEX3_LIN3_RX input func */
  {130U, 4U},
  /* DSPI3_DSPI3_SINC input func */
  {130U, 5U},
  /* EMIOS_EMIOS_24 input func */
  {130U, 6U},
  /* EMIOS_EMIOS_24 input func */
  {130U, 6U},
  /* GTM_TOUT61 input func */
  {130U, 7U},
  /* LINFLEX3_LIN3_TX input func */
  {130U, 8U},
  /* DSPI3_DSPI3_SOUT input func */
  {130U, 9U},
  /* M_CAN_4_CAN03_TXD input func */
  {130U, 12U},
  /* M_CAN_10_CAN21_TXD input func */
  {130U, 13U},
  /* INMUX settings for pad PORT131:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN0_1 input func */
  {131U, 1U},
  /* GTM_TIM3_IN6_5 input func */
  {131U, 2U},
  /* GTM_TIM2_IN6_5 input func */
  {131U, 3U},
  /* M_CAN_7_CAN12_RXDA input func */
  {131U, 4U},
  /* LINFLEX9_LIN9_RX input func */
  {131U, 5U},
  /* DSPI9_DSPI9_SINE input func */
  {131U, 6U},
  /* GTM_TOUT62 input func */
  {131U, 7U},
  /* INMUX settings for pad PORT132:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN7_5 input func */
  {132U, 1U},
  /* GTM_TIM2_IN7_5 input func */
  {132U, 2U},
  /* GTM_TIM1_IN5_8 input func */
  {132U, 3U},
  /* GTM_TIM6_IN1_1 input func */
  {132U, 4U},
  /* M_CAN_1_CAN00_RXDB input func */
  {132U, 5U},
  /* LINFLEX9_LIN9_RX input func */
  {132U, 7U},
  /* DSPI9_DSPI9_SINF input func */
  {132U, 8U},
  /* SD_EMMC_SDMMC0_DAT0_IN input func */
  {132U, 9U},
  /* GTM_TOUT63 input func */
  {132U, 10U},
  /* LINFLEX9_LIN9_TX input func */
  {132U, 11U},
  /* DSPI9_DSPI9_SOUT input func */
  {132U, 12U},
  /* M_CAN_7_CAN12_TXD input func */
  {132U, 13U},
  /* EMIOS_EMIOS_21 input func */
  {132U, 14U},
  /* SD_EMMC_SDMMC0_DAT0 input func */
  {132U, 9U},
  /* INMUX settings for pad PORT133:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN2_1 input func */
  {133U, 1U},
  /* GTM_TIM1_IN7_3 input func */
  {133U, 2U},
  /* GTM_TIM0_IN7_3 input func */
  {133U, 3U},
  /* SD_EMMC_SDMMC0_DAT1_IN input func */
  {133U, 4U},
  /* DSPI1_DSPI1_PCS0 input func */
  {133U, 7U},
  /* GTM_TOUT64 input func */
  {133U, 5U},
  /* DSPI1_DSPI1_PCS0 input func */
  {133U, 7U},
  /* DSPI16_DSPI16_PCS0 input func */
  {133U, 8U},
  /* DSPI17_DSPI17_PCS0 input func */
  {133U, 9U},
  /* M_CAN_1_CAN00_TXD input func */
  {133U, 10U},
  /* EMIOS_EMIOS_6 input func */
  {133U, 11U},
  /* SD_EMMC_SDMMC0_DAT1 input func */
  {133U, 4U},
  /* INMUX settings for pad PORT134:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN3_1 input func */
  {134U, 1U},
  /* GTM_TIM3_IN5_5 input func */
  {134U, 2U},
  /* GTM_TIM2_IN5_5 input func */
  {134U, 3U},
  /* M_CAN_4_CAN03_RXDE input func */
  {134U, 4U},
  /* LINFLEX1_LIN1_RX input func */
  {134U, 5U},
  /* DSPI1_DSPI1_SINC input func */
  {134U, 6U},
  /* DSPI16_DSPI16_PCSB input func */
  {134U, 7U},
  /* GTM_TOUT65 input func */
  {134U, 9U},
  /* DSPI16_DSPI16_PCS1 input func */
  {134U, 10U},
  /* DSPI17_DSPI17_PCS1 input func */
  {134U, 11U},
  /* EMIOS_EMIOS_16 input func */
  {134U, 12U},
  /* INMUX settings for pad PORT135:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN6_6 input func */
  {135U, 1U},
  /* GTM_TIM2_IN6_6 input func */
  {135U, 2U},
  /* SD_EMMC_SDMMC0_DAT2_IN input func */
  {135U, 3U},
  /* DSPI1_DSPI1_SCK input func */
  {135U, 11U},
  /* GTM_TOUT66 input func */
  {135U, 4U},
  /* LINFLEX1_LIN1_TX input func */
  {135U, 5U},
  /* DSPI1_DSPI1_SOUT input func */
  {135U, 6U},
  /* DSPI16_DSPI16_PCS6 input func */
  {135U, 7U},
  /* DSPI18_DSPI18_PCS7 input func */
  {135U, 8U},
  /* M_CAN_4_CAN03_TXD input func */
  {135U, 9U},
  /* EMIOS_EMIOS_18 input func */
  {135U, 12U},
  /* SD_EMMC_SDMMC0_DAT2 input func */
  {135U, 3U},
  /* INMUX settings for pad PORT136:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN7_6 input func */
  {136U, 1U},
  /* GTM_TIM2_IN7_6 input func */
  {136U, 2U},
  /* DSPI16_DSPI16_SCKA input func */
  {136U, 3U},
  /* SD_EMMC_SDMMC0_DAT3_IN input func */
  {136U, 4U},
  /* GTM_TOUT67 input func */
  {136U, 5U},
  /* EMIOS_EMIOS_7 input func */
  {136U, 7U},
  /* SD_EMMC_SDMMC0_DAT3 input func */
  {136U, 4U},
  /* INMUX settings for pad PORT137:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN0_5 input func */
  {137U, 1U},
  /* GTM_TIM2_IN0_5 input func */
  {137U, 2U},
  /* DSPI16_DSPI16_SINA input func */
  {137U, 3U},
  /* SD_EMMC_SDMMC0_DAT4_IN input func */
  {137U, 4U},
  /* GTM_TOUT68 input func */
  {137U, 5U},
  /* DSPI16_DSPI16_SOUT input func */
  {137U, 6U},
  /* EMIOS_EMIOS_17 input func */
  {137U, 8U},
  /* SD_EMMC_SDMMC0_DAT4 input func */
  {137U, 4U},
  /* INMUX settings for pad PORT138:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN1_4 input func */
  {138U, 1U},
  /* GTM_TIM2_IN1_4 input func */
  {138U, 2U},
  /* DSPI16_DSPI16_PCSA input func */
  {138U, 3U},
  /* SD_EMMC_SDMMC0_DAT5_IN input func */
  {138U, 4U},
  /* GTM_TOUT69 input func */
  {138U, 5U},
  /* DSPI16_DSPI16_PCS2 input func */
  {138U, 6U},
  /* DSPI17_DSPI17_PCS2 input func */
  {138U, 7U},
  /* EMIOS_EMIOS_19 input func */
  {138U, 9U},
  /* SD_EMMC_SDMMC0_DAT5 input func */
  {138U, 4U},
  /* INMUX settings for pad PORT139:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN2_4 input func */
  {139U, 1U},
  /* GTM_TIM2_IN2_4 input func */
  {139U, 2U},
  /* DSPI16_DSPI16_SINA input func */
  {139U, 3U},
  /* SD_EMMC_SDMMC0_DAT6_IN input func */
  {139U, 4U},
  /* GTM_TOUT70 input func */
  {139U, 5U},
  /* DSPI16_DSPI16_SOUT input func */
  {139U, 6U},
  /* SD_EMMC_SDMMC0_DAT6 input func */
  {139U, 4U},
  /* INMUX settings for pad PORT140:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN0_11 input func */
  {140U, 1U},
  /* GTM_TIM3_IN4_6 input func */
  {140U, 2U},
  /* GTM_TIM2_IN4_6 input func */
  {140U, 3U},
  /* LINFLEX11_LIN11_RX input func */
  {140U, 6U},
  /* DSPI12_DSPI12_SINC input func */
  {140U, 7U},
  /* GTM_TOUT51 input func */
  {140U, 9U},
  /* LINFLEX11_LIN11_TX input func */
  {140U, 10U},
  /* DSPI12_DSPI12_SOUT input func */
  {140U, 11U},
  /* INMUX settings for pad PORT141:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN1_13 input func */
  {141U, 1U},
  /* GTM_TIM3_IN5_6 input func */
  {141U, 2U},
  /* GTM_TIM2_IN5_6 input func */
  {141U, 3U},
  /* LINFLEX11_LIN11_RX input func */
  {141U, 5U},
  /* DSPI12_DSPI12_SIND input func */
  {141U, 6U},
  /* GTM_DTMA4_1 input func */
  {141U, 8U},
  /* GTM_TOUT52 input func */
  {141U, 9U},
  /* INMUX settings for pad PORT142:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN4_11 input func */
  {142U, 1U},
  /* GTM_TIM1_IN0_7 input func */
  {142U, 2U},
  /* GTM_TIM0_IN0_7 input func */
  {142U, 3U},
  /* LINFLEX11_LIN11_RX input func */
  {142U, 9U},
  /* DSPI12_DSPI12_SINE input func */
  {142U, 10U},
  /* GTM_DTMA1_0 input func */
  {142U, 11U},
  /* DSPI3_DSPI3_PCS0 input func */
  {142U, 14U},
  /* GTM_TOUT53 input func */
  {142U, 12U},
  /* DSPI3_DSPI3_PCS0 input func */
  {142U, 14U},
  /* GMAC_GETH_MDC input func */
  {142U, 15U},
  /* INMUX settings for pad PORT143:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN5_12 input func */
  {143U, 1U},
  /* GTM_TIM1_IN1_6 input func */
  {143U, 2U},
  /* GTM_TIM0_IN1_6 input func */
  {143U, 3U},
  /* GMAC_GETH_MDIOD input func */
  {143U, 6U},
  /* DSPI12_DSPI12_SCK input func */
  {143U, 11U},
  /* GTM_TOUT54 input func */
  {143U, 9U},
  /* GMAC_GETH_MDIO input func */
  {143U, 6U},
  /* INMUX settings for pad PORT144:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN6_12 input func */
  {144U, 1U},
  /* GTM_TIM1_IN2_6 input func */
  {144U, 2U},
  /* GTM_TIM0_IN2_6 input func */
  {144U, 3U},
  /* DSPI12_DSPI12_PCS0 input func */
  {144U, 6U},
  /* GTM_TOUT55 input func */
  {144U, 4U},
  /* DSPI12_DSPI12_PCS0 input func */
  {144U, 6U},
  /* INMUX settings for pad PORT145:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN7_11 input func */
  {145U, 1U},
  /* GTM_TIM1_IN3_6 input func */
  {145U, 2U},
  /* GTM_TIM0_IN3_6 input func */
  {145U, 3U},
  /* LINFLEX11_LIN11_RX input func */
  {145U, 4U},
  /* DSPI12_DSPI12_SINF input func */
  {145U, 5U},
  /* DSPI3_DSPI3_SCK input func */
  {145U, 8U},
  /* GTM_TOUT56 input func */
  {145U, 6U},
  /* LINFLEX11_LIN11_TX input func */
  {145U, 9U},
  /* DSPI12_DSPI12_SOUT input func */
  {145U, 10U},
  /* INMUX settings for pad PORT146:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN2_12 input func */
  {146U, 1U},
  /* GTM_TIM1_IN4_8 input func */
  {146U, 2U},
  /* GTM_TIM0_IN4_8 input func */
  {146U, 3U},
  /* LINFLEX3_LIN3_RX input func */
  {146U, 5U},
  /* DSPI3_DSPI3_SINF input func */
  {146U, 6U},
  /* JTAG_TDI input func */
  {146U, 8U},
  /* DSPI3_DSPI3_PCS0 input func */
  {146U, 11U},
  /* GTM_TOUT57 input func */
  {146U, 9U},
  /* DSPI3_DSPI3_PCS0 input func */
  {146U, 11U},
  /* EMIOS_EMIOS_22 input func */
  {146U, 12U},
  /* INMUX settings for pad PORT147:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN3_12 input func */
  {147U, 1U},
  /* GTM_TIM1_IN5_7 input func */
  {147U, 2U},
  /* GTM_TIM0_IN5_7 input func */
  {147U, 3U},
  /* EMIOS_EMIOS_23 input func */
  {147U, 4U},
  /* GMAC_GETH_RXERB input func */
  {147U, 6U},
  /* DSPI3_DSPI3_SCK input func */
  {147U, 11U},
  /* GTM_TOUT58 input func */
  {147U, 7U},
  /* LINFLEX3_LIN3_TX input func */
  {147U, 8U},
  /* DSPI3_DSPI3_SOUT input func */
  {147U, 9U},
  /* EMIOS_EMIOS_23 input func */
  {147U, 12U},
  /* JTAG_TDO input func */
  {147U, 0U},
  /* INMUX settings for pad PORT148:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN3_1 input func */
  {148U, 1U},
  /* GTM_TIM1_IN1_7 input func */
  {148U, 2U},
  /* GTM_TIM0_IN1_7 input func */
  {148U, 3U},
  /* DSPI20_DSPI20_SINB input func */
  {148U, 4U},
  /* LINFLEX6_LIN6_RX input func */
  {148U, 5U},
  /* DSPI6_DSPI6_SINE input func */
  {148U, 6U},
  /* GTM_TOUT47 input func */
  {148U, 7U},
  /* DSPI20_DSPI20_SOUT input func */
  {148U, 9U},
  /* LINFLEX6_LIN6_TX input func */
  {148U, 12U},
  /* DSPI6_DSPI6_SOUT input func */
  {148U, 13U},
  /* INMUX settings for pad PORT149:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN2_1 input func */
  {149U, 1U},
  /* GTM_TIM1_IN0_8 input func */
  {149U, 2U},
  /* GTM_TIM0_IN0_8 input func */
  {149U, 3U},
  /* DSPI20_DSPI20_SINB input func */
  {149U, 4U},
  /* LINFLEX7_LIN7_RX input func */
  {149U, 5U},
  /* DSPI7_DSPI7_SINE input func */
  {149U, 6U},
  /* GTM_TOUT48 input func */
  {149U, 7U},
  /* DSPI20_DSPI20_SOUT input func */
  {149U, 9U},
  /* LINFLEX7_LIN7_TX input func */
  {149U, 12U},
  /* DSPI7_DSPI7_SOUT input func */
  {149U, 13U},
  /* INMUX settings for pad PORT150:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN1_1 input func */
  {150U, 1U},
  /* GTM_TIM1_IN3_7 input func */
  {150U, 2U},
  /* GTM_TIM0_IN3_7 input func */
  {150U, 3U},
  /* DSPI20_DSPI20_PCSB input func */
  {150U, 4U},
  /* GTM_TOUT49 input func */
  {150U, 5U},
  /* LINFLEX5_LIN5_TX input func */
  {150U, 6U},
  /* DSPI5_DSPI5_SOUT input func */
  {150U, 7U},
  /* DSPI20_DSPI20_PCS3 input func */
  {150U, 8U},
  /* INMUX settings for pad PORT151:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN0_1 input func */
  {151U, 1U},
  /* GTM_TIM1_IN4_4 input func */
  {151U, 2U},
  /* GTM_TIM0_IN4_4 input func */
  {151U, 3U},
  /* DSPI20_DSPI20_SCKB input func */
  {151U, 4U},
  /* LINFLEX5_LIN5_RX input func */
  {151U, 5U},
  /* DSPI5_DSPI5_SINC input func */
  {151U, 6U},
  /* GTM_TOUT50 input func */
  {151U, 7U},
  /* INMUX settings for pad PORT152:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN0_8 input func */
  {152U, 1U},
  /* LINFLEX7_LIN7_RX input func */
  {152U, 2U},
  /* DSPI7_DSPI7_SINF input func */
  {152U, 3U},
  /* GTM_DTMA3_0 input func */
  {152U, 4U},
  /* DSPI4_DSPI4_PCS0 input func */
  {152U, 7U},
  /* GTM_TOUT130 input func */
  {152U, 5U},
  /* DSPI4_DSPI4_PCS0 input func */
  {152U, 7U},
  /* M_CAN_8_CAN13_TXD input func */
  {152U, 9U},
  /* INMUX settings for pad PORT153:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN1_7 input func */
  {153U, 1U},
  /* DSPI16_DSPI16_SINC input func */
  {153U, 2U},
  /* M_CAN_8_CAN13_RXDC input func */
  {153U, 3U},
  /* GTM_TOUT131 input func */
  {153U, 4U},
  /* LINFLEX4_LIN4_TX input func */
  {153U, 5U},
  /* DSPI4_DSPI4_SOUT input func */
  {153U, 6U},
  /* DSPI16_DSPI16_SOUT input func */
  {153U, 7U},
  /* INMUX settings for pad PORT154:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN2_6 input func */
  {154U, 1U},
  /* GTM_TIM2_IN6_14 input func */
  {154U, 2U},
  /* DSPI16_DSPI16_SINC input func */
  {154U, 3U},
  /* LINFLEX4_LIN4_RX input func */
  {154U, 4U},
  /* DSPI4_DSPI4_SINC input func */
  {154U, 5U},
  /* GTM_TOUT132 input func */
  {154U, 6U},
  /* DSPI16_DSPI16_SOUT input func */
  {154U, 7U},
  /* M_CAN_10_CAN21_TXD input func */
  {154U, 8U},
  /* INMUX settings for pad PORT155:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN3_7 input func */
  {155U, 1U},
  /* DSPI16_DSPI16_SCKC input func */
  {155U, 2U},
  /* M_CAN_10_CAN21_RXDF input func */
  {155U, 3U},
  /* DSPI4_DSPI4_SCK input func */
  {155U, 6U},
  /* GTM_TOUT133 input func */
  {155U, 4U},
  /* INMUX settings for pad PORT156:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN0_4 input func */
  {156U, 1U},
  /* GTM_TIM3_IN4_7 input func */
  {156U, 2U},
  /* DSPI16_DSPI16_SCKB input func */
  {156U, 3U},
  /* DSPI5_DSPI5_SCK input func */
  {156U, 6U},
  /* GTM_TOUT134 input func */
  {156U, 4U},
  /* M_CAN_11_CAN22_TXD input func */
  {156U, 8U},
  /* INMUX settings for pad PORT157:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN1_10 input func */
  {157U, 1U},
  /* GTM_TIM3_IN5_7 input func */
  {157U, 2U},
  /* DSPI16_DSPI16_SINB input func */
  {157U, 3U},
  /* LINFLEX4_LIN4_RX input func */
  {157U, 4U},
  /* DSPI4_DSPI4_SIND input func */
  {157U, 5U},
  /* M_CAN_11_CAN22_RXDE input func */
  {157U, 6U},
  /* GTM_DTMA3_1 input func */
  {157U, 7U},
  /* GTM_TOUT135 input func */
  {157U, 8U},
  /* DSPI16_DSPI16_SOUT input func */
  {157U, 9U},
  /* INMUX settings for pad PORT158:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN2_8 input func */
  {158U, 1U},
  /* GTM_TIM3_IN6_7 input func */
  {158U, 2U},
  /* DSPI16_DSPI16_SINB input func */
  {158U, 3U},
  /* GTM_TOUT136 input func */
  {158U, 4U},
  /* LINFLEX4_LIN4_TX input func */
  {158U, 5U},
  /* DSPI4_DSPI4_SOUT input func */
  {158U, 6U},
  /* DSPI16_DSPI16_SOUT input func */
  {158U, 7U},
  /* M_CAN_12_CAN23_TXD input func */
  {158U, 8U},
  /* INMUX settings for pad PORT159:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN3_10 input func */
  {159U, 1U},
  /* GTM_TIM3_IN7_7 input func */
  {159U, 2U},
  /* M_CAN_12_CAN23_RXDE input func */
  {159U, 3U},
  /* DSPI4_DSPI4_PCS0 input func */
  {159U, 6U},
  /* GTM_TOUT137 input func */
  {159U, 4U},
  /* DSPI4_DSPI4_PCS0 input func */
  {159U, 6U},
  /* INMUX settings for pad PORT160:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN7_1 input func */
  {160U, 1U},
  /* GTM_TIM1_IN5_4 input func */
  {160U, 2U},
  /* GTM_TIM0_IN5_4 input func */
  {160U, 3U},
  /* M_CAN_5_CAN10_RXDC input func */
  {160U, 4U},
  /* GTM_TOUT41 input func */
  {160U, 5U},
  /* INMUX settings for pad PORT161:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN6_1 input func */
  {161U, 1U},
  /* GTM_TIM1_IN6_4 input func */
  {161U, 2U},
  /* GTM_TIM0_IN6_4 input func */
  {161U, 3U},
  /* DSPI13_DSPI13_SIN input func */
  {161U, 4U},
  /* LINFLEX6_LIN6_RX input func */
  {161U, 5U},
  /* DSPI6_DSPI6_SINF input func */
  {161U, 6U},
  /* DSPI6_DSPI6_SCK input func */
  {161U, 14U},
  /* GTM_TOUT42 input func */
  {161U, 7U},
  /* DSPI20_DSPI20_PCS6 input func */
  {161U, 9U},
  /* GTM_CLK0 input func */
  {161U, 10U},
  /* M_CAN_5_CAN10_TXD input func */
  {161U, 11U},
  /* INMUX settings for pad PORT162:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN5_1 input func */
  {162U, 1U},
  /* GTM_TIM1_IN6_5 input func */
  {162U, 2U},
  /* GTM_TIM0_IN6_5 input func */
  {162U, 3U},
  /* LINFLEX7_LIN7_RX input func */
  {162U, 4U},
  /* DSPI7_DSPI7_SINC input func */
  {162U, 5U},
  /* GTM_TOUT43 input func */
  {162U, 6U},
  /* M_CAN_12_CAN23_TXD input func */
  {162U, 7U},
  /* M_CAN_7_CAN12_TXD input func */
  {162U, 8U},
  /* INMUX settings for pad PORT163:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN4_2 input func */
  {163U, 1U},
  /* GTM_TIM1_IN7_4 input func */
  {163U, 2U},
  /* GTM_TIM0_IN7_4 input func */
  {163U, 3U},
  /* LINFLEX6_LIN6_RX input func */
  {163U, 5U},
  /* DSPI6_DSPI6_SINA input func */
  {163U, 6U},
  /* M_CAN_7_CAN12_RXDC input func */
  {163U, 7U},
  /* M_CAN_12_CAN23_RXDB input func */
  {163U, 8U},
  /* GTM_TOUT44 input func */
  {163U, 9U},
  /* LINFLEX7_LIN7_TX input func */
  {163U, 10U},
  /* DSPI7_DSPI7_SOUT input func */
  {163U, 11U},
  /* INMUX settings for pad PORT164:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN3_2 input func */
  {164U, 1U},
  /* GTM_TIM1_IN7_5 input func */
  {164U, 2U},
  /* GTM_TIM0_IN7_5 input func */
  {164U, 3U},
  /* DSPI6_DSPI6_PCS0 input func */
  {164U, 6U},
  /* GTM_TOUT45 input func */
  {164U, 4U},
  /* DSPI6_DSPI6_PCS0 input func */
  {164U, 6U},
  /* DSPI20_DSPI20_PCS5 input func */
  {164U, 7U},
  /* DSPI13_DSPI13_PCS0 input func */
  {164U, 8U},
  /* INMUX settings for pad PORT165:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN2_2 input func */
  {165U, 1U},
  /* GTM_TIM1_IN2_7 input func */
  {165U, 2U},
  /* GTM_TIM0_IN2_7 input func */
  {165U, 3U},
  /* GTM_TOUT46 input func */
  {165U, 4U},
  /* LINFLEX6_LIN6_TX input func */
  {165U, 5U},
  /* DSPI6_DSPI6_SOUT input func */
  {165U, 6U},
  /* DSPI20_DSPI20_PCS4 input func */
  {165U, 7U},
  /* DSPI13_DSPI13_PCS1 input func */
  {165U, 8U},
  /* M_CAN_11_CAN22_TXD input func */
  {165U, 9U},
  /* INMUX settings for pad PORT166:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN1_2 input func */
  {166U, 1U},
  /* GTM_TIM4_IN2_7 input func */
  {166U, 2U},
  /* GTM_TIM1_IN2_10 input func */
  {166U, 3U},
  /* M_CAN_11_CAN22_RXDC input func */
  {166U, 4U},
  /* GTM_TOUT138 input func */
  {166U, 5U},
  /* M_CAN_6_CAN11_TXD input func */
  {166U, 7U},
  /* INMUX settings for pad PORT167:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN0_2 input func */
  {167U, 1U},
  /* GTM_TIM4_IN3_7 input func */
  {167U, 2U},
  /* GTM_TIM1_IN3_10 input func */
  {167U, 3U},
  /* M_CAN_6_CAN11_RXDC input func */
  {167U, 4U},
  /* GTM_TOUT139 input func */
  {167U, 5U},
  /* INMUX settings for pad PORT168:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN0_6 input func */
  {168U, 1U},
  /* GTM_TIM4_IN0_8 input func */
  {168U, 2U},
  /* GTM_TOUT222 input func */
  {168U, 4U},
  /* INMUX settings for pad PORT169:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN1_6 input func */
  {169U, 1U},
  /* GTM_TIM4_IN1_8 input func */
  {169U, 2U},
  /* GTM_TOUT223 input func */
  {169U, 4U},
  /* INMUX settings for pad PORT170:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN2_6 input func */
  {170U, 1U},
  /* GTM_TIM4_IN2_8 input func */
  {170U, 2U},
  /* GTM_TOUT224 input func */
  {170U, 4U},
  /* INMUX settings for pad PORT171:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN3_6 input func */
  {171U, 1U},
  /* GTM_TIM4_IN3_8 input func */
  {171U, 2U},
  /* GTM_TOUT225 input func */
  {171U, 4U},
  /* INMUX settings for pad PORT172:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN4_5 input func */
  {172U, 1U},
  /* GTM_TIM4_IN4_7 input func */
  {172U, 2U},
  /* GTM_TOUT226 input func */
  {172U, 4U},
  /* INMUX settings for pad PORT173:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN5_5 input func */
  {173U, 1U},
  /* GTM_TIM4_IN5_7 input func */
  {173U, 2U},
  /* GTM_TOUT227 input func */
  {173U, 4U},
  /* INMUX settings for pad PORT174:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN6_5 input func */
  {174U, 1U},
  /* GTM_TIM4_IN6_7 input func */
  {174U, 2U},
  /* GTM_TOUT228 input func */
  {174U, 4U},
  /* INMUX settings for pad PORT175:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN7_5 input func */
  {175U, 1U},
  /* GTM_TIM4_IN7_7 input func */
  {175U, 2U},
  /* GTM_TOUT229 input func */
  {175U, 4U},
  /* INMUX settings for pad PORT176:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN0_5 input func */
  {176U, 1U},
  /* GTM_TIM5_IN0_5 input func */
  {176U, 2U},
  /* SDADC_0_EM_CLK_SDADC0 input func */
  {176U, 9U},
  /* GTM_TOUT230 input func */
  {176U, 4U},
  /* SAR_ADC45_SAR_ADC45_MA2 input func */
  {176U, 7U},
  /* INMUX settings for pad PORT177:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN1_5 input func */
  {177U, 1U},
  /* GTM_TIM5_IN1_6 input func */
  {177U, 2U},
  /* SDADC_0_EM_BS1_SDADC0 input func */
  {177U, 9U},
  /* GTM_TOUT231 input func */
  {177U, 4U},
  /* SAR_ADC45_SAR_ADC45_MA1 input func */
  {177U, 7U},
  /* INMUX settings for pad PORT178:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN2_4 input func */
  {178U, 1U},
  /* GTM_TIM5_IN2_5 input func */
  {178U, 2U},
  /* SDADC_0_EM_BS2_SDADC0 input func */
  {178U, 9U},
  /* GTM_TOUT232 input func */
  {178U, 4U},
  /* SAR_ADC45_SAR_ADC45_MA0 input func */
  {178U, 7U},
  /* INMUX settings for pad PORT179:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN3_4 input func */
  {179U, 1U},
  /* GTM_TIM5_IN3_6 input func */
  {179U, 2U},
  /* SDADC_1_EM_CLK_SDADC1 input func */
  {179U, 9U},
  /* GTM_TOUT233 input func */
  {179U, 4U},
  /* SAR_ADC89_SAR_ADC89_MA2 input func */
  {179U, 7U},
  /* INMUX settings for pad PORT180:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN4_3 input func */
  {180U, 1U},
  /* GTM_TIM5_IN4_6 input func */
  {180U, 2U},
  /* SDADC_1_EM_BS1_SDADC1 input func */
  {180U, 9U},
  /* GTM_TOUT234 input func */
  {180U, 4U},
  /* SAR_ADC89_SAR_ADC89_MA1 input func */
  {180U, 7U},
  /* INMUX settings for pad PORT181:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN5_3 input func */
  {181U, 1U},
  /* GTM_TIM5_IN5_6 input func */
  {181U, 2U},
  /* SDADC_1_EM_BS2_SDADC1 input func */
  {181U, 9U},
  /* GTM_TOUT235 input func */
  {181U, 4U},
  /* SAR_ADC89_SAR_ADC89_MA0 input func */
  {181U, 7U},
  /* INMUX settings for pad PORT182:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN7_3 input func */
  {182U, 1U},
  /* GTM_TIM7_IN6_3 input func */
  {182U, 2U},
  /* GTM_TIM5_IN6_6 input func */
  {182U, 3U},
  /* SDADC_2_EM_CLK_SDADC2 input func */
  {182U, 9U},
  /* GTM_TOUT236 input func */
  {182U, 5U},
  /* CSENT_CSENT0_TXD0 input func */
  {182U, 7U},
  /* INMUX settings for pad PORT183:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN7_2 input func */
  {183U, 1U},
  /* GTM_TIM5_IN7_5 input func */
  {183U, 2U},
  /* SDADC_2_EM_BS1_SDADC2 input func */
  {183U, 9U},
  /* GTM_TOUT237 input func */
  {183U, 4U},
  /* CSENT_CSENT0_TXD1 input func */
  {183U, 7U},
  /* INMUX settings for pad PORT184:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN0_7 input func */
  {184U, 1U},
  /* GTM_TIM3_IN0_12 input func */
  {184U, 2U},
  /* SDADC_2_EM_BS2_SDADC2 input func */
  {184U, 9U},
  /* GTM_TOUT206 input func */
  {184U, 3U},
  /* CSENT_CSENT0_TXD2 input func */
  {184U, 7U},
  /* INMUX settings for pad PORT185:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN1_7 input func */
  {185U, 1U},
  /* GTM_TIM3_IN1_11 input func */
  {185U, 2U},
  /* SDADC_3_EM_CLK_SDADC3 input func */
  {185U, 9U},
  /* GTM_TOUT207 input func */
  {185U, 4U},
  /* CSENT_CSENT0_TXD3 input func */
  {185U, 7U},
  /* INMUX settings for pad PORT186:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN2_7 input func */
  {186U, 1U},
  /* GTM_TIM3_IN2_9 input func */
  {186U, 2U},
  /* SDADC_3_EM_BS1_SDADC3 input func */
  {186U, 9U},
  /* GTM_TOUT208 input func */
  {186U, 4U},
  /* CSENT_CSENT0_TXD4 input func */
  {186U, 7U},
  /* INMUX settings for pad PORT187:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN3_7 input func */
  {187U, 1U},
  /* GTM_TIM3_IN3_9 input func */
  {187U, 2U},
  /* SDADC_3_EM_BS2_SDADC3 input func */
  {187U, 9U},
  /* GTM_TOUT209 input func */
  {187U, 4U},
  /* CSENT_CSENT0_TXD5 input func */
  {187U, 7U},
  /* INMUX settings for pad PORT188:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN4_6 input func */
  {188U, 1U},
  /* GTM_TIM3_IN4_10 input func */
  {188U, 2U},
  /* SDADC_4_EM_CLK_SDADC4 input func */
  {188U, 9U},
  /* GTM_TOUT210 input func */
  {188U, 4U},
  /* CSENT_CSENT0_TXD6 input func */
  {188U, 7U},
  /* INMUX settings for pad PORT189:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN5_6 input func */
  {189U, 1U},
  /* GTM_TIM3_IN5_11 input func */
  {189U, 2U},
  /* SDADC_4_EM_BS1_SDADC4 input func */
  {189U, 9U},
  /* GTM_TOUT211 input func */
  {189U, 4U},
  /* CSENT_CSENT0_TXD7 input func */
  {189U, 7U},
  /* INMUX settings for pad PORT190:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN6_6 input func */
  {190U, 1U},
  /* GTM_TIM3_IN6_14 input func */
  {190U, 2U},
  /* SDADC_4_EM_BS2_SDADC4 input func */
  {190U, 9U},
  /* GTM_TOUT212 input func */
  {190U, 4U},
  /* CSENT_CSENT0_TXD8 input func */
  {190U, 7U},
  /* INMUX settings for pad PORT191:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN7_6 input func */
  {191U, 1U},
  /* GTM_TIM3_IN7_10 input func */
  {191U, 2U},
  /* SDADC_5_EM_CLK_SDADC5 input func */
  {191U, 9U},
  /* GTM_TOUT213 input func */
  {191U, 4U},
  /* CSENT_CSENT0_TXD9 input func */
  {191U, 7U},
  /* INMUX settings for pad PORT192:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN0_6 input func */
  {192U, 1U},
  /* GTM_TIM4_IN0_9 input func */
  {192U, 2U},
  /* EMIOS_EMIOS_8 input func */
  {192U, 6U},
  /* SIUL_EPORT0 input func */
  {192U, 7U},
  /* SDADC_5_EM_BS1_SDADC5 input func */
  {192U, 9U},
  /* GTM_TOUT214 input func */
  {192U, 3U},
  /* EMIOS_EMIOS_8 input func */
  {192U, 6U},
  /* INMUX settings for pad PORT193:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN1_6 input func */
  {193U, 1U},
  /* GTM_TIM4_IN1_9 input func */
  {193U, 2U},
  /* EMIOS_EMIOS_9 input func */
  {193U, 6U},
  /* SIUL_EPORT1 input func */
  {193U, 7U},
  /* SDADC_5_EM_BS2_SDADC5 input func */
  {193U, 9U},
  /* GTM_TOUT215 input func */
  {193U, 3U},
  /* EMIOS_EMIOS_9 input func */
  {193U, 6U},
  /* INMUX settings for pad PORT194:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN2_5 input func */
  {194U, 1U},
  /* GTM_TIM4_IN2_9 input func */
  {194U, 2U},
  /* EMIOS_EMIOS_10 input func */
  {194U, 6U},
  /* SIUL_EPORT2 input func */
  {194U, 7U},
  /* SDADC_6_EM_CLK_SDADC6 input func */
  {194U, 9U},
  /* GTM_TOUT216 input func */
  {194U, 3U},
  /* EMIOS_EMIOS_10 input func */
  {194U, 6U},
  /* INMUX settings for pad PORT195:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN3_5 input func */
  {195U, 1U},
  /* GTM_TIM4_IN3_9 input func */
  {195U, 2U},
  /* EMIOS_EMIOS_11 input func */
  {195U, 6U},
  /* SIUL_EPORT3 input func */
  {195U, 7U},
  /* SDADC_6_EM_BS1_SDADC6 input func */
  {195U, 9U},
  /* GTM_TOUT217 input func */
  {195U, 3U},
  /* EMIOS_EMIOS_11 input func */
  {195U, 6U},
  /* INMUX settings for pad PORT196:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN4_4 input func */
  {196U, 1U},
  /* GTM_TIM4_IN4_8 input func */
  {196U, 2U},
  /* EMIOS_EMIOS_12 input func */
  {196U, 6U},
  /* SIUL_EPORT4 input func */
  {196U, 7U},
  /* SDADC_6_EM_BS2_SDADC6 input func */
  {196U, 9U},
  /* GTM_TOUT218 input func */
  {196U, 3U},
  /* EMIOS_EMIOS_12 input func */
  {196U, 6U},
  /* INMUX settings for pad PORT197:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN5_4 input func */
  {197U, 1U},
  /* GTM_TIM4_IN5_8 input func */
  {197U, 2U},
  /* EMIOS_EMIOS_13 input func */
  {197U, 6U},
  /* SIUL_EPORT5 input func */
  {197U, 7U},
  /* SDADC_7_EM_CLK_SDADC7 input func */
  {197U, 9U},
  /* GTM_TOUT219 input func */
  {197U, 3U},
  /* EMIOS_EMIOS_13 input func */
  {197U, 6U},
  /* INMUX settings for pad PORT198:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN6_4 input func */
  {198U, 1U},
  /* GTM_TIM4_IN6_8 input func */
  {198U, 2U},
  /* EMIOS_EMIOS_14 input func */
  {198U, 6U},
  /* SIUL_EPORT6 input func */
  {198U, 7U},
  /* SDADC_7_EM_BS1_SDADC7 input func */
  {198U, 9U},
  /* GTM_TOUT220 input func */
  {198U, 3U},
  /* EMIOS_EMIOS_14 input func */
  {198U, 6U},
  /* INMUX settings for pad PORT199:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN7_8 input func */
  {199U, 1U},
  /* EMIOS_EMIOS_15 input func */
  {199U, 6U},
  /* SIUL_EPORT7 input func */
  {199U, 7U},
  /* SDADC_7_EM_BS2_SDADC7 input func */
  {199U, 9U},
  /* GTM_TOUT221 input func */
  {199U, 2U},
  /* EMIOS_EMIOS_15 input func */
  {199U, 6U},
  /* INMUX settings for pad PORT200:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN6_9 input func */
  {200U, 1U},
  /* GTM_TIM3_IN6_11 input func */
  {200U, 2U},
  /* EMIOS_EMIOS_25 input func */
  {200U, 6U},
  /* SIUL_EPORT8 input func */
  {200U, 7U},
  /* SDADC_8_EM_CLK_SDADC8 input func */
  {200U, 9U},
  /* GTM_TOUT212 input func */
  {200U, 4U},
  /* EMIOS_EMIOS_25 input func */
  {200U, 6U},
  /* INMUX settings for pad PORT201:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN0_7 input func */
  {201U, 1U},
  /* GTM_TIM4_IN0_10 input func */
  {201U, 2U},
  /* EMIOS_EMIOS_26 input func */
  {201U, 6U},
  /* SIUL_EPORT9 input func */
  {201U, 7U},
  /* SDADC_8_EM_BS1_SDADC8 input func */
  {201U, 9U},
  /* GTM_TOUT190 input func */
  {201U, 4U},
  /* EMIOS_EMIOS_26 input func */
  {201U, 6U},
  /* INMUX settings for pad PORT202:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN1_7 input func */
  {202U, 1U},
  /* GTM_TIM4_IN1_10 input func */
  {202U, 2U},
  /* EMIOS_EMIOS_27 input func */
  {202U, 6U},
  /* SIUL_EPORT10 input func */
  {202U, 7U},
  /* SDADC_8_EM_BS2_SDADC8 input func */
  {202U, 9U},
  /* GTM_TOUT191 input func */
  {202U, 4U},
  /* EMIOS_EMIOS_27 input func */
  {202U, 6U},
  /* INMUX settings for pad PORT203:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN2_6 input func */
  {203U, 1U},
  /* GTM_TIM4_IN2_10 input func */
  {203U, 2U},
  /* EMIOS_EMIOS_28 input func */
  {203U, 6U},
  /* SIUL_EPORT11 input func */
  {203U, 7U},
  /* SDADC_9_EM_CLK_SDADC9 input func */
  {203U, 9U},
  /* GTM_TOUT192 input func */
  {203U, 4U},
  /* EMIOS_EMIOS_28 input func */
  {203U, 6U},
  /* INMUX settings for pad PORT204:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN3_6 input func */
  {204U, 1U},
  /* GTM_TIM4_IN3_10 input func */
  {204U, 2U},
  /* EMIOS_EMIOS_29 input func */
  {204U, 6U},
  /* SIUL_EPORT12 input func */
  {204U, 7U},
  /* SDADC_9_EM_BS1_SDADC9 input func */
  {204U, 9U},
  /* GTM_TOUT193 input func */
  {204U, 4U},
  /* EMIOS_EMIOS_29 input func */
  {204U, 6U},
  /* INMUX settings for pad PORT205:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN4_5 input func */
  {205U, 1U},
  /* GTM_TIM4_IN4_9 input func */
  {205U, 2U},
  /* EMIOS_EMIOS_30 input func */
  {205U, 6U},
  /* SIUL_EPORT13 input func */
  {205U, 7U},
  /* SDADC_9_EM_BS2_SDADC9 input func */
  {205U, 9U},
  /* GTM_TOUT194 input func */
  {205U, 4U},
  /* EMIOS_EMIOS_30 input func */
  {205U, 6U},
  /* INMUX settings for pad PORT206:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN5_5 input func */
  {206U, 1U},
  /* GTM_TIM4_IN5_9 input func */
  {206U, 2U},
  /* EMIOS_EMIOS_31 input func */
  {206U, 6U},
  /* SIUL_EPORT14 input func */
  {206U, 7U},
  /* SDADC_10_EM_CLK_SDADC10 input func */
  {206U, 9U},
  /* GTM_TOUT195 input func */
  {206U, 4U},
  /* EMIOS_EMIOS_31 input func */
  {206U, 6U},
  /* INMUX settings for pad PORT207:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN6_5 input func */
  {207U, 1U},
  /* GTM_TIM4_IN6_9 input func */
  {207U, 2U},
  /* LINFLEX12_LIN12_RX input func */
  {207U, 6U},
  /* SIUL_EPORT15 input func */
  {207U, 7U},
  /* SDADC_10_EM_BS1_SDADC10 input func */
  {207U, 9U},
  /* GTM_TOUT196 input func */
  {207U, 4U},
  /* INMUX settings for pad PORT208:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN7_4 input func */
  {208U, 1U},
  /* GTM_TIM4_IN7_9 input func */
  {208U, 2U},
  /* SIUL_EPORT16 input func */
  {208U, 7U},
  /* SDADC_10_EM_BS2_SDADC10 input func */
  {208U, 9U},
  /* GTM_TOUT197 input func */
  {208U, 4U},
  /* LINFLEX12_LIN12_TX input func */
  {208U, 6U},
  /* INMUX settings for pad PORT209:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN0_8 input func */
  {209U, 1U},
  /* GTM_TIM5_IN0_6 input func */
  {209U, 2U},
  /* LINFLEX14_LIN14_RX input func */
  {209U, 6U},
  /* SIUL_EPORT17 input func */
  {209U, 7U},
  /* SDADC_11_EM_CLK_SDADC11 input func */
  {209U, 9U},
  /* GTM_TOUT198 input func */
  {209U, 4U},
  /* INMUX settings for pad PORT210:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN1_8 input func */
  {210U, 1U},
  /* GTM_TIM5_IN1_7 input func */
  {210U, 2U},
  /* SIUL_EPORT18 input func */
  {210U, 7U},
  /* SDADC_11_EM_BS1_SDADC11 input func */
  {210U, 9U},
  /* GTM_TOUT199 input func */
  {210U, 4U},
  /* LINFLEX14_LIN14_TX input func */
  {210U, 6U},
  /* INMUX settings for pad PORT211:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN2_8 input func */
  {211U, 1U},
  /* GTM_TIM5_IN2_6 input func */
  {211U, 2U},
  /* LINFLEX15_LIN15_RX input func */
  {211U, 6U},
  /* SIUL_EPORT19 input func */
  {211U, 7U},
  /* SDADC_11_EM_BS2_SDADC11 input func */
  {211U, 9U},
  /* GTM_TOUT200 input func */
  {211U, 4U},
  /* INMUX settings for pad PORT212:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN3_8 input func */
  {212U, 1U},
  /* GTM_TIM5_IN3_7 input func */
  {212U, 2U},
  /* SIUL_EPORT20 input func */
  {212U, 7U},
  /* SDADC_12_EM_CLK_SDADC12 input func */
  {212U, 9U},
  /* GTM_TOUT201 input func */
  {212U, 4U},
  /* LINFLEX15_LIN15_TX input func */
  {212U, 6U},
  /* INMUX settings for pad PORT213:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN4_7 input func */
  {213U, 1U},
  /* GTM_TIM5_IN4_7 input func */
  {213U, 2U},
  /* LINFLEX16_LIN16_RX input func */
  {213U, 6U},
  /* SIUL_EPORT21 input func */
  {213U, 7U},
  /* SDADC_12_EM_BS1_SDADC12 input func */
  {213U, 9U},
  /* GTM_TOUT202 input func */
  {213U, 4U},
  /* INMUX settings for pad PORT214:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN5_7 input func */
  {214U, 1U},
  /* GTM_TIM5_IN5_7 input func */
  {214U, 2U},
  /* SIUL_EPORT22 input func */
  {214U, 7U},
  /* SDADC_12_EM_BS2_SDADC12 input func */
  {214U, 9U},
  /* GTM_TOUT203 input func */
  {214U, 4U},
  /* LINFLEX16_LIN16_TX input func */
  {214U, 6U},
  /* INMUX settings for pad PORT215:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN6_7 input func */
  {215U, 1U},
  /* GTM_TIM5_IN6_7 input func */
  {215U, 2U},
  /* SIUL_EPORT23 input func */
  {215U, 7U},
  /* SDADC_13_EM_CLK_SDADC13 input func */
  {215U, 9U},
  /* GTM_TOUT204 input func */
  {215U, 4U},
  /* INMUX settings for pad PORT216:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN7_7 input func */
  {216U, 1U},
  /* GTM_TIM5_IN7_6 input func */
  {216U, 2U},
  /* PASS_PASS_BAF_PLOCK input func */
  {216U, 7U},
  /* SDADC_13_EM_BS1_SDADC13 input func */
  {216U, 9U},
  /* GTM_TOUT205 input func */
  {216U, 4U},
  /* INMUX settings for pad PORT217:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN0_8 input func */
  {217U, 1U},
  /* GTM_TIM2_IN0_13 input func */
  {217U, 2U},
  /* SDADC_13_EM_BS2_SDADC13 input func */
  {217U, 9U},
  /* GTM_TOUT174 input func */
  {217U, 4U},
  /* MC_CGL_EBI_CLKOUT input func */
  {217U, 7U},
  /* INMUX settings for pad PORT218:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN1_8 input func */
  {218U, 1U},
  /* GTM_TIM2_IN1_9 input func */
  {218U, 2U},
  /* TTCAN0_TTCAN0_RX input func */
  {218U, 9U},
  /* GTM_TOUT175 input func */
  {218U, 4U},
  /* MC_CGL_SYS_CLK0 input func */
  {218U, 7U},
  /* INMUX settings for pad PORT219:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN2_7 input func */
  {219U, 1U},
  /* GTM_TIM2_IN2_9 input func */
  {219U, 2U},
  /* GTM_TOUT176 input func */
  {219U, 4U},
  /* MC_CGL_SYS_CLK1 input func */
  {219U, 7U},
  /* TTCAN0_TTCAN0_TX input func */
  {219U, 9U},
  /* INMUX settings for pad PORT220:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN3_7 input func */
  {220U, 1U},
  /* GTM_TIM2_IN3_14 input func */
  {220U, 2U},
  /* TTCAN1_TTCAN1_RX input func */
  {220U, 9U},
  /* GTM_TOUT177 input func */
  {220U, 4U},
  /* MC_CGL_CDM input func */
  {220U, 7U},
  /* INMUX settings for pad PORT221:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN4_6 input func */
  {221U, 1U},
  /* GTM_TIM2_IN4_12 input func */
  {221U, 2U},
  /* GTM_TOUT178 input func */
  {221U, 4U},
  /* MC_CGL_FEC_REF_CLK input func */
  {221U, 7U},
  /* TTCAN1_TTCAN1_TX input func */
  {221U, 9U},
  /* INMUX settings for pad PORT222:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN5_6 input func */
  {222U, 1U},
  /* GTM_TIM2_IN5_13 input func */
  {222U, 2U},
  /* TTCAN2_TTCAN2_RX input func */
  {222U, 9U},
  /* GTM_TOUT179 input func */
  {222U, 4U},
  /* INMUX settings for pad PORT223:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN6_6 input func */
  {223U, 1U},
  /* GTM_TIM2_IN6_12 input func */
  {223U, 2U},
  /* GTM_TOUT180 input func */
  {223U, 4U},
  /* TTCAN2_TTCAN2_TX input func */
  {223U, 9U},
  /* INMUX settings for pad PORT224:      {INMUX reg, PADSEL val} */
  /* GTM_TIM7_IN7_5 input func */
  {224U, 1U},
  /* GTM_TIM2_IN7_14 input func */
  {224U, 2U},
  /* GTM_TOUT181 input func */
  {224U, 4U},
  /* INMUX settings for pad PORT225:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN0_9 input func */
  {225U, 1U},
  /* GTM_TIM5_IN0_7 input func */
  {225U, 2U},
  /* SENT_SENT_SENT20C input func */
  {225U, 4U},
  /* GTM_TOUT182 input func */
  {225U, 5U},
  /* INMUX settings for pad PORT226:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN1_9 input func */
  {226U, 1U},
  /* GTM_TIM5_IN1_8 input func */
  {226U, 2U},
  /* SENT_SENT_SENT21C input func */
  {226U, 4U},
  /* GTM_TOUT183 input func */
  {226U, 5U},
  /* INMUX settings for pad PORT227:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN2_9 input func */
  {227U, 1U},
  /* GTM_TIM5_IN2_7 input func */
  {227U, 2U},
  /* SENT_SENT_SENT22C input func */
  {227U, 4U},
  /* GTM_TOUT184 input func */
  {227U, 5U},
  /* INMUX settings for pad PORT228:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN3_9 input func */
  {228U, 1U},
  /* GTM_TIM5_IN3_8 input func */
  {228U, 2U},
  /* SENT_SENT_SENT23C input func */
  {228U, 4U},
  /* GTM_TOUT185 input func */
  {228U, 5U},
  /* INMUX settings for pad PORT229:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN4_8 input func */
  {229U, 1U},
  /* GTM_TIM5_IN4_8 input func */
  {229U, 2U},
  /* SENT_SENT_SENT24C input func */
  {229U, 4U},
  /* GTM_TOUT186 input func */
  {229U, 5U},
  /* INMUX settings for pad PORT230:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN5_8 input func */
  {230U, 1U},
  /* GTM_TIM5_IN5_8 input func */
  {230U, 2U},
  /* GTM_TOUT187 input func */
  {230U, 4U},
  /* INMUX settings for pad PORT231:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN6_8 input func */
  {231U, 1U},
  /* GTM_TIM5_IN6_8 input func */
  {231U, 2U},
  /* GTM_TOUT188 input func */
  {231U, 4U},
  /* INMUX settings for pad PORT232:      {INMUX reg, PADSEL val} */
  /* GTM_TIM6_IN7_8 input func */
  {232U, 1U},
  /* GTM_TIM5_IN7_7 input func */
  {232U, 2U},
  /* GTM_TOUT189 input func */
  {232U, 4U},
  /* INMUX settings for pad PORT233:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN2_5 input func */
  {233U, 1U},
  /* GTM_TIM2_IN2_5 input func */
  {233U, 2U},
  /* GTM_TOUT36 input func */
  {233U, 3U},
  /* INMUX settings for pad PORT234:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN3_15 input func */
  {234U, 1U},
  /* GTM_TOUT37 input func */
  {234U, 2U},
  /* INMUX settings for pad PORT235:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN3_8 input func */
  {235U, 1U},
  /* GTM_TIM0_IN3_8 input func */
  {235U, 2U},
  /* M_CAN_4_CAN03_RXDB input func */
  {235U, 3U},
  /* LINFLEX3_LIN3_RX input func */
  {235U, 4U},
  /* DSPI3_DSPI3_SIND input func */
  {235U, 5U},
  /* M_CAN_10_CAN21_RXDD input func */
  {235U, 6U},
  /* GTM_TOUT38 input func */
  {235U, 7U},
  /* LINFLEX3_LIN3_TX input func */
  {235U, 8U},
  /* DSPI3_DSPI3_SOUT input func */
  {235U, 9U},
  /* INMUX settings for pad PORT236:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN4_5 input func */
  {236U, 1U},
  /* GTM_TIM0_IN4_5 input func */
  {236U, 2U},
  /* DSPI3_DSPI3_SCK input func */
  {236U, 7U},
  /* GTM_TOUT39 input func */
  {236U, 3U},
  /* LINFLEX3_LIN3_TX input func */
  {236U, 4U},
  /* DSPI3_DSPI3_SOUT input func */
  {236U, 5U},
  /* M_CAN_4_CAN03_TXD input func */
  {236U, 8U},
  /* M_CAN_10_CAN21_TXD input func */
  {236U, 9U},
  /* INMUX settings for pad PORT237:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN5_5 input func */
  {237U, 1U},
  /* GTM_TIM0_IN5_5 input func */
  {237U, 2U},
  /* DSPI13_DSPI13_SIN input func */
  {237U, 4U},
  /* GTM_TOUT40 input func */
  {237U, 5U},
  /* GTM_CLK1 input func */
  {237U, 6U},
  /* DSPI13_DSPI13_PCS0 input func */
  {237U, 7U},
  /* EMIOS_EMIOS_20 input func */
  {237U, 9U},
  /* INMUX settings for pad PORT238:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN5_9 input func */
  {238U, 1U},
  /* GTM_TIM4_IN1_14 input func */
  {238U, 2U},
  /* GTM_TIM3_IN5_8 input func */
  {238U, 3U},
  /* SENT_SENT_SENT10C input func */
  {238U, 4U},
  /* GTM_TOUT140 input func */
  {238U, 5U},
  /* LINFLEX2_LIN2_TX input func */
  {238U, 6U},
  /* DSPI2_DSPI2_SOUT input func */
  {238U, 7U},
  /* M_CAN_3_CAN02_TXD input func */
  {238U, 8U},
  /* INMUX settings for pad PORT239:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN6_9 input func */
  {239U, 1U},
  /* GTM_TIM4_IN4_15 input func */
  {239U, 2U},
  /* GTM_TIM3_IN6_8 input func */
  {239U, 3U},
  /* M_CAN_3_CAN02_RXDC input func */
  {239U, 4U},
  /* LINFLEX2_LIN2_RX input func */
  {239U, 6U},
  /* DSPI2_DSPI2_SINF input func */
  {239U, 7U},
  /* LINFLEX6_LIN6_RX input func */
  {239U, 8U},
  /* DSPI6_DSPI6_SINC input func */
  {239U, 9U},
  /* SENT_SENT_SENT11C input func */
  {239U, 10U},
  /* GTM_TOUT141 input func */
  {239U, 11U},
  /* M_CAN_11_CAN22_TXD input func */
  {239U, 13U},
  /* INMUX settings for pad PORT240:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN7_8 input func */
  {240U, 1U},
  /* GTM_TIM4_IN0_15 input func */
  {240U, 2U},
  /* GTM_TIM3_IN7_8 input func */
  {240U, 3U},
  /* M_CAN_11_CAN22_RXDB input func */
  {240U, 5U},
  /* SENT_SENT_SENT12C input func */
  {240U, 6U},
  /* SPORTA_SPORTA_CLK input func */
  {240U, 11U},
  /* GTM_TOUT142 input func */
  {240U, 7U},
  /* LINFLEX6_LIN6_TX input func */
  {240U, 8U},
  /* DSPI6_DSPI6_SOUT input func */
  {240U, 9U},
  /* SPORTA_SPORTA_CLK input func */
  {240U, 11U},
  /* INMUX settings for pad PORT241:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN0_13 input func */
  {241U, 1U},
  /* GTM_TIM1_IN4_6 input func */
  {241U, 2U},
  /* GTM_TIM0_IN4_6 input func */
  {241U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR0E input func */
  {241U, 4U},
  /* SENT_SENT_SENT13C input func */
  {241U, 5U},
  /* GTM_DTMT1_2 input func */
  {241U, 6U},
  /* SPORTA_SPORTA_FS input func */
  {241U, 12U},
  /* GTM_TOUT22 input func */
  {241U, 8U},
  /* LINFLEX5_LIN5_TX input func */
  {241U, 9U},
  /* DSPI5_DSPI5_SOUT input func */
  {241U, 10U},
  /* ACMP2_EVADC_FC2BFLOUT input func */
  {241U, 11U},
  /* SPORTA_SPORTA_FS input func */
  {241U, 12U},
  /* INMUX settings for pad PORT242:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN1_15 input func */
  {242U, 1U},
  /* GTM_TIM1_IN5_6 input func */
  {242U, 2U},
  /* GTM_TIM0_IN5_6 input func */
  {242U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR1E input func */
  {242U, 4U},
  /* PSI5_PSI5_RX0C input func */
  {242U, 5U},
  /* SENT_SENT_SENT9C input func */
  {242U, 7U},
  /* LINFLEX8_LIN8_RX input func */
  {242U, 8U},
  /* DSPI8_DSPI8_SINC input func */
  {242U, 9U},
  /* DSPI3_DSPI3_PCS0 input func */
  {242U, 13U},
  /* SPORTA_SPORTA_D0 input func */
  {242U, 2U},
  /* GTM_TOUT23 input func */
  {242U, 11U},
  /* DSPI3_DSPI3_PCS0 input func */
  {242U, 13U},
  /* ACMP4_EVADC_FC4BFLOUT input func */
  {242U, 1U},
  /* SPORTA_SPORTA_D0 input func */
  {242U, 2U},
  /* INMUX settings for pad PORT243:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN2_14 input func */
  {243U, 1U},
  /* GTM_TIM1_IN6_6 input func */
  {243U, 2U},
  /* GTM_TIM0_IN6_6 input func */
  {243U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR2E input func */
  {243U, 4U},
  /* SENT_SENT_SENT8C input func */
  {243U, 5U},
  /* DSPI3_DSPI3_SCK input func */
  {243U, 10U},
  /* SPORTA_SPORTA_D1 input func */
  {243U, 15U},
  /* GTM_TOUT24 input func */
  {243U, 8U},
  /* PSI5_PSI5_TX0 input func */
  {243U, 12U},
  /* ACMP3_EVADC_FC3BFLOUT input func */
  {243U, 14U},
  /* SPORTA_SPORTA_D1 input func */
  {243U, 15U},
  /* INMUX settings for pad PORT244:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN3_12 input func */
  {244U, 1U},
  /* GTM_TIM1_IN7_6 input func */
  {244U, 2U},
  /* GTM_TIM0_IN7_6 input func */
  {244U, 3U},
  /* PSI5_PSI5_RX1C input func */
  {244U, 4U},
  /* SENT_SENT_SENT7C input func */
  {244U, 5U},
  /* DSPI5_DSPI5_SCK input func */
  {244U, 10U},
  /* GTM_TOUT25 input func */
  {244U, 8U},
  /* DSPI20_DSPI20_PCS2 input func */
  {244U, 11U},
  /* ACMP5_EVADC_FC5BFLOUT input func */
  {244U, 14U},
  /* SPORTA_SPORTA_TDV input func */
  {244U, 15U},
  /* INMUX settings for pad PORT245:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN4_10 input func */
  {245U, 1U},
  /* GTM_TIM1_IN0_10 input func */
  {245U, 2U},
  /* GTM_TIM0_IN0_10 input func */
  {245U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR0F input func */
  {245U, 4U},
  /* SENT_SENT_SENT6C input func */
  {245U, 5U},
  /* EMIOS_emios_odis input func */
  {245U, 7U},
  /* LINFLEX5_LIN5_RX input func */
  {245U, 8U},
  /* DSPI5_DSPI5_SINB input func */
  {245U, 9U},
  /* GTM_DTMT2_0 input func */
  {245U, 10U},
  /* SPORTB_SPORTB_CLK input func */
  {245U, 2U},
  /* GTM_TOUT26 input func */
  {245U, 11U},
  /* PSI5_PSI5_TX1 input func */
  {245U, 14U},
  /* ACMP0_EVADC_FC0BFLOUT input func */
  {245U, 0U},
  /* M_CAN_8_CAN13_TXD input func */
  {245U, 1U},
  /* SPORTB_SPORTB_CLK input func */
  {245U, 2U},
  /* INMUX settings for pad PORT246:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN5_10 input func */
  {246U, 1U},
  /* GTM_TIM1_IN1_8 input func */
  {246U, 2U},
  /* GTM_TIM0_IN1_8 input func */
  {246U, 3U},
  /* SAR_ADC_SDADC_EDSADC_ITR1F input func */
  {246U, 5U},
  /* PSI5S_PSI5S_RXC input func */
  {246U, 7U},
  /* EMIOS_EMIOS_19 input func */
  {246U, 9U},
  /* PSI5_PSI5_RX2C input func */
  {246U, 10U},
  /* SENT_SENT_SENT5C input func */
  {246U, 11U},
  /* M_CAN_8_CAN13_RXDB input func */
  {246U, 12U},
  /* DSPI5_DSPI5_PCS0 input func */
  {246U, 4U},
  /* GTM_TOUT27 input func */
  {246U, 13U},
  /* DSPI16_DSPI16_PCS7 input func */
  {246U, 14U},
  /* DSPI17_DSPI17_PCS7 input func */
  {246U, 15U},
  /* ACMP2_EVADC_FC2BFLOUT input func */
  {246U, 2U},
  /* DSPI5_DSPI5_PCS0 input func */
  {246U, 4U},
  /* INMUX settings for pad PORT247:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN2_9 input func */
  {247U, 1U},
  /* GTM_TIM0_IN2_9 input func */
  {247U, 2U},
  /* SAR_ADC_SDADC_EDSADC_ITR2F input func */
  {247U, 3U},
  /* SENT_SENT_SENT4C input func */
  {247U, 5U},
  /* EMIOS_EMIOS_18 input func */
  {247U, 6U},
  /* LINFLEX8_LIN8_RX input func */
  {247U, 8U},
  /* DSPI8_DSPI8_SIND input func */
  {247U, 9U},
  /* GTM_DTMT2_1 input func */
  {247U, 10U},
  /* DSPI2_DSPI2_PCS0 input func */
  {247U, 13U},
  /* SPORTB_SPORTB_D0 input func */
  {247U, 3U},
  /* GTM_TOUT28 input func */
  {247U, 11U},
  /* DSPI2_DSPI2_PCS0 input func */
  {247U, 13U},
  /* PSI5_PSI5_TX2 input func */
  {247U, 15U},
  /* ACMP1_EVADC_FC1BFLOUT input func */
  {247U, 1U},
  /* PSI5S_PSI5S_TX input func */
  {247U, 2U},
  /* SPORTB_SPORTB_D0 input func */
  {247U, 3U},
  /* INMUX settings for pad PORT248:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN3_9 input func */
  {248U, 1U},
  /* GTM_TIM0_IN3_9 input func */
  {248U, 2U},
  /* M_CAN_1_CAN00_RXDE input func */
  {248U, 3U},
  /* EMIOS_EMIOS_20 input func */
  {248U, 4U},
  /* EMIOS_EMIOS_17 input func */
  {248U, 5U},
  /* SENT_SENT_SENT14C input func */
  {248U, 7U},
  /* DSPI2_DSPI2_SCK input func */
  {248U, 10U},
  /* SPORTB_SPORTB_D1 input func */
  {248U, 15U},
  /* GTM_TOUT29 input func */
  {248U, 8U},
  /* DSPI20_DSPI20_PCS7 input func */
  {248U, 11U},
  /* LINFLEX8_LIN8_TX input func */
  {248U, 12U},
  /* DSPI8_DSPI8_SOUT input func */
  {248U, 13U},
  /* ACMP3_EVADC_FC3BFLOUT input func */
  {248U, 14U},
  /* SPORTB_SPORTB_D1 input func */
  {248U, 15U},
  /* INMUX settings for pad PORT249:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN4_7 input func */
  {249U, 1U},
  /* GTM_TIM0_IN4_7 input func */
  {249U, 2U},
  /* LINFLEX2_LIN2_RX input func */
  {249U, 3U},
  /* DSPI2_DSPI2_SINE input func */
  {249U, 4U},
  /* FCCU_FCCU_EIN input func */
  {249U, 12U},
  /* GTM_TOUT30 input func */
  {249U, 6U},
  /* LINFLEX2_LIN2_TX input func */
  {249U, 7U},
  /* DSPI2_DSPI2_SOUT input func */
  {249U, 8U},
  /* DSPI20_DSPI20_PCS2 input func */
  {249U, 9U},
  /* M_CAN_1_CAN00_TXD input func */
  {249U, 10U},
  /* EMIOS_EMIOS_19 input func */
  {249U, 11U},
  /* FCCU_FCCU_EOUT input func */
  {249U, 12U},
  /* SPORTB_SPORTB_TDV input func */
  {249U, 13U},
  /* INMUX settings for pad PORT250:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN1_9 input func */
  {250U, 1U},
  /* GTM_TIM0_IN1_9 input func */
  {250U, 2U},
  /* DSPI2_DSPI2_SCK input func */
  {250U, 9U},
  /* SPORTB_SPORTB_FS input func */
  {250U, 14U},
  /* PWM_PWM0_IN input func */
  {250U, 15U},
  /* GTM_TOUT31 input func */
  {250U, 4U},
  /* LINFLEX2_LIN2_TX input func */
  {250U, 5U},
  /* DSPI2_DSPI2_SOUT input func */
  {250U, 6U},
  /* DSPI20_DSPI20_PCS1 input func */
  {250U, 7U},
  /* M_CAN_2_CAN01_TXD input func */
  {250U, 10U},
  /* LINFLEX0_LIN0_TX input func */
  {250U, 11U},
  /* DSPI10_DSPI10_SOUT input func */
  {250U, 12U},
  /* EMIOS_EMIOS_18 input func */
  {250U, 13U},
  /* SPORTB_SPORTB_FS input func */
  {250U, 14U},
  /* PWM_PWM0_OUT input func */
  {250U, 15U},
  /* INMUX settings for pad PORT251:      {INMUX reg, PADSEL val} */
  /* GTM_TIM4_IN4_14 input func */
  {251U, 1U},
  /* GTM_TIM1_IN0_9 input func */
  {251U, 2U},
  /* GTM_TIM0_IN0_9 input func */
  {251U, 3U},
  /* DSPI20_DSPI20_PCSA input func */
  {251U, 4U},
  /* M_CAN_2_CAN01_RXDD input func */
  {251U, 6U},
  /* LINFLEX0_LIN0_RX input func */
  {251U, 7U},
  /* DSPI10_DSPI10_SIND input func */
  {251U, 8U},
  /* DSPI1_DSPI1_PCS0 input func */
  {251U, 13U},
  /* FCCU_FCCU_EIN input func */
  {251U, 0U},
  /* GTM_TOUT32 input func */
  {251U, 9U},
  /* DSPI17_DSPI17_PCS6 input func */
  {251U, 10U},
  /* DSPI20_DSPI20_PCS0 input func */
  {251U, 11U},
  /* DSPI1_DSPI1_PCS0 input func */
  {251U, 13U},
  /* PSI5S_PSI5S_CLK input func */
  {251U, 14U},
  /* EMIOS_EMIOS_17 input func */
  {251U, 15U},
  /* FCCU_FCCU_EOUT input func */
  {251U, 0U},
  /* INMUX settings for pad PORT252:      {INMUX reg, PADSEL val} */
  /* GTM_TIM1_IN2_8 input func */
  {252U, 1U},
  /* GTM_TIM0_IN2_8 input func */
  {252U, 2U},
  /* DSPI20_DSPI20_SCKA input func */
  {252U, 3U},
  /* DSPI1_DSPI1_SCK input func */
  {252U, 6U},
  /* PWM_PWM1_IN input func */
  {252U, 10U},
  /* GTM_TOUT33 input func */
  {252U, 4U},
  /* EMIOS_EMIOS_16 input func */
  {252U, 9U},
  /* PWM_PWM1_OUT input func */
  {252U, 10U},
  /* INMUX settings for pad PORT253:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN0_6 input func */
  {253U, 1U},
  /* GTM_TIM2_IN0_6 input func */
  {253U, 2U},
  /* DSPI20_DSPI20_SINA input func */
  {253U, 3U},
  /* M_CAN_1_CAN00_RXDD input func */
  {253U, 4U},
  /* DSPI1_DSPI1_SCK input func */
  {253U, 11U},
  /* GTM_TOUT34 input func */
  {253U, 6U},
  /* LINFLEX1_LIN1_TX input func */
  {253U, 7U},
  /* DSPI1_DSPI1_SOUT input func */
  {253U, 8U},
  /* DSPI20_DSPI20_SOUT input func */
  {253U, 9U},
  /* M_CAN_11_CAN22_TXD input func */
  {253U, 12U},
  /* EMIOS_EMIOS_7 input func */
  {253U, 14U},
  /* INMUX settings for pad PORT254:      {INMUX reg, PADSEL val} */
  /* GTM_TIM3_IN1_5 input func */
  {254U, 1U},
  /* GTM_TIM2_IN1_5 input func */
  {254U, 2U},
  /* LINFLEX1_LIN1_RX input func */
  {254U, 3U},
  /* DSPI1_DSPI1_SINF input func */
  {254U, 4U},
  /* DSPI20_DSPI20_SINA input func */
  {254U, 6U},
  /* M_CAN_11_CAN22_RXDA input func */
  {254U, 8U},
  /* GTM_TOUT35 input func */
  {254U, 9U},
  /* LINFLEX1_LIN1_TX input func */
  {254U, 10U},
  /* DSPI1_DSPI1_SOUT input func */
  {254U, 11U},
  /* DSPI20_DSPI20_SOUT input func */
  {254U, 12U},
  /* DSPI18_DSPI18_PCS6 input func */
  {254U, 13U},
  /* M_CAN_1_CAN00_TXD input func */
  {254U, 14U},
  /* EMIOS_EMIOS_6 input func */
  {254U, 15U},
  /* INMUX settings for pad PORT255:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN0_8 input func */
  {255U, 1U},
  /* GTM_TIM4_IN5_14 input func */
  {255U, 2U},
  /* GTM_TIM2_IN0_8 input func */
  {255U, 3U},
  /* DSPI18_DSPI18_SCKD input func */
  {255U, 4U},
  /* PWM_PWM2_IN input func */
  {255U, 10U},
  /* GTM_TOUT143 input func */
  {255U, 6U},
  /* EMIOS_EMIOS_4 input func */
  {255U, 8U},
  /* PWM_PWM2_OUT input func */
  {255U, 10U},
  /* INMUX settings for pad PORT256:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN1_9 input func */
  {256U, 1U},
  /* GTM_TIM4_IN6_12 input func */
  {256U, 2U},
  /* GTM_TIM2_IN1_7 input func */
  {256U, 3U},
  /* GTM_TOUT144 input func */
  {256U, 5U},
  /* EMIOS_EMIOS_5 input func */
  {256U, 7U},
  /* INMUX settings for pad PORT257:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN3_9 input func */
  {257U, 1U},
  /* GTM_TIM3_IN4_12 input func */
  {257U, 2U},
  /* GTM_TIM2_IN3_9 input func */
  {257U, 3U},
  /* PWM_PWM3_IN input func */
  {257U, 10U},
  /* GTM_TOUT146 input func */
  {257U, 4U},
  /* LINFLEX4_LIN4_TX input func */
  {257U, 5U},
  /* DSPI4_DSPI4_SOUT input func */
  {257U, 6U},
  /* M_CAN_1_CAN00_TXD input func */
  {257U, 7U},
  /* M_CAN_9_CAN20_TXD input func */
  {257U, 8U},
  /* EMIOS_EMIOS_20 input func */
  {257U, 9U},
  /* PWM_PWM3_OUT input func */
  {257U, 10U},
  /* INMUX settings for pad PORT258:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN4_9 input func */
  {258U, 1U},
  /* GTM_TIM3_IN5_13 input func */
  {258U, 2U},
  /* GTM_TIM2_IN4_8 input func */
  {258U, 3U},
  /* LINFLEX4_LIN4_RX input func */
  {258U, 4U},
  /* DSPI4_DSPI4_SINB input func */
  {258U, 5U},
  /* M_CAN_1_CAN00_RXDG input func */
  {258U, 6U},
  /* M_CAN_9_CAN20_RXDC input func */
  {258U, 7U},
  /* GTM_TOUT147 input func */
  {258U, 8U},
  /* EMIOS_EMIOS_0 input func */
  {258U, 9U},
  /* INMUX settings for pad PORT259:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN5_10 input func */
  {259U, 1U},
  /* GTM_TIM3_IN6_13 input func */
  {259U, 2U},
  /* GTM_TIM2_IN5_9 input func */
  {259U, 3U},
  /* DSPI4_DSPI4_SCK input func */
  {259U, 6U},
  /* GTM_TOUT148 input func */
  {259U, 4U},
  /* EMIOS_EMIOS_1 input func */
  {259U, 8U},
  /* INMUX settings for pad PORT260:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN6_10 input func */
  {260U, 1U},
  /* GTM_TIM3_IN7_12 input func */
  {260U, 2U},
  /* GTM_TIM2_IN6_8 input func */
  {260U, 3U},
  /* DSPI18_DSPI18_SIND input func */
  {260U, 4U},
  /* DSPI4_DSPI4_PCS0 input func */
  {260U, 7U},
  /* GTM_TOUT149 input func */
  {260U, 5U},
  /* DSPI4_DSPI4_PCS0 input func */
  {260U, 7U},
  /* DSPI18_DSPI18_SOUT input func */
  {260U, 8U},
  /* ACMP6_EVADC_FC6BFLOUT input func */
  {260U, 9U},
  /* EMIOS_EMIOS_2 input func */
  {260U, 10U},
  /* INMUX settings for pad PORT261:      {INMUX reg, PADSEL val} */
  /* GTM_TIM5_IN7_9 input func */
  {261U, 1U},
  /* GTM_TIM4_IN7_12 input func */
  {261U, 2U},
  /* GTM_TIM2_IN7_9 input func */
  {261U, 3U},
  /* DSPI18_DSPI18_SIND input func */
  {261U, 4U},
  /* LINFLEX8_LIN8_RX input func */
  {261U, 5U},
  /* DSPI8_DSPI8_SINE input func */
  {261U, 6U},
  /* GTM_TOUT150 input func */
  {261U, 7U},
  /* LINFLEX8_LIN8_TX input func */
  {261U, 8U},
  /* DSPI8_DSPI8_SOUT input func */
  {261U, 9U},
  /* DSPI18_DSPI18_SOUT input func */
  {261U, 10U},
  /* ACMP7_EVADC_FC7BFLOUT input func */
  {261U, 11U},
  /* EMIOS_EMIOS_3 input func */
  {261U, 12U},
  /* INMUX settings for pad PORT262:      {INMUX reg, PADSEL val} */
  /* GPIO_AN24_P40_0 input func */
  {262U, 0U},
  /* GPIO_AN24_P40_0 input func */
  {262U, 0U},
  /* SENT_SENT_SENT0A input func */
  {262U, 1U},
  /* EMIOS_EMIOS_3 input func */
  {262U, 2U},
  /* INMUX settings for pad PORT263:      {INMUX reg, PADSEL val} */
  /* GPIO_AN25_P40_1 input func */
  {263U, 0U},
  /* GPIO_AN25_P40_1 input func */
  {263U, 0U},
  /* SENT_SENT_SENT1A input func */
  {263U, 1U},
  /* EMIOS_EMIOS_4 input func */
  {263U, 2U},
  /* INMUX settings for pad PORT264:      {INMUX reg, PADSEL val} */
  /* GPIO_AN17_P40_10 input func */
  {264U, 0U},
  /* GPIO_AN17_P40_10 input func */
  {264U, 0U},
  /* SENT_SENT_SENT10A input func */
  {264U, 1U},
  /* INMUX settings for pad PORT265:      {INMUX reg, PADSEL val} */
  /* GPIO_AN18_P40_11 input func */
  {265U, 0U},
  /* GPIO_AN18_P40_11 input func */
  {265U, 0U},
  /* SENT_SENT_SENT11A input func */
  {265U, 1U},
  /* INMUX settings for pad PORT266:      {INMUX reg, PADSEL val} */
  /* GPIO_AN19_P40_12 input func */
  {266U, 0U},
  /* GPIO_AN19_P40_12 input func */
  {266U, 0U},
  /* SENT_SENT_SENT12A input func */
  {266U, 1U},
  /* INMUX settings for pad PORT267:      {INMUX reg, PADSEL val} */
  /* GPIO_AN28_P40_13 input func */
  {267U, 0U},
  /* GPIO_AN28_P40_13 input func */
  {267U, 0U},
  /* SENT_SENT_SENT13A input func */
  {267U, 1U},
  /* INMUX settings for pad PORT268:      {INMUX reg, PADSEL val} */
  /* GPIO_AN29_P40_14 input func */
  {268U, 0U},
  /* GPIO_AN29_P40_14 input func */
  {268U, 0U},
  /* SENT_SENT_SENT14A input func */
  {268U, 1U},
  /* INMUX settings for pad PORT269:      {INMUX reg, PADSEL val} */
  /* GPIO_AN67_P40_15 input func */
  {269U, 0U},
  /* GPIO_AN67_P40_15 input func */
  {269U, 0U},
  /* SENT_SENT_SENT15A input func */
  {269U, 1U},
  /* INMUX settings for pad PORT270:      {INMUX reg, PADSEL val} */
  /* GPIO_AN26_P40_2 input func */
  {270U, 0U},
  /* GPIO_AN26_P40_2 input func */
  {270U, 0U},
  /* SENT_SENT_SENT2A input func */
  {270U, 1U},
  /* EMIOS_EMIOS_4 input func */
  {270U, 2U},
  /* INMUX settings for pad PORT271:      {INMUX reg, PADSEL val} */
  /* GPIO_AN27_P40_3 input func */
  {271U, 0U},
  /* GPIO_AN27_P40_3 input func */
  {271U, 0U},
  /* SENT_SENT_SENT3A input func */
  {271U, 1U},
  /* EMIOS_EMIOS_5 input func */
  {271U, 2U},
  /* INMUX settings for pad PORT272:      {INMUX reg, PADSEL val} */
  /* GPIO_AN32_P40_4 input func */
  {272U, 0U},
  /* GPIO_AN32_P40_4 input func */
  {272U, 0U},
  /* SENT_SENT_SENT4A input func */
  {272U, 1U},
  /* EMIOS_EMIOS_5 input func */
  {272U, 2U},
  /* INMUX settings for pad PORT273:      {INMUX reg, PADSEL val} */
  /* GPIO_AN33_P40_5 input func */
  {273U, 0U},
  /* GPIO_AN33_P40_5 input func */
  {273U, 0U},
  /* SENT_SENT_SENT5A input func */
  {273U, 1U},
  /* EMIOS_EMIOS_17 input func */
  {273U, 2U},
  /* INMUX settings for pad PORT274:      {INMUX reg, PADSEL val} */
  /* GPIO_AN36_P40_6 input func */
  {274U, 0U},
  /* GPIO_AN36_P40_6 input func */
  {274U, 0U},
  /* SENT_SENT_SENT6A input func */
  {274U, 1U},
  /* EMIOS_EMIOS_18 input func */
  {274U, 2U},
  /* INMUX settings for pad PORT275:      {INMUX reg, PADSEL val} */
  /* GPIO_AN37_P40_7 input func */
  {275U, 0U},
  /* GPIO_AN37_P40_7 input func */
  {275U, 0U},
  /* SENT_SENT_SENT7A input func */
  {275U, 1U},
  /* EMIOS_EMIOS_18 input func */
  {275U, 2U},
  /* INMUX settings for pad PORT276:      {INMUX reg, PADSEL val} */
  /* GPIO_AN38_P40_8 input func */
  {276U, 0U},
  /* GPIO_AN38_P40_8 input func */
  {276U, 0U},
  /* SENT_SENT_SENT8A input func */
  {276U, 1U},
  /* EMIOS_EMIOS_19 input func */
  {276U, 2U},
  /* INMUX settings for pad PORT277:      {INMUX reg, PADSEL val} */
  /* GPIO_AN39_P40_9 input func */
  {277U, 0U},
  /* GPIO_AN39_P40_9 input func */
  {277U, 0U},
  /* SENT_SENT_SENT9A input func */
  {277U, 1U},
  /* EMIOS_EMIOS_19 input func */
  {277U, 2U},
  /* INMUX settings for pad PORT278:      {INMUX reg, PADSEL val} */
  /* GPIO_AN68_P41_0 input func */
  {278U, 0U},
  /* GPIO_AN68_P41_0 input func */
  {278U, 0U},
  /* SENT_SENT_SENT16A input func */
  {278U, 1U},
  /* INMUX settings for pad PORT279:      {INMUX reg, PADSEL val} */
  /* GPIO_AN69_P41_1 input func */
  {279U, 0U},
  /* GPIO_AN69_P41_1 input func */
  {279U, 0U},
  /* SENT_SENT_SENT17A input func */
  {279U, 1U},
  /* INMUX settings for pad PORT280:      {INMUX reg, PADSEL val} */
  /* GPIO_AN70_P41_2 input func */
  {280U, 0U},
  /* GPIO_AN70_P41_2 input func */
  {280U, 0U},
  /* SENT_SENT_SENT18A input func */
  {280U, 1U},
  /* INMUX settings for pad PORT281:      {INMUX reg, PADSEL val} */
  /* GPIO_AN71_P41_3 input func */
  {281U, 0U},
  /* GPIO_AN71_P41_3 input func */
  {281U, 0U},
  /* SENT_SENT_SENT19A input func */
  {281U, 1U},
  /* INMUX settings for pad PORT282:      {INMUX reg, PADSEL val} */
  /* GPIO_AN54_P41_4 input func */
  {282U, 0U},
  /* GPIO_AN54_P41_4 input func */
  {282U, 0U},
  /* SENT_SENT_SENT20A input func */
  {282U, 1U},
  /* INMUX settings for pad PORT283:      {INMUX reg, PADSEL val} */
  /* GPIO_AN55_P41_5 input func */
  {283U, 0U},
  /* GPIO_AN55_P41_5 input func */
  {283U, 0U},
  /* SENT_SENT_SENT21A input func */
  {283U, 1U},
  /* INMUX settings for pad PORT284:      {INMUX reg, PADSEL val} */
  /* GPIO_AN62_P41_6 input func */
  {284U, 0U},
  /* GPIO_AN62_P41_6 input func */
  {284U, 0U},
  /* SENT_SENT_SENT22A input func */
  {284U, 1U},
  /* INMUX settings for pad PORT285:      {INMUX reg, PADSEL val} */
  /* GPIO_AN63_P41_7 input func */
  {285U, 0U},
  /* GPIO_AN63_P41_7 input func */
  {285U, 0U},
  /* SENT_SENT_SENT23A input func */
  {285U, 1U},
  /* INMUX settings for pad PORT286:      {INMUX reg, PADSEL val} */
  /* GPIO_AN64_P41_8 input func */
  {286U, 0U},
  /* GPIO_AN64_P41_8 input func */
  {286U, 0U},
  /* SENT_SENT_SENT24A input func */
  {286U, 1U},
  /* INMUX settings for pad PORT287:      {INMUX reg, PADSEL val} */
  /* GPIO_AN0 input func */
  {287U, 0U},
  /* GPIO_AN0 input func */
  {287U, 0U},
  /* INMUX settings for pad PORT288:      {INMUX reg, PADSEL val} */
  /* GPIO_AN1 input func */
  {288U, 0U},
  /* GPIO_AN1 input func */
  {288U, 0U},
  /* INMUX settings for pad PORT289:      {INMUX reg, PADSEL val} */
  /* GPIO_AN2 input func */
  {289U, 0U},
  /* GPIO_AN2 input func */
  {289U, 0U},
  /* INMUX settings for pad PORT290:      {INMUX reg, PADSEL val} */
  /* GPIO_AN3 input func */
  {290U, 0U},
  /* GPIO_AN3 input func */
  {290U, 0U},
  /* INMUX settings for pad PORT291:      {INMUX reg, PADSEL val} */
  /* GPIO_AN4 input func */
  {291U, 0U},
  /* GPIO_AN4 input func */
  {291U, 0U},
  /* INMUX settings for pad PORT292:      {INMUX reg, PADSEL val} */
  /* GPIO_AN5 input func */
  {292U, 0U},
  /* GPIO_AN5 input func */
  {292U, 0U},
  /* INMUX settings for pad PORT293:      {INMUX reg, PADSEL val} */
  /* GPIO_AN6 input func */
  {293U, 0U},
  /* GPIO_AN6 input func */
  {293U, 0U},
  /* INMUX settings for pad PORT294:      {INMUX reg, PADSEL val} */
  /* GPIO_AN7 input func */
  {294U, 0U},
  /* GPIO_AN7 input func */
  {294U, 0U},
  /* INMUX settings for pad PORT295:      {INMUX reg, PADSEL val} */
  /* GPIO_AN8 input func */
  {295U, 0U},
  /* GPIO_AN8 input func */
  {295U, 0U},
  /* INMUX settings for pad PORT296:      {INMUX reg, PADSEL val} */
  /* GPIO_AN9 input func */
  {296U, 0U},
  /* GPIO_AN9 input func */
  {296U, 0U},
  /* INMUX settings for pad PORT297:      {INMUX reg, PADSEL val} */
  /* GPIO_AN10 input func */
  {297U, 0U},
  /* GPIO_AN10 input func */
  {297U, 0U},
  /* INMUX settings for pad PORT298:      {INMUX reg, PADSEL val} */
  /* GPIO_AN11 input func */
  {298U, 0U},
  /* GPIO_AN11 input func */
  {298U, 0U},
  /* INMUX settings for pad PORT299:      {INMUX reg, PADSEL val} */
  /* GPIO_AN12 input func */
  {299U, 0U},
  /* GPIO_AN12 input func */
  {299U, 0U},
  /* INMUX settings for pad PORT300:      {INMUX reg, PADSEL val} */
  /* GPIO_AN13 input func */
  {300U, 0U},
  /* GPIO_AN13 input func */
  {300U, 0U},
  /* INMUX settings for pad PORT301:      {INMUX reg, PADSEL val} */
  /* GPIO_AN14 input func */
  {301U, 0U},
  /* GPIO_AN14 input func */
  {301U, 0U},
  /* INMUX settings for pad PORT302:      {INMUX reg, PADSEL val} */
  /* GPIO_AN15 input func */
  {302U, 0U},
  /* GPIO_AN15 input func */
  {302U, 0U},
  /* INMUX settings for pad PORT303:      {INMUX reg, PADSEL val} */
  /* GPIO_AN16 input func */
  {303U, 0U},
  /* GPIO_AN16 input func */
  {303U, 0U},
  /* INMUX settings for pad PORT304:      {INMUX reg, PADSEL val} */
  /* GPIO_AN20 input func */
  {304U, 0U},
  /* GPIO_AN20 input func */
  {304U, 0U},
  /* INMUX settings for pad PORT305:      {INMUX reg, PADSEL val} */
  /* GPIO_AN21 input func */
  {305U, 0U},
  /* GPIO_AN21 input func */
  {305U, 0U},
  /* INMUX settings for pad PORT306:      {INMUX reg, PADSEL val} */
  /* GPIO_AN22 input func */
  {306U, 0U},
  /* GPIO_AN22 input func */
  {306U, 0U},
  /* INMUX settings for pad PORT307:      {INMUX reg, PADSEL val} */
  /* GPIO_AN23 input func */
  {307U, 0U},
  /* GPIO_AN23 input func */
  {307U, 0U},
  /* INMUX settings for pad PORT308:      {INMUX reg, PADSEL val} */
  /* GPIO_AN30 input func */
  {308U, 0U},
  /* GPIO_AN30 input func */
  {308U, 0U},
  /* INMUX settings for pad PORT309:      {INMUX reg, PADSEL val} */
  /* GPIO_AN31 input func */
  {309U, 0U},
  /* GPIO_AN31 input func */
  {309U, 0U},
  /* INMUX settings for pad PORT310:      {INMUX reg, PADSEL val} */
  /* GPIO_AN34 input func */
  {310U, 0U},
  /* GPIO_AN34 input func */
  {310U, 0U},
  /* INMUX settings for pad PORT311:      {INMUX reg, PADSEL val} */
  /* GPIO_AN35 input func */
  {311U, 0U},
  /* GPIO_AN35 input func */
  {311U, 0U},
  /* INMUX settings for pad PORT312:      {INMUX reg, PADSEL val} */
  /* GPIO_AN40 input func */
  {312U, 0U},
  /* GPIO_AN40 input func */
  {312U, 0U},
  /* INMUX settings for pad PORT313:      {INMUX reg, PADSEL val} */
  /* GPIO_AN41 input func */
  {313U, 0U},
  /* GPIO_AN41 input func */
  {313U, 0U},
  /* INMUX settings for pad PORT314:      {INMUX reg, PADSEL val} */
  /* GPIO_AN42 input func */
  {314U, 0U},
  /* GPIO_AN42 input func */
  {314U, 0U},
  /* INMUX settings for pad PORT315:      {INMUX reg, PADSEL val} */
  /* GPIO_AN43 input func */
  {315U, 0U},
  /* GPIO_AN43 input func */
  {315U, 0U},
  /* INMUX settings for pad PORT316:      {INMUX reg, PADSEL val} */
  /* GPIO_AN44 input func */
  {316U, 0U},
  /* GPIO_AN44 input func */
  {316U, 0U},
  /* INMUX settings for pad PORT317:      {INMUX reg, PADSEL val} */
  /* GPIO_AN45 input func */
  {317U, 0U},
  /* GPIO_AN45 input func */
  {317U, 0U},
  /* INMUX settings for pad PORT318:      {INMUX reg, PADSEL val} */
  /* GPIO_AN46 input func */
  {318U, 0U},
  /* GPIO_AN46 input func */
  {318U, 0U},
  /* INMUX settings for pad PORT319:      {INMUX reg, PADSEL val} */
  /* GPIO_AN47 input func */
  {319U, 0U},
  /* GPIO_AN47 input func */
  {319U, 0U},
  /* INMUX settings for pad PORT320:      {INMUX reg, PADSEL val} */
  /* GPIO_AN48 input func */
  {320U, 0U},
  /* GPIO_AN48 input func */
  {320U, 0U},
  /* INMUX settings for pad PORT321:      {INMUX reg, PADSEL val} */
  /* GPIO_AN49 input func */
  {321U, 0U},
  /* GPIO_AN49 input func */
  {321U, 0U},
  /* INMUX settings for pad PORT322:      {INMUX reg, PADSEL val} */
  /* GPIO_AN50 input func */
  {322U, 0U},
  /* GPIO_AN50 input func */
  {322U, 0U},
  /* INMUX settings for pad PORT323:      {INMUX reg, PADSEL val} */
  /* GPIO_AN51 input func */
  {323U, 0U},
  /* GPIO_AN51 input func */
  {323U, 0U},
  /* INMUX settings for pad PORT324:      {INMUX reg, PADSEL val} */
  /* GPIO_AN52 input func */
  {324U, 0U},
  /* GPIO_AN52 input func */
  {324U, 0U},
  /* INMUX settings for pad PORT325:      {INMUX reg, PADSEL val} */
  /* GPIO_AN53 input func */
  {325U, 0U},
  /* GPIO_AN53 input func */
  {325U, 0U},
  /* INMUX settings for pad PORT326:      {INMUX reg, PADSEL val} */
  /* GPIO_AN56 input func */
  {326U, 0U},
  /* GPIO_AN56 input func */
  {326U, 0U},
  /* INMUX settings for pad PORT327:      {INMUX reg, PADSEL val} */
  /* GPIO_AN57 input func */
  {327U, 0U},
  /* GPIO_AN57 input func */
  {327U, 0U},
  /* INMUX settings for pad PORT328:      {INMUX reg, PADSEL val} */
  /* GPIO_AN58 input func */
  {328U, 0U},
  /* GPIO_AN58 input func */
  {328U, 0U},
  /* INMUX settings for pad PORT329:      {INMUX reg, PADSEL val} */
  /* GPIO_AN59 input func */
  {329U, 0U},
  /* GPIO_AN59 input func */
  {329U, 0U},
  /* INMUX settings for pad PORT330:      {INMUX reg, PADSEL val} */
  /* GPIO_AN60 input func */
  {330U, 0U},
  /* GPIO_AN60 input func */
  {330U, 0U},
  /* INMUX settings for pad PORT331:      {INMUX reg, PADSEL val} */
  /* GPIO_AN61 input func */
  {331U, 0U},
  /* GPIO_AN61 input func */
  {331U, 0U},
  /* INMUX settings for pad PORT332:      {INMUX reg, PADSEL val} */
  /* GPIO_AN65 input func */
  {332U, 0U},
  /* GPIO_AN65 input func */
  {332U, 0U},
  /* INMUX settings for pad PORT333:      {INMUX reg, PADSEL val} */
  /* GPIO_AN66 input func */
  {333U, 0U},
  /* GPIO_AN66 input func */
  {333U, 0U},
  /* INMUX settings for pad PORT334:      {INMUX reg, PADSEL val} */
  /* GPIO_AN72 input func */
  {334U, 0U},
  /* GPIO_AN72 input func */
  {334U, 0U},
  /* INMUX settings for pad PORT335:      {INMUX reg, PADSEL val} */
  /* GPIO_AN73 input func */
  {335U, 0U},
  /* GPIO_AN73 input func */
  {335U, 0U}

};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"


/**
* @brief Port INOUT settings data
*/

/**
* @brief Port INPUT INMUX settings data
*/

#endif
#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Port Pin description data
*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
CONST (uint16, PORT_CONST) Port_au16PinDescription[93][22] =
{

/*  Mode PORT_GPIO_MODE: */
{
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff
},
/*  Mode PORT_ALT1_FUNC_MODE: */
{
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xfffd,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0x7fff,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT2_FUNC_MODE: */
{
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xfffd,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xc0ff,
(uint16)0x003f,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT3_FUNC_MODE: */
{
(uint16)0xffff,
(uint16)0xfffb,
(uint16)0xffd7,
(uint16)0xff7f,
(uint16)0xdfff,
(uint16)0xfff7,
(uint16)0xfdc3,
(uint16)0xffff,
(uint16)0xfffd,
(uint16)0xffff,
(uint16)0x00ff,
(uint16)0x0140,
(uint16)0x007f,
(uint16)0x0000,
(uint16)0xda00,
(uint16)0xfbff,
(uint16)0x003f,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT4_FUNC_MODE: */
{
(uint16)0x87eb,
(uint16)0x0dff,
(uint16)0x4fef,
(uint16)0xff5c,
(uint16)0xfbff,
(uint16)0xdfef,
(uint16)0x79ff,
(uint16)0xfeff,
(uint16)0x0ffc,
(uint16)0xfffb,
(uint16)0xfff7,
(uint16)0xfebf,
(uint16)0xff00,
(uint16)0xffff,
(uint16)0xf9ff,
(uint16)0xff3e,
(uint16)0x003e,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT5_FUNC_MODE: */
{
(uint16)0xe3b2,
(uint16)0x7f9f,
(uint16)0xffff,
(uint16)0xbff7,
(uint16)0xfffe,
(uint16)0x7e7f,
(uint16)0xffff,
(uint16)0x7fef,
(uint16)0x2ffd,
(uint16)0x67f6,
(uint16)0x00ef,
(uint16)0x0040,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x783e,
(uint16)0x05ff,
(uint16)0x0037,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT6_FUNC_MODE: */
{
(uint16)0x126e,
(uint16)0xfeff,
(uint16)0xb73f,
(uint16)0x875f,
(uint16)0xbff7,
(uint16)0xbe06,
(uint16)0xefff,
(uint16)0xe7fb,
(uint16)0xbfcd,
(uint16)0xfeff,
(uint16)0x003e,
(uint16)0x0000,
(uint16)0xffff,
(uint16)0x007f,
(uint16)0xe800,
(uint16)0xfe83,
(uint16)0x002e,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT7_FUNC_MODE: */
{
(uint16)0x1ce9,
(uint16)0xffa3,
(uint16)0xfefc,
(uint16)0x9eff,
(uint16)0xab3f,
(uint16)0x9e2f,
(uint16)0xf7e7,
(uint16)0x60d4,
(uint16)0x15fc,
(uint16)0x7ff8,
(uint16)0x007e,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0x3fff,
(uint16)0xf800,
(uint16)0xbf65,
(uint16)0x0037,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT8_FUNC_MODE: */
{
(uint16)0x13ff,
(uint16)0x3ffb,
(uint16)0xf77f,
(uint16)0x81bb,
(uint16)0xbc0f,
(uint16)0x3601,
(uint16)0xe7eb,
(uint16)0x01ff,
(uint16)0x26b4,
(uint16)0x74ce,
(uint16)0x003c,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0xd800,
(uint16)0xebbf,
(uint16)0x003e,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT9_FUNC_MODE: */
{
(uint16)0x0c7a,
(uint16)0x3de1,
(uint16)0xb7ff,
(uint16)0x81fd,
(uint16)0x0f2d,
(uint16)0x1a02,
(uint16)0xd6ed,
(uint16)0x01fe,
(uint16)0xf4f4,
(uint16)0x213e,
(uint16)0x002a,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xffff,
(uint16)0xb800,
(uint16)0x7ee7,
(uint16)0x0036,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT10_FUNC_MODE: */
{
(uint16)0x11ff,
(uint16)0x2380,
(uint16)0xe6bf,
(uint16)0x808f,
(uint16)0x2f09,
(uint16)0x1800,
(uint16)0x5788,
(uint16)0x80ff,
(uint16)0x5070,
(uint16)0x0002,
(uint16)0x000a,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x8000,
(uint16)0xdffa,
(uint16)0x0032,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT11_FUNC_MODE: */
{
(uint16)0x1d7f,
(uint16)0x2d00,
(uint16)0xb2fd,
(uint16)0x81d7,
(uint16)0x0e28,
(uint16)0x0002,
(uint16)0xc60b,
(uint16)0x802e,
(uint16)0xd0f0,
(uint16)0x000c,
(uint16)0x000a,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x8000,
(uint16)0x6ff7,
(uint16)0x0020,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT12_FUNC_MODE: */
{
(uint16)0x00ad,
(uint16)0x0d00,
(uint16)0x0327,
(uint16)0x0074,
(uint16)0x0620,
(uint16)0x0000,
(uint16)0xc783,
(uint16)0x807a,
(uint16)0x40d4,
(uint16)0x003c,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x674a,
(uint16)0x0020,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT13_FUNC_MODE: */
{
(uint16)0x03d5,
(uint16)0x0100,
(uint16)0x01dc,
(uint16)0x0145,
(uint16)0x0e00,
(uint16)0x0000,
(uint16)0x828a,
(uint16)0x004c,
(uint16)0x0014,
(uint16)0x0030,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x8000,
(uint16)0x4fc4,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT14_FUNC_MODE: */
{
(uint16)0x03ff,
(uint16)0x0100,
(uint16)0x01d9,
(uint16)0x0060,
(uint16)0x0e00,
(uint16)0x0000,
(uint16)0x0082,
(uint16)0x8020,
(uint16)0x4010,
(uint16)0x0000,
(uint16)0x0002,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x6d7c,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ALT15_FUNC_MODE: */
{
(uint16)0x01b6,
(uint16)0x0000,
(uint16)0x0071,
(uint16)0x0060,
(uint16)0x0200,
(uint16)0x0000,
(uint16)0x0008,
(uint16)0x0000,
(uint16)0x4000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x4dd8,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ONLY_OUTPUT_MODE: */
{
(uint16)0x013a,
(uint16)0x0000,
(uint16)0x0169,
(uint16)0x0040,
(uint16)0x0200,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0008,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0820,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ANALOG_INPUT_MODE: */
{
(uint16)0x0250,
(uint16)0x0000,
(uint16)0x0110,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x00a4,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_ONLY_INPUT_MODE: */
{
(uint16)0x0220,
(uint16)0x0000,
(uint16)0x00d0,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x00e4,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT1_MODE: */
{
(uint16)0x0198,
(uint16)0x0000,
(uint16)0x0100,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0080,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT2_MODE: */
{
(uint16)0x0202,
(uint16)0x0000,
(uint16)0x0100,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0040,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT3_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT4_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT5_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT6_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT7_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT8_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT9_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT10_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT11_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT12_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT13_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT14_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT15_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT16_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT17_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT18_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT19_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT20_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT21_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT22_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT23_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT24_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT25_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT26_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT27_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT28_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT29_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT30_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT31_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT32_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT33_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT34_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT35_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT36_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT37_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT38_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT39_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT40_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT41_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT42_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT43_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT44_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT45_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT46_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT47_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT48_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT49_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT50_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT51_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT52_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT53_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT54_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT55_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT56_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT57_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT58_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT59_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT60_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT61_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT62_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT63_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT64_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT65_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT66_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT67_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT68_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INPUT69_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INOUT1_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INOUT2_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INOUT3_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INOUT4_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
},
/*  Mode PORT_INOUT5_MODE: */
{
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000,
(uint16)0x0000
}

};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"

/**
* @brief Port index to address the INPUT INDEX data
*/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
CONST(uint16,PORT_CONST) Port_au16PadFunctInMuxIndex[364]=
{

  /* Index to address the input settings for pad 0*/
  (uint16)1,
  /* Index to address the input settings for pad 1*/
  (uint16)15,
  /* Index to address the input settings for pad 2*/
  (uint16)31,
  /* Index to address the input settings for pad 3*/
  (uint16)43,
  /* Index to address the input settings for pad 4*/
  (uint16)60,
  /* Index to address the input settings for pad 5*/
  (uint16)76,
  /* Index to address the input settings for pad 6*/
  (uint16)94,
  /* Index to address the input settings for pad 7*/
  (uint16)109,
  /* Index to address the input settings for pad 8*/
  (uint16)124,
  /* Index to address the input settings for pad 9*/
  (uint16)139,
  /* Index to address the input settings for pad 10*/
  (uint16)153,
  /* Index to address the input settings for pad 11*/
  (uint16)162,
  /* Index to address the input settings for pad 12*/
  (uint16)170,
  /* Index to address the input settings for pad 13*/
  (uint16)179,
  /* Index to address the input settings for pad 14*/
  (uint16)184,
  /* Index to address the input settings for pad 15*/
  (uint16)189,
  /* Index to address the input settings for pad 16*/
  (uint16)195,
  /* Index to address the input settings for pad 17*/
  (uint16)205,
  /* Index to address the input settings for pad 18*/
  (uint16)214,
  /* Index to address the input settings for pad 19*/
  (uint16)220,
  /* Index to address the input settings for pad 20*/
  (uint16)228,
  /* Index to address the input settings for pad 21*/
  (uint16)237,
  /* Index to address the input settings for pad 22*/
  (uint16)246,
  /* Index to address the input settings for pad 23*/
  (uint16)254,
  /* Index to address the input settings for pad 24*/
  (uint16)264,
  /* Index to address the input settings for pad 25*/
  (uint16)278,
  /* Index to address the input settings for pad 26*/
  (uint16)287,
  /* Index to address the input settings for pad 27*/
  (uint16)299,
  /* Index to address the input settings for pad 28*/
  (uint16)312,
  /* Index to address the input settings for pad 29*/
  (uint16)321,
  /* Index to address the input settings for pad 30*/
  (uint16)332,
  /* Index to address the input settings for pad 31*/
  (uint16)339,
  /* Index to address the input settings for pad 32*/
  (uint16)345,
  /* Index to address the input settings for pad 33*/
  (uint16)360,
  /* Index to address the input settings for pad 34*/
  (uint16)371,
  /* Index to address the input settings for pad 35*/
  (uint16)385,
  /* Index to address the input settings for pad 36*/
  (uint16)400,
  /* Index to address the input settings for pad 37*/
  (uint16)416,
  /* Index to address the input settings for pad 38*/
  (uint16)430,
  /* Index to address the input settings for pad 39*/
  (uint16)445,
  /* Index to address the input settings for pad 40*/
  (uint16)458,
  /* Index to address the input settings for pad 41*/
  (uint16)474,
  /* Index to address the input settings for pad 42*/
  (uint16)487,
  /* Index to address the input settings for pad 43*/
  (uint16)498,
  /* Index to address the input settings for pad 44*/
  (uint16)506,
  /* Index to address the input settings for pad 45*/
  (uint16)517,
  /* Index to address the input settings for pad 46*/
  (uint16)528,
  /* Index to address the input settings for pad 47*/
  (uint16)537,
  /* Index to address the input settings for pad 48*/
  (uint16)548,
  /* Index to address the input settings for pad 49*/
  (uint16)560,
  /* Index to address the input settings for pad 50*/
  (uint16)570,
  /* Index to address the input settings for pad 51*/
  (uint16)582,
  /* Index to address the input settings for pad 52*/
  (uint16)592,
  /* Index to address the input settings for pad 53*/
  (uint16)604,
  /* Index to address the input settings for pad 54*/
  (uint16)616,
  /* Index to address the input settings for pad 55*/
  (uint16)631,
  /* Index to address the input settings for pad 56*/
  (uint16)640,
  /* Index to address the input settings for pad 57*/
  (uint16)650,
  /* Index to address the input settings for pad 58*/
  (uint16)658,
  /* Index to address the input settings for pad 59*/
  (uint16)666,
  /* Index to address the input settings for pad 60*/
  (uint16)673,
  /* Index to address the input settings for pad 61*/
  (uint16)681,
  /* Index to address the input settings for pad 62*/
  (uint16)687,
  /* Index to address the input settings for pad 63*/
  (uint16)692,
  /* Index to address the input settings for pad 64*/
  (uint16)704,
  /* Index to address the input settings for pad 65*/
  (uint16)714,
  /* Index to address the input settings for pad 66*/
  (uint16)723,
  /* Index to address the input settings for pad 67*/
  (uint16)733,
  /* Index to address the input settings for pad 68*/
  (uint16)744,
  /* Index to address the input settings for pad 69*/
  (uint16)752,
  /* Index to address the input settings for pad 70*/
  (uint16)763,
  /* Index to address the input settings for pad 71*/
  (uint16)771,
  /* Index to address the input settings for pad 72*/
  (uint16)779,
  /* Index to address the input settings for pad 73*/
  (uint16)790,
  /* Index to address the input settings for pad 74*/
  (uint16)806,
  /* Index to address the input settings for pad 75*/
  (uint16)819,
  /* Index to address the input settings for pad 76*/
  (uint16)834,
  /* Index to address the input settings for pad 77*/
  (uint16)843,
  /* Index to address the input settings for pad 78*/
  (uint16)853,
  /* Index to address the input settings for pad 79*/
  (uint16)860,
  /* Index to address the input settings for pad 80*/
  (uint16)869,
  /* Index to address the input settings for pad 81*/
  (uint16)879,
  /* Index to address the input settings for pad 82*/
  (uint16)889,
  /* Index to address the input settings for pad 83*/
  (uint16)897,
  /* Index to address the input settings for pad 84*/
  (uint16)903,
  /* Index to address the input settings for pad 85*/
  (uint16)909,
  /* Index to address the input settings for pad 86*/
  (uint16)916,
  /* Index to address the input settings for pad 87*/
  (uint16)922,
  /* Index to address the input settings for pad 88*/
  (uint16)927,
  /* Index to address the input settings for pad 89*/
  (uint16)932,
  /* Index to address the input settings for pad 90*/
  (uint16)942,
  /* Index to address the input settings for pad 91*/
  (uint16)951,
  /* Index to address the input settings for pad 92*/
  (uint16)961,
  /* Index to address the input settings for pad 93*/
  (uint16)972,
  /* Index to address the input settings for pad 94*/
  (uint16)979,
  /* Index to address the input settings for pad 95*/
  (uint16)985,
  /* Index to address the input settings for pad 96*/
  (uint16)993,
  /* Index to address the input settings for pad 97*/
  (uint16)1005,
  /* Index to address the input settings for pad 98*/
  (uint16)1018,
  /* Index to address the input settings for pad 99*/
  (uint16)1026,
  /* Index to address the input settings for pad 100*/
  (uint16)1040,
  /* Index to address the input settings for pad 101*/
  (uint16)1047,
  /* Index to address the input settings for pad 102*/
  (uint16)1056,
  /* Index to address the input settings for pad 103*/
  (uint16)1066,
  /* Index to address the input settings for pad 104*/
  (uint16)1080,
  /* Index to address the input settings for pad 105*/
  (uint16)1093,
  /* Index to address the input settings for pad 106*/
  (uint16)1105,
  /* Index to address the input settings for pad 107*/
  (uint16)1116,
  /* Index to address the input settings for pad 108*/
  (uint16)1123,
  /* Index to address the input settings for pad 109*/
  (uint16)1132,
  /* Index to address the input settings for pad 110*/
  (uint16)1140,
  /* Index to address the input settings for pad 111*/
  (uint16)1153,
  /* Index to address the input settings for pad 112*/
  (uint16)1165,
  /* Index to address the input settings for pad 113*/
  (uint16)1175,
  /* Index to address the input settings for pad 114*/
  (uint16)1187,
  /* Index to address the input settings for pad 115*/
  (uint16)1199,
  /* Index to address the input settings for pad 116*/
  (uint16)1212,
  /* Index to address the input settings for pad 117*/
  (uint16)1223,
  /* Index to address the input settings for pad 118*/
  (uint16)1236,
  /* Index to address the input settings for pad 119*/
  (uint16)1248,
  /* Index to address the input settings for pad 120*/
  (uint16)1259,
  /* Index to address the input settings for pad 121*/
  (uint16)1266,
  /* Index to address the input settings for pad 122*/
  (uint16)1273,
  /* Index to address the input settings for pad 123*/
  (uint16)1280,
  /* Index to address the input settings for pad 124*/
  (uint16)1286,
  /* Index to address the input settings for pad 125*/
  (uint16)1292,
  /* Index to address the input settings for pad 126*/
  (uint16)1300,
  /* Index to address the input settings for pad 127*/
  (uint16)1307,
  /* Index to address the input settings for pad 128*/
  (uint16)1317,
  /* Index to address the input settings for pad 129*/
  (uint16)1323,
  /* Index to address the input settings for pad 130*/
  (uint16)1324,
  /* Index to address the input settings for pad 131*/
  (uint16)1337,
  /* Index to address the input settings for pad 132*/
  (uint16)1345,
  /* Index to address the input settings for pad 133*/
  (uint16)1360,
  /* Index to address the input settings for pad 134*/
  (uint16)1373,
  /* Index to address the input settings for pad 135*/
  (uint16)1385,
  /* Index to address the input settings for pad 136*/
  (uint16)1398,
  /* Index to address the input settings for pad 137*/
  (uint16)1406,
  /* Index to address the input settings for pad 138*/
  (uint16)1415,
  /* Index to address the input settings for pad 139*/
  (uint16)1425,
  /* Index to address the input settings for pad 140*/
  (uint16)1433,
  /* Index to address the input settings for pad 141*/
  (uint16)1442,
  /* Index to address the input settings for pad 142*/
  (uint16)1450,
  /* Index to address the input settings for pad 143*/
  (uint16)1461,
  /* Index to address the input settings for pad 144*/
  (uint16)1469,
  /* Index to address the input settings for pad 145*/
  (uint16)1476,
  /* Index to address the input settings for pad 146*/
  (uint16)1486,
  /* Index to address the input settings for pad 147*/
  (uint16)1497,
  /* Index to address the input settings for pad 148*/
  (uint16)1509,
  /* Index to address the input settings for pad 149*/
  (uint16)1520,
  /* Index to address the input settings for pad 150*/
  (uint16)1531,
  /* Index to address the input settings for pad 151*/
  (uint16)1540,
  /* Index to address the input settings for pad 152*/
  (uint16)1548,
  /* Index to address the input settings for pad 153*/
  (uint16)1557,
  /* Index to address the input settings for pad 154*/
  (uint16)1565,
  /* Index to address the input settings for pad 155*/
  (uint16)1574,
  /* Index to address the input settings for pad 156*/
  (uint16)1580,
  /* Index to address the input settings for pad 157*/
  (uint16)1587,
  /* Index to address the input settings for pad 158*/
  (uint16)1597,
  /* Index to address the input settings for pad 159*/
  (uint16)1606,
  /* Index to address the input settings for pad 160*/
  (uint16)1613,
  /* Index to address the input settings for pad 161*/
  (uint16)1619,
  /* Index to address the input settings for pad 162*/
  (uint16)1631,
  /* Index to address the input settings for pad 163*/
  (uint16)1640,
  /* Index to address the input settings for pad 164*/
  (uint16)1651,
  /* Index to address the input settings for pad 165*/
  (uint16)1660,
  /* Index to address the input settings for pad 166*/
  (uint16)1670,
  /* Index to address the input settings for pad 167*/
  (uint16)1677,
  /* Index to address the input settings for pad 168*/
  (uint16)1683,
  /* Index to address the input settings for pad 169*/
  (uint16)1687,
  /* Index to address the input settings for pad 170*/
  (uint16)1691,
  /* Index to address the input settings for pad 171*/
  (uint16)1695,
  /* Index to address the input settings for pad 172*/
  (uint16)1699,
  /* Index to address the input settings for pad 173*/
  (uint16)1703,
  /* Index to address the input settings for pad 174*/
  (uint16)1707,
  /* Index to address the input settings for pad 175*/
  (uint16)1711,
  /* Index to address the input settings for pad 176*/
  (uint16)1715,
  /* Index to address the input settings for pad 177*/
  (uint16)1721,
  /* Index to address the input settings for pad 178*/
  (uint16)1727,
  /* Index to address the input settings for pad 179*/
  (uint16)1733,
  /* Index to address the input settings for pad 180*/
  (uint16)1739,
  /* Index to address the input settings for pad 181*/
  (uint16)1745,
  /* Index to address the input settings for pad 182*/
  (uint16)1751,
  /* Index to address the input settings for pad 183*/
  (uint16)1758,
  /* Index to address the input settings for pad 184*/
  (uint16)1764,
  /* Index to address the input settings for pad 185*/
  (uint16)1770,
  /* Index to address the input settings for pad 186*/
  (uint16)1776,
  /* Index to address the input settings for pad 187*/
  (uint16)1782,
  /* Index to address the input settings for pad 188*/
  (uint16)1788,
  /* Index to address the input settings for pad 189*/
  (uint16)1794,
  /* Index to address the input settings for pad 190*/
  (uint16)1800,
  /* Index to address the input settings for pad 191*/
  (uint16)1806,
  /* Index to address the input settings for pad 192*/
  (uint16)1812,
  /* Index to address the input settings for pad 193*/
  (uint16)1820,
  /* Index to address the input settings for pad 194*/
  (uint16)1828,
  /* Index to address the input settings for pad 195*/
  (uint16)1836,
  /* Index to address the input settings for pad 196*/
  (uint16)1844,
  /* Index to address the input settings for pad 197*/
  (uint16)1852,
  /* Index to address the input settings for pad 198*/
  (uint16)1860,
  /* Index to address the input settings for pad 199*/
  (uint16)1868,
  /* Index to address the input settings for pad 200*/
  (uint16)1875,
  /* Index to address the input settings for pad 201*/
  (uint16)1883,
  /* Index to address the input settings for pad 202*/
  (uint16)1891,
  /* Index to address the input settings for pad 203*/
  (uint16)1899,
  /* Index to address the input settings for pad 204*/
  (uint16)1907,
  /* Index to address the input settings for pad 205*/
  (uint16)1915,
  /* Index to address the input settings for pad 206*/
  (uint16)1923,
  /* Index to address the input settings for pad 207*/
  (uint16)1931,
  /* Index to address the input settings for pad 208*/
  (uint16)1938,
  /* Index to address the input settings for pad 209*/
  (uint16)1945,
  /* Index to address the input settings for pad 210*/
  (uint16)1952,
  /* Index to address the input settings for pad 211*/
  (uint16)1959,
  /* Index to address the input settings for pad 212*/
  (uint16)1966,
  /* Index to address the input settings for pad 213*/
  (uint16)1973,
  /* Index to address the input settings for pad 214*/
  (uint16)1980,
  /* Index to address the input settings for pad 215*/
  (uint16)1987,
  /* Index to address the input settings for pad 216*/
  (uint16)1993,
  /* Index to address the input settings for pad 217*/
  (uint16)1999,
  /* Index to address the input settings for pad 218*/
  (uint16)2005,
  /* Index to address the input settings for pad 219*/
  (uint16)2011,
  /* Index to address the input settings for pad 220*/
  (uint16)2017,
  /* Index to address the input settings for pad 221*/
  (uint16)2023,
  /* Index to address the input settings for pad 222*/
  (uint16)2029,
  /* Index to address the input settings for pad 223*/
  (uint16)2034,
  /* Index to address the input settings for pad 224*/
  (uint16)2039,
  /* Index to address the input settings for pad 225*/
  (uint16)2043,
  /* Index to address the input settings for pad 226*/
  (uint16)2048,
  /* Index to address the input settings for pad 227*/
  (uint16)2053,
  /* Index to address the input settings for pad 228*/
  (uint16)2058,
  /* Index to address the input settings for pad 229*/
  (uint16)2063,
  /* Index to address the input settings for pad 230*/
  (uint16)2068,
  /* Index to address the input settings for pad 231*/
  (uint16)2072,
  /* Index to address the input settings for pad 232*/
  (uint16)2076,
  /* Index to address the input settings for pad 233*/
  (uint16)2080,
  /* Index to address the input settings for pad 234*/
  (uint16)2084,
  /* Index to address the input settings for pad 235*/
  (uint16)2087,
  /* Index to address the input settings for pad 236*/
  (uint16)2097,
  /* Index to address the input settings for pad 237*/
  (uint16)2106,
  /* Index to address the input settings for pad 238*/
  (uint16)2114,
  /* Index to address the input settings for pad 239*/
  (uint16)2123,
  /* Index to address the input settings for pad 240*/
  (uint16)2135,
  /* Index to address the input settings for pad 241*/
  (uint16)2146,
  /* Index to address the input settings for pad 242*/
  (uint16)2159,
  /* Index to address the input settings for pad 243*/
  (uint16)2174,
  /* Index to address the input settings for pad 244*/
  (uint16)2186,
  /* Index to address the input settings for pad 245*/
  (uint16)2197,
  /* Index to address the input settings for pad 246*/
  (uint16)2213,
  /* Index to address the input settings for pad 247*/
  (uint16)2229,
  /* Index to address the input settings for pad 248*/
  (uint16)2246,
  /* Index to address the input settings for pad 249*/
  (uint16)2261,
  /* Index to address the input settings for pad 250*/
  (uint16)2275,
  /* Index to address the input settings for pad 251*/
  (uint16)2291,
  /* Index to address the input settings for pad 252*/
  (uint16)2308,
  /* Index to address the input settings for pad 253*/
  (uint16)2317,
  /* Index to address the input settings for pad 254*/
  (uint16)2329,
  /* Index to address the input settings for pad 255*/
  (uint16)2343,
  /* Index to address the input settings for pad 256*/
  (uint16)2352,
  /* Index to address the input settings for pad 257*/
  (uint16)2358,
  /* Index to address the input settings for pad 258*/
  (uint16)2370,
  /* Index to address the input settings for pad 259*/
  (uint16)2380,
  /* Index to address the input settings for pad 260*/
  (uint16)2387,
  /* Index to address the input settings for pad 261*/
  (uint16)2398,
  /* Index to address the input settings for pad 262*/
  (uint16)2411,
  /* Index to address the input settings for pad 263*/
  (uint16)2414,
  /* Index to address the input settings for pad 264*/
  (uint16)2417,
  /* Index to address the input settings for pad 265*/
  (uint16)2419,
  /* Index to address the input settings for pad 266*/
  (uint16)2421,
  /* Index to address the input settings for pad 267*/
  (uint16)2423,
  /* Index to address the input settings for pad 268*/
  (uint16)2425,
  /* Index to address the input settings for pad 269*/
  (uint16)2427,
  /* Index to address the input settings for pad 270*/
  (uint16)2429,
  /* Index to address the input settings for pad 271*/
  (uint16)2432,
  /* Index to address the input settings for pad 272*/
  (uint16)2435,
  /* Index to address the input settings for pad 273*/
  (uint16)2438,
  /* Index to address the input settings for pad 274*/
  (uint16)2441,
  /* Index to address the input settings for pad 275*/
  (uint16)2444,
  /* Index to address the input settings for pad 276*/
  (uint16)2447,
  /* Index to address the input settings for pad 277*/
  (uint16)2450,
  /* Index to address the input settings for pad 278*/
  (uint16)2453,
  /* Index to address the input settings for pad 279*/
  (uint16)2455,
  /* Index to address the input settings for pad 280*/
  (uint16)2457,
  /* Index to address the input settings for pad 281*/
  (uint16)2459,
  /* Index to address the input settings for pad 282*/
  (uint16)2461,
  /* Index to address the input settings for pad 283*/
  (uint16)2463,
  /* Index to address the input settings for pad 284*/
  (uint16)2465,
  /* Index to address the input settings for pad 285*/
  (uint16)2467,
  /* Index to address the input settings for pad 286*/
  (uint16)2469,
  /* Index to address the input settings for pad 287*/
  (uint16)2471,
  /* Index to address the input settings for pad 288*/
  (uint16)2472,
  /* Index to address the input settings for pad 289*/
  (uint16)2473,
  /* Index to address the input settings for pad 290*/
  (uint16)2474,
  /* Index to address the input settings for pad 291*/
  (uint16)2475,
  /* Index to address the input settings for pad 292*/
  (uint16)2476,
  /* Index to address the input settings for pad 293*/
  (uint16)2477,
  /* Index to address the input settings for pad 294*/
  (uint16)2478,
  /* Index to address the input settings for pad 295*/
  (uint16)2479,
  /* Index to address the input settings for pad 296*/
  (uint16)2480,
  /* Index to address the input settings for pad 297*/
  (uint16)2481,
  /* Index to address the input settings for pad 298*/
  (uint16)2482,
  /* Index to address the input settings for pad 299*/
  (uint16)2483,
  /* Index to address the input settings for pad 300*/
  (uint16)2484,
  /* Index to address the input settings for pad 301*/
  (uint16)2485,
  /* Index to address the input settings for pad 302*/
  (uint16)2486,
  /* Index to address the input settings for pad 303*/
  (uint16)2487,
  /* Index to address the input settings for pad 304*/
  (uint16)2488,
  /* Index to address the input settings for pad 305*/
  (uint16)2489,
  /* Index to address the input settings for pad 306*/
  (uint16)2490,
  /* Index to address the input settings for pad 307*/
  (uint16)2491,
  /* Index to address the input settings for pad 308*/
  (uint16)2492,
  /* Index to address the input settings for pad 309*/
  (uint16)2493,
  /* Index to address the input settings for pad 310*/
  (uint16)2494,
  /* Index to address the input settings for pad 311*/
  (uint16)2495,
  /* Index to address the input settings for pad 312*/
  (uint16)2496,
  /* Index to address the input settings for pad 313*/
  (uint16)2497,
  /* Index to address the input settings for pad 314*/
  (uint16)2498,
  /* Index to address the input settings for pad 315*/
  (uint16)2499,
  /* Index to address the input settings for pad 316*/
  (uint16)2500,
  /* Index to address the input settings for pad 317*/
  (uint16)2501,
  /* Index to address the input settings for pad 318*/
  (uint16)2502,
  /* Index to address the input settings for pad 319*/
  (uint16)2503,
  /* Index to address the input settings for pad 320*/
  (uint16)2504,
  /* Index to address the input settings for pad 321*/
  (uint16)2505,
  /* Index to address the input settings for pad 322*/
  (uint16)2506,
  /* Index to address the input settings for pad 323*/
  (uint16)2507,
  /* Index to address the input settings for pad 324*/
  (uint16)2508,
  /* Index to address the input settings for pad 325*/
  (uint16)2509,
  /* Index to address the input settings for pad 326*/
  (uint16)2510,
  /* Index to address the input settings for pad 327*/
  (uint16)2511,
  /* Index to address the input settings for pad 328*/
  (uint16)2512,
  /* Index to address the input settings for pad 329*/
  (uint16)2513,
  /* Index to address the input settings for pad 330*/
  (uint16)2514,
  /* Index to address the input settings for pad 331*/
  (uint16)2515,
  /* Index to address the input settings for pad 332*/
  (uint16)2516,
  /* Index to address the input settings for pad 333*/
  (uint16)2517,
  /* Index to address the input settings for pad 334*/
  (uint16)2518,
  /* Index to address the input settings for pad 335*/
  (uint16)2519,
  /* Index to address the input settings for pad 336*/
  (uint16)0,
  /* Index to address the input settings for pad 337*/
  (uint16)0,
  /* Index to address the input settings for pad 338*/
  (uint16)0,
  /* Index to address the input settings for pad 339*/
  (uint16)0,
  /* Index to address the input settings for pad 340*/
  (uint16)0,

};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"

/**
* @brief Port Pin description data
*/

/**
* @brief Port index to address the INPUT INDEX data
*/

#endif

/*======================================GLOBAL VARIABLES============================================*/


/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/


/*======================================LOCAL FUNCTIONS=============================================*/


/*======================================GLOBAL FUNCTIONS============================================*/




/** @} */


#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"
static CONST(Port_CoreMapItemType, PORT_CONST) Port_CoreMap[PORT_MAX_CONFIGURED_PADS_U16]=
{
    {
        .u16Port_Pin = 298,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 321,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 241,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 270,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 308,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 303,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 320,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 295,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 3,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 4,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 289,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 292,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 297,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 21,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 310,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 6,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 311,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 277,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 327,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 284,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 332,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 274,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 272,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 268,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 267,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 275,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 285,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 273,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 242,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 283,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 264,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 299,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 309,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 271,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 286,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 269,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 316,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 333,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 276,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 317,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 278,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 313,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 262,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 9,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 263,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 279,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 10,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 315,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 19,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 20,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 11,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 8,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 5,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 293,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 300,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 291,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 290,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 296,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 288,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 306,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 265,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 302,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 301,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 246,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 287,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 245,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 248,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 304,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 27,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 28,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 31,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 33,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 38,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 43,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 48,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 49,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 51,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 53,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 57,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 58,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 59,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 60,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 61,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 62,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 68,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 75,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 76,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 77,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 78,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 90,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 92,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 94,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 97,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 101,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 102,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 111,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 114,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 115,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 116,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 118,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 121,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 122,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 123,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 124,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 125,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 126,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 132,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 135,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 136,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 137,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 138,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 139,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 182,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 183,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 189,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 191,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 192,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 193,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 195,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 196,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 197,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 198,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 199,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 207,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 208,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 209,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 210,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 211,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 212,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 213,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 214,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 217,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 218,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 219,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 220,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 244,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 39,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 40,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 47,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 168,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 169,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 170,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 171,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 172,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 173,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 174,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 175,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 176,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 177,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 178,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 179,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 180,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 181,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 184,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 185,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 186,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 187,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 188,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 194,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 200,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 201,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 202,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 203,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 204,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 205,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 206,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 215,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 216,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 221,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 222,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 223,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 224,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 225,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 226,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 227,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 228,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 229,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 230,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 231,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 232,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 256,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 249,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 79,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 150,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 161,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 148,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 160,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 165,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 237,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 52,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 151,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 149,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 325,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 324,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 280,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 322,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 331,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 330,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 329,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 328,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 7,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 12,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 1,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 281,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 282,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 133,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 252,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 253,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 254,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 260,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 259,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 258,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 257,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 247,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 250,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 238,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 239,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 69,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 66,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 72,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 74,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 65,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 55,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 56,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 45,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 46,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 34,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 35,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 41,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 42,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 29,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 24,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 37,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 36,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 109,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 110,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 17,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 16,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 112,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 113,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 127,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 130,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 145,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 81,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 82,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 144,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 190,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 323,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 13,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 14,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 15,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 30,
        .u8CoreId =1
    },
    {
        .u16Port_Pin = 261,
        .u8CoreId =1
    },
};
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"
/* End of File */


#ifdef __cplusplus
}
#endif
