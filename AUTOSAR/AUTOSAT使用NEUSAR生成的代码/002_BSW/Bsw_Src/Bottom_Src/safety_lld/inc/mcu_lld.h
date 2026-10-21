/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     mcu_lld.h
* @version  1.0
* @date     2023 - 04 - 17
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
#ifndef MCU_LLD_H_
#define MCU_LLD_H_
/*PRQA S 0635 EOF*/
#include "derivative.h"
#include "status.h"
#ifdef SAFETY_ENABLE
#include "Mcu_LLDriver.h"
#endif
/****************************************************************************/


typedef enum {
    SAF_CORE_ID_Z7_0,
	SAF_CORE_ID_Z7_1,
	SAF_CORE_ID_Z4_2,
	SAF_CORE_ID_Z7_3_Check,
	SAF_CORE_ID_Z0_4_HSM,
	SAF_CORE_ID_BUTT,
} Saf_CoreId;

typedef union {
    uint16_t R;
    struct {
      uint16_t stop0:1;
      uint16_t halt0:1;
      uint16_t run3:1;
      uint16_t run2:1;
      uint16_t run1:1;
      uint16_t run0:1;
      uint16_t drun:1;
      uint16_t safe:1;
      uint16_t test:1;
      uint16_t reset:1;
      uint16_t resv:6;
    } B;
} CoreMode;

typedef enum {
    CHIP_MODE_RESET_FUNC,
    CHIP_MODE_TEST,
    CHIP_MODE_SAFE,
    CHIP_MODE_DRUN,
    CHIP_MODE_RUN0,
    CHIP_MODE_RUN1,
    CHIP_MODE_RUN2,
    CHIP_MODE_RUN3,
    CHIP_MODE_HALT,
    CHIP_MODE_STOP,
    CHIP_MODE_RESET_DEST,
    CHIP_MODE_INVALID,
} ChipMode;

#ifndef SAFETY_ENABLE
typedef  struct IRCOSC_tag                   IRCOSC_Type;/*PRQA S 0631*/
typedef  struct XOSC_tag                     XOSC_Type;/*PRQA S 0631*/
typedef  struct PLLDIG_tag                   PLLDIG_Type;/*PRQA S 0631*/
typedef  struct MC_CGM_tag                   MC_CGM_Type;/*PRQA S 0631*/
#endif

/* IRCOSC - Peripheral instance base addresses */
/** Peripheral IRCOSC base address */
#define SAF_IRCOSC_BASE                              (0xFFFB0000u)
/** Peripheral IRCOSC base pointer */
#define SAF_IRCOSC_StPtr                             ((IRCOSC_Type *)SAF_IRCOSC_BASE)
/** Array initializer of IRCOSC peripheral base addresses */
#define SAF_IRCOSC_BASE_ADDRS                        { SAF_IRCOSC_BASE }
/** Array initializer of IRCOSC peripheral base pointers */
#define SAF_IRCOSC_BASE_PTRS                         { SAF_IRCOSC_StPtr }

/* XOSC - Peripheral instance base addresses */
/** Peripheral XOSC base address */
#define SAF_XOSC_BASE                                (0xFFFB0080u)
/** Peripheral XOSC base pointer */
#define SAF_XOSC_StPtr                               ((XOSC_Type *)SAF_XOSC_BASE)
/** Array initializer of XOSC peripheral base addresses */
#define SAF_XOSC_BASE_ADDRS                          { SAF_XOSC_BASE }
/** Array initializer of XOSC peripheral base pointers */
#define SAF_XOSC_BASE_PTRS                           { SAF_XOSC_StPtr }

/* PLLDIG - Peripheral instance base addresses */
/** Peripheral PLLDIG base address */
#define SAF_PLLDIG_BASE                              (0xFFFB0100u)
/** Peripheral PLLDIG base pointer */
#define SAF_PLLDIG_StPtr                             ((PLLDIG_Type *)SAF_PLLDIG_BASE)
/** Array initializer of PLLDIG peripheral base addresses */
#define SAF_PLLDIG_BASE_ADDRS                        { SAF_PLLDIG_BASE }
/** Array initializer of PLLDIG peripheral base pointers */
#define SAF_PLLDIG_BASE_PTRS                         { SAF_PLLDIG_StPtr }


/* MC_CGM - Peripheral instance base addresses */
/** Peripheral MC_CGM base address */
#define SAF_MC_CGM_BASE                              (0xFFFB0000u)
/** Peripheral MC_CGM base pointer */
#define SAF_MC_CGM_StPtr                             ((MC_CGM_Type *)SAF_MC_CGM_BASE)
/** Array initializer of MC_CGM peripheral base addresses */
#define SAF_MC_CGM_BASE_ADDRS                        { SAF_MC_CGM_BASE }
/** Array initializer of MC_CGM peripheral base pointers */
#define SAF_MC_CGM_BASE_PTRS                         { SAF_MC_CGM_StPtr }

/* PLL0CR Bit Fields */
#define SAF_PLLDIG_PLL0CR_CLKCFG_MASK                0x300u
#define SAF_PLLDIG_PLL0CR_CLKCFG_SHIFT               8u
#define SAF_PLLDIG_PLL0CR_CLKCFG_WIDTH               2u
#define SAF_PLLDIG_PLL0CR_CLKCFG(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_PLLDIG_PLL0CR_CLKCFG_SHIFT))&SAF_PLLDIG_PLL0CR_CLKCFG_MASK)

/* PLL1CR Bit Fields */
#define SAF_PLLDIG_PLL1CR_CLKCFG_MASK                0x300u
#define SAF_PLLDIG_PLL1CR_CLKCFG_SHIFT               8u
#define SAF_PLLDIG_PLL1CR_CLKCFG_WIDTH               2u
#define SAF_PLLDIG_PLL1CR_CLKCFG(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_PLLDIG_PLL1CR_CLKCFG_SHIFT))&SAF_PLLDIG_PLL1CR_CLKCFG_MASK)

/*!
 * @brief IRC clock divider
 * Implements cgmcs_irc_clk_div_t_Class
 */
typedef enum {

    IRC_CLOCK_DIV_1  = 0U,         /*!< Divided by 1  */
    IRC_CLOCK_DIV_2  = 1U,         /*!< Divided by 2  */
    IRC_CLOCK_DIV_3  = 2U,         /*!< Divided by 3  */
    IRC_CLOCK_DIV_4  = 3U,         /*!< Divided by 4  */
    IRC_CLOCK_DIV_5  = 4U,         /*!< Divided by 5  */
    IRC_CLOCK_DIV_6  = 5U,         /*!< Divided by 6  */
    IRC_CLOCK_DIV_7  = 6U,         /*!< Divided by 7  */
    IRC_CLOCK_DIV_8  = 7U,         /*!< Divided by 8  */
    IRC_CLOCK_DIV_9  = 8U,         /*!< Divided by 9  */
    IRC_CLOCK_DIV_10 = 9U,         /*!< Divided by 10 */
    IRC_CLOCK_DIV_11 = 10U,        /*!< Divided by 11 */
    IRC_CLOCK_DIV_12 = 11U,        /*!< Divided by 12 */
    IRC_CLOCK_DIV_13 = 12U,        /*!< Divided by 13 */
    IRC_CLOCK_DIV_14 = 13U,        /*!< Divided by 14 */
    IRC_CLOCK_DIV_15 = 14U,        /*!< Divided by 15 */
    IRC_CLOCK_DIV_16 = 15U,        /*!< Divided by 16 */
    IRC_CLOCK_DIV_17 = 16U,        /*!< Divided by 17 */
    IRC_CLOCK_DIV_18 = 17U,        /*!< Divided by 18 */
    IRC_CLOCK_DIV_19 = 18U,        /*!< Divided by 19 */
    IRC_CLOCK_DIV_20 = 19U,        /*!< Divided by 20 */
    IRC_CLOCK_DIV_21 = 20U,        /*!< Divided by 21 */
    IRC_CLOCK_DIV_22 = 21U,        /*!< Divided by 22 */
    IRC_CLOCK_DIV_23 = 22U,        /*!< Divided by 23 */
    IRC_CLOCK_DIV_24 = 23U,        /*!< Divided by 24 */
    IRC_CLOCK_DIV_25 = 24U,        /*!< Divided by 25 */
    IRC_CLOCK_DIV_26 = 25U,        /*!< Divided by 26 */
    IRC_CLOCK_DIV_27 = 26U,        /*!< Divided by 27 */
    IRC_CLOCK_DIV_28 = 27U,        /*!< Divided by 28 */
    IRC_CLOCK_DIV_29 = 28U,        /*!< Divided by 29 */
    IRC_CLOCK_DIV_30 = 29U,        /*!< Divided by 30 */
    IRC_CLOCK_DIV_31 = 30U,        /*!< Divided by 31 */
    IRC_CLOCK_DIV_32 = 31U,        /*!< Divided by 32 */
}cgmcs_irc_clk_div_t;/*PRQA S 1535*/


/*!
 * @brief IRC clock trimming value
 * Implements cgmcs_irc_clk_trim_t_Class
 */
typedef enum {
    IRC_CLOCK_TRIM_BY_MINUS_15 = 31U,         /*!< Trim by minus 15 */
    IRC_CLOCK_TRIM_BY_MINUS_14 = 30U,         /*!< Trim by minus 14 */
    IRC_CLOCK_TRIM_BY_MINUS_13 = 29U,         /*!< Trim by minus 13 */
    IRC_CLOCK_TRIM_BY_MINUS_12 = 28U,         /*!< Trim by minus 12 */
    IRC_CLOCK_TRIM_BY_MINUS_11 = 27U,         /*!< Trim by minus 11 */
    IRC_CLOCK_TRIM_BY_MINUS_10 = 26U,         /*!< Trim by minus 10 */
    IRC_CLOCK_TRIM_BY_MINUS_9  = 25U,         /*!< Trim by minus 9  */
    IRC_CLOCK_TRIM_BY_MINUS_8  = 24U,         /*!< Trim by minus 8  */
    IRC_CLOCK_TRIM_BY_MINUS_7  = 23U,         /*!< Trim by minus 7  */
    IRC_CLOCK_TRIM_BY_MINUS_6  = 22U,         /*!< Trim by minus 6  */
    IRC_CLOCK_TRIM_BY_MINUS_5  = 21U,         /*!< Trim by minus 5  */
    IRC_CLOCK_TRIM_BY_MINUS_4  = 20U,         /*!< Trim by minus 4  */
    IRC_CLOCK_TRIM_BY_MINUS_3  = 19U,         /*!< Trim by minus 3  */
    IRC_CLOCK_TRIM_BY_MINUS_2  = 18U,         /*!< Trim by minus 2  */
    IRC_CLOCK_TRIM_BY_MINUS_1  = 17U,         /*!< Trim by minus 1  */
    IRC_CLOCK_NO_TRIMMING      = 16U,         /*!< No trimming      */
    IRC_CLOCK_TRIM_BY_PLUS_1   = 1U,          /*!< Trim by plus 1   */
    IRC_CLOCK_TRIM_BY_PLUS_2   = 2U,          /*!< Trim by plus 2   */
    IRC_CLOCK_TRIM_BY_PLUS_3   = 3U,          /*!< Trim by plus 3   */
    IRC_CLOCK_TRIM_BY_PLUS_4   = 4U,          /*!< Trim by plus 4   */
    IRC_CLOCK_TRIM_BY_PLUS_5   = 5U,          /*!< Trim by plus 5   */
    IRC_CLOCK_TRIM_BY_PLUS_6   = 6U,          /*!< Trim by plus 6   */
    IRC_CLOCK_TRIM_BY_PLUS_7   = 7U,          /*!< Trim by plus 7   */
    IRC_CLOCK_TRIM_BY_PLUS_8   = 8U,          /*!< Trim by plus 8   */
    IRC_CLOCK_TRIM_BY_PLUS_9   = 9U,          /*!< Trim by plus 9   */
    IRC_CLOCK_TRIM_BY_PLUS_10  = 10U,         /*!< Trim by plus 10  */
    IRC_CLOCK_TRIM_BY_PLUS_11  = 11U,         /*!< Trim by plus 11  */
    IRC_CLOCK_TRIM_BY_PLUS_12  = 12U,         /*!< Trim by plus 12  */
    IRC_CLOCK_TRIM_BY_PLUS_13  = 13U,         /*!< Trim by plus 13  */
    IRC_CLOCK_TRIM_BY_PLUS_14  = 14U,         /*!< Trim by plus 14  */
    IRC_CLOCK_TRIM_BY_PLUS_15  = 15U,         /*!< Trim by plus 15  */
}cgmcs_irc_clk_trim_t;
/*!
 * @brief CGM Clock Source IRC configuration structure.
 * Implements cgmcs_irc_config_t_Class
 */
typedef struct
{

    cgmcs_irc_clk_trim_t     trimmingValue;    /*!< User trim value.  */

} cgmcs_irc_config_t;


/*!
 * @brief XOSC clock divider
 * Implements cgmcs_xosc_clk_div_t_Class
 */
