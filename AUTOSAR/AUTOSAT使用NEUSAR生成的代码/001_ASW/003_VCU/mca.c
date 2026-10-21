/*----------------------------------------------------------------------------------------------------------------------------------------
* @file         mca.c
*
* @author       YKXN
*
* @date_created:   2020/07/01
*
* @version    	V1.2
*
* @description:
*
* @Modification:
*    					Date		               Author		Description
*
*----------------------------------------------------------------------------------------------------------------------------------------*/
/****************************************************************************
* 	Include Files
****************************************************************************/
#include "mca.h"
#include "swc_MEST.h"
#include "rtwtypes.h"
//#include "Platform_Types.h"

/****************************************************************************
* 	Local Macro Definitions
****************************************************************************/

#define MCA_VEL_FACTOR 		  1047      	//车速计算因子 0.1047*10000
#define MCA_P_FACTOR   	 	  955         	//转速扭矩功率计算因子 9.55*100
#define MCA_F_FACTOR_1 		  760	      	//滚阻计算因子 0.0076*100000
#define MCA_F_FACTOR_2 		  2			   	//滚阻计算因子 0.0002016*10000≈2
#define MCA_PW_FACTOR         61     		//风阻计算因子 0.612766*100≈61
#define MCA_STA_FILTER		  50			//统计算法滤波参数

/****************************************************************************
* 	Local Type Definitions
****************************************************************************/


/****************************************************************************
* 	Local Function Declarations
****************************************************************************/


/****************************************************************************
*	Local Type Definitions
****************************************************************************/


/****************************************************************************
*	Local Function Declarations
****************************************************************************/


/****************************************************************************
*	Global Variable Definitions
****************************************************************************/

/****************************************************************************
*	Global CONST  Definitions
****************************************************************************/

/****************************************************************************
*	Static Variable Definitions
****************************************************************************/
/***********Input parameters**********/
static uint8_T  MCA_ErrCode_Flg = 0;		//输入值超过限值标志位
static uint16_T IFC_MCA_Vlt  = 0;
static int16_T  IFC_MCA_Crt  = 0;
static int16_T  IFC_MCA_Rot  = 0;
static int16_T  IFC_MCA_Torq = 0;
static int16_T  MCA_Sta_Rot  = 0;			//统计算法转速
static int32_T  MCA_Sta_Vel  = 0;	  		//统计算法车速

// static     C_MCA_r = 0;
// static   uint16_T C_MCA_Mmin = 0;
// static   uint16_T C_MCA_Mmax = 0;
// static   uint16_T C_MCA_MassOverload1 = 0;          //9500
// static   uint16_T C_MCA_MassOverload2 = 0;
/***********Output parameters**********/
static uint16_T Out_MCA_Totalmass = 0;
/*static*/ uint32_T MCA_RLS_Mass = 0;
/*static*/ uint32_T MCA_Sta_Mass = 0;

/**************************************/
static uint8_T MCA_10ms_Count = 0;
static uint8_T MCA_100ms_Flg  = 0;

/***********Sta parameters*************/
static uint8_T  MCA_Sta_AFilter_Count  = 0;
static uint16_T MCA_Sta_Data_Count  = 0;
static uint16_T MCA_Sta_Vlt_Temp 	= 0; 		//上一时刻电压
static int16_T  MCA_Sta_Crt_Temp 	= 0; 		//上一时刻电流
static int32_T  MCA_Sta_Vel_Temp 	= 0; 		//上一时刻车速
static real64_T  MCA_Sta_Power 	   	= 0;
static int32_T  MCA_Sta_Acc  		= 0;
static int32_T  MCA_Sta_Acc_Mean  	= 0;
static uint32_T MCA_Sta_Mass_Sum  	= 0;
static uint32_T MCA_Sta_Mass_Mean 	= 0;
static uint32_T MCA_Sta_Mass_Mean_New  = 0;
static int32_T  MCA_Sta_Acc_Buff[MCA_STA_FILTER] = {0};


