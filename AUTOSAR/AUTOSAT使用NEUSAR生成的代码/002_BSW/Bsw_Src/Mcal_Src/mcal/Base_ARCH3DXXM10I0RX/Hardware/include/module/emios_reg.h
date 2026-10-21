#ifndef EMIOS_REG_H_
#define EMIOS_REG_H_

/* ============================================================================
   =============================== Module: eMIOS ==============================
   ============================================================================ */

/*!
 * @addtogroup eMIOS_Peripheral_Access_Layer eMIOS Peripheral Access Layer
 * @{
 */


/** eMIOS - Size of Registers Arrays */
#define eMIOS_UC_COUNT                           32u

/** eMIOS - Register Layout Typedef */
typedef union { /* Module Configuration (Base+0x0000) */
  vuint32_t R;
  struct {
    vuint32_t :1;
    vuint32_t MDIS:1;
    vuint32_t FRZ:1;
    vuint32_t GTBE:1;
    vuint32_t ETB:1;
    vuint32_t GPREN:1;
    vuint32_t :6;
    vuint32_t SRV:4;
    vuint32_t GPRE:8;
    vuint32_t :8;
  } B;
} eMIOS_MCR_tag;

typedef union { /* Global Flag (Base+0x0004) */
  vuint32_t R;
  struct {
    vuint32_t :8;
    vuint32_t F23:1;
    vuint32_t F22:1;
    vuint32_t F21:1;
    vuint32_t F20:1;
    vuint32_t F19:1;
    vuint32_t F18:1;
    vuint32_t F17:1;
    vuint32_t F16:1;
    vuint32_t :8;
    vuint32_t F7:1;
    vuint32_t F6:1;
    vuint32_t F5:1;
    vuint32_t F4:1;
    vuint32_t F3:1;
    vuint32_t F2:1;
    vuint32_t F1:1;
    vuint32_t F0:1;
  } B;
} eMIOS_GFLAG_tag;

typedef union { /* Output Update Disable (Base+0x0008) */
  vuint32_t R;
  struct {
    vuint32_t :8;
    vuint32_t OU23:1;
    vuint32_t OU22:1;
    vuint32_t OU21:1;
    vuint32_t OU20:1;
    vuint32_t OU19:1;
    vuint32_t OU18:1;
    vuint32_t OU17:1;
    vuint32_t OU16:1;
    vuint32_t :8;
    vuint32_t OU7:1;
    vuint32_t OU6:1;
    vuint32_t OU5:1;
    vuint32_t OU4:1;
    vuint32_t OU3:1;
    vuint32_t OU2:1;
    vuint32_t OU1:1;
    vuint32_t OU0:1;
  } B;
} eMIOS_OUDIS_tag;

typedef union { /* Channel A Data (UCn Base+0x0000) */
  vuint32_t R;
  struct {
    vuint32_t :8;
    vuint32_t A:24;
  } B;
} eMIOS_UC_An_tag;

typedef union { /* Channel B Data (UCn Base+0x0004) */
  vuint32_t R;
  struct {
    vuint32_t :8;
    vuint32_t B:24;
  } B;
} eMIOS_UC_Bn_tag;

typedef union { /* Channel Counter (UCn Base+0x0008) */
  vuint32_t R;
  struct {
    vuint32_t :8;
    vuint32_t C:24;
  } B;
} eMIOS_UC_CNTn_tag;

typedef union { /* Channel Control (UCn Base+0x000C) */
  vuint32_t R;
  struct {
    vuint32_t FREN:1;
    vuint32_t ODIS:1;
    vuint32_t ODISSL:2;
    vuint32_t UCPRE:2;
    vuint32_t UCPREN:1;
    vuint32_t DMA:1;
    vuint32_t :1;
    vuint32_t IF:4;
    vuint32_t FCK:1;
    vuint32_t FEN:1;
    vuint32_t :3;
    vuint32_t FORCMA:1;
    vuint32_t FORCMB:1;
    vuint32_t :1;
    vuint32_t BSL:2;
    vuint32_t EDSEL:1;
    vuint32_t EDPOL:1;
    vuint32_t MODE:7;
  } B;
} eMIOS_UC_Cn_tag;

