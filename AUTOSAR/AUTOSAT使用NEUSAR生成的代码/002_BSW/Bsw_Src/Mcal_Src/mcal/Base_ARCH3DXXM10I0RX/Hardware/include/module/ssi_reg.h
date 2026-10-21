#ifndef SSI_REG_H_
#define SSI_REG_H_

/* ============================================================================
   =============================== Module: SSI ================================
   ============================================================================ */

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t FRF:2	;
		vuint32_t :1;
		vuint32_t DFS:5;
		vuint32_t :1;
		vuint32_t SSTE:1;
		vuint32_t SSRL:1;
		vuint32_t :1;
		vuint32_t TMOD:2;
		vuint32_t SCPOL:1;
		vuint32_t SCPH:1;
		vuint32_t SPI_FRF:2;
		vuint32_t :2;
		vuint32_t CFS:4;
		vuint32_t:8;
	}B;

}SSI_CTRLR0_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t DNF_L:8;
		vuint32_t DNF_H:8;
		vuint32_t:16;
	}B;

}SSI_CTRLR1_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t SSIC_EN:1;
		vuint32_t:24;
	}B;

}SSI_SSI_ENR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t SCKDV_L:8;
		vuint32_t SCKDV_H:8;
		vuint32_t:16;
	}B;

}SSI_BAUDR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:3;
		vuint32_t TFT:5;
		vuint32_t:11;
		vuint32_t TXFTHR:5;
		vuint32_t:8;
	}B;

}SSI_TXFTLR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:3;
		vuint32_t RFT:5;
		vuint32_t:24;
	}B;

}SSI_RXFTLR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:2;
		vuint32_t TXFLR:6;
		vuint32_t:24;
	}B;

}SSI_TXFLR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:2;
		vuint32_t RXFLR:6;
		vuint32_t:24;
	}B;

}SSI_RXFLR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:3;
		vuint32_t RFF:1;
		vuint32_t RFNE:1;
		vuint32_t TFE:1;
		vuint32_t TFNF:1;
		vuint32_t BUSY:1;
		vuint32_t:24;
	}B;

}SSI_SR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:1;
		vuint32_t XRXOIM:1;
		vuint32_t:1;
		vuint32_t RXFIM:1;
		vuint32_t RXOIM:1;
		vuint32_t RXUIM:1;
		vuint32_t TXOIM:1;
		vuint32_t TXEIM:1;
		vuint32_t:24;
	}B;

}SSI_IMR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:1;
		vuint32_t XRXOIS:1;
		vuint32_t:1;
		vuint32_t RXFIS:1;
		vuint32_t RXOIS:1;
		vuint32_t RXUIS:1;
		vuint32_t TXOIS:1;
		vuint32_t TXEIS:1;
		vuint32_t:24;
	}B;

}SSI_ISR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:1;
		vuint32_t XRXOIR:1;
		vuint32_t:1;
		vuint32_t RXFIR:1;
		vuint32_t RXOIR:1;
		vuint32_t RXUIR:1;
		vuint32_t TXOIR:1;
		vuint32_t TXEIR:1;
		vuint32_t:24;
	}B;

}SSI_RISR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t TXOICR:1;
		vuint32_t:24;
	}B;

}SSI_TXOICR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t RXOICR:1;
		vuint32_t:24;
	}B;

}SSI_RXOICR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t RXUICR:1;
		vuint32_t:24;
	}B;

}SSI_RXUICR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:7;
		vuint32_t ICR:1;
		vuint32_t:24;
	}B;

}SSI_ICR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:6;
		vuint32_t TDMAE:1;
		vuint32_t RDMAE:1;
		vuint32_t:24;
	}B;

}SSI_DMACR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:5;
		vuint32_t DMATDL:3;
		vuint32_t:24;
	}B;

}SSI_DMATDL_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t:5;
		vuint32_t DMARDL:3;
		vuint32_t:24;
	}B;

}SSI_DMARDL_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t DR7_0:8;
		vuint32_t DR15_8:8;
		vuint32_t DR23_16:8;
		vuint32_t DR31_24:8;
	}B;

}SSI_DR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t RSD:8;
		vuint32_t :8;
		vuint32_t :7;
		vuint32_t SE:1;
		vuint32_t :8;
	}B;

}SSI_RXSDR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t :2;
		vuint32_t ADDR_L:4;
		vuint32_t TRANS_TYPE:2;
		vuint32_t WAIT_CYCLES:5;
		vuint32_t :1;
		vuint32_t INST_L:2;
		vuint32_t :9;
		vuint32_t CLK_STRETCH:1;
		vuint32_t :6;
	}B;

}SPI_CTRLR0_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t XIP_MD_BITS_L:8;
		vuint32_t XIP_MD_BITS_H:8;
		vuint32_t :16;
	}B;

}SSI_XIPMBR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t INCR_INST_L:8;
		vuint32_t INCR_INST_H:8;
		vuint32_t :16;
	}B;

}SSI_XIPIIR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t ADDR_L:4;
		vuint32_t TRANS_TYPE:2;
		vuint32_t FRF:2;
		vuint32_t WAIT_CYCLES_2_0:3;
		vuint32_t MD_BITS_EN:1;
		vuint32_t :1;
		vuint32_t INST_L:2;
		vuint32_t :1;
		vuint32_t CONT_XFER_EN:1;
		vuint32_t INST_EN:1;
		vuint32_t :3;
		vuint32_t DFS_HC:1;
		vuint32_t WAIT_CYCLES_4_3:2;
		vuint32_t :2;
		vuint32_t XIP_PREFETCH_EN:1;
		vuint32_t :1;
		vuint32_t XIP_MBL:2;
		vuint32_t :2;
	}B;

}SSI_XIPCR_tag;

