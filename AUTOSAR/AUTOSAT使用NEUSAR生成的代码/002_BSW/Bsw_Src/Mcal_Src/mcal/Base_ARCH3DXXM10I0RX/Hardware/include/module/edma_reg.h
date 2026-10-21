#ifndef EDMA_REG_H_
#define EDMA_REG_H_

/* ============================================================================
   =============================== Module: eDMA ===============================
   ============================================================================ */

typedef union eDMA_CR_union_tag {      /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :14;
    vuint32_t CX:1;
    vuint32_t ECX:1;
    vuint32_t GRP3PRI:2;
    vuint32_t GRP2PRI:2;
    vuint32_t GRP1PRI:2;
    vuint32_t GRP0PRI:2;
    vuint32_t EMLM:1;
    vuint32_t CLM:1;
    vuint32_t HALT:1;
    vuint32_t HOE:1;
    vuint32_t ERGA:1;
    vuint32_t ERCA:1;
    vuint32_t EDBG:1;
    vuint32_t  :1;
  } B;
} eDMA_CR_tag;

typedef union eDMA_ES_union_tag {      /* Error Status */
  vuint32_t R;
  struct {
    vuint32_t VLD:1;
    vuint32_t  :13;
    vuint32_t UCE:1;
    vuint32_t ECX:1;
    vuint32_t GPE:1;
    vuint32_t CPE:1;
    vuint32_t ERRCHN:6;
    vuint32_t SAE:1;
    vuint32_t SOE:1;
    vuint32_t DAE:1;
    vuint32_t DOE:1;
    vuint32_t NCE:1;
    vuint32_t SGE:1;
    vuint32_t SBE:1;
    vuint32_t DBE:1;
  } B;
} eDMA_ES_tag;

typedef union eDMA_ERQH_union_tag {    /* Enable Request Register High */
  vuint32_t R;
  struct {
    vuint32_t ERQ63:1;
    vuint32_t ERQ62:1;
    vuint32_t ERQ61:1;
    vuint32_t ERQ60:1;
    vuint32_t ERQ59:1;
    vuint32_t ERQ58:1;
    vuint32_t ERQ57:1;
    vuint32_t ERQ56:1;
    vuint32_t ERQ55:1;
    vuint32_t ERQ54:1;
    vuint32_t ERQ53:1;
    vuint32_t ERQ52:1;
    vuint32_t ERQ51:1;
    vuint32_t ERQ50:1;
    vuint32_t ERQ49:1;
    vuint32_t ERQ48:1;
    vuint32_t ERQ47:1;
    vuint32_t ERQ46:1;
    vuint32_t ERQ45:1;
    vuint32_t ERQ44:1;
    vuint32_t ERQ43:1;
    vuint32_t ERQ42:1;
    vuint32_t ERQ41:1;
    vuint32_t ERQ40:1;
    vuint32_t ERQ39:1;
    vuint32_t ERQ38:1;
    vuint32_t ERQ37:1;
    vuint32_t ERQ36:1;
    vuint32_t ERQ35:1;
    vuint32_t ERQ34:1;
    vuint32_t ERQ33:1;
    vuint32_t ERQ32:1;
  } B;
} eDMA_ERQH_tag;

typedef union eDMA_ERQL_union_tag {    /* Enable Request Register Low */
  vuint32_t R;
  struct {
    vuint32_t ERQ31:1;
    vuint32_t ERQ30:1;
    vuint32_t ERQ29:1;
    vuint32_t ERQ28:1;
    vuint32_t ERQ27:1;
    vuint32_t ERQ26:1;
    vuint32_t ERQ25:1;
    vuint32_t ERQ24:1;
    vuint32_t ERQ23:1;
    vuint32_t ERQ22:1;
    vuint32_t ERQ21:1;
    vuint32_t ERQ20:1;
    vuint32_t ERQ19:1;
    vuint32_t ERQ18:1;
    vuint32_t ERQ17:1;
    vuint32_t ERQ16:1;
    vuint32_t ERQ15:1;
    vuint32_t ERQ14:1;
    vuint32_t ERQ13:1;
    vuint32_t ERQ12:1;
    vuint32_t ERQ11:1;
    vuint32_t ERQ10:1;
    vuint32_t ERQ9:1;
    vuint32_t ERQ8:1;
    vuint32_t ERQ7:1;
    vuint32_t ERQ6:1;
    vuint32_t ERQ5:1;
    vuint32_t ERQ4:1;
    vuint32_t ERQ3:1;
    vuint32_t ERQ2:1;
    vuint32_t ERQ1:1;
    vuint32_t ERQ0:1;
  } B;
} eDMA_ERQL_tag;

typedef union eDMA_EEIH_union_tag {    /* Enable Error Interrupt Register High */
  vuint32_t R;
  struct {
    vuint32_t EEI63:1;
    vuint32_t EEI62:1;
    vuint32_t EEI61:1;
    vuint32_t EEI60:1;
    vuint32_t EEI59:1;
    vuint32_t EEI58:1;
    vuint32_t EEI57:1;
    vuint32_t EEI56:1;
    vuint32_t EEI55:1;
    vuint32_t EEI54:1;
    vuint32_t EEI53:1;
    vuint32_t EEI52:1;
    vuint32_t EEI51:1;
    vuint32_t EEI50:1;
    vuint32_t EEI49:1;
    vuint32_t EEI48:1;
    vuint32_t EEI47:1;
    vuint32_t EEI46:1;
    vuint32_t EEI45:1;
    vuint32_t EEI44:1;
    vuint32_t EEI43:1;
    vuint32_t EEI42:1;
    vuint32_t EEI41:1;
    vuint32_t EEI40:1;
    vuint32_t EEI39:1;
    vuint32_t EEI38:1;
    vuint32_t EEI37:1;
    vuint32_t EEI36:1;
    vuint32_t EEI35:1;
    vuint32_t EEI34:1;
    vuint32_t EEI33:1;
    vuint32_t EEI32:1;
  } B;
} eDMA_EEIH_tag;

typedef union eDMA_EEIL_union_tag {    /* Enable Error Interrupt Register Low */
  vuint32_t R;
  struct {
    vuint32_t EEI31:1;
    vuint32_t EEI30:1;
    vuint32_t EEI29:1;
    vuint32_t EEI28:1;
    vuint32_t EEI27:1;
    vuint32_t EEI26:1;
    vuint32_t EEI25:1;
    vuint32_t EEI24:1;
    vuint32_t EEI23:1;
    vuint32_t EEI22:1;
    vuint32_t EEI21:1;
    vuint32_t EEI20:1;
    vuint32_t EEI19:1;
    vuint32_t EEI18:1;
    vuint32_t EEI17:1;
    vuint32_t EEI16:1;
    vuint32_t EEI15:1;
    vuint32_t EEI14:1;
    vuint32_t EEI13:1;
    vuint32_t EEI12:1;
    vuint32_t EEI11:1;
    vuint32_t EEI10:1;
    vuint32_t EEI9:1;
    vuint32_t EEI8:1;
    vuint32_t EEI7:1;
    vuint32_t EEI6:1;
    vuint32_t EEI5:1;
    vuint32_t EEI4:1;
    vuint32_t EEI3:1;
    vuint32_t EEI2:1;
    vuint32_t EEI1:1;
    vuint32_t EEI0:1;
  } B;
} eDMA_EEIL_tag;

typedef union eDMA_SERQ_union_tag {    /* Set Enable Request Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t SAER:1;
    vuint8_t SERQ:6;
  } B;
} eDMA_SERQ_tag;

typedef union eDMA_CERQ_union_tag {    /* Clear Enable Request Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CAER:1;
    vuint8_t CERQ:6;
  } B;
} eDMA_CERQ_tag;

typedef union eDMA_SEEI_union_tag {    /* Set Enable Error Interrupt Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t SAEE:1;
    vuint8_t SEEI:6;
  } B;
} eDMA_SEEI_tag;

typedef union eDMA_CEEI_union_tag {    /* Clear Enable Error Interrupt Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CAEE:1;
    vuint8_t CEEI:6;
  } B;
} eDMA_CEEI_tag;

typedef union eDMA_CINT_union_tag {    /* Clear Interrupt Request Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CAIR:1;
    vuint8_t CINT:6;
  } B;
} eDMA_CINT_tag;

typedef union eDMA_CERR_union_tag {    /* Clear Error Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CAEI:1;
    vuint8_t CERR:6;
  } B;
} eDMA_CERR_tag;

typedef union eDMA_SSRT_union_tag {    /* Set START Bit Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t SAST:1;
    vuint8_t SSRT:6;
  } B;
} eDMA_SSRT_tag;

typedef union eDMA_CDNE_union_tag {    /* Clear DONE Status Bit Register */
  vuint8_t R;
  struct {
    vuint8_t NOP:1;
    vuint8_t CADN:1;
    vuint8_t CDNE:6;
  } B;
} eDMA_CDNE_tag;

typedef union eDMA_INTH_union_tag {    /* Interrupt Request Register High */
  vuint32_t R;
  struct {
    vuint32_t INT63:1;
    vuint32_t INT62:1;
    vuint32_t INT61:1;
    vuint32_t INT60:1;
    vuint32_t INT59:1;
    vuint32_t INT58:1;
    vuint32_t INT57:1;
    vuint32_t INT56:1;
    vuint32_t INT55:1;
    vuint32_t INT54:1;
    vuint32_t INT53:1;
    vuint32_t INT52:1;
    vuint32_t INT51:1;
    vuint32_t INT50:1;
    vuint32_t INT49:1;
    vuint32_t INT48:1;
    vuint32_t INT47:1;
    vuint32_t INT46:1;
    vuint32_t INT45:1;
    vuint32_t INT44:1;
    vuint32_t INT43:1;
    vuint32_t INT42:1;
    vuint32_t INT41:1;
    vuint32_t INT40:1;
    vuint32_t INT39:1;
    vuint32_t INT38:1;
    vuint32_t INT37:1;
    vuint32_t INT36:1;
    vuint32_t INT35:1;
    vuint32_t INT34:1;
    vuint32_t INT33:1;
    vuint32_t INT32:1;
  } B;
} eDMA_INTH_tag;

typedef union eDMA_INTL_union_tag {    /* Interrupt Request Register Low */
  vuint32_t R;
  struct {
    vuint32_t INT31:1;
    vuint32_t INT30:1;
    vuint32_t INT29:1;
    vuint32_t INT28:1;
    vuint32_t INT27:1;
    vuint32_t INT26:1;
    vuint32_t INT25:1;
    vuint32_t INT24:1;
    vuint32_t INT23:1;
    vuint32_t INT22:1;
    vuint32_t INT21:1;
    vuint32_t INT20:1;
    vuint32_t INT19:1;
    vuint32_t INT18:1;
    vuint32_t INT17:1;
    vuint32_t INT16:1;
    vuint32_t INT15:1;
    vuint32_t INT14:1;
    vuint32_t INT13:1;
    vuint32_t INT12:1;
    vuint32_t INT11:1;
    vuint32_t INT10:1;
    vuint32_t INT9:1;
    vuint32_t INT8:1;
    vuint32_t INT7:1;
    vuint32_t INT6:1;
    vuint32_t INT5:1;
    vuint32_t INT4:1;
    vuint32_t INT3:1;
    vuint32_t INT2:1;
    vuint32_t INT1:1;
    vuint32_t INT0:1;
  } B;
} eDMA_INTL_tag;

typedef union eDMA_ERRH_union_tag {    /* Error Register High */
  vuint32_t R;
  struct {
    vuint32_t ERR63:1;
    vuint32_t ERR62:1;
    vuint32_t ERR61:1;
    vuint32_t ERR60:1;
    vuint32_t ERR59:1;
    vuint32_t ERR58:1;
    vuint32_t ERR57:1;
    vuint32_t ERR56:1;
    vuint32_t ERR55:1;
    vuint32_t ERR54:1;
    vuint32_t ERR53:1;
    vuint32_t ERR52:1;
    vuint32_t ERR51:1;
    vuint32_t ERR50:1;
    vuint32_t ERR49:1;
    vuint32_t ERR48:1;
    vuint32_t ERR47:1;
    vuint32_t ERR46:1;
    vuint32_t ERR45:1;
    vuint32_t ERR44:1;
    vuint32_t ERR43:1;
    vuint32_t ERR42:1;
    vuint32_t ERR41:1;
    vuint32_t ERR40:1;
    vuint32_t ERR39:1;
    vuint32_t ERR38:1;
    vuint32_t ERR37:1;
    vuint32_t ERR36:1;
    vuint32_t ERR35:1;
    vuint32_t ERR34:1;
    vuint32_t ERR33:1;
    vuint32_t ERR32:1;
  } B;
} eDMA_ERRH_tag;

typedef union eDMA_ERRL_union_tag {    /* Error Register Low */
  vuint32_t R;
  struct {
    vuint32_t ERR31:1;
    vuint32_t ERR30:1;
    vuint32_t ERR29:1;
    vuint32_t ERR28:1;
    vuint32_t ERR27:1;
    vuint32_t ERR26:1;
    vuint32_t ERR25:1;
    vuint32_t ERR24:1;
    vuint32_t ERR23:1;
    vuint32_t ERR22:1;
    vuint32_t ERR21:1;
    vuint32_t ERR20:1;
    vuint32_t ERR19:1;
    vuint32_t ERR18:1;
    vuint32_t ERR17:1;
    vuint32_t ERR16:1;
    vuint32_t ERR15:1;
    vuint32_t ERR14:1;
    vuint32_t ERR13:1;
    vuint32_t ERR12:1;
    vuint32_t ERR11:1;
    vuint32_t ERR10:1;
    vuint32_t ERR9:1;
    vuint32_t ERR8:1;
    vuint32_t ERR7:1;
    vuint32_t ERR6:1;
    vuint32_t ERR5:1;
    vuint32_t ERR4:1;
    vuint32_t ERR3:1;
    vuint32_t ERR2:1;
    vuint32_t ERR1:1;
    vuint32_t ERR0:1;
  } B;
} eDMA_ERRL_tag;

typedef union eDMA_HRSH_union_tag {    /* Hardware Request Status Register High */
  vuint32_t R;
  struct {
    vuint32_t HRS63:1;
    vuint32_t HRS62:1;
    vuint32_t HRS61:1;
    vuint32_t HRS60:1;
    vuint32_t HRS59:1;
    vuint32_t HRS58:1;
    vuint32_t HRS57:1;
    vuint32_t HRS56:1;
    vuint32_t HRS55:1;
    vuint32_t HRS54:1;
    vuint32_t HRS53:1;
    vuint32_t HRS52:1;
    vuint32_t HRS51:1;
    vuint32_t HRS50:1;
    vuint32_t HRS49:1;
    vuint32_t HRS48:1;
    vuint32_t HRS47:1;
    vuint32_t HRS46:1;
    vuint32_t HRS45:1;
    vuint32_t HRS44:1;
    vuint32_t HRS43:1;
    vuint32_t HRS42:1;
    vuint32_t HRS41:1;
    vuint32_t HRS40:1;
    vuint32_t HRS39:1;
    vuint32_t HRS38:1;
    vuint32_t HRS37:1;
    vuint32_t HRS36:1;
    vuint32_t HRS35:1;
    vuint32_t HRS34:1;
    vuint32_t HRS33:1;
    vuint32_t HRS32:1;
  } B;
} eDMA_HRSH_tag;

typedef union eDMA_HRSL_union_tag {    /* Hardware Request Status Register Low */
  vuint32_t R;
  struct {
    vuint32_t HRS31:1;
    vuint32_t HRS30:1;
    vuint32_t HRS29:1;
    vuint32_t HRS28:1;
    vuint32_t HRS27:1;
    vuint32_t HRS26:1;
    vuint32_t HRS25:1;
    vuint32_t HRS24:1;
    vuint32_t HRS23:1;
    vuint32_t HRS22:1;
    vuint32_t HRS21:1;
    vuint32_t HRS20:1;
    vuint32_t HRS19:1;
    vuint32_t HRS18:1;
    vuint32_t HRS17:1;
    vuint32_t HRS16:1;
    vuint32_t HRS15:1;
    vuint32_t HRS14:1;
    vuint32_t HRS13:1;
    vuint32_t HRS12:1;
    vuint32_t HRS11:1;
    vuint32_t HRS10:1;
    vuint32_t HRS9:1;
    vuint32_t HRS8:1;
    vuint32_t HRS7:1;
    vuint32_t HRS6:1;
    vuint32_t HRS5:1;
    vuint32_t HRS4:1;
    vuint32_t HRS3:1;
    vuint32_t HRS2:1;
    vuint32_t HRS1:1;
    vuint32_t HRS0:1;
  } B;
} eDMA_HRSL_tag;

typedef union eDMA_DCHPRI_union_tag {  /* Channel Priority Register */
  vuint8_t R;
  struct {
    vuint8_t ECP:1;
    vuint8_t DPA:1;
    vuint8_t GRPPRI:2;
    vuint8_t CHPRI:4;
  } B;
} eDMA_DCHPRI_tag;

typedef union eDMA_DCHMID_union_tag {  /* Channel Master ID Register */
  vuint8_t R;
  struct {
    vuint8_t EMI:1;
    vuint8_t PAL:1;
    vuint8_t  :2;
    vuint8_t MID:4;
  } B;
} eDMA_DCHMID_tag;

typedef union eDMA_TCD_SADDR_union_tag { /* TCD Source Address */
  vuint32_t R;
  struct {
    vuint32_t SADDR:32;
  } B;
} eDMA_TCD_SADDR_tag;

typedef union eDMA_TCD_ATTR_union_tag { /* TCD Transfer Attributes */
  vuint16_t R;
  struct {
    vuint16_t SMOD:5;
    vuint16_t SSIZE:3;
    vuint16_t DMOD:5;
    vuint16_t DSIZE:3;
  } B;
} eDMA_TCD_ATTR_tag;

typedef union eDMA_TCD_SOFF_union_tag { /* TCD Signed Source Address Offset */
  vuint16_t R;
  struct {
    vuint16_t SOFF:16;
  } B;
} eDMA_TCD_SOFF_tag;

typedef union eDMA_TCD_NBYTES_MLNO_union_tag { /* TCD Minor Byte Count Minor Loop Disabled */
  vuint32_t R;
  struct {
    vuint32_t NBYTES:32;
  } B;
} eDMA_TCD_NBYTES_MLNO_tag;

typedef union eDMA_TCD_NBYTES_MLOFFNO_union_tag { /* TCD Signed Minor Loop Offset Minor Loop Enabled and Offset Disabled */
  vuint32_t R;
  struct {
    vuint32_t SMLOE:1;
    vuint32_t DMLOE:1;
    vuint32_t NBYTES:30;
  } B;
} eDMA_TCD_NBYTES_MLOFFNO_tag;

typedef union eDMA_TCD_NBYTES_MLOFFYES_union_tag { /* TCD Signed Minor Loop Offset Minor Loop and Offset Enabled */
  vuint32_t R;
  struct {
    vuint32_t SMLOE:1;
    vuint32_t DMLOE:1;
    vuint32_t MLOFF:20;
    vuint32_t NBYTES:10;
  } B;
} eDMA_TCD_NBYTES_MLOFFYES_tag;

typedef union eDMA_TCD_NBYTES_union_tag {
  eDMA_TCD_NBYTES_MLNO_tag MLNO;       /* TCD Minor Byte Count Minor Loop Disabled */
  eDMA_TCD_NBYTES_MLOFFNO_tag MLOFFNO; /* TCD Signed Minor Loop Offset Minor Loop Enabled and Offset Disabled */
  eDMA_TCD_NBYTES_MLOFFYES_tag MLOFFYES; /* TCD Signed Minor Loop Offset Minor Loop and Offset Enabled */
} eDMA_TCD_NBYTES_tag;

typedef union eDMA_TCD_SLAST_union_tag { /* TCD Last Source Address Adjustment */
  vuint32_t R;
  struct {
    vuint32_t SLAST:32;
  } B;
} eDMA_TCD_SLAST_tag;

typedef union eDMA_TCD_DADDR_union_tag { /* TCD Destination Address */
  vuint32_t R;
  struct {
    vuint32_t DADDR:32;
  } B;
} eDMA_TCD_DADDR_tag;

typedef union eDMA_TCD_CITER_ELINKNO_union_tag { /* TCD Current Minor Loop Link, Major Loop Count Channel Linking Disabled */
  vuint16_t R;
  struct {
    vuint16_t ELINK:1;
    vuint16_t CITER:15;
  } B;
} eDMA_TCD_CITER_ELINKNO_tag;