typedef union { /* Channel Status (UCn Base+0x0010) */
  vuint32_t R;
  struct {
    vuint32_t OVR:1;
    vuint32_t :15;
    vuint32_t OVFL:1;
    vuint32_t :12;
    vuint32_t UCIN:1;
    vuint32_t UCOUT:1;
    vuint32_t FLAG:1;
  } B;
} eMIOS_UC_Sn_tag;

typedef union { /* Alternate Channel A Data (UCn Base+0x0014) */
  vuint32_t R;
  struct {
    vuint32_t :8;
    vuint32_t ALTA:24;
  } B;
} eMIOS_UC_ALTAn_tag;

struct eMIOS_tag {
  eMIOS_MCR_tag MCR;                               /**< eMIOS Module Configuration Register, offset: 0x0 */
  eMIOS_GFLAG_tag GFLAG;                           /**< eMIOS Global FLAG Register, offset: 0x4 */
  eMIOS_OUDIS_tag OUDIS;                           /**< eMIOS Output Update Disable register, offset: 0x8 */
  vuint32_t RESERVED_0;
  uint8_t RESERVED_1[16];
  struct {                                         /* offset: 0x20, array step: 0x20 */
    eMIOS_UC_An_tag A;                             /**< eMIOS UC A register n, array offset: 0x20, array step: 0x20 */
    eMIOS_UC_Bn_tag B;                             /**< eMIOS UC B register n, array offset: 0x24, array step: 0x20 */
    eMIOS_UC_CNTn_tag CNT;                         /**< eMIOS CNT register n, array offset: 0x28, array step: 0x20 */
    eMIOS_UC_Cn_tag C;                             /**< eMIOS UC Control register n, array offset: 0x2C, array step: 0x20 */
    eMIOS_UC_Sn_tag S;                             /**< eMIOS UC Status register n, array offset: 0x30, array step: 0x20 */
    eMIOS_UC_ALTAn_tag ALTA;                       /**< eMIOS Alternate Address register n, array offset: 0x34, array step: 0x20 */
    uint8_t RESERVED_2[8];
  } UC[eMIOS_UC_COUNT];
}; /* end of eMIOS_tag */


/* ----------------------------------------------------------------------------
   -- eMIOS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup eMIOS_Register_Masks eMIOS Register Masks
 * @{
 */

