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
*   @file    Lin_HAL_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Lin - Isolation level header file for LIN driver.
*   @details Header file for function definition on isolation level betwen high and low level driver.
*
*   @addtogroup Lin
*   @{
*/
/*PRQA S 2844,2934 EOF*/
#include "Lin.h"/* PRQA S 0380 */
#include "Lin_HAL_Wrapper.h"
#include "Lin_LLDriver.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_HAL_C_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_HAL_C_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_HAL_C_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_HAL_C_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_HAL_C_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_HAL_C_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_HAL_C_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_HAL_C_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_HAL_C_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_HAL_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_HAL_C_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_HAL_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_HAL_C_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_HAL_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_HAL_C_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_HAL_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_HAL_C_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_HAL_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_HAL_C_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_HAL_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_HAL_C_SW_PATCH_VER "
#endif

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
volatile Lin_Configs g_sLin_HW_Config[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
extern volatile VAR(uint8, LIN_VAR) u8Lin_TransmitHeaderCmd[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(uint8, LIN_CODE) Lin_Wrapper_GetChannel(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#if (LIN_MASTER_NODE_USED == STD_ON)
#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
static volatile VAR(uint8,LIN_VAR) g_u8Lin_ChHeaderStatus[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
#endif

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
LIN_INLINE FUNC(uint8, LIN_CODE) Lin_Wrapper_GetChannel(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
	VAR(uint8, AUTOMATIC) LinHwCh = 0;
    if (u8Lin_Channel < LIN_HW_MAX_AVAILABLE_MODULES) 
    {
        if(g_pLin_ChannelConfigPtr[u8Lin_Channel] != NULL)
        {
            LinHwCh = g_pLin_ChannelConfigPtr[u8Lin_Channel]->u8LinHwChannel;/* PRQA S 2844 */ /* polyspace RTE:OBAI */
        }
	    
    }
    return LinHwCh;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_Wrapper_Init(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
	VAR(uint8, AUTOMATIC) LinHwCh = 0;
	LinHwCh = Lin_Wrapper_GetChannel(u8Lin_Channel);
	static VAR(LinLldConfig, AUTOMATIC) s_sLin_Config[LIN_HW_MAX_AVAILABLE_MODULES];
	u8Lin_ChStatus[LinHwCh] = LIN_CH_SLEEP_STATE; /* polyspace RTE:OBAI */
	u8Lin_ChFrameStatus[LinHwCh] = LIN_CH_NOT_READY_STATE;
	u8Lin_TransmitHeaderCmd[LinHwCh] = LIN_TX_NO_COMMAND_U8;
	u8Lin_ChFrameErrorStatus[LinHwCh] = LIN_NO_ERROR;
#if (LIN_MASTER_NODE_USED == STD_ON)
        g_u8Lin_ChHeaderStatus[LinHwCh] = (uint8)FALSE;
#endif

    if(g_pLin_ChannelConfigPtr[u8Lin_Channel]->eLinNodeType == LIN_MASTER_NODE)
    {
        s_sLin_Config[u8Lin_Channel].mode = LIN_MASTER;
    }
    else
    {
        s_sLin_Config[u8Lin_Channel].mode = LIN_SLAVE;
    }

    s_sLin_Config[u8Lin_Channel].DmaTxChannel = g_pLin_ChannelConfigPtr[u8Lin_Channel]->DmaTxChannel;
    s_sLin_Config[u8Lin_Channel].DmaRxChannel = g_pLin_ChannelConfigPtr[u8Lin_Channel]->DmaRxChannel;
    s_sLin_Config[u8Lin_Channel].api_mode = LIN_API_MODE_SYNCHRONOUS;
    s_sLin_Config[u8Lin_Channel].speed = g_pLin_ChannelConfigPtr[u8Lin_Channel]->u32Lin_BaudRate_RegValue;

    g_sLin_HW_Config[LinHwCh].mbl = g_pLin_ChannelConfigPtr[u8Lin_Channel]->u8LinChannelBrkLengthMaster;
    g_sLin_HW_Config[LinHwCh].sbl = g_pLin_ChannelConfigPtr[u8Lin_Channel]->u8LinChannelBrkLengthSlave;
    g_sLin_HW_Config[LinHwCh].rto = g_pLin_ChannelConfigPtr[u8Lin_Channel]->u8ResponseTimeout;
    g_sLin_HW_Config[LinHwCh].hto = g_pLin_ChannelConfigPtr[u8Lin_Channel]->u8HeaderTimeout;
    g_sLin_HW_Config[LinHwCh].DmaSupport = g_pLin_ChannelConfigPtr[u8Lin_Channel]->u8LinDmaSupport;
    g_sLin_HW_Config[LinHwCh].WakeupSupport = g_pLin_ChannelConfigPtr[u8Lin_Channel]->u16LinChannelWakeupSupport;
    g_sLin_HW_Config[LinHwCh].WakeupSource = g_pLin_ChannelConfigPtr[u8Lin_Channel]->LinChannelEcuMWakeupSource;
    g_sLin_HW_Config[LinHwCh].LinNotificationFunc = g_pLin_ChannelConfigPtr[u8Lin_Channel]->LinNotificationFunc;

    

    Lin_LLD_Init(LinHwCh, &(s_sLin_Config[u8Lin_Channel]));
    Lin_LLD_Start(LinHwCh);

}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#if (LIN_MASTER_NODE_USED == STD_ON)
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_Wrapper_SendResponse(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr)
{
	VAR(uint8, AUTOMATIC) LinHwCh = 0;
	LinHwCh = Lin_Wrapper_GetChannel(u8Lin_Channel);
    if (LIN_FRAMERESPONSE_TX == spLin_PduInfoPtr->Drc)
    {
        g_u8Lin_ChHeaderStatus[LinHwCh] = (uint8)TRUE;/* PRQA S 2844 */ /* polyspace RTE:OBAI */
    }
    if ((uint8)FALSE != g_u8Lin_ChHeaderStatus[LinHwCh])/* PRQA S 2844 */ /* polyspace RTE:OBAI */
    {
        g_u8Lin_ChHeaderStatus[LinHwCh] = (uint8)FALSE;/* PRQA S 2844 */
        (void)Lin_LLD_Master_Transmit(LinHwCh, spLin_PduInfoPtr);
    }
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_Wrapper_SendHeader(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr)
{
	VAR(uint8, AUTOMATIC) LinHwCh = 0;
	LinHwCh = Lin_Wrapper_GetChannel(u8Lin_Channel);
    return Lin_LLD_Master_Transmit(LinHwCh, spLin_PduInfoPtr);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#endif

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_Wrapper_CheckWakeup(VAR(uint8, AUTOMATIC) u8Lin_Channel)
{
	VAR(uint8, AUTOMATIC) LinHwCh = 0;
	LinHwCh = Lin_Wrapper_GetChannel(u8Lin_Channel);
    return Lin_LLD_CheckWakeup(LinHwCh);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (Std_ReturnType, LIN_CODE) Lin_Wrapper_GoToSleep(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = E_NOT_OK;
	VAR(uint8, AUTOMATIC) LinHwCh = 0;
	LinHwCh = Lin_Wrapper_GetChannel(u8Lin_Channel);
    if(LIN_CH_SLEEP_STATE == u8Lin_ChStatus[LinHwCh])/* PRQA S 2844 */ /* polyspace RTE:OBAI */
    {
        u8Lin_ReturnValue = E_OK;
    }
    else
    {
        u8Lin_ReturnValue =  Lin_LLD_GoToSleep(LinHwCh);
        u8Lin_ChStatus[LinHwCh] = LIN_CH_SLEEP_PENDING;/* PRQA S 2844 */
    }
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (Std_ReturnType, LIN_CODE) Lin_Wrapper_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel)/* PRQA S 2844 */
{
	VAR(uint8, AUTOMATIC) LinHwCh = 0;
	LinHwCh = Lin_Wrapper_GetChannel(u8Lin_Channel);
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = E_NOT_OK;
    if (LIN_CH_SLEEP_STATE == u8Lin_ChStatus[LinHwCh])/* PRQA S 2844 */ /* polyspace RTE:OBAI */
    {
        u8Lin_ReturnValue = E_OK;
    }
    else
    {
        u8Lin_ReturnValue = Lin_LLD_GoToSleepInternal(LinHwCh);
        if(u8Lin_ReturnValue == (uint8)E_OK)
        {
            u8Lin_ChStatus[LinHwCh] = LIN_CH_SLEEP_STATE;/* PRQA S 2844 */
            u8Lin_ChFrameStatus[LinHwCh] = LIN_CH_NOT_READY_STATE;/* PRQA S 2844 */
        }
    }
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_Wrapper_WakeUp(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    VAR(uint8, AUTOMATIC) LinHwCh = 0;
    LinHwCh = Lin_Wrapper_GetChannel(u8Lin_Channel);
	u8Lin_ChStatus[LinHwCh] = LIN_CH_OPERATIONAL;/* PRQA S 2844 */ /* polyspace RTE:OBAI */
    u8Lin_ChFrameStatus[LinHwCh] = LIN_CH_READY_STATE;/* PRQA S 2844 */
    u8Lin_ChFrameErrorStatus[LinHwCh] = LIN_NO_ERROR;/* PRQA S 2844 */
    Lin_LLD_Wakeup(LinHwCh);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (void, LIN_CODE) Lin_Wrapper_WakeUpInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    VAR(uint8, AUTOMATIC) LinHwCh = 0;
    LinHwCh = Lin_Wrapper_GetChannel(u8Lin_Channel);
    u8Lin_ChStatus[LinHwCh] = LIN_CH_OPERATIONAL;/* PRQA S 2844 */ /* polyspace RTE:OBAI */
    u8Lin_ChFrameStatus[LinHwCh] = LIN_CH_READY_STATE;/* PRQA S 2844 */
    u8Lin_ChFrameErrorStatus[LinHwCh] = LIN_NO_ERROR;/* PRQA S 2844 */
    Lin_LLD_WakeupInternal(LinHwCh);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (Lin_StatusType, LIN_CODE) Lin_Wrapper_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) u8pLin_SduPtr)/* PRQA S 3432 */
{
    VAR(uint8, AUTOMATIC) LinHwCh = 0;
    LinHwCh = Lin_Wrapper_GetChannel(u8Lin_Channel);
    return Lin_LLD_HardwareGetStatus(LinHwCh, u8pLin_SduPtr);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
