#ifndef _CDD_SA47301_REG_H_
#define _CDD_SA47301_REG_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "Std_Types.h"
#include "Cdd_Sa47301_Cfg.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_REG             4
#define SA47301_AR_REL_MINOR_VER_REG             4
#define SA47301_AR_REL_REV_VER_REG               0
#define SA47301_SW_MAJOR_VER_REG                 1
#define SA47301_SW_MINOR_VER_REG                 0
#define SA47301_SW_PATCH_VER_REG                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_REG != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_REG"
#endif
#if (SA47301_AR_REL_MINOR_VER_REG != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_REG"
#endif
#if (SA47301_AR_REL_REV_VER_REG != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_REG"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_REG != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_REG"
#endif
#if (SA47301_SW_MINOR_VER_REG != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_REG"
#endif
#if (SA47301_SW_PATCH_VER_REG != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_REG"
#endif

/*****************************************SPI Protocol********************************************* */
#define SA_SPI_RW_BIT_SHIFT                                   0x0F
#define SA_SPI_ADDR_BIT_SHIFT                                 0x09
#define SA_SPI_DATA_BIT_SHIFT                                 0x01

/********************************************************************************************** */
#define SA_DEVCFG0_ADDR                                       0x00

#define SA_WKTIMECYC_MASK                                     0x06 
#define SA_WKTIMECYC_SHIFT                                    6 

#define SA_DEVCFG0_DEFAULT                                    0x80
#define SA_WKTIME_ENABLE                                      0x80
#define SA_WKTIMEEN_SHIFT                                       7

#define SA_WKTIME_DISABLE                                     0x00
#define SA_WKTIME_1MS                                         0x00
#define SA_WKTIME_1S                                          0x40
/********************************************************************************************** */
#define SA_DEVCFG1_ADDR                                       0x01
/********************************************************************************************** */
#define SA_DEVCFG2_ADDR                                       0x02
/********************************************************************************************** */
#define SA_PROTCFG_ADDR                                       0x03
#define SA_PROTCFG_DEFAULT                                    0x00

#define SA_KEY_MASK                                           0xFF
#define SA_KEY_SHIFT                                          0x00

#define SA_UNLOCK_KEY1_VAL                                    0xAB <<SA_KEY_SHIFT
#define SA_UNLOCK_KEY2_VAL                                    0xEF <<SA_KEY_SHIFT
#define SA_UNLOCK_KEY3_VAL                                    0x56 <<SA_KEY_SHIFT
#define SA_UNLOCK_KEY4_VAL                                    0x12 <<SA_KEY_SHIFT

#define SA_LOCK_KEY1_VAL                                      0xDF <<SA_KEY_SHIFT
#define SA_LOCK_KEY2_VAL                                      0x34 <<SA_KEY_SHIFT
#define SA_LOCK_KEY3_VAL                                      0xBE <<SA_KEY_SHIFT
#define SA_LOCK_KEY4_VAL                                      0xCA <<SA_KEY_SHIFT
/************************************************************************************************* */
#define SA_SYSPCFG0_ADDR                                      0x04 
#define SA_SYSPCFG0_DEFAULT                                   0x08 

#define SA_STBYEN_MASK                                        0x01 
#define SA_STBYEN_SHIFT                                       0x00 

#define SA_STBYEN_EN_VAL                                      0x01 <<SA_STBYEN_SHIFT       
#define SA_STBYEN_DIS_VAL                                     0x00 <<SA_STBYEN_SHIFT     
/************************************************************************************************* */

#define SA_SYSPCFG1_ADDR                                      0x05 
#define SA_SYSPCFG1_DEFAULT                                   0x08 

#define SA_ERRRECTIM_MASK                                     0x03 
#define SA_ERRRECTIM_SHIFT                                    0x00 
#define SA_ERRRECTIM_1MS                                      0x00 <<SA_ERRRECTIM_SHIFT 
#define SA_ERRRECTIM_2_5MS                                    0x01 <<SA_ERRRECTIM_SHIFT 
#define SA_ERRRECTIM_5MS                                      0x03 <<SA_ERRRECTIM_SHIFT 
#define SA_ERRRECTIM_10MS                                     0x03 <<SA_ERRRECTIM_SHIFT 

#define SA_ERRRECEN_MASK                                      0x04 
#define SA_ERRRECEN_SHIFT                                     0x02 
#define SA_ERRRECEN_EN_VAL                                    0x01U<<SA_ERRRECEN_SHIFT 
#define SA_ERRRECEN_DIS_VAL                                   0x00U<<SA_ERRRECEN_SHIFT 

#define SA_ERREN_MASK                                         0x08 
#define SA_ERREN_SHIFT                                        0x03 
#define SA_ERREN_EN_VAL                                       0x01 <<SA_ERREN_SHIFT 
#define SA_ERREN_DIS_VAL                                      0x00 <<SA_ERREN_SHIFT 

#define SA_ERRSLPEN_MASK                                      0x10 
#define SA_ERRSLPEN_SHIFT                                     0x04 
#define SA_ERRSLPEN_EN_VAL                                    0x01 <<SA_ERRSLPEN_SHIFT 
#define SA_ERRSLPEN_DIS_VAL                                   0x00 <<SA_ERRSLPEN_SHIFT 

#define SA_SSLDEL_MASK                                        0xE0 
#define SA_SSLDEL_SHIFT                                       0x05 
#define SA_SSLDEL_NODELAY_VAL                                 0x00 <<SA_SSLDEL_SHIFT 
                            
#define SA_SSLDEL_10MSDELAY_VAL                               0x01 <<SA_SSLDEL_SHIFT 
#define SA_SSLDEL_50MSDELAY_VAL                               0x02 <<SA_SSLDEL_SHIFT 
#define SA_SSLDEL_100MSDELAY_VAL                              0x03 <<SA_SSLDEL_SHIFT 
#define SA_SSLDEL_250MSDELAY_VAL                              0x04 <<SA_SSLDEL_SHIFT 
#define SA_SSLDEL_1250MSDELAY_VAL                             0x05 <<SA_SSLDEL_SHIFT 
#define SA_SSLDEL_2500MSDELAY_VAL                             0x06 <<SA_SSLDEL_SHIFT 
/************************************************************************************************* */

#define SA_WDCFG0_ADDR                                        0x06 
#define SA_WDCFG0_DEFAULT                                     0x9B 

#define SA_WDCYC_MASK                                         0x01 
#define SA_WDCYC_SHIFT                                        0x00 
#define SA_WDCYC_0_1MS_VAL                                    0x00 <<SA_WDCYC_SHIFT 
#define SA_WDCYC_1MS_VAL                                      0x01 <<SA_WDCYC_SHIFT 

#define SA_WWDTSEL_MASK                                       0x02 
#define SA_WWDTSEL_SHIFT                                      0x01 
#define SA_WWDTSEL_EXT_VAL                                    0x00 <<SA_WWDTSEL_SHIFT 
#define SA_WWDTSEL_SPI_VAL                                    0x01 <<SA_WWDTSEL_SHIFT 

#define SA_FWDEN_MASK                                         0x04 
#define SA_FWDEN_SHIFT                                        0x02 
#define SA_FWDEN_EN_VAL                                       0x01 <<SA_FWDEN_SHIFT
#define SA_FWDEN_DIS_VAL                                      0x00 <<SA_FWDEN_SHIFT

#define SA_WWDEN_MASK                                         0x08 
#define SA_WWDEN_SHIFT                                        0x03 
#define SA_WWDEN_EN_VAL                                       0x01 <<SA_WWDEN_SHIFT
#define SA_WWDEN_DIS_VAL                                      0x00 <<SA_WWDEN_SHIFT

#define SA_WWDETHR_MASK                                       0xF0 
#define SA_WWDETHR_SHIFT                                      0x04 
#define SA_WWDETHR_VAL(X)                                     (X<<SA_WWDEN_SHIFT)
/************************************************************************************************* */
#define SA_WDCFG1_ADDR                                        0x07 
/************************************************************************************************* */
#define SA_FWDCFG_ADDR                                        0x08 
/************************************************************************************************* */
#define SA_WWDCFG0_ADDR                                       0x09 
#define SA_WWDCFG0_DEFAULT                                    0x08 

#define SA_CW_MASK                                            0x1F 
#define SA_CW_SHIFT                                           0x00   
#define SA_CW_50MS_VAL                                        0x00 << SA_CW_SHIFT //EVPT used                                 
/************************************************************************************************* */
#define SA_WWDCFG1_ADDR                                       0x0A
#define SA_WWDCFG1_DEFAULT                                    0x08

#define SA_OW_MASK                                            0x1F
#define SA_OW_SHIFT                                           0x00  
#define SA_OW_50MS_VAL                                        0x00<<SA_OW_SHIFT //EVPT used  
/************************************************************************************************* */
#define SA_WKTIMCFG0_ADDR                                     0x12
#define SA_WKTIMCFG1_ADDR                                     0x13
#define SA_WKTIMCFG2_ADDR                                     0x14
/************************************************************************************************* */
#define SA_DEVCTL_ADDR                                        0x15
#define SA_DEVCTL_DEFAULT                                     0x10

#define SA_STATEREQ_MASK                                      0x07
#define SA_STATEREQ_SHIFT                                     0x00 
#define SA_STATEREQ_NONE_VAL                                  0x00<<SA_STATEREQ_SHIFT
#define SA_STATEREQ_INIT_VAL                                  0x01<<SA_STATEREQ_SHIFT
#define SA_STATEREQ_NORMAL_VAL                                0x02<<SA_STATEREQ_SHIFT
#define SA_STATEREQ_SLEEP_VAL                                 0x03<<SA_STATEREQ_SHIFT
#define SA_STATEREQ_STANDBY_VAL                               0x04<<SA_STATEREQ_SHIFT
#define SA_STATEREQ_WAKE_VAL                                  0x05<<SA_STATEREQ_SHIFT

#define SA_VREF_MASK                                          0x08 
#define SA_VREF_SHIFT                                         0x03  
#define SA_VREF_EN_VAL                                        0x01<<SA_VREF_SHIFT 
#define SA_VREF_DIS_VAL                                       0x00<<SA_VREF_SHIFT 

#define SA_VCOM_MASK                                          0x20 
#define SA_VCOM_SHIFT                                         0x05  
#define SA_VCOM_EN_VAL                                        0x01<<SA_VCOM_SHIFT 
#define SA_VCOM_DIS_VAL                                       0x00<<SA_VCOM_SHIFT 

#define SA_VTRK1_MASK                                         0x40 
#define SA_VTRK1_SHIFT                                        0x06  
#define SA_VTRK1_EN_VAL                                       0x01<<SA_VTRK1_SHIFT 
#define SA_VTRK1_DIS_VAL                                      0x00<<SA_VTRK1_SHIFT 

#define SA_VTRK2_MASK                                         0x80 
#define SA_VTRK2_SHIFT                                        0x07  
#define SA_VTRK2_EN_VAL                                       0x01<<SA_VTRK2_SHIFT 
#define SA_VTRK2_DIS_VAL                                      0x00<<SA_VTRK2_SHIFT 
/************************************************************************************************* */
#define SA_DEVCTRLN_ADDR                                      0x16 
#define SA_DEVCTRLN_DEFAULT                                   0x00 
/************************************************************************************************* */
#define SA_WWDSCMD_ADDR                                       0x17 
#define SA_WWDSCMD_DEFAULT                                    0x08 

