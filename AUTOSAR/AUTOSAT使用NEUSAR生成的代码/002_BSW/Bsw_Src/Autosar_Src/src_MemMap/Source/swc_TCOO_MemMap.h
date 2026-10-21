 
/*
********************************************************************************
*
*  File name: swc_TCOO_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/



/*** ASW Start ***/

#ifdef swc_TCOO_START_SEC_CONST_VOLATILE
#undef swc_TCOO_START_SEC_CONST_VOLATILE
#define SWC_TCOO_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef swc_TCOO_STOP_SEC_CONST_VOLATILE
#undef swc_TCOO_STOP_SEC_CONST_VOLATILE
#define SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef swc_TCOO_START_SEC_VAR
#undef swc_TCOO_START_SEC_VAR
#define SWC_TCOO_START_SEC_VAR_NO_INIT_16
#endif
#ifdef swc_TCOO_STOP_SEC_VAR
#undef swc_TCOO_STOP_SEC_VAR
#define SWC_TCOO_STOP_SEC_VAR_NO_INIT_16
#endif

/*** ASW End ***/


#ifdef SWC_TCOO_START_SEC_CODE
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef SWC_TCOO_START_SEC_CODE
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CODE
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CODE
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_8
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_16
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_32
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef SWC_TCOO_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CONST_BOOLEAN
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef SWC_TCOO_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CONST_BOOLEAN
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CONST_8
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef SWC_TCOO_START_SEC_CONST_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CONST_8
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CONST_16
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef SWC_TCOO_START_SEC_CONST_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CONST_16
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CONST_32
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef SWC_TCOO_START_SEC_CONST_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CONST_32
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_CONST_UNSPECIFIED
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef SWC_TCOO_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_CONST_UNSPECIFIED
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef SWC_TCOO_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_NO_INIT_8
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef SWC_TCOO_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_NO_INIT_8
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_NO_INIT_16
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef SWC_TCOO_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_NO_INIT_16
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_NO_INIT_32
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef SWC_TCOO_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_NO_INIT_32
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef SWC_TCOO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_INIT_BOOLEAN
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef SWC_TCOO_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_INIT_8
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef SWC_TCOO_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_INIT_8
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_INIT_16
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef SWC_TCOO_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_INIT_16
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_INIT_32
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef SWC_TCOO_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_INIT_32
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef SWC_TCOO_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_8
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_16
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_32
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_SWC_TCOO
#endif
#ifdef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef SWC_TCOO_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef SWC_TCOO_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif

#ifdef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef SWC_TCOO_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef SWC_TCOO_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef SWC_TCOO_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_SWC_TCOO
#endif

 
 
 
