#ifndef SIUL2_REG_H_
#define SIUL2_REG_H_
/* ============================================================================
   =============================== Module: SIUL2 ==============================
   ============================================================================ */

typedef union SIUL2_MIDR1_union_tag {  /* MCU ID Register #1 */
    vuint32_t R;
    struct {
        vuint32_t PARTNUM:16;
        vuint32_t ED:1;
        vuint32_t PKG:5;
        vuint32_t  :2;
        vuint32_t MAJOR_MASK:4;
        vuint32_t MINOR_MASK:4;
    } B;
} SIUL2_MIDR1_tag;

typedef union SIUL2_MIDR2_union_tag {  /* MCU ID Register #2 */
    vuint32_t R;
    struct {
        vuint32_t SF:1;
        vuint32_t FLASH_SIZE_1:4;
        vuint32_t FLASH_SIZE_2:4;
        vuint32_t  :7;
        vuint32_t FAMILYNUM:8;
        vuint32_t  :8;
    } B;
} SIUL2_MIDR2_tag;

typedef union SIUL2_DISR0_union_tag {  /* DMA/Interrupt Status Flag Register0 */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t EIF15:1;
        vuint32_t EIF14:1;
        vuint32_t EIF13:1;
        vuint32_t EIF12:1;
        vuint32_t EIF11:1;
        vuint32_t EIF10:1;
        vuint32_t EIF9:1;
        vuint32_t EIF8:1;
        vuint32_t EIF7:1;
        vuint32_t EIF6:1;
        vuint32_t EIF5:1;
        vuint32_t EIF4:1;
        vuint32_t EIF3:1;
        vuint32_t EIF2:1;
        vuint32_t EIF1:1;
        vuint32_t EIF0:1;
    } B;
} SIUL2_DISR0_tag;

typedef union SIUL2_DIRER0_union_tag { /* DMA/Interrupt Request Enable Register0 */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t EIRE15:1;
        vuint32_t EIRE14:1;
        vuint32_t EIRE13:1;
        vuint32_t EIRE12:1;
        vuint32_t EIRE11:1;
        vuint32_t EIRE10:1;
        vuint32_t EIRE9:1;
        vuint32_t EIRE8:1;
        vuint32_t EIRE7:1;
        vuint32_t EIRE6:1;
        vuint32_t EIRE5:1;
        vuint32_t EIRE4:1;
        vuint32_t EIRE3:1;
        vuint32_t EIRE2:1;
        vuint32_t EIRE1:1;
        vuint32_t EIRE0:1;
    } B;
} SIUL2_DIRER0_tag;

typedef union SIUL2_DIRSR0_union_tag { /* DMA/Interrupt Request Select Register0 */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t DIRS15:1;
        vuint32_t DIRS14:1;
        vuint32_t DIRS13:1;
        vuint32_t DIRS12:1;
        vuint32_t DIRS11:1;
        vuint32_t DIRS10:1;
        vuint32_t DIRS9:1;
        vuint32_t DIRS8:1;
        vuint32_t DIRS7:1;
        vuint32_t DIRS6:1;
        vuint32_t DIRS5:1;
        vuint32_t DIRS4:1;
        vuint32_t DIRS3:1;
        vuint32_t DIRS2:1;
        vuint32_t DIRS1:1;
        vuint32_t DIRS0:1;
    } B;
} SIUL2_DIRSR0_tag;

typedef union SIUL2_IREER0_union_tag { /* Interrupt Rising-Edge Event Enable Register0 */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t IREE15:1;
        vuint32_t IREE14:1;
        vuint32_t IREE13:1;
        vuint32_t IREE12:1;
        vuint32_t IREE11:1;
        vuint32_t IREE10:1;
        vuint32_t IREE9:1;
        vuint32_t IREE8:1;
        vuint32_t IREE7:1;
        vuint32_t IREE6:1;
        vuint32_t IREE5:1;
        vuint32_t IREE4:1;
        vuint32_t IREE3:1;
        vuint32_t IREE2:1;
        vuint32_t IREE1:1;
        vuint32_t IREE0:1;
    } B;
} SIUL2_IREER0_tag;

typedef union SIUL2_IFEER0_union_tag { /* Interrupt Falling-Edge Event Enable Register0 */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t IFEE15:1;
        vuint32_t IFEE14:1;
        vuint32_t IFEE13:1;
        vuint32_t IFEE12:1;
        vuint32_t IFEE11:1;
        vuint32_t IFEE10:1;
        vuint32_t IFEE9:1;
        vuint32_t IFEE8:1;
        vuint32_t IFEE7:1;
        vuint32_t IFEE6:1;
        vuint32_t IFEE5:1;
        vuint32_t IFEE4:1;
        vuint32_t IFEE3:1;
        vuint32_t IFEE2:1;
        vuint32_t IFEE1:1;
        vuint32_t IFEE0:1;
    } B;
} SIUL2_IFEER0_tag;

typedef union SIUL2_IFER0_union_tag {  /* Interrupt Filter Enable Register0 */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t IFE15:1;
        vuint32_t IFE14:1;
        vuint32_t IFE13:1;
        vuint32_t IFE12:1;
        vuint32_t IFE11:1;
        vuint32_t IFE10:1;
        vuint32_t IFE9:1;
        vuint32_t IFE8:1;
        vuint32_t IFE7:1;
        vuint32_t IFE6:1;
        vuint32_t IFE5:1;
        vuint32_t IFE4:1;
        vuint32_t IFE3:1;
        vuint32_t IFE2:1;
        vuint32_t IFE1:1;
        vuint32_t IFE0:1;
    } B;
} SIUL2_IFER0_tag;

typedef union SIUL2_IFMCR_union_tag {  /* Interrupt Filter Maximum Counter Register */
    vuint32_t R;
    struct {
        vuint32_t  :28;
        vuint32_t MAXCNTx:4;
    } B;
} SIUL2_IFMCR_tag;

