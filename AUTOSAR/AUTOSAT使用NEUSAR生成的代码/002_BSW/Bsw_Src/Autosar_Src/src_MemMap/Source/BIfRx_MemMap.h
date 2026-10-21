 
/*
********************************************************************************
*
*  File name: BIfRx_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef BIfRx_START_SEC_CALIB_BOOLEAN
#undef BIfRx_START_SEC_CALIB_BOOLEAN
#define BIFRX_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef BIfRx_STOP_SEC_CALIB_BOOLEAN
#undef BIfRx_STOP_SEC_CALIB_BOOLEAN
#define BIFRX_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef BIfRx_START_SEC_CALIB_8
#undef BIfRx_START_SEC_CALIB_8
#define BIFRX_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef BIfRx_STOP_SEC_CALIB_8
#undef BIfRx_STOP_SEC_CALIB_8
#define BIFRX_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef BIfRx_START_SEC_CALIB_16
#undef BIfRx_START_SEC_CALIB_16
#define BIFRX_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef BIfRx_STOP_SEC_CALIB_16
#undef BIfRx_STOP_SEC_CALIB_16
#define BIFRX_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef BIfRx_START_SEC_CALIB_32
#undef BIfRx_START_SEC_CALIB_32
#define BIFRX_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef BIfRx_STOP_SEC_CALIB_32
#undef BIfRx_STOP_SEC_CALIB_32
#define BIFRX_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef BIfRx_START_SEC_CALIB_UNSPECIFIED
#undef BIfRx_START_SEC_CALIB_UNSPECIFIED
#define BIFRX_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef BIfRx_STOP_SEC_CALIB_UNSPECIFIED
#undef BIfRx_STOP_SEC_CALIB_UNSPECIFIED
#define BIFRX_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef BIfRx_START_SEC_VAR_BOOLEAN
#undef BIfRx_START_SEC_VAR_BOOLEAN
#define BIFRX_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef BIfRx_STOP_SEC_VAR_BOOLEAN
#undef BIfRx_STOP_SEC_VAR_BOOLEAN
#define BIFRX_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef BIfRx_START_SEC_VAR_8
#undef BIfRx_START_SEC_VAR_8
#define BIFRX_START_SEC_VAR_NO_INIT_8
#endif
#ifdef BIfRx_STOP_SEC_VAR_8
#undef BIfRx_STOP_SEC_VAR_8
#define BIFRX_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef BIfRx_START_SEC_VAR_16
#undef BIfRx_START_SEC_VAR_16
#define BIFRX_START_SEC_VAR_NO_INIT_16
#endif
#ifdef BIfRx_STOP_SEC_VAR_16
#undef BIfRx_STOP_SEC_VAR_16
#define BIFRX_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef BIfRx_START_SEC_VAR_32
#undef BIfRx_START_SEC_VAR_32
#define BIFRX_START_SEC_VAR_NO_INIT_32
#endif
#ifdef BIfRx_STOP_SEC_VAR_32
#undef BIfRx_STOP_SEC_VAR_32
#define BIFRX_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef BIfRx_START_SEC_VAR_UNSPECIFIED
#undef BIfRx_START_SEC_VAR_UNSPECIFIED
#define BIFRX_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef BIfRx_STOP_SEC_VAR_UNSPECIFIED
#undef BIfRx_STOP_SEC_VAR_UNSPECIFIED
#define BIFRX_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef BIfRx_START_SEC_CODE
#undef BIfRx_START_SEC_CODE
#define BIFRX_START_SEC_CODE
#endif
#ifdef BIfRx_STOP_SEC_CODE
#undef BIfRx_STOP_SEC_CODE
#define BIFRX_STOP_SEC_CODE
#endif

#ifdef BIfRx_START_SEC_CODE_fc_BIfRx
#undef BIfRx_START_SEC_CODE_fc_BIfRx
#define BIFRX_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef BIfRx_STOP_SEC_CODE_fc_BIfRx
#undef BIfRx_STOP_SEC_CODE_fc_BIfRx
#define BIFRX_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef BIfRx_START_SEC_CODE_BIfRx_Init
#undef BIfRx_START_SEC_CODE_BIfRx_Init
#define BIFRX_START_SEC_CODE
#endif
#ifdef BIfRx_STOP_SEC_CODE_BIfRx_Init
#undef BIfRx_STOP_SEC_CODE_BIfRx_Init
#define BIFRX_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef BIFRX_START_SEC_CODE
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef BIFRX_START_SEC_CODE
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CODE
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CODE
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CODE_UNSPECIFIED
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef BIFRX_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CODE_UNSPECIFIED
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFRX_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CALIBRATION_ONLINE_8
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFRX_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CALIBRATION_ONLINE_16
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFRX_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CALIBRATION_ONLINE_32
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFRX_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFRX_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CONST_BOOLEAN
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef BIFRX_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CONST_BOOLEAN
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CONST_8
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef BIFRX_START_SEC_CONST_8
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CONST_8
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CONST_16
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef BIFRX_START_SEC_CONST_16
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CONST_16
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CONST_32
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef BIFRX_START_SEC_CONST_32
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CONST_32
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_CONST_UNSPECIFIED
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef BIFRX_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_CONST_UNSPECIFIED
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFRX_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_NO_INIT_8
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFRX_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_NO_INIT_8
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_NO_INIT_16
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFRX_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_NO_INIT_16
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_NO_INIT_32
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFRX_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_NO_INIT_32
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFRX_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_INIT_BOOLEAN
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFRX_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_INIT_8
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFRX_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_INIT_8
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_INIT_16
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFRX_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_INIT_16
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_INIT_32
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFRX_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_INIT_32
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFRX_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_INIT_8
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_INIT_16
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_INIT_32
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_BIFRX
#endif
#ifdef BIFRX_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef BIFRX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFRX_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif

#ifdef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef BIFRX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFRX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFRX_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFRX
#endif

 
 
 
