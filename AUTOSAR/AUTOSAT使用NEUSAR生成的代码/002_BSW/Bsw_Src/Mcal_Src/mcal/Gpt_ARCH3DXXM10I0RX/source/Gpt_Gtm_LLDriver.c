
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30XX
* DESCRIPTION : CCFC30XX GTM TOM low level drivers code
* HISTORY     : Initial version
* @file     Gpt_Gtm_LLDriver.c
* @version  3.0.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 0380,3432,2844,0310 EOF */

#ifdef __cplusplus
extern "C"{
#endif

#include "Gpt_Gtm_LLDriver.h"
#include "Gpt_Irq.h"
#include "Gpt_AutoSar_Wrapper.h"
#include "Gpt_Cfg.h"
#include "SchM_Gpt.h"
#if (defined(RESOURCE_SUPPORT_GTM104) )
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define GPT_VENDOR_ID_C                 176
#define GPT_AR_MAJOR_VER_C              4
#define GPT_AR_MINOR_VER_C              4
#define GPT_AR_PATCH_VER_C              0
#define GPT_SW_MAJOR_VER_C              3
#define GPT_SW_MINOR_VER_C              0
#define GPT_SW_PATCH_VER_C              0

/*============================================FILE VERSION CHECKS===================================*/

/* Check if current file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_C != GPT_VENDOR_ID)
#error "NON-MATCHED DATA : GPT_VENDOR_ID"
#endif

/* Check if current file and GPT header file are of the same Autosar version */
#if (GPT_AR_MAJOR_VER_C != GPT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER"
#endif
#if (GPT_AR_MINOR_VER_C != GPT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER"
#endif
#if (GPT_AR_PATCH_VER_C != GPT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER"
#endif

/* Check if current file and GPT header file are of the same Software version */
#if (GPT_SW_MAJOR_VER_C != GPT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER"
#endif
#if (GPT_SW_MINOR_VER_C != GPT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER"
#endif
#if (GPT_SW_PATCH_VER_C != GPT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER"
#endif




extern P2CONST(Gpt_ConfigType, GPT_VAR,  GPT_APPL_CONST)  sGpt_pConfig[GPT_MAX_PARTITION];

#define GPT_START_SEC_VAR_INIT
#include "Gpt_MemMap.h"
P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC,GPT_APPL_DATA) g_GPT_GTM_TOM_Base[5U];
P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC,GPT_APPL_DATA) g_GPT_GTM_TOM_Base[5U] = {
										 GPT_GTM_TOM_0_BASE_ADDR, \
                                         GPT_GTM_TOM_1_BASE_ADDR, \
                                         GPT_GTM_TOM_2_BASE_ADDR, \
                                         GPT_GTM_TOM_3_BASE_ADDR, \
                                         GPT_GTM_TOM_4_BASE_ADDR  \
};
#define GPT_STOP_SEC_VAR_INIT
#include "Gpt_MemMap.h"


