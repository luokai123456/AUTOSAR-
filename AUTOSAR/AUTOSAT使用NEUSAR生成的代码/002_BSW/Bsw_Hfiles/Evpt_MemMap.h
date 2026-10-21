#if 1 // 临时打开
// #ifdef FUNC_SAFETY_ASW


#define MMAP_ERROR

        


#if defined(EVPT_BSW_START_SEC_CODE_ASIL_C)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text=".bsw_flash_safety_asilc.text"
    #undef EVPT_BSW_START_SEC_CODE_ASIL_C
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_CODE_ASIL_C */


#elif defined(EVPT_BSW_STOP_SEC_CODE_ASIL_C)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text=default
    #undef EVPT_BSW_STOP_SEC_CODE_ASIL_C
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_CODE_ASIL_C */

#elif defined(EVPT_BSW_START_SEC_CODE_ASIL_B)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text=".bsw_flash_safety_asilb.text"
    #undef EVPT_BSW_START_SEC_CODE_ASIL_B
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_CODE_ASIL_B */


#elif defined(EVPT_BSW_STOP_SEC_CODE_ASIL_B)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text=default
    #undef EVPT_BSW_STOP_SEC_CODE_ASIL_B
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_CODE_ASIL_B */

#elif defined(EVPT_BSW_START_SEC_CODE_ASIL_A)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text=".bsw_flash_safety_asila.text"
    #undef EVPT_BSW_START_SEC_CODE_ASIL_A
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_CODE_ASIL_A */


#elif defined(EVPT_BSW_STOP_SEC_CODE_ASIL_A)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text=default
    #undef EVPT_BSW_STOP_SEC_CODE_ASIL_A
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_CODE_ASIL_A */

#elif defined(EVPT_BSW_START_SEC_VAR_INIT_ASIL_C)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data=".bsw_data_safety_asilc"
    #undef EVPT_BSW_START_SEC_VAR_INIT_ASIL_C
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_VAR_INIT_ASIL_C */


#elif defined(EVPT_BSW_STOP_SEC_VAR_INIT_ASIL_C)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data=default
    #undef EVPT_BSW_STOP_SEC_VAR_INIT_ASIL_C
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_VAR_INIT_ASIL_C */

#elif defined(EVPT_BSW_START_SEC_VAR_INIT_ASIL_B)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data=".bsw_data_safety_asilb"
    #undef EVPT_BSW_START_SEC_VAR_INIT_ASIL_B
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_VAR_INIT_ASIL_B */


#elif defined(EVPT_BSW_STOP_SEC_VAR_INIT_ASIL_B)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data=default
    #undef EVPT_BSW_STOP_SEC_VAR_INIT_ASIL_B
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_VAR_INIT_ASIL_B */

#elif defined(EVPT_BSW_START_SEC_VAR_INIT_ASIL_A)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data=".bsw_data_safety_asila"
    #undef EVPT_BSW_START_SEC_VAR_INIT_ASIL_A
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_VAR_INIT_ASIL_A */


#elif defined(EVPT_BSW_STOP_SEC_VAR_INIT_ASIL_A)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data=default
    #undef EVPT_BSW_STOP_SEC_VAR_INIT_ASIL_A
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_VAR_INIT_ASIL_A */

#elif defined(EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_C)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section bss=".bsw_bss_safety_asilc"
    #undef EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_C
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_C */


#elif defined(EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_C)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section bss=default
    #undef EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_C
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_C */

#elif defined(EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_B)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section bss=".bsw_bss_safety_asilb"
    #undef EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_B
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_B */


#elif defined(EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_B)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section bss=default
    #undef EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_B
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_B */

#elif defined(EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_A)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section bss=".bsw_bss_safety_asila"
    #undef EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_A
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_A */


#elif defined(EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_A)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section bss=default
    #undef EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_A
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_A */

#elif defined(EVPT_BSW_START_SEC_CONST_ASIL_C)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section rodata=".bsw_flash_safety_asilc.rodata"
    #undef EVPT_BSW_START_SEC_CONST_ASIL_C
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_CONST_ASIL_C */


#elif defined(EVPT_BSW_STOP_SEC_CONST_ASIL_C)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section rodata=default
    #undef EVPT_BSW_STOP_SEC_CONST_ASIL_C
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_CONST_ASIL_C */

#elif defined(EVPT_BSW_START_SEC_CONST_ASIL_B)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section rodata=".bsw_flash_safety_asilb.rodata"
    #undef EVPT_BSW_START_SEC_CONST_ASIL_B
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_CONST_ASIL_B */


#elif defined(EVPT_BSW_STOP_SEC_CONST_ASIL_B)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section rodata=default
    #undef EVPT_BSW_STOP_SEC_CONST_ASIL_B
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_CONST_ASIL_B */

#elif defined(EVPT_BSW_START_SEC_CONST_ASIL_A)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section rodata=".bsw_flash_safety_asila.rodata"
    #undef EVPT_BSW_START_SEC_CONST_ASIL_A
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_CONST_ASIL_A */


#elif defined(EVPT_BSW_STOP_SEC_CONST_ASIL_A)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section rodata=default
    #undef EVPT_BSW_STOP_SEC_CONST_ASIL_A
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_CONST_ASIL_A */

#elif defined(EVPT_BSW_START_SEC_CODE)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text=default
    #undef EVPT_BSW_START_SEC_CODE
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_CODE */


#elif defined(EVPT_BSW_STOP_SEC_CODE)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text=default
    #undef EVPT_BSW_STOP_SEC_CODE
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_CODE */

#elif defined(EVPT_BSW_START_SEC_VAR_INIT)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data=default
    #undef EVPT_BSW_START_SEC_VAR_INIT
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_VAR_INIT */


#elif defined(EVPT_BSW_STOP_SEC_VAR_INIT)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data=default
    #undef EVPT_BSW_STOP_SEC_VAR_INIT
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_VAR_INIT */

#elif defined(EVPT_BSW_START_SEC_VAR_CLEAR)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section bss=default
    #undef EVPT_BSW_START_SEC_VAR_CLEAR
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_VAR_CLEAR */


#elif defined(EVPT_BSW_STOP_SEC_VAR_CLEAR)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section bss=default
    #undef EVPT_BSW_STOP_SEC_VAR_CLEAR
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_VAR_CLEAR */

#elif defined(EVPT_BSW_START_SEC_CONST)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section rodata=default
    #undef EVPT_BSW_START_SEC_CONST
    #undef MMAP_ERROR
/* EVPT_BSW_START_SEC_CONST */


#elif defined(EVPT_BSW_STOP_SEC_CONST)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section rodata=default
    #undef EVPT_BSW_STOP_SEC_CONST
    #undef MMAP_ERROR
/* EVPT_BSW_STOP_SEC_CONST */
#endif

#ifdef MMAP_ERROR
#error "EvptMemMap error"
#undef MMAP_ERROR
#endif

#endif /* FUNC_SAFETY_ASW */
