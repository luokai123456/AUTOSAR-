/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     mcu_config.h
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
/*PRQA S 1534,1535 EOF*/
#ifndef RGM_LLD_H_
#define RGM_LLD_H_

#include "derivative.h"
#include "status.h"
#include "typedefs.h"

typedef  struct MC_RGM_tag                   RGM_Type;

/* IRCOSC - Peripheral instance base addresses */
/** Peripheral IRCOSC base address */
#define RGM_BASE                              (0xFFFA8000u)
/** Peripheral IRCOSC base pointer */
#define RGM_StPtr                             ((RGM_Type *)RGM_BASE)
/** Array initializer of IRCOSC peripheral base addresses */
#define RGM_BASE_ADDRS                        { RGM_BASE }
/** Array initializer of IRCOSC peripheral base pointers */
#define RGM_BASE_PTRS                         { RGM_StPtr }

/* DES Fields */
#define RGM_VOR_DEST_MASK                     0x1000000u
#define RGM_VOR_DEST_SHIFT                    25u
#define RGM_TSR_DEST_MASK                     0x0800000u
#define RGM_TSR_DEST_SHIFT                    24u
#define RGM_HSM_DEST_MASK                     0x8000u
#define RGM_HSM_DEST_SHIFT                    15u
#define RGM_SSCM_DEST_MASK                    0x4000u
#define RGM_SSCM_DEST_SHIFT                   14u
#define RGM_JTAG_DEST_MASK                    0x400u
#define RGM_JTAG_DEST_SHIFT                   10u
#define RGM_FIF_DEST_MASK                     0x200u
#define RGM_FIF_DEST_SHIFT                    9u
#define RGM_EDR_DEST_MASK                     0x100u
#define RGM_EDR_DEST_SHIFT                    8u
#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
#define RGM_SWT_AO_DEST_MASK                  0x80u
#define RGM_SWT_AO_DEST_SHIFT                 7u
#endif
#define RGM_SUF_DEST_MASK                     0x20u
#define RGM_SUF_DEST_SHIFT                    5u
#define RGM_FFRR_DEST_MASK                    0x10u
#define RGM_FFRR_DEST_SHIFT                   4u
#define RGM_SOFT_DEST_MASK                    0x4u
#define RGM_SOFT_DEST_SHIFT                   3u
#define RGM_PORST_DEST_MASK                   0x2u
#define RGM_PORST_DEST_SHIFT                  1u
#define RGM_POR_DEST_MASK                     0x1u
#define RGM_POR_DEST_SHIFT                    0u

/* FES Fields */
#define RGM_VOR_FUNC_MASK                     0x1000000u
#define RGM_VOR_FUNC_SHIFT                    25u
#define RGM_TSR_FUNC_MASK                     0x0800000u
#define RGM_TSR_FUNC_SHIFT                    24u
#define RGM_HSM_FUNC_MASK                     0x8000u
#define RGM_HSM_FUNC_SHIFT                    15u
#define RGM_JTAG_FUNC_MASK                    0x400u
#define RGM_JTAG_FUNC_SHIFT                   10u
#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
#define RGM_SWT_AO_FUNC_MASK                  0x80u
#define RGM_SWT_AO_FUNC_SHIFT                 7u
#endif
#define RGM_FCCU_SOFT_FUNC_MASK               0x40u
#define RGM_FCCU_SOFT_FUNC_SHIFT              6u
#define RGM_FCCU_HARD_FUNC_MASK               0x20u
#define RGM_FCCU_HARD_FUNC_SHIFT              5u
#define RGM_SOFT_FUNC_MASK                    0x8u
#define RGM_SOFT_FUNC_SHIFT                   3u
#define RGM_ST_DONE_FUNC_MASK                 0x4u
#define RGM_ST_DONE_FUNC_SHIFT                2u
#define RGM_ESR1_FUNC_MASK                    0x2u
#define RGM_ESR1_FUNC_SHIFT                   1u
#define RGM_ESR0_FUNC_MASK                    0x1u
#define RGM_ESR0_FUNC_SHIFT                   0u


/*!
 * @brief destructive reset type.
 * Implements alternate_request_t_Class
 */
typedef enum
{
    DEST_VOR              = 0U,
	DEST_TSR              = 1U,
	DEST_HSM              = 2U,
	DEST_SCCM             = 3U,
	DEST_JTAG             = 4U,
	DEST_FIF              = 5U,
	DEST_EDR              = 6U,
	DEST_SUF              = 7U,
	DEST_FFRR             = 8U,
	DEST_SOFT             = 9U,
	DEST_PORST            = 10U,
	DEST_POR              = 11U,
    DEST_Disnable         = 12U,
}destrutive_reset_name_t;

/*!
 * @brief functional reset type.
 * Implements functional_request_t_Class
 */
typedef enum
{
    Func_VOR              = 0U,
    Func_TSR              = 1U,
    Func_HSM              = 2U,
    Func_JTAG             = 3U,
    Func_FCCU_SOFT        = 4U,
    Func_FCCU_HARD        = 5U,
    Func_SOFT             = 6U,
    Func_ST_DONE          = 7U,
	Func_ESR1			  = 8U,
    Func_ESR0             = 9U,
	Func_Dinable          = 10U,
}functional_reset_name_t;

