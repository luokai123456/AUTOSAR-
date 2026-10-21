#ifndef PSI5_REG_H_
#define PSI5_REG_H_
/* ============================================================================
   =============================== Module: PSI5 ===============================
   ============================================================================ */

typedef union PSI5_GCR_union_tag {     /* Global Control Register */
  vuint16_t R;
  struct {
    vuint16_t  :14;
    vuint16_t CTC_GED:1;
    vuint16_t GLOBAL_DISABLE_REQ:1;
  } B;
} PSI5_GCR_tag;

typedef union PSI5_CH0_PCCR_union_tag { /* PSI5 Channel Control Register */
  vuint32_t R;
  struct {
    vuint32_t CTC_GED_SEL:1;
    vuint32_t CTC_ED:1;
    vuint32_t  :1;
    vuint32_t MEM_DEPTH:5;
    vuint32_t  :3;
    vuint32_t ERROR_SELECT4:1;
    vuint32_t ERROR_SELECT3:1;
    vuint32_t ERROR_SELECT2:1;
    vuint32_t ERROR_SELECT1:1;
    vuint32_t ERROR_SELECT0:1;
    vuint32_t  :1;
    vuint32_t GTM_RESET_ASYNC_EN:1;
    vuint32_t  :3;
    vuint32_t DEBUG_EN:1;
    vuint32_t DEBUG_FREEZE_CTRL:1;
    vuint32_t SP_TS_CLK_SEL:1;
    vuint32_t  :2;
    vuint32_t FAST_CLR_SMC:1;
    vuint32_t FAST_CLR_PSI5:1;
    vuint32_t BIT_RATE:1;              /* Bit Rate */
    vuint32_t MODE:1;
    vuint32_t PSI5_CH_CONFIG:1;
    vuint32_t PSI5_CH_EN:1;
  } B;
} PSI5_CH0_PCCR_tag;

typedef union PSI5_CH0_DCR_union_tag { /* DMA Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t  :2;
    vuint32_t DMA_PM_DS_WM:5;
    vuint32_t  :5;
    vuint32_t IE_DMA_TF_SF:1;
    vuint32_t IE_DMA_TF_PM_DS:1;
    vuint32_t  :5;
    vuint32_t IE_DMA_PM_DS_FIFO_FULL:1;
    vuint32_t IE_DMA_SFUF:1;
    vuint32_t  :1;
    vuint32_t IE_DMA_PM_DS_UF:1;
    vuint32_t  :5;
    vuint32_t DMA_EN_SF:1;
    vuint32_t DMA_PM_DS_CONFIG:2;
  } B;
} PSI5_CH0_DCR_tag;

typedef union PSI5_CH0_DSR_union_tag { /* DMA Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t IS_DMA_TF_SF:1;
    vuint32_t IS_DMA_TF_PM_DS:1;
    vuint32_t  :5;
    vuint32_t IS_DMA_PM_DS_FIFO_FULL:1;
    vuint32_t IS_DMA_SFUF:1;
    vuint32_t  :1;
    vuint32_t IS_DMA_PM_DS_UF:1;
    vuint32_t  :8;
  } B;
} PSI5_CH0_DSR_tag;

typedef union PSI5_CH0_GICR_union_tag { /* General Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t IE_CESM:6;
    vuint32_t IE_STS:1;
    vuint32_t IE_DTS:1;
    vuint32_t IE_DSROW:1;
    vuint32_t IE_BROW:1;
    vuint32_t IE_PROW:1;
    vuint32_t IE_DSRR:1;
    vuint32_t IE_BRR:1;
    vuint32_t IE_PRR:1;
    vuint32_t  :2;
    vuint32_t IE_OWSM:6;
    vuint32_t  :2;
    vuint32_t IE_NVSM:6;
  } B;
} PSI5_CH0_GICR_tag;

typedef union PSI5_CH0_NDICR_union_tag { /* New Data Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_ND:32;
  } B;
} PSI5_CH0_NDICR_tag;

typedef union PSI5_CH0_OWICR_union_tag { /* Overwrite Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_OW:32;
  } B;
} PSI5_CH0_OWICR_tag;

typedef union PSI5_CH0_EICR_union_tag { /* Error Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_ERROR:32;
  } B;
} PSI5_CH0_EICR_tag;

typedef union PSI5_CH0_GISR_union_tag { /* General Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t IS_DB_FR:1;
    vuint32_t  :1;
    vuint32_t IS_CESM:6;
    vuint32_t IS_STS:1;
    vuint32_t IS_DTS:1;
    vuint32_t IS_DSROW:1;
    vuint32_t IS_BROW:1;
    vuint32_t IS_PROW:1;
    vuint32_t DSR_RDY:1;
    vuint32_t DBR_RDY:1;
    vuint32_t DPR_RDY:1;
    vuint32_t  :2;
    vuint32_t IS_OWSM:6;
    vuint32_t  :2;
    vuint32_t IS_NVSM:6;
  } B;
} PSI5_CH0_GISR_tag;

typedef union PSI5_CH0_DPMR_union_tag { /* DMA PSI5 Message Register */
  vuint32_t R;
  struct {
    vuint32_t PSI5_RXDATA:32;
  } B;
} PSI5_CH0_DPMR_tag;

typedef union PSI5_CH0_DSFR_union_tag { /* DMA SMC Frame Register */
  vuint32_t R;
  struct {
    vuint32_t SMC_RXDATA:32;
  } B;
} PSI5_CH0_DSFR_tag;

typedef union PSI5_CH0_DDSR_union_tag { /* DMA Diagnostic Status Register */
  vuint32_t R;
  struct {
    vuint32_t DDS:32;
  } B;
} PSI5_CH0_DDSR_tag;

typedef union PSI5_CH0_PMRRL_union_tag { /* PSI5 Message Receive Register Low */
  vuint32_t R;
  struct {
    vuint32_t DATA_REGION:28;
    vuint32_t CRC:3;
    vuint32_t C:1;
  } B;
} PSI5_CH0_PMRRL_tag;

typedef union PSI5_CH0_PMRRH_union_tag { /* PSI5 Message Receive Register High */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t F:1;
    vuint32_t EM:1;
    vuint32_t E:1;
    vuint32_t T:1;
    vuint32_t SlotCounter:3;
    vuint32_t TimeStampValue:24;
  } B;
} PSI5_CH0_PMRRH_tag;

typedef union PSI5_CH0_PMRL_union_tag { /* PSI5 Message Register Low i */
  vuint32_t R;
  struct {
    vuint32_t DATA_REGION:28;
    vuint32_t CRCP:3;
    vuint32_t C:1;
  } B;
} PSI5_CH0_PMRL_tag;

typedef union PSI5_CH0_PMRH_union_tag { /* PSI5 Message Register High i */
  vuint32_t R;
  struct {
    vuint32_t O:1;
    vuint32_t F:1;
    vuint32_t EM:1;
    vuint32_t E:1;
    vuint32_t T:1;
    vuint32_t Slot_Counter:3;
    vuint32_t TimeStampValue:24;
  } B;
} PSI5_CH0_PMRH_tag;

typedef struct PSI5_CH0_struct_tag {
  PSI5_CH0_PMRL_tag PMRL;              /* PSI5 Message Register Low i */
  PSI5_CH0_PMRH_tag PMRH;              /* PSI5 Message Register High i */
} PSI5_CH0_tag;

typedef union PSI5_CH0_SFR_union_tag { /* SMC Frame Register n */
  vuint32_t R;
  struct {
    vuint32_t SLOT_NO:3;
    vuint32_t CER:1;
    vuint32_t OW:1;
    vuint32_t CRC:6;
    vuint32_t C:1;
    vuint32_t ID:4;
    vuint32_t IDDATA:4;
    vuint32_t DATA:12;
  } B;
} PSI5_CH0_SFR_tag;

typedef union PSI5_CH0_NDSR_union_tag { /* New Data Status Register */
  vuint32_t R;
  struct {
    vuint32_t NDS:32;
  } B;
} PSI5_CH0_NDSR_tag;

typedef union PSI5_CH0_OWSR_union_tag { /* Overwrite Status Register */
  vuint32_t R;
  struct {
    vuint32_t OWS:32;
  } B;
} PSI5_CH0_OWSR_tag;

typedef union PSI5_CH0_EISR_union_tag { /* Error Indication Status Register */
  vuint32_t R;
  struct {
    vuint32_t ERROR:32;
  } B;
} PSI5_CH0_EISR_tag;

typedef union PSI5_CH0_SNDSR_union_tag { /* Set New Data Status Register */
  vuint32_t R;
  struct {
    vuint32_t SNDS:32;
  } B;
} PSI5_CH0_SNDSR_tag;

typedef union PSI5_CH0_SOWSR_union_tag { /* Set Overwrite Status Register */
  vuint32_t R;
  struct {
    vuint32_t SOWS:32;
  } B;
} PSI5_CH0_SOWSR_tag;

