/*******************************************************************************
File Name:  Pwm3ph.c
Author:
Date:
Version:    V1.1
File Description:
Copyright:
            Copyright(C)    2022-2025
            All rights reserved
*******************************************************************************/

/******************************************************************************
*@fileDescription:     This is a c source file for PWM moudle.
*******************************************************************************/

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Pwm3ph.h"
#include "Pwm_LLDriver.h"




#pragma ghs section data =".foc_data"
// #pragma ghs section text =".foc_code"
#pragma ghs section bss =".foc_bss"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/




/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

const GTM_TOUT_MUX_t GTM_TOUT_MUX[] = {
            {0   ,    9     ,    32  },     // PC[0]
            {1   ,    8     ,    33  },     // PC[1]
            {2   ,    6     ,    34  },     // PC[2]
            {3   ,    11    ,    35  },     // PC[3]
            {4   ,    11    ,    36  },     // PC[4]
            {5   ,    10    ,    37  },     // PC[5]
            {6   ,    13    ,    38  },     // PC[6]
            {7   ,    13    ,    39  },     // PC[7]
            {8   ,    13    ,    40  },     // PC[8]
            {9   ,    8     ,    0   },     // PA[0]
            {10  ,    14    ,    1   },     // PA[1]
            {11  ,    8     ,    2   },     // PA[2]
            {12  ,    14    ,    3   },     // PA[3]
            {13  ,    13    ,    4   },     // PA[4]
            {14  ,    12    ,    5   },     // PA[5]
            {15  ,    11    ,    6   },     // PA[6]
            {16  ,    12    ,    7   },     // PA[7]
            {17  ,    13    ,    8   },     // PA[8]
            {18  ,    13    ,    9   },     // PA[9]
            {19  ,    7     ,    10  },     // PA[10]
            {20  ,    9     ,    11  },     // PA[11]
            {21  ,    10    ,    12  },     // PA[12]
            {22  ,    8     ,    241 },     // PP[1]
            {23  ,    11    ,    242 },     // PP[2]
            {24  ,    8     ,    243 },     // PP[3]
            {25  ,    8     ,    244 },     // PP[4]
            {26  ,    11    ,    245 },     // PP[5]
            {27  ,    13    ,    246 },     // PP[6]
            {28  ,    11    ,    247 },     // PP[7]
            {29  ,    8     ,    248 },     // PP[8]
            {30  ,    6     ,    249 },     // PP[9]
            {31  ,    4     ,    250 },     // PP[10]
            {32  ,    9     ,    251 },     // PP[11]
            {33  ,    4     ,    252 },     // PP[12]
            {34  ,    6     ,    253 },     // PP[13]
            {35  ,    9     ,    254 },     // PP[14]
            {36  ,    3     ,    233 },     // PO[9]
            {37  ,    2     ,    234 },     // PO[10]
            {38  ,    7     ,    235 },     // PO[11]
            {39  ,    3     ,    236 },     // PO[12]
            {40  ,    5     ,    237 },     // PO[13]
            {41  ,    5     ,    160 },     // PK[0]           {41  ,    5     ,    160 },
            {42  ,    7     ,    161 },     // PK[1]
            {43  ,    6     ,    162 },     // PK[2]
            {44  ,    9     ,    163 },     // PK[3]
            {45  ,    4     ,    164 },     // PK[4]
            {46  ,    4     ,    165 },     // PK[5]           {46  ,    4     ,    165 },
            {47  ,    7     ,    148 },     // PJ[4]           {47  ,    7     ,    148 },
            {48  ,    7     ,    149 },     // PJ[5]
            {49  ,    5     ,    150 },     // PJ[6]
            {50  ,    7     ,    151 },     // PJ[7]
            {51  ,    9     ,    140 },     // PI[12]
            {52  ,    9     ,    141 },     // PI[13]
            {53  ,    12    ,    142 },     // PI[14]
            {54  ,    9     ,    143 },     // PI[15]
            {55  ,    4     ,    144 },     // PJ[0]
            {56  ,    6     ,    145 },     // PJ[1]
            {57  ,    9     ,    146 },     // PJ[2]
            {58  ,    7     ,    147 },     // PJ[3]
            {59  ,    10    ,    127 },     // PH[15]
            {60  ,    6     ,    128 },     // PI[0]
            {61  ,    7     ,    130 },     // PI[2]
            {62  ,    7     ,    131 },     // PI[3]
            {63  ,    10    ,    132 },     // PI[4]
            {64  ,    5     ,    133 },     // PI[5]
            {65  ,    9     ,    134 },     // PI[6]
            {66  ,    4     ,    135 },     // PI[7]
            {67  ,    5     ,    136 },     // PI[8]
            {68  ,    5     ,    137 },     // PI[9]
            {69  ,    5     ,    138 },     // PI[10]
            {70  ,    5     ,    139 },     // PI[11]
            {71  ,    4     ,    112 },     // PH[0]
            {72  ,    8     ,    113 },     // PH[1]
            {73  ,    7     ,    114 },     // PH[2]
            {74  ,    9     ,    115 },     // PH[3]
            {75  ,    7     ,    116 },     // PH[4]
            {76  ,    8     ,    117 },     // PH[5]
            {77  ,    5     ,    118 },     // PH[6]
            {78  ,    6     ,    119 },     // PH[7]
            {79  ,    5     ,    120 },     // PH[8]
            {80  ,    4     ,    96  },     // PG[0]
            {81  ,    11    ,    97  },     // PG[1]
            {82  ,    4     ,    98  },     // PG[2]
            {83  ,    8     ,    99  },     // PG[3]
            {84  ,    5     ,    100 },     // PG[4]
            {85  ,    6     ,    101 },     // PG[5]
            {86  ,    4     ,    102 },     // PG[6]
            {87  ,    10    ,    103 },     // PG[7]
            {88  ,    8     ,    104 },     // PG[8]
            {89  ,    7     ,    105 },     // PG[9]
            {90  ,    5     ,    106 },     // PG[10]
            {91  ,    5     ,    81  },     // PF[1]
            {92  ,    7     ,    82  },     // PF[2]
            {93  ,    5     ,    83  },     // PF[3]
            {94  ,    3     ,    84  },     // PF[4]
            {95  ,    3     ,    65  },     // PE[1]
            {96  ,    5     ,    66  },     // PE[2]
            {97  ,    4     ,    69  },     // PE[5]
            {98  ,    6     ,    72  },     // PE[8]
            {99  ,    12    ,    73  },     // PE[9]
            {100 ,    8     ,    74  },     // PE[10]
            {101 ,    6     ,    75  },     // PE[11]
            {102 ,    9     ,    48  },     // PD[0]
            {103 ,    7     ,    49  },     // PD[1]
            {104 ,    10    ,    50  },     // PD[2]
            {105 ,    7     ,    51  },     // PD[3]
            {106 ,    9     ,    52  },     // PD[4]
            {107 ,    7     ,    53  },     // PD[5]
            {108 ,    9     ,    54  },     // PD[6]
            {109 ,    8     ,    55  },     // PD[7]
            {110 ,    11    ,    56  },     // PD[8]
            {111 ,    6     ,    19  },     // PB[3]
            {112 ,    6     ,    20  },     // PB[4]
            {113 ,    8     ,    21  },     // PB[5]
            {114 ,    6     ,    22  },     // PB[6]
            {115 ,    7     ,    23  },     // PB[7]
            {116 ,    7     ,    41  },     // PC[9]
            {117 ,    10    ,    42  },     // PC[10]
            {118 ,    5     ,    43  },     // PC[11]
            {119 ,    7     ,    63  },     // PD[15]
            {120 ,    4     ,    64  },     // PE[0]
            {121 ,    5     ,    67  },     // PE[3]
            {122 ,    5     ,    68  },     // PE[4]
            {123 ,    5     ,    70  },     // PE[6]
            {124 ,    5     ,    71  },     // PE[7]
            {125 ,    6     ,    76  },     // PE[12]
            {126 ,    8     ,    77  },     // PE[13]
            {127 ,    4     ,    78  },     // PE[14]
            {128 ,    7     ,    79  },     // PE[15]
            {129 ,    5     ,    80  },     // PF[0]
            {130 ,    5     ,    152 },     // PJ[8]
            {131 ,    4     ,    153 },     // PJ[9]
            {132 ,    6     ,    154 },     // PJ[10]
            {133 ,    4     ,    155 },     // PJ[11]
            {134 ,    4     ,    156 },     // PJ[12]
            {135 ,    8     ,    157 },     // PJ[13]
            {136 ,    4     ,    158 },     // PJ[14]
            {137 ,    4     ,    159 },     // PJ[15]
            {138 ,    5     ,    166 },     // PK[6]
            {139 ,    5     ,    167 },     // PK[7]
            {140 ,    5     ,    238 },     // PO[14]
            {141 ,    11    ,    239 },     // PO[15]
            {142 ,    7     ,    240 },     // PP[0]
            {143 ,    6     ,    255 },     // PP[15]
            {144 ,    5     ,    256 },     // PQ[0]
            {146 ,    4     ,    257 },     // PQ[1]
            {147 ,    8     ,    258 },     // PQ[2]
            {148 ,    4     ,    259 },     // PQ[3]
            {149 ,    5     ,    260 },     // PQ[4]
            {150 ,    7     ,    261 },     // PQ[5]
            {151 ,    7     ,    44  },     // PC[12]
            {152 ,    6     ,    47  },     // PC[15]
            {153 ,    7     ,    45  },     // PC[13]
            {154 ,    8     ,    46  },     // PC[14]
            {155 ,    9     ,    16  },     // PB[0]
            {156 ,    4     ,    18  },     // PB[2]
            {157 ,    7     ,    31  },     // PB[15]
            {158 ,    6     ,    28  },     // PB[12]
            {159 ,    6     ,    17  },     // PB[1]
            {160 ,    6     ,    25  },     // PB[9]
            {161 ,    6     ,    29  },     // PB[13]
            {162 ,    13    ,    24  },     // PB[8]
            {163 ,    9     ,    26  },     // PB[10]
            {164 ,    6     ,    30  },     // PB[14]
            {165 ,    9     ,    27  },     // PB[11]
            {166 ,    5     ,    14  },     // PA[14]
            {167 ,    5     ,    13  },     // PA[13]
            {168 ,    5     ,    15  },     // PA[15]
            {174 ,    4     ,    217 },     // PN[9]
            {175 ,    4     ,    218 },     // PN[10]
            {176 ,    4     ,    219 },     // PN[11]
            {177 ,    4     ,    220 },     // PN[12]
            {178 ,    4     ,    221 },     // PN[13]
            {179 ,    4     ,    222 },     // PN[14]
            {180 ,    4     ,    223 },     // PN[15]
            {181 ,    4     ,    224 },     // PO[0]
            {182 ,    5     ,    225 },     // PO[1]
            {183 ,    5     ,    226 },     // PO[2]
            {184 ,    5     ,    227 },     // PO[3]
            {185 ,    5     ,    228 },     // PO[4]
            {186 ,    5     ,    229 },     // PO[5]
            {187 ,    4     ,    230 },     // PO[6]
            {188 ,    4     ,    231 },     // PO[7]
            {189 ,    4     ,    232 },     // PO[8]
            {190 ,    4     ,    201 },     // PM[9]
            {191 ,    4     ,    202 },     // PM[10]
            {192 ,    4     ,    203 },     // PM[11]
            {193 ,    4     ,    204 },     // PM[12]
            {194 ,    4     ,    205 },     // PM[13]
            {195 ,    4     ,    206 },     // PM[14]
            {196 ,    4     ,    207 },     // PM[15]
            {197 ,    4     ,    208 },     // PN[0]
            {198 ,    4     ,    209 },     // PN[1]
            {199 ,    4     ,    210 },     // PN[2]
            {200 ,    4     ,    211 },     // PN[3]
            {201 ,    4     ,    212 },     // PN[4]
            {202 ,    4     ,    213 },     // PN[5]
            {203 ,    4     ,    214 },     // PN[6]
            {204 ,    4     ,    215 },     // PN[7]
            {205 ,    4     ,    216 },     // PN[8]
            {206 ,    3     ,    184 },     // PL[8]
            {207 ,    4     ,    185 },     // PL[9]
            {208 ,    4     ,    186 },     // PL[10]
            {209 ,    4     ,    187 },     // PL[11]
            {210 ,    4     ,    188 },     // PL[12]
            {211 ,    4     ,    189 },     // PL[13]
            {212 ,    4     ,    190 },     // PL[14]
            {212 ,    4     ,    200 },     // PM[8]
            {213 ,    4     ,    191 },     // PL[15]
            {214 ,    3     ,    192 },     // PM[0]
            {215 ,    3     ,    193 },     // PM[1]
            {216 ,    3     ,    194 },     // PM[2]
            {217 ,    3     ,    195 },     // PM[3]
            {218 ,    3     ,    196 },     // PM[4]
            {219 ,    3     ,    197 },     // PM[5]
            {220 ,    3     ,    198 },     // PM[6]
            {221 ,    2     ,    199 },     // PM[7]
            {222 ,    4     ,    168 },     // PK[8]
            {223 ,    4     ,    169 },     // PK[9]
            {224 ,    4     ,    170 },     // PK[10]
            {225 ,    4     ,    171 },     // PK[11]
            {226 ,    4     ,    172 },     // PK[12]
            {227 ,    4     ,    173 },     // PK[13]
            {228 ,    4     ,    174 },     // PK[14]
            {229 ,    4     ,    175 },     // PK[15]
            {230 ,    4     ,    176 },     // PL[0]
            {231 ,    4     ,    177 },     // PL[1]
            {232 ,    4     ,    178 },     // PL[2]
            {233 ,    4     ,    179 },     // PL[3]
            {234 ,    4     ,    180 },     // PL[4]
            {235 ,    4     ,    181 },     // PL[5]
            {236 ,    5     ,    182 },     // PL[6]
            {237 ,    4     ,    183 },     // PL[7]
            {242 ,    5     ,    121 },     // PH[9]
            {243 ,    5     ,    122 },     // PH[10]
            {244 ,    4     ,    123 },     // PH[11]
            {245 ,    4     ,    124 },     // PH[12]
            {246 ,    5     ,    125 },     // PH[13]
            {247 ,    5     ,    126 },     // PH[14]
            {248 ,    5     ,    89  },     // PF[9]
            {249 ,    8     ,    92  },     // PF[12]
            {250 ,    9     ,    91  },     // PF[11]
            {251 ,    6     ,    90  },     // PF[10]
            {252 ,    4     ,    94  },     // PF[14]
            {253 ,    4     ,    85  },     // PF[5]
            {254 ,    5     ,    86  },     // PF[6]
            {255 ,    4     ,    87  },     // PF[7]
            {256 ,    4     ,    88  },     // PF[8]
            {258 ,    5     ,    107 },     // PG[11]
            {259 ,    5     ,    110 },     // PG[14]
            {260 ,    5     ,    109 },     // PG[13]
            {261 ,    5     ,    108 },     // PG[12]
            {262 ,    6     ,    93  },     // PF[13]
            {263 ,    11    ,    111 },     // PG[15]
            {264 ,    4     ,    95  },     // PF[15]
            {265 ,    7     ,    57  },     // PD[9]
            {266 ,    5     ,    58  },     // PD[10]
            {267 ,    5     ,    61  },     // PD[13]
            {268 ,    5     ,    60  },     // PD[12]
            {269 ,    5     ,    59  },     // PD[11]
            {270 ,    4     ,    62  },     // PD[14]

            {0x5a5a,  0     ,    0   },
};

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/