typedef union
{
	vuint32_t R;
	struct
	{
		vuint32_t :7;
		vuint32_t XRXOICR:1;
		vuint32_t :24;
	}B;

}SSI_XRXOICR_tag;

struct SSI_tag{
    SSI_CTRLR0_tag CTRLR0;          //0x00
    SSI_CTRLR1_tag CTRLR1;          //0x04
    SSI_SSI_ENR_tag SSIENR;         //0x08
    uint32_t reserve_0c;       		//0x0c
    uint32_t reserve_10;       		//0x10
    SSI_BAUDR_tag BAUDR;           	//0x14
    SSI_TXFTLR_tag TXFTLR;          //0x18
    SSI_RXFTLR_tag RXFTLR;    	    //0x1c
    SSI_TXFLR_tag TXFLR;     	    //0x20
    SSI_RXFLR_tag RXFLR;     	    //0x24
    SSI_SR_tag SR;        	      	//0x28
    SSI_IMR_tag IMR;        	    //0x2c
    SSI_ISR_tag ISR;        	    //0x30
    SSI_RISR_tag RISR;       	    //0x34
    SSI_TXOICR_tag TXOICR;          //0x38
    SSI_RXOICR_tag RXOICR;          //0x3c
    SSI_RXUICR_tag RXUICR;          //0x40
    uint32_t reserve_44;       		//0x44
	SSI_ICR_tag ICR;             	//0x48
	SSI_DMACR_tag DMACR;           	//0x4c
	SSI_DMATDL_tag DMATDLR;         //0x50
	SSI_DMARDL_tag DMARDLR;         //0x54
    uint32_t reserve_58;       		//0x58
    uint32_t reserve_5c;	    	//0x5c
	SSI_DR_tag DR;              	//0x60
    uint32_t RESERVERED[35];	    //0x64~0xec
    SSI_RXSDR_tag RXSDR; 	        //0xf0
    SPI_CTRLR0_tag SPICTRLR0;      	//0xf4
    uint32_t reserve_f8;  	         //0xf8
    SSI_XIPMBR_tag XIPMBR;   	     //0xfc
    SSI_XIPIIR_tag XIPIIR;           //0x100
    uint32_t reserve_104;  	         //0x104
    SSI_XIPCR_tag XIPCR;             //0x108
    uint32_t reserve_10c;  	         //0x10c
    uint32_t reserve_110;  	         //0x110
    uint32_t reserve_114;      	 	 //0x114
};

/* MASK FOR SSI_CTRLR0(0x00) */
#define SSI_CTRLR0_FRF_WIDTH                         2u
#define SSI_CTRLR0_FRF_SHIFT                         30u
#define SSI_CTRLR0_FRF_MASK                          (((1U<<SSI_CTRLR0_FRF_WIDTH)-1U)<<SSI_CTRLR0_FRF_SHIFT)
#define SSI_CTRLR0_FRF_DATAW(x)                      (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR0_FRF_SHIFT))&SSI_CTRLR0_FRF_MASK)

#define SSI_CTRLR0_DFS_WIDTH                         5u
#define SSI_CTRLR0_DFS_SHIFT                         24u
#define SSI_CTRLR0_DFS_MASK                          (((1U<<SSI_CTRLR0_DFS_WIDTH)-1U)<<SSI_CTRLR0_DFS_SHIFT)
#define SSI_CTRLR0_DFS_DATAW(x)                      (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR0_DFS_SHIFT))&SSI_CTRLR0_DFS_MASK)

