/*******************************************************************************
 * File Name:    RdcDrv.c
 * Author:       duqian
 * Date:         2026-04-12
 * Version:      V1.0
 * Description:  旋变解码（Resolver-to-Digital）驱动源文件。
 *               主要功能包括：
 *               - 激励载波信号生成（基于GTM PSM + ATOM）
 *               - SDADC采样缓冲区配置与调制启动
 *               - 采样时间戳捕获（用于角度同步）
 *               - SIN/COS信号包络解算（过零点检测、整流积分）
 *               - 多核数据一致性同步（基于SEMA42信号量）
 * Copyright:    Copyright(C) 2022-2026
 *               All rights reserved
 ******************************************************************************/

/******************************************************************************
 * @fileDescription: 旋变解码驱动实现，提供旋变激励、信号采集与角度解算的底层接口。
 *                   本模块依赖GTM、SDADC及SEMA42硬件资源，适用于多核电机控制系统。
 ******************************************************************************/

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "RdcDrv.h"
#include "derivative.h"
#include "common.h"
#include "Mcal.h"
#include "Mcu.h"
#include "intc_lld.h"
#include "Gpt_Irq.h"
#include "CCFC3012PT.h"
#include "SDAdc.h"
#include "SigResolverAngleDecoder.h"
#include "IoHwAbs_ADC_Cfg.h"

#pragma ghs section data =".foc_data"
// #pragma ghs section text =".foc_code"
#pragma ghs section bss =".foc_bss"



/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/



/* SIN信号采样缓存，用于DMA数据搬运 */
signed int sin_data_buf[RDCDRV_SIGNAL_FIFO_SIZE] = {0};

/* COS信号采样缓存，用于DMA数据搬运 */
signed int cos_data_buf[RDCDRV_SIGNAL_FIFO_SIZE] = {0};

/* 旋变解码设备实例1 */
RdcDrv_Dev_t RdcDrv_Dev1;

/* 电机旋变SIN包络值（s16） */
int16 Motor_RdcDrvSinValue_s16 = 0;

/* 电机旋变COS包络值（s16） */
int16 Motor_RdcDrvCosValue_s16 = 0;

/* 功能安全备份SIN包络值 */
int16 Motor_RdcDrvSinValue_s16_Fusa = 0;

/* 功能安全备份COS包络值 */
int16 Motor_RdcDrvCosValue_s16_Fusa = 0;

/* 旋变采样时间戳（32位） */
uint32 Motor_ResolverTimestamp_au32 = 0;
uint32 Motor_ResolverTimestamp_au32_Last = 0;
uint32 Diag_ResolverTimestamp_au32 = 0;

/* SDADC6 DMA 结果缓冲区（乒乓双缓冲：偶数次中断取 0-7，奇数次取 8-15） */
extern volatile uint16 Adc_valResultBufferGroup26_ARRY[16];
extern volatile uint16 Adc_valResultBufferGroup27_ARRY[8];

/* RDC 原始采样数据（谷值/峰值分离） */
RdcDrv_SampleData_t RdcDrv_SampleData;

/**
 * @brief 激励载波基波整周期波形比较值表（64点）
 * @note  用于生成正弦激励信号，数据经幅度缩放以适应PWM比较寄存器范围。
 */
const uint32_t EXC_CARDIG_Buffer[RDCDRV_CARSIGGEN_FIFO_SIZE] = {
    269, 268, 265, 261, 256, 250, 243, 235,\
    226, 217, 207, 196, 185, 173, 162, 150,\
    138, 127, 115, 104,  93,  83,  74,  65,\
     57,  50,  44,  39,  35,  32,  31,  30,\
     31,  32,  35,  39,  44,  50,  57,  65,\
     74,  83,  93, 104, 115, 127, 138, 150,\
    162, 173, 185, 196, 207, 217, 226, 235,\
    243, 250, 256, 261, 265, 268, 269, 270};    



#pragma ghs section
#pragma ghs section

#pragma ghs section text=".foc_code_fls"
/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
void RdcDrv_CarSigGenInit(void);
extern status_t GTM_LLD_SetToutSel_lld(uint32_t TOUT_NUM,  uint32_t TOUT_SEL);



// void RdcDrv_ExcPeakTrigInit(void)
// {
// 	/* ATOM3 CH7 中心对齐PWM配置                                               */
// 	/* 中心对齐模式(UDMODE=2): CN0从0→CM0→0循环计数，完整周期=CM0*2           */
// 	/* 上升沿: CN0上计数到CM1(4800)时输出翻转为高 → 1/4周期处                  */
// 	/* 下降沿: CN0下计数到CM1(4800)时输出翻转为低 → 3/4周期处                  */
// 	/* 波形:  LOW [0~1/4]  HIGH [1/4~3/4]  LOW [3/4~1周期]                     */
// 	{
// 		GTM4.GLS[0].ATOM.CH[4].CTRL.B.MODE = 2;                                                       /* SOMP模式, PWM输出 */
// 		GTM4.GLS[0].ATOM.CH[4].CTRL.B.UDMODE = 2;                                                     /* Up-down计数, 中心对齐 */
// 		GTM4.GLS[0].ATOM.CH[4].CTRL.B.SL = 1;                                                          /* 高有效: 1/4~3/4周期输出高电平 */
// 		GTM4.GLS[0].ATOM.CH[4].CTRL.B.RST_CCU0 = 0;                                                    /* CN0自由运行, 不与其它通道连锁复位 */

// 		GTM4.GLS[0].ATOM.CH[4].CN0.R = 0;                                                              /* 计数器清零 */
// 		GTM4.GLS[0].ATOM.CH[4].CM0.B.CM0 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / 2;   /* 半周期=9600, 完整周期=19200ticks */
// 		GTM4.GLS[0].ATOM.CH[4].CM1.B.CM1 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / 4;   /* 1/4周期=4800, 上升沿/下降沿比较值 */
// 		GTM4.GLS[0].ATOM.CH[4].SR0.B.SR0 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / 2;   /* CM0影子寄存器 */
// 		GTM4.GLS[0].ATOM.CH[4].SR1.B.SR1 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / 4;   /* CM1影子寄存器 */
// 	}