// float dutyU = 0.3f;
// float dutyV = 0.3f;
// float dutyW = 0.3f;

Pwm3ph_Dev_t Dev1;                                  /*PWM设备实例*/
Pwm3ph_ConfigType g_PwmConfig = {20000, 10000, 10000, false};      /*PWM配置结构体 默认10k*/


/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
void Pwm3ph_SetPwmAtomCfg(void);
uint8_t Pwm3ph_SetPwmDuty(float32_t duty1, float32_t duty2, float32_t duty3);
uint8_t Pwm3ph_SetPwmFreq(uint32_t freq);
uint32_t Pwm3ph_GetPwmFreq(void);
void Pwm3ph_SetPwmState(Pwm3ph_Dev_t * pwmDev, uint8_t stateCmd);
void Pwm3ph_SetHasc(Pwm3ph_Dev_t * pwmDev);
void Pwm3ph_SetLasc(Pwm3ph_Dev_t * pwmDev);
void Pwm3ph_SetSpo(Pwm3ph_Dev_t * pwmDev);

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/




/*******************************************************************************
 * <@name>          Pwm3ph_SetPwmAtomCfg
 * <@param>         void
 * <@return>        void
 * <@descr.>        PWM输出ATOM模块初始化配置
 * <@note>            
********************************************************************************/
void Pwm3ph_SetPwmAtomCfg(void)
{
    GTM_ATOM_LLD_HresEn();                                      //can be deleted by creating a PWM with Atom channel

    Pwm3ph_SetPwmTimCfg();

    GTM4.GLS[0].ATOM.CH[6].IRQ_EN.B.CCU0TC_IRQ_EN = 1;          /*使能ATOM0_6通道CCU0中断*/
    GTM4.GLS[0].ATOM.CH[6].IRQ_EN.B.CCU1TC_IRQ_EN = 0;          /*关闭ATOM0_6通道CCU1中断*/
    GTM4.GLS[0].ATOM.CH[6].IRQ_MODE.B.IRQ_MODE = 0;             /*设置ATOM0_6通道中断为电平模式*/



    {
        GTM4.GLS[0].ARCH.CTRL.B.RF_PROT = 0;
        GTM4.GLS[0].ARCH.CLS_CLK_CFG.B.CLS0_CLK_DIV = 1;
        GTM4.GLS[0].ARCH.CLS_CLK_CFG.B.CLS1_CLK_DIV = 1;
        GTM4.GLS[0].ARCH.CLS_CLK_CFG.B.CLS2_CLK_DIV = 1;
        GTM4.GLS[0].ARCH.CLS_CLK_CFG.B.CLS3_CLK_DIV = 1;
        GTM4.GLS[0].ARCH.CLS_CLK_CFG.B.CLS4_CLK_DIV = 1;
        GTM4.GLS[0].ARCH.CLS_CLK_CFG.B.CLS5_CLK_DIV = 1;
        GTM4.GLS[0].ARCH.CLS_CLK_CFG.B.CLS6_CLK_DIV = 1;
        GTM4.GLS[0].ARCH.CLS_CLK_CFG.B.CLS7_CLK_DIV = 1;
        GTM4.GLS[0].ARCH.CTRL.B.RF_PROT = 1;

        GTM4.GLS[0].GTMINT.GTMMCR.B.MDIS = 0;
    }

    {

        GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[47].TOUT_NUM, 2);                       /* ATOM0 CH1 PJ4, V相上管PWM信号 */
        
        GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[41].TOUT_NUM, 8);                       /* ATOM0 CH1_N PK0, V相下管PWM信号 */

        GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[46].TOUT_NUM, 2);                       /* ATOM0 CH2 PK5, W相上管PWM信号 */

        GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[40].TOUT_NUM, 9);                       /* ATOM0 CH2_N PO13, W相下管PWM信号 */

        GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[49].TOUT_NUM, 2);                       /* ATOM0 CH3 PJ6, U相上管PWM信号 */

        GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[42].TOUT_NUM, 10);                      /* ATOM0 CH3_N PK1, U相下管PWM信号 */

    }

    {
        GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[48].TOUT_NUM, 2);                       /* ATOM0 CH0 PJ5, MASTER触发 */

        GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[50].TOUT_NUM, 2);                       /* ATOM0 CH4 PJ7, ATOM触发信号 */

        GTM_LLD_SetToutSel_lld(GTM_TOUT_MUX[106].TOUT_NUM, 2);                      /* ATOM0 CH6 PD4, ATOM触发信号 */
    }

    {
        GPT_GTM_CMU_LLD_IsEnableClock(0,1);
        GPT_GTM_CMU_LLD_IsEnableClock(1,1);
    }

    {
        GTM4_ATOM0.CH[1].CTRL.B.MODE = 2;                       /* ATOM0_1为PWM输出模式 */
        GTM4_ATOM0.CH[2].CTRL.B.MODE = 2;                       /* ATOM0_2为PWM输出模式 */
        GTM4_ATOM0.CH[3].CTRL.B.MODE = 2;                       /* ATOM0_3为PWM输出模式 */

        GTM4_ATOM0.CH[0].CTRL.B.MODE = 2;                       /* ATOM0_0为PWM输出模式 */
        GTM4_ATOM0.CH[4].CTRL.B.MODE = 2;                       /* ATOM0_4为PWM输出模式 */
        GTM4_ATOM0.CH[6].CTRL.B.MODE = 2;                       /* ATOM0_6为PWM输出模式 */
    	GTM4_ATOM0.CH[5].CTRL.B.MODE = 2;                       /* ATOM0_5为PWM输出模式 */

        GTM4_ATOM0.CH[0].CTRL.B.TRIGOUT = 1;                    /* ATOM0_0为参考通道触发源 */
        GTM4_ATOM0.CH[0].CTRL.B.RST_CCU0 = 0;                   /* 关闭CCU0复位 */

        GTM4_ATOM0.CH[1].CTRL.B.TRIGOUT = 0;                    /* ATOM0_1为从通道 */
        GTM4_ATOM0.CH[1].CTRL.B.RST_CCU0 = 1;                   /* ATOM0_1的CN值跟随上一通道触发信号清零 */

        GTM4_ATOM0.CH[2].CTRL.B.TRIGOUT = 0;                    /* ATOM0_2为从通道 */
        GTM4_ATOM0.CH[2].CTRL.B.RST_CCU0 = 1;                   /* ATOM0_2的CN值跟随上一通道触发信号清零 */

        GTM4_ATOM0.CH[3].CTRL.B.TRIGOUT = 0;                    /* ATOM0_3为从通道 */
        GTM4_ATOM0.CH[3].CTRL.B.RST_CCU0 = 1;                   /* ATOM0_3的CN值跟随上一通道触发信号清零 */

        GTM4_ATOM0.CH[4].CTRL.B.TRIGOUT = 0;                    /* ATOM0_4为从通道 */
        GTM4_ATOM0.CH[4].CTRL.B.RST_CCU0 = 1;                   /* ATOM0_4的CN值跟随上一通道触发信号清零 */

        GTM4_ATOM0.CH[5].CTRL.B.TRIGOUT = 0;                    /* ATOM0_5为从通道 */
        GTM4_ATOM0.CH[5].CTRL.B.RST_CCU0 = 1;                   /* ATOM0_5的CN值跟随上一通道触发信号清零 */

        GTM4_ATOM0.CH[6].CTRL.B.TRIGOUT = 0;                    /* ATOM0_6为从通道 */
        GTM4_ATOM0.CH[6].CTRL.B.RST_CCU0 = 1;                   /* 关闭CCU0复位 */
    }

    {
        GTM4_ATOM0.CH[1].CM0.B.CM0 = PWM3PH_PERIOD_CNT;         /* 设置ATOM0_1的周期及占空比寄存器，V相 */
        GTM4_ATOM0.CH[1].SR0.B.SR0 = PWM3PH_PERIOD_CNT;
        GTM4_ATOM0.CH[1].CM1.B.CM1 = 0u;
        GTM4_ATOM0.CH[1].SR1.B.SR1 = 0u;

        GTM4_ATOM0.CH[2].CM0.B.CM0 = PWM3PH_PERIOD_CNT;         /* 设置ATOM0_2的周期及占空比寄存器，W相 */
        GTM4_ATOM0.CH[2].SR0.B.SR0 = PWM3PH_PERIOD_CNT;
        GTM4_ATOM0.CH[2].CM1.B.CM1 = 0u;
        GTM4_ATOM0.CH[2].SR1.B.SR1 = 0u;

        GTM4_ATOM0.CH[3].CM0.B.CM0 = PWM3PH_PERIOD_CNT;         /* 设置ATOM0_3的周期及占空比寄存器，U相 */
        GTM4_ATOM0.CH[3].SR0.B.SR0 = PWM3PH_PERIOD_CNT;
        GTM4_ATOM0.CH[3].CM1.B.CM1 = 0u;
        GTM4_ATOM0.CH[3].SR1.B.SR1 = 0u;
    }

    {
        GTM4_ATOM0.CH[0].CN0.R = 0;                             /* 设置ATOM0_0的周期及占空比寄存器 */
        GTM4_ATOM0.CH[0].CM1.B.CM1 = PWM3PH_PERIOD_CNT/2;       /*PWM Duty,50%*/
        GTM4_ATOM0.CH[0].CM0.B.CM0 = PWM3PH_PERIOD_CNT;         /*PWM Period 10KHz*/
        GTM4_ATOM0.CH[0].SR1.B.SR1 = PWM3PH_PERIOD_CNT/2;       /*PWM Duty,,50%*/
        GTM4_ATOM0.CH[0].SR0.B.SR0 = PWM3PH_PERIOD_CNT;         /*PWM Period 10KHz*/

        GTM4_ATOM0.CH[4].CN0.R = 0;                             /* 设置ATOM0_4的周期及占空比寄存器 */
        GTM4_ATOM0.CH[4].CM1.B.CM1 = PWM3PH_PERIOD_CNT/2;       /*PWM Duty,50%*/
        GTM4_ATOM0.CH[4].CM0.B.CM0 = PWM3PH_PERIOD_CNT;         /*PWM Period 10KHz*/
        GTM4_ATOM0.CH[4].SR1.B.SR1 = PWM3PH_PERIOD_CNT/2;       /*PWM Duty,50%*/
        GTM4_ATOM0.CH[4].SR0.B.SR0 = PWM3PH_PERIOD_CNT;         /*PWM Period 10KHz*/

        GTM4_ATOM0.CH[6].CN0.R = 0;                             /* 设置ATOM0_6的周期及占空比寄存器 */
        GTM4_ATOM0.CH[6].CM1.B.CM1 = PWM3PH_PERIOD_CNT/2;       /*PWM Duty,50%*/
        GTM4_ATOM0.CH[6].CM0.B.CM0 = PWM3PH_PERIOD_CNT;         /*PWM Period 10KHz*/
        GTM4_ATOM0.CH[6].SR1.B.SR1 = PWM3PH_PERIOD_CNT/2;       /*PWM Duty,50%*/
        GTM4_ATOM0.CH[6].SR0.B.SR0 = PWM3PH_PERIOD_CNT;         /*PWM Period 10KHz*/

    	GTM4_ATOM0.CH[5].CN0.R = 0;                             /* 设置ATOM0_5的周期及占空比寄存器 */
    	GTM4_ATOM0.CH[5].CM1.B.CM1 = PWM3PH_PERIOD_CNT/2;       /*PWM Duty,50%*/
    	GTM4_ATOM0.CH[5].CM0.B.CM0 = PWM3PH_PERIOD_CNT;         /*PWM Period 10KHz*/
    	GTM4_ATOM0.CH[5].SR1.B.SR1 = PWM3PH_PERIOD_CNT/2;       /*PWM Duty,50%*/
    	GTM4_ATOM0.CH[5].SR0.B.SR0 = PWM3PH_PERIOD_CNT;         /*PWM Period 10KHz*/
    }

    {
        GTM4.GLS[0].CDTM.DTM[4].CH_DTV[1].B.RELRISE = PWM3PH_DEADTIME_CNT;          /*ATOM0_1,CDTM0_DTM4_1的RELRISE为3us*/
        GTM4.GLS[0].CDTM.DTM[4].CH_DTV[1].B.RELFALL = PWM3PH_DEADTIME_CNT;          /*ATOM0_1,CDTM0_DTM4_1的RELFALL为3us*/
        GTM4.GLS[0].CDTM.DTM[4].CH_DTV[2].B.RELRISE = PWM3PH_DEADTIME_CNT;          /*ATOM0_2,CDTM0_DTM4_2的RELRISE为3us*/
        GTM4.GLS[0].CDTM.DTM[4].CH_DTV[2].B.RELFALL = PWM3PH_DEADTIME_CNT;          /*ATOM0_2,CDTM0_DTM4_2的RELFALL为3us*/
        GTM4.GLS[0].CDTM.DTM[4].CH_DTV[3].B.RELRISE = PWM3PH_DEADTIME_CNT;          /*ATOM0_3,CDTM0_DTM4_3的RELRISE为3us*/
        GTM4.GLS[0].CDTM.DTM[4].CH_DTV[3].B.RELFALL = PWM3PH_DEADTIME_CNT;          /*ATOM0_3,CDTM0_DTM4_3的RELFALL为3us*/  

        GTM4.GLS[0].CDTM.DTM[4].CH_DTV[0].B.RELRISE = 0;                            /*ATOM0_0,CDTM0_DTM4_0的RELRISE为0us*/
        GTM4.GLS[0].CDTM.DTM[4].CH_DTV[0].B.RELFALL = 0;                            /*ATOM0_0,CDTM0_DTM4_0的RELFALL为0us*/
        GTM4.GLS[0].CDTM.DTM[5].CH_DTV[0].B.RELRISE = 0;                            /*ATOM0_4,CDTM0_DTM5_0的RELRISE为0us*/
        GTM4.GLS[0].CDTM.DTM[5].CH_DTV[0].B.RELFALL = 0;                            /*ATOM0_4,CDTM0_DTM5_0的RELFALL为0us*/
        GTM4.GLS[0].CDTM.DTM[5].CH_DTV[2].B.RELRISE = 0;                            /*ATOM0_6,CDTM0_DTM5_2的RELRISE为0us*/
        GTM4.GLS[0].CDTM.DTM[5].CH_DTV[2].B.RELFALL = 0;                            /*ATOM0_6,CDTM0_DTM5_2的RELFALL为0us*/
    }

    {
        GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.B.DT0_1 = 1u;                              /*ATOM0_1,CDTM0_DTM4_1姝诲尯鍚敤*/
        GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.B.DT1_1 = 1u;
        GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.B.DT0_2 = 1u;                              /*ATOM0_2,CDTM0_DTM4_2姝诲尯鍚敤*/
        GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.B.DT1_2 = 1u;
        GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.B.DT0_3 = 1u;                              /*ATOM0_3,CDTM0_DTM4_3姝诲尯鍚敤*/
        GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.B.DT1_3 = 1u;

        GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.B.DT0_0 = 0u;                              /*ATOM0_0,CDTM0_DTM4_0姝诲尯鍚敤*/
        GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.B.DT1_0 = 0u;                              
        GTM4.GLS[0].CDTM.DTM[5].CH_CTRL2.B.DT0_0 = 0u;                              /*ATOM0_4,CDTM0_DTM4_4姝诲尯鍚敤*/
        GTM4.GLS[0].CDTM.DTM[5].CH_CTRL2.B.DT1_0 = 0u;                              
        GTM4.GLS[0].CDTM.DTM[5].CH_CTRL2.B.DT0_2 = 0u;                              /*ATOM0_6,CDTM0_DTM5_2姝诲尯鍚敤*/
        GTM4.GLS[0].CDTM.DTM[5].CH_CTRL2.B.DT1_2 = 0u;
    }

    {
        GTM4_ATOM0.CH[1].CTRL.B.SL = 0u;                                            /*设置ATOM0通道输出电平极性*/
        GTM4_ATOM0.CH[2].CTRL.B.SL = 0u;
        GTM4_ATOM0.CH[3].CTRL.B.SL = 0u;

        GTM4_ATOM0.CH[0].CTRL.B.SL = 0u;
        GTM4_ATOM0.CH[4].CTRL.B.SL = 0u;
        GTM4_ATOM0.CH[6].CTRL.B.SL = 0u;


    	GTM4_ATOM0.CH[0].CTRL.B.CLK_SRC_SR = 0u;
    	GTM4_ATOM0.CH[1].CTRL.B.CLK_SRC_SR = 0u;
    	GTM4_ATOM0.CH[2].CTRL.B.CLK_SRC_SR = 0u;
    	GTM4_ATOM0.CH[3].CTRL.B.CLK_SRC_SR = 0u;
    	GTM4_ATOM0.CH[4].CTRL.B.CLK_SRC_SR = 0u;
    	GTM4_ATOM0.CH[5].CTRL.B.CLK_SRC_SR = 0u;
    	GTM4_ATOM0.CH[6].CTRL.B.CLK_SRC_SR = 0u;

    	GTM4.GLS[0].TBU.CHEN.B.ENDIS_CH1 = 1;                                       /*设置ATOM0通道输出*/
    	GTM4.GLS[0].TBU.CH1_CTRL.B.CH_CLK_SRC = 0;
    	GTM4.GLS[0].TBU.CH1_CTRL.B.CH_MODE = 0;
    }

    {
    	GTM4_ATOM0.CH[1].CTRL.B.UDMODE = 0;                                         /*设置ATOM0_1为UP计数模式*/
    	GTM4_ATOM0.CH[2].CTRL.B.UDMODE = 0;                                         /*设置ATOM0_2为UP计数模式*/
    	GTM4_ATOM0.CH[3].CTRL.B.UDMODE = 0;                                         /*设置ATOM0_3为UP计数模式*/

    	GTM4_ATOM0.CH[0].CTRL.B.UDMODE = 0;                                         /*设置ATOM0_0为UP计数模式*/
    	GTM4_ATOM0.CH[4].CTRL.B.UDMODE = 0;                                         /*设置ATOM0_4为UP计数模式*/
    	GTM4_ATOM0.CH[6].CTRL.B.UDMODE = 0;                                         /*设置ATOM0_6为UP计数模式*/

    	GTM4_ATOM0.CH[5].CTRL.B.UDMODE = 0;                                         /*设置ATOM0_5为UP计数模式*/
    }

    {
    	GTM4_ATOM0.AGC.GLB_CTRL.B.UPEN_CTRL1 = 2;                                   /*使能ATOM0_1通道CM值自动更新*/
    	GTM4_ATOM0.AGC.GLB_CTRL.B.UPEN_CTRL2 = 2;                                   /*使能ATOM0_2通道CM值自动更新*/
    	GTM4_ATOM0.AGC.GLB_CTRL.B.UPEN_CTRL3 = 2;                                   /*使能ATOM0_3通道CM值自动更新*/
    	GTM4_ATOM0.AGC.GLB_CTRL.B.UPEN_CTRL0 = 2;                                   /*使能ATOM0_0通道CM值自动更新*/
    	GTM4_ATOM0.AGC.GLB_CTRL.B.UPEN_CTRL4 = 2;                                   /*使能ATOM0_4通道CM值自动更新*/
    	GTM4_ATOM0.AGC.GLB_CTRL.B.UPEN_CTRL6 = 2;                                   /*使能ATOM0_6通道CM值自动更新*/
    	GTM4_ATOM0.AGC.GLB_CTRL.B.UPEN_CTRL5 = 2;                                   /*使能ATOM0_5通道CM值自动更新*/

    	GTM4_ATOM0.AGC.ENDIS_CTRL.B.ENDIS_CTRL1 = 2;                                /*使能ATOM0通道*/
    	GTM4_ATOM0.AGC.ENDIS_CTRL.B.ENDIS_CTRL2 = 2;
    	GTM4_ATOM0.AGC.ENDIS_CTRL.B.ENDIS_CTRL3 = 2;
    	GTM4_ATOM0.AGC.ENDIS_CTRL.B.ENDIS_CTRL0 = 2;
    	GTM4_ATOM0.AGC.ENDIS_CTRL.B.ENDIS_CTRL4 = 2;
    	GTM4_ATOM0.AGC.ENDIS_CTRL.B.ENDIS_CTRL6 = 2;
    	GTM4_ATOM0.AGC.ENDIS_CTRL.B.ENDIS_CTRL5 = 2;

    	GTM4_ATOM0.AGC.ENDIS_STAT.B.ENDIS_STAT1 = 2;
    	GTM4_ATOM0.AGC.ENDIS_STAT.B.ENDIS_STAT2 = 2;
    	GTM4_ATOM0.AGC.ENDIS_STAT.B.ENDIS_STAT3 = 2;
    	GTM4_ATOM0.AGC.ENDIS_STAT.B.ENDIS_STAT0 = 2;
        GTM4_ATOM0.AGC.ENDIS_STAT.B.ENDIS_STAT4 = 2;
    	GTM4_ATOM0.AGC.ENDIS_STAT.B.ENDIS_STAT6 = 2;
        GTM4_ATOM0.AGC.ENDIS_STAT.B.ENDIS_STAT5 = 2;

    	GTM4_ATOM0.AGC.OUTEN_CTRL.B.OUTEN_CTRL1 = 2;                                /*使能ATOM0通道输出*/
    	GTM4_ATOM0.AGC.OUTEN_CTRL.B.OUTEN_CTRL2 = 2;
    	GTM4_ATOM0.AGC.OUTEN_CTRL.B.OUTEN_CTRL3 = 2;
    	GTM4_ATOM0.AGC.OUTEN_CTRL.B.OUTEN_CTRL0 = 2;
    	GTM4_ATOM0.AGC.OUTEN_CTRL.B.OUTEN_CTRL4 = 2;
    	GTM4_ATOM0.AGC.OUTEN_CTRL.B.OUTEN_CTRL6 = 2;
    	GTM4_ATOM0.AGC.OUTEN_CTRL.B.OUTEN_CTRL5 = 2;

    	GTM4_ATOM0.AGC.OUTEN_STAT.B.OUTEN_STAT1 = 2;
    	GTM4_ATOM0.AGC.OUTEN_STAT.B.OUTEN_STAT2 = 2;
    	GTM4_ATOM0.AGC.OUTEN_STAT.B.OUTEN_STAT3 = 2;
    	GTM4_ATOM0.AGC.OUTEN_STAT.B.OUTEN_STAT0 = 2;
    	GTM4_ATOM0.AGC.OUTEN_STAT.B.OUTEN_STAT4 = 2;
    	GTM4_ATOM0.AGC.OUTEN_STAT.B.OUTEN_STAT6 = 2;
    	GTM4_ATOM0.AGC.OUTEN_STAT.B.OUTEN_STAT5 = 2;

        // GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.R |= 0x22222200;
        
    	GTM4.GLS[0].CMU.CLK[0].CTRL.B.CLK_CNT =0;

    	GTM4_ATOM0.AGC.ACT_TB.B.TB_TRIG = 1u;

    	GTM4_ATOM0.AGC.GLB_CTRL.B.HOST_TRIG = 1u;                                   /*触发ATOM0更新*/
    }



    Pwm3ph_SetPwmFreq(10000);

    Pwm3ph_SetPwmDuty(0.0f, 0.0f, 0.0f);

}

