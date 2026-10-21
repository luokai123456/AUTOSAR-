/**********************************************************************************************************************
*
* COPYRIGHT RESERVED, Tianjin Yidingfeng Power Technology, 2012. All rights reserved.
* The reproduction, distribution and utilization of this document as well as the communication of its contents to
* others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
* All rights reserved in the event of the grant of a patent, utility model or design.
*
**********************************************************************************************************************
* Administrative Information
* Namespace_:
* Class_____:H
* Name______:CanTrcv_cfg
* Variant___:75.16.01
* Revision__:0
**********************************************************************************************************************
 * History___:
 *
 * 75.16.01; 0     28.06.2023 SH-RD  Kaili.Shentu
 *   N: new created
 *
 * 
 * 
 * 
***********************************************************************************************************************/
#ifndef CANTRCV_CFG_H
#define CANTRCV_CFG_H
/*
 ***************************************************************************************************
 * Defines
 ***************************************************************************************************
 */

#define CANTRCV_CFG_NUMBER_OF_CANTRCV  2u

/*index of CAN tranceiver*/
#define CANTRCV_TPT1145_01    0      /*  Index for TPT1145_01 TPT1145 */

/* Wakeup Enabled if one CanTrcv is configured with CANTRCV_WAKEUP_BY_POLLING = ON */
#define CANTRCV_CFG_WAKEUP_BY_NODE_USED STD_ON

#ifndef CANTRCV_ECUM_USED   // Value could be overwritten in integrator code
# define CANTRCV_ECUM_USED   STD_OFF
#endif

/* Enables partial network API */
#define CANTRCV_HW_PN_SUPPORT STD_ON

/* enables/disables DET (at least for one trcv)*/
#define CANTRCV_DEV_ERROR_DETECT   STD_OFF

/* enables/disables DEM (at least for one trcv)*/
#define CANTRCV_CFG_DEM_ENABLE   STD_OFF

/* enables/disables HE9788 CANTRCV interface support*/
#define CANTRCV_CFG_HE9788_USED             STD_ON
#define CANTRCV_CFG_SPI_USED                STD_ON
#define CANTRCV_INDICATION_ASYNC            0
#define CANTRCV_INDICATION_IMMEDIATELY      1
#define CANTRCV_CFG_RB_INDICATION_BEHAVIOUR CANTRCV_INDICATION_ASYNC

/* SPI: STD_ON: external buffers are used; STD_OFF: internal buffers are used */
/* value is set according SPI_CHANNEL_BUFFERS_ALLOWED */
#define CANTRCV_CFG_SPI_TPT1145_USED        STD_ON
#define CANTRCV_CFG_BUS_ERR_FLAG_GENERAL    STD_OFF
#define CANTRCV_CFG_TPT1145_MAX             2
#define CANTRCV_CFG_TPT1145_SPI_INIT_MAX    29
#define CANTRCV_CFG_TPT1145_SPI_CTRL_MAX    12


