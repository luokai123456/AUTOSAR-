/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3007PT
* DESCRIPTION : CCFC3007PT CCU7 low level drivers h file
* HISTORY     : Initial version
* @file     Pwm_Ccu7_LLDriver.h
* @version  3.0.0
* @date     2024 - 06 - 28
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 0779,1535,2053,4397,1860,0499,4491 EOF*/
/*PRQA S 1891,4535,4534,4543,4433,4499,0709 EOF*/
#ifndef CCU7_PWM_LLD_H_
#define CCU7_PWM_LLD_H_
#include "Mcal.h"
#if (defined(RESOURCE_SUPPORT_CCU7_IP))

#define PWM_INLINE    LOCAL_INLINE

#define PWM_CCU7_LLD_H_VENDOR_ID                      176
#define PWM_CCU7_LLD_H_AR_REL_MAJOR_VER               4
#define PWM_CCU7_LLD_H_AR_REL_MINOR_VER               4
#define PWM_CCU7_LLD_H_AR_REL_REV_VER                 0
#define PWM_CCU7_LLD_H_SW_MAJOR_VER                   3
#define PWM_CCU7_LLD_H_SW_MINOR_VER                   0
#define PWM_CCU7_LLD_H_SW_PATCH_VER                   0

#if (PWM_CCU7_LLD_H_VENDOR_ID != MCAL_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_H_VENDOR_ID "
#endif
#if (PWM_CCU7_LLD_H_AR_REL_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (PWM_CCU7_LLD_H_AR_REL_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_H_AR_REL_MINOR_VER "
#endif
#if (PWM_CCU7_LLD_H_AR_REL_REV_VER != MCAL_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_H_AR_REL_REV_VER "
#endif
#if (PWM_CCU7_LLD_H_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_H_SW_MAJOR_VER "
#endif
#if (PWM_CCU7_LLD_H_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_H_SW_MINOR_VER "
#endif
#if (PWM_CCU7_LLD_H_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : PWM_CCU7_LLD_H_SW_PATCH_VER "
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
** Traceabilty      :                                                         **
*******************************************************************************/
#define PWM_17_GTMCCU7_MAX_CORES                    1U
#define CCU7_INSTANCE_COUNT                         (0x2U)
#define MCU_17_CCU7_NO_OF_COMPARATORS               (0x4U)

typedef uint8 Mcu_17_Ccu7_TimerType;
#define MCU_CCU7_TIMER_T12      ((Mcu_17_Ccu7_TimerType)0x0U)
#define MCU_CCU7_TIMER_T13      ((Mcu_17_Ccu7_TimerType)0x1U)

typedef uint8 Mcu_17_Ccu7_ComparatorType;
#define MCU_CCU7_COMPARATOR_CCU70      ((Mcu_17_Ccu7_ComparatorType)0x0U)
#define MCU_CCU7_COMPARATOR_CCU71      ((Mcu_17_Ccu7_ComparatorType)0x1U)
#define MCU_CCU7_COMPARATOR_CCU72      ((Mcu_17_Ccu7_ComparatorType)0x2U)
#define MCU_CCU7_COMPARATOR_CCU73      ((Mcu_17_Ccu7_ComparatorType)0x3U)

typedef struct
{
    VAR(uint8, AUTOMATIC) IEnBitPos;
    VAR(uint8, AUTOMATIC) IEnLen;
    VAR(uint8, AUTOMATIC) RegVal;
} Mcu_17_Ccu7_TimerChIntType;

typedef struct CCU7_Type s_CCU7_Type;

/* CCU7 - Peripheral instance base addresses */
#define CCU7_0_BASE                             (0xFFDF0000UL)
#define CCU7_0_P                                ((s_CCU7_Type *)CCU7_0_BASE)

#define CCU7_1_BASE                             (0xFBF7C000UL)
#define CCU7_1_P                                ((s_CCU7_Type *)CCU7_1_BASE)

#define CCU7_BASE_ADDRS                         { CCU7_0_BASE, CCU7_1_BASE}
#define CCU7_BASE_PTRS                          { CCU7_0_P, CCU7_1_P}

static CONSTP2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) g_ccu7Base[CCU7_INSTANCE_COUNT] = CCU7_BASE_PTRS;

/* Pwm_17_GtmCcu7_ChannelClassType implemented as uint8 */
typedef uint8 Pwm_17_GtmCcu7_ChannelClassType;

/* Output state of a PWM channel. Note that this will be read from the output
   state on the LTC cell (Assigned_HwUnit) connected to the port pin.
   This will not be read directly from the Port Pin. However both will be
   the same. */
typedef uint8 Pwm_17_GtmCcu7_OutputStateType;

/* The PWM channel is in low state.*/
#define PWM_17_GTMCCU7_LOW   ((Pwm_17_GtmCcu7_OutputStateType)(0U))
/* The PWM channel is in High state.*/
#define PWM_17_GTMCCU7_HIGH  ((Pwm_17_GtmCcu7_OutputStateType)(1U))

/* Definition of the type of notification of a PWM channel */
typedef uint8 Pwm_17_GtmCcu7_EdgeNotificationType;

/* Notification will be called when a rising edge occurs on the PWM Output signal.*/
#define PWM_17_GTMCCU7_RISING_EDGE     ((Pwm_17_GtmCcu7_EdgeNotificationType)(1))
/* Notification will be called when a falling edge occurs on the PWM output signal */
#define PWM_17_GTMCCU7_FALLING_EDGE    ((Pwm_17_GtmCcu7_EdgeNotificationType)(2))
/* Notification will be called when both a rising edge or falling edge
   (means any edge) occurs on the PWM output signal */
#define PWM_17_GTMCCU7_BOTH_EDGES      ((Pwm_17_GtmCcu7_EdgeNotificationType)(3))

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* Numeric identifier of a PWM channel */
/* Maximum 32 channels can be supported.
If proper configuration setup made by user */
typedef uint8 Pwm_17_GtmCcu7_ChannelType;

