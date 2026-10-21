/*******************************************************************************
File Name:  Motor_HwIf.c
Author:
Date:
Version:    V1.0
File Description:
Copyright:
*******************************************************************************/



/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Motor_Diag.h"
#include "Pwm3ph.h"
#include "Icu.h"
#include "IoHwAbs_PWM_Cfg.h"
#include "IoHwAbs_DIO_prv.h"
#include "Motor_HwIf.h"

#pragma ghs section data =".XCP_CAL"

volatile uint16_t Motor_Diag_SetFreq = 2000;
volatile uint16_t Motor_Diag_Vref_VDC_SetDuty = 843;
volatile uint16_t Motor_Diag_VrefPhase_OCP_P_SetDuty = 772;//530;
volatile uint16_t Motor_Diag_VrefPhase_OCP_N_SetDuty = 228;//470;

#pragma ghs section

#pragma ghs section data =".foc_data"
// #pragma ghs section text =".foc_code"
#pragma ghs section bss =".foc_bss"


/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
//Test
uint8 Test_Tim4C0Cnt_u8 = 0;   // TIM4通道0 (U相下管故障)
uint8 Test_Tim6C1Cnt_u8 = 0;   // TIM6通道1 (U相上管故障)
uint8 Test_Tim6C2Cnt_u8 = 0;   // TIM6通道2 (V相下管故障)
uint8 Test_Tim6C3Cnt_u8 = 0;   // TIM6通道3 (V相上管故障)
uint8 Test_Tim6C4Cnt_u8 = 0;   // TIM6通道4 (W相下管故障)
uint8 Test_Tim6C5Cnt_u8 = 0;   // TIM6通道5 (W相上管故障)
uint8 Test_Tim6C0Cnt_u8 = 0;   // TIM6通道0 (V相过流)
uint8 Test_Tim3C2Cnt_u8 = 0;   // TIM3通道2 (U相过流)
uint8 Test_Tim6C6Cnt_u8 = 0;   // TIM6通道6 (W相过流)
uint8 Test_Tim3C3Cnt_u8 = 0;   // TIM3通道3 (过压故障OV1)
uint8 Test_Tim3C4Cnt_u8 = 0;   // TIM3通道4 (过压故障OV2)
uint8 Test_Tim4C7Cnt_u8 = 0;   // TIM4通道7 (故障自锁状态回读)

// 预驱上下管故障标志（6个）
uint8 Motor_U_HsFault_Flag = 0;      // U相上管故障
uint8 Motor_U_LsFault_Flag = 0;      // U相下管故障
uint8 Motor_V_HsFault_Flag = 0;      // V相上管故障
uint8 Motor_V_LsFault_Flag = 0;      // V相下管故障
uint8 Motor_W_HsFault_Flag = 0;      // W相上管故障
uint8 Motor_W_LsFault_Flag = 0;      // W相下管故障

// 过流故障标志（3个）
uint8 Motor_U_OverCurrent_Flag = 0;  // U相过流
uint8 Motor_V_OverCurrent_Flag = 0;  // V相过流
uint8 Motor_W_OverCurrent_Flag = 0;  // W相过流

// 过压故障标志（2个）
uint8 Motor_OverVoltage1_Flag = 0;   // 过压故障1 (OV1)
uint8 Motor_OverVoltage2_Flag = 0;   // 过压故障2 (OV2)

// 欠压故障标志（2个）
uint8 Motor_TOP_UV_Flag = 0;         // 上管欠压故障
uint8 Motor_BOT_UV_Flag = 0;         // 下管欠压故障

// 退饱和故障标志（2个）
uint8 Motor_TOP_DesatFlt_Flag = 0;   // 上管退饱和故障
uint8 Motor_BOT_DesatFlt_Flag = 0;   // 下管退饱和故障

// 故障自锁状态回读标志（1个）
uint8 Motor_OCPOV_TRIGGER_Flag = 0;   // 故障自锁状态回读


/**
 * @brief Motor诊断相关模块初始化
 * @details 初始化诊断相关TIM中断
 */
