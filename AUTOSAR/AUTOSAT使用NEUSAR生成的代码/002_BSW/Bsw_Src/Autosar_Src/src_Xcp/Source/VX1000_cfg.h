/* ------------------------------------------------------------------------------ */
/* VX1000_cfg.h                                                                   */
/* Vector VX1000 Application Driver for PowerPC MOT MPC5xx,FSL MPC5xxx,STM SPC5xx */
/* Release: 04_09                    Build: 810          Modification: 17.05.2025 */
/* Vector Informatik GmbH                                                         */
/*                                                                                */
/* User specific configuration settings                                           */
/* ------------------------------------------------------------------------------ */


/* ----------------------------------------------------------------------------------------------------------------------- /
/ Status of MISRA conformance:                                                                                             /
/ ---------------------------                                                                                              /
/                                                                                                                          /
/     T H E    U S E R    I S    R E S P O N S I B L E    F O R   T H E    C O N T E N T    O F    T H I S    F I L E      /
/                                                                                                                          /
/------------------------------------------------------------------------------------------------------------------------ */
#include "Xcp_Swc.h"

#if !defined(VX1000_TARGET_POWERPC)
#define VX1000_TARGET_POWERPC
#endif /* !VX1000_TARGET_POWERPC */


/* ----------------------------------------------------------------------------- */
/* Note: VX1000_cfg.h serves multiple purposes and is included                   */
/* several times with different predefines being set to select the wanted        */
/* purpose. IT IS INTENDED that some lines may be repeatedly processed (namely   */
/* the "#pragma" part) while the rest (the configuration part) actually IS       */
/* PROTECTED from double inclusion even though your static code analyser tool    */
/* might not see this and state a warning or error about lacking protection.     */
/* Those wrong messages can be safely ignored.                                   */
#if defined(VX1000_BEGSECT_VXMODULE_C) && (!defined(VX1000_BEGSECT_VXMODULE_C_UNDO))

/* ----------------------------------------------------------------------------- */
/* Optional code lines that you may want to place at the beginning of the        */
/* module, e.g. with #pragmas to raise the compiler's optimisation level for it. */

/*
___optional_and_compiler_dependent_sequence_of_pragmas
*/


#elif !defined(VX1000_CFG_H)
#define VX1000_CFG_H


/* ----------------------------------------------------------------------------- */
/* This specifies the version numbers of the configuration template that this    */
/* file was derived from. It is used in the compatibility check between the      */
/* configuration file, the driver header file and the driver module file.        */

#define VX1000_APPDRIVER_BUILDNUMBER_H 810UL


/* ----------------------------------------------------------------------------- */
/* The application may maintain its own version in range 0U..255U (it is not     */
/* interpreted by the AppDriver or VX1000, just displayed in VXconsole)          */

#define VX1000_APPDRIVER_CONFIGVERSION 0U


/* ----------------------------------------------------------------------------- */
/* If for production code the entire VX1000 functionality shall be disabled      */
/* transparently, enable the following define. This way, the driver module will  */
/* not produce any code or constants, will not use RAM, and the driver header    */
/* will provide empty API macros so that the application code needs no change.   */

/*
#define VX1000_DISABLE_INSTRUMENTATION
*/


/* ----------------------------------------------------------------------------- */
/* Optionally define a compiler dependent expression that just evaluates to the  */
/* value of the 2nd parameter (whose expected type is the 1st parameter) but as  */
/* a side effect may perform a dummy access of the four remaining parameters in  */
/* a way that prevents compiler warnings about unused or needlessly initialised  */
/* variables inside the calling code if needed. Be aware that those parameters   */
/* can be of any type, e.g. constants, immediates, variables or pointers with    */
/* arbitrary qualifiers like const or volatile. If you leave this undefined the  */
/* default definition to just "(R)" will become active which definitely does     */
/* not produce any code to be executed but cannot prevent any warning.           */

#define VX1000_DISCARD4DUMMYARGS(T, R, A1, A2, A3, A4)  /*lint -e(835,845,931,960) dummy operations my look like stupid math, may cast to bigger types or to floating-point types and may touch multiple volatiles in one expression*/((R) + (T)(0UL & (((VX1000_UINT32)(A1) & (VX1000_UINT32)(A2)) | ((VX1000_UINT32)(A3) & (VX1000_UINT32)(A4))))) /* PRQA S 3453 */ /* Violating MISRA rule 19.7 because the goal of this expression is that the compiler does NOT generate any code for it */

/* ----------------------------------------------------------------------------- */
/* Optionally define a compiler dependent statement that just reads the value    */
/* of its macro parameter without modifying it or relying on it to be of a       */
/* specific type (it can be e.g. a constant, immediate, variable or a pointer    */
/* with arbitrary qualifiers like const or volatile). If you leave this          */
/* undefined the default definition to "" will become active. You may want to    */
/* find a solution per tool chain, e.g. for 100% coverage it is good to HAVE     */
/* code generated for it (e.g. a NOP) while for normal compilation you want no   */
/* code that would have to be executed at runtime and for MISRA or LINT checkers */
/* you definitely need a statement that actually touches the parameter.          */

#define VX1000_DUMMYREAD(X) (void)/*lint -e(831,845) dummy read may get zero value as input*/(X); /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to expand either to nothing (= no ; without statement) or to a correctly terminated (with ;) statement */


#if defined(VX1000_DISABLE_INSTRUMENTATION)
/* ----------------------------------------------------------------------------- */
/* As some compilers fail creating completely empty object files or fail         */
/* linking those, you may provide this define as a workaround that makes the     */
/* driver module look "somehow non-empty" to compiler and linker.                */

/*
#define VX1000_EMPTYFILE_DUMMYDECL     ___some_dummy_constant_declaration_or_function_declaration
*/

#else /* !VX1000_DISABLE_INSTRUMENTATION */

/* ----------------------------------------------------------------------------- */
/* If you do not plan to exploit the In-Place-Olda measurement capabilities of   */
/* the VX1000, you can suppress the compilation/execution of the AppDriver code  */
/* that would be needed to support this feature by activating the definition of  */
/* VX1000_SUPPRESS_IPO_API. If you think you might ever run into a situation     */
/* where you run out of OLDA memory, you better should leave it undefined.       */

/*
#define VX1000_SUPPRESS_IPO_API
*/

/* ----------------------------------------------------------------------------- */
/* If your ECU is part of a radar / vision system and you plan to measure the    */
/* stream of raw or processed data ("chirps", "frames" or FFT) via the VX1000    */
/* RIF channel you can enable AppDriver support for this feature via the APIs    */
/* DataTransferStart()/-Finish()/-GetInfo() by defining VX1000_ENABLE_RADAR_API. */
/* Otherwise you can leave it undefined to keep the memory footprint small.      */

/*
#define VX1000_ENABLE_RADAR_API
*/

/* ----------------------------------------------------------------------------- */
/* If your application wants to check measurement status via DaqGetStatus() API  */
/* you have to enable this feature by defining VX1000_ENABLE_DAQ_STATUS_API.     */
/* Otherwise you can leave it undefined to keep the memory footprint small.      */

/*
#define VX1000_ENABLE_DAQ_STATUS_API
*/

/* ----------------------------------------------------------------------------- */
/* Optionally define the compiler dependent type for 64bit variables which is    */
/* mandatory when the _complete_ API set of the VX1000_HOOK_BASED_BYPASSING      */
/* feature or of the VX1000_ENABLE_RADAR_API feature is needed by your app.      */

typedef long unsigned long MY_UINT64_T;/* note: 'long long' is a language extension that is not allowed by MISRA */
#define VX1000_UINT64 MY_UINT64_T      /* ___the_64bit_interger_type_that_is_provided_by_the_used_compiler_for_this_plattform */


/* ----------------------------------------------------------------------------- */
/* To ensure data consistency, in certain situations barrier instructions must   */
/* be executed. The driver knows the respective places, but because the driver   */
/* is written in C, the barrier instructions cannot be included directly. The    */
/* syntax depends on the used compiler and even on the used compiler options,    */
/* so the user must provide the following interface. VX1000_BARRIER_FORCE_WRITE  */
/* is meant to instruct the processor to not optimise away the first write       */
/* operation when two write operations target the same storage location, while   */
/* VX1000_BARRIER_FORCE_ORDER is meant to instruct the processor to not reorder  */
/* surrounding write operations nor to combine them into fewer, larger stores.   */

/*
#define VX1000_BARRIER_FORCE_WRITE()   ___inline_assembly_code_that_performs_a_MBAR_barrier_instruction();
#define VX1000_BARRIER_FORCE_ORDER()   ___inline_assembly_code_that_performs_a_MBAR_barrier_instruction();
*/


/* ----------------------------------------------------------------------------- */
/* Define the target ECU identification string (for subcommands 0 and 1 of XCP   */
/* GET_ID). This is optional and may be used by CANape to auto-select the        */
/* correct A2L database when connecting to an unidentified ECU. Just leave this  */
/* undefined if you do not want to exploit this feature.                         */

/*
#define VX1000_ECUID                   ___a_quoted_constant_string_that_contains_the_desired_file_name
#define VX1000_ECUID_LEN               ___the_count_of_characters_in_VX1000_ECUID_excluding_the_terminating_zero_byte
*/