// 	/* TOUT引脚映射（需根据实际硬件原理图配置） */
// 	/* 参考: ATOM3 CH3使用TOUT21(TOUT_SEL=3)和TOUT16(TOUT_SEL=10) */
// 	/* GTM_LLD_SetToutSel_lld(TOUT_NUM, TOUT_SEL);                   */
//  	GTM_LLD_SetToutSel_lld(50, 2);   //PJ7,151
// 	/* AGC使能CH4 */
// 	{
// 		GTM4.GLS[0].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL4 = 2;                                              /* 使能影子寄存器更新, HOST_TRIG时SRx→CMx */
// 		GTM4.GLS[0].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL4 = 2;                                            /* 使能CH4通道 */
// 		GTM4.GLS[0].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL4 = 2;                                            /* 使能CH4 PWM输出 */
// 		GTM4.GLS[0].ATOM.AGC.GLB_CTRL.B.HOST_TRIG = 1;                                                /* 触发AGC, 所有配置立即生效 */
// 	}
// }


/*******************************************************************************
 * <@name>          RdcDrv_ExcPeakTrigInit
 * <@param>         void
 * <@return>        void
 * <@descr.>        励磁峰值触发PWM初始化。
 *                  生成一路与励磁信号同步的中心对齐PWM波：
 *                  - 上升沿对应励磁周期的1/4（正弦波最高点）
 *                  - 下降沿对应励磁周期的3/4（正弦波最低点）
 *                  用于触发励磁信号正弦波的峰值和谷值采集。
 *                  PWM模式：ATOM3 CH7, SOMP, 中心对齐(UDMODE=2, up-down计数)
 *                  PWM周期 = 300*64 = 19200 ticks（一个完整励磁周期）
 * <@note>          使用ATOM3 CH7，与激励载波共用CMU_CLK3时钟源。
 *                  TOUT引脚需根据实际硬件原理图配置。
********************************************************************************/
void RdcDrv_ExcPeakTrigInit(void)
{
	{
		GTM4.GLS[3].ATOM.CH[7].CTRL.B.MODE = 2;                                                       /* SOMP模式, PWM输出 */
		GTM4.GLS[3].ATOM.CH[7].CTRL.B.UDMODE = 0;                                                     /* Up-down计数*/
		GTM4.GLS[3].ATOM.CH[7].CTRL.B.SL = 1;                                                          /* 高有效*/
		GTM4.GLS[3].ATOM.CH[7].CTRL.B.RST_CCU0 = 0;                                                    /* CN0自由运行, 不与其它通道连锁复位 */

		GTM4.GLS[3].ATOM.CH[7].CN0.R = 0;                                                              /* 计数器清零 */
		GTM4.GLS[3].ATOM.CH[7].CM0.B.CM0 = (uint32)(RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / 2U);   /* 48us一个周期 */
		GTM4.GLS[3].ATOM.CH[7].CM1.B.CM1 = (uint32)(RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / 4U);   /* 24us时候上升沿 */
		GTM4.GLS[3].ATOM.CH[7].SR0.B.SR0 = (uint32)(RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / 2U);   /* 48us一个周期 */
		GTM4.GLS[3].ATOM.CH[7].SR1.B.SR1 = (uint32)(RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / 4U);   /* 24us时候上升沿 */
	}

 	GTM_LLD_SetToutSel_lld(37, 3);   //PO10,234
	/* AGC使能CH7（仅arm，不触发；由 CarSigGenInit 的 HOST_TRIG 与 CH3 同步启动） */
	{
		GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL7 = 2;                                              /* 使能影子寄存器更新, HOST_TRIG时SRx→CMx */
		GTM4.GLS[3].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL7 = 2;                                            /* 使能CH7通道 */
		GTM4.GLS[3].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL7 = 2;                                            /* 使能CH7 PWM输出 */
	}
}


