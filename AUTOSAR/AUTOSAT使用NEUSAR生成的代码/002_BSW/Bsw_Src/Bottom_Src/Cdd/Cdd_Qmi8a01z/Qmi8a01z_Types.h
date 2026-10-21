#ifndef __QMI8A01Z_TYPES_H_
#define __QMI8A01Z_TYPES_H_

#include "typedefs.h"

/*!< @name ChipInfo - QMI8A01Z WHO_AM_I Register */
/*!< @{ */

#define QMI8A01Z_WHO_AM_I_MASK                  	0xffU
#define QMI8A01Z_WHO_AM_I_SHIFT                 	0U
#define QMI8A01Z_WHO_AM_I_WIDTH                 	8U
#define QMI8A01Z_WHO_AM_I_SET(x)                	((uint8_t)(((uint8_t)(x)) << QMI8A01Z_WHO_AM_I_SHIFT) & QMI8A01Z_WHO_AM_I_MASK)
#define QMI8A01Z_WHO_AM_I_GET(x)                	((uint8_t)((((uint8_t)(x))&QMI8A01Z_WHO_AM_I_MASK) >> QMI8A01Z_WHO_AM_I_SHIFT))

/*!< @} */

/*!< @name ChipInfo - QMI8A01Z REVISION_ID Register */
/*!< @{ */

#define QMI8A01Z_REVISION_ID_MASK                   0xffU
#define QMI8A01Z_REVISION_ID_SHIFT                  0U
#define QMI8A01Z_REVISION_ID_WIDTH                  8U
#define QMI8A01Z_REVISION_ID_SET(x)                 ((uint8_t)(((uint8_t)(x)) << QMI8A01Z_REVISION_ID_SHIFT) & QMI8A01Z_REVISION_ID_MASK)
#define QMI8A01Z_REVISION_ID_GET(x)                 ((uint8_t)((((uint8_t)(x))&QMI8A01Z_REVISION_ID_MASK) >> QMI8A01Z_REVISION_ID_SHIFT))

/*!< @} */

/*!< @name Configuration - QMI8A01Z CTRL1 Register */
/*!< @{ */

#define QMI8A01Z_CTRL1_SIM_MASK                     0x80U
#define QMI8A01Z_CTRL1_SIM_SHIFT                    7U
#define QMI8A01Z_CTRL1_SIM_WIDTH                    1U
#define QMI8A01Z_CTRL1_SIM_SET(x)                   ((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL1_SIM_SHIFT) & QMI8A01Z_CTRL1_SIM_MASK)
#define QMI8A01Z_CTRL1_SIM_GET(x)                   ((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL1_SIM_MASK) >> QMI8A01Z_CTRL1_SIM_SHIFT))
#define QMI8A01Z_CTRL1_ADDR_AI_MASK                 0x40U
#define QMI8A01Z_CTRL1_ADDR_AI_SHIFT                6U
#define QMI8A01Z_CTRL1_ADDR_AI_WIDTH                1U
#define QMI8A01Z_CTRL1_ADDR_AI_SET(x)               ((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL1_ADDR_AI_SHIFT) & QMI8A01Z_CTRL1_ADDR_AI_MASK)
#define QMI8A01Z_CTRL1_ADDR_AI_GET(x)               ((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL1_ADDR_AI_MASK) >> QMI8A01Z_CTRL1_ADDR_AI_SHIFT))
#define QMI8A01Z_CTRL1_BE_MASK 						0x20U
#define QMI8A01Z_CTRL1_BE_SHIFT						5U
#define QMI8A01Z_CTRL1_BE_WIDTH						1U
#define QMI8A01Z_CTRL1_BE_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL1_BE_SHIFT) & QMI8A01Z_CTRL1_BE_MASK)
#define QMI8A01Z_CTRL1_BE_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL1_BE_MASK) >> QMI8A01Z_CTRL1_BE_SHIFT))
#define QMI8A01Z_CTRL1_INT2_EN_MASK					0x10U
#define QMI8A01Z_CTRL1_INT2_EN_SHIFT				4U
#define QMI8A01Z_CTRL1_INT2_EN_WIDTH				1U
#define QMI8A01Z_CTRL1_INT2_EN_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL1_INT2_EN_SHIFT) & QMI8A01Z_CTRL1_INT2_EN_MASK)
#define QMI8A01Z_CTRL1_INT2_EN_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL1_INT2_EN_MASK) >> QMI8A01Z_CTRL1_INT2_EN_SHIFT))
#define QMI8A01Z_CTRL1_INT1_EN_MASK					0x08U
#define QMI8A01Z_CTRL1_INT1_EN_SHIFT				3U
#define QMI8A01Z_CTRL1_INT1_EN_WIDTH				1U
#define QMI8A01Z_CTRL1_INT1_EN_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL1_INT1_EN_SHIFT) & QMI8A01Z_CTRL1_INT1_EN_MASK)
#define QMI8A01Z_CTRL1_INT1_EN_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL1_INT1_EN_MASK) >> QMI8A01Z_CTRL1_INT1_EN_SHIFT))
#define QMI8A01Z_CTRL1_FIFO_INT_SEL_MASK			0x04U
#define QMI8A01Z_CTRL1_FIFO_INT_SEL_SHIFT			2U
#define QMI8A01Z_CTRL1_FIFO_INT_SEL_WIDTH			1U
#define QMI8A01Z_CTRL1_FIFO_INT_SEL_SET(x)			((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL1_FIFO_INT_SEL_SHIFT) & QMI8A01Z_CTRL1_FIFO_INT_SEL_MASK)
#define QMI8A01Z_CTRL1_FIFO_INT_SEL_GET(x)			((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL1_FIFO_INT_SEL_MASK) >> QMI8A01Z_CTRL1_FIFO_INT_SEL_SHIFT))
#define QMI8A01Z_CTRL1_SensororDisable_MASK			0x01U
#define QMI8A01Z_CTRL1_SensororDisable_SHIFT		0U
#define QMI8A01Z_CTRL1_SensororDisable_WIDTH		1U
#define QMI8A01Z_CTRL1_SensororDisable_SET(x)		((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL1_SensororDisable_SHIFT) & QMI8A01Z_CTRL1_SensororDisable_MASK)
#define QMI8A01Z_CTRL1_SensororDisable_GET(x)		((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL1_SensororDisable_MASK) >> QMI8A01Z_CTRL1_SensororDisable_SHIFT))

/*!< @} */

/*!< @name Configuration - QMI8A01Z CTRL2 Register */
/*!< @{ */