#define SA_TRIG_MASK                                          0x01 
#define SA_TRIG_SHIFT                                         0x00 

#define SA_TRIGSTATUS_MASK                                    0x80 
/************************************************************************************************* */
#define SA_FWDRSP_ADDR                                        0x18
#define SA_FWDRSPSYNC_ADDR                                    0x19
/***************************************************************** **************************** */
#define SA_SYSFAIL_ADDR                                       0x1A
#define SA_SYSFAIL_DEFAULT                                    0x00

#define SA_VOLSELER_MASK                                        0x01 
#define SA_VOLSELER_SHIFT                                       0x00 
#define SA_VOLSELER_NOACT_VAL                                   0 << SA_VOLSELER_SHIFT 
#define SA_VOLSELER_DETECT_VAL                                  1 << SA_VOLSELER_SHIFT 

#define SA_OTF_MASK                                           0x02 
#define SA_OTF_SHIFT                                          0x01 
#define SA_OTF_NOACT_VAL                                      0 << SA_OTF_SHIFT 
#define SA_OTF_DETECT_VAL                                     1 << SA_OTF_SHIFT 

#define SA_VMONF_MASK                                         0x04 
#define SA_VMONF_SHIFT                                        0x02 
#define SA_VMONF_NOACT_VAL                                    0 << SA_VMONF_SHIFT 
#define SA_VMONF_DETECT_VAL                                   1 << SA_VMONF_SHIFT 

#define SA_ABISTERR_MASK                                      0x40 
#define SA_ABISTERR_SHIFT                                     0x06 
#define SA_ABISTERR_NOACT_VAL                                 0 << SA_ABISTERR_SHIFT 
#define SA_ABISTERR_DETECT_VAL                                1 << SA_ABISTERR_SHIFT 

#define SA_INITF_MASK                                         0x80 
#define SA_INITF_SHIFT                                        0x07 
#define SA_INITF_NOACT_VAL                                    0 << SA_INITF_SHIFT 
#define SA_INITF_DETECT_VAL                                   1 << SA_INITF_SHIFT 

/***************************************************************** **************************** */
#define SA_WKSF_ADDR                                          0x1E 
#define SA_WKSF_DEFAULT                                       0x08 

#define SA_WAKE_MASK                                          0x01 
#define SA_WAKE_SHIFT                                         0x00 
#define SA_WAKE_NOACT_VAL                                     0x00 << SA_WAKE_SHIFT                                        
#define SA_WAKE_DETECT_VAL                                    0x01 << SA_WAKE_SHIFT   

#define SA_EN_MASK                                            0x02 
#define SA_EN_SHIFT                                           0x01 
#define SA_EN_NOACT_VAL                                       0x00 << SA_EN_SHIFT                                        
#define SA_EN_DETECT_VAL                                      0x01 << SA_EN_SHIFT  

#define SA_CMON_MASK                                          0x04 
#define SA_CMON_SHIFT                                         0x02 
#define SA_CMON_NOACT_VAL                                     0x00 << SA_CMON_SHIFT                                       
#define SA_CMON_DETECT_VAL                                    0x01 << SA_CMON_SHIFT 

#define SA_WKTIM_MASK                                         0x08 
#define SA_WKTIM_SHIFT                                        0x03 
#define SA_WKTIM_NOACT_VAL                                    0x00 << SA_WKTIM_SHIFT                                        
#define SA_WKTIM_DETECT_VAL                                   0x01 << SA_WKTIM_SHIFT  

#define SA_WKSPI_MASK                                         0x10 
#define SA_WKSPI_SHIFT                                        0x04 
#define SA_WKSPI_NOACT_VAL                                    0x00 << SA_WKSPI_SHIFT                                        
#define SA_WKSPI_DETECT_VAL                                   0x01 << SA_WKSPI_SHIFT  

#define SA_ENST_MASK                                          0x40 
#define SA_ENST_SHIFT                                         0x06 
#define SA_ENST_LOW_VAL                                       0x00 << SA_WKSPI_SHIFT                                        
#define SA_ENST_HIGH_VAL                                      0x01 << SA_WKSPI_SHIFT  

#define SA_WAKST_MASK                                         0x80 
#define SA_WAKST_SHIFT                                        0x07 
#define SA_WAKST_LOW_VAL                                      0x00 << SA_WKSPI_SHIFT                                        
#define SA_WAKST_HIGH_VAL                                     0x01 << SA_WKSPI_SHIFT  

/************************************************************************************************* */

#define SA_SPISF_ADDR                                         0x1F 
#define SA_SPISF_DEFAULT                                      0x08 

#define SA_PARE_MASK                                          0x01 
#define SA_PARE_SHIFT                                         0x00 
#define SA_PARE_NOACT_VAL                                     0x00 << SA_PARE_SHIFT                                        
#define SA_PARE_DETECT_VAL                                    0x01 << SA_PARE_SHIFT   

#define SA_LENE_MASK                                          0x02 
#define SA_LENE_SHIFT                                         0x01 
#define SA_LENE_NOACT_VAL                                     0x00 << SA_LENE_SHIFT                                        
#define SA_LENE_DETECT_VAL                                    0x01 << SA_LENE_SHIFT  

#define SA_ADDRE_MASK                                         0x04 
#define SA_ADDRE_SHIFT                                        0x02 
#define SA_ADDRE_NOACT_VAL                                    0x00 <<SA_ADDRE_SHIFT 
#define SA_ADDRE_DETECT_VAL                                   0x01 <<SA_ADDRE_SHIFT 

#define SA_DURE_MASK                                          0x08 
#define SA_DURE_SHIFT                                         0x03 
#define SA_DURE_NOACT_VAL                                     0x00 << SA_DURE_SHIFT                                        
#define SA_DURE_DETECT_VAL                                    0x01 << SA_DURE_SHIFT  

#define SA_LOCKERROR_MASK                                     0x10
#define SA_LOCKERROR_SHIFT                                    0x04
#define SA_LOCKERROR_NOACT_VAL                                0x00 << SA_LOCK_SHIFT
#define SA_LOCKERROR_DETECT_VAL                               0x01 << SA_LOCK_SHIFT
/************************************************************************************************* */
#define SA_MONSF0_ADDR                                        0x20 
#define SA_MONSF0_DEFAULT                                     0x00 

#define SA_PREGSG_MASK                                        0x01 
#define SA_PREGSG_SHIFT                                       0x00 
#define SA_PREGSG_NOACT_VAL                                   0 << SA_PREGSG_SHIFT 
#define SA_PREGSG_DETECT_VAL                                  1 << SA_PREGSG_SHIFT 

#define SA_UCSG_MASK                                          0x02 
#define SA_UCSG_SHIFT                                         0x01 
#define SA_UCSG_NOACT_VAL                                     0 << SA_UCSG_SHIFT 
#define SA_UCSG_DETECT_VAL                                    1 << SA_UCSG_SHIFT 

#define SA_STBYSG_MASK                                        0x04 
#define SA_STBYSG_SHIFT                                       0x02 
#define SA_STBYSG_NOACT_VAL                                   0 << SA_PREGSG_SHIFT 
#define SA_STBYSG_DETECT_VAL                                  1 << SA_PREGSG_SHIFT 

#define SA_VMONSG_MASK                                        0x08 
#define SA_VMONSG_SHIFT                                       0x03 
#define SA_VMONSG_NOACT_VAL                                   0 << SA_VMONSG_SHIFT 
#define SA_VMONSG_DETECT_VAL                                  1 << SA_VMONSG_SHIFT 

#define SA_COMSG_MASK                                         0x10 
#define SA_COMSG_SHIFT                                        0x04 
#define SA_COMSG_NOACT_VAL                                    0 << SA_COMSG_SHIFT 
#define SA_COMSG_DETECT_VAL                                   1 << SA_COMSG_SHIFT 

#define SA_VREFSG_MASK                                        0x20 
#define SA_VREFSG_SHIFT                                       0x05 
#define SA_VREFSG_NOACT_VAL                                   0 << SA_VREFSG_SHIFT 
#define SA_VREFSG_DETECT_VAL                                  1 << SA_VREFSG_SHIFT 

#define SA_TRK1SG_MASK                                        0x40 
#define SA_TRK1SG_SHIFT                                       0x06 
#define SA_TRK1SG_NOACT_VAL                                   0 << SA_TRK1SG_SHIFT 
#define SA_TRK1SG_DETECT_VAL                                  1 << SA_TRK1SG_SHIFT 

#define SA_TRK2SG_MASK                                        0x80 
#define SA_TRK2SG_SHIFT                                       0x07 
#define SA_TRK2SG_NOACT_VAL                                   0 << SA_TRK2SG_SHIFT 
#define SA_TRK2SG_DETECT_VAL                                  1 << SA_TRK2SG_SHIFT 
/************************************************************************************************* */

#define SA_MONSF1_ADDR                                        0x21 
#define SA_MONSF1_DEFAULT                                     0x08 

#define SA_PREGOV_MASK                                        0x01 
#define SA_PREGOV_SHIFT                                       0x00 
#define SA_PREGOV_NOACT_VAL                                   0 << SA_PREGOV_SHIFT 
#define SA_PREGOV_DETECT_VAL                                  1 << SA_PREGOV_SHIFT 

#define SA_UCOV_MASK                                          0x02 
#define SA_UCOV_SHIFT                                         0x01 
#define SA_UCOV_NOACT_VAL                                     0 << SA_UCOV_SHIFT 
#define SA_UCOV_DETECT_VAL                                    1 << SA_UCOV_SHIFT 

#define SA_STBYOV_MASK                                        0x04 
#define SA_STBYOV_SHIFT                                       0x02 
#define SA_STBYOV_NOACT_VAL                                   0 << SA_STBYOV_SHIFT 
#define SA_STBYOV_DETECT_VAL                                  1 << SA_STBYOV_SHIFT 

#define SA_VMONOV_MASK                                        0x08 
#define SA_VMONOV_SHIFT                                       0x03 
#define SA_VMONOV_NOACT_VAL                                   0 << SA_VMONOV_SHIFT 
#define SA_VMONOV_DETECT_VAL                                  1 << SA_VMONOV_SHIFT 

#define SA_COMOV_MASK                                         0x10 
#define SA_COMOV_SHIFT                                        0x04 
#define SA_COMOV_NOACT_VAL                                    0 << SA_COMOV_SHIFT 
#define SA_COMOV_DETECT_VAL                                   1 << SA_COMOV_SHIFT 

#define SA_VREFOV_MASK                                        0x20 
#define SA_VREFOV_SHIFT                                       0x05 
#define SA_VREFOV_NOACT_VAL                                   0 << SA_VREFOV_SHIFT 
#define SA_VREFOV_DETECT_VAL                                  1 << SA_VREFOV_SHIFT 