typedef union eDMA_TCD_CITER_ELINKYES_union_tag { /* TCD Current Minor Loop Link, Major Loop Count Channel Linking Enabled */
  vuint16_t R;
  struct {
    vuint16_t ELINK:1;
    vuint16_t LINKCH:6;
    vuint16_t CITER:9;
  } B;
} eDMA_TCD_CITER_ELINKYES_tag;

typedef union eDMA_TCD_CITER_union_tag {
  eDMA_TCD_CITER_ELINKNO_tag ELINKNO;  /* TCD Current Minor Loop Link, Major Loop Count Channel Linking Disabled */
  eDMA_TCD_CITER_ELINKYES_tag ELINKYES; /* TCD Current Minor Loop Link, Major Loop Count Channel Linking Enabled */
} eDMA_TCD_CITER_tag;

typedef union eDMA_TCD_DOFF_union_tag { /* TCD Signed Destination Address Offset */
  vuint16_t R;
  struct {
    vuint16_t DOFF:16;
  } B;
} eDMA_TCD_DOFF_tag;

typedef union eDMA_TCD_DLASTSGA_union_tag { /* TCD Last Destination Address Adjustment/Scatter Gather Address */
  vuint32_t R;
  struct {
    vuint32_t DLASTSGA:32;
  } B;
} eDMA_TCD_DLASTSGA_tag;

typedef union eDMA_TCD_BITER_ELINKNO_union_tag { /* TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Disabled */
  vuint16_t R;
  struct {
    vuint16_t ELINK:1;
    vuint16_t BITER:15;
  } B;
} eDMA_TCD_BITER_ELINKNO_tag;

typedef union eDMA_TCD_BITER_ELINKYES_union_tag { /* TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Enabled */
  vuint16_t R;
  struct {
    vuint16_t ELINK:1;
    vuint16_t LINKCH:6;
    vuint16_t BITER:9;
  } B;
} eDMA_TCD_BITER_ELINKYES_tag;

typedef union eDMA_TCD_BITER_union_tag {
  eDMA_TCD_BITER_ELINKNO_tag ELINKNO;  /* TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Disabled */
  eDMA_TCD_BITER_ELINKYES_tag ELINKYES; /* TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Enabled */
} eDMA_TCD_BITER_tag;

typedef union eDMA_TCD_CSR_union_tag { /* TCD Control and Status */
  vuint16_t R;
  struct {
    vuint16_t BWC:2;
    vuint16_t MAJORLINKCH:6;
    vuint16_t DONE:1;
    vuint16_t ACTIVE:1;
    vuint16_t MAJORELINK:1;
    vuint16_t ESG:1;
    vuint16_t DREQ:1;
    vuint16_t INTHALF:1;
    vuint16_t INTMAJOR:1;
    vuint16_t START:1;
  } B;
} eDMA_TCD_CSR_tag;

typedef struct eDMA_TCD_struct_tag {
  eDMA_TCD_SADDR_tag SADDR;            /* TCD Source Address */
  eDMA_TCD_ATTR_tag ATTR;              /* TCD Transfer Attributes */
  eDMA_TCD_SOFF_tag SOFF;              /* TCD Signed Source Address Offset */
  eDMA_TCD_NBYTES_tag NBYTES;
  eDMA_TCD_SLAST_tag SLAST;            /* TCD Last Source Address Adjustment */
  eDMA_TCD_DADDR_tag DADDR;            /* TCD Destination Address */
  eDMA_TCD_CITER_tag CITER;
  eDMA_TCD_DOFF_tag DOFF;              /* TCD Signed Destination Address Offset */
  eDMA_TCD_DLASTSGA_tag DLASTSGA;      /* TCD Last Destination Address Adjustment/Scatter Gather Address */
  eDMA_TCD_BITER_tag BITER;
  eDMA_TCD_CSR_tag CSR;                /* TCD Control and Status */
} eDMA_TCD_tag;

struct eDMA_tag {
  eDMA_CR_tag CR;                      /* Control Register */
  eDMA_ES_tag ES;                      /* Error Status */
  eDMA_ERQH_tag ERQH;                  /* Enable Request Register High */
  eDMA_ERQL_tag ERQL;                  /* Enable Request Register Low */
  eDMA_EEIH_tag EEIH;                  /* Enable Error Interrupt Register High */
  eDMA_EEIL_tag EEIL;                  /* Enable Error Interrupt Register Low */
  eDMA_SERQ_tag SERQ;                  /* Set Enable Request Register */
  eDMA_CERQ_tag CERQ;                  /* Clear Enable Request Register */
  eDMA_SEEI_tag SEEI;                  /* Set Enable Error Interrupt Register */
  eDMA_CEEI_tag CEEI;                  /* Clear Enable Error Interrupt Register */
  eDMA_CINT_tag CINT;                  /* Clear Interrupt Request Register */
  eDMA_CERR_tag CERR;                  /* Clear Error Register */
  eDMA_SSRT_tag SSRT;                  /* Set START Bit Register */
  eDMA_CDNE_tag CDNE;                  /* Clear DONE Status Bit Register */
  eDMA_INTH_tag INTH;                  /* Interrupt Request Register High */
  eDMA_INTL_tag INTL;                  /* Interrupt Request Register Low */
  eDMA_ERRH_tag ERRH;                  /* Error Register High */
  eDMA_ERRL_tag ERRL;                  /* Error Register Low */
  eDMA_HRSH_tag HRSH;                  /* Hardware Request Status Register High */
  eDMA_HRSL_tag HRSL;                  /* Hardware Request Status Register Low */
  uint8_t eDMA_reserved0[200];
  eDMA_DCHPRI_tag DCHPRI[64];          /* Channel Priority Register */
  eDMA_DCHMID_tag DCHMID[64];          /* Channel Master ID Register */
  uint8_t eDMA_reserved1[3712];
  eDMA_TCD_tag TCD[64];
};

/*----------------------------------------------------------------------------
 -- DMA  Masks
 ---------------------------------------------------------------------------- */

#define DMA_CR_EDBG_MASK                        0x2UL
#define DMA_CR_EDBG_SHIFT                       1u
#define DMA_CR_EDBG_WIDTH                       1u
#define DMA_CR_EDBG(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_EDBG_SHIFT)) \
                                                    &DMA_CR_EDBG_MASK)
#define DMA_CR_ERCA_MASK                        0x4UL
#define DMA_CR_ERCA_SHIFT                       2u
#define DMA_CR_ERCA_WIDTH                       1u
#define DMA_CR_ERCA(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_ERCA_SHIFT)) \
                                                  &DMA_CR_ERCA_MASK)
#define DMA_CR_ERGA_MASK                        0x8UL
#define DMA_CR_ERGA_SHIFT                       3u
#define DMA_CR_ERGA_WIDTH                       1u
#define DMA_CR_ERGA(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_ERGA_SHIFT)) \
                                                  &DMA_CR_ERGA_MASK)
#define DMA_CR_HOE_MASK                         0x10UL
#define DMA_CR_HOE_SHIFT                        4u
#define DMA_CR_HOE_WIDTH                        1u
#define DMA_CR_HOE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_HOE_SHIFT)) \
                                                  &DMA_CR_HOE_MASK)
#define DMA_CR_HALT_MASK                        0x20u
#define DMA_CR_HALT_SHIFT                       5u
#define DMA_CR_HALT_WIDTH                       1u
#define DMA_CR_HALT(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_HALT_SHIFT)) \
                                                  &DMA_CR_HALT_MASK)
#define DMA_CR_CLM_MASK                         0x40UL
#define DMA_CR_CLM_SHIFT                        6u
#define DMA_CR_CLM_WIDTH                        1u
#define DMA_CR_CLM(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_CLM_SHIFT)) \
                                                  &DMA_CR_CLM_MASK)
#define DMA_CR_EMLM_MASK                        0x80UL
#define DMA_CR_EMLM_SHIFT                       7u
#define DMA_CR_EMLM_WIDTH                       1u
#define DMA_CR_EMLM(x)                          (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_EMLM_SHIFT)) \
                                                  &DMA_CR_EMLM_MASK)
#define DMA_CR_GRP0PRI_MASK                     0x300u
#define DMA_CR_GRP0PRI_SHIFT                    8u
#define DMA_CR_GRP0PRI_WIDTH                    2u
#define DMA_CR_GRP0PRI(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_GRP0PRI_SHIFT)) \
                                                  &DMA_CR_GRP0PRI_MASK)
#define DMA_CR_GRP1PRI_MASK                     0xC00u
#define DMA_CR_GRP1PRI_SHIFT                    10u
#define DMA_CR_GRP1PRI_WIDTH                    2u
#define DMA_CR_GRP1PRI(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_GRP1PRI_SHIFT)) \
                                                  &DMA_CR_GRP1PRI_MASK)
#define DMA_CR_GRP2PRI_MASK                     0x3000u
#define DMA_CR_GRP2PRI_SHIFT                    12u
#define DMA_CR_GRP2PRI_WIDTH                    2u
#define DMA_CR_GRP2PRI(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_GRP2PRI_SHIFT)) \
                                                  &DMA_CR_GRP2PRI_MASK)
#define DMA_CR_GRP3PRI_MASK                     0xC000u
#define DMA_CR_GRP3PRI_SHIFT                    14u
#define DMA_CR_GRP3PRI_WIDTH                    2u
#define DMA_CR_GRP3PRI(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_GRP3PRI_SHIFT)) \
                                                  &DMA_CR_GRP3PRI_MASK)
#define DMA_CR_ECX_MASK                         0x10000UL
#define DMA_CR_ECX_SHIFT                        16u
#define DMA_CR_ECX_WIDTH                        1u
#define DMA_CR_ECX(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_ECX_SHIFT)) \
                                                  &DMA_CR_ECX_MASK)
#define DMA_CR_CX_MASK                          0x20000UL
#define DMA_CR_CX_SHIFT                         17u
#define DMA_CR_CX_WIDTH                         1u
#define DMA_CR_CX(x)                            (((uint32)(((uint32)(x)) \
                                                  << DMA_CR_CX_SHIFT)) \
                                                  &DMA_CR_CX_MASK)
/* ES Bit Fields */
#define DMA_ES_DBE_MASK                         0x1u
#define DMA_ES_DBE_SHIFT                        0u
#define DMA_ES_DBE_WIDTH                        1u
#define DMA_ES_DBE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_DBE_SHIFT)) \
                                                  &DMA_ES_DBE_MASK)
#define DMA_ES_SBE_MASK                         0x2u
#define DMA_ES_SBE_SHIFT                        1u
#define DMA_ES_SBE_WIDTH                        1u
#define DMA_ES_SBE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_SBE_SHIFT)) \
                                                  &DMA_ES_SBE_MASK)
#define DMA_ES_SGE_MASK                         0x4u
#define DMA_ES_SGE_SHIFT                        2u
#define DMA_ES_SGE_WIDTH                        1u
#define DMA_ES_SGE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_SGE_SHIFT)) \
                                                  &DMA_ES_SGE_MASK)
#define DMA_ES_NCE_MASK                         0x8u
#define DMA_ES_NCE_SHIFT                        3u
#define DMA_ES_NCE_WIDTH                        1u
#define DMA_ES_NCE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_NCE_SHIFT)) \
                                                  &DMA_ES_NCE_MASK)
#define DMA_ES_DOE_MASK                         0x10u
#define DMA_ES_DOE_SHIFT                        4u
#define DMA_ES_DOE_WIDTH                        1u
#define DMA_ES_DOE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_DOE_SHIFT)) \
                                                  &DMA_ES_DOE_MASK)
#define DMA_ES_DAE_MASK                         0x20u
#define DMA_ES_DAE_SHIFT                        5u
#define DMA_ES_DAE_WIDTH                        1u
#define DMA_ES_DAE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_DAE_SHIFT)) \
                                                  &DMA_ES_DAE_MASK)
#define DMA_ES_SOE_MASK                         0x40u
#define DMA_ES_SOE_SHIFT                        6u
#define DMA_ES_SOE_WIDTH                        1u
#define DMA_ES_SOE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_SOE_SHIFT)) \
                                                  &DMA_ES_SOE_MASK)
#define DMA_ES_SAE_MASK                         0x80u
#define DMA_ES_SAE_SHIFT                        7u
#define DMA_ES_SAE_WIDTH                        1u
#define DMA_ES_SAE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_SAE_SHIFT)) \
                                                  &DMA_ES_SAE_MASK)
#define DMA_ES_ERRCHN_MASK                      0x3F00u
#define DMA_ES_ERRCHN_SHIFT                     8u
#define DMA_ES_ERRCHN_WIDTH                     6u
#define DMA_ES_ERRCHN(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_ERRCHN_SHIFT)) \
                                                  &DMA_ES_ERRCHN_MASK)
#define DMA_ES_CPE_MASK                         0x4000u
#define DMA_ES_CPE_SHIFT                        14u
#define DMA_ES_CPE_WIDTH                        1u
#define DMA_ES_CPE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_CPE_SHIFT)) \
                                                  &DMA_ES_CPE_MASK)
#define DMA_ES_GPE_MASK                         0x8000u
#define DMA_ES_GPE_SHIFT                        15u
#define DMA_ES_GPE_WIDTH                        1u
#define DMA_ES_GPE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_GPE_SHIFT)) \
                                                  &DMA_ES_GPE_MASK)
#define DMA_ES_ECX_MASK                         0x10000u
#define DMA_ES_ECX_SHIFT                        16u
#define DMA_ES_ECX_WIDTH                        1u
#define DMA_ES_ECX(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_ECX_SHIFT)) \
                                                  &DMA_ES_ECX_MASK)
#define DMA_ES_UCE_MASK                         0x20000u
#define DMA_ES_UCE_SHIFT                        17u
#define DMA_ES_UCE_WIDTH                        1u
#define DMA_ES_UCE(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_UCE_SHIFT)) \
                                                  &DMA_ES_UCE_MASK)
#define DMA_ES_VLD_MASK                         0x80000000u
#define DMA_ES_VLD_SHIFT                        31u
#define DMA_ES_VLD_WIDTH                        1u
#define DMA_ES_VLD(x)                           (((uint32)(((uint32)(x)) \
                                                  << DMA_ES_VLD_SHIFT)) \
                                                  &DMA_ES_VLD_MASK)
/* ERQH Bit Fields */
#define DMA_ERQH_ERQ32_MASK                     0x1u
#define DMA_ERQH_ERQ32_SHIFT                    0u
#define DMA_ERQH_ERQ32_WIDTH                    1u
#define DMA_ERQH_ERQ32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ32_SHIFT)) \
                                                  &DMA_ERQH_ERQ32_MASK)
#define DMA_ERQH_ERQ33_MASK                     0x2u
#define DMA_ERQH_ERQ33_SHIFT                    1u
#define DMA_ERQH_ERQ33_WIDTH                    1u
#define DMA_ERQH_ERQ33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ33_SHIFT)) \
                                                  &DMA_ERQH_ERQ33_MASK)
#define DMA_ERQH_ERQ34_MASK                     0x4u
#define DMA_ERQH_ERQ34_SHIFT                    2u
#define DMA_ERQH_ERQ34_WIDTH                    1u
#define DMA_ERQH_ERQ34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ34_SHIFT)) \
                                                  &DMA_ERQH_ERQ34_MASK)
#define DMA_ERQH_ERQ35_MASK                     0x8u
#define DMA_ERQH_ERQ35_SHIFT                    3u
#define DMA_ERQH_ERQ35_WIDTH                    1u
#define DMA_ERQH_ERQ35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ35_SHIFT)) \
                                                  &DMA_ERQH_ERQ35_MASK)
#define DMA_ERQH_ERQ36_MASK                     0x10u
#define DMA_ERQH_ERQ36_SHIFT                    4u
#define DMA_ERQH_ERQ36_WIDTH                    1u
#define DMA_ERQH_ERQ36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ36_SHIFT)) \
                                                  &DMA_ERQH_ERQ36_MASK)
#define DMA_ERQH_ERQ37_MASK                     0x20u
#define DMA_ERQH_ERQ37_SHIFT                    5u
#define DMA_ERQH_ERQ37_WIDTH                    1u
#define DMA_ERQH_ERQ37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ37_SHIFT)) \
                                                  &DMA_ERQH_ERQ37_MASK)
#define DMA_ERQH_ERQ38_MASK                     0x40u
#define DMA_ERQH_ERQ38_SHIFT                    6u
#define DMA_ERQH_ERQ38_WIDTH                    1u
#define DMA_ERQH_ERQ38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ38_SHIFT)) \
                                                  &DMA_ERQH_ERQ38_MASK)
#define DMA_ERQH_ERQ39_MASK                     0x80u
#define DMA_ERQH_ERQ39_SHIFT                    7u
#define DMA_ERQH_ERQ39_WIDTH                    1u
#define DMA_ERQH_ERQ39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ39_SHIFT)) \
                                                  &DMA_ERQH_ERQ39_MASK)
#define DMA_ERQH_ERQ40_MASK                     0x100u
#define DMA_ERQH_ERQ40_SHIFT                    8u
#define DMA_ERQH_ERQ40_WIDTH                    1u
#define DMA_ERQH_ERQ40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ40_SHIFT)) \
                                                  &DMA_ERQH_ERQ40_MASK)
#define DMA_ERQH_ERQ41_MASK                     0x200u
#define DMA_ERQH_ERQ41_SHIFT                    9u
#define DMA_ERQH_ERQ41_WIDTH                    1u
#define DMA_ERQH_ERQ41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ41_SHIFT)) \
                                                  &DMA_ERQH_ERQ41_MASK)
#define DMA_ERQH_ERQ42_MASK                     0x400u
#define DMA_ERQH_ERQ42_SHIFT                    10u
#define DMA_ERQH_ERQ42_WIDTH                    1u
#define DMA_ERQH_ERQ42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ42_SHIFT)) \
                                                  &DMA_ERQH_ERQ42_MASK)
#define DMA_ERQH_ERQ43_MASK                     0x800u
#define DMA_ERQH_ERQ43_SHIFT                    11u
#define DMA_ERQH_ERQ43_WIDTH                    1u
#define DMA_ERQH_ERQ43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ43_SHIFT)) \
                                                  &DMA_ERQH_ERQ43_MASK)
#define DMA_ERQH_ERQ44_MASK                     0x1000u
#define DMA_ERQH_ERQ44_SHIFT                    12u
#define DMA_ERQH_ERQ44_WIDTH                    1u
#define DMA_ERQH_ERQ44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ44_SHIFT)) \
                                                  &DMA_ERQH_ERQ44_MASK)
#define DMA_ERQH_ERQ45_MASK                     0x2000u
#define DMA_ERQH_ERQ45_SHIFT                    13u
#define DMA_ERQH_ERQ45_WIDTH                    1u
#define DMA_ERQH_ERQ45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ45_SHIFT)) \
                                                  &DMA_ERQH_ERQ45_MASK)
#define DMA_ERQH_ERQ46_MASK                     0x4000u
#define DMA_ERQH_ERQ46_SHIFT                    14u
#define DMA_ERQH_ERQ46_WIDTH                    1u
#define DMA_ERQH_ERQ46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ46_SHIFT)) \
                                                  &DMA_ERQH_ERQ46_MASK)
#define DMA_ERQH_ERQ47_MASK                     0x8000u
#define DMA_ERQH_ERQ47_SHIFT                    15u
#define DMA_ERQH_ERQ47_WIDTH                    1u
#define DMA_ERQH_ERQ47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ47_SHIFT)) \
                                                  &DMA_ERQH_ERQ47_MASK)
#define DMA_ERQH_ERQ48_MASK                     0x10000u
#define DMA_ERQH_ERQ48_SHIFT                    16u
#define DMA_ERQH_ERQ48_WIDTH                    1u
#define DMA_ERQH_ERQ48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ48_SHIFT)) \
                                                  &DMA_ERQH_ERQ48_MASK)
#define DMA_ERQH_ERQ49_MASK                     0x20000u
#define DMA_ERQH_ERQ49_SHIFT                    17u
#define DMA_ERQH_ERQ49_WIDTH                    1u
#define DMA_ERQH_ERQ49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ49_SHIFT)) \
                                                  &DMA_ERQH_ERQ49_MASK)
#define DMA_ERQH_ERQ50_MASK                     0x40000u
#define DMA_ERQH_ERQ50_SHIFT                    18u
#define DMA_ERQH_ERQ50_WIDTH                    1u
#define DMA_ERQH_ERQ50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ50_SHIFT)) \
                                                  &DMA_ERQH_ERQ50_MASK)
#define DMA_ERQH_ERQ51_MASK                     0x80000u
#define DMA_ERQH_ERQ51_SHIFT                    19u
#define DMA_ERQH_ERQ51_WIDTH                    1u
#define DMA_ERQH_ERQ51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ51_SHIFT)) \
                                                  &DMA_ERQH_ERQ51_MASK)
