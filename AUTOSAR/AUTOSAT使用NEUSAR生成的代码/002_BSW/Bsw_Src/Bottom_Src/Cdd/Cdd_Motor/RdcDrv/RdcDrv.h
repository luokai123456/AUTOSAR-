/****************************************************************
 * 模块：Cdd层 - RDC驱动模块
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.0 (初始版本)
 * 1. 支持RDC驱动模块控制功能
 * 2. 支持RDC驱动模块状态获取功能
 * ==================================================
 ****************************************************************/
#ifndef _RDCDRV_H_
#define _RDCDRV_H_

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Platform_Types.h"
#include "status.h"
#include "typedefs.h"

/******************************************************************************/
/*----------------------------------Defines-----------------------------------*/
/******************************************************************************/
#define RDCDRV_CHECK_INPUT_AVAIL                1
#define RDCDRV_NULL_PTR						    ((void *) 0)
#define RDCDRV_NOT_OK                           0x01
#define RDCDRV_OK                               0x00


#define RDCDRV_CARSIGGEN_FIFO_SIZE	            64                                      /* 激励载波基波整周期波形比较值数组长度 */
#define RDCDRV_CARSIGGEN_TI_EXCT_PERD	        312                                     /* 激励载波PWM波周期1.56us@200MHz */
#define RDCDRV_CARSIGGEN_DIV	        		1             	                        /* 时钟配置分频值，2@100MHz，1@200MHz */

#define RDCDRV_SIGNAL_SAMPLE_NUM            	16                                      /* 激励载波基波周期内的采样点数 */
#define RDCDRV_SIGNAL_HALF_SAMPLE_NUM           (RDCDRV_SIGNAL_SAMPLE_NUM / 2)          /* 激励载波基波周期内的采样点数 */
#define RDCDRV_SIGNAL_FIFO_SIZE	            	(RDCDRV_SIGNAL_SAMPLE_NUM * 1)          /* 包络线采样点缓存大小，1倍于采样点数 */

#define RDCDRV_SDADC_TRIG_TIMNUM                3                                       /* SDADC时间戳捕获TIM模块号*/
#define RDCDRV_SDADC_TRIG_TIMCH                 5                                       /* SDADC时间戳捕获TIM通道号*/

#define RDCDRV_SDADC_CHN_SIN                    1                                       /* 旋变信号SIN的SDADC通道号*/
#define RDCDRV_SDADC_CHN_COS                    0                                       /* 旋变信号COS的SDADC通道号*/

#define RDCDRV_CFG_INTEGCOEF                    ((float32)0.0125F)                      /* 旋变信号整流积分后的缩放系数*/

#define RDCDRV_CFG_VALUEMAXID                   ((uint32)5U)                            /* 旋变反馈信号最大幅值位置索引*/
#define RDCDRV_CFG_AMPVALIDP                    ((float32)4000.0F)                      /* 旋变反馈信号幅值有效幅值正*/
#define RDCDRV_CFG_AMPVALIDN                    ((float32)-4000.0F)                     /* 旋变反馈信号幅值有效幅值负*/
#define RDCDRV_CFG_WAITTIME                     ((uint32)1000U)                         /*96*1000 = 96ms*/
#define RDCDRV_TIMESTAMPGPR_MASK                ((uint32)0x00FFFFFFU)                   /*Time Stamp GPR Register Mask*/

#define	RDCDRV_GETPOS_PARAERROR                 ((uint32)1U)
#define RDCDRV_GETPOSPHY_PARAERROR			    ((uint32)2U)
#define RDCDRV_GETTIME_PARAERROR			    ((uint32)4U)
#define RDCDRV_SINSIGCHANGETIMEERROR		    ((uint32)1U)
#define RDCDRV_COSSIGCHANGETIMEERROR		    ((uint32)2U)
#define RDCDRV_SINCOSAMPERROR				    ((uint32)4U)


#define SEMAPHORES_GATE_NO				0
#define UNLOCK      0
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef enum
{
	RdcDrv_SelfStudy_Undo = 0U,  /*Self Study Undo*/
	RdcDrv_SelfStudy_Ongoing,    /*Self Study Ongoing*/
	RdcDrv_SelfStudy_Done,       /*Self Study Done*/
	RdcDrv_SelfStudy_Fail,       /*Self Study Fail*/

}RdcDrv_SelfStudyStateType;      /*Self Study State Type*/


