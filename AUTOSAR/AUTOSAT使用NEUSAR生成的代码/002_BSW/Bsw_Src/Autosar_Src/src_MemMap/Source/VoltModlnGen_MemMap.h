 
/*
********************************************************************************
*
*  File name: VoltModlnGen_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/


/*** ASW Start ***/

#ifdef VoltModlnGen_START_SEC_CALIB_BOOLEAN
#undef VoltModlnGen_START_SEC_CALIB_BOOLEAN
#define VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef VoltModlnGen_STOP_SEC_CALIB_BOOLEAN
#undef VoltModlnGen_STOP_SEC_CALIB_BOOLEAN
#define VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef VoltModlnGen_START_SEC_CALIB_8
#undef VoltModlnGen_START_SEC_CALIB_8
#define VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef VoltModlnGen_STOP_SEC_CALIB_8
#undef VoltModlnGen_STOP_SEC_CALIB_8
#define VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef VoltModlnGen_START_SEC_CALIB_16
#undef VoltModlnGen_START_SEC_CALIB_16
#define VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef VoltModlnGen_STOP_SEC_CALIB_16
#undef VoltModlnGen_STOP_SEC_CALIB_16
#define VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef VoltModlnGen_START_SEC_CALIB_32
#undef VoltModlnGen_START_SEC_CALIB_32
#define VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef VoltModlnGen_STOP_SEC_CALIB_32
#undef VoltModlnGen_STOP_SEC_CALIB_32
#define VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef VoltModlnGen_START_SEC_CALIB_UNSPECIFIED
#undef VoltModlnGen_START_SEC_CALIB_UNSPECIFIED
#define VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef VoltModlnGen_STOP_SEC_CALIB_UNSPECIFIED
#undef VoltModlnGen_STOP_SEC_CALIB_UNSPECIFIED
#define VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef VoltModlnGen_START_SEC_VAR_BOOLEAN
#undef VoltModlnGen_START_SEC_VAR_BOOLEAN
#define VOLTMODLNGEN_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef VoltModlnGen_STOP_SEC_VAR_BOOLEAN
#undef VoltModlnGen_STOP_SEC_VAR_BOOLEAN
#define VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef VoltModlnGen_START_SEC_VAR_8
#undef VoltModlnGen_START_SEC_VAR_8
#define VOLTMODLNGEN_START_SEC_VAR_NO_INIT_8
#endif
#ifdef VoltModlnGen_STOP_SEC_VAR_8
#undef VoltModlnGen_STOP_SEC_VAR_8
#define VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef VoltModlnGen_START_SEC_VAR_16
#undef VoltModlnGen_START_SEC_VAR_16
#define VOLTMODLNGEN_START_SEC_VAR_NO_INIT_16
#endif
#ifdef VoltModlnGen_STOP_SEC_VAR_16
#undef VoltModlnGen_STOP_SEC_VAR_16
#define VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef VoltModlnGen_START_SEC_VAR_32
#undef VoltModlnGen_START_SEC_VAR_32
#define VOLTMODLNGEN_START_SEC_VAR_NO_INIT_32
#endif
#ifdef VoltModlnGen_STOP_SEC_VAR_32
#undef VoltModlnGen_STOP_SEC_VAR_32
#define VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef VoltModlnGen_START_SEC_VAR_UNSPECIFIED
#undef VoltModlnGen_START_SEC_VAR_UNSPECIFIED
#define VOLTMODLNGEN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef VoltModlnGen_STOP_SEC_VAR_UNSPECIFIED
#undef VoltModlnGen_STOP_SEC_VAR_UNSPECIFIED
#define VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef VoltModlnGen_START_SEC_CODE
#undef VoltModlnGen_START_SEC_CODE
#define VOLTMODLNGEN_START_SEC_CODE
#endif
#ifdef VoltModlnGen_STOP_SEC_CODE
#undef VoltModlnGen_STOP_SEC_CODE
#define VOLTMODLNGEN_STOP_SEC_CODE
#endif

#ifdef VoltModlnGen_START_SEC_CODE_fc_VoltModlnGen
#undef VoltModlnGen_START_SEC_CODE_fc_VoltModlnGen
#define VOLTMODLNGEN_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef VoltModlnGen_STOP_SEC_CODE_fc_VoltModlnGen
#undef VoltModlnGen_STOP_SEC_CODE_fc_VoltModlnGen
#define VOLTMODLNGEN_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef VoltModlnGen_START_SEC_CODE_VoltModlnGen_Init
#undef VoltModlnGen_START_SEC_CODE_VoltModlnGen_Init
#define VOLTMODLNGEN_START_SEC_CODE
#endif
#ifdef VoltModlnGen_STOP_SEC_CODE_VoltModlnGen_Init
#undef VoltModlnGen_STOP_SEC_CODE_VoltModlnGen_Init
#define VOLTMODLNGEN_STOP_SEC_CODE
#endif

/*** ASW End ***/



#ifdef VOLTMODLNGEN_START_SEC_CODE
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef VOLTMODLNGEN_START_SEC_CODE
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CODE
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CODE
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CODE_UNSPECIFIED
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef VOLTMODLNGEN_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CODE_UNSPECIFIED
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_8
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_16
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_32
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNGEN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CONST_BOOLEAN
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef VOLTMODLNGEN_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CONST_BOOLEAN
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CONST_8
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef VOLTMODLNGEN_START_SEC_CONST_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CONST_8
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CONST_16
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef VOLTMODLNGEN_START_SEC_CONST_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CONST_16
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CONST_32
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef VOLTMODLNGEN_START_SEC_CONST_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CONST_32
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_CONST_UNSPECIFIED
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef VOLTMODLNGEN_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_CONST_UNSPECIFIED
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_8
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_8
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_16
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_16
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_32
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_32
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNGEN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_INIT_BOOLEAN
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNGEN_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_INIT_8
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNGEN_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_INIT_8
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_INIT_16
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNGEN_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_INIT_16
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_INIT_32
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNGEN_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_INIT_32
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNGEN_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_8
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_16
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_32
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif
#ifdef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNGEN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

#ifdef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNGEN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNGEN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNGEN
#endif

 
 
 
