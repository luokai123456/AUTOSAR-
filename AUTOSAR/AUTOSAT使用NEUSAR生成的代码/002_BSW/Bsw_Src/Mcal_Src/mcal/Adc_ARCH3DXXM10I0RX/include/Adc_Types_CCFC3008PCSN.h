#ifndef ADC_TYPES_CCFC3008PCSN_H_
#define ADC_TYPES_CCFC3008PCSN_H_
#if defined(CCFC3008PCSN)

/*******************************************************************************
 * @brief EQADC Command FIFO Trigger Source.
 *******************************************************************************/
#define EQADC_HW_TRIG_NOT_CONNECTED         (0U)
/* PIT */
#define EQADC_HW_TRIG_RTI                   (1U)
#define EQADC_HW_TRIG_PIT0_CH0              (2U)
#define EQADC_HW_TRIG_PIT0_CH1              (3U)
#define EQADC_HW_TRIG_PIT1_CH0              (4U)
#define EQADC_HW_TRIG_PIT1_CH1              (5U)
/* EMIOS */
#define EQADC_HW_TRIG_EMIOS0_CH16           (24U)
#define EQADC_HW_TRIG_EMIOS0_CH17           (25U)
#define EQADC_HW_TRIG_EMIOS0_CH18           (26U)
#define EQADC_HW_TRIG_EMIOS0_CH19           (27U)
#define EQADC_HW_TRIG_EMIOS0_CH20           (28U)
#define EQADC_HW_TRIG_EMIOS0_CH21           (29U)
#define EQADC_HW_TRIG_EMIOS0_CH22           (30U)
#define EQADC_HW_TRIG_EMIOS0_CH23           (31U)
#define EQADC_HW_TRIG_CFIFO0_EMIOS1_CH2     (64U)   /* eMOIS trigger CFIFO_0 only */
#define EQADC_HW_TRIG_CFIFO1_EMIOS1_CH3     (64U)   /* eMOIS trigger CFIFO_1 only */
#define EQADC_HW_TRIG_CFIFO5_EMIOS1_CH4     (64U)   /* eMOIS trigger CFIFO_5 only */
#define EQADC_HW_TRIG_CFIFO4_EMIOS1_CH5     (64U)   /* eMOIS trigger CFIFO_4 only */
#define EQADC_HW_TRIG_CFIFO3_EMIOS1_CH6     (64U)   /* eMOIS trigger CFIFO_3 only */
#define EQADC_HW_TRIG_CFIFO2_EMIOS1_CH7     (64U)   /* eMOIS trigger CFIFO_2 only */
#define EQADC_HW_TRIG_CFIFO6_EMIOS1_CH1     (64U)   /* eMOIS trigger CFIFO_6 only */
#define EQADC_HW_TRIG_CFIFO7_EMIOS1_CH0     (64U)   /* eMOIS trigger CFIFO_7 only */
/* GTM */
#define EQADC_HW_TRIG_GTM_ATOM1_0           (12U)
#define EQADC_HW_TRIG_GTM_ATOM0_0           (13U)
#define EQADC_HW_TRIG_GTM_ATOM0_1           (14U)
#define EQADC_HW_TRIG_GTM_ATOM0_2           (15U)
#define EQADC_HW_TRIG_GTM_ATOM1_1           (16U)
#define EQADC_HW_TRIG_GTM_ATOM1_2           (17U)
#define EQADC_HW_TRIG_GTM_TOM0_0            (18U)
#define EQADC_HW_TRIG_GTM_TOM0_1            (19U)
#define EQADC_HW_TRIG_GTM_TOM0_2            (20U)
#define EQADC_HW_TRIG_GTM_TOM1_0            (21U)
#define EQADC_HW_TRIG_GTM_TOM1_1            (22U)
#define EQADC_HW_TRIG_GTM_TOM1_2            (23U)
#define EQADC_HW_TRIG_CFIFO1_GTM_ATOM1_7    (6U)    /* CFIFO_1 only */
#define EQADC_HW_TRIG_CFIFO2_GTM_TOM1_7     (6U)    /* CFIFO_2 only */
#define EQADC_HW_TRIG_CFIFO3_GTM_TOM1_14    (6U)    /* CFIFO_3 only */
#define EQADC_HW_TRIG_CFIFO4_GTM_ATOM0_7    (32U)   /* CFIFO_4 only */
#define EQADC_HW_TRIG_CFIFO5_GTM_TOM0_7     (32U)   /* CFIFO_5 only */
#define EQADC_HW_TRIG_CFIFO7_GTM_TOM1_7     (6U)    /* CFIFO_7 only */
/* GTM - RESOURCE_SUPPORT_GTM_TO_EQADC:
 *  TRIGx[y], x = TrigRegIdx, y = TrigRegMemberIdx */
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER0     (66U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER1     (67U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER2     (68U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER3     (69U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER4     (70U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER5     (71U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER6     (72U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER7     (73U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER8     (74U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER9     (75U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER10    (76U)
#define EQADC_HW_TRIG_GTM_TRIG0_MEMBER11    (77U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER0     (78U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER1     (79U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER2     (80U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER3     (81U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER4     (82U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER5     (83U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER6     (84U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER7     (85U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER8     (86U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER9     (87U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER10    (88U)
#define EQADC_HW_TRIG_GTM_TRIG1_MEMBER11    (89U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER0     (90U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER1     (91U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER2     (92U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER3     (93U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER4     (94U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER5     (95U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER6     (96U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER7     (97U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER8     (98U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER9     (99U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER10    (100U)
#define EQADC_HW_TRIG_GTM_TRIG2_MEMBER11    (101U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER0     (102U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER1     (103U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER2     (104U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER3     (105U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER4     (106U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER5     (107U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER6     (108U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER7     (109U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER8     (110U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER9     (111U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER10    (112U)
#define EQADC_HW_TRIG_GTM_TRIG3_MEMBER11    (113U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER0     (114U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER1     (115U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER2     (116U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER3     (117U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER4     (118U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER5     (119U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER6     (120U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER7     (121U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER8     (122U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER9     (123U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER10    (124U)
#define EQADC_HW_TRIG_GTM_TRIG4_MEMBER11    (125U)
/* CCU7 */
#define EQADC_HW_TRIG_CCU7_CC70             (32U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_1_CC70           (33U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_COUT73           (34U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_1_COUT73         (35U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_CC71             (36U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_1_CC71           (37U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_SR_1             (38U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_1_SR_1           (39U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_SR_3             (40U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_1_SR_3           (41U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_CC72             (42U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
#define EQADC_HW_TRIG_CCU7_1_CC72           (43U)   /* CFIFO_0 ~ CFIFO_3, CFIFO_6 ~ CFIFO_7 only */
/* ETRIG/GPIO Trigger */
#define EQADC_HW_TRIG_CFIFO0_ETRIG0         (65U)
#define EQADC_HW_TRIG_CFIFO1_ETRIG0         (7U)
#define EQADC_HW_TRIG_CFIFO2_ETRIG0         (65U)
#define EQADC_HW_TRIG_CFIFO3_ETRIG0         (7U)
#define EQADC_HW_TRIG_CFIFO4_ETRIG0         (65U)
#define EQADC_HW_TRIG_CFIFO5_ETRIG0         (7U)
#define EQADC_HW_TRIG_CFIFO6_ETRIG0         (65U)
#define EQADC_HW_TRIG_CFIFO7_ETRIG0         (65U)
#define EQADC_HW_TRIG_CFIFO0_ETRIG1         (7U)
#define EQADC_HW_TRIG_CFIFO1_ETRIG1         (65U)
#define EQADC_HW_TRIG_CFIFO2_ETRIG1         (7U)
#define EQADC_HW_TRIG_CFIFO3_ETRIG1         (65U)
#define EQADC_HW_TRIG_CFIFO4_ETRIG1         (7U)
#define EQADC_HW_TRIG_CFIFO5_ETRIG1         (65U)
#define EQADC_HW_TRIG_CFIFO6_ETRIG1         (7U)
#define EQADC_HW_TRIG_CFIFO7_ETRIG1         (7U)

/*******************************************************************************
 * @brief EQADC CFIFO0 Advance Trigger Source.
 *******************************************************************************/
#define EQADC_ATRIG_NOT_CONNECTED           (0U)
#define EQADC_ATRIG_RTI                     (1U)
#define EQADC_ATRIG_PIT0_CH0                (2U)
#define EQADC_ATRIG_PIT0_CH1                (3U)
#define EQADC_ATRIG_PIT1_CH0                (4U)
#define EQADC_ATRIG_PIT1_CH1                (5U)
#define EQADC_ATRIG_GTM_ATOM0_1_PIT0_CH0    (8U)
#define EQADC_ATRIG_GTM_ATOM0_1_PIT0_CH1    (9U)
#define EQADC_ATRIG_GTM_ATOM1_0             (12U)
#define EQADC_ATRIG_GTM_ATOM0_0             (13U)
#define EQADC_ATRIG_GTM_ATOM0_1             (14U)
#define EQADC_ATRIG_GTM_ATOM0_2             (15U)
#define EQADC_ATRIG_GTM_TOM0_2              (16U)
#define EQADC_ATRIG_GTM_TOM1_0              (17U)
#define EQADC_ATRIG_GTM_TOM1_1              (18U)
#define EQADC_ATRIG_GTM_TOM1_2              (19U)
#define EQADC_ATRIG_EMIOS1_CH2_PIT1_CH0     (20U)
#define EQADC_ATRIG_EMIOS1_CH2_PIT1_CH1     (21U)
#define EQADC_ATRIG_EMIOS0_CH23             (31U)

/*******************************************************************************
 * @brief EQADC Channel.
 *******************************************************************************/
/* Single ended Channel */
#define EQADC_CH0                   (0U)    /* Channel 0:   Single ended conversion */
#define EQADC_CH1                   (1U)    /* Channel 1:   Single ended conversion */
#define EQADC_CH2                   (2U)    /* Channel 2:   Single ended conversion */
#define EQADC_CH3                   (3U)    /* Channel 3:   Single ended conversion */
#define EQADC_CH4                   (4U)    /* Channel 4:   Single ended conversion */
#define EQADC_CH5                   (5U)    /* Channel 5:   Single ended conversion */
#define EQADC_CH6                   (6U)    /* Channel 6:   Single ended conversion */
#define EQADC_CH7                   (7U)    /* Channel 7:   Single ended conversion */
#define EQADC_CH8                   (8U)    /* Channel 8:   Single ended conversion */
#define EQADC_CH9                   (9U)    /* Channel 9:   Single ended conversion */
#define EQADC_CH10                  (10U)   /* Channel 10:  Single ended conversion */
#define EQADC_CH11                  (11U)   /* Channel 11:  Single ended conversion */
#define EQADC_CH12                  (12U)   /* Channel 12:  Single ended conversion */
#define EQADC_CH13                  (13U)   /* Channel 13:  Single ended conversion */
#define EQADC_CH14                  (14U)   /* Channel 14:  Single ended conversion */
#define EQADC_CH15                  (15U)   /* Channel 15:  Single ended conversion */
#define EQADC_CH16                  (16U)   /* Channel 16:  Single ended conversion */
#define EQADC_CH17                  (17U)   /* Channel 17:  Single ended conversion */
#define EQADC_CH18                  (18U)   /* Channel 18:  Single ended conversion */
#define EQADC_CH19                  (19U)   /* Channel 19:  Single ended conversion */
#define EQADC_CH20                  (20U)   /* Channel 20:  Single ended conversion */
#define EQADC_CH21                  (21U)   /* Channel 21:  Single ended conversion */
#define EQADC_CH22                  (22U)   /* Channel 22:  Single ended conversion */
#define EQADC_CH23                  (23U)   /* Channel 23:  Single ended conversion */
#define EQADC_CH24                  (24U)   /* Channel 24:  Single ended conversion */
#define EQADC_CH25                  (25U)   /* Channel 25:  Single ended conversion */
#define EQADC_CH26                  (26U)   /* Channel 26:  Single ended conversion */
#define EQADC_CH27                  (27U)   /* Channel 27:  Single ended conversion */
#define EQADC_CH28                  (28U)   /* Channel 28:  Single ended conversion */
#define EQADC_CH29                  (29U)   /* Channel 29:  Single ended conversion */
#define EQADC_CH30                  (30U)   /* Channel 30:  Single ended conversion */
#define EQADC_CH31                  (31U)   /* Channel 31:  Single ended conversion */
#define EQADC_CH32                  (32U)   /* Channel 32:  Single ended conversion */
#define EQADC_CH33                  (33U)   /* Channel 33:  Single ended conversion */
#define EQADC_CH34                  (34U)   /* Channel 34:  Single ended conversion */
#define EQADC_CH35                  (35U)   /* Channel 35:  Single ended conversion */
#define EQADC_CH36                  (36U)   /* Channel 36:  Single ended conversion */
#define EQADC_CH37                  (37U)   /* Channel 37:  Single ended conversion */
#define EQADC_CH38                  (38U)   /* Channel 38:  Single ended conversion */
#define EQADC_CH39                  (39U)   /* Channel 39:  Single ended conversion */
#define EQADC_CH40                  (40U)   /* Channel 40:  Single ended conversion */
#define EQADC_CH41                  (41U)   /* Channel 41:  Single ended conversion */
#define EQADC_CH42                  (42U)   /* Channel 42:  Single ended conversion */
#define EQADC_CH43                  (43U)   /* Channel 43:  Single ended conversion */
#define EQADC_CH44                  (44U)   /* Channel 44:  Single ended conversion */
#define EQADC_CH45                  (45U)   /* Channel 45:  Single ended conversion */
#define EQADC_CH46                  (46U)   /* Channel 46:  Single ended conversion */
#define EQADC_CH47                  (47U)   /* Channel 47:  Single ended conversion */
#define EQADC_CH48                  (48U)   /* Channel 48:  Single ended conversion */
#define EQADC_CH49                  (49U)   /* Channel 49:  Single ended conversion */
#define EQADC_CH50                  (50U)   /* Channel 50:  Single ended conversion */
#define EQADC_CH51                  (51U)   /* Channel 51:  Single ended conversion */
#define EQADC_CH52                  (52U)   /* Channel 52:  Single ended conversion */
#define EQADC_CH53                  (53U)   /* Channel 53:  Single ended conversion */
#define EQADC_CH54                  (54U)   /* Channel 54:  Single ended conversion */
#define EQADC_CH55                  (55U)   /* Channel 55:  Single ended conversion */
#define EQADC_CH56                  (56U)   /* Channel 56:  Single ended conversion */
#define EQADC_CH57                  (57U)   /* Channel 57:  Single ended conversion */
#define EQADC_CH58                  (58U)   /* Channel 58:  Single ended conversion */
#define EQADC_CH59                  (59U)   /* Channel 59:  Single ended conversion */
#define EQADC_CH60                  (60U)   /* Channel 60:  Single ended conversion */
#define EQADC_CH61                  (61U)   /* Channel 61:  Single ended conversion */
#define EQADC_CH62                  (62U)   /* Channel 62:  Single ended conversion */
#define EQADC_CH63                  (63U)   /* Channel 63:  Single ended conversion */
#define EQADC_CH64                  (64U)   /* Channel 64:  Single ended conversion */
#define EQADC_CH65                  (65U)   /* Channel 65:  Single ended conversion */
#define EQADC_CH66                  (66U)   /* Channel 66:  Single ended conversion */
#define EQADC_CH67                  (67U)   /* Channel 67:  Single ended conversion */
#define EQADC_CH68                  (68U)   /* Channel 68:  Single ended conversion */
#define EQADC_CH69                  (69U)   /* Channel 69:  Single ended conversion */
#define EQADC_CH70                  (70U)   /* Channel 70:  Single ended conversion */
#define EQADC_CH71                  (71U)   /* Channel 71:  Single ended conversion */
#define EQADC_CH72                  (72U)   /* Channel 72:  Single ended conversion */
#define EQADC_CH73                  (73U)   /* Channel 73:  Single ended conversion */
#define EQADC_CH74                  (74U)   /* Channel 74:  Single ended conversion */
#define EQADC_CH75                  (75U)   /* Channel 75:  Single ended conversion */
#define EQADC_CH76                  (76U)   /* Channel 76:  Single ended conversion */
#define EQADC_CH77                  (77U)   /* Channel 77:  Single ended conversion */
#define EQADC_CH78                  (78U)   /* Channel 78:  Single ended conversion */
#define EQADC_CH79                  (79U)   /* Channel 79:  Single ended conversion */
#define EQADC_CH80                  (80U)   /* Channel 80:  Single ended conversion */
#define EQADC_CH81                  (81U)   /* Channel 81:  Single ended conversion */
#define EQADC_CH82                  (82U)   /* Channel 82:  Single ended conversion */
#define EQADC_CH83                  (83U)   /* Channel 83:  Single ended conversion */
#define EQADC_CH84                  (84U)   /* Channel 84:  Single ended conversion */
#define EQADC_CH85                  (85U)   /* Channel 85:  Single ended conversion */
#define EQADC_CH86                  (86U)   /* Channel 86:  Single ended conversion */
#define EQADC_CH87                  (87U)   /* Channel 87:  Single ended conversion */
#define EQADC_CH88                  (88U)   /* Channel 88:  Single ended conversion */
#define EQADC_CH89                  (89U)   /* Channel 89:  Single ended conversion */
#define EQADC_CH90                  (90U)   /* Channel 90:  Single ended conversion */
#define EQADC_CH91                  (91U)   /* Channel 91:  Single ended conversion */
#define EQADC_CH92                  (92U)   /* Channel 92:  Single ended conversion */
#define EQADC_CH93                  (93U)   /* Channel 93:  Single ended conversion */
#define EQADC_CH94                  (94U)   /* Channel 94:  Single ended conversion */
#define EQADC_CH95                  (95U)   /* Channel 95:  Single ended conversion */
#define EQADC_CH96                  (96U)   /* Channel 96:  Single ended conversion */
#define EQADC_CH97                  (97U)   /* Channel 97:  Single ended conversion */
#define EQADC_CH98                  (98U)   /* Channel 98:  Single ended conversion */
#define EQADC_CH99                  (99U)   /* Channel 99:  Single ended conversion */
#define EQADC_CH100                 (100U)  /* Channel 100: Single ended conversion */
#define EQADC_CH101                 (101U)  /* Channel 101: Single ended conversion */
#define EQADC_CH102                 (102U)  /* Channel 102: Single ended conversion */
#define EQADC_CH103                 (103U)  /* Channel 103: Single ended conversion */
#define EQADC_CH104                 (104U)  /* Channel 104: Single ended conversion */
#define EQADC_CH105                 (105U)  /* Channel 105: Single ended conversion */
#define EQADC_CH106                 (106U)  /* Channel 106: Single ended conversion */
#define EQADC_CH107                 (107U)  /* Channel 107: Single ended conversion */
#define EQADC_CH108                 (108U)  /* Channel 108: Single ended conversion */
#define EQADC_CH109                 (109U)  /* Channel 109: Single ended conversion */
#define EQADC_CH110                 (110U)  /* Channel 110: Single ended conversion */
#define EQADC_CH111                 (111U)  /* Channel 111: Single ended conversion */
#define EQADC_CH112                 (112U)  /* Channel 112: Single ended conversion */
#define EQADC_CH113                 (113U)  /* Channel 113: Single ended conversion */
#define EQADC_CH114                 (114U)  /* Channel 114: Single ended conversion */
#define EQADC_CH115                 (115U)  /* Channel 115: Single ended conversion */
#define EQADC_CH116                 (116U)  /* Channel 116: Single ended conversion */
#define EQADC_CH117                 (117U)  /* Channel 117: Single ended conversion */
#define EQADC_CH118                 (118U)  /* Channel 118: Single ended conversion */
#define EQADC_CH119                 (119U)  /* Channel 119: Single ended conversion */
#define EQADC_CH120                 (120U)  /* Channel 120: Single ended conversion */
#define EQADC_CH121                 (121U)  /* Channel 121: Single ended conversion */
#define EQADC_CH122                 (122U)  /* Channel 122: Single ended conversion */
#define EQADC_CH123                 (123U)  /* Channel 123: Single ended conversion */
#define EQADC_CH124                 (124U)  /* Channel 124: Single ended conversion */
#define EQADC_CH125                 (125U)  /* Channel 125: Single ended conversion */
#define EQADC_CH126                 (126U)  /* Channel 126: Single ended conversion */
#define EQADC_CH127                 (127U)  /* Channel 127: Single ended conversion */
#define EQADC_CH192                 (192U)  /* Channel 192: Single ended conversion */
#define EQADC_CH200                 (200U)  /* Channel 200: Single ended conversion */
#define EQADC_CH208                 (208U)  /* Channel 208: Single ended conversion */
#define EQADC_CH216                 (216U)  /* Channel 216: Single ended conversion */

/* Differential Channel */
#define EQADC_DAN_CH128             (128U)  /* Channel 128: Differential conversion */
#define EQADC_DAN_CH129             (129U)  /* Channel 129: Differential conversion */
#define EQADC_DAN_CH130             (130U)  /* Channel 130: Differential conversion */
#define EQADC_DAN_CH131             (131U)  /* Channel 131: Differential conversion */
#define EQADC_DAN_CH132             (132U)  /* Channel 132: Differential conversion */
#define EQADC_DAN_CH133             (133U)  /* Channel 133: Differential conversion */
#define EQADC_DAN_CH134             (134U)  /* Channel 134: Differential conversion */
#define EQADC_DAN_CH135             (135U)  /* Channel 135: Differential conversion */
#define EQADC_DAN_CH136             (136U)  /* Channel 136: Differential conversion */
#define EQADC_DAN_CH137             (137U)  /* Channel 137: Differential conversion */
#define EQADC_DAN_CH138             (138U)  /* Channel 138: Differential conversion */
#define EQADC_DAN_CH139             (139U)  /* Channel 139: Differential conversion */
#define EQADC_DAN_CH140             (140U)  /* Channel 140: Differential conversion */
#define EQADC_DAN_CH141             (141U)  /* Channel 141: Differential conversion */
#define EQADC_DAN_CH142             (142U)  /* Channel 142: Differential conversion */
#define EQADC_DAN_CH143             (143U)  /* Channel 143: Differential conversion */
#define EQADC_DAN_CH144             (144U)  /* Channel 144: Differential conversion */
#define EQADC_DAN_CH145             (145U)  /* Channel 145: Differential conversion */
#define EQADC_DAN_CH146             (146U)  /* Channel 146: Differential conversion */
#define EQADC_DAN_CH147             (147U)  /* Channel 147: Differential conversion */
#define EQADC_DAN_CH148             (148U)  /* Channel 148: Differential conversion */
#define EQADC_DAN_CH149             (149U)  /* Channel 149: Differential conversion */
#define EQADC_DAN_CH150             (150U)  /* Channel 150: Differential conversion */
#define EQADC_DAN_CH151             (151U)  /* Channel 151: Differential conversion */
#define EQADC_DAN_CH152             (152U)  /* Channel 152: Differential conversion */
#define EQADC_DAN_CH153             (153U)  /* Channel 153: Differential conversion */
#define EQADC_DAN_CH154             (154U)  /* Channel 154: Differential conversion */
#define EQADC_DAN_CH155             (155U)  /* Channel 155: Differential conversion */
#define EQADC_DAN_CH156             (156U)  /* Channel 156: Differential conversion */
#define EQADC_DAN_CH157             (157U)  /* Channel 157: Differential conversion */
#define EQADC_DAN_CH160             (160U)  /* Channel 160: Differential conversion */
#define EQADC_DAN_CH161             (161U)  /* Channel 161: Differential conversion */
#define EQADC_DAN_CH162             (162U)  /* Channel 162: Differential conversion */
#define EQADC_DAN_CH163             (163U)  /* Channel 163: Differential conversion */
#define EQADC_DAN_CH164             (164U)  /* Channel 164: Differential conversion */
#define EQADC_DAN_CH165             (165U)  /* Channel 165: Differential conversion */

/* Internal Channel
 *  (EQADC0_OnChipAdc1(ADC1) has.) */
#define EQADC_CH_VDD_HV_STBY        (15U)   /* Channel: VDD_HV_STBY (3.3V/5V)   */
#define EQADC_CH_VDD_HV_FLA         (31U)   /* Channel: VDD_HV_FLA  (3.3V)      */
#define EQADC_CH_VDD_HV_PMC         (47U)   /* Channel: VDD_HV_PMC  (3.3V/5V)   */
#define EQADC_CH_VDD_HV_IO_MAIN     (63U)   /* Channel: VDD_HV_IO_MAIN(3.3V/5V) */
#define EQADC_CH_VDD_LV             (79U)   /* Channel: VDD_LV      (1.2V)      */
#define EQADC_CH_TEMP_SENSOR        (7U)    /* Channel: Temperature Sensor      */
#define EQADC_CH_VDD_PCT75_VREF     (127U)  /* Channel: 75% VREF                */
#define EQADC_CH_VDD_PCT50_VREF     (111U)  /* Channel: 50% VREF                */
#define EQADC_CH_VDD_PCT25_VREF     (95U)   /* Channel: 25% VREF                */

/* External Multiplexing Channel */
#define EQADC_EXT0_CH0              (0U)
#define EQADC_EXT0_CH16             (16U)
#define EQADC_EXT0_CH32             (32U)
#define EQADC_EXT0_CH48             (48U)
#define EQADC_EXT0_CH64             (64U)
#define EQADC_EXT0_CH80             (80U)
#define EQADC_EXT0_CH96             (96U)
#define EQADC_EXT0_CH112            (112U)
#define EQADC_EXT1_CH1              (1U)
#define EQADC_EXT1_CH17             (17U)
#define EQADC_EXT1_CH33             (33U)
#define EQADC_EXT1_CH49             (49U)
#define EQADC_EXT1_CH65             (65U)
#define EQADC_EXT1_CH81             (81U)
#define EQADC_EXT1_CH97             (97U)
#define EQADC_EXT1_CH113            (113U)
#define EQADC_EXT2_CH2              (2U)
#define EQADC_EXT2_CH18             (18U)
#define EQADC_EXT2_CH34             (34U)
#define EQADC_EXT2_CH50             (50U)
#define EQADC_EXT2_CH66             (66U)
#define EQADC_EXT2_CH82             (82U)
#define EQADC_EXT2_CH98             (98U)
#define EQADC_EXT2_CH114            (114U)
#define EQADC_EXT3_CH3              (3U)
#define EQADC_EXT3_CH19             (19U)
#define EQADC_EXT3_CH35             (35U)
#define EQADC_EXT3_CH51             (51U)
#define EQADC_EXT3_CH67             (67U)
#define EQADC_EXT3_CH83             (83U)
#define EQADC_EXT3_CH99             (99U)
#define EQADC_EXT3_CH115            (115U)
#define EQADC_EXT4_CH4              (4U)
#define EQADC_EXT4_CH20             (20U)
#define EQADC_EXT4_CH36             (36U)
#define EQADC_EXT4_CH52             (52U)
#define EQADC_EXT4_CH68             (68U)
#define EQADC_EXT4_CH84             (84U)
#define EQADC_EXT4_CH100            (100U)
#define EQADC_EXT4_CH116            (116U)
#define EQADC_EXT5_CH5              (5U)
#define EQADC_EXT5_CH21             (21U)
#define EQADC_EXT5_CH37             (37U)
#define EQADC_EXT5_CH53             (53U)
#define EQADC_EXT5_CH69             (69U)
#define EQADC_EXT5_CH85             (85U)
#define EQADC_EXT5_CH101            (101U)
#define EQADC_EXT5_CH117            (117U)
#define EQADC_EXT6_CH6              (6U)
#define EQADC_EXT6_CH22             (22U)
#define EQADC_EXT6_CH38             (38U)
#define EQADC_EXT6_CH54             (54U)
#define EQADC_EXT6_CH70             (70U)
#define EQADC_EXT6_CH86             (86U)
#define EQADC_EXT6_CH102            (102U)
#define EQADC_EXT6_CH118            (118U)
#define EQADC_EXT7_CH7              (7U)
#define EQADC_EXT7_CH23             (23U)
#define EQADC_EXT7_CH39             (39U)
#define EQADC_EXT7_CH55             (55U)
#define EQADC_EXT7_CH71             (71U)
#define EQADC_EXT7_CH87             (87U)
#define EQADC_EXT7_CH103            (103U)
#define EQADC_EXT7_CH119            (119U)
#define EQADC_EXT8_CH8              (8U)
#define EQADC_EXT8_CH24             (24U)
#define EQADC_EXT8_CH40             (40U)
#define EQADC_EXT8_CH56             (56U)
#define EQADC_EXT8_CH72             (72U)
#define EQADC_EXT8_CH88             (88U)
#define EQADC_EXT8_CH104            (104U)
#define EQADC_EXT8_CH120            (120U)
#define EQADC_EXT9_CH9              (9U)
#define EQADC_EXT9_CH25             (25U)
#define EQADC_EXT9_CH41             (41U)
#define EQADC_EXT9_CH57             (57U)
#define EQADC_EXT9_CH73             (73U)
#define EQADC_EXT9_CH89             (89U)
#define EQADC_EXT9_CH105            (105U)
#define EQADC_EXT9_CH121            (121U)
#define EQADC_EXT10_CH10            (10U)
#define EQADC_EXT10_CH26            (26U)
#define EQADC_EXT10_CH42            (42U)
#define EQADC_EXT10_CH58            (58U)
#define EQADC_EXT10_CH74            (74U)
#define EQADC_EXT10_CH90            (90U)
#define EQADC_EXT10_CH106           (106U)
#define EQADC_EXT10_CH122           (122U)
#define EQADC_EXT11_CH11            (11U)
#define EQADC_EXT11_CH27            (27U)
#define EQADC_EXT11_CH43            (43U)
#define EQADC_EXT11_CH59            (59U)
#define EQADC_EXT11_CH75            (75U)
#define EQADC_EXT11_CH91            (91U)
#define EQADC_EXT11_CH107           (107U)
#define EQADC_EXT11_CH123           (123U)
#define EQADC_EXT12_CH12            (12U)
#define EQADC_EXT12_CH28            (28U)
#define EQADC_EXT12_CH44            (44U)
#define EQADC_EXT12_CH60            (60U)
#define EQADC_EXT12_CH76            (76U)
#define EQADC_EXT12_CH92            (92U)
#define EQADC_EXT12_CH108           (108U)
#define EQADC_EXT12_CH124           (124U)
#define EQADC_EXT13_CH13            (13U)
#define EQADC_EXT13_CH29            (29U)
#define EQADC_EXT13_CH45            (45U)
#define EQADC_EXT13_CH61            (61U)
#define EQADC_EXT13_CH77            (77U)
#define EQADC_EXT13_CH93            (93U)
#define EQADC_EXT13_CH109           (109U)
#define EQADC_EXT13_CH125           (125U)
#define EQADC_EXT14_CH14            (14U)
#define EQADC_EXT14_CH30            (30U)
#define EQADC_EXT14_CH46            (46U)
#define EQADC_EXT14_CH62            (62U)
#define EQADC_EXT14_CH78            (78U)
#define EQADC_EXT14_CH94            (94U)
#define EQADC_EXT14_CH110           (110U)
#define EQADC_EXT14_CH126           (126U)
#define EQADC_EXT15_CH15            (15U)
#define EQADC_EXT15_CH31            (31U)
#define EQADC_EXT15_CH47            (47U)
#define EQADC_EXT15_CH63            (63U)
#define EQADC_EXT15_CH79            (79U)
#define EQADC_EXT15_CH95            (95U)
#define EQADC_EXT15_CH111           (111U)
#define EQADC_EXT15_CH127           (127U)

#endif  /* CCFC3008PCSN */
#endif  /* ADC_TYPES_CCFC3008PCSN_H_ */
