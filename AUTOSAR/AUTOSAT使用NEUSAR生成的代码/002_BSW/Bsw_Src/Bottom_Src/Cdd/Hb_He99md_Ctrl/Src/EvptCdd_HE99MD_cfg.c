#include "EvptCdd_HE99MD_Prv.h"

HBDrv_Spi_Str EH_valSpiArray_Mp[] = {
	{
		0,
		SpiChannel_HB_HE99MD,
		SpiSequence_HB_HE99MD,
		0,
		9,
		24,
		29
	},
};

uint16 EH_valCfgSpiChannel_Mp[] =
{
		//half-bridge 1 - Init Start
		0x072b,
        0x2040,
		0x2500,
		0x2600,
		0x0f08,
		0x101a,
		0x112c,
		0x123e,
		0x1dff,
		//half-bridge 1 - Init End
		//half-bridge 1 - Ctrl Start
		0x0b00,
		0x0c00,
		0x0d00,
		0x1300,
		0x1400,
		0x1500,
		0x1600,
		0x1700,
		0x1800,
		0x1900,
		0x1a00,
		0x1b00,
		0x1c00,
		0x0800,
		0x0900,
		0x4000,
		0x4100,
		0x4200,
		0x4400,
		0x4500,
		//half-bridge 1 - Ctrl End
		// //half-bridge 2 - Init Start
		// 0x072b,
        // 0x2040,
		// 0x2500,
		// 0x2600,
		// 0x0f08,
		// 0x101a,
		// 0x112c,
		// 0x123e,
		// 0x1dff,
		// //half-bridge 2 - Init End
		// //half-bridge 2 - Ctrl Start
		// 0x0b00,
		// 0x0c00,
		// 0x0d00,
		// 0x1300,
		// 0x1400,
		// 0x1500,
		// 0x1600,
		// 0x1700,
		// 0x1800,
		// 0x1900,
		// 0x1a00,
		// 0x1b00,
		// 0x1c00,
		// 0x0800,
		// 0x0900,
		// 0x4000,
		// 0x4100,
		// 0x4200,
		// 0x4400,
		// 0x4500,
		// //half-bridge 2 - Ctrl End
};

HbDrv_FctP_Str EH_valFctP_Mp[] =
{
	{
		&HBridge_HE99MD_Init,
		&HBridge_HE99MD_SetOpMode,
		&HBridge_HE99MD_OutputCtrl,
	},
	// {
	// 	&HBridge_HE99MD_Init,
	// 	&HBridge_HE99MD_SetOpMode,
	// 	&HBridge_HE99MD_OutputCtrl,
	// },
};
