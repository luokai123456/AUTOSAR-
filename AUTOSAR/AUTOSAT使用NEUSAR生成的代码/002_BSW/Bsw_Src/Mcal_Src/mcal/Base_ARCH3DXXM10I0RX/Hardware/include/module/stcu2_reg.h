#ifndef STCU2_REG_H_
#define STCU2_REG_H_

/* ============================================================================
   =============================== Module: STCU2 ==============================
   ============================================================================ */

typedef union STCU2_RUN_union_tag {    /* STCU2 Run Register */
  vuint32_t R;
  struct {
    vuint32_t  :21;
    vuint32_t BYP:1;
    vuint32_t MBPLLEN:1;
    vuint32_t LBPLLEN:1;
    vuint32_t  :7;
    vuint32_t RUN:1;
  } B;
} STCU2_RUN_tag;

typedef union STCU2_RUNSW_union_tag {  /* STCU2 Run Software Register */
  vuint32_t R;
  struct {
    vuint32_t  :20;
    vuint32_t MBIE:1;
    vuint32_t LBIE:1;
    vuint32_t MBSWPLLEN:1;
    vuint32_t LBSWPLLEN:1;
    vuint32_t  :6;
    vuint32_t RUNSW_ABORT:1;
    vuint32_t RUNSW:1;
  } B;
} STCU2_RUNSW_tag;

typedef union STCU2_SKC_union_tag {    /* STCU2 SK Code Register */
  vuint32_t R;
  struct {
    vuint32_t SKC:32;
  } B;
} STCU2_SKC_tag;

typedef union STCU2_CFG_union_tag {    /* STCU2 Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :1;
    vuint32_t PTR:7;
    vuint32_t LB_DELAY:8;
    vuint32_t  :7;
    vuint32_t WRP:1;
    vuint32_t  :2;
    vuint32_t CRCEN:1;
    vuint32_t PMOSEN:1;
    vuint32_t MBU:1;
    vuint32_t CLK_CFG:3;
  } B;
} STCU2_CFG_tag;

typedef union STCU2_PLL_CFG_union_tag { /* STCU2 PLL Configuration Register */
  vuint32_t R;
  struct {
    vuint32_t  :2;
    vuint32_t PLLODF:6;
    vuint32_t  :5;
    vuint32_t PLLIDF:3;
    vuint32_t  :9;
    vuint32_t PLLLDF:7;
  } B;
} STCU2_PLL_CFG_tag;

typedef union STCU2_WDG_union_tag {    /* STCU2 Watchdog Register Granularity */
  vuint32_t R;
  struct {
    vuint32_t WDGEOC:32;
  } B;
} STCU2_WDG_tag;

typedef union STCU2_INT_FLG_union_tag { /* STCU2 Interrupt Flag Register */
  vuint32_t R;
  struct {
    vuint32_t  :30;
    vuint32_t MBIFLG:1;
    vuint32_t LBIFLG:1;
  } B;
} STCU2_INT_FLG_tag;

typedef union STCU2_CRCE_union_tag {   /* STCU2 CRC Expected Status Register */
  vuint32_t R;
  struct {
    vuint32_t CRCE:32;
  } B;
} STCU2_CRCE_tag;

typedef union STCU2_CRCR_union_tag {   /* STCU2 CRC Read Status Register */
  vuint32_t R;
  struct {
    vuint32_t CRCR:32;
  } B;
} STCU2_CRCR_tag;

typedef union STCU2_ERR_STAT_union_tag { /* STCU2 Error Register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t ABORTHW:1;
    vuint32_t ABORTSW:1;
    vuint32_t  :3;
    vuint32_t LOCKESW:1;
    vuint32_t WDTOSW:1;
    vuint32_t CRCSSW:1;
    vuint32_t ENGESW:1;
    vuint32_t INVPSW:1;
    vuint32_t  :6;
    vuint32_t UFSF:1;
    vuint32_t RFSF:1;
    vuint32_t  :3;
    vuint32_t LOCKE:1;
    vuint32_t WDTO:1;
    vuint32_t CRCS:1;
    vuint32_t ENGE:1;
    vuint32_t INVP:1;
  } B;
} STCU2_ERR_STAT_tag;

typedef union STCU2_ERR_FM_union_tag { /* STCU2 Error FM Register */
  vuint32_t R;
  struct {
    vuint32_t  :27;
    vuint32_t LOCKEUFM:1;
    vuint32_t WDTOUFM:1;
    vuint32_t CRCSUFM:1;
    vuint32_t ENGEUFM:1;
    vuint32_t INVPUFM:1;
  } B;
} STCU2_ERR_FM_tag;

