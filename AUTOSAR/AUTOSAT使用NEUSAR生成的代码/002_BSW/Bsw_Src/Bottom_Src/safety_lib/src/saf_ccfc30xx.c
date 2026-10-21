/**
****************************************************************************************
 * @FilePath: saf_ccfc3007pt.c
 * @Author: CCORE
 * @Date: 2024-02-28
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: ccfc3007 Source File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cpu.h"/*PRQA S 0380*/
#include "mcu_lld.h"
#include "saf_ccfc30xx.h"
#include "Saf_MemMap.h"

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/


/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/
/**
* @brief This function is used for read after write assert.
*/
SAF_MCU_SEC_CODE
void SAF_ReadAfterWriteAssert(uint32_t exprA, uint32_t exprB, const char* file, unsigned int line)
{
    if (exprA != exprB)
    {

    }

    (void)exprA;/*PRQA S 3119*/
    (void)exprB;/*PRQA S 3119*/
    (void)file;/*PRQA S 3119*/
    (void)line;/*PRQA S 3119*/
}

/**
* @brief This function is used for read back compare.
*/
SAF_MCU_SEC_CODE
FS_STATUS SAF_ReadBackCompare(uint32_t cmpValA, uint32_t cmpValB, uint32_t cmpMask)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if((cmpValA & cmpMask) == (cmpValB & cmpMask))
    {
        status = FS_STATUS_SUCCESS;
    }

    return status;
}


/**
****************************************************************************************
* @brief: This function is used to get system clock source.
* @param[in] clkName clock type name
* @return clock source type
****************************************************************************************
*/
SAF_MCU_SEC_CODE
SAF_CLOCK_SOURCE_TYPE SAF_MCU_ClkGetClkSrc(const SAF_CLOCK_NAME clkName)
{
    uint32_t regValue = 0;
    SAF_CLOCK_SOURCE_TYPE clkType = SAF_CLOCK_SOURCE_IS_INVALID;

    switch(clkName)
    {
        case SAF_SYSTEM_CLK:
        case SAF_PCS_SYS_CLK:
        {
            regValue = (MC_CGM.SC_SS.R & MC_CGM_SC_SS_SELSTAT_MASK) >> MC_CGM_SC_SS_SELSTAT_SHIFT;/*PRQA S 1841,4542*/
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_IRCOSC == regValue) ? SAF_CLOCK_SOURCE_IS_IRCOSC : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_XOSC == regValue) ? SAF_CLOCK_SOURCE_IS_XOSC : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_NON_FMPLL == regValue) ? SAF_CLOCK_SOURCE_IS_NON_FMPLL : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_FMPLL == regValue) ? SAF_CLOCK_SOURCE_IS_FMPLL : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_DISABLED == regValue) ? SAF_CLOCK_SOURCE_IS_DISABLED : clkType;
            break;
        }
        case SAF_PERIPHERAL_CLK:
        {
            regValue = (MC_CGM.AC0_SC.R & SAF_MC_CGM_AC0_SC_SELCTL_MASK) >> SAF_MC_CGM_AC0_SC_SELCTL_SHIFT;

            clkType = (SAF_OSC_CLOCK_SOURCE_IS_IRCOSC == regValue) ? SAF_CLOCK_SOURCE_IS_IRCOSC : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_XOSC == regValue) ? SAF_CLOCK_SOURCE_IS_XOSC : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_NON_FMPLL == regValue) ? SAF_CLOCK_SOURCE_IS_NON_FMPLL : clkType;
            break;
        }
        case SAF_MCAN_0:
        case SAF_MCAN_1:
        case SAF_MCAN_2:
        case SAF_MCAN_3:
        case SAF_MCAN_4:
        case SAF_MCAN_5:
        case SAF_MCAN_6:
        case SAF_MCAN_7:
        case SAF_MCAN_8:
        case SAF_MCAN_9:
        case SAF_MCAN_10:
        case SAF_MCAN_11:
        {
            regValue = ((MC_CGM.AC8_SC.R & MC_CGM_AC8_SC_SELSTAT_MASK) >> MC_CGM_AC8_SC_SELCTL_SHIFT_SAF);/*PRQA S 1841,4542*/
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_IRCOSC == regValue) ? SAF_CLOCK_SOURCE_IS_IRCOSC : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_XOSC == regValue) ? SAF_CLOCK_SOURCE_IS_XOSC : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_NON_FMPLL == regValue) ? SAF_CLOCK_SOURCE_IS_NON_FMPLL : clkType;
            break;
        }
        case SAF_NON_FMPLL_CLK:
        {
            regValue = ((MC_CGM.AC3_SC.R & MC_CGM_AC3_SC_SELSTAT_MASK) >> MC_CGM_AC3_SC_SELCTL_SHIFT);/*PRQA S 1841,4542*/

            clkType = (SAF_OSC_CLOCK_SOURCE_IS_IRCOSC == regValue) ? SAF_CLOCK_SOURCE_IS_IRCOSC : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_XOSC == regValue) ? SAF_CLOCK_SOURCE_IS_XOSC : clkType;
            break;
        }
        case SAF_FMPLL_CLK:
        {
            regValue = ((MC_CGM.AC4_SC.R & MC_CGM_AC4_SC_SELSTAT_MASK) >> MC_CGM_AC4_SC_SELCTL_SHIFT);/*PRQA S 1841,4542*/

            clkType = (SAF_OSC_CLOCK_SOURCE_IS_IRCOSC == regValue) ? SAF_CLOCK_SOURCE_IS_IRCOSC : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_XOSC == regValue) ? SAF_CLOCK_SOURCE_IS_XOSC : clkType;
            clkType = (SAF_OSC_CLOCK_SOURCE_IS_NON_FMPLL == regValue) ? SAF_CLOCK_SOURCE_IS_NON_FMPLL : clkType;

            break;
        }
        default:/*PRQA S 2016*/
        {
            break;
        }
    }

    return clkType;
}

/**
****************************************************************************************
* @brief: This function is used to check if the XOSC is stable.
* @param[in] void
* @return status:
        true: the XOSC is stable.
        false: the XOSC is not stable.
****************************************************************************************
*/
SAF_MCU_SEC_CODE
bool SAF_MCU_OscXoscIsStable(void)
{
    return (bool)( 1U == ((MC_ME.GS.R & SAF_MC_ME_GS_S_XOSC_MASK) >> SAF_MC_ME_GS_S_XOSC_SHIFT));/*PRQA S 4304*/
}

/**
****************************************************************************************
* @brief: This function is used to delay.
* @param[in] void
* @return status: void
****************************************************************************************
*/
SAF_MCU_SEC_CODE
void saf_delay(volatile uint32_t x)
{
    volatile uint32_t x_temp = x;
    while (x_temp != 0u)
    {
        x_temp--;
    }
}
#ifdef __cplusplus
}
#endif