#define QMI8A01Z_CTRL2_aST_MASK                     0x80U
#define QMI8A01Z_CTRL2_aST_SHIFT                    7U
#define QMI8A01Z_CTRL2_aST_WIDTH                    1U
#define QMI8A01Z_CTRL2_aST_SET(x)                   ((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL2_aST_SHIFT) & QMI8A01Z_CTRL2_aST_MASK)
#define QMI8A01Z_CTRL2_aST_GET(x)                   ((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL2_aST_MASK) >> QMI8A01Z_CTRL2_aST_SHIFT))
#define QMI8A01Z_CTRL2_aFS_MASK                     0x70U
#define QMI8A01Z_CTRL2_aFS_SHIFT                    4U
#define QMI8A01Z_CTRL2_aFS_WIDTH                    3U
#define QMI8A01Z_CTRL2_aFS_SET(x)                   ((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL2_aFS_SHIFT) & QMI8A01Z_CTRL2_aFS_MASK)
#define QMI8A01Z_CTRL2_aFS_GET(x)                   ((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL2_aFS_MASK) >> QMI8A01Z_CTRL2_aFS_SHIFT))
#define QMI8A01Z_CTRL2_aODR_MASK                     0x0fU
#define QMI8A01Z_CTRL2_aODR_SHIFT                    0U
#define QMI8A01Z_CTRL2_aODR_WIDTH                    4U
#define QMI8A01Z_CTRL2_aODR_SET(x)                   ((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL2_aODR_SHIFT) & QMI8A01Z_CTRL2_aODR_MASK)
#define QMI8A01Z_CTRL2_aODR_GET(x)                   ((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL2_aODR_MASK) >> QMI8A01Z_CTRL2_aODR_SHIFT))

/*!< @} */

/*!< @name Configuration - QMI8A01Z CTRL3 Register */
/*!< @{ */

#define QMI8A01Z_CTRL3_gST_MASK                     0x80U
#define QMI8A01Z_CTRL3_gST_SHIFT                    7U
#define QMI8A01Z_CTRL3_gST_WIDTH                    1U
#define QMI8A01Z_CTRL3_gST_SET(x)                   ((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL3_gST_SHIFT) & QMI8A01Z_CTRL3_gST_MASK)
#define QMI8A01Z_CTRL3_gST_GET(x)                   ((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL3_gST_MASK) >> QMI8A01Z_CTRL3_gST_SHIFT))
#define QMI8A01Z_CTRL3_gFS_MASK                     0x70U
#define QMI8A01Z_CTRL3_gFS_SHIFT                    4U
#define QMI8A01Z_CTRL3_gFS_WIDTH                    3U
#define QMI8A01Z_CTRL3_gFS_SET(x)                   ((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL3_gFS_SHIFT) & QMI8A01Z_CTRL3_gFS_MASK)
#define QMI8A01Z_CTRL3_gFS_GET(x)                   ((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL3_gFS_MASK) >> QMI8A01Z_CTRL3_gFS_SHIFT))
#define QMI8A01Z_CTRL3_gODR_MASK                     0x0fU
#define QMI8A01Z_CTRL3_gODR_SHIFT                    0U
#define QMI8A01Z_CTRL3_gODR_WIDTH                    4U
#define QMI8A01Z_CTRL3_gODR_SET(x)                   ((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL3_gODR_SHIFT) & QMI8A01Z_CTRL3_gODR_MASK)
#define QMI8A01Z_CTRL3_gODR_GET(x)                   ((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL3_gODR_MASK) >> QMI8A01Z_CTRL3_gODR_SHIFT))

/*!< @} */

/*!< @name Configuration - QMI8A01Z CTRL5 Register */
/*!< @{ */

#define QMI8A01Z_CTRL5_gLPF_MODE_MASK  				0x60U
#define QMI8A01Z_CTRL5_gLPF_MODE_SHIFT 				5U
#define QMI8A01Z_CTRL5_gLPF_MODE_WIDTH 				2U
#define QMI8A01Z_CTRL5_gLPF_MODE_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL5_gLPF_MODE_SHIFT) & QMI8A01Z_CTRL5_gLPF_MODE_MASK)
#define QMI8A01Z_CTRL5_gLPF_MODE_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL5_gLPF_MODE_MASK) >> QMI8A01Z_CTRL5_gLPF_MODE_SHIFT))
#define QMI8A01Z_CTRL5_gLPF_EN_MASK  				0x10U
#define QMI8A01Z_CTRL5_gLPF_EN_SHIFT 				4U
#define QMI8A01Z_CTRL5_gLPF_EN_WIDTH 				1U
#define QMI8A01Z_CTRL5_gLPF_EN_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL5_gLPF_EN_SHIFT) & QMI8A01Z_CTRL5_gLPF_EN_MASK)
#define QMI8A01Z_CTRL5_gLPF_EN_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL5_gLPF_EN_MASK) >> QMI8A01Z_CTRL5_gLPF_EN_SHIFT))
#define QMI8A01Z_CTRL5_aLPF_MODE_MASK  				0x06U
#define QMI8A01Z_CTRL5_aLPF_MODE_SHIFT 				1U
#define QMI8A01Z_CTRL5_aLPF_MODE_WIDTH 				2U
#define QMI8A01Z_CTRL5_aLPF_MODE_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL5_aLPF_MODE_SHIFT) & QMI8A01Z_CTRL5_aLPF_MODE_MASK)
#define QMI8A01Z_CTRL5_aLPF_MODE_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL5_aLPF_MODE_MASK) >> QMI8A01Z_CTRL5_aLPF_MODE_SHIFT))
#define QMI8A01Z_CTRL5_aLPF_EN_MASK  				0x01U
#define QMI8A01Z_CTRL5_aLPF_EN_SHIFT 				0U
#define QMI8A01Z_CTRL5_aLPF_EN_WIDTH 				1U
#define QMI8A01Z_CTRL5_aLPF_EN_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL5_aLPF_EN_SHIFT) & QMI8A01Z_CTRL5_aLPF_EN_MASK)
#define QMI8A01Z_CTRL5_aLPF_EN_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL5_aLPF_EN_MASK) >> QMI8A01Z_CTRL5_aLPF_EN_SHIFT))

/*!< @} */

/*!< @name Configuration - QMI8A01Z CTRL7 Register */
/*!< @{ */