typedef union STCU2_LBS_union_tag {    /* STCU2 Off-Line LBIST Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t LBS9:1;
    vuint32_t LBS8:1;
    vuint32_t LBS7:1;
    vuint32_t LBS6:1;
    vuint32_t LBS5:1;
    vuint32_t LBS4:1;
    vuint32_t LBS3:1;
    vuint32_t LBS2:1;
    vuint32_t LBS1:1;
    vuint32_t LBS0:1;
  } B;
} STCU2_LBS_tag;

typedef union STCU2_LBE_union_tag {    /* STCU2 Off-Line LBIST End Flag Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t LBE9:1;
    vuint32_t LBE8:1;
    vuint32_t LBE7:1;
    vuint32_t LBE6:1;
    vuint32_t LBE5:1;
    vuint32_t LBE4:1;
    vuint32_t LBE3:1;
    vuint32_t LBE2:1;
    vuint32_t LBE1:1;
    vuint32_t LBE0:1;
  } B;
} STCU2_LBE_tag;

typedef union STCU2_LBSSW_union_tag {  /* STCU2 On-Line LBIST Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t LBSSW9:1;
    vuint32_t LBSSW8:1;
    vuint32_t LBSSW7:1;
    vuint32_t LBSSW6:1;
    vuint32_t LBSSW5:1;
    vuint32_t LBSSW4:1;
    vuint32_t LBSSW3:1;
    vuint32_t LBSSW2:1;
    vuint32_t LBSSW1:1;
    vuint32_t LBSSW0:1;
  } B;
} STCU2_LBSSW_tag;

typedef union STCU2_LBESW_union_tag {  /* STCU2 On-Line LBIST End Flag Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t LBESW9:1;
    vuint32_t LBESW8:1;
    vuint32_t LBESW7:1;
    vuint32_t LBESW6:1;
    vuint32_t LBESW5:1;
    vuint32_t LBESW4:1;
    vuint32_t LBESW3:1;
    vuint32_t LBESW2:1;
    vuint32_t LBESW1:1;
    vuint32_t LBESW0:1;
  } B;
} STCU2_LBESW_tag;

typedef union STCU2_LBRMSW_union_tag { /* STCU2 On-Line LBIST Reset Management */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t LBRMSW9:1;
    vuint32_t LBRMSW8:1;
    vuint32_t LBRMSW7:1;
    vuint32_t LBRMSW6:1;
    vuint32_t LBRMSW5:1;
    vuint32_t LBRMSW4:1;
    vuint32_t LBRMSW3:1;
    vuint32_t LBRMSW2:1;
    vuint32_t LBRMSW1:1;
    vuint32_t LBRMSW0:1;
  } B;
} STCU2_LBRMSW_tag;

typedef union STCU2_LBUFM_union_tag {  /* STCU2 LBIST Unrecoverable FM Register */
  vuint32_t R;
  struct {
    vuint32_t  :22;
    vuint32_t LBUFM9:1;
    vuint32_t LBUFM8:1;
    vuint32_t LBUFM7:1;
    vuint32_t LBUFM6:1;
    vuint32_t LBUFM5:1;
    vuint32_t LBUFM4:1;
    vuint32_t LBUFM3:1;
    vuint32_t LBUFM2:1;
    vuint32_t LBUFM1:1;
    vuint32_t LBUFM0:1;
  } B;
} STCU2_LBUFM_tag;

typedef union STCU2_MBSL_union_tag {   /* STCU2 Off-Line MBIST Status Low Register */
  vuint32_t R;
  struct {
    vuint32_t MBS31:1;
    vuint32_t MBS30:1;
    vuint32_t MBS29:1;
    vuint32_t MBS28:1;
    vuint32_t MBS27:1;
    vuint32_t MBS26:1;
    vuint32_t MBS25:1;
    vuint32_t MBS24:1;
    vuint32_t MBS23:1;
    vuint32_t MBS22:1;
    vuint32_t MBS21:1;
    vuint32_t MBS20:1;
    vuint32_t MBS19:1;
    vuint32_t MBS18:1;
    vuint32_t MBS17:1;
    vuint32_t MBS16:1;
    vuint32_t MBS15:1;
    vuint32_t MBS14:1;
    vuint32_t MBS13:1;
    vuint32_t MBS12:1;
    vuint32_t MBS11:1;
    vuint32_t MBS10:1;
    vuint32_t MBS9:1;
    vuint32_t MBS8:1;
    vuint32_t MBS7:1;
    vuint32_t MBS6:1;
    vuint32_t MBS5:1;
    vuint32_t MBS4:1;
    vuint32_t MBS3:1;
    vuint32_t MBS2:1;
    vuint32_t MBS1:1;
    vuint32_t MBS0:1;
  } B;
} STCU2_MBSL_tag;