/*******************************************************************************
 * <@name>          GTM_LLD_SetToutSel_lld
 * <@param>         uint32_t，TOUT_NUM
 * <@param>         uint32_t，TOUT_SEL
 * <@return>        status_t
 * <@descr.>        GTM模块输出IO配置
 * <@note>            
********************************************************************************/
status_t GTM_LLD_SetToutSel_lld(uint32_t TOUT_NUM,  uint32_t TOUT_SEL)
{
    GTM4.GLS[0].TOUTSEL[TOUT_NUM / 8].R |= (TOUT_SEL << (0x4 * (TOUT_NUM % 8)));

    return STATUS_SUCCESS;
}
#pragma ghs section text =".foc_code"
/*******************************************************************************
 * <@name>          Pwm3ph_GetTs
 * <@param>         void
 * <@return>        void
 * <@descr.>        获取PWM时间戳
 * <@note>
********************************************************************************/
uint32 Pwm3ph_GetTs(void)
{
	uint32 ret;

	ret = GTM4.GLS[0].TIM.CH[0].GPR0.B.GPR0;    /*读取TIM0_0的捕获时间戳*/

	return ret;
}


/*******************************************************************************
 * <@name>          Pwm3ph_SetPwmTimCfg
 * <@param>         void
 * <@return>        void
 * <@descr.>        PWM输出TIM模块初始化配置
 * <@note>
********************************************************************************/
void Pwm3ph_SetPwmTimCfg(void)
{
	GTM4.GLS[0].CCM.TIM_AUX_IN_SRC.B.SRC_CH0 = 1u;      /*设置TIM0_0捕获，用于捕获ATOM0_0的CCU0*/
	GTM4.GLS[0].TIM.IN_SRC.B.MODE_0 = 0u;
	GTM4.GLS[0].TIM.IN_SRC.B.VAL_0 = 2u;

	GTM4.GLS[0].TIM.CH[0].CTRL.R = 0x00000C25;          //rising GPR0 captureTBU0 
	GTM4.GLS[0].TIMINSEL[0].B.CH0SEL = 0u;

}