#define QMI8A01Z_CTRL7_SyncSample_MASK  			0x80U
#define QMI8A01Z_CTRL7_SyncSample_SHIFT 			7U
#define QMI8A01Z_CTRL7_SyncSample_WIDTH 			1U
#define QMI8A01Z_CTRL7_SyncSample_SET(x)			((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL7_SyncSample_SHIFT) & QMI8A01Z_CTRL7_SyncSample_MASK)
#define QMI8A01Z_CTRL7_SyncSample_GET(x)			((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL7_SyncSample_MASK) >> QMI8A01Z_CTRL7_SyncSample_SHIFT))
#define QMI8A01Z_CTRL7_DRDY_DIS_MASK  				0x20U
#define QMI8A01Z_CTRL7_DRDY_DIS_SHIFT 				5U
#define QMI8A01Z_CTRL7_DRDY_DIS_WIDTH 				1U
#define QMI8A01Z_CTRL7_DRDY_DIS_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL7_DRDY_DIS_SHIFT) & QMI8A01Z_CTRL7_DRDY_DIS_MASK)
#define QMI8A01Z_CTRL7_DRDY_DIS_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL7_DRDY_DIS_MASK) >> QMI8A01Z_CTRL7_DRDY_DIS_SHIFT))
#define QMI8A01Z_CTRL7_gSN_MASK  					0x10U
#define QMI8A01Z_CTRL7_gSN_SHIFT 					4U
#define QMI8A01Z_CTRL7_gSN_WIDTH 					1U
#define QMI8A01Z_CTRL7_gSN_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL7_gSN_SHIFT) & QMI8A01Z_CTRL7_gSN_MASK)
#define QMI8A01Z_CTRL7_gSN_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL7_gSN_MASK) >> QMI8A01Z_CTRL7_gSN_SHIFT))
#define QMI8A01Z_CTRL7_gEN_MASK  					0x02U
#define QMI8A01Z_CTRL7_gEN_SHIFT 					1U
#define QMI8A01Z_CTRL7_gEN_WIDTH 					1U
#define QMI8A01Z_CTRL7_gEN_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL7_gEN_SHIFT) & QMI8A01Z_CTRL7_gEN_MASK)
#define QMI8A01Z_CTRL7_gEN_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL7_gEN_MASK) >> QMI8A01Z_CTRL7_gEN_SHIFT))
#define QMI8A01Z_CTRL7_aEN_MASK  					0x01U
#define QMI8A01Z_CTRL7_aEN_SHIFT 					0U
#define QMI8A01Z_CTRL7_aEN_WIDTH 					1U
#define QMI8A01Z_CTRL7_aEN_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL7_aEN_SHIFT) & QMI8A01Z_CTRL7_aEN_MASK)
#define QMI8A01Z_CTRL7_aEN_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL7_aEN_MASK) >> QMI8A01Z_CTRL7_aEN_SHIFT))

/*!< @} */

/*!< @name Configuration - QMI8A01Z CTRL8 Register */
/*!< @{ */

#define QMI8A01Z_CTRL8_CTRL9_HandShake_Type_MASK  		0x80U
#define QMI8A01Z_CTRL8_CTRL9_HandShake_Type_SHIFT 		7U
#define QMI8A01Z_CTRL8_CTRL9_HandShake_Type_WIDTH 		1U
#define QMI8A01Z_CTRL8_CTRL9_HandShake_Type_SET(x)		((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL8_CTRL9_HandShake_Type_SHIFT) & QMI8A01Z_CTRL8_CTRL9_HandShake_Type_MASK)
#define QMI8A01Z_CTRL8_CTRL9_HandShake_Type_GET(x)		((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL8_CTRL9_HandShake_Type_MASK) >> QMI8A01Z_CTRL8_CTRL9_HandShake_Type_SHIFT))
#define QMI8A01Z_CTRL8_ACTIVITY_INT_SEL_MASK			0x40U
#define QMI8A01Z_CTRL8_ACTIVITY_INT_SEL_SHIFT			6U
#define QMI8A01Z_CTRL8_ACTIVITY_INT_SEL_WIDTH			1U
#define QMI8A01Z_CTRL8_ACTIVITY_INT_SEL_SET(x)			((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL8_ACTIVITY_INT_SEL_SHIFT) & QMI8A01Z_CTRL8_ACTIVITY_INT_SEL_MASK)
#define QMI8A01Z_CTRL8_ACTIVITY_INT_SEL_GET(x)			((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL8_ACTIVITY_INT_SEL_MASK) >> QMI8A01Z_CTRL8_ACTIVITY_INT_SEL_SHIFT))
#define QMI8A01Z_CTRL8_Sig_Motion_EN_MASK				0x08U
#define QMI8A01Z_CTRL8_Sig_Motion_EN_SHIFT				3U
#define QMI8A01Z_CTRL8_Sig_Motion_EN_WIDTH				1U
#define QMI8A01Z_CTRL8_Sig_Motion_EN_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL8_Sig_Motion_EN_SHIFT) & QMI8A01Z_CTRL8_Sig_Motion_EN_MASK)
#define QMI8A01Z_CTRL8_Sig_Motion_EN_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL8_Sig_Motion_EN_MASK) >> QMI8A01Z_CTRL8_Sig_Motion_EN_SHIFT))
#define QMI8A01Z_CTRL8_No_Motion_EN_MASK				0x04U
#define QMI8A01Z_CTRL8_No_Motion_EN_SHIFT				2U
#define QMI8A01Z_CTRL8_No_Motion_EN_WIDTH				1U
#define QMI8A01Z_CTRL8_No_Motion_EN_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL8_No_Motion_EN_SHIFT) & QMI8A01Z_CTRL8_No_Motion_EN_MASK)
#define QMI8A01Z_CTRL8_No_Motion_EN_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL8_No_Motion_EN_MASK) >> QMI8A01Z_CTRL8_No_Motion_EN_SHIFT))
#define QMI8A01Z_CTRL8_Any_Motion_EN_MASK				0x02U
#define QMI8A01Z_CTRL8_Any_Motion_EN_SHIFT				1U
#define QMI8A01Z_CTRL8_Any_Motion_EN_WIDTH				1U
#define QMI8A01Z_CTRL8_Any_Motion_EN_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL8_Any_Motion_EN_SHIFT) & QMI8A01Z_CTRL8_Any_Motion_EN_MASK)
#define QMI8A01Z_CTRL8_Any_Motion_EN_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL8_Any_Motion_EN_MASK) >> QMI8A01Z_CTRL8_Any_Motion_EN_SHIFT))
#define QMI8A01Z_CTRL8_Tap_EN_MASK						0x01U
#define QMI8A01Z_CTRL8_Tap_EN_SHIFT						0U
#define QMI8A01Z_CTRL8_Tap_EN_WIDTH						1U
#define QMI8A01Z_CTRL8_Tap_EN_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_CTRL8_Tap_EN_SHIFT) & QMI8A01Z_CTRL8_Tap_EN_MASK)
#define QMI8A01Z_CTRL8_Tap_EN_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_CTRL8_Tap_EN_MASK) >> QMI8A01Z_CTRL8_Tap_EN_SHIFT))

/*!< @} */

/*!< @name FIFO - QMI8A01Z FIFO_WTM_TH Register */
/*!< @{ */

#define QMI8A01Z_FIFO_WTM_MASK  						0xffU
#define QMI8A01Z_FIFO_WTM_SHIFT 						0U
#define QMI8A01Z_FIFO_WTM_WIDTH 						8U
#define QMI8A01Z_FIFO_WTM_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_WTM_SHIFT) & QMI8A01Z_FIFO_WTM_MASK)
#define QMI8A01Z_FIFO_WTM_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_WTM_MASK) >> QMI8A01Z_FIFO_WTM_SHIFT))

/*!< @} */

/*!< @name FIFO - QMI8A01Z FIFO_CTRL Register */
/*!< @{ */