typedef union STCU2_MBSM_union_tag {   /* STCU2 Off-Line MBIST Status Medium Register */
  vuint32_t R;
  struct {
    vuint32_t MBS63:1;
    vuint32_t MBS62:1;
    vuint32_t MBS61:1;
    vuint32_t MBS60:1;
    vuint32_t MBS59:1;
    vuint32_t MBS58:1;
    vuint32_t MBS57:1;
    vuint32_t MBS56:1;
    vuint32_t MBS55:1;
    vuint32_t MBS54:1;
    vuint32_t MBS53:1;
    vuint32_t MBS52:1;
    vuint32_t MBS51:1;
    vuint32_t MBS50:1;
    vuint32_t MBS49:1;
    vuint32_t MBS48:1;
    vuint32_t MBS47:1;
    vuint32_t MBS46:1;
    vuint32_t MBS45:1;
    vuint32_t MBS44:1;
    vuint32_t MBS43:1;
    vuint32_t MBS42:1;
    vuint32_t MBS41:1;
    vuint32_t MBS40:1;
    vuint32_t MBS39:1;
    vuint32_t MBS38:1;
    vuint32_t MBS37:1;
    vuint32_t MBS36:1;
    vuint32_t MBS35:1;
    vuint32_t MBS34:1;
    vuint32_t MBS33:1;
    vuint32_t MBS32:1;
  } B;
} STCU2_MBSM_tag;

typedef union STCU2_MBSH_union_tag {   /* STCU2 Off-Line MBIST Status High Register */
  vuint32_t R;
  struct {
    vuint32_t  :18;
    vuint32_t MBS77:1;
    vuint32_t MBS76:1;
    vuint32_t MBS75:1;
    vuint32_t MBS74:1;
    vuint32_t MBS73:1;
    vuint32_t MBS72:1;
    vuint32_t MBS71:1;
    vuint32_t MBS70:1;
    vuint32_t MBS69:1;
    vuint32_t MBS68:1;
    vuint32_t MBS67:1;
    vuint32_t MBS66:1;
    vuint32_t MBS65:1;
    vuint32_t MBS64:1;
  } B;
} STCU2_MBSH_tag;

typedef union STCU2_MBEL_union_tag {   /* STCU2 Off-Line MBIST End Flag Low Register */
  vuint32_t R;
  struct {
    vuint32_t MBE31:1;
    vuint32_t MBE30:1;
    vuint32_t MBE29:1;
    vuint32_t MBE28:1;
    vuint32_t MBE27:1;
    vuint32_t MBE26:1;
    vuint32_t MBE25:1;
    vuint32_t MBE24:1;
    vuint32_t MBE23:1;
    vuint32_t MBE22:1;
    vuint32_t MBE21:1;
    vuint32_t MBE20:1;
    vuint32_t MBE19:1;
    vuint32_t MBE18:1;
    vuint32_t MBE17:1;
    vuint32_t MBE16:1;
    vuint32_t MBE15:1;
    vuint32_t MBE14:1;
    vuint32_t MBE13:1;
    vuint32_t MBE12:1;
    vuint32_t MBE11:1;
    vuint32_t MBE10:1;
    vuint32_t MBE9:1;
    vuint32_t MBE8:1;
    vuint32_t MBE7:1;
    vuint32_t MBE6:1;
    vuint32_t MBE5:1;
    vuint32_t MBE4:1;
    vuint32_t MBE3:1;
    vuint32_t MBE2:1;
    vuint32_t MBE1:1;
    vuint32_t MBE0:1;
  } B;
} STCU2_MBEL_tag;