/*******************************************************************************
 * <@name>          Pwm3ph_GetPwmFreq
 * <@param>         void
 * <@return>        void
 * <@descr.>        获取PWM频率
 * <@note>
********************************************************************************/
uint32_t Pwm3ph_GetPwmFreq(void)
{
    if(g_PwmConfig.initialized == false)
    {
        return PWM_NOT_OK;
    }
    return g_PwmConfig.current_freq;
}

/*******************************************************************************
 * <@name>          Pwm3ph_SetPwmFreq
 * <@param>         uint32_t freq
 * <@return>        Std_ReturnType
 * <@descr.>        PWM设置频率
 * <@note>            
********************************************************************************/
uint8_t Pwm3ph_SetPwmFreq(uint32_t freq)
{
    #if 0
    vuint32_t period_cnt = 0;                               /* PWM周期的计数值 */
    #endif
    if (freq == 0)                                          /* 判断频率是否为0 */
    {
        return PWM_NOT_OK;
    }

    if(freq >10000)                                         /* 判断频率是否大于10kHz */
    {
        freq = 10000;
    }


    g_PwmConfig.period_cnt = PWM3PH_GTM_PWM_CLK / freq;
    #if 0
    g_PwmConfig.half_period_cnt = g_PwmConfig.period_cnt / 2;
    #else
    g_PwmConfig.half_period_cnt = g_PwmConfig.period_cnt >>1;
    #endif
    g_PwmConfig.current_freq = freq;
    g_PwmConfig.initialized = true;
 
    GTM4_ATOM0.CH[0].SR0.R = (vuint32_t)(g_PwmConfig.period_cnt);                /* 频率计数值 */
    GTM4_ATOM0.CH[0].SR1.R = (vuint32_t)(g_PwmConfig.half_period_cnt);

    GTM4_ATOM0.CH[6].SR0.R = (vuint32_t)(g_PwmConfig.period_cnt);                /* FOC中断频率同步更新 */
    GTM4_ATOM0.CH[6].SR1.R = (vuint32_t)(g_PwmConfig.half_period_cnt);

    return PWM_OK;
}

