/****************************************************************************
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : EMIOS
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    eMIOS_LLDriver.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eMIOS MCAL driver.
*
*   @addtogroup eMIOS
*   @{
*/
/* PRQA S 0380,3432,2985,1258,2052,3332 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "eMIOS_LLDriver.h"
#include "eMIOS_HAL_Irq.h"

#define EMIOS_LLD_C_VENDOR_ID                     176
#define EMIOS_LLD_C_AR_REL_MAJOR_VER              4
#define EMIOS_LLD_C_AR_REL_MINOR_VER              4
#define EMIOS_LLD_C_AR_REL_REV_VER                0
#define EMIOS_LLD_C_SW_MAJOR_VER                  3
#define EMIOS_LLD_C_SW_MINOR_VER                  0
#define EMIOS_LLD_C_SW_PATCH_VER                  0

#if (EMIOS_VENDOR_ID != EMIOS_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_VENDOR_ID "
#endif
#if (EMIOS_AR_REL_MAJOR_VER != EMIOS_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (EMIOS_AR_REL_MINOR_VER != EMIOS_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_AR_REL_MINOR_VER "
#endif
#if (EMIOS_AR_REL_REV_VER != EMIOS_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_AR_REL_REV_VER "
#endif
#if (EMIOS_SW_MAJOR_VER != EMIOS_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_SW_MAJOR_VER "
#endif
#if (EMIOS_SW_MINOR_VER != EMIOS_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_SW_MINOR_VER "
#endif
#if (EMIOS_SW_PATCH_VER != EMIOS_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EMIOS_LLD_C_SW_PATCH_VER "
#endif

/*******************************************************************************
 * @brief eMIOS instance base address pointer array
 *******************************************************************************/