typedef union SIUL2_IFCPR_union_tag {  /* Interrupt Filter Clock Prescaler */
    vuint32_t R;
    struct {
        vuint32_t  :28;
        vuint32_t IFCP:4;
    } B;
} SIUL2_IFCPR_tag;

typedef union SIUL2_ISEL4_union_tag {   /* eQADC Command FIFO Trigger Source Registers */
    vuint32_t R;
    struct {
        vuint32_t  :1;
        vuint32_t CTSEL5_A:7;
        vuint32_t  :1;
        vuint32_t CTSEL4_A:7;
        vuint32_t  :1;
        vuint32_t CTSEL3_A:7;
        vuint32_t  :1;
        vuint32_t CTSEL2_A:7;
    } B;
} SIUL2_ISEL4_tag;

typedef union SIUL2_ISEL5_union_tag {   /* eQADC Command FIFO Trigger Source Registers */
    vuint32_t R;
    struct {
        vuint32_t  :1;
        vuint32_t CTSEL1_A:7;
        vuint32_t  :1;
        vuint32_t CTSEL0_A:7;
        vuint32_t  :1;
        vuint32_t CTSEL6_A:7;
        vuint32_t  :1;
        vuint32_t CTSEL7_A:7;
    } B;
} SIUL2_ISEL5_tag;

typedef union SIUL2_ISEL6_union_tag {   /* eQADC Command FIFO Trigger Source Registers */
    vuint32_t R;
    struct {
        vuint32_t  :1;
        vuint32_t CTSEL5_B:7;
        vuint32_t  :1;
        vuint32_t CTSEL4_B:7;
        vuint32_t  :1;
        vuint32_t CTSEL3_B:7;
        vuint32_t  :1;
        vuint32_t CTSEL2_B:7;
    } B;
} SIUL2_ISEL6_tag;

typedef union SIUL2_ISEL7_union_tag {   /* eQADC Command FIFO Trigger Source Registers */
    vuint32_t R;
    struct {
        vuint32_t  :1;
        vuint32_t CTSEL1_B:7;
        vuint32_t  :1;
        vuint32_t CTSEL0_B:7;
        vuint32_t  :1;
        vuint32_t CTSEL6_B:7;
        vuint32_t  :1;
        vuint32_t CTSEL7_B:7;
    } B;
} SIUL2_ISEL7_tag;

typedef union SIUL2_ISEL8_union_tag {   /* eTPU_A Input Select Register */
    vuint32_t R;
    struct {
        vuint32_t  :11;
        vuint32_t ETPU29:1;
        vuint32_t  :3;
        vuint32_t ETPU28:1;
        vuint32_t  :3;
        vuint32_t ETPU27:1;
        vuint32_t  :3;
        vuint32_t ETPU26:1;
        vuint32_t  :3;
        vuint32_t ETPU25:1;
        vuint32_t  :3;
        vuint32_t ETPU24:1;
    } B;
} SIUL2_ISEL8_tag;

typedef union SIUL2_ISEL9_union_tag {   /* eQADC Advance Trigger Source Register */
    vuint32_t R;
    struct {
        vuint32_t  :11;
        vuint32_t EETSEL0ADV_A:5;
        vuint32_t  :11;
        vuint32_t EETSEL0ADV_B:5;
    } B;
} SIUL2_ISEL9_tag;

typedef union SIUL2_EIISR_union_tag {   /* External IRQ Input Select Register */
    vuint32_t R;
    struct {
        vuint32_t ESEL15:2;
        vuint32_t ESEL14:2;
        vuint32_t ESEL13:2;
        vuint32_t ESEL12:2;
        vuint32_t ESEL11:2;
        vuint32_t ESEL10:2;
        vuint32_t ESEL9:2;
        vuint32_t ESEL8:2;
        vuint32_t ESEL7:2;
        vuint32_t ESEL6:2;
        vuint32_t ESEL5:2;
        vuint32_t ESEL4:2;
        vuint32_t ESEL3:2;
        vuint32_t ESEL2:2;
        vuint32_t ESEL1:2;
        vuint32_t ESEL0:2;
    } B;
} SIUL2_EIISR_tag;

typedef union SIUL2_DISR_union_tag {   /* DSPI Input Select Register */
    vuint32_t R;
    struct {
        vuint32_t SINSELA:2;
        vuint32_t SSSELA:2;
        vuint32_t SCKSELA:2;
        vuint32_t :2;
        vuint32_t SINSELB:2;
        vuint32_t SSSELB:2;
        vuint32_t SCKSELB:2;
        vuint32_t :2;
        vuint32_t SINSELC:2;
        vuint32_t SSSELC:2;
        vuint32_t SCKSELC:2;
        vuint32_t :2;
        vuint32_t SINSELD:2;
        vuint32_t SSSELD:2;
        vuint32_t SCKSELD:2;
        vuint32_t :2;
    } B;
} SIUL2_DISR_tag;

typedef union SIUL2_SCR0_union_tag {   /* SoC Configuration Register0 */
    vuint32_t R;
    struct {
        vuint32_t FEC_MODE:1;
        vuint32_t  :7;
        vuint32_t ESR0_ASSERT:1;
        vuint32_t  :23;
    } B;
} SIUL2_SCR0_tag;

