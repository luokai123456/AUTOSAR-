 
/*
********************************************************************************
*
*  File name: BIfTx_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef BIfTx_START_SEC_CALIB_BOOLEAN
#undef BIfTx_START_SEC_CALIB_BOOLEAN
#define BIFTX_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef BIfTx_STOP_SEC_CALIB_BOOLEAN
#undef BIfTx_STOP_SEC_CALIB_BOOLEAN
#define BIFTX_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef BIfTx_START_SEC_CALIB_8
#undef BIfTx_START_SEC_CALIB_8
#define BIFTX_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef BIfTx_STOP_SEC_CALIB_8
#undef BIfTx_STOP_SEC_CALIB_8
#define BIFTX_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef BIfTx_START_SEC_CALIB_16
#undef BIfTx_START_SEC_CALIB_16
#define BIFTX_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef BIfTx_STOP_SEC_CALIB_16
#undef BIfTx_STOP_SEC_CALIB_16
#define BIFTX_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef BIfTx_START_SEC_CALIB_32
#undef BIfTx_START_SEC_CALIB_32
#define BIFTX_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef BIfTx_STOP_SEC_CALIB_32
#undef BIfTx_STOP_SEC_CALIB_32
#define BIFTX_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef BIfTx_START_SEC_CALIB_UNSPECIFIED
#undef BIfTx_START_SEC_CALIB_UNSPECIFIED
#define BIFTX_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef BIfTx_STOP_SEC_CALIB_UNSPECIFIED
#undef BIfTx_STOP_SEC_CALIB_UNSPECIFIED
#define BIFTX_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef BIfTx_START_SEC_VAR_BOOLEAN
#undef BIfTx_START_SEC_VAR_BOOLEAN
#define BIFTX_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef BIfTx_STOP_SEC_VAR_BOOLEAN
#undef BIfTx_STOP_SEC_VAR_BOOLEAN
#define BIFTX_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef BIfTx_START_SEC_VAR_8
#undef BIfTx_START_SEC_VAR_8
#define BIFTX_START_SEC_VAR_NO_INIT_8
#endif
#ifdef BIfTx_STOP_SEC_VAR_8
#undef BIfTx_STOP_SEC_VAR_8
#define BIFTX_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef BIfTx_START_SEC_VAR_16
#undef BIfTx_START_SEC_VAR_16
#define BIFTX_START_SEC_VAR_NO_INIT_16
#endif
#ifdef BIfTx_STOP_SEC_VAR_16
#undef BIfTx_STOP_SEC_VAR_16
#define BIFTX_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef BIfTx_START_SEC_VAR_32
#undef BIfTx_START_SEC_VAR_32
#define BIFTX_START_SEC_VAR_NO_INIT_32
#endif
#ifdef BIfTx_STOP_SEC_VAR_32
#undef BIfTx_STOP_SEC_VAR_32
#define BIFTX_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef BIfTx_START_SEC_VAR_UNSPECIFIED
#undef BIfTx_START_SEC_VAR_UNSPECIFIED
#define BIFTX_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef BIfTx_STOP_SEC_VAR_UNSPECIFIED
#undef BIfTx_STOP_SEC_VAR_UNSPECIFIED
#define BIFTX_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef BIfTx_START_SEC_CODE
#undef BIfTx_START_SEC_CODE
#define BIFTX_START_SEC_CODE
#endif
#ifdef BIfTx_STOP_SEC_CODE
#undef BIfTx_STOP_SEC_CODE
#define BIFTX_STOP_SEC_CODE
#endif

#ifdef BIfTx_START_SEC_CODE_fc_BIfTx
#undef BIfTx_START_SEC_CODE_fc_BIfTx
#define BIFTX_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef BIfTx_STOP_SEC_CODE_fc_BIfTx
#undef BIfTx_STOP_SEC_CODE_fc_BIfTx
#define BIFTX_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef BIfTx_START_SEC_CODE_BIfTx_Init
#undef BIfTx_START_SEC_CODE_BIfTx_Init
#define BIFTX_START_SEC_CODE
#endif
#ifdef BIfTx_STOP_SEC_CODE_BIfTx_Init
#undef BIfTx_STOP_SEC_CODE_BIfTx_Init
#define BIFTX_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef BIFTX_START_SEC_CODE
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef BIFTX_START_SEC_CODE
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CODE
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CODE
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CODE_UNSPECIFIED
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef BIFTX_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CODE_UNSPECIFIED
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFTX_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CALIBRATION_ONLINE_8
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFTX_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CALIBRATION_ONLINE_16
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFTX_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CALIBRATION_ONLINE_32
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFTX_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef BIFTX_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CONST_BOOLEAN
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef BIFTX_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CONST_BOOLEAN
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CONST_8
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef BIFTX_START_SEC_CONST_8
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CONST_8
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CONST_16
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef BIFTX_START_SEC_CONST_16
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CONST_16
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CONST_32
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef BIFTX_START_SEC_CONST_32
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CONST_32
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_CONST_UNSPECIFIED
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef BIFTX_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_CONST_UNSPECIFIED
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFTX_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_NO_INIT_8
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFTX_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_NO_INIT_8
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_NO_INIT_16
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFTX_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_NO_INIT_16
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_NO_INIT_32
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFTX_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_NO_INIT_32
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef BIFTX_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_INIT_BOOLEAN
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFTX_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_INIT_8
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFTX_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_INIT_8
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_INIT_16
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFTX_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_INIT_16
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_INIT_32
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFTX_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_INIT_32
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef BIFTX_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_INIT_8
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_INIT_16
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_INIT_32
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_BIFTX
#endif
#ifdef BIFTX_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef BIFTX_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef BIFTX_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif

#ifdef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef BIFTX_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef BIFTX_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef BIFTX_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_BIFTX
#endif

 
 
 
