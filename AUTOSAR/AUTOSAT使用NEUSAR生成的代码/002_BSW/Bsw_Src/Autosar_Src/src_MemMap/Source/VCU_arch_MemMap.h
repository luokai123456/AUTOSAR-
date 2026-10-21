 
/*
********************************************************************************
*
*  File name: VCU_arch_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef vcu_arch_START_SEC_CONST_VOLATILE
#undef vcu_arch_START_SEC_CONST_VOLATILE
#define VCU_ARCH_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef vcu_arch_STOP_SEC_CONST_VOLATILE
#undef vcu_arch_STOP_SEC_CONST_VOLATILE
#define VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef vcu_arch_START_SEC_VAR
#undef vcu_arch_START_SEC_VAR
#define VCU_ARCH_START_SEC_VAR_NO_INIT_16
#endif
#ifdef vcu_arch_STOP_SEC_VAR
#undef vcu_arch_STOP_SEC_VAR
#define VCU_ARCH_STOP_SEC_VAR_NO_INIT_16
#endif

/*** ASW End ***/



#ifdef VCU_ARCH_START_SEC_CODE
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef VCU_ARCH_START_SEC_CODE
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CODE
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CODE
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_8
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_16
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_32
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VCU_ARCH_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CONST_BOOLEAN
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef VCU_ARCH_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CONST_BOOLEAN
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CONST_8
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef VCU_ARCH_START_SEC_CONST_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CONST_8
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CONST_16
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef VCU_ARCH_START_SEC_CONST_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CONST_16
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CONST_32
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef VCU_ARCH_START_SEC_CONST_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CONST_32
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_CONST_UNSPECIFIED
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef VCU_ARCH_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_CONST_UNSPECIFIED
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef VCU_ARCH_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_NO_INIT_8
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef VCU_ARCH_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_NO_INIT_8
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_NO_INIT_16
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef VCU_ARCH_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_NO_INIT_16
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_NO_INIT_32
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef VCU_ARCH_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_NO_INIT_32
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".XCP_OBS"
#undef VCU_ARCH_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_INIT_BOOLEAN
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef VCU_ARCH_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_INIT_8
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef VCU_ARCH_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_INIT_8
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_INIT_16
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef VCU_ARCH_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_INIT_16
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_INIT_32
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef VCU_ARCH_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_INIT_32
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data"
#undef VCU_ARCH_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_8
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_16
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_32
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_VCU_ARCH
#endif
#ifdef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef VCU_ARCH_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VCU_ARCH_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif

#ifdef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef VCU_ARCH_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VCU_ARCH_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VCU_ARCH_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VCU_ARCH
#endif

 
 
 
