/*** create info ***********************
*@ Author : wangjiacheng
*@ date :2025-12-04
*@ Description :CAN device configuration H file
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : 
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/

#ifndef __CAN_TRANSMIT_CFG_H_
#define __CAN_TRANSMIT_CFG_H_

#define CAN_EXTFRAME_CLER(x)			(x & (~0x80000000))

/* common */
#define CAN_NETMANGE_CHANNEL			(63U)

/* channel max */
#define CAN_TURN_OFF_MAX				(2U)
#define CAN_CTRL_MODE_MAX				(2U)
#ifndef CAN_TEST_CFG_H_
#define CAN_CTRL_NUM_MAX				(6U)
#else
#define CAN_CTRL_NUM_MAX				(7U)
#endif
#define CAN_REC_MAIL_BOX_MAX			(64U)
#define CAN_TX_MAIL_BOX_MAX				(32U)

#endif /* __CAN_TRANSMIT_CFG_H_ */