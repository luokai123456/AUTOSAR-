/*
********************************************************************************
*
* File name: Dem_Lcfg.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJP/2021.08.14
* Change: New
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: LQiao/2023.01.13
* Change: Add Includes.
* Cause: Bugfix
********************************************************************************
* Version: 3.1
* Author/Date: ZengJX/2024.07.18
* Change: 1.Modify copyright information.
*         2.Fix Dem memmap issue.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: ZengJX/2024.08.22
* Change: Modify copyright information.
* Cause: Bugfix
********************************************************************************
* Version: 3.3
* Author/Date: ZengJX/2025.05.06
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Optimization
********************************************************************************
*/
#ifndef DEM_LCFG_H_
#define DEM_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dem_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Configurations of component */
#define DEM_CFG_COMP_NUM                                    (0U)
#define DEM_CFG_MAX_CHILD_COMP_NUM                          (1U)
/* Configurations of Operation Cycles */
#define DEM_CFG_OPCYC_NUM                                   (1U)
/* Configurations of DTC list */
#define DEM_CFG_DTC_NUM                                     (248U)
#define DEM_CFG_DTC_GROUP_NUM                               (0U)
#define DEM_CFG_COMB_DTC_MAX_EVENT_NUM                      (1U)
/* Configurations of Supported Event Memory */
#define DEM_CFG_EVENT_MEMORY_NUM                            (1U)
#define DEM_CFG_PRIMARY_MAX_NUMBER_EVENT_ENTRY              (10U)
#define DEM_CFG_USER0_MAX_NUMBER_EVENT_ENTRY                (1U)
#define DEM_CFG_USER1_MAX_NUMBER_EVENT_ENTRY                (1U)
#define DEM_CFG_MAX_NUMBER_EVENT_ENTRY                      (10U)
/* Configurations of Event list ***/
#define DEM_CFG_EVENT_NUM                                   (248U)
#define DEM_CFG_EVENT_ID_MAX                                (32983U)
#define DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM                 (1U)
/* Configurations of Debounce counter */
#define DEM_CFG_DEBOUNCE_COUNTER_NUM                        (1U)
#define DEM_CFG_DEBOUNCE_TIME_NUM                           (0U)
/* Configurations of OBD DTC */
#define DEM_CFG_OBD_DTC_NUM                                 (0U)
#define DEM_CFG_OBD_PID_DATA_NUM                            (0U)
#define DEM_CFG_PID_MAX_REF_DATA_ELEMENT_NUM                (1U)
/* Configurations of data element */
#define DEM_CFG_DATA_ELEMENT_NUM                            (115U)
#define DEM_CFG_DID_NUM                                     (113U)
#define DEM_CFG_DID_MAX_REF_DATA_ELEMENT_NUM                (1U)
#define DEM_CFG_EXDATA_NUM                                  (1U)
#define DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM            (2U)
#define DEM_CFG_EXDATA_RECORD_NUM                           (2U)
#define DEM_CFG_EXDATA_MAX_REF_DATA_ELEMENT_NUM             (1U)
#define DEM_CFG_FFDATA_NUM                                  (21U)
#define DEM_CFG_FFDATA_MAX_REF_DID_NUM                      (84U)
#define DEM_CFG_FFDATA_RECORDNUM_NUM                        (12U)
#define DEM_CFG_FFDATA_MAX_REF_RECORD_NUM                   (6U)
#define DEM_CFG_FFDATA_RECORD_NUM                           (9U)
/* Enable Condition Configurations */
#define DEM_CFG_ENCOND_NUM                                  (1U)
#define DEM_CFG_ENCOND_GROUP_NUM                            (1U)
#define DEM_CFG_ENCONDGRP_MAX_REF_ENCOND_NUM                (1U)
/* Storage Condition Configurations */
#define DEM_CFG_STORCOND_NUM                                (0U)
#define DEM_CFG_STORCOND_GROUP_NUM                          (0U)
#define DEM_CFG_STORCONDGRP_MAX_REF_STORCOND_NUM            (1U)
/* Indicator Configurations */
#define DEM_CFG_INDICATOR_NUM                               (0U)
/* Nvm Block Configurations */
#define DEM_CFG_NVM_BLOCK_NUM                               (12U)
/* Callback of DTC status changed Configurations */
#define DEM_CFG_DTC_STATUS_CHANGED_CALLBACK_NUM             (1U)
/* Ratio for OBD Configurations */
#define DEM_CFG_OBD_RATIO_NUM                               (0U)
#define DEM_CFG_MAX_SECOND_FIM_FUNC_NUM                     (1U)
/* OBD DTC status changed callback configurations */
#define DEM_CFG_OBDDTC_STATUS_CHANGED_CALLBACK_NUM          (0U)
/* Dtr configtrations */
#define DEM_CFG_DTR_NUM                                     (0U)

/* Freeze Frame Data/Extended Data max bytes for 1 DTC */
#define DEM_CFG_EXDATA_MAX_BYTES                            (2U)
#define DEM_CFG_FFDATA_MAX_BYTES                            (840U)

