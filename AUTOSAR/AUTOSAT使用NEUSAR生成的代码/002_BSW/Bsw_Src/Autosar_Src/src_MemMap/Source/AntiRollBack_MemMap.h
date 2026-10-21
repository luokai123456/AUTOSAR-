 
/*
********************************************************************************
*
*  File name: AntiRollBack_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/


/*** ASW Start ***/

#ifdef AntiRollBack_START_SEC_CALIB_BOOLEAN
#undef AntiRollBack_START_SEC_CALIB_BOOLEAN
#define ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef AntiRollBack_STOP_SEC_CALIB_BOOLEAN
#undef AntiRollBack_STOP_SEC_CALIB_BOOLEAN
#define ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef AntiRollBack_START_SEC_CALIB_8
#undef AntiRollBack_START_SEC_CALIB_8
#define ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef AntiRollBack_STOP_SEC_CALIB_8
#undef AntiRollBack_STOP_SEC_CALIB_8
#define ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef AntiRollBack_START_SEC_CALIB_16
#undef AntiRollBack_START_SEC_CALIB_16
#define ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef AntiRollBack_STOP_SEC_CALIB_16
#undef AntiRollBack_STOP_SEC_CALIB_16
#define ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef AntiRollBack_START_SEC_CALIB_32
#undef AntiRollBack_START_SEC_CALIB_32
#define ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef AntiRollBack_STOP_SEC_CALIB_32
#undef AntiRollBack_STOP_SEC_CALIB_32
#define ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef AntiRollBack_START_SEC_CALIB_UNSPECIFIED
#undef AntiRollBack_START_SEC_CALIB_UNSPECIFIED
#define ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef AntiRollBack_STOP_SEC_CALIB_UNSPECIFIED
#undef AntiRollBack_STOP_SEC_CALIB_UNSPECIFIED
#define ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef AntiRollBack_START_SEC_VAR_BOOLEAN
#undef AntiRollBack_START_SEC_VAR_BOOLEAN
#define ANTIROLLBACK_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef AntiRollBack_STOP_SEC_VAR_BOOLEAN
#undef AntiRollBack_STOP_SEC_VAR_BOOLEAN
#define ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef AntiRollBack_START_SEC_VAR_8
#undef AntiRollBack_START_SEC_VAR_8
#define ANTIROLLBACK_START_SEC_VAR_NO_INIT_8
#endif
#ifdef AntiRollBack_STOP_SEC_VAR_8
#undef AntiRollBack_STOP_SEC_VAR_8
#define ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef AntiRollBack_START_SEC_VAR_16
#undef AntiRollBack_START_SEC_VAR_16
#define ANTIROLLBACK_START_SEC_VAR_NO_INIT_16
#endif
#ifdef AntiRollBack_STOP_SEC_VAR_16
#undef AntiRollBack_STOP_SEC_VAR_16
#define ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef AntiRollBack_START_SEC_VAR_32
#undef AntiRollBack_START_SEC_VAR_32
#define ANTIROLLBACK_START_SEC_VAR_NO_INIT_32
#endif
#ifdef AntiRollBack_STOP_SEC_VAR_32
#undef AntiRollBack_STOP_SEC_VAR_32
#define ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef AntiRollBack_START_SEC_VAR_UNSPECIFIED
#undef AntiRollBack_START_SEC_VAR_UNSPECIFIED
#define ANTIROLLBACK_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef AntiRollBack_STOP_SEC_VAR_UNSPECIFIED
#undef AntiRollBack_STOP_SEC_VAR_UNSPECIFIED
#define ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef AntiRollBack_START_SEC_CODE
#undef AntiRollBack_START_SEC_CODE
#define ANTIROLLBACK_START_SEC_CODE
#endif
#ifdef AntiRollBack_STOP_SEC_CODE
#undef AntiRollBack_STOP_SEC_CODE
#define ANTIROLLBACK_STOP_SEC_CODE
#endif

#ifdef AntiRollBack_START_SEC_CODE_fc_AntiRollBack
#undef AntiRollBack_START_SEC_CODE_fc_AntiRollBack
#define ANTIROLLBACK_START_SEC_CODE
#endif
#ifdef AntiRollBack_STOP_SEC_CODE_fc_AntiRollBack
#undef AntiRollBack_STOP_SEC_CODE_fc_AntiRollBack
#define ANTIROLLBACK_STOP_SEC_CODE
#endif

#ifdef AntiRollBack_START_SEC_CODE_AntiRollBack_Init
#undef AntiRollBack_START_SEC_CODE_AntiRollBack_Init
#define ANTIROLLBACK_START_SEC_CODE
#endif
#ifdef AntiRollBack_STOP_SEC_CODE_AntiRollBack_Init
#undef AntiRollBack_STOP_SEC_CODE_AntiRollBack_Init
#define ANTIROLLBACK_STOP_SEC_CODE
#endif

/*** ASW End ***/



#ifdef ANTIROLLBACK_START_SEC_CODE
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef ANTIROLLBACK_START_SEC_CODE
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CODE
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CODE
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_8
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_16
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_32
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANTIROLLBACK_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CONST_BOOLEAN
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANTIROLLBACK_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CONST_BOOLEAN
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CONST_8
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANTIROLLBACK_START_SEC_CONST_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CONST_8
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CONST_16
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANTIROLLBACK_START_SEC_CONST_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CONST_16
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CONST_32
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANTIROLLBACK_START_SEC_CONST_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CONST_32
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_CONST_UNSPECIFIED
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef ANTIROLLBACK_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_CONST_UNSPECIFIED
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANTIROLLBACK_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_NO_INIT_8
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANTIROLLBACK_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_8
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_NO_INIT_16
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANTIROLLBACK_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_16
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_NO_INIT_32
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANTIROLLBACK_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_32
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANTIROLLBACK_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_INIT_BOOLEAN
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANTIROLLBACK_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_INIT_8
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANTIROLLBACK_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_INIT_8
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_INIT_16
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANTIROLLBACK_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_INIT_16
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_INIT_32
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANTIROLLBACK_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_INIT_32
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANTIROLLBACK_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_8
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_16
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_32
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif
#ifdef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANTIROLLBACK_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

#ifdef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANTIROLLBACK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANTIROLLBACK_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANTIROLLBACK
#endif

 
 
 