#define SA_TRK1OV_MASK                                        0x40 
#define SA_TRK1OV_SHIFT                                       0x06 
#define SA_TRK1OV_NOACT_VAL                                   0 << SA_TRK1OV_SHIFT 
#define SA_TRK1OV_DETECT_VAL                                  1 << SA_TRK1OV_SHIFT 

#define SA_TRK2OV_MASK                                        0x80 
#define SA_TRK2OV_SHIFT                                       0x07 
#define SA_TRK2OV_NOACT_VAL                                   0 << SA_TRK2OV_SHIFT 
#define SA_TRK2OV_DETECT_VAL                                  1 << SA_TRK2OV_SHIFT 
/************************************************************************************************* */
#define SA_MONSF2_ADDR                                        0x22 
#define SA_MONSF2_DEFAULT                                     0x00 

#define SA_PREGUV_MASK                                        0x01 
#define SA_PREGUV_SHIFT                                       0x00 
#define SA_PREGUV_NOACT_VAL                                   0 << SA_PREGUV_SHIFT 
#define SA_PREGUV_DETECT_VAL                                  1 << SA_PREGUV_SHIFT 

#define SA_UCUV_MASK                                          0x02 
#define SA_UCUV_SHIFT                                         0x01 
#define SA_UCUV_NOACT_VAL                                     0 << SA_UCUV_SHIFT 
#define SA_UCUV_DETECT_VAL                                    1 << SA_UCUV_SHIFT 

#define SA_STBYUV_MASK                                        0x04 
#define SA_STBYUV_SHIFT                                       0x02 
#define SA_STBYUV_NOACT_VAL                                   0 << SA_STBYUV_SHIFT 
#define SA_STBYUV_DETECT_VAL                                  1 << SA_STBYUV_SHIFT 

#define SA_VMONUV_MASK                                        0x08 
#define SA_VMONUV_SHIFT                                       0x03 
#define SA_VMONUV_NOACT_VAL                                   0 << SA_VMONUV_SHIFT 
#define SA_VMONUV_DETECT_VAL                                  1 << SA_VMONUV_SHIFT 

#define SA_COMUV_MASK                                         0x10 
#define SA_COMUV_SHIFT                                        0x04 
#define SA_COMUV_NOACT_VAL                                    0 << SA_COMUV_SHIFT  
#define SA_COMUV_DETECT_VAL                                   1 << SA_COMUV_SHIFT  

#define SA_VREFUV_MASK                                        0x20 
#define SA_VREFUV_SHIFT                                       0x05 
#define SA_VREFUV_NOACT_VAL                                   0 << SA_VREFUV_SHIFT 
#define SA_VREFUV_DETECT_VAL                                  1 << SA_VREFUV_SHIFT 

#define SA_TRK1UV_MASK                                        0x40 
#define SA_TRK1UV_SHIFT                                       0x06 
#define SA_TRK1UV_NOACT_VAL                                   0 << SA_TRK1UV_SHIFT 
#define SA_TRK1UV_DETECT_VAL                                  1 << SA_TRK1UV_SHIFT 

#define SA_TRK2UV_MASK                                        0x80 
#define SA_TRK2UV_SHIFT                                       0x07 
#define SA_TRK2UV_NOACT_VAL                                   0 << SA_TRK2UV_SHIFT 
#define SA_TRK2UV_DETECT_VAL                                  1 << SA_TRK2UV_SHIFT 
/************************************************************************************************* */
#define SA_MONSF3_ADDR                                        0x23
#define SA_MONSF3_DEFAULT                                     0x00

#define SA_VBATOV_MASK                                        0x01
#define SA_VBATOV_SHIFT                                       0x00
#define SA_VBATOV_NOACT_VAL                                   0 << SA_VBATOV_SHIFT 
#define SA_VBATOV_DETECT_VAL                                  1 << SA_VBATOV_SHIFT 

#define SA_BG12UV_MASK                                        0x10 
#define SA_BG12UV_SHIFT                                       0x04 
#define SA_BG12UV_NOACT_VAL                                   0 << SA_BG12UV_SHIFT 
#define SA_BG12UV_DETECT_VAL                                  1 << SA_BG12UV_SHIFT 

#define SA_BG12OV_MASK                                        0x20 
#define SA_BG12OV_SHIFT                                       0x05 
#define SA_BG12OV_NOACT_VAL                                   0 << SA_BG12OV_SHIFT 
#define SA_BG12OV_DETECT_VAL                                  1 << SA_BG12OV_SHIFT 

#define SA_BIASLOW_MASK                                       0x40 
#define SA_BIASLOW_SHIFT                                      0x06 
#define SA_BIASLOW_NOACT_VAL                                  0 << SA_BIASLOW_SHIFT 
#define SA_BIASLOW_DETECT_VAL                                 1 << SA_BIASLOW_SHIFT 

#define SA_BIASHI_MASK                                        0x80 
#define SA_BIASHI_SHIFT                                       0x07 
#define SA_BIASHI_NOACT_VAL                                   0 << SA_BIASHI_SHIFT 
#define SA_BIASHI_DETECT_VAL                                  1 << SA_BIASHI_SHIFT 
/************************************************************************************************* */

#define SA_OTFAIL_ADDR                                        0x24 
#define SA_OTFAIL_DEFAULT                                     0x00 

#define SA_PREGOT_MASK                                        0x01 
#define SA_PREGOT_SHIFT                                       0x00 
#define SA_PREGOT_NOACT_VAL                                   0 << SA_PREGOT_SHIFT 
#define SA_PREGOT_DETECT_VAL                                  1 << SA_PREGOT_SHIFT 

#define SA_UCOT_MASK                                          0x02 
#define SA_UCOT_SHIFT                                         0x01 
#define SA_UCOT_NOACT_VAL                                     0 << SA_UCOT_SHIFT 
#define SA_UCOT_DETECT_VAL                                    1 << SA_UCOT_SHIFT 

#define SA_COMGOT_MASK                                        0x10 
#define SA_COMGOT_SHIFT                                       0x04 
#define SA_COMGOT_NOACT_VAL                                   0 << SA_PREGOT_SHIFT 
#define SA_COMGOT_DETECT_VAL                                  1 << SA_PREGOT_SHIFT 

#define SA_MONOT_MASK                                         0x80 
#define SA_MONOT_SHIFT                                        0x07 
#define SA_MONOT_NOACT_VAL                                    0 << SA_UCOT_SHIFT 
#define SA_MONOT_DETECT_VAL                                   1 << SA_UCOT_SHIFT 
/************************************************************************************************* */
#define SA_DEVSTAT_ADDR                                       0x27 
#define SA_DEVSTAT_DEFAULT                                    0x00 

#define SA_STATE_MASK                                         0x07 
#define SA_STATE_SHIFT                                        0x00 
#define SA_STATE_NONE_VAL                                     0 << SA_STATE_SHIFT 
#define SA_STATE_INIT_VAL                                     1 << SA_STATE_SHIFT 
#define SA_STATE_NORMAL_VAL                                   2 << SA_STATE_SHIFT 
#define SA_STATE_SLEEP_VAL                                    3 << SA_STATE_SHIFT 
#define SA_STATE_STNDBY_VAL                                   4 << SA_STATE_SHIFT 
#define SA_STATE_WAKE_VAL                                     5 << SA_STATE_SHIFT 

#define SA_RVREF_MASK                                         0x08 
#define SA_RVREF_SHIFT                                        0x03 
#define SA_RVREF_EN_VAL                                       1 << SA_VREF_SHIFT  
#define SA_RVREF_DIS_VAL                                      0 << SA_VREF_SHIFT  

#define SA_RVSTBY_MASK                                        0x10 
#define SA_RVSTBY_SHIFT                                       0x04 
#define SA_RVSTBY_EN_VAL                                      1 << SA_VSTBY_SHIFT 
#define SA_RVSTBY_DIS_VAL                                     0 << SA_VSTBY_SHIFT 

#define SA_RVCOM_MASK                                         0x20 
#define SA_RVCOM_SHIFT                                        0x05 
#define SA_RVCOM_EN_VAL                                       1 << SA_VCOM_SHIFT 
#define SA_RVCOM_DIS_VAL                                      0 << SA_VCOM_SHIFT 

#define SA_RVTRK1_MASK                                        0x40 
#define SA_RVTRK1_SHIFT                                       0x06 
#define SA_RVTRK1_EN_VAL                                      1 << SA_VTRK1_SHIFT 
#define SA_RVTRK1_DIS_VAL                                     0 << SA_VTRK1_SHIFT 

#define SA_RVTRK2_MASK                                        0x80 
#define SA_RVTRK2_SHIFT                                       0x07 
#define SA_RVTRK2_EN_VAL                                      1 << SA_VTRK2_SHIFT 
#define SA_RVTRK2_DIS_VAL                                     0 << SA_VTRK2_SHIFT 
/************************************************************************************************* */
#define SA_PROTSTAT_ADDR                                      0x28
#define SA_PROTSTAT_DEFAULT                                   0x01


#define SA_LOCK_STATUS_MASK                                   0x01
#define SA_LOCK_STATUS_SHIFT                                  0x00
#define SA_LOCKED_STATUS                                      1
#define SA_UNLOCK_STATUS                                      0
/************************************************************************************************* */
#define SA_WWDSTAT_ADDR                                       0x29 
#define SA_WWDSTAT_DEFAULT                                    0x00 

#define SA_WWDECNT_MASK                                       0x0F 
#define SA_WWDECNT_SHIFT                                      0x00 
/************************************************************************************************* */
#define SA_FWDRSPOK_ADDR                                       0x2A
#define SA_FWDSTAT1_ADDR                                       0x2B
/************************************************************************************************* */
#define SA_ABIST_CTRL0_ADDR                                   0x2C 
#define SA_ABIST_CTRL0_STATUS_MASK                            0xF0
#define SA_ABIST_CTRL0_STATUS_SHIFT                           0x04
#define SA_ABIST_CTRL0_STATUS_PASS                            0x50
#define SA_ABIST_CTRL0_STATUS_FAIL                            0xA0

#define SA_ABIST_CTRL0_INT_MASK                               0x08
#define SA_ABIST_CTRL0_INT_SHIFT                              0x03

#define SA_ABIST_CTRL0_SINGLE_MAKE                            0x04
#define SA_ABIST_CTRL0_SINGLE_SHIFT                           0x02

#define SA_ABIST_CTRL0_PATH_MASK                              0x02
#define SA_ABIST_CTRL0_PATH_SHIFT                             0x01

#define SA_ABIST_CTRL0_START_MASK                             0x01
#define SA_ABIST_CTRL0_START_SHIFT                            0x00
/************************************************************************************************* */
#define SA_ABIST_CTRL1_ADDR                                   0x2D

#define SA_ABIST_CTRL_CLKEN_MASK                              0x02
#define SA_ABIST_CTRL_CLKEN_SHIFT                             0x01

#define SA_ABIST_CTRL_OV_TRIG_MASK                             0x01
#define SA_ABIST_CTRL_OV_TRIG_SHIFT                            0x00
/************************************************************************************************* */
#define SA_ABIST_SELECT0_ADDR                                 0x2E