typedef union PSI5_CH0_SEISR_union_tag { /* Set Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t SERROR:32;
  } B;
} PSI5_CH0_SEISR_tag;

typedef union PSI5_CH0_SSESR_union_tag { /* Set SMC Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t SCESM:6;
    vuint32_t  :10;
    vuint32_t SOWSM:6;
    vuint32_t  :2;
    vuint32_t SNVSM:6;
  } B;
} PSI5_CH0_SSESR_tag;

typedef union PSI5_CH0_STSRR_union_tag { /* Sync Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t STSV:24;
  } B;
} PSI5_CH0_STSRR_tag;

typedef union PSI5_CH0_DTSRR_union_tag { /* Data Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t SLOT_COUNTER:3;
    vuint32_t DTSV:24;
  } B;
} PSI5_CH0_DTSRR_tag;

typedef union PSI5_CH0_SFCR_union_tag { /* Slot n Frame Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t SLOT_EN:1;
    vuint32_t TS_CAPT:1;
    vuint32_t  :1;
    vuint32_t SMCL:1;
    vuint32_t  :9;
    vuint32_t DRL:5;
    vuint32_t CRCP:1;
  } B;
} PSI5_CH0_SFCR_tag;

typedef union PSI5_CH0_S1SBR_union_tag { /* Slot 1 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S1SBT:15;
  } B;
} PSI5_CH0_S1SBR_tag;

typedef union PSI5_CH0_S2SBR_union_tag { /* Slot 2 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S2SBT:15;
  } B;
} PSI5_CH0_S2SBR_tag;

typedef union PSI5_CH0_S3SBR_union_tag { /* Slot 3 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S3SBT:15;
  } B;
} PSI5_CH0_S3SBR_tag;

typedef union PSI5_CH0_S4SBR_union_tag { /* Slot 4 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S4SBT:15;
  } B;
} PSI5_CH0_S4SBR_tag;

typedef union PSI5_CH0_S5SBR_union_tag { /* Slot 5 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S5SBT:15;
  } B;
} PSI5_CH0_S5SBR_tag;

typedef union PSI5_CH0_S6SBR_union_tag { /* Slot 6 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S6SBT:15;
  } B;
} PSI5_CH0_S6SBR_tag;

typedef union PSI5_CH0_SnEBR_union_tag { /* Slot n End Boundary Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t SLOT_NO:3;
    vuint32_t  :1;
    vuint32_t SnEBT:15;
  } B;
} PSI5_CH0_SnEBR_tag;

typedef union PSI5_CH0_DOBCR_union_tag { /* Data Output Block Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t DATA_LENGTH:6;
    vuint16_t DBR_RST:1;
    vuint16_t DSR_RST:1;
    vuint16_t CMD_TYPE:3;
    vuint16_t DEFAULT_SYNC:1;
    vuint16_t GTM_TRIG_SEL:1;
    vuint16_t SP_PULSE_SEL:1;
    vuint16_t OP_SEL:1;
    vuint16_t SW_READY:1;
  } B;
} PSI5_CH0_DOBCR_tag;

typedef union PSI5_CH0_MDDIS_OFF_union_tag { /* Manchestor Decoder Disable Offset */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t MDDIS_OFF:7;
  } B;
} PSI5_CH0_MDDIS_OFF_tag;

typedef union PSI5_CH0_PW0D_union_tag { /* Pulse Width for Data Bit Value 0 */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t Pulse_Width0:7;
  } B;
} PSI5_CH0_PW0D_tag;

typedef union PSI5_CH0_PW1D_union_tag { /* Pulse Width for Data Bit Value 1 */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t Pulse_Width1:7;
  } B;
} PSI5_CH0_PW1D_tag;

typedef union PSI5_CH0_CTPR_union_tag { /* Counter Target Pulse Register */
  vuint16_t R;
  struct {
    vuint16_t CTPR:16;
  } B;
} PSI5_CH0_CTPR_tag;

typedef union PSI5_CH0_CIPR_union_tag { /* Counter Initialize Pulse Register */
  vuint16_t R;
  struct {
    vuint16_t CIPR:16;
  } B;
} PSI5_CH0_CIPR_tag;

typedef union PSI5_CH0_DPRL_union_tag { /* Data Preparation Register Low */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t DPR:24;
  } B;
} PSI5_CH0_DPRL_tag;

typedef union PSI5_CH0_DPRH_union_tag { /* Data Preparation Register High */
  vuint32_t R;
  struct {
    vuint32_t  :32;
  } B;
} PSI5_CH0_DPRH_tag;

typedef union PSI5_CH0_DBRL_union_tag { /* Data Buffer Register Low */
  vuint32_t R;
  struct {
    vuint32_t DBR:32;
  } B;
} PSI5_CH0_DBRL_tag;

typedef union PSI5_CH0_DBRH_union_tag { /* Data Buffer Register High */
  vuint32_t R;
  struct {
    vuint32_t DBR:32;
  } B;
} PSI5_CH0_DBRH_tag;

typedef union PSI5_CH0_DSRL_union_tag { /* Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DSR:32;
  } B;
} PSI5_CH0_DSRL_tag;

typedef union PSI5_CH0_DSRH_union_tag { /* Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t DSR:32;
  } B;
} PSI5_CH0_DSRH_tag;

typedef union PSI5_CH1_PCCR_union_tag { /* PSI5 Channel Control Register */
  vuint32_t R;
  struct {
    vuint32_t CTC_GED_SEL:1;
    vuint32_t CTC_ED:1;
    vuint32_t  :1;
    vuint32_t MEM_DEPTH:5;
    vuint32_t  :3;
    vuint32_t ERROR_SELECT4:1;
    vuint32_t ERROR_SELECT3:1;
    vuint32_t ERROR_SELECT2:1;
    vuint32_t ERROR_SELECT1:1;
    vuint32_t ERROR_SELECT0:1;
    vuint32_t  :1;
    vuint32_t GTM_RESET_ASYNC_EN:1;
    vuint32_t  :3;
    vuint32_t DEBUG_EN:1;
    vuint32_t DEBUG_FREEZE_CTRL:1;
    vuint32_t SP_TS_CLK_SEL:1;
    vuint32_t  :2;
    vuint32_t FAST_CLR_SMC:1;
    vuint32_t FAST_CLR_PSI5:1;
    vuint32_t BIT_RATE:1;
    vuint32_t MODE:1;
    vuint32_t PSI5_CH_CONFIG:1;
    vuint32_t PSI5_CH_EN:1;
  } B;
} PSI5_CH1_PCCR_tag;

typedef union PSI5_CH1_DCR_union_tag { /* DMA Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t DMA_PM_DS_WM:5;
    vuint32_t  :5;
    vuint32_t IE_DMA_TF_SF:1;
    vuint32_t IE_DMA_TF_PM_DS:1;
    vuint32_t  :5;
    vuint32_t IE_DMA_PM_DS_FIFO_FULL:1;
    vuint32_t IE_DMA_SFUF:1;
    vuint32_t  :1;
    vuint32_t IE_DMA_PM_DS_UF:1;
    vuint32_t  :5;
    vuint32_t DMA_EN_SF:1;
    vuint32_t DMA_PM_DS_CONFIG:2;
  } B;
} PSI5_CH1_DCR_tag;

typedef union PSI5_CH1_DSR_union_tag { /* DMA Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t IS_DMA_TF_SF:1;
    vuint32_t IS_DMA_TF_PM_DS:1;
    vuint32_t  :5;
    vuint32_t IS_DMA_PM_DS_FIFO_FULL:1;
    vuint32_t IS_DMA_SFUF:1;
    vuint32_t  :1;
    vuint32_t IS_DMA_PM_DS_UF:1;
    vuint32_t  :8;
  } B;
} PSI5_CH1_DSR_tag;

typedef union PSI5_CH1_GICR_union_tag { /* General Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t IE_CESM:6;
    vuint32_t IE_STS:1;
    vuint32_t IE_DTS:1;
    vuint32_t IE_DSROW:1;
    vuint32_t IE_BROW:1;
    vuint32_t IE_PROW:1;
    vuint32_t IE_DSRR:1;
    vuint32_t IE_BRR:1;
    vuint32_t IE_PRR:1;
    vuint32_t  :2;
    vuint32_t IE_OWSM:6;
    vuint32_t  :2;
    vuint32_t IE_NVSM:6;
  } B;
} PSI5_CH1_GICR_tag;

typedef union PSI5_CH1_NDICR_union_tag { /* New Data Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_ND:32;
  } B;
} PSI5_CH1_NDICR_tag;

typedef union PSI5_CH1_OWICR_union_tag { /* Overwrite Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_OW:32;
  } B;
} PSI5_CH1_OWICR_tag;

typedef union PSI5_CH1_EICR_union_tag { /* Error Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_ERROR:32;
  } B;
} PSI5_CH1_EICR_tag;

typedef union PSI5_CH1_GISR_union_tag { /* General Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t IS_DB_FR:1;
    vuint32_t  :1;
    vuint32_t IS_CESM:6;
    vuint32_t IS_STS:1;
    vuint32_t IS_DTS:1;
    vuint32_t IS_DSROW:1;
    vuint32_t IS_BROW:1;
    vuint32_t IS_PROW:1;
    vuint32_t DSR_RDY:1;
    vuint32_t DBR_RDY:1;
    vuint32_t DPR_RDY:1;
    vuint32_t  :2;
    vuint32_t IS_OWSM:6;
    vuint32_t  :2;
    vuint32_t IS_NVSM:6;
  } B;
} PSI5_CH1_GISR_tag;

typedef union PSI5_CH1_DPMR_union_tag { /* DMA PSI5 Message Register */
  vuint32_t R;
  struct {
    vuint32_t PSI5_RXDATA:32;
  } B;
} PSI5_CH1_DPMR_tag;