#define DMA_ERQH_ERQ52_MASK                     0x100000u
#define DMA_ERQH_ERQ52_SHIFT                    20u
#define DMA_ERQH_ERQ52_WIDTH                    1u
#define DMA_ERQH_ERQ52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ52_SHIFT)) \
                                                  &DMA_ERQH_ERQ52_MASK)
#define DMA_ERQH_ERQ53_MASK                     0x200000u
#define DMA_ERQH_ERQ53_SHIFT                    21u
#define DMA_ERQH_ERQ53_WIDTH                    1u
#define DMA_ERQH_ERQ53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ53_SHIFT)) \
                                                  &DMA_ERQH_ERQ53_MASK)
#define DMA_ERQH_ERQ54_MASK                     0x400000u
#define DMA_ERQH_ERQ54_SHIFT                    22u
#define DMA_ERQH_ERQ54_WIDTH                    1u
#define DMA_ERQH_ERQ54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ54_SHIFT)) \
                                                  &DMA_ERQH_ERQ54_MASK)
#define DMA_ERQH_ERQ55_MASK                     0x800000u
#define DMA_ERQH_ERQ55_SHIFT                    23u
#define DMA_ERQH_ERQ55_WIDTH                    1u
#define DMA_ERQH_ERQ55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ55_SHIFT)) \
                                                  &DMA_ERQH_ERQ55_MASK)
#define DMA_ERQH_ERQ56_MASK                     0x1000000u
#define DMA_ERQH_ERQ56_SHIFT                    24u
#define DMA_ERQH_ERQ56_WIDTH                    1u
#define DMA_ERQH_ERQ56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ56_SHIFT)) \
                                                  &DMA_ERQH_ERQ56_MASK)
#define DMA_ERQH_ERQ57_MASK                     0x2000000u
#define DMA_ERQH_ERQ57_SHIFT                    25u
#define DMA_ERQH_ERQ57_WIDTH                    1u
#define DMA_ERQH_ERQ57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ57_SHIFT)) \
                                                  &DMA_ERQH_ERQ57_MASK)
#define DMA_ERQH_ERQ58_MASK                     0x4000000u
#define DMA_ERQH_ERQ58_SHIFT                    26u
#define DMA_ERQH_ERQ58_WIDTH                    1u
#define DMA_ERQH_ERQ58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ58_SHIFT)) \
                                                  &DMA_ERQH_ERQ58_MASK)
#define DMA_ERQH_ERQ59_MASK                     0x8000000u
#define DMA_ERQH_ERQ59_SHIFT                    27u
#define DMA_ERQH_ERQ59_WIDTH                    1u
#define DMA_ERQH_ERQ59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ59_SHIFT)) \
                                                  &DMA_ERQH_ERQ59_MASK)
#define DMA_ERQH_ERQ60_MASK                     0x10000000u
#define DMA_ERQH_ERQ60_SHIFT                    28u
#define DMA_ERQH_ERQ60_WIDTH                    1u
#define DMA_ERQH_ERQ60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ60_SHIFT)) \
                                                  &DMA_ERQH_ERQ60_MASK)
#define DMA_ERQH_ERQ61_MASK                     0x20000000u
#define DMA_ERQH_ERQ61_SHIFT                    29u
#define DMA_ERQH_ERQ61_WIDTH                    1u
#define DMA_ERQH_ERQ61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ61_SHIFT)) \
                                                  &DMA_ERQH_ERQ61_MASK)
#define DMA_ERQH_ERQ62_MASK                     0x40000000u
#define DMA_ERQH_ERQ62_SHIFT                    30u
#define DMA_ERQH_ERQ62_WIDTH                    1u
#define DMA_ERQH_ERQ62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ62_SHIFT)) \
                                                  &DMA_ERQH_ERQ62_MASK)
#define DMA_ERQH_ERQ63_MASK                     0x80000000u
#define DMA_ERQH_ERQ63_SHIFT                    31u
#define DMA_ERQH_ERQ63_WIDTH                    1u
#define DMA_ERQH_ERQ63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQH_ERQ63_SHIFT)) \
                                                  &DMA_ERQH_ERQ63_MASK)
/* ERQL Bit Fields */
#define DMA_ERQL_ERQ0_MASK                      0x1u
#define DMA_ERQL_ERQ0_SHIFT                     0u
#define DMA_ERQL_ERQ0_WIDTH                     1u
#define DMA_ERQL_ERQ0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ0_SHIFT)) \
                                                  &DMA_ERQL_ERQ0_MASK)
#define DMA_ERQL_ERQ1_MASK                      0x2u
#define DMA_ERQL_ERQ1_SHIFT                     1u
#define DMA_ERQL_ERQ1_WIDTH                     1u
#define DMA_ERQL_ERQ1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ1_SHIFT)) \
                                                  &DMA_ERQL_ERQ1_MASK)
#define DMA_ERQL_ERQ2_MASK                      0x4u
#define DMA_ERQL_ERQ2_SHIFT                     2u
#define DMA_ERQL_ERQ2_WIDTH                     1u
#define DMA_ERQL_ERQ2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ2_SHIFT)) \
                                                  &DMA_ERQL_ERQ2_MASK)
#define DMA_ERQL_ERQ3_MASK                      0x8u
#define DMA_ERQL_ERQ3_SHIFT                     3u
#define DMA_ERQL_ERQ3_WIDTH                     1u
#define DMA_ERQL_ERQ3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ3_SHIFT)) \
                                                  &DMA_ERQL_ERQ3_MASK)
#define DMA_ERQL_ERQ4_MASK                      0x10u
#define DMA_ERQL_ERQ4_SHIFT                     4u
#define DMA_ERQL_ERQ4_WIDTH                     1u
#define DMA_ERQL_ERQ4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ4_SHIFT)) \
                                                  &DMA_ERQL_ERQ4_MASK)
#define DMA_ERQL_ERQ5_MASK                      0x20u
#define DMA_ERQL_ERQ5_SHIFT                     5u
#define DMA_ERQL_ERQ5_WIDTH                     1u
#define DMA_ERQL_ERQ5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ5_SHIFT)) \
                                                  &DMA_ERQL_ERQ5_MASK)
#define DMA_ERQL_ERQ6_MASK                      0x40u
#define DMA_ERQL_ERQ6_SHIFT                     6u
#define DMA_ERQL_ERQ6_WIDTH                     1u
#define DMA_ERQL_ERQ6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ6_SHIFT)) \
                                                  &DMA_ERQL_ERQ6_MASK)
#define DMA_ERQL_ERQ7_MASK                      0x80u
#define DMA_ERQL_ERQ7_SHIFT                     7u
#define DMA_ERQL_ERQ7_WIDTH                     1u
#define DMA_ERQL_ERQ7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ7_SHIFT)) \
                                                  &DMA_ERQL_ERQ7_MASK)
#define DMA_ERQL_ERQ8_MASK                      0x100u
#define DMA_ERQL_ERQ8_SHIFT                     8u
#define DMA_ERQL_ERQ8_WIDTH                     1u
#define DMA_ERQL_ERQ8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ8_SHIFT)) \
                                                  &DMA_ERQL_ERQ8_MASK)
#define DMA_ERQL_ERQ9_MASK                      0x200u
#define DMA_ERQL_ERQ9_SHIFT                     9u
#define DMA_ERQL_ERQ9_WIDTH                     1u
#define DMA_ERQL_ERQ9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ9_SHIFT)) \
                                                  &DMA_ERQL_ERQ9_MASK)
#define DMA_ERQL_ERQ10_MASK                     0x400u
#define DMA_ERQL_ERQ10_SHIFT                    10u
#define DMA_ERQL_ERQ10_WIDTH                    1u
#define DMA_ERQL_ERQ10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ10_SHIFT)) \
                                                  &DMA_ERQL_ERQ10_MASK)
#define DMA_ERQL_ERQ11_MASK                     0x800u
#define DMA_ERQL_ERQ11_SHIFT                    11u
#define DMA_ERQL_ERQ11_WIDTH                    1u
#define DMA_ERQL_ERQ11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ11_SHIFT)) \
                                                  &DMA_ERQL_ERQ11_MASK)
#define DMA_ERQL_ERQ12_MASK                     0x1000u
#define DMA_ERQL_ERQ12_SHIFT                    12u
#define DMA_ERQL_ERQ12_WIDTH                    1u
#define DMA_ERQL_ERQ12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ12_SHIFT)) \
                                                  &DMA_ERQL_ERQ12_MASK)
#define DMA_ERQL_ERQ13_MASK                     0x2000u
#define DMA_ERQL_ERQ13_SHIFT                    13u
#define DMA_ERQL_ERQ13_WIDTH                    1u
#define DMA_ERQL_ERQ13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ13_SHIFT)) \
                                                  &DMA_ERQL_ERQ13_MASK)
#define DMA_ERQL_ERQ14_MASK                     0x4000u
#define DMA_ERQL_ERQ14_SHIFT                    14u
#define DMA_ERQL_ERQ14_WIDTH                    1u
#define DMA_ERQL_ERQ14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ14_SHIFT)) \
                                                  &DMA_ERQL_ERQ14_MASK)
#define DMA_ERQL_ERQ15_MASK                     0x8000u
#define DMA_ERQL_ERQ15_SHIFT                    15u
#define DMA_ERQL_ERQ15_WIDTH                    1u
#define DMA_ERQL_ERQ15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ15_SHIFT)) \
                                                  &DMA_ERQL_ERQ15_MASK)
#define DMA_ERQL_ERQ16_MASK                     0x10000u
#define DMA_ERQL_ERQ16_SHIFT                    16u
#define DMA_ERQL_ERQ16_WIDTH                    1u
#define DMA_ERQL_ERQ16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ16_SHIFT)) \
                                                  &DMA_ERQL_ERQ16_MASK)
#define DMA_ERQL_ERQ17_MASK                     0x20000u
#define DMA_ERQL_ERQ17_SHIFT                    17u
#define DMA_ERQL_ERQ17_WIDTH                    1u
#define DMA_ERQL_ERQ17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ17_SHIFT)) \
                                                  &DMA_ERQL_ERQ17_MASK)
#define DMA_ERQL_ERQ18_MASK                     0x40000u
#define DMA_ERQL_ERQ18_SHIFT                    18u
#define DMA_ERQL_ERQ18_WIDTH                    1u
#define DMA_ERQL_ERQ18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ18_SHIFT)) \
                                                  &DMA_ERQL_ERQ18_MASK)
#define DMA_ERQL_ERQ19_MASK                     0x80000u
#define DMA_ERQL_ERQ19_SHIFT                    19u
#define DMA_ERQL_ERQ19_WIDTH                    1u
#define DMA_ERQL_ERQ19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ19_SHIFT)) \
                                                  &DMA_ERQL_ERQ19_MASK)
#define DMA_ERQL_ERQ20_MASK                     0x100000u
#define DMA_ERQL_ERQ20_SHIFT                    20u
#define DMA_ERQL_ERQ20_WIDTH                    1u
#define DMA_ERQL_ERQ20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ20_SHIFT)) \
                                                  &DMA_ERQL_ERQ20_MASK)
#define DMA_ERQL_ERQ21_MASK                     0x200000u
#define DMA_ERQL_ERQ21_SHIFT                    21u
#define DMA_ERQL_ERQ21_WIDTH                    1u
#define DMA_ERQL_ERQ21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ21_SHIFT)) \
                                                  &DMA_ERQL_ERQ21_MASK)
#define DMA_ERQL_ERQ22_MASK                     0x400000u
#define DMA_ERQL_ERQ22_SHIFT                    22u
#define DMA_ERQL_ERQ22_WIDTH                    1u
#define DMA_ERQL_ERQ22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ22_SHIFT)) \
                                                  &DMA_ERQL_ERQ22_MASK)
#define DMA_ERQL_ERQ23_MASK                     0x800000u
#define DMA_ERQL_ERQ23_SHIFT                    23u
#define DMA_ERQL_ERQ23_WIDTH                    1u
#define DMA_ERQL_ERQ23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ23_SHIFT)) \
                                                  &DMA_ERQL_ERQ23_MASK)
#define DMA_ERQL_ERQ24_MASK                     0x1000000u
#define DMA_ERQL_ERQ24_SHIFT                    24u
#define DMA_ERQL_ERQ24_WIDTH                    1u
#define DMA_ERQL_ERQ24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ24_SHIFT)) \
                                                  &DMA_ERQL_ERQ24_MASK)
#define DMA_ERQL_ERQ25_MASK                     0x2000000u
#define DMA_ERQL_ERQ25_SHIFT                    25u
#define DMA_ERQL_ERQ25_WIDTH                    1u
#define DMA_ERQL_ERQ25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ25_SHIFT)) \
                                                  &DMA_ERQL_ERQ25_MASK)
#define DMA_ERQL_ERQ26_MASK                     0x4000000u
#define DMA_ERQL_ERQ26_SHIFT                    26u
#define DMA_ERQL_ERQ26_WIDTH                    1u
#define DMA_ERQL_ERQ26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ26_SHIFT)) \
                                                  &DMA_ERQL_ERQ26_MASK)
#define DMA_ERQL_ERQ27_MASK                     0x8000000u
#define DMA_ERQL_ERQ27_SHIFT                    27u
#define DMA_ERQL_ERQ27_WIDTH                    1u
#define DMA_ERQL_ERQ27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ27_SHIFT)) \
                                                  &DMA_ERQL_ERQ27_MASK)
#define DMA_ERQL_ERQ28_MASK                     0x10000000u
#define DMA_ERQL_ERQ28_SHIFT                    28u
#define DMA_ERQL_ERQ28_WIDTH                    1u
#define DMA_ERQL_ERQ28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ28_SHIFT)) \
                                                  &DMA_ERQL_ERQ28_MASK)
#define DMA_ERQL_ERQ29_MASK                     0x20000000u
#define DMA_ERQL_ERQ29_SHIFT                    29u
#define DMA_ERQL_ERQ29_WIDTH                    1u
#define DMA_ERQL_ERQ29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ29_SHIFT)) \
                                                  &DMA_ERQL_ERQ29_MASK)
#define DMA_ERQL_ERQ30_MASK                     0x40000000u
#define DMA_ERQL_ERQ30_SHIFT                    30u
#define DMA_ERQL_ERQ30_WIDTH                    1u
#define DMA_ERQL_ERQ30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ30_SHIFT)) \
                                                  &DMA_ERQL_ERQ30_MASK)
#define DMA_ERQL_ERQ31_MASK                     0x80000000u
#define DMA_ERQL_ERQ31_SHIFT                    31u
#define DMA_ERQL_ERQ31_WIDTH                    1u
#define DMA_ERQL_ERQ31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERQL_ERQ31_SHIFT)) \
                                                  &DMA_ERQL_ERQ31_MASK)
/* EEIH Bit Fields */
#define DMA_EEIH_EEI32_MASK                     0x1u
#define DMA_EEIH_EEI32_SHIFT                    0u
#define DMA_EEIH_EEI32_WIDTH                    1u
#define DMA_EEIH_EEI32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI32_SHIFT)) \
                                                  &DMA_EEIH_EEI32_MASK)
#define DMA_EEIH_EEI33_MASK                     0x2u
#define DMA_EEIH_EEI33_SHIFT                    1u
#define DMA_EEIH_EEI33_WIDTH                    1u
#define DMA_EEIH_EEI33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI33_SHIFT)) \
                                                  &DMA_EEIH_EEI33_MASK)
#define DMA_EEIH_EEI34_MASK                     0x4u
#define DMA_EEIH_EEI34_SHIFT                    2u
#define DMA_EEIH_EEI34_WIDTH                    1u
#define DMA_EEIH_EEI34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI34_SHIFT)) \
                                                  &DMA_EEIH_EEI34_MASK)
#define DMA_EEIH_EEI35_MASK                     0x8u
#define DMA_EEIH_EEI35_SHIFT                    3u
#define DMA_EEIH_EEI35_WIDTH                    1u
#define DMA_EEIH_EEI35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI35_SHIFT)) \
                                                  &DMA_EEIH_EEI35_MASK)
#define DMA_EEIH_EEI36_MASK                     0x10u
#define DMA_EEIH_EEI36_SHIFT                    4u
#define DMA_EEIH_EEI36_WIDTH                    1u
#define DMA_EEIH_EEI36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI36_SHIFT)) \
                                                  &DMA_EEIH_EEI36_MASK)
#define DMA_EEIH_EEI37_MASK                     0x20u
#define DMA_EEIH_EEI37_SHIFT                    5u
#define DMA_EEIH_EEI37_WIDTH                    1u
#define DMA_EEIH_EEI37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI37_SHIFT)) \
                                                  &DMA_EEIH_EEI37_MASK)
#define DMA_EEIH_EEI38_MASK                     0x40u
#define DMA_EEIH_EEI38_SHIFT                    6u
#define DMA_EEIH_EEI38_WIDTH                    1u
#define DMA_EEIH_EEI38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI38_SHIFT)) \
                                                  &DMA_EEIH_EEI38_MASK)
#define DMA_EEIH_EEI39_MASK                     0x80u
#define DMA_EEIH_EEI39_SHIFT                    7u
#define DMA_EEIH_EEI39_WIDTH                    1u
#define DMA_EEIH_EEI39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI39_SHIFT)) \
                                                  &DMA_EEIH_EEI39_MASK)
#define DMA_EEIH_EEI40_MASK                     0x100u
#define DMA_EEIH_EEI40_SHIFT                    8u
#define DMA_EEIH_EEI40_WIDTH                    1u
#define DMA_EEIH_EEI40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI40_SHIFT)) \
                                                  &DMA_EEIH_EEI40_MASK)
#define DMA_EEIH_EEI41_MASK                     0x200u
#define DMA_EEIH_EEI41_SHIFT                    9u
#define DMA_EEIH_EEI41_WIDTH                    1u
#define DMA_EEIH_EEI41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI41_SHIFT)) \
                                                  &DMA_EEIH_EEI41_MASK)
#define DMA_EEIH_EEI42_MASK                     0x400u
#define DMA_EEIH_EEI42_SHIFT                    10u
#define DMA_EEIH_EEI42_WIDTH                    1u
#define DMA_EEIH_EEI42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI42_SHIFT)) \
                                                  &DMA_EEIH_EEI42_MASK)
#define DMA_EEIH_EEI43_MASK                     0x800u
#define DMA_EEIH_EEI43_SHIFT                    11u
#define DMA_EEIH_EEI43_WIDTH                    1u
#define DMA_EEIH_EEI43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI43_SHIFT)) \
                                                  &DMA_EEIH_EEI43_MASK)
#define DMA_EEIH_EEI44_MASK                     0x1000u
#define DMA_EEIH_EEI44_SHIFT                    12u
#define DMA_EEIH_EEI44_WIDTH                    1u
#define DMA_EEIH_EEI44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI44_SHIFT)) \
                                                  &DMA_EEIH_EEI44_MASK)
#define DMA_EEIH_EEI45_MASK                     0x2000u
#define DMA_EEIH_EEI45_SHIFT                    13u
#define DMA_EEIH_EEI45_WIDTH                    1u
#define DMA_EEIH_EEI45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI45_SHIFT)) \
                                                  &DMA_EEIH_EEI45_MASK)
#define DMA_EEIH_EEI46_MASK                     0x4000u
#define DMA_EEIH_EEI46_SHIFT                    14u
#define DMA_EEIH_EEI46_WIDTH                    1u
#define DMA_EEIH_EEI46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI46_SHIFT)) \
                                                  &DMA_EEIH_EEI46_MASK)
#define DMA_EEIH_EEI47_MASK                     0x8000u
#define DMA_EEIH_EEI47_SHIFT                    15u
#define DMA_EEIH_EEI47_WIDTH                    1u
#define DMA_EEIH_EEI47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI47_SHIFT)) \
                                                  &DMA_EEIH_EEI47_MASK)
#define DMA_EEIH_EEI48_MASK                     0x10000u
#define DMA_EEIH_EEI48_SHIFT                    16u
#define DMA_EEIH_EEI48_WIDTH                    1u
#define DMA_EEIH_EEI48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI48_SHIFT)) \
                                                  &DMA_EEIH_EEI48_MASK)
#define DMA_EEIH_EEI49_MASK                     0x20000u
#define DMA_EEIH_EEI49_SHIFT                    17u
#define DMA_EEIH_EEI49_WIDTH                    1u
#define DMA_EEIH_EEI49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI49_SHIFT)) \
                                                  &DMA_EEIH_EEI49_MASK)
#define DMA_EEIH_EEI50_MASK                     0x40000u
#define DMA_EEIH_EEI50_SHIFT                    18u
#define DMA_EEIH_EEI50_WIDTH                    1u
#define DMA_EEIH_EEI50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI50_SHIFT)) \
                                                  &DMA_EEIH_EEI50_MASK)