/*******************************************************************************
 * <@name>          Pwm3ph_SetPwmDuty
 * <@param>         float32_t, duty1
 * <@param>         float32_t, duty2
 * <@param>         float32_t, duty3
 * <@return>        void
 * <@descr.>        PWM设置占空比
 * <@note>            
********************************************************************************/
uint8_t Pwm3ph_SetPwmDuty(float32_t duty1, float32_t duty2, float32_t duty3)
{
	vuint32_t a = 0;                                        /* L1相PWM高电平比较码值 */
	vuint32_t b = 0;                                        /* L2相PWM高电平比较码值 */
	vuint32_t c = 0;                                        /* L3相PWM高电平比较码值 */

	float32_t du1=0.0f, du2=0.0f, du3=0.0f;
#if 0
    du1 = duty1;
    du2 = duty2;
    du3 = duty3;
#endif
    if (!g_PwmConfig.initialized) 
    {
        return PWM_NOT_OK;
    }
#if 0
    if(duty1 < 0.0f)                                        /* 判断duty1占空比是否小于0 */
    {
        du1 = 0.0f;                                         /* 将duty1占空比强制设置为0 */
    }



    if(duty2 < 0.0f)                                        /* 判断duty2占空比是否小于0 */
    {
        du2 = 0.0f;                                         /* 将duty2占空比强制设置为0 */
    }

    if(duty3 < 0.0f)                                        /* 判断duty3占空比是否小于0 */
    {
        du3 = 0.0f;                                         /* 将duty3占空比强制设置为0 */
    }

    if(duty1 > 0.9999f)                                     /* 判断duty1占空比是否大于0.9999 */
    {
        du1 = 0.9999f;                                      /* 将duty1占空比强制设置为0.9999 */
    }

    if(duty2 > 0.9999f)                                     /* 判断duty2占空比是否大于0.9999 */
    {
        du2 = 0.9999f;                                      /* 将duty2占空比强制设置为0.9999 */
    }

    if(duty3 > 0.9999f)                                     /* 判断duty3占空比是否大于0.9999 */
    {
        du3 = 0.9999f;                                      /* 将duty3占空比强制设置为0.9999 */
    }
#else
    du1 = duty1 < 0.0f?0.0f:duty1;
    du2 = duty2 < 0.0f?0.0f:duty2;
    du3 = duty3 < 0.0f?0.0f:duty3;

    du1 = duty1 > 0.9999f?0.9999f:duty1;
    du2 = duty2 > 0.9999f?0.9999f:duty2;
    du3 = duty3 > 0.9999f?0.9999f:duty3;
#endif


    a = (vuint32_t)((du1) * ((float)(g_PwmConfig.half_period_cnt)));             /* 根据占空比计算高电平的计数值 */
    b = (vuint32_t)((du2) * ((float)(g_PwmConfig.half_period_cnt)));
    c = (vuint32_t)((du3) * ((float)(g_PwmConfig.half_period_cnt)));

    GTM4_ATOM0.CH[3].SR0.R = (vuint32_t)(g_PwmConfig.half_period_cnt) + a;       /* U相，根据占空比计算SR0和SR1 */
    GTM4_ATOM0.CH[3].SR1.R = (vuint32_t)(g_PwmConfig.half_period_cnt) - a;

    GTM4_ATOM0.CH[1].SR0.R = (vuint32_t)(g_PwmConfig.half_period_cnt) + b;       /* V相，根据占空比计算SR0和SR1 */
    GTM4_ATOM0.CH[1].SR1.R = (vuint32_t)(g_PwmConfig.half_period_cnt) - b;

    GTM4_ATOM0.CH[2].SR0.R = (vuint32_t)(g_PwmConfig.half_period_cnt) + c;       /* W相，根据占空比计算SR0和SR1 */
    GTM4_ATOM0.CH[2].SR1.R = (vuint32_t)(g_PwmConfig.half_period_cnt) - c;

    return PWM_OK;
}