typedef union STCU2_MBEM_union_tag {   /* STCU2 Off-Line MBIST End Flag Medium Register */
  vuint32_t R;
  struct {
    vuint32_t MBE63:1;
    vuint32_t MBE62:1;
    vuint32_t MBE61:1;
    vuint32_t MBE60:1;
    vuint32_t MBE59:1;
    vuint32_t MBE58:1;
    vuint32_t MBE57:1;
    vuint32_t MBE56:1;
    vuint32_t MBE55:1;
    vuint32_t MBE54:1;
    vuint32_t MBE53:1;
    vuint32_t MBE52:1;
    vuint32_t MBE51:1;
    vuint32_t MBE50:1;
    vuint32_t MBE49:1;
    vuint32_t MBE48:1;
    vuint32_t MBE47:1;
    vuint32_t MBE46:1;
    vuint32_t MBE45:1;
    vuint32_t MBE44:1;
    vuint32_t MBE43:1;
    vuint32_t MBE42:1;
    vuint32_t MBE41:1;
    vuint32_t MBE40:1;
    vuint32_t MBE39:1;
    vuint32_t MBE38:1;
    vuint32_t MBE37:1;
    vuint32_t MBE36:1;
    vuint32_t MBE35:1;
    vuint32_t MBE34:1;
    vuint32_t MBE33:1;
    vuint32_t MBE32:1;
  } B;
} STCU2_MBEM_tag;

typedef union STCU2_MBEH_union_tag {   /* STCU2 Off-Line MBIST End Flag High Register */
  vuint32_t R;
  struct {
    vuint32_t  :18;
    vuint32_t MBE77:1;
    vuint32_t MBE76:1;
    vuint32_t MBE75:1;
    vuint32_t MBE74:1;
    vuint32_t MBE73:1;
    vuint32_t MBE72:1;
    vuint32_t MBE71:1;
    vuint32_t MBE70:1;
    vuint32_t MBE69:1;
    vuint32_t MBE68:1;
    vuint32_t MBE67:1;
    vuint32_t MBE66:1;
    vuint32_t MBE65:1;
    vuint32_t MBE64:1;
  } B;
} STCU2_MBEH_tag;

typedef union STCU2_MBSLSW_union_tag { /* STCU2 On-Line MBIST Status Low Register */
  vuint32_t R;
  struct {
    vuint32_t MBSSW31:1;
    vuint32_t MBSSW30:1;
    vuint32_t MBSSW29:1;
    vuint32_t MBSSW28:1;
    vuint32_t MBSSW27:1;
    vuint32_t MBSSW26:1;
    vuint32_t MBSSW25:1;
    vuint32_t MBSSW24:1;
    vuint32_t MBSSW23:1;
    vuint32_t MBSSW22:1;
    vuint32_t MBSSW21:1;
    vuint32_t MBSSW20:1;
    vuint32_t MBSSW19:1;
    vuint32_t MBSSW18:1;
    vuint32_t MBSSW17:1;
    vuint32_t MBSSW16:1;
    vuint32_t MBSSW15:1;
    vuint32_t MBSSW14:1;
    vuint32_t MBSSW13:1;
    vuint32_t MBSSW12:1;
    vuint32_t MBSSW11:1;
    vuint32_t MBSSW10:1;
    vuint32_t MBSSW9:1;
    vuint32_t MBSSW8:1;
    vuint32_t MBSSW7:1;
    vuint32_t MBSSW6:1;
    vuint32_t MBSSW5:1;
    vuint32_t MBSSW4:1;
    vuint32_t MBSSW3:1;
    vuint32_t MBSSW2:1;
    vuint32_t MBSSW1:1;
    vuint32_t MBSSW0:1;
  } B;
} STCU2_MBSLSW_tag;

typedef union STCU2_MBSMSW_union_tag { /* STCU2 On-Line MBIST Status Medium Register */
  vuint32_t R;
  struct {
    vuint32_t MBSSW63:1;
    vuint32_t MBSSW62:1;
    vuint32_t MBSSW61:1;
    vuint32_t MBSSW60:1;
    vuint32_t MBSSW59:1;
    vuint32_t MBSSW58:1;
    vuint32_t MBSSW57:1;
    vuint32_t MBSSW56:1;
    vuint32_t MBSSW55:1;
    vuint32_t MBSSW54:1;
    vuint32_t MBSSW53:1;
    vuint32_t MBSSW52:1;
    vuint32_t MBSSW51:1;
    vuint32_t MBSSW50:1;
    vuint32_t MBSSW49:1;
    vuint32_t MBSSW48:1;
    vuint32_t MBSSW47:1;
    vuint32_t MBSSW46:1;
    vuint32_t MBSSW45:1;
    vuint32_t MBSSW44:1;
    vuint32_t MBSSW43:1;
    vuint32_t MBSSW42:1;
    vuint32_t MBSSW41:1;
    vuint32_t MBSSW40:1;
    vuint32_t MBSSW39:1;
    vuint32_t MBSSW38:1;
    vuint32_t MBSSW37:1;
    vuint32_t MBSSW36:1;
    vuint32_t MBSSW35:1;
    vuint32_t MBSSW34:1;
    vuint32_t MBSSW33:1;
    vuint32_t MBSSW32:1;
  } B;
} STCU2_MBSMSW_tag;

