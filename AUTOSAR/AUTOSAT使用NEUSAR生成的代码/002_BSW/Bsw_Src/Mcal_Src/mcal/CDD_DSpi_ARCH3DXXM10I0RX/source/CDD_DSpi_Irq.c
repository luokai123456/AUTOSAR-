/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : DSPI
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    CDD_DSpi_Irq.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CDD_DSpi MCAL driver.
*
*   @addtogroup CDD_DSpi
*   @{
*/
/*PRQA S 0380 EOF*/
#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_DSpi_Irq.h"
#include "dspi_LLDriver.h"

#define CDD_DSPI_IRQ_C_VENDOR_ID                     176
#define CDD_DSPI_IRQ_C_AR_REL_MAJOR_VER              4
#define CDD_DSPI_IRQ_C_AR_REL_MINOR_VER              4
#define CDD_DSPI_IRQ_C_AR_REL_REV_VER                0
#define CDD_DSPI_IRQ_C_SW_MAJOR_VER                  3
#define CDD_DSPI_IRQ_C_SW_MINOR_VER                  0
#define CDD_DSPI_IRQ_C_SW_PATCH_VER                  0

#if (CDD_DSPI_VENDOR_ID_OUTPUT != CDD_DSPI_IRQ_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CDD_DSPI_IRQ_C_VENDOR_ID "
#endif
#if (CDD_DSPI_AR_RELEASE_MAJOR_VERSION_OUTPUT != CDD_DSPI_IRQ_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_IRQ_C_AR_REL_MAJOR_VER "
#endif
#if (CDD_DSPI_AR_RELEASE_MINOR_VERSION_OUTPUT != CDD_DSPI_IRQ_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_IRQ_C_AR_REL_MINOR_VER "
#endif
#if (CDD_DSPI_AR_RELEASE_REVISION_VERSION_OUTPUT != CDD_DSPI_IRQ_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_IRQ_C_AR_REL_REV_VER "
#endif
#if (CDD_DSPI_SW_MAJOR_VERSION_OUTPUT != CDD_DSPI_IRQ_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_IRQ_C_SW_MAJOR_VER "
#endif
#if (CDD_DSPI_SW_MINOR_VERSION_OUTPUT != CDD_DSPI_IRQ_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_IRQ_C_SW_MINOR_VER "
#endif
#if (CDD_DSPI_SW_PATCH_VERSION_OUTPUT != CDD_DSPI_IRQ_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CDD_DSPI_IRQ_C_SW_PATCH_VER "
#endif

#ifdef RESOURCE_SUPPORT_DSPI_0
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi0_FifoError_IRQHandler(void)
{
    (void)DSPI_TrannsferFail(&SPID1);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi0_Eoqf_IRQHandler(void)
{
	spi_serve_dspi_eoqf(&SPID1);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi0_Tcf_IRQHandler(void)
{
	spi_serve_dspi_tcf(&SPID1);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* RESOURCE_SUPPORT_DSPI_0 */
#ifdef RESOURCE_SUPPORT_DSPI_1
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi1_FifoError_IRQHandler(void)
{
	(void)DSPI_TrannsferFail(&SPID2);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi1_Eoqf_IRQHandler(void)
{
	spi_serve_dspi_eoqf(&SPID2);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi1_Tcf_IRQHandler(void)
{
	spi_serve_dspi_tcf(&SPID2);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* RESOURCE_SUPPORT_DSPI_1 */
#ifdef RESOURCE_SUPPORT_DSPI_2
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi2_FifoError_IRQHandler(void)
{
	(void)DSPI_TrannsferFail(&SPID3);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi2_Eoqf_IRQHandler(void)
{
	spi_serve_dspi_eoqf(&SPID3);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi2_Tcf_IRQHandler(void)
{
	spi_serve_dspi_tcf(&SPID3);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* RESOURCE_SUPPORT_DSPI_2 */
#ifdef RESOURCE_SUPPORT_DSPI_3
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi3_FifoError_IRQHandler(void)
{
	(void)DSPI_TrannsferFail(&SPID4);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi3_Eoqf_IRQHandler(void)
{
	spi_serve_dspi_eoqf(&SPID4);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi3_Tcf_IRQHandler(void)
{
	spi_serve_dspi_tcf(&SPID4);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* RESOURCE_SUPPORT_DSPI_3 */
#ifdef RESOURCE_SUPPORT_DSPI_4
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi4_FifoError_IRQHandler(void)
{
	(void)DSPI_TrannsferFail(&SPID5);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi4_Eoqf_IRQHandler(void)
{
	spi_serve_dspi_eoqf(&SPID5);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi4_Tcf_IRQHandler(void)
{
	spi_serve_dspi_tcf(&SPID5);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* RESOURCE_SUPPORT_DSPI_4 */
#ifdef RESOURCE_SUPPORT_DSPI_5
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi5_FifoError_IRQHandler(void)
{
	(void)DSPI_TrannsferFail(&SPID6);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi5_Eoqf_IRQHandler(void)
{
	spi_serve_dspi_eoqf(&SPID6);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi5_Tcf_IRQHandler(void)
{
	spi_serve_dspi_tcf(&SPID6);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* RESOURCE_SUPPORT_DSPI_5 */
#ifdef RESOURCE_SUPPORT_DSPI_6
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi6_FifoError_IRQHandler(void)
{
	(void)DSPI_TrannsferFail(&SPID7);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi6_Eoqf_IRQHandler(void)
{
	spi_serve_dspi_eoqf(&SPID7);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi6_Tcf_IRQHandler(void)
{
	spi_serve_dspi_tcf(&SPID7);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* RESOURCE_SUPPORT_DSPI_6 */
#ifdef RESOURCE_SUPPORT_DSPI_12
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi12_FifoError_IRQHandler(void)
{
	(void)DSPI_TrannsferFail(&SPID13);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi12_Eoqf_IRQHandler(void)
{
	spi_serve_dspi_eoqf(&SPID13);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Dspi_Spi12_Tcf_IRQHandler(void)
{
	spi_serve_dspi_tcf(&SPID13);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* RESOURCE_SUPPORT_DSPI_12 */

#ifdef __cplusplus
}
#endif