#define QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_MASK  			0x80U
#define QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_SHIFT 			7U
#define QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_WIDTH 			1U
#define QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_SET(x)			((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_SHIFT) & QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_MASK)
#define QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_GET(x)			((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_MASK) >> QMI8A01Z_FIFO_CTRL_FIFO_RD_MODE_SHIFT))
#define QMI8A01Z_FIFO_CTRL_FIFO_SIZE_MASK  				0x0cU
#define QMI8A01Z_FIFO_CTRL_FIFO_SIZE_SHIFT 				2U
#define QMI8A01Z_FIFO_CTRL_FIFO_SIZE_WIDTH 				2U
#define QMI8A01Z_FIFO_CTRL_FIFO_SIZE_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_CTRL_FIFO_SIZE_SHIFT) & QMI8A01Z_FIFO_CTRL_FIFO_SIZE_MASK)
#define QMI8A01Z_FIFO_CTRL_FIFO_SIZE_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_CTRL_FIFO_SIZE_MASK) >> QMI8A01Z_FIFO_CTRL_FIFO_SIZE_SHIFT))
#define QMI8A01Z_FIFO_CTRL_FIFO_MODE_MASK  				0x03U
#define QMI8A01Z_FIFO_CTRL_FIFO_MODE_SHIFT 				0U
#define QMI8A01Z_FIFO_CTRL_FIFO_MODE_WIDTH 				2U
#define QMI8A01Z_FIFO_CTRL_FIFO_MODE_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_CTRL_FIFO_MODE_SHIFT) & QMI8A01Z_FIFO_CTRL_FIFO_MODE_MASK)
#define QMI8A01Z_FIFO_CTRL_FIFO_MODE_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_CTRL_FIFO_MODE_MASK) >> QMI8A01Z_FIFO_CTRL_FIFO_MODE_SHIFT))

/*!< @} */

/*!< @name FIFO - QMI8A01Z FIFO_SMPL_CNT Register */
/*!< @{ */

#define QMI8A01Z_FIFO_SMPL_CNT_LSB_MASK  				0xffU
#define QMI8A01Z_FIFO_SMPL_CNT_LSB_SHIFT 				0U
#define QMI8A01Z_FIFO_SMPL_CNT_LSB_WIDTH 				8U
#define QMI8A01Z_FIFO_SMPL_CNT_LSB_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_SMPL_CNT_LSB_SHIFT) & QMI8A01Z_FIFO_SMPL_CNT_LSB_MASK)
#define QMI8A01Z_FIFO_SMPL_CNT_LSB_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_SMPL_CNT_LSB_MASK) >> QMI8A01Z_FIFO_SMPL_CNT_LSB_SHIFT))

/*!< @} */

/*!< @name FIFO - QMI8A01Z FIFO_STATUS Register */
/*!< @{ */

#define QMI8A01Z_FIFO_STATUS_FIFO_FULL_MASK  			0x80U
#define QMI8A01Z_FIFO_STATUS_FIFO_FULL_SHIFT 			7U
#define QMI8A01Z_FIFO_STATUS_FIFO_FULL_WIDTH 			1U
#define QMI8A01Z_FIFO_STATUS_FIFO_FULL_SET(x)			((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_STATUS_FIFO_FULL_SHIFT) & QMI8A01Z_FIFO_STATUS_FIFO_FULL_MASK)
#define QMI8A01Z_FIFO_STATUS_FIFO_FULL_GET(x)			((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_STATUS_FIFO_FULL_MASK) >> QMI8A01Z_FIFO_STATUS_FIFO_FULL_SHIFT))
#define QMI8A01Z_FIFO_STATUS_FIFO_WTM_MASK  			0x40U
#define QMI8A01Z_FIFO_STATUS_FIFO_WTM_SHIFT 			6U
#define QMI8A01Z_FIFO_STATUS_FIFO_WTM_WIDTH 			1U
#define QMI8A01Z_FIFO_STATUS_FIFO_WTM_SET(x)			((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_STATUS_FIFO_WTM_SHIFT) & QMI8A01Z_FIFO_STATUS_FIFO_WTM_MASK)
#define QMI8A01Z_FIFO_STATUS_FIFO_WTM_GET(x)			((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_STATUS_FIFO_WTM_MASK) >> QMI8A01Z_FIFO_STATUS_FIFO_WTM_SHIFT))
#define QMI8A01Z_FIFO_STATUS_FIFO_OVFLOW_MASK  			0x20U
#define QMI8A01Z_FIFO_STATUS_FIFO_OVFLOW_SHIFT 			5U
#define QMI8A01Z_FIFO_STATUS_FIFO_OVFLOW_WIDTH 			1U
#define QMI8A01Z_FIFO_STATUS_FIFO_OVFLOW_SET(x)			((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_STATUS_FIFO_OVFLOW_SHIFT) & QMI8A01Z_FIFO_STATUS_FIFO_OVFLOW_MASK)
#define QMI8A01Z_FIFO_STATUS_FIFO_OVFLOW_GET(x)			((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_STATUS_FIFO_OVFLOW_MASK) >> QMI8A01Z_FIFO_STATUS_FIFO_OVFLOW_SHIFT))
#define QMI8A01Z_FIFO_STATUS_FIFO_NOT_EMPTY_MASK  		0x10U
#define QMI8A01Z_FIFO_STATUS_FIFO_NOT_EMPTY_SHIFT 		4U
#define QMI8A01Z_FIFO_STATUS_FIFO_NOT_EMPTY_WIDTH 		1U
#define QMI8A01Z_FIFO_STATUS_FIFO_NOT_EMPTY_SET(x)		((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_STATUS_FIFO_NOT_EMPTY_SHIFT) & QMI8A01Z_FIFO_STATUS_FIFO_NOT_EMPTY_MASK)
#define QMI8A01Z_FIFO_STATUS_FIFO_NOT_EMPTY_GET(x)		((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_STATUS_FIFO_NOT_EMPTY_MASK) >> QMI8A01Z_FIFO_STATUS_FIFO_NOT_EMPTY_SHIFT))
#define QMI8A01Z_FIFO_STATUS_FIFO_SMPL_CNT_MSB_MASK  	0x03U
#define QMI8A01Z_FIFO_STATUS_FIFO_SMPL_CNT_MSB_SHIFT 	0U
#define QMI8A01Z_FIFO_STATUS_FIFO_SMPL_CNT_MSB_WIDTH 	2U
#define QMI8A01Z_FIFO_STATUS_FIFO_SMPL_CNT_MSB_SET(x)	((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_STATUS_FIFO_SMPL_CNT_MSB_SHIFT) & QMI8A01Z_FIFO_STATUS_FIFO_SMPL_CNT_MSB_MASK)
#define QMI8A01Z_FIFO_STATUS_FIFO_SMPL_CNT_MSB_GET(x)	((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_STATUS_FIFO_SMPL_CNT_MSB_MASK) >> QMI8A01Z_FIFO_STATUS_FIFO_SMPL_CNT_MSB_SHIFT))

/*!< @} */

/*!< @name FIFO - QMI8A01Z FIFO_DATA Register */
/*!< @{ */

