
#include "SoftwareVersion.h"
#include "Os.h"

typedef float Core_LoadRate;
//extern VAR(Os_Monitor_CoreCpuloadType_st, OS_VAR_INIT) Os_Monitor_CpuLoadkPara[OS_COREID_COUNT];
Core_LoadRate coreLoadRate[CoreId_Count] = {0};
const Sw_stVersionTime_TDSTR EP_valBswVerTime_STR =
{
	.Sw_numVersion1 = BSW_VERSION_MAJOR,
	.Sw_numVersion2 = BSW_VERSION_MINOR,
	.Sw_numVersion3 = BSW_VERSION_TEST,
	.Sw_tiYear 		= BSW_VERSION_YEAR,
	.Sw_tiMonth 	= BSW_VERSION_MONTH,
	.Sw_tiDay 		= BSW_VERSION_DAY,
};

Sw_stVersionTime_TDSTR Get_Bsw_Version(void)
{
	Sw_stVersionTime_TDSTR valVersion_LO = {0};
	valVersion_LO = EP_valBswVerTime_STR;
	return valVersion_LO;
}

Sw_stVersionTime_TDSTR Get_Pbl_Version(void)
{
	uint32 valPBLVerAddr_LO = PBL_VERSION_ADDR;
	Sw_stVersionTime_TDSTR valVersion_LO = {0};

	valVersion_LO.Sw_tiYear			=	*(uint8*)(valPBLVerAddr_LO + 0x0);
	valVersion_LO.Sw_tiMonth		=	*(uint8*)(valPBLVerAddr_LO + 0x1);
	valVersion_LO.Sw_tiDay			=	*(uint8*)(valPBLVerAddr_LO + 0x2);
	valVersion_LO.Sw_numVersion1	= 	*(uint8*)(valPBLVerAddr_LO + 0x3);
	valVersion_LO.Sw_numVersion2	=	*(uint8*)(valPBLVerAddr_LO + 0x4);
	valVersion_LO.Sw_numVersion3	=	*(uint8*)(valPBLVerAddr_LO + 0x5);
    
	return valVersion_LO;
}

Sw_stVersionTime_TDSTR Get_Sbl_Version(void)
{
	uint32 valSBLVerAddr_LO = SBL_VERSION_ADDR;
	Sw_stVersionTime_TDSTR valVersion_LO = {0};

	valVersion_LO.Sw_tiYear			=	*(uint8*)(valSBLVerAddr_LO + 0x0);
	valVersion_LO.Sw_tiMonth		=	*(uint8*)(valSBLVerAddr_LO + 0x1);
	valVersion_LO.Sw_tiDay			=	*(uint8*)(valSBLVerAddr_LO + 0x2);
	valVersion_LO.Sw_numVersion1	= 	*(uint8*)(valSBLVerAddr_LO + 0x3);
	valVersion_LO.Sw_numVersion2	=	*(uint8*)(valSBLVerAddr_LO + 0x4);
	valVersion_LO.Sw_numVersion3	=	*(uint8*)(valSBLVerAddr_LO + 0x5);

	return valVersion_LO;
}


