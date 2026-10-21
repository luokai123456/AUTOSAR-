 
/*
********************************************************************************
*
*  File name: EdrvStMac_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef EdrvStMac_START_SEC_CALIB_BOOLEAN
#undef EdrvStMac_START_SEC_CALIB_BOOLEAN
#define EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef EdrvStMac_STOP_SEC_CALIB_BOOLEAN
#undef EdrvStMac_STOP_SEC_CALIB_BOOLEAN
#define EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef EdrvStMac_START_SEC_CALIB_8
#undef EdrvStMac_START_SEC_CALIB_8
#define EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef EdrvStMac_STOP_SEC_CALIB_8
#undef EdrvStMac_STOP_SEC_CALIB_8
#define EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef EdrvStMac_START_SEC_CALIB_16
#undef EdrvStMac_START_SEC_CALIB_16
#define EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef EdrvStMac_STOP_SEC_CALIB_16
#undef EdrvStMac_STOP_SEC_CALIB_16
#define EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef EdrvStMac_START_SEC_CALIB_32
#undef EdrvStMac_START_SEC_CALIB_32
#define EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef EdrvStMac_STOP_SEC_CALIB_32
#undef EdrvStMac_STOP_SEC_CALIB_32
#define EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef EdrvStMac_START_SEC_CALIB_UNSPECIFIED
#undef EdrvStMac_START_SEC_CALIB_UNSPECIFIED
#define EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef EdrvStMac_STOP_SEC_CALIB_UNSPECIFIED
#undef EdrvStMac_STOP_SEC_CALIB_UNSPECIFIED
#define EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef EdrvStMac_START_SEC_VAR_BOOLEAN
#undef EdrvStMac_START_SEC_VAR_BOOLEAN
#define EDRVSTMAC_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef EdrvStMac_STOP_SEC_VAR_BOOLEAN
#undef EdrvStMac_STOP_SEC_VAR_BOOLEAN
#define EDRVSTMAC_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef EdrvStMac_START_SEC_VAR_8
#undef EdrvStMac_START_SEC_VAR_8
#define EDRVSTMAC_START_SEC_VAR_NO_INIT_8
#endif
#ifdef EdrvStMac_STOP_SEC_VAR_8
#undef EdrvStMac_STOP_SEC_VAR_8
#define EDRVSTMAC_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef EdrvStMac_START_SEC_VAR_16
#undef EdrvStMac_START_SEC_VAR_16
#define EDRVSTMAC_START_SEC_VAR_NO_INIT_16
#endif
#ifdef EdrvStMac_STOP_SEC_VAR_16
#undef EdrvStMac_STOP_SEC_VAR_16
#define EDRVSTMAC_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef EdrvStMac_START_SEC_VAR_32
#undef EdrvStMac_START_SEC_VAR_32
#define EDRVSTMAC_START_SEC_VAR_NO_INIT_32
#endif
#ifdef EdrvStMac_STOP_SEC_VAR_32
#undef EdrvStMac_STOP_SEC_VAR_32
#define EDRVSTMAC_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef EdrvStMac_START_SEC_VAR_UNSPECIFIED
#undef EdrvStMac_START_SEC_VAR_UNSPECIFIED
#define EDRVSTMAC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef EdrvStMac_STOP_SEC_VAR_UNSPECIFIED
#undef EdrvStMac_STOP_SEC_VAR_UNSPECIFIED
#define EDRVSTMAC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef EdrvStMac_START_SEC_CODE
#undef EdrvStMac_START_SEC_CODE
#define EDRVSTMAC_START_SEC_CODE
#endif
#ifdef EdrvStMac_STOP_SEC_CODE
#undef EdrvStMac_STOP_SEC_CODE
#define EDRVSTMAC_STOP_SEC_CODE
#endif

#ifdef EdrvStMac_START_SEC_CODE_fc_EdrvStMac
#undef EdrvStMac_START_SEC_CODE_fc_EdrvStMac
#define EDRVSTMAC_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef EdrvStMac_STOP_SEC_CODE_fc_EdrvStMac
#undef EdrvStMac_STOP_SEC_CODE_fc_EdrvStMac
#define EDRVSTMAC_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef EdrvStMac_START_SEC_CODE_EdrvStMac_Init
#undef EdrvStMac_START_SEC_CODE_EdrvStMac_Init
#define EDRVSTMAC_START_SEC_CODE
#endif
#ifdef EdrvStMac_STOP_SEC_CODE_EdrvStMac_Init
#undef EdrvStMac_STOP_SEC_CODE_EdrvStMac_Init
#define EDRVSTMAC_STOP_SEC_CODE
#endif

#ifdef EdrvStMac_START_SEC_CODE_fc_EdrvStMac1ms
#undef EdrvStMac_START_SEC_CODE_fc_EdrvStMac1ms
#define EDRVSTMAC_START_SEC_CODE
#endif
#ifdef EdrvStMac_STOP_SEC_CODE_fc_EdrvStMac1ms
#undef EdrvStMac_STOP_SEC_CODE_fc_EdrvStMac1ms
#define EDRVSTMAC_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef EDRVSTMAC_START_SEC_CODE
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef EDRVSTMAC_START_SEC_CODE
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CODE
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CODE
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CODE_UNSPECIFIED
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef EDRVSTMAC_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CODE_UNSPECIFIED
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_8
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_16
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_32
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EDRVSTMAC_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CONST_BOOLEAN
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EDRVSTMAC_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CONST_BOOLEAN
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CONST_8
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EDRVSTMAC_START_SEC_CONST_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CONST_8
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CONST_16
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EDRVSTMAC_START_SEC_CONST_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CONST_16
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CONST_32
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EDRVSTMAC_START_SEC_CONST_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CONST_32
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_CONST_UNSPECIFIED
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef EDRVSTMAC_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_CONST_UNSPECIFIED
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EDRVSTMAC_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_NO_INIT_8
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EDRVSTMAC_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_8
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_NO_INIT_16
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EDRVSTMAC_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_16
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_NO_INIT_32
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EDRVSTMAC_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_32
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EDRVSTMAC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_INIT_BOOLEAN
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EDRVSTMAC_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_INIT_8
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EDRVSTMAC_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_INIT_8
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_INIT_16
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EDRVSTMAC_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_INIT_16
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_INIT_32
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EDRVSTMAC_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_INIT_32
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EDRVSTMAC_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_8
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_16
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_32
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_EDRVSTMAC
#endif
#ifdef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EDRVSTMAC_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

#ifdef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef EDRVSTMAC_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EDRVSTMAC_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EDRVSTMAC_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EDRVSTMAC
#endif

 
 
 