typedef union SIUL2_DSPI_DSPIH_union_tag {  /* Mask-Output High Register */
    vuint32_t R;
    struct {
        vuint32_t MASK0:1;
        vuint32_t MASK1:1;
        vuint32_t MASK2:1;
        vuint32_t MASK3:1;
        vuint32_t MASK4:1;
        vuint32_t MASK5:1;
        vuint32_t MASK6:1;
        vuint32_t MASK7:1;
        vuint32_t MASK8:1;
        vuint32_t MASK9:1;
        vuint32_t MASK10:1;
        vuint32_t MASK11:1;
        vuint32_t MASK12:1;
        vuint32_t MASK13:1;
        vuint32_t MASK14:1;
        vuint32_t MASK15:1;
        vuint32_t DATA0:1;
        vuint32_t DATA1:1;
        vuint32_t DATA2:1;
        vuint32_t DATA3:1;
        vuint32_t DATA4:1;
        vuint32_t DATA5:1;
        vuint32_t DATA6:1;
        vuint32_t DATA7:1;
        vuint32_t DATA8:1;
        vuint32_t DATA9:1;
        vuint32_t DATA10:1;
        vuint32_t DATA11:1;
        vuint32_t DATA12:1;
        vuint32_t DATA13:1;
        vuint32_t DATA14:1;
        vuint32_t DATA15:1;
    } B;
} SIUL2_DSPI_DSPIH_tag;

typedef union SIUL2_DSPI_DSPIL_union_tag {  /* Mask-Output Low Register */
    vuint32_t R;
    struct {
        vuint32_t MASK16:1;
        vuint32_t MASK17:1;
        vuint32_t MASK18:1;
        vuint32_t MASK19:1;
        vuint32_t MASK20:1;
        vuint32_t MASK21:1;
        vuint32_t MASK22:1;
        vuint32_t MASK23:1;
        vuint32_t MASK24:1;
        vuint32_t MASK25:1;
        vuint32_t MASK26:1;
        vuint32_t MASK27:1;
        vuint32_t MASK28:1;
        vuint32_t MASK29:1;
        vuint32_t MASK30:1;
        vuint32_t MASK31:1;
        vuint32_t DATA16:1;
        vuint32_t DATA17:1;
        vuint32_t DATA18:1;
        vuint32_t DATA19:1;
        vuint32_t DATA20:1;
        vuint32_t DATA21:1;
        vuint32_t DATA22:1;
        vuint32_t DATA23:1;
        vuint32_t DATA24:1;
        vuint32_t DATA25:1;
        vuint32_t DATA26:1;
        vuint32_t DATA27:1;
        vuint32_t DATA28:1;
        vuint32_t DATA29:1;
        vuint32_t DATA30:1;
        vuint32_t DATA31:1;
    } B;
} SIUL2_DSPI_DSPIL_tag;

typedef struct SIUL2_DSPI_struct_tag {
    SIUL2_DSPI_DSPIH_tag DSPIH;         /* Mask-Output High Register */
    SIUL2_DSPI_DSPIL_tag DSPIL;         /* Mask-Output Low Register */
} SIUL2_DSPI_tag;

typedef union SIUL2_ETPUBA_union_tag {  /* Serialized Output Signal Selection Register for DSPI_A */
    vuint32_t R;
    struct {
        vuint32_t ETPUB15:1;
        vuint32_t ETPUB14:1;
        vuint32_t ETPUB13:1;
        vuint32_t ETPUB12:1;
        vuint32_t ETPUB11:1;
        vuint32_t ETPUB10:1;
        vuint32_t ETPUB9:1;
        vuint32_t ETPUB8:1;
        vuint32_t ETPUB7:1;
        vuint32_t ETPUB6:1;
        vuint32_t ETPUB5:1;
        vuint32_t ETPUB4:1;
        vuint32_t ETPUB3:1;
        vuint32_t ETPUB2:1;
        vuint32_t ETPUB1:1;
        vuint32_t ETPUB0:1;
        vuint32_t ETPUB31:1;
        vuint32_t ETPUB30:1;
        vuint32_t ETPUB29:1;
        vuint32_t ETPUB28:1;
        vuint32_t ETPUB27:1;
        vuint32_t ETPUB26:1;
        vuint32_t ETPUB25:1;
        vuint32_t ETPUB24:1;
        vuint32_t ETPUB23:1;
        vuint32_t ETPUB22:1;
        vuint32_t ETPUB21:1;
        vuint32_t ETPUB20:1;
        vuint32_t ETPUB19:1;
        vuint32_t ETPUB18:1;
        vuint32_t ETPUB17:1;
        vuint32_t ETPUB16:1;
    } B;
} SIUL2_ETPUBA_tag;

typedef union SIUL2_EMIOSA_union_tag {  /* Serialized Output Signal Selection Register for DSPI_A */
    vuint32_t R;
    struct {
        vuint32_t EMIOS0_7_OUT0:1;
        vuint32_t EMIOS0_6_OUT1:1;
        vuint32_t EMIOS0_5_OUT2:1;
        vuint32_t EMIOS0_4_OUT3:1;
        vuint32_t EMIOS0_3_OUT4:1;
        vuint32_t EMIOS0_2_OUT5:1;
        vuint32_t EMIOS0_1_OUT6:1;
        vuint32_t EMIOS0_0_OUT7:1;
        vuint32_t EMIOS1_0_OUT8:1;
        vuint32_t EMIOS1_1_OUT9:1;
        vuint32_t EMIOS1_2_OUT10:1;
        vuint32_t EMIOS1_3_OUT11:1;
        vuint32_t EMIOS1_4_OUT12:1;
        vuint32_t EMIOS1_5_OUT13:1;
        vuint32_t EMIOS1_6_OUT14:1;
        vuint32_t EMIOS1_7_OUT15:1;
        vuint32_t EMIOS0_16_OUT16:1;
        vuint32_t EMIOS0_17_OUT17:1;
        vuint32_t EMIOS0_18_OUT18:1;
        vuint32_t EMIOS0_19_OUT19:1;
        vuint32_t EMIOS0_20_OUT20:1;
        vuint32_t EMIOS0_21_OUT21:1;
        vuint32_t EMIOS0_22_OUT22:1;
        vuint32_t EMIOS0_23_OUT23:1;
        vuint32_t EMIOS0_0_OUT24:1;
        vuint32_t EMIOS0_1_OUT25:1;
        vuint32_t EMIOS0_2_OUT26:1;
        vuint32_t EMIOS0_3_OUT27:1;
        vuint32_t EMIOS0_4_OUT28:1;
        vuint32_t EMIOS0_5_OUT29:1;
        vuint32_t EMIOS0_6_OUT30:1;
        vuint32_t EMIOS0_7_OUT31:1;
    } B;
} SIUL2_EMIOSA_tag;