/* Type definition of the period of a PWM channel.*/
typedef uint32 Pwm_17_GtmCcu7_PeriodType;

/* To provide Notification the following type will be used */
typedef void (*Pwm_17_GtmCcu7_NotifiPtrType)(void);

typedef enum
{
    PWM_PreDisable = 0u,
    PWM_PreEnable = 1u
} Pwm_Ccu7_T12_Prescaler;

typedef enum
{
    PWM_EdgealignedMode = 0u,
    PWM_CenteralignedMode = 1u
} Pwm_Ccu7_Operating_Mode;

typedef enum
{
    PWM_Level0 = 0u,
    PWM_Level1 = 1u,
    PWM_Level2 = 2u,
    PWM_Level3 = 3u
} Pwm_Ccu7_Output_Passive_State;

typedef enum
{
    PWM_SR0 = 0u,
    PWM_SR1 = 1u,
    PWM_SR2 = 2u,
    PWM_SR3 = 3u
} Pwm_Ccu7_Interupt_Line;

typedef enum
{
    PWM_COMPARE_MODE1 = 1u,
    PWM_COMPARE_MODE2 = 2u,
    PWM_COMPARE_MODE3 = 3u
} Pwm_Ccu7_TimerMode;

typedef enum
{
    PWM_CCU7X_PM = 0u,
    PWM_CCU7X_R = 1u,
    PWM_CCU7X_F = 2u,
    PWM_CCU7X_RF = 3u
} Pwm_Ccu7_Edge_Type;

typedef struct
{
    VAR(uint32, AUTOMATIC) TimerCtrlReg0; /* For T12 - [2-0] - Timer T12 Input Clock Select
                                        [3]   - Timer T12 Prescaler Bit
                                        [7]   - T12 Operating Mode
                            For T13 - [10-8] - Timer T13 Input Clock Select
                                        [11]   - Timer T13 Prescaler Bit*/
    VAR(uint32, AUTOMATIC) ModCtrlReg;   /*  For T12 - [1-0] - Timer T12 modulation enable for
                                                comparator
                            For T13 - [2]   - Enable Compare Timer T13 Output
                        */
    VAR(uint32, AUTOMATIC) PasStateLvlReg; /*For T12 - [1-0] - Compare Outputs
                                                Passive State Level of comparator
                            For T13 - [2]   - Passive State Level of Output COUT73
                            */
    VAR(uint32, AUTOMATIC) TimerCntReg;
    VAR(uint32, AUTOMATIC) TimerPeriodReg;
    VAR(uint32, AUTOMATIC) Ccu7ShadowReg;
    VAR(uint32, AUTOMATIC) TimerModeSelectReg;
    VAR(uint32, AUTOMATIC) IntEnReg;           /* 2 - Falling 1- Raising 0- PM */
    VAR(uint32, AUTOMATIC) IntNodePointerReg;  /* [3:2]T12/T13, [1:0] CC7x     */
} Mcu_17_Ccu7_TimerConfigType;

typedef struct
{
    VAR(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) PwmChanneId;
    /* The following parameter is a function pointer to provide notification */
    VAR(Pwm_17_GtmCcu7_NotifiPtrType, AUTOMATIC) PwmNotification;

    /* Pwm_ChannelInfo constitutes
        Reference_Channel, Pwm_ChannelMode, Pwm_IdleState and
        Assigned_HwUnit.
        While forming the variable, user has to form this in the following
        manner. [Note : Use macro Pwm_lConfigChannel() for configuration ]
        PwmChannelInfo =
                        (   ((ShiftReset) << 5U)          |   \
                            ((ChannelClass) << 3U)        |   \
                            ((ChannelCoherency) << 2U)    |   \
                            ((IdleState) << 1U)           |   \
                            (Polarity)                        \
                        )
        Where :
                bit 5:
                To indicate ccu0 is reset by its own compare match or from
                other channel
                bit 3-4:
                PwmChannelClass :  Used to indicate whether channel is
                                    FIXED_PERIOD
                                    FIXED_PERIOD_SHIFTED
                                    FIXED_PERIOD_CENTER_ALIGNED
                                    VARIABLE_PERIOD
                bit 2:
                PwmCoherency   : Informs the channel wise Coherency Selection.
                                1 - Coherent or 0 - non Coherent.
                bit 1:
                PwmIdleState   : Informs the channel Idle State.
                                PWM_17_GTMCCU7_HIGH or PWM_17_GTMCCU7_LOW

                bit 0:
                PwmPolarity    : Informs the channels start state
                                PWM_17_GTMCCU7_HIGH Or PWM_17_GTMCCU7_LOW
    */
    VAR(uint8, AUTOMATIC) PwmChannelInfo;

    /* Default period of PWM channel. This value is fixed permanently for a PWM
        channel configured with Fixed Period Type. */
    VAR(Pwm_17_GtmCcu7_PeriodType, AUTOMATIC) PwmPeriodDefault;

    /* Default Duty Cycle of a PWM channel */
    VAR(uint32, AUTOMATIC) PwmDutycycleDefault;

    /* The following parameter informs the % of shift required.
        The range will be from 0x0000 to 0x8000.
        For 0% shift : value=0x0000, for 100% shift : value=0x8000 */
    VAR(uint32, AUTOMATIC) PwmShiftValue;

    /* Pointer to GTM/CCU7 timer channel information */
    P2VAR(Mcu_17_Ccu7_TimerConfigType, AUTOMATIC, PWM_APPL_DATA) PwmTimerPtr;

} Pwm_17_GtmCcu7_ChannelConfigType;

typedef struct
{
    VAR(uint32, AUTOMATIC)  Pwm_GlobChn;
    VAR(uint32, AUTOMATIC)  Pwm_CurrentPeriodVal;
} Pwm_17_GtmCcu7_ChannelStatusType;