typedef enum {

    XOSC_CLOCK_DIV_1  = 0U,         /*!< Divided by 1  */
    XOSC_CLOCK_DIV_2  = 1U,         /*!< Divided by 2  */
    XOSC_CLOCK_DIV_3  = 2U,         /*!< Divided by 3  */
    XOSC_CLOCK_DIV_4  = 3U,         /*!< Divided by 4  */
    XOSC_CLOCK_DIV_5  = 4U,         /*!< Divided by 5  */
    XOSC_CLOCK_DIV_6  = 5U,         /*!< Divided by 6  */
    XOSC_CLOCK_DIV_7  = 6U,         /*!< Divided by 7  */
    XOSC_CLOCK_DIV_8  = 7U,         /*!< Divided by 8  */
    XOSC_CLOCK_DIV_9  = 8U,         /*!< Divided by 9  */
    XOSC_CLOCK_DIV_10 = 9U,         /*!< Divided by 10 */
    XOSC_CLOCK_DIV_11 = 10U,        /*!< Divided by 11 */
    XOSC_CLOCK_DIV_12 = 11U,        /*!< Divided by 12 */
    XOSC_CLOCK_DIV_13 = 12U,        /*!< Divided by 13 */
    XOSC_CLOCK_DIV_14 = 13U,        /*!< Divided by 14 */
    XOSC_CLOCK_DIV_15 = 14U,        /*!< Divided by 15 */
    XOSC_CLOCK_DIV_16 = 15U,        /*!< Divided by 16 */
    XOSC_CLOCK_DIV_17 = 16U,        /*!< Divided by 17 */
    XOSC_CLOCK_DIV_18 = 17U,        /*!< Divided by 18 */
    XOSC_CLOCK_DIV_19 = 18U,        /*!< Divided by 19 */
    XOSC_CLOCK_DIV_20 = 19U,        /*!< Divided by 20 */
    XOSC_CLOCK_DIV_21 = 20U,        /*!< Divided by 21 */
    XOSC_CLOCK_DIV_22 = 21U,        /*!< Divided by 22 */
    XOSC_CLOCK_DIV_23 = 22U,        /*!< Divided by 23 */
    XOSC_CLOCK_DIV_24 = 23U,        /*!< Divided by 24 */
    XOSC_CLOCK_DIV_25 = 24U,        /*!< Divided by 25 */
    XOSC_CLOCK_DIV_26 = 25U,        /*!< Divided by 26 */
    XOSC_CLOCK_DIV_27 = 26U,        /*!< Divided by 27 */
    XOSC_CLOCK_DIV_28 = 27U,        /*!< Divided by 28 */
    XOSC_CLOCK_DIV_29 = 28U,        /*!< Divided by 29 */
    XOSC_CLOCK_DIV_30 = 29U,        /*!< Divided by 30 */
    XOSC_CLOCK_DIV_31 = 30U,        /*!< Divided by 31 */
    XOSC_CLOCK_DIV_32 = 31U,        /*!< Divided by 32 */
}cgmcs_xosc_clk_div_t;/*PRQA S 1535*/


/*!
 * @brief XOSC bypass type.
 * Implements cgmcs_xosc_bypass_t_Class
 */
typedef enum
{
    SAF_XOSC_USE_CRYSTAL              = 0U,
	SAF_XOSC_USE_EXTAL                = 1U,
	SAF_XOSC_SINGLE_ENDED_BYPASS_MODE = 2U,
	SAF_XOSC_DIFFERENTIAL_BYPASS_MODE = 3U,
}cgmcs_xosc_bypass_t;

/*!
 * @brief XOSC mode.
 * Implements cgmcs_xosc_mode_t_Class
 */
typedef enum
{
    XOSC_FULL_SWING_PIERCE_MODE       = 0U,
    XOSC_LOOP_CONTROLLED_PIERCE_MODE  = 1U,
}cgmcs_xosc_mode_t;/*PRQA S 1535*/

/*!
 * @brief CGM Clock Source XOSC configuration structure.
 * Implements cgmcs_xosc_config_t_Class
 */
typedef struct
{
    uint32_t                  freq;               /*!< External oscillator frequency. */
    uint16_t                  startupDelay;       /*!< Startup stabilization time. */
    cgmcs_xosc_bypass_t       bypassOption;       /*!< XOSC option */
} cgmcs_xosc_config_t;

/*!
 * @brief plldig clock divider
 * Implements cgmcs_plldig_clk_prediv_t_Class
 */
typedef enum {
    PLLDIG_CLOCK_PREDIV_DISABLE  = 0U,     /*!< Disable predivider        */
    PLLDIG_CLOCK_PREDIV_1     = 1U,     /*!< Input clock divided by 1  */
    PLLDIG_CLOCK_PREDIV_2     = 2U,     /*!< Input clock divided by 2  */
    PLLDIG_CLOCK_PREDIV_3     = 3U,     /*!< Input clock divided by 3  */
    PLLDIG_CLOCK_PREDIV_4     = 4U,     /*!< Input clock divided by 4  */
    PLLDIG_CLOCK_PREDIV_5     = 5U,     /*!< Input clock divided by 5  */
    PLLDIG_CLOCK_PREDIV_6     = 6U,     /*!< Input clock divided by 6  */
    PLLDIG_CLOCK_PREDIV_7     = 7U,     /*!< Input clock divided by 7  */
}cgmcs_plldig_clk_prediv_t;


/*!
 * @brief plldig clockout divider
 * Implements cgmcs_plldig_clkout_div_t_Class
 */
typedef enum {

	SAF_PLLDIG_PHI_DIV_1  = 0U,           /*!< Divided by 1  */
	SAF_PLLDIG_PHI_DIV_2  = 1U,           /*!< Divided by 2  */
	SAF_PLLDIG_PHI_DIV_3  = 2U,           /*!< Divided by 3  */
	SAF_PLLDIG_PHI_DIV_4  = 3U,           /*!< Divided by 4  */
	SAF_PLLDIG_PHI_DIV_5  = 4U,           /*!< Divided by 5  */
	SAF_PLLDIG_PHI_DIV_6  = 5U,           /*!< Divided by 6  */
	SAF_PLLDIG_PHI_DIV_7  = 6U,           /*!< Divided by 7  */
	SAF_PLLDIG_PHI_DIV_8  = 7U,           /*!< Divided by 8  */
	SAF_PLLDIG_PHI_DIV_9  = 8U,           /*!< Divided by 9  */
	SAF_PLLDIG_PHI_DIV_10 = 9U,           /*!< Divided by 10 */
	SAF_PLLDIG_PHI_DIV_11 = 10U,          /*!< Divided by 11 */
	SAF_PLLDIG_PHI_DIV_12 = 11U,          /*!< Divided by 12 */
	SAF_PLLDIG_PHI_DIV_13 = 12U,          /*!< Divided by 13 */
	SAF_PLLDIG_PHI_DIV_14 = 13U,          /*!< Divided by 14 */
	SAF_PLLDIG_PHI_DIV_15 = 14U,          /*!< Divided by 15 */
	SAF_PLLDIG_PHI_DIV_16 = 15U,          /*!< Divided by 16 */
	SAF_PLLDIG_PHI_DIV_17 = 16U,          /*!< Divided by 17 */
	SAF_PLLDIG_PHI_DIV_18 = 17U,          /*!< Divided by 18 */
	SAF_PLLDIG_PHI_DIV_19 = 18U,          /*!< Divided by 19 */
	SAF_PLLDIG_PHI_DIV_20 = 19U,          /*!< Divided by 20 */
	SAF_PLLDIG_PHI_DIV_21 = 20U,          /*!< Divided by 21 */
	SAF_PLLDIG_PHI_DIV_22 = 21U,          /*!< Divided by 22 */
	SAF_PLLDIG_PHI_DIV_23 = 22U,          /*!< Divided by 23 */
	SAF_PLLDIG_PHI_DIV_24 = 23U,          /*!< Divided by 24 */
	SAF_PLLDIG_PHI_DIV_25 = 24U,          /*!< Divided by 25 */
	SAF_PLLDIG_PHI_DIV_26 = 25U,          /*!< Divided by 26 */
	SAF_PLLDIG_PHI_DIV_27 = 26U,          /*!< Divided by 27 */
	SAF_PLLDIG_PHI_DIV_28 = 27U,          /*!< Divided by 28 */
	SAF_PLLDIG_PHI_DIV_29 = 28U,          /*!< Divided by 29 */
	SAF_PLLDIG_PHI_DIV_30 = 29U,          /*!< Divided by 30 */
	SAF_PLLDIG_PHI_DIV_31 = 30U,          /*!< Divided by 31 */
	SAF_PLLDIG_PHI_DIV_32 = 31U,          /*!< Divided by 32 */
	SAF_PLLDIG_PHI_DIV_33 = 32U,          /*!< Divided by 33 */
	SAF_PLLDIG_PHI_DIV_34 = 33U,          /*!< Divided by 34 */
	SAF_PLLDIG_PHI_DIV_35 = 34U,          /*!< Divided by 35 */
	SAF_PLLDIG_PHI_DIV_36 = 35U,          /*!< Divided by 36 */
	SAF_PLLDIG_PHI_DIV_37 = 36U,          /*!< Divided by 37 */
	SAF_PLLDIG_PHI_DIV_38 = 37U,          /*!< Divided by 38 */
	SAF_PLLDIG_PHI_DIV_39 = 38U,          /*!< Divided by 39 */
	SAF_PLLDIG_PHI_DIV_40 = 39U,          /*!< Divided by 40 */
	SAF_PLLDIG_PHI_DIV_41 = 40U,          /*!< Divided by 41 */
	SAF_PLLDIG_PHI_DIV_42 = 41U,          /*!< Divided by 42 */
	SAF_PLLDIG_PHI_DIV_43 = 42U,          /*!< Divided by 43 */
	SAF_PLLDIG_PHI_DIV_44 = 43U,          /*!< Divided by 44 */
	SAF_PLLDIG_PHI_DIV_45 = 44U,          /*!< Divided by 45 */
	SAF_PLLDIG_PHI_DIV_46 = 45U,          /*!< Divided by 46 */
	SAF_PLLDIG_PHI_DIV_47 = 46U,          /*!< Divided by 47 */
	SAF_PLLDIG_PHI_DIV_48 = 47U,          /*!< Divided by 48 */
	SAF_PLLDIG_PHI_DIV_49 = 48U,          /*!< Divided by 49 */
	SAF_PLLDIG_PHI_DIV_50 = 49U,          /*!< Divided by 50 */
	SAF_PLLDIG_PHI_DIV_51 = 50U,          /*!< Divided by 51 */
	SAF_PLLDIG_PHI_DIV_52 = 51U,          /*!< Divided by 52 */
	SAF_PLLDIG_PHI_DIV_53 = 52U,          /*!< Divided by 53 */
	SAF_PLLDIG_PHI_DIV_54 = 53U,          /*!< Divided by 54 */
	SAF_PLLDIG_PHI_DIV_55 = 54U,          /*!< Divided by 55 */
	SAF_PLLDIG_PHI_DIV_56 = 55U,          /*!< Divided by 56 */
	SAF_PLLDIG_PHI_DIV_57 = 56U,          /*!< Divided by 57 */
	SAF_PLLDIG_PHI_DIV_58 = 57U,          /*!< Divided by 58 */
	SAF_PLLDIG_PHI_DIV_59 = 58U,          /*!< Divided by 59 */
	SAF_PLLDIG_PHI_DIV_60 = 59U,          /*!< Divided by 60 */
	SAF_PLLDIG_PHI_DIV_61 = 60U,          /*!< Divided by 61 */
	SAF_PLLDIG_PHI_DIV_62 = 61U,          /*!< Divided by 62 */
	SAF_PLLDIG_PHI_DIV_63 = 62U,          /*!< Divided by 63 */
	SAF_PLLDIG_PHI_DIV_64 = 63U,          /*!< Divided by 64 */
	SAF_PLLDIG_PHI_DIV_DISABLE  = 64U,           /*!< Disable  */
}cgmcs_plldig_clkout_div_t;


/*!
 * @brief Modulation mode.
 * Implements cgmcs_plldig_mod_type_t_Class
 */
typedef enum
{
	SAF_CENTRE_SPREAD_MODULATION       = 0U,
	SAF_DOWN_SPREAD_MODULATION         = 1U,
}cgmcs_plldig_mod_type_t;



/*!
 * @brief CGM Clock Source PLLDIG configuration structure.
 * Implements cgmcs_plldig_config_t_Class
 */
typedef struct
{
    cgmcs_plldig_clk_prediv_t  predivider;                     /*!< Input clock predivider. (PREDIV) */
    uint8_t                    mulFactorDiv;                   /*!< Multiplication factor divider (MFD) */
    cgmcs_plldig_clkout_div_t  phi0Divider;                    /*!< Divider for clockout0 - PHI (RFDPHI) */
    cgmcs_plldig_clkout_div_t  phi1Divider;                    /*!< Divider for clockout1 - PHI1 (RFDPHI1) */

    boolean                    modulation;                     /*!< Enable/disable (MODEN)modulation */
    cgmcs_plldig_mod_type_t    modulationType;                 /*!< Modulation type(MODSEL) */
    uint16_t                   modulationPeriod;               /*!< Stepsize(MODPRD) - modulation period */
    uint16_t                   incrementStep;                  /*!< Stepno(INCSTP)  - step no */

    boolean                    fracDivider;                    /*!< Enable fractional divider(FDEN) */
    uint16_t                   fracDividerValue;               /*!< Fractional divider value(FRCDIV) */

} cgmcs_plldig_config_t;

/*!
 * @brief CGM Clock Sources configuration structure.
 * Implements cgmcs_config_t_Class
 */
typedef struct
{
    cgmcs_irc_config_t                irc0Config;
    cgmcs_xosc_config_t               xosc0Config;



    cgmcs_plldig_config_t             pll0Config;
    cgmcs_plldig_config_t             pll1Config;

} cgmcs_config_t;


/*!
 * @brief CGM clock divider
 * Implements cgm_clk_div_t_Class
 */
