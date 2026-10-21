/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc_LLDriver.c
* @version  3.0.0
* @date     2023 - 09 - 01
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 0380,2985,3432,4397,2991,2995,2844,3604,4342,1880,2052,1258,4344,1852,4434,2024,1257,4404,0686,3218,4521,4391,4399 EOF*/
/* PRQA S 4461 EOF*/
#ifdef __cplusplus
extern "C"{
#endif


#include "SDAdc.h"
#include "SDAdc_LLDriver.h"		/* PRQA S 0380,4095*/
#ifdef RESOURCE_SUPPORT_SDADC_IP
#include "eDma.h"
#include "SchM_SDAdc.h"
#include "common.h"

#define SDADC_LLD_C_VENDOR_ID                     176
#define SDADC_LLD_C_AR_REL_MAJOR_VER              4
#define SDADC_LLD_C_AR_REL_MINOR_VER              4
#define SDADC_LLD_C_AR_REL_REV_VER                0
#define SDADC_LLD_C_SW_MAJOR_VER                  3
#define SDADC_LLD_C_SW_MINOR_VER                  0
#define SDADC_LLD_C_SW_PATCH_VER                  0

#if (SDADC_CFG_H_VENDOR_ID               != SDADC_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_LLD_C_VENDOR_ID "
#endif
#if (SDADC_CFG_H_AR_REL_MAJOR_VER    != SDADC_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_MINOR_VER    != SDADC_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_AR_REL_MINOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_REV_VER != SDADC_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_AR_REL_REV_VER "
#endif
#if (SDADC_CFG_H_SW_MAJOR_VER        != SDADC_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_SW_MAJOR_VER "
#endif
#if (SDADC_CFG_H_SW_MINOR_VER        != SDADC_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_SW_MINOR_VER "
#endif
#if (SDADC_CFG_H_SW_PATCH_VER        != SDADC_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_LLD_C_SW_PATCH_VER "
#endif

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
static FUNC(uint32, SDADC_CODE) SDADC_LLD_CalculateGain(CONST(Sdadc_InstanceType, SDADC_CONST) instance, P2CONST(Sdadc_OsrParameterType, AUTOMATIC, SDADC_APPL_CONST) pSdadc_OsrPara);
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
static FUNC(uint32, SDADC_CODE) SDADC_LLD_CalculateOffset(CONST(Sdadc_InstanceType, SDADC_CONST) instance, VAR(uint32, SDADC_VAR) gainVal, P2CONST(Sdadc_OsrParameterType, AUTOMATIC, SDADC_APPL_CONST) pSdadc_OsrPara);
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CONFIG_DATA
#include "SDAdc_MemMap.h"
static CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) Adc_SdadcBase[SDADC_MAX_INSTANCE] = SDADC_BASE_PTR_ARRAY;
#define SDADC_STOP_SEC_CONFIG_DATA
#include "SDAdc_MemMap.h"

#ifdef RESOURCE_SUPPORT_SIUL_IP
#define SDADC_START_SEC_VAR_SHARED_NO_INIT
#include "SDAdc_MemMap.h"
static VAR(uint32, SDADC_VAR) Sdadc_SiulTrig[4];
#define SDADC_STOP_SEC_VAR_SHARED_NO_INIT
#include "SDAdc_MemMap.h"
#endif

