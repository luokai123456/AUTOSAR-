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
*   @file    LinIf.c
*   @version 3.0.0
*
*   @brief   AUTOSAR Lin 
*   @details 
*
*   @addtogroup LIN
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/*PRQA S 1756 EOF*/
/*======================================INCLUDE FILES===============================================*/

#include "Lin.h" /* PRQA S 0380 */
#include "LinIf.h"
#include "Lin_LLDriver.h"
#include "Dem.h"
#if (LIN_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif
#include "cc_printf.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LINIF_C_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LINIF_C_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LINIF_C_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LINIF_C_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LINIF_C_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LINIF_C_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LINIF_C_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LINIF_C_VENDOR_ID)
    #error " NON-MATCHED DATA : LINIF_C_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LINIF_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LINIF_C_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LINIF_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LINIF_C_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LINIF_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LINIF_C_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LINIF_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LINIF_C_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LINIF_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LINIF_C_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LINIF_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LINIF_C_SW_PATCH_VER "
#endif
/*=========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)===============================*/
#define PDU_INFO_NUM  0x4u
#define LIN_SEND_DATA_LEN  0x8u
/*======================================LOCAL MACROS================================================*/

/*======================================LOCAL CONSTANTS=============================================*/

/*======================================LOCAL VARIABLES=============================================*/

/*======================================GLOBAL CONSTANTS============================================*/

/*======================================GLOBAL VARIABLES============================================*/
extern volatile Lin_Configs g_sLin_HW_Config[LIN_HW_MAX_AVAILABLE_MODULES];
/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/

/*======================================LOCAL FUNCTIONS=============================================*/

/*======================================GLOBAL FUNCTIONS============================================*/

#if (LINIF_WAKEUP_SUPPORT == STD_ON)
 /** 
* @brief   The LIN Driver or LIN Transceiver Driver will call this function to report the wake up 
*          source after the successful wakeup detection during CheckWakeup or after power on by bus. 
* @details This is a function stub only. 
*
* @param[in]  WakeupSource - Source device which initiated the wakeup event: LIN controller
*                            or LIN transceiver.
*
* @Requirements
*/
LINIF_START_SEC_CODE
FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation(VAR(EcuM_WakeupSourceType, LINIF_VAR) WakeupSource)
{
    /* This is an empty stub function */
    (void)WakeupSource;
    LINIF_PRINTF("LinIf_WakeupConfirmation chn 0x%x\r\n", WakeupSource);
}
LINIF_STOP_SEC_CODE
 /** 
* @brief   Will be called when the EcuM has been notified about a wakeup on a specific LIN channel. 
*
* @details This is a function stub only.
*
* @param[in]  WakeupSource - Source device which initiated the wakeup event: LIN controller
*                            or LIN transceiver.
*
* @Requirements
*/
LINIF_START_SEC_CODE
FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckWakeup(VAR(EcuM_WakeupSourceType, LINIF_VAR) WakeupSource)
{
    (void)WakeupSource;
    LINIF_PRINTF("LinIf_CheckWakeup WakeupSource: %x\r\n", WakeupSource);

    return E_OK;
}
LINIF_STOP_SEC_CODE
#endif

