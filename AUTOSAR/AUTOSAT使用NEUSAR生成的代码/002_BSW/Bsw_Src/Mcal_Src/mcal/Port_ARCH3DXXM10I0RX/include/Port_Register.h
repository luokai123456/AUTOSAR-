/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : PORT
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Port_Register.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/

#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H
#ifdef __cplusplus
extern "C"{
#endif
/* ==============================================INCLUDE FILES======================================= */
#include "derivative.h"
/* =====================================SOURCE FILE VERSION INFORMATION============================== */

#define REGESYS_SIUL2_VENDOR_ID                    176
#define REGESYS_SIUL2_AR_REL_MAJOR_VER             4
#define REGESYS_SIUL2_AR_REL_MINOR_VER             4
#define REGESYS_SIUL2_AR_REL_REV_VER               0
#define REGESYS_SIUL2_SW_MAJOR_VERSION             3
#define REGESYS_SIUL2_SW_MINOR_VERSION             0
#define REGESYS_SIUL2_SW_PATCH_VERSION             0

/* ============================================FILE VERSION CHECKS=================================== */
#if (REGESYS_SIUL2_VENDOR_ID != REGESYS_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_VENDOR_ID"
#endif

#if (REGESYS_SIUL2_AR_REL_MAJOR_VER != REGESYS_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MAJOR_VER"
#endif

#if (REGESYS_SIUL2_AR_REL_MINOR_VER != REGESYS_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MINOR_VER"
#endif

#if (REGESYS_SIUL2_AR_REL_REV_VER != REGESYS_SIUL2_AR_REL_REV_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_REV_VER"
#endif

#if (REGESYS_SIUL2_SW_MAJOR_VERSION != REGESYS_SIUL2_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_MAJOR_VERSION"
#endif

#if (REGESYS_SIUL2_SW_MINOR_VERSION != REGESYS_SIUL2_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_MINOR_VERSION"
#endif

#if (REGESYS_SIUL2_SW_PATCH_VERSION != REGESYS_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_PATCH_VERSION"
#endif
/* =============================================CONSTANTS============================================ */


/* =========================================DEFINES AND MACROS======================================= */
#define SIU_BASEADDR                                ((uint32)0xC3F90000UL)
#define SIUL2_IMCR_RESET_MASK_U32                   ((uint32)0x00000000UL)

#define SIUL2_MSCR_OERC_U32                         (0x70000000UL)
#define SIUL2_MSCR_OERC_OFFSET_U32                  ((uint32)28UL)
#define SIUL2_MSCR_OERC_WEAK_DRIVE_U32              ((uint32)0x00000000UL)
#define SIUL2_MSCR_OERC_MED_DRIVE_U32               ((uint32)0x10000000UL)
#define SIUL2_MSCR_OERC_STR_DRIVE_U32               ((uint32)0x20000000UL)
#define SIUL2_MSCR_OERC_VERY_STR_DR_U32             ((uint32)0x30000000UL)
#define SIUL2_MSCR_OERC_6PF_U32                     ((uint32)0x40000000UL)
#define SIUL2_MSCR_OERC_12PF_U32                    ((uint32)0x50000000UL)
#define SIUL2_MSCR_OERC_18PF_U32                    ((uint32)0x60000000UL)
#define SIUL2_MSCR_OERC_30PF_U32                    ((uint32)0x70000000UL)


/* @brief Mask definitions for MSCR bit field ODC or OBE and ODE */
#if (defined (RESOURCE_SUPPORT_SIUL_IP))
#define SIUL_PCR_ODE_U16                            ((uint16)0x0020U)
#else
#define SIUL2_MSCR_ODC_U32                          (0x07000000UL)
#endif

#define SIUL2_MSCR_ODC_OFFSET_U32                   ((uint32)24UL)
#define SIUL2_MSCR_ODC_OUT_BUF_DAB_U32              ((uint32)0x00000000UL)
#define SIUL2_MSCR_ODC_OPEN_DRAIN_U32               ((uint32)0x01000000UL)
#define SIUL2_MSCR_ODC_PUSH_PULL_U32                ((uint32)0x02000000UL)
#define SIUL2_MSCR_ODC_OPEN_SOURCE_U32              ((uint32)0x03000000UL)
#define SIUL2_MSCR_ODC_MICRO_LVDS_U32               ((uint32)0x04000000UL)
#define SIUL2_MSCR_ODC_LFAST_LVDS_U32               ((uint32)0x05000000UL)


/* @brief Mask definitions for MSCR bit field SMC */
#define SIUL2_MSCR_SMC_U32                              (0x00800000UL)
#define SIUL2_MSCR_SMC_OFFSET_U32                       ((uint32)23UL)
#define SIUL2_MSCR_SMC_ON_U32                           ((uint32)0x00800000UL)
#define SIUL2_MSCR_SMC_OFF_U32                          ((uint32)0x00000000UL)


/* @brief Mask definitions for MSCR bit field APC, IBE and HYS */
#define SIUL2_MSCR_APC_U32                              (0x00400000UL)
#define SIUL2_MSCR_APC_OFFSET_U32                       ((uint32)22UL)
#define SIUL2_MSCR_APC_ON_U32                           ((uint32)0x00400000UL)
#define SIUL2_MSCR_APC_OFF_U32                          ((uint32)0x00000000UL)

#if (defined (RESOURCE_SUPPORT_SIUL_IP))
#define SIUL_PCR_IBE_U16                                ((uint16)0x0040U)
#define SIUL_PCR_IBE_ON_U16                             ((uint16)0x0040U)
#else
#define SIUL2_MSCR_IBE_U32                              (0x00080000UL)
#define SIUL2_MSCR_IBE_ON_U32                           ((uint32)0x00080000UL)
#endif

#define SIUL2_MSCR_IBE_OFFSET_U32                       ((uint32)19UL)
#define SIUL2_MSCR_IBE_OFF_U32                          ((uint32)0x00000000UL)

#define SIUL2_MSCR_HYS_U32                              (0x00040000UL)
#define SIUL2_MSCR_HYS_OFFSET_U32                       ((uint32)18UL)
#define SIUL2_MSCR_HYS_ON_U32                           ((uint32)0x00040000UL)
#define SIUL2_MSCR_HYS_OFF_U32                          ((uint32)0x00000000UL)


/* @brief Mask definitions for MSCR bit field ILS and TTL */
#define SIUL2_MSCR_ILS_U32                              (0x00300000UL)
#define SIUL2_MSCR_ILS_OFFSET_U32                       ((uint32)20UL)
#define SIUL2_MSCR_ILS_AUTO_U32                         ((uint32)0x00000000UL)
#define SIUL2_MSCR_ILS_TTL_U32                          ((uint32)0x00100000UL)
#define SIUL2_MSCR_ILS_LVDS_U32                         ((uint32)0x00200000UL)
#define SIUL2_MSCR_ILS_CMOS_U32                         ((uint32)0x00300000UL)


/* @brief Mask definitions for MSCR bit field PUS, PUE or WPDE, WPUE */
#define SIUL2_MSCR_WPDE_U32                         (0x00020000UL)
#define SIUL2_MSCR_WPDE_OFFSET_U32                  ((uint32)17UL)
#define SIUL2_MSCR_WPDE_ON_U32                      ((uint32)0x00020000UL)
#define SIUL2_MSCR_WPDE_OFF_U32                     ((uint32)0x00000000UL)

#define SIUL2_MSCR_WPUE_U32                         (0x00010000UL)
#define SIUL2_MSCR_WPUE_OFFSET_U32                  ((uint32)16UL)
#define SIUL2_MSCR_WPUE_ON_U32                      ((uint32)0x00010000UL)
#define SIUL2_MSCR_WPUE_OFF_U32                     ((uint32)0x00000000UL)


/* @brief Mask definitions for MSCR bit field INV */

#define SIUL2_MSCR_INV_U32                          (0x00008000UL)
#define SIUL2_MSCR_INV_OFFSET_U32                   ((uint32)15UL)
#define SIUL2_MSCR_INV_ON_U32                       ((uint32)0x00008000UL)
#define SIUL2_MSCR_INV_OFF_U32                      ((uint32)0x00000000UL)


/* @brief Mask definitions for MSCR bit field SSS */
#if (defined (RESOURCE_SUPPORT_SIUL_IP))
#define SIUL_PCR_SSS_U16                            ((uint16)0x1F00U)
#else
#define SIUL2_MSCR_SSS_U32                          (0x000000FFUL)
#endif

#define SIUL2_MSCR_SSS_OFFSET_U32                   ((uint32)0UL)


#define SIUL2_IMCR_INV_U32                              (0x00008000UL)



#define SIUL2_IMCR_SSS_U32                      (0x000000FFUL)


#define SIUL2_IMCR_SSS_OFFSET_U32                       ((uint32)0UL)


/* @brief Mode bit offset mask */
#define SIUL2_BIT_OFFSET_MASK_U8       ((uint8)0x0F)



/* @brief Mask definitions for EIOMUX2(CCFC3008PCSN's EIOMUX) bit field ODC or OBE or IBE */
#define EIOMUX2_PADX_IBE_MASK_U32                     (0x00000800UL)
#define EIOMUX2_PADX_IBE_OFFSET_U32                   ((uint32)11UL)
#define EIOMUX2_PADX_IBE_ON_U32                       ((uint32)0x00000800UL)
#define EIOMUX2_PADX_IBE_OFF_U32                      ((uint32)0x00000000UL)

#define EIOMUX2_PADX_ODC_MASK_U32                     (0x000000e0UL)
#define EIOMUX2_PADX_ODC_OFFSET_U32                   ((uint32)5UL)
#define EIOMUX2_PADX_ODC_OUT_BUF_DISABLE_U32          ((uint32)0x00000080UL)
#define EIOMUX2_PADX_ODC_OPEN_SOURCE_U32              ((uint32)0x00000060UL)
#define EIOMUX2_PADX_ODC_PUSH_PULL_U32                ((uint32)0x00000040UL)
#define EIOMUX2_PADX_ODC_OPEN_DRAIN_U32               ((uint32)0x00000020UL)
#define EIOMUX2_PADX_ODC_DISABLE_U32                  ((uint32)0x00000000UL)
/* @brief Mask definitions for EIOMUX2(CCFC3008PCSN's EIOMUX) bit field SMOD */
#define EIOMUX2_PADX_SMOD_MASK_U32                    (0x00000200UL)
#define EIOMUX2_PADX_SMOD_OFFSET_U32                  ((uint32)9UL)
#define EIOMUX2_PADX_SMOD_ON_U32                      ((uint32)0x00000200UL)
#define EIOMUX2_PADX_SMOD_OFF_U32                     ((uint32)0x00000000UL)
/* @brief Mask definitions for EIOMUX2(CCFC3008PCSN's EIOMUX) bit field INV */
#define EIOMUX2_PADX_INV_MASK_U32                     (0x00008000UL)
#define EIOMUX2_PADX_INV_OFFSET_U32                   ((uint32)15UL)
#define EIOMUX2_PADX_INV_ON_U32                       ((uint32)0x00008000UL)
#define EIOMUX2_PADX_INV_OFF_U32                      ((uint32)0x00000000UL)
/* @brief Mask definitions for EIOMUX2(CCFC3008PCSN's EIOMUX) bit field SSS */
#define EIOMUX2_PADX_ISSS_MASK_U32                     (0x0000001FUL)
#define EIOMUX2_PADX_ISSS_OFFSET_U32                   ((uint32)0UL)
/* @brief Mask definitions for EIOMUX2(CCFC3008PCSN's EIOMUX) bit field SSS */
#define EIOMUX2_ISR_ISS_MASK_U32                       (0x0000001FUL)
#define EIOMUX2_ISR_ISS_OFFSET_U32                     ((uint32)0UL)
/* ==============================================ENUMS=============================================== */


/* =======================================STRUCTURES AND OTHER TYPEDEFS============================== */


/* ====================================GLOBAL VARIABLE DECLARATIONS================================== */


/* ========================================FUNCTION PROTOTYPES======================================= */

#ifdef __cplusplus
}
#endif
/* PORT_REGISTER_H */
#endif
/** @} */
