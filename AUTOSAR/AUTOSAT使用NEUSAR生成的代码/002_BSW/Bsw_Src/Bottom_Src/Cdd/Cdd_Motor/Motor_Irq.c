#include "Platform_Types.h"
#include "Mcal.h"
#include "CCFC3012PT.h"
#include "RdcDrv.h"
#include "SigSignalAdapter.h"
#include "SigResolverAngleDecoder.h"
#include "SigPreProcessor.h"
#include "Adc3ph.h"
#include "Xcp_Swc.h"
#include "VX1000If.h"
#include "Task_App_Core3.h"
#include "Motor_HwIf.h"
#include "intc_lld.h"
#include "Motor_Diag.h"
#ifdef MOTORCTRL_TEST
#include "McuFunSafeMonitor.h"
#include "AswAdapter.h"
#include "CtlCurrentRegulator.h"
#include "CtlStateOrchestrator.h"
#include "FltFaultDiagnoser.h"
#include "SrvOpenLoopService.h"
#include "TrfDQToAlphaBeta.h"
#include "TrfInverterErrorComp.h"
#include "TrfPhaseToDQ.h"
#include "TrfPWMModulator.h"
#else

#endif


#define STM_DIFF(start, end)   ((end) > (start) ? ((end) - (start)) : (0xFFFFFFFFU - (start) + (end) + 1U))


#pragma ghs section data =".foc_data"
#pragma ghs section text =".foc_code"
#pragma ghs section bss =".foc_bss"


float SGRD_OmegaRaw =0;
float SGRD_ThetaRaw =0;
float SGRD_OmegaRaw_Last =0;
float SGRD_ThetaRaw_Last =0;
float SGRD_SinEnvelope_New = 0;
float SGRD_CosEnvelope_New = 0;
extern uint32 Motor_ResolverTimestamp_au32_Last;
uint8 Test_Atom0C6Cnt_u8 = 0;       /*FOC中断计数*/

uint32 Foc_Sch_StartCnt = 0;
uint32 Foc_Sch_EndCnt = 0;
uint32 Foc_Sch_CycleCnt = 0;
extern volatile uint32 g_rdcSemA;   
extern volatile uint32 g_rdcSemB; 
extern int16 Motor_RdcDrvSinValue_s16 ;
extern int16 Motor_RdcDrvCosValue_s16 ;
uint8 Motor_Rctrl_Cnt = 0;
uint16 focarray[32] = {0};
uint8 focindex = 0;

/**
 * @brief FOC 控制中断服务函数（ATOM0 通道 6 触发）
 * @details 根据驱动状态执行不同任务：
 *          - 状态 2（运行）：读取 ADC 电流，更新位置/角度/速度，执行电流环及 PWM 调制；
 *          - 状态 1（就绪）：仅读取 ADC 并校正零漂；
 *          - 状态 0（初始化）：清除 ADC 标志，清除故障并切至状态 1。
 *          同时记录任务执行时间用于性能监控，测试模式下触发 VX1000 事件。
 * @note  中断周期通常为 100 µs，内部操作 ADC 时临时禁用中断以避免冲突。
 *        共享数据（角度、速度等）通过信号量保护，确保多核一致性。
 */
// uint16 VDD5REF_Ch5_Adc = 0;
// uint16 VDD5REF_Ch1_Adc = 0;
// uint16 VDD5REF_Ch4_Adc = 0;
// uint16 VDD5REF_Ch3_Adc = 0;
// uint16 VDD5REF_Ch6_Adc = 0;
// uint16 VDD5REF_Ch2_Adc = 0;

void ATOM0_6_FOC_IRQHandler(void)
{
	Foc_Sch_StartCnt = Gpt_Stm_LLD_GetCounter(STM0);
	if(Motor_DriveState_u8 == 2)
	{		
		Motor_PosUpdata_Function();//放上面以后测试试一试
		INTC_LLD_Set_IRQ_Disable(229);
		Adc3ph_MainFunction(3);
		Adc3ph_SafetyMainFunction(0);

		// VDD5REF_Ch5_Adc = VDD5REF_AN1[0];
		// VDD5REF_Ch1_Adc = VDD5REF_AN1[1];
		// VDD5REF_Ch4_Adc = VDD5REF_AN1[2];
		// VDD5REF_Ch3_Adc = VDD5REF_AN0[0];
		// VDD5REF_Ch6_Adc = VDD5REF_AN0[1];
		// VDD5REF_Ch2_Adc = VDD5REF_AN0[2];

		Motor_Adc3phGetRaw_100us();
		INTC_LLD_Set_IRQ_Enable(229);
		SGRD_CalcElecAngle_100us();
		SGSA_Read_100us();
		SGPP_Read_100us();
		
		#ifdef MOTORCTRL_TEST
		CTSO_ControlPwmState_100us();
		FLDG_DiagCurrentFast_100us();
		TFPD_ClarkeParkTransform_100us();
		SVOL_CalcAlphaBetaVolt_100us();
		CTCR_RegulateCurrent_100us();
		TFDA_InvParkTransform_100us();
		TFEC_CompInverterError_100us();
		TFPM_ModulatePwm_100us();
		ASWA_WriteProcess_100us();	
		#else
		Core3_Runnable_App_100us();
		#endif

		SGPP_ReadCmd_100us();	
		SGSA_WriteCommand_100us();
	}
	else if(Motor_DriveState_u8 == 1)
	{
		INTC_LLD_Set_IRQ_Disable(229);
		Adc3ph_MainFunction(3);
		Adc3ph_SafetyMainFunction(0);
		Motor_Adc3phGetRaw_100us();
		INTC_LLD_Set_IRQ_Enable(229);
		Motor_Adc3ph_ZeroDrift_Function();
	}
	else if(Motor_DriveState_u8 == 0)
	{
		INTC_LLD_Set_IRQ_Disable(229);
		Adc3ph_ClearRFifoEvent(3);
		Adc3ph_ClearRFifoEvent(0);
		INTC_LLD_Set_IRQ_Enable(229);
		Motor_Diag_ClearAllFaults();
		Motor_DriveState_u8=1;
	}
	Foc_Sch_EndCnt = Gpt_Stm_LLD_GetCounter(STM0);
	Foc_Sch_CycleCnt = Foc_Sch_EndCnt - Foc_Sch_StartCnt;
	focarray[focindex] = Foc_Sch_CycleCnt; 
	focindex = (focindex + 1)&0x1F;
	#ifdef MOTORCTRL_TEST
	VX1000If_Event(0x1);
	#else
	VX1000If_Event(0x1);
	#endif




	GTM4_ATOM0.CH[6].IRQ_NOTIFY.R = 3;
    Test_Atom0C6Cnt_u8++; 
}
#pragma ghs section
#pragma ghs section
#pragma ghs section





