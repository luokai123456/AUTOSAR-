/* PRQA S 0602 EOF */
/*
 * gtm4_reg.h
 *
 *  Created on: 2024年4月28日
 *      Author: ccore
 */

#ifndef _GTM4_REG_H_
#define _GTM4_REG_H_

/* ============================================================================
   =============================== Module: GTM ================================
   ============================================================================ */
typedef union _GTM_REV {
    vuint32_t R;
    struct {
        vuint32_t VER_MAJOR:4;                  /**< \brief [31:28] Major version number (r) */
        vuint32_t VER_MINOR:4;                  /**< \brief [27:24] Minor version number (r) */
        vuint32_t DEVICE_CODE:4;                /**< \brief [23:20] Device encoding digit 0 (r) */
        vuint32_t VENDOR_CODE:4;                /**< \brief [19:16] Device encoding digit 1 (r) */
        vuint32_t reserved_12:4;                /**< \brief [15:12] \internal Reserved */
        vuint32_t REL_BASE:8;                   /**< \brief [11:4] Release step (r) */
        vuint32_t REL_ITER:4;                   /**< \brief [3:0] GTM IP release iteration (r) */
    } B;
} GTM_REV;

typedef union _GTM_RST {
    vuint32_t R;
    struct {
        vuint32_t reserved_28:4;                /**< \brief [31:28] \internal Reserved */
        vuint32_t BRIDGE_MODE_WRDIS:1;          /**< \brief [27:27] GTM_BRIDGE_MODE write disable (rw) */
        vuint32_t reserved_1:26;                /**< \brief [26:1] \internal Reserved */
        vuint32_t RST:1;                        /**< \brief [0:0] GTM IP Reset */
    } B;
} GTM_RST;

typedef union _GTM_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;               /**< \brief [31:16] \internal Reserved */
        vuint32_t AEIM_CLUSTER:4;               /**< \brief [15:12] AEIM cluster number (r) */
        vuint32_t TO_VAL:8;                     /**< \brief [11:4] AEI timeout value (rw) */
        vuint32_t reserved_2:1;                 /**< \brief [3:3] \internal Reserved */
        vuint32_t TO_MODE:2;                    /**< \brief [2:1] AEI timeout mode (rw) */
        vuint32_t RF_PROT:1;                    /**< \brief [0:0] RST and FORCINT protection (rw) */
    } B;
} GTM_CTRL;

typedef union _GTM_CFG {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;                /**< \brief [31:1] \internal Reserved */
        vuint32_t SRC_IN_MUX:1;                 /**< \brief [0:0] GTM_TIM[i]_AUX_IN input source selection (rw) */
    } B;
} GTM_CFG;

typedef union _GTM_AEI_ADDR_XPT {
    vuint32_t R;
    struct {
        vuint32_t reserved_25:7;                /**< \brief [31:25] \internal Reserved */
        vuint32_t TO_W1R0:1;                    /**< \brief [24:24] AEI timeout Read/Write flag (r) */
        vuint32_t reserved_21:3;                /**< \brief [23:21] \internal Reserved */
        vuint32_t TO_ADDR:21;                   /**< \brief [20:0] AEI timeout address (r) */
    } B;
} GTM_AEI_ADDR_XPT;

typedef union _GTM_AEI_STA_XPT {
    vuint32_t R;
    struct {
        vuint32_t reserved_25:7;                /**< \brief [31:25] \internal Reserved */
        vuint32_t W1R0:1;                       /**< \brief [24:24] AEI exception Read/Write flag (r) */
        vuint32_t reserved_21:3;                /**< \brief [23:21] \internal Reserved */
        vuint32_t ADDR:21;                      /**< \brief [20:0] AEI exception address (r) */
    } B;
} GTM_AEI_STA_XPT;

typedef union _GTM_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_30:2;                /**< \brief [31:30] \internal Reserved */
        vuint32_t CLK_EN_EXP_STATE:2;           /**< \brief [29:28] Expected clock enable state (r) */
        vuint32_t reserved_26:2;                /**< \brief [27:26] \internal Reserved */
        vuint32_t CLK_EN_ERR_STATE:2;           /**< \brief [25:24] Erroneous clock enable state (r) */
        vuint32_t reserved_9:15;                /**< \brief [23:9] \internal Reserved */
        vuint32_t CLK_PER_ERR:1;                /**< \brief [8:8] Clock period error interrupt (rw) */
        vuint32_t CLK_EN_ERR:1;                 /**< \brief [7:7] Clock enable error interrupt (rw) */
        vuint32_t AEIM_USP_BE:1;                /**< \brief [6:6] AEI master port unsupported byte enable interrupt (rw) */
        vuint32_t AEIM_IM_ADDR:1;               /**< \brief [5:5] AEI master port illegal Module address interrupt (rw) */
        vuint32_t AEIM_USP_ADDR:1;              /**< \brief [4:4] AEI master port unsupported address interrupt (rw) */
        vuint32_t AEI_USP_BE:1;                 /**< \brief [3:3] AEI unsupported byte enable interrupt (rw) */
        vuint32_t AEI_IM_ADDR:1;                /**< \brief [2:2] AEI illegal Module address interrupt (rw) */
        vuint32_t AEI_USP_ADDR:1;               /**< \brief [1:1] AEI unsupported address interrupt (rw) */
        vuint32_t AEI_TO_XPT:1;                 /**< \brief [0:0] AEI timeout exception occurred (rw) */
    } B;
} GTM_IRQ_NOTIFY;

typedef union _GTM_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;                /**< \brief [31:9] \internal Reserved */
        vuint32_t CLK_PER_ERR_IRQ_EN:1;         /**< \brief [8:8] CLK_PER_ERR_IRQ interrupt enable (rw) */
        vuint32_t CLK_EN_ERR_IRQ_EN:1;          /**< \brief [7:7] CLK_EN_ERR_IRQ interrupt enable (rw) */
        vuint32_t AEIM_USP_BE_IRQ_EN:1;         /**< \brief [6:6] AEIM_USP_BE_IRQ interrupt enable (rw) */
        vuint32_t AEIM_IM_ADDR_IRQ_EN:1;        /**< \brief [5:5] AEIM_IM_ADDR_IRQ interrupt enable (rw) */
        vuint32_t AEIM_USP_ADDR_IRQ_EN:1;       /**< \brief [4:4] AEI_MUSP_ADDR_IRQ interrupt enable (rw) */
        vuint32_t AEI_USP_BE_IRQ_EN:1;          /**< \brief [3:3] AEI_USP_BE_IRQ interrupt enable (rw) */
        vuint32_t AEI_IM_ADDR_IRQ_EN:1;         /**< \brief [2:2] AEI_IM_ADDR_IRQ interrupt enable (rw) */
        vuint32_t AEI_USP_ADDR_IRQ_EN:1;        /**< \brief [1:1] AEI_USP_ADDR_IRQ interrupt enable (rw) */
        vuint32_t AEI_TO_XPT_IRQ_EN:1;          /**< \brief [0:0] AEI_TO_XPT_IRQ interrupt enable (rw) */
    } B;
} GTM_IRQ_EN;

typedef union _GTM_EIRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;                /**< \brief [31:9] \internal Reserved */
        vuint32_t CLK_PER_ERR_EIRQ_EN:1;        /**< \brief [8:8] CLK_PER_ERR_EIRQ interrupt enable (rw) */
        vuint32_t CLK_EN_ERR_EIRQ_EN:1;         /**< \brief [7:7] CLK_EN_ERR_EIRQ interrupt enable (rw) */
        vuint32_t AEIM_USP_BE_EIRQ_EN:1;        /**< \brief [6:6] AEIM_USP_BE_EIRQ error interrupt enable (rw) */
        vuint32_t AEIM_IM_ADDR_EIRQ_EN:1;       /**< \brief [5:5] AEIM_IM_ADDR_EIRQ error interrupt enable (rw) */
        vuint32_t AEIM_USP_ADDR_EIRQ_EN:1;      /**< \brief [4:4] AEIM_USP_ADDR_EIRQ error interrupt enable (rw) */
        vuint32_t AEI_USP_BE_EIRQ_EN:1;         /**< \brief [3:3] AEI_USP_BE_EIRQ error interrupt enable (rw) */
        vuint32_t AEI_IM_ADDR_EIRQ_EN:1;        /**< \brief [2:2] AEI_IM_ADDR_EIRQ error interrupt enable (rw) */
        vuint32_t AEI_USP_ADDR_EIRQ_EN:1;       /**< \brief [1:1] AEI_USP_ADDR_EIRQ error interrupt enable (rw) */
        vuint32_t AEI_TO_XPT_EIRQ_EN:1;         /**< \brief [0:0] AEI_TO_XPT_EIRQ error interrupt enable (rw) */
    } B;
} GTM_EIRQ_EN;

typedef union _GTM_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;                /**< \brief [31:9] \internal Reserved */
        vuint32_t TRG_CLK_PER_ERR:1;            /**< \brief [8:8] Trigger CLK_PER_ERR_IRQ interrupt by software (rw) */
        vuint32_t TRG_CLK_EN_ERR:1;             /**< \brief [7:7] Trigger CLK_EN_ERR_IRQ interrupt by software (rw) */
        vuint32_t TRG_AEIM_USP_BE:1;            /**< \brief [6:6] Trigger AEIM_USP_BE_IRQ interrupt by software (rw) */
        vuint32_t TRG_AEIM_IM_ADDR:1;           /**< \brief [5:5] Trigger AEIM_IM_ADDR_IRQ interrupt by software (rw) */
        vuint32_t TRG_AEIM_USP_ADDR:1;          /**< \brief [4:4] Trigger AEIM_USP_ADDR_IRQ interrupt by software (rw) */
        vuint32_t TRG_AEI_USP_BE:1;             /**< \brief [3:3] Trigger AEI_USP_BE_IRQ interrupt by software (rw) */
        vuint32_t TRG_AEI_IM_ADDR:1;            /**< \brief [2:2] Trigger AEI_IM_ADDR_IRQ interrupt by software (rw) */
        vuint32_t TRG_AEI_USP_ADDR:1;           /**< \brief [1:1] Trigger AEI_USP_ADDR_IRQ interrupt by software (rw) */
        vuint32_t TRG_AEI_TO_XPT:1;             /**< \brief [0:0] Trigger AEI_TO_XPT_IRQ interrupt by software (rw) */
    } B;
} GTM_IRQ_FORCINT;

typedef union _GTM_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;                /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;                   /**< \brief [1:0] Interrupt strategy mode selection for the AEI timeout and address monitoring interrupts (rw) */
    } B;
} GTM_IRQ_MODE;

typedef union _GTM_CLS_CLK_CFG {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t CLS11_CLK_DIV:2;              /**< \brief [23:22] Cluster 11 Clock Divider (rw) */
        vuint32_t CLS10_CLK_DIV:2;              /**< \brief [21:20] Cluster 10 Clock Divider (rw) */
        vuint32_t CLS9_CLK_DIV:2;               /**< \brief [19:18] Cluster 9 Clock Divider (rw) */
        vuint32_t CLS8_CLK_DIV:2;               /**< \brief [17:16] Cluster 8 Clock Divider (rw) */
        vuint32_t CLS7_CLK_DIV:2;               /**< \brief [15:14] Cluster 7 Clock Divider (rw) */
        vuint32_t CLS6_CLK_DIV:2;               /**< \brief [13:12] Cluster 6 Clock Divider (rw) */
        vuint32_t CLS5_CLK_DIV:2;               /**< \brief [11:10] Cluster 5 Clock Divider (rw) */
        vuint32_t CLS4_CLK_DIV:2;               /**< \brief [9:8] Cluster 4 Clock Divider (rw) */
        vuint32_t CLS3_CLK_DIV:2;               /**< \brief [7:6] Cluster 3 Clock Divider (rw) */
        vuint32_t CLS2_CLK_DIV:2;               /**< \brief [5:4] Cluster 2 Clock Divider (rw) */
        vuint32_t CLS1_CLK_DIV:2;               /**< \brief [3:2] Cluster 1 Clock Divider (rw) */
        vuint32_t CLS0_CLK_DIV:2;               /**< \brief [1:0] Cluster 0 Clock Divider (rw) */
    } B;
} GTM_CLS_CLK_CFG;

typedef union _GTM_ARU_COM_DIS {
    vuint32_t R;
    struct {
        vuint32_t reserved_20:20;               /**< \brief [31:20] \internal Reserved */
        vuint32_t CLS11_DIS:1;                  /**< \brief [0:0] Disable cluster 11 ARU communication (rw) */
        vuint32_t CLS10_DIS:1;                  /**< \brief [0:0] Disable cluster 10 ARU communication (rw) */
        vuint32_t CLS9_DIS:1;                   /**< \brief [0:0] Disable cluster 9 ARU communication (rw) */
        vuint32_t CLS8_DIS:1;                   /**< \brief [0:0] Disable cluster 8 ARU communication (rw) */
        vuint32_t CLS7_DIS:1;                   /**< \brief [0:0] Disable cluster 7 ARU communication (rw) */
        vuint32_t CLS6_DIS:1;                   /**< \brief [0:0] Disable cluster 6 ARU communication (rw) */
        vuint32_t CLS5_DIS:1;                   /**< \brief [0:0] Disable cluster 5 ARU communication (rw) */
        vuint32_t CLS4_DIS:1;                   /**< \brief [0:0] Disable cluster 4 ARU communication (rw) */
        vuint32_t CLS3_DIS:1;                   /**< \brief [0:0] Disable cluster 3 ARU communication (rw) */
        vuint32_t CLS2_DIS:1;                   /**< \brief [0:0] Disable cluster 2 ARU communication (rw) */
        vuint32_t CLS1_DIS:1;                   /**< \brief [0:0] Disable cluster 1 ARU communication (rw) */
        vuint32_t CLS0_DIS:1;                   /**< \brief [0:0] Disable cluster 0 ARU communication (rw) */
    } B;
} GTM_ARU_COM_DIS;

typedef volatile struct _GTM_ARCH {
    GTM_REV                         REV;                    /**< \brief 0, GTM Version Control Register*/
    GTM_RST                         RST;                    /**< \brief 4, GTM Global Reset Register*/
    GTM_CTRL                        CTRL;                   /**< \brief 8, GTM Global Control Register*/
    GTM_CFG                         CFG;                    /**< \brief C, GTM Configuration Register*/
    GTM_AEI_ADDR_XPT                AEI_ADDR_XPT;           /**< \brief 10, GTM AEI Timeout Exception Address Register*/
    GTM_AEI_STA_XPT                 AEI_STA_XPT;            /**< \brief 14, GTM AEI Non Zero Status Register*/
    GTM_IRQ_NOTIFY                  IRQ_NOTIFY;             /**< \brief 18, GTM Interrupt Notification Register*/
    GTM_IRQ_EN                      IRQ_EN;                 /**< \brief 1c, GTM Interrupt Enable Register*/
    GTM_EIRQ_EN                     EIRQ_EN;                /**< \brief 20, GTM Error Interrupt Enable Register*/
    GTM_IRQ_FORCINT                 IRQ_FORCINT;            /**< \brief 24, GTM Software Interrupt Generation Register*/
    GTM_IRQ_MODE                    IRQ_MODE;               /**< \brief 28, GTM Top Level Interrupts Mode Selection Register*/
    GTM_CLS_CLK_CFG                 CLS_CLK_CFG;            /**< \brief 2C, GTM Cluster Clock Configuration*/
    GTM_ARU_COM_DIS                 ARU_COM_DIS;            /**< \brief 30, GTM ARU communication disable*/
} GTM_ARCH;

/* ============================================================================
   =============================== Module: GTM_AEI ================================
   ============================================================================ */

typedef union _GTM_BRIDGE_MODE {
    vuint32_t R;
    struct {
        vuint32_t BUFF_DPT:8;                   /**< \brief [31:24] Buffer depth of AEI bridge (r) */
        vuint32_t reserved_17:7;                /**< \brief [23:17] \internal Reserved */
        vuint32_t BRG_RST:1;                    /**< \brief [16:16] Bridge software reset (rw) */
        vuint32_t reserved_13:3;                /**< \brief [15:13] \internal Reserved */
        vuint32_t SYNC_INPUT_REG:1;             /**< \brief [12:12] Additional pipelined stage in synchronous bridge mode (r) */
        vuint32_t reserved_10:2;                /**< \brief [11:10] \internal Reserved */
        vuint32_t BUFF_OVL:1;                   /**< \brief [9:9] Buffer overflow register (r) */
        vuint32_t MODE_UP_PGR:1;                /**< \brief [8:8] Mode update in progress (r) */
        vuint32_t reserved_3:5;                 /**< \brief [7:3] \internal Reserved */
        vuint32_t BYPASS_SYNC:1;                /**< \brief [2:2] Bypass synchronizer flipflops (rw) */
        vuint32_t MSK_WR_RSP:1;                 /**< \brief [1:1] Mask write response (rw) */
        vuint32_t BRG_MODE:1;                   /**< \brief [0:0] Defines the operation mode for the AEI bridge (rw) */
    } B;
} GTM_BRIDGE_MODE;

typedef union _GTM_BRIDGE_PTR1 {
    vuint32_t R;
    struct {
        vuint32_t RSP_TRAN_RDY:6;               /**< \brief [31:26] Response transactions ready. - RSP_TRAN_RDY (r) */
        vuint32_t FBC:6;                        /**< \brief [25:20] Free buffer count (r) */
        vuint32_t ABT_TRAN_PGR:5;               /**< \brief [19:15] Aborted transaction in progress pointer (r) */
        vuint32_t TRAN_IN_PGR:5;                /**< \brief [14:10] Transaction in progress pointer (acquire) (r) */
        vuint32_t FIRST_RSP_PTR:5;              /**< \brief [9:5] First response pointer (r) */
        vuint32_t NEW_TRAN_PTR:5;               /**< \brief [4:0] New transaction pointer (r) */
    } B;
} GTM_BRIDGE_PTR1;

typedef union _GTM_BRIDGE_PTR2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_5:27;                /**< \brief [31:5] \internal Reserved */
        vuint32_t TRAN_IN_PGR2:5;               /**< \brief [4:0] Transaction in progress pointer (aquire2) (r) */
    } B;
} GTM_BRIDGE_PTR2;

typedef union _GTM_MCS_AEM_DIS {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t DIS_CLS11:2;                  /**< \brief [23:22] Disable MCS AEIM access in cluster 11, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS10:2;                  /**< \brief [21:20] Disable MCS AEIM access in cluster 10, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS9:2;                   /**< \brief [19:18] Disable MCS AEIM access in cluster 9, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS8:2;                   /**< \brief [17:16] Disable MCS AEIM access in cluster 8, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS7:2;                   /**< \brief [15:14] Disable MCS AEIM access in cluster 7, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS6:2;                   /**< \brief [13:12] Disable MCS AEIM access in cluster 6, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS5:2;                   /**< \brief [11:10] Disable MCS AEIM access in cluster 5, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS4:2;                   /**< \brief [9:8] Disable MCS AEIM access in cluster 4, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS3:2;                   /**< \brief [7:6] Disable MCS AEIM access in cluster 3, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS2:2;                   /**< \brief [5:4] Disable MCS AEIM access in cluster 2, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS1:2;                   /**< \brief [3:2] Disable MCS AEIM access in cluster 1, see bit DIS_CLS0 (rw) */
        vuint32_t DIS_CLS0:2;                   /**< \brief [1:0] Disable MCS AEIM access in cluster 0 (rw) */
    } B;
} GTM_MCS_AEM_DIS;

typedef volatile struct _GTM_AEI {
       GTM_BRIDGE_MODE                 BRIDGE_MODE;            /**< \brief 0, GTM AEI Bridge Mode Register*/
       GTM_BRIDGE_PTR1                 BRIDGE_PTR1;            /**< \brief 4, GTM AEI Bridge Pointer 1 Register*/
       GTM_BRIDGE_PTR2                 BRIDGE_PTR2;            /**< \brief 8, GTM AEI Bridge Pointer 2 Register*/
       GTM_MCS_AEM_DIS                 MCS_AEM_DIS;            /**< \brief C, GTM MCS Master Port Disable Register*/
} GTM_AEI;

/* ============================================================================
   =============================== Module: GTM_CMU ================================
   ============================================================================ */
typedef union _GTM_CMU_CLK_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t EN_FXCLK:2;                   /**< \brief [23:22] Enable all CMU_FXCLK, see bits 1:0 (rw) */
        vuint32_t EN_ECLK2:2;                   /**< \brief [21:20] Enable ECLK 2 generation sub-unit (rw) */
        vuint32_t EN_ECLK1:2;                   /**< \brief [19:18] Enable ECLK 1 generation sub-unit (rw) */
        vuint32_t EN_ECLK0:2;                   /**< \brief [17:16] Enable ECLK 0 generation sub-unit (rw) */
        vuint32_t EN_CLK7:2;                    /**< \brief [15:14] Enable clock source x (rw) */
        vuint32_t EN_CLK6:2;                    /**< \brief [13:12] Enable clock source x (rw) */
        vuint32_t EN_CLK5:2;                    /**< \brief [11:10] Enable clock source x (rw) */
        vuint32_t EN_CLK4:2;                    /**< \brief [9:8] Enable clock source x (rw) */
        vuint32_t EN_CLK3:2;                    /**< \brief [7:6] Enable clock source x (rw) */
        vuint32_t EN_CLK2:2;                    /**< \brief [5:4] Enable clock source x (rw) */
        vuint32_t EN_CLK1:2;                    /**< \brief [3:2] Enable clock source x (rw) */
        vuint32_t EN_CLK0:2;                    /**< \brief [1:0] Enable clock source x (rw) */
    } B;
} GTM_CMU_CLK_EN;

typedef union _GTM_CMU_GCLK_NUM {
    vuint32_t R;
    struct{
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t GCLK_NUM:24;                  /**< \brief [23:0] GCLK_NUM (rw) */
    } B;
} GTM_CMU_GCLK_NUM;

typedef union _GTM_CMU_GCLK_DEN {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t GCLK_DEN:24;                  /**< \brief [23:0] GCLK_DEN (rw) */
    } B;
} GTM_CMU_GCLK_DEN;

typedef union _GTM_CMU_CLK__CTRL{
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
    //    vuint32_t CLK_SEL:2;                  /**< \brief [25:24] Clock source selection for CMU_CLKz (rw) */
        vuint32_t CLK_CNT:24;                   /**< \brief [23:0] Clock count (rw) */
    } B;
} GTM_CMU_CLK__CTRL;

typedef volatile struct _GTM_CMU_CLK {
       GTM_CMU_CLK__CTRL               CTRL;    /**< \brief 0, CMU Control for Clock Source ${z}*/
} GTM_CMU_CLK;

typedef union _GTM_CMU_CLK_6 {
    vuint32_t R;
    struct {
        vuint32_t reserved_26:6;                /**< \brief [31:26] \internal Reserved */
        vuint32_t CLK_SEL:2;                    /**< \brief [25:24] Clock source selection for CMU_CLKz (rw) */
        vuint32_t CLK_CNT:24;                   /**< \brief [23:0] Clock count (rw) */
    } B;
} GTM_CMU_CLK_6;

typedef union _GTM_CMU_CLK_7 {
    vuint32_t R;
    struct {
        vuint32_t reserved_26:6;                /**< \brief [31:26] \internal Reserved */
        vuint32_t CLK_SEL:2;                    /**< \brief [25:24] Clock source selection for CMU_CLKz (rw) */
        vuint32_t CLK_CNT:24;                   /**< \brief [23:0] Clock count (rw) */
    } B;
} GTM_CMU_CLK_7;

typedef union _GTM_CMU_ECLK_NUM {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t ECLK_NUM:24;                  /**< \brief [23:0] ECLK_NUM (rw) */
    } B;
} GTM_CMU_ECLK_NUM;

typedef union _GTM_CMU_ECLK_DEN {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t ECLK_DEN:24;                  /**< \brief [23:0] ECLK_DEN (rw) */
    } B;
} GTM_CMU_ECLK_DEN;

typedef volatile struct _GTM_CMU_ECLK {
       GTM_CMU_ECLK_NUM                NUM;     /**< \brief 0, CMU External Clock ${z} Control Numerator*/
       GTM_CMU_ECLK_DEN                DEN;     /**< \brief 4, CMU External Clock ${z} Control Denominator*/
} GTM_CMU_ECLK;

typedef union _GTM_CMU_FXCLK_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;                /**< \brief [31:4] \internal Reserved */
        vuint32_t FXCLK_SEL:4;                  /**< \brief [3:0] Input clock selection for EN_FXCLK line (rw) */
    } B;
} GTM_CMU_FXCLK_CTRL;

typedef volatile struct _GTM_CMU_FXCLK {
       GTM_CMU_FXCLK_CTRL              CTRL;                   /**< \brief 0, CMU Control FXCLK Sub-Unit Input Clock*/
} GTM_CMU_FXCLK;

typedef union _GTM_CMU_GLB_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;                /**< \brief [31:1] \internal Reserved */
        vuint32_t ARU_ADDR_RSTGLB:1;            /**< \brief [0:0] Reset ARU caddr counter and ARU dynamic route counter (rw) */
    } B;
} GTM_CMU_GLB_CTRL;

typedef union _GTM_CMU_CLK_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;                /**< \brief [31:9] \internal Reserved */
        vuint32_t CLK8_EXT_DIVIDER:1;           /**< \brief [8:8] Clock source selection for CMU_CLK8 (rw) */
        vuint32_t CLK7_EXT_DIVIDER:1;           /**< \brief [7:7] Clock source selection for CMU_CLK_7_CTRL (rw) */
        vuint32_t CLK6_EXT_DIVIDER:1;           /**< \brief [6:6] Clock source selection for CMU_CLK_6_CTRL (rw) */
        vuint32_t CLK5_EXT_DIVIDER:1;           /**< \brief [5:5] Clock source selection for CMU_CLK_5_CTRL (rw) */
        vuint32_t CLK4_EXT_DIVIDER:1;           /**< \brief [4:4] Clock source selection for CMU_CLK_4_CTRL (rw) */
        vuint32_t CLK3_EXT_DIVIDER:1;           /**< \brief [3:3] Clock source selection for CMU_CLK_3_CTRL (rw) */
        vuint32_t CLK2_EXT_DIVIDER:1;           /**< \brief [2:2] Clock source selection for CMU_CLK_2_CTRL (rw) */
        vuint32_t CLK1_EXT_DIVIDER:1;           /**< \brief [1:1] Clock source selection for CMU_CLK_1_CTRL (rw) */
        vuint32_t CLK0_EXT_DIVIDER:1;           /**< \brief [0:0] Clock source selection for CMU_CLK_0_CTRL (rw) */
    } B;
} GTM_CMU_CLK_CTRL;

typedef volatile struct _GTM_CMU {
       GTM_CMU_CLK_EN                  CLK_EN;                 /**< \brief 80, CMU Clock Enable Register*/
       GTM_CMU_GCLK_NUM                GCLK_NUM;               /**< \brief 84, CMU Global Clock Control Numerator*/
       GTM_CMU_GCLK_DEN                GCLK_DEN;               /**< \brief 88, CMU Global Clock Control Denominator*/
       GTM_CMU_CLK                     CLK[6];                 /**< \brief 8C, CMU Control for Clock Source ${z}*/
       GTM_CMU_CLK_6                   CLK_6;
       GTM_CMU_CLK_7                   CLK_7;
       GTM_CMU_ECLK                    ECLK[3];                /**< \brief AC, CMU External Clock ${z} Control Denominator*/
       GTM_CMU_FXCLK                   FXCLK;                  /**< \brief C4, CMU Control FXCLK Sub-Unit Input Clock*/
       GTM_CMU_GLB_CTRL                GLB_CTRL;               /**< \brief C8, CMU Synchronizing ARU and Clock Source*/
       GTM_CMU_CLK_CTRL                CLK_CTRL;               /**< \brief CC, CMU Control for Clock Source Selection*/
} GTM_CMU;

/* ============================================================================
   =============================== Module: GTM_INT ================================
   ============================================================================ */

typedef union _GTMINT_GTMMCR {
    vuint32_t R;
    struct {
        vuint32_t  :1;
        vuint32_t MDIS:1;                       /* [Covers: Saf1461] MDIS Module Disable. */
        vuint32_t  :13;
        vuint32_t AEISREN:1;                    /* Saf1276 - Safety-critical AEISREN AEI interface soft-reset control enable. */
        vuint32_t  :1;
        vuint32_t STPS:1;                       /* [Covers: Saf1461] STPS Stop Mode Status. */
        vuint32_t  :14;
    } B;
}  GTMINT_GTMMCR;

typedef union _GTMINT_GTMINTCLR {
    vuint32_t R;
    struct {
        vuint32_t  :22;
        vuint32_t INTCLR_PTR:10;                /* [Covers: Saf1461] INTCLR_PTR Interrupt Clear Pointer. */
    } B;
} GTMINT_GTMINTCLR;

typedef union _GTMINT_GTMAEICR {
    vuint32_t R;
    struct {
        vuint32_t  :31;
        vuint32_t  AEISRST:1;                   /* [Covers: Saf1461] AEISRST AEI interface soft-reset control. */
    } B;
} GTMINT_GTMAEICR;

typedef union _GTM_RESET1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;                /**< \brief [31:2] \internal Reserved */
        vuint32_t RSTSTAT:1;                    /**< \brief [1:1] Kernel Reset Status (rh) */
        vuint32_t RST:1;                        /**< \brief [0:0] Kernel Reset (rwh) */
    } B;
} GTM_RESET1;

typedef union _GTM_RESET_CLR {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;                /**< \brief [31:1] \internal Reserved */
        vuint32_t CLR:1;                        /**< \brief [0:0] Kernel Reset Status Clear (w) */
    } B;
} GTM_RESET_CLR;

typedef union _GTM_ACCEN0 {
    vuint32_t R;
    struct {
        vuint32_t EN0:1;                        /**< \brief [0:0] Access Enable for Master TAG ID 0 (rw) */
        vuint32_t EN1:1;                        /**< \brief [1:1] Access Enable for Master TAG ID 1 (rw) */
        vuint32_t EN2:1;                        /**< \brief [2:2] Access Enable for Master TAG ID 2 (rw) */
        vuint32_t EN3:1;                        /**< \brief [3:3] Access Enable for Master TAG ID 3 (rw) */
        vuint32_t EN4:1;                        /**< \brief [4:4] Access Enable for Master TAG ID 4 (rw) */
        vuint32_t EN5:1;                        /**< \brief [5:5] Access Enable for Master TAG ID 5 (rw) */
        vuint32_t EN6:1;                        /**< \brief [6:6] Access Enable for Master TAG ID 6 (rw) */
        vuint32_t EN7:1;                        /**< \brief [7:7] Access Enable for Master TAG ID 7 (rw) */
        vuint32_t EN8:1;                        /**< \brief [8:8] Access Enable for Master TAG ID 8 (rw) */
        vuint32_t EN9:1;                        /**< \brief [9:9] Access Enable for Master TAG ID 9 (rw) */
        vuint32_t EN10:1;                       /**< \brief [10:10] Access Enable for Master TAG ID 10 (rw) */
        vuint32_t EN11:1;                       /**< \brief [11:11] Access Enable for Master TAG ID 11 (rw) */
        vuint32_t EN12:1;                       /**< \brief [12:12] Access Enable for Master TAG ID 12 (rw) */
        vuint32_t EN13:1;                       /**< \brief [13:13] Access Enable for Master TAG ID 13 (rw) */
        vuint32_t EN14:1;                       /**< \brief [14:14] Access Enable for Master TAG ID 14 (rw) */
        vuint32_t EN15:1;                       /**< \brief [15:15] Access Enable for Master TAG ID 15 (rw) */
        vuint32_t EN16:1;                       /**< \brief [16:16] Access Enable for Master TAG ID 16 (rw) */
        vuint32_t EN17:1;                       /**< \brief [17:17] Access Enable for Master TAG ID 17 (rw) */
        vuint32_t EN18:1;                       /**< \brief [18:18] Access Enable for Master TAG ID 18 (rw) */
        vuint32_t EN19:1;                       /**< \brief [19:19] Access Enable for Master TAG ID 19 (rw) */
        vuint32_t EN20:1;                       /**< \brief [20:20] Access Enable for Master TAG ID 20 (rw) */
        vuint32_t EN21:1;                       /**< \brief [21:21] Access Enable for Master TAG ID 21 (rw) */
        vuint32_t EN22:1;                       /**< \brief [22:22] Access Enable for Master TAG ID 22 (rw) */
        vuint32_t EN23:1;                       /**< \brief [23:23] Access Enable for Master TAG ID 23 (rw) */
        vuint32_t EN24:1;                       /**< \brief [24:24] Access Enable for Master TAG ID 24 (rw) */
        vuint32_t EN25:1;                       /**< \brief [25:25] Access Enable for Master TAG ID 25 (rw) */
        vuint32_t EN26:1;                       /**< \brief [26:26] Access Enable for Master TAG ID 26 (rw) */
        vuint32_t EN27:1;                       /**< \brief [27:27] Access Enable for Master TAG ID 27 (rw) */
        vuint32_t EN28:1;                       /**< \brief [28:28] Access Enable for Master TAG ID 28 (rw) */
        vuint32_t EN29:1;                       /**< \brief [29:29] Access Enable for Master TAG ID 29 (rw) */
        vuint32_t EN30:1;                       /**< \brief [30:30] Access Enable for Master TAG ID 30 (rw) */
        vuint32_t EN31:1;                       /**< \brief [31:31] Access Enable for Master TAG ID 31 (rw) */
    }  B;
} GTM_ACCEN0;

typedef volatile struct _GTM_GTMINT {
    GTMINT_GTMMCR        GTMMCR;                /**< \brief 00  GTM Module Configuration Register */
    vuint8_t             reserved_04[4];        /**< \brief 04, \internal Reserved */
    GTMINT_GTMINTCLR     GTMINTCLR;             /**< \brief 08  GTM Interrupts Clear Register */
    GTMINT_GTMAEICR      GTMAEICR;              /**< \brief 0C GTM AEI Control Register */
    vuint8_t             MCSDBGEN;              /**< \brief 10 MCS Debug Enable Register*/
    GTM_RESET1           RESET1;                /**< \brief 14, Kernel Reset Register 0*/
    GTM_RESET_CLR        RESET_CLR;             /**< \brief 18, Kernel Reset Status Clear Register*/
    GTM_ACCEN0           ACCEN0;                /**< \brief 1C, Access Enable Register 0*/
}GTM_GTMINT;

/* ============================================================================
   =============================== Module: GTM_TBU ================================
   ============================================================================ */

typedef union _GTM_TBU_CHEN {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;                /**< \brief [31:8] \internal Reserved */
        vuint32_t ENDIS_CH3:2;                  /**< \brief [7:6] TBU channel 3 enable/disable control (rw) */
        vuint32_t ENDIS_CH2:2;                  /**< \brief [5:4] TBU channel 2 enable/disable control (rw) */
        vuint32_t ENDIS_CH1:2;                  /**< \brief [3:2] TBU channel 1 enable/disable control (rw) */
        vuint32_t ENDIS_CH0:2;                  /**< \brief [1:0] TBU channel 0 enable/disable control (rw) */
    } B;
} GTM_TBU_CHEN;

typedef union _GTM_TBU_CH0_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;                /**< \brief [31:4] \internal Reserved */
        vuint32_t CH_CLK_SRC:3;                 /**< \brief [3:1] Clock source for channel x (x:0...2) time base counter (rw) */
        vuint32_t LOW_RES:1;                    /**< \brief [0:0] TBU_CH0_BASE register resolution (rw) */
    } B;
} GTM_TBU_CH0_CTRL;

typedef union _GTM_TBU_CH0_BASE {
    vuint32_t R;
    struct {
        vuint32_t reserved_27:5;                /**< \brief [31:27] \internal Reserved */
        vuint32_t BASE:27;                      /**< \brief [26:0] Time base value for channel 0 (rw) */
    } B;
} GTM_TBU_CH0_BASE;

typedef union _GTM_TBU_CH1_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;                /**< \brief [31:4] \internal Reserved */
        vuint32_t CH_CLK_SRC:3;                 /**< \brief [3:1] Clock source for channel 1 time base counter (rw) */
        vuint32_t CH_MODE:1;                    /**< \brief [0:0] Channel mode (rw) */
    } B;
} GTM_TBU_CH1_CTRL;

typedef union _GTM_TBU_CH1_BASE {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t BASE:24;                      /**< \brief [23:0] Time base value for channel y (y: 1, 2) (rw) */
    } B;
} GTM_TBU_CH1_BASE;

typedef union _GTM_TBU_CH2_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;                /**< \brief [31:4] \internal Reserved */
        vuint32_t CH_CLK_SRC:3;                 /**< \brief [3:1] Clock source for channel 2 time base counter (rw) */
        vuint32_t CH_MODE:1;                    /**< \brief [0:0] Channel mode (rw) */
    } B;
} GTM_TBU_CH2_CTRL;

typedef union _GTM_TBU_CH2_BASE {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t BASE:24;                      /**< \brief [23:0] Time base value for channel y (y: 1, 2) (rw) */
    } B;
} GTM_TBU_CH2_BASE;

typedef union _GTM_TBU_CH3_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_5:27;                /**< \brief [31:5] \internal Reserved */
        vuint32_t USE_CH2:1;                    /**< \brief [4:4] Channel selector for modulo counter (rw) */
        vuint32_t reserved_1:3;                 /**< \brief [3:1] \internal Reserved */
        vuint32_t CH_MODE:1;                    /**< \brief [0:0] Channel mode (r) */
    } B;
} GTM_TBU_CH3_CTRL;

typedef union _GTM_TBU_CH3_BASE {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t BASE:24;                      /**< \brief [23:0] Time base value for channel 3 (rw) */
    } B;
} GTM_TBU_CH3_BASE;

typedef union _GTM_TBU_CH3_BASE_MARK {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t BASE_MARK:24;                 /**< \brief [23:0] Modulo value for channel 3 (rw) */
    } B;
} GTM_TBU_CH3_BASE_MARK;

typedef union _GTM_TBU_CH3_BASE_CAPTURE {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;                /**< \brief [31:24] \internal Reserved */
        vuint32_t BASE_CAPTURE:24;              /**< \brief [23:0] Captured value of time base channel 1 or 2 (r) */
    } B;
} GTM_TBU_CH3_BASE_CAPTURE;

typedef volatile struct _GTM_TBU {
       GTM_TBU_CHEN                    CHEN;                   /**< \brief 0, TBU Global Channel Enable*/
       GTM_TBU_CH0_CTRL                CH0_CTRL;               /**< \brief 4, TBU Channel 0 Control Register*/
       GTM_TBU_CH0_BASE                CH0_BASE;               /**< \brief 8, TBU Channel 0 Base Register*/
       GTM_TBU_CH1_CTRL                CH1_CTRL;               /**< \brief C, TBU Channel 1 Control Register*/
       GTM_TBU_CH1_BASE                CH1_BASE;               /**< \brief 10, TBU Channel 1 Base Register*/
       GTM_TBU_CH2_CTRL                CH2_CTRL;               /**< \brief 14, TBU Channel 2 Control Register*/
       GTM_TBU_CH2_BASE                CH2_BASE;               /**< \brief 18, TBU Channel 2 Base Register*/
       GTM_TBU_CH3_CTRL                CH3_CTRL;               /**< \brief 1C, TBU Channel 3 Control Register*/
       GTM_TBU_CH3_BASE                CH3_BASE;               /**< \brief 20, TBU Channel 3 Base Register*/
       GTM_TBU_CH3_BASE_MARK           CH3_BASE_MARK;          /**< \brief 24, TBU Channel 3 Modulo Value Register*/
       GTM_TBU_CH3_BASE_CAPTURE        CH3_BASE_CAPTURE;       /**< \brief 28, TBU Channel 3 Base Captured Register*/
       vuint8_t                        reserved_2C[84];        /**< \brief 2C, \internal Reserved */
} GTM_TBU;

/* ============================================================================
   =============================== Module: GTM_ARU ================================
   ============================================================================ */

typedef union _GTM_ARU_ACCESS {
    vuint32_t R;
    struct {
        vuint32_t reserved_14:18;               /**< \brief [31:14] \internal Reserved */
        vuint32_t WREQ:1;                       /**< \brief [13:13] Initiate write request (rw) */
        vuint32_t RREQ:1;                       /**< \brief [12:12] Initiate read request (rw) */
        vuint32_t reserved_9:3;                 /**< \brief [11:9] \internal Reserved */
        vuint32_t ADDR:9;                       /**< \brief [8:0] ARU address (rw) */
    } B;
} GTM_ARU_ACCESS;

typedef union _GTM_ARU_DATA_H {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;                /**< \brief [31:29] \internal Reserved */
        vuint32_t DATA:29;                      /**< \brief [28:0] Upper ARU data word (rw) */
    } B;
} GTM_ARU_DATA_H;

typedef union _GTM_ARU_DATA_L {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;                /**< \brief [31:29] \internal Reserved */
        vuint32_t DATA:29;                      /**< \brief [28:0] Lower ARU data word (rw) */
    } B;
} GTM_ARU_DATA_L;

typedef union _GTM_ARU_DBG_ACCESS0 {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;                /**< \brief [31:9] \internal Reserved */
        vuint32_t ADDR:9;                       /**< \brief [8:0] ARU debugging address (rw) */
    } B;
} GTM_ARU_DBG_ACCESS0;

typedef union _GTM_ARU_DBG_DATA0_H {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;                /**< \brief [31:29] \internal Reserved */
        vuint32_t DATA:29;                      /**< \brief [28:0] Upper debug data word (r) */
    } B;
} GTM_ARU_DBG_DATA0_H;

typedef union _GTM_ARU_DBG_DATA0_L {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;                /**< \brief [31:29] \internal Reserved */
        vuint32_t DATA:29;                      /**< \brief [28:0] Lower debug data word (r) */
    } B;
} GTM_ARU_DBG_DATA0_L;

typedef union _GTM_ARU_DBG_ACCESS1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;                /**< \brief [31:9] \internal Reserved */
        vuint32_t ADDR:9;                       /**< \brief [8:0] ARU debugging address (rw) */
    } B;
} GTM_ARU_DBG_ACCESS1;

typedef union _GTM_ARU_DBG_DATA1_H {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;                /**< \brief [31:29] \internal Reserved */
        vuint32_t DATA:29;                      /**< \brief [28:0] Upper debug data word (r) */
    } B;
} GTM_ARU_DBG_DATA1_H;

typedef union _GTM_ARU_DBG_DATA1_L {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;                /**< \brief [31:29] \internal Reserved */
        vuint32_t DATA:29;                      /**< \brief [28:0] Lower debug data word - DATA (r) */
    } B;
} GTM_ARU_DBG_DATA1_L;

typedef union _GTM_ARU_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_3:29;                /**< \brief [31:3] \internal Reserved */
        vuint32_t ACC_ACK:1;                    /**< \brief [2:2] AEI to ARU access finished, on read access data are valid (rw) */
        vuint32_t NEW_DATA1:1;                  /**< \brief [1:1] Data was transferred for addr ARU_DBG_ACCESS1 (rw) */
        vuint32_t NEW_DATA0:1;                  /**< \brief [0:0] Data was transferred for addr ARU_DBG_ACCESS0 (rw) */
    } B;
} GTM_ARU_IRQ_NOTIFY;

typedef union _GTM_ARU_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_3:29;                /**< \brief [31:3] \internal Reserved */
        vuint32_t ACC_ACK_IRQ_EN:1;             /**< \brief [2:2] ACC_ACK_IRQ interrupt enable (rw) */
        vuint32_t NEW_DATA1_IRQ_EN:1;           /**< \brief [1:1] ARU_NEW_DATA1_IRQ interrupt enable (rw) */
        vuint32_t NEW_DATA0_IRQ_EN:1;           /**< \brief [0:0] ARU_NEW_DATA0_IRQ interrupt enable (rw) */
    } B;
} GTM_ARU_IRQ_EN;

typedef union _GTM_ARU_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_3:29;                /**< \brief [31:3] \internal Reserved */
        vuint32_t TRG_ACC_ACK:1;                /**< \brief [2:2] Trigger ACC_ACK interrupt (rw) */
        vuint32_t TRG_NEW_DATA1:1;              /**< \brief [1:1] Trigger new data 1 interrupt (rw) */
        vuint32_t TRG_NEW_DATA0:1;              /**< \brief [0:0] Trigger new data 0 interrupt (rw) */
    } B;
} GTM_ARU_IRQ_FORCINT;

typedef union _GTM_ARU_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;                /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;                   /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_ARU_IRQ_MODE;

typedef union _GTM_ARU_CADDR_END {
    vuint32_t R;
    struct {
        vuint32_t reserved_7:25;                /**< \brief [31:7] \internal Reserved */
        vuint32_t CADDR_END:7;                  /**< \brief [6:0] Set end value of ARU caddr counter (rw) */
    } B;
} GTM_ARU_CADDR_END;

typedef union _GTM_ARU_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_5:27;                /**< \brief [31:5] \internal Reserved */
        vuint32_t ARU_DYN_RING_MODE:1;          /**< \brief [4:4] Enable dynamic routing ring mode (rw) */
        vuint32_t ARU_1_DYN_EN:2;               /**< \brief [3:2] Enable dynamic routing for ARU-1 (rw) */
        vuint32_t ARU_0_DYN_EN:2;               /**< \brief [1:0] Enable dynamic routing for ARU-0 (rw) */
    } B;
} GTM_ARU_CTRL;

typedef union _GTM_ARU_DYN_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;                /**< \brief [31:2] \internal Reserved */
        vuint32_t DYN_ROUTE_SWAP:1;             /**< \brief [1:1] Enable swapping DYN_ROUTE_SR with DYN_ROUTE register (rw) */
        vuint32_t DYN_ARU_UPDATE_EN:1;          /**< \brief [0:0] Enable reload of DYN_ROUTE register from ARU itself (rw) */
    } B;
} GTM_ARU_DYN_CTRL;

typedef union _GTM_ARU_DYN_ROUTE_LOW {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DYN_READ_ID2:8;    /**< \brief [23:16] ARU read ID 2 (rw) */
        vuint32_t DYN_READ_ID1:8;    /**< \brief [15:8] ARU read ID 1 (rw) */
        vuint32_t DYN_READ_ID0:8;    /**< \brief [7:0] ARU read ID 0 (rw) */
    } B;
} GTM_ARU_DYN_ROUTE_LOW;

typedef union _GTM_ARU_DYN_ROUTE_HIGH {
    vuint32_t R;
    struct {
        vuint32_t reserved_28:4;     /**< \brief [31:28] \internal Reserved */
        vuint32_t DYN_CLK_WAIT:4;    /**< \brief [27:24] Number of clk cycles for dynamic routing (rw) */
        vuint32_t DYN_READ_ID5:8;    /**< \brief [23:16] ARU read ID 5 (rw) */
        vuint32_t DYN_READ_ID4:8;    /**< \brief [15:8] ARU read ID 4 (rw) */
        vuint32_t DYN_READ_ID3:8;    /**< \brief [7:0] ARU read ID 3 (rw) */
    } B;
} GTM_ARU_DYN_ROUTE_HIGH;

typedef union _GTM_ARU_DYN_ROUTE_SR_LOW {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DYN_READ_ID8:8;    /**< \brief [23:16] ARU read ID 8 (rw) */
        vuint32_t DYN_READ_ID7:8;    /**< \brief [15:8] ARU read ID 7 (rw) */
        vuint32_t DYN_READ_ID6:8;    /**< \brief [7:0] ARU read ID 6 (rw) */
    } B;
} GTM_ARU_DYN_ROUTE_SR_LOW;

typedef union _GTM_ARU_DYN_ROUTE_SR_HIGH {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;    /**< \brief [31:29] \internal Reserved */
        vuint32_t DYN_UPDATE_EN:1;    /**< \brief [28:28] Update enable from shadow register (rw) */
        vuint32_t DYN_CLK_WAIT:4;    /**< \brief [27:24] Number of clk cycles for dynamic routing (rw) */
        vuint32_t DYN_READ_ID11:8;    /**< \brief [23:16] ARU read ID 11 (rw) */
        vuint32_t DYN_READ_ID10:8;    /**< \brief [15:8] ARU read ID 10 (rw) */
        vuint32_t DYN_READ_ID9:8;    /**< \brief [7:0] ARU read ID 9 (rw) */
    } B;
} GTM_ARU_DYN_ROUTE_SR_HIGH;

typedef union _GTM_ARU_DYN_RDADDR {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;    /**< \brief [31:9] \internal Reserved */
        vuint32_t DYN_ARU_RDADDR:9;    /**< \brief [8:0] ARU read address ID to reload the DYN_ROUTE register (rw) */
    } B;
} GTM_ARU_DYN_RDADDR;

typedef union _GTM_ARU_CADDR {
    vuint32_t R;
    struct {
        vuint32_t reserved_23:9;   /**< \brief [31:23] \internal Reserved */
        vuint32_t CADDR_1:7;       /**< \brief [22:16] Value of ARU-1 caddr counter (r) */
        vuint32_t reserved_7:9;    /**< \brief [15:7] \internal Reserved */
        vuint32_t CADDR_0:7;       /**< \brief [6:0] Value of ARU-0 caddr counter (r) */
    } B;
} GTM_ARU_CADDR;

typedef volatile struct _GTM_ARU {
       GTM_ARU_ACCESS                  ACCESS;                 /**< \brief 0, ARU Access Register*/
       GTM_ARU_DATA_H                  DATA_H;                 /**< \brief 4, ARU Access Register Upper Data Word*/
       GTM_ARU_DATA_L                  DATA_L;                 /**< \brief 8, ARU Access Register Lower Data Word*/
       GTM_ARU_DBG_ACCESS0             DBG_ACCESS0;            /**< \brief C, ARU Debug Access Channel 0*/
       GTM_ARU_DBG_DATA0_H             DBG_DATA0_H;            /**< \brief 10, ARU Debug Access 0 Transfer Register Upper Data Word*/
       GTM_ARU_DBG_DATA0_L             DBG_DATA0_L;            /**< \brief 14, ARU Debug Access 0 Transfer Register Lower Data Word*/
       GTM_ARU_DBG_ACCESS1             DBG_ACCESS1;            /**< \brief 18, ARU Debug Access Channel 1*/
       GTM_ARU_DBG_DATA1_H             DBG_DATA1_H;            /**< \brief 1C, ARU Debug Access 1 Transfer Register Upper Data Word*/
       GTM_ARU_DBG_DATA1_L             DBG_DATA1_L;            /**< \brief 20, ARU Debug Access 1 Transfer Register Lower Data Word*/
       GTM_ARU_IRQ_NOTIFY              IRQ_NOTIFY;             /**< \brief 24, ARU Interrupt Notification Register*/
       GTM_ARU_IRQ_EN                  IRQ_EN;                 /**< \brief 28, ARU Interrupt Enable Register*/
       GTM_ARU_IRQ_FORCINT             IRQ_FORCINT;            /**< \brief 2C, ARU Force Interrupt Register*/
       GTM_ARU_IRQ_MODE                IRQ_MODE;               /**< \brief 30, ARU Interrupt Mode Register*/
       GTM_ARU_CADDR_END               CADDR_END;              /**< \brief 34, ARU caddr Counter End Value Register*/
       vuint8_t                        reserved_38[4];         /**< \brief 38, \internal Reserved */
       GTM_ARU_CTRL                    CTRL;                   /**< \brief 3C, ARU Enable Dynamic Routing Register*/
       GTM_ARU_DYN_CTRL                DYN_CTRL[2];            /**< \brief 40, ARU ${z} Dynamic Routing Control Register*/
       GTM_ARU_DYN_ROUTE_LOW           DYN_ROUTE_LOW[2];       /**< \brief 48, ARU ${z} Lower Bits of DYN_ROUTE Register*/
       GTM_ARU_DYN_ROUTE_HIGH          DYN_ROUTE_HIGH[2];      /**< \brief 50, ARU ${z} Higher Bits of DYN_ROUTE Register*/
       GTM_ARU_DYN_ROUTE_SR_LOW        DYN_ROUTE_SR_LOW[2];    /**< \brief 58, ARU ${z} Shadow Register for ARU_${z}_DYN_ROUTE_LOW*/
       GTM_ARU_DYN_ROUTE_SR_HIGH       DYN_ROUTE_SR_HIGH[2];   /**< \brief 60, ARU ${z} Shadow Register for ARU_${z}_DYN_ROUTE_HIGH*/
       GTM_ARU_DYN_RDADDR              DYN_RDADDR[2];          /**< \brief 68, ARU ${z} Read ID for Dynamic Routing*/
       vuint8_t                        reserved_70[12];        /**< \brief 70, \internal Reserved */
       GTM_ARU_CADDR                   CADDR;                  /**< \brief 7C, ARU caddr Counter Value*/
} GTM_ARU;

/* ============================================================================
   =============================== Module: GTM_BRC ================================
   ============================================================================ */
typedef union _GTM_BRC_SRC_ADDR {
    vuint32_t R;
    struct {
        vuint32_t reserved_13:19;    /**< \brief [31:13] \internal Reserved */
        vuint32_t BRC_MODE:1;      /**< \brief [12:12] BRC_MODE: BRC Operation mode select (rw) */
        vuint32_t reserved_9:3;    /**< \brief [11:9] \internal Reserved */
        vuint32_t ADDR:9;          /**< \brief [8:0] Source ARU address. Defines an ARU read address used as data source for input channel z (rw) */
    } B;
} GTM_BRC_SRC_ADDR;

typedef union _GTM_BRC_SRC_DEST {
    vuint32_t R;
    struct {
        vuint32_t reserved_23:9;    /**< \brief [31:23] \internal Reserved */
        vuint32_t EN_TRASHBIN:1;    /**< \brief [22:22] EN_TRASHBIN: Control trash bin functionality (rw) */
        vuint32_t EN_DEST21:1;     /**< \brief [21:21] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST20:1;     /**< \brief [20:20] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST19:1;     /**< \brief [19:19] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST18:1;     /**< \brief [18:18] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST17:1;     /**< \brief [17:17] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST16:1;     /**< \brief [16:16] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST15:1;     /**< \brief [15:15] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST14:1;     /**< \brief [14:14] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST13:1;     /**< \brief [13:13] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST12:1;     /**< \brief [12:12] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST11:1;     /**< \brief [11:11] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST10:1;     /**< \brief [10:10] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST9:1;      /**< \brief [9:9] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST8:1;      /**< \brief [8:8] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST7:1;      /**< \brief [7:7] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST6:1;      /**< \brief [6:6] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST5:1;      /**< \brief [5:5] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST4:1;      /**< \brief [4:4] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST3:1;      /**< \brief [3:3] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST2:1;      /**< \brief [2:2] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST1:1;      /**< \brief [1:1] Enable BRC destination address q (rw) */
        vuint32_t EN_DEST0:1;      /**< \brief [0:0] Enable BRC destination address q (rw) */
    } B;
} GTM_BRC_SRC_DEST;

typedef volatile struct _GTM_BRC_SRC {
       GTM_BRC_SRC_ADDR                ADDR;                   /**< \brief 0, BRC Read Address for Input Channel ${z}*/
       GTM_BRC_SRC_DEST                DEST;                   /**< \brief 4, BRC Destination Channels for Input Channel ${z}*/
} GTM_BRC_SRC;

typedef union _GTM_BRC_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_13:19;    /**< \brief [31:13] \internal Reserved */
        vuint32_t DID11:1;         /**< \brief [12:12] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID10:1;         /**< \brief [11:11] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID9:1;          /**< \brief [10:10] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID8:1;          /**< \brief [9:9] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID7:1;          /**< \brief [8:8] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID6:1;          /**< \brief [7:7] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID5:1;          /**< \brief [6:6] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID4:1;          /**< \brief [5:5] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID3:1;          /**< \brief [4:4] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID2:1;          /**< \brief [3:3] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID1:1;          /**< \brief [2:2] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DID0:1;          /**< \brief [1:1] Data inconsistency occurred for channel x in MTM mode (rw) */
        vuint32_t DEST_ERR:1;      /**< \brief [0:0] Configuration error interrupt for BRC sub-module (rw) */
    } B;
} GTM_BRC_IRQ_NOTIFY;

typedef union _GTM_BRC_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_13:19;    /**< \brief [31:13] \internal Reserved */
        vuint32_t DID_IRQ_EN11:1;    /**< \brief [12:12] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN10:1;    /**< \brief [11:11] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN9:1;    /**< \brief [10:10] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN8:1;    /**< \brief [9:9] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN7:1;    /**< \brief [8:8] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN6:1;    /**< \brief [7:7] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN5:1;    /**< \brief [6:6] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN4:1;    /**< \brief [5:5] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN3:1;    /**< \brief [4:4] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN2:1;    /**< \brief [3:3] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN1:1;    /**< \brief [2:2] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_IRQ_EN0:1;    /**< \brief [1:1] Enable DID interrupt for channel x (rw) */
        vuint32_t DEST_ERR_IRQ_EN:1;    /**< \brief [0:0] BRC_DEST_ERR_IRQ interrupt enable (rw) */
    } B;
} GTM_BRC_IRQ_EN;

typedef union _GTM_BRC_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_13:19;    /**< \brief [31:13] \internal Reserved */
        vuint32_t TRG_DID11:1;     /**< \brief [12:12] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID10:1;     /**< \brief [11:11] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID9:1;      /**< \brief [10:10] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID8:1;      /**< \brief [9:9] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID7:1;      /**< \brief [8:8] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID6:1;      /**< \brief [7:7] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID5:1;      /**< \brief [6:6] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID4:1;      /**< \brief [5:5] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID3:1;      /**< \brief [4:4] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID2:1;      /**< \brief [3:3] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID1:1;      /**< \brief [2:2] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DID0:1;      /**< \brief [1:1] Trigger DID interrupt for channel x (rw) */
        vuint32_t TRG_DEST_ERR:1;    /**< \brief [0:0] Trigger destination error interrupt (rw) */
    } B;
} GTM_BRC_IRQ_FORCINT;

typedef union _GTM_BRC_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;      /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_BRC_IRQ_MODE;

typedef union _GTM_BRC_RST {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;    /**< \brief [31:1] \internal Reserved */
        vuint32_t RST:1;           /**< \brief [0:0] Software reset (rw) */
    } B;
} GTM_BRC_RST;

typedef union _GTM_BRC_EIRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_13:19;    /**< \brief [31:13] \internal Reserved */
        vuint32_t DID_EIRQ_EN11:1;    /**< \brief [12:12] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN10:1;    /**< \brief [11:11] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN9:1;    /**< \brief [10:10] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN8:1;    /**< \brief [9:9] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN7:1;    /**< \brief [8:8] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN6:1;    /**< \brief [7:7] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN5:1;    /**< \brief [6:6] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN4:1;    /**< \brief [5:5] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN3:1;    /**< \brief [4:4] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN2:1;    /**< \brief [3:3] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN1:1;    /**< \brief [2:2] Enable DID interrupt for channel x (rw) */
        vuint32_t DID_EIRQ_EN0:1;    /**< \brief [1:1] Enable DID interrupt for channel x (rw) */
        vuint32_t DEST_ERR_EIRQ_EN:1;    /**< \brief [0:0] BRC_DEST_ERR_EIRQ error interrupt enable (rw) */
    } B;
} GTM_BRC_EIRQ_EN;

typedef volatile struct _GTM_BRC {
       GTM_BRC_SRC                     SRC[12];                /**< \brief 0, */
       GTM_BRC_IRQ_NOTIFY              IRQ_NOTIFY;             /**< \brief 60, BRC Interrupt Notification Register*/
       GTM_BRC_IRQ_EN                  IRQ_EN;                 /**< \brief 64, BRC Interrupt Enable Register*/
       GTM_BRC_IRQ_FORCINT             IRQ_FORCINT;            /**< \brief 68, BRC Force Interrupt Register*/
       GTM_BRC_IRQ_MODE                IRQ_MODE;               /**< \brief 6C, BRC Interrupt Mode Configuration Register*/
       GTM_BRC_RST                     RST;                    /**< \brief 70, BRC Software Reset Register*/
       GTM_BRC_EIRQ_EN                 EIRQ_EN;                /**< \brief 74, BRC Error Interrupt Enable Register*/
       vuint8_t                   reserved_78[392];       /**< \brief 78, \internal Reserved */
} GTM_BRC;

/* ============================================================================
   =============================== Module: GTM_ICM ================================
   ============================================================================ */
typedef union _GTM_ICM_IRQG_R0 {
    vuint32_t R;
    struct {
        vuint32_t PSM1_CH7_IRQ:1;    /**< \brief [31:31] PSM1 shared sub-module channel 7 interrupt (r) */
        vuint32_t PSM1_CH6_IRQ:1;    /**< \brief [30:30] PSM1 shared sub-module channel 6 interrupt (r) */
        vuint32_t PSM1_CH5_IRQ:1;    /**< \brief [29:29] PSM1 shared sub-module channel 5 interrupt (r) */
        vuint32_t PSM1_CH4_IRQ:1;    /**< \brief [28:28] PSM1 shared sub-module channel 4 interrupt (r) */
        vuint32_t PSM1_CH3_IRQ:1;    /**< \brief [27:27] PSM1 shared sub-module channel 3 interrupt (r) */
        vuint32_t PSM1_CH2_IRQ:1;    /**< \brief [26:26] PSM1 shared sub-module channel 2 interrupt (r) */
        vuint32_t PSM1_CH1_IRQ:1;    /**< \brief [25:25] PSM1 shared sub-module channel 1 interrupt (r) */
        vuint32_t PSM1_CH0_IRQ:1;    /**< \brief [24:24] PSM1 shared sub-module channel 0 interrupt (r) */
        vuint32_t PSM0_CH7_IRQ:1;    /**< \brief [23:23] PSM0 shared sub-module channel 7 interrupt (r) */
        vuint32_t PSM0_CH6_IRQ:1;    /**< \brief [22:22] PSM0 shared sub-module channel 6 interrupt (r) */
        vuint32_t PSM0_CH5_IRQ:1;    /**< \brief [21:21] PSM0 shared sub-module channel 5 interrupt (r) */
        vuint32_t PSM0_CH4_IRQ:1;    /**< \brief [20:20] PSM0 shared sub-module channel 4 interrupt (r) */
        vuint32_t PSM0_CH3_IRQ:1;    /**< \brief [19:19] PSM0 shared sub-module channel 3 interrupt (r) */
        vuint32_t PSM0_CH2_IRQ:1;    /**< \brief [18:18] PSM0 shared sub-module channel 2 interrupt (r) */
        vuint32_t PSM0_CH1_IRQ:1;    /**< \brief [17:17] PSM0 shared sub-module channel 1 interrupt (r) */
        vuint32_t PSM0_CH0_IRQ:1;    /**< \brief [16:16] PSM0 shared sub-module channel 0 interrupt (r) */
        vuint32_t reserved_14:2;    /**< \brief [15:14] \internal Reserved */
        vuint32_t SPE7_IRQ:1;      /**< \brief [13:13] SPE5 shared sub-module interrupt (r) */
        vuint32_t SPE6_IRQ:1;      /**< \brief [12:12] SPE5 shared sub-module interrupt (r) */
        vuint32_t SPE5_IRQ:1;      /**< \brief [11:11] SPE5 shared sub-module interrupt (r) */
        vuint32_t SPE4_IRQ:1;      /**< \brief [10:10] SPE4 shared sub-module interrupt (r) */
        vuint32_t SPE3_IRQ:1;      /**< \brief [9:9] SPE3 shared sub-module interrupt (r) */
        vuint32_t SPE2_IRQ:1;      /**< \brief [8:8] SPE2 shared sub-module interrupt (r) */
        vuint32_t SPE1_IRQ:1;      /**< \brief [7:7] SPE1 shared sub-module interrupt (r) */
        vuint32_t SPE0_IRQ:1;      /**< \brief [6:6] SPE0 shared sub-module interrupt (r) */
        vuint32_t CMP_IRQ:1;       /**< \brief [5:5] CMP shared sub-module interrupt (r) */
        vuint32_t AEI_IRQ:1;       /**< \brief [4:4] AEI_IRQ interrupt (r) */
        vuint32_t BRC_IRQ:1;       /**< \brief [3:3] BRC shared sub-module interrupt (r) */
        vuint32_t ARU_ACC_ACK_IRQ:1;    /**< \brief [2:2] ARU_ACC_ACK interrupt (r) */
        vuint32_t ARU_NEW_DATA1_IRQ:1;    /**< \brief [1:1] ARU_NEW_DATA1 interrupt (r) */
        vuint32_t ARU_NEW_DATA0_IRQ:1;    /**< \brief [0:0] ARU_NEW_DATA0 interrupt (r) */
    } B;
} GTM_ICM_IRQG_R0;

typedef union _GTM_ICM_IRQG_R1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_27:5;    /**< \brief [31:27] \internal Reserved */
        vuint32_t DPLL_SORI_IRQ:1;    /**< \brief [26:26] DPLL calculated duration interrupt for state (r) */
        vuint32_t DPLL_TORI_IRQ:1;    /**< \brief [25:25] DPLL calculated duration interrupt for state (r) */
        vuint32_t DPLL_CDSI_IRQ:1;    /**< \brief [24:24] DPLL calculated duration interrupt for state (r) */
        vuint32_t DPLL_CDTI_IRQ:1;    /**< \brief [23:23] DPLL calculated duration interrupt for trigger (r) */
        vuint32_t DPLL_TE4I_IRQ:1;    /**< \brief [22:22] TRIGGER event interrupt 4 (r) */
        vuint32_t DPLL_TE3I_IRQ:1;    /**< \brief [21:21] TRIGGER event interrupt 3 (r) */
        vuint32_t DPLL_TE2I_IRQ:1;    /**< \brief [20:20] TRIGGER event interrupt 2 (r) */
        vuint32_t DPLL_TE1I_IRQ:1;    /**< \brief [19:19] TRIGGER event interrupt 1 (r) */
        vuint32_t DPLL_TE0I_IRQ:1;    /**< \brief [18:18] TRIGGER event interrupt 0 (r) */
        vuint32_t DPLL_LL2I_IRQ:1;    /**< \brief [17:17] Loss of lock interrupt for SUB_INC2 (r) */
        vuint32_t DPLL_GL2I_IRQ:1;    /**< \brief [16:16] Get of lock interrupt for SUB_INC2 (r) */
        vuint32_t DPLL_EI_IRQ:1;      /**< \brief [15:15] Error interrupt (r) */
        vuint32_t DPLL_LL1I_IRQ:1;    /**< \brief [14:14] Loss of lock interrupt for SUB_INC1 (r) */
        vuint32_t DPLL_GL1I_IRQ:1;    /**< \brief [13:13] Get of lock interrupt for SUB_INC1 (r) */
        vuint32_t DPLL_W1I_IRQ:1;    /**< \brief [12:12] Write access to RAM region 1b or 1c interrupt (r) */
        vuint32_t DPLL_W2I_IRQ:1;    /**< \brief [11:11] Write access to RAM region 2 interrupt (r) */
        vuint32_t DPLL_PWI_IRQ:1;    /**< \brief [10:10] Plausibility window (PVT) violation interrupt of TRIGGER (r) */
        vuint32_t DPLL_TASI_IRQ:1;    /**< \brief [9:9] TRIGGER active slope detected while NTI_CNT is zero (r) */
        vuint32_t DPLL_SASI_IRQ:1;    /**< \brief [8:8] STATE active slope detected (r) */
        vuint32_t DPLL_MTI_IRQ:1;    /**< \brief [7:7] Missing TRIGGER interrupt (r) */
        vuint32_t DPLL_MSI_IRQ:1;    /**< \brief [6:6] Missing STATE interrupt (r) */
        vuint32_t DPLL_TISI_IRQ:1;    /**< \brief [5:5] TRIGGER inactive slope detected interrupt (r) */
        vuint32_t DPLL_SISI_IRQ:1;    /**< \brief [4:4] STATE inactive slope detected interrupt (r) */
        vuint32_t DPLL_TAXI_IRQ:1;    /**< \brief [3:3] TRIGGER maximum hold time (THMA) violation detected interrupt (r) */
        vuint32_t DPLL_TINI_IRQ:1;    /**< \brief [2:2] TRIGGER minimum hold time (THMI) violation detected interrupt (r) */
        vuint32_t DPLL_EDI_IRQ:1;    /**< \brief [1:1] DPLL enable/disable interrupt (r) */
        vuint32_t DPLL_DCGI_IRQ:1;    /**< \brief [0:0] TRIGGER direction change detected (r) */
    } B;
} GTM_ICM_IRQG_R1;

typedef union _GTM_ICM_IRQG_R2 {
    vuint32_t R;
    struct {
        vuint32_t TIM3_CH7_IRQ:1;    /**< \brief [31:31] TIM2 shared interrupt channel 7 (r) */
        vuint32_t TIM3_CH6_IRQ:1;    /**< \brief [30:30] TIM2 shared interrupt channel 6 (r) */
        vuint32_t TIM3_CH5_IRQ:1;    /**< \brief [29:29] TIM2 shared interrupt channel 5 (r) */
        vuint32_t TIM3_CH4_IRQ:1;    /**< \brief [28:28] TIM2 shared interrupt channel 4 (r) */
        vuint32_t TIM3_CH3_IRQ:1;    /**< \brief [27:27] TIM2 shared interrupt channel 3 (r) */
        vuint32_t TIM3_CH2_IRQ:1;    /**< \brief [26:26] TIM2 shared interrupt channel 2 (r) */
        vuint32_t TIM3_CH1_IRQ:1;    /**< \brief [25:25] TIM2 shared interrupt channel 1 (r) */
        vuint32_t TIM3_CH0_IRQ:1;    /**< \brief [24:24] TIM2 shared interrupt channel 0 (r) */
        vuint32_t TIM2_CH7_IRQ:1;    /**< \brief [23:23] TIM2 shared interrupt channel 7 (r) */
        vuint32_t TIM2_CH6_IRQ:1;    /**< \brief [22:22] TIM2 shared interrupt channel 6 (r) */
        vuint32_t TIM2_CH5_IRQ:1;    /**< \brief [21:21] TIM2 shared interrupt channel 5 (r) */
        vuint32_t TIM2_CH4_IRQ:1;    /**< \brief [20:20] TIM2 shared interrupt channel 4 (r) */
        vuint32_t TIM2_CH3_IRQ:1;    /**< \brief [19:19] TIM2 shared interrupt channel 3 (r) */
        vuint32_t TIM2_CH2_IRQ:1;    /**< \brief [18:18] TIM2 shared interrupt channel 2 (r) */
        vuint32_t TIM2_CH1_IRQ:1;    /**< \brief [17:17] TIM2 shared interrupt channel 1 (r) */
        vuint32_t TIM2_CH0_IRQ:1;    /**< \brief [16:16] TIM2 shared interrupt channel 0 (r) */
        vuint32_t TIM1_CH7_IRQ:1;    /**< \brief [15:15] TIM1 shared interrupt channel 7 (r) */
        vuint32_t TIM1_CH6_IRQ:1;    /**< \brief [14:14] TIM1 shared interrupt channel 6 (r) */
        vuint32_t TIM1_CH5_IRQ:1;    /**< \brief [13:13] TIM1 shared interrupt channel 5 (r) */
        vuint32_t TIM1_CH4_IRQ:1;    /**< \brief [12:12] TIM1 shared interrupt channel 4 (r) */
        vuint32_t TIM1_CH3_IRQ:1;    /**< \brief [11:11] TIM1 shared interrupt channel 3 (r) */
        vuint32_t TIM1_CH2_IRQ:1;    /**< \brief [10:10] TIM1 shared interrupt channel 2 (r) */
        vuint32_t TIM1_CH1_IRQ:1;    /**< \brief [9:9] TIM1 shared interrupt channel 1 (r) */
        vuint32_t TIM1_CH0_IRQ:1;    /**< \brief [8:8] TIM1 shared interrupt channel 0 (r) */
        vuint32_t TIM0_CH7_IRQ:1;    /**< \brief [7:7] TIM0 shared interrupt channel 7 (r) */
        vuint32_t TIM0_CH6_IRQ:1;    /**< \brief [6:6] TIM0 shared interrupt channel 6 (r) */
        vuint32_t TIM0_CH5_IRQ:1;    /**< \brief [5:5] TIM0 shared interrupt channel 5 (r) */
        vuint32_t TIM0_CH4_IRQ:1;    /**< \brief [4:4] TIM0 shared interrupt channel 4 (r) */
        vuint32_t TIM0_CH3_IRQ:1;    /**< \brief [3:3] TIM0 shared interrupt channel 3 (r) */
        vuint32_t TIM0_CH2_IRQ:1;    /**< \brief [2:2] TIM0 shared interrupt channel 2 (r) */
        vuint32_t TIM0_CH1_IRQ:1;    /**< \brief [1:1] TIM0 shared interrupt channel 1 (r) */
        vuint32_t TIM0_CH0_IRQ:1;    /**< \brief [0:0] TIM0 shared interrupt channel 0 (r) */
    } B;
} GTM_ICM_IRQG_R2;

typedef union _GTM_ICM_IRQG_R3 {
    vuint32_t R;
    struct {
        vuint32_t TIM7_CH7_IRQ:1;    /**< \brief [31:31] TIM7 shared interrupt channel 7 (r) */
        vuint32_t TIM7_CH6_IRQ:1;    /**< \brief [30:30] TIM7 shared interrupt channel 6 (r) */
        vuint32_t TIM7_CH5_IRQ:1;    /**< \brief [29:29] TIM7 shared interrupt channel 5 (r) */
        vuint32_t TIM7_CH4_IRQ:1;    /**< \brief [28:28] TIM7 shared interrupt channel 4 (r) */
        vuint32_t TIM7_CH3_IRQ:1;    /**< \brief [27:27] TIM7 shared interrupt channel 3 (r) */
        vuint32_t TIM7_CH2_IRQ:1;    /**< \brief [26:26] TIM7 shared interrupt channel 2 (r) */
        vuint32_t TIM7_CH1_IRQ:1;    /**< \brief [25:25] TIM7 shared interrupt channel 1 (r) */
        vuint32_t TIM7_CH0_IRQ:1;    /**< \brief [24:24] TIM7 shared interrupt channel 0 (r) */
        vuint32_t TIM6_CH7_IRQ:1;    /**< \brief [23:23] TIM6 shared interrupt channel 7 (r) */
        vuint32_t TIM6_CH6_IRQ:1;    /**< \brief [22:22] TIM6 shared interrupt channel 6 (r) */
        vuint32_t TIM6_CH5_IRQ:1;    /**< \brief [21:21] TIM6 shared interrupt channel 5 (r) */
        vuint32_t TIM6_CH4_IRQ:1;    /**< \brief [20:20] TIM6 shared interrupt channel 4 (r) */
        vuint32_t TIM6_CH3_IRQ:1;    /**< \brief [19:19] TIM6 shared interrupt channel 3 (r) */
        vuint32_t TIM6_CH2_IRQ:1;    /**< \brief [18:18] TIM6 shared interrupt channel 2 (r) */
        vuint32_t TIM6_CH1_IRQ:1;    /**< \brief [17:17] TIM6 shared interrupt channel 1 (r) */
        vuint32_t TIM6_CH0_IRQ:1;    /**< \brief [16:16] TIM6 shared interrupt channel 0 (r) */
        vuint32_t TIM5_CH7_IRQ:1;    /**< \brief [15:15] TIM5 shared interrupt channel 7 (r) */
        vuint32_t TIM5_CH6_IRQ:1;    /**< \brief [14:14] TIM5 shared interrupt channel 6 (r) */
        vuint32_t TIM5_CH5_IRQ:1;    /**< \brief [13:13] TIM5 shared interrupt channel 5 (r) */
        vuint32_t TIM5_CH4_IRQ:1;    /**< \brief [12:12] TIM5 shared interrupt channel 4 (r) */
        vuint32_t TIM5_CH3_IRQ:1;    /**< \brief [11:11] TIM5 shared interrupt channel 3 (r) */
        vuint32_t TIM5_CH2_IRQ:1;    /**< \brief [10:10] TIM5 shared interrupt channel 2 (r) */
        vuint32_t TIM5_CH1_IRQ:1;    /**< \brief [9:9] TIM5 shared interrupt channel 1 (r) */
        vuint32_t TIM5_CH0_IRQ:1;    /**< \brief [8:8] TIM5 shared interrupt channel 0 (r) */
        vuint32_t TIM4_CH7_IRQ:1;    /**< \brief [7:7] TIM4 shared interrupt channel 7 (r) */
        vuint32_t TIM4_CH6_IRQ:1;    /**< \brief [6:6] TIM4 shared interrupt channel 6 (r) */
        vuint32_t TIM4_CH5_IRQ:1;    /**< \brief [5:5] TIM4 shared interrupt channel 5 (r) */
        vuint32_t TIM4_CH4_IRQ:1;    /**< \brief [4:4] TIM4 shared interrupt channel 4 (r) */
        vuint32_t TIM4_CH3_IRQ:1;    /**< \brief [3:3] TIM4 shared interrupt channel 3 (r) */
        vuint32_t TIM4_CH2_IRQ:1;    /**< \brief [2:2] TIM4 shared interrupt channel 2 (r) */
        vuint32_t TIM4_CH1_IRQ:1;    /**< \brief [1:1] TIM4 shared interrupt channel 1 (r) */
        vuint32_t TIM4_CH0_IRQ:1;    /**< \brief [0:0] TIM4 shared interrupt channel 0 (r) */
    } B;
} GTM_ICM_IRQG_R3;

typedef union _GTM_ICM_IRQG_R4 {
    vuint32_t R;
    struct {
        vuint32_t MCS3_CH7_IRQ:1;    /**< \brief [31:31] MCS3 channel 7 interrupt (r) */
        vuint32_t MCS3_CH6_IRQ:1;    /**< \brief [30:30] MCS3 channel 6 interrupt (r) */
        vuint32_t MCS3_CH5_IRQ:1;    /**< \brief [29:29] MCS3 channel 5 interrupt (r) */
        vuint32_t MCS3_CH4_IRQ:1;    /**< \brief [28:28] MCS3 channel 4 interrupt (r) */
        vuint32_t MCS3_CH3_IRQ:1;    /**< \brief [27:27] MCS3 channel 3 interrupt (r) */
        vuint32_t MCS3_CH2_IRQ:1;    /**< \brief [26:26] MCS3 channel 2 interrupt (r) */
        vuint32_t MCS3_CH1_IRQ:1;    /**< \brief [25:25] MCS3 channel 1 interrupt (r) */
        vuint32_t MCS3_CH0_IRQ:1;    /**< \brief [24:24] MCS3 channel 0 interrupt (r) */
        vuint32_t MCS2_CH7_IRQ:1;    /**< \brief [23:23] MCS2 channel 7 interrupt (r) */
        vuint32_t MCS2_CH6_IRQ:1;    /**< \brief [22:22] MCS2 channel 6 interrupt (r) */
        vuint32_t MCS2_CH5_IRQ:1;    /**< \brief [21:21] MCS2 channel 5 interrupt (r) */
        vuint32_t MCS2_CH4_IRQ:1;    /**< \brief [20:20] MCS2 channel 4 interrupt (r) */
        vuint32_t MCS2_CH3_IRQ:1;    /**< \brief [19:19] MCS2 channel 3 interrupt (r) */
        vuint32_t MCS2_CH2_IRQ:1;    /**< \brief [18:18] MCS2 channel 2 interrupt (r) */
        vuint32_t MCS2_CH1_IRQ:1;    /**< \brief [17:17] MCS2 channel 1 interrupt (r) */
        vuint32_t MCS2_CH0_IRQ:1;    /**< \brief [16:16] MCS2 channel 0 interrupt (r) */
        vuint32_t MCS1_CH7_IRQ:1;    /**< \brief [15:15] MCS1 channel 7 interrupt (r) */
        vuint32_t MCS1_CH6_IRQ:1;    /**< \brief [14:14] MCS1 channel 6 interrupt (r) */
        vuint32_t MCS1_CH5_IRQ:1;    /**< \brief [13:13] MCS1 channel 5 interrupt (r) */
        vuint32_t MCS1_CH4_IRQ:1;    /**< \brief [12:12] MCS1 channel 4 interrupt (r) */
        vuint32_t MCS1_CH3_IRQ:1;    /**< \brief [11:11] MCS1 channel 3 interrupt (r) */
        vuint32_t MCS1_CH2_IRQ:1;    /**< \brief [10:10] MCS1 channel 2 interrupt (r) */
        vuint32_t MCS1_CH1_IRQ:1;    /**< \brief [9:9] MCS1 channel 1 interrupt (r) */
        vuint32_t MCS1_CH0_IRQ:1;    /**< \brief [8:8] MCS1 channel 0 interrupt (r) */
        vuint32_t MCS0_CH7_IRQ:1;    /**< \brief [7:7] MCS0 channel 7 interrupt (r) */
        vuint32_t MCS0_CH6_IRQ:1;    /**< \brief [6:6] MCS0 channel 6 interrupt (r) */
        vuint32_t MCS0_CH5_IRQ:1;    /**< \brief [5:5] MCS0 channel 5 interrupt (r) */
        vuint32_t MCS0_CH4_IRQ:1;    /**< \brief [4:4] MCS0 channel 4 interrupt (r) */
        vuint32_t MCS0_CH3_IRQ:1;    /**< \brief [3:3] MCS0 channel 3 interrupt (r) */
        vuint32_t MCS0_CH2_IRQ:1;    /**< \brief [2:2] MCS0 channel 2 interrupt (r) */
        vuint32_t MCS0_CH1_IRQ:1;    /**< \brief [1:1] MCS0 channel 1 interrupt (r) */
        vuint32_t MCS0_CH0_IRQ:1;    /**< \brief [0:0] MCS0 channel 0 interrupt (r) */
    } B;
} GTM_ICM_IRQG_R4;

typedef union _GTM_ICM_IRQG_R5 {
    vuint32_t R;
    struct {
        vuint32_t MCS7_CH6_IRQ:1;    /**< \brief [30:30] MCS7 channel 6 interrupt (r) */
        vuint32_t MCS7_CH5_IRQ:1;    /**< \brief [29:29] MCS7 channel 5 interrupt (r) */
        vuint32_t MCS7_CH4_IRQ:1;    /**< \brief [28:28] MCS7 channel 4 interrupt (r) */
        vuint32_t MCS7_CH3_IRQ:1;    /**< \brief [27:27] MCS7 channel 3 interrupt (r) */
        vuint32_t MCS7_CH2_IRQ:1;    /**< \brief [26:26] MCS7 channel 2 interrupt (r) */
        vuint32_t MCS7_CH1_IRQ:1;    /**< \brief [25:25] MCS7 channel 1 interrupt (r) */
        vuint32_t MCS7_CH0_IRQ:1;    /**< \brief [24:24] MCS7 channel 0 interrupt (r) */
        vuint32_t MCS6_CH7_IRQ:1;    /**< \brief [23:23] MCS6 channel 7 interrupt (r) */
        vuint32_t MCS6_CH6_IRQ:1;    /**< \brief [22:22] MCS6 channel 6 interrupt (r) */
        vuint32_t MCS6_CH5_IRQ:1;    /**< \brief [21:21] MCS6 channel 5 interrupt (r) */
        vuint32_t MCS6_CH4_IRQ:1;    /**< \brief [20:20] MCS6 channel 4 interrupt (r) */
        vuint32_t MCS6_CH3_IRQ:1;    /**< \brief [19:19] MCS6 channel 3 interrupt (r) */
        vuint32_t MCS6_CH2_IRQ:1;    /**< \brief [18:18] MCS6 channel 2 interrupt (r) */
        vuint32_t MCS6_CH1_IRQ:1;    /**< \brief [17:17] MCS6 channel 1 interrupt (r) */
        vuint32_t MCS6_CH0_IRQ:1;    /**< \brief [16:16] MCS6 channel 0 interrupt (r) */
        vuint32_t MCS5_CH7_IRQ:1;    /**< \brief [15:15] MCS5 channel 7 interrupt (r) */
        vuint32_t MCS5_CH6_IRQ:1;    /**< \brief [14:14] MCS5 channel 6 interrupt (r) */
        vuint32_t MCS5_CH5_IRQ:1;    /**< \brief [13:13] MCS5 channel 5 interrupt (r) */
        vuint32_t MCS5_CH4_IRQ:1;    /**< \brief [12:12] MCS5 channel 4 interrupt (r) */
        vuint32_t MCS5_CH3_IRQ:1;    /**< \brief [11:11] MCS5 channel 3 interrupt (r) */
        vuint32_t MCS5_CH2_IRQ:1;    /**< \brief [10:10] MCS5 channel 2 interrupt (r) */
        vuint32_t MCS5_CH1_IRQ:1;    /**< \brief [9:9] MCS5 channel 1 interrupt (r) */
        vuint32_t MCS5_CH0_IRQ:1;    /**< \brief [8:8] MCS5 channel 0 interrupt (r) */
        vuint32_t MCS4_CH7_IRQ:1;    /**< \brief [7:7] MCS4 channel 7 interrupt (r) */
        vuint32_t MCS4_CH6_IRQ:1;    /**< \brief [6:6] MCS4 channel 6 interrupt (r) */
        vuint32_t MCS4_CH5_IRQ:1;    /**< \brief [5:5] MCS4 channel 5 interrupt (r) */
        vuint32_t MCS4_CH4_IRQ:1;    /**< \brief [4:4] MCS4 channel 4 interrupt (r) */
        vuint32_t MCS4_CH3_IRQ:1;    /**< \brief [3:3] MCS4 channel 3 interrupt (r) */
        vuint32_t MCS4_CH2_IRQ:1;    /**< \brief [2:2] MCS4 channel 2 interrupt (r) */
        vuint32_t MCS4_CH1_IRQ:1;    /**< \brief [1:1] MCS4 channel 1 interrupt (r) */
        vuint32_t MCS4_CH0_IRQ:1;    /**< \brief [0:0] MCS4 channel 0 interrupt (r) */
    } B;
} GTM_ICM_IRQG_R5;

typedef union _GTM_ICM_IRQG_MEI {
    vuint32_t R;
    struct {
        vuint32_t reserved_26:6;    /**< \brief [31:26] \internal Reserved */
        vuint32_t DPLL_EIRQ:1;     /**< \brief [25:25] DPLL error interrupt (r) */
        vuint32_t CMP_EIRQ:1;      /**< \brief [24:24] CMP error interrupt (r) */
        vuint32_t SPE3_EIRQ:1;     /**< \brief [23:23] SPE3 error interrupt (r) */
        vuint32_t SPE2_EIRQ:1;     /**< \brief [22:22] SPE2 error interrupt (r) */
        vuint32_t SPE1_EIRQ:1;     /**< \brief [21:21] SPE1 error interrupt (r) */
        vuint32_t SPE0_EIRQ:1;     /**< \brief [20:20] SPE0 error interrupt (r) */
        vuint32_t MCS7_EIRQ:1;     /**< \brief [19:19] MCS7 error interrupt (r) */
        vuint32_t MCS6_EIRQ:1;     /**< \brief [18:18] MCS6 error interrupt (r) */
        vuint32_t MCS5_EIRQ:1;     /**< \brief [17:17] MCS5 error interrupt (r) */
        vuint32_t MCS4_EIRQ:1;     /**< \brief [16:16] MCS4 error interrupt (r) */
        vuint32_t MCS3_EIRQ:1;     /**< \brief [15:15] MCS3 error interrupt (r) */
        vuint32_t MCS2_EIRQ:1;     /**< \brief [14:14] MCS2 error interrupt (r) */
        vuint32_t MCS1_EIRQ:1;     /**< \brief [13:13] MCS1 error interrupt (r) */
        vuint32_t MCS0_EIRQ:1;     /**< \brief [12:12] MCS0 error interrupt (r) */
        vuint32_t TIM7_EIRQ:1;     /**< \brief [11:11] TIM7 error interrupt (r) */
        vuint32_t TIM6_EIRQ:1;     /**< \brief [10:10] TIM6 error interrupt (r) */
        vuint32_t TIM5_EIRQ:1;     /**< \brief [9:9] TIM5 error interrupt (r) */
        vuint32_t TIM4_EIRQ:1;     /**< \brief [8:8] TIM4 error interrupt (r) */
        vuint32_t TIM3_EIRQ:1;     /**< \brief [7:7] TIM3 error interrupt (r) */
        vuint32_t TIM2_EIRQ:1;     /**< \brief [6:6] TIM2 error interrupt (r) */
        vuint32_t TIM1_EIRQ:1;     /**< \brief [5:5] TIM1 error interrupt (r) */
        vuint32_t TIM0_EIRQ:1;     /**< \brief [4:4] TIM0 error interrupt (r) */
        vuint32_t FIFO1_EIRQ:1;    /**< \brief [3:3] FIFO1 error interrupt (r) */
        vuint32_t FIFO0_EIRQ:1;    /**< \brief [2:2] FIFO0 error interrupt (r) */
        vuint32_t BRC_EIRQ:1;      /**< \brief [1:1] BRC error interrupt (r) */
        vuint32_t GTM_EIRQ:1;      /**< \brief [0:0] AEI Error interrupt request (r) */
    } B;
} GTM_ICM_IRQG_MEI;

typedef union _GTM_ICM_IRQG_CEI0 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t FIFO2_CH7_EIRQ:1;    /**< \brief [23:23] FIFO2 channel 7 error interrupt (r) */
        vuint32_t FIFO2_CH6_EIRQ:1;    /**< \brief [22:22] FIFO2 channel 6 error interrupt (r) */
        vuint32_t FIFO2_CH5_EIRQ:1;    /**< \brief [21:21] FIFO2 channel 5 error interrupt (r) */
        vuint32_t FIFO2_CH4_EIRQ:1;    /**< \brief [20:20] FIFO2 channel 4 error interrupt (r) */
        vuint32_t FIFO2_CH3_EIRQ:1;    /**< \brief [19:19] FIFO2 channel 3 error interrupt (r) */
        vuint32_t FIFO2_CH2_EIRQ:1;    /**< \brief [18:18] FIFO2 channel 2 error interrupt (r) */
        vuint32_t FIFO2_CH1_EIRQ:1;    /**< \brief [17:17] FIFO2 channel 1 error interrupt (r) */
        vuint32_t FIFO2_CH0_EIRQ:1;    /**< \brief [16:16] FIFO2 channel 0 error interrupt (r) */
        vuint32_t FIFO1_CH7_EIRQ:1;    /**< \brief [15:15] FIFO1 channel 7 error interrupt (r) */
        vuint32_t FIFO1_CH6_EIRQ:1;    /**< \brief [14:14] FIFO1 channel 6 error interrupt (r) */
        vuint32_t FIFO1_CH5_EIRQ:1;    /**< \brief [13:13] FIFO1 channel 5 error interrupt (r) */
        vuint32_t FIFO1_CH4_EIRQ:1;    /**< \brief [12:12] FIFO1 channel 4 error interrupt (r) */
        vuint32_t FIFO1_CH3_EIRQ:1;    /**< \brief [11:11] FIFO1 channel 3 error interrupt (r) */
        vuint32_t FIFO1_CH2_EIRQ:1;    /**< \brief [10:10] FIFO1 channel 2 error interrupt (r) */
        vuint32_t FIFO1_CH1_EIRQ:1;    /**< \brief [9:9] FIFO1 channel 1 error interrupt (r) */
        vuint32_t FIFO1_CH0_EIRQ:1;    /**< \brief [8:8] FIFO1 channel 0 error interrupt (r) */
        vuint32_t FIFO0_CH7_EIRQ:1;    /**< \brief [7:7] FIFO0 channel 7 error interrupt (r) */
        vuint32_t FIFO0_CH6_EIRQ:1;    /**< \brief [6:6] FIFO0 channel 6 error interrupt (r) */
        vuint32_t FIFO0_CH5_EIRQ:1;    /**< \brief [5:5] FIFO0 channel 5 error interrupt (r) */
        vuint32_t FIFO0_CH4_EIRQ:1;    /**< \brief [4:4] FIFO0 channel 4 error interrupt (r) */
        vuint32_t FIFO0_CH3_EIRQ:1;    /**< \brief [3:3] FIFO0 channel 3 error interrupt (r) */
        vuint32_t FIFO0_CH2_EIRQ:1;    /**< \brief [2:2] FIFO0 channel 2 error interrupt (r) */
        vuint32_t FIFO0_CH1_EIRQ:1;    /**< \brief [1:1] FIFO0 channel 1 error interrupt (r) */
        vuint32_t FIFO0_CH0_EIRQ:1;    /**< \brief [0:0] FIFO0 channel 0 error interrupt (r) */
    } B;
} GTM_ICM_IRQG_CEI0;

typedef union _GTM_ICM_IRQG_CEI1 {
    vuint32_t R;
    struct {
        vuint32_t TIM3_CH7_EIRQ:1;    /**< \brief [31:31] TIM3 channel 7 error interrupt (r) */
        vuint32_t TIM3_CH6_EIRQ:1;    /**< \brief [30:30] TIM3 channel 6 error interrupt (r) */
        vuint32_t TIM3_CH5_EIRQ:1;    /**< \brief [29:29] TIM3 channel 5 error interrupt (r) */
        vuint32_t TIM3_CH4_EIRQ:1;    /**< \brief [28:28] TIM3 channel 4 error interrupt (r) */
        vuint32_t TIM3_CH3_EIRQ:1;    /**< \brief [27:27] TIM3 channel 3 error interrupt (r) */
        vuint32_t TIM3_CH2_EIRQ:1;    /**< \brief [26:26] TIM3 channel 2 error interrupt (r) */
        vuint32_t TIM3_CH1_EIRQ:1;    /**< \brief [25:25] TIM3 channel 1 error interrupt (r) */
        vuint32_t TIM3_CH0_EIRQ:1;    /**< \brief [24:24] TIM3 channel 0 error interrupt (r) */
        vuint32_t TIM2_CH7_EIRQ:1;    /**< \brief [23:23] TIM2 channel 7 error interrupt (r) */
        vuint32_t TIM2_CH6_EIRQ:1;    /**< \brief [22:22] TIM2 channel 6 error interrupt (r) */
        vuint32_t TIM2_CH5_EIRQ:1;    /**< \brief [21:21] TIM2 channel 5 error interrupt (r) */
        vuint32_t TIM2_CH4_EIRQ:1;    /**< \brief [20:20] TIM2 channel 4 error interrupt (r) */
        vuint32_t TIM2_CH3_EIRQ:1;    /**< \brief [19:19] TIM2 channel 3 error interrupt (r) */
        vuint32_t TIM2_CH2_EIRQ:1;    /**< \brief [18:18] TIM2 channel 2 error interrupt (r) */
        vuint32_t TIM2_CH1_EIRQ:1;    /**< \brief [17:17] TIM2 channel 1 error interrupt (r) */
        vuint32_t TIM2_CH0_EIRQ:1;    /**< \brief [16:16] TIM2 channel 0 error interrupt (r) */
        vuint32_t TIM1_CH7_EIRQ:1;    /**< \brief [15:15] TIM1 channel 7 error interrupt (r) */
        vuint32_t TIM1_CH6_EIRQ:1;    /**< \brief [14:14] TIM1 channel 6 error interrupt (r) */
        vuint32_t TIM1_CH5_EIRQ:1;    /**< \brief [13:13] TIM1 channel 5 error interrupt (r) */
        vuint32_t TIM1_CH4_EIRQ:1;    /**< \brief [12:12] TIM1 channel 4 error interrupt (r) */
        vuint32_t TIM1_CH3_EIRQ:1;    /**< \brief [11:11] TIM1 channel 3 error interrupt (r) */
        vuint32_t TIM1_CH2_EIRQ:1;    /**< \brief [10:10] TIM1 channel 2 error interrupt (r) */
        vuint32_t TIM1_CH1_EIRQ:1;    /**< \brief [9:9] TIM1 channel 1 error interrupt (r) */
        vuint32_t TIM1_CH0_EIRQ:1;    /**< \brief [8:8] TIM1 channel 0 error interrupt (r) */
        vuint32_t TIM0_CH7_EIRQ:1;    /**< \brief [7:7] TIM0 channel 7 error interrupt (r) */
        vuint32_t TIM0_CH6_EIRQ:1;    /**< \brief [6:6] TIM0 channel 6 error interrupt (r) */
        vuint32_t TIM0_CH5_EIRQ:1;    /**< \brief [5:5] TIM0 channel 5 error interrupt (r) */
        vuint32_t TIM0_CH4_EIRQ:1;    /**< \brief [4:4] TIM0 channel 4 error interrupt (r) */
        vuint32_t TIM0_CH3_EIRQ:1;    /**< \brief [3:3] TIM0 channel 3 error interrupt (r) */
        vuint32_t TIM0_CH2_EIRQ:1;    /**< \brief [2:2] TIM0 channel 2 error interrupt (r) */
        vuint32_t TIM0_CH1_EIRQ:1;    /**< \brief [1:1] TIM0 channel 1 error interrupt (r) */
        vuint32_t TIM0_CH0_EIRQ:1;    /**< \brief [0:0] TIM0 channel 0 error interrupt (r) */
    } B;
} GTM_ICM_IRQG_CEI1;

typedef union _GTM_ICM_IRQG_CEI2 {
    vuint32_t R;
    struct {
        vuint32_t TIM7_CH7_EIRQ:1;    /**< \brief [31:31] TIM7 channel 7 error interrupt (r) */
        vuint32_t TIM7_CH6_EIRQ:1;    /**< \brief [30:30] TIM7 channel 6 error interrupt (r) */
        vuint32_t TIM7_CH5_EIRQ:1;    /**< \brief [29:29] TIM7 channel 5 error interrupt (r) */
        vuint32_t TIM7_CH4_EIRQ:1;    /**< \brief [28:28] TIM7 channel 4 error interrupt (r) */
        vuint32_t TIM7_CH3_EIRQ:1;    /**< \brief [27:27] TIM7 channel 3 error interrupt (r) */
        vuint32_t TIM7_CH2_EIRQ:1;    /**< \brief [26:26] TIM7 channel 2 error interrupt (r) */
        vuint32_t TIM7_CH1_EIRQ:1;    /**< \brief [25:25] TIM7 channel 1 error interrupt (r) */
        vuint32_t TIM7_CH0_EIRQ:1;    /**< \brief [24:24] TIM7 channel 0 error interrupt (r) */
        vuint32_t TIM6_CH7_EIRQ:1;    /**< \brief [23:23] TIM6 channel 7 error interrupt (r) */
        vuint32_t TIM6_CH6_EIRQ:1;    /**< \brief [22:22] TIM6 channel 6 error interrupt (r) */
        vuint32_t TIM6_CH5_EIRQ:1;    /**< \brief [21:21] TIM6 channel 5 error interrupt (r) */
        vuint32_t TIM6_CH4_EIRQ:1;    /**< \brief [20:20] TIM6 channel 4 error interrupt (r) */
        vuint32_t TIM6_CH3_EIRQ:1;    /**< \brief [19:19] TIM6 channel 3 error interrupt (r) */
        vuint32_t TIM6_CH2_EIRQ:1;    /**< \brief [18:18] TIM6 channel 2 error interrupt (r) */
        vuint32_t TIM6_CH1_EIRQ:1;    /**< \brief [17:17] TIM6 channel 1 error interrupt (r) */
        vuint32_t TIM6_CH0_EIRQ:1;    /**< \brief [16:16] TIM6 channel 0 error interrupt (r) */
        vuint32_t TIM5_CH7_EIRQ:1;    /**< \brief [15:15] TIM5 channel 7 error interrupt (r) */
        vuint32_t TIM5_CH6_EIRQ:1;    /**< \brief [14:14] TIM5 channel 6 error interrupt (r) */
        vuint32_t TIM5_CH5_EIRQ:1;    /**< \brief [13:13] TIM5 channel 5 error interrupt (r) */
        vuint32_t TIM5_CH4_EIRQ:1;    /**< \brief [12:12] TIM5 channel 4 error interrupt (r) */
        vuint32_t TIM5_CH3_EIRQ:1;    /**< \brief [11:11] TIM5 channel 3 error interrupt (r) */
        vuint32_t TIM5_CH2_EIRQ:1;    /**< \brief [10:10] TIM5 channel 2 error interrupt (r) */
        vuint32_t TIM5_CH1_EIRQ:1;    /**< \brief [9:9] TIM5 channel 1 error interrupt (r) */
        vuint32_t TIM5_CH0_EIRQ:1;    /**< \brief [8:8] TIM5 channel 0 error interrupt (r) */
        vuint32_t TIM4_CH7_EIRQ:1;    /**< \brief [7:7] TIM4 channel 7 error interrupt (r) */
        vuint32_t TIM4_CH6_EIRQ:1;    /**< \brief [6:6] TIM4 channel 6 error interrupt (r) */
        vuint32_t TIM4_CH5_EIRQ:1;    /**< \brief [5:5] TIM4 channel 5 error interrupt (r) */
        vuint32_t TIM4_CH4_EIRQ:1;    /**< \brief [4:4] TIM4 channel 4 error interrupt (r) */
        vuint32_t TIM4_CH3_EIRQ:1;    /**< \brief [3:3] TIM4 channel 3 error interrupt (r) */
        vuint32_t TIM4_CH2_EIRQ:1;    /**< \brief [2:2] TIM4 channel 2 error interrupt (r) */
        vuint32_t TIM4_CH1_EIRQ:1;    /**< \brief [1:1] TIM4 channel 1 error interrupt (r) */
        vuint32_t TIM4_CH0_EIRQ:1;    /**< \brief [0:0] TIM4 channel 0 error interrupt (r) */
    } B;
} GTM_ICM_IRQG_CEI2;

typedef union _GTM_ICM_IRQG_CEI3 {
    vuint32_t R;
    struct {
        vuint32_t MCS3_CH7_EIRQ:1;    /**< \brief [31:31] MCS3 channel 7 error interrupt (r) */
        vuint32_t MCS3_CH6_EIRQ:1;    /**< \brief [30:30] MCS3 channel 6 error interrupt (r) */
        vuint32_t MCS3_CH5_EIRQ:1;    /**< \brief [29:29] MCS3 channel 5 error interrupt (r) */
        vuint32_t MCS3_CH4_EIRQ:1;    /**< \brief [28:28] MCS3 channel 4 error interrupt (r) */
        vuint32_t MCS3_CH3_EIRQ:1;    /**< \brief [27:27] MCS3 channel 3 error interrupt (r) */
        vuint32_t MCS3_CH2_EIRQ:1;    /**< \brief [26:26] MCS3 channel 2 error interrupt (r) */
        vuint32_t MCS3_CH1_EIRQ:1;    /**< \brief [25:25] MCS3 channel 1 error interrupt (r) */
        vuint32_t MCS3_CH0_EIRQ:1;    /**< \brief [24:24] MCS3 channel 0 error interrupt (r) */
        vuint32_t MCS2_CH7_EIRQ:1;    /**< \brief [23:23] MCS2 channel 7 error interrupt (r) */
        vuint32_t MCS2_CH6_EIRQ:1;    /**< \brief [22:22] MCS2 channel 6 error interrupt (r) */
        vuint32_t MCS2_CH5_EIRQ:1;    /**< \brief [21:21] MCS2 channel 5 error interrupt (r) */
        vuint32_t MCS2_CH4_EIRQ:1;    /**< \brief [20:20] MCS2 channel 4 error interrupt (r) */
        vuint32_t MCS2_CH3_EIRQ:1;    /**< \brief [19:19] MCS2 channel 3 error interrupt (r) */
        vuint32_t MCS2_CH2_EIRQ:1;    /**< \brief [18:18] MCS2 channel 2 error interrupt (r) */
        vuint32_t MCS2_CH1_EIRQ:1;    /**< \brief [17:17] MCS2 channel 1 error interrupt (r) */
        vuint32_t MCS2_CH0_EIRQ:1;    /**< \brief [16:16] MCS2 channel 0 error interrupt (r) */
        vuint32_t MCS1_CH7_EIRQ:1;    /**< \brief [15:15] MCS1 channel 7 error interrupt (r) */
        vuint32_t MCS1_CH6_EIRQ:1;    /**< \brief [14:14] MCS1 channel 6 error interrupt (r) */
        vuint32_t MCS1_CH5_EIRQ:1;    /**< \brief [13:13] MCS1 channel 5 error interrupt (r) */
        vuint32_t MCS1_CH4_EIRQ:1;    /**< \brief [12:12] MCS1 channel 4 error interrupt (r) */
        vuint32_t MCS1_CH3_EIRQ:1;    /**< \brief [11:11] MCS1 channel 3 error interrupt (r) */
        vuint32_t MCS1_CH2_EIRQ:1;    /**< \brief [10:10] MCS1 channel 2 error interrupt (r) */
        vuint32_t MCS1_CH1_EIRQ:1;    /**< \brief [9:9] MCS1 channel 1 error interrupt (r) */
        vuint32_t MCS1_CH0_EIRQ:1;    /**< \brief [8:8] MCS1 channel 0 error interrupt (r) */
        vuint32_t MCS0_CH7_EIRQ:1;    /**< \brief [7:7] MCS0 channel 7 error interrupt (r) */
        vuint32_t MCS0_CH6_EIRQ:1;    /**< \brief [6:6] MCS0 channel 6 error interrupt (r) */
        vuint32_t MCS0_CH5_EIRQ:1;    /**< \brief [5:5] MCS0 channel 5 error interrupt (r) */
        vuint32_t MCS0_CH4_EIRQ:1;    /**< \brief [4:4] MCS0 channel 4 error interrupt (r) */
        vuint32_t MCS0_CH3_EIRQ:1;    /**< \brief [3:3] MCS0 channel 3 error interrupt (r) */
        vuint32_t MCS0_CH2_EIRQ:1;    /**< \brief [2:2] MCS0 channel 2 error interrupt (r) */
        vuint32_t MCS0_CH1_EIRQ:1;    /**< \brief [1:1] MCS0 channel 1 error interrupt (r) */
        vuint32_t MCS0_CH0_EIRQ:1;    /**< \brief [0:0] MCS0 channel 0 error interrupt (r) */
    } B;
} GTM_ICM_IRQG_CEI3;

typedef union _GTM_ICM_IRQG_CEI4 {
    vuint32_t R;
    struct {
        vuint32_t MCS7_CH7_EIRQ:1;    /**< \brief [31:31] MCS7 channel 7 error interrupt (r) */
        vuint32_t MCS7_CH6_EIRQ:1;    /**< \brief [30:30] MCS7 channel 6 error interrupt (r) */
        vuint32_t MCS7_CH5_EIRQ:1;    /**< \brief [29:29] MCS7 channel 5 error interrupt (r) */
        vuint32_t MCS7_CH4_EIRQ:1;    /**< \brief [28:28] MCS7 channel 4 error interrupt (r) */
        vuint32_t MCS7_CH3_EIRQ:1;    /**< \brief [27:27] MCS7 channel 3 error interrupt (r) */
        vuint32_t MCS7_CH2_EIRQ:1;    /**< \brief [26:26] MCS7 channel 2 error interrupt (r) */
        vuint32_t MCS7_CH1_EIRQ:1;    /**< \brief [25:25] MCS7 channel 1 error interrupt (r) */
        vuint32_t MCS7_CH0_EIRQ:1;    /**< \brief [24:24] MCS7 channel 0 error interrupt (r) */
        vuint32_t MCS6_CH7_EIRQ:1;    /**< \brief [23:23] MCS6 channel 7 error interrupt (r) */
        vuint32_t MCS6_CH6_EIRQ:1;    /**< \brief [22:22] MCS6 channel 6 error interrupt (r) */
        vuint32_t MCS6_CH5_EIRQ:1;    /**< \brief [21:21] MCS6 channel 5 error interrupt (r) */
        vuint32_t MCS6_CH4_EIRQ:1;    /**< \brief [20:20] MCS6 channel 4 error interrupt (r) */
        vuint32_t MCS6_CH3_EIRQ:1;    /**< \brief [19:19] MCS6 channel 3 error interrupt (r) */
        vuint32_t MCS6_CH2_EIRQ:1;    /**< \brief [18:18] MCS6 channel 2 error interrupt (r) */
        vuint32_t MCS6_CH1_EIRQ:1;    /**< \brief [17:17] MCS6 channel 1 error interrupt (r) */
        vuint32_t MCS6_CH0_EIRQ:1;    /**< \brief [16:16] MCS6 channel 0 error interrupt (r) */
        vuint32_t MCS5_CH7_EIRQ:1;    /**< \brief [15:15] MCS5 channel 7 error interrupt (r) */
        vuint32_t MCS5_CH6_EIRQ:1;    /**< \brief [14:14] MCS5 channel 6 error interrupt (r) */
        vuint32_t MCS5_CH5_EIRQ:1;    /**< \brief [13:13] MCS5 channel 5 error interrupt (r) */
        vuint32_t MCS5_CH4_EIRQ:1;    /**< \brief [12:12] MCS5 channel 4 error interrupt (r) */
        vuint32_t MCS5_CH3_EIRQ:1;    /**< \brief [11:11] MCS5 channel 3 error interrupt (r) */
        vuint32_t MCS5_CH2_EIRQ:1;    /**< \brief [10:10] MCS5 channel 2 error interrupt (r) */
        vuint32_t MCS5_CH1_EIRQ:1;    /**< \brief [9:9] MCS5 channel 1 error interrupt (r) */
        vuint32_t MCS5_CH0_EIRQ:1;    /**< \brief [8:8] MCS5 channel 0 error interrupt (r) */
        vuint32_t MCS4_CH7_EIRQ:1;    /**< \brief [7:7] MCS4 channel 7 error interrupt (r) */
        vuint32_t MCS4_CH6_EIRQ:1;    /**< \brief [6:6] MCS4 channel 6 error interrupt (r) */
        vuint32_t MCS4_CH5_EIRQ:1;    /**< \brief [5:5] MCS4 channel 5 error interrupt (r) */
        vuint32_t MCS4_CH4_EIRQ:1;    /**< \brief [4:4] MCS4 channel 4 error interrupt (r) */
        vuint32_t MCS4_CH3_EIRQ:1;    /**< \brief [3:3] MCS4 channel 3 error interrupt (r) */
        vuint32_t MCS4_CH2_EIRQ:1;    /**< \brief [2:2] MCS4 channel 2 error interrupt (r) */
        vuint32_t MCS4_CH1_EIRQ:1;    /**< \brief [1:1] MCS4 channel 1 error interrupt (r) */
        vuint32_t MCS4_CH0_EIRQ:1;    /**< \brief [0:0] MCS4 channel 0 error interrupt (r) */
    } B;
} GTM_ICM_IRQG_CEI4;

typedef union _GTM_ICM_IRQG_CEI_MCS {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t MCS_CH7_EIRQ:1;    /**< \brief [7:7] MCS channel 7 error interrupt (r) */
        vuint32_t MCS_CH6_EIRQ:1;    /**< \brief [6:6] MCS channel 6 error interrupt (r) */
        vuint32_t MCS_CH5_EIRQ:1;    /**< \brief [5:5] MCS channel 5 error interrupt (r) */
        vuint32_t MCS_CH4_EIRQ:1;    /**< \brief [4:4] MCS channel 4 error interrupt (r) */
        vuint32_t MCS_CH3_EIRQ:1;    /**< \brief [3:3] MCS channel 3 error interrupt (r) */
        vuint32_t MCS_CH2_EIRQ:1;    /**< \brief [2:2] MCS channel 2 error interrupt (r) */
        vuint32_t MCS_CH1_EIRQ:1;    /**< \brief [1:1] MCS channel 1 error interrupt (r) */
        vuint32_t MCS_CH0_EIRQ:1;    /**< \brief [0:0] MCS channel 0 error interrupt (r) */
    } B;
} GTM_ICM_IRQG_CEI_MCS;

typedef union _GTM_ICM_IRQG_CEI_PSM {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSM_M2_CH7_EIRQ:1;    /**< \brief [23:23] PSM2 channel 7 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH6_EIRQ:1;    /**< \brief [22:22] PSM2 channel 6 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH5_EIRQ:1;    /**< \brief [21:21] PSM2 channel 5 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH4_EIRQ:1;    /**< \brief [20:20] PSM2 channel 4 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH3_EIRQ:1;    /**< \brief [19:19] PSM2 channel 3 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH2_EIRQ:1;    /**< \brief [18:18] PSM2 channel 2 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH1_EIRQ:1;    /**< \brief [17:17] PSM2 channel 1 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH0_EIRQ:1;    /**< \brief [16:16] PSM2 channel 0 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH7_EIRQ:1;    /**< \brief [15:15] PSM1 channel 7 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH6_EIRQ:1;    /**< \brief [14:14] PSM1 channel 6 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH5_EIRQ:1;    /**< \brief [13:13] PSM1 channel 5 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH4_EIRQ:1;    /**< \brief [12:12] PSM1 channel 4 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH3_EIRQ:1;    /**< \brief [11:11] PSM1 channel 3 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH2_EIRQ:1;    /**< \brief [10:10] PSM1 channel 2 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH1_EIRQ:1;    /**< \brief [9:9] PSM1 channel 1 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH0_EIRQ:1;    /**< \brief [8:8] PSM1 channel 0 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH7_EIRQ:1;    /**< \brief [7:7] PSM0 channel 7 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH6_EIRQ:1;    /**< \brief [6:6] PSM0 channel 6 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH5_EIRQ:1;    /**< \brief [5:5] PSM0 channel 5 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH4_EIRQ:1;    /**< \brief [4:4] PSM0 channel 4 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH3_EIRQ:1;    /**< \brief [3:3] PSM0 channel 3 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH2_EIRQ:1;    /**< \brief [2:2] PSM0 channel 2 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH1_EIRQ:1;    /**< \brief [1:1] PSM0 channel 1 error interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH0_EIRQ:1;    /**< \brief [0:0] PSM0 channel 0 error interrupt (m=4*0+0) (r) */
    } B;
} GTM_ICM_IRQG_CEI_PSM;

typedef union _GTM_ICM_IRQG_CEI_SPE {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t SPE7_EIRQ:1;     /**< \brief [7:7] SPE channel 5 error interrupt (r) */
        vuint32_t SPE6_EIRQ:1;     /**< \brief [6:6] SPE channel 5 error interrupt (r) */
        vuint32_t SPE5_EIRQ:1;     /**< \brief [5:5] SPE channel 5 error interrupt (r) */
        vuint32_t SPE4_EIRQ:1;     /**< \brief [4:4] SPE channel 4 error interrupt (r) */
        vuint32_t SPE3_EIRQ:1;     /**< \brief [3:3] SPE channel 3 error interrupt (r) */
        vuint32_t SPE2_EIRQ:1;     /**< \brief [2:2] SPE channel 2 error interrupt (r) */
        vuint32_t SPE1_EIRQ:1;     /**< \brief [1:1] SPE channel 1 error interrupt (r) */
        vuint32_t SPE0_EIRQ:1;     /**< \brief [0:0] SPE channel 0 error interrupt (r) */
    } B;
} GTM_ICM_IRQG_CEI_SPE;

typedef union _GTM_ICM_IRQG_MEI_CLS {
    vuint32_t R;
    struct {
        vuint32_t reserved_28:4;    /**< \brief [31:28] \internal Reserved */
        vuint32_t reserved_27:1;    /**< \brief [27:27] \internal Reserved */
        vuint32_t SPE_M3_EIRQ:1;    /**< \brief [26:26] Error interrupt SPEm_EIRQ (m={4*0+3}) (r) */
        vuint32_t MCS_M3_EIRQ:1;    /**< \brief [25:25] Error interrupt MCSm_EIRQ (m={4*0+3}) (r) */
        vuint32_t TIM_M3_EIRQ:1;    /**< \brief [24:24] Error interrupt TIMm_EIRQ (m={4*0+3}) (r) */
        vuint32_t reserved_20:4;    /**< \brief [23:20] \internal Reserved */
        vuint32_t FIFO_M2_EIRQ:1;    /**< \brief [19:19] Error interrupt FIFOm_EIRQ (m={4*0+2}) (r) */
        vuint32_t SPE_M2_EIRQ:1;    /**< \brief [18:18] Error interrupt SPEm_EIRQ (m={4*0+2}) (r) */
        vuint32_t MCS_M2_EIRQ:1;    /**< \brief [17:17] Error interrupt MCSm_EIRQ (m={4*0+2}) (r) */
        vuint32_t TIM_M2_EIRQ:1;    /**< \brief [16:16] Error interrupt TIMm_EIRQ (m={4*0+2}) (r) */
        vuint32_t reserved_12:4;    /**< \brief [15:12] \internal Reserved */
        vuint32_t FIFO_M1_EIRQ:1;    /**< \brief [11:11] Error interrupt FIFOm_EIRQ (m={4*0+1}) (r) */
        vuint32_t SPE_M1_EIRQ:1;    /**< \brief [10:10] Error interrupt SPEm_EIRQ (m={4*0+1}) (r) */
        vuint32_t MCS_M1_EIRQ:1;    /**< \brief [9:9] Error interrupt MCSm_EIRQ (m={4*0+1}) (r) */
        vuint32_t TIM_M1_EIRQ:1;    /**< \brief [8:8] Error interrupt TIMm_EIRQ (m={4*0+1}) (r) */
        vuint32_t reserved_4:4;    /**< \brief [7:4] \internal Reserved */
        vuint32_t FIFO_M0_EIRQ:1;    /**< \brief [3:3] Error interrupt FIFOm_EIRQ (m={4*0+0}) (r) */
        vuint32_t SPE_M0_EIRQ:1;    /**< \brief [2:2] Error interrupt SPEm_EIRQ (m={4*0+0}) (r) */
        vuint32_t MCS_M0_EIRQ:1;    /**< \brief [1:1] Error interrupt MCSm_EIRQ (m={4*0+0}) (r) */
        vuint32_t TIM_M0_EIRQ:1;    /**< \brief [0:0] Error interrupt TIMm_EIRQ (m={4*0+0}) (r) */
    } B;
} GTM_ICM_IRQG_MEI_CLS;

typedef union _GTM_ICM_IRQG_CI_MCS {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t MCS_CH7_IRQ:1;    /**< \brief [7:7] MCS channel 7 interrupt (r) */
        vuint32_t MCS_CH6_IRQ:1;    /**< \brief [6:6] MCS channel 6 interrupt (r) */
        vuint32_t MCS_CH5_IRQ:1;    /**< \brief [5:5] MCS channel 5 interrupt (r) */
        vuint32_t MCS_CH4_IRQ:1;    /**< \brief [4:4] MCS channel 4 interrupt (r) */
        vuint32_t MCS_CH3_IRQ:1;    /**< \brief [3:3] MCS channel 3 interrupt (r) */
        vuint32_t MCS_CH2_IRQ:1;    /**< \brief [2:2] MCS channel 2 interrupt (r) */
        vuint32_t MCS_CH1_IRQ:1;    /**< \brief [1:1] MCS channel 1 interrupt (r) */
        vuint32_t MCS_CH0_IRQ:1;    /**< \brief [0:0] MCS channel 0 interrupt (r) */
    } B;
} GTM_ICM_IRQG_CI_MCS;

typedef union _GTM_ICM_IRQG_CI_PSM {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSM_M2_CH7_IRQ:1;    /**< \brief [23:23] PSM2 channel 7 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH6_IRQ:1;    /**< \brief [22:22] PSM2 channel 6 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH5_IRQ:1;    /**< \brief [21:21] PSM2 channel 5 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH4_IRQ:1;    /**< \brief [20:20] PSM2 channel 4 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH3_IRQ:1;    /**< \brief [19:19] PSM2 channel 3 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH2_IRQ:1;    /**< \brief [18:18] PSM2 channel 2 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH1_IRQ:1;    /**< \brief [17:17] PSM2 channel 1 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M2_CH0_IRQ:1;    /**< \brief [16:16] PSM2 channel 0 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH7_IRQ:1;    /**< \brief [15:15] PSM1 channel 7 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH6_IRQ:1;    /**< \brief [14:14] PSM1 channel 6 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH5_IRQ:1;    /**< \brief [13:13] PSM1 channel 5 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH4_IRQ:1;    /**< \brief [12:12] PSM1 channel 4 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH3_IRQ:1;    /**< \brief [11:11] PSM1 channel 3 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH2_IRQ:1;    /**< \brief [10:10] PSM1 channel 2 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH1_IRQ:1;    /**< \brief [9:9] PSM1 channel 1 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M1_CH0_IRQ:1;    /**< \brief [8:8] PSM1 channel 0 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH7_IRQ:1;    /**< \brief [7:7] PSM0 channel 7 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH6_IRQ:1;    /**< \brief [6:6] PSM0 channel 6 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH5_IRQ:1;    /**< \brief [5:5] PSM0 channel 5 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH4_IRQ:1;    /**< \brief [4:4] PSM0 channel 4 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH3_IRQ:1;    /**< \brief [3:3] PSM0 channel 3 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH2_IRQ:1;    /**< \brief [2:2] PSM0 channel 2 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH1_IRQ:1;    /**< \brief [1:1] PSM0 channel 1 shared interrupt (m=4*0+0) (r) */
        vuint32_t PSM_M0_CH0_IRQ:1;    /**< \brief [0:0] PSM0 channel 0 shared interrupt (m=4*0+0) (r) */
    } B;
} GTM_ICM_IRQG_CI_PSM;

typedef union _GTM_ICM_IRQG_CI_SPE {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t SPE0_IRQ:1;      /**< \brief [0:0] SPE channel 0 interrupt (r) */
        vuint32_t SPE1_IRQ:1;      /**< \brief [1:1] SPE channel 1 interrupt (r) */
        vuint32_t SPE2_IRQ:1;      /**< \brief [2:2] SPE channel 2 interrupt (r) */
        vuint32_t SPE3_IRQ:1;      /**< \brief [3:3] SPE channel 3 interrupt (r) */
        vuint32_t SPE4_IRQ:1;      /**< \brief [4:4] SPE channel 4 interrupt (r) */
        vuint32_t SPE5_IRQ:1;      /**< \brief [5:5] SPE channel 5 interrupt (r) */
        vuint32_t SPE6_IRQ:1;      /**< \brief [6:6] SPE channel 4 interrupt (r) */
        vuint32_t SPE7_IRQ:1;      /**< \brief [7:7] SPE channel 5 interrupt (r) */
    } B;
} GTM_ICM_IRQG_CI_SPE;

typedef union _GTM_ICM_IRQG_CI_ATOM {
    vuint32_t R;
    struct {
        vuint32_t ATOM_M3_CH7_IRQ:1;    /**< \brief [31:31] ATOMm channel 7 interrupt (m={4*0+3) (r) */
        vuint32_t ATOM_M3_CH6_IRQ:1;    /**< \brief [30:30] ATOMm channel 6 interrupt (m={4*0+3) (r) */
        vuint32_t ATOM_M3_CH5_IRQ:1;    /**< \brief [29:29] ATOMm channel 5 interrupt (m={4*0+3) (r) */
        vuint32_t ATOM_M3_CH4_IRQ:1;    /**< \brief [28:28] ATOMm channel 4 interrupt (m={4*0+3) (r) */
        vuint32_t ATOM_M3_CH3_IRQ:1;    /**< \brief [27:27] ATOMm channel 3 interrupt (m={4*0+3) (r) */
        vuint32_t ATOM_M3_CH2_IRQ:1;    /**< \brief [26:26] ATOMm channel 2 interrupt (m={4*0+3) (r) */
        vuint32_t ATOM_M3_CH1_IRQ:1;    /**< \brief [25:25] ATOMm channel 1 interrupt (m={4*0+3) (r) */
        vuint32_t ATOM_M3_CH0_IRQ:1;    /**< \brief [24:24] ATOMm channel 0 interrupt (m={4*0+3) (r) */
        vuint32_t ATOM_M2_CH7_IRQ:1;    /**< \brief [23:23] ATOMm channel 7 interrupt (m={4*0+2}) (r) */
        vuint32_t ATOM_M2_CH6_IRQ:1;    /**< \brief [22:22] ATOMm channel 6 interrupt (m={4*0+2}) (r) */
        vuint32_t ATOM_M2_CH5_IRQ:1;    /**< \brief [21:21] ATOMm channel 5 interrupt (m={4*0+2}) (r) */
        vuint32_t ATOM_M2_CH4_IRQ:1;    /**< \brief [20:20] ATOMm channel 4 interrupt (m={4*0+2}) (r) */
        vuint32_t ATOM_M2_CH3_IRQ:1;    /**< \brief [19:19] ATOMm channel 3 interrupt (m={4*0+2}) (r) */
        vuint32_t ATOM_M2_CH2_IRQ:1;    /**< \brief [18:18] ATOMm channel 2 interrupt (m={4*0+2}) (r) */
        vuint32_t ATOM_M2_CH1_IRQ:1;    /**< \brief [17:17] ATOMm channel 1 interrupt (m={4*0+2}) (r) */
        vuint32_t ATOM_M2_CH0_IRQ:1;    /**< \brief [16:16] ATOMm channel 0 interrupt (m={4*0+2}) (r) */
        vuint32_t ATOM_M1_CH7_IRQ:1;    /**< \brief [15:15] ATOMm channel 7 interrupt (m={4*0+1}) (r) */
        vuint32_t ATOM_M1_CH6_IRQ:1;    /**< \brief [14:14] ATOMm channel 6 interrupt (m={4*0+1}) (r) */
        vuint32_t ATOM_M1_CH5_IRQ:1;    /**< \brief [13:13] ATOMm channel 5 interrupt (m={4*0+1}) (r) */
        vuint32_t ATOM_M1_CH4_IRQ:1;    /**< \brief [12:12] ATOMm channel 4 interrupt (m={4*0+1}) (r) */
        vuint32_t ATOM_M1_CH3_IRQ:1;    /**< \brief [11:11] ATOMm channel 3 interrupt (m={4*0+1}) (r) */
        vuint32_t ATOM_M1_CH2_IRQ:1;    /**< \brief [10:10] ATOMm channel 2 interrupt (m={4*0+1}) (r) */
        vuint32_t ATOM_M1_CH1_IRQ:1;    /**< \brief [9:9] ATOMm channel 1 interrupt (m={4*0+1}) (r) */
        vuint32_t ATOM_M1_CH0_IRQ:1;    /**< \brief [8:8] ATOMm channel 0 interrupt (m={4*0+1}) (r) */
        vuint32_t ATOM_M0_CH7_IRQ:1;    /**< \brief [7:7] ATOMm channel 7 interrupt (m={4*0+0}) (r) */
        vuint32_t ATOM_M0_CH6_IRQ:1;    /**< \brief [6:6] ATOMm channel 6 interrupt (m={4*0+0}) (r) */
        vuint32_t ATOM_M0_CH5_IRQ:1;    /**< \brief [5:5] ATOMm channel 5 interrupt (m={4*0+0}) (r) */
        vuint32_t ATOM_M0_CH4_IRQ:1;    /**< \brief [4:4] ATOMm channel 4 interrupt (m={4*0+0}) (r) */
        vuint32_t ATOM_M0_CH3_IRQ:1;    /**< \brief [3:3] ATOMm channel 3 interrupt (m={4*0+0}) (r) */
        vuint32_t ATOM_M0_CH2_IRQ:1;    /**< \brief [2:2] ATOMm channel 2 interrupt (m={4*0+0}) (r) */
        vuint32_t ATOM_M0_CH1_IRQ:1;    /**< \brief [1:1] ATOMm channel 1 interrupt (m={4*0+0}) (r) */
        vuint32_t ATOM_M0_CH0_IRQ:1;    /**< \brief [0:0] ATOMm channel 0 interrupt (m={4*0+0}) (r) */
    } B;
} GTM_ICM_IRQG_CI_ATOM;

typedef union _GTM_ICM_IRQG_CI_TOM {
    vuint32_t R;
    struct {
        vuint32_t TOM_M1_CH15_IRQ:1;    /**< \brief [31:31] TOMm channel 15 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH14_IRQ:1;    /**< \brief [30:30] TOMm channel 14 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH13_IRQ:1;    /**< \brief [29:29] TOMm channel 13 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH12_IRQ:1;    /**< \brief [28:28] TOMm channel 12 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH11_IRQ:1;    /**< \brief [27:27] TOMm channel 11 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH10_IRQ:1;    /**< \brief [26:26] TOMm channel 10 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH9_IRQ:1;    /**< \brief [25:25] TOMm channel 9 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH8_IRQ:1;    /**< \brief [24:24] TOMm channel 8 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH7_IRQ:1;    /**< \brief [23:23] TOMm channel 7 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH6_IRQ:1;    /**< \brief [22:22] TOMm channel 6 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH5_IRQ:1;    /**< \brief [21:21] TOMm channel 5 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH4_IRQ:1;    /**< \brief [20:20] TOMm channel 4 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH3_IRQ:1;    /**< \brief [19:19] TOMm channel 3 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH2_IRQ:1;    /**< \brief [18:18] TOMm channel 2 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH1_IRQ:1;    /**< \brief [17:17] TOMm channel 1 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M1_CH0_IRQ:1;    /**< \brief [16:16] TOMm channel 0 interrupt (m={2*0+1}) (r) */
        vuint32_t TOM_M0_CH15_IRQ:1;    /**< \brief [15:15] TOMm channel 15 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH14_IRQ:1;    /**< \brief [14:14] TOMm channel 14 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH13_IRQ:1;    /**< \brief [13:13] TOMm channel 13 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH12_IRQ:1;    /**< \brief [12:12] TOMm channel 12 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH11_IRQ:1;    /**< \brief [11:11] TOMm channel 11 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH10_IRQ:1;    /**< \brief [10:10] TOMm channel 10 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH9_IRQ:1;    /**< \brief [9:9] TOMm channel 9 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH8_IRQ:1;    /**< \brief [8:8] TOMm channel 8 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH7_IRQ:1;    /**< \brief [7:7] TOMm channel 7 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH6_IRQ:1;    /**< \brief [6:6] TOMm channel 6 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH5_IRQ:1;    /**< \brief [5:5] TOMm channel 5 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH4_IRQ:1;    /**< \brief [4:4] TOMm channel 4 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH3_IRQ:1;    /**< \brief [3:3] TOMm channel 3 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH2_IRQ:1;    /**< \brief [2:2] TOMm channel 2 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH1_IRQ:1;    /**< \brief [1:1] TOMm channel 1 interrupt (m={2*0+0}) (r) */
        vuint32_t TOM_M0_CH0_IRQ:1;    /**< \brief [0:0] TOMm channel 0 interrupt (m={2*0+0}) (r) */
    } B;
} GTM_ICM_IRQG_CI_TOM;

typedef volatile struct _GTM_ICM_IRQG {
       GTM_ICM_IRQG_R0                 R0;                     /**< \brief 0, ICM Interrupt Group Register Covering Infrastructural and Safety Components ARU, BRC, AEI, PSM0, PSM1, MAP, CMP, SPE*/
       GTM_ICM_IRQG_R1                 R1;                     /**< \brief 4, ICM Interrupt Group Register Covering DPLL*/
       GTM_ICM_IRQG_R2                 R2;                     /**< \brief 8, ICM Interrupt Group Register Covering TIM0, TIM1, TIM2, TIM3*/
       GTM_ICM_IRQG_R3                 R3;                     /**< \brief C, ICM Interrupt Group Register Covering TIM4, TIM5, TIM6, TIM7*/
       GTM_ICM_IRQG_R4                 R4;                     /**< \brief 10, ICM Interrupt Group Register Covering MCS0 to MCS3 Sub-Modules*/
       GTM_ICM_IRQG_R5                 R5;                     /**< \brief 14, ICM Interrupt Group Register Covering MCS4 to MCS6 Sub-Modules*/
       vuint8_t                   reserved_18[24];        /**< \brief 18, \internal Reserved */
       GTM_ICM_IRQG_MEI                MEI;                    /**< \brief 30, ICM Interrupt Group Register for Module Error Interrupt Information*/
       GTM_ICM_IRQG_CEI0               CEI0;                   /**< \brief 34, ICM Interrupt Group Register 0 for Channel Error Interrupt Information*/
       GTM_ICM_IRQG_CEI1               CEI1;                   /**< \brief 38, ICM Interrupt Group Register 1 for Channel Error Interrupt Information*/
       GTM_ICM_IRQG_CEI2               CEI2;                   /**< \brief 3C, ICM Interrupt Group Register 2 for Channel Error Interrupt Information*/
       GTM_ICM_IRQG_CEI3               CEI3;                   /**< \brief 40, ICM Interrupt Group Register 3 for Channel Error Interrupt Information*/
       GTM_ICM_IRQG_CEI4               CEI4;                   /**< \brief 44, ICM Interrupt Group Register 4 for Channel Error Interrupt Information*/
       vuint8_t                   reserved_48[28];        /**< \brief 48, \internal Reserved */
       GTM_ICM_IRQG_CEI_MCS            CEI_MCS[10];            /**< \brief 64, ICM Interrupt Group MCS ${i} for Channel Error Interrupt information*/
       vuint8_t                   reserved_8C[24];        /**< \brief 8C, \internal Reserved */
       GTM_ICM_IRQG_CEI_PSM            CEI_PSM[1];             /**< \brief A4, ICM Interrupt Group PSM 0 for Channel Error Interrupt information of FIFO0, FIFO1, FIFO2*/
       vuint8_t                   reserved_A8[12];        /**< \brief A8, \internal Reserved */
       GTM_ICM_IRQG_CEI_SPE            CEI_SPE;                /**< \brief B4, ICM Interrupt Group SPE for Module Error Interrupt Information*/
       vuint8_t                   reserved_B8[88];        /**< \brief B8, \internal Reserved */
       GTM_ICM_IRQG_MEI_CLS            MEI_CLS[3];             /**< \brief 110, ICM Interrupt Group k for Module Error Interrupt Information for each TIMm, MCSm, SPEm, FIFOm*/
       vuint8_t                   reserved_11C[4];        /**< \brief 11C, \internal Reserved */
       GTM_ICM_IRQG_CI_MCS             CI_MCS[10];             /**< \brief 120, ICM Interrupt Group MCS ${i} for Channel Interrupt Information*/
       vuint8_t                   reserved_148[24];       /**< \brief 148, \internal Reserved */
       GTM_ICM_IRQG_CI_PSM             CI_PSM[1];              /**< \brief 160, ICM Interrupt Group PSM 0 for Channel Interrupt Information of FIFO0, FIFO1, FIFO2*/
       vuint8_t                   reserved_164[12];       /**< \brief 164, \internal Reserved */
       GTM_ICM_IRQG_CI_SPE             CI_SPE;                 /**< \brief 170, ICM Interrupt Group SPE for Module Interrupt Information*/
       vuint8_t                   reserved_174[28];       /**< \brief 174, \internal Reserved */
       GTM_ICM_IRQG_CI_ATOM            CI_ATOM[3];             /**< \brief 190, ICM Interrupt Group ATOM ${k} for Channel Interrupt Information of ATOMm*/
       vuint8_t                   reserved_19C[4];        /**< \brief 19C, \internal Reserved */
       GTM_ICM_IRQG_CI_TOM             CI_TOM[6];              /**< \brief 1A0, ICM Interrupt Group TOM ${k} for Channel Interrupt Information of TOMm*/
} GTM_ICM_IRQG;

typedef volatile struct _GTM_ICM {
       GTM_ICM_IRQG                    IRQG;                   /**< \brief 0, */
} GTM_ICM;

/* ============================================================================
   =============================== Module: GTM_MAP_CTRL ================================
   ============================================================================ */

typedef union _GTM_MAP_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_31:1;    /**< \brief [31:31] \internal Reserved */
        vuint32_t TSPP1_I2V:1;     /**< \brief [30:30] Disable of TSPP1 TIM0_CHz(48) input line (rw) */
        vuint32_t TSPP1_I1V:1;     /**< \brief [29:29] Disable of TSPP1 TIM0_CHy(48) input line (rw) */
        vuint32_t TSPP1_I0V:1;     /**< \brief [28:28] Disable of TSPP1 TIM0_CHx(48) input line (rw) */
        vuint32_t reserved_26:2;    /**< \brief [27:26] \internal Reserved */
        vuint32_t TSPP1_DLD:1;     /**< \brief [25:25] DIR level definition bit (rw) */
        vuint32_t TSPP1_EN:1;      /**< \brief [24:24] Enable of TSPP1 subunit (rw) */
        vuint32_t reserved_23:1;    /**< \brief [23:23] \internal Reserved */
        vuint32_t TSPP0_I2V:1;     /**< \brief [22:22] Disable of TSPP0 TIM0_CHz(48) input line (rw) */
        vuint32_t TSPP0_I1V:1;     /**< \brief [21:21] Disable of TSPP0 TIM0_CHy(48) input line (rw) */
        vuint32_t TSPP0_I0V:1;     /**< \brief [20:20] Disable of TSPP0 TIM0_CHx(48) input line (rw) */
        vuint32_t reserved_18:2;    /**< \brief [19:18] \internal Reserved */
        vuint32_t TSPP0_DLD:1;     /**< \brief [17:17] DIR level definition bit (rw) */
        vuint32_t TSPP0_EN:1;      /**< \brief [16:16] Enable of TSPP0 subunit (rw) */
        vuint32_t reserved_5:11;    /**< \brief [15:5] \internal Reserved */
        vuint32_t LSEL:1;          /**< \brief [4:4] TIM0_IN6 input level selection (rw) */
        vuint32_t SSL:3;           /**< \brief [3:1] STATE signal output select (rw) */
        vuint32_t TSEL:1;          /**< \brief [0:0] TRIGGER signal output select (rw) */
    } B;
} GTM_MAP_CTRL;

/* ============================================================================
   =============================== Module: GTM_MON ================================
   ============================================================================ */
typedef union _GTM_MON_STATUS {
    vuint32_t R;
    struct {
        vuint32_t reserved_30:2;    /**< \brief [31:30] \internal Reserved */
        vuint32_t MCS9_ERR:1;      /**< \brief [29:29] Error detected at MCS9 (r) */
        vuint32_t MCS8_ERR:1;      /**< \brief [28:28] Error detected at MCS8 (r) */
        vuint32_t MCS7_ERR:1;      /**< \brief [27:27] Error detected at MCS7 (r) */
        vuint32_t MCS6_ERR:1;      /**< \brief [26:26] Error detected at MCS6 (r) */
        vuint32_t MCS5_ERR:1;      /**< \brief [25:25] Error detected at MCS5 (r) */
        vuint32_t MCS4_ERR:1;      /**< \brief [24:24] Error detected at MCS4 (r) */
        vuint32_t MCS3_ERR:1;      /**< \brief [23:23] Error detected at MCS3 (r) */
        vuint32_t MCS2_ERR:1;      /**< \brief [22:22] Error detected at MCS2 (r) */
        vuint32_t MCS1_ERR:1;      /**< \brief [21:21] Error detected at MCS1 (r) */
        vuint32_t MCS0_ERR:1;      /**< \brief [20:20] Error detected at MCS0 (r) */
        vuint32_t reserved_17:3;    /**< \brief [19:17] \internal Reserved */
        vuint32_t CMP_ERR:1;       /**< \brief [16:16] Error detected at CMP (r) */
        vuint32_t reserved_15:1;    /**< \brief [15:15] \internal Reserved */
        vuint32_t ACT_CMU8:1;      /**< \brief [14:14] CMU_CLK8 activity (rw) */
        vuint32_t reserved_13:1;    /**< \brief [13:13] \internal Reserved */
        vuint32_t ACT_CMUFX4:1;    /**< \brief [12:12] CMU_CLKFX4 activity (rw) */
        vuint32_t ACT_CMUFX3:1;    /**< \brief [11:11] CMU_CLKFX3 activity (rw) */
        vuint32_t ACT_CMUFX2:1;    /**< \brief [10:10] CMU_CLKFX2 activity (rw) */
        vuint32_t ACT_CMUFX1:1;    /**< \brief [9:9] CMU_CLKFX1 activity (rw) */
        vuint32_t ACT_CMUFX0:1;    /**< \brief [8:8] CMU_CLKFX0 activity (rw) */
        vuint32_t ACT_CMU7:1;      /**< \brief [7:7] CMU_CLK7 activity (rw) */
        vuint32_t ACT_CMU6:1;      /**< \brief [6:6] CMU_CLK6 activity (rw) */
        vuint32_t ACT_CMU5:1;      /**< \brief [5:5] CMU_CLK5 activity (rw) */
        vuint32_t ACT_CMU4:1;      /**< \brief [4:4] CMU_CLK4 activity (rw) */
        vuint32_t ACT_CMU3:1;      /**< \brief [3:3] CMU_CLK3 activity (rw) */
        vuint32_t ACT_CMU2:1;      /**< \brief [2:2] CMU_CLK2 activity (rw) */
        vuint32_t ACT_CMU1:1;      /**< \brief [1:1] CMU_CLK1 activity (rw) */
        vuint32_t ACT_CMU0:1;      /**< \brief [0:0] CMU_CLK0 activity (rw) */
    } B;
} GTM_MON_STATUS;

typedef union _GTM_MON_ACTIVITY_R0 {
    vuint32_t R;
    struct {
        vuint32_t MCA_3_7:1;       /**< \brief [31:31] Activity of check performed in module MCS 3 at channel 7 (rw) */
        vuint32_t MCA_3_6:1;       /**< \brief [30:30] Activity of check performed in module MCS 3 at channel 6 (rw) */
        vuint32_t MCA_3_5:1;       /**< \brief [29:29] Activity of check performed in module MCS 3 at channel 5 (rw) */
        vuint32_t MCA_3_4:1;       /**< \brief [28:28] Activity of check performed in module MCS 3 at channel 4 (rw) */
        vuint32_t MCA_3_3:1;       /**< \brief [27:27] Activity of check performed in module MCS 3 at channel 3 (rw) */
        vuint32_t MCA_3_2:1;       /**< \brief [26:26] Activity of check performed in module MCS 3 at channel 2 (rw) */
        vuint32_t MCA_3_1:1;       /**< \brief [25:25] Activity of check performed in module MCS 3 at channel 1 (rw) */
        vuint32_t MCA_3_0:1;       /**< \brief [24:24] Activity of check performed in module MCS 3 at channel 0 (rw) */
        vuint32_t MCA_2_7:1;       /**< \brief [23:23] Activity of check performed in module MCS 2 at channel 7 (rw) */
        vuint32_t MCA_2_6:1;       /**< \brief [22:22] Activity of check performed in module MCS 2 at channel 6 (rw) */
        vuint32_t MCA_2_5:1;       /**< \brief [21:21] Activity of check performed in module MCS 2 at channel 5 (rw) */
        vuint32_t MCA_2_4:1;       /**< \brief [20:20] Activity of check performed in module MCS 2 at channel 4 (rw) */
        vuint32_t MCA_2_3:1;       /**< \brief [19:19] Activity of check performed in module MCS 2 at channel 3 (rw) */
        vuint32_t MCA_2_2:1;       /**< \brief [18:18] Activity of check performed in module MCS 2 at channel 2 (rw) */
        vuint32_t MCA_2_1:1;       /**< \brief [17:17] Activity of check performed in module MCS 2 at channel 1 (rw) */
        vuint32_t MCA_2_0:1;       /**< \brief [16:16] Activity of check performed in module MCS 2 at channel 0 (rw) */
        vuint32_t MCA_1_7:1;       /**< \brief [15:15] Activity of check performed in module MCS 1 at channel 7 (rw) */
        vuint32_t MCA_1_6:1;       /**< \brief [14:14] Activity of check performed in module MCS 1 at channel 6 (rw) */
        vuint32_t MCA_1_5:1;       /**< \brief [13:13] Activity of check performed in module MCS 1 at channel 5 (rw) */
        vuint32_t MCA_1_4:1;       /**< \brief [12:12] Activity of check performed in module MCS 1 at channel 4 (rw) */
        vuint32_t MCA_1_3:1;       /**< \brief [11:11] Activity of check performed in module MCS 1 at channel 3 (rw) */
        vuint32_t MCA_1_2:1;       /**< \brief [10:10] Activity of check performed in module MCS 1 at channel 2 (rw) */
        vuint32_t MCA_1_1:1;       /**< \brief [9:9] Activity of check performed in module MCS 1 at channel 1 (rw) */
        vuint32_t MCA_1_0:1;       /**< \brief [8:8] Activity of check performed in module MCS 1 at channel 0 (rw) */
        vuint32_t MCA_0_7:1;       /**< \brief [7:7] Activity of check performed in module MCS 0 at channel 7 (rw) */
        vuint32_t MCA_0_6:1;       /**< \brief [6:6] Activity of check performed in module MCS 0 at channel 6 (rw) */
        vuint32_t MCA_0_5:1;       /**< \brief [5:5] Activity of check performed in module MCS 0 at channel 5 (rw) */
        vuint32_t MCA_0_4:1;       /**< \brief [4:4] Activity of check performed in module MCS 0 at channel 4 (rw) */
        vuint32_t MCA_0_3:1;       /**< \brief [3:3] Activity of check performed in module MCS 0 at channel 3 (rw) */
        vuint32_t MCA_0_2:1;       /**< \brief [2:2] Activity of check performed in module MCS 0 at channel 2 (rw) */
        vuint32_t MCA_0_1:1;       /**< \brief [1:1] Activity of check performed in module MCS 0 at channel 1 (rw) */
        vuint32_t MCA_0_0:1;       /**< \brief [0:0] Activity of check performed in module MCS 0 at channel 0 (rw) */
    } B;
} GTM_MON_ACTIVITY_R0;

typedef union _GTM_MON_ACTIVITY_R1 {
    vuint32_t R;
    struct {
        vuint32_t MCA_7_7:1;       /**< \brief [31:31] Activity of check performed in module MCS 7 at channel 7 - MCA_7_7 (rw) */
        vuint32_t MCA_7_6:1;       /**< \brief [30:30] Activity of check performed in module MCS 7 at channel 6 - MCA_7_6 (rw) */
        vuint32_t MCA_7_5:1;       /**< \brief [29:29] Activity of check performed in module MCS 7 at channel 5 - MCA_7_5 (rw) */
        vuint32_t MCA_7_4:1;       /**< \brief [28:28] Activity of check performed in module MCS 7 at channel 4 - MCA_7_4 (rw) */
        vuint32_t MCA_7_3:1;       /**< \brief [27:27] Activity of check performed in module MCS 7 at channel 3 - MCA_7_3 (rw) */
        vuint32_t MCA_7_2:1;       /**< \brief [26:26] Activity of check performed in module MCS 7 at channel 2 - MCA_7_2 (rw) */
        vuint32_t MCA_7_1:1;       /**< \brief [25:25] Activity of check performed in module MCS 7 at channel 1 - MCA_7_1 (rw) */
        vuint32_t MCA_7_0:1;       /**< \brief [24:24] Activity of check performed in module MCS 7 at channel 0 - MCA_7_0 (rw) */
        vuint32_t MCA_6_7:1;       /**< \brief [23:23] Activity of check performed in module MCS 6 at channel 7 (rw) */
        vuint32_t MCA_6_6:1;       /**< \brief [22:22] Activity of check performed in module MCS 6 at channel 6 (rw) */
        vuint32_t MCA_6_5:1;       /**< \brief [21:21] Activity of check performed in module MCS 6 at channel 5 (rw) */
        vuint32_t MCA_6_4:1;       /**< \brief [20:20] Activity of check performed in module MCS 6 at channel 4 (rw) */
        vuint32_t MCA_6_3:1;       /**< \brief [19:19] Activity of check performed in module MCS 6 at channel 3 (rw) */
        vuint32_t MCA_6_2:1;       /**< \brief [18:18] Activity of check performed in module MCS 6 at channel 2 (rw) */
        vuint32_t MCA_6_1:1;       /**< \brief [17:17] Activity of check performed in module MCS 6 at channel 1 (rw) */
        vuint32_t MCA_6_0:1;       /**< \brief [16:16] Activity of check performed in module MCS 6 at channel 0 (rw) */
        vuint32_t MCA_5_7:1;       /**< \brief [15:15] Activity of check performed in module MCS 5 at channel 7 (rw) */
        vuint32_t MCA_5_6:1;       /**< \brief [14:14] Activity of check performed in module MCS 5 at channel 6 (rw) */
        vuint32_t MCA_5_5:1;       /**< \brief [13:13] Activity of check performed in module MCS 5 at channel 5 (rw) */
        vuint32_t MCA_5_4:1;       /**< \brief [12:12] Activity of check performed in module MCS 5 at channel 4 (rw) */
        vuint32_t MCA_5_3:1;       /**< \brief [11:11] Activity of check performed in module MCS 5 at channel 3 (rw) */
        vuint32_t MCA_5_2:1;       /**< \brief [10:10] Activity of check performed in module MCS 5 at channel 2 (rw) */
        vuint32_t MCA_5_1:1;       /**< \brief [9:9] Activity of check performed in module MCS 5 at channel 1 (rw) */
        vuint32_t MCA_5_0:1;       /**< \brief [8:8] Activity of check performed in module MCS 5 at channel 0 (rw) */
        vuint32_t MCA_4_7:1;       /**< \brief [7:7] Activity of check performed in module MCS 4 at channel 7 (rw) */
        vuint32_t MCA_4_6:1;       /**< \brief [6:6] Activity of check performed in module MCS 4 at channel 6 (rw) */
        vuint32_t MCA_4_5:1;       /**< \brief [5:5] Activity of check performed in module MCS 4 at channel 5 (rw) */
        vuint32_t MCA_4_4:1;       /**< \brief [4:4] Activity of check performed in module MCS 4 at channel 4 (rw) */
        vuint32_t MCA_4_3:1;       /**< \brief [3:3] Activity of check performed in module MCS 4 at channel 3 (rw) */
        vuint32_t MCA_4_2:1;       /**< \brief [2:2] Activity of check performed in module MCS 4 at channel 2 (rw) */
        vuint32_t MCA_4_1:1;       /**< \brief [1:1] Activity of check performed in module MCS 4 at channel 1 (rw) */
        vuint32_t MCA_4_0:1;       /**< \brief [0:0] Activity of check performed in module MCS 4 at channel 0 (rw) */
    } B;
} GTM_MON_ACTIVITY_R1;

typedef union _GTM_MON_ACTIVITY_MCS {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t MCA_7:1;         /**< \brief [7:7] Activity of check performed in module MCS[z] at channel 7 (rw) */
        vuint32_t MCA_6:1;         /**< \brief [6:6] Activity of check performed in module MCS[z] at channel 6 (rw) */
        vuint32_t MCA_5:1;         /**< \brief [5:5] Activity of check performed in module MCS[z] at channel 5 (rw) */
        vuint32_t MCA_4:1;         /**< \brief [4:4] Activity of check performed in module MCS[z] at channel 4 (rw) */
        vuint32_t MCA_3:1;         /**< \brief [3:3] Activity of check performed in module MCS[z] at channel 3 (rw) */
        vuint32_t MCA_2:1;         /**< \brief [2:2] Activity of check performed in module MCS[z] at channel 2 (rw) */
        vuint32_t MCA_1:1;         /**< \brief [1:1] Activity of check performed in module MCS[z] at channel 1 (rw) */
        vuint32_t MCA_0:1;         /**< \brief [0:0] Activity of check performed in module MCS[z] at channel 0 (rw) */
    } B;
} GTM_MON_ACTIVITY_MCS;

typedef volatile struct _GTM_MON_ACTIVITY {
       GTM_MON_ACTIVITY_R0             R0;                     /**< \brief 0, Monitor Activity Register 0*/
       GTM_MON_ACTIVITY_R1             R1;                     /**< \brief 4, Monitor Activity Register 1*/
       GTM_MON_ACTIVITY_MCS            MCS[10];                /**< \brief 8, Monitor Activity Register for MCS ${z}*/
} GTM_MON_ACTIVITY;

typedef volatile struct _GTM_MON {
       GTM_MON_STATUS                  STATUS;                 /**< \brief 0, Monitor Status Register*/
       GTM_MON_ACTIVITY                ACTIVITY;               /**< \brief 4, */
} GTM_MON;

/* ============================================================================
   =============================== Module: GTM_CMP ================================
   ============================================================================ */
typedef union _GTM_CMP_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TBWC11_EN:1;     /**< \brief [23:23] Enable comparator 11 in TBWC (rw) */
        vuint32_t TBWC10_EN:1;     /**< \brief [22:22] Enable comparator 10 in TBWC (rw) */
        vuint32_t TBWC9_EN:1;      /**< \brief [21:21] Enable comparator 9 in TBWC (rw) */
        vuint32_t TBWC8_EN:1;      /**< \brief [20:20] Enable comparator 8 in TBWC (rw) */
        vuint32_t TBWC7_EN:1;      /**< \brief [19:19] Enable comparator 7 in TBWC (rw) */
        vuint32_t TBWC6_EN:1;      /**< \brief [18:18] Enable comparator 6 in TBWC (rw) */
        vuint32_t TBWC5_EN:1;      /**< \brief [17:17] Enable comparator 5 in TBWC (rw) */
        vuint32_t TBWC4_EN:1;      /**< \brief [16:16] Enable comparator 4 in TBWC (rw) */
        vuint32_t TBWC3_EN:1;      /**< \brief [15:15] Enable comparator 3 in TBWC (rw) */
        vuint32_t TBWC2_EN:1;      /**< \brief [14:14] Enable comparator 2 in TBWC (rw) */
        vuint32_t TBWC1_EN:1;      /**< \brief [13:13] Enable comparator 1 in TBWC (rw) */
        vuint32_t TBWC0_EN:1;      /**< \brief [12:12] Enable comparator 0 in TBWC (rw) */
        vuint32_t ABWC11_EN:1;     /**< \brief [11:11] Enable comparator 11 in ABWC (rw) */
        vuint32_t ABWC10_EN:1;     /**< \brief [10:10] Enable comparator 10 in ABWC (rw) */
        vuint32_t ABWC9_EN:1;      /**< \brief [9:9] Enable comparator 9 in ABWC (rw) */
        vuint32_t ABWC8_EN:1;      /**< \brief [8:8] Enable comparator 8 in ABWC (rw) */
        vuint32_t ABWC7_EN:1;      /**< \brief [7:7] Enable comparator 7 in ABWC (rw) */
        vuint32_t ABWC6_EN:1;      /**< \brief [6:6] Enable comparator 6 in ABWC (rw) */
        vuint32_t ABWC5_EN:1;      /**< \brief [5:5] Enable comparator 5 in ABWC (rw) */
        vuint32_t ABWC4_EN:1;      /**< \brief [4:4] Enable comparator 4 in ABWC (rw) */
        vuint32_t ABWC3_EN:1;      /**< \brief [3:3] Enable comparator 3 in ABWC (rw) */
        vuint32_t ABWC2_EN:1;      /**< \brief [2:2] Enable comparator 2 in ABWC (rw) */
        vuint32_t ABWC1_EN:1;      /**< \brief [1:1] Enable comparator 1 in ABWC (rw) */
        vuint32_t ABWC0_EN:1;      /**< \brief [0:0] Enable comparator 0 in ABWC (rw) */
    } B;
} GTM_CMP_EN;

typedef union _GTM_CMP_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TBWC11:1;        /**< \brief [23:23] TOM sub-modules outputs bitwise comparator 11 error indication (rw) */
        vuint32_t TBWC10:1;        /**< \brief [22:22] TOM sub-modules outputs bitwise comparator 10 error indication (rw) */
        vuint32_t TBWC9:1;         /**< \brief [21:21] TOM sub-modules outputs bitwise comparator 9 error indication (rw) */
        vuint32_t TBWC8:1;         /**< \brief [20:20] TOM sub-modules outputs bitwise comparator 8 error indication (rw) */
        vuint32_t TBWC7:1;         /**< \brief [19:19] TOM sub-modules outputs bitwise comparator 7 error indication (rw) */
        vuint32_t TBWC6:1;         /**< \brief [18:18] TOM sub-modules outputs bitwise comparator 6 error indication (rw) */
        vuint32_t TBWC5:1;         /**< \brief [17:17] TOM sub-modules outputs bitwise comparator 5 error indication (rw) */
        vuint32_t TBWC4:1;         /**< \brief [16:16] TOM sub-modules outputs bitwise comparator 4 error indication (rw) */
        vuint32_t TBWC3:1;         /**< \brief [15:15] TOM sub-modules outputs bitwise comparator 3 error indication (rw) */
        vuint32_t TBWC2:1;         /**< \brief [14:14] TOM sub-modules outputs bitwise comparator 2 error indication (rw) */
        vuint32_t TBWC1:1;         /**< \brief [13:13] TOM sub-modules outputs bitwise comparator 1 error indication (rw) */
        vuint32_t TBWC0:1;         /**< \brief [12:12] TOM sub-modules outputs bitwise comparator 0 error indication (rw) */
        vuint32_t ABWC11:1;        /**< \brief [11:11] Error indication for ABWC11 (rw) */
        vuint32_t ABWC10:1;        /**< \brief [10:10] Error indication for ABWC10 (rw) */
        vuint32_t ABWC9:1;         /**< \brief [9:9] Error indication for ABWC9 (rw) */
        vuint32_t ABWC8:1;         /**< \brief [8:8] Error indication for ABWC8 (rw) */
        vuint32_t ABWC7:1;         /**< \brief [7:7] Error indication for ABWC7 (rw) */
        vuint32_t ABWC6:1;         /**< \brief [6:6] Error indication for ABWC6 (rw) */
        vuint32_t ABWC5:1;         /**< \brief [5:5] Error indication for ABWC5 (rw) */
        vuint32_t ABWC4:1;         /**< \brief [4:4] Error indication for ABWC4 (rw) */
        vuint32_t ABWC3:1;         /**< \brief [3:3] Error indication for ABWC3 (rw) */
        vuint32_t ABWC2:1;         /**< \brief [2:2] Error indication for ABWC2 (rw) */
        vuint32_t ABWC1:1;         /**< \brief [1:1] Error indication for ABWC1 (rw) */
        vuint32_t ABWC0:1;         /**< \brief [0:0] Error indication for ABWC0 (rw) */
    } B;
} GTM_CMP_IRQ_NOTIFY;

typedef union _GTM_CMP_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TBWC11_EN_IRQ:1;    /**< \brief [23:23] Enable TBWC11 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC10_EN_IRQ:1;    /**< \brief [22:22] Enable TBWC10 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC9_EN_IRQ:1;    /**< \brief [21:21] Enable TBWC9 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC8_EN_IRQ:1;    /**< \brief [20:20] Enable TBWC8 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC7_EN_IRQ:1;    /**< \brief [19:19] Enable TBWC7 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC6_EN_IRQ:1;    /**< \brief [18:18] Enable TBWC6 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC5_EN_IRQ:1;    /**< \brief [17:17] Enable TBWC5 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC4_EN_IRQ:1;    /**< \brief [16:16] Enable TBWC4 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC3_EN_IRQ:1;    /**< \brief [15:15] Enable TBWC3 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC2_EN_IRQ:1;    /**< \brief [14:14] Enable TBWC2 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC1_EN_IRQ:1;    /**< \brief [13:13] Enable TBWC1 interrupt source for CMP_IRQ line (rw) */
        vuint32_t TBWC0_EN_IRQ:1;    /**< \brief [12:12] Enable TBWC0 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC11_EN_IRQ:1;    /**< \brief [11:11] Enable ABWC11 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC10_EN_IRQ:1;    /**< \brief [10:10] Enable ABWC10 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC9_EN_IRQ:1;    /**< \brief [9:9] Enable ABWC9 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC8_EN_IRQ:1;    /**< \brief [8:8] Enable ABWC8 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC7_EN_IRQ:1;    /**< \brief [7:7] Enable ABWC7 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC6_EN_IRQ:1;    /**< \brief [6:6] Enable ABWC6 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC5_EN_IRQ:1;    /**< \brief [5:5] Enable ABWC5 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC4_EN_IRQ:1;    /**< \brief [4:4] Enable ABWC4 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC3_EN_IRQ:1;    /**< \brief [3:3] Enable ABWC3 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC2_EN_IRQ:1;    /**< \brief [2:2] Enable ABWC2 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC1_EN_IRQ:1;    /**< \brief [1:1] Enable ABWC1 interrupt source for CMP_IRQ line (rw) */
        vuint32_t ABWC0_EN_IRQ:1;    /**< \brief [0:0] Enable ABWC0 interrupt source for CMP_IRQ line (rw) */
    } B;
} GTM_CMP_IRQ_EN;

typedef union _GTM_CMP_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TRG_TBWC11:1;    /**< \brief [23:23] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC10:1;    /**< \brief [22:22] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC9:1;     /**< \brief [21:21] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC8:1;     /**< \brief [20:20] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC7:1;     /**< \brief [19:19] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC6:1;     /**< \brief [18:18] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC5:1;     /**< \brief [17:17] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC4:1;     /**< \brief [16:16] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC3:1;     /**< \brief [15:15] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC2:1;     /**< \brief [14:14] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC1:1;     /**< \brief [13:13] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TBWC0:1;     /**< \brief [12:12] Trigger TBWCx bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC11:1;    /**< \brief [11:11] Trigger ABWC11 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC10:1;    /**< \brief [10:10] Trigger ABWC10 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC9:1;     /**< \brief [9:9] Trigger ABWC9 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC8:1;     /**< \brief [8:8] Trigger ABWC8 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC7:1;     /**< \brief [7:7] Trigger ABWC7 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC6:1;     /**< \brief [6:6] Trigger ABWC6 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC5:1;     /**< \brief [5:5] Trigger ABWC5 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC4:1;     /**< \brief [4:4] Trigger ABWC4 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC3:1;     /**< \brief [3:3] Trigger ABWC3 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC2:1;     /**< \brief [2:2] Trigger ABWC2 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC1:1;     /**< \brief [1:1] Trigger ABWC1 bit in CMP_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ABWC0:1;     /**< \brief [0:0] Trigger ABWC0 bit in CMP_IRQ_NOTIFY register by software (rw) */
    } B;
} GTM_CMP_IRQ_FORCINT;

typedef union _GTM_CMP_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;      /**< \brief [1:0] IRQ mode selection - IRQ_MODE (rw) */
    } B;
} GTM_CMP_IRQ_MODE;

typedef union _GTM_CMP_EIRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t ABWC0_EN_EIRQ:1;    /**< \brief [0:0] Enable ABWC0 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC1_EN_EIRQ:1;    /**< \brief [1:1] Enable ABWC1 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC2_EN_EIRQ:1;    /**< \brief [2:2] Enable ABWC2 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC3_EN_EIRQ:1;    /**< \brief [3:3] Enable ABWC3 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC4_EN_EIRQ:1;    /**< \brief [4:4] Enable ABWC4 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC5_EN_EIRQ:1;    /**< \brief [5:5] Enable ABWC5 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC6_EN_EIRQ:1;    /**< \brief [6:6] Enable ABWC6 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC7_EN_EIRQ:1;    /**< \brief [7:7] Enable ABWC7 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC8_EN_EIRQ:1;    /**< \brief [8:8] Enable ABWC8 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC9_EN_EIRQ:1;    /**< \brief [9:9] Enable ABWC9 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC10_EN_EIRQ:1;    /**< \brief [10:10] Enable ABWC10 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t ABWC11_EN_EIRQ:1;    /**< \brief [11:11] Enable ABWC11 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC0_EN_EIRQ:1;    /**< \brief [12:12] Enable TBWC0 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC1_EN_EIRQ:1;    /**< \brief [13:13] Enable TBWC1 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC2_EN_EIRQ:1;    /**< \brief [14:14] Enable TBWC2 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC3_EN_EIRQ:1;    /**< \brief [15:15] Enable TBWC3 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC4_EN_EIRQ:1;    /**< \brief [16:16] Enable TBWC4 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC5_EN_EIRQ:1;    /**< \brief [17:17] Enable TBWC5 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC6_EN_EIRQ:1;    /**< \brief [18:18] Enable TBWC6 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC7_EN_EIRQ:1;    /**< \brief [19:19] Enable TBWC7 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC8_EN_EIRQ:1;    /**< \brief [20:20] Enable TBWC8 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC9_EN_EIRQ:1;    /**< \brief [21:21] Enable TBWC9 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC10_EN_EIRQ:1;    /**< \brief [22:22] Enable TBWC10 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t TBWC11_EN_EIRQ:1;    /**< \brief [23:23] Enable TBWC11 interrupt source for CMP_EIRQ line (rw) */
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
    } B;
} GTM_CMP_EIRQ_EN;

typedef volatile struct _GTM_CMP {
       GTM_CMP_EN                      EN;                     /**< \brief 0, CMP Comparator Enable Register*/
       GTM_CMP_IRQ_NOTIFY              IRQ_NOTIFY;             /**< \brief 4, CMP Event Notification Register*/
       GTM_CMP_IRQ_EN                  IRQ_EN;                 /**< \brief 8, CMP Interrupt Enable Register*/
       GTM_CMP_IRQ_FORCINT             IRQ_FORCINT;            /**< \brief C, CMP Interrupt Force Register*/
       GTM_CMP_IRQ_MODE                IRQ_MODE;               /**< \brief 10, CMP Interrupt Mode Configuration Register*/
       GTM_CMP_EIRQ_EN                 EIRQ_EN;                /**< \brief 14, CMP error interrupt enable register*/
} GTM_CMP;

/* ============================================================================
   =============================== Module: GTM_TIM ================================
   ============================================================================ */
typedef union _GTM_TIM_CH_GPR0 {
    vuint32_t R;
    struct {
        vuint32_t ECNT:8;          /**< \brief [31:24] Edge counter (rh) */
        vuint32_t GPR0:24;         /**< \brief [23:0] Input signal characteristic parameter 0 (rw) */
    } B;
} GTM_TIM_CH_GPR0;

typedef union _GTM_TIM_CH_GPR1 {
    vuint32_t R;
    struct {
        vuint32_t ECNT:8;          /**< \brief [31:24] Edge counter (rh) */
        vuint32_t GPR1:24;         /**< \brief [23:0] Input signal characteristic parameter 1 (rw) */
    } B;
} GTM_TIM_CH_GPR1;

typedef union _GTM_TIM_CH_CNT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CNT:24;          /**< \brief [23:0] Actual SMU counter value (r) */
    } B;
} GTM_TIM_CH_CNT;

typedef union _GTM_TIM_CH_ECNT {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;  /**< \brief [31:16] \internal Reserved */
        vuint32_t ECNT:16;         /**< \brief [15:0] Edge counter (r) */
    } B;
} GTM_TIM_CH_ECNT;

typedef union _GTM_TIM_CH_CNTS {
    vuint32_t R;
    struct {
        vuint32_t ECNT:8;          /**< \brief [31:24] Edge counter - ECNT (r) */
        vuint32_t CNTS:24;         /**< \brief [23:0] Counter shadow register (rw) */
    } B;
} GTM_TIM_CH_CNTS;

typedef union _GTM_TIM_CH_TDUC {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TO_CNT2:8;       /**< \brief [23:16] Current Timeout value slice2 for channel x (rw) */
        vuint32_t TO_CNT1:8;       /**< \brief [15:8] Current Timeout value slice1 for channel x (rw) */
        vuint32_t TO_CNT:8;        /**< \brief [7:0] Current Timeout value slice0 for channel x (rw) */
    } B;
} GTM_TIM_CH_TDUC;

typedef union _GTM_TIM_CH_TDUV {
    vuint32_t R;
    struct {
        vuint32_t reserved_31:1;    /**< \brief [31:31] \internal Reserved */
        vuint32_t TCS:3;           /**< \brief [30:28] Timeout Clock selection (rw) */
        vuint32_t TDU_SAME_CNT_CLK:1;    /**< \brief [27:27] Define clocking of TO_CNT, TO_CNT1 (rw) */
        vuint32_t TCS_USE_SAMPLE_EVT:1;    /**< \brief [26:26] Use tdu_sample_evt as Timeout Clock (rw) */
        vuint32_t SLICING:2;       /**< \brief [25:24] Cascading of counter slices (rw) */
        vuint32_t TOV2:8;          /**< \brief [23:16] Time out compare value slice2 for channel x (rw) */
        vuint32_t TOV1:8;          /**< \brief [15:8] Time out compare value slice1 for channel x (rw) */
        vuint32_t TOV:8;           /**< \brief [7:0] Time out compare value slice0 for channel x (rw) */
    } B;
} GTM_TIM_CH_TDUV;

typedef union _GTM_TIM_CH_FLT_RE {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t FLT_RE:24;       /**< \brief [23:0] Filter parameter for rising edge (rw) */
    } B;
} GTM_TIM_CH_FLT_RE;

typedef union _GTM_TIM_CH_FLT_FE {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t FLT_FE:24;       /**< \brief [23:0] Filter parameter for falling edge (rw) */
    } B;
} GTM_TIM_CH_FLT_FE;

typedef union _GTM_TIM_CH_CTRL {
    vuint32_t R;
    struct {
        vuint32_t TOCTRL:2;        /**< \brief [31:30] Timeout control (rw) */
        vuint32_t EGPR1_SEL:1;     /**< \brief [29:29] Extension of GPR1_SEL bit field (rw) */
        vuint32_t EGPR0_SEL:1;     /**< \brief [28:28] Extension of GPR0_SEL bit field (rw) */
        vuint32_t FR_ECNT_OFL:1;    /**< \brief [27:27] Extended Edge counter overflow behavior (rw) */
        vuint32_t CLK_SEL:3;       /**< \brief [26:24] CMU clock source select for channel (rw) */
        vuint32_t FLT_CTR_FE:1;    /**< \brief [23:23] Filter counter mode for falling edge (rw) */
        vuint32_t FLT_MODE_FE:1;    /**< \brief [22:22] Filter mode for falling edge (rw) */
        vuint32_t FLT_CTR_RE:1;    /**< \brief [21:21] Filter counter mode for rising edge (rw) */
        vuint32_t FLT_MODE_RE:1;    /**< \brief [20:20] Filter mode for rising edge (rw) */
        vuint32_t EXT_CAP_EN:1;    /**< \brief [19:19] Enables external capture mode (rw) */
        vuint32_t FLT_CNT_FRQ:2;    /**< \brief [18:17] Filter counter frequency select (rw) */
        vuint32_t FLT_EN:1;        /**< \brief [16:16] Filter enable for channel x (rw) */
        vuint32_t ECNT_RESET:1;    /**< \brief [15:15] Enables resetting of counter in certain modes (rw) */
        vuint32_t ISL:1;           /**< \brief [14:14] Ignore signal level (rw) */
        vuint32_t DSL:1;           /**< \brief [13:13] Signal level control (rw) */
        vuint32_t CNTS_SEL:1;      /**< \brief [12:12] Selection for CNTS register (rw) */
        vuint32_t GPR1_SEL:2;      /**< \brief [11:10] Selection for GPR1 register (rw) */
        vuint32_t GPR0_SEL:2;      /**< \brief [9:8] Selection for GPR0 register (rw) */
        vuint32_t TBU0_SEL:1;      /**< \brief [7:7] TBU_TS0 bits input select for TIM0_CH[x]_GPRz (z: 0, 1) (rw) */
        vuint32_t CICTRL:1;        /**< \brief [6:6] Channel Input Control (rw) */
        vuint32_t ARU_EN:1;        /**< \brief [5:5] GPR0 and GPR1 register values routed to ARU (rw) */
        vuint32_t OSM:1;           /**< \brief [4:4] One-shot mode (rw) */
        vuint32_t TIM_MODE:3;      /**< \brief [3:1] TIM channel x mode (rw) */
        vuint32_t TIM_EN:1;        /**< \brief [0:0] TIM channel x enable (rw) */
    } B;
} GTM_TIM_CH_CTRL;

typedef union _GTM_TIM_CH_ECTRL {
    vuint32_t R;
    struct {
        vuint32_t USE_PREV_CH_IN:1;    /**< \brief [31:31] Select input data source for TIM channel (rw) */
        vuint32_t ECLK_SEL:1;      /**< \brief [30:30] Extension of bit field CLK_SEL (rw) */
        vuint32_t IMM_START:1;     /**< \brief [29:29] Start immediately the measurement (rw) */
        vuint32_t SWAP_CAPTURE:1;    /**< \brief [28:28] Swap point of time of capturing CNTS and GPR1 (rw) */
        vuint32_t reserved_26:2;    /**< \brief [27:26] \internal Reserved */
        vuint32_t EFLT_CTR_FE:1;    /**< \brief [25:25] Extension of bit field FLT_CTR_FE (rw) */
        vuint32_t EFLT_CTR_RE:1;    /**< \brief [24:24] Extension of bit field FLT_CTR_RE (rw) */
        vuint32_t USE_LUT:2;       /**< \brief [23:22] Generate Filter input by lookup table (rw) */
        vuint32_t reserved_20:2;    /**< \brief [21:20] \internal Reserved */
        vuint32_t TDU_RESYNC:4;    /**< \brief [19:16] Defines condition which will resynchronize the TDU unit (rw) */
        vuint32_t reserved_15:1;    /**< \brief [15:15] \internal Reserved */
        vuint32_t TDU_STOP:3;      /**< \brief [14:12] Defines condition which will stop the TDU unit (rw) */
        vuint32_t reserved_11:1;    /**< \brief [11:11] \internal Reserved */
        vuint32_t TDU_START:3;     /**< \brief [10:8] Defines condition which will start the TDU unit (rw) */
        vuint32_t TODET_IRQ_SRC:2;    /**< \brief [7:6] selection of source for TODET_IRQ (rw) */
        vuint32_t USE_PREV_TDU_IN:1;    /**< \brief [5:5] Select input data source for TDU (rw) */
        vuint32_t reserved_4:1;    /**< \brief [4:4] \internal Reserved */
        vuint32_t EXT_CAP_SRC:4;    /**< \brief [3:0] Defines selected source for triggering the EXT_CAPTURE functionality (rw) */
    } B;
} GTM_TIM_CH_ECTRL;

typedef union _GTM_TIM_CH_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:26;    /**< \brief [31:6] \internal Reserved */
        vuint32_t GLITCHDET:1;     /**< \brief [5:5] Glitch detected on channel x, (x:0...m-1) (rw) */
        vuint32_t TODET:1;         /**< \brief [4:4] Timeout reached for input signal of channel x (rw) */
        vuint32_t GPROFL:1;        /**< \brief [3:3] GPR0 and GPR1 data overflow (rw) */
        vuint32_t CNTOFL:1;        /**< \brief [2:2] SMU CNT counter overflow of channel x (rw) */
        vuint32_t ECNTOFL:1;       /**< \brief [1:1] counter overflow of channel x (rw) */
        vuint32_t NEWVAL:1;        /**< \brief [0:0] New measurement value detected by in channel x (rw) */
    } B;
} GTM_TIM_CH_IRQ_NOTIFY;

typedef union _GTM_TIM_CH_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:26;    /**< \brief [31:6] \internal Reserved */
        vuint32_t GLITCHDET_IRQ_EN:1;    /**< \brief [5:5] TIM_GLITCHDETx_IRQ interrupt enable (rw) */
        vuint32_t TODET_IRQ_EN:1;    /**< \brief [4:4] TIM_TODETx_IRQ interrupt enable (rw) */
        vuint32_t GPROFL_IRQ_EN:1;    /**< \brief [3:3] TIM_GPROFL_IRQ interrupt enable (rw) */
        vuint32_t CNTOFL_IRQ_EN:1;    /**< \brief [2:2] TIM_CNTOFLx_IRQ interrupt enable (rw) */
        vuint32_t ECNTOFL_IRQ_EN:1;    /**< \brief [1:1] TIM_ECNTOFLx_IRQ interrupt enable (rw) */
        vuint32_t NEWVAL_IRQ_EN:1;    /**< \brief [0:0] TIM_NEWVALx_IRQ interrupt enable (rw) */
    } B;
} GTM_TIM_CH_IRQ_EN;

typedef union _GTM_TIM_CH_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:26;    /**< \brief [31:6] \internal Reserved */
        vuint32_t TRG_GLITCHDET:1;    /**< \brief [5:5] Trigger GLITCHDET bit in TIM_CHx_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_TODET:1;     /**< \brief [4:4] Trigger TODET bit in TIM_CHx_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_GPROFL:1;    /**< \brief [3:3] Trigger GPROFL bit in TIM_CHx_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_CNTOFL:1;    /**< \brief [2:2] Trigger CNTOFL bit in TIM_CHx_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_ECNTOFL:1;    /**< \brief [1:1] Trigger ECNTOFL bit in TIM_CHx_IRQ_NOTIFY register by software (rw) */
        vuint32_t TRG_NEWVAL:1;    /**< \brief [0:0] Trigger NEWVAL bit in TIM_CHx_IRQ_NOTIFY register by software (rw) */
    } B;
} GTM_TIM_CH_IRQ_FORCINT;

typedef union _GTM_TIM_CH_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;      /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_TIM_CH_IRQ_MODE;

typedef union _GTM_TIM_CH_EIRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:26;    /**< \brief [31:6] \internal Reserved */
        vuint32_t GLITCHDET_EIRQ_EN:1;    /**< \brief [5:5] TIM_GLITCHDETx_IRQ interrupt enable (rw) */
        vuint32_t TODET_EIRQ_EN:1;    /**< \brief [4:4] TIM_TODETx_IRQ interrupt enable (rw) */
        vuint32_t GPROFL_EIRQ_EN:1;    /**< \brief [3:3] TIM_GPROFL_IRQ interrupt enable (rw) */
        vuint32_t CNTOFL_EIRQ_EN:1;    /**< \brief [2:2] TIM_CNTOFLx_IRQ interrupt enable (rw) */
        vuint32_t ECNTOFL_EIRQ_EN:1;    /**< \brief [1:1] TIM_ECNTOFLx_IRQ interrupt enable (rw) */
        vuint32_t NEWVAL_EIRQ_EN:1;    /**< \brief [0:0] TIM_NEWVALx_EIRQ error interrupt enable (rw) */
    } B;
} GTM_TIM_CH_EIRQ_EN;

typedef volatile struct _GTM_TIM_CH {
       GTM_TIM_CH_GPR0                 GPR0;                   /**< \brief 0, TIM${i} Channel ${x} General Purpose 0 Register*/
       GTM_TIM_CH_GPR1                 GPR1;                   /**< \brief 4, TIM${i} Channel ${x} General Purpose 1 Register*/
       GTM_TIM_CH_CNT                  CNT;                    /**< \brief 8, TIM${i} Channel ${x} SMU Counter Register*/
       GTM_TIM_CH_ECNT                 ECNT;                   /**< \brief C, TIM${i} Channel ${x} SMU Edge Counter Register*/
       GTM_TIM_CH_CNTS                 CNTS;                   /**< \brief 10, TIM${i} Channel ${x} SMU Shadow Counter Register*/
       GTM_TIM_CH_TDUC                 TDUC;                   /**< \brief 14, TIM${i} Channel ${x} TDU Counter Register*/
       GTM_TIM_CH_TDUV                 TDUV;                   /**< \brief 18, TIM${i} Channel ${x} TDU Control Register*/
       GTM_TIM_CH_FLT_RE               FLT_RE;                 /**< \brief 1C, TIM${i} Channel ${x} Filter Parameter 0 Register*/
       GTM_TIM_CH_FLT_FE               FLT_FE;                 /**< \brief 20, TIM${i} Channel ${x} Filter Parameter 1 Register*/
       GTM_TIM_CH_CTRL                 CTRL;                   /**< \brief 24, TIM${i} Channel ${x} Control Register*/
       GTM_TIM_CH_ECTRL                ECTRL;                  /**< \brief 28, TIM${i} Channel ${x} Extended Control Register*/
       GTM_TIM_CH_IRQ_NOTIFY           IRQ_NOTIFY;             /**< \brief 2C, TIM${i} Channel ${x} Interrupt Notification Register*/
       GTM_TIM_CH_IRQ_EN               IRQ_EN;                 /**< \brief 30, TIM${i} Channel ${x} Interrupt Enable Register*/
       GTM_TIM_CH_IRQ_FORCINT          IRQ_FORCINT;            /**< \brief 34, TIM${i} Channel ${x} Force Interrupt Register*/
       GTM_TIM_CH_IRQ_MODE             IRQ_MODE;               /**< \brief 38, TIM${i} Channel ${x} Interrupt Mode Configuration Register*/
       GTM_TIM_CH_EIRQ_EN              EIRQ_EN;                /**< \brief 3C, TIM${i} Channel ${x} Error Interrupt Enable Register*/
       vuint8_t                   reserved_40[64];        /**< \brief 40, \internal Reserved */
} GTM_TIM_CH;

typedef union _GTM_TIM_INP_VAL {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TIM_IN:8;        /**< \brief [23:16] Signals after TIM input signal synchronization (r) */
        vuint32_t F_IN:8;          /**< \brief [15:8] Signals after INPSRC selection, before TIM FLT unit (r) */
        vuint32_t F_OUT:8;         /**< \brief [7:0] Signals after TIM FLT unit (r) */
    } B;
} GTM_TIM_INP_VAL;

typedef union _GTM_TIM_IN_SRC {
    vuint32_t R;
    struct {
        vuint32_t MODE_7:2;        /**< \brief [31:30] Input source to Channel 7 (rw) */
        vuint32_t VAL_7:2;         /**< \brief [29:28] Value to be fed to Channel 7 (rw) */
        vuint32_t MODE_6:2;        /**< \brief [27:26] Input source to Channel 6 (rw) */
        vuint32_t VAL_6:2;         /**< \brief [25:24] Value to be fed to Channel 6 (rw) */
        vuint32_t MODE_5:2;        /**< \brief [23:22] Input source to Channel 5 (rw) */
        vuint32_t VAL_5:2;         /**< \brief [21:20] Value to be fed to Channel 5 (rw) */
        vuint32_t MODE_4:2;        /**< \brief [19:18] Input source to Channel 4 (rw) */
        vuint32_t VAL_4:2;         /**< \brief [17:16] Value to be fed to Channel 4 (rw) */
        vuint32_t MODE_3:2;        /**< \brief [15:14] Input source to Channel 3 (rw) */
        vuint32_t VAL_3:2;         /**< \brief [13:12] Value to be fed to Channel 3 (rw) */
        vuint32_t MODE_2:2;        /**< \brief [11:10] Input source to Channel 2 (rw) */
        vuint32_t VAL_2:2;         /**< \brief [9:8] Value to be fed to Channel 2 (rw) */
        vuint32_t MODE_1:2;        /**< \brief [7:6] Input source to Channel 1 (rw) */
        vuint32_t VAL_1:2;         /**< \brief [5:4] Value to be fed to Channel 1 (rw) */
        vuint32_t MODE_0:2;        /**< \brief [3:2] Input source to Channel 0 (rw) */
        vuint32_t VAL_0:2;         /**< \brief [1:0] Value to be fed to Channel 0 (rw) */
    } B;
} GTM_TIM_IN_SRC;

typedef union _GTM_TIM_RST {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t RST_CH7:1;       /**< \brief [7:7] Software reset of channel 7 (rw) */
        vuint32_t RST_CH6:1;       /**< \brief [6:6] Software reset of channel 6 (rw) */
        vuint32_t RST_CH5:1;       /**< \brief [5:5] Software reset of channel 5 (rw) */
        vuint32_t RST_CH4:1;       /**< \brief [4:4] Software reset of channel 4 (rw) */
        vuint32_t RST_CH3:1;       /**< \brief [3:3] Software reset of channel 3 (rw) */
        vuint32_t RST_CH2:1;       /**< \brief [2:2] Software reset of channel 2 (rw) */
        vuint32_t RST_CH1:1;       /**< \brief [1:1] Software reset of channel 1 (rw) */
        vuint32_t RST_CH0:1;       /**< \brief [0:0] Software reset of channel 0 (rw) */
    } B;
} GTM_TIM_RST;

typedef volatile struct _GTM_TIM {
       GTM_TIM_CH                      CH[8];                  /**< \brief 0, */
       GTM_TIM_INP_VAL                 INP_VAL;                /**< \brief 400, TIM${i} Input Value Observation Register*/
       GTM_TIM_IN_SRC                  IN_SRC;                 /**< \brief 404, TIM${i} AUX IN Source Selection Register*/
       GTM_TIM_RST                     RST;                    /**< \brief 408, TIM${i} Global Software Reset Register*/
       vuint8_t                        reserved_40C[1012];     /**< \brief 40C, \internal Reserved */
} GTM_TIM;

/* ============================================================================
   =============================== Module: GTM_TOM ================================
   ============================================================================ */

typedef union _GTM_TOM_CH_CTRL {
    vuint32_t R;
    struct {
        vuint32_t FREEZE:1;        /**< \brief [31:31] FREEZE (rw) */
        vuint32_t reserved_30:1;   /**< \brief [30:30] \internal Reserved */
        vuint32_t GCM:1;           /**< \brief [29:29] Gated Counter Mode enable (rw) */
        vuint32_t SPEM:1;          /**< \brief [28:28] SPE output mode enable for channel (rw) */
        vuint32_t BITREV:1;        /**< \brief [27:27] Bit-reversing of output of counter register CN0 (rw) */
        vuint32_t OSM:1;           /**< \brief [26:26] One-shot mode (rw) */
        vuint32_t SPE_TRIG:1;      /**< \brief [25:25] SPE trigger to reset CN0 (rw) */
        vuint32_t TRIGOUT:1;       /**< \brief [24:24] Trigger output selection (output signal TRIG_[x]) of module TOM_CH[x] (rw) */
        vuint32_t EXTTRIGOUT:1;    /**< \brief [23:23] TIM_EXT_CAPTURE(x) as potential output signal TRIG_[x] (rw) */
        vuint32_t EXT_TRIG:1;      /**< \brief [22:22] Select TIM_EXT_CAPTURE(x) as trigger signal (rw) */
        vuint32_t OSM_TRIG:1;      /**< \brief [21:21] Enable trigger of one-shot pulse by trigger signal OSM_TRIG (rw) */
        vuint32_t RST_CCU0:1;      /**< \brief [20:20] Reset source of CCU0 (rw) */
        vuint32_t UDMODE:2;        /**< \brief [19:18] Up-down counter mode (rw) */
        vuint32_t TRIG_PULSE:1;    /**< \brief [17:17] Clock source select for channel (rw) */
        vuint32_t reserved_16:1;   /**< \brief [16:16] \internal Reserved */
        vuint32_t CLK_SRC:4;       /**< \brief [15:12] Clock source select for channel (rw) */
        vuint32_t SL:1;            /**< \brief [11:11] Signal level for duty cycle (rw) */
        vuint32_t reserved_8:3;    /**< \brief [10:8] \internal Reserved */
        vuint32_t SR0_TRIG:1;      /**< \brief [7:7] SR0 is used to generate a trigger on output TOM[i]_CH[x]_OUT_T if equal to CN0 (rw) */
        vuint32_t reserved_0:7;    /**< \brief [6:0] \internal Reserved */
    } B;
} GTM_TOM_CH_CTRL;

typedef union _GTM_TOM_CH_SR0 {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t SR0:16;          /**< \brief [15:0] TOM channel x shadow register SR0 for update of compare register CM0 (rw) */
    } B;
} GTM_TOM_CH_SR0;

typedef union _GTM_TOM_CH_SR1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t SR1:16;            /**< \brief [15:0] TOM channel x shadow register SR1 for update of compare register CM1 (rw) */
    } B;
} GTM_TOM_CH_SR1;

typedef union _GTM_TOM_CH_CM0 {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t CM0:16;          /**< \brief [15:0] TOM CCU0 compare register (rw) */
    } B;
} GTM_TOM_CH_CM0;

typedef union _GTM_TOM_CH_CM1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t CM1:16;          /**< \brief [15:0] TOM CCU1 compare register (rw) */
    } B;
} GTM_TOM_CH_CM1;

typedef union _GTM_TOM_CH_CN0 {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t CN0:16;          /**< \brief [15:0] TOM CCU0 counter register (rw) */
    } B;
} GTM_TOM_CH_CN0;

typedef union _GTM_TOM_CH_STAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_30:2;    /**< \brief [31:30] \internal Reserved */
        vuint32_t OSM_RTF:1;        /**< \brief [29:29] Output level of output TOM_OUT(x) (r) */
        vuint32_t reserved_1:28;    /**< \brief [28:1] \internal Reserved */
        vuint32_t OL:1;             /**< \brief [0:0] Output level of output TOM_OUT(x) (r) */
    } B;
} GTM_TOM_CH_STAT;

typedef union _GTM_TOM_CH_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t CCU1TC:1;        /**< \brief [1:1] CCU1 Trigger condition interrupt for channel x (rw) */
        vuint32_t CCU0TC:1;        /**< \brief [0:0] CCU0 Trigger condition interrupt for channel x (rw) */
    } B;
} GTM_TOM_CH_IRQ_NOTIFY;

typedef union _GTM_TOM_CH_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t CCU1TC_IRQ_EN:1;    /**< \brief [1:1] TOM_CCU1TC_IRQ interrupt enable (rw) */
        vuint32_t CCU0TC_IRQ_EN:1;    /**< \brief [0:0] TOM_CCU0TC_IRQ interrupt enable (rw) */
    } B;
} GTM_TOM_CH_IRQ_EN;

typedef union _GTM_TOM_CH_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t TRG_CCU1TC0:1;    /**< \brief [1:1] Trigger TOM_CCU1TC0_IRQ interrupt by software (rw) */
        vuint32_t TRG_CCU0TC0:1;    /**< \brief [0:0] Trigger TOM_CCU0TC0_IRQ interrupt by software (rw) */
    } B;
} GTM_TOM_CH_IRQ_FORCINT;

typedef union _GTM_TOM_CH_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;      /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_TOM_CH_IRQ_MODE;

typedef union _GTM_TOM_CH_CTRL2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;   /**< \brief [31:1] \internal Reserved */
        vuint32_t HRES:1;          /**< \brief [0:0] TOM[i] high鈭抮esolution support (rw) */
    } B;
} GTM_TOM_CH_CTRL2;

typedef union _GTM_TOM_CH_CTRL_SR {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t CLK_SRC_SR:4;     /**< \brief [15:12] Shadow register for TOM[i]_CH[x]_CTRL.CLK_SRC (rw) */
        vuint32_t SL_SR:1;          /**< \brief [11:11] Shadow register for TOM[i]_CH[x]_CTRL.SL (rw) */
        vuint32_t reserved_0:11;    /**< \brief [10:0] \internal Reserved */
    } B;
} GTM_TOM_CH_CTRL_SR;

typedef volatile struct _GTM_TOM_CH {
       GTM_TOM_CH_CTRL                 CTRL;                   /**< \brief 0, TOM${i} Channel ${x} Control Register*/
       GTM_TOM_CH_SR0                  SR0;                    /**< \brief 4, TOM${i} Channel ${x} CCU0 Compare Shadow Register*/
       GTM_TOM_CH_SR1                  SR1;                    /**< \brief 8, TOM${i} Channel ${x} CCU1 Compare Shadow Register*/
       GTM_TOM_CH_CM0                  CM0;                    /**< \brief C, TOM${i} Channel ${x} CCU0 Compare Register*/
       GTM_TOM_CH_CM1                  CM1;                    /**< \brief 10, TOM${i} Channel ${x} CCU1 Compare Register*/
       GTM_TOM_CH_CN0                  CN0;                    /**< \brief 14, TOM${i} Channel ${x} CCU0 Counter Register*/
       GTM_TOM_CH_STAT                 STAT;                   /**< \brief 18, TOM${i} Channel ${x} Status Register*/
       GTM_TOM_CH_IRQ_NOTIFY           IRQ_NOTIFY;             /**< \brief 1C, TOM${i} Channel ${x} Interrupt Notification Register*/
       GTM_TOM_CH_IRQ_EN               IRQ_EN;                 /**< \brief 20, TOM${i} Channel ${x} Interrupt Enable Register*/
       GTM_TOM_CH_IRQ_FORCINT          IRQ_FORCINT;            /**< \brief 24, TOM${i} Channel ${x} Force Interrupt Register*/
       GTM_TOM_CH_IRQ_MODE             IRQ_MODE;               /**< \brief 28, TOM${i} Channel ${x} Interrupt Mode Register*/
       GTM_TOM_CH_CTRL2                CTRL2;                  /**< \brief 2C, TOM${i} channel ${x} control register */
       GTM_TOM_CH_CTRL_SR              CTRL_SR;                /**< \brief 30, TOM${i} channel ${x} control shadow register */
       vuint8_t                   reserved_34[12];        /**< \brief 34, \internal Reserved */
} GTM_TOM_CH;

typedef union _GTM_TOM_TGC_GLB_CTRL {
    vuint32_t R;
    struct {
        vuint32_t UPEN_CTRL7:2;    /**< \brief [31:30] TOM channel 7 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL6:2;    /**< \brief [29:28] TOM channel 6 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL5:2;    /**< \brief [27:26] TOM channel 5 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL4:2;    /**< \brief [25:24] TOM channel 4 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL3:2;    /**< \brief [23:22] TOM channel 3 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL2:2;    /**< \brief [21:20] TOM channel 2 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL1:2;    /**< \brief [19:18] TOM channel 1 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL0:2;    /**< \brief [17:16] TOM channel 0 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t RST_CH7:1;       /**< \brief [15:15] Software reset of channel 7 (w) */
        vuint32_t RST_CH6:1;       /**< \brief [14:14] Software reset of channel 6 (w) */
        vuint32_t RST_CH5:1;       /**< \brief [13:13] Software reset of channel 5 (w) */
        vuint32_t RST_CH4:1;       /**< \brief [12:12] Software reset of channel 4 (w) */
        vuint32_t RST_CH3:1;       /**< \brief [11:11] Software reset of channel 3 (w) */
        vuint32_t RST_CH2:1;       /**< \brief [10:10] Software reset of channel 2 (w) */
        vuint32_t RST_CH1:1;       /**< \brief [9:9] Software reset of channel 1 (w) */
        vuint32_t RST_CH0:1;       /**< \brief [8:8] Software reset of channel 0 (w) */
        vuint32_t reserved_1:7;    /**< \brief [7:1] \internal Reserved */
        vuint32_t HOST_TRIG:1;     /**< \brief [0:0] Trigger request signal (see TGC0, TGC1) to update the register ENDIS_STAT and OUTEN_STAT (w) */
    } B;
} GTM_TOM_TGC_GLB_CTRL;

typedef union _GTM_TOM_TGC_ACT_TB {
    vuint32_t R;
    struct {
        vuint32_t reserved_27:5;    /**< \brief [31:27] \internal Reserved */
        vuint32_t TBU_SEL:2;       /**< \brief [26:25] Selection of time base used for comparison (rw) */
        vuint32_t TB_TRIG:1;       /**< \brief [24:24] Set trigger request (rw) */
        vuint32_t ACT_TB:24;       /**< \brief [23:0] Time base value (rw) */
    } B;
} GTM_TOM_TGC_ACT_TB;

typedef union _GTM_TOM_TGC_FUPD_CTRL {
    vuint32_t R;
    struct {
        vuint32_t RSTCN0_CH7:2;    /**< \brief [31:30] Reset CN0 of channel 7 on force update event (rw) */
        vuint32_t RSTCN0_CH6:2;    /**< \brief [29:28] Reset CN0 of channel 6 on force update event (rw) */
        vuint32_t RSTCN0_CH5:2;    /**< \brief [27:26] Reset CN0 of channel 5 on force update event (rw) */
        vuint32_t RSTCN0_CH4:2;    /**< \brief [25:24] Reset CN0 of channel 4 on force update event (rw) */
        vuint32_t RSTCN0_CH3:2;    /**< \brief [23:22] Reset CN0 of channel 3 on force update event (rw) */
        vuint32_t RSTCN0_CH2:2;    /**< \brief [21:20] Reset CN0 of channel 2 on force update event (rw) */
        vuint32_t RSTCN0_CH1:2;    /**< \brief [19:18] Reset CN0 of channel 1 on force update event (rw) */
        vuint32_t RSTCN0_CH0:2;    /**< \brief [17:16] Reset CN0 of channel 0 on force update event (rw) */
        vuint32_t FUPD_CTRL7:2;    /**< \brief [15:14] Force update of TOM channel 7 operation registers (rw) */
        vuint32_t FUPD_CTRL6:2;    /**< \brief [13:12] Force update of TOM channel 6 operation registers (rw) */
        vuint32_t FUPD_CTRL5:2;    /**< \brief [11:10] Force update of TOM channel 5 operation registers (rw) */
        vuint32_t FUPD_CTRL4:2;    /**< \brief [9:8] Force update of TOM channel 4 operation registers (rw) */
        vuint32_t FUPD_CTRL3:2;    /**< \brief [7:6] Force update of TOM channel 3 operation registers (rw) */
        vuint32_t FUPD_CTRL2:2;    /**< \brief [5:4] Force update of TOM channel 2 operation registers (rw) */
        vuint32_t FUPD_CTRL1:2;    /**< \brief [3:2] Force update of TOM channel 1 operation registers (rw) */
        vuint32_t FUPD_CTRL0:2;    /**< \brief [1:0] Force update of TOM channel 0 operation registers (rw) */
    } B;
} GTM_TOM_TGC_FUPD_CTRL;

typedef union _GTM_TOM_TGC_INT_TRIG {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t INT_TRIG7:2;     /**< \brief [15:14] Select input signal TRIG_7 as a trigger source (rw) */
        vuint32_t INT_TRIG6:2;     /**< \brief [13:12] Select input signal TRIG_6 as a trigger source (rw) */
        vuint32_t INT_TRIG5:2;     /**< \brief [11:10] Select input signal TRIG_5 as a trigger source (rw) */
        vuint32_t INT_TRIG4:2;     /**< \brief [9:8] Select input signal TRIG_4 as a trigger source (rw) */
        vuint32_t INT_TRIG3:2;     /**< \brief [7:6] Select input signal TRIG_3 as a trigger source (rw) */
        vuint32_t INT_TRIG2:2;     /**< \brief [5:4] Select input signal TRIG_2 as a trigger source (rw) */
        vuint32_t INT_TRIG1:2;     /**< \brief [3:2] Select input signal TRIG_1 as a trigger source (rw) */
        vuint32_t INT_TRIG0:2;     /**< \brief [1:0] Select input signal TRIG_0 as a trigger source (rw) */
    } B;
} GTM_TOM_TGC_INT_TRIG;

typedef union _GTM_TOM_TGC_ENDIS_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t ENDIS_CTRL7:2;    /**< \brief [15:14] TOM channel 7 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL6:2;    /**< \brief [13:12] TOM channel 6 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL5:2;    /**< \brief [11:10] TOM channel 5 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL4:2;    /**< \brief [9:8] TOM channel 4 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL3:2;    /**< \brief [7:6] TOM channel 3 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL2:2;    /**< \brief [5:4] TOM channel 2 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL1:2;    /**< \brief [3:2] TOM channel 1 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL0:2;    /**< \brief [1:0] TOM channel 0 enable/disable update value (rw) */
    } B;
} GTM_TOM_TGC_ENDIS_CTRL;

typedef union _GTM_TOM_TGC_ENDIS_STAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t ENDIS_STAT7:2;    /**< \brief [15:14] TOM channel 7 enable/disable update value (rw) */
        vuint32_t ENDIS_STAT6:2;    /**< \brief [13:12] TOM channel 6 enable/disable update value (rw) */
        vuint32_t ENDIS_STAT5:2;    /**< \brief [11:10] TOM channel 5 enable/disable update value (rw) */
        vuint32_t ENDIS_STAT4:2;    /**< \brief [9:8] TOM channel 4 enable/disable update value (rw) */
        vuint32_t ENDIS_STAT3:2;    /**< \brief [7:6] TOM channel 3 enable/disable update value (rw) */
        vuint32_t ENDIS_STAT2:2;    /**< \brief [5:4] TOM channel 2 enable/disable update value (rw) */
        vuint32_t ENDIS_STAT1:2;    /**< \brief [3:2] TOM channel 1 enable/disable update value (rw) */
        vuint32_t ENDIS_STAT0:2;    /**< \brief [1:0] TOM channel 0 enable/disable update value (rw) */
    } B;
} GTM_TOM_TGC_ENDIS_STAT;

typedef union _GTM_TOM_TGC_OUTEN_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t OUTEN_CTRL7:2;    /**< \brief [15:14] Output TOM[i]_CH7_OUT enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL6:2;    /**< \brief [13:12] Output TOM[i]_CH6_OUT enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL5:2;    /**< \brief [11:10] Output TOM[i]_CH5_OUT enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL4:2;    /**< \brief [9:8] Output TOM[i]_CH4_OUT enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL3:2;    /**< \brief [7:6] Output TOM[i]_CH3_OUT enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL2:2;    /**< \brief [5:4] Output TOM[i]_CH2_OUT enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL1:2;    /**< \brief [3:2] Output TOM[i]_CH1_OUT enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL0:2;    /**< \brief [1:0] Output TOM[i]_CH0_OUT enable/disable update value (rw) */
    } B;
} GTM_TOM_TGC_OUTEN_CTRL;

typedef union _GTM_TOM_TGC_OUTEN_STAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t OUTEN_STAT7:2;    /**< \brief [15:14] Control/status of output TOM[i]_CH7_OUT (rw) */
        vuint32_t OUTEN_STAT6:2;    /**< \brief [13:12] Control/status of output TOM[i]_CH6_OUT (rw) */
        vuint32_t OUTEN_STAT5:2;    /**< \brief [11:10] Control/status of output TOM[i]_CH5_OUT (rw) */
        vuint32_t OUTEN_STAT4:2;    /**< \brief [9:8] Control/status of output TOM[i]_CH4_OUT (rw) */
        vuint32_t OUTEN_STAT3:2;    /**< \brief [7:6] Control/status of output TOM[i]_CH3_OUT (rw) */
        vuint32_t OUTEN_STAT2:2;    /**< \brief [5:4] Control/status of output TOM[i]_CH2_OUT (rw) */
        vuint32_t OUTEN_STAT1:2;    /**< \brief [3:2] Control/status of output TOM[i]_CH1_OUT (rw) */
        vuint32_t OUTEN_STAT0:2;    /**< \brief [1:0] Control/status of output TOM[i]_CH0_OUT (rw) */
    } B;
} GTM_TOM_TGC_OUTEN_STAT;

typedef volatile struct _GTM_TOM {
       GTM_TOM_CH                      CH[16];                 /**< \brief 0, */
       vuint8_t                   reserved_400[48];       /**< \brief 400, \internal Reserved */
       GTM_TOM_TGC_GLB_CTRL            TGC0_GLB_CTRL;          /**< \brief 430, TOM${i} TGC0 Global Control Register*/
       GTM_TOM_TGC_ACT_TB              TGC0_ACT_TB;            /**< \brief 434, TOM${i} TGC0 Action Time Base Register*/
       GTM_TOM_TGC_FUPD_CTRL           TGC0_FUPD_CTRL;         /**< \brief 438, TOM${i} TGC0 Force Update Control Register*/
       GTM_TOM_TGC_INT_TRIG            TGC0_INT_TRIG;          /**< \brief 43C, TOM${i} TGC0 Internal Trigger Control Register*/
       vuint8_t                   reserved_440[48];       /**< \brief 440, \internal Reserved */
       GTM_TOM_TGC_ENDIS_CTRL          TGC0_ENDIS_CTRL;        /**< \brief 470, TOM${i} TGC0 Enable/Disable Control Register*/
       GTM_TOM_TGC_ENDIS_STAT          TGC0_ENDIS_STAT;        /**< \brief 474, TOM${i} TGC0 Enable/Disable Status Register*/
       GTM_TOM_TGC_OUTEN_CTRL          TGC0_OUTEN_CTRL;        /**< \brief 478, TOM${i} TGC0 Output Enable Control Register*/
       GTM_TOM_TGC_OUTEN_STAT          TGC0_OUTEN_STAT;        /**< \brief 47C, TOM${i} TGC0 Output Enable Status Register*/
       vuint8_t                   reserved_480[48];       /**< \brief 480, \internal Reserved */
       GTM_TOM_TGC_GLB_CTRL            TGC1_GLB_CTRL;          /**< \brief 4B0, TOM${i} TGC1 Global Control Register*/
       GTM_TOM_TGC_ACT_TB              TGC1_ACT_TB;            /**< \brief 4B4, TOM${i} TGC1 Action Time Base Register*/
       GTM_TOM_TGC_FUPD_CTRL           TGC1_FUPD_CTRL;         /**< \brief 4B8, TOM${i} TGC1 Force Update Control Register*/
       GTM_TOM_TGC_INT_TRIG            TGC1_INT_TRIG;          /**< \brief 4BC, TOM${i} TGC1 Internal Trigger Control Register*/
       vuint8_t                   reserved_4C0[48];       /**< \brief 4C0, \internal Reserved */
       GTM_TOM_TGC_ENDIS_CTRL          TGC1_ENDIS_CTRL;        /**< \brief 4F0, TOM${i} TGC1 Enable/Disable Control Register*/
       GTM_TOM_TGC_ENDIS_STAT          TGC1_ENDIS_STAT;        /**< \brief 4F4, TOM${i} TGC1 Enable/Disable Status Register*/
       GTM_TOM_TGC_OUTEN_CTRL          TGC1_OUTEN_CTRL;        /**< \brief 4F8, TOM${i} TGC1 Output Enable Control Register*/
       GTM_TOM_TGC_OUTEN_STAT          TGC1_OUTEN_STAT;        /**< \brief 4FC, TOM${i} TGC1 Output Enable Status Register*/
       vuint8_t                   reserved_500[768];      /**< \brief 500, \internal Reserved */
} GTM_TOM;

/* ============================================================================
   =============================== Module: GTM_ATOM ================================
   ============================================================================ */
typedef union _GTM_ATOM_CH_RDADDR {
    vuint32_t R;
    struct {
        vuint32_t reserved_25:7;    /**< \brief [31:25] \internal Reserved */
        vuint32_t RDADDR1:9;       /**< \brief [24:16] ARU Read address 1 (rw) */
        vuint32_t reserved_9:7;    /**< \brief [15:9] \internal Reserved */
        vuint32_t RDADDR0:9;       /**< \brief [8:0] ARU Read address 0 (rw) */
    } B;
} GTM_ATOM_CH_RDADDR;

typedef union _GTM_ATOM_CH_CTRL {
    vuint32_t R;
    struct {
        vuint32_t FREEZE:1;        /**< \brief [31:31] FREEZE (rw) */
        vuint32_t SOMB:1;          /**< \brief [30:30] SOMB mode (rw) */
        vuint32_t EXT_FUPD:1;      /**< \brief [29:29] External forced update (rw) */
        vuint32_t reserved_28:1;    /**< \brief [28:28] \internal Reserved */
        vuint32_t ABM:1;           /**< \brief [27:27] ARU blocking mode (rw) */
        vuint32_t OSM:1;           /**< \brief [26:26] One-shot mode (rw) */
        vuint32_t SLA:1;           /**< \brief [25:25] Serve last ARU communication strategy (rw) */
        vuint32_t TRIGOUT:1;       /**< \brief [24:24] Trigger output selection (output signal TRIG_CHx) of module ATOM_CHx (rw) */
        vuint32_t EXTTRIGOUT:1;    /**< \brief [23:23] Select TIM_EXT_CAPTURE(x) as potential output signal TRIG_[x] (rw) */
        vuint32_t EXT_TRIG:1;      /**< \brief [22:22] Select TIM_EXT_CAPTURE(x) as trigger signal (rw) */
        vuint32_t OSM_TRIG:1;      /**< \brief [21:21] Enable trigger of one-shot pulse by trigger signal OSM_TRIG (rw) */
        vuint32_t RST_CCU0:1;      /**< \brief [20:20] Reset source of CCU0 (rw) */
        vuint32_t UDMODE:2;        /**< \brief [19:18] Up/down counter mode (rw) */
        vuint32_t TRIG_PULSE:1;    /**< \brief [17:17] Trigger output pulse length of one SYS_CLK period (rw) */
        vuint32_t WR_REQ:1;        /**< \brief [16:16] CPU Write request bit for late compare register update (rw) */
        vuint32_t CLK_SRC_SR:4;    /**< \brief [15:12] CMU clock source (rw) */
        vuint32_t SL:1;            /**< \brief [11:11] Initial signal level (rw) */
        vuint32_t EUPM:1;          /**< \brief [10:10] Extended update mode (rw) */
        vuint32_t CMP_CTRL:1;      /**< \brief [9:9] CCUx compare strategy select (rw) */
        vuint32_t ACB:5;           /**< \brief [8:4] ATOM Mode control bits (rw) */
        vuint32_t ARU_EN:1;        /**< \brief [3:3] ARU input stream enable (rw) */
        vuint32_t TB12_SEL:1;      /**< \brief [2:2] Select time base value TBU_TS1 or TBU_TS2 (rw) */
        vuint32_t MODE:2;          /**< \brief [1:0] ATOM channel mode select (rw) */
    } B;
} GTM_ATOM_CH_CTRL;

typedef union _GTM_ATOM_CH_SOMB {
    vuint32_t R;
    struct {
        vuint32_t FREEZE:1;        /**< \brief [31:31] FREEZE (rw) */
        vuint32_t SOMB:1;          /**< \brief [30:30] SOMB: SOMB mode (rw) */
        vuint32_t reserved_29:1;    /**< \brief [29:29] \internal Reserved */
        vuint32_t reserved_28:1;    /**< \brief [28:28] \internal Reserved */
        vuint32_t ABM:1;           /**< \brief [27:27] ARU blocking mode (rw) */
        vuint32_t reserved_26:1;    /**< \brief [26:26] \internal Reserved */
        vuint32_t reserved_25:1;    /**< \brief [25:25] \internal Reserved */
        vuint32_t TRIGOUT:1;       /**< \brief [24:24] Trigger output selection (output signal TRIG_CHx) of module ATOM_CHx (rw) */
        vuint32_t EXTTRIGOUT:1;    /**< \brief [23:23] TIM_EXT_CAPTURE(x) as potential output signal TRIG_[x] (rw) */
        vuint32_t reserved_21:2;    /**< \brief [22:21] \internal Reserved */
        vuint32_t reserved_20:1;    /**< \brief [20:20] \internal Reserved */
        vuint32_t reserved_18:2;    /**< \brief [19:18] \internal Reserved */
        vuint32_t reserved_17:1;    /**< \brief [17:17] \internal Reserved */
        vuint32_t WR_REQ:1;        /**< \brief [16:16] CPU Write request bit for late compare register update (rw) */
        vuint32_t reserved_15:1;    /**< \brief [15:15] \internal Reserved */
        vuint32_t reserved_12:3;    /**< \brief [14:12] \internal Reserved */
        vuint32_t SL:1;            /**< \brief [11:11] Initial signal level after channel enable (rw) */
        vuint32_t EUPM:1;          /**< \brief [10:10] Extended update mode (rw) */
        vuint32_t CMP_CTRL:1;      /**< \brief [9:9] CCUx compare strategy select (rw) */
        vuint32_t ACB_4_3_2:3;     /**< \brief [8:6] ATOM SOMB compare strategy (rw) */
        vuint32_t ACB_1_0:2;       /**< \brief [5:4] Signal level control bits (rw) */
        vuint32_t ARU_EN:1;        /**< \brief [3:3] ARU Input stream enable (rw) */
        vuint32_t TB12_SEL:1;      /**< \brief [2:2] Select time base value TBU_TS1 or TBU_TS2 (rw) */
        vuint32_t MODE:2;          /**< \brief [1:0] ATOM channel mode select (rw) */
    } B;
} GTM_ATOM_CH_SOMB;

typedef union _GTM_ATOM_CH_SOMC {
    vuint32_t R;
    struct {
        vuint32_t FREEZE:1;        /**< \brief [31:31] FREEZE (rw) */
        vuint32_t reserved_30:1;    /**< \brief [30:30] \internal Reserved */
        vuint32_t reserved_29:1;    /**< \brief [29:29] \internal Reserved */
        vuint32_t reserved_28:1;    /**< \brief [28:28] \internal Reserved */
        vuint32_t ABM:1;           /**< \brief [27:27] ARU blocking mode (rw) */
        vuint32_t reserved_26:1;    /**< \brief [26:26] \internal Reserved */
        vuint32_t SLA:1;           /**< \brief [25:25] Serve last ARU communication strategy (rw) */
        vuint32_t TRIGOUT:1;       /**< \brief [24:24] TRIGOUT: Trigger output selection (output signal TRIG_CHx) of module ATOM_CHx (rw) */
        vuint32_t EXTTRIGOUT:1;    /**< \brief [23:23] Select TIM_EXT_CAPTURE(x) as potential output signal TRIG_[x] (rw) */
        vuint32_t reserved_21:2;    /**< \brief [22:21] \internal Reserved */
        vuint32_t reserved_20:1;    /**< \brief [20:20] \internal Reserved */
        vuint32_t reserved_18:2;    /**< \brief [19:18] \internal Reserved */
        vuint32_t reserved_17:1;    /**< \brief [17:17] \internal Reserved */
        vuint32_t WR_REQ:1;        /**< \brief [16:16] CPU write request bit (rw) */
        vuint32_t reserved_15:1;    /**< \brief [15:15] \internal Reserved */
        vuint32_t reserved_12:3;    /**< \brief [14:12] \internal Reserved */
        vuint32_t SL:1;            /**< \brief [11:11] Initial signal level after channel enable (rw) */
        vuint32_t EUPM:1;          /**< \brief [10:10] Extended Update Mode (rw) */
        vuint32_t CMP_CTRL:1;      /**< \brief [9:9] CCUx compare strategy select (rw) */
        vuint32_t ACB_4_3_2:3;     /**< \brief [8:6] ATOM control bits ACB(4), ACB(3), ACB(2) (rw) */
        vuint32_t ACB_1_0:2;       /**< \brief [5:4] Signal level control bits (rw) */
        vuint32_t ARU_EN:1;        /**< \brief [3:3] ARU Input stream enable (rw) */
        vuint32_t TB12_SEL:1;      /**< \brief [2:2] Select time base value TBU_TS1 or TBU_TS2 (rw) */
        vuint32_t MODE:2;          /**< \brief [1:0] ATOM channel mode select (rw) */
    } B;
} GTM_ATOM_CH_SOMC;

typedef union _GTM_ATOM_CH_SOMI {
    vuint32_t R;
    struct {
        vuint32_t FREEZE:1;        /**< \brief [31:31] FREEZE (rw) */
        vuint32_t reserved_30:1;    /**< \brief [30:30] \internal Reserved */
        vuint32_t reserved_29:1;    /**< \brief [29:29] \internal Reserved */
        vuint32_t reserved_28:1;    /**< \brief [28:28] \internal Reserved */
        vuint32_t reserved_27:1;    /**< \brief [27:27] \internal Reserved */
        vuint32_t reserved_26:1;    /**< \brief [26:26] \internal Reserved */
        vuint32_t reserved_25:1;    /**< \brief [25:25] \internal Reserved */
        vuint32_t reserved_24:1;    /**< \brief [24:24] \internal Reserved */
        vuint32_t reserved_21:3;    /**< \brief [23:21] \internal Reserved */
        vuint32_t reserved_20:1;    /**< \brief [20:20] \internal Reserved */
        vuint32_t reserved_18:2;    /**< \brief [19:18] \internal Reserved */
        vuint32_t reserved_17:1;    /**< \brief [17:17] \internal Reserved */
        vuint32_t reserved_16:1;    /**< \brief [16:16] \internal Reserved */
        vuint32_t reserved_15:1;    /**< \brief [15:15] \internal Reserved */
        vuint32_t reserved_12:3;    /**< \brief [14:12] \internal Reserved */
        vuint32_t SL:1;            /**< \brief [11:11] Initial signal level after channel is enabled (rw) */
        vuint32_t reserved_10:1;    /**< \brief [10:10] \internal Reserved */
        vuint32_t reserved_9:1;    /**< \brief [9:9] \internal Reserved */
        vuint32_t reserved_5:4;    /**< \brief [8:5] \internal Reserved */
        vuint32_t ACB0:1;          /**< \brief [4:4] ACB bit 0 (rw) */
        vuint32_t ARU_EN:1;        /**< \brief [3:3] ARU Input stream enable (rw) */
        vuint32_t reserved_2:1;    /**< \brief [2:2] \internal Reserved */
        vuint32_t MODE:2;          /**< \brief [1:0] ATOM channel mode select (rw) */
    } B;
} GTM_ATOM_CH_SOMI;

typedef union _GTM_ATOM_CH_SOMP {
    vuint32_t R;
    struct {
        vuint32_t FREEZE:1;        /**< \brief [31:31] FREEZE (rw) */
        vuint32_t reserved_30:1;    /**< \brief [30:30] \internal Reserved */
        vuint32_t EXT_FUPD:1;      /**< \brief [29:29] External forced update (rw) */
        vuint32_t reserved_28:1;    /**< \brief [28:28] \internal Reserved */
        vuint32_t reserved_27:1;    /**< \brief [27:27] \internal Reserved */
        vuint32_t OSM:1;           /**< \brief [26:26] One-shot mode (rw) */
        vuint32_t reserved_25:1;    /**< \brief [25:25] \internal Reserved */
        vuint32_t TRIGOUT:1;       /**< \brief [24:24] Trigger output selection (output signal TRIG_CHx) of module ATOM_CHx (rw) */
        vuint32_t EXTTRIGOUT:1;    /**< \brief [23:23] Select TIM_EXT_CAPTURE(x) as potential output signal TRIG_[x] (rw) */
        vuint32_t EXT_TRIG:1;      /**< \brief [22:22] Select TIM_EXT_CAPTURE(x) as trigger signal (rw) */
        vuint32_t OSM_TRIG:1;      /**< \brief [21:21] Enable trigger of one-shot pulse by trigger signal OSM_TRIG (rw) */
        vuint32_t RST_CCU0:1;      /**< \brief [20:20] Reset source of CCU0 (rw) */
        vuint32_t UDMODE:2;        /**< \brief [19:18] Up/down counter mode (rw) */
        vuint32_t TRIG_PULSE:1;    /**< \brief [17:17] Trigger output pulse length of one SYS_CLK period (rw) */
        vuint32_t reserved_16:1;    /**< \brief [16:16] \internal Reserved */
        vuint32_t CLK_SRC:4;        /**< \brief [15:12] CMU clock source for SOMP mode (rw) */
        vuint32_t SL:1;            /**< \brief [11:11] Signal level for pulse of PWM (rw) */
        vuint32_t reserved_10:1;    /**< \brief [10:10] \internal Reserved */
        vuint32_t reserved_9:1;    /**< \brief [9:9] \internal Reserved */
        vuint32_t reserved_8:1;    /**< \brief [8:8] \internal Reserved */
        vuint32_t SR0_TRIG:1;      /**< \brief [7:7] SR0 is used to generate a trigger on output ATOM[i]_CH[x]_OUT_T if equal to CN0 (rw) */
        vuint32_t BITREV:1;        /**< \brief [6:6] Bit-reversing of output of counter register CN0. This bit enables the PCM mode (rw) */
        vuint32_t ADL:2;           /**< \brief [5:4] ARU data select for SOMP (rw) */
        vuint32_t ARU_EN:1;        /**< \brief [3:3] ARU Input stream enable (rw) */
        vuint32_t reserved_2:1;    /**< \brief [2:2] \internal Reserved */
        vuint32_t MODE:2;          /**< \brief [1:0] ATOM channel mode select (rw) */
    } B;
} GTM_ATOM_CH_SOMP;

typedef union _GTM_ATOM_CH_SOMS {
    vuint32_t R;
    struct {
        vuint32_t FREEZE:1;        /**< \brief [31:31] FREEZE (rw) */
        vuint32_t reserved_30:1;    /**< \brief [30:30] \internal Reserved */
        vuint32_t EXT_FUPD:1;      /**< \brief [29:29] External forced update (rw) */
        vuint32_t reserved_28:1;    /**< \brief [28:28] \internal Reserved */
        vuint32_t reserved_27:1;    /**< \brief [27:27] \internal Reserved */
        vuint32_t OSM:1;           /**< \brief [26:26] One-shot mode (rw) */
        vuint32_t reserved_25:1;    /**< \brief [25:25] \internal Reserved */
        vuint32_t reserved_24:1;    /**< \brief [24:24] \internal Reserved */
        vuint32_t reserved_21:3;    /**< \brief [23:21] \internal Reserved */
        vuint32_t reserved_20:1;    /**< \brief [20:20] \internal Reserved */
        vuint32_t reserved_18:2;    /**< \brief [19:18] \internal Reserved */
        vuint32_t reserved_17:1;    /**< \brief [17:17] \internal Reserved */
        vuint32_t reserved_16:1;    /**< \brief [16:16] \internal Reserved */
        vuint32_t CLK_SRC_SR:4;    /**< \brief [15:12] CMU clock source for SOMS mode (rw) */
        vuint32_t SL:1;            /**< \brief [11:11] Defines signal level when channel and output is disabling (rw) */
        vuint32_t reserved_10:1;    /**< \brief [10:10] \internal Reserved */
        vuint32_t reserved_9:1;    /**< \brief [9:9] \internal Reserved */
        vuint32_t reserved_8:1;    /**< \brief [8:8] \internal Reserved */
        vuint32_t DSO:1;           /**< \brief [7:7] Double Shift Output (rw) */
        vuint32_t reserved_5:2;    /**< \brief [6:5] \internal Reserved */
        vuint32_t ACB0:1;          /**< \brief [4:4] Shift direction for CM1 register (rw) */
        vuint32_t ARU_EN:1;        /**< \brief [3:3] ARU Input stream enable (rw) */
        vuint32_t reserved_2:1;    /**< \brief [2:2] \internal Reserved */
        vuint32_t MODE:2;          /**< \brief [1:0] ATOM channel mode select (rw) */
    } B;
} GTM_ATOM_CH_SOMS;

typedef union _GTM_ATOM_CH_SR0 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t SR0:24;          /**< \brief [23:0] ATOM channel x shadow register SR0 (rw) */
    } B;
} GTM_ATOM_CH_SR0;

typedef union _GTM_ATOM_CH_SR1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t SR1:24;          /**< \brief [23:0] ATOM channel x shadow register SR1 (rw) */
    } B;
} GTM_ATOM_CH_SR1;

typedef union _GTM_ATOM_CH_CM0 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CM0:24;          /**< \brief [23:0] ATOM CCU0 compare register (rw) */
    } B;
} GTM_ATOM_CH_CM0;

typedef union _GTM_ATOM_CH_CM1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CM1:24;          /**< \brief [23:0] ATOM CCU1 compare register (rw) */
    } B;
} GTM_ATOM_CH_CM1;

typedef union _GTM_ATOM_CH_CN0 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CN0:24;          /**< \brief [23:0] ATOM CCU0 counter register (rw) */
    } B;
} GTM_ATOM_CH_CN0;

typedef union _GTM_ATOM_CH_STAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_30:2;    /**< \brief [31:30] \internal Reserved */
        vuint32_t OSM_RTF:1;       /**< \brief [29:29] One鈭抯hot mode retrigger failed flag (rw) */
        vuint32_t ACBO:5;          /**< \brief [28:24] ATOM Internal status bits (r) */
        vuint32_t DR:1;            /**< \brief [23:23] ARU data rejected flag (r) */
        vuint32_t WRF:1;           /**< \brief [22:22] Write request of CPU failed for late update (rw) */
        vuint32_t DV:1;            /**< \brief [21:21] Valid ARU Data stored in compare registers (r) */
        vuint32_t ACBI:5;          /**< \brief [20:16] ATOM Mode control bits (r) */
        vuint32_t reserved_1:15;    /**< \brief [15:1] \internal Reserved */
        vuint32_t OL:1;            /**< \brief [0:0] Actual output signal level of ATOM_CHx_OUT (r) */
    } B;
} GTM_ATOM_CH_STAT;

typedef union _GTM_ATOM_CH_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t CCU1TC:1;        /**< \brief [1:1] CCU1TC: CCU1 Trigger condition interrupt for channel x (rw) */
        vuint32_t CCU0TC:1;        /**< \brief [0:0] CCU0 Trigger condition interrupt for channel x (rw) */
    } B;
} GTM_ATOM_CH_IRQ_NOTIFY;

typedef union _GTM_ATOM_CH_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t CCU1TC_IRQ_EN:1;    /**< \brief [1:1] ATOM_CCU1TC_IRQ interrupt enable (rw) */
        vuint32_t CCU0TC_IRQ_EN:1;    /**< \brief [0:0] ATOM_CCU0TC_IRQ interrupt enable (rw) */
    } B;
} GTM_ATOM_CH_IRQ_EN;

typedef union _GTM_ATOM_CH_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t TRG_CCU1TC:1;    /**< \brief [1:1] Trigger ATOM_CCU1TC_IRQ interrupt by software (rw) */
        vuint32_t TRG_CCU0TC:1;    /**< \brief [0:0] Trigger ATOM_CCU0TC_IRQ interrupt by software (rw) */
    } B;
} GTM_ATOM_CH_IRQ_FORCINT;

typedef union _GTM_ATOM_CH_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;      /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_ATOM_CH_IRQ_MODE;

typedef union _GTM_ATOM_CH_CTRL2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;   /**< \brief [31:1] \internal Reserved */
        vuint32_t HRES:1;          /**< \brief [0:0]  ATOM high resolution support (rw) */
    } B;
} GTM_ATOM_CH_CTRL2;

typedef union _GTM_ATOM_CH_CTRL_SR {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;   /**< \brief [31:16] \internal Reserved */
        vuint32_t CLK_SRC_SR:4;     /**< \brief [15:12] Shadow register for ATOM[i]_CH[x]_CTRL.CLK_SRC (rw) */
        vuint32_t SL_SR:1;          /**< \brief [11:11] Shadow register for ATOM[i]_CH[x]_CTRL.SL (rw) */
        vuint32_t reserved_0:11;    /**< \brief [10:0] \internal Reserved */
    } B;
} GTM_ATOM_CH_CTRL_SR;

typedef volatile struct _GTM_ATOM_CH {
       GTM_ATOM_CH_RDADDR              RDADDR;                 /**< \brief 0, ATOM${i} Channel ${x} ARU read address Register*/
       union
       {
            GTM_ATOM_CH_CTRL                CTRL;                   /**< \brief 4, */
            GTM_ATOM_CH_SOMB                SOMB;                   /**< \brief 4, */
            GTM_ATOM_CH_SOMC                SOMC;                   /**< \brief 4, */
            GTM_ATOM_CH_SOMI                SOMI;                   /**< \brief 4, */
            GTM_ATOM_CH_SOMP                SOMP;                   /**< \brief 4, */
            GTM_ATOM_CH_SOMS                SOMS;                   /**< \brief 4, */
       };
       GTM_ATOM_CH_SR0                 SR0;                    /**< \brief 8, ATOM${i} Channel ${x} CCU0 Compare Shadow Register*/
       GTM_ATOM_CH_SR1                 SR1;                    /**< \brief C, ATOM${i} Channel ${x} CCU1 Compare Shadow Register*/
       GTM_ATOM_CH_CM0                 CM0;                    /**< \brief 10, ATOM${i} Channel ${x} CCU0 Compare Register*/
       GTM_ATOM_CH_CM1                 CM1;                    /**< \brief 14, ATOM${i} Channel ${x} CCU1 Compare Register*/
       GTM_ATOM_CH_CN0                 CN0;                    /**< \brief 18, ATOM${i} Channel ${x} CCU0 Counter Register*/
       GTM_ATOM_CH_STAT                STAT;                   /**< \brief 1C, ATOM${i} Channel ${x} Status Register*/
       GTM_ATOM_CH_IRQ_NOTIFY          IRQ_NOTIFY;             /**< \brief 20, ATOM${i} Channel ${x} Interrupt Notification Register*/
       GTM_ATOM_CH_IRQ_EN              IRQ_EN;                 /**< \brief 24, ATOM${i} Channel ${x} Interrupt Enable Register*/
       GTM_ATOM_CH_IRQ_FORCINT         IRQ_FORCINT;            /**< \brief 28, ATOM${i} Channel ${x} Software Interrupt Generation Register*/
       GTM_ATOM_CH_IRQ_MODE            IRQ_MODE;               /**< \brief 2C, ATOM${i} Channel ${x} Interrupt Mode Configuration Register*/
       GTM_ATOM_CH_CTRL2               CTRL2;                  /**< \brief 30, ATOM${i} Channel ${x} control2 Register*/
       GTM_ATOM_CH_CTRL_SR             CTRL_SR;                /**< \brief 34, ATOM${i} Channel ${x} control shadow Register*/
       vuint8_t                   reserved_38[72];        /**< \brief 38, \internal Reserved */
} GTM_ATOM_CH;

typedef union _GTM_ATOM_AGC_GLB_CTRL {
    vuint32_t R;
    struct {
        vuint32_t UPEN_CTRL7:2;    /**< \brief [31:30] ATOM channel 7 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL6:2;    /**< \brief [29:28] ATOM channel 6 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL5:2;    /**< \brief [27:26] ATOM channel 5 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL4:2;    /**< \brief [25:24] ATOM channel 4 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL3:2;    /**< \brief [23:22] ATOM channel 3 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL2:2;    /**< \brief [21:20] ATOM channel 2 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL1:2;    /**< \brief [19:18] ATOM channel 1 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t UPEN_CTRL0:2;    /**< \brief [17:16] ATOM channel 0 enable update of register CM0, CM1 and CLK_SRC from SR0, SR1 and CLK_SRC_SR (rw) */
        vuint32_t RST_CH7:1;       /**< \brief [15:15] Software reset of channel 7 (w) */
        vuint32_t RST_CH6:1;       /**< \brief [14:14] Software reset of channel 6 (w) */
        vuint32_t RST_CH5:1;       /**< \brief [13:13] Software reset of channel 5 (w) */
        vuint32_t RST_CH4:1;       /**< \brief [12:12] Software reset of channel 4 (w) */
        vuint32_t RST_CH3:1;       /**< \brief [11:11] Software reset of channel 3 (w) */
        vuint32_t RST_CH2:1;       /**< \brief [10:10] Software reset of channel 2 (w) */
        vuint32_t RST_CH1:1;       /**< \brief [9:9] Software reset of channel 1 (w) */
        vuint32_t RST_CH0:1;       /**< \brief [8:8] Software reset of channel 0 (w) */
        vuint32_t reserved_1:7;    /**< \brief [7:1] \internal Reserved */
        vuint32_t HOST_TRIG:1;     /**< \brief [0:0] Trigger request signal (see AGC) to update the register ENDIS_STAT and OUTEN_STAT (w) */
    } B;
} GTM_ATOM_AGC_GLB_CTRL;

typedef union _GTM_ATOM_AGC_ENDIS_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t ENDIS_CTRL7:2;    /**< \brief [15:14] ATOM channel 7 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL6:2;    /**< \brief [13:12] ATOM channel 6 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL5:2;    /**< \brief [11:10] ATOM channel 5 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL4:2;    /**< \brief [9:8] ATOM channel 4 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL3:2;    /**< \brief [7:6] ATOM channel 3 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL2:2;    /**< \brief [5:4] ATOM channel 2 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL1:2;    /**< \brief [3:2] ATOM channel 1 enable/disable update value (rw) */
        vuint32_t ENDIS_CTRL0:2;    /**< \brief [1:0] ATOM channel 0 enable/disable update value (rw) */
    } B;
} GTM_ATOM_AGC_ENDIS_CTRL;

typedef union _GTM_ATOM_AGC_ENDIS_STAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t ENDIS_STAT7:2;    /**< \brief [15:14] ATOM channel 7 enable/disable (rw) */
        vuint32_t ENDIS_STAT6:2;    /**< \brief [13:12] ATOM channel 6 enable/disable (rw) */
        vuint32_t ENDIS_STAT5:2;    /**< \brief [11:10] ATOM channel 5 enable/disable (rw) */
        vuint32_t ENDIS_STAT4:2;    /**< \brief [9:8] ATOM channel 4 enable/disable (rw) */
        vuint32_t ENDIS_STAT3:2;    /**< \brief [7:6] ATOM channel 3 enable/disable (rw) */
        vuint32_t ENDIS_STAT2:2;    /**< \brief [5:4] ATOM channel 2 enable/disable (rw) */
        vuint32_t ENDIS_STAT1:2;    /**< \brief [3:2] ATOM channel 1 enable/disable (rw) */
        vuint32_t ENDIS_STAT0:2;    /**< \brief [1:0] ATOM channel 0 enable/disable (rw) */
    } B;
} GTM_ATOM_AGC_ENDIS_STAT;

typedef union _GTM_ATOM_AGC_ACT_TB {
    vuint32_t R;
    struct {
        vuint32_t reserved_27:5;    /**< \brief [31:27] \internal Reserved */
        vuint32_t TBU_SEL:2;       /**< \brief [26:25] Selection of time base used for comparison (rw) */
        vuint32_t TB_TRIG:1;       /**< \brief [24:24] Set trigger request (rw) */
        vuint32_t ACT_TB:24;       /**< \brief [23:0] Time base value (rw) */
    } B;
} GTM_ATOM_AGC_ACT_TB;

typedef union _GTM_ATOM_AGC_OUTEN_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t OUTEN_CTRL7:2;    /**< \brief [15:14] Output ATOM_OUT7 enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL6:2;    /**< \brief [13:12] Output ATOM_OUT6 enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL5:2;    /**< \brief [11:10] Output ATOM_OUT5 enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL4:2;    /**< \brief [9:8] Output ATOM_OUT4 enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL3:2;    /**< \brief [7:6] Output ATOM_OUT3 enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL2:2;    /**< \brief [5:4] Output ATOM_OUT2 enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL1:2;    /**< \brief [3:2] Output ATOM_OUT1 enable/disable update value (rw) */
        vuint32_t OUTEN_CTRL0:2;    /**< \brief [1:0] Output ATOM_OUT0 enable/disable update value (rw) */
    } B;
} GTM_ATOM_AGC_OUTEN_CTRL;

typedef union _GTM_ATOM_AGC_OUTEN_STAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t OUTEN_STAT7:2;    /**< \brief [15:14] Control/status of output ATOM_OUT7 (rw) */
        vuint32_t OUTEN_STAT6:2;    /**< \brief [13:12] Control/status of output ATOM_OUT6 (rw) */
        vuint32_t OUTEN_STAT5:2;    /**< \brief [11:10] Control/status of output ATOM_OUT5 (rw) */
        vuint32_t OUTEN_STAT4:2;    /**< \brief [9:8] Control/status of output ATOM_OUT4 (rw) */
        vuint32_t OUTEN_STAT3:2;    /**< \brief [7:6] Control/status of output ATOM_OUT3 (rw) */
        vuint32_t OUTEN_STAT2:2;    /**< \brief [5:4] Control/status of output ATOM_OUT2 (rw) */
        vuint32_t OUTEN_STAT1:2;    /**< \brief [3:2] Control/status of output ATOM_OUT1 (rw) */
        vuint32_t OUTEN_STAT0:2;    /**< \brief [1:0] Control/status of output ATOM_OUT0 (rw) */
    } B;
} GTM_ATOM_AGC_OUTEN_STAT;

typedef union _GTM_ATOM_AGC_FUPD_CTRL {
    vuint32_t R;
    struct {
        vuint32_t RSTCN0_CH7:2;    /**< \brief [31:30] Reset CN0 of channel 7 on force update event (rw) */
        vuint32_t RSTCN0_CH6:2;    /**< \brief [29:28] Reset CN0 of channel 6 on force update event (rw) */
        vuint32_t RSTCN0_CH5:2;    /**< \brief [27:26] Reset CN0 of channel 5 on force update event (rw) */
        vuint32_t RSTCN0_CH4:2;    /**< \brief [25:24] Reset CN0 of channel 4 on force update event (rw) */
        vuint32_t RSTCN0_CH3:2;    /**< \brief [23:22] Reset CN0 of channel 3 on force update event (rw) */
        vuint32_t RSTCN0_CH2:2;    /**< \brief [21:20] Reset CN0 of channel 2 on force update event (rw) */
        vuint32_t RSTCN0_CH1:2;    /**< \brief [19:18] Reset CN0 of channel 1 on force update event (rw) */
        vuint32_t RSTCN0_CH0:2;    /**< \brief [17:16] Reset CN0 of channel 0 on force update event (rw) */
        vuint32_t FUPD_CTRL7:2;    /**< \brief [15:14] Force update of ATOM channel 7 operation registers (rw) */
        vuint32_t FUPD_CTRL6:2;    /**< \brief [13:12] Force update of ATOM channel 6 operation registers (rw) */
        vuint32_t FUPD_CTRL5:2;    /**< \brief [11:10] Force update of ATOM channel 5 operation registers (rw) */
        vuint32_t FUPD_CTRL4:2;    /**< \brief [9:8] Force update of ATOM channel 4 operation registers (rw) */
        vuint32_t FUPD_CTRL3:2;    /**< \brief [7:6] Force update of ATOM channel 3 operation registers (rw) */
        vuint32_t FUPD_CTRL2:2;    /**< \brief [5:4] Force update of ATOM channel 2 operation registers (rw) */
        vuint32_t FUPD_CTRL1:2;    /**< \brief [3:2] Force update of ATOM channel 1 operation registers (rw) */
        vuint32_t FUPD_CTRL0:2;    /**< \brief [1:0] Force update of ATOM channel 0 operation registers (rw) */
    } B;
} GTM_ATOM_AGC_FUPD_CTRL;

typedef union _GTM_ATOM_AGC_INT_TRIG {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t INT_TRIG7:2;     /**< \brief [15:14] Select input signal TRIG_7 as a trigger source (rw) */
        vuint32_t INT_TRIG6:2;     /**< \brief [13:12] Select input signal TRIG_6 as a trigger source (rw) */
        vuint32_t INT_TRIG5:2;     /**< \brief [11:10] Select input signal TRIG_5 as a trigger source (rw) */
        vuint32_t INT_TRIG4:2;     /**< \brief [9:8] Select input signal TRIG_4 as a trigger source (rw) */
        vuint32_t INT_TRIG3:2;     /**< \brief [7:6] Select input signal TRIG_3 as a trigger source (rw) */
        vuint32_t INT_TRIG2:2;     /**< \brief [5:4] Select input signal TRIG_2 as a trigger source (rw) */
        vuint32_t INT_TRIG1:2;     /**< \brief [3:2] Select input signal TRIG_1 as a trigger source (rw) */
        vuint32_t INT_TRIG0:2;     /**< \brief [1:0] Select input signal TRIG_0 as a trigger source (rw) */
    } B;
} GTM_ATOM_AGC_INT_TRIG;

typedef volatile struct _GTM_ATOM_AGC {
       GTM_ATOM_AGC_GLB_CTRL           GLB_CTRL;               /**< \brief 0, ATOM${i} AGC Global Control Register*/
       GTM_ATOM_AGC_ENDIS_CTRL         ENDIS_CTRL;             /**< \brief 4, ATOM${i} AGC Enable/Disable Control Register*/
       GTM_ATOM_AGC_ENDIS_STAT         ENDIS_STAT;             /**< \brief 8, ATOM${i} AGC Enable/Disable Status Register*/
       GTM_ATOM_AGC_ACT_TB             ACT_TB;                 /**< \brief C, ATOM${i} AGC Action Time Base Register*/
       GTM_ATOM_AGC_OUTEN_CTRL         OUTEN_CTRL;             /**< \brief 10, ATOM${i} AGC Output Enable Control Register*/
       GTM_ATOM_AGC_OUTEN_STAT         OUTEN_STAT;             /**< \brief 14, ATOM${i} AGC Output Enable Status Register*/
       GTM_ATOM_AGC_FUPD_CTRL          FUPD_CTRL;              /**< \brief 18, ATOM${i} AGC Force Update Control Register*/
       GTM_ATOM_AGC_INT_TRIG           INT_TRIG;               /**< \brief 1C, ATOM${i} AGC Internal Trigger Control Register*/
       vuint8_t                   reserved_20[32];        /**< \brief 20, \internal Reserved */
} GTM_ATOM_AGC;

typedef volatile struct _GTM_ATOM {
       GTM_ATOM_CH                     CH[8];                   /**< \brief 0, */
       vuint8_t                   reserved_400[64];        /**< \brief 400, \internal Reserved */
       GTM_ATOM_AGC                    AGC;                     /**< \brief 440, */
       vuint8_t                   reserved_480[896];       /**< \brief 480, \internal Reserved */
} GTM_ATOM;

/* ============================================================================
   =============================== Module: GTM_MCS ================================
   ============================================================================ */
typedef union _GTM_MCS_CH_R {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DATA:24;         /**< \brief [23:0] Data of general purpose register R[y] (rw) */
    } B;
} GTM_MCS_CH_R;

typedef union _GTM_MCS_CH_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_19:13;    /**< \brief [31:19] \internal Reserved */
        vuint32_t SP_CNT:3;        /**< \brief [18:16] Stack pointer counter value (r) */
        vuint32_t reserved_11:5;    /**< \brief [15:11] \internal Reserved */
        vuint32_t SAT:1;           /**< \brief [10:10] Successful ARU transfer bit (r) */
        vuint32_t CWT:1;           /**< \brief [9:9] Cancel WURM instruction state (r) */
        vuint32_t CAT:1;           /**< \brief [8:8] Cancel ARU transfer state (r) */
        vuint32_t N:1;             /**< \brief [7:7] Negative bit state (r) */
        vuint32_t V:1;             /**< \brief [6:6] Overflow bit state (r) */
        vuint32_t Z:1;             /**< \brief [5:5] Zero bit state (r) */
        vuint32_t CY:1;            /**< \brief [4:4] Carry bit state (r) */
        vuint32_t reserved_3:1;    /**< \brief [3:3] \internal Reserved */
        vuint32_t ERR:1;           /**< \brief [2:2] Error state (r) */
        vuint32_t IRQ:1;           /**< \brief [1:1] Interrupt state (r) */
        vuint32_t EN:1;            /**< \brief [0:0] Enable MCS-channel (rw) */
    } B;
} GTM_MCS_CH_CTRL;

typedef union _GTM_MCS_CH_ACB {
    vuint32_t R;
    struct {
        vuint32_t reserved_5:27;    /**< \brief [31:5] \internal Reserved */
        vuint32_t ACB4:1;          /**< \brief [4:4] ARU Control bit 4 (r) */
        vuint32_t ACB3:1;          /**< \brief [3:3] ARU Control bit 3 (r) */
        vuint32_t ACB2:1;          /**< \brief [2:2] ARU Control bit 2 (r) */
        vuint32_t ACB1:1;          /**< \brief [1:1] ARU Control bit 1 (r) */
        vuint32_t ACB0:1;          /**< \brief [0:0] ARU Control bit 0 (r) */
    } B;
} GTM_MCS_CH_ACB;

typedef union _GTM_MCS_CH_MHB {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t DATA:8;          /**< \brief [7:0] Data of memory high bit register MHB (r) */
    } B;
} GTM_MCS_CH_MHB;

typedef union _GTM_MCS_CH_PC {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t PC:16;           /**< \brief [15:0] Current Program Counter (rw) */
    } B;
} GTM_MCS_CH_PC;

typedef union _GTM_MCS_CH_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_3:29;    /**< \brief [31:3] \internal Reserved */
        vuint32_t ERR_IRQ:1;       /**< \brief [2:2] MCS channel x ERR interrupt (rw) */
        vuint32_t reserved_1:1;    /**< \brief [1:1] \internal Reserved */
        vuint32_t MCS_IRQ:1;       /**< \brief [0:0] Interrupt request by MCS-channel x (rw) */
    } B;
} GTM_MCS_CH_IRQ_NOTIFY;

typedef union _GTM_MCS_CH_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_3:29;    /**< \brief [31:3] \internal Reserved */
        vuint32_t ERR_IRQ_EN:1;    /**< \brief [2:2] MCS channel x ERR_IRQ interrupt enable (rw) */
        vuint32_t reserved_1:1;    /**< \brief [1:1] \internal Reserved */
        vuint32_t MCS_IRQ_EN:1;    /**< \brief [0:0] MCS channel x MCS_IRQ interrupt enable (rw) */
    } B;
} GTM_MCS_CH_IRQ_EN;

typedef union _GTM_MCS_CH_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_3:29;    /**< \brief [31:3] \internal Reserved */
        vuint32_t TRG_ERR_IRQ:1;    /**< \brief [2:2] Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software (rw) */
        vuint32_t reserved_1:1;     /**< \brief [1:1] \internal Reserved */
        vuint32_t TRG_MCS_IRQ:1;    /**< \brief [0:0] Trigger IRQ bit in MCS_CH_[x]_IRQ_NOTIFY register by software (rw) */
    } B;
} GTM_MCS_CH_IRQ_FORCINT;

typedef union _GTM_MCS_CH_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;      /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_MCS_CH_IRQ_MODE;

typedef union _GTM_MCS_CH_EIRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_3:29;    /**< \brief [31:3] \internal Reserved */
        vuint32_t ERR_EIRQ_EN:1;    /**< \brief [2:2] MCS channel x ERR_EIRQ error interrupt enable (rw) */
        vuint32_t reserved_1:1;      /**< \brief [1:1] \internal Reserved */
        vuint32_t MCS_EIRQ_EN0:1;    /**< \brief [0:0] MCS channel x MCS_EIRQ error interrupt enable (rw) */
    } B;
} GTM_MCS_CH_EIRQ_EN;

typedef volatile struct _GTM_MCS_CH {
       GTM_MCS_CH_R                    R[8];                   /**< \brief 0, MCS${i} Channel ${x} General Purpose Register ${y}*/
       GTM_MCS_CH_CTRL                 CTRL;                   /**< \brief 20, MCS${i} Channel ${x} Control Register*/
       GTM_MCS_CH_ACB                  ACB;                    /**< \brief 24, MCS${i} Channel ${x} ARU Control Bit Register*/
       vuint8_t                   reserved_28[20];        /**< \brief 28, \internal Reserved */
       GTM_MCS_CH_MHB                  MHB;                    /**< \brief 3C, MCS${i} Channel ${x} Memory High Byte Register*/
       vuint8_t                   reserved_40[160];       /**< \brief 40, \internal Reserved */
       GTM_MCS_CH_PC                   PC;                     /**< \brief E0, MCS${i} Channel ${x} Program Counter Register*/
       GTM_MCS_CH_IRQ_NOTIFY           IRQ_NOTIFY;             /**< \brief E4, MCS${i} Channel ${x} Interrupt Notification Register*/
       GTM_MCS_CH_IRQ_EN               IRQ_EN;                 /**< \brief E8, MCS${i} Channel ${x} Interrupt Enable Register*/
       GTM_MCS_CH_IRQ_FORCINT          IRQ_FORCINT;            /**< \brief EC, MCS${i} Channel ${x} Force Interrupt Register*/
       GTM_MCS_CH_IRQ_MODE             IRQ_MODE;               /**< \brief F0, MCS${i} Channel ${x} Interrupt Mode Configuration Register*/
       GTM_MCS_CH_EIRQ_EN              EIRQ_EN;                /**< \brief F4, MCS${i} Channel ${x} Error Interrupt Enable Register*/
       vuint8_t                   reserved_F8[8];         /**< \brief F8, \internal Reserved */
} GTM_MCS_CH;

typedef union _GTM_MCS_CH_CTRG {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TRG23:1;         /**< \brief [23:23] Trigger bit 23 (rw) */
        vuint32_t TRG22:1;         /**< \brief [22:22] Trigger bit 22 (rw) */
        vuint32_t TRG21:1;         /**< \brief [21:21] Trigger bit 21 (rw) */
        vuint32_t TRG20:1;         /**< \brief [20:20] Trigger bit 20 (rw) */
        vuint32_t TRG19:1;         /**< \brief [19:19] Trigger bit 19 (rw) */
        vuint32_t TRG18:1;         /**< \brief [18:18] Trigger bit 18 (rw) */
        vuint32_t TRG17:1;         /**< \brief [17:17] Trigger bit 17 (rw) */
        vuint32_t TRG16:1;         /**< \brief [16:16] Trigger bit 16 (rw) */
        vuint32_t TRG15:1;         /**< \brief [15:15] Trigger bit 15 (rw) */
        vuint32_t TRG14:1;         /**< \brief [14:14] Trigger bit 14 (rw) */
        vuint32_t TRG13:1;         /**< \brief [13:13] Trigger bit 13 (rw) */
        vuint32_t TRG12:1;         /**< \brief [12:12] Trigger bit 12 (rw) */
        vuint32_t TRG11:1;         /**< \brief [11:11] Trigger bit 11 (rw) */
        vuint32_t TRG10:1;         /**< \brief [10:10] Trigger bit 10 (rw) */
        vuint32_t TRG9:1;          /**< \brief [9:9] Trigger bit 9 (rw) */
        vuint32_t TRG8:1;          /**< \brief [8:8] Trigger bit 8 (rw) */
        vuint32_t TRG7:1;          /**< \brief [7:7] Trigger bit 7 (rw) */
        vuint32_t TRG6:1;          /**< \brief [6:6] Trigger bit 6 (rw) */
        vuint32_t TRG5:1;          /**< \brief [5:5] Trigger bit 5 (rw) */
        vuint32_t TRG4:1;          /**< \brief [4:4] Trigger bit 4 (rw) */
        vuint32_t TRG3:1;          /**< \brief [3:3] Trigger bit 3 (rw) */
        vuint32_t TRG2:1;          /**< \brief [2:2] Trigger bit 2 (rw) */
        vuint32_t TRG1:1;          /**< \brief [1:1] Trigger bit 1 (rw) */
        vuint32_t TRG0:1;          /**< \brief [0:0] Trigger bit 0 (rw) */
    } B;
} GTM_MCS_CH_CTRG;

typedef union _GTM_MCS_CH_STRG {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TRG23:1;         /**< \brief [23:23] Trigger bit 23 (rw) */
        vuint32_t TRG22:1;         /**< \brief [22:22] Trigger bit 22 (rw) */
        vuint32_t TRG21:1;         /**< \brief [21:21] Trigger bit 21 (rw) */
        vuint32_t TRG20:1;         /**< \brief [20:20] Trigger bit 20 (rw) */
        vuint32_t TRG19:1;         /**< \brief [19:19] Trigger bit 19 (rw) */
        vuint32_t TRG18:1;         /**< \brief [18:18] Trigger bit 18 (rw) */
        vuint32_t TRG17:1;         /**< \brief [17:17] Trigger bit 17 (rw) */
        vuint32_t TRG16:1;         /**< \brief [16:16] Trigger bit 16 (rw) */
        vuint32_t TRG15:1;         /**< \brief [15:15] Trigger bit 15 (rw) */
        vuint32_t TRG14:1;         /**< \brief [14:14] Trigger bit 14 (rw) */
        vuint32_t TRG13:1;         /**< \brief [13:13] Trigger bit 13 (rw) */
        vuint32_t TRG12:1;         /**< \brief [12:12] Trigger bit 12 (rw) */
        vuint32_t TRG11:1;         /**< \brief [11:11] Trigger bit 11 (rw) */
        vuint32_t TRG10:1;         /**< \brief [10:10] Trigger bit 10 (rw) */
        vuint32_t TRG9:1;          /**< \brief [9:9] Trigger bit 9 (rw) */
        vuint32_t TRG8:1;          /**< \brief [8:8] Trigger bit 8 (rw) */
        vuint32_t TRG7:1;          /**< \brief [7:7] Trigger bit 7 (rw) */
        vuint32_t TRG6:1;          /**< \brief [6:6] Trigger bit 6 (rw) */
        vuint32_t TRG5:1;          /**< \brief [5:5] Trigger bit 5 (rw) */
        vuint32_t TRG4:1;          /**< \brief [4:4] Trigger bit 4 (rw) */
        vuint32_t TRG3:1;          /**< \brief [3:3] Trigger bit 3 (rw) */
        vuint32_t TRG2:1;          /**< \brief [2:2] Trigger bit 2 (rw) */
        vuint32_t TRG1:1;          /**< \brief [1:1] Trigger bit 1 (rw) */
        vuint32_t TRG0:1;          /**< \brief [0:0] Trigger bit 0 (rw) */
    } B;
} GTM_MCS_CH_STRG;

typedef union _GTM_MCS_CTRL_STAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_27:5;    /**< \brief [31:27] \internal Reserved */
        vuint32_t HLT_AEIM_ERR:1;    /**< \brief [26:26] Halt on AEI bus master error (rw) */
        vuint32_t EN_HVD:1;          /**< \brief [25:25] Enable Modified Harvard architecture (rw) */
        vuint32_t EN_TIM_FOUT:1;    /**< \brief [24:24] Enable routing of TIM[i]_CH[x]_F_OUT signal (rw) */
        vuint32_t reserved_23:1;    /**< \brief [23:23] \internal Reserved */
        vuint32_t ERR_SRC_ID:3;    /**< \brief [22:20] Error source identifier (r) */
        vuint32_t reserved_18:2;    /**< \brief [19:18] \internal Reserved */
        vuint32_t HLT_SP_OFL:1;    /**< \brief [17:17] Halt on stack pointer overflow (rw) */
        vuint32_t RAM_RST:1;       /**< \brief [16:16] RAM reset bit (rw) */
        vuint32_t reserved_12:4;    /**< \brief [15:12] \internal Reserved */
        vuint32_t SCD_CH:4;        /**< \brief [11:8] Channel selection for scheduling algorithm (rw) */
        vuint32_t reserved_2:6;    /**< \brief [7:2] \internal Reserved */
        vuint32_t SCD_MODE:2;      /**< \brief [1:0] Select MCS scheduling mode (rw) */
    } B;
} GTM_MCS_CTRL_STAT;

typedef union _GTM_MCS_RESET {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t RST7:1;          /**< \brief [7:7] Software reset of channel 7 (rw) */
        vuint32_t RST6:1;          /**< \brief [6:6] Software reset of channel 6 (rw) */
        vuint32_t RST5:1;          /**< \brief [5:5] Software reset of channel 5 (rw) */
        vuint32_t RST4:1;          /**< \brief [4:4] Software reset of channel 4 (rw) */
        vuint32_t RST3:1;          /**< \brief [3:3] Software reset of channel 3 (rw) */
        vuint32_t RST2:1;          /**< \brief [2:2] Software reset of channel 2 (rw) */
        vuint32_t RST1:1;          /**< \brief [1:1] Software reset of channel 1 (rw) */
        vuint32_t RST0:1;          /**< \brief [0:0] Software reset of channel 0 (rw) */
    } B;
} GTM_MCS_RESET;

typedef union _GTM_MCS_CAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t CAT7:1;          /**< \brief [7:7] Cancel ARU transfer for channel 7 (rw) */
        vuint32_t CAT6:1;          /**< \brief [6:6] Cancel ARU transfer for channel 6 (rw) */
        vuint32_t CAT5:1;          /**< \brief [5:5] Cancel ARU transfer for channel 5 (rw) */
        vuint32_t CAT4:1;          /**< \brief [4:4] Cancel ARU transfer for channel 4 (rw) */
        vuint32_t CAT3:1;          /**< \brief [3:3] Cancel ARU transfer for channel 3 (rw) */
        vuint32_t CAT2:1;          /**< \brief [2:2] Cancel ARU transfer for channel 2 (rw) */
        vuint32_t CAT1:1;          /**< \brief [1:1] Cancel ARU transfer for channel 1 (rw) */
        vuint32_t CAT0:1;          /**< \brief [0:0] Cancel ARU transfer for channel 0 (rw) */
    } B;
} GTM_MCS_CAT;

typedef union _GTM_MCS_CWT {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t CWT7:1;          /**< \brief [7:7] Cancel WURM instruction for channel 7 (rw) */
        vuint32_t CWT6:1;          /**< \brief [6:6] Cancel WURM instruction for channel 6 (rw) */
        vuint32_t CWT5:1;          /**< \brief [5:5] Cancel WURM instruction for channel 5 (rw) */
        vuint32_t CWT4:1;          /**< \brief [4:4] Cancel WURM instruction for channel 4 (rw) */
        vuint32_t CWT3:1;          /**< \brief [3:3] Cancel WURM instruction for channel 3 (rw) */
        vuint32_t CWT2:1;          /**< \brief [2:2] Cancel WURM instruction for channel 2 (rw) */
        vuint32_t CWT1:1;          /**< \brief [1:1] Cancel WURM instruction for channel 1 (rw) */
        vuint32_t CWT0:1;          /**< \brief [0:0] Cancel WURM instruction for channel 0 (rw) */
    } B;
} GTM_MCS_CWT;

typedef union _GTM_MCS_ERR {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t ERR7:1;          /**< \brief [7:7] Error State of MCS-channel 7 (rw) */
        vuint32_t ERR6:1;          /**< \brief [6:6] Error State of MCS-channel 6 (rw) */
        vuint32_t ERR5:1;          /**< \brief [5:5] Error State of MCS-channel 5 (rw) */
        vuint32_t ERR4:1;          /**< \brief [4:4] Error State of MCS-channel 4 (rw) */
        vuint32_t ERR3:1;          /**< \brief [3:3] Error State of MCS-channel 3 (rw) */
        vuint32_t ERR2:1;          /**< \brief [2:2] Error State of MCS-channel 2 (rw) */
        vuint32_t ERR1:1;          /**< \brief [1:1] Error State of MCS-channel 1 (rw) */
        vuint32_t ERR0:1;          /**< \brief [0:0] Error State of MCS-channel 0 (rw) */
    } B;
} GTM_MCS_ERR;

typedef union _GTM_MCS_REG_PROT {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t WPROT7:2;        /**< \brief [15:14] Register Write Protection of MCS-channel 7 (rw) */
        vuint32_t WPROT6:2;        /**< \brief [13:12] Register Write Protection of MCS-channel 6 (rw) */
        vuint32_t WPROT5:2;        /**< \brief [11:10] Register Write Protection of MCS-channel 5 (rw) */
        vuint32_t WPROT4:2;        /**< \brief [9:8] Register Write Protection of MCS-channel 4 (rw) */
        vuint32_t WPROT3:2;        /**< \brief [7:6] Register Write Protection of MCS-channel 3 (rw) */
        vuint32_t WPROT2:2;        /**< \brief [5:4] Register Write Protection of MCS-channel 2 (rw) */
        vuint32_t WPROT1:2;        /**< \brief [3:2] Register Write Protection of MCS-channel 1 (rw) */
        vuint32_t WPROT0:2;        /**< \brief [1:0] Register Write Protection of MCS-channel 0 (rw) */
    } B;
} GTM_MCS_REG_PROT;

typedef union _GTM_MCS_SINT_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t S_IRQ7:1;        /**< \brief [7:7] Shared interrupt 7 notify flag. (rw) */
        vuint32_t S_IRQ6:1;        /**< \brief [6:6] Shared interrupt 6 notify flag. (rw) */
        vuint32_t S_IRQ5:1;        /**< \brief [5:5] Shared interrupt 5 notify flag. (rw) */
        vuint32_t S_IRQ4:1;        /**< \brief [4:4] Shared interrupt 4 notify flag. (rw) */
        vuint32_t S_IRQ3:1;        /**< \brief [3:3] Shared interrupt 3 notify flag. (rw) */
        vuint32_t S_IRQ2:1;        /**< \brief [2:2] Shared interrupt 2 notify flag. (rw) */
        vuint32_t S_IRQ1:1;        /**< \brief [1:1] Shared interrupt 1 notify flag. (rw) */
        vuint32_t S_IRQ0:1;        /**< \brief [0:0] Shared interrupt 0 notify flag. (rw) */
    } B;
} GTM_MCS_SINT_IRQ_NOTIFY;

typedef union _GTM_MCS_SINT_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;      /**< \brief [31:8] \internal Reserved */
        vuint32_t S_IRQ7_EN:1;        /**< \brief [7:7] Shared interrupt 7 enable. (rw) */
        vuint32_t S_IRQ6_EN:1;        /**< \brief [6:6] Shared interrupt 6 enable. (rw) */
        vuint32_t S_IRQ5_EN:1;        /**< \brief [5:5] Shared interrupt 5 enable. (rw) */
        vuint32_t S_IRQ4_EN:1;        /**< \brief [4:4] Shared interrupt 4 enable. (rw) */
        vuint32_t S_IRQ3_EN:1;        /**< \brief [3:3] Shared interrupt 3 enable. (rw) */
        vuint32_t S_IRQ2_EN:1;        /**< \brief [2:2] Shared interrupt 2 enable. (rw) */
        vuint32_t S_IRQ1_EN:1;        /**< \brief [1:1] Shared interrupt 1 enable. (rw) */
        vuint32_t S_IRQ0_EN:1;        /**< \brief [0:0] Shared interrupt 0 enable. (rw) */
    } B;
} GTM_MCS_SINT_IRQ_EN;

typedef union _GTM_MCS_SINT_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;       /**< \brief [31:8] \internal Reserved */
        vuint32_t TRG_S_IRQ7:1;        /**< \brief [7:7] Trigger the bit MCS${i}_SINT_IRQ_NOTIFY.S_IRQ[7] by software (rw) */
        vuint32_t TRG_S_IRQ6:1;        /**< \brief [6:6] Trigger the bit MCS${i}_SINT_IRQ_NOTIFY.S_IRQ[6] by software (rw) */
        vuint32_t TRG_S_IRQ5:1;        /**< \brief [5:5] Trigger the bit MCS${i}_SINT_IRQ_NOTIFY.S_IRQ[5] by software (rw) */
        vuint32_t TRG_S_IRQ4:1;        /**< \brief [4:4] Trigger the bit MCS${i}_SINT_IRQ_NOTIFY.S_IRQ[4] by software (rw) */
        vuint32_t TRG_S_IRQ3:1;        /**< \brief [3:3] Trigger the bit MCS${i}_SINT_IRQ_NOTIFY.S_IRQ[3] by software (rw) */
        vuint32_t TRG_S_IRQ2:1;        /**< \brief [2:2] Trigger the bit MCS${i}_SINT_IRQ_NOTIFY.S_IRQ[2] by software (rw) */
        vuint32_t TRG_S_IRQ1:1;        /**< \brief [1:1] Trigger the bit MCS${i}_SINT_IRQ_NOTIFY.S_IRQ[1] by software (rw) */
        vuint32_t TRG_S_IRQ0:1;        /**< \brief [0:0] Trigger the bit MCS${i}_SINT_IRQ_NOTIFY.S_IRQ[0] by software (rw) */
    } B;
} GTM_MCS_SINT_IRQ_FORCINT;

typedef union _GTM_MCS_SINT_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;     /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;        /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_MCS_SINT_IRQ_MODE;

typedef union _GTM_MCS_HBP_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_18:14;    /**< \brief [31:18] \internal Reserved */
        vuint32_t NOT:1;             /**< \brief [17:17] Logical negation of h−th hardware break point (rw) */
        vuint32_t AND:1;             /**< \brief [16:16] Logical AND conjunction of h−th hardware break point (rw) */
        vuint32_t reserved_13:1;     /**< \brief [15:15] \internal Reserved */
        vuint32_t TYPE:3;            /**< \brief [14:12] Define type of h−th hardware break point (rw) */
        vuint32_t reserved_10:2;     /**< \brief [11:10] \internal Reserved */
        vuint32_t SCOPE:2;           /**< \brief [9:8] Define scope of h−th hardware break point (rw) */
        vuint32_t EN_CH7:1;          /**< \brief [7:7] Enable h−th hardware break point for channel 7 (rw) */
        vuint32_t EN_CH6:1;          /**< \brief [6:6] Enable h−th hardware break point for channel 6 (rw) */
        vuint32_t EN_CH5:1;          /**< \brief [5:5] Enable h−th hardware break point for channel 5 (rw) */
        vuint32_t EN_CH4:1;          /**< \brief [4:4] Enable h−th hardware break point for channel 4 (rw) */
        vuint32_t EN_CH3:1;          /**< \brief [3:3] Enable h−th hardware break point for channel 3 (rw) */
        vuint32_t EN_CH2:1;          /**< \brief [2:2] Enable h−th hardware break point for channel 2 (rw) */
        vuint32_t EN_CH1:1;          /**< \brief [1:1] Enable h−th hardware break point for channel 1 (rw) */
        vuint32_t EN_CH0:1;          /**< \brief [0:0] Enable h−th hardware break point for channel 0 (rw) */
    } B;
} GTM_MCS_HBP_CTRL;

typedef union _GTM_MCS_HBP_PATTERN {
    vuint32_t R;
    struct {
        vuint32_t DATA:32;    /**< \brief [31:0] Define pattern or address of h−th hardware break point */
    } B;
} GTM_MCS_HBP_PATTERN;

typedef union _GTM_MCS_HBP_STATUS {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t HALT_CH7:1;       /**< \brief [7:7]  */
        vuint32_t HALT_CH6:1;       /**< \brief [6:6]  */
        vuint32_t HALT_CH5:1;       /**< \brief [5:5]  */
        vuint32_t HALT_CH4:1;       /**< \brief [4:4]  */
        vuint32_t HALT_CH3:1;       /**< \brief [3:3]  */
        vuint32_t HALT_CH2:1;       /**< \brief [2:2]  */
        vuint32_t HALT_CH1:1;       /**< \brief [1:1]  */
        vuint32_t HALT_CH0:1;       /**< \brief [0:0]  */
    } B;
} GTM_MCS_HBP_STATUS;

typedef union _GTM_MCS_HBP_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;    /**< \brief [31:1] \internal Reserved */
        vuint32_t HBP_IRQ:1;        /**< \brief [0:0]  Interrupt notify flag of the h−th hardware break point (rw)*/
    } B;
} GTM_MCS_HBP_IRQ_NOTIFY;

typedef union _GTM_MCS_HBP_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;    /**< \brief [31:1] \internal Reserved */
        vuint32_t HBP_IRQ_EN:1;     /**< \brief [0:0] Trigger the bit MCS${i}_HBP_IRQ_NOTIFY.HBP_IRQ by software (rw)*/
    } B;
} GTM_MCS_HBP_IRQ_EN;

typedef union _GTM_MCS_HBP_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;     /**< \brief [31:1] \internal Reserved */
        vuint32_t TRG_HBP_IRQ:1;     /**< \brief [0:0]  Interrupt Enable bit of the h−th hardware break point (rw)*/
    } B;
} GTM_MCS_HBP_IRQ_FORCINT;

typedef union _GTM_MCS_HBP_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;       /**< \brief [1:0] IRQ mode selection for all break point interrupts (rw)*/
    } B;
} GTM_MCS_HBP_IRQ_MODE;

typedef volatile struct _GTM_MCS_HBP {
       GTM_MCS_HBP_CTRL                 CTRL;                   /**< \brief 0, MCS${i} hardware break point h control register*/
       GTM_MCS_HBP_PATTERN              PATTERN;                /**< \brief 4, MCS${i} hardware break point pattern register*/
       GTM_MCS_HBP_STATUS               STATUS;                 /**< \brief 8, MCS${i} hardware break point status register*/
       GTM_MCS_HBP_IRQ_NOTIFY           IRQ_NOTIFY;             /**< \brief C, MCS${i} hardware break point interrupt notification register*/
       GTM_MCS_HBP_IRQ_EN               IRQ_EN ;                /**< \brief 10, MCS${i} hardware break point interrupt enable register*/
       GTM_MCS_HBP_IRQ_FORCINT          IRQ_FORCINT ;           /**< \brief 14, MCS${i} force hardware break point interrupt register*/
       GTM_MCS_HBP_IRQ_MODE             IRQ_MODE;               /**< \brief 18, MCS${i} break point h interrupt mode configuration register*/
       vuint8_t                    reserved_1C[0x4];       /**< \brief 1C, \internal Reserved */
} GTM_MCS_HBP;

typedef volatile struct _GTM_MCS {
       GTM_MCS_CH                      CH[8];                  /**< \brief 0, */
       vuint8_t                   reserved_800[0x628];    /**< \brief 800, \internal Reserved */
       GTM_MCS_CH_CTRG                 CTRG;                   /**< \brief E28, MCS${i} Clear Trigger Control Register*/
       GTM_MCS_CH_STRG                 STRG;                   /**< \brief E2C, MCS${i} Set Trigger Control Register*/
       vuint8_t                   reserved_E30[0xD0];     /**< \brief E30, \internal Reserved */
       GTM_MCS_CTRL_STAT               CTRL_STAT;              /**< \brief F00, MCS${i} Control and Status Register*/
       GTM_MCS_RESET                   RESET;                  /**< \brief F04, MCS${i} Reset Register*/
       GTM_MCS_CAT                     CAT;                    /**< \brief F08, MCS${i} Cancel ARU Transfer Instruction Register*/
       GTM_MCS_CWT                     CWT;                    /**< \brief F0C, MCS${i} Cancel WURM Instruction Register*/
       GTM_MCS_ERR                     ERR;                    /**< \brief F10, MCS${i} error register*/
       vuint8_t                   reserved_F14[0x8];      /**< \brief F14, \internal Reserved */
       GTM_MCS_REG_PROT                REG_PROT;               /**< \brief F1C, MCS${i} Write Protection Register*/
       GTM_MCS_SINT_IRQ_NOTIFY         SINT_IRQ_NOTIFY;        /**< \brief F20, MCS${i} shared interrupt notification register*/
       GTM_MCS_SINT_IRQ_EN             SINT_IRQ_EN;            /**< \brief F24, MCS${i} shared interrupt enable register*/
       GTM_MCS_SINT_IRQ_FORCINT        SINT_IRQ_FORCINT ;      /**< \brief F28, MCS${i} force shared interrupt register*/
       GTM_MCS_SINT_IRQ_MODE           SINT_IRQ_MODE;          /**< \brief F2C, MCS${i} shared interrupt mode configuration register*/
       vuint8_t                   reserved_F30[0x10];     /**< \brief F30, \internal Reserved */
       GTM_MCS_HBP                     HBP[2];                 /**< \brief F40, \internal Reserved */
       vuint8_t                   reserved_F80[0x80];     /**< \brief F80, \internal Reserved */
} GTM_MCS;

/* ============================================================================
   =============================== Module: GTM_TIO ================================
   ============================================================================ */
typedef union _GTM_TIO_G_CH_CTRL {
    vuint32_t R;
    struct {
        vuint32_t PL_TRIG_OUT_UPD_EN:1;         /**< \brief [31:31] Select TIO[i] basic update source of channel [c] */
        vuint32_t PL_TRIG_OUT_EN_PREV_PL_TRIG:1;/**< \brief [30:30] TIO[i] channel [c] PL_TRIG_OUT source: PL_TRIG_OUT[c]−1 enable */
        vuint32_t PL_TRIG_OUT_EN_PL_EVT:1;      /**< \brief [29:29] TIO[i] channel [c] PL_TRIG_OUT source: PL_EVT[c] enable */
        vuint32_t PL_TRIG_OUT_EN_PREV_TRIG:1;   /**< \brief [28:28] TIO[i] channel [c] PL_TRIG_OUT source: TRIG_OUT[c]−1 enable */
        vuint32_t PL_TRIG_OUT_EN_O_FE:1;        /**< \brief [27:27] TIO[i] channel [c] PL_TRIG_OUT source: Falling edge O[c] enable */
        vuint32_t PL_TRIG_OUT_EN_O_RE:1;        /**< \brief [26:26] TIO[i] channel [c] PL_TRIG_OUT source: Rising edge O[c] enable */
        vuint32_t PL_TRIG_OUT_EN_S_FE:1;        /**< \brief [25:25] TIO[i] channel [c] PL_TRIG_OUT source: Falling edge S[c] enable */
        vuint32_t PL_TRIG_OUT_EN_S_RE:1;        /**< \brief [24:24] TIO[i] channel [c] PL_TRIG_OUT source: Rising edge S[c] enable */
        vuint32_t PL_S_TRIG_OUT_EN:1;           /**< \brief [23:23] Enable usage of TRIG_OUT[c] in instruction of S resource channel [c] */
        vuint32_t PL_O_TRIG_OUT_EN:1;           /**< \brief [22:22] Enable usage of TRIG_OUT[c] in instruction of O resource channel [c] */
        vuint32_t PL_SEL_IN:1;                  /**< \brief [21:21] Select input source for O resource channel [c] */
        vuint32_t PL_ODIS:1;                    /**< \brief [20:20] Disable change of TIO[i]_O.CH[x] bit x = [g] * 8 + [c] */
        vuint32_t PL_FREEZE_O_EN:1;             /**< \brief [19:19] Enable O buffer freeze in channel [c] */
        vuint32_t PL_O_MODE:3;                  /**< \brief [18:16] Select mode of operation for O resource channel [c] */
        vuint32_t PL_CYCLIC_BUFF:1;             /**< \brief [15:15] Enable circular buffer functionality in channel [c] */
        vuint32_t PL_FREEZE_S_EN:1;             /**< \brief [14:14] Enable S buffer freeze in channel [c] */
        vuint32_t PL_S_MODE:2;                  /**< \brief [13:12] Select mode of operation for S resource channel [c] */
        vuint32_t UPDATE_SRC:4;                 /**< \brief [11:8] Select update source of channel [c] */
        vuint32_t PL_CYCLIC_INIT_TRIG_EN:1;     /**< \brief [7:7] Enable usage of TRIG_OUT[c] as init trigger of cyclic buffer functionality in channel [c] */
        vuint32_t TRIG_OUT_EN_PREV_PL_TRIG:1;   /**< \brief [6:6] TIO[i] channel [c] Trigger Output source: PL_TRIG_OUT[c]−1enable */
        vuint32_t TRIG_OUT_EN_PL_EVT:1;         /**< \brief [5:5] TIO[i] channel [c] Trigger Output source: PL_EVT[c] enable */
        vuint32_t TRIG_OUT_EN_PREV_TRIG:1;      /**< \brief [4:4] TIO[i] channel [c] Trigger Output source: TRIG_OUT[c]−1enable */
        vuint32_t TRIG_OUT_EN_O_FE:1;           /**< \brief [3:3] TIO[i] channel [c] Trigger Output source: Falling edge O[c] enable */
        vuint32_t TRIG_OUT_EN_O_RE:1;           /**< \brief [2:2] TIO[i] channel [c] Trigger Output source: Rising edge O[c] enable */
        vuint32_t TRIG_OUT_EN_S_FE:1;           /**< \brief [1:1] TIO[i] channel [c] Trigger Output source: Falling edge S[c] enable */
        vuint32_t TRIG_OUT_EN_S_RE:1;           /**< \brief [0:0] TIO[i] channel [c] Trigger Output source: Rising edge S[c] enable */
    } B;
} GTM_TIO_G_CH_CTRL;

typedef union _GTM_TIO_G_CH_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:26;        /**< \brief [31:6] \internal Reserved */
        vuint32_t PL_EVT_IRQ:1;         /**< \brief [5:5] Interrupt request PL_EVT of channel [c] */
        vuint32_t UPDATE_IRQ:1;         /**< \brief [4:4] Interrupt request for update of channel [c] */
        vuint32_t O_FE_IRQ:1;           /**< \brief [3:3] Interrupt request Falling edge O[c] */
        vuint32_t O_RE_IRQ:1;           /**< \brief [2:2] Interrupt request Rising edge O[c] */
        vuint32_t S_FE_IRQ:1;           /**< \brief [1:1] Interrupt request Falling edge S[c] */
        vuint32_t S_RE_IRQ:1;           /**< \brief [0:0] Interrupt request Rising edge S[c] */
    } B;
} GTM_TIO_G_CH_IRQ_NOTIFY;

typedef union _GTM_TIO_G_CH_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:26;           /**< \brief [31:6] \internal Reserved */
        vuint32_t PL_EVT_IRQ_EN:1;         /**< \brief [5:5] Interrupt enable request PL_EVT of channel [c] */
        vuint32_t UPDATE_IRQ_EN:1;         /**< \brief [4:4] Interrupt enable request for update of channel [c] */
        vuint32_t O_FE_IRQ_EN:1;           /**< \brief [3:3] Interrupt enable request Falling edge O[c] */
        vuint32_t O_RE_IRQ_EN:1;           /**< \brief [2:2] Interrupt enable request Rising edge O[c] */
        vuint32_t S_FE_IRQ_EN:1;           /**< \brief [1:1] Interrupt enable request Falling edge S[c] */
        vuint32_t S_RE_IRQ_EN:1;           /**< \brief [0:0] Interrupt enable request Rising edge S[c] */
    } B;
} GTM_TIO_G_CH_IRQ_EN;

typedef union _GTM_TIO_G_CH_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:26;        /**< \brief [31:6] \internal Reserved */
        vuint32_t TRG_PL_EVT_IRQ:1;         /**< \brief [5:5] Trigger the bit TIO[i]_G[g]_CH[c]_IRQ_NOTIFY.PL_EVT_IRQ by software */
        vuint32_t TRG_UPDATE_IRQ:1;         /**< \brief [4:4] Trigger the bit TIO[i]_G[g]_CH[c]_IRQ_NOTIFY.UPDATE_IRQ by software */
        vuint32_t TRG_O_FE_IRQ:1;           /**< \brief [3:3] Trigger the bit TIO[i]_G[g]_CH[c]_IRQ_NOTIFY.O_FE_IRQ by software. */
        vuint32_t TRG_O_RE_IRQ:1;           /**< \brief [2:2] Trigger the bit TIO[i]_G[g]_CH[c]_IRQ_NOTIFY.O_RE_IRQ by software */
        vuint32_t TRG_S_FE_IRQ:1;           /**< \brief [1:1] Trigger the bit TIO[i]_G[g]_CH[c]_IRQ_NOTIFY.S_FE_IRQ by software. */
        vuint32_t TRG_S_RE_IRQ:1;           /**< \brief [0:0] Trigger the bit TIO[i]_G[g]_CH[c]_IRQ_NOTIFY.S_RE_IRQ by software */
    } B;
} GTM_TIO_G_CH_IRQ_FORCINT;

typedef union _GTM_TIO_G_CH_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;        /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;           /**< \brief [1:0] IRQ mode selection */
    } B;
} GTM_TIO_G_CH_IRQ_MODE;

typedef union _GTM_TIO_G_CH_CTRL2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;        /**< \brief [31:2] \internal Reserved */
        vuint32_t DUAL_CMP_MST_EN:1;       /**< \brief [1:1] TIO[i] channel [c] Trigger Output source: Falling edge S[c] enable*/
        vuint32_t DUAL_CMP_EN:1;           /**< \brief [0:0] TIO[i] channel [c] Trigger Output source: Rising edge S[c] enable */
    } B;
} GTM_TIO_G_CH_CTRL2;

typedef union _GTM_TIO_G_CH_SINST {
    vuint32_t R;
    struct {
        vuint32_t INSTR_PULL_EN:1;      /**< \brief [31:31] Enable instruction fetch*/
        vuint32_t DATA_PUSH_EN:1;       /**< \brief [30:30] Enable data capture*/
        vuint32_t CMD:6;                /**< \brief [29:24] Command*/
        vuint32_t OP:24;                /**< \brief [23:0] Operand */
    } B;
} GTM_TIO_G_CH_SINST;

typedef union _GTM_TIO_G_CH_SCMD {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t INSTR_PULL_EN:1;      /**< \brief [31:31] Enable instruction fetch*/
        vuint32_t DATA_PUSH_EN:1;       /**< \brief [30:30] Enable data capture*/
        vuint32_t CMD:6;                /**< \brief [29:24] Command*/
        vuint32_t reserved_0:24;        /**< \brief [23:0] \internal Reserved */
    } B;
} GTM_TIO_G_CH_SCMD;

typedef union _GTM_TIO_G_CH_SOP {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;        /**< \brief [31:24] \internal Reserved */
        vuint32_t OP:24;                /**< \brief [23:0] Operand */
    } B;
} GTM_TIO_G_CH_SOP;

typedef union _GTM_TIO_G_CH_OINST {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t INSTR_PULL_EN:1;      /**< \brief [31:31] Enable instruction fetch*/
        vuint32_t DATA_PUSH_EN:1;       /**< \brief [30:30] Enable data capture*/
        vuint32_t CMD:6;                /**< \brief [29:24] Command*/
        vuint32_t OP:24;                /**< \brief [23:0] Operand */
    } B;
} GTM_TIO_G_CH_OINST;

typedef union _GTM_TIO_G_CH_OCMD {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t INSTR_PULL_EN:1;      /**< \brief [31:31] Enable instruction fetch*/
        vuint32_t DATA_PUSH_EN:1;       /**< \brief [30:30] Enable data capture*/
        vuint32_t CMD:6;                /**< \brief [29:24] Command*/
        vuint32_t reserved_0:24;        /**< \brief [23:0] \internal Reserved */
    } B;
} GTM_TIO_G_CH_OCMD;

typedef union _GTM_TIO_G_CH_OOP {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;        /**< \brief [31:24] \internal Reserved */
        vuint32_t OP:24;                /**< \brief [23:0] Operand */
    } B;
} GTM_TIO_G_CH_OOP;

typedef union _GTM_TIO_G_CH_SHIFTCNT {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_5:27;       /**< \brief [31:5] \internal Reserved */
        vuint32_t CNT:5;                /**< \brief [4:0] Shift counter value */
    } B;
} GTM_TIO_G_CH_SHIFTCNT;

typedef volatile struct _GTM_TIO_CH {
       GTM_TIO_G_CH_CTRL              CTRL;                   /**< \brief 0, TIO${i} group ${g} channel ${c} control register */
       GTM_TIO_G_CH_IRQ_NOTIFY        IRQ_NOTIFY ;            /**< \brief 4, TIO${i} group ${g} channel ${c} interrupt notification register */
       GTM_TIO_G_CH_IRQ_EN            IRQ_EN ;                /**< \brief 8, TIO${i} group ${g} channel ${c} interrupt enable register */
       GTM_TIO_G_CH_IRQ_FORCINT       IRQ_FORCINT ;           /**< \brief C, TIO${i} group ${g} channel ${c} force interrupt register */
       GTM_TIO_G_CH_IRQ_MODE          IRQ_MODE ;              /**< \brief 10, TIO${i} group ${g} channel ${c} IRQ mode configuration register */
       GTM_TIO_G_CH_CTRL2             CTRL2;                  /**< \brief 14, TIO${i} group ${g} channel ${c} control2 register */
       vuint8_t                  reserved_18[0x8];       /**< \brief 18, \internal Reserved */
       GTM_TIO_G_CH_SINST             SINST;                  /**< \brief 20, TIO${i} group ${g} channel ${c} control2 register */
       GTM_TIO_G_CH_SCMD              SCMD;                   /**< \brief 24, TIO${i} group ${g} channel ${c} resource S instruction register (buffer operation) */
       GTM_TIO_G_CH_SOP               SOP;                    /**< \brief 28, TIO${i} group ${g} channel ${c} resource S operand register */
       vuint8_t                  reserved_2C[0x4];       /**< \brief 2C, \internal Reserved */
       GTM_TIO_G_CH_OINST             OINST;                  /**< \brief 30, TIO${i}  group ${g} channel ${c} resource O instruction register (buffer operation) */
       GTM_TIO_G_CH_OCMD              OCMD;                   /**< \brief 34, TIO${i}  group ${g} channel ${c} resource O command register (buffer operation) */
       GTM_TIO_G_CH_OOP               OOP;                    /**< \brief 38, TIO${i}  group ${g} channel ${c} resource O operand register */
       GTM_TIO_G_CH_SHIFTCNT          SHIFTCNT;               /**< \brief 3C, TIO${i}  group ${g} channel ${c} resource shift count register */
} GTM_TIO_G_CH;

typedef union _GTM_TIO_G_ISEL0_CTRL1 {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_28:4;         /**< \brief [31:28] \internal Reserved */
        vuint32_t WRITE_EN3:1;           /**< \brief [27:27] enable writing of configuration bit fields LUT2_[k], OUT_SEL[k] */
        vuint32_t WRITE_EN2:1;           /**< \brief [26:26] enable writing of configuration bit fields LUT2_[k], OUT_SEL[k] */
        vuint32_t WRITE_EN1:1;           /**< \brief [25:25] enable writing of configuration bit fields LUT2_[k], OUT_SEL[k] */
        vuint32_t WRITE_EN0:1;           /**< \brief [24:24] enable writing of configuration bit fields LUT2_[k], OUT_SEL[k] */
        vuint32_t reserved_20:4;         /**< \brief [23:20] \internal Reserved */
        vuint32_t OUT_SEL3:1;            /**< \brief [19:19] select signal for ISEL_OUT[c] where c =[q]*4+[k] */
        vuint32_t OUT_SEL2:1;            /**< \brief [18:18] select signal for ISEL_OUT[c] where c =[q]*4+[k] */
        vuint32_t OUT_SEL1:1;            /**< \brief [17:17] select signal for ISEL_OUT[c] where c =[q]*4+[k] */
        vuint32_t OUT_SEL0:1;            /**< \brief [16:16] select signal for ISEL_OUT[c] where c =[q]*4+[k] */
        vuint32_t LUT2_3:4;              /**< \brief [15:12] 2 bit Lookup table function for channel c=[q]*4+[k] */
        vuint32_t LUT2_2:4;              /**< \brief [11:8] 2 bit Lookup table function for channel c=[q]*4+[k] */
        vuint32_t LUT2_1:4;              /**< \brief [7:4] 2 bit Lookup table function for channel c=[q]*4+[k] */
        vuint32_t LUT2_0:4;              /**< \brief [3:0] 2 bit Lookup table function for channel c=[q]*4+[k] */
    } B;
} GTM_TIO_G_ISEL0_CTRL1;

typedef union _GTM_TIO_G_ISEL0_CTRL2 {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_23:9;         /**< \brief [31:23] \internal Reserved */
        vuint32_t LUT3IN_SEL2:1;         /**< \brief [22:22] select source for LUT3_IN[k] signal in quad = [q] */
        vuint32_t LUT3IN_SEL1:1;         /**< \brief [21:21] select source for LUT3_IN[k] signal in quad = [q] */
        vuint32_t LUT3IN_SEL0:1;         /**< \brief [20:20] select source for LUT3_IN[k] signal in quad = [q] */
        vuint32_t reserved_18:2;         /**< \brief [19:18] \internal Reserved */
        vuint32_t QOUT_SEL:2;            /**< \brief [17:16] select source for ISEL_QOUT[q] signal in quad = [q] */
        vuint32_t reserved_8:8;          /**< \brief [15:8] \internal Reserved */
        vuint32_t LUT3:8;                /**< \brief [7:0] 3 bit Lookup table function for quad=[q]; channels [q]*4+2 .. [q]*4 */
    } B;
} GTM_TIO_G_ISEL0_CTRL2;

typedef union _GTM_TIO_G_ISEL1_CTRL1 {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_28:4;         /**< \brief [31:28] \internal Reserved */
        vuint32_t WRITE_EN3:1;           /**< \brief [27:27] enable writing of configuration bit fields LUT2_[k], OUT_SEL[k] */
        vuint32_t WRITE_EN2:1;           /**< \brief [26:26] enable writing of configuration bit fields LUT2_[k], OUT_SEL[k] */
        vuint32_t WRITE_EN1:1;           /**< \brief [25:25] enable writing of configuration bit fields LUT2_[k], OUT_SEL[k] */
        vuint32_t WRITE_EN0:1;           /**< \brief [24:24] enable writing of configuration bit fields LUT2_[k], OUT_SEL[k] */
        vuint32_t reserved_20:4;         /**< \brief [23:20] \internal Reserved */
        vuint32_t OUT_SEL3:1;            /**< \brief [19:19] select signal for ISEL_OUT[c] where c =[q]*4+[k] */
        vuint32_t OUT_SEL2:1;            /**< \brief [18:18] select signal for ISEL_OUT[c] where c =[q]*4+[k] */
        vuint32_t OUT_SEL1:1;            /**< \brief [17:17] select signal for ISEL_OUT[c] where c =[q]*4+[k] */
        vuint32_t OUT_SEL0:1;            /**< \brief [16:16] select signal for ISEL_OUT[c] where c =[q]*4+[k] */
        vuint32_t LUT2_3:4;              /**< \brief [15:12] 2 bit Lookup table function for channel c=[q]*4+[k] */
        vuint32_t LUT2_2:4;              /**< \brief [11:8] 2 bit Lookup table function for channel c=[q]*4+[k] */
        vuint32_t LUT2_1:4;              /**< \brief [7:4] 2 bit Lookup table function for channel c=[q]*4+[k] */
        vuint32_t LUT2_0:4;              /**< \brief [3:0] 2 bit Lookup table function for channel c=[q]*4+[k] */
    } B;
} GTM_TIO_G_ISEL1_CTRL1;

typedef union _GTM_TIO_G_ISEL1_CTRL2 {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_23:9;         /**< \brief [31:23] \internal Reserved */
        vuint32_t LUT3IN_SEL2:1;         /**< \brief [22:22] select source for LUT3_IN[k] signal in quad = [q] */
        vuint32_t LUT3IN_SEL1:1;         /**< \brief [21:21] select source for LUT3_IN[k] signal in quad = [q] */
        vuint32_t LUT3IN_SEL0:1;         /**< \brief [20:20] select source for LUT3_IN[k] signal in quad = [q] */
        vuint32_t reserved_18:2;         /**< \brief [19:18] \internal Reserved */
        vuint32_t QOUT_SEL:2;            /**< \brief [17:16] select source for ISEL_QOUT[q] signal in quad = [q] */
        vuint32_t reserved_8:8;          /**< \brief [15:8] \internal Reserved */
        vuint32_t LUT3:8;                /**< \brief [7:0] 3 bit Lookup table function for quad=[q]; channels [q]*4+2 .. [q]*4 */
    } B;
} GTM_TIO_G_ISEL1_CTRL2;

typedef union _GTM_TIO_G_OP_USAGE {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t WRITE_EN7:1;              /**< \brief [31:31] enable writing of configuration bit fields TIO[i]_G[g]_OP_USAGE.MODE[c] */
        vuint32_t WRITE_EN6:1;              /**< \brief [30:30] enable writing of configuration bit fields TIO[i]_G[g]_OP_USAGE.MODE[c] */
        vuint32_t WRITE_EN5:1;              /**< \brief [29:29] enable writing of configuration bit fields TIO[i]_G[g]_OP_USAGE.MODE[c] */
        vuint32_t WRITE_EN4:1;              /**< \brief [28:28] enable writing of configuration bit fields TIO[i]_G[g]_OP_USAGE.MODE[c] */
        vuint32_t WRITE_EN3:1;              /**< \brief [27:27] enable writing of configuration bit fields TIO[i]_G[g]_OP_USAGE.MODE[c] */
        vuint32_t WRITE_EN2:1;              /**< \brief [26:26] enable writing of configuration bit fields TIO[i]_G[g]_OP_USAGE.MODE[c] */
        vuint32_t WRITE_EN1:1;              /**< \brief [25:25] enable writing of configuration bit fields TIO[i]_G[g]_OP_USAGE.MODE[c] */
        vuint32_t WRITE_EN0:1;              /**< \brief [24:24] enable writing of configuration bit fields TIO[i]_G[g]_OP_USAGE.MODE[c] */
        vuint32_t MODE7:3;              /**< \brief [23:21] operand usage of S/ O resource */
        vuint32_t MODE6:3;              /**< \brief [20:18] operand usage of S/ O resource */
        vuint32_t MODE5:3;              /**< \brief [17:15] operand usage of S/ O resource */
        vuint32_t MODE4:3;              /**< \brief [14:12] operand usage of S/ O resource */
        vuint32_t MODE3:3;              /**< \brief [11:9] operand usage of S/ O resource */
        vuint32_t MODE2:3;              /**< \brief [8:6] operand usage of S/ O resource */
        vuint32_t MODE1:3;              /**< \brief [5:3] operand usage of S/ O resource */
        vuint32_t MODE0:3;              /**< \brief [2:0] operand usage of S/ O resource */
    } B;
} GTM_TIO_G_OP_USAGE;

typedef volatile struct _GTM_TIO_G {
    GTM_TIO_G_CH                    CH[8];                   /**< \brief 0, TIO${i} group ${g} channel ${c} Register*/
    GTM_TIO_G_ISEL0_CTRL1            ISEL0_CTRL1;             /**< \brief 200, TIO${i} group ${g} input selection0 register 1*/
    GTM_TIO_G_ISEL0_CTRL2            ISEL0_CTRL2;             /**< \brief 204, TIO${i} group ${g} input selection0 register 2*/
    vuint8_t                   reserved_208[0x18];      /**< \brief 208, \internal Reserved */
    GTM_TIO_G_ISEL1_CTRL1            ISEL1_CTRL1;             /**< \brief 220, TIO${i} group ${g} input selection1 register 1*/
    GTM_TIO_G_ISEL1_CTRL2            ISEL1_CTRL2;             /**< \brief 224, TIO${i} group ${g} input selection1 register 2*/
    vuint8_t                   reserved_228[0x18];      /**< \brief 228, \internal Reserved */
    GTM_TIO_G_OP_USAGE              OP_USAGE;                /**< \brief 240, TIO${i} group ${g} operand usage selection register*/
    vuint8_t                   reserved_244[0x1BC];     /**< \brief 244, \internal Reserved */
} GTM_TIO_G;

typedef union _GTM_TIO_S {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Value of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Value of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Value of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Value of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Value of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Value of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Value of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Value of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Value of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Value of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Value of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Value of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Value of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Value of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Value of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Value of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Value of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Value of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Value of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Value of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Value of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Value of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Value of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Value of channel [x] */
    } B;
} GTM_TIO_S;

typedef union _GTM_TIO_O {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Value driven on output of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Value driven on output of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Value driven on output of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Value driven on output of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Value driven on output of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Value driven on output of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Value driven on output of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Value driven on output of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Value driven on output of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Value driven on output of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Value driven on output of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Value driven on output of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Value driven on output of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Value driven on output of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Value driven on output of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Value driven on output of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Value driven on output of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Value driven on output of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Value driven on output of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Value driven on output of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Value driven on output of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Value driven on output of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Value driven on output of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Value driven on output of channel [x] */
    } B;
} GTM_TIO_O;

typedef union _GTM_TIO_ENDIS {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Enable/Disable request of  channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Enable/Disable request of  channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Enable/Disable request of  channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Enable/Disable request of  channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Enable/Disable request of  channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Enable/Disable request of  channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Enable/Disable request of  channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Enable/Disable request of  channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Enable/Disable request of  channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Enable/Disable request of  channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Enable/Disable request of  channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Enable/Disable request of  channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Enable/Disable request of  channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Enable/Disable request of  channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Enable/Disable request of  channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Enable/Disable request of  channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Enable/Disable request of  channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Enable/Disable request of  channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Enable/Disable request of  channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Enable/Disable request of  channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Enable/Disable request of  channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Enable/Disable request of  channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Enable/Disable request of  channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Enable/Disable request of  channel [x] */
    } B;
} GTM_TIO_ENDIS;

typedef union _GTM_TIO_INVERT {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Enable/Disable signal inversion of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Enable/Disable signal inversion of channel [x] */
    } B;
} GTM_TIO_INVERT;

typedef union _GTM_TIO_INPUT_MODE {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Enable/Disable input mode of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Enable/Disable input mode of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Enable/Disable input mode of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Enable/Disable input mode of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Enable/Disable input mode of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Enable/Disable input mode of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Enable/Disable input mode of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Enable/Disable input mode of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Enable/Disable input mode of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Enable/Disable input mode of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Enable/Disable input mode of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Enable/Disable input mode of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Enable/Disable input mode of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Enable/Disable input mode of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Enable/Disable input mode of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Enable/Disable input mode of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Enable/Disable input mode of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Enable/Disable input mode of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Enable/Disable input mode of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Enable/Disable input mode of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Enable/Disable input mode of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Enable/Disable input mode of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Enable/Disable input mode of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Enable/Disable input mode of channel [x] */
    } B;
} GTM_TIO_INPUT_MODE;

typedef union _GTM_TIO_CYCLIC_MODE {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Enable/Disable cyclic mode of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Enable/Disable cyclic mode of channel [x] */
    } B;
} GTM_TIO_CYCLIC_MODE;

typedef union _GTM_TIO_TRIG_OUT_GATE_EN {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] enable gating of Trigger Output events of channel [x] */
    } B;
} GTM_TIO_TRIG_OUT_GATE_EN;

typedef union _GTM_TIO_PLTRIG_OUT_GATE_EN {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] enable gating of PL_TRIG_OUT events of channel [x] */
    } B;
} GTM_TIO_PLTRIG_OUT_GATE_EN;

typedef union _GTM_TIO_CS {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Clear channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Clear channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Clear channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Clear channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Clear channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Clear channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Clear channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Clear channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Clear channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Clear channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Clear channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Clear channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Clear channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Clear channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Clear channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Clear channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Clear channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Clear channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Clear channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Clear channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Clear channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Clear channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Clear channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Clear channel [x] */
    } B;
} GTM_TIO_CS;

typedef union _GTM_TIO_CO {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Clear channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Clear channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Clear channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Clear channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Clear channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Clear channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Clear channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Clear channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Clear channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Clear channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Clear channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Clear channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Clear channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Clear channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Clear channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Clear channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Clear channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Clear channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Clear channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Clear channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Clear channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Clear channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Clear channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Clear channel [x] */
    } B;
} GTM_TIO_CO;

typedef union _GTM_TIO_CENDIS {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Disable request of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Disable request of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Disable request of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Disable request of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Disable request of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Disable request of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Disable request of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Disable request of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Disable request of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Disable request of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Disable request of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Disable request of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Disable request of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Disable request of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Disable request of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Disable request of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Disable request of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Disable request of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Disable request of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Disable request of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Disable request of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Disable request of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Disable request of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Disable request of channel [x] */
    } B;
} GTM_TIO_CENDIS;

typedef union _GTM_TIO_CINVERT {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Disable signal inversion of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Disable signal inversion of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Disable signal inversion of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Disable signal inversion of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Disable signal inversion of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Disable signal inversion of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Disable signal inversion of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Disable signal inversion of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Disable signal inversion of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Disable signal inversion of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Disable signal inversion of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Disable signal inversion of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Disable signal inversion of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Disable signal inversion of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Disable signal inversion of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Disable signal inversion of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Disable signal inversion of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Disable signal inversion of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Disable signal inversion of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Disable signal inversion of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Disable signal inversion of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Disable signal inversion of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Disable signal inversion of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Disable signal inversion of channel [x] */
    } B;
} GTM_TIO_CINVERT;

typedef union _GTM_TIO_CINPUT_MODE {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Disable input mode of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Disable input mode of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Disable input mode of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Disable input mode of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Disable input mode of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Disable input mode of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Disable input mode of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Disable input mode of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Disable input mode of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Disable input mode of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Disable input mode of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Disable input mode of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Disable input mode of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Disable input mode of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Disable input mode of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Disable input mode of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Disable input mode of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Disable input mode of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Disable input mode of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Disable input mode of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Disable input mode of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Disable input mode of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Disable input mode of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Disable input mode of channel [x] */
    } B;
} GTM_TIO_CINPUT_MODE;

typedef union _GTM_TIO_CCYCLIC_MODE {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Disable cyclic mode of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Disable cyclic mode of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Disable cyclic mode of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Disable cyclic mode of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Disable cyclic mode of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Disable cyclic mode of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Disable cyclic mode of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Disable cyclic mode of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Disable cyclic mode of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Disable cyclic mode of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Disable cyclic mode of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Disable cyclic mode of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Disable cyclic mode of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Disable cyclic mode of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Disable cyclic mode of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Disable cyclic mode of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Disable cyclic mode of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Disable cyclic mode of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Disable cyclic mode of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Disable cyclic mode of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Disable cyclic mode of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Disable cyclic mode of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Disable cyclic mode of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Disable cyclic mode of channel [x] */
    } B;
} GTM_TIO_CCYCLIC_MODE;

typedef union _GTM_TIO_CTRIG_OUT_GATE_EN {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] disable gating of Trigger Output events of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] disable gating of Trigger Output events of channel [x] */
    } B;
} GTM_TIO_CTRIG_OUT_GATE_EN;

typedef union _GTM_TIO_CPLTRIG_OUT_GATE_EN {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] disable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] disable gating of PL_TRIG_OUT events of channel [x] */
    } B;
} GTM_TIO_CPLTRIG_OUT_GATE_EN;

typedef union _GTM_TIO_SS {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Set channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Set channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Set channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Set channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Set channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Set channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Set channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Set channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Set channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Set channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Set channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Set channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Set channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Set channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Set channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Set channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Set channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Set channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Set channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Set channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Set channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Set channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Set channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Set channel [x] */
    } B;
} GTM_TIO_SS;

typedef union _GTM_TIO_SO {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Set channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Set channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Set channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Set channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Set channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Set channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Set channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Set channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Set channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Set channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Set channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Set channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Set channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Set channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Set channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Set channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Set channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Set channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Set channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Set channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Set channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Set channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Set channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Set channel [x] */
    } B;
} GTM_TIO_SO;

typedef union _GTM_TIO_SENDIS {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Enable request of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Enable request of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Enable request of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Enable request of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Enable request of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Enable request of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Enable request of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Enable request of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Enable request of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Enable request of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Enable request of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Enable request of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Enable request of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Enable request of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Enable request of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Enable request of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Enable request of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Enable request of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Enable request of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Enable request of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Enable request of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Enable request of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Enable request of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Enable request of channel [x] */
    } B;
} GTM_TIO_SENDIS;

typedef union _GTM_TIO_SINVERT {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Enable signal inversion of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Enable signal inversion of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Enable signal inversion of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Enable signal inversion of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Enable signal inversion of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Enable signal inversion of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Enable signal inversion of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Enable signal inversion of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Enable signal inversion of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Enable signal inversion of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Enable signal inversion of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Enable signal inversion of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Enable signal inversion of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Enable signal inversion of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Enable signal inversion of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Enable signal inversion of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Enable signal inversion of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Enable signal inversion of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Enable signal inversion of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Enable signal inversion of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Enable signal inversion of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Enable signal inversion of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Enable signal inversion of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Enable signal inversion of channel [x] */
    } B;
} GTM_TIO_SINVERT;

typedef union _GTM_TIO_SINPUT_MODE {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Enable input mode of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Enable input mode of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Enable input mode of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Enable input mode of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Enable input mode of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Enable input mode of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Enable input mode of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Enable input mode of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Enable input mode of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Enable input mode of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Enable input mode of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Enable input mode of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Enable input mode of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Enable input mode of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Enable input mode of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Enable input mode of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Enable input mode of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Enable input mode of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Enable input mode of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Enable input mode of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Enable input mode of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Enable input mode of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Enable input mode of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Enable input mode of channel [x] */
    } B;
} GTM_TIO_SINPUT_MODE;

typedef union _GTM_TIO_SCYCLIC_MODE {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Enable cyclic mode of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Enable cyclic mode of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Enable cyclic mode of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Enable cyclic mode of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Enable cyclic mode of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Enable cyclic mode of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Enable cyclic mode of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Enable cyclic mode of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Enable cyclic mode of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Enable cyclic mode of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Enable cyclic mode of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Enable cyclic mode of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Enable cyclic mode of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Enable cyclic mode of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Enable cyclic mode of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Enable cyclic mode of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Enable cyclic mode of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Enable cyclic mode of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Enable cyclic mode of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Enable cyclic mode of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Enable cyclic mode of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Enable cyclic mode of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Enable cyclic mode of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Enable cyclic mode of channel [x] */
    } B;
} GTM_TIO_SCYCLIC_MODE;

typedef union _GTM_TIO_STRIG_OUT_GATE_EN {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] enable gating of Trigger Output events of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] enable gating of Trigger Output events of channel [x] */
    } B;
} GTM_TIO_STRIG_OUT_GATE_EN;

typedef union _GTM_TIO_SPLTRIG_OUT_GATE_EN {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] enable gating of PL_TRIG_OUT events of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] enable gating of PL_TRIG_OUT events of channel [x] */
    } B;
} GTM_TIO_SPLTRIG_OUT_GATE_EN;

typedef union _GTM_TIO_IS {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Invert channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Invert channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Invert channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Invert channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Invert channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Invert channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Invert channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Invert channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Invert channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Invert channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Invert channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Invert channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Invert channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Invert channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Invert channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Invert channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Invert channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Invert channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Invert channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Invert channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Invert channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Invert channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Invert channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Invert channel [x] */
    } B;
} GTM_TIO_IS;

typedef union _GTM_TIO_IO {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Invert channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Invert channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Invert channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Invert channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Invert channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Invert channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Invert channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Invert channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Invert channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Invert channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Invert channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Invert channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Invert channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Invert channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Invert channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Invert channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Invert channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Invert channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Invert channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Invert channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Invert channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Invert channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Invert channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Invert channel [x] */
    } B;
} GTM_TIO_IO;

typedef union _GTM_TIO_IENDIS {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Toggle state  request of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Toggle state  request of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Toggle state  request of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Toggle state  request of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Toggle state  request of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Toggle state  request of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Toggle state  request of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Toggle state  request of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Toggle state  request of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Toggle state  request of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Toggle state  request of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Toggle state  request of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Toggle state  request of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Toggle state  request of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Toggle state  request of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Toggle state  request of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Toggle state  request of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Toggle state  request of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Toggle state  request of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Toggle state  request of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Toggle state  request of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Toggle state  request of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Toggle state  request of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Toggle state  request of channel [x] */
    } B;
} GTM_TIO_IENDIS;

typedef union _GTM_TIO_IINVERT {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Invert signal inversion of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Invert signal inversion of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Invert signal inversion of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Invert signal inversion of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Invert signal inversion of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Invert signal inversion of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Invert signal inversion of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Invert signal inversion of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Invert signal inversion of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Invert signal inversion of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Invert signal inversion of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Invert signal inversion of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Invert signal inversion of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Invert signal inversion of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Invert signal inversion of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Invert signal inversion of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Invert signal inversion of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Invert signal inversion of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Invert signal inversion of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Invert signal inversion of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Invert signal inversion of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Invert signal inversion of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Invert signal inversion of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Invert signal inversion of channel [x] */
    } B;
} GTM_TIO_IINVERT;

typedef union _GTM_TIO_IINPUT_MODE {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Toggle input mode of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Toggle input mode of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Toggle input mode of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Toggle input mode of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Toggle input mode of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Toggle input mode of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Toggle input mode of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Toggle input mode of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Toggle input mode of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Toggle input mode of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Toggle input mode of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Toggle input mode of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Toggle input mode of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Toggle input mode of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Toggle input mode of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Toggle input mode of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Toggle input mode of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Toggle input mode of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Toggle input mode of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Toggle input mode of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Toggle input mode of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Toggle input mode of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Toggle input mode of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Toggle input mode of channel [x] */
    } B;
} GTM_TIO_IINPUT_MODE;

typedef union _GTM_TIO_ICYCLIC_MODE {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] Toggle cyclic mode of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] Toggle cyclic mode of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] Toggle cyclic mode of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] Toggle cyclic mode of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] Toggle cyclic mode of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] Toggle cyclic mode of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] Toggle cyclic mode of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] Toggle cyclic mode of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] Toggle cyclic mode of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] Toggle cyclic mode of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] Toggle cyclic mode of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] Toggle cyclic mode of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] Toggle cyclic mode of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] Toggle cyclic mode of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] Toggle cyclic mode of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] Toggle cyclic mode of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] Toggle cyclic mode of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] Toggle cyclic mode of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] Toggle cyclic mode of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] Toggle cyclic mode of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] Toggle cyclic mode of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] Toggle cyclic mode of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] Toggle cyclic mode of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] Toggle cyclic mode of channel [x] */
    } B;
} GTM_TIO_ICYCLIC_MODE;

typedef union _GTM_TIO_FUPD {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] issue immediately a signal pulse on the update signal of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] issue immediately a signal pulse on the update signal of channel [x] */
    } B;
} GTM_TIO_FUPD;

typedef union _GTM_TIO_HW_CONF {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_5:27;              /**< \brief [31:5] \internal Reserved */
        vuint32_t TIO_PLUS:1;                 /**< \brief [4:4] signals availability of TIOplus functionality */
        vuint32_t reserved_2:2;               /**< \brief [3:2] \internal Reserved */
        vuint32_t NTIO_CH8:2;                 /**< \brief [1:0] signals availability of number of channels */
    } B;
} GTM_TIO_HW_CONF;

typedef union _GTM_TIO_RSEL_CTRL1 {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_31:1;                  /**< \brief [31:31] \internal Reserved */
        vuint32_t SEL_CLKEN7_2:1;                 /**< \brief [30:30] select source of RS_CLKEN[g][7:7] for channels [g]*8 .. [g]*8+7 */
        vuint32_t SEL_CLKEN7_1:1;                 /**< \brief [29:29] select source of RS_CLKEN[g][7:7] for channels [g]*8 .. [g]*8+7 */
        vuint32_t SEL_CLKEN7_0:1;                 /**< \brief [28:28] select source of RS_CLKEN[g][7:7] for channels [g]*8 .. [g]*8+7 */
        vuint32_t reserved_27:1;                  /**< \brief [27:27] \internal Reserved */
        vuint32_t SEL_CLKEN6_2:1;                 /**< \brief [26:26] select source of RS_CLKEN[g][6:6] for channels [g]*8 .. [g]*8+7 */
        vuint32_t SEL_CLKEN6_1:1;                 /**< \brief [25:25] select source of RS_CLKEN[g][6:6] for channels [g]*8 .. [g]*8+7 */
        vuint32_t SEL_CLKEN6_0:1;                 /**< \brief [24:24] select source of RS_CLKEN[g][6:6] for channels [g]*8 .. [g]*8+7 */
        vuint32_t reserved_0:24;                  /**< \brief [23:0] \internal Reserved */
    } B;
} GTM_TIO_RSEL_CTRL1;

typedef union _GTM_TIO_RSEL_CTRL2 {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_11:21;               /**< \brief [31:11] \internal Reserved */
        vuint32_t SEL_TB2_2:1;                 /**< \brief [10:10] select source of RS_TB2[g] for channels [g]*8 .. [g]*8+7 */
        vuint32_t SEL_TB2_1:1;                 /**< \brief [9:9] select source of RS_TB2[g] for channels [g]*8 .. [g]*8+7 */
        vuint32_t SEL_TB2_0:1;                 /**< \brief [8:8] select source of RS_TB2[g] for channels [g]*8 .. [g]*8+7 */
        vuint32_t reserved_27:1;               /**< \brief [7:7] \internal Reserved */
        vuint32_t SEL_TB1_2:1;                 /**< \brief [6:6] select source of RS_TB1[g] for channels [g]*8 .. [g]*8+7 */
        vuint32_t SEL_TB1_1:1;                 /**< \brief [5:5] select source of RS_TB1[g] for channels [g]*8 .. [g]*8+7 */
        vuint32_t SEL_TB1_0:1;                 /**< \brief [4:4] select source of RS_TB1[g] for channels [g]*8 .. [g]*8+7 */
        vuint32_t reserved_0:4;               /**< \brief [3:0] \internal Reserved */
    } B;
} GTM_TIO_RSEL_CTRL2;

typedef union _GTM_TIO_PL_SWRST {
    vuint32_t R;
    vint32_t I;
    struct {
        vuint32_t reserved_24:8;         /**< \brief [31:24] \internal Reserved */
        vuint32_t CH23:1;                /**< \brief [23:23] reset TIO_Plus resources of channel [x] */
        vuint32_t CH22:1;                /**< \brief [22:22] reset TIO_Plus resources of channel [x] */
        vuint32_t CH21:1;                /**< \brief [21:21] reset TIO_Plus resources of channel [x] */
        vuint32_t CH20:1;                /**< \brief [20:20] reset TIO_Plus resources of channel [x] */
        vuint32_t CH19:1;                /**< \brief [19:19] reset TIO_Plus resources of channel [x] */
        vuint32_t CH18:1;                /**< \brief [18:18] reset TIO_Plus resources of channel [x] */
        vuint32_t CH17:1;                /**< \brief [17:17] reset TIO_Plus resources of channel [x] */
        vuint32_t CH16:1;                /**< \brief [16:16] reset TIO_Plus resources of channel [x] */
        vuint32_t CH15:1;                /**< \brief [15:15] reset TIO_Plus resources of channel [x] */
        vuint32_t CH14:1;                /**< \brief [14:14] reset TIO_Plus resources of channel [x] */
        vuint32_t CH13:1;                /**< \brief [13:13] reset TIO_Plus resources of channel [x] */
        vuint32_t CH12:1;                /**< \brief [12:12] reset TIO_Plus resources of channel [x] */
        vuint32_t CH11:1;                /**< \brief [11:11] reset TIO_Plus resources of channel [x] */
        vuint32_t CH10:1;                /**< \brief [10:10] reset TIO_Plus resources of channel [x] */
        vuint32_t CH9:1;                 /**< \brief [9:9] reset TIO_Plus resources of channel [x] */
        vuint32_t CH8:1;                 /**< \brief [8:8] reset TIO_Plus resources of channel [x] */
        vuint32_t CH7:1;                 /**< \brief [7:7] reset TIO_Plus resources of channel [x] */
        vuint32_t CH6:1;                 /**< \brief [6:6] reset TIO_Plus resources of channel [x] */
        vuint32_t CH5:1;                 /**< \brief [5:5] reset TIO_Plus resources of channel [x] */
        vuint32_t CH4:1;                 /**< \brief [4:4] reset TIO_Plus resources of channel [x] */
        vuint32_t CH3:1;                 /**< \brief [3:3] reset TIO_Plus resources of channel [x] */
        vuint32_t CH2:1;                 /**< \brief [2:2] reset TIO_Plus resources of channel [x] */
        vuint32_t CH1:1;                 /**< \brief [1:1] reset TIO_Plus resources of channel [x] */
        vuint32_t CH0:1;                 /**< \brief [0:0] reset TIO_Plus resources of channel [x] */
    } B;
} GTM_TIO_PL_SWRST;

typedef volatile struct _GTM_TIO {
       GTM_TIO_G                      G[3];                     /**< \brief 0, */
       GTM_TIO_S                      S;                        /**< \brief C00, TIO${i} signal sampling register*/
       GTM_TIO_O                      O;                        /**< \brief C04, TIO${i} output register*/
       GTM_TIO_ENDIS                  ENDIS;                    /**< \brief C08, TIO${i} enable/disable register*/
       GTM_TIO_INVERT                 INVERT;                   /**< \brief C0C, TIO${i} signal invert register*/
       GTM_TIO_INPUT_MODE             INPUT_MODE;               /**< \brief C10, TIO${i} input mode register*/
       GTM_TIO_CYCLIC_MODE            CYCLIC_MODE;              /**< \brief C14, TIO${i} cyclic mode register*/
       GTM_TIO_TRIG_OUT_GATE_EN       TRIG_OUT_GATE_EN;         /**< \brief C18, TIO${i} enable Trigger Output, output gating register*/
       GTM_TIO_PLTRIG_OUT_GATE_EN     PLTRIG_OUT_GATE_EN;       /**< \brief C1C, TIO${i} enable PL_TRIG_OUT output gating register*/
       vuint8_t                  reserved_C20[0x20];       /**< \brief C20, \internal Reserved */
       GTM_TIO_CS                     CS;                       /**< \brief C40, TIO${i} clear signal sampling register*/
       GTM_TIO_CO                     CO;                       /**< \brief C44, TIO${i} clear output register*/
       GTM_TIO_CENDIS                 CENDIS;                   /**< \brief C48, TIO${i} disable register*/
       GTM_TIO_CINVERT                CINVERT;                  /**< \brief C4C, TIO${i} clear signal invert register*/
       GTM_TIO_CINPUT_MODE            CINPUT_MODE;              /**< \brief C50, TIO${i} disable input mode register*/
       GTM_TIO_CCYCLIC_MODE           CCYCLIC_MODE;             /**< \brief C54, TIO${i} disable cyclic mode register*/
       GTM_TIO_CTRIG_OUT_GATE_EN      CTRIG_OUT_GATE_EN;        /**< \brief C58, TIO${i} clear Trigger Output, output gating register*/
       GTM_TIO_CPLTRIG_OUT_GATE_EN    CPLTRIG_OUT_GATE_EN;      /**< \brief C5C, TIO${i} clear PL_TRIG_OUT output gating register*/
       vuint8_t                  reserved_C60[0x20];       /**< \brief C60, \internal Reserved */
       GTM_TIO_SS                     SS;                       /**< \brief C80, TIO${i} set signal sampling register*/
       GTM_TIO_SO                     SO;                       /**< \brief C84, TIO${i} set output register*/
       GTM_TIO_SENDIS                 SENDIS;                   /**< \brief C88, TIO${i} enable register*/
       GTM_TIO_SINVERT                SINVERT;                  /**< \brief C8C, TIO${i} set signal invert register*/
       GTM_TIO_SINPUT_MODE            SINPUT_MODE;              /**< \brief C90, TIO${i} enable input mode register*/
       GTM_TIO_SCYCLIC_MODE           SCYCLIC_MODE;             /**< \brief C94, TIO${i} enable cyclic mode register*/
       GTM_TIO_STRIG_OUT_GATE_EN      STRIG_OUT_GATE_EN;        /**< \brief C98, TIO${i} set Trigger Output, output gating register*/
       GTM_TIO_SPLTRIG_OUT_GATE_EN    SPLTRIG_OUT_GATE_EN;      /**< \brief C9C, TIO${i} set PL_TRIG_OUT output gating register*/
       vuint8_t                  reserved_CA0[0x20];       /**< \brief CA0, \internal Reserved */
       GTM_TIO_IS                     IS;                       /**< \brief CC0, TIO${i} invert signal sampling register*/
       GTM_TIO_IO                     IO;                       /**< \brief CC4, TIO${i} invert output register*/
       GTM_TIO_IENDIS                 IENDIS;                   /**< \brief CC8, TIO${i} toggle enable/disable register*/
       GTM_TIO_IINVERT                IINVERT;                  /**< \brief CCC, TIO${i} toggle signal invert register*/
       GTM_TIO_IINPUT_MODE            IINPUT_MODE;              /**< \brief CD0, TIO${i} toggle input mode register*/
       GTM_TIO_ICYCLIC_MODE           ICYCLIC_MODE;             /**< \brief CD4, TIO${i} toggle cyclic mode register*/
       vuint8_t                  reserved_CD8[0x28];       /**< \brief CD8, \internal Reserved */
       GTM_TIO_FUPD                   FUPD;                     /**< \brief D00, TIO${i} force update register*/
       GTM_TIO_HW_CONF                HW_CONF;                  /**< \brief D04, TIO${i} configuration register*/
       GTM_TIO_RSEL_CTRL1             RSEL_CTRL1;               /**< \brief D08, TIO${i} resource selection control register 1*/
       GTM_TIO_RSEL_CTRL2             RSEL_CTRL2;               /**< \brief D0C, TIO${i} resource selection control register 2*/
       GTM_TIO_PL_SWRST               PL_SWRST;                 /**< \brief D10, TIO${i} software reset for TIO Plus functionality*/
       vuint8_t                  reserved_D14[0x2EC];      /**< \brief D14, \internal Reserved */

} GTM_TIO;

/* ============================================================================
   =============================== Module: GTM_CCM ================================
   ============================================================================ */
typedef union _GTM_CCM_ARP_CTRL {
    vuint32_t R;
    struct {
        vuint32_t WPROT_AEI:1;     /**< \brief [31:31] AEI slave write protection (rw) */
        vuint32_t reserved_25:6;    /**< \brief [30:25] \internal Reserved */
        vuint32_t DIS_PROT:1;      /**< \brief [24:24] Disable ARP protection (rw) */
        vuint32_t reserved_20:4;    /**< \brief [23:20] \internal Reserved */
        vuint32_t SIZE:4;          /**< \brief [19:16] Size of ARP (rw) */
        vuint32_t ADDR:16;         /**< \brief [15:0] ARP base address (rw) */
    } B;
} GTM_CCM_ARP_CTRL;

typedef union _GTM_CCM_ARP_PROT {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t WPROT7:1;        /**< \brief [7:7] Write Protection MCS channel 7 (rw) */
        vuint32_t WPROT6:1;        /**< \brief [6:6] Write Protection MCS channel 6 (rw) */
        vuint32_t WPROT5:1;        /**< \brief [5:5] Write Protection MCS channel 5 (rw) */
        vuint32_t WPROT4:1;        /**< \brief [4:4] Write Protection MCS channel 4 (rw) */
        vuint32_t WPROT3:1;        /**< \brief [3:3] Write Protection MCS channel 3 (rw) */
        vuint32_t WPROT2:1;        /**< \brief [2:2] Write Protection MCS channel 2 (rw) */
        vuint32_t WPROT1:1;        /**< \brief [1:1] Write Protection MCS channel 1 (rw) */
        vuint32_t WPROT0:1;        /**< \brief [0:0] Write Protection MCS channel 0 (rw) */
    } B;
} GTM_CCM_ARP_PROT;

typedef volatile struct _GTM_CCM_ARP {
       GTM_CCM_ARP_CTRL                CTRL;                   /**< \brief 0, CCM${i} Address Range Protector ${z} Control Register*/
       GTM_CCM_ARP_PROT                PROT;                   /**< \brief 4, CCM${i} Address Range Protector ${z} Protection Register*/
} GTM_CCM_ARP;

typedef union _GTM_CCM_TIO_G0_OUT {
    vuint32_t R;
    struct {
        vuint32_t TIO_G1_OUT_N:8;      /**< \brief [31:24] Output level snapshot of channel [c] (r) */
        vuint32_t TIO_G0_OUT_N:8;      /**< \brief [23:16] Output level snapshot of channel [c] (r) */
        vuint32_t TIO_G1_OUT:8;        /**< \brief [15:8] Output level snapshot of TIO[i]_G1_OUT channel [c] (r) */
        vuint32_t TIO_G0_OUT:8;        /**< \brief [7:0] Output level snapshot of TIO[i]_G0_OUT channel [c] (r) */
    } B;
} GTM_CCM_TIO_G0_OUT;

typedef union _GTM_CCM_TIO_G2_OUT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;       /**< \brief [31:24] \internal Reserved */
        vuint32_t TIO_G2_OUT_N:8;      /**< \brief [23:16] Output level snapshot of channel [c] (r) */
        vuint32_t reserved_8:8;        /**< \brief [15:8] \internal Reserved */
        vuint32_t TIO_G2_OUT:8;        /**< \brief [7:0] Output level snapshot of TIO[i]_G2_OUT channel [c] (r) */
    } B;
} GTM_CCM_TIO_G2_OUT;

typedef union _GTM_CCM_HW_CONF2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_19:13;         /**< \brief [31:19] \internal Reserved */
        vuint32_t AXIM_DATA_SIZE:1;       /**< \brief [18:18] Defines the data bus width of the AXI master interface (r) */
        vuint32_t reserved_17:1;          /**< \brief [17:17] \internal Reserved */
        vuint32_t AXIS_DATA_SIZE:1;       /**< \brief [16:16] Defines the data bus width of the AXI slave interface (r) */
        vuint32_t reserved_10:6;          /**< \brief [15:10] \internal Reserved */
        vuint32_t TIO_OUT_RST:1;          /**< \brief [9:9] Reset level for all TIO output signals (r) */
        vuint32_t reserved_8:1;           /**< \brief [8:8] \internal Reserved */
        vuint32_t AXIM_POSTED_WRITE:1;    /**< \brief [7:7] Write transaction without response (r) */
        vuint32_t AXIM_SEC_ACC:1;         /**< \brief [6:6] Secure AXI master access constant (r) */
        vuint32_t AXIM_PRIV_ACC:1;        /**< \brief [5:5] Privileged AXI master access constant (r) */
        vuint32_t AXIM_ID_WIDTH:5;        /**< \brief [4:0] Defines the number of lower bits which are used for the AXIM transaction IDs (r) */
    } B;
} GTM_CCM_HW_CONF2;

typedef union _GTM_CCM_AEIM_STA {
    vuint32_t R;
    struct {
        vuint32_t reserved_26:6;    /**< \brief [31:26] \internal Reserved */
        vuint32_t AEIM_XPT_STA:2;    /**< \brief [25:24] AEIM exception status (rw) */
        vuint32_t reserved_16:8;    /**< \brief [23:16] \internal Reserved */
        vuint32_t AEIM_XPT_ADDR:16;    /**< \brief [15:0] Exception Address (rw) */
    } B;
} GTM_CCM_AEIM_STA;

typedef union _GTM_CCM_HW_CONF {
    vuint32_t R;
    struct {
        vuint32_t AEI_RDATA_PIPELINE_STAGE:1;    /**< \brief [31:31] Read data pipeline stage implemented */
        vuint32_t AEI_ADDR_PIPELINE_STAGE:1;  /**< \brief [30:30] Address pipeline stage implemented (r) */
        vuint32_t INT_CLK_EN_GEN:1;    /**< \brief [29:29] Internal clock enable generation (r) */
        vuint32_t TOM_TRIG_INTCHAIN:5;    /**< \brief [28:24] TOM internal trigger chain length without synchronization register (r) */
        vuint32_t ATOM_TRIG_INTCHAIN:4;    /**< \brief [23:20] ATOM internal trigger chain length without synchronization register (r) */
        vuint32_t IRQ_MODE_SINGLE_PULSE:1;    /**< \brief [19:19] IRQ_MODE_SINGLE_PULSE (r) */
        vuint32_t IRQ_MODE_PULSE_NOTIFY:1;    /**< \brief [18:18] IRQ_MODE_PULSE_NOTIFY (r) */
        vuint32_t IRQ_MODE_PULSE:1;    /**< \brief [17:17] IRQ_MODE_PULSE (r) */
        vuint32_t IRQ_MODE_LEVEL:1;    /**< \brief [16:16] IRQ_MODE_LEVEL (r) */
        vuint32_t RESET_ACTIVE:1;    /**< \brief [15:15] Active level of asynchronous reset (r) */
        vuint32_t reserved_14:1;    /**< \brief [14:14] \internal Reserved */
        vuint32_t ERM:1;           /**< \brief [13:13] Enable RAM1 MSB for available MCS modules (r) */
        vuint32_t RAM_INIT_RST:1;    /**< \brief [12:12] RAM initialization from reset (r) */
        vuint32_t TOM_TRIG_CHAIN:3;    /**< \brief [11:9] TOM trigger chain length without synchronization register (r) */
        vuint32_t TOM_OUT_RST:1;    /**< \brief [8:8] TOM_OUT reset level (r) */
        vuint32_t ATOM_TRIG_CHAIN:3;    /**< \brief [7:5] ATOM trigger chain length without synchronization register (r) */
        vuint32_t ATOM_OUT_RST:1;    /**< \brief [4:4] ATOM_OUT reset level (r) */
        vuint32_t CFG_CLOCK_RATE:1;    /**< \brief [3:3] Clocks per ARU transfer (r) */
        vuint32_t SYNC_INPUT_REG:1;    /**< \brief [2:2] Additional pipelined stage in synchronous bridge mode (r) */
        vuint32_t BRIDGE_MODE_RST:1;    /**< \brief [1:1] Bridge mode after reset (r) */
        vuint32_t GRSTEN:1;        /**< \brief [0:0] Global Reset Enable (r) */
    } B;
} GTM_CCM_HW_CONF;

typedef union _GTM_CCM_TIM_AUX_IN_SRC {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t SEL_OUT_N_CH7:1;    /**< \brief [23:23] Use DTM_OUT or DTM_OUT_N signals as AUX_IN source of TIM[i] channel 7 (rw) */
        vuint32_t SEL_OUT_N_CH6:1;    /**< \brief [22:22] Use DTM_OUT or DTM_OUT_N signals as AUX_IN source of TIM[i] channel 6 (rw) */
        vuint32_t SEL_OUT_N_CH5:1;    /**< \brief [21:21] Use DTM_OUT or DTM_OUT_N signals as AUX_IN source of TIM[i] channel 5 (rw) */
        vuint32_t SEL_OUT_N_CH4:1;    /**< \brief [20:20] Use DTM_OUT or DTM_OUT_N signals as AUX_IN source of TIM[i] channel 4 (rw) */
        vuint32_t SEL_OUT_N_CH3:1;    /**< \brief [19:19] Use DTM_OUT or DTM_OUT_N signals as AUX_IN source of TIM[i] channel 3 (rw) */
        vuint32_t SEL_OUT_N_CH2:1;    /**< \brief [18:18] Use DTM_OUT or DTM_OUT_N signals as AUX_IN source of TIM[i] channel 2 (rw) */
        vuint32_t SEL_OUT_N_CH1:1;    /**< \brief [17:17] Use DTM_OUT or DTM_OUT_N signals as AUX_IN source of TIM[i] channel 1 (rw) */
        vuint32_t SEL_OUT_N_CH0:1;    /**< \brief [16:16] Use DTM_OUT or DTM_OUT_N signals as AUX_IN source of TIM[i] channel 0 (rw) */
        vuint32_t reserved_8:8;    /**< \brief [15:8] \internal Reserved */
        vuint32_t SRC_CH7:1;       /**< \brief [7:7] Defines AUX_IN source of TIM[i] channel 7 (rw) */
        vuint32_t SRC_CH6:1;       /**< \brief [6:6] Defines AUX_IN source of TIM[i] channel 6 (rw) */
        vuint32_t SRC_CH5:1;       /**< \brief [5:5] Defines AUX_IN source of TIM[i] channel 5 (rw) */
        vuint32_t SRC_CH4:1;       /**< \brief [4:4] Defines AUX_IN source of TIM[i] channel 4 (rw) */
        vuint32_t SRC_CH3:1;       /**< \brief [3:3] Defines AUX_IN source of TIM[i] channel 3 (rw) */
        vuint32_t SRC_CH2:1;       /**< \brief [2:2] Defines AUX_IN source of TIM[i] channel 2 (rw) */
        vuint32_t SRC_CH1:1;       /**< \brief [1:1] Defines AUX_IN source of TIM[i] channel 1 (rw) */
        vuint32_t SRC_CH0:1;       /**< \brief [0:0] Defines AUX_IN source of TIM[i] channel 0 (rw) */
    } B;
} GTM_CCM_TIM_AUX_IN_SRC;

typedef union _GTM_CCM_EXT_CAP_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t TIM_IP1_EXT_CAP_EN:8;    /**< \brief [15:8] TIM[i+1]_EXT_CAPTURE signal forwarding enable (rw) */
        vuint32_t TIM_I_EXT_CAP_EN:8;    /**< \brief [7:0] TIM[i]_EXT_CAPTURE signal forwarding enable (rw) */
    } B;
} GTM_CCM_EXT_CAP_EN;

typedef union _GTM_CCM_TOM_OUT {
    vuint32_t R;
    struct {
        vuint32_t TOM_OUT_N:16;    /**< \brief [31:16] Output level snapshot of TOM[i]_OUT_N all channels (r) */
        vuint32_t TOM_OUT:16;      /**< \brief [15:0] Output level snapshot of TOM[i]_OUT all channels (r) */
    } B;
} GTM_CCM_TOM_OUT;

typedef union _GTM_CCM_ATOM_OUT {
    vuint32_t R;
    struct {
        vuint32_t ATOM_IP1_OUT_N:8;    /**< \brief [31:24] Output level snapshot of ATOM[i+1]_OUT_N all channels (r) */
        vuint32_t ATOM_IP1_OUT:8;    /**< \brief [23:16] Output level snapshot of ATOM[i+1]_OUT all channels (r) */
        vuint32_t ATOM_I_OUT_N:8;    /**< \brief [15:8] Output level snapshot of ATOM[i]_OUT_N all channels (r) */
        vuint32_t ATOM_I_OUT:8;    /**< \brief [7:0] Output level snapshot of ATOM[i]_OUT all channels (r) */
    } B;
} GTM_CCM_ATOM_OUT;

typedef union _GTM_CCM_CMU_CLK_CFG {
    vuint32_t R;
    struct {
        vuint32_t reserved_30:2;    /**< \brief [31:30] \internal Reserved */
        vuint32_t CLK7_SRC:2;      /**< \brief [29:28] Clock 7 source signal selector (rw) */
        vuint32_t reserved_26:2;    /**< \brief [27:26] \internal Reserved */
        vuint32_t CLK6_SRC:2;      /**< \brief [25:24] Clock 6 source signal selector (rw) */
        vuint32_t reserved_22:2;    /**< \brief [23:22] \internal Reserved */
        vuint32_t CLK5_SRC:2;      /**< \brief [21:20] Clock 5 source signal selector (rw) */
        vuint32_t reserved_18:2;    /**< \brief [19:18] \internal Reserved */
        vuint32_t CLK4_SRC:2;      /**< \brief [17:16] Clock 4 source signal selector (rw) */
        vuint32_t reserved_14:2;    /**< \brief [15:14] \internal Reserved */
        vuint32_t CLK3_SRC:2;      /**< \brief [13:12] Clock 3 source signal selector (rw) */
        vuint32_t reserved_10:2;    /**< \brief [11:10] \internal Reserved */
        vuint32_t CLK2_SRC:2;      /**< \brief [9:8] Clock 2 source signal selector (rw) */
        vuint32_t reserved_6:2;    /**< \brief [7:6] \internal Reserved */
        vuint32_t CLK1_SRC:2;      /**< \brief [5:4] Clock 1 source signal selector (rw) */
        vuint32_t reserved_2:2;    /**< \brief [3:2] \internal Reserved */
        vuint32_t CLK0_SRC:2;      /**< \brief [1:0] Clock 0 source signal selector (rw) */
    } B;
} GTM_CCM_CMU_CLK_CFG;

typedef union _GTM_CCM_CMU_FXCLK_CFG {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;    /**< \brief [31:4] \internal Reserved */
        vuint32_t FXCLK0_SRC:4;    /**< \brief [3:0] Fixed clock 0 source signal selector (rw) */
    } B;
} GTM_CCM_CMU_FXCLK_CFG;

typedef union _GTM_CCM_CFG {
    vuint32_t R;
    struct {
        vuint32_t TBU_DIR2:1;      /**< \brief [31:31] DIR2 input signal of module TBU (r) */
        vuint32_t TBU_DIR1:1;      /**< \brief [30:30] DIR1 input signal of module TBU (r) */
        vuint32_t reserved_18:12;    /**< \brief [29:18] \internal Reserved */
        vuint32_t CLS_CLK_DIV:2;    /**< \brief [17:16] Cluster Clock Divider (r) */
        vuint32_t reserved_9:7;    /**< \brief [15:9] \internal Reserved */
        vuint32_t EN_TIO_DTM:1;    /**< \brief [8:8]Enable TIO and connected DTM (rw) */
        vuint32_t EN_CMP_MON:1;    /**< \brief [7:7] Enable CMP and MON (rw) */
        vuint32_t EN_PSM:1;        /**< \brief [6:6] Enable PSM (rw) */
        vuint32_t EN_BRC:1;        /**< \brief [5:5] Enable BRC (rw) */
        vuint32_t EN_DPLL_MAP:1;    /**< \brief [4:4] Enable DPLL and MAP (rw) */
        vuint32_t EN_MCS:1;        /**< \brief [3:3] Enable MCS (rw) */
        vuint32_t EN_ATOM_ADTM:1;    /**< \brief [2:2] Enable ATOM and ADTM (rw) */
        vuint32_t EN_TOM_SPE_TDTM:1;    /**< \brief [1:1] Enable TOM, SPE and TDTM (rw) */
        vuint32_t EN_TIM:1;        /**< \brief [0:0] Enable TIM (rw) */
    } B;
} GTM_CCM_CFG;

typedef union _GTM_CCM_PROT {
    vuint32_t R;
    struct {
        vuint32_t reserved_1:31;    /**< \brief [31:1] \internal Reserved */
        vuint32_t CLS_PROT:1;      /**< \brief [0:0] Cluster Protection (rw) */
    } B;
} GTM_CCM_PROT;

typedef volatile struct _GTM_CCM {
       GTM_CCM_ARP                     ARP[10];                /**< \brief 0, */
       vuint8_t                   reserved_50[0x17C];     /**< \brief 50, \internal Reserved */
       GTM_CCM_TIO_G0_OUT              TIO_G0_OUT;             /**< \brief 1CC, CCM${i} TIO Group 0,1 Output Register*/
       GTM_CCM_TIO_G2_OUT              TIO_G2_OUT;             /**< \brief 1D0, CCM${i} TIO Group 2 Output Register*/
       GTM_CCM_HW_CONF2                HW_CONF2;               /**< \brief 1D4, CCM${i} 2. Hardware Configuration Register*/
       GTM_CCM_AEIM_STA                AEIM_STA;               /**< \brief 1D8, CCM${i} MCS Bus Master Status Register*/
       GTM_CCM_HW_CONF                 HW_CONF;                /**< \brief 1DC, CCM${i} Hardware Configuration Register*/
       GTM_CCM_TIM_AUX_IN_SRC          TIM_AUX_IN_SRC;         /**< \brief 1E0, CCM${i} TIM Module AUX_IN Source Selection Register*/
       GTM_CCM_EXT_CAP_EN              EXT_CAP_EN;             /**< \brief 1E4, CCM${i} External Capture Trigger Enable Register*/
       GTM_CCM_TOM_OUT                 TOM_OUT;                /**< \brief 1E8, CCM${i} TOM Output Level Register*/
       GTM_CCM_ATOM_OUT                ATOM_OUT;               /**< \brief 1EC, CCM${i} ATOM Output Level Register*/
       GTM_CCM_CMU_CLK_CFG             CMU_CLK_CFG;            /**< \brief 1F0, CCM${i} CMU Clock Configuration Register*/
       GTM_CCM_CMU_FXCLK_CFG           CMU_FXCLK_CFG;          /**< \brief 1F4, CCM${i} CMU Fixed Clock Configuration Register*/
       GTM_CCM_CFG                     CFG;                    /**< \brief 1F8, CCM${i} Configuration Register*/
       GTM_CCM_PROT                    PROT;                   /**< \brief 1FC, CCM${i} Protection Register*/
       vuint8_t                   reserved_200[0x200];    /**< \brief 200, \internal Reserved */
} GTM_CCM;

/* ============================================================================
   =============================== Module: GTM_CDTM ================================
   ============================================================================ */
typedef union _GTM_CDTM_DTM_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_17:15;    /**< \brief [31:17] \internal Reserved */
        vuint32_t SHUT_OFF_RST:1;    /**< \brief [16:16] Shut off reset (rw) */
        vuint32_t reserved_9:7;    /**< \brief [15:9] \internal Reserved */
        vuint32_t SR_UPD_EN:1;     /**< \brief [8:8] Shadow register update enable (rw) */
        vuint32_t reserved_7:1;    /**< \brief [7:7] \internal Reserved */
        vuint32_t UPD_MODE:3;      /**< \brief [6:4] Update mode (rw) */
        vuint32_t DTM_SEL:2;       /**< \brief [3:2] Select DTM update and SHUT_OFF reset signal (rw) */
        vuint32_t CLK_SEL:2;       /**< \brief [1:0] Clock source select (rw) */
    } B;
} GTM_CDTM_DTM_CTRL;

typedef union _GTM_CDTM_DTM_CH_CTRL1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_30:2;    /**< \brief [31:30] \internal Reserved */
        vuint32_t O1F_3:2;         /**< \brief [29:28] Output 1 function channel 3 (rw) */
        vuint32_t SWAP_3:1;        /**< \brief [27:27] Swap outputs DTM[i]_CH[3]_OUT0 and DTM[i]_CH[3]_OUT1 (before final output register) (rw) */
        vuint32_t SH_EN_3:1;       /**< \brief [26:26] Shift enable channel 3 (rw) */
        vuint32_t I1SEL_3:1;       /**< \brief [25:25] Input 1 select channel 3 (rw) */
        vuint32_t O1SEL_3:1;       /**< \brief [24:24] Output 1 select channel 3 (rw) */
        vuint32_t reserved_23:1;    /**< \brief [23:23] \internal Reserved */
        vuint32_t XDT_EN_2_3:1;    /**< \brief [22:22] Cross dead time enable on channels 0 and 1 (rw) */
        vuint32_t O1F_2:2;         /**< \brief [21:20] Output 1 function channel 2 (rw) */
        vuint32_t SWAP_2:1;        /**< \brief [19:19] Swap outputs DTM[i]_CH[2]_OUT0 and DTM[i]_CH[2]_OUT1 (before final output register) (rw) */
        vuint32_t SH_EN_2:1;       /**< \brief [18:18] Shift enable channel 2 (rw) */
        vuint32_t I1SEL_2:1;       /**< \brief [17:17] Input 1 select channel 2 (rw) */
        vuint32_t O1SEL_2:1;       /**< \brief [16:16] Output 1 select channel 2 (rw) */
        vuint32_t reserved_14:2;    /**< \brief [15:14] \internal Reserved */
        vuint32_t O1F_1:2;         /**< \brief [13:12] Output 1 function channel 1 (rw) */
        vuint32_t SWAP_1:1;        /**< \brief [11:11] Swap outputs DTM[i]_CH[1]_OUT0 and DTM[i]_CH[1]_OUT1 (before final output register) (rw) */
        vuint32_t SH_EN_1:1;       /**< \brief [10:10] Shift enable channel 1 (rw) */
        vuint32_t I1SEL_1:1;       /**< \brief [9:9] Input 1 select channel 1 (rw) */
        vuint32_t O1SEL_1:1;       /**< \brief [8:8] Output 1 select channel 1 (rw) */
        vuint32_t reserved_7:1;    /**< \brief [7:7] \internal Reserved */
        vuint32_t XDT_EN_0_1:1;    /**< \brief [6:6] Cross dead time enable on channels 0 and 1 (rw) */
        vuint32_t O1F_0:2;         /**< \brief [5:4] Output 1 function channel 0 (rw) */
        vuint32_t SWAP_0:1;        /**< \brief [3:3] Swap outputs DTM[i]_CH[0]_OUT0 and DTM[i]_CH[0]_OUT1 (before final output register) (rw) */
        vuint32_t reserved_2:1;    /**< \brief [2:2] \internal Reserved */
        vuint32_t I1SEL_0:1;       /**< \brief [1:1] Input 1 select channel 0 (rw) */
        vuint32_t O1SEL_0:1;       /**< \brief [0:0] Output 1 select channel 0 (rw) */
    } B;
} GTM_CDTM_DTM_CH_CTRL1;

typedef union _GTM_CDTM_DTM_CH_CTRL2 {
    vuint32_t R;
    struct {
        vuint32_t DT1_3:1;         /**< \brief [31:31] Dead time path enable on output 1 channel 3 (rw) */
        vuint32_t SL1_3:1;         /**< \brief [30:30] Signal level on output 1 channel 3 (rw) */
        vuint32_t OC1_3:1;         /**< \brief [29:29] Output 1 control channel 3 (rw) */
        vuint32_t POL1_3:1;        /**< \brief [28:28] Polarity on output 1 channel 3 (rw) */
        vuint32_t DT0_3:1;         /**< \brief [27:27] Dead time path enable on output 0 channel 3 (rw) */
        vuint32_t SL0_3:1;         /**< \brief [26:26] Signal level on output 0 channel 3 (rw) */
        vuint32_t OC0_3:1;         /**< \brief [25:25] Output 0 control channel 3 (rw) */
        vuint32_t POL0_3:1;        /**< \brief [24:24] Polarity on output 0 channel 3 (rw) */
        vuint32_t DT1_2:1;         /**< \brief [23:23] Dead time path enable on output 1 channel 2 (rw) */
        vuint32_t SL1_2:1;         /**< \brief [22:22] Signal level on output 1 channel 2 (rw) */
        vuint32_t OC1_2:1;         /**< \brief [21:21] Output 1 control channel 2 (rw) */
        vuint32_t POL1_2:1;        /**< \brief [20:20] Polarity on output 1 channel 2 (rw) */
        vuint32_t DT0_2:1;         /**< \brief [19:19] Dead time path enable on output 0 channel 2 (rw) */
        vuint32_t SL0_2:1;         /**< \brief [18:18] Signal level on output 0 channel 2 (rw) */
        vuint32_t OC0_2:1;         /**< \brief [17:17] Output 0 control channel 2 (rw) */
        vuint32_t POL0_2:1;        /**< \brief [16:16] Polarity on output 0 channel 2 (rw) */
        vuint32_t DT1_1:1;         /**< \brief [15:15] Dead time path enable on output 1 channel 1 (rw) */
        vuint32_t SL1_1:1;         /**< \brief [14:14] Signal level on output 1 channel 1 (rw) */
        vuint32_t OC1_1:1;         /**< \brief [13:13] Output 1 control channel 1 (rw) */
        vuint32_t POL1_1:1;        /**< \brief [12:12] Polarity on output 1 channel 1 (rw) */
        vuint32_t DT0_1:1;         /**< \brief [11:11] Dead time path enable on output 0 channel 1 (rw) */
        vuint32_t SL0_1:1;         /**< \brief [10:10] Signal level on output 0 channel 1 (rw) */
        vuint32_t OC0_1:1;         /**< \brief [9:9] Output 0 control channel 1 (rw) */
        vuint32_t POL0_1:1;        /**< \brief [8:8] Polarity on output 0 channel 1 (rw) */
        vuint32_t DT1_0:1;         /**< \brief [7:7] Dead time path enable on output 1 channel 0 (rw) */
        vuint32_t SL1_0:1;         /**< \brief [6:6] Signal level on output 1 channel 0 (rw) */
        vuint32_t OC1_0:1;         /**< \brief [5:5] Output 1 control channel 0 (rw) */
        vuint32_t POL1_0:1;        /**< \brief [4:4] Polarity on output 1 channel 0 (rw) */
        vuint32_t DT0_0:1;         /**< \brief [3:3] Dead time path enable on output 0 channel 0 (rw) */
        vuint32_t SL0_0:1;         /**< \brief [2:2] Signal level on output 0 channel 0 (rw) */
        vuint32_t OC0_0:1;         /**< \brief [1:1] Output 0 control channel 0 (rw) */
        vuint32_t POL0_0:1;        /**< \brief [0:0] Polarity on output 0 channel 0 (rw) */
    } B;
} GTM_CDTM_DTM_CH_CTRL2;

typedef union _GTM_CDTM_DTM_CH_CTRL2_SR {
    vuint32_t R;
    struct {
        vuint32_t DT1_3_SR:1;      /**< \brief [31:31] Dead time path enable on output 1 channel 3 shadow register (rw) */
        vuint32_t SL1_3_SR:1;      /**< \brief [30:30] Signal level on output 1 channel 3 shadow register (rw) */
        vuint32_t OC1_3_SR:1;      /**< \brief [29:29] Output 1 control channel 3 shadow register (rw) */
        vuint32_t POL1_3_SR:1;     /**< \brief [28:28] Polarity on output 1 channel 3 shadow register (rw) */
        vuint32_t DT0_3_SR:1;      /**< \brief [27:27] Dead time path enable on output 0 channel 3 shadow register (rw) */
        vuint32_t SL0_3_SR:1;      /**< \brief [26:26] Signal level on output 0 channel 3 shadow register (rw) */
        vuint32_t OC0_3_SR:1;      /**< \brief [25:25] Output 0 control channel 3 shadow register (rw) */
        vuint32_t POL0_3_SR:1;     /**< \brief [24:24] Polarity on output 0 channel 3 shadow register (rw) */
        vuint32_t DT1_2_SR:1;      /**< \brief [23:23] Dead time path enable on output 1 channel 2 shadow register (rw) */
        vuint32_t SL1_2_SR:1;      /**< \brief [22:22] Signal level on output 1 channel 2 shadow register (rw) */
        vuint32_t OC1_2_SR:1;      /**< \brief [21:21] Output 1 control channel 2 shadow register (rw) */
        vuint32_t POL1_2_SR:1;     /**< \brief [20:20] Polarity on output 1 channel 2 shadow register (rw) */
        vuint32_t DT0_2_SR:1;      /**< \brief [19:19] Dead time path enable on output 0 channel 2 shadow register (rw) */
        vuint32_t SL0_2_SR:1;      /**< \brief [18:18] Signal level on output 0 channel 2 shadow register (rw) */
        vuint32_t OC0_2_SR:1;      /**< \brief [17:17] Output 0 control channel 2 shadow register (rw) */
        vuint32_t POL0_2_SR:1;     /**< \brief [16:16] Polarity on output 0 channel 2 shadow register (rw) */
        vuint32_t DT1_1_SR:1;      /**< \brief [15:15] Dead time path enable on output 1 channel 1 shadow register (rw) */
        vuint32_t SL1_1_SR:1;      /**< \brief [14:14] Signal level on output 1 channel 1 shadow register (rw) */
        vuint32_t OC1_1_SR:1;      /**< \brief [13:13] Output 1 control channel 1 shadow register (rw) */
        vuint32_t POL1_1_SR:1;     /**< \brief [12:12] Polarity on output 1 channel 1 shadow register (rw) */
        vuint32_t DT0_1_SR:1;      /**< \brief [11:11] Dead time path enable on output 0 channel 1 shadow register (rw) */
        vuint32_t SL0_1_SR:1;      /**< \brief [10:10] Signal level on output 0 channel 1 shadow register (rw) */
        vuint32_t OC0_1_SR:1;      /**< \brief [9:9] Output 0 control channel 1 shadow register (rw) */
        vuint32_t POL0_1_SR:1;     /**< \brief [8:8] Polarity on output 0 channel 1 shadow register (rw) */
        vuint32_t DT1_0_SR:1;      /**< \brief [7:7] Dead time path enable on output 1 channel 0 shadow register (rw) */
        vuint32_t SL1_0_SR:1;      /**< \brief [6:6] Signal level on output 1 channel 0 shadow register (rw) */
        vuint32_t OC1_0_SR:1;      /**< \brief [5:5] Output 1 control channel 0 shadow register (rw) */
        vuint32_t POL1_0_SR:1;     /**< \brief [4:4] Polarity on output 1 channel 0 shadow register (rw) */
        vuint32_t DT0_0_SR:1;      /**< \brief [3:3] Dead time path enable on output 0 channel 0 shadow register (rw) */
        vuint32_t SL0_0_SR:1;      /**< \brief [2:2] Signal level on output 0 channel 0 shadow register (rw) */
        vuint32_t OC0_0_SR:1;      /**< \brief [1:1] Output 0 control channel 0 shadow register (rw) */
        vuint32_t POL0_0_SR:1;     /**< \brief [0:0] Polarity on output 0 channel 0 shadow register (rw) */
    } B;
} GTM_CDTM_DTM_CH_CTRL2_SR;

typedef union _GTM_CDTM_DTM_PS_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_22:10;    /**< \brief [31:22] \internal Reserved */
        vuint32_t SHIFT_SEL:2;     /**< \brief [21:20] Shift select (rw) */
        vuint32_t reserved_19:1;    /**< \brief [19:19] \internal Reserved */
        vuint32_t TIM_SEL:1;       /**< \brief [18:18] TIM input selection (rw) */
        vuint32_t IN_POL:1;        /**< \brief [17:17] Input polarity (rw) */
        vuint32_t PSU_IN_SEL:1;    /**< \brief [16:16] PSU input selection (rw) */
        vuint32_t reserved_10:6;    /**< \brief [15:10] \internal Reserved */
        vuint32_t RELBLK:10;       /**< \brief [9:0] Reload value blanking window (rw) */
    } B;
} GTM_CDTM_DTM_PS_CTRL;

typedef union _GTM_CDTM_DTM_CH_DTV {
    vuint32_t R;
    struct {
        vuint32_t HRES:1;           /**< \brief [31:31] high resolution PWM support */
        vuint32_t reserved_29:2;    /**< \brief [30:29] \internal Reserved */
        vuint32_t RELFALL:13;       /**< \brief [28:16] Reload value for falling edge dead time (rw) */
        vuint32_t reserved_13:3;    /**< \brief [15:13] \internal Reserved */
        vuint32_t RELRISE:13;       /**< \brief [12:0] Reload value for rising edge dead time (rw) */
    } B;
} GTM_CDTM_DTM_CH_DTV;

typedef union _GTM_CDTM_DTM_CH_SR {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t SL1_3_SR_SR:1;    /**< \brief [7:7] Shadow register for bit SL1_3_SR of register DTM[i]_CH_CTRL2_SR (rw) */
        vuint32_t SL0_3_SR_SR:1;    /**< \brief [6:6] Shadow register for bit SL0_3_SR of register DTM[i]_CH_CTRL2_SR (rw) */
        vuint32_t SL1_2_SR_SR:1;    /**< \brief [5:5] Shadow register for bit SL1_2_SR of register DTM[i]_CH_CTRL2_SR (rw) */
        vuint32_t SL0_2_SR_SR:1;    /**< \brief [4:4] Shadow register for bit SL0_2_SR of register DTM[i]_CH_CTRL2_SR (rw) */
        vuint32_t SL1_1_SR_SR:1;    /**< \brief [3:3] Shadow register for bit SL1_1_SR of register DTM[i]_CH_CTRL2_SR (rw) */
        vuint32_t SL0_1_SR_SR:1;    /**< \brief [2:2] Shadow register for bit SL0_1_SR of register DTM[i]_CH_CTRL2_SR (rw) */
        vuint32_t SL1_0_SR_SR:1;    /**< \brief [1:1] Shadow register for bit SL1_0_SR of register DTM[i]_CH_CTRL2_SR (rw) */
        vuint32_t SL0_0_SR_SR:1;    /**< \brief [0:0] Shadow register for bit SL0_0_SR of register DTM[i]_CH_CTRL2_SR (rw) */
    } B;
} GTM_CDTM_DTM_CH_SR;

typedef union _GTM_CDTM_DTM_CH_CTRL3 {
    vuint32_t R;
    struct {
        vuint32_t reserved_28:4;    /**< \brief [31:28] \internal Reserved */
        vuint32_t TSEL1_3:1;       /**< \brief [27:27] Input selection combinational logic path (rw) */
        vuint32_t TSEL0_3:1;       /**< \brief [26:26] Input selection for dead time / edge trigger generation (rw) */
        vuint32_t CIS3:1;          /**< \brief [25:25] Combinational input select channel 3 (rw) */
        vuint32_t CII3:1;          /**< \brief [24:24] Combinational input invert channel 3 (rw) */
        vuint32_t reserved_20:4;    /**< \brief [23:20] \internal Reserved */
        vuint32_t TSEL1_2:1;       /**< \brief [19:19] Input selection combinational logic path (rw) */
        vuint32_t TSEL0_2:1;       /**< \brief [18:18] Input selection for dead time / edge trigger generation (rw) */
        vuint32_t CIS2:1;          /**< \brief [17:17] Combinational input select channel 2 (rw) */
        vuint32_t CII2:1;          /**< \brief [16:16] Combinational input invert channel 2 (rw) */
        vuint32_t reserved_12:4;    /**< \brief [15:12] \internal Reserved */
        vuint32_t TSEL1_1:1;       /**< \brief [11:11] Input selection combinational logic path (rw) */
        vuint32_t TSEL0_1:1;       /**< \brief [10:10] Input selection for dead time / edge trigger generation (rw) */
        vuint32_t CIS1:1;          /**< \brief [9:9] Combinational input select channel 1 (rw) */
        vuint32_t CII1:1;          /**< \brief [8:8] Combinational input invert channel 1 (rw) */
        vuint32_t reserved_4:4;    /**< \brief [7:4] \internal Reserved */
        vuint32_t TSEL1_0:1;       /**< \brief [3:3] Input selection combinational logic path (rw) */
        vuint32_t TSEL0_0:1;       /**< \brief [2:2] Input selection for dead time / edge trigger generation (rw) */
        vuint32_t CIS0:1;          /**< \brief [1:1] Combinational input select channel 0 (rw) */
        vuint32_t CII0:1;          /**< \brief [0:0] Combinational input invert channel 0 (rw) */
    } B;
} GTM_CDTM_DTM_CH_CTRL3;

typedef union _GTM_CDTM_DTM_CTRL2 {
    vuint32_t R;
    struct {
        vuint32_t WR_EN_3:1;             /**< \brief [31:31] Channel 3: Write enable of Bitfields (rw) */
        vuint32_t SHUT_OFF_RST_3:1;      /**< \brief [30:30] Channel 3: Clear of internal signal SHUTOFF_SYNC_0 if selected as control source */
        vuint32_t UPD_MODE_3:2;          /**< \brief [29:28] Channel 3: Control the update mode of the internal SHUTOFF_SYNC_0 signal (rw) */
        vuint32_t SHUTOFF_POL_3:1;       /**< \brief [27:27] Channel 3: Configure if the selected shutoff input signal used as shutoff output signal is inverted or not (rw) */
        vuint32_t SHUTOFF_SEL_3:3;       /**< \brief [26:24] Channel 3: Select input signal to be used as shutoff signal (rw) */
        vuint32_t WR_EN_2:1;             /**< \brief [23:23] Channel 2: Write enable of Bitfields (rw) */
        vuint32_t SHUT_OFF_RST_2:1;      /**< \brief [22:22] Channel 2: Clear of internal signal SHUTOFF_SYNC_0 if selected as control source */
        vuint32_t UPD_MODE_2:2;          /**< \brief [21:20] Channel 2: Control the update mode of the internal SHUTOFF_SYNC_0 signal (rw) */
        vuint32_t SHUTOFF_POL_2:1;       /**< \brief [19:19] Channel 2: Configure if the selected shutoff input signal used as shutoff output signal is inverted or not (rw) */
        vuint32_t SHUTOFF_SEL_2:3;       /**< \brief [18:16] Channel 2: Select input signal to be used as shutoff signal (rw) */
        vuint32_t WR_EN_1:1;             /**< \brief [15:15] Channel 1: Write enable of Bitfields (rw) */
        vuint32_t SHUT_OFF_RST_1:1;      /**< \brief [14:14] Channel 1: Clear of internal signal SHUTOFF_SYNC_0 if selected as control source */
        vuint32_t UPD_MODE_1:2;          /**< \brief [13:12] Channel 1: Control the update mode of the internal SHUTOFF_SYNC_0 signal (rw) */
        vuint32_t SHUTOFF_POL_1:1;       /**< \brief [11:11] Channel 1: Configure if the selected shutoff input signal used as shutoff output signal is inverted or not (rw) */
        vuint32_t SHUTOFF_SEL_1:3;       /**< \brief [10:8] Channel 1: Select input signal to be used as shutoff signal (rw) */
        vuint32_t WR_EN_0:1;             /**< \brief [7:7] Channel 0: Write enable of Bitfields (rw) */
        vuint32_t SHUT_OFF_RST_0:1;      /**< \brief [6:6] Channel 0: Clear of internal signal SHUTOFF_SYNC_0 if selected as control source */
        vuint32_t UPD_MODE_0:2;          /**< \brief [5:4] Channel 0: Control the update mode of the internal SHUTOFF_SYNC_0 signal (rw) */
        vuint32_t SHUTOFF_POL_0:1;       /**< \brief [3:3] Channel 0: Configure if the selected shutoff input signal used as shutoff output signal is inverted or not (rw) */
        vuint32_t SHUTOFF_SEL_0:3;       /**< \brief [2:0] Channel 0: Select input signal to be used as shutoff signal (rw) */
    } B;
} GTM_CDTM_DTM_CTRL2;

typedef union _GTM_CDTM_DTM_CH_DTV_SR {
    vuint32_t R;
    struct {
        vuint32_t RELFALL_UPD_EN:1;    /**< \brief [31:31] Control bit to enable update of CDTM[i]_DTM[d]_CH[x]_DTV.RELFALL */
        vuint32_t RELFALL_UPD_FE0RE1:1;/**< \brief [30:30] Control if falling edge or rising edge triggers update of CDTM[i]_DTM[d]_CH[x]_DTV.RELFALL (rw) */
        vuint32_t reserved_29:1;       /**< \brief [29:29] \internal Reserved */
        vuint32_t RELFALL_SR:13;       /**< \brief [28:16] Reload value for falling edge dead time (rw) */
        vuint32_t RELRISE_UPD_EN:1;    /**< \brief [15:15] Control bit to enable update of CDTM[i]_DTM[d]_CH[x]_DTV.RELRISE */
        vuint32_t RELRISE_UPD_FE0RE1:1;/**< \brief [14:14] Control if falling edge or rising edge triggers update of CDTM[i]_DTM[d]_CH[x]_DTV.RELRISE */
        vuint32_t reserved_13:1;       /**< \brief [13:13] \internal Reserved */
        vuint32_t RELRISE_SR:13;       /**< \brief [12:0] Reload value for rising edge dead time (rw) */
    } B;
} GTM_CDTM_DTM_CH_DTV_SR;

typedef volatile struct _GTM_CDTM_DTM {
       GTM_CDTM_DTM_CTRL               CTRL;                   /**< \brief 0, CDTM${i} DTM${j} Global Configuration and Control Register*/
       GTM_CDTM_DTM_CH_CTRL1           CH_CTRL1;               /**< \brief 4, CDTM${i} DTM${j} Channel Control Register 1*/
       GTM_CDTM_DTM_CH_CTRL2           CH_CTRL2;               /**< \brief 8, CDTM${i} DTM${j} Channel Control Register 2*/
       GTM_CDTM_DTM_CH_CTRL2_SR        CH_CTRL2_SR;            /**< \brief C, CDTM${i} DTM${j} Channel Control Register 2 Shadow*/
       GTM_CDTM_DTM_PS_CTRL            PS_CTRL;                /**< \brief 10, CDTM${i} DTM${j} Phase Shift Unit Configuration and Control Register*/
       GTM_CDTM_DTM_CH_DTV             CH_DTV[4];              /**< \brief 14, CDTM${i} DTM${j} Channel ${z} Dead Time Reload Values*/
       GTM_CDTM_DTM_CH_SR              CH_SR;                  /**< \brief 24, CDTM${i} DTM${j} Channel Shadow Register*/
       GTM_CDTM_DTM_CH_CTRL3           CH_CTRL3;               /**< \brief 28, CDTM${i} DTM${j} Channel Control Register 3*/
       GTM_CDTM_DTM_CTRL2              CTRL2;                  /**< \brief 2C, CDTM${i} DTM${j} Global configuration and control register 2*/
       GTM_CDTM_DTM_CH_DTV_SR          CH_DTV_SR[4];           /**< \brief 30, CDTM${i} DTM${j} Channel ${z} Dead Time shadow Values*/
} GTM_CDTM_DTM;

typedef volatile struct _GTM_CDTM {
       GTM_CDTM_DTM                    DTM[12];                 /**< \brief 0, */
       vuint8_t                   reserved_300[0x100];     /**< \brief 300, \internal Reserved */
} GTM_CDTM;

/* ============================================================================
   =============================== Module: GTM_PSM ================================
   ============================================================================ */
typedef union _GTM_PSM_F2A_RD_CH_ARU_RD_FIFO {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;    /**< \brief [31:9] \internal Reserved */
        vuint32_t ADDR:9;          /**< \brief [8:0] ARU Read address (rw) */
    } B;
} GTM_PSM_F2A_RD_CH_ARU_RD_FIFO;

typedef volatile struct _GTM_PSM_F2A_RD_CH {
       GTM_PSM_F2A_RD_CH_ARU_RD_FIFO   ARU_RD_FIFO;            /**< \brief 0, F2A${i} Stream ${z} Read Address Register*/
} GTM_PSM_F2A_RD_CH;

typedef union _GTM_PSM_F2A_STR_CH_STR_CFG {
    vuint32_t R;
    struct {
        vuint32_t reserved_19:13;    /**< \brief [31:19] \internal Reserved */
        vuint32_t DIR:1;           /**< \brief [18:18] Data transfer direction (rw) */
        vuint32_t TMODE:2;         /**< \brief [17:16] Transfer mode for 53 bit ARU data from/to FIFO (rw) */
        vuint32_t reserved_0:16;    /**< \brief [15:0] \internal Reserved */
    } B;
} GTM_PSM_F2A_STR_CH_STR_CFG;

typedef volatile struct _GTM_PSM_F2A_STR_CH {
       GTM_PSM_F2A_STR_CH_STR_CFG      STR_CFG;                /**< \brief 0, F2A${i} Stream ${z} Configuration Register*/
} GTM_PSM_F2A_STR_CH;

typedef union _GTM_PSM_F2A_ENABLE {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t STR7_EN:2;       /**< \brief [15:14] Enable/disable stream 7 (rw) */
        vuint32_t STR6_EN:2;       /**< \brief [13:12] Enable/disable stream 6 (rw) */
        vuint32_t STR5_EN:2;       /**< \brief [11:10] Enable/disable stream 5 (rw) */
        vuint32_t STR4_EN:2;       /**< \brief [9:8] Enable/disable stream 4 (rw) */
        vuint32_t STR3_EN:2;       /**< \brief [7:6] Enable/disable stream 3 (rw) */
        vuint32_t STR2_EN:2;       /**< \brief [5:4] Enable/disable stream 2 (rw) */
        vuint32_t STR1_EN:2;       /**< \brief [3:2] Enable/disable stream 1 (rw) */
        vuint32_t STR0_EN:2;       /**< \brief [1:0] Enable/disable stream 0 (rw) */
    } B;
} GTM_PSM_F2A_ENABLE;

typedef union _GTM_PSM_F2A_F2A_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t STR7_CONF:2;     /**< \brief [7:6] Reconfiguration of stream 7 to FIFO channel 3 (rw) */
        vuint32_t STR6_CONF:2;     /**< \brief [5:4] Reconfiguration of stream 6 to FIFO channel 2 (rw) */
        vuint32_t STR5_CONF:2;     /**< \brief [3:2] Reconfiguration of stream 5 to FIFO channel 1 (rw) */
        vuint32_t STR4_CONF:2;     /**< \brief [1:0] Reconfiguration of stream 4 to FIFO channel 0 (rw) */
    } B;
} GTM_PSM_F2A_F2A_CTRL;

typedef volatile struct _GTM_PSM_F2A {
       GTM_PSM_F2A_RD_CH               RD_CH[8];               /**< \brief 0, F2A${i} Stream ${z} Read Address Register*/
       GTM_PSM_F2A_STR_CH              STR_CH[8];              /**< \brief 20, F2A${i} Stream ${z} Configuration Register*/
       GTM_PSM_F2A_ENABLE              ENABLE;                 /**< \brief 40, F2A${i} Stream Activation Register*/
       GTM_PSM_F2A_F2A_CTRL            F2A_CTRL;               /**< \brief 44, F2A${i} Stream Control Register*/
} GTM_PSM_F2A;

typedef union _GTM_PSM_AFD_CH_BUF_ACC {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;    /**< \brief [31:29] \internal Reserved */
        vuint32_t DATA:29;         /**< \brief [28:0] Read/write data from/to FIFO (rw) */
    } B;
} GTM_PSM_AFD_CH_BUF_ACC;

typedef volatile struct _GTM_PSM_AFD_CH {
       GTM_PSM_AFD_CH_BUF_ACC          BUF_ACC;                /**< \brief 0, AFD ${i} FIFO ${x} Buffer Access Register*/
       vuint8_t                   reserved_4[12];         /**< \brief 4, \internal Reserved */
} GTM_PSM_AFD_CH;

typedef volatile struct _GTM_PSM_AFD {
       GTM_PSM_AFD_CH                  CH[8];                  /**< \brief 0, */
} GTM_PSM_AFD;

typedef union _GTM_PSM_FIFO_CH_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;    /**< \brief [31:4] \internal Reserved */
        vuint32_t WULOCK:1;        /**< \brief [3:3] RAM write unlock (rw) */
        vuint32_t FLUSH:1;         /**< \brief [2:2] FIFO Flush control (rw) */
        vuint32_t RAP:1;           /**< \brief [1:1] RAM access priority (rw) */
        vuint32_t RBM:1;           /**< \brief [0:0] Ring buffer mode enable (rw) */
    } B;
} GTM_PSM_FIFO_CH_CTRL;

typedef union _GTM_PSM_FIFO_CH_END_ADDR {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t ADDR:10;         /**< \brief [9:0] End address for FIFO channel z (rw) */
    } B;
} GTM_PSM_FIFO_CH_END_ADDR;

typedef union _GTM_PSM_FIFO_CH_START_ADDR {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t ADDR:10;         /**< \brief [9:0] Start address for FIFO channel z (rw) */
    } B;
} GTM_PSM_FIFO_CH_START_ADDR;

typedef union _GTM_PSM_FIFO_CH_UPPER_WM {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t ADDR:10;         /**< \brief [9:0] Upper watermark address for channel z (rw) */
    } B;
} GTM_PSM_FIFO_CH_UPPER_WM;

typedef union _GTM_PSM_FIFO_CH_LOWER_WM {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t ADDR:10;         /**< \brief [9:0] Lower watermark address for channel z (rw) */
    } B;
} GTM_PSM_FIFO_CH_LOWER_WM;

typedef union _GTM_PSM_FIFO_CH_STATUS {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;    /**< \brief [31:4] \internal Reserved */
        vuint32_t UP_WM:1;         /**< \brief [3:3] Upper watermark reached (r) */
        vuint32_t LOW_WM:1;        /**< \brief [2:2] Lower watermark reached (r) */
        vuint32_t FULL:1;          /**< \brief [1:1] FIFO is full (r) */
        vuint32_t EMPTY:1;         /**< \brief [0:0] FIFO is empty (r) */
    } B;
} GTM_PSM_FIFO_CH_STATUS;

typedef union _GTM_PSM_FIFO_CH_FILL_LEVEL {
    vuint32_t R;
    struct {
        vuint32_t reserved_11:21;    /**< \brief [31:11] \internal Reserved */
        vuint32_t LEVEL:11;        /**< \brief [10:0] Fill level of the current FIFO (r) */
    } B;
} GTM_PSM_FIFO_CH_FILL_LEVEL;

typedef union _GTM_PSM_FIFO_CH_WR_PTR {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t ADDR:10;         /**< \brief [9:0] Position of the write pointer (r) */
    } B;
} GTM_PSM_FIFO_CH_WR_PTR;

typedef union _GTM_PSM_FIFO_CH_RD_PTR {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t ADDR:10;         /**< \brief [9:0] Position of the read pointer (r) */
    } B;
} GTM_PSM_FIFO_CH_RD_PTR;

typedef union _GTM_PSM_FIFO_CH_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;    /**< \brief [31:4] \internal Reserved */
        vuint32_t FIFO_UWM:1;      /**< \brief [3:3] FIFO upper watermark was over-run (rw) */
        vuint32_t FIFO_LWM:1;      /**< \brief [2:2] FIFO lower watermark was under-run (rw) */
        vuint32_t FIFO_FULL:1;     /**< \brief [1:1] FIFO is full (rw) */
        vuint32_t FIFO_EMPTY:1;    /**< \brief [0:0] FIFO is empty (rw) */
    } B;
} GTM_PSM_FIFO_CH_IRQ_NOTIFY;

typedef union _GTM_PSM_FIFO_CH_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;    /**< \brief [31:4] \internal Reserved */
        vuint32_t FIFO_UWM_IRQ_EN:1;    /**< \brief [3:3] FIFO Upper Watermark interrupt enable (rw) */
        vuint32_t FIFO_LWM_IRQ_EN:1;    /**< \brief [2:2] FIFO Lower Watermark interrupt enable (rw) */
        vuint32_t FIFO_FULL_IRQ_EN:1;    /**< \brief [1:1] FIFO Full interrupt enable (rw) */
        vuint32_t FIFO_EMPTY_IRQ_EN:1;    /**< \brief [0:0] FIFO Empty interrupt enable (rw) */
    } B;
} GTM_PSM_FIFO_CH_IRQ_EN;

typedef union _GTM_PSM_FIFO_CH_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;    /**< \brief [31:4] \internal Reserved */
        vuint32_t TRG_FIFO_UWM:1;    /**< \brief [3:3] Force interrupt of Upper Watermark (rw) */
        vuint32_t TRG_FIFO_LWM:1;    /**< \brief [2:2] Force interrupt of Lower Watermark (rw) */
        vuint32_t TRG_FIFO_FULL:1;    /**< \brief [1:1] Force interrupt of FIFO Full status (rw) */
        vuint32_t TRG_FIFO_EMPTY:1;    /**< \brief [0:0] Force interrupt of FIFO Empty status (rw) */
    } B;
} GTM_PSM_FIFO_CH_IRQ_FORCINT;

typedef union _GTM_PSM_FIFO_CH_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;    /**< \brief [31:4] \internal Reserved */
        vuint32_t DMA_HYST_DIR:1;    /**< \brief [3:3] DMA direction in hysteresis mode (rw) */
        vuint32_t DMA_HYSTERESIS:1;    /**< \brief [2:2] Enable DMA hysteresis mode (rw) */
        vuint32_t IRQ_MODE:2;      /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_PSM_FIFO_CH_IRQ_MODE;

typedef union _GTM_PSM_FIFO_CH_EIRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;    /**< \brief [31:4] \internal Reserved */
        vuint32_t FIFO_UWM_EIRQ_EN:1;    /**< \brief [3:3] FIFO Upper Watermark error interrupt enable (rw) */
        vuint32_t FIFO_LWM_EIRQ_EN:1;    /**< \brief [2:2] FIFO Lower Watermark error interrupt enable (rw) */
        vuint32_t FIFO_FULL_EIRQ_EN:1;    /**< \brief [1:1] FIFO Full error interrupt enable (rw) */
        vuint32_t FIFO_EMPTY_EIRQ_EN:1;    /**< \brief [0:0] FIFO Empty error interrupt enable (rw) */
    } B;
} GTM_PSM_FIFO_CH_EIRQ_EN;

typedef volatile struct _GTM_PSM_FIFO_CH {
       GTM_PSM_FIFO_CH_CTRL            CTRL;                   /**< \brief 0, FIFO${i} Channel ${z} Control Register*/
       GTM_PSM_FIFO_CH_END_ADDR        END_ADDR;               /**< \brief 4, FIFO${i} Channel ${z} End Address Register*/
       GTM_PSM_FIFO_CH_START_ADDR      START_ADDR;             /**< \brief 8, FIFO${i} Channel ${z} Start Address Register*/
       GTM_PSM_FIFO_CH_UPPER_WM        UPPER_WM;               /**< \brief C, FIFO${i} Channel ${z} Upper Watermark Register*/
       GTM_PSM_FIFO_CH_LOWER_WM        LOWER_WM;               /**< \brief 10, FIFO${i} Channel ${z} Lower Watermark Register*/
       GTM_PSM_FIFO_CH_STATUS          STATUS;                 /**< \brief 14, FIFO${i} Channel ${z} Status Register*/
       GTM_PSM_FIFO_CH_FILL_LEVEL      FILL_LEVEL;             /**< \brief 18, FIFO${i} Channel ${z} Fill Level Register*/
       GTM_PSM_FIFO_CH_WR_PTR          WR_PTR;                 /**< \brief 1C, FIFO${i} Channel ${z} Write Pointer Register*/
       GTM_PSM_FIFO_CH_RD_PTR          RD_PTR;                 /**< \brief 20, FIFO${i} Channel ${z} Read Pointer Register*/
       GTM_PSM_FIFO_CH_IRQ_NOTIFY      IRQ_NOTIFY;             /**< \brief 24, FIFO${i} Channel ${z} Interrupt Notification Register*/
       GTM_PSM_FIFO_CH_IRQ_EN          IRQ_EN;                 /**< \brief 28, FIFO${i} Channel ${z} Interrupt Enable Register*/
       GTM_PSM_FIFO_CH_IRQ_FORCINT     IRQ_FORCINT;            /**< \brief 2C, FIFO${i} Channel ${z} Force Interrupt Register*/
       GTM_PSM_FIFO_CH_IRQ_MODE        IRQ_MODE;               /**< \brief 30, FIFO${i} Channel ${z} Interrupt Mode Control Register*/
       GTM_PSM_FIFO_CH_EIRQ_EN         EIRQ_EN;                /**< \brief 34, FIFO${i} Channel ${z} Error Interrupt Enable Register*/
       vuint8_t                   reserved_38[8];         /**< \brief 38, \internal Reserved */
} GTM_PSM_FIFO_CH;

typedef volatile struct _GTM_PSM_FIFO {
       GTM_PSM_FIFO_CH                 CH[8];                  /**< \brief 0, */
} GTM_PSM_FIFO;

typedef volatile struct _GTM_PSM {
       GTM_PSM_F2A                     F2A;                    /**< \brief 0, */
       vuint8_t                   reserved_48[0x38];      /**< \brief 48, \internal Reserved */
       GTM_PSM_AFD                     AFD;                    /**< \brief 80, */
       vuint8_t                   reserved_100[0x100];    /**< \brief 100, \internal Reserved */
       GTM_PSM_FIFO                    FIFO;                   /**< \brief 200, */
} GTM_PSM;

/* ============================================================================
   =============================== Module: GTM_SPE ================================
   ============================================================================ */

typedef union _GTM_SPE_CTRL_STAT {
    vuint32_t R;
    struct {
        vuint32_t FSOL:8;          /**< \brief [31:24] Fast Shutoff Level for TOM[i] channel 0 to 7 (rw) */
        vuint32_t ETRIG_SEL:1;     /**< \brief [23:23] Extended TRIG_SEL (rw) */
        vuint32_t NIP:3;           /**< \brief [22:20] New input pattern that was detected (r) */
        vuint32_t PDIR:1;          /**< \brief [19:19] Previous rotation direction (rw) */
        vuint32_t PIP:3;           /**< \brief [18:16] Previous input pattern that was detected by a regular input pattern change (rw) */
        vuint32_t ADIR:1;          /**< \brief [15:15] Actual rotation direction (rw) */
        vuint32_t AIP:3;           /**< \brief [14:12] Actual input pattern that was detected by a regular input pattern change (rw) */
        vuint32_t reserved_11:1;    /**< \brief [11:11] \internal Reserved */
        vuint32_t SPE_PAT_PTR:3;    /**< \brief [10:8] Pattern selector for TOM output signals (rw) */
        vuint32_t FSOM:1;          /**< \brief [7:7] Fast Shutoff Mode (rw) */
        vuint32_t TIM_SEL:1;       /**< \brief [6:6] Select TIM input signal (rw) */
        vuint32_t TRIG_SEL:2;      /**< \brief [5:4] Select trigger input signal (rw) */
        vuint32_t SIE2:1;          /**< \brief [3:3] SPE Input enable for TIM_CHz(48) (rw) */
        vuint32_t SIE1:1;          /**< \brief [2:2] SPE Input enable for TIM_CHy(48) (rw) */
        vuint32_t SIE0:1;          /**< \brief [1:1] SPE Input enable for TIM_CHx(48) (rw) */
        vuint32_t EN:1;            /**< \brief [0:0] SPE Submodule enable (rw) */
    } B;
} GTM_SPE_CTRL_STAT;

typedef union _GTM_SPE_PAT {
    vuint32_t R;
    struct {
        vuint32_t IP7_PAT:3;       /**< \brief [31:29] Input pattern 7 - IP7_PAT (rw) */
        vuint32_t IP7_VAL:1;       /**< \brief [28:28] Input pattern 7 is a valid pattern (rw) */
        vuint32_t IP6_PAT:3;       /**< \brief [27:25] Input pattern 6 - IP6_PAT (rw) */
        vuint32_t IP6_VAL:1;       /**< \brief [24:24] Input pattern 6 is a valid pattern (rw) */
        vuint32_t IP5_PAT:3;       /**< \brief [23:21] Input pattern 5 - IP5_PAT (rw) */
        vuint32_t IP5_VAL:1;       /**< \brief [20:20] Input pattern 5 is a valid pattern (rw) */
        vuint32_t IP4_PAT:3;       /**< \brief [19:17] Input pattern 4 - IP4_PAT (rw) */
        vuint32_t IP4_VAL:1;       /**< \brief [16:16] Input pattern 4 is a valid pattern (rw) */
        vuint32_t IP3_PAT:3;       /**< \brief [15:13] Input pattern 3 - IP3_PAT (rw) */
        vuint32_t IP3_VAL:1;       /**< \brief [12:12] Input pattern 3 is a valid pattern (rw) */
        vuint32_t IP2_PAT:3;       /**< \brief [11:9] Input pattern 2 - IP2_PAT (rw) */
        vuint32_t IP2_VAL:1;       /**< \brief [8:8] Input pattern 2 is a valid pattern (rw) */
        vuint32_t IP1_PAT:3;       /**< \brief [7:5] Input pattern 1 - IP1_PAT (rw) */
        vuint32_t IP1_VAL:1;       /**< \brief [4:4] Input pattern 1 is a valid pattern (rw) */
        vuint32_t IP0_PAT:3;       /**< \brief [3:1] Input pattern 0 - IP0_PAT (rw) */
        vuint32_t IP0_VAL:1;       /**< \brief [0:0] Input pattern 0 is a valid pattern (rw) */
    } B;
} GTM_SPE_PAT;

typedef union _GTM_SPE_OUT_PAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t SPE_OUT_PAT:16;    /**< \brief [15:0] SPE output control value for TOM_CH0 to TOM_CH7 (rw) */
    } B;
} GTM_SPE_OUT_PAT;

typedef union _GTM_SPE_OUT_CTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t SPE_OUT_CTRL:16;    /**< \brief [15:0] SPE output control value for TOM_CH0 to TOM_CH7 (rw) */
    } B;
} GTM_SPE_OUT_CTRL;

typedef union _GTM_SPE_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_5:27;    /**< \brief [31:5] \internal Reserved */
        vuint32_t SPE_RCMP:1;      /**< \brief [4:4] SPE revolution counter match event (rw) */
        vuint32_t SPE_BIS:1;       /**< \brief [3:3] Bouncing input signal detected (rw) */
        vuint32_t SPE_PERR:1;      /**< \brief [2:2] Wrong or invalid pattern detected at input (rw) */
        vuint32_t SPE_DCHG:1;      /**< \brief [1:1] SPE_DIR bit changed on behalf of new input pattern (rw) */
        vuint32_t SPE_NIPD:1;      /**< \brief [0:0] New input pattern interrupt occurred (rw) */
    } B;
} GTM_SPE_IRQ_NOTIFY;

typedef union _GTM_SPE_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_5:27;    /**< \brief [31:5] \internal Reserved */
        vuint32_t SPE_RCMP_IRQ_EN:1;    /**< \brief [4:4] SPE_RCMP_IRQ interrupt enable (rw) */
        vuint32_t SPE_BIS_IRQ_EN:1;    /**< \brief [3:3] SPE_BIS_IRQ interrupt enable (rw) */
        vuint32_t SPE_PERR_IRQ_EN:1;    /**< \brief [2:2] SPE_PERR_IRQ interrupt enable (rw) */
        vuint32_t SPE_DCHG_IRQ_EN:1;    /**< \brief [1:1] SPE_DCHG_IRQ interrupt enable (rw) */
        vuint32_t SPE_NIPD_IRQ_EN:1;    /**< \brief [0:0] SPE_NIPD_IRQ interrupt enable (rw) */
    } B;
} GTM_SPE_IRQ_EN;

typedef union _GTM_SPE_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_5:27;    /**< \brief [31:5] \internal Reserved */
        vuint32_t TRG_SPE_RCMP:1;    /**< \brief [4:4] Force interrupt of SPE_RCMP (rw) */
        vuint32_t TRG_SPE_BIS:1;    /**< \brief [3:3] Force interrupt of SPE_BIS (rw) */
        vuint32_t TRG_SPE_PERR:1;    /**< \brief [2:2] Force interrupt of SPE_PERR (rw) */
        vuint32_t TRG_SPE_DCHG:1;    /**< \brief [1:1] Force interrupt of SPE_DCHG (rw) */
        vuint32_t TRG_SPE_NIPD:1;    /**< \brief [0:0] Force interrupt of SPE_NIPD (rw) */
    } B;
} GTM_SPE_IRQ_FORCINT;

typedef union _GTM_SPE_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;      /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_SPE_IRQ_MODE;

typedef union _GTM_SPE_EIRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_5:27;    /**< \brief [31:5] \internal Reserved */
        vuint32_t SPE_RCMP_EIRQ_EN:1;    /**< \brief [4:4] SPE_RCMP_EIRQ error interrupt enable (rw) */
        vuint32_t SPE_BIS_EIRQ_EN:1;    /**< \brief [3:3] SPE_BIS_EIRQ error interrupt enable (rw) */
        vuint32_t SPE_PERR_EIRQ_EN:1;    /**< \brief [2:2] SPE_PERR_EIRQ error interrupt enable (rw) */
        vuint32_t SPE_DCHG_EIRQ_EN:1;    /**< \brief [1:1] SPE_DCHG_EIRQ error interrupt enable (rw) */
        vuint32_t SPE_NIPD_EIRQ_EN:1;    /**< \brief [0:0] SPE_NIPD_EIRQ interrupt enable (rw) */
    } B;
} GTM_SPE_EIRQ_EN;

typedef union _GTM_SPE_REV_CNT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t REV_CNT:24;      /**< \brief [23:0] Input signal revolution counter (rw) */
    } B;
} GTM_SPE_REV_CNT;

typedef union _GTM_SPE_REV_CMP {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t REV_CMP:24;      /**< \brief [23:0] Input signal revolution counter compare value (rw) */
    } B;
} GTM_SPE_REV_CMP;

typedef union _GTM_SPE_CTRL_STAT2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_11:21;    /**< \brief [31:11] \internal Reserved */
        vuint32_t SPE_PAT_PTR_BWD:3;    /**< \brief [10:8] Pattern selector for TOM output signals in case of SPE_CTRL_CMD = 0b01 (e.g. backward direction) (rw) */
        vuint32_t reserved_0:8;    /**< \brief [7:0] \internal Reserved */
    } B;
} GTM_SPE_CTRL_STAT2;

typedef union _GTM_SPE_CMD {
    vuint32_t R;
    struct {
        vuint32_t reserved_17:15;    /**< \brief [31:17] \internal Reserved */
        vuint32_t SPE_UPD_TRIG:1;    /**< \brief [16:16] SPE updater trigger (rw) */
        vuint32_t reserved_2:14;    /**< \brief [15:2] \internal Reserved */
        vuint32_t SPE_CTRL_CMD:2;    /**< \brief [1:0] SPE control command (rw) */
    } B;
} GTM_SPE_CMD;

typedef volatile struct _GTM_SPE {
       GTM_SPE_CTRL_STAT               CTRL_STAT;              /**< \brief 0, SPE${i} Control Status Register*/
       GTM_SPE_PAT                     PAT;                    /**< \brief 4, SPE${i} Input Pattern Definition Register*/
       GTM_SPE_OUT_PAT                 OUT_PAT[8];             /**< \brief 8, SPE${i} Output Definition Register z*/
       GTM_SPE_OUT_CTRL                OUT_CTRL;               /**< \brief 28, SPE${i} Output Control Register*/
       GTM_SPE_IRQ_NOTIFY              IRQ_NOTIFY;             /**< \brief 2C, SPE${i} Interrupt Notification Register*/
       GTM_SPE_IRQ_EN                  IRQ_EN;                 /**< \brief 30, SPE${i} Interrupt Enable Register*/
       GTM_SPE_IRQ_FORCINT             IRQ_FORCINT;            /**< \brief 34, SPE${i} Interrupt Generation by Software*/
       GTM_SPE_IRQ_MODE                IRQ_MODE;               /**< \brief 38, SPE${i} Interrupt Mode Configuration Register*/
       GTM_SPE_EIRQ_EN                 EIRQ_EN;                /**< \brief 3C, SPE${i} Error Interrupt Enable Register*/
       GTM_SPE_REV_CNT                 REV_CNT;                /**< \brief 40, SPE${i} Input Revolution Counter*/
       GTM_SPE_REV_CMP                 REV_CMP;                /**< \brief 44, SPE${i} Revolution Counter Compare Value*/
       GTM_SPE_CTRL_STAT2              CTRL_STAT2;             /**< \brief 48, SPE${i} Control Status Register 2*/
       GTM_SPE_CMD                     CMD;                    /**< \brief 4C, SPE${i} Command register*/
       vuint8_t                   reserved_50[0x30];      /**< \brief 50, \internal Reserved */
} GTM_SPE;

/* ============================================================================
   =============================== Module: GTM_AXIM ================================
   ============================================================================ */

typedef union _GTM_AXIM_FREE {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t FREE15:1;          /**< \brief [15:15] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE14:1;          /**< \brief [14:14] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE13:1;          /**< \brief [13:13] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE12:1;          /**< \brief [12:12] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE11:1;          /**< \brief [11:11] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE10:1;          /**< \brief [10:10] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE9:1;           /**< \brief [9 :9 ] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE8:1;           /**< \brief [8 :8 ] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE7:1;           /**< \brief [7 :7 ] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE6:1;           /**< \brief [6 :6 ] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE5:1;           /**< \brief [5 :5 ] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE4:1;           /**< \brief [4 :4 ] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE3:1;           /**< \brief [3 :3 ] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE2:1;           /**< \brief [2 :2 ] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE1:1;           /**< \brief [1 :1 ] This bit represents the allocation status of the slot [t] (r) */
        vuint32_t FREE0:1;           /**< \brief [0 :0 ] This bit represents the allocation status of the slot [t] (r) */
    } B;
} GTM_AXIM_FREE;

typedef union _GTM_AXIM_REQUEST {
    vuint32_t R;
    struct {
        vuint32_t REQID:8;              /**< \brief [31:24] This bit field shows the new allocated slot as binary encoded index */
        vuint32_t reserved_16:8;        /**< \brief [23:16] \internal Reserved */
        vuint32_t REQ1HOT15:1;          /**< \brief [15:15] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT14:1;          /**< \brief [14:14] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT13:1;          /**< \brief [13:13] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT12:1;          /**< \brief [12:12] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT11:1;          /**< \brief [11:11] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT10:1;          /**< \brief [10:10] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT9:1;           /**< \brief [9 :9 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT8:1;           /**< \brief [8 :8 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT7:1;           /**< \brief [7 :7 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT6:1;           /**< \brief [6 :6 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT5:1;           /**< \brief [5 :5 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT4:1;           /**< \brief [4 :4 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT3:1;           /**< \brief [3 :3 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT2:1;           /**< \brief [2 :2 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT1:1;           /**< \brief [1 :1 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
        vuint32_t REQ1HOT0:1;           /**< \brief [0 :0 ] A read to the AXIM[i]_REQUEST register will allocate a new slot if any slot is available (r) */
    } B;
} GTM_AXIM_REQUEST;

typedef union _GTM_AXIM_RELEASE {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;       /**< \brief [31:16] \internal Reserved */
        vuint32_t RELREQ15:1;          /**< \brief [15:15] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ14:1;          /**< \brief [14:14] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ13:1;          /**< \brief [13:13] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ12:1;          /**< \brief [12:12] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ11:1;          /**< \brief [11:11] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ10:1;          /**< \brief [10:10] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ9:1;           /**< \brief [9 :9 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ8:1;           /**< \brief [8 :8 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ7:1;           /**< \brief [7 :7 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ6:1;           /**< \brief [6 :6 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ5:1;           /**< \brief [5 :5 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ4:1;           /**< \brief [4 :4 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ3:1;           /**< \brief [3 :3 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ2:1;           /**< \brief [2 :2 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ1:1;           /**< \brief [1 :1 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
        vuint32_t RELREQ0:1;           /**< \brief [0 :0 ] Slot [t] release request: A write to AXIM[i]_RELEASE.RELREQ[t] de−allocates one or more slots.  (rw) */
    } B;
} GTM_AXIM_RELEASE;

typedef union _GTM_AXIM_SLOT_ADDR_LOW {
    vuint32_t R;
    struct {
        vuint32_t AXI_ADDR:32;             /**< \brief [31:0] Address for the AXI transaction (rw) */
    } B;
} GTM_AXIM_SLOT_ADDR_LOW;

typedef union _GTM_AXIM_SLOT_DATA_LOW {
    vuint32_t R;
    struct {
        vuint32_t AXI_DATA_LOW:32;             /**< \brief [31:0] Read or write data (rw) */
    } B;
} GTM_AXIM_SLOT_DATA_LOW;

typedef union _GTM_AXIM_SLOT_CFG1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_26:6;     /**< \brief [31:26] \internal Reserved */
        vuint32_t AXI_RW:1;          /**< \brief [25:25] AXI Read Write indication (rw) */
        vuint32_t AXI_SIZE:3;        /**< \brief [24:22] AXI data size (rw) */
        vuint32_t reserved_20:2;     /**< \brief [21:20] \internal Reserved */
        vuint32_t AXI_LOCK:2;        /**< \brief [19:18] AXI Lock indication (rw) */
        vuint32_t AXI_CACHE:4;       /**< \brief [17:14] AxCACHE bit field (rw) */
        vuint32_t AXI_PROT:3;        /**< \brief [13:11] AXI priority mode (rw) */
        vuint32_t reserved_7:4;      /**< \brief [10:7] \internal Reserved */
        vuint32_t PRIO:2;            /**< \brief [6:5] Slot priority. Priority used for slot arbitration. Lowest priority is 0, highest priority is 3 (rw) */
        vuint32_t AUTO_INCR:1;       /**< \brief [4:4] Enable or disable auto−increment mode (rw) */
        vuint32_t INCR:4;            /**< \brief [3:0] Address increment for auto−increment mode (rw) */
    } B;
} GTM_AXIM_SLOT_CFG1;

typedef union _GTM_AXIM_SLOT_CFG2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t AXI_ID:16;         /**< \brief [15:0] AXI ID for transaction (rw) */
    } B;
} GTM_AXIM_SLOT_CFG2;

typedef union _GTM_AXIM_SLOT_STATUS {
    vuint32_t R;
    struct {
        vuint32_t reserved_6:26;    /**< \brief [31:6] \internal Reserved */
        vuint32_t RESP:2;           /**< \brief [5:4] AXI response from last AXI transaction (r) */
        vuint32_t READY:1;          /**< \brief [3:3] This bit represents the slot AXIM[i]_SLOT[s]_STATUS.READY state (r) */
        vuint32_t STARTED:1;        /**< \brief [2:2] This bit represents the slot AXIM[i]_SLOT[s]_STATUS.STARTED state (r) */
        vuint32_t QUEUED:1;         /**< \brief [1:1] This bit represents the slot AXIM[i]_SLOT[s]_STATUS.QUEUED state (r) */
        vuint32_t ALLOC:1;          /**< \brief [0:0] AXI Slot occupation indication (r) */
    } B;
} GTM_AXIM_SLOT_STATUS;

typedef volatile struct _GTM_AXIM_SLOT {
       GTM_AXIM_SLOT_ADDR_LOW          ADDR_LOW;               /**< \brief 0, AXIM[i] slot[s] address bits 31:0 of AXI transaction*/
       vuint8_t                   reserved_4[0x4];        /**< \brief 4, \internal Reserved */
       GTM_AXIM_SLOT_DATA_LOW          DATA_LOW;               /**< \brief 8, AXIM[i] slot[s] data bits 31:0 of AXI transaction*/
       vuint8_t                   reserved_C[0x4];        /**< \brief C, \internal Reserved */
       GTM_AXIM_SLOT_CFG1              CFG1;                   /**< \brief 10, AXIM[i] slot [s] configuration 1*/
       GTM_AXIM_SLOT_CFG2              CFG2;                   /**< \brief 14, AXIM[i] slot [s] configuration 2*/
       GTM_AXIM_SLOT_STATUS            STATUS;                 /**< \brief 18, AXIM[i] slot[s] status*/
       vuint8_t                   reserved_1C[0x4];       /**< \brief 1C, \internal Reserved */
} GTM_AXIM_SLOT;

typedef volatile struct _GTM_AXIM {
       GTM_AXIM_FREE                   FREE;                   /**< \brief 0, AXIM[i] slot allocation status*/
       GTM_AXIM_REQUEST                REQUEST;                /**< \brief 4, AXIM[i] slot request (allocation)*/
       GTM_AXIM_RELEASE                RELEASE;                /**< \brief 8, AXIM[i] slot release (de−allocation)*/
       vuint8_t                   reserved_C[0x14];       /**< \brief C, \internal Reserved */
       GTM_AXIM_SLOT                   SLOT[16];               /**< \brief 20,*/
} GTM_AXIM;

/* ============================================================================
   =============================== Module: GTM_ ================================
   ============================================================================ */

typedef union _GTM_TIMINSEL {
    vuint32_t R;
    struct {
        vuint32_t CH7SEL:4;          /**< \brief [31:28] TIM Channel 7 Input Selection (rw) */
        vuint32_t CH6SEL:4;          /**< \brief [27:24] TIM Channel 6 Input Selection (rw) */
        vuint32_t CH5SEL:4;          /**< \brief [23:20] TIM Channel 5 Input Selection (rw) */
        vuint32_t CH4SEL:4;          /**< \brief [19:16] TIM Channel 4 Input Selection (rw) */
        vuint32_t CH3SEL:4;          /**< \brief [15:12] TIM Channel 3 Input Selection (rw) */
        vuint32_t CH2SEL:4;          /**< \brief [11:8] TIM Channel 2 Input Selection (rw) */
        vuint32_t CH1SEL:4;          /**< \brief [7:4] TIM Channel 1 Input Selection (rw) */
        vuint32_t CH0SEL:4;          /**< \brief [3:0] TIM Channel 0 Input Selection (rw) */
    } B;
} GTM_TIMINSEL;

typedef union _GTM_DTMAUXINSEL {
    vuint32_t R;
    struct {
        vuint32_t reserved_26:6;     /**< \brief [31:26] \internal Reserved */
        vuint32_t TSEL4:2;           /**< \brief [25:24] CDTM4_DTM0_AUX Input Selection (TOMx_CH0...3) (rw) */
        vuint32_t TSEL3:2;           /**< \brief [23:22] CDTM3_DTM0_AUX Input Selection (TOMx_CH0...3) (rw) */
        vuint32_t TSEL2:2;           /**< \brief [21:20] CDTM2_DTM0_AUX Input Selection (TOMx_CH0...3) (rw) */
        vuint32_t TSEL1:2;           /**< \brief [19:18] CDTM1_DTM0_AUX Input Selection (TOMx_CH0...3) (rw) */
        vuint32_t TSEL0:2;           /**< \brief [17:16] CDTM0_DTM0_AUX Input Selection (TOMx_CH0...3) (rw) */
        vuint32_t reserved_14:2;     /**< \brief [15:14] \internal Reserved */
        vuint32_t ASEL6:2;           /**< \brief [13:12] CDTM6_DTM4_AUX Input Selection (ATOMx_CH0...3) (rw) */
        vuint32_t ASEL5:2;           /**< \brief [11:10] CDTM5_DTM4_AUX Input Selection (ATOMx_CH0...3) (rw) */
        vuint32_t ASEL4:2;           /**< \brief [9:8] CDTM4_DTM4_AUX Input Selection (ATOMx_CH0...3) (rw) */
        vuint32_t ASEL3:2;           /**< \brief [7:6] CDTM3_DTM4_AUX Input Selection (ATOMx_CH0...3) (rw) */
        vuint32_t ASEL2:2;           /**< \brief [5:4] CDTM2_DTM4_AUX Input Selection (ATOMx_CH0...3) (rw) */
        vuint32_t ASEL1:2;           /**< \brief [3:2] CDTM1_DTM4_AUX Input Selection (ATOMx_CH0...3) (rw) */
        vuint32_t ASEL0:2;           /**< \brief [1:0] CDTM0_DTM4_AUX Input Selection (ATOMx_CH0...3) (rw) */
    } B;
} GTM_DTMAUXINSEL;

typedef union _GTM_MSC_SET_CON0 {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;     /**< \brief [31:29] \internal Reserved */
        vuint32_t SEL3:5;            /**< \brief [28:24] Set 0[3] Input Selection (rw) */
        vuint32_t reserved_21:3;     /**< \brief [23:21] \internal Reserved */
        vuint32_t SEL2:5;            /**< \brief [20:16] Set 0[2] Input Selection (rw) */
        vuint32_t reserved_13:3;     /**< \brief [15:13] \internal Reserved */
        vuint32_t SEL1:5;            /**< \brief [12:8] Set 0[1] Input Selection (rw) */
        vuint32_t reserved_5:3;      /**< \brief [7:5] \internal Reserved */
        vuint32_t SEL0:5;            /**< \brief [4:0] Set 0[0] Input Selection (rw) */
    } B;
} GTM_MSC_SET_CON0;

typedef union _GTM_MSC_SET_CON1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;     /**< \brief [31:29] \internal Reserved */
        vuint32_t SEL7:5;            /**< \brief [28:24] Set 0[7] Input Selection (rw) */
        vuint32_t reserved_21:3;     /**< \brief [23:21] \internal Reserved */
        vuint32_t SEL6:5;            /**< \brief [20:16] Set 0[6] Input Selection (rw) */
        vuint32_t reserved_13:3;     /**< \brief [15:13] \internal Reserved */
        vuint32_t SEL5:5;            /**< \brief [12:8] Set 0[5] Input Selection (rw) */
        vuint32_t reserved_5:3;      /**< \brief [7:5] \internal Reserved */
        vuint32_t SEL4:5;            /**< \brief [4:0] Set 0[4] Input Selection (rw) */
    } B;
} GTM_MSC_SET_CON1;

typedef union _GTM_MSC_SET_CON2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;     /**< \brief [31:29] \internal Reserved */
        vuint32_t SEL11:5;           /**< \brief [28:24] Set 0[11] Input Selection (rw) */
        vuint32_t reserved_21:3;     /**< \brief [23:21] \internal Reserved */
        vuint32_t SEL10:5;           /**< \brief [20:16] Set 0[10] Input Selection (rw) */
        vuint32_t reserved_13:3;     /**< \brief [15:13] \internal Reserved */
        vuint32_t SEL9:5;            /**< \brief [12:8] Set 0[9] Input Selection (rw) */
        vuint32_t reserved_5:3;      /**< \brief [7:5] \internal Reserved */
        vuint32_t SEL8:5;            /**< \brief [4:0] Set 0[8] Input Selection (rw) */
    } B;
} GTM_MSC_SET_CON2;

typedef union _GTM_MSC_SET_CON3 {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;     /**< \brief [31:29] \internal Reserved */
        vuint32_t SEL15:5;           /**< \brief [28:24] Set 0[15] Input Selection (rw) */
        vuint32_t reserved_21:3;     /**< \brief [23:21] \internal Reserved */
        vuint32_t SEL14:5;           /**< \brief [20:16] Set 0[14] Input Selection (rw) */
        vuint32_t reserved_13:3;     /**< \brief [15:13] \internal Reserved */
        vuint32_t SEL13:5;           /**< \brief [12:8] Set 0[13] Input Selection (rw) */
        vuint32_t reserved_5:3;      /**< \brief [7:5] \internal Reserved */
        vuint32_t SEL12:5;           /**< \brief [4:0] Set 0[12] Input Selection (rw) */
    } B;
} GTM_MSC_SET_CON3;

typedef volatile struct _GTM_MSC_SET {
       GTM_MSC_SET_CON0                CON0;                   /**< \brief 0, MSC Set ${i} Control ${j} Register*/
       GTM_MSC_SET_CON1                CON1;                   /**< \brief 4, MSC Set ${i} Control ${j} Register*/
       GTM_MSC_SET_CON2                CON2;                   /**< \brief 8, MSC Set ${i} Control ${j} Register*/
       GTM_MSC_SET_CON3                CON3;                   /**< \brief C, MSC Set ${i} Control ${j} Register*/
} GTM_MSC_SET;

typedef union _GTM_MSC_MSCQ_INLCON {
    vuint32_t R;
    struct {
        vuint32_t SEL15:2;           /**< \brief [31:30] GTM MSCq Low 15 Output Selection (rw) */
        vuint32_t SEL14:2;           /**< \brief [29:28] GTM MSCq Low 14 Output Selection (rw) */
        vuint32_t SEL13:2;           /**< \brief [27:26] GTM MSCq Low 13 Output Selection (rw) */
        vuint32_t SEL12:2;           /**< \brief [25:24] GTM MSCq Low 12 Output Selection (rw) */
        vuint32_t SEL11:2;           /**< \brief [23:22] GTM MSCq Low 11 Output Selection (rw) */
        vuint32_t SEL10:2;           /**< \brief [21:20] GTM MSCq Low 10 Output Selection (rw) */
        vuint32_t SEL9:2;            /**< \brief [19:18] GTM MSCq Low 9 Output Selection (rw) */
        vuint32_t SEL8:2;            /**< \brief [17:16] GTM MSCq Low 8 Output Selection (rw) */
        vuint32_t SEL7:2;            /**< \brief [15:14] GTM MSCq Low 7 Output Selection (rw) */
        vuint32_t SEL6:2;            /**< \brief [13:12] GTM MSCq Low 6 Output Selection (rw) */
        vuint32_t SEL5:2;            /**< \brief [11:10] GTM MSCq Low 5 Output Selection (rw) */
        vuint32_t SEL4:2;            /**< \brief [9:8] GTM MSCq Low 4 Output Selection (rw) */
        vuint32_t SEL3:2;            /**< \brief [7:6] GTM MSCq Low 3 Output Selection (rw) */
        vuint32_t SEL2:2;            /**< \brief [5:4] GTM MSCq Low 2 Output Selection (rw) */
        vuint32_t SEL1:2;            /**< \brief [3:2] GTM MSCq Low 1 Output Selection (rw) */
        vuint32_t SEL0:2;            /**< \brief [1:0] GTM MSCq Low 0 Output Selection (rw) */
    } B;
} GTM_MSC_MSCQ_INLCON;

typedef union _GTM_MSC_MSCQ_INHCON {
    vuint32_t R;
    struct {
        vuint32_t SEL15:2;           /**< \brief [31:30] GTM MSCq High 15 Output Selection (rw) */
        vuint32_t SEL14:2;           /**< \brief [29:28] GTM MSCq High 14 Output Selection (rw) */
        vuint32_t SEL13:2;           /**< \brief [27:26] GTM MSCq High 13 Output Selection (rw) */
        vuint32_t SEL12:2;           /**< \brief [25:24] GTM MSCq High 12 Output Selection (rw) */
        vuint32_t SEL11:2;           /**< \brief [23:22] GTM MSCq High 11 Output Selection (rw) */
        vuint32_t SEL10:2;           /**< \brief [21:20] GTM MSCq High 10 Output Selection (rw) */
        vuint32_t SEL9:2;            /**< \brief [19:18] GTM MSCq High 9 Output Selection (rw) */
        vuint32_t SEL8:2;            /**< \brief [17:16] GTM MSCq High 8 Output Selection (rw) */
        vuint32_t SEL7:2;            /**< \brief [15:14] GTM MSCq High 7 Output Selection (rw) */
        vuint32_t SEL6:2;            /**< \brief [13:12] GTM MSCq High 6 Output Selection (rw) */
        vuint32_t SEL5:2;            /**< \brief [11:10] GTM MSCq High 5 Output Selection (rw) */
        vuint32_t SEL4:2;            /**< \brief [9:8] GTM MSCq High 4 Output Selection (rw) */
        vuint32_t SEL3:2;            /**< \brief [7:6] GTM MSCq High 3 Output Selection (rw) */
        vuint32_t SEL2:2;            /**< \brief [5:4] GTM MSCq High 2 Output Selection (rw) */
        vuint32_t SEL1:2;            /**< \brief [3:2] GTM MSCq High 1 Output Selection (rw) */
        vuint32_t SEL0:2;            /**< \brief [1:0] GTM MSCq High 0 Output Selection (rw) */
    } B;
} GTM_MSC_MSCQ_INHCON;

typedef union _GTM_MSC_MSCQ_INLEXTCON {
    vuint32_t R;
    struct {
        vuint32_t SEL15:2;           /**< \brief [31:30] GTM MSCq LowExtended 15 Output Selection (rw) */
        vuint32_t SEL14:2;           /**< \brief [29:28] GTM MSCq LowExtended 14 Output Selection (rw) */
        vuint32_t SEL13:2;           /**< \brief [27:26] GTM MSCq LowExtended 13 Output Selection (rw) */
        vuint32_t SEL12:2;           /**< \brief [25:24] GTM MSCq LowExtended 12 Output Selection (rw) */
        vuint32_t SEL11:2;           /**< \brief [23:22] GTM MSCq LowExtended 11 Output Selection (rw) */
        vuint32_t SEL10:2;           /**< \brief [21:20] GTM MSCq LowExtended 10 Output Selection (rw) */
        vuint32_t SEL9:2;            /**< \brief [19:18] GTM MSCq LowExtended 9 Output Selection (rw) */
        vuint32_t SEL8:2;            /**< \brief [17:16] GTM MSCq LowExtended 8 Output Selection (rw) */
        vuint32_t SEL7:2;            /**< \brief [15:14] GTM MSCq LowExtended 7 Output Selection (rw) */
        vuint32_t SEL6:2;            /**< \brief [13:12] GTM MSCq LowExtended 6 Output Selection (rw) */
        vuint32_t SEL5:2;            /**< \brief [11:10] GTM MSCq LowExtended 5 Output Selection (rw) */
        vuint32_t SEL4:2;            /**< \brief [9:8] GTM MSCq LowExtended 4 Output Selection (rw) */
        vuint32_t SEL3:2;            /**< \brief [7:6] GTM MSCq LowExtended 3 Output Selection (rw) */
        vuint32_t SEL2:2;            /**< \brief [5:4] GTM MSCq LowExtended 2 Output Selection (rw) */
        vuint32_t SEL1:2;            /**< \brief [3:2] GTM MSCq LowExtended 1 Output Selection (rw) */
        vuint32_t SEL0:2;            /**< \brief [1:0] GTM MSCq LowExtended 0 Output Selection (rw) */
    } B;
} GTM_MSC_MSCQ_INLEXTCON;

typedef volatile struct _GTM_MSC_MSCQ {
       GTM_MSC_MSCQ_INLCON             INLCON;                 /**< \brief 0, MSC${i} Input Low Control Register*/
       GTM_MSC_MSCQ_INHCON             INHCON;                 /**< \brief 4, MSC${i} Input High Control Register*/
       GTM_MSC_MSCQ_INLEXTCON          INLEXTCON;              /**< \brief 8, MSC${i} Input Low Extended Control Register*/
} GTM_MSC_MSCQ;

typedef volatile struct _GTM_MSC {
       GTM_MSC_SET                     SET[9];                 /**< \brief 0, */
       GTM_MSC_MSCQ                    MSCQ[4];                /**< \brief 90, MSC${i} Input Low Extended Control Register*/
} GTM_MSC;

typedef union _GTM_TOUTSEL {
    vuint32_t R;
    struct {
        vuint32_t SEL7:4;            /**< \brief [31:28] TOUT(n*8 + 7) Output Selection (rw) */
        vuint32_t SEL6:4;            /**< \brief [27:24] TOUT(n*8 + 6) Output Selection (rw) */
        vuint32_t SEL5:4;            /**< \brief [23:20] TOUT(n*8 + 5) Output Selection (rw) */
        vuint32_t SEL4:4;            /**< \brief [19:16] TOUT(n*8 + 4) Output Selection (rw) */
        vuint32_t SEL3:4;            /**< \brief [15:12] TOUT(n*8 + 3) Output Selection (rw) */
        vuint32_t SEL2:4;            /**< \brief [11:8] TOUT(n*8 + 2) Output Selection (rw) */
        vuint32_t SEL1:4;            /**< \brief [7:4] TOUT(n*8 + 1) Output Selection (rw) */
        vuint32_t SEL0:4;            /**< \brief [3:0] TOUT(n*8 + 0) Output Selection (rw) */
    } B;
} GTM_TOUTSEL;

typedef union _GTM_DSADCINSEL {
    vuint32_t R;
    struct {
        vuint32_t INSEL7:4;          /**< \brief [31:28] In Selection for DSADCn GTM connection (rw) */
        vuint32_t INSEL6:4;          /**< \brief [27:24] In Selection for DSADCn GTM connection (rw) */
        vuint32_t INSEL5:4;          /**< \brief [23:20] In Selection for DSADCn GTM connection (rw) */
        vuint32_t INSEL4:4;          /**< \brief [19:16] In Selection for DSADCn GTM connection (rw) */
        vuint32_t INSEL3:4;          /**< \brief [15:12] In Selection for DSADCn GTM connection (rw) */
        vuint32_t INSEL2:4;          /**< \brief [11:8] In Selection for DSADCn GTM connection (rw) */
        vuint32_t INSEL1:4;          /**< \brief [7:4] In Selection for DSADCn GTM connection (rw) */
        vuint32_t INSEL0:4;          /**< \brief [3:0] In Selection for DSADCn GTM connection (rw) */
    } B;
} GTM_DSADCINSEL;

typedef union _GTM_DSADC_OUTSEL0 {
    vuint32_t R;
    struct {
        vuint32_t SEL7:4;            /**< \brief [31:28] Output Selection for DSADC7 GTM connection (rw) */
        vuint32_t SEL6:4;            /**< \brief [27:24] Output Selection for DSADC6 GTM connection (rw) */
        vuint32_t SEL5:4;            /**< \brief [23:20] Output Selection for DSADC5 GTM connection (rw) */
        vuint32_t SEL4:4;            /**< \brief [19:16] Output Selection for DSADC4 GTM connection (rw) */
        vuint32_t SEL3:4;            /**< \brief [15:12] Output Selection for DSADC3 GTM connection (rw) */
        vuint32_t SEL2:4;            /**< \brief [11:8] Output Selection for DSADC2 GTM connection (rw) */
        vuint32_t SEL1:4;            /**< \brief [7:4] Output Selection for DSADC1 GTM connection (rw) */
        vuint32_t SEL0:4;            /**< \brief [3:0] Output Selection for DSADC0 GTM connection (rw) */
    } B;
} GTM_DSADC_OUTSEL0;

typedef union _GTM_DSADC_OUTSEL1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;     /**< \brief [31:24] \internal Reserved */
        vuint32_t SEL13:4;           /**< \brief [23:20] Output Selection for GTM to DSADC13 connection (rw) */
        vuint32_t SEL12:4;           /**< \brief [19:16] Output Selection for GTM to DSADC12 connection (rw) */
        vuint32_t SEL11:4;           /**< \brief [15:12] Output Selection for GTM to DSADC11 connection (rw) */
        vuint32_t SEL10:4;           /**< \brief [11:8] Output Selection for GTM to DSADC10 connection (rw) */
        vuint32_t SEL9:4;            /**< \brief [7:4] Output Selection for GTM to DSADC9 connection (rw) */
        vuint32_t SEL8:4;            /**< \brief [3:0] Output Selection for GTM to DSADC8 connection (rw) */
    } B;
} GTM_DSADC_OUTSEL1;

typedef volatile struct _GTM_DSADC {
       GTM_DSADC_OUTSEL0               OUTSEL0;                /**< \brief 0, DSADC Output Select i0 Register*/
       GTM_DSADC_OUTSEL1               OUTSEL1;                /**< \brief 4, DSADC Output Select i1 Register*/
} GTM_DSADC;

typedef union _GTM_ADCTRIG_OUT0 {
    vuint32_t R;
    struct {
        vuint32_t SEL7:4;            /**< \brief [31:28] Output Selection for GTM to ADC7 connection (rw) */
        vuint32_t SEL6:4;            /**< \brief [27:24] Output Selection for GTM to ADC6 connection (rw) */
        vuint32_t SEL5:4;            /**< \brief [23:20] Output Selection for GTM to ADC5 connection (rw) */
        vuint32_t SEL4:4;            /**< \brief [19:16] Output Selection for GTM to ADC4 connection (rw) */
        vuint32_t SEL3:4;            /**< \brief [15:12] Output Selection for GTM to ADC3 connection (rw) */
        vuint32_t SEL2:4;            /**< \brief [11:8] Output Selection for GTM to ADC2 connection (rw) */
        vuint32_t SEL1:4;            /**< \brief [7:4] Output Selection for GTM to ADC1 connection (rw) */
        vuint32_t SEL0:4;            /**< \brief [3:0] Output Selection for GTM to ADC0 connection (rw) */
    } B;
} GTM_ADCTRIG_OUT0;

typedef union _GTM_ADCTRIG_OUT1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t SEL3:4;            /**< \brief [15:12] Output Selection for GTM to ADC3 connection (rw) */
        vuint32_t SEL2:4;            /**< \brief [11:8] Output Selection for GTM to ADC2 connection (rw) */
        vuint32_t SEL1:4;            /**< \brief [7:4] Output Selection for GTM to ADC1 connection (rw) */
        vuint32_t SEL0:4;            /**< \brief [3:0] Output Selection for GTM to ADC0 connection (rw) */
    } B;
} GTM_ADCTRIG_OUT1;

typedef volatile struct _GTM_ADCTRIG {
       GTM_ADCTRIG_OUT0                OUT0;                   /**< \brief 0, ADC Trigger ${i} Output Select 0 Register*/
       GTM_ADCTRIG_OUT1                OUT1;                   /**< \brief 4, ADC Trigger ${i} Output Select 1 Register*/
} GTM_ADCTRIG;

typedef union _GTM_CANOUTSEL0 {
    vuint32_t R;
    struct {
        vuint32_t SEL7:4;            /**< \brief [31:28] Output Selection for GTM to CAN connection 7 (rw) */
        vuint32_t SEL6:4;            /**< \brief [27:24] Output Selection for GTM to CAN connection 6 (rw) */
        vuint32_t SEL5:4;            /**< \brief [23:20] Output Selection for GTM to CAN connection 5 (rw) */
        vuint32_t SEL4:4;            /**< \brief [19:16] Output Selection for GTM to CAN connection 4 (rw) */
        vuint32_t SEL3:4;            /**< \brief [15:12] Output Selection for GTM to CAN connection 3 (rw) */
        vuint32_t SEL2:4;            /**< \brief [11:8] Output Selection for GTM to CAN connection 2 (rw) */
        vuint32_t SEL1:4;            /**< \brief [7:4] Output Selection for GTM to CAN connection 1 (rw) */
        vuint32_t SEL0:4;            /**< \brief [3:0] Output Selection for GTM to CAN connection 0 (rw) */
    } B;
} GTM_CANOUTSEL0;

typedef union _GTM_CANOUTSEL1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t SEL3:4;            /**< \brief [15:12] Output Selection for GTM to CAN connection 3 (rw) */
        vuint32_t SEL2:4;            /**< \brief [11:8] Output Selection for GTM to CAN connection 2 (rw) */
        vuint32_t SEL1:4;            /**< \brief [7:4] Output Selection for GTM to CAN connection 1 (rw) */
        vuint32_t SEL0:4;            /**< \brief [3:0] Output Selection for GTM to CAN connection 0 (rw) */
    } B;
} GTM_CANOUTSEL1;

typedef union _GTM_PSI5OUTSEL {
    vuint32_t R;
    struct {
        vuint32_t PSI5_SEL7:4;            /**< \brief [31:28] Output Selection for GTM to PSI5_7 connection (rw) */
        vuint32_t PSI5_SEL6:4;            /**< \brief [27:24] Output Selection for GTM to PSI5_6 connection (rw) */
        vuint32_t PSI5_SEL5:4;            /**< \brief [23:20] Output Selection for GTM to PSI5_5 connection (rw) */
        vuint32_t PSI5_SEL4:4;            /**< \brief [19:16] Output Selection for GTM to PSI5_4 connection (rw) */
        vuint32_t PSI5_SEL3:4;            /**< \brief [15:12] Output Selection for GTM to PSI5_3 connection (rw) */
        vuint32_t PSI5_SEL2:4;            /**< \brief [11:8] Output Selection for GTM to PSI5_2 connection (rw) */
        vuint32_t PSI5_SEL1:4;            /**< \brief [7:4] Output Selection for GTM to PSI5_1 connection (rw) */
        vuint32_t PSI5_SEL0:4;            /**< \brief [3:0] Output Selection for GTM to PSI5_0 connection (rw) */
    } B;
} GTM_PSI5OUTSEL;

typedef union _GTM_PSI5SOUTSEL {
    vuint32_t R;
    struct {
        vuint32_t PSI5S_SEL3:4;            /**< \brief [31:28] Output Selection for GTM to PSI5-S_3 connection (rw) */
        vuint32_t PSI5S_SEL2:4;            /**< \brief [27:24] Output Selection for GTM to PSI5-S_2 connection (rw) */
        vuint32_t PSI5S_SEL1:4;            /**< \brief [23:20] Output Selection for GTM to PSI5-S_1 connection (rw) */
        vuint32_t PSI5S_SEL0:4;            /**< \brief [19:16] Output Selection for GTM to PSI5-S_0 connection (rw) */
        vuint32_t PSI5_SEL11:4;            /**< \brief [15:12] Output Selection for GTM to PSI5_11 connection (rw) */
        vuint32_t PSI5_SEL10:4;            /**< \brief [11:8] Output Selection for GTM to PSI5_10 connection (rw) */
        vuint32_t PSI5_SEL9:4;             /**< \brief [7:4] Output Selection for GTM to PSI5_9 connection (rw) */
        vuint32_t PSI5_SEL8:4;             /**< \brief [3:0] Output Selection for GTM to PSI5_8 connection (rw) */
    } B;
} GTM_PSI5SOUTSEL;

typedef union _GTM_LCDCDCOUTSEL {
    vuint32_t R;
    struct {
        vuint32_t reserved_4:28;     /**< \brief [31:4] \internal Reserved */
        vuint32_t SEL:4;             /**< \brief [3:0] Output Selection for GTM to LCDCDC connection (rw) */
    } B;
} GTM_LCDCDCOUTSEL;

typedef union _GTM_MCSDPLLMEMSEL {
    vuint32_t R;
    struct {
        vuint32_t reserved_11:21;    /**< \brief [31:11] \internal Reserved */
        vuint32_t DPLL_USED_SEL:1;   /**< \brief [10:10] dpll memory select (rw) */
        vuint32_t reserved_6:4;      /**< \brief [9:6] \internal Reserved */
        vuint32_t MCS_USED_SEL5:1;   /**< \brief [5:5] mcs channel 5 memory select (rw) */
        vuint32_t MCS_USED_SEL4:1;   /**< \brief [4:4] mcs channel 4 memory select (rw) */
        vuint32_t MCS_USED_SEL3:1;   /**< \brief [3:3] mcs channel 3 memory select (rw) */
        vuint32_t MCS_USED_SEL2:1;   /**< \brief [2:2] mcs channel 2 memory select (rw) */
        vuint32_t MCS_USED_SEL1:1;   /**< \brief [1:1] mcs channel 1 memory select (rw) */
        vuint32_t MCS_USED_SEL0:1;   /**< \brief [0:0] mcs channel 0 memory select (rw) */
    } B;
} GTM_MCSDPLLMEMSEL;

typedef union _GTM_MCSDPLLCTLSTS {
    vuint32_t R;
    struct {
        vuint32_t reserved_11:14;       /**< \brief [31:18] \internal Reserved */
        vuint32_t MCS_RAM_SWITCH_ACK:2; /**< \brief [17:16] memory switch status (r) */
        vuint32_t reserved_1:15;        /**< \brief [15:1] \internal Reserved */
        vuint32_t MEM_USED_EN:1;        /**< \brief [0:0] memory used enable (rw) */
    } B;
} GTM_MCSDPLLCTLSTS;

typedef union _GTM_GLSDLLCTRL {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;        /**< \brief [31:16] \internal Reserved */
        vuint32_t ATOM_TOM_SEL:8;        /**< \brief [15:8] ATOM/TOM Selection 1 = TOM, 0 = ATOM (rw) */
        vuint32_t reserved_4:4;          /**< \brief [7:4] \internal Reserved */
        vuint32_t UNLOCK_SEL:1;          /**< \brief [3:3] Unlock Selection (rw) */
        vuint32_t OVERFLOW_STA:1;        /**< \brief [2:2] Overflow status((r) */
        vuint32_t LOCK_STA:1;            /**< \brief [1:1] LOCK status (r) */
        vuint32_t HRES_EN:1;             /**< \brief [0:0] HRES enable (rw) */
    } B;
} GTM_GLSDLLCTRL;

typedef union _GTM_DXOUTCON {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t OUT9:1;            /**< \brief [9:9] Output 09 Control (rw) */
        vuint32_t OUT8:1;            /**< \brief [8:8] Output 08 Control (rw) */
        vuint32_t OUT7:1;            /**< \brief [7:7] Output 07 Control (rw) */
        vuint32_t OUT6:1;            /**< \brief [6:6] Output 06 Control (rw) */
        vuint32_t OUT5:1;            /**< \brief [5:5] Output 05 Control (rw) */
        vuint32_t OUT4:1;            /**< \brief [4:4] Output 04 Control (rw) */
        vuint32_t OUT3:1;            /**< \brief [3:3] Output 03 Control (rw) */
        vuint32_t OUT2:1;            /**< \brief [2:2] Output 02 Control (rw) */
        vuint32_t OUT1:1;            /**< \brief [1:1] Output 01 Control (rw) */
        vuint32_t OUT0:1;            /**< \brief [0:0] Output 00 Control (rw) */
    } B;
} GTM_DXOUTCON;

typedef union _GTM_TRIGOUT {
    vuint32_t R;
    struct {
        vuint32_t TRIG15:2;          /**< \brief [31:30] Trigger 15 (w) */
        vuint32_t TRIG14:2;          /**< \brief [29:28] Trigger 14 (w) */
        vuint32_t TRIG13:2;          /**< \brief [27:26] Trigger 13 (w) */
        vuint32_t TRIG12:2;          /**< \brief [25:24] Trigger 12 (w) */
        vuint32_t TRIG11:2;          /**< \brief [23:22] Trigger 11 (w) */
        vuint32_t TRIG10:2;          /**< \brief [21:20] Trigger 10 (w) */
        vuint32_t TRIG9:2;           /**< \brief [19:18] Trigger 9 (w) */
        vuint32_t TRIG8:2;           /**< \brief [17:16] Trigger 8 (w) */
        vuint32_t TRIG7:2;           /**< \brief [15:14] Trigger 7 (w) */
        vuint32_t TRIG6:2;           /**< \brief [13:12] Trigger 6 (w) */
        vuint32_t TRIG5:2;           /**< \brief [11:10] Trigger 5 (w) */
        vuint32_t TRIG4:2;           /**< \brief [9:8] Trigger 4 (w) */
        vuint32_t TRIG3:2;           /**< \brief [7:6] Trigger 3 (w) */
        vuint32_t TRIG2:2;           /**< \brief [5:4] Trigger 2 (w) */
        vuint32_t TRIG1:2;           /**< \brief [3:2] Trigger 1 (w) */
        vuint32_t TRIG0:2;           /**< \brief [1:0] Trigger 0 (w) */
    } B;
} GTM_TRIGOUT;

typedef union _GTM_MCSTRIGOUTSEL {
    vuint32_t R;
    struct {
        vuint32_t SEL7:4;            /**< \brief [31:28] Selects which MCS triggers go to FC7BFDAT/SEL (rw) */
        vuint32_t SEL6:4;            /**< \brief [27:24] Selects which MCS triggers go to FC6BFDAT/SEL (rw) */
        vuint32_t SEL5:4;            /**< \brief [23:20] Selects which MCS triggers go to FC5BFDAT/SEL (rw) */
        vuint32_t SEL4:4;            /**< \brief [19:16] Selects which MCS triggers go to FC4BFDAT/SEL (rw) */
        vuint32_t SEL3:4;            /**< \brief [15:12] Selects which MCS triggers go to FC3BFDAT/SEL (rw) */
        vuint32_t SEL2:4;            /**< \brief [11:8] Selects which MCS triggers go to FC2BFDAT/SEL (rw) */
        vuint32_t SEL1:4;            /**< \brief [7:4] Selects which MCS triggers go to FC1BFDAT/SEL (rw) */
        vuint32_t SEL0:4;            /**< \brief [3:0] Selects which MCS triggers go to FC0BFDAT/SEL (rw) */
    } B;
} GTM_MCSTRIGOUTSEL;

typedef union _GTM_MCSINTSTAT {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t MCS90:1;           /**< \brief [9:9] MCS9 RAM0 Interrupt 0 Status Flag (rh) */
        vuint32_t MCS80:1;           /**< \brief [8:8] MCS8 RAM0 Interrupt 0 Status Flag (rh) */
        vuint32_t MCS70:1;           /**< \brief [7:7] MCS7 RAM0 Interrupt 0 Status Flag (rh) */
        vuint32_t MCS60:1;           /**< \brief [6:6] MCS6 RAM0 Interrupt 0 Status Flag (rh) */
        vuint32_t MCS50:1;           /**< \brief [5:5] MCS5 RAM0 Interrupt 0 Status Flag (rh) */
        vuint32_t MCS40:1;           /**< \brief [4:4] MCS4 RAM0 Interrupt 0 Status Flag (rh) */
        vuint32_t MCS30:1;           /**< \brief [3:3] MCS3 RAM0 Interrupt 0 Status Flag (rh) */
        vuint32_t MCS20:1;           /**< \brief [2:2] MCS2 RAM0 Interrupt 0 Status Flag (rh) */
        vuint32_t MCS10:1;           /**< \brief [1:1] MCS1 RAM0 Interrupt 0 Status Flag (rh) */
        vuint32_t MCS00:1;           /**< \brief [0:0] MCS0 RAM0 Interrupt 0 Status Flag (rh) */
    } B;
} GTM_MCSINTSTAT;

typedef union _GTM_MCSINTCLR {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t MCS9:1;            /**< \brief [9:9] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
        vuint32_t MCS8:1;            /**< \brief [8:8] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
        vuint32_t MCS7:1;            /**< \brief [7:7] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
        vuint32_t MCS6:1;            /**< \brief [6:6] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
        vuint32_t MCS5:1;            /**< \brief [5:5] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
        vuint32_t MCS4:1;            /**< \brief [4:4] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
        vuint32_t MCS3:1;            /**< \brief [3:3] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
        vuint32_t MCS2:1;            /**< \brief [2:2] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
        vuint32_t MCS1:1;            /**< \brief [1:1] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
        vuint32_t MCS0:1;            /**< \brief [0:0] MCSn RAM0 Interrupt 0 Status Clear Bit (w) */
    } B;
} GTM_MCSINTCLR;

typedef union _GTM_INTOUT {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;     /**< \brief [31:2] \internal Reserved */
        vuint32_t INT0:2;            /**< \brief [1:0] Interrupt Trigger Request 0 (w) */
    } B;
} GTM_INTOUT;

typedef union _GTM_DXINCON {
    vuint32_t R;
    struct {
        vuint32_t IN0:1;             /**< \brief [0:0] Input 00 Control (rw) */
        vuint32_t IN1:1;             /**< \brief [1:1] Input 01 Control (rw) */
        vuint32_t IN2:1;             /**< \brief [2:2] Input 02 Control (rw) */
        vuint32_t IN3:1;             /**< \brief [3:3] Input 03 Control (rw) */
        vuint32_t IN4:1;             /**< \brief [4:4] Input 04 Control (rw) */
        vuint32_t IN5:1;             /**< \brief [5:5] Input 05 Control (rw) */
        vuint32_t IN6:1;             /**< \brief [6:6] Input 06 Control (rw) */
        vuint32_t IN7:1;             /**< \brief [7:7] Input 07 Control (rw) */
        vuint32_t IN8:1;             /**< \brief [8:8] Input 08 Control (rw) */
        vuint32_t IN9:1;             /**< \brief [9:9] Input 09 Control (rw) */
        vuint32_t reserved_10:6;     /**< \brief [15:10] \internal Reserved */
        vuint32_t DSS0:1;            /**< \brief [16:16] Data Source Select 00 Control (rw) */
        vuint32_t DSS1:1;            /**< \brief [17:17] Data Source Select 01 Control (rw) */
        vuint32_t DSS2:1;            /**< \brief [18:18] Data Source Select 02 Control (rw) */
        vuint32_t DSS3:1;            /**< \brief [19:19] Data Source Select 03 Control (rw) */
        vuint32_t DSS4:1;            /**< \brief [20:20] Data Source Select 04 Control (rw) */
        vuint32_t DSS5:1;            /**< \brief [21:21] Data Source Select 05 Control (rw) */
        vuint32_t DSS6:1;            /**< \brief [22:22] Data Source Select 06 Control (rw) */
        vuint32_t DSS7:1;            /**< \brief [23:23] Data Source Select 07 Control (rw) */
        vuint32_t DSS8:1;            /**< \brief [24:24] Data Source Select 08 Control (rw) */
        vuint32_t DSS9:1;            /**< \brief [25:25] Data Source Select 09 Control (rw) */
        vuint32_t reserved_26:6;     /**< \brief [31:26] \internal Reserved */
    } B;
} GTM_DXINCON;

typedef union _GTM_DATAIN {
    vuint32_t R;
    struct {
        vuint32_t DATA:32;           /**< \brief [31:0] Data (rw) */
    } B;
} GTM_DATAIN;

/* ============================================================================
   =============================== Module: GTM_DPLL ================================
   ============================================================================ */
typedef union _GTM_DPLL_CTRL_0 {
    vuint32_t R;
    struct {
        vuint32_t RMO:1;           /**< \brief [31:31] Reference mode (rw) */
        vuint32_t TEN:1;           /**< \brief [30:30] TRIGGER enable (rw) */
        vuint32_t SEN:1;           /**< \brief [29:29] STATE enable (rw) */
        vuint32_t IDT:1;           /**< \brief [28:28] Input delay TRIGGER (rw) */
        vuint32_t IDS:1;           /**< \brief [27:27] Input delay STATE (rw) */
        vuint32_t AMT:1;           /**< \brief [26:26] Adapt mode TRIGGER (rw) */
        vuint32_t AMS:1;           /**< \brief [25:25] Adapt mode STATE (rw) */
        vuint32_t TNU:9;           /**< \brief [24:16] TRIGGER number (rw) */
        vuint32_t SNU:5;           /**< \brief [15:11] STATE number (rw) */
        vuint32_t IFP:1;           /**< \brief [10:10] Input filter position (rw) */
        vuint32_t MLT:10;          /**< \brief [9:0] Multiplier for TRIGGER (rw) */
    } B;
} GTM_DPLL_CTRL_0;

typedef union _GTM_DPLL_CTRL_1 {
    vuint32_t R;
    struct {
        vuint32_t TSL:2;           /**< \brief [31:30] TRIGGER slope select (rw) */
        vuint32_t SSL:2;           /**< \brief [29:28] STATE slope select (rw) */
        vuint32_t SMC:1;           /**< \brief [27:27] Synchronous Motor Control (rw) */
        vuint32_t TS0_HRT:1;       /**< \brief [26:26] Time stamp high resolution TRIGGER (rw) */
        vuint32_t TS0_HRS:1;       /**< \brief [25:25] Time stamp high resolution STATE (rw) */
        vuint32_t SYSF:1;          /**< \brief [24:24] SYN_NS for FULL_SCALE (rw) */
        vuint32_t SWR:1;           /**< \brief [23:23] Software reset (rw) */
        vuint32_t LCD:1;           /**< \brief [22:22] Locking condition definition (rw) */
        vuint32_t SYN_NT:6;        /**< \brief [21:16] Synchronization numberof TRIGGER (rw) */
        vuint32_t SYN_NS:5;        /**< \brief [15:11] Synchronization number of STATE (rw) */
        vuint32_t PCM2:1;          /**< \brief [10:10] Pulse Correction Mode for SUB_INC2 generation (rw) */
        vuint32_t DLM2:1;          /**< \brief [9:9] Direct Load Mode for SUB_INC2 generation (rw) */
        vuint32_t SGE2:1;          /**< \brief [8:8] SUB_INC2 generator enable (rw) */
        vuint32_t PCM1:1;          /**< \brief [7:7] Pulse Correction Mode for SUB_INC1 generation (rw) */
        vuint32_t DLM1:1;          /**< \brief [6:6] Direct Load Mode for SUB_INC1 generation (rw) */
        vuint32_t SGE1:1;          /**< \brief [5:5] SUB_INC1 generator enable (rw) */
        vuint32_t PIT:1;           /**< \brief [4:4] Plausibility value PVT to next active TRIGGER is time related (rw) */
        vuint32_t COA:1;           /**< \brief [3:3] Correction strategy in automatic end mode (DMO=0) (rw) */
        vuint32_t IDDS:1;          /**< \brief [2:2] Input direction detection strategy in the case of SMC=0 (rw) */
        vuint32_t DEN:1;           /**< \brief [1:1] DPLL enable (rw) */
        vuint32_t DMO:1;           /**< \brief [0:0] DPLL mode select (rw) */
    } B;
} GTM_DPLL_CTRL_1;

typedef union _GTM_DPLL_CTRL_2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t WAD7:1;          /**< \brief [23:23] Write control bit of Action_7 (rw) */
        vuint32_t WAD6:1;          /**< \brief [22:22] Write control bit of Action_6 (rw) */
        vuint32_t WAD5:1;          /**< \brief [21:21] Write control bit of Action_5 (rw) */
        vuint32_t WAD4:1;          /**< \brief [20:20] Write control bit of Action_4 (rw) */
        vuint32_t WAD3:1;          /**< \brief [19:19] Write control bit of Action_3 (rw) */
        vuint32_t WAD2:1;          /**< \brief [18:18] Write control bit of Action_2 (rw) */
        vuint32_t WAD1:1;          /**< \brief [17:17] Write control bit of Action_1 (rw) */
        vuint32_t WAD0:1;          /**< \brief [16:16] Write control bit of Action_0 (rw) */
        vuint32_t AEN7:1;          /**< \brief [15:15] ACTION_7 enable (rw) */
        vuint32_t AEN6:1;          /**< \brief [14:14] ACTION_6 enable (rw) */
        vuint32_t AEN5:1;          /**< \brief [13:13] ACTION_5 enable (rw) */
        vuint32_t AEN4:1;          /**< \brief [12:12] ACTION_4 enable (rw) */
        vuint32_t AEN3:1;          /**< \brief [11:11] ACTION_3 enable (rw) */
        vuint32_t AEN2:1;          /**< \brief [10:10] ACTION_2 enable (rw) */
        vuint32_t AEN1:1;          /**< \brief [9:9] ACTION_1 enable (rw) */
        vuint32_t AEN0:1;          /**< \brief [8:8] ACTION_0 enable (rw) */
        vuint32_t reserved_0:8;    /**< \brief [7:0] \internal Reserved */
    } B;
} GTM_DPLL_CTRL_2;

typedef union _GTM_DPLL_CTRL_3 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t WAD15:1;         /**< \brief [23:23] Write control bit of Action_15 (rw) */
        vuint32_t WAD14:1;         /**< \brief [22:22] Write control bit of Action_14 (rw) */
        vuint32_t WAD13:1;         /**< \brief [21:21] Write control bit of Action_13 (rw) */
        vuint32_t WAD12:1;         /**< \brief [20:20] Write control bit of Action_12 (rw) */
        vuint32_t WAD11:1;         /**< \brief [19:19] Write control bit of Action_11 (rw) */
        vuint32_t WAD10:1;         /**< \brief [18:18] Write control bit of Action_10 (rw) */
        vuint32_t WAD9:1;          /**< \brief [17:17] Write control bit of Action_9 (rw) */
        vuint32_t WAD8:1;          /**< \brief [16:16] Write control bit of Action_8 (rw) */
        vuint32_t AEN15:1;         /**< \brief [15:15] ACTION_15 enable (rw) */
        vuint32_t AEN14:1;         /**< \brief [14:14] ACTION_14 enable (rw) */
        vuint32_t AEN13:1;         /**< \brief [13:13] ACTION_13 enable (rw) */
        vuint32_t AEN12:1;         /**< \brief [12:12] ACTION_12 enable (rw) */
        vuint32_t AEN11:1;         /**< \brief [11:11] ACTION_11 enable (rw) */
        vuint32_t AEN10:1;         /**< \brief [10:10] ACTION_10 enable (rw) */
        vuint32_t AEN9:1;          /**< \brief [9:9] ACTION_9 enable (rw) */
        vuint32_t AEN8:1;          /**< \brief [8:8] ACTION_8 enable (rw) */
        vuint32_t reserved_0:8;    /**< \brief [7:0] \internal Reserved */
    } B;
} GTM_DPLL_CTRL_3;

typedef union _GTM_DPLL_CTRL_4 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t WAD23:1;         /**< \brief [23:23] Write control bit of Action_23 (rw) */
        vuint32_t WAD22:1;         /**< \brief [22:22] Write control bit of Action_22 (rw) */
        vuint32_t WAD21:1;         /**< \brief [21:21] Write control bit of Action_21 (rw) */
        vuint32_t WAD20:1;         /**< \brief [20:20] Write control bit of Action_20 (rw) */
        vuint32_t WAD19:1;         /**< \brief [19:19] Write control bit of Action_19 (rw) */
        vuint32_t WAD18:1;         /**< \brief [18:18] Write control bit of Action_18 (rw) */
        vuint32_t WAD17:1;         /**< \brief [17:17] Write control bit of Action_17 (rw) */
        vuint32_t WAD16:1;         /**< \brief [16:16] Write control bit of Action_16 (rw) */
        vuint32_t AEN23:1;         /**< \brief [15:15] ACTION_23 enable (rw) */
        vuint32_t AEN22:1;         /**< \brief [14:14] ACTION_22 enable (rw) */
        vuint32_t AEN21:1;         /**< \brief [13:13] ACTION_21 enable (rw) */
        vuint32_t AEN20:1;         /**< \brief [12:12] ACTION_20 enable (rw) */
        vuint32_t AEN19:1;         /**< \brief [11:11] ACTION_19 enable (rw) */
        vuint32_t AEN18:1;         /**< \brief [10:10] ACTION_18 enable (rw) */
        vuint32_t AEN17:1;         /**< \brief [9:9] ACTION_17 enable (rw) */
        vuint32_t AEN16:1;         /**< \brief [8:8] ACTION_16 enable (rw) */
        vuint32_t reserved_0:8;    /**< \brief [7:0] \internal Reserved */
    } B;
} GTM_DPLL_CTRL_4;

typedef union _GTM_DPLL_CTRL_5 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t WAD31:1;         /**< \brief [23:23] Write control bit of Action_31 (rw) */
        vuint32_t WAD30:1;         /**< \brief [22:22] Write control bit of Action_30 (rw) */
        vuint32_t WAD29:1;         /**< \brief [21:21] Write control bit of Action_29 (rw) */
        vuint32_t WAD28:1;         /**< \brief [20:20] Write control bit of Action_28 (rw) */
        vuint32_t WAD27:1;         /**< \brief [19:19] Write control bit of Action_27 (rw) */
        vuint32_t WAD26:1;         /**< \brief [18:18] Write control bit of Action_26 (rw) */
        vuint32_t WAD25:1;         /**< \brief [17:17] Write control bit of Action_25 (rw) */
        vuint32_t WAD24:1;         /**< \brief [16:16] Write control bit of Action_24 (rw) */
        vuint32_t AEN31:1;         /**< \brief [15:15] ACTION_31 enable (rw) */
        vuint32_t AEN30:1;         /**< \brief [14:14] ACTION_30 enable (rw) */
        vuint32_t AEN29:1;         /**< \brief [13:13] ACTION_29 enable (rw) */
        vuint32_t AEN28:1;         /**< \brief [12:12] ACTION_28 enable (rw) */
        vuint32_t AEN27:1;         /**< \brief [11:11] ACTION_27 enable (rw) */
        vuint32_t AEN26:1;         /**< \brief [10:10] ACTION_26 enable (rw) */
        vuint32_t AEN25:1;         /**< \brief [9:9] ACTION_25 enable (rw) */
        vuint32_t AEN24:1;         /**< \brief [8:8] ACTION_24 enable (rw) */
        vuint32_t reserved_0:8;    /**< \brief [7:0] \internal Reserved */
    } B;
} GTM_DPLL_CTRL_5;

typedef union _GTM_DPLL_ACT_STA {
    vuint32_t R;
    struct {
        vuint32_t ACT_N:32;        /**< \brief [31:0] New output data values concerning to action i provided - ACT_N (rw) */
    } B;
} GTM_DPLL_ACT_STA;

typedef union _GTM_DPLL_OSW {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t OSS:2;           /**< \brief [9:8] Offset size of RAM region 2 (rw) */
        vuint32_t reserved_2:6;    /**< \brief [7:2] \internal Reserved */
        vuint32_t SWON_T:1;        /**< \brief [1:1] Switch of new TRIGGER (r) */
        vuint32_t SWON_S:1;        /**< \brief [0:0] Switch of new STATE (r) */
    } B;
} GTM_DPLL_OSW;

typedef union _GTM_DPLL_AOSV_2 {
    vuint32_t R;
    struct {
        vuint32_t AOSV_2D:8;       /**< \brief [31:24] Address offset value of the RAM 2D region - AOSV_2D (r) */
        vuint32_t AOSV_2C:8;       /**< \brief [23:16] Address offset value of the RAM 2C region (r) */
        vuint32_t AOSV_2B:8;       /**< \brief [15:8] Address offset value of the RAM 2B region (r) */
        vuint32_t AOSV_2A:8;       /**< \brief [7:0] Address offset value of the RAM 2A region (r) */
    } B;
} GTM_DPLL_AOSV_2;

typedef union _GTM_DPLL_APT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t APT_2B:10;       /**< \brief [23:14] Address pointer TRIGGER for RAM region 2b (rw) */
        vuint32_t WAPT_2B:1;       /**< \brief [13:13] Write bit for address pointer APT_2B (rw) */
        vuint32_t reserved_12:1;    /**< \brief [12:12] \internal Reserved */
        vuint32_t APT:10;          /**< \brief [11:2] Address pointer TRIGGER (rw) */
        vuint32_t WAPT:1;          /**< \brief [1:1] Write bit for address pointer APT (rw) */
        vuint32_t reserved_0:1;    /**< \brief [0:0] \internal Reserved */
    } B;
} GTM_DPLL_APT;

typedef union _GTM_DPLL_APS {
    vuint32_t R;
    struct {
        vuint32_t reserved_20:12;    /**< \brief [31:20] \internal Reserved */
        vuint32_t APS_1C2:6;       /**< \brief [19:14] Address pointer STATE for RAM region 1c2 (rw) */
        vuint32_t WAPS_1C2:1;      /**< \brief [13:13] Write bit for address pointer APS_1C2 (rw) */
        vuint32_t reserved_8:5;    /**< \brief [12:8] \internal Reserved */
        vuint32_t APS:6;           /**< \brief [7:2] Address pointer STATE (rw) */
        vuint32_t WAPS:1;          /**< \brief [1:1] Write bit for address pointer APS (rw) */
        vuint32_t reserved_0:1;    /**< \brief [0:0] \internal Reserved */
    } B;
} GTM_DPLL_APS;

typedef union _GTM_DPLL_APT_2C {
    vuint32_t R;
    struct {
        vuint32_t reserved_12:20;    /**< \brief [31:12] \internal Reserved */
        vuint32_t APT_2C:10;       /**< \brief [11:2] Address pointer TRIGGER for RAM region 2c and Actual RAM pointer address value for ADT_T[i] (rw) */
        vuint32_t reserved_0:2;    /**< \brief [1:0] \internal Reserved */
    } B;
} GTM_DPLL_APT_2C;

typedef union _GTM_DPLL_APS_1C3 {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t APS_1C3:6;       /**< \brief [7:2] Address pointer STATE for RAM region 1c3 (rw) */
        vuint32_t reserved_0:2;    /**< \brief [1:0] \internal Reserved */
    } B;
} GTM_DPLL_APS_1C3;

typedef union _GTM_DPLL_NUTC {
    vuint32_t R;
    struct {
        vuint32_t WVTN:1;          /**< \brief [31:31] Write control bit for VTN (rw) */
        vuint32_t WSYN:1;          /**< \brief [30:30] Write control bit for SYN_T and SYN_T_OLD (rw) */
        vuint32_t WNUT:1;          /**< \brief [29:29] Write control bit for NUTE and FST (rw) */
        vuint32_t reserved_25:4;    /**< \brief [28:25] \internal Reserved */
        vuint32_t VTN:6;           /**< \brief [24:19] Virtual TRIGGER number (rw) */
        vuint32_t SYN_T_OLD:3;     /**< \brief [18:16] Number of real and virtual events to be considered for the last increment (rw) */
        vuint32_t SYN_T:3;         /**< \brief [15:13] Number of real and virtual events to be considered for the current increment (rw) */
        vuint32_t reserved_11:2;    /**< \brief [12:11] \internal Reserved */
        vuint32_t FST:1;           /**< \brief [10:10] FULL_SCALE of TRIGGER (rw) */
        vuint32_t NUTE:10;         /**< \brief [9:0] Number of recent TRIGGER events used for SUB_INC1 and action calculations modulo 2*(TNUmax+1) (rw) */
    } B;
} GTM_DPLL_NUTC;

typedef union _GTM_DPLL_NUSC {
    vuint32_t R;
    struct {
        vuint32_t WVSN:1;          /**< \brief [31:31] Write control bit for VS - WVSN (rw) */
        vuint32_t WSYN:1;          /**< \brief [30:30] Write control bit for SYN_S and SYN_S_OLD (rw) */
        vuint32_t WNUS:1;          /**< \brief [29:29] Write control bit for NUSE (rw) */
        vuint32_t reserved_25:4;    /**< \brief [28:25] \internal Reserved */
        vuint32_t VSN:6;           /**< \brief [24:19] Virtual STATE number (rw) */
        vuint32_t SYN_S_OLD:6;     /**< \brief [18:13] Number of real and virtual events to be considered for the last increment (rw) */
        vuint32_t SYN_S:6;         /**< \brief [12:7] Number of real and virtual events to be considered for the current increment (rw) */
        vuint32_t FSS:1;           /**< \brief [6:6] FULL_SCALE of STATE (rw) */
        vuint32_t NUSE:6;          /**< \brief [5:0] Number of recent STATE events used for SUB_INCx calculations modulo 2*(SNUmax+1) (rw) */
    } B;
} GTM_DPLL_NUSC;

typedef union _GTM_DPLL_NTI_CNT {
    vuint32_t R;
    struct {
        vuint32_t reserved_10:22;    /**< \brief [31:10] \internal Reserved */
        vuint32_t NTI_CNT:10;      /**< \brief [9:0] Number of TRIGGERs to interrupt (rw) */
    } B;
} GTM_DPLL_NTI_CNT;

typedef union _GTM_DPLL_IRQ_NOTIFY {
    vuint32_t R;
    struct {
        vuint32_t reserved_28:4;    /**< \brief [31:28] \internal Reserved */
        vuint32_t DCGI:1;          /**< \brief [27:27] Direction change interrupt (rw) */
        vuint32_t SORI:1;          /**< \brief [26:26] STATE out of range (rw) */
        vuint32_t TORI:1;          /**< \brief [25:25] TRIGGER out of range interrupt (rw) */
        vuint32_t CDSI:1;          /**< \brief [24:24] Calculation of STATE duration done (rw) */
        vuint32_t CDTI:1;          /**< \brief [23:23] Calculation of TRIGGER duration done, only while NTI_CNT is zero (rw) */
        vuint32_t TE4I:1;          /**< \brief [22:22] TRIGGER event interrupt 4 (rw) */
        vuint32_t TE3I:1;          /**< \brief [21:21] TRIGGER event interrupt 3 (rw) */
        vuint32_t TE2I:1;          /**< \brief [20:20] TRIGGER event interrupt 2 (rw) */
        vuint32_t TE1I:1;          /**< \brief [19:19] TRIGGER event interrupt 1 (rw) */
        vuint32_t TE0I:1;          /**< \brief [18:18] TRIGGER event interrupt 0 (rw) */
        vuint32_t LL2I:1;          /**< \brief [17:17] Loss of lock interrupt for SUB_INC2 (rw) */
        vuint32_t GL2I:1;          /**< \brief [16:16] Get of lock interrupt, for SUB_INC2 (rw) */
        vuint32_t EI:1;            /**< \brief [15:15] Error interrupt (see status register bit 31) (rw) */
        vuint32_t LL1I:1;          /**< \brief [14:14] Loss of lock interrupt for SUB_INC1 (rw) */
        vuint32_t GL1I:1;          /**< \brief [13:13] Get of lock interrupt, for SUB_INC1 (rw) */
        vuint32_t W1I:1;           /**< \brief [12:12] Write access to RAM region 1b or 1c interrupt (rw) */
        vuint32_t W2I:1;           /**< \brief [11:11] RAM write access to RAM region 2 interrupt (rw) */
        vuint32_t PWI:1;           /**< \brief [10:10] Plausibility window (PVT) violation interrupt of TRIGGER (rw) */
        vuint32_t TASI:1;          /**< \brief [9:9] TRIGGER active slope interrupt (rw) */
        vuint32_t SASI:1;          /**< \brief [8:8] STATE active slope interrupt (rw) */
        vuint32_t MTI:1;           /**< \brief [7:7] Missing TRIGGER interrupt (rw) */
        vuint32_t MSI:1;           /**< \brief [6:6] Missing STATE interrupt (rw) */
        vuint32_t TISI:1;          /**< \brief [5:5] TRIGGER inactive slope interrupt (rw) */
        vuint32_t SISI:1;          /**< \brief [4:4] STATE inactive slope interrupt (rw) */
        vuint32_t TAXI:1;          /**< \brief [3:3] TRIGGER maximum hold time violation interrupt (dt > THMA > 0) (rw) */
        vuint32_t TINI:1;          /**< \brief [2:2] TRIGGER minimum hold time violation interrupt (dt <= THMI > 0) (rw) */
        vuint32_t PEI:1;           /**< \brief [1:1] DPLL enable interrupt (rw) */
        vuint32_t PDI:1;           /**< \brief [0:0] DPLL disable interrupt; announces the switch off of the DEN bit (rw) */
    } B;
} GTM_DPLL_IRQ_NOTIFY;

typedef union _GTM_DPLL_IRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_28:4;    /**< \brief [31:28] \internal Reserved */
        vuint32_t DCGI_IRQ_EN:1;    /**< \brief [27:27] Direction change interrupt enable (rw) */
        vuint32_t SORI_IRQ_EN:1;    /**< \brief [26:26] STATE out of range interrupt enable (rw) */
        vuint32_t TORI_IRQ_EN:1;    /**< \brief [25:25] TRIGGER out of range interrupt enable (rw) */
        vuint32_t CDSI_IRQ_EN:1;    /**< \brief [24:24] Interrupt enable for calculation of STATE duration done (rw) */
        vuint32_t CDTI_IRQ_EN:1;    /**< \brief [23:23] Interrupt enable for calculation of TRIGGER duration done (rw) */
        vuint32_t TE4I_IRQ_EN:1;    /**< \brief [22:22] TRIGGER event interrupt 4 enable (rw) */
        vuint32_t TE3I_IRQ_EN:1;    /**< \brief [21:21] TRIGGER event interrupt 3 enable (rw) */
        vuint32_t TE2I_IRQ_EN:1;    /**< \brief [20:20] TRIGGER event interrupt 2 enable (rw) */
        vuint32_t TE1I_IRQ_EN:1;    /**< \brief [19:19] TRIGGER event interrupt 1 enable (rw) */
        vuint32_t TE0I_IRQ_EN:1;    /**< \brief [18:18] TRIGGER event interrupt 0 enable (rw) */
        vuint32_t LL2I_IRQ_EN:1;    /**< \brief [17:17] Loss of lock interrupt enable for SUB_INC2 (rw) */
        vuint32_t GL2I_IRQ_EN:1;    /**< \brief [16:16] Get of lock interrupt enable for SUB_INC2 (rw) */
        vuint32_t EI_IRQ_EN:1;     /**< \brief [15:15] Error interrupt enable (see status register) (rw) */
        vuint32_t LL1I_IRQ_EN:1;    /**< \brief [14:14] Loss of lock interrupt enable (rw) */
        vuint32_t GL1I_IRQ_EN:1;    /**< \brief [13:13] Get of lock interrupt enable, when lock arises (rw) */
        vuint32_t W1I_IRQ_EN:1;    /**< \brief [12:12] Write access to RAM region 1b or 1c interrupt enable (rw) */
        vuint32_t W2I_IRQ_EN:1;    /**< \brief [11:11] RAM write access to RAM region 2 interrupt enable (rw) */
        vuint32_t PWI_IRQ_EN:1;    /**< \brief [10:10] Plausibility window (PVT) violation of TRIGGER interrupt enable (rw) */
        vuint32_t TASI_IRQ_EN:1;    /**< \brief [9:9] TRIGGER active slope interrupt enable (rw) */
        vuint32_t SASI_IRQ_EN:1;    /**< \brief [8:8] STATE active slope interrupt enable (rw) */
        vuint32_t MTI_IRQ_EN:1;    /**< \brief [7:7] Missing TRIGGER interrupt enable (rw) */
        vuint32_t MSI_IRQ_EN:1;    /**< \brief [6:6] Missing STATE interrupt enable (rw) */
        vuint32_t TISI_IRQ_EN:1;    /**< \brief [5:5] TRIGGER inactive slope interrupt enable (rw) */
        vuint32_t SISI_IRQ_EN:1;    /**< \brief [4:4] STATE inactive slope interrupt enable (rw) */
        vuint32_t TAXI_IRQ_EN:1;    /**< \brief [3:3] TRIGGER maximum hold time violation interrupt enable (rw) */
        vuint32_t TINI_IRQ_EN:1;    /**< \brief [2:2] TRIGGER minimum hold time violation interrupt enable (rw) */
        vuint32_t PEI_IRQ_EN:1;    /**< \brief [1:1] DPLL enable interrupt enable, when switch-on of the DEN bit (rw) */
        vuint32_t PDI_IRQ_EN:1;    /**< \brief [0:0] DPLL disable interrupt enable, when switch-off of the DEN bit (rw) */
    } B;
} GTM_DPLL_IRQ_EN;

typedef union _GTM_DPLL_IRQ_FORCINT {
    vuint32_t R;
    struct {
        vuint32_t reserved_28:4;    /**< \brief [31:28] \internal Reserved */
        vuint32_t TRG_DCGI:1;      /**< \brief [27:27] Force interrupt DCGI (rw) */
        vuint32_t TRG_SORI:1;      /**< \brief [26:26] Force Interrupt SORI (rw) */
        vuint32_t TRG_TORI:1;      /**< \brief [25:25] Force Interrupt TORI (rw) */
        vuint32_t TRG_CDSI:1;      /**< \brief [24:24] Force Interrupt CDSI (rw) */
        vuint32_t TRG_CDTI:1;      /**< \brief [23:23] Force Interrupt CDTI (rw) */
        vuint32_t TRG_TE4I:1;      /**< \brief [22:22] Force Interrupt TE4I (rw) */
        vuint32_t TRG_TE3I:1;      /**< \brief [21:21] Force Interrupt TE3I (rw) */
        vuint32_t TRG_TE2I:1;      /**< \brief [20:20] Force Interrupt TE2I (rw) */
        vuint32_t TRG_TE1I:1;      /**< \brief [19:19] Force Interrupt TE1I (rw) */
        vuint32_t TRG_TE0I:1;      /**< \brief [18:18] Force Interrupt TE0I (rw) */
        vuint32_t TRG_LL2I:1;      /**< \brief [17:17] Force Interrupt LL2I (rw) */
        vuint32_t TRG_GL2I:1;      /**< \brief [16:16] Force Interrupt GL2I (rw) */
        vuint32_t TRG_EI:1;        /**< \brief [15:15] Force Interrupt EI (rw) */
        vuint32_t TRG_LL1I:1;      /**< \brief [14:14] Force Interrupt LL1I (rw) */
        vuint32_t TRG_GL1I:1;      /**< \brief [13:13] Force Interrupt GL1I (rw) */
        vuint32_t TRG_W1I:1;       /**< \brief [12:12] Force Interrupt W1I (rw) */
        vuint32_t TRG_W2I:1;       /**< \brief [11:11] Force Interrupt W2I (rw) */
        vuint32_t TRG_PWI:1;       /**< \brief [10:10] Force Interrupt PWI (rw) */
        vuint32_t TRG_TASI:1;      /**< \brief [9:9] Force Interrupt TASI (rw) */
        vuint32_t TRG_SASI:1;      /**< \brief [8:8] Force Interrupt SASI (rw) */
        vuint32_t TRG_MTI:1;       /**< \brief [7:7] Force Interrupt MTI (rw) */
        vuint32_t TRG_MSI:1;       /**< \brief [6:6] Force Interrupt MSI (rw) */
        vuint32_t TRG_TISI:1;      /**< \brief [5:5] Force Interrupt TISI (rw) */
        vuint32_t TRG_SISI:1;      /**< \brief [4:4] Force Interrupt SISI (rw) */
        vuint32_t TRG_TAXI:1;      /**< \brief [3:3] Force Interrupt TAXI (rw) */
        vuint32_t TRG_TINI:1;      /**< \brief [2:2] Force Interrupt TINI (rw) */
        vuint32_t TRG_PEI:1;       /**< \brief [1:1] Force Interrupt PEI (rw) */
        vuint32_t TRG_PDI:1;       /**< \brief [0:0] Force Interrupt PDI (rw) */
    } B;
} GTM_DPLL_IRQ_FORCINT;

typedef union _GTM_DPLL_IRQ_MODE {
    vuint32_t R;
    struct {
        vuint32_t reserved_2:30;    /**< \brief [31:2] \internal Reserved */
        vuint32_t IRQ_MODE:2;      /**< \brief [1:0] IRQ mode selection (rw) */
    } B;
} GTM_DPLL_IRQ_MODE;

typedef volatile struct _GTM_DPLL_IRQ {
       GTM_DPLL_IRQ_NOTIFY             NOTIFY;                 /**< \brief 0, DPLL Interrupt Notification Register*/
       GTM_DPLL_IRQ_EN                 EN;                     /**< \brief 4, DPLL Interrupt Enable Register*/
       GTM_DPLL_IRQ_FORCINT            FORCINT;                /**< \brief 8, DPLL Interrupt Force Register*/
       GTM_DPLL_IRQ_MODE               MODE;                   /**< \brief C, DPLL Interrupt Mode Register*/
} GTM_DPLL_IRQ;

typedef union _GTM_DPLL_EIRQ_EN {
    vuint32_t R;
    struct {
        vuint32_t reserved_28:4;    /**< \brief [31:28] \internal Reserved */
        vuint32_t DCGI_EIRQ_EN:1;    /**< \brief [27:27] Direction change interrupt (rw) */
        vuint32_t SORI_EIRQ_EN:1;    /**< \brief [26:26] STATE out of range (rw) */
        vuint32_t TORI_EIRQ_EN:1;    /**< \brief [25:25] TRIGGER out of range interrupt (rw) */
        vuint32_t CDSI_EIRQ_EN:1;    /**< \brief [24:24] Enable interrupt when calculation of TRIGGER duration done (rw) */
        vuint32_t CDTI_EIRQ_EN:1;    /**< \brief [23:23] Enable interrupt when calculation of TRIGGER duration done (rw) */
        vuint32_t TE4I_EIRQ_EN:1;    /**< \brief [22:22] TRIGGER event interrupt 4 enable (rw) */
        vuint32_t TE3I_EIRQ_EN:1;    /**< \brief [21:21] TRIGGER event interrupt 3 enable (rw) */
        vuint32_t TE2I_EIRQ_EN:1;    /**< \brief [20:20] TRIGGER event interrupt 2 enable (rw) */
        vuint32_t TE1I_EIRQ_EN:1;    /**< \brief [19:19] TRIGGER event interrupt 1 enable (rw) */
        vuint32_t TE0I_EIRQ_EN:1;    /**< \brief [18:18] TRIGGER event interrupt 0 enable (rw) */
        vuint32_t LL2I_EIRQ_EN:1;    /**< \brief [17:17] Loss of lock interrupt enable for SUB_INC2 (rw) */
        vuint32_t GL2I_EIRQ_EN:1;    /**< \brief [16:16] Get of lock interrupt enable for SUB_INC2 (rw) */
        vuint32_t EI_EIRQ_EN:1;    /**< \brief [15:15] Error interrupt enable (see status register) (rw) */
        vuint32_t LL1I_EIRQ_EN:1;    /**< \brief [14:14] Loss of lock interrupt enable (rw) */
        vuint32_t GL1I_EIRQ_EN:1;    /**< \brief [13:13] Get of lock interrupt enable, when lock arises (rw) */
        vuint32_t W1I_EIRQ_EN:1;    /**< \brief [12:12] Write access to RAM region 1b or 1c interrupt (rw) */
        vuint32_t W2I_EIRQ_EN:1;    /**< \brief [11:11] RAM write access to RAM region 2 interrupt enable (rw) */
        vuint32_t PWI_EIRQ_EN:1;    /**< \brief [10:10] Plausibility window (PVT) violation interrupt of TRIGGER enable (rw) */
        vuint32_t TASI_EIRQ_EN:1;    /**< \brief [9:9] TRIGGER active slope interrupt enable (rw) */
        vuint32_t SASI_EIRQ_EN:1;    /**< \brief [8:8] STATE active slope interrupt enable (rw) */
        vuint32_t MTI_EIRQ_EN:1;    /**< \brief [7:7] Missing TRIGGER interrupt enable (rw) */
        vuint32_t MSI_EIRQ_EN:1;    /**< \brief [6:6] Missing STATE interrupt enable (rw) */
        vuint32_t TISI_EIRQ_EN:1;    /**< \brief [5:5] TRIGGER inactive slope interrupt enable bit (rw) */
        vuint32_t SISI_EIRQ_EN:1;    /**< \brief [4:4] STATE inactive slope interrupt enable bit (rw) */
        vuint32_t TAXI_EIRQ_EN:1;    /**< \brief [3:3] TRIGGER maximum hold time violation interrupt enable bit (rw) */
        vuint32_t TINI_EIRQ_EN:1;    /**< \brief [2:2] TRIGGER minimum hold time violation interrupt enable bit (rw) */
        vuint32_t PEI_EIRQ_EN:1;    /**< \brief [1:1] DPLL enable interrupt enable, when switch on of the DEN bit (rw) */
        vuint32_t PDI_EIRQ_EN:1;    /**< \brief [0:0] DPLL disable interrupt enable, when switch off of the DEN bit (rw) */
    } B;
} GTM_DPLL_EIRQ_EN;

typedef union _GTM_DPLL_INC_CNT1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t INC_CNT1:24;     /**< \brief [23:0] Actual number of pulses to be still sent out at the current increment until the next active input signal in automatic end mode (rw) */
    } B;
} GTM_DPLL_INC_CNT1;

typedef union _GTM_DPLL_INC_CNT2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t INC_CNT2:24;     /**< \brief [23:0] Actual number of pulses to be still sent out at the current increment until the next active input signal in automatic end mode (rw) */
    } B;
} GTM_DPLL_INC_CNT2;

typedef union _GTM_DPLL_APT_SYNC {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t APT_2B_OLD:10;    /**< \brief [23:14] Address pointer TRIGGER for RAM region 2b at synchronization time (rw) */
        vuint32_t reserved_7:7;    /**< \brief [13:7] \internal Reserved */
        vuint32_t APT_2B_STATUS:1;    /**< \brief [6:6] Address pointer 2b status (rw) */
        vuint32_t APT_2B_EXT:6;    /**< \brief [5:0] Address pointer 2b extension (rw) */
    } B;
} GTM_DPLL_APT_SYNC;

typedef union _GTM_DPLL_APS_SYNC {
    vuint32_t R;
    struct {
        vuint32_t reserved_20:12;    /**< \brief [31:20] \internal Reserved */
        vuint32_t APS_1C2_OLD:6;    /**< \brief [19:14] Address pointer STATE for RAM region 1c2 at synchronization time (rw) */
        vuint32_t reserved_7:7;    /**< \brief [13:7] \internal Reserved */
        vuint32_t APS_1C2_STATUS:1;    /**< \brief [6:6] Address pointer 1c2 status (rw) */
        vuint32_t APS_1C2_EXT:6;    /**< \brief [5:0] Address pointer 1c2 extension (rw) */
    } B;
} GTM_DPLL_APS_SYNC;

typedef union _GTM_DPLL_TBU_TS0_T {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TBU_TS0_T:24;    /**< \brief [23:0] Value of TBU_TS0 at the last TRIGGER event (rw) */
    } B;
} GTM_DPLL_TBU_TS0_T;

typedef union _GTM_DPLL_TBU_TS0_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TBU_TS0_S:24;    /**< \brief [23:0] Value of TBU_TS0 at the last STATE event (rw) */
    } B;
} GTM_DPLL_TBU_TS0_S;

typedef union _GTM_DPLL_ADD_IN_LD1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t ADD_IN_LD1:24;    /**< \brief [23:0] Input value for SUB_INC1 generation (rw) */
    } B;
} GTM_DPLL_ADD_IN_LD1;

typedef union _GTM_DPLL_ADD_IN_LD2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t ADD_IN_LD2:24;    /**< \brief [23:0] Input value for SUB_INC2 generation (rw) */
    } B;
} GTM_DPLL_ADD_IN_LD2;

typedef union _GTM_DPLL_STATUS {
    vuint32_t R;
    struct {
        vuint32_t ERR:1;           /**< \brief [31:31] Error during configuration or operation resulting in unexpected values (r) */
        vuint32_t LOCK1:1;         /**< \brief [30:30] DPLL Lock status concerning SUB_INC1 (r) */
        vuint32_t FTD:1;           /**< \brief [29:29] First TRIGGER detected (r) */
        vuint32_t FSD:1;           /**< \brief [28:28] First STATE detected (r) */
        vuint32_t SYT:1;           /**< \brief [27:27] Synchronization condition of TRIGGER fixed (r) */
        vuint32_t SYS:1;           /**< \brief [26:26] Synchronization condition of STATE fixed (r) */
        vuint32_t LOCK2:1;         /**< \brief [25:25] DPLL Lock status concerning SUB_INC2 (r) */
        vuint32_t reserved_24:1;    /**< \brief [24:24] \internal Reserved */
        vuint32_t BWD1:1;          /**< \brief [23:23] Backwards drive of SUB_INC1 (r) */
        vuint32_t BWD2:1;          /**< \brief [22:22] Backwards drive of SUB_INC2 (r) */
        vuint32_t ITN:1;           /**< \brief [21:21] Increment number of TRIGGER is not plausible (r) */
        vuint32_t ISN:1;           /**< \brief [20:20] Increment number of STATE is not plausible (r) */
        vuint32_t CAIP1:1;         /**< \brief [19:19] Calculation of lower half actionsin progress (r) */
        vuint32_t CAIP2:1;         /**< \brief [18:18] Calculation of upper half actions in progress (r) */
        vuint32_t CSVT:1;          /**< \brief [17:17] Current signal value TRIGGER (r) */
        vuint32_t CSVS:1;          /**< \brief [16:16] Current signal value STATE (r) */
        vuint32_t LOW_RES:1;       /**< \brief [15:15] Low resolution of TBU_TS0 is used for DPLL input (r) */
        vuint32_t reserved_13:2;    /**< \brief [14:13] \internal Reserved */
        vuint32_t RAM2_ERR:1;      /**< \brief [12:12] DPLL internal access to not configured RAM2 memory space (rw) */
        vuint32_t MT:1;            /**< \brief [11:11] Missing TRIGGER detected according to TOV (rw) */
        vuint32_t TOR:1;           /**< \brief [10:10] TRIGGER out of range (rw) */
        vuint32_t MS:1;            /**< \brief [9:9] Missing STATE detected according to SOV (rw) */
        vuint32_t SOR:1;           /**< \brief [8:8] STATE out of range (rw) */
        vuint32_t PSE:1;           /**< \brief [7:7] Prediction space configuration error (r) */
        vuint32_t RCT:1;           /**< \brief [6:6] Resolution conflict TRIGGER (r) */
        vuint32_t RCS:1;           /**< \brief [5:5] Resolution conflict STATE (r) */
        vuint32_t CRO:1;           /**< \brief [4:4] Calculated Reciprocal value overflow (rw) */
        vuint32_t CTO:1;           /**< \brief [3:3] Calculated TRIGGER duration overflow (rw) */
        vuint32_t reserved_2:1;    /**< \brief [2:2] \internal Reserved */
        vuint32_t CSO:1;           /**< \brief [1:1] Calculated STATE duration overflow (rw) */
        vuint32_t FPCE:1;          /**< \brief [0:0] Fast pulse correction error (rw) */
    } B;
} GTM_DPLL_STATUS;

typedef union _GTM_DPLL_ID_PMTR {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;    /**< \brief [31:9] \internal Reserved */
        vuint32_t ID_PMTR_X:9;     /**< \brief [8:0] ID information to the input signal PMTR[z] from the ARU (rw) */
    } B;
} GTM_DPLL_ID_PMTR;

typedef union _GTM_DPLL_CTRL_0_SHADOW_TRIGGER {
    vuint32_t R;
    struct {
        vuint32_t RMO:1;           /**< \brief [31:31] Reference mode (r) */
        vuint32_t reserved_29:2;    /**< \brief [30:29] \internal Reserved */
        vuint32_t IDT:1;           /**< \brief [28:28] Input delay TRIGGER (r) */
        vuint32_t reserved_27:1;    /**< \brief [27:27] \internal Reserved */
        vuint32_t AMT:1;           /**< \brief [26:26] Adapt mode TRIGGER (r) */
        vuint32_t reserved_11:15;    /**< \brief [25:11] \internal Reserved */
        vuint32_t IFP:1;           /**< \brief [10:10] Input filter position (r) */
        vuint32_t MLT:10;          /**< \brief [9:0] Multiplier for TRIGGER (r) */
    } B;
} GTM_DPLL_CTRL_0_SHADOW_TRIGGER;

typedef union _GTM_DPLL_CTRL_0_SHADOW_STATE {
    vuint32_t R;
    struct {
        vuint32_t RMO:1;           /**< \brief [31:31] Reference mode (r) */
        vuint32_t reserved_28:3;    /**< \brief [30:28] \internal Reserved */
        vuint32_t IDS:1;           /**< \brief [27:27] Input delay STATE (r) */
        vuint32_t reserved_26:1;    /**< \brief [26:26] \internal Reserved */
        vuint32_t AMS:1;           /**< \brief [25:25] Adapt mode STATE (r) */
        vuint32_t reserved_11:14;    /**< \brief [24:11] \internal Reserved */
        vuint32_t IFP:1;           /**< \brief [10:10] Input filter position (r) */
        vuint32_t reserved_0:10;    /**< \brief [9:0] \internal Reserved */
    } B;
} GTM_DPLL_CTRL_0_SHADOW_STATE;

typedef union _GTM_DPLL_CTRL_1_SHADOW_TRIGGER {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;    /**< \brief [31:8] \internal Reserved */
        vuint32_t PCM1:1;          /**< \brief [7:7] Pulse Correction Mode for SUB_INC1 generation (r) */
        vuint32_t DLM1:1;          /**< \brief [6:6] Direct Load Mode for SUB_INC1 generation (r) */
        vuint32_t SGE1:1;          /**< \brief [5:5] SUB_INC1 generator enable (r) */
        vuint32_t PIT:1;           /**< \brief [4:4] Plausibility value PVT to next valid TRIGGER is time related (r) */
        vuint32_t COA:1;           /**< \brief [3:3] Correction strategy in automatic end mode (DMO=0) (r) */
        vuint32_t reserved_1:2;    /**< \brief [2:1] \internal Reserved */
        vuint32_t DMO:1;           /**< \brief [0:0] DPLL mode select (r) */
    } B;
} GTM_DPLL_CTRL_1_SHADOW_TRIGGER;

typedef union _GTM_DPLL_CTRL_1_SHADOW_STATE {
    vuint32_t R;
    struct {
        vuint32_t reserved_11:21;    /**< \brief [31:11] \internal Reserved */
        vuint32_t PCM2:1;          /**< \brief [10:10] Pulse Correction Mode for SUB_INC2 generation (r) */
        vuint32_t DLM2:1;          /**< \brief [9:9] Direct Load Mode for SUB_INC2 generation (r) */
        vuint32_t SGE2:1;          /**< \brief [8:8] SUB_INC2 generator enable (r) */
        vuint32_t PCM1:1;          /**< \brief [7:7] Pulse Correction Mode for SUB_INC1 generation (r) */
        vuint32_t DLM1:1;          /**< \brief [6:6] Direct Load Mode for SUB_INC1 generation (r) */
        vuint32_t SGE1:1;          /**< \brief [5:5] SUB_INC1 generator enable (r) */
        vuint32_t reserved_4:1;    /**< \brief [4:4] \internal Reserved */
        vuint32_t COA:1;           /**< \brief [3:3] Correction strategy in automatic end mode (DMO=0) (r) */
        vuint32_t reserved_1:2;    /**< \brief [2:1] \internal Reserved */
        vuint32_t DMO:1;           /**< \brief [0:0] DPLL mode select (r) */
    } B;
} GTM_DPLL_CTRL_1_SHADOW_STATE;

typedef union _GTM_DPLL_RAM_INI {
    vuint32_t R;
    struct {
        vuint32_t reserved_5:27;    /**< \brief [31:5] \internal Reserved */
        vuint32_t INIT_RAM:1;      /**< \brief [4:4] RAM regions 1a, 1b and 2 are to be initialized (rw) */
        vuint32_t reserved_3:1;    /**< \brief [3:3] \internal Reserved */
        vuint32_t INIT_2:1;        /**< \brief [2:2] RAM region 2 initialization in progress (r) */
        vuint32_t INIT_1BC:1;      /**< \brief [1:1] RAM region 1b and 1c initialization in progress (r) */
        vuint32_t INIT_1A:1;       /**< \brief [0:0] RAM region 1a initialization in progress (r) */
    } B;
} GTM_DPLL_RAM_INI;

typedef union _GTM_DPLL_PSA {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSA:24;          /**< \brief [23:0] Position information of a desired action i (rw) */
    } B;
} GTM_DPLL_PSA;

typedef union _GTM_DPLL_DLA {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DLA:24;          /**< \brief [23:0] Time to react before the corresponding position value of a desired action i is reached (rw) */
    } B;
} GTM_DPLL_DLA;

typedef union _GTM_DPLL_NA {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_20:4;    /**< \brief [23:20] \internal Reserved */
        vuint32_t DW:10;           /**< \brief [19:10] Number of events to Action_i (integer part) (rw) */
        vuint32_t DB:10;           /**< \brief [9:0] Number of events to Action_i (fractional part) (rw) */
    } B;
} GTM_DPLL_NA;

typedef union _GTM_DPLL_DTA {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DTA:24;          /**< \brief [23:0] Calculated relative time to ACTION_i (rw) */
    } B;
} GTM_DPLL_DTA;

typedef union _GTM_DPLL_TS_T {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TRIGGER_TS:24;    /**< \brief [23:0] Time stamp value of the last active TRIGGER input (rw) */
    } B;
} GTM_DPLL_TS_T;

typedef union _GTM_DPLL_TS_T_OLD {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TRIGGER_TS_OLD:24;    /**< \brief [23:0] Time stamp value of the last but one active TRIGGER input (rw) */
    } B;
} GTM_DPLL_TS_T_OLD;

typedef union _GTM_DPLL_FTV_T {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TRIGGER_FT:24;    /**< \brief [23:0] Filter value of the last active TRIGGER input (rw) */
    } B;
} GTM_DPLL_FTV_T;

typedef union _GTM_DPLL_TS_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t STATE_TS:24;     /**< \brief [23:0] Time stamp value of the last active STATE input (rw) */
    } B;
} GTM_DPLL_TS_S;

typedef union _GTM_DPLL_TS_S_OLD {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t STATE_TS_OLD:24;    /**< \brief [23:0] Time stamp value of the last active STATE input (rw) */
    } B;
} GTM_DPLL_TS_S_OLD;

typedef union _GTM_DPLL_FTV_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t STATE_FT:24;     /**< \brief [23:0] Filter value of the last active STATE input (rw) */
    } B;
} GTM_DPLL_FTV_S;

typedef union _GTM_DPLL_THMI {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_16:8;    /**< \brief [23:16] \internal Reserved */
        vuint32_t THMI:16;         /**< \brief [15:0] Minimal time between active and inactive TRIGGER slope (uint16) (rw) */
    } B;
} GTM_DPLL_THMI;

typedef union _GTM_DPLL_THMA {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_16:8;    /**< \brief [23:16] \internal Reserved */
        vuint32_t THMA:16;         /**< \brief [15:0] Maximal time between active and inactive TRIGGER slope (uint16) (rw) */
    } B;
} GTM_DPLL_THMA;

typedef union _GTM_DPLL_THVAL {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t THVAL:24;        /**< \brief [23:0] Measured time from the last active slope to the next inactive TRIGGER slope in time stamp clock counts: this does mean the clock selected for the TBU_CH0_BASE (uint16) (rw) */
    } B;
} GTM_DPLL_THVAL;

typedef union _GTM_DPLL_TOV {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_16:8;    /**< \brief [23:16] \internal Reserved */
        vuint32_t TOV_DW:6;        /**< \brief [15:10] Decision value (integer part) for missing TRIGGER interrupt (rw) */
        vuint32_t TOV_DB:10;       /**< \brief [9:0] Decision value (fractional part) for missing TRIGGER interrupt (rw) */
    } B;
} GTM_DPLL_TOV;

typedef union _GTM_DPLL_TOV_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_16:8;    /**< \brief [23:16] \internal Reserved */
        vuint32_t DW:6;            /**< \brief [15:10] Decision value (integer part) for missing STATE interrupt (rw) */
        vuint32_t DB:10;           /**< \brief [9:0] Decision value (fractional part) for missing STATE interrupt (rw) */
    } B;
} GTM_DPLL_TOV_S;

typedef union _GTM_DPLL_ADD_IN_CAL1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t ADD_IN_CAL1:24;    /**< \brief [23:0] Calculated input value for SUB_INC1 generation, calculated by the DPLL (rw) */
    } B;
} GTM_DPLL_ADD_IN_CAL1;

typedef union _GTM_DPLL_ADD_IN_CAL2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t ADD_IN_CAL2:24;    /**< \brief [23:0] Input value for SUB_INC2 generation, calculated by the DPLL for SMC=RMO=1 (rw) */
    } B;
} GTM_DPLL_ADD_IN_CAL2;

typedef union _GTM_DPLL_MPVAL1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t SIX1:8;          /**< \brief [23:16] Sign extension for MPVAL1 (rw) */
        vuint32_t MPVAL1:16;       /**< \brief [15:0] Missing pulses for direct correction of SUB_INC1 pulses by the CPU (sint16) (rw) */
    } B;
} GTM_DPLL_MPVAL1;

typedef union _GTM_DPLL_MPVAL2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t SIX2:8;          /**< \brief [23:16] Sign extension for MPVAL2 (rw) */
        vuint32_t MPVAL2:16;       /**< \brief [15:0] Missing pulses for direct correction of SUB_INC2 pulses by the CPU (sint16) (rw) */
    } B;
} GTM_DPLL_MPVAL2;

typedef union _GTM_DPLL_NMB_T_TAR {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_16:8;    /**< \brief [23:16] \internal Reserved */
        vuint32_t NMB_T_TAR:16;    /**< \brief [15:0] Target Number of pulses for TRIGGER (rw) */
    } B;
} GTM_DPLL_NMB_T_TAR;

typedef union _GTM_DPLL_NMB_T_TAR_OLD {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_16:8;    /**< \brief [23:16] \internal Reserved */
        vuint32_t NMB_T_TAR_OLD:16;    /**< \brief [15:0] Target Number of pulses for TRIGGER (rw) */
    } B;
} GTM_DPLL_NMB_T_TAR_OLD;

typedef union _GTM_DPLL_NMB_S_TAR {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_20:4;    /**< \brief [23:20] \internal Reserved */
        vuint32_t NMB_S_TAR:20;    /**< \brief [19:0] Target Number of pulses for STATE (rw) */
    } B;
} GTM_DPLL_NMB_S_TAR;

typedef union _GTM_DPLL_NMB_S_TAR_OLD {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_20:4;    /**< \brief [23:20] \internal Reserved */
        vuint32_t NMB_S_TAR_OLD:20;    /**< \brief [19:0] Target Number of pulses for STATE (rw) */
    } B;
} GTM_DPLL_NMB_S_TAR_OLD;

typedef union _GTM_DPLL_RCDT_TX {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t RCDT_TX:24;      /**< \brief [23:0] Reciprocal value of expected increment duration *2^32 while only the lower 24 bits are used (rw) */
    } B;
} GTM_DPLL_RCDT_TX;

typedef union _GTM_DPLL_RCDT_SX {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t RCDT_SX:24;      /**< \brief [23:0] Reciprocal value of expected increment duration *2^32 while only the lower 24 bits are used (rw) */
    } B;
} GTM_DPLL_RCDT_SX;

typedef union _GTM_DPLL_RCDT_TX_NOM {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t RCDT_TX_NOM:24;    /**< \brief [23:0] Reciprocal value of nominal increment duration *2^32 while only the lower 24 bits are used (rw) */
    } B;
} GTM_DPLL_RCDT_TX_NOM;

typedef union _GTM_DPLL_RCDT_SX_NOM {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t RCDT_SX_NOM:24;    /**< \brief [23:0] Reciprocal value of nominal increment duration *2^32 while only the lower 24 bits are used (rw) */
    } B;
} GTM_DPLL_RCDT_SX_NOM;

typedef union _GTM_DPLL_RDT_T_ACT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t RDT_T_ACT:24;    /**< \brief [23:0] Reciprocal value of last TRIGGER increment *2^32, only the lower 24 bits are used (rw) */
    } B;
} GTM_DPLL_RDT_T_ACT;

typedef union _GTM_DPLL_RDT_S_ACT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t RDT_S_ACT:24;    /**< \brief [23:0] Reciprocal value of last STATE increment *2^32, only the lower 24 bits are used (rw) */
    } B;
} GTM_DPLL_RDT_S_ACT;

typedef union _GTM_DPLL_DT_T_ACT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DT_T_ACT:24;     /**< \brief [23:0] Calculated duration of the last TRIGGER increment (rw) */
    } B;
} GTM_DPLL_DT_T_ACT;

typedef union _GTM_DPLL_DT_S_ACT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DT_S_ACT:24;     /**< \brief [23:0] Calculated duration of the last STATE increment (rw) */
    } B;
} GTM_DPLL_DT_S_ACT;

typedef union _GTM_DPLL_EDT_T {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t EDT_T:24;        /**< \brief [23:0] Signed difference between actual value and a simple prediction of the last TRIGGER increment: sint24 (rw) */
    } B;
} GTM_DPLL_EDT_T;

typedef union _GTM_DPLL_MEDT_T {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t MEDT_T:24;       /**< \brief [23:0] Signed middle weighted difference between actual value and prediction of the last TRIGGER increments: sint24 (rw) */
    } B;
} GTM_DPLL_MEDT_T;

typedef union _GTM_DPLL_EDT_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t EDT_S:24;        /**< \brief [23:0] Signed difference between actual value and prediction of the last STATE increment: sint24 (rw) */
    } B;
} GTM_DPLL_EDT_S;

typedef union _GTM_DPLL_MEDT_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t MEDT_S:24;       /**< \brief [23:0] Signed middle weighted difference between actual value and prediction of the last STATE increments: sint24; only calculated for SYS=1 (rw) */
    } B;
} GTM_DPLL_MEDT_S;

typedef union _GTM_DPLL_CDT_TX {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CDT_TX:24;       /**< \brief [23:0] Calculated duration of the current TRIGGER increment (rw) */
    } B;
} GTM_DPLL_CDT_TX;

typedef union _GTM_DPLL_CDT_SX {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CDT_SX:24;       /**< \brief [23:0] Calculated duration of the current STATE increment (rw) */
    } B;
} GTM_DPLL_CDT_SX;

typedef union _GTM_DPLL_CDT_TX_NOM {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CDT_TX_NOM:24;    /**< \brief [23:0] Calculated duration of the current nominal TRIGGER event (rw) */
    } B;
} GTM_DPLL_CDT_TX_NOM;

typedef union _GTM_DPLL_CDT_SX_NOM {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CDT_SX_NOM:24;    /**< \brief [23:0] Calculated duration of the current nominal STATE event (rw) */
    } B;
} GTM_DPLL_CDT_SX_NOM;

typedef union _GTM_DPLL_TLR {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_8:16;    /**< \brief [23:8] \internal Reserved */
        vuint32_t TLR:8;           /**< \brief [7:0] Value is to be multiplied with the last nominal TRIGGER duration in order to get the range for the next TRIGGER event without setting TOR in the DPLL_STATUS register (rw) */
    } B;
} GTM_DPLL_TLR;

typedef union _GTM_DPLL_SLR {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_8:16;    /**< \brief [23:8] \internal Reserved */
        vuint32_t SLR:8;           /**< \brief [7:0] Value is to be multiplied with the last nominal STATE duration in order to get the range for the next STATE event without setting SOR in the DPLL_STATUS register (rw) */
    } B;
} GTM_DPLL_SLR;

typedef union _GTM_DPLL_PDT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DW:10;           /**< \brief [23:14] Integer part of relation between TRIGGER or STATE increments (rw) */
        vuint32_t DB:14;           /**< \brief [13:0] Fractional part of relation between TRIGGER or STATE increments (rw) */
    } B;
} GTM_DPLL_PDT;

typedef union _GTM_DPLL_MLS1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_18:6;    /**< \brief [23:18] \internal Reserved */
        vuint32_t MLS1:18;         /**< \brief [17:0] Number of pulses between two STATE events (rw) */
    } B;
} GTM_DPLL_MLS1;

typedef union _GTM_DPLL_MLS2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_18:6;    /**< \brief [23:18] \internal Reserved */
        vuint32_t MLS2:18;         /**< \brief [17:0] Number of pulses between two STATE events (to be set and updated by the CPU) (rw) */
    } B;
} GTM_DPLL_MLS2;

typedef union _GTM_DPLL_CNT_NUM_1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CNT_NUM_1:24;    /**< \brief [23:0] Counter for number of SUB_INC1 pulses (rw) */
    } B;
} GTM_DPLL_CNT_NUM_1;

typedef union _GTM_DPLL_CNT_NUM_2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CNT_NUM_2:24;    /**< \brief [23:0] Counter for number of SUB_INC2 pulses (rw) */
    } B;
} GTM_DPLL_CNT_NUM_2;

typedef union _GTM_DPLL_PVT {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PVT:24;          /**< \brief [23:0] Plausibility value of next active TRIGGER slope (rw) */
    } B;
} GTM_DPLL_PVT;

typedef union _GTM_DPLL_PSTC {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSTC:24;         /**< \brief [23:0] Calculated position stamp of last TRIGGER input (rw) */
    } B;
} GTM_DPLL_PSTC;

typedef union _GTM_DPLL_PSSC {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSSC:24;         /**< \brief [23:0] Calculated position stamp for the last STATE input (rw) */
    } B;
} GTM_DPLL_PSSC;

typedef union _GTM_DPLL_PSTM {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSTM:24;         /**< \brief [23:0] Position stamp of TRIGGER, measured (rw) */
    } B;
} GTM_DPLL_PSTM;

typedef union _GTM_DPLL_PSTM_OLD {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSTM_OLD:24;     /**< \brief [23:0] Last but one position stamp of TRIGGER, measured (rw) */
    } B;
} GTM_DPLL_PSTM_OLD;

typedef union _GTM_DPLL_PSSM {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSSM:24;         /**< \brief [23:0] Position stamp of STATE, measured (rw) */
    } B;
} GTM_DPLL_PSSM;

typedef union _GTM_DPLL_PSSM_OLD {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSSM_OLD:24;     /**< \brief [23:0] Last but one position stamp of STATE, measured (rw) */
    } B;
} GTM_DPLL_PSSM_OLD;

typedef union _GTM_DPLL_NMB_T {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_16:8;    /**< \brief [23:16] \internal Reserved */
        vuint32_t NMB_T:16;        /**< \brief [15:0] Number of pulses for TRIGGER (rw) */
    } B;
} GTM_DPLL_NMB_T;

typedef union _GTM_DPLL_NMB_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_20:4;    /**< \brief [23:20] \internal Reserved */
        vuint32_t NMB_S:20;        /**< \brief [19:0] Number of pulses for STATE (rw) */
    } B;
} GTM_DPLL_NMB_S;

typedef union _GTM_DPLL_RDT_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t RDT_S:24;        /**< \brief [23:0] Reciprocal difference time of STATE (rw) */
    } B;
} GTM_DPLL_RDT_S;

typedef union _GTM_DPLL_TSF_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TSF_S:24;        /**< \brief [23:0] Time stamp field of STATE (rw) */
    } B;
} GTM_DPLL_TSF_S;

typedef union _GTM_DPLL_ADT_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t reserved_22:2;    /**< \brief [23:22] \internal Reserved */
        vuint32_t NS:6;            /**< \brief [21:16] Number of STATEs (rw) */
        vuint32_t PD_S:16;         /**< \brief [15:0] Physical deviation of STATE (rw) */
    } B;
} GTM_DPLL_ADT_S;

typedef union _GTM_DPLL_DT_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DT_S:24;         /**< \brief [23:0] Difference time of STATE (rw) */
    } B;
} GTM_DPLL_DT_S;

typedef union _GTM_DPLL_TSAC {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TSAC:24;         /**< \brief [23:0] Calculated time stamp for ACTION_z (rw) */
    } B;
} GTM_DPLL_TSAC;

typedef union _GTM_DPLL_PSAC {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t PSAC:24;         /**< \brief [23:0] Calculated position value for the start of ACTION_z in normal or emergency mode according to equations DPLL-17 or DPLL-20, respectively (rw) */
    } B;
} GTM_DPLL_PSAC;

typedef union _GTM_DPLL_ACB {
    vuint32_t R;
    struct {
        vuint32_t reserved_29:3;    /**< \brief [31:29] \internal Reserved */
        vuint32_t ACB_3:5;         /**< \brief [28:24] Action Control Bits of ACTION_(i + 3) (rw) */
        vuint32_t reserved_21:3;    /**< \brief [23:21] \internal Reserved */
        vuint32_t ACB_2:5;         /**< \brief [20:16] Action Control Bits of ACTION_(i + 2) (rw) */
        vuint32_t reserved_13:3;    /**< \brief [15:13] \internal Reserved */
        vuint32_t ACB_1:5;         /**< \brief [12:8] Action Control Bits of ACTION_(i + 1) (rw) */
        vuint32_t reserved_5:3;    /**< \brief [7:5] \internal Reserved */
        vuint32_t ACB_0:5;         /**< \brief [4:0] Action Control Bits of ACTION_z (rw) */
    } B;
} GTM_DPLL_ACB;

typedef union _GTM_DPLL_CTRL_11 {
    vuint32_t R;
    struct {
        vuint32_t WACBU:1;         /**< \brief [31:31] Write enable for ACB use (rw) */
        vuint32_t WSTATE_EXT:1;    /**< \brief [30:30] Write enable of STATE_EXT (rw) */
        vuint32_t WPCMF2_INCCNT_B:1;    /**< \brief [29:29] Write enable of PCMF2_INCCNT_B (rw) */
        vuint32_t WINCF2:1;        /**< \brief [28:28] Write enable for INC_CNT2 fast (rw) */
        vuint32_t WFSYL2:1;        /**< \brief [27:27] Write enable for force synchronization loss 2 (rw) */
        vuint32_t WPCMF2:1;        /**< \brief [26:26] Write enable for pulse correction mode fast 2 (rw) */
        vuint32_t WERZ2:1;         /**< \brief [25:25] Write enable for error zero 2 (rw) */
        vuint32_t WSIP2:1;         /**< \brief [24:24] Write enable for simplified increment prediction 2 (rw) */
        vuint32_t WADS:1;          /**< \brief [23:23] Write enable of ADS (r) */
        vuint32_t WADT:1;          /**< \brief [22:22] Write enable of ADT (r) */
        vuint32_t WPCMF1_INCCNT_B:1;    /**< \brief [21:21] Write enable of PCMF1_INCCNT_B (rw) */
        vuint32_t WINCF1:1;        /**< \brief [20:20] Write enable for INC_CNT1 fast (rw) */
        vuint32_t WFSYL1:1;        /**< \brief [19:19] Write enable for force synchronization loss 1 (rw) */
        vuint32_t WPCMF1:1;        /**< \brief [18:18] Write enable for pulse correction mode fast 1 (rw) */
        vuint32_t WERZ1:1;         /**< \brief [17:17] Write enable for error zero 1 (rw) */
        vuint32_t WSIP1:1;         /**< \brief [16:16] Write enable for simplified increment prediction 1 (rw) */
        vuint32_t ACBU:1;          /**< \brief [15:15] ACB use; the ACB values of PMTR are used to decide if an action is in the past (rw) */
        vuint32_t STATE_EXT:1;     /**< \brief [14:14] Use of STATE engine extension (rw) */
        vuint32_t PCMF2_INCCNT_B:1;    /**< \brief [13:13] No increment of INC_CNT2 when PCMF2 active (automatic end mode) (rw) */
        vuint32_t INCF2:1;         /**< \brief [12:12] INC_CNT2 fast (rw) */
        vuint32_t FSYL2:1;         /**< \brief [11:11] Force Synchronization Loss of LOCK2 (rw) */
        vuint32_t PCMF2:1;         /**< \brief [10:10] Pulse correction mode fast for INC_CNT2 (rw) */
        vuint32_t ERZ2:1;          /**< \brief [9:9] Error is assumed as zero in emergency mode and for the second engine for SMC=1 (rw) */
        vuint32_t SIP2:1;          /**< \brief [8:8] Simplified increment prediction in emergency mode and for the second engine in the case RMO=1 (rw) */
        vuint32_t ADS:1;           /**< \brief [7:7] Correction of DT_S_ACTUAL, CDT_SX_nom_corr by PD_S (r) */
        vuint32_t ADT:1;           /**< \brief [6:6] Correction of DT_T_ACTUAL,CDT_TX_nom_corr by PD_T (r) */
        vuint32_t PCMF1_INCCNT_B:1;    /**< \brief [5:5] No increment of INC_CNT1 when PCMF1 active (automatic end mode) (rw) */
        vuint32_t INCF1:1;         /**< \brief [4:4] INC_CNT1 fast correction (rw) */
        vuint32_t FSYL1:1;         /**< \brief [3:3] Force Synchronization Loss of LOCK1 (rw) */
        vuint32_t PCMF1:1;         /**< \brief [2:2] Pulse correction mode fast for INC_CNT1 (rw) */
        vuint32_t ERZ1:1;          /**< \brief [1:1] Error is assumed as zero in normal mode and for the first engine for SMC=1 (rw) */
        vuint32_t SIP1:1;          /**< \brief [0:0] Simplified increment prediction in normal mode and for the first engine in the case SMC=1 (rw) */
    } B;
} GTM_DPLL_CTRL_11;

typedef union _GTM_DPLL_THVAL2 {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t THVAL:24;        /**< \brief [23:0] Measured last pulse time from active to inactive slope of TRIGGER after correction of input slope filter delays (r) */
    } B;
} GTM_DPLL_THVAL2;

typedef union _GTM_DPLL_TIDEL {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t TIDEL:24;        /**< \brief [23:0] TRIGGER input delay (rw) */
    } B;
} GTM_DPLL_TIDEL;

typedef union _GTM_DPLL_SIDEL {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t SIDEL:24;        /**< \brief [23:0] STATE input delay (rw) */
    } B;
} GTM_DPLL_SIDEL;

typedef union _GTM_DPLL_APS_SYNC_EXT {
    vuint32_t R;
    struct {
        vuint32_t reserved_23:9;    /**< \brief [31:23] \internal Reserved */
        vuint32_t APS_1C2_OLD:7;    /**< \brief [22:16] Address pointer STATE for RAM region 1c2 at synchronization time (rw) */
        vuint32_t APS_1C2_STATUS:1;    /**< \brief [15:15] Address pointer 1c2 status (rw) */
        vuint32_t reserved_7:8;    /**< \brief [14:7] \internal Reserved */
        vuint32_t APS_1C2_EXT:7;    /**< \brief [6:0] Address pointer 1c2 extension (rw) */
    } B;
} GTM_DPLL_APS_SYNC_EXT;

typedef union _GTM_DPLL_CTRL_EXT {
    vuint32_t R;
    struct {
        vuint32_t reserved_22:10;    /**< \brief [31:22] \internal Reserved */
        vuint32_t SYN_NS:6;        /**< \brief [21:16] Synchronization number of STATE (rw) */
        vuint32_t reserved_6:10;    /**< \brief [15:6] \internal Reserved */
        vuint32_t SNU:6;           /**< \brief [5:0] STATE number (rw) */
    } B;
} GTM_DPLL_CTRL_EXT;

typedef union _GTM_DPLL_APS_EXT {
    vuint32_t R;
    struct {
        vuint32_t reserved_21:11;    /**< \brief [31:21] \internal Reserved */
        vuint32_t APS_1C2:7;       /**< \brief [20:14] Actual RAM pointer address value for TSF_S[i] (rw) */
        vuint32_t WAPS_1C2:1;      /**< \brief [13:13] Write bit for address pointer APS_1C2 (rw) */
        vuint32_t reserved_9:4;    /**< \brief [12:9] \internal Reserved */
        vuint32_t APS:7;           /**< \brief [8:2] Actual RAM pointer address value for DT_S[i] and RDT_S[i] (rw) */
        vuint32_t WAPS:1;          /**< \brief [1:1] Write bit for address pointer APS (rw) */
        vuint32_t reserved_0:1;    /**< \brief [0:0] \internal Reserved */
    } B;
} GTM_DPLL_APS_EXT;

typedef union _GTM_DPLL_APS_1C3_EXT {
    vuint32_t R;
    struct {
        vuint32_t reserved_9:23;    /**< \brief [31:9] \internal Reserved */
        vuint32_t APS_1C3:7;       /**< \brief [8:2] Actual RAM pointer address value for ADT_S[i] (rw) */
        vuint32_t reserved_0:2;    /**< \brief [1:0] \internal Reserved */
    } B;
} GTM_DPLL_APS_1C3_EXT;

typedef union _GTM_DPLL_STA {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CNT_S:3;         /**< \brief [23:21] Count STATE (r) */
        vuint32_t reserved_20:1;    /**< \brief [20:20] \internal Reserved */
        vuint32_t STA_S:8;         /**< \brief [19:12] Status of STATE state machine (r) */
        vuint32_t CNT_T:3;         /**< \brief [11:9] Count TRIGGER (r) */
        vuint32_t reserved_8:1;    /**< \brief [8:8] \internal Reserved */
        vuint32_t STA_T:8;         /**< \brief [7:0] Status of TRIGGER state machine; state binary coded (r) */
    } B;
} GTM_DPLL_STA;

typedef union _GTM_DPLL_INCF1_OFFSET {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DPLL_INCF1_OFFSET:24;    /**< \brief [23:0] Start value of the ADD_IN_ADDER1 (rw) */
    } B;
} GTM_DPLL_INCF1_OFFSET;

typedef union _GTM_DPLL_INCF2_OFFSET {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DPLL_INCF2_OFFSET:24;    /**< \brief [23:0] Start value of the ADD_IN_ADDER2 (rw) */
    } B;
} GTM_DPLL_INCF2_OFFSET;

typedef union _GTM_DPLL_DT_T_START {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DPLL_DT_T_START:24;    /**< \brief [23:0] Start value of DPLL_DT_T_ACT for the first increment after SIP1 is set to 1 (rw) */
    } B;
} GTM_DPLL_DT_T_START;

typedef union _GTM_DPLL_DT_S_START {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t DPLL_DT_S_START:24;    /**< \brief [23:0] Start value of DPLL_DT_S_ACT for the first increment after SIP2 is set to 1 (rw) */
    } B;
} GTM_DPLL_DT_S_START;

typedef union _GTM_DPLL_STA_MASK {
    vuint32_t R;
    struct {
        vuint32_t reserved_16:16;    /**< \brief [31:16] \internal Reserved */
        vuint32_t STA_NOTIFY_S:8;    /**< \brief [15:8] Notify value for STA_S of register DPLL_STA (rw) */
        vuint32_t STA_NOTIFY_T:8;    /**< \brief [7:0] Notify value for STA_T of register DPLL_STA (rw) */
    } B;
} GTM_DPLL_STA_MASK;

typedef union _GTM_DPLL_STA_FLAG {
    vuint32_t R;
    struct {
        vuint32_t reserved_11:21;    /**< \brief [31:11] \internal Reserved */
        vuint32_t INC_CNT2_FLAG:1;    /**< \brief [10:10] Flag according to DPLL_INC_CNT2_MASK.INC_CNT2_NOTIFY (rw) */
        vuint32_t INC_CNT1_FLAG:1;    /**< \brief [9:9] Flag according to DPLL_INC_CNT1_MASK.INC_CNT1_NOTIFY (rw) */
        vuint32_t STA_FLAG_S:1;    /**< \brief [8:8] Flag according to DPLL_STA_MASK.STA_NOTIFY_S (rw) */
        vuint32_t reserved_1:7;    /**< \brief [7:1] \internal Reserved */
        vuint32_t STA_FLAG_T:1;    /**< \brief [0:0] Flag according to DPLL_MASK.STA_NOTIFY_T (rw) */
    } B;
} GTM_DPLL_STA_FLAG;

typedef union _GTM_DPLL_INC_CNT1_MASK {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t INC_CNT1_NOTIFY:24;    /**< \brief [23:0] Notify value for INC_CNT1 of register DPLL_INC_CNT1 (rw) */
    } B;
} GTM_DPLL_INC_CNT1_MASK;

typedef union _GTM_DPLL_INC_CNT2_MASK {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t INC_CNT2_NOTIFY:24;    /**< \brief [23:0] Notify value for INC_CNT2 of register DPLL_INC_CNT2 (rw) */
    } B;
} GTM_DPLL_INC_CNT2_MASK;

typedef union _GTM_DPLL_NUSC_EXT1 {
    vuint32_t R;
    struct {
        vuint32_t reserved_31:1;    /**< \brief [31:31] \internal Reserved */
        vuint32_t WSYN:1;          /**< \brief [30:30] Write control bit for SYN_S and SYN_S_OLD (rw) */
        vuint32_t reserved_23:7;    /**< \brief [29:23] \internal Reserved */
        vuint32_t SYN_S_OLD:7;     /**< \brief [22:16] Number of real and virtual events to be considered for the last increment (rw) */
        vuint32_t reserved_7:9;    /**< \brief [15:7] \internal Reserved */
        vuint32_t SYN_S:7;         /**< \brief [6:0] Number of real and virtual events to be considered for the current increment (rw) */
    } B;
} GTM_DPLL_NUSC_EXT1;

typedef union _GTM_DPLL_NUSC_EXT2 {
    vuint32_t R;
    struct {
        vuint32_t WVSN:1;          /**< \brief [31:31] Write control bit for VSN (rw) */
        vuint32_t reserved_30:1;    /**< \brief [30:30] \internal Reserved */
        vuint32_t WNUS:1;          /**< \brief [29:29] Write control bit for NUSE (rw) */
        vuint32_t reserved_23:6;    /**< \brief [28:23] \internal Reserved */
        vuint32_t VSN:7;           /**< \brief [22:16] Number of virtual state increments in the current NUSE region (rw) */
        vuint32_t FSS:1;           /**< \brief [15:15] This value is to be set, when NUSE is set to FULL_SCALE (rw) */
        vuint32_t reserved_7:8;    /**< \brief [14:7] \internal Reserved */
        vuint32_t NUSE:7;          /**< \brief [6:0] Number of recent STATE events used for SUB_INCx calculations modulo 2*(SNUmax+1) (rw) */
    } B;
} GTM_DPLL_NUSC_EXT2;

typedef union _GTM_DPLL_CTN_MIN {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CTN_MIN:24;      /**< \brief [23:0] CDT_T_NOM min value (rw) */
    } B;
} GTM_DPLL_CTN_MIN;

typedef union _GTM_DPLL_CTN_MAX {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CTN_MAX:24;      /**< \brief [23:0] CDT_T_NOM max value (rw) */
    } B;
} GTM_DPLL_CTN_MAX;

typedef union _GTM_DPLL_CSN_MIN {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CSN_MIN:24;      /**< \brief [23:0] CDT_SX_NOM min value (rw) */
    } B;
} GTM_DPLL_CSN_MIN;

typedef union _GTM_DPLL_CSN_MAX {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;    /**< \brief [31:24] \internal Reserved */
        vuint32_t CSN_MAX:24;      /**< \brief [23:0] CDT_SX_NOM max value (rw) */
    } B;
} GTM_DPLL_CSN_MAX;

typedef union _GTM_DPLL_SW_TRIG {
    vuint32_t R;
    struct {
        vuint32_t reserved_8:24;          /**< \brief [31:8] \internal Reserved */
        vuint32_t WSTATE_LEVEL:1;         /**< \brief [7:7] Write enable for DPLL_SW_TRIG.STATE_LEVEL */
        vuint32_t STATE_LEVEL:1;          /**< \brief [6:6] Input signal level of software triggered input event for STATE */
        vuint32_t WSTATE_EVENT:1;         /**< \brief [5:5] Write enable for DPLL_SW_TRIG.STATE_EVENT */
        vuint32_t STATE_EVENT:1;          /**< \brief [4:4] Software triggered input event for STATE */
        vuint32_t WTRIG_LEVEL:1;          /**< \brief [3:3] Write enable for DPLL_SW_TRIG.TRIG_LEVEL */
        vuint32_t TRIG_LEVEL:1;           /**< \brief [2:2] Input signal level of software triggered input event for TRIGGER */
        vuint32_t WTRIG_EVENT:1;          /**< \brief [1:1] Write enable for DPLL_SW_TRIG.TRIG_EVENT */
        vuint32_t TRIG_EVENT:1;           /**< \brief [0:0] Software triggered input event for TRIGGER */
    } B;
} GTM_DPLL_SW_TRIG;

typedef union _GTM_DPLL_MP_T {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;          /**< \brief [31:24] \internal Reserved */
        vuint32_t MP_T:24;                /**< \brief [23:0] Number of missing pulses of the SUB_INC1 pulses in automatic end mode (DPLL_CTRL_1.DMO=0) */
    } B;
} GTM_DPLL_MP_T;

typedef union _GTM_DPLL_MP_S {
    vuint32_t R;
    struct {
        vuint32_t reserved_24:8;          /**< \brief [31:24] \internal Reserved */
        vuint32_t MP_S:24;                /**< \brief [23:0] Number of missing pulses of the SUB_INC1/SUB_INC2 pulses in automatic end mode (DPLL_CTRL_1.DMO=0) */
    } B;
} GTM_DPLL_MP_S;

typedef union _GTM_DPLL_CTRL_12 {
    vuint32_t R;
    struct {
        vuint32_t reserved_17:15;             /**< \brief [31:17] \internal Reserved */
        vuint32_t WSUBINC_MUX_SEL:1;          /**< \brief [16:16] Write enable for DPLL_CTRL_12.SUBINC_MUX_SEL */
        vuint32_t reserved_1:15;              /**< \brief [15:1] \internal Reserved */
        vuint32_t SUBINC_MUX_SEL:1;           /**< \brief [0:0] Selection of DPLL sub increment source for CCM[0]_TBU_TS1 angle base */
    } B;
} GTM_DPLL_CTRL_12;

typedef volatile struct _GTM_DPLL {
       GTM_DPLL_CTRL_0                 CTRL_0;                 /**< \brief 0, DPLL Control Register 0*/
       GTM_DPLL_CTRL_1                 CTRL_1;                 /**< \brief 4, DPLL Control Register 1*/
       GTM_DPLL_CTRL_2                 CTRL_2;                 /**< \brief 8, DPLL Control Register 2*/
       GTM_DPLL_CTRL_3                 CTRL_3;                 /**< \brief C, DPLL Control Register 3*/
       GTM_DPLL_CTRL_4                 CTRL_4;                 /**< \brief 10, DPLL Control Register 4*/
       GTM_DPLL_CTRL_5                 CTRL_5;                 /**< \brief 14, DPLL Control Register 5*/
       GTM_DPLL_ACT_STA                ACT_STA;                /**< \brief 18, DPLL ACTION Status Register with Connected Shadow Register*/
       GTM_DPLL_OSW                    OSW;                    /**< \brief 1C, DPLL Offset and Switch Old/New Address Register*/
       GTM_DPLL_AOSV_2                 AOSV_2;                 /**< \brief 20, DPLL Address Offset Register of RAM 2 Regions*/
       GTM_DPLL_APT                    APT;                    /**< \brief 24, DPLL Actual RAM Pointer Address for TRIGGER*/
       GTM_DPLL_APS                    APS;                    /**< \brief 28, DPLL Actual RAM Pointer Address for STATE*/
       GTM_DPLL_APT_2C                 APT_2C;                 /**< \brief 2C, DPLL Actual RAM Pointer for Region 2C*/
       GTM_DPLL_APS_1C3                APS_1C3;                /**< \brief 30, DPLL Actual RAM Pointer for RAM Region 1C3*/
       GTM_DPLL_NUTC                   NUTC;                   /**< \brief 34, DPLL Number of Recent TRIGGER Events Used for Calculations*/
       GTM_DPLL_NUSC                   NUSC;                   /**< \brief 38, DPLL Number of Recent STATE Events Used for Calculations*/
       GTM_DPLL_NTI_CNT                NTI_CNT;                /**< \brief 3C, DPLL Number of Active TRIGGER Events to Interrupt*/
       GTM_DPLL_IRQ                    IRQ;                    /**< \brief 40, DPLL Interrupt Mode Register*/
       GTM_DPLL_EIRQ_EN                EIRQ_EN;                /**< \brief 50, DPLL Error Interrupt Enable Register*/
       vuint8_t                   reserved_54[92];        /**< \brief 54, \internal Reserved */
       GTM_DPLL_INC_CNT1               INC_CNT1;               /**< \brief B0, DPLL Counter for Pulses for TBU_CH1_BASE to be Sent in Automatic End Mode*/
       GTM_DPLL_INC_CNT2               INC_CNT2;               /**< \brief B4, DPLL Counter for Pulses for TBU_TS2 to be Sent in Automatic End Mode*/
       GTM_DPLL_APT_SYNC               APT_SYNC;               /**< \brief B8, DPLL Old RAM Pointer and Offset Value for TRIGGER*/
       GTM_DPLL_APS_SYNC               APS_SYNC;               /**< \brief BC, DPLL Old RAM Pointer and Offset Value for STATE*/
       GTM_DPLL_TBU_TS0_T              TBU_TS0_T;              /**< \brief C0, DPLL TBU_TS0 Value at Last TRIGGER Event*/
       GTM_DPLL_TBU_TS0_S              TBU_TS0_S;              /**< \brief C4, DPLL TBU_TS0 Value at Last STATE Event*/
       GTM_DPLL_ADD_IN_LD1             ADD_IN_LD1;             /**< \brief C8, DPLL Direct Load Input Value for SUB_INC1*/
       GTM_DPLL_ADD_IN_LD2             ADD_IN_LD2;             /**< \brief CC, DPLL Direct Load Input Value for SUB_INC2*/
       vuint8_t                   reserved_D0[44];        /**< \brief D0, \internal Reserved */
       GTM_DPLL_STATUS                 STATUS;                 /**< \brief FC, DPLL Status Register*/
       GTM_DPLL_ID_PMTR                ID_PMTR[32];            /**< \brief 100, DPLL ID Information for Input Signal PMT ${z} Register*/
       vuint8_t                   reserved_180[96];       /**< \brief 180, \internal Reserved */
       GTM_DPLL_CTRL_0_SHADOW_TRIGGER  CTRL_0_SHADOW_TRIGGER;    /**< \brief 1E0, DPLL Control 0 Shadow Trigger Register*/
       GTM_DPLL_CTRL_0_SHADOW_STATE    CTRL_0_SHADOW_STATE;    /**< \brief 1E4, DPLL Control 0 Shadow STATE Register*/
       GTM_DPLL_CTRL_1_SHADOW_TRIGGER  CTRL_1_SHADOW_TRIGGER;    /**< \brief 1E8, DPLL Control 1 Shadow TRIGGER Register*/
       GTM_DPLL_CTRL_1_SHADOW_STATE    CTRL_1_SHADOW_STATE;    /**< \brief 1EC, DPLL Control 1 Shadow STATE Register*/
       vuint8_t                   reserved_1F0[12];       /**< \brief 1F0, \internal Reserved */
       GTM_DPLL_RAM_INI                RAM_INI;                /**< \brief 1FC, DPLL RAM Initialization Register*/
       GTM_DPLL_PSA                    PSA[32];                /**< \brief 200, DPLL ACTION_${i} Position/Value Request*/
       GTM_DPLL_DLA                    DLA[32];                /**< \brief 280, DPLL ACTION_${i} Time to React before PSAi*/
       GTM_DPLL_NA                     NA[32];                 /**< \brief 300, DPLL Calculated Number of TRIGGER/STATE Increments to ACTION_${i}*/
       GTM_DPLL_DTA                    DTA[32];                /**< \brief 380, DPLL Calculated Relative TIME to ACTION_${i}*/
       GTM_DPLL_TS_T                   TS_T;                   /**< \brief 400, DPLL Actual TRIGGER Time Stamp Value*/
       GTM_DPLL_TS_T_OLD               TS_T_OLD;               /**< \brief 404, DPLL Previous TRIGGER Time Stamp Value*/
       GTM_DPLL_FTV_T                  FTV_T;                  /**< \brief 408, DPLL Actual TRIGGER Filter Value*/
       vuint8_t                   reserved_40C[4];        /**< \brief 40C, \internal Reserved */
       GTM_DPLL_TS_S                   TS_S;                   /**< \brief 410, DPLL Actual STATE Time Stamp*/
       GTM_DPLL_TS_S_OLD               TS_S_OLD;               /**< \brief 414, DPLL Previous STATE Time Stamp*/
       GTM_DPLL_FTV_S                  FTV_S;                  /**< \brief 418, DPLL Actual STATE Filter Value*/
       vuint8_t                   reserved_41C[4];        /**< \brief 41C, \internal Reserved */
       GTM_DPLL_THMI                   THMI;                   /**< \brief 420, DPLL TRIGGER Hold Time Minimum Value*/
       GTM_DPLL_THMA                   THMA;                   /**< \brief 424, DPLL TRIGGER Hold Time Maximum Value*/
       GTM_DPLL_THVAL                  THVAL;                  /**< \brief 428, DPLL Measured TRIGGER Hold Time Value*/
       vuint8_t                   reserved_42C[4];        /**< \brief 42C, \internal Reserved */
       GTM_DPLL_TOV                    TOV;                    /**< \brief 430, DPLL Time Out Value of Active TRIGGER Slope*/
       GTM_DPLL_TOV_S                  TOV_S;                  /**< \brief 434, DPLL Time Out Value of Active STATE Slope*/
       GTM_DPLL_ADD_IN_CAL1            ADD_IN_CAL1;            /**< \brief 438, DPLL Calculated ADD_IN Value for SUB_INC1 Generation*/
       GTM_DPLL_ADD_IN_CAL2            ADD_IN_CAL2;            /**< \brief 43C, DPLL Calculated ADD_IN Value for SUB_INC2 Generation*/
       GTM_DPLL_MPVAL1                 MPVAL1;                 /**< \brief 440, DPLL Missing Pulses to be Added or Subtracted Directly 1*/
       GTM_DPLL_MPVAL2                 MPVAL2;                 /**< \brief 444, DPLL Missing Pulses to be Added or Subtracted Directly 2*/
       GTM_DPLL_NMB_T_TAR              NMB_T_TAR;              /**< \brief 448, DPLL Target Number of Pulses to be Sent in Normal Mode*/
       GTM_DPLL_NMB_T_TAR_OLD          NMB_T_TAR_OLD;          /**< \brief 44C, DPLL Last but One Target Number of Pulses to be Sent in Normal Mode*/
       GTM_DPLL_NMB_S_TAR              NMB_S_TAR;              /**< \brief 450, DPLL Target Number of Pulses to be Sent in Emergency Mode*/
       GTM_DPLL_NMB_S_TAR_OLD          NMB_S_TAR_OLD;          /**< \brief 454, DPLL Last but One Target Number of Pulses to be Sent in Emergency Mode*/
       vuint8_t                   reserved_458[8];        /**< \brief 458, \internal Reserved */
       GTM_DPLL_RCDT_TX                RCDT_TX;                /**< \brief 460, DPLL Reciprocal Value of the Expected Increment Duration of TRIGGER*/
       GTM_DPLL_RCDT_SX                RCDT_SX;                /**< \brief 464, DPLL Reciprocal Value of the Expected Increment Duration of STATE*/
       GTM_DPLL_RCDT_TX_NOM            RCDT_TX_NOM;            /**< \brief 468, DPLL Reciprocal Value of the Expected Nominal Increment Duration of TRIGGER*/
       GTM_DPLL_RCDT_SX_NOM            RCDT_SX_NOM;            /**< \brief 46C, DPLL Reciprocal Value of the Expected Nominal Increment Duration of STATE*/
       GTM_DPLL_RDT_T_ACT              RDT_T_ACT;              /**< \brief 470, DPLL Reciprocal Value of the Last Increment of TRIGGER*/
       GTM_DPLL_RDT_S_ACT              RDT_S_ACT;              /**< \brief 474, DPLL Reciprocal Value of the Last Increment of STATE*/
       GTM_DPLL_DT_T_ACT               DT_T_ACT;               /**< \brief 478, DPLL Duration of the Last TRIGGER Increment*/
       GTM_DPLL_DT_S_ACT               DT_S_ACT;               /**< \brief 47C, DPLL Duration of the Last STATE Increment*/
       GTM_DPLL_EDT_T                  EDT_T;                  /**< \brief 480, DPLL Difference of Prediction to Actual Value of the Last TRIGGER Increment*/
       GTM_DPLL_MEDT_T                 MEDT_T;                 /**< \brief 484, DPLL Weighted Difference of Prediction Errors of TRIGGER*/
       GTM_DPLL_EDT_S                  EDT_S;                  /**< \brief 488, DPLL Difference of Prediction to Actual Value of the Last STATE Increment*/
       GTM_DPLL_MEDT_S                 MEDT_S;                 /**< \brief 48C, DPLL Weighted Difference of Prediction Errors of STATE*/
       GTM_DPLL_CDT_TX                 CDT_TX;                 /**< \brief 490, DPLL Prediction of the Actual TRIGGER Increment Duration*/
       GTM_DPLL_CDT_SX                 CDT_SX;                 /**< \brief 494, DPLL Prediction of the Actual STATE Increment Duration*/
       GTM_DPLL_CDT_TX_NOM             CDT_TX_NOM;             /**< \brief 498, DPLL Prediction of the Nominal TRIGGER Increment Duration*/
       GTM_DPLL_CDT_SX_NOM             CDT_SX_NOM;             /**< \brief 49C, DPLL Prediction of the Nominal STATE Increment Duration*/
       GTM_DPLL_TLR                    TLR;                    /**< \brief 4A0, DPLL TRIGGER Locking Range*/
       GTM_DPLL_SLR                    SLR;                    /**< \brief 4A4, DPLL STATE Locking Range*/
       vuint8_t                   reserved_4A8[88];       /**< \brief 4A8, \internal Reserved */
       GTM_DPLL_PDT                    PDT[32];                /**< \brief 500, DPLL Projected Increment Sum Relations for Action ${z}*/
       vuint8_t                   reserved_580[64];       /**< \brief 580, \internal Reserved */
       GTM_DPLL_MLS1                   MLS1;                   /**< \brief 5C0, DPLL Calculated Number of Sub-Pulses between two Nominal STATE Events for SMC = 0*/
       GTM_DPLL_MLS2                   MLS2;                   /**< \brief 5C4, DPLL Calculated Number of Sub-Pulses between two Nominal STATE Events for SMC = 1 and RMO = 1*/
       GTM_DPLL_CNT_NUM_1              CNT_NUM_1;              /**< \brief 5C8, DPLL Number of Sub-Pulses of SUB_INC1 in Continuous Mode*/
       GTM_DPLL_CNT_NUM_2              CNT_NUM_2;              /**< \brief 5CC, DPLL Number of Sub-Pulses of SUB_INC2 in Continuous Mode*/
       GTM_DPLL_PVT                    PVT;                    /**< \brief 5D0, DPLL Plausibility Value of Next TRIGGER Slope*/
       vuint8_t                   reserved_5D4[12];       /**< \brief 5D4, \internal Reserved */
       GTM_DPLL_PSTC                   PSTC;                   /**< \brief 5E0, DPLL Actual Calculated Position Stamp of TRIGGER*/
       GTM_DPLL_PSSC                   PSSC;                   /**< \brief 5E4, DPLL Actual Calculated Position Stamp of STATE*/
       GTM_DPLL_PSTM                   PSTM;                   /**< \brief 5E8, DPLL Measured Position Stamp at Last TRIGGER Input*/
       GTM_DPLL_PSTM_OLD               PSTM_OLD;               /**< \brief 5EC, DPLL Measured Position Stamp at Last but One TRIGGER Input*/
       GTM_DPLL_PSSM                   PSSM;                   /**< \brief 5F0, DPLL Measured Position Stamp at Last STATE Input*/
       GTM_DPLL_PSSM_OLD               PSSM_OLD;               /**< \brief 5F4, DPLL Measured Position Stamp at Last but One STATE Input*/
       GTM_DPLL_NMB_T                  NMB_T;                  /**< \brief 5F8, DPLL Number of Pulses to be Sent in Normal Mode*/
       GTM_DPLL_NMB_S                  NMB_S;                  /**< \brief 5FC, DPLL Number of Pulses to be Sent in Emergency Mode*/
       GTM_DPLL_RDT_S                  RDT_S[64];              /**< \brief 600, DPLL Reciprocal Values of the Nominal STATE ${i} Increment Duration in FULL_SCALE*/
       GTM_DPLL_TSF_S                  TSF_S[64];              /**< \brief 700, DPLL Time Stamp Values of the Nominal STATE ${i} Events in FULL_SCALE*/
       GTM_DPLL_ADT_S                  ADT_S[64];              /**< \brief 800, DPLL Adapt and Profile Values of the STATE ${i} Increments in FULL_SCALE*/
       GTM_DPLL_DT_S                   DT_S[64];               /**< \brief 900, DPLL Nominal STATE ${i} Increment Duration in FULL_SCALE*/
       vuint8_t                   reserved_A00[1024];     /**< \brief A00, \internal Reserved */
       GTM_DPLL_TSAC                   TSAC[32];               /**< \brief E00, DPLL Calculated Time Value to start Action ${z} Register*/
       GTM_DPLL_PSAC                   PSAC[32];               /**< \brief E80, DPLL ACTION Position/Value Action ${z} Request Register*/
       GTM_DPLL_ACB                    ACB[8];                 /**< \brief F00, DPLL Control Bits Register ${z} for up to 32 Actions*/
       GTM_DPLL_CTRL_11                CTRL_11;                /**< \brief F20, DPLL Control Register 11*/
       GTM_DPLL_THVAL2                 THVAL2;                 /**< \brief F24, DPLL Immediate THVAL Value Register*/
       GTM_DPLL_TIDEL                  TIDEL;                  /**< \brief F28, DPLL Additional TRIGGER Input Delay Register*/
       GTM_DPLL_SIDEL                  SIDEL;                  /**< \brief F2C, DPLL Additional STATE Input Delay Register*/
       GTM_DPLL_APS_SYNC_EXT           APS_SYNC_EXT;           /**< \brief F30, DPLL Extension Register for DPLL_APS_SYNC*/
       GTM_DPLL_CTRL_EXT               CTRL_EXT;               /**< \brief F34, DPLL Extension Register for DPLL_CTRL*/
       GTM_DPLL_APS_EXT                APS_EXT;                /**< \brief F38, DPLL Extension Register for DPLL_APS*/
       GTM_DPLL_APS_1C3_EXT            APS_1C3_EXT;            /**< \brief F3C, DPLL Extension Register for DPLL_APS_1C3*/
       GTM_DPLL_STA                    STA;                    /**< \brief F40, DPLL Status of the State Machine States Register*/
       GTM_DPLL_INCF1_OFFSET           INCF1_OFFSET;           /**< \brief F44, DPLL Start Value of the ADD_IN_ADDER1 Register*/
       GTM_DPLL_INCF2_OFFSET           INCF2_OFFSET;           /**< \brief F48, DPLL Start Value of the ADD_IN_ADDER2 Register*/
       GTM_DPLL_DT_T_START             DT_T_START;             /**< \brief F4C, DPLL Start Value of DPLL_DT_T_ACT for the First Increment after SIP1 is Set to 1*/
       GTM_DPLL_DT_S_START             DT_S_START;             /**< \brief F50, DPLL Start Value of DPLL_DT_S_ACT for the First Increment after SIP2 is Set to 1*/
       GTM_DPLL_STA_MASK               STA_MASK;               /**< \brief F54, DPLL Trigger Masks for Signals DPLL_STA_T and DPLL_STA_S*/
       GTM_DPLL_STA_FLAG               STA_FLAG;               /**< \brief F58, DPLL STA Flag Register*/
       GTM_DPLL_INC_CNT1_MASK          INC_CNT1_MASK;          /**< \brief F5C, DPLL INC_CNT1 Trigger Mask*/
       GTM_DPLL_INC_CNT2_MASK          INC_CNT2_MASK;          /**< \brief F60, DPLL INC_CNT2 Trigger Mask*/
       GTM_DPLL_NUSC_EXT1              NUSC_EXT1;              /**< \brief F64, DPLL Extension Register Number 1 for DPLL_NUSC 4*/
       GTM_DPLL_NUSC_EXT2              NUSC_EXT2;              /**< \brief F68, DPLL Extension Register Number 2 for DPLL_NUSC 4*/
       GTM_DPLL_CTN_MIN                CTN_MIN;                /**< \brief F6C, DPLL Minimum CDT_T Nominal Value Register*/
       GTM_DPLL_CTN_MAX                CTN_MAX;                /**< \brief F70, DPLL Maximum CDT_T Nominal Value Register*/
       GTM_DPLL_CSN_MIN                CSN_MIN;                /**< \brief F74, DPLL Minimum CDT_S Nominal Value Register*/
       GTM_DPLL_CSN_MAX                CSN_MAX;                /**< \brief F78, DPLL Maximum CDT_S Nominal Value Register*/

       GTM_DPLL_SW_TRIG                SW_TRIG;                /**< \brief F7C, Software triggered input events*/
       GTM_DPLL_MP_T                   MP_T;                   /**< \brief F80, Missing pulses of TRIGGER*/
       GTM_DPLL_MP_S                   MP_S;                   /**< \brief F84, Missing pulses of STATE*/
       GTM_DPLL_CTRL_12                CTRL_12;                /**< \brief F88, DPLL control register 12*/
       vuint8_t                   reserved_F8C[12404];    /**< \brief F8C, \internal Reserved */
       vuint32_t                    RR2[4096];              /**< \brief 4000, RAM based TRIGGER data*/
} GTM_DPLL;

/* ============================================================================
   =============================== Module: GTM_MCS_RAM ================================
   ============================================================================ */

typedef volatile struct _GTM_MCS_RAM {
       vuint32_t                             MEM[4096];              /**< \brief 0, Mapped section of embedded RAM 0*/
       vuint32_t                             MEM1[2048];             /**< \brief 4000, Mapped section of embedded RAM 1*/
} GTM_MCS_RAM;

/* ============================================================================
   =============================== Module: GTM_CLS ================================
   ============================================================================ */

typedef volatile struct _GTM_CLS {
       GTM_ARCH                        ARCH;                   /**< \brief 0, */
       vuint8_t                        reserved_34[12];        /**< \brief 34, \internal Reserved */
       GTM_AEI                         AEI;                    /**< \brief 40, GTM AEI Configuration Registers*/
       vuint8_t                        reserved_50[48];        /**< \brief 50, \internal Reserved */
       GTM_CMU                         CMU;                    /**< \brief 80, */
       GTM_GTMINT                      GTMINT;                 /**< \brief D0, */
       vuint8_t                        reserved_F0[0x10];      /**< \brief F0, \internal Reserved */
       GTM_TBU                         TBU;                    /**< \brief 100, */
       GTM_ARU                         ARU;                    /**< \brief 180, */
       GTM_BRC                         BRC;                    /**< \brief 200, */
       GTM_ICM                         ICM;                    /**< \brief 400, */
       vuint8_t                        reserved_5B8[136];      /**< \brief 5B8, \internal Reserved */
       GTM_MAP_CTRL                    MAP_CTRL;               /**< \brief 640, MAP Control Register*/
       vuint8_t                        reserved_644[0x3C];     /**< \brief 644, \internal Reserved */
       GTM_MON                         MON;                    /**< \brief 680, */
       vuint8_t                        reserved_6B4[0xC];      /**< \brief 6B4, \internal Reserved */
       GTM_CMP                         CMP;                    /**< \brief 6C0, */
       vuint8_t                        reserved_6D8[0x128];    /**< \brief 6D8, \internal Reserved */
       GTM_TIM                         TIM;                    /**< \brief 800, */
       GTM_TOM                         TOM;                    /**< \brief 1000, */
       GTM_ATOM                        ATOM;                   /**< \brief 1800, */
       GTM_MCS                         MCS;                    /**< \brief 2000, */
       GTM_TIO                         TIO;                    /**< \brief 3000, */
       GTM_CCM                         CCM;                    /**< \brief 4000, */
       GTM_CDTM                        CDTM;                   /**< \brief 4400, */
       GTM_PSM                         PSM;                    /**< \brief 4800, */
       GTM_SPE                         SPE;                    /**< \brief 4C00, */
       vuint8_t                        reserved_4C80[0x380];   /**< \brief 4C80, \internal Reserved */
       GTM_AXIM                        AXIM;                   /**< \brief 5000, */
       vuint8_t                        reserved_5220[0xDE0];   /**< \brief 5220, \internal Reserved */
       vuint32_t                       FIF0_MEMORY[0x400];     /**< \brief 6000, */
#ifdef CCFC3008PCSN
	   GTM_TIMINSEL                    TIMINSEL[2];            /**< \brief 7000, TIM${n} Input Select Register*/
	   GTM_TOUTSEL                     TOUTSEL[17];            /**< \brief 7008, Timer Output Select Register*/
	   GTM_ADCTRIG                     ADCTRIG[5];             /**< \brief 704C, ADC Trigger ${i} Output Select 1 Register*/
	   GTM_DTMAUXINSEL                 DTMAUXINSEL;            /**< \brief 7074, DTM_AUX Input Selection Register*/

	   unsigned char                   reserved_7078[0x6C];    /**< \brief 7078, \internal Reserved */
	   unsigned char                   reserved_70E4[0x1C];    /**< \brief 70E4, \internal Reserved */
       GTM_TOUTSEL                     Reserved_TOUTSEL[34];   /**< \brief 7100, Timer Output Select Register*/
#else
       GTM_TIMINSEL                    TIMINSEL[8];            /**< \brief 7000, TIM${n} Input Select Register*/
       GTM_DTMAUXINSEL                 DTMAUXINSEL;            /**< \brief 7020, DTM_AUX Input Selection Register*/
       GTM_MSC                         MSC;                    /**< \brief 7024, */
       vuint8_t                        reserved_70E4[0x1C];    /**< \brief 70E4, \internal Reserved */
       GTM_TOUTSEL                     TOUTSEL[34];            /**< \brief 7100, Timer Output Select Register*/
#endif /* CCFC3008PCSN */
       GTM_DSADCINSEL                  DSADCINSEL[6];          /**< \brief 7188, DSADC Input Select i Register*/
       GTM_DSADC                       DSADC[4];               /**< \brief 71A0, */
       vuint8_t                        reserved_71C0[0x40];    /**< \brief 71C0, \internal Reserved */
#ifdef CCFC3008PCSN
       GTM_ADCTRIG                     Reserved_ADCTRIG[5];    /**< \brief 7200, ADC Trigger ${i} Output Select 1 Register*/
#else
       GTM_ADCTRIG                     ADCTRIG[5];             /**< \brief 7200, ADC Trigger ${i} Output Select 1 Register*/
#endif
       GTM_CANOUTSEL0                  Reserved_CANOUTSEL0;    /**< \brief 7228, CAN0/CAN1 Output Select Register*/ //Reserved
       GTM_CANOUTSEL1                  Reserved_CANOUTSEL1;    /**< \brief 722C, CAN2 Output Select Register*/  //Reserved
       GTM_PSI5OUTSEL                  PSI5OUTSEL;             /**< \brief 7230, PSI5 Output Select Register*/
       GTM_PSI5SOUTSEL                 PSI5SOUTSEL;            /**< \brief 7234, PSI5-S Output Select Register*/
       GTM_LCDCDCOUTSEL                Reserved_LCDCDCOUTSEL;           /**< \brief 7238, LCDCDC Output Select Register*/

       vuint8_t                        reserved_723C[0xC4];    /**< \brief 723C, \internal Reserved */
       GTM_MCSDPLLMEMSEL               MCSDPLLMEMSEL;          /**< \brief 7300, MCS&&DPLL MEM SEL Register*/
       GTM_MCSDPLLCTLSTS               MCSDPLLCTLSTS;          /**< \brief 7304, MCS&&DPLL MEM CONTRLO AND STATUS Register*/
       vuint8_t                        reserved_7308[0x8];     /**< \brief 7308, Reserved Register*/
       GTM_GLSDLLCTRL                  GLSDLLCTRL[2];          /**< \brief 7310, Reserved Register*/
       vuint8_t                        reserved_7318[0x28];    /**< \brief 7318, Reserved Register*/

       GTM_DXOUTCON                    DXOUTCON;               /**< \brief 7340, Data Exchange Output Control Register*/
       GTM_TRIGOUT                     TRIGOUT[10];            /**< \brief 7344, Trigger Output Register ${n}*/
       GTM_MCSTRIGOUTSEL               MCSTRIGOUTSEL;          /**< \brief 736C, Trigger Output Select Register*/
       GTM_MCSINTSTAT                  Reserved_MCSINTSTAT;    /**< \brief 7370, MCS Interrupt Status Register*/
       GTM_MCSINTCLR                   Reserved_MCSINTCLR;     /**< \brief 7374, MCS Interrupt Clear Register*/
       GTM_INTOUT                      Reserved_INTOUT[10];    /**< \brief 7378, Interrupt Output Register ${n}*/
       GTM_DXINCON                     DXINCON;                /**< \brief 73A0, Data Exchange Input Control Register*/
       GTM_DATAIN                      DATAIN[10];             /**< \brief 73A4, Data Input ${n} Register*/
       vuint8_t                        reserved_73CC[0xC34];   /**< \brief 73CC, \internal Reserved */

       GTM_DPLL                        DPLL;                   /**< \brief 8000, */
       GTM_MCS_RAM                     MCS_MEM;                /**< \brief 10000, */
       vuint8_t                        reserved_16000[0xA000]; /**< \brief 16000, \internal Reserved */
} GTM_CLS;

struct GTM4_tag {     /**< \brief 0, */
     GTM_CLS    GLS[12];
};

#endif /* COMMON_INC_GTM4_REG_H_ */
