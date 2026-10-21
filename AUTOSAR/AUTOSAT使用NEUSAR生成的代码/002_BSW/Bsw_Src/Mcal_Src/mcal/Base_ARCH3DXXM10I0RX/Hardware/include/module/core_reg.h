#ifndef CORE_REG_H_
#define CORE_REG_H_

/* ============================================================================
   =============================== Module: MCORE =============================
   ============================================================================ */
#define Z4_ICACHE_SIZE 8192U
#define Z4_ICACHE_LINE 32U
#define Z4_ICACHE_WAY_NUM 2U
#define Z4_ICACHE_SET_NUM (Z4_ICACHE_SIZE / (Z4_ICACHE_LINE * Z4_ICACHE_WAY_NUM))

#define Z4_DCACHE_SIZE 0U
#define Z4_DCACHE_LINE 0U
#define Z4_DCACHE_WAY_NUM 0U
#define Z4_DCACHE_SET_NUM 0U

#define Z7_ICACHE_SIZE 16384U
#define Z7_ICACHE_LINE 32U
#define Z7_ICACHE_WAY_NUM 2U
#define Z7_ICACHE_SET_NUM (Z7_ICACHE_SIZE / (Z7_ICACHE_LINE * Z7_ICACHE_WAY_NUM))

#define Z7_DCACHE_SIZE 4096U
#define Z7_DCACHE_LINE 32U
#define Z7_DCACHE_WAY_NUM 2U
#define Z7_DCACHE_SET_NUM (Z7_DCACHE_SIZE / (Z7_DCACHE_LINE * Z7_DCACHE_WAY_NUM))

typedef union Z4_SPR_L1CFG1_union_tag {
  vuint32_t R;
  struct {
    vuint32_t :4;
    vuint32_t ICFISWA:1;
    vuint32_t :2;
    vuint32_t ICBSIZE:2;
    vuint32_t ICREPL:2;
    vuint32_t ICLA:1;
    vuint32_t ICECA:1;
    vuint32_t ICNWAY:8;
    vuint32_t ICSIZE:11;
  } B;
} Z4_SPR_L1CFG1_tag;

typedef union Z7_SPR_L1CFG1_union_tag {
  vuint32_t R;
  struct {
    vuint32_t :4;
    vuint32_t ICFISWA:1;
    vuint32_t :2;
    vuint32_t ICBSIZE:2;
    vuint32_t ICREPL:2;
    vuint32_t ICLA:1;
    vuint32_t ICECA:1;
    vuint32_t ICNWAY:8;
    vuint32_t ICSIZE:11;
  } B;
} Z7_SPR_L1CFG1_tag;

typedef union Z4_SPR_L1CSR0_union_tag {
  vuint32_t R;
  struct {
    vuint32_t WID:2;
    vuint32_t :30;
  } B;
} Z4_SPR_L1CSR0_tag;

typedef union Z7_SPR_L1CSR0_union_tag {
  vuint32_t R;
  struct {
    vuint32_t WID:2;
    vuint32_t :2;
    vuint32_t WDD:2;
    vuint32_t :6;
    vuint32_t DCWA:1;
    vuint32_t :2;
    vuint32_t DCECE:1;
    vuint32_t DCEI:1;
    vuint32_t DCLOC:2;
    vuint32_t :6;
    vuint32_t DCEA:2;
    vuint32_t DCLOINV:1;
    vuint32_t :1;
    vuint32_t DCABT:1;
    vuint32_t DCINV:1;
    vuint32_t DCE:1;
  } B;
} Z7_SPR_L1CSR0_tag;

typedef union Z4_SPR_L1CSR1_union_tag {
  vuint32_t R;
  struct {
    vuint32_t :15;
    vuint32_t ICECE:1;
    vuint32_t ICEI:1;
    vuint32_t ICLOC:2;
    vuint32_t :6;
    vuint32_t ICEA:2;
    vuint32_t ICLOINV:1;
    vuint32_t :1;
    vuint32_t ICABT:1;
    vuint32_t ICINV:1;
    vuint32_t ICE:1;
  } B;
} Z4_SPR_L1CSR1_tag;

typedef union Z7_SPR_L1CSR1_union_tag {
  vuint32_t R;
  struct {
    vuint32_t :15;
    vuint32_t ICECE:1;
    vuint32_t ICEI:1;
    vuint32_t ICLOC:2;
    vuint32_t :6;
    vuint32_t ICEA:2;
    vuint32_t ICLOINV:1;
    vuint32_t :1;
    vuint32_t ICABT:1;
    vuint32_t ICINV:1;
    vuint32_t ICE:1;
  } B;
} Z7_SPR_L1CSR1_tag;

typedef union Z4_SPR_L1FINV1_union_tag {
  vuint32_t R;
  struct {
    vuint32_t :7;
    vuint32_t CWAY:1;
    vuint32_t :12;
    vuint32_t CSET:7;
    vuint32_t :2;
    vuint32_t CCMD:3;
  } B;
} Z4_SPR_L1FINV1_tag;

typedef union Z7_SPR_L1FINV0_union_tag {
  vuint32_t R;
  struct {
    vuint32_t :7;
    vuint32_t CWAY:1;
    vuint32_t :13;
    vuint32_t CSET:6;
    vuint32_t :2;
    vuint32_t CCMD:3;
  } B;
} Z7_SPR_L1FINV0_tag;