typedef union PSI5_CH1_DSFR_union_tag { /* DMA SMC Frame Register */
  vuint32_t R;
  struct {
    vuint32_t SMC_RXDATA:32;
  } B;
} PSI5_CH1_DSFR_tag;

typedef union PSI5_CH1_DDSR_union_tag { /* DMA Diagnostic Status Register */
  vuint32_t R;
  struct {
    vuint32_t DDS:32;
  } B;
} PSI5_CH1_DDSR_tag;

typedef union PSI5_CH1_PMRRL_union_tag { /* PSI5 Message Receive Register Low */
  vuint32_t R;
  struct {
    vuint32_t DATA_REGION:28;
    vuint32_t CRC:3;
    vuint32_t C:1;
  } B;
} PSI5_CH1_PMRRL_tag;

typedef union PSI5_CH1_PMRRH_union_tag { /* PSI5 Message Receive Register High */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t F:1;
    vuint32_t EM:1;
    vuint32_t E:1;
    vuint32_t T:1;
    vuint32_t SlotCounter:3;
    vuint32_t TimeStampValue:24;
  } B;
} PSI5_CH1_PMRRH_tag;

typedef union PSI5_CH1_PMRL_union_tag { /* PSI5 Message Register Low i */
  vuint32_t R;
  struct {
    vuint32_t DATA_REGION:28;
    vuint32_t CRCP:3;
    vuint32_t C:1;
  } B;
} PSI5_CH1_PMRL_tag;

typedef union PSI5_CH1_PMRH_union_tag { /* PSI5 Message Register High i */
  vuint32_t R;
  struct {
    vuint32_t O:1;
    vuint32_t F:1;
    vuint32_t EM:1;
    vuint32_t E:1;
    vuint32_t T:1;
    vuint32_t Slot_Counter:3;
    vuint32_t TimeStampValue:24;
  } B;
} PSI5_CH1_PMRH_tag;

typedef struct PSI5_CH1_struct_tag {
  PSI5_CH1_PMRL_tag PMRL;              /* PSI5 Message Register Low i */
  PSI5_CH1_PMRH_tag PMRH;              /* PSI5 Message Register High i */
} PSI5_CH1_tag;

typedef union PSI5_CH1_SFR_union_tag { /* SMC Frame Register n */
  vuint32_t R;
  struct {
    vuint32_t SLOT_NO:3;
    vuint32_t CER:1;
    vuint32_t OW:1;
    vuint32_t CRC:6;
    vuint32_t C:1;
    vuint32_t ID:4;
    vuint32_t IDDATA:4;
    vuint32_t DATA:12;
  } B;
} PSI5_CH1_SFR_tag;

typedef union PSI5_CH1_NDSR_union_tag { /* New Data Status Register */
  vuint32_t R;
  struct {
    vuint32_t NDS:32;
  } B;
} PSI5_CH1_NDSR_tag;

typedef union PSI5_CH1_OWSR_union_tag { /* Overwrite Status Register */
  vuint32_t R;
  struct {
    vuint32_t OWS:32;
  } B;
} PSI5_CH1_OWSR_tag;

typedef union PSI5_CH1_EISR_union_tag { /* Error Indication Status Register */
  vuint32_t R;
  struct {
    vuint32_t ERROR:32;
  } B;
} PSI5_CH1_EISR_tag;

typedef union PSI5_CH1_SNDSR_union_tag { /* Set New Data Status Register */
  vuint32_t R;
  struct {
    vuint32_t SNDS:32;
  } B;
} PSI5_CH1_SNDSR_tag;

typedef union PSI5_CH1_SOWSR_union_tag { /* Set Overwrite Status Register */
  vuint32_t R;
  struct {
    vuint32_t SOWS:32;
  } B;
} PSI5_CH1_SOWSR_tag;

typedef union PSI5_CH1_SEISR_union_tag { /* Set Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t SERROR:32;
  } B;
} PSI5_CH1_SEISR_tag;

typedef union PSI5_CH1_SSESR_union_tag { /* Set SMC Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t SCESM:6;
    vuint32_t  :10;
    vuint32_t SOWSM:6;
    vuint32_t  :2;
    vuint32_t SNVSM:6;
  } B;
} PSI5_CH1_SSESR_tag;

typedef union PSI5_CH1_STSRR_union_tag { /* Sync Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t STSV:24;
  } B;
} PSI5_CH1_STSRR_tag;

typedef union PSI5_CH1_DTSRR_union_tag { /* Data Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t SLOT_COUNTER:3;
    vuint32_t DTSV:24;
  } B;
} PSI5_CH1_DTSRR_tag;

typedef union PSI5_CH1_SFCR_union_tag { /* Slot n Frame Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t SLOT_EN:1;               /* SLOT_EN */
    vuint32_t TS_CAPT:1;               /* TS_CAPT */
    vuint32_t  :1;
    vuint32_t SMCL:1;
    vuint32_t  :9;
    vuint32_t DRL:5;
    vuint32_t CRCP:1;                  /* CRCP */
  } B;
} PSI5_CH1_SFCR_tag;

typedef union PSI5_CH1_S1SBR_union_tag { /* Slot 1 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S1SBT:15;
  } B;
} PSI5_CH1_S1SBR_tag;

typedef union PSI5_CH1_S2SBR_union_tag { /* Slot 2 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S2SBT:15;
  } B;
} PSI5_CH1_S2SBR_tag;

typedef union PSI5_CH1_S3SBR_union_tag { /* Slot 3 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S3SBT:15;
  } B;
} PSI5_CH1_S3SBR_tag;

typedef union PSI5_CH1_S4SBR_union_tag { /* Slot 4 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S4SBT:15;
  } B;
} PSI5_CH1_S4SBR_tag;

typedef union PSI5_CH1_S5SBR_union_tag { /* Slot 5 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S5SBT:15;
  } B;
} PSI5_CH1_S5SBR_tag;

typedef union PSI5_CH1_S6SBR_union_tag { /* Slot 6 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S6SBT:15;
  } B;
} PSI5_CH1_S6SBR_tag;

typedef union PSI5_CH1_SnEBR_union_tag { /* Slot n End Boundary Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t SLOT_NO:3;
    vuint32_t  :1;
    vuint32_t SnEBT:15;
  } B;
} PSI5_CH1_SnEBR_tag;

typedef union PSI5_CH1_DOBCR_union_tag { /* Data Output Block Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t DATA_LENGTH:6;
    vuint16_t DBR_RST:1;
    vuint16_t DSR_RST:1;
    vuint16_t CMD_TYPE:3;
    vuint16_t DEFAULT_SYNC:1;
    vuint16_t GTM_TRIG_SEL:1;
    vuint16_t SP_PULSE_SEL:1;
    vuint16_t OP_SEL:1;
    vuint16_t SW_READY:1;
  } B;
} PSI5_CH1_DOBCR_tag;

typedef union PSI5_CH1_MDDIS_OFF_union_tag { /* Manchestor Decoder Disable Offset */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t MDDIS_OFF:7;
  } B;
} PSI5_CH1_MDDIS_OFF_tag;

typedef union PSI5_CH1_PW0D_union_tag { /* Pulse Width for Data Bit Value 0 */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t Pulse_Width0:7;
  } B;
} PSI5_CH1_PW0D_tag;

typedef union PSI5_CH1_PW1D_union_tag { /* Pulse Width for Data Bit Value 1 */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t Pulse_Width1:7;
  } B;
} PSI5_CH1_PW1D_tag;

typedef union PSI5_CH1_CTPR_union_tag { /* Counter Target Pulse Register */
  vuint16_t R;
  struct {
    vuint16_t CTPR:16;
  } B;
} PSI5_CH1_CTPR_tag;

typedef union PSI5_CH1_CIPR_union_tag { /* Counter Initialize Pulse Register */
  vuint16_t R;
  struct {
    vuint16_t CIPR:16;
  } B;
} PSI5_CH1_CIPR_tag;

typedef union PSI5_CH1_DPRL_union_tag { /* Data Preparation Register Low */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t DPR:24;
  } B;
} PSI5_CH1_DPRL_tag;

typedef union PSI5_CH1_DPRH_union_tag { /* Data Preparation Register High */
  vuint32_t R;
  struct {
    vuint32_t  :32;
  } B;
} PSI5_CH1_DPRH_tag;

typedef union PSI5_CH1_DBRL_union_tag { /* Data Buffer Register Low */
  vuint32_t R;
  struct {
    vuint32_t DBR:32;
  } B;
} PSI5_CH1_DBRL_tag;

typedef union PSI5_CH1_DBRH_union_tag { /* Data Buffer Register High */
  vuint32_t R;
  struct {
    vuint32_t DBR:32;
  } B;
} PSI5_CH1_DBRH_tag;

