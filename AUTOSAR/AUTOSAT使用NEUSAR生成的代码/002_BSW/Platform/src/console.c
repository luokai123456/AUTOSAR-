/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3012PT
* DESCRIPTION : console c file
* HISTORY     : Initial version
* @file     console.c
* @version  3.0.0
* @date     2023 - 05 - 06
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 1505,1503,3335,3437 EOF*/
#include "console.h" /* PRQA S 0380 */
#include "Mcal.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

static struct Private_Param *Param0; /* PRQA S 1504 */
static struct Private_Param *Param1; /* PRQA S 1504 */
static struct Private_Param *Param2; /* PRQA S 1504 */
static struct Private_Param *Param3; /* PRQA S 1504 */
static struct Private_Param *Param4; /* PRQA S 1504 */
static struct Private_Param *Param5; /* PRQA S 1504 */

static struct Private_Param ParamN0; /* PRQA S 1504, 1514, 0308, 3218 */
static struct Private_Param ParamN1; /* PRQA S 1504, 1514, 0308, 3218 */
static struct Private_Param ParamN2; /* PRQA S 1504, 1514, 0308, 3218 */
static struct Private_Param ParamN3; /* PRQA S 1504, 1514, 0308, 3218 */
static struct Private_Param ParamN4; /* PRQA S 1504, 1514, 0308, 3218 */
static struct Private_Param ParamN5; /* PRQA S 1504, 1514, 0308, 3218 */

static struct Lin_Device STD_DEV_0; /* PRQA S 1504, 1514 */
static struct Lin_Device STD_DEV_1; /* PRQA S 1504, 1514 */
static struct Lin_Device STD_DEV_2; /* PRQA S 1504, 1514 */
static struct Lin_Device STD_DEV_3; /* PRQA S 1504, 1514 */
static struct Lin_Device STD_DEV_4; /* PRQA S 1504, 1514 */
static struct Lin_Device STD_DEV_5; /* PRQA S 1504, 1514 */
/*******************************************************************************
 * @brief   UART_Siu_Conf
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void UART_Siu_Conf(const struct Lin_Device *dev) /* PRQA S 1504, 1505 */
{
#if SWITCH_CORE_ENABLE
    (void)dev;
#if SPI_CONFIG
    SIUL.PCR[150U].R = 0x069C;
    SIUL.PCR[151U].R = 0x2540;
    SIUL.PSMI[5U].R = 2U;
#else
    SIUL.PCR[PA7].R = 0x0D9C;
    SIUL.PCR[PA6].R = 0x2740;
    SIUL.PSMI[5U].R = 0U;
#endif
#else /* SWITCH_CORE_ENABLE */
    volatile const struct LINFlexD_tag *LINFLEX_PTR = dev->lin_num;
    if(LINFLEX_PTR == &LINFlexD_5)
    {
        SIUL.PCR[PJ6].R = 0x069C;
        SIUL.PCR[PJ7].R = 0x2540;
        SIUL.PSMI[5U].R = 2U;
    }
    else if(LINFLEX_PTR == &LINFlexD_9)
    {
        SIUL.PCR[PB7].R = 0x089C;
        SIUL.PCR[PB5].R = 0x2640;
        SIUL.PSMI[9U].R = 0U;
    }
    else if(LINFLEX_PTR == &LINFlexD_3)
    {
        SIUL.PCR[PH6].R = 0x069C;
        SIUL.PCR[PH7].R = 0x2340;
        SIUL.PSMI[3U].R = 3U;
    }
    else if(LINFLEX_PTR == &LINFlexD_4)
    {
        SIUL.PCR[PJ14].R = 0x059C;
        SIUL.PCR[PJ13].R = 0x2440;
        SIUL.PSMI[4U].R = 2U;
    }
    else if(LINFLEX_PTR == &LINFlexD_7)
    {
        SIUL.PCR[PK3].R = 0x0A9C;
        SIUL.PCR[PK2].R = 0x2440;
        SIUL.PSMI[7U].R = 5U;
    }
    else if(LINFLEX_PTR == &LINFlexD_8)
    {
        SIUL.PCR[PC9].R = 0x0A9C;
        SIUL.PCR[PC10].R = 0x2840;
        SIUL.PSMI[8U].R = 0U;
    }
    else /* PRQA S 2013 */
    {

    }
#endif
}