#define SA_ABIST_SELECT0_TRK2OV_MASK                          0x80
#define SA_ABIST_SELECT0_TRK2OV_SHIFT                         0x07
#define SA_ABIST_SELECT0_TRK2OV_VAL                           1 << SA_ABIST_SELECT0_TRK2OV_SHIFT

#define SA_ABIST_SELECT0_TRK1OV_MASK                          0x40
#define SA_ABIST_SELECT0_TRK1OV_SHIFT                         0x06
#define SA_ABIST_SELECT0_TRK1OV_VAL                           1 << SA_ABIST_SELECT0_TRK1OV_SHIFT 

#define SA_ABIST_SELECT0_VREFOV_MASK                          0x20
#define SA_ABIST_SELECT0_VREFOV_SHIFT                         0x05
#define SA_ABIST_SELECT0_VREFOV_VAL                           1 << SA_ABIST_SELECT0_VREFOV_SHIFT 

#define SA_ABIST_SELECT0_COMOV_MASK                           0x10
#define SA_ABIST_SELECT0_COMOV_SHIFT                          0x04
#define SA_ABIST_SELECT0_COMOV_VAL                            1 << SA_ABIST_SELECT0_COMOV_SHIFT 

#define SA_ABIST_SELECT0_VMONOV_MASK                          0x08
#define SA_ABIST_SELECT0_VMONOV_SHIFT                         0x03
#define SA_ABIST_SELECT0_VMONOV_VAL                           1 << SA_ABIST_SELECT0_VMONOV_SHIFT

#define SA_ABIST_SELECT0_STBYOV_MASK                          0x04
#define SA_ABIST_SELECT0_STBYOV_SHIFT                         0x02
#define SA_ABIST_SELECT0_STBYOV_VAL                           1 << SA_ABIST_SELECT0_STBYOV_SHIFT

#define SA_ABIST_SELECT0_UCOV_MASK                            0x02
#define SA_ABIST_SELECT0_UCOV_SHIFT                           0x01
#define SA_ABIST_SELECT0_UCOV_VAL                             1 << SA_ABIST_SELECT0_UCOV_SHIFT

#define SA_ABIST_SELECT0_PREGOV_MASK                          0x01
#define SA_ABIST_SELECT0_PREGOV_SHIFT                         0x00
#define SA_ABIST_SELECT0_PREGOV_VAL                           1 << SA_ABIST_SELECT0_PREGOV_SHIFT
/************************************************************************************************* */
#define SA_ABIST_SELECT1_ADDR                                 0x2F

#define SA_ABIST_SELECT1_TRK2UV_MASK                          0x80
#define SA_ABIST_SELECT1_TRK2UV_SHIFT                         0x07
#define SA_ABIST_SELECT1_TRK2UV_VAL                           1 << SA_ABIST_SELECT1_TRK2UV_SHIFT

#define SA_ABIST_SELECT1_TRK1UV_MASK                          0x40
#define SA_ABIST_SELECT1_TRK1UV_SHIFT                         0x06
#define SA_ABIST_SELECT1_TRK1UV_VAL                           1 << SA_ABIST_SELECT1_TRK1UV_SHIFT 

#define SA_ABIST_SELECT1_VREFUV_MASK                          0x20
#define SA_ABIST_SELECT1_VREFUV_SHIFT                         0x05
#define SA_ABIST_SELECT1_VREFUV_VAL                           1 << SA_ABIST_SELECT1_VREFUV_SHIFT 

#define SA_ABIST_SELECT1_COMUV_MASK                           0x10
#define SA_ABIST_SELECT1_COMUV_SHIFT                          0x04
#define SA_ABIST_SELECT1_COMUV_VAL                            1 << SA_ABIST_SELECT1_COMUV_SHIFT 

#define SA_ABIST_SELECT1_VMONUV_MASK                          0x08
#define SA_ABIST_SELECT1_VMONUV_SHIFT                         0x03
#define SA_ABIST_SELECT1_VMONUV_VAL                           1 << SA_ABIST_SELECT1_VMONUV_SHIFT

#define SA_ABIST_SELECT1_STBYUV_MASK                          0x04
#define SA_ABIST_SELECT1_STBYUV_SHIFT                         0x02
#define SA_ABIST_SELECT1_STBYUV_VAL                           1 << SA_ABIST_SELECT1_STBYUV_SHIFT

#define SA_ABIST_SELECT1_UCUV_MASK                            0x02
#define SA_ABIST_SELECT1_UCUV_SHIFT                           0x01
#define SA_ABIST_SELECT1_UCUV_VAL                             1 << SA_ABIST_SELECT1_UCUV_SHIFT

#define SA_ABIST_SELECT1_PREGUV_MASK                          0x01
#define SA_ABIST_SELECT1_PREGUV_SHIFT                         0x00
#define SA_ABIST_SELECT1_PREGUV_VAL                           1 << SA_ABIST_SELECT1_PREGUV_SHIFT
/************************************************************************************************* */
#define SA_ABIST_SELECT2_ADDR                                 0x30

#define SA_ABIST_SELECT1_BIASHI_MASK                          0x80
#define SA_ABIST_SELECT1_BIASHI_SHIFT                         0x07
#define SA_ABIST_SELECT1_BIASHI_VAL                           1 << SA_ABIST_SELECT1_BIASHI_SHIFT

#define SA_ABIST_SELECT1_BIASLOW_MASK                          0x40
#define SA_ABIST_SELECT1_BIASLOW_SHIFT                         0x06
#define SA_ABIST_SELECT1_BIASLOW_VAL                           1 << SA_ABIST_SELECT1_BIASLOW_SHIFT 

#define SA_ABIST_SELECT1_BG12OV_MASK                           0x20
#define SA_ABIST_SELECT1_BG12OV_SHIFT                          0x05
#define SA_ABIST_SELECT1_BG12OV_VAL                            1 << SA_ABIST_SELECT1_BG12OV_SHIFT 

#define SA_ABIST_SELECT1_BG12UV_MASK                           0x10
#define SA_ABIST_SELECT1_BG12UV_SHIFT                          0x04
#define SA_ABIST_SELECT1_BG12UV_VAL                            1 << SA_ABIST_SELECT1_BG12UV_SHIFT 

#define SA_ABIST_SELECT1_INTOV_MASK                           0x08
#define SA_ABIST_SELECT1_INTOV_SHIFT                          0x03
#define SA_ABIST_SELECT1_INTOV_VAL                            1 << SA_ABIST_SELECT1_INTOV_SHIFT

#define SA_ABIST_SELECT1_VBATOV_MASK                          0x01
#define SA_ABIST_SELECT1_VBATOV_SHIFT                         0x00
#define SA_ABIST_SELECT1_VBATOV_VAL                           1 << SA_ABIST_SELECT1_VBATOV_SHIFT
/************************************************************************************************* */
#define SA_BCK_FRE_CHANGE_ADDR                                0x31
/************************************************************************************************* */
#define SA_BCK_FRE_SPREAD_ADDR                                0x32 
#define SA_BCK_FRE_SPREAD_DEFAULT                             0x00 

#define SA_FRE_SP_THR_MASK                                    0xFF 
#define SA_FRE_SP_THR_SHIFT                                   0x00 
#define SA_FRE_SP_THR_NO_VAL                                  0x00<<SA_FRE_SP_THR_SHIFT  
#define SA_FRE_SP_THR_6PER_VAL                                0xFF<<SA_FRE_SP_THR_SHIFT  

#define SA_BCK_MAIN_CTRL_ADDR                                 0x33 
#define SA_BCK_MAIN_CTRL_DEFAULT                              0x00 

#define SA_DATA_VALID_MASK                                    0x40 
#define SA_DATA_VALID_SHIFT                                   0x06 
#define SA_DATA_VALID_NOACT_VAL                               0x00<<SA_DATA_VALID_SHIFT  
#define SA_DATA_VALID_LOAD_VAL                                0x01<<SA_DATA_VALID_SHIFT  
/************************************************************************************************** */
#define SA_FCR_ADDR                                           0x36
#define SA_MCUSUP_ADDR                                        0x3C

/************************************************************************************************** */

// 基础设备配置类（0-2为你已定义）
#define SA_REG_DEVCFG0_TAG                                    (0x00)
#define SA_REG_DEVCFG1_TAG                                    (0x01)
#define SA_REG_DEVCFG2_TAG                                    (0x02)
#define SA_REG_PROTCFG_TAG                                    (0x03)
#define SA_REG_SYSPCFG0_TAG                                   (0x04)
#define SA_REG_SYSPCFG1_TAG                                   (0x05)

// 看门狗配置请求类
#define SA_REG_WDCFG0_TAG                                     (0x06)
#define SA_REG_WDCFG1_TAG                                     (0x07)
#define SA_REG_FWDCFG_TAG                                     (0x08)
#define SA_REG_WWDCFG0_TAG                                    (0x09)
#define SA_REG_WWDCFG1_TAG                                    (0x0A)

// 系统/看门狗状态类
#define SA_REG_RSYSCFG0_TAG                                   (0x0B)
#define SA_REG_RSYSCFG1_TAG                                   (0x0C)
#define SA_REG_RWDCFG0_TAG                                    (0x0D)
#define SA_REG_RWDCFG1_TAG                                    (0x0E)
#define SA_REG_RFWDCFG_TAG                                    (0x0F)
#define SA_REG_RWWDCFG0_TAG                                   (0x10)
#define SA_REG_RWWDCFG1_TAG                                   (0x11)

// 唤醒定时器配置类
#define SA_REG_WKTIMCFG0_TAG                                  (0x12)
#define SA_REG_WKTIMCFG1_TAG                                  (0x13)
#define SA_REG_WKTIMCFG2_TAG                                  (0x14)

// 设备控制类
#define SA_REG_DEVCTRL_TAG                                    (0x15)
#define SA_REG_DEVCTRLN_TAG                                   (0x16)

// 看门狗命令类
#define SA_REG_WDSVCMMD_TAG                                   (0x17)
#define SA_REG_FWDRSP_TAG                                     (0x18)
#define SA_REG_FWDRSPSYNC_TAG                                 (0x19)

// 故障/错误状态类
#define SA_REG_SYSFAIL_TAG                                    (0x1A)
#define SA_REG_INITERROR_TAG                                  (0x1B)
#define SA_REG_INTERRUPTFLAGS_TAG                             (0x1C)
#define SA_REG_SYSFLG_TAG                                     (0x1D)

// 唤醒/通信状态类
#define SA_REG_WKS_TAG                                        (0x1E)
#define SA_REG_SPISTATUS_TAG                                  (0x1F)

// 监控状态类（过压/欠压/短路等）
#define SA_REG_MONST0_TAG                                     (0x20)
#define SA_REG_MONST1_TAG                                     (0x21)
#define SA_REG_MONST2_TAG                                     (0x22)
#define SA_REG_MONST3_TAG                                     (0x23)

// 过温保护类
#define SA_REG_OTFAIL_TAG                                     (0x24)
#define SA_REG_OTWRNSF_TAG                                    (0x25)

// 电压/设备状态类
#define SA_REG_VMONSTAT_TAG                                   (0x26)
#define SA_REG_DEVSTAT_TAG                                    (0x27)
#define SA_REG_PROTSTAT_TAG                                   (0x28)