void PwmOutEnable(uint8 enable)
{
    #if 0
    if (enable == 1)
    {
        SIUL.GPDO[145].B.PDO = 1;         /* PWN硬件PIN使能 */
    }
    else
    {
        SIUL.GPDO[145].B.PDO = 0;          /* PWN硬件PIN关闭 */
    }
    #else
    SIUL.GPDO[145].B.PDO = (enable==1)?1:0;
    #endif

}


/*******************************************************************************
 * <@name>          Pwm3ph_Enable
 * <@param>         Pwm3ph_Dev_t *, pwmDev
 * <@return>        void
 * <@descr.>        使能PWM输出
 * <@note>
********************************************************************************/
void Pwm3ph_Enable(Pwm3ph_Dev_t * pwmDev)
{
	GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.R &= 0xCCCCCCFF;       /* 打开3相的DTM输出 */
}

/*******************************************************************************
 * <@name>          Pwm3ph_Disable
 * <@param>         Pwm3ph_Dev_t *, pwmDev
 * <@return>        void
 * <@descr.>        关闭PWM输出
 * <@note>
********************************************************************************/
void Pwm3ph_Disable(Pwm3ph_Dev_t * pwmDev)
{
    GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.R |= 0x22222200;       /* 关闭3相的DTM输出 */
}


