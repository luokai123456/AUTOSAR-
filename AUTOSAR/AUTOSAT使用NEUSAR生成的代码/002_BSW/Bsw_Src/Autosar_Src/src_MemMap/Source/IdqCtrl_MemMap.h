 
/*
********************************************************************************
*
*  File name: IdqCtrl_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef IdqCtrl_START_SEC_CALIB_BOOLEAN
#undef IdqCtrl_START_SEC_CALIB_BOOLEAN
#define IDQCTRL_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef IdqCtrl_STOP_SEC_CALIB_BOOLEAN
#undef IdqCtrl_STOP_SEC_CALIB_BOOLEAN
#define IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef IdqCtrl_START_SEC_CALIB_8
#undef IdqCtrl_START_SEC_CALIB_8
#define IDQCTRL_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef IdqCtrl_STOP_SEC_CALIB_8
#undef IdqCtrl_STOP_SEC_CALIB_8
#define IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef IdqCtrl_START_SEC_CALIB_16
#undef IdqCtrl_START_SEC_CALIB_16
#define IDQCTRL_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef IdqCtrl_STOP_SEC_CALIB_16
#undef IdqCtrl_STOP_SEC_CALIB_16
#define IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef IdqCtrl_START_SEC_CALIB_32
#undef IdqCtrl_START_SEC_CALIB_32
#define IDQCTRL_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef IdqCtrl_STOP_SEC_CALIB_32
#undef IdqCtrl_STOP_SEC_CALIB_32
#define IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef IdqCtrl_START_SEC_CALIB_UNSPECIFIED
#undef IdqCtrl_START_SEC_CALIB_UNSPECIFIED
#define IDQCTRL_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef IdqCtrl_STOP_SEC_CALIB_UNSPECIFIED
#undef IdqCtrl_STOP_SEC_CALIB_UNSPECIFIED
#define IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef IdqCtrl_START_SEC_VAR_BOOLEAN
#undef IdqCtrl_START_SEC_VAR_BOOLEAN
#define IDQCTRL_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef IdqCtrl_STOP_SEC_VAR_BOOLEAN
#undef IdqCtrl_STOP_SEC_VAR_BOOLEAN
#define IDQCTRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef IdqCtrl_START_SEC_VAR_8
#undef IdqCtrl_START_SEC_VAR_8
#define IDQCTRL_START_SEC_VAR_NO_INIT_8
#endif
#ifdef IdqCtrl_STOP_SEC_VAR_8
#undef IdqCtrl_STOP_SEC_VAR_8
#define IDQCTRL_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef IdqCtrl_START_SEC_VAR_16
#undef IdqCtrl_START_SEC_VAR_16
#define IDQCTRL_START_SEC_VAR_NO_INIT_16
#endif
#ifdef IdqCtrl_STOP_SEC_VAR_16
#undef IdqCtrl_STOP_SEC_VAR_16
#define IDQCTRL_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef IdqCtrl_START_SEC_VAR_32
#undef IdqCtrl_START_SEC_VAR_32
#define IDQCTRL_START_SEC_VAR_NO_INIT_32
#endif
#ifdef IdqCtrl_STOP_SEC_VAR_32
#undef IdqCtrl_STOP_SEC_VAR_32
#define IDQCTRL_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef IdqCtrl_START_SEC_VAR_UNSPECIFIED
#undef IdqCtrl_START_SEC_VAR_UNSPECIFIED
#define IDQCTRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef IdqCtrl_STOP_SEC_VAR_UNSPECIFIED
#undef IdqCtrl_STOP_SEC_VAR_UNSPECIFIED
#define IDQCTRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef IdqCtrl_START_SEC_CODE
#undef IdqCtrl_START_SEC_CODE
#define IDQCTRL_START_SEC_CODE
#endif
#ifdef IdqCtrl_STOP_SEC_CODE
#undef IdqCtrl_STOP_SEC_CODE
#define IDQCTRL_STOP_SEC_CODE
#endif

#ifdef IdqCtrl_START_SEC_CODE_fc_IdqCtrl
#undef IdqCtrl_START_SEC_CODE_fc_IdqCtrl
#define IDQCTRL_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef IdqCtrl_STOP_SEC_CODE_fc_IdqCtrl
#undef IdqCtrl_STOP_SEC_CODE_fc_IdqCtrl
#define IDQCTRL_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef IdqCtrl_START_SEC_CODE_IdqCtrl_Init
#undef IdqCtrl_START_SEC_CODE_IdqCtrl_Init
#define IDQCTRL_START_SEC_CODE
#endif
#ifdef IdqCtrl_STOP_SEC_CODE_IdqCtrl_Init
#undef IdqCtrl_STOP_SEC_CODE_IdqCtrl_Init
#define IDQCTRL_STOP_SEC_CODE
#endif

/*** ASW End ***/



#ifdef IDQCTRL_START_SEC_CODE
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef IDQCTRL_START_SEC_CODE
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CODE
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CODE
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CODE_UNSPECIFIED
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef IDQCTRL_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CODE_UNSPECIFIED
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQCTRL_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CALIBRATION_ONLINE_8
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQCTRL_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CALIBRATION_ONLINE_16
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQCTRL_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CALIBRATION_ONLINE_32
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQCTRL_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQCTRL_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CONST_BOOLEAN
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQCTRL_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CONST_BOOLEAN
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CONST_8
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQCTRL_START_SEC_CONST_8
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CONST_8
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CONST_16
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQCTRL_START_SEC_CONST_16
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CONST_16
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CONST_32
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQCTRL_START_SEC_CONST_32
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CONST_32
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_CONST_UNSPECIFIED
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef IDQCTRL_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_CONST_UNSPECIFIED
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQCTRL_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_NO_INIT_8
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQCTRL_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_NO_INIT_8
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_NO_INIT_16
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQCTRL_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_NO_INIT_16
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_NO_INIT_32
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQCTRL_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_NO_INIT_32
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQCTRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_INIT_BOOLEAN
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQCTRL_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_INIT_8
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQCTRL_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_INIT_8
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_INIT_16
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQCTRL_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_INIT_16
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_INIT_32
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQCTRL_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_INIT_32
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQCTRL_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_8
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_16
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_32
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_IDQCTRL
#endif
#ifdef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef IDQCTRL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQCTRL_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif

#ifdef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef IDQCTRL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQCTRL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQCTRL_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQCTRL
#endif

 
 
 