#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(GPT_GTM_TOM_Type, GPT_CODE) Gpt_GTM_LLD_ConvertModuleId
(
		VAR(uint8, AUTOMATIC)u8Module
)
{
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId;
    switch(u8Module)
    {
        #ifdef RESOURCE_SUPPORT_GTM_TOM0
        case 0u:
            eModuleId = GPT_GTM_TOM0;
        break;
        #endif
        #ifdef RESOURCE_SUPPORT_GTM_TOM1
        case 1u:
            eModuleId = GPT_GTM_TOM1;
        break;
        #endif
        #ifdef RESOURCE_SUPPORT_GTM_TOM2
        case 2u:
            eModuleId = GPT_GTM_TOM2;
        break;
        #endif
        #ifdef RESOURCE_SUPPORT_GTM_TOM3
        case 3u:
            eModuleId = GPT_GTM_TOM3;
        break;
        #endif
        #ifdef RESOURCE_SUPPORT_GTM_TOM4
        case 4u:
            eModuleId = GPT_GTM_TOM4;
        break;
        #endif
        #ifdef RESOURCE_SUPPORT_GTM_TOM5
        case 5u:
            eModuleId = GPT_GTM_TOM5;
        break;
        #endif
        default:
            eModuleId = GPT_GTM_TOM0;
        break;
    }
    return eModuleId;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(GPT_GTM_TOM_Channel_Type, GPT_CODE) Gpt_Gtm_LLD_ConvertChannelId(VAR(uint8, AUTOMATIC)u8Channel)
{
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId;
    switch(u8Channel)
    {
        case 0u:
            eChannelId = GPT_GTM_TOM_CH0;
        break;
        case 1u:
            eChannelId = GPT_GTM_TOM_CH1;
        break;
        case 2u:
            eChannelId = GPT_GTM_TOM_CH2;
        break;
        case 3u:
            eChannelId = GPT_GTM_TOM_CH3;
        break;
        case 4u:
            eChannelId = GPT_GTM_TOM_CH4;
        break;
        case 5u:
            eChannelId = GPT_GTM_TOM_CH5;
        break;
        case 6u:
            eChannelId = GPT_GTM_TOM_CH6;
        break;
        case 7u:
            eChannelId = GPT_GTM_TOM_CH7;
        break;
        case 8u:
            eChannelId = GPT_GTM_TOM_CH8;
        break;
        case 9u:
            eChannelId = GPT_GTM_TOM_CH9;
        break;
        case 10u:
            eChannelId = GPT_GTM_TOM_CH10;
        break;
        case 11u:
            eChannelId = GPT_GTM_TOM_CH11;
        break;
        case 12u:
            eChannelId = GPT_GTM_TOM_CH12;
        break;
        case 13u:
            eChannelId = GPT_GTM_TOM_CH13;
        break;
        case 14u:
            eChannelId = GPT_GTM_TOM_CH14;
        break;
        case 15u:
            eChannelId = GPT_GTM_TOM_CH15;
        break;
        default:
            eChannelId = GPT_GTM_TOM_CH0;
        break;
    }
    return eChannelId;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) Gpt_GTM_TOM_LLD_IsEnableOneShotMode  \
( 																    \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					    \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 					\
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            GPT_GTM_TOM_n->CH0_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            GPT_GTM_TOM_n->CH1_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            GPT_GTM_TOM_n->CH2_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            GPT_GTM_TOM_n->CH3_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            GPT_GTM_TOM_n->CH4_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            GPT_GTM_TOM_n->CH5_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            GPT_GTM_TOM_n->CH6_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            GPT_GTM_TOM_n->CH7_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            GPT_GTM_TOM_n->CH8_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            GPT_GTM_TOM_n->CH9_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            GPT_GTM_TOM_n->CH10_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            GPT_GTM_TOM_n->CH11_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            GPT_GTM_TOM_n->CH12_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            GPT_GTM_TOM_n->CH13_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            GPT_GTM_TOM_n->CH14_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            GPT_GTM_TOM_n->CH15_CTRL.B.OSM = (uint8)IsEnable;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
VAR(uint32, AUTOMATIC) Gpt_GTM_TOM_LLD_Channel_GetCompareRegister   \
(                                                                   \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,                      \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn                    \
)
{
    VAR(uint32, AUTOMATIC) u32Gpt_ReturnValue = 0;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH0_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH1_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH2_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH3_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH4_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH5_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH6_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH7_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH8_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH9_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH10_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH11_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH12_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH13_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH14_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            u32Gpt_ReturnValue = (uint16)GPT_GTM_TOM_n->CH15_CM0.B.CM0; /* polyspace RTE:NIV */
            break;
        }
        default:
        {
            u32Gpt_ReturnValue = 0;
            break;
        }
    }

    return u32Gpt_ReturnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SelectClockSource 	\
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_TOM_ClockSource_Type, AUTOMATIC) ClockSource 		\
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            GPT_GTM_TOM_n->CH0_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            GPT_GTM_TOM_n->CH1_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            GPT_GTM_TOM_n->CH2_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            GPT_GTM_TOM_n->CH3_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            GPT_GTM_TOM_n->CH4_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            GPT_GTM_TOM_n->CH5_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            GPT_GTM_TOM_n->CH6_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            GPT_GTM_TOM_n->CH7_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            GPT_GTM_TOM_n->CH8_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            GPT_GTM_TOM_n->CH9_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            GPT_GTM_TOM_n->CH10_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            GPT_GTM_TOM_n->CH11_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            GPT_GTM_TOM_n->CH12_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            GPT_GTM_TOM_n->CH13_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            GPT_GTM_TOM_n->CH14_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            GPT_GTM_TOM_n->CH15_CTRL.B.CLK_SRC_SR = (uint8)ClockSource;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SelectCCU0ResetSource  \
(                                                                     \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,                        \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn,                     \
    VAR(GPT_GTM_TOM_CCU0ResetSource_Type, AUTOMATIC) CCU0ResetSource  \
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            GPT_GTM_TOM_n->CH0_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            GPT_GTM_TOM_n->CH1_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            GPT_GTM_TOM_n->CH2_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            GPT_GTM_TOM_n->CH3_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            GPT_GTM_TOM_n->CH4_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            GPT_GTM_TOM_n->CH5_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            GPT_GTM_TOM_n->CH6_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            GPT_GTM_TOM_n->CH7_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            GPT_GTM_TOM_n->CH8_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            GPT_GTM_TOM_n->CH9_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            GPT_GTM_TOM_n->CH10_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            GPT_GTM_TOM_n->CH11_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            GPT_GTM_TOM_n->CH12_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            GPT_GTM_TOM_n->CH13_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            GPT_GTM_TOM_n->CH14_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            GPT_GTM_TOM_n->CH15_CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;     
        }
    }

	return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SetShadowRegister \