typedef union SIUL2_DSPIAHLA_union_tag {    /* Serialized Output Signal Selection Register for DSPI_A */
    vuint32_t R;
    struct {
        vuint32_t DSPIAH0:1;
        vuint32_t DSPIAH1:1;
        vuint32_t DSPIAH2:1;
        vuint32_t DSPIAH3:1;
        vuint32_t DSPIAH4:1;
        vuint32_t DSPIAH5:1;
        vuint32_t DSPIAH6:1;
        vuint32_t DSPIAH7:1;
        vuint32_t DSPIAH8:1;
        vuint32_t DSPIAH9:1;
        vuint32_t DSPIAH10:1;
        vuint32_t DSPIAH11:1;
        vuint32_t DSPIAH12:1;
        vuint32_t DSPIAH13:1;
        vuint32_t DSPIAH14:1;
        vuint32_t DSPIAH15:1;
        vuint32_t DSPIAL16:1;
        vuint32_t DSPIAL17:1;
        vuint32_t DSPIAL18:1;
        vuint32_t DSPIAL19:1;
        vuint32_t DSPIAL20:1;
        vuint32_t DSPIAL21:1;
        vuint32_t DSPIAL22:1;
        vuint32_t DSPIAL23:1;
        vuint32_t DSPIAL24:1;
        vuint32_t DSPIAL25:1;
        vuint32_t DSPIAL26:1;
        vuint32_t DSPIAL27:1;
        vuint32_t DSPIAL28:1;
        vuint32_t DSPIAL29:1;
        vuint32_t DSPIAL30:1;
        vuint32_t DSPIAL31:1;
    } B;
} SIUL2_DSPIAHLA_tag;

typedef union SIUL2_ETPUAB_union_tag {  /* Serialized Output Signal Selection Register for DSPI_B */
    vuint32_t R;
    struct {
        vuint32_t ETPUA23:1;
        vuint32_t ETPUA22:1;
        vuint32_t ETPUA21:1;
        vuint32_t ETPUA20:1;
        vuint32_t ETPUA19:1;
        vuint32_t ETPUA18:1;
        vuint32_t ETPUA17:1;
        vuint32_t ETPUA16:1;
        vuint32_t ETPUA29:1;
        vuint32_t ETPUA28:1;
        vuint32_t ETPUA27:1;
        vuint32_t ETPUA26:1;
        vuint32_t ETPUA25:1;
        vuint32_t ETPUA24:1;
        vuint32_t ETPUA31:1;
        vuint32_t ETPUA30:1;
        vuint32_t ETPUA12:1;
        vuint32_t ETPUA13:1;
        vuint32_t ETPUA14:1;
        vuint32_t ETPUA15:1;
        vuint32_t ETPUA0:1;
        vuint32_t ETPUA1:1;
        vuint32_t ETPUA2:1;
        vuint32_t ETPUA3:1;
        vuint32_t ETPUA4:1;
        vuint32_t ETPUA5:1;
        vuint32_t ETPUA6:1;
        vuint32_t ETPUA7:1;
        vuint32_t ETPUA8:1;
        vuint32_t ETPUA9:1;
        vuint32_t ETPUA10:1;
        vuint32_t ETPUA11:1;
    } B;
} SIUL2_ETPUAB_tag;

typedef union SIUL2_EMIOSB_union_tag {  /* Serialized Output Signal Selection Register for DSPI_B */
    vuint32_t R;
    struct {
        vuint32_t EMIOS1_3_OUT0:1;
        vuint32_t EMIOS1_2_OUT1:1;
        vuint32_t EMIOS1_1_OUT2:1;
        vuint32_t EMIOS1_0_OUT3:1;
        vuint32_t EMIOS0_6_OUT4:1;
        vuint32_t EMIOS0_5_OUT5:1;
        vuint32_t EMIOS0_4_OUT6:1;
        vuint32_t EMIOS0_3_OUT7:1;
        vuint32_t EMIOS0_2_OUT8:1;
        vuint32_t EMIOS0_1_OUT9:1;
        vuint32_t EMIOS0_0_OUT10:1;
        vuint32_t EMIOS0_23_OUT11:1;
        vuint32_t EMIOS1_7_OUT12:1;
        vuint32_t EMIOS1_6_OUT13:1;
        vuint32_t EMIOS1_5_OUT14:1;
        vuint32_t EMIOS1_4_OUT15:1;
        vuint32_t EMIOS0_23_OUT16:1;
        vuint32_t EMIOS1_7_OUT17:1;
        vuint32_t EMIOS1_6_OUT18:1;
        vuint32_t EMIOS1_5_OUT19:1;
        vuint32_t EMIOS1_4_OUT20:1;
        vuint32_t EMIOS1_3_OUT21:1;
        vuint32_t EMIOS1_2_OUT22:1;
        vuint32_t EMIOS1_1_OUT23:1;
        vuint32_t EMIOS1_0_OUT24:1;
        vuint32_t EMIOS0_6_OUT25:1;
        vuint32_t EMIOS0_5_OUT26:1;
        vuint32_t EMIOS0_4_OUT27:1;
        vuint32_t EMIOS0_3_OUT28:1;
        vuint32_t EMIOS0_2_OUT29:1;
        vuint32_t EMIOS0_1_OUT30:1;
        vuint32_t EMIOS0_0_OUT31:1;
    } B;
} SIUL2_EMIOSB_tag;

