/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     Wdg_LLDriver.c
* @author   C*Core
* @version  3.0.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 3432,2844,2983,1006,3006 EOF*/

#include "Wdg_LLDriver.h"/*PRQA S 0380*/
#include "Wdg_irq.h"



#define WDG_LLD_C_VENDOR_ID                      176
#define WDG_LLD_C_VERSION_MAJOR                  4
#define WDG_LLD_C_VERSION_MINOR                  4
#define WDG_LLD_C_VERSION_REVISION               0
#define WDG_LLD_C_SW_VERSION_MAJOR               3
#define WDG_LLD_C_SW_VERSION_MINOR               0
#define WDG_LLD_C_SW_VERSION_PATCH               0

#if (WDG_LLD_C_VENDOR_ID != WDG_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_LLD_C_VENDOR_ID "
#endif
#if (WDG_LLD_C_VERSION_MAJOR != WDG_LLD_H_VERSION_MAJOR)
    #error " NON-MATCHED DATA : WDG_LLD_C_VERSION_MAJOR "
#endif
#if (WDG_LLD_C_VERSION_MINOR != WDG_LLD_H_VERSION_MINOR)
    #error " NON-MATCHED DATA : WDG_LLD_C_VERSION_MINOR "
#endif
#if (WDG_LLD_C_VERSION_REVISION != WDG_LLD_H_VERSION_REVISION)
    #error " NON-MATCHED DATA : WDG_LLD_C_VERSION_REVISION "
#endif
#if (WDG_LLD_C_SW_VERSION_MAJOR != WDG_LLD_H_SW_VERSION_MAJOR)
    #error " NON-MATCHED DATA : WDG_LLD_C_SW_VERSION_MAJOR "
#endif
#if (WDG_LLD_C_SW_VERSION_MINOR != WDG_LLD_H_SW_VERSION_MINOR)
    #error " NON-MATCHED DATA : WDG_LLD_C_SW_VERSION_MINOR "
#endif
#if (WDG_LLD_C_SW_VERSION_PATCH != WDG_LLD_H_SW_VERSION_PATCH)
    #error " NON-MATCHED DATA : WDG_LLD_C_SW_VERSION_PATCH "
#endif



#define WDG_START_SEC_VAR_INIT
#include "Wdg_MemMap.h"
static P2VAR(SWT_tag_Type, WDG_VAR, WDG_APPL_CONST) g_SWTBase[SWT_INSTANCE_NUM] = SWT_BASE_ARRAY;/*PRQA S 1258*/
#define WDG_STOP_SEC_VAR_INIT
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_NO_INIT
#include "Wdg_MemMap.h"
static P2CONST(SWT_Module_Config_Type,AUTOMATIC, WDG_APPL_CONST) s_SWT_Global_Config[SWT_INSTANCE_NUM];
#define WDG_STOP_SEC_VAR_NO_INIT
#include "Wdg_MemMap.h"