/*******************************************************************************
 * @brief SDADC Demodulator Input Configuration Register (SDADC_DICFG: ITRMODE)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_DICFG_SetIntegratorTriggerMode \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) IntegratorTriggerMode \
)
{
    BasePtr->DICFG.R = SDADC_DICFG_ITRMODE(IntegratorTriggerMode);/* polyspace RTE:IDP */  
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"
/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: CALIB_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_FCFGM_SetCalibEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_CALIB_EN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_CALIB_EN_MASK;      /* polyspace RTE:NIV,IDP */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SDADC_IECFG: FWM_INT_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_IECFG_SetFifoWaterMarkerIntEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SDADC_IECFG_FWM_INT_EN_MASK;     /* polyspace RTE:NIV,IDP */
    }
    else
    {
        BasePtr->IECFG.R |= SDADC_IECFG_FWM_INT_EN_MASK;     /* polyspace RTE:NIV,IDP */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Control Register (SDADC_CTRL: SDADC_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_CTRL_SetSdadcEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    BasePtr->CTRL.R = ((EnDis == FALSE) ? 0UL : SDADC_CTRL_EN_MASK);/* polyspace RTE:IDP */  
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Gain Correction Register (SDADC_GAINCORR: CICSHIFT)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_GAINCORR_SetCorrection \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CorrMultiFactor, \
    CONST(uint8, SDADC_CONST) CICShift \
)
{
    BasePtr->GAINCORR.R = SDADC_GAINCORR_GAINFACTOR(CorrMultiFactor) | SDADC_GAINCORR_CICSHIFT(CICShift);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Gain Calibration Register (SDADC_GAINCAL: CALFACTOR)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_GAINCAL_SetMultiFactor \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CalMultiFactor \
)
{
    BasePtr->GAINCAL.R = SDADC_GAINCAL_CALFACTOR(CalMultiFactor);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, CIC Filter (SDADC_FCFGC: CFMDF)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGC_SetCICFilterDecFactor \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CICFilterDecFactor \
)
{
    BasePtr->FCFGC.R &= ~SDADC_FCFGC_CFMDF_MASK;     /* polyspace RTE:NIV */
    BasePtr->FCFGC.R |= SDADC_FCFGC_CFMDF(CICFilterDecFactor);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, CIC Filter (SDADC_FCFGC: CFMSV)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGC_SetCICFilterStartVal \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CICFilterStartVal \
)
{
    BasePtr->FCFGC.R &= ~SDADC_FCFGC_CFMSV_MASK;     /* polyspace RTE:NIV */
    BasePtr->FCFGC.R |= SDADC_FCFGC_CFMSV(CICFilterStartVal);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Counter Register, CIC Filter (SDADC_FCNTC: CFMDCNT)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCNTC_SetCICFilterDecCounter \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) CICFilterDecCounter \
)
{
    BasePtr->FCNTC.R &= ~SDADC_FCNTC_CFMDCNT_MASK;     /* polyspace RTE:NIV */
    BasePtr->FCNTC.R |= SDADC_FCNTC_CFMDCNT(CICFilterDecCounter);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: FIR0EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetFIR0FilterEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_FIR0EN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_FIR0EN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: FIR1EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetFIR1FilterEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_FIR1EN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_FIR1EN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: OVCEN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetOvershootCompenEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_OVCEN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_OVCEN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: FIR1DEC)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetFIR1FilterDecRate \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FIR1FilterDecRate \
)
{
    if (FIR1FilterDecRate == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_FIR1DEC_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_FIR1DEC_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: CICMOD)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetCICFilterMode \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) CICFilterMode \
)
{
    if (CICFilterMode == SDADC_CIC_MODE_CIC3)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_CICMOD_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_CICMOD_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: PFEN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetPrefilterEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_PFEN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_PFEN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: COMPTR_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetBoundaryComparatorEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_COMPTR_EN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_COMPTR_EN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: EXT_MESH_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetExtMeshClkEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_EXT_MESH_EN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_EXT_MESH_EN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: OCEN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetOffsetCompenFilterEn \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) OffsetCompenFilterEn \
)
{
    BasePtr->FCFGM.R &= ~SDADC_FCFGM_OCEN_MASK;     /* polyspace RTE:NIV */
    BasePtr->FCFGM.R |= SDADC_FCFGM_OCEN(OffsetCompenFilterEn);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: CH_WRAP_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetChannelWraparoundEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_CH_WRAP_EN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_CH_WRAP_EN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Configuration Register, Main (SDADC_FCFGM: DIFF_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFGM_SetDifferenceEnDis 
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFGM.R &= ~SDADC_FCFGM_DIFF_EN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFGM.R |= SDADC_FCFGM_DIFF_EN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Offset Compensation Register (SDADC_OFFCOMP: OFFSET)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_OFFCOMP_SetOffsetVal \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) OffsetVal \
)
{
    BasePtr->OFFCOMP.R = SDADC_OFFCOMP_OFFSET(OffsetVal);     /* polyspace RTE:NIV */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(uint32, SDADC_CODE) SDADC_OFFCOMP_GetOffsetVal(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->OFFCOMP.R);     /* polyspace RTE:NIV */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SDADC_IECFG: FOV_INT_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_IECFG_SetFifoOverFlowIntEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SDADC_IECFG_FOV_INT_EN_MASK;     /* polyspace RTE:NIV,IDP */
    }
    else
    {
        BasePtr->IECFG.R |= SDADC_IECFG_FOV_INT_EN_MASK;     /* polyspace RTE:NIV,IDP */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SDADC_IECFG: DOV_INT_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_IECFG_SetDataOverFlowIntEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SDADC_IECFG_DOV_INT_EN_MASK;     /* polyspace RTE:NIV,IDP */
    }
    else
    {
        BasePtr->IECFG.R |= SDADC_IECFG_DOV_INT_EN_MASK;     /* polyspace RTE:NIV,IDP */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Interrupt Enable Configuration Register (SDADC_IECFG: DMA_REQ_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_IECFG_SetDMAReqEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->IECFG.R &= ~SDADC_IECFG_DMA_REQ_EN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->IECFG.R |= SDADC_IECFG_DMA_REQ_EN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SDADC_FCFG: FIFOSIZE)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFG_SetFifoSize
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FifoSize \
)
{
    BasePtr->FCFG.R &= ~SDADC_FCFG_FIFOSIZE_MASK;     /* polyspace RTE:NIV */
    BasePtr->FCFG.R |= SDADC_FCFG_FIFOSIZE(FifoSize);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SDADC_FCFG: FIFOWM)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFG_SetFifoWaterMarkerVal \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FifoWaterMarkerVal \
)
{
    BasePtr->FCFG.R &= ~SDADC_FCFG_FIFOWM_MASK;     /* polyspace RTE:NIV */
    BasePtr->FCFG.R |= SDADC_FCFG_FIFOWM(FifoWaterMarkerVal);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SDADC_FCFG: INFOEN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFG_SetInfoEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFG.R &= ~SDADC_FCFG_INFOEN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFG.R |= SDADC_FCFG_INFOEN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC FIFO Configuration Register (SDADC_FCFG: SIGNEN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCFG_SetSignEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCFG.R &= ~SDADC_FCFG_SIGNEN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCFG.R |= SDADC_FCFG_SIGNEN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC FIFO Data Register (SDADC_FDATA: DATA)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(uint32, SDADC_CODE) SDADC_FDATA_GetFifoData(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->FDATA.R);     /* polyspace RTE:NIV,IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"
/*******************************************************************************
 * @brief SDADC Integrator Status Register (SDADC_ISTAT: INTEN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(uint8, SDADC_CODE) SDADC_ISTAT_GetIntegrationEn(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)((BasePtr->ISTAT.R & SDADC_ISTAT_INTEN_MASK) >> SDADC_ISTAT_INTEN_SHIFT);     /* polyspace RTE:NIV,IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Intermediate Integration Value Register (SDADC_IIVAL: IVAL)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(uint32, SDADC_CODE) SDADC_IIVAL_GetInterIntegrationVal(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->IIVAL.R);     /* polyspace RTE:NIV,IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: ISC)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetIntegratorShiftCtrl \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) IntegratorShiftCtrl \
)
{
    BasePtr->IWCTR.R &= ~SDADC_IWCTR_ISC_MASK;     /* polyspace RTE:NIV */
    BasePtr->IWCTR.R |= SDADC_IWCTR_ISC(IntegratorShiftCtrl);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: IWS)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetIntegrationWindowSize \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) IntegrationWindowSize \
)
{
    if (IntegrationWindowSize == FALSE)
    {
        BasePtr->IWCTR.R &= ~SDADC_IWCTR_IWS_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->IWCTR.R |= SDADC_IWCTR_IWS_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: FRC)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetFilterRestartCtrl \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FilterRestartCtrl \
)
{
    if (FilterRestartCtrl == FALSE)
    {
        BasePtr->IWCTR.R &= ~SDADC_IWCTR_FRC_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->IWCTR.R |= SDADC_IWCTR_FRC_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: REPVAL)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetIntegrationCycle \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) IntegrationCycle \
)
{
    BasePtr->IWCTR.R &= ~SDADC_IWCTR_REPVAL_MASK;     /* polyspace RTE:NIV */
    BasePtr->IWCTR.R |= SDADC_IWCTR_REPVAL(IntegrationCycle);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: NVALDIS)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetNumberOfValDiscarded \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) NumberOfValDiscarded \
)
{
    BasePtr->IWCTR.R &= ~SDADC_IWCTR_NVALDIS_MASK;     /* polyspace RTE:NIV */
    BasePtr->IWCTR.R |= SDADC_IWCTR_NVALDIS(NumberOfValDiscarded);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Integration Window Control Register (SDADC_IWCTR: NVALINT)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_IWCTR_SetNumberOfValAccumulated \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) NumberOfValAccumulated \
)
{
    BasePtr->IWCTR.R &= ~SDADC_IWCTR_NVALINT_MASK;     /* polyspace RTE:NIV */
    BasePtr->IWCTR.R |= SDADC_IWCTR_NVALINT(NumberOfValAccumulated);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"


/*******************************************************************************
 * @brief SDADC Boundary Select Register (SDADC_BOUNDSEL: BOUNDARYL / BOUNDARYU)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_BOUNDSEL_SetLowerUpperBoundaryLimit \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) LowerBoundaryLimit, \
    CONST(uint16, SDADC_CONST) UpperBoundaryLimit \
)
{
    BasePtr->BOUNDSEL.R = SDADC_BOUNDSEL_BOUNDARYL(LowerBoundaryLimit) | SDADC_BOUNDSEL_BOUNDARYU(UpperBoundaryLimit);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC WaterMarker Interrupt State Register (SDADC_WMINTSTAT: FWM_INT)
 *
 * @note  Read / Write 1 clear.
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(uint8, SDADC_CODE) SDADC_WMINTSTAT_GetWaterMarkerIntState(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)(BasePtr->WMINTSTAT.R & SDADC_WMINTSTAT_FWM_INT_MASK);     /* polyspace RTE:NIV,IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_WMINTSTAT_ClearWaterMarkerIntState(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    BasePtr->WMINTSTAT.R = SDADC_WMINTSTAT_FWM_INT_MASK;     /* polyspace RTE:NIV,IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC OverFlow Interrupt State Register
 *          (SDADC_OVINTSTAT: FOV_INT / DOV_INT)
 *
 * @note  Read / Write 1 clear.
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(uint8, SDADC_CODE) SDADC_OVINTSTAT_GetDataOverFlowIntState(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)((BasePtr->OVINTSTAT.R & SDADC_OVINTSTAT_DOV_INT_MASK) >> 1U);     /* polyspace RTE:NIV,IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_OVINTSTAT_ClearDataOverFlowIntState(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{															/* PRQA S 4391 */						
    BasePtr->OVINTSTAT.R = SDADC_OVINTSTAT_DOV_INT_MASK;	/* PRQA S 4391 */	/* polyspace RTE:IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(uint8, SDADC_CODE) SDADC_OVINTSTAT_GetFifoOverFlowIntState(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint8)(BasePtr->OVINTSTAT.R & SDADC_OVINTSTAT_FOV_INT_MASK);     /* polyspace RTE:NIV,IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_OVINTSTAT_ClearFifoOverFlowIntState(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{															/* PRQA S 4391 */
    BasePtr->OVINTSTAT.R = SDADC_OVINTSTAT_FOV_INT_MASK;	/* PRQA S 4391 */	/* polyspace RTE:IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SDADC_OVSCFG: SRFS)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_OVSCFG_SetSlewRateFilterStrength \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) SlewRateFilterStrength \
)
{
    BasePtr->OVSCFG.R &= ~SDADC_OVSCFG_SRFS_MASK;     /* polyspace RTE:NIV */
    BasePtr->OVSCFG.R |= SDADC_OVSCFG_SRFS(SlewRateFilterStrength);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SDADC_OVSCFG: SRFRT)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_OVSCFG_SetSlewRateFilterRunTime \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) SlewRateFilterRunTime \
)
{
    BasePtr->OVSCFG.R &= ~SDADC_OVSCFG_SRFRT_MASK;     /* polyspace RTE:NIV */
    BasePtr->OVSCFG.R |= SDADC_OVSCFG_SRFRT(SlewRateFilterRunTime);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SDADC_OVSCFG: SDM)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_OVSCFG_SetStepDetectionMode \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) StepDetectionMode \
)
{
    if (StepDetectionMode == FALSE)
    {
        BasePtr->OVSCFG.R &= ~SDADC_OVSCFG_SDM_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->OVSCFG.R |= SDADC_OVSCFG_SDM_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Overshoot Compensation Configuration Register
 *          (SDADC_OVSCFG: SDTH)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_OVSCFG_SetStepDetectionThreshold \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint16, SDADC_CONST) StepDetectionThreshold \
)
{
    BasePtr->OVSCFG.R &= ~SDADC_OVSCFG_SDTH_MASK;     /* polyspace RTE:NIV */
    BasePtr->OVSCFG.R |= SDADC_OVSCFG_SDTH(StepDetectionThreshold);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Hardware Trigger Configuration Register
 *          (SDADC_HTCFG: HT0 ~ HT15)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_HTCFG_SetHwTriggerEdge \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint32, SDADC_CONST) HwTrigIdx, \
    CONST(uint32, SDADC_CONST) HwTrigEdge \
)
{
    if (HwTrigIdx < SDADC_HW_TRIG_CNT)
    {	
        /* PRQA S 1891 */	
        if((SDADC_HTCFG_HT0_WIDTH * HwTrigIdx) <= 32U)
        {
            BasePtr->HTCFG.R &= ~(SDADC_HTCFG_HT0_MASK  << (SDADC_HTCFG_HT0_WIDTH * HwTrigIdx));			/* PRQA S 1891 */       /* polyspace RTE:NIV */  
        }
        if((SDADC_HTCFG_HT0_WIDTH * HwTrigIdx) <= 32U)
        {
            BasePtr->HTCFG.R |= ((HwTrigEdge & SDADC_HTCFG_HT0_MASK) << (SDADC_HTCFG_HT0_WIDTH * HwTrigIdx));	/* PRQA S 1891 */	     /* polyspace RTE:NIV */
        }
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Software Trigger Configuration Register (SDADC_STCFG: SH_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_STCFG_SetSoftTrigEn(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    BasePtr->STCFG.R = SDADC_STCFG_SH_EN_MASK;/* polyspace RTE:IDP */  
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Software Trigger Configuration Register (SDADC_STCFG: SH_CLR)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_STCFG_ClearSoftTrig(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    BasePtr->STCFG.R = SDADC_STCFG_SH_CLR_MASK;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Software Trigger Configuration Register (SDADC_STCFG: FSRSTN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_STCFG_SetFifoSoftReset(CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    BasePtr->STCFG.R = SDADC_STCFG_FSRSTN_MASK;/* polyspace RTE:IDP */  
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Chain Discard Register (SDADC_FCDIS: FCDIS_EN)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCDIS_SetFilterChainDiscardEnDis \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(boolean, SDADC_CONST) EnDis \
)
{
    if (EnDis == FALSE)
    {
        BasePtr->FCDIS.R &= ~SDADC_FCDIS_FCDIS_EN_MASK;     /* polyspace RTE:NIV */
    }
    else
    {
        BasePtr->FCDIS.R |= SDADC_FCDIS_FCDIS_EN_MASK;     /* polyspace RTE:NIV */
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Filter Chain Discard Register (SDADC_FCDIS: FCDIS_NUM)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_FCDIS_SetFilterChainDiscardNum \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) FilterChainDiscardNum \
)
{
    BasePtr->FCDIS.R &= ~SDADC_FCDIS_FCDIS_NUM_MASK;     /* polyspace RTE:NIV */
    BasePtr->FCDIS.R |= SDADC_FCDIS_FCDIS_NUM(FilterChainDiscardNum);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Channel default & wrap Register (SDADC_CH_WRAP: CH_DFLT /CH_NUM)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_CH_WRAP_SetChannelDefault \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) ChannelDefault, \
    CONST(uint8, SDADC_CONST) ChannelWrap \
)
{
    BasePtr->CH_WRAP.R = SDADC_CH_WRAP_CH_DFLT(ChannelDefault) | SDADC_CH_WRAP_CH_NUM(ChannelWrap);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Analog Channel Resistor Select Register (SDADC_RES)
 *******************************************************************************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_RES_SetResistorSelChan \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) res_p_lv, \
    CONST(uint8, SDADC_CONST) res_n_lv \
)
{
    BasePtr->RES.R = SDADC_RES_RES_N_LV(res_n_lv) | SDADC_RES_RES_P_LV(res_p_lv);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

/*******************************************************************************
 * @brief SDADC Analog Module Configuration Register (SDADC_ATT)
 **************************************************************** ***************/
#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(void, SDADC_CODE) SDADC_ATT_SetAnalogModuleCfg \
(
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr, \
    CONST(uint8, SDADC_CONST) gain_lv, \
    CONST(uint8, SDADC_CONST) vcom_sel_lv, \
    CONST(uint8, SDADC_CONST) adc_div_lv \
)
{
    BasePtr->ATT.R = (SDADC_ATT_GAIN_LV(gain_lv) | SDADC_ATT_VCOM_SEL_LV(vcom_sel_lv) | 	/* polyspace RTE:IDP */
                      SDADC_ATT_ADC_DIV_LV(adc_div_lv));
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
SDADC_INLINE FUNC(uint32, SDADC_CODE) SDADC_ATT_GetAnalogModuleCfg(CONSTP2CONST(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr)
{
    return (uint32)(BasePtr->ATT.R);     /* polyspace RTE:NIV,IDP */
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_Init \
(
	CONST(Sdadc_InstanceType, SDADC_CONST) instance, \
	CONSTP2CONST(Sdadc_ConfigType, SDADC_CONST, SDADC_APPL_CONST) ConfigPtr, \
	CONST(uint16, SDADC_CONST) Trig_Sel
)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));
    DEV_ASSERT(ConfigPtr != NULL);

    VAR(uint8, SDADC_VAR) u8inst = (uint8)instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[u8inst];/* polyspace RTE:OBAI */

    VAR(uint32, SDADC_VAR) gain_cal_val, offset_cal_val = 0U;
#ifdef RESOURCE_SUPPORT_SIUL2_IP
    P2VAR(uint32, SDADC_VAR, SDADC_APPL_CONST) SDAdc_MSCR[SDADC_MAX_INSTANCE] =
    {
        (uint32 *)(0xfffc0b88U), //SIUL2_MSCR[594] 
        (uint32 *)(0xfffc0b8cU), //SIUL2_MSCR[595] 
        (uint32 *)(0xfffc0b90U), //SIUL2_MSCR[596] 
        (uint32 *)(0xfffc0b94U), //SIUL2_MSCR[597] 
        (uint32 *)(0xfffc0b98U), //SIUL2_MSCR[598] 
        (uint32 *)(0xfffc0b9CU), //SIUL2_MSCR[599] 
        (uint32 *)(0xfffc0ba0U), //SIUL2_MSCR[600] 
        (uint32 *)(0xfffc0ba4U), //SIUL2_MSCR[601] 
        (uint32 *)(0xfffc0ba8U), //SIUL2_MSCR[602]     
    };
    VAR(Sdadc_HwTrigSourceType, SDADC_VAR) SDAdc_HwTrigMap[] =
    {
        TOM2_4_SOURCE,
        TOM2_5_SOURCE,
        TOM2_6_SOURCE,
        TOM2_7_SOURCE,
        TOM2_8_SOURCE,
        TOM2_9_SOURCE,
        TOM2_10_SOURCE,
        TOM2_11_SOURCE,
        ATOM3_0_SOURCE,
        ATOM3_1_SOURCE,
        ATOM3_2_SOURCE,
        ATOM3_3_SOURCE,
        ATOM3_4_SOURCE,
        ATOM3_5_SOURCE,
        ATOM3_6_SOURCE,
        ATOM3_7_SOURCE,
    };
#endif
#ifdef RESOURCE_SUPPORT_SIUL_IP
#ifdef CCFC3010PTD
    VAR(Sdadc_HwTrigSourceType, SDADC_VAR) SDAdc_HwTrigMap[] =
    {
        SDADC_GTM_TRIG0_BIT0,
        SDADC_GTM_TRIG0_BIT1,
        SDADC_GTM_TRIG0_BIT2,
        SDADC_GTM_TRIG0_BIT3,
        SDADC_GTM_TRIG0_BIT4,
        SDADC_GTM_TRIG0_BIT5,
        SDADC_GTM_TRIG0_BIT6,
        SDADC_GTM_TRIG0_BIT7,
        SDADC_GTM_TRIG0_BIT8,
        SDADC_GTM_TRIG0_BIT9,
        SDADC_GTM_TRIG0_BIT10,
        SDADC_GTM_TRIG0_BIT11,
        SDADC_GTM_TRIG0_BIT12,
        SDADC_GTM_TRIG0_BIT13,
        SDADC_GTM_TRIG1_BIT0,
        SDADC_GTM_TRIG1_BIT1,
        SDADC_GTM_TRIG1_BIT2,
        SDADC_GTM_TRIG1_BIT3,
        SDADC_GTM_TRIG1_BIT4,
        SDADC_GTM_TRIG1_BIT5,
        SDADC_GTM_TRIG1_BIT6,
        SDADC_GTM_TRIG1_BIT7,
        SDADC_GTM_TRIG1_BIT8,
        SDADC_GTM_TRIG1_BIT9,
        SDADC_GTM_TRIG1_BIT10,
        SDADC_GTM_TRIG1_BIT11,
        SDADC_GTM_TRIG1_BIT12,
        SDADC_GTM_TRIG1_BIT13,
        SDADC_GTM_TRIG2_BIT0,
        SDADC_GTM_TRIG2_BIT1,
        SDADC_GTM_TRIG2_BIT2,
        SDADC_GTM_TRIG2_BIT3,
        SDADC_GTM_TRIG2_BIT4,
        SDADC_GTM_TRIG2_BIT5,
        SDADC_GTM_TRIG2_BIT6,
        SDADC_GTM_TRIG2_BIT7,
        SDADC_GTM_TRIG2_BIT8,
        SDADC_GTM_TRIG2_BIT9,
        SDADC_GTM_TRIG2_BIT10,
        SDADC_GTM_TRIG2_BIT11,
        SDADC_GTM_TRIG2_BIT12,
        SDADC_GTM_TRIG2_BIT13,
        SDADC_GTM_TRIG3_BIT0,
        SDADC_GTM_TRIG3_BIT1,
        SDADC_GTM_TRIG3_BIT2,
        SDADC_GTM_TRIG3_BIT3,
        SDADC_GTM_TRIG3_BIT4,
        SDADC_GTM_TRIG3_BIT5,
        SDADC_GTM_TRIG3_BIT6,
        SDADC_GTM_TRIG3_BIT7,
        SDADC_GTM_TRIG3_BIT8,
        SDADC_GTM_TRIG3_BIT9,
        SDADC_GTM_TRIG3_BIT10,
        SDADC_GTM_TRIG3_BIT11,
        SDADC_GTM_TRIG3_BIT12,
        SDADC_GTM_TRIG3_BIT13,
        SDADC_TRIG_PAD3,
        SDADC_TRIG_PAD6,
        SDADC_TRIG_PAD9,
        SDADC_TRIG_PAD19,
        SDADC_TRIG_PAD20,
        SDADC_TRIG_PAD23,
        SDADC_TRIG_PAD38,
        SDADC_TRIG_PAD39,
        SDADC_TRIG_PAD40,
        SDADC_TRIG_PAD241,
        SDADC_TRIG_PAD242,
        SDADC_TRIG_PAD243,
        SDADC_TRIG_PAD245,
        SDADC_TRIG_PAD246,
        SDADC_TRIG_PAD247,
        SDADC_GTM_ATOM0_0,
        SDADC_GTM_ATOM0_1,
        SDADC_GTM_ATOM0_2,
        SDADC_GTM_ATOM0_3,
        SDADC_GTM_ATOM0_4,
        SDADC_GTM_ATOM0_5,
        SDADC_GTM_ATOM0_6,
        SDADC_GTM_ATOM0_7,
        SDADC_GTM_ATOM1_0,
        SDADC_GTM_ATOM1_1,
        SDADC_GTM_ATOM1_2,
        SDADC_GTM_ATOM1_3,
        SDADC_GTM_ATOM1_4,
        SDADC_GTM_ATOM1_5,
        SDADC_GTM_ATOM1_6,
        SDADC_GTM_ATOM1_7,
        SDADC_GTM_ATOM2_0,
        SDADC_GTM_ATOM2_1,
        SDADC_GTM_ATOM2_2,
        SDADC_GTM_ATOM2_3,
        SDADC_GTM_ATOM2_4,
        SDADC_GTM_ATOM2_5,
        SDADC_GTM_ATOM2_6,
        SDADC_GTM_ATOM2_7,
        SDADC_GTM_ATOM3_0,
        SDADC_GTM_ATOM3_1,
        SDADC_GTM_ATOM3_2,
        SDADC_GTM_ATOM3_3,
        SDADC_GTM_ATOM3_4,
        SDADC_GTM_ATOM3_5,
        SDADC_GTM_ATOM3_6,
        SDADC_GTM_ATOM3_7,
        SDADC_GTM_TOM0_0,
        SDADC_GTM_TOM0_1,
        SDADC_GTM_TOM0_2,
        SDADC_GTM_TOM0_3,
        SDADC_GTM_TOM0_4,
        SDADC_GTM_TOM0_5,
        SDADC_GTM_TOM0_6,
        SDADC_GTM_TOM0_7,
        SDADC_GTM_TOM0_8,
        SDADC_GTM_TOM0_9,
        SDADC_GTM_TOM0_10,
        SDADC_GTM_TOM0_11,
        SDADC_GTM_TOM0_12,
        SDADC_GTM_TOM0_13,
        SDADC_GTM_TOM0_14,
        SDADC_GTM_TOM0_15,
        SDADC_GTM_TOM1_0,
        SDADC_GTM_TOM1_1,
        SDADC_GTM_TOM1_2,
        SDADC_GTM_TOM1_3,
        SDADC_GTM_TOM1_4,
        SDADC_GTM_TOM1_5,
        SDADC_GTM_TOM1_6,
        SDADC_GTM_TOM1_7,
        SDADC_GTM_TOM1_8,
        SDADC_GTM_TOM1_9,
        SDADC_GTM_TOM1_10,
        SDADC_GTM_TOM1_11,
        SDADC_GTM_TOM1_12,
        SDADC_GTM_TOM1_13,
        SDADC_GTM_TOM1_14,
        SDADC_GTM_TOM1_15,
        SDADC_EMIOS0_FLAG_OUT_0,
        SDADC_EMIOS0_FLAG_OUT_1,
        SDADC_EMIOS0_FLAG_OUT_2,
        SDADC_EMIOS0_FLAG_OUT_3,
        SDADC_EMIOS0_FLAG_OUT_4,
        SDADC_EMIOS0_FLAG_OUT_5,
        SDADC_EMIOS0_FLAG_OUT_6,
        SDADC_EMIOS0_FLAG_OUT_7,
        SDADC_EMIOS0_FLAG_OUT_16,
        SDADC_EMIOS0_FLAG_OUT_17,
        SDADC_EMIOS0_FLAG_OUT_18,
        SDADC_EMIOS0_FLAG_OUT_19,
        SDADC_EMIOS0_FLAG_OUT_20,
        SDADC_EMIOS0_FLAG_OUT_21,
        SDADC_EMIOS0_FLAG_OUT_22,
        SDADC_EMIOS0_FLAG_OUT_23,
        SDADC_EMIOS0_FLAG_OUT_24,
    };
#else
    VAR(Sdadc_HwTrigSourceType, SDADC_VAR) SDAdc_HwTrigMap[] =
    {
        SDADC_GTM_TRIG0_BIT0,
        SDADC_GTM_TRIG0_BIT1,
        SDADC_GTM_TRIG0_BIT2,
        SDADC_GTM_TRIG0_BIT3,
        SDADC_GTM_TRIG0_BIT4,
        SDADC_GTM_TRIG0_BIT5,
        SDADC_GTM_TRIG0_BIT6,
        SDADC_GTM_TRIG0_BIT7,
        SDADC_GTM_TRIG0_BIT8,
        SDADC_GTM_TRIG0_BIT9,
        SDADC_GTM_TRIG0_BIT10,
        SDADC_GTM_TRIG0_BIT11,
        SDADC_GTM_TRIG0_BIT12,
        SDADC_GTM_TRIG0_BIT13,
        SDADC_GTM_TRIG1_BIT0,
        SDADC_GTM_TRIG1_BIT1,
        SDADC_GTM_TRIG1_BIT2,
        SDADC_GTM_TRIG1_BIT3,
        SDADC_GTM_TRIG1_BIT4,
        SDADC_GTM_TRIG1_BIT5,
        SDADC_GTM_TRIG1_BIT6,
        SDADC_GTM_TRIG1_BIT7,
        SDADC_GTM_TRIG1_BIT8,
        SDADC_GTM_TRIG1_BIT9,
        SDADC_GTM_TRIG1_BIT10,
        SDADC_GTM_TRIG1_BIT11,
        SDADC_GTM_TRIG1_BIT12,
        SDADC_GTM_TRIG1_BIT13,
        SDADC_GTM_TRIG2_BIT0,
        SDADC_GTM_TRIG2_BIT1,
        SDADC_GTM_TRIG2_BIT2,
        SDADC_GTM_TRIG2_BIT3,
        SDADC_GTM_TRIG2_BIT4,
        SDADC_GTM_TRIG2_BIT5,
        SDADC_GTM_TRIG2_BIT6,
        SDADC_GTM_TRIG2_BIT7,
        SDADC_GTM_TRIG2_BIT8,
        SDADC_GTM_TRIG2_BIT9,
        SDADC_GTM_TRIG2_BIT10,
        SDADC_GTM_TRIG2_BIT11,
        SDADC_GTM_TRIG2_BIT12,
        SDADC_GTM_TRIG2_BIT13,
        SDADC_GTM_TRIG3_BIT0,
        SDADC_GTM_TRIG3_BIT1,
        SDADC_GTM_TRIG3_BIT2,
        SDADC_GTM_TRIG3_BIT3,
        SDADC_GTM_TRIG3_BIT4,
        SDADC_GTM_TRIG3_BIT5,
        SDADC_GTM_TRIG3_BIT6,
        SDADC_GTM_TRIG3_BIT7,
        SDADC_GTM_TRIG3_BIT8,
        SDADC_GTM_TRIG3_BIT9,
        SDADC_GTM_TRIG3_BIT10,
        SDADC_GTM_TRIG3_BIT11,
        SDADC_GTM_TRIG3_BIT12,
        SDADC_GTM_TRIG3_BIT13,
        SDADC_TRIG_PAD15,
        SDADC_TRIG_PAD3,
        SDADC_TRIG_PAD6,
        SDADC_TRIG_PAD9,
        SDADC_TRIG_PAD16,
        SDADC_TRIG_PAD26,
        SDADC_TRIG_PAD27,
        SDADC_TRIG_PAD28,
        SDADC_TRIG_PAD29,
        SDADC_TRIG_PAD30,
        SDADC_TRIG_PAD31,
        SDADC_TRIG_PAD17,
        SDADC_TRIG_PAD19,
        SDADC_TRIG_PAD20,
        SDADC_TRIG_PAD23,
        SDADC_TRIG_PAD44,
        SDADC_TRIG_PAD45,
        SDADC_TRIG_PAD46,
        SDADC_TRIG_PAD47,
        SDADC_TRIG_PAD38,
        SDADC_TRIG_PAD39,
        SDADC_TRIG_PAD40,
        SDADC_TRIG_PAD241,
        SDADC_TRIG_PAD242,
        SDADC_TRIG_PAD243,
        SDADC_TRIG_PAD245,
        SDADC_TRIG_PAD246,
        SDADC_TRIG_PAD247,
    };
#endif // #if defined(CCFC3010PTD)
#endif
#ifdef RESOURCE_SUPPORT_SIUL2_IP
	P2VAR(uint32, SDADC_VAR, SDADC_APPL_DATA) MSCRPtr = SDAdc_MSCR[instance];/* polyspace RTE:OBAI */
#endif
    DEV_ASSERT((ConfigPtr->AnalogCfg.PreGain == SDADC_PRE_GAIN_X1) || \
               (ConfigPtr->AnalogCfg.PreGain == SDADC_PRE_GAIN_X2) || \
               (ConfigPtr->AnalogCfg.PreGain == SDADC_PRE_GAIN_X4));
    DEV_ASSERT((uint8)(ConfigPtr->AnalogCfg.VcomSel) <= (uint8)SDADC_VCOM_SEL_VREF_L);
    DEV_ASSERT((uint8)(ConfigPtr->AnalogCfg.ClkDiv) <= (uint8)SDADC_CLK_DIV_8);
    
    VAR(uint16, SDADC_VAR) cicFilterDecimationFactor = 0;
    VAR(uint8, SDADC_VAR) cicFilterOutputShifter = 0;
    VAR(boolean, SDADC_VAR) fir0State = TRUE, fir1State = TRUE, preFilterState = TRUE;
    VAR(Sdadc_OsrParameterType, SDADC_VAR) PosrPara;/* polyspace RTE:OBAI */

    switch(ConfigPtr->OsrVal)/* polyspace RTE:NIV,IDP */
    {
        case SDADC_OSR_12:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 5U;

                cicFilterOutputShifter = 2U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }

                fir0State = FALSE;

                preFilterState = FALSE;
            }
            else
            {
                cicFilterDecimationFactor = 2U;

                cicFilterOutputShifter = 3U;

                fir0State = FALSE;
            }

            break;
        }

        case SDADC_OSR_16:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 3U;

                cicFilterOutputShifter = 3U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }

                fir0State = FALSE;
            }
            else
            {
                cicFilterDecimationFactor = 3U;

                cicFilterOutputShifter = 4U;

                fir0State = FALSE;
            }

            break;
        }

        case SDADC_OSR_24:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 5U;

                cicFilterOutputShifter = 6U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }

                fir0State = FALSE;
            }
            else
            {
                cicFilterDecimationFactor = 2U;

                cicFilterOutputShifter = 7U;
            }

            break;
        }

        case SDADC_OSR_32:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 3U;

                cicFilterOutputShifter = 3U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 3U;

                cicFilterOutputShifter = 4U;
            }

            break;
        }

        case SDADC_OSR_48:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 5U;

                cicFilterOutputShifter = 6U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 5U;

                cicFilterOutputShifter = 7U;
            }

            break;
        }

        case SDADC_OSR_64:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 7U;

                cicFilterOutputShifter = 7U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 7U;

                cicFilterOutputShifter = 8U;
            }

            break;
        }

        case SDADC_OSR_96:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 11U;

                cicFilterOutputShifter = 10U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 11U;

                cicFilterOutputShifter = 11U;
            }

            break;
        }

        case SDADC_OSR_128:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 15U;

                cicFilterOutputShifter = 11U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 15U;

                cicFilterOutputShifter = 12U;
            }

            break;
        }

        case SDADC_OSR_160:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 19U;

                cicFilterOutputShifter = 12U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 19U;

                cicFilterOutputShifter = 13U;
            }

            break;
        }

        case SDADC_OSR_192:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 23U;

                cicFilterOutputShifter = 13U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 23U;

                cicFilterOutputShifter = 14U;
            }

            break;
        }

        case SDADC_OSR_224:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 27U;

                cicFilterOutputShifter = 14U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 27U;

                cicFilterOutputShifter = 15U;
            }

            break;
        }

        case SDADC_OSR_256:
        {
            if(ConfigPtr->ChanSel.DifferenceEn == FALSE)/* polyspace RTE:NIV */
            {
                cicFilterDecimationFactor = 31U;

                cicFilterOutputShifter = 15U;

                if((uint8)(ConfigPtr->AnalogCfg.PreGain) == (uint8)2U)/* polyspace RTE:NIV */
                {
                    cicFilterOutputShifter = (uint8)(cicFilterOutputShifter + (uint8)1U);
                }
            }
            else
            {
                cicFilterDecimationFactor = 31U;

                cicFilterOutputShifter = 16U;
            }

            break;
        }

        default:
        {
            /* Nothing todo */
            break;
        }
    }

    PosrPara.OsrCicFilterDecimationFactor = cicFilterDecimationFactor;
    PosrPara.OsrFilterOutputShifter = cicFilterOutputShifter;
    PosrPara.OsrFir0State = fir0State;
    PosrPara.OsrFir1State = fir1State;
    PosrPara.OsrPreFilterState = preFilterState;

	SchM_Enter_SDAdc_EXCLUSIVE_AREA_00();

    /* Analog Module PRE configuration */
    SDADC_ATT_SetAnalogModuleCfg(BasePtr, 1U, (uint8)(ConfigPtr->AnalogCfg.VcomSel), (uint8)(ConfigPtr->AnalogCfg.ClkDiv));/* polyspace RTE:OBAI,IDP,NIV*/
    /* Calculate Gain Value */
    gain_cal_val = SDADC_LLD_CalculateGain((Sdadc_InstanceType)u8inst, &PosrPara);

    /* Calculate Offset Value */
    offset_cal_val = SDADC_LLD_CalculateOffset((Sdadc_InstanceType)u8inst, gain_cal_val, &PosrPara);

    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    SDADC_STCFG_ClearSoftTrig(BasePtr);

    SDADC_STCFG_SetFifoSoftReset(BasePtr);

    SDADC_ATT_SetAnalogModuleCfg(BasePtr, (uint8)(ConfigPtr->AnalogCfg.PreGain), (uint8)(ConfigPtr->AnalogCfg.VcomSel), (uint8)(ConfigPtr->AnalogCfg.ClkDiv));/* polyspace RTE:NIV */
    
	SDADC_GAINCORR_SetCorrection(BasePtr, (uint16)gain_cal_val, cicFilterOutputShifter);

    SDADC_FCFGC_SetCICFilterDecFactor(BasePtr, cicFilterDecimationFactor);

    SDADC_FCFGC_SetCICFilterStartVal(BasePtr, (uint16)(cicFilterDecimationFactor + (uint16)1U));

	SDADC_OFFCOMP_SetOffsetVal(BasePtr, (uint16)offset_cal_val);

	SDADC_FCNTC_SetCICFilterDecCounter(BasePtr, cicFilterDecimationFactor);

	SDADC_CH_WRAP_SetChannelDefault(BasePtr, ConfigPtr->ChanSel.ChanDefaultId, ConfigPtr->ChanWrap.ChanWraparoundNum);/* polyspace RTE:NIV */

	SDADC_GAINCAL_SetMultiFactor(BasePtr, 0x1000U);

    SDADC_FCFGM_SetFIR0FilterEnDis(BasePtr, fir0State);

    SDADC_FCFGM_SetFIR1FilterEnDis(BasePtr, fir1State);

    SDADC_FCFGM_SetOvershootCompenEnDis(BasePtr, ConfigPtr->FirFilter.OvershootCompEn);/* polyspace RTE:NIV */

    SDADC_FCFGM_SetFIR1FilterDecRate(BasePtr, (uint8)(ConfigPtr->FirFilter.Fir1DecimationRate));/* polyspace RTE:NIV */

    SDADC_FCFGM_SetCICFilterMode(BasePtr, (((ConfigPtr->FirFilter.CicMode) != FALSE) ? (uint8)1U : (uint8)0U));/* polyspace RTE:NIV */

    SDADC_FCFGM_SetPrefilterEnDis(BasePtr, preFilterState);/* polyspace RTE:NIV */

    if(ConfigPtr->Comparator.BoundaryComparatorEn == TRUE)/* polyspace RTE:NIV */
    {
        SDADC_FCFGM_SetBoundaryComparatorEnDis(BasePtr, TRUE);

        SDADC_BOUNDSEL_SetLowerUpperBoundaryLimit(BasePtr, ConfigPtr->Comparator.LowerBoundary, ConfigPtr->Comparator.UpperBoundary);/* polyspace RTE:NIV */
    }

    SDADC_FCFGM_SetExtMeshClkEnDis(BasePtr, (((uint32)(ConfigPtr->ExtMeshClkSel) != 0U) ? (boolean)TRUE : (boolean)FALSE));/* polyspace RTE:NIV */

    if(ConfigPtr->DCTestEn == FALSE)/* polyspace RTE:NIV */
    {
        SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, (uint8)(ConfigPtr->FirFilter.OffsetCompFilterEn));/* polyspace RTE:NIV */
        SDADC_RES_SetResistorSelChan(BasePtr, (((ConfigPtr->Res_P_En) != FALSE) ? (uint8)1U : (uint8)0U), (((ConfigPtr->Res_N_En) != FALSE) ? (uint8)1U : (uint8)0U));/* polyspace RTE:NIV */
    }
    else
    {
    	SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, FALSE);
    }

    SDADC_FCFGM_SetChannelWraparoundEnDis(BasePtr, ConfigPtr->ChanWrap.ChanWraparoundEn);/* polyspace RTE:NIV */

    SDADC_FCFGM_SetDifferenceEnDis(BasePtr, ConfigPtr->ChanSel.DifferenceEn);/* polyspace RTE:NIV */

    SDADC_FCFGM_SetCalibEnDis(BasePtr, ConfigPtr->FirFilter.CalibrationEn);/* polyspace RTE:NIV */

    /* Overshoot Compensation */
    if (ConfigPtr->FirFilter.OvershootCompEn != FALSE)
    {
        DEV_ASSERT(ConfigPtr->OvershootComp.StepDetectionThreshold <= SDADC_OVERSHOOT_STEP_DETECTION_THRESHOLD_MAX);

        SDADC_OVSCFG_SetSlewRateFilterStrength(BasePtr, (uint8)(ConfigPtr->OvershootComp.SlewRateFilterStrength));/* polyspace RTE:NIV */

        SDADC_OVSCFG_SetSlewRateFilterRunTime(BasePtr, (uint8)(ConfigPtr->OvershootComp.SlewRateFilterRunTime));/* polyspace RTE:NIV */

        SDADC_OVSCFG_SetStepDetectionMode(BasePtr, (uint8)(ConfigPtr->OvershootComp.StepDetectionMode));/* polyspace RTE:NIV */

        SDADC_OVSCFG_SetStepDetectionThreshold(BasePtr, ConfigPtr->OvershootComp.StepDetectionThreshold);/* polyspace RTE:NIV */
    }

    /* Interrupt/DMA Enable Configuration */
    SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, ConfigPtr->IntDma.FifoWaterMarkerIntEn);/* polyspace RTE:NIV */

    SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, ConfigPtr->IntDma.FifoOverFlowIntEn);/* polyspace RTE:NIV */

    SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, ConfigPtr->IntDma.DataOverFlowIntEn);/* polyspace RTE:NIV */

    SDADC_IECFG_SetDMAReqEnDis(BasePtr, ConfigPtr->IntDma.DmaReqEn);/* polyspace RTE:NIV */

	/* Integration configuration */
    if(ConfigPtr->IntegratorEn == TRUE)/* polyspace RTE:NIV */
    {
		DEV_ASSERT((ConfigPtr->Integrator.IntegratorTrigMode) <= SDADC_INTEGRATOR_TRIG_MODE_ALWAYS_ACTIVE);
		DEV_ASSERT((ConfigPtr->Integrator.IntegratorShiftCtrl) <= SDADC_INTEGRATOR_SHIFT_CTRL_SEL_BITS_9_25);

		SDADC_DICFG_SetIntegratorTriggerMode(BasePtr, (uint8)(ConfigPtr->Integrator.IntegratorTrigMode));/* polyspace RTE:NIV */

		SDADC_IWCTR_SetIntegratorShiftCtrl(BasePtr, (uint8)(ConfigPtr->Integrator.IntegratorShiftCtrl));/* polyspace RTE:NIV */

		SDADC_IWCTR_SetIntegrationWindowSize(BasePtr, (uint8)(ConfigPtr->Integrator.IntegrationWindowSize));/* polyspace RTE:NIV */

		SDADC_IWCTR_SetFilterRestartCtrl(BasePtr, (uint8)(ConfigPtr->Integrator.FilterChainRestartCtrl));/* polyspace RTE:NIV */

		SDADC_IWCTR_SetIntegrationCycle(BasePtr, ConfigPtr->Integrator.NumOfIntegrationCycles);/* polyspace RTE:NIV */

		SDADC_IWCTR_SetNumberOfValDiscarded(BasePtr, ConfigPtr->Integrator.NumOfDiscardedVal);/* polyspace RTE:NIV */

		SDADC_IWCTR_SetNumberOfValAccumulated(BasePtr, ConfigPtr->Integrator.NumOfAccumulatedVal);/* polyspace RTE:NIV */
    }

	/* Filter Chain Discard */
	SDADC_FCDIS_SetFilterChainDiscardEnDis(BasePtr, ConfigPtr->FilterChainDiscard.FilterChainDiscardEn);/* polyspace RTE:NIV */

	SDADC_FCDIS_SetFilterChainDiscardNum(BasePtr, ConfigPtr->FilterChainDiscard.FilterChainDiscardNum);/* polyspace RTE:NIV */

	/* FIFO Configuration */
	DEV_ASSERT(ConfigPtr->FifoCfg.FifoSize <= SDADC_FIFO_SIZE_MAX);
	DEV_ASSERT(ConfigPtr->FifoCfg.FifoSize >= ConfigPtr->FifoCfg.FifoWaterMarker);

	SDADC_FCFG_SetFifoSize(BasePtr, ConfigPtr->FifoCfg.FifoSize);/* polyspace RTE:NIV */

	SDADC_FCFG_SetFifoWaterMarkerVal(BasePtr, ConfigPtr->FifoCfg.FifoWaterMarker);/* polyspace RTE:NIV */

	SDADC_FCFG_SetInfoEnDis(BasePtr, ConfigPtr->FifoCfg.InfoEn);/* polyspace RTE:NIV */

	SDADC_FCFG_SetSignEnDis(BasePtr, ConfigPtr->FifoCfg.SignEn);/* polyspace RTE:NIV */

	if(Trig_Sel < (uint16)HWTRIGSEL_SDADC0)
	{
#ifdef RESOURCE_SUPPORT_SIUL2_IP
		*MSCRPtr = (uint32)SDAdc_HwTrigMap[Trig_Sel];/* polyspace RTE:IDP */
#endif
#ifdef RESOURCE_SUPPORT_SIUL_IP
		if(instance < SDADC_INSTANCE_4)
		{
			Sdadc_SiulTrig[0] |= (uint32)((uint8)SDAdc_HwTrigMap[Trig_Sel] << ((instance % 4U) * 8U));
			SIUL.ISEL13.R = Sdadc_SiulTrig[0];
		}
		else if(instance < SDADC_INSTANCE_8)
		{
			Sdadc_SiulTrig[1] |= (uint32)((uint8)SDAdc_HwTrigMap[Trig_Sel] << ((instance % 4U) * 8U));
			SIUL.ISEL14.R = Sdadc_SiulTrig[1];
		}
		else if(instance < SDADC_INSTANCE_12)
		{
			Sdadc_SiulTrig[2] |= (uint32)((uint8)SDAdc_HwTrigMap[Trig_Sel] << ((instance % 4U) * 8U));
			SIUL.ISEL15.R = Sdadc_SiulTrig[2];
		}
		else
		{
			Sdadc_SiulTrig[3] |= (uint32)((uint8)SDAdc_HwTrigMap[Trig_Sel] << ((instance % 4U) * 8U));
			SIUL.ISEL16.R = Sdadc_SiulTrig[3];
		}
#endif
    }
	/* Hardware Trigger Configuration */
	for(uint32 i = 0U; i < SDADC_HW_TRIG_CNT; i++)
	{
		SDADC_HTCFG_SetHwTriggerEdge(BasePtr, i, (uint32)(ConfigPtr->HwTrigSel[i]));/* polyspace RTE:NIV */
	}

    /* Clear flag */
    SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
    SDADC_OVINTSTAT_ClearDataOverFlowIntState(BasePtr);
    SDADC_OVINTSTAT_ClearFifoOverFlowIntState(BasePtr);

    SchM_Exit_SDAdc_EXCLUSIVE_AREA_00();
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_DeInit(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;
    if(instance_l >= SDADC_MAX_INSTANCE)
    {
    	return;
    }

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    /* SDADC disable */
    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    /* Flush FIFO */
    SDADC_STCFG_SetFifoSoftReset(BasePtr);

    /* Interrupt/DMA */
    BasePtr->IECFG.R    = 0UL;
    /* Control */
    BasePtr->FCFGM.R    = 0UL;
    BasePtr->DICFG.R    = 0UL;
    /* Configuration */
    BasePtr->GAINCORR.R = 0UL;
    BasePtr->GAINCAL.R  = 0UL;
    BasePtr->FCFGC.R    = 0UL;
    BasePtr->OFFCOMP.R  = 0UL;
    BasePtr->FCFG.R     = SDADC_FCFG_FIFOSIZE(SDADC_FIFO_SIZE_MAX);
    BasePtr->IWCTR.R    = 0UL;
    BasePtr->BOUNDSEL.R = 0UL;
    BasePtr->OVSCFG.R   = 0UL;
    BasePtr->HTCFG.R    = 0UL;
    BasePtr->FCDIS.R    = 0UL;
    BasePtr->CH_WRAP.R  = 0UL;

    SDADC_RES_SetResistorSelChan(BasePtr, 0U, 0U);
    SDADC_ATT_SetAnalogModuleCfg(BasePtr, 0U, 0U, 0U);

    /* Clear flag */
    SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
    SDADC_OVINTSTAT_ClearDataOverFlowIntState(BasePtr);
    SDADC_OVINTSTAT_ClearFifoOverFlowIntState(BasePtr);

	MC_RGM.PRST1.R = 0x1f000000;
	MC_RGM.PRST5.R = 0x1f000000;
	MC_RGM.PRST1.R = 0x00000000;
	MC_RGM.PRST5.R = 0x00000000;

}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_ModuleEnable(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];/* polyspace RTE:OBAI */

    SDADC_CTRL_SetSdadcEnDis(BasePtr, TRUE);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_ModuleDisable(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];/* polyspace RTE:OBAI */

    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