/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Dem_2.5" */
/* Configur Event ID */
#define DEM_Parameters_2AD4A2 (32876U)
#define DEM_Parameters_2AD5A3 (32877U)
#define DEM_Parameters_140149 (32878U)
#define DEM_Parameters_140249 (32879U)
#define DEM_Parameters_212C11 (32880U)
#define DEM_Parameters_212D12 (32881U)
#define DEM_Parameters_212B16 (32882U)
#define DEM_Parameters_212B17 (32883U)
#define DEM_Parameters_213211 (32884U)
#define DEM_Parameters_213312 (32885U)
#define DEM_Parameters_213116 (32886U)
#define DEM_Parameters_213117 (32887U)
#define DEM_Parameters_212F64 (32888U)
#define DEM_Parameters_050464 (32935U)
#define DEM_Parameters_C07388 (32891U)
#define DEM_Parameters_C07588 (32892U)
#define DEM_Parameters_C07488 (32936U)
#define DEM_Parameters_C12187 (32894U)
#define DEM_Parameters_C29887 (32896U)
#define DEM_Parameters_C10387 (32900U)
#define DEM_Parameters_D13487 (32902U)
#define DEM_Parameters_C45281 (32972U)
#define DEM_Parameters_C41381 (32973U)
#define DEM_Parameters_C19A87 (32975U)
#define DEM_Parameters_C41181 (32974U)
#define DEM_Parameters_14DB13 (32913U)
#define DEM_Parameters_14D900 (32914U)
#define DEM_Parameters_14164B (32920U)
#define DEM_Parameters_14174B (32921U)
#define DEM_Parameters_14184B (32922U)
#define DEM_Parameters_14194B (32923U)
#define DEM_Parameters_14204B (32924U)
#define DEM_Parameters_14214B (32925U)
#define DEM_Parameters_14314B (32947U)
#define DEM_Parameters_14324B (32948U)
#define DEM_Parameters_14334B (32949U)
#define DEM_Parameters_14344B (32950U)
#define DEM_Parameters_14354B (32951U)
#define DEM_Parameters_14364B (32952U)
#define DEM_Parameters_D40981 (32945U)
#define DEM_Parameters_149D68 (32955U)
#define DEM_Parameters_149F68 (32956U)
#define DEM_Parameters_149468 (32957U)
#define DEM_Parameters_149868 (32958U)
#define DEM_Parameters_149568 (32959U)
#define DEM_Parameters_14F100 (32982U)
#define DEM_Parameters_14F600 (32915U)
#define DEM_Parameters_14F700 (32916U)
#define DEM_Parameters_14F800 (32917U)
#define DEM_Parameters_14F900 (32918U)
#define DEM_Parameters_14FA00 (32983U)
#define DEM_Parameters_MCU_150016 (3001U)
#define DEM_Parameters_MCU_150119 (3002U)
#define DEM_Parameters_MCU_150219 (3003U)
#define DEM_Parameters_MCU_150317 (3004U)
#define DEM_Parameters_MCU_150417 (3005U)
#define DEM_Parameters_MCU_150616 (3006U)
#define DEM_Parameters_MCU_15094B (3007U)
#define DEM_Parameters_MCU_150A4B (3008U)
#define DEM_Parameters_MCU_150B4B (3009U)
#define DEM_Parameters_MCU_150C4B (3010U)
#define DEM_Parameters_MCU_150D00 (3011U)
#define DEM_Parameters_MCU_150E22 (3012U)
#define DEM_Parameters_MCU_15101C (3013U)
#define DEM_Parameters_MCU_151112 (3014U)
#define DEM_Parameters_MCU_151313 (3015U)
#define DEM_Parameters_MCU_151412 (3016U)
#define DEM_Parameters_MCU_151512 (3017U)
#define DEM_Parameters_MCU_151612 (3018U)
#define DEM_Parameters_MCU_151728 (3019U)
#define DEM_Parameters_MCU_151812 (3020U)
#define DEM_Parameters_MCU_151912 (3021U)
#define DEM_Parameters_MCU_151A28 (3022U)
#define DEM_Parameters_MCU_151B13 (3023U)
#define DEM_Parameters_MCU_151C12 (3024U)
#define DEM_Parameters_MCU_151E03 (3025U)
#define DEM_Parameters_MCU_152071 (3026U)
#define DEM_Parameters_MCU_150796 (3027U)
#define DEM_Parameters_BMS_0AFB01 (2020U)
#define DEM_Parameters_BMS_0AFA01 (2018U)
#define DEM_Parameters_BMS_0A7D02 (2005U)
#define DEM_Parameters_BMS_0A7D01 (2004U)
#define DEM_Parameters_BMS_313B04 (2006U)
#define DEM_Parameters_BMS_311200 (2044U)
#define DEM_Parameters_BMS_0CA600 (2026U)
#define DEM_Parameters_BMS_315D19 (2030U)
#define DEM_Parameters_BMS_0CA701 (2029U)
#define DEM_Parameters_BMS_311519 (2037U)
#define DEM_Parameters_BMS_311419 (2036U)
#define DEM_Parameters_BMS_311119 (2035U)
#define DEM_Parameters_BMS_0A7E02 (2009U)
#define DEM_Parameters_BMS_0A7E01 (2008U)
#define DEM_Parameters_BMS_0A7E00 (2007U)
#define DEM_Parameters_BMS_0AFD00 (2022U)
#define DEM_Parameters_BMS_0DE603 (2040U)
#define DEM_Parameters_BMS_0DE602 (2039U)
#define DEM_Parameters_BMS_0DE601 (2038U)
#define DEM_Parameters_BMS_0DE703 (2043U)
#define DEM_Parameters_BMS_0DE702 (2042U)
#define DEM_Parameters_BMS_0DE701 (2041U)
#define DEM_Parameters_BMS_0DAB01 (2048U)
#define DEM_Parameters_BMS_311602 (2053U)
#define DEM_Parameters_BMS_0AA602 (2014U)
#define DEM_Parameters_BMS_0AA601 (2013U)
#define DEM_Parameters_BMS_311702 (2061U)
#define DEM_Parameters_BMS_312702 (2060U)
#define DEM_Parameters_BMS_313A1A (2080U)
#define DEM_Parameters_BMS_0AA700 (2024U)
#define DEM_Parameters_BMS_313E13 (2104U)
#define DEM_Parameters_BMS_C1A000 (2113U)
#define DEM_Parameters_BMS_D8A487 (2067U)
#define DEM_Parameters_BMS_F00616 (2001U)
#define DEM_Parameters_BMS_F00617 (2002U)
#define DEM_Parameters_BMS_313900 (2079U)
#define DEM_Parameters_BMS_0AA100 (2055U)
#define DEM_Parameters_BMS_0AA000 (2054U)
#define DEM_Parameters_BMS_0AA400 (2012U)
#define DEM_Parameters_BMS_0AA300 (2011U)
#define DEM_Parameters_BMS_313F1F (2153U)
#define DEM_Parameters_BMS_312298 (2155U)
#define DEM_Parameters_BMS_312398 (2154U)
#define DEM_Parameters_BMS_31074B (2032U)
#define DEM_Parameters_BMS_31064B (2033U)
#define DEM_Parameters_BMS_0D0900 (2058U)
#define DEM_Parameters_BMS_0D0800 (2057U)
#define DEM_Parameters_BMS_314149 (2118U)
#define DEM_Parameters_BMS_314249 (2107U)
#define DEM_Parameters_BMS_0AC000 (2015U)
#define DEM_Parameters_BMS_313A49 (2082U)
#define DEM_Parameters_BMS_0AC300 (2016U)
#define DEM_Parameters_BMS_060600 (2003U)
#define DEM_Parameters_BMS_313300 (2073U)
#define DEM_Parameters_BMS_313200 (2072U)
#define DEM_Parameters_BMS_313100 (2071U)
#define DEM_Parameters_BMS_313000 (2093U)
#define DEM_Parameters_BMS_312800 (2068U)
#define DEM_Parameters_BMS_314387 (2158U)
#define DEM_Parameters_BMS_314487 (2159U)
#define DEM_Parameters_BMS_314587 (2160U)
#define DEM_Parameters_BMS_314687 (2161U)
#define DEM_Parameters_BMS_314787 (2162U)
#define DEM_Parameters_BMS_314887 (2163U)
#define DEM_Parameters_BMS_314A87 (2165U)
#define DEM_Parameters_BMS_314B87 (2166U)
#define DEM_Parameters_BMS_314C87 (2167U)
#define DEM_Parameters_BMS_314D87 (2168U)
#define DEM_Parameters_BMS_314E87 (2169U)
#define DEM_Parameters_BMS_314F87 (2170U)
#define DEM_Parameters_BMS_315087 (2171U)
#define DEM_Parameters_BMS_310200 (2070U)
#define DEM_Parameters_BMS_310284 (2103U)
#define DEM_Parameters_BMS_31011C (2051U)
#define DEM_Parameters_BMS_31014B (2101U)
#define DEM_Parameters_BMS_310184 (2102U)
#define DEM_Parameters_BMS_31021C (2105U)
#define DEM_Parameters_BMS_31041C (2106U)
#define DEM_Parameters_BMS_310102 (2108U)
#define DEM_Parameters_BMS_31024B (2109U)
#define DEM_Parameters_BMS_31034B (2110U)
#define DEM_Parameters_BMS_31044B (2111U)
#define DEM_Parameters_BMS_31011B (2114U)
#define DEM_Parameters_BMS_31011A (2115U)
#define DEM_Parameters_BMS_31021A (2116U)
#define DEM_Parameters_BMS_31021B (2117U)
#define DEM_Parameters_BMS_310115 (2119U)
#define DEM_Parameters_BMS_310104 (2125U)
#define DEM_Parameters_BMS_31031C (2126U)
#define DEM_Parameters_BMS_311C96 (2152U)
#define DEM_Parameters_BMS_310287 (2088U)
#define DEM_Parameters_MCU_15A001 (3100U)
#define DEM_Parameters_MCU_15A002 (3101U)
#define DEM_Parameters_MCU_15A003 (3102U)
#define DEM_Parameters_MCU_15A004 (3103U)
#define DEM_Parameters_BSW_160001 (3201U)
#define DEM_Parameters_BSW_160002 (3202U)
#define DEM_Parameters_BSW_160003 (3203U)
#define DEM_Parameters_BSW_160004 (3204U)
#define DEM_Parameters_BSW_160005 (3205U)
#define DEM_Parameters_BSW_160006 (3206U)
#define DEM_Parameters_BSW_160007 (3207U)
#define DEM_Parameters_BSW_160008 (3208U)
#define DEM_Parameters_BSW_160009 (3209U)
#define DEM_Parameters_BSW_16000A (3210U)
#define DEM_Parameters_BSW_16000B (3211U)
#define DEM_Parameters_BSW_16000C (3212U)
#define DEM_Parameters_BSW_16000D (3213U)
#define DEM_Parameters_BSW_16000E (3214U)
#define DEM_Parameters_BSW_16000F (3215U)
#define DEM_Parameters_BSW_160010 (3216U)
#define DEM_Parameters_BSW_160011 (3217U)
#define DEM_Parameters_BSW_160012 (3218U)
#define DEM_Parameters_BSW_160013 (3219U)
#define DEM_Parameters_BSW_160014 (3220U)
#define DEM_Parameters_BSW_160015 (3221U)
#define DEM_Parameters_BSW_160016 (3222U)
#define DEM_Parameters_BSW_160017 (3223U)
#define DEM_Parameters_BSW_160018 (3224U)
#define DEM_Parameters_BSW_160019 (3225U)
#define DEM_Parameters_BSW_16001A (3226U)
#define DEM_Parameters_BSW_16001B (3227U)
#define DEM_Parameters_BSW_16001C (3228U)
#define DEM_Parameters_BSW_16001D (3229U)
#define DEM_Parameters_BSW_16001E (3230U)
#define DEM_Parameters_BSW_16001F (3231U)
#define DEM_Parameters_BSW_160020 (3232U)
#define DEM_Parameters_BSW_160021 (3233U)
#define DEM_Parameters_BSW_160022 (3234U)
#define DEM_Parameters_BSW_160023 (3235U)
#define DEM_Parameters_BSW_160024 (3236U)
#define DEM_Parameters_BSW_160025 (3237U)
#define DEM_Parameters_BSW_160026 (3238U)
#define DEM_Parameters_BSW_160027 (3239U)
#define DEM_Parameters_BSW_160028 (3240U)
#define DEM_Parameters_BSW_160029 (3241U)
#define DEM_Parameters_BSW_16002A (3242U)
#define DEM_Parameters_BSW_16002B (3243U)
#define DEM_Parameters_BSW_16002C (3244U)
#define DEM_Parameters_BSW_16002D (3245U)
#define DEM_Parameters_BSW_16002E (3246U)
#define DEM_Parameters_BSW_16002F (3247U)
#define DEM_Parameters_BSW_160030 (3248U)
#define DEM_Parameters_BSW_160031 (3249U)
#define DEM_Parameters_BSW_160032 (3250U)
#define DEM_Parameters_BSW_160033 (3251U)
#define DEM_Parameters_BSW_160034 (3252U)
#define DEM_Parameters_BSW_160035 (3253U)
#define DEM_Parameters_BSW_160036 (3254U)
#define DEM_Parameters_BSW_160037 (3255U)
#define DEM_Parameters_BSW_160038 (3256U)
#define DEM_Parameters_BSW_160039 (3257U)
#define DEM_Parameters_BSW_16003A (3258U)
#define DEM_Parameters_BSW_16003B (3259U)
#define DEM_Parameters_BSW_16003C (3260U)
#define DEM_Parameters_BSW_16003D (3261U)
#define DEM_Parameters_BSW_16003E (3262U)
#define DEM_Parameters_BSW_16003F (3263U)
#define DEM_Parameters_BSW_160040 (3264U)
#define DEM_Parameters_BSW_160041 (3265U)
#define DEM_Parameters_BSW_160042 (3266U)
#define DEM_Parameters_BSW_160043 (3267U)
#define DEM_Parameters_BSW_160044 (3268U)
#define DEM_Parameters_BSW_160045 (3269U)
#define DEM_Parameters_BSW_160046 (3270U)
#define DEM_Parameters_BSW_160047 (3271U)
#define DEM_Parameters_BSW_160048 (3272U)
#define DEM_Parameters_BSW_160049 (3273U)
#define DEM_Parameters_BSW_16004A (3274U)
#define DEM_Parameters_BSW_16004B (3275U)
#define DEM_DemDTC_2AD4A2 (2806946U)
#define DEM_DemDTC_2AD5A3 (2807203U)
#define DEM_DemDTC_140149 (1311049U)
#define DEM_DemDTC_140249 (1311305U)
#define DEM_DemDTC_212C11 (2173969U)
#define DEM_DemDTC_212D12 (2174226U)
#define DEM_DemDTC_212B16 (2173718U)
#define DEM_DemDTC_212B17 (2173719U)
#define DEM_DemDTC_213211 (2175505U)
#define DEM_DemDTC_213312 (2175762U)
#define DEM_DemDTC_213116 (2175254U)
#define DEM_DemDTC_213117 (2175255U)
#define DEM_DemDTC_212F64 (2174820U)
#define DEM_DemDTC_050464 (328804U)
#define DEM_DemDTC_C07388 (12612488U)
#define DEM_DemDTC_C07588 (12613000U)
#define DEM_DemDTC_C07488 (12612744U)
#define DEM_DemDTC_C12187 (12657031U)
#define DEM_DemDTC_C29887 (12753031U)
#define DEM_DemDTC_C10387 (12649351U)
#define DEM_DemDTC_D13487 (13710471U)
#define DEM_DemDTC_C45281 (12866177U)
#define DEM_DemDTC_C41381 (12850049U)
#define DEM_DemDTC_C19A87 (12688007U)
#define DEM_DemDTC_C41181 (12849537U)
#define DEM_DemDTC_14DB13 (1366803U)
#define DEM_DemDTC_14D900 (1366272U)
#define DEM_DemDTC_14164B (1316427U)
#define DEM_DemDTC_14174B (1316683U)
#define DEM_DemDTC_14184B (1316939U)
#define DEM_DemDTC_14194B (1317195U)
#define DEM_DemDTC_14204B (1318987U)
#define DEM_DemDTC_14214B (1319243U)
#define DEM_DemDTC_14314B (1323339U)
#define DEM_DemDTC_14324B (1323595U)
#define DEM_DemDTC_14334B (1323851U)
#define DEM_DemDTC_14344B (1324107U)
#define DEM_DemDTC_14354B (1324363U)
#define DEM_DemDTC_14364B (1324619U)
#define DEM_DemDTC_D40981 (13896065U)
#define DEM_DemDTC_149D68 (1351016U)
#define DEM_DemDTC_149F68 (1351528U)
#define DEM_DemDTC_149468 (1348712U)
#define DEM_DemDTC_149868 (1349736U)
#define DEM_DemDTC_149568 (1348968U)
#define DEM_DemDTC_14F100 (1372416U)
#define DEM_DemDTC_14F600 (1373696U)
#define DEM_DemDTC_14F700 (1373952U)
#define DEM_DemDTC_14F800 (1374208U)
#define DEM_DemDTC_14F900 (1374464U)
#define DEM_DemDTC_14FA00 (1374720U)
#define DEM_DemMcuDTC_150016 (1376278U)
#define DEM_DemMcuDTC_150119 (1376537U)
#define DEM_DemMcuDTC_150219 (1376793U)
#define DEM_DemMcuDTC_150317 (1377047U)
#define DEM_DemMcuDTC_150417 (1377303U)
#define DEM_DemMcuDTC_150616 (1377814U)
#define DEM_DemMcuDTC_15094B (1378635U)
#define DEM_DemMcuDTC_150A4B (1378891U)
#define DEM_DemMcuDTC_150B4B (1379147U)
#define DEM_DemMcuDTC_150C4B (1379403U)
#define DEM_DemMcuDTC_150D00 (1379584U)
#define DEM_DemMcuDTC_150E22 (1379874U)
#define DEM_DemMcuDTC_15101C (1380380U)
#define DEM_DemMcuDTC_151112 (1380626U)
#define DEM_DemMcuDTC_151313 (1381139U)
#define DEM_DemMcuDTC_151412 (1381394U)
#define DEM_DemMcuDTC_151512 (1381650U)
#define DEM_DemMcuDTC_151612 (1381906U)
#define DEM_DemMcuDTC_151728 (1382184U)
#define DEM_DemMcuDTC_151812 (1382418U)
#define DEM_DemMcuDTC_151912 (1382674U)
#define DEM_DemMcuDTC_151A28 (1382952U)
#define DEM_DemMcuDTC_151B13 (1383187U)
#define DEM_DemMcuDTC_151C12 (1383442U)
#define DEM_DemMcuDTC_151E03 (1383939U)
#define DEM_DemMcuDTC_152071 (1384561U)
#define DEM_DemMcuDTC_150796 (1378198U)
#define DEM_DemBmsDTC_0AFB01 (719617U)
#define DEM_DemBmsDTC_0AFA01 (719361U)
#define DEM_DemBmsDTC_0A7D02 (687362U)
#define DEM_DemBmsDTC_0A7D01 (687361U)
#define DEM_DemBmsDTC_313B04 (3226372U)
#define DEM_DemBmsDTC_311200 (3215872U)
#define DEM_DemBmsDTC_0CA600 (828928U)
#define DEM_DemBmsDTC_315D19 (3235097U)
#define DEM_DemBmsDTC_0CA701 (829185U)
#define DEM_DemBmsDTC_311519 (3216665U)
#define DEM_DemBmsDTC_311419 (3216409U)
#define DEM_DemBmsDTC_311119 (3215641U)
#define DEM_DemBmsDTC_0A7E02 (687618U)
#define DEM_DemBmsDTC_0A7E01 (687617U)
#define DEM_DemBmsDTC_0A7E00 (687616U)
#define DEM_DemBmsDTC_0AFD00 (720128U)
#define DEM_DemBmsDTC_0DE603 (910851U)
#define DEM_DemBmsDTC_0DE602 (910850U)
#define DEM_DemBmsDTC_0DE601 (910849U)
#define DEM_DemBmsDTC_0DE703 (911107U)
#define DEM_DemBmsDTC_0DE702 (911106U)
#define DEM_DemBmsDTC_0DE701 (911105U)
#define DEM_DemBmsDTC_0DAB01 (895745U)
#define DEM_DemBmsDTC_311602 (3216898U)
#define DEM_DemBmsDTC_0AA602 (697858U)
#define DEM_DemBmsDTC_0AA601 (697857U)
#define DEM_DemBmsDTC_311702 (3217154U)
#define DEM_DemBmsDTC_312702 (3221250U)
#define DEM_DemBmsDTC_313A1A (3226138U)
#define DEM_DemBmsDTC_0AA700 (698112U)
#define DEM_DemBmsDTC_313E13 (3227155U)
#define DEM_DemBmsDTC_C1A000 (12689408U)
#define DEM_DemBmsDTC_D8A487 (14197895U)
#define DEM_DemBmsDTC_F00616 (15730198U)
#define DEM_DemBmsDTC_F00617 (15730199U)
#define DEM_DemBmsDTC_313900 (3225856U)
#define DEM_DemBmsDTC_0AA100 (696576U)
#define DEM_DemBmsDTC_0AA000 (696320U)
#define DEM_DemBmsDTC_0AA400 (697344U)
#define DEM_DemBmsDTC_0AA300 (697088U)
#define DEM_DemBmsDTC_313F1F (3227423U)
#define DEM_DemBmsDTC_312298 (3220120U)
#define DEM_DemBmsDTC_312398 (3220376U)
#define DEM_DemBmsDTC_31074B (3213131U)
#define DEM_DemBmsDTC_31064B (3212875U)
#define DEM_DemBmsDTC_0D0900 (854272U)
#define DEM_DemBmsDTC_0D0800 (854016U)
#define DEM_DemBmsDTC_314149 (3227977U)
#define DEM_DemBmsDTC_314249 (3228233U)
#define DEM_DemBmsDTC_0AC000 (704512U)
#define DEM_DemBmsDTC_313A49 (3226185U)
#define DEM_DemBmsDTC_0AC300 (705280U)
#define DEM_DemBmsDTC_060600 (394752U)
#define DEM_DemBmsDTC_313300 (3224320U)
#define DEM_DemBmsDTC_313200 (3224064U)
#define DEM_DemBmsDTC_313100 (3223808U)
#define DEM_DemBmsDTC_313000 (3223552U)
#define DEM_DemBmsDTC_312800 (3221504U)
#define DEM_DemBmsDTC_314387 (3228551U)
#define DEM_DemBmsDTC_314487 (3228807U)
#define DEM_DemBmsDTC_314587 (3229063U)
#define DEM_DemBmsDTC_314687 (3229319U)
#define DEM_DemBmsDTC_314787 (3229575U)
#define DEM_DemBmsDTC_314887 (3229831U)
#define DEM_DemBmsDTC_314A87 (3230343U)
#define DEM_DemBmsDTC_314B87 (3230599U)
#define DEM_DemBmsDTC_314C87 (3230855U)
#define DEM_DemBmsDTC_314D87 (3231111U)
#define DEM_DemBmsDTC_314E87 (3231367U)
#define DEM_DemBmsDTC_314F87 (3231623U)
#define DEM_DemBmsDTC_315087 (3231879U)
#define DEM_DemBmsDTC_310200 (3211776U)
#define DEM_DemBmsDTC_310284 (3211908U)
#define DEM_DemBmsDTC_31011C (3211548U)
#define DEM_DemBmsDTC_31014B (3211595U)
#define DEM_DemBmsDTC_310184 (3211652U)
#define DEM_DemBmsDTC_31021C (3211804U)
#define DEM_DemBmsDTC_31041C (3212316U)
#define DEM_DemBmsDTC_310102 (3211522U)
#define DEM_DemBmsDTC_31024B (3211851U)
#define DEM_DemBmsDTC_31034B (3212107U)
#define DEM_DemBmsDTC_31044B (3212363U)
#define DEM_DemBmsDTC_31011B (3211547U)
#define DEM_DemBmsDTC_31011A (3211546U)
#define DEM_DemBmsDTC_31021A (3211802U)
#define DEM_DemBmsDTC_31021B (3211803U)
#define DEM_DemBmsDTC_310115 (3211541U)
#define DEM_DemBmsDTC_310104 (3211524U)
#define DEM_DemBmsDTC_31031C (3212060U)
#define DEM_DemBmsDTC_311C96 (3218582U)
#define DEM_DemBmsDTC_310287 (3211911U)
#define DEM_DemMcuDTC_15A001 (1417217U)
#define DEM_DemMcuDTC_15A002 (1417218U)
#define DEM_DemMcuDTC_15A003 (1417219U)
#define DEM_DemMcuDTC_15A004 (1417220U)
#define DEM_DemBswDTC_160001 (1441793U)
#define DEM_DemBswDTC_160002 (1441794U)
#define DEM_DemBswDTC_160003 (1441795U)
#define DEM_DemBswDTC_160004 (1441796U)
#define DEM_DemBswDTC_160005 (1441797U)
#define DEM_DemBswDTC_160006 (1441798U)
#define DEM_DemBswDTC_160007 (1441799U)
#define DEM_DemBswDTC_160008 (1441800U)
#define DEM_DemBswDTC_160009 (1441801U)
#define DEM_DemBswDTC_16000A (1441802U)
#define DEM_DemBswDTC_16000B (1441803U)
#define DEM_DemBswDTC_16000C (1441804U)
#define DEM_DemBswDTC_16000D (1441805U)
#define DEM_DemBswDTC_16000E (1441806U)
#define DEM_DemBswDTC_16000F (1441807U)
#define DEM_DemBswDTC_160010 (1441808U)
#define DEM_DemBswDTC_160011 (1441809U)
#define DEM_DemBswDTC_160012 (1441810U)
#define DEM_DemBswDTC_160013 (1441811U)
#define DEM_DemBswDTC_160014 (1441812U)
#define DEM_DemBswDTC_160015 (1441813U)
#define DEM_DemBswDTC_160016 (1441814U)
#define DEM_DemBswDTC_160017 (1441815U)
#define DEM_DemBswDTC_160018 (1441816U)
#define DEM_DemBswDTC_160019 (1441817U)
#define DEM_DemBswDTC_16001A (1441818U)
#define DEM_DemBswDTC_16001B (1441819U)
#define DEM_DemBswDTC_16001C (1441820U)
#define DEM_DemBswDTC_16001D (1441821U)
#define DEM_DemBswDTC_16001E (1441822U)
#define DEM_DemBswDTC_16001F (1441823U)
#define DEM_DemBswDTC_160020 (1441824U)
#define DEM_DemBswDTC_160021 (1441825U)
#define DEM_DemBswDTC_160022 (1441826U)
#define DEM_DemBswDTC_160023 (1441827U)
#define DEM_DemBswDTC_160024 (1441828U)
#define DEM_DemBswDTC_160025 (1441829U)
#define DEM_DemBswDTC_160026 (1441830U)
#define DEM_DemBswDTC_160027 (1441831U)
#define DEM_DemBswDTC_160028 (1441832U)
#define DEM_DemBswDTC_160029 (1441833U)
#define DEM_DemBswDTC_16002A (1441834U)
#define DEM_DemBswDTC_16002B (1441835U)
#define DEM_DemBswDTC_16002C (1441836U)
#define DEM_DemBswDTC_16002D (1441837U)
#define DEM_DemBswDTC_16002E (1441838U)
#define DEM_DemBswDTC_16002F (1441839U)
#define DEM_DemBswDTC_160030 (1441840U)
#define DEM_DemBswDTC_160031 (1441841U)
#define DEM_DemBswDTC_160032 (1441842U)
#define DEM_DemBswDTC_160033 (1441843U)
#define DEM_DemBswDTC_160034 (1441844U)
#define DEM_DemBswDTC_160035 (1441845U)
#define DEM_DemBswDTC_160036 (1441846U)
#define DEM_DemBswDTC_160037 (1441847U)
#define DEM_DemBswDTC_160038 (1441848U)
#define DEM_DemBswDTC_160039 (1441849U)
#define DEM_DemBswDTC_16003A (1441850U)
#define DEM_DemBswDTC_16003B (1441851U)
#define DEM_DemBswDTC_16003C (1441852U)
#define DEM_DemBswDTC_16003D (1441853U)
#define DEM_DemBswDTC_16003E (1441854U)
#define DEM_DemBswDTC_16003F (1441855U)
#define DEM_DemBswDTC_160040 (1441856U)
#define DEM_DemBswDTC_160041 (1441857U)
#define DEM_DemBswDTC_160042 (1441858U)
#define DEM_DemBswDTC_160043 (1441859U)
#define DEM_DemBswDTC_160044 (1441860U)
#define DEM_DemBswDTC_160045 (1441861U)
#define DEM_DemBswDTC_160046 (1441862U)
#define DEM_DemBswDTC_160047 (1441863U)
#define DEM_DemBswDTC_160048 (1441864U)
#define DEM_DemBswDTC_160049 (1441865U)
#define DEM_DemBswDTC_16004A (1441866U)
#define DEM_DemBswDTC_16004B (1441867U)
#define DEM_DemOperationCycle_IGON (1U)
#define DEM_DemEnableCondition0 (0U)