typedef enum {

    SAF_CGM_CLOCK_DIV_1  = 0U,           /*!< Divided by 1  */
    SAF_CGM_CLOCK_DIV_2  = 1U,           /*!< Divided by 2  */
    SAF_CGM_CLOCK_DIV_3  = 2U,           /*!< Divided by 3  */
    SAF_CGM_CLOCK_DIV_4  = 3U,           /*!< Divided by 4  */
    SAF_CGM_CLOCK_DIV_5  = 4U,           /*!< Divided by 5  */
    SAF_CGM_CLOCK_DIV_6  = 5U,           /*!< Divided by 6  */
    SAF_CGM_CLOCK_DIV_7  = 6U,           /*!< Divided by 7  */
    SAF_CGM_CLOCK_DIV_8  = 7U,           /*!< Divided by 8  */
    SAF_CGM_CLOCK_DIV_9  = 8U,           /*!< Divided by 9  */
    SAF_CGM_CLOCK_DIV_10 = 9U,           /*!< Divided by 10 */
    SAF_CGM_CLOCK_DIV_11 = 10U,          /*!< Divided by 11 */
    SAF_CGM_CLOCK_DIV_12 = 11U,          /*!< Divided by 12 */
    SAF_CGM_CLOCK_DIV_13 = 12U,          /*!< Divided by 13 */
    SAF_CGM_CLOCK_DIV_14 = 13U,          /*!< Divided by 14 */
    SAF_CGM_CLOCK_DIV_15 = 14U,          /*!< Divided by 15 */
    SAF_CGM_CLOCK_DIV_16 = 15U,          /*!< Divided by 16 */
    SAF_CGM_CLOCK_DIV_17 = 16U,          /*!< Divided by 17 */
    SAF_CGM_CLOCK_DIV_18 = 17U,          /*!< Divided by 18 */
    SAF_CGM_CLOCK_DIV_19 = 18U,          /*!< Divided by 19 */
    SAF_CGM_CLOCK_DIV_20 = 19U,          /*!< Divided by 20 */
    SAF_CGM_CLOCK_DIV_21 = 20U,          /*!< Divided by 21 */
    SAF_CGM_CLOCK_DIV_22 = 21U,          /*!< Divided by 22 */
    SAF_CGM_CLOCK_DIV_23 = 22U,          /*!< Divided by 23 */
    SAF_CGM_CLOCK_DIV_24 = 23U,          /*!< Divided by 24 */
    SAF_CGM_CLOCK_DIV_25 = 24U,          /*!< Divided by 25 */
    SAF_CGM_CLOCK_DIV_26 = 25U,          /*!< Divided by 26 */
    SAF_CGM_CLOCK_DIV_27 = 26U,          /*!< Divided by 27 */
    SAF_CGM_CLOCK_DIV_28 = 27U,          /*!< Divided by 28 */
    SAF_CGM_CLOCK_DIV_29 = 28U,          /*!< Divided by 29 */
    SAF_CGM_CLOCK_DIV_30 = 29U,          /*!< Divided by 30 */
    SAF_CGM_CLOCK_DIV_31 = 30U,          /*!< Divided by 31 */
    SAF_CGM_CLOCK_DIV_32 = 31U,          /*!< Divided by 32 */
    SAF_CGM_CLOCK_DIV_33 = 32U,          /*!< Divided by 33 */
    SAF_CGM_CLOCK_DIV_34 = 33U,          /*!< Divided by 34 */
    SAF_CGM_CLOCK_DIV_35 = 34U,          /*!< Divided by 35 */
    SAF_CGM_CLOCK_DIV_36 = 35U,          /*!< Divided by 36 */
    SAF_CGM_CLOCK_DIV_37 = 36U,          /*!< Divided by 37 */
    SAF_CGM_CLOCK_DIV_38 = 37U,          /*!< Divided by 38 */
    SAF_CGM_CLOCK_DIV_39 = 38U,          /*!< Divided by 39 */
    SAF_CGM_CLOCK_DIV_40 = 39U,          /*!< Divided by 40 */
    SAF_CGM_CLOCK_DIV_41 = 40U,          /*!< Divided by 41 */
    SAF_CGM_CLOCK_DIV_42 = 41U,          /*!< Divided by 42 */
    SAF_CGM_CLOCK_DIV_43 = 42U,          /*!< Divided by 43 */
    SAF_CGM_CLOCK_DIV_44 = 43U,          /*!< Divided by 44 */
    SAF_CGM_CLOCK_DIV_45 = 44U,          /*!< Divided by 45 */
    SAF_CGM_CLOCK_DIV_46 = 45U,          /*!< Divided by 46 */
    SAF_CGM_CLOCK_DIV_47 = 46U,          /*!< Divided by 47 */
    SAF_CGM_CLOCK_DIV_48 = 47U,          /*!< Divided by 48 */
    SAF_CGM_CLOCK_DIV_49 = 48U,          /*!< Divided by 49 */
    SAF_CGM_CLOCK_DIV_50 = 49U,          /*!< Divided by 50 */
    SAF_CGM_CLOCK_DIV_51 = 50U,          /*!< Divided by 51 */
    SAF_CGM_CLOCK_DIV_52 = 51U,          /*!< Divided by 52 */
    SAF_CGM_CLOCK_DIV_53 = 52U,          /*!< Divided by 53 */
    SAF_CGM_CLOCK_DIV_54 = 53U,          /*!< Divided by 54 */
    SAF_CGM_CLOCK_DIV_55 = 54U,          /*!< Divided by 55 */
    SAF_CGM_CLOCK_DIV_56 = 55U,          /*!< Divided by 56 */
    SAF_CGM_CLOCK_DIV_57 = 56U,          /*!< Divided by 57 */
    SAF_CGM_CLOCK_DIV_58 = 57U,          /*!< Divided by 58 */
    SAF_CGM_CLOCK_DIV_59 = 58U,          /*!< Divided by 59 */
    SAF_CGM_CLOCK_DIV_60 = 59U,          /*!< Divided by 60 */
    SAF_CGM_CLOCK_DIV_61 = 60U,          /*!< Divided by 61 */
    SAF_CGM_CLOCK_DIV_62 = 61U,          /*!< Divided by 62 */
    SAF_CGM_CLOCK_DIV_63 = 62U,          /*!< Divided by 63 */
    SAF_CGM_CLOCK_DIV_64 = 63U,          /*!< Divided by 64 */
    SAF_CGM_CLOCK_DIV_65 = 64U,          /*!< Divided by 65 */
    SAF_CGM_CLOCK_DIV_66 = 65U,          /*!< Divided by 66 */
    SAF_CGM_CLOCK_DIV_67 = 66U,          /*!< Divided by 67 */
    SAF_CGM_CLOCK_DIV_68 = 67U,          /*!< Divided by 68 */
    SAF_CGM_CLOCK_DIV_69 = 68U,          /*!< Divided by 69 */
    SAF_CGM_CLOCK_DIV_70 = 69U,          /*!< Divided by 70 */
    SAF_CGM_CLOCK_DIV_71 = 70U,          /*!< Divided by 71 */
    SAF_CGM_CLOCK_DIV_72 = 71U,          /*!< Divided by 72 */
    SAF_CGM_CLOCK_DIV_73 = 72U,          /*!< Divided by 73 */
    SAF_CGM_CLOCK_DIV_74 = 73U,          /*!< Divided by 74 */
    SAF_CGM_CLOCK_DIV_75 = 74U,          /*!< Divided by 75 */
    SAF_CGM_CLOCK_DIV_76 = 75U,          /*!< Divided by 76 */
    SAF_CGM_CLOCK_DIV_77 = 76U,          /*!< Divided by 77 */
    SAF_CGM_CLOCK_DIV_78 = 77U,          /*!< Divided by 78 */
    SAF_CGM_CLOCK_DIV_79 = 78U,          /*!< Divided by 79 */
    SAF_CGM_CLOCK_DIV_80 = 79U,          /*!< Divided by 80 */
    SAF_CGM_CLOCK_DIV_81 = 80U,          /*!< Divided by 81 */
    SAF_CGM_CLOCK_DIV_82 = 81U,          /*!< Divided by 82 */
    SAF_CGM_CLOCK_DIV_83 = 82U,          /*!< Divided by 83 */
    SAF_CGM_CLOCK_DIV_84 = 83U,          /*!< Divided by 84 */
    SAF_CGM_CLOCK_DIV_85 = 84U,          /*!< Divided by 85 */
    SAF_CGM_CLOCK_DIV_86 = 85U,          /*!< Divided by 86 */
    SAF_CGM_CLOCK_DIV_87 = 86U,          /*!< Divided by 87 */
    SAF_CGM_CLOCK_DIV_88 = 87U,          /*!< Divided by 88 */
    SAF_CGM_CLOCK_DIV_89 = 88U,          /*!< Divided by 89 */
    SAF_CGM_CLOCK_DIV_90 = 89U,          /*!< Divided by 90 */
    SAF_CGM_CLOCK_DIV_91 = 90U,          /*!< Divided by 91 */
    SAF_CGM_CLOCK_DIV_92 = 91U,          /*!< Divided by 92 */
    SAF_CGM_CLOCK_DIV_93 = 92U,          /*!< Divided by 93 */
    SAF_CGM_CLOCK_DIV_94 = 93U,          /*!< Divided by 94 */
    SAF_CGM_CLOCK_DIV_95 = 94U,          /*!< Divided by 95 */
    SAF_CGM_CLOCK_DIV_96 = 95U,          /*!< Divided by 96 */
    SAF_CGM_CLOCK_DIV_97 = 96U,          /*!< Divided by 97 */
    SAF_CGM_CLOCK_DIV_98 = 97U,          /*!< Divided by 98 */
    SAF_CGM_CLOCK_DIV_99 = 98U,          /*!< Divided by 99 */
    SAF_CGM_CLOCK_DIV_100 = 99U,         /*!< Divided by 100 */
    SAF_CGM_CLOCK_DIV_101 = 100U,        /*!< Divided by 101 */
    SAF_CGM_CLOCK_DIV_102 = 101U,        /*!< Divided by 102 */
    SAF_CGM_CLOCK_DIV_103 = 102U,        /*!< Divided by 103 */
    SAF_CGM_CLOCK_DIV_104 = 103U,        /*!< Divided by 104 */
    SAF_CGM_CLOCK_DIV_105 = 104U,        /*!< Divided by 105 */
    SAF_CGM_CLOCK_DIV_106 = 105U,        /*!< Divided by 106 */
    SAF_CGM_CLOCK_DIV_107 = 106U,        /*!< Divided by 107 */
    SAF_CGM_CLOCK_DIV_108 = 107U,        /*!< Divided by 108 */
    SAF_CGM_CLOCK_DIV_109 = 108U,        /*!< Divided by 109 */
    SAF_CGM_CLOCK_DIV_110 = 109U,        /*!< Divided by 110 */
    SAF_CGM_CLOCK_DIV_111 = 110U,        /*!< Divided by 111 */
    SAF_CGM_CLOCK_DIV_112 = 111U,        /*!< Divided by 112 */
    SAF_CGM_CLOCK_DIV_113 = 112U,        /*!< Divided by 113 */
    SAF_CGM_CLOCK_DIV_114 = 113U,        /*!< Divided by 114 */
    SAF_CGM_CLOCK_DIV_115 = 114U,        /*!< Divided by 115 */
    SAF_CGM_CLOCK_DIV_116 = 115U,        /*!< Divided by 116 */
    SAF_CGM_CLOCK_DIV_117 = 116U,        /*!< Divided by 117 */
    SAF_CGM_CLOCK_DIV_118 = 117U,        /*!< Divided by 118 */
    SAF_CGM_CLOCK_DIV_119 = 118U,        /*!< Divided by 119 */
    SAF_CGM_CLOCK_DIV_120 = 119U,        /*!< Divided by 120 */
    SAF_CGM_CLOCK_DIV_121 = 120U,        /*!< Divided by 121 */
    SAF_CGM_CLOCK_DIV_122 = 121U,        /*!< Divided by 122 */
    SAF_CGM_CLOCK_DIV_123 = 122U,        /*!< Divided by 123 */
    SAF_CGM_CLOCK_DIV_124 = 123U,        /*!< Divided by 124 */
    SAF_CGM_CLOCK_DIV_125 = 124U,        /*!< Divided by 125 */
    SAF_CGM_CLOCK_DIV_126 = 125U,        /*!< Divided by 126 */
    SAF_CGM_CLOCK_DIV_127 = 126U,        /*!< Divided by 127 */
    SAF_CGM_CLOCK_DIV_128 = 127U,        /*!< Divided by 128 */
    SAF_CGM_CLOCK_DIV_129 = 128U,        /*!< Divided by 129 */
    SAF_CGM_CLOCK_DIV_130 = 129U,        /*!< Divided by 130 */
    SAF_CGM_CLOCK_DIV_131 = 130U,        /*!< Divided by 131 */
    SAF_CGM_CLOCK_DIV_132 = 131U,        /*!< Divided by 132 */
    SAF_CGM_CLOCK_DIV_133 = 132U,        /*!< Divided by 133 */
    SAF_CGM_CLOCK_DIV_134 = 133U,        /*!< Divided by 134 */
    SAF_CGM_CLOCK_DIV_135 = 134U,        /*!< Divided by 135 */
    SAF_CGM_CLOCK_DIV_136 = 135U,        /*!< Divided by 136 */
    SAF_CGM_CLOCK_DIV_137 = 136U,        /*!< Divided by 137 */
    SAF_CGM_CLOCK_DIV_138 = 137U,        /*!< Divided by 138 */
    SAF_CGM_CLOCK_DIV_139 = 138U,        /*!< Divided by 139 */
    SAF_CGM_CLOCK_DIV_140 = 139U,        /*!< Divided by 140 */
    SAF_CGM_CLOCK_DIV_141 = 140U,        /*!< Divided by 141 */
    SAF_CGM_CLOCK_DIV_142 = 141U,        /*!< Divided by 142 */
    SAF_CGM_CLOCK_DIV_143 = 142U,        /*!< Divided by 143 */
    SAF_CGM_CLOCK_DIV_144 = 143U,        /*!< Divided by 144 */
    SAF_CGM_CLOCK_DIV_145 = 144U,        /*!< Divided by 145 */
    SAF_CGM_CLOCK_DIV_146 = 145U,        /*!< Divided by 146 */
    SAF_CGM_CLOCK_DIV_147 = 146U,        /*!< Divided by 147 */
    SAF_CGM_CLOCK_DIV_148 = 147U,        /*!< Divided by 148 */
    SAF_CGM_CLOCK_DIV_149 = 148U,        /*!< Divided by 149 */
    SAF_CGM_CLOCK_DIV_150 = 149U,        /*!< Divided by 150 */
    SAF_CGM_CLOCK_DIV_151 = 150U,        /*!< Divided by 151 */
    SAF_CGM_CLOCK_DIV_152 = 151U,        /*!< Divided by 152 */
    SAF_CGM_CLOCK_DIV_153 = 152U,        /*!< Divided by 153 */
    SAF_CGM_CLOCK_DIV_154 = 153U,        /*!< Divided by 154 */
    SAF_CGM_CLOCK_DIV_155 = 154U,        /*!< Divided by 155 */
    SAF_CGM_CLOCK_DIV_156 = 155U,        /*!< Divided by 156 */
    SAF_CGM_CLOCK_DIV_157 = 156U,        /*!< Divided by 157 */
    SAF_CGM_CLOCK_DIV_158 = 157U,        /*!< Divided by 158 */
    SAF_CGM_CLOCK_DIV_159 = 158U,        /*!< Divided by 159 */
    SAF_CGM_CLOCK_DIV_160 = 159U,        /*!< Divided by 160 */
    SAF_CGM_CLOCK_DIV_161 = 160U,        /*!< Divided by 161 */
    SAF_CGM_CLOCK_DIV_162 = 161U,        /*!< Divided by 162 */
    SAF_CGM_CLOCK_DIV_163 = 162U,        /*!< Divided by 163 */
    SAF_CGM_CLOCK_DIV_164 = 163U,        /*!< Divided by 164 */
    SAF_CGM_CLOCK_DIV_165 = 164U,        /*!< Divided by 165 */
    SAF_CGM_CLOCK_DIV_166 = 165U,        /*!< Divided by 166 */
    SAF_CGM_CLOCK_DIV_167 = 166U,        /*!< Divided by 167 */
    SAF_CGM_CLOCK_DIV_168 = 167U,        /*!< Divided by 168 */
    SAF_CGM_CLOCK_DIV_169 = 168U,        /*!< Divided by 169 */
    SAF_CGM_CLOCK_DIV_170 = 169U,        /*!< Divided by 170 */
    SAF_CGM_CLOCK_DIV_171 = 170U,        /*!< Divided by 171 */
    SAF_CGM_CLOCK_DIV_172 = 171U,        /*!< Divided by 172 */
    SAF_CGM_CLOCK_DIV_173 = 172U,        /*!< Divided by 173 */
    SAF_CGM_CLOCK_DIV_174 = 173U,        /*!< Divided by 174 */
    SAF_CGM_CLOCK_DIV_175 = 174U,        /*!< Divided by 175 */
    SAF_CGM_CLOCK_DIV_176 = 175U,        /*!< Divided by 176 */
    SAF_CGM_CLOCK_DIV_177 = 176U,        /*!< Divided by 177 */
    SAF_CGM_CLOCK_DIV_178 = 177U,        /*!< Divided by 178 */
    SAF_CGM_CLOCK_DIV_179 = 178U,        /*!< Divided by 179 */
    SAF_CGM_CLOCK_DIV_180 = 179U,        /*!< Divided by 180 */
    SAF_CGM_CLOCK_DIV_181 = 180U,        /*!< Divided by 181 */
    SAF_CGM_CLOCK_DIV_182 = 181U,        /*!< Divided by 182 */
    SAF_CGM_CLOCK_DIV_183 = 182U,        /*!< Divided by 183 */
    SAF_CGM_CLOCK_DIV_184 = 183U,        /*!< Divided by 184 */
    SAF_CGM_CLOCK_DIV_185 = 184U,        /*!< Divided by 185 */
    SAF_CGM_CLOCK_DIV_186 = 185U,        /*!< Divided by 186 */
    SAF_CGM_CLOCK_DIV_187 = 186U,        /*!< Divided by 187 */
    SAF_CGM_CLOCK_DIV_188 = 187U,        /*!< Divided by 188 */
    SAF_CGM_CLOCK_DIV_189 = 188U,        /*!< Divided by 189 */
    SAF_CGM_CLOCK_DIV_190 = 189U,        /*!< Divided by 190 */
    SAF_CGM_CLOCK_DIV_191 = 190U,        /*!< Divided by 191 */
    SAF_CGM_CLOCK_DIV_192 = 191U,        /*!< Divided by 192 */
    SAF_CGM_CLOCK_DIV_193 = 192U,        /*!< Divided by 193 */
    SAF_CGM_CLOCK_DIV_194 = 193U,        /*!< Divided by 194 */
    SAF_CGM_CLOCK_DIV_195 = 194U,        /*!< Divided by 195 */
    SAF_CGM_CLOCK_DIV_196 = 195U,        /*!< Divided by 196 */
    SAF_CGM_CLOCK_DIV_197 = 196U,        /*!< Divided by 197 */
    SAF_CGM_CLOCK_DIV_198 = 197U,        /*!< Divided by 198 */
    SAF_CGM_CLOCK_DIV_199 = 198U,        /*!< Divided by 199 */
    SAF_CGM_CLOCK_DIV_200 = 199U,        /*!< Divided by 200 */
    SAF_CGM_CLOCK_DIV_201 = 200U,        /*!< Divided by 201 */
    SAF_CGM_CLOCK_DIV_202 = 201U,        /*!< Divided by 202 */
    SAF_CGM_CLOCK_DIV_203 = 202U,        /*!< Divided by 203 */
    SAF_CGM_CLOCK_DIV_204 = 203U,        /*!< Divided by 204 */
    SAF_CGM_CLOCK_DIV_205 = 204U,        /*!< Divided by 205 */
    SAF_CGM_CLOCK_DIV_206 = 205U,        /*!< Divided by 206 */
    SAF_CGM_CLOCK_DIV_207 = 206U,        /*!< Divided by 207 */
    SAF_CGM_CLOCK_DIV_208 = 207U,        /*!< Divided by 208 */
    SAF_CGM_CLOCK_DIV_209 = 208U,        /*!< Divided by 209 */
    SAF_CGM_CLOCK_DIV_210 = 209U,        /*!< Divided by 210 */
    SAF_CGM_CLOCK_DIV_211 = 210U,        /*!< Divided by 211 */
    SAF_CGM_CLOCK_DIV_212 = 211U,        /*!< Divided by 212 */
    SAF_CGM_CLOCK_DIV_213 = 212U,        /*!< Divided by 213 */
    SAF_CGM_CLOCK_DIV_214 = 213U,        /*!< Divided by 214 */
    SAF_CGM_CLOCK_DIV_215 = 214U,        /*!< Divided by 215 */
    SAF_CGM_CLOCK_DIV_216 = 215U,        /*!< Divided by 216 */
    SAF_CGM_CLOCK_DIV_217 = 216U,        /*!< Divided by 217 */
    SAF_CGM_CLOCK_DIV_218 = 217U,        /*!< Divided by 218 */
    SAF_CGM_CLOCK_DIV_219 = 218U,        /*!< Divided by 219 */
    SAF_CGM_CLOCK_DIV_220 = 219U,        /*!< Divided by 220 */
    SAF_CGM_CLOCK_DIV_221 = 220U,        /*!< Divided by 221 */
    SAF_CGM_CLOCK_DIV_222 = 221U,        /*!< Divided by 222 */
    SAF_CGM_CLOCK_DIV_223 = 222U,        /*!< Divided by 223 */
    SAF_CGM_CLOCK_DIV_224 = 223U,        /*!< Divided by 224 */
    SAF_CGM_CLOCK_DIV_225 = 224U,        /*!< Divided by 225 */
    SAF_CGM_CLOCK_DIV_226 = 225U,        /*!< Divided by 226 */
    SAF_CGM_CLOCK_DIV_227 = 226U,        /*!< Divided by 227 */
    SAF_CGM_CLOCK_DIV_228 = 227U,        /*!< Divided by 228 */
    SAF_CGM_CLOCK_DIV_229 = 228U,        /*!< Divided by 229 */
    SAF_CGM_CLOCK_DIV_230 = 229U,        /*!< Divided by 230 */
    SAF_CGM_CLOCK_DIV_231 = 230U,        /*!< Divided by 231 */
    SAF_CGM_CLOCK_DIV_232 = 231U,        /*!< Divided by 232 */
    SAF_CGM_CLOCK_DIV_233 = 232U,        /*!< Divided by 233 */
    SAF_CGM_CLOCK_DIV_234 = 233U,        /*!< Divided by 234 */
    SAF_CGM_CLOCK_DIV_235 = 234U,        /*!< Divided by 235 */
    SAF_CGM_CLOCK_DIV_236 = 235U,        /*!< Divided by 236 */
    SAF_CGM_CLOCK_DIV_237 = 236U,        /*!< Divided by 237 */
    SAF_CGM_CLOCK_DIV_238 = 237U,        /*!< Divided by 238 */
    SAF_CGM_CLOCK_DIV_239 = 238U,        /*!< Divided by 239 */
    SAF_CGM_CLOCK_DIV_240 = 239U,        /*!< Divided by 240 */
    SAF_CGM_CLOCK_DIV_241 = 240U,        /*!< Divided by 241 */
    SAF_CGM_CLOCK_DIV_242 = 241U,        /*!< Divided by 242 */
    SAF_CGM_CLOCK_DIV_243 = 242U,        /*!< Divided by 243 */
    SAF_CGM_CLOCK_DIV_244 = 243U,        /*!< Divided by 244 */
    SAF_CGM_CLOCK_DIV_245 = 244U,        /*!< Divided by 245 */
    SAF_CGM_CLOCK_DIV_246 = 245U,        /*!< Divided by 246 */
    SAF_CGM_CLOCK_DIV_247 = 246U,        /*!< Divided by 247 */
    SAF_CGM_CLOCK_DIV_248 = 247U,        /*!< Divided by 248 */
    SAF_CGM_CLOCK_DIV_249 = 248U,        /*!< Divided by 249 */
    SAF_CGM_CLOCK_DIV_250 = 249U,        /*!< Divided by 250 */
    SAF_CGM_CLOCK_DIV_251 = 250U,        /*!< Divided by 251 */
    SAF_CGM_CLOCK_DIV_252 = 251U,        /*!< Divided by 252 */
    SAF_CGM_CLOCK_DIV_253 = 252U,        /*!< Divided by 253 */
    SAF_CGM_CLOCK_DIV_254 = 253U,        /*!< Divided by 254 */
    SAF_CGM_CLOCK_DIV_255 = 254U,        /*!< Divided by 255 */

    SAF_CGM_CLOCK_DIV_300 = 299U,        /*!< Divided by 300 */

	SAF_CGM_CLOCK_DISABLE4    = 16U,        /*!< Disable system clock divider */
	SAF_CGM_CLOCK_DISABLE6    = 64U,        /*!< Disable system clock divider */
	SAF_CGM_CLOCK_DISABLE7    = 128U,       /*!< Disable system clock divider */
	SAF_CGM_CLOCK_DISABLE8    = 256U,       /*!< Disable system clock divider */
	SAF_CGM_CLOCK_DISABLE9    = 512U,       /*!< Disable system clock divider */
	SAF_CGM_CLOCK_DISABLE10    = 1024U,     /*!< Disable system clock divider */
	SAF_CGM_CLOCK_DISABLE13    = 8192U,      /*!< Disable system clock divider */

}cgm_clk_div_t;