/* ----------------------------------------------------------------------------- */
/* To allow re-compilation of the driver code for different targets with common  */
/* linkage of the data (e.g. to have the code replicated into the local IRAMs of */
/* each core, or when the cores are differently equipped with instruction set    */
/* extensions or when the cores use completely different instruction sets, like  */
/* HC12<>XGATE, ARM<>THUMB, BookE<>VLE, Tricore<>XC800, MCU<>DSP, ...), you may  */
/* provide a string that will serve as function suffix. A second effect is that  */
/* the code is optimised with respect to main/slave-core nature of the driver    */
/* architecture: the objects for the slave cores' functions will not contain     */
/* code to detect whether they run on the main core, nor the main-core-only      */
/* features (like mailbox etc.) Just leave this undefined if the driver shall    */
/* be executed on the main core (or on a single-core MCU).                       */

/*
#define VX1000_COMPILED_FOR_SLAVECORES ___an_optional_unique_sequence_of_some_letters_and_digits
*/

/* ----------------------------------------------------------------------------- */
/* When compiling the driver for different targets with _separate_ linkage, the  */
/* main core's address of the gVX1000 structure must be announced to the slave   */
/* core(s) so all cores will work on common data. Note that if the cores use     */
/* different address mappings, the address as seen by the _main_ core must be    */
/* used, while on the slave core(s), the macros VX1000_ADDRESS_TO_POINTER and    */
/* VX1000_POINTER_TO_ADDRESS must be configured in a way that remaps the main    */
/* core address to a slave space pointer and the slave space pointer to an main  */
/* core address. The given address is only evaluated when also the define        */
/* VX1000_COMPILED_FOR_SLAVECORES is enabled. Because the feature involves a lot */
/* of pointer indirections, keep VX1000_MAINCORE_VX_STRUCT_ADDR undefined for    */
/* performance reasons whenever common linkage of all cores' code is possible.   */

/*
#define VX1000_MAINCORE_VX_STRUCT_ADDR ___the_address_of_the_gVX1000_structure_as_seen_from_the_main_core
*/

/* ----------------------------------------------------------------------------- */
/* Some configuration settings cannot be checked at compile time. The driver     */
/* therefore performs several runtime checks. Some of these checks happen in     */
/* response to XCP requests which allows to transmit the result to the XCP       */
/* master but other checks happen implicitly during start-up. In the latter case */
/* there is no XCP channel to transmit the error code and therefore the driver   */
/* offers the possibility to log these error codes into a ring buffer in RAM.    */
/* You may optionally specify the size of that ring buffer here, where the       */
/* default value of 0 means that there is no logging at all.                     */

/*
#define VX1000_ERRLOG_SIZE             ___optional_count_of_entries_in_the_fault_collection_buffer
*/

/* ----------------------------------------------------------------------------- */
/* The VX1000_CLOCK() callback is important for the correct detection of timeout */
/* expiries, benchmarking and the time-stamping of DAQ packets.                  */
/* The VX1000 app driver must know the resolution of the timer as returned by    */
/* VX1000_CLOCK(), which is achieved in EITHER of two ways.                      */
/* In some cases, undesired compiler warnings cannot be avoided if the first     */
/* method is applied, so if you encounter inexplicable warnings, especially      */
/* about conditions always being true/false, try the second method.              */

/* 1) Define ONE of the VX1000_CLOCK_TICKS_PER_S, VX1000_CLOCK_TICKS_PER_MS or   */
/* VX1000_CLOCK_TICKS_PER_US macros - which one depends on how fast your clock   */
/* runs (easiest).                                                               */

#define VX1000_CLOCK_TICKS_PER_MS      1000UL
/*
#define VX1000_CLOCK_TICKS_PER_US      ___alternative1_to_VX1000_CLOCK_TICKS_PER_MS
#define VX1000_CLOCK_TICKS_PER_S       ___alternative2_to_VX1000_CLOCK_TICKS_PER_MS
*/

/* 2) Define BOTH of VX1000_CLOCK_TICKS_BASE_NS and VX1000_CLOCK_TICKS_PER_BASE  */
/* macros to declare the exact interval (in nanoseconds) and the number of ticks */
/* your clock produces during one interval (recommended). The value of define    */
/* VX1000_CLOCK_TICKS_BASE_NS must expand to an immediate because the pre-       */
/* processor decides depending on its value whether the compiled code will first */
/* divide and then multiply in timeout computations or the other way round.      */

/*
#define VX1000_CLOCK_TICKS_BASE_NS     ___alternative3_to_VX1000_CLOCK_TICKS_PER_US_OR_MS_OR_S
#define VX1000_CLOCK_TICKS_PER_BASE    ___alternative3_to_VX1000_CLOCK_TICKS_PER_US_OR_MS_OR_S
*/

/* ----------------------------------------------------------------------------- */
/* If you want to synchronise/syntonise events in this ECU to events in further  */
/* ECUs or in the PC, you have to provide some additional details about the time */
/* base of the driver. Just leave this undefined if you don't need that feature, */
/* then the VX blindly trusts VX1000_CLOCK(), assuming full 32bit time stamps.   */

/*
#define VX1000_CLOCK_TIMER_ADDR        ___an_optional_pointer_to_the_memory_mapped_32bit_or_64bit_register_that_VX1000_CLOCK_timestamps_are_based_on
#define VX1000_CLOCK_TIMER_SIZE        ___the_count_of_valid_bits_in_the_timer_hardware_register_rounded_down_to_0_or_16_or_24_or_32_or_64
#define VX1000_CLOCK_TIMER_COUNTS_DOWN ___leave_undefined_if_the_counter_increments_but_define_if_counter_decrements
*/

/* ----------------------------------------------------------------------------- */
/* The driver needs a stable high resolution time base to correctly detect       */
/* communication timeouts and optionally for time stamping the XCP packets.      */
/* In particular, the time base is needed for the following features             */
/*   1. DAQ over DATA TRACE with timestamps that relate to the ECU time          */
/*   2. DAQ over JTAG is used (for Nexus class 2+)                               */
/*   3. to validate/reject STIM_v1 packets                                       */
/*   4. to check bypass timeouts                                                 */
/*   5. to check coldstart delay timeouts                                        */
/*   6. to check soft-reset notification timeouts                                */

#if defined(VX1000_CLOCK_TIMER_COUNTS_DOWN) && (defined(VX1000_CLOCK_TIMER_ADDR) && ((VX1000_CLOCK_TIMER_SIZE)>=32UL))
#define VX1000_CLOCK()                 (~(VX1000_ADDR_TO_PTR2VU32(VX1000_CLOCK_TIMER_ADDR)[0])) /* automatic solution (but in big endian mode with 64bit timer, use index 1 instead of 0) */
#elif defined(VX1000_CLOCK_TIMER_ADDR) && ((VX1000_CLOCK_TIMER_SIZE)>=32UL)
#define VX1000_CLOCK()                 (VX1000_ADDR_TO_PTR2VU32(VX1000_CLOCK_TIMER_ADDR)[0])    /* automatic solution (but in big endian mode with 64bit timer, use index 1 instead of 0) */
#else  /* not all timer properties known: need manual solution */
#define VX1000_CLOCK()                 ((uint32)Gpt_Stm_LLD_GetCounter(STM0))  /* "BadConfig" dummy, actually: (VX1000_UINT32)(___a_function_or_hw_register_that_returns_a_freerunning_32bit_time()) */
#endif /* not all timer properties known: need manual solution */


/* ----------------------------------------------------------------------------- */
/* Whenever a variable that doesn't allow for measurement via trace is to be     */
/* measured, VX1000_OLDA must be enabled.                                        */

#define VX1000_OLDA

#if defined(VX1000_OLDA)

/* ----------------------------------------------------------------------------- */
/* In some cases, adding some extra code at the start of that function in charge */
/* of the copying of measurement data and event signalisation can cause some     */
/* very time-critical instructions to end up at more appropriate addresses in    */
/* memory, leading to better cache efficiency and higher event rates.            */
/* You may want to try to define VX1000_OLDA_NOPS to expand to some void code    */
/* that will be inserted there if your event rate is too low.                    */

#define VX1000_OLDA_NOPS()

/* ----------------------------------------------------------------------------- */
/* Define the memory size in bytes for the OLDA DAQ transfer tables.             */
/* Size needs to be at least the amount of measurement data + 4 Byte for each    */
/* memory gap. In case that VX1000_MEMSYNC_TRIGGER_COUNT is defined > 0, the     */
/* buffer is only used to store the copy descriptors but needs not to hold a     */
/* copy of the data. Note that "0" has special meaning "buddy RAM"               */
/* Note that the maximum value allowed is 0xFFFCU!                               */

#define VX1000_OLDA_MEMORY_SIZE        0xFFFCU


/* ----------------------------------------------------------------------------- */
/* Optionally define VX1000_OLDA_MEMORY_ADDR to reuse user space for VX at that  */
/* address. (Otherwise VX1000_OLDA_MEMORY_SIZE bytes will be allocated           */
/* automatically inside the VX1000_DATA structure.)                              */

/*
#define VX1000_OLDA_MEMORY_ADDR        ___optional_address_of_a_RAM_area_that_can_be_used_exclusively_by_the_VX
*/


/* ----------------------------------------------------------------------------- */
/* Optionally define VX1000_EVENT00_HANDLING up to VX1000_EVENT31_HANDLING to    */
/* one of the values VX1000_EVENT_IS_UNUSED, VX1000_EVENT_NORMAL,                */
/* VX1000_EVENT_ALSO_USES_BARRIER and VX1000_EVENT_MBUF_ONLY_TRIGGER to optimise */
/* the OLDA behaviour for your particular environment. (Note that in case of     */
/* measurement via trace, the mode of events whose variables are fully covered   */
/* by trace windows is overridden dynamically to not use OLDA at all. To force a */
/* static decision for such events, use VX1000_EVENT_ALWAYS_USE_BARRIER instead  */
/* of VX1000_EVENT_ALSO_USES_BARRIER to use the In-Place-Olda ("IPO") feature    */
/* despite trace. For the other OLDA modes, other configuration options exist    */
/* in other places to override this, so here keep their settings untouched.)     */
/* If you are not interested in using the BARRIER feature or the MBUF ("multi-   */
/* buffer OLDA") feature, just leave them all undefined.                         */