typedef union STCU2_MBSHSW_union_tag { /* STCU2 On-Line MBIST Status High Register */
  vuint32_t R;
  struct {
    vuint32_t  :18;
    vuint32_t MBSSW77:1;
    vuint32_t MBSSW76:1;
    vuint32_t MBSSW75:1;
    vuint32_t MBSSW74:1;
    vuint32_t MBSSW73:1;
    vuint32_t MBSSW72:1;
    vuint32_t MBSSW71:1;
    vuint32_t MBSSW70:1;
    vuint32_t MBSSW69:1;
    vuint32_t MBSSW68:1;
    vuint32_t MBSSW67:1;
    vuint32_t MBSSW66:1;
    vuint32_t MBSSW65:1;
    vuint32_t MBSSW64:1;
  } B;
} STCU2_MBSHSW_tag;

typedef union STCU2_MBELSW_union_tag { /* STCU2 On-Line MBIST End Flag Low Register */
  vuint32_t R;
  struct {
    vuint32_t MBESW31:1;
    vuint32_t MBESW30:1;
    vuint32_t MBESW29:1;
    vuint32_t MBESW28:1;
    vuint32_t MBESW27:1;
    vuint32_t MBESW26:1;
    vuint32_t MBESW25:1;
    vuint32_t MBESW24:1;
    vuint32_t MBESW23:1;
    vuint32_t MBESW22:1;
    vuint32_t MBESW21:1;
    vuint32_t MBESW20:1;
    vuint32_t MBESW19:1;
    vuint32_t MBESW18:1;
    vuint32_t MBESW17:1;
    vuint32_t MBESW16:1;
    vuint32_t MBESW15:1;
    vuint32_t MBESW14:1;
    vuint32_t MBESW13:1;
    vuint32_t MBESW12:1;
    vuint32_t MBESW11:1;
    vuint32_t MBESW10:1;
    vuint32_t MBESW9:1;
    vuint32_t MBESW8:1;
    vuint32_t MBESW7:1;
    vuint32_t MBESW6:1;
    vuint32_t MBESW5:1;
    vuint32_t MBESW4:1;
    vuint32_t MBESW3:1;
    vuint32_t MBESW2:1;
    vuint32_t MBESW1:1;
    vuint32_t MBESW0:1;
  } B;
} STCU2_MBELSW_tag;

typedef union STCU2_MBEMSW_union_tag { /* STCU2 On-Line MBIST End Flag Medium Register */
  vuint32_t R;
  struct {
    vuint32_t MBESW63:1;
    vuint32_t MBESW62:1;
    vuint32_t MBESW61:1;
    vuint32_t MBESW60:1;
    vuint32_t MBESW59:1;
    vuint32_t MBESW58:1;
    vuint32_t MBESW57:1;
    vuint32_t MBESW56:1;
    vuint32_t MBESW55:1;
    vuint32_t MBESW54:1;
    vuint32_t MBESW53:1;
    vuint32_t MBESW52:1;
    vuint32_t MBESW51:1;
    vuint32_t MBESW50:1;
    vuint32_t MBESW49:1;
    vuint32_t MBESW48:1;
    vuint32_t MBESW47:1;
    vuint32_t MBESW46:1;
    vuint32_t MBESW45:1;
    vuint32_t MBESW44:1;
    vuint32_t MBESW43:1;
    vuint32_t MBESW42:1;
    vuint32_t MBESW41:1;
    vuint32_t MBESW40:1;
    vuint32_t MBESW39:1;
    vuint32_t MBESW38:1;
    vuint32_t MBESW37:1;
    vuint32_t MBESW36:1;
    vuint32_t MBESW35:1;
    vuint32_t MBESW34:1;
    vuint32_t MBESW33:1;
    vuint32_t MBESW32:1;
  } B;
} STCU2_MBEMSW_tag;

typedef union STCU2_MBEHSW_union_tag { /* STCU2 On-Line MBIST End Flag High Register */
  vuint32_t R;
  struct {
    vuint32_t  :18;
    vuint32_t MBESW77:1;
    vuint32_t MBESW76:1;
    vuint32_t MBESW75:1;
    vuint32_t MBESW74:1;
    vuint32_t MBESW73:1;
    vuint32_t MBESW72:1;
    vuint32_t MBESW71:1;
    vuint32_t MBESW70:1;
    vuint32_t MBESW69:1;
    vuint32_t MBESW68:1;
    vuint32_t MBESW67:1;
    vuint32_t MBESW66:1;
    vuint32_t MBESW65:1;
    vuint32_t MBESW64:1;
  } B;
} STCU2_MBEHSW_tag;