/*!
 * @brief HSM clock divider
 */
typedef uint32_t hsm_clk_div_t;
#define HSM_CLOCK_DIV_1  0U           /*!< Divided by 1  */
#define HSM_CLOCK_DIV_2  1U           /*!< Divided by 2  */
#define HSM_CLOCK_DIV_3  2U           /*!< Divided by 3  */
#define HSM_CLOCK_DIV_4  3U           /*!< Divided by 4  */
#define HSM_CLOCK_DIV_5  4U           /*!< Divided by 5  */
#define HSM_CLOCK_DIV_6  5U           /*!< Divided by 6  */

/*!
 * @brief CGM auxiliary clock selector.
 * Implements cgm_clk_sel_t_Class
 */
typedef uint8_t cgm_clk_sel_t;
#define SAF_CGM_SOURCE_SEL_IRCOSC           0U
#define SAF_CGM_SOURCE_SEL_XOSC             1U
#define SAF_CGM_SOURCE_SEL_PLL0_PHI0        2U
#define SAF_CGM_SOURCE_SEL_PLL1_PHI0        4U

/* @brief LFAST_SYS_PIN source selector.
   0U -  No LFAST module */
#define SAF_CGM_LFASTx_SOURCE_SYS_PIN    (5U)
#define SAF_CGM_LFASTx_SOURCE_LFAST_REF     5U


/* MC_ME index offsets */
#define MC_ME_RUN_PC0_INDEX                      0
#define MC_ME_RUN_PC1_INDEX                      1
#define MC_ME_RUN_PC2_INDEX                      2
#define MC_ME_RUN_PC3_INDEX                      3
#define MC_ME_RUN_PC4_INDEX                      4
#define MC_ME_RUN_PC5_INDEX                      5
#define MC_ME_RUN_PC6_INDEX                      6
#define MC_ME_RUN_PC7_INDEX                      7
#define MC_ME_LP_PC0_INDEX                       0
#define MC_ME_LP_PC1_INDEX                       1
#define MC_ME_LP_PC2_INDEX                       2
#define MC_ME_LP_PC3_INDEX                       3
#define MC_ME_LP_PC4_INDEX                       4
#define MC_ME_LP_PC5_INDEX                       5
#define MC_ME_LP_PC6_INDEX                       6
#define MC_ME_LP_PC7_INDEX                       7


typedef enum {
	CGM_DIVIDER_FORMAT_00 = 0U,		/*!< (DIV+1)/1    */
	CGM_DIVIDER_FORMAT_01 = 1U,		/*!< (DIV+1)/10   */
	CGM_DIVIDER_FORMAT_02 = 2U,		/*!< (DIV+1)/100  */
	CGM_DIVIDER_FORMAT_03 = 2U,		/*!< (DIV+1)/1000 */
}cgm_clk_div_fmt_t;
/*!
 * @brief CGM configuration structure.
 * Implements cgm_config_t_Class
 */