#define VX1000_EVENT00_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT01_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT02_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT03_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT04_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT05_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT06_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT07_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT08_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT09_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT10_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT11_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT12_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT13_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT14_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT15_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT16_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT17_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT18_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT19_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT20_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT21_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT22_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT23_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT24_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT25_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT26_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT27_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT28_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT29_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT30_HANDLING        (VX1000_EVENT_NORMAL)
#define VX1000_EVENT31_HANDLING        (VX1000_EVENT_IS_RESERVED) /* channel 31 is reserved for VX-internal special event signalisation */


/* ----------------------------------------------------------------------------- */
/* Enable Olda overload detection.                                               */

#define VX1000_OLDA_OVERLOAD_DETECTION


/* ----------------------------------------------------------------------------- */
/* To turn on benchmarks of the event copy durations, needs 8bytes RAM per event */

/*
#define VX1000_OLDA_BENCHMARK
*/

/* ----------------------------------------------------------------------------- */
/* VX1000_OLDA_BENCHMARK_CNT is an optional configuration parameter that allows  */
/* you to limit the number of benchmarked events. For obvious reasons, this      */
/* must not be bigger than the event channels total.                             */

/*
#define VX1000_OLDA_BENCHMARK_CNT __number_of_benchmarked_event_channels
*/


/* ----------------------------------------------------------------------------- */
/* Here you can enable features that may help to improve OLDA performance. The   */
/* effect is not deterministic, so you should benchmark all versions to finally  */
/* decide what shall be enabled or disabled. If you don't care for performance   */
/* and RAM usage, just leave everything undefined.                               */

/* ----------------------------------------------------------------------------- */
/* When you benchmark different measurement configurations you can temporarily   */
/* override any "VX1000_EVENTxxx_HANDLING == VX1000_EVENT_MBUF_ONLY_TRIGGER"     */
/* setting simply by defining VX1000_IGNORE_MBUF_EVENTMODE instead of having to  */
/* change all the individual mode settings to VX1000_EVENT_NORMAL.               */
/* Having this define set also reduces OLDA code size and runtime a little bit.  */

/*
#define VX1000_IGNORE_MBUF_EVENTMODE
*/

/* ----------------------------------------------------------------------------- */
/* The application may provide "copy offloader engines" that may free            */
/* the AppDriver from the burden of the DAQ copy operations or that take over    */
/* the task of serialisation of stream transfer transactions from various events */
/* that may be triggered on various cores. When not planning to use the          */
/* copy offloader feature, just ignore all of the following VX1000_CO_* defines. */

#define VX1000_CO_OFFLOADER_COUNT      0U

#if (VX1000_CO_OFFLOADER_COUNT) > 0x00U

/* ----------------------------------------------------------------------------- */
/* Provide the capabilities and handling functions of all your offloader engines */
/* counted in hexadecimal from index 00 to index (VX1000_CO_OFFLOADER_COUNT-1).  */
/* In very special use cases an offloader may be of VX1000_CO_COPY_TYPE_MEMSYNC  */
/* type, but normally the type VX1000_CO_COPY_TYPE_SIMPLECOPY is to be selected  */
/* in the VX1000_CO_COPY_TYPES_xx defines. If an offloader does not support the  */
/* VX1000_CO_COPY_TYPE_MEMSYNC mode, the offloader implementation can save the   */
/* VX1000_CO_GET_DO_MEMSYNC() evaluation for each offloaded request at runtime.  */

#define VX1000_CO_COPY_TYPES_00        VX1000_CO_COPY_TYPE_SIMPLECOPY


/* ----------------------------------------------------------------------------- */
/* Depending on the used HW module, the maximum size that a copy offloader can   */
/* handle may be smaller than 0xFFFFFFFF. You have to define the limitation in   */
/* VX1000_CO_MAX_BLOCKSIZE_xx so the VX1000 can split larger blocks accordingly. */

#define VX1000_CO_MAX_BLOCKSIZE_00     ___maximum_size_in_bytes_that_can_be_handled_by_a_single_copy_job_of_offloader_00


/* ----------------------------------------------------------------------------- */
/* The HW itself (or the SW that configures it) may not support arbitrary sizes  */
/* for memory/FIFO reads and writes. The defines VX1000_CO_ACCESS_SIZES_xx are   */
/* to be configured as the disjunction of the respective subset of the defines   */
/* VX1000_CO_ACCESS_SIZE_8BIT, .. 16/32/64/128 .. ,VX1000_CO_ACCESS_SIZE_256BIT  */
/* so the VX1000 can know which alignment requirements have to be met and which  */
/* accesses can be requested. To simplify the implementation of the functions    */
/* behind VX1000_CO_FUNCP_ENQUEUE_xx, it is advantageous to offer only a single  */
/* access size, e.g. 32, which avoids the need for runtime evaluation of each    */
/* request's VX1000_CO_GET_SRC_DATATYPE() and VX1000_CO_GET_DST_DATATYPE()       */
/* values, especially you get rid of the endianess conversion problems this way. */

#define VX1000_CO_ACCESS_SIZES_00      ___any_combination_of_VX1000_CO_ACCESS_SIZE_8BIT__16BIT__32BIT__64BIT__128BIT__VX1000_CO_ACCESS_SIZE_256BIT_to_describe_the_supported_access_sizes_by_offloader_00


/* ----------------------------------------------------------------------------- */
/* Each offloader must provide at least one address mode for destination and at  */
/* least one for source. (If you provide exactly one for destination and for     */
/* source you can avoid the otherwise needed runtime evaluation of the requests' */
/* VX1000_CO_GET_DO_DSTINC() and VX1000_CO_GET_DO_SRCINC() values. The selection */
/* of fixed addres mode and of autoincrementing address mo is performed by a     */
/* disjunction of VX1000_CO_ADDRESS_MODE_FIXDST, VX1000_CO_ADDRESS_MODE_INCDST,  */
/* VX1000_CO_ADDRESS_MODE_FIXSRC and VX1000_CO_ADDRESS_MODE_INCSRC.              */

#define VX1000_CO_ADDRESS_MODES_00     ___any_combination_of_VX1000_CO_ADDRESS_MODE_INCDST__VX1000_CO_ADDRESS_MODE_FIXDST__VX1000_CO_ADDRESS_MODE_INCSRC__VX1000_CO_ADDRESS_MODE_FIXSRC_to_describe_the_supported_address_increment_modes_by_offloader_00


/* ----------------------------------------------------------------------------- */
/* Whenever the AppDriver has to copy measurement data to the tool, it offloads  */
/* the sequence of copy operations to a user callback. Such a callback has to be */
/* configured per used offloader as an int-(int*, int)-function-pointer whose    */
/* implementation should follow one of the VX1000_CopyOffloader.c_template_xxx   */
/* reference implementations. These explain the parameters and return values.    */

#define VX1000_CO_FUNCP_ENQUEUE_00     ___pointer_to_a_function_that_enqueues_new_copy_jobs_for_offloader_00


/* ----------------------------------------------------------------------------- */
/* The VX1000 cyclically checks the status of all used offloaders. You have to   */
/* provide a function pointer to a uint32-void-function per used offloader that  */
/* return zero if the offloader is OK or non-zero if the offloader has problems. */

#define VX1000_CO_FUNCP_STATUS_00      ___pointer_to_a_function_that_returns_the_current_status_of_offloader_00


/* ----------------------------------------------------------------------------- */
/* Inside VX1000_INIT_ASYNC_START() and always after an offloader ran into an    */
/* error state, a void-void-function is called to perform a (re-)initialisation. */
/* You have to provide a function pointer to these functions per used offloader. */

#define VX1000_CO_FUNCP_RESET_00       ___pointer_to_a_function_that_resets_all_current_and_enables_all_future_activities_of_offloader_00

#endif /* VX1000_CO_OFFLOADER_COUNT > 0x00U */

#endif /* VX1000_OLDA */


/* ----------------------------------------------------------------------------- */
/* For several trace topologies it is advantageous or even mandatory to combine  */
/* the normally independent 32bit stores of event's timestamp and channel number */
/* into a shared 64bit store. This feature requires however a stricter alignment */
/* that normally has to be manually controlled in the linker script of your      */
/* application's project and in the case of slave trace may require to move the  */
/* gVX1000 structure to an entirely different RAM to ensure that a 64bit access  */
/* of it from any CPU core really generates one 64bit trace packet from it. Also */
/* required is either VX1000_UINT64 hardware support of your toolchain and MISRA */
/* rules or you have to provide a callback VX1000_STORE64 that will execute      */
/* the required machine instruction. Just leave VX1000_COMBINE_TIMESTAMP_EVENT   */
/* undefined if you don't use trace at all or your MCU does not "misoptimise"    */
/* (in the sense of event triggering) data trace of neigbouring 32bit words.     */

/*
#define VX1000_COMBINE_TIMESTAMP_EVENT
*/


/* ----------------------------------------------------------------------------- */
/* Disable or enable and configure the stimulation / bypassing feature           */

/*
#define VX1000_STIM
*/

#if defined(VX1000_STIM)