void Motor_Diag_Init(void)
{
    Motor_InitDiagThresholds(); // 初始化诊断阈值
    uint8 Icu_numIcuSignalChannel_i;
    for(Icu_numIcuSignalChannel_i = 15; Icu_numIcuSignalChannel_i < 27; Icu_numIcuSignalChannel_i++ )
	{
        Icu_StartSignalMeasurement(Icu_numIcuSignalChannel_i);
    }
    GTM4.GLS[4].TIM.CH[0].CTRL.B.TIM_MODE = 2;
    GTM4.GLS[6].TIM.CH[0].CTRL.B.TIM_MODE = 2;
    GTM4.GLS[6].TIM.CH[1].CTRL.B.TIM_MODE = 2; 
    GTM4.GLS[6].TIM.CH[2].CTRL.B.TIM_MODE = 2; 
    GTM4.GLS[6].TIM.CH[3].CTRL.B.TIM_MODE = 2; 
    GTM4.GLS[6].TIM.CH[4].CTRL.B.TIM_MODE = 2;  
    GTM4.GLS[6].TIM.CH[5].CTRL.B.TIM_MODE = 2;
    GTM4.GLS[6].TIM.CH[6].CTRL.B.TIM_MODE = 2; 
    GTM4.GLS[3].TIM.CH[2].CTRL.B.TIM_MODE = 2; 
    GTM4.GLS[3].TIM.CH[3].CTRL.B.TIM_MODE = 2; 
    GTM4.GLS[3].TIM.CH[4].CTRL.B.TIM_MODE = 2;  
    GTM4.GLS[4].TIM.CH[7].CTRL.B.TIM_MODE = 2;

    Diag_TIM_Isr_Init();        // 初始化诊断相关TIM中断
}

/**
 * @brief 诊断相关TIM中断初始化
 * @details 配置GTM TIM通道的中断使能和中断模式
 */
void Diag_TIM_Isr_Init(void)
{
    // TIM4通道0中断配置 UL-Diag
    GTM4.GLS[4].TIM.CH[0].IRQ_EN.R = 0x1; 
    GTM4.GLS[4].TIM.CH[0].IRQ_MODE.B.IRQ_MODE = 0; 

    // TIM6通道1中断配置 UH-Diag
    GTM4.GLS[6].TIM.CH[1].IRQ_EN.R = 0x1;
    GTM4.GLS[6].TIM.CH[1].IRQ_MODE.B.IRQ_MODE = 0;

    // TIM6通道2中断配置 VL-Diag
    GTM4.GLS[6].TIM.CH[2].IRQ_EN.R = 0x1;
    GTM4.GLS[6].TIM.CH[2].IRQ_MODE.B.IRQ_MODE = 0;

    // TIM6通道3中断配置 VH-Diag
    GTM4.GLS[6].TIM.CH[3].IRQ_EN.R = 0x1;
    GTM4.GLS[6].TIM.CH[3].IRQ_MODE.B.IRQ_MODE = 0;

    // TIM6通道4中断配置 WL-Diag
    GTM4.GLS[6].TIM.CH[4].IRQ_EN.R = 0x1;
    GTM4.GLS[6].TIM.CH[4].IRQ_MODE.B.IRQ_MODE = 0;

    // TIM6通道5中断配置 WH-Diag
    GTM4.GLS[6].TIM.CH[5].IRQ_EN.R = 0x1; 
    GTM4.GLS[6].TIM.CH[5].IRQ_MODE.B.IRQ_MODE = 0; 

    // TIM6通道0中断配置 VOC-Diag
    GTM4.GLS[6].TIM.CH[0].IRQ_EN.R = 0x0;
    GTM4.GLS[6].TIM.CH[0].IRQ_MODE.B.IRQ_MODE = 0;

    // TIM3通道2中断配置 UOC-Diag
    GTM4.GLS[3].TIM.CH[2].IRQ_EN.R = 0x1;
    GTM4.GLS[3].TIM.CH[2].IRQ_MODE.B.IRQ_MODE = 0;

    // TIM3通道3中断配置 OV1-Diag
    GTM4.GLS[3].TIM.CH[3].IRQ_EN.R = 0x1;
    GTM4.GLS[3].TIM.CH[3].IRQ_MODE.B.IRQ_MODE = 0;

    // TIM3通道4中断配置 OV2-Diag
    GTM4.GLS[3].TIM.CH[4].IRQ_EN.R = 0x0;// 禁用OV2-Diag中断
    GTM4.GLS[3].TIM.CH[4].IRQ_MODE.B.IRQ_MODE = 0;

    // TIM6通道6中断配置 WOC-Diag
    GTM4.GLS[6].TIM.CH[6].IRQ_EN.R = 0x1;
    GTM4.GLS[6].TIM.CH[6].IRQ_MODE.B.IRQ_MODE = 0;

    // TIM4通道7中断配置 
    GTM4.GLS[4].TIM.CH[7].IRQ_EN.R = 0x1;//故障自锁状态回读
    GTM4.GLS[4].TIM.CH[7].IRQ_MODE.B.IRQ_MODE = 0;
}