#pragma ghs section data =".rdc_data"
#pragma ghs section text =".rdc_code"
#pragma ghs section bss =".rdc_bss"


uint32 Core5_Cnt = 0;
uint32 rdcarray[32] = {0};
uint8 rdcindex = 0;
uint8 Sdadc6_Dma_Timeout_Flag = 0;


/**
 * @brief 清除 DMA 中断标志（CDNE 和 CINT）
 */
static inline void clearSdadcDmaInterrupts(void) {
    eDMA_1.CDNE.R = 0;
    eDMA_1.CDNE.R = 1;
    eDMA_1.CINT.R = 0;
    eDMA_1.CINT.R = 1;
}

/**
 * @brief 更新全局共享数据（受信号量保护）
 * @param timestamp 从 RdcDrv 读取的时间戳
 */
static void Update_shared_data(uint32_t timestamp) 
{
    uint8_t master = get_master_id() + 1;

	SGRD_OmegaRaw_Last = SGRD_OmegaRaw;
	SGRD_ThetaRaw_Last = SGRD_ThetaRaw;
	Motor_ResolverTimestamp_au32_Last = RdcDrv_Dev1.TimeStamp_u32;
    // 自旋等待获取信号量
    Lock_Gate(SEMAPHORES_GATE_NO);
    while (Get_Gate_status(SEMAPHORES_GATE_NO) != master) {
        Lock_Gate(SEMAPHORES_GATE_NO);			/* 自旋等待读者释放 SEMA42 */
    }

    // 写入共享变量
    RdcDrv_Dev1.TimeStamp_u32 = timestamp;
    SGRD_OmegaRaw = SGRD_EstOmega;
    SGRD_ThetaRaw = SGRD_EstTheta;
    SGRD_SinEnvelope_New = Motor_RdcDrvSinValue_s16;
    SGRD_CosEnvelope_New = Motor_RdcDrvCosValue_s16;

    Unlock_Gate(SEMAPHORES_GATE_NO);
}


/**
 * @brief SDADC DMA 传输完成中断服务函数
 * @details 获取采样时间戳，等待DMA完成（带超时），更新SIN/COS包络，
 *          调用角度观测器，将结果通过信号量保护写入全局共享变量。
 * @note 运行于中断上下文，含超时保护（10个STM周期），需注意中断优先级。
 */
void SDADC6_DMA_Complete_Handler(void)
{
	static uint8 startupSkipCnt = 0u;   /* 上电后前2次中断跳过，第3次起开始采集 */

	rdcindex = (rdcindex + 1)&0x1F;
	
	uint32 start,end = 0;
	start = Gpt_Stm_LLD_GetCounter(STM0);
	uint8_t master;
	uint32 timestamp_temp = 0;
	timestamp_temp = (RdcDrv_GetTs() & RDCDRV_TIMESTAMPGPR_MASK);

    while (eDMA_1.TCD[1].CSR.B.DONE == 0)
    {
        uint32 now = Gpt_Stm_LLD_GetCounter(STM0);
        uint32 elapsed_ticks = STM_DIFF(start, now);
        if (elapsed_ticks > 10)
        {
            Sdadc6_Dma_Timeout_Flag = 1;
            break;
        }
    }

    if (eDMA_1.TCD[1].CSR.B.DONE == 0)
    {
    }
    else
    {
        Motor_RdcDrvGetPos_100us();
        SGRD_AngleObserver_96us();
        Update_shared_data(timestamp_temp);
		SGPP_SpeedClc_96us();
		#ifdef MOTORCTRL_TEST
		MFSM_FuncSafetyRedundancy_96us();
		#else
		#endif
		
    }

	end = Gpt_Stm_LLD_GetCounter(STM0);
	rdcarray[rdcindex] = end - start; 

	if (startupSkipCnt >= 2u)
	{
		RdcDrv_StoreAdcResult();
	}
	else
	{
		startupSkipCnt++;
	}

	clearSdadcDmaInterrupts();
}

#pragma ghs section
#pragma ghs section
#pragma ghs section
