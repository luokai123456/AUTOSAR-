 
/*
********************************************************************************
*
*  File name: Diag_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/


/*** ASW Start ***/

#ifdef Diag_START_SEC_CALIB_BOOLEAN
#undef Diag_START_SEC_CALIB_BOOLEAN
#define DIAG_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef Diag_STOP_SEC_CALIB_BOOLEAN
#undef Diag_STOP_SEC_CALIB_BOOLEAN
#define DIAG_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef Diag_START_SEC_CALIB_8
#undef Diag_START_SEC_CALIB_8
#define DIAG_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef Diag_STOP_SEC_CALIB_8
#undef Diag_STOP_SEC_CALIB_8
#define DIAG_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef Diag_START_SEC_CALIB_16
#undef Diag_START_SEC_CALIB_16
#define DIAG_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef Diag_STOP_SEC_CALIB_16
#undef Diag_STOP_SEC_CALIB_16
#define DIAG_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef Diag_START_SEC_CALIB_32
#undef Diag_START_SEC_CALIB_32
#define DIAG_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef Diag_STOP_SEC_CALIB_32
#undef Diag_STOP_SEC_CALIB_32
#define DIAG_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef Diag_START_SEC_CALIB_UNSPECIFIED
#undef Diag_START_SEC_CALIB_UNSPECIFIED
#define DIAG_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef Diag_STOP_SEC_CALIB_UNSPECIFIED
#undef Diag_STOP_SEC_CALIB_UNSPECIFIED
#define DIAG_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef Diag_START_SEC_VAR_BOOLEAN
#undef Diag_START_SEC_VAR_BOOLEAN
#define DIAG_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef Diag_STOP_SEC_VAR_BOOLEAN
#undef Diag_STOP_SEC_VAR_BOOLEAN
#define DIAG_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef Diag_START_SEC_VAR_8
#undef Diag_START_SEC_VAR_8
#define DIAG_START_SEC_VAR_NO_INIT_8
#endif
#ifdef Diag_STOP_SEC_VAR_8
#undef Diag_STOP_SEC_VAR_8
#define DIAG_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef Diag_START_SEC_VAR_16
#undef Diag_START_SEC_VAR_16
#define DIAG_START_SEC_VAR_NO_INIT_16
#endif
#ifdef Diag_STOP_SEC_VAR_16
#undef Diag_STOP_SEC_VAR_16
#define DIAG_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef Diag_START_SEC_VAR_32
#undef Diag_START_SEC_VAR_32
#define DIAG_START_SEC_VAR_NO_INIT_32
#endif
#ifdef Diag_STOP_SEC_VAR_32
#undef Diag_STOP_SEC_VAR_32
#define DIAG_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef Diag_START_SEC_VAR_UNSPECIFIED
#undef Diag_START_SEC_VAR_UNSPECIFIED
#define DIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef Diag_STOP_SEC_VAR_UNSPECIFIED
#undef Diag_STOP_SEC_VAR_UNSPECIFIED
#define DIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef Diag_START_SEC_CODE
#undef Diag_START_SEC_CODE
#define DIAG_START_SEC_CODE
#endif
#ifdef Diag_STOP_SEC_CODE
#undef Diag_STOP_SEC_CODE
#define DIAG_STOP_SEC_CODE
#endif

#ifdef Diag_START_SEC_CODE_fc_Diag
#undef Diag_START_SEC_CODE_fc_Diag
#define DIAG_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef Diag_STOP_SEC_CODE_fc_Diag
#undef Diag_STOP_SEC_CODE_fc_Diag
#define DIAG_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef Diag_START_SEC_CODE_Diag_Init
#undef Diag_START_SEC_CODE_Diag_Init
#define DIAG_START_SEC_CODE
#endif
#ifdef Diag_STOP_SEC_CODE_Diag_Init
#undef Diag_STOP_SEC_CODE_Diag_Init
#define DIAG_STOP_SEC_CODE
#endif

/*** ASW End ***/



#ifdef DIAG_START_SEC_CODE
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef DIAG_START_SEC_CODE
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CODE
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CODE
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CODE_UNSPECIFIED
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef DIAG_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CODE_UNSPECIFIED
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DIAG_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CALIBRATION_ONLINE_8
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DIAG_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CALIBRATION_ONLINE_16
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DIAG_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CALIBRATION_ONLINE_32
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DIAG_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DIAG_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CONST_BOOLEAN
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DIAG_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CONST_BOOLEAN
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CONST_8
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DIAG_START_SEC_CONST_8
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CONST_8
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CONST_16
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DIAG_START_SEC_CONST_16
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CONST_16
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CONST_32
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DIAG_START_SEC_CONST_32
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CONST_32
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_CONST_UNSPECIFIED
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef DIAG_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_CONST_UNSPECIFIED
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DIAG_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_NO_INIT_8
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DIAG_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_NO_INIT_8
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_NO_INIT_16
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DIAG_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_NO_INIT_16
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_NO_INIT_32
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DIAG_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_NO_INIT_32
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_INIT_BOOLEAN
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DIAG_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_INIT_8
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DIAG_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_INIT_8
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_INIT_16
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DIAG_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_INIT_16
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_INIT_32
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DIAG_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_INIT_32
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DIAG_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DIAG_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DIAG_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_INIT_8
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DIAG_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_INIT_16
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DIAG_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_INIT_32
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DIAG_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DIAG
#endif
#ifdef DIAG_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef DIAG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DIAG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DIAG_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif

#ifdef DIAG_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef DIAG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DIAG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DIAG_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DIAG
#endif

 
 
 