void Motor_Diag_DIOMainFunction(void)
{
    boolean level = STD_LOW;
    if (IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_MCU_TOP_DESAT_FLT, &level) == E_OK)
    {
        if(level == STD_LOW)
        {
           Motor_TOP_DesatFlt_Flag = 1;
           Hal_PwmEnableSet(0);
        }
        else
        {
           Motor_TOP_DesatFlt_Flag = 0;
        }
    }

    if (IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_MCU_BOT_DESAT_FLT, &level) == E_OK)
    {
        if(level == STD_LOW)
        {
           Motor_BOT_DesatFlt_Flag = 1;
           Hal_PwmEnableSet(0);
        }
        else
        {
           Motor_BOT_DesatFlt_Flag = 0;
        }
    }

    if (IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_MCU_TOP_UV, &level) == E_OK)
    {
        if(level == STD_LOW)
        {
           Motor_TOP_UV_Flag = 1;
           Hal_PwmEnableSet(0);
        }
        else
        {
           Motor_TOP_UV_Flag = 0;
        }
    }

    if (IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_MCU_BOT_UV, &level) == E_OK)
    {
        if(level == STD_LOW)
        {
           Motor_BOT_UV_Flag = 1;
           Hal_PwmEnableSet(0);
        }
        else
        {
           Motor_BOT_UV_Flag = 0;
        }
    }
}

uint8_t Motor_InitDiagThresholds(void)
{
    MotorDiag_PwmSetFreqDutySync(IoHwAbs_PWM_MCU_Vref_VDC,Motor_Diag_SetFreq,Motor_Diag_Vref_VDC_SetDuty);
    MotorDiag_PwmSetFreqDutySync(IoHwAbs_PWM_MCU_VrefPhase_OCP_P,Motor_Diag_SetFreq,Motor_Diag_VrefPhase_OCP_P_SetDuty);
    MotorDiag_PwmSetFreqDutySync(IoHwAbs_PWM_MCU_VrefPhase_OCP_N,Motor_Diag_SetFreq,Motor_Diag_VrefPhase_OCP_N_SetDuty);
}

void Motor_DiagOverCorV_Reset(uint8 enable)
{
    SIUL.GPDO[190].B.PDO = (enable==1)?1:0;
}
#pragma ghs section text =".foc_code"
/**
 * @brief TIM4通道0中断服务函数 - U相下管故障
 */
void TIM4_0_U_LsFault_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim4C0Cnt_u8++;
    Temp = GTM4_TIM4.CH[0].IRQ_NOTIFY.R; 
    GTM4_TIM4.CH[0].IRQ_NOTIFY.R = Temp;
    Motor_U_LsFault_Flag = 1;   // 置位故障标志
    Hal_PwmEnableSet(0);
    GTM4.GLS[4].TIM.CH[0].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM6通道1中断服务函数 - U相上管故障
 */
void TIM6_1_U_HsFault_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim6C1Cnt_u8++;
    Temp = GTM4_TIM6.CH[1].IRQ_NOTIFY.R;
    GTM4_TIM6.CH[1].IRQ_NOTIFY.R = Temp;
    Motor_U_HsFault_Flag = 1;
    Hal_PwmEnableSet(0);
    GTM4.GLS[6].TIM.CH[1].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM6通道2中断服务函数 - V相下管故障
 */
void TIM6_2_V_LsFault_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim6C2Cnt_u8++;
    Temp = GTM4_TIM6.CH[2].IRQ_NOTIFY.R;
    GTM4_TIM6.CH[2].IRQ_NOTIFY.R = Temp;
    Motor_V_LsFault_Flag = 1;
    Hal_PwmEnableSet(0);
    GTM4.GLS[6].TIM.CH[2].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM6通道3中断服务函数 - V相上管故障
 */
void TIM6_3_V_HsFault_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim6C3Cnt_u8++;
    Temp = GTM4_TIM6.CH[3].IRQ_NOTIFY.R;
    GTM4_TIM6.CH[3].IRQ_NOTIFY.R = Temp;
    Motor_V_HsFault_Flag = 1;
    Hal_PwmEnableSet(0);
    GTM4.GLS[6].TIM.CH[3].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM6通道4中断服务函数 - W相下管故障
 */
