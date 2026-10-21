/*
********************************************************************************
*
* File name: NvM_Cfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation.All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 130
* Author/Date : WangJP/2021.08.14
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: WangLX/2024.04.25
* Change: Add a memory-map label to function and variable declarations.
* Cause: Bugfix
********************************************************************************
* Version: 3.1
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
*/
#ifndef NVM_CFG_H_
#define NVM_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "NvM_Types.h"
#include "NvM_Def.h"
#include "Crc.h"
#include "Nvm_UserBlock.h"
#include "Nvm_BlockCallback.h"
#include "Dcm_Lcfg.h"
#include "NvM_UserDefine.h"
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */

#define EEPROM_BLOCK2_RAM_SIZE 20       
#define EEPROM_BLOCK3_RAM_SIZE 100     
#define EEPROM_BLOCK4_RAM_SIZE 40    
#define EEPROM_BLOCK5_RAM_SIZE 100     
#define EEPROM_BLOCK6_RAM_SIZE 4     
#define EEPROM_BLOCK7_RAM_SIZE 6     
#define EEPROM_BLOCK8_9_RAM_SIZE 512     
#define EEPROM_BLOCK10_49_RAM_SIZE 256     
#define EEPROM_BLOCK50_89_RAM_SIZE 20     
#define EEPROM_BLOCK90_96_RAM_SIZE 32     
#define EEPROM_BLOCK97_100_RAM_SIZE 64    
#define EEPROM_BLOCK101_RAM_SIZE 256      
#define EEPROM_BLOCK102_105_RAM_SIZE 64    
#define EEPROM_BLOCK106_RAM_SIZE 256
#define EEPROM_BLOCK107_118_RAM_SIZE 64
#define EEPROM_BLOCK119_RAM_SIZE 256
#define EEPROM_BLOCK120_127_RAM_SIZE 64
#define EEPROM_BLOCK128_131_RAM_SIZE 256