typedef union PSI5_CH1_DSRL_union_tag { /* Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DSR:32;
  } B;
} PSI5_CH1_DSRL_tag;

typedef union PSI5_CH1_DSRH_union_tag { /* Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t DSR:32;
  } B;
} PSI5_CH1_DSRH_tag;

typedef union PSI5_CH2_PCCR_union_tag { /* PSI5 Channel Control Register */
  vuint32_t R;
  struct {
    vuint32_t CTC_GED_SEL:1;
    vuint32_t CTC_ED:1;
    vuint32_t  :1;
    vuint32_t MEM_DEPTH:5;
    vuint32_t  :3;
    vuint32_t ERROR_SELECT4:1;
    vuint32_t ERROR_SELECT3:1;
    vuint32_t ERROR_SELECT2:1;
    vuint32_t ERROR_SELECT1:1;
    vuint32_t ERROR_SELECT0:1;
    vuint32_t  :1;
    vuint32_t GTM_RESET_ASYNC_EN:1;
    vuint32_t  :3;
    vuint32_t DEBUG_EN:1;
    vuint32_t DEBUG_FREEZE_CTRL:1;
    vuint32_t SP_TS_CLK_SEL:1;
    vuint32_t  :2;
    vuint32_t FAST_CLR_SMC:1;
    vuint32_t FAST_CLR_PSI5:1;
    vuint32_t BIT_RATE:1;
    vuint32_t MODE:1;
    vuint32_t PSI5_CH_CONFIG:1;
    vuint32_t PSI5_CH_EN:1;
  } B;
} PSI5_CH2_PCCR_tag;

typedef union PSI5_CH2_DCR_union_tag { /* DMA Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t DMA_PM_DS_WM:5;
    vuint32_t  :5;
    vuint32_t IE_DMA_TF_SF:1;
    vuint32_t IE_DMA_TF_PM_DS:1;
    vuint32_t  :5;
    vuint32_t IE_DMA_PM_DS_FIFO_FULL:1;
    vuint32_t IE_DMA_SFUF:1;
    vuint32_t  :1;
    vuint32_t IE_DMA_PM_DS_UF:1;
    vuint32_t  :5;
    vuint32_t DMA_EN_SF:1;
    vuint32_t DMA_PM_DS_CONFIG:2;
  } B;
} PSI5_CH2_DCR_tag;

typedef union PSI5_CH2_DSR_union_tag { /* DMA Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t IS_DMA_TF_SF:1;
    vuint32_t IS_DMA_TF_PM_DS:1;
    vuint32_t  :5;
    vuint32_t IS_DMA_PM_DS_FIFO_FULL:1;
    vuint32_t IS_DMA_SFUF:1;
    vuint32_t  :1;
    vuint32_t IS_DMA_PM_DS_UF:1;
    vuint32_t  :8;
  } B;
} PSI5_CH2_DSR_tag;

typedef union PSI5_CH2_GICR_union_tag { /* General Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t IE_CESM:6;
    vuint32_t IE_STS:1;
    vuint32_t IE_DTS:1;
    vuint32_t IE_DSROW:1;
    vuint32_t IE_BROW:1;
    vuint32_t IE_PROW:1;
    vuint32_t IE_DSRR:1;
    vuint32_t IE_BRR:1;
    vuint32_t IE_PRR:1;
    vuint32_t  :2;
    vuint32_t IE_OWSM:6;
    vuint32_t  :2;
    vuint32_t IE_NVSM:6;
  } B;
} PSI5_CH2_GICR_tag;

typedef union PSI5_CH2_NDICR_union_tag { /* New Data Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_ND:32;
  } B;
} PSI5_CH2_NDICR_tag;

typedef union PSI5_CH2_OWICR_union_tag { /* Overwrite Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_OW:32;
  } B;
} PSI5_CH2_OWICR_tag;

typedef union PSI5_CH2_EICR_union_tag { /* Error Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_ERROR:32;
  } B;
} PSI5_CH2_EICR_tag;

typedef union PSI5_CH2_GISR_union_tag { /* General Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t IS_DB_FR:1;
    vuint32_t  :1;
    vuint32_t IS_CESM:6;
    vuint32_t IS_STS:1;
    vuint32_t IS_DTS:1;
    vuint32_t IS_DSROW:1;
    vuint32_t IS_BROW:1;
    vuint32_t IS_PROW:1;
    vuint32_t DSR_RDY:1;
    vuint32_t DBR_RDY:1;
    vuint32_t DPR_RDY:1;
    vuint32_t  :2;
    vuint32_t IS_OWSM:6;
    vuint32_t  :2;
    vuint32_t IS_NVSM:6;
  } B;
} PSI5_CH2_GISR_tag;

typedef union PSI5_CH2_DPMR_union_tag { /* DMA PSI5 Message Register */
  vuint32_t R;
  struct {
    vuint32_t PSI5_RXDATA:32;
  } B;
} PSI5_CH2_DPMR_tag;

typedef union PSI5_CH2_DSFR_union_tag { /* DMA SMC Frame Register */
  vuint32_t R;
  struct {
    vuint32_t SMC_RXDATA:32;
  } B;
} PSI5_CH2_DSFR_tag;

typedef union PSI5_CH2_DDSR_union_tag { /* DMA Diagnostic Status Register */
  vuint32_t R;
  struct {
    vuint32_t DDS:32;
  } B;
} PSI5_CH2_DDSR_tag;

typedef union PSI5_CH2_PMRRL_union_tag { /* PSI5 Message Receive Register Low */
  vuint32_t R;
  struct {
    vuint32_t DATA_REGION:28;
    vuint32_t CRC:3;
    vuint32_t C:1;
  } B;
} PSI5_CH2_PMRRL_tag;

typedef union PSI5_CH2_PMRRH_union_tag { /* PSI5 Message Receive Register High */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t F:1;
    vuint32_t EM:1;
    vuint32_t E:1;
    vuint32_t T:1;
    vuint32_t SlotCounter:3;
    vuint32_t TimeStampValue:24;
  } B;
} PSI5_CH2_PMRRH_tag;

typedef union PSI5_CH2_PMRL_union_tag { /* PSI5 Message Register Low i */
  vuint32_t R;
  struct {
    vuint32_t DATA_REGION:28;
    vuint32_t CRCP:3;
    vuint32_t C:1;
  } B;
} PSI5_CH2_PMRL_tag;

typedef union PSI5_CH2_PMRH_union_tag { /* PSI5 Message Register High i */
  vuint32_t R;
  struct {
    vuint32_t O:1;
    vuint32_t F:1;
    vuint32_t EM:1;
    vuint32_t E:1;
    vuint32_t T:1;
    vuint32_t Slot_Counter:3;
    vuint32_t TimeStampValue:24;
  } B;
} PSI5_CH2_PMRH_tag;

typedef struct PSI5_CH2_struct_tag {
  PSI5_CH2_PMRL_tag PMRL;              /* PSI5 Message Register Low i */
  PSI5_CH2_PMRH_tag PMRH;              /* PSI5 Message Register High i */
} PSI5_CH2_tag;

typedef union PSI5_CH2_SFR_union_tag { /* SMC Frame Register n */
  vuint32_t R;
  struct {
    vuint32_t SLOT_NO:3;
    vuint32_t CER:1;
    vuint32_t OW:1;
    vuint32_t CRC:6;
    vuint32_t C:1;
    vuint32_t ID:4;
    vuint32_t IDDATA:4;
    vuint32_t DATA:12;
  } B;
} PSI5_CH2_SFR_tag;

typedef union PSI5_CH2_NDSR_union_tag { /* New Data Status Register */
  vuint32_t R;
  struct {
    vuint32_t NDS:32;
  } B;
} PSI5_CH2_NDSR_tag;

typedef union PSI5_CH2_OWSR_union_tag { /* Overwrite Status Register */
  vuint32_t R;
  struct {
    vuint32_t OWS:32;
  } B;
} PSI5_CH2_OWSR_tag;

typedef union PSI5_CH2_EISR_union_tag { /* Error Indication Status Register */
  vuint32_t R;
  struct {
    vuint32_t ERROR:32;
  } B;
} PSI5_CH2_EISR_tag;

typedef union PSI5_CH2_SNDSR_union_tag { /* Set New Data Status Register */
  vuint32_t R;
  struct {
    vuint32_t SNDS:32;
  } B;
} PSI5_CH2_SNDSR_tag;

typedef union PSI5_CH2_SOWSR_union_tag { /* Set Overwrite Status Register */
  vuint32_t R;
  struct {
    vuint32_t SOWS:32;
  } B;
} PSI5_CH2_SOWSR_tag;