/*******************************************************************************
 * <@name>          RdcDrv_CarSigGenInit
 * <@param>         void
 * <@return>        void
 * <@descr.>        旋变激励信号生成初始化
 * <@note>            
********************************************************************************/
void RdcDrv_CarSigGenInit(void)
{
	uint32_t fifoCnt;

	{										
		// SIUL.PCR[PA12].R = 0x0880;
		// SIUL.PCR[PA7].R = 0x0C80;	
		GTM_LLD_SetToutSel_lld(21, 3);
		GTM_LLD_SetToutSel_lld(16, 10);	

	}

	{
		GTM4.GLS[1].PSM.FIFO.CH[1].START_ADDR.R = 0x0;									/*设置FIFO传输的起始索引地址*/
		GTM4.GLS[1].PSM.FIFO.CH[1].END_ADDR.R = RDCDRV_CARSIGGEN_FIFO_SIZE * 4 - 1;		/*设置FIFO传输的结束索引地址，载波数据长度*/
		GTM4.GLS[1].PSM.FIFO.CH[1].CTRL.R = 0x9;	                                    /*使能环形buf模式*/

		GTM4.GLS[1].PSM.F2A.STR_CH[1].STR_CFG.R	= 0x50000;	                            /*设置F2A传输高字节从FIFO到ARU，即SR1，duty cycle of PWM*/

		for( fifoCnt = 0u; fifoCnt < RDCDRV_CARSIGGEN_FIFO_SIZE; fifoCnt++)				/*遍历激励载波数据*/
		{
			GTM4.GLS[1].PSM.AFD.CH[1].BUF_ACC.R = EXC_CARDIG_Buffer[fifoCnt] >> (RDCDRV_CARSIGGEN_DIV - 1);			/*初始化FIFO数据为激励载波数据*/
		}

		GTM4.GLS[1].PSM.F2A.ENABLE.B.STR1_EN = 2;										/*Enable stream 1*/
	}

	{
		GTM4_ATOM3.CH[3].CTRL.B.CLK_SRC_SR = 0u;
		GTM4.GLS[3].CMU.CLK[3].CTRL.B.CLK_CNT = 0;
		GPT_GTM_CMU_LLD_IsEnableClock(3, 1);
	}

	{
		GTM4.GLS[3].ATOM.CH[3].CTRL.R = 0x0000002A;										/* SOMP, SR1 reloaded from FIFO by ARU*/
																						/*Up counter mode*/
		GTM4.GLS[3].ATOM.CH[3].CN0.R = 0;												/*CMU_CLK0, Duty cycle active high, SOMP,CMx are reloaded when CN0=0; ARU enabled*/
		GTM4.GLS[3].ATOM.CH[3].CM1.B.CM1 = RDCDRV_CARSIGGEN_TI_EXCT_PERD / 2; 			/*设置占空比比较值PWM Duty即High Time，50%*/
		GTM4.GLS[3].ATOM.CH[3].CM0.B.CM0 = RDCDRV_CARSIGGEN_TI_EXCT_PERD; 				/*设置周期比较值PWM Period*/

		GTM4.GLS[3].ATOM.CH[3].SR1.B.SR1 = RDCDRV_CARSIGGEN_TI_EXCT_PERD / 2; 			/*设置占空比比较值影子值PWM Duty即High Time，50%*/
		GTM4.GLS[3].ATOM.CH[3].SR0.B.SR0 = RDCDRV_CARSIGGEN_TI_EXCT_PERD; 				/*设置周期比较值影子值PWM Period*/

		GTM4.GLS[3].ATOM.CH[3].RDADDR.B.RDADDR0	= 0x00A;								/*get data from PSM channel1，ARU*/

		GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2.B.DT0_3 = 1U;
		GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2.B.DT1_3 = 1U;
	}	

	{
		// GTM4.GLS[3].ATOM.CH[5].IRQ_EN.B.CCU0TC_IRQ_EN = 1;          /*使能ATOM3_5通道CCU0中断*/
		// GTM4.GLS[3].ATOM.CH[5].IRQ_EN.B.CCU1TC_IRQ_EN = 0;          /*关闭ATOM3_5通道CCU1中断*/
		// GTM4.GLS[3].ATOM.CH[5].IRQ_MODE.B.IRQ_MODE = 0;             /*设置ATOM3_5通道中断为单次触发模式*/
	}

	{
		GTM4.GLS[3].ATOM.CH[4].SOMP.B.MODE = 0x2;										/*设置TRIGER SDADC ATOM3_4*/
		GTM4.GLS[3].ATOM.CH[4].SOMP.B.SL = 1;											/*设置ATOM3_4为SOMP, Up counter mode*/
		GTM4.GLS[3].ATOM.CH[4].CTRL_SR.B.SL_SR = 1u;

		GTM4.GLS[3].ATOM.CH[4].SOMP.B.TRIGOUT = 1;
		GTM4.GLS[3].ATOM.CH[4].SOMP.B.RST_CCU0 = 0;

		GTM4.GLS[3].ATOM.CH[4].CN0.R = 0;
		GTM4.GLS[3].ATOM.CH[4].CM1.B.CM1 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / RDCDRV_SIGNAL_SAMPLE_NUM / 2; 				/*设置ATOM3_4脉宽1.5us,PWM Duty即High Time*/
		GTM4.GLS[3].ATOM.CH[4].CM0.B.CM0 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / RDCDRV_SIGNAL_SAMPLE_NUM; 					/*设置ATOM3_4周期96us，64个载波调制周期，PWM Period*/
		GTM4.GLS[3].ATOM.CH[4].SR1.B.SR1 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / RDCDRV_SIGNAL_SAMPLE_NUM / 2;
		GTM4.GLS[3].ATOM.CH[4].SR0.B.SR0 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / RDCDRV_SIGNAL_SAMPLE_NUM;

		GTM4.GLS[3].ATOM.CH[5].SOMP.B.MODE = 0x2;				/*SDADC TRIGER TimeSample ATOM3_5*/
		GTM4.GLS[3].ATOM.CH[5].SOMP.B.SL = 1;					/*设置ATOM3_4为SOMP, Up counter mode*/
		GTM4.GLS[3].ATOM.CH[5].CTRL_SR.B.SL_SR = 1u;

		GTM4.GLS[3].ATOM.CH[5].SOMP.B.TRIGOUT = 1;
		GTM4.GLS[3].ATOM.CH[5].SOMP.B.RST_CCU0 = 0;

		GTM4.GLS[3].ATOM.CH[5].CN0.R = 0;
		GTM4.GLS[3].ATOM.CH[5].CM1.B.CM1 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE /2; 										/*设置ATOM3_5脉宽1.5us,PWM Duty即High Time*/
		GTM4.GLS[3].ATOM.CH[5].CM0.B.CM0 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE; 											/*设置ATOM3_5周期96us，64个载波调制周期，PWM Period*/
		GTM4.GLS[3].ATOM.CH[5].SR1.B.SR1 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE /2;
		GTM4.GLS[3].ATOM.CH[5].SR0.B.SR0 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE;

	}

	{
		GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL4 = 2;			/*enabling update of CMx by SRx registers*/
		GTM4.GLS[3].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL4 = 2;		/*enabling ATOM3_4*/
		GTM4.GLS[3].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL4 = 2;

		GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL5 = 2;			/*enabling update of CMx by SRx registers*/
		GTM4.GLS[3].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL5 = 2;		/*enabling ATOM3_5*/
		GTM4.GLS[3].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL5 = 2;

		GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL3 = 2;			/*enabling update of CMx by SRx registers*/
		GTM4.GLS[3].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL3 = 2;		/*enabling ATOM3_3*/
		GTM4.GLS[3].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL3 = 2;
	
		GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.HOST_TRIG = 1;			/*触发使能寄存器更新生效*/
		GTM4.GLS[3].ATOM.CH[4].SR0.B.SR0 = RDCDRV_CARSIGGEN_TI_EXCT_PERD * RDCDRV_CARSIGGEN_FIFO_SIZE / RDCDRV_SIGNAL_SAMPLE_NUM / 2;
	}

}



/*******************************************************************************
 * <@name>          RdcDrv_SdadcTimestampInit
 * <@param>         void
 * <@return>        void
 * <@descr.>        初始化SDADC采样时间戳捕获功能，使用GTM的TIM模块和TBU时基，
 *                  在SDADC触发信号到来时记录精确的时间戳，供角度解码使用。
 * <@note>          时间戳用于同步旋变信号采样时刻，提高角度计算精度。
********************************************************************************/
void RdcDrv_SdadcTimestampInit(void)
{

	GTM4.GLS[0].TBU.CHEN.B.ENDIS_CH0 = 0x1;
	GTM4.GLS[0].TBU.CH0_CTRL.B.CH_CLK_SRC = 0;

	{
		GTM4.GLS[RDCDRV_SDADC_TRIG_TIMNUM].CCM.TIM_AUX_IN_SRC.R |= 1 << RDCDRV_SDADC_TRIG_TIMCH;						// TIM channel, PWM triggered:
		GTM4.GLS[RDCDRV_SDADC_TRIG_TIMNUM].TIM.IN_SRC.R |= (0x6 << (RDCDRV_SDADC_TRIG_TIMCH * 4));

		GTM4.GLS[RDCDRV_SDADC_TRIG_TIMNUM].TIM.CH[RDCDRV_SDADC_TRIG_TIMCH].CTRL.R = 0x00000005|(0 << 14)|(1 << 13);		//rising GPR0 captureTBU0
		// RdcDrv_rdcTimCh = &GTM4.GLS[RDCDRV_SDADC_TRIG_TIMNUM].TIM.CH[RDCDRV_SDADC_TRIG_TIMCH];

	}

	GTM4.GLS[0].TBU.CHEN.B.ENDIS_CH0 = 0x2;

}