#define DEM_CFG_J1939DTC_STATUS_CHANGED_CALLBACK_NUM        (0U)
#define DEM_CFG_J1939NODE_NUM                               (255U)

/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Dem_2.5" */
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef struct
{
    uint8  compPriIgnor;
    uint8  childCompIdx[DEM_CFG_MAX_CHILD_COMP_NUM];
    void   (*DemComponentFailedCallbackFnc)(Dem_ComponentIdType ComponentId, boolean ComponentFailedStauts);
} Dem_ConfigComponent_st;

typedef struct
{
    uint8 acCycleId;        /* Opercycle Id. */
    uint8 acCycType;        /* Opercycle Type */
    uint8 acCycleStartType; /* Opercycle Start Type. */
    uint8 acCycleEndType;   /* Opercycle End Type. */
} Dem_ConfigOperCycle_st;

typedef struct
{
    uint8   acFuncId;            /* DTC assigned Function unit id */
    uint8   acDtcSeverity;        /* DTC Severity. */
    uint8   acWwhObdClass;       /* WWH-OBD class */
    uint16  acObdDtcIdx;         /* Assigned Obd DTC */
    uint16  combEvtIdx[DEM_CFG_COMB_DTC_MAX_EVENT_NUM]; /* Combined event idx list */
    
    /* start of Dtc Attributes define */
    boolean acAgeAllow;         /* Switch of aging allowed or not */
    uint8   acAgeCycThrs;       /* Aging cycles needs to delete event, 1~255 */
    uint8   acAgeCycThrsTFSLC;  /* Aging cycles needs to reset bit TFSLC */
    uint8   acDtcSign;
    uint8   acFdcEvtMemStorThrs;/* Threshold of FDC to capture FF and EX data */
    boolean acImdiStor;         /* Switch of immediate Nvm storage */
    uint8   acAgeOpcycIdx;      /* Operation cycle used for aging refer index number */
    uint8   acExDataClsIdx;     /* Extend data class refer index number */
    uint8   acFfDataRecClsIdx;  /* Freeze frame record data class refer index number */
    uint8   acJ1939DtcNdId;
    uint8   acWobdFfDataClsIdx; /* WWH-OBD Freeze frame data class refer index number */
    uint8   acEvtMemIdx[DEM_CFG_EVENT_MEMORY_NUM];      /* Event memory Index */
    /* end of Dtc Attributes define */
} Dem_ConfigDTCTable_st;