typedef union PSI5_CH2_SEISR_union_tag { /* Set Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t SERROR:32;
  } B;
} PSI5_CH2_SEISR_tag;

typedef union PSI5_CH2_SSESR_union_tag { /* Set SMC Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t SCESM:6;
    vuint32_t  :10;
    vuint32_t SOWSM:6;
    vuint32_t  :2;
    vuint32_t SNVSM:6;
  } B;
} PSI5_CH2_SSESR_tag;

typedef union PSI5_CH2_STSRR_union_tag { /* Sync Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t STSV:24;
  } B;
} PSI5_CH2_STSRR_tag;

typedef union PSI5_CH2_DTSRR_union_tag { /* Data Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t SLOT_COUNTER:3;
    vuint32_t DTSV:24;
  } B;
} PSI5_CH2_DTSRR_tag;

typedef union PSI5_CH2_SFCR_union_tag { /* Slot n Frame Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t SLOT_EN:1;
    vuint32_t TS_CAPT:1;
    vuint32_t  :1;
    vuint32_t SMCL:1;
    vuint32_t  :9;
    vuint32_t DRL:5;
    vuint32_t CRCP:1;
  } B;
} PSI5_CH2_SFCR_tag;

typedef union PSI5_CH2_S1SBR_union_tag { /* Slot 1 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S1SBT:15;
  } B;
} PSI5_CH2_S1SBR_tag;

typedef union PSI5_CH2_S2SBR_union_tag { /* Slot 2 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S2SBT:15;
  } B;
} PSI5_CH2_S2SBR_tag;

typedef union PSI5_CH2_S3SBR_union_tag { /* Slot 3 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S3SBT:15;
  } B;
} PSI5_CH2_S3SBR_tag;

typedef union PSI5_CH2_S4SBR_union_tag { /* Slot 4 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S4SBT:15;
  } B;
} PSI5_CH2_S4SBR_tag;

typedef union PSI5_CH2_S5SBR_union_tag { /* Slot 5 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S5SBT:15;
  } B;
} PSI5_CH2_S5SBR_tag;

typedef union PSI5_CH2_S6SBR_union_tag { /* Slot 6 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S6SBT:15;
  } B;
} PSI5_CH2_S6SBR_tag;

typedef union PSI5_CH2_SnEBR_union_tag { /* Slot n End Boundary Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t SLOT_NO:3;
    vuint32_t  :1;
    vuint32_t SnEBT:15;
  } B;
} PSI5_CH2_SnEBR_tag;

typedef union PSI5_CH2_DOBCR_union_tag { /* Data Output Block Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t DATA_LENGTH:6;
    vuint16_t DBR_RST:1;
    vuint16_t DSR_RST:1;
    vuint16_t CMD_TYPE:3;
    vuint16_t DEFAULT_SYNC:1;
    vuint16_t GTM_TRIG_SEL:1;
    vuint16_t SP_PULSE_SEL:1;
    vuint16_t OP_SEL:1;
    vuint16_t SW_READY:1;
  } B;
} PSI5_CH2_DOBCR_tag;

typedef union PSI5_CH2_MDDIS_OFF_union_tag { /* Manchestor Decoder Disable Offset */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t MDDIS_OFF:7;
  } B;
} PSI5_CH2_MDDIS_OFF_tag;

typedef union PSI5_CH2_PW0D_union_tag { /* Pulse Width for Data Bit Value 0 */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t Pulse_Width0:7;
  } B;
} PSI5_CH2_PW0D_tag;

typedef union PSI5_CH2_PW1D_union_tag { /* Pulse Width for Data Bit Value 1 */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t Pulse_Width1:7;
  } B;
} PSI5_CH2_PW1D_tag;

typedef union PSI5_CH2_CTPR_union_tag { /* Counter Target Pulse Register */
  vuint16_t R;
  struct {
    vuint16_t CTPR:16;
  } B;
} PSI5_CH2_CTPR_tag;

typedef union PSI5_CH2_CIPR_union_tag { /* Counter Initialize Pulse Register */
  vuint16_t R;
  struct {
    vuint16_t CIPR:16;
  } B;
} PSI5_CH2_CIPR_tag;

typedef union PSI5_CH2_DPRL_union_tag { /* Data Preparation Register Low */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t DPR:24;
  } B;
} PSI5_CH2_DPRL_tag;

typedef union PSI5_CH2_DPRH_union_tag { /* Data Preparation Register High */
  vuint32_t R;
  struct {
    vuint32_t  :32;
  } B;
} PSI5_CH2_DPRH_tag;

typedef union PSI5_CH2_DBRL_union_tag { /* Data Buffer Register Low */
  vuint32_t R;
  struct {
    vuint32_t DBR:32;
  } B;
} PSI5_CH2_DBRL_tag;

typedef union PSI5_CH2_DBRH_union_tag { /* Data Buffer Register High */
  vuint32_t R;
  struct {
    vuint32_t DBR:32;
  } B;
} PSI5_CH2_DBRH_tag;

typedef union PSI5_CH2_DSRL_union_tag { /* Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DSR:32;
  } B;
} PSI5_CH2_DSRL_tag;

typedef union PSI5_CH2_DSRH_union_tag { /* Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t DSR:32;
  } B;
} PSI5_CH2_DSRH_tag;


/* ==== CH3 REG ==== */
typedef union PSI5_CH3_PCCR_union_tag { /* PSI5 Channel Control Register */
  vuint32_t R;
  struct {
    vuint32_t CTC_GED_SEL:1;
    vuint32_t CTC_ED:1;
    vuint32_t  :1;
    vuint32_t MEM_DEPTH:5;
    vuint32_t  :3;
    vuint32_t ERROR_SELECT4:1;
    vuint32_t ERROR_SELECT3:1;
    vuint32_t ERROR_SELECT2:1;
    vuint32_t ERROR_SELECT1:1;
    vuint32_t ERROR_SELECT0:1;
    vuint32_t  :1;
    vuint32_t GTM_RESET_ASYNC_EN:1;
    vuint32_t  :3;
    vuint32_t DEBUG_EN:1;
    vuint32_t DEBUG_FREEZE_CTRL:1;
    vuint32_t SP_TS_CLK_SEL:1;
    vuint32_t  :2;
    vuint32_t FAST_CLR_SMC:1;
    vuint32_t FAST_CLR_PSI5:1;
    vuint32_t BIT_RATE:1;
    vuint32_t MODE:1;
    vuint32_t PSI5_CH_CONFIG:1;
    vuint32_t PSI5_CH_EN:1;
  } B;
} PSI5_CH3_PCCR_tag;

typedef union PSI5_CH3_DCR_union_tag { /* DMA Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t DMA_PM_DS_WM:5;
    vuint32_t  :5;
    vuint32_t IE_DMA_TF_SF:1;
    vuint32_t IE_DMA_TF_PM_DS:1;
    vuint32_t  :5;
    vuint32_t IE_DMA_PM_DS_FIFO_FULL:1;
    vuint32_t IE_DMA_SFUF:1;
    vuint32_t  :1;
    vuint32_t IE_DMA_PM_DS_UF:1;
    vuint32_t  :5;
    vuint32_t DMA_EN_SF:1;
    vuint32_t DMA_PM_DS_CONFIG:2;
  } B;
} PSI5_CH3_DCR_tag;

typedef union PSI5_CH3_DSR_union_tag { /* DMA Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t IS_DMA_TF_SF:1;
    vuint32_t IS_DMA_TF_PM_DS:1;
    vuint32_t  :5;
    vuint32_t IS_DMA_PM_DS_FIFO_FULL:1;
    vuint32_t IS_DMA_SFUF:1;
    vuint32_t  :1;
    vuint32_t IS_DMA_PM_DS_UF:1;
    vuint32_t  :8;
  } B;
} PSI5_CH3_DSR_tag;

typedef union PSI5_CH3_GICR_union_tag { /* General Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t IE_CESM:6;
    vuint32_t IE_STS:1;
    vuint32_t IE_DTS:1;
    vuint32_t IE_DSROW:1;
    vuint32_t IE_BROW:1;
    vuint32_t IE_PROW:1;
    vuint32_t IE_DSRR:1;
    vuint32_t IE_BRR:1;
    vuint32_t IE_PRR:1;
    vuint32_t  :2;
    vuint32_t IE_OWSM:6;
    vuint32_t  :2;
    vuint32_t IE_NVSM:6;
  } B;
} PSI5_CH3_GICR_tag;

typedef union PSI5_CH3_NDICR_union_tag { /* New Data Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_ND:32;
  } B;
} PSI5_CH3_NDICR_tag;

typedef union PSI5_CH3_OWICR_union_tag { /* Overwrite Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_OW:32;
  } B;
} PSI5_CH3_OWICR_tag;

typedef union PSI5_CH3_EICR_union_tag { /* Error Interrupt Control Register */
  vuint32_t R;
  struct {
    vuint32_t IE_ERROR:32;
  } B;
} PSI5_CH3_EICR_tag;

typedef union PSI5_CH3_GISR_union_tag { /* General Interrupt Status Register */
  vuint32_t R;
  struct {
    vuint32_t IS_DB_FR:1;
    vuint32_t  :1;
    vuint32_t IS_CESM:6;
    vuint32_t IS_STS:1;
    vuint32_t IS_DTS:1;
    vuint32_t IS_DSROW:1;
    vuint32_t IS_BROW:1;
    vuint32_t IS_PROW:1;
    vuint32_t DSR_RDY:1;
    vuint32_t DBR_RDY:1;
    vuint32_t DPR_RDY:1;
    vuint32_t  :2;
    vuint32_t IS_OWSM:6;
    vuint32_t  :2;
    vuint32_t IS_NVSM:6;
  } B;
} PSI5_CH3_GISR_tag;

typedef union PSI5_CH3_DPMR_union_tag { /* DMA PSI5 Message Register */
  vuint32_t R;
  struct {
    vuint32_t PSI5_RXDATA:32;
  } B;
} PSI5_CH3_DPMR_tag;

typedef union PSI5_CH3_DSFR_union_tag { /* DMA SMC Frame Register */
  vuint32_t R;
  struct {
    vuint32_t SMC_RXDATA:32;
  } B;
} PSI5_CH3_DSFR_tag;

typedef union PSI5_CH3_DDSR_union_tag { /* DMA Diagnostic Status Register */
  vuint32_t R;
  struct {
    vuint32_t DDS:32;
  } B;
} PSI5_CH3_DDSR_tag;

typedef union PSI5_CH3_PMRRL_union_tag { /* PSI5 Message Receive Register Low */
  vuint32_t R;
  struct {
    vuint32_t DATA_REGION:28;
    vuint32_t CRC:3;
    vuint32_t C:1;
  } B;
} PSI5_CH3_PMRRL_tag;

typedef union PSI5_CH3_PMRRH_union_tag { /* PSI5 Message Receive Register High */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t F:1;
    vuint32_t EM:1;
    vuint32_t E:1;
    vuint32_t T:1;
    vuint32_t SlotCounter:3;
    vuint32_t TimeStampValue:24;
  } B;
} PSI5_CH3_PMRRH_tag;