static FUNC(uint32, SDADC_CODE) SDADC_LLD_CalculateGain(CONST(Sdadc_InstanceType, SDADC_CONST) instance, P2CONST(Sdadc_OsrParameterType, AUTOMATIC, SDADC_APPL_CONST) pSdadc_OsrPara)
{
    VAR(uint32, SDADC_VAR) Sdadc_Timeout = 0U;

    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(uint32, SDADC_VAR) attValue;

    VAR(uint8, SDADC_VAR) attVcomSelValue, attClkDivValue;

	VAR(uint32, SDADC_VAR) gain_corr_p = 0x1000;

	VAR(uint32, SDADC_VAR) gain_corr_n = 0x1000;

	VAR(uint32, SDADC_VAR) gain_sft_mask = 0x1000;

	VAR(uint32, SDADC_VAR) hard_data ,gain_corr= 0;

    VAR(uint16, SDADC_VAR) cicFilterDecimationFactor = 0;
    VAR(uint8, SDADC_VAR) cicFilterOutputShifter = 0;
    VAR(boolean, SDADC_VAR) fir0State = TRUE, fir1State = TRUE, preFilterState = TRUE;

	cicFilterDecimationFactor = pSdadc_OsrPara->OsrCicFilterDecimationFactor;
	cicFilterOutputShifter = pSdadc_OsrPara->OsrFilterOutputShifter;
	fir0State = pSdadc_OsrPara->OsrFir0State;
	fir1State = pSdadc_OsrPara->OsrFir1State;
	preFilterState = pSdadc_OsrPara->OsrPreFilterState;
	
    attValue = SDADC_ATT_GetAnalogModuleCfg(BasePtr);

    attClkDivValue = (uint8)((attValue & SDADC_ATT_ADC_DIV_LV_MASK) >> SDADC_ATT_ADC_DIV_LV_SHIFT);

    attVcomSelValue = (uint8)((attValue & SDADC_ATT_VCOM_SEL_LV_MASK) >> SDADC_ATT_VCOM_SEL_LV_SHIFT);

    SDADC_ATT_SetAnalogModuleCfg(BasePtr, 1U, attVcomSelValue, attClkDivValue);

    SDADC_RES_SetResistorSelChan(BasePtr, 0U, 0U);

    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    SDADC_CH_WRAP_SetChannelDefault(BasePtr, 6U, 0U);

    SDADC_GAINCORR_SetCorrection(BasePtr, 0U, 0U);

    SDADC_GAINCAL_SetMultiFactor(BasePtr, 0x1000U);

    SDADC_FCFGC_SetCICFilterDecFactor(BasePtr, cicFilterDecimationFactor);

    SDADC_FCFGC_SetCICFilterStartVal(BasePtr, 7U);

    SDADC_FCNTC_SetCICFilterDecCounter(BasePtr, cicFilterDecimationFactor);

    SDADC_OFFCOMP_SetOffsetVal(BasePtr, 0U);

    SDADC_FCFGM_SetFIR0FilterEnDis(BasePtr, fir0State);

    SDADC_FCFGM_SetFIR1FilterEnDis(BasePtr, fir1State);

    SDADC_FCFGM_SetOvershootCompenEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetFIR1FilterDecRate(BasePtr, 0U);

    SDADC_FCFGM_SetCICFilterMode(BasePtr, 0U);

    SDADC_FCFGM_SetPrefilterEnDis(BasePtr, preFilterState);

    SDADC_FCFGM_SetBoundaryComparatorEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetExtMeshClkEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, 0U);

    SDADC_FCFGM_SetChannelWraparoundEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetDifferenceEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetCalibEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetDMAReqEnDis(BasePtr, FALSE);

    SDADC_FCFG_SetFifoSize(BasePtr, 0x40U);

    SDADC_FCFG_SetFifoWaterMarkerVal(BasePtr, 0x1U);    //dq 

    SDADC_FCFG_SetInfoEnDis(BasePtr, FALSE);

    SDADC_FCFG_SetSignEnDis(BasePtr, FALSE);

    SDADC_FCDIS_SetFilterChainDiscardEnDis(BasePtr, TRUE);

    SDADC_FCDIS_SetFilterChainDiscardNum(BasePtr, 0x10U);   //dq

    SDADC_CTRL_SetSdadcEnDis(BasePtr, TRUE);

    /*GAIN_CAL_P*/
    while(gain_sft_mask != (uint32)0U)
	{
    	SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);

		SDADC_GAINCORR_SetCorrection(BasePtr, (uint16)gain_corr_p, cicFilterOutputShifter);

		SDADC_STCFG_SetSoftTrigEn(BasePtr);

        Sdadc_Timeout = 0U;

		while((SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) == 0U) && (Sdadc_Timeout < DEFAULT_TIMEOUT))
		{
			Sdadc_Timeout++;
		}

		hard_data = SDADC_FDATA_GetFifoData(BasePtr);

	    hard_data = hard_data & 0x0000FFFFU;

	    SDADC_STCFG_ClearSoftTrig(BasePtr);

		// delay(0x200U);   //dq

		SDADC_STCFG_SetFifoSoftReset(BasePtr);

		if(hard_data > 0x0007000U)
		{
			gain_corr_p = (gain_corr_p & (~gain_sft_mask)) | (gain_sft_mask >> 1);

		}
		else
		{
			gain_corr_p = gain_corr_p + (gain_sft_mask >> 1);
		}

		gain_sft_mask = gain_sft_mask >> 1;
	}

    /*GAIN_CAL_N*/
	gain_sft_mask = 0x1000U;

    SDADC_CH_WRAP_SetChannelDefault(BasePtr, 7U, 0U);

	while(gain_sft_mask != (uint32)0U)
	{
    	SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);

		SDADC_GAINCORR_SetCorrection(BasePtr, (uint16)gain_corr_n, cicFilterOutputShifter);

		SDADC_STCFG_SetSoftTrigEn(BasePtr);

		Sdadc_Timeout = 0U;

		while((SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) == 0U) && (Sdadc_Timeout < DEFAULT_TIMEOUT))
		{
			Sdadc_Timeout++;
		}

		hard_data = SDADC_FDATA_GetFifoData(BasePtr);

	    hard_data = hard_data & 0x0000FFFFU;

	    SDADC_STCFG_ClearSoftTrig(BasePtr);

		// delay(0x200U);   //dq

		SDADC_STCFG_SetFifoSoftReset(BasePtr);

		if(hard_data < 0x0009000U)
		{
			gain_corr_n = (gain_corr_n & (~gain_sft_mask)) | (gain_sft_mask >> 1);
		}
		else
		{
			gain_corr_n = gain_corr_n + (gain_sft_mask >> 1);
		}

		gain_sft_mask = gain_sft_mask >> 1;
	}

	gain_corr = (gain_corr_p + gain_corr_n ) >> 1;

	return gain_corr ;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
