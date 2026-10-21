 
/*
********************************************************************************
*
*  File name: ActvDampg_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef ActvDampg_START_SEC_CALIB_BOOLEAN
#undef ActvDampg_START_SEC_CALIB_BOOLEAN
#define ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef ActvDampg_STOP_SEC_CALIB_BOOLEAN
#undef ActvDampg_STOP_SEC_CALIB_BOOLEAN
#define ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef ActvDampg_START_SEC_CALIB_8
#undef ActvDampg_START_SEC_CALIB_8
#define ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef ActvDampg_STOP_SEC_CALIB_8
#undef ActvDampg_STOP_SEC_CALIB_8
#define ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef ActvDampg_START_SEC_CALIB_16
#undef ActvDampg_START_SEC_CALIB_16
#define ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef ActvDampg_STOP_SEC_CALIB_16
#undef ActvDampg_STOP_SEC_CALIB_16
#define ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef ActvDampg_START_SEC_CALIB_32
#undef ActvDampg_START_SEC_CALIB_32
#define ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef ActvDampg_STOP_SEC_CALIB_32
#undef ActvDampg_STOP_SEC_CALIB_32
#define ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef ActvDampg_START_SEC_CALIB_UNSPECIFIED
#undef ActvDampg_START_SEC_CALIB_UNSPECIFIED
#define ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef ActvDampg_STOP_SEC_CALIB_UNSPECIFIED
#undef ActvDampg_STOP_SEC_CALIB_UNSPECIFIED
#define ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef ActvDampg_START_SEC_VAR_BOOLEAN
#undef ActvDampg_START_SEC_VAR_BOOLEAN
#define ACTVDAMPG_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef ActvDampg_STOP_SEC_VAR_BOOLEAN
#undef ActvDampg_STOP_SEC_VAR_BOOLEAN
#define ACTVDAMPG_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef ActvDampg_START_SEC_VAR_8
#undef ActvDampg_START_SEC_VAR_8
#define ACTVDAMPG_START_SEC_VAR_NO_INIT_8
#endif
#ifdef ActvDampg_STOP_SEC_VAR_8
#undef ActvDampg_STOP_SEC_VAR_8
#define ACTVDAMPG_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef ActvDampg_START_SEC_VAR_16
#undef ActvDampg_START_SEC_VAR_16
#define ACTVDAMPG_START_SEC_VAR_NO_INIT_16
#endif
#ifdef ActvDampg_STOP_SEC_VAR_16
#undef ActvDampg_STOP_SEC_VAR_16
#define ACTVDAMPG_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef ActvDampg_START_SEC_VAR_32
#undef ActvDampg_START_SEC_VAR_32
#define ACTVDAMPG_START_SEC_VAR_NO_INIT_32
#endif
#ifdef ActvDampg_STOP_SEC_VAR_32
#undef ActvDampg_STOP_SEC_VAR_32
#define ACTVDAMPG_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef ActvDampg_START_SEC_VAR_UNSPECIFIED
#undef ActvDampg_START_SEC_VAR_UNSPECIFIED
#define ACTVDAMPG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef ActvDampg_STOP_SEC_VAR_UNSPECIFIED
#undef ActvDampg_STOP_SEC_VAR_UNSPECIFIED
#define ACTVDAMPG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ActvDampg_START_SEC_CODE
#undef ActvDampg_START_SEC_CODE
#define ACTVDAMPG_START_SEC_CODE
#endif
#ifdef ActvDampg_STOP_SEC_CODE
#undef ActvDampg_STOP_SEC_CODE
#define ACTVDAMPG_STOP_SEC_CODE
#endif

#ifdef ActvDampg_START_SEC_CODE_fc_ActvDampg
#undef ActvDampg_START_SEC_CODE_fc_ActvDampg
#define ACTVDAMPG_START_SEC_CODE
#endif
#ifdef ActvDampg_STOP_SEC_CODE_fc_ActvDampg
#undef ActvDampg_STOP_SEC_CODE_fc_ActvDampg
#define ACTVDAMPG_STOP_SEC_CODE
#endif

#ifdef ActvDampg_START_SEC_CODE_ActvDampg_Init
#undef ActvDampg_START_SEC_CODE_ActvDampg_Init
#define ACTVDAMPG_START_SEC_CODE
#endif
#ifdef ActvDampg_STOP_SEC_CODE_ActvDampg_Init
#undef ActvDampg_STOP_SEC_CODE_ActvDampg_Init
#define ACTVDAMPG_STOP_SEC_CODE
#endif

/*** ASW End ***/



#ifdef ACTVDAMPG_START_SEC_CODE
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef ACTVDAMPG_START_SEC_CODE
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CODE
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CODE
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_8
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_16
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_32
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ACTVDAMPG_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CONST_BOOLEAN
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ACTVDAMPG_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CONST_BOOLEAN
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CONST_8
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ACTVDAMPG_START_SEC_CONST_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CONST_8
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CONST_16
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ACTVDAMPG_START_SEC_CONST_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CONST_16
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CONST_32
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ACTVDAMPG_START_SEC_CONST_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CONST_32
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_CONST_UNSPECIFIED
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef ACTVDAMPG_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_CONST_UNSPECIFIED
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ACTVDAMPG_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_NO_INIT_8
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ACTVDAMPG_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_8
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_NO_INIT_16
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ACTVDAMPG_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_16
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_NO_INIT_32
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ACTVDAMPG_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_32
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ACTVDAMPG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_INIT_BOOLEAN
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ACTVDAMPG_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_INIT_8
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ACTVDAMPG_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_INIT_8
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_INIT_16
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ACTVDAMPG_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_INIT_16
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_INIT_32
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ACTVDAMPG_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_INIT_32
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ACTVDAMPG_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_8
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_16
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_32
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_ACTVDAMPG
#endif
#ifdef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ACTVDAMPG_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

#ifdef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef ACTVDAMPG_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ACTVDAMPG_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ACTVDAMPG_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ACTVDAMPG
#endif

 
 
 