/*****************************************************************************
** Service Name      : LinIf_HeaderIndication
**
**
**  Description      : The LIN Driver will call this function to report 
**                     a received LIN header. This function is 
**                     only applicable for LIN slave nodes 
**                     (available only if the ECU has any LIN slave channel).
**
**  Parameters (in)  : Channel : LIN channel to be addressed.
**                     PduPtr : Pointer to PDU providing the received PID and pointer to the SDU data buffer
**                        as in parameter. Upon return, the length, checksum type and frame response 
**                        type are received as out parameter. If the frame response type is 
**                        LIN_FRAMERESPONSE_TX, then the SDU data buffer contains the transmission data.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
******************************************************************************/
LINIF_START_SEC_CODE
FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication(P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr)/* PRQA S 3432 */
{
    Std_ReturnType Ret = E_NOT_OK;
    uint8 LinId = PduPtr->Pid & (uint8)0x3F;

    static uint8 linslvdataval[PDU_INFO_NUM][LIN_SEND_DATA_LEN] = {
    {0x00u, 0x50u, 0x90u, 0xD0u, 0x10u, 0xa1u, 0x42u, 0x85u}, /* classic : 0xD4 enhance : 0x3D */
    {0x14u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x12u}, /* classic : 0xDB enhance : 0x03 */
    {0x02u, 0x08u, 0x36u, 0xD0u, 0x10u, 0xa1u, 0x42u, 0x85u}, /* classic : 0x75 enhance : 0xDB */
    {0x45u, 0x39u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u} /* classic : 0x60 enhance : 0x46 */

    };

    static Lin_PduType linslvPduInfoTable[PDU_INFO_NUM]={
    {
        .Pid= 0x17u,
#ifdef LIN_TEST_MVCC
        .Cs = LIN_CLASSIC_CS,
        .Drc= LIN_FRAMERESPONSE_RX,
#else
		.Cs = LIN_CLASSIC_CS,
        .Drc= LIN_FRAMERESPONSE_TX,
#endif
        .Dl = LIN_SEND_DATA_LEN,
        .SduPtr = linslvdataval[0],
    },

    {
        .Pid= 0x18u,
#ifdef LIN_TEST_MVCC
        .Cs = LIN_CLASSIC_CS,
        .Drc= LIN_FRAMERESPONSE_TX,
#else
		.Cs = LIN_CLASSIC_CS,
        .Drc= LIN_FRAMERESPONSE_RX,
#endif
        .Dl = LIN_SEND_DATA_LEN,
        .SduPtr =  linslvdataval[1],
    },
    {
        .Pid= 0x19u,
#ifdef LIN_TEST_MVCC
        .Cs = LIN_ENHANCED_CS,
        .Drc= LIN_FRAMERESPONSE_RX,
#else
        .Cs = LIN_ENHANCED_CS,
        .Drc= LIN_FRAMERESPONSE_TX,
#endif
        .Dl = LIN_SEND_DATA_LEN,
        .SduPtr = linslvdataval[2],
    },

    {
        .Pid= 0x1Au,
#ifdef LIN_TEST_MVCC
        .Cs = LIN_ENHANCED_CS,
        .Drc= LIN_FRAMERESPONSE_TX,
#else
        .Cs = LIN_ENHANCED_CS,
        .Drc= LIN_FRAMERESPONSE_RX,
#endif
        .Dl = LIN_SEND_DATA_LEN,
        .SduPtr =  linslvdataval[3],
    },
};
    for (uint8 i = 0; i < PDU_INFO_NUM; i++)
    {
        if (LinId == linslvPduInfoTable[i].Pid)
        {
            *PduPtr = linslvPduInfoTable[i];
            Ret = E_OK;
            break;
        }
    }
    return Ret;
}
LINIF_STOP_SEC_CODE
/*****************************************************************************
** Service Name      : LinIf_RxIndication
**
**
**  Description      : The LIN Driver will call this function to report 
**                     a successfully received response and
**                     provides the reception data to the LIN Interface. 
**                     This function is only applicable for LIN slave nodes 
**                      (available only if the ECU has any LIN slave channel).
**
**  Parameters (in)  : Channel : LIN channel to be addressed.
**                     Lin_SduPtr : Pointer to pointer to a shadow buffer or memory mapped LIN Hardware receive
**                        buffer where the current SDU is stored. This pointer is only valid if the 
**                        response is received.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
LINIF_START_SEC_CODE
FUNC(void, LINIF_CODE) LinIf_RxIndication(VAR(NetworkHandleType, AUTOMATIC) Channel, P2CONST(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr)
{
    (void)Lin_SduPtr;
    VAR(uint8, AUTOMATIC) u8tempDataLength = 0U;

    LINIF_PRINTF("LinIf_RxIndication chn 0x%x\r\n", Channel);
    if (Channel < LIN_HW_MAX_AVAILABLE_MODULES)
    {
        if(g_pLin_ChannelConfigPtr[Channel] != NULL)
        {
            u8tempDataLength = (uint8)((g_sLin_HW_Config[g_pLin_ChannelConfigPtr[Channel]->u8LinHwChannel].ldp->linflexD->BIDR.B.DFL + 1U) & 0xffU);/* PRQA S 2844 *//* polyspace RTE:OBAI,NIV,NIP,IDP */
        }
        
    }
    LINIF_PRINTF("-----------Received data length: %d-----------\r\n", u8tempDataLength);
    for (uint8 j = 0; j < u8tempDataLength; j++)
    {
        LINIF_PRINTF("%02X ", Lin_SduPtr[j]);
    }

    LINIF_PRINTF("\r\n");
}
LINIF_STOP_SEC_CODE
/*****************************************************************************
** Service Name      : LinIf_TxConfirmation
**
**
**  Description      : The LIN Driver will call this function to report 
**                      a successfully transmitted response.
**                     This function is only applicable for LIN slave nodes 
**                      (available only if the ECU has any LIN slave channel).
**
**  Parameters (in)  : Channel : LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
LINIF_START_SEC_CODE
FUNC(void, LINIF_CODE) LinIf_TxConfirmation(VAR(NetworkHandleType, AUTOMATIC) Channel)
{
    (void)Channel;
	LINIF_PRINTF("\n\t txok 0x%x\n\n", Channel);
}
LINIF_STOP_SEC_CODE
/**
* @brief   The LIN Driver will call this function to report a detected error event during header
*          or response processing. This function is only applicable for LIN slave nodes (available 
*          only if the ECU has any LIN slave channel).
*
* @details This is a function stub only.
*
* @param[in]  Channel    Identification of the LIN channel.
* @param[in]  ErrorStatus Type of detected error
*
* @Requirements
*/
/*****************************************************************************
** Service Name      : LinIf_LinErrorIndication
**
**
**  Description      : The LIN Driver will call this function to report 
**                      a detected error event during header or response processing. 
**                     This function is only applicable for LIN slave nodes 
**                      (available only if the ECU has any LIN slave channel).
**
**  Parameters (in)  : Channel : LIN channel to be addressed.
**                     ErrorStatus : Type of detected error
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
LINIF_START_SEC_CODE
FUNC(void, LINIF_CODE) LinIf_LinErrorIndication(VAR(NetworkHandleType, AUTOMATIC) Channel, VAR(Lin_SlaveErrorType, AUTOMATIC) ErrorStatus)
{
    (void)Channel;
    (void)ErrorStatus;
	LINIF_PRINTF("chn 0x%x, err 0x%x\n", Channel, ErrorStatus);
}
LINIF_STOP_SEC_CODE

#ifdef __cplusplus
}
#endif

/* End of File */

/** @}*/