typedef union SIUL2_DSPIBHLB_union_tag {    /* Serialized Output Signal Selection Register for DSPI_B */
    vuint32_t R;
    struct {
        vuint32_t DSPIBH0:1;
        vuint32_t DSPIBH1:1;
        vuint32_t DSPIBH2:1;
        vuint32_t DSPIBH3:1;
        vuint32_t DSPIBH4:1;
        vuint32_t DSPIBH5:1;
        vuint32_t DSPIBH6:1;
        vuint32_t DSPIBH7:1;
        vuint32_t DSPIBH8:1;
        vuint32_t DSPIBH9:1;
        vuint32_t DSPIBH10:1;
        vuint32_t DSPIBH11:1;
        vuint32_t DSPIBH12:1;
        vuint32_t DSPIBH13:1;
        vuint32_t DSPIBH14:1;
        vuint32_t DSPIBH15:1;
        vuint32_t DSPIBL16:1;
        vuint32_t DSPIBL17:1;
        vuint32_t DSPIBL18:1;
        vuint32_t DSPIBL19:1;
        vuint32_t DSPIBL20:1;
        vuint32_t DSPIBL21:1;
        vuint32_t DSPIBL22:1;
        vuint32_t DSPIBL23:1;
        vuint32_t DSPIBL24:1;
        vuint32_t DSPIBL25:1;
        vuint32_t DSPIBL26:1;
        vuint32_t DSPIBL27:1;
        vuint32_t DSPIBL28:1;
        vuint32_t DSPIBL29:1;
        vuint32_t DSPIBL30:1;
        vuint32_t DSPIBL31:1;
    } B;
} SIUL2_DSPIBHLB_tag;

typedef union SIUL2_ETPUAC_union_tag {  /* Serialized Output Signal Selection Register for DSPI_C */
    vuint32_t R;
    struct {
        vuint32_t ETPUA12:1;
        vuint32_t ETPUA13:1;
        vuint32_t ETPUA14:1;
        vuint32_t ETPUA15:1;
        vuint32_t ETPUA0:1;
        vuint32_t ETPUA1:1;
        vuint32_t ETPUA2:1;
        vuint32_t ETPUA3:1;
        vuint32_t ETPUA4:1;
        vuint32_t ETPUA5:1;
        vuint32_t ETPUA6:1;
        vuint32_t ETPUA7:1;
        vuint32_t ETPUA8:1;
        vuint32_t ETPUA9:1;
        vuint32_t ETPUA10:1;
        vuint32_t ETPUA11:1;
        vuint32_t ETPUA23:1;
        vuint32_t ETPUA22:1;
        vuint32_t ETPUA21:1;
        vuint32_t ETPUA20:1;
        vuint32_t ETPUA19:1;
        vuint32_t ETPUA18:1;
        vuint32_t ETPUA17:1;
        vuint32_t ETPUA16:1;
        vuint32_t ETPUA29:1;
        vuint32_t ETPUA28:1;
        vuint32_t ETPUA27:1;
        vuint32_t ETPUA26:1;
        vuint32_t ETPUA25:1;
        vuint32_t ETPUA24:1;
        vuint32_t ETPUA31:1;
        vuint32_t ETPUA30:1;
    } B;
} SIUL2_ETPUAC_tag;

typedef union SIUL2_EMIOSC_union_tag {  /* Serialized Output Signal Selection Register for DSPI_C */
    vuint32_t R;
    struct {
        vuint32_t EMIOS1_4_OUT0:1;
        vuint32_t EMIOS1_5_OUT1:1;
        vuint32_t EMIOS1_6_OUT2:1;
        vuint32_t EMIOS1_7_OUT3:1;
        vuint32_t EMIOS0_23_OUT4:1;
        vuint32_t EMIOS0_0_OUT5:1;
        vuint32_t EMIOS0_1_OUT6:1;
        vuint32_t EMIOS0_2_OUT7:1;
        vuint32_t EMIOS0_3_OUT8:1;
        vuint32_t EMIOS0_4_OUT9:1;
        vuint32_t EMIOS0_5_OUT10:1;
        vuint32_t EMIOS0_6_OUT11:1;
        vuint32_t EMIOS1_0_OUT12:1;
        vuint32_t EMIOS1_1_OUT13:1;
        vuint32_t EMIOS1_2_OUT14:1;
        vuint32_t EMIOS1_3_OUT15:1;
        vuint32_t EMIOS0_0_OUT16:1;
        vuint32_t EMIOS0_1_OUT17:1;
        vuint32_t EMIOS0_2_OUT18:1;
        vuint32_t EMIOS0_3_OUT19:1;
        vuint32_t EMIOS0_4_OUT20:1;
        vuint32_t EMIOS0_5_OUT21:1;
        vuint32_t EMIOS0_6_OUT22:1;
        vuint32_t EMIOS1_0_OUT23:1;
        vuint32_t EMIOS1_1_OUT24:1;
        vuint32_t EMIOS1_2_OUT25:1;
        vuint32_t EMIOS1_3_OUT26:1;
        vuint32_t EMIOS1_4_OUT27:1;
        vuint32_t EMIOS1_5_OUT28:1;
        vuint32_t EMIOS1_6_OUT29:1;
        vuint32_t EMIOS1_7_OUT30:1;
        vuint32_t EMIOS0_23_OUT31:1;
    } B;
} SIUL2_EMIOSC_tag;