/* Event Config Struct. */
typedef struct
{
    uint8    acCompPri;         /* Component priority within ref DemComponent */
    uint16   awEvtId;           /* Event ID, start from 1 */
    uint8    acEvtKind;         /* Event kind */
    uint8    acEvtRepBhv;       /* Event report behavior */
    uint16   awEvtComIdx;       /* Component class index */
    uint16   awEvtEnCondGrpIdx; /* Enable condition group index */
    uint8    acEvtOpcycIdx;     /* Event operation cycle index */
    uint8    acEvtStorCondGrpIdx;  /* Event storage condition group index */
    uint8    acIndiIdx[DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];          /* Referred Indicator Index */
    uint8    acIndiFccThrs[DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];     /* Indicator failure cycle counter threshold */
    uint8    acIndiHccThrs[DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];     /* Indicator healing cycle counter threshold */
    uint8    acIndFailureOpCycIdx[DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];     /* Indicator failure cycle Index */
    uint8    acIndHealingOpCycIdx[DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];     /* Indicator healing cycle Index */
    uint8    acCallbackClrEvtBhv;     /* Clear event behavior on if call back function allow clear action */
    uint8    (*DemCallbackGetFDC)(sint8 *FaultDetectionCounter);    /* DemCallbackGetFDCFnc */
    uint8    (*DemCallbackClearAllowed_p)(boolean *Allowed);    /* DemCallbackClearEventAllowed */
    void     (*DemCallbackEventDataChanged_p)(Dem_EventIdType EventId);    /* DemCallbackEventDataChanged */
    void     (*DemCallbackEventStatusChanged_p)(Dem_EventIdType EventId, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew);  /* DemCallbackEventStatusChanged  */
    Std_ReturnType (*DemCallbackInitMonitor_p)(Dem_InitMonitorReasonType Reason);    /* CallbackInitMonitorForEvent */
} Dem_ConfigEventTable_st;