#if (defined(RESOURCE_SUPPORT_WDG_ADDRMODE))
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE void SWT_LLD_SetTriggerAddress(uint32_t triggerAddr);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif /* RESOURCE_SUPPORT_WDG_ADDRMODE */

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE VAR(status_t, WDG_VAR) SWT_LLD_UnLock(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetTimeoutValue \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(uint32, WDG_VAR) u32Wdg_Value \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetWindowMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_Status_Type, WDG_VAR) eWdg_Windowmode, \
    VAR(uint32, WDG_VAR) u32Wdg_Value \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetInitialServiceKey \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(uint16, WDG_VAR) u16Wdg_Intitialvalue \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetServiceMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_ServiceMode_Type, WDG_VAR) eWdg_Mode \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetInterruptState \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_InterMode, WDG_VAR) eWdg_InterruptState \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_ClearInterruptFlag \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetDebugFreeze \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_DebugMode_Type, WDG_VAR) eWdg_SWT_DebugMod \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_ModuleEnable \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_ModuleDisable \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_Lock \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_Lock_Type, WDG_VAR) eWdg_Locktype \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(void, WDG_CODE) SWT_LLD_DeInit \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetResetOnInvalidAccess \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_RIA_Type, WDG_VAR) eWdg_Mode \
);
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#if defined (CUSTOM_DEVASSERT) || defined (DEV_ERROR_DETECT)
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
static boolean SWT_LLD_ParaVerify(SWT_ModuleID_Type SWT_ModuleID);

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
static boolean SWT_LLD_ParaVerify(SWT_ModuleID_Type SWT_ModuleID)
{
    boolean swtParaStatus = FALSE;

#if ( WDGINSTANCE0 ==STD_ON)
    if(SWT_ModuleID == SWT0)
    {
        swtParaStatus = TRUE;
    }
#endif

#if ( WDGINSTANCE1 ==STD_ON)
    if(SWT_ModuleID == SWT1)
    {
        swtParaStatus = TRUE;
    }
#endif

#if ( WDGINSTANCE2 ==STD_ON)
    if(SWT_ModuleID == SWT2)
    {
        swtParaStatus = TRUE;
    }
#endif

#if ( WDGINSTANCE3 ==STD_ON)
    if(SWT_ModuleID == SWT3)
    {
        swtParaStatus = TRUE;
    }
#endif

#if ( WDGINSTANCE4 ==STD_ON)
    if(SWT_ModuleID == SWT4)
    {
        swtParaStatus = TRUE;
    }
#endif

#if ( WDGINSTANCE5 ==STD_ON)
    if(SWT_ModuleID == SWT5)
    {
        swtParaStatus = TRUE;
    }
#endif

#if ( WDGINSTANCE6 ==STD_ON)
    if(SWT_ModuleID == SWT6)
    {
        swtParaStatus = TRUE;
    }
#endif

#if ( WDGINSTANCE7_AO ==STD_ON)
    if(SWT_ModuleID == SWT7_AO)
    {
        swtParaStatus = TRUE;
    }
#endif

    return swtParaStatus;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_UnLock(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Write unlock sequence*/
    pWdg_Base->SR.R = SWT_UNLOCK_KEY_1;
    pWdg_Base->SR.R = SWT_UNLOCK_KEY_2;

#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->CR.B.SLK != 0U)
    {
        return STATUS_ERROR;
    }
#endif

    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Enable SWT module clock
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_ModuleEnable(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Unlock SWT register*/
    /*Enable SWT module clock*/
    pWdg_Base->CR.B.WEN = 1u;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->CR.B.WEN != 1u)
    {
        return STATUS_ERROR;
    }
#endif


    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Disable SWT module clock
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_ModuleDisable(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);
    if(SWT_ModuleID <= SWT7_AO)
    {
        P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[SWT_ModuleID];
        /*Unlock SWT register*/
        (void)SWT_LLD_UnLock(SWT_ModuleID);
        /*Disable SWT module clock*/

        pWdg_Base->CR.B.WEN = 0u;
#if SWT_REG_READBACK
        /*Check whether the operation is successful*/
        if (pWdg_Base->CR.B.WEN != 0u)
        {
            return STATUS_ERROR;
        }
#endif
    }
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Lock SWT register
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :locktype software lock or hardware lock
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_Lock \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_Lock_Type, WDG_VAR) eWdg_Locktype \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);
    VAR(status_t,WDG_VAR) result = STATUS_SUCCESS;
    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);

    if (eWdg_Locktype == SWT_Softlock)
    {
        /*Software lock*/

        pWdg_Base->CR.B.SLK = 1;
#if SWT_REG_READBACK
        /*Check whether the operation is successful*/
        if (pWdg_Base->CR.B.SLK != 1u)
        {
            return STATUS_ERROR;
        }
#endif

        result= STATUS_SUCCESS;
    }
    else
    {

        /*Hardware lock*/
        pWdg_Base->CR.B.HLK = 1;
#if SWT_REG_READBACK
        /*Check whether the operation is successful*/
        if (pWdg_Base->CR.B.HLK != 1u)
        {
            return STATUS_ERROR;
        }
#endif

        result= STATUS_SUCCESS;
    }
    return result;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Feed dog
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :servicemode feed dog mode
 * @param[out] :None
 * @retval     :None
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) SWT_Trigger \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_ServiceMode_Type, WDG_VAR) eWdg_Servicemode \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    VAR(uint32, WDG_VAR) u32Wdg_Servekey = 0U;
    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[SWT_ModuleID];
    /*Fixed sequence feed dog*/

    if (eWdg_Servicemode == Fixed_Serv_Seq)
    {
        pWdg_Base->SR.R = SWT_SERVICE_KEY_1;
        pWdg_Base->SR.R = SWT_SERVICE_KEY_2;

    }
    /*Random sequence feed dog*/
    else
    {

        u32Wdg_Servekey = pWdg_Base->SK.R; /* polyspace RTE:NIV */
        u32Wdg_Servekey = (uint32_t)NEW_SERVICE_KEY(u32Wdg_Servekey);
        pWdg_Base->SR.R = u32Wdg_Servekey;
        u32Wdg_Servekey = (uint32_t)NEW_SERVICE_KEY(u32Wdg_Servekey);
        pWdg_Base->SR.R = u32Wdg_Servekey;

    }
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Set module freeze mode
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :SWT_DebugMod freeze mode
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetDebugFreeze \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_DebugMode_Type, WDG_VAR) eWdg_SWT_DebugMod \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);
    /*Set freeze mode*/
    pWdg_Base->CR.B.FRZ = (uint8_t)eWdg_SWT_DebugMod;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->CR.B.FRZ != eWdg_SWT_DebugMod)
    {
        return STATUS_ERROR;
    }
