 
/*
********************************************************************************
*
*  File name: HrmcInj_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef HrmcInj_START_SEC_CALIB_BOOLEAN
#undef HrmcInj_START_SEC_CALIB_BOOLEAN
#define HRMCINJ_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef HrmcInj_STOP_SEC_CALIB_BOOLEAN
#undef HrmcInj_STOP_SEC_CALIB_BOOLEAN
#define HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef HrmcInj_START_SEC_CALIB_8
#undef HrmcInj_START_SEC_CALIB_8
#define HRMCINJ_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef HrmcInj_STOP_SEC_CALIB_8
#undef HrmcInj_STOP_SEC_CALIB_8
#define HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef HrmcInj_START_SEC_CALIB_16
#undef HrmcInj_START_SEC_CALIB_16
#define HRMCINJ_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef HrmcInj_STOP_SEC_CALIB_16
#undef HrmcInj_STOP_SEC_CALIB_16
#define HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef HrmcInj_START_SEC_CALIB_32
#undef HrmcInj_START_SEC_CALIB_32
#define HRMCINJ_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef HrmcInj_STOP_SEC_CALIB_32
#undef HrmcInj_STOP_SEC_CALIB_32
#define HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef HrmcInj_START_SEC_CALIB_UNSPECIFIED
#undef HrmcInj_START_SEC_CALIB_UNSPECIFIED
#define HRMCINJ_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef HrmcInj_STOP_SEC_CALIB_UNSPECIFIED
#undef HrmcInj_STOP_SEC_CALIB_UNSPECIFIED
#define HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef HrmcInj_START_SEC_VAR_BOOLEAN
#undef HrmcInj_START_SEC_VAR_BOOLEAN
#define HRMCINJ_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef HrmcInj_STOP_SEC_VAR_BOOLEAN
#undef HrmcInj_STOP_SEC_VAR_BOOLEAN
#define HRMCINJ_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef HrmcInj_START_SEC_VAR_8
#undef HrmcInj_START_SEC_VAR_8
#define HRMCINJ_START_SEC_VAR_NO_INIT_8
#endif
#ifdef HrmcInj_STOP_SEC_VAR_8
#undef HrmcInj_STOP_SEC_VAR_8
#define HRMCINJ_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef HrmcInj_START_SEC_VAR_16
#undef HrmcInj_START_SEC_VAR_16
#define HRMCINJ_START_SEC_VAR_NO_INIT_16
#endif
#ifdef HrmcInj_STOP_SEC_VAR_16
#undef HrmcInj_STOP_SEC_VAR_16
#define HRMCINJ_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef HrmcInj_START_SEC_VAR_32
#undef HrmcInj_START_SEC_VAR_32
#define HRMCINJ_START_SEC_VAR_NO_INIT_32
#endif
#ifdef HrmcInj_STOP_SEC_VAR_32
#undef HrmcInj_STOP_SEC_VAR_32
#define HRMCINJ_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef HrmcInj_START_SEC_VAR_UNSPECIFIED
#undef HrmcInj_START_SEC_VAR_UNSPECIFIED
#define HRMCINJ_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef HrmcInj_STOP_SEC_VAR_UNSPECIFIED
#undef HrmcInj_STOP_SEC_VAR_UNSPECIFIED
#define HRMCINJ_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef HrmcInj_START_SEC_CODE
#undef HrmcInj_START_SEC_CODE
#define HRMCINJ_START_SEC_CODE
#endif
#ifdef HrmcInj_STOP_SEC_CODE
#undef HrmcInj_STOP_SEC_CODE
#define HRMCINJ_STOP_SEC_CODE
#endif

#ifdef HrmcInj_START_SEC_CODE_fc_HrmcInj
#undef HrmcInj_START_SEC_CODE_fc_HrmcInj
#define HRMCINJ_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef HrmcInj_STOP_SEC_CODE_fc_HrmcInj
#undef HrmcInj_STOP_SEC_CODE_fc_HrmcInj
#define HRMCINJ_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef HrmcInj_START_SEC_CODE_HrmcInj_Init
#undef HrmcInj_START_SEC_CODE_HrmcInj_Init
#define HRMCINJ_START_SEC_CODE
#endif
#ifdef HrmcInj_STOP_SEC_CODE_HrmcInj_Init
#undef HrmcInj_STOP_SEC_CODE_HrmcInj_Init
#define HRMCINJ_STOP_SEC_CODE
#endif

/*** ASW End ***/

#ifdef HRMCINJ_START_SEC_CODE
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef HRMCINJ_START_SEC_CODE
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CODE
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CODE
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CODE_UNSPECIFIED
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef HRMCINJ_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CODE_UNSPECIFIED
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HRMCINJ_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CALIBRATION_ONLINE_8
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HRMCINJ_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CALIBRATION_ONLINE_16
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HRMCINJ_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CALIBRATION_ONLINE_32
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HRMCINJ_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HRMCINJ_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CONST_BOOLEAN
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HRMCINJ_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CONST_BOOLEAN
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CONST_8
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HRMCINJ_START_SEC_CONST_8
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CONST_8
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CONST_16
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HRMCINJ_START_SEC_CONST_16
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CONST_16
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CONST_32
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HRMCINJ_START_SEC_CONST_32
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CONST_32
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_CONST_UNSPECIFIED
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef HRMCINJ_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_CONST_UNSPECIFIED
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HRMCINJ_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_NO_INIT_8
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HRMCINJ_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_NO_INIT_8
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_NO_INIT_16
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HRMCINJ_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_NO_INIT_16
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_NO_INIT_32
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HRMCINJ_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_NO_INIT_32
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HRMCINJ_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_INIT_BOOLEAN
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HRMCINJ_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_INIT_8
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HRMCINJ_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_INIT_8
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_INIT_16
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HRMCINJ_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_INIT_16
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_INIT_32
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HRMCINJ_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_INIT_32
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HRMCINJ_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_8
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_16
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_32
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_HRMCINJ
#endif
#ifdef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef HRMCINJ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HRMCINJ_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif

#ifdef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef HRMCINJ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HRMCINJ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HRMCINJ_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HRMCINJ
#endif

 
 
 
