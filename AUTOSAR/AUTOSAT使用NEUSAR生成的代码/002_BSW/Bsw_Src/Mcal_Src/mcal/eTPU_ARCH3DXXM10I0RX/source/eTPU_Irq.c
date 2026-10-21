/****************************************************************************
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETPU
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/
/* PRQA S 0380 EOF */
/**
*   @file    eTPU_Irq.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of ETPU MCAL driver.
*
*   @addtogroup ETPU
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "Qom.h" 
#include "QOM_LLDrivers.h"
#include "eTPU_LLDrivers.h"
#include "eTPU_Irq.h"
#include "Pwm_Irq.h"

#define ETPU_IRQ_C_VENDOR_ID                      176
#define ETPU_IRQ_C_AR_REL_MAJOR_VER               4
#define ETPU_IRQ_C_AR_REL_MINOR_VER               4
#define ETPU_IRQ_C_AR_REL_REV_VER                 0
#define ETPU_IRQ_C_SW_MAJOR_VER                   3
#define ETPU_IRQ_C_SW_MINOR_VER                   0
#define ETPU_IRQ_C_SW_PATCH_VER                   0

#if (ETPU_IRQ_C_VENDOR_ID != ETPU_VENDOR_ID_OUTPUT)
    #error " NON-MATCHED DATA : ETPU_IRQ_C_VENDOR_ID "
#endif
#if (ETPU_IRQ_C_AR_REL_MAJOR_VER != ETPU_AR_REL_MAJOR_VER_OUTPUT)
    #error " NON-MATCHED DATA : ETPU_IRQ_C_AR_REL_MAJOR_VER "
#endif
#if (ETPU_IRQ_C_AR_REL_MINOR_VER != ETPU_AR_REL_MINOR_VER_OUTPUT)
    #error " NON-MATCHED DATA : ETPU_IRQ_C_AR_REL_MINOR_VER "
#endif
#if (ETPU_IRQ_C_AR_REL_REV_VER != ETPU_AR_REL_REVISION_VER_OUTPUT)
    #error " NON-MATCHED DATA : ETPU_IRQ_C_AR_REL_REV_VER "
#endif
#if (ETPU_IRQ_C_SW_MAJOR_VER != ETPU_SW_MAJOR_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : ETPU_IRQ_C_SW_MAJOR_VER "
#endif
#if (ETPU_IRQ_C_SW_MINOR_VER != ETPU_SW_MINOR_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : ETPU_IRQ_C_SW_MINOR_VER "
#endif
#if (ETPU_IRQ_C_SW_PATCH_VER != ETPU_SW_PATCH_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : ETPU_IRQ_C_SW_PATCH_VER "
#endif

#if ((ETPU_QOM_INSTANCE_NUM != 0U)&&(QOM_MODULE_ENABLE !=STD_OFF))
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_0_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,0);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_1_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,1);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_2_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,2);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_3_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,3);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_4_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,4);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_5_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,5);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_6_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,6);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_7_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,7);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_8_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,8);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_9_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,9);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_10_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,10);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_11_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,11);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_12_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,12);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_13_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,13);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_14_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,14);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_15_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,15);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_16_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,16);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_17_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,17);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_18_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,18);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_19_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,19);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_20_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,20);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_21_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,21);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_22_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,22);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_23_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,23);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_24_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,24);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_25_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,25);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_26_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,26);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_27_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,27);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_28_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,28);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_29_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,29);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_30_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,30);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_31_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,31);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_0_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,64);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_1_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,65);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_2_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,66);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_3_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,67);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_4_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,68);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_5_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,69);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_6_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,70);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_7_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,71);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_8_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,72);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_9_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,73);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_10_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,74);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_11_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,75);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_12_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,76);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_13_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,77);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_14_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,78);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_15_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,79);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_16_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,80);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_17_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,81);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_18_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,82);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_19_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,83);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_20_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,84);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_21_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,85);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_22_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,86);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_23_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,87);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_24_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,88);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_25_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,89);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_26_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,90);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_27_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,91);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_28_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,92);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_29_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,93);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_30_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,94);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_31_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_A_B,95);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_0_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,0);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_1_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,1);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_2_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,2);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_3_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,3);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_4_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,4);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_5_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,5);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_6_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,6);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_7_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,7);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_8_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,8);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_9_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,9);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_10_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,10);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_11_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,11);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_12_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,12);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_13_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,13);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_14_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,14);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_15_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,15);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_16_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,16);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_17_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,17);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_18_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,18);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_19_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,19);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_20_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,20);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_21_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,21);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_22_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,22);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_23_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,23);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_24_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,24);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_25_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,25);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_26_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,26);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_27_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,27);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_28_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,28);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_29_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,29);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_30_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,30);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_31_Qom_IRQ_Handle (void)
{
    Etpu_Qom_isr_handle(ETPU_INSTANCE_C,31);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_0_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,0);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_1_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,0);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_2_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,2);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_3_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,3);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_4_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,4);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_5_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,5);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_6_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,6);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_7_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,7);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_8_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,8);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_9_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,9);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_10_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,10);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_11_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,11);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_12_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,12);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_13_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,13);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_14_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,14);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_15_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,15);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_16_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,16);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_17_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,17);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_18_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,18);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_19_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,19);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_20_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,20);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_21_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,21);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_22_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,22);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_23_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,23);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_24_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,24);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_25_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,25);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_26_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,26);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_27_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,27);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_28_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,28);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_29_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,29);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_30_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,30);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu0_31_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,31);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_0_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,64);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_1_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,65);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_2_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,66);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_3_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,67);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_4_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,68);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_5_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,69);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_6_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,70);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_7_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,71);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_8_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,72);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_9_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,73);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_10_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,74);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_11_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,75);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_12_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,76);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_13_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,77);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_14_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,78);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_15_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,79);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_16_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,80);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_17_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,81);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_18_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,82);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_19_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,83);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_20_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,84);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_21_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,85);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_22_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,86);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_23_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,87);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_24_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,88);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_25_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,89);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_26_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,90);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_27_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,91);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_28_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,92);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_29_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,93);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_30_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,94);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu1_31_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_A_B,95);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_0_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,0);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_1_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,1);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_2_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,2);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_3_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,3);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_4_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,4);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_5_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,5);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_6_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,6);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_7_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,7);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_8_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,8);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_9_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,9);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_10_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,10);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_11_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,11);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_12_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,12);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_13_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,13);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_14_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,14);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_15_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,15);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_16_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,16);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_17_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,17);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_18_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,18);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_19_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,19);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_20_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,20);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_21_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,21);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_22_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,22);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_23_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,23);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_24_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,24);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_25_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,25);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_26_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,26);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_27_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,27);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_28_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,28);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_29_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,29);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_30_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,30);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu2_31_Pwm_IRQ_Handle (void)
{
    Pwm_Etpu_isr_handle(ETPU_INSTANCE_C,31);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"


#if ((ETPU_QOM_INSTANCE_NUM != 0U)&&(QOM_MODULE_ENABLE !=STD_OFF))
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE)Etpu_Qom_isr_handle \
( \
    VAR(uint8, ETPU_VAR) u8Etpu_Group, \
    VAR(uint8, ETPU_VAR) u8Qom_ChaHardWareIdx \
)
{
    VAR(uint8, ETPU_VAR) u8Qom_State = 0U;
	u8Qom_State = fs_etpu_get_chan_interrupt_flag(u8Etpu_Group,u8Qom_ChaHardWareIdx);

    if(u8Qom_State == 1)
    {
    	VAR(uint8, ETPU_VAR) u8Qom_ChannelIdx = 0U;
    	VAR(uint8, ETPU_VAR) u8Qom_Index = 0U;
    	VAR(Qom_GetStaType, ETPU_VAR) Qom_Notify = NULL_PTR;
    	for(u8Qom_Index = 0U; u8Qom_Index < ETPU_QOM_INSTANCE_NUM; u8Qom_Index++)
    	{
    	    if(u8Etpu_Group == eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_Index].etpuGroup && \
    	        		u8Qom_ChaHardWareIdx == eTPU_QOM_ConfigPtr->Qom_ChannelConfigPtr[u8Qom_Index].channel)
    	        {
    	        	u8Qom_ChannelIdx = u8Qom_Index;
    	        }else{
    	            ;//do nothing
    	        }
    	}

    	Qom_Notify = eTPU_QOM_ConfigPtr->Qom_GetStaNotifyTable[u8Qom_ChannelIdx].Qom_Notification;

        if(Qom_Notify != NULL_PTR)
        {
            ETPU_LLD_ClearChannelInterruptFlag(u8Etpu_Group,u8Qom_ChaHardWareIdx);
            Qom_Notify();
        }
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif
#endif
