#if defined(CCFC3012PT)
#define  CPU_FIRST_BOOT_CORE 0

#include "typedefs.h"
/* PRQA S 1534, 1752 EOF */
#define BOOT_HEADER_MAGIC_WORD  0x005A0000U

#define BOOT_ENABLE_CPU_CORE_0  0x00000001U
#define BOOT_ENABLE_CPU_CORE_1  0x00000002U
#define BOOT_ENABLE_CPU_CORE_2  0x00000004U
#define BOOT_ENABLE_CPU_CORE_3  0x00000008U
#define BOOT_ENABLE_CPU_CORE_4  0x00000010U
#define BOOT_ENABLE_CPU_CORE_5  0x00000020U
#define BOOT_ENABLE_CPU_CORE_C0 0x00000100U
#define BOOT_ENABLE_CPU_CORE_C1 0x00000200U
#define BOOT_ENABLE_CPU_CORE_C2 0x00000400U
#define BOOT_ENABLE_CPU_CORE_C3 0x00000500U

#if CPU_FIRST_BOOT_CORE == 0    
#define BOOT_HEADER_CORE_BITMAP (BOOT_HEADER_MAGIC_WORD | BOOT_ENABLE_CPU_CORE_0 | BOOT_ENABLE_CPU_CORE_C0)
#elif CPU_FIRST_BOOT_CORE == 1  
#define BOOT_HEADER_CORE_BITMAP (BOOT_HEADER_MAGIC_WORD | BOOT_ENABLE_CPU_CORE_1 | BOOT_ENABLE_CPU_CORE_C1)
#elif CPU_FIRST_BOOT_CORE == 2  
#define BOOT_HEADER_CORE_BITMAP (BOOT_HEADER_MAGIC_WORD | BOOT_ENABLE_CPU_CORE_2 | BOOT_ENABLE_CPU_CORE_C2)
#elif CPU_FIRST_BOOT_CORE == 3   
#define BOOT_HEADER_CORE_BITMAP (BOOT_HEADER_MAGIC_WORD | BOOT_ENABLE_CPU_CORE_3 | BOOT_ENABLE_CPU_CORE_C3)
#elif CPU_FIRST_BOOT_CORE == 4  
#define BOOT_HEADER_CORE_BITMAP (BOOT_HEADER_MAGIC_WORD | BOOT_ENABLE_CPU_CORE_4)
#elif CPU_FIRST_BOOT_CORE == 5  
#define BOOT_HEADER_CORE_BITMAP (BOOT_HEADER_MAGIC_WORD | BOOT_ENABLE_CPU_CORE_5)
#endif
// const volatile uint32_t __attribute__ ((section(".boot_header"))) boot_header_core_bitmap = BOOT_HEADER_CORE_BITMAP; /* PRQA S 3408 */
// extern uint32_t __CPU_CORE_0_RESET_VECTOR_ADDR; // extern from link file
// const volatile uint32_t __attribute__ ((section(".cpu0_reset_vector"))) boot_header_reset_vector_0 = (uint32_t)&__CPU_CORE_0_RESET_VECTOR_ADDR; /* PRQA S 3408 */
// extern uint32_t __CPU_CORE_1_RESET_VECTOR_ADDR; // extern from link file
// const volatile uint32_t __attribute__ ((section(".cpu1_reset_vector"))) boot_header_reset_vector_1 = (uint32_t)&__CPU_CORE_1_RESET_VECTOR_ADDR; /* PRQA S 3408 */
// extern uint32_t __CPU_CORE_2_RESET_VECTOR_ADDR; // extern from link file
// const volatile uint32_t __attribute__ ((section(".cpu2_reset_vector"))) boot_header_reset_vector_2 = (uint32_t)&__CPU_CORE_2_RESET_VECTOR_ADDR; /* PRQA S 3408 */
// extern uint32_t __CPU_CORE_3_RESET_VECTOR_ADDR; // extern from link file
// const volatile uint32_t __attribute__ ((section(".cpu3_reset_vector"))) boot_header_reset_vector_3 = (uint32_t)&__CPU_CORE_3_RESET_VECTOR_ADDR; /* PRQA S 3408 */
// extern uint32_t __CPU_CORE_4_RESET_VECTOR_ADDR; // extern from link file
// const volatile uint32_t __attribute__ ((section(".cpu4_reset_vector"))) boot_header_reset_vector_4 = (uint32_t)&__CPU_CORE_4_RESET_VECTOR_ADDR; /* PRQA S 3408 */
// extern uint32_t __CPU_CORE_5_RESET_VECTOR_ADDR; // extern from link file
// const volatile uint32_t __attribute__ ((section(".cpu5_reset_vector"))) boot_header_reset_vector_5 = (uint32_t)&__CPU_CORE_5_RESET_VECTOR_ADDR; /* PRQA S 3408 */

#endif