typedef union PSI5_CH3_PMRL_union_tag { /* PSI5 Message Register Low i */
  vuint32_t R;
  struct {
    vuint32_t DATA_REGION:28;
    vuint32_t CRCP:3;
    vuint32_t C:1;
  } B;
} PSI5_CH3_PMRL_tag;

typedef union PSI5_CH3_PMRH_union_tag { /* PSI5 Message Register High i */
  vuint32_t R;
  struct {
    vuint32_t O:1;
    vuint32_t F:1;
    vuint32_t EM:1;
    vuint32_t E:1;
    vuint32_t T:1;
    vuint32_t Slot_Counter:3;
    vuint32_t TimeStampValue:24;
  } B;
} PSI5_CH3_PMRH_tag;

typedef struct PSI5_CH3_struct_tag {
  PSI5_CH3_PMRL_tag PMRL;              /* PSI5 Message Register Low i */
  PSI5_CH3_PMRH_tag PMRH;              /* PSI5 Message Register High i */
} PSI5_CH3_tag;

typedef union PSI5_CH3_SFR_union_tag { /* SMC Frame Register n */
  vuint32_t R;
  struct {
    vuint32_t SLOT_NO:3;
    vuint32_t CER:1;
    vuint32_t OW:1;
    vuint32_t CRC:6;
    vuint32_t C:1;
    vuint32_t ID:4;
    vuint32_t IDDATA:4;
    vuint32_t DATA:12;
  } B;
} PSI5_CH3_SFR_tag;

typedef union PSI5_CH3_NDSR_union_tag { /* New Data Status Register */
  vuint32_t R;
  struct {
    vuint32_t NDS:32;
  } B;
} PSI5_CH3_NDSR_tag;

typedef union PSI5_CH3_OWSR_union_tag { /* Overwrite Status Register */
  vuint32_t R;
  struct {
    vuint32_t OWS:32;
  } B;
} PSI5_CH3_OWSR_tag;

typedef union PSI5_CH3_EISR_union_tag { /* Error Indication Status Register */
  vuint32_t R;
  struct {
    vuint32_t ERROR:32;
  } B;
} PSI5_CH3_EISR_tag;

typedef union PSI5_CH3_SNDSR_union_tag { /* Set New Data Status Register */
  vuint32_t R;
  struct {
    vuint32_t SNDS:32;
  } B;
} PSI5_CH3_SNDSR_tag;

typedef union PSI5_CH3_SOWSR_union_tag { /* Set Overwrite Status Register */
  vuint32_t R;
  struct {
    vuint32_t SOWS:32;
  } B;
} PSI5_CH3_SOWSR_tag;

typedef union PSI5_CH3_SEISR_union_tag { /* Set Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t SERROR:32;
  } B;
} PSI5_CH3_SEISR_tag;

typedef union PSI5_CH3_SSESR_union_tag { /* Set SMC Error Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t SCESM:6;
    vuint32_t  :10;
    vuint32_t SOWSM:6;
    vuint32_t  :2;
    vuint32_t SNVSM:6;
  } B;
} PSI5_CH3_SSESR_tag;

typedef union PSI5_CH3_STSRR_union_tag { /* Sync Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t STSV:24;
  } B;
} PSI5_CH3_STSRR_tag;

typedef union PSI5_CH3_DTSRR_union_tag { /* Data Time Stamp Read Register */
  vuint32_t R;
  struct {
    vuint32_t  :5;
    vuint32_t SLOT_COUNTER:3;
    vuint32_t DTSV:24;
  } B;
} PSI5_CH3_DTSRR_tag;

typedef union PSI5_CH3_SFCR_union_tag { /* Slot n Frame Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t SLOT_EN:1;
    vuint32_t TS_CAPT:1;
    vuint32_t  :1;
    vuint32_t SMCL:1;
    vuint32_t  :9;
    vuint32_t DRL:5;
    vuint32_t CRCP:1;
  } B;
} PSI5_CH3_SFCR_tag;

typedef union PSI5_CH3_S1SBR_union_tag { /* Slot 1 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S1SBT:15;
  } B;
} PSI5_CH3_S1SBR_tag;

typedef union PSI5_CH3_S2SBR_union_tag { /* Slot 2 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S2SBT:15;
  } B;
} PSI5_CH3_S2SBR_tag;

typedef union PSI5_CH3_S3SBR_union_tag { /* Slot 3 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S3SBT:15;
  } B;
} PSI5_CH3_S3SBR_tag;

typedef union PSI5_CH3_S4SBR_union_tag { /* Slot 4 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S4SBT:15;
  } B;
} PSI5_CH3_S4SBR_tag;

typedef union PSI5_CH3_S5SBR_union_tag { /* Slot 5 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S5SBT:15;
  } B;
} PSI5_CH3_S5SBR_tag;

typedef union PSI5_CH3_S6SBR_union_tag { /* Slot 6 Start Boundary Register */
  vuint16_t R;
  struct {
    vuint16_t  :1;
    vuint16_t S6SBT:15;
  } B;
} PSI5_CH3_S6SBR_tag;

typedef union PSI5_CH3_SnEBR_union_tag { /* Slot n End Boundary Register */
  vuint32_t R;
  struct {
    vuint32_t  :13;
    vuint32_t SLOT_NO:3;
    vuint32_t  :1;
    vuint32_t SnEBT:15;
  } B;
} PSI5_CH3_SnEBR_tag;

typedef union PSI5_CH3_DOBCR_union_tag { /* Data Output Block Configuration Register */
  vuint16_t R;
  struct {
    vuint16_t DATA_LENGTH:6;
    vuint16_t DBR_RST:1;
    vuint16_t DSR_RST:1;
    vuint16_t CMD_TYPE:3;
    vuint16_t DEFAULT_SYNC:1;
    vuint16_t GTM_TRIG_SEL:1;
    vuint16_t SP_PULSE_SEL:1;
    vuint16_t OP_SEL:1;
    vuint16_t SW_READY:1;
  } B;
} PSI5_CH3_DOBCR_tag;

typedef union PSI5_CH3_MDDIS_OFF_union_tag { /* Manchestor Decoder Disable Offset */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t MDDIS_OFF:7;
  } B;
} PSI5_CH3_MDDIS_OFF_tag;

typedef union PSI5_CH3_PW0D_union_tag { /* Pulse Width for Data Bit Value 0 */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t Pulse_Width0:7;
  } B;
} PSI5_CH3_PW0D_tag;

typedef union PSI5_CH3_PW1D_union_tag { /* Pulse Width for Data Bit Value 1 */
  vuint16_t R;
  struct {
    vuint16_t  :9;
    vuint16_t Pulse_Width1:7;
  } B;
} PSI5_CH3_PW1D_tag;

typedef union PSI5_CH3_CTPR_union_tag { /* Counter Target Pulse Register */
  vuint16_t R;
  struct {
    vuint16_t CTPR:16;
  } B;
} PSI5_CH3_CTPR_tag;

typedef union PSI5_CH3_CIPR_union_tag { /* Counter Initialize Pulse Register */
  vuint16_t R;
  struct {
    vuint16_t CIPR:16;
  } B;
} PSI5_CH3_CIPR_tag;

typedef union PSI5_CH3_DPRL_union_tag { /* Data Preparation Register Low */
  vuint32_t R;
  struct {
    vuint32_t  :8;
    vuint32_t DPR:24;
  } B;
} PSI5_CH3_DPRL_tag;

typedef union PSI5_CH3_DPRH_union_tag { /* Data Preparation Register High */
  vuint32_t R;
  struct {
    vuint32_t  :32;
  } B;
} PSI5_CH3_DPRH_tag;

typedef union PSI5_CH3_DBRL_union_tag { /* Data Buffer Register Low */
  vuint32_t R;
  struct {
    vuint32_t DBR:32;
  } B;
} PSI5_CH3_DBRL_tag;

typedef union PSI5_CH3_DBRH_union_tag { /* Data Buffer Register High */
  vuint32_t R;
  struct {
    vuint32_t DBR:32;
  } B;
} PSI5_CH3_DBRH_tag;

typedef union PSI5_CH3_DSRL_union_tag { /* Data Shift Register Low */
  vuint32_t R;
  struct {
    vuint32_t DSR:32;
  } B;
} PSI5_CH3_DSRL_tag;

typedef union PSI5_CH3_DSRH_union_tag { /* Data Shift Register High */
  vuint32_t R;
  struct {
    vuint32_t DSR:32;
  } B;
} PSI5_CH3_DSRH_tag;
/* ==== CH3 REG END ==== */

