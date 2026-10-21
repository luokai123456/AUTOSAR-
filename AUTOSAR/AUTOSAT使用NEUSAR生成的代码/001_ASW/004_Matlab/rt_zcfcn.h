/*
 * File: rt_zcfcn.h
 *
 * Code generated for Simulink model 'swc_BatThermHndlgMngt'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 16:20:54 2023
 */

#ifndef RTW_HEADER_rt_zcfcn_h_
#define RTW_HEADER_rt_zcfcn_h_
#include "zero_crossing_types.h"
#include "rtwtypes.h"
#include "solver_zc.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

#define swc_BatThermHndlgMngt_START_SEC_CODE
#include "swc_BatThermHndlgMngt_MemMap.h"

extern ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, float64
  currValue);

#define swc_BatThermHndlgMngt_STOP_SEC_CODE
#include "swc_BatThermHndlgMngt_MemMap.h"
#endif                                 /* RTW_HEADER_rt_zcfcn_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