typedef struct
{
  VAR(uint32, AUTOMATIC) Pwm_CoreInitStatus;
  VAR(uint32, AUTOMATIC) Pwm_CCU7PMStatus;
} Pwm_17_GtmCcu7_CoreStatusType;

typedef enum
{
    IEN_SINGLE_EDGE = 1U,
    IEN_BOTH_EDGE = 2U,
}IEN_Intr_Edge_Type;

/*----------------------------------Pwm_17_GtmCcu7.c----------------------------------------*/
#define PWM_CCU7_CH_MASK                      (0xFFU)

#define PWM_BIT_SET                (1U)
#define PWM_BIT_RESET              (0U)

#define PWM_MAX_TIMER_CCU7                    ((uint32)0xFFFFUL)


/* Position of Notification edges */
#define PWM_NOTIFI_EDGE_POS                    1

/* Duty update Flag position */
#define PWM_DUTY_0_OR_100_UPDATE_FLGPOS        3

#define PWM_POLSTATE_MASK          ((uint16)0x1U)

/* Polarity  Position */
#define PWM_POLSTATE_POS           (0x0U)

/* Mask to obtain Duty Update bit */
#define PWM_DUTY_0_OR_100_UPDATE_MASK         ((uint32)(0x00000008UL))
/* Position of Notification Status Bit */
#define PWM_NOTIFI_STATUS_POS                  0
/* Mask to obtain Notification Status bit */
#define PWM_NOTIFI_STATUS_MASK                ((uint32)(0x00000001UL))
#define PWM_PM_NOTIF_HANDLED                  1U

/* Idle state  Position */
#define PWM_IDLESTATE_POS          (0x1U)
#define PWM_IDLESTATE_MASK         ((uint16)0x1U)

/* To shift by 15 */
#define PWM_SHIFT_BY15             (32768U)

#define PWM_NO_NOTIFICATION             ((Pwm_17_GtmCcu7_EdgeNotificationType)0U)
#define PWM_NOTIFICATION_EDGE_MASK            ((uint32)(0x00000006UL))

#define PWM_BIT_RESET                         (0U)

#define PWM_CONST_1                           (1UL)

#define PWM_CONST_2                           (2U)

#define PWM_CONST_3                           (3U)

/* CCU7 Notification mask */
#define PWM_CCU7_NOTIFI_STATUS_POS             4

#define PWM_CONST_4                           (4U)

#define PWM_CONST_5                           (5U)

#define PWM_CONST_6                           (6UL)

#define PWM_CONST_7                           (7U)

#define PWM_CONST_8                           (8U)

#define PWM_CONST_9                           (9U)

#define PWM_CONST_16                          (16U)

#define PWM_CONST_24                          (24U)

/*Macro to obtain the Polarity from PwmChannelInfo.*/
#define PWM_GET_POLARITY(Value) ((Pwm_17_GtmCcu7_OutputStateType)\
        (((uint16)(Value) >> PWM_POLSTATE_POS) & (PWM_POLSTATE_MASK)))

/*Function to get the Notification kind in the global channel variable*/
#define PWM_GET_NOTIFICATION_KIND(Module, Channel) \
    ((Pwm_17_GtmCcu7_EdgeNotificationType)((s_Pwm_CoreChannelStatus\
        [Module][Channel].Pwm_GlobChn)& PWM_NOTIFICATION_EDGE_MASK))
/*--------------------------------------------------------------------------------*/

/*  ------------------------------------Mcu_17_TimerIp.h------------------------  */
/* Function pointer type that defines an MCAL driver callback function */
typedef void (* const Mcu_17_Timer_CallbackFuncPtrType)
(
    CONST(uint8, AUTOMATIC)          moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)          channelNum, \
    CONST(uint32, AUTOMATIC) IsrStatus \
);

/*--------------------------------------------------------------------------------*/

/*  ------------------------------------Mcu_17_TimerIp.c------------------------  */
/* CCU7 Timer related macros */
#define CCU7_KERNEL_MSK                         (0xFFU)
#define CCU7_TIMER_POS                          (0x08U)
#define CCU7_TIMER_MSK                          (0xFFU)
#define CCU7_COMPARATOR_POS                     (0x10U)
#define CCU7_COMPARATOR_MSK                     (0xFFU)
#define CCU7_TCTR0_T12_DEINIT_LEN               (0x8)
#define CCU7_TCTR0_T12_DEINIT_VAL               (0x0)

#define CCU7_TCTR0_T13_DEINIT_LEN               (0x6)
#define CCU7_TCTR0_T13_DEINIT_VAL               (0x0)

#define CCU7_MODCTR_T12_DEINIT_VAL              (0x0)
#define CCU7_MODCTR_T13_DEINIT_VAL              (0x0)

#define CCU7_PSLR_T12_DEINIT_VAL                (0x0)
#define CCU7_PSLR_T13_DEINIT_VAL                (0x0)

#define CCU7_IEN_T12_DEINIT_VAL                 (0x0)
#define CCU7_IEN_T13_DEINIT_VAL                 (0x0)
#define CCU7_IEN_CC7_DEINIT_VAL                 (0x0)

#define CCU7_T12PR_CC7_DEINIT_VAL               (0x0)
#define CCU7_T12_CC7_DEINIT_VAL                 (0x0)
#define CCU7_CC7xSR_DEINIT_VAL                  (0x0)
#define CCU7_T13PR_CC7_DEINIT_VAL               (0x0)
#define CCU7_T13_CC7_DEINIT_VAL                 (0x0)
#define CCU7_INP_T12_DEINIT_VAL                 (0x2)
#define CCU7_INP_T13_DEINIT_VAL                 (0x3)
#define CCU7_INP_CC7x_DEINIT_VAL                (0x0)
#define CCU7_PISEL0_CC7x_DEINIT_VAL             (0x0)
#define CCU7_T12MSEL_MSEL7x_DEINIT_VAL          (0x0)