#define QMI8A01Z_FIFO_DATA_MASK  						0xffU
#define QMI8A01Z_FIFO_DATA_SHIFT 						0U
#define QMI8A01Z_FIFO_DATA_WIDTH 						8U
#define QMI8A01Z_FIFO_DATA_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_FIFO_DATA_SHIFT) & QMI8A01Z_FIFO_DATA_MASK)
#define QMI8A01Z_FIFO_DATA_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_FIFO_DATA_MASK) >> QMI8A01Z_FIFO_DATA_SHIFT))

/*!< @} */

/*!< @name Status and Time Stamp - QMI8A01Z STATUSINT Register */
/*!< @{ */

#define QMI8A01Z_STATUSINT_Ctrl9CmdDone_MASK  			0x80U
#define QMI8A01Z_STATUSINT_Ctrl9CmdDone_SHIFT 			7U
#define QMI8A01Z_STATUSINT_Ctrl9CmdDone_WIDTH 			1U
#define QMI8A01Z_STATUSINT_Ctrl9CmdDone_SET(x)			((uint8_t)(((uint8_t)(x)) << QMI8A01Z_STATUSINT_Ctrl9CmdDone_SHIFT) & QMI8A01Z_STATUSINT_Ctrl9CmdDone_MASK)
#define QMI8A01Z_STATUSINT_Ctrl9CmdDone_GET(x)			((uint8_t)((((uint8_t)(x))&QMI8A01Z_STATUSINT_Ctrl9CmdDone_MASK) >> QMI8A01Z_STATUSINT_Ctrl9CmdDone_SHIFT))
#define QMI8A01Z_STATUSINT_Locked_MASK  				0x02U
#define QMI8A01Z_STATUSINT_Locked_SHIFT 				1U
#define QMI8A01Z_STATUSINT_Locked_WIDTH 				1U
#define QMI8A01Z_STATUSINT_Locked_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_STATUSINT_Locked_SHIFT) & QMI8A01Z_STATUSINT_Locked_MASK)
#define QMI8A01Z_STATUSINT_Locked_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_STATUSINT_Locked_MASK) >> QMI8A01Z_STATUSINT_Locked_SHIFT))
#define QMI8A01Z_STATUSINT_Avail_MASK  					0x01U
#define QMI8A01Z_STATUSINT_Avail_SHIFT 					0U
#define QMI8A01Z_STATUSINT_Avail_WIDTH 					1U
#define QMI8A01Z_STATUSINT_Avail_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_STATUSINT_Avail_SHIFT) & QMI8A01Z_STATUSINT_Avail_MASK)
#define QMI8A01Z_STATUSINT_Avail_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_STATUSINT_Avail_MASK) >> QMI8A01Z_STATUSINT_Avail_SHIFT))

/*!< @} */

/*!< @name Status and Time Stamp - QMI8A01Z STATUS0 Register */
/*!< @{ */

#define QMI8A01Z_STATUS0_gDA_MASK  						0x02U
#define QMI8A01Z_STATUS0_gDA_SHIFT 						1U
#define QMI8A01Z_STATUS0_gDA_WIDTH 						1U
#define QMI8A01Z_STATUS0_gDA_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_STATUS0_gDA_SHIFT) & QMI8A01Z_STATUS0_gDA_MASK)
#define QMI8A01Z_STATUS0_gDA_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_STATUS0_gDA_MASK) >> QMI8A01Z_STATUS0_gDA_SHIFT))
#define QMI8A01Z_STATUS0_aDA_MASK  						0x01U
#define QMI8A01Z_STATUS0_aDA_SHIFT 						0U
#define QMI8A01Z_STATUS0_aDA_WIDTH 						1U
#define QMI8A01Z_STATUS0_aDA_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_STATUS0_aDA_SHIFT) & QMI8A01Z_STATUS0_aDA_MASK)
#define QMI8A01Z_STATUS0_aDA_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_STATUS0_aDA_MASK) >> QMI8A01Z_STATUS0_aDA_SHIFT))

/*!< @} */

/*!< @name Status and Time Stamp - QMI8A01Z STATUS1 Register */
/*!< @{ */

#define QMI8A01Z_STATUS1_Significant_Motion_MASK  		0x80U
#define QMI8A01Z_STATUS1_Significant_Motion_SHIFT 		7U
#define QMI8A01Z_STATUS1_Significant_Motion_WIDTH 		1U
#define QMI8A01Z_STATUS1_Significant_Motion_SET(x)		((uint8_t)(((uint8_t)(x)) << QMI8A01Z_STATUS1_Significant_Motion_SHIFT) & QMI8A01Z_STATUS1_Significant_Motion_MASK)
#define QMI8A01Z_STATUS1_Significant_Motion_GET(x)		((uint8_t)((((uint8_t)(x))&QMI8A01Z_STATUS1_Significant_Motion_MASK) >> QMI8A01Z_STATUS1_Significant_Motion_SHIFT))
#define QMI8A01Z_STATUS1_No_Motion_MASK					0x40U
#define QMI8A01Z_STATUS1_No_Motion_SHIFT				6U
#define QMI8A01Z_STATUS1_No_Motion_WIDTH				1U
#define QMI8A01Z_STATUS1_No_Motion_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_STATUS1_No_Motion_SHIFT) & QMI8A01Z_STATUS1_No_Motion_MASK)
#define QMI8A01Z_STATUS1_No_Motion_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_STATUS1_No_Motion_MASK) >> QMI8A01Z_STATUS1_No_Motion_SHIFT))
#define QMI8A01Z_STATUS1_Any_Motion_MASK				0x20U
#define QMI8A01Z_STATUS1_Any_Motion_SHIFT				5U
#define QMI8A01Z_STATUS1_Any_Motion_WIDTH				1U
#define QMI8A01Z_STATUS1_Any_Motion_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_STATUS1_Any_Motion_SHIFT) & QMI8A01Z_STATUS1_Any_Motion_MASK)
#define QMI8A01Z_STATUS1_Any_Motion_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_STATUS1_Any_Motion_MASK) >> QMI8A01Z_STATUS1_Any_Motion_SHIFT))
#define QMI8A01Z_STATUS1_TAP_MASK						0x02U
#define QMI8A01Z_STATUS1_TAP_SHIFT						1U
#define QMI8A01Z_STATUS1_TAP_WIDTH						1U
#define QMI8A01Z_STATUS1_TAP_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_STATUS1_TAP_SHIFT) & QMI8A01Z_STATUS1_TAP_MASK)
#define QMI8A01Z_STATUS1_TAP_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_STATUS1_TAP_MASK) >> QMI8A01Z_STATUS1_TAP_SHIFT))

/*!< @} */

/*!< @name Status and Time Stamp - QMI8A01Z TIMESTAMP Register */
/*!< @{ */

