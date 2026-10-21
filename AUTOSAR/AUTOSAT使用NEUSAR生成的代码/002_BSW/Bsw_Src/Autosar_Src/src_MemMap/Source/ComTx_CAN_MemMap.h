 
/*
********************************************************************************
*
*  File name: ComTx_CAN_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/


/*** ASW Start ***/

#ifdef ComTx_CAN_START_SEC_CALIB_BOOLEAN
#undef ComTx_CAN_START_SEC_CALIB_BOOLEAN
#define COMTX_CAN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef ComTx_CAN_STOP_SEC_CALIB_BOOLEAN
#undef ComTx_CAN_STOP_SEC_CALIB_BOOLEAN
#define COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef ComTx_CAN_START_SEC_CALIB_8
#undef ComTx_CAN_START_SEC_CALIB_8
#define COMTX_CAN_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef ComTx_CAN_STOP_SEC_CALIB_8
#undef ComTx_CAN_STOP_SEC_CALIB_8
#define COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef ComTx_CAN_START_SEC_CALIB_16
#undef ComTx_CAN_START_SEC_CALIB_16
#define COMTX_CAN_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef ComTx_CAN_STOP_SEC_CALIB_16
#undef ComTx_CAN_STOP_SEC_CALIB_16
#define COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef ComTx_CAN_START_SEC_CALIB_32
#undef ComTx_CAN_START_SEC_CALIB_32
#define COMTX_CAN_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef ComTx_CAN_STOP_SEC_CALIB_32
#undef ComTx_CAN_STOP_SEC_CALIB_32
#define COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef ComTx_CAN_START_SEC_CALIB_UNSPECIFIED
#undef ComTx_CAN_START_SEC_CALIB_UNSPECIFIED
#define COMTX_CAN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef ComTx_CAN_STOP_SEC_CALIB_UNSPECIFIED
#undef ComTx_CAN_STOP_SEC_CALIB_UNSPECIFIED
#define COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef ComTx_CAN_START_SEC_VAR_BOOLEAN
#undef ComTx_CAN_START_SEC_VAR_BOOLEAN
#define COMTX_CAN_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef ComTx_CAN_STOP_SEC_VAR_BOOLEAN
#undef ComTx_CAN_STOP_SEC_VAR_BOOLEAN
#define COMTX_CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef ComTx_CAN_START_SEC_VAR_8
#undef ComTx_CAN_START_SEC_VAR_8
#define COMTX_CAN_START_SEC_VAR_NO_INIT_8
#endif
#ifdef ComTx_CAN_STOP_SEC_VAR_8
#undef ComTx_CAN_STOP_SEC_VAR_8
#define COMTX_CAN_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef ComTx_CAN_START_SEC_VAR_16
#undef ComTx_CAN_START_SEC_VAR_16
#define COMTX_CAN_START_SEC_VAR_NO_INIT_16
#endif
#ifdef ComTx_CAN_STOP_SEC_VAR_16
#undef ComTx_CAN_STOP_SEC_VAR_16
#define COMTX_CAN_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef ComTx_CAN_START_SEC_VAR_32
#undef ComTx_CAN_START_SEC_VAR_32
#define COMTX_CAN_START_SEC_VAR_NO_INIT_32
#endif
#ifdef ComTx_CAN_STOP_SEC_VAR_32
#undef ComTx_CAN_STOP_SEC_VAR_32
#define COMTX_CAN_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef ComTx_CAN_START_SEC_VAR_UNSPECIFIED
#undef ComTx_CAN_START_SEC_VAR_UNSPECIFIED
#define COMTX_CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef ComTx_CAN_STOP_SEC_VAR_UNSPECIFIED
#undef ComTx_CAN_STOP_SEC_VAR_UNSPECIFIED
#define COMTX_CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ComTx_CAN_START_SEC_CODE
#undef ComTx_CAN_START_SEC_CODE
#define COMTX_CAN_START_SEC_CODE
#endif
#ifdef ComTx_CAN_STOP_SEC_CODE
#undef ComTx_CAN_STOP_SEC_CODE
#define COMTX_CAN_STOP_SEC_CODE
#endif

#ifdef ComTx_CAN_START_SEC_CODE_ComTx_CAN_1_Init
#undef ComTx_CAN_START_SEC_CODE_ComTx_CAN_1_Init
#define COMTX_CAN_START_SEC_CODE
#endif
#ifdef ComTx_CAN_STOP_SEC_CODE_ComTx_CAN_1_Init
#undef ComTx_CAN_STOP_SEC_CODE_ComTx_CAN_1_Init
#define COMTX_CAN_STOP_SEC_CODE
#endif

#ifdef ComTx_CAN_START_SEC_CODE_fc_ComTx10ms
#undef ComTx_CAN_START_SEC_CODE_fc_ComTx10ms
#define COMTX_CAN_START_SEC_CODE
#endif
#ifdef ComTx_CAN_STOP_SEC_CODE_fc_ComTx10ms
#undef ComTx_CAN_STOP_SEC_CODE_fc_ComTx10ms
#define COMTX_CAN_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef COMTX_CAN_START_SEC_CODE
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef COMTX_CAN_START_SEC_CODE
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CODE
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CODE
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_8
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_16
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_32
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMTX_CAN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CONST_BOOLEAN
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef COMTX_CAN_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CONST_BOOLEAN
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CONST_8
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef COMTX_CAN_START_SEC_CONST_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CONST_8
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CONST_16
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef COMTX_CAN_START_SEC_CONST_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CONST_16
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CONST_32
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef COMTX_CAN_START_SEC_CONST_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CONST_32
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_CONST_UNSPECIFIED
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef COMTX_CAN_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_CONST_UNSPECIFIED
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMTX_CAN_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_NO_INIT_8
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMTX_CAN_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_NO_INIT_8
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_NO_INIT_16
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMTX_CAN_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_NO_INIT_16
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_NO_INIT_32
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMTX_CAN_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_NO_INIT_32
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMTX_CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_INIT_BOOLEAN
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMTX_CAN_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_INIT_8
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMTX_CAN_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_INIT_8
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_INIT_16
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMTX_CAN_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_INIT_16
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_INIT_32
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMTX_CAN_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_INIT_32
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMTX_CAN_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_8
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_16
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_32
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_COMTX_CAN
#endif
#ifdef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef COMTX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMTX_CAN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif

#ifdef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef COMTX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMTX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMTX_CAN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMTX_CAN
#endif

 
 
 