struct PSI5_tag {
  PSI5_GCR_tag GCR;                    /* Global Control Register */
  uint8_t PSI5_reserved0[6];
  PSI5_CH0_PCCR_tag CH0_PCCR;          /* PSI5 Channel Control Register */
  PSI5_CH0_DCR_tag CH0_DCR;            /* DMA Control Register */
  PSI5_CH0_DSR_tag CH0_DSR;            /* DMA Status Register */
  PSI5_CH0_GICR_tag CH0_GICR;          /* General Interrupt Control Register */
  PSI5_CH0_NDICR_tag CH0_NDICR;        /* New Data Interrupt Control Register */
  PSI5_CH0_OWICR_tag CH0_OWICR;        /* Overwrite Interrupt Control Register */
  PSI5_CH0_EICR_tag CH0_EICR;          /* Error Interrupt Control Register */
  PSI5_CH0_GISR_tag CH0_GISR;          /* General Interrupt Status Register */
  PSI5_CH0_DPMR_tag CH0_DPMR;          /* DMA PSI5 Message Register */
  PSI5_CH0_DSFR_tag CH0_DSFR;          /* DMA SMC Frame Register */
  PSI5_CH0_DDSR_tag CH0_DDSR;          /* DMA Diagnostic Status Register */
  PSI5_CH0_PMRRL_tag CH0_PMRRL;        /* PSI5 Message Receive Register Low */
  PSI5_CH0_PMRRH_tag CH0_PMRRH;        /* PSI5 Message Receive Register High */
  PSI5_CH0_tag CH0[32];
  PSI5_CH0_SFR_tag CH0_SFR[6];         /* SMC Frame Register n */
  PSI5_CH0_NDSR_tag CH0_NDSR;          /* New Data Status Register */
  PSI5_CH0_OWSR_tag CH0_OWSR;          /* Overwrite Status Register */
  PSI5_CH0_EISR_tag CH0_EISR;          /* Error Indication Status Register */
  PSI5_CH0_SNDSR_tag CH0_SNDSR;        /* Set New Data Status Register */
  PSI5_CH0_SOWSR_tag CH0_SOWSR;        /* Set Overwrite Status Register */
  PSI5_CH0_SEISR_tag CH0_SEISR;        /* Set Error Status Register */
  PSI5_CH0_SSESR_tag CH0_SSESR;        /* Set SMC Error Status Register */
  PSI5_CH0_STSRR_tag CH0_STSRR;        /* Sync Time Stamp Read Register */
  PSI5_CH0_DTSRR_tag CH0_DTSRR;        /* Data Time Stamp Read Register */
  PSI5_CH0_SFCR_tag CH0_SFCR[6];       /* Slot n Frame Configuration Register */
  PSI5_CH0_S1SBR_tag CH0_S1SBR;        /* Slot 1 Start Boundary Register */
  PSI5_CH0_S2SBR_tag CH0_S2SBR;        /* Slot 2 Start Boundary Register */
  PSI5_CH0_S3SBR_tag CH0_S3SBR;        /* Slot 3 Start Boundary Register */
  PSI5_CH0_S4SBR_tag CH0_S4SBR;        /* Slot 4 Start Boundary Register */
  PSI5_CH0_S5SBR_tag CH0_S5SBR;        /* Slot 5 Start Boundary Register */
  PSI5_CH0_S6SBR_tag CH0_S6SBR;        /* Slot 6 Start Boundary Register */
  PSI5_CH0_SnEBR_tag CH0_SnEBR;        /* Slot n End Boundary Register */
  PSI5_CH0_DOBCR_tag CH0_DOBCR;        /* Data Output Block Configuration Register */
  PSI5_CH0_MDDIS_OFF_tag CH0_MDDIS_OFF; /* Manchestor Decoder Disable Offset */
  PSI5_CH0_PW0D_tag CH0_PW0D;          /* Pulse Width for Data Bit Value 0 */
  PSI5_CH0_PW1D_tag CH0_PW1D;          /* Pulse Width for Data Bit Value 1 */
  PSI5_CH0_CTPR_tag CH0_CTPR;          /* Counter Target Pulse Register */
  PSI5_CH0_CIPR_tag CH0_CIPR;          /* Counter Initialize Pulse Register */
  PSI5_CH0_DPRL_tag CH0_DPRL;          /* Data Preparation Register Low */
  PSI5_CH0_DPRH_tag CH0_DPRH;          /* Data Preparation Register High */
  PSI5_CH0_DBRL_tag CH0_DBRL;          /* Data Buffer Register Low */
  PSI5_CH0_DBRH_tag CH0_DBRH;          /* Data Buffer Register High */
  PSI5_CH0_DSRL_tag CH0_DSRL;          /* Data Shift Register Low */
  PSI5_CH0_DSRH_tag CH0_DSRH;          /* Data Shift Register High */
  uint8_t PSI5_reserved1[4];
  PSI5_CH1_PCCR_tag CH1_PCCR;          /* PSI5 Channel Control Register */
  PSI5_CH1_DCR_tag CH1_DCR;            /* DMA Control Register */
  PSI5_CH1_DSR_tag CH1_DSR;            /* DMA Status Register */
  PSI5_CH1_GICR_tag CH1_GICR;          /* General Interrupt Control Register */
  PSI5_CH1_NDICR_tag CH1_NDICR;        /* New Data Interrupt Control Register */
  PSI5_CH1_OWICR_tag CH1_OWICR;        /* Overwrite Interrupt Control Register */
  PSI5_CH1_EICR_tag CH1_EICR;          /* Error Interrupt Control Register */
  PSI5_CH1_GISR_tag CH1_GISR;          /* General Interrupt Status Register */
  PSI5_CH1_DPMR_tag CH1_DPMR;          /* DMA PSI5 Message Register */
  PSI5_CH1_DSFR_tag CH1_DSFR;          /* DMA SMC Frame Register */
  PSI5_CH1_DDSR_tag CH1_DDSR;          /* DMA Diagnostic Status Register */
  PSI5_CH1_PMRRL_tag CH1_PMRRL;        /* PSI5 Message Receive Register Low */
  PSI5_CH1_PMRRH_tag CH1_PMRRH;        /* PSI5 Message Receive Register High */
  PSI5_CH1_tag CH1[32];
  PSI5_CH1_SFR_tag CH1_SFR[6];         /* SMC Frame Register n */
  PSI5_CH1_NDSR_tag CH1_NDSR;          /* New Data Status Register */
  PSI5_CH1_OWSR_tag CH1_OWSR;          /* Overwrite Status Register */
  PSI5_CH1_EISR_tag CH1_EISR;          /* Error Indication Status Register */
  PSI5_CH1_SNDSR_tag CH1_SNDSR;        /* Set New Data Status Register */
  PSI5_CH1_SOWSR_tag CH1_SOWSR;        /* Set Overwrite Status Register */
  PSI5_CH1_SEISR_tag CH1_SEISR;        /* Set Error Status Register */
  PSI5_CH1_SSESR_tag CH1_SSESR;        /* Set SMC Error Status Register */
  PSI5_CH1_STSRR_tag CH1_STSRR;        /* Sync Time Stamp Read Register */
  PSI5_CH1_DTSRR_tag CH1_DTSRR;        /* Data Time Stamp Read Register */
  PSI5_CH1_SFCR_tag CH1_SFCR[6];       /* Slot n Frame Configuration Register */
  PSI5_CH1_S1SBR_tag CH1_S1SBR;        /* Slot 1 Start Boundary Register */
  PSI5_CH1_S2SBR_tag CH1_S2SBR;        /* Slot 2 Start Boundary Register */
  PSI5_CH1_S3SBR_tag CH1_S3SBR;        /* Slot 3 Start Boundary Register */
  PSI5_CH1_S4SBR_tag CH1_S4SBR;        /* Slot 4 Start Boundary Register */
  PSI5_CH1_S5SBR_tag CH1_S5SBR;        /* Slot 5 Start Boundary Register */
  PSI5_CH1_S6SBR_tag CH1_S6SBR;        /* Slot 6 Start Boundary Register */
  PSI5_CH1_SnEBR_tag CH1_SnEBR;        /* Slot n End Boundary Register */
  PSI5_CH1_DOBCR_tag CH1_DOBCR;        /* Data Output Block Configuration Register */
  PSI5_CH1_MDDIS_OFF_tag CH1_MDDIS_OFF; /* Manchestor Decoder Disable Offset */
  PSI5_CH1_PW0D_tag CH1_PW0D;          /* Pulse Width for Data Bit Value 0 */
  PSI5_CH1_PW1D_tag CH1_PW1D;          /* Pulse Width for Data Bit Value 1 */
  PSI5_CH1_CTPR_tag CH1_CTPR;          /* Counter Target Pulse Register */
  PSI5_CH1_CIPR_tag CH1_CIPR;          /* Counter Initialize Pulse Register */
  PSI5_CH1_DPRL_tag CH1_DPRL;          /* Data Preparation Register Low */
  PSI5_CH1_DPRH_tag CH1_DPRH;          /* Data Preparation Register High */
  PSI5_CH1_DBRL_tag CH1_DBRL;          /* Data Buffer Register Low */
  PSI5_CH1_DBRH_tag CH1_DBRH;          /* Data Buffer Register High */
  PSI5_CH1_DSRL_tag CH1_DSRL;          /* Data Shift Register Low */
  PSI5_CH1_DSRH_tag CH1_DSRH;          /* Data Shift Register High */
  uint8_t PSI5_reserved2[4];
  PSI5_CH2_PCCR_tag CH2_PCCR;          /* PSI5 Channel Control Register */
  PSI5_CH2_DCR_tag CH2_DCR;            /* DMA Control Register */
  PSI5_CH2_DSR_tag CH2_DSR;            /* DMA Status Register */
  PSI5_CH2_GICR_tag CH2_GICR;          /* General Interrupt Control Register */
  PSI5_CH2_NDICR_tag CH2_NDICR;        /* New Data Interrupt Control Register */
  PSI5_CH2_OWICR_tag CH2_OWICR;        /* Overwrite Interrupt Control Register */
  PSI5_CH2_EICR_tag CH2_EICR;          /* Error Interrupt Control Register */
  PSI5_CH2_GISR_tag CH2_GISR;          /* General Interrupt Status Register */
  PSI5_CH2_DPMR_tag CH2_DPMR;          /* DMA PSI5 Message Register */
  PSI5_CH2_DSFR_tag CH2_DSFR;          /* DMA SMC Frame Register */
  PSI5_CH2_DDSR_tag CH2_DDSR;          /* DMA Diagnostic Status Register */
  PSI5_CH2_PMRRL_tag CH2_PMRRL;        /* PSI5 Message Receive Register Low */
  PSI5_CH2_PMRRH_tag CH2_PMRRH;        /* PSI5 Message Receive Register High */
  PSI5_CH2_tag CH2[32];
  PSI5_CH2_SFR_tag CH2_SFR[6];         /* SMC Frame Register n */
  PSI5_CH2_NDSR_tag CH2_NDSR;          /* New Data Status Register */
  PSI5_CH2_OWSR_tag CH2_OWSR;          /* Overwrite Status Register */
  PSI5_CH2_EISR_tag CH2_EISR;          /* Error Indication Status Register */
  PSI5_CH2_SNDSR_tag CH2_SNDSR;        /* Set New Data Status Register */
  PSI5_CH2_SOWSR_tag CH2_SOWSR;        /* Set Overwrite Status Register */
  PSI5_CH2_SEISR_tag CH2_SEISR;        /* Set Error Status Register */
  PSI5_CH2_SSESR_tag CH2_SSESR;        /* Set SMC Error Status Register */
  PSI5_CH2_STSRR_tag CH2_STSRR;        /* Sync Time Stamp Read Register */
  PSI5_CH2_DTSRR_tag CH2_DTSRR;        /* Data Time Stamp Read Register */
  PSI5_CH2_SFCR_tag CH2_SFCR[6];       /* Slot n Frame Configuration Register */
  PSI5_CH2_S1SBR_tag CH2_S1SBR;        /* Slot 1 Start Boundary Register */
  PSI5_CH2_S2SBR_tag CH2_S2SBR;        /* Slot 2 Start Boundary Register */
  PSI5_CH2_S3SBR_tag CH2_S3SBR;        /* Slot 3 Start Boundary Register */
  PSI5_CH2_S4SBR_tag CH2_S4SBR;        /* Slot 4 Start Boundary Register */
  PSI5_CH2_S5SBR_tag CH2_S5SBR;        /* Slot 5 Start Boundary Register */
  PSI5_CH2_S6SBR_tag CH2_S6SBR;        /* Slot 6 Start Boundary Register */
  PSI5_CH2_SnEBR_tag CH2_SnEBR;        /* Slot n End Boundary Register */
  PSI5_CH2_DOBCR_tag CH2_DOBCR;        /* Data Output Block Configuration Register */
  PSI5_CH2_MDDIS_OFF_tag CH2_MDDIS_OFF; /* Manchestor Decoder Disable Offset */
  PSI5_CH2_PW0D_tag CH2_PW0D;          /* Pulse Width for Data Bit Value 0 */
  PSI5_CH2_PW1D_tag CH2_PW1D;          /* Pulse Width for Data Bit Value 1 */
  PSI5_CH2_CTPR_tag CH2_CTPR;          /* Counter Target Pulse Register */
  PSI5_CH2_CIPR_tag CH2_CIPR;          /* Counter Initialize Pulse Register */
  PSI5_CH2_DPRL_tag CH2_DPRL;          /* Data Preparation Register Low */
  PSI5_CH2_DPRH_tag CH2_DPRH;          /* Data Preparation Register High */
  PSI5_CH2_DBRL_tag CH2_DBRL;          /* Data Buffer Register Low */
  PSI5_CH2_DBRH_tag CH2_DBRH;          /* Data Buffer Register High */
  PSI5_CH2_DSRL_tag CH2_DSRL;          /* Data Shift Register Low */
  PSI5_CH2_DSRH_tag CH2_DSRH;          /* Data Shift Register High */
  uint8_t PSI5_reserved3[4];
  PSI5_CH3_PCCR_tag CH3_PCCR;          /* PSI5 Channel Control Register */
  PSI5_CH3_DCR_tag CH3_DCR;            /* DMA Control Register */
  PSI5_CH3_DSR_tag CH3_DSR;            /* DMA Status Register */
  PSI5_CH3_GICR_tag CH3_GICR;          /* General Interrupt Control Register */
  PSI5_CH3_NDICR_tag CH3_NDICR;        /* New Data Interrupt Control Register */
  PSI5_CH3_OWICR_tag CH3_OWICR;        /* Overwrite Interrupt Control Register */
  PSI5_CH3_EICR_tag CH3_EICR;          /* Error Interrupt Control Register */
  PSI5_CH3_GISR_tag CH3_GISR;          /* General Interrupt Status Register */
  PSI5_CH3_DPMR_tag CH3_DPMR;          /* DMA PSI5 Message Register */
  PSI5_CH3_DSFR_tag CH3_DSFR;          /* DMA SMC Frame Register */
  PSI5_CH3_DDSR_tag CH3_DDSR;          /* DMA Diagnostic Status Register */
  PSI5_CH3_PMRRL_tag CH3_PMRRL;        /* PSI5 Message Receive Register Low */
  PSI5_CH3_PMRRH_tag CH3_PMRRH;        /* PSI5 Message Receive Register High */
  PSI5_CH3_tag CH3[32];
  PSI5_CH3_SFR_tag CH3_SFR[6];         /* SMC Frame Register n */
  PSI5_CH3_NDSR_tag CH3_NDSR;          /* New Data Status Register */
  PSI5_CH3_OWSR_tag CH3_OWSR;          /* Overwrite Status Register */
  PSI5_CH3_EISR_tag CH3_EISR;          /* Error Indication Status Register */
  PSI5_CH3_SNDSR_tag CH3_SNDSR;        /* Set New Data Status Register */
  PSI5_CH3_SOWSR_tag CH3_SOWSR;        /* Set Overwrite Status Register */
  PSI5_CH3_SEISR_tag CH3_SEISR;        /* Set Error Status Register */
  PSI5_CH3_SSESR_tag CH3_SSESR;        /* Set SMC Error Status Register */
  PSI5_CH3_STSRR_tag CH3_STSRR;        /* Sync Time Stamp Read Register */
  PSI5_CH3_DTSRR_tag CH3_DTSRR;        /* Data Time Stamp Read Register */
  PSI5_CH3_SFCR_tag CH3_SFCR[6];       /* Slot n Frame Configuration Register */
  PSI5_CH3_S1SBR_tag CH3_S1SBR;        /* Slot 1 Start Boundary Register */
  PSI5_CH3_S2SBR_tag CH3_S2SBR;        /* Slot 2 Start Boundary Register */
  PSI5_CH3_S3SBR_tag CH3_S3SBR;        /* Slot 3 Start Boundary Register */
  PSI5_CH3_S4SBR_tag CH3_S4SBR;        /* Slot 4 Start Boundary Register */
  PSI5_CH3_S5SBR_tag CH3_S5SBR;        /* Slot 5 Start Boundary Register */
  PSI5_CH3_S6SBR_tag CH3_S6SBR;        /* Slot 6 Start Boundary Register */
  PSI5_CH3_SnEBR_tag CH3_SnEBR;        /* Slot n End Boundary Register */
  PSI5_CH3_DOBCR_tag CH3_DOBCR;        /* Data Output Block Configuration Register */
  PSI5_CH3_MDDIS_OFF_tag CH3_MDDIS_OFF; /* Manchestor Decoder Disable Offset */
  PSI5_CH3_PW0D_tag CH3_PW0D;          /* Pulse Width for Data Bit Value 0 */
  PSI5_CH3_PW1D_tag CH3_PW1D;          /* Pulse Width for Data Bit Value 1 */
  PSI5_CH3_CTPR_tag CH3_CTPR;          /* Counter Target Pulse Register */
  PSI5_CH3_CIPR_tag CH3_CIPR;          /* Counter Initialize Pulse Register */
  PSI5_CH3_DPRL_tag CH3_DPRL;          /* Data Preparation Register Low */
  PSI5_CH3_DPRH_tag CH3_DPRH;          /* Data Preparation Register High */
  PSI5_CH3_DBRL_tag CH3_DBRL;          /* Data Buffer Register Low */
  PSI5_CH3_DBRH_tag CH3_DBRH;          /* Data Buffer Register High */
  PSI5_CH3_DSRL_tag CH3_DSRL;          /* Data Shift Register Low */
  PSI5_CH3_DSRH_tag CH3_DSRH;          /* Data Shift Register High */
};
#endif
