/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     vector_table.c
* @version  3.0.0
* @date     2023 - 04 - 17
* @brief    Initial version.
*****************************************************************************/
/* PRQA S 2052 EOF */
#include "typedefs.h"
#include "intc_lld.h" /* PRQA S 0380 */

#include "eDma_LLDriver.h"
#include "compiler_api.h"
#ifdef SAFETY_ENABLE
#include "fccu_lld.h"
#endif /* SAFETY_ENABLE */
#ifdef FUNC_SAFETY
#include "saf_mpu.h"
#endif
/*========================================================================*/
/* PROTOTYPES */
/*========================================================================*/
void dummy  (void);
void IVOR0_Exception_Handler(void);
void IVOR1_Exception_Handler(void);
void IVOR2_Exception_Handler(void);
void IVOR3_Exception_Handler(void);
void IVOR4_Exception_Handler(void);/* PRQA S 1753 */
void IVOR5_Exception_Handler(void);
void IVOR6_Exception_Handler(void);
void IVOR7_Exception_Handler(void);
void IVOR8_Exception_Handler(void);
void IVOR9_Exception_Handler(void);/* PRQA S 1753 */
void IVOR10_Exception_Handler(void);
void IVOR11_Exception_Handler(void);
void IVOR12_Exception_Handler(void);
void IVOR13_Exception_Handler(void);
void IVOR14_Exception_Handler(void);
void IVOR15_Exception_Handler(void);