/* ----------------------------------------------------------------------------- */
/* Configure the stimulation / bypassing feature. The event number range may     */
/* be chosen freely, the maximum range is 0..31. Each event needs 4 Bytes RAM,   */
/* so you may want to specify a smaller range.                                   */

#define VX1000_STIM_EVENT_OFFSET       0U     /* ___index_of_the_first_STIM_event */
#define VX1000_STIM_EVENT_COUNT        31U    /* ___count_of_available_STIM_events*/


/* ----------------------------------------------------------------------------- */
/* Enable indirect stimulation to optimise performance against memory usage.     */
/* Needs additional memory (amount of bypass data + 4 byte per memory gap)       */

#if defined(VX1000_OLDA)
#define VX1000_STIM_BY_OLDA
#endif /* VX1000_OLDA */


/* ----------------------------------------------------------------------------- */
/* To turn on basic benchmarking of all bypass round trip times, just define     */
/* VX1000_STIM_BENCHMARK. This will only use little RAM and runtime resources.   */

/*
#define VX1000_STIM_BENCHMARK
*/


/* ----------------------------------------------------------------------------- */
/* To turn on advanced benchmarking (of one particular STIM channel) you can     */
/* define VX1000_STIM_HISTOGRAM to the desired channel number. This debug        */
/* feature eats one kilobyte of RAM. Leave undefined to disable the feature.     */

/*
#define VX1000_STIM_HISTOGRAM          ((VX1000_STIM_EVENT_OFFSET) +0U)
*/

/* ----------------------------------------------------------------------------- */
/* Define the STIM behaviour after ECU resets. In cases where a slow PC or debug */
/* connection forces long STIM timeouts it may happen that non-preemtible tasks  */
/* when using the bypassing feature prevent the watchdog handler from doing its  */
/* job in time, leading to a correct yet undesired ECU reset. To avoid looping   */
/* endlessly through this situation, you can specify an expression here that     */
/* returns 0U when such a situation is detected by the app (or expected by you). */
/* If you don't have problems with your watchdog, just define it to 1U so STIM   */
/* and bypassing feature is resumed always together with DAQ after ECU resets.   */

#define VX1000_IS_BYPASS_RESUME_ALLOWED() 1U


/* ----------------------------------------------------------------------------- */
/* STIM version 0 works out of the box, is supported by all FW versions and does */
/* not need additional RAM or configuration settings. However several advanced   */
/* features are only available in STIM version 1 (only supported by FW 1.8 and   */
/* newer!) If you want to use the advanced features, define VX1000_STIM_FORCE_V1 */
/* and configure the particular features below.                                  */

/*
#define VX1000_STIM_FORCE_V1
*/

#if defined (VX1000_STIM_FORCE_V1)
/* ----------------------------------------------------------------------------- */
/* configuration of STIM version 1 special features                              */


/* ----------------------------------------------------------------------------- */
/* Inform the VX1000 how a specific XCP event is to be handled. For each STIM    */
/* event, the following information must be provided: What is the associated     */
/* DAQ event (for the bypassing upload path) and which STIM type out of the      */
/* following set (VX1000_BYPASS_TYPE_DIRECT, VX1000_BYPASS_TYPE_OLDA,            */
/* VX1000_BYPASS_TYPE_HOOK) shall be used.                                       */

#define VX1000_SET_STIM_INFO() do                                                                        \
  {                                                                                                      \
    VX1000_REGISTER_STIM_EVENT(___associated_DAQ_event_ID, ___first_STIM_event_ID, ___desired_STIM_type) \
    ...                                                                                                  \
    VX1000_REGISTER_STIM_EVENT(___associated_DAQ_event_ID, ___last_STIM_event_ID , ___desired_STIM_type) \
  } while (0); /* dummy loop only here for MISRA */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide both empty and nonempty callbacks */



/* ----------------------------------------------------------------------------- */
/* Depending on the STIM type, the driver can be forced to wait for all channels */
/* to have receive complete/valid STIM data before the application will see data */

/*
#define VX1000_BYPASS_ALL_CHANS_STIMD
*/

/* ----------------------------------------------------------------------------- */
/* You may override VX1000_BYPASS_ALL_CHANS_STIMD in arbitrary situations for    */
/* any event E by defining the callback VX1000_IS_INSTANT_BYP_ALLOWED(E) to      */
/* evaluate to / return "1" in that case (and "0" otherwise)                     */

/*
#define VX1000_IS_INSTANT_BYP_ALLOWED(E) 0U
*/


/* ----------------------------------------------------------------------------- */
/* If the STIM type VX1000_BYPASS_TYPE_HOOK shall be used,                       */
/* VX1000_HOOK_BASED_BYPASSING must be enabled and configured below              */

/*
#define VX1000_HOOK_BASED_BYPASSING
*/


/* ----------------------------------------------------------------------------- */
/* Specify where in RAM the hook based bypassing lookup table resides            */

/*
#define VX1000_BYPASS_HBB_LUT_ADDR     ___address_of_the_HBB_lookup_table
*/


/* ----------------------------------------------------------------------------- */
/* Specify how many entries in the hook based bypassing lookup table exist       */

/*
#define VX1000_BYPASS_HBB_LUT_ENTRIES  ___number_of_entries_in_the_HBB_lookup_table
*/

#endif /* VX1000_STIM_FORCE_V1 */

/* ----------------------------------------------------------------------------- */
/* Force trace messages to be sent from the ECU to the POD even when large       */
/* buffers (either in the ECU or in the POD) are involved.                       */

#define VX1000_FLUSH_TRACE_FOR_STIM


/* ----------------------------------------------------------------------------- */
/* Unless undefined, VX1000_FLUSH_TRACE_FOR_STIM_MAX reduces the trace load that */
/* the VX1000_FLUSH_TRACE_FOR_STIM feature creates. The value must be chosen     */
/* wisely: a very low value may prevent reliable flushing, a very high value may */
/* not reliably prevent overruns in the trace path. Hint: Some targets allow the */
/* application to read SFRs reflecting e.g. the count of available Aurora lanes  */
/* or the threshold or depth of the trace FIFOs. Runtime-computed formulas based */
/* on SFRs usually work best, second best works a calibration variable that is   */
/* pre-initialised rather small and that is incremented via XCP after timeouts.  */

/*
#define VX1000_FLUSH_TRACE_FOR_STIM_MAX ___the_maximum_repeat_count_of_sending_dummy_packets_along_the_trace_channel
*/

/* ----------------------------------------------------------------------------- */
/* Unless undefined, VX1000_FLUSH_TRACE_FOR_STIM_USR(EVENT) is called after the  */
/* limit defined by VX1000_FLUSH_TRACE_FOR_STIM_MAX has been reached. This can   */
/* by used to make the VX1000_FLUSH_TRACE_FOR_STIM feature more robust on HW     */
/* with complicated trace pipeline structure (e.g. when each event channel feeds */
/* a different pipeline). Usually this callback is not needed or at least its    */
/* parameter can be ignored.                                                     */

/*
#define VX1000_FLUSH_TRACE_FOR_STIM_USR(EVENT) ___a_callback_with_hardware_specific_code_that_ultimately_flushes_the_trace_pipeline(EVENT);
*/

#endif /* VX1000_STIM */

/* ----------------------------------------------------------------------------- */
/* Define the maximum coldstart delay from VX1000_INIT_ASYNC_START to            */
/* VX1000_INIT_ASYNC_END in milliseconds (a value of 0 disables the delay).      */

/*
#define VX1000_COLDSTART_TIMEOUT_MS    ___the_number_of_milliseconds_to_wait_for_tool_during_coldstart
*/

/* ----------------------------------------------------------------------------- */
/* Turn on benchmarking of the cold start behaviour (undef this to save memory)  */

/*
#define VX1000_COLDSTART_BENCHMARK
*/

/* ----------------------------------------------------------------------------- */
/* Depending on the wiring of the ECU, software reset may not be visible for the */
/* VX and the measurement will not be restarted automatically when the ECU       */
/* finished booting. As a workaround, the driver provides a handshake mechanism  */
/* that allows the application to inform the VX via the VX1000_PREPARE_SOFTRESET */
/* API right before performing the reset. The maximum allowed delay of the       */
/* handshake must be specified here. If it is not defined, the API will be empty */

/*
#define VX1000_SOFTRESET_TIMEOUT_MS    ___the_number_of_milliseconds_to_wait_for_tool_before_a_softreset
*/

/* ----------------------------------------------------------------------------- */
/* Define VX1000_DETECTION if upon ECU boot the AppDriver shall check for        */
/* connection attempts by external measurement tools. This feature allows for    */
/* first-cycle measurment, coldstart calibration and startup page switching.     */
/* So basically this should be always enabled, but leave it undefined if the     */
/* resulting raise of boot time is inacceptable or you need to reduce code size. */

/*
#define VX1000_DETECTION
*/

/* ----------------------------------------------------------------------------- */
/* Define the waiting time inside VX1000_INIT_ASYNC_START in which the ECU will  */
/* check for connection attempts by external measurement tools. The value is     */
/* sensitive to many environmental conditions, e.g. for the various kinds of     */
/* MCU reset: when does the MCU signal release of reset on the debug port, when  */
/* does it start executing user code, when does the user's code finally call     */
/* VX1000_INIT_ASYNC_START(), which external delay accessDelayAfterECUHWResetUs  */
/* and/or accessDelayAfterEcuHwResetLongUs is configured in VXconfig/CANape etc. */

#define VX1000_DETECTION_TIMEOUT_US    ___the_number_of_microseconds_to_wait_for_tool_response_during_presence_check