( 																 \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					 \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 				 \
    uint16 SR0, 												 \
    uint16 SR1 													 \
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            GPT_GTM_TOM_n->CH0_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH0_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            GPT_GTM_TOM_n->CH1_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH1_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            GPT_GTM_TOM_n->CH2_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH2_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            GPT_GTM_TOM_n->CH3_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH3_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            GPT_GTM_TOM_n->CH4_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH4_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            GPT_GTM_TOM_n->CH5_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH5_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            GPT_GTM_TOM_n->CH6_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH6_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            GPT_GTM_TOM_n->CH7_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH7_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            GPT_GTM_TOM_n->CH8_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH8_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            GPT_GTM_TOM_n->CH9_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH9_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            GPT_GTM_TOM_n->CH10_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH10_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            GPT_GTM_TOM_n->CH11_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH11_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            GPT_GTM_TOM_n->CH12_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH12_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            GPT_GTM_TOM_n->CH13_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH13_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            GPT_GTM_TOM_n->CH14_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH14_SR1.B.SR1 = SR1;
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            GPT_GTM_TOM_n->CH15_SR0.B.SR0 = SR0;
            GPT_GTM_TOM_n->CH15_SR1.B.SR1 = SR1;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SetCompareRegister \
( 													\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 		\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 	\
    uint16 CM0, 									\
    uint16 CM1 										\
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    st_Gpt_GTM_TOM_tag* GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            GPT_GTM_TOM_n->CH0_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH0_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            GPT_GTM_TOM_n->CH1_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH1_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            GPT_GTM_TOM_n->CH2_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH2_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            GPT_GTM_TOM_n->CH3_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH3_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            GPT_GTM_TOM_n->CH4_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH4_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            GPT_GTM_TOM_n->CH5_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH5_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            GPT_GTM_TOM_n->CH6_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH6_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            GPT_GTM_TOM_n->CH7_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH7_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            GPT_GTM_TOM_n->CH8_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH8_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            GPT_GTM_TOM_n->CH9_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH9_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            GPT_GTM_TOM_n->CH10_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH10_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            GPT_GTM_TOM_n->CH11_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH11_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            GPT_GTM_TOM_n->CH12_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH12_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            GPT_GTM_TOM_n->CH13_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH13_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            GPT_GTM_TOM_n->CH14_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH14_CM1.B.CM1 = CM1;
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            GPT_GTM_TOM_n->CH15_CM0.B.CM0 = CM0;
            GPT_GTM_TOM_n->CH15_CM1.B.CM1 = CM1;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SetCounter \
( 												  \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 	  \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, \
    VAR(uint16, AUTOMATIC) CN0                    \
)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            GPT_GTM_TOM_n->CH0_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            GPT_GTM_TOM_n->CH1_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            GPT_GTM_TOM_n->CH2_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            GPT_GTM_TOM_n->CH3_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            GPT_GTM_TOM_n->CH4_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            GPT_GTM_TOM_n->CH5_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            GPT_GTM_TOM_n->CH6_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            GPT_GTM_TOM_n->CH7_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            GPT_GTM_TOM_n->CH8_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            GPT_GTM_TOM_n->CH9_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            GPT_GTM_TOM_n->CH10_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            GPT_GTM_TOM_n->CH11_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            GPT_GTM_TOM_n->CH12_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            GPT_GTM_TOM_n->CH13_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            GPT_GTM_TOM_n->CH14_CN0.B.CN0 = CN0;
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            GPT_GTM_TOM_n->CH15_CN0.B.CN0 = CN0;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint8, GPT_CODE) GPT_GTM_TOM_LLD_GetInterruptFlag 	 \
( 														 \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 			 \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 		 \
    VAR(GPT_GTM_TOM_Interrupt_Type, AUTOMATIC) Interrupt \
)
{
	VAR(uint8, AUTOMATIC) Ret = 0;
    P2CONST(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            switch(Interrupt)
            {
                case GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH0_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */	
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH0_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH1_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH1_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH2_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH2_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH3_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH3_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH4_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH4_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH5_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH5_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH6_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH6_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH7_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH7_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH8_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH8_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH9_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH9_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH10_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH10_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH11_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH11_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH12_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH12_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH13_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH13_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH14_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH14_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH15_IRQ_NOTIFY.B.CCU0TC; /* polyspace RTE:NIV */
                    break;
                }

                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    Ret = (uint8)GPT_GTM_TOM_n->CH15_IRQ_NOTIFY.B.CCU1TC;
                    break;
                }

                default:
                {
                    Ret = (uint8)0;
                    break;
                }
            }
            break;
        }
        default:
        {
            Ret = (uint8)0;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_ClearInterruptFlag \
( 																  \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					  \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 				  \
    VAR(GPT_GTM_TOM_Interrupt_Type, AUTOMATIC) Interrupt 		  \
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH0_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH0_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH1_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH1_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH2_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH2_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH3_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH3_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH4_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH4_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                     GPT_GTM_TOM_n->CH5_IRQ_NOTIFY.R= 1u;
                     break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH5_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH6_IRQ_NOTIFY.R= 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH6_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH7_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH7_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH8_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH8_IRQ_NOTIFY.R= 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH9_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH9_IRQ_NOTIFY.R= 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH10_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH10_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                     GPT_GTM_TOM_n->CH11_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH11_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH12_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH12_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH13_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH13_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH14_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH14_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH15_IRQ_NOTIFY.R = 1u;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH15_IRQ_NOTIFY.R = 2u;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableInterrupt 	\
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_TOM_Interrupt_Type, AUTOMATIC) Interrupt, 			\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 					\
)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH0_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH0_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH1_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH1_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH2_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH2_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH3_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH3_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH4_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH4_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH5_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH5_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH6_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH6_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH7_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH7_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH8_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH8_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH9_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH9_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH10_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH10_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH11_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH11_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH12_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH12_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH13_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH13_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH14_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH14_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            switch(Interrupt)
            {
                case  GPT_GTM_TOM_IRQ_CCU0TC:
                {
                    GPT_GTM_TOM_n->CH15_IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                case  GPT_GTM_TOM_IRQ_CCU1TC:
                {
                    GPT_GTM_TOM_n->CH15_IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;
                    break;
                }
                default:
                {
                    Ret = (Std_ReturnType)E_NOT_OK;
                    break;
                }

            }
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableUpdate \
( 															  \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 				  \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 			  \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 			  \
)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];
    VAR(uint8, AUTOMATIC) IsEnable_l = (uint8)IsEnable;

    if((uint8)IsEnable_l  == 1u)
    {
    	IsEnable_l = (uint8)2u;
    }
    else
    {
    	IsEnable_l = (uint8)1u;
    }

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            GPT_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL0 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            GPT_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL1 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            GPT_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL2 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            GPT_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL3 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            GPT_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL4 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            GPT_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL5 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            GPT_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL6 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            GPT_GTM_TOM_n->TGC0_GLB_CTRL.B.UPEN_CTRL7 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            GPT_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL8 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            GPT_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL9 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            GPT_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL10 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            GPT_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL11 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            GPT_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL12 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            GPT_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL13 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            GPT_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL14 =(uint8) IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            GPT_GTM_TOM_n->TGC1_GLB_CTRL.B.UPEN_CTRL15 = (uint8)IsEnable_l;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) GPT_GTM_TOM_LLD_GetCounter \
(                                                 \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,    \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn  \
)
{
	VAR(uint32, AUTOMATIC) u32Ret = 0;
    P2CONST(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_CONST) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            u32Ret = (uint16)GPT_GTM_TOM_n->CH0_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            u32Ret = (uint16)GPT_GTM_TOM_n->CH1_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH2_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH3_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH4_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH5_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH6_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH7_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH8_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH9_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH10_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH11_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH12_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH13_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH14_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            u32Ret = (uint16) GPT_GTM_TOM_n->CH15_CN0.B.CN0; /* polyspace RTE:NIV */
            break;
        }
        default:
        {
            u32Ret = 0;
            break;
        }
    }

    return u32Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableChannel 	\