/* Debounce Algorithm Configration Struct */
typedef struct
{
    uint8    acDebBhv;            /* Debounce behavior */
    boolean  acDebCntStor;        /* Debounce counter storage */
} Dem_ConfigDebCntBasedTable_st;

typedef struct
{
    uint8    acDebBhv;            /* Debounce behavior */
} Dem_ConfigDebTimBasedTable_st;

typedef struct
{
    uint8    acEvtMemId;            /* Event memory id */
    uint8    acEvtMemType;          /* Event memory type: primary or user defined */
    uint8    acEvtMemMaxEntry;      /* Max entries for the event memory */
} Dem_ConfigEventMemoryTable_st;

/* OBD related Configurations */
typedef struct
{
    boolean acConsidePto;           /* Whether consider the pto status */
    uint8   acObbEvtReadinessGrp;   /* Readiness group */
    uint32  awJ1939DtcVal;
} Dem_ConfigObdDtcTable_st;

/* PID Configurations */
typedef struct
{
    uint8 pidId;
    uint8 pidDataElementIdx[DEM_CFG_PID_MAX_REF_DATA_ELEMENT_NUM];
} Dem_CfgObdPidDataTable_st;

/* Freeze Frame and Extended Data */
typedef struct
{
    uint8   acDataType;             /* Data element type: internal or CS, SR currently not support */
    uint8   acDataSize;             /* Data element size */
    uint8   acInterDataElement;     /* Internal date element */
    boolean acDataUsePort;          /* For CS data element, whether generate a R-port to obtain data from interface */
    uint8   (*DataElementReadPortPtr)(uint8 *DataBufPtr);  /* For CS data element, if acDataUsePort selected, Dem will generate a R-port interface to read data */
    uint8   (*DataElementReadFncPtr)(uint8 *DataBufPtr);  /* For CS data element, the interface from SWC or BSW to read data */
} Dem_ConfigDataElementTable_st;