/*******************************************************************************
 * <@name>          RdcDrv_DevInit
 * <@param>         void
 * <@return>        void
 * <@descr.>        旋变解码驱动总体初始化，包括：
 *                  - 配置SDADC结果缓冲区（SIN/COS通道）
 *                  - 启动SDADC调制
 *                  - 初始化时间戳捕获
 *                  - 初始化激励载波生成
 * <@note>          该函数应在系统启动时调用一次。
********************************************************************************/
void RdcDrv_DevInit(void)
{
    Sdadc_SetupResultBuffer(RDCDRV_SDADC_CHN_SIN, &sin_data_buf[0], RDCDRV_SIGNAL_FIFO_SIZE);
    Sdadc_SetupResultBuffer(RDCDRV_SDADC_CHN_COS, &cos_data_buf[0], RDCDRV_SIGNAL_FIFO_SIZE);

    Sdadc_StartModulation(RDCDRV_SDADC_CHN_COS);
    Sdadc_StartModulation(RDCDRV_SDADC_CHN_SIN);

	 RdcDrv_SdadcTimestampInit();
	 RdcDrv_ExcPeakTrigInit();   /* 先配置并arm CH7（不触发） */
	 RdcDrv_CarSigGenInit();     /* 最后统一 HOST_TRIG，使 CH3/4/5/7 同时启动 */
}

#pragma ghs section
#pragma ghs section text =".foc_code"
/*******************************************************************************
 * <@name>          RdcDrv_GetTs
 * <@param>         void
 * <@return>        uint32
 * <@descr.>        获取RDC解码的时间戳
 * <@note>
********************************************************************************/
uint32 RdcDrv_GetTs(void)
{
	uint32 ret;

	ret = GTM4.GLS[RDCDRV_SDADC_TRIG_TIMNUM].TIM.CH[RDCDRV_SDADC_TRIG_TIMCH].GPR0.B.GPR0;

	return ret;
}
#pragma ghs section


#pragma ghs section data =".rdc_data"
#pragma ghs section text =".rdc_code"
#pragma ghs section bss =".rdc_bss"
/*******************************************************************************
 * <@name>          RdcDrv_JudgeSymSin
 * <@param>         RdcDrv_Dev_t, 旋变软解实例指针
 * <@return>        void
 * <@descr.>        判定sin波形的符号序列.
 * <@note>
********************************************************************************/
void RdcDrv_JudgeSymSin(RdcDrv_Dev_t *RdcDev)
{
	uint32 SymIndex_u32 = 0U;

	for(SymIndex_u32 = 0; SymIndex_u32 < RDCDRV_SIGNAL_SAMPLE_NUM; SymIndex_u32++)		/*遍历所有采样buf里的数据*/
	{
		
		if(RdcDev->SinSampleValue_f32[SymIndex_u32] >= 0.0f)							/*判断信号的raw值是否大于0*/
		{
			RdcDev->SinValueSig_s16[SymIndex_u32] = 1;									/*对应的信号符号数组值设置为1*/
		}
		else
		{
			RdcDev->SinValueSig_s16[SymIndex_u32] = -1;									/*对应的信号符号数组值设置为-1*/
		}
	}
}


/*******************************************************************************
 * <@name>          RdcDrv_JudgeSymCos
 * <@param>         RdcDrv_Dev_t, 旋变软解实例指针
 * <@return>        void
 * <@descr.>        判定cos波形的符号序列.
 * <@note>
********************************************************************************/
void RdcDrv_JudgeSymCos(RdcDrv_Dev_t *RdcDev)
{
	uint32 SymIndex_u32 = 0U;

	for(SymIndex_u32 = 0; SymIndex_u32 < RDCDRV_SIGNAL_SAMPLE_NUM; SymIndex_u32++)		/*遍历所有采样buf里的数据*/
	{
		if(RdcDev->CosSampleValue_f32[SymIndex_u32] >= 0.0f)							/*判断信号的raw值是否大于0*/
		{
			RdcDev->CosValueSig_s16[SymIndex_u32] = 1;									/*对应的信号符号数组值设置为1*/
		}
		else
		{
			RdcDev->CosValueSig_s16[SymIndex_u32] = -1;									/*对应的信号符号数组值设置为-1*/
		}
	}
}


/*******************************************************************************
 * <@name>          RdcDrv_CalSigCrossTimesSin
 * <@param>         RdcDrv_Dev_t, 旋变软解实例指针
 * <@return>        void
 * <@descr.>        计算sin波形载波信号过零点相位点.
 * <@note>
********************************************************************************/
void RdcDrv_CalSigCrossTimesSin(RdcDrv_Dev_t *RdcDev)
{
	uint32 ValueIndex_u32 = 0U;

	// RdcDev->SinValueShiftNum_u32 = RDCDRV_SIGNAL_HALF_SAMPLE_NUM;

	for(ValueIndex_u32 = 1; ValueIndex_u32 < RDCDRV_SIGNAL_SAMPLE_NUM; ValueIndex_u32++)			/*遍历所有符号序列里的数据*/
	{

		if(RdcDev->SinValueSig_s16[ValueIndex_u32] != RdcDev->SinValueSig_s16[ValueIndex_u32-1])	/*判断前后2次符号数据是否不同，即判断是否过零*/
		{
			RdcDev->SinValueSigCrossTimes_u8 += 1;													/*过零点计数值自增1*/
		}
		else
		{

		}

		if(RdcDev->SinValueSigCrossTimes_u8 == 2u)													/*判断过零点计数值是否为2，即判断是否为第2次过零，判断单边*/
		{
			RdcDev->SinValueShiftNum_u32 = ValueIndex_u32;											/*记录发生第2次过零点的buf数组索引*/

			break;
		}
		else
		{

		}
	}
}