typedef union STCU2_MBUFML_union_tag { /* STCU2 MBIST Unrecoverable FM Low Register */
  vuint32_t R;
  struct {
    vuint32_t MBUFM31:1;
    vuint32_t MBUFM30:1;
    vuint32_t MBUFM29:1;
    vuint32_t MBUFM28:1;
    vuint32_t MBUFM27:1;
    vuint32_t MBUFM26:1;
    vuint32_t MBUFM25:1;
    vuint32_t MBUFM24:1;
    vuint32_t MBUFM23:1;
    vuint32_t MBUFM22:1;
    vuint32_t MBUFM21:1;
    vuint32_t MBUFM20:1;
    vuint32_t MBUFM19:1;
    vuint32_t MBUFM18:1;
    vuint32_t MBUFM17:1;
    vuint32_t MBUFM16:1;
    vuint32_t MBUFM15:1;
    vuint32_t MBUFM14:1;
    vuint32_t MBUFM13:1;
    vuint32_t MBUFM12:1;
    vuint32_t MBUFM11:1;
    vuint32_t MBUFM10:1;
    vuint32_t MBUFM9:1;
    vuint32_t MBUFM8:1;
    vuint32_t MBUFM7:1;
    vuint32_t MBUFM6:1;
    vuint32_t MBUFM5:1;
    vuint32_t MBUFM4:1;
    vuint32_t MBUFM3:1;
    vuint32_t MBUFM2:1;
    vuint32_t MBUFM1:1;
    vuint32_t MBUFM0:1;
  } B;
} STCU2_MBUFML_tag;

typedef union STCU2_MBUFMM_union_tag { /* STCU2 MBIST Unrecoverable FM Medium Register */
  vuint32_t R;
  struct {
    vuint32_t MBUFM63:1;
    vuint32_t MBUFM62:1;
    vuint32_t MBUFM61:1;
    vuint32_t MBUFM60:1;
    vuint32_t MBUFM59:1;
    vuint32_t MBUFM58:1;
    vuint32_t MBUFM57:1;
    vuint32_t MBUFM56:1;
    vuint32_t MBUFM55:1;
    vuint32_t MBUFM54:1;
    vuint32_t MBUFM53:1;
    vuint32_t MBUFM52:1;
    vuint32_t MBUFM51:1;
    vuint32_t MBUFM50:1;
    vuint32_t MBUFM49:1;
    vuint32_t MBUFM48:1;
    vuint32_t MBUFM47:1;
    vuint32_t MBUFM46:1;
    vuint32_t MBUFM45:1;
    vuint32_t MBUFM44:1;
    vuint32_t MBUFM43:1;
    vuint32_t MBUFM42:1;
    vuint32_t MBUFM41:1;
    vuint32_t MBUFM40:1;
    vuint32_t MBUFM39:1;
    vuint32_t MBUFM38:1;
    vuint32_t MBUFM37:1;
    vuint32_t MBUFM36:1;
    vuint32_t MBUFM35:1;
    vuint32_t MBUFM34:1;
    vuint32_t MBUFM33:1;
    vuint32_t MBUFM32:1;
  } B;
} STCU2_MBUFMM_tag;

typedef union STCU2_MBUFMH_union_tag { /* STCU2 MBIST Unrecoverable FM High Register */
  vuint32_t R;
  struct {
    vuint32_t  :18;
    vuint32_t MBUFM77:1;
    vuint32_t MBUFM76:1;
    vuint32_t MBUFM75:1;
    vuint32_t MBUFM74:1;
    vuint32_t MBUFM73:1;
    vuint32_t MBUFM72:1;
    vuint32_t MBUFM71:1;
    vuint32_t MBUFM70:1;
    vuint32_t MBUFM69:1;
    vuint32_t MBUFM68:1;
    vuint32_t MBUFM67:1;
    vuint32_t MBUFM66:1;
    vuint32_t MBUFM65:1;
    vuint32_t MBUFM64:1;
  } B;
} STCU2_MBUFMH_tag;

typedef union STCU2_LB_LB_CTRL_union_tag { /* STCU2 LBIST Control Register */
  vuint32_t R;
  struct {
    vuint32_t CSM:1;
    vuint32_t PTR:7;
    vuint32_t  :4;
    vuint32_t PRPGEN:1;
    vuint32_t SHS:3;
    vuint32_t SCEN_OFF:4;
    vuint32_t SCEN_ON:4;
    vuint32_t  :4;
    vuint32_t PFT:1;
    vuint32_t CWS:3;
  } B;
} STCU2_LB_LB_CTRL_tag;