typedef struct
{
    uint16  acDid;                 /* Did identifier */
    uint8   acDataElementIdx[DEM_CFG_DID_MAX_REF_DATA_ELEMENT_NUM];    /* the index of reference data elements */
    uint16  acDataLen;             /* Data length */
} Dem_ConfigDidTable_st;

typedef struct
{
    uint8   acExDataRecordIdx[DEM_CFG_EXDATA_MAX_REF_EXDATA_RECORD_NUM];
    uint16   acExDataRecLen;          /* Extended data record data length */
} Dem_ConfigExDataTable_st;

typedef struct
{
    uint8   acExDataRecNum;           /* Extended data record number */
    uint8   acExDataRecTrig;          /* Trigger to store this extended data record */
    uint8   acExDataRecUpdate;        /* Whether store the exdata record when the trigger is fulfilled */
    uint8   acExDataElementIdx[DEM_CFG_EXDATA_MAX_REF_DATA_ELEMENT_NUM];
    uint16   acExDataLen;              /* Extended data length */
} Dem_ConfigExDataRecordTable_st;

typedef struct
{
    uint8   acFfDataDidIdx[DEM_CFG_FFDATA_MAX_REF_DID_NUM];
    uint16   acFfDataLen;     /* FF data length */
} Dem_ConfigFfDataTable_st;