/*******************************************************************************
 * @brief   UART_Set_Baudrate
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static inline void UART_Set_Baudrate(const struct Lin_Device *dev, uint64_t sys_clock, uint64_t baudrate) /* PRQA S 1503, 3408 */
{
    volatile struct LINFlexD_tag *LINFLEX_PTR;
    uint32_t rate,rate_f,rate_m;

    LINFLEX_PTR = dev->lin_num;

    LINFLEX_PTR->LINCR1.B.SLEEP  = DISABLE;
    LINFLEX_PTR->LINCR1.B.BF     = DISABLE;

    LINFLEX_PTR->UARTCR.B.UART   = 1U;
    LINFLEX_PTR->UARTCR.B.RxEn   = ENABLE;
    LINFLEX_PTR->UARTCR.B.TxEn   = ENABLE;

    rate = (uint32_t)(sys_clock / baudrate);
    rate_f = rate % 16U;
    rate_m = rate / 16U;

    LINFLEX_PTR->LINFBRR.B.FBR = rate_f;
    LINFLEX_PTR->LINIBRR.B.IBR = rate_m;

    LINFLEX_PTR->UARTSR.B.DRFRFE = 1U;
    LINFLEX_PTR->UARTSR.B.DTFTFF = 1U;
}
/*******************************************************************************
 * @brief   UART_Set_Param
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/


static inline void UART_Set_Param(const struct Lin_Device *dev,uint8_t parity,uint8_t bit_len,uint8_t tfc,uint8_t rfc) /* PRQA S 1503, 3408 */
{
    volatile struct LINFlexD_tag *LINFLEX_PTR;

    LINFLEX_PTR = dev->lin_num;
    LINFLEX_PTR->LINCR1.B.LBKM = 0U;

    switch(parity)
    {
        case 0:
            LINFLEX_PTR->UARTCR.B.PCE = DISABLE;
            break;
        case UART_ODD_PARITY:
            LINFLEX_PTR->UARTCR.B.PCE = ENABLE;
            LINFLEX_PTR->UARTCR.B.PC_0 = 1U; /*Parity sent is odd*/
            break;
        case UART_EVEN_PARITY:
            LINFLEX_PTR->UARTCR.B.PCE = ENABLE;
            LINFLEX_PTR->UARTCR.B.PC_0 = 0U; /*Parity sent is even*/
            break;
        default:
            LINFLEX_PTR->UARTCR.B.PCE = DISABLE;
            break;
    }

    switch(bit_len)
    {
        case 7:
            LINFLEX_PTR->UARTCR.B.WL0 = 0U;
            break;
        case 8:
            LINFLEX_PTR->UARTCR.B.WL0 = 1U;
            break;
        default:
            LINFLEX_PTR->UARTCR.B.WL0 = 1U;
            break;
    }

    LINFLEX_PTR->UARTCR.B.TDFL_TFC = tfc;   /* Tx FIFO counter*/
    LINFLEX_PTR->UARTCR.B.RDFL_RFC = rfc;   /* Rx FIFO counter*/
}
/*******************************************************************************
 * @brief   UART_INT_DIS
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void UART_INT_DIS(const struct Lin_Device *dev)
{
    volatile struct LINFlexD_tag *LINFLEX_PTR;
    LINFLEX_PTR = dev->lin_num;
    LINFLEX_PTR->LINIER.R = 0U;

    LINFLEX_PTR->LINIER.B.DRIE = 1;
}
/*******************************************************************************
 * @brief   UART_TX
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void UART_TX(const struct Lin_Device *dev, char data)
{
    volatile struct LINFlexD_tag *LINFLEX_PTR = dev->lin_num;

    LINFLEX_PTR->UARTSR.B.DTFTFF = 1U;

    LINFLEX_PTR->BDRL.B.DATA0 = (uint8_t)data;

    while(LINFLEX_PTR->UARTSR.B.DTFTFF == 0U) {}
}
/*******************************************************************************
 * @brief   UART_RX
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
uint8_t UART_RX(const struct Lin_Device *dev, char *s)
{
    volatile struct LINFlexD_tag *LINFLEX_PTR = dev->lin_num;
    if (LINFLEX_PTR->UARTSR.B.DRFRFE == 1U)
    {
        LINFLEX_PTR->UARTSR.B.DRFRFE = 1U;
        *s = LINFLEX_PTR->BDRM.B.DATA4;
        return 1;
    }
    else
    {
        return 0;
    }
}
/*******************************************************************************
 * @brief   Std_Dev_Register
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void Std_Dev_Register(struct Lin_Device *lin_dev,volatile struct LINFlexD_tag *base,struct Private_Param *Paramx)
{
    lin_dev->lin_num = base;/*PRQA S 2919*/
    lin_dev->param_num = Paramx;
    return;
}
/*******************************************************************************
 * @brief   LINFLEX_Start_Config
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void LINFLEX_Start_Config(struct Lin_Device *dev)/*PRQA S 3673*/
{
    volatile struct LINFlexD_tag *LINFLEX_PTR;
    LINFLEX_PTR = dev->lin_num;
    LINFLEX_PTR->LINCR1.B.INIT = ENABLE;
}
/*******************************************************************************
 * @brief   LINFLEX_Complete_Config
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void LINFLEX_Complete_Config(struct Lin_Device *dev)/*PRQA S 3673*/
{
    volatile struct LINFlexD_tag *LINFLEX_PTR;
    LINFLEX_PTR = dev->lin_num;
    LINFLEX_PTR->LINCR1.B.INIT   = DISABLE;
}
/*******************************************************************************
 * @brief   Uart_Send_Char
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void Uart_Send_Char(char s)
{
#if SWITCH_CORE_ENABLE
    UART_TX(Param0->std_uart,s);/* polyspace RTE:IDP */
