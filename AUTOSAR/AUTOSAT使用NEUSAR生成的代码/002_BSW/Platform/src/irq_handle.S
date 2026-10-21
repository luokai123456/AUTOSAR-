
#ifdef __HIGHTEC__
#define e_bne bne
#endif
    .globl   IVOR0_Handler
    .globl   IVOR1_Handler
    .globl   IVOR2_Handler
    .globl   IVOR3_Handler
    .globl   IVOR4_Handler
    .globl   IVOR5_Handler
    .globl   IVOR6_Handler
    .globl   IVOR7_Handler
    .globl   IVOR8_Handler
    .globl   IVOR9_Handler
    .globl   IVOR10_Handler
    .globl   IVOR11_Handler
    .globl   IVOR12_Handler
    .globl   IVOR13_Handler
    .globl   IVOR14_Handler
    .globl   IVOR15_Handler
    .globl   SetupE2EECSR0_for_1b_ECC_fault
    .globl   SetupE2EECSR0_for_2b_ECC_fault
    .globl   SetupE2EECSR0_for_ClearECC
    .globl   SetupE2EECSR0_for_ClearWRC
#ifndef __HIGHTEC__
    .extern  IVOR0_Exception_Handler
    .extern  IVOR1_Exception_Handler
    .extern  IVOR2_Exception_Handler
    .extern  IVOR3_Exception_Handler
    .extern  IVOR5_Exception_Handler
    .extern  IVOR6_Exception_Handler
    .extern  IVOR7_Exception_Handler
    .extern  IVOR8_Exception_Handler
    .extern  IVOR10_Exception_Handler
    .extern  IVOR11_Exception_Handler
    .extern  IVOR12_Exception_Handler
    .extern  IVOR13_Exception_Handler
    .extern  IVOR14_Exception_Handler
    .extern  IVOR15_Exception_Handler
#endif
#ifdef __HIGHTEC__ /* HighTec */
    #define e_bdnz bdnz
    #define e_beq  beq
    #define e_subi subi
    #define e_bne  bne
#endif
#ifdef __ghs__
    .section    .vletext, axv
    .vle
#endif
    .equ  INTC_IACKR_0, 0xfc040020  ;# Interrupt Acknowledge Register address
    .equ  INTC_EOIR_0,  0xfc040030   ;# End Of Interrupt Register address
    .equ  INTC_IACKR_1, 0xfc040024  ;# Interrupt Acknowledge Register address
    .equ  INTC_EOIR_1,  0xfc040034   ;# End Of Interrupt Register address
    .equ  INTC_IACKR_2, 0xfc040028  ;# Interrupt Acknowledge Register address
    .equ  INTC_EOIR_2,  0xfc040038   ;# End Of Interrupt Register address
    .equ  INTC_IACKR_3, 0xfc04002C  ;# Interrupt Acknowledge Register address
    .equ  INTC_EOIR_3,  0xfc04003C   ;# End Of Interrupt Register address
    .equ  INTC_IACKR_4, 0xfc042020  ;# Interrupt Acknowledge Register address
    .equ  INTC_EOIR_4,  0xfc042030   ;# End Of Interrupt Register address
    .equ  INTC_IACKR_5, 0xfc042024  ;# Interrupt Acknowledge Register address
    .equ  INTC_EOIR_5,  0xfc042034   ;# End Of Interrupt Register address
    .align 4

;# Store/Restore common GPRs (GPR3-GPR12 stack offset 0x24-0x48)
;#     prolog_GPRs: Store GPRs
;#     epilog_GPRs: Restore GPRs
prolog_GPRs:
    se_stw   r3,  0x24(r1)            # Store GPR3
    se_stw   r4,  0x28(r1)            # Store GPR4
    se_stw   r5,  0x2C(r1)            # Store GPR5
    se_stw   r6,  0x30(r1)            # Store GPR6
    se_stw   r7,  0x34(r1)            # Store GPR7
    e_stw    r8,  0x38(r1)            # Store GPR8
    e_stw    r9,  0x3C(r1)            # Store GPR9
    e_stw    r10, 0x40(r1)            # Store GPR10
    e_stw    r11, 0x44(r1)            # Store GPR11
    e_stw    r12, 0x48(r1)            # Store GPR12
    se_blrl