#endif

    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Get module freeze mode
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[out] :None
 * @retval     :Module freeze mode
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint8, WDG_CODE) SWT_LLD_GetDebugFreeze(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2CONST(SWT_tag_Type, WDG_VAR, WDG_APPL_CONST) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Return module freeze mode*/
    return (uint8_t)pWdg_Base->CR.B.FRZ; /* polyspace RTE:NIV */
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Clear SWT interrupt flag
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_ClearInterruptFlag(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);
    /*Clear SWT interrupt flag*/
    pWdg_Base->IR.R = 0x1u;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->IR.R != 0U)
    {
        return STATUS_ERROR;
    }
#endif
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Get SWT interrupt flag status
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[out] :None
 * @retval     :SWT interrupt flag status
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE) SWT_LLD_GetInterruptFlag(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2CONST(SWT_tag_Type, WDG_VAR, WDG_APPL_CONST) pWdg_Base = g_SWTBase[SWT_ModuleID];
    /*Return SWT interrupt flag status*/
    return pWdg_Base->IR.R; /* polyspace RTE:NIV */
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Set SWT interrupt then reset or reset immediately when timeout
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :InterruptState interrupt state
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetInterruptState \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_InterMode, WDG_VAR) eWdg_InterruptState \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);
    /*Set SWT interrupt state*/
    pWdg_Base->CR.B.ITR = (uint8_t)eWdg_InterruptState;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->CR.B.ITR != eWdg_InterruptState)
    {
        return STATUS_ERROR;
    }
#endif
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Set whether SWT module can run in stop mode
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :stopmode whether SWT module can run in stop mode
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(status_t, WDG_CODE) SWT_LLD_SetStopMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_StopMode_Type, WDG_VAR) eWdg_Stopmode \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);
    /*Set whether SWT module can run in stop mode*/
    pWdg_Base->CR.B.STP = (uint8_t)eWdg_Stopmode;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->CR.B.STP != eWdg_Stopmode)
    {
        return STATUS_ERROR;
    }