typedef struct
{
    hsm_clk_div_t        hsm_dc;              /*!< HSM clock divide */

    cgm_clk_div_t        sc_dc0;              /*!< CGM system clock divider 0.  */
    cgm_clk_div_t        sc_dc1;              /*!< CGM system clock divider 1.  */
    cgm_clk_div_t        sc_dc2;              /*!< CGM system clock divider 2.  */
    cgm_clk_div_t        sc_dc3;              /*!< CGM system clock divider 3.  */
    cgm_clk_div_t        sc_dc4;              /*!< CGM system clock divider 4.  */

    cgm_clk_sel_t       ac0_sc;               /*!< CGM auxiliary clock selector 0.                 */
    cgm_clk_div_t       ac0_dc0;              /*!< CGM auxiliary clock selector 0, first  divider  */
    cgm_clk_div_t       ac0_dc1;              /*!< CGM auxiliary clock selector 0, second divider  */
    cgm_clk_div_t       ac0_dc2;              /*!< CGM auxiliary clock selector 0, third  divider  */
    cgm_clk_div_t       ac0_dc3;              /*!< CGM auxiliary clock selector 0, fourth divider  */
    cgm_clk_div_fmt_t   ac3_dc0_fmt;		  /*!< CGM auxiliary clock selector 5, 0 Division Factor */
    cgm_clk_div_t       ac0_dc4;              /*!< CGM auxiliary clock selector 0, fifth divider  */

    cgm_clk_sel_t       ac1_sc;               /*!< CGM auxiliary clock selector 1.                 */
    cgm_clk_div_t       ac1_dc0;              /*!< CGM auxiliary clock selector 1, first  divider  */

    cgm_clk_sel_t       ac2_sc;               /*!< CGM auxiliary clock selector 2.                 */
    cgm_clk_div_t       ac2_dc0;              /*!< CGM auxiliary clock selector 2, first  divider  */
    cgm_clk_div_t       ac2_dc1;              /*!< CGM auxiliary clock selector 2, second divider  */

    cgm_clk_sel_t       ac3_sc;               /*!< CGM auxiliary clock selector 3.                 */

    cgm_clk_sel_t       ac4_sc;               /*!< CGM auxiliary clock selector 4.                 */

    cgm_clk_div_t       ac5_dc0;              /*!< CGM auxiliary clock selector 5, first  divider  */ // PSI5_f189_CLK
    cgm_clk_div_fmt_t   ac5_dc0_fmt;		  /*!< CGM auxiliary clock selector 5, 0 Division Factor */
    cgm_clk_div_t       ac5_dc1;              /*!< CGM auxiliary clock selector 5, second divider  */ // PSI5_f125_CLK
    cgm_clk_div_t       ac5_dc2;              /*!< CGM auxiliary clock selector 5, third divider   */ // PSI5_1us_CLK

    cgm_clk_div_t       ac5_cdc0;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_TS_CLK :ENABLE PSI5_1us
    cgm_clk_div_t       ac5_cdc1;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR_CLK :ENABLE PSI5_1us
    cgm_clk_div_t       ac5_cdc2;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK :ENABLE PSI5_1us

    cgm_clk_div_t       ac5_cdc10;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR0_CLK
    cgm_clk_div_t       ac5_cdc11;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR1_CLK
    cgm_clk_div_t       ac5_cdc12;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR2_CLK
    cgm_clk_div_t       ac5_cdc13;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_DDSR3_CLK

    cgm_clk_div_t       ac5_cdc20;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK0
    cgm_clk_div_t       ac5_cdc21;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK1
    cgm_clk_div_t       ac5_cdc22;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK2
    cgm_clk_div_t       ac5_cdc23;              /*!< CGM auxiliary clock selector 5, cashed configure divider  */ // PSI5_S_WD_CLK3

    cgm_clk_sel_t       ac6_sc;               /*!< CGM auxiliary clock selector 6.                 */
    cgm_clk_div_t       ac6_dc0;              /*!< CGM auxiliary clock selector 6, first  divider  */

    cgm_clk_sel_t       ac7_sc;               /*!< CGM auxiliary clock selector 7.                 */
    cgm_clk_div_t       ac7_dc0;              /*!< CGM auxiliary clock selector 7, first  divider  */

    cgm_clk_sel_t       ac8_sc;               /*!< CGM auxiliary clock selector 8.                 */
    cgm_clk_div_t       ac8_dc0;              /*!< CGM auxiliary clock selector 8, first  divider  */

    cgm_clk_sel_t       ac9_sc;               /*!< CGM auxiliary clock selector 9.                 */
    cgm_clk_div_t       ac9_dc0;              /*!< CGM auxiliary clock selector 9, first  divider  */

    cgm_clk_sel_t       ac10_sc;              /*!< CGM auxiliary clock selector 10.                */
    cgm_clk_div_t       ac10_dc0;             /*!< CGM auxiliary clock selector 10, first  divider */
} cgm_config_t;

#define SAF_MC_CGM_ACX_DIV_FMT_MASK                  0x0003u
#define SAF_MC_CGM_ACX_DIV_FMT_SHIFT                 0u
#define SAF_MC_CGM_ACX_DIV_FMT_WIDTH                 2u
#define SAF_MC_CGM_ACX_DIV_FMT(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_ACX_DIV_FMT_SHIFT))&SAF_MC_CGM_ACX_DIV_FMT_MASK)

/* SC_DC0 Bit Fields */
#define SAF_MC_CGM_SC_DC0_DIV_MASK                   0x3F0000u
#define SAF_MC_CGM_SC_DC0_DIV_SHIFT                  16u
#define SAF_MC_CGM_SC_DC0_DIV_WIDTH                  4u
#define SAF_MC_CGM_SC_DC0_DIV(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC0_DIV_SHIFT))&SAF_MC_CGM_SC_DC0_DIV_MASK)
#define SAF_MC_CGM_SC_DC0_DE_MASK                    0x80000000u
#define SAF_MC_CGM_SC_DC0_DE_SHIFT                   31u
#define SAF_MC_CGM_SC_DC0_DE_WIDTH                   1u
#define SAF_MC_CGM_SC_DC0_DE(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC0_DE_SHIFT))&SAF_MC_CGM_SC_DC0_DE_MASK)
/* SC_DC1 Bit Fields */
#define SAF_MC_CGM_SC_DC1_DIV_MASK                   0x3F0000u
#define SAF_MC_CGM_SC_DC1_DIV_SHIFT                  16u
#define SAF_MC_CGM_SC_DC1_DIV_WIDTH                  4u
#define SAF_MC_CGM_SC_DC1_DIV(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC1_DIV_SHIFT))&SAF_MC_CGM_SC_DC1_DIV_MASK)
#define SAF_MC_CGM_SC_DC1_DE_MASK                    0x80000000u
#define SAF_MC_CGM_SC_DC1_DE_SHIFT                   31u
#define SAF_MC_CGM_SC_DC1_DE_WIDTH                   1u
#define SAF_MC_CGM_SC_DC1_DE(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC1_DE_SHIFT))&SAF_MC_CGM_SC_DC1_DE_MASK)
/* SC_DC2 Bit Fields */
#define SAF_MC_CGM_SC_DC2_DIV_MASK                   0x3F0000u
#define SAF_MC_CGM_SC_DC2_DIV_SHIFT                  16u
#define SAF_MC_CGM_SC_DC2_DIV_WIDTH                  4u
#define SAF_MC_CGM_SC_DC2_DIV(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC2_DIV_SHIFT))&SAF_MC_CGM_SC_DC2_DIV_MASK)
#define SAF_MC_CGM_SC_DC2_DE_MASK                    0x80000000u
#define SAF_MC_CGM_SC_DC2_DE_SHIFT                   31u
#define SAF_MC_CGM_SC_DC2_DE_WIDTH                   1u
#define SAF_MC_CGM_SC_DC2_DE(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC2_DE_SHIFT))&SAF_MC_CGM_SC_DC2_DE_MASK)
/* SC_DC3 Bit Fields */
#define SAF_MC_CGM_SC_DC3_DIV_MASK                   0x3F0000u
#define SAF_MC_CGM_SC_DC3_DIV_SHIFT                  16u
#define SAF_MC_CGM_SC_DC3_DIV_WIDTH                  4u
#define SAF_MC_CGM_SC_DC3_DIV(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC3_DIV_SHIFT))&SAF_MC_CGM_SC_DC3_DIV_MASK)
#define SAF_MC_CGM_SC_DC3_DE_MASK                    0x80000000u
#define SAF_MC_CGM_SC_DC3_DE_SHIFT                   31u
#define SAF_MC_CGM_SC_DC3_DE_WIDTH                   1u
#define SAF_MC_CGM_SC_DC3_DE(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC3_DE_SHIFT))&SAF_MC_CGM_SC_DC3_DE_MASK)
/* SC_DC4 Bit Fields */
#define SAF_MC_CGM_SC_DC4_DIV_MASK                   0x3F0000u
#define SAF_MC_CGM_SC_DC4_DIV_SHIFT                  16u
#define SAF_MC_CGM_SC_DC4_DIV_WIDTH                  4u
#define SAF_MC_CGM_SC_DC4_DIV(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC4_DIV_SHIFT))&SAF_MC_CGM_SC_DC4_DIV_MASK)
#define SAF_MC_CGM_SC_DC4_DE_MASK                    0x80000000u
#define SAF_MC_CGM_SC_DC4_DE_SHIFT                   31u
#define SAF_MC_CGM_SC_DC4_DE_WIDTH                   1u
#define SAF_MC_CGM_SC_DC4_DE(x)                      (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_SC_DC4_DE_SHIFT))&SAF_MC_CGM_SC_DC4_DE_MASK)

/* AC0_SC Bit Fields */
#define SAF_MC_CGM_AC0_SC_SELCTL_MASK                0x7000000u
#define SAF_MC_CGM_AC0_SC_SELCTL_SHIFT               24u
#define SAF_MC_CGM_AC0_SC_SELCTL_WIDTH               3u
#define SAF_MC_CGM_AC0_SC_SELCTL(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_SC_SELCTL_SHIFT))&SAF_MC_CGM_AC0_SC_SELCTL_MASK)

/* AC0_DC0 Bit Fields */
#define SAF_MC_CGM_AC0_DC0_DIV_MASK                  0xF0000u
#define SAF_MC_CGM_AC0_DC0_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC0_DC0_DIV_WIDTH                 4u
#define SAF_MC_CGM_AC0_DC0_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC0_DIV_SHIFT))&SAF_MC_CGM_AC0_DC0_DIV_MASK)
#define SAF_MC_CGM_AC0_DC0_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC0_DC0_DE_SHIFT                  31u
#define SAF_MC_CGM_AC0_DC0_DE_WIDTH                  1u
#define SAF_MC_CGM_AC0_DC0_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC0_DE_SHIFT))&SAF_MC_CGM_AC0_DC0_DE_MASK)
/* AC0_DC1 Bit Fields */
#define SAF_MC_CGM_AC0_DC1_DIV_MASK                  0x7F0000u
#define SAF_MC_CGM_AC0_DC1_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC0_DC1_DIV_WIDTH                 7u
#define SAF_MC_CGM_AC0_DC1_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC1_DIV_SHIFT))&SAF_MC_CGM_AC0_DC1_DIV_MASK)
#define SAF_MC_CGM_AC0_DC1_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC0_DC1_DE_SHIFT                  31u
#define SAF_MC_CGM_AC0_DC1_DE_WIDTH                  1u
#define SAF_MC_CGM_AC0_DC1_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC1_DE_SHIFT))&SAF_MC_CGM_AC0_DC1_DE_MASK)
/* AC0_DC2 Bit Fields */
#define SAF_MC_CGM_AC0_DC2_DIV_MASK                  0x7F0000u
#define SAF_MC_CGM_AC0_DC2_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC0_DC2_DIV_WIDTH                 7u
#define SAF_MC_CGM_AC0_DC2_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC2_DIV_SHIFT))&SAF_MC_CGM_AC0_DC2_DIV_MASK)
#define SAF_MC_CGM_AC0_DC2_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC0_DC2_DE_SHIFT                  31u
#define SAF_MC_CGM_AC0_DC2_DE_WIDTH                  1u
#define SAF_MC_CGM_AC0_DC2_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC2_DE_SHIFT))&SAF_MC_CGM_AC0_DC2_DE_MASK)

/* AC0_DC3 Bit Fields */
#define SAF_MC_CGM_AC0_DC3_DIV_MASK                  0x1FF0000u
#define SAF_MC_CGM_AC0_DC3_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC0_DC3_DIV_WIDTH                 7u
#define SAF_MC_CGM_AC0_DC3_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC3_DIV_SHIFT))&SAF_MC_CGM_AC0_DC3_DIV_MASK)
#define SAF_MC_CGM_AC0_DC3_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC0_DC3_DE_SHIFT                  31u
#define SAF_MC_CGM_AC0_DC3_DE_WIDTH                  1u
#define SAF_MC_CGM_AC0_DC3_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC3_DE_SHIFT))&SAF_MC_CGM_AC0_DC3_DE_MASK)

/* AC0_DC4 Bit Fields */
#define SAF_MC_CGM_AC0_DC4_DIV_MASK                  0xF0000u
#define SAF_MC_CGM_AC0_DC4_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC0_DC4_DIV_WIDTH                 7u
#define SAF_MC_CGM_AC0_DC4_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC4_DIV_SHIFT))&SAF_MC_CGM_AC0_DC4_DIV_MASK)
#define SAF_MC_CGM_AC0_DC4_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC0_DC4_DE_SHIFT                  31u
#define SAF_MC_CGM_AC0_DC4_DE_WIDTH                  1u
#define SAF_MC_CGM_AC0_DC4_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC0_DC4_DE_SHIFT))&SAF_MC_CGM_AC0_DC4_DE_MASK)

/* AC1_DC0 Bit Fields */

#define SAF_MC_CGM_AC1_DC0_DIV_MASK                  0x7F0000u
#define SAF_MC_CGM_AC1_DC0_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC1_DC0_DIV_WIDTH                 7u
#define SAF_MC_CGM_AC1_DC0_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC1_DC0_DIV_SHIFT))&SAF_MC_CGM_AC1_DC0_DIV_MASK)
#define SAF_MC_CGM_AC1_DC0_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC1_DC0_DE_SHIFT                  31u
#define SAF_MC_CGM_AC1_DC0_DE_WIDTH                  1u
#define SAF_MC_CGM_AC1_DC0_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC1_DC0_DE_SHIFT))&SAF_MC_CGM_AC1_DC0_DE_MASK)

/* AC2_DC0 Bit Fields */
#define SAF_MC_CGM_AC2_DC0_DIV_MASK                  0x3F0000u
#define SAF_MC_CGM_AC2_DC0_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC2_DC0_DIV_WIDTH                 6u
#define SAF_MC_CGM_AC2_DC0_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC2_DC0_DIV_SHIFT))&SAF_MC_CGM_AC2_DC0_DIV_MASK)
#define SAF_MC_CGM_AC2_DC0_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC2_DC0_DE_SHIFT                  31u
#define SAF_MC_CGM_AC2_DC0_DE_WIDTH                  1u
#define SAF_MC_CGM_AC2_DC0_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC2_DC0_DE_SHIFT))&SAF_MC_CGM_AC2_DC0_DE_MASK)
/* AC2_DC1 Bit Fields */
#define SAF_MC_CGM_AC2_DC1_DIV_MASK                  0x3F0000u
#define SAF_MC_CGM_AC2_DC1_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC2_DC1_DIV_WIDTH                 6u
#define SAF_MC_CGM_AC2_DC1_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC2_DC1_DIV_SHIFT))&SAF_MC_CGM_AC2_DC1_DIV_MASK)
#define SAF_MC_CGM_AC2_DC1_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC2_DC1_DE_SHIFT                  31u
#define SAF_MC_CGM_AC2_DC1_DE_WIDTH                  1u
#define SAF_MC_CGM_AC2_DC1_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC2_DC1_DE_SHIFT))&SAF_MC_CGM_AC2_DC1_DE_MASK)


/* AC5_SC Bit Fields */
#define SAF_MC_CGM_AC5_SC_SELCTL_MASK                0x7000000u
#define SAF_MC_CGM_AC5_SC_SELCTL_SHIFT               24u
#define SAF_MC_CGM_AC5_SC_SELCTL_WIDTH               3u
#define SAF_MC_CGM_AC5_SC_SELCTL(x)                  (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_SC_SELCTL_SHIFT))&SAF_MC_CGM_AC5_SC_SELCTL_MASK)
/* AC5_SS Bit Fields */
#define SAF_MC_CGM_AC5_SS_SELSTAT_MASK               0x7000000u
#define SAF_MC_CGM_AC5_SS_SELSTAT_SHIFT              24u
#define SAF_MC_CGM_AC5_SS_SELSTAT_WIDTH              3u
#define SAF_MC_CGM_AC5_SS_SELSTAT(x)                 (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_SS_SELSTAT_SHIFT))&SAF_MC_CGM_AC5_SS_SELSTAT_MASK)