/* MCR Bit Fields */
#define eMIOS_MCR_GPRE_MASK                      0xFF00u
#define eMIOS_MCR_GPRE_SHIFT                     8u
#define eMIOS_MCR_GPRE_WIDTH                     8u
#define eMIOS_MCR_GPRE(x)                        (((uint32_t)(((uint32_t)(x))<<eMIOS_MCR_GPRE_SHIFT))&eMIOS_MCR_GPRE_MASK)
#define eMIOS_MCR_SRV_MASK                       0xF0000u
#define eMIOS_MCR_SRV_SHIFT                      16u
#define eMIOS_MCR_SRV_WIDTH                      4u
#define eMIOS_MCR_SRV(x)                         (((uint32_t)(((uint32_t)(x))<<eMIOS_MCR_SRV_SHIFT))&eMIOS_MCR_SRV_MASK)
#define eMIOS_MCR_GPREN_MASK                     0x4000000u
#define eMIOS_MCR_GPREN_SHIFT                    26u
#define eMIOS_MCR_GPREN_WIDTH                    1u
#define eMIOS_MCR_GPREN(x)                       (((uint32_t)(((uint32_t)(x))<<eMIOS_MCR_GPREN_SHIFT))&eMIOS_MCR_GPREN_MASK)
#define eMIOS_MCR_ETB_MASK                       0x8000000u
#define eMIOS_MCR_ETB_SHIFT                      27u
#define eMIOS_MCR_ETB_WIDTH                      1u
#define eMIOS_MCR_ETB(x)                         (((uint32_t)(((uint32_t)(x))<<eMIOS_MCR_ETB_SHIFT))&eMIOS_MCR_ETB_MASK)
#define eMIOS_MCR_GTBE_MASK                      0x10000000u
#define eMIOS_MCR_GTBE_SHIFT                     28u
#define eMIOS_MCR_GTBE_WIDTH                     1u
#define eMIOS_MCR_GTBE(x)                        (((uint32_t)(((uint32_t)(x))<<eMIOS_MCR_GTBE_SHIFT))&eMIOS_MCR_GTBE_MASK)
#define eMIOS_MCR_FRZ_MASK                       0x20000000u
#define eMIOS_MCR_FRZ_SHIFT                      29u
#define eMIOS_MCR_FRZ_WIDTH                      1u
#define eMIOS_MCR_FRZ(x)                         (((uint32_t)(((uint32_t)(x))<<eMIOS_MCR_FRZ_SHIFT))&eMIOS_MCR_FRZ_MASK)
#define eMIOS_MCR_MDIS_MASK                      0x40000000u
#define eMIOS_MCR_MDIS_SHIFT                     30u
#define eMIOS_MCR_MDIS_WIDTH                     1u
#define eMIOS_MCR_MDIS(x)                        (((uint32_t)(((uint32_t)(x))<<eMIOS_MCR_MDIS_SHIFT))&eMIOS_MCR_MDIS_MASK)
/* GFLAG Bit Fields */
#define eMIOS_GFLAG_F7_F0_MASK                   0xFFu
#define eMIOS_GFLAG_F7_F0_SHIFT                  0u
#define eMIOS_GFLAG_F7_F0_WIDTH                  8u
#define eMIOS_GFLAG_F7_F0(x)                     (((uint32_t)(((uint32_t)(x))<<eMIOS_GFLAG_F7_F0_SHIFT))&eMIOS_GFLAG_F7_F0_MASK)
#define eMIOS_GFLAG_F23_F16_MASK                 0xFF0000u
#define eMIOS_GFLAG_F23_F16_SHIFT                16u
#define eMIOS_GFLAG_F23_F16_WIDTH                8u
#define eMIOS_GFLAG_F23_F16(x)                   (((uint32_t)(((uint32_t)(x))<<eMIOS_GFLAG_F23_F16_SHIFT))&eMIOS_GFLAG_F23_F16_MASK)
/* OUDIS Bit Fields */
#define eMIOS_OUDIS_OU7_OU0_MASK                 0xFFu
#define eMIOS_OUDIS_OU7_OU0_SHIFT                0u
#define eMIOS_OUDIS_OU7_OU0_WIDTH                8u
#define eMIOS_OUDIS_OU7_OU0(x)                   (((uint32_t)(((uint32_t)(x))<<eMIOS_OUDIS_OU7_OU0_SHIFT))&eMIOS_OUDIS_OU7_OU0_MASK)
#define eMIOS_OUDIS_OU23_OU16_MASK               0xFF0000u
#define eMIOS_OUDIS_OU23_OU16_SHIFT              16u
#define eMIOS_OUDIS_OU23_OU16_WIDTH              8u
#define eMIOS_OUDIS_OU23_OU16(x)                 (((uint32_t)(((uint32_t)(x))<<eMIOS_OUDIS_OU23_OU16_SHIFT))&eMIOS_OUDIS_OU23_OU16_MASK)
/* A Bit Fields */
#define eMIOS_A_A_MASK                           0xFFFFFFu
#define eMIOS_A_A_SHIFT                          0u
#define eMIOS_A_A_WIDTH                          24u
#define eMIOS_A_A(x)                             (((uint32_t)(((uint32_t)(x))<<eMIOS_A_A_SHIFT))&eMIOS_A_A_MASK)
/* B Bit Fields */
#define eMIOS_B_B_MASK                           0xFFFFFFu
#define eMIOS_B_B_SHIFT                          0u
#define eMIOS_B_B_WIDTH                          24u
#define eMIOS_B_B(x)                             (((uint32_t)(((uint32_t)(x))<<eMIOS_B_B_SHIFT))&eMIOS_B_B_MASK)
/* CNT Bit Fields */
#define eMIOS_CNT_C_MASK                         0xFFFFFFu
#define eMIOS_CNT_C_SHIFT                        0u
#define eMIOS_CNT_C_WIDTH                        24u
#define eMIOS_CNT_C(x)                           (((uint32_t)(((uint32_t)(x))<<eMIOS_CNT_C_SHIFT))&eMIOS_CNT_C_MASK)
/* C Bit Fields */
#define eMIOS_C_MODE_MASK                        0x7Fu
#define eMIOS_C_MODE_SHIFT                       0u
#define eMIOS_C_MODE_WIDTH                       7u
#define eMIOS_C_MODE(x)                          (((uint32_t)(((uint32_t)(x))<<eMIOS_C_MODE_SHIFT))&eMIOS_C_MODE_MASK)
#define eMIOS_C_EDPOL_MASK                       0x80u
#define eMIOS_C_EDPOL_SHIFT                      7u
#define eMIOS_C_EDPOL_WIDTH                      1u
#define eMIOS_C_EDPOL(x)                         (((uint32_t)(((uint32_t)(x))<<eMIOS_C_EDPOL_SHIFT))&eMIOS_C_EDPOL_MASK)
#define eMIOS_C_EDSEL_MASK                       0x100u
#define eMIOS_C_EDSEL_SHIFT                      8u
#define eMIOS_C_EDSEL_WIDTH                      1u
#define eMIOS_C_EDSEL(x)                         (((uint32_t)(((uint32_t)(x))<<eMIOS_C_EDSEL_SHIFT))&eMIOS_C_EDSEL_MASK)
#define eMIOS_C_BSL_MASK                         0x600u
#define eMIOS_C_BSL_SHIFT                        9u
#define eMIOS_C_BSL_WIDTH                        2u
#define eMIOS_C_BSL(x)                           (((uint32_t)(((uint32_t)(x))<<eMIOS_C_BSL_SHIFT))&eMIOS_C_BSL_MASK)
#define eMIOS_C_FORCMB_MASK                      0x1000u
#define eMIOS_C_FORCMB_SHIFT                     12u
#define eMIOS_C_FORCMB_WIDTH                     1u
#define eMIOS_C_FORCMB(x)                        (((uint32_t)(((uint32_t)(x))<<eMIOS_C_FORCMB_SHIFT))&eMIOS_C_FORCMB_MASK)
#define eMIOS_C_FORCMA_MASK                      0x2000u
#define eMIOS_C_FORCMA_SHIFT                     13u
#define eMIOS_C_FORCMA_WIDTH                     1u
#define eMIOS_C_FORCMA(x)                        (((uint32_t)(((uint32_t)(x))<<eMIOS_C_FORCMA_SHIFT))&eMIOS_C_FORCMA_MASK)
#define eMIOS_C_FEN_MASK                         0x20000u
#define eMIOS_C_FEN_SHIFT                        17u
#define eMIOS_C_FEN_WIDTH                        1u
#define eMIOS_C_FEN(x)                           (((uint32_t)(((uint32_t)(x))<<eMIOS_C_FEN_SHIFT))&eMIOS_C_FEN_MASK)
#define eMIOS_C_FCK_MASK                         0x40000u
#define eMIOS_C_FCK_SHIFT                        18u
#define eMIOS_C_FCK_WIDTH                        1u
#define eMIOS_C_FCK(x)                           (((uint32_t)(((uint32_t)(x))<<eMIOS_C_FCK_SHIFT))&eMIOS_C_FCK_MASK)
#define eMIOS_C_IF_MASK                          0x780000u
#define eMIOS_C_IF_SHIFT                         19u
#define eMIOS_C_IF_WIDTH                         4u
#define eMIOS_C_IF(x)                            (((uint32_t)(((uint32_t)(x))<<eMIOS_C_IF_SHIFT))&eMIOS_C_IF_MASK)
#define eMIOS_C_DMA_MASK                         0x1000000u
#define eMIOS_C_DMA_SHIFT                        24u
#define eMIOS_C_DMA_WIDTH                        1u
#define eMIOS_C_DMA(x)                           (((uint32_t)(((uint32_t)(x))<<eMIOS_C_DMA_SHIFT))&eMIOS_C_DMA_MASK)
#define eMIOS_C_UCPREN_MASK                      0x2000000u
#define eMIOS_C_UCPREN_SHIFT                     25u
#define eMIOS_C_UCPREN_WIDTH                     1u
#define eMIOS_C_UCPREN(x)                        (((uint32_t)(((uint32_t)(x))<<eMIOS_C_UCPREN_SHIFT))&eMIOS_C_UCPREN_MASK)
#define eMIOS_C_UCPRE_MASK                       0xC000000u
#define eMIOS_C_UCPRE_SHIFT                      26u
#define eMIOS_C_UCPRE_WIDTH                      2u
#define eMIOS_C_UCPRE(x)                         (((uint32_t)(((uint32_t)(x))<<eMIOS_C_UCPRE_SHIFT))&eMIOS_C_UCPRE_MASK)
#define eMIOS_C_ODISSL_MASK                      0x30000000u
#define eMIOS_C_ODISSL_SHIFT                     28u
#define eMIOS_C_ODISSL_WIDTH                     2u
#define eMIOS_C_ODISSL(x)                        (((uint32_t)(((uint32_t)(x))<<eMIOS_C_ODISSL_SHIFT))&eMIOS_C_ODISSL_MASK)
#define eMIOS_C_ODIS_MASK                        0x40000000u
#define eMIOS_C_ODIS_SHIFT                       30u
#define eMIOS_C_ODIS_WIDTH                       1u
#define eMIOS_C_ODIS(x)                          (((uint32_t)(((uint32_t)(x))<<eMIOS_C_ODIS_SHIFT))&eMIOS_C_ODIS_MASK)
#define eMIOS_C_FREN_MASK                        0x80000000u
#define eMIOS_C_FREN_SHIFT                       31u
#define eMIOS_C_FREN_WIDTH                       1u
#define eMIOS_C_FREN(x)                          (((uint32_t)(((uint32_t)(x))<<eMIOS_C_FREN_SHIFT))&eMIOS_C_FREN_MASK)
/* S Bit Fields */
#define eMIOS_S_FLAG_MASK                        0x1u
#define eMIOS_S_FLAG_SHIFT                       0u
#define eMIOS_S_FLAG_WIDTH                       1u
#define eMIOS_S_FLAG(x)                          (((uint32_t)(((uint32_t)(x))<<eMIOS_S_FLAG_SHIFT))&eMIOS_S_FLAG_MASK)
#define eMIOS_S_UCOUT_MASK                       0x2u
#define eMIOS_S_UCOUT_SHIFT                      1u
#define eMIOS_S_UCOUT_WIDTH                      1u
#define eMIOS_S_UCOUT(x)                         (((uint32_t)(((uint32_t)(x))<<eMIOS_S_UCOUT_SHIFT))&eMIOS_S_UCOUT_MASK)
#define eMIOS_S_UCIN_MASK                        0x4u
#define eMIOS_S_UCIN_SHIFT                       2u
#define eMIOS_S_UCIN_WIDTH                       1u
#define eMIOS_S_UCIN(x)                          (((uint32_t)(((uint32_t)(x))<<eMIOS_S_UCIN_SHIFT))&eMIOS_S_UCIN_MASK)
#define eMIOS_S_OVFL_MASK                        0x8000u
#define eMIOS_S_OVFL_SHIFT                       15u
#define eMIOS_S_OVFL_WIDTH                       1u
#define eMIOS_S_OVFL(x)                          (((uint32_t)(((uint32_t)(x))<<eMIOS_S_OVFL_SHIFT))&eMIOS_S_OVFL_MASK)
#define eMIOS_S_OVR_MASK                         0x80000000u
#define eMIOS_S_OVR_SHIFT                        31u
#define eMIOS_S_OVR_WIDTH                        1u
#define eMIOS_S_OVR(x)                           (((uint32_t)(((uint32_t)(x))<<eMIOS_S_OVR_SHIFT))&eMIOS_S_OVR_MASK)
/* ALTA Bit Fields */
#define eMIOS_ALTA_ALTA_MASK                     0xFFFFFFu
#define eMIOS_ALTA_ALTA_SHIFT                    0u
#define eMIOS_ALTA_ALTA_WIDTH                    24u
#define eMIOS_ALTA_ALTA(x)                       (((uint32_t)(((uint32_t)(x))<<eMIOS_ALTA_ALTA_SHIFT))&eMIOS_ALTA_ALTA_MASK)

#endif