#endif
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Get whether SWT module can run in stop mode
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[out] :None
 * @retval     :whether SWT module can run in stop mode
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE) SWT_LLD_GetStopMode(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2CONST(SWT_tag_Type, WDG_VAR, WDG_APPL_CONST) pWdg_Base = g_SWTBase[SWT_ModuleID];
    /*Get whether SWT module can run in stop mode*/
    return pWdg_Base->CR.B.STP; /* polyspace RTE:NIV */
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Get the value of the internal down counter when the SWT is disabled
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[out] :None
 * @retval     :whether SWT module can run in stop mode
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE) SWT_LLD_GetCounterOutValue(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2CONST(SWT_tag_Type, WDG_VAR, WDG_APPL_CONST) pWdg_Base = g_SWTBase[SWT_ModuleID];
    /*Get the value of the internal down counter when the SWT is disabled*/
    return pWdg_Base->CO.R; /* polyspace RTE:NIV */
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Set module timeout value
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :value timeout value
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetTimeoutValue \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(uint32, WDG_VAR) u32Wdg_Value \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);
    /*Set module timeout value*/
    pWdg_Base->TO.R = u32Wdg_Value;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->TO.R != u32Wdg_Value)
    {
        return STATUS_ERROR;
    }
#endif
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Set module window mode and window value
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :windowmode SWT window mode
 * @param[in]  :value window value
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetWindowMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_Status_Type, WDG_VAR) eWdg_Windowmode, \
    VAR(uint32, WDG_VAR) u32Wdg_Value \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);
    /*Set window mode*/
    pWdg_Base->CR.B.WND = (uint8_t)eWdg_Windowmode;
    /*Set window value*/
    pWdg_Base->WN.R = u32Wdg_Value;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->WN.R != u32Wdg_Value)
    {
        return STATUS_ERROR;
    }
#endif
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Set initial key when random sequence feed dog
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :intitialvalue intitial key
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetInitialServiceKey \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(uint16, WDG_VAR) u16Wdg_Intitialvalue \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);
    /*Set initial key*/
    pWdg_Base->SK.R = u16Wdg_Intitialvalue;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->SK.R != u16Wdg_Intitialvalue)
    {
        return STATUS_ERROR;
    }
#endif
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Set module service mode
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :mode service mode
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetServiceMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_ServiceMode_Type, WDG_VAR) eWdg_Mode \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);
    /*Set service key*/
    pWdg_Base->CR.B.SMD = (uint8_t)eWdg_Mode;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->CR.B.SMD != eWdg_Mode)
    {
        return STATUS_ERROR;
    }
#endif
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Set module reset or bus error on invalid access
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :mode reset or bus error
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(status_t, WDG_CODE) SWT_LLD_SetResetOnInvalidAccess \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(SWT_RIA_Type, WDG_VAR) eWdg_Mode \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2VAR(SWT_tag_Type, WDG_VAR , WDG_APPL_DATA) pWdg_Base = g_SWTBase[(uint8_t)SWT_ModuleID];
    /*Unlock SWT register*/
    (void)SWT_LLD_UnLock(SWT_ModuleID);
    /*Set module reset or bus error on invalid access*/
    pWdg_Base->CR.B.RIA = (uint8_t)eWdg_Mode;
#if SWT_REG_READBACK
    /*Check whether the operation is successful*/
    if (pWdg_Base->CR.B.RIA != eWdg_Mode)
    {
        return STATUS_ERROR;
    }