#define SSI_CTRLR0_SSTE_WIDTH                        1u
#define SSI_CTRLR0_SSTE_SHIFT                        22u
#define SSI_CTRLR0_SSTE_MASK                         (((1U<<SSI_CTRLR0_SSTE_WIDTH)-1U)<<SSI_CTRLR0_SSTE_SHIFT)
#define SSI_CTRLR0_SSTE_DATAW(x)                     (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR0_SSTE_SHIFT))&SSI_CTRLR0_SSTE_MASK)

#define SSI_CTRLR0_SSRL_WIDTH                        1u
#define SSI_CTRLR0_SSRL_SHIFT                        21u
#define SSI_CTRLR0_SSRL_MASK                         (((1U<<SSI_CTRLR0_SSRL_WIDTH)-1U)<<SSI_CTRLR0_SSRL_SHIFT)
#define SSI_CTRLR0_SSRL_DATAW(x)                     (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR0_SSRL_SHIFT))&SSI_CTRLR0_SSRL_MASK)

#define SSI_CTRLR0_TMOD_WIDTH                        2u
#define SSI_CTRLR0_TMOD_SHIFT                        18u
#define SSI_CTRLR0_TMOD_MASK                         (((1U<<SSI_CTRLR0_TMOD_WIDTH)-1U)<<SSI_CTRLR0_TMOD_SHIFT)
#define SSI_CTRLR0_TMOD_DATAW(x)                     (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR0_TMOD_SHIFT))&SSI_CTRLR0_TMOD_MASK)

#define SSI_CTRLR0_SCOPL_WIDTH                       1u
#define SSI_CTRLR0_SCOPL_SHIFT                       17u
#define SSI_CTRLR0_SCOPL_MASK                        (((1U<<SSI_CTRLR0_SCOPL_WIDTH)-1U)<<SSI_CTRLR0_SCOPL_SHIFT)
#define SSI_CTRLR0_SCOPL_DATAW(x)                    (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR0_SCOPL_SHIFT))&SSI_CTRLR0_SCOPL_MASK)

#define SSI_CTRLR0_SCPH_WIDTH                        1u
#define SSI_CTRLR0_SCPH_SHIFT                        16u
#define SSI_CTRLR0_SCPH_MASK                         (((1U<<SSI_CTRLR0_SCPH_WIDTH)-1U)<<SSI_CTRLR0_SCPH_SHIFT)
#define SSI_CTRLR0_SCPH_DATAW(x)                     (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR0_SCPH_SHIFT))&SSI_CTRLR0_SCPH_MASK)

#define SSI_CTRLR0_SPI_FRF_WIDTH                     2u
#define SSI_CTRLR0_SPI_FRF_SHIFT                     14u
#define SSI_CTRLR0_SPI_FRF_MASK                      (((1U<<SSI_CTRLR0_SPI_FRF_WIDTH)-1U)<<SSI_CTRLR0_SPI_FRF_SHIFT)
#define SSI_CTRLR0_SPI_FRF_DATAW(x)                  (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR0_SPI_FRF_SHIFT))&SSI_CTRLR0_SPI_FRF_MASK)

#define SSI_CTRLR0_CFS_WIDTH                         4u
#define SSI_CTRLR0_CFS_SHIFT                         8u
#define SSI_CTRLR0_CFS_MASK                          (((1U<<SSI_CTRLR0_CFS_WIDTH)-1U)<<SSI_CTRLR0_CFS_SHIFT)
#define SSI_CTRLR0_CFS_DATAW(x)                      (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR0_CFS_SHIFT))&SSI_CTRLR0_CFS_MASK)

/* MASK FOR SSICTRL1(0x04) */
#define SSI_CTRLR1_NDF_H_WIDTH                     8u
#define SSI_CTRLR1_NDF_H_SHIFT                     16u
#define SSI_CTRLR1_NDF_H_MASK                      (((1U<<SSI_CTRLR1_NDF_H_WIDTH)-1U)<<SSI_CTRLR1_NDF_H_SHIFT)
#define SSI_CTRLR1_NDF_H_DATAW(x)                  (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR1_NDF_H_SHIFT))&SSI_CTRLR1_NDF_H_MASK)