/*!
 * @brief functional reset type.
 * Implements functional_request_t_Class
 */
typedef enum
{
    PIT_RTC_RST            = 0U,
	SIUL_RST			   = 1U,
	SIPI_RST			   = 2U,
	LFAST_RST			   = 3U,
	EBI_RST				   = 4U,//CCFC3008PT will not have it
	ADCSD_RST			   = 5U,
	CRC_RST				   = 6U,
	DMAMUX_RST             = 7U,
	DSPI_RST               = 8U,
	LINFlexeD_RST		   = 9U,
	CAN_RAM_CTR_RST		   = 10U,
	TTCAN_RST			   = 11U,
	MCAN_RST			   = 12U,
	PSI5_RST			   = 13U,
	ADCSAR_RST			   = 14U,
	FLEXRAY_RST            = 15U,
	SENT_RST               = 16U,
	IIC_RST				   = 17U,
	GTMINT_RST             = 18U,
	FCCU_RST			   = 19U,
}individual_PR_name_t;

typedef enum
{
    PSI5_0_RST             = 0U,
	PSI5_1_RST			   = 1U,
	PSI5_S_0_RST		   = 2U,
}PSI5_name_t;

/*!
 * @brief alternate request type.
 * Implements alternate_request_t_Class
 */
typedef enum
{
    SAFE_REQ              = 0U,
    INT_REQ               = 1U,
}alternate_request_t;


typedef struct
{
	boolean DE_enable;
	destrutive_reset_name_t DE_name;
} destructive_disnable_config_t;

typedef struct
{
	boolean FE_enable;
	functional_reset_name_t FERD_name;
} functional_disnable_config_t;

typedef struct
{
	boolean isnot_esr0_assreted;
	functional_reset_name_t FB_name;
} functional_bidirection_config_t;

typedef struct
{
	boolean FE_enable;
	alternate_request_t mode;
	functional_reset_name_t FEAR_name;
} functional_alternate_config_t;

typedef struct
{
	boolean FE_enable;
	functional_reset_name_t FESS_name;
} functional_shortSequence_config_t;

typedef struct
{
	boolean DE_enable;
	uint8_t  threholdcount;
} destructive_escalation_config_t;

typedef struct
{
	boolean FE_enable;
	uint8_t  threholdcount;
} functional_escalation_config_t;

typedef struct
{
	boolean PR_enable;
	uint32_t instance;
	functional_reset_name_t PRname;
} peripheral_rest_config_t;

#define RGM_DERD_COUNT  1
#define RGM_FERD_COUNT  3
#define RGM_FEAR_COUNT  3
#define RGM_FBRE_COUNT  7
#define RGM_FESS_COUNT  6
#define RGM_PRST_COUNT  62

typedef struct
{
	destructive_disnable_config_t DERD_PROST;
	functional_disnable_config_t  FERD[RGM_FERD_COUNT];
	functional_alternate_config_t FEAR[RGM_FEAR_COUNT];
	functional_bidirection_config_t FBRE[RGM_FBRE_COUNT];
	functional_shortSequence_config_t FESS[RGM_FESS_COUNT];
	destructive_escalation_config_t DRET;
	functional_escalation_config_t FRET;
} rgm_manager_user_config_t;

extern rgm_manager_user_config_t config1;

extern void RGM_ISR(void);
extern void RGM_LLD_test(void);
extern status_t RGM_LLD_SetDEAR(destrutive_reset_name_t name,alternate_request_t mode);
extern status_t RGM_LLD_PITRTC_Rst(uint32_t instance,boolean enable);
extern void RGM_LLD_DESandFES(void);

status_t RGM_LLD_SIUL_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_SIPI_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_LFAST_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_EBI_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_ADCSD_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_CRC_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_DMAMUX_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_DSPI_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_LINFlexd_Rst(uint32_t instance,boolean enable);
status_t RGM_CANRAMCTR_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_TTCAN_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_MCAN_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_PSI5_Rst(PSI5_name_t instance,boolean enable);
status_t RGM_LLD_FlexRay_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_SENT_Rst(uint32_t instance,boolean enable);
status_t RGM_IIC_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_ADCSAR_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_GTMMINT_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_FCCU_Rst(uint32_t instance,boolean enable);
status_t RGM_LLD_SetDERD(destrutive_reset_name_t name,boolean enable);
status_t RGM_LLD_SetFERD(functional_reset_name_t name,boolean enable);
status_t RGM_LLD_SetFEAR(functional_reset_name_t name,alternate_request_t mode);
status_t RGM_LLD_SetFBRE(functional_reset_name_t name,boolean isnot_esr0_assreted);
status_t RGM_LLD_SetFESS(functional_reset_name_t name,boolean enable);
status_t RGM_LLD_SetDRET(boolean enable,uint8_t count);
status_t RGM_LLD_SetFRET(boolean enable,uint8_t count);
status_t RGM_LLD_Config(rgm_manager_user_config_t const * config);
status_t RGM_LLD_SetPRST(individual_PR_name_t peripheral_name,uint32_t instance,boolean enable);



#endif /* RGM_LLD_H_ */
