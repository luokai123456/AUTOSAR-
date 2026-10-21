#ifndef CAN_SAMPLE_REG_H_
#define CAN_SAMPLE_REG_H_

/* ============================================================================
   =============================== Module: CAN_SAMPLE =========================
   ============================================================================ */

typedef union
{
    vuint32_t R;
    struct
    {
        vuint32_t Resered0: 			16;
        vuint32_t RX_COMPLETE:	    	1;		/* Read Only; CAN frame is stored in the sample registers or not             */
        vuint32_t BUSY:			    	1;		/* Read Only; This bit indicates the status of sampling                      */
        vuint32_t ACTIVE_CK:	    	1;		/* Read Only; This bit indicates which is current clock for sample registers */
        vuint32_t MODE:					1;		/* read / write; FF_MODE / SF_MODE                                           */
        vuint32_t CAN_RX_SEL:			6;		/* read / write; These bits determine which RX bit is sampled.               */
        vuint32_t BRP:					5;		/* read / write; Baudrate Prescaler                                          */
        vuint32_t CAN_SMPLR_EN:			1;		/* read / write; CAN SAMPLER Enable                                          */
    } B;
} CAN_Sampler_CR_tag;

typedef struct CAN_SAMPLER_tag
{
    CAN_Sampler_CR_tag CR;			/* CAN SAMPLER Control Register */
    vuint32_t SR[12];				/* CAN SAMPLER Sample Register 0 - 11 */
} CAN_Sampler_TypeDef;

/* CAN_SAMPLER_CR */
#define CAN_SAMPLER_CR_RX_COMPLETE_MASK         0x8000u
#define CAN_SAMPLER_CR_RX_COMPLETE_SHIFT        15u
#define CAN_SAMPLER_CR_RX_COMPLETE_WIDTH        1u
#define CAN_SAMPLER_CR_RX_COMPLETE(x)           (((uint32_t)(((uint32_t)(x))<<CAN_SAMPLER_CR_RX_COMPLETE_SHIFT))&CAN_SAMPLER_CR_RX_COMPLETE_MASK)
#define CAN_SAMPLER_CR_BUSY_MASK                0x4000u
#define CAN_SAMPLER_CR_BUSY_SHIFT               14u
#define CAN_SAMPLER_CR_BUSY_WIDTH               1u
#define CAN_SAMPLER_CR_BUSY(x)                  (((uint32_t)(((uint32_t)(x))<<CAN_SAMPLER_CR_BUSY_SHIFT))&CAN_SAMPLER_CR_BUSY_MASK)
#define CAN_SAMPLER_CR_ACTIVE_CK_MASK           0x2000u
#define CAN_SAMPLER_CR_ACTIVE_CK_SHIFT          13u
#define CAN_SAMPLER_CR_ACTIVE_CK_WIDTH          1u
#define CAN_SAMPLER_CR_ACTIVE_CK(x)             (((uint32_t)(((uint32_t)(x))<<CAN_SAMPLER_CR_ACTIVE_CK_SHIFT))&CAN_SAMPLER_CR_ACTIVE_CK_MASK)
#define CAN_SAMPLER_CR_MODE_MASK                0x800u
#define CAN_SAMPLER_CR_MODE_SHIFT               11u
#define CAN_SAMPLER_CR_MODE_WIDTH               1u
#define CAN_SAMPLER_CR_MODE(x)                  (((uint32_t)(((uint32_t)(x))<<CAN_SAMPLER_CR_MODE_SHIFT))&CAN_SAMPLER_CR_MODE_MASK)
#define CAN_SAMPLER_CR_RX_SEL_MASK              0xFC0u
#define CAN_SAMPLER_CR_RX_SEL_SHIFT             6u
#define CAN_SAMPLER_CR_RX_SEL_WIDTH             6u
#define CAN_SAMPLER_CR_RX_SEL(x)                (((uint32_t)(((uint32_t)(x))<<CAN_SAMPLER_CR_RX_SEL_SHIFT))&CAN_SAMPLER_CR_RX_SEL_MASK)
#define CAN_SAMPLER_CR_BRP_MASK                 0x3Eu
#define CAN_SAMPLER_CR_BRP_SHIFT                1u
#define CAN_SAMPLER_CR_BRP_WIDTH                5u
#define CAN_SAMPLER_CR_BRP(x)                   (((uint32_t)(((uint32_t)(x))<<CAN_SAMPLER_CR_BRP_SHIFT))&CAN_SAMPLER_CR_BRP_MASK)
#define CAN_SAMPLER_CR_EN_MASK                  0x1u
#define CAN_SAMPLER_CR_EN_SHIFT                 1u
#define CAN_SAMPLER_CR_EN_WIDTH                 1u
#define CAN_SAMPLER_CR_EN(x)                    (((uint32_t)(((uint32_t)(x))<<CAN_SAMPLER_CR_EN_SHIFT))&CAN_SAMPLER_CR_EN_MASK)

#endif  /* CAN_SAMPLE_REG_H_ */
