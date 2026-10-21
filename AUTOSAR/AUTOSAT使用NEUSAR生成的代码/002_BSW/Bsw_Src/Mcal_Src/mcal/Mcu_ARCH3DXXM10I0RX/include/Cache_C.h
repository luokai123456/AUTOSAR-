#ifndef CACHE_C_H
#define CACHE_C_H

/*PRQA S 3406,1820,1840 EOF*/

/*******************************************************************************
 * @brief    [local_static] Enable or disable the ICACHE
 * @param[in]  uint32 u32Mcu_Switch_val
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Switch_ICache(VAR(uint32, AUTOMATIC) u32Mcu_Switch_val)
{
    VAR(Z7_SPR_L1CSR1_tag, MCU_VAR) Z7_SPR_L1CSR1;
    VAR(Mcu_CoreType, MCU_VAR) eMcu_CoreId = Mcu_LLD_Get_Core_Id();
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;

    #if ((MCU_HARDVER == 5))
    if(eMcu_CoreId < 6U)
    #elif((MCU_HARDVER == 7))
    if(eMcu_CoreId < 4U)
    #else
    if(eMcu_CoreId < 3U)
    #endif
    {
        Z7_SPR_L1CSR1.R = MFSPR(SPR_L1CSR1); /* READ L1CSR1 */
        Z7_SPR_L1CSR1.B.ICECE = u32Mcu_Switch_val;
        Z7_SPR_L1CSR1.B.ICE = u32Mcu_Switch_val;
        MTSPR(SPR_L1CSR1, Z7_SPR_L1CSR1.R); /* WRITE L1CSR1 */
    }
    else
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return (Std_ReturnType)Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Enable ICACHE
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Enable_ICache(void)
{
    return Mcu_LLD_Switch_ICache(TRUE);
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Disable ICACHE
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Disable_ICache(void)
{
    return Mcu_LLD_Switch_ICache(FALSE);
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Invalid ICACHE by u32Mcu_Set and u32Mcu_way
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Invalid_ICache_Set_Way(
    VAR(uint32, AUTOMATIC) u32Mcu_Set,
    VAR(uint32, AUTOMATIC) u32Mcu_way )
{
    VAR(uint32, MCU_VAR)Mcu_Timeout;
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    VAR(Z7_SPR_L1FINV1_tag, MCU_VAR) Z7_SPR_L1FINV1;
    VAR(Z7_SPR_L1CSR1_tag, MCU_VAR) Z7_SPR_L1CSR1;
    Mcu_CoreType eMcu_CoreId = Mcu_LLD_Get_Core_Id();

    #if ((MCU_HARDVER == 5))
    if(eMcu_CoreId < 6U)
    #else
    if(eMcu_CoreId < 3U)
    #endif
    {
        Z7_SPR_L1FINV1.R = MFSPR(SPR_L1FINV1); /* READ SPR_L1FINV1 */
        Z7_SPR_L1FINV1.B.CWAY = u32Mcu_way;
        Z7_SPR_L1FINV1.B.CSET = u32Mcu_Set;
        MTSPR(SPR_L1FINV1, Z7_SPR_L1FINV1.R);  /* WRITE SPR_L1FINV1 */
        Z7_SPR_L1CSR1.R = MFSPR(SPR_L1CSR1);   /* READ SPR_L1CSR1 */
        Z7_SPR_L1CSR1.B.ICINV = 1U;
        MTSPR(SPR_L1CSR1, Z7_SPR_L1CSR1.R);    /* WRITE Z7_SPR_L1CSR1 */
        Mcu_Timeout = 0U;
        do 
        {
            Z7_SPR_L1CSR1.R = MFSPR(SPR_L1CSR1); /* READ SPR_L1CSR1 */
        } while ((Z7_SPR_L1CSR1.B.ICINV == 1U) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS));
        if(Mcu_Timeout == MCU_TIMEOUT_LOOPS)
        {
            Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Invalid ICACHE by address and length
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Invalid_ICache (
    VAR(uint32, AUTOMATIC) u32Mcu_Base,
    VAR(uint32, AUTOMATIC) u32Mcu_Len )
{
    VAR(Std_ReturnType, MCU_VAR) u32Mcu_Ret = (Std_ReturnType)E_OK;
    VAR(uint32, MCU_VAR) u32Mcu_SetIdx = 0;
    VAR(uint32, MCU_VAR) u32Mcu_WayIdx = 0;
    VAR(uint32, MCU_VAR) u32Mcu_MaxAddr = u32Mcu_Base + u32Mcu_Len;
    VAR(Mcu_CoreType, MCU_VAR) eMcu_CoreId = Mcu_LLD_Get_Core_Id();;

    switch (eMcu_CoreId) 
    {
    case 0:
    case 1:
    {
        for (u32Mcu_SetIdx = u32Mcu_Base / Z7_ICACHE_LINE;u32Mcu_SetIdx
            < (((uint32)ALIGN_UP(u32Mcu_MaxAddr, Z7_ICACHE_LINE)) / Z7_ICACHE_LINE); u32Mcu_SetIdx++) /* polyspace RTE:OVFL */
        {
            for (u32Mcu_WayIdx = 0U; u32Mcu_WayIdx < Z7_ICACHE_WAY_NUM; u32Mcu_WayIdx++) 
            {
                u32Mcu_Ret |= \
                Mcu_LLD_Invalid_ICache_Set_Way(u32Mcu_SetIdx % Z7_ICACHE_SET_NUM, u32Mcu_WayIdx);
            }
        }
        break;
    }
    case 2:
    {
        for (u32Mcu_SetIdx = u32Mcu_Base / Z4_ICACHE_LINE;u32Mcu_SetIdx
            < (((uint32)ALIGN_UP(u32Mcu_MaxAddr, Z4_ICACHE_LINE)) / Z4_ICACHE_LINE); u32Mcu_SetIdx++) /* polyspace RTE:OVFL */
        {
            for (u32Mcu_WayIdx = 0U; u32Mcu_WayIdx < Z4_ICACHE_WAY_NUM; u32Mcu_WayIdx++) 
            {
                u32Mcu_Ret |= \
                Mcu_LLD_Invalid_ICache_Set_Way(u32Mcu_SetIdx % Z4_ICACHE_SET_NUM, u32Mcu_WayIdx);
            }
        }
        break;
    }
    default: 
    {
        u32Mcu_Ret = (Std_ReturnType)E_NOT_OK;
        break;
    }
    }

    return u32Mcu_Ret;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief    [local_static] Enable or disable the DCACHE
 * @param[in]  uint32 u32Mcu_Switch_val
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Switch_DCache ( VAR(uint32, AUTOMATIC) u32Mcu_Switch_val )
{
    VAR(Z7_SPR_L1CSR0_tag, MCU_VAR) Z7_SPR_L1CSR0;
    VAR(Mcu_CoreType, MCU_VAR) eMcu_CoreId = Mcu_LLD_Get_Core_Id();
    VAR(Std_ReturnType, MCU_VAR)Mcu_RetVal = (Std_ReturnType)E_OK;
    #if ((MCU_HARDVER == 5))
    if(eMcu_CoreId < 6U)
    #else
    if(eMcu_CoreId < 2U)
    #endif
    {
        Z7_SPR_L1CSR0.R = MFSPR(SPR_L1CSR0);
        Z7_SPR_L1CSR0.B.DCECE = u32Mcu_Switch_val;
        Z7_SPR_L1CSR0.B.DCE = u32Mcu_Switch_val;
        MTSPR(SPR_L1CSR0, Z7_SPR_L1CSR0.R);
    }
    else
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Enable DCACHE
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Enable_DCache(void)
{
    return Mcu_LLD_Switch_DCache(TRUE);
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Disable DCACHE
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Disable_DCache(void)
{
    return Mcu_LLD_Switch_DCache(FALSE);
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Invalid DCACHE by u32Mcu_Set and u32Mcu_way
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Invalid_DCache_Set_Way \
( \
    VAR(uint32, AUTOMATIC) u32Mcu_Set, \
    VAR(uint32, AUTOMATIC) u32Mcu_way \
)
{
    VAR(uint32, MCU_VAR)Mcu_Timeout;
    VAR(Z7_SPR_L1FINV0_tag, MCU_VAR) Z7_SPR_L1FINV0;
    VAR(Z7_SPR_L1CSR0_tag, MCU_VAR) Z7_SPR_L1CSR0;
    VAR(Mcu_CoreType, MCU_VAR) eMcu_CoreId = Mcu_LLD_Get_Core_Id();
    VAR(Std_ReturnType, MCU_VAR)Mcu_RetVal = (Std_ReturnType)E_OK;

    #if ((MCU_HARDVER == 5))
    if(eMcu_CoreId < 6U)
    #else
    if(eMcu_CoreId < 2U)
    #endif
    {
        Z7_SPR_L1FINV0.R = MFSPR(SPR_L1FINV1);
        Z7_SPR_L1FINV0.B.CWAY = u32Mcu_way;
        Z7_SPR_L1FINV0.B.CSET = u32Mcu_Set;
        MTSPR(SPR_L1FINV1, Z7_SPR_L1FINV0.R);
        Z7_SPR_L1CSR0.R = MFSPR(SPR_L1CSR1);
        Z7_SPR_L1CSR0.B.DCINV = 1U;
        MTSPR(SPR_L1CSR1, Z7_SPR_L1CSR0.R);
        Mcu_Timeout = 0U;
        do 
        {
            Z7_SPR_L1CSR0.R = MFSPR(SPR_L1CSR1);
            Mcu_Timeout++;
        } while ((Z7_SPR_L1CSR0.B.DCINV == 1U) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS));
        if(Mcu_Timeout == MCU_TIMEOUT_LOOPS)
        {
            Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Invalid ICACHE by address and length
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Invalid_DCache \
( \
    VAR(uint32, AUTOMATIC) u32Mcu_Base, \
    VAR(uint32, AUTOMATIC) u32Mcu_Len \
)
{
    VAR(uint32, MCU_VAR) u32Mcu_Ret = (Std_ReturnType)E_OK;
    VAR(uint32, MCU_VAR) u32Mcu_SetIdx = 0;
    VAR(uint32, MCU_VAR) u32Mcu_WayIdx = 0;
    VAR(uint32, MCU_VAR) u32Mcu_MaxAddr = u32Mcu_Base + u32Mcu_Len;
    VAR(Mcu_CoreType, MCU_VAR) eMcu_CoreId = Mcu_LLD_Get_Core_Id();

    switch (eMcu_CoreId) 
    {
        case 0:
        case 1:
        {
            for (u32Mcu_SetIdx = u32Mcu_Base / Z7_DCACHE_LINE;u32Mcu_SetIdx < ((uint32)ALIGN_UP(u32Mcu_MaxAddr, Z7_DCACHE_LINE) / Z7_DCACHE_LINE); u32Mcu_SetIdx++) /* polyspace RTE:OVFL */
            {
                for (u32Mcu_WayIdx = 0U; u32Mcu_WayIdx < Z7_DCACHE_WAY_NUM; u32Mcu_WayIdx++) 
                {
                    u32Mcu_Ret |= Mcu_LLD_Invalid_DCache_Set_Way(u32Mcu_SetIdx % Z7_DCACHE_SET_NUM, u32Mcu_WayIdx);
                }
            }
            break;
        }
        case 2:
        {
            u32Mcu_Ret =  (Std_ReturnType)E_NOT_OK;
            break;
        }
        default: 
        {
            u32Mcu_Ret =  (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return u32Mcu_Ret;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif
