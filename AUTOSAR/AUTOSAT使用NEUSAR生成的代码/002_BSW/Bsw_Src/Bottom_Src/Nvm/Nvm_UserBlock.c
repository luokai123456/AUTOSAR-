/*** create info ***********************
*@ Author : wangjiacheng
*@ date :2025-12-04
*@ Description :NVM user block definitions
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : wangjiacheng 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#include "NvM_UserBlock.h"


/* Array of pointers to RAM BLOCK variables for blocks 2-34 */
uint8* const NvM_RamBlockArray[] = {
    (uint8*)0,
    (uint8*)0,
    (uint8*)NvMBlock2_ResetReason,                          /* Block 2 */
    (uint8*)NvMBlock3_OsError,                          /* Block 3 */
    (uint8*)NvMBlock4_FunErrDiag_Security,                          /* Block 4 */
    (uint8*)NvMBlock5_Information_Security,                        /* Block 5 */
    (uint8*)NvMBlock6_Dcm_11_NvMBuf,                        /* Block 6 */
    (uint8*)NvMBlock7_Dcm_27_Security_Data,                        /* Block 7 */
    (uint8*)NvMBlock8_Uds_Faultstatus_agingcount,                        /* Block 8 */
    (uint8*)NvMBlock9_Uds_Faultstatus_agingcount,                        /* Block 9 */
    (uint8*)NvMBlock10_Uds_Frozendata,                       /* Block 10 */
    (uint8*)NvMBlock11_Uds_Frozendata,                       /* Block 11 */
    (uint8*)NvMBlock12_Uds_Frozendata,                       /* Block 12 */
    (uint8*)NvMBlock13_Uds_Frozendata,                       /* Block 13 */
    (uint8*)NvMBlock14_Uds_Frozendata,                       /* Block 14 */
    (uint8*)NvMBlock15_Uds_Frozendata,                       /* Block 15 */
    (uint8*)NvMBlock16_Uds_Frozendata,                       /* Block 16 */
    (uint8*)NvMBlock17_Uds_Frozendata,                       /* Block 17 */
    (uint8*)NvMBlock18_Uds_Frozendata,                       /* Block 18 */
    (uint8*)NvMBlock19_Uds_Frozendata,                       /* Block 19 */
    (uint8*)NvMBlock20_Uds_Frozendata,                       /* Block 20 */
    (uint8*)NvMBlock21_Uds_Frozendata,                       /* Block 21 */
    (uint8*)NvMBlock22_Uds_Frozendata,                       /* Block 22 */
    (uint8*)NvMBlock23_Uds_Frozendata,                       /* Block 23 */
    (uint8*)NvMBlock24_Uds_Frozendata,                       /* Block 24 */
    (uint8*)NvMBlock25_Uds_Frozendata,                     /* Block 25 */
    (uint8*)NvMBlock26_Uds_Frozendata,                          /* Block 26 */
    (uint8*)NvMBlock27_Uds_Frozendata,                          /* Block 27 */
    (uint8*)NvMBlock28_Uds_Frozendata,                          /* Block 28 */
    (uint8*)NvMBlock29_Uds_Frozendata,                        /* Block 29 */
    (uint8*)NvMBlock30_Uds_Frozendata,                        /* Block 30 */
    (uint8*)NvMBlock31_Uds_Frozendata,                        /* Block 31 */
    (uint8*)NvMBlock32_Uds_Frozendata,                        /* Block 32 */
    (uint8*)NvMBlock33_Uds_Frozendata,                        /* Block 33 */
    (uint8*)NvMBlock34_Uds_Frozendata,                       /* Block 34 */
    (uint8*)NvMBlock35_Uds_Frozendata,                       /* Block 35 */
    (uint8*)NvMBlock36_Uds_Frozendata,                       /* Block 36 */
    (uint8*)NvMBlock37_Uds_Frozendata,                       /* Block 37 */
    (uint8*)NvMBlock38_Uds_Frozendata,                       /* Block 38 */
    (uint8*)NvMBlock39_Uds_Frozendata,                       /* Block 39 */
    (uint8*)NvMBlock40_Uds_Frozendata,                       /* Block 40 */
    (uint8*)NvMBlock41_Uds_Frozendata,                       /* Block 41 */
    (uint8*)NvMBlock42_Uds_Frozendata,                       /* Block 42 */
    (uint8*)NvMBlock43_Uds_Frozendata,                       /* Block 43 */
    (uint8*)NvMBlock44_Uds_Frozendata,                       /* Block 44 */
    (uint8*)NvMBlock45_Uds_Frozendata,                       /* Block 45 */
    (uint8*)NvMBlock46_Uds_Frozendata,                       /* Block 46 */
    (uint8*)NvMBlock47_Uds_Frozendata,                       /* Block 47 */
    (uint8*)NvMBlock48_Uds_Frozendata,                       /* Block 48 */
    (uint8*)NvMBlock49_Uds_Frozendata,                     /* Block 49 */
    (uint8*)NvMBlock50_DCM2E_ASW,     
    (uint8*)NvMBlock51_DCM2E_ASW,  
    (uint8*)NvMBlock52_DCM2E_ASW,  
    (uint8*)NvMBlock53_DCM2E_ASW,  
    (uint8*)NvMBlock54_DCM2E_ASW,  
    (uint8*)NvMBlock55_DCM2E_ASW,         
    (uint8*)NvMBlock56_DCM2E_ASW,     
    (uint8*)NvMBlock57_DCM2E_ASW,  
    (uint8*)NvMBlock58_DCM2E_ASW,  
    (uint8*)NvMBlock59_DCM2E_ASW,  
    (uint8*)NvMBlock60_DCM2E_ASW,  
    (uint8*)NvMBlock61_DCM2E_ASW,  
    (uint8*)NvMBlock62_DCM2E_ASW,     
    (uint8*)NvMBlock63_DCM2E_ASW,  
    (uint8*)NvMBlock64_DCM2E_ASW,  
    (uint8*)NvMBlock65_DCM2E_ASW,  
    (uint8*)NvMBlock66_DCM2E_ASW,  
    (uint8*)NvMBlock67_DCM2E_ASW,  
    (uint8*)NvMBlock68_DCM2E_ASW,     
    (uint8*)NvMBlock69_DCM2E_ASW,  
    (uint8*)NvMBlock70_DCM2E_ASW,  
    (uint8*)NvMBlock71_DCM2E_ASW,  
    (uint8*)NvMBlock72_DCM2E_ASW,  
    (uint8*)NvMBlock73_DCM2E_ASW,  
    (uint8*)NvMBlock74_DCM2E_ASW,     
    (uint8*)NvMBlock75_DCM2E_ASW,  
    (uint8*)NvMBlock76_DCM2E_ASW,  
    (uint8*)NvMBlock77_DCM2E_ASW,  
    (uint8*)NvMBlock78_DCM2E_ASW,  
    (uint8*)NvMBlock79_DCM2E_ASW,  
    (uint8*)NvMBlock80_DCM2E_ASW,     
    (uint8*)NvMBlock81_DCM2E_ASW,  
    (uint8*)NvMBlock82_DCM2E_ASW,  
    (uint8*)NvMBlock83_DCM2E_ASW,  
    (uint8*)NvMBlock84_DCM2E_ASW,  
    (uint8*)NvMBlock85_DCM2E_ASW,               
    (uint8*)NvMBlock86_DCM2E_ASW,  
    (uint8*)NvMBlock87_DCM2E_ASW,  
    (uint8*)NvMBlock88_DCM2E_ASW,     
    (uint8*)NvMBlock89_DCM2E_ASW,  
    (uint8*)NvMBlock90_DCM2E_ASW,  
    (uint8*)NvMBlock91_DCM2E_ASW,  
    (uint8*)NvMBlock92_DCM2E_ASW,  
    (uint8*)NvMBlock93_DCM2E_ASW,  
    (uint8*)NvMBlock94_DCM2E_ASW,     
    (uint8*)NvMBlock95_DCM2E_ASW,  
    (uint8*)NvMBlock96_DCM2E_ASW,  
    (uint8*)NvMBlock97_DCM2E_ASW,  
    (uint8*)NvMBlock98_DCM2E_ASW,  
    (uint8*)NvMBlock99_DCM2E_ASW,     
    (uint8*)NvMBlock100_DCM2E_ASW,  
    (uint8*)NvMBlock101_DCM2E_ASW,  
    (uint8*)NvMBlock102_DCM2E_BOOT,  
    (uint8*)NvMBlock103_DCM2E_BOOT,
    (uint8*)NvMBlock104_DCM2E_BOOT,  
    (uint8*)NvMBlock105_DCM2E_BOOT,  
    (uint8*)NvMBlock106_DCM2E_BOOT,  
    (uint8*)NvMBlock107_DCM2E_SHARE,  
    (uint8*)NvMBlock108_DCM2E_SHARE,  
    (uint8*)NvMBlock109_DCM2E_SHARE,  
    (uint8*)NvMBlock110_DCM2E_SHARE, 
    (uint8*)NvMBlock111_DCM2E_SHARE,  
    (uint8*)NvMBlock112_DCM2E_SHARE, 
    (uint8*)NvMBlock113_DCM2E_SHARE,  
    (uint8*)NvMBlock114_DCM2E_SHARE, 
    (uint8*)NvMBlock115_DCM2E_SHARE,  
    (uint8*)NvMBlock116_DCM2E_SHARE, 
    (uint8*)NvMBlock117_DCM2E_SHARE,  
    (uint8*)NvMBlock118_DCM2E_SHARE, 
    (uint8*)NvMBlock119_DCM2E_SHARE,  
    (uint8*)NvMBlock120_Reserve_ASW,
    (uint8*)NvMBlock121_Reserve_ASW,
    (uint8*)NvMBlock122_Reserve_ASW,
    (uint8*)NvMBlock123_Reserve_ASW,
    (uint8*)NvMBlock124_Reserve_ASW,
    (uint8*)NvMBlock125_Reserve_ASW,
    (uint8*)NvMBlock126_Reserve_ASW,
    (uint8*)NvMBlock127_Reserve_ASW,
    (uint8*)NvMBlock128_Reserve_ASW,
    (uint8*)NvMBlock129_Reserve_ASW,
    (uint8*)NvMBlock130_Reserve_ASW,
    (uint8*)NvMBlock131_Reserve_ASW,
    (uint8*)&Dem_EventMemoryStatus,
    (uint8*)&Dem_PrimaryEventMemoryInfo,
    (uint8*)&Dem_PrimaryEventMemoryEntry[0],
    (uint8*)&Dem_PrimaryEventMemoryEntry[1],
    (uint8*)&Dem_PrimaryEventMemoryEntry[2],
    (uint8*)&Dem_PrimaryEventMemoryEntry[3],
    (uint8*)&Dem_PrimaryEventMemoryEntry[4],
    (uint8*)&Dem_PrimaryEventMemoryEntry[5],
    (uint8*)&Dem_PrimaryEventMemoryEntry[6],
    (uint8*)&Dem_PrimaryEventMemoryEntry[7],
    (uint8*)&Dem_PrimaryEventMemoryEntry[8],
    (uint8*)&Dem_PrimaryEventMemoryEntry[9],
    (uint8*)&Dcm_Did_Block0090_Data.Dcm_DidF199Buffer,
    (uint8*)&Dcm_Did_Block0091_Data.Dcm_DidF190Buffer,
    (uint8*)&Dcm_Did_Block0092_Data.Dcm_DidF1A2Buffer,
    (uint8*)&Dcm_Did_Block0093_Data.Dcm_DidF112Buffer,
    (uint8*)&Dcm_Did_Block0094_Data.Dcm_DidF198Buffer,
    (uint8*)&Dcm_Did_Block0095_Data.Dcm_DidF197Buffer,
    (uint8*)&Dcm_Did_Block0096_Data.Dcm_DidDFECBuffer,
    (uint8*)&Dcm_Did_Block0097_Data.Dcm_DidDFEDBuffer,
    (uint8*)&Dcm_Did_Block0098_Data.Dcm_DidDFEEBuffer,
    (uint8*)&Dcm_Did_Block0099_Data.Dcm_DidDFEFBuffer,
    (uint8*)&Dcm_Did_Block009A_Data.Dcm_DidF101Buffer,
    (uint8*)&Dcm_Did_Block009B_Data.Dcm_DidF110Buffer,
    (uint8*)&Dcm_Did_Block009C_Data.Dcm_DidD135Buffer,
    (uint8*)&Dcm_Did_Block009D_Data.Dcm_DidD136Buffer,
    (uint8*)&Dcm_Did_Block009E_Data.Dcm_Did0280Buffer,
    (uint8*)&Dcm_Did_Block009F_Data.Dcm_Did05D5Buffer,
    (uint8*)&Dcm_Did_Block00A0_Data.Dcm_Did05D6Buffer,
    (uint8*)&Dcm_Did_Block00A1_Data.Dcm_Did05D7Buffer,
    (uint8*)&Dcm_Did_Block00A2_Data.Dcm_Did05D8Buffer,
    (uint8*)&Dcm_Did_Block00A3_Data.Dcm_Did05D9Buffer,
    (uint8*)&Dcm_Did_Block00A4_Data.Dcm_Did05DABuffer,
    (uint8*)&Dcm_Did_Block00A5_Data.Dcm_Did05DBBuffer,
    (uint8*)&Dcm_Did_Block00A6_Data.Dcm_DidF187Buffer,
    (uint8*)&Dcm_Did_Block00A7_Data.Dcm_DidF18CBuffer,
    (uint8*)&Dcm_Did_Block00A8_Data.Dcm_DidF18ABuffer,
    (uint8*)&Dcm_Did_Block00A9_Data.Dcm_DidF191Buffer,
    (uint8*)&Dcm_Did_Block00AA_Data.Dcm_DidF189Buffer,
    (uint8*)&Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer,
    (uint8*)&Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer,
    (uint8*)&Dcm_Did_Block00AD_Data.Dcm_DidF180Buffer,
    (uint8*)&Dcm_Did_Block00AE_Data.Dcm_DidF113Buffer,
    (uint8*)&Dcm_Did_Block00AF_Data.Dcm_DidF182Buffer,
    (uint8*)&Dcm_Did_Block00B0_Data.Dcm_DidF186Buffer,
    (uint8*)&Dcm_Did_Block00B1_Data.Dcm_DidF18BBuffer,
    (uint8*)&Dcm_Did_Block00B2_Data.Dcm_Did0200Buffer,
    (uint8*)&Dcm_Did_Block00B3_Data.Dcm_Did0201Buffer,
    (uint8*)&Dcm_Did_Block00B4_Data.Dcm_DidF1A3Buffer,
    (uint8*)&Dcm_Did_Block00B5_Data.Dcm_DidF1A4Buffer,
    (uint8*)&Dcm_Did_Block00B6_Data.Dcm_DidF1A5Buffer,
    (uint8*)&Dcm_Did_Block00B7_Data.Dcm_DidF800Buffer,
    (uint8*)&Dcm_Did_Block00B8_Data.Dcm_DidF802Buffer,
    (uint8*)&Dcm_Did_Block00B9_Data.Dcm_Service0x14CountBuffer,
};