void TIM6_4_W_LsFault_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim6C4Cnt_u8++;
    Temp = GTM4_TIM6.CH[4].IRQ_NOTIFY.R;
    GTM4_TIM6.CH[4].IRQ_NOTIFY.R = Temp;
    Motor_W_LsFault_Flag = 1;
    Hal_PwmEnableSet(0);
    GTM4.GLS[6].TIM.CH[4].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM6通道5中断服务函数 - W相上管故障
 */
void TIM6_5_W_HsFault_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim6C5Cnt_u8++;
    Temp = GTM4_TIM6.CH[5].IRQ_NOTIFY.R;
    GTM4_TIM6.CH[5].IRQ_NOTIFY.R = Temp;
    Motor_W_HsFault_Flag = 1;
    Hal_PwmEnableSet(0);
    GTM4.GLS[6].TIM.CH[5].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM6通道0中断服务函数 - V相过流
 */
void TIM6_0_V_OCP_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim6C0Cnt_u8++;
    Temp = GTM4_TIM6.CH[0].IRQ_NOTIFY.R;
    GTM4_TIM6.CH[0].IRQ_NOTIFY.R = Temp;
    // Motor_V_OverCurrent_Flag = 1;
    // Hal_PwmEnableSet(0);
    GTM4.GLS[6].TIM.CH[0].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM3通道2中断服务函数 - U相过流
 */
void TIM3_2_U_OCP_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim3C2Cnt_u8++;
    Temp = GTM4_TIM3.CH[2].IRQ_NOTIFY.R;
    GTM4_TIM3.CH[2].IRQ_NOTIFY.R = Temp;
    Motor_U_OverCurrent_Flag = 1;
    Hal_PwmEnableSet(0);
    GTM4.GLS[3].TIM.CH[2].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM6通道6中断服务函数 - W相过流
 */
void TIM6_6_W_OCP_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim6C6Cnt_u8++;
    Temp = GTM4_TIM6.CH[6].IRQ_NOTIFY.R;
    GTM4_TIM6.CH[6].IRQ_NOTIFY.R = Temp;
    Motor_W_OverCurrent_Flag = 1;
    Hal_PwmEnableSet(0);
    GTM4.GLS[6].TIM.CH[6].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM3通道3中断服务函数 - 过压故障1 (OV1)
 */
void TIM3_3_DC_OverFault1_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim3C3Cnt_u8++;
    Temp = GTM4_TIM3.CH[3].IRQ_NOTIFY.R;
    GTM4_TIM3.CH[3].IRQ_NOTIFY.R = Temp;
    Motor_OverVoltage1_Flag = 1;    
    Hal_PwmEnableSet(0);
    GTM4.GLS[3].TIM.CH[3].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM3通道4中断服务函数 - 过压故障2 (OV2)
 */
void TIM3_4_DC_OverFault2_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim3C4Cnt_u8++;
    Temp = GTM4_TIM3.CH[4].IRQ_NOTIFY.R;
    GTM4_TIM3.CH[4].IRQ_NOTIFY.R = Temp;
    Motor_OverVoltage2_Flag = 1;    
    Hal_PwmEnableSet(0);
    GTM4.GLS[3].TIM.CH[4].IRQ_EN.R = 0x0; 
}

/**
 * @brief TIM4通道7中断服务函数 - 故障自锁状态回读
 */
void TIM4_7_OCPOV_Trigger_IRQHandler(void)
{
    uint32 Temp;
    Test_Tim4C7Cnt_u8++;
    Temp = GTM4_TIM4.CH[7].IRQ_NOTIFY.R;
    GTM4_TIM4.CH[7].IRQ_NOTIFY.R = Temp;
    Motor_OCPOV_TRIGGER_Flag = 1; 

    GTM4.GLS[4].TIM.CH[7].IRQ_EN.R = 0x0; 
}