#define CCU7_TCTR0_T12CLK_LEN                   (0x3)
#define CCU7_TCTR0_T12PRE_LEN                   (0x1)
#define CCU7_TCTR0_CTM_LEN                      (0x1)
#define CCU7_MODCTR_T12MODEN_LEN                (0x2U)
#define CCU7_PSLR_PSL_LEN                       (0x2U)
#define CCU7_TCTR0_T13CLK_LEN                   (0x3)
#define CCU7_TCTR0_T13PRE_LEN                   (0x1)
#define CCU7_MODCTR_ECT13O_LEN                  (0x1)
#define CCU7_MODCTR_T12MODEN_MSK                (0x3U)
#define CCU7_PSLR_PSL_MSK                       (0x3U)
#define CCU7_PSLR_PSL73_OFF                     (0x7U) //
#define CCU7_MODCTR_ECT13O_OFF                  (0xFU) //
#define CCU7_PSLR_PSL73_LEN                     (0x1)
#define CCU7_T12MSEL_MSEL70_LEN                 (0x4UL)
#define CCU7_T12MSEL_MSEL70_MSK                 (0xFU)
#define CCU7_PISEL0_ISCC70_LEN                  (0x2)
#define CCU7_IEN_ENT12PM_MSK                    (0x1U)
#define CCU7_IEN_ENT12PM_LEN                    (0x1)
#define CCU7_IEN_ENCC7xRF_LEN                   (0x2)
#define CCU7_IEN_ENCC7xRF_MSK                   (0x3U)
#define CCU7_IEN_ENCC7xRF_POS                   (0x0U) //
#define CCU7_IEN_ENT13PM_LEN                    (0x1)
#define CCU7_IEN_ENT13PM_MSK                    (0x1U)
#define CCU7_IEN_ENT13CM_LEN                    (0x1)
#define CCU7_IEN_ENT13CM_MSK                    (0x1U)
#define CCU7_IEN_ENT13CM_POS                    (0x8U) //
#define CCU7_INP_INPT12_LEN                     (0x2)
#define CCU7_INP_INPT12_MSK                     (0x3U)
#define CCU7_INP_INPT12_POS                     (0x2U)
#define CCU7_INP_INPT13_LEN                     (0x2)
#define CCU7_INP_INPT13_MSK                     (0x3U)
#define CCU7_INP_INPT13_POS                     (0x12U) //
#define CCU7_INP_INPCC70_LEN                    (0x2)
#define CCU7_INP_INPCC70_MSK                    (0x3U)
#define CCU7_TCTR4_T12RS_LEN                    (0x1)
#define CCU7_T12_START                          (0x1)
#define CCU7_TCTR4_T13RS_LEN                    (0x1)
#define CCU7_T13_START                          (0x1)
#define CCU7_TCTR4_T13RR_LEN                    (0x1)
#define CCU7_T13_STOP                           (0x1)
#define CCU7_TCTR4_T12RR_LEN                    (0x1)
#define CCU7_T12_STOP                           (0x1)
#define CCU7_TCTR4_T12STR_LEN                   (0x1)
#define CCU7_T12_STR                            (0x1)
#define CCU7_TCTR4_T13STR_LEN                   (0x1)
#define CCU7_T13_STR                            (0x1)
#define CCU7_TIMER_INT_STAT_RST                 (0x1)
#define CCU7_TIMER_RCC7xRF_INT_STAT_RST         (0x3U)
#define CCU7_ISR_RT12PM_LEN                     (0x1)
#define CCU7_ISR_RT13PM_LEN                     (0x1)
#define CCU7_ISR_RT13CM_LEN                     (0x1)
#define CCU7_IEN_RCC7xRF_LEN                    (0x2U)
#define CCU7_IEN_SINGLE_EDGE                    (0x1)
#define CCU7_IEN_BOTH_EDGE                      (0x2)

#define CCU7_T13_INT_PM_CM_MSK                  (0x300U)
#define CCU7_T12_INT_PM_MSK                     (0x80U)
#define CCU7_T12_INT_CC7x_MSK                   (0x3U)
#define CCU7_T12_MSK                            (0xFFFFU)
#define CCU7_PISEL_MSK                          (0x3U)
#define CCU7_COMPARATOR_BITLEN                  (0x2U)
#define CCU7_BIT_CLEAR                          (0x0U)
#define CCU7_KERNEL_ENABLE                      (0x0U)

extern FUNC(void, PWM_CODE) Pwm_17_GtmCcu7_Isr \
( \
    CONST(uint8, AUTOMATIC)          moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)          channelNum, \
    CONST(uint32, AUTOMATIC) IsrStatus \
);
 /* PWM driver callback notification */
static CONST(Mcu_17_Timer_CallbackFuncPtrType, AUTOMATIC)  \
Mcu_17_Timer_DrivFuncCallbackLst = &Pwm_17_GtmCcu7_Isr;

/*-------------------------------IfCcu7_bf.h----------------------*/
/** \brief Length for Ifx_CCU7_TCTR2_Bits.T13TEC */
#define IFX_CCU7_TCTR2_T13TEC_LEN (3u)

/** \brief Mask for Ifx_CCU7_TCTR2_Bits.T13TEC */
#define IFX_CCU7_TCTR2_T13TEC_MSK (0x7u)

/** \brief Offset for Ifx_CCU7_TCTR2_Bits.T13TEC */
#define IFX_CCU7_TCTR2_T13TEC_OFF (2u)

/** \brief Length for Ifx_CCU7_TCTR2_Bits.T13TED */
#define IFX_CCU7_TCTR2_T13TED_LEN (2u)

/** \brief Mask for Ifx_CCU7_TCTR2_Bits.T13TED */
#define IFX_CCU7_TCTR2_T13TED_MSK (0x3u)

/** \brief Offset for Ifx_CCU7_TCTR2_Bits.T13TED */
#define IFX_CCU7_TCTR2_T13TED_OFF (5u)

/** \brief Length for Ifx_CCU7_TCTR4_Bits.T12RS */
#define IFX_CCU7_TCTR4_T12RS_LEN (1u)

