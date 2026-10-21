/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     mcu_lld.c
* @version  3.0.0
* @date     2023 - 04 - 17
* @brief    Initial version.
*
*****************************************************************************/

#include "intc_lld.h" /* PRQA S 0380 */
#include "compiler_api.h"

/*******************************************************************************
 * @brief   Set the unified interrupt entry in software interrupt mode
 * @param[in]  register uint32_t prefix
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
void INTC_LLD_Set_Vector_Prefix(register uint32_t prefix) /* PRQA S 1503, 3206 # prefix is used in assemble */
{
    MTSPR(SPR_IVPR, prefix); /* PRQA S 1006 */
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief    Get the interrupt vector table
 * @param[in]  None
 * @param[out] None
 * @retval     Interrupt vector table address
 * @notapi
 *******************************************************************************/
INTC_START_SEC_VAR_NO_INIT
static uint32_t g_vector_table;
INTC_STOP_SEC_VAR_NO_INIT

INTC_START_SEC_CODE
static uint32_t INTC_LLD_Get_Vector_Table(void) /* PRQA S 1505, 1506 */
{
    return g_vector_table;
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief    Set the interrupt vector table
 * @param[in]  Interrupt vector table address
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
void INTC_LLD_Set_Vector_Table(uint32_t vector_table) /* PRQA S 1503 */
{
    Mcu_CoreType core_id = Mcu_LLD_Get_Core_Id();

    if (core_id < INTC_SUPPORT_CORE_NUM) 
    {
        INTC_0.IACKR[core_id].R = vector_table;
    }
    else
    {
#ifdef RESOURCE_SUPPORT_INTC_1
        INTC_1.IACKR[core_id - INTC_SUPPORT_CORE_NUM].R = vector_table;/* polyspace RTE:OBAI */
#endif
    }

    g_vector_table = vector_table;
}
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
void INTC_LLD_Reset_IRQ_Status(void)
{
    uint32_t intr_id;
    for(intr_id = 0U; intr_id < (uint32_t)INTR_ID_BUTT; intr_id++)
    {
#ifdef SAFETY_ENABLE
        if((intr_id != FCCU_0_IRQn) && (intr_id != FCCU_1_IRQn))
        {
#endif /* SAFETY_ENABLE */
            INTC_0.PSR[intr_id].R = 0x00000000U;
    #ifdef RESOURCE_SUPPORT_INTC_1
            INTC_1.PSR[intr_id].R = 0x00000000U;
    #endif
#ifdef SAFETY_ENABLE
        }
#endif /* SAFETY_ENABLE */
    }
}
INTC_STOP_SEC_CODE


/*******************************************************************************
 * @brief     Get the current interrupt vector number
 * @param[in]  None
 * @param[out] None
 * @retval     Current interrupt vector number
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
IntrId INTC_LLD_Get_Cur_IRQ_Id(void)
{
    INTC_IACKR_tag IACKR = {.R = 0}; /* PRQA S 3604 */
    uint32_t vector_base, vector_addr;
    Mcu_CoreType core_id = Mcu_LLD_Get_Core_Id();

    if (core_id < INTC_SUPPORT_CORE_NUM)
    {
        IACKR.R = INTC_0.IACKR[core_id].R;
    }
    else
    {
#ifdef RESOURCE_SUPPORT_INTC_1
        IACKR.R = INTC_1.IACKR[core_id - INTC_SUPPORT_CORE_NUM].R;/* polyspace RTE:OBAI */
#endif
    }

    vector_addr = IACKR.R;/* polyspace RTE:NIVL */
    vector_base = INTC_LLD_Get_Vector_Table();

    return (IntrId)(uint32_t)((vector_addr - vector_base) / sizeof(uint32_t)); /* PRQA S 4342 */
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief    [inner_static] Turn on or Turn off interrupts
 * @param[in]  IntrId intr_id, uint32_t switch_val(on or off)
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
static status_t INTC_LLD_Switch_IRQ(IntrId intr_id, uint32_t switch_val)
{
    Mcu_CoreType core_id = Mcu_LLD_Get_Core_Id();

    if (intr_id >= INTR_ID_BUTT) {
        return STATUS_MCU_INVALID_INTC_NUM;
    }
    if (core_id >= RESOURCE_CHIP_CORE_NUM) {
    	return STATUS_MCU_INVALID_CORE_ID;
    }
    switch (core_id) {
        case 0U: {
            INTC_0.PSR[intr_id].B.PRC_SELN0 = (uint16_t)switch_val;/* polyspace RTE:OBAI */
            break;
        }
        case 1U: {
            INTC_0.PSR[intr_id].B.PRC_SELN1 = (uint16_t)switch_val;/* polyspace RTE:OBAI */
            break;
        }
        case 2U: {
            INTC_0.PSR[intr_id].B.PRC_SELN2 = (uint16_t)switch_val;/* polyspace RTE:OBAI */
            break;
        }
        case 3U: {
            INTC_0.PSR[intr_id].B.PRC_SELN3 = (uint16_t)switch_val;/* polyspace RTE:OBAI */
            break;
        }
#ifdef RESOURCE_SUPPORT_INTC_1
        case 4U: {
            INTC_1.PSR[intr_id].B.PRC_SELN0 = (uint16_t)switch_val;/* polyspace RTE:OBAI */
            break;
        }
        case 5U: {
            INTC_1.PSR[intr_id].B.PRC_SELN1 = (uint16_t)switch_val;/* polyspace RTE:OBAI */
            break;
        }
#endif
        default: { /* PRQA S 2024, 2881 */
        	return STATUS_MCU_INVALID_CORE_ID; /* PRQA S 2880 */
        }
    }
    return STATUS_SUCCESS;
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief     Set the specified interrupt to disable
 * @param[in]  IntrId intr_id
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
status_t INTC_LLD_Set_IRQ_Disable(IntrId intr_id)
{
    return INTC_LLD_Switch_IRQ(intr_id, OFF);
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief     Set the specified interrupt to enable
 * @param[in]  IntrId intr_id
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
status_t INTC_LLD_Set_IRQ_Enable(IntrId intr_id)
{
    return INTC_LLD_Switch_IRQ(intr_id, ON);
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief      Set global interrupt to disable
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
void INTC_LLD_Set_Global_Disable(void)
{
    PPCASM ("wrteei 0"); /* PRQA S 1006 */
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief      Set global interrupt to enable
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
void INTC_LLD_Set_Global_Enable(void)
{
    PPCASM ("wrteei 1"); /* PRQA S 1006 */
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief      Set the specified interrupt priority
 * @param[in]  IntrId intr_id, IntrPrior intr_prior
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
status_t INTC_LLD_Set_IRQ_Priority(IntrId intr_id, IntrPrior intr_prior)
{
	Mcu_CoreType core_id = Mcu_LLD_Get_Core_Id();

    if (intr_id >= INTR_ID_BUTT) {
        return STATUS_MCU_INVALID_INTC_NUM;
    }

    if (intr_prior > INTR_PRI_BUTT) {
        return STATUS_MCU_INVALID_PRIOR_NUM;
    }

    if (core_id < INTC_SUPPORT_CORE_NUM) {
        INTC_0.PSR[intr_id].B.PRIN = (uint32_t)intr_prior;/* polyspace RTE:OBAI */
    } else {
#ifdef RESOURCE_SUPPORT_INTC_1
        INTC_1.PSR[intr_id].B.PRIN = (uint32_t)intr_prior;/* polyspace RTE:OBAI */
#endif
    }

    return STATUS_SUCCESS;
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief      Set the global interrupt priority
 * @param[in]  IntrId intr_id
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
status_t INTC_LLD_Set_Global_Priority(IntrPrior intr_prior)
{
    Mcu_CoreType core_id = Mcu_LLD_Get_Core_Id();

    if (intr_prior > INTR_PRI_BUTT) {
        return STATUS_MCU_INVALID_PRIOR_NUM;
    }

    if (core_id < INTC_SUPPORT_CORE_NUM) {
        INTC_0.CPR[core_id].B.PRI = (uint32_t)intr_prior;
    } else {
#ifdef RESOURCE_SUPPORT_INTC_1
        INTC_1.CPR[core_id - INTC_SUPPORT_CORE_NUM].B.PRI = (uint32_t)intr_prior;/* polyspace RTE:OBAI */
#endif
    }

    return STATUS_SUCCESS;
}
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Set_Soft_IRQ(uint8_t instance, IntrId intr_id)
{
    if (intr_id > SOFT_SET_31_IRQn) {
        return STATUS_MCU_INVALID_INTC_NUM;
    }

    if (0u == instance)
    {
        INTC_0.SSCIR[(uint32_t)intr_id].B.SET = 1U;/* polyspace RTE:IDP,OBAI */
    }
#ifdef RESOURCE_SUPPORT_INTC_1
    else if (1u == instance)
    {
        INTC_1.SSCIR[(uint32_t)intr_id].B.SET = 1U;/* polyspace RTE:IDP,OBAI */
    }
#endif
    else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Clr_Soft_IRQ(uint8_t instance, IntrId intr_id)
{
    if (intr_id > SOFT_SET_31_IRQn) {
        return STATUS_MCU_INVALID_INTC_NUM;
    }

    if (0u == instance)
    {
        INTC_0.SSCIR[(uint32_t)intr_id].B.CLR = 1U;/* polyspace RTE:IDP,OBAI */
    }
#ifdef RESOURCE_SUPPORT_INTC_1
    else if (1u == instance)
    {
        INTC_1.SSCIR[(uint32_t)intr_id].B.CLR = 1U;/* polyspace RTE:IDP,OBAI */
    }
#endif
    else
    {
        return STATUS_ERROR;
    }

    return STATUS_SUCCESS;
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief      Set the specified interrupt callback
 * @param[in]  IntrId intr_id, IntrHandle intr_handle
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
status_t INTC_LLD_Set_IRQ_Handle(IntrId intr_id, IntrHandle intr_handle)
{
    uint32_t vector_base = INTC_LLD_Get_Vector_Table();

    if (intr_id > INTR_ID_BUTT) {
        return STATUS_MCU_INVALID_INTC_NUM;
    }

    *((IntrHandle *)vector_base + (uint32_t)intr_id) = intr_handle;/* polyspace RTE:IDP*/ /* PRQA S 0488 */

    return STATUS_SUCCESS;
}
INTC_STOP_SEC_CODE

/*******************************************************************************
 * @brief      Switch interrupt handle mode
 * @param[in]  IntcMode intc_mode
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
INTC_START_SEC_CODE
status_t INTC_LLD_Swtich_Mode(IntcMode intc_mode) /* PRQA S 1503 */
{
    INTC_BCR_tag INTC_BCR;
    Mcu_CoreType core_id = Mcu_LLD_Get_Core_Id();

    if (core_id >= RESOURCE_CHIP_CORE_NUM) {
        return STATUS_MCU_INVALID_CORE_ID;
    }

    if (intc_mode >= INTC_MODE_BNUTT) {
        return STATUS_MCU_INVALID_INTC_MODE;
    }

    switch (core_id) {
        case 0U: {
            INTC_BCR.R = INTC_0.BCR.R;
            INTC_BCR.B.HVEN0 = (uint32_t)intc_mode;
            INTC_0.BCR.R = INTC_BCR.R;
            break;
        }
        case 1U: {
            INTC_BCR.R = INTC_0.BCR.R;
            INTC_BCR.B.HVEN1 = (uint32_t)intc_mode;
            INTC_0.BCR.R = INTC_BCR.R;
            break;
        }
        case 2U: {
            INTC_BCR.R = INTC_0.BCR.R;
            INTC_BCR.B.HVEN2 = (uint32_t)intc_mode;
            INTC_0.BCR.R = INTC_BCR.R;
            break;
        }
        case 3U: {
            INTC_BCR.R = INTC_0.BCR.R;
            INTC_BCR.B.HVEN3 = (uint32_t)intc_mode;
            INTC_0.BCR.R = INTC_BCR.R;
            break;
        }
#ifdef RESOURCE_SUPPORT_INTC_1
        case 4U: {
            INTC_BCR.R = INTC_1.BCR.R;
            INTC_BCR.B.HVEN0 = (uint32_t)intc_mode;
            INTC_1.BCR.R = INTC_BCR.R;
            break;
        }
        case 5U: {
            INTC_BCR.R = INTC_1.BCR.R;
            INTC_BCR.B.HVEN1 = (uint32_t)intc_mode;
            INTC_1.BCR.R = INTC_BCR.R;
            break;
        }
#endif
        default: { /* PRQA S 2024, 2881 */
            return STATUS_MCU_INVALID_CORE_ID; /* PRQA S 2880 */
        }
    }

    return STATUS_SUCCESS;
}
INTC_STOP_SEC_CODE