/*******************************************************************************
 * <@name>          RdcDrv_CalSigCrossTimesCos
 * <@param>         RdcDrv_Dev_t, 旋变软解实例指针
 * <@return>        void
 * <@descr.>        计算cos波形载波信号过零点相位点.
 * <@note>
********************************************************************************/
void RdcDrv_CalSigCrossTimesCos(RdcDrv_Dev_t *RdcDev)
{
	uint32 ValueIndex_u32 = 0U;

	// RdcDev->CosValueShiftNum_u32 = RDCDRV_SIGNAL_HALF_SAMPLE_NUM;

	for(ValueIndex_u32 = 1; ValueIndex_u32 < RDCDRV_SIGNAL_SAMPLE_NUM; ValueIndex_u32++)			/*遍历所有符号序列里的数据*/
	{

		if(RdcDev->CosValueSig_s16[ValueIndex_u32] != RdcDev->CosValueSig_s16[ValueIndex_u32-1])	/*判断前后2次符号数据是否不同，即判断是否过零*/
		{
			RdcDev->CosValueSigCrossTimes_u8 += 1;													/*过零点计数值自增1*/
		}
		else
		{

		}

		if(RdcDev->CosValueSigCrossTimes_u8 == 2u)													/*判断过零点计数值是否为2，即判断是否为第2次过零，判断单边*/
		{
			RdcDev->CosValueShiftNum_u32 = ValueIndex_u32;											/*记录发生第2次过零点的buf数组索引*/

			break;
		}
		else
		{

		}
	}
}


#if 1
/*******************************************************************************
 * <@name>          RdcDrv_CalSinValue
 * <@param>         RdcDrv_Dev_t, 旋变软解实例指针
 * <@return>        void
 * <@descr.>        计算sin波形包络线值，对数据整流反转并积分缩放.
 * <@note>
********************************************************************************/
void RdcDrv_CalSinValue(RdcDrv_Dev_t *RdcDev)
{
    uint32_t i;
    const uint32_t shift = RdcDev->SinValueShiftNum_u32;
    const uint32_t half = RDCDRV_SIGNAL_HALF_SAMPLE_NUM;
    const uint32_t total = RDCDRV_SIGNAL_SAMPLE_NUM;
    const float * const pSample = RdcDev->SinSampleValue_f32;
    const float * const pShift = RdcDev->ShiftSinValue_f32;
    float sum = 0.0f;

    for (i = 0; i < total; i++) {
        if (i < shift - half) {
            sum += pSample[i];       
        } else if (i < shift) {
            sum -= pSample[i];      
        } else {
            sum += pShift[i];        
        }
    }

    RdcDev->SinSdadcGain_f32 = 4.0f;   // TODO: sin增益值暂时赋值0.25
    RdcDev->SinValue_f32 = RDCDRV_CFG_INTEGCOEF * sum * RdcDev->SinSdadcGain_f32;
}

/*******************************************************************************
 * <@name>          RdcDrv_CalCosValue
 * <@param>         RdcDrv_Dev_t, 旋变软解实例指针
 * <@return>        void
 * <@descr.>        计算cos波形包络线值，对数据整流反转并积分缩放.
 * <@note>
********************************************************************************/
void RdcDrv_CalCosValue(RdcDrv_Dev_t *RdcDev)
{
    uint32_t i;
    const uint32_t shift = RdcDev->CosValueShiftNum_u32;
    const uint32_t half = RDCDRV_SIGNAL_HALF_SAMPLE_NUM;
    const uint32_t total = RDCDRV_SIGNAL_SAMPLE_NUM;
    const float * const pSample = RdcDev->CosSampleValue_f32;
    const float * const pShift = RdcDev->ShiftCosValue_f32;
    float sum = 0.0f;

    for (i = 0; i < total; i++) {
        if (i < shift - half) {
            sum += pSample[i];
        } else if (i < shift) {
            sum -= pSample[i];
        } else {
            sum += pShift[i];
        }
    }

    RdcDev->CosSdadcGain_f32 = 4.0f;   // TODO: cos增益值暂时赋值0.25
    RdcDev->CosValue_f32 = RDCDRV_CFG_INTEGCOEF * sum * RdcDev->CosSdadcGain_f32;
}

#else

/*******************************************************************************
 * <@name>          RdcDrv_CalSinValue
 * <@param>         RdcDrv_Dev_t, 旋变软解实例指针
 * <@return>        void
 * <@descr.>        计算sin波形包络线值，对数据整流反转并积分缩放.
 * <@note>
********************************************************************************/
void RdcDrv_CalSinValue(RdcDrv_Dev_t *RdcDev)
{
	uint32 ValueIndex_u32 = 0U;

	RdcDev->SinValue_f32 = 0.0F;
	RdcDev->SinSdadcGain_f32 = 4.0f;//TODO:sin增益值暂时赋值0.25

	for(ValueIndex_u32 = RdcDev->SinValueShiftNum_u32; ValueIndex_u32 < RDCDRV_SIGNAL_SAMPLE_NUM; ValueIndex_u32++)				/*遍历第2个过零点到buf结尾的采样raw值*/
	{
		RdcDev->SinValue_f32 += (RdcDev->ShiftSinValue_f32[ValueIndex_u32]);													/*不反转，并累加采样raw值*/
	}

	for(ValueIndex_u32 = 0; ValueIndex_u32 < RdcDev->SinValueShiftNum_u32 - RDCDRV_SIGNAL_HALF_SAMPLE_NUM; ValueIndex_u32++)	/*遍历buf第一个元素到第1个过零点的采样raw值*/
	{
		RdcDev->SinValue_f32 += (RdcDev->SinSampleValue_f32[ValueIndex_u32]);													/*不反转，继续累加采样raw值*/
	}

	for(ValueIndex_u32 = RdcDev->SinValueShiftNum_u32 - RDCDRV_SIGNAL_HALF_SAMPLE_NUM; ValueIndex_u32 < RdcDev->SinValueShiftNum_u32; ValueIndex_u32++)	/*遍历第1个过零点到第2个过零点间的采样raw值*/
	{
		RdcDev->SinValue_f32 += (-RdcDev->SinSampleValue_f32[ValueIndex_u32]);													/*符号取反，继续累加采样raw值*/
	}

	RdcDev->SinValue_f32 = RDCDRV_CFG_INTEGCOEF * (RdcDev->SinValue_f32) * (RdcDev->SinSdadcGain_f32);							/*对积分后的值进行缩放*/
}