typedef union SIUL2_DSPICHLC_union_tag {    /* Serialized Output Signal Selection Register for DSPI_C */
    vuint32_t R;
    struct {
        vuint32_t DSPICH0:1;
        vuint32_t DSPICH1:1;
        vuint32_t DSPICH2:1;
        vuint32_t DSPICH3:1;
        vuint32_t DSPICH4:1;
        vuint32_t DSPICH5:1;
        vuint32_t DSPICH6:1;
        vuint32_t DSPICH7:1;
        vuint32_t DSPICH8:1;
        vuint32_t DSPICH9:1;
        vuint32_t DSPICH10:1;
        vuint32_t DSPICH11:1;
        vuint32_t DSPICH12:1;
        vuint32_t DSPICH13:1;
        vuint32_t DSPICH14:1;
        vuint32_t DSPICH15:1;
        vuint32_t DSPICL16:1;
        vuint32_t DSPICL17:1;
        vuint32_t DSPICL18:1;
        vuint32_t DSPICL19:1;
        vuint32_t DSPICL20:1;
        vuint32_t DSPICL21:1;
        vuint32_t DSPICL22:1;
        vuint32_t DSPICL23:1;
        vuint32_t DSPICL24:1;
        vuint32_t DSPICL25:1;
        vuint32_t DSPICL26:1;
        vuint32_t DSPICL27:1;
        vuint32_t DSPICL28:1;
        vuint32_t DSPICL29:1;
        vuint32_t DSPICL30:1;
        vuint32_t DSPICL31:1;
    } B;
} SIUL2_DSPICHLC_tag;

typedef union SIUL2_ETPUBC_union_tag {  /* Serialized Output Signal Selection Register for DSPI_C */
    vuint32_t R;
    struct {
        vuint32_t ETPUB15:1;
        vuint32_t ETPUB14:1;
        vuint32_t ETPUB13:1;
        vuint32_t ETPUB12:1;
        vuint32_t ETPUB11:1;
        vuint32_t ETPUB10:1;
        vuint32_t ETPUB9:1;
        vuint32_t ETPUB8:1;
        vuint32_t ETPUB7:1;
        vuint32_t ETPUB6:1;
        vuint32_t ETPUB5:1;
        vuint32_t ETPUB4:1;
        vuint32_t ETPUB3:1;
        vuint32_t ETPUB2:1;
        vuint32_t ETPUB1:1;
        vuint32_t ETPUB0:1;
        vuint32_t ETPUB31:1;
        vuint32_t ETPUB30:1;
        vuint32_t ETPUB29:1;
        vuint32_t ETPUB28:1;
        vuint32_t ETPUB27:1;
        vuint32_t ETPUB26:1;
        vuint32_t ETPUB25:1;
        vuint32_t ETPUB24:1;
        vuint32_t ETPUB23:1;
        vuint32_t ETPUB22:1;
        vuint32_t ETPUB21:1;
        vuint32_t ETPUB20:1;
        vuint32_t ETPUB19:1;
        vuint32_t ETPUB18:1;
        vuint32_t ETPUB17:1;
        vuint32_t ETPUB16:1;
    } B;
} SIUL2_ETPUBC_tag;

typedef union SIUL2_ETPUBD_union_tag {  /* Serialized Output Signal Selection Register for DSPI_D */
    vuint32_t R;
    struct {
        vuint32_t ETPUB21:1;
        vuint32_t ETPUB20:1;
        vuint32_t ETPUB19:1;
        vuint32_t ETPUB18:1;
        vuint32_t ETPUB17:1;
        vuint32_t ETPUB16:1;
        vuint32_t  :4;
        vuint32_t ETPUB29:1;
        vuint32_t ETPUB28:1;
        vuint32_t ETPUB27:1;
        vuint32_t ETPUB26:1;
        vuint32_t ETPUB25:1;
        vuint32_t ETPUB24:1;
        vuint32_t  :16;
    } B;
} SIUL2_ETPUBD_tag;

typedef union SIUL2_EMIOSD_union_tag {  /* Serialized Output Signal Selection Register for DSPI_D */
    vuint32_t R;
    struct {
        vuint32_t  :6;
        vuint32_t EMIOS1_3_OUT6:1;
        vuint32_t EMIOS1_2_OUT7:1;
        vuint32_t EMIOS1_5_OUT8:1;
        vuint32_t EMIOS1_4_OUT9:1;
        vuint32_t  :22;
    } B;
} SIUL2_EMIOSD_tag;

typedef union SIUL2_DSPIDHLD_union_tag {    /* Serialized Output Signal Selection Register for DSPI_D */
    vuint32_t R;
    struct {
        vuint32_t DSPIDH0:1;
        vuint32_t DSPIDH1:1;
        vuint32_t DSPIDH2:1;
        vuint32_t DSPIDH3:1;
        vuint32_t DSPIDH4:1;
        vuint32_t DSPIDH5:1;
        vuint32_t DSPIDH6:1;
        vuint32_t DSPIDH7:1;
        vuint32_t DSPIDH8:1;
        vuint32_t DSPIDH9:1;
        vuint32_t DSPIDH10:1;
        vuint32_t DSPIDH11:1;
        vuint32_t DSPIDH12:1;
        vuint32_t DSPIDH13:1;
        vuint32_t DSPIDH14:1;
        vuint32_t DSPIDH15:1;
        vuint32_t DSPIDL16:1;
        vuint32_t DSPIDL17:1;
        vuint32_t DSPIDL18:1;
        vuint32_t DSPIDL19:1;
        vuint32_t DSPIDL20:1;
        vuint32_t DSPIDL21:1;
        vuint32_t DSPIDL22:1;
        vuint32_t DSPIDL23:1;
        vuint32_t DSPIDL24:1;
        vuint32_t DSPIDL25:1;
        vuint32_t DSPIDL26:1;
        vuint32_t DSPIDL27:1;
        vuint32_t DSPIDL28:1;
        vuint32_t DSPIDL29:1;
        vuint32_t DSPIDL30:1;
        vuint32_t DSPIDL31:1;
    } B;
} SIUL2_DSPIDHLD_tag;