/*******************************************************************************
 * <@name>          Pwm3ph_SetSpo
 * <@param>         Pwm3ph_Dev_t *, pwmDev
 * <@return>        void
 * <@descr.>        PWM设定为安全关断
 * <@note>            
********************************************************************************/
void Pwm3ph_SetSpo(Pwm3ph_Dev_t * pwmDev)
{
    GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.R |= 0x22222200;       /* 强制DTM输出为SPO */
}


/*******************************************************************************
 * <@name>          Pwm3ph_SetLasc
 * <@param>         Pwm3ph_Dev_t *, pwmDev
 * <@return>        void
 * <@descr.>        PWM设置为低边短路
 * <@note>            
********************************************************************************/
void Pwm3ph_SetLasc(Pwm3ph_Dev_t * pwmDev)
{
	GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.R |= 0x32323200;       /* 强制DTM输出为LASC */
}


/*******************************************************************************
 * <@name>          Pwm3ph_SetHasc
 * <@param>         Pwm3ph_Dev_t *, pwmDev
 * <@return>        void
 * <@descr.>        PWM设置为高边短路
 * <@note>            
********************************************************************************/
void Pwm3ph_SetHasc(Pwm3ph_Dev_t * pwmDev)
{
	GTM4.GLS[0].CDTM.DTM[4].CH_CTRL2.R |= 0x23232300;       /* 强制DTM输出为HASC */
}