/*******************************************************************************
 * <@name>          RdcDrv_CalCosValue
 * <@param>         RdcDrv_Dev_t, 旋变软解实例指针
 * <@return>        void
 * <@descr.>        计算cos波形包络线值，对数据整流反转并积分缩放.
 * <@note>
********************************************************************************/
void RdcDrv_CalCosValue(RdcDrv_Dev_t *RdcDev)
{
	uint32 ValueIndex_u32 = 0U;

	RdcDev->CosValue_f32 = 0.0F;
	RdcDev->CosSdadcGain_f32 = 4.0f;//TODO:cos增益值暂时赋值0.25

	for(ValueIndex_u32 = RdcDev->CosValueShiftNum_u32; ValueIndex_u32 < RDCDRV_SIGNAL_SAMPLE_NUM; ValueIndex_u32++)				/*遍历第2个过零点到buf结尾的采样raw值*/
	{
		RdcDev->CosValue_f32 += (RdcDev->ShiftCosValue_f32[ValueIndex_u32]);													/*不反转，并累加采样raw值*/
	}

	for(ValueIndex_u32 = 0; ValueIndex_u32 < RdcDev->CosValueShiftNum_u32-RDCDRV_SIGNAL_HALF_SAMPLE_NUM; ValueIndex_u32++)		/*遍历buf第一个元素到第1个过零点的采样raw值*/
	{
		RdcDev->CosValue_f32 += (RdcDev->CosSampleValue_f32[ValueIndex_u32]);													/*不反转，继续累加采样raw值*/
	}

	for(ValueIndex_u32 = RdcDev->CosValueShiftNum_u32 - RDCDRV_SIGNAL_HALF_SAMPLE_NUM; ValueIndex_u32 < RdcDev->CosValueShiftNum_u32; ValueIndex_u32++)	/*遍历第1个过零点到第2个过零点间的采样raw值*/
	{
		RdcDev->CosValue_f32 += (-RdcDev->CosSampleValue_f32[ValueIndex_u32]);													/*符号取反，继续累加采样raw值*/
	}

	RdcDev->CosValue_f32 = RDCDRV_CFG_INTEGCOEF * (RdcDev->CosValue_f32) * (RdcDev->CosSdadcGain_f32);							/*对积分后的值进行缩放*/
}
#endif

/*******************************************************************************
 * <@name>          RdcDrv_CalShiftNum
 * <@param>         RdcDrv_Dev_t, 旋变软解实例指针
 * <@return>        void
 * <@descr.>        计算旋变反馈波形过零点位置，来齐sin和cos的过零点.
 * <@note>
********************************************************************************/
void RdcDrv_CalShiftNum(RdcDrv_Dev_t *RdcDev)
{
	RdcDev->SelfStudyState = RdcDrv_SelfStudy_Ongoing;																	/*置位过零点学习进行中标志*/
	RdcDev->SinValueSigCrossTimes_u8 = 0U;
	RdcDev->CosValueSigCrossTimes_u8 = 0U;
	RdcDev->FuncError_u32 = 0U;

	RdcDrv_JudgeSymSin(RdcDev);																							/*分别标记sin和cos反馈信号buf里各采样值的符号*/
	RdcDrv_JudgeSymCos(RdcDev);

	RdcDrv_CalSigCrossTimesSin(RdcDev);																					/*分别计算sin和cos反馈信号的过零点位置索引*/
	RdcDrv_CalSigCrossTimesCos(RdcDev);

	if(RdcDev->SinSampleValue_f32[RdcDev->SinValueShiftNum_u32-RDCDRV_CFG_VALUEMAXID] > RDCDRV_CFG_AMPVALIDP\
	|| RdcDev->SinSampleValue_f32[RdcDev->SinValueShiftNum_u32-RDCDRV_CFG_VALUEMAXID] < RDCDRV_CFG_AMPVALIDN)			/*判断sin反馈信号最大幅值的raw值是否满足幅值有效值的要求*/
	{
		RdcDev->SinValueShiftNum_u32 = RdcDev->SinValueShiftNum_u32;													/*sin和cos反馈信号的过零点位置索引都拉齐到sin反馈信号的过零点*/
		RdcDev->CosValueShiftNum_u32 = RdcDev->SinValueShiftNum_u32;
	}
	else if(RdcDev->CosSampleValue_f32[RdcDev->CosValueShiftNum_u32-RDCDRV_CFG_VALUEMAXID] > RDCDRV_CFG_AMPVALIDP\
	|| RdcDev->CosSampleValue_f32[RdcDev->CosValueShiftNum_u32-RDCDRV_CFG_VALUEMAXID] < RDCDRV_CFG_AMPVALIDN)			/*判断cos反馈信号最大幅值的raw值是否满足幅值有效值的要求*/
	{
		RdcDev->CosValueShiftNum_u32 = RdcDev->CosValueShiftNum_u32;													/*sin和cos反馈信号的过零点位置索引都拉齐到cos反馈信号的过零点*/
		RdcDev->SinValueShiftNum_u32 = RdcDev->CosValueShiftNum_u32;
	}
	else
	{
		RdcDev->FuncError_u32 |= RDCDRV_SINCOSAMPERROR;																	/*sin和cos反馈信号的幅值均不满足时，置位旋变采样故障*/
	}

	if(RdcDev->SinValueShiftNum_u32 < RDCDRV_SIGNAL_HALF_SAMPLE_NUM)													/*判断sin反馈信号过零点位置索引是否小于采样数的一半*/
	{
		// RdcDev->SinValueShiftNum_u32 = RDCDRV_SIGNAL_HALF_SAMPLE_NUM;
		RdcDev->FuncError_u32 |= RDCDRV_SINSIGCHANGETIMEERROR;															/*置位sin过零点检测故障*/
	}
	else
	{

	}

	if(RdcDev->CosValueShiftNum_u32 < RDCDRV_SIGNAL_HALF_SAMPLE_NUM)													/*判断cos反馈信号过零点位置索引是否小于采样数的一半*/
	{
		// RdcDev->CosValueShiftNum_u32 = RDCDRV_SIGNAL_HALF_SAMPLE_NUM;
		RdcDev->FuncError_u32 |= RDCDRV_COSSIGCHANGETIMEERROR;															/*置位cos过零点检测故障*/
	}
	else
	{

	}

	if(RdcDev->FuncError_u32 == 0U)							/*判断过零点位置学习过程中是否有故障产生*/
	{
		RdcDev->SelfStudyState = RdcDrv_SelfStudy_Done;		/*置位过零点学习完成标志*/
	}
	else
	{
		RdcDev->SelfStudyState = RdcDrv_SelfStudy_Fail;		/*置位过零点学习失败标志*/
	}
}


