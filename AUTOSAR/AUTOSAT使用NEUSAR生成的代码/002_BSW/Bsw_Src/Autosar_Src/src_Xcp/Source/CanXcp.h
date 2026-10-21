/*
********************************************************************************
*
*  File name:   CanXcp.h
*
*  Copyright    Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Sunpengfei/2018.07.10
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: yong.zhang/2020.07.02
* Change: Add release software number
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: FangT/2021.03.03
* Change: Add checksum and Multi pudid functions.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date : FangT/2021.08.18
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date : FangT/2021.10.29
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date : ShiRong/2022.09.16
* Change: Add XcpOnCANFD function.
* Cause: Update
*******************************************************************************
*/
#ifndef CANXCP_H_
#define CANXCP_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
//#include "CanIf.h"
#include "ComStack_Types.h"
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
extern FUNC(void, XCP_CODE) Xcp_CanIfRxIndication
(
    PduIdType CanCanXcpRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, XCP_APPL_CONST) PduInfoPtr
);

extern FUNC(void, XCP_CODE) Xcp_CanIfTxConfirmation(PduIdType CanTxPduId);

#endif /* CANXCP_H_ */
