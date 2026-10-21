#ifndef MEMU_REG_H_
#define MEMU_REG_H_

/* ============================================================================
   =============================== Module: MEMU ===============================
   ============================================================================ */

typedef union MEMU_CTRL_union_tag {    /* Control register */
  vuint32_t R;
  struct {
    vuint32_t  :16;
    vuint32_t SWR:1;
    vuint32_t  :15;
  } B;
} MEMU_CTRL_tag;

typedef union MEMU_ERR_FLAG_union_tag { /* Error flag register */
  vuint32_t R;
  struct {
    vuint32_t  :11;
    vuint32_t PR_CE:1;
    vuint32_t PR_UCE:1;
    vuint32_t PR_CEO:1;
    vuint32_t PR_UCO:1;
    vuint32_t PR_EBO:1;
    vuint32_t  :3;
    vuint32_t F_CE:1;
    vuint32_t F_UCE:1;
    vuint32_t F_CEO:1;
    vuint32_t F_UCO:1;
    vuint32_t F_EBO:1;
    vuint32_t  :3;
    vuint32_t SR_CE:1;
    vuint32_t SR_UCE:1;
    vuint32_t SR_CEO:1;
    vuint32_t SR_UCO:1;
    vuint32_t SR_EBO:1;
  } B;
} MEMU_ERR_FLAG_tag;

typedef union MEMU_DEBUG_union_tag {   /* Debug register */
  vuint32_t R;
  struct {
    vuint32_t  :11;
    vuint32_t FR_PR_CE:1;
    vuint32_t FR_PR_UCE:1;
    vuint32_t FR_PR_CEO:1;
    vuint32_t FR_PR_UCO:1;
    vuint32_t FR_PR_EBO:1;
    vuint32_t  :3;
    vuint32_t FR_F_CE:1;
    vuint32_t FR_F_UCE:1;
    vuint32_t FR_F_CEO:1;
    vuint32_t FR_F_UCO:1;
    vuint32_t FR_F_EBO:1;
    vuint32_t  :3;
    vuint32_t FR_SR_CE:1;
    vuint32_t FR_SR_UCE:1;
    vuint32_t FR_SR_CEO:1;
    vuint32_t FR_SR_UCO:1;
    vuint32_t FR_SR_EBO:1;
  } B;
} MEMU_DEBUG_tag;

typedef union MEMU_SYS_RAM_CERR_STS_union_tag { /* System RAM correctable error reporting table status register */
  vuint32_t R;
  struct {
    vuint32_t VLD:1;
    vuint32_t  :23;
    vuint32_t BAD_BIT:8;
  } B;
} MEMU_SYS_RAM_CERR_STS_tag;

typedef union MEMU_SYS_RAM_CERR_ADDR_union_tag { /* System RAM correctable error reporting table address register */
  vuint32_t R;
  struct {
    vuint32_t ERR_ADD:32;
  } B;
} MEMU_SYS_RAM_CERR_ADDR_tag;

typedef struct MEMU_SYS_RAM_CERR_struct_tag {
  MEMU_SYS_RAM_CERR_STS_tag STS;       /* System RAM correctable error reporting table status register */
  MEMU_SYS_RAM_CERR_ADDR_tag ADDR;     /* System RAM correctable error reporting table address register */
} MEMU_SYS_RAM_CERR_tag;

typedef union MEMU_SYS_RAM_UNCERR_STS_union_tag { /* System RAM uncorrectable error reporting table status register */
  vuint32_t R;
  struct {
    vuint32_t VLD:1;
    vuint32_t  :31;
  } B;
} MEMU_SYS_RAM_UNCERR_STS_tag;

typedef union MEMU_SYS_RAM_UNCERR_ADDR_union_tag { /* System RAM uncorrectable error reporting table address register */
  vuint32_t R;
  struct {
    vuint32_t ERR_ADD:32;
  } B;
} MEMU_SYS_RAM_UNCERR_ADDR_tag;

typedef union MEMU_SYS_RAM_OFLW_union_tag { /* System RAM concurrent overflow register */
  vuint32_t R;
  struct {
    vuint32_t OFLW:32;
  } B;
} MEMU_SYS_RAM_OFLW_tag;

typedef union MEMU_PERIPH_RAM_CERR_STS_union_tag { /* Peripheral RAM correctable error reporting table status register */
  vuint32_t R;
  struct {
    vuint32_t VLD:1;
    vuint32_t  :23;
    vuint32_t BAD_BIT:8;
  } B;
} MEMU_PERIPH_RAM_CERR_STS_tag;

typedef union MEMU_PERIPH_RAM_CERR_ADDR_union_tag { /* Peripheral RAM correctable error reporting table address register */
  vuint32_t R;
  struct {
    vuint32_t ERR_ADD:32;
  } B;
} MEMU_PERIPH_RAM_CERR_ADDR_tag;