#define EMIOS_START_SEC_CONFIG_DATA
#include "eMIOS_MemMap.h"
#if (defined (EMIOS_UnUsed_EMIOS1))
CONSTP2VAR(eMIOS_Type, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_BasePtr[EMIOS_INSTANCE_MAX] = {EMIOS0_PTR};
#else
CONSTP2VAR(eMIOS_Type, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_BasePtr[EMIOS_INSTANCE_MAX] = EMIOS_BASE_PTR_ARRAY;
#endif
#define EMIOS_STOP_SEC_CONFIG_DATA
#include "eMIOS_MemMap.h"

/*******************************************************************************
 * @brief Developer error judgment for eMIOS instance validation.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out] TRUE:   valid
 *              FALSE:  invalid
 *******************************************************************************/
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_DevError_Instance(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    return ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) ? TRUE : FALSE);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"
/*******************************************************************************
 * @brief Developer error judgment for eMIOS channel number validation.
 *
 * @param u8eMIOS_ChanNum: channel number
 *        [out] TRUE:   valid
 *              FALSE:  invalid
 *******************************************************************************/
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_DevError_ChanNum(VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(boolean, EMIOS_VAR) beMIOS_DevErrorRet = FALSE;

#if (defined(RESOURCE_SUPPORT_EMIOS0_CH0_7) || defined(RESOURCE_SUPPORT_EMIOS1_CH0_7))
    if (u8eMIOS_ChanNum <= 7U)
    {
        beMIOS_DevErrorRet = TRUE;
    }
#endif

#if (defined(RESOURCE_SUPPORT_EMIOS0_CH8_15) || defined(RESOURCE_SUPPORT_EMIOS1_CH8_15))
    if ((u8eMIOS_ChanNum >= 8U) && (u8eMIOS_ChanNum <= 15U))
    {
        beMIOS_DevErrorRet = TRUE;
    }
#endif

#if (defined(RESOURCE_SUPPORT_EMIOS0_CH16_23) || defined(RESOURCE_SUPPORT_EMIOS1_CH16_23))
    if ((u8eMIOS_ChanNum >= 16U) && (u8eMIOS_ChanNum <= 23U))
    {
        beMIOS_DevErrorRet = TRUE;
    }
#endif

#if (defined(RESOURCE_SUPPORT_EMIOS0_CH24_31) || defined(RESOURCE_SUPPORT_EMIOS1_CH24_31))
    if ((u8eMIOS_ChanNum >= 24U) && (u8eMIOS_ChanNum <= 31U))
    {
        beMIOS_DevErrorRet = TRUE;
    }
#endif
    return beMIOS_DevErrorRet;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"
/*******************************************************************************
 * @brief eMIOS global initialization.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        eMIOS_GlobalParamType: global parameter configuration pointer
 *******************************************************************************/
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_InitGlobalParam \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    P2CONST(eMIOS_GlobalParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_GlobalParam \
)
{
    VAR(eMIOS_MCR_tag, EMIOS_VAR) uneMIOS_Tag;

    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPREN = 0U;
    }

    uneMIOS_Tag.R = 0U;

    uneMIOS_Tag.B.MDIS  = ((peMIOS_GlobalParam->LowPowerModeEn == TRUE) ? 1UL : 0UL);
    uneMIOS_Tag.B.FRZ   = ((peMIOS_GlobalParam->FreezeInDebugMode == TRUE) ? 1UL : 0UL);

    EMIOS_DEV_ERR((peMIOS_GlobalParam->GlobalPreClkDiv > 0U) && (peMIOS_GlobalParam->GlobalPreClkDiv <= (EMIOS_MCR_GPRE_MAX + 1U)));

    if(peMIOS_GlobalParam->GlobalPreClkDiv == 0U)
    {
        uneMIOS_Tag.B.GPRE  = 0U;
    }
    else
    {
        uneMIOS_Tag.B.GPRE  = ((uint32)peMIOS_GlobalParam->GlobalPreClkDiv - 1U);
    }
    
    uneMIOS_Tag.B.ETB   = ((peMIOS_GlobalParam->ExternalTimeBaseSel == EMIOS_ETB_EN_COUNTER_BUSA_TO_STAC) ? 1UL : 0UL);
    uneMIOS_Tag.B.SRV   = (peMIOS_GlobalParam->ServerTimeSlotSel);

    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.R = uneMIOS_Tag.R;
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetEnDisGlobal \
(\
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_EnDisGlobal \
)
{
   EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    /* Global prescaler enabled/disabled */
    eMIOS_MCR_SetGPREN(u8eMIOS_Index, beMIOS_EnDisGlobal);
    /* Global Time Base Enable Out signal asserted/negated */
#if (EMIOS_STARTTIMER_API == STD_OFF)
    eMIOS_MCR_SetGTBE(u8eMIOS_Index, beMIOS_EnDisGlobal);
#endif
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetGLOTimebaseEnDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return eMIOS_MCR_GetGTBE(u8eMIOS_Index);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetGLOPrescalerEnDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return eMIOS_MCR_GetGPREN(u8eMIOS_Index);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetLowPowerMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_SwitchOnOff \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    eMIOS_MCR_SetMDIS(u8eMIOS_Index, beMIOS_SwitchOnOff);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetLowPowerMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return eMIOS_MCR_GetMDIS(u8eMIOS_Index);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetFreezeInDebugMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_FreezeStatus \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    eMIOS_MCR_SetFRZ(u8eMIOS_Index, beMIOS_FreezeStatus);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetFreezeInDebugMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return eMIOS_MCR_GetFRZ(u8eMIOS_Index);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetFlagSts_Ch \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return eMIOS_GFLAG_GetFLAGn(u8eMIOS_Index, u8eMIOS_ChanNum);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetChOutputUPDEnDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateEnDis \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    if(beMIOS_OutUpdateEnDis == TRUE)
    {
        /* Transfer enabled: disabled bit -> disable */
        eMIOS_OUDIS_SetChNumOutUPDDis(u8eMIOS_Index, u8eMIOS_ChanNum, FALSE);
    }
    else
    {
        /* Transfer disable: disabled bit -> enable */
        eMIOS_OUDIS_SetChNumOutUPDDis(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetChNumOutUpdateDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return eMIOS_OUDIS_GetChNumOutUPDDis(u8eMIOS_Index, u8eMIOS_ChanNum);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_SetAllChOutUPDEnDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateEnDis \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    if(beMIOS_OutUpdateEnDis == TRUE)
    {
        /* Transfer enabled: disabled bit -> disable */
        eMIOS_OUDIS_SetAllChOutUPDDis(u8eMIOS_Index, 0UL);
    }
    else
    {
        /* Transfer disable: disabled bit -> enable */
        eMIOS_OUDIS_SetAllChOutUPDDis(u8eMIOS_Index, 0xFF00FFUL);
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_GetAllChOutUpdateDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));

    return ((eMIOS_OUDIS_GetAllChOutUPDDis(u8eMIOS_Index) == 1U)?TRUE:FALSE);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_DeInitChannel \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_LLD_UC_SetChannelClkEnDis(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);

    eMIOS_UC_Cn_SetCtrlCfg(u8eMIOS_Index, u8eMIOS_ChanNum, 0UL);
    eMIOS_UC_An_SetValue(u8eMIOS_Index, u8eMIOS_ChanNum, 0UL);
    eMIOS_UC_Bn_SetValue(u8eMIOS_Index, u8eMIOS_ChanNum, 0UL);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(status_t, EMIOS_CODE) eMIOS_LLD_UC_SetDebugMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_UcFreezeStatus \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    VAR(status_t, EMIOS_VAR) eeMIOS_Ret = STATUS_ERROR;

    if (beMIOS_UcFreezeStatus == TRUE)
    {
        if (eMIOS_MCR_GetFRZ(u8eMIOS_Index) == TRUE)
        {
            eMIOS_UC_Cn_SetFREN(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);
            eeMIOS_Ret = STATUS_SUCCESS;
        }
        else
        {
            eeMIOS_Ret = STATUS_EMIOS_ENABLE_GLOBAL_FRZ;
        }
    }
    else
    {
        eMIOS_UC_Cn_SetFREN(u8eMIOS_Index, u8eMIOS_ChanNum, FALSE);
        eeMIOS_Ret = STATUS_SUCCESS;
    }

    return eeMIOS_Ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
/*******************************************************************************
 * @brief Enable/Disable Clock Prescaler.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        beMIOS_ClkEnDis: 0, 1 (Disable, Enable)
 *              FALSE: Disable
 *              TRUE: Enable
 *
 * @note  The UCPREN bit enables the prescaler counter.
 *          0: Prescaler disabled (no clock)
 *          1: Prescaler enabled
 *******************************************************************************/
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetChannelClkEnDis \
(\
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ClkEnDis \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Cn_SetUCPREN(u8eMIOS_Index, u8eMIOS_ChanNum, beMIOS_ClkEnDis);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
/*******************************************************************************
 * @brief Clock Prescaler Disable status.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        [out] TRUE: Disable
 *              FALSE: Enable
 *******************************************************************************/
FUNC(boolean, EMIOS_CODE) eMIOS_LLD_UC_GetChannelClkDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return ((eMIOS_UC_Cn_GetUCPREN(u8eMIOS_Index, u8eMIOS_ChanNum) == FALSE) ? TRUE : FALSE);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetDMARequestEn \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Cn_SetFEN(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);
    eMIOS_UC_Cn_SetDMA(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)EMIOS_C_REQ_DMA);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(eMIOS_UC_IntDmaType, EMIOS_CODE) eMIOS_LLD_UC_GetDMAModeStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return ((eMIOS_UC_Cn_GetDMA(u8eMIOS_Index, u8eMIOS_ChanNum) == 1U)? EMIOS_C_REQ_DMA : EMIOS_C_REQ_INT);/*PRQA S 4342*/
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetIntcRequestEn \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Cn_SetFEN(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);
    eMIOS_UC_Cn_SetDMA(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)EMIOS_C_REQ_INT);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_SetOutputLevel \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgeSel, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgePol \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Cn_SetEDSEL(u8eMIOS_Index, u8eMIOS_ChanNum, u8eMIOS_EdgeSel);
    eMIOS_UC_Cn_SetEDPOL(u8eMIOS_Index, u8eMIOS_ChanNum, u8eMIOS_EdgePol);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_LLD_UC_GetInputPinStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return eMIOS_UC_Sn_GetUCIN(u8eMIOS_Index, u8eMIOS_ChanNum);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_LLD_UC_GetOutputPinStatus \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    return eMIOS_UC_Sn_GetUCOUT(u8eMIOS_Index, u8eMIOS_ChanNum);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_LLD_UC_ClearFlag \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    eMIOS_UC_Sn_ClearFLAG(u8eMIOS_Index, u8eMIOS_ChanNum);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
static FUNC(boolean, EMIOS_CODE) eMIOS_DevError_McMode(VAR(uint8, AUTOMATIC) u8eMIOS_Mode)
{
    VAR(boolean, EMIOS_VAR) beMIOS_Dev_t = (boolean)((((u8eMIOS_Mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UP_MASK) ||
                    ((u8eMIOS_Mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UPDOWN_MASK) ||
                    ((u8eMIOS_Mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UP_MASK) ||
                    ((u8eMIOS_Mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UPDOWN_MASK)) ? 1 : 0);

    return beMIOS_Dev_t;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(status_t, EMIOS_CODE) eMIOS_LLD_MC_Init \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    P2CONST(eMIOS_MC_ParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_ParamPtr \
)
{
    VAR(status_t, EMIOS_VAR) eeMIOS_Ret = STATUS_SUCCESS;

    VAR(uint32, EMIOS_VAR) u32eMIOS_period = 0U;

    if ((((uint8)peMIOS_ParamPtr->mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UP_MASK) || \
       (((uint8)peMIOS_ParamPtr->mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UP_MASK))
    {
        /* MC mode: A register value will be "period" */

    	u32eMIOS_period = peMIOS_ParamPtr->period;
    }
    else if (((uint8)peMIOS_ParamPtr->mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UPDOWN_MASK)
    {
        /* MCB mode: A register value will be "period"/2 +1 */
        u32eMIOS_period =  ((peMIOS_ParamPtr->period >> 1UL) + 1UL);
    }
    else if (((uint8)peMIOS_ParamPtr->mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UPDOWN_MASK)
    {
        /* MC mode: A register value will be "period"/2 */
        u32eMIOS_period =  peMIOS_ParamPtr->period >> 1UL;
    }
    else
    {
        eeMIOS_Ret = STATUS_EMIOS_WRONG_PARAMETER;
    }

    if (eeMIOS_Ret == STATUS_SUCCESS)
    {
        /* Init mc mode */
        /* Cleared UC configure registers */
        eMIOS_LLD_UC_DeInitChannel(u8eMIOS_Index, u8eMIOS_ChanNum);    /* Disable u8eMIOS_ChanNum pre-scaler (reset default) */

        eMIOS_UC_An_SetValue(u8eMIOS_Index, u8eMIOS_ChanNum, u32eMIOS_period);

        /* Setup parammeter for external clock source */
        if (((uint8)peMIOS_ParamPtr->mode & 0x01U) == 1U)
        {
            eMIOS_UC_Cn_SetEDSEL(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)((((uint32)peMIOS_ParamPtr->trigger & 0x02U) == 0U) ? 0U : 1U));
            eMIOS_UC_Cn_SetEDPOL(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)((((uint32)peMIOS_ParamPtr->trigger & 0x01U) == 0U) ? 0U : 1U));
            eMIOS_UC_Cn_SetIF(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)peMIOS_ParamPtr->filter);
            eMIOS_UC_Cn_SetFCK(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)EMIOS_C_FCK_PRESCALED_CLK);
        }
        eMIOS_UC_Cn_SetUCPREN(u8eMIOS_Index, u8eMIOS_ChanNum, TRUE);     /* Enable pre-scaler */
        eMIOS_UC_Cn_SetMode(u8eMIOS_Index, u8eMIOS_ChanNum, (uint8)peMIOS_ParamPtr->mode);            /* Modulus Counter (Up ctr) */
        eMIOS_UC_Cn_SetUCPRE(u8eMIOS_Index, u8eMIOS_ChanNum, peMIOS_ParamPtr->divid);          /* Pre-scale u8eMIOS_ChanNum clock by divid +1 */
    }

    return eeMIOS_Ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(status_t, EMIOS_CODE) eMIOS_LLD_MC_SetPeriod \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_Period \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    VAR(status_t, EMIOS_VAR) eeMIOS_Ret = STATUS_SUCCESS;

    VAR(uint32, EMIOS_VAR) u32eMIOS_PeriodTemp;
    VAR(uint8, EMIOS_VAR) u8eMIOS_Mode = eMIOS_UC_Cn_GetMode(u8eMIOS_Index, u8eMIOS_ChanNum);

    if ((((uint8)u8eMIOS_Mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UP_MASK) || \
       (((uint8)u8eMIOS_Mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UP_MASK))
    {
        /* MC mode: A register value will be "period" */

        u32eMIOS_PeriodTemp = u32eMIOS_Period;
    }
    else if ((u8eMIOS_Mode & EMIOS_FILTER_MC_MASK) == EMIOS_MC_UPDOWN_MASK)
    {
        /* MC mode: A register value will be "period"/2 */
        u32eMIOS_PeriodTemp = (u32eMIOS_Period >> 1UL);
    }
    else if (((u8eMIOS_Mode & EMIOS_FILTER_MCB_MASK) == EMIOS_MCB_UPDOWN_MASK))
    {
        /* MCB mode: A register value will be "period"/2 + 1 */
        u32eMIOS_PeriodTemp =  ((u32eMIOS_Period >> 1UL) + 1UL);
    }
    else
    {
        eeMIOS_Ret = STATUS_EMIOS_WRONG_MODE;
    }

    if (eeMIOS_Ret == STATUS_SUCCESS)
    {
        eMIOS_UC_An_SetValue(u8eMIOS_Index, u8eMIOS_ChanNum, u32eMIOS_PeriodTemp);
    }

    return eeMIOS_Ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_LLD_MC_GetPeriod \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    VAR(uint32, EMIOS_VAR) u32eMIOS_Period = 0UL;
    VAR(uint8, EMIOS_VAR) u8eMIOS_Mode = eMIOS_UC_Cn_GetMode(u8eMIOS_Index, u8eMIOS_ChanNum);
    VAR(uint8, EMIOS_VAR) u8eMIOS_ModeSw;

    if(u8eMIOS_Mode == (uint8)EMIOS_UC_MODE_SAOC)
    {
        u8eMIOS_ModeSw = (uint8)EMIOS_UC_MODE_SAOC;
    }
    else
    {
        u8eMIOS_ModeSw = u8eMIOS_Mode & EMIOS_FILTER_MC_MASK;
    }

    switch(u8eMIOS_ModeSw)
    {
        case (uint8)EMIOS_UC_MODE_SAOC:
        case EMIOS_MC_UP_MASK:
        case EMIOS_MCB_UP_MASK:
            u32eMIOS_Period = eMIOS_UC_An_GetValue(u8eMIOS_Index, u8eMIOS_ChanNum);
            break;
        case EMIOS_MC_UPDOWN_MASK:
            u32eMIOS_Period = (eMIOS_UC_An_GetValue(u8eMIOS_Index, u8eMIOS_ChanNum) << 1UL);
            break;
        case EMIOS_MCB_UPDOWN_MASK:
            u32eMIOS_Period = ((eMIOS_UC_An_GetValue(u8eMIOS_Index, u8eMIOS_ChanNum) << 1UL) - 2UL);
            break;
        default:
            EMIOS_DEV_ERR(FALSE);
            break;
    }

    return u32eMIOS_Period;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_LLD_MC_GetInternalCounter \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(u8eMIOS_Index));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(u8eMIOS_ChanNum));

    VAR(uint8, EMIOS_VAR) u8eMIOS_Mode = eMIOS_UC_Cn_GetMode(u8eMIOS_Index, u8eMIOS_ChanNum);
    VAR(boolean, EMIOS_VAR) temp = eMIOS_DevError_McMode(u8eMIOS_Mode);
    EMIOS_DEV_ERR(temp);
    (void)temp;
    return eMIOS_UC_CNTn_GetValue(u8eMIOS_Index, u8eMIOS_ChanNum);
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#if (defined (RESOURCE_SUPPORT_SIUL2_IP))
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) GPIO_ConfigIdx(VAR(uint32, AUTOMATIC) u32eMIOS_Idx, VAR(uint32, AUTOMATIC) u32eMIOS_Mode)
{
    if(u32eMIOS_Idx < 512U)
    {
        SIUL2.MSCR_IO[u32eMIOS_Idx].R = (SIUL2.MSCR_IO[u32eMIOS_Idx].R & (~GPIO_Mode_Mask)) | ((u32eMIOS_Mode) & GPIO_Mode_Mask);/* polyspace RTE:NIV */
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"
#endif

/******eMIOS_MCR bit fields: GPRE***********************************************/

/* @brief Get Module configuration register: Global Prescaler bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]Global Prescaler bits(8 bits)
 *                  0b00000000: 1(divide)
 *                  0b00000001: 2(divide)
 *                  0b11111111: 256(divide)
 *
 * @note  The GPRE[0:7] bits select the clock divider value for the
 *          global prescaler.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8_t, EMIOS_CODE) eMIOS_MCR_GetGPRE(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(uint8_t, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPRE));/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Module configuration register: Global Prescaler bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_GlobalPreDiv: Global Prescaler bits(8 bits)
 *                  0b00000000: 1(divide)
 *                  0b00000001: 2(divide)
 *                  0b11111111: 256(divide)
 *
 * @note  The GPRE[0:7] bits select the clock divider value for the
 *          global prescaler.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetGPRE(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_GlobalPreDiv)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPRE = (uint32)u8eMIOS_GlobalPreDiv;
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_MCR bit fields: SRV************************************************/

/* @brief Get Module configuration register: Server Time Slot bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]Server Time Slot bits(4 bits)
 *
 * @note  The SRV bits select the address of a specific STAC server to which
 *          the STAC is assigned.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_MCR_GetSRV(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0U;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.SRV));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Module configuration register: Server Time Slot bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ServerTimeSlot: Server Time Slot bits(4 bits)
 *
 * @note  The SRV bits select the address of a specific STAC server to which
 *          the STAC is assigned.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetSRV(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ServerTimeSlot)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.SRV = (uint32)u8eMIOS_ServerTimeSlot;
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_MCR bit fields: GPREN**********************************************/

/* @brief Get Module configuration register: Global Prescaler Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]Global Prescaler Enable bit(1 bit)
 *          0: Prescaler disabled (no clock) and prescaler counter is cleared
 *          1: Prescaler enabled
 *
 * @note  The GPREN bit enables the prescaler counter.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetGPREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPREN) == 1U) ? TRUE : FALSE);/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Module configuration register: Global Prescaler Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_GlobalPreEnDis: Global Prescaler Enable bit(1 bit)
 *          0: Prescaler disabled (no clock) and prescaler counter is cleared
 *          1: Prescaler enabled
 *
 * @note  The GPREN bit enables the prescaler counter.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetGPREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_GlobalPreEnDis)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GPREN = ((beMIOS_GlobalPreEnDis == TRUE)?1U:0U);
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_MCR bit fields: ETB************************************************/

/* @brief Get Module configuration register: External Time Base bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]External Time Base bit(1 bit)
 *                  0: Counter bus[A] assigned to Unified Channel.
 *                  1: Counter bus[A] assigned to STAC.
 *
 * @note  The ETB bit selects the time base source that drives counter bus[A].
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetETB(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.ETB) == 1U)? TRUE : FALSE);/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Module configuration register: External Time Base bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_ExtTimeBase: External Time Base bit(1 bit)
 *                  0: Counter bus[A] assigned to Unified Channel.
 *                  1: Counter bus[A] assigned to STAC.
 *
 * @note  The ETB bit selects the time base source that drives counter bus[A].
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetETB(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_ExtTimeBase)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.ETB = ((beMIOS_ExtTimeBase == TRUE)?1U:0U);
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_MCR bit fields: GTBE***********************************************/

/* @brief Get Module configuration register: Global Time Base Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out] Global Time Base Enable bit(1 bit)
 *                  0: Global Time Base Enable Out signal negated.
 *                  1: Global Time Base Enable Out signal asserted.
 *
 * @note  The GTBE bit is used to export a Global Time Base Enable from the
 *          module and provide a method to start time bases of several blocks
 *          simultaneously.
 *        NOTE: The Global Time Base Enable input pin controls the internal
 *          counters. When asserted, Internal counters are enabled. When negated,
 *          Internal counters disabled.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetGTBE(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GTBE) == 1U) ? TRUE : FALSE);/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Module configuration register: Global Time Base Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_GlobalTimeBaseEn: Global Time Base Enable bit(1 bit)
 *                  0: Global Time Base Enable Out signal negated.
 *                  1: Global Time Base Enable Out signal asserted.
 *
 * @note  The GTBE bit is used to export a Global Time Base Enable from the
 *          module and provide a method to start time bases of several blocks
 *          simultaneously.
 *        NOTE: The Global Time Base Enable input pin controls the internal
 *          counters. When asserted, Internal counters are enabled. When negated,
 *          Internal counters disabled.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetGTBE(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_GlobalTimeBaseEn)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.GTBE = ((beMIOS_GlobalTimeBaseEn == TRUE)?1U:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_MCR bit fields: FRZ************************************************/

/* @brief Get Module configuration register: Freeze bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out] Freeze bit(1 bit)
 *          0: Exit freeze state
 *          1: Stops Unified Channels operation when in Debug mode and
 *              the FREN bit is set in the eMIOS_UC_Cn register
 *
 * @note  This bit enables the eMIOS to freeze the registers of the
 *          Unified Channels when Debug Mode is requested at MCU level.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetFRZ(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.FRZ) == 1U) ? TRUE : FALSE);/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Module configuration register: Freeze bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_FreezeEnDis: Freeze bit(1 bit)
 *          0: Exit freeze state
 *          1: Stops Unified Channels operation when in Debug mode and
 *              the FREN bit is set in the eMIOS_UC_Cn register
 *
 * @note  This bit enables the eMIOS to freeze the registers of the
 *          Unified Channels when Debug Mode is requested at MCU level.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetFRZ(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_FreezeEnDis)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.FRZ = ((beMIOS_FreezeEnDis == TRUE)?1u:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_MCR bit fields: MDIS***********************************************/

/* @brief Get Module configuration register: Module Disable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out]Module Disable bit(1 bit)
 *                  0: Clock is running
 *                  1: Enter low power mode
 *
 * @note  Puts the eMIOS into low power mode. The MDIS bit stops the clock of
 *          the block, except the access to registers EMIOSMCR and EMIOSOUDIS.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_MCR_GetMDIS(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.MDIS) == 1U) ? TRUE : FALSE);/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Module configuration register: Module Disable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        beMIOS_ModuleDis: Module Disable bit(1 bit)
 *                  0: Clock is running
 *                  1: Enter low power mode
 *
 * @note  Puts the eMIOS into low power mode. The MDIS bit stops the clock of
 *          the block, except the access to registers EMIOSMCR and EMIOSOUDIS.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_MCR_SetMDIS(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(boolean, AUTOMATIC) beMIOS_ModuleDis)
{
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->MCR.B.MDIS = ((beMIOS_ModuleDis == TRUE)?1U:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/*******************************************************************************/
/*******************eMIOS Global FLAG Register (eMIOS_GFLAG)********************/

/* @brief Get Global FLAG Register(read-only).
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        [out] Channel [n] mirrored FLAG bit(1 bit)
 *
 * @note  For Unified Channels these bits are mirrors of the FLAG bits
 *          in the eMIOS_UC_S[n] register.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_GFLAG_GetFLAGn(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    if(u8eMIOS_ChanNum < eMIOS_UC_COUNT)
    {
        if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
        {
            return (((((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->GFLAG.R)) & ((uint32_t)(1UL << u8eMIOS_ChanNum))) == 0UL) ? FALSE : TRUE);/* polyspace RTE:NIV */
        }

    }

    return (boolean)FALSE;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_GFLAG_GetAllFLAG(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(uint32_t, AUTOMATIC) beMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        beMIOS_ret = (((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->GFLAG.R)) & 0xFF00FFUL);/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/*******************************************************************************/
/**************eMIOS Output Update Disable Register (eMIOS_OUDIS)***************/

/* @brief Get Output Update Disable Register: one bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        [out] Channel [n] Output Update Disable bit (1 bit)
 *          0(FALSE): disabled bit -> disable(Transfer enabled)
 *          1(TRUE): disabled bit -> enable(Transfers disabled)
 *
 * @note  When running MC, MCB or an output mode, values are written to
 *          registers A2 and B2. OU[n] bits are used to disable transfers
 *          from registers A2 to A1 and B2 to B1. Each bit controls one channel.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_OUDIS_GetChNumOutUPDDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    if(u8eMIOS_ChanNum < eMIOS_UC_COUNT)
    {
        if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
        {
            return (((((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R)) & ((uint32_t)(1UL << u8eMIOS_ChanNum))) == 0UL) ? FALSE : TRUE);/* polyspace RTE:NIV */
        }

    }

    return (boolean)FALSE;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Get Output Update Disable Register: all bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        [out] Channel [n] Output Update Disable bit(1 bit)
 *          0(FALSE): disabled bit -> disable(Transfer enabled)
 *          1(TRUE): disabled bit -> enable(Transfers disabled)
 *
 * @note  When running MC, MCB or an output mode, values are written to
 *          registers A2 and B2. OU[n] bits are used to disable transfers
 *          from registers A2 to A1 and B2 to B1. Each bit controls one channel.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_OUDIS_GetAllChOutUPDDis(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        u32eMIOS_ret = (((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R)) & 0xFF00FFUL);/* polyspace RTE:NIV */
    }
    return u32eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Output Update Disable Register: one bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number
 *        beMIOS_OutUpdateDisable_EnDis:
 *          0(FALSE): disabled bit -> disable(Transfer enabled)
 *          1(TRUE): disabled bit -> enable(Transfers disabled)
 *
 * @note  When running MC, MCB or an output mode, values are written to
 *          registers A2 and B2. OU[n] bits are used to disable transfers
 *          from registers A2 to A1 and B2 to B1. Each bit controls one channel.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_OUDIS_SetChNumOutUPDDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutUpdateDisable_EnDis \
)
{
    if(beMIOS_OutUpdateDisable_EnDis == TRUE)
    {
        /* Output Update Disable Register bit -> enable, Transfers disabled */
        if(u8eMIOS_ChanNum < eMIOS_UC_COUNT)
        {
            if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
            {
                peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R |= (1UL << u8eMIOS_ChanNum);/* polyspace RTE:NIV */
            }

        }
    }
    else
    {
        /* Output Update Disable Register bit -> disable, Transfers enabled */
        if(u8eMIOS_ChanNum < eMIOS_UC_COUNT)
        {
            if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
            {
                peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R &= ((1UL << u8eMIOS_ChanNum) ^ 0xFFFFFFFFUL);/* polyspace RTE:NIV */
            }

        }
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Output Update Disable Register: all bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u32eMIOS_OutUpdateDisableVal:
 *      Bit 0  1  2  3  4  5  6  7  | 8    9    10   11   12   13   14   15
 *          (Reserved             )  Ch23 Ch22 Ch21 Ch20 Ch19 Ch18 Ch17 Ch16
 *      Bit 16 17 18 19 20 21 22 23 | 24   25   26   27   28   29   30   31
 *          (Reserved             )  Ch7  Ch6  Ch5  Ch4  Ch3  Ch2  Ch1  Ch0
 *          0(FALSE): disabled bit -> disable(Transfer enabled)
 *          1(TRUE): disabled bit -> enable(Transfers disabled)
 *
 * @note  When running MC, MCB or an output mode, values are written to
 *          registers A2 and B2. OU[n] bits are used to disable transfers
 *          from registers A2 to A1 and B2 to B1. Each bit controls one channel.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_OUDIS_SetAllChOutUPDDis \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint32, AUTOMATIC) u32eMIOS_OutUpdateDisableVal \
)
{
    /* Output Update Disable Register all bits -> enable, Transfers disabled */
    if (u8eMIOS_Index < EMIOS_INSTANCE_MAX)
    {
        peMIOS_BasePtr[u8eMIOS_Index]->OUDIS.R = (u32eMIOS_OutUpdateDisableVal & 0xFF00FFUL);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/*******************************************************************************/
/*******************eMIOS UC A register n (eMIOS_UC_An)*************************/

/* @brief Get A value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]A_value: internal registers A1[0:23] or A2[0:23]
 *
 * @note  Depending on the mode of operation, internal registers
 *          A1[0:23] or A2[0:23], used for matches and captures,
 *          can be assigned to address EMIOS_An.
 *        Both A1 and A2 are cleared by reset.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_An_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u32eMIOS_ret = ((uint32_t)((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].A.R) & eMIOS_A_A_MASK));/* polyspace RTE:NIV */
    }
    return u32eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_An_GetAddress(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u32eMIOS_ret = ((uint32_t)(&(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].A.R)));
    }
    return u32eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set A value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u32eMIOS_A_value: internal registers A1[0:23] or A2[0:23]
 *
 * @note  Depending on the mode of operation, internal registers
 *          A1[0:23] or A2[0:23], used for matches and captures,
 *          can be assigned to address EMIOS_An.
 *        Both A1 and A2 are cleared by reset.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_An_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_A_value \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].A.R = ((uint32_t)(u32eMIOS_A_value & eMIOS_A_A_MASK));
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/*******************************************************************************/
/*******************eMIOS UC B register n (eMIOS_UC_Bn)*************************/

/* @brief Get B value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]B_value: internal registers B1[0:23] or B2[0:23]
 *
 * @note  Depending on the mode of operation, internal registers
 *          B1[0:23] or B2[0:23] can be assigned to address EMIOS_Bn.
 *        Both B1 and B2 are cleared by reset.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_Bn_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u32eMIOS_ret = ((uint32_t)((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].B.R) & eMIOS_B_B_MASK));/* polyspace RTE:NIV */
    }
    return u32eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set B value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u32eMIOS_B_value: internal registers B1[0:23] or B2[0:23]
 *
 * @note  Depending on the mode of operation, internal registers
 *          B1[0:23] or B2[0:23] can be assigned to address EMIOS_Bn.
 *        Both B1 and B2 are cleared by reset.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Bn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_B_value \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].B.R = ((uint32_t)(u32eMIOS_B_value & eMIOS_B_B_MASK));
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/*******************************************************************************/
/*******************eMIOS UC CNT register n (eMIOS_UC_CNTn)*********************/

/* @brief Get CNT value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]C_value: The C field contains the value of the internal counter.
 *
 * @note  EMIOS_CNTn register is required for the following modes:
 *          OPWFM, OPWFMB, OPWMC, OPWMCB, PEA, PEC, WPTA, QDEC, MC, MCB.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_CNTn_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u32eMIOS_ret = ((uint32_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].CNT.R & eMIOS_CNT_C_MASK));/* polyspace RTE:NIV */

    }
    return u32eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set CNT value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u32eMIOS_C_value: The C field contains the value of the internal counter.
 *
 * @note  EMIOS_CNTn register is required for the following modes:
 *          OPWFM, OPWFMB, OPWMC, OPWMCB, PEA, PEC, WPTA, QDEC, MC, MCB.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_CNTn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_C_value \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].CNT.R = ((uint32_t)(u32eMIOS_C_value & eMIOS_CNT_C_MASK));
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/*******************************************************************************/
/*******************eMIOS UC Control register n (eMIOS_UC_Cn)*******************/
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_Cn_GetCtrlCfg(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u32eMIOS_ret = ((uint32_t)((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.R) & 0xFFFFFFFFU));/* polyspace RTE:NIV */
    }
    return u32eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetCtrlCfg \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_C_value \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.R = ((uint32_t)(u32eMIOS_C_value & 0xFFFFFFFFU));
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: MODE*********************************************/

/* @brief Get Control register: mode selection.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]ModeSel: Mode selection bits(7 bits).
 *
 * @note  The MODE bits select the mode of operation of the Unified Channel.
 *        NOTE: If a reserved value is written to the mode bit field,
 *          the results are unpredictable.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetMode(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
            u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.MODE));/* polyspace RTE:NIV */

    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: mode selection.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_ModeSel: Mode selection bits(7 bits).
 *
 * @note  The MODE bits select the mode of operation of the Unified Channel.
 *        NOTE: If a reserved value is written to the mode bit field,
 *          the results are unpredictable.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetMode \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ModeSel \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.MODE = (uint32)u8eMIOS_ModeSel;
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: EDPOL********************************************/

/* @brief Get Control register: Edge Polarity bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]u8eMIOS_EdgePolar: Edge Polarity bit(1 bit).
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetEDPOL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0U;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.EDPOL));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Edge Polarity bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_EdgePolar: Edge Polarity bit(1 bit).
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetEDPOL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgePolar \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.EDPOL = (uint32)u8eMIOS_EdgePolar;
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: EDSEL********************************************/

/* @brief Get Control register: Edge Selection bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]EdgeSel: Edge Selection bit(1 bit).
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetEDSEL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0U;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.EDSEL));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Edge Selection bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_EdgeSel: Edge Selection bit(1 bit).
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetEDSEL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_EdgeSel \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.EDSEL = (uint8)u8eMIOS_EdgeSel;
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetBSL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0U;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.BSL));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Bus Select bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_BusSel: Bus Select bits(2 bits).
 *
 * @note  The BSL[0:1] bits are used to select either one of the counter buses
 *          or the internal counter to be used by the Unified Channel.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetBSL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_BusSel \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.BSL = (uint32)u8eMIOS_BusSel;
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: FORCMB*******************************************/

/* @brief Set Control register: Force Match B bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_ForceMatchB: Force Match B bit(1 bit),
 *                     0: Has not effect,
 *                     1: Force a match at comparator B.
 *
 * @note  For output modes, the FORCMB bit is equivalent to a successful
 *          comparison on comparator B (except that the FLAG bit is not set).
 *        This bit is cleared by reset and is always read as zero.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFORCMB \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ForceMatchB \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FORCMB = ((beMIOS_ForceMatchB == TRUE)?1U:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: FORCMA*******************************************/

/* @brief Set Control register: Force Match A bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_ForceMatchA: Force Match A bit(1 bit),
 *                     0: Has not effect,
 *                     1: Force a match at comparator A.
 *
 * @note  For output modes, the FORCMA bit is equivalent to a successful
 *          comparison on comparator A (except that the FLAG bit is not set).
 *        This bit is cleared by reset and is always read as zero.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFORCMA \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ForceMatchA \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FORCMA = ((beMIOS_ForceMatchA == TRUE)?1U:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: FEN**********************************************/

/* @brief Get Control register: FLAG Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]FlagEN: FLAG Enable bit(1 bit),
 *                0: Disable(FLAG does not generate an interrupt request)
 *                1: Enable(FLAG generates an interrupt request)
 *
 * @note  The FEN bit allows the Unified Channel FLAG bit to generate an
 *          interrupt signal or a DMA request signal (the type of signal
 *          to be generated is defined by the DMA bit).
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetFEN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FEN == 1U)? TRUE:FALSE);/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: FLAG Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_FlagEN: FLAG Enable bit(1 bit),
 *                0: Disable(FLAG does not generate an interrupt request)
 *                1: Enable(FLAG generates an interrupt request)
 *
 * @note  The FEN bit allows the Unified Channel FLAG bit to generate an
 *          interrupt signal or a DMA request signal (the type of signal
 *          to be generated is defined by the DMA bit).
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFEN \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_FlagEN \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FEN = ((beMIOS_FlagEN == TRUE)?1U:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: FCK**********************************************/

/* @brief Get Control register: Filter Clock select bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]FilterClkSel: Filter Clock select bit(1 bit),
 *                0: Prescaled clock
 *                1: eMIOS module clock
 *
 * @note  The FCK bit selects the clock source for the programmable input filter.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetFCK(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0U;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FCK));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Filter Clock select bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_FilterClkSel: Filter Clock select bit(1 bit),
 *                0: Prescaled clock
 *                1: eMIOS module clock
 *
 * @note  The FCK bit selects the clock source for the programmable input filter.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFCK \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_FilterClkSel \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FCK = (uint32)u8eMIOS_FilterClkSel;
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: IF***********************************************/

/* @brief Get Control register: Input Filter bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]InputFilter: Input Filter bits(4 bits)
 *                  IF      *   Minimum input Pulse width [filter clock periods]
 *                  0b0000  *   bypassed
 *                  0b0001  *   2
 *                  0b0010  *   4
 *                  0b0100  *   8
 *                  0b1000  *   16
 *
 * @note  The IF[0:3] bits control the programmable input filter, selecting the
 *          minimum input pulse width that can pass through the filter.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetIF(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0U;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.IF));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Input Filter bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_InputFilter: Input Filter bits(4 bits)
 *                  IF      *   Minimum input Pulse width [filter clock periods]
 *                  0b0000  *   bypassed
 *                  0b0001  *   2
 *                  0b0010  *   4
 *                  0b0100  *   8
 *                  0b1000  *   16
 *
 * @note  The IF[0:3] bits control the programmable input filter, selecting the
 *          minimum input pulse width that can pass through the filter.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetIF \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_InputFilter \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.IF = (uint32)u8eMIOS_InputFilter;
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: DMA**********************************************/

/* @brief Get Control register: Direct Memory Access bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]IntDmaReqSel: Direct Memory Access bit(1 bit)
 *                      0: Flag/overrun assigned to Interrupt request.
 *                      1: Flag/overrun assigned to DMA request.
 *
 * @note  The DMA bit selects if FLAG generation will be used as
 *          an interrupt or as a DMA request.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetDMA(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.DMA));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Direct Memory Access bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_IntDmaReqSel: Direct Memory Access bit(1 bit)
 *                      0: Flag/overrun assigned to Interrupt request.
 *                      1: Flag/overrun assigned to DMA request.
 *
 * @note  The DMA bit selects if FLAG generation will be used as
 *          an interrupt or as a DMA request.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetDMA \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_IntDmaReqSel \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.DMA = ((u8eMIOS_IntDmaReqSel == TRUE)?1U:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: UCPREN*******************************************/

/* @brief Get Control register: Prescaler Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]ClkPreEnDis: Prescaler Enable bit(1 bit)
 *                      0: Prescaler disabled (no clock).
 *                      1: Prescaler enabled.
 *
 * @note  The UCPREN bit enables the prescaler counter.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetUCPREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        beMIOS_ret = ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.UCPREN == 1U) ? TRUE : FALSE);/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetUCPREN \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_ClkPreEnDis \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.UCPREN = ((beMIOS_ClkPreEnDis == TRUE)?1U:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: UCPRE********************************************/

/* @brief Get Control register: Prescaler bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]ClkPreDiv: Prescaler bits(2 bits)
 *                  0b00: 1(DIV), 0b01: 2(DIV), 0b10: 3(DIV), 0b11: 4(DIV)
 *
 * @note  The UCPRE[0:1] bits select the clock divider value for the
 *          internal prescaler of Unified Channel.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetUCPRE(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.UCPRE));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Prescaler bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_ClkPreDiv: Prescaler bits(2 bits)
 *                  0b00: 1(DIV), 0b01: 2(DIV), 0b10: 3(DIV), 0b11: 4(DIV)
 *
 * @note  The UCPRE[0:1] bits select the clock divider value for the
 *          internal prescaler of Unified Channel.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetUCPRE \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ClkPreDiv \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.UCPRE = (uint32)u8eMIOS_ClkPreDiv;
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: ODISSL*******************************************/

/* @brief Get Control register: Output Disable select bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]OutDisSel: Output Disable select bits(2 bits)
 *                  0b00: Output Disable Input 0,
 *                  0b01: Output Disable Input 1,
 *                  0b10: Output Disable Input 2,
 *                  0b11: Output Disable Input 3
 *
 * @note  The ODISSL[0:1] bits select one of the four output disable input signals.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Cn_GetODISSL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.ODISSL));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Output Disable select bits.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u8eMIOS_OutDisSel: Output Disable select bits(2 bits)
 *                  0b00: Output Disable Input 0,
 *                  0b01: Output Disable Input 1,
 *                  0b10: Output Disable Input 2,
 *                  0b11: Output Disable Input 3
 *
 * @note  The ODISSL[0:1] bits select one of the four output disable input signals.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetODISSL \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint8, AUTOMATIC) u8eMIOS_OutDisSel \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.ODISSL = ((u8eMIOS_OutDisSel == TRUE)?1U:0U);
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: ODIS*********************************************/

/* @brief Get Control register: Output Disable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]OutDis: Output Disable bit(1 bit)
 *
 * @note  The ODIS bit allows disabling the output pin when running any of
 *          the output modes with the exception of GPIO mode.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetODIS(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.ODIS == 1U)? TRUE:FALSE);/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Output Disable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_OutDis: Output Disable bit(1 bit)
 *
 * @note  The ODIS bit allows disabling the output pin when running any of
 *          the output modes with the exception of GPIO mode.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetODIS \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_OutDis \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.ODIS = ((beMIOS_OutDis == TRUE)?1U:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Cn bit fields: FREN*********************************************/

/* @brief Get Control register: Freeze Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]FreezeEn: Freeze Enable bit(1 bit)
 *                  0: Normal operation,
 *                  1: Freeze UC registers values
 *
 * @note  The FREN bit, if set and validated by FRZ bit in EMIOS_MCR register
 *          allows the channel to enter freeze state, freezing all registers values
 *          when in debug mode and allowing the MCU to perform debug functions.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Cn_GetFREN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FREN == 1U)? TRUE:FALSE);/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Control register: Freeze Enable bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        beMIOS_FreezeEn: Freeze Enable bit(1 bit)
 *                  0: Normal operation,
 *                  1: Freeze UC registers values
 *
 * @note  The FREN bit, if set and validated by FRZ bit in EMIOS_MCR register
 *          allows the channel to enter freeze state, freezing all registers values
 *          when in debug mode and allowing the MCU to perform debug functions.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Cn_SetFREN \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(boolean, AUTOMATIC) beMIOS_FreezeEn \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].C.B.FREN = ((beMIOS_FreezeEn == TRUE)?1U:0U);
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/*******************************************************************************/
/*******************eMIOS UC Status register n (eMIOS_UC_Sn)********************/

/******eMIOS_UC_Sn bit fields: FLAG*********************************************/

/* @brief Get Status register: FLAG bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]FLAG(1 bit)
 *              0: FLAG cleared,
 *              1: FLAG set event has occurred
 *
 * @note  The FLAG bit is set when an input capture or a match event
 *          in the comparators occurred.
 *        The FLAG bit must be cleared by writing a 1 to it.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Sn_GetFLAG(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(boolean, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        return ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.FLAG == 1U)? TRUE:FALSE);/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Clear Status register: FLAG bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *
 * @note  The FLAG bit is set when an input capture or a match event
 *          in the comparators occurred.
 *        The FLAG bit must be cleared by writing a 1 to it.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Sn_ClearFLAG(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.FLAG = (uint32)1UL;
    }

}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Sn bit fields: UCOUT********************************************/

/* @brief Get Status register: Unified Channel Output pin bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]UCOUT(1 bit)
 *
 * @note  The UCOUT bit reflects the output pin state.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Sn_GetUCOUT(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.UCOUT));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Sn bit fields: UCIN*********************************************/

/* @brief Get Status register: Unified Channel Input pin bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]UCIN(1 bit)
 *
 * @note  The UCIN bit reflects the input pin state after being filtered
 *          and synchronized.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint8, EMIOS_CODE) eMIOS_UC_Sn_GetUCIN(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint8, AUTOMATIC) u8eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u8eMIOS_ret = ((uint8_t)(peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.UCIN));/* polyspace RTE:NIV */
    }
    return u8eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Sn bit fields: OVFL*********************************************/