( 																\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 				\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 				\
)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    VAR(uint8, AUTOMATIC) IsEnable_l = 0;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];

    if((uint8)IsEnable  == 1U)
    {
        IsEnable_l = 2;
    }
    else
    {
        IsEnable_l = 1;
    }

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            GPT_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT0 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            GPT_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT1 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            GPT_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT2 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            GPT_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT3 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            GPT_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT4 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            GPT_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT5 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            GPT_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT6 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            GPT_GTM_TOM_n->TGC0_ENDIS_STAT.B.ENDIS_STAT7 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            GPT_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT8 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            GPT_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT9 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            GPT_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT10 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            GPT_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT11 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            GPT_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT12 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            GPT_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT13 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            GPT_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT14 = (uint8)IsEnable_l;
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            GPT_GTM_TOM_n->TGC1_ENDIS_STAT.B.ENDIS_STAT15 = (uint8)IsEnable_l;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableOut \
(                                                 \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,    \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable  \
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
	VAR(uint8, AUTOMATIC) Status = 0;
    P2VAR(st_Gpt_GTM_TOM_tag, AUTOMATIC, GPT_APPL_DATA) GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[GTM_TOMn];/* polyspace RTE:OBAI */

    if((uint8)IsEnable  == 1U)
    {
    	Status = 2;
    }
    else
    {
    	Status = 1;
    }

    switch(CHn)
    {
        case GPT_GTM_TOM_CH0:
        {
            GPT_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT0 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH1:
        {
            GPT_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT1 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH2:
        {
            GPT_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT2 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH3:
        {
            GPT_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT3 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH4:
        {
            GPT_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT4 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH5:
        {
            GPT_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT5 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH6:
        {
            GPT_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT6 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH7:
        {
            GPT_GTM_TOM_n->TGC0_OUTEN_STAT.B.OUTEN_STAT7 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH8:
        {
            GPT_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT8 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH9:
        {
            GPT_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT9 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH10:
        {
            GPT_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT10 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH11:
        {
            GPT_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT11 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH12:
        {
            GPT_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT12 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH13:
        {
            GPT_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT13 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH14:
        {
            GPT_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT14 = (uint8)Status;
            break;
        }
        case GPT_GTM_TOM_CH15:
        {
            GPT_GTM_TOM_n->TGC1_OUTEN_STAT.B.OUTEN_STAT15 = (uint8)Status;
            break;
        }
        default:
        {
            Ret = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(Std_ReturnType, GPT_CODE) GPT_GTMINT_LLD_IsEnableModule(VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable)
{
    static P2VAR(st_Gpt_GTMINT_tag, AUTOMATIC, GPT_APPL_DATA) g_GPT_GTMINT_Base[1] = {
										 GPT_GTMINT_BASE_ADDR};
    VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
	VAR(uint8, AUTOMATIC) Status = 0;
	if((uint8)IsEnable != 0u)	 /*PRQA S 1881 */
	{
		Status = 0u;
	}
	else
	{
		Status = 1u;
	}

    g_GPT_GTMINT_Base[0]->GTMMCR.B.MDIS = (uint32)Status;

	if(g_GPT_GTMINT_Base[0]->GTMMCR.B.MDIS != (uint32)Status)
	{
		Ret = (Std_ReturnType)E_NOT_OK;
	}
	return Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

///////////  GTM ////////////////
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) GPT_GTM_LLD_Reset(void)
{
    GTM.RST.B.RST = 1u;
}

FUNC(void, GPT_CODE) GPT_TOM_LLD_IRQHandler 				\
( 															\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) TOM_ModuleID, 			\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) TOM_ChannelID 	\
)
{
	VAR(uint8, AUTOMATIC) u8Channel = 0;
    VAR(uint32, AUTOMATIC) Gtm_CoreIndex = Gpt_GetCoreID();

    uint32* pIrqNotify;
    volatile uint32* pChStat;
    st_Gpt_GTM_TOM_tag* GPT_GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[TOM_ModuleID];

    VAR(Gpt_ChannelType, AUTOMATIC) u8Gpt_Instance = ((uint8)TOM_ModuleID * (uint8)GPT_GTM_CHANNEL_MAX) + (uint8)TOM_ChannelID + (uint8)GPT_GTM_MODULE_INDEX;
    u8Channel = sGpt_pConfig[Gtm_CoreIndex]->Gpt_aHw2LogicChannelMap[u8Gpt_Instance]; /* polyspace RTE:IDP */
    

#if (GPT_ENABLE_MULTICORE == STD_ON)
    P2VAR(Gpt_Wrapper_ChannelInfo, AUTOMATIC, GPT_APPL_DATA) pChannelInfo = NULL_PTR;

    VAR(uint32, AUTOMATIC) CurrentCoreId = 1 << Gpt_GetCoreID();

    pChannelInfo = Gpt_AutoSar_Wrapper_GetChannelInfo(u8Channel);

    VAR(uint8, AUTOMATCI) Temp = CurrentCoreId & pChannelInfo->pGpt_CoreId[u8Channel];

    if(Temp != (uint8)0u)
#endif
    {

    	pIrqNotify = (uint32*)((uint32)(&GPT_GPT_GTM_TOM_n->CH0_IRQ_NOTIFY.R) + (uint32)(0x40u * (uint32)TOM_ChannelID));
		*pIrqNotify = 3;  /* polyspace RTE:IDP */

		if (GPT_CH_MODE_ONESHOT == (*(sGpt_pConfig[Gtm_CoreIndex]->pChannelConfig))[u8Channel].eChannelMode) /* polyspace RTE:IDP,OBAI */
		{
			SchM_Enter_Gpt_EXCLUSIVE_AREA_16();

			if((uint32)TOM_ChannelID < 8u)
			{
				pChStat = (volatile uint32*)&GPT_GPT_GTM_TOM_n->TGC0_ENDIS_STAT.R;
				*pChStat = 1UL << ((uint32)TOM_ChannelID * 2UL);
			}
			else
			{
				pChStat = (volatile uint32*)&GPT_GPT_GTM_TOM_n->TGC1_ENDIS_STAT.R;
				*pChStat = 1UL << (((uint32)TOM_ChannelID - 8u) * 2UL);
			}

			SchM_Exit_Gpt_EXCLUSIVE_AREA_16();
		}

		Gpt_ProcessCommonIrq(u8Channel);
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#ifdef __cplusplus
}
#endif
#endif