#define DMA_EEIH_EEI51_MASK                     0x80000u
#define DMA_EEIH_EEI51_SHIFT                    19u
#define DMA_EEIH_EEI51_WIDTH                    1u
#define DMA_EEIH_EEI51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI51_SHIFT)) \
                                                  &DMA_EEIH_EEI51_MASK)
#define DMA_EEIH_EEI52_MASK                     0x100000u
#define DMA_EEIH_EEI52_SHIFT                    20u
#define DMA_EEIH_EEI52_WIDTH                    1u
#define DMA_EEIH_EEI52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI52_SHIFT)) \
                                                  &DMA_EEIH_EEI52_MASK)
#define DMA_EEIH_EEI53_MASK                     0x200000u
#define DMA_EEIH_EEI53_SHIFT                    21u
#define DMA_EEIH_EEI53_WIDTH                    1u
#define DMA_EEIH_EEI53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI53_SHIFT)) \
                                                  &DMA_EEIH_EEI53_MASK)
#define DMA_EEIH_EEI54_MASK                     0x400000u
#define DMA_EEIH_EEI54_SHIFT                    22u
#define DMA_EEIH_EEI54_WIDTH                    1u
#define DMA_EEIH_EEI54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI54_SHIFT)) \
                                                  &DMA_EEIH_EEI54_MASK)
#define DMA_EEIH_EEI55_MASK                     0x800000u
#define DMA_EEIH_EEI55_SHIFT                    23u
#define DMA_EEIH_EEI55_WIDTH                    1u
#define DMA_EEIH_EEI55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI55_SHIFT)) \
                                                  &DMA_EEIH_EEI55_MASK)
#define DMA_EEIH_EEI56_MASK                     0x1000000u
#define DMA_EEIH_EEI56_SHIFT                    24u
#define DMA_EEIH_EEI56_WIDTH                    1u
#define DMA_EEIH_EEI56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI56_SHIFT)) \
                                                  &DMA_EEIH_EEI56_MASK)
#define DMA_EEIH_EEI57_MASK                     0x2000000u
#define DMA_EEIH_EEI57_SHIFT                    25u
#define DMA_EEIH_EEI57_WIDTH                    1u
#define DMA_EEIH_EEI57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI57_SHIFT)) \
                                                  &DMA_EEIH_EEI57_MASK)
#define DMA_EEIH_EEI58_MASK                     0x4000000u
#define DMA_EEIH_EEI58_SHIFT                    26u
#define DMA_EEIH_EEI58_WIDTH                    1u
#define DMA_EEIH_EEI58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI58_SHIFT)) \
                                                  &DMA_EEIH_EEI58_MASK)
#define DMA_EEIH_EEI59_MASK                     0x8000000u
#define DMA_EEIH_EEI59_SHIFT                    27u
#define DMA_EEIH_EEI59_WIDTH                    1u
#define DMA_EEIH_EEI59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI59_SHIFT)) \
                                                  &DMA_EEIH_EEI59_MASK)
#define DMA_EEIH_EEI60_MASK                     0x10000000u
#define DMA_EEIH_EEI60_SHIFT                    28u
#define DMA_EEIH_EEI60_WIDTH                    1u
#define DMA_EEIH_EEI60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI60_SHIFT)) \
                                                  &DMA_EEIH_EEI60_MASK)
#define DMA_EEIH_EEI61_MASK                     0x20000000u
#define DMA_EEIH_EEI61_SHIFT                    29u
#define DMA_EEIH_EEI61_WIDTH                    1u
#define DMA_EEIH_EEI61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI61_SHIFT)) \
                                                  &DMA_EEIH_EEI61_MASK)
#define DMA_EEIH_EEI62_MASK                     0x40000000u
#define DMA_EEIH_EEI62_SHIFT                    30u
#define DMA_EEIH_EEI62_WIDTH                    1u
#define DMA_EEIH_EEI62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI62_SHIFT)) \
                                                  &DMA_EEIH_EEI62_MASK)
#define DMA_EEIH_EEI63_MASK                     0x80000000u
#define DMA_EEIH_EEI63_SHIFT                    31u
#define DMA_EEIH_EEI63_WIDTH                    1u
#define DMA_EEIH_EEI63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIH_EEI63_SHIFT)) \
                                                  &DMA_EEIH_EEI63_MASK)
/* EEIL Bit Fields */
#define DMA_EEIL_EEI0_MASK                      0x1u
#define DMA_EEIL_EEI0_SHIFT                     0u
#define DMA_EEIL_EEI0_WIDTH                     1u
#define DMA_EEIL_EEI0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI0_SHIFT)) \
                                                  &DMA_EEIL_EEI0_MASK)
#define DMA_EEIL_EEI1_MASK                      0x2u
#define DMA_EEIL_EEI1_SHIFT                     1u
#define DMA_EEIL_EEI1_WIDTH                     1u
#define DMA_EEIL_EEI1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI1_SHIFT)) \
                                                  &DMA_EEIL_EEI1_MASK)
#define DMA_EEIL_EEI2_MASK                      0x4u
#define DMA_EEIL_EEI2_SHIFT                     2u
#define DMA_EEIL_EEI2_WIDTH                     1u
#define DMA_EEIL_EEI2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI2_SHIFT)) \
                                                  &DMA_EEIL_EEI2_MASK)
#define DMA_EEIL_EEI3_MASK                      0x8u
#define DMA_EEIL_EEI3_SHIFT                     3u
#define DMA_EEIL_EEI3_WIDTH                     1u
#define DMA_EEIL_EEI3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI3_SHIFT)) \
                                                  &DMA_EEIL_EEI3_MASK)
#define DMA_EEIL_EEI4_MASK                      0x10u
#define DMA_EEIL_EEI4_SHIFT                     4u
#define DMA_EEIL_EEI4_WIDTH                     1u
#define DMA_EEIL_EEI4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI4_SHIFT)) \
                                                  &DMA_EEIL_EEI4_MASK)
#define DMA_EEIL_EEI5_MASK                      0x20u
#define DMA_EEIL_EEI5_SHIFT                     5u
#define DMA_EEIL_EEI5_WIDTH                     1u
#define DMA_EEIL_EEI5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI5_SHIFT)) \
                                                  &DMA_EEIL_EEI5_MASK)
#define DMA_EEIL_EEI6_MASK                      0x40u
#define DMA_EEIL_EEI6_SHIFT                     6u
#define DMA_EEIL_EEI6_WIDTH                     1u
#define DMA_EEIL_EEI6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI6_SHIFT)) \
                                                  &DMA_EEIL_EEI6_MASK)
#define DMA_EEIL_EEI7_MASK                      0x80u
#define DMA_EEIL_EEI7_SHIFT                     7u
#define DMA_EEIL_EEI7_WIDTH                     1u
#define DMA_EEIL_EEI7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI7_SHIFT)) \
                                                  &DMA_EEIL_EEI7_MASK)
#define DMA_EEIL_EEI8_MASK                      0x100u
#define DMA_EEIL_EEI8_SHIFT                     8u
#define DMA_EEIL_EEI8_WIDTH                     1u
#define DMA_EEIL_EEI8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI8_SHIFT)) \
                                                  &DMA_EEIL_EEI8_MASK)
#define DMA_EEIL_EEI9_MASK                      0x200u
#define DMA_EEIL_EEI9_SHIFT                     9u
#define DMA_EEIL_EEI9_WIDTH                     1u
#define DMA_EEIL_EEI9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI9_SHIFT)) \
                                                  &DMA_EEIL_EEI9_MASK)
#define DMA_EEIL_EEI10_MASK                     0x400u
#define DMA_EEIL_EEI10_SHIFT                    10u
#define DMA_EEIL_EEI10_WIDTH                    1u
#define DMA_EEIL_EEI10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI10_SHIFT)) \
                                                  &DMA_EEIL_EEI10_MASK)
#define DMA_EEIL_EEI11_MASK                     0x800u
#define DMA_EEIL_EEI11_SHIFT                    11u
#define DMA_EEIL_EEI11_WIDTH                    1u
#define DMA_EEIL_EEI11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI11_SHIFT)) \
                                                  &DMA_EEIL_EEI11_MASK)
#define DMA_EEIL_EEI12_MASK                     0x1000u
#define DMA_EEIL_EEI12_SHIFT                    12u
#define DMA_EEIL_EEI12_WIDTH                    1u
#define DMA_EEIL_EEI12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI12_SHIFT)) \
                                                  &DMA_EEIL_EEI12_MASK)
#define DMA_EEIL_EEI13_MASK                     0x2000u
#define DMA_EEIL_EEI13_SHIFT                    13u
#define DMA_EEIL_EEI13_WIDTH                    1u
#define DMA_EEIL_EEI13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI13_SHIFT)) \
                                                  &DMA_EEIL_EEI13_MASK)
#define DMA_EEIL_EEI14_MASK                     0x4000u
#define DMA_EEIL_EEI14_SHIFT                    14u
#define DMA_EEIL_EEI14_WIDTH                    1u
#define DMA_EEIL_EEI14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI14_SHIFT)) \
                                                  &DMA_EEIL_EEI14_MASK)
#define DMA_EEIL_EEI15_MASK                     0x8000u
#define DMA_EEIL_EEI15_SHIFT                    15u
#define DMA_EEIL_EEI15_WIDTH                    1u
#define DMA_EEIL_EEI15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI15_SHIFT)) \
                                                  &DMA_EEIL_EEI15_MASK)
#define DMA_EEIL_EEI16_MASK                     0x10000u
#define DMA_EEIL_EEI16_SHIFT                    16u
#define DMA_EEIL_EEI16_WIDTH                    1u
#define DMA_EEIL_EEI16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI16_SHIFT)) \
                                                  &DMA_EEIL_EEI16_MASK)
#define DMA_EEIL_EEI17_MASK                     0x20000u
#define DMA_EEIL_EEI17_SHIFT                    17u
#define DMA_EEIL_EEI17_WIDTH                    1u
#define DMA_EEIL_EEI17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI17_SHIFT)) \
                                                  &DMA_EEIL_EEI17_MASK)
#define DMA_EEIL_EEI18_MASK                     0x40000u
#define DMA_EEIL_EEI18_SHIFT                    18u
#define DMA_EEIL_EEI18_WIDTH                    1u
#define DMA_EEIL_EEI18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI18_SHIFT)) \
                                                  &DMA_EEIL_EEI18_MASK)
#define DMA_EEIL_EEI19_MASK                     0x80000u
#define DMA_EEIL_EEI19_SHIFT                    19u
#define DMA_EEIL_EEI19_WIDTH                    1u
#define DMA_EEIL_EEI19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI19_SHIFT)) \
                                                  &DMA_EEIL_EEI19_MASK)
#define DMA_EEIL_EEI20_MASK                     0x100000u
#define DMA_EEIL_EEI20_SHIFT                    20u
#define DMA_EEIL_EEI20_WIDTH                    1u
#define DMA_EEIL_EEI20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI20_SHIFT)) \
                                                  &DMA_EEIL_EEI20_MASK)
#define DMA_EEIL_EEI21_MASK                     0x200000u
#define DMA_EEIL_EEI21_SHIFT                    21u
#define DMA_EEIL_EEI21_WIDTH                    1u
#define DMA_EEIL_EEI21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI21_SHIFT)) \
                                                  &DMA_EEIL_EEI21_MASK)
#define DMA_EEIL_EEI22_MASK                     0x400000u
#define DMA_EEIL_EEI22_SHIFT                    22u
#define DMA_EEIL_EEI22_WIDTH                    1u
#define DMA_EEIL_EEI22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI22_SHIFT)) \
                                                  &DMA_EEIL_EEI22_MASK)
#define DMA_EEIL_EEI23_MASK                     0x800000u
#define DMA_EEIL_EEI23_SHIFT                    23u
#define DMA_EEIL_EEI23_WIDTH                    1u
#define DMA_EEIL_EEI23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI23_SHIFT)) \
                                                  &DMA_EEIL_EEI23_MASK)
#define DMA_EEIL_EEI24_MASK                     0x1000000u
#define DMA_EEIL_EEI24_SHIFT                    24u
#define DMA_EEIL_EEI24_WIDTH                    1u
#define DMA_EEIL_EEI24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI24_SHIFT)) \
                                                  &DMA_EEIL_EEI24_MASK)
#define DMA_EEIL_EEI25_MASK                     0x2000000u
#define DMA_EEIL_EEI25_SHIFT                    25u
#define DMA_EEIL_EEI25_WIDTH                    1u
#define DMA_EEIL_EEI25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI25_SHIFT)) \
                                                  &DMA_EEIL_EEI25_MASK)
#define DMA_EEIL_EEI26_MASK                     0x4000000u
#define DMA_EEIL_EEI26_SHIFT                    26u
#define DMA_EEIL_EEI26_WIDTH                    1u
#define DMA_EEIL_EEI26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI26_SHIFT)) \
                                                  &DMA_EEIL_EEI26_MASK)
#define DMA_EEIL_EEI27_MASK                     0x8000000u
#define DMA_EEIL_EEI27_SHIFT                    27u
#define DMA_EEIL_EEI27_WIDTH                    1u
#define DMA_EEIL_EEI27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI27_SHIFT)) \
                                                  &DMA_EEIL_EEI27_MASK)
#define DMA_EEIL_EEI28_MASK                     0x10000000u
#define DMA_EEIL_EEI28_SHIFT                    28u
#define DMA_EEIL_EEI28_WIDTH                    1u
#define DMA_EEIL_EEI28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI28_SHIFT)) \
                                                  &DMA_EEIL_EEI28_MASK)
#define DMA_EEIL_EEI29_MASK                     0x20000000u
#define DMA_EEIL_EEI29_SHIFT                    29u
#define DMA_EEIL_EEI29_WIDTH                    1u
#define DMA_EEIL_EEI29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI29_SHIFT)) \
                                                  &DMA_EEIL_EEI29_MASK)
#define DMA_EEIL_EEI30_MASK                     0x40000000u
#define DMA_EEIL_EEI30_SHIFT                    30u
#define DMA_EEIL_EEI30_WIDTH                    1u
#define DMA_EEIL_EEI30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI30_SHIFT)) \
                                                  &DMA_EEIL_EEI30_MASK)
#define DMA_EEIL_EEI31_MASK                     0x80000000u
#define DMA_EEIL_EEI31_SHIFT                    31u
#define DMA_EEIL_EEI31_WIDTH                    1u
#define DMA_EEIL_EEI31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_EEIL_EEI31_SHIFT)) \
                                                  &DMA_EEIL_EEI31_MASK)
/* SERQ Bit Fields */
#define DMA_SERQ_SERQ_MASK                      0x3Fu
#define DMA_SERQ_SERQ_SHIFT                     0u
#define DMA_SERQ_SERQ_WIDTH                     6u
#define DMA_SERQ_SERQ(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SERQ_SERQ_SHIFT)) \
                                                  &DMA_SERQ_SERQ_MASK)
#define DMA_SERQ_SAER_MASK                      0x40u
#define DMA_SERQ_SAER_SHIFT                     6u
#define DMA_SERQ_SAER_WIDTH                     1u
#define DMA_SERQ_SAER(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SERQ_SAER_SHIFT)) \
                                                  &DMA_SERQ_SAER_MASK)
#define DMA_SERQ_NOP_MASK                       0x80u
#define DMA_SERQ_NOP_SHIFT                      7u
#define DMA_SERQ_NOP_WIDTH                      1u
#define DMA_SERQ_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_SERQ_NOP_SHIFT)) \
                                                  &DMA_SERQ_NOP_MASK)
/* CERQ Bit Fields */
#define DMA_CERQ_CERQ_MASK                      0x3Fu
#define DMA_CERQ_CERQ_SHIFT                     0u
#define DMA_CERQ_CERQ_WIDTH                     6u
#define DMA_CERQ_CERQ(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CERQ_CERQ_SHIFT)) \
                                                  &DMA_CERQ_CERQ_MASK)
#define DMA_CERQ_CAER_MASK                      0x40u
#define DMA_CERQ_CAER_SHIFT                     6u
#define DMA_CERQ_CAER_WIDTH                     1u
#define DMA_CERQ_CAER(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CERQ_CAER_SHIFT)) \
                                                  &DMA_CERQ_CAER_MASK)
#define DMA_CERQ_NOP_MASK                       0x80u
#define DMA_CERQ_NOP_SHIFT                      7u
#define DMA_CERQ_NOP_WIDTH                      1u
#define DMA_CERQ_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CERQ_NOP_SHIFT)) \
                                                  &DMA_CERQ_NOP_MASK)
/* SEEI Bit Fields */
#define DMA_SEEI_SEEI_MASK                      0x3Fu
#define DMA_SEEI_SEEI_SHIFT                     0u
#define DMA_SEEI_SEEI_WIDTH                     6u
#define DMA_SEEI_SEEI(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SEEI_SEEI_SHIFT)) \
                                                  &DMA_SEEI_SEEI_MASK)
#define DMA_SEEI_SAEE_MASK                      0x40u
#define DMA_SEEI_SAEE_SHIFT                     6u
#define DMA_SEEI_SAEE_WIDTH                     1u
#define DMA_SEEI_SAEE(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SEEI_SAEE_SHIFT)) \
                                                  &DMA_SEEI_SAEE_MASK)
#define DMA_SEEI_NOP_MASK                       0x80u
#define DMA_SEEI_NOP_SHIFT                      7u
#define DMA_SEEI_NOP_WIDTH                      1u
#define DMA_SEEI_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_SEEI_NOP_SHIFT)) \
                                                  &DMA_SEEI_NOP_MASK)
/* CEEI Bit Fields */
#define DMA_CEEI_CEEI_MASK                      0x3Fu
#define DMA_CEEI_CEEI_SHIFT                     0u
#define DMA_CEEI_CEEI_WIDTH                     6u
#define DMA_CEEI_CEEI(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CEEI_CEEI_SHIFT)) \
                                                  &DMA_CEEI_CEEI_MASK)
#define DMA_CEEI_CAEE_MASK                      0x40u
#define DMA_CEEI_CAEE_SHIFT                     6u
#define DMA_CEEI_CAEE_WIDTH                     1u
#define DMA_CEEI_CAEE(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CEEI_CAEE_SHIFT)) \
                                                  &DMA_CEEI_CAEE_MASK)
#define DMA_CEEI_NOP_MASK                       0x80u
#define DMA_CEEI_NOP_SHIFT                      7u
#define DMA_CEEI_NOP_WIDTH                      1u
#define DMA_CEEI_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CEEI_NOP_SHIFT)) \
                                                  &DMA_CEEI_NOP_MASK)
/* CINT Bit Fields */
#define DMA_CINT_CINT_MASK                      0x3Fu
#define DMA_CINT_CINT_SHIFT                     0u
#define DMA_CINT_CINT_WIDTH                     6u
#define DMA_CINT_CINT(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CINT_CINT_SHIFT)) \
                                                  &DMA_CINT_CINT_MASK)
#define DMA_CINT_CAIR_MASK                      0x40u
#define DMA_CINT_CAIR_SHIFT                     6u
#define DMA_CINT_CAIR_WIDTH                     1u
#define DMA_CINT_CAIR(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CINT_CAIR_SHIFT)) \
                                                  &DMA_CINT_CAIR_MASK)
#define DMA_CINT_NOP_MASK                       0x80u
#define DMA_CINT_NOP_SHIFT                      7u
#define DMA_CINT_NOP_WIDTH                      1u
#define DMA_CINT_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CINT_NOP_SHIFT)) \
                                                  &DMA_CINT_NOP_MASK)
/* CERR Bit Fields */
#define DMA_CERR_CERR_MASK                      0x3Fu
#define DMA_CERR_CERR_SHIFT                     0u
#define DMA_CERR_CERR_WIDTH                     6u
#define DMA_CERR_CERR(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CERR_CERR_SHIFT)) \
                                                  &DMA_CERR_CERR_MASK)
#define DMA_CERR_CAEI_MASK                      0x40u
#define DMA_CERR_CAEI_SHIFT                     6u
#define DMA_CERR_CAEI_WIDTH                     1u
#define DMA_CERR_CAEI(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CERR_CAEI_SHIFT)) \
                                                  &DMA_CERR_CAEI_MASK)
#define DMA_CERR_NOP_MASK                       0x80u
#define DMA_CERR_NOP_SHIFT                      7u
#define DMA_CERR_NOP_WIDTH                      1u
#define DMA_CERR_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CERR_NOP_SHIFT)) \
                                                  &DMA_CERR_NOP_MASK)
/* SSRT Bit Fields */
#define DMA_SSRT_SSRT_MASK                      0x3Fu
#define DMA_SSRT_SSRT_SHIFT                     0u
#define DMA_SSRT_SSRT_WIDTH                     6u
#define DMA_SSRT_SSRT(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SSRT_SSRT_SHIFT)) \
                                                  &DMA_SSRT_SSRT_MASK)