/* @brief Get Status register: Overflow bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]Overflow bit(1 bit)
 *              0: No overflow,
 *              1: An overflow had occurred
 *
 * @note  The OVFL bit indicates that an overflow has occurred in the
 *          internal counter.
 *        The OVFL bit must be cleared by software writing a 1 to it.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Sn_GetOVFL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        beMIOS_ret = ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.OVFL == 1U) ? TRUE : FALSE);/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Clear Status register: Overflow bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *
 * @note  The OVFL bit indicates that an overflow has occurred in the
 *          internal counter.
 *        The OVFL bit must be cleared by software writing a 1 to it.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Sn_ClearOVFL(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    /* OVR bit, OVFL bit & FLAG bit can be cleared when write 1 to them */
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.OVFL = (uint32)1UL;
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/******eMIOS_UC_Sn bit fields: OVR**********************************************/

/* @brief Get Status register: Overrun bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]Overrun(1 bit)
 *              0: Overrun has not occurred,
 *              1: Overrun has occurred
 *
 * @note  The OVR bit indicates that FLAG generation occurred when the FLAG bit
 *          was already set.
 *        The OVR bit can be cleared either by clearing the FLAG bit or by
 *          writing a 1 to the OVR bit.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(boolean, EMIOS_CODE) eMIOS_UC_Sn_GetOVR(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(boolean, AUTOMATIC) beMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        beMIOS_ret =  ((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.OVR == 1U)?TRUE:FALSE);/* polyspace RTE:NIV */
    }
    return beMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Clear Status register: Overrun bit.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *
 * @note  The OVR bit indicates that FLAG generation occurred when the FLAG bit
 *          was already set.
 *        The OVR bit can be cleared either by clearing the FLAG bit or by
 *          writing a 1 to the OVR bit.
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_Sn_ClearOVR(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].S.B.OVR = (uint32)1UL;
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/*******************************************************************************/
/**************eMIOS UC Alternate Address register n (eMIOS_UC_ALTAn)***********/

