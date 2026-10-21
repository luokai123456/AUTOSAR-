 
/*
********************************************************************************
*
*  File name: DernInv_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef DernInv_START_SEC_CALIB_BOOLEAN
#undef DernInv_START_SEC_CALIB_BOOLEAN
#define DERNINV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef DernInv_STOP_SEC_CALIB_BOOLEAN
#undef DernInv_STOP_SEC_CALIB_BOOLEAN
#define DERNINV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef DernInv_START_SEC_CALIB_8
#undef DernInv_START_SEC_CALIB_8
#define DERNINV_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef DernInv_STOP_SEC_CALIB_8
#undef DernInv_STOP_SEC_CALIB_8
#define DERNINV_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef DernInv_START_SEC_CALIB_16
#undef DernInv_START_SEC_CALIB_16
#define DERNINV_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef DernInv_STOP_SEC_CALIB_16
#undef DernInv_STOP_SEC_CALIB_16
#define DERNINV_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef DernInv_START_SEC_CALIB_32
#undef DernInv_START_SEC_CALIB_32
#define DERNINV_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef DernInv_STOP_SEC_CALIB_32
#undef DernInv_STOP_SEC_CALIB_32
#define DERNINV_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef DernInv_START_SEC_CALIB_UNSPECIFIED
#undef DernInv_START_SEC_CALIB_UNSPECIFIED
#define DERNINV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef DernInv_STOP_SEC_CALIB_UNSPECIFIED
#undef DernInv_STOP_SEC_CALIB_UNSPECIFIED
#define DERNINV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef DernInv_START_SEC_VAR_BOOLEAN
#undef DernInv_START_SEC_VAR_BOOLEAN
#define DERNINV_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef DernInv_STOP_SEC_VAR_BOOLEAN
#undef DernInv_STOP_SEC_VAR_BOOLEAN
#define DERNINV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef DernInv_START_SEC_VAR_8
#undef DernInv_START_SEC_VAR_8
#define DERNINV_START_SEC_VAR_NO_INIT_8
#endif
#ifdef DernInv_STOP_SEC_VAR_8
#undef DernInv_STOP_SEC_VAR_8
#define DERNINV_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef DernInv_START_SEC_VAR_16
#undef DernInv_START_SEC_VAR_16
#define DERNINV_START_SEC_VAR_NO_INIT_16
#endif
#ifdef DernInv_STOP_SEC_VAR_16
#undef DernInv_STOP_SEC_VAR_16
#define DERNINV_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef DernInv_START_SEC_VAR_32
#undef DernInv_START_SEC_VAR_32
#define DERNINV_START_SEC_VAR_NO_INIT_32
#endif
#ifdef DernInv_STOP_SEC_VAR_32
#undef DernInv_STOP_SEC_VAR_32
#define DERNINV_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef DernInv_START_SEC_VAR_UNSPECIFIED
#undef DernInv_START_SEC_VAR_UNSPECIFIED
#define DERNINV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef DernInv_STOP_SEC_VAR_UNSPECIFIED
#undef DernInv_STOP_SEC_VAR_UNSPECIFIED
#define DERNINV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef DernInv_START_SEC_CODE
#undef DernInv_START_SEC_CODE
#define DERNINV_START_SEC_CODE
#endif
#ifdef DernInv_STOP_SEC_CODE
#undef DernInv_STOP_SEC_CODE
#define DERNINV_STOP_SEC_CODE
#endif

#ifdef DernInv_START_SEC_CODE_fc_DernInv
#undef DernInv_START_SEC_CODE_fc_DernInv
#define DERNINV_START_SEC_CODE
#endif
#ifdef DernInv_STOP_SEC_CODE_fc_DernInv
#undef DernInv_STOP_SEC_CODE_fc_DernInv
#define DERNINV_STOP_SEC_CODE
#endif

#ifdef DernInv_START_SEC_CODE_DernInv_Init
#undef DernInv_START_SEC_CODE_DernInv_Init
#define DERNINV_START_SEC_CODE
#endif
#ifdef DernInv_STOP_SEC_CODE_DernInv_Init
#undef DernInv_STOP_SEC_CODE_DernInv_Init
#define DERNINV_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef DERNINV_START_SEC_CODE
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef DERNINV_START_SEC_CODE
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CODE
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CODE
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNINV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CALIBRATION_ONLINE_8
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNINV_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CALIBRATION_ONLINE_16
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNINV_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CALIBRATION_ONLINE_32
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNINV_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNINV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CONST_BOOLEAN
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNINV_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CONST_BOOLEAN
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CONST_8
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNINV_START_SEC_CONST_8
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CONST_8
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CONST_16
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNINV_START_SEC_CONST_16
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CONST_16
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CONST_32
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNINV_START_SEC_CONST_32
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CONST_32
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_CONST_UNSPECIFIED
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef DERNINV_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_CONST_UNSPECIFIED
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNINV_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_NO_INIT_8
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNINV_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_NO_INIT_8
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_NO_INIT_16
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNINV_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_NO_INIT_16
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_NO_INIT_32
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNINV_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_NO_INIT_32
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNINV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_INIT_BOOLEAN
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNINV_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_INIT_8
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNINV_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_INIT_8
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_INIT_16
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNINV_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_INIT_16
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_INIT_32
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNINV_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_INIT_32
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNINV_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_INIT_8
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_INIT_16
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_INIT_32
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DERNINV
#endif
#ifdef DERNINV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef DERNINV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNINV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif

#ifdef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef DERNINV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNINV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNINV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNINV
#endif

 
 
 