epilog_GPRs:
    se_lwz   r3,  0x24(r1)            # Restore GPR3
    se_lwz   r4,  0x28(r1)            # Restore GPR4
    se_lwz   r5,  0x2C(r1)            # Restore GPR5
    se_lwz   r6,  0x30(r1)            # Restore GPR6
    se_lwz   r7,  0x34(r1)            # Restore GPR7
    e_lwz    r8,  0x38(r1)            # Restore GPR8
    e_lwz    r9,  0x3C(r1)            # Restore GPR9
    e_lwz    r10, 0x40(r1)            # Restore GPR10
    e_lwz    r11, 0x44(r1)            # Restore GPR11
    e_lwz    r12, 0x48(r1)            # Restore GPR12
    se_blrl
;# End Store/Restore common GPRs
;# IVOR0 Exception Handler
;#     Critical Input Interrupt
IVOR0_Handler:
prolog_IVOR0:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR0_Exception_Handler  # Invoke exception handler

epilog_IVOR0:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR0 Exception Handler

;# IVOR1 Exception Handler
;#     Machine Check Interrupt
IVOR1_Handler:
prolog_IVOR1:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    se_mfctr r0
    se_stw   r0,  0x18(r1)            # Store CTR
    mfxer    r0
    se_stw   r0,  0x1C(r1)            # Store XER
    mfcr     r0
    se_stw   r0,  0x20(r1)            # Store CR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR1_Exception_Handler  # Invoke exception handler

    mfspr r5, 570                     # MCSRR0->r5
    se_lhz r4,0(r5)                   # determine opcode @ MCSRR0
    e_andi. r3,r4,0x9000              # check bit 31,28 only
    e_cmpli 0x0, r3, 0x1000
    e_bne adjust_for_16bit_opcode
    se_addi r5, 2                     # 0xx1 => 32 bit
    adjust_for_16bit_opcode:
    se_addi r5, 2                     # all others just 16 bit long
    mtspr 570, r5                     # save adjusted return address

epilog_IVOR1:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x20(r1)
    mtcr     r0                       # Restore CR
    se_lwz   r0,  0x1c(r1)
    mtxer    r0                       # Restore XER
    se_lwz   r0,  0x18(r1)
    se_mtctr r0                       # Restore CTR
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfmci
;# End IVOR1 Exception Handler

;# IVOR2 Exception Handler
;#     Data Storage Interrupt
IVOR2_Handler:
prolog_IVOR2:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    mfesr    r0
    se_stw   r0,  0x18(r1)            # Store ESR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR2_Exception_Handler  # Invoke exception handler

epilog_IVOR2:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x18(r1)
    mtesr r0                          # Restore ESR
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR2 Exception Handler

;# IVOR3 Exception Handler
;#     Instruction Storage Interrupt
IVOR3_Handler:
prolog_IVOR3:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    mfesr    r0
    se_stw   r0,  0x18(r1)            # Store ESR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR3_Exception_Handler  # Invoke exception handler

epilog_IVOR3:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x18(r1)
    mtesr r0                          # Restore ESR
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR3 Exception Handler

;# IVOR4 Exception Handler
;#     External Input Interrupt
IVOR4_Handler:
prologue:
    e_stwu      r1,-0x50 (r1)           ;# Create stack frame and store back chain
    e_stmvsrrw      0x0c (r1)           ;# Save SRR[0-1] (must be done before enabling MSR[EE])
    se_stw      r3, 0x08 (r1)           ;# Save working register (r3)
    e_stmvsprw      0x14 (r1)           ;# Save CR, LR, CTR, XER
    mfspr       r3, 286                 ;# Save coreid to r9
    e_cmp16i    r3, 0
    e_beq       set_int_cpu_0
    e_cmp16i    r3, 1
    e_beq       set_int_cpu_1
    e_cmp16i    r3, 2
    e_beq       set_int_cpu_2
    e_cmp16i    r3, 3
    e_beq       set_int_cpu_3
    e_cmp16i    r3, 4
    e_beq       set_int_cpu_4
    e_cmp16i    r3, 5
    e_beq       set_int_cpu_5
    e_b         dummy