#define SSI_CTRLR1_NDF_L_WIDTH                     8u
#define SSI_CTRLR1_NDF_L_SHIFT                     24u
#define SSI_CTRLR1_NDF_L_MASK                      (((1U<<SSI_CTRLR1_NDF_L_WIDTH)-1U)<<SSI_CTRLR1_NDF_L_SHIFT)
#define SSI_CTRLR1_NDF_L_DATAW(x)                  (((uint32_t)(((uint32_t)(x))<<SSI_CTRLR1_NDF_L_SHIFT))&SSI_CTRLR1_NDF_L_MASK)

/* MASK FOR SSIENR(0x08) */
#define SSI_ENR_SSIC_EN_WIDTH                        1U
#define SSI_ENR_SSIC_EN_SHIFT                        24U
#define SSI_ENR_SSIC_EN_MASK                         (((1U<<SSI_ENR_SSIC_EN_WIDTH)-1U)<<SSI_ENR_SSIC_EN_SHIFT)
#define SSI_ENR_SSIC_EN_DATAW(x)                     (((uint32_t)(((uint32_t)(x))<<SSI_ENR_SSIC_EN_SHIFT))&SSI_ENR_SSIC_EN_MASK)

/* MASK FOR SSI_BAUDR(0x14) */
#define SSI_BAUDR_SCKDV_L_WIDTH                     8U
#define SSI_BAUDR_SCKDV_L_SHIFT                     24U
#define SSI_BAUDR_SCKDV_L_MASK                      (((1U<<SSI_BAUDR_SCKDV_L_WIDTH)-1U)<<SSI_BAUDR_SCKDV_L_SHIFT)
#define SSI_BAUDR_SCKDV_L_DATAW(x)                  (((uint32_t)(((uint32_t)(x))<<SSI_BAUDR_SCKDV_L_SHIFT))&SSI_BAUDR_SCKDV_L_MASK)

#define SSI_BAUDR_SCKDV_H_WIDTH                     8U
#define SSI_BAUDR_SCKDV_H_SHIFT                     16U
#define SSI_BAUDR_SCKDV_H_MASK                      (((1U<<SSI_BAUDR_SCKDV_H_WIDTH)-1U)<<SSI_BAUDR_SCKDV_H_SHIFT)
#define SSI_BAUDR_SCKDV_H_DATAW(x)                  (((uint32_t)(((uint32_t)(x))<<SSI_BAUDR_SCKDV_H_SHIFT))&SSI_BAUDR_SCKDV_H_MASK)

/* 0xF0 */
#define SSI_RXSD_RSD_WIDTH                     8U
#define SSI_RXSD_RSD_SHIFT                     24U
#define SSI_RXSD_RSD_MASK                      (((1U<<SSI_RXSD_RSD_WIDTH)-1U)<<SSI_RXSD_RSD_SHIFT)
#define SSI_RXSD_RSD_DATAW(x)                  (((uint32_t)(((uint32_t)(x))<<SSI_RXSD_RSD_SHIFT))&SSI_RXSD_RSD_MASK)

#define SSI_RXSD_SE_WIDTH                     1U
#define SSI_RXSD_SE_SHIFT                     8U
#define SSI_RXSD_SE_MASK                      (((1U<<SSI_RXSD_SE_WIDTH)-1U)<<SSI_RXSD_SE_SHIFT)
#define SSI_RXSD_SE_DATAW(x)                  (((uint32_t)(((uint32_t)(x))<<SSI_RXSD_SE_SHIFT))&SSI_RXSD_SE_MASK)

/* 0x18 */
#define SSI_TXFTL_TFT_WIDTH                     5U
#define SSI_TXFTL_TFT_SHIFT                     24U
#define SSI_TXFTL_TFT_MASK                      (((1U<<SSI_TXFTL_TFT_WIDTH)-1U)<<SSI_TXFTL_TFT_SHIFT)
#define SSI_TXFTL_TFT_DATAW(x)                  (((uint32_t)(((uint32_t)(x))<<SSI_TXFTL_TFT_SHIFT))&SSI_TXFTL_TFT_MASK)

#define SSI_TXFTL_TXFTHR_WIDTH                  5U
#define SSI_TXFTL_TXFTHR_SHIFT                  8U
#define SSI_TXFTL_TXFTHR_MASK                   (((1U<<SSI_TXFTL_TXFTHR_WIDTH)-1U)<<SSI_TXFTL_TXFTHR_SHIFT)
#define SSI_TXFTL_TXFTHR_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_TXFTL_TXFTHR_SHIFT))&SSI_TXFTL_TXFTHR_MASK)