/** \brief Mask for Ifx_CCU7_TCTR4_Bits.T12RS */
#define IFX_CCU7_TCTR4_T12RS_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_TCTR4_Bits.T12RS */
#define IFX_CCU7_TCTR4_T12RS_OFF (1u)

/** \brief Length for Ifx_CCU7_TCTR0_Bits.T12CLK */
#define IFX_CCU7_TCTR0_T12CLK_LEN (3u)

/** \brief Mask for Ifx_CCU7_TCTR0_Bits.T12CLK */
#define IFX_CCU7_TCTR0_T12CLK_MSK (0x7u)

/** \brief Offset for Ifx_CCU7_TCTR0_Bits.T12CLK */
#define IFX_CCU7_TCTR0_T12CLK_OFF (0u)

/** \brief Length for Ifx_CCU7_TCTR0_Bits.T12PRE */
#define IFX_CCU7_TCTR0_T12PRE_LEN (1u)

/** \brief Mask for Ifx_CCU7_TCTR0_Bits.T12PRE */
#define IFX_CCU7_TCTR0_T12PRE_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_TCTR0_Bits.T12PRE */
#define IFX_CCU7_TCTR0_T12PRE_OFF (3u)

/** \brief Length for Ifx_CCU7_TCTR0_Bits.CTM */
#define IFX_CCU7_TCTR0_CTM_LEN (1u)

/** \brief Mask for Ifx_CCU7_TCTR0_Bits.CTM */
#define IFX_CCU7_TCTR0_CTM_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_TCTR0_Bits.CTM */
#define IFX_CCU7_TCTR0_CTM_OFF (7u)

/** \brief Length for Ifx_CCU7_ISR_Bits.RT12PM */
#define IFX_CCU7_ISR_RT12PM_LEN (1u)

/** \brief Mask for Ifx_CCU7_ISR_Bits.RT12PM */
#define IFX_CCU7_ISR_RT12PM_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_ISR_Bits.RT12PM */
#define IFX_CCU7_ISR_RT12PM_OFF (7u)

/** \brief Length for Ifx_CCU7_IEN_Bits.ENT12PM */
#define IFX_CCU7_IEN_ENT12PM_LEN (1u)

/** \brief Mask for Ifx_CCU7_IEN_Bits.ENT12PM */
#define IFX_CCU7_IEN_ENT12PM_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_IEN_Bits.ENT12PM */
#define IFX_CCU7_IEN_ENT12PM_OFF (7u)

/** \brief Length for Ifx_CCU7_INP_Bits.INPT12 */
#define IFX_CCU7_INP_INPT12_LEN (2u)

/** \brief Mask for Ifx_CCU7_INP_Bits.INPT12 */
#define IFX_CCU7_INP_INPT12_MSK (0x3u)

/** \brief Offset for Ifx_CCU7_INP_Bits.INPT12 */
#define IFX_CCU7_INP_INPT12_OFF (10u)

/** \brief Length for Ifx_CCU7_TCTR0_Bits.T13CLK */
#define IFX_CCU7_TCTR0_T13CLK_LEN (3u)

/** \brief Mask for Ifx_CCU7_TCTR0_Bits.T13CLK */
#define IFX_CCU7_TCTR0_T13CLK_MSK (0x7u)

/** \brief Offset for Ifx_CCU7_TCTR0_Bits.T13CLK */
#define IFX_CCU7_TCTR0_T13CLK_OFF (8u)

/** \brief Length for Ifx_CCU7_TCTR0_Bits.T13PRE */
#define IFX_CCU7_TCTR0_T13PRE_LEN (1u)

/** \brief Mask for Ifx_CCU7_TCTR0_Bits.T13PRE */
#define IFX_CCU7_TCTR0_T13PRE_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_TCTR0_Bits.T13PRE */
#define IFX_CCU7_TCTR0_T13PRE_OFF (11u)

/** \brief Length for Ifx_CCU7_MODCTR_Bits.ECT13O */
#define IFX_CCU7_MODCTR_ECT13O_LEN (1u)

/** \brief Mask for Ifx_CCU7_MODCTR_Bits.ECT13O */
#define IFX_CCU7_MODCTR_ECT13O_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_MODCTR_Bits.ECT13O */
#define IFX_CCU7_MODCTR_ECT13O_OFF (15u)

/** \brief Length for Ifx_CCU7_PSLR_Bits.PSL73 */
#define IFX_CCU7_PSLR_PSL73_LEN (1u)

/** \brief Mask for Ifx_CCU7_PSLR_Bits.PSL73 */
#define IFX_CCU7_PSLR_PSL73_MSK (0x1U)

/** \brief Offset for Ifx_CCU7_PSLR_Bits.PSL73 */
#define IFX_CCU7_PSLR_PSL73_OFF (7U)

/** \brief Length for Ifx_CCU7_ISR_Bits.RT13PM */
#define IFX_CCU7_ISR_RT13PM_LEN (1u)

/** \brief Mask for Ifx_CCU7_ISR_Bits.RT13PM */
#define IFX_CCU7_ISR_RT13PM_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_ISR_Bits.RT13PM */
#define IFX_CCU7_ISR_RT13PM_OFF (9u)

/** \brief Length for Ifx_CCU7_ISR_Bits.RT13CM */
#define IFX_CCU7_ISR_RT13CM_LEN (1u)

/** \brief Mask for Ifx_CCU7_ISR_Bits.RT13CM */
#define IFX_CCU7_ISR_RT13CM_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_ISR_Bits.RT13CM */
#define IFX_CCU7_ISR_RT13CM_OFF (8u)

/** \brief Length for Ifx_CCU7_IEN_Bits.ENT13PM */
#define IFX_CCU7_IEN_ENT13PM_LEN (1u)

/** \brief Mask for Ifx_CCU7_IEN_Bits.ENT13PM */
#define IFX_CCU7_IEN_ENT13PM_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_IEN_Bits.ENT13PM */
#define IFX_CCU7_IEN_ENT13PM_OFF (9u)

