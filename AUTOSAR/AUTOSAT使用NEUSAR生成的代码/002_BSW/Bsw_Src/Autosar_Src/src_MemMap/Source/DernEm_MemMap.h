 
/*
********************************************************************************
*
*  File name: DernEm_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/


/*** ASW Start ***/

#ifdef DernEm_START_SEC_CALIB_BOOLEAN
#undef DernEm_START_SEC_CALIB_BOOLEAN
#define DERNEM_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef DernEm_STOP_SEC_CALIB_BOOLEAN
#undef DernEm_STOP_SEC_CALIB_BOOLEAN
#define DERNEM_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef DernEm_START_SEC_CALIB_8
#undef DernEm_START_SEC_CALIB_8
#define DERNEM_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef DernEm_STOP_SEC_CALIB_8
#undef DernEm_STOP_SEC_CALIB_8
#define DERNEM_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef DernEm_START_SEC_CALIB_16
#undef DernEm_START_SEC_CALIB_16
#define DERNEM_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef DernEm_STOP_SEC_CALIB_16
#undef DernEm_STOP_SEC_CALIB_16
#define DERNEM_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef DernEm_START_SEC_CALIB_32
#undef DernEm_START_SEC_CALIB_32
#define DERNEM_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef DernEm_STOP_SEC_CALIB_32
#undef DernEm_STOP_SEC_CALIB_32
#define DERNEM_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef DernEm_START_SEC_CALIB_UNSPECIFIED
#undef DernEm_START_SEC_CALIB_UNSPECIFIED
#define DERNEM_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef DernEm_STOP_SEC_CALIB_UNSPECIFIED
#undef DernEm_STOP_SEC_CALIB_UNSPECIFIED
#define DERNEM_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef DernEm_START_SEC_VAR_BOOLEAN
#undef DernEm_START_SEC_VAR_BOOLEAN
#define DERNEM_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef DernEm_STOP_SEC_VAR_BOOLEAN
#undef DernEm_STOP_SEC_VAR_BOOLEAN
#define DERNEM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef DernEm_START_SEC_VAR_8
#undef DernEm_START_SEC_VAR_8
#define DERNEM_START_SEC_VAR_NO_INIT_8
#endif
#ifdef DernEm_STOP_SEC_VAR_8
#undef DernEm_STOP_SEC_VAR_8
#define DERNEM_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef DernEm_START_SEC_VAR_16
#undef DernEm_START_SEC_VAR_16
#define DERNEM_START_SEC_VAR_NO_INIT_16
#endif
#ifdef DernEm_STOP_SEC_VAR_16
#undef DernEm_STOP_SEC_VAR_16
#define DERNEM_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef DernEm_START_SEC_VAR_32
#undef DernEm_START_SEC_VAR_32
#define DERNEM_START_SEC_VAR_NO_INIT_32
#endif
#ifdef DernEm_STOP_SEC_VAR_32
#undef DernEm_STOP_SEC_VAR_32
#define DERNEM_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef DernEm_START_SEC_VAR_UNSPECIFIED
#undef DernEm_START_SEC_VAR_UNSPECIFIED
#define DERNEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef DernEm_STOP_SEC_VAR_UNSPECIFIED
#undef DernEm_STOP_SEC_VAR_UNSPECIFIED
#define DERNEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef DernEm_START_SEC_CODE
#undef DernEm_START_SEC_CODE
#define DERNEM_START_SEC_CODE
#endif
#ifdef DernEm_STOP_SEC_CODE
#undef DernEm_STOP_SEC_CODE
#define DERNEM_STOP_SEC_CODE
#endif

#ifdef DernEm_START_SEC_CODE_fc_DernEm
#undef DernEm_START_SEC_CODE_fc_DernEm
#define DERNEM_START_SEC_CODE
#endif
#ifdef DernEm_STOP_SEC_CODE_fc_DernEm
#undef DernEm_STOP_SEC_CODE_fc_DernEm
#define DERNEM_STOP_SEC_CODE
#endif

#ifdef DernEm_START_SEC_CODE_DernEm_Init
#undef DernEm_START_SEC_CODE_DernEm_Init
#define DERNEM_START_SEC_CODE
#endif
#ifdef DernEm_STOP_SEC_CODE_DernEm_Init
#undef DernEm_STOP_SEC_CODE_DernEm_Init
#define DERNEM_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef DERNEM_START_SEC_CODE
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef DERNEM_START_SEC_CODE
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CODE
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CODE
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNEM_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CALIBRATION_ONLINE_8
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNEM_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CALIBRATION_ONLINE_16
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNEM_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CALIBRATION_ONLINE_32
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNEM_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNEM_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CONST_BOOLEAN
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNEM_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CONST_BOOLEAN
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CONST_8
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNEM_START_SEC_CONST_8
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CONST_8
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CONST_16
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNEM_START_SEC_CONST_16
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CONST_16
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CONST_32
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNEM_START_SEC_CONST_32
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CONST_32
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_CONST_UNSPECIFIED
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef DERNEM_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_CONST_UNSPECIFIED
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNEM_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_NO_INIT_8
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNEM_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_NO_INIT_8
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_NO_INIT_16
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNEM_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_NO_INIT_16
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_NO_INIT_32
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNEM_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_NO_INIT_32
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_INIT_BOOLEAN
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNEM_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_INIT_8
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNEM_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_INIT_8
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_INIT_16
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNEM_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_INIT_16
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_INIT_32
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNEM_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_INIT_32
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNEM_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_INIT_8
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_INIT_16
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_INIT_32
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DERNEM
#endif
#ifdef DERNEM_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef DERNEM_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNEM_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif

#ifdef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef DERNEM_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNEM_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNEM_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNEM
#endif

 
 
 