/* ----------------------------------------------------------------------------- */
/* If you are using data trace but your MCU is incapable of tracing all writes   */
/* from each core to any memory you have to define VX1000_MEMSYNC_TRIGGER_COUNT  */
/* to a value in the range 1 to 8 (typically 1 is just fine and larger values    */
/* are only needed if the extra speed provided by tightly coupled RAMs shall be  */
/* exploited. If you never plan to use trace or if your favourite VX firmware    */
/* version is older than 3.2, just leave VX1000_MEMSYNC_TRIGGER_COUNT undefined. */

/*
#define VX1000_MEMSYNC_TRIGGER_COUNT   __optional_memsync_count_in_the_range_1_to_8
*/

#if defined(VX1000_MEMSYNC_TRIGGER_COUNT)
#if (VX1000_MEMSYNC_TRIGGER_COUNT == 1U)

/* ----------------------------------------------------------------------------- */
/* You may optionally define an address of memory that shall be used by the      */
/* AppDriver to send messages to the VX via memory write trace. If you leave     */
/* this undefined, the AppDriver will allocate and use memory inside gVX1000.    */
/* Hint for PCIe POD users: the address is (VX1000_PCIE_BAR0_START_ADDR+0x70UL). */

/*
#define VX1000_MEMSYNC_TRIGGER_PTR     ___an_optional_address_of_64_unused_bytes_that_every_core_can_write_to_and_whose_writes_are_all_traceable
*/

#elif (VX1000_MEMSYNC_TRIGGER_COUNT > 1U)

/* ----------------------------------------------------------------------------- */
/* Define at least VX1000_MEMSYNC_TRIGGER_COUNT addresses of memory that will    */
/* be used by the AppDriver to send messages to the VX via memory write trace.   */
/* A combination of VXconfig settings, A2L address extension values and of the   */
/* return values of the user's callback VX1000_CURRENT_CORE_IDX() are used at    */
/* runtime to choose the optimal trigger pointer per VX1000_EVENT() call.        */

#define VX1000_MEMSYNC_TRIGGER_PTR0    ___an_address_of_64_unused_bytes_that_every_core_can_write_to_and_whose_writes_are_all_traceable
#define VX1000_MEMSYNC_TRIGGER_PTR1    ___an_address_of_64_unused_bytes_that_one_core_can_write_to_quickly_and_whose_writes_are_traceable
#define VX1000_MEMSYNC_TRIGGER_PTR2    ___an_address_of_64_unused_bytes_that_one_core_can_write_to_quickly_and_whose_writes_are_traceable
#define VX1000_MEMSYNC_TRIGGER_PTR3    ___an_address_of_64_unused_bytes_that_one_core_can_write_to_quickly_and_whose_writes_are_traceable
#define VX1000_MEMSYNC_TRIGGER_PTR4    ___an_address_of_64_unused_bytes_that_one_core_can_write_to_quickly_and_whose_writes_are_traceable
#define VX1000_MEMSYNC_TRIGGER_PTR5    ___an_address_of_64_unused_bytes_that_one_core_can_write_to_quickly_and_whose_writes_are_traceable
#define VX1000_MEMSYNC_TRIGGER_PTR6    ___an_address_of_64_unused_bytes_that_one_core_can_write_to_quickly_and_whose_writes_are_traceable
#define VX1000_MEMSYNC_TRIGGER_PTR7    ___an_address_of_64_unused_bytes_that_one_core_can_write_to_quickly_and_whose_writes_are_traceable

#endif /* VX1000_MEMSYNC_TRIGGER_COUNT > 1 */

#endif /* VX1000_MEMSYNC_TRIGGER_COUNT */


/* ----------------------------------------------------------------------------- */
/* In all standard use cases the information about the measurement objects is    */
/* extracted at build time from the ELF file and stored in an A2L file on the    */
/* PC. Additionally the various tools support features like selecting from a     */
/* set of A2L files the one that matches the currently running app in the ECU    */
/* based on its ECU_ID or PSK. Since those A2L files publish information that    */
/* may be considered confidential or because the application uses malloc()/new() */
/* not all objects can be covered by such static A2L files on the PC. For those  */
/* cases enabling the define VX1000_MEAS_CFG_ENABLE allows the ECU app at its    */
/* runtime to announce objects and their attributes. Both fixed and variable     */
/* descriptions are supported by te API. If usage of variable descriptions is    */
/* to be expected furthermore the define VX1000_MEAS_CFG_RAMSIZE has to be       */
/* configured to allocate sufficient RAM for those descriptions. Leave all       */
/* undefined if you don't use these features (e.g. not all tools support them).  */

/*
#define VX1000_MEAS_CFG_ENABLE
#define VX1000_MEAS_CFG_RAMSIZE        ___the_size_in_bytes_to_be_allocated_by_the_driver_as_A2L_transmit_buffer
*/

/* ----------------------------------------------------------------------------- */
/* Calibration of flash at runtime is possible if the MCU supports it and if     */
/* the following defines are configured properly. The sub-feature of page        */
/* switching allows transaction-based calibrate and to undo the entire           */
/* calibration with a single command. Because this feature may alter also        */
/* code being executed by the ECU, you should know well what you're doing.       */

/*
#define VX1000_OVERLAY
*/

#if defined(VX1000_OVERLAY)

/* ----------------------------------------------------------------------------- */
/* By default, the overlay is activated in VX1000_INIT() call and stays active   */
/* all the time. If you need more control and want to switch between the overlay */
/* pages, this can be enabled by defining VX1000_MAILBOX_OVERLAY_CONTROL         */

#define VX1000_MAILBOX_OVERLAY_CONTROL


/* ----------------------------------------------------------------------------- */
/* VX1000_OVL_INVALIDATE_CACHE_CB must be defined if MailboxControl shall call   */
/* application callback for cache invalidation when requested by VX1000 because  */
/* overlay data has been modified.                                               */
/* VX1000_OVL_INVALIDATE_CACHE_CB must be defined as the name of the application */
/* callback function for ECU overlay cache invalidation.                         */
/* This feature can only be used with ECU defined overlay mode.                  */

/*
#define VX1000_OVL_INVALIDATE_CACHE_CB()   ___a_void_function_that_invalidates_the_overlay_cache();
*/

/* ----------------------------------------------------------------------------- */
/* By defining or undefining VX1000_OVERLAY_USER_MANAGED the system architecture */
/* is massively influenced. When defined, the user application polls on the main */
/* core using Vector_POD_PSS_CAL_Get_Page_Switch_Request() for tool requests to  */
/* switch the page, manually distributes the request to all cores, on all cores  */
/* executes proprietary code to locally switch the page, concentrates the local  */
/* results of the operation on the main core and there transmits the overall     */
/* result using Vector_POD_PSS_CAL_Set_Page_Switch_Status to POD and tool.       */
/* If all these actions should be delegated to either POD or PSS, however, this  */
/* define must not be enabled but instead a lot of the following defined needs   */
/* to be filled correctly to allow POD/PPS to perform the actions autonomously.  */

/*
#define VX1000_OVERLAY_USER_MANAGED
*/

/* ----------------------------------------------------------------------------- */
/* For flash port controller based overlays, the controller's base address must  */
/* be provided. If the MCU has multiple port controller, here one of them can be */
/* freely chosen. The driver will take control of it, so it must not be used by  */
/* other drivers / parts of the application. Leave this undefined, if another    */
/* overlay mechanism (Autosar/Callbacks/MMU/...) is used.                        */

/*
#define VX1000_FLASHPORTCTLR_BASE_ADDR ___a_derivative_dependent_hardware_base_address
*/

/* ----------------------------------------------------------------------------- */
/* By default, the overlay is configured statically by the defines in this       */
/* header. For some derivatives, you can enable dynamic configuration of the     */
/* overlay(s) based on the requests of the tool to gain better resource          */
/* utilisation.                                                                  */

/*
#define VX1000_OVERLAY_VX_CONFIGURABLE
*/

#if defined(VX1000_OVERLAY_VX_CONFIGURABLE)


/* ----------------------------------------------------------------------------- */
/* Enable the desired overlay features depending on the ECU capabilities         */

/* Can the application handle keep-awakes correctly?                             */
#define VX1000_OVLENBL_KEEP_AWAKE
/* Does the application want to verify the working page before page switch?      */
#define VX1000_OVLENBL_VALIDATE_PAGESW
/* Has the EMEM a dedicated power supply?                                        */
#define VX1000_OVLENBL_PERSISTENT_EMEM
/* Will the application perform a soft-reset after it detected a CAL-Wakeup?     */
#define VX1000_OVLENBL_RST_ON_CALWAKEUP
/* Shall the EPK address of the WP be calculated by the VX1000?                  */
#define VX1000_OVLENBL_USE_VX_EPK_TRANS

#else /* !VX1000_OVERLAY_VX_CONFIGURABLE */

/* ----------------------------------------------------------------------------- */
/* A static definition of the overlay memory areas must be provided in this mode */
/* By default, the driver assumes that the application uses a 1:1 address        */
/* mapping to access the memory and thus the defines VX1000_OVERLAY_PHYSADDR     */
/* and VX1000_CALRAM_PHYSADDR need only to be provided if both the MCU provides  */
/* the feature of non-1:1 mappings and the application actually makes use of it. */

#define VX1000_OVERLAY_SIZE            ___the_size_of_the_to_be_overlaid_flash_area_of_supported_granularity
#define VX1000_OVERLAY_ADDR            ___the_virtual_address_of_the_to_be_overlaid_flash_area_of_supported_alignment
#define VX1000_CALRAM_ADDR             ___the_virtual_address_of_the_unused_RAM_area_that_shall_overlay_the_flash
/*
#define VX1000_OVERLAY_PHYSADDR        ___the_optional_physical_address_for_VX1000_OVERLAY_ADDR
#define VX1000_CALRAM_PHYSADDR         ___the_optional_physical_address_for_VX1000_CALRAM_ADDR
*/