set_int_cpu_0:
    e_lis       r3, INTC_IACKR_0@ha       ;# Save address  of INTC_IACKR in r3
    e_lwz       r3, INTC_IACKR_0@l(r3)    ;# Save contents of INTC_IACKR in r3 (this is vector table address)
    e_b         set_int_end
set_int_cpu_1:
    e_lis       r3, INTC_IACKR_1@ha       ;# Save address  of INTC_IACKR in r3
    e_lwz       r3, INTC_IACKR_1@l(r3)    ;# Save contents of INTC_IACKR in r3 (this is vector table address)
    e_b         set_int_end
set_int_cpu_2:
    e_lis       r3, INTC_IACKR_2@ha       ;# Save address  of INTC_IACKR in r3
    e_lwz       r3, INTC_IACKR_2@l(r3)    ;# Save contents of INTC_IACKR in r3 (this is vector table address)
    e_b         set_int_end
set_int_cpu_3:
    e_lis       r3, INTC_IACKR_3@ha       ;# Save address  of INTC_IACKR in r3
    e_lwz       r3, INTC_IACKR_3@l(r3)    ;# Save contents of INTC_IACKR in r3 (this is vector table address)
    e_b         set_int_end
set_int_cpu_4:
    e_lis       r3, INTC_IACKR_4@ha       ;# Save address  of INTC_IACKR in r3
    e_lwz       r3, INTC_IACKR_4@l(r3)    ;# Save contents of INTC_IACKR in r3 (this is vector table address)
    e_b         set_int_end
set_int_cpu_5:
    e_lis       r3, INTC_IACKR_5@ha       ;# Save address  of INTC_IACKR in r3
    e_lwz       r3, INTC_IACKR_5@l(r3)    ;# Save contents of INTC_IACKR in r3 (this is vector table address)
    e_b         set_int_end
set_int_end:
    wrteei      1                       ;# Set MSR[EE] (must wait a couple clocks after reading IACKR)
    se_lwz      r3, 0x0(r3)             ;# Read ISR address from Interrupt Vector Table using pointer

    se_mtLR     r3                      ;# Copy ISR address (from IACKR) to LR for next branch
    e_stmvgprw      0x24 (r1)           ;# Save GPRs, r[0,3-12]
    se_blrl                             ;# Branch to ISR, with return to next instruction (epilogue)

epilogue:

    e_lmvgprw       0x24  (r1)           ;# Restore GPRs, r[0,3-12]
    mfspr       r3, 286                 ;# Save coreid to r9
    e_cmp16i    r3, 0
    e_beq       set_intc_eoir_cpu_0
    e_cmp16i    r3, 1
    e_beq       set_intc_eoir_cpu_1
    e_cmp16i    r3, 2
    e_beq       set_intc_eoir_cpu_2
    e_cmp16i    r3, 3
    e_beq       set_intc_eoir_cpu_3
    e_cmp16i    r3, 4
    e_beq       set_intc_eoir_cpu_4
    e_cmp16i    r3, 5
    e_beq       set_intc_eoir_cpu_5
    e_b         dummy
set_intc_eoir_cpu_0:
    e_lis       r3, INTC_EOIR_0@ha        ;# Load upper half of INTC_EOIR address to r3
    mbar                                ;# Ensure prior clearing of interrupt flag conmpleted.
    wrteei      0                       ;# Disable interrupts
    e_stw       r3, INTC_EOIR_0@l(r3)     ;# Load lower half of INTC_EOIR address to r3 and
                                        ;# write contents of r3 to INTC_EOIR
    e_b         set_intc_eoir_end
set_intc_eoir_cpu_1:
    e_lis       r3, INTC_EOIR_1@ha        ;# Load upper half of INTC_EOIR address to r3
    mbar                                ;# Ensure prior clearing of interrupt flag conmpleted.
    wrteei      0                       ;# Disable interrupts
    e_stw       r3, INTC_EOIR_1@l(r3)     ;# Load lower half of INTC_EOIR address to r3 and
                                        ;# write contents of r3 to INTC_EOIR
    e_b         set_intc_eoir_end