#define NVM_NUM_OF_BLOCK_TOTAL                               (186U)
#define NVM_BLOCK_REAL_NUMBER                                (NVM_NUM_OF_BLOCK_TOTAL - 1U)
#define NVM_BLOCK_REMAIN_NUMBER                              (NVM_BLOCK_REAL_NUMBER - 1U)
#define NVM_BLOCK_MAX_LENGTH                                 (1498U)
#define NVM_API_CONFIG_CLASS_1                               (1U)
#define NVM_API_CONFIG_CLASS_2                               (3U)
#define NVM_API_CONFIG_CLASS_3                               (7U)
#define NVM_API_CONFIG_CLASS                                 (NVM_API_CONFIG_CLASS_3)
#define NVM_CRC_NUM_OF_BYTES                                 (64U)
#define NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION          (STD_OFF)
#define NVM_JOB_PRIORITIZATION                               (STD_OFF)
#define NVM_POLLING_MODE                                     (STD_ON)
#define NVM_REPEAT_MIRROR_OPERATIONS                         (1U)
#define NVM_SET_RAM_BLOCK_STATUS_API                         (STD_ON)
#define NVM_VERSION_INFO_API                                 (STD_ON)
#define NVM_DRV_MODE_SWITCH                                  (STD_ON)
#define NVM_DEV_ERROR_DETECT                                 (STD_ON)
#define NVM_MULTI_BLOCK_CALLBACK                             (STD_OFF)
#define NVM_COMPILED_CONFIG_ID                               (2U)
#define NVM_DATASET_SELECTION_BITS                           (2U)
#define NVM_DYNAMIC_CONFIGURATION                            (STD_OFF)
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE                         (186U)
#define NVM_SIZE_STANDARD_JOB_QUEUE                          (186U)
#define NVM_MULTI_BLOCK_CALLBACK_ENABLE                      (STD_OFF)
#define NVM_WRITEVERIFY_ENABLE                               (STD_OFF)
#define NVM_WRITEVERIFY_LENGTH                               (0U)
#define NVM_BLOCKID_NVMBLOCK2_RESETREASON (2U)
#define NVM_BLOCKID_NVMBLOCK3_OSERROR (3U)
#define NVM_BLOCKID_NVMBLOCK4_FUNERRDIAG_SECURITY (4U)
#define NVM_BLOCKID_NVMBLOCK5_INFORMATION_SECURITY (5U)
#define NVM_BLOCKID_NVMBLOCK6_DCM11_NVMBUF (6U)
#define NVM_BLOCKID_NVMBLOCK7_DCM_27_SECURITY_DATA (7U)
#define NVM_BLOCKID_NVMBLOCK8_UDS_FAULTSTATUS_AGINGCOUNT (8U)
#define NVM_BLOCKID_NVMBLOCK9_UDS_FAULTSTATUS_AGINGCOUNT (9U)
#define NVM_BLOCKID_NVMBLOCK10_UDS_FROZENDATA (10U)
#define NVM_BLOCKID_NVMBLOCK11_UDS_FROZENDATA (11U)
#define NVM_BLOCKID_NVMBLOCK12_UDS_FROZENDATA (12U)
#define NVM_BLOCKID_NVMBLOCK13_UDS_FROZENDATA (13U)
#define NVM_BLOCKID_NVMBLOCK14_UDS_FROZENDATA (14U)
#define NVM_BLOCKID_NVMBLOCK15_UDS_FROZENDATA (15U)
#define NVM_BLOCKID_NVMBLOCK16_UDS_FROZENDATA (16U)
#define NVM_BLOCKID_NVMBLOCK17_UDS_FROZENDATA (17U)
#define NVM_BLOCKID_NVMBLOCK18_UDS_FROZENDATA (18U)
#define NVM_BLOCKID_NVMBLOCK19_UDS_FROZENDATA (19U)
#define NVM_BLOCKID_NVMBLOCK20_UDS_FROZENDATA (20U)
#define NVM_BLOCKID_NVMBLOCK21_UDS_FROZENDATA (21U)
#define NVM_BLOCKID_NVMBLOCK22_UDS_FROZENDATA (22U)
#define NVM_BLOCKID_NVMBLOCK23_UDS_FROZENDATA (23U)
#define NVM_BLOCKID_NVMBLOCK24_UDS_FROZENDATA (24U)
#define NVM_BLOCKID_NVMBLOCK25_UDS_FROZENDATA (25U)
#define NVM_BLOCKID_NVMBLOCK26_UDS_FROZENDATA (26U)
#define NVM_BLOCKID_NVMBLOCK27_UDS_FROZENDATA (27U)
#define NVM_BLOCKID_NVMBLOCK28_UDS_FROZENDATA (28U)
#define NVM_BLOCKID_NVMBLOCK29_UDS_FROZENDATA (29U)
#define NVM_BLOCKID_NVMBLOCK30_UDS_FROZENDATA (30U)
#define NVM_BLOCKID_NVMBLOCK31_UDS_FROZENDATA (31U)
#define NVM_BLOCKID_NVMBLOCK32_UDS_FROZENDATA (32U)
#define NVM_BLOCKID_NVMBLOCK33_UDS_FROZENDATA (33U)
#define NVM_BLOCKID_NVMBLOCK34_UDS_FROZENDATA (34U)
#define NVM_BLOCKID_NVMBLOCK35_UDS_FROZENDATA (35U)
#define NVM_BLOCKID_NVMBLOCK36_UDS_FROZENDATA (36U)
#define NVM_BLOCKID_NVMBLOCK37_UDS_FROZENDATA (37U)
#define NVM_BLOCKID_NVMBLOCK38_UDS_FROZENDATA (38U)
#define NVM_BLOCKID_NVMBLOCK39_UDS_FROZENDATA (39U)
#define NVM_BLOCKID_NVMBLOCK40_UDS_FROZENDATA (40U)
#define NVM_BLOCKID_NVMBLOCK41_UDS_FROZENDATA (41U)
#define NVM_BLOCKID_NVMBLOCK42_UDS_FROZENDATA (42U)
#define NVM_BLOCKID_NVMBLOCK43_UDS_FROZENDATA (43U)
#define NVM_BLOCKID_NVMBLOCK44_UDS_FROZENDATA (44U)
#define NVM_BLOCKID_NVMBLOCK45_UDS_FROZENDATA (45U)
#define NVM_BLOCKID_NVMBLOCK46_UDS_FROZENDATA (46U)
#define NVM_BLOCKID_NVMBLOCK47_UDS_FROZENDATA (47U)
#define NVM_BLOCKID_NVMBLOCK48_UDS_FROZENDATA (48U)
#define NVM_BLOCKID_NVMBLOCK49_UDS_FROZENDATA (49U)
#define NVM_BLOCKID_NVMBLOCK50_DCM2E_ASW (50U)
#define NVM_BLOCKID_NVMBLOCK51_DCM2E_ASW (51U)
#define NVM_BLOCKID_NVMBLOCK52_DCM2E_ASW (52U)
#define NVM_BLOCKID_NVMBLOCK53_DCM2E_ASW (53U)
#define NVM_BLOCKID_NVMBLOCK54_DCM2E_ASW (54U)
#define NVM_BLOCKID_NVMBLOCK55_DCM2E_ASW (55U)
#define NVM_BLOCKID_NVMBLOCK56_DCM2E_ASW (56U)
#define NVM_BLOCKID_NVMBLOCK57_DCM2E_ASW (57U)
#define NVM_BLOCKID_NVMBLOCK58_DCM2E_ASW (58U)
#define NVM_BLOCKID_NVMBLOCK59_DCM2E_ASW (59U)
#define NVM_BLOCKID_NVMBLOCK60_DCM2E_ASW (60U)
#define NVM_BLOCKID_NVMBLOCK61_DCM2E_ASW (61U)
#define NVM_BLOCKID_NVMBLOCK62_DCM2E_ASW (62U)
#define NVM_BLOCKID_NVMBLOCK63_DCM2E_ASW (63U)
#define NVM_BLOCKID_NVMBLOCK64_DCM2E_ASW (64U)
#define NVM_BLOCKID_NVMBLOCK65_DCM2E_ASW (65U)
#define NVM_BLOCKID_NVMBLOCK66_DCM2E_ASW (66U)
#define NVM_BLOCKID_NVMBLOCK67_DCM2E_ASW (67U)
#define NVM_BLOCKID_NVMBLOCK68_DCM2E_ASW (68U)
#define NVM_BLOCKID_NVMBLOCK69_DCM2E_ASW (69U)
#define NVM_BLOCKID_NVMBLOCK70_DCM2E_ASW (70U)
#define NVM_BLOCKID_NVMBLOCK71_DCM2E_ASW (71U)
#define NVM_BLOCKID_NVMBLOCK72_DCM2E_ASW (72U)
#define NVM_BLOCKID_NVMBLOCK73_DCM2E_ASW (73U)
#define NVM_BLOCKID_NVMBLOCK74_DCM2E_ASW (74U)
#define NVM_BLOCKID_NVMBLOCK75_DCM2E_ASW (75U)
#define NVM_BLOCKID_NVMBLOCK76_DCM2E_ASW (76U)
#define NVM_BLOCKID_NVMBLOCK77_DCM2E_ASW (77U)
#define NVM_BLOCKID_NVMBLOCK78_DCM2E_ASW (78U)
#define NVM_BLOCKID_NVMBLOCK79_DCM2E_ASW (79U)
#define NVM_BLOCKID_NVMBLOCK80_DCM2E_ASW (80U)
#define NVM_BLOCKID_NVMBLOCK81_DCM2E_ASW (81U)
#define NVM_BLOCKID_NVMBLOCK82_DCM2E_ASW (82U)
#define NVM_BLOCKID_NVMBLOCK83_DCM2E_ASW (83U)
#define NVM_BLOCKID_NVMBLOCK84_DCM2E_ASW (84U)
#define NVM_BLOCKID_NVMBLOCK85_DCM2E_ASW (85U)
#define NVM_BLOCKID_NVMBLOCK86_DCM2E_ASW (86U)
#define NVM_BLOCKID_NVMBLOCK87_DCM2E_ASW (87U)
#define NVM_BLOCKID_NVMBLOCK88_DCM2E_ASW (88U)
#define NVM_BLOCKID_NVMBLOCK89_DCM2E_ASW (89U)
#define NVM_BLOCKID_NVMBLOCK90_DCM2E_ASW (90U)
#define NVM_BLOCKID_NVMBLOCK91_DCM2E_ASW (91U)
#define NVM_BLOCKID_NVMBLOCK92_DCM2E_ASW (92U)
#define NVM_BLOCKID_NVMBLOCK93_DCM2E_ASW (93U)
#define NVM_BLOCKID_NVMBLOCK94_DCM2E_ASW (94U)
#define NVM_BLOCKID_NVMBLOCK95_DCM2E_ASW (95U)
#define NVM_BLOCKID_NVMBLOCK96_DCM2E_ASW (96U)
#define NVM_BLOCKID_NVMBLOCK97_DCM2E_ASW (97U)
#define NVM_BLOCKID_NVMBLOCK98_DCM2E_ASW (98U)
#define NVM_BLOCKID_NVMBLOCK99_DCM2E_ASW (99U)
#define NVM_BLOCKID_NVMBLOCK100_DCM2E_ASW (100U)
#define NVM_BLOCKID_NVMBLOCK101_DCM2E_ASW (101U)
#define NVM_BLOCKID_NVMBLOCK102_DCM2E_BOOT (102U)
#define NVM_BLOCKID_NVMBLOCK103_DCM2E_BOOT (103U)
#define NVM_BLOCKID_NVMBLOCK104_DCM2E_BOOT (104U)
#define NVM_BLOCKID_NVMBLOCK105_DCM2E_BOOT (105U)
#define NVM_BLOCKID_NVMBLOCK106_DCM2E_BOOT (106U)
#define NVM_BLOCKID_NVMBLOCK107_DCM2E_SHARE (107U)
#define NVM_BLOCKID_NVMBLOCK108_DCM2E_SHARE (108U)
#define NVM_BLOCKID_NVMBLOCK109_DCM2E_SHARE (109U)
#define NVM_BLOCKID_NVMBLOCK110_DCM2E_SHARE (110U)
#define NVM_BLOCKID_NVMBLOCK111_DCM2E_SHARE (111U)
#define NVM_BLOCKID_NVMBLOCK112_DCM2E_SHARE (112U)
#define NVM_BLOCKID_NVMBLOCK113_DCM2E_SHARE (113U)
#define NVM_BLOCKID_NVMBLOCK114_DCM2E_SHARE (114U)
#define NVM_BLOCKID_NVMBLOCK115_DCM2E_SHARE (115U)
#define NVM_BLOCKID_NVMBLOCK116_DCM2E_SHARE (116U)
#define NVM_BLOCKID_NVMBLOCK117_DCM2E_SHARE (117U)
#define NVM_BLOCKID_NVMBLOCK118_DCM2E_SHARE (118U)
#define NVM_BLOCKID_NVMBLOCK119_DCM2E_SHARE (119U)
#define NVM_BLOCKID_NVMBLOCK120_RESERVE_ASW (120U)
#define NVM_BLOCKID_NVMBLOCK121_RESERVE_ASW (121U)
#define NVM_BLOCKID_NVMBLOCK122_RESERVE_ASW (122U)
#define NVM_BLOCKID_NVMBLOCK123_RESERVE_ASW (123U)
#define NVM_BLOCKID_NVMBLOCK124_RESERVE_ASW (124U)
#define NVM_BLOCKID_NVMBLOCK125_RESERVE_ASW (125U)
#define NVM_BLOCKID_NVMBLOCK126_RESERVE_ASW (126U)
#define NVM_BLOCKID_NVMBLOCK127_RESERVE_ASW (127U)
#define NVM_BLOCKID_NVMBLOCK128_RESERVE_ASW (128U)
#define NVM_BLOCKID_NVMBLOCK129_RESERVE_ASW (129U)
#define NVM_BLOCKID_NVMBLOCK130_RESERVE_ASW (130U)
#define NVM_BLOCKID_NVMBLOCK131_RESERVE_ASW (131U)
#define NVM_BLOCKID_NVMBLOCK132_DEM_EVENTMEMORYSTATUS (132U)
#define NVM_BLOCKID_NVMBLOCK133_DEM_EVENTMEMORYINFO (133U)
#define NVM_BLOCKID_NVMBLOCK134_DEM_EVENTMEMORYENTRY1 (134U)
#define NVM_BLOCKID_NVMBLOCK135_DEM_EVENTMEMORYENTRY2 (135U)
#define NVM_BLOCKID_NVMBLOCK136_DEM_EVENTMEMORYENTRY3 (136U)
#define NVM_BLOCKID_NVMBLOCK137_DEM_EVENTMEMORYENTRY4 (137U)
#define NVM_BLOCKID_NVMBLOCK138_DEM_EVENTMEMORYENTRY5 (138U)
#define NVM_BLOCKID_NVMBLOCK139_DEM_EVENTMEMORYENTRY6 (139U)
#define NVM_BLOCKID_NVMBLOCK140_DEM_EVENTMEMORYENTRY7 (140U)
#define NVM_BLOCKID_NVMBLOCK141_DEM_EVENTMEMORYENTRY8 (141U)
#define NVM_BLOCKID_NVMBLOCK142_DEM_EVENTMEMORYENTRY9 (142U)
#define NVM_BLOCKID_NVMBLOCK143_DEM_EVENTMEMORYENTRY10 (143U)
#define NVM_BLOCKID_NVMBLOCK144_DID_0XF199 (144U)
#define NVM_BLOCKID_NVMBLOCK145_DID_0XF190 (145U)
#define NVM_BLOCKID_NVMBLOCK146_DID_0XF1A2 (146U)
#define NVM_BLOCKID_NVMBLOCK147_DID_0XF112 (147U)
#define NVM_BLOCKID_NVMBLOCK148_DID_0XF198 (148U)
#define NVM_BLOCKID_NVMBLOCK149_DID_0XF197 (149U)
#define NVM_BLOCKID_NVMBLOCK150_DID_0XDFEC (150U)
#define NVM_BLOCKID_NVMBLOCK151_DID_0XDFED (151U)
#define NVM_BLOCKID_NVMBLOCK152_DID_0XDFEE (152U)
#define NVM_BLOCKID_NVMBLOCK153_DID_0XDFEF (153U)
#define NVM_BLOCKID_NVMBLOCK154_DID_0XF101 (154U)
#define NVM_BLOCKID_NVMBLOCK155_DID_0XF110 (155U)
#define NVM_BLOCKID_NVMBLOCK156_DID_0XD135 (156U)
#define NVM_BLOCKID_NVMBLOCK157_DID_0XD136 (157U)
#define NVM_BLOCKID_NVMBLOCK158_DID_0X0280 (158U)
#define NVM_BLOCKID_NVMBLOCK159_DID_0X05D5 (159U)
#define NVM_BLOCKID_NVMBLOCK160_DID_0X05D6 (160U)
#define NVM_BLOCKID_NVMBLOCK161_DID_0X05D7 (161U)
#define NVM_BLOCKID_NVMBLOCK162_DID_0X05D8 (162U)
#define NVM_BLOCKID_NVMBLOCK163_DID_0X05D9 (163U)
#define NVM_BLOCKID_NVMBLOCK164_DID_0X05DA (164U)
#define NVM_BLOCKID_NVMBLOCK165_DID_0X05DB (165U)
#define NVM_BLOCKID_NVMBLOCK166_DID_0XF187 (166U)
#define NVM_BLOCKID_NVMBLOCK167_DID_0XF18C (167U)
#define NVM_BLOCKID_NVMBLOCK168_DID_0XF18A (168U)
#define NVM_BLOCKID_NVMBLOCK169_DID_0XF191 (169U)
#define NVM_BLOCKID_NVMBLOCK170_DID_0XF189 (170U)
#define NVM_BLOCKID_NVMBLOCK171_DID_0XF193 (171U)
#define NVM_BLOCKID_NVMBLOCK172_DID_0XF195 (172U)
#define NVM_BLOCKID_NVMBLOCK173_DID_0XF180 (173U)
#define NVM_BLOCKID_NVMBLOCK174_DID_0XF113 (174U)
#define NVM_BLOCKID_NVMBLOCK175_DID_0XF182 (175U)
#define NVM_BLOCKID_NVMBLOCK176_DID_0XF186 (176U)
#define NVM_BLOCKID_NVMBLOCK177_DID_0XF18B (177U)
#define NVM_BLOCKID_NVMBLOCK178_DID_0X0200 (178U)
#define NVM_BLOCKID_NVMBLOCK179_DID_0X0201 (179U)
#define NVM_BLOCKID_NVMBLOCK180_DID_0XF1A3 (180U)
#define NVM_BLOCKID_NVMBLOCK181_DID_0XF1A4 (181U)
#define NVM_BLOCKID_NVMBLOCK182_DID_0XF1A5 (182U)
#define NVM_BLOCKID_NVMBLOCK183_DID_0XF800 (183U)
#define NVM_BLOCKID_NVMBLOCK184_DID_0XF802 (184U)
#define NVM_BLOCKID_NVMBLOCK185_SERVICE0X14_COUNT (185U)
#define NVM_STOP_SERVICES                                    (STD_OFF)
#define NVM_BLOCKID_MULTI            (0U)
#define NVM_BLOCKID_CONFIGURE        (1U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_NvM_2.5" */
/* polyspace-begin MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
#define NVM_SIZEOF_RAMBLOCK_LENGTH_2             EEPROM_BLOCK2_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_3             EEPROM_BLOCK3_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_4             EEPROM_BLOCK4_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_5             EEPROM_BLOCK5_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_6             EEPROM_BLOCK6_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_7             EEPROM_BLOCK7_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_8             EEPROM_BLOCK8_9_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_9             EEPROM_BLOCK8_9_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_10            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_11            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_12            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_13            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_14            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_15            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_16            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_17            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_18            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_19            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_20            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_21            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_22            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_23            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_24            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_25            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_26            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_27            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_28            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_29            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_30            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_31            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_32            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_33            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_34            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_35            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_36            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_37            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_38            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_39            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_40            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_41            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_42            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_43            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_44            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_45            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_46            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_47            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_48            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_49            EEPROM_BLOCK10_49_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_50            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_51            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_52            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_53            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_54            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_55            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_56            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_57            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_58            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_59            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_60            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_61            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_62            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_63            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_64            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_65            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_66            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_67            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_68            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_69            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_70            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_71            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_72            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_73            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_74            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_75            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_76            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_77            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_78            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_79            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_80            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_81            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_82            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_83            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_84            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_85            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_86            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_87            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_88            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_89            EEPROM_BLOCK50_89_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_90            EEPROM_BLOCK90_96_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_91            EEPROM_BLOCK90_96_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_92            EEPROM_BLOCK90_96_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_93            EEPROM_BLOCK90_96_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_94            EEPROM_BLOCK90_96_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_95            EEPROM_BLOCK90_96_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_96            EEPROM_BLOCK90_96_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_97            EEPROM_BLOCK97_100_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_98            EEPROM_BLOCK97_100_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_99            EEPROM_BLOCK97_100_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_100           EEPROM_BLOCK97_100_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_101           EEPROM_BLOCK101_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_102           EEPROM_BLOCK102_105_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_103           EEPROM_BLOCK102_105_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_104           EEPROM_BLOCK102_105_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_105           EEPROM_BLOCK102_105_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_106           EEPROM_BLOCK106_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_107           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_108           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_109           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_110           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_111           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_112           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_113           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_114           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_115           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_116           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_117           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_118           EEPROM_BLOCK107_118_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_119           EEPROM_BLOCK119_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_120           EEPROM_BLOCK120_127_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_121           EEPROM_BLOCK120_127_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_122           EEPROM_BLOCK120_127_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_123           EEPROM_BLOCK120_127_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_124           EEPROM_BLOCK120_127_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_125           EEPROM_BLOCK120_127_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_126           EEPROM_BLOCK120_127_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_127           EEPROM_BLOCK120_127_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_128			 EEPROM_BLOCK128_131_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_129			 EEPROM_BLOCK128_131_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_130			 EEPROM_BLOCK128_131_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_131			 EEPROM_BLOCK128_131_RAM_SIZE
#define NVM_SIZEOF_RAMBLOCK_LENGTH_132           (sizeof(Dem_EventMemoryStatus))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_133           (sizeof(Dem_PrimaryEventMemoryInfo))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_134           (sizeof(Dem_PrimaryEventMemoryEntry[0]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_135           (sizeof(Dem_PrimaryEventMemoryEntry[1]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_136           (sizeof(Dem_PrimaryEventMemoryEntry[2]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_137           (sizeof(Dem_PrimaryEventMemoryEntry[3]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_138           (sizeof(Dem_PrimaryEventMemoryEntry[4]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_139           (sizeof(Dem_PrimaryEventMemoryEntry[5]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_140           (sizeof(Dem_PrimaryEventMemoryEntry[6]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_141           (sizeof(Dem_PrimaryEventMemoryEntry[7]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_142           (sizeof(Dem_PrimaryEventMemoryEntry[8]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_143           (sizeof(Dem_PrimaryEventMemoryEntry[9]))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_144           (sizeof(Dcm_Did_Block0090_Data.Dcm_DidF199Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_145           (sizeof(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_146           (sizeof(Dcm_Did_Block0092_Data.Dcm_DidF1A2Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_147           (sizeof(Dcm_Did_Block0093_Data.Dcm_DidF112Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_148           (sizeof(Dcm_Did_Block0094_Data.Dcm_DidF198Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_149           (sizeof(Dcm_Did_Block0095_Data.Dcm_DidF197Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_150           (sizeof(Dcm_Did_Block0096_Data.Dcm_DidDFECBuffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_151           (sizeof(Dcm_Did_Block0097_Data.Dcm_DidDFEDBuffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_152           (sizeof(Dcm_Did_Block0098_Data.Dcm_DidDFEEBuffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_153           (sizeof(Dcm_Did_Block0099_Data.Dcm_DidDFEFBuffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_154           (sizeof(Dcm_Did_Block009A_Data.Dcm_DidF101Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_155           (sizeof(Dcm_Did_Block009B_Data.Dcm_DidF110Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_156           (sizeof(Dcm_Did_Block009C_Data.Dcm_DidD135Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_157           (sizeof(Dcm_Did_Block009D_Data.Dcm_DidD136Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_158           (sizeof(Dcm_Did_Block009E_Data.Dcm_Did0280Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_159           (sizeof(Dcm_Did_Block009F_Data.Dcm_Did05D5Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_160           (sizeof(Dcm_Did_Block00A0_Data.Dcm_Did05D6Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_161           (sizeof(Dcm_Did_Block00A1_Data.Dcm_Did05D7Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_162           (sizeof(Dcm_Did_Block00A2_Data.Dcm_Did05D8Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_163           (sizeof(Dcm_Did_Block00A3_Data.Dcm_Did05D9Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_164           (sizeof(Dcm_Did_Block00A4_Data.Dcm_Did05DABuffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_165           (sizeof(Dcm_Did_Block00A5_Data.Dcm_Did05DBBuffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_166           (sizeof(Dcm_Did_Block00A6_Data.Dcm_DidF187Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_167           (sizeof(Dcm_Did_Block00A7_Data.Dcm_DidF18CBuffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_168           (sizeof(Dcm_Did_Block00A8_Data.Dcm_DidF18ABuffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_169           (sizeof(Dcm_Did_Block00A9_Data.Dcm_DidF191Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_170           (sizeof(Dcm_Did_Block00AA_Data.Dcm_DidF189Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_171           (sizeof(Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_172           (sizeof(Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_173           (sizeof(Dcm_Did_Block00AD_Data.Dcm_DidF180Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_174           (sizeof(Dcm_Did_Block00AE_Data.Dcm_DidF113Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_175           (sizeof(Dcm_Did_Block00AF_Data.Dcm_DidF182Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_176           (sizeof(Dcm_Did_Block00B0_Data.Dcm_DidF186Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_177           (sizeof(Dcm_Did_Block00B1_Data.Dcm_DidF18BBuffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_178           (sizeof(Dcm_Did_Block00B2_Data.Dcm_Did0200Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_179           (sizeof(Dcm_Did_Block00B3_Data.Dcm_Did0201Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_180           (sizeof(Dcm_Did_Block00B4_Data.Dcm_DidF1A3Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_181           (sizeof(Dcm_Did_Block00B5_Data.Dcm_DidF1A4Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_182           (sizeof(Dcm_Did_Block00B6_Data.Dcm_DidF1A5Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_183           (sizeof(Dcm_Did_Block00B7_Data.Dcm_DidF800Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_184           (sizeof(Dcm_Did_Block00B8_Data.Dcm_DidF802Buffer))
#define NVM_SIZEOF_RAMBLOCK_LENGTH_185           (sizeof(Dcm_Did_Block00B9_Data.Dcm_Service0x14CountBuffer))
/* polyspace-end MISRA-C3:10.3 [Justified:Unset] "NSCA_Polyspace_Common_AutosarBoolean" */
/* polyspace-begin MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_NvM_2.3" polyspace-begin MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_NvM_2.4" polyspace-begin MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_NvM_14.3" */
#define NVM_RAM_LESS_THAN_NV_132 ((sizeof(Dem_PrimaryEventMemoryInfo) < 40) ? -1 : 1)
struct NvM_BlockLenLessCheck_132_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock133_Dem_EventMemoryInfoLess[NVM_RAM_LESS_THAN_NV_132];
};
#define NVM_RAM_LESS_THAN_NV_133 ((sizeof(Dem_PrimaryEventMemoryEntry[0]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_133_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock134_Dem_EventMemoryEntry1Less[NVM_RAM_LESS_THAN_NV_133];
};
#define NVM_RAM_LESS_THAN_NV_134 ((sizeof(Dem_PrimaryEventMemoryEntry[1]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_134_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock135_Dem_EventMemoryEntry2Less[NVM_RAM_LESS_THAN_NV_134];
};
#define NVM_RAM_LESS_THAN_NV_135 ((sizeof(Dem_PrimaryEventMemoryEntry[2]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_135_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock136_Dem_EventMemoryEntry3Less[NVM_RAM_LESS_THAN_NV_135];
};
#define NVM_RAM_LESS_THAN_NV_136 ((sizeof(Dem_PrimaryEventMemoryEntry[3]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_136_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock137_Dem_EventMemoryEntry4Less[NVM_RAM_LESS_THAN_NV_136];
};
#define NVM_RAM_LESS_THAN_NV_137 ((sizeof(Dem_PrimaryEventMemoryEntry[4]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_137_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock138_Dem_EventMemoryEntry5Less[NVM_RAM_LESS_THAN_NV_137];
};
#define NVM_RAM_LESS_THAN_NV_138 ((sizeof(Dem_PrimaryEventMemoryEntry[5]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_138_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock139_Dem_EventMemoryEntry6Less[NVM_RAM_LESS_THAN_NV_138];
};
#define NVM_RAM_LESS_THAN_NV_139 ((sizeof(Dem_PrimaryEventMemoryEntry[6]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_139_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock140_Dem_EventMemoryEntry7Less[NVM_RAM_LESS_THAN_NV_139];
};
#define NVM_RAM_LESS_THAN_NV_140 ((sizeof(Dem_PrimaryEventMemoryEntry[7]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_140_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock141_Dem_EventMemoryEntry8Less[NVM_RAM_LESS_THAN_NV_140];
};
#define NVM_RAM_LESS_THAN_NV_141 ((sizeof(Dem_PrimaryEventMemoryEntry[8]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_141_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock142_Dem_EventMemoryEntry9Less[NVM_RAM_LESS_THAN_NV_141];
};
#define NVM_RAM_LESS_THAN_NV_142 ((sizeof(Dem_PrimaryEventMemoryEntry[9]) < 864) ? -1 : 1)
struct NvM_BlockLenLessCheck_142_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock143_Dem_EventMemoryEntry10Less[NVM_RAM_LESS_THAN_NV_142];
};
#define NVM_RAM_LESS_THAN_NV_143 ((sizeof(Dcm_Did_Block0090_Data.Dcm_DidF199Buffer) < 4) ? -1 : 1)
struct NvM_BlockLenLessCheck_143_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock144_DID_0xF199Less[NVM_RAM_LESS_THAN_NV_143];
};
#define NVM_RAM_LESS_THAN_NV_144 ((sizeof(Dcm_Did_Block0091_Data.Dcm_DidF190Buffer) < 17) ? -1 : 1)
struct NvM_BlockLenLessCheck_144_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock145_DID_0xF190Less[NVM_RAM_LESS_THAN_NV_144];
};
#define NVM_RAM_LESS_THAN_NV_145 ((sizeof(Dcm_Did_Block0092_Data.Dcm_DidF1A2Buffer) < 4) ? -1 : 1)
struct NvM_BlockLenLessCheck_145_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock146_DID_0xF1A2Less[NVM_RAM_LESS_THAN_NV_145];
};
#define NVM_RAM_LESS_THAN_NV_146 ((sizeof(Dcm_Did_Block0093_Data.Dcm_DidF112Buffer) < 8) ? -1 : 1)
struct NvM_BlockLenLessCheck_146_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock147_DID_0xF112Less[NVM_RAM_LESS_THAN_NV_146];
};
#define NVM_RAM_LESS_THAN_NV_147 ((sizeof(Dcm_Did_Block0094_Data.Dcm_DidF198Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_147_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock148_DID_0xF198Less[NVM_RAM_LESS_THAN_NV_147];
};
#define NVM_RAM_LESS_THAN_NV_148 ((sizeof(Dcm_Did_Block0095_Data.Dcm_DidF197Buffer) < 8) ? -1 : 1)
struct NvM_BlockLenLessCheck_148_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock149_DID_0xF197Less[NVM_RAM_LESS_THAN_NV_148];
};
#define NVM_RAM_LESS_THAN_NV_149 ((sizeof(Dcm_Did_Block0096_Data.Dcm_DidDFECBuffer) < 64) ? -1 : 1)
struct NvM_BlockLenLessCheck_149_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock150_DID_0xDFECLess[NVM_RAM_LESS_THAN_NV_149];
};
#define NVM_RAM_LESS_THAN_NV_150 ((sizeof(Dcm_Did_Block0097_Data.Dcm_DidDFEDBuffer) < 64) ? -1 : 1)
struct NvM_BlockLenLessCheck_150_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock151_DID_0xDFEDLess[NVM_RAM_LESS_THAN_NV_150];
};
#define NVM_RAM_LESS_THAN_NV_151 ((sizeof(Dcm_Did_Block0098_Data.Dcm_DidDFEEBuffer) < 64) ? -1 : 1)
struct NvM_BlockLenLessCheck_151_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock152_DID_0xDFEELess[NVM_RAM_LESS_THAN_NV_151];
};
#define NVM_RAM_LESS_THAN_NV_152 ((sizeof(Dcm_Did_Block0099_Data.Dcm_DidDFEFBuffer) < 64) ? -1 : 1)
struct NvM_BlockLenLessCheck_152_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock153_DID_0xDFEFLess[NVM_RAM_LESS_THAN_NV_152];
};
#define NVM_RAM_LESS_THAN_NV_153 ((sizeof(Dcm_Did_Block009A_Data.Dcm_DidF101Buffer) < 8) ? -1 : 1)
struct NvM_BlockLenLessCheck_153_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock154_DID_0xF101Less[NVM_RAM_LESS_THAN_NV_153];
};
#define NVM_RAM_LESS_THAN_NV_154 ((sizeof(Dcm_Did_Block009B_Data.Dcm_DidF110Buffer) < 8) ? -1 : 1)
struct NvM_BlockLenLessCheck_154_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock155_DID_0xF110Less[NVM_RAM_LESS_THAN_NV_154];
};
#define NVM_RAM_LESS_THAN_NV_155 ((sizeof(Dcm_Did_Block009C_Data.Dcm_DidD135Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_155_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock156_DID_0xD135Less[NVM_RAM_LESS_THAN_NV_155];
};
#define NVM_RAM_LESS_THAN_NV_156 ((sizeof(Dcm_Did_Block009D_Data.Dcm_DidD136Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_156_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock157_DID_0xD136Less[NVM_RAM_LESS_THAN_NV_156];
};
#define NVM_RAM_LESS_THAN_NV_157 ((sizeof(Dcm_Did_Block009E_Data.Dcm_Did0280Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_157_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock158_DID_0x0280Less[NVM_RAM_LESS_THAN_NV_157];
};
#define NVM_RAM_LESS_THAN_NV_158 ((sizeof(Dcm_Did_Block009F_Data.Dcm_Did05D5Buffer) < 4) ? -1 : 1)
struct NvM_BlockLenLessCheck_158_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock159_DID_0x05D5Less[NVM_RAM_LESS_THAN_NV_158];
};
#define NVM_RAM_LESS_THAN_NV_159 ((sizeof(Dcm_Did_Block00A0_Data.Dcm_Did05D6Buffer) < 4) ? -1 : 1)
struct NvM_BlockLenLessCheck_159_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock160_DID_0x05D6Less[NVM_RAM_LESS_THAN_NV_159];
};
#define NVM_RAM_LESS_THAN_NV_160 ((sizeof(Dcm_Did_Block00A1_Data.Dcm_Did05D7Buffer) < 3) ? -1 : 1)
struct NvM_BlockLenLessCheck_160_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock161_DID_0x05D7Less[NVM_RAM_LESS_THAN_NV_160];
};
#define NVM_RAM_LESS_THAN_NV_161 ((sizeof(Dcm_Did_Block00A2_Data.Dcm_Did05D8Buffer) < 2) ? -1 : 1)
struct NvM_BlockLenLessCheck_161_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock162_DID_0x05D8Less[NVM_RAM_LESS_THAN_NV_161];
};
#define NVM_RAM_LESS_THAN_NV_162 ((sizeof(Dcm_Did_Block00A3_Data.Dcm_Did05D9Buffer) < 1) ? -1 : 1)
struct NvM_BlockLenLessCheck_162_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock163_DID_0x05D9Less[NVM_RAM_LESS_THAN_NV_162];
};
#define NVM_RAM_LESS_THAN_NV_163 ((sizeof(Dcm_Did_Block00A4_Data.Dcm_Did05DABuffer) < 1) ? -1 : 1)
struct NvM_BlockLenLessCheck_163_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock164_DID_0x05DALess[NVM_RAM_LESS_THAN_NV_163];
};
#define NVM_RAM_LESS_THAN_NV_164 ((sizeof(Dcm_Did_Block00A5_Data.Dcm_Did05DBBuffer) < 24) ? -1 : 1)
struct NvM_BlockLenLessCheck_164_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock165_DID_0x05DBLess[NVM_RAM_LESS_THAN_NV_164];
};
#define NVM_RAM_LESS_THAN_NV_165 ((sizeof(Dcm_Did_Block00A6_Data.Dcm_DidF187Buffer) < 21) ? -1 : 1)
struct NvM_BlockLenLessCheck_165_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock166_DID_0xF187Less[NVM_RAM_LESS_THAN_NV_165];
};
#define NVM_RAM_LESS_THAN_NV_166 ((sizeof(Dcm_Did_Block00A7_Data.Dcm_DidF18CBuffer) < 24) ? -1 : 1)
struct NvM_BlockLenLessCheck_166_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock167_DID_0xF18CLess[NVM_RAM_LESS_THAN_NV_166];
};
#define NVM_RAM_LESS_THAN_NV_167 ((sizeof(Dcm_Did_Block00A8_Data.Dcm_DidF18ABuffer) < 6) ? -1 : 1)
struct NvM_BlockLenLessCheck_167_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock168_DID_0xF18ALess[NVM_RAM_LESS_THAN_NV_167];
};
#define NVM_RAM_LESS_THAN_NV_168 ((sizeof(Dcm_Did_Block00A9_Data.Dcm_DidF191Buffer) < 10) ? -1 : 1)
struct NvM_BlockLenLessCheck_168_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock169_DID_0xF191Less[NVM_RAM_LESS_THAN_NV_168];
};
#define NVM_RAM_LESS_THAN_NV_169 ((sizeof(Dcm_Did_Block00AA_Data.Dcm_DidF189Buffer) < 10) ? -1 : 1)
struct NvM_BlockLenLessCheck_169_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock170_DID_0xF189Less[NVM_RAM_LESS_THAN_NV_169];
};
#define NVM_RAM_LESS_THAN_NV_170 ((sizeof(Dcm_Did_Block00AB_Data.Dcm_DidF193Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_170_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock171_DID_0xF193Less[NVM_RAM_LESS_THAN_NV_170];
};
#define NVM_RAM_LESS_THAN_NV_171 ((sizeof(Dcm_Did_Block00AC_Data.Dcm_DidF195Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_171_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock172_DID_0xF195Less[NVM_RAM_LESS_THAN_NV_171];
};
#define NVM_RAM_LESS_THAN_NV_172 ((sizeof(Dcm_Did_Block00AD_Data.Dcm_DidF180Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_172_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock173_DID_0xF180Less[NVM_RAM_LESS_THAN_NV_172];
};
#define NVM_RAM_LESS_THAN_NV_173 ((sizeof(Dcm_Did_Block00AE_Data.Dcm_DidF113Buffer) < 4) ? -1 : 1)
struct NvM_BlockLenLessCheck_173_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock174_DID_0xF113Less[NVM_RAM_LESS_THAN_NV_173];
};
#define NVM_RAM_LESS_THAN_NV_174 ((sizeof(Dcm_Did_Block00AF_Data.Dcm_DidF182Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_174_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock175_DID_0xF182Less[NVM_RAM_LESS_THAN_NV_174];
};
#define NVM_RAM_LESS_THAN_NV_175 ((sizeof(Dcm_Did_Block00B0_Data.Dcm_DidF186Buffer) < 1) ? -1 : 1)
struct NvM_BlockLenLessCheck_175_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock176_DID_0xF186Less[NVM_RAM_LESS_THAN_NV_175];
};
#define NVM_RAM_LESS_THAN_NV_176 ((sizeof(Dcm_Did_Block00B1_Data.Dcm_DidF18BBuffer) < 4) ? -1 : 1)
struct NvM_BlockLenLessCheck_176_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock177_DID_0xF18BLess[NVM_RAM_LESS_THAN_NV_176];
};
#define NVM_RAM_LESS_THAN_NV_177 ((sizeof(Dcm_Did_Block00B2_Data.Dcm_Did0200Buffer) < 1) ? -1 : 1)
struct NvM_BlockLenLessCheck_177_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock178_DID_0x0200Less[NVM_RAM_LESS_THAN_NV_177];
};
#define NVM_RAM_LESS_THAN_NV_178 ((sizeof(Dcm_Did_Block00B3_Data.Dcm_Did0201Buffer) < 1) ? -1 : 1)
struct NvM_BlockLenLessCheck_178_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock179_DID_0x0201Less[NVM_RAM_LESS_THAN_NV_178];
};
#define NVM_RAM_LESS_THAN_NV_179 ((sizeof(Dcm_Did_Block00B4_Data.Dcm_DidF1A3Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_179_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock180_DID_0xF1A3Less[NVM_RAM_LESS_THAN_NV_179];
};
#define NVM_RAM_LESS_THAN_NV_180 ((sizeof(Dcm_Did_Block00B5_Data.Dcm_DidF1A4Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_180_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock181_DID_0xF1A4Less[NVM_RAM_LESS_THAN_NV_180];
};
#define NVM_RAM_LESS_THAN_NV_181 ((sizeof(Dcm_Did_Block00B6_Data.Dcm_DidF1A5Buffer) < 16) ? -1 : 1)
struct NvM_BlockLenLessCheck_181_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock182_DID_0xF1A5Less[NVM_RAM_LESS_THAN_NV_181];
};
#define NVM_RAM_LESS_THAN_NV_182 ((sizeof(Dcm_Did_Block00B7_Data.Dcm_DidF800Buffer) < 4) ? -1 : 1)
struct NvM_BlockLenLessCheck_182_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock183_DID_0xF800Less[NVM_RAM_LESS_THAN_NV_182];
};
#define NVM_RAM_LESS_THAN_NV_183 ((sizeof(Dcm_Did_Block00B8_Data.Dcm_DidF802Buffer) < 17) ? -1 : 1)
struct NvM_BlockLenLessCheck_183_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock184_DID_0xF802Less[NVM_RAM_LESS_THAN_NV_183];
};
#define NVM_RAM_LESS_THAN_NV_184 ((sizeof(Dcm_Did_Block00B9_Data.Dcm_Service0x14CountBuffer) < 1) ? -1 : 1)
struct NvM_BlockLenLessCheck_184_Type
{
	/* Error: The size of NvMRamBlockDataAddress is less than NvMNvBlockLength. */
	uint8 NvMBlock185_Service0x14_CountLess[NVM_RAM_LESS_THAN_NV_184];
};
/* polyspace-end MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_NvM_2.3" polyspace-end MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_NvM_2.4" polyspace-end MISRA-C3:14.3 [Justified:Unset] "NSCA_Polyspace_NvM_14.3" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define NVM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

extern VAR(uint8, NVM_VAR_INIT) NvM_CompiledConfigId[NVM_COMPILEDCONFIGID_LENGHT];

#define NVM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

#define NVM_START_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

extern VAR(Nvm_BlockManagment_st, NVM_VAR_NO_INIT) NvM_gstaBlockVar[NVM_NUM_OF_BLOCK_TOTAL];
extern VAR(Nvm_BlockAdministrator_st, NVM_VAR_NO_INIT) NvM_gstaBlockAdmini[NVM_NUM_OF_BLOCK_TOTAL];
extern VAR(uint8, NVM_VAR_NO_INIT) Nvm_InternalBuffer[NVM_BLOCK_MAX_LENGTH];

#define NVM_STOP_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define NVM_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

extern CONST(NvM_Block_Descriptor_Table_st, NVM_CONFIG_DATA) NvM_Block_Descriptor_Table[NVM_NUM_OF_BLOCK_TOTAL];

#define NVM_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NvM_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_Rule20.1 */

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* NVM_CFG_H_ */