/** \brief Length for Ifx_CCU7_IEN_Bits.ENT13CM */
#define IFX_CCU7_IEN_ENT13CM_LEN (1u)

/** \brief Mask for Ifx_CCU7_IEN_Bits.ENT13CM */
#define IFX_CCU7_IEN_ENT13CM_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_IEN_Bits.ENT13CM */
#define IFX_CCU7_IEN_ENT13CM_OFF (8u)

/** \brief Length for Ifx_CCU7_INP_Bits.INPT13 */
#define IFX_CCU7_INP_INPT13_LEN (2u)

/** \brief Mask for Ifx_CCU7_INP_Bits.INPT13 */
#define IFX_CCU7_INP_INPT13_MSK (0x3u)

/** \brief Offset for Ifx_CCU7_INP_Bits.INPT13 */
#define IFX_CCU7_INP_INPT13_OFF (12u)

/** \brief Length for Ifx_CCU7_TCTR4_Bits.T13RS */
#define IFX_CCU7_TCTR4_T13RS_LEN (1u)

/** \brief Mask for Ifx_CCU7_TCTR4_Bits.T13RS */
#define IFX_CCU7_TCTR4_T13RS_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_TCTR4_Bits.T13RS */
#define IFX_CCU7_TCTR4_T13RS_OFF (9u)

/** \brief Length for Ifx_CCU7_TCTR4_Bits.T12RR */
#define IFX_CCU7_TCTR4_T12RR_LEN (1u)

/** \brief Mask for Ifx_CCU7_TCTR4_Bits.T12RR */
#define IFX_CCU7_TCTR4_T12RR_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_TCTR4_Bits.T12RR */
#define IFX_CCU7_TCTR4_T12RR_OFF (0u)

/** \brief Length for Ifx_CCU7_TCTR4_Bits.T13RR */
#define IFX_CCU7_TCTR4_T13RR_LEN (1u)

/** \brief Mask for Ifx_CCU7_TCTR4_Bits.T13RR */
#define IFX_CCU7_TCTR4_T13RR_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_TCTR4_Bits.T13RR */
#define IFX_CCU7_TCTR4_T13RR_OFF (8u)

/** \brief Length for Ifx_CCU7_TCTR4_Bits.T12STR */
#define IFX_CCU7_TCTR4_T12STR_LEN (1u)

/** \brief Mask for Ifx_CCU7_TCTR4_Bits.T12STR */
#define IFX_CCU7_TCTR4_T12STR_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_TCTR4_Bits.T12STR */
#define IFX_CCU7_TCTR4_T12STR_OFF (6u)

/** \brief Length for Ifx_CCU7_TCTR4_Bits.T13STR */
#define IFX_CCU7_TCTR4_T13STR_LEN (1u)

/** \brief Mask for Ifx_CCU7_TCTR4_Bits.T13STR */
#define IFX_CCU7_TCTR4_T13STR_MSK (0x1u)

/** \brief Offset for Ifx_CCU7_TCTR4_Bits.T13STR */
#define IFX_CCU7_TCTR4_T13STR_OFF (14u)

