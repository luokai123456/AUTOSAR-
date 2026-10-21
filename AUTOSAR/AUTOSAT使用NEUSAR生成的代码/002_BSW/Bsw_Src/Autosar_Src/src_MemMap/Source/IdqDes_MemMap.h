 
/*
********************************************************************************
*
*  File name: IdqDes_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/


/*** ASW Start ***/

#ifdef IdqDes_START_SEC_CALIB_BOOLEAN
#undef IdqDes_START_SEC_CALIB_BOOLEAN
#define IDQDES_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef IdqDes_STOP_SEC_CALIB_BOOLEAN
#undef IdqDes_STOP_SEC_CALIB_BOOLEAN
#define IDQDES_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef IdqDes_START_SEC_CALIB_8
#undef IdqDes_START_SEC_CALIB_8
#define IDQDES_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef IdqDes_STOP_SEC_CALIB_8
#undef IdqDes_STOP_SEC_CALIB_8
#define IDQDES_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef IdqDes_START_SEC_CALIB_16
#undef IdqDes_START_SEC_CALIB_16
#define IDQDES_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef IdqDes_STOP_SEC_CALIB_16
#undef IdqDes_STOP_SEC_CALIB_16
#define IDQDES_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef IdqDes_START_SEC_CALIB_32
#undef IdqDes_START_SEC_CALIB_32
#define IDQDES_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef IdqDes_STOP_SEC_CALIB_32
#undef IdqDes_STOP_SEC_CALIB_32
#define IDQDES_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef IdqDes_START_SEC_CALIB_UNSPECIFIED
#undef IdqDes_START_SEC_CALIB_UNSPECIFIED
#define IDQDES_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef IdqDes_STOP_SEC_CALIB_UNSPECIFIED
#undef IdqDes_STOP_SEC_CALIB_UNSPECIFIED
#define IDQDES_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef IdqDes_START_SEC_VAR_BOOLEAN
#undef IdqDes_START_SEC_VAR_BOOLEAN
#define IDQDES_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef IdqDes_STOP_SEC_VAR_BOOLEAN
#undef IdqDes_STOP_SEC_VAR_BOOLEAN
#define IDQDES_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef IdqDes_START_SEC_VAR_8
#undef IdqDes_START_SEC_VAR_8
#define IDQDES_START_SEC_VAR_NO_INIT_8
#endif
#ifdef IdqDes_STOP_SEC_VAR_8
#undef IdqDes_STOP_SEC_VAR_8
#define IDQDES_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef IdqDes_START_SEC_VAR_16
#undef IdqDes_START_SEC_VAR_16
#define IDQDES_START_SEC_VAR_NO_INIT_16
#endif
#ifdef IdqDes_STOP_SEC_VAR_16
#undef IdqDes_STOP_SEC_VAR_16
#define IDQDES_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef IdqDes_START_SEC_VAR_32
#undef IdqDes_START_SEC_VAR_32
#define IDQDES_START_SEC_VAR_NO_INIT_32
#endif
#ifdef IdqDes_STOP_SEC_VAR_32
#undef IdqDes_STOP_SEC_VAR_32
#define IDQDES_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef IdqDes_START_SEC_VAR_UNSPECIFIED
#undef IdqDes_START_SEC_VAR_UNSPECIFIED
#define IDQDES_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef IdqDes_STOP_SEC_VAR_UNSPECIFIED
#undef IdqDes_STOP_SEC_VAR_UNSPECIFIED
#define IDQDES_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef IdqDes_START_SEC_CODE
#undef IdqDes_START_SEC_CODE
#define IDQDES_START_SEC_CODE
#endif
#ifdef IdqDes_STOP_SEC_CODE
#undef IdqDes_STOP_SEC_CODE
#define IDQDES_STOP_SEC_CODE
#endif

#ifdef IdqDes_START_SEC_CODE_fc_IdqDes
#undef IdqDes_START_SEC_CODE_fc_IdqDes
#define IDQDES_START_SEC_CODE
#endif
#ifdef IdqDes_STOP_SEC_CODE_fc_IdqDes
#undef IdqDes_STOP_SEC_CODE_fc_IdqDes
#define IDQDES_STOP_SEC_CODE
#endif

#ifdef IdqDes_START_SEC_CODE_IdqDes_Init
#undef IdqDes_START_SEC_CODE_IdqDes_Init
#define IDQDES_START_SEC_CODE
#endif
#ifdef IdqDes_STOP_SEC_CODE_IdqDes_Init
#undef IdqDes_STOP_SEC_CODE_IdqDes_Init
#define IDQDES_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef IDQDES_START_SEC_CODE
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef IDQDES_START_SEC_CODE
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CODE
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CODE
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQDES_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CALIBRATION_ONLINE_8
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQDES_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CALIBRATION_ONLINE_16
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQDES_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CALIBRATION_ONLINE_32
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQDES_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQDES_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CONST_BOOLEAN
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQDES_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CONST_BOOLEAN
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CONST_8
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQDES_START_SEC_CONST_8
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CONST_8
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CONST_16
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQDES_START_SEC_CONST_16
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CONST_16
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CONST_32
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQDES_START_SEC_CONST_32
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CONST_32
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_CONST_UNSPECIFIED
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef IDQDES_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_CONST_UNSPECIFIED
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQDES_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_NO_INIT_8
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQDES_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_NO_INIT_8
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_NO_INIT_16
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQDES_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_NO_INIT_16
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_NO_INIT_32
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQDES_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_NO_INIT_32
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQDES_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_INIT_BOOLEAN
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQDES_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_INIT_8
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQDES_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_INIT_8
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_INIT_16
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQDES_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_INIT_16
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_INIT_32
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQDES_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_INIT_32
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQDES_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_INIT_8
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_INIT_16
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_INIT_32
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_IDQDES
#endif
#ifdef IDQDES_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef IDQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQDES_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif

#ifdef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef IDQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQDES_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQDES
#endif

 
 
 
