 
/*
********************************************************************************
*
*  File name: Dchrg_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/


/*** ASW Start ***/

#ifdef Dchrg_START_SEC_CALIB_BOOLEAN
#undef Dchrg_START_SEC_CALIB_BOOLEAN
#define DCHRG_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef Dchrg_STOP_SEC_CALIB_BOOLEAN
#undef Dchrg_STOP_SEC_CALIB_BOOLEAN
#define DCHRG_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef Dchrg_START_SEC_CALIB_8
#undef Dchrg_START_SEC_CALIB_8
#define DCHRG_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef Dchrg_STOP_SEC_CALIB_8
#undef Dchrg_STOP_SEC_CALIB_8
#define DCHRG_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef Dchrg_START_SEC_CALIB_16
#undef Dchrg_START_SEC_CALIB_16
#define DCHRG_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef Dchrg_STOP_SEC_CALIB_16
#undef Dchrg_STOP_SEC_CALIB_16
#define DCHRG_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef Dchrg_START_SEC_CALIB_32
#undef Dchrg_START_SEC_CALIB_32
#define DCHRG_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef Dchrg_STOP_SEC_CALIB_32
#undef Dchrg_STOP_SEC_CALIB_32
#define DCHRG_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef Dchrg_START_SEC_CALIB_UNSPECIFIED
#undef Dchrg_START_SEC_CALIB_UNSPECIFIED
#define DCHRG_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef Dchrg_STOP_SEC_CALIB_UNSPECIFIED
#undef Dchrg_STOP_SEC_CALIB_UNSPECIFIED
#define DCHRG_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef Dchrg_START_SEC_VAR_BOOLEAN
#undef Dchrg_START_SEC_VAR_BOOLEAN
#define DCHRG_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef Dchrg_STOP_SEC_VAR_BOOLEAN
#undef Dchrg_STOP_SEC_VAR_BOOLEAN
#define DCHRG_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef Dchrg_START_SEC_VAR_8
#undef Dchrg_START_SEC_VAR_8
#define DCHRG_START_SEC_VAR_NO_INIT_8
#endif
#ifdef Dchrg_STOP_SEC_VAR_8
#undef Dchrg_STOP_SEC_VAR_8
#define DCHRG_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef Dchrg_START_SEC_VAR_16
#undef Dchrg_START_SEC_VAR_16
#define DCHRG_START_SEC_VAR_NO_INIT_16
#endif
#ifdef Dchrg_STOP_SEC_VAR_16
#undef Dchrg_STOP_SEC_VAR_16
#define DCHRG_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef Dchrg_START_SEC_VAR_32
#undef Dchrg_START_SEC_VAR_32
#define DCHRG_START_SEC_VAR_NO_INIT_32
#endif
#ifdef Dchrg_STOP_SEC_VAR_32
#undef Dchrg_STOP_SEC_VAR_32
#define DCHRG_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef Dchrg_START_SEC_VAR_UNSPECIFIED
#undef Dchrg_START_SEC_VAR_UNSPECIFIED
#define DCHRG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef Dchrg_STOP_SEC_VAR_UNSPECIFIED
#undef Dchrg_STOP_SEC_VAR_UNSPECIFIED
#define DCHRG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef Dchrg_START_SEC_CODE
#undef Dchrg_START_SEC_CODE
#define DCHRG_START_SEC_CODE
#endif
#ifdef Dchrg_STOP_SEC_CODE
#undef Dchrg_STOP_SEC_CODE
#define DCHRG_STOP_SEC_CODE
#endif

#ifdef Dchrg_START_SEC_CODE_fc_Dchrg
#undef Dchrg_START_SEC_CODE_fc_Dchrg
#define DCHRG_START_SEC_CODE
#endif
#ifdef Dchrg_STOP_SEC_CODE_fc_Dchrg
#undef Dchrg_STOP_SEC_CODE_fc_Dchrg
#define DCHRG_STOP_SEC_CODE
#endif

#ifdef Dchrg_START_SEC_CODE_Dchrg_Init
#undef Dchrg_START_SEC_CODE_Dchrg_Init
#define DCHRG_START_SEC_CODE
#endif
#ifdef Dchrg_STOP_SEC_CODE_Dchrg_Init
#undef Dchrg_STOP_SEC_CODE_Dchrg_Init
#define DCHRG_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef DCHRG_START_SEC_CODE
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef DCHRG_START_SEC_CODE
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CODE
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CODE
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DCHRG_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CALIBRATION_ONLINE_8
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DCHRG_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CALIBRATION_ONLINE_16
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DCHRG_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CALIBRATION_ONLINE_32
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DCHRG_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DCHRG_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CONST_BOOLEAN
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DCHRG_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CONST_BOOLEAN
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CONST_8
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DCHRG_START_SEC_CONST_8
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CONST_8
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CONST_16
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DCHRG_START_SEC_CONST_16
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CONST_16
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CONST_32
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DCHRG_START_SEC_CONST_32
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CONST_32
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_CONST_UNSPECIFIED
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef DCHRG_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_CONST_UNSPECIFIED
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DCHRG_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_NO_INIT_8
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DCHRG_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_NO_INIT_8
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_NO_INIT_16
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DCHRG_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_NO_INIT_16
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_NO_INIT_32
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DCHRG_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_NO_INIT_32
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DCHRG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_INIT_BOOLEAN
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DCHRG_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_INIT_8
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DCHRG_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_INIT_8
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_INIT_16
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DCHRG_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_INIT_16
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_INIT_32
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DCHRG_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_INIT_32
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DCHRG_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_INIT_8
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_INIT_16
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_INIT_32
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DCHRG
#endif
#ifdef DCHRG_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef DCHRG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DCHRG_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif

#ifdef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef DCHRG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DCHRG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DCHRG_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DCHRG
#endif

 
 
 