/* ----------------------------------------------------------------------------- */
/* Select which hardware (sub-)module in the ECU shall perform the overlay       */
/* address mapping. These settings depend on the derivative AND on the start-up  */
/* code AND on the application and potentially other XCP drivers. Only one       */
/* method can be activated for a given setup. If your hardware has a flash port  */
/* controller capable of forwarding reads to different address maps, reserve     */
/* one of its descriptors for VX1000 usage where a value 0..15 means secure      */
/* redundancy mode OR use value mod 32 in big mode). If the ECU lacks such a     */
/* controller but offers a memory management unit MMU, choose one TLB entry      */
/* inside TLB1 to perform the address mapping. Note that this choice must        */
/* match exactly the start-up code of your application!                          */

/*
#define VX1000_OVERLAY_DESCR_IDX       ___the_correct_index_of_the_descriptor_that_is_used_in_the_PFLASH_unit_to_map_the_overlay_area
*/
/*
#define VX1000_OVERLAY_TLB             ___the_correct_index_of_the_TLB_entry_that_is_used_in_the_MMU_to_map_the_overlay_area
*/

/* ----------------------------------------------------------------------------- */
/* Several PowerPC derivatives support two different access modes concerning     */
/* the endianess of data > 1 byte in memory. By default big endian mode is used  */
/* by most PowerPCs, but if you compiled your application in little endian mode, */
/* you have to inform the driver about this unusual configuration by defining    */
/* VX1000_OVERLAY_IS_LITTLE_ENDIAN. Leave undefined for big endian mode.         */

/*
#define VX1000_OVERLAY_IS_LITTLE_ENDIAN
*/

/* ----------------------------------------------------------------------------- */
/* Several PowerPC derivatives support two different instruction sets: BookE     */
/* (which is the standard and thus the default setting in the driver) and VLE    */
/* while other derivatives support only one of them. In the cases where you      */
/* activated VLE mode for the group mentioned first AND if your overlaid flash   */
/* window does not only contain data but also code, you must tell the driver so  */
/* by defining VX1000_OVERLAY_CONTAINS_VLECODE. Leave undefined for BookE code.  */

/*
#define VX1000_OVERLAY_CONTAINS_VLECODE
*/

/* ----------------------------------------------------------------------------- */
/* Several PowerPC derivatives lack a global address remap unit and the driver   */
/* has to manage the local MMU of the various cores to perform overlay page      */
/* switching. On multi-core processors, the driver by default only manages the   */
/* overlay of the main core. If you want it to manage also the slave cores'      */
/* (under the assumption, that the slave core actually has a MMU and that it     */
/* is initialised in the same manner as the main core's, you have to define      */
/* VX1000_OVLENBL_HW_INIT_PER_CORE. Leave undefined for single cores.            */

/*
#define VX1000_OVLENBL_HW_INIT_PER_CORE
*/

#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE */

/* ----------------------------------------------------------------------------- */
/* Core synchronous page switching means that each core switches the overlay     */
/* unit in the microcontroller for its own. In a multicore system there are      */
/* several points in time where the page switch is performed (corresponding to   */
/* the number of cores). Each core may switch its page outside of all tasks      */
/* that are running on this core. This option is only possible when the          */
/* microcontroller's overlay unit supports independent page switches for the     */
/* cores. On the other hand it is a must on those multicore systems where each   */
/* core brings an independent overlay unit that can only be programmed by the    */
/* core itself (e.g. core-internal MMU; see VX1000_OVLENBL_HW_INIT_PER_CORE).    */
/* The feature is enabled when VX1000_OVLENBL_CORE_SYNC_PAGESW is defined.       */

#if defined(VX1000_OVLENBL_HW_INIT_PER_CORE)
#define VX1000_OVLENBL_CORE_SYNC_PAGESW
#endif /* VX1000_OVLENBL_HW_INIT_PER_CORE */

/* ----------------------------------------------------------------------------- */
/* Synchronous calibration page switching means that the ECU is signalled by     */
/* the VX1000 to perform a page switch. The VX1000 pre-configures the overlay    */
/* registers and signals the ECU which overlay register sets should be           */
/* enabled/disabled. Before the ECU performs the page switch additional          */
/* validation checks can be performed. If the application requires a             */
/* task- or core- synchronous page switching, the application is responsible     */
/* for executing the page switch only in synchronised situations. If you leave   */
/* VX1000_OVLENBL_SYNC_PAGESWITCH undefined the VX1000 will switch the page in   */
/* the background without ECU application interaction.                           */

/*
#define VX1000_OVLENBL_SYNC_PAGESWITCH
*/

#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW) || defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
/* ----------------------------------------------------------------------------- */
/* In multi-core (or better "multi-bus-master") environments, it may be          */
/* desirable to make the overlay visible to only some of the bus masters while   */
/* the remaining masters shall continue accessing the reference page. For this   */
/* purpose you have to define a bit mask VX1000_OVL_CAL_BUS_MASTER according     */
/* to the PFlash register definition of your MCU. This value must be the logic   */
/* OR of all VX1000_OVL_CAL_BUS_MASTER_x values (x = any running core).          */

#define VX1000_OVL_CAL_BUS_MASTER      ___a_derivative_dependent_bitmask_of_relevant_PFLASH_busmasters

/* ----------------------------------------------------------------------------- */
/* In multi-core (or better "multi-bus-master") environments, the following      */
/* defines configure per core (as retrieved by VX1000_CURRENT_CORE_IDX())        */
/* which bus masters will see the overlay when this core switches to the         */
/* working page. Usually these are values with only a single bit set, but you    */
/* are free to set multiple bits for e.g. associating DMA/Flexray/Nexus/etc.     */
/* controllers with a particular CPU core to force consistent view on constants. */

/*
#define VX1000_OVL_CAL_BUS_MASTER_0    ___a_derivative_dependent_bitmask_for_core0
#define VX1000_OVL_CAL_BUS_MASTER_1    ___a_derivative_dependent_bitmask_for_core1
#define VX1000_OVL_CAL_BUS_MASTER_2    ___a_derivative_dependent_bitmask_for_core2
#define VX1000_OVL_CAL_BUS_MASTER_3    ___a_derivative_dependent_bitmask_for_core3
#define VX1000_OVL_CAL_BUS_MASTER_4    ___a_derivative_dependent_bitmask_for_core4
#define VX1000_OVL_CAL_BUS_MASTER_5    ___a_derivative_dependent_bitmask_for_core5
#define VX1000_OVL_CAL_BUS_MASTER_6    ___a_derivative_dependent_bitmask_for_core6
#define VX1000_OVL_CAL_BUS_MASTER_7    ___a_derivative_dependent_bitmask_for_core7
#define VX1000_OVL_CAL_BUS_MASTER_8    ___a_derivative_dependent_bitmask_for_core8
#define VX1000_OVL_CAL_BUS_MASTER_9    ___a_derivative_dependent_bitmask_for_core9
*/

/* ----------------------------------------------------------------------------- */
/* If the application performs an ECU reset after page switches (e.g. as very    */
/* rude method for synchronising multiple cores and DMA controllers) the VX must */
/* be informed beforehand about this behaviour by enabling the following define. */

/*
#define VX1000_OVLENBL_RST_ON_SNCPAGESW
*/

#endif /* VX1000_OVLENBL_CORE_SYNC_PAGESW || VX1000_OVLENBL_SYNC_PAGESWITCH */


#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS)
/* ----------------------------------------------------------------------------- */
/* Define the location of a string that identifies currently active calibration  */
/* and that will be retrieved by subcommand 5 of XCP GET_ID. This allows CANape  */
/* to select the right version of the parameter set and verify consistency with  */
/* the reference page.                                                           */

#define VX1000_OVL_EPK_REFPAGE_ADDR    ___the_correct_address
#define VX1000_OVL_EPK_LENGTH          ___the_correct_size

#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS */

#endif /* VX1000_OVERLAY */


/* ----------------------------------------------------------------------------- */
/* Enable the mailbox to forward some XCP commands between tool and application  */
/* It can be used e.g. for printf, page switching, copy page or page relocation  */
/* The sub features can be enabled or disabled individually and are only active  */
/* if VX1000_MAILBOX is defined. The default mailbox has a reasonable size for   */
/* the average purpose but the size may still be overridden below                */

/*
#define VX1000_MAILBOX
*/
/*
#define VX1000_MAILBOX_SLOTS           ___an_optional_number_that_must_be_a_power_of_two_greater_than_one
#define VX1000_MAILBOX_SLOT_DWORDS     ___an_optional_number_that_must_be_greater_than_two
#define VX1000_MAILBOX_MS_DWORDS       ((VX1000_MAILBOX_SLOT_DWORDS) * (VX1000_MAILBOX_SLOTS))
#define VX1000_MAILBOX_SM_DWORDS       ((VX1000_MAILBOX_SLOT_DWORDS) * (VX1000_MAILBOX_SLOTS))
*/

/* ----------------------------------------------------------------------------- */
/* Enable this to allow the application to send formatted XCP SERV_TEXT messages */

/*
#define VX1000_MAILBOX_PRINTF
*/

/* ----------------------------------------------------------------------------- */
/* Enable this if a reduced printf version instead of the full one is sufficient */

/*
#define VX1000_PRINTF_MINIMAL
*/


/* ----------------------------------------------------------------------------- */
/* Enable these to provide a special upload or download API                      */