/*========================================================================*/
/* GLOBAL VARIABLES */
/*========================================================================*/
IntrHandle __attribute__ ((section (".intc_vector_table"))) IntcIsrVectorTable[] = { /* PRQA S 1533, 3408 */ /* IntrHandle */
    &dummy, /* Vector #   0 Software setable flag 0 INTC_SSCIR0[CLR0] */
    &dummy, /* Vector #   1 Software setable flag 1 INTC_SSCIR0[CLR1] */
    &dummy, /* Vector #   2 Software setable flag 2 INTC_SSCIR0[CLR2] */
    &dummy, /* Vector #   3 Software setable flag 3 INTC_SSCIR0[CLR3] */
    &dummy, /* Vector #   4 Software setable flag 4 INTC_SSCIR0[CLR4] */
    &dummy, /* Vector #   5 Software setable flag 5 INTC_SSCIR0[CLR5] */
    &dummy, /* Vector #   6 Software setable flag 6 INTC_SSCIR0[CLR6] */
    &dummy, /* Vector #   7 Software setable flag 7 INTC_SSCIR0[CLR7] */
    &dummy, /* Vector #   8 Software setable flag 8 INTC_SSCIR0[CLR8] */
    &dummy, /* Vector #   9 Software setable flag 9 INTC_SSCIR0[CLR9] */
    &dummy, /* Vector #  10 Software setable flag 10 INTC_SSCIR0[CLR10] */
    &dummy, /* Vector #  11 Software setable flag 11 INTC_SSCIR0[CLR11] */
    &dummy, /* Vector #  12 Software setable flag 12 INTC_SSCIR0[CLR12] */
    &dummy, /* Vector #  13 Software setable flag 13 INTC_SSCIR0[CLR13] */
    &dummy, /* Vector #  14 Software setable flag 14 INTC_SSCIR0[CLR14] */
    &dummy, /* Vector #  15 Software setable flag 15 INTC_SSCIR0[CLR15] */
    &dummy, /* Vector #  16 Software setable flag 16 INTC_SSCIR0[CLR16] */
    &dummy, /* Vector #  17 Software setable flag 17 INTC_SSCIR0[CLR17] */
    &dummy, /* Vector #  18 Software setable flag 18 INTC_SSCIR0[CLR18] */
    &dummy, /* Vector #  19 Software setable flag 19 INTC_SSCIR0[CLR19] */
    &dummy, /* Vector #  20 Software setable flag 20 INTC_SSCIR0[CLR20] */
    &dummy, /* Vector #  21 Software setable flag 21 INTC_SSCIR0[CLR21] */
    &dummy, /* Vector #  22 Software setable flag 22 INTC_SSCIR0[CLR22] */
    &dummy, /* Vector #  23 Software setable flag 23 INTC_SSCIR0[CLR23] */
    &dummy, /* Vector #  24 Software setable flag 24 INTC_SSCIR0[CLR24] */
    &dummy, /* Vector #  25 Software setable flag 25 INTC_SSCIR0[CLR25] */
    &dummy, /* Vector #  26 Software setable flag 26 INTC_SSCIR0[CLR26] */
    &dummy, /* Vector #  27 Software setable flag 27 INTC_SSCIR0[CLR27] */
    &dummy, /* Vector #  28 Software setable flag 28 INTC_SSCIR0[CLR28] */
    &dummy, /* Vector #  29 Software setable flag 29 INTC_SSCIR0[CLR29] */
    &dummy, /* Vector #  30 Software setable flag 30 INTC_SSCIR0[CLR30] */
    &dummy, /* Vector #  31 Software setable flag 31 INTC_SSCIR0[CLR31] */
    &dummy, /* Vector #  32 Platform watchdog timer0 SWT_0_IR[TIF] */
    &dummy, /* Vector #  33 Platform watchdog timer1 SWT_1_IR[TIF] */
    &dummy, /* Vector #  34 Platform watchdog timer2 SWT_2_IR[TIF] */
    &dummy, /* Vector #  35 Platform watchdog timer3 SWT_3_IR[TIF] */
    &dummy, /* Vector #  36 Platform periodic timer 0_0 (STM) STM_0_CIR0[CIF] */
    &dummy, /* Vector #  37 Platform periodic timer 0_1 (STM) STM_0_CIR1[CIF] */
    &dummy, /* Vector #  38 Platform periodic timer 0_2 (STM) STM_0_CIR2[CIF] */
    &dummy, /* Vector #  39 Platform periodic timer 0_3 (STM) STM_0_CIR3[CIF] */
    &dummy, /* Vector #  40 Platform periodic timer 1_0 (STM) STM_1_CIR0[CIF] */
    &dummy, /* Vector #  41 Platform periodic timer 1_1 (STM) STM_1_CIR1[CIF] */
    &dummy, /* Vector #  42 Platform periodic timer 1_2 (STM) STM_1_CIR2[CIF] */
    &dummy, /* Vector #  43 Platform periodic timer 1_3 (STM) STM_1_CIR3[CIF] */
    &dummy, /* Vector #  44 Platform periodic timer 2_0 (STM) STM_2_CIR0[CIF] */
    &dummy, /* Vector #  45 Platform periodic timer 2_1 (STM) STM_2_CIR1[CIF] */
    &dummy, /* Vector #  46 Platform periodic timer 2_2 (STM) STM_2_CIR2[CIF] */
    &dummy, /* Vector #  47 Platform periodic timer 2_3 (STM) STM_2_CIR3[CIF] */
    &dummy, /* Vector #  48 */
    &dummy, /* Vector #  49 */
    &dummy, /* Vector #  50 */
    &dummy, /* Vector #  51 */
    &dummy, /* Vector #  52 eDMA Combined Error 127 - 0 eDMA Channel Error Flags */
    &dummy, /* Vector #  53 eDMA Channel 0 DMA_INTL[INT0] */
    &dummy, /* Vector #  54 eDMA Channel 1 DMA_INTL[INT1] */
    &dummy, /* Vector #  55 eDMA Channel 2 DMA_INTL[INT2] */
    &dummy, /* Vector #  56 eDMA Channel 3 DMA_INTL[INT3] */
    &dummy, /* Vector #  57 eDMA Channel 4 DMA_INTL[INT4] */
    &dummy, /* Vector #  58 eDMA Channel 5 DMA_INTL[INT5] */
    &dummy, /* Vector #  59 eDMA Channel 6 DMA_INTL[INT6] */
    &dummy, /* Vector #  60 eDMA Channel 7 DMA_INTL[INT7] */
    &dummy, /* Vector #  61 eDMA Channel 8 DMA_INTL[INT8] */
    &dummy, /* Vector #  62 eDMA Channel 9 DMA_INTL[INT9] */
    &dummy, /* Vector #  63 eDMA Channel 10 DMA_INTL[INT10] */
    &dummy, /* Vector #  64 eDMA Channel 11 DMA_INTL[INT11] */
    &dummy, /* Vector #  65 eDMA Channel 12 DMA_INTL[INT12] */
    &dummy, /* Vector #  66 eDMA Channel 13 DMA_INTL[INT13] */
    &dummy, /* Vector #  67 eDMA Channel 14 DMA_INTL[INT14] */
    &dummy, /* Vector #  68 eDMA Channel 15 DMA_INTL[INT15] */
    &dummy, /* Vector #  69 eDMA Channel 16 DMA_INTL[INT16] */
    &dummy, /* Vector #  70 eDMA Channel 17 DMA_INTL[INT17] */
    &dummy, /* Vector #  71 eDMA Channel 18 DMA_INTL[INT18] */
    &dummy, /* Vector #  72 eDMA Channel 19 DMA_INTL[INT19] */
    &dummy, /* Vector #  73 eDMA Channel 20 DMA_INTL[INT20] */
    &dummy, /* Vector #  74 eDMA Channel 21 DMA_INTL[INT21] */
    &dummy, /* Vector #  75 eDMA Channel 22 DMA_INTL[INT22] */
    &dummy, /* Vector #  76 eDMA Channel 23 DMA_INTL[INT23] */
    &dummy, /* Vector #  77 eDMA Channel 24 DMA_INTL[INT24] */
    &dummy, /* Vector #  78 eDMA Channel 25 DMA_INTL[INT25] */
    &dummy, /* Vector #  79 eDMA Channel 26 DMA_INTL[INT26] */
    &dummy, /* Vector #  80 eDMA Channel 27 DMA_INTL[INT27] */
    &dummy, /* Vector #  81 eDMA Channel 28 DMA_INTL[INT28] */
    &dummy, /* Vector #  82 eDMA Channel 29 DMA_INTL[INT29] */
    &dummy, /* Vector #  83 eDMA Channel 30 DMA_INTL[INT30] */
    &dummy, /* Vector #  84 eDMA Channel 31 DMA_INTL[INT31] */
    &dummy, /* Vector #  85 eDMA Channel 32 DMA_INTH[INT32] */
    &dummy, /* Vector #  86 eDMA Channel 33 DMA_INTH[INT33] */
    &dummy, /* Vector #  87 eDMA Channel 34 DMA_INTH[INT34] */
    &dummy, /* Vector #  88 eDMA Channel 35 DMA_INTH[INT35] */
    &dummy, /* Vector #  89 eDMA Channel 36 DMA_INTH[INT36] */
    &dummy, /* Vector #  90 eDMA Channel 37 DMA_INTH[INT37] */
    &dummy, /* Vector #  91 eDMA Channel 38 DMA_INTH[INT38] */
    &dummy, /* Vector #  92 eDMA Channel 39 DMA_INTH[INT39] */
    &dummy, /* Vector #  93 eDMA Channel 40 DMA_INTH[INT40] */
    &dummy, /* Vector #  94 eDMA Channel 41 DMA_INTH[INT41] */
    &dummy, /* Vector #  95 eDMA Channel 42 DMA_INTH[INT42] */
    &dummy, /* Vector #  96 eDMA Channel 43 DMA_INTH[INT43] */
    &dummy, /* Vector #  97 eDMA Channel 44 DMA_INTH[INT44] */
    &dummy, /* Vector #  98 eDMA Channel 45 DMA_INTH[INT45] */
    &dummy, /* Vector #  99 eDMA Channel 46 DMA_INTH[INT46] */
    &dummy, /* Vector # 100 eDMA Channel 47 DMA_INTH[INT47] */
    
    &dummy, /* Vector # 101 eDMA Channel 48 DMA_INTH[INT48] */
    &dummy, /* Vector # 102 eDMA Channel 49 DMA_INTH[INT49] */
    &dummy, /* Vector # 103 eDMA Channel 50 DMA_INTH[INT50] */
    &dummy, /* Vector # 104 eDMA Channel 51 DMA_INTH[INT51] */
    &dummy, /* Vector # 105 eDMA Channel 52 DMA_INTH[INT52] */
    &dummy, /* Vector # 106 eDMA Channel 53 DMA_INTH[INT53] */
    &dummy, /* Vector # 107 eDMA Channel 54 DMA_INTH[INT54] */
    &dummy, /* Vector # 108 eDMA Channel 55 DMA_INTH[INT55] */
    &dummy, /* Vector # 109 eDMA Channel 56 DMA_INTH[INT56] */
    &dummy, /* Vector # 110 eDMA Channel 57 DMA_INTH[INT57] */
    &dummy, /* Vector # 111 eDMA Channel 58 DMA_INTH[INT58] */
    &dummy, /* Vector # 112 eDMA Channel 59 DMA_INTH[INT59] */
    &dummy, /* Vector # 113 eDMA Channel 60 DMA_INTH[INT60] */
    &dummy, /* Vector # 114 eDMA Channel 61 DMA_INTH[INT61] */
    &dummy, /* Vector # 115 eDMA Channel 62 DMA_INTH[INT62] */
    &dummy, /* Vector # 116 eDMA Channel 63 DMA_INTH[INT63] */
    &dummy, /* Vector # 117 eDMA Channel 64 DMA_INTH[INT64] */
    &dummy, /* Vector # 118 eDMA Channel 65 DMA_INTH[INT65] */
    &dummy, /* Vector # 119 eDMA Channel 66 DMA_INTH[INT66] */
    &dummy, /* Vector # 120 eDMA Channel 67 DMA_INTH[INT67] */
    &dummy, /* Vector # 121 eDMA Channel 68 DMA_INTH[INT68] */
    &dummy, /* Vector # 122 eDMA Channel 69 DMA_INTH[INT69] */
    &dummy, /* Vector # 123 eDMA Channel 70 DMA_INTH[INT70] */
    &dummy, /* Vector # 124 eDMA Channel 71 DMA_INTH[INT71] */
    &dummy, /* Vector # 125 eDMA Channel 72 DMA_INTH[INT72] */
    &dummy, /* Vector # 126 eDMA Channel 73 DMA_INTH[INT73] */
    &dummy, /* Vector # 127 eDMA Channel 74 DMA_INTH[INT74] */
    &dummy, /* Vector # 128 eDMA Channel 75 DMA_INTH[INT75] */
    &dummy, /* Vector # 129 eDMA Channel 76 DMA_INTH[INT76] */
    &dummy, /* Vector # 130 eDMA Channel 77 DMA_INTH[INT77] */
    &dummy, /* Vector # 131 eDMA Channel 78 DMA_INTH[INT78] */
    &dummy, /* Vector # 132 eDMA Channel 79 DMA_INTH[INT79] */
    &dummy, /* Vector # 133 eDMA Channel 80 DMA_INTH[INT80] */
    &dummy, /* Vector # 134 eDMA Channel 81 DMA_INTH[INT81] */
    &dummy, /* Vector # 135 eDMA Channel 82 DMA_INTH[INT82] */
    &dummy, /* Vector # 136 eDMA Channel 83 DMA_INTH[INT83] */
    &dummy, /* Vector # 137 eDMA Channel 84 DMA_INTH[INT84] */
    &dummy, /* Vector # 138 eDMA Channel 85 DMA_INTH[INT85] */
    &dummy, /* Vector # 139 eDMA Channel 86 DMA_INTH[INT86] */
    &dummy, /* Vector # 140 eDMA Channel 87 DMA_INTH[INT87] */
    &dummy, /* Vector # 141 eDMA Channel 88 DMA_INTH[INT88] */
    &dummy, /* Vector # 142 eDMA Channel 89 DMA_INTH[INT89] */
    &dummy, /* Vector # 143 eDMA Channel 90 DMA_INTH[INT90] */
    &dummy, /* Vector # 144 eDMA Channel 91 DMA_INTH[INT91] */
    &dummy, /* Vector # 145 eDMA Channel 92 DMA_INTH[INT92] */
    &dummy, /* Vector # 146 eDMA Channel 93 DMA_INTH[INT93] */
    &dummy, /* Vector # 147 eDMA Channel 94 DMA_INTH[INT94] */
    &dummy, /* Vector # 148 eDMA Channel 95 DMA_INTH[INT95] */
    &dummy, /* Vector # 149 eDMA Channel 96 DMA_INTH[INT96] */
    &dummy, /* Vector # 150 eDMA Channel 97 DMA_INTH[INT97] */
    &dummy, /* Vector # 151 eDMA Channel 98 DMA_INTH[INT98] */
    &dummy, /* Vector # 152 eDMA Channel 99 DMA_INTH[INT99] */
    &dummy, /* Vector # 153 eDMA Channel 100 DMA_INTH[INT100] */
    &dummy, /* Vector # 154 eDMA Channel 101 DMA_INTH[INT101] */
    &dummy, /* Vector # 155 eDMA Channel 102 DMA_INTH[INT102] */
    &dummy, /* Vector # 156 eDMA Channel 103 DMA_INTH[INT103] */
    &dummy, /* Vector # 157 eDMA Channel 104 DMA_INTH[INT104] */
    &dummy, /* Vector # 158 eDMA Channel 105 DMA_INTH[INT105] */
    &dummy, /* Vector # 159 eDMA Channel 106 DMA_INTH[INT106] */
    &dummy, /* Vector # 160 eDMA Channel 107 DMA_INTH[INT107] */
    &dummy, /* Vector # 161 eDMA Channel 108 DMA_INTH[INT108] */
    &dummy, /* Vector # 162 eDMA Channel 109 DMA_INTH[INT109] */
    &dummy, /* Vector # 163 eDMA Channel 110 DMA_INTH[INT110] */
    &dummy, /* Vector # 164 eDMA Channel 111 DMA_INTH[INT111] */
    &dummy, /* Vector # 165 eDMA Channel 112 DMA_INTH[INT112] */
    &dummy, /* Vector # 166 eDMA Channel 113 DMA_INTH[INT113] */
    &dummy, /* Vector # 167 eDMA Channel 114 DMA_INTH[INT114] */
    &dummy, /* Vector # 168 eDMA Channel 115 DMA_INTH[INT115] */
    &dummy, /* Vector # 169 eDMA Channel 116 DMA_INTH[INT116] */
    &dummy, /* Vector # 170 eDMA Channel 117 DMA_INTH[INT117] */
    &dummy, /* Vector # 171 eDMA Channel 118 DMA_INTH[INT118] */
    &dummy, /* Vector # 172 eDMA Channel 119 DMA_INTH[INT119] */
    &dummy, /* Vector # 173 eDMA Channel 120 DMA_INTH[INT120] */
    &dummy, /* Vector # 174 eDMA Channel 121 DMA_INTH[INT121] */
    &dummy, /* Vector # 175 eDMA Channel 122 DMA_INTH[INT122] */
    &dummy, /* Vector # 176 eDMA Channel 123 DMA_INTH[INT123] */
    &dummy, /* Vector # 177 eDMA Channel 124 DMA_INTH[INT124] */
    &dummy, /* Vector # 178 eDMA Channel 125 DMA_INTH[INT125] */
    &dummy, /* Vector # 179 eDMA Channel 126 DMA_INTH[INT126] */
    &dummy, /* Vector # 180 eDMA Channel 127 DMA_INTH[INT127] */
    &dummy, /* Vector # 181 */
    &dummy, /* Vector # 182 */
    &dummy, /* Vector # 183 */
    &dummy, /* Vector # 184 */
    &dummy, /* Vector # 185 Flash controller Prog/Erase/Suspend IRQ_0 MCR[DONE] */
    &dummy, /* Vector # 186 */
    &dummy, /* Vector # 187 */
    &dummy, /* Vector # 188 */
    &dummy, /* Vector # 189 */
    &dummy, /* Vector # 190 */
    &dummy, /* Vector # 191 */
    &dummy, /* Vector # 192 */
    &dummy, /* Vector # 193 */
    &dummy, /* Vector # 194 */
    &dummy, /* Vector # 195 */
    &dummy, /* Vector # 196 */
    &dummy, /* Vector # 197 */
    &dummy, /* Vector # 198 */
    &dummy, /* Vector # 199 */
    &dummy, /* Vector # 200 */
    
    &dummy, /* Vector # 201 */
    &dummy, /* Vector # 202 */
    &dummy, /* Vector # 203 */
    &dummy, /* Vector # 204 */
    &dummy, /* Vector # 205 */
    &dummy, /* Vector # 206 */
    &dummy, /* Vector # 207 */
    &dummy, /* Vector # 208 */
    &dummy, /* Vector # 209 */
    &dummy, /* Vector # 210 */
    &dummy, /* Vector # 211 */
    &dummy, /* Vector # 212 */
    &dummy, /* Vector # 213 */
    &dummy, /* Vector # 214 */
    &dummy, /* Vector # 215 */
    &dummy, /* Vector # 216 */
    &dummy, /* Vector # 217 */
    &dummy, /* Vector # 218 Ethernet_0_0 EIR[TXF] */
    &dummy, /* Vector # 219 Ethernet_0_1 EIR[RXF] */
    &dummy, /* Vector # 220 Ethernet_0_2 EIR[HBERR] EIR[BABR] EIR[BABT] EIR[GRA] */
            /*                           EIR[TXB] EIR[RXB] EIR[MII] EIR[EBERR] */
            /*                           EIR[LC] EIR[RL] EIR[UN] */
    &dummy, /* Vector # 221 */
    &dummy, /* Vector # 222 */
    &dummy, /* Vector # 223 */
    &dummy, /* Vector # 224 */
    &dummy, /* Vector # 225 */
    &dummy, /* Vector # 226 Periodic Interrupt Timer (PIT0) PIT_0_TFLG0[TIF] */
    &dummy, /* Vector # 227 Periodic Interrupt Timer (PIT1) PIT_0_TFLG1[TIF] */
    &dummy, /* Vector # 228 Periodic Interrupt Timer (PIT2) PIT_0_TFLG2[TIF] */
    &dummy, /* Vector # 229 Periodic Interrupt Timer (PIT3) PIT_0_TFLG3[TIF] */
    &dummy, /* Vector # 230 Periodic Interrupt Timer (PIT4) PIT_0_TFLG4[TIF] */
    &dummy, /* Vector # 231 Periodic Interrupt Timer (PIT5) PIT_0_TFLG5[TIF] */
    &dummy, /* Vector # 232 Periodic Interrupt Timer (PIT6) PIT_0_TFLG6[TIF] */
    &dummy, /* Vector # 233 Periodic Interrupt Timer (PIT7) PIT_0_TFLG7[TIF] */
    &dummy, /* Vector # 234 */
    &dummy, /* Vector # 235 */
    &dummy, /* Vector # 236 */
    &dummy, /* Vector # 237 */
    &dummy, /* Vector # 238 */
    &dummy, /* Vector # 239 PIT_RTI PIT_0_RTI_TFLG[TIF] */
    &dummy, /* Vector # 240 PIT_64_Upper PIT_1_TFLG0[TIF] */
    &dummy, /* Vector # 241 PIT_64_Lower PIT_1_TFLG1[TIF] */
    &dummy, /* Vector # 242 XOSC counter XOSC */
    &dummy, /* Vector # 243 SIU External Interrupt_0 SIU External Interrupt_0 */
    &dummy, /* Vector # 244 SIU External Interrupt_1 SIU External Interrupt_1 */
    &dummy, /* Vector # 245 */
    &dummy, /* Vector # 246 */
    &dummy, /* Vector # 247 */
    &dummy, /* Vector # 248 */
    &dummy, /* Vector # 249 */
    &dummy, /* Vector # 250 */
    &dummy, /* Vector # 251 MC_ME 0 ME_IS[I_SAFE] */
    &dummy, /* Vector # 252 MC_ME 1 ME_IS[I_MTC] */
    &dummy, /* Vector # 253 MC_ME 2 ME_IS[I_IMODE] */
    &dummy, /* Vector # 254 MC_ME 3 ME_IS[I_ICONF] */
    &dummy, /* Vector # 255 MC_RGM 0 MC_RGM Functional and destructive reset alternate event interrupt */
    &dummy, /* Vector # 256 */
    &dummy, /* Vector # 257 */
    &dummy, /* Vector # 258 */
    &dummy, /* Vector # 259 DSPI0_0 DSPI_0_SR[TFUF] | DSPI_0_SR[RFOF] | DSPI_0_SR[TFIWF] */
    &dummy, /* Vector # 260 DSPI0_1 DSPI_0_SR[EOQF] */
    &dummy, /* Vector # 261 DSPI0_2 DSPI_0_SR[TFFF] */
    &dummy, /* Vector # 262 DSPI0_3 DSPI_0_SR[TCF] */
    &dummy, /* Vector # 263 DSPI0_4 DDSPI_0_SR[RFDF] */
    &dummy, /* Vector # 264 */
    &dummy, /* Vector # 265 */
    &dummy, /* Vector # 266 DSPI0_7 DSPI_0_SR[SPEF] */
    &dummy, /* Vector # 267 */
    &dummy, /* Vector # 268 DSPI1_0 DSPI_1_SR[TFUF] | DSPI_1_SR[RFOF] | */
            /*              DSPI_1_SR[TFIWF] */
    &dummy, /* Vector # 269 DSPI1_1 DSPI_1_SR[EOQF] */
    &dummy, /* Vector # 270 DSPI1_2 DSPI_1_SR[TFFF] */
    &dummy, /* Vector # 271 DSPI1_3 DSPI_1_SR[TCF] */
    &dummy, /* Vector # 272 DSPI1_4 DSPI_1_SR[RFDF] */
    &dummy, /* Vector # 273 */
    &dummy, /* Vector # 274 */
    &dummy, /* Vector # 275 DSPI1_7 DSPI_1_SR[SPEF] */
    &dummy, /* Vector # 276 */
    &dummy, /* Vector # 277 DSPI2_0 DSPI_2_SR[TFUF] | DSPI_2_SR[RFOF]| */
            /*              DSPI_2_SR[TFIWF] */
    &dummy, /* Vector # 278 DSPI2_1 DSPI_2_SR[EOQF] */
    &dummy, /* Vector # 279 DSPI2_2 DSPI_2_SR[TFFF] */
    &dummy, /* Vector # 280 DSPI2_3 DSPI_2_SR[TCF] */
    &dummy, /* Vector # 281 DSPI2_4 DSPI_2_SR[RFDF] */
    &dummy, /* Vector # 282 */
    &dummy, /* Vector # 283 */
    &dummy, /* Vector # 284 DSPI2_7 DSPI_2_SR[SPEF] */
    &dummy, /* Vector # 285 */
    &dummy, /* Vector # 286 DSPI3_0 DSPI_3_SR[TFUF] | DSPI_3_SR[RFOF]| */
            /*              DSPI_3_SR[TFIWF] */
    &dummy, /* Vector # 287 DSPI3_1 DSPI_3_SR[EOQF] */
    &dummy, /* Vector # 288 DSPI3_2 DSPI_3_SR[TFFF] */
    &dummy, /* Vector # 289 DSPI3_3 DSPI_3_SR[TCF] */
    &dummy, /* Vector # 290 DSPI3_4 DSPI_3_SR[RFDF] */
    &dummy, /* Vector # 291 */
    &dummy, /* Vector # 292 */
    &dummy, /* Vector # 293 DSPI3_7 DSPI_3_SR[SPEF] */
    &dummy, /* Vector # 294 */
    &dummy, /* Vector # 295 DSPI4_0 DSPI_4_SR[TFUF] | DSPI_4_SR[RFOF]| */
            /*              DSPI_4_SR[TFIWF] */
    &dummy, /* Vector # 296 DSPI4_1 DSPI_4_SR[EOQF] */
    &dummy, /* Vector # 297 DSPI4_2 DSPI_4_SR[TFFF] */
    &dummy, /* Vector # 298 DSPI4_3 DSPI_4_SR[TCF] */
    &dummy, /* Vector # 299 DSPI4_4 DSPI_4_SR[RFDF] */
    &dummy, /* Vector # 300 DSPI4_5 DSPI_4_SR[SPITCF] | */
            /*              DSPI_4_SR[CMD_TCF] */
    
    &dummy, /* Vector # 301 DSPI4_6 DSPI_4_SR[DSITCF] | */
            /*              DSPI_4_SR[CMDFFF] */
    &dummy, /* Vector # 302 DSPI4_7 DSPI_4_SR[SPEF] | DSPI_4_SR[DPEF] */
    &dummy, /* Vector # 303 DSPI4_8 DSPI_4_SR[DDIF] */
    &dummy, /* Vector # 304 DSPI5_0 DSPI_5_SR[TFUF] | DSPI_5_SR[RFOF]| */
            /*              DSPI_5_SR[TFIWF] */
    &dummy, /* Vector # 305 DSPI5_1 DSPI_5_SR[EOQF] */
    &dummy, /* Vector # 306 DSPI5_2 DSPI_5_SR[TFFF] */
    &dummy, /* Vector # 307 DSPI5_3 DSPI_5_SR[TCF] */
    &dummy, /* Vector # 308 DSPI5_4 DSPI_5_SR[RFDF] */
    &dummy, /* Vector # 309 DSPI5_5 DSPI_5_SR[SPITCF] | DSPI_5_SR[CMD_TCF] */
    &dummy, /* Vector # 310 DSPI5_6 DSPI_5_SR[DSITCF] | DSPI_5_SR[CMDFFF] */
    &dummy, /* Vector # 311 DSPI5_7 DSPI_5_SR[SPEF] | DSPI_5_SR[DPEF] */
    &dummy, /* Vector # 312 DSPI5_8 DSPI_5_SR[DDIF] */
    &dummy, /* Vector # 313 DSPI6_0 DSPI_6_SR[TFUF] | DSPI_6_SR[RFOF]| */
            /*              DSPI_6_SR[TFIWF] */
    &dummy, /* Vector # 314 DSPI6_1 DSPI_6_SR[EOQF] */
    &dummy, /* Vector # 315 DSPI6_2 DSPI_6_SR[TFFF] */
    &dummy, /* Vector # 316 DSPI6_3 DSPI_6_SR[TCF] */
    &dummy, /* Vector # 317 DSPI6_4 DSPI_6_SR[RFDF] */
    &dummy, /* Vector # 318 DSPI6_5 DSPI_6_SR[SPITCF] | DSPI_6_SR[CMD_TCF] */
    &dummy, /* Vector # 319 DSPI6_6 DSPI_6_SR[DSITCF] | DSPI_6_SR[CMDFFF] */
    &dummy, /* Vector # 320 DSPI6_7 DSPI_6_SR[SPEF] | DSPI_6_SR[DPEF] */
    &dummy, /* Vector # 321 DSPI6_8 DSPI_6_SR[DDIF] */
    &dummy, /* Vector # 322 */
    &dummy, /* Vector # 323 */
    &dummy, /* Vector # 324 */
    &dummy, /* Vector # 325 */
    &dummy, /* Vector # 326 */
    &dummy, /* Vector # 327 */
    &dummy, /* Vector # 328 */
    &dummy, /* Vector # 329 */
    &dummy, /* Vector # 330 */
    &dummy, /* Vector # 331 */
    &dummy, /* Vector # 332 */
    &dummy, /* Vector # 333 */
    &dummy, /* Vector # 334 */
    &dummy, /* Vector # 335 */
    &dummy, /* Vector # 336 */
    &dummy, /* Vector # 337 */
    &dummy, /* Vector # 338 */
    &dummy, /* Vector # 339 */
    &dummy, /* Vector # 340 */
    &dummy, /* Vector # 341 */
    &dummy, /* Vector # 342 */
    &dummy, /* Vector # 343 */
    &dummy, /* Vector # 344 */
    &dummy, /* Vector # 345 */
    &dummy, /* Vector # 346 */
    &dummy, /* Vector # 347 */
    &dummy, /* Vector # 348 */
    &dummy, /* Vector # 349 */
    &dummy, /* Vector # 350 */
    &dummy, /* Vector # 351 */
    &dummy, /* Vector # 352 */
    &dummy, /* Vector # 353 */
    &dummy, /* Vector # 354 */
    &dummy, /* Vector # 355 */
    &dummy, /* Vector # 356 */
    &dummy, /* Vector # 357 */
    &dummy, /* Vector # 358 */
    &dummy, /* Vector # 359 */
    &dummy, /* Vector # 360 */
    &dummy, /* Vector # 361 */
    &dummy, /* Vector # 362 */
    &dummy, /* Vector # 363 */
    &dummy, /* Vector # 364 */
    &dummy, /* Vector # 365 */
    &dummy, /* Vector # 366 */
    &dummy, /* Vector # 367 DSPI12_0 DSPI_12_SR[TFUF] | DSPI_12_SR[RFOF]| */
            /*              DSPI_12_SR[TFIWF] */
    &dummy, /* Vector # 368 DSPI12_1 DSPI_12_SR[EOQF] */
    &dummy, /* Vector # 369 DSPI12_2 DSPI_12_SR[TFFF] */
    &dummy, /* Vector # 370 DSPI12_3 DSPI_12_SR[TCF] */
    &dummy, /* Vector # 371 DSPI12_4 DSPI_12_SR[RFDF] */

    &dummy, /* Vector # 372 */
    &dummy, /* Vector # 373 */
    &dummy, /* Vector # 374 DSPI12_7 DSPI_12_SR[SPEF] */
    &dummy, /* Vector # 375 */
    &dummy, /* Vector # 376 Linflex/eSCI0_0 LINFlex_0_RXI */
    &dummy, /* Vector # 377 Linflex/eSCI0_1 LINFlex_0_TXI */
    &dummy, /* Vector # 378 Linflex/eSCI0_2 LINFlex_0_ERR */
    &dummy, /* Vector # 379 */
    &dummy, /* Vector # 380 Linflex/eSCI1_0 LINFlex_1_RXI */
    &dummy, /* Vector # 381 Linflex/eSCI1_1 LINFlex_1_TXI */
    &dummy, /* Vector # 382 Linflex/eSCI1_2 LINFlex_1_ERR */
    &dummy, /* Vector # 383 */
    &dummy, /* Vector # 384 Linflex/eSCI2_0 LINFlex_2_RXI */
    &dummy, /* Vector # 385 Linflex/eSCI2_1 LINFlex_2_TXI */
    &dummy, /* Vector # 386 Linflex/eSCI2_2 LINFlex_2_ERR */
    &dummy, /* Vector # 387 */
    &dummy, /* Vector # 388 */
    &dummy, /* Vector # 389 */
    &dummy, /* Vector # 390 */
    &dummy, /* Vector # 391 */
    &dummy, /* Vector # 392 */
    &dummy, /* Vector # 393 */
    &dummy, /* Vector # 394 */
    &dummy, /* Vector # 395 */
    &dummy, /* Vector # 396 */
    &dummy, /* Vector # 397 */
    &dummy, /* Vector # 398 */
    &dummy, /* Vector # 399 */
    &dummy, /* Vector # 400 */
    
    &dummy, /* Vector # 401 */
    &dummy, /* Vector # 402 */
    &dummy, /* Vector # 403 */
    &dummy, /* Vector # 404 */
    &dummy, /* Vector # 405 */
    &dummy, /* Vector # 406 */
    &dummy, /* Vector # 407 */
    &dummy, /* Vector # 408 */
    &dummy, /* Vector # 409 */
    &dummy, /* Vector # 410 */
    &dummy, /* Vector # 411 */
    &dummy, /* Vector # 412 */
    &dummy, /* Vector # 413 */
    &dummy, /* Vector # 414 */
    &dummy, /* Vector # 415 */
    &dummy, /* Vector # 416 Linflex/eSCI16_0 LINFlex_16_RXI */
    &dummy, /* Vector # 417 Linflex/eSCI16_1 LINFlex_16_TXI */
    &dummy, /* Vector # 418 Linflex/eSCI16_2 LINFlex_16_ERR */
    &dummy, /* Vector # 419 */
    &dummy, /* Vector # 420 */
    &dummy, /* Vector # 421 */
    &dummy, /* Vector # 422 */
    &dummy, /* Vector # 423 */
    &dummy, /* Vector # 424 */
    &dummy, /* Vector # 425 */
    &dummy, /* Vector # 426 */
    &dummy, /* Vector # 427 */
    &dummy, /* Vector # 428 */
    &dummy, /* Vector # 429 */
    &dummy, /* Vector # 430 */
    &dummy, /* Vector # 431 */
    &dummy, /* Vector # 432 Linflex/eSCI14_0 LINFlex_14_RXI */
    &dummy, /* Vector # 433 Linflex/eSCI14_1 LINFlex_14_TXI */
    &dummy, /* Vector # 434 Linflex/eSCI14_2 LINFlex_14_ERR */
    &dummy, /* Vector # 435 */
    &dummy, /* Vector # 436 Linflex/eSCI15_0 LINFlex_15_RXI */
    &dummy, /* Vector # 437 Linflex/eSCI15_1 LINFlex_15_TXI */
    &dummy, /* Vector # 438 Linflex/eSCI15_2 LINFlex_15_ERR */
    &dummy, /* Vector # 439 */
    &dummy, /* Vector # 440 IIC_0_0 I2C0_SR[IBAL] | I2C0_SR[TCF] | */
            /*              I2C0_SR[IAAS] */
    &dummy, /* Vector # 441 */
    &dummy, /* Vector # 442 IIC_1_0 I2C1_SR[IBAL] | I2C1_SR[TCF] | */
            /*              I2C1_SR[IAAS] */
    &dummy, /* Vector # 443 */
    &dummy, /* Vector # 444 */
    &dummy, /* Vector # 445 */
    &dummy, /* Vector # 446 */
    &dummy, /* Vector # 447 */
    &dummy, /* Vector # 448 */
    &dummy, /* Vector # 449 */
    &dummy, /* Vector # 450 */
    &dummy, /* Vector # 451 */
    &dummy, /* Vector # 452 */
    &dummy, /* Vector # 453 FlexRay_0_0 FR_0_LRNEIF | DRNEIF */
    &dummy, /* Vector # 454 FlexRay_0_1 FR_0_LRCEIF | DRCEIF */
    &dummy, /* Vector # 455 FlexRay_0_2 FR_0_FNEAIF */
    &dummy, /* Vector # 456 FlexRay_0_3 FR_0_FNEBIF */
    &dummy, /* Vector # 457 FlexRay_0_4 FR_0_WUPIF */
    &dummy, /* Vector # 458 FlexRay_0_5 FR_0_PRIF */
    &dummy, /* Vector # 459 FlexRay_0_6 FR_0_CHIF */
    &dummy, /* Vector # 460 FlexRay_0_7 FR_0_TBIF */
    &dummy, /* Vector # 461 FlexRay_0_8 FR_0_RBIF */
    &dummy, /* Vector # 462 FlexRay_0_9 FR_0_MIF */
    &dummy, /* Vector # 463 FlexRay_0_10 FR_0_STPCLK */
    &dummy, /* Vector # 464 */
    &dummy, /* Vector # 465 FlexRay_1_0 FR_1_LRNEIF | DRNEIF */
    &dummy, /* Vector # 466 FlexRay_1_1 FR_1_LRCEIF | DRCEIF */
    &dummy, /* Vector # 467 FlexRay_1_2 FR_1_FNEAIF */
    &dummy, /* Vector # 468 FlexRay_1_3 FR_1_FNEBIF */
    &dummy, /* Vector # 469 FlexRay_1_4 FR_1_WUPIF */
    &dummy, /* Vector # 470 FlexRay_1_5 FR_1_PRIF */
    &dummy, /* Vector # 471 FlexRay_1_6 FR_1_CHIF */
    &dummy, /* Vector # 472 FlexRay_1_7 FR_1_TBIF */
    &dummy, /* Vector # 473 FlexRay_1_8 FR_1_RBIF */
    &dummy, /* Vector # 474 FlexRay_1_9 FR_1_MIF */
    &dummy, /* Vector # 475 FlexRay_1_10 FR_1_STPCLK */
    &dummy, /* Vector # 476 */
    &dummy, /* Vector # 477 Power Monitor Unit GR_S[VD15] | GR_S[VD14] | GR_S[VD13] | */
            /*              GR_S[VD12] | GR_S[VD10] | GR_S[VD9] | */
            /*              GR_S[VD7] | GR_S[VD4] | GR_S[VD3] */
    &dummy, /* Vector # 478 Power management Unit (temp sensor) EPR_TD[TEMP_3] | EPR_TD[TEMP_2] | */
            /*              EPR_TD[TEMP_0] */
    &dummy, /* Vector # 479 */
    &dummy, /* Vector # 480 PLL_0_0 PLL0SR[LOLF] */
    &dummy, /* Vector # 481 */
    &dummy, /* Vector # 482 PLL_1_0 PLL1SR[LOLF] */
    &dummy, /* Vector # 483 */
    &dummy, /* Vector # 484 PLL_0_1 PLL0SR[EXTPDF] */
    &dummy, /* Vector # 485 PLL_1_1 PLL1SR[EXTPDF] */
    &dummy, /* Vector # 486 */
    &dummy, /* Vector # 487 */
#ifdef SAFETY_ENABLE
    &FCCU_IRQ_Handler, /* Vector # 488 FCCU_0 FCCU_IRQ_STAT[ALRM_STAT] */
    &FCCU_IRQ_Handler, /* Vector # 489 FCCU_1 FCU_IRQ_STAT[CFG_TO_STAT] */
#else
    &dummy, /* Vector # 488 FCCU_0 FCCU_IRQ_STAT[ALRM_STAT] */
    &dummy, /* Vector # 489 FCCU_1 FCU_IRQ_STAT[CFG_TO_STAT] */
#endif /* SAFETY_ENABLE */
    &dummy, /* Vector # 490 FCCU_2 FCCU_SCFS[RCCS0] */
    &dummy, /* Vector # 491 FCCU_3 FCCU_SCFS[RCCS1] */
    &dummy, /* Vector # 492 */
    &dummy, /* Vector # 493 */
    &dummy, /* Vector # 494 STCU2_0 STCU_RUNSW[LBIE] */
    &dummy, /* Vector # 495 STCU2_1 STCU_RUNSW[MBIE] */
    &dummy, /* Vector # 496 Hardware Security Module 0 HSM2HTIE[0] */
    &dummy, /* Vector # 497 Hardware Security Module 1 HSM2HTIE[1] */
    &dummy, /* Vector # 498 Hardware Security Module 2 HSM2HTIE[2] */
    &dummy, /* Vector # 499 Hardware Security Module 3 HSM2HTIE[3] */
    &dummy, /* Vector # 500 Hardware Security Module 4 HSM2HTIE[4] */
    
    &dummy, /* Vector # 501 Hardware Security Module 5 HSM2HTIE[5] */
    &dummy, /* Vector # 502 Hardware Security Module 6 HSM2HTIE[6] */
    &dummy, /* Vector # 503 Hardware Security Module 7 HSM2HTIE[7] */
    &dummy, /* Vector # 504 Hardware Security Module 8 HSM2HTIE[8] */
    &dummy, /* Vector # 505 Hardware Security Module 9 HSM2HTIE[9] */
    &dummy, /* Vector # 506 Hardware Security Module 10 HSM2HTIE[10] */
    &dummy, /* Vector # 507 Hardware Security Module 11 HSM2HTIE[11] */
    &dummy, /* Vector # 508 Hardware Security Module 12 HSM2HTIE[12] */
    &dummy, /* Vector # 509 Hardware Security Module 13 HSM2HTIE[13] */
    &dummy, /* Vector # 510 Hardware Security Module 14 HSM2HTIE[14] */
    &dummy, /* Vector # 511 Hardware Security Module 15 HSM2HTIE[15] */
    &dummy, /* Vector # 512 Hardware Security Module 16 HSM2HTIE[16] */
    &dummy, /* Vector # 513 Hardware Security Module 17 HSM2HTIE[17] */
    &dummy, /* Vector # 514 Hardware Security Module 18 HSM2HTIE[18] */
    &dummy, /* Vector # 515 Hardware Security Module 19 HSM2HTIE[19] */
    &dummy, /* Vector # 516 Hardware Security Module 20 HSM2HTIE[20] */
    &dummy, /* Vector # 517 Hardware Security Module 21 HSM2HTIE[21] */
    &dummy, /* Vector # 518 Hardware Security Module 22 HSM2HTIE[22] */
    &dummy, /* Vector # 519 Hardware Security Module 23 HSM2HTIE[23] */
    &dummy, /* Vector # 520 Hardware Security Module 24 HSM2HTIE[24] */
    &dummy, /* Vector # 521 Hardware Security Module 25 HSM2HTIE[25] */
    &dummy, /* Vector # 522 Hardware Security Module 26 HSM2HTIE[26] */
    &dummy, /* Vector # 523 Hardware Security Module 27 HSM2HTIE[27] */
    &dummy, /* Vector # 524 Hardware Security Module 28 HSM2HTIE[28] */
    &dummy, /* Vector # 525 Hardware Security Module 29 HSM2HTIE[29] */
    &dummy, /* Vector # 526 Hardware Security Module 30 HSM2HTIE[30] */
    &dummy, /* Vector # 527 Hardware Security Module 31 HSM2HTIE[31] */
    &dummy, /* Vector # 528 SAR_ADC0 SAR_ADC0 */
    &dummy, /* Vector # 529 SAR_ADC1 SAR_ADC1 */
    &dummy, /* Vector # 530 SAR_ADC2 SAR_ADC2 */
    &dummy, /* Vector # 531 SAR_ADC3 SAR_ADC3 */
    &dummy, /* Vector # 532 SAR_ADC4 SAR_ADC4 */
    &dummy, /* Vector # 533 */
    &dummy, /* Vector # 534 SAR_ADC6 SAR_ADC6 */
    &dummy, /* Vector # 535 SAR_ADC7 SAR_ADC7 */
    &dummy, /* Vector # 536 SAR_ADC8 SAR_ADC8 */
    &dummy, /* Vector # 537 SAR_ADC9 SAR_ADC9 */
    &dummy, /* Vector # 538 SAR_ADC10 SAR_ADC10 */
    &dummy, /* Vector # 539 SAR_ADC11 SAR_ADC11 */
    &dummy, /* Vector # 540 */
    &dummy, /* Vector # 541 */
    &dummy, /* Vector # 542 */
    &dummy, /* Vector # 543 SAR_ADCB SAR_ADCB */
    &dummy, /* Vector # 544 SD_ADC0 SD_ADC0 */
    &dummy, /* Vector # 545 SD_ADC1 SD_ADC1 */
    &dummy, /* Vector # 546 SD_ADC2 SD_ADC2 */
    &dummy, /* Vector # 547 SD_ADC3 SD_ADC3 */
    &dummy, /* Vector # 548 SD_ADC4 SD_ADC4 */
    &dummy, /* Vector # 549 SD_ADC5 SD_ADC5 */
    &dummy, /* Vector # 550 SD_ADC6 SD_ADC6 */
    &dummy, /* Vector # 551 SD_ADC7 SD_ADC7 */
    &dummy, /* Vector # 552 SD_ADC8 SD_ADC8 */
    &dummy, /* Vector # 553 SD_ADC9 SD_ADC9 */
    &dummy, /* Vector # 554 */
    &dummy, /* Vector # 555 */
    &dummy, /* Vector # 556 */
    &dummy, /* Vector # 557 */
    &dummy, /* Vector # 558 SENT_COMBINED_FAST_0 SENT_0_FMSG_RDY[0] | */
            /*              SENT_0_FMSG_RDY[1] | */
            /*              SENT_0_FMSG_RDY[2] | */
            /*              SENT_0_FMSG_RDY[3] | */
            /*              SENT_0_FMSG_RDY[4] */
    &dummy, /* Vector # 559 SENT_COMBINED_SLOW_0 SENT_0_SMSG_RDY[0] | */
            /*              SENT_0_SMSG_RDY[1] | */
            /*              SENT_0_SMSG_RDY[2] | */
            /*              SENT_0_SMSG_RDY[3] | */
            /*              SENT_0_SMSG_RDY[4] */
    &dummy, /* Vector # 560 SENT_COMBINED_ERR_0 SENT_0_GBL_STATUS[FMDU] | */
            /*              SENT_0_GBL_STATUS[SMDU] | */
            /*              SENT_0_CHn_STATUS[4:7] | */
            /*              SENT_0_CHn_STATUS[9:15] */
    &dummy, /* Vector # 561 SENT_COMBINED_FAST_1 SENT_1_FMSG_RDY[0] | */
            /*              SENT_1_FMSG_RDY[1] | */
            /*              SENT_1_FMSG_RDY[2] | */
            /*              SENT_1_FMSG_RDY[3] | */
            /*              SENT_1_FMSG_RDY[4] */
    &dummy, /* Vector # 562 SENT_COMBINED_SLOW_1 SENT_1_SMSG_RDY[0] | */
            /*              SENT_1_SMSG_RDY[1] | */
            /*              SENT_1_SMSG_RDY[2] | */
            /*              SENT_1_SMSG_RDY[3] | */
            /*              SENT_1_SMSG_RDY[4] */
    &dummy, /* Vector # 563 SENT_COMBINED_ERR_1 SENT_1_GBL_STATUS[FMDU] | */
            /*              SENT_1_GBL_STATUS[SMDU] | */
            /*              SENT_1_CHn_STATUS[4:7] | */
            /*              SENT_1_CHn_STATUS[9:15] */
    &dummy, /* Vector # 564 SENT_0_CH0_FAST SENT_0_FMSG_RDY[0] */
    &dummy, /* Vector # 565 SENT_0_CH0_SLOW SENT_0_SMSG_RDY[0] */
    &dummy, /* Vector # 566 SENT_0_CH0_ERR SENT_0_CH0_STATUS[4:7] | */
            /*              SENT_0_CH0_STATUS[9:15] */
    &dummy, /* Vector # 567 SENT_0_CH1_FAST SENT_0_FMSG_RDY[1] */
    &dummy, /* Vector # 568 SENT_0_CH1_SLOW SENT_0_SMSG_RDY[1] */
    &dummy, /* Vector # 569 SENT_0_CH1_ERR SENT_0_CH1_STATUS[4:7] | */
            /*              SENT_0_CH1_STATUS[9:15] */
    &dummy, /* Vector # 570 SENT_0_CH2_FAST SENT_0_FMSG_RDY[2] */
    &dummy, /* Vector # 571 SENT_0_CH2_SLOW SENT_0_SMSG_RDY[2] */
    &dummy, /* Vector # 572 SENT_0_CH2_ERR SENT_0_CH2_STATUS[4:7] | */
            /*              SENT_2_CH3_STATUS[9:15] */
    &dummy, /* Vector # 573 SENT_0_CH3_FAST SENT_0_FMSG_RDY[3] */
    &dummy, /* Vector # 574 SENT_0_CH3_SLOW SENT_0_SMSG_RDY[3] */
    &dummy, /* Vector # 575 SENT_0_CH3_ERR SENT_0_CH3_STATUS[4:7] | */
            /*              SENT_0_CH3_STATUS[9:15] */
    &dummy, /* Vector # 576 SENT_0_CH4_FAST SENT_0_FMSG_RDY[4] */
    &dummy, /* Vector # 577 SENT_0_CH4_SLOW SENT_0_SMSG_RDY[4] */
    &dummy, /* Vector # 578 SENT_0_CH4_ERR SENT_0_CH4_STATUS[4:7] | */
            /*              SENT_0_CH4_STATUS[9:15] */
    &dummy, /* Vector # 579 SENT_1_CH0_FAST SENT_1_FMSG_RDY[0] */
    &dummy, /* Vector # 580 SENT_1_CH0_SLOW SENT_1_SMSG_RDY[0] */
    &dummy, /* Vector # 581 SENT_1_CH0_ERR SENT_1_CH0_STATUS[4:7] | */
            /*              SENT_1_CH0_STATUS[9:15] */
    &dummy, /* Vector # 582 SENT_1_CH1_FAST SENT_1_FMSG_RDY[1] */
    &dummy, /* Vector # 583 SENT_1_CH1_SLOW SENT_1_SMSG_RDY[1] */
    &dummy, /* Vector # 584 SENT_1_CH1_ERR SENT_1_CH1_STATUS[4:7] | */
            /*              SENT_1_CH1_STATUS[9:15] */
    &dummy, /* Vector # 585 SENT_1_CH2_FAST SENT_1_FMSG_RDY[2] */
    &dummy, /* Vector # 586 SENT_1_CH2_SLOW SENT_1_SMSG_RDY[2] */
    &dummy, /* Vector # 587 SENT_1_CH2_ERR SENT_1_CH3_STATUS[4:7] | */
            /*              SENT_1_CH3_STATUS[9:15] */
    &dummy, /* Vector # 588 SENT_1_CH3_FAST SENT_1_FMSG_RDY[3] */
    &dummy, /* Vector # 589 SENT_1_CH3_SLOW SENT_1_SMSG_RDY[3] */
    &dummy, /* Vector # 590 SENT_1_CH3_ERR SENT_1_CH3_STATUS[4:7] | */
            /*              SENT_1_CH3_STATUS[9:15] */
    &dummy, /* Vector # 591 SENT_1_CH4_FAST SENT_1_FMSG_RDY[4] */
    &dummy, /* Vector # 592 SENT_1_CH4_SLOW SENT_1_SMSG_RDY[4] */
    &dummy, /* Vector # 593 SENT_1_CH4_ERR SENT_1_CH4_STATUS[4:7] | */
            /*              SENT_1_CH4_STATUS[9:15] */
    &dummy, /* Vector # 594 SENT_0_CH5_FAST SENT_0_FMSG_RDY[5] */
    &dummy, /* Vector # 595 SENT_0_CH5_SLOW SENT_0_SMSG_RDY[5] */
    &dummy, /* Vector # 596 SENT_0_CH5_ERR SENT_0_CH5_STATUS[4:7] | */
            /*              SENT_0_CH5_STATUS[9:15] */
    &dummy, /* Vector # 597 SENT_0_CH6_FAST SENT_0_FMSG_RDY[6] */
    &dummy, /* Vector # 598 SENT_0_CH6_SLOW SENT_0_SMSG_RDY[6] */
    &dummy, /* Vector # 599 SENT_0_CH6_ERR SENT_0_CH6_STATUS[4:7] | */
            /*              SENT_0_CH6_STATUS[9:15] */
    &dummy, /* Vector # 600 SENT_0_CH7_FAST SENT_0_FMSG_RDY[7] */
    
    &dummy, /* Vector # 601 SENT_0_CH7_SLOW SENT_0_SMSG_RDY[7] */
    &dummy, /* Vector # 602 SENT_0_CH7_ERR SENT_0_CH7_STATUS[4:7] | */
            /*              SENT_0_CH7_STATUS[9:15] */
    &dummy, /* Vector # 603 SENT_1_CH5_FAST SENT_1_FMSG_RDY[5] */
    &dummy, /* Vector # 604 SENT_1_CH5_SLOW SENT_1_SMSG_RDY[5] */
    &dummy, /* Vector # 605 SENT_1_CH5_ERR SENT_1_CH5_STATUS[4:7] | */
            /*              SENT_1_CH5_STATUS[9:15] */
    &dummy, /* Vector # 606 SENT_1_CH6_FAST SENT_1_FMSG_RDY[6] */
    &dummy, /* Vector # 607 SENT_1_CH6_SLOW SENT_1_SMSG_RDY[6] */
    &dummy, /* Vector # 608 SENT_1_CH6_ERR SENT_1_CH6_STATUS[4:7] | */
            /*              SENT_1_CH6_STATUS[9:15] */
    &dummy, /* Vector # 609 */
    &dummy, /* Vector # 610 */
    &dummy, /* Vector # 611 */
    &dummy, /* Vector # 612 PSI5_0_CH0_0 PSI5_0_CH_0_DSR[IS_DMA_TF_PM_DS] | PSI5_0_CH_0_DSR[IS_DMA_TF_SF] | */
            /*              PSI5_0_CH_0_DSR[IS_DMA_PM_DS_FIFO_FULL] | */
            /*              PSI5_0_CH_0_DSR[IS_DMA_SFUF] | */
            /*              PSI5_0_CH_0_DSR[IS_DMA_PM_DS_UF] */
    &dummy, /* Vector # 613 PSI5_0_CH0_1 PSI5_0_CH_0_GISR[IS_CESM[6:1]] | */
            /*              PSI5_0_CH_0_GISR[IS_STS] | */
            /*              PSI5_0_CH_0_GISR[IS_DTS] | */
            /*              PSI5_0_CH_0_GISR[[IS_DSROW] | */
            /*              PSI5_0_CH_0_GISR[IS_BROW] | */
            /*              PSI5_0_CH_0_GISR[[DSR_RDY] | */
            /*              PSI5_0_CH_0_GISR[DBR_RDY] | */
            /*              PSI5_0_CH_0_GISR[DPR_RDY] | */
            /*              PSI5_0_CH_0_GISR[IS_OWSM[6:1]] | */
            /*              PSI5_0_CH_0_GISR[IS_NVSM[6:1]] */
    &dummy, /* Vector # 614 PSI5_0_CH0_2 PSI5_0_CH_0_NDSR[NDS31] | */
            /*              PSI5_0_CH_0_NDSR[NDS30] | ��?| */
            /*              PSI5_0_CH_0_NDSR[NDS1] | */
            /*              PSI5_0_CH_0_NDSR[NDS0] */
    &dummy, /* Vector # 615 PSI5_0_CH0_3 PSI5_0_CH_0_OWSR[NDS31] | */
            /*              PSI5_0_CH_0_OWSR[NDS30] | ��?| */
            /*              PSI5_0_CH_0_OWSR[NDS1] | */
            /*              PSI5_0_CH_0_OWSR[NDS0] */
    &dummy, /* Vector # 616 PSI5_0_CH0_4 PSI5_0_CH_0_EISR[NDS31] | */
            /*              PSI5_0_CH_0_EISR[NDS30] | ��?| */
            /*              PSI5_0_CH_0_EISR[NDS1] | */
            /*              PSI5_0_CH_0_EISR[NDS0] */
    &dummy, /* Vector # 617 PSI5_0_CH0_5 PSI5_0_CH_0_DSR[*] | */
            /*              PSI5_0_CH_0_GISR[*] | */
            /*              PSI5_0_CH_0_NDSR[31:0] | */
            /*              PSI5_0_CH_0_OWSR[31:0] | */
            /*              PSI5_0_CH_0_EISR[31:0] */
    &dummy, /* Vector # 618 PSI5_0_CH1_0 PSI5_0_CH_1_DSR[IS_DMA_TF_PM_DS] | PSI5_0_CH_1_DSR[IS_DMA_TF_SF] | */
            /*              PSI5_0_CH_1_DSR[IS_DMA_PM_DS_FIFO_FULL] | */
            /*              PSI5_0_CH_1_DSR[IS_DMA_SFUF] | */
            /*              PSI5_0_CH_1_DSR[IS_DMA_PM_DS_UF] */
    &dummy, /* Vector # 619 PSI5_0_CH1_1 PSI5_0_CH_1_GISR[IS_CESM[6:1]] | */
            /*              PSI5_0_CH_1_GISR[IS_STS] | */
            /*              PSI5_0_CH_1_GISR[IS_DTS] | */
            /*              PSI5_0_CH_1_GISR[[IS_DSROW] | */
            /*              PSI5_0_CH_1_GISR[IS_BROW] | */
            /*              PSI5_0_CH_1_GISR[[DSR_RDY] | */
            /*              PSI5_0_CH_1_GISR[DBR_RDY] | */
            /*              PSI5_0_CH_1_GISR[DPR_RDY] | */
            /*              PSI5_0_CH_1_GISR[IS_OWSM[6:1]] | */
            /*              PSI5_0_CH_1_GISR[IS_NVSM[6:1]] */
    &dummy, /* Vector # 620 PSI5_0_CH1_2 PSI5_0_CH_1_NDSR[NDS31] | */
            /*              PSI5_0_CH_1_NDSR[NDS30] | ��?| */
            /*              PSI5_0_CH_1_NDSR[NDS1] | */
            /*              PSI5_0_CH_1_NDSR[NDS0] */
    &dummy, /* Vector # 621 PSI5_0_CH1_3 PSI5_0_CH_1_OWSR[NDS31] | */
            /*              PSI5_0_CH_1_OWSR[NDS30] | ��?| */
            /*              PSI5_0_CH_1_OWSR[NDS1] | */
            /*              PSI5_0_CH_1_OWSR[NDS0] */
    &dummy, /* Vector # 622 PSI5_0_CH1_4 PSI5_0_CH_1_EISR[NDS31] | */
            /*              PSI5_0_CH_1_EISR[NDS30] | ��?| */
            /*              PSI5_0_CH_1_EISR[NDS1] | */
            /*              PSI5_0_CH_1_EISR[NDS0] */
    &dummy, /* Vector # 623 PSI5_0_CH1_5 PSI5_0_CH_1_DSR[*] | */
            /*              PSI5_0_CH_1_GISR[*] | */
            /*              PSI5_0_CH_1_NDSR[31:0] | */
            /*              PSI5_0_CH_1_OWSR[31:0] | */
            /*              PSI5_0_CH_1_EISR[31:0] */
    &dummy, /* Vector # 624 PSI5_1_CH0_0 PSI5_1_CH_0_DSR[IS_DMA_TF_PM_DS] | PSI5_1_CH_0_DSR[IS_DMA_TF_SF] | */
            /*              PSI5_1_CH_0_DSR[IS_DMA_PM_DS_FIFO_FULL] | */
            /*              PSI5_1_CH_0_DSR[IS_DMA_SFUF] | */
            /*              PSI5_1_CH_0_DSR[IS_DMA_PM_DS_UF] */
    &dummy, /* Vector # 625 PSI5_1_CH0_1 PSI5_1_CH_0_GISR[IS_CESM[6:1]] | */
            /*              PSI5_1_CH_0_GISR[IS_STS] | */
            /*              PSI5_1_CH_0_GISR[IS_DTS] | */
            /*              PSI5_1_CH_0_GISR[[IS_DSROW] | */
            /*              PSI5_1_CH_0_GISR[IS_BROW] | */
            /*              PSI5_1_CH_0_GISR[[DSR_RDY] | */
            /*              PSI5_1_CH_0_GISR[DBR_RDY] | */
            /*              PSI5_1_CH_0_GISR[DPR_RDY] | */
            /*              PSI5_1_CH_0_GISR[IS_OWSM[6:1]] | */
            /*              PSI5_1_CH_0_GISR[IS_NVSM[6:1]] */
    &dummy, /* Vector # 626 PSI5_1_CH0_2 PSI5_1_CH_0_NDSR[NDS31] | */
            /*              PSI5_1_CH_0_NDSR[NDS30] | ��?| */
            /*              PSI5_1_CH_0_NDSR[NDS1] | */
            /*              PSI5_1_CH_0_NDSR[NDS0] */
    &dummy, /* Vector # 627 PSI5_1_CH0_3 PSI5_1_CH_0_OWSR[NDS31] | */
            /*              PSI5_1_CH_0_OWSR[NDS30] | ��?| */
            /*              PSI5_1_CH_0_OWSR[NDS1] | */
            /*              PSI5_1_CH_0_OWSR[NDS0] */
    &dummy, /* Vector # 628 PSI5_1_CH0_4 PSI5_1_CH_0_EISR[NDS31] | */
            /*              PSI5_1_CH_0_EISR[NDS30] | ��?| */
            /*              PSI5_1_CH_0_EISR[NDS1] | */
            /*              PSI5_1_CH_0_EISR[NDS0] */
    &dummy, /* Vector # 629 PSI5_1_CH0_5 PSI5_1_CH_0_DSR[*] | */
            /*              PSI5_1_CH_0_GISR[*] | */
            /*              PSI5_1_CH_0_NDSR[31:0] | */
            /*              PSI5_1_CH_0_OWSR[31:0] | */
            /*              PSI5_1_CH_0_EISR[31:0] */
    &dummy, /* Vector # 630 PSI5_0_CH2_0 PSI5_0_CH_2_DSR[IS_DMA_TF_PM_DS] | PSI5_0_CH_2_DSR[IS_DMA_TF_SF] | */
            /*              PSI5_0_CH_2_DSR[IS_DMA_PM_DS_FIFO_FULL] | */
            /*              PSI5_0_CH_2_DSR[IS_DMA_SFUF] | */
            /*              PSI5_0_CH_2_DSR[IS_DMA_PM_DS_UF] */
    &dummy, /* Vector # 631 PSI5_0_CH2_1 PSI5_0_CH_2_GISR[IS_CESM[6:1]] | */
            /*              PSI5_0_CH_2_GISR[IS_STS] | */
            /*              PSI5_0_CH_2_GISR[IS_DTS] | */
            /*              PSI5_0_CH_2_GISR[[IS_DSROW] | */
            /*              PSI5_0_CH_2_GISR[IS_BROW] | */
            /*              PSI5_0_CH_2_GISR[[DSR_RDY] | */
            /*              PSI5_0_CH_2_GISR[DBR_RDY] | */
            /*              PSI5_0_CH_2_GISR[DPR_RDY] | */
            /*              PSI5_0_CH_2_GISR[IS_OWSM[6:1]] | */
            /*              PSI5_0_CH_2_GISR[IS_NVSM[6:1]] */
    &dummy, /* Vector # 632 PSI5_0_CH2_2 PSI5_0_CH_2_NDSR[NDS31] | */
            /*              PSI5_0_CH_2_NDSR[NDS30] | ��?| */
            /*              PSI5_0_CH_2_NDSR[NDS1] | */
            /*              PSI5_0_CH_2_NDSR[NDS0] */
    &dummy, /* Vector # 633 PSI5_0_CH2_3 PSI5_0_CH_2_OWSR[NDS31] | */
            /*              PSI5_0_CH_2_OWSR[NDS30] | ��?| */
            /*              PSI5_0_CH_2_OWSR[NDS1] | */
            /*              PSI5_0_CH_2_OWSR[NDS0] */
    &dummy, /* Vector # 634 PSI5_0_CH2_4 PSI5_0_CH_2_EISR[NDS31] | */
            /*              PSI5_0_CH_2_EISR[NDS30] | ��?| */
            /*              PSI5_0_CH_2_EISR[NDS1] | */
            /*              PSI5_0_CH_2_EISR[NDS0] */
    &dummy, /* Vector # 635 PSI5_0_CH2_5 PSI5_0_CH_2_DSR[*] | */
            /*              PSI5_0_CH_2_GISR[*] | */
            /*              PSI5_0_CH_2_NDSR[31:0] | */
            /*              PSI5_0_CH_2_OWSR[31:0] | */
            /*              PSI5_0_CH_2_EISR[31:0] */
    &dummy, /* Vector # 636 PSI5_1_CH1_0 PSI5_1_CH_1_DSR[IS_DMA_TF_PM_DS] | PSI5_1_CH_1_DSR[IS_DMA_TF_SF] | */
            /*              PSI5_1_CH_1_DSR[IS_DMA_PM_DS_FIFO_FULL] | */
            /*              PSI5_1_CH_1_DSR[IS_DMA_SFUF] | */
            /*              PSI5_1_CH_1_DSR[IS_DMA_PM_DS_UF] */
    &dummy, /* Vector # 637 PSI5_1_CH1_1 PSI5_1_CH_1_GISR[IS_CESM[6:1]] | */
            /*              PSI5_1_CH_1_GISR[IS_STS] | */
            /*              PSI5_1_CH_1_GISR[IS_DTS] | */
            /*              PSI5_1_CH_1_GISR[[IS_DSROW] | */
            /*              PSI5_1_CH_1_GISR[IS_BROW] | */
            /*              PSI5_1_CH_1_GISR[[DSR_RDY] | */
            /*              PSI5_1_CH_1_GISR[DBR_RDY] | */
            /*              PSI5_1_CH_1_GISR[DPR_RDY] | */
            /*              PSI5_1_CH_1_GISR[IS_OWSM[6:1]] | */
            /*              PSI5_1_CH_1_GISR[IS_NVSM[6:1]] */
    &dummy, /* Vector # 638 PSI5_1_CH1_2 PSI5_1_CH_1_NDSR[NDS31] | */
            /*              PSI5_1_CH_1_NDSR[NDS30] | ��?| */
            /*              PSI5_1_CH_1_NDSR[NDS1] | */
            /*              PSI5_1_CH_1_NDSR[NDS0] */
    &dummy, /* Vector # 639 PSI5_1_CH1_3 PSI5_1_CH_1_OWSR[NDS31] | */
            /*              PSI5_1_CH_1_OWSR[NDS30] | ��?| */
            /*              PSI5_1_CH_1_OWSR[NDS1] | */
            /*              PSI5_1_CH_1_OWSR[NDS0] */
    &dummy, /* Vector # 640 PSI5_1_CH1_4 PSI5_1_CH_1_EISR[NDS31] | */
            /*              PSI5_1_CH_1_EISR[NDS30] | ��?| */
            /*              PSI5_1_CH_1_EISR[NDS1] | */
            /*              PSI5_1_CH_1_EISR[NDS0] */
    &dummy, /* Vector # 641 PSI5_1_CH1_5 PSI5_1_CH_1_DSR[*] | */
            /*              PSI5_1_CH_1_GISR[*] | */
            /*              PSI5_1_CH_1_NDSR[31:0] | */
            /*              PSI5_1_CH_1_OWSR[31:0] | */
            /*              PSI5_1_CH_1_EISR[31:0] */
    &dummy, /* Vector # 642 */
    &dummy, /* Vector # 643 */
    &dummy, /* Vector # 644 */
    &dummy, /* Vector # 645 */
    &dummy, /* Vector # 646 */
    &dummy, /* Vector # 647 */
    &dummy, /* Vector # 648 */
    &dummy, /* Vector # 649 */
    &dummy, /* Vector # 650 */
    &dummy, /* Vector # 651 */
    &dummy, /* Vector # 652 */
    &dummy, /* Vector # 653 */
    &dummy, /* Vector # 654 SIPI_0 SIPI_ERR[TOEn] | SIPI_ERR[TIDEn] | */
            /*              SIPI_ERR[ACKEn] */
    &dummy, /* Vector # 655 SIPI_1 SIPI_SR[GCRCE) */
    &dummy, /* Vector # 656 SIPI_2 SIPI_CSR0[RAR] | SIPI_CSR0[ACKR] */
    &dummy, /* Vector # 657 SIPI_3 SIPI_CSR1[RAR] | SIPI_CSR1[ACKR] */
    &dummy, /* Vector # 658 SIPI_4 SIPI_CSR2[RAR] | SIPI_CSR2[ACKR] */
    &dummy, /* Vector # 659 SIPI_5 SIPI_CSR3[RAR] | SIPI_CSR3[ACKR] */
    &dummy, /* Vector # 660 SIPI_6 SIPI_SR[TE0] | SIPI_SR[TE1] | */
            /*              SIPI_SR[TE2] |SIPI_SR[TE3] | */
            /*              SIPI_SR[MCR] */
    &dummy, /* Vector # 661 LFAST0_0 LFAST_0_TISR[TXPNGF] | */
            /*              LFAST_0_TISR[TXUNSF] | */
            /*              LFAST_0_TISR[TXICLCF] | */
            /*              LFAST_0_TISR[TXDTF] */
    &dummy, /* Vector # 662 LFAST0_1 LFAST_0_TISR[TXIEF] | */
            /*              LFAST_0_TISR[TXOVF] */
    &dummy, /* Vector # 663 LFAST0_2 LFAST_0_RISR[RXCTSF] | */
            /*              LFAST_0_RISR[RXDF] | */
            /*              LFAST_0_RISR[RXUNSF] */
    &dummy, /* Vector # 664 LFAST0_3 LFAST_0_RISR[RXUOF] | */
            /*              LFAST_0_RISR[RXMNF] | */
            /*              LFAST_0_RISR[RXMXF] | */
            /*              LFAST_0_RISR[RXUFF] | */
            /*              LFAST_0_RISR[RXOFF] | */
            /*              LFAST_0_RISR[RXSZF] | */
            /*              LFAST_0_RISR[RXICF] | */
            /*              LFAST_0_RISR[RXLCEF] */
    &dummy, /* Vector # 665 LFAST0_4 LFAST_0_RIISR[ICPFF] | */
            /*              LFAST_0_RIISR[ICPSF] | */
            /*              LFAST_0_RIISR[ICPRF] | */
            /*              LFAST_0_RIISR[ICTOF] | */
            /*              LFAST_0_RIISR[ICLPF] | */
            /*              LFAST_0_RIISR[ICCTF] | */
            /*              LFAST_0_RIISR[ICTDF] | */
            /*              LFAST_0_RIISR[ICTEF] | */
            /*              LFAST_0_RIISR[ICRFF] | */
            /*              LFAST_0_RIISR[ICRSF] | */
            /*              LFAST_0_RIISR[ICTFF] | */
            /*              LFAST_0_RIISR[ICTSF] | */
            /*              LFAST_0_RIISR[ICPOFF] | */
            /*              LFAST_0_RIISR[ICPONF] */
    &dummy, /* Vector # 666 */
    &dummy, /* Vector # 667 */
    &dummy, /* Vector # 668 */
    &dummy, /* Vector # 669 */
    &dummy, /* Vector # 670 */
    &dummy, /* Vector # 671 */
    &dummy, /* Vector # 672 */
    &dummy, /* Vector # 673 */
    &dummy, /* Vector # 674 JTAGM JTAGM_SR[SPU_INT] | JTAGM_SR[Idle] */
    &dummy, /* Vector # 675 JDC JDC_MSR[JIN_INT] | */
            /*              JDC_MSR[JOUT_INT] */
    &dummy, /* Vector # 676 */
    &dummy, /* Vector # 677 M_TTCAN0_0 M_TTCAN_0 interrupt line0 */
    &dummy, /* Vector # 678 M_TTCAN0_1 M_TTCAN_0 interrupt line1 */
    &dummy, /* Vector # 679 M_TTCAN0_2 M_TTCAN_0 Register Time Mark interrupt */
    &dummy, /* Vector # 680 */
    &dummy, /* Vector # 681 */
    &dummy, /* Vector # 682 */
    &dummy, /* Vector # 683 */
    &dummy, /* Vector # 684 */
    &dummy, /* Vector # 685 */
    &dummy, /* Vector # 686 */
    &dummy, /* Vector # 687 */
    &dummy, /* Vector # 688 M_CAN1_0 m_can1_int0 */
    &dummy, /* Vector # 689 M_CAN1_1 m_can1_int1 */
    &dummy, /* Vector # 690 M_CAN2_0 m_can2_int0 */
    &dummy, /* Vector # 691 M_CAN2_1 m_can2_int1 */
    &dummy, /* Vector # 692 M_CAN3_0 m_can3_int0 */
    &dummy, /* Vector # 693 M_CAN3_1 m_can3_int1 */
    &dummy, /* Vector # 694 M_CAN4_0 m_can4_int0 */
    &dummy, /* Vector # 695 M_CAN4_1 m_can4_int1 */
    &dummy, /* Vector # 696 */
    &dummy, /* Vector # 697 */
    &dummy, /* Vector # 698 */
    &dummy, /* Vector # 699 */
    &dummy, /* Vector # 700 */
    &dummy, /* Vector # 701 */
    &dummy, /* Vector # 702 */
    &dummy, /* Vector # 703 */
    &dummy, /* Vector # 704 */
    &dummy, /* Vector # 705 */
    &dummy, /* Vector # 706 GTM_AEI_IRQ AEI gtm_icm.gtm_aei_irq aei */
    &dummy, /* Vector # 707 GTM_ARU_IRQ[0] gtm_icm.gtm_aru_irq[0] */
    &dummy, /* Vector # 708 GTM_ARU_IRQ[1] gtm_icm.gtm_aru_irq[1] */
    &dummy, /* Vector # 709 GTM_ARU_IRQ[2] gtm_icm.gtm_aru_irq[2] */
    &dummy, /* Vector # 710 GTM_BRC_IRQ gtm_icm.gtm_brc_irq */
    &dummy, /* Vector # 711 GTM_CMP_IRQ gtm_icm.gtm_cmp_irq */
    &dummy, /* Vector # 712 GTM_SPE0_IRQ gtm_icm.gtm_spe0_irq */
    &dummy, /* Vector # 713 GTM_SPE1_IRQ gtm_icm.gtm_spe1_irq */
    &dummy, /* Vector # 714 GTM_PSM0_IRQ[0] gtm_icm.gtm_psm0_irq[0] */
    &dummy, /* Vector # 715 GTM_PSM0_IRQ[1] gtm_icm.gtm_psm0_irq[1] */
    &dummy, /* Vector # 716 GTM_PSM0_IRQ[2] gtm_icm.gtm_psm0_irq[2] */
    &dummy, /* Vector # 717 GTM_PSM0_IRQ[3] gtm_icm.gtm_psm0_irq[3] */
    &dummy, /* Vector # 718 GTM_PSM0_IRQ[4] gtm_icm.gtm_psm0_irq[4] */
    &dummy, /* Vector # 719 GTM_PSM0_IRQ[5] gtm_icm.gtm_psm0_irq[5] */
    &dummy, /* Vector # 720 GTM_PSM0_IRQ[6] gtm_icm.gtm_psm0_irq[6] */
    &dummy, /* Vector # 721 GTM_PSM0_IRQ[7] gtm_icm.gtm_psm0_irq[7] */
    &dummy, /* Vector # 722 GTM_DPLL_IRQ[0] gtm_icm.gtm_dpll_irq[0] */
    &dummy, /* Vector # 723 GTM_DPLL_IRQ[1] gtm_icm.gtm_dpll_irq[1] */
    &dummy, /* Vector # 724 GTM_DPLL_IRQ[2] gtm_icm.gtm_dpll_irq[2] */
    &dummy, /* Vector # 725 GTM_DPLL_IRQ[3] gtm_icm.gtm_dpll_irq[3] */
    &dummy, /* Vector # 726 GTM_DPLL_IRQ[4] gtm_icm.gtm_dpll_irq[4] */
    &dummy, /* Vector # 727 GTM_DPLL_IRQ[5] gtm_icm.gtm_dpll_irq[5] */
    &dummy, /* Vector # 728 GTM_DPLL_IRQ[6] gtm_icm.gtm_dpll_irq[6] */
    &dummy, /* Vector # 729 GTM_DPLL_IRQ[7] gtm_icm.gtm_dpll_irq[7] */
    &dummy, /* Vector # 730 GTM_DPLL_IRQ[8] gtm_icm.gtm_dpll_irq[8] */
    &dummy, /* Vector # 731 GTM_DPLL_IRQ[9] gtm_icm.gtm_dpll_irq[9] */
    &dummy, /* Vector # 732 GTM_DPLL_IRQ[10] gtm_icm.gtm_dpll_irq[10] */
    &dummy, /* Vector # 733 GTM_DPLL_IRQ[11] gtm_icm.gtm_dpll_irq[11] */
    &dummy, /* Vector # 734 GTM_DPLL_IRQ[12] gtm_icm.gtm_dpll_irq[12] */
    &dummy, /* Vector # 735 GTM_DPLL_IRQ[13] gtm_icm.gtm_dpll_irq[13] */
    &dummy, /* Vector # 736 GTM_DPLL_IRQ[14] gtm_icm.gtm_dpll_irq[14] */
    &dummy, /* Vector # 737 GTM_DPLL_IRQ[15] gtm_icm.gtm_dpll_irq[15] */
    &dummy, /* Vector # 738 GTM_DPLL_IRQ[16] gtm_icm.gtm_dpll_irq[16] */
    &dummy, /* Vector # 739 GTM_DPLL_IRQ[17] gtm_icm.gtm_dpll_irq[17] */
    &dummy, /* Vector # 740 GTM_DPLL_IRQ[18] gtm_icm.gtm_dpll_irq[18] */
    &dummy, /* Vector # 741 GTM_DPLL_IRQ[19] gtm_icm.gtm_dpll_irq[19] */
    &dummy, /* Vector # 742 GTM_DPLL_IRQ[20] gtm_icm.gtm_dpll_irq[20] */
    &dummy, /* Vector # 743 GTM_DPLL_IRQ[21] gtm_icm.gtm_dpll_irq[21] */
    &dummy, /* Vector # 744 GTM_DPLL_IRQ[22] gtm_icm.gtm_dpll_irq[22] */
    &dummy, /* Vector # 745 GTM_DPLL_IRQ[23] gtm_icm.gtm_dpll_irq[23] */
    &dummy, /* Vector # 746 GTM_DPLL_IRQ[24] gtm_icm.gtm_dpll_irq[24] */
    &dummy, /* Vector # 747 GTM_DPLL_IRQ[25] gtm_icm.gtm_dpll_irq[25] */
    &dummy, /* Vector # 748 GTM_DPLL_IRQ[26] gtm_icm.gtm_dpll_irq[26] */
    &dummy, /* Vector # 749 GTM_TIM0_IRQ[0] gtm_icm.gtm_tim0_irq[0] */
    &dummy, /* Vector # 750 GTM_TIM0_IRQ[1] gtm_icm.gtm_tim0_irq[1] */
    &dummy, /* Vector # 751 GTM_TIM0_IRQ[2] gtm_icm.gtm_tim0_irq[2] */
    &dummy, /* Vector # 752 GTM_TIM0_IRQ[3] gtm_icm.gtm_tim0_irq[3] */
    &dummy, /* Vector # 753 GTM_TIM0_IRQ[4] gtm_icm.gtm_tim0_irq[4] */
    &dummy, /* Vector # 754 GTM_TIM0_IRQ[5] gtm_icm.gtm_tim0_irq[5] */
    &dummy, /* Vector # 755 GTM_TIM0_IRQ[6] gtm_icm.gtm_tim0_irq[6] */
    &dummy, /* Vector # 756 GTM_TIM0_IRQ[7] gtm_icm.gtm_tim0_irq[7] */
    &dummy, /* Vector # 757 GTM_TIM1_IRQ[0] gtm_icm.gtm_tim1_irq[0] */
    &dummy, /* Vector # 758 GTM_TIM1_IRQ[1] gtm_icm.gtm_tim1_irq[1] */
    &dummy, /* Vector # 759 GTM_TIM1_IRQ[2] gtm_icm.gtm_tim1_irq[2] */
    &dummy, /* Vector # 760 GTM_TIM1_IRQ[3] gtm_icm.gtm_tim1_irq[3] */
    &dummy, /* Vector # 761 GTM_TIM1_IRQ[4] gtm_icm.gtm_tim1_irq[4] */
    &dummy, /* Vector # 762 GTM_TIM1_IRQ[5] gtm_icm.gtm_tim1_irq[5] */
    &dummy, /* Vector # 763 GTM_TIM1_IRQ[6] gtm_icm.gtm_tim1_irq[6] */
    &dummy, /* Vector # 764 GTM_TIM1_IRQ[7] gtm_icm.gtm_tim1_irq[7] */
    &dummy, /* Vector # 765 GTM_TIM2_IRQ[0] gtm_icm.gtm_tim2_irq[0] */
    &dummy, /* Vector # 766 GTM_TIM2_IRQ[1] gtm_icm.gtm_tim2_irq[1] */
    &dummy, /* Vector # 767 GTM_TIM2_IRQ[2] gtm_icm.gtm_tim2_irq[2] */
    &dummy, /* Vector # 768 GTM_TIM2_IRQ[3] gtm_icm.gtm_tim2_irq[3] */
    &dummy, /* Vector # 769 GTM_TIM2_IRQ[4] gtm_icm.gtm_tim2_irq[4] */
    &dummy, /* Vector # 770 GTM_TIM2_IRQ[5] gtm_icm.gtm_tim2_irq[5] */
    &dummy, /* Vector # 771 GTM_TIM2_IRQ[6] gtm_icm.gtm_tim2_irq[6] */
    &dummy, /* Vector # 772 GTM_TIM2_IRQ[7] gtm_icm.gtm_tim2_irq[7] */
    &dummy, /* Vector # 773 GTM_TIM3_IRQ[0] gtm_icm.gtm_tim3_irq[0] */
    &dummy, /* Vector # 774 GTM_TIM3_IRQ[1] gtm_icm.gtm_tim3_irq[1] */
    &dummy, /* Vector # 775 GTM_TIM3_IRQ[2] gtm_icm.gtm_tim3_irq[2] */
    &dummy, /* Vector # 776 GTM_TIM3_IRQ[3] gtm_icm.gtm_tim3_irq[3] */
    &dummy, /* Vector # 777 GTM_TIM3_IRQ[4] gtm_icm.gtm_tim3_irq[4] */
    &dummy, /* Vector # 778 GTM_TIM3_IRQ[5] gtm_icm.gtm_tim3_irq[5] */
    &dummy, /* Vector # 779 GTM_TIM3_IRQ[6] gtm_icm.gtm_tim3_irq[6] */
    &dummy, /* Vector # 780 GTM_TIM3_IRQ[7] gtm_icm.gtm_tim3_irq[7] */
    &dummy, /* Vector # 781 GTM_MCS0_IRQ[0] gtm_icm.gtm_mcs0_irq[0] */
    &dummy, /* Vector # 782 GTM_MCS0_IRQ[1] gtm_icm.gtm_mcs0_irq[1] */
    &dummy, /* Vector # 783 GTM_MCS0_IRQ[2] gtm_icm.gtm_mcs0_irq[2] */
    &dummy, /* Vector # 784 GTM_MCS0_IRQ[3] gtm_icm.gtm_mcs0_irq[3] */
    &dummy, /* Vector # 785 GTM_MCS0_IRQ[4] gtm_icm.gtm_mcs0_irq[4] */
    &dummy, /* Vector # 786 GTM_MCS0_IRQ[5] gtm_icm.gtm_mcs0_irq[5] */
    &dummy, /* Vector # 787 GTM_MCS0_IRQ[6] gtm_icm.gtm_mcs0_irq[6] */
    &dummy, /* Vector # 788 GTM_MCS0_IRQ[7] gtm_icm.gtm_mcs0_irq[7] */
    &dummy, /* Vector # 789 GTM_MCS1_IRQ[0] gtm_icm.gtm_mcs1_irq[0] */
    &dummy, /* Vector # 790 GTM_MCS1_IRQ[1] gtm_icm.gtm_mcs1_irq[1] */
    &dummy, /* Vector # 791 GTM_MCS1_IRQ[2] gtm_icm.gtm_mcs1_irq[2] */
    &dummy, /* Vector # 792 GTM_MCS1_IRQ[3] gtm_icm.gtm_mcs1_irq[3] */
    &dummy, /* Vector # 793 GTM_MCS1_IRQ[4] gtm_icm.gtm_mcs1_irq[4] */
    &dummy, /* Vector # 794 GTM_MCS1_IRQ[5] gtm_icm.gtm_mcs1_irq[5] */
    &dummy, /* Vector # 795 GTM_MCS1_IRQ[6] gtm_icm.gtm_mcs1_irq[6] */
    &dummy, /* Vector # 796 GTM_MCS1_IRQ[7] gtm_icm.gtm_mcs1_irq[7] */
    &dummy, /* Vector # 797 GTM_MCS2_IRQ[0] gtm_icm.gtm_mcs2_irq[0] */
    &dummy, /* Vector # 798 GTM_MCS2_IRQ[1] gtm_icm.gtm_mcs2_irq[1] */
    &dummy, /* Vector # 799 GTM_MCS2_IRQ[2] gtm_icm.gtm_mcs2_irq[2] */
    &dummy, /* Vector # 800 GTM_MCS2_IRQ[3] gtm_icm.gtm_mcs2_irq[3] */
    
    &dummy, /* Vector # 801 GTM_MCS2_IRQ[4] gtm_icm.gtm_mcs2_irq[4] */
    &dummy, /* Vector # 802 GTM_MCS2_IRQ[5] gtm_icm.gtm_mcs2_irq[5] */
    &dummy, /* Vector # 803 GTM_MCS2_IRQ[6] gtm_icm.gtm_mcs2_irq[6] */
    &dummy, /* Vector # 804 GTM_MCS2_IRQ[7] gtm_icm.gtm_mcs2_irq[7] */
    &dummy, /* Vector # 805 GTM_MCS3_IRQ[0] gtm_icm.gtm_mcs3_irq[0] */
    &dummy, /* Vector # 806 GTM_MCS3_IRQ[1] gtm_icm.gtm_mcs3_irq[1] */
    &dummy, /* Vector # 807 GTM_MCS3_IRQ[2] gtm_icm.gtm_mcs3_irq[2] */
    &dummy, /* Vector # 808 GTM_MCS3_IRQ[3] gtm_icm.gtm_mcs3_irq[3] */
    &dummy, /* Vector # 809 GTM_MCS3_IRQ[4] gtm_icm.gtm_mcs3_irq[4] */
    &dummy, /* Vector # 810 GTM_MCS3_IRQ[5] gtm_icm.gtm_mcs3_irq[5] */
    &dummy, /* Vector # 811 GTM_MCS3_IRQ[6] gtm_icm.gtm_mcs3_irq[6] */
    &dummy, /* Vector # 812 GTM_MCS3_IRQ[7] gtm_icm.gtm_mcs3_irq[7] */
    &dummy, /* Vector # 813 GTM_TOM0_IRQ[0] gtm_icm.gtm_tom0_irq[0] */
    &dummy, /* Vector # 814 GTM_TOM0_IRQ[1] gtm_icm.gtm_tom0_irq[1] */
    &dummy, /* Vector # 815 GTM_TOM0_IRQ[2] gtm_icm.gtm_tom0_irq[2] */
    &dummy, /* Vector # 816 GTM_TOM0_IRQ[3] gtm_icm.gtm_tom0_irq[3] */
    &dummy, /* Vector # 817 GTM_TOM0_IRQ[4] gtm_icm.gtm_tom0_irq[4] */
    &dummy, /* Vector # 818 GTM_TOM0_IRQ[5] gtm_icm.gtm_tom0_irq[5] */
    &dummy, /* Vector # 819 GTM_TOM0_IRQ[6] gtm_icm.gtm_tom0_irq[6] */
    &dummy, /* Vector # 820 GTM_TOM0_IRQ[7] gtm_icm.gtm_tom0_irq[7] */
    &dummy, /* Vector # 821 GTM_TOM1_IRQ[0] gtm_icm.gtm_tom1_irq[0] */
    &dummy, /* Vector # 822 GTM_TOM1_IRQ[1] gtm_icm.gtm_tom1_irq[1] */
    &dummy, /* Vector # 823 GTM_TOM1_IRQ[2] gtm_icm.gtm_tom1_irq[2] */
    &dummy, /* Vector # 824 GTM_TOM1_IRQ[3] gtm_icm.gtm_tom1_irq[3] */
    &dummy, /* Vector # 825 GTM_TOM1_IRQ[4] gtm_icm.gtm_tom1_irq[4] */
    &dummy, /* Vector # 826 GTM_TOM1_IRQ[5] gtm_icm.gtm_tom1_irq[5] */
    &dummy, /* Vector # 827 GTM_TOM1_IRQ[6] gtm_icm.gtm_tom1_irq[6] */
    &dummy, /* Vector # 828 GTM_TOM1_IRQ[7] gtm_icm.gtm_tom1_irq[7] */
    &dummy, /* Vector # 829 GTM_TOM2_IRQ[0] gtm_icm.gtm_tom2_irq[0] */
    &dummy, /* Vector # 830 GTM_TOM2_IRQ[1] gtm_icm.gtm_tom2_irq[1] */
    &dummy, /* Vector # 831 GTM_TOM2_IRQ[2] gtm_icm.gtm_tom2_irq[2] */
    &dummy, /* Vector # 832 GTM_TOM2_IRQ[3] gtm_icm.gtm_tom2_irq[3] */
    &dummy, /* Vector # 833 GTM_TOM2_IRQ[4] gtm_icm.gtm_tom2_irq[4] */
    &dummy, /* Vector # 834 GTM_TOM2_IRQ[5] gtm_icm.gtm_tom2_irq[5] */
    &dummy, /* Vector # 835 GTM_TOM2_IRQ[6] gtm_icm.gtm_tom2_irq[6] */
    &dummy, /* Vector # 836 GTM_TOM2_IRQ[7] gtm_icm.gtm_tom2_irq[7] */
    &dummy, /* Vector # 837 GTM_ATOM0_IRQ[0] gtm_icm.gtm_atom0_irq[0] */
    &dummy, /* Vector # 838 GTM_ATOM0_IRQ[1] gtm_icm.gtm_atom0_irq[1] */
    &dummy, /* Vector # 839 GTM_ATOM0_IRQ[2] gtm_icm.gtm_atom0_irq[2] */
    &dummy, /* Vector # 840 GTM_ATOM0_IRQ[3] gtm_icm.gtm_atom0_irq[3] */
    &dummy, /* Vector # 841 GTM_ATOM1_IRQ[0] gtm_icm.gtm_atom1_irq[0] */
    &dummy, /* Vector # 842 GTM_ATOM1_IRQ[1] gtm_icm.gtm_atom1_irq[1] */
    &dummy, /* Vector # 843 GTM_ATOM1_IRQ[2] gtm_icm.gtm_atom1_irq[2] */
    &dummy, /* Vector # 844 GTM_ATOM1_IRQ[3] gtm_icm.gtm_atom1_irq[3] */
    &dummy, /* Vector # 845 GTM_ATOM2_IRQ[0] gtm_icm.gtm_atom2_irq[0] */
    &dummy, /* Vector # 846 GTM_ATOM2_IRQ[1] gtm_icm.gtm_atom2_irq[1] */
    &dummy, /* Vector # 847 GTM_ATOM2_IRQ[2] gtm_icm.gtm_atom2_irq[2] */
    &dummy, /* Vector # 848 GTM_ATOM2_IRQ[3] gtm_icm.gtm_atom2_irq[3] */
    &dummy, /* Vector # 849 GTM_ATOM3_IRQ[0] gtm_icm.gtm_atom3_irq[0] */
    &dummy, /* Vector # 850 GTM_ATOM3_IRQ[1] gtm_icm.gtm_atom3_irq[1] */
    &dummy, /* Vector # 851 GTM_ATOM3_IRQ[2] gtm_icm.gtm_atom3_irq[2] */
    &dummy, /* Vector # 852 GTM_ATOM3_IRQ[3] gtm_icm.gtm_atom3_irq[3] */
    &dummy, /* Vector # 853 GTM_ATOM4_IRQ[0] gtm_icm.gtm_atom4_irq[0] */
    &dummy, /* Vector # 854 GTM_ATOM4_IRQ[1] gtm_icm.gtm_atom4_irq[1] */
    &dummy, /* Vector # 855 GTM_ATOM4_IRQ[2] gtm_icm.gtm_atom4_irq[2] */
    &dummy, /* Vector # 856 GTM_ATOM4_IRQ[3] gtm_icm.gtm_atom4_irq[3] */
    &dummy, /* Vector # 857 GTM_SPE2_IRQ gtm_icm.gtm_spe2_irq */
    &dummy, /* Vector # 858 GTM_SPE3_IRQ gtm_icm.gtm_spe3_irq */
    &dummy, /* Vector # 859 GTM_PSM1_IRQ[0] gtm_icm.gtm_psm1_irq[0] */
    &dummy, /* Vector # 860 GTM_PSM1_IRQ[1] gtm_icm.gtm_psm1_irq[1] */
    &dummy, /* Vector # 861 GTM_PSM1_IRQ[2] gtm_icm.gtm_psm1_irq[2] */
    &dummy, /* Vector # 862 GTM_PSM1_IRQ[3] gtm_icm.gtm_psm1_irq[3] */
    &dummy, /* Vector # 863 GTM_PSM1_IRQ[4] gtm_icm.gtm_psm1_irq[4] */
    &dummy, /* Vector # 864 GTM_PSM1_IRQ[5] gtm_icm.gtm_psm1_irq[5] */
    &dummy, /* Vector # 865 GTM_PSM1_IRQ[6] gtm_icm.gtm_psm1_irq[6] */
    &dummy, /* Vector # 866 GTM_PSM1_IRQ[7] gtm_icm.gtm_psm1_irq[7] */
    &dummy, /* Vector # 867 GTM_TIM4_IRQ[0] gtm_icm.gtm_tim4_irq[0] */
    &dummy, /* Vector # 868 GTM_TIM4_IRQ[1] gtm_icm.gtm_tim4_irq[1] */
    &dummy, /* Vector # 869 GTM_TIM4_IRQ[2] gtm_icm.gtm_tim4_irq[2] */
    &dummy, /* Vector # 870 GTM_TIM4_IRQ[3] gtm_icm.gtm_tim4_irq[3] */
    &dummy, /* Vector # 871 GTM_TIM4_IRQ[4] gtm_icm.gtm_tim4_irq[4] */
    &dummy, /* Vector # 872 GTM_TIM4_IRQ[5] gtm_icm.gtm_tim4_irq[5] */
    &dummy, /* Vector # 873 GTM_TIM4_IRQ[6] gtm_icm.gtm_tim4_irq[6] */
    &dummy, /* Vector # 874 GTM_TIM4_IRQ[7] gtm_icm.gtm_tim4_irq[7] */
    &dummy, /* Vector # 875 GTM_TIM5_IRQ[0] gtm_icm.gtm_tim5_irq[0] */
    &dummy, /* Vector # 876 GTM_TIM5_IRQ[1] gtm_icm.gtm_tim5_irq[1] */
    &dummy, /* Vector # 877 GTM_TIM5_IRQ[2] gtm_icm.gtm_tim5_irq[2] */
    &dummy, /* Vector # 878 GTM_TIM5_IRQ[3] gtm_icm.gtm_tim5_irq[3] */
    &dummy, /* Vector # 879 GTM_TIM5_IRQ[4] gtm_icm.gtm_tim5_irq[4] */
    &dummy, /* Vector # 880 GTM_TIM5_IRQ[5] gtm_icm.gtm_tim5_irq[5] */
    &dummy, /* Vector # 881 GTM_TIM5_IRQ[6] gtm_icm.gtm_tim5_irq[6] */
    &dummy, /* Vector # 882 GTM_TIM5_IRQ[7] gtm_icm.gtm_tim5_irq[7] */
    &dummy, /* Vector # 883 GTM_MCS4_IRQ[0] gtm_icm.gtm_mcs4_irq[0] */
    &dummy, /* Vector # 884 GTM_MCS4_IRQ[1] gtm_icm.gtm_mcs4_irq[1] */
    &dummy, /* Vector # 885 GTM_MCS4_IRQ[2] gtm_icm.gtm_mcs4_irq[2] */
    &dummy, /* Vector # 886 GTM_MCS4_IRQ[3] gtm_icm.gtm_mcs4_irq[3] */
    &dummy, /* Vector # 887 GTM_MCS4_IRQ[4] gtm_icm.gtm_mcs4_irq[4] */
    &dummy, /* Vector # 888 GTM_MCS4_IRQ[5] gtm_icm.gtm_mcs4_irq[5] */
    &dummy, /* Vector # 889 GTM_MCS4_IRQ[6] gtm_icm.gtm_mcs4_irq[6] */
    &dummy, /* Vector # 890 GTM_MCS4_IRQ[7] gtm_icm.gtm_mcs4_irq[7] */
    &dummy, /* Vector # 891 GTM_MCS5_IRQ[0] gtm_icm.gtm_mcs5_irq[0] */
    &dummy, /* Vector # 892 GTM_MCS5_IRQ[1] gtm_icm.gtm_mcs5_irq[1] */
    &dummy, /* Vector # 893 GTM_MCS5_IRQ[2] gtm_icm.gtm_mcs5_irq[2] */
    &dummy, /* Vector # 894 GTM_MCS5_IRQ[3] gtm_icm.gtm_mcs5_irq[3] */
    &dummy, /* Vector # 895 GTM_MCS5_IRQ[4] gtm_icm.gtm_mcs5_irq[4] */
    &dummy, /* Vector # 896 GTM_MCS5_IRQ[5] gtm_icm.gtm_mcs5_irq[5] */
    &dummy, /* Vector # 897 GTM_MCS5_IRQ[6] gtm_icm.gtm_mcs5_irq[6] */
    &dummy, /* Vector # 898 GTM_MCS5_IRQ[7] gtm_icm.gtm_mcs5_irq[7] */
    &dummy, /* Vector # 899 GTM_TOM3_IRQ[0] gtm_icm.gtm_tom3_irq[0] */
    &dummy, /* Vector # 900 GTM_TOM3_IRQ[1] gtm_icm.gtm_tom3_irq[1] */
    
    &dummy, /* Vector # 901 GTM_TOM3_IRQ[2] gtm_icm.gtm_tom3_irq[2] */
    &dummy, /* Vector # 902 GTM_TOM3_IRQ[3] gtm_icm.gtm_tom3_irq[3] */
    &dummy, /* Vector # 903 GTM_TOM3_IRQ[4] gtm_icm.gtm_tom3_irq[4] */
    &dummy, /* Vector # 904 GTM_TOM3_IRQ[5] gtm_icm.gtm_tom3_irq[5] */
    &dummy, /* Vector # 905 GTM_TOM3_IRQ[6] gtm_icm.gtm_tom3_irq[6] */
    &dummy, /* Vector # 906 GTM_TOM3_IRQ[7] gtm_icm.gtm_tom3_irq[7] */
    &dummy, /* Vector # 907 GTM_TOM4_IRQ[0] gtm_icm.gtm_tom4_irq[0] */
    &dummy, /* Vector # 908 GTM_TOM4_IRQ[1] gtm_icm.gtm_tom4_irq[1] */
    &dummy, /* Vector # 909 GTM_TOM4_IRQ[2] gtm_icm.gtm_tom4_irq[2] */
    &dummy, /* Vector # 910 GTM_TOM4_IRQ[3] gtm_icm.gtm_tom4_irq[3] */
    &dummy, /* Vector # 911 GTM_TOM4_IRQ[4] gtm_icm.gtm_tom4_irq[4] */
    &dummy, /* Vector # 912 GTM_TOM4_IRQ[5] gtm_icm.gtm_tom4_irq[5] */
    &dummy, /* Vector # 913 GTM_TOM4_IRQ[6] gtm_icm.gtm_tom4_irq[6] */
    &dummy, /* Vector # 914 GTM_TOM4_IRQ[7] gtm_icm.gtm_tom4_irq[7] */
    &dummy, /* Vector # 915 GTM_ATOM5_IRQ[0] gtm_icm.gtm_atom5_irq[0] */
    &dummy, /* Vector # 916 GTM_ATOM5_IRQ[1] gtm_icm.gtm_atom5_irq[1] */
    &dummy, /* Vector # 917 GTM_ATOM5_IRQ[2] gtm_icm.gtm_atom5_irq[2] */
    &dummy, /* Vector # 918 GTM_ATOM5_IRQ[3] gtm_icm.gtm_atom5_irq[3] */
    &dummy, /* Vector # 919 GTM_ATOM6_IRQ[0] gtm_icm.gtm_atom6_irq[0] */
    &dummy, /* Vector # 920 GTM_ATOM6_IRQ[1] gtm_icm.gtm_atom6_irq[1] */
    &dummy, /* Vector # 921 GTM_ATOM6_IRQ[2] gtm_icm.gtm_atom6_irq[2] */
    &dummy, /* Vector # 922 GTM_ATOM6_IRQ[3] gtm_icm.gtm_atom6_irq[3] */
    &dummy, /* Vector # 923 GTM_ATOM7_IRQ[0] gtm_icm.gtm_atom7_irq[0] */
    &dummy, /* Vector # 924 GTM_ATOM7_IRQ[1] gtm_icm.gtm_atom7_irq[1] */
    &dummy, /* Vector # 925 GTM_ATOM7_IRQ[2] gtm_icm.gtm_atom7_irq[2] */
    &dummy, /* Vector # 926 GTM_ATOM7_IRQ[3] gtm_icm.gtm_atom7_irq[3] */
    &dummy, /* Vector # 927 GTM_ATOM8_IRQ[0] gtm_icm.gtm_atom8_irq[0] */
    &dummy, /* Vector # 928 GTM_ATOM8_IRQ[1] gtm_icm.gtm_atom8_irq[1] */
    &dummy, /* Vector # 929 GTM_ATOM8_IRQ[2] gtm_icm.gtm_atom8_irq[2] */
    &dummy, /* Vector # 930 GTM_ATOM8_IRQ[3] gtm_icm.gtm_atom8_irq[3] */
    &dummy, /* Vector # 931 GTM_ERR_IRQ gtm_err_irq */
    &dummy, /* Vector # 932 */
    &dummy, /* Vector # 933 */
    &dummy, /* Vector # 934 */
    &dummy, /* Vector # 935 */
    &dummy, /* Vector # 936 */
    &dummy, /* Vector # 937 */
    &dummy, /* Vector # 938 */
    &dummy, /* Vector # 939 */
    &dummy, /* Vector # 940 */
    &dummy, /* Vector # 941 */
    &dummy, /* Vector # 942 */
    &dummy, /* Vector # 943 */
    &dummy, /* Vector # 944 */
    &dummy, /* Vector # 945 */
    &dummy, /* Vector # 946 PS_SR_IRQ[0] PS_MBOX_SR_IRQ[0] */
            /*              PS_ERR_SR_IRQ[0] */
    &dummy, /* Vector # 947 PS_SR_IRQ[1] PS_MBOX_SR_IRQ[1] */
            /*              PS_ERR_SR_IRQ[1] */
    &dummy, /* Vector # 948 PS_SR_IRQ[2] PS_MBOX_SR_IRQ[2] */
            /*              PS_ERR_SR_IRQ[2] */
    &dummy, /* Vector # 949 PS_SR_IRQ[3] PS_MBOX_SR_IRQ[3] */
            /*              PS_ERR_SR_IRQ[3] */
    &dummy, /* Vector # 950 PS_SR_IRQ[4] PS_MBOX_SR_IRQ[4] */
            /*              PS_ERR_SR_IRQ[4] */
    &dummy, /* Vector # 951 PS_SR_IRQ[5] PS_MBOX_SR_IRQ[5] */
            /*              PS_ERR_SR_IRQ[5] */
    &dummy, /* Vector # 952 PS_SR_IRQ[6] PS_MBOX_SR_IRQ[6] */
            /*              PS_ERR_SR_IRQ[6] */
    &dummy, /* Vector # 953 PS_SR_IRQ[7] PS_MBOX_SR_IRQ[7] */
            /*              PS_ERR_SR_IRQ[7] */
    &dummy, /* Vector # 954 PSI5_E2SSR[1] PSI5_E2SSR[1] */
    &dummy, /* Vector # 955 PSI5_E2SSR[2] PSI5_E2SSR[2] */
    &dummy, /* Vector # 956 PSI5_E2SSR[3] PSI5_E2SSR[3] */
    &dummy, /* Vector # 957 PSI5_E2SSR[4] PSI5_E2SSR[4] */
    &dummy, /* Vector # 958 PSI5_E2SSR[5] PSI5_E2SSR[5] */
    &dummy, /* Vector # 959 PSI5_E2SSR[6] PSI5_E2SSR[6] */
    &dummy, /* Vector # 960 PSI5_E2SSR[7] PSI5_E2SSR[7] */
    &dummy, /* Vector # 961 PS_GLSR PS_GLSR */
    &dummy, /* Vector # 962 PSI5_S_0_UART_RX PSI5_S_0_UART_RX */
    &dummy, /* Vector # 963 PSI5_S_0_UART_TX PSI5_S_0_UART_TX */
    &dummy, /* Vector # 964 PSI5_S_0_UART_ERR PSI5_S_0_UART_ERR */
    &dummy, /* Vector # 965 QADC01 ipi_int_adc01_grp0 */
    &dummy, /* Vector # 966 QADC01 ipi_int_adc01_grp1 */
    &dummy, /* Vector # 967 QADC01 ipi_int_adc01_grp2 */
    &dummy, /* Vector # 968 QADC01 ipi_int_adc01_grp3 */
    &dummy, /* Vector # 969 QADC01 ipi_int_adc01_grp4 */
    &dummy, /* Vector # 970 QADC01 ipi_int_adc01_grp5 */
    &dummy, /* Vector # 971 QADC23 ipi_int_adc23_grp0 */
    &dummy, /* Vector # 972 QADC23 ipi_int_adc23_grp1 */
    &dummy, /* Vector # 973 QADC23 ipi_int_adc23_grp2 */
    &dummy, /* Vector # 974 QADC23 ipi_int_adc23_grp3 */
    &dummy, /* Vector # 975 QADC23 ipi_int_adc23_grp4 */
    &dummy, /* Vector # 976 QADC23 ipi_int_adc23_grp5 */
    &dummy, /* Vector # 977 QADC45 ipi_int_adc45_grp0 */
    &dummy, /* Vector # 978 QADC45 ipi_int_adc45_grp1 */
    &dummy, /* Vector # 979 QADC45 ipi_int_adc45_grp2 */
    &dummy, /* Vector # 980 QADC45 ipi_int_adc45_grp3 */
    &dummy, /* Vector # 981 QADC45 ipi_int_adc45_grp4 */
    &dummy, /* Vector # 982 QADC45 ipi_int_adc45_grp5 */
    &dummy, /* Vector # 983 QADC67 ipi_int_adc67_grp0 */
    &dummy, /* Vector # 984 QADC67 ipi_int_adc67_grp1 */
    &dummy, /* Vector # 985 QADC67 ipi_int_adc67_grp2 */
    &dummy, /* Vector # 986 QADC67 ipi_int_adc67_grp3 */
    &dummy, /* Vector # 987 QADC67 ipi_int_adc67_grp4 */
    &dummy, /* Vector # 988 QADC67 ipi_int_adc67_grp5 */
    &dummy, /* Vector # 989 QADC89 ipi_int_adc89_grp0 */
    &dummy, /* Vector # 990 QADC89 ipi_int_adc89_grp1 */
    &dummy, /* Vector # 991 QADC89 ipi_int_adc89_grp2 */
    &dummy, /* Vector # 992 QADC89 ipi_int_adc89_grp3 */
    &dummy, /* Vector # 993 QADC89 ipi_int_adc89_grp4 */
    &dummy, /* Vector # 994 QADC89 ipi_int_adc89_grp5 */
    &dummy, /* Vector # 995 emios0_ch3 emios_flag_out__wire[3] */
    &dummy, /* Vector # 996 emios0_ch4 emios_flag_out__wire[4] */
    &dummy, /* Vector # 997 emios0_ch5 emios_flag_out__wire[5] */
    &dummy, /* Vector # 998 emios0_ch6 emios_flag_out__wire[6] */
    &dummy, /* Vector # 999 emios0_ch7 emios_flag_out__wire[7] */
    &dummy, /* Vector # 1000 emios0_ch8 emios_flag_out__wire[8] */
    &dummy, /* Vector # 1001 emios0_ch9 emios_flag_out__wire[9] */
    &dummy, /* Vector # 1002 emios0_ch10 emios_flag_out__wire[10] */
    &dummy, /* Vector # 1003 emios0_ch11 emios_flag_out__wire[11] */
    &dummy, /* Vector # 1004 emios0_ch12 emios_flag_out__wire[12] */
    &dummy, /* Vector # 1005 emios0_ch13 emios_flag_out__wire[13] */
    &dummy, /* Vector # 1006 emios0_ch14 emios_flag_out__wire[14] */
    &dummy, /* Vector # 1007 emios0_ch15 emios_flag_out__wire[15] */
    &dummy, /* Vector # 1008 emios0_ch16 emios_flag_out__wire[16] */
    &dummy, /* Vector # 1009 emios0_ch17 emios_flag_out__wire[17] */
    &dummy, /* Vector # 1010 emios0_ch18 emios_flag_out__wire[18] */
    &dummy, /* Vector # 1011 emios0_ch19 emios_flag_out__wire[19] */
    &dummy, /* Vector # 1012 emios0_ch20 emios_flag_out__wire[20] */
    &dummy, /* Vector # 1013 emios0_ch21 emios_flag_out__wire[21] */
    &dummy, /* Vector # 1014 emios0_ch22 emios_flag_out__wire[22] */
    &dummy, /* Vector # 1015 emios0_ch23 emios_flag_out__wire[23] */
    &dummy, /* Vector # 1016 emios0_ch24 emios_flag_out__wire[24] */
    &dummy, /* Vector # 1017 emios0_ch25 emios_flag_out__wire[25] */
    &dummy, /* Vector # 1018 emios0_ch26 emios_flag_out__wire[26] */
    &dummy, /* Vector # 1019 emios0_ch27 emios_flag_out__wire[27] */
    &dummy, /* Vector # 1020 emios0_ch28 emios_flag_out__wire[28] */
    &dummy, /* Vector # 1021 emios0_ch29 emios_flag_out__wire[29] */
    &dummy, /* Vector # 1022 emios0_ch30 emios_flag_out__wire[30] */
    &dummy, /* Vector # 1023 emios0_ch31 emios_flag_out__wire[31] */
};