#else /* SWITCH_CORE_ENABLE */
    uint32 Id = GetCoreID();
    switch(Id)
    {
        case 0:
            UART_TX(Param0->std_uart,s);
            break;
        case 1:
            UART_TX(Param1->std_uart,s);
            break;
        case 2:
            UART_TX(Param2->std_uart,s);
            break;
        case 3:
            UART_TX(Param3->std_uart,s);
            break;
        case 4:
            UART_TX(Param4->std_uart,s);
            break;
        case 5:
            UART_TX(Param5->std_uart,s);
            break;
        default:
            break;
    }
#endif
}
/*******************************************************************************
 * @brief   Uart_Read_Char
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
uint8_t Uart_Read_Char(char *s)
{
    uint8_t ret = 0;
#if SWITCH_CORE_ENABLE
    ret = UART_RX(Param0->std_uart,s);/* polyspace RTE:IDP */
#else /* SWITCH_CORE_ENABLE */
    uint32 Id = GetCoreID();
    switch(Id)
    {
        case 0:
            ret = UART_RX(Param0->std_uart,s);
            break;
        case 1:
        	ret = UART_RX(Param1->std_uart,s);
            break;
        case 2:
        	ret = UART_RX(Param2->std_uart,s);
            break;
        case 3:
        	ret = UART_RX(Param3->std_uart,s);
            break;
        case 4:
        	ret = UART_RX(Param4->std_uart,s);
            break;
        case 5:
        	ret = UART_RX(Param5->std_uart,s);
            break;
        default:
            break;
    }
#endif
    return ret;
}
/*******************************************************************************
 * @brief   STDIO_OUT_INIT
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static inline void STDIO_OUT_INIT0(struct Lin_Device *dev)
{
    uint32_t lin_clockfre = 100000000;
    Param0 = dev->param_num;/*PRQA S 2919*/
    Param0->std_uart = dev;

    LINFLEX_Start_Config(Param0->std_uart);
    UART_Siu_Conf(Param0->std_uart);
    UART_Set_Baudrate(Param0->std_uart,(uint64_t)lin_clockfre,UART_BAUDRATE);
    UART_Set_Param(Param0->std_uart,UART_DISABLE_PARITY,8U,0U,0U);
    UART_INT_DIS(Param0->std_uart);
    LINFLEX_Complete_Config(Param0->std_uart);
}

static inline void STDIO_OUT_INIT1(struct Lin_Device *dev)
{
    uint32_t lin_clockfre = 100000000;
    Param1 = dev->param_num;/*PRQA S 2919*/
    Param1->std_uart = dev;

    LINFLEX_Start_Config(Param1->std_uart);
    UART_Siu_Conf(Param1->std_uart);
    UART_Set_Baudrate(Param1->std_uart,(uint64_t)lin_clockfre,UART_BAUDRATE);
    UART_Set_Param(Param1->std_uart,UART_DISABLE_PARITY,8U,0U,0U);
    UART_INT_DIS(Param1->std_uart);
    LINFLEX_Complete_Config(Param1->std_uart);
}

static inline void STDIO_OUT_INIT2(struct Lin_Device *dev)
{
    uint32_t lin_clockfre = 100000000;
    Param2 = dev->param_num;/*PRQA S 2919*/
    Param2->std_uart = dev;

    LINFLEX_Start_Config(Param2->std_uart);
    UART_Siu_Conf(Param2->std_uart);
    UART_Set_Baudrate(Param2->std_uart,(uint64_t)lin_clockfre,UART_BAUDRATE);
    UART_Set_Param(Param2->std_uart,UART_DISABLE_PARITY,8U,0U,0U);
    UART_INT_DIS(Param2->std_uart);
    LINFLEX_Complete_Config(Param2->std_uart);
}