/* 0x1c */
#define SSI_RXFTLR_RFT_WIDTH                  5U
#define SSI_RXFTLR_RFT_SHIFT                  24U
#define SSI_RXFTLR_RFT_MASK                   (((1U<<SSI_RXFTLR_RFT_WIDTH)-1U)<<SSI_RXFTLR_RFT_SHIFT)
#define SSI_RXFTLR_RFT_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_RXFTLR_RFT_SHIFT))&SSI_RXFTLR_RFT_MASK)

/* 0x28 */
#define SSI_SR_RFF_WIDTH                  1U
#define SSI_SR_RFF_SHIFT                  28U
#define SSI_SR_RFF_MASK                   (((1U<<SSI_SR_RFF_WIDTH)-1U)<<SSI_SR_RFF_SHIFT)
#define SSI_SR_RFF_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_SR_RFF_SHIFT))&SSI_SR_RFF_MASK)

#define SSI_SR_RFNE_WIDTH                  1U
#define SSI_SR_RFNE_SHIFT                  27U
#define SSI_SR_RFNE_MASK                   (((1U<<SSI_SR_RFNE_WIDTH)-1U)<<SSI_SR_RFNE_SHIFT)
#define SSI_SR_RFNE_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_SR_RFNE_SHIFT))&SSI_SR_RFNE_MASK)

#define SSI_SR_TFE_WIDTH                  1U
#define SSI_SR_TFE_SHIFT                  26U
#define SSI_SR_TFE_MASK                   (((1U<<SSI_SR_TFE_WIDTH)-1U)<<SSI_SR_TFE_SHIFT)
#define SSI_SR_TFE_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_SR_TFE_SHIFT))&SSI_SR_TFE_MASK)

#define SSI_SR_TFNF_WIDTH                  1U
#define SSI_SR_TFNF_SHIFT                  25U
#define SSI_SR_TFNF_MASK                   (((1U<<SSI_SR_TFNF_WIDTH)-1U)<<SSI_SR_TFNF_SHIFT)
#define SSI_SR_TFNF_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_SR_TFNF_SHIFT))&SSI_SR_TFNF_MASK)

#define SSI_SR_BUSY_WIDTH                  1U
#define SSI_SR_BUSY_SHIFT                  24U
#define SSI_SR_BUSY_MASK                   (((1U<<SSI_SR_BUSY_WIDTH)-1U)<<SSI_SR_BUSY_SHIFT)
#define SSI_SR_BUSY_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_SR_BUSY_SHIFT))&SSI_SR_BUSY_MASK)
/* 0x2c */
#define SSI_IMR_XRXOIM_WIDTH                 2U
#define SSI_IMR_XRXOIM_SHIFT                 29U
#define SSI_IMR_XRXOIM_MASK                  (((1U<<SSI_IMR_XRXOIM_WIDTH)-1U)<<SSI_IMR_XRXOIM_SHIFT)
#define SSI_IMR_XRXOIM_DATAW(x)              (((uint32_t)(((uint32_t)(x))<<SSI_IMR_XRXOIM_SHIFT))&SSI_IMR_XRXOIM_MASK)

#define SSI_IMR_RXFIM_WIDTH                  1U
#define SSI_IMR_RXFIM_SHIFT                  28U
#define SSI_IMR_RXFIM_MASK                   (((1U<<SSI_IMR_RXFIM_WIDTH)-1U)<<SSI_IMR_RXFIM_SHIFT)
#define SSI_IMR_RXFIM_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_IMR_RXFIM_SHIFT))&SSI_IMR_RXFIM_MASK)

#define SSI_IMR_RXOIM_WIDTH                  1U
#define SSI_IMR_RXOIM_SHIFT                  27U
#define SSI_IMR_RXOIM_MASK                   (((1U<<SSI_IMR_RXOIM_WIDTH)-1U)<<SSI_IMR_RXOIM_SHIFT)
#define SSI_IMR_RXOIM_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_IMR_RXOIM_SHIFT))&SSI_IMR_RXOIM_MASK)

#define SSI_IMR_RXUIM_WIDTH                  1U
#define SSI_IMR_RXUIM_SHIFT                  26U
#define SSI_IMR_RXUIM_MASK                   (((1U<<SSI_IMR_RXUIM_WIDTH)-1U)<<SSI_IMR_RXUIM_SHIFT)
#define SSI_IMR_RXUIM_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_IMR_RXUIM_SHIFT))&SSI_IMR_RXUIM_MASK)