void dummy (void) /* PRQA S 1505 */
{   /* Dummy ISR vector to trap undefined ISRs */
    while (1) {};  /* Wait forever or for watchdog timeout */ /* PRQA S 2880 */
}

/*******************************************************************************
 * @brief      Critical Input Interrupt
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR0_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
//    NMI_CriticalInt_Ivor0Handler();
    while (1) {}
}

/*******************************************************************************
 * @brief      Machine Check Interrupt
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR1_Exception_Handler(void) /* PRQA S 3006, 3408, 1503, 1505 */
{
    uint32_t temp = 0U;
#ifdef SAFETY_ENABLE
    uint32_t fccu_flag = 0U;
    uint32_t inject_fault = 0U;
#endif
    /* Clears error flags from MSCR */
    temp = MFSPR(572); /* PRQA S 1006, 2983 # write clear */
    MTSPR(572, temp); /* PRQA S 1006 */
#ifdef SAFETY_ENABLE
    fccu_flag = FCCU_IVOR_Handler();
    (void)fccu_flag;
    inject_fault = FCCU_StartInject_Check();
    extern uint32_t mpuTestFlag;
    if (inject_fault == 1 || mpuTestFlag == 1u)
    {

    }
    else
    {
    	while (1) {}
    }
#endif

#ifdef FUNC_SAFETY
    SAF_MPU_IvorHandler();
#endif
//    SMPU_handler();
//    CMPU_handler();
//    NMI_NonMaskableInt_Ivor1Handler();
//    NMI_MachineCheckReq_Ivor1Handler();
}