typedef struct
{
    uint8   acFfDataRecordIdx[DEM_CFG_FFDATA_MAX_REF_RECORD_NUM];
} Dem_ConfigFfDataRecordNumTable_st;

typedef struct
{
    uint8   acFfDataRecordNum;
    uint8   acFfDataRecTrig;          /* Trigger to store this extended data record */
    uint8   acFfDataRecUpdate;        /* Whether store the exdata record when the trigger is fulfilled */
} Dem_ConfigFfDataRecordTable_st;

/* Enable Condition Configurations */
typedef struct
{
    uint8   acEnCondId;                /* Enable condition ID */
} Dem_ConfigEnCondTable_st;

typedef struct
{
    uint8   acEnCondIdx[DEM_CFG_ENCONDGRP_MAX_REF_ENCOND_NUM];               /* Index of Referenced Enable condition */
} Dem_ConfigEnCondGrpTable_st;

/* Storage Condition Configurations */
typedef struct
{
    uint8   acStorCondId;                 /* Storage Condition ID */
    boolean acStorCondSt;                 /* Storage Condition status */
    uint16  acStorCondRepEvtIdx;           /* Storage Condition replacement event index */
} Dem_ConfigStorCondTable_st;

typedef struct
{
    uint8   acStorCondIdx[DEM_CFG_STORCONDGRP_MAX_REF_STORCOND_NUM];               /* Index of Referenced storage condition */
} Dem_ConfigStorCondGrpTable_st;

/* Callback of DTC status changed Configurations */
typedef struct
{
    void    (*DemCallbackDTCStatusChanged_p)(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew);
} Dem_ConfigDTCStatusChangedPtrTable_st;

/* Ratio for OBD Configurations */
typedef struct
{
    uint8   acIuprDenGrp;
    uint8   acIuprGrp;
    uint16  awRatioId;
    uint8   acRatioKind;
    uint16  awEvtIdx;
    uint16  awPriFimFuncIdx;
    /* Polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_Dem_FLEXIBLE_ARRAY_MEMBER_INCORRECT_SIZE" */
    uint16  awSecFimFuncIdx[DEM_CFG_MAX_SECOND_FIM_FUNC_NUM];
} Dem_ConfigObdRatioTable_st;

/* OBD DTC status changed callback configurations */
typedef struct
{
    void    (*DemCallbackDTCStatusChanged_p)(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew);
} Dem_ConfigObdDTCStatusChangedPtrTable_st;

/* Dtrs Configurations */
typedef struct
{
    sint32 dtrCompuDenominator0;
    sint32 dtrCompuNumerator0;
    sint32 dtrCompuNumerator1;
    uint16 dtrId;
    uint8  dtrMid;
    uint8  dtrTid;
    uint8  dtrUasid;
    uint8  dtrUpdatekind;
    uint16 dtrEventRefIdx;
} Dem_ConfigDtrTable_st;

/* Callback of J1939DTC status changed Configurations */
typedef struct
{
    void    (*DemCallbackDTCStatusChanged_p)(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew);
} Dem_ConfigJ1939DTCStatusChangedPtrTable_st;