// TPT1145_01 InitStarPos
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG0A_A	(0U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG01		(1U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG04		(2U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG23		(3U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG26		(4U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG27		(5U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG28		(6U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG29		(7U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG2A		(8U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG2B		(9U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG2C		(10U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG2D		(11U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG2E		(12U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG2F		(13U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG68		(14U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG69		(15U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG6A		(16U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG6B		(17U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG6C		(18U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG6D		(19U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG6E		(20U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG6F		(21U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG4C		(22U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG61		(23U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG63		(24U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG60		(25U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG20		(26U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG0A_B	(27U)
#define CANTRCV_CFG_TPT1145_INIT_SPI_REG0A_C	(28U)
// Startpos for Control Reg
#define CANTRCV_CFG_TPT1145_READ_ONLY_MASK  0x0100uL
#define CANTRCV_CFG_TPT1145_SPI_REG0A_A     0
#define CANTRCV_CFG_TPT1145_SPI_LK2C_MASK        0x04u  // 0x20 to 0x2F -
#define CANTRCV_CFG_TPT1145_SPI_LK1C_MASK        0x02u  // 0x10 to 0x1F -
#define CANTRCV_CFG_TPT1145_SPI_LK0C_MASK        0x01u  // 0x06 to 0x09 -
#define CANTRCV_CFG_TPT1145_SPI_REG01       5
#define CANTRCV_CFG_TPT1145_SPI_MC_AND_MASK      0x0007u // Mask to read out Mode
#define CANTRCV_CFG_TPT1145_SPI_MC_NM_AND_MASK   0xFEF8u // Mask for normal Mode and Cleared ReadOnlyBit
#define CANTRCV_CFG_TPT1145_SPI_MC_NM_OR_MASK    0x0007u // Mask for normal Mode
#define CANTRCV_CFG_TPT1145_SPI_MC_SM_AND_MASK   0xFEF8u // Mask for sleep Mode and Cleared ReadOnlyBit
#define CANTRCV_CFG_TPT1145_SPI_MC_SM_OR_MASK    0x0001u // Mask for sleep Mode
#define CANTRCV_CFG_TPT1145_SPI_MC_SBM_AND_MASK  0xFEF8u // Mask for standby Mode and Cleared ReadOnlyBit
#define CANTRCV_CFG_TPT1145_SPI_MC_SBM_OR_MASK   0x0004u // Mask for standby Mode
#define CANTRCV_CFG_TPT1145_SPI_REG20            4
#define CANTRCV_CFG_TPT1145_SPI_CMC_NM_AND_MASK  (~(CANTRCV_CFG_TPT1145_READ_ONLY_MASK + 3uL))    // Mask for normal Mode
#define CANTRCV_CFG_TPT1145_SPI_CMC_SM_AND_MASK  (~(CANTRCV_CFG_TPT1145_READ_ONLY_MASK + 3uL))    // Mask for sleep Mode
#define CANTRCV_CFG_TPT1145_SPI_CMC_SM_OR_MASK   0x00u    // Mask for sleep Mode. Always 0
#define CANTRCV_CFG_TPT1145_SPI_CMC_SBM_AND_MASK (~(CANTRCV_CFG_TPT1145_READ_ONLY_MASK + 3uL))    // Mask for standby Mode
#define CANTRCV_CFG_TPT1145_SPI_CMC_SBM_OR_MASK  0x00u    // Mask for standby Mode. Always 0
#define CANTRCV_CFG_TPT1145_SPI_CPNC_MASK        0x10u
#define CANTRCV_CFG_TPT1145_SPI_REG4C       6
#define CANTRCV_CFG_TPT1145_SPI_REG03       7
#define CANTRCV_CFG_TPT1145_SPI_REG22       8
#define CANTRCV_CFG_TPT1145_SPI_CFS_MASK    1u
#define CANTRCV_CFG_TPT1145_SPI_CBSS_MASK   8u
#define CANTRCV_CFG_TPT1145_SPI_CTS_MASK    128u
#define CANTRCV_CFG_TPT1145_SPI_CPNERR_MASK 64u
#define CANTRCV_CFG_TPT1145_SPI_REG4B       9
#define CANTRCV_CFG_TPT1145_SPI_WPVS_MASK   0x02u
#define CANTRCV_CFG_TPT1145_SPI_REG60       1
#define CANTRCV_CFG_TPT1145_SPI_WPE_MASK    0x08u
#define CANTRCV_CFG_TPT1145_SPI_REG61       2
#define CANTRCV_CFG_TPT1145_SPI_PO_MASK     0x10u
#define CANTRCV_CFG_TPT1145_SPI_REG63       3
#define CANTRCV_CFG_TPT1145_SPI_CW_MASK     0x01u
#define CANTRCV_CFG_TPT1145_SPI_PO_MASK     0x10u
#define CANTRCV_CFG_TPT1145_SPI_CBS_MASK    0x10u
#define CANTRCV_CFG_TPT1145_SPI_REG64       10
#define CANTRCV_CFG_TPT1145_SPI_WPR_MASK    0x02u
#define CANTRCV_CFG_TPT1145_SPI_WPF_MASK    0x01u
#define CANTRCV_CFG_TPT1145_SPI_REG0A_E     11

/* enables multiple wakeup reasons */
#define CANTRCV_CFG_WU_BY_BUS_AND_PIN                CANTRCV_WU_NOT_SUPPORTED
#define CANTRCV_CFG_WU_BY_BUS_AND_POWER_ON           CANTRCV_WU_NOT_SUPPORTED
#define CANTRCV_CFG_WU_BY_PIN_AND_POWER_ON           CANTRCV_WU_NOT_SUPPORTED
#define CANTRCV_CFG_WU_BY_BUS_AND_PIN_AND_POWER_ON   CANTRCV_WU_NOT_SUPPORTED

#endif //endif for EVPTCDD_TPT1145_H