/*******************************************************************************
 * @brief      Data Storage Interrupt 
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR2_Exception_Handler(void) /* PRQA S 3006, 3408, 1503, 1505 */
{
    uint32_t temp = 0U;
#ifdef SAFETY_ENABLE
    uint32_t fccu_flag = 0U;
    uint32_t inject_fault = 0U;
#endif
    /* Clears error flags from MSCR */
    temp = MFSPR(572); /* PRQA S 1006, 2983 # write clear */
    MTSPR(572, temp); /* PRQA S 1006 */
#ifdef SAFETY_ENABLE
    fccu_flag = FCCU_IVOR_Handler();
    (void)fccu_flag;
    inject_fault = FCCU_StartInject_Check();
    extern uint32_t mpuTestFlag;
    if (inject_fault == 1 || mpuTestFlag == 1u)
    {

    }
    else
    {
    	while (1) {}
    }
#endif

#ifdef FUNC_SAFETY
    SAF_MPU_IvorHandler();
#endif

//    SMPU_handler();
//    CMPU_handler();
}

/*******************************************************************************
 * @brief      Instruction Storage Interrupt
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR3_Exception_Handler(void) /* PRQA S 3006, 3408, 1503, 1505 */
{
    uint32_t temp = 0U;
#ifdef SAFETY_ENABLE
    uint32_t fccu_flag = 0U;
    uint32_t inject_fault = 0U;
#endif
    /* Clears error flags from MSCR */
    temp = MFSPR(572); /* PRQA S 1006, 2983 # write clear */
    MTSPR(572, temp); /* PRQA S 1006 */
#ifdef SAFETY_ENABLE
    fccu_flag = FCCU_IVOR_Handler();
    (void)fccu_flag;
    inject_fault = FCCU_StartInject_Check();
    extern uint32_t mpuTestFlag;
    if (inject_fault == 1 || mpuTestFlag == 1u)
    {

    }
    else
    {
    	while (1) {}
    }
#endif

#ifdef FUNC_SAFETY
    SAF_MPU_IvorHandler();
#endif

//    SMPU_handler();
//    CMPU_handler();
}

/*******************************************************************************
 * @brief      Alignment Interrupt
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR5_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}

/*******************************************************************************
 * @brief      Program Interrupt
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR6_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}

/*******************************************************************************
 * @brief      Performance Monitor Interrupt
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR7_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}

/*******************************************************************************
 * @brief      System Call Interrupt
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR8_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}

/*******************************************************************************
 * @brief      Embedded Floating-point Data Interrupt
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR10_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}

/*******************************************************************************
 * @brief      Embedded Floating-point Round Interrupt
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void IVOR11_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}
void IVOR12_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}
void IVOR13_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}
void IVOR14_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}
void IVOR15_Exception_Handler(void) /* PRQA S 3408, 1503, 1505 */
{
    while (1) {}; /* PRQA S 2880 */
}