set_intc_eoir_cpu_2:
    e_lis       r3, INTC_EOIR_2@ha        ;# Load upper half of INTC_EOIR address to r3
    mbar                                ;# Ensure prior clearing of interrupt flag conmpleted.
    wrteei      0                       ;# Disable interrupts
    e_stw       r3, INTC_EOIR_2@l(r3)     ;# Load lower half of INTC_EOIR address to r3 and
                                        ;# write contents of r3 to INTC_EOIR
    e_b         set_intc_eoir_end
set_intc_eoir_cpu_3:
    e_lis       r3, INTC_EOIR_3@ha        ;# Load upper half of INTC_EOIR address to r3
    mbar                                ;# Ensure prior clearing of interrupt flag conmpleted.
    wrteei      0                       ;# Disable interrupts
    e_stw       r3, INTC_EOIR_3@l(r3)     ;# Load lower half of INTC_EOIR address to r3 and
                                        ;# write contents of r3 to INTC_EOIR
    e_b         set_intc_eoir_end
set_intc_eoir_cpu_4:
    e_lis       r3, INTC_EOIR_4@ha        ;# Load upper half of INTC_EOIR address to r3
    mbar                                ;# Ensure prior clearing of interrupt flag conmpleted.
    wrteei      0                       ;# Disable interrupts
    e_stw       r3, INTC_EOIR_4@l(r3)     ;# Load lower half of INTC_EOIR address to r3 and
                                        ;# write contents of r3 to INTC_EOIR
    e_b         set_intc_eoir_end
set_intc_eoir_cpu_5:
    e_lis       r3, INTC_EOIR_5@ha        ;# Load upper half of INTC_EOIR address to r3
    mbar                                ;# Ensure prior clearing of interrupt flag conmpleted.
    wrteei      0                       ;# Disable interrupts
    e_stw       r3, INTC_EOIR_5@l(r3)     ;# Load lower half of INTC_EOIR address to r3 and
                                        ;# write contents of r3 to INTC_EOIR
    e_b         set_intc_eoir_end
set_intc_eoir_end:
    se_lwz      r3, 0x08 (r1)           ;# Restore working register (r3) (original value)
    e_lmvsrrw       0x0c (r1)           ;# Restore SRR[0-1]
    e_lmvsprw       0x14 (r1)           ;# Restore CR, LR, CTR, XER
    e_add16i    r1, r1, 0x50            ;# Reclaim stack space
    se_rfi                              ;# End of Interrupt Handler - re-enables interrupts
;# IVOR4 Exception Handler

;# IVOR5 Exception Handler
;#     Alignment Interrupt
IVOR5_Handler:
prolog_IVOR5:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    mfesr    r0
    se_stw   r0,  0x18(r1)            # Store ESR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR5_Exception_Handler  # Invoke exception handler

epilog_IVOR5:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x18(r1)
    mtesr r0                          # Restore ESR
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR5 Exception Handler

;# IVOR6 Exception Handler
;#     Program Interrupt
IVOR6_Handler:
prolog_IVOR6:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    mfesr    r0
    se_stw   r0,  0x18(r1)            # Store ESR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR6_Exception_Handler  # Invoke exception handler

epilog_IVOR6:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x18(r1)
    mtesr r0                          # Restore ESR
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR6 Exception Handler

;# IVOR7 Exception Handler
;#     Floating-Point Unavailable Interrupt
IVOR7_Handler:
prolog_IVOR7:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR7_Exception_Handler  # Invoke exception handler

epilog_IVOR7:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR7 Exception Handler

;# IVOR8 Exception Handler
;#     System Call Interrupt
IVOR8_Handler:
prolog_IVOR8:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    mfesr    r0
    se_stw   r0,  0x18(r1)            # Store ESR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR8_Exception_Handler  # Invoke exception handler

epilog_IVOR8:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x18(r1)
    mtesr r0                          # Restore ESR
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR8 Exception Handler