typedef struct
{
	float32     SinSdadcGain_f32;                                   /*Get Sin SDADC Gain Value*/
	float32     SinSdadcOffset_f32;                                 /*Get Sin SDADC Offset Value*/
	float32     CosSdadcGain_f32;                                   /*Get Cos SDADC Gain Value*/
	float32     CosSdadcOffset_f32;                                 /*Get Cos SDADC Offset Value*/
	float32     SinSampleValue_f32[RDCDRV_SIGNAL_SAMPLE_NUM];       /*Get Cos Sample Value*/
	float32     CosSampleValue_f32[RDCDRV_SIGNAL_SAMPLE_NUM];       /*Get Sin Sample Value*/ 	 
	float32     SinValue_f32;                                       /*Calculate Sin Value*/        
	float32     CosValue_f32;                                       /*Calculate Cos Value*/	
	float32     SinPV_f32;                                          /*Physical SIN*/	         
	float32     CosPV_f32;                                          /*Physical COS*/	         
	float32     SinNV_f32;                                          /*Physical SIN*/	         
	float32     CosNV_f32;                                          /*Physical COS*/	         	       
	float32     ShiftSinValue_f32[RDCDRV_SIGNAL_SAMPLE_NUM];        /*Save Shift Sin Value*/
	float32     ShiftCosValue_f32[RDCDRV_SIGNAL_SAMPLE_NUM];        /*Save Shift Cos Value*/

	RdcDrv_SelfStudyStateType SelfStudyState;                       /*Self Study State*/
	uint32      SinValueShiftNum_u32;                               /*Sin Value Shift Number*/
	uint32      CosValueShiftNum_u32;                               /*Cos Value Shift Number*/
	uint32      TimeStamp_u32;                                      /*Get SDADC Time Stamp*/         
	uint32      StudyCount_u32;                                     /*Wait Count Number*/
	uint32      LogicError_u32;                                     /*Logical Error Status*/
	uint32      FuncError_u32;                                      /*Functional Error Status*/ 
	sint16      SinValueSig_s16[RDCDRV_SIGNAL_SAMPLE_NUM];          /*Judge Sin Value Signal*/
	sint16      CosValueSig_s16[RDCDRV_SIGNAL_SAMPLE_NUM];          /*Judge Cos Value Signal*/
	uint8       SinValueSigCrossTimes_u8;                           /*Sin Value Signal Change Times*/
	uint8       CosValueSigCrossTimes_u8;                           /*Cos Value Signal Change Times*/
	uint8       SignalOverrun_u8;                                   /*Signal is Overrun*/
	uint8       ParameterStu_u8;                                    /*Parameter is Valid/NoValid*/	

}RdcDrv_Dev_t;


/**
 * @brief RDC 原始采样数据（SDADC6 DMA 结果，谷值/峰值分离）
 */
typedef struct
{
    uint16      CospValley_u16;                                     /* COS+ 谷值（励磁最低点） */
    uint16      CospPeak_u16;                                       /* COS+ 峰值（励磁最高点） */
    uint16      CosnValley_u16;                                     /* COS- 谷值 */
    uint16      CosnPeak_u16;                                       /* COS- 峰值 */
    uint16      SinpValley_u16;                                     /* SIN+ 谷值 */
    uint16      SinpPeak_u16;                                       /* SIN+ 峰值 */
    uint16      SinnValley_u16;                                     /* SIN- 谷值 */
    uint16      SinnPeak_u16;                                       /* SIN- 峰值 */
    uint16      ExcpValley_u16;                                     /* EXC+ 谷值 */
    uint16      ExcpPeak_u16;                                       /* EXC+ 峰值 */
    uint16      ExcnValley_u16;                                     /* EXC- 谷值 */
    uint16      ExcnPeak_u16;                                       /* EXC- 峰值 */
}RdcDrv_SampleData_t;


/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

extern RdcDrv_Dev_t RdcDrv_Dev1;
extern uint32 Motor_ResolverTimestamp_au32;
extern int16 Motor_RdcDrvSinValue_s16_New;
extern int16 Motor_RdcDrvCosValue_s16_New;
extern RdcDrv_SampleData_t RdcDrv_SampleData;
extern uint32 RdcDrv_DmaFailCnt_u32;


/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern void RdcDrv_DevInit(void);
extern void RdcDrv_SdadcTimestampInit(void);
extern void RdcDrv_CarSigGenInit(void);
extern void RdcDrv_ExcPeakTrigInit(void);
extern uint32 RdcDrv_GetTs(void);
extern void RdcDrv_GetPos(RdcDrv_Dev_t *RdcDev, sint16 *SinValue_s16, sint16 *CosValue_s16);
extern void RdcDrv_StoreAdcResult(void);

extern void Motor_RdcDrvGetPos_100us(void);
extern void Motor_PosUpdata_Function(void);
extern uint32 get_master_id(void);
extern volatile uint8 Get_Gate_status(volatile uint8 gate_no);
extern volatile uint8 Lock_Gate(volatile uint8 gate_no);
extern volatile uint8 Unlock_Gate(volatile uint8 gate_no);
// extern void RDC_Diag_Pos_Updata_Function(void);
#endif /* __RDCDRV_H */