/* AC5_DC0 Bit Fields */
#define SAF_MC_CGM_AC5_DC0_DIV_MASK                  0x1FFF0000u
#define SAF_MC_CGM_AC5_DC0_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC5_DC0_DIV_WIDTH                 13u
#define SAF_MC_CGM_AC5_DC0_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_DC0_DIV_SHIFT))&SAF_MC_CGM_AC5_DC0_DIV_MASK)
#define SAF_MC_CGM_AC5_DC0_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC5_DC0_DE_SHIFT                  31u
#define SAF_MC_CGM_AC5_DC0_DE_WIDTH                  1u
#define SAF_MC_CGM_AC5_DC0_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_DC0_DE_SHIFT))&SAF_MC_CGM_AC5_DC0_DE_MASK)

/* AC5_DC1 Bit Fields */
#define SAF_MC_CGM_AC5_DC1_DIV_MASK                  0xFF0000u
#define SAF_MC_CGM_AC5_DC1_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC5_DC1_DIV_WIDTH                 8u
#define SAF_MC_CGM_AC5_DC1_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_DC1_DIV_SHIFT))&SAF_MC_CGM_AC5_DC1_DIV_MASK)
#define SAF_MC_CGM_AC5_DC1_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC5_DC1_DE_SHIFT                  31u
#define SAF_MC_CGM_AC5_DC1_DE_WIDTH                  1u
#define SAF_MC_CGM_AC5_DC1_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_DC1_DE_SHIFT))&SAF_MC_CGM_AC5_DC1_DE_MASK)

/* AC5_DC2 Bit Fields */
#define SAF_MC_CGM_AC5_DC2_DIV_MASK                  0x3FF0000u
#define SAF_MC_CGM_AC5_DC2_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC5_DC2_DIV_WIDTH                 10u
#define SAF_MC_CGM_AC5_DC2_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_DC2_DIV_SHIFT))&SAF_MC_CGM_AC5_DC2_DIV_MASK)
#define SAF_MC_CGM_AC5_DC2_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC5_DC2_DE_SHIFT                  31u
#define SAF_MC_CGM_AC5_DC2_DE_WIDTH                  1u
#define SAF_MC_CGM_AC5_DC2_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_DC2_DE_SHIFT))&SAF_MC_CGM_AC5_DC2_DE_MASK)

/* AC5_CDCx Bit Fields */
#define SAF_MC_CGM_AC5_CDCx_DIV_MASK                  0x3FF0000u
#define SAF_MC_CGM_AC5_CDCx_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC5_CDCx_DIV_WIDTH                 10u
#define SAF_MC_CGM_AC5_CDCx_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_CDCx_DIV_SHIFT))&SAF_MC_CGM_AC5_CDCx_DIV_MASK)
#define SAF_MC_CGM_AC5_CDCx_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC5_CDCx_DE_SHIFT                  31u
#define SAF_MC_CGM_AC5_CDCx_DE_WIDTH                  1u
#define SAF_MC_CGM_AC5_CDCx_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC5_CDCx_DE_SHIFT))&SAF_MC_CGM_AC5_CDCx_DE_MASK)


/* AC6_DC0 Bit Fields */
#define SAF_MC_CGM_AC6_DC0_DIV_MASK                  0x1FF0000u
#define SAF_MC_CGM_AC6_DC0_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC6_DC0_DIV_WIDTH                 9u
#define SAF_MC_CGM_AC6_DC0_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC6_DC0_DIV_SHIFT))&SAF_MC_CGM_AC6_DC0_DIV_MASK)
#define SAF_MC_CGM_AC6_DC0_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC6_DC0_DE_SHIFT                  31u
#define SAF_MC_CGM_AC6_DC0_DE_WIDTH                  1u
#define SAF_MC_CGM_AC6_DC0_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC6_DC0_DE_SHIFT))&SAF_MC_CGM_AC6_DC0_DE_MASK)

/* AC7_DC0 Bit Fields */
#define SAF_MC_CGM_AC7_DC0_DIV_MASK                  0x1FF0000u
#define SAF_MC_CGM_AC7_DC0_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC7_DC0_DIV_WIDTH                 9u
#define SAF_MC_CGM_AC7_DC0_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC7_DC0_DIV_SHIFT))&SAF_MC_CGM_AC7_DC0_DIV_MASK)
#define SAF_MC_CGM_AC7_DC0_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC7_DC0_DE_SHIFT                  31u
#define SAF_MC_CGM_AC7_DC0_DE_WIDTH                  1u
#define SAF_MC_CGM_AC7_DC0_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC7_DC0_DE_SHIFT))&SAF_MC_CGM_AC7_DC0_DE_MASK)

/* AC8_DC0 Bit Fields */
#define SAF_MC_CGM_AC8_DC0_DIV_MASK                  0x3F0000u
#define SAF_MC_CGM_AC8_DC0_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC8_DC0_DIV_WIDTH                 6u
#define SAF_MC_CGM_AC8_DC0_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC8_DC0_DIV_SHIFT))&SAF_MC_CGM_AC8_DC0_DIV_MASK)
#define SAF_MC_CGM_AC8_DC0_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC8_DC0_DE_SHIFT                  31u
#define SAF_MC_CGM_AC8_DC0_DE_WIDTH                  1u
#define SAF_MC_CGM_AC8_DC0_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC8_DC0_DE_SHIFT))&SAF_MC_CGM_AC8_DC0_DE_MASK)

/* AC9_DC0 Bit Fields */
#define SAF_MC_CGM_AC9_DC0_DIV_MASK                  0x3F0000u
#define SAF_MC_CGM_AC9_DC0_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC9_DC0_DIV_WIDTH                 6u
#define SAF_MC_CGM_AC9_DC0_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC9_DC0_DIV_SHIFT))&SAF_MC_CGM_AC9_DC0_DIV_MASK)
#define SAF_MC_CGM_AC9_DC0_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC9_DC0_DE_SHIFT                  31u
#define SAF_MC_CGM_AC9_DC0_DE_WIDTH                  1u
#define SAF_MC_CGM_AC9_DC0_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC9_DC0_DE_SHIFT))&SAF_MC_CGM_AC9_DC0_DE_MASK)

/* AC10_DC0 Bit Fields */
#define SAF_MC_CGM_AC10_DC0_DIV_MASK                  0xF0000u
#define SAF_MC_CGM_AC10_DC0_DIV_SHIFT                 16u
#define SAF_MC_CGM_AC10_DC0_DIV_WIDTH                 4u
#define SAF_MC_CGM_AC10_DC0_DIV(x)                    (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC10_DC0_DIV_SHIFT))&SAF_MC_CGM_AC10_DC0_DIV_MASK)
#define SAF_MC_CGM_AC10_DC0_DE_MASK                   0x80000000u
#define SAF_MC_CGM_AC10_DC0_DE_SHIFT                  31u
#define SAF_MC_CGM_AC10_DC0_DE_WIDTH                  1u
#define SAF_MC_CGM_AC10_DC0_DE(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_CGM_AC10_DC0_DE_SHIFT))&SAF_MC_CGM_AC10_DC0_DE_MASK)

/*! @brief Clock names. */
typedef enum {
    /* Clock sources */
	SAF_IRCOSC_CLK                     = 0u,      /*!< IRCOSC_CLK clock source                */
	SAF_XOSC_CLK                       = 1u,      /*!< XOSC_CLK clock source                  */
	SAF_PLL0_PHI0_CLK                  = 2u,      /*!< PLL0_PHI0_CLK clock source             */
	SAF_PLL0_PHI1_CLK                  = 3u,      /*!< PLL0_PHI1_CLK clock source             */
	SAF_PLL1_PHI0_CLK                  = 4u,      /*!< PLL1_PHI0_CLK clock source             */
	SAF_END_OF_CLK_SOURCES             = 10u,      /*!< End of clock sources                  */
    /* System and common clocks */
	SAF_PBRIDGEx_CLK                   = 11u,      /*!< PBRIDGEx_CLK common clock             */
	SAF_FXBAR_CLK                      = 12u,      /*!< FXBAR_CLK common clock                */
	SAF_BD_CLK                         = 13u,      /*!< BD_CLK common clock                   */
	SAF_IOP_CLK                        = 14u,      /*!< IOP_CLK common clock                  */
	SAF_SXBAR_CLK                      = 15u,      /*!< SXBAR_CLK common clock                */
	SAF_CORE_CLK                       = 16u,      /*!< CORE_CLK                              */
	SAF_CHKR_CLK                       = 17u,      /*!< CHKR_CLK                              */
	SAF_HSM_CLK                        = 18u,      /*!< HSM_CLK common clock              */
	SAF_CLKOUT0                        = 19u,      /*!< CLKOUT0_CLK common clock              */
	SAF_END_OF_SYSTEM_CLKS             = 20u,      /*!< End of common and system clocks       */
	SAF_PER_CLK                        = 21u,      /*!< PER_CLK common clock                  */
	SAF_ADCSD_CLK                      = 22u,      /*!< ADCSD1_CLK clock source               */
	SAF_ADCSAR_CLK                     = 23u,      /*!< ADCSD1_CLK clock source               */
	SAF_DSPI_A_CLK                     = 24u,      /*!< DSPI_CLK  4/5/6 clock source          */
	SAF_DSPI_B_CLK                     = 25u,      /*!< DSPI_CLK  0/1/2/3/12 clock source     */
	SAF_LIN_CLK                        = 26u,      /*!< LIN_CLK clock source                  */
	SAF_PSI5_S_CLK                     = 27u,      /*!< PSI_5_CLK clock source                */
	SAF_END_OF_AC0_CLK				   = 30,	   /*!< End of AC0 clocks       			  */
	SAF_SYS0_CLK                       = 41u,      /*!< SYS0_CLK clock source                 */
	SAF_END_OF_AC6_CLK				   = 50u,	   /*!< End of AC6 clocks       			  */
	SAF_SYS1_CLK                       = 51u,      /*!< SYS1_CLK clock source                 */
	SAF_END_OF_AC7_CLK				   = 60u,	   /*!< End of AC7 clocks       			  */
	SAF_LFAST_CLK                      = 61u,      /*!< LFAST_CLK clock source                */
	SAF_I2C0_CLK                       = 64u,      /*!< I2C0_CLK clock source                */
	SAF_I2C1_CLK                       = 65u,      /*!< I2C1_CLK clock source                */
	SAF_END_OF_AC1_CLK				   = 70u,	   /*!< End of AC1 clocks       			  */
	SAF_FlexRay_CLK					   = 71u,	   /*!< FlexRay_CLK clock source              */
	SAF_SENT_CLK                       = 72u,      /*!< SENT_CLK clock source                 */
	SAF_END_OF_AC2_CLK				   = 80u,	   /*!< End of AC2 clocks       			  */
	SAF_PSI5_f189_CLK                  = 81u,      /*!< PSI5_f189_CLK clock source            */
	SAF_PSI5_f125_CLK                  = 82u,      /*!< PSI5_f125__CLK clock source           */
	SAF_PSI5_1us_CLK                   = 83u,      /*!< PSI5_1us__CLK clock source            */
	SAF_PSI5_S_TS_CLK                  = 84u,      /*!< PSI5_S_TS_CLK clock source            */
	SAF_PSI5_S_DDSR0_CLK               = 85u,      /*!< PSI5_S_DDSR0_CLK clock source         */
	SAF_PSI5_S_DDSR1_CLK               = 86u,      /*!< PSI5_S_DDSR1_CLK clock source         */
	SAF_PSI5_S_DDSR2_CLK               = 87u,      /*!< PSI5_S_DDSR2_CLK clock source         */
	SAF_PSI5_S_DDSR3_CLK               = 88u,      /*!< PSI5_S_DDSR3_CLK clock source         */
	SAF_PSI5_S_WD0_CLK                 = 89u,      /*!< PSI5_S_WD0_CLK clock source           */
	SAF_PSI5_S_WD1_CLK                 = 90u,      /*!< PSI5_S_WD1_CLK clock source           */
	SAF_PSI5_S_WD2_CLK                 = 91u,      /*!< PSI5_S_WD2_CLK clock source           */
	SAF_PSI5_S_WD3_CLK                 = 92u,      /*!< PSI5_S_WD3_CLK clock source           */
	SAF_END_OF_PSI5_CLK                = 93u,      /*!< PSI5_S_WD3_CLK clock source           */
	SAF_TXCLK_REF_CLK                  = 94u,	   /*!< TXCLK_REF_CLK clock source            */
	SAF_CAN_CLK                        = 95u,	   /*!< M_CAN_CLK clock source                */
	SAF_RTI_CLK                        = 96u,	   /*!< M_CAN_CLK clock source                */
	SAF_END_OF_PERIPHERAL_CLKS         = 97u,      /*!< End of peripheral clocks             */
} saf_clock_names_t;