#define QMI8A01Z_TIMESTAMP_L_MASK  						0xffU
#define QMI8A01Z_TIMESTAMP_L_SHIFT 						0U
#define QMI8A01Z_TIMESTAMP_L_WIDTH 						8U
#define QMI8A01Z_TIMESTAMP_L_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_TIMESTAMP_L_SHIFT) & QMI8A01Z_TIMESTAMP_L_MASK)
#define QMI8A01Z_TIMESTAMP_L_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_TIMESTAMP_L_MASK) >> QMI8A01Z_TIMESTAMP_L_SHIFT))
#define QMI8A01Z_TIMESTAMP_M_MASK  						0xffU
#define QMI8A01Z_TIMESTAMP_M_SHIFT 						0U
#define QMI8A01Z_TIMESTAMP_M_WIDTH 						8U
#define QMI8A01Z_TIMESTAMP_M_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_TIMESTAMP_M_SHIFT) & QMI8A01Z_TIMESTAMP_M_MASK)
#define QMI8A01Z_TIMESTAMP_M_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_TIMESTAMP_M_MASK) >> QMI8A01Z_TIMESTAMP_M_SHIFT))
#define QMI8A01Z_TIMESTAMP_H_MASK  						0xffU
#define QMI8A01Z_TIMESTAMP_H_SHIFT 						0U
#define QMI8A01Z_TIMESTAMP_H_WIDTH 						8U
#define QMI8A01Z_TIMESTAMP_H_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_TIMESTAMP_H_SHIFT) & QMI8A01Z_TIMESTAMP_H_MASK)
#define QMI8A01Z_TIMESTAMP_H_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_TIMESTAMP_H_MASK) >> QMI8A01Z_TIMESTAMP_H_SHIFT))

/*!< @} */

/*!< @name Sensor Data Output - QMI8A01Z TEMP[H,L] Register */
/*!< @{ */

#define QMI8A01Z_TEMP_HL_TEMP_L_MASK  							0xffU
#define QMI8A01Z_TEMP_HL_TEMP_L_SHIFT 							0U
#define QMI8A01Z_TEMP_HL_TEMP_L_WIDTH 							8U
#define QMI8A01Z_TEMP_HL_TEMP_L_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_TEMP_HL_TEMP_L_SHIFT) & QMI8A01Z_TEMP_HL_TEMP_L_MASK)
#define QMI8A01Z_TEMP_HL_TEMP_L_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_TEMP_HL_TEMP_L_MASK) >> QMI8A01Z_TEMP_HL_TEMP_L_SHIFT))
#define QMI8A01Z_TEMP_HL_TEMP_H_MASK  							0xffU
#define QMI8A01Z_TEMP_HL_TEMP_H_SHIFT 							0U
#define QMI8A01Z_TEMP_HL_TEMP_H_WIDTH 							8U
#define QMI8A01Z_TEMP_HL_TEMP_H_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_TEMP_HL_TEMP_H_SHIFT) & QMI8A01Z_TEMP_HL_TEMP_H_MASK)
#define QMI8A01Z_TEMP_HL_TEMP_H_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_TEMP_HL_TEMP_H_MASK) >> QMI8A01Z_TEMP_HL_TEMP_H_SHIFT))

/*!< @} */

/*!< @name Sensor Data Output - QMI8A01Z A[X,Y,Z]_[H,L] Register */
/*!< @{ */

#define QMI8A01Z_A_XYZ_HL_AX_L_MASK  							0xffU
#define QMI8A01Z_A_XYZ_HL_AX_L_SHIFT 							0U
#define QMI8A01Z_A_XYZ_HL_AX_L_WIDTH 							8U
#define QMI8A01Z_A_XYZ_HL_AX_L_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_A_XYZ_HL_AX_L_SHIFT) & QMI8A01Z_A_XYZ_HL_AX_L_MASK)
#define QMI8A01Z_A_XYZ_HL_AX_L_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_A_XYZ_HL_AX_L_MASK) >> QMI8A01Z_A_XYZ_HL_AX_L_SHIFT))
#define QMI8A01Z_A_XYZ_HL_AX_H_MASK  							0xffU
#define QMI8A01Z_A_XYZ_HL_AX_H_SHIFT 							0U
#define QMI8A01Z_A_XYZ_HL_AX_H_WIDTH 							8U
#define QMI8A01Z_A_XYZ_HL_AX_H_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_A_XYZ_HL_AX_H_SHIFT) & QMI8A01Z_A_XYZ_HL_AX_H_MASK)
#define QMI8A01Z_A_XYZ_HL_AX_H_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_A_XYZ_HL_AX_H_MASK) >> QMI8A01Z_A_XYZ_HL_AX_H_SHIFT))
#define QMI8A01Z_A_XYZ_HL_AY_L_MASK  							0xffU
#define QMI8A01Z_A_XYZ_HL_AY_L_SHIFT 							0U
#define QMI8A01Z_A_XYZ_HL_AY_L_WIDTH 							8U
#define QMI8A01Z_A_XYZ_HL_AY_L_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_A_XYZ_HL_AY_L_SHIFT) & QMI8A01Z_A_XYZ_HL_AY_L_MASK)
#define QMI8A01Z_A_XYZ_HL_AY_L_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_A_XYZ_HL_AY_L_MASK) >> QMI8A01Z_A_XYZ_HL_AY_L_SHIFT))
#define QMI8A01Z_A_XYZ_HL_AY_H_MASK  							0xffU
#define QMI8A01Z_A_XYZ_HL_AY_H_SHIFT 							0U
#define QMI8A01Z_A_XYZ_HL_AY_H_WIDTH 							8U
#define QMI8A01Z_A_XYZ_HL_AY_H_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_A_XYZ_HL_AY_H_SHIFT) & QMI8A01Z_A_XYZ_HL_AY_H_MASK)
#define QMI8A01Z_A_XYZ_HL_AY_H_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_A_XYZ_HL_AY_H_MASK) >> QMI8A01Z_A_XYZ_HL_AY_H_SHIFT))
#define QMI8A01Z_A_XYZ_HL_AZ_L_MASK  							0xffU
#define QMI8A01Z_A_XYZ_HL_AZ_L_SHIFT 							0U
#define QMI8A01Z_A_XYZ_HL_AZ_L_WIDTH 							8U
#define QMI8A01Z_A_XYZ_HL_AZ_L_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_A_XYZ_HL_AZ_L_SHIFT) & QMI8A01Z_A_XYZ_HL_AZ_L_MASK)
#define QMI8A01Z_A_XYZ_HL_AZ_L_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_A_XYZ_HL_AZ_L_MASK) >> QMI8A01Z_A_XYZ_HL_AZ_L_SHIFT))
#define QMI8A01Z_A_XYZ_HL_AZ_H_MASK  							0xffU
#define QMI8A01Z_A_XYZ_HL_AZ_H_SHIFT 							0U
#define QMI8A01Z_A_XYZ_HL_AZ_H_WIDTH 							8U
#define QMI8A01Z_A_XYZ_HL_AZ_H_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_A_XYZ_HL_AZ_H_SHIFT) & QMI8A01Z_A_XYZ_HL_AZ_H_MASK)
#define QMI8A01Z_A_XYZ_HL_AZ_H_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_A_XYZ_HL_AZ_H_MASK) >> QMI8A01Z_A_XYZ_HL_AZ_H_SHIFT))