/*******************************************************************************
 * <@name>          Pwm3ph_SetPwmState
 * <@param>         Pwm3ph_Dev_t *, pwmDev
 * <@param>         Pwm3ph_StateType, stateCmd
 * <@return>        void
 * <@descr.>        PWM设定状态机
 * <@note>            
********************************************************************************/
void Pwm3ph_SetPwmState(Pwm3ph_Dev_t * pwmDev, uint8_t stateCmd)
{

    switch(stateCmd)                                                                        /* 根据stateCmd判断PWM模式 */
    {
        case Pwm3ph_State_Enable:
            if(pwmDev->state != Pwm3ph_State_Enable)
            {
                pwmDev->state = Pwm3ph_State_Enable;
                Pwm3ph_Enable(pwmDev);
            }
            break;

        case Pwm3ph_State_Disable:
            if(pwmDev->state != Pwm3ph_State_Disable)
            {
                pwmDev->state = Pwm3ph_State_Disable;
                Pwm3ph_Disable(pwmDev);
            }

            break;

        case Pwm3ph_State_Lasc:
            if(pwmDev->state != Pwm3ph_State_Lasc)
            {
                pwmDev->state = Pwm3ph_State_Lasc;
                Pwm3ph_SetLasc(pwmDev);
            }

            break;

        case Pwm3ph_State_Hasc:
            if(pwmDev->state != Pwm3ph_State_Hasc)
            {
                pwmDev->state = Pwm3ph_State_Hasc;
                Pwm3ph_SetHasc(pwmDev);
            }

            break;

        default:
            break;
    }
}

void Foc_Isr_init(void)
{
    GTM4.GLS[0].ATOM.CH[6].IRQ_EN.B.CCU0TC_IRQ_EN = 1;          /*使能ATOM0_6通道CCU0中断*/
    GTM4.GLS[0].ATOM.CH[6].IRQ_EN.B.CCU1TC_IRQ_EN = 0;          /*关闭ATOM0_6通道CCU1中断*/
    GTM4.GLS[0].ATOM.CH[6].IRQ_MODE.B.IRQ_MODE = 0;             /*设置ATOM0_6通道中断为电平模式*/    
}


#pragma ghs section
#pragma ghs section
#pragma ghs section