/*******************************************************************************
 * <@name>          RdcDrv_GetPos
 * <@param>         sint16, sin信号的接口指针
 * <@param>         sint16, cos信号的接口指针
 * <@return>        void
 * <@descr.>        读取旋变sin和cos反馈信号包络线的raw值，应在SDADC整周期中断ISR中调用.
 * <@note>
********************************************************************************/
void RdcDrv_GetPos(RdcDrv_Dev_t *RdcDev, sint16 *SinValue_s16, sint16 *CosValue_s16)
{
	uint32* TimeStamp_ptr;
	uint16* SinValue_pu16;
	uint16* CosValue_pu16;
	float32 SinValue_f32 = 0.0F;
	float32 CosValue_f32 = 0.0F;
	uint32 CoreId_u32 = 0U;
	uint32 ValueIndex_u32 = 0U;
	uint32 tmpTimeStamp;

	// RdcDev->TimeStamp_u32 = TimeStamp_ptr[0] & RDCDRV_TIMESTAMPGPR_MASK;
	// tmpTimeStamp = RdcDrv_GetTs();																	/*读取SDADC时间戳*/
	// RdcDev->TimeStamp_u32 = tmpTimeStamp & RDCDRV_TIMESTAMPGPR_MASK;

	if((SinValue_s16 != RDCDRV_NULL_PTR) && (CosValue_s16 != RDCDRV_NULL_PTR))						/*判断sin和cos的接口指针是否有效*/
	{
		if(RdcDev->StudyCount_u32 > RDCDRV_CFG_WAITTIME)											/*判断过零点自学习是否达到等待时间*/
		{
			for(ValueIndex_u32 = 0; ValueIndex_u32 < RDCDRV_SIGNAL_SAMPLE_NUM; ValueIndex_u32++)	/*遍历buf的所有元素*/
			{

				RdcDev->SinSampleValue_f32[ValueIndex_u32] =  (float32)(sint16)(sin_data_buf[ValueIndex_u32]);	/*将buf的DMA搬运的所有元素读取到临时缓存*/
				RdcDev->CosSampleValue_f32[ValueIndex_u32] =  (float32)(sint16)(cos_data_buf[ValueIndex_u32]);

			}

			if(RdcDev->SelfStudyState == RdcDrv_SelfStudy_Done)										/*判断过零点自学习是否完成*/
			{
				RdcDrv_CalSinValue(RdcDev);															/*计算sin和cos波形包络线值，对数据整流反转并积分缩放*/
				RdcDrv_CalCosValue(RdcDev);

				*SinValue_s16 = (sint16)RdcDev->SinValue_f32;										/*将积分后的sin和cos波形包络线raw值返回给接口*/
				*CosValue_s16 = (sint16)RdcDev->CosValue_f32;




				for(ValueIndex_u32 = RdcDev->SinValueShiftNum_u32; ValueIndex_u32 < RDCDRV_SIGNAL_SAMPLE_NUM; ValueIndex_u32++)		/*Save the shift sin data*/
				{
					RdcDev->ShiftSinValue_f32[ValueIndex_u32] = RdcDev->SinSampleValue_f32[ValueIndex_u32];
				}
				
				for(ValueIndex_u32 = RdcDev->CosValueShiftNum_u32; ValueIndex_u32 < RDCDRV_SIGNAL_SAMPLE_NUM; ValueIndex_u32++)		/*Save the shift cos data*/
				{
					RdcDev->ShiftCosValue_f32[ValueIndex_u32] = RdcDev->CosSampleValue_f32[ValueIndex_u32];
				}
			}
			else
			{
				RdcDrv_CalShiftNum(RdcDev);			/*计算旋变反馈波形过零点位置，来齐sin和cos的过零点*/
				
				*SinValue_s16 = 0;					/*接口返回初始值*/
				*CosValue_s16 = 0;
			}
		}
		else
		{
			RdcDev->StudyCount_u32++;				/*过零点自学习计时计数寄存器自加*/

			*SinValue_s16 = 0;						/*接口返回初始值*/
			*CosValue_s16 = 0;
		}
		RdcDev->ParameterStu_u8 = RDCDRV_OK;
	}
	else
	{
		RdcDev->ParameterStu_u8 = RDCDRV_NOT_OK;
		RdcDev->LogicError_u32 |= RDCDRV_GETPOS_PARAERROR;
	}	
}

/*******************************************************************************
 * <@name>          Motor_RdcDrvGetPos_100us
 * <@param>         void
 * <@return>        void
 * <@descr.>        在SDADC—DMA完成中断中调用，获取旋变sin和cos包络值，
 *                  并存储到全局变量Motor_RdcDrvSinValue_s16和Motor_RdcDrvCosValue_s16中。
 * <@note>          该函数应被周期调用，通常由SDADC—DMA完成中断触发。
********************************************************************************/
void Motor_RdcDrvGetPos_100us(void)
{
    RdcDrv_GetPos(&RdcDrv_Dev1, &Motor_RdcDrvSinValue_s16, &Motor_RdcDrvCosValue_s16);
}

#pragma ghs section
#pragma ghs section
#pragma ghs section



#pragma ghs section data =".foc_data"
#pragma ghs section text =".foc_code"
#pragma ghs section bss =".foc_bss"

/* 全局信号量定义 */
volatile uint32 g_rdcSemA = 0;   /* （core3）占用标志 */
volatile uint32 g_rdcSemB = 0;   /* （core5）占用标志 */
extern float SGRD_OmegaRaw ;
extern float SGRD_ThetaRaw ;
extern float SGRD_SinEnvelope_New;
extern float SGRD_CosEnvelope_New;

#define GetCoreID() ((uint16) MFSPR(286))
/*******************************************************************************
 * <@name>          get_master_id
 * <@param>         void
 * <@return>        uint32  返回当前运行的核心对应的主ID编号
 * <@descr.>        获取当前代码运行的核心ID，并将其映射为SEMA42门控所需的master ID。
 *                  映射关系：Core0->0, Core1->1, Core2->2, Core3->6, Core4->7, Core5->13。
 * <@note>          该函数通过读取特殊功能寄存器获取核心ID，用于信号量操作。
********************************************************************************/
uint32 get_master_id(void)
{
    uint8 master = 0;
    switch (GetCoreID())
    {
        case 0:
            master = 0;
            break;
        case 1:
            master = 1;
            break;
        case 2:
            master = 2;
            break;
        case 3:
            master = 6;
            break;
        case 4:
            master = 7;
            break;
        case 5:
            master = 13;
            break;
        default:
           master = 0;
		   break;
    }
    return master;
}

/*******************************************************************************
 * <@name>          Get_Gate_status
 * <@param>         volatile uint8_t gate_no  门控编号（信号量ID）
 * <@return>        volatile uint8_t  返回该门控的当前状态值
 * <@descr.>        读取指定门控（信号量）的当前状态。
 *                  状态值表示当前占用该门控的主设备ID（若为0则空闲）。
 * <@note>          该函数直接读取硬件寄存器，不涉及原子操作。
********************************************************************************/
volatile uint8 Get_Gate_status(volatile uint8_t gate_no)
{
    return SEMA42.GATE[gate_no].R;
}