#define DMA_SSRT_SAST_MASK                      0x40u
#define DMA_SSRT_SAST_SHIFT                     6u
#define DMA_SSRT_SAST_WIDTH                     1u
#define DMA_SSRT_SAST(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_SSRT_SAST_SHIFT)) \
                                                  &DMA_SSRT_SAST_MASK)
#define DMA_SSRT_NOP_MASK                       0x80u
#define DMA_SSRT_NOP_SHIFT                      7u
#define DMA_SSRT_NOP_WIDTH                      1u
#define DMA_SSRT_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_SSRT_NOP_SHIFT)) \
                                                  &DMA_SSRT_NOP_MASK)
/* CDNE Bit Fields */
#define DMA_CDNE_CDNE_MASK                      0x3Fu
#define DMA_CDNE_CDNE_SHIFT                     0u
#define DMA_CDNE_CDNE_WIDTH                     6u
#define DMA_CDNE_CDNE(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CDNE_CDNE_SHIFT)) \
                                                  &DMA_CDNE_CDNE_MASK)
#define DMA_CDNE_CADN_MASK                      0x40u
#define DMA_CDNE_CADN_SHIFT                     6u
#define DMA_CDNE_CADN_WIDTH                     1u
#define DMA_CDNE_CADN(x)                        (((uint8)(((uint8)(x)) \
                                                  << DMA_CDNE_CADN_SHIFT)) \
                                                  &DMA_CDNE_CADN_MASK)
#define DMA_CDNE_NOP_MASK                       0x80u
#define DMA_CDNE_NOP_SHIFT                      7u
#define DMA_CDNE_NOP_WIDTH                      1u
#define DMA_CDNE_NOP(x)                         (((uint8)(((uint8)(x)) \
                                                  << DMA_CDNE_NOP_SHIFT)) \
                                                  &DMA_CDNE_NOP_MASK)
/* INTH Bit Fields */
#define DMA_INTH_INT32_MASK                     0x1u
#define DMA_INTH_INT32_SHIFT                    0u
#define DMA_INTH_INT32_WIDTH                    1u
#define DMA_INTH_INT32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT32_SHIFT)) \
                                                  &DMA_INTH_INT32_MASK)
#define DMA_INTH_INT33_MASK                     0x2u
#define DMA_INTH_INT33_SHIFT                    1u
#define DMA_INTH_INT33_WIDTH                    1u
#define DMA_INTH_INT33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT33_SHIFT)) \
                                                  &DMA_INTH_INT33_MASK)
#define DMA_INTH_INT34_MASK                     0x4u
#define DMA_INTH_INT34_SHIFT                    2u
#define DMA_INTH_INT34_WIDTH                    1u
#define DMA_INTH_INT34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT34_SHIFT)) \
                                                  &DMA_INTH_INT34_MASK)
#define DMA_INTH_INT35_MASK                     0x8u
#define DMA_INTH_INT35_SHIFT                    3u
#define DMA_INTH_INT35_WIDTH                    1u
#define DMA_INTH_INT35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT35_SHIFT)) \
                                                  &DMA_INTH_INT35_MASK)
#define DMA_INTH_INT36_MASK                     0x10u
#define DMA_INTH_INT36_SHIFT                    4u
#define DMA_INTH_INT36_WIDTH                    1u
#define DMA_INTH_INT36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT36_SHIFT)) \
                                                  &DMA_INTH_INT36_MASK)
#define DMA_INTH_INT37_MASK                     0x20u
#define DMA_INTH_INT37_SHIFT                    5u
#define DMA_INTH_INT37_WIDTH                    1u
#define DMA_INTH_INT37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT37_SHIFT)) \
                                                  &DMA_INTH_INT37_MASK)
#define DMA_INTH_INT38_MASK                     0x40u
#define DMA_INTH_INT38_SHIFT                    6u
#define DMA_INTH_INT38_WIDTH                    1u
#define DMA_INTH_INT38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT38_SHIFT)) \
                                                  &DMA_INTH_INT38_MASK)
#define DMA_INTH_INT39_MASK                     0x80u
#define DMA_INTH_INT39_SHIFT                    7u
#define DMA_INTH_INT39_WIDTH                    1u
#define DMA_INTH_INT39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT39_SHIFT)) \
                                                  &DMA_INTH_INT39_MASK)
#define DMA_INTH_INT40_MASK                     0x100u
#define DMA_INTH_INT40_SHIFT                    8u
#define DMA_INTH_INT40_WIDTH                    1u
#define DMA_INTH_INT40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT40_SHIFT)) \
                                                  &DMA_INTH_INT40_MASK)
#define DMA_INTH_INT41_MASK                     0x200u
#define DMA_INTH_INT41_SHIFT                    9u
#define DMA_INTH_INT41_WIDTH                    1u
#define DMA_INTH_INT41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT41_SHIFT)) \
                                                  &DMA_INTH_INT41_MASK)
#define DMA_INTH_INT42_MASK                     0x400u
#define DMA_INTH_INT42_SHIFT                    10u
#define DMA_INTH_INT42_WIDTH                    1u
#define DMA_INTH_INT42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT42_SHIFT)) \
                                                  &DMA_INTH_INT42_MASK)
#define DMA_INTH_INT43_MASK                     0x800u
#define DMA_INTH_INT43_SHIFT                    11u
#define DMA_INTH_INT43_WIDTH                    1u
#define DMA_INTH_INT43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT43_SHIFT)) \
                                                  &DMA_INTH_INT43_MASK)
#define DMA_INTH_INT44_MASK                     0x1000u
#define DMA_INTH_INT44_SHIFT                    12u
#define DMA_INTH_INT44_WIDTH                    1u
#define DMA_INTH_INT44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT44_SHIFT)) \
                                                  &DMA_INTH_INT44_MASK)
#define DMA_INTH_INT45_MASK                     0x2000u
#define DMA_INTH_INT45_SHIFT                    13u
#define DMA_INTH_INT45_WIDTH                    1u
#define DMA_INTH_INT45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT45_SHIFT)) \
                                                  &DMA_INTH_INT45_MASK)
#define DMA_INTH_INT46_MASK                     0x4000u
#define DMA_INTH_INT46_SHIFT                    14u
#define DMA_INTH_INT46_WIDTH                    1u
#define DMA_INTH_INT46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT46_SHIFT)) \
                                                  &DMA_INTH_INT46_MASK)
#define DMA_INTH_INT47_MASK                     0x8000u
#define DMA_INTH_INT47_SHIFT                    15u
#define DMA_INTH_INT47_WIDTH                    1u
#define DMA_INTH_INT47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT47_SHIFT)) \
                                                  &DMA_INTH_INT47_MASK)
#define DMA_INTH_INT48_MASK                     0x10000u
#define DMA_INTH_INT48_SHIFT                    16u
#define DMA_INTH_INT48_WIDTH                    1u
#define DMA_INTH_INT48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT48_SHIFT)) \
                                                  &DMA_INTH_INT48_MASK)
#define DMA_INTH_INT49_MASK                     0x20000u
#define DMA_INTH_INT49_SHIFT                    17u
#define DMA_INTH_INT49_WIDTH                    1u
#define DMA_INTH_INT49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT49_SHIFT)) \
                                                  &DMA_INTH_INT49_MASK)
#define DMA_INTH_INT50_MASK                     0x40000u
#define DMA_INTH_INT50_SHIFT                    18u
#define DMA_INTH_INT50_WIDTH                    1u
#define DMA_INTH_INT50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT50_SHIFT)) \
                                                  &DMA_INTH_INT50_MASK)
#define DMA_INTH_INT51_MASK                     0x80000u
#define DMA_INTH_INT51_SHIFT                    19u
#define DMA_INTH_INT51_WIDTH                    1u
#define DMA_INTH_INT51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT51_SHIFT)) \
                                                  &DMA_INTH_INT51_MASK)
#define DMA_INTH_INT52_MASK                     0x100000u
#define DMA_INTH_INT52_SHIFT                    20u
#define DMA_INTH_INT52_WIDTH                    1u
#define DMA_INTH_INT52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT52_SHIFT)) \
                                                  &DMA_INTH_INT52_MASK)
#define DMA_INTH_INT53_MASK                     0x200000u
#define DMA_INTH_INT53_SHIFT                    21u
#define DMA_INTH_INT53_WIDTH                    1u
#define DMA_INTH_INT53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT53_SHIFT)) \
                                                  &DMA_INTH_INT53_MASK)
#define DMA_INTH_INT54_MASK                     0x400000u
#define DMA_INTH_INT54_SHIFT                    22u
#define DMA_INTH_INT54_WIDTH                    1u
#define DMA_INTH_INT54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT54_SHIFT)) \
                                                  &DMA_INTH_INT54_MASK)
#define DMA_INTH_INT55_MASK                     0x800000u
#define DMA_INTH_INT55_SHIFT                    23u
#define DMA_INTH_INT55_WIDTH                    1u
#define DMA_INTH_INT55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT55_SHIFT)) \
                                                  &DMA_INTH_INT55_MASK)
#define DMA_INTH_INT56_MASK                     0x1000000u
#define DMA_INTH_INT56_SHIFT                    24u
#define DMA_INTH_INT56_WIDTH                    1u
#define DMA_INTH_INT56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT56_SHIFT)) \
                                                  &DMA_INTH_INT56_MASK)
#define DMA_INTH_INT57_MASK                     0x2000000u
#define DMA_INTH_INT57_SHIFT                    25u
#define DMA_INTH_INT57_WIDTH                    1u
#define DMA_INTH_INT57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT57_SHIFT)) \
                                                  &DMA_INTH_INT57_MASK)
#define DMA_INTH_INT58_MASK                     0x4000000u
#define DMA_INTH_INT58_SHIFT                    26u
#define DMA_INTH_INT58_WIDTH                    1u
#define DMA_INTH_INT58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT58_SHIFT)) \
                                                  &DMA_INTH_INT58_MASK)
#define DMA_INTH_INT59_MASK                     0x8000000u
#define DMA_INTH_INT59_SHIFT                    27u
#define DMA_INTH_INT59_WIDTH                    1u
#define DMA_INTH_INT59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT59_SHIFT)) \
                                                  &DMA_INTH_INT59_MASK)
#define DMA_INTH_INT60_MASK                     0x10000000u
#define DMA_INTH_INT60_SHIFT                    28u
#define DMA_INTH_INT60_WIDTH                    1u
#define DMA_INTH_INT60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT60_SHIFT)) \
                                                  &DMA_INTH_INT60_MASK)
#define DMA_INTH_INT61_MASK                     0x20000000u
#define DMA_INTH_INT61_SHIFT                    29u
#define DMA_INTH_INT61_WIDTH                    1u
#define DMA_INTH_INT61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT61_SHIFT)) \
                                                  &DMA_INTH_INT61_MASK)
#define DMA_INTH_INT62_MASK                     0x40000000u
#define DMA_INTH_INT62_SHIFT                    30u
#define DMA_INTH_INT62_WIDTH                    1u
#define DMA_INTH_INT62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT62_SHIFT)) \
                                                  &DMA_INTH_INT62_MASK)
#define DMA_INTH_INT63_MASK                     0x80000000u
#define DMA_INTH_INT63_SHIFT                    31u
#define DMA_INTH_INT63_WIDTH                    1u
#define DMA_INTH_INT63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTH_INT63_SHIFT)) \
                                                  &DMA_INTH_INT63_MASK)
/* INTL Bit Fields */
#define DMA_INTL_INT0_MASK                      0x1u
#define DMA_INTL_INT0_SHIFT                     0u
#define DMA_INTL_INT0_WIDTH                     1u
#define DMA_INTL_INT0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT0_SHIFT)) \
                                                  &DMA_INTL_INT0_MASK)
#define DMA_INTL_INT1_MASK                      0x2u
#define DMA_INTL_INT1_SHIFT                     1u
#define DMA_INTL_INT1_WIDTH                     1u
#define DMA_INTL_INT1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT1_SHIFT)) \
                                                  &DMA_INTL_INT1_MASK)
#define DMA_INTL_INT2_MASK                      0x4u
#define DMA_INTL_INT2_SHIFT                     2u
#define DMA_INTL_INT2_WIDTH                     1u
#define DMA_INTL_INT2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT2_SHIFT)) \
                                                  &DMA_INTL_INT2_MASK)
#define DMA_INTL_INT3_MASK                      0x8u
#define DMA_INTL_INT3_SHIFT                     3u
#define DMA_INTL_INT3_WIDTH                     1u
#define DMA_INTL_INT3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT3_SHIFT)) \
                                                  &DMA_INTL_INT3_MASK)
#define DMA_INTL_INT4_MASK                      0x10u
#define DMA_INTL_INT4_SHIFT                     4u
#define DMA_INTL_INT4_WIDTH                     1u
#define DMA_INTL_INT4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT4_SHIFT)) \
                                                  &DMA_INTL_INT4_MASK)
#define DMA_INTL_INT5_MASK                      0x20u
#define DMA_INTL_INT5_SHIFT                     5u
#define DMA_INTL_INT5_WIDTH                     1u
#define DMA_INTL_INT5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT5_SHIFT)) \
                                                  &DMA_INTL_INT5_MASK)
#define DMA_INTL_INT6_MASK                      0x40u
#define DMA_INTL_INT6_SHIFT                     6u
#define DMA_INTL_INT6_WIDTH                     1u
#define DMA_INTL_INT6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT6_SHIFT)) \
                                                  &DMA_INTL_INT6_MASK)
#define DMA_INTL_INT7_MASK                      0x80u
#define DMA_INTL_INT7_SHIFT                     7u
#define DMA_INTL_INT7_WIDTH                     1u
#define DMA_INTL_INT7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT7_SHIFT)) \
                                                  &DMA_INTL_INT7_MASK)
#define DMA_INTL_INT8_MASK                      0x100u
#define DMA_INTL_INT8_SHIFT                     8u
#define DMA_INTL_INT8_WIDTH                     1u
#define DMA_INTL_INT8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT8_SHIFT)) \
                                                  &DMA_INTL_INT8_MASK)
#define DMA_INTL_INT9_MASK                      0x200u
#define DMA_INTL_INT9_SHIFT                     9u
#define DMA_INTL_INT9_WIDTH                     1u
#define DMA_INTL_INT9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT9_SHIFT)) \
                                                  &DMA_INTL_INT9_MASK)
#define DMA_INTL_INT10_MASK                     0x400u
#define DMA_INTL_INT10_SHIFT                    10u
#define DMA_INTL_INT10_WIDTH                    1u
#define DMA_INTL_INT10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT10_SHIFT)) \
                                                  &DMA_INTL_INT10_MASK)
#define DMA_INTL_INT11_MASK                     0x800u
#define DMA_INTL_INT11_SHIFT                    11u
#define DMA_INTL_INT11_WIDTH                    1u
#define DMA_INTL_INT11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT11_SHIFT)) \
                                                  &DMA_INTL_INT11_MASK)
#define DMA_INTL_INT12_MASK                     0x1000u
#define DMA_INTL_INT12_SHIFT                    12u
#define DMA_INTL_INT12_WIDTH                    1u
#define DMA_INTL_INT12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT12_SHIFT)) \
                                                  &DMA_INTL_INT12_MASK)
#define DMA_INTL_INT13_MASK                     0x2000u
#define DMA_INTL_INT13_SHIFT                    13u
#define DMA_INTL_INT13_WIDTH                    1u
#define DMA_INTL_INT13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT13_SHIFT)) \
                                                  &DMA_INTL_INT13_MASK)
#define DMA_INTL_INT14_MASK                     0x4000u
#define DMA_INTL_INT14_SHIFT                    14u
#define DMA_INTL_INT14_WIDTH                    1u
#define DMA_INTL_INT14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT14_SHIFT)) \
                                                  &DMA_INTL_INT14_MASK)
#define DMA_INTL_INT15_MASK                     0x8000u
#define DMA_INTL_INT15_SHIFT                    15u
#define DMA_INTL_INT15_WIDTH                    1u
#define DMA_INTL_INT15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT15_SHIFT)) \
                                                  &DMA_INTL_INT15_MASK)
#define DMA_INTL_INT16_MASK                     0x10000u
#define DMA_INTL_INT16_SHIFT                    16u
#define DMA_INTL_INT16_WIDTH                    1u
#define DMA_INTL_INT16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT16_SHIFT)) \
                                                  &DMA_INTL_INT16_MASK)
#define DMA_INTL_INT17_MASK                     0x20000u
#define DMA_INTL_INT17_SHIFT                    17u
#define DMA_INTL_INT17_WIDTH                    1u
#define DMA_INTL_INT17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT17_SHIFT)) \
                                                  &DMA_INTL_INT17_MASK)
#define DMA_INTL_INT18_MASK                     0x40000u
#define DMA_INTL_INT18_SHIFT                    18u
#define DMA_INTL_INT18_WIDTH                    1u
#define DMA_INTL_INT18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT18_SHIFT)) \
                                                  &DMA_INTL_INT18_MASK)
#define DMA_INTL_INT19_MASK                     0x80000u
#define DMA_INTL_INT19_SHIFT                    19u
#define DMA_INTL_INT19_WIDTH                    1u
#define DMA_INTL_INT19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT19_SHIFT)) \
                                                  &DMA_INTL_INT19_MASK)
#define DMA_INTL_INT20_MASK                     0x100000u
#define DMA_INTL_INT20_SHIFT                    20u
#define DMA_INTL_INT20_WIDTH                    1u
#define DMA_INTL_INT20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT20_SHIFT)) \
                                                  &DMA_INTL_INT20_MASK)
#define DMA_INTL_INT21_MASK                     0x200000u
#define DMA_INTL_INT21_SHIFT                    21u
#define DMA_INTL_INT21_WIDTH                    1u
#define DMA_INTL_INT21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT21_SHIFT)) \
                                                  &DMA_INTL_INT21_MASK)
#define DMA_INTL_INT22_MASK                     0x400000u
#define DMA_INTL_INT22_SHIFT                    22u
#define DMA_INTL_INT22_WIDTH                    1u
#define DMA_INTL_INT22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT22_SHIFT)) \
                                                  &DMA_INTL_INT22_MASK)
#define DMA_INTL_INT23_MASK                     0x800000u
#define DMA_INTL_INT23_SHIFT                    23u
#define DMA_INTL_INT23_WIDTH                    1u
#define DMA_INTL_INT23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT23_SHIFT)) \
                                                  &DMA_INTL_INT23_MASK)
#define DMA_INTL_INT24_MASK                     0x1000000u
#define DMA_INTL_INT24_SHIFT                    24u
#define DMA_INTL_INT24_WIDTH                    1u
#define DMA_INTL_INT24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT24_SHIFT)) \
                                                  &DMA_INTL_INT24_MASK)
#define DMA_INTL_INT25_MASK                     0x2000000u
#define DMA_INTL_INT25_SHIFT                    25u
#define DMA_INTL_INT25_WIDTH                    1u
#define DMA_INTL_INT25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT25_SHIFT)) \
                                                  &DMA_INTL_INT25_MASK)
#define DMA_INTL_INT26_MASK                     0x4000000u
#define DMA_INTL_INT26_SHIFT                    26u
#define DMA_INTL_INT26_WIDTH                    1u
#define DMA_INTL_INT26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT26_SHIFT)) \
                                                  &DMA_INTL_INT26_MASK)
#define DMA_INTL_INT27_MASK                     0x8000000u
#define DMA_INTL_INT27_SHIFT                    27u
#define DMA_INTL_INT27_WIDTH                    1u
#define DMA_INTL_INT27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT27_SHIFT)) \
                                                  &DMA_INTL_INT27_MASK)
#define DMA_INTL_INT28_MASK                     0x10000000u
#define DMA_INTL_INT28_SHIFT                    28u
#define DMA_INTL_INT28_WIDTH                    1u
#define DMA_INTL_INT28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT28_SHIFT)) \
                                                  &DMA_INTL_INT28_MASK)
#define DMA_INTL_INT29_MASK                     0x20000000u
#define DMA_INTL_INT29_SHIFT                    29u
#define DMA_INTL_INT29_WIDTH                    1u
#define DMA_INTL_INT29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT29_SHIFT)) \
                                                  &DMA_INTL_INT29_MASK)
#define DMA_INTL_INT30_MASK                     0x40000000u
#define DMA_INTL_INT30_SHIFT                    30u
#define DMA_INTL_INT30_WIDTH                    1u
#define DMA_INTL_INT30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT30_SHIFT)) \
                                                  &DMA_INTL_INT30_MASK)
#define DMA_INTL_INT31_MASK                     0x80000000u
#define DMA_INTL_INT31_SHIFT                    31u
#define DMA_INTL_INT31_WIDTH                    1u
#define DMA_INTL_INT31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_INTL_INT31_SHIFT)) \
                                                  &DMA_INTL_INT31_MASK)