static FUNC(uint32, SDADC_CODE) SDADC_LLD_CalculateOffset(CONST(Sdadc_InstanceType, SDADC_CONST) instance, VAR(uint32, SDADC_VAR) gainVal, P2CONST(Sdadc_OsrParameterType, AUTOMATIC, SDADC_APPL_CONST) pSdadc_OsrPara)
{
    VAR(uint32, SDADC_VAR) Sdadc_Timeout1 = 0U;
    VAR(uint32, SDADC_VAR) Sdadc_Timeout2 = 0U;

    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(uint32, SDADC_VAR) attValue;

    VAR(uint8, SDADC_VAR) attVcomSelValue, attClkDivValue;

	VAR(uint32, SDADC_VAR) offcmp_n1 = 0;

	VAR(uint16, SDADC_VAR) off_data;

	VAR(uint16, SDADC_VAR) abs_res;

    VAR(uint16, SDADC_VAR) cicFilterDecimationFactor = 0;
    VAR(uint8, SDADC_VAR) cicFilterOutputShifter = 0;
    VAR(boolean, SDADC_VAR) fir0State = TRUE, fir1State = TRUE, preFilterState = TRUE;

    cicFilterDecimationFactor = pSdadc_OsrPara->OsrCicFilterDecimationFactor;
    cicFilterOutputShifter = pSdadc_OsrPara->OsrFilterOutputShifter;
    fir0State = pSdadc_OsrPara->OsrFir0State;
    fir1State = pSdadc_OsrPara->OsrFir1State;
    preFilterState = pSdadc_OsrPara->OsrPreFilterState;

    attValue = SDADC_ATT_GetAnalogModuleCfg(BasePtr);

    attClkDivValue = (uint8)((attValue & SDADC_ATT_ADC_DIV_LV_MASK) >> SDADC_ATT_ADC_DIV_LV_SHIFT);

    attVcomSelValue = (uint8)((attValue & SDADC_ATT_VCOM_SEL_LV_MASK) >> SDADC_ATT_VCOM_SEL_LV_SHIFT);

    SDADC_ATT_SetAnalogModuleCfg(BasePtr, 1U, attVcomSelValue, attClkDivValue);

    SDADC_RES_SetResistorSelChan(BasePtr, 0U, 0U);

    /*Step 1*/
    SDADC_CTRL_SetSdadcEnDis(BasePtr, FALSE);

    SDADC_CTRL_SetSdadcEnDis(BasePtr, TRUE);

    /*Step 2*/
    SDADC_CH_WRAP_SetChannelDefault(BasePtr, 5U, 0U);

    delay(0x200U);

    SDADC_GAINCORR_SetCorrection(BasePtr, (uint16)gainVal, cicFilterOutputShifter);

    SDADC_FCNTC_SetCICFilterDecCounter(BasePtr, cicFilterDecimationFactor);

    SDADC_GAINCAL_SetMultiFactor(BasePtr, 0x1000U);

    SDADC_FCFGC_SetCICFilterDecFactor(BasePtr, cicFilterDecimationFactor);

    SDADC_FCFGC_SetCICFilterStartVal(BasePtr, 6U);

    SDADC_FCFGM_SetFIR0FilterEnDis(BasePtr, fir0State);

    SDADC_FCFGM_SetFIR1FilterEnDis(BasePtr, fir1State);

    SDADC_FCFGM_SetOvershootCompenEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetFIR1FilterDecRate(BasePtr, 0U);

    SDADC_FCFGM_SetCICFilterMode(BasePtr, 0U);

    SDADC_FCFGM_SetPrefilterEnDis(BasePtr, preFilterState);

    SDADC_FCFGM_SetBoundaryComparatorEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetExtMeshClkEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetOffsetCompenFilterEn(BasePtr, 0x4U);

    SDADC_FCFGM_SetChannelWraparoundEnDis(BasePtr, FALSE);

    SDADC_FCFGM_SetDifferenceEnDis(BasePtr, TRUE);

    SDADC_FCFGM_SetCalibEnDis(BasePtr, FALSE);

    SDADC_OFFCOMP_SetOffsetVal(BasePtr, 0U);

    SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, TRUE);

    SDADC_IECFG_SetDMAReqEnDis(BasePtr, FALSE);

    SDADC_FCFG_SetFifoSize(BasePtr, 0x40U);

    SDADC_FCFG_SetFifoWaterMarkerVal(BasePtr, 0x8U);

    SDADC_FCDIS_SetFilterChainDiscardEnDis(BasePtr, TRUE);

    SDADC_FCDIS_SetFilterChainDiscardNum(BasePtr, 0xFFU);

    /*Step 3*/
	SDADC_STCFG_SetSoftTrigEn(BasePtr);

    delay(0x200U);
    
    Sdadc_Timeout1 = 0U;
    /*Step 4*/
	while(Sdadc_Timeout1 < DEFAULT_TIMEOUT)
	{
		Sdadc_Timeout1++;
		Sdadc_Timeout2 = 0U;

		while((SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) == FALSE)  && (Sdadc_Timeout2 < DEFAULT_TIMEOUT))
		{
            Sdadc_Timeout2++;
		}

		(void)SDADC_FDATA_GetFifoData(BasePtr);

	    /*Step 5*/
		off_data = (uint16)(SDADC_OFFCOMP_GetOffsetVal(BasePtr) & 0x0000FFFFU) ;
		if(((sint32)offcmp_n1 - (sint32)off_data) > (sint32)0U)
		{
			abs_res = (sint32)offcmp_n1 - (sint32)off_data;
		}
		else
		{
			abs_res = (sint32)off_data - (sint32)offcmp_n1;
		}
		
		if(abs_res > (sint32)0x03U)
		{
	    	SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
			offcmp_n1 = off_data;

		}
		else
		{
			break;
		}
	}

	return off_data;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(uint32, SDADC_CODE) SDADC_LLD_GetFifoData(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;
    if(instance_l >= SDADC_MAX_INSTANCE)
    {
        return 0;
    }
    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];
    return SDADC_FDATA_GetFifoData(BasePtr);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_SetSoftTrigger(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];/* polyspace RTE:OBAI */

	SDADC_STCFG_SetSoftTrigEn(BasePtr);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(boolean, SDADC_CODE) SDADC_LLD_GetWaterMarkerIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(boolean, SDADC_VAR) ret;

    ret = (SDADC_WMINTSTAT_GetWaterMarkerIntState(BasePtr) != 0U) ? (boolean)TRUE : (boolean)FALSE;

    return ret;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_ClearWaterMarkerIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_WMINTSTAT_ClearWaterMarkerIntState(BasePtr);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(boolean, SDADC_CODE) SDADC_LLD_GetDataOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(boolean, SDADC_VAR) ret;

    ret = (SDADC_OVINTSTAT_GetDataOverFlowIntState(BasePtr) != 0U) ? (boolean)TRUE : (boolean)FALSE;

    return ret;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_ClearDataOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_OVINTSTAT_ClearDataOverFlowIntState(BasePtr);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(boolean, SDADC_CODE) SDADC_LLD_GetFifoOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    VAR(boolean, SDADC_VAR) ret;

    ret = (SDADC_OVINTSTAT_GetFifoOverFlowIntState(BasePtr) != 0U) ? (boolean)TRUE : (boolean)FALSE;

    return ret;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_ClearFifoOverFlowIntState(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    SDADC_OVINTSTAT_ClearFifoOverFlowIntState(BasePtr);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_SetInterruptState(CONST(Sdadc_InstanceType, SDADC_CONST) instance, VAR(Sdadc_InterruptType, SDADC_VAR) intType, VAR(boolean, SDADC_VAR) intState)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    if(SDADC_INT_WATERMARKER == intType)
    {
        SDADC_IECFG_SetFifoWaterMarkerIntEnDis(BasePtr, intState);
    }
    else if(SDADC_INT_DATAOVERRUN == intType)
    {
    	SDADC_IECFG_SetDataOverFlowIntEnDis(BasePtr, intState);
    }
    else if(SDADC_INT_FIFOOVERRUN == intType)
    {
    	SDADC_IECFG_SetFifoOverFlowIntEnDis(BasePtr, intState);
    }
    else
    {
        /*Null*/
    }
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(void, SDADC_CODE) SDADC_LLD_ResetFifo(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));

    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];/* polyspace RTE:OBAI */

    SDADC_STCFG_SetFifoSoftReset(BasePtr);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(uint32, SDADC_CODE) SDADC_LLD_GetRecentAccumulation(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    return SDADC_IIVAL_GetInterIntegrationVal(BasePtr);
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"

#define SDADC_START_SEC_CODE
#include "SDAdc_MemMap.h"
FUNC(boolean, SDADC_CODE) SDADC_LLD_GetIntegrationEnable(CONST(Sdadc_InstanceType, SDADC_CONST) instance)
{
    DEV_ASSERT(((uint8)instance < SDADC_MAX_INSTANCE));
    VAR(Sdadc_InstanceType, SDADC_VAR) instance_l = instance;

    CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase[(uint8)instance_l];

    return ( SDADC_ISTAT_GetIntegrationEn(BasePtr) != 0U) ? (boolean)TRUE : (boolean)FALSE;
}
#define SDADC_STOP_SEC_CODE
#include "SDAdc_MemMap.h"
#endif /*RESOURCE_SUPPORT_SDADC_IP*/

#ifdef __cplusplus
}
#endif