/*
#define VX1000_MAILBOX_PROVIDE_SPLITREAD
#define VX1000_MAILBOX_PROVIDE_SPLITWRITE
*/
#if !defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
#define VX1000_MAILBOX_NO_SPLITREAD       1 /* suppress this mailbox sub-features in a MISRA conform way */
#endif /* !VX1000_MAILBOX_PROVIDE_SPLITREAD */
#if !defined(VX1000_MAILBOX_PROVIDE_SPLITWRITE)
#define VX1000_MAILBOX_NO_SPLITWRITE      1 /* suppress this mailbox sub-features in a MISRA conform way */
#endif /* !VX1000_MAILBOX_PROVIDE_SPLITWRITE */


#if defined(VX1000_ENABLE_RADAR_API)
/* ----------------------------------------------------------------------------- */
/* If you want to use a PCIe interface for measurement purposes, at least one    */
/* BAR area must be specified to allow exchange of data between the AppDriver    */
/* and the PCIe POD. The size of this area - typically 16Mb - has to be given    */
/* via define VX1000_PCIE_BAR0_SIZE_BYTES and the start address via define       */
/* VX1000_PCIE_BAR0_START_ADDR. Leave both undefined if PCIe is not to be used.  */

/*
#define VX1000_PCIE_BAR0_SIZE_BYTES    0x01000000UL
#define VX1000_PCIE_BAR0_START_ADDR    ___the_virtual_start_address_of_the_PCIe_BAR_area
*/

/* ----------------------------------------------------------------------------- */
/* In special use cases the VX1000 isn't the exclusive user of the selected PCIe */
/* interface. You tell the VX so by undefining VX1000_PCIE_IS_EXCLUSIVE_FOR_VX.  */

#define VX1000_PCIE_IS_EXCLUSIVE_FOR_VX

/* ----------------------------------------------------------------------------- */
/* To be able to use a PCIe interface for measurement purposes, several target   */
/* specific SFRs of the ECU must be written to establish a link. Depending on    */
/* the use case either the ECU application or the VX1000 would perform this      */
/* setup. If it is the ECU, define VX1000_PCIELINK_IS_SETUP_BY_ECU to tell the   */
/* VX1000 to not touch the SFRs. Leave undefined to give the task to the VX1000. */

/*
#define VX1000_PCIELINK_IS_SETUP_BY_ECU
*/

#endif /* VX1000_ENABLE_RADAR_API */


/* ----------------------------------------------------------------------------- */
/* If the MCU includes a DTS semaphore peripheral, you should specify it's base  */
/* address here. This makes the driver signal olda events via that hardware      */
/* (which typically improves performance in multicore systems). If you don't     */
/* provide the address, normal signalling via gVX1000 is used.                   */

/*
#define VX1000_OLDA_DTS_BASE_ADDR      ___the_correct_DTS_address_for_your_MCU
*/

/* ----------------------------------------------------------------------------- */
/* If the MCU includes both an LFAST and a standalone SIPI module and you plan   */
/* to exploit this SIPI module for VX measurements, you should specify the base  */
/* address of the interprocessor LFAST module. Otherwise leave it undefined.     */

/*
#define VX1000_SIPI_BASEADDR           ___the_correct_SIPI_address_for_your_MCU
#define VX1000_LFAST_BASEADDR          ___the_correct_LFAST_address_for_your_MCU
*/
#define VX1000_LFAST_PLLMULOFS         1UL /* the documented and thus default value is one but some derivatives instead use zero! */

/* ----------------------------------------------------------------------------- */
/* Because the SIPI pin usage depends on the derivative and on top of that the   */
/* pads are multiplexed with other modules, you must provide a few code lines    */
/* that initialise the LFAST clock pin for output mode, the LFAST Rx pin pair    */
/* for LVDS input and the LFAST Tx pair for LVDS output (see SIUL xCR registers) */
/* This macro is entirely ignored if VX1000_LFAST_BASEADDR is not defined.       */

#define VX1000_SIPI_CLK_TXN_TXP_RXN_RXP() do                                                 \
  {                                                                                          \
    (VX1000_ADDR_TO_PTR2VU32(0xFFFC0240UL))[..] = 0x........UL;   /* Configure CLKOUT pin */ \
    (VX1000_ADDR_TO_PTR2VU32(0xFFFC0240UL))[..] = 0x........UL;   /* Configure Tx_N pin */   \
    (VX1000_ADDR_TO_PTR2VU32(0xFFFC0240UL))[..] = 0x........UL;   /* Configure Tx_P pin */   \
    (VX1000_ADDR_TO_PTR2VU32(0xFFFC0240UL))[..] = 0x........UL;   /* Configure Rx_N pin */   \
    (VX1000_ADDR_TO_PTR2VU32(0xFFFC0240UL))[..] = 0x........UL;   /* Configure Rx_P pin */   \
  } while (0); /* dummy loop only here for MISRA */ /* PRQA S 3412 */ /* Willingly violating MISRA rule 19.4 to be able to provide both empty and nonempty callbacks */


/* ----------------------------------------------------------------------------- */
/* Physically LFAST allows a reference clock of 10, 13, 20 and 26 MHz, which     */
/* has to be pre-initialised by the application before calling VX1000_INIT().    */
/* Because FSL discourages usage of 13 and 26 MHz and STM encourages usage of    */
/* 20 MHz, the AppDriver by default assumes 20MHz and does not support 13 or 26  */
/* MHz. However a 10 MHz reference clock is supported by the AppDriver and it    */
/* will be used correctly whenever VX1000_LFAST_REFCLOCK_IS_10MHZ is defined.    */

/*
#define VX1000_LFAST_REFCLOCK_IS_10MHZ
*/

/* ----------------------------------------------------------------------------- */
/* If the wiring and/or operation environment of the LFAST connection do not     */
/* allow reliable transmissions at 320MHz, you must force the interface to work  */
/* in the robust low speed mode (5MHz) by defining VX1000_LFAST_FORCE_LOWSPEED.  */
/* The corresponding VXplugin/VXconfig setting digrfForceLowSpeedTrx must be set */
/* consistently. Leave undefined whenever the normal speed works reliably.       */

/*
#define VX1000_LFAST_FORCE_LOWSPEED
*/


/* ----------------------------------------------------------------------------- */
/* This enables and configures the Resource Management feature.                  */
/* This features helps to divide the resources of the micro-controller between   */
/* the application of the ECU and the VX1000 AppDriver.                          */

/*
#define VX1000_RES_MGMT
*/

#if defined(VX1000_RES_MGMT)
/* ----------------------------------------------------------------------------- */
/* With this define the switches VX1000_RES_MGMT_RAM_START and                   */
/* VX1000_RES_MGMT_RAM_SIZE are used to specify a memory-region that the VX1000  */
/* AppDriver and the VX1000 hardware should use exclusively for measurement and  */
/* calibration purposes (e.g. overlay, data trace, OLDA). This memory region     */
/* shall not be accessed by the ECU application. Especially RAM checks/tests     */
/* or memory/CRC initialisations are not permitted. As a result of this          */
/* requirement the gVX1000 structure and the overlay EMEM headers (EMEM_HDR)     */
/* shall not be located in this resource management memory region. If            */
/* VX1000_OLDA_MEMORY_ADDR is explicitly defined, this memory shall not be       */
/* located in the resource management memory region. Usually this feature is     */
/* used to divide the emulation memory of a development device                   */

/*
#define VX1000_RES_MGMT_ENABLE_OVL_RAM
#define VX1000_RES_MGMT_RAM_START      ___the_correct_address  -- note: had been called VX1000_RES_MGMT_OVL_RAM_START in the past
#define VX1000_RES_MGMT_RAM_SIZE       ___the_correct_size     -- note: had been called VX1000_RES_MGMT_OVL_RAM_SIZE in the past
*/

/* ----------------------------------------------------------------------------- */
/* With define pairs VX1000_RES_MGMT_RAM_START_1 and VX1000_RES_MGMT_RAM_SIZE_1, */
/* VX1000_RES_MGMT_RAM_START_2 and VX1000_RES_MGMT_RAM_SIZE_2,                   */
/* VX1000_RES_MGMT_RAM_START_3 and VX1000_RES_MGMT_RAM_SIZE_3 up to three        */
/* additional memory-regions can be specified for resource management.           */

/*
#define VX1000_RES_MGMT_RAM_START_1    ___the_correct_address
#define VX1000_RES_MGMT_RAM_SIZE_1     ___the_correct_size
*/

/*
#define VX1000_RES_MGMT_RAM_START_2    ___the_correct_address
#define VX1000_RES_MGMT_RAM_SIZE_2     ___the_correct_size
*/

/*
#define VX1000_RES_MGMT_RAM_START_3    ___the_correct_address
#define VX1000_RES_MGMT_RAM_SIZE_3     ___the_correct_size
*/

#endif /* VX1000_RES_MGMT */



/* ----------------------------------------------------------------------------- */
/* You should include here the header(s) that provide the data types and the     */
/* prototypes or SFR definitions that you will use as the application callbacks  */
/* At this point, the selection of the used VX driver features is complete and   */
/* the included header(s) may evaluate the above defines to provide only the     */
/* desired functionality. This way, you will not run into compiler or MISRA      */
/* warnings about uncalled functions and such.                                   */

/*
#include "___my_header_that_provides_the_needed_declarations.h"
*/


/* ----------------------------------------------------------------------------- */
/* The optional macro VX1000_GENERIC_INIT_CB() can be used to define special     */
/* initialsisations to be performed by the main core in VX1000If_InitAsyncStart. */
/* Examples are optimising the driver strength of the debug pins, powering the   */
/* timer used by VX1000_CLOCK(), enabling the ResetOut feature on the debug port */