/* ERRH Bit Fields */
#define DMA_ERRH_ERR32_MASK                     0x1u
#define DMA_ERRH_ERR32_SHIFT                    0u
#define DMA_ERRH_ERR32_WIDTH                    1u
#define DMA_ERRH_ERR32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR32_SHIFT)) \
                                                  &DMA_ERRH_ERR32_MASK)
#define DMA_ERRH_ERR33_MASK                     0x2u
#define DMA_ERRH_ERR33_SHIFT                    1u
#define DMA_ERRH_ERR33_WIDTH                    1u
#define DMA_ERRH_ERR33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR33_SHIFT)) \
                                                  &DMA_ERRH_ERR33_MASK)
#define DMA_ERRH_ERR34_MASK                     0x4u
#define DMA_ERRH_ERR34_SHIFT                    2u
#define DMA_ERRH_ERR34_WIDTH                    1u
#define DMA_ERRH_ERR34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR34_SHIFT)) \
                                                  &DMA_ERRH_ERR34_MASK)
#define DMA_ERRH_ERR35_MASK                     0x8u
#define DMA_ERRH_ERR35_SHIFT                    3u
#define DMA_ERRH_ERR35_WIDTH                    1u
#define DMA_ERRH_ERR35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR35_SHIFT)) \
                                                  &DMA_ERRH_ERR35_MASK)
#define DMA_ERRH_ERR36_MASK                     0x10u
#define DMA_ERRH_ERR36_SHIFT                    4u
#define DMA_ERRH_ERR36_WIDTH                    1u
#define DMA_ERRH_ERR36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR36_SHIFT)) \
                                                  &DMA_ERRH_ERR36_MASK)
#define DMA_ERRH_ERR37_MASK                     0x20u
#define DMA_ERRH_ERR37_SHIFT                    5u
#define DMA_ERRH_ERR37_WIDTH                    1u
#define DMA_ERRH_ERR37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR37_SHIFT)) \
                                                  &DMA_ERRH_ERR37_MASK)
#define DMA_ERRH_ERR38_MASK                     0x40u
#define DMA_ERRH_ERR38_SHIFT                    6u
#define DMA_ERRH_ERR38_WIDTH                    1u
#define DMA_ERRH_ERR38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR38_SHIFT)) \
                                                  &DMA_ERRH_ERR38_MASK)
#define DMA_ERRH_ERR39_MASK                     0x80u
#define DMA_ERRH_ERR39_SHIFT                    7u
#define DMA_ERRH_ERR39_WIDTH                    1u
#define DMA_ERRH_ERR39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR39_SHIFT)) \
                                                  &DMA_ERRH_ERR39_MASK)
#define DMA_ERRH_ERR40_MASK                     0x100u
#define DMA_ERRH_ERR40_SHIFT                    8u
#define DMA_ERRH_ERR40_WIDTH                    1u
#define DMA_ERRH_ERR40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR40_SHIFT)) \
                                                  &DMA_ERRH_ERR40_MASK)
#define DMA_ERRH_ERR41_MASK                     0x200u
#define DMA_ERRH_ERR41_SHIFT                    9u
#define DMA_ERRH_ERR41_WIDTH                    1u
#define DMA_ERRH_ERR41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR41_SHIFT)) \
                                                  &DMA_ERRH_ERR41_MASK)
#define DMA_ERRH_ERR42_MASK                     0x400u
#define DMA_ERRH_ERR42_SHIFT                    10u
#define DMA_ERRH_ERR42_WIDTH                    1u
#define DMA_ERRH_ERR42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR42_SHIFT)) \
                                                  &DMA_ERRH_ERR42_MASK)
#define DMA_ERRH_ERR43_MASK                     0x800u
#define DMA_ERRH_ERR43_SHIFT                    11u
#define DMA_ERRH_ERR43_WIDTH                    1u
#define DMA_ERRH_ERR43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR43_SHIFT)) \
                                                  &DMA_ERRH_ERR43_MASK)
#define DMA_ERRH_ERR44_MASK                     0x1000u
#define DMA_ERRH_ERR44_SHIFT                    12u
#define DMA_ERRH_ERR44_WIDTH                    1u
#define DMA_ERRH_ERR44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR44_SHIFT)) \
                                                  &DMA_ERRH_ERR44_MASK)
#define DMA_ERRH_ERR45_MASK                     0x2000u
#define DMA_ERRH_ERR45_SHIFT                    13u
#define DMA_ERRH_ERR45_WIDTH                    1u
#define DMA_ERRH_ERR45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR45_SHIFT)) \
                                                  &DMA_ERRH_ERR45_MASK)
#define DMA_ERRH_ERR46_MASK                     0x4000u
#define DMA_ERRH_ERR46_SHIFT                    14u
#define DMA_ERRH_ERR46_WIDTH                    1u
#define DMA_ERRH_ERR46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR46_SHIFT)) \
                                                  &DMA_ERRH_ERR46_MASK)
#define DMA_ERRH_ERR47_MASK                     0x8000u
#define DMA_ERRH_ERR47_SHIFT                    15u
#define DMA_ERRH_ERR47_WIDTH                    1u
#define DMA_ERRH_ERR47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR47_SHIFT)) \
                                                  &DMA_ERRH_ERR47_MASK)
#define DMA_ERRH_ERR48_MASK                     0x10000u
#define DMA_ERRH_ERR48_SHIFT                    16u
#define DMA_ERRH_ERR48_WIDTH                    1u
#define DMA_ERRH_ERR48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR48_SHIFT)) \
                                                  &DMA_ERRH_ERR48_MASK)
#define DMA_ERRH_ERR49_MASK                     0x20000u
#define DMA_ERRH_ERR49_SHIFT                    17u
#define DMA_ERRH_ERR49_WIDTH                    1u
#define DMA_ERRH_ERR49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR49_SHIFT)) \
                                                  &DMA_ERRH_ERR49_MASK)
#define DMA_ERRH_ERR50_MASK                     0x40000u
#define DMA_ERRH_ERR50_SHIFT                    18u
#define DMA_ERRH_ERR50_WIDTH                    1u
#define DMA_ERRH_ERR50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR50_SHIFT)) \
                                                  &DMA_ERRH_ERR50_MASK)
#define DMA_ERRH_ERR51_MASK                     0x80000u
#define DMA_ERRH_ERR51_SHIFT                    19u
#define DMA_ERRH_ERR51_WIDTH                    1u
#define DMA_ERRH_ERR51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR51_SHIFT)) \
                                                  &DMA_ERRH_ERR51_MASK)
#define DMA_ERRH_ERR52_MASK                     0x100000u
#define DMA_ERRH_ERR52_SHIFT                    20u
#define DMA_ERRH_ERR52_WIDTH                    1u
#define DMA_ERRH_ERR52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR52_SHIFT)) \
                                                  &DMA_ERRH_ERR52_MASK)
#define DMA_ERRH_ERR53_MASK                     0x200000u
#define DMA_ERRH_ERR53_SHIFT                    21u
#define DMA_ERRH_ERR53_WIDTH                    1u
#define DMA_ERRH_ERR53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR53_SHIFT)) \
                                                  &DMA_ERRH_ERR53_MASK)
#define DMA_ERRH_ERR54_MASK                     0x400000u
#define DMA_ERRH_ERR54_SHIFT                    22u
#define DMA_ERRH_ERR54_WIDTH                    1u
#define DMA_ERRH_ERR54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR54_SHIFT)) \
                                                  &DMA_ERRH_ERR54_MASK)
#define DMA_ERRH_ERR55_MASK                     0x800000u
#define DMA_ERRH_ERR55_SHIFT                    23u
#define DMA_ERRH_ERR55_WIDTH                    1u
#define DMA_ERRH_ERR55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR55_SHIFT)) \
                                                  &DMA_ERRH_ERR55_MASK)
#define DMA_ERRH_ERR56_MASK                     0x1000000u
#define DMA_ERRH_ERR56_SHIFT                    24u
#define DMA_ERRH_ERR56_WIDTH                    1u
#define DMA_ERRH_ERR56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR56_SHIFT)) \
                                                  &DMA_ERRH_ERR56_MASK)
#define DMA_ERRH_ERR57_MASK                     0x2000000u
#define DMA_ERRH_ERR57_SHIFT                    25u
#define DMA_ERRH_ERR57_WIDTH                    1u
#define DMA_ERRH_ERR57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR57_SHIFT)) \
                                                  &DMA_ERRH_ERR57_MASK)
#define DMA_ERRH_ERR58_MASK                     0x4000000u
#define DMA_ERRH_ERR58_SHIFT                    26u
#define DMA_ERRH_ERR58_WIDTH                    1u
#define DMA_ERRH_ERR58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR58_SHIFT)) \
                                                  &DMA_ERRH_ERR58_MASK)
#define DMA_ERRH_ERR59_MASK                     0x8000000u
#define DMA_ERRH_ERR59_SHIFT                    27u
#define DMA_ERRH_ERR59_WIDTH                    1u
#define DMA_ERRH_ERR59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR59_SHIFT)) \
                                                  &DMA_ERRH_ERR59_MASK)
#define DMA_ERRH_ERR60_MASK                     0x10000000u
#define DMA_ERRH_ERR60_SHIFT                    28u
#define DMA_ERRH_ERR60_WIDTH                    1u
#define DMA_ERRH_ERR60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR60_SHIFT)) \
                                                  &DMA_ERRH_ERR60_MASK)
#define DMA_ERRH_ERR61_MASK                     0x20000000u
#define DMA_ERRH_ERR61_SHIFT                    29u
#define DMA_ERRH_ERR61_WIDTH                    1u
#define DMA_ERRH_ERR61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR61_SHIFT)) \
                                                  &DMA_ERRH_ERR61_MASK)
#define DMA_ERRH_ERR62_MASK                     0x40000000u
#define DMA_ERRH_ERR62_SHIFT                    30u
#define DMA_ERRH_ERR62_WIDTH                    1u
#define DMA_ERRH_ERR62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR62_SHIFT)) \
                                                  &DMA_ERRH_ERR62_MASK)
#define DMA_ERRH_ERR63_MASK                     0x80000000u
#define DMA_ERRH_ERR63_SHIFT                    31u
#define DMA_ERRH_ERR63_WIDTH                    1u
#define DMA_ERRH_ERR63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRH_ERR63_SHIFT)) \
                                                  &DMA_ERRH_ERR63_MASK)
/* ERRL Bit Fields */
#define DMA_ERRL_ERR0_MASK                      0x1u
#define DMA_ERRL_ERR0_SHIFT                     0u
#define DMA_ERRL_ERR0_WIDTH                     1u
#define DMA_ERRL_ERR0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR0_SHIFT)) \
                                                  &DMA_ERRL_ERR0_MASK)
#define DMA_ERRL_ERR1_MASK                      0x2u
#define DMA_ERRL_ERR1_SHIFT                     1u
#define DMA_ERRL_ERR1_WIDTH                     1u
#define DMA_ERRL_ERR1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR1_SHIFT)) \
                                                  &DMA_ERRL_ERR1_MASK)
#define DMA_ERRL_ERR2_MASK                      0x4u
#define DMA_ERRL_ERR2_SHIFT                     2u
#define DMA_ERRL_ERR2_WIDTH                     1u
#define DMA_ERRL_ERR2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR2_SHIFT)) \
                                                  &DMA_ERRL_ERR2_MASK)
#define DMA_ERRL_ERR3_MASK                      0x8u
#define DMA_ERRL_ERR3_SHIFT                     3u
#define DMA_ERRL_ERR3_WIDTH                     1u
#define DMA_ERRL_ERR3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR3_SHIFT)) \
                                                  &DMA_ERRL_ERR3_MASK)
#define DMA_ERRL_ERR4_MASK                      0x10u
#define DMA_ERRL_ERR4_SHIFT                     4u
#define DMA_ERRL_ERR4_WIDTH                     1u
#define DMA_ERRL_ERR4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR4_SHIFT)) \
                                                  &DMA_ERRL_ERR4_MASK)
#define DMA_ERRL_ERR5_MASK                      0x20u
#define DMA_ERRL_ERR5_SHIFT                     5u
#define DMA_ERRL_ERR5_WIDTH                     1u
#define DMA_ERRL_ERR5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR5_SHIFT)) \
                                                  &DMA_ERRL_ERR5_MASK)
#define DMA_ERRL_ERR6_MASK                      0x40u
#define DMA_ERRL_ERR6_SHIFT                     6u
#define DMA_ERRL_ERR6_WIDTH                     1u
#define DMA_ERRL_ERR6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR6_SHIFT)) \
                                                  &DMA_ERRL_ERR6_MASK)
#define DMA_ERRL_ERR7_MASK                      0x80u
#define DMA_ERRL_ERR7_SHIFT                     7u
#define DMA_ERRL_ERR7_WIDTH                     1u
#define DMA_ERRL_ERR7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR7_SHIFT)) \
                                                  &DMA_ERRL_ERR7_MASK)
#define DMA_ERRL_ERR8_MASK                      0x100u
#define DMA_ERRL_ERR8_SHIFT                     8u
#define DMA_ERRL_ERR8_WIDTH                     1u
#define DMA_ERRL_ERR8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR8_SHIFT)) \
                                                  &DMA_ERRL_ERR8_MASK)
#define DMA_ERRL_ERR9_MASK                      0x200u
#define DMA_ERRL_ERR9_SHIFT                     9u
#define DMA_ERRL_ERR9_WIDTH                     1u
#define DMA_ERRL_ERR9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR9_SHIFT)) \
                                                  &DMA_ERRL_ERR9_MASK)
#define DMA_ERRL_ERR10_MASK                     0x400u
#define DMA_ERRL_ERR10_SHIFT                    10u
#define DMA_ERRL_ERR10_WIDTH                    1u
#define DMA_ERRL_ERR10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR10_SHIFT)) \
                                                  &DMA_ERRL_ERR10_MASK)
#define DMA_ERRL_ERR11_MASK                     0x800u
#define DMA_ERRL_ERR11_SHIFT                    11u
#define DMA_ERRL_ERR11_WIDTH                    1u
#define DMA_ERRL_ERR11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR11_SHIFT)) \
                                                  &DMA_ERRL_ERR11_MASK)
#define DMA_ERRL_ERR12_MASK                     0x1000u
#define DMA_ERRL_ERR12_SHIFT                    12u
#define DMA_ERRL_ERR12_WIDTH                    1u
#define DMA_ERRL_ERR12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR12_SHIFT)) \
                                                  &DMA_ERRL_ERR12_MASK)
#define DMA_ERRL_ERR13_MASK                     0x2000u
#define DMA_ERRL_ERR13_SHIFT                    13u
#define DMA_ERRL_ERR13_WIDTH                    1u
#define DMA_ERRL_ERR13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR13_SHIFT)) \
                                                  &DMA_ERRL_ERR13_MASK)
#define DMA_ERRL_ERR14_MASK                     0x4000u
#define DMA_ERRL_ERR14_SHIFT                    14u
#define DMA_ERRL_ERR14_WIDTH                    1u
#define DMA_ERRL_ERR14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR14_SHIFT)) \
                                                  &DMA_ERRL_ERR14_MASK)
#define DMA_ERRL_ERR15_MASK                     0x8000u
#define DMA_ERRL_ERR15_SHIFT                    15u
#define DMA_ERRL_ERR15_WIDTH                    1u
#define DMA_ERRL_ERR15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR15_SHIFT)) \
                                                  &DMA_ERRL_ERR15_MASK)
#define DMA_ERRL_ERR16_MASK                     0x10000u
#define DMA_ERRL_ERR16_SHIFT                    16u
#define DMA_ERRL_ERR16_WIDTH                    1u
#define DMA_ERRL_ERR16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR16_SHIFT)) \
                                                  &DMA_ERRL_ERR16_MASK)
#define DMA_ERRL_ERR17_MASK                     0x20000u
#define DMA_ERRL_ERR17_SHIFT                    17u
#define DMA_ERRL_ERR17_WIDTH                    1u
#define DMA_ERRL_ERR17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR17_SHIFT)) \
                                                  &DMA_ERRL_ERR17_MASK)
#define DMA_ERRL_ERR18_MASK                     0x40000u
#define DMA_ERRL_ERR18_SHIFT                    18u
#define DMA_ERRL_ERR18_WIDTH                    1u
#define DMA_ERRL_ERR18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR18_SHIFT)) \
                                                  &DMA_ERRL_ERR18_MASK)
#define DMA_ERRL_ERR19_MASK                     0x80000u
#define DMA_ERRL_ERR19_SHIFT                    19u
#define DMA_ERRL_ERR19_WIDTH                    1u
#define DMA_ERRL_ERR19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR19_SHIFT)) \
                                                  &DMA_ERRL_ERR19_MASK)
#define DMA_ERRL_ERR20_MASK                     0x100000u
#define DMA_ERRL_ERR20_SHIFT                    20u
#define DMA_ERRL_ERR20_WIDTH                    1u
#define DMA_ERRL_ERR20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR20_SHIFT)) \
                                                  &DMA_ERRL_ERR20_MASK)
#define DMA_ERRL_ERR21_MASK                     0x200000u
#define DMA_ERRL_ERR21_SHIFT                    21u
#define DMA_ERRL_ERR21_WIDTH                    1u
#define DMA_ERRL_ERR21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR21_SHIFT)) \
                                                  &DMA_ERRL_ERR21_MASK)
#define DMA_ERRL_ERR22_MASK                     0x400000u
#define DMA_ERRL_ERR22_SHIFT                    22u
#define DMA_ERRL_ERR22_WIDTH                    1u
#define DMA_ERRL_ERR22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR22_SHIFT)) \
                                                  &DMA_ERRL_ERR22_MASK)
#define DMA_ERRL_ERR23_MASK                     0x800000u
#define DMA_ERRL_ERR23_SHIFT                    23u
#define DMA_ERRL_ERR23_WIDTH                    1u
#define DMA_ERRL_ERR23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR23_SHIFT)) \
                                                  &DMA_ERRL_ERR23_MASK)
#define DMA_ERRL_ERR24_MASK                     0x1000000u
#define DMA_ERRL_ERR24_SHIFT                    24u
#define DMA_ERRL_ERR24_WIDTH                    1u
#define DMA_ERRL_ERR24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR24_SHIFT)) \
                                                  &DMA_ERRL_ERR24_MASK)
#define DMA_ERRL_ERR25_MASK                     0x2000000u
#define DMA_ERRL_ERR25_SHIFT                    25u
#define DMA_ERRL_ERR25_WIDTH                    1u
#define DMA_ERRL_ERR25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR25_SHIFT)) \
                                                  &DMA_ERRL_ERR25_MASK)
#define DMA_ERRL_ERR26_MASK                     0x4000000u
#define DMA_ERRL_ERR26_SHIFT                    26u
#define DMA_ERRL_ERR26_WIDTH                    1u
#define DMA_ERRL_ERR26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR26_SHIFT)) \
                                                  &DMA_ERRL_ERR26_MASK)
#define DMA_ERRL_ERR27_MASK                     0x8000000u
#define DMA_ERRL_ERR27_SHIFT                    27u
#define DMA_ERRL_ERR27_WIDTH                    1u
#define DMA_ERRL_ERR27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR27_SHIFT)) \
                                                  &DMA_ERRL_ERR27_MASK)
#define DMA_ERRL_ERR28_MASK                     0x10000000u
#define DMA_ERRL_ERR28_SHIFT                    28u
#define DMA_ERRL_ERR28_WIDTH                    1u
#define DMA_ERRL_ERR28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR28_SHIFT)) \
                                                  &DMA_ERRL_ERR28_MASK)
#define DMA_ERRL_ERR29_MASK                     0x20000000u
#define DMA_ERRL_ERR29_SHIFT                    29u
#define DMA_ERRL_ERR29_WIDTH                    1u
#define DMA_ERRL_ERR29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR29_SHIFT)) \
                                                  &DMA_ERRL_ERR29_MASK)
#define DMA_ERRL_ERR30_MASK                     0x40000000u
#define DMA_ERRL_ERR30_SHIFT                    30u
#define DMA_ERRL_ERR30_WIDTH                    1u
#define DMA_ERRL_ERR30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR30_SHIFT)) \
                                                  &DMA_ERRL_ERR30_MASK)
#define DMA_ERRL_ERR31_MASK                     0x80000000u
#define DMA_ERRL_ERR31_SHIFT                    31u
#define DMA_ERRL_ERR31_WIDTH                    1u
#define DMA_ERRL_ERR31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_ERRL_ERR31_SHIFT)) \
                                                  &DMA_ERRL_ERR31_MASK)