/* @brief Get Alternate Address register: ALTA value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        [out]ALTA_Value(24 bits)
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(uint32, EMIOS_CODE) eMIOS_UC_ALTAn_GetValue(VAR(uint8, AUTOMATIC) u8eMIOS_Index, VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum)
{
    VAR(uint32, AUTOMATIC) u32eMIOS_ret = 0;
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        u32eMIOS_ret = ((uint32_t)((peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].ALTA.R) & eMIOS_ALTA_ALTA_MASK));/* polyspace RTE:NIV */
    }
    return u32eMIOS_ret;
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"

/* @brief Set Alternate Address register: ALTA value.
 *
 * @param u8eMIOS_Index: eMIOS index
 *        u8eMIOS_ChanNum: eMIOS channel number(register n)
 *        u32eMIOS_ALTA_Value(24 bits)
 * */
#define EMIOS_START_SEC_CODE
#include "eMIOS_MemMap.h"
FUNC(void, EMIOS_CODE) eMIOS_UC_ALTAn_SetValue \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    VAR(uint32, AUTOMATIC) u32eMIOS_ALTA_Value \
)
{
    if ((u8eMIOS_Index < EMIOS_INSTANCE_MAX) && (u8eMIOS_ChanNum < eMIOS_UC_COUNT))
    {
        peMIOS_BasePtr[u8eMIOS_Index]->UC[u8eMIOS_ChanNum].ALTA.R = ((uint32_t)(u32eMIOS_ALTA_Value & eMIOS_ALTA_ALTA_MASK));
    }
}
#define EMIOS_STOP_SEC_CODE
#include "eMIOS_MemMap.h"
#ifdef __cplusplus
}
#endif
