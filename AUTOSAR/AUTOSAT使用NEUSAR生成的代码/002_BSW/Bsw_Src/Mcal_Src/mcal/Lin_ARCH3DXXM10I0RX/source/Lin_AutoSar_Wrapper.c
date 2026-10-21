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
*   @file    Lin_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Lin - Isolation level file for LIN driver.
*   @details Implementation file for function definition on isolation level betwen high and low level driver.
*
*   @addtogroup MCAL
*   @{
*/


#ifdef __cplusplus
extern "C"
{
#endif

/* ==============================================INCLUDE FILES======================================= */

#include "Lin_AutoSar_Wrapper.h"/* PRQA S 0380,1006,0491 EOF*/
#include "Lin_HAL_Wrapper.h"
#include "Lin_LLDriver.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_ATS_C_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_ATS_C_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_ATS_C_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_ATS_C_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_ATS_C_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_ATS_C_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_ATS_C_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_ATS_C_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_ATS_C_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_ATS_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_ATS_C_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_ATS_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_ATS_C_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_ATS_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_ATS_C_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_ATS_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_ATS_C_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_ATS_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_ATS_C_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_ATS_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_ATS_C_SW_PATCH_VER "
#endif
/* =========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)=============================== */

/* ======================================LOCAL MACROS================================================ */


/* ======================================LOCAL CONSTANTS============================================= */


/* ======================================LOCAL VARIABLES============================================= */

/* ======================================GLOBAL CONSTANTS============================================ */

/* ======================================GLOBAL VARIABLES============================================ */
#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
extern P2CONST(Lin_ChannelConfigType,LIN_VAR,LIN_APPL_CONST) g_pLin_ChannelConfigPtr[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

/* ==================================LOCAL FUNCTION PROTOTYPES=======================================*/

/* ======================================LOCAL FUNCTIONS=============================================*/

/* ======================================GLOBAL FUNCTIONS============================================*/
/*****************************************************************************
** Service Name      : Lin_AutoSar_Wrapper_InitChannel
**
**
**  Description      : This function initialize a LIN channel.
**
**  Parameters (in)  : u8Lin_Channel   : LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (void, LIN_CODE) Lin_AutoSar_Wrapper_InitChannel(void)
{
	VAR(uint8,AUTOMATIC) u8Lin_Count = 0;

#if (LIN_MULTICORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)(GetCoreID());/*comment get core id*/
#endif
    while(u8Lin_Count < g_pLin_GenerateConfigPBPtr->u8Lin_MaxHWChannels)
    {
#if (LIN_MULTICORE_SUPPORT == STD_ON)
        if((u32CoreID == (g_pLin_GenerateConfigPBPtr->coreMap[u8Lin_Count].u8CoreId)))
#endif
        {

            g_pLin_ChannelConfigPtr[u8Lin_Count] = g_pLin_GenerateConfigPBPtr->pLin_Channel[u8Lin_Count];/* PRQA S 2844 */ /* polyspace RTE:OBAI */
        
            Lin_Wrapper_Init(u8Lin_Count);

            s8Lin_ChannelHardwareMap[g_pLin_ChannelConfigPtr[u8Lin_Count]->u8LinChannelID]/* PRQA S 2844 */ /* polyspace RTE:OBAI */
                    = (sint8)g_pLin_ChannelConfigPtr[u8Lin_Count]->u8LinHwChannel;/* PRQA S 2844 */

        }
        u8Lin_Count++;
    }
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#if (LIN_MASTER_NODE_USED == STD_ON)
/*****************************************************************************
** Service Name      : Lin_AutoSar_Wrapper_SendResponse
**
**
**  Description      : This function sends frame.
**
**  Parameters (in)  : u8Lin_Channel    : Hardware Lin channel Id.
**                     spLin_PduInfoPtr : This is used to provide PID, checksum model,
**                                  data length and SDU pointer from the LIN
**                                  Interface to the LIN driver.
**                     Mode       : Master or slave mode.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_AutoSar_Wrapper_SendResponse(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr)
{
    Lin_Wrapper_SendResponse(u8Lin_Channel, spLin_PduInfoPtr);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/*****************************************************************************
** Service Name      : Lin_AutoSar_Wrapper_SendHeader
**
**
**  Description      : This function sends frame.
**
**  Parameters (in)  : u8Lin_Channel    : Hardware Lin channel Id.
**                     spLin_PduInfoPtr : This is used to provide PID, checksum model,
**                                  data length and SDU pointer from the LIN
**                                  Interface to the LIN driver.
**                     Mode       : Master or slave mode.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_AutoSar_Wrapper_SendHeader(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr)
{
    
    return Lin_Wrapper_SendHeader(u8Lin_Channel, spLin_PduInfoPtr);

}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*****************************************************************************
** Service Name      : Lin_AutoSar_Wrapper_HardwareGetStatus
**
**
**  Description      : This function gets the status of the LIN driver when
**                     Channel is operating.
**
**  Parameters (in)  : u8Lin_Channel      : LIN channel to be addressed.
**                     u8pLin_SduPtr : Pointer to pointer to a shadow buffer or
**                                    memory mapped LIN Hardware receive buffer
**                                    where the  current SDU is stored.
**
**  Parameters (out) : None
**
**  Return value     : Lin_StatusType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (Lin_StatusType, LIN_CODE) Lin_AutoSar_Wrapper_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) u8pLin_SduPtr)/* PRQA S 3432 */
{
    return Lin_Wrapper_HardwareGetStatus(u8Lin_Channel, u8pLin_SduPtr);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*****************************************************************************
** Service Name      : Lin_AutoSar_Wrapper_GoToSleep
**
**
**  Description      : This function go to LIN sleep mode.
**
**  Parameters (in)  : u8Lin_Channel : Hardware Lin channel Id.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (Std_ReturnType, LIN_CODE) Lin_AutoSar_Wrapper_GoToSleep(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{

    return Lin_Wrapper_GoToSleep(u8Lin_Channel);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif


/*****************************************************************************
** Service Name      : Lin_AutoSar_Wrapper_CheckWakeup
**
**
**  Description      : This function checks if the LIN channel has been waked-up.
**
**  Parameters (in)  : u8Lin_Channel : Hardware Lin channel Id.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (Std_ReturnType, LIN_CODE) Lin_AutoSar_Wrapper_CheckWakeup(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = E_FALSE;
    if ((uint8)STD_ON == g_pLin_ChannelConfigPtr[u8Lin_Channel]->u16LinChannelWakeupSupport)/* PRQA S 2844 */
    {
        u8Lin_ReturnValue = Lin_Wrapper_CheckWakeup(u8Lin_Channel);  
    }    
    
         
    return u8Lin_ReturnValue;
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"


/*****************************************************************************
** Service Name      : Lin_AutoSar_Wrapper_GoToSleepInternal
**
**
**  Description      : This function put a Lin channel in the internal sleep state.
**
**  Parameters (in)  : u8Lin_Channel : LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (Std_ReturnType, LIN_CODE) Lin_AutoSar_Wrapper_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
	return Lin_Wrapper_GoToSleepInternal(u8Lin_Channel);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*****************************************************************************
** Service Name      : Lin_AutoSar_Wrapper_WakeUp
**
**
**  Description      : This function generates a wake up pulse.
**
**  Parameters (in)  : u8Lin_Channel      : Hardware Lin channel Id.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (void, LIN_CODE) Lin_AutoSar_Wrapper_WakeUp(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    Lin_Wrapper_WakeUp(u8Lin_Channel);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"


/*****************************************************************************
** Service Name      : Lin_AutoSar_Wrapper_WakeUpInternal
**
**
**  Description      : This function shall put the LIN channel in
**                     LIN_CH_OPERATIONAL_STATE_U8 state without
**                     sending a wake up signal to the LIN bus
**
**  Parameters (in)  : u8Lin_Channel      : Hardware Lin channel Id.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC (void, LIN_CODE) Lin_AutoSar_Wrapper_WakeUpInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    Lin_Wrapper_WakeUpInternal(u8Lin_Channel);
}
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