#define SSI_IMR_TXOIM_WIDTH                  1U
#define SSI_IMR_TXOIM_SHIFT                  25U
#define SSI_IMR_TXOIM_MASK                   (((1U<<SSI_IMR_TXOIM_WIDTH)-1U)<<SSI_IMR_TXOIM_SHIFT)
#define SSI_IMR_TXOIM_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_IMR_TXOIM_SHIFT))&SSI_IMR_TXOIM_MASK)

#define SSI_IMR_TXEIM_WIDTH                  1U
#define SSI_IMR_TXEIM_SHIFT                  24U
#define SSI_IMR_TXEIM_MASK                   (((1U<<SSI_IMR_TXEIM_WIDTH)-1U)<<SSI_IMR_TXEIM_SHIFT)
#define SSI_IMR_TXEIM_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_IMR_TXEIM_SHIFT))&SSI_IMR_TXEIM_MASK)

/* 0x4C */
#define SSI_DMACR_TDMAE_WIDTH                  1U
#define SSI_DMACR_TDMAE_SHIFT                  25U
#define SSI_DMACR_TDMAE_MASK                   (((1U<<SSI_DMACR_TDMAE_WIDTH)-1U)<<SSI_DMACR_TDMAE_SHIFT)
#define SSI_DMACR_TDMAE_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_DMACR_TDMAE_SHIFT))&SSI_DMACR_TDMAE_MASK)

#define SSI_DMACR_RDMAE_WIDTH                  1U
#define SSI_DMACR_RDMAE_SHIFT                  24U
#define SSI_DMACR_RDMAE_MASK                   (((1U<<SSI_DMACR_RDMAE_WIDTH)-1U)<<SSI_DMACR_RDMAE_SHIFT)
#define SSI_DMACR_RDMAE_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_DMACR_RDMAE_SHIFT))&SSI_DMACR_RDMAE_MASK)

/* 0x50  */
#define SSI_DMATDL_WIDTH                  3U
#define SSI_DMATDL_SHIFT                  24U
#define SSI_DMATDL_MASK                   (((1U<<SSI_DMATDL_WIDTH)-1U)<<SSI_DMATDL_SHIFT)
#define SSI_DMATDL_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_DMATDL_SHIFT))&SSI_DMATDL_MASK)

/* 0x54 */
#define SSI_DMARDL_WIDTH                  3U
#define SSI_DMARDL_SHIFT                  24U
#define SSI_DMARDL_MASK                   (((1U<<SSI_DMARDL_WIDTH)-1U)<<SSI_DMARDL_SHIFT)
#define SSI_DMARDL_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_DMARDL_SHIFT))&SSI_DMARDL_MASK)

/* MASK FOR SPICTRLR0(0xf4) */
#define SSI_SPICTRLR0_ADDR_L_WIDTH                  4U
#define SSI_SPICTRLR0_ADDR_L_SHIFT                  26U
#define SSI_SPICTRLR0_ADDR_L_MASK                   (((1U<<SSI_SPICTRLR0_ADDR_L_WIDTH)-1U)<<SSI_SPICTRLR0_ADDR_L_SHIFT)
#define SSI_SPICTRLR0_ADDR_L_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_SPICTRLR0_ADDR_L_SHIFT))&SSI_SPICTRLR0_ADDR_L_MASK)

#define SSI_SPICTRLR0_TRANS_TYPE_WIDTH              2U
#define SSI_SPICTRLR0_TRANS_TYPE_SHIFT              24U
#define SSI_SPICTRLR0_TRANS_TYPE_MASK               (((1U<<SSI_SPICTRLR0_TRANS_TYPE_WIDTH)-1U)<<SSI_SPICTRLR0_TRANS_TYPE_SHIFT)
#define SSI_SPICTRLR0_TRANS_TYPE_DATAW(x)           (((uint32_t)(((uint32_t)(x))<<SSI_SPICTRLR0_TRANS_TYPE_SHIFT))&SSI_SPICTRLR0_TRANS_TYPE_MASK)

#define SSI_SPICTRLR0_WAIT_CYCLES_WIDTH             5U
#define SSI_SPICTRLR0_WAIT_CYCLES_SHIFT             19U
#define SSI_SPICTRLR0_WAIT_CYCLES_MASK              (((1U<<SSI_SPICTRLR0_WAIT_CYCLES_WIDTH)-1U)<<SSI_SPICTRLR0_WAIT_CYCLES_SHIFT)
#define SSI_SPICTRLR0_WAIT_CYCLES_DATAW(x)          (((uint32_t)(((uint32_t)(x))<<SSI_SPICTRLR0_WAIT_CYCLES_SHIFT))&SSI_SPICTRLR0_WAIT_CYCLES_MASK)