typedef union SIUL2_MSCR_IO_union_tag { /* I/O Pin Multiplexed Signal Configuration Registers */
    vuint32_t R;
    struct {
        vuint32_t  :1;
        vuint32_t OERC:3;
        vuint32_t  :1;
        vuint32_t ODC:3;
        vuint32_t SMC:1;
        vuint32_t APC:1;
        vuint32_t ILS:2;
        vuint32_t IBE:1;
        vuint32_t HYS:1;
        vuint32_t WPDE:1;
        vuint32_t WPUE:1;
        vuint32_t INV:1;
        vuint32_t  :7;
        vuint32_t SSS:8;
    } B;
} SIUL2_MSCR_IO_tag;

typedef union SIUL2_MSCR_MUX_union_tag {    /* Multiplexed Signal Configuration Register for Multiplexed Input Selection */
    vuint32_t R;
    struct {
        vuint32_t  :16;
        vuint32_t INV:1;
        vuint32_t  :7;
        vuint32_t SSS:8;
    } B;
} SIUL2_MSCR_MUX_tag;

typedef union SIUL2_GPDO_union_tag {    /* GPIO Pad Data Out Register */
    vuint8_t R;
    struct {
        vuint8_t  :7;
        vuint8_t PDO:1;
    } B;
} SIUL2_GPDO_tag;

typedef union SIUL2_GPDI_union_tag {    /* GPIO Pad Data In Register */
    vuint8_t R;
    struct {
        vuint8_t  :7;
        vuint8_t PDI:1;
    } B;
} SIUL2_GPDI_tag;

typedef union SIUL2_PGPDO_union_tag {   /* Parallel GPIO Pad Data Out Register */
    vuint16_t R;
    struct {
        vuint16_t PPDO:16;
    } B;
} SIUL2_PGPDO_tag;

typedef union SIUL2_PGPDI_union_tag {   /* Parallel GPIO Pad Data In Register */
    vuint16_t R;
    struct {
        vuint16_t PPDI:16;
    } B;
} SIUL2_PGPDI_tag;

typedef union SIUL2_MPGPDO_union_tag {  /* Masked Parallel GPIO Pad Data Out Register */
    vuint32_t R;
    struct {
        vuint32_t MASK:16;
        vuint32_t MPPDO:16;
    } B;
} SIUL2_MPGPDO_tag;

typedef union SIUL2_FLT_CH_RE_union_tag {  /* Filter Channel n Parameter 0 Register, n = 0:75 */
    vuint32_t R;
    struct {
        vuint32_t :8;
        vuint32_t FLT_RE_CNT:24;
    } B;
} SIUL2_FLT_CH_RE_tag;

typedef union SIUL2_FLT_CH_FE_union_tag {  /* Filter Channel n Parameter 1 Register, n = 0:75 */
    vuint32_t R;
    struct {
        vuint32_t :8;
        vuint32_t FLT_FE_CNT:24;
    } B;
} SIUL2_FLT_CH_FE_tag;

typedef union SIUL2_FLT_CH_CTRL0_union_tag {  /* Filter Channel n Control 0 Register, n = 0:7 */
    vuint8_t R;
    struct {
        vuint8_t :3;
        vuint8_t CTR_FE:1;
        vuint8_t MODE_FE:1;
        vuint8_t CTR_RE:1;
        vuint8_t MODE_RE:1;
        vuint8_t FLT_EN:1;
    } B;
} SIUL2_FLT_CH_CTRL0_tag;

typedef union SIUL2_FLT_CH_CTRL1_union_tag {  /* Filter Channel n Control 1 Register, n = 0:7 */
    vuint32_t R;
    struct {
        vuint32_t FLT_CLK_DIV:32;
    } B;
} SIUL2_FLT_CH_CTRL1_tag;