typedef union STCU2_LB_LB_PCS_union_tag { /* STCU2 LBIST PC Stop Register */
  vuint32_t R;
  struct {
    vuint32_t  :6;
    vuint32_t PCS:26;
  } B;
} STCU2_LB_LB_PCS_tag;

typedef union STCU2_LB_LB_PRPGL_union_tag { /* STCU2 LBIST PRPG Low Register */
  vuint32_t R;
  struct {
    vuint32_t PRPGx:32;
  } B;
} STCU2_LB_LB_PRPGL_tag;

typedef union STCU2_LB_LB_PRPGH_union_tag { /* STCU2 LBIST PRPG High Register */
  vuint32_t R;
  struct {
    vuint32_t PRPGx:32;
  } B;
} STCU2_LB_LB_PRPGH_tag;

typedef union STCU2_LB_LB_MISREL_union_tag { /* STCU2 Off-Line LBIST MISR Expected Low Register */
  vuint32_t R;
  struct {
    vuint32_t MISREx:32;
  } B;
} STCU2_LB_LB_MISREL_tag;

typedef union STCU2_LB_LB_MISREH_union_tag { /* STCU2 Off-Line LBIST MISR Expected High Register */
  vuint32_t R;
  struct {
    vuint32_t MISREx:32;
  } B;
} STCU2_LB_LB_MISREH_tag;

typedef union STCU2_LB_LB_MISRRL_union_tag { /* STCU2 Off-Line LBIST MISR Read Low Register */
  vuint32_t R;
  struct {
    vuint32_t MISRRx:32;
  } B;
} STCU2_LB_LB_MISRRL_tag;

typedef union STCU2_LB_LB_MISRRH_union_tag { /* STCU2 Off-Line LBIST MISR Read High Register */
  vuint32_t R;
  struct {
    vuint32_t MISRRx:32;
  } B;
} STCU2_LB_LB_MISRRH_tag;

typedef union STCU2_LB_LB_MISRELSW_union_tag { /* STCU2 On-Line LBIST MISR Expected Low Register */
  vuint32_t R;
  struct {
    vuint32_t MISRESWx:32;
  } B;
} STCU2_LB_LB_MISRELSW_tag;

typedef union STCU2_LB_LB_MISREHSW_union_tag { /* STCU2 On-Line LBIST MISR Expected High Register */
  vuint32_t R;
  struct {
    vuint32_t MISRESWx:32;
  } B;
} STCU2_LB_LB_MISREHSW_tag;

typedef union STCU2_LB_LB_MISRRLSW_union_tag { /* STCU2 On-Line LBIST MISR Read Low Register */
  vuint32_t R;
  struct {
    vuint32_t MISRRSWx:32;
  } B;
} STCU2_LB_LB_MISRRLSW_tag;

typedef union STCU2_LB_LB_MISRRHSW_union_tag { /* STCU2 On-Line LBIST MISR Read High Register */
  vuint32_t R;
  struct {
    vuint32_t MISRRSWx:32;
  } B;
} STCU2_LB_LB_MISRRHSW_tag;

typedef struct STCU2_LB_struct_tag {
  STCU2_LB_LB_CTRL_tag LB_CTRL;        /* STCU2 LBIST Control Register */
  STCU2_LB_LB_PCS_tag LB_PCS;          /* STCU2 LBIST PC Stop Register */
  STCU2_LB_LB_PRPGL_tag LB_PRPGL;      /* STCU2 LBIST PRPG Low Register */
  STCU2_LB_LB_PRPGH_tag LB_PRPGH;      /* STCU2 LBIST PRPG High Register */
  STCU2_LB_LB_MISREL_tag LB_MISREL;    /* STCU2 Off-Line LBIST MISR Expected Low Register */
  STCU2_LB_LB_MISREH_tag LB_MISREH;    /* STCU2 Off-Line LBIST MISR Expected High Register */
  STCU2_LB_LB_MISRRL_tag LB_MISRRL;    /* STCU2 Off-Line LBIST MISR Read Low Register */
  STCU2_LB_LB_MISRRH_tag LB_MISRRH;    /* STCU2 Off-Line LBIST MISR Read High Register */
  STCU2_LB_LB_MISRELSW_tag LB_MISRELSW; /* STCU2 On-Line LBIST MISR Expected Low Register */
  STCU2_LB_LB_MISREHSW_tag LB_MISREHSW; /* STCU2 On-Line LBIST MISR Expected High Register */
  STCU2_LB_LB_MISRRLSW_tag LB_MISRRLSW; /* STCU2 On-Line LBIST MISR Read Low Register */
  STCU2_LB_LB_MISRRHSW_tag LB_MISRRHSW; /* STCU2 On-Line LBIST MISR Read High Register */
  uint8_t LB_reserved0[16];
} STCU2_LB_tag;