#endif
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#if (defined(RESOURCE_SUPPORT_WDG_ADDRMODE))
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE void SWT_LLD_SetTriggerAddress(uint32_t triggerAddr)/*PRQA S 3206*/
{
    MTSPR(SPR_IAC8, triggerAddr); /* assembly language */
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif /* RESOURCE_SUPPORT_WDG_ADDRMODE */
/*******************************************************************************
 * @brief      :Global irq handler for SWT
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[out] :None
 * @retval     :None
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) SWT_LLD_IRQHandler(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    (void)SWT_LLD_ClearInterruptFlag(SWT_ModuleID);


    if (s_SWT_Global_Config[SWT_ModuleID]->SWT_Callback != NULL_PTR) /* polyspace RTE:IDP*/
    {
        s_SWT_Global_Config[SWT_ModuleID]->SWT_Callback();
    }
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Deinitialize SWT module
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(void, WDG_CODE) SWT_LLD_DeInit (VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);
    /*Disable module clock*/
    (void)SWT_LLD_ModuleDisable(SWT_ModuleID);
    /*Clear interrupt flag*/
    (void)SWT_LLD_ClearInterruptFlag(SWT_ModuleID);
    /*Disable freeze mode*/
    (void)SWT_LLD_SetDebugFreeze(SWT_ModuleID, SWT_FreezeOFF);
    /*Set reset immediately when timeout*/
    (void)SWT_LLD_SetInterruptState(SWT_ModuleID, SWT_RESET_FIRST);
    /*Set service mode*/
    (void)SWT_LLD_SetServiceMode(SWT_ModuleID, Fixed_Serv_Seq);
    /*Set bus error on invalid access*/
    (void)SWT_LLD_SetResetOnInvalidAccess(SWT_ModuleID, SWT_BusError);
    /*Disable window mode and clear window value*/
    (void)SWT_LLD_SetWindowMode(SWT_ModuleID, SWT_Disable, 0u);
    /*Clear timeout value*/
    (void)SWT_LLD_SetTimeoutValue(SWT_ModuleID, 0u);
    /*Clear initial key value*/
    (void)SWT_LLD_SetInitialServiceKey(SWT_ModuleID, 0u);
    /*Clear globle variable*/
    s_SWT_Global_Config[SWT_ModuleID] = NULL_PTR;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Set SWT module mode
 * @param[in]  :SWT_ModuleID SWT peripheral instance number
 * @param[in]  :eWdg_SWT_RunMode SWT mode
 * @param[out] :None
 * @retval     :None
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(status_t, WDG_CODE) SWT_LLD_SetMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
    VAR(WdgIf_ModeType, WDG_VAR) eWdg_SWT_RunMode \
)
{
    /*Check Module ID*/
    DEV_ASSERT(SWT_LLD_ParaVerify(SWT_ModuleID) == TRUE);

    P2CONST(SWT_Module_Config_Type, WDG_VAR, WDG_APPL_CONST) pWdg_Cfgptr;

#ifdef RESOURCE_SUPPORT_SWT7_AO
#if (RESOURCE_SUPPORT_SWT_AO_CTRL == RESOURCE_SUPPORT_SWT_AO_CTRL_1)
    uint32 tmp;
#endif
	if(SWT_ModuleID == SWT7_AO)
    {
#if (RESOURCE_SUPPORT_SWT_AO_CTRL == RESOURCE_SUPPORT_SWT_AO_CTRL_1)
	    if(eWdg_SWT_RunMode != WDGIF_OFF_MODE)
        {
            tmp =*(uint32_t*)0xFFFA05D8u;
            tmp |= (1UL << 10u);
            *(uint32_t*)0xFFFA05D8u = tmp;
        }
#else
        if(eWdg_SWT_RunMode != WDGIF_OFF_MODE)
        {
            *(uint32_t*)0xFFFA05B0u |= (1UL<<12);
        }
        else
        {
            *(uint32_t*)0xFFFA05B0u &= ~(1UL<<12);
        }
#endif /* RESOURCE_SUPPORT_SWT_AO_CTRL */
    }
#endif

    /*Get glable config*/
    pWdg_Cfgptr = s_SWT_Global_Config[(uint8_t)SWT_ModuleID];
#if (defined(RESOURCE_SUPPORT_WDG_ADDRMODE))
	VAR(uint32, WDG_VAR) DBCR0_Val = 0U;
#endif
    if (eWdg_SWT_RunMode == WDGIF_OFF_MODE)
    {
        /*Disable module clock*/
        (void)SWT_LLD_ModuleDisable(SWT_ModuleID);
        /*Clear interrupt flag*/
        (void)SWT_LLD_ClearInterruptFlag(SWT_ModuleID);
        /*Disable freeze mode*/
        (void)SWT_LLD_SetDebugFreeze(SWT_ModuleID, SWT_FreezeOFF);
        /*Set reset immediately when timeout*/
        (void)SWT_LLD_SetInterruptState(SWT_ModuleID, SWT_RESET_FIRST);
        (void)SWT_LLD_Lock(SWT_ModuleID, SWT_Softlock);
        /*Set service mode*/
        (void)SWT_LLD_SetServiceMode(SWT_ModuleID, Fixed_Serv_Seq);
        /*Set bus error on invalid access*/
        (void)SWT_LLD_SetResetOnInvalidAccess(SWT_ModuleID, SWT_BusError);
        /*Disable window mode and clear window value*/
        (void)SWT_LLD_SetWindowMode(SWT_ModuleID, SWT_Enable, 0u);
        /*Clear timeout value*/
        (void)SWT_LLD_SetTimeoutValue(SWT_ModuleID, 0u);
        /*Clear initial key value*/
        (void)SWT_LLD_SetInitialServiceKey(SWT_ModuleID, 0u);
    }
    else
    {
	     /*Disable module clock*/
        (void)SWT_LLD_ModuleDisable(SWT_ModuleID);
        /*Clear interrupt flag*/
        (void)SWT_LLD_ClearInterruptFlag(SWT_ModuleID);
        /*Set freeze mode*/
        (void)SWT_LLD_SetDebugFreeze(SWT_ModuleID, 
            pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_DebugMode); /* polyspace RTE:IDP*/
       
        /*Set module interrupt state*/
        (void)SWT_LLD_SetInterruptState(SWT_ModuleID, \
            pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_InterruptMode);
        (void)SWT_LLD_Lock(SWT_ModuleID, \
        		pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_Lock_Mode);
        /*Set module service mode*/
        (void)SWT_LLD_SetServiceMode(SWT_ModuleID, \
            pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_ServiceMode);

#if (defined(RESOURCE_SUPPORT_WDG_ADDRMODE))
		if((pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_ServiceMode == Fixed_Addr_Exe)|| \
				(pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_ServiceMode == Incremental_Addr_Exe))
        {
            SWT_LLD_SetTriggerAddress(pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->Wdg_TriggerAddr);
            DBCR0_Val = MFSPR(SPR_DBCR0);/* assembly language */
            MTSPR(SPR_DBCR0, DBCR0_Val | (0x1U << 27U) | (0x1U << 11U) | (0x1U << 30U));/* assembly language */
        }
#endif

        /*Set module reset or bus error on invalid access*/
        (void)SWT_LLD_SetResetOnInvalidAccess(SWT_ModuleID, \
            pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_ResetonInvalidAccess);
        /*Set window mode and window value*/
        (void)SWT_LLD_SetWindowMode(SWT_ModuleID, \
            pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_WindowMode, \
            pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_WindowValue);
        /*Set timeout value*/
        (void)SWT_LLD_SetTimeoutValue(SWT_ModuleID, \
            pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_Timeout);
        /*Set initial key*/
        (void)SWT_LLD_SetInitialServiceKey(SWT_ModuleID, \
            pWdg_Cfgptr->SWT_Config[eWdg_SWT_RunMode]->SWT_InitialSK);
        /*Enable module clock*/
        (void)SWT_LLD_ModuleEnable(SWT_ModuleID);
    }
    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
 * @brief      :Initialize SWT module
 * @param[in]  :pWdg_Cfgptr SWT module config
 * @param[out] :None
 * @retval     :Error or success status returned by API
 *******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(status_t, WDG_CODE) SWT_LLD_Init \
( \
    P2CONST(SWT_Module_Config_Type, WDG_VAR, WDG_APPL_CONST) pWdg_Cfgptr \
)
{
    /*Check Module ID*/
    SWT_DET_ERR(pWdg_Cfgptr != NULL_PTR);
    /*Unlock*/
    (void)SWT_LLD_UnLock(pWdg_Cfgptr->SWT_ModuleID);
    /*Reset module*/
    SWT_LLD_DeInit(pWdg_Cfgptr->SWT_ModuleID);
    /*Set globle config*/
    s_SWT_Global_Config[pWdg_Cfgptr->SWT_ModuleID] = pWdg_Cfgptr;
    /*Set mode */
    (void)SWT_LLD_SetMode(pWdg_Cfgptr->SWT_ModuleID, pWdg_Cfgptr->SWT_DefaultRunMode);

    return STATUS_SUCCESS;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