struct SIUL2_tag {
    uint8_t SIUL2_reserved0[4];
    SIUL2_MIDR1_tag MIDR1;              /* MCU ID Register #1 (Offset: 0x0004) */
    SIUL2_MIDR2_tag MIDR2;              /* MCU ID Register #2 (Offset: 0x0008) */
    uint8_t SIUL2_reserved1[4];
    SIUL2_DISR0_tag DISR0;              /* DMA/Interrupt Status Flag Register0 (Offset: 0x0010) */
    uint8_t SIUL2_reserved2[4];
    SIUL2_DIRER0_tag DIRER0;            /* DMA/Interrupt Request Enable Register0 (Offset: 0x0018) */
    uint8_t SIUL2_reserved3[4];
    SIUL2_DIRSR0_tag DIRSR0;            /* DMA/Interrupt Request Select Register0 (Offset: 0x0020) */
    uint8_t SIUL2_reserved4[4];
    SIUL2_IREER0_tag IREER0;            /* Interrupt Rising-Edge Event Enable Register0 (Offset: 0x0028) */
    uint8_t SIUL2_reserved5[4];
    SIUL2_IFEER0_tag IFEER0;            /* Interrupt Falling-Edge Event Enable Register0 (Offset: 0x0030) */
    uint8_t SIUL2_reserved6[4];
    SIUL2_IFER0_tag IFER0;              /* Interrupt Filter Enable Register0 (Offset: 0x0038) */
    uint8_t SIUL2_reserved7[4];
    SIUL2_IFMCR_tag IFMCR[32];          /* Interrupt Filter Maximum Counter Register (Offset: 0x0040) */
    SIUL2_IFCPR_tag IFCPR;              /* Interrupt Filter Clock Prescaler (Offset: 0x00C0) */
    SIUL2_ISEL4_tag ISEL4;              /* eQADC Command FIFO Trigger Source Registers (SIU_ISEL4) (Offset: 0x00C4) */
    SIUL2_ISEL5_tag ISEL5;              /* eQADC Command FIFO Trigger Source Registers (SIU_ISEL5) (Offset: 0x00C8) */
    SIUL2_ISEL6_tag ISEL6;              /* eQADC Command FIFO Trigger Source Registers (SIU_ISEL6) (Offset: 0x00CC) */
    SIUL2_ISEL7_tag ISEL7;              /* eQADC Command FIFO Trigger Source Registers (SIU_ISEL7) (Offset: 0x00D0) */
    SIUL2_ISEL8_tag ISEL8;              /* eTPU_A Input Select Register (SIU_ISEL8) (Offset: 0x00D4) */
    SIUL2_ISEL9_tag ISEL9;              /* eQADC Advance Trigger Source Register (SIU_ISEL9) (Offset: 0x00D8) */
    SIUL2_EIISR_tag EIISR;              /* External IRQ Input Select Register, (SIU_EIISR) (Offset: 0x00DC) */
    SIUL2_DISR_tag DISR;                /* DSPI Input Select Register, (SIU_DISR) (Offset: 0x00E0) */
    uint8_t SIUL2_reserved8[28];
    SIUL2_SCR0_tag SCR0;                /* SoC Configuration Register0 (Offset: 0x0100) */
    uint8_t SIUL2_reserved9[124];
    SIUL2_DSPI_tag DSPI[4];             /* Mask-Output High/Low Register (Offset: 0x0180) */
    SIUL2_ETPUBA_tag ETPUBA;            /* Serialized Output Signal Selection Register for DSPI_A (Offset: 0x01A0) */
    SIUL2_EMIOSA_tag EMIOSA;            /* Serialized Output Signal Selection Register for DSPI_A (Offset: 0x01A4) */
    SIUL2_DSPIAHLA_tag DSPIAHLA;        /* Serialized Output Signal Selection Register for DSPI_A (Offset: 0x01A8) */
    SIUL2_ETPUAB_tag ETPUAB;            /* Serialized Output Signal Selection Register for DSPI_B (Offset: 0x01AC) */
    SIUL2_EMIOSB_tag EMIOSB;            /* Serialized Output Signal Selection Register for DSPI_B (Offset: 0x01B0) */
    SIUL2_DSPIBHLB_tag DSPIBHLB;        /* Serialized Output Signal Selection Register for DSPI_B (Offset: 0x01B4) */
    SIUL2_ETPUAC_tag ETPUAC;            /* Serialized Output Signal Selection Register for DSPI_C (Offset: 0x01B8) */
    SIUL2_EMIOSC_tag EMIOSC;            /* Serialized Output Signal Selection Register for DSPI_C (Offset: 0x01BC) */
    SIUL2_DSPICHLC_tag DSPICHLC;        /* Serialized Output Signal Selection Register for DSPI_C (Offset: 0x01C0) */
    SIUL2_ETPUBC_tag ETPUBC;            /* Serialized Output Signal Selection Register for DSPI_C (Offset: 0x01C4) */
    SIUL2_ETPUBD_tag ETPUBD;            /* Serialized Output Signal Selection Register for DSPI_D (Offset: 0x01C8) */
    SIUL2_EMIOSD_tag EMIOSD;            /* Serialized Output Signal Selection Register for DSPI_D (Offset: 0x01CC) */
    SIUL2_DSPIDHLD_tag DSPIDHLD;        /* Serialized Output Signal Selection Register for DSPI_D (Offset: 0x01D0) */
    uint8_t SIUL2_reserved10[108];
    SIUL2_MSCR_IO_tag MSCR_IO[512];     /* I/O Pin Multiplexed Signal Configuration Registers (Offset: 0x0240) */
    SIUL2_MSCR_MUX_tag MSCR_MUX[512];   /* Multiplexed Signal Configuration Register for Multiplexed Input Selection (Offset: 0x0A40) */
    uint8_t SIUL2_reserved11[192];
    SIUL2_GPDO_tag GPDO[512];           /* GPIO Pad Data Out Register (Offset: 0x1300) */
    SIUL2_GPDI_tag GPDI[512];           /* GPIO Pad Data In Register (Offset: 0x1500) */
    SIUL2_PGPDO_tag PGPDO[32];          /* Parallel GPIO Pad Data Out Register (Offset: 0x1700) */
    SIUL2_PGPDI_tag PGPDI[32];          /* Parallel GPIO Pad Data In Register (Offset: 0x1740) */
    SIUL2_MPGPDO_tag MPGPDO[32];        /* Masked Parallel GPIO Pad Data Out Register (Offset: 0x1780) */
    SIUL2_FLT_CH_RE_tag FLT_CH_RE[76];  /* Filter Channel n Parameter 0 Register, n = 0:75 (Offset: 0x1800) */
    SIUL2_FLT_CH_FE_tag FLT_CH_FE[76];  /* Filter Channel n Parameter 0 Register, n = 0:75 (Offset: 0x1930) */
    SIUL2_FLT_CH_CTRL0_tag FLT_CH_CTRL0[8]; /* Filter Channel n Control 0 Register, n = 0:7 (Offset: 0x1A60) */
    SIUL2_FLT_CH_CTRL1_tag FLT_CH_CTRL1[8]; /* Filter Channel n Control 1 Register, n = 0:7 (Offset: 0x1A68) */
};

typedef struct SIUL2_tag SIUL2_TagType;

/* @brief SIUL2 base address */
#define SIUL2_BASEADDR              ((uint32_t)0xFFFC0000UL)

/* @brief SIUL2 base pointer */
#define SIUL2_PTR                   ((SIUL2_TagType *) SIUL2_BASEADDR)



#endif  /* SIUL2_REG_H_ */