/*-------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------Mcal_SetBitAtomic-----------------------------------------*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR2_T13TEC( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR2_T13TEC \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR2.reg &= ~(IFX_CCU7_TCTR2_T13TEC_MSK << IFX_CCU7_TCTR2_T13TEC_OFF);/* polyspace RTE:NIV */
    base->TCTR2.reg |= val_TCTR2_T13TEC << IFX_CCU7_TCTR2_T13TEC_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if 1
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR2_T13TED( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR2_T13TED \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR2.reg &= ~(IFX_CCU7_TCTR2_T13TED_MSK << IFX_CCU7_TCTR2_T13TED_OFF);/* polyspace RTE:NIV */
    base->TCTR2.reg |= val_TCTR2_T13TED << IFX_CCU7_TCTR2_T13TEC_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR0_T13CLK( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR0_T13CLK \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR0.reg &= ~(IFX_CCU7_TCTR0_T13CLK_MSK << IFX_CCU7_TCTR0_T13CLK_OFF);
    base->TCTR0.reg |= val_TCTR0_T13CLK << IFX_CCU7_TCTR0_T13CLK_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR0_T13PRE( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR0_T13PRE \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR0.reg &= ~(IFX_CCU7_TCTR0_T13PRE_MSK << IFX_CCU7_TCTR0_T13PRE_OFF);/* polyspace RTE:NIV */
    base->TCTR0.reg |= val_TCTR0_T13PRE << IFX_CCU7_TCTR0_T13PRE_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR4_T12RS( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR4_T12RS \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR4.reg &= ~(IFX_CCU7_TCTR4_T12RS_MSK << IFX_CCU7_TCTR4_T12RS_OFF);/* polyspace RTE:NIV */
    base->TCTR4.reg |= val_TCTR4_T12RS << IFX_CCU7_TCTR4_T12RS_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR4_T13RS( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR4_T13RS \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR4.reg &= ~(IFX_CCU7_TCTR4_T13RS_MSK << IFX_CCU7_TCTR4_T13RS_OFF);/* polyspace RTE:NIV */
    base->TCTR4.reg |= val_TCTR4_T13RS << IFX_CCU7_TCTR4_T13RS_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR4_T12RR( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR4_T12RR \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];/* polyspace RTE:OBAI */
    base->TCTR4.reg &= ~(IFX_CCU7_TCTR4_T12RR_MSK << IFX_CCU7_TCTR4_T12RR_OFF);/* polyspace RTE:NIV */
    base->TCTR4.reg |= val_TCTR4_T12RR << IFX_CCU7_TCTR4_T12RR_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR4_T13RR( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR4_T13RR \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];/* polyspace RTE:OBAI */
    base->TCTR4.reg &= ~(IFX_CCU7_TCTR4_T13RR_MSK << IFX_CCU7_TCTR4_T12RR_OFF);/* polyspace RTE:NIV */
    base->TCTR4.reg |= val_TCTR4_T13RR << IFX_CCU7_TCTR4_T12RR_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR4_T12STR( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR4_T12STR \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR4.reg &= ~(IFX_CCU7_TCTR4_T12STR_MSK << IFX_CCU7_TCTR4_T12STR_OFF);/* polyspace RTE:NIV */
    base->TCTR4.reg |= val_TCTR4_T12STR << IFX_CCU7_TCTR4_T12STR_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR4_T13STR( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR4_T13STR \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR4.reg &= ~(IFX_CCU7_TCTR4_T13STR_MSK << IFX_CCU7_TCTR4_T13STR_OFF);/* polyspace RTE:NIV */
    base->TCTR4.reg |= val_TCTR4_T13STR << IFX_CCU7_TCTR4_T13STR_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR0_T12CLK( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR0_T12CLK \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR0.reg &= ~(IFX_CCU7_TCTR0_T12CLK_MSK << IFX_CCU7_TCTR0_T12CLK_OFF);
    base->TCTR0.reg |= val_TCTR0_T12CLK << IFX_CCU7_TCTR0_T12CLK_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR0_T12PRE( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR0_T12PRE \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR0.reg &= ~(IFX_CCU7_TCTR0_T12PRE_MSK << IFX_CCU7_TCTR0_T12PRE_OFF);/* polyspace RTE:NIV */
    base->TCTR0.reg |= val_TCTR0_T12PRE << IFX_CCU7_TCTR0_T12PRE_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetTCTR0_CTM( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_TCTR0_CTM \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->TCTR0.reg &= ~(IFX_CCU7_TCTR0_CTM_MSK << IFX_CCU7_TCTR0_CTM_OFF);/* polyspace RTE:NIV */
    base->TCTR0.reg |= val_TCTR0_CTM << IFX_CCU7_TCTR0_CTM_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetMODCTR_T12MODEN( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint8, AUTOMATIC) channelNum, \
    VAR(uint32, AUTOMATIC) val_MODCTR_T12MODEN \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->MODCTR.reg &= ~(CCU7_MODCTR_T12MODEN_MSK << (channelNum * CCU7_MODCTR_T12MODEN_LEN));/* polyspace RTE:NIV */
    base->MODCTR.reg |= val_MODCTR_T12MODEN << (channelNum * CCU7_MODCTR_T12MODEN_LEN);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetMODCTR_ECT13O( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_MODCTR_ECT13O \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->MODCTR.reg &= ~(IFX_CCU7_MODCTR_ECT13O_MSK << CCU7_MODCTR_ECT13O_OFF);/* polyspace RTE:NIV */
    base->MODCTR.reg |= val_MODCTR_ECT13O << CCU7_MODCTR_ECT13O_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetPSLR_PSL( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint8, AUTOMATIC) channelNum, \
    VAR(uint32, AUTOMATIC) val_PSLR_PSL\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->PSLR.reg &= ~(CCU7_PSLR_PSL_MSK << (channelNum * CCU7_PSLR_PSL_LEN));/* polyspace RTE:NIV */
    base->PSLR.reg |= val_PSLR_PSL << (channelNum * CCU7_PSLR_PSL_LEN);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetPSLR_PSL73( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_PSLR_PSL73\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->PSLR.reg &= ~(IFX_CCU7_PSLR_PSL73_MSK << IFX_CCU7_PSLR_PSL73_OFF);/* polyspace RTE:NIV */
    base->PSLR.reg |= val_PSLR_PSL73 << IFX_CCU7_PSLR_PSL73_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_ClearISR_RCC7xRF( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint8, AUTOMATIC) channelNum
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];/* polyspace RTE:OBAI */
    base->ISR.reg = CCU7_TIMER_RCC7xRF_INT_STAT_RST << (channelNum * CCU7_IEN_RCC7xRF_LEN); //Write 1 Clear
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_ClearISR_RT12PM( \
    VAR(uint8, AUTOMATIC) moduleNum \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->ISR.reg = CCU7_TIMER_INT_STAT_RST << IFX_CCU7_ISR_RT12PM_OFF; //Write 1 Clear
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_ClearISR_RT13PM( \
    VAR(uint8, AUTOMATIC) moduleNum \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];/* polyspace RTE:OBAI */
    base->ISR.reg = CCU7_TIMER_INT_STAT_RST << IFX_CCU7_ISR_RT13PM_OFF; //Write 1 Clear
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_ClearISR_RT13CM( \
    VAR(uint8, AUTOMATIC) moduleNum \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->ISR.reg = CCU7_TIMER_INT_STAT_RST << IFX_CCU7_ISR_RT13CM_OFF; //Write 1 Clear
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetIEN_ENT12PM( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_IEN_ENT12PM\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->IEN.reg &= ~(CCU7_IEN_ENT12PM_MSK << IFX_CCU7_IEN_ENT12PM_OFF);
    base->IEN.reg |= val_IEN_ENT12PM << IFX_CCU7_IEN_ENT12PM_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetIEN_ENT13PM( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_IEN_ENT13PM\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->IEN.reg &= ~(CCU7_IEN_ENT13PM_MSK << IFX_CCU7_IEN_ENT13PM_OFF);/* polyspace RTE:NIV */
    base->IEN.reg |= val_IEN_ENT13PM << IFX_CCU7_IEN_ENT13PM_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetIEN_ENT13CM( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_IEN_ENT13CM\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->IEN.reg &= ~(CCU7_IEN_ENT13CM_MSK << IFX_CCU7_IEN_ENT13CM_OFF);/* polyspace RTE:NIV */
    base->IEN.reg |= val_IEN_ENT13CM << IFX_CCU7_IEN_ENT13CM_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetIEN_EnBits( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(IEN_Intr_Edge_Type, AUTOMATIC) intr_edge_type,
    VAR(uint32, AUTOMATIC) reg_value, \
    VAR(uint32, AUTOMATIC) reg_position \
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];/* polyspace RTE:OBAI */
    switch(intr_edge_type)
    {
        case IEN_SINGLE_EDGE:
            base->IEN.reg &= ~(0x1U << reg_position);/* polyspace RTE:NIV,SHF */
        break;

        case IEN_BOTH_EDGE:
            base->IEN.reg &= ~(0x11U << reg_position);/* polyspace RTE:NIV,SHF */
        break;

        default:
            /*do nothing*/
        break;
    }
    base->IEN.reg |= reg_value << reg_position;/* polyspace RTE:NIV,SHF */
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetIEN_ENCC7xRF( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint8, AUTOMATIC) channelNum, \
    VAR(uint32, AUTOMATIC) val_IEN_ENCC7xRF\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->IEN.reg &= ~(CCU7_IEN_ENCC7xRF_POS << (channelNum * CCU7_IEN_ENCC7xRF_LEN));/* polyspace RTE:NIV */
    base->IEN.reg |= val_IEN_ENCC7xRF << (channelNum * CCU7_IEN_ENCC7xRF_LEN);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetINP_INPT12( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_INP_INPT12\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->INP.reg &= ~(CCU7_INP_INPT12_MSK << IFX_CCU7_INP_INPT12_OFF);
    base->INP.reg |= val_INP_INPT12 << IFX_CCU7_INP_INPT12_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetINP_INPT13( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint32, AUTOMATIC) val_INP_INPT13\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->INP.reg &= ~(CCU7_INP_INPT13_MSK << IFX_CCU7_INP_INPT13_OFF);
    base->INP.reg |= val_INP_INPT13 << IFX_CCU7_INP_INPT13_OFF;
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetINP_INPCC7x( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint8, AUTOMATIC) channelNum, \
    VAR(uint32, AUTOMATIC) val_INP_INPCC7x\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->INP.reg &= ~(CCU7_INP_INPCC70_MSK << (channelNum * CCU7_INP_INPCC70_LEN));
    base->INP.reg |= val_INP_INPCC7x << (channelNum * CCU7_INP_INPCC70_LEN);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetPISEL0_ISCC7x( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint8, AUTOMATIC) channelNum, \
    VAR(uint32, AUTOMATIC) val_PISELx_ISCC7x\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->PISEL0.reg &= ~(CCU7_PISEL_MSK << (channelNum * CCU7_PISEL0_ISCC70_LEN));
    base->PISEL0.reg |= val_PISELx_ISCC7x << (channelNum * CCU7_PISEL0_ISCC70_LEN);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
PWM_INLINE FUNC(void, PWM_CODE) Pwm_Ccu7_SetT12MSEL_MSEL7x( \
    VAR(uint8, AUTOMATIC) moduleNum, \
    VAR(uint8, AUTOMATIC) channelNum, \
    VAR(uint32, AUTOMATIC) val_T12MSEL_MSEL7x\
)
{
	P2VAR(s_CCU7_Type, AUTOMATIC, PWM_APPL_DATA) base = g_ccu7Base[moduleNum];
    base->T12MSEL.reg &= ~(CCU7_T12MSEL_MSEL70_MSK << (channelNum * CCU7_T12MSEL_MSEL70_LEN));/* polyspace RTE:NIV */
    base->T12MSEL.reg |= val_T12MSEL_MSEL7x << (channelNum * CCU7_T12MSEL_MSEL70_LEN);
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void,  PWM_CODE) Ccu7_LLD_PWM_Init \
( \
	CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)       moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum, \
    VAR(Pwm_17_GtmCcu7_ChannelConfigType, AUTOMATIC) ConfigPtr\
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerInit \
( \
	CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)       moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum, \
    CONSTP2CONST(Mcu_17_Ccu7_TimerConfigType, PWM_CONST, PWM_APPL_CONST) pConfigPtr \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerStart \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_Pwm_LLD_ClearIntrFlag \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerStop \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerShadowTransfer \
( \
    CONST(uint8, AUTOMATIC) moduleNum,  \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Mcu_17_Ccu7_TimerIntEnDis \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONSTP2CONST(Mcu_17_Ccu7_TimerChIntType, PWM_CONST, PWM_APPL_CONST) pCcu7IntConfig \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(Std_ReturnType, PWM_CODE) Mcu_17_Ccu7_TimerInitCheck \
( \
	CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)       moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)        channelNum, \
    CONSTP2CONST(Mcu_17_Ccu7_TimerConfigType, PWM_CONST, PWM_APPL_CONST)  ConfigPtr \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_DeInit \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    VAR(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)  channelNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_SetDutyCycle \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum, \
    CONST(uint16, AUTOMATIC)          dutyCycle \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_SetPeriodAndDuty \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum, \
    CONST(Pwm_17_GtmCcu7_PeriodType, AUTOMATIC) period, \
    CONST(uint32, AUTOMATIC) dutyCycle \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_SetOutputToIdle \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(Pwm_17_GtmCcu7_OutputStateType, PWM_CODE) Ccu7_LLD_PWM_GetOutputState \
( \
    CONST(uint8, AUTOMATIC)  moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)  channelNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_DisableNotification \
( \
    CONST(uint8, AUTOMATIC) moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC) channelNum \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Ccu7_LLD_PWM_EnableNotification \
( \
    CONST(uint8, AUTOMATIC)          moduleNum, \
    CONST(Pwm_17_GtmCcu7_ChannelType, AUTOMATIC)          channelNum, \
    CONST(Pwm_17_GtmCcu7_EdgeNotificationType, AUTOMATIC)  notification \
);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8*, PWM_CODE) Ccu7_LLD_PWM_Get_PmStatus(void);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(uint8*, PWM_CODE) Ccu7_LLD_PWM_Get_Duty0or100Status(void);
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_CCU7_IP */
#endif /* EMIOS_PWM_LLD_H_ */