#define SSI_SPICTRLR0_INST_L_WIDTH                  2U
#define SSI_SPICTRLR0_INST_L_SHIFT                  16U
#define SSI_SPICTRLR0_INST_L_MASK                   (((1U<<SSI_SPICTRLR0_INST_L_WIDTH)-1U)<<SSI_SPICTRLR0_INST_L_SHIFT)
#define SSI_SPICTRLR0_INST_L_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_SPICTRLR0_INST_L_SHIFT))&SSI_SPICTRLR0_INST_L_MASK)

#define SSI_SPICTRLR0_CLK_STH_WIDTH                  1U
#define SSI_SPICTRLR0_CLK_STH_SHIFT                  6U
#define SSI_SPICTRLR0_CLK_STH_MASK                   (((1U<<SSI_SPICTRLR0_CLK_STH_WIDTH)-1U)<<SSI_SPICTRLR0_CLK_STH_SHIFT)
#define SSI_SPICTRLR0_CLK_STH_DATAW(x)               (((uint32_t)(((uint32_t)(x))<<SSI_SPICTRLR0_CLK_STH_SHIFT))&SSI_SPICTRLR0_CLK_STH_MASK)


/* MASK FOR SSI-XIPCR */
#define XIPCR_XIP_MBL_WIDTH                         2u
#define XIPCR_XIP_MBL_SHIFT                         2u
#define XIPCR_XIP_MBL_MASK                          (((1U<<XIPCR_XIP_MBL_WIDTH)-1U)<<XIPCR_XIP_MBL_SHIFT)
#define XIPCR_XIP_MBL_DATAW(x)                      (((uint32_t)(((uint32_t)(x))<<XIPCR_XIP_MBL_SHIFT))&XIPCR_XIP_MBL_MASK)

#define XIPCR_INST_EN_WIDTH                         1u
#define XIPCR_INST_EN_SHIFT                         14u
#define XIPCR_INST_EN_MASK                          (((1U<<XIPCR_INST_EN_WIDTH)-1U)<<XIPCR_INST_EN_SHIFT)
#define XIPCR_INST_EN_DATAW(x)                      (((uint32_t)(((uint32_t)(x))<<XIPCR_INST_EN_SHIFT))&XIPCR_INST_EN_MASK)

#define XIPCR_WAIT_CYCLES_4_3_WIDTH                 2u
#define XIPCR_WAIT_CYCLES_4_3_SHIFT                 8u
#define XIPCR_WAIT_CYCLES_4_3_MASK                  (((1U<<XIPCR_WAIT_CYCLES_4_3_WIDTH)-1U)<<XIPCR_WAIT_CYCLES_4_3_SHIFT)
#define XIPCR_WAIT_CYCLES_4_3_DATAW(x)              (((uint32_t)(((uint32_t)(x))<<XIPCR_WAIT_CYCLES_4_3_SHIFT))&XIPCR_WAIT_CYCLES_4_3_MASK)

#define XIPCR_WAIT_CYCLES_2_0_WIDTH                 3u
#define XIPCR_WAIT_CYCLES_2_0_SHIFT                 21u
#define XIPCR_WAIT_CYCLES_2_0_MASK                  (((1U<<XIPCR_WAIT_CYCLES_2_0_WIDTH)-1U)<<XIPCR_WAIT_CYCLES_2_0_SHIFT)
#define XIPCR_WAIT_CYCLES_2_0_DATAW(x)              (((uint32_t)(((uint32_t)(x))<<XIPCR_WAIT_CYCLES_2_0_SHIFT))&XIPCR_WAIT_CYCLES_2_0_MASK)

#define XIPCR_INST_L_WIDTH                          2u
#define XIPCR_INST_L_SHIFT                          17u
#define XIPCR_INST_L_MASK                           (((1U<<XIPCR_INST_L_WIDTH)-1U)<<XIPCR_INST_L_SHIFT)
#define XIPCR_INST_L_DATAW(x)                       (((uint32_t)(((uint32_t)(x))<<XIPCR_INST_L_SHIFT))&XIPCR_INST_L_MASK)

#define XIPCR_MD_BITS_EN_WIDTH                      1u
#define XIPCR_MD_BITS_EN_SHIFT                      20u
#define XIPCR_MD_BITS_EN_MASK                       (((1U<<XIPCR_MD_BITS_EN_WIDTH)-1U)<<XIPCR_MD_BITS_EN_SHIFT)
#define XIPCR_MD_BITS_EN_DATAW(x)                   (((uint32_t)(((uint32_t)(x))<<XIPCR_MD_BITS_EN_SHIFT))&XIPCR_MD_BITS_EN_MASK)