/* HRSH Bit Fields */
#define DMA_HRSH_HRS32_MASK                     0x1u
#define DMA_HRSH_HRS32_SHIFT                    0u
#define DMA_HRSH_HRS32_WIDTH                    1u
#define DMA_HRSH_HRS32(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS32_SHIFT)) \
                                                  &DMA_HRSH_HRS32_MASK)
#define DMA_HRSH_HRS33_MASK                     0x2u
#define DMA_HRSH_HRS33_SHIFT                    1u
#define DMA_HRSH_HRS33_WIDTH                    1u
#define DMA_HRSH_HRS33(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS33_SHIFT)) \
                                                  &DMA_HRSH_HRS33_MASK)
#define DMA_HRSH_HRS34_MASK                     0x4u
#define DMA_HRSH_HRS34_SHIFT                    2u
#define DMA_HRSH_HRS34_WIDTH                    1u
#define DMA_HRSH_HRS34(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS34_SHIFT)) \
                                                  &DMA_HRSH_HRS34_MASK)
#define DMA_HRSH_HRS35_MASK                     0x8u
#define DMA_HRSH_HRS35_SHIFT                    3u
#define DMA_HRSH_HRS35_WIDTH                    1u
#define DMA_HRSH_HRS35(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS35_SHIFT)) \
                                                  &DMA_HRSH_HRS35_MASK)
#define DMA_HRSH_HRS36_MASK                     0x10u
#define DMA_HRSH_HRS36_SHIFT                    4u
#define DMA_HRSH_HRS36_WIDTH                    1u
#define DMA_HRSH_HRS36(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS36_SHIFT)) \
                                                  &DMA_HRSH_HRS36_MASK)
#define DMA_HRSH_HRS37_MASK                     0x20u
#define DMA_HRSH_HRS37_SHIFT                    5u
#define DMA_HRSH_HRS37_WIDTH                    1u
#define DMA_HRSH_HRS37(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS37_SHIFT)) \
                                                  &DMA_HRSH_HRS37_MASK)
#define DMA_HRSH_HRS38_MASK                     0x40u
#define DMA_HRSH_HRS38_SHIFT                    6u
#define DMA_HRSH_HRS38_WIDTH                    1u
#define DMA_HRSH_HRS38(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS38_SHIFT)) \
                                                  &DMA_HRSH_HRS38_MASK)
#define DMA_HRSH_HRS39_MASK                     0x80u
#define DMA_HRSH_HRS39_SHIFT                    7u
#define DMA_HRSH_HRS39_WIDTH                    1u
#define DMA_HRSH_HRS39(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS39_SHIFT)) \
                                                  &DMA_HRSH_HRS39_MASK)
#define DMA_HRSH_HRS40_MASK                     0x100u
#define DMA_HRSH_HRS40_SHIFT                    8u
#define DMA_HRSH_HRS40_WIDTH                    1u
#define DMA_HRSH_HRS40(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS40_SHIFT)) \
                                                  &DMA_HRSH_HRS40_MASK)
#define DMA_HRSH_HRS41_MASK                     0x200u
#define DMA_HRSH_HRS41_SHIFT                    9u
#define DMA_HRSH_HRS41_WIDTH                    1u
#define DMA_HRSH_HRS41(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS41_SHIFT)) \
                                                  &DMA_HRSH_HRS41_MASK)
#define DMA_HRSH_HRS42_MASK                     0x400u
#define DMA_HRSH_HRS42_SHIFT                    10u
#define DMA_HRSH_HRS42_WIDTH                    1u
#define DMA_HRSH_HRS42(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS42_SHIFT)) \
                                                  &DMA_HRSH_HRS42_MASK)
#define DMA_HRSH_HRS43_MASK                     0x800u
#define DMA_HRSH_HRS43_SHIFT                    11u
#define DMA_HRSH_HRS43_WIDTH                    1u
#define DMA_HRSH_HRS43(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS43_SHIFT)) \
                                                  &DMA_HRSH_HRS43_MASK)
#define DMA_HRSH_HRS44_MASK                     0x1000u
#define DMA_HRSH_HRS44_SHIFT                    12u
#define DMA_HRSH_HRS44_WIDTH                    1u
#define DMA_HRSH_HRS44(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS44_SHIFT)) \
                                                  &DMA_HRSH_HRS44_MASK)
#define DMA_HRSH_HRS45_MASK                     0x2000u
#define DMA_HRSH_HRS45_SHIFT                    13u
#define DMA_HRSH_HRS45_WIDTH                    1u
#define DMA_HRSH_HRS45(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS45_SHIFT)) \
                                                  &DMA_HRSH_HRS45_MASK)
#define DMA_HRSH_HRS46_MASK                     0x4000u
#define DMA_HRSH_HRS46_SHIFT                    14u
#define DMA_HRSH_HRS46_WIDTH                    1u
#define DMA_HRSH_HRS46(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS46_SHIFT)) \
                                                  &DMA_HRSH_HRS46_MASK)
#define DMA_HRSH_HRS47_MASK                     0x8000u
#define DMA_HRSH_HRS47_SHIFT                    15u
#define DMA_HRSH_HRS47_WIDTH                    1u
#define DMA_HRSH_HRS47(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS47_SHIFT)) \
                                                  &DMA_HRSH_HRS47_MASK)
#define DMA_HRSH_HRS48_MASK                     0x10000u
#define DMA_HRSH_HRS48_SHIFT                    16u
#define DMA_HRSH_HRS48_WIDTH                    1u
#define DMA_HRSH_HRS48(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS48_SHIFT)) \
                                                  &DMA_HRSH_HRS48_MASK)
#define DMA_HRSH_HRS49_MASK                     0x20000u
#define DMA_HRSH_HRS49_SHIFT                    17u
#define DMA_HRSH_HRS49_WIDTH                    1u
#define DMA_HRSH_HRS49(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS49_SHIFT)) \
                                                  &DMA_HRSH_HRS49_MASK)
#define DMA_HRSH_HRS50_MASK                     0x40000u
#define DMA_HRSH_HRS50_SHIFT                    18u
#define DMA_HRSH_HRS50_WIDTH                    1u
#define DMA_HRSH_HRS50(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS50_SHIFT)) \
                                                  &DMA_HRSH_HRS50_MASK)
#define DMA_HRSH_HRS51_MASK                     0x80000u
#define DMA_HRSH_HRS51_SHIFT                    19u
#define DMA_HRSH_HRS51_WIDTH                    1u
#define DMA_HRSH_HRS51(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS51_SHIFT)) \
                                                  &DMA_HRSH_HRS51_MASK)
#define DMA_HRSH_HRS52_MASK                     0x100000u
#define DMA_HRSH_HRS52_SHIFT                    20u
#define DMA_HRSH_HRS52_WIDTH                    1u
#define DMA_HRSH_HRS52(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS52_SHIFT)) \
                                                  &DMA_HRSH_HRS52_MASK)
#define DMA_HRSH_HRS53_MASK                     0x200000u
#define DMA_HRSH_HRS53_SHIFT                    21u
#define DMA_HRSH_HRS53_WIDTH                    1u
#define DMA_HRSH_HRS53(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS53_SHIFT)) \
                                                  &DMA_HRSH_HRS53_MASK)
#define DMA_HRSH_HRS54_MASK                     0x400000u
#define DMA_HRSH_HRS54_SHIFT                    22u
#define DMA_HRSH_HRS54_WIDTH                    1u
#define DMA_HRSH_HRS54(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS54_SHIFT)) \
                                                  &DMA_HRSH_HRS54_MASK)
#define DMA_HRSH_HRS55_MASK                     0x800000u
#define DMA_HRSH_HRS55_SHIFT                    23u
#define DMA_HRSH_HRS55_WIDTH                    1u
#define DMA_HRSH_HRS55(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS55_SHIFT)) \
                                                  &DMA_HRSH_HRS55_MASK)
#define DMA_HRSH_HRS56_MASK                     0x1000000u
#define DMA_HRSH_HRS56_SHIFT                    24u
#define DMA_HRSH_HRS56_WIDTH                    1u
#define DMA_HRSH_HRS56(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS56_SHIFT)) \
                                                  &DMA_HRSH_HRS56_MASK)
#define DMA_HRSH_HRS57_MASK                     0x2000000u
#define DMA_HRSH_HRS57_SHIFT                    25u
#define DMA_HRSH_HRS57_WIDTH                    1u
#define DMA_HRSH_HRS57(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS57_SHIFT)) \
                                                  &DMA_HRSH_HRS57_MASK)
#define DMA_HRSH_HRS58_MASK                     0x4000000u
#define DMA_HRSH_HRS58_SHIFT                    26u
#define DMA_HRSH_HRS58_WIDTH                    1u
#define DMA_HRSH_HRS58(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS58_SHIFT)) \
                                                  &DMA_HRSH_HRS58_MASK)
#define DMA_HRSH_HRS59_MASK                     0x8000000u
#define DMA_HRSH_HRS59_SHIFT                    27u
#define DMA_HRSH_HRS59_WIDTH                    1u
#define DMA_HRSH_HRS59(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS59_SHIFT)) \
                                                  &DMA_HRSH_HRS59_MASK)
#define DMA_HRSH_HRS60_MASK                     0x10000000u
#define DMA_HRSH_HRS60_SHIFT                    28u
#define DMA_HRSH_HRS60_WIDTH                    1u
#define DMA_HRSH_HRS60(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS60_SHIFT)) \
                                                  &DMA_HRSH_HRS60_MASK)
#define DMA_HRSH_HRS61_MASK                     0x20000000u
#define DMA_HRSH_HRS61_SHIFT                    29u
#define DMA_HRSH_HRS61_WIDTH                    1u
#define DMA_HRSH_HRS61(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS61_SHIFT)) \
                                                  &DMA_HRSH_HRS61_MASK)
#define DMA_HRSH_HRS62_MASK                     0x40000000u
#define DMA_HRSH_HRS62_SHIFT                    30u
#define DMA_HRSH_HRS62_WIDTH                    1u
#define DMA_HRSH_HRS62(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS62_SHIFT)) \
                                                  &DMA_HRSH_HRS62_MASK)
#define DMA_HRSH_HRS63_MASK                     0x80000000u
#define DMA_HRSH_HRS63_SHIFT                    31u
#define DMA_HRSH_HRS63_WIDTH                    1u
#define DMA_HRSH_HRS63(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSH_HRS63_SHIFT)) \
                                                  &DMA_HRSH_HRS63_MASK)
/* HRSL Bit Fields */
#define DMA_HRSL_HRS0_MASK                      0x1u
#define DMA_HRSL_HRS0_SHIFT                     0u
#define DMA_HRSL_HRS0_WIDTH                     1u
#define DMA_HRSL_HRS0(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS0_SHIFT)) \
                                                  &DMA_HRSL_HRS0_MASK)
#define DMA_HRSL_HRS1_MASK                      0x2u
#define DMA_HRSL_HRS1_SHIFT                     1u
#define DMA_HRSL_HRS1_WIDTH                     1u
#define DMA_HRSL_HRS1(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS1_SHIFT)) \
                                                  &DMA_HRSL_HRS1_MASK)
#define DMA_HRSL_HRS2_MASK                      0x4u
#define DMA_HRSL_HRS2_SHIFT                     2u
#define DMA_HRSL_HRS2_WIDTH                     1u
#define DMA_HRSL_HRS2(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS2_SHIFT)) \
                                                  &DMA_HRSL_HRS2_MASK)
#define DMA_HRSL_HRS3_MASK                      0x8u
#define DMA_HRSL_HRS3_SHIFT                     3u
#define DMA_HRSL_HRS3_WIDTH                     1u
#define DMA_HRSL_HRS3(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS3_SHIFT)) \
                                                  &DMA_HRSL_HRS3_MASK)
#define DMA_HRSL_HRS4_MASK                      0x10u
#define DMA_HRSL_HRS4_SHIFT                     4u
#define DMA_HRSL_HRS4_WIDTH                     1u
#define DMA_HRSL_HRS4(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS4_SHIFT)) \
                                                  &DMA_HRSL_HRS4_MASK)
#define DMA_HRSL_HRS5_MASK                      0x20u
#define DMA_HRSL_HRS5_SHIFT                     5u
#define DMA_HRSL_HRS5_WIDTH                     1u
#define DMA_HRSL_HRS5(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS5_SHIFT)) \
                                                  &DMA_HRSL_HRS5_MASK)
#define DMA_HRSL_HRS6_MASK                      0x40u
#define DMA_HRSL_HRS6_SHIFT                     6u
#define DMA_HRSL_HRS6_WIDTH                     1u
#define DMA_HRSL_HRS6(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS6_SHIFT)) \
                                                  &DMA_HRSL_HRS6_MASK)
#define DMA_HRSL_HRS7_MASK                      0x80u
#define DMA_HRSL_HRS7_SHIFT                     7u
#define DMA_HRSL_HRS7_WIDTH                     1u
#define DMA_HRSL_HRS7(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS7_SHIFT)) \
                                                  &DMA_HRSL_HRS7_MASK)
#define DMA_HRSL_HRS8_MASK                      0x100u
#define DMA_HRSL_HRS8_SHIFT                     8u
#define DMA_HRSL_HRS8_WIDTH                     1u
#define DMA_HRSL_HRS8(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS8_SHIFT)) \
                                                  &DMA_HRSL_HRS8_MASK)
#define DMA_HRSL_HRS9_MASK                      0x200u
#define DMA_HRSL_HRS9_SHIFT                     9u
#define DMA_HRSL_HRS9_WIDTH                     1u
#define DMA_HRSL_HRS9(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS9_SHIFT)) \
                                                  &DMA_HRSL_HRS9_MASK)
#define DMA_HRSL_HRS10_MASK                     0x400u
#define DMA_HRSL_HRS10_SHIFT                    10u
#define DMA_HRSL_HRS10_WIDTH                    1u
#define DMA_HRSL_HRS10(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS10_SHIFT)) \
                                                  &DMA_HRSL_HRS10_MASK)
#define DMA_HRSL_HRS11_MASK                     0x800u
#define DMA_HRSL_HRS11_SHIFT                    11u
#define DMA_HRSL_HRS11_WIDTH                    1u
#define DMA_HRSL_HRS11(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS11_SHIFT)) \
                                                  &DMA_HRSL_HRS11_MASK)
#define DMA_HRSL_HRS12_MASK                     0x1000u
#define DMA_HRSL_HRS12_SHIFT                    12u
#define DMA_HRSL_HRS12_WIDTH                    1u
#define DMA_HRSL_HRS12(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS12_SHIFT)) \
                                                  &DMA_HRSL_HRS12_MASK)
#define DMA_HRSL_HRS13_MASK                     0x2000u
#define DMA_HRSL_HRS13_SHIFT                    13u
#define DMA_HRSL_HRS13_WIDTH                    1u
#define DMA_HRSL_HRS13(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS13_SHIFT)) \
                                                  &DMA_HRSL_HRS13_MASK)
#define DMA_HRSL_HRS14_MASK                     0x4000u
#define DMA_HRSL_HRS14_SHIFT                    14u
#define DMA_HRSL_HRS14_WIDTH                    1u
#define DMA_HRSL_HRS14(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS14_SHIFT)) \
                                                  &DMA_HRSL_HRS14_MASK)
#define DMA_HRSL_HRS15_MASK                     0x8000u
#define DMA_HRSL_HRS15_SHIFT                    15u
#define DMA_HRSL_HRS15_WIDTH                    1u
#define DMA_HRSL_HRS15(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS15_SHIFT)) \
                                                  &DMA_HRSL_HRS15_MASK)
#define DMA_HRSL_HRS16_MASK                     0x10000u
#define DMA_HRSL_HRS16_SHIFT                    16u
#define DMA_HRSL_HRS16_WIDTH                    1u
#define DMA_HRSL_HRS16(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS16_SHIFT)) \
                                                  &DMA_HRSL_HRS16_MASK)
#define DMA_HRSL_HRS17_MASK                     0x20000u
#define DMA_HRSL_HRS17_SHIFT                    17u
#define DMA_HRSL_HRS17_WIDTH                    1u
#define DMA_HRSL_HRS17(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS17_SHIFT)) \
                                                  &DMA_HRSL_HRS17_MASK)
#define DMA_HRSL_HRS18_MASK                     0x40000u
#define DMA_HRSL_HRS18_SHIFT                    18u
#define DMA_HRSL_HRS18_WIDTH                    1u
#define DMA_HRSL_HRS18(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS18_SHIFT)) \
                                                  &DMA_HRSL_HRS18_MASK)
#define DMA_HRSL_HRS19_MASK                     0x80000u
#define DMA_HRSL_HRS19_SHIFT                    19u
#define DMA_HRSL_HRS19_WIDTH                    1u
#define DMA_HRSL_HRS19(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS19_SHIFT)) \
                                                  &DMA_HRSL_HRS19_MASK)
#define DMA_HRSL_HRS20_MASK                     0x100000u
#define DMA_HRSL_HRS20_SHIFT                    20u
#define DMA_HRSL_HRS20_WIDTH                    1u
#define DMA_HRSL_HRS20(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS20_SHIFT)) \
                                                  &DMA_HRSL_HRS20_MASK)
#define DMA_HRSL_HRS21_MASK                     0x200000u
#define DMA_HRSL_HRS21_SHIFT                    21u
#define DMA_HRSL_HRS21_WIDTH                    1u
#define DMA_HRSL_HRS21(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS21_SHIFT)) \
                                                  &DMA_HRSL_HRS21_MASK)
#define DMA_HRSL_HRS22_MASK                     0x400000u
#define DMA_HRSL_HRS22_SHIFT                    22u
#define DMA_HRSL_HRS22_WIDTH                    1u
#define DMA_HRSL_HRS22(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS22_SHIFT)) \
                                                  &DMA_HRSL_HRS22_MASK)
#define DMA_HRSL_HRS23_MASK                     0x800000u
#define DMA_HRSL_HRS23_SHIFT                    23u
#define DMA_HRSL_HRS23_WIDTH                    1u
#define DMA_HRSL_HRS23(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS23_SHIFT)) \
                                                  &DMA_HRSL_HRS23_MASK)
#define DMA_HRSL_HRS24_MASK                     0x1000000u
#define DMA_HRSL_HRS24_SHIFT                    24u
#define DMA_HRSL_HRS24_WIDTH                    1u
#define DMA_HRSL_HRS24(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS24_SHIFT)) \
                                                  &DMA_HRSL_HRS24_MASK)
#define DMA_HRSL_HRS25_MASK                     0x2000000u
#define DMA_HRSL_HRS25_SHIFT                    25u
#define DMA_HRSL_HRS25_WIDTH                    1u
#define DMA_HRSL_HRS25(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS25_SHIFT)) \
                                                  &DMA_HRSL_HRS25_MASK)
#define DMA_HRSL_HRS26_MASK                     0x4000000u
#define DMA_HRSL_HRS26_SHIFT                    26u
#define DMA_HRSL_HRS26_WIDTH                    1u
#define DMA_HRSL_HRS26(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS26_SHIFT)) \
                                                  &DMA_HRSL_HRS26_MASK)
#define DMA_HRSL_HRS27_MASK                     0x8000000u
#define DMA_HRSL_HRS27_SHIFT                    27u
#define DMA_HRSL_HRS27_WIDTH                    1u
#define DMA_HRSL_HRS27(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS27_SHIFT)) \
                                                  &DMA_HRSL_HRS27_MASK)
#define DMA_HRSL_HRS28_MASK                     0x10000000u
#define DMA_HRSL_HRS28_SHIFT                    28u
#define DMA_HRSL_HRS28_WIDTH                    1u
#define DMA_HRSL_HRS28(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS28_SHIFT)) \
                                                  &DMA_HRSL_HRS28_MASK)
#define DMA_HRSL_HRS29_MASK                     0x20000000u
#define DMA_HRSL_HRS29_SHIFT                    29u
#define DMA_HRSL_HRS29_WIDTH                    1u
#define DMA_HRSL_HRS29(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS29_SHIFT)) \
                                                  &DMA_HRSL_HRS29_MASK)
#define DMA_HRSL_HRS30_MASK                     0x40000000u
#define DMA_HRSL_HRS30_SHIFT                    30u
#define DMA_HRSL_HRS30_WIDTH                    1u
#define DMA_HRSL_HRS30(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS30_SHIFT)) \
                                                  &DMA_HRSL_HRS30_MASK)
#define DMA_HRSL_HRS31_MASK                     0x80000000u
#define DMA_HRSL_HRS31_SHIFT                    31u
#define DMA_HRSL_HRS31_WIDTH                    1u
#define DMA_HRSL_HRS31(x)                       (((uint32)(((uint32)(x)) \
                                                  << DMA_HRSL_HRS31_SHIFT)) \
                                                  &DMA_HRSL_HRS31_MASK)