typedef struct
{
    uint8  J1939NmNdRefld;
} Dem_ConfigJ1939NodeTable_st;

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define DEM_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern CONST(Dem_ConfigComponent_st, DEM_CONFIG_DATA) Dem_ConfigComponentTable[DEM_CFG_COMP_NUM + 1U];
extern CONST(Dem_ConfigOperCycle_st, DEM_CONFIG_DATA) Dem_CfgOperationCycleTable[DEM_CFG_OPCYC_NUM + 1U];
extern CONST(Dem_ConfigDTCTable_st, DEM_CONFIG_DATA) Dem_CfgDTCTable[DEM_CFG_DTC_NUM + 1U];
extern CONST(uint32, DEM_CONFIG_DATA) Dem_CfgDTCGrpTable[DEM_CFG_DTC_GROUP_NUM + 1U];
extern CONST(Dem_ConfigEventTable_st, DEM_CONFIG_DATA) Dem_CfgEventTable[DEM_CFG_EVENT_NUM + 1U];
extern CONST(uint16, DEM_CONFIG_DATA) Dem_CfgEventIdTableIndex[DEM_CFG_EVENT_ID_MAX + 1U];
extern CONST(Dem_ConfigDebCntBasedTable_st, DEM_CONFIG_DATA) Dem_CfgDebCounterTable[DEM_CFG_DEBOUNCE_COUNTER_NUM + 1U];
extern CONST(Dem_ConfigDebTimBasedTable_st, DEM_CONFIG_DATA) Dem_CfgDebTimeTable[DEM_CFG_DEBOUNCE_TIME_NUM + 1U];
extern CONST(Dem_ConfigEventMemoryTable_st, DEM_CONFIG_DATA) Dem_CfgEventMemoryTable[DEM_CFG_EVENT_MEMORY_NUM + 1U];
extern CONST(Dem_ConfigObdDtcTable_st, DEM_CONFIG_DATA) Dem_CfgObdDTCTable[DEM_CFG_OBD_DTC_NUM + 1U];
extern CONST(Dem_CfgObdPidDataTable_st, DEM_CONFIG_DATA) Dem_CfgObdPidDataTable[DEM_CFG_OBD_PID_DATA_NUM + 1U];
extern CONST(uint8, DEM_CONFIG_DATA) Dem_CfgObdPidDataIndexTable[DEM_CFG_OBD_PID_DATA_NUM + 1U];
extern CONST(Dem_ConfigDataElementTable_st, DEM_CONFIG_DATA) Dem_CfgDataElementTable[DEM_CFG_DATA_ELEMENT_NUM + 1U];
extern CONST(Dem_ConfigDidTable_st, DEM_CONFIG_DATA) Dem_CfgDidTable[DEM_CFG_DID_NUM + 1U];
extern CONST(Dem_ConfigExDataTable_st, DEM_CONFIG_DATA) Dem_CfgExDataTable[DEM_CFG_EXDATA_NUM + 1U];
extern CONST(Dem_ConfigExDataRecordTable_st, DEM_CONFIG_DATA) Dem_CfgExDataRecordTable[DEM_CFG_EXDATA_RECORD_NUM + 1U];
extern CONST(Dem_ConfigFfDataTable_st, DEM_CONFIG_DATA) Dem_CfgFfDataTable[DEM_CFG_FFDATA_NUM + 1U];
extern CONST(Dem_ConfigFfDataRecordNumTable_st, DEM_CONFIG_DATA) Dem_CfgFfDataRecordNumTable[DEM_CFG_FFDATA_RECORDNUM_NUM + 1U];
extern CONST(Dem_ConfigFfDataRecordTable_st, DEM_CONFIG_DATA) Dem_CfgFfDataRecordTable[DEM_CFG_FFDATA_RECORD_NUM + 1U];
extern CONST(Dem_ConfigEnCondTable_st, DEM_CONFIG_DATA) Dem_CfgEnConditionTable[DEM_CFG_ENCOND_NUM + 1U];
extern CONST(Dem_ConfigEnCondGrpTable_st, DEM_CONFIG_DATA) Dem_CfgEnConditionGrpTable[DEM_CFG_ENCOND_GROUP_NUM + 1U];
extern CONST(Dem_ConfigStorCondTable_st, DEM_CONFIG_DATA) Dem_CfgStorConditionTable[DEM_CFG_STORCOND_NUM + 1U];
extern CONST(Dem_ConfigStorCondGrpTable_st, DEM_CONFIG_DATA) Dem_CfgStorConditionGrpTable[DEM_CFG_STORCOND_GROUP_NUM + 1U];
extern CONST(uint8, DEM_CONFIG_DATA) Dem_CfgIndicatorTable[DEM_CFG_INDICATOR_NUM + 1U];
extern CONST(uint16, DEM_CONFIG_DATA) Dem_CfgNvmBlockTable[DEM_CFG_NVM_BLOCK_NUM + 1U];
extern CONST(Dem_ConfigDTCStatusChangedPtrTable_st, DEM_CONFIG_DATA) Dem_CfgDTCStatsuChangedPtrTable[DEM_CFG_DTC_STATUS_CHANGED_CALLBACK_NUM + 1U];
extern CONST(Dem_ConfigObdRatioTable_st, DEM_CONFIG_DATA) Dem_ConfigObdRatioTable[DEM_CFG_OBD_RATIO_NUM + 1U];
extern CONST(Dem_ConfigObdDTCStatusChangedPtrTable_st, DEM_CONFIG_DATA) Dem_CfgObdDTCStatusChangedPtrTable[DEM_CFG_OBDDTC_STATUS_CHANGED_CALLBACK_NUM + 1U];
extern CONST(Dem_ConfigDtrTable_st, DEM_CONFIG_DATA) Dem_ConfigDtrTable[DEM_CFG_DTR_NUM + 1U];

extern CONST(uint8, DEM_CONFIG_DATA) Dem_CfgEvtIndiBhv[DEM_CFG_EVENT_NUM + 1U][DEM_CFG_EVENT_MAX_REF_INDICATOR_NUM];
extern CONST(uint8, DEM_CONFIG_DATA) Dem_CfgDtcPriority[DEM_CFG_DTC_NUM + 1U];
extern CONST(uint32, DEM_CONFIG_DATA) Dem_CfgObdDtcValue[DEM_CFG_OBD_DTC_NUM + 1U];
extern CONST(uint8, DEM_CONFIG_DATA) Dem_CfgEvtFcThrs[DEM_CFG_EVENT_NUM + 1U];
extern CONST(uint8, DEM_CONFIG_DATA) Dem_CfgEvtDebCntCls[DEM_CFG_EVENT_NUM + 1U];
extern CONST(uint16, DEM_CONFIG_DATA) Dem_CfgEvtDebCntIdx[DEM_CFG_EVENT_NUM + 1U];
extern CONST(uint16, DEM_CONFIG_DATA) Dem_CfgEvtDtcIdx[DEM_CFG_EVENT_NUM + 1U];
extern CONST(uint32, DEM_CONFIG_DATA) Dem_CfgDebTimFailThrs[DEM_CFG_DEBOUNCE_TIME_NUM + 1U];
extern CONST(uint32, DEM_CONFIG_DATA) Dem_CfgDebTimPassThrs[DEM_CFG_DEBOUNCE_TIME_NUM + 1U];
extern CONST(uint8, DEM_CONFIG_DATA) Dem_CfgDtcFfDataClsIdx[DEM_CFG_DTC_NUM + 1U];

extern CONST(Dem_ConfigJ1939DTCStatusChangedPtrTable_st, DEM_CONFIG_DATA) Dem_CfgJ1939DTCStatusChangedPtrTable[DEM_CFG_J1939DTC_STATUS_CHANGED_CALLBACK_NUM + 1U];
extern CONST(Dem_ConfigJ1939NodeTable_st, DEM_CONFIG_DATA) Dem_CfgJ1939NodeDTCTable[DEM_CFG_J1939NODE_NUM + 1U];
#define DEM_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
*********************************************************************************
*    Global Functions
*********************************************************************************
*/
#define DEM_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0400(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0402(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0403(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0404(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0405(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0406(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0407(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0408(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0409(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x040B(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x040C(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x040D(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x04CF(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0505(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0525(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0526(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0527(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0528(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0529(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x052B(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x052D(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0530(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0531(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0532(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0533(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0534(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0535(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0536(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0538(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0539(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x053B(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x053C(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0542(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0543(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0544(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0545(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0547(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x055A(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x055C(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0585(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0586(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0587(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0588(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0589(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x058A(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x058C(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x058D(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x058E(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x058F(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0590(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0592(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0594(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0596(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0597(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0598(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x0599(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x059A(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x059B(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x059C(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x059D(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x059E(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x059F(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05A1(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05AA(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05AB(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05B3(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05B4(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05B5(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05B6(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05B9(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05BA(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05BB(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05BC(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05BD(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05BE(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C0(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C1(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C2(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C3(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C4(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C5(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C6(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C7(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C8(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05C9(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05CA(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05CB(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05CC(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05CD(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05CE(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05CF(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05D0(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05D1(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05D2(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05D3(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0x05D4(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xCF00(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xCF05(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xCF06(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xCF07(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF00(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF01(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF02(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF03(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF04(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF06(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF09(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF0A(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF0B(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF0C(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF0D(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDF0E(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);
extern FUNC(uint8, DEM_CODE) Dem_DataServices_ElementClass_DID_0xDD00(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufPtr);

#define DEM_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dem_MemMap.h"    /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif /* DEM_LCFG_H_ */