uint8_t Motor_Diag_ClearError=0;
void Motor_Diag_ClearAllFaults(void)
{
    uint8_t retry_count;
    uint8_t fault_status_high = 0U;

    for (retry_count = 0U; retry_count < 10U; retry_count++)
    {
        Motor_DiagOverCorV_Reset(0U); // 清除故障时拉低 MCU_OCP/OV_RST 引脚

        if ((GTM4.GLS[4].TIM.INP_VAL.B.TIM_IN & 0x80U) != 0U)
        {
            fault_status_high = 1U;
            break;
        }
    }

    if (fault_status_high != 0U) // TIM4 CH7 高电平，故障已清除
    {
        Motor_U_HsFault_Flag = 0;
        Motor_U_LsFault_Flag = 0;
        Motor_V_HsFault_Flag = 0;
        Motor_V_LsFault_Flag = 0;
        Motor_W_HsFault_Flag = 0;
        Motor_W_LsFault_Flag = 0;
        Motor_U_OverCurrent_Flag = 0;
        Motor_V_OverCurrent_Flag = 0;
        Motor_W_OverCurrent_Flag = 0;
        Motor_OverVoltage1_Flag = 0;
        Motor_OverVoltage2_Flag = 0;
        Motor_OCPOV_TRIGGER_Flag = 0;
        GTM4.GLS[4].TIM.CH[0].IRQ_EN.R = 0x1;
        GTM4.GLS[6].TIM.CH[1].IRQ_EN.R = 0x1;
        GTM4.GLS[6].TIM.CH[2].IRQ_EN.R = 0x1;
        GTM4.GLS[6].TIM.CH[3].IRQ_EN.R = 0x1;
        GTM4.GLS[6].TIM.CH[4].IRQ_EN.R = 0x1;
        GTM4.GLS[6].TIM.CH[5].IRQ_EN.R = 0x1;
        // GTM4.GLS[6].TIM.CH[0].IRQ_EN.R = 0x1;
        GTM4.GLS[3].TIM.CH[2].IRQ_EN.R = 0x1;
        GTM4.GLS[3].TIM.CH[3].IRQ_EN.R = 0x1;
        // GTM4.GLS[3].TIM.CH[4].IRQ_EN.R = 0x1;
        GTM4.GLS[6].TIM.CH[6].IRQ_EN.R = 0x1;
        GTM4.GLS[4].TIM.CH[7].IRQ_EN.R = 0x1;

        Motor_DiagOverCorV_Reset(1U); // 清故障后恢复 MCU_OCP/OV_RST 引脚状态
        // Hal_PwmEnableSet(1U);
    }
    else
    {
        // 三次读取均未检测到高电平，保持复位脚拉低和故障状态
        Motor_Diag_ClearError++;
    }
}


/**
 * @brief 获取U相上管故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_U_HsFault(void)
{
    return Motor_U_HsFault_Flag;
}

/**
 * @brief 获取U相下管故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_U_LsFault(void)
{
    return Motor_U_LsFault_Flag;
}

/**
 * @brief 获取V相上管故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_V_HsFault(void)
{
    return Motor_V_HsFault_Flag;
}

/**
 * @brief 获取V相下管故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_V_LsFault(void)
{
    return Motor_V_LsFault_Flag;
}

/**
 * @brief 获取W相上管故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_W_HsFault(void)
{
    return Motor_W_HsFault_Flag;
}

/**
 * @brief 获取W相下管故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_W_LsFault(void)
{
    return Motor_W_LsFault_Flag;
}

/**
 * @brief 获取U相过流故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_U_OverCurrent(void)
{
    return Motor_U_OverCurrent_Flag;
}

/**
 * @brief 获取V相过流故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_V_OverCurrent(void)
{
    return Motor_V_OverCurrent_Flag;
}

/**
 * @brief 获取W相过流故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_W_OverCurrent(void)
{
    return Motor_W_OverCurrent_Flag;
}

/**
 * @brief 获取过压故障1 (OV1) 状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_OverVoltage1(void)
{
    return Motor_OverVoltage1_Flag;
}

/**
 * @brief 获取过压故障2 (OV2) 状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_OverVoltage2(void)
{
    return Motor_OverVoltage2_Flag;
}

/**
 * @brief 获取上管退饱和故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_TOPDesatFlt(void)
{
    return Motor_TOP_DesatFlt_Flag;
}

/**
 * @brief 获取下管退饱和故障状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_BOTDesatFlt(void)
{
    return Motor_BOT_DesatFlt_Flag;
}

/**
 * @brief 获取上管欠压反馈状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_TOP_UV(void)
{
    return Motor_TOP_UV_Flag;
}

/**
 * @brief 获取上管欠压反馈状态
 * @return 0-无故障, 1-有故障
 */
uint8_t Motor_Get_BOT_UV(void)
{
    return Motor_BOT_UV_Flag;
}







#pragma ghs section
#pragma ghs section
#pragma ghs section