// 看门狗状态补充类
#define SA_REG_WWDSTAT_TAG                                    (0x29)
#define SA_REG_FWDRSPOK_TAG                                   (0x2A)
#define SA_REG_FWDSTAT1_TAG                                   (0x2B)

// ABIST自检配置类
#define SA_REG_ABIST_CTRL0_TAG                                (0x2C)
#define SA_REG_ABIST_CTRL1_TAG                                (0x2D)
#define SA_REG_ABIST_SELECT0_TAG                              (0x2E)
#define SA_REG_ABIST_SELECT1_TAG                              (0x2F)
#define SA_REG_ABIST_SELECT2_TAG                              (0x30)

// Buck电源模块配置类
#define SA_REG_BCK_FREQ_CHANGE_TAG                            (0x31)
#define SA_REG_BCK_FREQ_SPREAD_TAG                            (0x32)
#define SA_REG_BCK_MAIN_CTRL_TAG                              (0x33)
#define SA_REG_RESERVED_1_TAG                                 (0x34)
#define SA_REG_RESERVED_2_TAG                                 (0x35)

// 测试/功能控制类
#define SA_REG_FCR_TAG                                        (0x36)
#define SA_REG_RESERVED_3_TAG                                 (0x37)
#define SA_REG_RESERVED_4_TAG                                 (0x38)
#define SA_REG_RESERVED_5_TAG                                 (0x39)
#define SA_REG_RESERVED_6_TAG                                 (0x3A)
#define SA_REG_RESERVED_7_TAG                                 (0x3B)
#define SA_REG_MCUSUP_TAG                                     (0x3C)
#define SA_REG_RESERVED_8_TAG                                 (0x3D)
#define SA_REG_RESERVED_9_TAG                                 (0x3E)
#define SA_REG_GTM_TAG                                        (0x3F)

#define SA_REG_NUM_MAX                                        (0x40)  
/************************************************************************************************** */