/*! @brief Clock names. */
typedef enum {
    /* peripheral name */
 SAF_MC_ME_PCTL_EBI0_INDEX                    = 3u,
 SAF_MC_ME_PCTL_LFAST_INDEX                   = 9u,
 SAF_MC_ME_PCTL_SIPI0_INDEX					  = 11u,
 SAF_MC_ME_PCTL_SIUL_INDEX                    = 15u,
 SAF_MC_ME_PCTL_PIT_RTC_0_INDEX               = 30u,
 SAF_MC_ME_PCTL_PIT_RTC_1_INDEX               = 31u,
 SAF_MC_ME_PCTL_DMAMUX_INDEX                  = 36u,
 SAF_MC_ME_PCTL_CRC_0_INDEX                   = 38u,
 SAF_MC_ME_PCTL_ADCSD_8_INDEX                 = 56u,
 SAF_MC_ME_PCTL_ADCSD_6_INDEX                 = 57u,
 SAF_MC_ME_PCTL_ADCSD_4_INDEX                 = 58u,
 SAF_MC_ME_PCTL_ADCSD_2_INDEX                 = 59u,
 SAF_MC_ME_PCTL_ADCSD_0_INDEX                 = 60u,
 SAF_MC_ME_PCTL_MCAN4_INDEX                   = 67u,
 SAF_MC_ME_PCTL_MCAN3_INDEX                   = 68u,
 SAF_MC_ME_PCTL_MCAN2_INDEX                   = 69u,
 SAF_MC_ME_PCTL_MCAN1_INDEX                   = 70u,
 SAF_MC_ME_PCTL_TTCAN_INDEX                   = 72u,
 SAF_MC_ME_PCTL_CAN_RAM_CTRL_INDEX            = 74u,
 SAF_MC_ME_PCTL_LINFlexD_16_INDEX             = 84u,
 SAF_MC_ME_PCTL_LINFlexD_14_INDEX             = 85u,
 SAF_MC_ME_PCTL_LINFlexD_1_INDEX              = 91u,
 SAF_MC_ME_PCTL_LINFlexD_0_INDEX              = 92u,
 SAF_MC_ME_PCTL_DSPI_12_INDEX                 = 93u,
 SAF_MC_ME_PCTL_DSPI_6_INDEX                  = 96u,
 SAF_MC_ME_PCTL_DSPI_4_INDEX                  = 97u,
 SAF_MC_ME_PCTL_DSPI_1_INDEX                  = 98u,
 SAF_MC_ME_PCTL_DSPI_0_INDEX                  = 99u,
 SAF_MC_ME_PCTL_IIC_0_INDEX                   = 101u,
 SAF_MC_ME_PCTL_SENT_INDEX                    = 104u,
 SAF_MC_ME_PCTL_FLEXRAY_0_INDEX               = 107u,
 SAF_MC_ME_PCTL_PSI5_0_INDEX               	  = 111u,
 SAF_MC_ME_PCTL_ADCSAR_b_INDEX                = 112u,
 SAF_MC_ME_PCTL_ADCSAR_4_INDEX                = 123u,
 SAF_MC_ME_PCTL_ADCSAR_0_INDEX                = 127u,
 SAF_MC_ME_PCTL_GTMINT_INDEX                  = 128u,
 SAF_MC_ME_PCTL_PSI5_S_0_INDEX                = 162u,
 SAF_MC_ME_PCTL_CRC_1_INDEX                   = 166u,
 SAF_MC_ME_PCTL_ADCSD_9_INDEX                 = 184u,
 SAF_MC_ME_PCTL_ADCSD_7_INDEX                 = 185u,
 SAF_MC_ME_PCTL_ADCSD_5_INDEX                 = 186u,
 SAF_MC_ME_PCTL_ADCSD_3_INDEX                 = 187u,
 SAF_MC_ME_PCTL_ADCSD_1_INDEX                 = 188u,
 SAF_MC_ME_PCTL_LINFlexD_15_INDEX             = 213u,
 SAF_MC_ME_PCTL_LINFlexD_2_INDEX              = 220u,
 SAF_MC_ME_PCTL_DSPI_5_INDEX                  = 225u,
 SAF_MC_ME_PCTL_DSPI_3_INDEX                  = 226u,
 SAF_MC_ME_PCTL_DSPI_2_INDEX                  = 227u,
 SAF_MC_ME_PCTL_IIC_1_INDEX                   = 229u,
 SAF_MC_ME_PCTL_SENT_1_INDEX                  = 232u,
 SAF_MC_ME_PCTL_FLEXRAY_1_INDEX               = 235u,
 SAF_MC_ME_PCTL_PSI5_1_INDEX                  = 239u,
 SAF_MC_ME_PCTL_ADCSAR_10_INDEX               = 245u,
 SAF_MC_ME_PCTL_ADCSAR_9_INDEX                = 246u,
 SAF_MC_ME_PCTL_ADCSAR_8_INDEX                = 247u,
 SAF_MC_ME_PCTL_ADCSAR_7_INDEX                = 248u,
 SAF_MC_ME_PCTL_ADCSAR_6_INDEX                = 249u,
 SAF_MC_ME_PCTL_ADCSAR_5_INDEX                = 250u,
 SAF_MC_ME_PCTL_ADCSAR_3_INDEX                = 252u,
 SAF_MC_ME_PCTL_ADCSAR_2_INDEX                = 253u,
 SAF_MC_ME_PCTL_ADCSAR_1_INDEX                = 254u,
 SAF_MC_ME_PCTLn_COUNT                        = 256u,
} peripheral_names_t;

/** MC_ME - Size of Registers Arrays */
#define MC_ME_RUN_PC_COUNT                       8u
#define MC_ME_LP_PC_COUNT                        8u
#define SAF_MC_ME_INVALID_INDEX  SAF_MC_ME_PCTLn_COUNT


/* MCTL Bit Fields */
#define SAF_MC_ME_MCTL_KEY_MASK                      0xFFFFu
#define SAF_MC_ME_MCTL_KEY_SHIFT                     0u
#define SAF_MC_ME_MCTL_KEY_WIDTH                     16u
#define SAF_MC_ME_MCTL_KEY(x)                        (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_MCTL_KEY_SHIFT))&SAF_MC_ME_MCTL_KEY_MASK)
#define SAF_MC_ME_MCTL_TARGET_MODE_MASK              0xF0000000u
#define SAF_MC_ME_MCTL_TARGET_MODE_SHIFT             28u
#define SAF_MC_ME_MCTL_TARGET_MODE_WIDTH             4u
#define SAF_MC_ME_MCTL_TARGET_MODE(x)                (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_MCTL_TARGET_MODE_SHIFT))&SAF_MC_ME_MCTL_TARGET_MODE_MASK)

/* PCTLn Bit Fields */
#define SAF_MC_ME_PCTLn_RUN_CFG_MASK                 0x7u
#define SAF_MC_ME_PCTLn_RUN_CFG_SHIFT                0u
#define SAF_MC_ME_PCTLn_RUN_CFG_WIDTH                3u
#define SAF_MC_ME_PCTLn_RUN_CFG(x)                   (((uint8_t)(((uint8_t)(x))<<SAF_MC_ME_PCTLn_RUN_CFG_SHIFT))&SAF_MC_ME_PCTLn_RUN_CFG_MASK)
#define SAF_MC_ME_PCTLn_LP_CFG_MASK                  0x38u
#define SAF_MC_ME_PCTLn_LP_CFG_SHIFT                 3u
#define SAF_MC_ME_PCTLn_LP_CFG_WIDTH                 3u
#define SAF_MC_ME_PCTLn_LP_CFG(x)                    (((uint8_t)(((uint8_t)(x))<<SAF_MC_ME_PCTLn_LP_CFG_SHIFT))&SAF_MC_ME_PCTLn_LP_CFG_MASK)

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * @brief Enabled clock sources structure. Indicates what clock sources are enabled for a particular power mode.
 * Implements mc_me_clk_srcs_t_Class
 */
typedef struct
{
	boolean irc0;                                      /*!< Internal RC oscillator 0 is switched on */
	boolean xosc0;                                     /*!< External RC oscillator 0 is switched on */
	boolean pll0;                                      /*!< PLL0 is switched on */
	boolean pll1;                                      /*!< PLL1 is switched on */

} mc_me_clk_srcs_t;

/*!
 * @brief CGM auxiliary clock selector.
 * Implements cgm_sys_clk_src_t_Class
 */
typedef uint8_t cgm_sys_clk_src_t;
#define CGM_SYSTEM_CLOCK_SRC_IRCOSC     0U       /*!< IRCOSC. */
#define CGM_SYSTEM_CLOCK_SRC_XOSC       1U       /*!< XOSC. */
#define CGM_SYSTEM_CLOCK_SRC_PLL_PHI0   2U       /*!< PLL PHI_0. */
#define CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0  2U       /*!< Primary PLL PHI_0. */
#define CGM_SYSTEM_CLOCK_SRC_PLL1_PHI0  4U       /*!< Secondary PLL1 PHI_0. */
#define CGM_SYSTEM_CLOCK_SRC_NONE       15U      /*!< NONE. */

/*!
 * @brief Mode configuration structure. System clock source and enabled clock sources for a mode.
 * Implements mc_me_mode_config_t_Class
 */
typedef struct
{
    cgm_sys_clk_src_t          sysclk;         /*!< System clock source */
    mc_me_clk_srcs_t           clocksEnabled;  /*!< Enabled clock sources (struct) */
} mc_me_mode_config_t;

/*!
 * @brief Mode configuration structure. System clock source and enabled clock sources for a mode.
 * Implements mc_me_mode_config_t_Class
 */
typedef struct
{
    boolean test;
    boolean run1;
    boolean run2;
    boolean run3;
    boolean halt0;
    boolean stop0;
} mc_me_me_config_t;

#ifndef SAFETY_ENABLE
typedef struct MC_ME_tag                        MC_ME_Type;/*PRQA S 0631*/
#endif

/* MC_CGM - Peripheral instance base addresses */
/** Peripheral MC_CGM base address */
#define SAF_MC_ME_BASE                              ((uint32_t)0xFFFB8000UL)
/** Peripheral MC_CGM base pointer */
#define SAF_MC_ME_StPtr                             ((MC_ME_Type *) SAF_MC_ME_BASE)
/** Array initializer of MC_CGM peripheraSAF_MC_CGM addresses */
#define SAF_MC_ME_BASE_ADDRS                        { SAF_MC_ME_BASE }
/** Array initializer of MC_CGM peripheral base pointers */
#define SAF_MC_ME_BASE_PTRS                         { SAF_MC_ME_StPtr }

/*!
 * @addtogroup MC_ME_Register_Masks MC_ME Register Masks
 * @{
 */

/* GS Bit Fields */
#define SAF_MC_ME_GS_S_SYSCLK_MASK                   0xFu
#define SAF_MC_ME_GS_S_SYSCLK_SHIFT                  0u
#define SAF_MC_ME_GS_S_SYSCLK_WIDTH                  4u
#define SAF_MC_ME_GS_S_SYSCLK(x)                     (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_GS_S_SYSCLK_SHIFT))&SAF_MC_ME_GS_S_SYSCLK_MASK)
#define SAF_MC_ME_GS_S_IRC_MASK                      0x10u
#define SAF_MC_ME_GS_S_IRC_SHIFT                     4u
#define SAF_MC_ME_GS_S_IRC_WIDTH                     1u
#define SAF_MC_ME_GS_S_IRC(x)                        (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_GS_S_IRC_SHIFT))&SAF_MC_ME_GS_S_IRC_MASK)
#define SAF_MC_ME_GS_S_XOSC_MASK                     0x20u
#define SAF_MC_ME_GS_S_XOSC_SHIFT                    5u
#define SAF_MC_ME_GS_S_XOSC_WIDTH                    1u
#define SAF_MC_ME_GS_S_XOSC(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_GS_S_XOSC_SHIFT))&SAF_MC_ME_GS_S_XOSC_MASK)
#define SAF_MC_ME_GS_S_PLL0_MASK                     0x40u
#define SAF_MC_ME_GS_S_PLL0_SHIFT                    6u
#define SAF_MC_ME_GS_S_PLL0_WIDTH                    1u
#define SAF_MC_ME_GS_S_PLL0(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_GS_S_PLL0_SHIFT))&SAF_MC_ME_GS_S_PLL0_MASK)
#define SAF_MC_ME_GS_S_PLL1_MASK                     0x80u
#define SAF_MC_ME_GS_S_PLL1_SHIFT                    7u
#define SAF_MC_ME_GS_S_PLL1_WIDTH                    1u
#define SAF_MC_ME_GS_S_PLL1(x)                       (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_GS_S_PLL1_SHIFT))&SAF_MC_ME_GS_S_PLL1_MASK)

/* ME Bit Fields */
#define SAF_MC_ME_ME_RESET_FUNC_MASK                 0x1u
#define SAF_MC_ME_ME_RESET_FUNC_SHIFT                0u
#define SAF_MC_ME_ME_RESET_FUNC_WIDTH                1u
#define SAF_MC_ME_ME_RESET_FUNC(x)                   (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_RESET_FUNC_SHIFT))&SAF_MC_ME_ME_RESET_FUNC_MASK)
#define SAF_MC_ME_ME_TEST_MASK                       0x2u
#define SAF_MC_ME_ME_TEST_SHIFT                      1u
#define SAF_MC_ME_ME_TEST_WIDTH                      1u
#define SAF_MC_ME_ME_TEST(x)                         (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_TEST_SHIFT))&SAF_MC_ME_ME_TEST_MASK)
#define SAF_MC_ME_ME_SAFE_MASK                       0x4u
#define SAF_MC_ME_ME_SAFE_SHIFT                      2u
#define SAF_MC_ME_ME_SAFE_WIDTH                      1u
#define SAF_MC_ME_ME_SAFE(x)                         (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_SAFE_SHIFT))&SAF_MC_ME_ME_SAFE_MASK)
#define SAF_MC_ME_ME_DRUN_MASK                       0x8u
#define SAF_MC_ME_ME_DRUN_SHIFT                      3u
#define SAF_MC_ME_ME_DRUN_WIDTH                      1u
#define SAF_MC_ME_ME_DRUN(x)                         (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_DRUN_SHIFT))&SAF_MC_ME_ME_DRUN_MASK)
#define SAF_MC_ME_ME_RUN0_MASK                       0x10u
#define SAF_MC_ME_ME_RUN0_SHIFT                      4u
#define SAF_MC_ME_ME_RUN0_WIDTH                      1u
#define SAF_MC_ME_ME_RUN0(x)                         (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_RUN0_SHIFT))&SAF_MC_ME_ME_RUN0_MASK)
#define SAF_MC_ME_ME_RUN1_MASK                       0x20u
#define SAF_MC_ME_ME_RUN1_SHIFT                      5u
#define SAF_MC_ME_ME_RUN1_WIDTH                      1u
#define SAF_MC_ME_ME_RUN1(x)                         (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_RUN1_SHIFT))&SAF_MC_ME_ME_RUN1_MASK)
#define SAF_MC_ME_ME_RUN2_MASK                       0x40u
#define SAF_MC_ME_ME_RUN2_SHIFT                      6u
#define SAF_MC_ME_ME_RUN2_WIDTH                      1u
#define SAF_MC_ME_ME_RUN2(x)                         (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_RUN2_SHIFT))&SAF_MC_ME_ME_RUN2_MASK)
#define SAF_MC_ME_ME_RUN3_MASK                       0x80u
#define SAF_MC_ME_ME_RUN3_SHIFT                      7u
#define SAF_MC_ME_ME_RUN3_WIDTH                      1u
#define SAF_MC_ME_ME_RUN3(x)                         (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_RUN3_SHIFT))&SAF_MC_ME_ME_RUN3_MASK)