/***********RLS parameters*************/
static uint16_T MCA_RLS_Data_Count  = 0;
/*static*/ uint16_T MCA_RLS_Amark 	    = 0;
static uint16_T MCA_RLS_Eflag_1     = 0;
/*static*/ uint16_T MCA_RLS_Eflag_2     = 0;
static real64_T  MCA_RLS_Vel_Buff[4] = {0};
static real64_T  MCA_RLS_Power_Temp  = 0;
static real64_T  MCA_RLS_Vel_Temp 	= 0;
static real64_T  MCA_RLS_Power_1     = 0;
static real64_T  MCA_RLS_Vel_1 	    = 0;
static real64_T  MCA_RLS_Vel_2 		= 0;
static real64_T  MCA_RLS_Acc_1		= 0;
static real64_T  MCA_RLS_Acc_2  		= 0;
static real64_T  MCA_RLS_Acc_Temp 	= 0;

static real64_T  MCA_RLS_Vel_lotBuff[4] = {0};
static real64_T  MCA_RLS_Vel_lotTemp 	= 0;
static real64_T  MCA_RLS_Vel_lot1 	    = 0;
static real64_T  MCA_RLS_Vel_lot2 		= 0;
static real64_T  MCA_RLS_Acc_lot1		= 0;
static real64_T  MCA_RLS_Acc_lot2  		= 0;
static real64_T  MCA_RLS_Acc_lotTemp 	= 0;

static real64_T MCA_RLS_Result 		= 0;
static real64_T MCA_RLS_Accum 		= 0;
static real64_T MCA_RLS_RAccum 		= 0;
static real64_T  MCA_RLS_f  	 = 0;
static real64_T  MCA_RLS_Pw 	 = 0;
static real64_T  MCA_RLS_Pr 	 = 0;
static real64_T  MCA_RLS_zk   = 0;
static real64_T  MCA_RLS_Kk 	 = 0;
static real64_T MCA_RLS_Hk 	 = 0;
static real64_T MCA_RLS_Pk   = 0;
static real64_T MCA_RLS_xk 	 = 0;
static real64_T MCA_RLS_Pk_1 = 0;
static real64_T MCA_RLS_xk_1 = 0;

static uint16_T MCA_BaseMass = 3000;
static uint32_T MCA_Stamass_factor=115000;
static uint8_T  MCA_RLSmass_factor=100;