typedef union Cdd_Sa47301_Reg
{
    uint8 Data;

    struct 
    {
        uint8 WKTIMKN:      1;
        uint8 WKTIMCYC:     1;
        uint8 Reserved:     2;
        uint8 TRDEL:        4;
    }Reg_DEVCFG0_tag;

    // Device Configuration 1 Register (Address: 01H, Register Name: DEVCFG1)
    struct 
    {
        uint8 Reserved:     4;  // Bit7-Bit4 | Type: rw | Reset Value: 0000 | Reserved bits
        uint8 RESDEL:       4;  // Bit3-Bit0 | Type: rw | Reset Value: 0110 | nRESET release delay time (0000=200us, etc.)
    }Reg_DEVCFG1_tag;
    
    // Device Configuration 2 Register (Address: 02H, Register Name: DEVCFG2)
    struct 
    {
        uint8 EXSEL:        1;     // Bit7 | Type: r | Reset Value: Depends on EXSEL pin | External buck regulator enable status (0=Disabled/1=Enabled)
        uint8 BSTEN:        1;     // Bit6 | Type: r | Reset Value: Depends on BSTEN pin | Boost converter enable status (0=Disabled/1=Enabled)
        uint8 FSW:          1;     // Bit5 | Type: r | Reset Value: Depends on FSW pin | Buck converter frequency selection (0=Low frequency/1=High frequency)
        uint8 CMONEN:       1;     // Bit4 | Type: rw | Reset Value: 0 | LDO current monitor enable (0=Disabled/1=Enabled)
        uint8 CTHR:         2;     // Bit3-Bit2 | Type: rw | Reset Value: 00 | LDO current monitor threshold (00=10mA, etc.)
        uint8 SYNCPHA:       1;     // Bit1 | Type: rw | Reset Value: 0 | Phase shift (0=No shift/1=180° shift)
        uint8 SYNCEN:       1;     // Bit0 | Type: rw | Reset Value: 0 | External buck regulator sync output enable (0=Disabled/1=Enabled)
    }Reg_DEVCFG2_tag;

    // Protection Register (Address: 03H, Register Name: PROTCFG)
    struct 
    {
        uint8 KEY:          8;     // Bit7-Bit0 | Type: rw | Reset Value: 00000000 | Protection key (used to request write access to protected registers)
    }Reg_PROTCFG_tag;

    // Protected System Configuration Request 0 Register (Address: 04H, Register Name: SYSPCFG0)
    struct 
    {
        uint8 Reserved:     7;      // Bit7-Bit1 | Type: r | Reset Value: 0000000 | Unused bits (write 0, read 1)
        uint8 STBYEN:       1;      // Bit0 | Type: rwp | Reset Value: 1 | LDO STANDBY enable (0=Disabled / 1=Enabled)
    }Reg_SYSPCFG0_tag;

    // Protected System Configuration Request 1 Register (Address: 05H, Register Name: SYSPFG1)
    struct 
    {
        uint8 SS2DEL:       3;      // Bit7-Bit5 | Type: rwp | Reset Value: 000 | SS2 pin pull-low delay (000=0ms, etc.)
        uint8 ERRSLPEN:     1;      // Bit4 | Type: rwp | Reset Value: 0 | Error monitor enable in SLEEP state (0=Disabled / 1=Enabled)
        uint8 ERREN:        1;      // Bit3 | Type: rwp | Reset Value: 1 | Error monitor enable (0=Disabled / 1=Enabled)
        uint8 ERRRECEN:     1;      // Bit2 | Type: rwp | Reset Value: 0 | Error monitor recovery delay enable (0=Disabled / 1=Enabled)
        uint8 ERRRECTIM:    2;      // Bit1-Bit0 | Type: rwp | Reset Value: 00 | Error monitor recovery delay time (00=1ms, etc.)
    }Reg_SYSPFG1_tag;

    // Protected Watchdog Configuration Request 0 Register (WWDCFG0, Address: 0x06)
    struct
    {
        uint8 WWDETHR: 4;     // Bit7-Bit4 | Type: rwp | Reset Value: 0x9 | WWD error counter threshold (reset to INIT when reached)
        uint8 WWDEN: 1;        // Bit3 | Type: rwp | Reset Value: 1 | Window watchdog enable (0=Disabled; 1=Enabled)
        uint8 FWDEN: 1;       // Bit2 | Type: rwp | Reset Value: 0 | Functional watchdog enable (0=Disabled; 1=Enabled)
        uint8 WWDTSEL: 1;      // Bit1 | Type: rwp | Reset Value: 1 | WWD trigger source select (0=External WWDI input; 1=SPI write WDSVCMMD reg)
        uint8 WDCYC: 1;        // Bit0 | Type: rwp | Reset Value: 1 | Watchdog cycle config (0=0.1ms clock cycle; 1=1ms clock cycle)
    } Reg_WDCFG0_tag;

    // Protected Watchdog Configuration Request 1 Register (Address: 07H, Register Name: WDCFG1)
    struct 
    {
        uint8 Reserved_7:   1;    // Bit7 | Type: / | Reset Value: 0 | Unused bit (write 0, read 1)
        uint8 WDCYCDIV:     1;    // Bit6 | Type: rwp | Reset Value: 0 | Request enable of additional divider for watchdog cycle time (WDCYC) configuration
        uint8 Reserved_5:   1;    // Bit5 | Type: / | Reset Value: 0 | Unused bit (write 0, read 1)
        uint8 WDSLPEN:      1;    // Bit4 | Type: rwp | Reset Value: 0 | Watchdog enable in SLEEP state (0=Disabled / 1=Enabled)
        uint8 FWDETHR:      4;    // Bit3-Bit0 | Type: rwp | Reset Value: 1001 | Functional watchdog error threshold (triggers reset & INIT state)
    }Reg_WDCFG1_tag;

    // Protected Functional Watchdog Configuration Request Register (Address: 08H, Register Name: FWDCFG)
    struct 
    {
        uint8 Reserved_7_5: 3;      // Bit7-Bit5 | Type: / | Reset Value: 000 | Unused bits (write 0, read 1)
        uint8 WDHBTP:        5;      // Bit4-Bit0 | Type: rwp | Reset Value: 01011 | Functional watchdog timeout period (defines cycles, e.g., 00000=50wd cycles)
    }Reg_FWDCFG_tag;

    // Protected Window Watchdog Configuration Request 0 Register (Address: 09H, Register Name: WWDCFG0)
    struct Reg_WWDCFG0_tag
    {
        uint8 Reserved_7_5: 3;      // Bit7-Bit5 | Type: / | Reset Value: - | Unused bits (write 0, read 1)
        uint8 CW:           5;      // Bit4-Bit0 | Type: rwp | Reset Value: 00110 | Window watchdog timeout period (multiple of 50 watchdog cycles, e.g., 00000=50wd cycles)
    }Reg_WWDCFG0_tag;

    // Protected Window Watchdog Configuration Request 1 Register (Address: 0AH, Register Name: WWDCFG1)
    struct 
    {
        uint8 Reserved_7_5: 3;      // Bit7-Bit5 | Type: / | Reset Value: - | Unused bits (write 0, read 1)
        uint8 OW:           5;      // Bit4-Bit0 | Type: rwp | Reset Value: 01011 | Window watchdog timeout period (multiple of 50 watchdog cycles, e.g., 00000=50wd cycles)
    }Reg_WWDCFG1_tag;

    // System Configuration 0 Status Register (Address: 0BH, Register Name: RSYSCFG0)
    struct 
    {
        uint8 Reserved_7_1: 7; // Bit7-Bit1 | Type: / | Reset Value: 0000000 | Unused bits (write 0, read 1)
        uint8 STBYEN: 1;       // Bit0 | Type: r | Reset Value: 1 | LDO STANDBY enable status (0=Disabled / 1=Enabled)
    }Reg_RSYSCFG0_tag;

    // System Configuration 1 Status Register (Address: 0CH, Register Name: RSYSCFG1)
    struct 
    {
        uint8 SS2DEL: 3;       // Bit7-Bit5 | Type: r | Reset Value: 0 | SS2 pin pull-low delay status
        uint8 ERRSLPEN: 1;     // Bit4 | Type: r | Reset Value: 0 | Error monitor enable status in SLEEP state
        uint8 ERREN: 1;        // Bit3 | Type: r | Reset Value: 1 | Error monitor enable status
        uint8 ERRRECEN: 1;     // Bit2 | Type: r | Reset Value: 0 | Error monitor recovery delay enable status
        uint8 ERRREC: 2;       // Bit1-Bit0 | Type: r | Reset Value: 0 | Error monitor recovery delay time status
    }Reg_RSYSCFG1_tag;

    // Watchdog Configuration 0 Status Register (Address: 0DH, Register Name: RWDCFG0)
    struct 
    {
        uint8 WWDETHR: 4;      // Bit7-Bit4 | Type: r | Reset Value: 1001 | Window watchdog error threshold status
        uint8 WWDEN: 1;        // Bit3 | Type: r | Reset Value: 1 | Window watchdog enable status
        uint8 FWDEN: 1;        // Bit2 | Type: r | Reset Value: 0 | Functional watchdog enable status
        uint8 WWDTSEL: 1;      // Bit1 | Type: r | Reset Value: 1 | Window watchdog source selection status
        uint8 WDCYC: 1;        // Bit0 | Type: r | Reset Value: 1 | Watchdog cycle time status
    }Reg_RWDCFG0_tag;

    // Watchdog Configuration 1 Status Register (Address: 0EH, Register Name: RWDCFG1)
    struct 
    {
        uint8 Reserved_7: 1;    // Bit7 | Type: / | Reset Value: 0 | Unused bit
        uint8 WDCYCDIV: 1;      // Bit6 | Type: r | Reset Value: 0 | Additional divider by 10 for watchdog cycle time (WDCYC) configuration enable status
        uint8 Reserved_5: 1;    // Bit5 | Type: / | Reset Value: 0 | Unused bit
        uint8 WDSLPEN: 1;       // Bit4 | Type: r | Reset Value: 0 | Watchdog enable in SLEEP state status (0=Disabled / 1=Enabled)
        uint8 FWDETHR: 4;       // Bit3-0 | Type: r | Reset Value: 1001 | Functional watchdog error counter threshold status (triggers reset & INIT state)
    }Reg_RWDCFG1_tag;

    // Functional Watchdog Configuration Status Register (Address: 0FH, Register Name: RFWDCFG)
    struct 
    {
        uint8 Reserved_7_5: 3; // Bit7-Bit5 | Type: / | Reset Value: 000 | Unused bits (write 0, read 1)
        uint8 WDHBTP: 5;        // Bit4-Bit0 | Type: r | Reset Value: 01011 | Functional watchdog timeout period status (defined as multiple of 50 watchdog cycles)
    }Reg_RFWDCFG_tag;

    // Window Watchdog Configuration 0 Status Register (Address: 10H, Register Name: RWWDCFG0)
    struct 
    {
        uint8 Reserved_7_5: 3; // Bit7-Bit5 | Type: / | Reset Value: 000 | Unused bits (write 0, read 1)
        uint8 CW: 5;           // Bit4-Bit0 | Type: r | Reset Value: 00110 | Window watchdog timeout period status (defined as multiple of 50 watchdog cycles)
    }Reg_RWWDCFG0_tag;

    // Window Watchdog Configuration 1 Status Register (Address: 11H, Register Name: RWWDCFG1)
    struct 
    {
        uint8 Reserved_7_5: 3; // Bit7-Bit5 | Type: / | Reset Value: 000 | Unused bits (write 0, read 1)
        uint8 OW: 5;           // Bit4-Bit0 | Type: r | Reset Value: 00111 | Window watchdog timeout period status (defined as multiple of 50 watchdog cycles)
    }Reg_RWWDCFG1_tag;

    // Wake Timer Configuration 0 Register (Address: 12H, Register Name: WKTMCFG0)
    struct 
    {
        uint8 TIMVALL: 8;      // Bit7-Bit0 | Type: rw | Reset Value: 00000000 | Wake timer value (high bits, defined as multiple of wake timer cycles)
    }Reg_WKTMCFG0_tag;

    // Wake Timer Configuration 1 Register (Address: 13H, Register Name: WKTMCFG1)
    struct 
    {
        uint8 TIMVALM: 8;     // Bit7-Bit0 | Type: rw | Reset Value: 00000000 | Wake timer value (middle bits, defined as multiple of wake timer cycles)
    }Reg_WKTMCFG1_tag;

    // Wake Timer Configuration 2 Register (Address: 14H, Register Name: WKTMCFG2)
    struct 
    {
        uint8 TIMVALH: 8;     // Bit7-Bit0 | Type: rw | Reset Value: 00000000 | Wake timer value high bits (defined as multiple of wake timer cycles)
    }Reg_WKTMCFG2_tag;

    // Device Control Request Register (Address: 15H, Register Name: DEVCTRL)
    struct 
    {
        uint8 TRK2EN: 1;      // Bit7 | Type: rw | Reset Value: 0 | Request tracker2 enable (0=Disable after request / 1=Enable after request)
        uint8 TRK1EN: 1;      // Bit6 | Type: rw | Reset Value: 0 | Request tracker1 enable (0=Disable after request / 1=Enable after request)
        uint8 COMEN: 1;       // Bit5 | Type: rw | Reset Value: 0 | Request VCO enable (0=Disable after request / 1=Enable after request)
        uint8 Reserved: 1;    // Bit4 | Type: / | Reset Value: 1 | Unused bit (write 0, read 1)
        uint8 VREFEN: 1;      // Bit3 | Type: rw | Reset Value: 1 | Request VR enable (0=Disable after request / 1=Enable after request)
        uint8 STATEREQ: 3;    // Bit2-Bit0 | Type: rwlc | Reset Value: 000 | Request device state (000=STANDBY, 001=INIT, etc.; cleared by hardware after processing)
    }Reg_DEVCTRL_tag;

    // Device Control Inverted Request Register (Address: 16H, Register Name: DEVCTRLN)
    struct 
    {
        uint8 TRK2EN: 1;      // Bit7 | Type: rw | Reset Value: 0 | Inverted request tracker2 enable (0=Enable after request / 1=Disable after request)
        uint8 TRK1EN: 1;      // Bit6 | Type: rw | Reset Value: 0 | Inverted request tracker1 enable (0=Enable after request / 1=Disable after request)
        uint8 COMEN: 1;       // Bit5 | Type: rw | Reset Value: 0 | Inverted request VCO enable (0=Enable after request / 1=Disable after request)
        uint8 Reserved: 1;    // Bit4 | Type: / | Reset Value: 0 | Unused bit (write 0, read 1)
        uint8 VREFEN: 1;      // Bit3 | Type: rw | Reset Value: 0 | Inverted request VR enable (0=Enable after request / 1=Disable after request)
        uint8 STATEREQ: 3;    // Bit2-Bit0 | Type: rwlc | Reset Value: 000 | Inverted request device state (cleared by hardware after processing)
    }Reg_DEVCTRLN_tag;

    // Window Watchdog Service Command Register (Address: 17H, Register Name: WDSVCMMD)
    struct 
    {
        uint8 TRIG_STATUS: 1;
        uint8 Reserved: 6;  // Bit6-Bit1 | Type: / | Reset Value: 000000 | Unused bits
        uint8 TRIG: 1;      // Bit0 | Type: rw | Reset Value: 0 | Window watchdog service command trigger
    }Reg_WWDSCMD_tag;

    // Functional Watchdog Response Command Register (Address: 18H, Register Name: FWDRSP)
    struct 
    {
        uint8 FWDRSP: 8;    // Bit7-Bit0 | Type: rw | Reset Value: 00000000 | Functional watchdog response command
    }Reg_FWDRSP_tag;

    // Functional Watchdog Response Command with Synchronization Register (Address: 19H, Register Name: FWDRSPSYNC)
    struct 
    {
        uint8 FWDRSPS: 8;   // Bit7-Bit0 | Type: rw | Reset Value: 00000000 | Functional watchdog response command (with synchronization marker)
    }Reg_FWDRSPSYNC_tag;

    // Failure Status Flags Register (Address: 1AH, Register Name: SYSFAIL)
    struct 
    {
        uint8 INITF: 1;      // Bit7 | Type: rwlc | Reset Value: 0 | INIT failure flag (0=No fail; 1=Fail; write 1 to clear)
        uint8 ABISTERR: 1;     // Bit6 | Type: rwlc | Reset Value: 0 | ABIST operation failure flag (write 1 to clear)
        uint8 Reserved: 3;  // Bit5-Bit3 | Type: / | Reset Value: 000 | Unused bits
        uint8 VMONF: 1;     // Bit2 | Type: rwlc | Reset Value: 0 | Voltage monitor failure flag (write 1 to clear)
        uint8 OTF: 1;       // Bit1 | Type: rwlc | Reset Value: 0 | Overtemperature failure flag (write 1 to clear)
        uint8 VOLSELER: 1;  // Bit0 | Type: rwlc | Reset Value: 0 | Voltage selection failure flag (write 1 to clear)
    }Reg_SYSFAIL_tag;

    // Init Error Status Flag Register (Address: 1BH)
    struct 
    {
        uint8 HARDERS: 1;   // Bit7 | Type: rwlc | Reset Value: 0 | Second BIST failure flag (write 1 to clear)
        uint8 SOFTRES: 1;   // Bit6 | Type: rwlc | Reset Value: 0 | First BIST failure flag (write 1 to clear)
        uint8 ERRF: 1;  // Bit5 | Type: rwlc | Reset Value: 0 | Soft reset error flag (write 1 to clear)
        uint8 FWDF: 1;      // Bit3 | Type: rwlc | Reset Value: 0 | Functional watchdog error flag (write 1 to clear)
        uint8 WWDF: 1;      // Bit2 | Type: rwlc | Reset Value: 0 | Window watchdog error flag (write 1 to clear)
        uint8 VMONF: 1;     // Bit1 | Type: rwlc | Reset Value: 0 | Voltage monitor error flag (write 1 to clear)
        uint8 Reserved: 2;  // Bit0 | Type: / | Reset Value: 0 | Unused bit
    }Reg_INITERR_tag;

    // Interrupt Flags Register (Address: 1CH)
    struct 
    {
        uint8 INTMISS: 1;    // Bit7 | Type: r | Reset Value: 0 | Interrupt mask status (read-only)
        uint8 ABIST: 1;     // Bit6 | Type: rwlc | Reset Value: 0 | ABIST interrupt flag (write 1 to clear)
        uint8 OTF: 1;       // Bit5 | Type: rwlc | Reset Value: 0 | Overtemperature interrupt flag (write 1 to clear)
        uint8 OTW: 1;      // Bit4 | Type: rwlc | Reset Value: 0 | Functional watchdog timeout interrupt flag (write 1 to clear)
        uint8 MON: 1;       // Bit3 | Type: rwlc | Reset Value: 0 | Monitor interrupt flag (write 1 to clear)
        uint8 SPI: 1;       // Bit2 | Type: rwlc | Reset Value: 0 | SPI error interrupt flag (write 1 to clear)
        uint8 WK: 1;        // Bit1 | Type: rwlc | Reset Value: 0 | Wake interrupt flag (write 1 to clear)
        uint8 SYS: 1;       // Bit0 | Type: rwlc | Reset Value: 0 | System interrupt flag (write 1 to clear)
    }Reg_IF_tag;

    // System Status Flags Register (Address: 1DH, Register Name: SYSFLG)
    struct 
    {
        uint8 Reserved_7_6: 2; // Bit7-Bit6 | Type: rwlc | Reset Value: 0 | Unused bits (write 1 to clear)
        uint8 NO_LOP: 1;       // Bit5 | Type: rwlc | Reset Value: 1 | State transition request failure flag (write 1 to clear)
        uint8 TRFAIL: 1;       // Bit4 | Type: rwlc | Reset Value: 0 | Transition to low power state failure flag (write 1 to clear)
        uint8 ERRMISS: 1;       // Bit3 | Type: rwlc | Reset Value: 0 | MCI error status flag (write 1 to clear)
        uint8 FWDE: 1;         // Bit2 | Type: rwlc | Reset Value: 0 | Functional watchdog error flag (write 1 to clear)
        uint8 WWDE: 1;         // Bit1 | Type: rwlc | Reset Value: 0 | Window watchdog error flag (write 1 to clear)
        uint8 CFGE: 1;         // Bit0 | Type: rwlc | Reset Value: 0 | Protected configuration register double bit error flag (write 1 to clear)
    }Reg_SYSSF_tag;

    // Wakeup Status Flags Register (Address: 1EH, Register Name: WKS)
    struct 
    {
        uint8 WAKST: 1;     // Bit7 | Type: r | Reset Value: 0 | Voltage level at WAKE pin (0=Low / 1=High)
        uint8 ENST: 1;         // Bit6 | Type: r | Reset Value: 0 | EN signal range status (0=Low range / 1=High range)
        uint8 Reserved: 1;     // Bit5 | Type: / | Reset Value: 0 | Unused bit
        uint8 WKSPI: 1;        // Bit4 | Type: rwlc | Reset Value: 0 | SPI wakeup flag (write 1 to clear)
        uint8 WKTIM: 1;        // Bit3 | Type: rwlc | Reset Value: 0 | Wake timer wakeup flag (write 1 to clear)
        uint8 CMON: 1;         // Bit2 | Type: rwlc | Reset Value: 0 | Current monitor wakeup flag (write 1 to clear)
        uint8 EN: 1;           // Bit1 | Type: rwlc | Reset Value: 0 | EN signal wakeup flag (write 1 to clear)
        uint8 WAKE: 1;    // Bit0 | Type: rwlc | Reset Value: 0 | Wakeup status flag (write 1 to clear)
    }Reg_WKSF_tag;

    // SPI Status Flags Register (Address: 1FH)
    struct 
    {
        uint8 Reserved_7_5: 3; // Bit7-Bit5 | Type: rwlc | Reset Value: 0 | Unused bits (write 1 to clear)
        uint8 LOCK: 1;         // Bit4 | Type: rwlc | Reset Value: 0 | SPI lock/PID check failure flag (write 1 to clear)
        uint8 DURE: 1;         // Bit3 | Type: rwlc | Reset Value: 0 | SPI data order error flag (write 1 to clear)
        uint8 ADDRE: 1;         // Bit2 | Type: rwlc | Reset Value: 0 | SPI address error flag (write 1 to clear)
        uint8 LENE: 1;          // Bit1 | Type: rwlc | Reset Value: 0 | SPI length error flag (write 1 to clear)
        uint8 PAR: 1;          // Bit0 | Type: rwlc | Reset Value: 0 | SPI parity error flag (write 1 to clear)
    }Reg_SPISF_tag;

    // Monitor Status Flags 0 Register (Address: 20H, Register Name: MONST0)
    struct 
    {
        uint8 TRK2SC: 1;
        uint8 TRK1SC: 1;
        uint8 VREFSG: 1;
        uint8 COMSG: 1; 
        uint8 VMONSG: 1;
        uint8 STBYSG: 1;
        uint8 UCSG: 1;  
        uint8 PREGSG: 1;  
    }Reg_MONSF0_tag;

    // Monitor Status Flags 1 Register (Address: 21H, Register Name: MONST1)
    struct 
    {
        uint8 TRK2OV: 1;       // Bit7 | Type: rwlc | Reset Value: 0 | Tracker2 overvoltage flag (write 1 to clear)
        uint8 TRK1OV: 1;       // Bit6 | Type: rwlc | Reset Value: 0 | Tracker1 overvoltage flag (write 1 to clear)
        uint8 VREFOV: 1;        // Bit5 | Type: rwlc | Reset Value: 0 | VR overvoltage flag (write 1 to clear)
        uint8 COMOV: 1;       // Bit4 | Type: rwlc | Reset Value: 0 | VCO overvoltage flag (write 1 to clear)
        uint8 VMONOV: 1;      // Bit3 | Type: rwlc | Reset Value: 0 | VMON overvoltage flag (write 1 to clear)
        uint8 STBYOV: 1;       // Bit2 | Type: rwlc | Reset Value: 0 | STANDBY overvoltage flag (write 1 to clear)
        uint8 UCOV: 1;         // Bit1 | Type: rwlc | Reset Value: 0 | LDO overvoltage flag (write 1 to clear)
        uint8 PREGOV: 1;        // Bit0 | Type: rwlc | Reset Value: 0 | Pre-bias overvoltage flag (write 1 to clear)
    }Reg_MONSF1_tag;

    // Monitor Status Flags 2 Register (Address: 22H)
    struct 
    {
        uint8 TRK2UV: 1;       // Bit7 | Type: rwlc | Reset Value: 0 | Tracker2 undervoltage flag (write 1 to clear)
        uint8 TRK1UV: 1;       // Bit6 | Type: rwlc | Reset Value: 0 | Tracker1 undervoltage flag (write 1 to clear)
        uint8 VREFUV: 1;        // Bit5 | Type: rwlc | Reset Value: 0 | VR undervoltage flag (write 1 to clear)
        uint8 COMUV: 1;       // Bit4 | Type: rwlc | Reset Value: 0 | VCO undervoltage flag (write 1 to clear)
        uint8 VMONUV: 1;      // Bit3 | Type: rwlc | Reset Value: 0 | VMON undervoltage flag (write 1 to clear)
        uint8 STBYUV: 1;       // Bit2 | Type: rwlc | Reset Value: 0 | STANDBY undervoltage flag (write 1 to clear)
        uint8 UCUV: 1;        // Bit1 | Type: rwlc | Reset Value: 0 | LDO undervoltage flag (write 1 to clear)
        uint8 PREGUV: 1;        // Bit0 | Type: rwlc | Reset Value: 0 | Pre-bias undervoltage flag (write 1 to clear)
    }Reg_MONSF2_tag;

    // Monitor Status Flags 3 Register (Address: 23H)
    struct 
    {
        uint8 BIASHI: 1;       // Bit7 | Type: rwlc | Reset Value: 0 | Bias undervoltage flag (write 1 to clear)
        uint8 BIASLOW: 1;       // Bit6 | Type: rwlc | Reset Value: 0 | Bias overvoltage flag (write 1 to clear)
        uint8 RG12OV: 1;       // Bit5 | Type: rwlc | Reset Value: 0 | REG2 undervoltage flag (write 1 to clear)
        uint8 BG12UV: 1;       // Bit4 | Type: rwlc | Reset Value: 0 | Bandgap 1.2V undervoltage flag (write 1 to clear)
        uint8 Reserved_3_1: 3; // Bit3-Bit1 | Type: / | Reset Value: 0 | Unused bits
        uint8 VBATOV: 1;       // Bit0 | Type: rwlc | Reset Value: 0 | VIAT undervoltage flag (write 1 to clear)
    }Reg_MONSF3_tag;

    // Over Temperature Failure Status Register (Address: 24H, Register Name: OTFAIL)
    struct 
    {
        uint8 MON: 1;          // Bit7 | Type: rwlc | Reset Value: 0 | Monitoring over-temperature failure flag (write 1 to clear)
        uint8 Reserved_6_5: 2; // Bit6-Bit5 | Type: / | Reset Value: 0 | Unused bits
        uint8 COM: 1;          // Bit4 | Type: rwlc | Reset Value: 0 | LDO_COM over-temperature failure flag (write 1 to clear)
        uint8 Reserved_3_2: 2; // Bit3-Bit2 | Type: / | Reset Value: 0 | Unused bits
        uint8 UC: 1;           // Bit1 | Type: rwlc | Reset Value: 0 | LDO_UC over-temperature failure flag (write 1 to clear)
        uint8 PREG: 1;         // Bit0 | Type: rwlc | Reset Value: 0 | Pre-regulator over-temperature failure flag (write 1 to clear)
    }Reg_OTFAIL_tag;

    // Over Temperature Warning Status Flags Register (Address: 25H, Register Name: OTWRNSF)
    struct 
    {
        uint8 Reserved_7_6: 2; // Bit7-Bit6 | Type: / | Reset Value: 0 | Unused bits
        uint8 VREF: 1;         // Bit5 | Type: rwlc | Reset Value: 0 | LDO_REF over-load warning flag (write 1 to clear)
        uint8 COM: 1;          // Bit4 | Type: rwlc | Reset Value: 0 | LDO_COM over-temperature warning flag (write 1 to clear)
        uint8 Reserved_3: 1;   // Bit3 | Type: / | Reset Value: 0 | Unused bit
        uint8 STDBY: 1;        // Bit2 | Type: rwlc | Reset Value: 0 | LDO_STBY over-load warning flag (write 1 to clear)
        uint8 UC: 1;           // Bit1 | Type: rwlc | Reset Value: 0 | LDO_UC over-temperature warning flag (write 1 to clear)
        uint8 PREG: 1;         // Bit0 | Type: rwlc | Reset Value: 0 | Pre-regulator over-temperature warning flag (write 1 to clear)
    }Reg_OTWRNSF_tag;

    // Voltage Monitor Status Register (Address: 26H, Register Name: VMONSTAT)
    struct 
    {
        uint8 TRK2ST: 1;       // Bit7 | Type: r | Reset Value: 0 | Tracker2 voltage ready status (0=Out of range / 1=OK)
        uint8 TRK1ST: 1;       // Bit6 | Type: r | Reset Value: 0 | Tracker1 voltage ready status (0=Out of range / 1=OK)
        uint8 VREFST: 1;       // Bit5 | Type: r | Reset Value: 0 | LDO_REF voltage ready status (0=Out of range/not enabled / 1=OK)
        uint8 COMST: 1;        // Bit4 | Type: r | Reset Value: 0 | LDO_COM voltage ready status (0=Out of range/not enabled / 1=OK)
        uint8 VMONST: 1;       // Bit3 | Type: r | Reset Value: 0 | External buck ready status (0=Out of range/not enabled / 1=OK)
        uint8 STBYST: 1;       // Bit2 | Type: r | Reset Value: 0 | LDO_STBY voltage ready status (0=Out of range/not enabled / 1=OK)
        uint8 Reserved: 1;     // Bit1 | Type: / | Reset Value: 0 | Unused bit
        uint8 PREGST: 1;       // Bit0 | Type: r | Reset Value: 0 | Pre-regulator (PB) voltage status (0=Out of range/not enabled / 1=OK)
    }Reg_VMONSTAT_tag;

    // Device Status Register (Address: 27H, Register Name: DEVSTAT)
    struct 
    {
        uint8 TRK2EN: 1;       // Bit7 | Type: r | Reset Value: 0 | Tracker2 voltage enable status (0=Disabled / 1=Enabled)
        uint8 TRK1EN: 1;       // Bit6 | Type: r | Reset Value: 0 | Tracker1 voltage enable status (0=Disabled / 1=Enabled)
        uint8 COMEN: 1;        // Bit5 | Type: r | Reset Value: 0 | LDO_COM enable status (0=Disabled / 1=Enabled)
        uint8 STBYEN: 1;       // Bit4 | Type: r | Reset Value: 0 | Standby LDO enable status (0=Disabled / 1=Enabled)
        uint8 VREFEN: 1;       // Bit3 | Type: r | Reset Value: 0 | LDO_REF enable status (0=Disabled / 1=Enabled)
        uint8 STATE: 3;        // Bit2-Bit0 | Type: r | Reset Value: 0 | Device state (000=NONE, 001=INIT, 010=NORMAL, etc.)
    }Reg_DEVSTAT_tag;

    // Protection Status Register (Address: 28H, Register Name: PROTSTAT)
    struct 
    {
        uint8 KEY4OK: 1;       // Bit7 | Type: r | Reset Value: 0 | 4th protection key byte validity (0=Not valid / 1=Valid)
        uint8 KEY3OK: 1;       // Bit6 | Type: r | Reset Value: 0 | 3rd protection key byte validity (0=Not valid / 1=Valid)
        uint8 KEY2OK: 1;       // Bit5 | Type: r | Reset Value: 0 | 2nd protection key byte validity (0=Not valid / 1=Valid)
        uint8 KEY1OK: 1;       // Bit4 | Type: r | Reset Value: 0 | 1st protection key byte validity (0=Not valid / 1=Valid)
        uint8 Reserved_3_1: 3; // Bit3-Bit1 | Type: / | Reset Value: 000 | Unused bits
        uint8 LOCK: 1;         // Bit0 | Type: r | Reset Value: 1 | Protected register lock status (0=Unlocked / 1=Locked)
    }Reg_PROTSTAT_tag;

    // Window Watchdog Status Register (Address: 29H, Register Name: WWDSTAT)
    struct 
    {
        uint8 Reserved_7_4: 4; // Bit7-Bit4 | Type: / | Reset Value: 0000 | Unused bits
        uint8 WWDECNT: 4;      // Bit3-Bit0 | Type: r | Reset Value: 0000 | Window watchdog error counter status
    }Reg_WWDSTAT_tag;

    // Functional Watchdog Status 0 Register (Address: 2AH, Register Name: FWDRSPOK)
    struct 
    {
        uint8 Reserved: 1;     // Bit7 | Type: / | Reset Value: 0 | Unused bit
        uint8 FWDRSPOK: 1;     // Bit6 | Type: r | Reset Value: 0 | Functional watchdog response check error status (0=Wrong / 1=Correct)
        uint8 FWDRSPC: 2;      // Bit5-Bit4 | Type: r | Reset Value: 0 | Functional watchdog response counter value
        uint8 FWDRQUEST: 4;    // Bit3-Bit0 | Type: r | Reset Value: 0 | Functional watchdog question status
    }Reg_FWDRSPOK_tag;

    // Functional Watchdog Status 1 Register (Address: 2BH, Register Name: FWDSTAT1)
    struct 
    {
        uint8 Reserved_7_4: 4; // Bit7-Bit4 | Type: / | Reset Value: 0000 | Unused bits
        uint8 FWDECNT: 4;      // Bit3-Bit0 | Type: r | Reset Value: 0000 | Functional watchdog error counter status
    }Reg_FWDSTAT1_tag;

    // ABIST Control 0 Register (Address: 2CH, Register Name: ABIST_CTRL0)
    struct 
    {
        uint8 STATUS: 4;       // Bit7-Bit4 | Type: r | Reset Value: 0000 | ABIST global error status (valid after ABIST completion)
        uint8 INT: 1;          // Bit3 | Type: rw | Reset Value: 0 | Comparator status selection (0=Safe state / 1=Interrupt-related)
        uint8 SINGLE: 1;       // Bit2 | Type: rw | Reset Value: 0 | ABIST sequence selection (0=Predefined sequence / 1=Single comparator test)
        uint8 PATH: 1;         // Bit1 | Type: rw | Reset Value: 0 | Full path test selection (0=Comparator only / 1=Full path)
        uint8 START: 1;        // Bit0 | Type: rwc | Reset Value: 0 | ABIST operation start (1=Start; cleared after operation completion)
    }Reg_ABIST_CTRL0_tag;

    // ABIST Control 1 Register (Address: 2DH, Register Name: ABIST_CTRL1)
    struct 
    {
        uint8 Reserved_7_2: 6; // Bit7-Bit2 | Type: / | Reset Value: 000000 | Unused bits
        uint8 ABIST_CLK_EN: 1; // Bit1 | Type: rw | Reset Value: 0 | ABIST clock check enable (0=Disable / 1=Enable)
        uint8 OV_TRIG: 1;      // Bit0 | Type: rw | Reset Value: 0 | Overvoltage trigger for secondary internal monitor (0=Disable / 1=Enable)
    }Reg_ABIST_CTRL1_tag;

    // ABIST SELECT0 Register (Address: 2EH, Register Name: ABIST_SELECT0)
    struct 
    {
        uint8 TRK2OV: 1;   // Bit7 | Type: rwhu | Reset Value: 0 | Select TRACK2 OV comparator for ABIST operation
        uint8 TRK1OV: 1;   // Bit6 | Type: rwhu | Reset Value: 0 | Select TRACK1 OV comparator for ABIST operation
        uint8 VREFOV: 1;   // Bit5 | Type: rwhu | Reset Value: 0 | Select LDO_REF OV comparator for ABIST operation
        uint8 COMOV: 1;    // Bit4 | Type: rwhu | Reset Value: 0 | Select LDO_COM OV comparator for ABIST operation
        uint8 VMONOV: 1;   // Bit3 | Type: rwhu | Reset Value: 0 | Select External buck OV comparator for ABIST operation
        uint8 STBYOV: 1;   // Bit2 | Type: rwhu | Reset Value: 0 | Select LDO_STBY OV comparator for ABIST operation
        uint8 UCOV: 1;     // Bit1 | Type: rwhu | Reset Value: 0 | Select LDO_UC OV comparator for ABIST operation
        uint8 PREGOV: 1;   // Bit0 | Type: rwhu | Reset Value: 0 | Select Pre-regulator OV comparator for ABIST operation
    }Reg_ABIST_SELECT0_tag;

    // ABIST SELECT1 Register (Address: 2FH, Register Name: ABIST_SELECT1)
    struct 
    {
        uint8 TRK2UV: 1;   // Bit7 | Type: rwhu | Reset Value: 0 | Select TRACK2 UV comparator for ABIST operation
        uint8 TRK1UV: 1;   // Bit6 | Type: rwhu | Reset Value: 0 | Select TRACK1 UV comparator for ABIST operation
        uint8 VREFUV: 1;   // Bit5 | Type: rwhu | Reset Value: 0 | Select LDO_REF UV comparator for ABIST operation
        uint8 COMUV: 1;   // Bit4 | Type: rwhu | Reset Value: 0 | Select LDO_COM UV comparator for ABIST operation
        uint8 VMONUV: 1;   // Bit3 | Type: rwhu | Reset Value: 0 | Select External buck UV comparator for ABIST operation
        uint8 STBYUV: 1;   // Bit2 | Type: rwhu | Reset Value: 0 | Select LDO_STBY UV comparator for ABIST operation
        uint8 UCUV: 1;     // Bit1 | Type: rwhu | Reset Value: 0 | Select LDO_UC UV comparator for ABIST operation
        uint8 PREGUV: 1;   // Bit0 | Type: rwhu | Reset Value: 0 | Select Pre-regulator UV comparator for ABIST operation
    }Reg_ABIST_SELECT1_tag;

    // ABIST SELECT2 Register (Address: 30H, Register Name: ABIST_SELECT2)
    struct 
    {
        uint8 BIASHI: 1;    // Bit7 | Type: rwhu | Reset Value: 0 | Select bias current too high comparator for ABIST operation
        uint8 BIASLOW: 1;   // Bit6 | Type: rwhu | Reset Value: 0 | Select bias current too low comparator for ABIST operation
        uint8 BG12OV: 1;    // Bit5 | Type: rwhu | Reset Value: 0 | Select bandgap comparator OV condition for ABIST operation
        uint8 BG12UV: 1;    // Bit4 | Type: rwhu | Reset Value: 0 | Select bandgap comparator UV condition for ABIST operation
        uint8 INTOV: 1;     // Bit3 | Type: rwhu | Reset Value: 0 | Select internal supply OV condition comparator for ABIST operation
        uint8 Reserved_2_1: 2; // Bit2-Bit1 | Type: / | Reset Value: 0 | Unused bits
        uint8 VBATOV: 1;     // Bit0 | Type: rwhu | Reset Value: 0 | Select supply VIN/VINST overvoltage comparator for ABIST operation
    }Reg_ABIST_SELECT2_tag;

    // Buck Switching Frequency Change Register (Address: 31H, Register Name: BCK_FREQ_CHANGE)
    struct 
    {
        uint8 Reserved_7_3: 5; // Bit7-Bit3 | Type: / | Reset Value: 000 | Unused bits
        uint8 BCK_FREQ_SEL: 3;  // Bit2-Bit0 | Type: rw | Reset Value: 000 | Buck switching frequency change selection
    }Reg_BCK_FREQ_CHANGE_tag;

    // Buck Frequency Spread Register (Address: 32H, Register Name: BCK_FREQ_SPREAD)
    struct 
    {
        uint8 FRE_SP_THR: 8;    // Bit7-Bit0 | Type: rw | Reset Value: 00000000 | Buck frequency spread percentage selection
    }Reg_BCK_FREQ_SPREAD_tag;

    // Buck Main Control Register (Address: 33H, Register Name: BCK_MAIN_CTRL)
    struct 
    {
        uint8 BUSY: 1;          // Bit7 | Type: r | Reset Value: 0 | Buck main regulator ready status
        uint8 DATA_VALID: 1;    // Bit6 | Type: rw | Reset Value: 0 | Update command to enable Buck regulator
        uint8 Reserved_5_0: 6;  // Bit5-Bit0 | Type: / | Reset Value: 000000 | Unused bits
    }Reg_BCK_MAIN_CTRL_tag;

    // Global Test Mode Register (Address: 3FH, Register Name: GTM)
    struct 
    {
        uint8 Reserved_7_2: 6; // Bit7-Bit2 | Type: / | Reset Value: 000000 | Unused bits
        uint8 NIM: 1;          // Bit1 | Type: r | Reset Value: 1 | Test mode protection status (0=Test mode / 1=Normal mode)
        uint8 TM: 1;           // Bit0 | Type: r | Reset Value: 0 | Test mode status (0=Normal mode / 1=Test mode)
    }Reg_GTM_tag;

    // Function Control Register (Address: 36H, Register Name: FCR)
    struct 
    {  
        uint8 Reserved_1: 6; 
        uint8 VR_OV_FS:   1;  
        uint8 LDO_UC_CUR: 1;  
    }Reg_FCR_tag;

    // MCU Program Support Register (Address: 3CH, Register Name: MCUSUP)
    struct 
    {
        uint8 PROG: 1;         // Bit7 | Type: rw | Reset Value: 0 | MCU programming support enable (0=Disabled / 1=Enabled)
        uint8 MPSIN: 1;        // Bit6 | Type: rw | Reset Value: 0 | MCU programming support monitor (0=Disabled / 1=Enabled)
        uint8 Reserved_5_0: 6; // Bit5-Bit0 | Type: / | Reset Value: 000000 | Unused bits
    }Reg_MCUSUP_tag;
    /* data */
}Cdd_SA47301_RegInfoType;


#ifdef __cplusplus
}
#endif




#endif /* _CDD_SA47301_REG_H_ */