/*!< @} */

/*!< @name Sensor Data Output - QMI8A01Z G[X,Y,Z]_[H,L] Register */
/*!< @{ */

#define QMI8A01Z_G_XYZ_HL_GX_L_MASK  							0xffU
#define QMI8A01Z_G_XYZ_HL_GX_L_SHIFT 							0U
#define QMI8A01Z_G_XYZ_HL_GX_L_WIDTH 							8U
#define QMI8A01Z_G_XYZ_HL_GX_L_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_G_XYZ_HL_GX_L_SHIFT) & QMI8A01Z_G_XYZ_HL_GX_L_MASK)
#define QMI8A01Z_G_XYZ_HL_GX_L_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_G_XYZ_HL_GX_L_MASK) >> QMI8A01Z_G_XYZ_HL_GX_L_SHIFT))
#define QMI8A01Z_G_XYZ_HL_GX_H_MASK  							0xffU
#define QMI8A01Z_G_XYZ_HL_GX_H_SHIFT 							0U
#define QMI8A01Z_G_XYZ_HL_GX_H_WIDTH 							8U
#define QMI8A01Z_G_XYZ_HL_GX_H_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_G_XYZ_HL_GX_H_SHIFT) & QMI8A01Z_G_XYZ_HL_GX_H_MASK)
#define QMI8A01Z_G_XYZ_HL_GX_H_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_G_XYZ_HL_GX_H_MASK) >> QMI8A01Z_G_XYZ_HL_GX_H_SHIFT))
#define QMI8A01Z_G_XYZ_HL_GY_L_MASK  							0xffU
#define QMI8A01Z_G_XYZ_HL_GY_L_SHIFT 							0U
#define QMI8A01Z_G_XYZ_HL_GY_L_WIDTH 							8U
#define QMI8A01Z_G_XYZ_HL_GY_L_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_G_XYZ_HL_GY_L_SHIFT) & QMI8A01Z_G_XYZ_HL_GY_L_MASK)
#define QMI8A01Z_G_XYZ_HL_GY_L_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_G_XYZ_HL_GY_L_MASK) >> QMI8A01Z_G_XYZ_HL_GY_L_SHIFT))
#define QMI8A01Z_G_XYZ_HL_GY_H_MASK  							0xffU
#define QMI8A01Z_G_XYZ_HL_GY_H_SHIFT 							0U
#define QMI8A01Z_G_XYZ_HL_GY_H_WIDTH 							8U
#define QMI8A01Z_G_XYZ_HL_GY_H_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_G_XYZ_HL_GY_H_SHIFT) & QMI8A01Z_G_XYZ_HL_GY_H_MASK)
#define QMI8A01Z_G_XYZ_HL_GY_H_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_G_XYZ_HL_GY_H_MASK) >> QMI8A01Z_G_XYZ_HL_GY_H_SHIFT))
#define QMI8A01Z_G_XYZ_HL_GZ_L_MASK  							0xffU
#define QMI8A01Z_G_XYZ_HL_GZ_L_SHIFT 							0U
#define QMI8A01Z_G_XYZ_HL_GZ_L_WIDTH 							8U
#define QMI8A01Z_G_XYZ_HL_GZ_L_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_G_XYZ_HL_GZ_L_SHIFT) & QMI8A01Z_G_XYZ_HL_GZ_L_MASK)
#define QMI8A01Z_G_XYZ_HL_GZ_L_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_G_XYZ_HL_GZ_L_MASK) >> QMI8A01Z_G_XYZ_HL_GZ_L_SHIFT))
#define QMI8A01Z_G_XYZ_HL_GZ_H_MASK  							0xffU
#define QMI8A01Z_G_XYZ_HL_GZ_H_SHIFT 							0U
#define QMI8A01Z_G_XYZ_HL_GZ_H_WIDTH 							8U
#define QMI8A01Z_G_XYZ_HL_GZ_H_SET(x)							((uint8_t)(((uint8_t)(x)) << QMI8A01Z_G_XYZ_HL_GZ_H_SHIFT) & QMI8A01Z_G_XYZ_HL_GZ_H_MASK)
#define QMI8A01Z_G_XYZ_HL_GZ_H_GET(x)							((uint8_t)((((uint8_t)(x))&QMI8A01Z_G_XYZ_HL_GZ_H_MASK) >> QMI8A01Z_G_XYZ_HL_GZ_H_SHIFT))

/*!< @} */

/*!< @name Calibration-on-Demand - QMI8A01Z COD_STATUS Register */
/*!< @{ */