/****************************************************************************
*	Global and Static Function Definitions
****************************************************************************/
/****************************************************************************
 * @Function:	 MCA_Init()
 *
 * @description:   Init MCA_RLS_Pk_1/MCA_RLS_xk_1.
 *
 * @param:	 void
 *
 * @author:
 *
 * @date:	2020/05/12
 *
 * @return: void
 *
 * @Modification:
 *						Date					Author		Description
 *
****************************************************************************/
void MCA_Init(uint16_T vhlBaseMass,uint16_T vhlWhlRad,uint16_T vhlMinMass,uint16_T vhlMaxMass,uint16_T vhlMassOverload1,uint16_T vhlMassOverload2)
{
	uint8_T Acc_idx = 0;
	uint8_T Vel_idx = 0;

	IFC_MCA_Rot 	  = 0;
	IFC_MCA_Torq      = 0;
	IFC_MCA_Vlt       = 0;
	IFC_MCA_Crt  	  = 0;
	MCA_Sta_Rot 	  = 0;
	MCA_Sta_Vel  	  = 0;
	MCA_ErrCode_Flg   = 0;
	MCA_RLS_Mass      = 0;
	MCA_Sta_Mass 	  = 0;
	Out_MCA_Totalmass = 0;
	MCA_10ms_Count    = 0;
	MCA_100ms_Flg 	  = 0;
	MCA_Sta_Vel_Temp  = 0;
    MCA_Sta_Vlt_Temp  = 0;
	MCA_Sta_Crt_Temp  = 0;
	MCA_Sta_Power	  = 0;
	MCA_Sta_Acc		  = 0;
	MCA_Sta_Acc_Mean  = 0;
	MCA_Sta_Mass_Sum  = 0;
	MCA_Sta_Mass_Mean = 0;
	MCA_Sta_Mass_Mean_New = 0;
	MCA_Sta_AFilter_Count = 0;
	MCA_Sta_Data_Count    = 0;
	MCA_RLS_Data_Count    = 0;
	MCA_RLS_Power_Temp    = 0;
	MCA_RLS_Vel_Temp      = 0;
	MCA_RLS_Power_1     = 0;
	MCA_RLS_Vel_1 	   	= 0;
	MCA_RLS_Vel_2 		= 0;
	MCA_RLS_Acc_1 		= 0;
	MCA_RLS_Acc_2 		= 0;
	MCA_RLS_Acc_Temp 	= 0;
	MCA_RLS_Amark    	= 0;
	MCA_RLS_Eflag_1  	= 0;
	MCA_RLS_Eflag_2  	= 0;
	MCA_RLS_Result  	= 0;
	MCA_RLS_Accum   	= 0;
	MCA_RLS_RAccum   	= 0;
	MCA_RLS_f  = 0;
	MCA_RLS_Pw = 0;
	MCA_RLS_Pr = 0;
	MCA_RLS_zk = 0;
	MCA_RLS_Hk = 0;
	MCA_RLS_Kk = 0;
	MCA_RLS_Pk = 0;
	MCA_RLS_xk = 0;
	MCA_RLS_Pk_1 = C_MCA_RLS_P0*1e7;		//初始化函数赋值P0*1e7
	// MCA_RLS_xk_1 = C_MCA_Mmin;				//初始化函数赋值m0
    MCA_RLS_xk_1 = vhlMinMass;
    //*******EFROM Input parameters ***************//

    MCA_BaseMass = vhlBaseMass;
    // C_MCA_r = vhlWhlRad;
    // C_MCA_Mmin = vhlMinMass;
    // C_MCA_Mmax = vhlMaxMass;
    // C_MCA_MassOverload1 = vhlMassOverload1;
    // C_MCA_MassOverload2 = vhlMassOverload2;
	if(vhlBaseMass==2510)
	{MCA_Stamass_factor=120000;
     MCA_RLSmass_factor=105;}
    // *****************************************//

	for(Acc_idx;Acc_idx<MCA_STA_FILTER;Acc_idx++)
	{
		MCA_Sta_Acc_Buff[Acc_idx] = 0;
	}
	for(Vel_idx;Vel_idx < 4;Vel_idx++)
	{
		MCA_RLS_Vel_Buff[Vel_idx] = 0;
	}

}
/****************************************************************************
 * @Function:	 MCA_ReInit()
 *
 * @description:
 *
 * @param:	 void
 *
 * @author:
 *
 * @date:	2020/05/12
 *
 * @return: void
 *
 * @Modification:
 *						Date					Author		Description
 *
****************************************************************************/
void MCA_ReInit()
{
	//MCA_Init();
     MCA_Init(MCA_BaseMass,C_MCA_r,C_MCA_Mmin,C_MCA_Mmax,C_MCA_MassOverload1,C_MCA_MassOverload2);
}
/****************************************************************************
 * @Function:	 MCA_Input()
 *
 * @description:
 *
 * @param:	  void
 *
 * @author:
 *
 * @date:	  2020/05/12
 *
 * @return: void
 *
 * @Modification:
 *						Date					Author		Description
 *
****************************************************************************/
void MCA_Input(int16_T rot,int16_T torq,uint16_T motorvlt,int16_T motorcrt)
{
	IFC_MCA_Rot  = rot;
	IFC_MCA_Torq = torq;
	IFC_MCA_Vlt  = motorvlt;
	IFC_MCA_Crt  = motorcrt;

	if((IFC_MCA_Rot  < C_IFC_MCA_Rot_Min) ||(IFC_MCA_Rot  > C_IFC_MCA_Rot_Max))
	{
		MCA_ErrCode_Flg |= 0x01;
	}
	if((IFC_MCA_Torq < C_IFC_MCA_Torq_Min)||(IFC_MCA_Torq > C_IFC_MCA_Torq_Max))
	{
		MCA_ErrCode_Flg |= 0x02;
	}
	if((IFC_MCA_Vlt  < C_IFC_MCA_Vlt_Min) ||(IFC_MCA_Vlt  > C_IFC_MCA_Vlt_Max))
	{
		MCA_ErrCode_Flg |= 0x03;
	}
	if((IFC_MCA_Crt  < C_IFC_MCA_Crt_Min) ||(IFC_MCA_Crt  > C_IFC_MCA_Crt_Max))
	{
		MCA_ErrCode_Flg |= 0x00;
	}


	MCA_Sta_Rot	 = IFC_MCA_Rot; 												//电机转速
	MCA_Sta_Vel  = (MCA_VEL_FACTOR * MCA_Sta_Rot * C_MCA_r) / (C_MCA_ig*100); 	//车速*100
}