#define XIPCR_FRF_WIDTH                             2u
#define XIPCR_FRF_SHIFT                             24u
#define XIPCR_FRF_MASK                              (((1U<<XIPCR_FRF_WIDTH)-1U)<<XIPCR_FRF_SHIFT)
#define XIPCR_FRF_DATAW(x)                          (((uint32_t)(((uint32_t)(x))<<XIPCR_FRF_SHIFT))&XIPCR_FRF_MASK)

#define XIPCR_TRANS_TYPE_WIDTH                      2u
#define XIPCR_TRANS_TYPE_SHIFT                      26u
#define XIPCR_TRANS_TYPE_MASK                       (((1U<<XIPCR_TRANS_TYPE_WIDTH)-1U)<<XIPCR_TRANS_TYPE_SHIFT)
#define XIPCR_TRANS_TYPE_DATAW(x)                   (((uint32_t)(((uint32_t)(x))<<XIPCR_TRANS_TYPE_SHIFT))&XIPCR_TRANS_TYPE_MASK)

#define XIPCR_ADDR_L_WIDTH                          4u
#define XIPCR_ADDR_L_SHIFT                          28u
#define XIPCR_ADDR_L_MASK                           (((1U<<XIPCR_ADDR_L_WIDTH)-1U)<<XIPCR_ADDR_L_SHIFT)
#define XIPCR_ADDR_L_DATAW(x)                       (((uint32_t)(((uint32_t)(x))<<XIPCR_ADDR_L_SHIFT))&XIPCR_ADDR_L_MASK)

/* MASK FOR XIPMBR */
#define SSI_XIPMBR_MD_BITS_15_8_WIDTH               8U
#define SSI_XIPMBR_MD_BITS_15_8_SHIFT               16U
#define SSI_XIPMBR_MD_BITS_15_8_MASK                (((1U<<SSI_XIPMBR_MD_BITS_15_8_WIDTH)-1U)<<SSI_XIPMBR_MD_BITS_15_8_SHIFT)
#define SSI_XIPMBR_MD_BITS_15_8_DATAW(x)            (((uint32_t)(((uint32_t)(x))<<SSI_XIPMBR_MD_BITS_15_8_SHIFT))&SSI_XIPMBR_MD_BITS_15_8_MASK)

#define SSI_XIPMBR_MD_BITS_7_0_WIDTH                8U
#define SSI_XIPMBR_MD_BITS_7_0_SHIFT                24U
#define SSI_XIPMBR_MD_BITS_7_0_MASK                 (((1U<<SSI_XIPMBR_MD_BITS_7_0_WIDTH)-1U)<<SSI_XIPMBR_MD_BITS_7_0_SHIFT)
#define SSI_XIPMBR_MD_BITS_7_0_DATAW(x)             (((uint32_t)(((uint32_t)(x))<<SSI_XIPMBR_MD_BITS_7_0_SHIFT))&SSI_XIPMBR_MD_BITS_7_0_MASK)

/* MASK FOR XIPIIR */
#define SSI_XIPIIR_INCR_INST_L_WIDTH               8U
#define SSI_XIPIIR_INCR_INST_L_SHIFT               24U
#define SSI_XIPIIR_INCR_INST_L_MASK                (((1U<<SSI_XIPIIR_INCR_INST_L_WIDTH)-1U)<<SSI_XIPIIR_INCR_INST_L_SHIFT)
#define SSI_XIPIIR_INCR_INST_L_DATAW(x)            (((uint32_t)(((uint32_t)(x))<<SSI_XIPIIR_INCR_INST_L_SHIFT))&SSI_XIPIIR_INCR_INST_L_MASK)

#define SSI_XIPIIR_INCR_INST_H_WIDTH               8U
#define SSI_XIPIIR_INCR_INST_H_SHIFT               16U
#define SSI_XIPIIR_INCR_INST_H_MASK                (((1U<<SSI_XIPIIR_INCR_INST_H_WIDTH)-1U)<<SSI_XIPIIR_INCR_INST_H_SHIFT)
#define SSI_XIPIIR_INCR_INST_H_DATAW(x)            (((uint32_t)(((uint32_t)(x))<<SSI_XIPIIR_INCR_INST_H_SHIFT))&SSI_XIPIIR_INCR_INST_H_MASK)


#endif