#define QMI8A01Z_COD_STATUS_X_Limit_L_Fail_MASK  				0x80U
#define QMI8A01Z_COD_STATUS_X_Limit_L_Fail_SHIFT 				7U
#define QMI8A01Z_COD_STATUS_X_Limit_L_Fail_WIDTH 				1U
#define QMI8A01Z_COD_STATUS_X_Limit_L_Fail_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_COD_STATUS_X_Limit_L_Fail_SHIFT) & QMI8A01Z_COD_STATUS_X_Limit_L_Fail_MASK)
#define QMI8A01Z_COD_STATUS_X_Limit_L_Fail_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_COD_STATUS_X_Limit_L_Fail_MASK) >> QMI8A01Z_COD_STATUS_X_Limit_L_Fail_SHIFT))
#define QMI8A01Z_COD_STATUS_X_Limit_H_Fail_MASK  				0x40U
#define QMI8A01Z_COD_STATUS_X_Limit_H_Fail_SHIFT 				6U
#define QMI8A01Z_COD_STATUS_X_Limit_H_Fail_WIDTH 				1U
#define QMI8A01Z_COD_STATUS_X_Limit_H_Fail_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_COD_STATUS_X_Limit_H_Fail_SHIFT) & QMI8A01Z_COD_STATUS_X_Limit_H_Fail_MASK)
#define QMI8A01Z_COD_STATUS_X_Limit_H_Fail_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_COD_STATUS_X_Limit_H_Fail_MASK) >> QMI8A01Z_COD_STATUS_X_Limit_H_Fail_SHIFT))
#define QMI8A01Z_COD_STATUS_Y_Limit_L_Fail_MASK  				0x20U
#define QMI8A01Z_COD_STATUS_Y_Limit_L_Fail_SHIFT 				5U
#define QMI8A01Z_COD_STATUS_Y_Limit_L_Fail_WIDTH 				1U
#define QMI8A01Z_COD_STATUS_Y_Limit_L_Fail_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_COD_STATUS_Y_Limit_L_Fail_SHIFT) & QMI8A01Z_COD_STATUS_Y_Limit_L_Fail_MASK)
#define QMI8A01Z_COD_STATUS_Y_Limit_L_Fail_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_COD_STATUS_Y_Limit_L_Fail_MASK) >> QMI8A01Z_COD_STATUS_Y_Limit_L_Fail_SHIFT))
#define QMI8A01Z_COD_STATUS_Y_Limit_H_Fail_MASK  				0x10U
#define QMI8A01Z_COD_STATUS_Y_Limit_H_Fail_SHIFT 				4U
#define QMI8A01Z_COD_STATUS_Y_Limit_H_Fail_WIDTH 				1U
#define QMI8A01Z_COD_STATUS_Y_Limit_H_Fail_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_COD_STATUS_Y_Limit_H_Fail_SHIFT) & QMI8A01Z_COD_STATUS_Y_Limit_H_Fail_MASK)
#define QMI8A01Z_COD_STATUS_Y_Limit_H_Fail_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_COD_STATUS_Y_Limit_H_Fail_MASK) >> QMI8A01Z_COD_STATUS_Y_Limit_H_Fail_SHIFT))
#define QMI8A01Z_COD_STATUS_Accel_Check_MASK  					0x08U
#define QMI8A01Z_COD_STATUS_Accel_Check_SHIFT 					3U
#define QMI8A01Z_COD_STATUS_Accel_Check_WIDTH 					1U
#define QMI8A01Z_COD_STATUS_Accel_Check_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_COD_STATUS_Accel_Check_SHIFT) & QMI8A01Z_COD_STATUS_Accel_Check_MASK)
#define QMI8A01Z_COD_STATUS_Accel_Check_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_COD_STATUS_Accel_Check_MASK) >> QMI8A01Z_COD_STATUS_Accel_Check_SHIFT))
#define QMI8A01Z_COD_STATUS_Startup_Failed_MASK  				0x04U
#define QMI8A01Z_COD_STATUS_Startup_Failed_SHIFT 				2U
#define QMI8A01Z_COD_STATUS_Startup_Failed_WIDTH 				1U
#define QMI8A01Z_COD_STATUS_Startup_Failed_SET(x)				((uint8_t)(((uint8_t)(x)) << QMI8A01Z_COD_STATUS_Startup_Failed_SHIFT) & QMI8A01Z_COD_STATUS_Startup_Failed_MASK)
#define QMI8A01Z_COD_STATUS_Startup_Failed_GET(x)				((uint8_t)((((uint8_t)(x))&QMI8A01Z_COD_STATUS_Startup_Failed_MASK) >> QMI8A01Z_COD_STATUS_Startup_Failed_SHIFT))
#define QMI8A01Z_COD_STATUS_Gyro_Enabled_MASK  					0x02U
#define QMI8A01Z_COD_STATUS_Gyro_Enabled_SHIFT 					1U
#define QMI8A01Z_COD_STATUS_Gyro_Enabled_WIDTH 					1U
#define QMI8A01Z_COD_STATUS_Gyro_Enabled_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_COD_STATUS_Gyro_Enabled_SHIFT) & QMI8A01Z_COD_STATUS_Gyro_Enabled_MASK)
#define QMI8A01Z_COD_STATUS_Gyro_Enabled_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_COD_STATUS_Gyro_Enabled_MASK) >> QMI8A01Z_COD_STATUS_Gyro_Enabled_SHIFT))
#define QMI8A01Z_COD_STATUS_COD_Failed_MASK  					0x01U
#define QMI8A01Z_COD_STATUS_COD_Failed_SHIFT 					0U
#define QMI8A01Z_COD_STATUS_COD_Failed_WIDTH 					1U
#define QMI8A01Z_COD_STATUS_COD_Failed_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_COD_STATUS_COD_Failed_SHIFT) & QMI8A01Z_COD_STATUS_COD_Failed_MASK)
#define QMI8A01Z_COD_STATUS_COD_Failed_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_COD_STATUS_COD_Failed_MASK) >> QMI8A01Z_COD_STATUS_COD_Failed_SHIFT))

/*!< @} */

/*!< @name Activity Detection Output - QMI8A01Z TAP_STATUS Register */
/*!< @{ */

#define QMI8A01Z_TAP_STATUS_TAP_POLARITY_MASK  					0x80U
#define QMI8A01Z_TAP_STATUS_TAP_POLARITY_SHIFT 					7U
#define QMI8A01Z_TAP_STATUS_TAP_POLARITY_WIDTH 					1U
#define QMI8A01Z_TAP_STATUS_TAP_POLARITY_SET(x)					((uint8_t)(((uint8_t)(x)) << QMI8A01Z_TAP_STATUS_TAP_POLARITY_SHIFT) & QMI8A01Z_TAP_STATUS_TAP_POLARITY_MASK)
#define QMI8A01Z_TAP_STATUS_TAP_POLARITY_GET(x)					((uint8_t)((((uint8_t)(x))&QMI8A01Z_TAP_STATUS_TAP_POLARITY_MASK) >> QMI8A01Z_TAP_STATUS_TAP_POLARITY_SHIFT))
#define QMI8A01Z_TAP_STATUS_TAP_AXIS_MASK  						0x30U
#define QMI8A01Z_TAP_STATUS_TAP_AXIS_SHIFT 						4U
#define QMI8A01Z_TAP_STATUS_TAP_AXIS_WIDTH 						2U
#define QMI8A01Z_TAP_STATUS_TAP_AXIS_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_TAP_STATUS_TAP_AXIS_SHIFT) & QMI8A01Z_TAP_STATUS_TAP_AXIS_MASK)
#define QMI8A01Z_TAP_STATUS_TAP_AXIS_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_TAP_STATUS_TAP_AXIS_MASK) >> QMI8A01Z_TAP_STATUS_TAP_AXIS_SHIFT))
#define QMI8A01Z_TAP_STATUS_TAP_NUM_MASK  						0x03U
#define QMI8A01Z_TAP_STATUS_TAP_NUM_SHIFT 						0U
#define QMI8A01Z_TAP_STATUS_TAP_NUM_WIDTH 						2U
#define QMI8A01Z_TAP_STATUS_TAP_NUM_SET(x)						((uint8_t)(((uint8_t)(x)) << QMI8A01Z_TAP_STATUS_TAP_NUM_SHIFT) & QMI8A01Z_TAP_STATUS_TAP_NUM_MASK)
#define QMI8A01Z_TAP_STATUS_TAP_NUM_GET(x)						((uint8_t)((((uint8_t)(x))&QMI8A01Z_TAP_STATUS_TAP_NUM_MASK) >> QMI8A01Z_TAP_STATUS_TAP_NUM_SHIFT))

/*!< @} */

/*!< @name Reset - QMI8A01Z RESET Register */
/*!< @{ */

#define QMI8A01Z_RESET_MASK  									0xffU
#define QMI8A01Z_RESET_SHIFT 									0U
#define QMI8A01Z_RESET_WIDTH 									8U
#define QMI8A01Z_RESET_SET(x)									((uint8_t)(((uint8_t)(x)) << QMI8A01Z_RESET_SHIFT) & QMI8A01Z_RESET_MASK)
#define QMI8A01Z_RESET_GET(x)									((uint8_t)((((uint8_t)(x))&QMI8A01Z_RESET_MASK) >> QMI8A01Z_RESET_SHIFT))

/*!< @} */

#endif /* __QMI8A01Z_TYPES_H_ */