/****************************************************************************
 * @Function:	 MCA_MainFunction()
 *
 * @description:   MCA_MainFunction
 *
 * @param:	 void
 *
 * @author:
 *
 * @date:	2020/05/12
 *
 * @return: void
 *
 * @Modification:
 *						Date					Author		Description
 *
****************************************************************************/
void MCA_MainFunction()
{
	uint8_T idx = 0;
	/************************************************************************/
	MCA_10ms_Count ++;
	if(MCA_10ms_Count == 50)	//500ms取值一次
	{
		MCA_100ms_Flg = 1;
	}
	if(MCA_10ms_Count >= 50)
	{
		MCA_10ms_Count = 0;
	}
	/*************************************************************************/
	if(MCA_RLS_Data_Count <= 3)	//初始化速度、加速度、功率
	{
		MCA_RLS_Vel_Temp   = (MCA_VEL_FACTOR * IFC_MCA_Rot * C_MCA_r) / (C_MCA_ig * 10); //车速*1000
		MCA_RLS_Power_Temp = (IFC_MCA_Rot * IFC_MCA_Torq * 100) / MCA_P_FACTOR;
		MCA_RLS_Vel_Buff[MCA_RLS_Data_Count] = MCA_RLS_Vel_Temp;
		/******加速度阈值判断计算******/
		MCA_RLS_Vel_lotTemp = (MCA_VEL_FACTOR * IFC_MCA_Rot * C_MCA_r);
		MCA_RLS_Vel_lotBuff[MCA_RLS_Data_Count] = MCA_RLS_Vel_lotTemp;
		/******************************/
		if(MCA_RLS_Data_Count == 3)
		{
			MCA_RLS_Vel_1 = MCA_RLS_Vel_Buff[1];
			MCA_RLS_Vel_2 = MCA_RLS_Vel_Buff[2];
			MCA_RLS_Acc_1 = (100 * (MCA_RLS_Vel_Buff[2]-MCA_RLS_Vel_Buff[0])) / (2 * C_MCA_RLS_Dt);//加速度*100
			MCA_RLS_Acc_2 = (100 * (MCA_RLS_Vel_Buff[3]-MCA_RLS_Vel_Buff[1])) / (2 * C_MCA_RLS_Dt);
			MCA_RLS_Acc_2 = ((MCA_RLS_Acc_2 * C_MCA_RLS_Alpha) + (MCA_RLS_Acc_1 * (100-C_MCA_RLS_Alpha)))/100;
			/******加速度阈值判断计算******/
			MCA_RLS_Vel_lot1 = MCA_RLS_Vel_lotBuff[1];
			MCA_RLS_Vel_lot2 = MCA_RLS_Vel_lotBuff[2];
			MCA_RLS_Acc_lot1 = (MCA_RLS_Vel_lotBuff[2]-MCA_RLS_Vel_lotBuff[0]);
			MCA_RLS_Acc_lot2 = (MCA_RLS_Vel_lotBuff[3]-MCA_RLS_Vel_lotBuff[1]);
			MCA_RLS_Acc_lot2 = ((MCA_RLS_Acc_lot2 * C_MCA_RLS_Alpha) + (MCA_RLS_Acc_lot1 * (100-C_MCA_RLS_Alpha)))/100;
			/******************************/
		}
		MCA_RLS_Data_Count ++;
	}
	else
	{
		MCA_RLS_Vel_1      = MCA_RLS_Vel_2;
		MCA_RLS_Vel_2 	   = MCA_RLS_Vel_Temp;
		MCA_RLS_Vel_Temp   = (MCA_VEL_FACTOR * IFC_MCA_Rot * C_MCA_r) / (C_MCA_ig * 10);	//新进NT数据的速度
		MCA_RLS_Power_1    = MCA_RLS_Power_Temp;
		MCA_RLS_Power_Temp = (IFC_MCA_Rot * IFC_MCA_Torq * 100) / MCA_P_FACTOR; //新进NT的功率
		MCA_RLS_Acc_1      = MCA_RLS_Acc_2;
		MCA_RLS_Acc_Temp   = (100 * (MCA_RLS_Vel_Temp - MCA_RLS_Vel_1)) / (2 * C_MCA_RLS_Dt);
		/******加速度阈值判断计算******/
		MCA_RLS_Vel_lot1    = MCA_RLS_Vel_lot2;
		MCA_RLS_Vel_lot2 	= MCA_RLS_Vel_lotTemp;
		MCA_RLS_Vel_lotTemp = (MCA_VEL_FACTOR * IFC_MCA_Rot * C_MCA_r);
		MCA_RLS_Acc_lot1    = MCA_RLS_Acc_lot2;
		MCA_RLS_Acc_lotTemp = (MCA_RLS_Vel_lotTemp - MCA_RLS_Vel_lot1);
		/******************************/
		if(MCA_RLS_Acc_Temp > C_MCA_g)
		{
			MCA_RLS_Acc_Temp = MCA_RLS_Acc_1;
		}
		MCA_RLS_Acc_2 = ((MCA_RLS_Acc_Temp * C_MCA_RLS_Alpha) + (MCA_RLS_Acc_1 * (100-C_MCA_RLS_Alpha)))/100;
		/******加速度阈值判断计算******/
		if(MCA_RLS_Acc_lotTemp > (C_MCA_g * 2 * C_MCA_RLS_Dt * C_MCA_ig /10))
		{
			MCA_RLS_Acc_lotTemp = MCA_RLS_Acc_lot1;
		}
		MCA_RLS_Acc_lot2 = ((MCA_RLS_Acc_lotTemp * C_MCA_RLS_Alpha) + (MCA_RLS_Acc_lot1 * (100-C_MCA_RLS_Alpha)))/100;
		/******************************/
		if((MCA_RLS_Acc_lot1 > (C_MCA_RLS_Acc_Lot * 2 * C_MCA_RLS_Dt * C_MCA_ig /10)) &&
		   (MCA_RLS_Acc_lot2 > (C_MCA_RLS_Acc_Lot * 2 * C_MCA_RLS_Dt * C_MCA_ig /10)))
		{
			MCA_RLS_Amark ++;

			MCA_RLS_f  = (MCA_F_FACTOR_1*100 + (MCA_F_FACTOR_2 * MCA_RLS_Vel_2))/10;//滚阻功率 f*1000000
			MCA_RLS_Pw = ((C_MCA_CdA * MCA_RLS_Vel_2 * MCA_RLS_Vel_2 * MCA_RLS_Vel_2 * MCA_PW_FACTOR)*1e-10);//风阻功率 Pw*100
			MCA_RLS_Pr = (MCA_RLS_Vel_2 * MCA_RLS_Acc_2 * C_MCA_RLS_Mr)*1e-3;//Pr*100
			MCA_RLS_zk = ((MCA_RLS_Power_1 * C_MCA_RLS_Eta) - MCA_RLS_Pw - MCA_RLS_Pr)/100;
			MCA_RLS_Hk = (((C_MCA_g * MCA_RLS_f) + (MCA_RLS_Acc_2*1e6)) * (MCA_RLS_Vel_2))*1e-7;//Hk*10000
			MCA_RLS_Kk = (MCA_RLS_Pk_1 * MCA_RLS_Hk*1e7) / (1e13 + (MCA_RLS_Hk * MCA_RLS_Hk * MCA_RLS_Pk_1)*1e-3);//Kk*1e6
			MCA_RLS_Pk = ((1e10 - (MCA_RLS_Kk * MCA_RLS_Hk)) * MCA_RLS_Pk_1)*1e-10;//Pk*1e8
			MCA_RLS_xk = ((MCA_RLS_xk_1*1e10) + (MCA_RLS_Kk * (MCA_RLS_zk*1e4 - MCA_RLS_Hk * MCA_RLS_xk_1)))*1e-10;


			if(MCA_RLS_xk > C_MCA_Mmax)
			{
				MCA_RLS_xk = C_MCA_Mmax;
			}
			if(MCA_RLS_xk < C_MCA_Mmin)
			{
				MCA_RLS_xk = C_MCA_Mmin;
			}
			if(MCA_RLS_Amark > C_MCA_RLS_EfMk)
			{
				MCA_RLS_Accum = MCA_RLS_Accum + MCA_RLS_xk;
				MCA_RLS_Eflag_1 ++;
			}
			MCA_RLS_xk_1 = MCA_RLS_xk;
			MCA_RLS_Pk_1 = MCA_RLS_Pk;
		}
		else
		{
			if((MCA_RLS_Amark * C_MCA_RLS_Dt) > C_MCA_RLS_EfTm)
			{
				MCA_RLS_Result = MCA_RLS_Accum / MCA_RLS_Eflag_1;
				MCA_RLS_Eflag_2 ++;

				MCA_RLS_RAccum = MCA_RLS_RAccum + MCA_RLS_Result;
				MCA_RLS_Mass   = (uint32_T)(MCA_RLS_RAccum / MCA_RLS_Eflag_2);

				if(MCA_RLS_Mass > C_MCA_RLS_Mass_ST)
				{
					MCA_RLS_Mass = (MCA_RLS_Mass * C_MCA_RSL_MassScale_Factor)/100;

				}
			}
			MCA_RLS_Accum   = 0;
			MCA_RLS_Amark   = 0;
			MCA_RLS_Eflag_1 = 0;
			MCA_RLS_xk_1 	= C_MCA_Mmin;
			MCA_RLS_Pk_1 	= C_MCA_RLS_P0*1e7;
		}
	}
	/**********统计算法**********/
	if(MCA_100ms_Flg == 1)
	{
		MCA_100ms_Flg = 0;
		MCA_Sta_Acc	  = (1000 * (MCA_Sta_Vel - MCA_Sta_Vel_Temp)) / C_MCA_Sta_Dt;	//加速度*100
		MCA_Sta_Acc_Buff[MCA_Sta_AFilter_Count] = MCA_Sta_Acc;
		MCA_Sta_AFilter_Count ++;

		if(MCA_Sta_AFilter_Count >= MCA_STA_FILTER)
		{
			MCA_Sta_AFilter_Count = 0;
		}
		for(idx = 0;idx < MCA_STA_FILTER;idx ++)
		{
			MCA_Sta_Acc_Mean += MCA_Sta_Acc_Buff[idx];
		}
		MCA_Sta_Acc		 = MCA_Sta_Acc_Mean / MCA_STA_FILTER;
		MCA_Sta_Acc_Mean = 0;
		MCA_Sta_Power    = MCA_Sta_Vlt_Temp * MCA_Sta_Crt_Temp;

		if((MCA_Sta_Acc > C_MCA_Sta_Acc_Lot) && (MCA_Sta_Acc < C_MCA_Sta_Acc_Upt) &&
	       (MCA_Sta_Vel_Temp > (C_MCA_Sta_Vel_Lot*10)) && (MCA_Sta_Power > C_MCA_Sta_Power_Lot))//统计车速已*100
		{
			MCA_Sta_Data_Count ++;
			MCA_Sta_Mass_Mean_New = (uint32_T)((MCA_Sta_Power*MCA_Stamass_factor) / ((MCA_Sta_Vel_Temp*100) + C_MCA_Sta_K_Ratio * MCA_Sta_Vel_Temp * MCA_Sta_Acc));	//MCA_Sta_Mass_Mean_New*10

	        if(MCA_Sta_Mass_Mean_New <= C_MCA_Mmin)
			{
				MCA_Sta_Mass_Mean_New = C_MCA_Sta_Mass_Factor;
			}
			 if(MCA_Sta_Mass_Mean_New > C_MCA_Mmin&&MCA_Sta_Mass_Mean_New <C_MCA_Mmax)
			{
				MCA_Sta_Mass_Mean_New = (MCA_Sta_Mass_Mean_New * C_MCA_Sta_Mass_Factor /C_MCA_Mmin);
			}
			if(MCA_Sta_Mass_Mean_New >= C_MCA_Mmax)
			{
				MCA_Sta_Mass_Mean_New = (C_MCA_Mmax * C_MCA_Sta_Mass_Factor /C_MCA_Mmin);
			}

			MCA_Sta_Mass_Sum  = MCA_Sta_Mass_Sum + MCA_Sta_Mass_Mean_New;	//MCA_Sta_Mass_Sum*10
			MCA_Sta_Mass_Mean = MCA_Sta_Mass_Sum / MCA_Sta_Data_Count;		//MCA_Sta_Mass_Mean*10
			MCA_Sta_Mass 	  = (MCA_Sta_Mass_Mean * C_MCA_Mmin) / C_MCA_Sta_Mass_Factor;

			if(MCA_Sta_Mass > C_MCA_Sta_Mass_ST)
			{
				MCA_Sta_Mass = (MCA_Sta_Mass * C_MCA_Sta_MassScale_Factor)/100;//标定量已*100
			}

		}

		MCA_Sta_Vel_Temp = MCA_Sta_Vel;
		MCA_Sta_Vlt_Temp = IFC_MCA_Vlt;
		MCA_Sta_Crt_Temp = IFC_MCA_Crt;
	}

	if(MCA_Sta_Data_Count == 0)
	{
		Out_MCA_Totalmass = MCA_BaseMass;
	}
	else if((MCA_Sta_Data_Count>0)&&(MCA_Sta_Data_Count<=C_MCA_Cls_Num)&&(MCA_RLS_Mass == 0))
	{
		Out_MCA_Totalmass = (uint16_T)(MCA_Sta_Mass);
	}
	else
	{
		Out_MCA_Totalmass = (uint16_T)(((MCA_Sta_Mass * C_MCA_Total_Factor) + (MCA_RLS_Mass * (100 - C_MCA_Total_Factor)*MCA_RLSmass_factor/100))/100);//标定量已*100
		MCA_BaseMass = Out_MCA_Totalmass;
	}
	if(MCA_Sta_Data_Count >= C_MCA_Cls_Num)
	{
		MCA_ReInit();	//初始化
		Out_MCA_Totalmass = MCA_BaseMass;
	}


}
/****************************************************************************
 * @Function:	 MCA_Output()
 *
 * @description:
 *
 * @param:	 void
 *
 * @author:
 *
 * @date:	2020/05/12
 *
 * @return: void
 *
 * @Modification:
 *						Date					Author		Description
 *
****************************************************************************/
uint8_T MCA_Output(uint16_T *MCA_TotalMass,uint8_T *MCA_OverLoadFlag,uint16_T *MCA_DataID)
{
	uint8_T dataValidFlg = 0;
	uint8_T overLoadFlg  = 0;

	/*****result valid*****/
	if((MCA_Sta_Data_Count > C_MCA_ResutlCom_Num)&&(MCA_ErrCode_Flg == 0))
	{
		dataValidFlg = 1;
	}
	else
	{
		dataValidFlg = 0;
	}
	/*****overload********/
	if((Out_MCA_Totalmass > C_MCA_MassOverload2)&&(dataValidFlg == 1))
	{
		overLoadFlg = 2;
	}
	else if((Out_MCA_Totalmass <= C_MCA_MassOverload2)&&(Out_MCA_Totalmass > C_MCA_MassOverload1)&&(dataValidFlg == 1))
	{
		overLoadFlg = 1;
	}
	else
	{
		overLoadFlg = 0;
	}

	*MCA_DataID 	  = MCA_Sta_Data_Count;
	*MCA_TotalMass    = Out_MCA_Totalmass;
	*MCA_OverLoadFlag = overLoadFlg;

	return dataValidFlg;
}