#define SAF_MC_ME_ME_HALT0_MASK                      0x100u
#define SAF_MC_ME_ME_HALT0_SHIFT                     8u
#define SAF_MC_ME_ME_HALT0_WIDTH                     1u
#define SAF_MC_ME_ME_HALT0(x)                        (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_HALT0_SHIFT))&SAF_MC_ME_ME_HALT0_MASK)
#define SAF_MC_ME_ME_STOP0_MASK                      0x400u
#define SAF_MC_ME_ME_STOP0_SHIFT                     10u
#define SAF_MC_ME_ME_STOP0_WIDTH                     1u
#define SAF_MC_ME_ME_STOP0(x)                        (((uint32_t)(((uint32_t)(x))<<SAF_MC_ME_ME_STOP0_SHIFT))&SAF_MC_ME_ME_STOP0_MASK)


typedef enum
{
    saf_me_mc_reset_mode      = 0x0,
	saf_me_mc_test_mode       = 0x1,
	saf_me_mc_safe_mode       = 0x2,
	saf_me_mc_drun_mode       = 0x3,
	saf_me_mc_run0_mode       = 0x4,
	saf_me_mc_run1_mode       = 0x5,
	saf_me_mc_run2_mode       = 0x6,
	saf_me_mc_run3_mode       = 0x7,
	saf_me_mc_halt0_mode      = 0x8,
	saf_me_mc_stop0_mode      = 0xA,
	saf_me_mc_mode_notchange,/*PRQA S 0722*/
}mode_config_t;/*PRQA S 0723*/
/*!
 * @brief Running modes peripheral configuration
 * Implements mc_me_run_periph_config_t_Class
 */
typedef struct
{
	boolean reset;
	boolean test;
	boolean safe;
	boolean drun;
	boolean run0;
	boolean run1;
	boolean run2;
	boolean run3;
} mc_me_run_periph_config_t;

/*!
 * @brief Low power modes peripheral configuration
 * Implements mc_me_low_periph_config_t_Class
 */
typedef struct
{
	boolean stop0;
	boolean halt0;

} mc_me_low_periph_config_t;

/*!
 * @brief Peripheral configuration enum. Used to specify one of the available peripheral configurations.
 * Implements mc_me_periph_config_t_Class
 */
typedef enum
{
    SAF_MC_ME_PERIPH_CONFIG_0,              /*!< Peripheral configuration 0 */
    SAF_MC_ME_PERIPH_CONFIG_1,              /*!< Peripheral configuration 1 */
    SAF_MC_ME_PERIPH_CONFIG_2,              /*!< Peripheral configuration 2 */
    SAF_MC_ME_PERIPH_CONFIG_3,              /*!< Peripheral configuration 3 */
    SAF_MC_ME_PERIPH_CONFIG_4,              /*!< Peripheral configuration 4 */
    SAF_MC_ME_PERIPH_CONFIG_5,              /*!< Peripheral configuration 5 */
    SAF_MC_ME_PERIPH_CONFIG_6,              /*!< Peripheral configuration 6 */
    SAF_MC_ME_PERIPH_CONFIG_7,              /*!< Peripheral configuration 7 */
    SAF_MC_ME_PERIPH_CONFIG_COUNT           /*!< Peripheral configuration count */
} mc_me_periph_config_t;


/*! @brief MC_ME peripheral instance clock configuration.
 *  Implements mc_me_peripheral_clock_config_t_Class
 */
typedef struct
{
    /* clockName   is the name of the peripheral clock
     *    must be one of the following values
     *    DMA0_CLK
     *    MPU0_CLK
     *    ...
     *    LPUART3_CLK
     */
    peripheral_names_t clockName;
    mc_me_periph_config_t mc_me_RunPeriphConfig;               /*!< Peripheral clock gating in running mode. */
    mc_me_periph_config_t mc_me_LowPowerPeriphConfig;          /*!< Peripheral clock gating in low-power mode. */

}mc_me_peripheral_clock_config_t;

#define SAF_MC_ME_PERIPH_INSTANCE_COUNT 61U

/*! @brief MC_ME configuration.
 *  Implements mc_me_config_t_Class
 */
typedef struct
{
	mc_me_me_config_t me;					/*!< MODE ENABLE.   */
    mc_me_mode_config_t reset;               /*!< MC_ME_RESET.   */
    mc_me_mode_config_t test;                /*!< MC_ME_TEST.    */
    mc_me_mode_config_t safe;                /*!< MC_ME_SAFE.    */
    mc_me_mode_config_t drun;                /*!< MC_ME_DRUN.    */
    mc_me_mode_config_t run0;                /*!< MC_ME_RUN0.    */
    mc_me_mode_config_t run1;                /*!< MC_ME_RUN1.    */
    mc_me_mode_config_t run2;                /*!< MC_ME_RUN2.    */
    mc_me_mode_config_t run3;                /*!< MC_ME_RUN3.    */
    mc_me_mode_config_t stop0;               /*!< MC_ME_STOP.    */

    mc_me_mode_config_t halt0;               /*!< MC_ME_HALT.    */

    mc_me_run_periph_config_t periphRunConfig[SAF_MC_ME_PERIPH_CONFIG_COUNT];      /*!< Run peripheral configurations          */
    mc_me_low_periph_config_t periphLowPowerConfig[SAF_MC_ME_PERIPH_CONFIG_COUNT]; /*!< Low power peripheral configurations    */

    uint32_t count;                                          /*!< Number of peripherals to be configured.               */
    mc_me_peripheral_clock_config_t peripherals[SAF_MC_ME_PERIPH_INSTANCE_COUNT];            /*!< Pointer to the mc_me peripheral clock configurations array. */

} mc_me_config_t;



#define MC_ME_COMPLETE_TRANSITION_TIMEOUT 10000000U

#define CMU_INSTANCE_COUNT 13U

#ifndef SAFETY_ENABLE
typedef  struct CMU_tag                   CMU_Type;/*PRQA S 0631*/
#endif

/* MC_CGM - Peripheral instance base addresses */
/** Peripheral MC_CGM base address */
#define CMU_PLL_BASE                                (0xFFFB0200u)
#define CMU_FXBAR_BASE                              (0xFBFB0200u)
#define CMU_SXBAR_BASE                              (0xFBFB0240u)
#define CMU_PBRIDGE_BASE                            (0xFBFB0280u)
#define CMU_PER_BASE                                (0xFBFB02C0u)
#define CMU_ADCSD_BASE                              (0xFBFB0300u)
#define CMU_ADCSAR_BASE                             (0xFBFB0340u)
#define CMU_SENT_BASE                               (0xFBFB0380u)
#define CMU_PSI5_F189_BASE                          (0xFBFB03C0u)
#define CMU_PSI5_F125_BASE                          (0xFBFB0400u)
#define CMU_PSI5_1uS_BASE                           (0xFBFB0440u)
#define CMU_CORE_BASE                               (0xFBFB0480u)
#define CMU_CLKOUT_BASE                             (0xFBFB04C0u)

/** Peripheral MC_CGM base pointer */
#define CMU_0                             ((CMU_Type *)CMU_PLL_BASE)
#define CMU_1                             ((CMU_Type *)CMU_FXBAR_BASE)
#define CMU_2                             ((CMU_Type *)CMU_SXBAR_BASE)
#define CMU_3                             ((CMU_Type *)CMU_PBRIDGE_BASE)
#define CMU_4                             ((CMU_Type *)CMU_PER_BASE)
#define CMU_5                             ((CMU_Type *)CMU_ADCSD_BASE)
#define CMU_6                             ((CMU_Type *)CMU_ADCSAR_BASE)
#define CMU_7                             ((CMU_Type *)CMU_SENT_BASE)
#define CMU_8                             ((CMU_Type *)CMU_PSI5_F189_BASE)
#define CMU_9                             ((CMU_Type *)CMU_PSI5_F125_BASE)
#define CMU_10                            ((CMU_Type *)CMU_PSI5_1uS_BASE)
#define CMU_11                            ((CMU_Type *)CMU_CORE_BASE)
#define CMU_12                            ((CMU_Type *)CMU_CLKOUT_BASE)


#define FIRST_CMU                                    CMU_0
#define FEATURE_HAS_RCDIV                            0
#define CMU_BASE_PTRS                                {CMU_0, CMU_1, CMU_2, CMU_3, CMU_4, CMU_5, CMU_6, CMU_7, CMU_8 ,CMU_9, CMU_10, CMU_11 , CMU_12 }
#define CMU_RESET_DIVIDER_VALUE                      0x03


#define CMU_ISR_OLRI_MASK                        0x1u
#define CMU_ISR_FLLI_MASK                        0x2u
#define CMU_ISR_FHHI_MASK                        0x4u
/*!
 * @brief CMU IRCOSC low frequency divider.
 * Implements cmu_ircosc_divider_t_Class
 */
typedef enum
{
    SAF_CMU_LO_FREQ_1       = 0x0,
	SAF_CMU_LO_FREQ_2       = 0x1,
	SAF_CMU_LO_FREQ_4       = 0x2,
	SAF_CMU_LO_FREQ_8       = 0x4,
}cmu_ircosc_divider_t;

/*!
 * @brief Clock Monitoring Unit configuration structure for CMU_1 - CMU_8 and CMU_PLL0.
 * Implements monitoring_units_config_t_Class
 */
typedef struct
{
	boolean						enable;
	uint32_t                    lo_freq;
	uint32_t                    hi_freq;
} monitoring_units_config_t;

/*!
 * @brief Clock Monitoring Units configuration structure.
 * Implements cmu_config_t_Class
 */
typedef struct
{
	cmu_ircosc_divider_t          cmu_rcdiv0;
    monitoring_units_config_t     cmu[CMU_INSTANCE_COUNT];
} cmu_config_t;

/*!
 * @brief Clock configuration structure.
 * Implements clock_manager_user_config_t_Class
 */
typedef struct
{
    mc_me_config_t              mcmeConfig;     /*!< MC_ME configuration.                             */
    cgm_config_t                cgmConfig;      /*!< CGM configuration.                               */
    cgmcs_config_t              cgmcsConfig;    /*!< CGM Clock Sources configuration.                 */
    cmu_config_t				cmuConfig;		/*!< Clock Monitoring Unit configuration.             */
    mode_config_t               targetmode;	    /*!< system run mode.             					  */
} clock_manager_user_config_t;

/*!
 * @brief Sets CMU_0 XOSC divider
 */
static inline void SAF_CMU_LLD_SetDivider(CMU_Type * base, uint32_t rcdiv)
{
	CMU_Type* pBase = base;
	pBase->CSR.B.RCDIV = rcdiv;
}

/*!
 * @brief Enables/Disables the monitoring unit
 */
static inline void SAF_CMU_LLD_EnableCMU(CMU_Type * base, boolean enable)
{
	CMU_Type* pBase = base;
	pBase->CSR.B.CME = enable;
}

/*!
 * @brief Sets inferior limit of the monitored clock
 */
static inline void SAF_CMU_LLD_SetLowFreq(CMU_Type * base, uint32_t freq)
{
	CMU_Type* pBase = base;
	pBase->LFREFR.B.LFREF = freq;
}

/*!
 * @brief Sets the superior limit of the monitored clock
 */
static inline void SAF_CMU_LLD_SetHighFreq(CMU_Type * base, uint32_t freq)
{
	CMU_Type* pBase = base;
	pBase->HFREFR.B.HFREF = freq;
}

extern status_t MCU_LLD_Init(clock_manager_user_config_t const * config);
extern void SAF_MCU_LLD_CalculateFrequenciesOfClockSources(boolean runtime);
extern status_t SAF_CLOCK_GetClockSourceFreq(saf_clock_names_t clockName,uint32_t *frequency);
extern status_t SAF_CLOCK_GetModuleClockFreq(saf_clock_names_t clockName,uint32_t *frequency);
extern status_t SAF_CLOCK_GetFlexrayClockFreq(saf_clock_names_t clockName, uint32_t *frequency);
extern uint32_t SAF_CMU_LLD_GetStatus(CMU_Type * base);
extern void SAF_CMU_LLD_CleanStatusRegister(CMU_Type * base);

extern uint32_t CPU_Z7_0_SRAM_BASE_ADDR;
extern uint32_t CPU_Z7_1_SRAM_BASE_ADDR;
extern uint32_t CPU_Z4_2_SRAM_BASE_ADDR;

extern uint32_t CPU_Z7_0_FLASH_BASE_ADDR;
extern uint32_t CPU_Z7_1_FLASH_BASE_ADDR;
extern uint32_t CPU_Z4_2_FLASH_BASE_ADDR;
void SAF_CMU_LLD_Reset(CMU_Type * base);
Saf_CoreId SAF_MCU_LLD_Get_Core_Id(void);
ChipMode MCU_LLD_Get_Chip_Mode(void);
status_t SAF_MCU_LLD_Get_Core_Mode(Saf_CoreId core_id, CoreMode *core_mode);
status_t SAF_MCU_LLD_Swtich_Core_Mode(Saf_CoreId core_id, const CoreMode *core_mode);
status_t SAF_MCU_LLD_Get_Mode(Saf_CoreId core_id, CoreMode *core_mode);
status_t SAF_MCU_LLD_Swtich_Mode(Saf_CoreId core_id, CoreMode *core_mode);
status_t SAF_MCU_LLD_Launch_Core(Saf_CoreId core_id);
status_t SAF_MCU_LLD_Set_Chip_Mode(ChipMode chip_mode);
status_t SAF_MCU_LLD_Switch_DCache(uint32_t switch_val);
void CMU_LLD_Reset(CMU_Type * base);
void SAF_MCU_LLD_Enter_Wait_Mode(void);
#ifdef ICACHE_ENABLE
status_t SAF_MCU_LLD_Enable_ICache(void);
status_t SAF_MCU_LLD_Disable_ICache(void);
status_t SAF_MCU_LLD_Invalid_ICache_Set_Way(uint32_t set, uint32_t way);
status_t SAF_MCU_LLD_Invalid_ICache(uint32_t base, uint32_t len);
#endif
#ifdef DCACHE_ENABLE
status_t SAF_MCU_LLD_Enable_DCache(void);
status_t SAF_MCU_LLD_Disable_DCache(void);
status_t SAF_MCU_LLD_Invalid_DCache_Set_Way(uint32_t set, uint32_t way);
status_t SAF_MCU_LLD_Invalid_DCache(uint32_t base, uint32_t len);
#endif
#endif
