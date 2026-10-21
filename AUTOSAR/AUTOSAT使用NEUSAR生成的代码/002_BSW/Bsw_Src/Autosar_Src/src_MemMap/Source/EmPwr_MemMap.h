 
/*
********************************************************************************
*
*  File name: EmPwr_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef EmPwr_START_SEC_CALIB_BOOLEAN
#undef EmPwr_START_SEC_CALIB_BOOLEAN
#define EMPWR_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef EmPwr_STOP_SEC_CALIB_BOOLEAN
#undef EmPwr_STOP_SEC_CALIB_BOOLEAN
#define EMPWR_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef EmPwr_START_SEC_CALIB_8
#undef EmPwr_START_SEC_CALIB_8
#define EMPWR_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef EmPwr_STOP_SEC_CALIB_8
#undef EmPwr_STOP_SEC_CALIB_8
#define EMPWR_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef EmPwr_START_SEC_CALIB_16
#undef EmPwr_START_SEC_CALIB_16
#define EMPWR_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef EmPwr_STOP_SEC_CALIB_16
#undef EmPwr_STOP_SEC_CALIB_16
#define EMPWR_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef EmPwr_START_SEC_CALIB_32
#undef EmPwr_START_SEC_CALIB_32
#define EMPWR_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef EmPwr_STOP_SEC_CALIB_32
#undef EmPwr_STOP_SEC_CALIB_32
#define EMPWR_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef EmPwr_START_SEC_CALIB_UNSPECIFIED
#undef EmPwr_START_SEC_CALIB_UNSPECIFIED
#define EMPWR_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef EmPwr_STOP_SEC_CALIB_UNSPECIFIED
#undef EmPwr_STOP_SEC_CALIB_UNSPECIFIED
#define EMPWR_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef EmPwr_START_SEC_VAR_BOOLEAN
#undef EmPwr_START_SEC_VAR_BOOLEAN
#define EMPWR_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef EmPwr_STOP_SEC_VAR_BOOLEAN
#undef EmPwr_STOP_SEC_VAR_BOOLEAN
#define EMPWR_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef EmPwr_START_SEC_VAR_8
#undef EmPwr_START_SEC_VAR_8
#define EMPWR_START_SEC_VAR_NO_INIT_8
#endif
#ifdef EmPwr_STOP_SEC_VAR_8
#undef EmPwr_STOP_SEC_VAR_8
#define EMPWR_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef EmPwr_START_SEC_VAR_16
#undef EmPwr_START_SEC_VAR_16
#define EMPWR_START_SEC_VAR_NO_INIT_16
#endif
#ifdef EmPwr_STOP_SEC_VAR_16
#undef EmPwr_STOP_SEC_VAR_16
#define EMPWR_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef EmPwr_START_SEC_VAR_32
#undef EmPwr_START_SEC_VAR_32
#define EMPWR_START_SEC_VAR_NO_INIT_32
#endif
#ifdef EmPwr_STOP_SEC_VAR_32
#undef EmPwr_STOP_SEC_VAR_32
#define EMPWR_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef EmPwr_START_SEC_VAR_UNSPECIFIED
#undef EmPwr_START_SEC_VAR_UNSPECIFIED
#define EMPWR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef EmPwr_STOP_SEC_VAR_UNSPECIFIED
#undef EmPwr_STOP_SEC_VAR_UNSPECIFIED
#define EMPWR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef EmPwr_START_SEC_CODE
#undef EmPwr_START_SEC_CODE
#define EMPWR_START_SEC_CODE
#endif
#ifdef EmPwr_STOP_SEC_CODE
#undef EmPwr_STOP_SEC_CODE
#define EMPWR_STOP_SEC_CODE
#endif

#ifdef EmPwr_START_SEC_CODE_fc_EmPwr
#undef EmPwr_START_SEC_CODE_fc_EmPwr
#define EMPWR_START_SEC_CODE
#endif
#ifdef EmPwr_STOP_SEC_CODE_fc_EmPwr
#undef EmPwr_STOP_SEC_CODE_fc_EmPwr
#define EMPWR_STOP_SEC_CODE
#endif

#ifdef EmPwr_START_SEC_CODE_EmPwr_Init
#undef EmPwr_START_SEC_CODE_EmPwr_Init
#define EMPWR_START_SEC_CODE
#endif
#ifdef EmPwr_STOP_SEC_CODE_EmPwr_Init
#undef EmPwr_STOP_SEC_CODE_EmPwr_Init
#define EMPWR_STOP_SEC_CODE
#endif

/*** ASW End ***/




#ifdef EMPWR_START_SEC_CODE
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef EMPWR_START_SEC_CODE
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CODE
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CODE
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMPWR_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CALIBRATION_ONLINE_8
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMPWR_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CALIBRATION_ONLINE_16
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMPWR_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CALIBRATION_ONLINE_32
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMPWR_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMPWR_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CONST_BOOLEAN
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EMPWR_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CONST_BOOLEAN
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CONST_8
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EMPWR_START_SEC_CONST_8
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CONST_8
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CONST_16
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EMPWR_START_SEC_CONST_16
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CONST_16
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CONST_32
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EMPWR_START_SEC_CONST_32
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CONST_32
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_CONST_UNSPECIFIED
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef EMPWR_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_CONST_UNSPECIFIED
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMPWR_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_NO_INIT_8
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMPWR_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_NO_INIT_8
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_NO_INIT_16
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMPWR_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_NO_INIT_16
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_NO_INIT_32
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMPWR_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_NO_INIT_32
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMPWR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_INIT_BOOLEAN
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMPWR_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_INIT_8
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMPWR_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_INIT_8
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_INIT_16
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMPWR_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_INIT_16
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_INIT_32
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMPWR_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_INIT_32
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMPWR_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_INIT_8
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_INIT_16
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_INIT_32
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_EMPWR
#endif
#ifdef EMPWR_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef EMPWR_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMPWR_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif

#ifdef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef EMPWR_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMPWR_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMPWR_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMPWR
#endif

 
 
 