static inline void STDIO_OUT_INIT3(struct Lin_Device *dev)
{
    uint32_t lin_clockfre = 100000000;
    Param3 = dev->param_num;/*PRQA S 2919*/
    Param3->std_uart = dev;

    LINFLEX_Start_Config(Param3->std_uart);
    UART_Siu_Conf(Param3->std_uart);
    UART_Set_Baudrate(Param3->std_uart,(uint64_t)lin_clockfre,UART_BAUDRATE);
    UART_Set_Param(Param3->std_uart,UART_DISABLE_PARITY,8U,0U,0U);
    UART_INT_DIS(Param3->std_uart);
    LINFLEX_Complete_Config(Param3->std_uart);
}

static inline void STDIO_OUT_INIT4(struct Lin_Device *dev)
{
    uint32_t lin_clockfre = 100000000;
    Param4 = dev->param_num;/*PRQA S 2919*/
    Param4->std_uart = dev;

    LINFLEX_Start_Config(Param4->std_uart);
    UART_Siu_Conf(Param4->std_uart);
    UART_Set_Baudrate(Param4->std_uart,(uint64_t)lin_clockfre,UART_BAUDRATE);
    UART_Set_Param(Param4->std_uart,UART_DISABLE_PARITY,8U,0U,0U);
    UART_INT_DIS(Param4->std_uart);
    LINFLEX_Complete_Config(Param4->std_uart);
}

static inline void STDIO_OUT_INIT5(struct Lin_Device *dev)
{
    uint32_t lin_clockfre = 100000000;
    Param5 = dev->param_num;/*PRQA S 2919*/
    Param5->std_uart = dev;

    LINFLEX_Start_Config(Param5->std_uart);
    UART_Siu_Conf(Param5->std_uart);
    UART_Set_Baudrate(Param5->std_uart,(uint64_t)lin_clockfre,UART_BAUDRATE);
    UART_Set_Param(Param5->std_uart,UART_DISABLE_PARITY,8U,0U,0U);
    UART_INT_DIS(Param5->std_uart);
    LINFLEX_Complete_Config(Param5->std_uart);
}

void Uart_SendStr(const char * s)
{
    const char * tmp = s;

    while(tmp < (s + strlen(s)))/* polyspace RTE:STD_LIB */
    {
        Uart_Send_Char(*tmp++);/* polyspace RTE:NIV *//* PRQA S 3387, 3440 */
    }
}

/*******************************************************************************
 * @brief   PSPRINTF
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void PSPRINTF(const char *fmt, ...)/*PRQA S 1337*/
{
#if SWITCH_CORE_ENABLE
    uint32 coreid = GetCoreID();
//     if (coreid == shell_coreid)
//     {
// #endif /* SWITCH_CORE_ENABLE */
//         char string[255];
//         va_list ap;

//         (void)va_start(ap , fmt);

//         (void)vsprintf(string, fmt, ap);/* polyspace RTE:STD_LIB */

//         (void)Uart_SendStr(string);

//         (void)va_end(ap);/*PRQA S 5140,3119*/
// #if SWITCH_CORE_ENABLE
//     }
#endif /* SWITCH_CORE_ENABLE */
}



//extern Shell shell_Handle[6U];

void HandleDebugCmd(uint8_t cmdChar)
{
    uint8_t coreid = GetCoreID();
    //shellHandler(&shell_Handle[coreid],cmdChar);
}

/*******************************************************************************
 * @brief      Console_Init
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void Console_Init(void)
{
    uint32 Id = GetCoreID();
    switch(Id)
    {
        case 0:
            Std_Dev_Register(&STD_DEV_0,&LINFlexD_5,&ParamN0);
            STDIO_OUT_INIT0(&STD_DEV_0);
            break;
        case 1:
            Std_Dev_Register(&STD_DEV_1,&LINFlexD_9,&ParamN1);
            STDIO_OUT_INIT1(&STD_DEV_1);
            break;
        case 2:
            Std_Dev_Register(&STD_DEV_2,&LINFlexD_3,&ParamN2);
            STDIO_OUT_INIT2(&STD_DEV_2);
            break;
        case 3:
            Std_Dev_Register(&STD_DEV_3,&LINFlexD_4,&ParamN3);
            STDIO_OUT_INIT3(&STD_DEV_3);
            break;
        case 4:
            Std_Dev_Register(&STD_DEV_4,&LINFlexD_7,&ParamN4);
            STDIO_OUT_INIT4(&STD_DEV_4);
            break;
        case 5:
            Std_Dev_Register(&STD_DEV_5,&LINFlexD_8,&ParamN5);
            STDIO_OUT_INIT5(&STD_DEV_5);
            break;
        default:
            break;
    }


}