;# IVOR9 Exception Handler
;#     Auxiliary Processor Unavailable Interrupt
;#     An auxiliary processor unavailable exception is defined by the Power ISA to occur when an attempt is
;#     made to execute an APU instruction which is implemented but configured as unavailable, and no higher
;#     priority exception condition exists.
;#     The e200 does not utilize this interrupt.
;# End IVOR9 Exception Handler

;# IVOR10 Exception Handler
;#     Decrementer Interrupt
IVOR10_Handler:
prolog_IVOR10:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR10_Exception_Handler # Invoke exception handler

epilog_IVOR10:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR10 Exception Handler

;# IVOR11 Exception Handler
;#     Fixed-Interval Timer Interrupt
IVOR11_Handler:
prolog_IVOR11:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR11_Exception_Handler # Invoke exception handler

epilog_IVOR11:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR11 Exception Handler

;# IVOR12 Exception Handler
;#     Watchdog Timer Interrupt
IVOR12_Handler:
prolog_IVOR12:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR12_Exception_Handler # Invoke exception handler

epilog_IVOR12:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR12 Exception Handler

;# IVOR13 Exception Handler
;#     Data TLB Error Interrupt
IVOR13_Handler:
prolog_IVOR13:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    mfesr    r0
    se_stw   r0,  0x18(r1)            # Store ESR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR13_Exception_Handler # Invoke exception handler

epilog_IVOR13:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x18(r1)
    mtesr r0                          # Restore ESR
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR13 Exception Handler

;# IVOR14 Exception Handler
;#     Instruction TLB Error Interrupt
IVOR14_Handler:
prolog_IVOR14:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    mfesr    r0
    se_stw   r0,  0x18(r1)            # Store ESR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR14_Exception_Handler # Invoke exception handler

epilog_IVOR14:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x18(r1)
    mtesr r0                          # Restore ESR
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfi
;# End IVOR14 Exception Handler

;# IVOR15 Exception Handler
;#     Debug Interrupt
IVOR15_Handler:
prolog_IVOR15:
    e_stwu   r1, -0x50(r1)            # Create stack frame and store back chain
    se_stw   r0,  0x10(r1)            # Store GPR0 (working register)
    se_mflr  r0
    se_stw   r0,  0x14(r1)            # Store LR
    e_bl     prolog_GPRs              # Store GPR3-GPR12 (stack offset 0x24-0x48)

    mfmsr    r0                       # As function prologs/epilogs may contain
    e_or2is  r0, 0x0200               # SPE instruction, enable SPE, as MSR
    mtmsr    r0                       # register is cleared at this point

    e_bl     IVOR15_Exception_Handler # Invoke exception handler

epilog_IVOR15:
    e_bl     epilog_GPRs              # Restore GPR3-GPR12 (stack offset 0x24-0x48)
    se_lwz   r0,  0x14(r1)
    se_mtlr  r0                       # Restore LR
    se_lwz   r0,  0x10(r1)            # Restore GPR0 (working register)
    e_add16i r1, r1, 0x50             # Clean up stack
    se_rfdi
;# End IVOR15 Exception Handler

SetupE2EECSR0_for_1b_ECC_fault:
    e_lis r4, 0x0000
    e_add16i r4,r4,0x1002
    mtdcr 511, r4
    se_blrl

SetupE2EECSR0_for_2b_ECC_fault:
    e_lis r4, 0x0000
    e_add16i r4,r4,0x1006
    mtdcr 511, r4
    se_blrl
;# SetupE2EECSR0_for_ClearECC(uint32 *buffer, uint32 length);
SetupE2EECSR0_for_ClearECC:
    se_subi     sp, 0x14
    se_stw      r5, 0x00(sp)
    e_stmvsprw  0x04 (sp)            # Save CR, LR, CTR, XER
    mtctr       r4
	raminit_loop:
        e_stmw      r30,0(r3)
        e_addi      r3,r3,8
        e_bdnz      raminit_loop
    e_lmvsprw   0x04 (sp)            # Restore CR, LR, CTR, XER
    se_lwz      r5, 0x00(sp)
    se_addi     sp, 0x14
    se_blr

SetupE2EECSR0_for_ClearWRC:
	e_lis r4, 0x0000
	e_add16i r4,r4,0x0000
	mtdcr 511, r4
	se_blrl
