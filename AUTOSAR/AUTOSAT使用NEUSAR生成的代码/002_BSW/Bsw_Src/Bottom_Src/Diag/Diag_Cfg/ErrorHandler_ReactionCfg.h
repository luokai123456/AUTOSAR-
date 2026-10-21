/*
* Generated at 2026-08-27 15:04:12.
* Source file last modified at 2026-08-27 14:58:19.
* Config generator version: 4.1.1
*/
#ifndef ERRORHANDLER_REACTIONCFG_H
#define ERRORHANDLER_REACTIONCFG_H


#include "ErrorHandler_Cfg.h"


#define EH_DRVSUPPRESS_NONE (0xFFFF)


/* Driver Suppression Definitions */
#define EH_HB1_Ch_C (0u)
#define EH_HB2_Ch_C (1u)
#define EH_HB3_Ch_C (2u)
#define EH_HB4_Ch_C (3u)
#define EH_HB5_Ch_C (4u)
#define EH_HB6_Ch_C (5u)
#define EH_HB7_Ch_C (6u)
#define EH_HB8_Ch_C (7u)
#define EH_HS10_Ch_C (8u)
#define EH_HS1_Ch_C (9u)
#define EH_HS2_Ch_C (10u)
#define EH_HS3_Ch_C (11u)
#define EH_HS4_Ch_C (12u)
#define EH_HS5_Ch_C (13u)
#define EH_HS6_Ch_C (14u)
#define EH_HS7_Ch_C (15u)
#define EH_HS8_Ch_C (16u)
#define EH_HS9_Ch_C (17u)
#define EH_LS1_Ch_C (18u)
#define EH_LS2_Ch_C (19u)
#define EH_LS3_Ch_C (20u)
#define EH_LS4_Ch_C (21u)

#define EH_DRIVER_SUPPRESS_CHANNEL_NUM (22u) /* Total number of unique Driver physical channels */
#define EH_DRIVER_SUPPRESS_NUM (22u) /* Total number of ErrorIDs with Driver suppression enabled */


/* L2 Suppression Definitions */
#define EH_L2_ENABLE_NUM (0u) /* Total number of ErrorIDs with L2 suppression enabled */


extern const EH_ConfigReaction_TDSTR EH_Reaction_Cfg[ERRORDIAG_ID_NUM_BSW];
extern const uint16* const EH_DrvSuppress_Cfg[];


#endif /* ERRORHANDLER_REACTIONCFG_H */