/*******************************************************************************
 * <@name>          Lock_Gate
 * <@param>         volatile uint8_t gate_no  门控编号（信号量ID）
 * <@return>        volatile uint8_t  返回锁定后的门控状态（应等于当前主ID+1）
 * <@descr.>        尝试锁定指定门控。若门控空闲，则将当前核心的master ID写入，
 *                  成功获取信号量；若已被占用，写入无效，返回原状态。
 * <@note>          使用时需配合 Get_Gate_status 检查是否锁定成功。
********************************************************************************/
volatile uint8 Lock_Gate(volatile uint8_t gate_no)
{
    SEMA42.GATE[gate_no].R = get_master_id()+1;

    return Get_Gate_status(gate_no);
}


/*******************************************************************************
 * <@name>          Unlock_Gate
 * <@param>         volatile uint8_t gate_no  门控编号（信号量ID）
 * <@return>        volatile uint8_t  返回解锁后的门控状态（应为0）
 * <@descr.>        释放指定门控（信号量），将门控状态清零。
 * <@note>          仅当持有该信号量的核心调用此函数才有效，否则可能破坏同步。
********************************************************************************/
volatile uint8 Unlock_Gate(volatile uint8_t gate_no)
{
    SEMA42.GATE[gate_no].R = UNLOCK;

    return Get_Gate_status(gate_no);
}

uint32 Core3_Cnt = 0;
uint32 Core3_else_Cnt = 0;
extern float SGRD_OmegaRaw_Last;
extern float SGRD_ThetaRaw_Last;

void Motor_PosUpdata_Function(void)
{
	uint8_t master;
	master = get_master_id() + 1;
	Lock_Gate(SEMAPHORES_GATE_NO);
	if(master == Get_Gate_status(SEMAPHORES_GATE_NO))//空闲状态
	{
		Motor_ResolverTimestamp_au32 = RdcDrv_Dev1.TimeStamp_u32;/*读取旋变采样时间戳*/
		SGRD_NewEstTheta = SGRD_ThetaRaw;
		SGRD_NewEstOmega = SGRD_OmegaRaw;
		if (Motor_ResolverTimestamp_au32 != RdcDrv_Dev1.TimeStamp_u32)/*如果旋变采样时间戳有更新，则重新更新*/
		{
			SGRD_NewEstTheta = SGRD_ThetaRaw;
			SGRD_NewEstOmega = SGRD_OmegaRaw;
			Motor_ResolverTimestamp_au32 = RdcDrv_Dev1.TimeStamp_u32;/*读取旋变采样时间戳*/
			SGRD_SinEnvelope = SGRD_SinEnvelope_New;
 			SGRD_CosEnvelope = SGRD_CosEnvelope_New;
		}
		Core3_Cnt++;
		Unlock_Gate(SEMAPHORES_GATE_NO);			
	}
	else
	{
		Core3_else_Cnt++;
		if (Motor_ResolverTimestamp_au32 != Motor_ResolverTimestamp_au32_Last)
		{
			SGRD_NewEstOmega = SGRD_OmegaRaw_Last;
			SGRD_NewEstTheta = SGRD_ThetaRaw_Last;
			Motor_ResolverTimestamp_au32 = Motor_ResolverTimestamp_au32_Last;
		}

	}
}

/**
 * @brief 将 SDADC6 的 DMA 结果赋值到全局采样结构体
 * @details 乒乓双缓冲：奇数次中断取数组 8-15（Group26 取 4-7），
 *          偶数次中断取数组 0-7（Group26 取 0-3）。
 *          每个 8 元组内：0-3 为谷值（4通道），4-7 为峰值（4通道）。
 */
void RdcDrv_StoreAdcResult(void)
{
    static uint8 oddInterrupt = 1u;   /* 奇数次中断标志，首次进入为奇数 */
    static RdcDrv_SampleData_t prevSample[2];   /* [0]偶数半区 / [1]奇数半区 上次结果 */
    static uint8 prevValid[2] = {0u, 0u};       /* 对应半区是否已有历史数据 */
    uint8 bank = (oddInterrupt != 0u) ? 1u : 0u;   /* 当前读取的乒乓半区 */
    uint8 sincosBase = (oddInterrupt != 0u) ? 8u : 0u;
    uint8 excBase    = (oddInterrupt != 0u) ? 4u : 0u;

	/* 谷值样本：励磁正弦波最低点，4+2 通道 */
	RdcDrv_SampleData.CospValley_u16 = Adc_valResultBufferGroup26_ARRY[sincosBase + 0u];
	RdcDrv_SampleData.CosnPeak_u16 = Adc_valResultBufferGroup26_ARRY[sincosBase + 1u];
	RdcDrv_SampleData.SinpValley_u16 = Adc_valResultBufferGroup26_ARRY[sincosBase + 2u];
	RdcDrv_SampleData.SinnPeak_u16 = Adc_valResultBufferGroup26_ARRY[sincosBase + 3u];
	RdcDrv_SampleData.ExcnPeak_u16  = Adc_valResultBufferGroup27_ARRY[excBase + 0u];
	RdcDrv_SampleData.ExcpValley_u16 = Adc_valResultBufferGroup27_ARRY[excBase + 1u];

	/* 峰值样本：励磁正弦波最高点，4+2 通道 */
	RdcDrv_SampleData.CospPeak_u16 = Adc_valResultBufferGroup26_ARRY[sincosBase + 4u];
	RdcDrv_SampleData.CosnValley_u16 = Adc_valResultBufferGroup26_ARRY[sincosBase + 5u];
	RdcDrv_SampleData.SinpPeak_u16 = Adc_valResultBufferGroup26_ARRY[sincosBase + 6u];
	RdcDrv_SampleData.SinnValley_u16 = Adc_valResultBufferGroup26_ARRY[sincosBase + 7u];
	RdcDrv_SampleData.ExcnValley_u16 = Adc_valResultBufferGroup27_ARRY[excBase + 2u];
	RdcDrv_SampleData.ExcpPeak_u16 = Adc_valResultBufferGroup27_ARRY[excBase + 3u];

	prevSample[bank] = RdcDrv_SampleData;  /* 保存本次结果，供下一轮同半区比较 */
	prevValid[bank] = 1u;
	oddInterrupt ^= 1u;   /* 翻转奇偶标志 */
}




#pragma ghs section
#pragma ghs section
#pragma ghs section