typedef struct MEMU_PERIPH_RAM_CERR_struct_tag {
  MEMU_PERIPH_RAM_CERR_STS_tag STS;    /* Peripheral RAM correctable error reporting table status register */
  MEMU_PERIPH_RAM_CERR_ADDR_tag ADDR;  /* Peripheral RAM correctable error reporting table address register */
} MEMU_PERIPH_RAM_CERR_tag;

typedef union MEMU_PERIPH_RAM_UNCERR_STS_union_tag { /* Peripheral RAM uncorrectable error reporting table status register */
  vuint32_t R;
  struct {
    vuint32_t VLD:1;
    vuint32_t  :31;
  } B;
} MEMU_PERIPH_RAM_UNCERR_STS_tag;

typedef union MEMU_PERIPH_RAM_UNCERR_ADDR_union_tag { /* Peripheral RAM uncorrectable error reporting table address register */
  vuint32_t R;
  struct {
    vuint32_t ERR_ADD:32;
  } B;
} MEMU_PERIPH_RAM_UNCERR_ADDR_tag;

typedef union MEMU_PERIPH_RAM_OFLW_union_tag { /* Peripheral RAM concurrent overflow register */
  vuint32_t R;
  struct {
    vuint32_t OFLW:32;
  } B;
} MEMU_PERIPH_RAM_OFLW_tag;

typedef union MEMU_FLASH_CERR_STS_union_tag { /* Flash memory correctable error reporting table status register */
  vuint32_t R;
  struct {
    vuint32_t VLD:1;
    vuint32_t  :23;
    vuint32_t BAD_BIT:8;
  } B;
} MEMU_FLASH_CERR_STS_tag;

typedef union MEMU_FLASH_CERR_ADDR_union_tag { /* Flash memory correctable error reporting table address register */
  vuint32_t R;
  struct {
    vuint32_t ERR_ADD:32;
  } B;
} MEMU_FLASH_CERR_ADDR_tag;

typedef struct MEMU_FLASH_CERR_struct_tag {
  MEMU_FLASH_CERR_STS_tag STS;         /* Flash memory correctable error reporting table status register */
  MEMU_FLASH_CERR_ADDR_tag ADDR;       /* Flash memory correctable error reporting table address register */
} MEMU_FLASH_CERR_tag;

typedef union MEMU_FLASH_UNCERR_STS_union_tag { /* Flash memory uncorrectable error reporting table status register */
  vuint32_t R;
  struct {
    vuint32_t VLD:1;
    vuint32_t  :31;
  } B;
} MEMU_FLASH_UNCERR_STS_tag;

typedef union MEMU_FLASH_UNCERR_ADDR_union_tag { /* Flash memory uncorrectable error reporting table address register */
  vuint32_t R;
  struct {
    vuint32_t ERR_ADD:32;
  } B;
} MEMU_FLASH_UNCERR_ADDR_tag;

typedef union MEMU_FLASH_OFLW0_union_tag { /* Flash memory concurrent overflow register */
  vuint32_t R;
  struct {
    vuint32_t OFLW:32;
  } B;
} MEMU_FLASH_OFLW0_tag;

struct MEMU_tag {
  MEMU_CTRL_tag CTRL;                  /* Control register */
  MEMU_ERR_FLAG_tag ERR_FLAG;          /* Error flag register */
  uint8_t MEMU_reserved0[4];
  MEMU_DEBUG_tag DEBUG;                /* Debug register */
  uint8_t MEMU_reserved1[16];
  MEMU_SYS_RAM_CERR_tag SYS_RAM_CERR[10];
  MEMU_SYS_RAM_UNCERR_STS_tag SYS_RAM_UNCERR_STS; /* System RAM uncorrectable error reporting table status register */
  MEMU_SYS_RAM_UNCERR_ADDR_tag SYS_RAM_UNCERR_ADDR; /* System RAM uncorrectable error reporting table address register */
  MEMU_SYS_RAM_OFLW_tag SYS_RAM_OFLW[3]; /* System RAM concurrent overflow register */
  uint8_t MEMU_reserved2[1436];
  MEMU_PERIPH_RAM_CERR_tag PERIPH_RAM_CERR[2];
  MEMU_PERIPH_RAM_UNCERR_STS_tag PERIPH_RAM_UNCERR_STS; /* Peripheral RAM uncorrectable error reporting table status register */
  MEMU_PERIPH_RAM_UNCERR_ADDR_tag PERIPH_RAM_UNCERR_ADDR; /* Peripheral RAM uncorrectable error reporting table address register */
  MEMU_PERIPH_RAM_OFLW_tag PERIPH_RAM_OFLW[2]; /* Peripheral RAM concurrent overflow register */
  uint8_t MEMU_reserved3[1504];
  MEMU_FLASH_CERR_tag FLASH_CERR[20];
  MEMU_FLASH_UNCERR_STS_tag FLASH_UNCERR_STS; /* Flash memory uncorrectable error reporting table status register */
  MEMU_FLASH_UNCERR_ADDR_tag FLASH_UNCERR_ADDR; /* Flash memory uncorrectable error reporting table address register */
  MEMU_FLASH_OFLW0_tag FLASH_OFLW0;    /* Flash memory concurrent overflow register */
};

#endif