/*
#define VX1000_GENERIC_INIT_CB()
*/


/* ----------------------------------------------------------------------------- */
/* If the XCP features shall be used on more than one core, the driver needs     */
/* an indicator whether it is running on the "main" core that is actively        */
/* initialising a stable high resolution time base to correctly detect           */
/* communication timeouts and optionally for time stamping the XCP packets.      */
/* The "main" core is also the one to handle the mailbox and the overlay system. */
/* Leave undefined if the entire instrumentation is executed on a single core.   */

/*
#define VX1000_RUNNING_ON_MAINCORE()   ((xxx == VX1000_CURRENT_CORE_IDX())? 1U : 0U)
*/

/* ----------------------------------------------------------------------------- */
/* Sometimes the driver needs to access data structures that need to be indexed  */
/* by the currently active CPU core. Define VX1000_CURRENT_CORE_IDX() in such a  */
/* way that for each core it returns a bijective index in the range [0,n), with  */
/* n being the total number of cores.                                            */

/*
#define VX1000_CURRENT_CORE_IDX()      ___a_unique_index_in_the_range_0_to_one_less_than_n()
*/

/* ----------------------------------------------------------------------------- */
/* If the VX API is called interruptible in multitasking systems or even used    */
/* on multicore systems, VX internal variables might become corrupted, which by  */
/* default is prevented by usage of the callback pair VX1000_ENTER_SPINLOCK() +  */
/* VX1000_LEAVE_SPINLOCK() to the cost of increased runtime. Some MCUs however   */
/* offer sync mechanisms in hardware via atomic read-modify-write memory access  */
/* instructions. You may optimise execution speed by defining some of these.     */

/*
#define VX1000_ATOMIC_XOR32(A, D)      ___an_optional_function_that_XORs_32bit_value_D_to_the_memory_at_addresse_A(...);
*/

/* ----------------------------------------------------------------------------- */
/* Provide an appropriate MUTEX mechanism to interlock code running on different */
/* task priorities, interrupt levels and multicore execution units. If you leave */
/* these undefined, the driver will assume a non-preemptive single core system   */
/* and not try to be thread-safe. Rest assured exclusive code parts are short.   */
/* Please understand the "portmanteau word" nature of the names: ENTER_SPINLOCK  */
/* is short for ENTER_CRITICAL_AND_ACQUIRE_SPINLOCK (in that order) while name   */
/* LEAVE_SPINLOCK represents RELEASE_SPINLOCK_AND_LEAVE_CRITICAL (inverse order) */

/*
#define VX1000_ENTER_SPINLOCK()        ___a_function_that_suppresses_execution_of_any_other_thread_until_VX1000_LEAVE_SPINLOCK_is_called();
#define VX1000_LEAVE_SPINLOCK()        ___a_function_that_restores_the_suppression_state_from_before_VX1000_ENTER_SPINLOCK_was_called();
*/

/* ----------------------------------------------------------------------------- */
/* If your compiler with your used compiler settings emits for writes to 64 bit  */
/* variables two 32 bit store instructions instead of one single 64 bit store    */
/* instruction, for several VX features to work properly you have to manually    */
/* provide an assembly callback that performs a 64 bit store to the naturally    */
/* aligned linear address in parameter 1 with the values of parameters 2 and 3   */
/* concatenated to form the 32+32=64 bit store data, and hook that to the        */
/* macro VX1000_STORE64. You may leave this undefined if the user data type      */
/* VX1000_UINT64 is not provided or if the compiler creates 64 bit stores.       */
/* Keep in mind that on heterogeneous MCUs this solution must work on ANY core.  */

#define exampleVX1000_STORE64(A,HI,LO) do { ((VX1000_ADDR_TO_PTR2VU64((A))))[0] = (((VX1000_UINT64)(HI) << 3) << 29) | (VX1000_UINT64)(LO); } while (0)  /* This is just an example in C to be overruled by an assembly implementation with real 64-bit-store operation. */
/*
#define VX1000_STORE64(A, HI, LO )     ___a_macro_that_atomically_64bit_stores_the_concatenation_of_two_32bit_numbers_HI_and_LO_to_the_given_linear_address_A((A), (HI), (LO))
*/

/* ----------------------------------------------------------------------------- */
/* If the application uses Autosar single pointer calibration via XCP, the       */
/* VX blindly sends all up- and download via mailbox to the application and it   */
/* is up to the application to inject the currently active address translation   */

/*
#define VX1000_SHORT_UPLOAD(D, S, L)   ___a_function_that_proprietarily_copies_L_bytes_from_S_to_D(...);
#define VX1000_SHORT_DOWNLOAD(D, S, L) ___a_function_that_proprietarily_copies_L_bytes_from_S_to_D(...);
*/

/* ----------------------------------------------------------------------------- */
/* Whenever the XCP tool starts a new measurement on any slave, the execution of */
/* the following callback is triggered to allow the application to immediately   */
/* trigger non-cyclic/infrequent events at least once that otherwise might not   */
/* occur at all during rather short measurements. Leave undefined if not needed. */

/*
#define VX1000_DAQ_STARTED_CB()        ___any_actions_the_app_may_want_to_take_upon_the_start_of_a_new_measurement();
*/

#if defined(VX1000_ENABLE_RADAR_API)
/* ----------------------------------------------------------------------------- */
/* Several target interfaces (like LINKTYPE==0 -> PCIe) need handshake actions   */
/* on both ends for fully establishing a link. If you plan to use at least one   */
/* of those interfaces you have to provide a callback via defining the macro     */
/* VX1000_TRIGGER_DISCOVERING_CB to handle requests of re-discovery on the link  */
/* type specified in the parameter. Leave undefined if no discovery is needed.   */

/*
#define VX1000_TRIGGER_DISCOVERING_CB(LINKTYPE) ___any_actions_the_app_must_take_when_an_external_tool_wants_to_be_discovered_on_that_link(LINKTYPE);
*/

#endif /* VX1000_ENABLE_RADAR_API */

#if defined(VX1000_OVERLAY)

#if defined(VX1000_OVERLAY_TLB)

/* ----------------------------------------------------------------------------- */
/* On PowerPC, the memory management unit cannot be configured from extern       */
/* and thus the VX has to let the driver execute special assembler instructions  */
/* that write the related core registers. The syntax depends on the used         */
/* compiler and even on the used compiler options, so the user must provide      */
/* the following interface                                                       */

#define VX1000_MPC_MMU_MTMAS0(M)       ___assembly_code_that_performs_a_MTSPR_624,_M_PowerPC_instruction(...);
#define VX1000_MPC_MMU_MTMAS1(M)       ___assembly_code_that_performs_a_MTSPR_625,_M_PowerPC_instruction(...);
#define VX1000_MPC_MMU_MTMAS2(M)       ___assembly_code_that_performs_a_MTSPR_626,_M_PowerPC_instruction(...);
#define VX1000_MPC_MMU_MTMAS3(M)       ___assembly_code_that_performs_a_MTSPR_627,_M_PowerPC_instruction(...);
#define VX1000_MPC_MMU_TLBWE()         ___assembly_code_that_performs_a_TLBWE_PowerPC_instruction(...);

#elif (!defined(VX1000_OVERLAY_USER_MANAGED)) && ((!defined(VX1000_OVERLAY_DESCR_IDX)) && (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)))

/* ----------------------------------------------------------------------------- */
/* As you did not provide configuration of the built-in overlay handling, you    */
/* must provide callbacks for manual handling the hardware and memory sections.  */
/* You probably may want to reuse the API of an XCP on CAN driver but as well    */
/* you may provide your very own implementation of all these callbacks:          */

#define VX1000_INIT_CAL_PAGE()                       ___a_function_that_initialises_the_calpage_handler();
#define VX1000_GET_CAL_PAGE(seg, mod)                ((VX1000_UINT8)___a_function_that_handles_XCP_get_calpage_command(...))
#define VX1000_SET_CAL_PAGE(seg, pag, mod, startup)  ((VX1000_UINT8)___a_function_that_handles_XCP_set_calpage_command(...))  /* note: the 4th parameter is only needed for FW >= 1.7 */
#define VX1000_COPY_CAL_PAGE(sseg, spag, dseg, dpag) ((VX1000_UINT8)___a_function_that_handles_XCP_copy_calpage_command(...))

#endif /* !VX1000_OVERLAY_USER_MANAGED && !VX1000_OVERLAY_TLB && !VX1000_OVERLAY_DESCR_IDX && !VX1000_OVERLAY_VX_CONFIGURABLE */


/* ----------------------------------------------------------------------------- */
/* If desired by the application, the driver may call hook functions in some     */
/* situations. Just define some of the following callback defines to let your    */
/* code be called                                                                */

/*
#define VX1000_OVL_RST_ON_CAL_WAKEUP_CB()                    ___a_void_function_with_userdefined_behaviour();
*/
/*
#define VX1000_SYNCAL_VALIDATE_WP_CB(addr)                   ___an_expression_or_function_whose_return_value_influences_the_behaviour_of_the_builtin_VX1000_SET_CAL_PAGE_function(...)
#define VX1000_SYNCAL_USRVALIDATE_WP_CB(value, mask, master) ___an_expression_or_function_whose_return_value_influences_the_behaviour_of_the_builtin_VX1000_SET_CAL_PAGE_function(...)
*/
#endif /* VX1000_OVERLAY */

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

#endif /* !VX1000_CFG_H */