typedef union STCU2_MB_CTRL_union_tag { /* STCU2 MBIST Control Register */
  vuint32_t R;
  struct {
    vuint32_t CSM:1;
    vuint32_t PTR:7;
    vuint32_t  :24;
  } B;
} STCU2_MB_CTRL_tag;

struct STCU2_tag {
  STCU2_RUN_tag RUN;                   /* STCU2 Run Register */
  STCU2_RUNSW_tag RUNSW;               /* STCU2 Run Software Register */
  STCU2_SKC_tag SKC;                   /* STCU2 SK Code Register */
  STCU2_CFG_tag CFG;                   /* STCU2 Configuration Register */
  STCU2_PLL_CFG_tag PLL_CFG;           /* STCU2 PLL Configuration Register */
  STCU2_WDG_tag WDG;                   /* STCU2 Watchdog Register Granularity */
  STCU2_INT_FLG_tag INT_FLG;           /* STCU2 Interrupt Flag Register */
  STCU2_CRCE_tag CRCE;                 /* STCU2 CRC Expected Status Register */
  STCU2_CRCR_tag CRCR;                 /* STCU2 CRC Read Status Register */
  STCU2_ERR_STAT_tag ERR_STAT;         /* STCU2 Error Register */
  STCU2_ERR_FM_tag ERR_FM;             /* STCU2 Error FM Register */
  STCU2_LBS_tag LBS;                   /* STCU2 Off-Line LBIST Status Register */
  STCU2_LBE_tag LBE;                   /* STCU2 Off-Line LBIST End Flag Register */
  STCU2_LBSSW_tag LBSSW;               /* STCU2 On-Line LBIST Status Register */
  STCU2_LBESW_tag LBESW;               /* STCU2 On-Line LBIST End Flag Register */
  STCU2_LBRMSW_tag LBRMSW;             /* STCU2 On-Line LBIST Reset Management */
  STCU2_LBUFM_tag LBUFM;               /* STCU2 LBIST Unrecoverable FM Register */
  STCU2_MBSL_tag MBSL;                 /* STCU2 Off-Line MBIST Status Low Register */
  STCU2_MBSM_tag MBSM;                 /* STCU2 Off-Line MBIST Status Medium Register */
  STCU2_MBSH_tag MBSH;                 /* STCU2 Off-Line MBIST Status High Register */
  STCU2_MBEL_tag MBEL;                 /* STCU2 Off-Line MBIST End Flag Low Register */
  STCU2_MBEM_tag MBEM;                 /* STCU2 Off-Line MBIST End Flag Medium Register */
  STCU2_MBEH_tag MBEH;                 /* STCU2 Off-Line MBIST End Flag High Register */
  STCU2_MBSLSW_tag MBSLSW;             /* STCU2 On-Line MBIST Status Low Register */
  STCU2_MBSMSW_tag MBSMSW;             /* STCU2 On-Line MBIST Status Medium Register */
  STCU2_MBSHSW_tag MBSHSW;             /* STCU2 On-Line MBIST Status High Register */
  STCU2_MBELSW_tag MBELSW;             /* STCU2 On-Line MBIST End Flag Low Register */
  STCU2_MBEMSW_tag MBEMSW;             /* STCU2 On-Line MBIST End Flag Medium Register */
  STCU2_MBEHSW_tag MBEHSW;             /* STCU2 On-Line MBIST End Flag High Register */
  STCU2_MBUFML_tag MBUFML;             /* STCU2 MBIST Unrecoverable FM Low Register */
  STCU2_MBUFMM_tag MBUFMM;             /* STCU2 MBIST Unrecoverable FM Medium Register */
  STCU2_MBUFMH_tag MBUFMH;             /* STCU2 MBIST Unrecoverable FM High Register */
  uint8_t STCU2_reserved0[128];
  STCU2_LB_tag LB[10];
  uint8_t STCU2_reserved1[640];
  STCU2_MB_CTRL_tag MB_CTRL[78];       /* STCU2 MBIST Control Register */
};

#endif