/* GPOR Bit Fields */
#define DMA_GPOR_GPOR_MASK                      0xFFFFFFFFu
#define DMA_GPOR_GPOR_SHIFT                     0u
#define DMA_GPOR_GPOR_WIDTH                     32u
#define DMA_GPOR_GPOR(x)                        (((uint32)(((uint32)(x)) \
                                                  << DMA_GPOR_GPOR_SHIFT)) \
                                                  &DMA_GPOR_GPOR_MASK)
/* DCHPRI Bit Fields */
#define DMA_DCHPRI_CHPRI_MASK                   0xFu
#define DMA_DCHPRI_CHPRI_SHIFT                  0u
#define DMA_DCHPRI_CHPRI_WIDTH                  4u
#define DMA_DCHPRI_CHPRI(x)                     (uint8)(((((uint32)(x)) \
                                                  << DMA_DCHPRI_CHPRI_SHIFT)) \
                                                  &DMA_DCHPRI_CHPRI_MASK)
#define DMA_DCHPRI_GRPPRI_MASK                  0x30u
#define DMA_DCHPRI_GRPPRI_SHIFT                 4u
#define DMA_DCHPRI_GRPPRI_WIDTH                 2u
#define DMA_DCHPRI_GRPPRI(x)                    (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHPRI_GRPPRI_SHIFT)) \
                                                  &DMA_DCHPRI_GRPPRI_MASK)
#define DMA_DCHPRI_DPA_MASK                     0x40u
#define DMA_DCHPRI_DPA_SHIFT                    6u
#define DMA_DCHPRI_DPA_WIDTH                    1u
#define DMA_DCHPRI_DPA(x)                       (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHPRI_DPA_SHIFT)) \
                                                  &DMA_DCHPRI_DPA_MASK)
#define DMA_DCHPRI_ECP_MASK                     0x80u
#define DMA_DCHPRI_ECP_SHIFT                    7u
#define DMA_DCHPRI_ECP_WIDTH                    1u
#define DMA_DCHPRI_ECP(x)                       (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHPRI_ECP_SHIFT)) \
                                                  &DMA_DCHPRI_ECP_MASK)

/* MASTER ID */
#define DMA_DCHMID_MID_MASK                   0xFu
#define DMA_DCHMID_MID_SHIFT                  0u
#define DMA_DCHMID_MID_WIDTH                  4u
#define DMA_DCHMID_MID(x)                     (uint8)(((((uint32)(x)) \
                                                  << DMA_DCHMID_MID_SHIFT)) \
                                                  &DMA_DCHMID_MID_MASK)
#define DMA_DCHMID_PAL_MASK                     0x40u
#define DMA_DCHMID_PAL_SHIFT                    6u
#define DMA_DCHMID_PAL_WIDTH                    1u
#define DMA_DCHMID_PAL(x)                       (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHMID_PAL_SHIFT)) \
                                                  &DMA_DCHMID_PAL_MASK)
#define DMA_DCHMID_EMI_MASK                     0x80u
#define DMA_DCHMID_EMI_SHIFT                    7u
#define DMA_DCHMID_EMI_WIDTH                    1u
#define DMA_DCHMID_EMI(x)                       (((uint8)(((uint8)(x)) \
                                                  << DMA_DCHMID_EMI_SHIFT)) \
                                                  &DMA_DCHMID_EMI_MASK)

/* TCD_SADDR Bit Fields */
#define DMA_TCD_SADDR_SADDR_MASK                0xFFFFFFFFu
#define DMA_TCD_SADDR_SADDR_SHIFT               0u
#define DMA_TCD_SADDR_SADDR_WIDTH               32u
#define DMA_TCD_SADDR_SADDR(x)                  (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_SADDR_SADDR_SHIFT)) \
                                                  &DMA_TCD_SADDR_SADDR_MASK)
/* TCD_ATTR Bit Fields */
#define DMA_TCD_ATTR_DSIZE_MASK                 0x7U
#define DMA_TCD_ATTR_DSIZE_SHIFT                0u
#define DMA_TCD_ATTR_DSIZE_WIDTH                3u
#define DMA_TCD_ATTR_DSIZE(x)                   (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_ATTR_DSIZE_SHIFT)) \
                                                  &DMA_TCD_ATTR_DSIZE_MASK)
#define DMA_TCD_ATTR_DMOD_MASK                  0xF8u
#define DMA_TCD_ATTR_DMOD_SHIFT                 3u
#define DMA_TCD_ATTR_DMOD_WIDTH                 5u
#define DMA_TCD_ATTR_DMOD(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_ATTR_DMOD_SHIFT)) \
                                                  &DMA_TCD_ATTR_DMOD_MASK)
#define DMA_TCD_ATTR_SSIZE_MASK                 0x700u
#define DMA_TCD_ATTR_SSIZE_SHIFT                8u
#define DMA_TCD_ATTR_SSIZE_WIDTH                3u
#define DMA_TCD_ATTR_SSIZE(x)                   (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_ATTR_SSIZE_SHIFT)) \
                                                  &DMA_TCD_ATTR_SSIZE_MASK)
#define DMA_TCD_ATTR_SMOD_MASK                  0xF800u
#define DMA_TCD_ATTR_SMOD_SHIFT                 11u
#define DMA_TCD_ATTR_SMOD_WIDTH                 5u
#define DMA_TCD_ATTR_SMOD(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_ATTR_SMOD_SHIFT)) \
                                                  &DMA_TCD_ATTR_SMOD_MASK)
/* TCD_SOFF Bit Fields */
#define DMA_TCD_SOFF_SOFF_MASK                  0xFFFFu
#define DMA_TCD_SOFF_SOFF_SHIFT                 0u
#define DMA_TCD_SOFF_SOFF_WIDTH                 16u
#define DMA_TCD_SOFF_SOFF(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_SOFF_SOFF_SHIFT)) \
                                                  &DMA_TCD_SOFF_SOFF_MASK)
/* TCD_NBYTES_MLNO Bit Fields */
#define DMA_TCD_NBYTES_MLNO_NBYTE_MASK          0xFFFFFFFFu
#define DMA_TCD_NBYTES_MLNO_NBYTE_SHIFT         0u
#define DMA_TCD_NBYTES_MLNO_NBYTE_WIDTH         32u
#define DMA_TCD_NBYTES_MLNO_NBYTES(x)           (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NBYTES_MLNO_NBYTE_SHIFT)) \
                                                  &DMA_TCD_NBYTES_MLNO_NBYTE_MASK)
/* TCD_NBYTES_MLOFFNO Bit Fields */
#define DMA_TCD_NBYTES_MLOFFNO_NB_MASK          0x3FFFFFFFu
#define DMA_TCD_NBYTES_MLOFFNO_NB_SHIFT         0u
#define DMA_TCD_NBYTES_MLOFFNO_NB_WIDTH         30u
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)        (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NBYTES_MLOFFNO_NB_SHIFT)) \
                                                  &DMA_TCD_NBYTES_MLOFFNO_NB_MASK)
#define DMA_TCD_NB_MLOFFNO_DMLOE_MASK           0x40000000u
#define DMA_TCD_NB_MLOFFNO_DMLOE_SHIFT          30u
#define DMA_TCD_NB_MLOFFNO_DMLOE_WIDTH          1u
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE(x)         (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFNO_DMLOE_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFNO_DMLOE_MASK)
#define DMA_TCD_NB_MLOFFNO_SMLOE_MASK           0x80000000u
#define DMA_TCD_NB_MLOFFNO_SMLOE_SHIFT          31u
#define DMA_TCD_NB_MLOFFNO_SMLOE_WIDTH          1u
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE(x)         (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFNO_SMLOE_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFNO_SMLOE_MASK)
/* TCD_NBYTES_MLOFFYES Bit Fields */
#define DMA_TCD_NB_MLOFFYES_NB_MASK             0x3FFUL
#define DMA_TCD_NB_MLOFFYES_NB_SHIFT            0u  /* PRQA S 0791 */
#define DMA_TCD_NB_MLOFFYES_NB_WIDTH            10u /* PRQA S 0791 */
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)       (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFYES_NB_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFYES_NB_MASK)
#define DMA_TCD_NB_MLOFFYES_MLOFF_MASK          0x3FFFFC00u
#define DMA_TCD_NB_MLOFFYES_MLOFF_SHIFT         10u
#define DMA_TCD_NB_MLOFFYES_MLOFF_WIDTH         20u
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)        (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFYES_MLOFF_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFYES_MLOFF_MASK)
#define DMA_TCD_NB_MLOFFYES_DMLOE_MASK          0x40000000u
#define DMA_TCD_NB_MLOFFYES_DMLOE_SHIFT         30u
#define DMA_TCD_NB_MLOFFYES_DMLOE_WIDTH         1u
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE(x)        (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFYES_DMLOE_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFYES_DMLOE_MASK)
#define DMA_TCD_NB_MLOFFYES_SMLOE_MASK          0x80000000u
#define DMA_TCD_NB_MLOFFYES_SMLOE_SHIFT         31u
#define DMA_TCD_NB_MLOFFYES_SMLOE_WIDTH         1u
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE(x)        (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_NB_MLOFFYES_SMLOE_SHIFT)) \
                                                  &DMA_TCD_NB_MLOFFYES_SMLOE_MASK)
/* TCD_SLAST Bit Fields */
#define DMA_TCD_SLAST_SLAST_MASK                0xFFFFFFFFu
#define DMA_TCD_SLAST_SLAST_SHIFT               0u
#define DMA_TCD_SLAST_SLAST_WIDTH               32u
#define DMA_TCD_SLAST_SLAST(x)                  (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_SLAST_SLAST_SHIFT)) \
                                                  &DMA_TCD_SLAST_SLAST_MASK)
/* TCD_DADDR Bit Fields */
#define DMA_TCD_DADDR_DADDR_MASK                0xFFFFFFFFu
#define DMA_TCD_DADDR_DADDR_SHIFT               0u
#define DMA_TCD_DADDR_DADDR_WIDTH               32u
#define DMA_TCD_DADDR_DADDR(x)                  (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_DADDR_DADDR_SHIFT)) \
                                                  &DMA_TCD_DADDR_DADDR_MASK)
/* TCD_CITER_ELINKNO Bit Fields */
#define DMA_TCD_CITER_ELINKNO_CTR_MASK          0x7FFFu
#define DMA_TCD_CITER_ELINKNO_CTR_SHIFT         0u
#define DMA_TCD_CITER_ELINKNO_CTR_WIDTH         15u
#define DMA_TCD_CITER_ELINKNO_CITER(x)          (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CITER_ELINKNO_CTR_SHIFT)) \
                                                  &DMA_TCD_CITER_ELINKNO_CTR_MASK)
#define DMA_TCD_CITER_ELINKNO_ELK_MASK          0x8000u
#define DMA_TCD_CITER_ELINKNO_ELK_SHIFT         15u
#define DMA_TCD_CITER_ELINKNO_ELK_WIDTH         1u
#define DMA_TCD_CITER_ELINKNO_ELINK(x)          (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CITER_ELINKNO_ELK_SHIFT)) \
                                                  &DMA_TCD_CITER_ELINKNO_ELK_MASK)
/* TCD_CITER_ELINKYES Bit Fields */
#define DMA_TCD_CTR_ELKYES_CITER_MASK           0x1FFu
#define DMA_TCD_CTR_ELKYES_CITER_SHIFT          0u
#define DMA_TCD_CTR_ELKYES_CITER_WIDTH          9u
#define DMA_TCD_CITER_ELINKYES_CITER(x)         (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CTR_ELKYES_CITER_SHIFT)) \
                                                  &DMA_TCD_CTR_ELKYES_CITER_MASK)
#define DMA_TCD_CTR_ELNKYES_LNKCH_MASK          0x7E00u
#define DMA_TCD_CTR_ELNKYES_LNKCH_SHIFT         9u
#define DMA_TCD_CTR_ELNKYES_LNKCH_WIDTH         6u
#define DMA_TCD_CITER_ELINKYES_LINKCH(x)        (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CTR_ELNKYES_LNKCH_SHIFT)) \
                                                  &DMA_TCD_CTR_ELNKYES_LNKCH_MASK)
#define DMA_TCD_CTR_ELINKYES_ELK_MASK           0x8000u
#define DMA_TCD_CTR_ELINKYES_ELK_SHIFT          15u
#define DMA_TCD_CTR_ELINKYES_ELK_WIDTH          1u
#define DMA_TCD_CITER_ELINKYES_ELINK(x)         (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CTR_ELINKYES_ELK_SHIFT)) \
                                                  &DMA_TCD_CTR_ELINKYES_ELK_MASK)
/* TCD_DOFF Bit Fields */
#define DMA_TCD_DOFF_DOFF_MASK                  0xFFFFu
#define DMA_TCD_DOFF_DOFF_SHIFT                 0u
#define DMA_TCD_DOFF_DOFF_WIDTH                 16u
#define DMA_TCD_DOFF_DOFF(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_DOFF_DOFF_SHIFT)) \
                                                  &DMA_TCD_DOFF_DOFF_MASK)
/* TCD_DLASTSGA Bit Fields */
#define DMA_TCD_DLASTSGA_DLASTSGA_MASK          0xFFFFFFFFu
#define DMA_TCD_DLASTSGA_DLASTSGA_SHIFT         0u
#define DMA_TCD_DLASTSGA_DLASTSGA_WIDTH         32u
#define DMA_TCD_DLASTSGA_DLASTSGA(x)            (((uint32)(((uint32)(x)) \
                                                  << DMA_TCD_DLASTSGA_DLASTSGA_SHIFT)) \
                                                  &DMA_TCD_DLASTSGA_DLASTSGA_MASK)
/* TCD_BITER_ELINKNO Bit Fields */
#define DMA_TCD_BITER_ELINKNO_BTR_MASK          0x7FFFu
#define DMA_TCD_BITER_ELINKNO_BTR_SHIFT         0u
#define DMA_TCD_BITER_ELINKNO_BTR_WIDTH         15u
#define DMA_TCD_BITER_ELINKNO_BITER(x)          (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_BITER_ELINKNO_BTR_SHIFT)) \
                                                  &DMA_TCD_BITER_ELINKNO_BTR_MASK)
#define DMA_TCD_BITER_ELINKNO_ELK_MASK          0x8000u
#define DMA_TCD_BITER_ELINKNO_ELK_SHIFT         15u
#define DMA_TCD_BITER_ELINKNO_ELK_WIDTH         1u
#define DMA_TCD_BITER_ELINKNO_ELINK(x)          (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_BITER_ELINKNO_ELK_SHIFT)) \
                                                  &DMA_TCD_BITER_ELINKNO_ELK_MASK)
/* TCD_BITER_ELINKYES Bit Fields */
#define DMA_TCD_BTR_ELINKYES_BTR_MASK           0x1FFu
#define DMA_TCD_BTR_ELINKYES_BTR_SHIFT          0u
#define DMA_TCD_BTR_ELINKYES_BTR_WIDTH          9u
#define DMA_TCD_BITER_ELINKYES_BITER(x)         (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_BTR_ELINKYES_BTR_SHIFT)) \
                                                  &DMA_TCD_BTR_ELINKYES_BTR_MASK)
#define DMA_TCD_BTR_ELKYES_LINKCH_MASK          0x7E00u
#define DMA_TCD_BTR_ELKYES_LINKCH_SHIFT         9u
#define DMA_TCD_BTR_ELKYES_LINKCH_WIDTH         6u
#define DMA_TCD_BITER_ELINKYES_LINKCH(x)        (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_BTR_ELKYES_LINKCH_SHIFT)) \
                                                  &DMA_TCD_BTR_ELKYES_LINKCH_MASK)
#define DMA_TCD_BTR_ELKYES_ELINK_MASK           0x8000u
#define DMA_TCD_BTR_ELKYES_ELINK_SHIFT          15u
#define DMA_TCD_BTR_ELKYES_ELINK_WIDTH          1u
#define DMA_TCD_BITER_ELINKYES_ELINK(x)         (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_BTR_ELKYES_ELINK_SHIFT)) \
                                                  &DMA_TCD_BTR_ELKYES_ELINK_MASK)
/* TCD_CSR Bit Fields */
#define DMA_TCD_CSR_START_MASK                  0x1u
#define DMA_TCD_CSR_START_SHIFT                 0u
#define DMA_TCD_CSR_START_WIDTH                 1u
#define DMA_TCD_CSR_START(x)                    (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CSR_START_SHIFT)) \
                                                  &DMA_TCD_CSR_START_MASK)
#define DMA_TCD_CSR_INTMAJOR_MASK               0x2u
#define DMA_TCD_CSR_INTMAJOR_SHIFT              1u
#define DMA_TCD_CSR_INTMAJOR_WIDTH              1u
#define DMA_TCD_CSR_INTMAJOR(x)                 (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_INTMAJOR_SHIFT)) \
                                                  &DMA_TCD_CSR_INTMAJOR_MASK)
#define DMA_TCD_CSR_INTHALF_MASK                0x4u
#define DMA_TCD_CSR_INTHALF_SHIFT               2u
#define DMA_TCD_CSR_INTHALF_WIDTH               1u
#define DMA_TCD_CSR_INTHALF(x)                  (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_INTHALF_SHIFT)) \
                                                  &DMA_TCD_CSR_INTHALF_MASK)
#define DMA_TCD_CSR_DREQ_MASK                   0x8u
#define DMA_TCD_CSR_DREQ_SHIFT                  3u
#define DMA_TCD_CSR_DREQ_WIDTH                  1u
#define DMA_TCD_CSR_DREQ(x)                     (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_DREQ_SHIFT)) \
                                                  &DMA_TCD_CSR_DREQ_MASK)
#define DMA_TCD_CSR_ESG_MASK                    0x10u
#define DMA_TCD_CSR_ESG_SHIFT                   4u
#define DMA_TCD_CSR_ESG_WIDTH                   1u
#define DMA_TCD_CSR_ESG(x)                      (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_ESG_SHIFT)) \
                                                  &DMA_TCD_CSR_ESG_MASK)
#define DMA_TCD_CSR_MAJORELINK_MASK             0x20u
#define DMA_TCD_CSR_MAJORELINK_SHIFT            5u
#define DMA_TCD_CSR_MAJORELINK_WIDTH            1u
#define DMA_TCD_CSR_MAJORELINK(x)               (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_MAJORELINK_SHIFT)) \
                                                  &DMA_TCD_CSR_MAJORELINK_MASK)
#define DMA_TCD_CSR_ACTIVE_MASK                 0x40u
#define DMA_TCD_CSR_ACTIVE_SHIFT                6u
#define DMA_TCD_CSR_ACTIVE_WIDTH                1u
#define DMA_TCD_CSR_ACTIVE(x)                   (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CSR_ACTIVE_SHIFT)) \
                                                  &DMA_TCD_CSR_ACTIVE_MASK)
#define DMA_TCD_CSR_DONE_MASK                   0x80u
#define DMA_TCD_CSR_DONE_SHIFT                  7u
#define DMA_TCD_CSR_DONE_WIDTH                  1u
#define DMA_TCD_CSR_DONE(x)                     (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CSR_DONE_SHIFT)) \
                                                  &DMA_TCD_CSR_DONE_MASK)
#define DMA_TCD_CSR_MAJORLINKCH_MASK            0x3F00u
#define DMA_TCD_CSR_MAJORLINKCH_SHIFT           8u
#define DMA_TCD_CSR_MAJORLINKCH_WIDTH           6u
#define DMA_TCD_CSR_MAJORLINKCH(x)              (uint16)(((((uint32)(x)) \
                                                  << DMA_TCD_CSR_MAJORLINKCH_SHIFT)) \
                                                  &DMA_TCD_CSR_MAJORLINKCH_MASK)
#define DMA_TCD_CSR_BWC_MASK                    0xC000u
#define DMA_TCD_CSR_BWC_SHIFT                   14u
#define DMA_TCD_CSR_BWC_WIDTH                   2u
#define DMA_TCD_CSR_BWC(x)                      (((uint16)(((uint16)(x)) \
                                                  << DMA_TCD_CSR_BWC_SHIFT)) \
                                                  &DMA_TCD_CSR_BWC_MASK)

#define DMAMUX_CHCFG_ENBL_SHIFT                 7U
#define DMAMUX_CHCFG_ENBL_MASK                  0x80U
#define DMAMUX_CHCFG_SOURCE_SHIFT               0U
#define DMAMUX_CHCFG_SOURCE_MASK                0x3FU
#define DMAMUX_CHCFG_TRIG_SHIFT                 6U
#define DMAMUX_CHCFG_TRIG_MASK                  0x40U

#endif  /* EDMA_REG_H_ */