typedef union Z7_SPR_L1FINV1_union_tag {
  vuint32_t R;
  struct {
    vuint32_t :7;
    vuint32_t CWAY:1;
    vuint32_t :11;
    vuint32_t CSET:8;
    vuint32_t :2;
    vuint32_t CCMD:3;
  } B;
} Z7_SPR_L1FINV1_tag;

/* SPR */
#define SPR_XER 1 /* Integer Exception Register */
#define SPR_LR 8 /* Link Register */
#define SPR_CTR 9 /* Count Register */
#define SPR_SRR0 26 /* Save/Restore Register */
#define SPR_SRR1 27 /* Save/Restore Register */
#define SPR_PID0 48 /* Process ID Register */
#define SPR_CSRR0 58 /* Critical Save/Restore Register 0 */
#define SPR_CSRR1 59 /* Critical Save/Restore Register 1 */
#define SPR_DEAR 61 /* Data Exception Address Register */
#define SPR_ESR 62 /* Exception Syndrome Register */
#define SPR_IVPR 63 /* Interrupt Vector Prefix Register */
#define SPR_SPRG0 272 /* SPR General 0 */
#define SPR_SPRG1 273 /* SPR General 1 */
#define SPR_SPRG2 274 /* SPR General 2 */
#define SPR_SPRG3 275 /* SPR General 3 */
#define SPR_PIR 286 /* Processor ID Register */
#define SPR_PVR 287 /* Processor Version Register */
#define SPR_DBSR 304 /* Debug Status Register */
#define SPR_DBCR0 308 /* Debug Control Register 0 */
#define SPR_DBCR1 309 /* Debug Control Register 1 */
#define SPR_DBCR2 310 /* Debug Control Register 2 */
#define SPR_IAC1 312 /* Instruction Address Compare 1 */
#define SPR_IAC2 313 /* Instruction Address Compare 2 */
#define SPR_IAC3 314 /* Instruction Address Compare 3 */
#define SPR_IAC4 315 /* Instruction Address Compare 4 */
#define SPR_DAC1 316 /* Data Address Compare 1 */
#define SPR_DAC2 317 /* Data Address Compare 2 */
#define SPR_DVC1 318 /* Data Value Compare 1 */
#define SPR_DVC2 319 /* Data Value Compare 2 */
#define SPR_SPEFSCR 512 /* LSP/EFP APU status and control register */
#define SPR_L1CFG0 515 /* L1 cache config register 0 */
#define SPR_L1CFG1 516 /* L1 cache config register 1 */
#define SPR_NPIDR 517 /* Nexus 3 Process ID register */
#define SPR_DBCR3 561 /* Debug control register */
#define SPR_DBCNT 562 /* Debug Counter register */
#define SPR_DBCR4 563 /* Debug control register */
#define SPR_DBCR5 564 /* Debug control register */
#define SPR_IAC5 565 /* Instruction Address Compare */
#define SPR_IAC6 566 /* Instruction Address Compare */
#define SPR_IAC7 567 /* Instruction Address Compare */
#define SPR_IAC8 568 /* Instruction Address Compare */
#define SPR_MCSRR0 570 /* Machine Check Save/Restore Register */
#define SPR_MCSRR1 571 /* Machine Check Save/Restore Register */
#define SPR_MCSR 572 /* Machine Check Syndrome Register Read */
#define SPR_MCAR 573 /* Machine Check Address Register */
#define SPR_DSRR0 574 /* Debug save/restore register 0 */
#define SPR_DSRR1 575 /* Debug save/restore register 1 */
#define SPR_DDAM 576 /* Debug Data Acquisition Messaging register */
#define SPR_DAC3 592 /* Data Address Compare */
#define SPR_DAC4 593 /* Data Address Compare */
#define SPR_DBCR7 596 /* Debug control register */
#define SPR_DBCR8 597 /* Debug control register */
#define SPR_DDEAR 600 /* Debug Data Effective Address register */
#define SPR_DVC1U4 601 /* Data Value Compare 1 Upper */
#define SPR_DVC2U4 602 /* Data Value Compare 2 Upper */
#define SPR_DBCR6 603 /* Debug control register */
#define SPR_MAS0 624 /* MPU assist register 0 */
#define SPR_MAS1 625 /* MPU assist register 1 */
#define SPR_MAS2 626 /* MPU assist register 2 */
#define SPR_MAS3 627 /* MPU assist register 3 */
#define SPR_EDBRAC0 638 /* External debug resource allocation control register */
#define SPR_MPU0CFG 692 /* MPU0 configuration register */
#define SPR_L1FINV1 959 /* L1 cache flush and invalidate control register */
#define SPR_DEVENT 975 /* Debug Event register */
#define SPR_HID0 1008 /* Hardware implementation dependent reg 0 */
#define SPR_HID1 1009 /* Hardware implementation dependent reg 1 */
#define SPR_L1CSR0 1010 /* L1 cache control and status register 0 */
#define SPR_L1CSR1 1011 /* L1 cache control and status register 1 */
#define SPR_BUCSR 1013 /* Branch Unit Control and Status Register */
#define SPR_MPU0CSR0 1014 /* MPU0 configuration register */
#define SPR_MMUCFG 1015 /* MMU/MPU configuration register */
#define SPR_L1FINV0 1016 /* L1 cache flush and invalidate control register 0 */
#define SPR_SVR 1023 /* System Version Register */

#endif  /* CORE_REG_H_ */
